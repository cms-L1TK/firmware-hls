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
#include "CircularBuffer.h"
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
    good___ = false;
    good____ = false;
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
  phiProjBin_ = projbuffer.phiProjBin();
  stubmask_ = projbuffer.getMaskStubs();
  //stubmask_[0] = nstubsall_[0]!=0;
  //stubmask_[1] = nstubsall_[1]!=0;
  //stubmask_[2] = nstubsall_[2]!=0;
  //stubmask_[3] = nstubsall_[3]!=0;
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
     
    //Calculate fine z position
    const int detectorshift(8);
    if (second_) {
      projfinezadj__ = projfinez-detectorshift;
      zbin=zbin+1;
    } else {
      projfinezadj__ = projfinez;
    }


    //The three lines of code below replaces this logic:
    //projfinephi__ = data.getFinePhi();
    //const int detectorshift(8);
    //if (phiPlus_ && !phiProjBin_ ) {
    //	projfinephi__ += detectorshift;      
    //}
    //if (!phiPlus_ && phiProjBin_ ) {
    //	projfinephi__ -= detectorshift;      
    //}

    ap_uint<1> signBit(!phiPlus_ && phiProjBin_);
    ap_uint<1> addBit(phiPlus_!=phiProjBin_);
    
    projfinephi__ = (signBit, addBit, data.getFinePhi());

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

    auto stubindex=stubdata____.getIndex();
    auto stubfinez=stubdata____.getFineZ();
    auto stubfinephi=stubdata____.getFinePhi();
    auto stubbend=stubdata____.getBend();
    
    const int projfinebits(VMProjectionBase<BARREL>::kVMProjFinePhiWideSize);
    const int stubfinebits(VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize);
    bool passphi = isLessThanSize<projfinebits,stubfinebits,false,projfinebits,stubfinebits>()[(projfinephi____,stubfinephi)];
    
    //Check if stub z position consistent
    const int stub2Sfinebits(1);
    bool pass = isPSseed____ ? isLessThanSize<projfinebits,stub2Sfinebits,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj____)] : isLessThanSize<projfinebits,projfinebits,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj____)];

    auto const index=projrinv____.concat(stubbend);

    //Check if stub bend and proj rinv consistent
    if (empty_) {
      projseqsNext_ = projseq____;
      matchesNext_ = (stubindex, projbuffer____.getAllProj());
    }
    projseqs_[writeindex_] = projseq____;
    matches_[writeindex_] = (stubindex,projbuffer____.getAllProj());
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    bool goodMatch = good____&passphi&pass&table[index]; 
    writeindex_ = (goodMatch&&!empty_) ? writeindexnext : writeindex_;
    empty_ = empty_ && !goodMatch;

    if (goodMatch) {
      matchBuffer_.store((stubindex,projbuffer____.getAllProj(),projseq____));
    }

    //update pipeline variables

    good____ = good___;
    stubdata____ = stubdata___;
    projfinephi____ = projfinephi___;
    projfinezadj____ = projfinezadj___;
    isPSseed____ = isPSseed___;
    projrinv____ = projrinv___;
    projbuffer____ = projbuffer___;
    projseq____ = projseq___;

    good___ = good__;
    stubdata___ = stubdata__;
    projfinephi___ = projfinephi__;
    projfinezadj___ = projfinezadj__;
    isPSseed___ = isPSseed__;
    projrinv___ = projrinv__;
    projbuffer___ = projbuffer__;
    projseq___ = projseq__;
  }

#ifndef __SYNTHESIS__
  inline void setUnit(int unit) {
    unit_ = unit;
  }

