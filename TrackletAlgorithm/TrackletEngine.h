#ifndef TRACKLETENGINE_H
#define TRACKLETENGINE_H

#include "VMStubsTEInner.hh"
#include "VMStubsTEOuter.hh"
#include "StubPairs.hh"

class CandMatch;

void TrackletEngine(
		    const ap_uint<3> bx,
		    const VMStubsTEInner& instubinnerdata, 
		    const VMStubsTEOuter& instubouterdata,
		    StubPairs& outstubpairdata
		    );

#endif
