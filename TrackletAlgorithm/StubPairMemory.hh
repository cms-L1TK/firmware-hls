#ifndef STUBPAIRMEMORY_HH
#define STUBPAIRMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for full StubPairMemory
constexpr unsigned int kStubPairSize = 2*kNBits_MemAddr;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the StubPairMemory word for different fields
constexpr unsigned int kSPOuterIndexLSB = 0;
constexpr unsigned int kSPOuterIndexMSB = kSPOuterIndexLSB + kNBits_MemAddr - 1;
constexpr unsigned int kSPInnerIndexLSB = kSPOuterIndexMSB + 1;
constexpr unsigned int kSPInnerIndexMSB = kSPInnerIndexLSB + kNBits_MemAddr - 1;

// Data object definition
class StubPair
{
public:
  
  typedef ap_uint<kNBits_MemAddr> SPInnerIndex;
  typedef ap_uint<kNBits_MemAddr> SPOuterIndex;

  typedef ap_uint<kStubPairSize> StubPairData;

  // Constructors
  StubPair(const SPInnerIndex innerindex, const SPOuterIndex outerindex):
    data_( (innerindex,outerindex) )
  {}
  
  StubPair():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  StubPair(const char* datastr, int base=16)
  {
    StubPairData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  StubPairData raw() const {return data_;}
  
  SPInnerIndex getInnerIndex() const {
    return data_.range(kSPInnerIndexMSB,kSPInnerIndexLSB);
  }

  SPOuterIndex getOuterIndex() const {
    return data_.range(kSPOuterIndexMSB,kSPOuterIndexLSB);
  }

  // Setter
  void setInnerIndex(const SPInnerIndex id) {
    data_.range(kSPInnerIndexMSB,kSPInnerIndexLSB) = id;
  }

  void setOuterIndex(const SPOuterIndex id) {
    data_.range(kSPOuterIndexMSB,kSPOuterIndexLSB) = id;
  }

private:
  
  StubPairData data_;
  
};

// Memory definition
typedef MemoryTemplate<StubPair, 1, kNBits_MemAddr> StubPairMemory;

#endif
