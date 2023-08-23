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
#include "Macros.h"

template<int VMProjType> class MatchEngineUnitBase {};

template<>
class MatchEngineUnitBase<BARREL> {
 public:
  enum BitWidths{
    kNBitsBuffer=3,
  };
};

template<>
class MatchEngineUnitBase<DISK> {
 public:
  enum BitWidths{
    kNBitsBuffer=3,
  };
};

template<int VMSMEType, unsigned kNbitsrzbinMP, int VMProjType, int AllProjectionType, TF::layerDisk LAYER, int ASTYPE>
class MatchEngineUnit : public MatchEngineUnitBase<VMProjType> {

 public:
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize> MATCH;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUB;
  typedef ap_uint<kNBits_MemAddrBinned*4> NSTUBS;
  typedef ap_uint<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> INDEX;

  inline MatchEngineUnit() {}

  inline void reset() {
#pragma HLS inline
    matchBuffer_.reset();
//writeindex_ = 0;
//   readindex_ = 0;
//  readindexnext = 1;
    stubmask_ = 0;
    nstubs_ = 0;
    idle_ = true;
    empty_ = true;
    good__ = false;
    good___ = false;
    good____ = false;
    static ap_uint<kNBits_MemAddr> tmp(0);
    projseqcache_ = ~tmp;
  }
  

  inline void init(BXType bxin, ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer, ap_uint<kNBits_MemAddr> projseq) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  idle_ = false;
  bx_ = bxin;
  istub_ = 0;
  projbuffer_ = projbuffer;
  projseq_ = projseq;
  (nstubsall_[3], nstubsall_[2], nstubsall_[1], nstubsall_[0]) = projbuffer.getNStubs();
  phiProjBin_ = projbuffer.getPhiProjBin();
  stubmask_ = projbuffer.getMaskStubs();
  ap_uint<1> usefirstMinus;
  ap_uint<1> usesecondMinus;
  ap_uint<1> usefirstPlus;
  ap_uint<1> usesecondPlus;
  (usesecondPlus, usefirstPlus, usesecondMinus, usefirstMinus) = stubmask_;
  ap_uint<2> index = __builtin_ctz(stubmask_);
  stubmask_[index]=0;
  second_ = index[0];
  phiPlus_ = index[1];
  nstubs_ = nstubsall_[index];
  iphi_ = projbuffer.getPhi();
  tcid_ = projbuffer.getTCID();

  good__ = false;

  iuse_ = 0;
#pragma HLS ARRAY_PARTITION variable=use_ dim=0 complete
  clearuse: for(int iuse = 0; iuse < kNuse; iuse++) {
#pragma HLS unroll
    use_[iuse] = 0;
  } 
  nuse_ = 0;
  if(usefirstMinus) use_[nuse_++] = 0;//(0, 0);
  else stubmask_[0] = 0;
  if(usesecondMinus) use_[nuse_++] = 2;//(1, 0);
  else stubmask_[1] = 0;
  if(usefirstPlus) use_[nuse_++] = 1;//(0, 1);
  else stubmask_[2] = 0;
  if(usesecondPlus) use_[nuse_++] = 3;//(1, 1);
  else stubmask_[3] = 0;

}



