#include "VMRouterTop_D1PHIA.h"

// VMRouter Top Function for Disk 1, AllStub region A
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: To run this VMR, change the following
//          - the included top function in VMRouter_test.cpp to "#include "VMRouterTop_D1PHIA.h""
//          - the top function in script_VMR.tcl to "add_files ../TrackletAlgorithm/VMRouterTop_D1PHIA.cc -cflags "$CFLAGS""
//          - the memory directory in script_VMR.tcl "to add_files -tb ../emData/VMR/VMR_D1PHIA/"


void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<inputType> inputStub[numInputs],
	const InputStubMemory<DISK2S> inputStubDisk2S[numInputsDisk2S], // Only disks has 2S modules
	// Output memories
	AllStubMemory<outputType> memoriesAS[maxASCopies],
	VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME],
	VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies],
	VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies])
 {

	///////////////////////////
	// Open Lookup tables

	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
	static const int fineBinTable[] =
#include "../emData/VMR/tables/VMR_D1PHIA_finebin.tab"
	;

	// LUT with phi corrections to project the stub to the nominal radius.
	// Only used by layers.
	// Indexed using phi and bend bits
	// static const int phiCorrtTable[bendCutTableSize] =
	// #include "../emData/VMR/tables/VMPhiCorrXX.tab"


	// LUT with the Z/R bits for TE memories
	// Contain information about where in z to look for valid stub pairs
	// Indexed using z and r position bits

	static const int rzBitsInnerTable[] = // 11 bits used for LUT
#include "../emData/VMR/tables/VMTableInnerD1D2.tab"

// 	static const int rzBitsOverlapTable[] = // 11 bits used for LUT
// #include "../emData/VMR/tables/VMTableInnerLXDX.tab"

	static const int rzBitsOuterTable[] = // 11 bits used for LUT
#include "../emData/VMR/tables/VMTableOuterD1.tab"


	// LUT with bend-cuts for the TE memories
	// The cuts are different depending on the memory version (nX)
	// Indexed using bend bits
	// Note: use an array of zeros for "missing" memories in the first and last Phi Region

	// TE Memory 1
	ap_uint<1> tmpBendInnerTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA1n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA1n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable1_n3[bendCutTableSize] = {0};

	// TE Memory 2
	ap_uint<1> tmpBendInnerTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n3_vmbendcut.tab"

	// TE Memory 3
	ap_uint<1> tmpBendInnerTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n3_vmbendcut.tab"

	// TE Memory 4
	ap_uint<1> tmpBendInnerTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n1_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n2_vmbendcut.tab"

	ap_uint<1> tmpBendInnerTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n3_vmbendcut.tab"


	// Combine all the temporary tables into one big table
	static const ap_uint<bendCutTableSize> bendCutInnerTable[] = {
		arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3),
		arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3)};


	// TE Outer Memory 1
	ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n1_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n2_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n3_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable1_n4[bendCutTableSize] = {0};

	ap_uint<1> tmpBendOuterTable1_n5[bendCutTableSize] = {0};

	// TE Overlap Memory 2
	ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n1_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n2_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n3_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n4_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable2_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n5_vmbendcut.tab"

	// TE Overlap Memory 3
	ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n1_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n2_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n3_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable3_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n4_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable3_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n5_vmbendcut.tab"

	// TE Overlap Memory 4
	ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n1_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n2_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n3_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable4_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n4_vmbendcut.tab"

	ap_uint<1> tmpBendOuterTable4_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n5_vmbendcut.tab"

	// Combine all the temporary Outer tables into one big table
	static const ap_uint<bendCutTableSize> bendCutOuterTable[] = {
		arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n5),
		arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n5),
		arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n5),
		arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n5)};


// Takes 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=inputStub[0].get_mem() latency=2
#pragma HLS resource variable=inputStub[1].get_mem() latency=2
#pragma HLS resource variable=inputStub[2].get_mem() latency=2
#pragma HLS resource variable=inputStub[3].get_mem() latency=2
#pragma HLS resource variable=inputStubDisk2S[0].get_mem() latency=2
#pragma HLS resource variable=inputStubDisk2S[1].get_mem() latency=2

#pragma HLS resource variable=fineBinTable latency=2
#pragma HLS resource variable=rzBitsInnerTable latency=2
//#pragma HLS resource variable=rzBitsOverlapTable latency=2
#pragma HLS resource variable=rzBitsOuterTable latency=2

//phiCorrtTable and bendCutTable seems to be using LUTs as they relatively small?
//#pragma HLS resource variable=bendCutInnerTable latency=2
//#pragma HLS resource variable=bendCutOuterTable latency=2


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

	// template<regionType InType, regionType OutType, int Layer, int Disk, int MaxAllCopies, int MaxTEICopies, int MaxOLCopies, int MaxTEOCopies>
	VMRouter<inputType, outputType, kLAYER, kDISK,  maxASCopies, maxTEICopies, maxOLCopies, maxTEOCopies, nbitsbin, bendCutTableSize>
	(bx, fineBinTable, nullptr,
		rzBitsInnerTable, nullptr, rzBitsOuterTable,
		bendCutInnerTable, nullptr, bendCutOuterTable,
		// Input memories
		maskIS, inputStub, inputStubDisk2S,
		// AllStub memories
		memoriesAS,
		// ME memories
		maskME, memoriesME,
		// TEInner memories
		maskTEI, memoriesTEI,
		// TEInner Overlap memories
		maskOL, nullptr,
		// TEOuter memories
		maskTEO, memoriesTEO
		);

	return;
}
