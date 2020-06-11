#ifndef TrackletAlgorithm_AllProjectionMemory_h
#define TrackletAlgorithm_AllProjectionMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// AllProjectionBase is where we define the bit widths, which depend on the class template parameter.
template<int AProjType> class AllProjectionBase {};

template<>
class AllProjectionBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for AllProjectionMemory fields
    kAProjRZDSize = 10,
    kAProjPhiDSize = 10,
    kAProjRZSize = 12,
    kAProjPhiSize = 14,
    kAProjTrackletIndexSize = 7,
    kAProjTCSeedSize = 3,        // sub division of TCID
    kAProjTCVMSize = 4,          // sub division of TCID
    kAProjTCIDSize = 7,
    //Bit size for full AllProjectionMemory
    kAllProjectionSize = kAProjRZDSize + kAProjPhiDSize + kAProjRZSize + kAProjPhiSize + kAProjTrackletIndexSize + kAProjTCIDSize
  };
};

template<>
class AllProjectionBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for AllProjectionMemory fields
    kAProjRZDSize = 9,
    kAProjPhiDSize = 10,
    kAProjRZSize = 8,
    kAProjPhiSize = 17,
    kAProjTrackletIndexSize = 7,
    kAProjTCSeedSize = 3,        // sub division of TCID
    kAProjTCVMSize = 4,          // sub division of TCID
    kAProjTCIDSize = 7,
    //Bit size for full AllProjectionMemory
    kAllProjectionSize = kAProjRZDSize + kAProjPhiDSize + kAProjRZSize + kAProjPhiSize + kAProjTrackletIndexSize + kAProjTCIDSize
  };
};

template<>
class AllProjectionBase<DISK>
{
public:
  enum BitWidths {
    // Bit size for AllProjectionMemory fields
    kAProjRZDSize = 9,
    kAProjPhiDSize = 10,
    kAProjRZSize = 12,
    kAProjPhiSize = 14,
    kAProjTrackletIndexSize = 7,
    kAProjTCSeedSize = 3,        // sub division of TCID
    kAProjTCVMSize = 4,          // sub division of TCID
    kAProjTCIDSize = 7,
    //Bit size for full AllProjectionMemory
    kAllProjectionSize = kAProjRZDSize + kAProjPhiDSize + kAProjRZSize + kAProjPhiSize + kAProjTrackletIndexSize + kAProjTCIDSize
  };
};


