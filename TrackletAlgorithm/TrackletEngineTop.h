#ifndef TrackletAlgorithm_TrackletEngineTop_h
#define TrackletAlgorithm_TrackletEngineTop_h

#include "TrackletEngine.h"

void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE],
                       const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE],
                       StubPairMemory& outstubpair);

#endif
