#ifndef VMROUTERTOP_H
#define VMROUTERTOP_H

#include "VMRouter.h"

// VMRouter Top Function for layer 1, AllStub region E
void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<BARRELPS> inputStub[4],
	// Output memories
	AllStubMemory<BARRELPS> allStub[6],
	VMStubMEMemory<BARRELPS> meMemories[4],
	VMStubTEInnerMemory<BARRELPS> teiMemories[4][5],
	VMStubTEInnerMemory<BARRELOL> olMemories[2][3]
	);

#endif // VMROUTERTOP_H
