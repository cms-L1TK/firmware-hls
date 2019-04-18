#ifndef MATCHCALCULATORTOP_H
#define MATCHCALCULATORTOP_H

#include "MatchCalculator.hh"
//#include "MatchCalculator_new.hh"
//#include "MatchCalculator_new_noinline.hh"
//#include "MatchCalculator_loop_v2.hh"
//#include "MatchCalculator_loop_wo_bestmatch.hh"
//#include "MatchCalculator_loop_v3.hh"
//#include "MatchCalculator_loop.hh"
//#include "MatchCalculator_dataflow.hh"
//#include "MatchCalculator_blah.hh"
//#include "MatchCalculator_cp.hh"
//#include "testmerger.hh"
//#include "testmerger_v2.hh"

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
