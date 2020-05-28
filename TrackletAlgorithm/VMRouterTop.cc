#include "VMRouterTop.h"

// Determine the masks

// VMRouter Top Function for layer 1, AllStub region E

void VMRouterTop(BXType bx,
// Input memories
		const InputStubMemory<BARRELPS> *i0,
		const InputStubMemory<BARRELPS> *i1,
		const InputStubMemory<BARRELPS> *i2,
		const InputStubMemory<BARRELPS> *i3,
		const InputStubMemory<BARRELPS> *i4,
		const InputStubMemory<BARRELPS> *i5,
// AllStub memories
		AllStubMemory<BARRELPS> *allStub,
// ME memories
		VMStubMEMemory<BARRELPS> *m0, VMStubMEMemory<BARRELPS> *m1,
		VMStubMEMemory<BARRELPS> *m2, VMStubMEMemory<BARRELPS> *m3,
		VMStubMEMemory<BARRELPS> *m4, VMStubMEMemory<BARRELPS> *m5,
		VMStubMEMemory<BARRELPS> *m6, VMStubMEMemory<BARRELPS> *m7,
// TE Inner memories
		VMStubTEInnerMemory<BARRELPS> *mtei0,
		VMStubTEInnerMemory<BARRELPS> *mtei1,
		VMStubTEInnerMemory<BARRELPS> *mtei2,
		VMStubTEInnerMemory<BARRELPS> *mtei3,
		VMStubTEInnerMemory<BARRELPS> *mtei4,
		VMStubTEInnerMemory<BARRELPS> *mtei5,
		VMStubTEInnerMemory<BARRELPS> *mtei6,
		VMStubTEInnerMemory<BARRELPS> *mtei7,
		VMStubTEInnerMemory<BARRELOL> *mteol1,
		VMStubTEInnerMemory<BARRELOL> *mteol2) {

// Variables for that are specified with regards to the test bench
	const int layer(1); // Which barrel layer number the data is coming from, 0 if not barrel
	const int disk(0); // Which disk number the data is coming from, 0 if not disk
	static const ap_uint<6> imask(0xF); // Mask of which inputs that are being used
	static const ap_uint<32> memask(0x000F0000UL); // Mask of which memories that are being used.
	static const ap_uint<32> teimask(0x000F0000UL); // Mask of which TE Inner memories that are used
	static const ap_uint<16> olmask(0x300); // Mask of which TE Outer memories that are used
	static const ap_uint<32> teomask(0x0); // Mask of which TE Inner memories that are used

///////////////////////////
// Open Lookup tables

// LUT with the finer region each z/r bin is divided into.
	static const int finebintable[] =
#include "../emData/VMR/tables/VMR_L1PHIE_finebin.tab"
					;

// LUT with phi corrections to the nominal radius. Only used by layers.
// Values are determined by the radius and the bend of the stub.
					static const int phicorrtable[] =
#include "../emData/VMR/tables/VMPhiCorrL1.txt"
					;

// LUT with the Z/R bits for TE memories
// Todo: comment on what the bits represent
					static const int rzbitstable[] =
#include "../emData/VMR/tables/VMTableInnerL1L2.tab" // Only for Layer 1
					;

// LUT with the Z/R bits for TE Overlap memories
// Only used for Layer 1 and 1, and Disk 1
					static const int overlaptable[1024] =// 10 bits used for LUT
#include "../emData/VMR/tables/VMTableInnerL1D1.tab"
					;

// LUT with bend-cuts for the TE memories
// The cuts are different depending on the memory version (nX)
					ap_uint<1> tmptable1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n1_vmbendcut.tab"
					;

					ap_uint<1> tmptable2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n1_vmbendcut.tab"
					;

					ap_uint<1> tmptable3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n1_vmbendcut.tab"
					;

					ap_uint<1> tmptable4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n1_vmbendcut.tab"
					;

					static const ap_uint<1>* bendtable[] = {tmptable1, tmptable2, tmptable3, tmptable4};

					static const ap_uint<1>* bendextratable[1]; // Only used for Disk 1

/////////////////////////
// Main function

// template<regionType INTYPE, regionType INTYPE2, regionType OUTTYPE, int LAYER, int DISK>
// Disks have two types of input
					VMRouter<BARRELPS, BARRELPS, BARRELPS, layer, disk>
					(bx, finebintable, phicorrtable, rzbitstable,
					bendtable, bendextratable, overlaptable, imask, i0, i1, i2,
					i3, nullptr,
					nullptr, //i5,i6,i7,
					allStub,
// ME memories
					memask, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, nullptr,
					nullptr, // 0-7
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 8-15
					m0, m1, m2, m3, nullptr, nullptr, nullptr,
					nullptr, // 16-23
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 24-31
// TEInner memories
					teimask, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, nullptr,
					nullptr, // 0-7
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 8-15
					mtei0, mtei1, mtei2, mtei3, nullptr, nullptr, nullptr,
					nullptr, // 16-23
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 24-31
// TEInner Overlap memories
					olmask, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, nullptr,
					nullptr, // 0-7
					mteol1, mteol2, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, // 8-15
// TEOuter memories
					teomask, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, nullptr,
					nullptr, // 0-7
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 8-15
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, // 16-23
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr, nullptr // 24-31
					);return;}
