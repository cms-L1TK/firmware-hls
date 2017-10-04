// This is the HLSReducedStubLayer class, which contains, in essence the 18 bits of a reduced stub, after it has been routed
#pragma once

//#define FAT_CLASS

#include "ap_int.h"
#include "HLSConstants.hh"
class HLSReducedStubLayer
{
private:
#ifdef FAT_CLASS
  ReducedZ_Layer z; // 4 bits
  ReducedPhi_Layer phi; // 3 bits
  ReducedR_Layer r; // 2 bits
  ReducedPt_Layer pt; // 3 bits
  ReducedIndex index; // 6 bits
#endif // FAT_CLASS
  ReducedStubData data_; // 18 bits
public:
  HLSReducedStubLayer():
    data_(0)
  {
#ifdef FAT_CLASS
    z = 0;
    phi = 0;
    r = 0;
    pt = 0;
    index = 0;
#endif // FAT_CLASS
  }
  // default copy constructor is ok

  void AddStub(ReducedZ_Layer newZ, ReducedPhi_Layer newPhi, ReducedR_Layer newR, ReducedPt_Layer newPt, ReducedIndex newIndex)
  {
#ifdef FAT_CLASS
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
    index = newIndex;
#endif // FAT_CLASS
    data_ = newZ | (newPhi.to_long()<< 4) | (newR.to_long() << (4+3)) |
      (newPt.to_long() << (4+3+2)) | (newIndex.to_long() << (4+3+2+3));
  }
  ReducedZ_Layer GetZ() const
  {
    ReducedZ_Layer tz = data_ & 0xFUL;
#ifdef FAT_CLASS
    if ( tz != z ) {
      printf("tz = 0x%03x, z = 0x%03lx\n", tz.to_int(), z.to_int());
    }
    tz = z;
#endif // FAT_CLASS
    return tz;
  }
  ReducedPhi_Layer GetPhi() const
  {
    ReducedPhi_Layer tphi = ( data_>> 4 ) & 0x7UL;
#ifdef FAT_CLASS
    if ( tphi != phi ) {
      printf("tphi = 0x%03x, phi = 0x%03lx\n", tphi.to_int(), phi.to_int());
    }
    tphi = phi;
#endif // FAT_CLASS
    return tphi;
  }
  ReducedR_Layer GetR() const
  {
    ReducedR_Layer tr = (data_ >> (4+3)) & 0x3UL;
#ifdef FAT_CLASS
    if ( tr != r ) {
      printf("tr = 0x%03x, r = 0x%03lx\n", tr.to_int(), r.to_int());
    }
    tr = r;
#endif // FAT_CLASS
    return tr;
  }
  ReducedPt_Layer GetPt() const
  {
    ReducedPt_Layer tpt = (data_ >> (4+3+2) ) & 0x7UL;
#ifdef FAT_CLASS
    if ( tpt != pt ) {
      printf("tpt = 0x%03x, pt = 0x%03lx\n", tpt.to_int(), pt.to_int());
    }
    tpt = pt;
#endif // FAT_CLASS
    return tpt;
  }
  ReducedIndex GetIndex() const
  {
    ReducedIndex tindex = ( data_ >> (4+3+2+3) ) & 0x3FUL;
#ifdef FAT_CLASS
    if ( tindex != index ) {
      printf("tpt = 0x%03x, pt = 0x%03lx\n", tindex.to_int(), index.to_int());
    }
    tindex = index;
#endif // FAT_CLASS
    return tindex;
  }
  // void SetZ(const ReducedZ_Layer newZ)
  // {
  //   z = newZ;
  // }
  // void SetPhi(const ReducedPhi_Layer newPhi)
  // {
  //   phi = newPhi;
  // }
  // void SetR(const ReducedR_Layer newR)
  // {
  //   r = newR;
  // }
  // void SetPt(const ReducedPt_Layer newPt)
  // {
  //   pt = newPt;
  // }
  // void SetIndex(const ReducedIndex newIndex)
  // {
  //   index = newIndex;
  // }
};


#ifdef FAT_CLASS
#undef FAT_CLASS
#endif

