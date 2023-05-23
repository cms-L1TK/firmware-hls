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

template<int VMSMEType, int VMProjType, int AllProjectionType, TF::layerDisk LAYER, int ASTYPE>
class MatchEngineUnit : public MatchEngineUnitBase<VMProjType> {

 public:
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize+AllProjection<AllProjectionType>::kAllProjectionSize> MATCH;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUB;
  typedef ap_uint<kNBits_MemAddrBinned*4> NSTUBS;
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

  iuse_ = 0;
  bool usefirstMinus = projbuffer_.getUseFirstMinus();
  bool usesecondMinus = projbuffer_.getUseSecondMinus();
  bool usefirstPlus = projbuffer_.getUseFirstPlus();
  bool usesecondPlus = projbuffer_.getUseSecondPlus();
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



inline void step(const VMStubMECM<VMSMEType> stubmem[4][1<<(kNbitsrzbinMP+kNbitsphibinMP+4)]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1

  bool nearfull = nearFull();

  good__ = (!idle_) && (!nearfull);

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUB istubtmp=istub_;
  NSTUB iusetmp=iuse_;

  ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphiSave = iphi_ + use_[iusetmp].range(0,0);
  auto secondSave = second_;

  VMProjection<VMProjType> data(projbuffer_.getProjection());
  bool useSecond = data.getZBin().range(0,0)==1;
  constexpr bool isDisk = LAYER > TF::L6;
  constexpr int nbins = isDisk ? (1 << kNbitsrzbin)*2 : (1 << kNbitsrzbin); //twice as many bins in disks (since there are two disks)
  constexpr regionType APTYPE = TF::layerDiskRegion[LAYER];
  int sign = isDisk ? (projbuffer_.getPhiDer() < 0 ? -1 : 1) : 0;
  bool usefirstMinus = use_[iusetmp] == 0;
  bool usesecondMinus = use_[iusetmp] == 2;
  bool usefirstPlus = use_[iusetmp] == 1;
  bool usesecondPlus = use_[iusetmp] == 3;
  bool first = usefirstPlus || usefirstMinus;
  bool second = usefirstPlus || usesecondPlus;

  if(istub_ == 0) {
     
    //Need to read the information about the proj in the buffer
    VMProjection<VMProjType> data(projbuffer_.getProjection());

    //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
    zbin_ = data.getZBinNoFlag();

    auto projfinez = data.getFineZ();
     
    //Calculate fine z position
    const int detectorshift(8);
    if (use_[iusetmp].range(1,1)) {
      projfinezadj__ = projfinez-detectorshift;
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

    isPSseed__ = projbuffer_.getIsPSSeed();
    projrinv__ = data.getRInv();

  }
  ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = (iphi_ + use_[iusetmp].range(0,0)) * nbins + zbin_ + use_[iusetmp].range(1,1);
  zbin__ = zbin_ + use_[iusetmp].range(1,1);
  //Read stub memory and extract data fields
  auto stubtmp=(iphiSave,zbin_);
  auto stubadd=(slot,istubtmp);
  stubdata__ = stubmem[bx_&3][stubadd];
   
   if (good__) {
    if (istubtmp+1>=nstubs_) {
      iuse_++;
      istub_ = 0;
      auto nstubstmp = nstubs_;
      if (!stubmask_ && iusetmp+1 >= nuse_) {
        idle_ = true;
      }
      else if (stubmask_) {
           ap_uint<2> index = __builtin_ctz(stubmask_);
           stubmask_[index]=0;
           second_ =  index[0];
           phiPlus_ =  index[1];
           nstubs_ = nstubsall_[index];
      }
      if(iusetmp+1 < nuse_) {
        istub_ = 0;
      }
      else {
           iuse_ = 0;
      }
    } else {
      istub_++;
     }
   }

  projbuffer__ = projbuffer_;
  projseq__ = projseq_;

   
} // end step




  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata___.getIndex();
    auto stubfinez=stubdata___.getFineZ();
    auto stubfinephi=stubdata___.getFinePhi();
    auto stubbend=stubdata___.getBend();
    constexpr int absz = (1 << MatchEngineUnitBase<VMProjType>::kNBitsBuffer) - 1;
    const bool isPSStub = VMProjType==BARREL ? LAYER <= TF::L3 : 
                                               LAYER <= TF::D2 ? ((zbin___ & absz) < 3) || ((zbin___ & absz) == 3 && stubfinez <= 3) :
                                                                 ((zbin___ & absz) < 3) || ((zbin___ & absz) == 3 && stubfinez <= 2);
    auto stubbendReduced=stubdata___.getBendPSDisk();

    const int projfinephibits(VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize);
    const int projfinezbits(VMProjectionBase<VMProjType>::kVMProjFineZSize);
    const int stubfinephibits(VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize);
    const int stubfinezbits(VMStubMECMBase<VMSMEType>::kVMSMEFineZSize);
    constexpr bool isDisk = LAYER > TF::L6;

	constexpr unsigned int kNBitBin = !isDisk ? 3 : 4;
	constexpr unsigned int kRInvSteps = 32;
	constexpr unsigned int kRInvBits = BITS_TO_REPRESENT(kRInvSteps - 1);
    
    const int projfinebits(VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize);
    const int stubfinebits(VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize);
    bool passphi = isLessThanSize<projfinephibits,StubPhiPositionConsistency::kMax,false,projfinephibits,stubfinephibits>()[(projfinephi___,stubfinephi)];
    
    //Check if stub z position consistent
    bool pass = false;
    if(!isDisk) {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kBarrel(PS|2S)Max
      pass = isPSseed___ ? isLessThanSize<projfinebits,StubZPositionBarrelConsistency::kBarrelPSMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)] : isLessThanSize<projfinebits,StubZPositionBarrelConsistency::kBarrel2SMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)];
    }
    else {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kDisk(PS|2S)Max
      pass = isPSStub ? isLessThanSize<projfinebits,StubZPositionDiskConsistency::kDiskPSMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)] : isLessThanSize<projfinebits,StubZPositionDiskConsistency::kDisk2SMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)];
    }

    //here we always use the larger number of bits for the bend
	// Check if stub bend and proj rinv consistent
	auto const index_part1 = (VMProjType == DISK && isPSseed___) ? projrinv___.concat(stubbendReduced) : projrinv___.concat(stubbend);
	auto const index_part2 = ((VMProjType == DISK && isPSseed___) ? (1 << (kRInvBits + kNBitBin)) : 0);
    const ap_int<1> diskps = isDisk && isPSStub;
    auto const index = diskps ? (diskps,projrinv___,stubbendReduced) : (diskps,projrinv___,stubbend);

    //Check if stub bend and proj rinv consistent
    projseqs_[writeindex_] = projseq___;
    matches_[writeindex_] = (stubindex,projbuffer___.getAllProj());
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    writeindex_ = (good___&passphi&pass&table[index]) ? writeindexnext : writeindex_;

    //update pipeline variables
    good___ = good__t;
    stubdata___ = stubdata__t;
    projfinephi___ = projfinephi__t;
    projfinezadj___ = projfinezadj__t;
    isPSseed___ = isPSseed__t;
    projrinv___ = projrinv__t;
    projbuffer___ = projbuffer__t;
    projseq___ = projseq__t;
    zbin___ = zbin__t;

    good__t = good__;
    stubdata__t = stubdata__;
    projfinephi__t = projfinephi__;
    projfinezadj__t = projfinezadj__;
    isPSseed__t = isPSseed__;
    projrinv__t = projrinv__;
    projbuffer__t = projbuffer__;
    projseq__t = projseq__;
    zbin__t = zbin__;
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
   return nearFull4Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
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
inline typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID getTCID() {
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





inline typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TRKID getTrkID() {
#pragma HLS inline
  if (!empty()) {
    ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> vmstub;
    ap_uint<AllProjection<AllProjectionType>::kAllProjectionSize> allprojdata;
    (vmstub,allprojdata) = matches_[readindex_];
    AllProjection<AllProjectionType> allproj(allprojdata);
    return (allproj.getTCID(), allproj.getTrackletIndex());
  }
  if (idle_&&!good__&&!good__t&&!good___) {
    typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TRKID tmp(0);
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
 ap_uint<kNBits_MemAddrBinned> nstubsall_[4];
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
 VMStubMECM<VMSMEType> stubdata__, stubdata__t, stubdata___; 
 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;

 NSTUB iuse_;
 static constexpr int kNuse = 4; // Only 4 options
 int nuse_;
 ap_uint<2> use_[kNuse];


 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::VMPZBINNOFLAG zbin_, zbin__, zbin___, zbin__t;

 //Pipeline variables
 bool good__, good__t, good___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinephi__, projfinephi___, projfinephi__t;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj__t, projfinezadj___;
 bool isPSseed__, isPSseed__t, isPSseed___;
 typename VMProjection<VMProjType>::VMPRINV projrinv__, projrinv___, projrinv__t;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer__, projbuffer___, projbuffer__t;
 ap_uint<kNBits_MemAddr> projseq__, projseq__t, projseq___;

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



#ifndef __SYNTHESIS__
 // only used for debugging to identify MEU
 int unit_;  
#endif

 
}; // end class

#endif
