#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackHandler.h"


const unsigned int kNComparisonModules = 1;
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kNTracks = 10;
const unsigned int kNBufferSize = kNTracks;

class ModuleBuffer{
  public:
    ModuleBuffer();

    ~ModuleBuffer();
    
    void insertTrack(const TrackHandler track);

    TrackHandler readTrack();

    void clearBuffer();
    
    private:
      unsigned int readIndex{0};
      unsigned int writeIndex{0};
      TrackHandler trackArray[kNBufferSize];
};

class ComparisonModule{
    public:
    ComparisonModule()
    {
      tracksProcessed = 0;
      TrackFit::TrackWord nullWord(0);
      masterTrack.setTrackWord(nullWord);
      track.setTrackWord(nullWord);

    }
    ~ComparisonModule(){};

    
    unsigned int getMatchFound(){return matchFound;}

    unsigned int getNProcessed(){return tracksProcessed;}

    void processTrack();

    unsigned int myIndex;

    unsigned int getEndOfStream(){return endOfStream;}

    TrackFit::TrackWord getMasterTrackWord(){return masterTrack.getTrackWord();}

    TrackFit::BarrelStubWord getMasterTrackBarrelStubs(unsigned int stubIndex, unsigned int layerIndex){
      return masterTrack.getBarrelStubArray(layerIndex, stubIndex);}

    TrackFit::DiskStubWord getMasterTrackDiskStubs(unsigned int stubIndex, unsigned int layerIndex){
      return masterTrack.getDiskStubArray(layerIndex, stubIndex);}

    unsigned int getEndOfModule(){return endOfModule;}

    void process(ModuleBuffer &inputBuffer, ModuleBuffer &outputBuffer);

    void process(hls::stream<TrackHandler>& inputBuffer,hls::stream<TrackHandler>& outputBuffer);
    void process(hls::stream<TrackFit::TrackWord>& inputBuffer,hls::stream<TrackFit::TrackWord>& outputBuffer);

    // void setInputBuffer(ModuleBuffer &buffer);

    // void setOutputBuffer(ModuleBuffer &buffer);
    
  private:

    unsigned int matchFound{0};
    unsigned int mergeCondition = 3;
    unsigned int tracksProcessed{0};
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};

    TrackHandler masterTrack;
    TrackHandler track;
    // ModuleBuffer inputBuffer;
    // ModuleBuffer outputBuffer;

};

void TrackMerger(const BXType bx,
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
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
  );



#endif