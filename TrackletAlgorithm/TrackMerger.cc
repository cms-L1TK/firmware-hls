#include "TrackMerger.h"

TrackStruct& ComparisonModule::getMasterTrackStruct(){
  return masterTrack;
}

void ComparisonModule::process(const TrackStruct &inTrack, TrackStruct &outTrack){
  tracksProcessed++;
  if (inTrack._trackWord != 0 && tracksProcessed <= kMaxTrack){
    if (!masterTrack.getTrackValid()){
      masterTrack = inTrack;
    } else {
      if(inTrack.getTrackValid()){
        if (!masterTrack.compareTrack(inTrack)) {
          // trackHandler.mergeTrack(inTrack, masterTrack);
        // } else {
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

void TrackMerger(
  const ap_uint<trackWordSize> trackWord[kMaxTrack],
  const ap_uint<stubWordSize> stubWords[kMaxTrack][NStub],
  ap_uint<trackWordSize> (&trackWord_o)[kMaxTrack],
  ap_uint<stubWordSize> (&stubWords_o)[kMaxTrack][NStub]
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
    tracks[0].loadTrack(trackWord[i],
              stubWords[i]);

    // CM processing loop
    LOOP_ProcTracks:
    for (unsigned int j = 0; j < kNComparisonModules; j++){
      comparisonModule[j].process(tracks[j], tracks[j+1]);
      tracks[j].resetTracks();
    }
    // When the unmerged track reaches the end of the buffer - put in unmerged tracks array to be output
    if (tracks[kNComparisonModules].getTrackValid()){
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
    trk.unloadTrack(trackWord_o[outputIndex], stubWords_o[outputIndex]);

    
  }

  return;
}