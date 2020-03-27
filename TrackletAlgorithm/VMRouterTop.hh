#ifndef VMROUTERTOP_HH
#define VMROUTERTOP_HH

#pragma once
#include "VMRouter.hh"

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
		);

#endif // VMROUTERTOP_HH
