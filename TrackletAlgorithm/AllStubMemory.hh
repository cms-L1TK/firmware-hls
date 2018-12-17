#ifndef ALLSTUBMEMORY_HH
#define ALLSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class AllStub
{
public:

  enum BitWidths {
    // Bit size for AllStubMemory fields
    kASBendSize = 3,
    kASPhiSize = 14,
    kASZSize = 12,
    kASRSize = 7,
    // Bit size for full AllStubMemory
    kAllStubSize = kASBendSize + kASPhiSize + kASZSize + kASRSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllStubMemory word for different fields
    kASBendLSB = 0,
    kASBendMSB = kASBendLSB + kASBendSize - 1,
    kASPhiLSB = kASBendMSB + 1,
    kASPhiMSB = kASPhiLSB + kASPhiSize - 1,
    kASZLSB = kASPhiMSB + 1,
    kASZMSB = kASZLSB + kASZSize - 1,
    kASRLSB = kASZMSB + 1,
    kASRMSB = kASRLSB + kASRSize - 1
  };
  
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

  #ifndef __SYNTHESIS__
  AllStub(const char* datastr, int base=16)
  {
    AllStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  AllStubData raw() const {return data_; }

  ASR getR() const {
    return data_.range(kASRMSB,kASRLSB);
  }

  ASZ getZ() const {
    return data_.range(kASZMSB,kASZLSB);
  }

  ASPHI getPhi() const {
    return data_.range(kASPhiMSB,kASPhiLSB);
  }

  ASBEND getBend() const {
    return data_.range(kASBendMSB,kASBendLSB);
  }

  // Setter
  void setR(const ASR r) {
    data_.range(kASRMSB,kASRLSB) = r;
  }

  void setZ(const ASZ z) {
    data_.range(kASZMSB,kASZLSB) = z;
  }

  void setPhi(const ASPHI phi) {
    data_.range(kASPhiMSB,kASPhiLSB) = phi;
  }

  void setBend(const ASBEND bend) {
    data_.range(kASBendMSB,kASBendLSB) = bend;
  }

private:

  AllStubData data_;

};

// Memory definition
typedef MemoryTemplate<AllStub, 3, kNBits_MemAddr> AllStubMemory;


#endif
