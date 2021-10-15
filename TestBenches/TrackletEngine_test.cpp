// TrackletEngine test bench
#include "TrackletEngineTop.h"
#include "StubPairMemory.h"
#include "VMStubTEInnerMemory.h"
#include "VMStubTEOuterMemory.h"
#include "FileReadUtility.h"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int nevents = 100;  // number of events to run

using namespace std;

int main(){
  TBHelper tb("TE/TE_L1PHIC12_L2PHIB12");

  // error counter
  int err_count = 0;
  
  // declare input memory arrays to be read from emulations files
  VMStubTEInnerMemory<BARRELPS> inputvmstubsinner;
  VMStubTEOuterMemory<BARRELPS> inputvmstubsouter;

  // declare the output memory array for the sub pairs
  StubPairMemory outputstubpairs; //produced by hls simulation

  // open input files from emulation
  auto &fin_vmstubsinner = tb.files("VMStubs_VMSTE_L1*");
  auto &fin_vmstubsouter = tb.files("VMStubs_VMSTE_L2*");
  auto &fin_stubpairs = tb.files("StubPairs_SP_*");

  ap_uint<1> bendinnertable[] =
#include "../emData/TE/tables/TE_L1PHIC12_L2PHIB12_stubptinnercut.tab"
  ap_uint<1> bendoutertable[] =
#include "../emData/TE/tables/TE_L1PHIC12_L2PHIB12_stubptoutercut.tab"

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    outputstubpairs.clear();

    //read next event from the input files
    writeMemFromFile<VMStubTEInnerMemory<BARRELPS> >(inputvmstubsinner, fin_vmstubsinner.at(0), ievt);
    writeMemFromFile<VMStubTEOuterMemory<BARRELPS> >(inputvmstubsouter, fin_vmstubsouter.at(0), ievt);

    //set the bunch crossing
    BXType bx=ievt&0x7;
    BXType bx_o;

    // Unit Under Test
    TrackletEngine_L1L2(bx, inputvmstubsinner, inputvmstubsouter, bendinnertable, bendoutertable, bx_o, outputstubpairs);

    bool truncation = false;

    // compare calculated outputs with those read from emulation printout
    err_count += compareMemWithFile<StubPairMemory>(outputstubpairs, fin_stubpairs.at(0), ievt, "StubPair", truncation);

  }  // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err_count > 255) err_count = 255;
  return err_count;
}
