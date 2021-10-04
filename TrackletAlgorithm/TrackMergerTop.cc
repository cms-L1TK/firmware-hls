#include "TrackMergerTop.h"

void TrackMergerTop(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o
  //TrackFit::TrackWord trackWord_o [kMaxProc],
  //TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  //TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){
    TrackMerger(bx, trackWord, barrelStubWords, diskStubWords, bx_o); //trackWord_o, barrelStubWords_o, diskStubWords_o);
}
