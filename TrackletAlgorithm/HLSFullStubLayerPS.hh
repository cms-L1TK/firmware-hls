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
  void AddStub(FullZ_Layer_PS newZ, FullPhi_Layer_PS newPhi, FullR_Layer_PS newR, FullPt_Layer_PS newPt)
  {
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
  }
  FullZ_Layer_PS GetZ()
  {
    return z;
  }
  FullPhi_Layer_PS GetPhi()
  {
    return phi;
  }
  FullR_Layer_PS GetR()
  {
    return r;
  }
  FullPt_Layer_PS GetPt()
  {
    return pt;
  }
  void SetZ(FullZ_Layer_PS newZ)
  {
    z = newZ;
  }
  void SetPhi(FullPhi_Layer_PS newPhi)
  {
    phi = newPhi;
  }
  void SetR(FullR_Layer_PS newR)
  {
    r = newR;
  }
  void SetPt(FullPt_Layer_PS newPt)
  {
    pt = newPt;
  }
private:
  FullZ_Layer_PS z;
  FullPhi_Layer_PS phi;
  FullR_Layer_PS r;
  FullPt_Layer_PS pt;
};

