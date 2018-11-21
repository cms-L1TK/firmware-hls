#ifndef TRACKLETPARAMETERMEMORY_HH
#define TRACKLETPARAMETERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit sizes for TrackletParameterMemory fields
constexpr unsigned int kTParRinvSize = 14; //rinv
constexpr unsigned int kTParPhi0Size = 17; //phi0
constexpr unsigned int kTParZ0Size = 12; //z0
constexpr unsigned int kTParTSize = 14; //t
// Bit size for full TrackletParameterMemory
constexpr unsigned int kTrackletParameterSize = kTParRinvSize + kTParPhi0Size + kTParZ0Size + kTParTSize + 2*kNBits_MemAddr;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackletParameterMemory word for different fields
constexpr unsigned int kTParRinvLSB = 0;
constexpr unsigned int kTParRinvMSB = kTParRinvLSB + kTParRinvSize - 1;
constexpr unsigned int kTParPhi0LSB = kTParRinvMSB + 1;
constexpr unsigned int kTParPhi0MSB = kTParPhi0LSB + kTParPhi0Size - 1;
constexpr unsigned int kTParZ0LSB = kTParPhi0MSB + 1;
constexpr unsigned int kTParZ0MSB = kTParZ0LSB + kTParZ0Size - 1;
constexpr unsigned int kTParTLSB = kTParZ0MSB + 1;
constexpr unsigned int kTParTMSB = kTParTLSB + kTParTSize - 1;
constexpr unsigned int kTParStubIndexInnerLSB = kTParTLSB + 1;
constexpr unsigned int kTParStubIndexInnerMSB = kTParStubIndexInnerLSB + kNBits_MemAddr - 1;
constexpr unsigned int kTParStubIndexOuterLSB = kTParStubIndexInnerMSB + 1;
constexpr unsigned int kTParStubIndexOuterMSB = kTParStubIndexOuterLSB + kNBits_MemAddr - 1;

// Data object definition
class TrackletParameters
{
public:

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
  
  TrackletParameters(const STUBINDEX id1, const STUBINDEX id2, const TPAR t, const Z0PAR z0, const PHI0PAR phi0, const RINVPAR rinv):
    data_( (((((id1,id2),t),z0),phi0), rinv ) )
  {}
  
  TrackletParameters():
    data_(0)
  {}
  
  TrackletParameters(const char* datastr, int base=16)
  {
    TrackletParameterData newdata(datastr, base);
    data_ = newdata;
  }
  
  // Getter
  TrackletParameterData raw() const {return data_;}

  STUBINDEX GetStubIndexOuter() const {
    return data_.range(kTParStubIndexOuterMSB,kTParStubIndexOuterLSB);
  }

  STUBINDEX GetStubIndexInner() const {
    return data_.range(kTParStubIndexInnerMSB,kTParStubIndexInnerLSB);
  }

  TPAR GetT() const {
    return data_.range(kTParTMSB,kTParTLSB);
  }

  Z0PAR GetZ0() const {
    return data_.range(kTParZ0MSB,kTParZ0LSB);
  }

  PHI0PAR GetPhi0() const {
    return data_.range(kTParPhi0MSB,kTParPhi0LSB);
  }

  RINVPAR GetRinv() const {
    return data_.range(kTParRinvMSB,kTParRinvLSB);
  }
  
  // Setter
  void SetStubIndexInner(const STUBINDEX id) {
    data_.range(kTParStubIndexInnerMSB,kTParStubIndexInnerLSB) = id;
  }

  void SetStubIndexOuter(const STUBINDEX id) {
    data_.range(kTParStubIndexOuterMSB,kTParStubIndexOuterLSB) = id;
  }
  
  void SetT(const TPAR t) {
    data_.range(kTParTMSB,kTParTLSB) = t;
  }
  
  void SetZ0(const Z0PAR z0) {
    data_.range(kTParZ0MSB,kTParZ0LSB) = z0;
  }

  void SetPhi0(const PHI0PAR phi0) {
    data_.range(kTParPhi0MSB,kTParPhi0LSB) = phi0;
  }
  
  void SetRinv(const RINVPAR rinv) {
    data_.range(kTParRinvMSB,kTParRinvLSB) = rinv;
  }
  
private:
  
  TrackletParameterData data_;
  
};

// Memory definition
typedef MemoryTemplate<TrackletParameters, 2, kNBits_MemAddr> TrackletParameterMemory;


#endif
