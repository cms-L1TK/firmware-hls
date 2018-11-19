#ifndef TRACKLETPROJECTION_HH
#define TRACKLETPROJECTION_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class TrackletProjection
{
public:

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

  TrackletProjection(const bool plusneighbor, const bool minusneighbor, const TProjTCID tcid, const TProjPHI phi, const TProjZ z, const TProjPHIDER phider, const TProjZDER zder):
    data_( ((((((plusneighbor,minusneighbor),tcid),phi),z),phider),zder) )
  {}
  
  TrackletProjection():
    data_(0)
  {}

  TrackletProjection(const char* datastr, int base=16)
  {
    TrackletProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  
  // copy constructor
  TrackletProjection(const TrackletProjection& rhs):
    data_(rhs.raw())
  {}

  // Getter
  TrackletProjectionData raw() const {return data_;}

  bool IsPlusNeighbor() const {
    return data_.range(kTProjIsPlusNeighbourLSB,kTProjIsPlusNeighbourLSB);
  }
  
  bool IsMinusNeighbor() const {
    return data_.range(kTProjIsMinusNeighbourLSB,kTProjIsMinusNeighbourLSB);
  }
  
  TProjTCID GetTrackletIndex() const {
    return data_.range(kTProjTCIndexLSB+kTProjTCIndexSize-1,kTProjTCIndexLSB);
  }

  TProjPHI GetPhi() const {
    return data_.range(kTProjPhiLSB+kTProjPhiSize-1,kTProjPhiLSB);
  }

  TProjZ GetZ() const {
    return data_.range(kTProjZLSB+kTProjZSize-1,kTProjZLSB);
  }

  TProjPHIDER GetPhiDer() {
    return data_.range(kTProjPhiDLSB+kTProjPhiDSize-1,kTProjPhiDLSB);
  }

  TProjZDER GetZDer() {
    return data_.range(kTProjZDLSB+kTProjZDSize-1,kTProjZDLSB);
  }

  // Setter
  void SetIsPlusNeighbor(const bool isplusneighbor) {
    data_.range(kTProjIsPlusNeighbourLSB,kTProjIsPlusNeighbourLSB) = isplusneighbor;
  }

  void SetIsMinusNeighbor(const bool isminusneighbor) {
    data_.range(kTProjIsMinusNeighbourLSB,kTProjIsMinusNeighbourLSB) = isminusneighbor;
  }

  void SetTrackletIndex(const TProjTCID id) {
    data_.range(kTProjTCIndexLSB+kTProjTCIndexSize-1,kTProjTCIndexLSB) = id;
  }

  void SetPhi(const TProjPHI phi) {
    data_.range(kTProjPhiLSB+kTProjPhiSize-1,kTProjPhiLSB) = phi;
  }

  void SetZ(const TProjZ z) {
    data_.range(kTProjZLSB+kTProjZSize-1,kTProjZLSB) = z;
  }

  void SetPhiDer(const TProjPHIDER phider) {
    data_.range(kTProjPhiDLSB+kTProjPhiDSize-1,kTProjPhiDLSB) = phider;
  }

  void SetZDer(const TProjZDER zder) {
    data_.range(kTProjZDLSB+kTProjZDSize-1,kTProjZDLSB) = zder;
  }
  
private:
  
  TrackletProjectionData data_;

};

// Memory definition
typedef MemoryTemplate<TrackletProjection, 1, kNBits_MemAddr> TrackletProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
