// Test bench for TrackBuilder
#include "TrackBuilderTop.h"

#include "Macros.h"
#include "FileReadUtility.h"

const int nevents = 100;  //number of events to run

using namespace std;

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined SEED_
  #define SEED_ AAAA_
#endif
#if !defined MODULE_
  #define MODULE_ TB_AAAA_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ TrackBuilder_AAAA
#endif

typedef TrackFit<trklet::N_LAYER, trklet::N_DISK> TrackFit_t;
typedef TrackFitMemory<trklet::N_LAYER, trklet::N_DISK> TrackFitMemory_t;

// Base assumed for input test vector files
constexpr int InputBase = 16;
// Base used for output of comparison results
//   (only base 2 and base 16 are supported)
constexpr int OutputBase = 16;

template<int I>
void setBarrelStubs(TrackFit_t &track, const TrackFit_t::BarrelStubWord stubWords[][kMaxProc], const unsigned i) {
  track.setBarrelStubWord<I>(stubWords[I][i]);
  setBarrelStubs<I - 1>(track, stubWords, i);
}

template<>
void setBarrelStubs<-1>(TrackFit_t &track, const TrackFit_t::BarrelStubWord stubWords[][kMaxProc], const unsigned i) {
}

template<int I>
void setDiskStubs(TrackFit_t &track, const TrackFit_t::DiskStubWord stubWords[][kMaxProc], const unsigned i) {
  track.setDiskStubWord<I + trklet::N_LAYER>(stubWords[I][i]);
  setDiskStubs<I - 1>(track, stubWords, i);
}

template<>
void setDiskStubs<-1>(TrackFit_t &track, const TrackFit_t::DiskStubWord stubWords[][kMaxProc], const unsigned i) {
}

template<int I>
void compareStubsWithFile(int &err, ifstream &fout, const int pos, const TrackFitMemory_t &tracksMem, const unsigned ievt) {
  fout.clear(), fout.seekg(pos);
  stringstream ss("");
  ss << "\nStub " << (I) << " word";
  err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFStubRZResidLSB(I),TrackFit_t::kTFStubValidMSB(I)>(tracksMem, fout, ievt, ss.str(), true, true);
  compareStubsWithFile<I - 1>(err, fout, pos, tracksMem, ievt);
}

template<>
void compareStubsWithFile<0>(int &err, ifstream &fout, const int pos, const TrackFitMemory_t &tracksMem, const unsigned ievt) {
  fout.clear(), fout.seekg(pos);
  err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFStubRZResidLSB(0),TrackFit_t::kTFStubValidMSB(0)>(tracksMem, fout, ievt, "\nStub 0 word", true, true);
}

