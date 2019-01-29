#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// VMProjectionBase is where we define the bit widths, which depend on the class template parameter.
template<regionType VMProjType> class VMProjectionBase {};

template<>
class VMProjectionBase<BARREL>
{
public:
  enum BitWidths {
    // Bit sizes for VMProjectionMemory fields
    kVMProjIsPSSeedSize = 1,
    kVMProjRinvSize = 5,
    kVMProjFineZSize = 4,
    kVMProjZBinSize = MEBinsBits+1,
    kVMProjIndexSize = 7,
    // Bit size for full VMProjectionMemory
    kVMProjectionSize = kVMProjRinvSize + kVMProjFineZSize + kVMProjZBinSize + kVMProjIndexSize
  };
};

template<>
class VMProjectionBase<DISK>
{
public:
  enum BitWidths {
    // Bit sizes for VMProjectionMemory fields
    kVMProjIsPSSeedSize = 0,
    kVMProjRinvSize = 5,
    kVMProjFineZSize = 4,
    kVMProjZBinSize = MEBinsBits+1+1,
    kVMProjIndexSize = 7,
    // Bit size for full VMProjectionMemory
    kVMProjectionSize = kVMProjRinvSize + kVMProjFineZSize + kVMProjZBinSize + kVMProjIndexSize
  };
};


// Data object definition
template<regionType VMProjType>
class VMProjection : public VMProjectionBase<VMProjType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMProjectionMemory word for different fields
    kVMProjIsPSSeedLSB = 0,
    kVMProjIsPSSeedMSB = kVMProjIsPSSeedLSB + VMProjectionBase<VMProjType>::kVMProjIsPSSeedSize - 1,
    
    kVMProjRinvLSB = kVMProjIsPSSeedMSB + 1,
    kVMProjRinvMSB = kVMProjRinvLSB + VMProjectionBase<VMProjType>::kVMProjRinvSize - 1,
    kVMProjFineZLSB = kVMProjRinvMSB + 1,
    kVMProjFineZMSB = kVMProjFineZLSB + VMProjectionBase<VMProjType>::kVMProjFineZSize - 1,
    kVMProjZBinLSB = kVMProjFineZMSB + 1,
    kVMProjZBinMSB = kVMProjZBinLSB + VMProjectionBase<VMProjType>::kVMProjZBinSize - 1,
    kVMProjIndexLSB = kVMProjZBinMSB + 1,
    kVMProjIndexMSB = kVMProjIndexLSB + VMProjectionBase<VMProjType>::kVMProjIndexSize - 1
  };
  
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjIndexSize> VMPID;
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjZBinSize> VMPZBIN;
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjFineZSize> VMPFINEZ;
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjRinvSize> VMPRINV;
	
  typedef ap_uint<VMProjectionBase<VMProjType>::kVMProjectionSize> VMProjData;

  // Constructors
  VMProjection(const VMProjData& newdata):
    data_(newdata)
  {}

  VMProjection(const VMPID id, const VMPZBIN zbin, const VMPFINEZ finez, const VMPRINV rinv, const bool ps):
    data_( ((((id,zbin),finez),rinv),ps) )
  {}

  VMProjection(const VMPID id, const VMPZBIN zbin, const VMPFINEZ finez, const VMPRINV rinv):
    data_( (((id,zbin),finez),rinv) )
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
    return data_.range(kVMProjIsPSSeedLSB,kVMProjIsPSSeedMSB);
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
    data_.range(kVMProjIsPSSeedLSB,kVMProjIsPSSeedMSB) = psseed;
  }
  
private:
  
  VMProjData data_;
  
};

// Memory definition
template<regionType VMProjType> using VMProjectionMemory = MemoryTemplate<VMProjection<VMProjType>, 1, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
