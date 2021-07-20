#include "MatchProcessorTop.h"

////////////////////////////////////////////////////////////////////////////////
// Top functions for various MatchProcessors (MP). For each iteration of
// the main processing loop, a MP retrieves an array of Candidate Matches,
// and computes Full Matches from each.
////////////////////////////////////////////////////////////////////////////////

void MatchProcessor_L3PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARRELPS> projin[L3PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARRELPS>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIBmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
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

MP_L3PHIB: MatchProcessor<BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, L3PHIBmaxTrackletProjections, L3PHIBmaxFullMatchCopies,
 TF::L3, TF::D1, MC::B> (
    bx,
    projin,
    instubdata,
    allstub,
    bx_o,
    fullmatch
  );
}

void MatchProcessor_L3PHIC(
    BXType bx,
    const TrackletProjectionMemory<BARRELPS> projin[L3PHICmaxTrackletProjections],
    const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARRELPS>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHICmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
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

MP_L3PHIC: MatchProcessor<BARRELPS, BARRELPS, BARREL, BARRELPS, BARRELPS, BARREL, L3PHICmaxTrackletProjections, L3PHICmaxFullMatchCopies,
 TF::L3, TF::D1, MC::C> (
    bx,
    projin,
    instubdata,
    allstub,
    bx_o,
    fullmatch
  );
}

void MatchProcessor_L4PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L4PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIBmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
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

MP_L4PHIB: MatchProcessor<BARREL2S, BARREL2S, BARREL, BARREL2S, BARREL2S, BARREL, L4PHIBmaxTrackletProjections, L4PHIBmaxFullMatchCopies,
 TF::L4, TF::D1, MC::B> (
    bx,
    projin,
    instubdata,
    allstub,
    bx_o,
    fullmatch
  );
}

void MatchProcessor_L5PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L5PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIBmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
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

MP_L5PHIB: MatchProcessor<BARREL2S, BARREL2S, BARREL, BARREL2S, BARREL2S, BARREL, L5PHIBmaxTrackletProjections, L5PHIBmaxFullMatchCopies,
 TF::L5, TF::D1, MC::B> (
    bx,
    projin,
    instubdata,
    allstub,
    bx_o,
    fullmatch
  );
}

void MatchProcessor_L6PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L6PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIBmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
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

MP_L6PHIB: MatchProcessor<BARREL2S, BARREL2S, BARREL, BARREL2S, BARREL2S, BARREL, L6PHIBmaxTrackletProjections, L6PHIBmaxFullMatchCopies,
 TF::L6, TF::D1, MC::B> (
    bx,
    projin,
    instubdata,
    allstub,
    bx_o,
    fullmatch
  );
}

////////////////////////////////////////////////////////////////////////////////
