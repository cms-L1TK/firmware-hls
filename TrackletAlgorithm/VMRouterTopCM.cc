#include "VMRouterTopCM.h"

// VMRouter Top Function for layer 2, AllStub region A
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTopCM.h
//          - the input parameters to VMRouterTopCM in VMRouterTopCM.h/.cc
//          - add/remove pragmas depending on inputStubs in VMRouterTopCM.cc
//          - the call to VMRouterCM() in VMRouterTopCM.cc
//          - the included top function in VMRouterCM_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR_CM.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean


void VMRouterTopCM(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 // Add layers/disks
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType,rzSizeTE,phiRegSize,numTEOCopies> *memoryTEO
#endif
 ) {


	///////////////////////////
	// Open Lookup tables
	// NOTE: needs to be changed manually if run for a different phi region

	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
#if kLAYER == 1
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L1.tab"
#elif kLAYER == 2
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L2.tab"
#elif kLAYER == 3
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L3.tab"
#elif kLAYER == 4
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L4.tab"
#elif kLAYER == 5
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L5.tab"
#elif kLAYER == 6
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_L6.tab"
#elif kDISK == 1
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_D1.tab"
#elif kDISK == 2
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_D2.tab"
#elif kDISK == 3
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_D3.tab"
#elif kDISK == 4
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_D4.tab"
#elif kDISK == 5
		static const int METable[] =
	#include "../emData/VMRCM/tables/VMRME_D5.tab"
#endif

#if kDISK == 1
		static const int TEDiskTable[] =
	#include "../emData/VMRCM/tables/VMRTE_D1.tab"
#elif kDISK == 2
		static const int TEDiskTable[] =
	#include "../emData/VMRCM/tables/VMRTE_D2.tab"
#elif kDISK == 4
		static const int TEDiskTable[] =
	#include "../emData/VMRCM/tables/VMRTE_D4.tab"
#endif

	// LUT with phi corrections to project the stub to the average radius in a layer.
	// Only used by layers.
	// Indexed using phi and bend bits
#if kLAYER == 1
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL1.tab"
#elif kLAYER == 2
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL2.tab"
#elif kLAYER == 3
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL3.tab"
#elif kLAYER == 4
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL4.tab"
#elif kLAYER == 5
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL5.tab"
#elif kLAYER == 6
		static const int phiCorrTable[] =
	#include "../emData/VMRCM/tables/VMPhiCorrL6.tab"
#endif

// // Takes 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=inputStubs[0].get_mem() latency=2
#pragma HLS resource variable=inputStubs[1].get_mem() latency=2
// #pragma HLS resource variable=inputStubs[2].get_mem() latency=2
// #pragma HLS resource variable=inputStubs[3].get_mem() latency=2


	//////////////////////////////////
	// Create memory masks

	// Masks of which memories that are being used. The first memory is represented by the LSB
	// and a "1" implies that the specified memory is used for this phi region
	// First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
	// NOTE: read from right to left
	static const ap_uint<maskASIsize> maskASI = 0b000111000000;//0b110110000000;


	/////////////////////////
	// Main function

	VMRouterCM<numInputs, numInputsDisk2S, numASCopies, numASInnerCopies, kLAYER, kDISK, inputType, outputType, rzSizeME, rzSizeTE, phiRegSize, numTEOCopies>
	(bx, bx_o, METable,
#if kDISK == 1 || kDISK == 2 || kDISK == 4
		TEDiskTable,
#else
		nullptr,
#endif
#if kDISK > 0
		nullptr,
#else
		phiCorrTable,
#endif
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
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 // Add layers/disks
		memoriesASInner,
#else
		nullptr,
#endif
		// ME memories
		memoryME,
		// TEOuter memories
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
		memoryTEO
#else
		nullptr
#endif
		);

	return;
}
