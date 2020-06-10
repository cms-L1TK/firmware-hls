#include "VMRouterTop_D1.hh"

// VMRouter Top Function for Disk 1, AllStub region A

void VMRouterTop(BXType bx,
		const InputStubMemory<DISK2S> *i0,
		const InputStubMemory<DISKPS> *i1,
		const InputStubMemory<DISKPS> *i2,
		const InputStubMemory<DISK2S> *i3,
		const InputStubMemory<DISKPS> *i4,
		const InputStubMemory<DISKPS> *i5,
//		const InputStubMemory<DISK> *i6,
//		const InputStubMemory<DISK> *i7,
AllStubMemory<DISK> allStub[6],
VMStubMEMemory<DISK> meMemories[8],
VMStubTEInnerMemory<DISK> teiMemories[4][3],
VMStubTEOuterMemory<DISK> teoMemories[4][5]
		)
{

	// Variables for that are specified with regards to the test bench, should be set somewhere else
	constexpr int layer(0); // Which barrel layer number the data is coming from, 0 if not barrel
	constexpr int disk(1); // Which disk number the data is coming from, 0 if not disk
	
	constexpr int nall(6);
	constexpr int ntei(3); // Number of maximum TEInner memory copies 
	constexpr int nteol(1);
	constexpr int nteo(5);
	
	static const ap_uint<6> imask(0x3F); // Mask of which inputs that are being used
	static const ap_uint<32> memask(0x000000FFUL); // Mask of which memories that are being used.
	static const ap_uint<32> teimask(0x0000000FUL); // Mask of which TE Inner memories that are used
	static const ap_uint<16> olmask(0x000); // Mask of which TE Outer memories that are used
	static const ap_uint<32> teomask(0x0000000FUL); // Mask of which TE Inner memories that are used


	///////////////////////////
	// Open Lookup tables

	// lookup table - 2^nbinsfinbinetable entries actually filled
	// Table is filled with numbers between 0 and 7 (and -1): the finer region each z/r bin is divided into.
		static const int finebintable[] =
	#include "../emData/MemPrints/Tables/VMR_D1PHIA_finebin.tab"
		;

		// Only used by layers. LUT with phi corrections for different r and bend
		static const int phicorrtable[] =
	#include "../emData/MemPrints/Tables/VMPhiCorrL1.txt"
		;

		static const int rzbitstable[2048] = // 11 bits used for LUT
	#include "../emData/MemPrints/Tables/VMTableInnerD1D2.tab" // Only for Layer 1
						;

	// Bendcut tables
	ap_uint<1> tmptable1_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA1n1_vmbendcut.tab"
	;
	ap_uint<1> tmptable1_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA1n2_vmbendcut.tab"
	;
	ap_uint<1> tmptable1_n3[8] = {0};
	
	
	ap_uint<1> tmptable2_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA2n1_vmbendcut.tab"
	;
	ap_uint<1> tmptable2_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA2n2_vmbendcut.tab"
	;
	ap_uint<1> tmptable2_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA2n3_vmbendcut.tab"
	;
	
	ap_uint<1> tmptable3_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA3n1_vmbendcut.tab"
	;
	ap_uint<1> tmptable3_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA3n2_vmbendcut.tab"
	;
	ap_uint<1> tmptable3_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA3n3_vmbendcut.tab"
	;

	ap_uint<1> tmptable4_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA4n1_vmbendcut.tab"
	;
	ap_uint<1> tmptable4_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA4n2_vmbendcut.tab"
	;
	ap_uint<1> tmptable4_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIA4n3_vmbendcut.tab"
	;
	
	static const ap_uint<1>* bendtable[] = {
		tmptable1_n1, tmptable1_n2, tmptable1_n3, 
		tmptable2_n1, tmptable2_n2, tmptable2_n3, 
		tmptable3_n1, tmptable3_n2, tmptable3_n3,
		tmptable4_n1, tmptable4_n2, tmptable4_n3};


	ap_uint<1> tmpoverlaptable1_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX1n1_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable1_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX1n2_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable1_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX1n3_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable1_n4[8] = {0};
	ap_uint<1> tmpoverlaptable1_n5[8] = {0};

	ap_uint<1> tmpoverlaptable2_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX2n1_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable2_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX2n2_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable2_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX2n3_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable2_n4[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX2n4_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable2_n5[8] = {0};


	ap_uint<1> tmpoverlaptable3_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX3n1_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable3_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX3n2_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable3_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX3n3_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable3_n4[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX3n4_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable3_n5[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX3n5_vmbendcut.tab"
	;

	ap_uint<1> tmpoverlaptable4_n1[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX4n1_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable4_n2[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX4n2_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable4_n3[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX4n3_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable4_n4[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX4n4_vmbendcut.tab"
	;
	ap_uint<1> tmpoverlaptable4_n5[] =
	#include "../emData/MemPrints/Tables/VMSTE_D1PHIX4n5_vmbendcut.tab"
	;
	

	static const ap_uint<1>* bendextratable[] = {
		tmpoverlaptable1_n1, tmpoverlaptable1_n2, tmpoverlaptable1_n3, tmpoverlaptable1_n4, tmpoverlaptable1_n5,
		tmpoverlaptable2_n1, tmpoverlaptable2_n2, tmpoverlaptable2_n3, tmpoverlaptable2_n4, tmpoverlaptable2_n5,
		tmpoverlaptable3_n1, tmpoverlaptable3_n2, tmpoverlaptable3_n3, tmpoverlaptable3_n4, tmpoverlaptable3_n5,
		tmpoverlaptable4_n1, tmpoverlaptable4_n2, tmpoverlaptable4_n3, tmpoverlaptable4_n4, tmpoverlaptable4_n5};


	// Overlap LUT
		static const int rzbitsoverlaptable[] = // 10 bits used for LUT
	#include "../emData/MemPrints/Tables/VMTableOuterD1.tab" // Only for Layer 1
						;

	// Takes 2 clock cycles before on gets data, used at high frequencies
		#pragma HLS resource variable=i0->get_mem() latency=2
		#pragma HLS resource variable=i1->get_mem() latency=2
		#pragma HLS resource variable=i2->get_mem() latency=2
		#pragma HLS resource variable=i3->get_mem() latency=2
		
		#pragma HLS resource variable=finebintable latency=2
		#pragma HLS resource variable=rzbitstable latency=2
		#pragma HLS resource variable=rzbitsoverlaptable latency=2
		#pragma HLS resource variable=bendtable latency=2
		//phicorrtable and bendtable seems to be using LUTs as it's relatively small?


	VMRouter<DISKPS, DISK2S, DISK, layer, disk, nall, ntei, nteol, nteo>
	(bx, finebintable, phicorrtable, rzbitstable, rzbitsoverlaptable, bendtable, bendextratable,
		imask, i0,i1,i2,i3,i4,i5,//,i6,i7,
		allStub,
// ME memories
		memask, meMemories,
// TEInner memories
		teimask, teiMemories,
// TEInner Overlap memories
		olmask, nullptr,
// TEOuter memories
		teomask, teoMemories
		 );

	return;
}
