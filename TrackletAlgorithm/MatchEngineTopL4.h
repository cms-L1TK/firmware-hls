#ifndef MATCHENGINETOPL4_H
#define MATCHENGINETOPL4_H

#include "MatchEngine.h"

void MatchEngineTopL4(const ap_uint<3> bx,
		      const VMStubMEMemory<BARREL2S>* const instubdata,
		      const VMProjectionMemory<BARREL>* const inprojdata,
		      CandidateMatchMemory* const outcandmatch);

#endif
