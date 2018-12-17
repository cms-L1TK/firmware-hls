#ifndef VMSTUBTEINNERMEMORY_HH
#define VMSTUBTEINNERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class VMStubTEInner
{
public:

  enum BitWidths {
    // Bit sizes for VMStubTEInnerMemory fields
    kVMSTEIZBitsSize = 10,
    kVMSTEIFinePhiSize = 2,
    kVMSTEIBendSize = 3,
    kVMSTEIIDSize = 7,
    // Bit size for full VMStubTEInnerMemory
    kVMStubTEInnerSize = kVMSTEIZBitsSize + kVMSTEIFinePhiSize + kVMSTEIBendSize + kVMSTEIIDSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubTEInnerMemory word for different fields
    kVMSTEIZBitsLSB = 0,
    kVMSTEIZBitsMSB = kVMSTEIZBitsLSB + kVMSTEIZBitsSize - 1,
    kVMSTEIFinePhiLSB = kVMSTEIZBitsMSB + 1,
    kVMSTEIFinePhiMSB = kVMSTEIFinePhiLSB + kVMSTEIFinePhiSize - 1,
    kVMSTEIBendLSB = kVMSTEIFinePhiMSB + 1,
    kVMSTEIBendMSB = kVMSTEIBendLSB + kVMSTEIBendSize - 1,
    kVMSTEIIDLSB = kVMSTEIBendMSB + 1,
    kVMSTEIIDMSB = kVMSTEIIDLSB + kVMSTEIIDSize - 1
  };

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
