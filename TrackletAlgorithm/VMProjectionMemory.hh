#ifndef VMPROJECTIONMEMORY_HH
#define VMPROJECTIONMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

constexpr int NBits_vmpid = 7;
constexpr int NBits_vmpzbin = MEBinsBits+1;
constexpr int NBits_vmpfinez = 4;
constexpr int NBits_vmprinv = 5;
constexpr int NBits_vmpdata =
  NBits_vmpid + NBits_vmpzbin + NBits_vmpfinez + NBits_vmprinv + 1;

// Data object definition
class VMProjection
{
public:
  

  typedef ap_uint<NBits_vmpid> VMPID;
  typedef ap_uint<NBits_vmpzbin> VMPZBIN;
  typedef ap_int<NBits_vmpfinez> VMPFINEZ;
  typedef ap_uint<NBits_vmprinv> VMPRINV;
	
  typedef ap_uint<NBits_vmpdata> VMProjData;
	
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
