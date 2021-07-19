#ifndef TrackAlgorithm_MatchProcessorTop_h
#define TrackAlgorithm_MatchProcessorTop_h

#include "MatchProcessor.h"


constexpr int L3PHIBmaxTrackletProjections(10);
constexpr int L3PHIBmaxFullMatchCopies(8);

void MatchProcessor_L3PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARRELPS> projin[L3PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARRELPS>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIBmaxFullMatchCopies]
);

constexpr int L3PHICmaxTrackletProjections(10);
constexpr int L3PHICmaxFullMatchCopies(8);

void MatchProcessor_L3PHIC(
    BXType bx,
    const TrackletProjectionMemory<BARRELPS> projin[L3PHICmaxTrackletProjections],
    const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARRELPS>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHICmaxFullMatchCopies]
);

constexpr int L4PHIBmaxTrackletProjections(13);
constexpr int L4PHIBmaxFullMatchCopies(8);

void MatchProcessor_L4PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L4PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIBmaxFullMatchCopies]
);

constexpr int L5PHIBmaxTrackletProjections(15);
constexpr int L5PHIBmaxFullMatchCopies(8);

void MatchProcessor_L5PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L5PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIBmaxFullMatchCopies]
);

constexpr int L6PHIBmaxTrackletProjections(12);
constexpr int L6PHIBmaxFullMatchCopies(8);

void MatchProcessor_L6PHIB(
    BXType bx,
    const TrackletProjectionMemory<BARREL2S> projin[L6PHIBmaxTrackletProjections],
    const VMStubMEMemoryCM<BARREL2S, 3, 3, kNMatchEngines>& instubdata,
    const AllStubMemory<BARREL2S>* allstub,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIBmaxFullMatchCopies]
);

#endif
