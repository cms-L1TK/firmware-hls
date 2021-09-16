#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "TrackFitMemory.h"

class TrackHandler{
  public:
    TrackHandler();
    TrackHandler(TrackFit trk)
    {
      //prepare the TrackHandler members
    }

  private:

  //formats the input tracks
  //duplicate TrackFitMemory fns
};


class ComparisonModule{
  public:
    ComparisonModule()
    {
      bufferIndex=0;
    }
    ~ComparisonModule();

    void InputTrack(TrackHandler trk); //the tracks are read in from TrackBuilder output
    //input buffer for each comparison module 
    
  private:
    bool CompareTracks(const TrackHandler masterTrack, const TrackHandler trk);
    

    void MergeTrack(TrackHandler &masterTrack, const TrackHandler trk);
    

    TrackHandler inputBuffer[kMaxProc];
    unsigned int bufferIndex;

};



void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]);

#endif