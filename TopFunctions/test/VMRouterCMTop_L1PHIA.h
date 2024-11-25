#ifndef TopFunctions_VMRouterCMTop_L1PHIA_h
#define TopFunctions_VMRouterCMTop_L1PHIA_h

#include "VMRouterCM.h"
#include "VMRouterCM_parameters.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region
// Some are used by the Test Bench

#define kLAYER_A 1 // Which barrel layer number the data is coming from
#define kDISK_A 0 // Which disk number the data is coming from, 0 if not disk
constexpr TF::phiRegion phiRegion_A = TF::A; // Which AllStub/PhiRegion

constexpr TF::layerDisk layerdisk_A = static_cast<TF::layerDisk>((kLAYER_A) ? kLAYER_A-1 : trklet::N_LAYER+kDISK_A-1);
constexpr regionType inputType_A = getInputType<layerdisk_A>();
constexpr regionType outputType_A = getOutputType<layerdisk_A>();
// Number of inputs
constexpr int numInputs_A = getNumInputs<layerdisk_A, phiRegion_A>(); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S_A = getNumInputsDisk2S<layerdisk_A, phiRegion_A>(); // Number of DISK2S input memories
// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies_A = getNumASCopies<layerdisk_A, phiRegion_A>(); // Allstub memory
constexpr int numASInnerCopies_A = getNumASInnerCopies<layerdisk_A, phiRegion_A>(); // Allstub Inner memory
constexpr int numTEOCopies_A = getNumTEOCopies<layerdisk_A, phiRegion_A>(); // TE Outer memories
// Number of bits for the RZ bins 
constexpr int kNbitsrzbinME_A = kNbitsrzbinMELayer; // For the VMSME memories


/////////////////////////////////////////////////////
// VMRouterCM Top Function

void VMRouterCMTop_L1PHIA(const BXType bx,
  // Input memories
  hls::stream<InputStub<inputType_A> > &inputStubs_0,
  hls::stream<InputStub<inputType_A> > &inputStubs_1,
  // Output memories
  AllStubMemory<outputType_A> memoriesAS[numASCopies_A],
  AllStubInnerMemory<outputType_A> memoriesASInner[numASInnerCopies_A],
  VMStubMEMemoryCM<outputType_A, kNbitsrzbinME_A, kNbitsphibin, kNMatchEngines> *memoryME  );

#endif // TopFunctions_VMRouterCMTop_L1PHIA_h
