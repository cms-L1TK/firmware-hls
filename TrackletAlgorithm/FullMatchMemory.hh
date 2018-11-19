#ifndef FULLMATCHMEMORY_HH
#define FULLMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class FullMatch
{
public:

  typedef ap_uint<kFMTCIndexSize> FMTCID;
  typedef ap_unit<kFMStubIndexSize> FMSTUBINDEX;
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

  FullMatch(const char* datastr, int base = 16)
  {
    FullMatchData newdata(datastr, base);
    data_ = newdata;
  }

  // copy constructor
  FullMatch(const FullMatch& rhs):
    data_(rhs.raw())
  {}

  // Getter
  FullMatchData raw() const {return data_;}

  FMTCID GetTrackletIndex() const {
    return data_.range(kFMTCIndexLSB+kFMTCIndexSize-1,kFMTCIndexLSB);
  }

  FMSTUBINDEX GetStubIndex() const {
    return data_.range(kFMStubIndexLSB+kFMStubIndexSize-1,kFMStubIndexLSB);
  }

  FMPHIRES GetPhiRes() const {
    return data_.range(kFMPhiResLSB+kFMPhiResSize-1,kFMPhiResLSB);
  }

  FMZRES GetZRes() const {
    return data.range(kFMZResLSB+kFMZResSize-1,kFMZResLSB);
  }

  // Setter
  void SetTrackletIndex(const FMTCID tcid) {
    data_.range(kFMTCIndexLSB+kFMTCIndexSize-1,kFMTCIndexLSB) = tcid;
  }

  void SetStubIndex(const FMSTUBINDEX stid) {
    data_.range(kFMStubIndexLSB+kFMStubIndexSize-1,kFMStubIndexLSB) = stid;
  }

  void SetPhiRes(const FMPHIRES phires) {
    data_.range(kFMPhiResLSB+kFMPhiResSize-1,kFMPhiResLSB) = phires;
  }

  void SetZRes(const FMZRES zres) {
    data_.range(kFMZResLSB+kFMZResSize-1,kFMZResLSB) = zres;
  }

private:

  FullMatchData data_;

};

// Memory definition
typedef MemoryTemplate<FullMatch, 1, kNBits_MemAddr> FullMatchMemory;

#endif
