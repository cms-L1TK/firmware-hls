#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackFitMemory.h"
#include "TrackHandler.h"

const unsigned int kNComparisonModules = 16;
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kMaxTrack = 50;
const unsigned int kNLastTracks = kMaxTrack - kNComparisonModules;

class ComparisonModule{
    public:
    ComparisonModule()
     {  tracksProcessed = 0;
        masterTrack._trackWord = 0;
      }
    ~ComparisonModule(){};

    unsigned int getMatchFound(){return matchFound;}

    unsigned int getNProcessed(){return tracksProcessed;}

    unsigned int getEndOfStream(){return endOfStream;}

    TrackFit<NBarrelStub, NDiskStub>::TrackWord getMasterTrackWord(){return masterTrack._trackWord;}

    void process(TrackStruct &inTrack, TrackStruct &outTrack);
    
    TrackStruct& getMasterTrackStruct();

  private:

    unsigned int matchFound{0};
    unsigned int mergeCondition = 3;
    unsigned int tracksProcessed{0};
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};

    TrackStruct masterTrack;
    TrackHandler trackHandler;

    void fillUnmerged(TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i);

    void loadTrack(
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::TrackWord> &trackWord,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_0,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_1,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_2,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord> &barrelStubWords_3,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_0,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_1,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_2,
      hls::stream<TrackFit<NBarrelStub, NDiskStub>::DiskStubWord> &diskStubWords_3,
      TrackStruct& aTrack
    );

    void unloadTrack(
       TrackStruct& aTrack,
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

};

void TrackMerger(const BXType bx,
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