#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "hls_stream.h"
#include "TrackMerger.h"
#include "TrackHandler.h"

void TrackMergerTop(const BXType bx,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::TrackWord> &trackWord,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_0,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_1,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_2,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_3,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_0,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_1,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_2,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::TrackWord> &trackWord_o,
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_0_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_1_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_2_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_3_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_0_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_1_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_2_o, 
  hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_3_o
);

#endif