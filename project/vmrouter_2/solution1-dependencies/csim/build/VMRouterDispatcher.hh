// VMRouterDispatcher header file.
#pragma once
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

using namespace std;

void VMRouterDispatcher(HLSFullStubLayerPS stubsInLayer[MAX_nSTUBS*MAX_nROUTERS],
              HLSFullStubLayerPS allStubs[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH1Z1[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH2Z1[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH3Z1[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH4Z1[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH1Z2[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH2Z2[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH3Z2[MAX_nSTUBS*MAX_nROUTERS],
              HLSReducedStubLayer vmStubsPH4Z2[MAX_nSTUBS*MAX_nROUTERS],
              int nStubs[MAX_nROUTERS],
              ReducedIndex nPH1Z1[MAX_nROUTERS], ReducedIndex nPH2Z1[MAX_nROUTERS],
              ReducedIndex nPH3Z1[MAX_nROUTERS], ReducedIndex nPH4Z1[MAX_nROUTERS],
              ReducedIndex nPH1Z2[MAX_nROUTERS], ReducedIndex nPH2Z2[MAX_nROUTERS],
              ReducedIndex nPH3Z2[MAX_nROUTERS], ReducedIndex nPH4Z2[MAX_nROUTERS]);
