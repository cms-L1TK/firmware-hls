#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

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
  
  VMProjection(const char* datastr, int base=16)
  {
    VMProjData newdata(datastr, base);
    data_ = newdata;
  }
  
  // copy constructor
  VMProjection(const VMProjection& rhs):
    data_(rhs.raw())
  {}
  
  // Getter
  VMProjData raw() const {return data_;}
  
  VMPID GetIndex() const {
    return data_.range(kVMProjIndexLSB+kVMProjIndexSize-1,kVMProjIndexLSB);
  }

  VMPZBIN GetZBin() const {
    return data_.range(kVMProjZbinLSB+kVMProjZbinSize-1,kVMProjZbinLSB);
  }

  VMPFINEZ GetFineZ() const {
    return data_.range(kVMProjFineZLSB+kVMProjFineZSize-1,kVMProjFineZLSB);
  }
  
  VMPRINV GetRInv() const {
    return data_.range(kVMProjRinvLSB+kVMProjRinvSize-1,kVMProjRinvLSB);
  }

  bool GetIsPSSeed() const {
    return data_.range(0,0);
  }
  
  // Setter
  void SetIndex(const VMPID id) {
    data_.range(kVMProjIndexLSB+kVMProjIndexSize-1,kVMProjIndexLSB) = id;
  }
  
  void SetZBin(const VMPZBIN zbin) {
    data_.range(kVMProjZbinLSB+kVMProjZbinSize-1,kVMProjZbinLSB) = zbin;
  }
  
  void SetFineZ(const VMPFINEZ finez) {
    data_.range(kVMProjFineZLSB+kVMProjFineZSize-1,kVMProjFineZLSB) = finez;
  }
  
  void SetRInv(const VMPRINV rinv) {
    data_.range(kVMProjRinvLSB+kVMProjRinvSize-1,kVMProjRinvLSB) = rinv;
  }
  
  void SetIsPSSeed(const bool psseed) {
    data_.range(0,0) = psseed;
  }
  
private:
  
  VMProjData data_;
  
};

// Memory definition
typedef MemoryTemplate<VMProjection, 1, kNBits_MemAddr> VMProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
