#include "TrackHandler.h"

void TrackHandler::CompareTrack(TrackHandler track){
  #pragma HLS inline
  #pragma HLS array_partition variable=_barrelStubArray complete dim=1
  #pragma HLS array_partition variable=_diskStubArray complete dim=1
  // compare the two tracks, masterTrack and trk
  // std::cout << "masterTrack: " << trkWord << std::endl;
  // std::cout << "track: " << track.trkWord << std::endl;
  LOOP_CompareTrack:
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS dependence variable=matchesFoundBarrel inter false
    #pragma HLS dependence variable=matchesFoundDisk inter false
    #pragma HLS unroll
    auto masterBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(_barrelStubArray[layerIndex][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto inputBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(track._barrelStubArray[layerIndex][0].range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto masterDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(_diskStubArray[layerIndex][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    auto inputDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(track._diskStubArray[layerIndex][0].range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));

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
}

int TrackHandler::MergeTrack(TrackHandler track, unsigned int& matchFound, unsigned int mergeCondition){
  #pragma HLS inline
  #pragma HLS dependence variable=matchesFoundBarrel inter false
  #pragma HLS dependence variable=matchesFoundDisk inter false
  #pragma HLS array_partition variable=_barrelStubArray complete dim=1
  #pragma HLS array_partition variable=_diskStubArray complete dim=1
  
  // update #matches found 
  int matchesFound = 0;
  LOOP_MatchesFound:
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    matchesFound += matchesFoundBarrel[layerIndex][0] + matchesFoundDisk[layerIndex][0];
  }
  if (matchesFound >= mergeCondition){
    matchFound = 1;
    #ifndef _SYNTHESIS_
    // std::cout << "It's a merge" << std::endl;
    #endif
    // update master track
    // check whether the stub word is non-zero in the compared track
    // then add stub into master track
    LOOP_SetInputStubToMaster:
    for(int layerIndex = 0; layerIndex < 4; layerIndex++){
      #pragma HLS unroll
      #ifndef _SYNTHESIS_
      // std::cout << "masterTrackWord: " << trkWord << " trackWord: " << track.trkWord << " layerIndex: " << layerIndex << " masterTrackBarrel:  " << barrelStubArray[layerIndex][0] << " comparedTrackBarrel: " << track.barrelStubArray[layerIndex][0] << std::endl;
      // std::cout << "masterTrackWord: " << trkWord << " trackWord: " << track.trkWord << " layerIndex: " << layerIndex << " masterTrackDisk:  " << diskStubArray[layerIndex][0] << " comparedTrackDisk: " << track.diskStubArray[layerIndex][0] << std::endl;
      #endif
      if((_barrelStubArray[layerIndex][0] == 0) && (track._barrelStubArray[layerIndex][0] != 0)){
        _barrelStubArray[layerIndex][0] = track._barrelStubArray[layerIndex][0];
        mergedBarrelStubsMap += (1 << 3*layerIndex);
      }
      if((_diskStubArray[layerIndex][0] == 0) && (track._diskStubArray[layerIndex][0] !=0)){
        _diskStubArray[layerIndex][0] = track._diskStubArray[layerIndex][0];
        mergedDiskStubsMap += (1 << 3*layerIndex);
      }
      totalHitMap = mergedBarrelStubsMap + mergedDiskStubsMap;
      // _trkWord | totalHitMap;
      
      LOOP_MergeLoopOverStubIndicies:
      for (int stubIndex = 1; stubIndex < layerStubIndexSize; stubIndex++){
        #pragma HLS unroll
        if(_barrelStubArray[layerIndex][stubIndex] == 0 && track._barrelStubArray[layerIndex][stubIndex] != 0){
          _barrelStubArray[layerIndex][stubIndex] = track._barrelStubArray[layerIndex][stubIndex];
        } else {
          LOOP_BitIndexBarrel:
          for (int bitIndex = 0; bitIndex < TrackFit::kBarrelStubSize; bitIndex++){
            #pragma HLS unroll
            // _barrelStubArray[layerIndex][stubIndex] = _barrelStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            #ifndef _SYNTHESIS_
            // std::cout << "barrelStubArray[layerIndex][stubIndex]: " << barrelStubArray[layerIndex][stubIndex] << std::endl;
            #endif 
          }
        }
        if(_diskStubArray[layerIndex][stubIndex] == 0 && track._diskStubArray[layerIndex][stubIndex] != 0){
          _diskStubArray[layerIndex][stubIndex] = track._diskStubArray[layerIndex][stubIndex];
        } else {
          LOOP_BitIndexDisk:
          for (int bitIndex = 0; bitIndex < TrackFit::kDiskStubSize; bitIndex++){
            #pragma HLS unroll
            // _diskStubArray[layerIndex][stubIndex] = _diskStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            #ifndef _SYNTHESIS_
            // std::cout << "diskStubArray[layerIndex][stubIndex]: " << diskStubArray[layerIndex][stubIndex] << std::endl;
            #endif
          }
        }
      }
    }
  }
    
  else matchFound = 0;

  return matchFound;

}