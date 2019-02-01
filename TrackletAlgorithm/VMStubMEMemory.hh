#ifndef VMSTUBMEMEMORY_HH
#define VMSTUBMEMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"

// Data object definition
class VMStubME
{
public:

  enum BitWidths {
    // Bit size for VMStubMEMemory fields
    kVMSMEFineZSize = 4,
    kVMSMEBendSize = 3,
    kVMSMEIndexSize = 7,
    // Bit size for full VMStubMEMemory
    kVMStubMESize = kVMSMEFineZSize + kVMSMEBendSize + kVMSMEIndexSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMEMemory word for different fields
    kVMSMEFineZLSB = 0,
    kVMSMEFineZMSB = kVMSMEFineZLSB + kVMSMEFineZSize - 1,
    kVMSMEBendLSB = kVMSMEFineZMSB + 1,
    kVMSMEBendMSB = kVMSMEBendLSB + kVMSMEBendSize - 1,
    kVMSMEIndexLSB = kVMSMEBendMSB + 1,
    kVMSMEIndexMSB = kVMSMEIndexLSB + kVMSMEIndexSize - 1
  };

  typedef ap_uint<kVMSMEIndexSize> VMSMEID;
  typedef ap_uint<kVMSMEBendSize> VMSMEBEND;
  typedef ap_uint<kVMSMEFineZSize> VMSMEFINEZ;

  typedef ap_uint<kVMStubMESize> VMStubMEData;

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
typedef MemoryTemplateBinned<VMStubME, 2, kNBits_MemAddr,3> VMStubMEMemory;


#endif