int main()
{
  TBHelper tb(string("TB/") + module_name[MODULE_]);

  // error counts
  int err = 0;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  const string tpar1_query = "TrackletParameters_MPAR_?????_*";
  const string tpar2_query = "TrackletParameters_MPAR_??????_*";
  const string tpar3_query = "TrackletParameters_MPAR_???????_*";
  const string tpar4_query = "TrackletParameters_MPAR_????????_*";
  const string barrelFM_query = "FullMatches_FM_*_L*";
  const string diskFM_query = "FullMatches_FM_*_D*";

  auto &fin_tpar1 = tb.files(tpar1_query);
  auto &fin_tpar2 = tb.files(tpar2_query);
  auto &fin_tpar3 = tb.files(tpar3_query);
  auto &fin_tpar4 = tb.files(tpar4_query);
  auto &fin_barrelFM = tb.files(barrelFM_query);
  auto &fin_diskFM = tb.files(diskFM_query);

  ///////////////////////////
  // open output files
  auto &fout_tracks = tb.files("TrackFit*");

  ///////////////////////////
  // input memories
  const auto nTPar1Mems = fin_tpar1.size();
  const auto nTPar2Mems = fin_tpar2.size();
  const auto nTPar3Mems = fin_tpar3.size();
  const auto nTPar4Mems = fin_tpar4.size();
  const auto nFMBarrelMems = fin_barrelFM.size();
  const auto nFMDiskMems = fin_diskFM.size();
  vector<TrackletParameterMemory1> trackletParameters1(nTPar1Mems);
  vector<TrackletParameterMemory2> trackletParameters2(nTPar2Mems);
  vector<TrackletParameterMemory3> trackletParameters3(nTPar3Mems);
  vector<TrackletParameterMemory4> trackletParameters4(nTPar4Mems);
  vector<FullMatchMemory<BARREL>> barrelFullMatches(nFMBarrelMems);
  vector<FullMatchMemory<DISK>> diskFullMatches(nFMDiskMems);

  // output memories
  TrackFit_t::TrackWord trackWord[kMaxProc];
  TrackFit_t::BarrelStubWord barrelStubWords[trklet::N_LAYER][kMaxProc];
  TrackFit_t::DiskStubWord diskStubWords[trklet::N_DISK][kMaxProc];
  TrackFitMemory_t tracksMem;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear all output memories before starting.
    for (unsigned short i = 0; i < kMaxProc; i++) {
      trackWord[i] = TrackFit_t::TrackWord(0);
      for (short j = 0; j < trklet::N_LAYER; j++)
        barrelStubWords[j][i] = TrackFit_t::BarrelStubWord(0);
      for (short j = 0; j < trklet::N_DISK; j++)
        diskStubWords[j][i] = TrackFit_t::DiskStubWord(0);
    }
    tracksMem.clear();
    tracksMem.setWriteBX(ievt);

    // read event and write to memories
    for (unsigned i = 0; i < nTPar1Mems; i++)
      writeMemFromFile<TrackletParameterMemory1>(trackletParameters1[i], fin_tpar1.at(i), ievt);
    for (unsigned i = 0; i < nTPar2Mems; i++)
      writeMemFromFile<TrackletParameterMemory2>(trackletParameters2[i], fin_tpar2.at(i), ievt);
    for (unsigned i = 0; i < nTPar3Mems; i++)
      writeMemFromFile<TrackletParameterMemory3>(trackletParameters3[i], fin_tpar3.at(i), ievt);
    for (unsigned i = 0; i < nTPar4Mems; i++)
      writeMemFromFile<TrackletParameterMemory4>(trackletParameters4[i], fin_tpar4.at(i), ievt);
    for (unsigned i = 0; i < nFMBarrelMems; i++)
      writeMemFromFile<FullMatchMemory<BARREL> >(barrelFullMatches[i], fin_barrelFM.at(i), ievt);
    for (unsigned i = 0; i < nFMDiskMems; i++)
      writeMemFromFile<FullMatchMemory<DISK> >(diskFullMatches[i], fin_diskFM.at(i), ievt);

    // bx
    BXType bx = ievt;
    BXType bx_o;
    bool done;

    // Unit Under Test
    TOP_FUNC_(bx,
      trackletParameters1.data(),
      trackletParameters2.data(),
      trackletParameters3.data(),
      trackletParameters4.data(),
      barrelFullMatches.data(),
      diskFullMatches.data(),
      bx_o,
      trackWord,
      barrelStubWords,
      diskStubWords,
      done
    );

    for (unsigned short i = 0; i < kMaxProc; i++) {
      TrackFit_t track;
      track.setTrackWord(trackWord[i]);
      setBarrelStubs<trklet::N_LAYER - 1>(track, barrelStubWords, i);
      setDiskStubs<trklet::N_DISK - 1>(track, diskStubWords, i);
      if (track.getTrackValid())
        tracksMem.write_mem(track);
    }

    const auto &pos = fout_tracks.at(0).tellg();

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFHitMapLSB,TrackFit_t::kTFTrackValidMSB>(tracksMem, fout_tracks.at(0), ievt, "\nTrack word", true);
    compareStubsWithFile<trklet::N_LAYER + trklet::N_DISK - 1>(err, fout_tracks.at(0), pos, tracksMem, ievt);
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
