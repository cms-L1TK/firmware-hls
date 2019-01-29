#ifndef FULLMATCHMEMORY_HH
#define FULLMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// FullMatchBase is where we define the bit widths, which depend on the class template parameter.
template<regionType FMType> class FullMatchBase {};

template<>
class FullMatchBase<BARREL>
{
public:
  enum BitWidths {
    // Bit size for FullMatchMemory fields
    kFMZResSize = 9,
    kFMPhiResSize = 12,
    kFMStubIndexSize = 10,
    kFMTrackletIndexSize = 7,
    kFMTCIDSize = 7,
    // Bit size for full FullMatchMemory
    kFullMatchSize = kFMTCIDSize + kFMTrackletIndexSize + kFMStubIndexSize + kFMPhiResSize + kFMZResSize
  };
};

template<>
class FullMatchBase<DISK>
{
public:
  enum BitWidths {
    // Bit size for FullMatchMemory fields
    kFMZResSize = 7,
    kFMPhiResSize = 12,
    kFMStubIndexSize = 10,
    kFMTrackletIndexSize = 7,
    kFMTCIDSize = 7,
    // Bit size for full FullMatchMemory
    kFullMatchSize = kFMTCIDSize + kFMTrackletIndexSize + kFMStubIndexSize + kFMPhiResSize + kFMZResSize
  };
};

// Data object definition
template<regionType FMType>
class FullMatch : public FullMatchBase<FMType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the FullMatchMemory word for different fields
    kFMZResLSB = 0,
    kFMZResMSB = kFMZResLSB + FullMatchBase<FMType>::kFMZResSize - 1,
    kFMPhiResLSB = kFMZResMSB + 1,
    kFMPhiResMSB = kFMPhiResLSB + FullMatchBase<FMType>::kFMPhiResSize - 1,
    kFMStubIndexLSB = kFMPhiResMSB + 1,
    kFMStubIndexMSB = kFMStubIndexLSB + FullMatchBase<FMType>::kFMStubIndexSize - 1,
    kFMTrackletIndexLSB = kFMStubIndexMSB + 1,
    kFMTrackletIndexMSB = kFMTrackletIndexLSB + FullMatchBase<FMType>::kFMTrackletIndexSize - 1,
    kFMTCIDLSB = kFMTrackletIndexMSB + 1,
    kFMTCIDMSB = kFMTCIDLSB + FullMatchBase<FMType>::kFMTCIDSize - 1
  };

  typedef ap_int<FullMatchBase<FMType>::kFMZResSize> FMZRES;
  typedef ap_int<FullMatchBase<FMType>::kFMPhiResSize> FMPHIRES;
  typedef ap_uint<FullMatchBase<FMType>::kFMStubIndexSize> FMSTUBINDEX;
  typedef ap_uint<FullMatchBase<FMType>::kFMTrackletIndexSize> FMTrackletIndex;
  typedef ap_uint<FullMatchBase<FMType>::kFMTCIDSize> FMTCID;

  typedef ap_uint<FullMatchBase<FMType>::kFullMatchSize> FullMatchData;

  // Constructors
  FullMatch(const FullMatchData& newdata):
    data_(newdata)
  {}

  FullMatch(const FMTCID tcid, const FMTrackletIndex trackletindex, const FMSTUBINDEX stub, const FMPHIRES phires, const FMZRES zres):
    data_( ((((tcid,trackletindex),stub),phires),zres) )
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

  FMTCID getTCID() const {
    return data_.range(kFMTCIDMSB,kFMTCIDLSB);
  }

  FMTrackletIndex getTrackletIndex() const {
    return data_.range(kFMTrackletIndexMSB,kFMTrackletIndexLSB);
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
  void setTCID(const FMTCID tcid) {
    data_.range(kFMTCIDMSB,kFMTCIDLSB) = tcid;
  }

  void setTrackletIndex(const FMTrackletIndex trackletindex) {
    data_.range(kFMTrackletIndexMSB,kFMTrackletIndexLSB) = trackletindex;
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
template<regionType FMType> using FullMatchMemory = MemoryTemplate<FullMatch<FMType>, 1, kNBits_MemAddr>;

#endif
