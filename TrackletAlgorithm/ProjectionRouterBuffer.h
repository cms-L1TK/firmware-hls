#ifndef PRBUFFERMEMORY_HH
#define PRBUFFERMEMORY_HH

#include "Constants.h"
#include "MemoryTemplate.h"
#include "VMProjectionMemory.h"
#include "AllProjectionMemory.h"
#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

// ProjectionRouterBufferBase is where we define the bit widths, which depend on the class template parameter.
template<int VMProjType, int AllProjetionType> class ProjectionRouterBufferBase {};

template<int AllProjectionType>
class ProjectionRouterBufferBase<BARREL,AllProjectionType>// : public VMProjectionBase<BARREL>
{
public:
  enum BitWidths {
    // Bit sizes for ProjectionRouterBufferMemory fields
    kPRBufferIsPSSeedSize = 1,
    kPRBufferZBinSize = MEBinsBits+1,
    kPRBufferNStubsSize = 4*kNBits_MemAddrBinned,
    kPRBufferMaskStubsSize = 4,
    kPRBufferIndexSize = 7,
    kPRBufferShiftSize = 2,
    kPRBufferTCIDSize = 7,
    kPRBufferPhiSize = 3,
    kPRBufferUseSize = 1,
    // Bit size for full ProjectionRouterBufferMemory
    kProjectionRouterBufferSize = 2*kPRBufferPhiSize + 4*kPRBufferUseSize + kPRBufferTCIDSize + kPRBufferShiftSize + kPRBufferIndexSize + kPRBufferMaskStubsSize + kPRBufferNStubsSize + kPRBufferZBinSize + kPRBufferIsPSSeedSize + VMProjectionBase<BARREL>::kVMProjectionSize + AllProjection<AllProjectionType>::kAllProjectionSize
  };
};

template<int AllProjectionType>
class ProjectionRouterBufferBase<DISK,AllProjectionType>// : public VMProjectionBase<DISK>
{
public:
  enum BitWidths {
    // Bit sizes for ProjectionRouterBufferMemory fields
    kPRBufferIsPSSeedSize = 1,
    //kPRProjSize = VMProjection<VMPTYPE>::kVMProjectionSize,
    kPRBufferZBinSize = MEBinsBits+1+1,
    kPRBufferNStubsSize = 4*kNBits_MemAddrBinned,
    kPRBufferMaskStubsSize = 4,
    kPRBufferIndexSize = 7,
    kPRBufferShiftSize = 2,
    kPRBufferTCIDSize = 7,
    kPRBufferPhiSize = 3,
    kPRBufferUseSize = 1,
    // Bit size for full ProjectionRouterBufferMemory
    kProjectionRouterBufferSize = 2*kPRBufferPhiSize + 4*kPRBufferUseSize + kPRBufferTCIDSize + kPRBufferIsPSSeedSize + kPRBufferIndexSize + VMProjectionBase<DISK>::kVMProjectionSize + kPRBufferZBinSize + kPRBufferMaskStubsSize + kPRBufferNStubsSize + kPRBufferShiftSize + AllProjection<AllProjectionType>::kAllProjectionSize
  };
};


