#include "TrackletEngineTop.h"

void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE],
                       const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE],
                       StubPairMemory& outstubpair)
{
#pragma HLS resource variable=instubinnerdata.get_mem() latency=2
#pragma HLS resource variable=instubouterdata.get_mem() latency=2
#pragma HLS resource variable=bendinnertable latency=2
#pragma HLS resource variable=bendoutertable latency=2
  TrackletEngine<BARRELPS, BARRELPS, 1<<kNBits_bendinnertableTE, 1<<kNBits_bendoutertableTE>
  (bx, instubinnerdata, instubouterdata, bendinnertable, bendoutertable, outstubpair);
}
