#ifndef TRACKLETPARAMETERMEMORY_HH
#define TRACKLETPARAMETERMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class TrackletParameters
{
public:

  typedef ap_int<kRinvSize> RINVPAR;
  typedef ap_uint<kPhi0Size> PHI0PAR;
  typedef ap_int<kZ0Size> Z0PAR;
  typedef ap_int<kTSize> TPAR;
  typedef ap_uint<kNBits_MemAddr> STUBINDEX;
	
  typedef ap_uint<kTrackletParameterSize> TrackletParameterData;
	
  // Constructors
  TrackletParameters(const TrackletParameterData& newdata):
    data_(newdata)
  {}
  
  TrackletParameters(STUBINDEX id1, STUBINDEX id2, TPAR t, Z0PAR z0, PHI0PAR phi0, RINVPAR rinv):
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
    return data_.range(kStubIndexOuterLSB+kNBits_MemAddr-1,kStubIndexOuterLSB);
  }

  STUBINDEX GetStubIndexInner() const {
    return data_.range(kStubIndexInnerLSB+kNBits_MemAddr-1,kStubIndexInnerLSB);
  }

  TPAR GetT() const {
    return data_.range(kTLSB+kTSize-1,kTLSB);
  }

  Z0PAR GetZ0() const {
    return data_.range(kZ0LSB+kZ0Size-1,kZ0LSB);
  }

  PHI0PAR GetPhi0() const {
    return data_.range(kPhi0LSB+kPhi0Size-1,kPhi0LSB);
  }

  RINVPAR GetRinv() const {
    return data_.range(kRinvLSB+kRinvSize-1,kRinvLSB);
  }
  
  // Setter
  void SetStubIndexInner(const STUBINDEX id) {
    data_.range(kStubIndexInnerLSB+kNBits_MemAddr-1,kStubIndexInnerLSB) = id;
  }

  void SetStubIndexOuter(const STUBINDEX id) {
    data_.range(kStubIndexOuterLSB+kNBits_MemAddr-1,kStubIndexOuterLSB) = id;
  }
  
  void SetT(const TPAR t) {
    data_.range(kTLSB+kTSize-1,kTLSB) = t;
  }
  
  void SetZ0(const Z0PAR z0) {
    data_.range(kZ0LSB+kZ0Size-1,kZ0LSB) = z0;
  }

  void SetPhi0(const PHI0PAR phi0) {
    data_.range(kPhi0LSB+kPhi0Size-1,kPhi0LSB) = phi0;
  }
  
  void SetRinv(const RINVPAR rinv) {
    data_.range(kRinvLSB+kRinvSize-1,kRinvLSB) = rinv;
  }
  
private:
  
  TrackletParameterData data_;
  
};

// Memory definition
typedef MemoryTemplate<TrackletParameters, 2, kNBits_MemAddr> TrackletParameterMemory;


#endif
