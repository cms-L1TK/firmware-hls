#include "TrackMergerTop.h"

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
  ){
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
