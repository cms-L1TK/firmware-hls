#include "TrackletEngineTop.h"

void TrackletEngine_PS_PS(const BXType bx,
                          const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                          const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
                          const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE[TF::L1L2]],
                          const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE[TF::L1L2]],
                          BXType& bx_o,
                          StubPairMemory& outstubpair)
{
#pragma HLS INTERFACE bram port=instubinnerdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=instubouterdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendinnertable storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendoutertable storage_type=RAM_2P latency=2
#pragma HLS interface mode=ap_none register port=bx_o
  TrackletEngine<BARRELPS, BARRELPS>
  (bx, instubinnerdata, instubouterdata, bendinnertable, bendoutertable, bx_o, outstubpair);
}

void TrackletEngine_PS_2S(const BXType bx,
                          const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
                          const VMStubTEOuterMemory<BARREL2S>& instubouterdata,
                          const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE[TF::L3L4]],
                          const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE[TF::L3L4]],
                          BXType& bx_o,
                          StubPairMemory& outstubpair)
{
#pragma HLS INTERFACE bram port=instubinnerdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=instubouterdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendinnertable storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendoutertable storage_type=RAM_2P latency=2
#pragma HLS interface mode=ap_none register port=bx_o
  TrackletEngine<BARRELPS, BARREL2S>
  (bx, instubinnerdata, instubouterdata, bendinnertable, bendoutertable, bx_o, outstubpair);
}

void TrackletEngine_2S_2S(const BXType bx,
                          const VMStubTEInnerMemory<BARREL2S>& instubinnerdata,
                          const VMStubTEOuterMemory<BARREL2S>& instubouterdata,
                          const ap_uint<1> bendinnertable[1<<kNBits_bendinnertableTE[TF::L5L6]],
                          const ap_uint<1> bendoutertable[1<<kNBits_bendoutertableTE[TF::L5L6]],
                          BXType& bx_o,
                          StubPairMemory& outstubpair)
{
#pragma HLS INTERFACE bram port=instubinnerdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=instubouterdata.get_mem() storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendinnertable storage_type=RAM_2P latency=2
#pragma HLS INTERFACE bram port=bendoutertable storage_type=RAM_2P latency=2
#pragma HLS interface mode=ap_none register port=bx_o
  TrackletEngine<BARREL2S, BARREL2S>
  (bx, instubinnerdata, instubouterdata, bendinnertable, bendoutertable, bx_o, outstubpair);
}
