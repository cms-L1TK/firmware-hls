#ifndef FITTRACKMEMORY_HH
#define FITTRACKMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for FitTrackMemory fields
constexpr unsigned int kFTStubIndexSize = 10;
constexpr unsigned int kFTZ0Size = 10;
constexpr unsigned int kFTtSize = 14;
constexpr unsigned int kFTPhi0Size = 19;
constexpr unsigned int kFTpTSize = 15;
// Bit size for full FitTrackMemory
constexpr unsigned int kFitTrackSize = kFTpTSize + kFTPhi0Size + kFTtSize + kFTZ0Size + 6*kFTStubIndexSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the FitTrackMemory word for different fields
constexpr unsigned int kFTStubIndex6LSB = 0;
constexpr unsigned int kFTStubIndex6MSB = kFTStubIndex6LSB + kFTStubIndex6Size - 1;
constexpr unsigned int kFTStubIndex5LSB = kFTStubIndex6MSB + 1;
constexpr unsigned int kFTStubIndex5MSB = kFTStubIndex5LSB + kFTStubIndex5Size - 1;
constexpr unsigned int kFTStubIndex4LSB = kFTStubIndex5MSB + 1;
constexpr unsigned int kFTStubIndex4MSB = kFTStubIndex4LSB + kFTStubIndex4Size - 1;
constexpr unsigned int kFTStubIndex3LSB = kFTStubIndex4MSB + 1;
constexpr unsigned int kFTStubIndex3MSB = kFTStubIndex3LSB + kFTStubIndex3Size - 1;
constexpr unsigned int kFTStubIndex2LSB = kFTStubIndex3MSB + 1;
constexpr unsigned int kFTStubIndex2MSB = kFTStubIndex2LSB + kFTStubIndex2Size - 1;
constexpr unsigned int kFTStubIndex1LSB = kFTStubIndex2MSB + 1;
constexpr unsigned int kFTStubIndex1MSB = kFTStubIndex1LSB + kFTStubIndex1Size - 1;
constexpr unsigned int kFTZ0LSB = kFTStubIndex1MSB + 1;
constexpr unsigned int kFTZ0MSB = kFTZ0LSB + kFTZ0Size - 1;
constexpr unsigned int kFTTLSB = kFTZ0MSB + 1;
constexpr unsigned int kFTTMSB = kFTTLSB + kFTTSize - 1;
constexpr unsigned int kFTPhi0LSB = kFTTMSB + 1;
constexpr unsigned int kFTPhi0MSB = kFTPhi0LSB + kFTPhi0Size - 1;
constexpr unsigned int kFTpTLSB = kFTPhi0MSB + 1;
constexpr unsigned int kFTpTMSB = kFTpTLSB + kFTpTSize - 1;

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

  #ifndef __SYNTHESIS__
  FitTracks(const char* datastr, int base=16)
  {
    FitTrackData = newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  FitTrackData raw() const {return data_;}

  FTPT getPt() const {
    return data_.range(kFTpTMSB,kFTpTLSB);
  }

  FTPHI0 getPhi0() const {
    return data_.range(kFTPhi0MSB,kFTPhi0LSB);
  }

  FTT getT() const {
    return data_.range(kFTTMSB,kFTTLSB);
  }

  FTZ0 getZ0() const {
    return data_.range(kFTZ0MSB,kFTZ0LSB);
  }

  FTSTUBINDEX getStubIndex1() const {
    return data_.range(kFTStubIndex1MSB,kFTStubIndex1LSB);
  }

  FTSTUBINDEX getStubIndex2() const {
    return data_.range(kFTStubIndex2MSB,kFTStubIndex2LSB);
  }

  FTSTUBINDEX getStubIndex3() const {
    return data_.range(kFTStubIndex3MSB,kFTStubIndex3LSB);
  }

  FTSTUBINDEX getStubIndex4() const {
    return data_.range(kFTStubIndex4MSB,kFTStubIndex4LSB);
  }

  FTSTUBINDEX getStubIndex5() const {
    return data_.range(kFTStubIndex5MSB,kFTStubIndex5LSB);
  }

  FTSTUBINDEX getStubIndex6() const {
    return data_.range(kFTStubIndex6MSB,kFTStubIndex6LSB);
  }

  // Setter
  void setPt(const FTPT pt) {
    data_.range(kFTpTMSB,kFTpTLSB) = pt;
  }

  void setPhi0(const FTPHI0 phi0) {
    data_.range(kFTPhi0MSB,kFTPhi0LSB) = phi0;
  }

  void setT(const FTT t) {
    data_.range(kFTTMSB,kFTTLSB) = t;
  }

  void setZ0(const FTZ0 z0) {
    data_.range(kFTZ0MSB,kFTZ0LSB) = z0;
  }

  void setStubIndex1(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex1MSB,kFTStubIndex1LSB) = id;
  }

  void setStubIndex2(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex2MSB,kFTStubIndex2LSB) = id;
  }

  void setStubIndex3(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex3MSB,kFTStubIndex3LSB) = id;
  }

  void setStubIndex4(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex4MSB,kFTStubIndex4LSB) = id;
  }

  void setStubIndex5(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex5MSB,kFTStubIndex5LSB) = id;
  }

  void setStubIndex6(const FTSTUBINDEX id) const {
    data_.range(kFTStubIndex6MSB,kFTStubIndex6LSB) = id;
  }

private:

  FitTrackData data_;

};

// Memory definition
typedef MemoryTemplate<FitTracks, 1, kNBits_MemAddr> FitTrackMemory;

#endif
