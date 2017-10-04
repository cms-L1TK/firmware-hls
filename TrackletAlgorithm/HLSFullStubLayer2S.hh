// This is the HLSFullStubLayer class, which contains, in essence the 36 bits of a full stub, with few other functions
#pragma once
#include <cstdio>
#include "ap_int.h"
#include "HLSConstants.hh"

//#define FAT_CLASS

class HLSFullStubLayer2S
{
private:
  StubData data_;
#ifdef FAT_CLASS
  FullZ_Layer_2S z;
  FullPhi_Layer_2S phi;
  FullR_Layer_2S r;
  FullPt_Layer_2S pt;
#endif // FAT_CLASS
public:
  HLSFullStubLayer2S(StubData newdata):
    data_(newdata)
  {}
  HLSFullStubLayer2S():
    data_(0)
  {
  }
  StubData raw() const
  {
    return data_;
  }
  HLSFullStubLayer2S(const FullZ_Layer_2S newZ, const FullPhi_Layer_2S newPhi,
		     const FullR_Layer_2S newR, const FullPt_Layer_2S newPt)
  {
    AddStub(newZ, newPhi, newR, newPt);
  }
  void AddStub(const StubData newStub)
  {
	data_ = newStub;
  }
  void AddStub(const FullZ_Layer_2S newZ, const FullPhi_Layer_2S newPhi,
	       const FullR_Layer_2S newR, const FullPt_Layer_2S newPt)
  {
#ifdef FAT_CLASS
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
#endif // FAT_CLASS
    // without the to_long these variables truncate at their current bit width.
    data_ = newZ | (newPhi.to_long()<<8) | (newR.to_long()<<(17+8)) | (newPt.to_long()<<(17+8+8));
//    printf("data_ is %09lx, %09lx\n", data_.to_long(),(newPhi.to_long()<<12));
  }
  FullZ_Layer_2S GetZ() const
  {
    FullZ_Layer_2S tz = (data_&0xFFUL);
#ifdef FAT_CLASS
    if ( tz != z ) {
      printf("tz = 0x%03x, z = 0x%03lx\n", tz.to_int(), z.to_int());
    }
#endif // FAT_CLASS
    return tz;
  }
  FullPhi_Layer_2S GetPhi()  const
  {
    FullPhi_Layer_2S tPhi = (data_>>8)& 0x1FFFFUL;
#ifdef FAT_CLASS
    if ( tPhi != phi ) {
      printf("tphi = 0x%03x, phi = 0x%03lx\n", tPhi.to_int(), phi.to_int());
    }
#endif // FAT_CLASS
    return tPhi;
  }
  FullR_Layer_2S GetR()  const
  {
    FullR_Layer_2S tR = (data_>> (8+17))&0xFFUL;
#ifdef FAT_CLASS
    if ( tR != r ) {
      printf("tr = 0x%03x, r = 0x%03lx\n", tR.to_int(), r.to_int());
    }
#endif // FAT_CLASS
    return tR;
  }
  FullPt_Layer_2S GetPt()  const
  {
    FullPt_Layer_2S tPt = (data_ >> (8+17+8)) & 0x7UL;
#ifdef FAT_CLASS
    if ( tPt != pt ) {
      printf("tpt = 0x%03x, pt = 0x%03lx\n", tPt.to_int(), pt.to_int());
    }
#endif // FAT_CLASS
    return tPt;
    //return pt;
  }
  // --------------------------------------------------
  // NOTA BENE -- THESE SETTERS HAVE NOT BEEN DEBUGGED
  // --------------------------------------------------
  void SetZ(const FullZ_Layer_2S newZ)
  {
    // 36 bit mask: 0x3FFFFFFFFU
    const long int maskZ = 0xFFFFFFF00UL; // bottom 8 bits
    const int zShift = 0;
    data_ = (data_ & maskZ) | (newZ.to_long() << zShift);
//    z = newZ;
  }
  void SetPhi(const FullPhi_Layer_2S newPhi)
  {
    const long int maskPhi = 0xFFE0000FFUL; // 17 bits, shifted up 8 bits
    const int phiShift = 8;
    data_ = ( data_ & maskPhi) | ( newPhi.to_long() << phiShift);
//    phi = newPhi;
  }
  void SetR(const FullR_Layer_2S newR)
  {
//    r = newR;
    const long int maskR = 0xE01FFFFFFUL;
    const int rShift = 8+17;
    data_ = (data_ & maskR ) | ( newR.to_long() << rShift);
  }
  void SetPt(const FullPt_Layer_2S newPt)
  {
    const long int maskPt = 0x1FFFFFFFFUL;
    const int ptShift = 8+17+8;
    data_ = (data_ & maskPt ) | ( newPt.to_long() << ptShift);
//    pt = newPt;
  }
};

#ifdef FAT_CLASS
#undef FAT_CLASS
#endif

