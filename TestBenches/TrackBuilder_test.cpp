// Test bench for TrackBuilder
#include "TrackBuilderTop.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  TBHelper tb("FT/FT_L1L2");

  // error counts
  int err = 0;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  auto &fin_tpar = tb.files("TrackletParameters*");
  auto &fin_barrelFM = tb.files("FullMatches_FM_L1L2_L*");
  auto &fin_diskFM = tb.files("FullMatches_FM_L1L2_D*");

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
  TrackFit::TrackWord trackWord[kMaxProc];
  TrackFit::BarrelStubWord barrelStubWords[TrackFit::kNBarrelStubs][kMaxProc];
  TrackFit::DiskStubWord diskStubWords[TrackFit::kNDiskStubs][kMaxProc];
  TrackFitMemory tracksMem;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // Clear all output memories before starting.
    for (unsigned short i = 0; i < kMaxProc; i++) {
      trackWord[i] = TrackFit::TrackWord(0);
      for (unsigned short j = 0; j < 4; j++) {
        barrelStubWords[j][i] = TrackFit::BarrelStubWord(0);
        diskStubWords[j][i] = TrackFit::DiskStubWord(0);
      }
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
    TrackBuilder_L1L2(bx,
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
      TrackFit track;
      track.setTrackWord(trackWord[i]);
      track.setBarrelStubWord<0>(barrelStubWords[0][i]);
      track.setBarrelStubWord<1>(barrelStubWords[1][i]);
      track.setBarrelStubWord<2>(barrelStubWords[2][i]);
      track.setBarrelStubWord<3>(barrelStubWords[3][i]);
      track.setDiskStubWord<4>(diskStubWords[0][i]);
      track.setDiskStubWord<5>(diskStubWords[1][i]);
      track.setDiskStubWord<6>(diskStubWords[2][i]);
      track.setDiskStubWord<7>(diskStubWords[3][i]);
      if (track.getTrackValid())
        tracksMem.write_mem(bx, track, nTracks++);
    }

    const bool truncate = true;
    const auto &pos = fout_tracks.at(0).tellg();

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFHitMapLSB,TrackFit::kTFTrackValidMSB>(tracksMem, fout_tracks.at(0), ievt, "\nTrack word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(0),TrackFit::kTFStubValidMSB(0)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 0 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(1),TrackFit::kTFStubValidMSB(1)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 1 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(2),TrackFit::kTFStubValidMSB(2)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 2 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(3),TrackFit::kTFStubValidMSB(3)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 3 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(4),TrackFit::kTFStubValidMSB(4)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 4 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(5),TrackFit::kTFStubValidMSB(5)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 5 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(6),TrackFit::kTFStubValidMSB(6)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 6 word", truncate);
    fout_tracks.at(0).clear(), fout_tracks.at(0).seekg(pos);
    err += compareMemWithFile<TrackFitMemory,16,16,TrackFit::kTFStubRZResidLSB(7),TrackFit::kTFStubValidMSB(7)>(tracksMem, fout_tracks.at(0), ievt, "\nStub 7 word", truncate);
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
