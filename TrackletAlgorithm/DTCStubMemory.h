#ifndef TrackletAlgorithm_DTCStubMemory_h
#define TrackletAlgorithm_DTCStubMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// Stub coming from the DTC  
// does not container header ... i.e. [without valid + layer id]
class DTCStubBase
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kDSStubSize = 36 
  };
};

class DTCStub : public DTCStubBase
{
public:
enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
    kDSStubLSB = 0 ,
	kDSStubMSB = kDSStubLSB + DTCStubBase::kDSStubSize - 1  
    };

  typedef ap_uint<kBRAMwidth> DTCStubWord;

  // Constructors
  DTCStub(const DTCStubWord& newdata):
    data_(newdata)
  {}

  DTCStub():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  DTCStub(const char* datastr, int base=16)
  {
    DTCStubWord newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return DTCStubBase::kDSStubSize;}

  DTCStubWord raw() const {return data_; }

private:

  DTCStubWord data_;

};

// Memory definition
using DTCStubMemory = MemoryTemplate<DTCStub, 3, kNBits_MemAddr>;

#endif
