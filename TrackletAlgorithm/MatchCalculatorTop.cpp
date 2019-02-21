#include "MatchCalculatorTop.h"

void MatchCalculatorTop(BXType bx,
                        const CandidateMatchMemory* const match1,
                        const CandidateMatchMemory* const match2, 
                        const CandidateMatchMemory* const match3, 
                        const CandidateMatchMemory* const match4, 
                        const CandidateMatchMemory* const match5, 
                        const CandidateMatchMemory* const match6, 
                        const CandidateMatchMemory* const match7, 
                        const CandidateMatchMemory* const match8,
                        const AllStubMemory<BARRELPS>* const allstub,
                        const AllProjectionMemory<BARRELPS>* const allproj,
                        BXType& bx_o,
                        FullMatchMemory<BARREL>* const fullmatch1,
                        FullMatchMemory<BARREL>* const fullmatch2
                        )
{

  MC_L3PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 3, 0, 2>
    (
      bx,
      match1, match2, match3, match4, match5, match6, match7, match8,
      allstub, allproj, 
      bx_o, fullmatch1, fullmatch2
    );

} 
