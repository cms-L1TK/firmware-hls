#include "VMRouterTop.h"

// VMRouter Top Function for layer 1, AllStub region E
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTop.h
//          - the input parameters to VMRouterTop in VMRouterTop.h/.cc
//          - the the number and directories to the LUTs
//          - add/remove pragmas depending on inputStub in VMRouterTop.cc
//          - the call to VMRouter() in VMRouterTop.cc
//          - the included top function in VMRouter_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean


void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<inputType> inputStub[numInputs],

	// Output memories
	AllStubMemory<outputType> memoriesAS[maxASCopies],
	VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME],
	VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies],
	VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies])
 {


	///////////////////////////
	// Open Lookup tables
	// NOTE: needs to be changed manually if run for a different phi region

	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
	static const int fineBinTable[] =
#include "../emData/VMR/tables/VMR_L1PHIE_finebin.tab"


	// LUT with phi corrections to project the stub to the average radius in a layer.
	// Only used by layers.
	// Indexed using phi and bend bits
	static const int phiCorrTable[] =
#include "../emData/VMR/tables/VMPhiCorrL1.tab"


	// LUT with the Z/R bits for TE memories
	// Contain information about where in z to look for valid stub pairs
	// Indexed using z and r position bits

	static const int rzBitsInnerTable[] =
#include "../emData/VMR/tables/VMTableInnerL1L2.tab" // 11 bits used for LUT

	static const int rzBitsOverlapTable[] = // 11 bits used for LUT
#include "../emData/VMR/tables/VMTableInnerL1D1.tab"

// 	static const int rzBitsOuterTable[] = // 11 bits used for LUT
// #include "../emData/VMR/tables/VMTableOuterXX.tab"


	// LUT with bend-cuts for the TE memories
	// The cuts are different depending on the memory version (nX)
	// Indexed using bend bits
	// Note: use an array of zeros for "missing" memories in the first and last Phi Region

	// TE Memory 1
	ap_uint<1> tmpBendInnerTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n3_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n4_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n5_vmbendcut.tab"

	// TE Memory 2
	ap_uint<1> tmpBendInnerTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n3_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n4_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n5_vmbendcut.tab"

	// TE Memory 3
	ap_uint<1> tmpBendInnerTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n3_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n4_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n5_vmbendcut.tab"

// TE Memory 4
	ap_uint<1> tmpBendInnerTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n3_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n4_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n5_vmbendcut.tab"

	// Combine all the temporary tables into one big table
	static const ap_uint<bendCutTableSize> bendCutInnerTable[] = {
		arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n5),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n5),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n5),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n5)};


	// TE Overlap Memory 1
	ap_uint<1> tmpBendOverlapTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n1_vmbendcut.tab"

	ap_uint<1> tmpBendOverlapTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n2_vmbendcut.tab"

	ap_uint<1> tmpBendOverlapTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n3_vmbendcut.tab"

	// TE Overlap Memory 2
	ap_uint<1> tmpBendOverlapTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n1_vmbendcut.tab"

	ap_uint<1> tmpBendOverlapTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n2_vmbendcut.tab"

	ap_uint<1> tmpBendOverlapTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n3_vmbendcut.tab"

	// Combine all the temporary Overlap tables into one big table
	static const ap_uint<bendCutTableSize> bendCutOverlapTable[] = {
		arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n3),
		arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n3)};

// Takes 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=inputStub[0].get_mem() latency=2
#pragma HLS resource variable=inputStub[1].get_mem() latency=2
#pragma HLS resource variable=inputStub[2].get_mem() latency=2
#pragma HLS resource variable=inputStub[3].get_mem() latency=2

#pragma HLS resource variable=fineBinTable latency=2
#pragma HLS resource variable=rzBitsInnerTable latency=2
#pragma HLS resource variable=rzBitsOverlapTable latency=2
#pragma HLS resource variable=rxBitsOuterTable latency=2

// phiCorrTable and bendCutTable seems to be using LUTs as they relatively small?
// #pragma HLS resource variable=bendCutInnerTable latency=2
// #pragma HLS resource variable=bendCutOverlapTable latency=2



	//////////////////////////////////
	// Create memory masks

	// Masks of which memories that are being used. The first memory is represented by the LSB
	// and a "1" implies that the specified memory is used for this phi region
	// Create "nvm" 1s, e.g. "1111", shift the mask until it corresponds to the correct phi region
	static const ap_uint<maskISsize> maskIS = ((1 << numInputs) - 1); // Input memories
	static const ap_uint<maskMEsize> maskME = ((1 << nvmME) - 1) << (nvmME * (phiRegion - 'A')); // ME memories
	static const ap_uint<maskTEIsize> maskTEI =
		(kLAYER == 1 || kLAYER  == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3) ?
				((1 << nvmTEI) - 1) << (nvmTEI * (phiRegion - 'A')) : 0x0; // TE Inner memories, only used for odd layers/disk and layer 2
	static const ap_uint<maskOLsize> maskOL =
		((kLAYER == 1) || (kLAYER == 2)) ?
				((1 << nvmOL) - 1) << (nvmOL * (phiRegion - 'A')) : 0x0; // TE Inner Overlap memories, only used for layer 1 and 2
	static const ap_uint<maskTEOsize> maskTEO =
		(kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4) ?
				((1 << nvmTEO) - 1) << (nvmTEO * (phiRegion - 'A')) : 0x0; // TE Outer memories, only for even layers/disks, and layer and disk 1


	/////////////////////////
	// Main function

	VMRouter<inputType, outputType, kLAYER, kDISK,  maxASCopies, maxTEICopies, maxOLCopies, maxTEOCopies, nbitsbin, bendCutTableSize>
	(bx, fineBinTable, phiCorrTable,
		rzBitsInnerTable, rzBitsOverlapTable, nullptr,
		bendCutInnerTable, bendCutOverlapTable, nullptr,
		// Input memories
		maskIS, inputStub, nullptr,
		// AllStub memories
		memoriesAS,
		// ME memories
		maskME, memoriesME,
		// TEInner memories
		maskTEI, memoriesTEI,
		// TEInner Overlap memories
		maskOL, memoriesOL,
		// TEOuter memories
		maskTEO, nullptr
		);

	return;
}
