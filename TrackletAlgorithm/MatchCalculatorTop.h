#ifndef MATCHCALCULATORTOP_H
#define MATCHCALCULATORTOP_H

#include "MatchCalculator.hh"

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
                        FullMatchMemory<BARREL>*
                       );

#endif
