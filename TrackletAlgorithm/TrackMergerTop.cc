#include "TrackMergerTop.h"
#include "TrackHandler.h"

void TrackMergerTop(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){
    #pragma HLS inline recursive
    #pragma HLS interface register port=bx_o
    #pragma HLS stream variable=trackWord depth=1 dim=1
    #pragma HLS stream variable=barrelStubWords depth=1 dim=2
    #pragma HLS stream variable=diskStubWords depth=1 dim=2
    #pragma HLS stream variable=trackWord_o depth=1 dim=1
    #pragma HLS stream variable=barrelStubWords_o depth=1 dim=2
    #pragma HLS stream variable=diskStubWords_o depth=1 dim=2
    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS array_partition variable=barrelStubWords_o complete dim=1
    #pragma HLS array_partition variable=diskStubWords_o complete dim=1
    TrackMerger(bx, trackWord, barrelStubWords, diskStubWords, bx_o, trackWord_o, barrelStubWords_o, diskStubWords_o);
}
