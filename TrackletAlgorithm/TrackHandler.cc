#include "TrackHandler.h"

void TrackStruct::resetTracks(){
  _trackWord = 0;
  LOOP_BarrelStubReset: 
  for (unsigned int nBarrelLayer = 0; nBarrelLayer < trklet::N_LAYER; nBarrelLayer++){
    #pragma HLS unroll
    for (unsigned int nBarrelStubs = 0; nBarrelStubs < maxNumStubs; nBarrelStubs++){
      #pragma HLS loop_flatten
      _barrelStubArray[nBarrelLayer][nBarrelStubs] = 0;
    }
  }
  LOOP_DiskStubReset:
  for (unsigned int nDiskLayer = 0; nDiskLayer < trklet::N_DISK; nDiskLayer++){
    #pragma HLS unroll
    for (unsigned int nDiskStubs = 0; nDiskStubs < maxNumStubs; nDiskStubs++){
      #pragma HLS loop_flatten
      _diskStubArray[nDiskLayer][nDiskStubs] = 0;
    }
  }

  return;
}

bool TrackHandler::compareTrack(const TrackStruct &trk, TrackStruct &masterTrk, unsigned int& matchFound, unsigned int mergeCondition){
  // Compare the two tracks, masterTrack and trk
  #pragma HLS array_partition variable=matchesFoundBarrel complete dim=0
  #pragma HLS array_partition variable=matchesFoundDisk complete dim=0
  #pragma HLS array_partition variable=masterTrk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=trk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=masterTrk._diskStubArray complete dim=0
  #pragma HLS array_partition variable=trk._diskStubArray complete dim=0
  LOOP_CompareBarrelStubs:
  for (unsigned int barrelStubNum = 0; barrelStubNum < trklet::N_LAYER; barrelStubNum++){
    #pragma HLS unroll
    ap_uint<TrackFitType::kTFStubIndexSize> masterBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    ap_uint<TrackFitType::kTFStubIndexSize> inputBarrelStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._barrelStubArray[barrelStubNum][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    
    matchesFoundBarrel[barrelStubNum][0] = ((masterBarrelStubIndex == inputBarrelStubIndex) && (masterBarrelStubIndex > 0)) ?  1 : 0; 
  }
  LOOP_CompareDiskStubs:
  for (unsigned int diskStubNum = 0; diskStubNum < trklet::N_DISK; diskStubNum++){
    #pragma HLS unroll
    ap_uint<TrackFitType::kTFStubIndexSize> masterDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(masterTrk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    ap_uint<TrackFitType::kTFStubIndexSize> inputDiskStubIndex = ap_uint<TrackFitType::kTFStubIndexSize>(trk._diskStubArray[diskStubNum][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));

    matchesFoundDisk[diskStubNum][0] = ((masterDiskStubIndex == inputDiskStubIndex) && (masterDiskStubIndex > 0)) ?  1 : 0;    
  }

  // Update #matches found 
  unsigned int matchesFound = 0;
  LOOP_MatchesFound:
  for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    matchesFound += matchesFoundBarrel[layerIndex][0] + matchesFoundDisk[layerIndex][0];
  }
  matchFound = (matchesFound >= mergeCondition) ? 1 : 0;

  return matchFound;
}

void TrackHandler::mergeTrack(const TrackStruct &trk, TrackStruct &masterTrk){
  #pragma HLS array_partition variable=masterTrk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=trk._barrelStubArray complete dim=0
  #pragma HLS array_partition variable=masterTrk._diskStubArray complete dim=0
  #pragma HLS array_partition variable=trk._diskStubArray complete dim=0
  // Update master track
  // Check whether the stub word is non-zero in the compared track
  // Then add stub into master track if share > 3 stubs in common
  LOOP_SetInputBarrelStubToMaster:
  for(unsigned int barrelStubNum = 0; barrelStubNum < trklet::N_LAYER; barrelStubNum++){
    #pragma HLS unroll
    if((masterTrk._barrelStubArray[barrelStubNum][0] == 0) && (trk._barrelStubArray[barrelStubNum][0] != 0)){
      masterTrk._barrelStubArray[barrelStubNum][0] = trk._barrelStubArray[barrelStubNum][0];
      mergedBarrelStubsMap = mergedBarrelStubsMap | (1 << TrackFitType::kTFHitCountSize*barrelStubNum);
    }
  }
  LOOP_SetInputDiskStubToMaster:
  for (unsigned int diskStubNum = 0; diskStubNum < trklet::N_DISK; diskStubNum++){
    #pragma HLS unroll
    if((masterTrk._diskStubArray[diskStubNum][0] == 0) && (trk._diskStubArray[diskStubNum][0] !=0 )){
      masterTrk._diskStubArray[diskStubNum][0] = trk._diskStubArray[diskStubNum][0];
      mergedDiskStubsMap = mergedDiskStubsMap | (1 << TrackFitType::kTFHitCountSize*diskStubNum);
    }
  }

  totalHitMap = mergedBarrelStubsMap + mergedDiskStubsMap;
  masterTrk._trackWord | totalHitMap;
  LOOP_BarrelStubs:
  for (unsigned int barrelStubNum = 0; barrelStubNum < trklet::N_LAYER; barrelStubNum++){ 
    #pragma HLS unroll
    LOOP_MergeBarrelStubs:
    for (unsigned int barrelStubIndex = 1; barrelStubIndex < maxNumStubs; barrelStubIndex++){
       #pragma HLS loop_flatten
      if((masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] == 0) && (trk._barrelStubArray[barrelStubNum][barrelStubIndex] != 0)){
        masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] = trk._barrelStubArray[barrelStubNum][barrelStubIndex];
      } else {
        LOOP_BitIndexBarrel:
        for (int bitIndex = 0; bitIndex < TrackFitType::kBarrelStubSize; bitIndex++){
          masterTrk._barrelStubArray[barrelStubNum][barrelStubIndex] = trk._barrelStubArray[barrelStubNum][barrelStubIndex] | (stubPadding << bitIndex);
        }
      }
    }
  }
  LOOP_DiskStubs:
  for (unsigned int diskStubNum = 0; diskStubNum < trklet::N_DISK; diskStubNum++){
    #pragma HLS unroll
    LOOP_MergeDiskStubs:
    for (unsigned int diskStubIndex = 1; diskStubIndex < maxNumStubs; diskStubIndex++){
      #pragma HLS loop_flatten
      if((masterTrk._diskStubArray[diskStubNum][diskStubIndex] == 0) && (trk._diskStubArray[diskStubNum][diskStubIndex] != 0)){
        masterTrk._diskStubArray[diskStubNum][diskStubIndex] = trk._diskStubArray[diskStubNum][diskStubIndex];
      } else {
        LOOP_BitIndexDisk:
        for (int bitIndex = 0; bitIndex < TrackFitType::kDiskStubSize; bitIndex++){
          masterTrk._diskStubArray[diskStubNum][diskStubIndex] = masterTrk._diskStubArray[diskStubNum][diskStubIndex] | (stubPadding << bitIndex);

        }
      }
    }
  }
  return;
}
