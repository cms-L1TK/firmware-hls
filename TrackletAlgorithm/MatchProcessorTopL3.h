#ifndef MATCHENGINETOPL3_H
#define MATCHENGINETOPL3_H

#include "MatchProcessor.h"

constexpr int maxTrackletProjections(10);
constexpr int maxFullMatchCopies(8);

void MatchProcessorTopL3(BXType bx,
                         const TrackletProjectionMemory<BARRELPS> projin[maxTrackletProjections],
                         const VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines>& instubdata,
                         const AllStubMemory<BARRELPS>* allstub,
                         BXType& bx_o,
                         FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]);

#endif
