#include "TrackMerger.h"
#include "TrackHandler.h"
#include <bitset>

TrackStruct& ComparisonModule::getMasterTrackStruct(){
  return masterTrack;
}

void ComparisonModule::process(const TrackStruct &inTrack, TrackStruct &outTrack){
  tracksProcessed++;
  trackHandler = TrackHandler();
  if (inTrack._trackWord != 0 && tracksProcessed <= kMaxTrack){
    if (masterTrack._trackWord == 0){
      masterTrack = inTrack;
    } else {
      if(masterTrack._trackWord != inTrack._trackWord){
        trackHandler.compareTrack(inTrack, masterTrack, matchFound, mergeCondition);
        if (matchFound) {
          trackHandler.mergeTrack(inTrack, masterTrack);
        } else {
        outTrack = inTrack;
        }
      }
    }
  }
  
  return;
}

void fillTrackArray(const TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i){
  outTrack[i] = inTrack;}

void loadTrack(
  const TrackFitType::TrackWord& trackWordIn,
  const TrackFitType::BarrelStubWord (&barrelStubWordsIn)[NBarrelStub],
  const TrackFitType::DiskStubWord (&diskStubWordsIn)[NDiskStub],
  TrackStruct& aTrack
) {
  aTrack._trackWord = trackWordIn;
  #pragma HLS array_partition variable=barrelStubWordsIn
  #pragma HLS array_partition variable=diskStubWordsIn

  for (unsigned int i = 0; i < NBarrelStub; i++){
    #pragma HLS unroll
    aTrack._barrelStubArray[i][0] = barrelStubWordsIn[i];
  }

  for (unsigned int j = 0; j < NDiskStub; j++){
    #pragma HLS unroll
    aTrack._diskStubArray[j][0] = diskStubWordsIn[j];
  }
 
  return;      
}  


void unloadTrack(
  TrackStruct& aTrack,
  TrackFitType::TrackWord& trackWordOut,
  TrackFitType::BarrelStubWord (&barrelStubWordsOut)[NBarrelStub], 
  TrackFitType::DiskStubWord (&diskStubWordsOut)[NDiskStub]
) {

  #pragma HLS array_partition variable=barrelStubWordsOut
  #pragma HLS array_partition variable=diskStubWordsOut

  trackWordOut = aTrack.getTrkWord(); 
  for (unsigned int i = 0; i < NBarrelStub; i++){
    #pragma HLS unroll
    barrelStubWordsOut[i] = aTrack.getBarrelStub(i, 0);
    }

  for (unsigned int j = 0; j < NDiskStub; j++){
    #pragma HLS unroll
     diskStubWordsOut[j]= aTrack.getDiskStub(j, 0);
  }

  return;
}

void TrackMerger(const BXType bx,
  const TrackFitType::TrackWord trackWord[kMaxTrack],
  const TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][NBarrelStub],
  const TrackFitType::DiskStubWord diskStubWords[kMaxTrack][NDiskStub],
  BXType bx_o,
  TrackFitType::TrackWord (&trackWord_o)[kMaxTrack],
  TrackFitType::BarrelStubWord (&barrelStubWords_o)[kMaxTrack][NBarrelStub],
  TrackFitType::DiskStubWord (&diskStubWords_o)[kMaxTrack][NDiskStub]
  )
{
  static ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule dim=1

  static TrackStruct unmergedTracks[kNLastTracks];
  #pragma HLS array_partition variable=unmergedTracks dim=1

  static TrackStruct cmTracks[kNComparisonModules];
  #pragma HLS array_partition variable=cmTracks dim=1


  unsigned int unmergedIndx{0};
  
  // Looping over all tracks
  LOOP_Input:
  for (unsigned int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS pipeline II=1
    TrackStruct tracks[kNBuffers];
    #pragma HLS array_partition variable=tracks dim=1
    // Filling first element of the buffer with module input
    loadTrack(trackWord[i],
              barrelStubWords[i],
              diskStubWords[i],
              tracks[0]);

    // CM processing loop
    LOOP_ProcTracks:
    for (unsigned int j = 0; j < kNComparisonModules; j++){
      comparisonModule[j].process(tracks[j], tracks[j+1]);
      tracks[j] = TrackStruct();
    }
    // When the unmerged track reaches the end of the buffer - put in unmerged tracks array to be output
    if (tracks[kNComparisonModules].getTrkWord() != 0){
      // fillTrackArray(tracks[kNComparisonModules], unmergedTracks, unmergedIndx);
      unmergedTracks[unmergedIndx] = tracks[kNComparisonModules];
      unmergedIndx++;
    }
  }
  // Getting CM master tracks
  LOOP_CMTracks:
  for (unsigned int nModule = 0; nModule < kNComparisonModules; nModule++){
    #pragma HLS pipeline II=1
    cmTracks[nModule] = comparisonModule[nModule].getMasterTrackStruct(); // This line fills CM array to be read out at same time as unmerged tracks
    comparisonModule[nModule] = ComparisonModule(); // Resetting
  }

  // Setting outputs in same loop
  LOOP_SetOutputs:
  for (unsigned int outputIndex = 0; outputIndex < kMaxTrack; outputIndex++) {
    #pragma HLS pipeline II=1
    TrackStruct trk;
    if (outputIndex < kNComparisonModules) {
      trk = cmTracks[outputIndex];
      cmTracks[outputIndex] = TrackStruct(); // Resetting
    } else {
      if ((outputIndex - kNComparisonModules) < kNLastTracks){
        trk = unmergedTracks[outputIndex-kNComparisonModules];
        unmergedTracks[outputIndex-kNComparisonModules] = TrackStruct(); // Resetting
      }
      
    }
    
    // Check if trk is 0, if so do not unload
    if (trk.getTrkWord() !=0){
    // Sending to output
      unloadTrack(trk, 
                  trackWord_o[outputIndex], 
                  barrelStubWords_o[outputIndex], 
                  diskStubWords_o[outputIndex]);
    }
    
  }
  bx_o = bx;

  return;
}