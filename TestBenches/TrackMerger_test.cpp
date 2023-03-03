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
  TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][4];
  TrackFitType::DiskStubWord diskStubWords[kMaxTrack][4];
  TrackFitMemory<NBarrelStub, NDiskStub> inputTracks;

  // Output memories
  TrackFitType::TrackWord trackWord_o[kMaxTrack];
  TrackFitType::BarrelStubWord barrelStubWords_o[kMaxTrack][4];
  TrackFitType::DiskStubWord diskStubWords_o[kMaxTrack][4];
  TrackFitMemory<NBarrelStub, NDiskStub> outputTracks;
  // int outputNumber;
 
  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_L1L2*");


  auto &fout_outputTracks = tb.files("CleanTrack_CT_L1L2*"); // use CleanTrack_CT_L1L2_04.dat when tracks have been merged or if no merge make a copy e.g. output_TrackFit_TF_L1L2*
  // Loop over events
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) { 
    cout << "Event: " << dec << ievt << endl;
    
    for (unsigned short i = 0; i < kMaxTrack; ++i){
      trackWord[i] = TrackFitType::TrackWord(0);
      trackWord_o[i] = TrackFitType::TrackWord(0);

      for (unsigned short nStub = 0; nStub < 4; nStub++){
        barrelStubWords[i][nStub] = TrackFitType::BarrelStubWord(0);
        diskStubWords[i][nStub] = TrackFitType::DiskStubWord(0);
        barrelStubWords_o[i][nStub] = TrackFitType::BarrelStubWord(0);
        diskStubWords_o[i][nStub] = TrackFitType::DiskStubWord(0);
      }
    }

    outputTracks.clear();

    // Read in next event from input
    writeMemFromFile<TrackFitMemory<NBarrelStub, NDiskStub>> (inputTracks, fin_inputTracks.at(0), ievt);
    
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
      diskStubWords[i][0] = track.getDiskStubWord<4>();
      diskStubWords[i][1] = track.getDiskStubWord<5>();
      diskStubWords[i][2] = track.getDiskStubWord<6>();
      diskStubWords[i][3] = track.getDiskStubWord<7>();
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
    unsigned nTracks = 0;
    for (unsigned short i = 0; i < kMaxTrack; i++){ 
      TrackFitType track;
      track.setTrackWord(trackWord_o[i]);
      track.setBarrelStubWord<0>(barrelStubWords_o[i][0]);
      track.setBarrelStubWord<1>(barrelStubWords_o[i][1]);
      track.setBarrelStubWord<2>(barrelStubWords_o[i][2]);
      track.setBarrelStubWord<3>(barrelStubWords_o[i][3]);
      track.setDiskStubWord<4>(diskStubWords_o[i][0]);
      track.setDiskStubWord<5>(diskStubWords_o[i][1]);
      track.setDiskStubWord<6>(diskStubWords_o[i][2]);
      track.setDiskStubWord<7>(diskStubWords_o[i][3]);
      
      outputTracks.write_mem(bx, track, nTracks );
      ++nTracks;
      
    } 

    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory<NBarrelStub, NDiskStub>>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);
    outputTracks.clear();
    
  }

  // Handling case of err%256 == 0 
  // if (err_count > 255) err_count = 255;
  // return err_count;

}