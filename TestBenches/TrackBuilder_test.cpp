// Test bench for TrackBuilder
#include "TrackBuilderTop.h"

#include "Macros.h"
#include "FileReadUtility.h"

const int nevents = 100;  //number of events to run

using namespace std;

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined SEED_
  #define SEED_ L1L2_
#endif
#if !defined MODULE_
  #define MODULE_ FT_L1L2_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ TrackBuilder_L1L2
#endif

#if SEED_ == L1L2_
  constexpr unsigned kNBarrelStubs = 4;
  constexpr unsigned kNDiskStubs = 4;
#elif SEED_ == L2L3_
  constexpr unsigned kNBarrelStubs = 3;
  constexpr unsigned kNDiskStubs = 4;
#elif SEED_ == L3L4_
  constexpr unsigned kNBarrelStubs = 4;
  constexpr unsigned kNDiskStubs = 2;
#elif SEED_ == L5L6_
  constexpr unsigned kNBarrelStubs = 4;
  constexpr unsigned kNDiskStubs = 0;
#else
#  error "Undefined seed"
#endif

typedef TrackFit<kNBarrelStubs, kNDiskStubs> TrackFit_t;
typedef TrackFitMemory<kNBarrelStubs, kNDiskStubs> TrackFitMemory_t;

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
  track.setDiskStubWord<I + kNBarrelStubs>(stubWords[I][i]);
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
  err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFStubRZResidLSB(I),TrackFit_t::kTFStubValidMSB(I)>(tracksMem, fout, ievt, ss.str(), true);
  compareStubsWithFile<I - 1>(err, fout, pos, tracksMem, ievt);
}

template<>
void compareStubsWithFile<0>(int &err, ifstream &fout, const int pos, const TrackFitMemory_t &tracksMem, const unsigned ievt) {
  fout.clear(), fout.seekg(pos);
  err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFStubRZResidLSB(0),TrackFit_t::kTFStubValidMSB(0)>(tracksMem, fout, ievt, "\nStub 0 word", true);
}

int main()
{
  TBHelper tb(string("FT/") + module_name[MODULE_]);

  // error counts
  int err = 0;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  const string barrelFM_query = "FullMatches_FM_*_L*";
  const string diskFM_query = "FullMatches_FM_*_D*";

  auto &fin_tpar = tb.files("TrackletParameters*");
  auto &fin_barrelFM = tb.files(barrelFM_query);
  auto &fin_diskFM = tb.files(diskFM_query);

  ///////////////////////////
  // open output files
  auto &fout_tracks = tb.files("TrackFit*");

  ///////////////////////////
  // input memories
  const auto nTParMems = fin_tpar.size();
  const auto nFMBarrelMems = fin_barrelFM.size();
  const auto nFMDiskMems = fin_diskFM.size();
  vector<TrackletParameterMemory> trackletParameters(nTParMems);
  vector<FullMatchMemory<BARREL>> barrelFullMatches(nFMBarrelMems);
  vector<FullMatchMemory<DISK>> diskFullMatches(nFMDiskMems);

  // output memories
  TrackFit_t::TrackWord trackWord[kMaxProc];
  TrackFit_t::BarrelStubWord barrelStubWords[kNBarrelStubs][kMaxProc];
  TrackFit_t::DiskStubWord diskStubWords[kNDiskStubs][kMaxProc];
  TrackFitMemory_t tracksMem;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear all output memories before starting.
    for (unsigned short i = 0; i < kMaxProc; i++) {
      trackWord[i] = TrackFit_t::TrackWord(0);
      for (unsigned short j = 0; j < kNBarrelStubs; j++)
        barrelStubWords[j][i] = TrackFit_t::BarrelStubWord(0);
      for (unsigned short j = 0; j < kNDiskStubs; j++)
        diskStubWords[j][i] = TrackFit_t::DiskStubWord(0);
    }
    tracksMem.clear();

    // read event and write to memories
    for (unsigned i = 0; i < nTParMems; i++)
      writeMemFromFile<TrackletParameterMemory>(trackletParameters[i], fin_tpar.at(i), ievt);
    for (unsigned i = 0; i < nFMBarrelMems; i++)
      writeMemFromFile<FullMatchMemory<BARREL> >(barrelFullMatches[i], fin_barrelFM.at(i), ievt);
    for (unsigned i = 0; i < nFMDiskMems; i++)
      writeMemFromFile<FullMatchMemory<DISK> >(diskFullMatches[i], fin_diskFM.at(i), ievt);

    // bx
    BXType bx = ievt;
    BXType bx_o;

    // Unit Under Test
    TOP_FUNC_(bx,
      trackletParameters.data(),
      barrelFullMatches.data(),
      diskFullMatches.data(),
      bx_o,
      trackWord,
      barrelStubWords,
      diskStubWords
    );

    unsigned nTracks = 0;
    for (unsigned short i = 0; i < kMaxProc; i++) {
      TrackFit_t track;
      track.setTrackWord(trackWord[i]);
      setBarrelStubs<kNBarrelStubs - 1>(track, barrelStubWords, i);
      setDiskStubs<kNDiskStubs - 1>(track, diskStubWords, i);
      if (track.getTrackValid())
        tracksMem.write_mem(bx, track, nTracks++);
    }

    const auto &pos = fout_tracks.at(0).tellg();

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackFitMemory_t,InputBase,OutputBase,TrackFit_t::kTFHitMapLSB,TrackFit_t::kTFTrackValidMSB>(tracksMem, fout_tracks.at(0), ievt, "\nTrack word", true);
    compareStubsWithFile<kNBarrelStubs + kNDiskStubs - 1>(err, fout_tracks.at(0), pos, tracksMem, ievt);
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
