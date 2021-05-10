#ifndef TrackletAlgorithm_VMRouterTopCM_h
#define TrackletAlgorithm_VMRouterTopCM_h

#include "VMRouterCM.h"

// VMRouter Top Function for layer 2, AllStub region A
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTopCM.h
//          - the input parameters to VMRouterTopCM in VMRouterTopCM.h/.cc
//          - add/remove pragmas depending on inputStubs in VMRouterTopCM.cc
//          - the call to VMRouterCM() in VMRouterTopCM.cc
//          - the included top function in VMRouterCM_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR_CM.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Changed manually

#define kLAYER 0 // Which barrel layer number the data is coming from
#define kDISK 1 // Which disk number the data is coming from, 0 if not disk

constexpr char phiRegion = 'C'; // Which AllStub/PhiRegion
constexpr int sector = 4; //  Specifies the sector

// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies(4); // Allstub memory
constexpr int numASInnerCopies(3); // Allstub memory Note: can't use 0 if we don't have any memories of a certain type. Use 1.
constexpr int numTEOCopies(3); // TE Outer memories, can be 0 when no TEOuter memories

// Number of inputs
constexpr int numInputs(8); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S(4); // Number of DISK2S input memories

///////////////////////////////////////////////
// Variables that don't need manual changing

//Bit size of phi and rz bins?!?! These don't change I think
constexpr int phiRegSize(3);
constexpr int rzSizeTE(3);
constexpr int rzSizeME = (kLAYER) ? 3 : 4;

#if kLAYER == kDISK
#error kLAYER and kDISK can not be the same
#elif kLAYER > 0
	// What regionType the input/output is
	constexpr regionType inputType = (kLAYER > 3) ? BARREL2S : BARRELPS;
	constexpr regionType outputType = (kLAYER > 3) ? BARREL2S : BARRELPS;

#elif kDISK > 0
	// What regionType the input/output is
	constexpr regionType inputType = DISKPS;
	constexpr regionType outputType = DISK;

#else
#error Need to have either kLAYER or kDISK larger than 0.
#endif


/////////////////////////////////////////////////////
// VMRouterCM Top Function
// Changed manually

void VMRouterTopCM(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 // Add layers/disks
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType,rzSizeTE,phiRegSize,numTEOCopies> *memoryTEO
#endif
	);

#endif // TrackletAlgorithm_VMRouterTopCM_h
