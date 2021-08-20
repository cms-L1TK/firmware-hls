#ifndef TrackletAlgorithm_VMRouterCMTop_h
#define TrackletAlgorithm_VMRouterCMTop_h

#include "VMRouterCM.h"
#include "VMRouterCM_parameters.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// To run a different phi region, change the following:
//          - add the phi region in emData/download.sh, make sure to also run clean
//
//          - kLAYER, kDISK, and phiRegion in VMRouterCMTop.h
//          - add corresponding magic numbers to VMRouterCM_parameters.h if not already defined
//          - add/remove pragmas depending on inputStubs in VMRouterCMTop.cc (not necessary to run simulation)
//          OR
//          - run emData/generate_VMRCM.py to generate new top and parameters files

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region

#define kLAYER 2 // Which barrel layer number the data is coming from
#define kDISK 0 // Which disk number the data is coming from, 0 if not disk

constexpr phiRegions phiRegion = phiRegions::A; // Which AllStub/PhiRegion


///////////////////////////////////////////////
// Values that don't need manual changing

constexpr TF::layerDisk layerdisk = static_cast<TF::layerDisk>((kLAYER) ? kLAYER-1 : trklet::N_LAYER+kDISK-1);

// Number of inputs
constexpr int numInputs = getNumInputs<layerdisk, phiRegion>(); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S = getNumInputsDisk2S<layerdisk, phiRegion>(); // Number of DISK2S input memories

// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies = getNumASCopies<layerdisk, phiRegion>(); // Allstub memory
constexpr int numASInnerCopies = getNumASInnerCopies<layerdisk, phiRegion>(); // Allstub Inner memory
constexpr int numTEOCopies = getNumTEOCopies<layerdisk, phiRegion>(); // TE Outer memories, can be 0 when no TEOuter memories

// Masks of which AllStubInner memories that are being used in this phi region; represented by a "1"
// First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
// NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)
static const ap_uint<maskASIsize> maskASI = getAllStubInnerMask<layerdisk, phiRegion>();

//Bit size of phi and rz bins
constexpr int phiRegSize(3);
constexpr int rzSizeTE(3);

#if kLAYER == kDISK
#error kLAYER and kDISK can not be the same
#elif kLAYER > 0
	constexpr int rzSizeME = 3;
	// What regionType the input/output is
	constexpr regionType inputType = (kLAYER > 3) ? BARREL2S : BARRELPS;
	constexpr regionType outputType = (kLAYER > 3) ? BARREL2S : BARRELPS;

#elif kDISK > 0
	constexpr int rzSizeME = 4;
	// What regionType the input/output is
	constexpr regionType inputType = DISKPS;
	constexpr regionType outputType = DISK;

#else
#error Need to have either kLAYER or kDISK larger than 0.
#endif


/////////////////////////////////////////////////////
// VMRouterCM Top Function

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
	, VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize, kNMatchEngines> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType, rzSizeTE, phiRegSize, kNTEUnits> memoriesTEO[numTEOCopies]
#endif
	);

#endif // TrackletAlgorithm_VMRouterCMTop_h
