#include "VMRouterCMTop.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// To run a different phi region, change the following:
//          - add the phi region in emData/download.sh, make sure to also run clean
//
//          - kLAYER, kDISK, and phiRegion in VMRouterCMTop.h
//          - add corresponding magic numbers to VMRouterCM_parameters.h if not already defined
//          - add/remove pragmas depending on inputStubs in VMRouterCMTop.cc (not necessary to run simulation)
//          OR
//          - run emData/generateCM_VMR.py to generate new top and parameters files

void VMRouterCMTop(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize, kNMatchEngines> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType, rzSizeTE, phiRegSize, kNTEUnits> memoriesTEO[numTEOCopies]
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
	static const int* METable = getMETable<layerdisk>();
	static const int* TETable = getTETable<layerdisk>();

	// LUT with phi corrections to project the stub to the average radius in a layer.
	// Only used by layers.
	// Indexed using phi and bend bits
	static const int* phiCorrTable = getPhiCorrTable<layerdisk>();


	/////////////////////////
	// Main function

	VMRouterCM<numInputs, numInputsDisk2S, numASCopies, numASInnerCopies, kLAYER, kDISK, inputType, outputType, rzSizeME, rzSizeTE, phiRegSize, numTEOCopies>
	(bx, bx_o, 

		// LUTs
		METable,
		TETable,
		phiCorrTable,

		// Input memories
		inputStubs, 
#if kDISK > 0
		inputStubsDisk2S,
#else
		nullptr,
#endif

		// AllStub memories
		memoriesAS, 
		maskASI, 
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 || kDISK == 3
		memoriesASInner,
#else
		nullptr,
#endif

		// ME memories
		memoryME,

		// TEOuter memories
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
		memoriesTEO
#else
		nullptr
#endif
		);

	return;
}
