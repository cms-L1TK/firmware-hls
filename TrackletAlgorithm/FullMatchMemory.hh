#ifndef FULLMATCHMEMORY_HH
#define FULLMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for FullMatchMemory fields
constexpr unsigned int kFMZResSize = 9;
constexpr unsigned int kFMPhiResSize = 12;
constexpr unsigned int kFMStubIndexSize = 10;
constexpr unsigned int kFMStubPhiIDSize = 3;   // sub division of StubIndex
constexpr unsigned int kFMStubIDSize = 7;      // sub division of StubIndex
constexpr unsigned int kFMTCIndexSize = 14;
constexpr unsigned int kFMTCIDSize = 7;        // sub division of TCIndex
constexpr unsigned int kFMTrackletNumSize = 7; // sub division of TCIndex
// Bit size for full FullMatchMemory
constexpr unsigned int kFullMatchSize = kFMTCIndexSize + kFMStubIndexSize + kFMPhiResSize + kFMZResSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the FullMatchMemory word for different fields
constexpr unsigned int kFMZResLSB = 0;
constexpr unsigned int kFMZResMSB = kFMZResLSB + kFMZResSize - 1;
constexpr unsigned int kFMPhiResLSB = kFMZResMSB + 1;
constexpr unsigned int kFMPhiResMSB = kFMPhiResLSB + kFMPhiResSize - 1;
constexpr unsigned int kFMStubIndexLSB = kFMPhiResMSB + 1;
constexpr unsigned int kFMStubIndexMSB = kFMStubIndexLSB + kFMStubIndexSize - 1;
constexpr unsigned int kFMTCIndexLSB = kFMStubIndexMSB + 1;
constexpr unsigned int kFMTCIndexMSB = kFMTCIndexLSB + kFMTCIndexSize - 1;
constexpr unsigned int kFMTrackletNumLSB = kFMStubIndexMSB + 1;
constexpr unsigned int kFMTrackletNumMSB = kFMTrackletNumLSB + kFMTrackletNumSize - 1;
constexpr unsigned int kFMTCIDLSB = kFMTrackletNumMSB + 1;
constexpr unsigned int kFMTCIDMSB = kFMTCIDLSB + kFMTCIDSize - 1;
constexpr unsigned int kFMStubIDLSB = kFMPhiResMSB + 1;
constexpr unsigned int kFMStubIDMSB = kFMStubIDLSB + kFMStubIDSize - 1;
constexpr unsigned int kFMStubPhiIDLSB = kFMStubIDMSB + 1;
constexpr unsigned int kFMStubPhiIDMSB = kFMStubPhiIDLSB + kFMStubPhiIDSize - 1;

// Data object definition
class FullMatch
{
public:

  typedef ap_uint<kFMTCIndexSize> FMTCINDEX;
  typedef ap_uint<kFMTCIDSize> FMTCID;
  typedef ap_uint<kFMTrackletNumSize> FMTCNUM;
  typedef ap_uint<kFMStubIndexSize> FMSTUBINDEX;
  typedef ap_uint<kFMStubIDSize> FMSTUBID;
  typedef ap_uint<kFMStubPhiIDSize> FMSTUBPHIID;
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

  FullMatch(const FMTCNUM num, const FMTCID tcid, const FMSTUBINDEX stub, const FMPHIRES phires, const FMZRES zres):
	data_( ((((num,tcid),stub),phires),zres) )
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

  FMTCID getTCID() const {
	return data_.range(kFMTCIDMSB,kFMTCIDLSB);
  }

  FMTCNUM getTrackletNumber() const {
	return data_.range(kFMTrackletNumMSB,kFMTrackletNumLSB);
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
  void setTCIndex(const FMTCINDEX tcid) {
    data_.range(kFMTCIndexMSB,kFMTCIndexLSB) = tcid;
  }

  void setTCID(const FMTCID tcid) {
	data_.range(kFMTCIDMSB,kFMTCIDLSB) = tcid;
  }

  void setTrackletNumber(const FMTCNUM num) {
	data_.range(kFMTrackletNumMSB,kFMTrackletNumLSB) = num;
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
