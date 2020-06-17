#ifndef VMROUTERTOP_H
#define VMROUTERTOP_H

#include "VMRouter.h"

// VMRouter Top Function for Disk 1, AllStub region A

// Number of VMs. Could use constants from VMRouter.h...
constexpr int numInputs(4); // Input memories
constexpr int numInputsDisk2S(2); // DISK2S inputs
constexpr int numME(8); // ME memories
constexpr int numTEI(4); // TE Inner memories
constexpr int numOL(0); // TE Inner Overlap memories
constexpr int numTEO(4); // TE Outer memories 

// Maximum number of memory "copies" for this Phi region
constexpr int maxAllCopies(6); // Allstub memory
constexpr int maxTEICopies(3); // TE Inner memories
constexpr int maxOLCopies(1); // Can't use 0 evne if we don't have any TE Inner Overlap memories
constexpr int maxTEOCopies(5); // TE Outer memories


void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<DISKPS> inputStub[numInputs],
	const InputStubMemory<DISK2S> inputStubDisk2S[numInputsDisk2S],
	// Output memories
	AllStubMemory<DISK> allStub[maxAllCopies],
	VMStubMEMemory<DISK> meMemories[numME],
	VMStubTEInnerMemory<DISK> teiMemories[numTEI][maxTEICopies],
	VMStubTEOuterMemory<DISK> teoMemories[numTEO][maxTEOCopies]
	);

#endif // VMROUTERTOP_H
