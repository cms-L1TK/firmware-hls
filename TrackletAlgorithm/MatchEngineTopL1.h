#ifndef MATCHENGINETOPL1_H
#define MATCHENGINETOPL1_H

#include "MatchEngine.h"

void MatchEngineTopL1(const ap_uint<3> bx,
		      const VMStubMEMemory<BARRELPS>* const instubdata,
		      const VMProjectionMemory<BARREL>* const inprojdata,
		      CandidateMatchMemory* const outcandmatch);


#endif
