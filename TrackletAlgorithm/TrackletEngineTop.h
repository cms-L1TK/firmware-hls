#ifndef TRACKLETENGINETOP_H
#define TRACKLETENGINETOP_H

#include "TrackletEngine.h"

// !!! currently handles TE_L1PHIE18_L2PHIC17 only !!!
void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       StubPairMemory& outstubpair);

#endif
