#ifndef TrackletAlgorithm_TrackletProjectionMemory_h
#define TrackletAlgorithm_TrackletProjectionMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"
#include "globalFunctions.h"

// TrackletProjectionBase is where we define the bit widths, which depend on
// the class template parameter.
template<int TProjType> class TrackletProjectionBase {};

template<>
class TrackletProjectionBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for TrackletProjectionMemory fields
    kTProjRZDSize = 10,
    kTProjPhiDSize = 10,
    kTProjRZSize = 12,
    kTProjPhiSize = 14,
    kTProjTCIDSize = 7,
    kTProjSeedSize = 3, // upper three bits of TCID
    kTProjITCSize = 4, // lower four bits of TCID
    kTProjTrackletIndexSize = 7,
    // Bit size for full TrackletProjectionMemory
    kTrackletProjectionSize = kTProjTCIDSize + kTProjTrackletIndexSize + kTProjPhiSize + kTProjRZSize + kTProjPhiDSize + kTProjRZDSize
  };
};

template<>
class TrackletProjectionBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for TrackletProjectionMemory fields
    kTProjRZDSize = 9,
    kTProjPhiDSize = 10,
    kTProjRZSize = 8,
    kTProjPhiSize = 17,
    kTProjTCIDSize = 7,
    kTProjSeedSize = 3, // upper three bits of TCID
    kTProjITCSize = 4, // lower four bits of TCID
    kTProjTrackletIndexSize = 7,
    // Bit size for full TrackletProjectionMemory
    kTrackletProjectionSize = kTProjTCIDSize + kTProjTrackletIndexSize + kTProjPhiSize + kTProjRZSize + kTProjPhiDSize + kTProjRZDSize
  };
};

template<>
class TrackletProjectionBase<DISK>
{
public:
  enum BitWidths {
    // Bit size for TrackletProjectionMemory fields
    kTProjRZDSize = 9,
    kTProjPhiDSize = 10,
    kTProjRZSize = 12,
    kTProjPhiSize = 14,
    kTProjTCIDSize = 7,
    kTProjSeedSize = 3, // upper three bits of TCID
    kTProjITCSize = 4, // lower four bits of TCID
    kTProjTrackletIndexSize = 7,
    // Bit size for full TrackletProjectionMemory
    kTrackletProjectionSize = kTProjTCIDSize + kTProjTrackletIndexSize + kTProjPhiSize + kTProjRZSize + kTProjPhiDSize + kTProjRZDSize
  };
};


// Data object definition
template<int TProjType>
class TrackletProjection : public TrackletProjectionBase<TProjType>
{
public:
  enum BitProjections {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackletProjectionMemory word for different fields
    kTProjRZDLSB = 0,
    kTProjRZDMSB = kTProjRZDLSB + TrackletProjectionBase<TProjType>::kTProjRZDSize - 1,
    kTProjPhiDLSB = kTProjRZDMSB + 1,
    kTProjPhiDMSB = kTProjPhiDLSB + TrackletProjectionBase<TProjType>::kTProjPhiDSize - 1,
    kTProjRZLSB = kTProjPhiDMSB + 1,
    kTProjRZMSB = kTProjRZLSB + TrackletProjectionBase<TProjType>::kTProjRZSize - 1,
    kTProjPhiLSB = kTProjRZMSB + 1,
    kTProjPhiMSB = kTProjPhiLSB + TrackletProjectionBase<TProjType>::kTProjPhiSize - 1,
    kTProjTrackletIndexLSB = kTProjPhiMSB + 1,
    kTProjTrackletIndexMSB = kTProjTrackletIndexLSB + TrackletProjectionBase<TProjType>::kTProjTrackletIndexSize - 1,
    kTProjTCIDLSB = kTProjTrackletIndexMSB + 1,
    kTProjTCIDMSB = kTProjTCIDLSB + TrackletProjectionBase<TProjType>::kTProjTCIDSize - 1,

    // subdivisions of the TCID
    kTProjITCLSB = kTProjTrackletIndexMSB + 1,
    kTProjITCMSB = kTProjITCLSB + TrackletProjectionBase<TProjType>::kTProjITCSize - 1,
    kTProjSeedLSB = kTProjITCMSB + 1,
    kTProjSeedMSB = kTProjSeedLSB + TrackletProjectionBase<TProjType>::kTProjSeedSize - 1,
  };

  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjTCIDSize> TProjTCID;
  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjSeedSize> TProjSeed;
  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjITCSize> TProjITC;
  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjTrackletIndexSize> TProjTrackletIndex;
  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjPhiSize> TProjPHI;
  typedef ap_int<TrackletProjectionBase<TProjType>::kTProjRZSize> TProjRZ;
  typedef ap_int<TrackletProjectionBase<TProjType>::kTProjPhiDSize> TProjPHIDER;
  typedef ap_int<TrackletProjectionBase<TProjType>::kTProjRZDSize> TProjRZDER;
  
