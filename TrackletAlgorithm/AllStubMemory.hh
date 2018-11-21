#ifndef ALLSTUBMEMORY_HH
#define ALLSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for AllStubMemory fields
constexpr unsigned int kASBendSize = 3;
constexpr unsigned int kASPhiSize = 14;
constexpr unsigned int kASZSize = 12;
constexpr unsigned int kASRSize = 7;
// Bit size for full AllStubMemory
constexpr unsigned int kAllStubSize = kASBendSize + kASPhiSize + kASZSize + kASRSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the AllStubMemory word for different fields
constexpr unsigned int kASBendLSB = 0;
constexpr unsigned int kASBendMSB = kASBendLSB + kASBendSize - 1;
constexpr unsigned int kASPhiLSB = kASBendMSB + 1;
constexpr unsigned int kASPhiMSB = kASPhiLSB + kASPhiSize - 1;
constexpr unsigned int kASZLSB = kASPhiMSB + 1;
constexpr unsigned int kASZMSB = kASZLSB + kASZSize - 1;
constexpr unsigned int kASRLSB = kASZMSB + 1;
constexpr unsigned int kASRMSB = kASRLSB + kASRSize - 1;

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

  // Getter
  AllStubData raw() const {return data_; }

  ASR GetR() const {
    return data_.range(kASRMSB,kASRLSB);
  }

  ASZ GetZ() const {
    return data_.range(kASZMSB,kASZLSB);
  }

  ASPHI GetPhi() const {
    return data_.range(kASPhiMSB,kASPhiLSB);
  }

  ASBEND GetBend() const {
    return data_.range(kASBendMSB,kASBendLSB);
  }

  // Setter
  void SetR(const ASR r) {
    data_.range(kASRMSB,kASRLSB) = r;
  }

  void SetZ(const ASZ z) {
    data_.range(kSZMSB,kASZLSB) = z;
  }

  void SetPhi(const ASPHI phi) {
    data_.range(kASPhiMSB,kASPhiLSB) = phi;
  }

  void SetBend(const ASBEND bend) {
    data_.range(kASBendMSB,kASBendLSB) = bend;
  }

private:

  AllStubData data_;

};

// Memory definition
typedef MemoryTemplate<AllStub, 3, kNBits_MemAddr> AllStubMemory;


#endif
