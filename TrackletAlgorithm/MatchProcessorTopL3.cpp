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
                         const TrackletProjectionMemory<BARRELPS>* const proj9in,
                         const TrackletProjectionMemory<BARRELPS>* const proj10in,
                         const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
                         const AllStubMemory<BARRELPS>* allstub,
                         BXType& bx_o,
                         FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]) {

 #pragma HLS interface register port=bx_o
/*
 #pragma HLS resource variable=proj1in->get_mem() latency=2
 #pragma HLS resource variable=proj2in->get_mem() latency=2
 #pragma HLS resource variable=proj3in->get_mem() latency=2
 #pragma HLS resource variable=proj4in->get_mem() latency=2
 #pragma HLS resource variable=proj5in->get_mem() latency=2
 #pragma HLS resource variable=proj6in->get_mem() latency=2
 #pragma HLS resource variable=proj7in->get_mem() latency=2
 #pragma HLS resource variable=proj8in->get_mem() latency=2
 #pragma HLS resource variable=proj9in->get_mem() latency=2
 #pragma HLS resource variable=proj10in->get_mem() latency=2
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

 MatchProcessor<3, BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, maxInCopies, maxFullMatchCopies, maxTrackletProjections, maxTrackletProjections, 3, 0, 2>
                     (bx,
                      proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
                      proj9in, proj10in, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      instubdata,
                      allstub,
                      bx_o,
                      fullmatch);

}

