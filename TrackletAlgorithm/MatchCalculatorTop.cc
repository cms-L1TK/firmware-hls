#include "MatchCalculatorTop.h"

////////////////////////////////////////////////////////////////////////////////
// Top functions for various MatchCalculators (MC). For each iteration of
// the main processing loop, a MC retrieves an array of Candidate Matches,
// and computes Full Matches from each.
////////////////////////////////////////////////////////////////////////////////

void MatchCalculator_L1PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIAmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIA: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::A> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIBmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIB: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L1PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHICmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHID(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIDmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHID: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIE(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIEmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIEmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIE: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::E> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIF(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIFmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIFmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIF: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::F> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIG(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIGmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIGmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIG: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::G> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L1PHIH(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIHmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIHmaxFullMatchCopies]
) {
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=match[0].get_mem() latency=2
#pragma HLS resource variable=match[1].get_mem() latency=2
#pragma HLS resource variable=match[2].get_mem() latency=2
#pragma HLS resource variable=match[3].get_mem() latency=2
#pragma HLS resource variable=allstub->get_mem() latency=2
#pragma HLS resource variable=allproj->get_mem() latency=2

MC_L1PHIH: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L1, TF::D1, MC::H> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L2PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIAmaxFullMatchCopies]
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

MC_L2PHIA: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L2, TF::D1, MC::A> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L2PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIBmaxFullMatchCopies]
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

MC_L2PHIB: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L2, TF::D1, MC::B> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L2PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L2PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHICmaxFullMatchCopies]
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

MC_L2PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L2, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L2PHID(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIDmaxFullMatchCopies]
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

MC_L2PHID: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L2, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L3PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIAmaxFullMatchCopies]
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

MC_L3PHIA: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L3, TF::D1, MC::A> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L3PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIBmaxFullMatchCopies]
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
    const CandidateMatchMemory match[L3PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHICmaxFullMatchCopies]
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

void MatchCalculator_L3PHID(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIDmaxFullMatchCopies]
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

MC_L3PHID: MatchCalculator<BARRELPS, BARRELPS, BARREL, 8, 8,
 TF::L3, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L4PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L4PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIAmaxFullMatchCopies]
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

MC_L4PHIA: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L4, TF::D1, MC::A> (
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
    const CandidateMatchMemory match[L4PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIBmaxFullMatchCopies]
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

void MatchCalculator_L4PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L4PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHICmaxFullMatchCopies]
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

MC_L4PHIC: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L4, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L4PHID(
    const BXType bx,
    const CandidateMatchMemory match[L4PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIDmaxFullMatchCopies]
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

MC_L4PHID: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L4, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L5PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L5PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIAmaxFullMatchCopies]
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

MC_L5PHIA: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L5, TF::D1, MC::A> (
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
    const CandidateMatchMemory match[L5PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIBmaxFullMatchCopies]
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

void MatchCalculator_L5PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L5PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHICmaxFullMatchCopies]
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

MC_L5PHIC: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L5, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L5PHID(
    const BXType bx,
    const CandidateMatchMemory match[L5PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIDmaxFullMatchCopies]
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

MC_L5PHID: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L5, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L6PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L6PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIAmaxFullMatchCopies]
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

MC_L6PHIA: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L6, TF::D1, MC::A> (
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
    const CandidateMatchMemory match[L6PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIBmaxFullMatchCopies]
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

void MatchCalculator_L6PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L6PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHICmaxFullMatchCopies]
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

MC_L6PHIC: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L6, TF::D1, MC::C> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

void MatchCalculator_L6PHID(
    const BXType bx,
    const CandidateMatchMemory match[L6PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIDmaxFullMatchCopies]
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

MC_L6PHID: MatchCalculator<BARREL2S, BARREL2S, BARREL, 8, 8,
 TF::L6, TF::D1, MC::D> (
    bx,
    match,
    allstub,
    allproj,
    bx_o,
    fullmatch
  );
}

////////////////////////////////////////////////////////////////////////////////
