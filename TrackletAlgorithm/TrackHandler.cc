#include "TrackHandler.h"


// fn to return the stubID

void TrackStruct::resetTracks(){
  _trackWord = 0;
  LOOP_StubReset: 
  for (unsigned int stubIdx= 0; stubIdx < NStub; stubIdx++){
    #pragma HLS unroll
    _stubArray[stubIdx]= 0;
  }

  return;
}

bool TrackHandler::compareTrack(const TrackStruct &trk, TrackStruct &masterTrk){
  // Compare the two tracks, masterTrack and trk
  #pragma HLS array_partition variable=matchesFoundStub complete dim=0
  #pragma HLS array_partition variable=masterTrk._stubArray complete dim=0
  #pragma HLS array_partition variable=trk._stubArray complete dim=0

  LOOP_CompareStubs:
  for (unsigned int stubNum = 0; stubNum < NStub; stubNum++){
    #pragma HLS unroll
    ap_uint<stubIDSize> masterStubIndex = masterTrk.getStubId(stubNum);
    ap_uint<stubIDSize> inputStubIndex = trk.getStubId(stubNum);
    ap_uint<stubVld> masterStubValid = masterTrk.getStubValid(stubNum);
    ap_uint<stubVld> inputStubValid = trk.getStubValid(stubNum);
    
    matchesFoundStubs[stubNum] = ((masterStubIndex == inputStubIndex) && masterStubValid == 1 && inputStubValid == 1) ?  1 : 0; 
  }

  // Update #matches found 
  unsigned int totMatchesFound = 0;
  LOOP_MatchesFound:
  for (unsigned int layerIndex = 0; layerIndex < NStub; layerIndex++){
    #pragma HLS unroll
    totMatchesFound += matchesFoundStubs[layerIndex];
  }
  return (totMatchesFound >= mergeCondition);


}

