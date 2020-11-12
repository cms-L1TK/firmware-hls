#ifndef TrackletAlgorithm_VMRouterTop_D1PHIA_h
#define TrackletAlgorithm_VMRouterTop_D1PHIA_h

#include "VMRouter.h"

// VMRouter Top Function for Disk 1, AllStub region A
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: To run this VMR, change the following
//          - the included top function in VMRouter_test.cpp to "#include "VMRouterTop_D1PHIA.h""
//          - the top function in script_VMR.tcl to "add_files ../TrackletAlgorithm/VMRouterTop_D1PHIA.cc -cflags "$CFLAGS""
//          - the memory directory in script_VMR.tcl "to add_files -tb ../emData/VMR/VMR_D1PHIA/"


//////////////////////////////////
// Variables for that are specified with regards to the VMR region

#define kLAYER 0 // Which barrel layer number the data is coming from, 0 if not barrel
#define kDISK 1 // Which disk number the data is coming from, 0 if not disk

constexpr char phiRegion = 'A'; // Which AllStub/PhiRegion
constexpr int sector = 4; //  Specifies the sector

// Maximum number of memory "copies" for this Phi region
// Note: can't use 0 if we don't have any memories of a certain type. Use 1.
constexpr int maxASCopies(6); // Allstub memory
constexpr int maxTEICopies(3); // TE Inner memories
constexpr int maxOLCopies(1); // TE Inner Overlap memories
constexpr int maxTEOCopies(5); // TE Outer memories

// Number of inputs
constexpr int numInputs(6); // Input memories
constexpr int numInputsDiskPS(4);
constexpr int numInputsDisk2S(numInputs-numInputsDiskPS); // inputType2 inputs

constexpr int bendCutTableSize(8); // Number of entries in each bendcut table. Can't use 0.


///////////////////////////////////////////////
// Variables that don't need manual changing for disks

// Number of VMs
constexpr int nvmME = nvmmedisks[kDISK-1]; // ME memories
constexpr int nvmTEI = nvmtedisks[kDISK-1]; // TE Inner memories
constexpr int nvmOL = 1; // TE Inner Overlap memories, can't use 0 when we don't have any OL memories
constexpr int nvmTEO = nvmtedisks[kDISK-1]; // TE Outer memories

// Number of bits used for the bins in VMStubeME memories
constexpr int nbitsbin = (kLAYER) ? 3 : 4;

// What regionType the input/output is
constexpr regionType inputType = DISKPS;
constexpr regionType outputType = DISK;


/////////////////////////////////////////////////////
// VMRouter Top Function

void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<inputType> inputStub[numInputs],
	const InputStubMemory<DISK2S> inputStubDisk2S[numInputsDisk2S], // Only disks has 2S modules

	// Output memories
	AllStubMemory<outputType> allStub[maxASCopies],
	VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME],
	VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies],
	VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies]
	);

#endif // TrackletAlgorithm_VMRouterTop_h
