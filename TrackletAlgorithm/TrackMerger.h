#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include <cassert>
#include "TrackHandler.h"


class ComparisonModule{
  public:
    ComparisonModule()
    {
      readIndex = 0;
      writeIndex = 0;
    }
    ~ComparisonModule(){};

    void InputTrack(const TrackHandler track);

    void CheckMaster();

    TrackHandler getTrack();
    
    void processTrack();
    
  private:
    //input buffer for each comparison module 
    TrackHandler inputBuffer[10]; 
    unsigned int readIndex;
    unsigned int writeIndex; 
    unsigned int matchFound;
    unsigned int mergeCondition = 3;

    TrackHandler masterTrack;
    TrackHandler track;

};


void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o
  //TrackFit::TrackWord trackWord_o [kMaxProc],
  //TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  //TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  );

#endif