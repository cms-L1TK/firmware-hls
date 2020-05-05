#ifndef VMROUTERTOP_HH
#define VMROUTERTOP_HH

#pragma once
#include "VMRouter.h"

// VMRouter Top Function for layer 1, AllStub region E

void VMRouterTop(BXType bx,
		const InputStubMemory<BARRELPS> inputMemories[6],
		AllStubMemory<BARRELPS> allStub[6],
		VMStubMEMemory<BARRELPS> meMemories[32],
		VMStubTEInnerMemory<BARRELPS> teiMemories[32],
		VMStubTEInnerMemory<BARRELOL> olMemories[3][16],
		VMStubTEOuterMemory<BARRELPS> teoMemories[32]
		);

#endif // VMROUTERTOP_HH