// Data object definition
template<int AProjType>
class AllProjection : public AllProjectionBase<AProjType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllProjectionMemory word for different fields
    kAProjRZDLSB = 0,
    kAProjRZDMSB = kAProjRZDLSB + AllProjectionBase<AProjType>::kAProjRZDSize - 1,
    kAProjPhiDLSB = kAProjRZDMSB + 1,
    kAProjPhiDMSB = kAProjPhiDLSB + AllProjectionBase<AProjType>::kAProjPhiDSize - 1,
    kAProjRZLSB = kAProjPhiDMSB + 1,
    kAProjRZMSB = kAProjRZLSB + AllProjectionBase<AProjType>::kAProjRZSize - 1,
    kAProjPhiLSB = kAProjRZMSB + 1,
    kAProjPhiMSB = kAProjPhiLSB + AllProjectionBase<AProjType>::kAProjPhiSize - 1,
    kAProjTrackletIndexLSB = kAProjPhiMSB + 1,
    kAProjTrackletIndexMSB = kAProjTrackletIndexLSB + AllProjectionBase<AProjType>::kAProjTrackletIndexSize - 1,
    kAProjTCVMLSB = kAProjTrackletIndexMSB + 1,
    kAProjTCVMMSB = kAProjTCVMLSB + AllProjectionBase<AProjType>::kAProjTCVMSize - 1,
    kAProjTCSeedLSB = kAProjTCVMMSB + 1,
    kAProjTCSeedMSB = kAProjTCSeedLSB + AllProjectionBase<AProjType>::kAProjTCSeedSize - 1,
    kAProjTCIDLSB = kAProjTrackletIndexMSB + 1,
    kAProjTCIDMSB = kAProjTCIDLSB + AllProjectionBase<AProjType>::kAProjTCIDSize - 1
  };

  typedef ap_uint<AllProjectionBase<AProjType>::kAProjTCIDSize> AProjTCID;
  typedef ap_uint<AllProjectionBase<AProjType>::kAProjTCSeedSize> AProjTCSEED; // sub division of TCID
  typedef ap_uint<AllProjectionBase<AProjType>::kAProjTCVMSize> AProjTCVM;     // sub division of TCID
  typedef ap_uint<AllProjectionBase<AProjType>::kAProjTrackletIndexSize> AProjTrackletIndex;
  typedef ap_uint<AllProjectionBase<AProjType>::kAProjPhiSize> AProjPHI;
  typedef ap_int<AllProjectionBase<AProjType>::kAProjRZSize> AProjRZ;
  typedef ap_int<AllProjectionBase<AProjType>::kAProjPhiDSize> AProjPHIDER;
  typedef ap_int<AllProjectionBase<AProjType>::kAProjRZDSize> AProjRZDER;
  
  typedef ap_uint<AllProjectionBase<AProjType>::kAllProjectionSize> AllProjectionData;
  
  // Constructors
  AllProjection(const AllProjectionData& newdata):
    data_(newdata)
  {}

  AllProjection(const AProjTCID tcid, const AProjTrackletIndex trackletindex, const AProjPHI phi, const AProjRZ rz, const AProjPHIDER phider, const AProjRZDER rzder):
    data_( (((((tcid,trackletindex),phi),rz),phider),rzder) )
  {}
  
  AllProjection(const AProjTCSEED seed, const AProjTCVM vm, const AProjTrackletIndex trackletindex, const AProjPHI phi, const AProjRZ rz, const AProjPHIDER phider, const AProjRZDER rzder):
    data_( ((((((seed,vm),trackletindex),phi),rz),phider),rzder) )
  {}

  AllProjection():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  AllProjection(const char* datastr, int base=16)
  {
    AllProjectionData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return AllProjectionBase<AProjType>::kAllProjectionSize;}
  
  AllProjectionData raw() const {return data_;}
  
  AProjTCID getTCID() const {
    return data_.range(kAProjTCIDMSB,kAProjTCIDLSB);
  }

  AProjTCSEED getSeed() const {
	return data_.range(kAProjTCSeedMSB,kAProjTCSeedLSB);
  }
  
  AProjTCVM getVM() const {
	return data_.range(kAProjTCVMMSB,kAProjTCVMLSB);
  }

  AProjTrackletIndex getTrackletIndex() const {
	return data_.range(kAProjTrackletIndexMSB,kAProjTrackletIndexLSB);
  }

  AProjPHI getPhi() const {
    return data_.range(kAProjPhiMSB,kAProjPhiLSB);
  }
  
  AProjRZ getRZ() const {
    return data_.range(kAProjRZMSB,kAProjRZLSB);
  }
  
  AProjPHIDER getPhiDer() const { 
    return data_.range(kAProjPhiDMSB,kAProjPhiDLSB);
  }
  
  AProjRZDER getRZDer() const {
    return data_.range(kAProjRZDMSB,kAProjRZDLSB);
  }

  // Setter
  void setTCID(const AProjTCID id) {
    data_.range(kAProjTCIDMSB,kAProjTCIDLSB) = id;
  }

  void setSeed(const AProjTCSEED seed) {
	data_.range(kAProjTCSeedMSB,kAProjTCSeedLSB) = seed;
  }

  void setVM(const AProjTCVM vm) {
	data_.range(kAProjTCVMMSB,kAProjTCVMLSB) = vm;
  }

  void setTrackletIndex(const AProjTrackletIndex trackletindex) {
        data_.range(kAProjTrackletIndexMSB,kAProjTrackletIndexLSB) = trackletindex;
  }

  void setPhi(const AProjPHI phi) {
    data_.range(kAProjPhiMSB,kAProjPhiLSB) = phi;
  }

  void setRZ(const AProjRZ rz) {
    data_.range(kAProjRZMSB,kAProjRZLSB) = rz;
  }

  void setPhiDer(const AProjPHIDER phider) {
    data_.range(kAProjPhiDMSB,kAProjPhiDLSB) = phider;
  }

  void setRZDer(const AProjRZDER rzder) {
    data_.range(kAProjRZDMSB,kAProjRZDLSB) = rzder;
  }

private:

  AllProjectionData data_;
  
};

// Memory definition
template<int AProjType> using AllProjectionMemory = MemoryTemplate<AllProjection<AProjType>, 3, kNBits_MemAddr>;
// FIXME: double check number of bits for bx and for memory address

#endif
