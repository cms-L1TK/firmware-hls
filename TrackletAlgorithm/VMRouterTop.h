#ifndef TrackletAlgorithm_VMRouterTop_h
#define TrackletAlgorithm_VMRouterTop_h

#include "VMRouter.h"

// Number of VMs. Could use constants from VMRouter.h...
constexpr int numInputs(4); // Input memories
constexpr int numME(4); // ME memories
constexpr int numTEI(4); // TE Inner memories
constexpr int numOL(2); // TE Inner Overlap memories

// Maximum number of memory "copies" for this Phi region
constexpr int maxAllCopies(6); // Allstub memory
constexpr int maxTEICopies(5); // TE Inner memories
constexpr int maxOLCopies(3); // TE Inner Overlap memories
constexpr int maxTEOCopies(1); // Can't use 0 even if we don't have any TE Outer memories

// Number of bits used for the bins in VMStubeME memories
constexpr int nbitsbin = 3; //3 for barrel, 4 for disks

// VMRouter Top Function for layer 1, AllStub region E
void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<BARRELPS> inputStub[numInputs],
	// Output memories
	AllStubMemory<BARRELPS> allStub[maxAllCopies],
	VMStubMEMemory<BARRELPS, nbitsbin> meMemories[numME],
	VMStubTEInnerMemory<BARRELPS> teiMemories[numTEI][maxTEICopies],
	VMStubTEInnerMemory<BARRELOL> olMemories[numOL][maxOLCopies]
	);

#endif // TrackletAlgorithm_VMRouterTop_h
