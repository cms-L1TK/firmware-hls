// First attempt at the VMRouter module
//
// Assumptions:
// Must be even-number layer
// Must be PS-layer
//
#pragma once
#include "HLSFullStubLayerPS.hh"
#include "HLSConstants.hh"
#include "ap_int.h"
#include <vector>
#include <stdio.h>

using namespace std;

template <int N>
void VMRouter(HLSFullStubLayerPS *stubsInLayer,
              HLSFullStubLayerPS *allStubs,
              HLSReducedStubLayer *vmStubsPH1Z1,
              HLSReducedStubLayer *vmStubsPH2Z1,
              HLSReducedStubLayer *vmStubsPH3Z1,
              HLSReducedStubLayer *vmStubsPH4Z1,
              HLSReducedStubLayer *vmStubsPH1Z2,
              HLSReducedStubLayer *vmStubsPH2Z2,
              HLSReducedStubLayer *vmStubsPH3Z2,
              HLSReducedStubLayer *vmStubsPH4Z2,
              const int nStubs,
              ReducedIndex *nPH1Z1, ReducedIndex *nPH2Z1,
              ReducedIndex *nPH3Z1, ReducedIndex *nPH4Z1,
              ReducedIndex *nPH1Z2, ReducedIndex *nPH2Z2,
              ReducedIndex *nPH3Z2, ReducedIndex *nPH4Z2)
{
  ReducedIndex index = 0;

  STUBLOOP: for (int i=0; i<MAX_nSTUBS; ++i)
  {
  #pragma HLS PIPELINE II=1
    if (i < nStubs)
    {
      // Extract stub parameters
      const FullZ_Layer_PS curZ = stubsInLayer[i].GetZ();
      const FullPhi_Layer_PS curPhi = stubsInLayer[i].GetPhi();
      const FullR_Layer_PS curR = stubsInLayer[i].GetR();
      const FullPt_Layer_PS curPt = stubsInLayer[i].GetPt();

      // Rewrite stub parameters to new stub in allStubs
      allStubs[i].AddStub(curZ,curPhi,curR,curPt);

      // Calculate reduced-format parameters.
      // (&ing with hex is to fix correct number if bit width is messed up.
      //  will leave it in for now but it doesn't appear to be needed).
      const ReducedZ_Layer redZ ( (curZ >> 5) & 0xFU);

      ReducedPhi_Layer redPhi;
      if (N==1 || N==3) {
        redPhi = (curPhi >> 9) ^ 0x4U;
      } else {
        redPhi = (curPhi >> 9) & 0x7U;
      }
      const ReducedR_Layer redR( (curR >> 5) & 0x3U);
      const ReducedPt_Layer redPt(curPt);

      // Calculate routing parameters (only works for even layers for now)
      ap_uint<2>routePhi;
      if (N==1 || N==3) {
        routePhi = (((curPhi >> 11) - 1) >> 1) & 0x3U;
      } else {
        routePhi = (curPhi >> 12 ) & 0x3U;
      }
      const ap_uint<1> routeZ((curZ>>9) & 0x1U);

      // Route stubs
      switch (routeZ)
      {
        case 0:
          switch (routePhi)
          {
            case 0:
              vmStubsPH1Z1[nPH1Z1->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH1Z1);
              break;
            case 1:
              vmStubsPH2Z1[nPH2Z1->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH2Z1);
              break;
            case 2:
              vmStubsPH3Z1[nPH3Z1->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH3Z1);
              break;
            case 3:
              vmStubsPH4Z1[nPH4Z1->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH4Z1);
              break;
          }
          break;
        case 1:
          switch (routePhi)
          {
            case 0:
             vmStubsPH1Z2[nPH1Z2->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH1Z2);
              break;
            case 1:
              vmStubsPH2Z2[nPH2Z2->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH2Z2);
              break;
            case 2:
              vmStubsPH3Z2[nPH3Z2->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH3Z2);
              break;
            case 3:
             vmStubsPH4Z2[nPH4Z2->to_int()].AddStub(redZ, redPhi, redR, redPt, index);
              ++(*nPH4Z2);
              break;
          }
          break;
      }
      if (index==63) { index--; };
      ++index;
    } else
    {
      break;
    }
  }
}
