// Layer Router
// [wittich 8/10/2017]
#include "HLSConstants.h"
#include "ap_int.h"
#include "HLSFullStubLayerPS.h"

void LayerRouter(
		 HLSFullStubLayerPS StubIn[64],
		 HLSFullStubLayerPS StubOut[6][64]
		 //		HLSFullStubLayerPS *StubOut1,
		 //		HLSFullStubLayerPS *StubOut2,
		 //		HLSFullStubLayerPS *StubOut3,
		 //		HLSFullStubLayerPS *StubOut4,
		 //              HLSFullStubLayerPS *StubOut5,
		 //              HLSFullStubLayerPS *StubOut6              
		 )
{
  StubData header = StubIn[0].raw();
  static int numberL[6]; // each is six bits but docs suggest I don't need to set it
   PARSE: for (int i = 0; i < 6; ++i) {
    numberL[5-i] = (header >> (i*6) ) & 0x3F;
  } // parse first word
        
  HLSFullStubLayerPS *activeOut = StubOut[0];
  int active = 0;
  int layerCnt = 0;
  STUBLOOP: for (int i = 1; i < MAX_nSTUBS-1; ++i ) { // note start at 1!!!!!
    if ( i < numberL[active] ) {
      activeOut[layerCnt] = StubIn[i];
      ++layerCnt;
    }
    else {
      ++active;
      activeOut = StubOut[active];
      layerCnt = 0;
    }
    if ( i > numberL[5])
      break;
	
  } // loop over stubs
	
  return;
}
