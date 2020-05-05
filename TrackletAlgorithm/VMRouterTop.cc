#include "VMRouterTop.h"

// VMRouter Top Function for layer 1, AllStub region E

void VMRouterTop(BXType bx, const InputStubMemory<BARRELPS> inputMemories[6],
		AllStubMemory<BARRELPS> allStub[6],
		VMStubMEMemory<BARRELPS> meMemories[32],
		VMStubTEInnerMemory<BARRELPS> teiMemories[32],
		VMStubTEInnerMemory<BARRELOL> olMemories[3][16],
		VMStubTEOuterMemory<BARRELPS> teoMemories[32]) {


// Variables for that are specified with regards to the test bench, should be set somewhere else
// Note that the first memory is represented by the LSB
	const int layer(1); // Which barrel layer number the data is coming from, 0 if not barrel
	const int disk(0); // Which disk number the data is coming from, 0 if not disk
	static const ap_uint<6> imask(0xF); // Mask of which inputs that are being used
	static const ap_uint<32> memask(0x000F0000UL); // Mask of which memories that are being used.
	static const ap_uint<32> teimask(0x000F0000UL); // Mask of which TE Inner memories that are used
	static const ap_uint<16> olmask(0x300); // Mask of which TE Outer memories that are used
	static const ap_uint<32> teomask(0x0); // Mask of which TE Inner memories that are used

///////////////////////////
// Open Lookup tables

// lookup table - 2^nbinsfinbinetable entries actually filled
// Table is filled with numbers between 0 and 7 (and -1): the finer region each z/r bin is divided into.
	static const int finebintable[kMaxFineBinTable] =
#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.tab"
	;

	// Only used by layers. LUT with phi corrections for different r and bend
	static const int phicorrtable[] =
#include "../emData/VMR/VMPhiCorrL1.txt"
	;

	static const int binlookuptable[2048] = // 11 bits used for LUT
#include "../emData/VMR/VMR_L1PHIE/VMTableInnerL1L2.tab" // Only for Layer 1
					;


// Bendcut tables
static const int bendtablesize = 8; // The size of each vmbendcut table. Either 8 or 16.
static const int bendtable[][bendtablesize] = {
			#include "../emData/VMR/VMSTE_L1PHIE17n1_vmbendcut.tab" // Seems to be the same for all E regions
			,
			#include "../emData/VMR/VMSTE_L1PHIE18n1_vmbendcut.tab"
			,
			#include "../emData/VMR/VMSTE_L1PHIE19n1_vmbendcut.tab"
			,
			#include "../emData/VMR/VMSTE_L1PHIE20n1_vmbendcut.tab"
};

// Overlap LUT
	static const int overlaptable[1024] = // 10 bits used for LUT
#include "../emData/VMR/VMTableInnerL1D1.tab" // Only for Layer 1
					;
// SHOULD I USE SOMETHING ELSE THAN INT FOR MY TABLES???

					VMRouter<BARRELPS, BARRELPS, layer, disk, bendtablesize>
					(bx, finebintable, phicorrtable, binlookuptable, bendtable, overlaptable,
					imask, inputMemories,
					allStub,
// ME memories
					memask, meMemories,
// TEInner memories
					teimask, teiMemories,
// TEInner Overlap memories
					olmask, olMemories,
// TEOuter memories
					teomask, teoMemories
					);
	return;
}
