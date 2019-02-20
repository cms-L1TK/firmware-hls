#ifndef MATCHCALCULATORTOP_H
#define MATCHCALCULATORTOP_H

#include "MatchCalculator.hh"

void MatchCalculatorTop(BXType bx,
                        const CandidateMatchMemory* const,
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const, 
                        const CandidateMatchMemory* const,
                        const AllStubMemory<BARRELPS>* const,
                        const AllProjectionMemory<BARRELPS>* const,
                        BXType&,
                        FullMatchMemory<BARREL>* const,
                        FullMatchMemory<BARREL>* const
                       );

#endif
