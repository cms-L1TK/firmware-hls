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

//#define DEBUG
//#define DEBUG_ALL

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

template<int VMSMEType, int VMProjType, int AllProjectionType, TF::layerDisk LAYER>
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
    good___ = false;
    good____ = false;
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
  ap_uint<2> index = __builtin_ctz(stubmask_);
  stubmask_[index]=0;
  second_ = index[0];
  phiPlus_ = index[1];
  nstubs_ = nstubsall_[index];
#ifdef DEBUG
  std::cout << std::hex << "Initializing MEU " << unit_ << " index=" << index << " with proj=" << projbuffer.getAllProj() << std::endl;
#endif
  iphi_ = projbuffer.getPhi();
  tcid_ = projbuffer.getTCID();

  good__ = false;

  iuse_ = 0;
  bool usefirstMinus = projbuffer_.getUseFirstMinus();
  bool usesecondMinus = projbuffer_.getUseSecondMinus();
  bool usefirstPlus = projbuffer_.getUseFirstPlus();
  bool usesecondPlus = projbuffer_.getUseSecondPlus();
#ifdef DEBUG
  std::cout << "received" << std::endl;
        std::cout << "usefirstMinus=" << usefirstMinus << "\t" <<
                     "usesecondMinus=" << usesecondMinus << "\t" <<
                     "usefirstPlus=" << usefirstPlus << "\t" <<
                     "usesecondPlus=" << usesecondPlus << std::endl;
#endif
#pragma HLS ARRAY_PARTITION variable=use_ dim=0 complete
  clearuse: for(int iuse = 0; iuse < kNuse; iuse++) {
#pragma HLS unroll
    use_[iuse] = 0;
  } 
  nuse_ = 0;
  if(usefirstMinus) use_[nuse_++] = 0;//(0, 0);
  if(usesecondMinus) use_[nuse_++] = 2;//(1, 0);
  if(usefirstPlus) use_[nuse_++] = 1;//(0, 1);
  if(usesecondPlus) use_[nuse_++] = 3;//(1, 1);

}



