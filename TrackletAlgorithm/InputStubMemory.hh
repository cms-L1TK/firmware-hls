#ifndef INPUTSTUBMEMORY_HH
#define INPUTSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class InputStub
{
public:

  typedef ap_uint<kISRSize> ISR;
  typedef ap_int<kISZSize> ISZ;
  typedef ap_uint<kISPhiSize> ISPHI;
  typedef ap_uint<kISBendSize> ISBEND;
  
  typedef ap_uint<kInputStubSize> InputStubData;

  // Constructors
  InputStub(const InputStubData& newdata):
    data_(newdata)
  {}

  InputStub(const ISR r, const ISZ z, const ISPHI phi, const ISBEND bend):
    data_( (((r,z),phi),bend) )
  {}

  InputStub():
    data_(0)
  {}

  InputStub(const char* datastr, int base=16)
  {
    InputStubData newdata(datastr, base);
    data_ = newdata;
  }

  // copy constructor
  InputStub(const InputStub& rhs):
    data_(rhs.raw())
  {}

  // Getter
  InputStubData raw() const {return data_; }

  ISR GetR() const {
    return data_.range(kISRLSB+kISRSize-1,kISRLSB);
  }

  ISZ GetZ() const {
    return data_.range(kISZLSB+kISZSize-1,kISZLSB);
  }

  ISPHI GetPhi() const {
    return data_.range(kISPhiLSB+kISPhiSize-1,kISPhiLSB);
  }

  ISBEND GetBend() const {
    return data_.range(kISBendLSB+kISBendSize-1,kISBendLSB);
  }

  // Setter
  void SetR(const ISR r) {
    data_.range(kISRLSB+kISRSize-1,kISRLSB) = r;
  }

  void SetZ(const ISZ z) {
    data_.range(kISZLSB+kISZSize-1,kISZLSB) = z;
  }

  void SetPhi(const ISPHI phi) {
    data_.range(kISPhiLSB+kISPhiSize-1,kISPhiLSB) = phi;
  }

  void SetBend(const ISBEND bend) {
    data_.range(kISBendLSB+kISBendSize-1,kISBendLSB) = bend;
  }

private:

  InputStubData data_;

};

// Memory definition
typedef MemoryTemplate<InputStub, 1, kNBits_MemAddr> InputStubMemory;


#endif
