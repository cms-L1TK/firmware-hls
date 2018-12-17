#ifndef INPUTSTUBMEMORY_HH
#define INPUTSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class InputStub
{
public:

  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 3,
    kISPhiSize = 14,
    kISZSize = 12,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISPhiSize + kISZSize + kISRSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
    kISBendLSB = 0,
    kISBendMSB = kISBendLSB + kISBendSize - 1,
    kISPhiLSB = kISBendMSB + 1,
    kISPhiMSB = kISPhiLSB + kISPhiSize - 1,
    kISZLSB = kISPhiMSB + 1,
    kISZMSB = kISZLSB + kISZSize - 1,
    kISRLSB = kISZMSB + 1,
    kISRMSB = kISRLSB + kISRSize - 1
  };

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

  #ifndef __SYNTHESIS__
  InputStub(const char* datastr, int base=16)
  {
    InputStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  InputStubData raw() const {return data_; }

  ISR getR() const {
    return data_.range(kISRMSB,kISRLSB);
  }

  ISZ getZ() const {
    return data_.range(kISZMSB,kISZLSB);
  }

  ISPHI getPhi() const {
    return data_.range(kISPhiMSB,kISPhiLSB);
  }

  ISBEND getBend() const {
    return data_.range(kISBendMSB,kISBendLSB);
  }

  // Setter
  void setR(const ISR r) {
    data_.range(kISRMSB,kISRLSB) = r;
  }

  void setZ(const ISZ z) {
    data_.range(kISZMSB,kISZLSB) = z;
  }

  void setPhi(const ISPHI phi) {
    data_.range(kISPhiMSB,kISPhiLSB) = phi;
  }

  void setBend(const ISBEND bend) {
    data_.range(kISBendMSB,kISBendLSB) = bend;
  }

private:

  InputStubData data_;

};

// Memory definition
typedef MemoryTemplate<InputStub, 1, kNBits_MemAddr> InputStubMemory;


#endif
