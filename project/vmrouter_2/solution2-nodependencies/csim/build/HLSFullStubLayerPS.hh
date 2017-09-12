// This is the HLSFullStubLayer class, which contains, in essence the 36 bits of a full stub, with few other functions
//using namespace std;
#include <cstdio>
#pragma once
#include "ap_int.h"
#include "HLSConstants.hh"

//#define FAT_CLASS

class HLSFullStubLayerPS
{
private:
  StubData data_;
#ifdef FAT_CLASS
  FullZ_Layer_PS z;
  FullPhi_Layer_PS phi;
  FullR_Layer_PS r;
  FullPt_Layer_PS pt;
#endif // FAT_CLASS
public:
  HLSFullStubLayerPS(StubData newdata):
    data_(newdata)
  {}
  HLSFullStubLayerPS():
    data_(0)
  {
  }
  StubData raw() const
  {
    return data_;
  }
  HLSFullStubLayerPS(const FullZ_Layer_PS newZ, const FullPhi_Layer_PS newPhi,
		     const FullR_Layer_PS newR, const FullPt_Layer_PS newPt)
  {
    AddStub(newZ, newPhi, newR, newPt);
  }
  void AddStub(const StubData newStub)
  {
	data_ = newStub;
  }
  void AddStub(const FullZ_Layer_PS newZ, const FullPhi_Layer_PS newPhi,
	       const FullR_Layer_PS newR, const FullPt_Layer_PS newPt)
  {
#ifdef FAT_CLASS
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
#endif // FAT_CLASS
    // without the to_long these variables truncate at their current bit width.
    data_ = newZ | (newPhi.to_long()<<12) | (newR.to_long()<<(14+12)) | (newPt.to_long()<<(14+12+7));
//    printf("data_ is %09lx, %09lx\n", data_.to_long(),(newPhi.to_long()<<12));
  }
  FullZ_Layer_PS GetZ() const
  {
    FullZ_Layer_PS tz = (data_&0xFFFUL);
#ifdef FAT_CLASS
    if ( tz != z ) {
      printf("tz = 0x%03x, z = 0x%03lx\n", tz.to_int(), z.to_int());
    }
#endif // FAT_CLASS
    return tz;
  }
  FullPhi_Layer_PS GetPhi()  const
  {
    FullPhi_Layer_PS tPhi = (data_>>12)& 0x3FFFUL;
#ifdef FAT_CLASS
    if ( tPhi != phi ) {
      printf("tphi = 0x%03x, phi = 0x%03lx\n", tPhi.to_int(), phi.to_int());
    }
#endif // FAT_CLASS
    return tPhi;
  }
  FullR_Layer_PS GetR()  const
  {
    FullR_Layer_PS tR = (data_>> (12+14))&0x7FUL;
#ifdef FAT_CLASS
    if ( tR != r ) {
      printf("tr = 0x%03x, r = 0x%03lx\n", tR.to_int(), r.to_int());
    }
#endif // FAT_CLASS
    return tR;
  }
  FullPt_Layer_PS GetPt()  const
  {
    FullPt_Layer_PS tPt = (data_ >> (12+14+7)) & 0x7UL;
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
  void SetZ(const FullZ_Layer_PS newZ)
  {
    // 36 bit mask: 0x3FFFFFFFFU
    const long int maskZ = 0x3FFFFFF000UL; // bottom 12 bits
    const int zShift = 0;
    data_ = (data_ & maskZ) | (newZ.to_long() << zShift);
//    z = newZ;
  }
  void SetPhi(const FullPhi_Layer_PS newPhi)
  {
    const long int maskPhi = 0x3FFC000FFFUL; // 14 bits, shifted up 12 bits
    const int phiShift = 12;
    data_ = ( data_ & maskPhi) | ( newPhi.to_long() << phiShift);
//    phi = newPhi;
  }
  void SetR(const FullR_Layer_PS newR)
  {
//    r = newR;
    const long int maskR = 0x3E03FFFFFFUL;
    const int rShift = 12+14;
    data_ = (data_ & maskR ) | ( newR.to_long() << rShift);
  }
  void SetPt(const FullPt_Layer_PS newPt)
  {
    const long int maskPt = 0x0FFFFFFFFUL;
    const int ptShift = 12+14+7;
    data_ = (data_ & maskPt ) | ( newPt.to_long() << ptShift);
//    pt = newPt;
  }
};

#ifdef FAT_CLASS
#undef FAT_CLASS
#endif