inline void step(const VMStubMECM<VMSMEType> stubmem[4][1<<(kNbitsrzbinMP+kNbitsphibin+4)]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1

  bool nearfull = nearFull();

  good__ = (!idle_) && (!nearfull);
#ifdef DEBUG_ALL
  std::cout << "good__=" << good__ << "(!idle_=" << !idle_ << " !nearfull=" << !nearfull << ")" << std::endl;
#endif

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUB istubtmp=istub_;

  ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphiSave = iphi_ + use_[iusetmp].range(0,0);
  auto secondSave = second_;

#ifdef DEBUG_ALL
  std::cout << "Getting projection" << std::endl;
  std::cout << "in MEU " << unit_ << std::endl;
#endif
  VMProjection<VMProjType> data(projbuffer_.getProjection());
  bool useSecond = data.getZBin().range(0,0)==1;
  constexpr bool isDisk = LAYER > TF::L6;
  constexpr int nbins = isDisk ? (1 << kNbitsrzbin)*2 : (1 << kNbitsrzbin); //twice as many bins in disks (since there are two disks)
  constexpr regionType APTYPE = TF::layerDiskRegion[LAYER];
  //auto tmpproj = AllProjection<APTYPE>(projbuffer_.getAllProj());
  int sign = isDisk ? (projbuffer_.getPhiDer() < 0 ? -1 : 1) : 0;
#ifdef DEBUG_ALL
  std::cout << "projfinephi__=" << projfinephi__ << " sign=" << sign << std::endl;
  //int sign = 1;
  std::cout << "usesecondMinus=(useSecond=" << useSecond << " & " << (nstubs_.range(7,4) != 0) << ")" << std::endl;
  std::cout << "MEU " << unit_  << " nstubs_=" << nstubs_ << std::endl;
  std::cout << "nstubsall_=" << nstubsall_[3] << "\t" << nstubsall_[2] << "\t" << nstubsall_[1] << "\t" << nstubsall_[0] << "\t" << std::endl;
  std::cout << "nstubs_=" << nstubs_.range(15,12) << "\t" << nstubs_.range(11,8) << "\t" << nstubs_.range(7,4) << "\t" << nstubs_.range(3,0) << "\t" << std::endl;
#endif
  /*
  bool usefirstMinus = nstubs_.range(3,0) != 0;
  bool usesecondMinus = (useSecond && nstubs_.range(7,4) != 0);
  bool usefirstPlus = projbuffer_.getIVMPlus() != projbuffer_.getIVMMinus() && nstubs_.range(11,8) != 0;
  bool usesecondPlus = projbuffer_.getIVMPlus() != projbuffer_.getIVMMinus() && (useSecond && nstubs_.range(15,12) != 0);
  bool usefirstMinus = projbuffer_.getUseFirstMinus();
  bool usesecondMinus = projbuffer_.getUseSecondMinus();
  bool usefirstPlus = projbuffer_.getUseFirstPlus();
  bool usesecondPlus = projbuffer_.getUseSecondPlus();
  */
  bool usefirstMinus = use_[iuse_] == 0;
  bool usesecondMinus = use_[iuse_] == 2;
  bool usefirstPlus = use_[iuse_] == 1;
  bool usesecondPlus = use_[iuse_] == 3;
#ifdef DEBUG_ALL
  std::cout << std::hex << "proj=" << projbuffer_.getAllProj() << std::endl;
#endif
  bool first = usefirstPlus || usefirstMinus;
  bool second = usefirstPlus || usesecondPlus;
#ifdef DEBUG
  std::cout << "use[" << iuse_ << "]=" << use_[iuse_] << std::endl;
  std::cout << "phibin=" << iphi_ << " (iphiSave=" << iphiSave << ") usesecond=" << second << " second_=" << second_ << " equal=" << (second==second_) << std::endl;
  std::cout << "usefirstMinus=" << usefirstMinus << "\t" <<
               "usesecondMinus=" << usesecondMinus << "\t" <<
               "usefirstPlus=" << usefirstPlus << "\t" <<
               "usesecondPlus=" << usesecondPlus << std::endl;
#endif

  //std::cout << "building slot " << (projfinephi__ + sign) << "*" << nbins << "+" << zbin << "+" << useSecond << std::endl;
  //ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = (iphi_ + second) * nbins + zbin + first;
  //ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = (iphi_ + sign) * nbins + zbin + first;
  //int slot = (iphi_ + second) * nbins + zbin + first;
  //int slot = (projfinephi__ + sign) * nbins + zbin + useSecond;
  if(istub_ == 0) {

#ifdef DEBUG_ALL
    std::cout << "Loading VMStubME" << std::endl;
#endif
     
    //Need to read the information about the proj in the buffer
    VMProjection<VMProjType> data(projbuffer_.getProjection());

    //FIXME is this valid? Only using range(3,1) instead of full range, zfirst in MatchProcessor.h
    zbin = data.getZBinNoFlag();
#ifdef DEBUG_ALL
    std::cout << "MEU " << unit_ << " loaded zbin=" << zbin << std::endl;
    std::cout << "zbin=" << std::bitset<VMProjectionBase<VMProjType>::kVMProjZBinSize>(data.getZBin()) << "\tuseSecond=" << useSecond << std::endl;
    std::cout << "should shift=" << useSecond << std::endl;
#endif

    auto projfinez = data.getFineZ();
    projfinephi__ = data.getFinePhi();
     
    //Calculate fine z position
    const int detectorshift(8);
    if (use_[iusetmp].range(1,1)) {
      projfinezadj__ = projfinez-detectorshift;
    } else {
      projfinezadj__ = projfinez;
    }
#ifdef DEBUG_ALL
    std::cout << "post correction projfinez=" << projfinez << std::endl;
#endif

    ap_uint<1> signBit(!use_[iusetmp].range(0,0) && phiProjBin_);
    ap_uint<1> addBit(phiPlus_!=phiProjBin_);

    projfinephi__ = (signBit, addBit, data.getFinePhi());

    isPSseed__ = (LAYER < TF::D1) ? projbuffer_.getIsPSSeed() : 0;
    projrinv__ = data.getRInv();

  }
  //ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphitmp = iphi_;
#ifdef DEBUG
  std::cout << iphi_ << "+" << use_[iuse_].range(0,0) << "*" << nbins << "=" << (iphi_ + use_[iuse_].range(0,0)) * nbins << std::endl;
#endif
  ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = (iphi_ + use_[iuse_].range(0,0)) * nbins + zbin + (second_ ? -1 : 0) + use_[iuse_].range(1,1);
#ifdef DEBUG
  //std::cout << "use_=" << use_[iuse_].first << ", " << use_[iuse_].second << std::endl;
  std::cout << std::hex << "proj=" << projbuffer_.getAllProj() << std::endl;
  std::cout << "first=" << use_[iuse_].range(1,1) << " second=" << use_[iuse_].range(0,0) << std::endl;
  std::cout << "usefirstMinus=" << usefirstMinus << "\t" <<
               "usesecondMinus=" << usesecondMinus << "\t" <<
               "usefirstPlus=" << usefirstPlus << "\t" <<
               "usesecondPlus=" << usesecondPlus << std::endl;
  std::cout << "first=" << first << "\tsecond=" << second << std::endl;
  std::cout << "building slot " << (iphi_ + sign) << "*" << nbins << "+" << zbin + (second_ ? -1 : 0) << "+" << useSecond << std::endl;
  std::cout << "building slot " << (iphi_ + second) << "*" << nbins << "+" << zbin + (second_ ? -1 : 0) << "+" << first << std::endl;
  std::cout << "building slot " << (iphi_  << "+" <<  use_[iuse_].range(0,0)) << "*" << nbins  << "+" <<  zbin + (second_ ? -1 : 0)  << "+" <<  use_[iuse_].range(1,1) << std::endl;
  std::cout << "istub_=" << istubtmp << std::endl;
  std::cout << "iuse_=" << iuse_ << std::endl;
  std::cout << "nuse_=" << nuse_ << std::endl;
  //std::cout << "iphiSave=" << iphiSave << std::endl;
  //std::cout << "zbin=" << zbin << std::endl;
#endif
#ifdef DEBUG_ALL
  std::cout << std::hex << "slot=" << slot << " istubtmp=" << istubtmp << " zbin=" << zbin << std::endl;
  std::cout << "istub_=" << istubtmp << "\t" << "nstubs_=" << nstubs_ << std::endl;
#endif
   
  //Check if last stub, if so, go to next buffer entry 
  if (good__) {
    if (istub_+1>=nstubs_){
      //istub_ = 0;
      iuse_++;
      if(iuse_ < nuse_) {
        istub_ = 0;
      }
      else {
        idle_ = true;
      }
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
  //auto stubtmp=(iphiSave,slot);
  auto stubtmp=(iphiSave,zbin);
  auto stubadd=(slot,istubtmp);
  //auto stubadd=(stubtmp,istubtmp);
  stubdata__ = stubmem[bx_&1][stubadd];
#ifdef DEBUG
  if(istub_ == 0 && 0) {
    std::cout << "Stubs in MEU " << unit_ << std::endl;
    for(int i = 0; i < 1024; i++) {
      std::cout << "stubmem[" << (bx_&1) << "][" << i << "]=" << stubmem[bx_&1][i].raw() << std::endl;
      //if(stubmem[bx_&1][i].raw() > 0) std::cout << "stubmem[" << (bx_&1) << "][" << i << "]=" << stubmem[bx_&1][i].raw() << std::endl;
    }
  }
  std::cout << std::hex << "proj=" << projbuffer_.getAllProj() << std::endl;
  std::cout << "stubid=" << stubdata__.getIndex() << std::endl;
  std::cout << "stubadd=" << (stubtmp,istubtmp) << std::endl;
  std::cout << "With slot stubadd=" << (slot,istubtmp) << std::endl;
  std::cout << std::bitset<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize>((iphiSave,zbin)) << "|"
            << std::bitset<kNBits_MemAddrBinned>(istubtmp) << std::endl
            << std::bitset<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize - 1 + kNBits_MemAddrBinned>(slot) << "|"
            << std::bitset<kNBits_MemAddrBinned>(istubtmp) << std::endl;
#endif
#ifdef DEBUG_ALL
  if(good__) std::cout << std::hex << "MEU " << unit_ << " pipelining stub=" << stubdata__.raw() << " with stubadd=(" << slot << "," << istubtmp << ") stubid=" << stubdata__.getIndex() << " against proj=" << projbuffer_.getAllProj() << std::endl;
  if(good__) std::cout << "usefirstMinus=" << usefirstMinus << "\t" <<
                "usesecondMinus=" << usesecondMinus << "\t" <<
                "usefirstPlus=" << usefirstPlus << "\t" <<
                "usesecondPlus=" << usesecondPlus << std::endl;
#endif
  projbuffer__ = projbuffer_;
  projseq__ = projseq_;

   
} // end step




  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata___.getIndex();
    auto stubfinez=stubdata___.getFineZ();
    auto stubfinephi=stubdata___.getFinePhi();
    auto stubbend=stubdata___.getBend();
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
    //std::cout << "passphi=" << passphi << "\t" << isLessThanSize<projfinebits,stubfinebits,false,projfinebits,stubfinebits>()[(projfinephi___,stubfinephi)] << std::endl;
    
    //Check if stub z position consistent
    bool pass = false;
    if(!isDisk) {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kBarrel(PS|2S)Max
      pass = isPSseed___ ? isLessThanSize<projfinebits,StubZPositionBarrelConsistency::kBarrelPSMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)] : isLessThanSize<projfinebits,StubZPositionBarrelConsistency::kBarrel2SMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)];
    }
    else {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kDisk(PS|2S)Max
      pass = isPSseed___ ? isLessThanSize<projfinebits,StubZPositionDiskConsistency::kDiskPSMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)] : isLessThanSize<projfinebits,StubZPositionDiskConsistency::kDisk2SMax,true,stubfinebits,projfinebits>()[(stubfinez,projfinezadj___)];
    }

    auto const index=projrinv___.concat(stubbend);
	// Check if stub bend and proj rinv consistent
	auto const index_part1 = (VMProjType == DISK && isPSseed___) ? projrinv___.concat(stubbendReduced) : projrinv___.concat(stubbend);
	auto const index_part2 = ((VMProjType == DISK && isPSseed___) ? (1 << (kRInvBits + kNBitBin)) : 0);
	//auto const index = index_part1 + index_part2;

    //Check if stub bend and proj rinv consistent
    projseqs_[writeindex_] = projseq____;
    matches_[writeindex_] = (stubindex,projbuffer____.getAllProj());
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    writeindex_ = (good___&passphi&pass&table[index]) ? writeindexnext : writeindex_;
#ifdef DEBUG_ALL
    if(writeindex_ == writeindexnext) {
    ap_uint<VMProjectionBase<VMProjType>::kVMProjFineZSize+1> idz = stubfinez - projfinezadj___;
    std::cout << std::hex << "MEU " << unit_ << " checking stubid=" << stubindex << " (" << std::bitset<8>(stubindex) << ")" << " stub=" << stubdata___.raw() << " against proj=" << projbuffer___.getAllProj() << " with vmproj=" << projbuffer___.getProjection() << std::endl;
    std::cout << "stubfinez=" << stubfinez << " (" << std::bitset<stubfinezbits>(stubfinez) << ")\t" << "projfinezadj___=" << projfinezadj___ << " (" << std::bitset<projfinezbits>(projfinezadj___) << ")\t" << idz << "\t";
    if (!isDisk) {
      if (isPSseed___) std::cout << StubZPositionBarrelConsistency::kBarrelPSMax;
      else std::cout << StubZPositionBarrelConsistency::kBarrel2SMax;
    }
    else {
      if (isPSseed___) std::cout << StubZPositionDiskConsistency::kDiskPSMax;
      else std::cout << StubZPositionDiskConsistency::kDisk2SMax;
    }
    std::cout << std::endl;
    }
