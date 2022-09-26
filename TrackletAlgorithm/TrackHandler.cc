#include "TrackHandler.h"

bool TrackHandler::compareTrack(TrackStruct& trk, TrackStruct& masterTrk, unsigned int& matchFound, unsigned int mergeCondition){
  #pragma HLS inline

  // compare the two tracks, masterTrack and trk
  LOOP_CompareTrack:
  for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    auto masterBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(masterTrk._barrelStubArray[layerIndex][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto inputBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(trk._barrelStubArray[layerIndex][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto masterDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(masterTrk._diskStubArray[layerIndex][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    auto inputDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(trk._diskStubArray[layerIndex][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));

    if((masterBarrelStubIndex == inputBarrelStubIndex) && (masterBarrelStubIndex > 0)){
      matchesFoundBarrel[layerIndex][0] = 1;
    } else {
      matchesFoundBarrel[layerIndex][0] = 0;
    }
    
    if ((masterDiskStubIndex == inputDiskStubIndex) && (masterDiskStubIndex > 0)){
      matchesFoundDisk[layerIndex][0] = 1;
    } else {
      matchesFoundDisk[layerIndex][0] = 0;
    }
  }

  // update #matches found 
  unsigned int matchesFound = 0;
  LOOP_MatchesFound:
  for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    matchesFound += matchesFoundBarrel[layerIndex][0] + matchesFoundDisk[layerIndex][0];
  }
  if (matchesFound >= mergeCondition){
    matchFound = 1;
    return matchFound; 
    } else {
      matchFound = 0;
      return matchFound;
    }
}

void TrackHandler::mergeTrack(TrackStruct& trk, TrackStruct& masterTrk){
  #pragma HLS inline
  #pragma HLS array_partition variable=masterTrk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=masterTrk._diskStubArray complete dim=0
  #pragma HLS array_partition variable=trk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=trk._diskStubArray complete dim=0
  // update master track
  // check whether the stub word is non-zero in the compared track
  // then add stub into master track if share > 3 stubs in common
  LOOP_SetInputStubToMaster:
  for(unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    if((masterTrk._barrelStubArray[layerIndex][0] == 0) && (trk._barrelStubArray[layerIndex][0] != 0)){
      masterTrk._barrelStubArray[layerIndex][0] = trk._barrelStubArray[layerIndex][0];
      mergedBarrelStubsMap += (1 << 3*layerIndex);
    }
    if((masterTrk._diskStubArray[layerIndex][0] == 0) && (trk._diskStubArray[layerIndex][0] !=0 )){
      masterTrk._diskStubArray[layerIndex][0] = trk._diskStubArray[layerIndex][0];
      mergedDiskStubsMap += (1 << 3*layerIndex);
    }
    totalHitMap = mergedBarrelStubsMap + mergedDiskStubsMap;
    masterTrk._trackWord | totalHitMap;
      
    LOOP_MergeLoopOverStubIndicies:
    for (unsigned int stubIndex = 1; stubIndex < layerStubIndexSize; stubIndex++){
      #pragma HLS unroll
      if((masterTrk._barrelStubArray[layerIndex][stubIndex] == 0) && (trk._barrelStubArray[layerIndex][stubIndex] != 0)){
        masterTrk._barrelStubArray[layerIndex][stubIndex] = trk._barrelStubArray[layerIndex][stubIndex];
      } else {
        LOOP_BitIndexBarrel:
        for (int bitIndex = 0; bitIndex < TrackFit::kBarrelStubSize; bitIndex++){
          #pragma HLS unroll
          masterTrk._barrelStubArray[layerIndex][stubIndex] = trk._barrelStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
        }
      }
      if((masterTrk._diskStubArray[layerIndex][stubIndex] == 0) && (trk._diskStubArray[layerIndex][stubIndex] != 0)){
        masterTrk._diskStubArray[layerIndex][stubIndex] = trk._diskStubArray[layerIndex][stubIndex];
      } else {
        LOOP_BitIndexDisk:
        for (int bitIndex = 0; bitIndex < TrackFit::kDiskStubSize; bitIndex++){
          #pragma HLS unroll
          masterTrk._diskStubArray[layerIndex][stubIndex] = masterTrk._diskStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);

        }
      }
    }
  }
}