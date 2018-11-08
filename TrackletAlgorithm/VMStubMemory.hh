#ifndef VMSTUBMEMORY_HH
#define VMSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"



//template<unsigned int bx=2, unsigned int memdepth=kMemDepth>
class VMStub {
public:

  typedef ap_uint<7> VMSID;
  typedef ap_uint<3> VMSBEND;
  typedef ap_uint<4> VMSFINEZ;

  typedef ap_uint<7+3+4> VMStubData;

  // Constructors
  VMStub(VMStubData newdata):
    data_(newdata)
  {}

  VMStub(VMSID id, VMSBEND bend, VMSFINEZ finez):
    data_( ((id, bend), id) )
  {}
  
  VMStub():
    data_(0)
  {}

  // copy constructor
  VMStub(const VMStub& rhs):
    data_(rhs.raw())
  {}

  VMStub(const char* datastr, int base=16)
  {
    VMStubData newdata(datastr, base);
    data_ = newdata;
  }

  // Getter
  VMStubData raw() const {return data_;}

  VMSID GetIndex() const {return data_.range(13,7);}
  VMSBEND GetBend() const {return data_.range(6,4);}
  VMSFINEZ GetFineZ() const {return data_.range(3,0);}

private:

  VMStubData data_;

};

// Memory definition
typedef MemoryTemplateBinned<VMStub, 2, kNBits_MemAddr,3> VMStubMemory;



#endif
