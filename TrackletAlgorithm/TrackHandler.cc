#include "TrackHandler.h"

void TrackHandler::setTrkWord(TrackStruct track){
    trkWord = track._trackWord;
}

void TrackHandler::setBarrelArray(TrackStruct track){
    barrelStubArray[1][0] = track._barrelStub_0;
    barrelStubArray[2][0] = track._barrelStub_1;
    barrelStubArray[3][0] = track._barrelStub_2;
    barrelStubArray[4][0] = track._barrelStub_3;
}   

void TrackHandler::setDiskArray(TrackStruct track){
    diskStubArray[0][0] = track._diskStub_0;
    diskStubArray[1][0] = track._diskStub_1;
    diskStubArray[2][0] = track._diskStub_2;
    diskStubArray[3][0] = track._diskStub_3;
}


void TrackHandler::CompareTrack(TrackStruct track){
  #pragma HLS inline
  // compare the two tracks, masterTrack and trk
  // std::cout << "masterTrack: " << trkWord << std::endl;
  // std::cout << "track: " << track.trkWord << std::endl;

  TrackHandler master_track = TrackHandler(masterTrack);
  TrackHandler trk = TrackHandler(track);

  LOOP_CompareTrack:
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    auto masterBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(master_track.getBarrelStubArray(layerIndex, 0).range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto inputBarrelStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(trk.getBarrelStubArray(layerIndex, 0).range(kBarrelStubIndexSizeMSB, kBarrelStubIndexSizeLSB));
    auto masterDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(master_track.getDiskStubArray(layerIndex, 0).range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));
    auto inputDiskStubIndex = ap_uint<TrackFit::kTFStubIndexSize>(trk.getDiskStubArray(layerIndex, 0).range(kDiskStubIndexSizeMSB, kDiskStubIndexSizeLSB));

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

bool TrackHandler::MergeTrack(TrackStruct track, unsigned int& matchFound, unsigned int mergeCondition){
  #pragma HLS inline
  TrackHandler master_track = TrackHandler(masterTrack);
  TrackHandler trk = TrackHandler(track);
  // update #matches found 
  int matchesFound = 0;
  LOOP_MatchesFound:
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){
    #pragma HLS unroll
    matchesFound += matchesFoundBarrel[layerIndex][0] + matchesFoundDisk[layerIndex][0];
  }
  if (matchesFound >= mergeCondition){
    matchFound = 1;
    return 1;
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
      if((master_track.getBarrelStubArray(layerIndex, 0) == 0) && (trk.getBarrelStubArray(layerIndex, 0) != 0)){
        master_track.barrelStubArray[layerIndex][0] = trk.barrelStubArray[layerIndex][0];
        mergedBarrelStubsMap += (1 << 3*layerIndex);
      }
      if((master_track.getDiskStubArray(layerIndex, 0) == 0) && (trk.getDiskStubArray(layerIndex, 0) !=0)){
        master_track.diskStubArray[layerIndex][0] = trk.diskStubArray[layerIndex][0];
        mergedDiskStubsMap += (1 << 3*layerIndex);
      }
      totalHitMap = mergedBarrelStubsMap + mergedDiskStubsMap;
      trkWord | totalHitMap;
      
      LOOP_MergeLoopOverStubIndicies:
      for (int stubIndex = 1; stubIndex < layerStubIndexSize; stubIndex++){
        #pragma HLS unroll
        if(master_track.getBarrelStubArray(layerIndex, stubIndex) == 0 && trk.getBarrelStubArray(layerIndex, stubIndex) != 0){
          master_track.barrelStubArray[layerIndex][stubIndex] = trk.barrelStubArray[layerIndex][stubIndex];
        } else {
          LOOP_BitIndexBarrel:
          for (int bitIndex = 0; bitIndex < TrackFit::kBarrelStubSize; bitIndex++){
            #pragma HLS unroll
            master_track.barrelStubArray[layerIndex][stubIndex] = trk.barrelStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            #ifndef _SYNTHESIS_
            // std::cout << "barrelStubArray[layerIndex][stubIndex]: " << barrelStubArray[layerIndex][stubIndex] << std::endl;
            #endif 
          }
        }
        if(master_track.getDiskStubArray(layerIndex, stubIndex) == 0 && trk.getDiskStubArray(layerIndex, stubIndex) != 0){
          master_track.diskStubArray[layerIndex][stubIndex] = trk.diskStubArray[layerIndex][stubIndex];
        } else {
          LOOP_BitIndexDisk:
          for (int bitIndex = 0; bitIndex < TrackFit::kDiskStubSize; bitIndex++){
            #pragma HLS unroll
            master_track.diskStubArray[layerIndex][stubIndex] = master_track.diskStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            #ifndef _SYNTHESIS_
            // std::cout << "diskStubArray[layerIndex][stubIndex]: " << diskStubArray[layerIndex][stubIndex] << std::endl;
            #endif
          }
        }
      }
    }
  }
    
  else {
    matchFound = 0;
    return 0; }

}