#include "VMRouter.hh"

void VMRouterTop(BXType bx,
		const InputStubMemory *i0,
		const InputStubMemory *i1,
		const InputStubMemory *i2,
		const InputStubMemory *i3,
		const InputStubMemory *i4,
//		const InputStubMemory *i5,
//		const InputStubMemory *i6,
//		const InputStubMemory *i7,
		AllStubMemory *allStub,
		VMStubMEMemory *m0,
		VMStubMEMemory *m1,
		VMStubMEMemory *m2,
		VMStubMEMemory *m3,
		VMStubMEMemory *m4,
		VMStubMEMemory *m5,
		VMStubMEMemory *m6,
		VMStubMEMemory *m7
		)
{

	VMRouter<0,-1,true>(bx,i0,i1,i2,i3,i4,//i5,i6,i7,
			allStub,
			m0,m1,m2,m3,m4,m5,m6,m7);

	return;
}
