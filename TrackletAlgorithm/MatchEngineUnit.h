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
  typedef ap_uint<kNBits_MemAddrBinned+2> NSTUBS;
  typedef ap_uint<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> INDEX;

inline MatchEngineUnit() {
#pragma HLS inline
  writeindex_ = 0;
  readindex_ = 0;
  stubmask_ = 0;
  nstubs_ = 0;
  nstubsall_ = 0;
  unit_ = -1;
  idle_ = true;
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
  unit_ = unit;
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

inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID getTCID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matches_[readindex_];
    AllProjection<AllProjectionType> allproj(allprojdata);
    return allproj.getTCID();
  }
  assert(!idle_);
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
  assert(!idle_);
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

 inline void step(bool *table, const VMStubMEMemoryCM<VMSMEType, 3, 3, kNMatchEngines> &stubmem) {
#pragma HLS inline


   if(idle_||nearFull()) return;
   
   // vmproj index
   typename VMProjection<VMPTYPE>::VMPZBIN projzbin;
   
   // Buffer still has projections to read out
   //If the buffer is not empty we have a projection that we need to 
   //process. 

   ap_uint<kNBits_MemAddrBinned+2> istubtmp=istub_;

   ap_uint<1> phiPlusSave = phiPlus_;
   auto nstubssave = nstubs_;
   auto secondSave = second_;

   if (istub_==0) {
       
     //Need to read the information about the proj in the buffer
     //FIXME - should this not be in init method?
     auto const qdata=projbuffer_;
     tcid=qdata.getTCID();
     //auto nstub = qdata.getNStubs();
     //nstubs=qdata.getNStubs();
     VMProjection<BARREL> data(qdata.getProjection());
     zbin=qdata.getZBin();
     
     projindex=data.getIndex();
     auto projfinez=data.getFineZ();
     projfinephi_=data.getFinePhi();
     projrinv=data.getRInv();
     isPSseed=data.getIsPSSeed();
     auto projzbin=qdata.getZBin();
     
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

     
     //if (nstubs_==1) {
     if (onlyOneStub[nstubs_]) {
       istub_=0;
       if (!stubmask_) {
       //if (stubmask_==0) {
	 idle_ = true;
       } else {
	 ap_uint<2> index = __builtin_ctz(stubmask_);
	 stubmask_[index]=0;
	 second_ =  index==1 || index==3; // can be simplified
	 phiPlus_ =  index==2 || index==3; // can be simplified
	 nstubs_ = nstubsall_.range(4*index+3,4*index);
	 assert(nstubs_!=0);
       }
     } else {
       istub_++;
     }
   } else {
     //Check if last stub, if so, go to next buffer entry 
     if (istub_+1>=nstubs_){
       istub_=0;
       if (!stubmask_) {
       //if (stubmask_==0) {
	 idle_ = true;
       } else {
	 ap_uint<2> index = __builtin_ctz(stubmask_);
	 stubmask_[index]=0;
	 second_ =  index==1 || index==3; // can be simplified
	 phiPlus_ =  index==2 || index==3; // can be simplified
	 nstubs_ = nstubsall_.range(4*index+3,4*index);
	 assert(nstubs_!=0);
       }
     } else {
       istub_++;
     }
   }

   //Read stub memory and extract data fields
   int stubadd=16*(iphi_+phiPlusSave+8*zbin)+istubtmp;
   assert(nstubssave==stubmem.getEntries(bx, zbin, iphi_+phiPlusSave));
   const VMStubMECM<VMSMEType> stubdata=stubmem.read_mem(unit_, bx, stubadd);
   auto stubindex=stubdata.getIndex();
   auto stubfinez=stubdata.getFineZ();
   auto stubfinephi=stubdata.getFinePhi();
   auto stubbend=stubdata.getBend();

   int phidiff = projfinephi_ - stubfinephi;

   bool passphi =  phidiff < 3 && phidiff > -3;

   //Check if stub z position consistent
   ap_int<5> idz=stubfinez-projfinezadj;
   bool pass;
   if (isPSseed) {
     pass=idz>=-1&&idz<=1;
   } else {
     pass=idz>=-5&&idz<=5;
   }

   auto const index=projrinv.concat(stubbend);
     
   //Check if stub bend and proj rinv consistent
   if (passphi&&pass&&table[index]) {
     matches_[writeindex_++]=(stubindex,projbuffer_.getAllProj());
   } // if(pass&&table[index])
   
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
 int iphi_;
 int unit_;
 BXType bx;
 NSTUBS istub_=0;
 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_int<5> projfinezadj; //FIXME Need replace 5 with const
 ap_int<5> projfinephi_; //FIXME Need replace 5 with const
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid;
 bool isPSseed;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBIN zbin;
 VMProjection<BARREL>::VMPRINV projrinv;
 VMProjection<BARREL>::VMPID projindex;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<(1 << (2 * MatchEngineUnitBase<VMProjType>::kNBitsBuffer))> nearFullLUT = nearFullUnit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>();
 bool isSecond[4] = {0, 1, 0, 1};
 bool isPhiPlus[4] = {0, 0, 1, 1};
 ap_uint<1<<(kNBits_MemAddrBinned+2)> onlyOneStub = hasOneStub<kNBits_MemAddrBinned+2>();
 
}; // end class

#endif
