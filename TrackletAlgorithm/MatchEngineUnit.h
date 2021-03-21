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
  nstubs=0;
  unit_ = -1;
  idle_ = true;
}


 inline void init(BXType bxin, ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer, int iphi, int unit) {
#pragma HLS inline
  idle_ = false;
  bx = bxin;
  istub_ = 0;
  projbuffer_ = projbuffer;
  projindex = projbuffer.getIndex();
  nstubs=projbuffer.getNStubs();
  ivmphi = projbuffer.getPhi();
  iphi_ = iphi;
  unit_ = unit;
}

inline bool empty() {
#pragma HLS inline  
  return (readindex_==writeindex_);

}

inline bool idle() {
#pragma HLS inline  
  return idle_;
}

inline typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID& getTCID() {
#pragma HLS inline  
  return tcid;
}

inline VMProjection<BARREL>::VMPID getProjindex() {
#pragma HLS inline  
  return projbuffer_.getIndex();
}

inline NSTUBS getNStubs() {
#pragma HLS inline  
  return nstubs;
}
inline int getIPhi() {
#pragma HLS inline  
  return iphi_;
}

inline MATCH read() {
#pragma HLS inline  
  return matches_[readindex_++];

}

 inline void step(bool *table, const VMStubMEMemoryCM<VMSMEType,3,3> &stubmem) {
#pragma HLS inline


   if(idle_) return;
   
   // vmproj index
   typename VMProjection<VMPTYPE>::VMPZBIN projzbin;
   
   // Buffer still has projections to read out
   //If the buffer is not empty we have a projection that we need to 
   //process. 

   ap_uint<kNBits_MemAddrBinned+2> istubtmp=istub_;
     
   if (istub_==0) {
       
     //Need to read the information about the proj in the buffer
     auto const qdata=projbuffer_;
     tcid=qdata.getTCID();
     auto nstub = qdata.getNStubs();
     nstubs=qdata.getNStubs();
     VMProjection<BARREL> data(qdata.getProjection());
     zbin=qdata.getZBin();
     
     projindex=data.getIndex();
     auto projfinez=data.getFineZ();
     projrinv=data.getRInv();
     isPSseed=data.getIsPSSeed();
     auto projzbin=qdata.getZBin();
     
     auto second=qdata.hasSecond();
     
     //Calculate fine z position
     if (second) {
	 projfinezadj=projfinez-8;
     } else {
       projfinezadj=projfinez;
     }
     
     if (nstubs==1) {
       istub_=0;
       idle_ = true;
     } else {
       istub_++;
     }
   } else {
     //Check if last stub, if so, go to next buffer entry 
     if (istub_+1>=nstubs){
       istub_=0;
       idle_ = true;
     } else {
       istub_++;
     }
   }
   
   //Read stub memory and extract data fields
   int stubadd=16*(iphi_*8+zbin)+istubtmp;
   const VMStubMECM<VMSMEType> stubdata=stubmem.read_mem(bx,stubadd);
   auto stubindex=stubdata.getIndex();
   auto stubfinez=stubdata.getFineZ();
   auto stubbend=stubdata.getBend();
   
   //Check if stub z position consistent
   ap_int<5> idz=stubfinez-projfinezadj;
   bool pass;
   if (isPSseed) {
     pass=idz>=-2&&idz<=2;
   } else {
     pass=idz>=-5&&idz<=5;
   }
     
   //Check if stub bend and proj rinv consistent
   auto const index=projrinv.concat(stubbend);
   if (pass&&table[index]) {
     matches_[writeindex_++]=(stubindex,projbuffer_.getAllProj());
   } // if(pass&&table[index])
   
 } // end step

 //protected:
 INDEX writeindex_;
 INDEX readindex_;
 NSTUBS nstubs;
 bool idle_;
 int ivmphi;
 int iphi_;
 int unit_;
 BXType bx;
 NSTUBS istub_=0;
 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_int<5> projfinezadj; //FIXME Need replace 5 with const
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::TCID tcid;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::PRHASSEC isPSseed;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::VMPZBIN zbin;
 VMProjection<BARREL>::VMPRINV projrinv;
 VMProjection<BARREL>::VMPID projindex;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 
}; // end class


#endif
