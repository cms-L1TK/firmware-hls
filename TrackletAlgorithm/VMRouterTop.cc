#include "VMRouter.hh"

void VMRouterTop(BXType bx,
		const InputStubMemory<BARRELPS> *i0,
		const InputStubMemory<BARRELPS> *i1,
		const InputStubMemory<BARRELPS> *i2,
		const InputStubMemory<BARRELPS> *i3,
		const InputStubMemory<BARRELPS> *i4,
//		const InputStubMemory<BARRELPS> *i5,
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
		VMStubMEMemory<BARRELPS> *m7
		)
{

//	VMRouter<0,-1,true>(0, -1, true, bx,i0,i1,i2,i3,i4,//i5,i6,i7,
	VMRouter(1, 0, true, bx,i0,i1,i2,i3,i4,//i5,i6,i7,
		 allStub, ap_uint<32>(0x000F00F0UL),
		 0,0,0,0,m4,m5,m6,m7, // 0-7
		 0,0,0,0,0,0,0,0, // 8-15
		 m0,m1,m2,m3,0,0,0,0, // 16-23
		 0,0,0,0,0,0,0,0 // 24-31
		 );

	return;
}