#endif

 inline void set_empty() {
   //empty_ = emptyUnit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool empty() const {
#pragma HLS inline  
   return empty_;
 }

 inline bool setNearFull() {
   matchBuffer_.loopInit();
   nearFull_ = nearFull5Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool nearFull() {
   return nearFull_;
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
  return !idle_||good__||good___||good____;
  }

// This method is no longer used, but kept for possible debugging etc.
inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID getTCID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matchesNext_;
    AllProjection<AllProjectionType> allproj(allprojdata);
    return allproj.getTCID();
  }
  if (good____) {
    return projbuffer____.getTCID();
  }
  if (good___) {
    return projbuffer___.getTCID();
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
    (vmstub,allprojdata) = matchesNext_;
    AllProjection<AllProjectionType> allproj(allprojdata);
    return (allproj.getTCID(), allproj.getTrackletIndex());
  }
  if (idle_&&!good__&&!good___&&!good____) {
    typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TRKID tmp(0);
    return ~tmp;
  }
  if (good____) {
    AllProjection<AllProjectionType> allproj(projbuffer____.getAllProj());
    return (projbuffer____.getTCID(), allproj.getTrackletIndex());
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
  return (tcid_, allproj.getTrackletIndex());
}

inline ap_uint<kNBits_MemAddr> getProjSeq() {
#pragma HLS inline
  if (!empty()) {
    assert(projseqsNext_==matchBuffer_.peek().range(kNBits_MemAddr-1,0));
    return matchBuffer_.peek().range(kNBits_MemAddr-1,0);
    //return projseqsNext_;
  }
  if (idle_&&!good__&&!good____) {
    ap_uint<kNBits_MemAddr> tmp(0);
    return ~tmp;
  }
  if (good____) {
    return projseq____;
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

//inline MATCH read() {
//#pragma HLS inline  
//  MATCH matchtmp = matchesNext_;
//  if (readindex_ == writeindex_) {
//    empty_ = true;
//  } else {
//    matchesNext_ =  matches_[readindex_++];
//  } 
//  return matchtmp;
//}


//inline MATCH peek() {

 inline ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize+kNBits_MemAddr> peek() {
#pragma HLS inline  
  assert(empty_==matchBuffer_.empty());
  if (!empty_ || !matchBuffer_.empty()) {
    std::cout << "empty_: " << empty_ << " " << matchBuffer_.empty() << std::endl;
    std::cout << "peek:" << matchesNext_.to_string(2) 
	      << " " << matchBuffer_.peek().to_string(2) << std::endl;
    assert((matchesNext_,projseqsNext_)==matchBuffer_.peek());
  }
  return (matchesNext_,projseqsNext_);
}
 
inline void advance() {
#pragma HLS inline  
  matchBuffer_.advance();
  if (readindex_ == writeindex_) {
    empty_ = true;
  } else {
    projseqsNext_ =  projseqsCache_;
    matchesNext_ =  matchesCache_;
    readindex_++;
  } 
}

inline void cache() {
#pragma HLS inline 
  matchBuffer_.loopEnd();
  if (readindex_ != writeindex_) {
    projseqsCache_ =  projseqs_[readindex_];
    matchesCache_ =  matches_[readindex_];
  }
}

 private:

 //Buffers for the matches
 INDEX writeindex_, readindex_;
 bool empty_;
 MATCH matchesNext_, matchesCache_;
 ap_uint<kNBits_MemAddr> projseqsNext_, projseqsCache_;

 CircularBuffer<(VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize+kNBits_MemAddr),MatchEngineUnitBase<VMProjType>::kNBitsBuffer,5> matchBuffer_;

 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_uint<kNBits_MemAddr> projseqs_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

 bool nearFull_;

 //Current projection
 ap_uint<4> nstubsall_[4];
 NSTUBS nstubs_, istub_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 ap_uint<1> phiProjBin_;
 bool idle_;
 ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphi_;
 BXType bx_;
 VMStubMECM<VMSMEType> stubdata__, stubdata___, stubdata____; 
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;


 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBINNOFLAG zbin;

 //Pipeline variables
 bool good__, good___, good____;
 ap_uint<VMProjectionBase<BARREL>::kVMProjFinePhiWideSize> projfinephi__, projfinephi____, projfinephi___;
 ap_uint<VMProjectionBase<BARREL>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj___, projfinezadj____;
 bool isPSseed__, isPSseed___, isPSseed____;
 VMProjection<BARREL>::VMPRINV projrinv__, projrinv___, projrinv____;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer__, projbuffer___,  projbuffer____;
 ap_uint<kNBits_MemAddr> projseq__, projseq___, projseq____;

#ifndef __SYNTHESIS__
 // only used for debugging to identify MEU
 int unit_;  
#endif

 
}; // end class

#endif
