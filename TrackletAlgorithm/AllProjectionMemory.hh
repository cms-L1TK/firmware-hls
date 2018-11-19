#ifndef ALLPROJECTIONMEMORY_HH
#define ALLPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class AllProjection
{
public:

  typedef ap_uint<kAProjTCIndexSize> AProjTCID;
  typedef ap_uint<kAProjPhiSize> AProjPHI;
  typedef ap_int<kAProjZSize> AProjZ;
  typedef ap_int<kAProjPhiDSize> AProjPHIDER;
  typedef ap_int<kAProjZDSize> AProjZDER;
  
  typedef ap_uint<kTrackletProjectionSize> AllProjectionData;
  
  // Constructors
  AllProjection(const AllProjectionData& newdata):
    data_(newdata)
  {}

  AllProjection(const bool plusneighbor, const bool minusneighbor, const AProjTCID tcid, const AProjPHI phi, const AProjZ z, const AProjPHIDER phider, const AProjZDER zder):
    data_( ((((((plusneighbor,minusneighbor),tcid),phi),z),phider),zder) )
  {}
  
  AllProjection():
    data_(0)
  {}

  AllProjection(const char* datastr, int base=16)
  {
    AllProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  
  // copy constructor
  AllProjection(const AllProjection& rhs):
    data_(rhs.raw())
  {}

  // Getter
  AllProjectionData raw() const {return data_;}
  
  bool IsPlusNeighbor() const {
    return data_.range(kAProjIsPlusNeighbourLSB,kAProjIsPlusNeighbourLSB);
  }
  
  bool IsMinusNeighbor() const {
    return data_.range(kAProjIsMinusNeighbourLSB,kAProjIsMinusNeighbourLSB);
  }

  AProjTCID GetTrackletIndex() const {
    return data_.range(kAProjTCIndexLSB+kAProjTCIndexSize-1,kAProjTCIndexLSB);
  }
  
  AProjPHI GetPhi() const {
    return data_.range(kAProjPhiLSB+kAProjPhiSize-1,kAProjPhiLSB);
  }
  
  AProjZ GetZ() const {
    return data_.range(kAProjZLSB+kAProjZSize-1,kAProjZLSB);
  }
  
  AProjPHIDER GetPhiDer() const { 
    return data_.range(kAProjPhiDLSB+kAProjPhiDSize-1,kAProjPhiDLSB);
  }
  
  AProjZDER GetZDer() const {
    return data_.range(kAProjZDLSB+kAProjZDSize-1,kAProjZDLSB);
  }

  // Setter
  void SetIsPlusNeighbor(const bool isplusneighbor) {
    data_.range(kAProjIsPlusNeighbourLSB,kAProjIsPlusNeighbourLSB) = isplusneighbor;
  }

  void SetIsMinusNeighbor(const bool isminusneighbor) {
    data_.range(kAProjIsMinusNeighbourLSB,kAProjIsMinusNeighbourLSB) = isminusneighbor;
  }

  void SetTrackletIndex(const AProjTCID id) {
    data_.range(kAProjTCIndexLSB+kAProjTCIndexSize-1,kAProjTCIndexLSB) = id;
  }

  void SetPhi(const AProjPHI phi) {
    data_.range(kAProjPhiLSB+kAProjPhiSize-1,kAProjPhiLSB) = phi;
  }

  void SetZ(const AProjZ z) {
    data_.range(kAProjZLSB+kAProjZSize-1,kAProjZLSB) = z;
  }

  void SetPhiDer(const AProjPHIDER phider) {
    data_.range(kAProjPhiDLSB+kAProjPhiDSize-1,kAProjPhiDLSB) = phider;
  }

  void SetZDer(const AProjZDER zder) {
    data_.range(kAProjZDLSB+kAProjZDSize-1,kAProjZDLSB) = zder;
  }

private:

  AllProjectionData data_;
  
};

// Memory definition
typedef MemoryTemplate<AllProjection, 3, kNBits_MemAddr> AllProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
