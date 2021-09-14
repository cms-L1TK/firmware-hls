#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "TrackFitMemory.h"

template<class>
class TrackHandler{
  //formats the input tracks
  //duplicate TrackFitMemory
}

template<class>
class ComparisonModule{
  private:
    bool CompareTracks(TrackFit masterTrack, TrackFit trk, bool &isMatch){
    }

    void MergeTrack(TrackFit &masterTrack, TrackFit::BarrelStubWord &masterTrackBarrelWords[4][7],
    TrackFit::DiskStubWord &masterTrackDiskStubWords[4][7], TrackFit trk, TrackFit::BarrelStubWord
    trkBarrelStubWords[4][7], TrackFit::DiskStubWord trkDiskStubWords[4][7]){
    }

    void WriteToBufferArray(TrackFit masterTrack){

    }


};



void TrackMergerHelper(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]);

void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]);

#endif