// Test bench for VMRouter
#include "VMRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"

using namespace std;

const int nEvents = 100;  //number of events to run

// VMRouter Test that works for all regions
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - constants specified in VMRouterTop.h
//          - add number to VMRouter_parameters.h if not already defined
//          - add the phi region in emData/download.sh, make sure to also run clean
//          - add/remove pragmas depending on inputStubs in VMRouterTop.cc (not necessary to run simulation)


// Count the number of copies of each memory in a file name vector
vector<int> countCopies(vector<string> fileNames) {
  vector<int> numCopies; // Each element in vector corresponds to one memory, i.e. L1PHIE17
  string firstCopyIndex = fileNames.begin()->substr(fileNames.begin()->find("n")+1, 1); // The number after n
  for (auto f = fileNames.begin(); f != fileNames.end(); ++f) {
    if (f->find("n"+firstCopyIndex) != string::npos) numCopies.push_back(1);
    else numCopies.back() += 1;
  }
  return numCopies;
}


int main() {

  constexpr int sector = 4; //  Specifies the sector
  constexpr char phi = static_cast<char>(phiRegion);

  char overlapPhiRegion[] = {'X', 'Y', 'Z', 'W', 'Q', 'R', 'S', 'T'}; // Special naming for the TE overlap memories, and outer memories in Disk 1
  char extraPhiRegion[] = {'I', 'J', 'K', 'L'}; // Special naming for the extra memories TEInner L2 and TEOuter L3.

  char teiPhiRegion = (kLAYER != 2) ? phi : extraPhiRegion[phi - 'A'];
  char teolPhiRegion = (kLAYER == 1 || kLAYER == 2) ? overlapPhiRegion[phi - 'A'] : ' ';
  char teoPhiRegion = (kDISK == 1) ? overlapPhiRegion[phi - 'A'] : ((kLAYER == 3) ? extraPhiRegion[phi - 'A'] : phi);


  ////////////////////////////////////////////////////////////////
  // Get the test vectors

  const string vmrID = ((kLAYER) ? "L" + to_string(kLAYER) : "D" + to_string(kDISK)) + "PHI" + phi;
  TBHelper tb("VMR/VMR_" + vmrID);

  // String patterns of the memory file names
  const string inputPattern = (kLAYER) ? "InputStubs*" : "InputStubs*PS*";
  const string inputDisk2SPattern = "InputStubs*_D*2S*";
  
  const string allStubPattern = "AllStubs*";
  const string mePattern = "VMStubs_VMSME*";
  const string teiPattern = (nvmTEI && maxTEICopies > 1) ? "VMStubs_VMSTE*PHI" + string(1,teiPhiRegion) + "*" : "No TEInner.";
  const string teolPattern = (nvmOL && maxOLCopies > 1) ? "VMStubs_VMSTE*PHI" + string(1,teolPhiRegion) + "*" : "No TEInner Overlap.";
  const string teoPattern = (nvmTEO && maxTEOCopies > 1) ? "VMStubs_VMSTE*PHI" + string(1,teoPhiRegion) + "*" : "No TEOuter.";
  
  // Number of files
  const auto nInputStubs = tb.nFiles(inputPattern);
  const auto nInputStubsDisk2S = tb.nFiles(inputDisk2SPattern);

  const auto nASCopies = tb.nFiles(allStubPattern);
  const auto nVMSME = tb.nFiles(mePattern);
  const auto nVMSTEI = tb.nFiles(teiPattern);
  const auto nVMSTEOL = tb.nFiles(teolPattern);
  const auto nVMSTEO = tb.nFiles(teoPattern);

  // Make sure that the number of input and output memories are correct
  assert((nInputStubs == numInputs) && (nInputStubsDisk2S == numInputsDisk2S) && (nASCopies == maxASCopies) && (nVMSME == nvmME));

  // Open the files
  cout << "Open files..." << endl;

  auto &fin_inputstubs = tb.files(inputPattern);
  auto &fin_inputstubs_disk2s = tb.files(inputDisk2SPattern);
  
  auto &fout_allstubs = tb.files(allStubPattern);
  auto &fout_vmstubme = tb.files(mePattern);
  auto &fout_vmstubtei = tb.files(teiPattern);
  auto &fout_vmstubteol = tb.files(teolPattern);
  auto &fout_vmstubteo = tb.files(teoPattern);

  // Get the number of copies for each TE memory
  vector<int> zero = {0};
  auto numCopiesTEI = (nVMSTEI) ? countCopies(tb.fileNames(teiPattern)) : zero;
  auto numCopiesOL = (nVMSTEOL) ? countCopies(tb.fileNames(teolPattern)) : zero;
  auto numCopiesTEO = (nVMSTEO) ? countCopies(tb.fileNames(teoPattern)) : zero;


  ///////////////////////////
  // Declare memories

  // Input memories
  static InputStubMemory<inputType> inputStubs[numInputs];
  static InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]; //Only used for Disks

  // Output memories
  static AllStubMemory<outputType> memoriesAS[maxASCopies];
  static VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME];
  static VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies];
  static VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies];
  static VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies];


  ///////////////////////////
  // Loop over events

  cout << "Start event loop ..." << endl;

  // Error count
  int err = 0;

  for (unsigned int ievt = 0; ievt < nEvents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear output memories
    for (int i=0; i<maxASCopies; ++i) {
      memoriesAS[i].clear();
    }
    for (int i=0; i<nvmME; ++i) {
      memoriesME[i].clear();
    }
    for (int i=0; i<nvmTEI; ++i) {
      for (int j=0; j<maxTEICopies; j++) {
        memoriesTEI[i][j].clear();
      }
    }
    for (int i=0; i<nvmOL; ++i) {
      for (int j=0; j<maxOLCopies; j++) {
        memoriesOL[i][j].clear();
      }
    }
    for (int i=0; i<nvmTEO; ++i) {
      for (int j=0; j<maxTEOCopies; j++) {
        memoriesTEO[i][j].clear();
      }
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
    VMRouterTop(bx, bx_out, inputStubs
#if kDISK > 0
        , inputStubsDisk2S
#endif
        , memoriesAS, memoriesME
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
        , memoriesTEI
#endif
#if kLAYER == 1 || kLAYER == 2
        , memoriesOL
#endif
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
        , memoriesTEO
#endif
      );

    // Compare the computed outputs with the expected ones
    // Add 1 to the error count per stub that is incorrect

    bool truncation = false;

    // AllStub
    for (unsigned int i = 0; i < maxASCopies; i++) {
      err += compareMemWithFile<AllStubMemory<outputType>>(memoriesAS[i], fout_allstubs[i], ievt, "AllStub", truncation);
    }

    // ME Memories
    for (unsigned int i = 0; i < nvmME; i++) {
      err += compareBinnedMemWithFile<VMStubMEMemory<outputType, nbitsbin>>(memoriesME[i], fout_vmstubme[i], ievt, "VMStubME" + to_string(i), truncation);
    }

    // TE Inner Memories
    if (nVMSTEI) {
      int k = 0;
      for (unsigned int i = 0; i < nvmTEI; i++) {
        for (unsigned int j = 0; j < numCopiesTEI[i]; j++) {
          err += compareMemWithFile<VMStubTEInnerMemory<outputType>>(memoriesTEI[i][j], fout_vmstubtei[k], ievt, "VMStubTEInner" + to_string(i) + "n" + to_string(j+1), truncation);
          k++;
        }
      }
    }

    // TE Inner Overlap memories
    if (nVMSTEOL) {
      int k = 0;
      for (unsigned int i = 0; i < nvmOL; i++) {
        for (unsigned int j = 0; j < numCopiesOL[i]; j++) {
          err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(memoriesOL[i][j], fout_vmstubteol[k], ievt, "VMStubTEOverlap" + to_string(i) + "n" + to_string(j+1), truncation);
          k++;
        }
      }
    }

    // TE Outer memories
    if (nVMSTEO) {
      int k = 0;
      for (unsigned int i = 0; i < nvmTEO; i++) {
        for (unsigned int j = 0; j < numCopiesTEO[i]; j++) {
          err += compareBinnedMemWithFile<VMStubTEOuterMemory<outputType>>(memoriesTEO[i][j], fout_vmstubteo[k], ievt, "VMStubTEOuter" + to_string(i) + "n" + to_string(j+1), truncation);
          k++;
        }
      }
    }
  } // End of event loop

  cerr << "Exiting with return value " << err << endl;
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
