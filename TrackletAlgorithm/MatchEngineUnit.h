#ifndef MATCHENGINEUNIT_H
#define MATCHENGINEUNIT_H

#include "Constants.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMemory.h"
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

template<int VMSType, unsigned kNbitsrzbinMP, int VMProjType, int AllProjectionType, TF::layerDisk LAYER, int ASTYPE>
class MatchEngineUnit : public MatchEngineUnitBase<VMProjType> {

 public:
  typedef ap_uint<VMStubBase<VMSType>::kVMSIDSize> MATCH;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUB;
  typedef ap_uint<kNBits_MemAddrBinned*4> NSTUBS;
  typedef ap_uint<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> INDEX;

  inline MatchEngineUnit() {}

  inline void reset() {
#pragma HLS inline
    writeindex_ = 0;
    readindex_ = 0;
    readindexnext = 1;
    stubmask_ = 0;
    nstubs_ = 0;
    idle_ = true;
    empty_ = true;
    good__ = false;
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



inline void step(const VMStub<VMSType> stubmem[4][1<<(kNbitsrzbinMP+kNbitsphibin+4)]) {
#pragma HLS inline
#pragma HLS array_partition variable=nstubsall_ complete dim=1
  
  bool nearfull = nearFull();

  good__ = (!idle_) && (!nearfull);

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  
  NSTUB istubtmp=istub_;
  ap_uint<2> iusetmp=iuse_;

  ap_uint<VMStubBase<VMSType>::kVMSFinePhiSize> iphiSave = iphi_ + use_[iusetmp].range(0,0);
  auto secondSave = second_;

  VMProjection<VMProjType> data(projbuffer_.getProjection());

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
  const int nphibins = 3; //number of bits for phi bins in VM memory not that L1 actually only uses 2 bits
  ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = iphi_ + use_[iusetmp].range(0,0) + (zbin_ + use_[iusetmp].range(1,1)) * (1 << nphibins);

  //The previous line should be like below after L1 is fixed to use four phi bins in the memories
  //ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize -1 + kNBits_MemAddrBinned> slot = iphi_ + use_[iusetmp].range(0,0) + (zbin_ + use_[iusetmp].range(1,1)) * (1 << nbits_vmmeall[LAYER]);

  zbin__ = zbin_ + use_[iusetmp].range(1,1);

  //Read stub memory and extract data fields
  auto stubadd=(slot,istubtmp);
  stubdata__ = stubmem[bx_&1][stubadd];

  //if (good__) {
  //  std::cout << "Read vmstub MEU: " << unit_ << " " << slot << " "
  //	      << iphi_ + use_[iusetmp].range(0,0) << " "
  //	      << zbin_ + use_[iusetmp].range(1,1) << " "
  //	      << (stubadd&15) << " " << stubdata__.getBend() <<std::endl;
  //}
  
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
   
  projseq__ = projseq_;

} // end step




  inline void processPipeLine(ap_uint<1> *table) {
#pragma HLS inline

    auto stubindex=stubdata___.getIndex();
    auto stubfinez=stubdata___.getFineZ();
    auto stubfinephi=stubdata___.getFinePhi();
    auto stubbend=stubdata___.getBend();
    constexpr int absz = (1 << MatchEngineUnitBase<VMProjType>::kNBitsBuffer) - 1;
    //
    // The geometry for D1 and D2 vs the other 3 disks is slightly different. In the code segment below we use the
    // rbin and finer (confusingly named zbin and stubfinez as the same code is used for both barrel and disks).
    // In D1 and D2 we have PS modules if the zbin<3 or if zbin=3 and the fine r position <=3
    // In D3, D4, and D5 the same is true with the difference that the fine r position <=2
    //
    const bool isPSStub = VMProjType==BARREL ? LAYER <= TF::L3 : 
                                               LAYER <= TF::D2 ? ((zbin___ & absz) < 3) || ((zbin___ & absz) == 3 && stubfinez <= 3) :
                                                                 ((zbin___ & absz) < 3) || ((zbin___ & absz) == 3 && stubfinez <= 2);
    auto stubbendReduced=stubdata___.getBendPSDisk();

    constexpr bool isDisk = LAYER > TF::L6;

    constexpr auto kNBitBinPS = 3;
    constexpr auto kNBitBin2S = 4;
    const unsigned int kNBitBin = isPSStub ? kNBitBinPS : kNBitBin2S;
    constexpr unsigned int kRInvSteps = 32;
    constexpr unsigned int kRInvBits = BITS_TO_REPRESENT(kRInvSteps - 1);
    
    bool phiLUT = isLessThanSizeBool<projfinephibits,StubPhiPositionConsistency::kMax,false,projfinephibits,stubfinephibits>(projfinephi___,stubfinephi);
    bool stubZBarrelPS = isLessThanSizeBool<projfinephibits,StubZPositionBarrelConsistency::kBarrelPSMax,true,stubfinephibits,projfinephibits>(stubfinez,projfinezadj___);
    bool stubZBarrel2S = isLessThanSizeBool<projfinephibits,StubZPositionBarrelConsistency::kBarrel2SMax,true,stubfinephibits,projfinephibits>(stubfinez,projfinezadj___);
    bool stubZDiskPS = isLessThanSizeBool<projfinephibits,StubZPositionDiskConsistency::kDiskPSMax,true,stubfinephibits,projfinephibits>(stubfinez,projfinezadj___);
    bool stubZDisk2S = isLessThanSizeBool<projfinephibits,StubZPositionDiskConsistency::kDisk2SMax,true,stubfinephibits,projfinephibits>(stubfinez,projfinezadj___);
    bool passphi = phiLUT;//isLessThanSizeBool<projfinephibits,StubPhiPositionConsistency::kMax,false,projfinephibits,stubfinephibits>()(projfinephi___,stubfinephi);
    
    //Check if stub z position consistent
    bool pass = false;
    if(!isDisk) {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kBarrel(PS|2S)Max
      pass = isPSseed___ ? stubZBarrelPS : stubZBarrel2S;
    }
    else {
      // check if abs(projfinezadj___ - stubfinez) < StubZPositionBarrelConsistency::kDisk(PS|2S)Max
      pass = isPSStub ? stubZDiskPS : stubZDisk2S;
    }

    //here we always use the larger number of bits for the bend
    // Check if stub bend and proj rinv consistent
    ap_uint<kNBitBin2S+kRInvBits+1> diskps = isDisk && isPSStub;
    ap_uint<kRInvBits+kNBitBin2S> projrinv_long = projrinv___;
    const ap_uint<1+kNBitBin2S+kRInvBits> index = (diskps << (kNBitBin2S + kRInvBits)) + (projrinv_long << kNBitBin) + (diskps ? ap_uint<kNBitBin2S>(stubbendReduced) : ap_uint<kNBitBin2S>(stubbend));

    //Check if stub bend and proj rinv consistent
    projseqs_[writeindex_] = projseq___;
    matches_[writeindex_] = stubindex;
    INDEX writeindexnext = writeindex_ + 1;
    
    //Though we did write to matches_ above only now do we increment
    //the writeindex_ if we had a good stub that pass the various cuts
    writeindex_ = (good___&passphi&pass&table[index]) ? writeindexnext : writeindex_;

    //if (good___) {
    //  std::cout << "CAndidateMatc: " << unit_ << " " << index << " "
    //		<< table[index] << " " << pass << " "  << passphi << " "
    //		<< stubfinephi << " " << projfinephi___ << std::endl;
    //}
    
    good___ = good__;
    stubdata___ = stubdata__;
    projfinephi___ = projfinephi__;
    projfinezadj___ = projfinezadj__;
    isPSseed___ = isPSseed__;
    projrinv___ = projrinv__;
    projseq___ = projseq__;
    zbin___ = zbin__;

    
  }

#ifndef __SYNTHESIS__
  inline void setUnit(int unit) {
    unit_ = unit;
  }

#endif

 inline void set_empty() {
   static const emptyUnitClass<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> EmptyUnitClass;
   empty_ = EmptyUnitClass.lut[(readindex_,writeindex_)];
   //empty_ = emptyUnit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
 }

 inline bool empty() const {
#pragma HLS inline  
   return empty_;
 }
 
 inline bool nearFull() {
   static const nearFull3Class<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> NearFull3Class;
   return NearFull3Class.lut[(readindex_,writeindex_)];
   //return nearFull3Unit<MatchEngineUnitBase<VMProjType>::kNBitsBuffer>()[(readindex_,writeindex_)];
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

//
// Get start of projseq pipeline 
//
inline ap_uint<kNBits_MemAddr> getProjSeqStart() {
#pragma HLS inline
  if (idle_) {
    ap_uint<kNBits_MemAddr> tmp(0);
    return ~tmp;
  }
  return projseq_;
}


  
inline ap_uint<kNBits_MemAddr> getProjSeq() {
#pragma HLS inline
#pragma HLS array_partition variable=projseqs_ complete 
  ap_uint<kNBits_MemAddr> tmp(0);
  return empty()?(~tmp):projseqs_[readindex_];
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
  readindex_ = readindexnext;
  readindexnext = readindex_+1;  
}

 private:

 //Buffers for the matches
 INDEX writeindex_, readindex_, readindexnext;
 MATCH matches_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
 ap_uint<kNBits_MemAddr> projseqs_[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];

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
 ap_uint<VMStubBase<VMSType>::kVMSFinePhiSize> iphi_;
 BXType bx_;
 bool empty_;
 VMStub<VMSType> stubdata__, stubdata___; 
 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::TCID tcid_;
 ProjectionRouterBuffer<VMProjType, AllProjectionType> projbuffer_;
 ap_uint<kNBits_MemAddr> projseq_;
 bool isPSseed_;

 ap_uint<2> iuse_;
 int nuse_;
 ap_uint<2> use_[kNuse];


 typename ProjectionRouterBuffer<VMProjType, AllProjectionType>::VMPZBINNOFLAG zbin_, zbin__, zbin___;

 //Pipeline variables
 bool good__, good___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinephi__, projfinephi___;
 ap_uint<VMProjectionBase<VMProjType>::kVMProjFinePhiWideSize> projfinezadj__, projfinezadj___;
 bool isPSseed__, isPSseed___;
 typename VMProjection<VMProjType>::VMPRINV projrinv__, projrinv___;
 ap_uint<kNBits_MemAddr> projseq__, projseq___;

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
 static constexpr int stubfinephibits = VMStubBase<VMSType>::kVMSFinePhiSize;
 static constexpr int stubfinezbits = VMStubBase<VMSType>::kVMSFineZSize;


#ifndef __SYNTHESIS__
 // only used for debugging to identify MEU
 int unit_;  
#endif

 
}; // end class

#endif
