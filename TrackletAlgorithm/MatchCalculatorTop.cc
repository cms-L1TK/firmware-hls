#include "MatchCalculatorTop.h"

void MatchCalculatorTop(BXType bx,
                        const CandidateMatchMemory match[maxMatchCopies],
                        const AllStubMemory<BARRELPS>* allstub,
                        const AllProjectionMemory<BARRELPS>* allproj,
                        BXType& bx_o,
                        FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
                        )
{
 #pragma HLS inline off
 #pragma HLS interface register port=bx_o
 #pragma HLS resource variable=match.get_mem() latency=2
 #pragma HLS resource variable=allstub->get_mem() latency=2
 #pragma HLS resource variable=allproj->get_mem() latency=2

  const auto LAYER  = 3;
  const auto DISK   = 0;
  const auto PHISEC = 2;
  MC_L3PHIC: MatchCalculator<BARRELPS, BARRELPS, BARREL, maxMatchCopies, maxFullMatchCopies, LAYER, DISK, PHISEC>
    (
      bx,
      match,
      allstub, allproj, bx_o,
      fullmatch
    );

} 
