#include "TrackHandler.h"

bool TrackHandler::compareTrack(const TrackStruct &trk, TrackStruct &masterTrk, unsigned int& matchFound, unsigned int mergeCondition){
  // Compare the two tracks, masterTrack and trk
  unsigned int matchesFoundBarrel = 0;
  unsigned int matchesFoundDisk = 0;

  for (unsigned int barrelStubNum = 0; barrelStubNum < NBarrelStub; barrelStubNum++){
    #pragma HLS unroll
    auto masterBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto inputBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));

    if ((masterBarrelStubIndex == inputBarrelStubIndex) && (masterBarrelStubIndex > 0)) matchesFoundBarrel++;
  }
  LOOP_CompareTrackDisk:
  for (unsigned int diskStubNum = 0; diskStubNum < NDiskStub; diskStubNum++){ 
    #pragma HLS unroll
    auto masterDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    auto inputDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    if((masterDiskStubIndex == inputDiskStubIndex) && (masterDiskStubIndex > 0)) matchesFoundDisk++;
  }

  // Update #matches found 
  unsigned int matchesFound = 0;
  LOOP_MatchesFound:
  for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    matchesFound += matchesFoundBarrel + matchesFoundDisk;
  }
  (matchesFound >= mergeCondition) ? matchFound = 1 : matchFound = 0; 

  return matchFound;
}

void TrackHandler::mergeTrack(const TrackStruct &trk, TrackStruct &masterTrk){
  // Update master track
  // Check whether the stub word is non-zero in the compared track
  // Then add stub into master track if share > 3 stubs in common
  LOOP_SetInputBarrelStubToMaster:
  for(unsigned int barrelStubNum = 0; barrelStubNum < NBarrelStub; barrelStubNum++){
    #pragma HLS unroll
    if((masterTrk._barrelStubArray[barrelStubNum][0] == 0) && (trk._barrelStubArray[barrelStubNum][0] != 0)){
      masterTrk._barrelStubArray[barrelStubNum][0] = trk._barrelStubArray[barrelStubNum][0];
      mergedBarrelStubsMap | (1 << TrackFitType::kTFHitCountSize*barrelStubNum);
    }
  }
  LOOP_SetInputDiskStubToMaster:
  for (unsigned int diskStubNum = 0; diskStubNum < NDiskStub; diskStubNum++){
    #pragma HLS unroll
    if((masterTrk._diskStubArray[diskStubNum][0] == 0) && (trk._diskStubArray[diskStubNum][0] !=0 )){
      masterTrk._diskStubArray[diskStubNum][0] = trk._diskStubArray[diskStubNum][0];
      mergedDiskStubsMap | (1 << TrackFitType::kTFHitCountSize*diskStubNum);
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
      #pragma HLS loop_flatten
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
      #pragma HLS loop_flatten
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