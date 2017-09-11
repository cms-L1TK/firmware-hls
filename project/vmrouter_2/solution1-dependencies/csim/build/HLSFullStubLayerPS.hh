// This is the HLSFullStubLayer class, which contains, in essence the 36 bits of a full stub, with few other functions
//using namespace std;
#pragma once
#include "ap_int.h"
#include "HLSConstants.hh"
class HLSFullStubLayerPS
{
public:
  HLSFullStubLayerPS()
  {
    z = 0;
    phi = 0;
    r = 0;
    pt = 0;
  }
  void AddStub(const FullZ_Layer_PS newZ, const FullPhi_Layer_PS newPhi, const FullR_Layer_PS newR, const FullPt_Layer_PS newPt)
  {
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
  }
  FullZ_Layer_PS GetZ() const
  {
    return z;
  }
  FullPhi_Layer_PS GetPhi()  const
  {
    return phi;
  }
  FullR_Layer_PS GetR()  const
  {
    return r;
  }
  FullPt_Layer_PS GetPt()  const
  {
    return pt;
  }
  void SetZ(const FullZ_Layer_PS newZ)
  {
    z = newZ;
  }
  void SetPhi(const FullPhi_Layer_PS newPhi)
  {
    phi = newPhi;
  }
  void SetR(const FullR_Layer_PS newR)
  {
    r = newR;
  }
  void SetPt(const FullPt_Layer_PS newPt)
  {
    pt = newPt;
  }
private:
  FullZ_Layer_PS z;
  FullPhi_Layer_PS phi;
  FullR_Layer_PS r;
  FullPt_Layer_PS pt;
};

