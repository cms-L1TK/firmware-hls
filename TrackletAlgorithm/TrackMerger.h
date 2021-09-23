#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "TrackFitMemory.h"
#include <cassert>

class TrackHandler : public TrackFit{
  public:
    TrackHandler();
    TrackHandler(TrackFitData data)
    {
      //prepare the TrackHandler members
      track = data;
    }
    ~TrackHandler();
    
    TrackFitData track;

    TFSTUBINDEX getStubIndex(int Hit) const {
      assert(Hit >= 0 && Hit <= kNStubs - 1);
      return track.range(TrackFitBits::kTFStubIndexMSB(Hit),TrackFitBits::kTFStubIndexLSB(Hit));
    }
    TFSTUBPHIRESID getStubPhiResid(int Hit) const {
      assert(Hit >= 0 && Hit <= kNStubs - 1);
      return track.range(TrackFitBits::kTFStubPhiResidMSB(Hit),TrackFitBits::kTFStubPhiResidLSB(Hit));
    }
    BarrelStubWord getBarrelStubWord(int Hit) const {
      assert(Hit >= 0 && Hit <= kNBarrelStubs - 1);
      return track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
    }
    DiskStubWord getDiskStubWord(int Hit) const {
      assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1);
      return track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
    }
    void setBarrelStubWord(const BarrelStubWord &word, int Hit) {
      assert(Hit >= 0 && Hit <= kNBarrelStubs - 1);
      track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
    }
    void setDiskStubWord(const DiskStubWord &word, int Hit) {
      assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1);
      track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
    }



  private:
};


class ComparisonModule{
  public:
    ComparisonModule()
    {
      bufferIndex = 0;
    }
    ~ComparisonModule();

    void InputTrack(TrackFit::TrackFitData data); //the tracks are read in from TrackBuilder output
    
    
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
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]);

#endif