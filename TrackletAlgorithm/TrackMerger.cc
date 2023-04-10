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

void ComparisonModule::resetCM(){
  masterTrack.resetTracks();
  tracksProcessed = 0;

  return;
}

void fillTrackArray(const TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i){
  outTrack[i] = inTrack;
  
  return;
}

void loadTrack(
  const TrackFitType::TrackWord& trackWordIn,
  const TrackFitType::BarrelStubWord (&barrelStubWordsIn)[NBarrelStub],
  const TrackFitType::DiskStubWord (&diskStubWordsIn)[NDiskStub],
  TrackStruct& aTrack
) {

  #pragma HLS array_partition variable=barrelStubWordsIn
  #pragma HLS array_partition variable=diskStubWordsIn
  aTrack._trackWord = trackWordIn;

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
  ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule dim=1

  TrackStruct unmergedTracks[kNLastTracks];
  #pragma HLS data_pack variable=unmergedTracks

  TrackStruct cmTracks[kNComparisonModules];
  #pragma HLS data_pack variable=cmTracks
  
  LOOP_ResetUnmergedTrks:
  for (unsigned int nTracks = 0; nTracks < kNLastTracks; nTracks++){
    #pragma HLS unroll
    unmergedTracks[nTracks].resetTracks();
  }

  LOOP_ResetCMTrks:
  for (unsigned int nCMTracks = 0; nCMTracks < kNComparisonModules; nCMTracks++){
    #pragma HLS unroll
    cmTracks[nCMTracks].resetTracks();
  }

  LOOP_ResetCMs:
  for (unsigned int nCM = 0; nCM < kNComparisonModules; nCM++){
    #pragma HLS unroll
    comparisonModule[nCM].resetCM();
  }

  unsigned int unmergedIndx{0};
  
  // Looping over all tracks
  LOOP_Input:
  for (unsigned int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS pipeline II=1
    TrackStruct tracks[kNBuffers];
    #pragma HLS data_pack variable=tracks
    // Filling first element of the buffer with module input
    loadTrack(trackWord[i],
              barrelStubWords[i],
              diskStubWords[i],
              tracks[0]);

    // CM processing loop
    LOOP_ProcTracks:
    for (unsigned int j = 0; j < kNComparisonModules; j++){
      comparisonModule[j].process(tracks[j], tracks[j+1]);
      tracks[j].resetTracks();
    }
    // When the unmerged track reaches the end of the buffer - put in unmerged tracks array to be output
    if (tracks[kNComparisonModules].getTrkWord() != 0){
      fillTrackArray(tracks[kNComparisonModules], unmergedTracks, unmergedIndx);
      tracks[kNComparisonModules].resetTracks();
      unmergedIndx++;
    }

  }

  // Getting CM master tracks
  LOOP_CMTracks:
  for (unsigned int nModule = 0; nModule < kNComparisonModules; nModule++){
    #pragma HLS pipeline II=1
    cmTracks[nModule] = comparisonModule[nModule].getMasterTrackStruct(); // This line fills CM array to be read out at same time as unmerged tracks
    comparisonModule[nModule].resetCM(); // Resetting
  }

  // Setting outputs in same loop
  LOOP_SetOutputs:
  for (unsigned int outputIndex = 0; outputIndex < kMaxTrack; outputIndex++){
    #pragma HLS pipeline II=1 
    TrackStruct trk;
    if (outputIndex < kNComparisonModules) {
      trk = cmTracks[outputIndex];
      cmTracks[outputIndex].resetTracks(); // Resetting
    } else if ((outputIndex - kNComparisonModules) < kNLastTracks) {
      trk = unmergedTracks[outputIndex-kNComparisonModules];
      unmergedTracks[outputIndex-kNComparisonModules].resetTracks(); // Resetting      
    } else {
      trk.resetTracks();
    }
    
    // Send track to output
    unloadTrack(trk, 
                trackWord_o[outputIndex], 
                barrelStubWords_o[outputIndex], 
                diskStubWords_o[outputIndex]);

    
  }
  bx_o = bx;

  return;
}