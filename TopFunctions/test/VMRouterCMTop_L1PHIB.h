#ifndef TopFunctions_VMRouterCMTop_L1PHIB_h
#define TopFunctions_VMRouterCMTop_L1PHIB_h

#include "VMRouterCM.h"
#include "VMRouterCM_parameters.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Some are used by the Test Bench

#define kLAYER_B 1 // Which barrel layer number the data is coming from
#define kDISK_B 0 // Which disk number the data is coming from, 0 if not disk
constexpr TF::phiRegion phiRegion_B = TF::B; // Which AllStub/PhiRegion

constexpr TF::layerDisk layerdisk_B = static_cast<TF::layerDisk>((kLAYER_B) ? kLAYER_B-1 : trklet::N_LAYER+kDISK_B-1);
constexpr regionType inputType_B = getInputType<layerdisk_B>();
constexpr regionType outputType_B = getOutputType<layerdisk_B>();
// Number of inputs
constexpr int numInputs_B = getNumInputs<layerdisk_B, phiRegion_B>(); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S_B = getNumInputsDisk2S<layerdisk_B, phiRegion_B>(); // Number of DISK2S input memories
// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies_B = getNumASCopies<layerdisk_B, phiRegion_B>(); // Allstub memory
constexpr int numASInnerCopies_B = getNumASInnerCopies<layerdisk_B, phiRegion_B>(); // Allstub Inner memory
constexpr int numTEOCopies_B = getNumTEOCopies<layerdisk_B, phiRegion_B>(); // TE Outer memories
// Number of bits for the RZ bins 
constexpr int kNbitsrzbinME_B = kNbitsrzbinMELayer; // For the VMSME memories


/////////////////////////////////////////////////////
// VMRouterCM Top Function

void VMRouterCMTop_L1PHIB(const BXType bx,
  // Input memories
  hls::stream<InputStub<inputType_B> > &inputStubs_0,
  hls::stream<InputStub<inputType_B> > &inputStubs_1,
  // Output memories
  AllStubMemory<outputType_B> memoriesAS[numASCopies_B],
  AllStubInnerMemory<outputType_B> memoriesASInner[numASInnerCopies_B],
  VMStubMEMemoryCM<outputType_B, kNbitsrzbinME_B, kNbitsphibin, kNMatchEngines> *memoryME  );

#endif // TopFunctions_VMRouterCMTop_L1PHIB_h
