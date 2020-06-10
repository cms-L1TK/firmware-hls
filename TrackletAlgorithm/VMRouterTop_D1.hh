#ifndef VMROUTERTOP_HH
#define VMROUTERTOP_HH

#pragma once
#include "VMRouter.h"

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
VMStubMEMemory<DISK> meMemories[4],
VMStubTEInnerMemory<DISK> teiMemories[4][3],
VMStubTEOuterMemory<DISK> teoMemories[4][5]
		);

#endif // VMROUTERTOP_HH
