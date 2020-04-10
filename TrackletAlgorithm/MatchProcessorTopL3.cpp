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
                      const VMStubMEMemory<BARRELPS>* instubdata1,
                      const VMStubMEMemory<BARRELPS>* instubdata2,
                      const VMStubMEMemory<BARRELPS>* instubdata3,
                      const VMStubMEMemory<BARRELPS>* instubdata4,
                      const VMStubMEMemory<BARRELPS>* instubdata5,
                      const VMStubMEMemory<BARRELPS>* instubdata6,
                      const VMStubMEMemory<BARRELPS>* instubdata7,
                      const VMStubMEMemory<BARRELPS>* instubdata8,
		      const VMStubMEMemory<BARRELPS>* instubdata,
                      const AllStubMemory<BARRELPS>* allstub,
                      const AllProjectionMemory<BARRELPS>* allproj,
                      BXType& bx_o,
                      FullMatchMemory<BARREL>* fullmatch1,
                      FullMatchMemory<BARREL>* fullmatch2,
                      FullMatchMemory<BARREL>* fullmatch3,
                      FullMatchMemory<BARREL>* fullmatch4,
                      FullMatchMemory<BARREL>* fullmatch5,
                      FullMatchMemory<BARREL>* fullmatch6,
                      FullMatchMemory<BARREL>* fullmatch7) {

 #pragma HLS interface register port=bx_o
 #pragma HLS resource variable=proj1in->get_mem() latency=2
 #pragma HLS resource variable=proj2in->get_mem() latency=2
 #pragma HLS resource variable=proj3in->get_mem() latency=2
 #pragma HLS resource variable=proj4in->get_mem() latency=2
 #pragma HLS resource variable=proj5in->get_mem() latency=2
 #pragma HLS resource variable=proj6in->get_mem() latency=2
 #pragma HLS resource variable=proj7in->get_mem() latency=2
 #pragma HLS resource variable=proj8in->get_mem() latency=2
 #pragma HLS resource variable=instubdata->get_mem() latency=2
 #pragma HLS resource variable=allstub->get_mem() latency=2
 #pragma HLS resource variable=allproj->get_mem() latency=2

 MatchProcessor<3, BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, 8, 3, 0, 2>
                     (bx,
                      proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      instubdata1, instubdata2, instubdata3, instubdata4, instubdata5, instubdata6, instubdata7, instubdata8,
                      instubdata,
                      allstub,
                      allproj,
                      bx_o,
					  fullmatch1, fullmatch2, fullmatch3, fullmatch4, fullmatch5, fullmatch6, fullmatch7);
}

