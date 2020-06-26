#ifndef TrackletAlgorithm_VMStubMEMemory_h
#define TrackletAlgorithm_VMStubMEMemory_h

#include "Constants.h"
#include "MemoryTemplateBinned.h"

// VMStubMEBase is where we define the bit widths, which depend on the class template parameter
template<int VMSMEType> class VMStubMEBase {};

template<>
class VMStubMEBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for VMStubMEMemory fields
    kVMSMEFineZSize = 3,
    kVMSMEBendSize = 3,
    kVMSMEIndexSize = 7,
    // Bit size for full VMStubMEMemory
    kVMStubMESize = kVMSMEFineZSize + kVMSMEBendSize + kVMSMEIndexSize
  };
};

template<>
class VMStubMEBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for VMStubMEMemory fields
    kVMSMEFineZSize = 3,
    kVMSMEBendSize = 4,
    kVMSMEIndexSize = 7,
    // Bit size for full VMStubMEMemory
    kVMStubMESize = kVMSMEFineZSize + kVMSMEBendSize + kVMSMEIndexSize
  };
};

template<>
class VMStubMEBase<DISK>
{
public:
  enum BitWidths {
    // Bit size for VMStubMEMemory fields
    kVMSMEFineZSize = 3,
    kVMSMEBendSize = 4,
    kVMSMEIndexSize = 7,
    // Bit size for full VMStubMEMemory
    kVMStubMESize = kVMSMEFineZSize + kVMSMEBendSize + kVMSMEIndexSize
  };
};


// Data object definition
template<int VMSMEType>
class VMStubME : public VMStubMEBase<VMSMEType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMEMemory word for different fields
    kVMSMEFineZLSB = 0,
    kVMSMEFineZMSB = kVMSMEFineZLSB + VMStubMEBase<VMSMEType>::kVMSMEFineZSize - 1,
    kVMSMEBendLSB = kVMSMEFineZMSB + 1,
    kVMSMEBendMSB = kVMSMEBendLSB + VMStubMEBase<VMSMEType>::kVMSMEBendSize - 1,
    kVMSMEIndexLSB = kVMSMEBendMSB + 1,
    kVMSMEIndexMSB = kVMSMEIndexLSB + VMStubMEBase<VMSMEType>::kVMSMEIndexSize - 1
  };

  typedef ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize> VMSMEID;
  typedef ap_uint<VMStubMEBase<VMSMEType>::kVMSMEBendSize> VMSMEBEND;
  typedef ap_uint<VMStubMEBase<VMSMEType>::kVMSMEFineZSize> VMSMEFINEZ;

  typedef ap_uint<VMStubMEBase<VMSMEType>::kVMStubMESize> VMStubMEData;

  // Constructors
  VMStubME(const VMStubMEData& newdata):
    data_(newdata)
  {}

  VMStubME(const VMSMEID id, const VMSMEBEND bend, const VMSMEFINEZ finez):
    data_( ((id, bend), finez) )
  {}

  VMStubME():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  VMStubME(const char* datastr, int base=16)
  {
    VMStubMEData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return VMStubMEBase<VMSMEType>::kVMStubMESize;}

  VMStubMEData raw() const {return data_;}

  VMSMEID getIndex() const {
    return data_.range(kVMSMEIndexMSB,kVMSMEIndexLSB);
  }

  VMSMEBEND getBend() const {
    return data_.range(kVMSMEBendMSB,kVMSMEBendLSB);
  }

  VMSMEFINEZ getFineZ() const {
    return data_.range(kVMSMEFineZMSB,kVMSMEFineZLSB);
  }

  // Setter
  void setIndex(const VMSMEID index) {
    data_.range(kVMSMEIndexMSB,kVMSMEIndexLSB) = index;
  }

  void setBend(const VMSMEBEND bend) {
    data_.range(kVMSMEBendMSB,kVMSMEBendLSB) = bend;
  }

  void setFineZ(const VMSMEFINEZ finez) {
    data_.range(kVMSMEFineZMSB,kVMSMEFineZLSB) = finez;
  }

private:

  VMStubMEData data_;

};

// Memory definition
template<int VMSMEType, int NBIT_BIN> using VMStubMEMemory = MemoryTemplateBinned<VMStubME<VMSMEType>, 2, kNBits_MemAddr,NBIT_BIN>;

#endif
