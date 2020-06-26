#include "VMRouterTop.h"

// VMRouter Top Function for layer 1, AllStub region E
void VMRouterTop(BXType bx, 
	// Input memories
		const InputStubMemory<BARRELPS> inputStub[numInputs],
		// Output memories
		AllStubMemory<BARRELPS> allStub[maxAllCopies],
		VMStubMEMemory<BARRELPS, nbitsbin> meMemories[numME],
		VMStubTEInnerMemory<BARRELPS> teiMemories[numTEI][maxTEICopies],
		VMStubTEInnerMemory<BARRELOL> olMemories[numOL][maxOLCopies]) {

//////////////////////////////////
// Variables for that are specified with regards to the test bench

	constexpr int layer(1); // Which barrel layer number the data is coming from, 0 if not barrel
	constexpr int disk(0); // Which disk number the data is coming from, 0 if not disk
	
	// Masks of which memories that are being used. The first memory is represented by the LSB
	static const ap_uint<6> imask(0xF); // Input memories
	static const ap_uint<32> memask(0x000F0000UL); // ME memories
	static const ap_uint<32> teimask(0x000F0000UL); // TE Inner memories
	static const ap_uint<16> olmask(0x300); // TE Inner Overlap memories
	static const ap_uint<32> teomask(0x0); // TE Outer memories
	
	///////////////////////////
	// Open Lookup tables

	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
	static const int finebintable[] =
#include "../emData/VMR/tables/VMR_L1PHIE_finebin.tab"
	;

	// LUT with phi corrections to project the stub to the average radius in a layer. 
	// Only used by layers.
	// Indexed using phi and bend bits
	static const int phicorrtable[] =
#include "../emData/VMR/tables/VMPhiCorrL1.txt"
	;

	// LUT with the Z/R bits for TE memories
	// Contain information about where in z to look for valid stub pairs
	// Indexed using z and r position bits
	static const int rzbitstable[] =
#include "../emData/VMR/tables/VMTableInnerL1L2.tab" // Only for Layer 1
	;

	// LUT with the Z/R bits for TE Overlap memories
	// Only used for Layer 1 and 2, and Disk 1
	// Indexed using z and r position bits
	static const int rzbitsextratable[1024] =// 10 bits used for LUT
#include "../emData/VMR/tables/VMTableInnerL1D1.tab"
	;


	// LUT with bend-cuts for the TE memories
	// The cuts are different depending on the memory version (nX)
	// Indexed using bend bits
// TE Memory 1
	ap_uint<1> tmptable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n1_vmbendcut.tab"
	;

	ap_uint<1> tmptable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n2_vmbendcut.tab"
	;

	ap_uint<1> tmptable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n3_vmbendcut.tab"
	;

	ap_uint<1> tmptable1_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n4_vmbendcut.tab"
	;

	ap_uint<1> tmptable1_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n5_vmbendcut.tab"
	;

	// TE Memory 2
	ap_uint<1> tmptable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n1_vmbendcut.tab"
	;

	ap_uint<1> tmptable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n2_vmbendcut.tab"
	;

	ap_uint<1> tmptable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n3_vmbendcut.tab"
	;

	ap_uint<1> tmptable2_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n4_vmbendcut.tab"
	;

	ap_uint<1> tmptable2_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n5_vmbendcut.tab"
	;

	// TE Memory 3
	ap_uint<1> tmptable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n1_vmbendcut.tab"
	;

	ap_uint<1> tmptable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n2_vmbendcut.tab"
	;

	ap_uint<1> tmptable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n3_vmbendcut.tab"
	;

	ap_uint<1> tmptable3_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n4_vmbendcut.tab"
	;

	ap_uint<1> tmptable3_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n5_vmbendcut.tab"
	;

// TE Memory 4
	ap_uint<1> tmptable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n1_vmbendcut.tab"
	;

	ap_uint<1> tmptable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n2_vmbendcut.tab"
	;

	ap_uint<1> tmptable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n3_vmbendcut.tab"
	;

	ap_uint<1> tmptable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n4_vmbendcut.tab"
	;

	ap_uint<1> tmptable4_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n5_vmbendcut.tab"
	;
					
	static const ap_uint<1>* bendtable[] = {
		tmptable1_n1, tmptable1_n2, tmptable1_n3, tmptable1_n4, tmptable1_n5, 
		tmptable2_n1, tmptable2_n2, tmptable2_n3, tmptable2_n4, tmptable2_n5,
		tmptable3_n1, tmptable3_n2, tmptable3_n3, tmptable3_n4, tmptable3_n5,
		tmptable4_n1, tmptable4_n2, tmptable4_n3, tmptable4_n4, tmptable4_n5};


	// TE Overlap Memory 1
	ap_uint<1> tmpextratable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n1_vmbendcut.tab"
	;

	ap_uint<1> tmpextratable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n2_vmbendcut.tab"
	;

	ap_uint<1> tmpextratable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n3_vmbendcut.tab"
	;

	// TE Overlap Memory 2
	ap_uint<1> tmpextratable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n1_vmbendcut.tab"
	;

	ap_uint<1> tmpextratable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n2_vmbendcut.tab"
	;

	ap_uint<1> tmpextratable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n3_vmbendcut.tab"
		
	static const ap_uint<1>* bendextratable[] = {
		tmpextratable1_n1, tmpextratable1_n2, tmpextratable1_n3,
		tmpextratable2_n1, tmpextratable2_n2, tmpextratable2_n3}; // Only used for overlap


// Takes 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=inputStub[0].get_mem() latency=2
#pragma HLS resource variable=inputStub[1].get_mem() latency=2
#pragma HLS resource variable=inputStub[2].get_mem() latency=2
#pragma HLS resource variable=inputStub[3].get_mem() latency=2

#pragma HLS resource variable=finebintable latency=2
#pragma HLS resource variable=rzbitstable latency=2
#pragma HLS resource variable=rzbitsextratable latency=2
// #pragma HLS resource variable=bendtable latency=2
// #pragma HLS resource variable=bendextratable latency=2
// phicorrtable and bendtable seems to be using LUTs as they relatively small?
	

/////////////////////////
// Main function

	// template<regionType InType, regionType OutType, int Layer, int Disk, int MaxAllCopies, int MaxTEICopies, int MaxOLCopies, int MaxTEOCopies>
	VMRouter<BARRELPS, BARRELPS, layer, disk,  maxAllCopies, maxTEICopies, maxOLCopies, maxTEOCopies, nbitsbin>
	(bx, finebintable, phicorrtable, 
		rzbitstable, rzbitsextratable, nullptr,
		bendtable, bendextratable, nullptr,
// Input memories
		imask, inputStub, nullptr,
// AllStub memories
		allStub,
// ME memories
		memask, meMemories,
// TEInner memories
		teimask, teiMemories,
// TEInner Overlap memories
		olmask, olMemories,
// TEOuter memories
		teomask, nullptr
		);

	return;
}
