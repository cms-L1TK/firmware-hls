#ifndef TrackletAlgorithm_VMRouterTop_D1PHIA_h
#define TrackletAlgorithm_VMRouterTop_D1PHIA_h

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
constexpr int maxOLCopies(1); // Can't use 0 even if we don't have any TE Inner Overlap memories
constexpr int maxTEOCopies(5); // TE Outer memories

// Number of bits used for the bins in VMStubeME memories
constexpr int nbitsbin = 4; //3 for barrel, 4 for disks

void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<DISKPS> inputStub[numInputs],
	const InputStubMemory<DISK2S> inputStubDisk2S[numInputsDisk2S],
	// Output memories
	AllStubMemory<DISK> allStub[maxAllCopies],
	VMStubMEMemory<DISK, nbitsbin> meMemories[numME],
	VMStubTEInnerMemory<DISK> teiMemories[numTEI][maxTEICopies],
	VMStubTEOuterMemory<DISK> teoMemories[numTEO][maxTEOCopies]
	);

#endif // TrackletAlgorithm_VMRouterTop_D1PHIA_h
