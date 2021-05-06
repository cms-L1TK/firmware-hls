// Test bench for VMRouter Combined Modules
#include "VMRouterTopCM.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"

using namespace std;

const int nEvents = 100;  //number of events to run

// VMRouter Test that works for all regions
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - the base directory when instantiating TBHelper in VMRouterCM_test.cpp
//          - the included top function in VMRouterCM_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR_CM.tcl (if file name is changed)
//          - and the changes listed in VMRouterTopCM.cc/h

int main() {

  ////////////////////////////////////////////////////////////////
  // Get lists of the input/output memory directory and file names
  // I.e. the names of the test vector files

  TBHelper tb("VMRCM/VMR_L2PHIA");

  // String patterns of the memory file names
  const string inputPattern = (kLAYER) ? "InputStubs*" : "InputStubs*PS*";
  const string inputDisk2SPattern = "InputStubs*_D*2S*";
  
  const string allStubPattern = "AllStubs*PHI?_*";  // need "PHI?_*" because of bug in the MemPrintsCM?
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
  assert((nInputStubs == numInputs) && (nInputStubsDisk2S == numInputsDisk2S) && (nASCopies == maxASCopies));
  
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

  // output memories
  static AllStubMemory<outputType> memoriesAS[maxASCopies];
  static AllStubInnerMemory<outputType> memoriesASInner[maxASInnerCopies];
  // ME memories
  static VMStubMEMemoryCM<outputType, rzSize, phiRegSize> memoryME;
  // TE Outer memories
  static VMStubTEOuterMemoryCM<outputType,rzSize,phiRegSize,numTEOCopies> memoryTEO;

  ///////////////////////////
  // loop over events
  
  // error count
  int err = 0;
  
  cout << "Start event loop ..." << endl;

  for (unsigned int ievt = 0; ievt < nEvents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // clear output memories
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

    // read event and write to memories
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
    VMRouterTopCM(bx, bx_out, inputStubs
#if kDISK > 0
        , inputStubsDisk2S
#endif
        , memoriesAS, memoriesASInner//, maskASI
        , memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
        , memoryTEO
#endif
      );

    // compare the computed outputs with the expected ones
    // add 1 to the error count per stub that is incorrect

    bool truncation = false;

    // AllStub memories
    for (unsigned int i = 0; i < maxASCopies; i++) {
      err += compareMemWithFile<AllStubMemory<outputType>>(memoriesAS[i], fout_allstubs[i], ievt, "AllStub", truncation);
    }

    // Allstub Inner memories
    for (unsigned int i = 0; i < maxASInnerCopies; i++) {
      err += compareMemWithFile<AllStubInnerMemory<outputType>>(memoriesASInner[i], fout_allstubs_inner[i], ievt, "AllStubInner", truncation);
    }

    // ME memories
    err += compareBinnedMemWithFile<VMStubMEMemoryCM<outputType, rzSize, phiRegSize>>(memoryME, fout_vmstubme[0], ievt, "VMStubME", truncation);
    
    //TE Outer memories
    if (numTEOCopies) {
      err += compareBinnedMemCMWithFile<VMStubTEOuterMemoryCM<outputType,rzSize,phiRegSize,numTEOCopies>>(memoryTEO, fout_vmstubte[0], ievt, "VMStubTEOuter", truncation);
    }
  } // end of event loop

	cerr << "Exiting with return value " << err << endl;
	// This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
	if (err > 255) err = 255;
	return err;

}
