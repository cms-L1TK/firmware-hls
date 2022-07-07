#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "hls_stream.h"
#include "TrackMerger.h"
#include "TrackHandler.h"

void TrackMergerTop(const BXType bx,
  hls::stream<TrackFit::TrackWord> &trackWord,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  hls::stream<TrackFit::TrackWord> &trackWord_o
//   hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
//   hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
//   hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
//   hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
//   hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
//   hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
//   hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
//   hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o
);

#endif