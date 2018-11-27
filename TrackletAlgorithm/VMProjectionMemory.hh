#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit sizes for VMProjectionMemory fields
constexpr unsigned int kVMProjRinvSize = 5;
constexpr unsigned int kVMProjFineZSize = 4;
constexpr unsigned int kVMProjZBinSize = MEBinsBits+1;
constexpr unsigned int kVMProjIndexSize = 7;
// Bit size for full VMProjectionMemory
constexpr unsigned int kVMProjectionSize = kVMProjRinvSize + kVMProjFineZSize + kVMProjZBinSize + kVMProjIndexSize + 1;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the VMProjectionMemory word for different fields
constexpr unsigned int kVMProjIsPSSeedLSB = 0;
constexpr unsigned int kVMProjRinvLSB = 1;
constexpr unsigned int kVMProjRinvMSB = kVMProjRinvLSB + kVMProjRinvSize - 1;
constexpr unsigned int kVMProjFineZLSB = kVMProjRinvMSB + 1;
constexpr unsigned int kVMProjFineZMSB = kVMProjFineZLSB + kVMProjFineZSize - 1;
constexpr unsigned int kVMProjZBinLSB = kVMProjFineZMSB + 1;
constexpr unsigned int kVMProjZBinMSB = kVMProjZBinLSB + kVMProjZBinSize - 1;
constexpr unsigned int kVMProjIndexLSB = kVMProjZBinMSB + 1;
constexpr unsigned int kVMProjIndexMSB = kVMProjIndexLSB + kVMProjIndexSize - 1;

// Data object definition
class VMProjection
{
public:
  
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
