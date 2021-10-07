#include "TrackMerger.h"
#include <bitset>


bool ComparisonModule::CompareTracks(TrackHandler masterTrack, TrackHandler track){
  #pragma HLS inline
  
  //compare the two tracks, masterTrack and trk
  // if they have > 3 stubs in common, update isMatch, else isMatch = false
  return false;
}

void ComparisonModule::MergeTrack(TrackHandler &masterTrack, const TrackHandler track){
  #pragma HLS inline
  //Will merge both tracks to produce the merged track word - update masterTrack
  //and its barrel/disk stubs
  

  if (ComparisonModule::CompareTracks(masterTrack, track) == true) //merge
  {
    #ifndef _SYNTHESIS_
    std::cout << "It's a merge" << std::endl;
    #endif
  }
}

void ComparisonModule::InputTrack(const TrackFit::TrackWord trackWord,
const TrackFit::BarrelStubWord barrelStubWords[4],
const TrackFit::DiskStubWord diskStubWords[4]){
  //put tracks into buffer
  for (bufferIndex = 0; bufferIndex < kMaxProc; bufferIndex++){
    TrackHandler nextTrack[8][10];
    
  }

  //inputBuffer[bufferIndex] = nextTrack;
  //bufferIndex++;
  assert(bufferIndex < kMaxProc);
}

//overall module should only read in a track and pass it to the comparison module
void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o
  //TrackFit::TrackWord trackWord_o[kMaxProc],
  //TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  //TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){

    ComparisonModule comparisonModule[16];

    for (int i = 0; i < kMaxProc; i++){
      TrackFit::BarrelStubWord brlStubs[4]={barrelStubWords[0][i],barrelStubWords[1][i],barrelStubWords[2][i],barrelStubWords[3][i]};
      TrackFit::DiskStubWord diskStubs[4]={diskStubWords[0][i],diskStubWords[1][i],diskStubWords[2][i],diskStubWords[3][i]} ;
      
      comparisonModule[0].InputTrack(trackWord[i], brlStubs, diskStubs); //how to make input track from constructor the input
      //fill what to keep from InputTrack
    }

    bx_o = bx;
}
