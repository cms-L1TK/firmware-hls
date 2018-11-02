#ifndef TRACKLETPROJECTION_HH
#define TRACKLETPROJECTION_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"



// Data object definition
class TrackletProjection
{
public:
  
  typedef ap_uint<13> TProjTCID;
  typedef ap_uint<14> TProjPHI;
  typedef ap_int<12> TProjZ;
  typedef ap_int<11> TProjPHIDER;
  typedef ap_int<10> TProjZDER;
  
  typedef ap_uint<1+1+13+14+12+11+10> TProjData;

  // Constructors
  TrackletProjection(TProjData newdata):
    data_(newdata)
  {}

  TrackletProjection(bool plusneighbor, bool minusneighbor, TProjTCID tcid,
                     TProjPHI phi, TProjZ z, TProjPHIDER phider, TProjZDER zder):
    data_( ((((((plusneighbor,minusneighbor),tcid),phi),z),phider),zder) )
  {}
  
  TrackletProjection():
    data_(0)
  {}

  TrackletProjection(const char* datastr, int base = 16)
  {
    TProjData newdata(datastr, base);
    data_ = newdata;
  }
  
  // copy constructor
  TrackletProjection(const TrackletProjection& rhs):
    data_(rhs.raw())
  {}

  // Getter
  TProjData raw() const {return data_;}

  bool IsPlusNeighbor() const {return data_.range(61,61);}
  bool IsMinusNeighbor() const {return data_.range(60,60);}
  TProjTCID GetTrackletIndex() const {return data_.range(59,47);}
  TProjPHI GetPhi() const {return data_.range(46,33);}
  TProjZ GetZ() const {return data_.range(32,21);}
  TProjPHIDER GetPhiDer() {return data_.range(20,10);}
  TProjZDER GetZDer() {return data_.range(9,0);}

  // Setter
  void SetIsPlusNeighbor(bool isplusneighbor)
  {
    data_.range(61,61) = isplusneighbor;
  }

  void SetIsMinusNeighbor(bool isminusneighbor)
  {
    data_.range(60,60) = isminusneighbor;
  }

  void SetTrackletIndex(TProjTCID id)
  {
    data_.range(59,47) = id;
  }

  void SetPhi(TProjPHI phi)
  {
    data_.range(46,33) = phi;
  }

  void SetZ(TProjZ z)
  {
    data_.range(32,21) = z;
  }

  void SetPhiDer(TProjPHIDER phider)
  {
    data_.range(20,10) = phider;
  }

  void SetZDer(TProjZDER zder)
  {
    data_.range(9,0) = zder;
  }
  
private:
  
  TProjData data_;

};

// Memory definition
typedef MemoryTemplate<TrackletProjection, 1, kNBits_MemAddr> TrackletProjectionMemory;
// FIXME: double check number of bits for bx and for memory address

#endif
