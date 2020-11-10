#include "MatchProcessorTopL3.h"

void MatchProcessorTopL3(BXType bx,
                      const TrackletProjectionMemory<BARRELPS>* const proj1in,
                      const TrackletProjectionMemory<BARRELPS>* const proj2in,
                      const TrackletProjectionMemory<BARRELPS>* const proj3in,
                      const TrackletProjectionMemory<BARRELPS>* const proj4in,
                      const TrackletProjectionMemory<BARRELPS>* const proj5in,
                      const TrackletProjectionMemory<BARRELPS>* const proj6in,
                      const TrackletProjectionMemory<BARRELPS>* const proj7in,
                      const TrackletProjectionMemory<BARRELPS>* const proj8in,
                      const VMStubMEMemory<BARRELPS,3> instubdata[maxInCopies],
                      const AllStubMemory<BARRELPS>* allstub,
                      const AllProjectionMemory<BARRELPS>* allproj,
                      BXType& bx_o,
                      FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]) {

 #pragma HLS interface register port=bx_o
 #pragma HLS resource variable=proj1in->get_mem() latency=2
 #pragma HLS resource variable=proj2in->get_mem() latency=2
 #pragma HLS resource variable=proj3in->get_mem() latency=2
 #pragma HLS resource variable=proj4in->get_mem() latency=2
 #pragma HLS resource variable=proj5in->get_mem() latency=2
 #pragma HLS resource variable=proj6in->get_mem() latency=2
 #pragma HLS resource variable=proj7in->get_mem() latency=2
 #pragma HLS resource variable=proj8in->get_mem() latency=2
 #pragma HLS resource variable=instubdata[0].get_mem() latency=2
 #pragma HLS resource variable=instubdata[1].get_mem() latency=2
 #pragma HLS resource variable=instubdata[2].get_mem() latency=2
 #pragma HLS resource variable=instubdata[3].get_mem() latency=2
 #pragma HLS resource variable=instubdata[4].get_mem() latency=2
 #pragma HLS resource variable=instubdata[5].get_mem() latency=2
 #pragma HLS resource variable=instubdata[6].get_mem() latency=2
 #pragma HLS resource variable=instubdata[7].get_mem() latency=2
 #pragma HLS resource variable=allstub->get_mem() latency=2
 #pragma HLS resource variable=allproj->get_mem() latency=2

 MatchProcessor<3, BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, maxInCopies, maxFullMatchCopies, 8, 3, 0, 2>
                     (bx,
                      proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      instubdata,
                      allstub,
                      allproj,
                      bx_o,
                      fullmatch);

}

