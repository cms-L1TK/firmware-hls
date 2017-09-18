// VMRouterDispatcher module
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

//using namespace std;

void VMRouterDispatcher(HLSFullStubLayerPS curStubsInLayer[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
                        HLSFullStubLayerPS curAllStubs[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS],
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
                        ReducedIndex curnPH4Z2[MAX_nSECTORS*MAX_nREGIONS])
{
  #pragma HLS ARRAY_PARTITION variable=curStubsInLayer block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curStubsInLayer inter false
  #pragma HLS ARRAY_PARTITION variable=curAllStubs block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curAllStubs inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH1Z1 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH1Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH2Z1 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH2Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH3Z1 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH3Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH4Z1 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH4Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH1Z2 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH1Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH2Z2 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH2Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH3Z2 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH3Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH4Z2 block factor=MAX_nSECTORS*MAX_nREGIONS
  #pragma HLS DEPENDENCE variable=curvmStubsPH4Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curnStubs complete
  #pragma HLS ARRAY_PARTITION variable=curnPH1Z1 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH2Z1 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH3Z1 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH4Z1 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH1Z2 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH2Z2 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH3Z2 complete
  #pragma HLS ARRAY_PARTITION variable=curnPH4Z2 complete

  for (int j=0; j<MAX_nSECTORS; j++)
  {
    #pragma HLS UNROLL
    VMRouter<1>(&curStubsInLayer[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS], &curAllStubs[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z1[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z1[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z1[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z1[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z2[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z2[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z2[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z2[j*MAX_nSTUBS+0*MAX_nSTUBS*MAX_nSECTORS],
                curnStubs[j+0*MAX_nSECTORS],
                &curnPH1Z1[j+0*MAX_nSECTORS], &curnPH2Z1[j+0*MAX_nSECTORS], &curnPH3Z1[j+0*MAX_nSECTORS], &curnPH4Z1[j+0*MAX_nSECTORS],
                &curnPH1Z2[j+0*MAX_nSECTORS], &curnPH2Z2[j+0*MAX_nSECTORS], &curnPH3Z2[j+0*MAX_nSECTORS], &curnPH4Z2[j+0*MAX_nSECTORS]);

    VMRouter<2>(&curStubsInLayer[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS], &curAllStubs[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z1[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z1[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z1[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z1[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z2[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z2[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z2[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z2[j*MAX_nSTUBS+1*MAX_nSTUBS*MAX_nSECTORS],
                curnStubs[j+1*MAX_nSECTORS],
                &curnPH1Z1[j+1*MAX_nSECTORS], &curnPH2Z1[j+1*MAX_nSECTORS], &curnPH3Z1[j+1*MAX_nSECTORS], &curnPH4Z1[j+1*MAX_nSECTORS],
                &curnPH1Z2[j+1*MAX_nSECTORS], &curnPH2Z2[j+1*MAX_nSECTORS], &curnPH3Z2[j+1*MAX_nSECTORS], &curnPH4Z2[j+1*MAX_nSECTORS]);

    VMRouter<3>(&curStubsInLayer[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS], &curAllStubs[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z1[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z1[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z1[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z1[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH1Z2[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH2Z2[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS],
                &curvmStubsPH3Z2[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS], &curvmStubsPH4Z2[j*MAX_nSTUBS+2*MAX_nSTUBS*MAX_nSECTORS],
                curnStubs[j+2*MAX_nSECTORS],
                &curnPH1Z1[j+2*MAX_nSECTORS], &curnPH2Z1[j+2*MAX_nSECTORS], &curnPH3Z1[j+2*MAX_nSECTORS], &curnPH4Z1[j+2*MAX_nSECTORS],
                &curnPH1Z2[j+2*MAX_nSECTORS], &curnPH2Z2[j+2*MAX_nSECTORS], &curnPH3Z2[j+2*MAX_nSECTORS], &curnPH4Z2[j+2*MAX_nSECTORS]);

  }
}

