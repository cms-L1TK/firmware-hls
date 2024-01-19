// Test bench for VMStubMERouter

// To run a different phi region, change the following:
//          - change the top function and header file (TOP_FUNC_, HEADER_FILE_)
//          - add the phi region in emData/download.sh, make sure to also run clean
//          - run emData/generate_VMSMER.py to generate new top and parameters files

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined TOP_FUNC_
  #define TOP_FUNC_ VMStubMERouterTop_L2PHIA
  #define HEADER_FILE_ "VMStubMERouterTop_L2PHIA.h"
#endif

#include HEADER_FILE_

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"

using namespace std;

const int nEvents = 5;  //number of events to run

int main() {

  ////////////////////////////////////////////////////////////////
  // Get the test vectors

  constexpr char phi = 'A' + phiRegion; // Converts phiRegion to char
  const string vmrID = ((kLAYER) ? "L" + to_string(kLAYER) : "D" + to_string(kDISK)) + "PHI" + phi;
  TBHelper tb("VMRCM/VMR_" + vmrID);

  const string allStubPattern = "AllStubs*";
  const string mePattern = "VMStubs_VMSME*";

  // Open the files
  cout << "Open files..." << endl;

  auto &fin_allstubs = tb.files(allStubPattern);
  auto &fout_vmstubme = tb.files(mePattern);

  ///////////////////////////
  // Declare memories

  // Input memories
  static AllStubMemory<inType> memoriesAS;

  // Output memories
  static VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> memoryME;

  ///////////////////////////
  // Loop over events

  cout << "Start event loop ..." << endl;

  // Error count
  int err = 0;

  for (unsigned int ievt = 0; ievt < nEvents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear output memories
    memoryME.clear();

    // Read event and write to memories
    writeMemFromFile(memoriesAS, fin_allstubs[0], ievt);
    for (int i = 0; i < memoriesAS.getEntries(ievt); ++i){
      std::cout << "AS RAW: " << std::hex << memoriesAS.read_mem(ievt, i).raw() << "\n";
    }
    // bx - bunch crossing
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    TOP_FUNC_(bx, bx_out, 
              memoriesAS, 
              &memoryME);

    // Compare the computed outputs with the expected ones
    // Add 1 to the error count per stub that is incorrect
    bool truncation = false;

    // ME memories
    std::cout << "comparing memories for layer/disk: " << dec << kLAYER << "/" << kDISK << " and region: " << phiRegion << "\n";
    err += compareBinnedMemCMWithFile<VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines>>(memoryME, fout_vmstubme[0], ievt, "VMStubME", truncation);
    
    // Clear input memories
    memoriesAS.clear();

  } // End of event loop

  cerr << "Exiting with return value " << err << endl;
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
