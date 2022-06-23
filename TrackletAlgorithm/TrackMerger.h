#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include <cassert>
#include "TrackHandler.h"

const unsigned int kNComparisonModules = 3; //check no. which causes synthesis to hang
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kNBufferSize = 32;
const unsigned int kMaxTracks = 32;


class ModuleBuffer{
  public:
    ModuleBuffer();

    ~ModuleBuffer();
    
    void insertTrack(const TrackHandler track);

    TrackHandler readTrack();

    void clearBuffer();

    TrackFit::TrackWord outputTrackFromBuffer(unsigned int trackIndex);

    TrackFit::BarrelStubWord outputBufferBarrelStubs(unsigned int trackIndex, unsigned int stubIndex, unsigned int layerIndex);

    TrackFit::DiskStubWord outputBufferDiskStubs(unsigned int trackIndex, unsigned int stubIndex, unsigned int layerIndex);
    
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

    unsigned int myIndex;

    unsigned int getEndOfStream(){return endOfStream;}

    TrackFit::TrackWord getMasterTrackWord(){return masterTrack.getTrackWord();}

    TrackFit::BarrelStubWord getMasterTrackBarrelStubs(unsigned int stubIndex, unsigned int layerIndex){
      return masterTrack.getBarrelStubArray(layerIndex, stubIndex);}

    TrackFit::DiskStubWord getMasterTrackDiskStubs(unsigned int stubIndex, unsigned int layerIndex){
      return masterTrack.getDiskStubArray(layerIndex, stubIndex);}

    unsigned int getEndOfModule(){return endOfModule;}

    void process(ModuleBuffer &inputBuffer, ModuleBuffer &outputBuffer);

    void endEvent();

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
  const TrackFit::TrackWord trackWord [kMaxTracks],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxTracks],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxTracks],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxTracks],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxTracks],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxTracks],
  int &outputNumber
  );



#endif
