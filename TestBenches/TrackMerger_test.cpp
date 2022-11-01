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
using namespace hls;

int main(){
  //Error counter
  int err_count = 0;
    
  // Input memories
  stream<TrackFitType::TrackWord> trackWord("input_stream_1");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_0("input_stream_2");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_1("input_stream_3");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_2("input_stream_4");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_3("input_stream_5");
  static stream<TrackFitType::DiskStubWord> diskStubWords_0("input_stream_6");
  static stream<TrackFitType::DiskStubWord> diskStubWords_1("input_stream_7");
  static stream<TrackFitType::DiskStubWord> diskStubWords_2("input_stream_8");
  static stream<TrackFitType::DiskStubWord> diskStubWords_3("input_stream_9");
  static TrackFitMemory<NBarrelStub, NDiskStub> inputTracks;

  // Output memories
  stream<TrackFitType::TrackWord> trackWord_o("output_stream_1");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_0_o("output_stream_2");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_1_o("output_stream_3");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_2_o("output_stream_4");
  static stream<TrackFitType::BarrelStubWord> barrelStubWords_3_o("output_stream_5");
  static stream<TrackFitType::DiskStubWord> diskStubWords_0_o("output_stream_6");
  static stream<TrackFitType::DiskStubWord> diskStubWords_1_o("output_stream_7");
  static stream<TrackFitType::DiskStubWord> diskStubWords_2_o("output_stream_8");
  static stream<TrackFitType::DiskStubWord> diskStubWords_3_o("output_stream_9");
  static TrackFitMemory<NBarrelStub, NDiskStub> outputTracks;
  // int outputNumber;

  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_L1L2*");


  auto &fout_outputTracks = tb.files("CleanTrack_CT_L1L2*"); // use CleanTrack_CT_L1L2_04.dat when tracks have been merged or if no merge make a copy e.g. output_TrackFit_TF_L1L2*
  // Loop over events
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;
    
    // Read in next event from input
    writeMemFromFile<TrackFitMemory<NBarrelStub, NDiskStub>> (inputTracks, fin_inputTracks.at(0), ievt);
    
    // Set bunch crossing
    BXType bx = ievt;
    BXType bx_o;

    // Set input memories
    for(unsigned short i = 0; i < kMaxTrack; i++){
      TrackFitType track;
      if (i < inputTracks.getEntries(bx)) {
        track = inputTracks.read_mem(bx, i+1); //i+1 for merge
      } else {
        track = TrackFitType();
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
    barrelStubWords_1,
    barrelStubWords_2,
    barrelStubWords_3,
    diskStubWords_0,
    diskStubWords_1,
    diskStubWords_2,
    diskStubWords_3,
    bx_o,
    trackWord_o,
    barrelStubWords_0_o,
    barrelStubWords_1_o,
    barrelStubWords_2_o,
    barrelStubWords_3_o,
    diskStubWords_0_o,
    diskStubWords_1_o,
    diskStubWords_2_o, 
    diskStubWords_3_o
    );

    bool truncation = false;

    // Filling outputs
    unsigned nTracks = 0;
    for (unsigned short i = 0; i < kMaxTrack+kNComparisonModules; i++){ //first 16 CMs don't appear in output first if outputting unmerged tracks first
      TrackFitType track;
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
    err_count += compareMemWithFile<TrackFitMemory<NBarrelStub, NDiskStub>>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);
    
    
  }

  // Handling case of err%256 == 0 
  // if (err_count > 255) err_count = 255;
  // return err_count;

}