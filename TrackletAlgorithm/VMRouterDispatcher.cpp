// VMRouterDispatcher module
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

//using namespace std;

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
                        ReducedIndex curnPH4Z2[MAX_nROUTERS])
{
  #pragma HLS ARRAY_PARTITION variable=curStubsInLayer block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curStubsInLayer inter false
  #pragma HLS ARRAY_PARTITION variable=curAllStubs block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curAllStubs inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH1Z1 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH1Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH2Z1 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH2Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH3Z1 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH3Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH4Z1 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH4Z1 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH1Z2 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH1Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH2Z2 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH2Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH3Z2 block factor=MAX_nROUTERS
  #pragma HLS DEPENDENCE variable=curvmStubsPH3Z2 inter false
  #pragma HLS ARRAY_PARTITION variable=curvmStubsPH4Z2 block factor=MAX_nROUTERS
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

  for (int i=0; i<MAX_nROUTERS; i++)
  {
    #pragma HLS UNROLL
    VMRouter(&curStubsInLayer[i*MAX_nSTUBS], &curAllStubs[i*MAX_nSTUBS],
             &curvmStubsPH1Z1[i*MAX_nSTUBS], &curvmStubsPH2Z1[i*MAX_nSTUBS], &curvmStubsPH3Z1[i*MAX_nSTUBS], &curvmStubsPH4Z1[i*MAX_nSTUBS],
             &curvmStubsPH1Z2[i*MAX_nSTUBS], &curvmStubsPH2Z2[i*MAX_nSTUBS], &curvmStubsPH3Z2[i*MAX_nSTUBS], &curvmStubsPH4Z2[i*MAX_nSTUBS],
             curnStubs[i], &curnPH1Z1[i], &curnPH2Z1[i], &curnPH3Z1[i], &curnPH4Z1[i], &curnPH1Z2[i], &curnPH2Z2[i], &curnPH3Z2[i], &curnPH4Z2[i]);
  }
}
