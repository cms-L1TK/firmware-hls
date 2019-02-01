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
  static TrackletProjectionMemory<INNER> tproj_L3PHIA;
  static TrackletProjectionMemory<INNER> tproj_L3PHIB;
  static TrackletProjectionMemory<INNER> tproj_L3PHIC;
  static TrackletProjectionMemory<INNER> tproj_L3PHID;
  static TrackletProjectionMemory<OUTER> tproj_L4PHIA;
  static TrackletProjectionMemory<OUTER> tproj_L4PHIB;
  static TrackletProjectionMemory<OUTER> tproj_L4PHIC;
  static TrackletProjectionMemory<OUTER> tproj_L4PHID;
  static TrackletProjectionMemory<OUTER> tproj_L5PHIA;
  static TrackletProjectionMemory<OUTER> tproj_L5PHIB;
  static TrackletProjectionMemory<OUTER> tproj_L5PHIC;
  static TrackletProjectionMemory<OUTER> tproj_L5PHID;
  static TrackletProjectionMemory<OUTER> tproj_L6PHIA;
  static TrackletProjectionMemory<OUTER> tproj_L6PHIB;
  static TrackletProjectionMemory<OUTER> tproj_L6PHIC;
  static TrackletProjectionMemory<OUTER> tproj_L6PHID;
  static TrackletProjectionMemory<DISK> tproj_D1PHIA;
  static TrackletProjectionMemory<DISK> tproj_D1PHIB;
  static TrackletProjectionMemory<DISK> tproj_D1PHIC;
  static TrackletProjectionMemory<DISK> tproj_D1PHID;
  static TrackletProjectionMemory<DISK> tproj_D2PHIA;
  static TrackletProjectionMemory<DISK> tproj_D2PHIB;
  static TrackletProjectionMemory<DISK> tproj_D2PHIC;
  static TrackletProjectionMemory<DISK> tproj_D2PHID;
  static TrackletProjectionMemory<DISK> tproj_D3PHIA;
  static TrackletProjectionMemory<DISK> tproj_D3PHIB;
  static TrackletProjectionMemory<DISK> tproj_D3PHIC;
  static TrackletProjectionMemory<DISK> tproj_D3PHID;
  static TrackletProjectionMemory<DISK> tproj_D4PHIA;
  static TrackletProjectionMemory<DISK> tproj_D4PHIB;
  static TrackletProjectionMemory<DISK> tproj_D4PHIC;
  static TrackletProjectionMemory<DISK> tproj_D4PHID;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_innerStubs0;
  if (not openDataFile(fin_innerStubs0, "TC_L1L2E/AllStubs_AS_L1PHICn3_04.dat")) return -1;

  ifstream fin_innerStubs1;
  if (not openDataFile(fin_innerStubs1, "TC_L1L2E/AllStubs_AS_L1PHIDn1_04.dat")) return -1;

  ifstream fin_outerStubs;
  if (not openDataFile(fin_outerStubs, "TC_L1L2E/AllStubs_AS_L2PHIBn3_04.dat")) return -1;

  ifstream fin_stubPairs0;
  if (not openDataFile(fin_stubPairs0, "TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB10_04.dat")) return -1;

  ifstream fin_stubPairs1;
  if (not openDataFile(fin_stubPairs1, "TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs2;
  if (not openDataFile(fin_stubPairs2, "TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs3;
  if (not openDataFile(fin_stubPairs3, "TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs4;
  if (not openDataFile(fin_stubPairs4, "TC_L1L2E/StubPairs_SP_L1PHIC12_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs5;
  if (not openDataFile(fin_stubPairs5, "TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs6;
  if (not openDataFile(fin_stubPairs6, "TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs7;
  if (not openDataFile(fin_stubPairs7, "TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs8;
  if (not openDataFile(fin_stubPairs8, "TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs9;
  if (not openDataFile(fin_stubPairs9, "TC_L1L2E/StubPairs_SP_L1PHID13_L2PHIB15_04.dat")) return -1;

  ifstream fin_stubPairs10;
  if (not openDataFile(fin_stubPairs10, "TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs11;
  if (not openDataFile(fin_stubPairs11, "TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs12;
  if (not openDataFile(fin_stubPairs12, "TC_L1L2E/StubPairs_SP_L1PHID14_L2PHIB14_04.dat")) return -1;


  ///////////////////////////
  // open output files
  ifstream fout_tpar;
  if (not openDataFile(fout_tpar, "TC_L1L2E/TrackletParameters_TPAR_L1L2E_04.dat")) return -1;

  ifstream fout_tproj0;
  if (not openDataFile(fout_tproj0, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L3PHIB_04.dat")) return -1;

  ifstream fout_tproj1;
  if (not openDataFile(fout_tproj1, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L4PHIA_04.dat")) return -1;

  ifstream fout_tproj2;
  if (not openDataFile(fout_tproj2, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L4PHIB_04.dat")) return -1;

  ifstream fout_tproj3;
  if (not openDataFile(fout_tproj3, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L4PHIC_04.dat")) return -1;

  ifstream fout_tproj4;
  if (not openDataFile(fout_tproj4, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L5PHIA_04.dat")) return -1;

  ifstream fout_tproj5;
  if (not openDataFile(fout_tproj5, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L5PHIB_04.dat")) return -1;

  ifstream fout_tproj6;
  if (not openDataFile(fout_tproj6, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L5PHIC_04.dat")) return -1;

  ifstream fout_tproj7;
  if (not openDataFile(fout_tproj7, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L6PHIA_04.dat")) return -1;

  ifstream fout_tproj8;
  if (not openDataFile(fout_tproj8, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L6PHIB_04.dat")) return -1;

  ifstream fout_tproj9;
  if (not openDataFile(fout_tproj9, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_L6PHIC_04.dat")) return -1;

  ifstream fout_tproj10;
  if (not openDataFile(fout_tproj10, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D1PHIA_04.dat")) return -1;

  ifstream fout_tproj11;
  if (not openDataFile(fout_tproj11, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D1PHIB_04.dat")) return -1;

  ifstream fout_tproj12;
  if (not openDataFile(fout_tproj12, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D1PHIC_04.dat")) return -1;

  ifstream fout_tproj13;
  if (not openDataFile(fout_tproj13, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D2PHIA_04.dat")) return -1;

  ifstream fout_tproj14;
  if (not openDataFile(fout_tproj14, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D2PHIB_04.dat")) return -1;

  ifstream fout_tproj15;
  if (not openDataFile(fout_tproj15, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D2PHIC_04.dat")) return -1;

  ifstream fout_tproj16;
  if (not openDataFile(fout_tproj16, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D3PHIA_04.dat")) return -1;

  ifstream fout_tproj17;
  if (not openDataFile(fout_tproj17, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D3PHIB_04.dat")) return -1;

  ifstream fout_tproj18;
  if (not openDataFile(fout_tproj18, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D3PHIC_04.dat")) return -1;

  ifstream fout_tproj19;
  if (not openDataFile(fout_tproj19, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D4PHIA_04.dat")) return -1;

  ifstream fout_tproj20;
  if (not openDataFile(fout_tproj20, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D4PHIB_04.dat")) return -1;

  ifstream fout_tproj21;
  if (not openDataFile(fout_tproj21, "TC_L1L2E/TrackletProjections_TPROJ_L1L2E_D4PHIC_04.dat")) return -1;

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
    writeMemFromFile<StubPairMemory>(stubPairs10[0], fin_stubPairs5, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[1], fin_stubPairs6, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[2], fin_stubPairs7, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[3], fin_stubPairs8, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[4], fin_stubPairs9, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[5], fin_stubPairs10, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[6], fin_stubPairs11, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs10[7], fin_stubPairs12, ievt);

    // bx
    BXType bx = ievt;

    // Unit Under Test
    TrackletCalculator_L1L2<5, 8>(bx, 4,
                        innerStubs, outerStubs, stubPairs00, stubPairs10,
                        &tpar,
                        &tproj_L3PHIA,
                        &tproj_L3PHIB,
                        &tproj_L3PHIC,
                        &tproj_L3PHID,
                        &tproj_L4PHIA,
                        &tproj_L4PHIB,
                        &tproj_L4PHIC,
                        &tproj_L4PHID,
                        &tproj_L5PHIA,
                        &tproj_L5PHIB,
                        &tproj_L5PHIC,
                        &tproj_L5PHID,
                        &tproj_L6PHIA,
                        &tproj_L6PHIB,
                        &tproj_L6PHIC,
                        &tproj_L6PHID,
                        &tproj_D1PHIA,
                        &tproj_D1PHIB,
                        &tproj_D1PHIC,
                        &tproj_D1PHID,
                        &tproj_D2PHIA,
                        &tproj_D2PHIB,
                        &tproj_D2PHIC,
                        &tproj_D2PHID,
                        &tproj_D3PHIA,
                        &tproj_D3PHIB,
                        &tproj_D3PHIC,
                        &tproj_D3PHID,
                        &tproj_D4PHIA,
                        &tproj_D4PHIB,
                        &tproj_D4PHIC,
                        &tproj_D4PHID
    );

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar, ievt,
                                                   "\nTrackletParameter");
    err += compareMemWithFile<TrackletProjectionMemory<INNER> >(tproj_L3PHIB, fout_tproj0, ievt,
                                                   "\nTrackletProjection (L3PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L4PHIA, fout_tproj1, ievt,
                                                   "\nTrackletProjection (L4PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L4PHIB, fout_tproj2, ievt,
                                                   "\nTrackletProjection (L4PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L4PHIC, fout_tproj3, ievt,
                                                   "\nTrackletProjection (L4PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L5PHIA, fout_tproj4, ievt,
                                                   "\nTrackletProjection (L5PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L5PHIB, fout_tproj5, ievt,
                                                   "\nTrackletProjection (L5PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L5PHIC, fout_tproj6, ievt,
                                                   "\nTrackletProjection (L5PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L6PHIA, fout_tproj7, ievt,
                                                   "\nTrackletProjection (L6PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L6PHIB, fout_tproj8, ievt,
                                                   "\nTrackletProjection (L6PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<OUTER> >(tproj_L6PHIC, fout_tproj9, ievt,
                                                   "\nTrackletProjection (L6PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIA, fout_tproj10, ievt,
                                                   "\nTrackletProjection (D1PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIB, fout_tproj11, ievt,
                                                   "\nTrackletProjection (D1PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIC, fout_tproj12, ievt,
                                                   "\nTrackletProjection (D1PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIA, fout_tproj13, ievt,
                                                   "\nTrackletProjection (D2PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIB, fout_tproj14, ievt,
                                                   "\nTrackletProjection (D2PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIC, fout_tproj15, ievt,
                                                   "\nTrackletProjection (D2PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIA, fout_tproj16, ievt,
                                                   "\nTrackletProjection (D3PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIB, fout_tproj17, ievt,
                                                   "\nTrackletProjection (D3PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIC, fout_tproj18, ievt,
                                                   "\nTrackletProjection (D3PHIC)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIA, fout_tproj19, ievt,
                                                   "\nTrackletProjection (D4PHIA)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIB, fout_tproj20, ievt,
                                                   "\nTrackletProjection (D4PHIB)");
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIC, fout_tproj21, ievt,
                                                   "\nTrackletProjection (D4PHIC)");
    cout << endl;

  } // end of event loop

  return err;

}
