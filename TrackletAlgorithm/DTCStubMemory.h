#ifndef TrackletAlgorithm_DTCStubMemory_h
#define TrackletAlgorithm_DTCStubMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// Memory containing stubs written by the InputRouter. 
// (Unlike the stubs read by the InputRouter, these do not contain the
// "valid + layer id" bits).
// N.B. Both class DTCStubMemory & InputStubMemory represent the same BRAM
// between InputRouter & VMRouter, but DTCStubMemory does not describe the bit
// fields, so can hold stubs in any of disk/barrel/PS/2S, so is used for the
// InputRouter output.

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

  DTCStub()
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
using DTCStubMemory = MemoryTemplate<DTCStub, 1, kNBits_MemAddr>;

#endif
