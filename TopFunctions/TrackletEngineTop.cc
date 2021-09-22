#include "TrackletEngineTop.h"

void TrackletEngineTop(const BXType bx,
                       const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                       const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                       const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE],
                       const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE],
                       BXType& bx_o,
                       StubPairMemory& outstubpair)
{
#pragma HLS resource variable=instubinnerdata.get_mem() latency=2
#pragma HLS resource variable=instubouterdata.get_mem() latency=2
#pragma HLS resource variable=bendinnertable latency=2
#pragma HLS resource variable=bendoutertable latency=2
#pragma HLS interface register port=bx_o
  TrackletEngine<BARRELPS, BARRELPS, 1<<kNBits_bendinnertableTE, 1<<kNBits_bendoutertableTE>
  (bx, instubinnerdata, instubouterdata, bendinnertable, bendoutertable, bx_o, outstubpair);
}
