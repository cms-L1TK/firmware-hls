#ifndef ALLPROJECTIONMEMORY_HH
#define ALLPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for AllProjectionMemory fields
constexpr unsigned int kAProjZDSize = 10;
constexpr unsigned int kAProjPhiDSize = 11;
constexpr unsigned int kAProjZSize = 12;
constexpr unsigned int kAProjPhiSize = 14;
constexpr unsigned int kAProjTCIndexSize = 13;
//Bit size for full AllProjectionMemory
constexpr unsigned int kAllProjectionSize = 1 + 1 +kAProjTCIndexSize + kAProjPhiSize + kAProjZSize + kAProjPhiDSize + kAProjZDSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the AllProjectionMemory word for different fields
constexpr unsigned int kAProjZDLSB = 0;
constexpr unsigned int kAProjZDMSB = kAProjZDLSB + kAProjZDSize - 1;
constexpr unsigned int kAProjPhiDLSB = kAProjZDMSB + 1;
constexpr unsigned int kAProjPhiDMSB = kAProjPhiDLSB + kAProjPhiDSize - 1;
constexpr unsigned int kAProjZLSB = kAProjPhiDMSB + 1;
constexpr unsigned int kAProjZMSB = kAProjZLSB + kAProjZSize - 1;
constexpr unsigned int kAProjPhiLSB = kAProjZMSB + 1;
constexpr unsigned int kAProjPhiMSB = kAProjPhiLSB + kAProjPhiSize - 1;
constexpr unsigned int kAProjTCIndexLSB = kAProjPhiMSB + 1;
constexpr unsigned int kAProjTCIndexMSB = kAProjTCIndexLSB + kAProjTCIndexSize - 1;
constexpr unsigned int kAProjIsMinusNeighborLSB = kAProjTCIndexMSB + 1;
constexpr unsigned int kAProjIsPlusNeighborLSB = kAProjIsMinusNeighborLSB + 1;

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
  AllProjection(const bool plusneighbor, const bool minusneighbor, const AProjTCID tcid, const AProjPHI phi, const AProjZ z, const AProjPHIDER phider, const AProjZDER zder):
    data_( ((((((plusneighbor,minusneighbor),tcid),phi),z),phider),zder) )
  {}
  
  AllProjection():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  AllProjection(const char* datastr, int base=16)
  {
    AllProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  AllProjectionData raw() const {return data_;}
  
  bool getIsPlusNeighbor() const {
    return data_.range(kAProjIsPlusNeighborLSB,kAProjIsPlusNeighborLSB);
  }
  
  bool getIsMinusNeighbor() const {
    return data_.range(kAProjIsMinusNeighborLSB,kAProjIsMinusNeighborLSB);
  }

  AProjTCID getTrackletIndex() const {
    return data_.range(kAProjTCIndexMSB,kAProjTCIndexLSB);
  }
  
  AProjPHI getPhi() const {
    return data_.range(kAProjPhiMSB,kAProjPhiLSB);
  }
  
  AProjZ getZ() const {
    return data_.range(kAProjZMSB,kAProjZLSB);
  }
  
  AProjPHIDER getPhiDer() const { 
    return data_.range(kAProjPhiDMSB,kAProjPhiDLSB);
  }
  
  AProjZDER getZDer() const {
    return data_.range(kAProjZDMSB,kAProjZDLSB);
  }

  // Setter
  void setIsPlusNeighbor(const bool isplusneighbor) {
    data_.range(kAProjIsPlusNeighborLSB,kAProjIsPlusNeighborLSB) = isplusneighbor;
  }

  void setIsMinusNeighbor(const bool isminusneighbor) {
    data_.range(kAProjIsMinusNeighborLSB,kAProjIsMinusNeighborLSB) = isminusneighbor;
  }

  void setTrackletIndex(const AProjTCID id) {
    data_.range(kAProjTCIndexMSB,kAProjTCIndexLSB) = id;
  }

  void setPhi(const AProjPHI phi) {
    data_.range(kAProjPhiMSB,kAProjPhiLSB) = phi;
  }

  void setZ(const AProjZ z) {
    data_.range(kAProjZMSB,kAProjZLSB) = z;
  }

  void setPhiDer(const AProjPHIDER phider) {
    data_.range(kAProjPhiDMSB,kAProjPhiDLSB) = phider;
  }

  void setZDer(const AProjZDER zder) {
    data_.range(kAProjZDMSB,kAProjZDLSB) = zder;
  }

private:

  AllProjectionData data_;
  
};

// Memory definition
typedef MemoryTemplate<AllProjection, 3, kNBits_MemAddr> AllProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
