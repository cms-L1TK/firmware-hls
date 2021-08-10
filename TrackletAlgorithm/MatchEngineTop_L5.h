#ifndef TrackletAlgorithm_MatchEngineTop_h
#define TrackletAlgorithm_MatchEngineTop_h

#define LAYER 5
#include "MatchEngine.h"

void MatchEngineTop_L5(const BXType bx, BXType& bx_o,
					const VMStubMEMemory<MODULETYPE, NBITBIN>& inputStubData,
					const VMProjectionMemory<PROJECTIONTYPE>& inputProjectionData,
					CandidateMatchMemory& outputCandidateMatch);

#endif
