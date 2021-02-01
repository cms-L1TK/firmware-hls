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
  // error counter
  int err_count = 0;
  
  // declare input memory arrays to be read from emulations files
  VMStubTEInnerMemory<BARRELPS> inputvmstubsinner;
  VMStubTEOuterMemory<BARRELPS> inputvmstubsouter;
  //StubPairMemory inputstubpairs;

  // declare the output memory array for the sub pairs
  StubPairMemory outputstubpairs; //produced by hls simulation


  // open input files from emulation
  ifstream fin_vmstubsinner("../../../../../emData/TE/TE_L1PHIE18_L2PHIC17/VMStubs_VMSTE_L1PHIE18n2_04.dat");
  ifstream fin_vmstubsouter("../../../../../emData/TE/TE_L1PHIE18_L2PHIC17/VMStubs_VMSTE_L2PHIC17n4_04.dat");
  ifstream fin_stubpairs("../../../../../emData/TE/TE_L1PHIE18_L2PHIC17/StubPairs_SP_L1PHIE18_L2PHIC17_04.dat");  
  assert(fin_vmstubsinner.good());
  assert(fin_vmstubsouter.good());
  assert(fin_stubpairs.good());

  ap_uint<1> bendinnertable[256] =
#include "../emData/TE/tables/TE_L1PHIE18_L2PHIC17_stubptinnercut.tab"
  ap_uint<1> bendoutertable[256] =
#include "../emData/TE/tables/TE_L1PHIE18_L2PHIC17_stubptoutercut.tab"

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    outputstubpairs.clear();

    //read next event from the input files
    writeMemFromFile<VMStubTEInnerMemory<BARRELPS> >(inputvmstubsinner, fin_vmstubsinner,ievt);
    writeMemFromFile<VMStubTEOuterMemory<BARRELPS> >(inputvmstubsouter, fin_vmstubsouter,ievt);

    //set the bunch crossing
    BXType bx=ievt&0x7;
    BXType bx_o;

    // Unit Under Test
    TrackletEngineTop(bx, inputvmstubsinner, inputvmstubsouter, bendinnertable, bendoutertable, bx_o, outputstubpairs);
    
    // compare calculated outputs with those read from emulation printout
    err_count += compareMemWithFile<StubPairMemory>(outputstubpairs,fin_stubpairs,ievt,"StubPair");

  }  // end of event loop

  // close files
  fin_vmstubsinner.close();
  fin_vmstubsouter.close();
  fin_stubpairs.close();
  
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err_count > 255) err_count = 255;
  return err_count;
}
