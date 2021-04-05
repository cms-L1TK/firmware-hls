#ifndef MATCHENGINETOPL3_H
#define MATCHENGINETOPL3_H

#include "MatchProcessor.h"

constexpr int maxTrackletProjections(10);
constexpr int maxInCopies(8);
constexpr int maxFullMatchCopies(8);

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
                         FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]);

#endif
