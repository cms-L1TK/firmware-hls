#ifndef MATCHENGINEUNIT_H
#define MATCHENGINEUNIT_H

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMEMemoryCM.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "AllStubMemory.h"
#include "AllProjectionMemory.h"
#include "FullMatchMemory.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include "MatchEngineUnit_parameters.h"


template<int VMProjType> class MatchEngineUnitBase {};

template<>
class MatchEngineUnitBase<BARREL> {
 public:
  enum BitWidths{
    kNBitsBuffer=3,
  };
};

template<int VMSMEType, int VMProjType, int VMPTYPE, int AllProjectionType>
class MatchEngineUnit : public MatchEngineUnitBase<VMProjType> {

 public:
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize> MATCH;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUBS;
  typedef ap_uint<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> INDEX;

  inline MatchEngineUnit() {}

  inline void reset() {
#pragma HLS inline
    writeindex_ = 0;
    readindex_ = 0;
    stubmask_ = 0;
    nstubs_ = 0;
    idle_ = true;
    empty_ = true;
    good__ = false;
    good__t = false;
    good___ = false;
  }
  

  inline void init(BXType bxin, ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer, ap_uint<kNBits_MemAddr> projseq) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  idle_ = false;
  bx_ = bxin;
  istub_ = 0;

  projbuffer_ = projbuffer;
  projseq_ = projseq;
  (nstubsall_[3], nstubsall_[2], nstubsall_[1], nstubsall_[0]) = projbuffer.getNStubs();
  shift_ = projbuffer.shift();
  stubmask_[0] = nstubsall_[0]!=0;
  stubmask_[1] = nstubsall_[1]!=0;
  stubmask_[2] = nstubsall_[2]!=0;
  stubmask_[3] = nstubsall_[3]!=0;
  ap_uint<2> index = __builtin_ctz(stubmask_);
  stubmask_[index]=0;
  second_ = index[0];
  phiPlus_ = index[1];
  nstubs_ = nstubsall_[index];
  iphi_ = projbuffer.getPhi();
  tcid_ = projbuffer.getTCID();

  good__ = false;

}



inline void step(const VMStubMECM<VMSMEType> stubmem[4][1024]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1

  bool nearfull = nearFull();

  good__ = (!idle_) && (!nearfull);

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUBS istubtmp=istub_;

  ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphiSave = iphi_ + phiPlus_;
  auto secondSave = second_;

  if(istub_ == 0) {
     
    //Need to read the information about the proj in the buffer
    VMProjection<BARREL> data(projbuffer_.getProjection());

    //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
    zbin = data.getZBinNoFlag();
    
    auto projfinez = data.getFineZ();
    projfinephi__ = data.getFinePhi();
     
    //Calculate fine z position
    const int detectorshift(8);
    if (second_) {
      projfinezadj__ = projfinez-detectorshift;
      zbin=zbin+1;
    } else {
      projfinezadj__ = projfinez;
    }

    if (!phiPlus_) {
      if (shift_==-1) {
	projfinephi__ -= detectorshift;
      }
    } else {
      //When we get here shift_ is either 1 or -1
      if (shift_==1) {
	projfinephi__ += detectorshift;
      }
    }

    isPSseed__ = data.getIsPSSeed();
    projrinv__ = data.getRInv();

  }
   
  //Check if last stub, if so, go to next buffer entry 
  if (good__) {
    if (istub_+1>=nstubs_){
      istub_=0;
      if (!stubmask_) {
	idle_ = true;
      } else {
	ap_uint<2> index = __builtin_ctz(stubmask_);
	stubmask_[index]=0;
	second_ =  index[0];
	phiPlus_ =  index[1];
	nstubs_ = nstubsall_[index];
      }
    } else {
      istub_++;
    }
  }
  
  //Read stub memory and extract data fields
  auto stubtmp=(iphiSave,zbin);
  auto stubadd=(stubtmp,istubtmp);
  stubdata__ = stubmem[bx_&3][stubadd];
  projbuffer__ = projbuffer_;
  projseq__ = projseq_;

   
} // end step




  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata___.getIndex();
    auto stubfinez=stubdata___.getFineZ();
    auto stubfinephi=stubdata___.getFinePhi();
    auto stubbend=stubdata___.getBend();
    
    const int projfinebits(VMProjectionBase<BARREL>::kVMProjFinePhiWideSize);
    const int stubfinebits(VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize);
    bool passphi = isLessThanSize<projfinebits,stubfinebits,false,projfinebits,stubfinebits>()[(projfinephi___,stubfinephi)];
    
    //Check if stub z position consistent
    const int stub2Sfinebits(1);
    bool pass = isPSseed___ ? isLessThanSize<projfinebits,stub2Sfinebits,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)] : isLessThanSize<projfinebits,projfinebits,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)];

    auto const index=projrinv___.concat(stubbend);

    //Check if stub bend and proj rinv consistent
    projseqs_[writeindex_] = projseq___;
    matches_[writeindex_] = (stubindex,projbuffer___.getAllProj());
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    writeindex_ = (good___&passphi&pass&table[index]) ? writeindexnext : writeindex_;

    //update pipeline variables
    //good___ = good__;
    //stubdata___ = stubdata__;
    //projfinephi___ = projfinephi__;
    //projfinezadj___ = projfinezadj__;
    //isPSseed___ = isPSseed__;
    //projrinv___ = projrinv__;
    //projbuffer___ = projbuffer__;
    //projseq___ = projseq__;

    good___ = good__t;
    stubdata___ = stubdata__t;
    projfinephi___ = projfinephi__t;
    projfinezadj___ = projfinezadj__t;
    isPSseed___ = isPSseed__t;
    projrinv___ = projrinv__t;
    projbuffer___ = projbuffer__t;
    projseq___ = projseq__t;

    good__t = good__;
    stubdata__t = stubdata__;
    projfinephi__t = projfinephi__;
    projfinezadj__t = projfinezadj__;
    isPSseed__t = isPSseed__;
    projrinv__t = projrinv__;
    projbuffer__t = projbuffer__;
    projseq__t = projseq__;
  }

