#include "TrackMergerTop.h"

void TrackMergerTop(const BXType bx,
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::TrackWord trackWord [kMaxProc],
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::TrackWord trackWord_o [kMaxProc],
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::DiskStubWord diskStubWords_o[4][kMaxProc]){
    TrackMerger(bx, trackWord, barrelStubWords, diskStubWords, bx_o, trackWord_o, barrelStubWords_o, diskStubWords_o);
}