#include "TrackMergerTop.h"

void TrackMergerTop(const BXType bx,
  const TrackFitType::TrackWord trackWord[kMaxTrack],
  const TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][NBarrelStub],
  const TrackFitType::DiskStubWord diskStubWords[kMaxTrack][NDiskStub],
  BXType bx_o,
  TrackFitType::TrackWord (&trackWord_o)[kMaxTrack],
  TrackFitType::BarrelStubWord (&barrelStubWords_o)[kMaxTrack][NBarrelStub],
  TrackFitType::DiskStubWord (&diskStubWords_o)[kMaxTrack][NDiskStub]
  ){
    #pragma HLS inline recursive
    #pragma HLS stream variable=trackWord
    #pragma HLS stream variable=barrelStubWords
    #pragma HLS stream variable=diskStubWords
    #pragma HLS stream variable=trackWord_o
    #pragma HLS stream variable=barrelStubWords_o
    #pragma HLS stream variable=diskStubWords_o

    TrackMerger(bx,
                trackWord,
                barrelStubWords,
                diskStubWords,
                bx_o,
                trackWord_o,
                barrelStubWords_o,
                diskStubWords_o);
}