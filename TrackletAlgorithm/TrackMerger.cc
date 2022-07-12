#include "TrackMerger.h"
#include <bitset>

void ComparisonModule::process(hls::stream<track_struct> &inputBuffer, hls::stream<track_struct> &outputBuffer){
  #pragma HLS inline
  #pragma HLS pipeline
  track_struct track;
  inputBuffer.read(track);
  //assert(track._trackWord !=0 && "Null track in CM");
  outputBuffer.write(track);
  tracksProcessed++;
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

  hls::stream<track_struct> buffer[kNBuffers];
  #pragma HLS STREAM variable=buffer depth=2

  LOOP_INPUT:
  for (int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS dataflow
    track_struct theTrack;
    trackWord.read(theTrack._trackWord);
    barrelStubWords_0.read(theTrack._barrelStub_0);
    barrelStubWords_1.read(theTrack._barrelStub_1);
    barrelStubWords_2.read(theTrack._barrelStub_2);
    barrelStubWords_3.read(theTrack._barrelStub_3);
    diskStubWords_0.read(theTrack._diskStub_0);        
    diskStubWords_1.read(theTrack._diskStub_1);        
    diskStubWords_2.read(theTrack._diskStub_2);        
    diskStubWords_3.read(theTrack._diskStub_3);        
    buffer[0].write(theTrack);

    LOOP_CM:
    for(unsigned int j = 0; j < kNComparisonModules; j++){
      comparisonModule[j].process(buffer[j], buffer[j+1]);
    } 

    track_struct track_o; 
    buffer[kNBuffers-1].read(track_o);
    //assert(track_o._trackWord != 0 && "Null track in FIFO"); // Check it is not a null track
    trackWord_o.write(track_o._trackWord);
    barrelStubWords_0_o.write(track_o._barrelStub_0);
    barrelStubWords_1_o.write(track_o._barrelStub_1);
    barrelStubWords_2_o.write(track_o._barrelStub_2);
    barrelStubWords_3_o.write(track_o._barrelStub_3);
    diskStubWords_0_o.write(track_o._diskStub_0);
    diskStubWords_1_o.write(track_o._diskStub_1);
    diskStubWords_2_o.write(track_o._diskStub_2);
    diskStubWords_3_o.write(track_o._diskStub_3);
  }
  bx_o = bx;
}