inline void step(const VMStubMECM<VMSMEType> stubmem[4][1<<(kNbitsrzbinMP+kNbitsphibin+4)]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  
  bool nearfull = nearFull();

  good__ = (!idle_) && (!nearfull);

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUB istubtmp=istub_;
  ap_uint<2> iusetmp=iuse_;

  ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphiSave = iphi_ + use_[iusetmp].range(0,0);
  auto secondSave = second_;

  VMProjection<VMProjType> data(projbuffer_.getProjection());
  bool useSecond = data.getZBin().range(0,0)==1;
  constexpr bool isDisk = LAYER > TF::L6;
  constexpr int nbins = isDisk ? (1 << kNbitsrzbin)*2 : (1 << kNbitsrzbin); //twice as many bins in disks (since there are two disks)
  constexpr regionType APTYPE = TF::layerDiskRegion[LAYER];
  int sign = isDisk ? (projbuffer_.getPhiDer() < 0 ? -1 : 1) : 0;

  if(istub_ == 0) {
     
    //Need to read the information about the proj in the buffer
    VMProjection<VMProjType> data(projbuffer_.getProjection());

    zbin_ = data.getZBinNoFlag();

    auto projfinez = data.getFineZ();
    projfinephi__ = data.getFinePhi();
     
    //Calculate fine z position
    const int detectorshift(8);
    if (use_[iusetmp].range(1,1)) {
      projfinezadj__ = projfinez-detectorshift;
    } else {
      projfinezadj__ = projfinez;
    }

    ap_uint<1> signBit(!use_[iusetmp].range(0,0) && phiProjBin_);
    ap_uint<1> addBit(phiPlus_!=phiProjBin_);

    projfinephi__ = (signBit, addBit, data.getFinePhi());

    isPSseed__ = (LAYER < TF::D1) ? projbuffer_.getIsPSSeed() : 0;
    projrinv__ = data.getRInv();

  }
  ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = (iphi_ + use_[iusetmp].range(0,0)) * nbins + zbin_ + use_[iusetmp].range(1,1);
  zbin__ = zbin_ + use_[iusetmp].range(1,1);
  //Read stub memory and extract data fields
  auto stubadd=(slot,istubtmp);
  stubdata__ = stubmem[bx_&3][stubadd];

  ap_uint<2> index = __builtin_ctz(stubmask_);
  bool istub_done = istubtmp+1>=nstubs_;
  bool iuse_done = iusetmp+1>=nuse_;
  ap_uint<2> iusenext = iuse_ + 1;
  NSTUB istubnext = istub_ + 1;
  bool finished = !stubmask_ && iusetmp+1 >= nuse_;

  iuse_ = (good__ && istub_done) ? iusenext : iuse_;
  istub_ = (good__ && istub_done) ? NSTUB(0) : istub_;
  idle_ = (good__ && istub_done && finished) ? true : idle_;
  phiPlus_ = (good__ && istub_done && !finished && stubmask_) ? index[1] : phiPlus_;
  nstubs_ = (good__ && istub_done && !finished && stubmask_) ? NSTUBS(nstubsall_[index]) : nstubs_;
  stubmask_[index] = (good__ && istub_done && !finished && stubmask_) ? ap_uint<1>(0) : stubmask_[index];

  istub_ = (good__ && istub_done && !finished && !stubmask_ && !iuse_done) ? NSTUB(0) : istub_;
  iuse_ = (good__ && iuse_done && !finished && !stubmask_ && iuse_done) ? ap_uint<2>(0) : iuse_;

  istub_ = (good__ && !istub_done) ? istubnext : istub_;
   
  projbuffer__ = projbuffer_;
  projseq__ = projseq_;

  if (idle_&&!good__) {
    ap_uint<kNBits_MemAddr> tmp(0);
    projseqcache_ = ~tmp;
  } else if (good__) {
    projseqcache_ =  projseq__;
  } else {
    projseqcache_ =  projseq_;
  }

   
} // end step




  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata____.getIndex();
    auto stubfinez=stubdata____.getFineZ();
    auto stubfinephi=stubdata____.getFinePhi();
    auto stubbend=stubdata____.getBend();
    constexpr int absz = (1 << MatchEngineUnitBase<VMProjType>::kNBitsBuffer) - 1;
    const bool isPSStub = VMProjType==BARREL ? LAYER <= TF::L3 : 
                                               LAYER <= TF::D2 ? ((zbin____ & absz) < 3) || ((zbin____ & absz) == 3 && stubfinez <= 3) :
                                                                 ((zbin____ & absz) < 3) || ((zbin____ & absz) == 3 && stubfinez <= 2);
    auto stubbendReduced=stubdata____.getBendPSDisk();

    constexpr bool isDisk = LAYER > TF::L6;

    constexpr unsigned int kNBitBin = !isDisk ? 3 : 4;
    constexpr unsigned int kRInvSteps = 32;
    constexpr unsigned int kRInvBits = BITS_TO_REPRESENT(kRInvSteps - 1);
    
    static const ap_uint<1 << 2*projfinephibits> phiLUT = isLessThanSize<projfinephibits,StubPhiPositionConsistency::kMax,false,projfinephibits,stubfinephibits>();
    static const ap_uint<1 << 2*projfinephibits> stubZBarrelPS = isLessThanSize<projfinephibits,StubZPositionBarrelConsistency::kBarrelPSMax,true,stubfinephibits,projfinephibits>();
    static const ap_uint<1 << 2*projfinephibits> stubZBarrel2S = isLessThanSize<projfinephibits,StubZPositionBarrelConsistency::kBarrel2SMax,true,stubfinephibits,projfinephibits>();
    static const ap_uint<1 << 2*projfinephibits> stubZDiskPS = isLessThanSize<projfinephibits,StubZPositionDiskConsistency::kDiskPSMax,true,stubfinephibits,projfinephibits>();
    static const ap_uint<1 << 2*projfinephibits> stubZDisk2S = isLessThanSize<projfinephibits,StubZPositionDiskConsistency::kDisk2SMax,true,stubfinephibits,projfinephibits>();
    bool passphi = phiLUT[(projfinephi____,stubfinephi)];//isLessThanSize<projfinephibits,StubPhiPositionConsistency::kMax,false,projfinephibits,stubfinephibits>()[(projfinephi____,stubfinephi)];
    
    //Check if stub z position consistent
    bool pass = false;
    if(!isDisk) {
      // check if abs(projfinezadj____ - stubfinez) < StubZPositionBarrelConsistency::kBarrel(PS|2S)Max
      pass = isPSseed____ ? stubZBarrelPS[(stubfinez,projfinezadj____)] : stubZBarrel2S[(stubfinez,projfinezadj____)];
    }
    else {
      // check if abs(projfinezadj____ - stubfinez) < StubZPositionBarrelConsistency::kDisk(PS|2S)Max
      pass = isPSStub ? stubZDiskPS[(stubfinez,projfinezadj____)] : stubZDisk2S[(stubfinez,projfinezadj____)];
    }

    //here we always use the larger number of bits for the bend
    // Check if stub bend and proj rinv consistent
    auto const index_part1 = (VMProjType == DISK && isPSseed____) ? projrinv____.concat(stubbendReduced) : projrinv____.concat(stubbend);
    auto const index_part2 = ((VMProjType == DISK && isPSseed____) ? (1 << (kRInvBits + kNBitBin)) : 0);
    const ap_int<1> diskps = isDisk && isPSStub;
    auto const index = diskps ? (diskps,projrinv____,stubbendReduced) : (diskps,projrinv____,stubbend);

    //Check if stub bend and proj rinv consistent
    //projseqs_[writeindex_] = projseq____;
    //matches_[writeindex_] = (stubindex,projbuffer____.getAllProj());
    //INDEX writeindexnext = writeindex_ + 1;
    
    matchBuffer_.save( (stubindex,projbuffer____.getAllProj(), projseq____));

    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts

    bool goodMatch = good____&passphi&pass&table[index]; 

    if (goodMatch) {
      matchBuffer_.inc();
    }

    //writeindex_ = (good____&passphi&pass&table[index]) ? writeindexnext : writeindex_;

    //update pipeline variables
    good____ = good___;
    stubdata____ = stubdata___;
    projfinephi____ = projfinephi___;
    projfinezadj____ = projfinezadj___;
    isPSseed____ = isPSseed___;
    projrinv____ = projrinv___;
    projbuffer____ = projbuffer___;
    projseq____ = projseq___;
    zbin____ = zbin___;

    good___ = good__;
    stubdata___ = stubdata__;
    projfinephi___ = projfinephi__;
    projfinezadj___ = projfinezadj__;
    isPSseed___ = isPSseed__;
    projrinv___ = projrinv__;
    projbuffer___ = projbuffer__;
    projseq___ = projseq__;
    zbin___ = zbin__;
  }

