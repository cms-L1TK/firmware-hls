#include "MatchEngineTopL1.h"

void MatchEngineTopL1(const ap_uint<3> bx,
		      const VMStubMEMemory<BARRELPS>* const instubdata,
		      const VMProjectionMemory<BARREL>* const inprojdata,
		      CandidateMatchMemory* const outcandmatch){
  

  MatchEngine<1,BARRELPS>(bx,
		 instubdata,
		 inprojdata,
		 outcandmatch);
  
}

