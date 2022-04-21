#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include <cassert>
#include "TrackHandler.h"

const unsigned int bufferSize = 108; // chosen random buffer size - will need to see how many tracks are in test bench
const unsigned int kNComparisonModules = 16;
const unsigned int kNBuffers = kNComparisonModules + 1;


class ModuleBuffer{
  public:
    ModuleBuffer(){
      readIndex = 0;
      writeIndex = 0;
    }

    ~ModuleBuffer(){};
    
    void insertTrack(const TrackHandler track);

    TrackHandler readTrack();

    bool isEmpty();

    void clearBuffer();

    private:
      unsigned int readIndex{0};
      unsigned int writeIndex{0};
      TrackHandler moduleBuffer[bufferSize];
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

    void process();

    void setInputBuffer(ModuleBuffer *buffer);
    void setOutputBuffer(ModuleBuffer *buffer);
    
  private:

    unsigned int matchFound{0};
    unsigned int mergeCondition = 3;
    unsigned int tracksProcessed{0};
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};

    TrackHandler masterTrack;
    TrackHandler track;
    ModuleBuffer* inputBuffer;
    ModuleBuffer* outputBuffer;

};

class TrackMerger{
  public:
  TrackMerger(){
    bufferPtr = buffer;
    // loop over the CMs to set the input/output buffer variables for each CM
    LOOP_SetBuffers:
    for (unsigned int i = 0; i < kNComparisonModules; i++){
      #pragma HLS unroll
      comparisonModule[i].setInputBuffer(&bufferPtr[i]);
      comparisonModule[i].setOutputBuffer(&bufferPtr[i]);
    }
  };

  ~TrackMerger(){};

  void TrackMergerMain(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  );

  private:
  ModuleBuffer buffer[kNBuffers];
  ComparisonModule comparisonModule[kNComparisonModules];
  ModuleBuffer *bufferPtr;

};



#endif