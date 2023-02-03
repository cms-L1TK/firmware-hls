#include "TrackMergerTop.h"

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
  ){
    #pragma HLS inline recursive
    TrackMerger(bx, trackWord, 
      barrelStubWords_0, 
      barrelStubWords_1, barrelStubWords_2, barrelStubWords_3,
      diskStubWords_0, diskStubWords_1, diskStubWords_2, diskStubWords_3, 
      bx_o, 
      trackWord_o, 
      barrelStubWords_0_o, barrelStubWords_1_o, barrelStubWords_2_o, barrelStubWords_3_o, 
      diskStubWords_0_o, diskStubWords_1_o, diskStubWords_2_o, diskStubWords_3_o 
    );
}
