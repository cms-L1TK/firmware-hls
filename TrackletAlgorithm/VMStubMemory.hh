#ifndef VMSTUBMEMORY_HH
#define VMSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"

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

  // copy constructor
  VMStub(const VMStub& rhs):
    data_(rhs.raw())
  {}

  // Getter
  VMStubData raw() const {return data_;}

  VMSID GetIndex() const {
    return data_.range(kVMSIndexLSB+kVMSIndexSize-1,kVMSIndexLSB);
  }

  VMSBEND GetBend() const {
    return data_.range(kVMSBendLSB+kVMSBendSize-1,kVMSBendLSB);
  }

  VMSFINEZ GetFineZ() const {
    return data_.range(kVMSFineZLSB+kVMSFineZSize-1,kVMSFineZLSB);
  }

  // Setter
  void SetIndex(const VMSID index) {
    data_.range(kVMSIndexLSB+kVMSIndexSize-1,kVMSIndexLSB) = index;
  }

  void SetBend(const VMSBEND bend) {
    data_.range(kVMSBendLSB+kVMSBendSize-1,kVMSBendLSB) = bend;
  }

  void SetFineZ(const VMSFINEZ finez) {
    data_.range(kVMSFineZLSB+kVMSFineZSize-1,kVMSFineZLSB) = finez;
  }

private:

  VMStubData data_;

};

// Memory definition
typedef MemoryTemplateBinned<VMStub, 2, kNBits_MemAddr,3> VMStubMemory;


#endif
