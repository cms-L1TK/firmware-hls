#include "TrackHandler.h"
void TrackHandler::CompareTrack(TrackHandler track, unsigned int& matchFound){
  #pragma HLS inline
  //compare the two tracks, masterTrack and trk
  // if they have > 3 stubs in common, update isMatch, else isMatch = false
  // get stub IDs (with a parameter that is a layer) - returns an array of const stub IDs
  // masterTrack.compareTrack(track)  as it has access to info of master, need to find a way to getting info of second track, accessing by the interface




  matchFound = 0;
}

void TrackHandler::MergeTrack(TrackHandler track, unsigned int matchFound, unsigned int mergeCondition){
  #pragma HLS inline
  if (matchFound >= mergeCondition)
  {
    #ifndef _SYNTHESIS_
    std::cout << "It's a merge" << std::endl;
    #endif
    //update master
  }
}