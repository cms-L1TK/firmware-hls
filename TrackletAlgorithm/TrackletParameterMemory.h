#ifndef TrackletAlgorithm_TrackletParameterMemory_h
#define TrackletAlgorithm_TrackletParameterMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// Memory written by the TrackletProcessor, containing the helix parameters of the tracklet seed.

class TrackletParameters
{
public:

  enum BitWidths {
    // Bit sizes for TrackletParameterMemory fields
    kTParRinvSize = 14, //rinv
    kTParPhi0Size = 18, //phi0
    kTParZ0Size = 10, //z0
    kTParTSize = 14, //t
    kTParPhiRegionSize = 3, //phi region size. Used for combined modules, set to zero for non-CM
    // Bit size for full TrackletParameterMemory
    kTrackletParameterSize = kTParRinvSize + kTParPhi0Size + kTParZ0Size + kTParTSize + 2*kNBits_MemAddr + kTParPhiRegionSize
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackletParameterMemory word for different fields
    kTParTLSB = 0,
    kTParTMSB = kTParTLSB + kTParTSize - 1,
    kTParZ0LSB = kTParTMSB + 1,
    kTParZ0MSB = kTParZ0LSB + kTParZ0Size - 1,
    kTParPhi0LSB = kTParZ0MSB + 1,
    kTParPhi0MSB = kTParPhi0LSB + kTParPhi0Size - 1,
    kTParRinvLSB = kTParPhi0MSB + 1,
    kTParRinvMSB = kTParRinvLSB + kTParRinvSize - 1,
    kTParStubIndexOuterLSB = kTParRinvMSB + 1,
    kTParStubIndexOuterMSB = kTParStubIndexOuterLSB + kNBits_MemAddr - 1,
    kTParStubIndexInnerLSB = kTParStubIndexOuterMSB + 1,
    kTParStubIndexInnerMSB = kTParStubIndexInnerLSB + kNBits_MemAddr - 1,
    kTParPhiRegionLSB = kTParStubIndexInnerMSB + 1,
    kTParPhiRegionMSB = kTParPhiRegionLSB + kTParPhiRegionSize - 1
  };

  typedef ap_uint<kTParPhiRegionSize> PHIREGION;
  typedef ap_uint<kNBits_MemAddr> STUBINDEX;
  typedef ap_int<kTParTSize> TPAR;
  typedef ap_int<kTParZ0Size> Z0PAR;
  typedef ap_uint<kTParPhi0Size> PHI0PAR;
  typedef ap_int<kTParRinvSize> RINVPAR;
  
  typedef ap_uint<kTrackletParameterSize> TrackletParameterData;
	
  // Constructors
  TrackletParameters(const TrackletParameterData& newdata):
    data_(newdata)
  {}

  TrackletParameters(const STUBINDEX id1, const STUBINDEX id2, const RINVPAR rinv, const PHI0PAR phi0, const Z0PAR z0, const TPAR t):
    data_( (((((id1,id2),rinv),phi0),z0),t) )
  {}

 TrackletParameters(const PHIREGION phireg, const STUBINDEX id1, const STUBINDEX id2, const RINVPAR rinv, const PHI0PAR phi0, const Z0PAR z0, const TPAR t):
    data_( ((((((phireg,id1),id2),rinv),phi0),z0),t) )
  {}
  
  TrackletParameters()
  {}

  #ifndef __SYNTHESIS__
  TrackletParameters(const char* datastr, int base=16)
  {
    TrackletParameterData newdata(datastr, base);
    data_ = newdata;
  }
  #endif
  
  // Getter
  static constexpr int getWidth() {return kTrackletParameterSize;}

  TrackletParameterData raw() const {return data_;}

  PHIREGION getPhiRegion() const {
    return data_.range(kTParPhiRegionMSB,kTParPhiRegionLSB);
  }

  STUBINDEX getStubIndexOuter() const {
    return data_.range(kTParStubIndexOuterMSB,kTParStubIndexOuterLSB);
  }

  STUBINDEX getStubIndexInner() const {
    return data_.range(kTParStubIndexInnerMSB,kTParStubIndexInnerLSB);
  }

  TPAR getT() const {
    return data_.range(kTParTMSB,kTParTLSB);
  }

  Z0PAR getZ0() const {
    return data_.range(kTParZ0MSB,kTParZ0LSB);
  }

  PHI0PAR getPhi0() const {
    return data_.range(kTParPhi0MSB,kTParPhi0LSB);
  }

  RINVPAR getRinv() const {
    return data_.range(kTParRinvMSB,kTParRinvLSB);
  }
  
  // Setter
  void setPhiRegion(const PHIREGION phiregion) {
    data_.range(kTParPhiRegionMSB,kTParPhiRegionLSB) = phiregion;
  }

  void setStubIndexInner(const STUBINDEX id) {
    data_.range(kTParStubIndexInnerMSB,kTParStubIndexInnerLSB) = id;
  }

  void setStubIndexOuter(const STUBINDEX id) {
    data_.range(kTParStubIndexOuterMSB,kTParStubIndexOuterLSB) = id;
  }
  
  void setT(const TPAR t) {
    data_.range(kTParTMSB,kTParTLSB) = t;
  }
  
  void setZ0(const Z0PAR z0) {
    data_.range(kTParZ0MSB,kTParZ0LSB) = z0;
  }

  void setPhi0(const PHI0PAR phi0) {
    data_.range(kTParPhi0MSB,kTParPhi0LSB) = phi0;
  }
  
  void setRinv(const RINVPAR rinv) {
    data_.range(kTParRinvMSB,kTParRinvLSB) = rinv;
  }
  
private:
  
  TrackletParameterData data_;
  
};

// Memory definition
typedef MemoryTemplate<TrackletParameters, 3, kNBits_MemAddr> TrackletParameterMemory;

#endif
