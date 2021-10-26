#include "MatchProcessorTopL3.h"

void MatchProcessorTopL3(BXType bx,
                         const TrackletProjectionMemory<BARRELPS> projin[maxTrackletProjections],
                         const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
                         const AllStubMemory<BARRELPS>* allstub,
                         BXType& bx_o,
                         FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]) {

 #pragma HLS interface register port=bx_o
 for(int i = 0; i < maxTrackletProjections; ++i) {
 #pragma HLS unroll
 #pragma HLS resource variable=projin[i].get_mem() latency=2
 }
 #pragma HLS resource variable=instubdata.get_mem() latency=2
 #pragma HLS resource variable=allstub->get_mem() latency=2
 #pragma HLS resource variable=fullmatch[0].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[1].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[2].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[3].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[4].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[5].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[6].get_mem() latency=2
 #pragma HLS resource variable=fullmatch[7].get_mem() latency=2

 const auto LAYER  = TF::L3;
 const auto DISK   = TF::D1;
  const auto PHISEC = MC::C;
 MatchProcessor<BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, maxTrackletProjections, maxFullMatchCopies, LAYER, DISK, PHISEC>
                     (bx,
                      projin,
                      instubdata,
                      allstub,
                      bx_o,
                      fullmatch);

}

