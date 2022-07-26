#include "TrackMerger.h"
#include <bitset>

ComparisonModule::ComparisonModule()
    {
      masterTrack = {0,0,0,0,0,0,0,0,0};
    }

void ComparisonModule::process(track_struct &inTrack, track_struct &outTrack) {
  #pragma HLS inline off
  if (inTrack._trackWord != 0 && masterTrack._trackWord == 0) {
    masterTrack = inTrack;
    outTrack = {0,0,0,0,0,0,0,0,0};
  } else {
    outTrack = inTrack;
  }
}

void loadTrack(
  hls::stream<TrackFit::TrackWord> &trackWord,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  track_struct& aTrack
) {
  trackWord.read(aTrack._trackWord);
  barrelStubWords_0.read(aTrack._barrelStub_0);
  barrelStubWords_1.read(aTrack._barrelStub_1);
  barrelStubWords_2.read(aTrack._barrelStub_2);
  barrelStubWords_3.read(aTrack._barrelStub_3);
  diskStubWords_0.read(aTrack._diskStub_0);        
  diskStubWords_1.read(aTrack._diskStub_1);        
  diskStubWords_2.read(aTrack._diskStub_2);        
  diskStubWords_3.read(aTrack._diskStub_3);        
}  

void unloadTrack(
  track_struct& aTrack,
  hls::stream<TrackFit::TrackWord> &trackWord_o,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
) {
  trackWord_o.write(aTrack._trackWord);
  barrelStubWords_0_o.write(aTrack._barrelStub_0);
  barrelStubWords_1_o.write(aTrack._barrelStub_1);
  barrelStubWords_2_o.write(aTrack._barrelStub_2);
  barrelStubWords_3_o.write(aTrack._barrelStub_3);
  diskStubWords_0_o.write(aTrack._diskStub_0);
  diskStubWords_1_o.write(aTrack._diskStub_1);
  diskStubWords_2_o.write(aTrack._diskStub_2);
  diskStubWords_3_o.write(aTrack._diskStub_3);
}

void TrackMerger(const BXType bx,
  hls::stream<TrackFit::TrackWord> &trackWord,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  hls::stream<TrackFit::TrackWord> &trackWord_o,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
  )
{
  #pragma HLS inline

  ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule complete dim=0

  LOOP_INPUT:
  for (int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS dataflow
    track_struct tracks[kNBuffers];
    #pragma HLS array_partition variable=tracks
    
    loadTrack(trackWord,barrelStubWords_0,barrelStubWords_1,barrelStubWords_2,barrelStubWords_3,diskStubWords_0,
        diskStubWords_1,diskStubWords_2,diskStubWords_3,tracks[0]);
    // std::cout <<"Input Track: "<< i << " " << tracks[0]._trackWord <<std::endl;
    LOOP_CM:
    for (uint j=0;j<kNComparisonModules;++j) {
      #pragma HLS unroll
      comparisonModule[j].process(tracks[j],tracks[j+1]);
    //   // std::cout << "CM "<<j<<" outputs "<<tracks[j+1]._trackWord <<std::endl;
    }

    unloadTrack(tracks[kNComparisonModules],trackWord_o,barrelStubWords_0_o,barrelStubWords_1_o,barrelStubWords_2_o,barrelStubWords_3_o,
        diskStubWords_0_o,diskStubWords_1_o,diskStubWords_2_o,diskStubWords_3_o);
    
  }
  LOOP_MASTERS:
  for (int j=0;j<kNComparisonModules;++j) {
    #pragma HLS pipeline II=1
    track_struct theMaster = comparisonModule[j].getMasterTrackStruct();
    unloadTrack(theMaster,trackWord_o,barrelStubWords_0_o,barrelStubWords_1_o,barrelStubWords_2_o,barrelStubWords_3_o,
        diskStubWords_0_o,diskStubWords_1_o,diskStubWords_2_o,diskStubWords_3_o);
  }
  bx_o = bx;
}