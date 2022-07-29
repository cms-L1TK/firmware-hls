#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackFitMemory.h"
#include "TrackHandler.h"

const unsigned int kNComparisonModules = 10;
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kMaxTrack = 50;
const unsigned int kNLastTracks = kMaxTrack - kNComparisonModules;

class ComparisonModule{
    public:
    ComparisonModule()
    {
      tracksProcessed = 0;
      masterTrack._trackWord = 0;
    }
    ~ComparisonModule(){};

    unsigned int getMatchFound(){return matchFound;}

    unsigned int getNProcessed(){return tracksProcessed;}

    void processTrack();

    unsigned int myIndex;

    unsigned int getEndOfStream(){return endOfStream;}

    TrackFit::TrackWord getMasterTrackWord(){return masterTrack._trackWord;}

    // TrackFit::BarrelStubWord getMasterTrackBarrelStubs(unsigned int stubIndex, unsigned int layerIndex){
    //   return masterTrack.getBarrelStubArray(layerIndex, stubIndex);}

    // TrackFit::DiskStubWord getMasterTrackDiskStubs(unsigned int stubIndex, unsigned int layerIndex){
    //   return masterTrack.getDiskStubArray(layerIndex, stubIndex);}

    unsigned int getEndOfModule(){return endOfModule;}

    // void process(hls::stream<TrackStruct>& inputBuffer,hls::stream<TrackStruct>& outputBuffer);
    void process( TrackStruct &inTrack,  TrackStruct &outTrack);
     TrackStruct getMasterTrackStruct();


  private:

    unsigned int matchFound{0};
    unsigned int mergeCondition = 3;
    unsigned int tracksProcessed{0};
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};

    TrackStruct masterTrack;
    TrackStruct track;


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
       TrackStruct& aTrack
    );

    void unloadTrack(
       TrackStruct& aTrack,
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