#ifndef __SYNTHESIS__
  inline void setUnit(int unit) {
    unit_ = unit;
  }

#endif

 inline bool empty() const {
#pragma HLS inline  
  return matchBuffer_.empty();
 }

inline void setNearFull() {
   matchBuffer_.loopInit();
 }
 
 inline bool nearFull() {
   return matchBuffer_.nearFull();
 }

 inline bool idle() {
#pragma HLS inline  
   return idle_;
 }

 inline INDEX readIndex() const {
   return  matchBuffer_.readptr();
 }

 inline INDEX writeIndex() const {
   return matchBuffer_.writeptr();
 }
   

inline bool processing() {
#pragma HLS inline  
  return !idle_||good__||good___||good____;
}

// This method is no longer used, but kept for possible debugging etc.
inline typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID getTCID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    ap_uint<kNBits_MemAddr> projseq;
    (vmstub,allprojdata,projseq) = matchBuffer_.peek();
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





inline typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TRKID getTrkID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    ap_uint<kNBits_MemAddr> projseq;
    (vmstub,allprojdata,projseq) = matchBuffer_.peek(); 
     AllProjection<AllProjectionType> allproj(allprojdata);
    return (allproj.getTCID(), allproj.getTrackletIndex());
  }
  if (idle_&&!good__&&!good___&&!good____) {
    typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TRKID tmp(0);
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

//
// Old implemenation of the getProjSeq. This method can be
// used instead of getProjSeq which now makes use of cached data
//
inline ap_uint<kNBits_MemAddr> getProjSeqOld() {
#pragma HLS inline
  if (!empty()) {
    MATCH match;
    ap_uint<kNBits_MemAddr> projseq;
    (match, projseq) = matchBuffer_.peek();
    return projseq;
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


inline ap_uint<kNBits_MemAddr> getProjSeq() {
#pragma HLS inline
  MATCH match;
  ap_uint<kNBits_MemAddr> projseq;
  (match, projseq) = matchBuffer_.peek();
  return empty()?(good____?projseq____:projseqcache_):projseq;

}

inline typename VMProjection<VMProjType>::VMPID getProjindex() {
#pragma HLS inline  
  return projbuffer_.getIndex();
}

inline typename AllProjection<AllProjectionType>::AllProjectionData getProjection() {
#pragma HLS inline  
  return projbuffer_.getAllProj();
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
  // return matches_[readindex_++];
  //}

inline MATCH peek() {
#pragma HLS inline  
  ap_uint<kNBits_MemAddr> projseq;
  MATCH match;
  (match, projseq) = matchBuffer_.peek();
  return match;
}
 
inline void advance() {
#pragma HLS inline
  matchBuffer_.advance();
}

inline void cache() {
#pragma HLS inline  
  matchBuffer_.loopEnd();
}

 private:

   CircularBuffer<VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize+kNBits_MemAddr,MatchEngineUnitBase<VMProjType>::kNBitsBuffer,5> matchBuffer_;

 //Buffers for the matches
 //INDEX writeindex_, readindex_, readindexnext;
 //MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 //ap_uint<kNBits_MemAddr> projseqs_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

 static constexpr int kNuse = 4; // Only 4 options
 //Current projection
 ap_uint<kNBits_MemAddrBinned> nstubsall_[kNuse];
 NSTUB istub_;
 NSTUBS nstubs_;
 ap_uint<kNBits_MemAddrBinned> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::PHIPROJBIN phiProjBin_;
 bool idle_;
 ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphi_;
 BXType bx_;
 bool empty_;
 VMStubMECM<VMSMEType> stubdata__, stubdata___, stubdata____; 
 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;
 ap_uint<kNBits_MemAddr> projseqcache_;

 ap_uint<2> iuse_;
 int nuse_;
 ap_uint<2> use_[kNuse];


 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::VMPZBINNOFLAG zbin_, zbin__, zbin____, zbin___;

 //Pipeline variables
 bool good__, good___, good____;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinephi__, projfinephi____, projfinephi___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj___, projfinezadj____;
 bool isPSseed__, isPSseed___, isPSseed____;
 typename VMProjection<VMProjType>::VMPRINV projrinv__, projrinv____, projrinv___;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer__, projbuffer____, projbuffer___;
 ap_uint<kNBits_MemAddr> projseq__, projseq___, projseq____;

 enum StubZPositionBarrelConsistency {
   kBarrelPSMax = 1,
   kBarrel2SMax = 5
 };
  enum StubZPositionDiskConsistency {
    kDiskPSMax = 1,
    kDisk2SMax = 3
 };
  enum StubPhiPositionConsistency {
    kMax = 3
 };

 static constexpr int projfinephibits = VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize;
 static constexpr int projfinezbits = VMProjectionBase<VMProjType>::kVMProjFineZSize;
 static constexpr int stubfinephibits = VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize;
 static constexpr int stubfinezbits = VMStubMECMBase<VMSMEType>::kVMSMEFineZSize;


#ifndef __SYNTHESIS__
 // only used for debugging to identify MEU
 int unit_;  
#endif

 
}; // end class

#endif
