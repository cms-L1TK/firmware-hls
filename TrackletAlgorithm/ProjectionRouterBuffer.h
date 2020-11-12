#ifndef PRBUFFERMEMORY_HH
#define PRBUFFERMEMORY_HH

#include "Constants.h"
#include "MemoryTemplate.h"
#include "VMProjectionMemory.h"

// ProjectionRouterBufferBase is where we define the bit widths, which depend on the class template parameter.
template<int VMProjType> class ProjectionRouterBufferBase {};

template<>
class ProjectionRouterBufferBase<BARREL>// : public VMProjectionBase<BARREL>
{
public:
  enum BitWidths {
    // Bit sizes for ProjectionRouterBufferMemory fields
    kPRBufferIsPSSeedSize = 1,
    kPRBufferZBinSize = MEBinsBits+1,
    kPRBufferNStubsSize = kNBits_MemAddrBinned,
    kPRBufferIndexSize = 7,
    kPRBufferHasSecondSize = 1,
    kPRBufferTCIDSize = 7,
    kPRBufferPhiSize = 3,
    // Bit size for full ProjectionRouterBufferMemory
    kProjectionRouterBufferSize = kPRBufferPhiSize + kPRBufferTCIDSize + kPRBufferIsPSSeedSize + kPRBufferIndexSize + kPRBufferNStubsSize + VMProjectionBase<BARREL>::kVMProjectionSize + kPRBufferZBinSize + kPRBufferHasSecondSize
  };
};

template<>
class ProjectionRouterBufferBase<DISK>// : public VMProjectionBase<DISK>
{
public:
  enum BitWidths {
    // Bit sizes for ProjectionRouterBufferMemory fields
    kPRBufferIsPSSeedSize = 0,
    //kPRProjSize = VMProjection<VMPTYPE>::kVMProjectionSize,
    kPRBufferZBinSize = MEBinsBits+1+1,
    kPRBufferNStubsSize = kNBits_MemAddrBinned,
    kPRBufferIndexSize = 7,
    kPRBufferHasSecondSize = 1,
    kPRBufferTCIDSize = 7,
    // Bit size for full ProjectionRouterBufferMemory
    kProjectionRouterBufferSize = kPRBufferTCIDSize + kPRBufferIsPSSeedSize + kPRBufferIndexSize + VMProjectionBase<DISK>::kVMProjectionSize + kPRBufferZBinSize + kPRBufferNStubsSize + kPRBufferHasSecondSize
  };
};


