// Test bench for TrackletCalculator
#include "TrackletCalculator.hh"

#include <algorithm>
#include <iterator>
#include <cstring>

#include "FileReadUtility.hh"
#include "Constants.hh"

const int nevents = 100;  //number of events to run

using namespace std;

int main(int argc, char *argv[])
{
  // toggle truncation
  bool truncate = argc < 2 || strcmp(argv[1], "0");
  cout << "Truncation: " << (truncate ? "ON" : "OFF") << endl;

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static AllStubMemory<BARRELPS> innerStubs[2];
  static AllStubMemory<BARRELPS> outerStubs[1];
  static StubPairMemory stubPairs[13];

  // output memories
  static TrackletParameterMemory tpar;
  static TrackletProjectionMemory<BARRELPS> tproj_L3PHIB;
  static TrackletProjectionMemory<BARREL2S> tproj_L4PHIA;
  static TrackletProjectionMemory<BARREL2S> tproj_L4PHIB;
  static TrackletProjectionMemory<BARREL2S> tproj_L4PHIC;
  static TrackletProjectionMemory<BARREL2S> tproj_L5PHIA;
  static TrackletProjectionMemory<BARREL2S> tproj_L5PHIB;
  static TrackletProjectionMemory<BARREL2S> tproj_L5PHIC;
  static TrackletProjectionMemory<BARREL2S> tproj_L6PHIA;
  static TrackletProjectionMemory<BARREL2S> tproj_L6PHIB;
  static TrackletProjectionMemory<BARREL2S> tproj_L6PHIC;
  static TrackletProjectionMemory<DISK> tproj_D1PHIA;
  static TrackletProjectionMemory<DISK> tproj_D1PHIB;
  static TrackletProjectionMemory<DISK> tproj_D1PHIC;
  static TrackletProjectionMemory<DISK> tproj_D2PHIA;
  static TrackletProjectionMemory<DISK> tproj_D2PHIB;
  static TrackletProjectionMemory<DISK> tproj_D2PHIC;
  static TrackletProjectionMemory<DISK> tproj_D3PHIA;
  static TrackletProjectionMemory<DISK> tproj_D3PHIB;
  static TrackletProjectionMemory<DISK> tproj_D3PHIC;
  static TrackletProjectionMemory<DISK> tproj_D4PHIA;
  static TrackletProjectionMemory<DISK> tproj_D4PHIB;
  static TrackletProjectionMemory<DISK> tproj_D4PHIC;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  const string dir = (truncate ? "TC_L1L2E_truncated" : "TC_L1L2E");

  ifstream fin_innerStubs0;
  if (not openDataFile(fin_innerStubs0, dir + "/AllStubs_AS_L1PHICn3_04.dat")) return -1;

  ifstream fin_innerStubs1;
  if (not openDataFile(fin_innerStubs1, dir + "/AllStubs_AS_L1PHIDn1_04.dat")) return -1;

  ifstream fin_outerStubs;
  if (not openDataFile(fin_outerStubs, dir + "/AllStubs_AS_L2PHIBn3_04.dat")) return -1;

  ifstream fin_stubPairs0;
  if (not openDataFile(fin_stubPairs0, dir + "/StubPairs_SP_L1PHIC12_L2PHIB10_04.dat")) return -1;

  ifstream fin_stubPairs1;
  if (not openDataFile(fin_stubPairs1, dir + "/StubPairs_SP_L1PHIC12_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs2;
  if (not openDataFile(fin_stubPairs2, dir + "/StubPairs_SP_L1PHIC12_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs3;
  if (not openDataFile(fin_stubPairs3, dir + "/StubPairs_SP_L1PHIC12_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs4;
  if (not openDataFile(fin_stubPairs4, dir + "/StubPairs_SP_L1PHIC12_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs5;
  if (not openDataFile(fin_stubPairs5, dir + "/StubPairs_SP_L1PHID13_L2PHIB11_04.dat")) return -1;

  ifstream fin_stubPairs6;
  if (not openDataFile(fin_stubPairs6, dir + "/StubPairs_SP_L1PHID13_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs7;
  if (not openDataFile(fin_stubPairs7, dir + "/StubPairs_SP_L1PHID13_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs8;
  if (not openDataFile(fin_stubPairs8, dir + "/StubPairs_SP_L1PHID13_L2PHIB14_04.dat")) return -1;

  ifstream fin_stubPairs9;
  if (not openDataFile(fin_stubPairs9, dir + "/StubPairs_SP_L1PHID13_L2PHIB15_04.dat")) return -1;

  ifstream fin_stubPairs10;
  if (not openDataFile(fin_stubPairs10, dir + "/StubPairs_SP_L1PHID14_L2PHIB12_04.dat")) return -1;

  ifstream fin_stubPairs11;
  if (not openDataFile(fin_stubPairs11, dir + "/StubPairs_SP_L1PHID14_L2PHIB13_04.dat")) return -1;

  ifstream fin_stubPairs12;
  if (not openDataFile(fin_stubPairs12, dir + "/StubPairs_SP_L1PHID14_L2PHIB14_04.dat")) return -1;


  ///////////////////////////
  // open output files
  ifstream fout_tpar;
  if (not openDataFile(fout_tpar, dir + "/TrackletParameters_TPAR_L1L2E_04.dat")) return -1;

  ifstream fout_tproj0;
  if (not openDataFile(fout_tproj0, dir + "/TrackletProjections_TPROJ_L1L2E_L3PHIB_04.dat")) return -1;

  ifstream fout_tproj1;
  if (not openDataFile(fout_tproj1, dir + "/TrackletProjections_TPROJ_L1L2E_L4PHIA_04.dat")) return -1;

  ifstream fout_tproj2;
  if (not openDataFile(fout_tproj2, dir + "/TrackletProjections_TPROJ_L1L2E_L4PHIB_04.dat")) return -1;

  ifstream fout_tproj3;
  if (not openDataFile(fout_tproj3, dir + "/TrackletProjections_TPROJ_L1L2E_L4PHIC_04.dat")) return -1;

  ifstream fout_tproj4;
  if (not openDataFile(fout_tproj4, dir + "/TrackletProjections_TPROJ_L1L2E_L5PHIA_04.dat")) return -1;

  ifstream fout_tproj5;
  if (not openDataFile(fout_tproj5, dir + "/TrackletProjections_TPROJ_L1L2E_L5PHIB_04.dat")) return -1;

  ifstream fout_tproj6;
  if (not openDataFile(fout_tproj6, dir + "/TrackletProjections_TPROJ_L1L2E_L5PHIC_04.dat")) return -1;

  ifstream fout_tproj7;
  if (not openDataFile(fout_tproj7, dir + "/TrackletProjections_TPROJ_L1L2E_L6PHIA_04.dat")) return -1;

  ifstream fout_tproj8;
  if (not openDataFile(fout_tproj8, dir + "/TrackletProjections_TPROJ_L1L2E_L6PHIB_04.dat")) return -1;

  ifstream fout_tproj9;
  if (not openDataFile(fout_tproj9, dir + "/TrackletProjections_TPROJ_L1L2E_L6PHIC_04.dat")) return -1;

  ifstream fout_tproj10;
  if (not openDataFile(fout_tproj10, dir + "/TrackletProjections_TPROJ_L1L2E_D1PHIA_04.dat")) return -1;

  ifstream fout_tproj11;
  if (not openDataFile(fout_tproj11, dir + "/TrackletProjections_TPROJ_L1L2E_D1PHIB_04.dat")) return -1;

  ifstream fout_tproj12;
  if (not openDataFile(fout_tproj12, dir + "/TrackletProjections_TPROJ_L1L2E_D1PHIC_04.dat")) return -1;

  ifstream fout_tproj13;
  if (not openDataFile(fout_tproj13, dir + "/TrackletProjections_TPROJ_L1L2E_D2PHIA_04.dat")) return -1;

  ifstream fout_tproj14;
  if (not openDataFile(fout_tproj14, dir + "/TrackletProjections_TPROJ_L1L2E_D2PHIB_04.dat")) return -1;

  ifstream fout_tproj15;
  if (not openDataFile(fout_tproj15, dir + "/TrackletProjections_TPROJ_L1L2E_D2PHIC_04.dat")) return -1;

  ifstream fout_tproj16;
  if (not openDataFile(fout_tproj16, dir + "/TrackletProjections_TPROJ_L1L2E_D3PHIA_04.dat")) return -1;

  ifstream fout_tproj17;
  if (not openDataFile(fout_tproj17, dir + "/TrackletProjections_TPROJ_L1L2E_D3PHIB_04.dat")) return -1;

  ifstream fout_tproj18;
  if (not openDataFile(fout_tproj18, dir + "/TrackletProjections_TPROJ_L1L2E_D3PHIC_04.dat")) return -1;

  ifstream fout_tproj19;
  if (not openDataFile(fout_tproj19, dir + "/TrackletProjections_TPROJ_L1L2E_D4PHIA_04.dat")) return -1;

  ifstream fout_tproj20;
  if (not openDataFile(fout_tproj20, dir + "/TrackletProjections_TPROJ_L1L2E_D4PHIB_04.dat")) return -1;

  ifstream fout_tproj21;
  if (not openDataFile(fout_tproj21, dir + "/TrackletProjections_TPROJ_L1L2E_D4PHIC_04.dat")) return -1;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<AllStubMemory<BARRELPS> >(innerStubs[0], fin_innerStubs0, ievt);
    writeMemFromFile<AllStubMemory<BARRELPS> >(innerStubs[1], fin_innerStubs1, ievt);
    writeMemFromFile<AllStubMemory<BARRELPS> >(outerStubs[0], fin_outerStubs, ievt);
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
    writeMemFromFile<StubPairMemory>(stubPairs[11], fin_stubPairs11, ievt);
    writeMemFromFile<StubPairMemory>(stubPairs[12], fin_stubPairs12, ievt);

    // bx
    BXType bx = ievt;

    const uint8_t NASMemInner = 2;
    const uint8_t NASMemOuter = 1;
    const uint8_t NSPMem00 = 5;
    const uint8_t NSPMem01 = 0;
    const uint8_t NSPMem10 = 8;
    const uint8_t NSPMem11 = 0;

    // This is the maximum number of stub pairs, if every stub pair memory is
    // filled to capacity.
    const uint16_t N = (NSPMem00 + NSPMem01 + NSPMem10 + NSPMem11) * (1 << kNBits_MemAddr);

    void (*TC) (
        const BXType,
        const AllStubMemory<BARRELPS> [],
        const AllStubMemory<BARRELPS> [],
        const StubPairMemory [],
        TrackletParameterMemory * const,
        TrackletProjectionMemory<BARRELPS> * const,
        TrackletProjectionMemory<BARRELPS> * const,
        TrackletProjectionMemory<BARRELPS> * const,
        TrackletProjectionMemory<BARRELPS> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<BARREL2S> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const,
        TrackletProjectionMemory<DISK> * const
    );

    // The last parameter is how many stub pairs to process.
    if (truncate)
      TC = &TrackletCalculator_L1L2E;
    else
      TC = &TrackletCalculator_L1L2<TC::E, NASMemInner, NASMemOuter, NSPMem00, NSPMem01, NSPMem10, NSPMem11, 0x77777772, N>;

    // Unit Under Test
    TC(bx, innerStubs, outerStubs, stubPairs,
       &tpar,
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
       NULL
    );

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar, ievt,
                                                   "\nTrackletParameter", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_L3PHIB, fout_tproj0, ievt,
                                                   "\nTrackletProjection (L3PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L4PHIA, fout_tproj1, ievt,
                                                   "\nTrackletProjection (L4PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L4PHIB, fout_tproj2, ievt,
                                                   "\nTrackletProjection (L4PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L4PHIC, fout_tproj3, ievt,
                                                   "\nTrackletProjection (L4PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L5PHIA, fout_tproj4, ievt,
                                                   "\nTrackletProjection (L5PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L5PHIB, fout_tproj5, ievt,
                                                   "\nTrackletProjection (L5PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L5PHIC, fout_tproj6, ievt,
                                                   "\nTrackletProjection (L5PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L6PHIA, fout_tproj7, ievt,
                                                   "\nTrackletProjection (L6PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L6PHIB, fout_tproj8, ievt,
                                                   "\nTrackletProjection (L6PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_L6PHIC, fout_tproj9, ievt,
                                                   "\nTrackletProjection (L6PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIA, fout_tproj10, ievt,
                                                   "\nTrackletProjection (D1PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIB, fout_tproj11, ievt,
                                                   "\nTrackletProjection (D1PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D1PHIC, fout_tproj12, ievt,
                                                   "\nTrackletProjection (D1PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIA, fout_tproj13, ievt,
                                                   "\nTrackletProjection (D2PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIB, fout_tproj14, ievt,
                                                   "\nTrackletProjection (D2PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D2PHIC, fout_tproj15, ievt,
                                                   "\nTrackletProjection (D2PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIA, fout_tproj16, ievt,
                                                   "\nTrackletProjection (D3PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIB, fout_tproj17, ievt,
                                                   "\nTrackletProjection (D3PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D3PHIC, fout_tproj18, ievt,
                                                   "\nTrackletProjection (D3PHIC)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIA, fout_tproj19, ievt,
                                                   "\nTrackletProjection (D4PHIA)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIB, fout_tproj20, ievt,
                                                   "\nTrackletProjection (D4PHIB)", truncate);
    err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_D4PHIC, fout_tproj21, ievt,
                                                   "\nTrackletProjection (D4PHIC)", truncate);
    cout << endl;

  } // end of event loop

  return err;

}
