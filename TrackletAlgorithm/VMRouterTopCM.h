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

#define kLAYER 2 // Which barrel layer number the data is coming from
#define kDISK 0 // Which disk number the data is coming from, 0 if not disk

constexpr char phiRegion = 'A'; // Which AllStub/PhiRegion
constexpr int sector = 4; //  Specifies the sector

// Maximum number of memory "copies" for this Phi region
// Note: can't use 0 if we don't have any memories of a certain type. Use 1.
constexpr int numASCopies(3); // Allstub memory
constexpr int numASInnerCopies(4); // Allstub memory
constexpr int numTEOCopies(3); // TE Outer memories

// Number of inputs
constexpr int numInputs(2); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S(0); // Number of DISK2S input memories

//Bit size of phi and rz bins?!?!
constexpr int phiRegSize(3);
constexpr int rzSize(3);

///////////////////////////////////////////////
// Variables that don't need manual changing

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

void VMRouterTopCM(const BXType bx, BXType& bx_o,
	// Input memories
	const InputStubMemory<inputType> inputStubs[numInputs],

	// Output memories
	AllStubMemory<outputType> memoriesAS[numASCopies],
	AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies],
	VMStubMEMemoryCM<outputType, rzSize, phiRegSize>& memoryME,
	VMStubTEOuterMemoryCM<outputType,rzSize,phiRegSize,numTEOCopies>& memoryTEO
	);

#endif // TrackletAlgorithm_VMRouterTopCM_h
