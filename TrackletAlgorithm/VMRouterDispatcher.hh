// VMRouterDispatcher header file.
#pragma once
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSFullStubLayer2S.hh"
#include "HLSReducedStubLayer.hh"
#include <vector>

using namespace std;

void VMRouterDispatcher(HLSFullStubLayerPS curStubsInLayerPS[MAX_nSTUBS*MAX_nSECTORS*MAX_nINNERRS],
                        HLSFullStubLayerPS curAllStubsPS[MAX_nSTUBS*MAX_nSECTORS*MAX_nINNERRS],
			HLSFullStubLayer2S curStubsInLayer2S[MAX_nSTUBS*MAX_nSECTORS*MAX_nOUTERRS],
                        HLSFullStubLayer2S curAllStubs2S[MAX_nSTUBS*MAX_nSECTORS*MAX_nOUTERRS],
                        HLSReducedStubLayer curvmStubsPH1Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH2Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH3Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH4Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH1Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH2Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH3Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSReducedStubLayer curvmStubsPH4Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        int curnStubs[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH1Z1[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH2Z1[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH3Z1[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH4Z1[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH1Z2[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH2Z2[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH3Z2[MAX_nSECTORS*MAX_nREGIONS],
                        ReducedIndex curnPH4Z2[MAX_nSECTORS*MAX_nREGIONS]);
