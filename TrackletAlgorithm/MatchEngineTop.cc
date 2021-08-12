#include "MatchEngineTop.h"

void MatchEngineTop(const BXType bx, BXType& bx_o,
					const VMStubMEMemory<kModuleType, kNBitBin>& inputStubData,
					const VMProjectionMemory<kProjectionType>& inputProjectionData,
					CandidateMatchMemory& outputCandidateMatch) {

#ifdef  __VITIS_HLS__
    // For use with Vitis >=2020.1
    #pragma HLS LATENCY min=1 max=1
    #pragma HLS interface ap_memory port=inputStubData->get_mem() latency=2
    #pragma HLS interface ap_memory port=inputProjectionData->get_mem() latency=2
#else
	#pragma HLS interface register port=bx_o
    #pragma HLS resource variable=inputStubData->get_mem() latency=2
    #pragma HLS resource variable=inputProjectionData->get_mem() latency=2
#endif

	MatchEngine<LayerDisk,kModuleType,kProjectionType>(bx, bx_o, inputStubData, inputProjectionData, outputCandidateMatch);
}
