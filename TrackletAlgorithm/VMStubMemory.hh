#ifndef VMSTUBMEMORY_HH
#define VMSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"

// Bit size for VMStubMemory fields
constexpr unsigned int kVMSFineZSize = 4;
constexpr unsigned int kVMSBendSize = 3;
constexpr unsigned int kVMSIndexSize = 7;
// Bit size for full VMStubMemory
constexpr unsigned int kVMStubSize = kVMSFineZSize + kVMSBendSize + kVMSIndexSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubMemory word for different fields
constexpr unsigned int kVMSFineZLSB = 0;
constexpr unsigned int kVMSFineZMSB = kVMSFineZLSB + kVMSFineZSize - 1;
constexpr unsigned int kVMSBendLSB = kVMSFineZMSB + 1;
constexpr unsigned int kVMSBendMSB = kVMSBendLSB + kVMSBendSize - 1;
constexpr unsigned int kVMSIndexLSB = kVMSBendMSB + 1;
constexpr unsigned int kVMSIndexMSB = kVMSIndexLSB + kVMSIndexSize - 1;

// Data object definition
class VMStub 
{
public:

  typedef ap_uint<kVMSIndexSize> VMSID;
  typedef ap_uint<kVMSBendSize> VMSBEND;
  typedef ap_uint<kVMSFineZSize> VMSFINEZ;

  typedef ap_uint<kVMStubSize> VMStubData;

  // Constructors
  VMStub(const VMStubData& newdata):
    data_(newdata)
  {}

  VMStub(const VMSID id, const VMSBEND bend, const VMSFINEZ finez):
    data_( ((id, bend), finez) )
  {}
  
  VMStub():
    data_(0)
  {}

  VMStub(const char* datastr, int base=16)
  {
    VMStubData newdata(datastr, base);
    data_ = newdata;
  }

  // Getter
  VMStubData raw() const {return data_;}

  VMSID GetIndex() const {
    return data_.range(kVMSIndexMSB,kVMSIndexLSB);
  }

  VMSBEND GetBend() const {
    return data_.range(kVMSBendMSB,kVMSBendLSB);
  }

  VMSFINEZ GetFineZ() const {
    return data_.range(kVMSFineZMSB,kVMSFineZLSB);
  }

  // Setter
  void SetIndex(const VMSID index) {
    data_.range(kVMSIndexMSB,kVMSIndexLSB) = index;
  }

  void SetBend(const VMSBEND bend) {
    data_.range(kVMSBendMSB,kVMSBendLSB) = bend;
  }

  void SetFineZ(const VMSFINEZ finez) {
    data_.range(kVMSFineZMSB,kVMSFineZLSB) = finez;
  }

private:

  VMStubData data_;

};

// Memory definition
typedef MemoryTemplateBinned<VMStub, 2, kNBits_MemAddr,3> VMStubMemory;


#endif
