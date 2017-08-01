// VMRouterDispatcher module
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

//using namespace std;

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
              ReducedIndex nPH3Z2[MAX_nROUTERS], ReducedIndex nPH4Z2[MAX_nROUTERS])
{
// These #pragmas are supposed to break up each array into MAX_nROUTERS different memories, so that they can be accessed in parallel
#pragma HLS ARRAY_PARTITION variable=stubsInLayer block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=nStubs complete
#pragma HLS ARRAY_PARTITION variable=allStubs block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH1Z1 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH2Z1 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH3Z1 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH4Z1 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH1Z2 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH2Z2 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH3Z2 block factor=MAX_nROUTERS
#pragma HLS ARRAY_PARTITION variable=vmStubsPH4Z2 block factor=MAX_nROUTERS
ROUTERLOOP: for (int i=0; i<MAX_nROUTERS; ++i)
  {
  // These #pragmas are suppose to explicitly tell HLS that, for each loop iteration, all the data being
  // operated on are independent. This #pragma is specifically designed to allow loops to be pipelined or unrolled
  // PW: moved to directives to allow exploration of different solutions
#pragma HLS UNROLL
    VMRouter(&stubsInLayer[i*MAX_nSTUBS], &allStubs[i*MAX_nSTUBS],
             &vmStubsPH1Z1[i*MAX_nSTUBS], &vmStubsPH2Z1[i*MAX_nSTUBS],
             &vmStubsPH3Z1[i*MAX_nSTUBS], &vmStubsPH4Z1[i*MAX_nSTUBS],
             &vmStubsPH1Z2[i*MAX_nSTUBS], &vmStubsPH2Z2[i*MAX_nSTUBS],
             &vmStubsPH3Z2[i*MAX_nSTUBS], &vmStubsPH4Z2[i*MAX_nSTUBS],
             nStubs[i],
             &nPH1Z1[i], &nPH2Z1[i],
             &nPH3Z1[i], &nPH4Z1[i],
             &nPH1Z2[i], &nPH2Z2[i],
             &nPH3Z2[i], &nPH4Z2[i]);

  }
}
