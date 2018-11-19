#ifndef ALLSTUBMEMORY_HH
#define ALLSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class AllStub
{
public:

  typedef ap_uint<kASRSize> ASR;
  typedef ap_int<kASZSize> ASZ;
  typedef ap_uint<kASPhiSize> ASPHI;
  typedef ap_uint<kASBendSize> ASBEND;
  
  typedef ap_uint<kAllStubSize> AllStubData;

  // Constructors
  AllStub(const AllStubData& newdata):
    data_(newdata)
  {}

  AllStub(const ASR r, const ASZ z, const ASPHI phi, const ASBEND bend):
    data_( (((r,z),phi),bend) )
  {}

  AllStub():
    data_(0)
  {}

  AllStub(const char* datastr, int base=16)
  {
    AllStubData newdata(datastr, base);
    data_ = newdata;
  }

  // copy constructor
  AllStub(const AllStub& rhs):
    data_(rhs.raw())
  {}

  // Getter
  AllStubData raw() const {return data_; }

  ASR GetR() const {
    return data_.range(kASRLSB+kASRSize-1,kASRLSB);
  }

  ASZ GetZ() const {
    return data_.range(kASZLSB+kASZSize-1,kASZLSB);
  }

  ASPHI GetPhi() const {
    return data_.range(kASPhiLSB+kASPhiSize-1,kASPhiLSB);
  }

  ASBEND GetBend() const {
    return data_.range(kASBendLSB+kASBendSize-1,kASBendLSB);
  }

  // Setter
  void SetR(const ASR r) {
    data_.range(kASRLSB+kASRSize-1,kASRLSB) = r;
  }

  void SetZ(const ASZ z) {
    data_.range(kSZLSB+kASZSize-1,kASZLSB) = z;
  }

  void SetPhi(const ASPHI phi) {
    data_.range(kASPhiLSB+kASPhiSize-1,kASPhiLSB) = phi;
  }

  void SetBend(const ASBEND bend) {
    data_.range(kASBendLSB+kASBendSize-1,kASBendLSB) = bend;
  }

private:

  AllStubData data_;

};

// Memory definition
typedef MemoryTemplate<AllStub, 3, kNBits_MemAddr> AllStubMemory;


#endif
