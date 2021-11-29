#ifndef TrackletAlgorithm_InputStubMemory_h
#define TrackletAlgorithm_InputStubMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// InputStubBase is where we define the bit widths, which depend on the class template parameter
template<int ISType> class InputStubBase {};

template<>
class InputStubBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 3,
    kISAlphaSize = 0,
    kISPhiSize = 14,
    kISZSize = 12,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 4,
    kISAlphaSize = 0,
    kISPhiSize = 17,
    kISZSize = 8,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<DISKPS>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 3,
    kISAlphaSize = 0,
    kISPhiSize = 14,
    kISZSize = 7,
    kISRSize = 12,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<DISK2S>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 4,
    kISAlphaSize = 4,
    kISPhiSize = 14,
    kISZSize = 7,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};


// Data object definition
template<int ISType>
class InputStub : public InputStubBase<ISType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
    kISBendLSB = 0,
    kISBendMSB = kISBendLSB + InputStubBase<ISType>::kISBendSize - 1,
    kISAlphaLSB = kISBendMSB + 1,
    kISAlphaMSB = kISAlphaLSB + InputStubBase<ISType>::kISAlphaSize - 1,
    kISPhiLSB = kISAlphaMSB + 1,
    kISPhiMSB = kISPhiLSB + InputStubBase<ISType>::kISPhiSize - 1,
    kISZLSB = kISPhiMSB + 1,
    kISZMSB = kISZLSB + InputStubBase<ISType>::kISZSize - 1,
    kISRLSB = kISZMSB + 1,
    kISRMSB = kISRLSB + InputStubBase<ISType>::kISRSize - 1
  };

  typedef ap_int<InputStubBase<ISType>::kISRSize> ISR;
  typedef ap_int<InputStubBase<ISType>::kISZSize> ISZ;
  typedef ap_uint<InputStubBase<ISType>::kISPhiSize> ISPHI;
  typedef ap_uint<InputStubBase<ISType>::kISAlphaSize> ISALPHA;
  typedef ap_uint<InputStubBase<ISType>::kISBendSize> ISBEND;
  
  typedef ap_uint<InputStubBase<ISType>::kInputStubSize> InputStubData;

  // Constructors
  InputStub(const InputStubData& newdata):
    data_(newdata)
  {}

  InputStub(const ISR r, const ISZ z, const ISPHI phi, const ISBEND bend):
    data_( (((r,z),phi),bend) )
  {
    static_assert(ISType != DISKPS, "Constructor should not be used for Disk 2S stubs");
  }

  // This constructor is only used for stubs in DISK2S
  InputStub(const ISR r, const ISZ z, const ISPHI phi, const ISALPHA alpha, const ISBEND bend):
    data_( ((((r,z),phi),alpha),bend) ) 
  {
    static_assert(ISType == DISKPS, "Constructor should only be used for Disk 2S stubs");
  }

  InputStub()
  {}

  #ifndef __SYNTHESIS__
  InputStub(const char* datastr, int base=16)
  {
    InputStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return InputStubBase<ISType>::kInputStubSize;}

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

  // This getter is only used for stubs in DISK2S
  ISALPHA getAlpha() const {
    static_assert(ISType == DISKPS, "Getter should only be used for Disk 2S stubs");
    return data_.range(kISAlphaMSB,kISAlphaLSB);
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

  // This setter is only used for stubs in DISK2S
  void setAlpha(const ISALPHA alpha) {
    static_assert(ISType == DISKPS, "Setter should only be used for Disk 2S stubs");
    data_.range(kISAlphaMSB,kISAlphaLSB) = alpha;
  }

  void setBend(const ISBEND bend) {
    data_.range(kISBendMSB,kISBendLSB) = bend;
  }

private:

  InputStubData data_;

};

// Memory definition
template<int ISType> using InputStubMemory = MemoryTemplate<InputStub<ISType>, 1, kNBits_MemAddr>;

#endif
