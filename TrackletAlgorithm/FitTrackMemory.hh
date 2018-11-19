#ifndef FITTRACKMEMORY_HH
#define FITTRACKMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class FitTracks
{
public:

  typedef ap_int<kFTpTSize> FTPT;
  typedef ap_int<kFTPhi0Size> FTPHI0;
  typedef ap_int<kFTTSize> FTT;
  typedef ap_int<kDTZ0Size> FTZ0;
  typedef ap_uint<kFTStubIndexSize FTSTUBINDEX;

  typedef ap_uint<kFitTrackSize> FitTrackData;

  // Constructors
  FitTracks(const FitTrackData& newdata):
    data_(newdata)
  {}

  FitTracks(const FTPT pt, const FTPHI0 phi0, const FTT t, const FTZ0 z0, const FTSTUBINDEX id1, const FTSTUBINDEX id2, const FTSTUBINDEX id3, const FTSTUBINDEX id4, const FTSTUBINDEX id5, const FTSTUBINDEX id6):
    data_( (((((((((pt,phi0),t),z0),id1),id2),id3),id4),id5),id6) )
  {}

  FitTracks():
    data_(0)
  {}

  FitTracks(const char* datastr, int base=16)
  {
    FitTrackData = newdata(datastr, base);
    data_ = newdata;
  }

  // copy constructor
  FitTracks(const FitTracks& rhs):
    data_(rhs.raw())
  {}

  // Getter
  FitTrackData raw() const {return data_;}

  FTPT GetPt() const {
    return data_.range(kFTpTLSB+kFTpTSize-1,kFTpTLSB);
  }

  FTPHI0 GetPhi0() const {
    return data_.range(kFTPhi0LSB+kFTPhi0Size-1,kFTPhi0LSB);
  }

  FTT GetT() const {
    return data_.range(kFTTLSB+kFTTSize-1,kFTTLSB);
  }

  FTZ0 GetZ0() const {
    return data_.range(kFTZ0LSB+kFTZ0Size-1,kFTZ0LSB);
  }

  FTSTUBINDEX GetStubIndex1() const {
    return data_.range(kFTStubIndex1LSB+kFTStubIndexSize-1,kFTStubIndex1LSB);
  }

  FTSTUBINDEX GetStubIndex2() const {
    return data_.range(kFTStubIndex2LSB+kFTStubIndexSize-1,kFTStubIndex2LSB);
  }

  FTSTUBINDEX GetStubIndex3() const {
    return data_.range(kFTStubIndex3LSB+kFTStubIndexSize-1,kFTStubIndex3LSB);
  }

  FTSTUBINDEX GetStubIndex4() const {
    return data_.range(kFTStubIndex4LSB+kFTStubIndexSize-1,kFTStubIndex4LSB);
  }

  FTSTUBINDEX GetStubIndex5() const {
    return data_.range(kFTStubIndex5LSB+kFTStubIndexSize-1,kFTStubIndex5LSB);
  }

  FTSTUBINDEX GetStubIndex6() const {
    return data_.range(kFTStubIndex6LSB+kFTStubIndexSize-1,kFTStubIndex6LSB);
  }

  // Setter
  void SetPt(const FTPT pt) {
    data_.range(kFTpTLSB+kFTpTSize-1,kFTpTLSB) = pt;
  }

  void SetPhi0(const FTPHI0 phi0) {
    data_.range(kFTPhi0LSB+kFTPhi0Size-1,kFTPhi0LSB) = phi0;
  }

  void SetT(const FTT t) {
    data_.range(kFTTLSB+kFTTSize-1,kFTTLSB) = t;
  }

  void SetZ0(const FTZ0 z0) {
    data_.range(kFTZ0LSB+kFTZ0Size-1,kFTZ0LSB) = z0;
  }

  void SetStubIndex1(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex1LSB+kFTStubIndexSize-1,kFTStubIndex1LSB) = id;
  }

  void SetStubIndex2(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex2LSB+kFTStubIndexSize-1,kFTStubIndex2LSB) = id;
  }

  void SetStubIndex3(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex3LSB+kFTStubIndexSize-1,kFTStubIndex3LSB) = id;
  }

  void SetStubIndex4(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex4LSB+kFTStubIndexSize-1,kFTStubIndex4LSB) = id;
  }

  void SetStubIndex5(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex5LSB+kFTStubIndexSize-1,kFTStubIndex5LSB) = id;
  }

  void SetStubIndex6(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex6LSB+kFTStubIndexSize-1,kFTStubIndex6LSB) = id;
  }

private:

  FitTrackData data_;

};

// Memory definition
typedef MemoryTemplate<FitTracks, 1, kNBits_MemAddr> FitTrackMemory;

#endif
