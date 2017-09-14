// input: LR input
// output: VMRouter output
#include "HLSConstants.hh"
#include "LayerRouter.hh"
#include "VMRouter.hh"

void
LR_VMR(HLSFullStubLayerPS Stubin1[MAX_nSTUBS],
       HLSFullStubLayerPS allStubs[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH1Z1[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH2Z1[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH3Z1[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH4Z1[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH1Z2[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH2Z2[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH3Z2[6][MAX_nSTUBS],
       HLSReducedStubLayer vmStubsPH4Z2[6][MAX_nSTUBS],
       ReducedIndex nPH1Z1[6][MAX_nSTUBS], ReducedIndex nPH2Z1[6][MAX_nSTUBS],
       ReducedIndex nPH3Z1[6][MAX_nSTUBS], ReducedIndex nPH4Z1[6][MAX_nSTUBS],
       ReducedIndex nPH1Z2[6][MAX_nSTUBS], ReducedIndex nPH2Z2[6][MAX_nSTUBS],
       ReducedIndex nPH3Z2[6][MAX_nSTUBS], ReducedIndex nPH4Z2[6][MAX_nSTUBS] )
{

  static HLSFullStubLayerPS stubs[6][MAX_nSTUBS];
  LayerRouter(Stubin1, stubs);

  static int nstubs[6]; // each is six bits but docs suggest I don't need to set it
   PARSE: for (int i = 0; i < 6; ++i) {
    nstubs[5-i] = (Stubin1[0].raw() >> (i*6) ) & 0x3F;
  } // parse first word
  
  VMRLOOP: for ( int i = 0; i < 6; ++i ) {
    VMRouter(stubs[i], allStubs[i],
	     vmStubsPH1Z1[i],
	     vmStubsPH2Z1[i],
	     vmStubsPH3Z1[i],
	     vmStubsPH4Z1[i],
	     vmStubsPH1Z2[i],
	     vmStubsPH2Z2[i],
	     vmStubsPH3Z2[i],
	     vmStubsPH4Z2[i],
	     nstubs[i],
	     nPH1Z1[i], nPH2Z1[i],
	     nPH3Z1[i], nPH4Z1[i],
	     nPH1Z2[i], nPH2Z2[i],
	     nPH3Z2[i], nPH4Z2[i]);
  }
      

  
}
