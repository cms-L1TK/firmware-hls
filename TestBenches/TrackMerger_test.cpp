// TrackMerger test bench
#include "TrackMergerTop.h"
#include "FileReadUtility.h"
#include "hls_math.h"
#include "hls_stream.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int nevents = 5;

using namespace std;

int main(){
  //Error counter
  int err_count = 0;
    
  // Input memories
  hls::stream<TrackFit::TrackWord> trackWord;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_0;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_1;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_2;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_3;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_0;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_1;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_2;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_3;
  static TrackFitMemory inputTracks;

  // Output memories
  hls::stream<TrackFit::TrackWord> trackWord_o;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_0_o;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_1_o;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_2_o;
  static hls::stream<TrackFit::BarrelStubWord> barrelStubWords_3_o;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_0_o;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_1_o;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_2_o;
  static hls::stream<TrackFit::DiskStubWord> diskStubWords_3_o;
  static TrackFitMemory outputTracks;
  // int outputNumber;

  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_L1L2*");


  auto &fout_outputTracks = tb.files("output_TrackFit_TF_L1L2*"); // use CleanTrack_CT_L1L2_04.dat when tracks have been merged output_TrackFit_TF_L1L2*
  // Loop over events
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;
    
    // Read in next event from input
    writeMemFromFile<TrackFitMemory> (inputTracks, fin_inputTracks.at(0), ievt);
    
    // Set bunch crossing
    BXType bx = ievt;
    BXType bx_o;

    // Set input memories
    for(unsigned short i = 0; i < kMaxTrack; i++){
      TrackFit track;
      if (i<inputTracks.getEntries(bx)) {
        track = inputTracks.read_mem(bx, i); //i+1 for merge
      } else {
        track = TrackFit();
      }
      trackWord << track.getTrackWord();
      barrelStubWords_0 << track.getBarrelStubWord<0>();
      barrelStubWords_1 << track.getBarrelStubWord<1>();
      barrelStubWords_2 << track.getBarrelStubWord<2>();
      barrelStubWords_3 << track.getBarrelStubWord<3>();
      diskStubWords_0 << track.getDiskStubWord<4>();
      diskStubWords_1 << track.getDiskStubWord<5>();
      diskStubWords_2 << track.getDiskStubWord<6>();
      diskStubWords_3 << track.getDiskStubWord<7>();
    }

    // Unit under test
    TrackMergerTop(bx,
    trackWord,
    barrelStubWords_0, 
    barrelStubWords_1, barrelStubWords_2, barrelStubWords_3,
    diskStubWords_0, diskStubWords_1, diskStubWords_2, diskStubWords_3,
    bx_o,
    trackWord_o,
    barrelStubWords_0_o, barrelStubWords_1_o, barrelStubWords_2_o, barrelStubWords_3_o,
    diskStubWords_0_o, diskStubWords_1_o, diskStubWords_2_o, diskStubWords_3_o
    );

    bool truncation = false;

    // Filling outputs
    unsigned nTracks = 0;
    for (unsigned short i = 0; i < kMaxTrack; i++){ 
      TrackFit track;
      track.setTrackWord(trackWord_o.read());
      track.setBarrelStubWord<0>(barrelStubWords_0_o.read());
      track.setBarrelStubWord<1>(barrelStubWords_1_o.read());
      track.setBarrelStubWord<2>(barrelStubWords_2_o.read());
      track.setBarrelStubWord<3>(barrelStubWords_3_o.read());
      track.setDiskStubWord<4>(diskStubWords_0_o.read());
      track.setDiskStubWord<5>(diskStubWords_1_o.read());
      track.setDiskStubWord<6>(diskStubWords_2_o.read());
      track.setDiskStubWord<7>(diskStubWords_3_o.read());
      
      outputTracks.write_mem(bx, track, nTracks );
      ++nTracks;
    } 

    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);
    
  }

  // Handling case of err%256 == 0 
  // if (err_count > 255) err_count = 255;
  // return err_count;

}