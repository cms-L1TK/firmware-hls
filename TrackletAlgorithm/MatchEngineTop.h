#ifndef TrackletAlgorithm_MatchEngineTop_h
#define TrackletAlgorithm_MatchEngineTop_h

#include "MatchEngine.h"

void MatchEngineTop(const BXType bx, BXType& bx_o,
					const VMStubMEMemory<MODULETYPE, NBITBIN>& inputStubData,
					const VMProjectionMemory<PROJECTIONTYPE>& inputProjectionData,
					CandidateMatchMemory& outputCandidateMatch);

#endif