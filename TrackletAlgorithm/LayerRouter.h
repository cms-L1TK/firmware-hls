#ifndef TrackletAlgorithm_LayerRouter_h
#define TrackletAlgorithm_LayerRouter_h

#include "HLSConstants.h"
#include "HLSFullStubLayerPS.h"

void 
LayerRouter(
	    HLSFullStubLayerPS StubIn[64],
	    HLSFullStubLayerPS StubOut[6][64]
	    //		HLSFullStubLayerPS *StubOut1,
	    //		HLSFullStubLayerPS *StubOut2,
	    //		HLSFullStubLayerPS *StubOut3,
	    //		HLSFullStubLayerPS *StubOut4,
	    //              HLSFullStubLayerPS *StubOut5,
	    //              HLSFullStubLayerPS *StubOut6              
	    );

#endif
