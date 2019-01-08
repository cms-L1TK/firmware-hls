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
    kFMTCIndexSize = 13,
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
    kFMTCIndexLSB = kFMStubIndexMSB + 1,
    kFMTCIndexMSB = kFMTCIndexLSB + kFMTCIndexSize - 1
  };

  typedef ap_uint<kFMTCIndexSize> FMTCID;
  typedef ap_uint<kFMStubIndexSize> FMSTUBINDEX;
  typedef ap_int<kFMPhiResSize> FMPHIRES;
  typedef ap_int<kFMZResSize> FMZRES;

  typedef ap_uint<kFullMatchSize> FullMatchData;

  // Constructors
  FullMatch(const FullMatchData& newdata):
    data_(newdata)
  {}

  FullMatch(const FMTCID tcid, const FMSTUBINDEX stub, const FMPHIRES phires, const FMZRES zres):
    data_( (((tcid,stub),phires),zres) )
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

  FMTCID getTrackletIndex() const {
    return data_.range(kFMTCIndexMSB,kFMTCIndexLSB);
  }

  FMSTUBINDEX getStubIndex() const {
    return data_.range(kFMStubIndexMSB,kFMStubIndexLSB);
  }

  FMPHIRES getPhiRes() const {
    return data_.range(kFMPhiResMSB,kFMPhiResLSB);
  }

  FMZRES getZRes() const {
    return data_.range(kFMZResMSB,kFMZResLSB);
  }

  // Setter
  void setTrackletIndex(const FMTCID tcid) {
    data_.range(kFMTCIndexMSB,kFMTCIndexLSB) = tcid;
  }

  void setStubIndex(const FMSTUBINDEX stid) {
    data_.range(kFMStubIndexMSB,kFMStubIndexLSB) = stid;
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
