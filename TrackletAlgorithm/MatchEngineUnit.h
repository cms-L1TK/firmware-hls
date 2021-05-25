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
#include "hls_math.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include "MatchProcessor_parameters.h"

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
    good_ = false;
    good__ = false;
  }
  
  inline void processPipeLine(bool *table) {
#pragma HLS inline
    if (good__) {
      auto stubindex=stubdata__.getIndex();
      auto stubfinez=stubdata__.getFineZ();
      auto stubfinephi=stubdata__.getFinePhi();
      auto stubbend=stubdata__.getBend();
    
      bool passphi = isLessThanSize<5,3,false,5,3>()[(projfinephi___,stubfinephi)];
    
      //Check if stub z position consistent
      bool pass = isPSseed__ ? isLessThanSize<5,1,true,3,5>()[(stubfinez,projfinezadj__)] : isLessThanSize<5,5,true,3,5>()[(stubfinez,projfinezadj__)];

      auto const index=projrinv__.concat(stubbend);

      //Check if stub bend and proj rinv consistent
      if (passphi&&pass&&table[index]) {
	matches_[writeindex_++]=(stubindex,projbuffer___.getAllProj());
      }
    }

    good__ = good_;
    stubdata__ = stubdata_;
    projfinephi___ = projfinephi__;
    projfinezadj__ = projfinezadj_;
    isPSseed__ = isPSseed_;
    projrinv__ = projrinv_;
    projbuffer___ = projbuffer__;
  }


 inline void init(BXType bxin, ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer, int iphi, int unit) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  idle_ = false;
  bx = bxin;
  istub_ = 0;
  AllProjection<AllProjectionType> aProj(projbuffer.getAllProj());
  projbuffer_ = projbuffer;
  projindex = projbuffer.getIndex();
  (nstubsall_[3], nstubsall_[2], nstubsall_[1], nstubsall_[0]) = projbuffer.getNStubs();
  shift_ = projbuffer.shift();
  stubmask_[0] = nstubsall_[0]!=0;
  stubmask_[1] = nstubsall_[1]!=0;
  stubmask_[2] = nstubsall_[2]!=0;
  stubmask_[3] = nstubsall_[3]!=0;
  ap_uint<2> index = __builtin_ctz(stubmask_);
  stubmask_[index]=0;
  second_ = isSecond[index];
  phiPlus_ = isPhiPlus[index];
  nstubs_ = nstubsall_[index];
  assert(nstubs_!=0);
  ivmphi = projbuffer.getPhi();
  iphi_ = iphi;
  auto const qdata=projbuffer_;
  tcid=qdata.getTCID();

  good_ = false;

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
  return !idle_||good_||good__;
}

inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID getTCID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matches_[readindex_];
    AllProjection<AllProjectionType> allproj(allprojdata);
    return allproj.getTCID();
  }
  assert(!idle_||good_||good__);
  if (good__) {
    return projbuffer___.getTCID();
  }
  if (good_) {
    return projbuffer__.getTCID();
  } 
  assert(tcid==projbuffer_.getTCID());
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
  if (idle_&&!good_&&!good__) {
    typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TRKID tmp(0);
    return ~tmp;
  }
  if (good__) {
    AllProjection<AllProjectionType> allproj(projbuffer___.getAllProj());
    return (projbuffer___.getTCID(), allproj.getTrackletIndex());
  }
  if (good_) {
    AllProjection<AllProjectionType> allproj(projbuffer__.getAllProj());
    return (projbuffer__.getTCID(), allproj.getTrackletIndex());
  } 
  AllProjection<AllProjectionType> allproj(projbuffer_.getAllProj());
  return (tcid, allproj.getTrackletIndex());
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

 inline void step(const VMStubMECM<VMSMEType> stubmem[2][1024]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1

   bool nearfull = nearFull();

   good_ = idle_ ? false : good_;
   good_ = nearfull ? false : good_;

   bool process = (!idle_) && (!nearfull);

   // vmproj index
   //typename VMProjection<VMPTYPE>::VMPZBIN projzbin;
   
   // Buffer still has projections to read out
   //If the buffer is not empty we have a projection that we need to 
   //process. 

   NSTUBS istubtmp=istub_;

   ap_uint<3> iphiSave = iphi_ + phiPlus_;
   auto secondSave = second_;

   if(emptyUnit<kNBits_MemAddrBinned>()[istub_]) {
       
     //Need to read the information about the proj in the buffer
     //FIXME - should this not be in init method?
     auto const qdata=projbuffer_;
     tcid=qdata.getTCID();
     VMProjection<BARREL> data(qdata.getProjection());
     zbin=data.getZBin().range(3,1); //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
     
     projindex=data.getIndex();
     auto projfinez=data.getFineZ();
     projfinephi_=data.getFinePhi();
     projrinv=data.getRInv();
     isPSseed=data.getIsPSSeed();
     
     //Calculate fine z position
     if (second_) {
       projfinezadj=projfinez-8;
       zbin=zbin+1;
     } else {
       projfinezadj=projfinez;
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
	 assert(nstubs_!=0);
       }
     } else {
       istub_++;
     }
   }

   //Read stub memory and extract data fields
   ap_uint<10> stubadd=(iphiSave,zbin,istubtmp);
   stubdata_ = stubmem[bx&1][stubadd];
   projfinephi__ = projfinephi_;
   projfinezadj_ = projfinezadj;
   isPSseed_ = isPSseed;
   projrinv_ = projrinv;
   projbuffer__ = projbuffer_;
   good_ =  process;

   
 } // end step

 bool Good_() const { return good_;}
 bool Good__() const { return good__;}

 private:
 INDEX writeindex_;
 INDEX readindex_;
 ap_uint<4> nstubsall_[4];
 NSTUBS nstubs_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 ap_int<2> shift_;
 bool idle_;
 int ivmphi;
 ap_uint<3> iphi_;
 BXType bx;
 bool empty_;
 NSTUBS istub_=0;
 VMStubMECM<VMSMEType> stubdata_, stubdata__; 
 bool good_, good__;
 ap_int<5> projfinephi__, projfinephi___;
 ap_int<5> projfinezadj_, projfinezadj__;
 bool isPSseed_, isPSseed__;
 VMProjection<BARREL>::VMPRINV projrinv_, projrinv__;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer__, projbuffer___;

 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_int<5> projfinezadj; //FIXME Need replace 5 with const
 ap_int<5> projfinephi_; //FIXME Need replace 5 with const
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid;
 bool isPSseed;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBINNOFLAG zbin;
 VMProjection<BARREL>::VMPRINV projrinv;
 VMProjection<BARREL>::VMPID projindex;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<(1 << (2 * MatchEngineUnitBase<VMProjType>::kNBitsBuffer))> nearFullLUT = nearFull3Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>();
 bool isSecond[4] = {0, 1, 0, 1};
 bool isPhiPlus[4] = {0, 0, 1, 1};
 ap_uint<1<<(kNBits_MemAddrBinned+2)> onlyOneStub = hasOneStub<kNBits_MemAddrBinned+2>();
 
}; // end class

#endif
