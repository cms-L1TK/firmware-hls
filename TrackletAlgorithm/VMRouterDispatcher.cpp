// VMRouterDispatcher module
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
              ReducedIndex nPH3Z2[MAX_nROUTERS], ReducedIndex nPH4Z2[MAX_nROUTERS])
{
  HLSFullStubLayerPS curStubsInLayer[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2[MAX_nSTUBS];

  for (int i=0; i<MAX_nROUTERS; i++)
  {
    VMRouter(&stubsInLayer[i*MAX_nSTUBS], curAllStubs,
             curvmStubsPH1Z1, curvmStubsPH2Z1,
             curvmStubsPH3Z1, curvmStubsPH4Z1,
             curvmStubsPH1Z2, curvmStubsPH2Z2,
             curvmStubsPH3Z2, curvmStubsPH4Z2,
             nStubs[i],
             &nPH1Z1[i], &nPH2Z1[i],
             &nPH3Z1[i], &nPH4Z1[i],
             &nPH1Z2[i], &nPH2Z2[i],
             &nPH3Z2[i], &nPH4Z2[i]);
    copy(curAllStubs, curAllStubs + MAX_nSTUBS, allStubs + i*MAX_nSTUBS);
    copy(curvmStubsPH1Z1, curvmStubsPH1Z1 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS);
    copy(curvmStubsPH2Z1, curvmStubsPH2Z1 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS);
    copy(curvmStubsPH3Z1, curvmStubsPH3Z1 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS);
    copy(curvmStubsPH4Z1, curvmStubsPH4Z1 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS);
    copy(curvmStubsPH1Z2, curvmStubsPH1Z2 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS);
    copy(curvmStubsPH2Z2, curvmStubsPH2Z2 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS);
    copy(curvmStubsPH3Z2, curvmStubsPH3Z2 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS);
    copy(curvmStubsPH4Z2, curvmStubsPH4Z2 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS);
  }
}
