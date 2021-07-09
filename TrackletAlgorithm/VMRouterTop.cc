#include "VMRouterTop.h"

// VMRouter Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// To run a different phi region, change the following:
//          - add the phi region in emData/download.sh, make sure to also run clean
//
//          - kLAYER, kDISK, and phiRegion in VMRouterTop.h
//          - add corresponding magic numbers to VMRouter_parameters.h if not already defined
//          - add/remove pragmas depending on inputStubs in VMRouterTop.cc (not necessary to run simulation)
//          OR
//          - run emData/generate_VMR.py to generate new top and parameters files
void VMRouterTop(const BXType bx, BXType& bx_o,
	// Input memories
	const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
	, const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif
	// Output memories
	, AllStubMemory<outputType> memoriesAS[maxASCopies]
	, VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
	, VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies]
#endif
#if kLAYER == 1 || kLAYER == 2
	, VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies]
#endif
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies]
#endif
) {
// Takes 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=inputStubs[0].get_mem() latency=2
#pragma HLS resource variable=inputStubs[1].get_mem() latency=2

#pragma HLS interface register port=bx_o
	///////////////////////////
	// Open Lookup tables
	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
	static const int* fineBinTable = getFineBinTable<layerdisk, phiRegion>();
	// LUT with phi corrections to project the stub to the average radius in a layer.
	// Only used by layers.
	// Indexed using phi and bend bits
	static const int* phiCorrTable = getPhiCorrTable<layerdisk>();
	// LUT with the Z/R bits for TE memories
	// Contain information about where in z to look for valid stub pairs
	// Indexed using z and r position bits
	static const int* rzBitsInnerTable = getRzBitsInnerTable<layerdisk>();
	static const int* rzBitsOverlapTable = getRzBitsOverlapTable<layerdisk>();
	static const int* rzBitsOuterTable = getRzBitsOuterTable<layerdisk>();
	// LUT with bend-cuts for the TE memories
	// The cuts are different depending on the memory version (nX)
	// Indexed using bend bits
	// Note: use an array of zeros for "missing" memories in the first and last Phi Region
	static const ap_uint<bendCutTableSize>* bendCutInnerTable = getBendCutInnerTable<layerdisk, phiRegion, bendCutTableSize>();
	static const ap_uint<bendCutTableSize>* bendCutOverlapTable = getBendCutOverlapTable<layerdisk, phiRegion, bendCutTableSize>();
	static const ap_uint<bendCutTableSize>* bendCutOuterTable = getBendCutOuterTable<layerdisk, phiRegion, bendCutTableSize>();
	//////////////////////////////////
	// Create memory masks
	// Masks of which memories that are being used. The first memory is represented by the LSB
	// and a "1" implies that the specified memory is used for this phi region
	// Create "nvm" 1s, e.g. "1111", shift the mask until it corresponds to the correct phi region
	static const ap_uint<maskMEsize> maskME = ((1 << nvmME) - 1) << (nvmME * (static_cast<char>(phiRegion) - 'A')); // ME memories
	static const ap_uint<maskTEIsize> maskTEI =
		(kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3) ?
				((1 << nvmTEI) - 1) << (nvmTEI * (static_cast<char>(phiRegion) - 'A')) : 0x0; // TE Inner memories, only used for odd layers/disk and layer 2
	static const ap_uint<maskOLsize> maskOL =
		((kLAYER == 1) || (kLAYER == 2)) ?
				((1 << nvmOL) - 1) << (nvmOL * (static_cast<char>(phiRegion) - 'A')) : 0x0; // TE Inner Overlap memories, only used for layer 1 and 2
	static const ap_uint<maskTEOsize> maskTEO =
		(kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4) ?
				((1 << nvmTEO) - 1) << (nvmTEO * (static_cast<char>(phiRegion) - 'A')) : 0x0; // TE Outer memories, only for even layers/disks, and layer and disk 1
	/////////////////////////
	// Main function
	VMRouter<inputType, outputType, kLAYER, kDISK, numInputs, numInputsDisk2S, maxASCopies, maxTEICopies, maxOLCopies, maxTEOCopies, nbitsbin, bendCutTableSize>
	(bx, bx_o, fineBinTable, phiCorrTable,
		rzBitsInnerTable, rzBitsOverlapTable, rzBitsOuterTable,
		bendCutInnerTable, bendCutOverlapTable, bendCutOuterTable,
		// Input memories
		inputStubs,
#if kDISK > 0
		inputStubsDisk2S,
#else
		nullptr,
#endif
		// AllStub memories
		memoriesAS,
		// ME memories
		maskME, memoriesME,
		// TEInner memories
		maskTEI,
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
		memoriesTEI,
#else
		nullptr,
#endif
		// TEInner Overlap memories
		maskOL, 
#if kLAYER == 1 || kLAYER == 2
		memoriesOL,
#else
		nullptr,
#endif
		// TEOuter memories
		maskTEO, 
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
		memoriesTEO
#else
		nullptr
#endif
		);
	return;
}