  typedef ap_uint<TrackletProjectionBase<TProjType>::kTrackletProjectionSize> TrackletProjectionData;

  // Constructors
  TrackletProjection(const TrackletProjectionData& newdata):
    data_(newdata)
  {}

  TrackletProjection(const TProjTCID tcid, const TProjTrackletIndex trackletIndex, const TProjPHI phi, const TProjRZ z, const TProjPHIDER phider, const TProjRZDER zder):
    data_( (((((tcid,trackletIndex),phi),z),phider),zder) )
  {}
  
  TrackletProjection()
  {}

  #ifndef __SYNTHESIS__
  TrackletProjection(const char* datastr, int base=16)
  {
    TrackletProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return TrackletProjectionBase<TProjType>::kTrackletProjectionSize;}

  TrackletProjectionData raw() const {return data_;}

  // TCID is a unique identifier assigned to each TC. It is a concatenation of
  // the seed and iTC numbers:
  // TCID = (seed<<4) + iTC
  // The seed number is assigned as follows:
  //   L1L2 -> 0
  //   L2L3 -> 1
  //   L3L4 -> 2
  //   L5L6 -> 3
  //   D1D2 -> 4
  //   D3D4 -> 5
  //   D1L1/L1D1 -> 6
  //   D1L2/L2D1 -> 7
  // The iTC number comes from the letter at the end of the TC name (i.e.,
  // TC_L1L2A and TC_L5L6A have the same iTC number); generally indicates the
  // region of the phi sector being processed:
  //   A -> 0
  //   B -> 1
  //   C -> 2
  //   ...
  TProjTCID getTCID() const {
    return data_.range(kTProjTCIDMSB,kTProjTCIDLSB);
  }

  TProjSeed getSeed() const {
    return data_.range(kTProjSeedMSB,kTProjSeedLSB);
  }

  TProjITC getITC() const {
    return data_.range(kTProjITCMSB,kTProjITCLSB);
  }

  // The tracklets in an event are indexed starting from zero, and the indices
  // are independent for each TC; i.e., the first tracklet written by any given
  // TC has tracklet index zero, the second tracklet written by any given TC
  // has tracklet index one, etc.
  TProjTrackletIndex getTrackletIndex() const {
    return data_.range(kTProjTrackletIndexMSB,kTProjTrackletIndexLSB);
  }

  TProjPHI getPhi() const {
    return data_.range(kTProjPhiMSB,kTProjPhiLSB);
  }

  TProjRZ getRZ() const {
    return data_.range(kTProjRZMSB,kTProjRZLSB);
  }

  // The phi derivative is d(phi)/d(r) at the given layer/disk
  TProjPHIDER getPhiDer() const {
    return data_.range(kTProjPhiDMSB,kTProjPhiDLSB);
  }

  // The r/z derivative is d(z)/d(r) at the given layer and d(r)/d(z) at the
  // given disk
  TProjRZDER getRZDer() const {
    return data_.range(kTProjRZDMSB,kTProjRZDLSB);
  }

 // Setter
  void setTCID(const TProjTCID id) {
    data_.range(kTProjTCIDMSB,kTProjTCIDLSB) = id;
  }

  void setTrackletIndex(const TProjTrackletIndex id) {
    data_.range(kTProjTrackletIndexMSB,kTProjTrackletIndexLSB) = id;
  }

  void setPhi(const TProjPHI phi) {
    data_.range(kTProjPhiMSB,kTProjPhiLSB) = phi;
  }

  void setRZ(const TProjRZ z) {
    data_.range(kTProjRZMSB,kTProjRZLSB) = z;
  }

  void setPhiDer(const TProjPHIDER phider) {
    data_.range(kTProjPhiDMSB,kTProjPhiDLSB) = phider;
  }

  void setRZDer(const TProjRZDER zder) {
    data_.range(kTProjRZDMSB,kTProjRZDLSB) = zder;
  }

#ifdef CMSSW_GIT_HASH
  std::string getBitStr() const {
    std::string str = decodeToBits(getTCID());
    str += "|"+decodeToBits(getTrackletIndex());
    str += "|"+decodeToBits(getPhi());
    str += "|"+decodeToBits(getRZ());
    str += "|"+decodeToBits(getPhiDer());
    str += "|"+decodeToBits(getRZDer());
    return str;
  }
#endif

private:
  
  TrackletProjectionData data_;

};

// Memory definition
template<int TProjType> using TrackletProjectionMemory = MemoryTemplate<TrackletProjection<TProjType>, 1, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
