#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class VMProjection
{
public:
  
  typedef ap_uint<7> VMPID;
  typedef ap_uint<MEBinsBits+1> VMPZBIN;
  typedef ap_uint<4> VMPFINEZ;
  typedef ap_uint<5> VMPRINV;
	
  typedef ap_uint<7+MEBinsBits+1+4+5+1> VMProjData;
	
  // Constructors
  VMProjection(VMProjData newdata):
    data_(newdata)
  {}
  
  VMProjection(VMPID id, VMPZBIN zbin, VMPFINEZ finez, VMPRINV rinv, bool ps):
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
  
  VMPID GetIndex() const {return data_.range(20,14);}
  VMPZBIN GetZBin() const {return data_.range(13,10);}
  VMPFINEZ GetFineZ() const {return data_.range(9,6);}
  VMPRINV GetRInv() const {return data_.range(5,1);}
  bool GetIsPSSeed() const {return data_.range(0,0);}
  
  // Setter
  void SetIndex(VMPID id)
  {
    data_.range(20,14) = id;
  }
  
  void SetZBin(VMPZBIN zbin)
  {
    data_.range(13,10) = zbin;
  }
  
  void SetFineZ(VMPFINEZ finez)
  {
    data_.range(9,6) = finez;
  }
  
  void SetRInv(VMPRINV rinv)
  {
    data_.range(5,1) = rinv;
  }
  
  void SetIsPSSeed(bool psseed)
  {
    data_.range(0,0) = psseed;
  }
  
private:
  
  VMProjData data_;
  
};

// Memory definition
typedef MemoryTemplate<VMProjection, 1, kNBits_MemAddr> VMProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
