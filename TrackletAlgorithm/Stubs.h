#ifndef TrackletAlgorithm_Stubs_h
#define TrackletAlgorithm_Stubs_h

#include "Constants.h"
#include "MemoryTemplate.h"

// Stub coming from the DTC  
// does not container header ... i.e. [without valid + layer id]
class Stubs
{
public:
  enum BitWidths {
    // Bit size for DTC memory fields
    kDSStubSize = 39 
  };
};

class Stub : public Stubs
{
public:
enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
    kDSStubLSB = 0 ,
	  kDSStubMSB = kDSStubLSB + Stubs::kDSStubSize - 1  
    };

  typedef ap_uint<kNBits_DTC> StubWord;

  // Constructors
  Stub(const StubWord& newdata):
    data_(newdata)
  {}

  Stub()
  {}

  #ifndef __SYNTHESIS__
  Stub(const char* datastr, int base=16)
  {
    StubWord newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return Stubs::kDSStubSize;}

  StubWord raw() const {return data_; }

private:

  StubWord data_;

};

// Memory definition
using DTCStubs = MemoryTemplate<Stub, 1, kNBits_MemAddr>;

#endif
