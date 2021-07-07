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

MC_L3PHIB: MatchCalculator<MC::ASRegion<TF::L3>(), MC::APRegion<TF::L3>(), MC::FMRegion<TF::L3>(), 8, 8,
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

MC_L3PHIC: MatchCalculator<MC::ASRegion<TF::L3>(), MC::APRegion<TF::L3>(), MC::FMRegion<TF::L3>(), 8, 8,
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

MC_L4PHIB: MatchCalculator<MC::ASRegion<TF::L4>(), MC::APRegion<TF::L4>(), MC::FMRegion<TF::L4>(), 8, 8,
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

MC_L5PHIB: MatchCalculator<MC::ASRegion<TF::L5>(), MC::APRegion<TF::L5>(), MC::FMRegion<TF::L5>(), 8, 8,
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

MC_L6PHIB: MatchCalculator<MC::ASRegion<TF::L6>(), MC::APRegion<TF::L6>(), MC::FMRegion<TF::L6>(), 8, 8,
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
