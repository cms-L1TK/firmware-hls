#ifndef TrackletAlgorithm_VMRouterTop_h
#define TrackletAlgorithm_VMRouterTop_h

#include "VMRouter.h"
#include "VMRouter_parameters.h"

// VMRouter Top Function for layer 1, AllStub region E
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTop.h
//          - the input parameters to VMRouterTop in VMRouterTop.h/.cc
//          - the the number and directories to the LUTs
//          - add/remove pragmas depending on inputStubs in VMRouterTop.cc
//          - the call to VMRouter() in VMRouterTop.cc
//          - the included top function in VMRouter_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Changed manually

#define kLAYER 1 // Which barrel layer number the data is coming from
#define kDISK 0 // Which disk number the data is coming from, 0 if not disk

constexpr phiRegions phiRegion = phiRegions::E; // Which AllStub/PhiRegion


///////////////////////////////////////////////
// Variables that don't need manual changing

constexpr bool isLayer = (kLAYER) ? true : false;
constexpr int layerDisk = (kLAYER) ? kLAYER-1 : kDISK-1;

// Number of inputs
constexpr int numInputs = getNumInputs<isLayer, layerDisk, phiRegion>(); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S = getNumInputsDisk2S<isLayer, layerDisk, phiRegion>(); // Number of DISK2S input memories

// Maximum number of memory "copies" for this Phi region
constexpr int maxASCopies = getNumASCopies<isLayer, layerDisk, phiRegion>(); // Allstub memory
constexpr int maxTEICopies = getNumTEICopies<isLayer, layerDisk, phiRegion>(); // TE Inner memories
constexpr int maxOLCopies = getNumOLCopies<isLayer, layerDisk, phiRegion>(); // TE Inner memories
constexpr int maxTEOCopies = getNumTEOCopies<isLayer, layerDisk, phiRegion>(); // TE Outer memories

constexpr int bendCutTableSize = getBendCutTableSize<isLayer, layerDisk, phiRegion>(); // Number of entries in each bendcut table

#if kLAYER == kDISK
#error kLAYER and kDISK cannot be the same
#elif kLAYER > 0
	// Number of VMs
	constexpr int nvmME = nvmmelayers[kLAYER-1]; // ME memories
	constexpr int nvmTEI = (kLAYER != 2) ? nvmtelayers[kLAYER-1] : nvmteextralayers[kLAYER-1]; // TE Inner memories
	constexpr int nvmOL = (kLAYER == 1 || kLAYER == 2) ? nvmollayers[kLAYER-1] : 1; // TE Inner Overlap memories, can't use 0 when we don't have any OL memories
	constexpr int nvmTEO = (kLAYER != 3) ? nvmtelayers[kLAYER-1] : nvmteextralayers[kLAYER-1]; // TE Outer memories

	// Number of bits used for the bins in VMStubeME memories
	constexpr int nbitsbin = 3;

	// What regionType the input/output is
	constexpr regionType inputType = (kLAYER > 3) ? BARREL2S : BARRELPS;
	constexpr regionType outputType = (kLAYER > 3) ? BARREL2S : BARRELPS;

#elif kDISK > 0
	// Number of VMs
	constexpr int nvmME = nvmmedisks[kDISK-1]; // ME memories
	constexpr int nvmTEI = nvmtedisks[kDISK-1]; // TE Inner memories
	constexpr int nvmOL = 1; // TE Inner Overlap memories, can't use 0 when we don't have any OL memories
	constexpr int nvmTEO = nvmtedisks[kDISK-1]; // TE Outer memories

	// Number of bits used for the bins in VMStubeME memories
	constexpr int nbitsbin = 4;

	// What regionType the input/output is
	constexpr regionType inputType = DISKPS;
	constexpr regionType outputType = DISK;

#else
#error Need to have either kLAYER or kDISK larger than 0.
#endif


/////////////////////////////////////////////////////
// VMRouter Top Function
// Changed manually

void VMRouterTop(const BXType bx, BXType& bx_o,
	// Input memories
	const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[maxASCopies]
	, VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME]
#if kLAYER == 1 || kLAYER  == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
	, VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies]
#endif
#if kLAYER == 1 || kLAYER == 2
	, VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies]
#endif
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies]
#endif
	);

#endif // TrackletAlgorithm_VMRouterTop_h
