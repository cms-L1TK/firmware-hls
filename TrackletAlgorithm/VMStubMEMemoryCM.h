#ifndef TrackletAlgorithm_VMStubMEMemoryCM_h
#define TrackletAlgorithm_VMStubMEMemoryCM_h

#include "Constants.h"
#include "MemoryTemplateBinnedCM.h"
#include "globalFunctions.h"

// VMStubMECMBase is where we define the bit widths, which depend on the class template parameter.
template<int VMSMEType> class VMStubMECMBase {};

template<>
class VMStubMECMBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMEMemoryCM fields
    kVMSMEFineZSize = 3,
    kVMSMEFinePhiSize = 3,
    kVMSMEBendSize = 3,
    kVMSMEIDSize = 7,
    // Bit size for full VMStubMEMemoryCM
    kVMStubMECMSize = kVMSMEFineZSize + kVMSMEFinePhiSize + kVMSMEBendSize + kVMSMEIDSize
  };
};

template<>
class VMStubMECMBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMEMemoryCM fields
    kVMSMEFineZSize = 3,
    kVMSMEFinePhiSize = 3,
    kVMSMEBendSize = 4,
    kVMSMEIDSize = 7,
    // Bit size for full VMStubMEMemoryCM
    kVMStubMECMSize = kVMSMEFineZSize + kVMSMEFinePhiSize + kVMSMEBendSize + kVMSMEIDSize
  };
};

template<>
class VMStubMECMBase<DISK>
{
public:
  enum BitWidths {
    // Bit sizes for VMStubMEMemoryCM fields
    kVMSMEFineZSize = 3,
    kVMSMEFinePhiSize = 3,
    kVMSMEBendSize = 4,
    kVMSMEIDSize = 7,
    // Bit size for full VMStubMEMemoryCM
    kVMStubMECMSize = kVMSMEFineZSize + kVMSMEFinePhiSize + kVMSMEBendSize + kVMSMEIDSize
  };
};

// Data object definition
template<int VMSMEType>
class VMStubMECM : public VMStubMECMBase<VMSMEType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMEMemoryCM word for different fields
    kVMSMEFineZLSB = 0,
    kVMSMEFineZMSB = kVMSMEFineZLSB + VMStubMECMBase<VMSMEType>::kVMSMEFineZSize - 1,
    kVMSMEFinePhiLSB = kVMSMEFineZMSB + 1,
    kVMSMEFinePhiMSB = kVMSMEFinePhiLSB + VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize - 1,
    kVMSMEBendLSB = kVMSMEFinePhiMSB + 1,
    kVMSMEBendMSB = kVMSMEBendLSB + VMStubMECMBase<VMSMEType>::kVMSMEBendSize - 1,
    kVMSMEIDLSB = kVMSMEBendMSB + 1,
    kVMSMEIDMSB = kVMSMEIDLSB + VMStubMECMBase<VMSMEType>::kVMSMEIDSize - 1
  };

  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> VMSMEID;
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEBendSize> VMSMEBEND;
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEBendSize - 1> VMSMEBENDPSDISK;
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFineZSize> VMSMEFINEZ;
  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize> VMSMEFINEPHI;

  typedef ap_uint<VMStubMECMBase<VMSMEType>::kVMStubMECMSize> VMStubMECMData;

  // Constructors
  VMStubMECM(const VMStubMECMData& newdata):
    data_(newdata)
  {}

 VMStubMECM(const VMSMEID id, const VMSMEBEND bend, const VMSMEFINEPHI finephi, const VMSMEFINEZ finez):
    data_( (id, bend,finephi, finez) )
  {}

  VMStubMECM()
  {}

  #ifndef __SYNTHESIS__
  VMStubMECM(const char* datastr, int base=16)
  {
    VMStubMECMData newdata(datastr, base);
    data_ = newdata;
  }
  void Print()
  {
    std::cout << std::hex << data_ << std::endl;
    std::cout << std::bitset<VMStubMECMBase<VMSMEType>::kVMSMEIDSize>(getIndex()) << "|" << std::bitset<VMStubMECMBase<VMSMEType>::kVMSMEBendSize>(getBend()) << "|" << std::bitset<VMStubMECMBase<VMSMEType>::kVMSMEFinePhiSize>(getFinePhi()) << "|" << std::bitset<VMStubMECMBase<VMSMEType>::kVMSMEFineZSize>(getFineZ()) << std::endl;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return VMStubMECMBase<VMSMEType>::kVMStubMECMSize;}

  VMStubMECMData raw() const {return data_;}

  VMSMEID getIndex() const {
    return data_.range(kVMSMEIDMSB,kVMSMEIDLSB);
  }

  VMSMEBEND getBend() const {
    return data_.range(kVMSMEBendMSB,kVMSMEBendLSB);
  }

  bool isPSStub() const {
    if(VMSMEType == BARRELPS) return true;
    else if(VMSMEType == BARREL2S) return false;
    else if(VMSMEType == DISK) return (getBend() & (1 << (VMStubMECMBase<VMSMEType>::kVMSMEBendSize-1))) == 0 && getBend() != 0; // Check highest 1 bits regardless of template type
    static_assert(true, "Should not be possible!");
  }

  VMSMEBENDPSDISK getBendPSDisk() const {
    return data_.range(kVMSMEBendMSB - 1,kVMSMEBendLSB);
  }

  VMSMEFINEPHI getFinePhi() const {
    return data_.range(kVMSMEFinePhiMSB, kVMSMEFinePhiLSB);
  }

  VMSMEFINEZ getFineZ() const {
    return data_.range(kVMSMEFineZMSB,kVMSMEFineZLSB);
  }

  // Setter
  void setIndex(const VMSMEID id) {
    data_.range(kVMSMEIDMSB,kVMSMEIDLSB) = id;
  }

  void setBend(const VMSMEBEND bend) {
    data_.range(kVMSMEBendMSB,kVMSMEBendLSB) = bend;
  }

  void setFinePhi(const VMSMEFINEPHI finephi) {
    data_.range(kVMSMEFinePhiMSB,kVMSMEFinePhiLSB) = finephi;
  }

  void setFineZ(const VMSMEFINEZ finez) {
    data_.range(kVMSMEFineZMSB,kVMSMEFineZLSB) = finez;
  }

#ifdef CMSSW_GIT_HVMSMEH
  std::string getBitStr() const {
    std::string str = decodeToBits(getIndex());
    str += "|"+decodeToBits(getBend());
    str += "|"+decodeToBits(getFineZ());
    return str;
  }
#endif

private:

  VMStubMECMData data_;

};

// Memory definition
template<int VMSMEType, int RZSize, int PhiRegSize, unsigned int NCOPY > using VMStubMEMemoryCM = MemoryTemplateBinnedCM<VMStubMECM<VMSMEType>, 2, 4+RZSize+PhiRegSize, RZSize+PhiRegSize, PhiRegSize, NCOPY>;

#endif
