#ifndef STUBPAIRMEMORY_HH
#define STUBPAIRMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class StubPair
{
public:
  
  typedef ap_uint<kNBits_MemAddr> SPInnerIndex;
  typedef ap_uint<kNBits_MemAddr> SPOuterIndex;

  typedef ap_uint<kStubPairSize> StubPairData;

  // Constructors
  StubPair(const StubPairData& newdata):
    data_(newdata)
  {}
  
  StubPair(const SPInnerIndex innerindex, const SPOuterIndex outerindex):
    data_( (innerindex,outerindex) )
  {}
  
  StubPair():
    data_(0)
  {}

  StubPair(const char* datastr, int base=16)
  {
    StubPairData newdata(datastr, base);
    data_ = newdata;
  }

  // copy constructor
  StubPair(const StubPair& rhs):
    data_(rhs.raw())
  {}
  
  // Getter
  StubPairData raw() const {return data_;}
  
  SPInnerIndex GetInnerIndex() const {
    return data_.range(kSPInnerIndexLSB+kNBits_MemAddr-1,kSPInnerIndexLSB);
  }

  SPOuterIndex GetOuterIndex() const {
    return data_.range(kSPOuterIndexLSB+kNBits_MemAddr-1,kSPOuterIndexLSB);
  }

  // Setter
  void SetInnerIndex(const SPInnerIndex id) {
    data_.range(kSPInnerIndexLSB+kNBits_MemAddr-1,kSPInnerIndexLSB) = id;
  }

  void SetOuterIndex(const SPOuterIndex id) {
    data_.range(kSPOuterIndexLSB+kNBits_MemAddr-1,kSPOuterIndexLSB) = id;
  }

private:
  
  StubPairData data_;
  
};

// Memory definition
typedef MemoryTemplate<StubPair, 1, kNBits_MemAddr> StubPairMemory;

#endif
