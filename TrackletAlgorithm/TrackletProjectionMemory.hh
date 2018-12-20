#ifndef TRACKLETPROJECTION_HH
#define TRACKLETPROJECTION_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class TrackletProjection
{
public:

  enum BitWidths {
    // Bit size for TrackletProjectionMemory fields
    kTProjZDSize = 10,
    kTProjPhiDSize = 10,
    kTProjZSize = 12,
    kTProjPhiSize = 14,
    kTProjTCIndexSize = 14,
    // Bit size for full TrackletProjectionMemory
    kTrackletProjectionSize = kTProjTCIndexSize + kTProjPhiSize + kTProjZSize + kTProjPhiDSize + kTProjZDSize
  };
  enum BitProjections {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackletProjectionMemory word for different fields
    kTProjZDLSB = 0,
    kTProjZDMSB = kTProjZDLSB + kTProjZDSize - 1,
    kTProjPhiDLSB = kTProjZDMSB + 1,
    kTProjPhiDMSB = kTProjPhiDLSB + kTProjPhiDSize - 1,
    kTProjZLSB = kTProjPhiDMSB + 1,
    kTProjZMSB = kTProjZLSB + kTProjZSize - 1,
    kTProjPhiLSB = kTProjZMSB + 1,
    kTProjPhiMSB = kTProjPhiLSB + kTProjPhiSize - 1,
    kTProjTCIndexLSB = kTProjPhiMSB + 1,
    kTProjTCIndexMSB = kTProjTCIndexLSB + kTProjTCIndexSize - 1
  };

  typedef ap_uint<kTProjTCIndexSize> TProjTCID;
  typedef ap_uint<kTProjPhiSize> TProjPHI;
  typedef ap_int<kTProjZSize> TProjZ;
  typedef ap_int<kTProjPhiDSize> TProjPHIDER;
  typedef ap_int<kTProjZDSize> TProjZDER;
  
  typedef ap_uint<kTrackletProjectionSize> TrackletProjectionData;

  // Constructors
  TrackletProjection(const TrackletProjectionData& newdata):
    data_(newdata)
  {}

  TrackletProjection(const TProjTCID tcid, const TProjPHI phi, const TProjZ z, const TProjPHIDER phider, const TProjZDER zder):
    data_( ((((tcid,phi),z),phider),zder) )
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

  TProjTCID getTrackletIndex() const {
    return data_.range(kTProjTCIndexMSB,kTProjTCIndexLSB);
  }

  TProjPHI getPhi() const {
    return data_.range(kTProjPhiMSB,kTProjPhiLSB);
  }

  TProjZ getZ() const {
    return data_.range(kTProjZMSB,kTProjZLSB);
  }

  TProjPHIDER getPhiDer() {
    return data_.range(kTProjPhiDMSB,kTProjPhiDLSB);
  }

  TProjZDER getZDer() {
    return data_.range(kTProjZDMSB,kTProjZDLSB);
  }

  void setTrackletIndex(const TProjTCID id) {
    data_.range(kTProjTCIndexMSB,kTProjTCIndexLSB) = id;
  }

  void setPhi(const TProjPHI phi) {
    data_.range(kTProjPhiMSB,kTProjPhiLSB) = phi;
  }

  void setZ(const TProjZ z) {
    data_.range(kTProjZMSB,kTProjZLSB) = z;
  }

  void setPhiDer(const TProjPHIDER phider) {
    data_.range(kTProjPhiDMSB,kTProjPhiDLSB) = phider;
  }

  void setZDer(const TProjZDER zder) {
    data_.range(kTProjZDMSB,kTProjZDLSB) = zder;
  }
  
private:
  
  TrackletProjectionData data_;

};

// Memory definition
typedef MemoryTemplate<TrackletProjection, 1, kNBits_MemAddr> TrackletProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
