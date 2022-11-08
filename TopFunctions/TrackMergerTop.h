#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "hls_stream.h"
#include "../TrackletAlgorithm/TrackMerger.h"
#include "../TrackletAlgorithm/TrackHandler.h"

void TrackMergerTop(const BXType bx,
  stream<TrackFitType::TrackWord> &trackWord,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3,
  stream<TrackFitType::DiskStubWord> &diskStubWords_0,
  stream<TrackFitType::DiskStubWord> &diskStubWords_1,
  stream<TrackFitType::DiskStubWord> &diskStubWords_2,
  stream<TrackFitType::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  stream<TrackFitType::TrackWord> &trackWord_o,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_0_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_1_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_2_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_3_o
);

#endif