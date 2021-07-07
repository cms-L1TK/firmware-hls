#ifndef TrackAlgorithm_MatchCalculatorTop_h
#define TrackAlgorithm_MatchCalculatorTop_h

#include "MatchCalculator.h"

constexpr int maxMatchCopies(8);
constexpr int maxFullMatchCopies(8);

void MatchCalculator_L3PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
);

void MatchCalculator_L3PHIC(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
);

void MatchCalculator_L4PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
);

void MatchCalculator_L5PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
);

void MatchCalculator_L6PHIB(
    const BXType bx,
    const CandidateMatchMemory match[maxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
);

#endif
