#ifndef TrackletAlgorithm_MatchEngineTop_h
#define TrackletAlgorithm_MatchEngineTop_h

#include "MatchEngine.h"

void MatchEngineTop(const BXType bx, BXType& bx_o,
					const VMStubMEMemory<kModuleType, kNBitBin>& inputStubData,
					const VMProjectionMemory<kProjectionType>& inputProjectionData,
					CandidateMatchMemory& outputCandidateMatch);

#endif
