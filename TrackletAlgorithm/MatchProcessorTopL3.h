#ifndef MATCHENGINETOPL3_H
#define MATCHENGINETOPL3_H

#include "MatchProcessor.h"

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
                      const VMStubMEMemory<BARRELPS,3> instubdata[maxInCopies],
                      const VMStubMEMemory<BARRELPS,3>* instubdata1,
                      const VMStubMEMemory<BARRELPS,3>* instubdata2,
                      const VMStubMEMemory<BARRELPS,3>* instubdata3,
                      const VMStubMEMemory<BARRELPS,3>* instubdata4,
                      const VMStubMEMemory<BARRELPS,3>* instubdata5,
                      const VMStubMEMemory<BARRELPS,3>* instubdata6,
                      const VMStubMEMemory<BARRELPS,3>* instubdata7,
                      const VMStubMEMemory<BARRELPS,3>* instubdata8,
                      const AllStubMemory<BARRELPS>* allstub,
                      const AllProjectionMemory<BARRELPS>* allproj,
                      BXType& bx_o,
                      FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies],
                      FullMatchMemory<BARREL>* fullmatch1,
                      FullMatchMemory<BARREL>* fullmatch2,
                      FullMatchMemory<BARREL>* fullmatch3,
                      FullMatchMemory<BARREL>* fullmatch4,
                      FullMatchMemory<BARREL>* fullmatch5,
                      FullMatchMemory<BARREL>* fullmatch6,
                      FullMatchMemory<BARREL>* fullmatch7,
                      FullMatchMemory<BARREL>* fullmatch8);

#endif
