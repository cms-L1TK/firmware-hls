#ifndef TRACKLETPROJECTION_HH
#define TRACKLETPROJECTION_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

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
    kTProjTCIDMSB = kTProjTCIDLSB + TrackletProjectionBase<TProjType>::kTProjTCIDSize - 1
  };

  typedef ap_uint<TrackletProjectionBase<TProjType>::kTProjTCIDSize> TProjTCID;
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
  
  TrackletProjection():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  TrackletProjection(const char* datastr, int base=16)
  {
    TrackletProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  TrackletProjectionData raw() const {return data_;}

  TProjTCID getTCID() const {
    return data_.range(kTProjTCIDMSB,kTProjTCIDLSB);
  }

  TProjTCID getTrackletIndex() const {
    return data_.range(kTProjTrackletIndexMSB,kTProjTrackletIndexLSB);
  }

  TProjPHI getPhi() const {
    return data_.range(kTProjPhiMSB,kTProjPhiLSB);
  }

  TProjRZ getRZ() const {
    return data_.range(kTProjRZMSB,kTProjRZLSB);
  }

  TProjPHIDER getPhiDer() {
    return data_.range(kTProjPhiDMSB,kTProjPhiDLSB);
  }

  TProjRZDER getRZDer() {
    return data_.range(kTProjRZDMSB,kTProjRZDLSB);
  }

 // Setter
  void setTCID(const TProjTCID id) {
    data_.range(kTProjTCIDMSB,kTProjTCIDLSB) = id;
  }

  void setTrackletIndex(const TProjTCID id) {
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
  
private:
  
  TrackletProjectionData data_;

};

// Memory definition
template<int TProjType> using TrackletProjectionMemory = MemoryTemplate<TrackletProjection<TProjType>, 1, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
