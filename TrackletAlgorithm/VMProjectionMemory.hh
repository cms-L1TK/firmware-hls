#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class VMProjection
{
public:

  enum BitWidths {
    // Bit sizes for VMProjectionMemory fields
    kVMProjRinvSize = 5,
    kVMProjFineZSize = 4,
    kVMProjZBinSize = MEBinsBits+1,
    kVMProjIndexSize = 7,
    // Bit size for full VMProjectionMemory
    kVMProjectionSize = kVMProjRinvSize + kVMProjFineZSize + kVMProjZBinSize + kVMProjIndexSize + 1
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMProjectionMemory word for different fields
    kVMProjIsPSSeedLSB = 0,
    kVMProjRinvLSB = 1,
    kVMProjRinvMSB = kVMProjRinvLSB + kVMProjRinvSize - 1,
    kVMProjFineZLSB = kVMProjRinvMSB + 1,
    kVMProjFineZMSB = kVMProjFineZLSB + kVMProjFineZSize - 1,
    kVMProjZBinLSB = kVMProjFineZMSB + 1,
    kVMProjZBinMSB = kVMProjZBinLSB + kVMProjZBinSize - 1,
    kVMProjIndexLSB = kVMProjZBinMSB + 1,
    kVMProjIndexMSB = kVMProjIndexLSB + kVMProjIndexSize - 1
  };
  
  typedef ap_uint<kVMProjIndexSize> VMPID;
  typedef ap_uint<kVMProjZBinSize> VMPZBIN;
  typedef ap_uint<kVMProjFineZSize> VMPFINEZ;
  typedef ap_uint<kVMProjRinvSize> VMPRINV;
	
  typedef ap_uint<kVMProjectionSize> VMProjData;

  // Constructors
  VMProjection(const VMProjData& newdata):
    data_(newdata)
  {}

  VMProjection(const VMPID id, const VMPZBIN zbin, const VMPFINEZ finez, const VMPRINV rinv, const bool ps):
    data_( ((((id,zbin),finez),rinv),ps) )
  {}
  
  VMProjection():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  VMProjection(const char* datastr, int base=16)
  {
    VMProjData newdata(datastr, base);
    data_ = newdata;
  }
  #endif
  
  // Getter
  VMProjData raw() const {return data_;}
  
  VMPID getIndex() const {
    return data_.range(kVMProjIndexMSB,kVMProjIndexLSB);
  }

  VMPZBIN getZBin() const {
    return data_.range(kVMProjZBinMSB,kVMProjZBinLSB);
  }

  VMPFINEZ getFineZ() const {
    return data_.range(kVMProjFineZMSB,kVMProjFineZLSB);
  }
  
  VMPRINV getRInv() const {
    return data_.range(kVMProjRinvMSB,kVMProjRinvLSB);
  }

  bool getIsPSSeed() const {
    return data_.range(kVMProjIsPSSeedLSB,kVMProjIsPSSeedLSB);
  }
  
  // Setter
  void setIndex(const VMPID id) {
    data_.range(kVMProjIndexMSB,kVMProjIndexLSB) = id;
  }
  
  void setZBin(const VMPZBIN zbin) {
    data_.range(kVMProjZBinMSB,kVMProjZBinLSB) = zbin;
  }
  
  void setFineZ(const VMPFINEZ finez) {
    data_.range(kVMProjFineZMSB,kVMProjFineZLSB) = finez;
  }
  
  void setRInv(const VMPRINV rinv) {
    data_.range(kVMProjRinvMSB,kVMProjRinvLSB) = rinv;
  }
  
  void setIsPSSeed(const bool psseed) {
    data_.range(kVMProjIsPSSeedLSB,kVMProjIsPSSeedLSB) = psseed;
  }
  
private:
  
  VMProjData data_;
  
};

// Memory definition
typedef MemoryTemplate<VMProjection, 1, kNBits_MemAddr> VMProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
