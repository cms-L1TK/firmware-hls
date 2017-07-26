// This is the HLSReducedStubLayer class, which contains, in essence the 18 bits of a reduced stub, after it has been routed
#pragma once
#include "ap_int.h"
#include "HLSConstants.hh"
class HLSReducedStubLayer
{
public:
  HLSReducedStubLayer()
  {
    z = 0;
    phi = 0;
    r = 0;
    pt = 0;
    index = 0;
  }
  void AddStub(ReducedZ_Layer newZ, ReducedPhi_Layer newPhi, ReducedR_Layer newR, ReducedPt_Layer newPt, ReducedIndex newIndex)
  {
    z = newZ;
    phi = newPhi;
    r = newR;
    pt = newPt;
    index = newIndex;
  }
  ReducedZ_Layer GetZ()
  {
    return z;
  }
  ReducedPhi_Layer GetPhi()
  {
    return phi;
  }
  ReducedR_Layer GetR()
  {
    return r;
  }
  ReducedPt_Layer GetPt()
  {
    return pt;
  }
  ReducedIndex GetIndex()
  {
    return index;
  }
  void SetZ(ReducedZ_Layer newZ)
  {
    z = newZ;
  }
  void SetPhi(ReducedPhi_Layer newPhi)
  {
    phi = newPhi;
  }
  void SetR(ReducedR_Layer newR)
  {
    r = newR;
  }
  void SetPt(ReducedPt_Layer newPt)
  {
    pt = newPt;
  }
  void SetIndex(ReducedIndex newIndex)
  {
    index = newIndex;
  }
private:
  ReducedZ_Layer z;
  ReducedPhi_Layer phi;
  ReducedR_Layer r;
  ReducedPt_Layer pt;
  ReducedIndex index;
};

