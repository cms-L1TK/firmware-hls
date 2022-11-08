#include "TrackHandler.h"

bool TrackHandler::compareTrack(TrackStruct& trk, TrackStruct& masterTrk, unsigned int& matchFound, unsigned int mergeCondition){
  // compare the two tracks, masterTrack and trk
  LOOP_CompareTrackBarrel:
  for (unsigned int barrelStubNum = 0; barrelStubNum < NBarrelStub; barrelStubNum++){
    #pragma HLS unroll
    auto masterBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto inputBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));

    if((masterBarrelStubIndex == inputBarrelStubIndex) && (masterBarrelStubIndex > 0)){
      matchesFoundBarrel[barrelStubNum][0] = 1;
    } else {
      matchesFoundBarrel[barrelStubNum][0] = 0;
    }
  }
  LOOP_CompareTrackDisk:
  for (unsigned int diskStubNum = 0; diskStubNum < NDiskStub; diskStubNum++){
    #pragma HLS unroll  
    auto masterDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    auto inputDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    if ((masterDiskStubIndex == inputDiskStubIndex) && (masterDiskStubIndex > 0)){
      matchesFoundDisk[diskStubNum][0] = 1;
    } else {
      matchesFoundDisk[diskStubNum][0] = 0;
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
  // update master track
  // check whether the stub word is non-zero in the compared track
  // then add stub into master track if share > 3 stubs in common
  LOOP_SetInputBarrelStubToMaster:
  for(unsigned int barrelStubNum = 0; barrelStubNum < NBarrelStub; barrelStubNum++){
    #pragma HLS unroll
    if((masterTrk._barrelStubArray[barrelStubNum][0] == 0) && (trk._barrelStubArray[barrelStubNum][0] != 0)){
      masterTrk._barrelStubArray[barrelStubNum][0] = trk._barrelStubArray[barrelStubNum][0];
      mergedBarrelStubsMap += (1 << TrackFitType::kTFHitCountSize*barrelStubNum);
    }
  }
  LOOP_SetInputDiskStubToMaster:
  for (unsigned int diskStubNum = 0; diskStubNum < NDiskStub; diskStubNum++){
    #pragma HLS unroll
    if((masterTrk._diskStubArray[diskStubNum][0] == 0) && (trk._diskStubArray[diskStubNum][0] !=0 )){
      masterTrk._diskStubArray[diskStubNum][0] = trk._diskStubArray[diskStubNum][0];
      mergedDiskStubsMap += (1 << TrackFitType::kTFHitCountSize*diskStubNum);
    }
  }

  totalHitMap = mergedBarrelStubsMap + mergedDiskStubsMap;
  masterTrk._trackWord | totalHitMap;
  LOOP_BarrelStubs:
  for (unsigned int barrelStubNum = 0; barrelStubNum < NBarrelStub; barrelStubNum++){ 
    #pragma HLS unroll   
    LOOP_MergeBarrelStubs:
    for (unsigned int barrelStubIndex = 1; barrelStubIndex < layerStubIndexSize; barrelStubIndex++){
      #pragma HLS unroll
      if((masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] == 0) && (trk._barrelStubArray[barrelStubNum][barrelStubIndex] != 0)){
        masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] = trk._barrelStubArray[barrelStubNum][barrelStubIndex];
      } else {
        LOOP_BitIndexBarrel:
        for (int bitIndex = 0; bitIndex < TrackFitType::kBarrelStubSize; bitIndex++){
          #pragma HLS unroll
          masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] = trk._barrelStubArray[barrelStubNum][barrelStubIndex] | (stubPadding << bitIndex);
        }
      }
    }
  }
  LOOP_DiskStubs:
  for (unsigned int diskStubNum = 0; diskStubNum < NDiskStub; diskStubNum++){
    #pragma HLS unroll
    LOOP_MergeDiskStubs:
    for (unsigned int diskStubIndex = 1; diskStubIndex < layerStubIndexSize; diskStubIndex++){
      #pragma HLS unroll
      if((masterTrk._diskStubArray[diskStubNum][diskStubIndex] == 0) && (trk._diskStubArray[diskStubNum][diskStubIndex] != 0)){
        masterTrk._diskStubArray[diskStubNum][diskStubIndex] = trk._diskStubArray[diskStubNum][diskStubIndex];
      } else {
        LOOP_BitIndexDisk:
        for (int bitIndex = 0; bitIndex < TrackFitType::kDiskStubSize; bitIndex++){
          #pragma HLS unroll
          masterTrk._diskStubArray[diskStubNum][diskStubIndex] = masterTrk._diskStubArray[diskStubNum][diskStubIndex] | (stubPadding << bitIndex);

        }
      }
    }
  }
}