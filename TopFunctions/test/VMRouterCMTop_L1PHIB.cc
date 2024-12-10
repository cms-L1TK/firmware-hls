#include "VMRouterCMTop_L1PHIB.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

void VMRouterCMTop_L1PHIB(
  const BXType bx,
  // Input memories
  hls::stream<InputStub<inputType_B> > &inputStubs_0,
  hls::stream<InputStub<inputType_B> > &inputStubs_1,
  // Output memories
  AllStubMemory<outputType_B> memoriesAS[numASCopies_B],
  AllStubInnerMemory<outputType_B> memoriesASInner[numASInnerCopies_B],
  VMStubMEMemoryCM<outputType_B, kNbitsrzbinME_B, kNbitsphibin, kNMatchEngines> *memoryME  ) {

  ///////////////////////////
  // Open Lookup tables

  // LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
  // Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
  // Indexed using r and z position bits
  static const int METable[] =
#include "../emData/VMRCM/tables/VMRME_L1.tab"
  static const int *TETable = nullptr;

  // LUT with phi corrections to project the stub to the average radius in a layer.
  // Only used by layers.
  // Indexed using phi and bend bits
  static const int phiCorrTable[] =
#include "../emData/VMRCM/tables/VMPhiCorrL1.tab"

  // Masks of which AllStubInner memories that are being used in this phi region; represented by a "1"
  // First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
  // NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)
  static const ap_uint<maskASIsize> maskASI = getAllStubInnerMask<layerdisk_B, phiRegion_B>();

  /////////////////////////
  // Main function

  VMRouterCM<numInputs_B, numInputsDisk2S_B, numASCopies_B, numASInnerCopies_B, kLAYER_B, kDISK_B, inputType_B, outputType_B, kNbitsrzbinME_B, kNbitsrzbin, kNbitsphibin, numTEOCopies_B>(
    bx,
    // LUTs
    METable,
    TETable,
    phiCorrTable,
    // Input memories
    inputStubs_0,
    inputStubs_1,
    // AllStub memories
    memoriesAS,
    maskASI,
    memoriesASInner,
    // ME memories
    memoryME,
    // TEOuter memories
    nullptr
  );

  return;
}
