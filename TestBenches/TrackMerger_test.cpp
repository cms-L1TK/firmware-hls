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

  TBHelper tb("../../../../../emData/PD/PD/");

  // Open input files
  auto &fin_inputTracks = tb.files("TrackFit_TF_L1L2*");
  cout << "inputTrack_file#: " << tb.nFiles("TrackFit_TF_L1L2*") << endl;
  auto fin_names = tb.fileNames("TrackFit_TF_L1L2*");
  for (auto name : fin_names ){
    cout << "fin_name: " << name << endl;
  }
  auto &fout_outputTracks = tb.files("TrackFit_TF_L1L2*"); // "../../../../../emData/PD/PD/CleanTrack_CT_L1L2_04.dat"

  /*ifstream fin_inputTracks;
  openDataFile(fin_inputTracks,"../../../../../emData/PD/PD/TrackFit_TF_L1L2_04.dat");
  assert(fin_inputTracks.good());

  ifstream fout_outputTracks;
  openDataFile(fout_outputTracks,"../../../../../emData/PD/PD/TrackFit_TF_L1L2_04.dat");// "../../../../../emData/PD/PD/CleanTrack_CT_L1L2_04.dat");
  assert(fout_outputTracks.good());*/

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
    //writeMemFromFile<TrackFitMemory> (outputTracks, fout_outputTracks.at(0), ievt);
   
    // Set bunch crossing
    BXType bx = ievt;
    BXType bx_o;

    // Set input memories into arrays of input track/stub words
    for(unsigned short i = 0; i < inputTracks.getEntries(bx); i++){
      TrackFit track;
      track = inputTracks.read_mem(bx, i);
      trackWord[i] = track.getTrackWord();
       for (unsigned short j = 0; j < 4; j++){
        switch (j) {
          case 0:
            barrelStubWords[0][i] = track.getBarrelStubWord<0>();
            break;
          case 1:
            barrelStubWords[1][i] = track.getBarrelStubWord<1>();
            break;
          case 2:
            barrelStubWords[2][i] = track.getBarrelStubWord<2>();
            break;
          case 3:
            barrelStubWords[3][i] = track.getBarrelStubWord<3>();
            break;
        }
      }
      for (unsigned short k = 0; k < 4; k++){
        switch (k) {
          case 0:
            diskStubWords[0][i] = track.getDiskStubWord<4>();
            break;
          case 1:
            diskStubWords[1][i] = track.getDiskStubWord<5>();
            break;
          case 2:
            diskStubWords[2][i] = track.getDiskStubWord<6>();
            break;
          case 3:
            diskStubWords[3][i] = track.getDiskStubWord<7>();
            break;
        }
      }
      if( i== 0 )std::cout << std::hex << track.raw() << std::dec << " -- " << std::hex << trackWord[i] << std::dec << "\n";
    }


    // Unit under test
    TrackMergerTop(bx,
    trackWord,
    barrelStubWords,
    diskStubWords,
    bx_o,
    trackWord_o,
    barrelStubWords_o,
    diskStubWords_o);

    bool truncation = false;

    // Filling outputs
    unsigned nTracks = 0;
    for (unsigned short i = 0; i < inputTracks.getEntries(bx); i++){
      TrackFit track;
      track.setTrackWord(trackWord[i]);
      std::stringstream wrd;
      track.setBarrelStubWord<0>(barrelStubWords[0][i]);
      track.setBarrelStubWord<1>(barrelStubWords[1][i]);
      track.setBarrelStubWord<2>(barrelStubWords[2][i]);
      track.setBarrelStubWord<3>(barrelStubWords[3][i]);
      track.setDiskStubWord<4>(diskStubWords[0][i]);
      track.setDiskStubWord<5>(diskStubWords[1][i]);
      track.setDiskStubWord<6>(diskStubWords[2][i]);
      track.setDiskStubWord<7>(diskStubWords[3][i]);
    
      //track.setTrackValid(InputTrack.getTrackValid());
      if( i == 0 ) cout << "trackWord: " << std::hex << track.getTrackWord() << std::dec 
        << "," << std::hex << trackWord[i] << std::dec 
        << " -- " << std::hex << track.raw() << std::dec
        << " -- " << wrd.str() 
        << "\n";
      //if (track.getTrackValid()){
        outputTracks.write_mem(bx, "00020202" );
      //}
    }
    std::cout << "Output mmry contains " << outputTracks.getEntries(bx) << " entries\n";
    // for(unsigned short i = 0; i < outputTracks.getEntries(bx); i++){
    //   TrackFit track;
    //   track = outputTracks.read_mem(bx, i);
    //   cout << "trackWord out : " << std::hex << track.getTrackWord() << std::dec 
    //        << "trackWord in : " << std::hex << inputTracks.read_mem(bx,i).getTrackWord() << std::dec
    //     << endl;
    // }
    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory>(outputTracks, fout_outputTracks.at(0), ievt, "Tracks", truncation);

  }

  // Close files
  //fin_inputTracks.close();
  //fout_outputTracks.close();

  // Handling case of err%256 == 0 
  if (err_count > 255) err_count = 255;
  return err_count;

}
