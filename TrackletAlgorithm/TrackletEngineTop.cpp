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
  // !!! currently handles TE_L1PHIE18_L2PHIC17 only !!!
  TE_L1PHIE18_L2PHIC17: TrackletEngine<TE::L1L2, TE::E18, TE::C17, BARRELPS, BARRELPS, 32, 256, 256>
			(bx, instubinnerdata, instubouterdata, pttable, bendinnertable, bendoutertable, outstubpair);
}
