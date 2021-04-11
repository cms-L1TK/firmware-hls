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
    kNMatchEngines=4
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
  nstubsall_ = 0;
  idle_ = true;
  good_ = false;
}


 inline void init(BXType bxin, ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer, int iphi, int unit) {
#pragma HLS inline
  idle_ = false;
  bx = bxin;
  istub_ = 0;
  AllProjection<AllProjectionType> aProj(projbuffer.getAllProj());
  projbuffer_ = projbuffer;
  projindex = projbuffer.getIndex();
  nstubsall_ = projbuffer.getNStubs();
  shift_ = projbuffer.shift();
  stubmask_[0] = nstubsall_.range(3,0)!=0;
  stubmask_[1] = nstubsall_.range(7,4)!=0;
  stubmask_[2] = nstubsall_.range(11,8)!=0;
  stubmask_[3] = nstubsall_.range(15,12)!=0;
  ap_uint<2> index = __builtin_ctz(stubmask_);
  stubmask_[index]=0;
  /*
  second_ = index==1 || index==3; // can be simplified
  phiPlus_ = index==2 || index==3; // can be simplified
  */
  second_ = isSecond[index];
  phiPlus_ = isPhiPlus[index];
  nstubs_ = nstubsall_.range(4*index+3,4*index);
  assert(nstubs_!=0);
  ivmphi = projbuffer.getPhi();
  iphi_ = iphi;
}

 inline bool empty() {
#pragma HLS inline  
   return (readindex_==writeindex_);
   
 }
 
 inline bool nearFull() {
   /*
   INDEX writeindexnext = writeindex_+1;
   INDEX writeindexnext2 = writeindex_+1;
   return readindex_==writeindexnext || readindex_==writeindexnext2;
   */

   return nearFullLUT[(readindex_,writeindex_)];
 }

inline bool idle() {
#pragma HLS inline  
  return idle_;
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
  assert(!idle_||good_||good__);
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

 inline void step(bool *table, const VMStubMECM<VMSMEType> stubmem[2][1024]) {
#pragma HLS inline

   bool nearfull = nearFull();

   if (good__) {
     auto stubindex=stubdata__.getIndex();
     auto stubfinez=stubdata__.getFineZ();
     auto stubfinephi=stubdata__.getFinePhi();
     auto stubbend=stubdata__.getBend();
     
     int phidiff = projfinephi___ - stubfinephi;

     bool passphi =  phidiff < 3 && phidiff > -3;

     //Check if stub z position consistent
     ap_int<5> idz=stubfinez-projfinezadj__;
     bool pass;
     if (isPSseed__) {
       pass=idz>=-1&&idz<=1;
     } else {
       pass=idz>=-5&&idz<=5;
     }

     auto const index=projrinv__.concat(stubbend);
     
     //Check if stub bend and proj rinv consistent
     if (passphi&&pass&&table[index]) {
       matches_[writeindex_++]=(stubindex,projbuffer___.getAllProj());
     } // if(pass&&table[index])
   }

   good__ = good_;
   stubdata__ = stubdata_;
   projfinephi___ = projfinephi__;
   projfinezadj__ = projfinezadj_;
   isPSseed__ = isPSseed_;
   projrinv__ = projrinv_;
   projbuffer___ = projbuffer__;

   if(idle_||nearfull) {
     good_ = false;
     return;
   }

   
   // vmproj index
   //typename VMProjection<VMPTYPE>::VMPZBIN projzbin;
   
   // Buffer still has projections to read out
   //If the buffer is not empty we have a projection that we need to 
   //process. 

   NSTUBS istubtmp=istub_;

   //ap_uint<1> phiPlusSave = phiPlus_;
   ap_uint<3> iphiSave = iphi_ + phiPlus_;
   auto secondSave = second_;

   if (istub_==0) {
       
     //Need to read the information about the proj in the buffer
     //FIXME - should this not be in init method?
     auto const qdata=projbuffer_;
     tcid=qdata.getTCID();
     //auto nstub = qdata.getNStubs();
     //nstubs=qdata.getNStubs();
     VMProjection<BARREL> data(qdata.getProjection());
     zbin=data.getZBin().range(3,1); //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
     
     projindex=data.getIndex();
     auto projfinez=data.getFineZ();
     projfinephi_=data.getFinePhi();
     projrinv=data.getRInv();
     isPSseed=data.getIsPSSeed();
     //auto projzbin=qdata.getZBin();
     
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
   if (istub_+1>=nstubs_){
     istub_=0;
     if (!stubmask_) {
       //if (stubmask_==0) {
       idle_ = true;
     } else {
       ap_uint<2> index = __builtin_ctz(stubmask_);
       stubmask_[index]=0;
       second_ =  index[0];
       phiPlus_ =  index[1];
       nstubs_ = nstubsall_.range(4*index+3,4*index);
       assert(nstubs_!=0);
     }
   } else {
     istub_++;
   }

   //Read stub memory and extract data fields
   ap_uint<10> stubadd=(zbin,iphiSave,istubtmp);
   stubdata_ = stubmem[bx&1][stubadd];
   projfinephi__ = projfinephi_;
   projfinezadj_ = projfinezadj;
   isPSseed_ = isPSseed;
   projrinv_ = projrinv;
   projbuffer__ = projbuffer_;
   good_ =  true;

   
 } // end step

 //protected:
 INDEX writeindex_;
 INDEX readindex_;
 ap_uint<16> nstubsall_;
 NSTUBS nstubs_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 ap_int<2> shift_;
 bool idle_;
 int ivmphi;
 ap_uint<3> iphi_;
 BXType bx;
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
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBIN zbin;
 VMProjection<BARREL>::VMPRINV projrinv;
 VMProjection<BARREL>::VMPID projindex;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<(1 << (2 * MatchEngineUnitBase<VMProjType>::kNBitsBuffer))> nearFullLUT = nearFull3Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>();
 bool isSecond[4] = {0, 1, 0, 1};
 bool isPhiPlus[4] = {0, 0, 1, 1};
 ap_uint<1<<(kNBits_MemAddrBinned+2)> onlyOneStub = hasOneStub<kNBits_MemAddrBinned+2>();
 
}; // end class

#endif
