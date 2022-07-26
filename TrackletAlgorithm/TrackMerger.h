#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackFitMemory.h"

const unsigned int kNComparisonModules = 10;
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kMaxTrack = 50;

typedef struct {
  TrackFit::TrackWord _trackWord;
  TrackFit::BarrelStubWord _barrelStub_0;  
  TrackFit::BarrelStubWord _barrelStub_1;  
  TrackFit::BarrelStubWord _barrelStub_2;  
  TrackFit::BarrelStubWord _barrelStub_3;  
  TrackFit::DiskStubWord _diskStub_0;
  TrackFit::DiskStubWord _diskStub_1;
  TrackFit::DiskStubWord _diskStub_2;
  TrackFit::DiskStubWord _diskStub_3;
} track_struct;

class ComparisonModule{
    public:
    ComparisonModule();
    ~ComparisonModule(){};

    void processTrack();

    TrackFit::TrackWord getMasterTrackWord(){return masterTrack._trackWord;}
    track_struct getMasterTrackStruct(){return masterTrack;}

    // TrackFit::BarrelStubWord getMasterTrackBarrelStubs(unsigned int stubIndex, unsigned int layerIndex){
    //   return masterTrack.getBarrelStubArray(layerIndex, stubIndex);}

    // TrackFit::DiskStubWord getMasterTrackDiskStubs(unsigned int stubIndex, unsigned int layerIndex){
    //   return masterTrack.getDiskStubArray(layerIndex, stubIndex);}

    void process(track_struct &inTrack,track_struct &outTrack);


  private:

    track_struct masterTrack;

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
    );

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
    );

};

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
  );



#endif