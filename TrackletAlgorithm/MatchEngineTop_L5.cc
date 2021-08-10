#include "MatchEngineTop_L5.h"

void MatchEngineTop_L5(const BXType bx, BXType& bx_o,
					const VMStubMEMemory<MODULETYPE, NBITBIN>& inputStubData,
					const VMProjectionMemory<PROJECTIONTYPE>& inputProjectionData,
					CandidateMatchMemory& outputCandidateMatch) {

#pragma HLS interface register port=bx_o
#ifdef  __VITIS_HLS__
    // For use with Vitis >=2020.1
    #pragma HLS interface ap_memory port=inputStubData->get_mem() latency=2
    #pragma HLS interface ap_memory port=inputProjectionData->get_mem() latency=2
#else
    #pragma HLS resource variable=inputStubData->get_mem() latency=2
    #pragma HLS resource variable=inputProjectionData->get_mem() latency=2
#endif

	MatchEngine<LAYER,MODULETYPE,PROJECTIONTYPE>(bx, bx_o, inputStubData, inputProjectionData, outputCandidateMatch); 
}
