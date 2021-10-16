#ifndef TrackletAlgorithm_TrackletEngineTop_h
#define TrackletAlgorithm_TrackletEngineTop_h

#include "TrackletEngine.h"

void TrackletEngine_PS_PS(const BXType bx,
                          const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                          const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                          const ap_uint<1> bendinnertable[],
                          const ap_uint<1> bendoutertable[],
                          BXType& bx_o,
                          StubPairMemory& outstubpair);

void TrackletEngine_PS_2S(const BXType bx,
                          const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                          const VMStubTEOuterMemory<BARREL2S>& instubouterdata,
                          const ap_uint<1> bendinnertable[],
                          const ap_uint<1> bendoutertable[],
                          BXType& bx_o,
                          StubPairMemory& outstubpair);

void TrackletEngine_2S_2S(const BXType bx,
                          const VMStubTEInnerMemory<BARREL2S>& instubinnerdata,
                          const VMStubTEOuterMemory<BARREL2S>& instubouterdata,
                          const ap_uint<1> bendinnertable[],
                          const ap_uint<1> bendoutertable[],
                          BXType& bx_o,
                          StubPairMemory& outstubpair);

#endif
