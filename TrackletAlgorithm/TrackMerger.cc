#include "TrackMerger.h"

TrackStruct& ComparisonModule::getMasterTrackStruct(){
  return masterTrack;
}

void ComparisonModule::process(const TrackStruct &inTrack, TrackStruct &outTrack){
  tracksProcessed++;
  if (inTrack._trackWord != 0 && tracksProcessed <= kMaxTrack){
    if (!masterTrack.getTrackValid() && inTrack._cm == 0){
      masterTrack = inTrack;
      inTrack.cm_ = 1;
      outTrack = inTrack;
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

void fillTrackArray(TrackStruct& inTrack, TrackStruct* outTrack, unsigned int &i){
  outTrack[i] = inTrack; 
}



void TrackMerger(
    const ap_uint<dinSize> din[kMaxTrack],
    ap_uint<doutSize> (&dout)[kMaxTrack])
{
  ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule complete dim=1

  TrackStruct unmergedTracks[kNLastTracks];
  #pragma HLS data_pack variable=unmergedTracks
  // #pragma HLS array_partition variable=unmergedTracks complete dim=0

  unsigned int unmergedIndx{0};
  
  LOOP_ResetUnmergedTrks:
  for (int nTracks = 0; nTracks < kNLastTracks; nTracks++){
    #pragma HLS unroll
    unmergedTracks[nTracks].resetTracks();
  }


  LOOP_ResetCM:
  for (int nCM = 0; nCM < kNComparisonModules; nCM++){
    #pragma HLS unroll
    comparisonModule[nCM].resetCM();
  }

  
  // Looping over all tracks
  LOOP_Input:
  for (int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS pipeline II=1
    TrackStruct tracks[kNBuffers];
    // #pragma HLS array_partition variable=tracks complete dim=1
    #pragma HLS data_pack variable=tracks
    // Filling first element of the buffer with module input
    tracks[0].loadTrack(din[i]);

    // CM processing loop
    LOOP_ProcTracks:
    for (int j = 0; j < kNComparisonModules; j++){
      comparisonModule[j].process(tracks[j], tracks[j+1]);
      tracks[j].resetTracks();
    }

    // When the unmerged track reaches the end of the buffer - put in unmerged tracks array to be output
    if(tracks[kNComparisonModules].getTrackValid()){
      fillTrackArray(tracks[kNComparisonModules], unmergedTracks, unmergedIndx);
      unmergedIndx++;
    }


  }

  // Setting outputs in same loop
  LOOP_SetOutputs:
  for (int outputIndex = 0; outputIndex < kMaxTrack; outputIndex++){
    #pragma HLS pipeline II=1 
    TrackStruct trk;
    if (outputIndex < kNComparisonModules) {
      trk = comparisonModule[outputIndex].getMasterTrackStruct();
      comparisonModule[outputIndex].resetCM(); // Resetting
    } else if ((outputIndex - kNComparisonModules) < kNLastTracks) {
      trk = unmergedTracks[outputIndex-kNComparisonModules];
      unmergedTracks[outputIndex-kNComparisonModules].resetTracks(); // Resetting      
    } else {
      trk.resetTracks();
    }


    // Send track to output
    trk.unloadTrack(dout[outputIndex]);

    
  }

  return;
}