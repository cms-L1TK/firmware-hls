#ifndef TrackletAlgorithm_TrackletEngineTop_h
#define TrackletAlgorithm_TrackletEngineTop_h

#include "TrackletEngine.h"

void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       const ap_uint<1> pttable[32],
                       const ap_uint<1> bendinnertable[256],
                       const ap_uint<1> bendoutertable[256],
                       StubPairMemory& outstubpair);

#endif
