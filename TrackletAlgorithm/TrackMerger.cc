#include "TrackMerger.h"
#include <bitset>


bool ComparisonModule::CompareTracks(TrackHandler masterTrack, TrackHandler trk){
  #pragma HLS inline
  
  //compare the two tracks, masterTrack and trk
  // if they have > 3 stubs in common, update isMatch, else isMatch = false
  //now compare two tracks - the master track and the second input track
  return false;
}

void ComparisonModule::MergeTrack(TrackHandler &masterTrack, const TrackHandler trk){
  #pragma HLS inline
  //Will merge both tracks to produce the merged track word - update masterTrack
  //and its barrel/disk stubs
  // UPDATE just change the master track - the output stub words will then become a 2D array, up to 7 hits per layer

  if (ComparisonModule::CompareTracks(masterTrack, trk) == true) //merge
}

void ComparisonModule::InputTrack(TrackFit trk){
  //put track into buffer
  TrackHandler nextTrack(trk);
  inputBuffer[bufferIndex] = nextTrack;
  bufferIndex++;
  assert(bufferIndex < kMaxProc);
}

//overall module should only read in a track and pass it to the comparison module
void TrackMergerModule(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o,
  TrackFit::BarrelStubWord barrelStubWords_o[4],
  TrackFit::DiskStubWord diskStubWords_o[4]){

    ComparisonModule comparisonModule[16];
    for (int i = 0; i < kMaxProc; i++){
      TrackFit trk;// 
      trk.setTrackWord(trackWord[i]); //all the information from the track and stub words;
      trk.setDiskStubWord(diskStubWords[i]);
      trk.setBarrelStubWord(barrelStubWords[i]);
      comparisonModule[0].InputTrack(trk); //how to make input track from constructor the input
      //fill what to keep from InputTrack
    }
    

    


  }
