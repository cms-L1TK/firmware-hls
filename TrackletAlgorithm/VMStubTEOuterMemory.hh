#ifndef VMSTUBTEOUTERMEMORY_HH
#define VMSTUBTEOUTERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplateBinned.hh"

// Bit sizes for VMStubTEOuterMemory fields
constexpr unsigned int kVMSTEOFineZSize = 3;
constexpr unsigned int kVMSTEOFinePhiSize = 3;
constexpr unsigned int kVMSTEOBendSize = 3;
constexpr unsigned int kVMSTEOIDSize = 7;
// Bit size for full VMStubTEOuterMemory
constexpr unsigned int kVMStubTEOuterSize = kVMSTEOFineZSize + kVMSTEOFinePhiSize + kVMSTEOBendSize + kVMSTEOIDSize;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the VMStubTEOuterMemory word for different fields
constexpr unsigned int kVMSTEOFineZLSB = 0;
constexpr unsigned int kVMSTEOFineZMSB = kVMSTEOFineZLSB + kVMSTEOFineZSize - 1;
constexpr unsigned int kVMSTEOFinePhiLSB = kVMSTEOFineZMSB + 1;
constexpr unsigned int kVMSTEOFinePhiMSB = kVMSTEOFinePhiLSB + kVMSTEOFinePhiSize - 1;
constexpr unsigned int kVMSTEOBendLSB = kVMSTEOFinePhiMSB + 1;
constexpr unsigned int kVMSTEOBendMSB = kVMSTEOBendLSB + kVMSTEOBendSize - 1;
constexpr unsigned int kVMSTEOIDLSB = kVMSTEOBendMSB + 1;
constexpr unsigned int kVMSTEOIDMSB = kVMSTEOIDLSB + kVMSTEOIDSize - 1;

// Data object definition
class VMStubTEOuter
{
public:

  typedef ap_uint<kVMSTEOIDSize> VMSTEOID;
  typedef ap_uint<kVMSTEOBendSize> VMSTEOBEND;
  typedef ap_uint<kVMSTEOFinePhiSize> VMSTEOFINEPHI;
  typedef ap_uint<kVMSTEOFineZSize> VMSTEOFINEZ;

  typedef ap_uint<kVMStubTEOuterSize> VMStubTEOuterData;

  // Constructors
  VMStubTEOuter(const VMStubTEOuterData& newdata):
    data_(newdata)
  {}

  VMStubTEOuter(const VMSTEOID id, const VMSTEOBEND bend, const VMSTEOFINEPHI finephi, const VMSTEOFINEZ finez):
    data_( (((id,bend),finephi),finez) )
  {}

  VMStubTEOuter():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  VMStubTEOuter(const char* datastr, int base=16)
  {
    VMStubTEOuterData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  VMStubTEOuterData raw() const {return data_;}

  VMSTEOID getIndex() const {
    return data_.range(kVMSTEOIDMSB,kVMSTEOIDLSB);
  }

  VMSTEOBEND getBend() const {
    return data_.range(kVMSTEOBendMSB,kVMSTEOBendLSB);
  }

  VMSTEOFINEPHI getFinePhi() const {
    return data_.range(kVMSTEOFinePhiMSB,kVMSTEOFinePhiLSB);
  }

  VMSTEOFINEZ getFineZ() const {
    return data_.range(kVMSTEOFineZMSB,kVMSTEOFineZLSB);
  }

  // Setter
  void setIndex(const VMSTEOID id) {
    data_.range(kVMSTEOIDMSB,kVMSTEOIDLSB) = id;
  }

  void setBend(const VMSTEOBEND bend) {
    data_.range(kVMSTEOBendMSB,kVMSTEOBendLSB) = bend;
  }

  void setFinePhi(const VMSTEOFINEPHI finephi) {
    data_.range(kVMSTEOFinePhiMSB,kVMSTEOFinePhiLSB) = finephi;
  }

  void setFineZ(const VMSTEOFINEZ finez) {
    data_.range(kVMSTEOFineZMSB,kVMSTEOFineZLSB) = finez;
  }

private:

  VMStubTEOuterData data_;

};

// Memory definition
typedef MemoryTemplateBinned<VMStubTEOuter, 2, kNBits_MemAddr, 3> VMStubTEOuterMemory;

#endif
