#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include <cassert>
#include "TrackHandler.h"

class ComparisonModule{
  public:
    ComparisonModule()
    {
      bufferIndex = 0;
    }
    ~ComparisonModule(){};

    void InputTrack(const TrackFit::TrackWord trackWord,
    const TrackFit::BarrelStubWord barrelStubWords[4],
    const TrackFit::DiskStubWord diskStubWords[4]); //the tracks are read in from TrackBuilder output
    
    
  private:
    bool CompareTracks(const TrackHandler masterTrack, const TrackHandler track);
    

    void MergeTrack(TrackHandler &masterTrack, const TrackHandler track);
    

    //input buffer for each comparison module 
    TrackHandler inputBuffer[kMaxProc];
    unsigned int bufferIndex;

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