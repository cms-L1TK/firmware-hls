#ifndef VMSTUBTEINNERMEMORY_HH
#define VMSTUBTEINNERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit sizes for VMStubTEInnerMemory fields
constexpr unsigned int kVMSTEIZBitsSize = 10;
constexpr unsigned int kVMSTEIFinePhiSize = 2;
constexpr unsigned int kVMSTEIBendSize = 3;
constexpr unsigned int kVMSTEIIDSize = 7;
// Bit size for full VMStubTEInnerMemory
constexpr unsigned int kVMStubTEInnerSize = kVMSTEIZBitsSize + kVMSTEIFinePhiSize + kVMSTEIBendSize + kVMSTEIIDSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubTEInnerMemory word for different fields
constexpr unsigned int kVMSTEIZBitsLSB = 0;
constexpr unsigned int kVMSTEIZBitsMSB = kVMSTEIZBitsLSB + kVMSTEIZBitsSize - 1;
constexpr unsigned int kVMSTEIFinePhiLSB = kVMSTEIZBitsMSB + 1;
constexpr unsigned int kVMSTEIFinePhiMSB = kVMSTEIFinePhiLSB + kVMSTEIFinePhiSize - 1;
constexpr unsigned int kVMSTEIBendLSB = kVMSTEIFinePhiMSB + 1;
constexpr unsigned int kVMSTEIBendMSB = kVMSTEIBendLSB + kVMSTEIBendSize - 1;
constexpr unsigned int kVMSTEIIDLSB = kVMSTEIBendMSB + 1;
constexpr unsigned int kVMSTEIIDMSB = kVMSTEIIDLSB + kVMSTEIIDSize - 1;

// Data object definition
class VMStubTEInner
{
public:

  typedef ap_uint<kVMSTEIIDSize> VMSTEIID;
  typedef ap_uint<kVMSTEIBendSize> VMSTEIBEND;
  typedef ap_uint<kVMSTEIFinePhiSize> VMSTEIFINEPHI;
  typedef ap_uint<kVMSTEIZBitsSize> VMSTEIZBITS;

  typedef ap_uint<kVMStubTEInnerSize> VMStubTEInnerData;

  // Constructors
  VMStubTEInner(const VMStubTEInnerData& newdata):
    data_(newdata)
  {}

  VMStubTEInner(const VMSTEIID id, const VMSTEIBEND bend, const VMSTEIFINEPHI finephi, const VMSTEIZBITS zbits):
    data_( (((id,bend),finephi),zbits) )
  {}

  VMStubTEInner():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  VMStubTEInner(const char* datastr, int base=16)
  {
    VMStubTEInnerData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  VMStubTEInnerData raw() const {return data_;}

  VMSTEIID getIndex() const {
    return data_.range(kVMSTEIIDMSB,kVMSTEIIDLSB);
  }

  VMSTEIBEND getBend() const {
    return data_.range(kVMSTEIBendMSB,kVMSTEIBendLSB);
  }

  VMSTEIFINEPHI getFinePhi() const {
    return data_.range(kVMSTEIFinePhiMSB,kVMSTEIFinePhiLSB);
  }

  VMSTEIZBITS getZBits() const {
    return data_.range(kVMSTEIZBitsMSB,kVMSTEIZBitsLSB);
  }

  // Setter
  void setIndex(const VMSTEIID id) {
    data_.range(kVMSTEIIDMSB,kVMSTEIIDLSB) = id;
  }

  void setBend(const VMSTEIBEND bend) {
    data_.range(kVMSTEIBendMSB,kVMSTEIBendLSB) = bend;
  }

  void setFinePhi(const VMSTEIFINEPHI finephi) {
    data_.range(kVMSTEIFinePhiMSB,kVMSTEIFinePhiLSB) = finephi;
  }

  void setZBits(const VMSTEIZBITS zbits) {
    data_.range(kVMSTEIZBitsMSB,kVMSTEIZBitsLSB) = zbits;
  }

private:

  VMStubTEInnerData data_;

};

// Memory definition
typedef MemoryTemplate<VMStubTEInner, 1, kNBits_MemAddr> VMStubTEInnerMemory;

#endif
