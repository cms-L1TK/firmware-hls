#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>


void ComparisonModule::CheckMaster(){
  //masterTrack, a private member variable - with a flag.
  //if no masterTrack, read in next track, if already have one then do CompareTrack
  //get false return of first CM to send the next track to the next module

  if (masterTrack.getTrackWord() == 0){
   masterTrack = getTrack();
  }

}

void ComparisonModule::InputTrack(const TrackHandler track){ 
  //put tracks into buffer

  inputBuffer[writeIndex] = track;
  writeIndex++;

}
void ComparisonModule::processTrack(){
  masterTrack.CompareTrack(track, matchFound);
  masterTrack.MergeTrack(track, matchFound, mergeCondition);
}

TrackHandler ComparisonModule::getTrack(){
  TrackHandler track = inputBuffer[readIndex];
  readIndex++;
  return track;
}

//overall module only reads in a track and pass it to the comparison module
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
      const TrackFit::BarrelStubWord barrelStubWordsArray[4] = {barrelStubWords[0][i], barrelStubWords[1][i], barrelStubWords[2][i], barrelStubWords[3][i]};
      const TrackFit::DiskStubWord diskStubWordsArray[4] = {diskStubWords[0][i], diskStubWords[1][i], diskStubWords[2][i], diskStubWords[3][i]};
      TrackHandler track(trackWord, barrelStubWordsArray, diskStubWordsArray);
        
      //load all info into a track handler object and pass that to the InputTrack function
      comparisonModule[0].InputTrack(track);
      
    
    }

    bx_o = bx;
}
