#ifndef VMSTUBMEMEMORY_HH
#define VMSTUBMEMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"

// Bit size for VMStubMEMemory fields
constexpr unsigned int kVMSMEFineZSize = 4;
constexpr unsigned int kVMSMEBendSize = 3;
constexpr unsigned int kVMSMEIndexSize = 7;
// Bit size for full VMStubMEMemory
constexpr unsigned int kVMStubMESize = kVMSMEFineZSize + kVMSMEBendSize + kVMSMEIndexSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMEMemory word for different fields
constexpr unsigned int kVMSMEFineZLSB = 0;
constexpr unsigned int kVMSMEFineZMSB = kVMSMEFineZLSB + kVMSMEFineZSize - 1;
constexpr unsigned int kVMSMEBendLSB = kVMSMEFineZMSB + 1;
constexpr unsigned int kVMSMEBendMSB = kVMSMEBendLSB + kVMSMEBendSize - 1;
constexpr unsigned int kVMSMEIndexLSB = kVMSMEBendMSB + 1;
constexpr unsigned int kVMSMEIndexMSB = kVMSMEIndexLSB + kVMSMEIndexSize - 1;

// Data object definition
class VMStubME
{
public:

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
