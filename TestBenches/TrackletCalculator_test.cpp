// Test bench for TrackletCalculator
#include "TrackletCalculator.hh"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.hh"
#include "Constants.hh"

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{ 
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static AllStubMemory innerStubs[2];
  static AllStubMemory outerStubs[1];
  static StubPairMemory stubPairs00[13];
  static StubPairMemory stubPairs10[13];

  // output memories
  static TrackletParameterMemory tpar;
  static TrackletProjectionMemory tproj_D1PHIA;
  static TrackletProjectionMemory tproj_D1PHIB;
  static TrackletProjectionMemory tproj_D1PHIC;
  static TrackletProjectionMemory tproj_D2PHIA;
  static TrackletProjectionMemory tproj_D2PHIB;
  static TrackletProjectionMemory tproj_D2PHIC;
  static TrackletProjectionMemory tproj_D3PHIA;
  static TrackletProjectionMemory tproj_D3PHIB;
  static TrackletProjectionMemory tproj_D3PHIC;
  static TrackletProjectionMemory tproj_D4PHIA;
  static TrackletProjectionMemory tproj_D4PHIB;
  static TrackletProjectionMemory tproj_D4PHIC;
  static TrackletProjectionMemory tproj_L3PHIB;
  static TrackletProjectionMemory tproj_L4PHIA;
  static TrackletProjectionMemory tproj_L4PHIB;
  static TrackletProjectionMemory tproj_L4PHIC;
  static TrackletProjectionMemory tproj_L5PHIA;
  static TrackletProjectionMemory tproj_L5PHIB;
  static TrackletProjectionMemory tproj_L5PHIC;
  static TrackletProjectionMemory tproj_L6PHIA;
  static TrackletProjectionMemory tproj_L6PHIB;
  static TrackletProjectionMemory tproj_L6PHIC;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_innerStubs0;
  if (not openDataFile(fin_innerStubs0, "TC/TC_L1L2E/AllStubs_AS_L1PHICn3_04.dat")) return -1;

  ifstream fin_innerStubs1;
  if (not openDataFile(fin_innerStubs1, "TC/TC_L1L2E/AllStubs_AS_L1PHIDn1_04.dat")) return -1;

  ifstream fin_outerStubs;
  if (not openDataFile(fin_outerStubs, "TC/TC_L1L2E/AllStubs_AS_L2PHIBn3_04.dat")) return -1;

  ifstream fin_stubPairs0;
  if (not openDataFile(fin_stubPairs0, "TC/TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB10_04.dat")) return -1;

  ifstream fin_stubPairs1;
  if (not openDataFile(fin_stubPairs1, "TC/TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs2;
  if (not openDataFile(fin_stubPairs2, "TC/TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs3;
  if (not openDataFile(fin_stubPairs3, "TC/TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs4;
  if (not openDataFile(fin_stubPairs4, "TC/TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs5;
  if (not openDataFile(fin_stubPairs5, "TC/TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs6;
  if (not openDataFile(fin_stubPairs6, "TC/TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs7;
  if (not openDataFile(fin_stubPairs7, "TC/TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs8;
  if (not openDataFile(fin_stubPairs8, "TC/TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs9;
  if (not openDataFile(fin_stubPairs9, "TC/TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB15_04.dat")) return -1;

  ifstream fin_stubPairs10;
  if (not openDataFile(fin_stubPairs10, "TC/TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs11;
  if (not openDataFile(fin_stubPairs11, "TC/TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs12;
  if (not openDataFile(fin_stubPairs12, "TC/TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB14_04.dat")) return -1;


  ///////////////////////////
  // open output files
  ifstream fout_tpar;
  if (not openDataFile(fout_tpar, "TC/TC_L1L2E/TrackletParameters_TPAR_L1L2E_04.dat")) return -1;

  ///////////////////////////  
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<AllStubMemory>(innerStubs[0], fin_innerStubs0, ievt);
    writeMemFromFile<AllStubMemory>(innerStubs[1], fin_innerStubs1, ievt);
    writeMemFromFile<AllStubMemory>(outerStubs[0], fin_outerStubs, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs00[0], fin_stubPairs0, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs00[1], fin_stubPairs1, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs00[2], fin_stubPairs2, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs00[3], fin_stubPairs3, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs00[4], fin_stubPairs4, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[5], fin_stubPairs5, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[6], fin_stubPairs6, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[7], fin_stubPairs7, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[8], fin_stubPairs8, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[9], fin_stubPairs9, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[10], fin_stubPairs10, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[11], fin_stubPairs11, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[12], fin_stubPairs12, ievt);
    
    // bx
    BXType bx = ievt;

    // Unit Under Test
    TrackletCalculator<L1L2>(bx,
                        innerStubs, outerStubs, stubPairs00, stubPairs10,
                        &tpar,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        &tproj_L3PHIB,
                        NULL,
                        NULL,
                        &tproj_L4PHIA,
                        &tproj_L4PHIB,
                        &tproj_L4PHIC,
                        NULL,
                        &tproj_L5PHIA,
                        &tproj_L5PHIB,
                        &tproj_L5PHIC,
                        NULL,
                        &tproj_L6PHIA,
                        &tproj_L6PHIB,
                        &tproj_L6PHIC,
                        NULL,
                        &tproj_D1PHIA,
                        &tproj_D1PHIB,
                        &tproj_D1PHIC,
                        NULL,
                        &tproj_D2PHIA,
                        &tproj_D2PHIB,
                        &tproj_D2PHIC,
                        NULL,
                        &tproj_D3PHIA,
                        &tproj_D3PHIB,
                        &tproj_D3PHIC,
                        NULL,
                        &tproj_D4PHIA,
                        &tproj_D4PHIB,
                        &tproj_D4PHIC,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL
    );

    // compare the computed outputs with the expected ones
    // TrackletParameter
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar, ievt,
                                                   "TrackletParameter");
    
  } // end of event loop
  
  return err;
  
}