#endif

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
  return !idle_||good__||good___||good____;
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
    (vmstub,allprojdata) = matches_[readindex_];
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

inline ap_uint<kNBits_MemAddr> getProjSeq() {
#pragma HLS inline
  if (!empty()) {
    return projseqs_[readindex_];
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

 static constexpr int kNuse = 4; // Only 4 options
 //Current projection
 ap_uint<4> nstubsall_[4];
 NSTUB istub_;
 NSTUBS nstubs_;
 ap_uint<4> stubmask_;
 ap_uint<1> second_;
 ap_uint<1> phiPlus_;
 typename ProjectionRouterBuffer<BARREL, AllProjectionType>::PHIPROJBIN phiProjBin_;
 bool idle_;
 ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> iphi_;
 BXType bx_;
 bool empty_;
 VMStubMECM<VMSMEType> stubdata__, stubdata__t, stubdata___; 
 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<BARREL, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;

 NSTUB iuse_;
 static constexpr int kNuse = 4; // Only 4 options
 int nuse_;
 ap_uint<2> use_[kNuse];


 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::VMPZBINNOFLAG zbin;

 //Pipeline variables
 bool good__, good___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinephi__, projfinephi___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj__t, projfinezadj___;
 bool isPSseed__, isPSseed___;
 typename VMProjection<VMProjType>::VMPRINV projrinv__, projrinv___;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer__, projbuffer___;
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
