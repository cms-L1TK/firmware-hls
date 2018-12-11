#ifndef TRACKLETENGINE_H
#define TRACKLETENGINE_H

#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"
#include "StubPairMemory.hh"

class CandMatch;

void TrackletEngine(
		    const ap_uint<3> bx,
		    const VMStubTEInnerMemory& instubinnerdata, 
		    const VMStubTEOuterMemory& instubouterdata,
		    StubPairMemory& outstubpairdata
		    );

#endif
