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

template<int nbits>
static const ap_uint<1 << nbits> hasOneStub() {
  ap_uint<1 << nbits> onlyOneStub(0);
  onlyOneStub[1] = 1;
  return onlyOneStub;
}

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

  inline MatchEngineUnit() {
#pragma HLS inline
    writeindex_ = 0;
    readindex_ = 0;
    stubmask_ = 0;
    nstubs_ = 0;
    idle_ = true;
    empty_ = true;
    good__ = false;
    good___ = false;
  }
  
  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata__.getIndex();
    auto stubfinez=stubdata__.getFineZ();
    auto stubfinephi=stubdata__.getFinePhi();
    auto stubbend=stubdata__.getBend();
    
    bool passphi = isLessThanSize<5,3,false,5,3>()[(projfinephi__,stubfinephi)];
    
    //Check if stub z position consistent
    bool pass = isPSseed___ ? isLessThanSize<5,1,true,3,5>()[(stubfinez,projfinezadj__)] : isLessThanSize<5,5,true,3,5>()[(stubfinez,projfinezadj__)];

    auto const index=projrinv___.concat(stubbend);

    //Check if stub bend and proj rinv consistent
    projseqs_[writeindex_] = projseq___;
    matches_[writeindex_] = (stubindex,projbuffer___.getAllProj());
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    writeindex_ = (good___&passphi&pass&table[index]) ? writeindexnext : writeindex_;

    //update pipeline variables
    good___ = good__;
    stubdata__ = stubdata_;
    projfinephi__ = projfinephi_;
    projfinezadj__ = projfinezadj_;
    isPSseed___ = isPSseed__;
    projrinv___ = projrinv__;
    projbuffer___ = projbuffer__;
    projseq___ = projseq__;
  }


  inline void init(BXType bxin, ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer, ap_uint<kNBits_MemAddr> projseq, int iphi, int unit) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  idle_ = false;
  bx = bxin;
  istub_ = 0;
  unit_ = unit;

  projbuffer_ = projbuffer;
  projseq_ = projseq;
  projindex = projbuffer.getIndex();
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
  ivmphi = projbuffer.getPhi();
  iphi_ = iphi;
  tcid=projbuffer.getTCID();

  good__ = false;

}

 inline void set_empty() {
   empty_ = emptyUnit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool empty() const {
#pragma HLS inline  
   return empty_;
 }
 
 inline bool nearFull() {
   return nearFullLUT[(readindex_,writeindex_)];
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
  return !idle_||good__||good___;
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
  if (good__) {
    return projbuffer__.getTCID();
  } 
  return tcid;
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
  if (idle_&&!good__&&!good___) {
    typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TRKID tmp(0);
    return ~tmp;
  }
  if (good___) {
    AllProjection<AllProjectionType> allproj(projbuffer___.getAllProj());
    return (projbuffer___.getTCID(), allproj.getTrackletIndex());
  }
  if (good__) {
    AllProjection<AllProjectionType> allproj(projbuffer__.getAllProj());
    return (projbuffer__.getTCID(), allproj.getTrackletIndex());
  } 
  AllProjection<AllProjectionType> allproj(projbuffer_.getAllProj());
  return (tcid, allproj.getTrackletIndex());
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

inline void step(const VMStubMECM<VMSMEType> stubmem[2][1024]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1

  bool nearfull = nearFull();
  
  //good__ = idle_ ? false : good__;
  //good__ = nearfull ? false : good__;

  bool process = (!idle_) && (!nearfull);

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUBS istubtmp=istub_;

  ap_uint<3> iphiSave = iphi_ + phiPlus_;
  auto secondSave = second_;

  if(zero<kNBits_MemAddrBinned>()[istub_]) {
     
    //Need to read the information about the proj in the buffer
    //FIXME - should this not be in init method?

    VMProjection<BARREL> data(projbuffer_.getProjection());
    zbin=data.getZBin().range(3,1); //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
    
    projindex = data.getIndex();
    auto projfinez = data.getFineZ();
    projfinephi_ = data.getFinePhi();
     
    //Calculate fine z position
    if (second_) {
      projfinezadj_ = projfinez-8;
      zbin=zbin+1;
    } else {
      projfinezadj_ = projfinez;
    }

    if (!phiPlus_) {
      if (shift_==-1) {
	projfinephi_ -= 8;
      }
    } else {
      //When we get here shift_ is either 1 or -1
      if (shift_==1) {
	projfinephi_ += 8;
      }
    }

    isPSseed__ = data.getIsPSSeed();
    projrinv__ = data.getRInv();

  }
   
  //Check if last stub, if so, go to next buffer entry 
  if (process) {
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
  ap_uint<10> stubadd=(iphiSave,zbin,istubtmp);
  stubdata_ = stubmem[bx&1][stubadd];
  projbuffer__ = projbuffer_;
  projseq__ = projseq_;
  good__ =  process;

   
} // end step

 private:


 INDEX writeindex_, readindex_;
 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

 ap_uint<4> nstubsall_[4];
 NSTUBS nstubs_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 ap_int<2> shift_;
 bool idle_;
 int ivmphi;
 int unit_;  // only used for debugging to identify MEU
 ap_uint<3> iphi_;
 BXType bx;
 bool empty_;
 NSTUBS istub_=0;
 VMStubMECM<VMSMEType> stubdata_, stubdata__; 
 bool good__, good___;
 ap_int<5> projfinephi_, projfinephi__; //FIXME Need replace 5 with const
 ap_int<5> projfinezadj_, projfinezadj__; //FIXME Need replace 5 with const
 bool isPSseed__, isPSseed___;
 VMProjection<BARREL>::VMPRINV projrinv__, projrinv___;

 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_, projbuffer__, projbuffer___;

 ap_uint<kNBits_MemAddr> projseq_, projseq__, projseq___;

 ap_uint<kNBits_MemAddr> projseqs_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid;
 bool isPSseed_;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBINNOFLAG zbin;

 VMProjection<BARREL>::VMPID projindex;

 ap_uint<(1 << (2 * MatchEngineUnitBase<VMProjType>::kNBitsBuffer))> nearFullLUT = nearFull3Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>();

 ap_uint<1<<(kNBits_MemAddrBinned+2)> onlyOneStub = hasOneStub<kNBits_MemAddrBinned+2>();
 
}; // end class

#endif
