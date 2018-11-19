#ifndef TRACKLETPARAMETERMEMORY_HH
#define TRACKLETPARAMETERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

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
  
  // copy constructor
  TrackletParameters(const TrackletParameters& rhs):
    data_(rhs.raw())
  {}
  
  // Getter
  TrackletParameterData raw() const {return data_;}

  STUBINDEX GetStubIndexOuter() const {
    return data_.range(kTParStubIndexOuterLSB+kNBits_MemAddr-1,kTParStubIndexOuterLSB);
  }

  STUBINDEX GetStubIndexInner() const {
    return data_.range(kTParStubIndexInnerLSB+kNBits_MemAddr-1,kTParStubIndexInnerLSB);
  }

  TPAR GetT() const {
    return data_.range(kTParTLSB+kTParTSize-1,kTParTLSB);
  }

  Z0PAR GetZ0() const {
    return data_.range(kTParZ0LSB+kTParZ0Size-1,kTParZ0LSB);
  }

  PHI0PAR GetPhi0() const {
    return data_.range(kTParPhi0LSB+kTParPhi0Size-1,kTParPhi0LSB);
  }

  RINVPAR GetRinv() const {
    return data_.range(kTParRinvLSB+kTParRinvSize-1,kTParRinvLSB);
  }
  
  // Setter
  void SetStubIndexInner(const STUBINDEX id) {
    data_.range(kTParStubIndexInnerLSB+kNBits_MemAddr-1,kTParStubIndexInnerLSB) = id;
  }

  void SetStubIndexOuter(const STUBINDEX id) {
    data_.range(kTParStubIndexOuterLSB+kNBits_MemAddr-1,kTParStubIndexOuterLSB) = id;
  }
  
  void SetT(const TPAR t) {
    data_.range(kTParTLSB+kTParTSize-1,kTParTLSB) = t;
  }
  
  void SetZ0(const Z0PAR z0) {
    data_.range(kTParZ0LSB+kTParZ0Size-1,kTParZ0LSB) = z0;
  }

  void SetPhi0(const PHI0PAR phi0) {
    data_.range(kTParPhi0LSB+kTParPhi0Size-1,kTParPhi0LSB) = phi0;
  }
  
  void SetRinv(const RINVPAR rinv) {
    data_.range(kTParRinvLSB+kTParRinvSize-1,kTParRinvLSB) = rinv;
  }
  
private:
  
  TrackletParameterData data_;
  
};

// Memory definition
typedef MemoryTemplate<TrackletParameters, 2, kNBits_MemAddr> TrackletParameterMemory;


#endif
