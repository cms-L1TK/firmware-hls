#ifndef MATCHENGINETOPL3_H
#define MATCHENGINETOPL3_H

#include "MatchEngine.h"

void MatchEngineTopL3(BXType bx,
		      BXType& bx_o,
		      const VMStubMEMemory<BARRELPS>* instubdata,
		      const VMProjectionMemory<BARREL>* inprojdata,
		      CandidateMatchMemory* outcandmatch);


#endif
