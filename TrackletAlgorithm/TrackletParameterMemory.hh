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

	
  typedef ap_uint<kRinvSize+kPhi0Size+kZ0Size+kTSize+2*kNBits_MemAddr> TrackletParameterData;
	
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
    return data_.range(kStubIndexOuterStart+kNBits_MemAddr-1,kStubIndexOuterStart);
  }

  STUBINDEX GetStubIndexInner() const {
    return data_.range(kStubIndexInnerStart+kNBits_MemAddr-1,kStubIndexInnerStart);
  }

  TPAR GetT() const {
    return data_.range(kTStart+kTSize-1,kTStart);
  }

  Z0PAR GetZ0() const {
    return data_.range(kZ0Start+kZ0Size-1,kZ0Start);
  }

  PHI0PAR GetPhi0() const {
    return data_.range(kPhi0Start+kPhi0Size-1,kPhi0Start);
  }

  RINVPAR GetRinv() const {
    return data_.range(kRinvStart+kRinvSize-1,kRinvStart);
  }
  
  // Setter
  void SetStubIndexInner(const STUBINDEX id) {
    data_.range(kStubIndexInnerStart+kNBits_MemAddr-1,kStubIndexInnerStart) = id;
  }

  void SetStubIndexOuter(const STUBINDEX id) {
    data_.range(kStubIndexOuterStart+kNBits_MemAddr-1,kStubIndexOuterStart) = id;
  }
  
  void SetT(const TPAR t) {
    data_.range(kTStart+kTSize-1,kTStart) = t;
  }
  
  void SetZ0(const Z0PAR z0) {
    data_.range(kZ0Start+kZ0Size-1,kZ0Start) = z0;
  }

  void SetPhi0(const PHI0PAR phi0) {
    data_.range(kPhi0Start+kPhi0Size-1,kPhi0Start) = phi0;
  }
  
  void SetRinv(const RINVPAR rinv) {
    data_.range(kRinvStart+kRinvSize-1,kRinvStart) = rinv;
  }
  
private:
  
  TrackletParameterData data_;
  
};

// Memory definition
typedef MemoryTemplate<TrackletParameters, 2, kNBits_MemAddr> TrackletParameterMemory;


#endif
