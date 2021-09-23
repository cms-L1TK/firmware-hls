#include "TrackMerger.h"
#include <bitset>


bool ComparisonModule::CompareTracks(TrackHandler masterTrack, TrackHandler track){
  #pragma HLS inline
  
  //compare the two tracks, masterTrack and trk
  // if they have > 3 stubs in common, update isMatch, else isMatch = false
  //now compare two tracks - the master track and the second input track
  return false;
}

void ComparisonModule::MergeTrack(TrackHandler &masterTrack, const TrackHandler track){
  #pragma HLS inline
  //Will merge both tracks to produce the merged track word - update masterTrack
  //and its barrel/disk stubs
  // UPDATE just change the master track - the output stub words will then become a 2D array, up to 7 hits per layer

  if (ComparisonModule::CompareTracks(masterTrack, track) == true) //merge
  {
    #ifndef _SYNTHESIS_
    std::cout << "It's a merge" << std::endl;
    #endif
  }
}

void ComparisonModule::InputTrack(TrackFit::TrackFitData data){
  //put track into buffer
  TrackHandler nextTrack(data);
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
      TrackFit trk;
      //trk.setTrackWord(trackWord[i]); //all the information from the track and stub words;
      comparisonModule[0].InputTrack(trackWord[i].raw()); //how to make input track from constructor the input
      //fill what to keep from InputTrack
    }
    

    


  }