#ifndef __SYNTHESIS__
  inline void setUnit(int unit) {
    unit_ = unit;
  }

#endif

 inline void set_empty() {
   empty_ = emptyUnit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool empty() const {
#pragma HLS inline  
   return empty_;
 }
 
 inline bool nearFull() {
   return nearFull3Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool idle() {
#pragma HLS inline  
   return idle_;
 }

 inline INDEX readIndex() const {
   return readindex_;
 }

 inline INDEX writeIndex() const {
   return writeindex_;
 }
   

inline bool processing() {
#pragma HLS inline  
  return !idle_||good__||good__t||good___;
}

// This method is no longer used, but kept for possible debugging etc.
inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID getTCID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matches_[readindex_];
    AllProjection<AllProjectionType> allproj(allprojdata);
    return allproj.getTCID();
  }
  if (good___) {
    return projbuffer___.getTCID();
  }
  if (good__t) {
    return projbuffer__t.getTCID();
  }
  if (good__) {
    return projbuffer__.getTCID();
  } 
  return tcid_;
}





inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TRKID getTrkID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matches_[readindex_];
    AllProjection<AllProjectionType> allproj(allprojdata);
    return (allproj.getTCID(), allproj.getTrackletIndex());
  }
  if (idle_&&!good__&&!good__t&&!good___) {
    typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TRKID tmp(0);
    return ~tmp;
  }
  if (good___) {
    AllProjection<AllProjectionType> allproj(projbuffer___.getAllProj());
    return (projbuffer___.getTCID(), allproj.getTrackletIndex());
  }
  if (good__t) {
    AllProjection<AllProjectionType> allproj(projbuffer__t.getAllProj());
    return (projbuffer__t.getTCID(), allproj.getTrackletIndex());
  } 
  if (good__) {
    AllProjection<AllProjectionType> allproj(projbuffer__.getAllProj());
    return (projbuffer__.getTCID(), allproj.getTrackletIndex());
  } 
  AllProjection<AllProjectionType> allproj(projbuffer_.getAllProj());
  return (tcid_, allproj.getTrackletIndex());
}

inline ap_uint<kNBits_MemAddr> getProjSeq() {
#pragma HLS inline
  if (!empty()) {
    return projseqs_[readindex_];
  }
  if (idle_&&!good__&&!good___) {
    ap_uint<kNBits_MemAddr> tmp(0);
    return ~tmp;
  }
  if (good___) {
    return projseq___;
  }
  if (good__) {
    return projseq__;
  } 
  return projseq_;
}

inline VMProjection<BARREL>::VMPID getProjindex() {
#pragma HLS inline  
  return projbuffer_.getIndex();
}

inline NSTUBS getNStubs() {
#pragma HLS inline  
  return nstubs_;
}
inline int getIPhi() {
#pragma HLS inline  
  return iphi_;
}

inline MATCH read() {
#pragma HLS inline  
  return matches_[readindex_++];
}

inline MATCH peek() {
#pragma HLS inline  
  return matches_[readindex_];
}
 
inline void advance() {
#pragma HLS inline  
  readindex_++;  
}

 private:

 //Buffers for the matches
 INDEX writeindex_, readindex_;
 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_uint<kNBits_MemAddr> projseqs_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

 //Current projection
 ap_uint<4> nstubsall_[4];
 NSTUBS nstubs_, istub_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 ap_int<2> shift_;
 bool idle_;
 ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphi_;
 BXType bx_;
 bool empty_;
 VMStubMECM<VMSMEType> stubdata__, stubdata__t, stubdata___; 
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;


 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBINNOFLAG zbin;

 //Pipeline variables
 bool good__, good__t, good___;
 ap_uint<VMProjectionBase<BARREL>::kVMProjFinePhiWideSize> projfinephi__, projfinephi___, projfinephi__t;
 ap_uint<VMProjectionBase<BARREL>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj__t, projfinezadj___;
 bool isPSseed__, isPSseed__t, isPSseed___;
 VMProjection<BARREL>::VMPRINV projrinv__, projrinv__t, projrinv___;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer__, projbuffer__t,  projbuffer___;
 ap_uint<kNBits_MemAddr> projseq__, projseq__t, projseq___;

#ifndef __SYNTHESIS__
 // only used for debugging to identify MEU
 int unit_;  
#endif

 
}; // end class

#endif
