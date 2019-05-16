#include "MatchCalculatorTop.h"

void MatchCalculatorTop(BXType bx,
                        const CandidateMatchMemory* match1,
                        const CandidateMatchMemory* match2, 
                        const CandidateMatchMemory* match3, 
                        const CandidateMatchMemory* match4, 
                        const CandidateMatchMemory* match5, 
                        const CandidateMatchMemory* match6, 
                        const CandidateMatchMemory* match7, 
                        const CandidateMatchMemory* match8,
                        const AllStubMemory<BARRELPS>* allstub,
                        const AllProjectionMemory<BARRELPS>* allproj,
                        BXType& bx_o,
                        FullMatchMemory<BARREL>* fullmatch1,
                        FullMatchMemory<BARREL>* fullmatch2,
                        FullMatchMemory<BARREL>* fullmatch3,
                        FullMatchMemory<BARREL>* fullmatch4,
                        FullMatchMemory<BARREL>* fullmatch5,
                        FullMatchMemory<BARREL>* fullmatch6,
                        FullMatchMemory<BARREL>* fullmatch7
                        )
{

  MC_L3PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 3, 0, 2>
    (
      bx,
      match1, match2, match3, match4, match5, match6, match7, match8,
      allstub, allproj, bx_o,
      fullmatch1, fullmatch2, fullmatch3, fullmatch4, fullmatch5, fullmatch6, fullmatch7
    );

} 
