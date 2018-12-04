#ifndef ALLPROJECTIONMEMORY_HH
#define ALLPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for AllProjectionMemory fields
constexpr unsigned int kAProjZDSize = 10;
constexpr unsigned int kAProjPhiDSize = 10;
constexpr unsigned int kAProjZSize = 12;
constexpr unsigned int kAProjPhiSize = 14;
constexpr unsigned int kAProjTCIndexSize = 14;
constexpr unsigned int kAProjTCSeedSize = 3;        // sub division of TCIndex
constexpr unsigned int kAProjTCVMSize = 4;          // sub division of TCIndex
constexpr unsigned int kAProjTCNumSize = 7;   // sub division of TCIndex
//Bit size for full AllProjectionMemory
constexpr unsigned int kAllProjectionSize = kAProjTCIndexSize + kAProjPhiSize + kAProjZSize + kAProjPhiDSize + kAProjZDSize;

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
constexpr unsigned int kAProjTCNumLSB = kAProjPhiMSB + 1;
constexpr unsigned int kAProjTCNumMSB = kAProjTCNumLSB + kAProjTCNumSize - 1;
constexpr unsigned int kAProjTCVMLSB = kAProjTCNumMSB + 1;
constexpr unsigned int kAProjTCVMMSB = kAProjTCVMLSB + kAProjTCVMSize - 1;
constexpr unsigned int kAProjTCSeedLSB = kAProjTCVMMSB + 1;
constexpr unsigned int kAProjTCSeedMSB = kAProjTCSeedLSB + kAProjTCSeedSize - 1;

// Data object definition
class AllProjection
{
public:

  typedef ap_uint<kAProjTCIndexSize> AProjTCID;
  typedef ap_uint<kAProjTCSeedSize> AProjTCSEED; // sub division of TCID
  typedef ap_uint<kAProjTCVMSize> AProjTCVM;     // sub division of TCID
  typedef ap_uint<kAProjTCNumSize> AProjTCNUM;   // sub division of TCID
  typedef ap_uint<kAProjPhiSize> AProjPHI;
  typedef ap_int<kAProjZSize> AProjZ;
  typedef ap_int<kAProjPhiDSize> AProjPHIDER;
  typedef ap_int<kAProjZDSize> AProjZDER;
  
  typedef ap_uint<kAllProjectionSize> AllProjectionData;
  
  // Constructors
  AllProjection(const AllProjectionData& newdata):
    data_(newdata)
  {}

  AllProjection(const AProjTCID tcid, const AProjPHI phi, const AProjZ z, const AProjPHIDER phider, const AProjZDER zder):
    data_( ((((tcid,phi),z),phider),zder) )
  {}
  
  AllProjection(const AProjTCSEED seed, const AProjTCVM vm, const AProjTCNUM num, const AProjPHI phi, const AProjZ z, const AProjPHIDER phider, const AProjZDER zder):
    data_( ((((((seed,vm),num),phi),z),phider),zder) )
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
  
  AProjTCID getTrackletIndex() const {
    return data_.range(kAProjTCIndexMSB,kAProjTCIndexLSB);
  }

  AProjTCSEED getSeed() const {
	return data_.range(kAProjTCSeedMSB,kAProjTCSeedLSB);
  }
  
  AProjTCVM getVM() const {
	return data_.range(kAProjTCVMMSB,kAProjTCVMLSB);
  }

  AProjTCNUM getTrackletNumber() const {
	return data_.range(kAProjTCNumMSB,kAProjTCNumLSB);
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
  void setTrackletIndex(const AProjTCID id) {
    data_.range(kAProjTCIndexMSB,kAProjTCIndexLSB) = id;
  }

  void setTrackletNumber(const AProjTCNUM num) {
	data_.range(kAProjTCNumMSB,kAProjTCNumLSB) = num;
  }

  void setSeed(const AProjTCSEED seed) {
	data_.range(kAProjTCSeedMSB,kAProjTCSeedLSB) = seed;
  }

  void setVM(const AProjTCVM vm) {
	data_.range(kAProjTCVMMSB,kAProjTCVMLSB) = vm;
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
