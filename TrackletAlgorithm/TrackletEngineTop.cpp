#include "TrackletEngineTop.h"

void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       const ap_uint<1> pttable[32],
                       const ap_uint<1> bendinnertable[256],
                       const ap_uint<1> bendoutertable[256],
                       StubPairMemory& outstubpair)
{
#pragma HLS resource variable=instubinnerdata.get_mem() latency=2
#pragma HLS resource variable=instubouterdata.get_mem() latency=2
#pragma HLS resource variable=pttable latency=2
#pragma HLS resource variable=bendinnertable latency=2
#pragma HLS resource variable=bendoutertable latency=2
  TrackletEngine<BARRELPS, BARRELPS, 32, 256, 256>
  (bx, instubinnerdata, instubouterdata, pttable, bendinnertable, bendoutertable, outstubpair);
}
