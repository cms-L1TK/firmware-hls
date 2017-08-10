// VMRouterDispatcher module
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include <vector>

//using namespace std;

void VMRouterDispatcher(HLSFullStubLayerPS curStubsInLayer_1[MAX_nSTUBS], HLSFullStubLayerPS curStubsInLayer_2[MAX_nSTUBS],
			HLSFullStubLayerPS curStubsInLayer_3[MAX_nSTUBS], HLSFullStubLayerPS curStubsInLayer_4[MAX_nSTUBS],
			HLSFullStubLayerPS curStubsInLayer_5[MAX_nSTUBS], HLSFullStubLayerPS curStubsInLayer_6[MAX_nSTUBS],
			HLSFullStubLayerPS curStubsInLayer_7[MAX_nSTUBS], HLSFullStubLayerPS curStubsInLayer_8[MAX_nSTUBS],
			HLSFullStubLayerPS curAllStubs_1[MAX_nSTUBS], HLSFullStubLayerPS curAllStubs_2[MAX_nSTUBS],
			HLSFullStubLayerPS curAllStubs_3[MAX_nSTUBS], HLSFullStubLayerPS curAllStubs_4[MAX_nSTUBS],
			HLSFullStubLayerPS curAllStubs_5[MAX_nSTUBS], HLSFullStubLayerPS curAllStubs_6[MAX_nSTUBS],
			HLSFullStubLayerPS curAllStubs_7[MAX_nSTUBS], HLSFullStubLayerPS curAllStubs_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z1_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z1_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z1_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z1_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z1_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z1_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z1_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z1_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z1_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z1_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z1_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z1_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z1_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z1_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z1_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z1_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z1_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z1_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z1_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z1_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z1_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z1_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z1_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z1_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z1_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z1_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z1_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z1_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z1_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z1_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z1_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z1_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z2_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z2_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z2_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z2_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z2_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z2_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH1Z2_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH1Z2_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z2_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z2_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z2_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z2_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z2_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z2_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH2Z2_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH2Z2_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z2_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z2_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z2_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z2_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z2_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z2_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH3Z2_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH3Z2_8[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z2_1[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z2_2[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z2_3[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z2_4[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z2_5[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z2_6[MAX_nSTUBS],
			HLSReducedStubLayer curvmStubsPH4Z2_7[MAX_nSTUBS], HLSReducedStubLayer curvmStubsPH4Z2_8[MAX_nSTUBS],
			int curnStubs_1, int curnStubs_2, int curnStubs_3, int curnStubs_4,
			int curnStubs_5, int curnStubs_6, int curnStubs_7, int curnStubs_8,
			ReducedIndex *curnPH1Z1_1, ReducedIndex *curnPH1Z1_2, ReducedIndex *curnPH1Z1_3, ReducedIndex *curnPH1Z1_4,
			ReducedIndex *curnPH1Z1_5, ReducedIndex *curnPH1Z1_6, ReducedIndex *curnPH1Z1_7, ReducedIndex *curnPH1Z1_8,
			ReducedIndex *curnPH2Z1_1, ReducedIndex *curnPH2Z1_2, ReducedIndex *curnPH2Z1_3, ReducedIndex *curnPH2Z1_4,
			ReducedIndex *curnPH2Z1_5, ReducedIndex *curnPH2Z1_6, ReducedIndex *curnPH2Z1_7, ReducedIndex *curnPH2Z1_8,
			ReducedIndex *curnPH3Z1_1, ReducedIndex *curnPH3Z1_2, ReducedIndex *curnPH3Z1_3, ReducedIndex *curnPH3Z1_4,
			ReducedIndex *curnPH3Z1_5, ReducedIndex *curnPH3Z1_6, ReducedIndex *curnPH3Z1_7, ReducedIndex *curnPH3Z1_8,
			ReducedIndex *curnPH4Z1_1, ReducedIndex *curnPH4Z1_2, ReducedIndex *curnPH4Z1_3, ReducedIndex *curnPH4Z1_4,
			ReducedIndex *curnPH4Z1_5, ReducedIndex *curnPH4Z1_6, ReducedIndex *curnPH4Z1_7, ReducedIndex *curnPH4Z1_8,
			ReducedIndex *curnPH1Z2_1, ReducedIndex *curnPH1Z2_2, ReducedIndex *curnPH1Z2_3, ReducedIndex *curnPH1Z2_4,
			ReducedIndex *curnPH1Z2_5, ReducedIndex *curnPH1Z2_6, ReducedIndex *curnPH1Z2_7, ReducedIndex *curnPH1Z2_8,
			ReducedIndex *curnPH2Z2_1, ReducedIndex *curnPH2Z2_2, ReducedIndex *curnPH2Z2_3, ReducedIndex *curnPH2Z2_4,
			ReducedIndex *curnPH2Z2_5, ReducedIndex *curnPH2Z2_6, ReducedIndex *curnPH2Z2_7, ReducedIndex *curnPH2Z2_8,
			ReducedIndex *curnPH3Z2_1, ReducedIndex *curnPH3Z2_2, ReducedIndex *curnPH3Z2_3, ReducedIndex *curnPH3Z2_4,
			ReducedIndex *curnPH3Z2_5, ReducedIndex *curnPH3Z2_6, ReducedIndex *curnPH3Z2_7, ReducedIndex *curnPH3Z2_8,
			ReducedIndex *curnPH4Z2_1, ReducedIndex *curnPH4Z2_2, ReducedIndex *curnPH4Z2_3, ReducedIndex *curnPH4Z2_4,
			ReducedIndex *curnPH4Z2_5, ReducedIndex *curnPH4Z2_6, ReducedIndex *curnPH4Z2_7, ReducedIndex *curnPH4Z2_8)
{
  VMRouter(curStubsInLayer_1, curAllStubs_1,
           curvmStubsPH1Z1_1, curvmStubsPH2Z1_1, curvmStubsPH3Z1_1, curvmStubsPH4Z1_1,
           curvmStubsPH1Z2_1, curvmStubsPH2Z2_1, curvmStubsPH3Z2_1, curvmStubsPH4Z2_1,
           curnStubs_1, curnPH1Z1_1, curnPH2Z1_1, curnPH3Z1_1, curnPH4Z1_1, curnPH1Z2_1, curnPH2Z2_1, curnPH3Z2_1, curnPH4Z2_1);

  VMRouter(curStubsInLayer_2, curAllStubs_2,
           curvmStubsPH1Z1_2, curvmStubsPH2Z1_2, curvmStubsPH3Z1_2, curvmStubsPH4Z1_2,
           curvmStubsPH1Z2_2, curvmStubsPH2Z2_2, curvmStubsPH3Z2_2, curvmStubsPH4Z2_2,
           curnStubs_2, curnPH1Z1_2, curnPH2Z1_2, curnPH3Z1_2, curnPH4Z1_2, curnPH1Z2_2, curnPH2Z2_2, curnPH3Z2_2, curnPH4Z2_2);

  VMRouter(curStubsInLayer_3, curAllStubs_3,
           curvmStubsPH1Z1_3, curvmStubsPH2Z1_3, curvmStubsPH3Z1_3, curvmStubsPH4Z1_3,
           curvmStubsPH1Z2_3, curvmStubsPH2Z2_3, curvmStubsPH3Z2_3, curvmStubsPH4Z2_3,
           curnStubs_3, curnPH1Z1_3, curnPH2Z1_3, curnPH3Z1_3, curnPH4Z1_3, curnPH1Z2_3, curnPH2Z2_3, curnPH3Z2_3, curnPH4Z2_3);

  VMRouter(curStubsInLayer_4, curAllStubs_4,
           curvmStubsPH1Z1_4, curvmStubsPH2Z1_4, curvmStubsPH3Z1_4, curvmStubsPH4Z1_4,
           curvmStubsPH1Z2_4, curvmStubsPH2Z2_4, curvmStubsPH3Z2_4, curvmStubsPH4Z2_4,
           curnStubs_4, curnPH1Z1_4, curnPH2Z1_4, curnPH3Z1_4, curnPH4Z1_4, curnPH1Z2_4, curnPH2Z2_4, curnPH3Z2_4, curnPH4Z2_4);

  VMRouter(curStubsInLayer_5, curAllStubs_5,
           curvmStubsPH1Z1_5, curvmStubsPH2Z1_5, curvmStubsPH3Z1_5, curvmStubsPH4Z1_5,
           curvmStubsPH1Z2_5, curvmStubsPH2Z2_5, curvmStubsPH3Z2_5, curvmStubsPH4Z2_5,
           curnStubs_5, curnPH1Z1_5, curnPH2Z1_5, curnPH3Z1_5, curnPH4Z1_5, curnPH1Z2_5, curnPH2Z2_5, curnPH3Z2_5, curnPH4Z2_5);

  VMRouter(curStubsInLayer_6, curAllStubs_6,
           curvmStubsPH1Z1_6, curvmStubsPH2Z1_6, curvmStubsPH3Z1_6, curvmStubsPH4Z1_6,
           curvmStubsPH1Z2_6, curvmStubsPH2Z2_6, curvmStubsPH3Z2_6, curvmStubsPH4Z2_6,
           curnStubs_6, curnPH1Z1_6, curnPH2Z1_6, curnPH3Z1_6, curnPH4Z1_6, curnPH1Z2_6, curnPH2Z2_6, curnPH3Z2_6, curnPH4Z2_6);

  VMRouter(curStubsInLayer_7, curAllStubs_7,
           curvmStubsPH1Z1_7, curvmStubsPH2Z1_7, curvmStubsPH3Z1_7, curvmStubsPH4Z1_7,
           curvmStubsPH1Z2_7, curvmStubsPH2Z2_7, curvmStubsPH3Z2_7, curvmStubsPH4Z2_7,
           curnStubs_7, curnPH1Z1_7, curnPH2Z1_7, curnPH3Z1_7, curnPH4Z1_7, curnPH1Z2_7, curnPH2Z2_7, curnPH3Z2_7, curnPH4Z2_7);

  VMRouter(curStubsInLayer_8, curAllStubs_8,
           curvmStubsPH1Z1_8, curvmStubsPH2Z1_8, curvmStubsPH3Z1_8, curvmStubsPH4Z1_8,
           curvmStubsPH1Z2_8, curvmStubsPH2Z2_8, curvmStubsPH3Z2_8, curvmStubsPH4Z2_8,
           curnStubs_8, curnPH1Z1_8, curnPH2Z1_8, curnPH3Z1_8, curnPH4Z1_8, curnPH1Z2_8, curnPH2Z2_8, curnPH3Z2_8, curnPH4Z2_8);
}
