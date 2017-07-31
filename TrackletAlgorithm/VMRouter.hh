// VMRouter header file.
#pragma once
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include <vector>

using namespace std;

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
              ReducedIndex *nPH3Z2, ReducedIndex *nPH4Z2);
