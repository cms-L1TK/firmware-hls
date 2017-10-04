// First attempt at the VMRouter module
//
// Assumptions:
// Must be even-number layer
// Must be PS-layer
//
#pragma once
#include "HLSFullStubLayerPS.hh"
#include "HLSFullStubLayer2S.hh"
#include "HLSConstants.hh"
#include "ap_int.h"
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

template <class T, int N>
void VMRouter(T *stubsInLayer,
              T *allStubs,
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
      // Calculate reduced-format parameters.
      // (&ing with hex is to fix correct number if bit width is messed up.
      //  will leave it in for now but it doesn't appear to be needed).
      // Calculate routing parameters
      ReducedZ_Layer redZ;
      ReducedPhi_Layer redPhi;
      ReducedR_Layer redR;
      ReducedPt_Layer redPt;
      ap_uint<2> routePhi;
      ap_uint<1> routeZ;
      if (N==1 || N==2 || N==3)
      {
        FullZ_Layer_PS curZ = stubsInLayer[i].GetZ();
        FullPhi_Layer_PS curPhi = stubsInLayer[i].GetPhi();
        FullR_Layer_PS curR = stubsInLayer[i].GetR();
        FullPt_Layer_PS curPt = stubsInLayer[i].GetPt();
        redPt = curPt;
        redZ = (curZ >> 5) & 0xFU;
        redR = (curR >> 5) & 0x3U;
        routeZ = (curZ >> 9) & 0x1U;
        if (N==2){
          redPhi = (curPhi >> 9) & 0x7U;
          routePhi = (curPhi >> 12 ) & 0x3U;
        } else {
          redPhi = (curPhi >> 9) ^ 0x4U;
          routePhi = (((curPhi >> 11) - 1) >> 1) & 0x3U;
        }
      }
      else if (N==4 || N==5 || N==6)
      {
        FullZ_Layer_2S curZ = stubsInLayer[i].GetZ();
        FullPhi_Layer_2S curPhi = stubsInLayer[i].GetPhi();
        FullR_Layer_2S curR = stubsInLayer[i].GetR();
        FullPt_Layer_2S curPt = stubsInLayer[i].GetPt();
        redPt = curPt;
        redZ = (curZ >> 1) & 0xFU;
        redR = (curR >> 6) & 0x3U;
        routeZ = (curZ >> 5) & 0x1U;
        if (N==5){
          redPhi = (curPhi >> 12) ^ 0x4U;
          routePhi = (((curPhi >> 14) - 1) >> 1) & 0x3U;
        } else {
          redPhi = (curPhi >> 12) & 0x7U;
          routePhi = (curPhi >> 15 ) & 0x3U;
        }
      }

      // Rewrite stub parameters to new stub in allStubs
      allStubs[i].AddStub(stubsInLayer[i].raw());

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