// Data object definition
template<int VMProjType, int AllProjectionType>
  class ProjectionRouterBuffer : public ProjectionRouterBufferBase<VMProjType, AllProjectionType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the ProjectionRouterBufferMemory word for different fields
    kPRBufferIsPSSeedLSB = 0,
    kPRBufferIsPSSeedMSB = kPRBufferIsPSSeedLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferIsPSSeedSize - 1,
    kPRBufferZBinLSB = kPRBufferIsPSSeedMSB + 1,
    kPRBufferZBinMSB = kPRBufferZBinLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize - 1,
    kPRProjLSB = kPRBufferZBinMSB + 1,
    kPRProjMSB = kPRProjLSB + VMProjectionBase<VMProjType>::kVMProjectionSize - 1,
    kPRProjNStubsLSB = kPRProjMSB + 1,
    kPRProjNStubsMSB = kPRProjNStubsLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferNStubsSize - 1,
    kPRBufferMaskStubsLSB = kPRProjNStubsMSB + 1,
    kPRBufferMaskStubsMSB = kPRBufferMaskStubsLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferMaskStubsSize - 1,
    kPRBufferIndexLSB = kPRBufferMaskStubsMSB + 1,
    kPRBufferIndexMSB = kPRBufferIndexLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferIndexSize - 1,
    kPRBufferShiftLSB = kPRBufferIndexMSB + 1,
    kPRBufferShiftMSB = kPRBufferShiftLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferShiftSize - 1,
    kPRBufferTCIDLSB = kPRBufferShiftMSB + 1,
    kPRBufferTCIDMSB = kPRBufferTCIDLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferTCIDSize - 1,
    kPRBufferIVMPlusLSB = kPRBufferTCIDMSB + 1,
    kPRBufferIVMPlusMSB = kPRBufferIVMPlusLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferPhiSize - 1,
    kPRBufferPhiLSB = kPRBufferIVMPlusMSB + 1,
    kPRBufferPhiMSB = kPRBufferPhiLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferPhiSize - 1,
    kPRBufferAllProjLSB = kPRBufferPhiMSB + 1,
    kPRBufferAllProjMSB = kPRBufferAllProjLSB + AllProjection<AllProjectionType>::kAllProjectionSize - 1,
    kPRBufferUseSecondPlusLSB = kPRBufferAllProjMSB + 1,
    kPRBufferUseSecondPlusMSB = kPRBufferUseSecondPlusLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferUseSize - 1,
    kPRBufferUseFirstPlusLSB = kPRBufferUseSecondPlusMSB + 1,
    kPRBufferUseFirstPlusMSB = kPRBufferUseFirstPlusLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferUseSize - 1,
    kPRBufferUseSecondMinusLSB = kPRBufferUseFirstPlusMSB + 1,
    kPRBufferUseSecondMinusMSB = kPRBufferUseSecondMinusLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferUseSize - 1,
    kPRBufferUseFirstMinusLSB = kPRBufferUseSecondMinusMSB + 1,
    kPRBufferUseFirstMinusMSB = kPRBufferUseFirstMinusLSB + ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferUseSize - 1,
  };
  
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferIndexSize> VMPID;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferShiftSize> SHIFT;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferMaskStubsSize> MASK;
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjectionSize> VMProjData;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferNStubsSize> PRNSTUB;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize> VMPZBIN;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferZBinSize-1> VMPZBINNOFLAG;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kProjectionRouterBufferSize> ProjBuffer;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferTCIDSize> TCID;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferPhiSize> PRPHI;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferUseSize> PRUSE;
  typedef typename AllProjection<AllProjectionType>::AllProjectionData ALLPROJ;

  typedef ap_uint<ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferTCIDSize+
    ProjectionRouterBufferBase<VMProjType, AllProjectionType>::kPRBufferIndexSize> TRKID;

  // Constructors
 ProjectionRouterBuffer(const ProjBuffer& newdata):
  data_(newdata)
  {}
  
  // This constructor is only used for projections in BARREL
 ProjectionRouterBuffer(const ALLPROJ allproj, const PRPHI phi, const PRPHI ivmPlus, const SHIFT shift, const TCID tcid, const MASK mask, const PRNSTUB nstub, const VMPZBIN zbin, const VMProjection<VMProjType> projdata, const bool ps, const PRUSE usefirstMinus, const PRUSE usesecondMinus, const PRUSE usefirstPlus, const PRUSE usesecondPlus):
  data_( (usefirstMinus, usesecondMinus, usefirstPlus, usesecondPlus, allproj, phi, ivmPlus, tcid, shift, projdata.getIndex(), mask, nstub, projdata.raw(), zbin, ap_uint<1>(ps)) )
  {
  }

  // This constructor is only used for projections in DISK
  ProjectionRouterBuffer(const SHIFT shift, const VMPID index, const PRNSTUB nstub, const VMPZBIN zbin, const VMProjData projdata):
    data_( ((((shift,index),nstub),projdata),zbin) )
  {
    static_assert(VMProjType == DISK, "Constructor should only be used for DISK projections");
  }

  ProjectionRouterBuffer()
  {}
  
  

  #ifndef __SYNTHESIS__
  ProjectionRouterBuffer(const char* datastr, int base=16)
  {
    ProjBuffer newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  #ifndef __SYNTHESIS__
  void Print()
  {
    edm::LogVerbatim("L1trackHLS") << "Contents in buffer:" << std::endl;
    edm::LogVerbatim("L1trackHLS") << std::hex << "tcid=" << getTCID() << " shift=" << shift() << " nstub=" << getNStubs() << " zbin=" << getZBin() << " VMProj zbin=" << VMProjection<VMProjType>(getProjection()).getZBin() << " projid=" << getIndex() << " proj=" << getProjection() << " isPS=" << getIsPSSeed() << std::endl;
  }
  #endif
  
  // Getter
  ProjBuffer raw() const {return data_;}

  TCID getTCID() const {
    return data_.range(kPRBufferTCIDMSB,kPRBufferTCIDLSB);
  }
  
  SHIFT shift() const {
    return data_.range(kPRBufferShiftMSB,kPRBufferShiftLSB);
  }

  VMPZBIN getZBin() const {
    return data_.range(kPRBufferZBinMSB,kPRBufferZBinLSB);
  }

  VMProjData getProjection() const {
    return data_.range(kPRProjMSB,kPRProjLSB);
  }

  PRNSTUB getNStubs() const {
    return data_.range(kPRProjNStubsMSB,kPRProjNStubsLSB);
  }

  MASK getMaskStubs() const {
    return data_.range(kPRBufferMaskStubsMSB,kPRBufferMaskStubsLSB);
  }

  VMPID getIndex() const {
    return data_.range(kPRBufferIndexMSB,kPRBufferIndexLSB);
  }

  // This getter is only used for projections in BARREL
  bool getIsPSSeed() {
    static_assert("VMProjType == BARREL", "Setter should only be used for BARREL projections");
    return data_.range(kPRBufferIsPSSeedMSB,kPRBufferIsPSSeedLSB);
  }

  PRPHI getPhi() {
    return data_.range(kPRBufferPhiMSB,kPRBufferPhiLSB);
  }

  PRPHI getIVMPlus() {
    return data_.range(kPRBufferIVMPlusMSB,kPRBufferIVMPlusLSB);
  }

  PRUSE getUseFirstMinus() {
    return data_.range(kPRBufferUseFirstMinusMSB,kPRBufferUseFirstMinusLSB);
  }

  PRUSE getUseSecondMinus() {
    return data_.range(kPRBufferUseSecondMinusMSB,kPRBufferUseSecondMinusLSB);
  }

  PRUSE getUseFirstPlus() {
    return data_.range(kPRBufferUseFirstPlusMSB,kPRBufferUseFirstPlusLSB);
  }

  PRUSE getUseSecondPlus() {
    return data_.range(kPRBufferUseSecondPlusMSB,kPRBufferUseSecondPlusLSB);
  }
  
  ALLPROJ getAllProj() {
    return data_.range(kPRBufferAllProjMSB,kPRBufferAllProjLSB);
  }

  typename AllProjection<AllProjectionType>::AProjPHIDER getPhiDer() {
    return AllProjection<AllProjectionType>(getAllProj()).getPhiDer();
  }
  
  // Setter
  void setTCID(const TCID tcid) {
    data_.range(kPRBufferTCIDMSB,kPRBufferTCIDLSB) = tcid;
  }

  void setShift(const SHIFT shift) {
    data_.range(kPRBufferShiftMSB,kPRBufferShiftLSB) = shift;
  }

  void setZBin(const VMPZBIN zbin) {
    data_.range(kPRBufferZBinMSB,kPRBufferZBinLSB) = zbin;
  }
  
  void setProjection(const VMProjData projdata) {
    data_.range(kPRProjMSB,kPRProjLSB) = projdata;
  }
  
  void setNStubs(const PRNSTUB nstubs) {
    data_.range(kPRProjNStubsMSB,kPRProjNStubsLSB) = nstubs;
  }

  void setMaskStubs(const MASK mask) const {
    data_.range(kPRBufferMaskStubsMSB,kPRBufferMaskStubsMSB) = mask;
  }

  void setIndex(const VMPID index) {
    data_.range(kPRBufferIndexMSB,kPRBufferIndexLSB) = index;
  }


  // This setter is only used for projections in BARREL
  void setIsPSSeed(const bool psseed) {
    data_.range(kPRBufferIsPSSeedMSB,kPRBufferIsPSSeedLSB) = psseed;
  }

  // This setter is only used for projections in BARREL
  void setPhi(const PRPHI phi) {
    data_.range(kPRBufferPhiMSB,kPRBufferPhiLSB) = phi;
  }

  void setIVMPlus(const PRPHI ivmPlus) {
    data_.range(kPRBufferIVMPlusMSB,kPRBufferIVMPlusLSB) = ivmPlus;
  }
  
  void setAllProj(const ALLPROJ& allProj) {
    data_.range(kPRBufferAllProjMSB,kPRBufferAllProjLSB) = allProj;
  }

  void setUseFirstMinus(const PRUSE use) {
    data_.range(kPRBufferUseFirstMinusMSB, kPRBufferUseFirstMinusLSB) = use;
  }

  void setUseSecondMinus(const PRUSE use) {
    data_.range(kPRBufferUseSecondMinusMSB, kPRBufferUseSecondMinusLSB) = use;
  }

  void setUseFirstPlus(const PRUSE use) {
    data_.range(kPRBufferUseFirstPlusMSB, kPRBufferUseFirstPlusLSB) = use;
  }

  void setUseSecondPlus(const PRUSE use) {
    data_.range(kPRBufferUseSecondPlusMSB, kPRBufferUseSecondPlusLSB) = use;
  }
  
private:
  
  ProjBuffer data_;
  
};

// Memory definition
template<int VMProjType, int AllProjectionType> using ProjectionRouterBufferMemory = MemoryTemplate<ProjectionRouterBuffer<VMProjType, AllProjectionType>, 1, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
