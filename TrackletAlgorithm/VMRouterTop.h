#ifndef TrackletAlgorithm_VMRouterTop_h
#define TrackletAlgorithm_VMRouterTop_h

#include "VMRouter.h"

// VMRouter Top Function for layer 1, AllStub region E
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTop.h
//          - the input parameters to VMRouterTop in VMRouterTop.h/.cc
//          - the the number and directories to the LUTs
//          - add/remove pragmas depending on inputStub in VMRouterTop.cc
//          - the call to VMRouter() in VMRouterTop.cc
//          - the included top function in VMRouter_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Changed manually

#define kLAYER 1 // Which barrel layer number the data is coming from, 0 if not barrel
#define kDISK 0 // Which disk number the data is coming from, 0 if not disk

constexpr char phiRegion = 'E'; // Which AllStub/PhiRegion
constexpr int sector = 4; //  Specifies the sector

// Maximum number of memory "copies" for this Phi region
// Note: can't use 0 if we don't have any memories of a certain type. Use 1.
constexpr int maxASCopies(6); // Allstub memory
constexpr int maxTEICopies(5); // TE Inner memories
constexpr int maxOLCopies(3); // TE Inner Overlap memories
constexpr int maxTEOCopies(1); // TE Outer memories

// Number of inputs
constexpr int numInputs(4); // Total number of input memories
constexpr int numInputsDiskPS(0); // Only used for disks
constexpr int numInputsDisk2S(numInputs-numInputsDiskPS); // Only used for disks

constexpr int bendCutTableSize(8); // Number of entries in each bendcut table. Can't use 0.


///////////////////////////////////////////////
// Variables that don't need manual changing

// Number of VMs
constexpr int nvmStandardTE = (kLAYER) ? nvmtelayers[kLAYER-1] : nvmtedisks[kDISK-1];

constexpr int nvmME = (kLAYER) ? nvmmelayers[kLAYER-1] : nvmmedisks[kDISK-1]; // ME memories
constexpr int nvmTEI = (kLAYER != 2) ? nvmStandardTE : nvmteextralayers[kLAYER-1]; // TE Inner memories
constexpr int nvmOL = (kLAYER == 1 || kLAYER == 2) ? nvmollayers[kLAYER-1] : 1; // TE Inner Overlap memories, can't use 0 when we don't have any OL memories
constexpr int nvmTEO = (kLAYER != 3) ? nvmStandardTE : nvmteextralayers[kLAYER-1]; // TE Outer memories

// Number of bits used for the bins in VMStubeME memories
constexpr int nbitsbin = (kLAYER) ? 3 : 4;

// What regionType the input/output is
constexpr regionType tmpLayerType = (kLAYER > 3) ? BARREL2S : BARRELPS;

constexpr regionType inputType = (kLAYER) ? tmpLayerType : DISKPS;
constexpr regionType outputType = (kLAYER) ? tmpLayerType : DISK;


/////////////////////////////////////////////////////
// VMRouter Top Function
// Changed manually

void VMRouterTop(BXType bx,
	// Input memories
	const InputStubMemory<inputType> inputStub[numInputs],

	// Output memories
	AllStubMemory<outputType> allStub[maxASCopies],
	VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME],
	VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies],
	VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies]
	);

#endif // TrackletAlgorithm_VMRouterTop_h
