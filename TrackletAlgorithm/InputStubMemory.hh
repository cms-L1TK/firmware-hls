#ifndef INPUTSTUBMEMORY_HH
#define INPUTSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for InputStubMemory fields
constexpr unsigned int kISBendSize = 3;
constexpr unsigned int kISPhiSize = 14;
constexpr unsigned int kISZSize = 12;
constexpr unsigned int kISRSize = 7;
// Bit size for full InputStubMemory
constexpr unsigned int kInputStubSize = kISBendSize + kISPhiSize + kISZSize + kISRSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
constexpr unsigned int kISBendLSB = 0;
constexpr unsigned int kISBendMSB = kISBendLSB + kISBendSize - 1;
constexpr unsigned int kISPhiLSB = kISBendMSB + 1;
constexpr unsigned int kISPhiMSB = kISPhiLSB + kISPhiSize - 1;
constexpr unsigned int kISZLSB = kISPhiMSB + 1;
constexpr unsigned int kISZMSB = kISZLSB + kISZSize - 1;
constexpr unsigned int kISRLSB = kISZMSB + 1;
constexpr unsigned int kISRMSB = kISRLSB + kISRSize - 1;

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

  // Getter
  InputStubData raw() const {return data_; }

  ISR GetR() const {
    return data_.range(kISRMSB,kISRLSB);
  }

  ISZ GetZ() const {
    return data_.range(kISZMSB,kISZLSB);
  }

  ISPHI GetPhi() const {
    return data_.range(kISPhiMSB,kISPhiLSB);
  }

  ISBEND GetBend() const {
    return data_.range(kISBendMSB,kISBendLSB);
  }

  // Setter
  void SetR(const ISR r) {
    data_.range(kISRMSB,kISRLSB) = r;
  }

  void SetZ(const ISZ z) {
    data_.range(kISZMSB,kISZLSB) = z;
  }

  void SetPhi(const ISPHI phi) {
    data_.range(kISPhiMSB,kISPhiLSB) = phi;
  }

  void SetBend(const ISBEND bend) {
    data_.range(kISBendMSB,kISBendLSB) = bend;
  }

private:

  InputStubData data_;

};

// Memory definition
typedef MemoryTemplate<InputStub, 1, kNBits_MemAddr> InputStubMemory;


#endif
