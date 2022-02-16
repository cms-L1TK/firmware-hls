// TrackletEngine test bench
#include "TrackletEngineTop.h"

#include "Macros.h"
#include "FileReadUtility.h"

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined SEED_
  #define SEED_ L1L2_
#endif
#if !defined MODULE_
  #define MODULE_ TE_L1PHIG27_L2PHID27_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ TrackletEngineTop_PS_PS
#endif
#if !defined INNER_TABLE_
  #define INNER_TABLE_ "../emData/TE/tables/TE_L1PHIG27_L2PHID27_stubptinnercut.tab"
#endif
#if !defined OUTER_TABLE_
  #define OUTER_TABLE_ "../emData/TE/tables/TE_L1PHIG27_L2PHID27_stubptoutercut.tab"
#endif

const int nevents = 100;  // number of events to run

using namespace std;

int main(){
#if SEED_ == L1L2_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "VMStubs_VMSTE_L1*";
  const string outerStubPattern = "VMStubs_VMSTE_L2*";
#elif SEED_ == L2L3_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "VMStubs_VMSTE_L2*";
  const string outerStubPattern = "VMStubs_VMSTE_L3*";
#elif SEED_ == L3L4_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "VMStubs_VMSTE_L3*";
  const string outerStubPattern = "VMStubs_VMSTE_L4*";
#elif SEED_ == L5L6_
  const auto InnerStubType = BARREL2S;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "VMStubs_VMSTE_L5*";
  const string outerStubPattern = "VMStubs_VMSTE_L6*";
#else
  #error "Undefined seed"
#endif
  TBHelper tb(string("TE/") + module_name[MODULE_]);

  // error counter
  int err_count = 0;
  
  // declare input memory arrays to be read from emulations files
  VMStubTEInnerMemory<InnerStubType> inputvmstubsinner;
  VMStubTEOuterMemory<OuterStubType> inputvmstubsouter;

  // declare the output memory array for the sub pairs
  StubPairMemory outputstubpairs; //produced by hls simulation

  // open input files from emulation
  auto &fin_vmstubsinner = tb.files(innerStubPattern);
  auto &fin_vmstubsouter = tb.files(outerStubPattern);
  auto &fin_stubpairs = tb.files("StubPairs_SP_*");

  ap_uint<1> bendinnertable[] =
#include INNER_TABLE_
  ap_uint<1> bendoutertable[] =
#include OUTER_TABLE_

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    outputstubpairs.clear();

    //read next event from the input files
    writeMemFromFile<VMStubTEInnerMemory<InnerStubType> >(inputvmstubsinner, fin_vmstubsinner.at(0), ievt);
    writeMemFromFile<VMStubTEOuterMemory<OuterStubType> >(inputvmstubsouter, fin_vmstubsouter.at(0), ievt);

    //set the bunch crossing
    BXType bx=ievt&0x7;
    BXType bx_o;

    // Unit Under Test
    TOP_FUNC_(bx, inputvmstubsinner, inputvmstubsouter, bendinnertable, bendoutertable, bx_o, outputstubpairs);

    bool truncation = false;

    // compare calculated outputs with those read from emulation printout
    err_count += compareMemWithFile<StubPairMemory>(outputstubpairs, fin_stubpairs.at(0), ievt, "StubPair", truncation);

  }  // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err_count > 255) err_count = 255;
  return err_count;
}
