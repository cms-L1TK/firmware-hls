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
                        FullMatchMemory<BARREL>* fullmatch7,
                        FullMatchMemory<BARREL>* fullmatch8
                        )
{
 #pragma HLS inline off
 #pragma HLS interface register port=bx_o
 #pragma HLS resource variable=match1->get_mem() latency=2
 #pragma HLS resource variable=match2->get_mem() latency=2
 #pragma HLS resource variable=match3->get_mem() latency=2
 #pragma HLS resource variable=match4->get_mem() latency=2
 #pragma HLS resource variable=match5->get_mem() latency=2
 #pragma HLS resource variable=match6->get_mem() latency=2
 #pragma HLS resource variable=match7->get_mem() latency=2
 #pragma HLS resource variable=match8->get_mem() latency=2
 #pragma HLS resource variable=allstub->get_mem() latency=2
 #pragma HLS resource variable=allproj->get_mem() latency=2

  MC_L3PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, 3, 0, 2>
    (
      bx,
      match1, match2, match3, match4, match5, match6, match7, match8,
      allstub, allproj, bx_o,
      fullmatch1, fullmatch2, fullmatch3, fullmatch4, fullmatch5, fullmatch6, fullmatch7, fullmatch8
    );

} 
