#include "TrackHandler.h"

// void TrackHandler::setTrkWord(TrackStruct track){
//   #pragma HLS inline
//   trkWord = track._trackWord;
// }

// void TrackHandler::setBarrelArray(TrackStruct track){
//     #pragma HLS inline
//     barrelStubArray[1][0] = track._barrelStub_0;
//     barrelStubArray[2][0] = track._barrelStub_1;
//     barrelStubArray[3][0] = track._barrelStub_2;
//     barrelStubArray[4][0] = track._barrelStub_3;
// }   

// void TrackHandler::setDiskArray(TrackStruct track){
//     #pragma HLS inline
//     diskStubArray[0][0] = track._diskStub_0;
//     diskStubArray[1][0] = track._diskStub_1;
//     diskStubArray[2][0] = track._diskStub_2;
//     diskStubArray[3][0] = track._diskStub_3;
// }


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
      #ifndef _SYNTHESIS_
      // std::cout << "Match found in barrel " << "masterBarrelStub ID: " << masterBarrelStubIndex << " trackBarrel ID: " << inputBarrelStubIndex << std::endl;
      #endif 
      matchesFoundBarrel[layerIndex][0] = 1;
    } else {
      matchesFoundBarrel[layerIndex][0] = 0;
    }
    
    if ((masterDiskStubIndex == inputDiskStubIndex) && (masterDiskStubIndex > 0)){
    #ifndef _SYNTHESIS_
    // std::cout << "Match found in disk " << "masterDiskStub ID: " << masterDiskStubIndex << " trackDisk ID: " << inputDiskStubIndex << std::endl;
    #endif 
    matchesFoundDisk[layerIndex][0] = 1;
    } else {
      matchesFoundDisk[layerIndex][0] = 0;
    }
    // std::cout << "layer: " << layerIndex << " masterTrackBrl: " << barrelStubArray[layerIndex][0] << " trkBrl: " << track.barrelStubArray[layerIndex][0] << " MatchFndBrl: " << matchesFoundBarrel[layerIndex][0] << std::endl;
    // std::cout << "layer: " << layerIndex << " masterTrackDsk: " << diskStubArray[layerIndex][0] << " trkDsk: " << track.diskStubArray[layerIndex][0] << " MatchFndDsk: " << matchesFoundDisk[layerIndex][0] << std::endl;
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
  // update #matches found 
  // update master track
  // check whether the stub word is non-zero in the compared track
  // then add stub into master track
  LOOP_SetInputStubToMaster:
  for(unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    #ifndef _SYNTHESIS_
    // std::cout << "masterTrackWord: " << trkWord << " trackWord: " << track.trkWord << " layerIndex: " << layerIndex << " masterTrackBarrel:  " << barrelStubArray[layerIndex][0] << " comparedTrackBarrel: " << track.barrelStubArray[layerIndex][0] << std::endl;
    // std::cout << "masterTrackWord: " << trkWord << " trackWord: " << track.trkWord << " layerIndex: " << layerIndex << " masterTrackDisk:  " << diskStubArray[layerIndex][0] << " comparedTrackDisk: " << track.diskStubArray[layerIndex][0] << std::endl;
    #endif
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
          #ifndef _SYNTHESIS_
          // std::cout << "barrelStubArray[layerIndex][stubIndex]: " << barrelStubArray[layerIndex][stubIndex] << std::endl;
          #endif 
        }
      }
      if((masterTrk._diskStubArray[layerIndex][stubIndex] == 0) && (trk._diskStubArray[layerIndex][stubIndex] != 0)){
        masterTrk._diskStubArray[layerIndex][stubIndex] = trk._diskStubArray[layerIndex][stubIndex];
      } else {
        LOOP_BitIndexDisk:
        for (int bitIndex = 0; bitIndex < TrackFit::kDiskStubSize; bitIndex++){
          #pragma HLS unroll
          masterTrk._diskStubArray[layerIndex][stubIndex] = masterTrk._diskStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
          #ifndef _SYNTHESIS_
          // std::cout << "diskStubArray[layerIndex][stubIndex]: " << diskStubArray[layerIndex][stubIndex] << std::endl;
          #endif
        }
      }
    }
  }
}