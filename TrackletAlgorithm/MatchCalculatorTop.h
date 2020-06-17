#ifndef TrackletAlgorithm_MatchCalculatorTop_h
#define TrackletAlgorithm_MatchCalculatorTop_h

#include "MatchCalculator.h"

void MatchCalculatorTop(BXType bx,
                        const CandidateMatchMemory*,
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*, 
                        const CandidateMatchMemory*,
                        const AllStubMemory<BARRELPS>*,
                        const AllProjectionMemory<BARRELPS>*,
                        BXType&,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*,
                        FullMatchMemory<BARREL>*
                       );

#endif
