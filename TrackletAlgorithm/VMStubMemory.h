#ifndef TrackletAlgorithm_VMStubMemory_h
#define TrackletAlgorithm_VMStubMemory_h

#include "Constants.h"
#include "MemoryTemplateBinnedCM.h"
#include "globalFunctions.h"

// Memory containing stub data written by the VMRouter, consisting of coarse
// stub data + a pointer to the full precision stub data in the AllStubMemory.

// VMStubBase is where we define the bit widths, which depend on the class template parameter.
template<int VMSType> class VMStubBase {};

template<>
class VMStubBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMemory fields
    kVMSFineZSize = 3,
    kVMSFinePhiSize = 3,
    kVMSBendSize = 3,
    kVMSIDSize = 7,
    // Bit size for full VMStubMemory
    kVMStubSize = kVMSFineZSize + kVMSFinePhiSize + kVMSBendSize + kVMSIDSize
  };
};

template<>
class VMStubBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMemory fields
    kVMSFineZSize = 3,
    kVMSFinePhiSize = 3,
    kVMSBendSize = 4,
    kVMSIDSize = 7,
    // Bit size for full VMStubMemory
    kVMStubSize = kVMSFineZSize + kVMSFinePhiSize + kVMSBendSize + kVMSIDSize
  };
};

template<>
class VMStubBase<DISK>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMemory fields
    kVMSFineZSize = 3,
    kVMSFinePhiSize = 3,
    kVMSBendSize = 4,
    kVMSIDSize = 7,
    // Bit size for full VMStubMemory
    kVMStubSize = kVMSFineZSize + kVMSFinePhiSize + kVMSBendSize + kVMSIDSize
  };
};

// Data object definition
template<int VMSType>
class VMStub : public VMStubBase<VMSType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMemory word for different fields
    kVMSFineZLSB = 0,
    kVMSFineZMSB = kVMSFineZLSB + VMStubBase<VMSType>::kVMSFineZSize - 1,
    kVMSFinePhiLSB = kVMSFineZMSB + 1,
    kVMSFinePhiMSB = kVMSFinePhiLSB + VMStubBase<VMSType>::kVMSFinePhiSize - 1,
    kVMSBendLSB = kVMSFinePhiMSB + 1,
    kVMSBendMSB = kVMSBendLSB + VMStubBase<VMSType>::kVMSBendSize - 1,
    kVMSIDLSB = kVMSBendMSB + 1,
    kVMSIDMSB = kVMSIDLSB + VMStubBase<VMSType>::kVMSIDSize - 1
  };

  typedef ap_uint<VMStubBase<VMSType>::kVMSIDSize> VMSID;
  typedef ap_uint<VMStubBase<VMSType>::kVMSBendSize> VMSBEND;
  typedef ap_uint<VMStubBase<VMSType>::kVMSBendSize - 1> VMSBENDPSDISK;
  typedef ap_uint<VMStubBase<VMSType>::kVMSFineZSize> VMSFINEZ;
  typedef ap_uint<VMStubBase<VMSType>::kVMSFinePhiSize> VMSFINEPHI;

  typedef ap_uint<VMStubBase<VMSType>::kVMStubSize> VMStubData;

  // Constructors
  VMStub(const VMStubData& newdata):
    data_(newdata)
  {}

 VMStub(const VMSID id, const VMSBEND bend, const VMSFINEPHI finephi, const VMSFINEZ finez):
    data_( (id, bend,finephi, finez) )
  {}

  VMStub()
  {}

  #ifndef __SYNTHESIS__
  VMStub(const char* datastr, int base=16)
  {
    VMStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return VMStubBase<VMSType>::kVMStubSize;}

  VMStubData raw() const {return data_;}

  VMSID getIndex() const {
    return data_.range(kVMSIDMSB,kVMSIDLSB);
  }

  VMSBEND getBend() const {
    return data_.range(kVMSBendMSB,kVMSBendLSB);
  }

  VMSBENDPSDISK getBendPSDisk() const {
    return data_.range(kVMSBendMSB - 1,kVMSBendLSB);
  }

  VMSFINEPHI getFinePhi() const {
    return data_.range(kVMSFinePhiMSB, kVMSFinePhiLSB);
  }

  VMSFINEZ getFineZ() const {
    return data_.range(kVMSFineZMSB,kVMSFineZLSB);
  }

  // Setter
  void setIndex(const VMSID id) {
    data_.range(kVMSIDMSB,kVMSIDLSB) = id;
  }

  void setBend(const VMSBEND bend) {
    data_.range(kVMSBendMSB,kVMSBendLSB) = bend;
  }

  void setFinePhi(const VMSFINEPHI finephi) {
    data_.range(kVMSFinePhiMSB,kVMSFinePhiLSB) = finephi;
  }

  void setFineZ(const VMSFINEZ finez) {
    data_.range(kVMSFineZMSB,kVMSFineZLSB) = finez;
  }

#ifdef CMSSW_GIT_HASH
  std::string getBitStr() const {
    std::string str = decodeToBits(getIndex());
    str += "|"+decodeToBits(getBend());
    str += "|"+decodeToBits(getFinePhi());
    str += "|"+decodeToBits(getFineZ());
    return str;
  }
#endif

private:

  VMStubData data_;

};

// Memory definition
template<int VMSType, int RZSize, int PhiRegSize, unsigned int NCOPY > using VMStubMemory = MemoryTemplateBinnedCM<VMStub<VMSType>, 1, 4+RZSize+PhiRegSize, RZSize+PhiRegSize, PhiRegSize, NCOPY>;

#endif
