#ifndef FULLMATCHMEMORY_HH
#define FULLMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class FullMatch
{
public:

  enum BitWidths {
    // Bit size for FullMatchMemory fields
    kFMZResSize = 9,
    kFMPhiResSize = 12,
    kFMStubIndexSize = 10,
    kFMStubPhiIDSize = 3,   // subdivision of StubIndex
    kFMStubIDSize = 7,      // subdivision of StubIndex
    kFMTCIndexSize = 14,
    // Bit size for full FullMatchMemory
    kFullMatchSize = kFMTCIndexSize + kFMStubIndexSize + kFMPhiResSize + kFMZResSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the FullMatchMemory word for different fields
    kFMZResLSB = 0,
    kFMZResMSB = kFMZResLSB + kFMZResSize - 1,
    kFMPhiResLSB = kFMZResMSB + 1,
    kFMPhiResMSB = kFMPhiResLSB + kFMPhiResSize - 1,
    kFMStubIndexLSB = kFMPhiResMSB + 1,
    kFMStubIndexMSB = kFMStubIndexLSB + kFMStubIndexSize - 1,
    kFMStubPhiIDLSB = kFMPhiResMSB + 1,
    kFMStubPHIIDMSB = kFMStubPhiIDLSB + kFMStubPhiIDSize - 1,
    kFMStubIDLSB = kFMStubPhiIDMSB + 1,
    kFMStubIDMSB = kFMStubIDLSB + kFMStubIDSize - 1,
    kFMTCIndexLSB = kFMStubIndexMSB + 1,
    kFMTCIndexMSB = kFMTCIndexLSB + kFMTCIndexSize - 1
  };

  typedef ap_uint<kFMTCIndexSize> FMTCID;
  typedef ap_uint<kFMStubIndexSize> FMSTUBINDEX;
  typedef ap_uint<kFMStubIDSize> FMSTUBID;        // subdivision of StubIndex 
  typedef ap_uint<kFMStubPhiIDSize> FMSTUBPHIID;  // subdivision of StubIndex
  typedef ap_int<kFMPhiResSize> FMPHIRES;
  typedef ap_int<kFMZResSize> FMZRES;

  typedef ap_uint<kFullMatchSize> FullMatchData;

  // Constructors
  FullMatch(const FullMatchData& newdata):
    data_(newdata)
  {}

  FullMatch(const FMTCINDEX tcid, const FMSTUBINDEX stub, const FMPHIRES phires, const FMZRES zres):
    data_( (((tcid,stub),phires),zres) )
  {}

  FullMatch(const FMTCINDEX tcid, const FMSTUBPHIID stubphiid, const FMSTUBID stubid, const FMPHIRES phires, const FMZRES zres):
	data_( ((((tcid,stubphiid),stubid),phires),zres) )
  {}

  FullMatch():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  FullMatch(const char* datastr, int base = 16)
  {
    FullMatchData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  FullMatchData raw() const {return data_;}

  FMTCINDEX getTCIndex() const {
    return data_.range(kFMTCIndexMSB,kFMTCIndexLSB);
  }

  FMSTUBINDEX getStubIndex() const {
    return data_.range(kFMStubIndexMSB,kFMStubIndexLSB);
  }

  FMSTUBID getStubID() const {
    return data_.range(kFMStubIDMSB,kFMStubIDLSB);
  }

  FMSTUBPHIID getStubPhiID() const {
    return data_.range(kFMStubPhiIDMSB,kFMStubPhiIDLSB);
  }

  FMPHIRES getPhiRes() const {
    return data_.range(kFMPhiResMSB,kFMPhiResLSB);
  }

  FMZRES getZRes() const {
    return data_.range(kFMZResMSB,kFMZResLSB);
  }

  // Setter
  void setTCIndex(const FMTCINDEX tcid) {
    data_.range(kFMTCIndexMSB,kFMTCIndexLSB) = tcid;
  }

  void setStubIndex(const FMSTUBINDEX stid) {
    data_.range(kFMStubIndexMSB,kFMStubIndexLSB) = stid;
  }

  void setStubPhiID(const FMSTUBPHIID stphiid) {
    data_.range(kFMStubPhiIDMSB,kFMStubPhiIDLSB) = stphiid;
  }

  void setStubID(const FMSTUBID stid) {
    data_.range(kFMStubIDMSB,kFMStubIDLSB) = stid;
  }

  void setPhiRes(const FMPHIRES phires) {
    data_.range(kFMPhiResMSB,kFMPhiResLSB) = phires;
  }

  void setZRes(const FMZRES zres) {
    data_.range(kFMZResMSB,kFMZResLSB) = zres;
  }

private:

  FullMatchData data_;

};

// Memory definition
typedef MemoryTemplate<FullMatch, 1, kNBits_MemAddr> FullMatchMemory;

#endif
