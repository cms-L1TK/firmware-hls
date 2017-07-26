// VMRouter header file.
#pragma once
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include <vector>

using namespace std;

void VMRouter(HLSFullStubLayerPS *stubsInLayer,
              HLSFullStubLayerPS allStubs[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH1Z1[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH2Z1[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH3Z1[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH4Z1[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH1Z2[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH2Z2[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH3Z2[MAX_nSTUBS],
              HLSReducedStubLayer vmStubsPH4Z2[MAX_nSTUBS],
              int nStubs,
              ReducedIndex *nPH1Z1, ReducedIndex *nPH2Z1,
              ReducedIndex *nPH3Z1, ReducedIndex *nPH4Z1,
              ReducedIndex *nPH1Z2, ReducedIndex *nPH2Z2,
              ReducedIndex *nPH3Z2, ReducedIndex *nPH4Z2);
