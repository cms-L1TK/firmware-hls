#ifndef ALLPROJECTIONMEMORY_HH
#define ALLPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class AllProjection
{
public:

  enum BitWidths {
    // Bit size for AllProjectionMemory fields
    kAProjZDSize = 10,
    kAProjPhiDSize = 10,
    kAProjZSize = 12,
    kAProjPhiSize = 14,
    kAProjTCIndexSize = 14,
    kAProjTCSeedSize = 3,        // sub division of TCIndex
    kAProjTCVMSize = 4,          // sub division of TCIndex
    kAProjTCNumSize = 7,   // sub division of TCIndex
    //Bit size for full AllProjectionMemory
    kAllProjectionSize = kAProjTCIndexSize + kAProjPhiSize + kAProjZSize + kAProjPhiDSize + kAProjZDSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllProjectionMemory word for different fields
    kAProjZDLSB = 0,
    kAProjZDMSB = kAProjZDLSB + kAProjZDSize - 1,
    kAProjPhiDLSB = kAProjZDMSB + 1,
    kAProjPhiDMSB = kAProjPhiDLSB + kAProjPhiDSize - 1,
    kAProjZLSB = kAProjPhiDMSB + 1,
    kAProjZMSB = kAProjZLSB + kAProjZSize - 1,
    kAProjPhiLSB = kAProjZMSB + 1,
    kAProjPhiMSB = kAProjPhiLSB + kAProjPhiSize - 1,
    kAProjTCIndexLSB = kAProjPhiMSB + 1,
    kAProjTCIndexMSB = kAProjTCIndexLSB + kAProjTCIndexSize - 1,
    kAProjTCNumLSB = kAProjPhiMSB + 1,
    kAProjTCNumMSB = kAProjTCNumLSB + kAProjTCNumSize - 1,
    kAProjTCVMLSB = kAProjTCNumMSB + 1,
    kAProjTCVMMSB = kAProjTCVMLSB + kAProjTCVMSize - 1,
    kAProjTCSeedLSB = kAProjTCVMMSB + 1,
    kAProjTCSeedMSB = kAProjTCSeedLSB + kAProjTCSeedSize - 1
  };

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
