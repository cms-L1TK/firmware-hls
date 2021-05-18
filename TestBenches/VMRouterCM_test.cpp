// Test bench for VMRouter Combined Modules
#include "VMRouterCMTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"

using namespace std;

const int nEvents = 100;  //number of events to run

// VMRouterCM Test that works for all regions
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterCMTop.h
//          - add/remove pragmas depending on number of inputStubs in VMRouterCMTop.cc (not necessary for simulation)
//          - add the phi region in emData/download.sh, make sure to also run clean
//          - add region specific constants defined in VMRouterCM_parameters.h if missing


int main() {

  constexpr int sector = 4; //  Specifies the sector/nonant

  ////////////////////////////////////////////////////////////////
  // Get the test vectors

  const string vmrID = ((kLAYER) ? "L" + to_string(kLAYER) : "D" + to_string(kDISK)) + "PHI" + static_cast<char>(phiRegion);
  TBHelper tb("VMRCM/VMR_" + vmrID);

  // String patterns of the memory file names
  const string inputPattern = (kLAYER) ? "InputStubs*" : "InputStubs*PS*";
  const string inputDisk2SPattern = "InputStubs*_D*2S*";
  
  const string allStubPattern = "AllStubs*";
  const string allStubInnerPattern = "AllInnerStubs*";
  const string mePattern = "VMStubs_VMSME*";
  const string tePattern = "VMStubs_VMSTE*";
  
  // Number of files
  const auto nInputStubs = tb.nFiles(inputPattern);
  const auto nInputStubsDisk2S = tb.nFiles(inputDisk2SPattern);

  const auto nASCopies = tb.nFiles(allStubPattern);
  const auto nASInnerCopies = tb.nFiles(allStubInnerPattern);
  const auto nVMSME = tb.nFiles(mePattern);
  const auto nVMSTE = tb.nFiles(tePattern);
  
  // Make sure that the number of input and output memories are correct
  assert((nInputStubs == numInputs) && (nInputStubsDisk2S == numInputsDisk2S) && (nASCopies == numASCopies) && (nVMSTE == numTEOCopies));

  // Open the files
  cout << "Open files..." << endl;

  auto &fin_inputstubs = tb.files(inputPattern);
  auto &fin_inputstubs_disk2s = tb.files(inputDisk2SPattern);

  auto &fout_allstubs = tb.files(allStubPattern);
  auto &fout_allstubs_inner = tb.files(allStubInnerPattern);
  auto &fout_vmstubme = tb.files(mePattern);
  auto &fout_vmstubte = tb.files(tePattern);


  ///////////////////////////
  // Declare memories

  // Input memories
  static InputStubMemory<inputType> inputStubs[numInputs];
  static InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]; //Only used for Disks

  // Output memories
  static AllStubMemory<outputType> memoriesAS[numASCopies];
  static AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies];
  static VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize> memoryME;
  static VMStubTEOuterMemoryCM<outputType,rzSizeTE,phiRegSize,numTEOCopies> memoryTEO;


  ///////////////////////////
  // Loop over events

  cout << "Start event loop ..." << endl;  

  // Error count
  int err = 0;

  for (unsigned int ievt = 0; ievt < nEvents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear output memories
    for (int i=0; i<nASCopies; ++i) {
      memoriesAS[i].clear();
    }
    for (int i=0; i<nASInnerCopies; ++i) {
      memoriesASInner[i].clear();
    }
    memoryME.clear();
    if (nVMSTE) {
      memoryTEO.clear();
    }
    
    // Read event and write to memories
    for (unsigned int i = 0; i < numInputs; i++) {
      writeMemFromFile<InputStubMemory<inputType>>(inputStubs[i], fin_inputstubs[i], ievt);
    }
    for (unsigned int i = 0; i < numInputsDisk2S; i++) {
      writeMemFromFile<InputStubMemory<DISK2S>>(inputStubsDisk2S[i], fin_inputstubs_disk2s[i], ievt);
    }

    // bx - bunch crossing
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    VMRouterCMTop(bx, bx_out, inputStubs
#if kDISK > 0
        , inputStubsDisk2S
#endif
        , memoriesAS
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
        , memoriesASInner
#endif
        , &memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
        , &memoryTEO
#endif
      );

    // Compare the computed outputs with the expected ones
    // Add 1 to the error count per stub that is incorrect
    bool truncation = false;

    // AllStub memories
    for (unsigned int i = 0; i < numASCopies; i++) {
      err += compareMemWithFile<AllStubMemory<outputType>>(memoriesAS[i], fout_allstubs[i], ievt, "AllStub", truncation);
    }
    // Allstub Inner memories
    if (nASInnerCopies) {
      for (unsigned int i = 0; i < numASInnerCopies; i++) {
        err += compareMemWithFile<AllStubInnerMemory<outputType>>(memoriesASInner[i], fout_allstubs_inner[i], ievt, "AllStubInner", truncation);
      }
    }
    // ME memories
    err += compareBinnedMemWithFile<VMStubMEMemoryCM<outputType, rzSizeME, phiRegSize>>(memoryME, fout_vmstubme[0], ievt, "VMStubME", truncation);  
    //TE Outer memories
    if (nVMSTE) {
      err += compareBinnedMemCMWithFile<VMStubTEOuterMemoryCM<outputType, rzSizeTE, phiRegSize, numTEOCopies>>(memoryTEO, fout_vmstubte[0], ievt, "VMStubTEOuter", truncation);
    }
  } // End of event loop

  cerr << "Exiting with return value " << err << endl;
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
