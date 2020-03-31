#include "VMRouterTop.hh"

// VMRouter Top Function for layer 1, AllStub region E

void VMRouterTop(BXType bx,
		const InputStubMemory<BARRELPS> *i0,
		const InputStubMemory<BARRELPS> *i1,
		const InputStubMemory<BARRELPS> *i2,
		const InputStubMemory<BARRELPS> *i3,
		const InputStubMemory<BARRELPS> *i4,
		const InputStubMemory<BARRELPS> *i5,
//		const InputStubMemory<BARRELPS> *i6,
//		const InputStubMemory<BARRELPS> *i7,
		AllStubMemory<BARRELPS> *allStub,
		VMStubMEMemory<BARRELPS> *m0,
		VMStubMEMemory<BARRELPS> *m1,
		VMStubMEMemory<BARRELPS> *m2,
		VMStubMEMemory<BARRELPS> *m3,
		VMStubMEMemory<BARRELPS> *m4,
		VMStubMEMemory<BARRELPS> *m5,
		VMStubMEMemory<BARRELPS> *m6,
		VMStubMEMemory<BARRELPS> *m7,
		VMStubTEInnerMemory<BARRELPS> *mtei0,
		VMStubTEInnerMemory<BARRELPS> *mtei1,
		VMStubTEInnerMemory<BARRELPS> *mtei2,
		VMStubTEInnerMemory<BARRELPS> *mtei3,
		VMStubTEInnerMemory<BARRELPS> *mtei4,
		VMStubTEInnerMemory<BARRELPS> *mtei5,
		VMStubTEInnerMemory<BARRELPS> *mtei6,
		VMStubTEInnerMemory<BARRELPS> *mtei7,
		VMStubTEInnerMemory<BARRELOL> *mteol1,
		VMStubTEInnerMemory<BARRELOL> *mteol2
		)
{

	// Variables for that are specified with regards to the test bench, should be set somewhere else
	const int layer(1); // Which barrel layer number the data is coming from, 0 if not barrel
	const int disk(0); // Which disk number the data is coming from, 0 if not disk
	const int ninputs(3);  // The number of input memories

	const uint32_t MEMask(0x000F0000UL); // Mask of which memories that are being used.
	const uint32_t TEIMask(0x000F0000UL); // Mask of which TE Inner memories that are used
	const uint16_t OLMask(0x300); // Mask of which TE Outer memories that are used
	const uint32_t TEOMask(0x0UL); // Mask of which TE Inner memories that are used
	// Note that the masks are "reversed"

static const ap_uint<6> imask(0x3); // Mask of which inputs that are being used
static const ap_uint<32> memask(0x000F0000UL); // Mask of which memories that are being used.
static const ap_uint<32> teimask(0x000F0000UL); // Mask of which TE Inner memories that are used
static const ap_uint<16> olmask(0x300); // Mask of which TE Outer memories that are used
static const ap_uint<32> teomask(0x0); // Mask of which TE Inner memories that are used

	VMRouter<BARRELPS, BARRELPS, layer, disk> //, ninputs, MEMask, TEIMask, OLMask, TEOMask>
		 (bx, imask, i0,i1,i2,nullptr,nullptr,nullptr,//i5,i6,i7,
		 allStub,
		 // ME memories
		 memask,
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 0-7
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 8-15
		 m0,m1,m2,m3,nullptr,nullptr,nullptr,nullptr, // 16-23
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 24-31
		 // TEInner memories
		 teimask,
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 0-7
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 8-15
		 mtei0,mtei1,mtei2,mtei3,nullptr,nullptr,nullptr,nullptr, // 16-23
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 24-31
		 // TEInner Overlap memories
		 olmask,
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 0-7
		 mteol1,mteol2,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 8-15
		 // TEOuter memories
		 teomask,
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 0-7
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 8-15
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr, // 16-23
		 nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr // 24-31
		 );

	return;
}
