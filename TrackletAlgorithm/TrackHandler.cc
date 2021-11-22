#include "TrackHandler.h"

void TrackHandler::CompareTrack(TrackHandler track){
  #pragma HLS inline

  // compare the two tracks, masterTrack and trk
  // std::cout << "masterTrack: " << trkWord << std::endl;
  // std::cout << "track: " << track.trkWord << std::endl;
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){

    if(debug == 1){
      if(track.barrelStubArray[layerIndex][0] != 0){
        #ifndef _SYNTHESIS_
        std::cout << "masterBarrelStubArray[layerIndex][0]: " << barrelStubArray[layerIndex][0] << std::endl;
        std::cout<< "trackBarrel: " << track.barrelStubArray[layerIndex][0] << std::endl;
        #endif
      }
    }

    
    if(barrelStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) == 
      track.barrelStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) && barrelStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) > 0){
      matchesFoundBarrel[layerIndex][0] = 1;
    } else {
      matchesFoundBarrel[layerIndex][0] = 0;
    }
    if(debug == 1){
      if(track.diskStubArray[layerIndex][0] != 0){
        #ifndef _SYNTHESIS_
        std::cout << "masterDiskStubArray[layerIndex][0]: " << diskStubArray[layerIndex][0] << std::endl;
        std::cout<< "trackDisk: " << track.diskStubArray[layerIndex][0] << std::endl;
        #endif
      }
    }

    if (diskStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) == 
        track.diskStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) && diskStubArray[layerIndex][0].range(kStubIndexSizeMSB, kStubIndexSizeLSB) > 0){
      matchesFoundDisk[layerIndex][0] = 1;

    } else {
      matchesFoundDisk[layerIndex][0] = 0;
    }
  }
}

void TrackHandler::MergeTrack(TrackHandler track, unsigned int& matchFound, unsigned int mergeCondition){
  #pragma HLS inline
  // update #matches found 
  int matchesFound = 0;
  for (int layerIndex = 0; layerIndex < 4; layerIndex++){
    matchesFound += matchesFoundBarrel[layerIndex][0] + matchesFoundDisk[layerIndex][0];
  }
  if (matchesFound >= mergeCondition)
  {
    matchFound = 1;
    #ifndef _SYNTHESIS_
    // std::cout << "It's a merge" << std::endl;
    #endif
    // update master track
    // check whether the stub word is non-zero in the compared track
    // then add stub into master track
    for(int layerIndex = 0; layerIndex < 4; layerIndex++){
      if(matchesFoundBarrel[layerIndex][0] == 0 && track.matchesFoundBarrel[layerIndex][0] == 1){
        barrelStubArray[layerIndex][0] = track.barrelStubArray[layerIndex][0];
        // if(debug == 1){
        //   #ifndef _SYNTHESIS_
        //   std::cout << "diskStubArray[layerIndex][0]: " << diskStubArray[layerIndex][0] << std::endl;
        //   #endif
        // }
      }
      if(matchesFoundDisk[layerIndex][0] == 0 && track.matchesFoundDisk[layerIndex][0] == 1){
        diskStubArray[layerIndex][0] = track.diskStubArray[layerIndex][0];
        // if(debug == 1){
        //   #ifndef _SYNTHESIS_
        //   std::cout << "diskStubArray[layerIndex][0]: " << diskStubArray[layerIndex][0] << std::endl;
        //   #endif
        // }
      }
      
      for (int stubIndex = 1; stubIndex < layerStubIndexSize; stubIndex++){
        if(barrelStubArray[layerIndex][stubIndex] == 0 && track.barrelStubArray[layerIndex][stubIndex] != 0){
          barrelStubArray[layerIndex][stubIndex] = track.barrelStubArray[layerIndex][stubIndex];
        } else {
          for (int bitIndex = 0; bitIndex < TrackFit::kBarrelStubSize; bitIndex++){
            barrelStubArray[layerIndex][stubIndex] = barrelStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            if(debug == 1){
              #ifndef _SYNTHESIS_
              std::cout << "barrelStubArray[layerIndex][stubIndex]: " << barrelStubArray[layerIndex][stubIndex] << std::endl;
              #endif
            }
          }
        }
        if(diskStubArray[layerIndex][stubIndex] == 0 && track.diskStubArray[layerIndex][stubIndex] != 0){
          diskStubArray[layerIndex][stubIndex] = track.diskStubArray[layerIndex][stubIndex];
        } else {
          for (int bitIndex = 0; bitIndex < TrackFit::kDiskStubSize; bitIndex++){
            diskStubArray[layerIndex][stubIndex] = diskStubArray[layerIndex][stubIndex] | (stubPadding << bitIndex);
            if(debug == 1){
              #ifndef _SYNTHESIS_
              std::cout << "diskStubArray[layerIndex][stubIndex]: " << diskStubArray[layerIndex][stubIndex] << std::endl;
              #endif
            }
          }
        }
      }

    }
    
  }
  else matchFound = 0;
}