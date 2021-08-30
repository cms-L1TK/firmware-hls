#include "MatchCalculatorTop.h"

////////////////////////////////////////////////////////////////////////////////
// Top functions for various MatchCalculators (MC). For each iteration of
// the main processing loop, a MC retrieves an array of Candidate Matches,
// and computes Full Matches from each.
////////////////////////////////////////////////////////////////////////////////

void MatchCalculator_L3PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=match[4].get_mem() latency=2
#pragma HLS resource variable=match[5].get_mem() latency=2
#pragma HLS resource variable=match[6].get_mem() latency=2
#pragma HLS resource variable=match[7].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L3PHIB: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L3, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L3PHIC(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=match[4].get_mem() latency=2
#pragma HLS resource variable=match[5].get_mem() latency=2
#pragma HLS resource variable=match[6].get_mem() latency=2
#pragma HLS resource variable=match[7].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L3PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L3, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L4PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=match[4].get_mem() latency=2
#pragma HLS resource variable=match[5].get_mem() latency=2
#pragma HLS resource variable=match[6].get_mem() latency=2
#pragma HLS resource variable=match[7].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L4PHIB: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L4, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L5PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=match[4].get_mem() latency=2
#pragma HLS resource variable=match[5].get_mem() latency=2
#pragma HLS resource variable=match[6].get_mem() latency=2
#pragma HLS resource variable=match[7].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L5PHIB: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L5, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L6PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=match[4].get_mem() latency=2
#pragma HLS resource variable=match[5].get_mem() latency=2
#pragma HLS resource variable=match[6].get_mem() latency=2
#pragma HLS resource variable=match[7].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L6PHIB: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L6, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

////////////////////////////////////////////////////////////////////////////////
