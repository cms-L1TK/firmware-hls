// TrackMerger test bench
#include "TrackMergerTop.h"
#include "FileReadUtility.h"
#include "hls_math.h"

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
  static TrackFit::TrackWord trackWord[kMaxProc];
  static TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc];
  static TrackFit::DiskStubWord diskStubWords[4][kMaxProc];
  static TrackFitMemory inputTracks;

  // Output memories
  static TrackFit::TrackWord trackWord_o [kMaxProc];
  static TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc];
  static TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc];
  static TrackFitMemory outputTracks;
  int outputNumber;

  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_L1L2*");


  auto &fout_outputTracks = tb.files("output_TrackFit_TF_L1L2*"); // use CleanTrack_CT_L1L2_04.dat when tracks have been merged output_TrackFit_TF_L1L2*
  // Loop over events
  for (unsigned int ievt = 0; ievt < 1; ++ievt) {
    cout << "Event: " << dec << ievt << endl;
    

    for (unsigned short i = 0; i < kMaxProc; ++i){
      trackWord[i] = TrackFit::TrackWord(0);
      for (unsigned short j = 0; j < 4; j++){
        barrelStubWords[j][i] = TrackFit::BarrelStubWord(0);
        diskStubWords[j][i] = TrackFit::DiskStubWord(0);
      }
    }
    outputTracks.clear();

    // Read in next event from input
    writeMemFromFile<TrackFitMemory> (inputTracks, fin_inputTracks.at(0), ievt);
    
    // Set bunch crossing
    BXType bx = ievt;
    BXType bx_o;

    // Set input memories into arrays of input track/stub words
    for(unsigned short i = 0; i < inputTracks.getEntries(bx); i++){
      TrackFit track;
      track = inputTracks.read_mem(bx, i); //i+1 for merge
      trackWord[i] = track.getTrackWord();
      ap_uint<TrackFit::kTFStubIndexSize> stubIndex;
       for (unsigned short j = 0; j < 4; j++){
        switch (j) {
          case 0:
            barrelStubWords[0][i] = track.getBarrelStubWord<0>();
            stubIndex = track.getStubIndex<0>();
            break;
          case 1:
            barrelStubWords[1][i] = track.getBarrelStubWord<1>();
            stubIndex = track.getStubIndex<1>();
            break;
          case 2:
            barrelStubWords[2][i] = track.getBarrelStubWord<2>();
            stubIndex = track.getStubIndex<2>();
            break;
          case 3:
            barrelStubWords[3][i] = track.getBarrelStubWord<3>();
            stubIndex = track.getStubIndex<3>();
            break;
        } if(stubIndex != 0){
          // std::cout << "BarrelStubIndex: " << stubIndex << " at track:  " << i << std::endl;
        }
      }
      for (unsigned short k = 0; k < 4; k++){
        switch (k) {
          case 0:
            diskStubWords[0][i] = track.getDiskStubWord<4>();
            stubIndex = track.getStubIndex<4>();
            break;
          case 1:
            diskStubWords[1][i] = track.getDiskStubWord<5>();
            stubIndex = track.getStubIndex<5>();
            break;
          case 2:
            diskStubWords[2][i] = track.getDiskStubWord<6>();
            stubIndex = track.getStubIndex<6>();
            break;
          case 3:
            diskStubWords[3][i] = track.getDiskStubWord<7>();
            stubIndex = track.getStubIndex<7>();
            break;
        }
        if(stubIndex != 0){
        // std::cout << "DiskStubIndex: " << stubIndex << " at track:  " << i << std::endl;
        }
      }
      // std::cout << "i: " << i << " trkWord[i]: " << std::hex << trackWord[i] << " brl1: " << std::hex << barrelStubWords[0][i] << " brl2: " << std::hex << barrelStubWords[1][i] << " brl3: " << std::hex << barrelStubWords[2][i] <<  " brl4: " << std::hex << barrelStubWords[3][i] <<  " disk1: " << std::hex << diskStubWords[0][i] << " disk2: " << std::hex << diskStubWords[1][i] << " disk3: " << std::hex << diskStubWords[2][i] << " disk4: " << std::hex << diskStubWords[3][i] <<  std::endl;

    }
    // Unit under test
    TrackMergerTop(bx,
    trackWord,
    barrelStubWords,
    diskStubWords,
    bx_o,
    trackWord_o,
    barrelStubWords_o,
    diskStubWords_o,
    outputNumber);

    bool truncation = false;

    // Filling outputs
    unsigned nTracks = 0;
    for (unsigned short i = 0; i < outputNumber; i++){
      TrackFit track;
      track.setTrackWord(trackWord_o[i]);
      track.setBarrelStubWord<0>(barrelStubWords_o[0][i]);
      track.setBarrelStubWord<1>(barrelStubWords_o[1][i]);
      track.setBarrelStubWord<2>(barrelStubWords_o[2][i]);
      track.setBarrelStubWord<3>(barrelStubWords_o[3][i]);
      track.setDiskStubWord<4>(diskStubWords_o[0][i]);
      track.setDiskStubWord<5>(diskStubWords_o[1][i]);
      track.setDiskStubWord<6>(diskStubWords_o[2][i]);
      track.setDiskStubWord<7>(diskStubWords_o[3][i]);
        
      outputTracks.write_mem(bx, track, i );

      // if(trackWord_o[i] == 0 && barrelStubWords_o[0][i] == 0 && barrelStubWords_o[1][i] == 0 && barrelStubWords_o[2][i] == 0 && barrelStubWords_o[3][i] == 0){
      // std::cout << "i: " << i << " trkWord_o[i]: " << std::hex << trackWord_o[i] << " brl1: " << std::hex << barrelStubWords_o[0][i] << " brl2: " << std::hex << barrelStubWords_o[1][i] << " brl3: " << std::hex << barrelStubWords_o[2][i] << " brl4: " << std::hex << barrelStubWords_o[3][i] <<  " disk1: " << std::hex << diskStubWords_o[0][i] << " disk2: " << std::hex << diskStubWords_o[1][i] << " disk3: " << std::hex << diskStubWords_o[2][i] << " disk4: " << std::hex << diskStubWords_o[3][i] <<  std::endl;
       // }
    }
    
    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);

    
  }

  // Handling case of err%256 == 0 
  if (err_count > 255) err_count = 255;
  return err_count;

}