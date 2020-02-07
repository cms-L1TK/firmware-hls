#include "MatchEngineTopL3.h"

void MatchEngineTopL3(BXType bx,
		      BXType& bx_o,
		      const VMStubMEMemory<BARRELPS>* instubdata,
		      const VMProjectionMemory<BARREL>* inprojdata,
		      CandidateMatchMemory* outcandmatch){

#pragma HLS interface register port=bx_o
//#pragma HLS resource variable=instubdata latency=2
//#pragma HLS resource variable=inprojdata latency=2

  MatchEngine<3,BARRELPS>(bx,
			  bx_o,
			  instubdata,
			  inprojdata,
			  outcandmatch);
  
}

