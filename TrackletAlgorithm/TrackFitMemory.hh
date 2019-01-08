#ifndef TRACKFITMEMORY_HH
#define TRACKFITMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class TrackFit
{
public:

  enum BitWidths {
    // Bit size for TrackFitMemory fields
    kTFStubIndexSize = 10,
    kTFZ0Size = 10,
    kTFTSize = 14,
    kTFPhi0Size = 19,
    kTFpTSize = 15,
    // Bit size for full TrackFitMemory
    kTrackFitSize = kTFpTSize + kTFPhi0Size + kTFTSize + kTFZ0Size + 6*kTFStubIndexSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackFitMemory word for different fields
    kTFStubIndex6LSB = 0,
    kTFStubIndex6MSB = kTFStubIndex6LSB + kTFStubIndexSize - 1,
    kTFStubIndex5LSB = kTFStubIndex6MSB + 1,
    kTFStubIndex5MSB = kTFStubIndex5LSB + kTFStubIndexSize - 1,
    kTFStubIndex4LSB = kTFStubIndex5MSB + 1,
    kTFStubIndex4MSB = kTFStubIndex4LSB + kTFStubIndexSize - 1,
    kTFStubIndex3LSB = kTFStubIndex4MSB + 1,
    kTFStubIndex3MSB = kTFStubIndex3LSB + kTFStubIndexSize - 1,
    kTFStubIndex2LSB = kTFStubIndex3MSB + 1,
    kTFStubIndex2MSB = kTFStubIndex2LSB + kTFStubIndexSize - 1,
    kTFStubIndex1LSB = kTFStubIndex2MSB + 1,
    kTFStubIndex1MSB = kTFStubIndex1LSB + kTFStubIndexSize - 1,
    kTFZ0LSB = kTFStubIndex1MSB + 1,
    kTFZ0MSB = kTFZ0LSB + kTFZ0Size - 1,
    kTFTLSB = kTFZ0MSB + 1,
    kTFTMSB = kTFTLSB + kTFTSize - 1,
    kTFPhi0LSB = kTFTMSB + 1,
    kTFPhi0MSB = kTFPhi0LSB + kTFPhi0Size - 1,
    kTFpTLSB = kTFPhi0MSB + 1,
    kTFpTMSB = kTFpTLSB + kTFpTSize - 1
  };

  typedef ap_int<kTFpTSize> TFPT;
  typedef ap_int<kTFPhi0Size> TFPHI0;
  typedef ap_int<kTFTSize> TFT;
  typedef ap_int<kTFZ0Size> TFZ0;
  typedef ap_uint<kTFStubIndexSize> TFSTUBINDEX;

  typedef ap_uint<kTrackFitSize> TrackFitData;

  // Constructors
  TrackFit(const TrackFitData& newdata):
    data_(newdata)
  {}

  TrackFit(const TFPT pt, const TFPHI0 phi0, const TFT t, const TFZ0 z0, const TFSTUBINDEX id1, const TFSTUBINDEX id2, const TFSTUBINDEX id3, const TFSTUBINDEX id4, const TFSTUBINDEX id5, const TFSTUBINDEX id6):
    data_( (((((((((pt,phi0),t),z0),id1),id2),id3),id4),id5),id6) )
  {}

  TrackFit():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  TrackFit(const char* datastr, int base=16)
  {
    TrackFitData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  TrackFitData raw() const {return data_;}

  TFPT getPt() const {
    return data_.range(kTFpTMSB,kTFpTLSB);
  }

  TFPHI0 getPhi0() const {
    return data_.range(kTFPhi0MSB,kTFPhi0LSB);
  }

  TFT getT() const {
    return data_.range(kTFTMSB,kTFTLSB);
  }

  TFZ0 getZ0() const {
    return data_.range(kTFZ0MSB,kTFZ0LSB);
  }

  TFSTUBINDEX getStubIndex1() const {
    return data_.range(kTFStubIndex1MSB,kTFStubIndex1LSB);
  }

  TFSTUBINDEX getStubIndex2() const {
    return data_.range(kTFStubIndex2MSB,kTFStubIndex2LSB);
  }

  TFSTUBINDEX getStubIndex3() const {
    return data_.range(kTFStubIndex3MSB,kTFStubIndex3LSB);
  }

  TFSTUBINDEX getStubIndex4() const {
    return data_.range(kTFStubIndex4MSB,kTFStubIndex4LSB);
  }

  TFSTUBINDEX getStubIndex5() const {
    return data_.range(kTFStubIndex5MSB,kTFStubIndex5LSB);
  }

  TFSTUBINDEX getStubIndex6() const {
    return data_.range(kTFStubIndex6MSB,kTFStubIndex6LSB);
  }

  // Setter
  void setPt(const TFPT pt) {
    data_.range(kTFpTMSB,kTFpTLSB) = pt;
  }

  void setPhi0(const TFPHI0 phi0) {
    data_.range(kTFPhi0MSB,kTFPhi0LSB) = phi0;
  }

  void setT(const TFT t) {
    data_.range(kTFTMSB,kTFTLSB) = t;
  }

  void setZ0(const TFZ0 z0) {
    data_.range(kTFZ0MSB,kTFZ0LSB) = z0;
  }

  void setStubIndex1(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex1MSB,kTFStubIndex1LSB) = id;
  }

  void setStubIndex2(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex2MSB,kTFStubIndex2LSB) = id;
  }

  void setStubIndex3(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex3MSB,kTFStubIndex3LSB) = id;
  }

  void setStubIndex4(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex4MSB,kTFStubIndex4LSB) = id;
  }

  void setStubIndex5(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex5MSB,kTFStubIndex5LSB) = id;
  }

  void setStubIndex6(const TFSTUBINDEX id) const {
    data_.range(kTFStubIndex6MSB,kTFStubIndex6LSB) = id;
  }

private:

  TrackFitData data_;

};

// Memory definition
typedef MemoryTemplate<TrackFit, 1, kNBits_MemAddr> TrackFitMemory;

#endif
