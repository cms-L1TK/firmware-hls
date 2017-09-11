// VMRouterDispatcher header file.
#pragma once
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

using namespace std;

void VMRouterDispatcher(HLSFullStubLayerPS curStubsInLayer[MAX_nSTUBS*MAX_nROUTERS],
			HLSFullStubLayerPS curAllStubs[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH1Z1[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH2Z1[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH3Z1[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH4Z1[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH1Z2[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH2Z2[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH3Z2[MAX_nSTUBS*MAX_nROUTERS],
			HLSReducedStubLayer curvmStubsPH4Z2[MAX_nSTUBS*MAX_nROUTERS],
			int curnStubs[MAX_nROUTERS],
			ReducedIndex curnPH1Z1[MAX_nROUTERS],
			ReducedIndex curnPH2Z1[MAX_nROUTERS],
			ReducedIndex curnPH3Z1[MAX_nROUTERS],
			ReducedIndex curnPH4Z1[MAX_nROUTERS],
			ReducedIndex curnPH1Z2[MAX_nROUTERS],
			ReducedIndex curnPH2Z2[MAX_nROUTERS],
			ReducedIndex curnPH3Z2[MAX_nROUTERS],
			ReducedIndex curnPH4Z2[MAX_nROUTERS]);
