#include "VMRouterTop.hh"

// VMRouter Top Function for Layer 1, AllStub region E

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
		// ME memories
		VMStubMEMemory<BARRELPS> *m0,
		VMStubMEMemory<BARRELPS> *m1,
		VMStubMEMemory<BARRELPS> *m2,
		VMStubMEMemory<BARRELPS> *m3,
		VMStubMEMemory<BARRELPS> *m4,
		VMStubMEMemory<BARRELPS> *m5,
		VMStubMEMemory<BARRELPS> *m6,
		VMStubMEMemory<BARRELPS> *m7
		)
{

// Variables that are specified with regards to the test TestBenches
	const int layer(1); // Which barrel layer number the data is coming from, 0 if not barrel
	const int disk(0); // Which disk number the data is coming from, 0 if not disk
	const int ninputs(3);  // The number of input memories
	const uint32_t meMask(0x000F0000UL); // Mask of which memories that are being used. Note: did not work when using ap_uint<31>... why?

	// The main function
	VMRouter<BARRELPS, BARRELPS, layer, disk, ninputs, meMask>(
		 bx, i0, i1, i2, 0, 0, 0, //i6, i7,
		 allStub,
		 0, 0, 0, 0, 0, 0, 0, 0, // 0-7
		 0, 0, 0, 0, 0, 0, 0, 0, // 8-15
		 m0,m1,m2,m3,0, 0, 0, 0, // 16-23
		 0, 0, 0, 0, 0, 0, 0, 0 // 24-31
		 );

	return;
}