// Data object definition
template<int VMProjType>
class ProjectionRouterBuffer : public ProjectionRouterBufferBase<VMProjType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the ProjectionRouterBufferMemory word for different fields
    kPRBufferIsPSSeedLSB = 0,
    kPRBufferIsPSSeedMSB = kPRBufferIsPSSeedLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferIsPSSeedSize - 1,
    kPRBufferZBinLSB = kPRBufferIsPSSeedMSB + 1,
    kPRBufferZBinMSB = kPRBufferZBinLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferZBinSize - 1,
    kPRProjLSB = kPRBufferZBinMSB + 1,
    kPRProjMSB = kPRProjLSB + VMProjection<VMProjType>::kVMProjectionSize - 1,
    kPRProjNStubsLSB = kPRProjMSB + 1,
    kPRProjNStubsMSB = kPRProjNStubsLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferNStubsSize - 1,
    kPRBufferIndexLSB = kPRProjNStubsMSB + 1,
    kPRBufferIndexMSB = kPRBufferIndexLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferIndexSize - 1,
    kPRBufferHasSecondLSB = kPRBufferIndexMSB + 1,
    kPRBufferHasSecondMSB = kPRBufferHasSecondLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferHasSecondSize - 1,
    kPRBufferTCIDLSB = kPRBufferHasSecondLSB + 1,
    kPRBufferTCIDMSB = kPRBufferTCIDLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferTCIDSize - 1,
    kPRBufferPhiLSB = kPRBufferTCIDMSB + 1,
    kPRBufferPhiMSB = kPRBufferPhiLSB + ProjectionRouterBufferBase<VMProjType>::kPRBufferPhiSize - 1
  };
  
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferIndexSize> VMPID;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferHasSecondSize> PRHASSEC;
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjectionSize> VMProjData;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferNStubsSize> PRNSTUB;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferZBinSize> VMPZBIN;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kProjectionRouterBufferSize> ProjBuffer;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferTCIDSize> TCID;
  typedef ap_uint<ProjectionRouterBufferBase<VMProjType>::kPRBufferPhiSize> PRPHI;

  // Constructors
  ProjectionRouterBuffer(const ProjBuffer& newdata):
    data_(newdata)
  {}

  // This constructor is only used for projections in BARREL
  ProjectionRouterBuffer(const TCID tcid, const PRHASSEC hasSec, const VMPID index, const PRNSTUB nstub, const VMPZBIN zbin, const VMProjData projdata, const bool ps):
    data_( ((((((tcid,hasSec),index),nstub),projdata),zbin),ps) )
  {
    static_assert(VMProjType == BARREL, "Constructor should only be used for BARREL projections");
    VMProjection<BARREL> vmproj(projdata);
    setIndex(vmproj.getIndex()); //FIXME error with data_ constructor not setting projindex correctly
    std::cout << "Creating new projrouterbuffer with projid=" << getIndex() << "\twith internal projid=" << vmproj.getIndex() << std::endl;
    setNStubs(nstub); //FIXME error with data_ constructor not setting nstubs correctly
    setHasSecond(hasSec); //FIXME error with data_ constructor not setting hasSec correctly
  }

  // This constructor is only used for projections in DISK
  ProjectionRouterBuffer(const PRHASSEC hasSec, const VMPID index, const PRNSTUB nstub, const VMPZBIN zbin, const VMProjData projdata):
    data_( ((((hasSec,index),nstub),projdata),zbin) )
  {
    static_assert(VMProjType == DISK, "Constructor should only be used for DISK projections");
  }

  ProjectionRouterBuffer():
    data_(0)
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
    std::cout << "Contents in buffer:" << std::endl;
    std::cout << std::hex << "tcid=" << getTCID() << " sec=" << hasSecond() << " nstub=" << getNStubs() << " zbin=" << getZBin() << " projid=" << getIndex() << " proj=" << getProjection() << " isPS=" << getIsPSSeed() << std::endl;
  }
  #endif
  
  // Getter
  ProjBuffer raw() const {return data_;}

  TCID getTCID() const {
    return data_.range(kPRBufferTCIDMSB,kPRBufferTCIDLSB);
  }
  
  PRHASSEC hasSecond() const {
    return data_.range(kPRBufferHasSecondMSB,kPRBufferHasSecondLSB);
  }

  VMPZBIN getZBin() const {
    return data_.range(kPRBufferZBinMSB,kPRBufferZBinLSB);
  }

  VMProjData getProjection() const {
    return data_.range(kPRProjMSB,kPRProjLSB);
  }

  PRNSTUB getNStubs() const {
    return data_.range(kPRProjNStubsLSB,kPRProjNStubsMSB);
  }

  VMPID getIndex() const {
    return data_.range(kPRBufferIndexLSB,kPRBufferIndexMSB);
  }

  // This getter is only used for projections in BARREL
  PRHASSEC getIsPSSeed() {
    static_assert("VMProjType == BARREL", "Setter should only be used for BARREL projections");
    return data_.range(kPRBufferIsPSSeedLSB,kPRBufferIsPSSeedMSB);
  }

  PRPHI getPhi() {
    static_assert("VMProjType == BARREL", "Setter should only be used for BARREL projections");
    return data_.range(kPRBufferPhiLSB,kPRBufferPhiMSB);
  }
  
  // Setter
  void setTCID(const TCID tcid) {
    data_.range(kPRBufferTCIDMSB,kPRBufferTCIDLSB) = tcid;
  }

  void setHasSecond(const PRHASSEC hasSec) {
    data_.range(kPRBufferHasSecondMSB,kPRBufferHasSecondLSB) = hasSec;
  }
  
  void setZBin(const VMPZBIN zbin) {
    data_.range(kPRBufferZBinMSB,kPRBufferZBinLSB) = zbin;
  }
  
  void setProjection(const VMProjData projdata) {
    data_.range(kPRProjMSB,kPRProjLSB) = projdata;
  }
  
  void setNStubs(const PRNSTUB nstubs) {
    data_.range(kPRProjNStubsLSB,kPRProjNStubsMSB) = nstubs;
  }

  void setIndex(const VMPID index) {
    data_.range(kPRBufferIndexLSB,kPRBufferIndexMSB) = index;
  }


  // This setter is only used for projections in BARREL
  void setIsPSSeed(const bool psseed) {
    static_assert("VMProjType == BARREL", "Setter should only be used for BARREL projections");
    data_.range(kPRBufferIsPSSeedLSB,kPRBufferIsPSSeedMSB) = psseed;
  }

  // This setter is only used for projections in BARREL
  void setPhi(const PRPHI phi) {
    static_assert("VMProjType == BARREL", "Setter should only be used for BARREL projections");
    data_.range(kPRBufferPhiLSB,kPRBufferPhiMSB) = phi;
  }
  
private:
  
  ProjBuffer data_;
  
};

// Memory definition
template<int VMProjType> using ProjectionRouterBufferMemory = MemoryTemplate<ProjectionRouterBuffer<VMProjType>, 1, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
