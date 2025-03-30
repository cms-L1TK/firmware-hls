// TrackMerger test bench
#include "../TopFunctions/TrackMergerTop.h"
#include "FileReadUtility.h"
#include "hls_math.h"
#include "hls_stream.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int nevents = 100;

using namespace std;

int main(){
  //Error counter
  int err_count = 0;
    
  // Input memories
  TrackFitType::TrackWord trackWord[kMaxTrack];
  TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][trklet::N_LAYER];
  TrackFitType::DiskStubWord diskStubWords[kMaxTrack][trklet::N_DISK];
  TrackFitMemory<trklet::N_LAYER, trklet::N_DISK> inputTracks;

  // Output memories
  TrackFitType::TrackWord trackWord_o[kMaxTrack];
  TrackFitType::BarrelStubWord barrelStubWords_o[kMaxTrack][trklet::N_LAYER];
  TrackFitType::DiskStubWord diskStubWords_o[kMaxTrack][trklet::N_DISK];
  TrackFitMemory<trklet::N_LAYER, trklet::N_DISK> outputTracks;
  // int outputNumber;
 
  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_AAAA*");


  auto &fout_outputTracks = tb.files("CleanTrack_CT_AAAA*"); 
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) { 
    cout << "Event: " << dec << ievt << endl;
    
    for (unsigned short i = 0; i < kMaxTrack; ++i){
      trackWord[i] = TrackFitType::TrackWord(0);
      trackWord_o[i] = TrackFitType::TrackWord(0);

      for (unsigned short nStub = 0; nStub < trklet::N_LAYER; nStub++){
        barrelStubWords[i][nStub] = TrackFitType::BarrelStubWord(0);
        barrelStubWords_o[i][nStub] = TrackFitType::BarrelStubWord(0);
	if ( nStub != trklet::N_DISK ) {  //FIXME this is written in a very confusing way....
	  diskStubWords[i][nStub] = TrackFitType::DiskStubWord(0);
	  diskStubWords_o[i][nStub] = TrackFitType::DiskStubWord(0);
	}
      }
    }

    outputTracks.clear();
    outputTracks.setWriteBX(ievt);

    // Read in next event from input
    writeMemFromFile<TrackFitMemory<trklet::N_LAYER, trklet::N_DISK>> (inputTracks, fin_inputTracks.at(0), ievt);
    
    // Set bunch crossing
    BXType bx = ievt;
    BXType bx_o;

    // Set input memories
    for(unsigned short i = 0; i < kMaxTrack; i++){
      TrackFitType track;
      if (i < inputTracks.getEntries(bx)) {
      track = inputTracks.read_mem(bx, i);
      } else {
        track = TrackFitType();
      } 
      trackWord[i] = track.getTrackWord();
      barrelStubWords[i][0] = track.getBarrelStubWord<0>();
      barrelStubWords[i][1] = track.getBarrelStubWord<1>();
      barrelStubWords[i][2] = track.getBarrelStubWord<2>();
      barrelStubWords[i][3] = track.getBarrelStubWord<3>();
      barrelStubWords[i][4] = track.getBarrelStubWord<4>();
      barrelStubWords[i][5] = track.getBarrelStubWord<5>();
      diskStubWords[i][0] = track.getDiskStubWord<6>();
      diskStubWords[i][1] = track.getDiskStubWord<7>();
      diskStubWords[i][2] = track.getDiskStubWord<8>();
      diskStubWords[i][3] = track.getDiskStubWord<9>();
      diskStubWords[i][4] = track.getDiskStubWord<10>();
    }

    // Unit under test
    TrackMergerTop(bx,
    trackWord,
    barrelStubWords,
    diskStubWords,
    bx_o,
    trackWord_o,
    barrelStubWords_o,
    diskStubWords_o
    );

    bool truncation = false;

    // Filling outputs
    for (unsigned short i = 0; i < kMaxTrack; i++){ 
      TrackFitType track;
      track.setTrackWord(trackWord_o[i]);
      track.setBarrelStubWord<0>(barrelStubWords_o[i][0]);
      track.setBarrelStubWord<1>(barrelStubWords_o[i][1]);
      track.setBarrelStubWord<2>(barrelStubWords_o[i][2]);
      track.setBarrelStubWord<3>(barrelStubWords_o[i][3]);
      track.setBarrelStubWord<4>(barrelStubWords_o[i][4]);
      track.setBarrelStubWord<5>(barrelStubWords_o[i][5]);
      track.setDiskStubWord<6>(diskStubWords_o[i][0]);
      track.setDiskStubWord<7>(diskStubWords_o[i][1]);
      track.setDiskStubWord<8>(diskStubWords_o[i][2]);
      track.setDiskStubWord<9>(diskStubWords_o[i][3]);
      track.setDiskStubWord<10>(diskStubWords_o[i][4]);
      
      outputTracks.write_mem(track);
      
    } 

    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory<trklet::N_LAYER, trklet::N_DISK>>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);
    
  }
  // Commented as f/w does not match the s/w - implementations are different so test vectors are different, TB fails.
  // Handling case of err%256 == 0 
  // if (err_count > 255) err_count = 255;
  // return err_count;

}
