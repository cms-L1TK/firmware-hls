#ifndef TrackletAlgorithm_VMRouterCMTop_h
#define TrackletAlgorithm_VMRouterCMTop_h

#include "VMRouterCM.h"

// VMRouter Top Function for layer 2, AllStub region A
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterCMTop.h
//          - add/remove pragmas depending on inputStubs in VMRouterCMTop.cc
//          - maskASI in VMRouterCMTop.cc
//          - the base directory when instantiating TBHelper in VMRouterCM_test.cpp
//          - add the phi region in emData/download.sh, make sure to also run clean

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Changed manually

#define kLAYER 2 // Which barrel layer number the data is coming from
#define kDISK 0 // Which disk number the data is coming from, 0 if not disk

constexpr char phiRegion = 'A'; // Which AllStub/PhiRegion
constexpr int sector = 4; //  Specifies the sector

// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies(4); // Allstub memory
constexpr int numASInnerCopies(4); // Allstub memory Note: can't use 0 if we don't have any memories of a certain type. Use 1.
constexpr int numTEOCopies(3); // TE Outer memories, can be 0 when no TEOuter memories

// Number of inputs
constexpr int numInputs(2); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S(0); // Number of DISK2S input memories

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

void VMRouterCMTop(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 || kDISK == 3
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType,rzSizeTE,phiRegSize,numTEOCopies> *memoryTEO
#endif
	);

#endif // TrackletAlgorithm_VMRouterCMTop_h
