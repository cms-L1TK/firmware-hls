// Test bench for TrackletCalculator
#include "TrackletCalculator.h"

#include <algorithm>
#include <iterator>
#include <cstring>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static AllStubMemory<BARRELPS> innerStubs[1];
  static AllStubMemory<BARREL2S> outerStubs[2];
  static StubPairMemory stubPairs[11];

  // output memories
  static TrackletParameterMemory tpar;
  static TrackletProjectionMemory<BARRELPS> tproj_barrel_ps[TC::N_PROJOUT_BARRELPS];
  static TrackletProjectionMemory<BARREL2S> tproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  static TrackletProjectionMemory<DISK> tproj_disk[TC::N_PROJOUT_DISK];

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  const string dir = "TC_L3L4E";

  ifstream fin_innerStubs;
  if (not openDataFile(fin_innerStubs, dir + "/AllStubs_AS_L3PHICn3_04.dat")) return -1;

  ifstream fin_outerStubs0;
  if (not openDataFile(fin_outerStubs0, dir + "/AllStubs_AS_L4PHIBn4_04.dat")) return -1;

  ifstream fin_outerStubs1;
  if (not openDataFile(fin_outerStubs1, dir + "/AllStubs_AS_L4PHICn2_04.dat")) return -1;

  ifstream fin_stubPairs0;
  if (not openDataFile(fin_stubPairs0, dir + "/StubPairs_SP_L3PHIC9_L4PHIB16_04.dat")) return -1;

  ifstream fin_stubPairs1;
  if (not openDataFile(fin_stubPairs1, dir + "/StubPairs_SP_L3PHIC9_L4PHIC17_04.dat")) return -1;

  ifstream fin_stubPairs2;
  if (not openDataFile(fin_stubPairs2, dir + "/StubPairs_SP_L3PHIC9_L4PHIC18_04.dat")) return -1;

  ifstream fin_stubPairs3;
  if (not openDataFile(fin_stubPairs3, dir + "/StubPairs_SP_L3PHIC9_L4PHIC19_04.dat")) return -1;

  ifstream fin_stubPairs4;
  if (not openDataFile(fin_stubPairs4, dir + "/StubPairs_SP_L3PHIC9_L4PHIC20_04.dat")) return -1;

  ifstream fin_stubPairs5;
  if (not openDataFile(fin_stubPairs5, dir + "/StubPairs_SP_L3PHIC9_L4PHIC21_04.dat")) return -1;

  ifstream fin_stubPairs6;
  if (not openDataFile(fin_stubPairs6, dir + "/StubPairs_SP_L3PHIC10_L4PHIC18_04.dat")) return -1;

  ifstream fin_stubPairs7;
  if (not openDataFile(fin_stubPairs7, dir + "/StubPairs_SP_L3PHIC10_L4PHIC19_04.dat")) return -1;

  ifstream fin_stubPairs8;
  if (not openDataFile(fin_stubPairs8, dir + "/StubPairs_SP_L3PHIC10_L4PHIC20_04.dat")) return -1;

  ifstream fin_stubPairs9;
  if (not openDataFile(fin_stubPairs9, dir + "/StubPairs_SP_L3PHIC10_L4PHIC21_04.dat")) return -1;

  ifstream fin_stubPairs10;
  if (not openDataFile(fin_stubPairs10, dir + "/StubPairs_SP_L3PHIC10_L4PHIC22_04.dat")) return -1;

  ///////////////////////////
  // open output files
  ifstream fout_tpar;
  if (not openDataFile(fout_tpar, dir + "/TrackletParameters_TPAR_L3L4E_04.dat")) return -1;

  ifstream fout_tproj0;
  if (not openDataFile(fout_tproj0, dir + "/TrackletProjections_TPROJ_L3L4E_L1PHID_04.dat")) return -1;

  ifstream fout_tproj1;
  if (not openDataFile(fout_tproj1, dir + "/TrackletProjections_TPROJ_L3L4E_L1PHIE_04.dat")) return -1;

  ifstream fout_tproj2;
  if (not openDataFile(fout_tproj2, dir + "/TrackletProjections_TPROJ_L3L4E_L1PHIF_04.dat")) return -1;

  ifstream fout_tproj3;
  if (not openDataFile(fout_tproj3, dir + "/TrackletProjections_TPROJ_L3L4E_L2PHIB_04.dat")) return -1;

  ifstream fout_tproj4;
  if (not openDataFile(fout_tproj4, dir + "/TrackletProjections_TPROJ_L3L4E_L2PHIC_04.dat")) return -1;

  ifstream fout_tproj5;
  if (not openDataFile(fout_tproj5, dir + "/TrackletProjections_TPROJ_L3L4E_L5PHIB_04.dat")) return -1;

  ifstream fout_tproj6;
  if (not openDataFile(fout_tproj6, dir + "/TrackletProjections_TPROJ_L3L4E_L5PHIC_04.dat")) return -1;

  ifstream fout_tproj7;
  if (not openDataFile(fout_tproj7, dir + "/TrackletProjections_TPROJ_L3L4E_L6PHIB_04.dat")) return -1;

  ifstream fout_tproj8;
  if (not openDataFile(fout_tproj8, dir + "/TrackletProjections_TPROJ_L3L4E_L6PHIC_04.dat")) return -1;

  ifstream fout_tproj9;
  if (not openDataFile(fout_tproj9, dir + "/TrackletProjections_TPROJ_L3L4E_D1PHIB_04.dat")) return -1;

  ifstream fout_tproj10;
  if (not openDataFile(fout_tproj10, dir + "/TrackletProjections_TPROJ_L3L4E_D1PHIC_04.dat")) return -1;

  ifstream fout_tproj11;
  if (not openDataFile(fout_tproj11, dir + "/TrackletProjections_TPROJ_L3L4E_D2PHIB_04.dat")) return -1;

  ifstream fout_tproj12;
  if (not openDataFile(fout_tproj12, dir + "/TrackletProjections_TPROJ_L3L4E_D2PHIC_04.dat")) return -1;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<AllStubMemory<BARRELPS> >(innerStubs[0], fin_innerStubs, ievt);
    writeMemFromFile<AllStubMemory<BARREL2S> >(outerStubs[0], fin_outerStubs0, ievt);
    writeMemFromFile<AllStubMemory<BARREL2S> >(outerStubs[1], fin_outerStubs1, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[0], fin_stubPairs0, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[1], fin_stubPairs1, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[2], fin_stubPairs2, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[3], fin_stubPairs3, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[4], fin_stubPairs4, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[5], fin_stubPairs5, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[6], fin_stubPairs6, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[7], fin_stubPairs7, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[8], fin_stubPairs8, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[9], fin_stubPairs9, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[10], fin_stubPairs10, ievt);

    // bx
    BXType bx = ievt;

    // Unit Under Test
    TrackletCalculator_L3L4E(bx, innerStubs, outerStubs, stubPairs,
       &tpar,
       tproj_barrel_ps,
       tproj_barrel_2s,
       tproj_disk
    );

    bool truncate;

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar, ievt,
                                                   "\nTrackletParameter", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHID], fout_tproj0, ievt,
                                                   "\nTrackletProjection (L1PHID)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIE], fout_tproj1, ievt,
                                                   "\nTrackletProjection (L1PHIE)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIF], fout_tproj2, ievt,
                                                   "\nTrackletProjection (L1PHIF)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIB], fout_tproj3, ievt,
                                                   "\nTrackletProjection (L2PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIC], fout_tproj4, ievt,
                                                   "\nTrackletProjection (L2PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIB], fout_tproj5, ievt,
                                                   "\nTrackletProjection (L5PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIC], fout_tproj6, ievt,
                                                   "\nTrackletProjection (L5PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIB], fout_tproj7, ievt,
                                                   "\nTrackletProjection (L6PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIC], fout_tproj8, ievt,
                                                   "\nTrackletProjection (L6PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIB], fout_tproj9, ievt,
                                                   "\nTrackletProjection (D1PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIC], fout_tproj10, ievt,
                                                   "\nTrackletProjection (D1PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIB], fout_tproj11, ievt,
                                                   "\nTrackletProjection (D2PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIC], fout_tproj12, ievt,
                                                   "\nTrackletProjection (D2PHIC)", truncate);
    cout << endl;

  } // end of event loop

  return err;

}
