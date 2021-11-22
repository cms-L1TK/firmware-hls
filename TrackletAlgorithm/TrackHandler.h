#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"

const unsigned int kFullBarrelStubSize = TrackFit::kBarrelStubSize * 4;
const unsigned int kFullDiskStubSize = TrackFit::kDiskStubSize * 4;
const unsigned int kFullTrackWordSize = TrackFit::kTrackWordSize;
const unsigned int kStubIndexSizeMSB = TrackFit::kTFValidSize + TrackFit::kTFTrackIndexSize + TrackFit::kTFStubIndexSize;
const unsigned int kStubIndexSizeLSB = TrackFit::kTFValidSize + TrackFit::kTFTrackIndexSize;
const int layerStubIndexSize = 10;

class TrackHandler{
  public:
    TrackHandler(){};
    TrackHandler(const TrackFit::TrackWord trackWord,
      const TrackFit::BarrelStubWord barrelStubWords[4],
      const TrackFit::DiskStubWord diskStubWords[4])
    {
      // prepare the TrackHandler members
      // assign the bits to trackWord, barrelStubsWord, diskStubsWord
      // set the barrel and disk stub words in constructor using loop
      // all the information from the track and stub words;
      trkWord = trackWord;
      for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
        barrelStubArray[j][0] = barrelStubWords[j];
      }

      for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
        diskStubArray[k][0] = diskStubWords[k];
      }
    
    }
  
    ~TrackHandler(){};

    TrackFit::TrackWord getTrackWord() const{
      return trkWord;
    }

    void setTrackWord(TrackFit::TrackWord trackWord){
      trkWord = trackWord;
    }
    
    void CompareTrack(TrackHandler track);

    void MergeTrack(TrackHandler track, unsigned int& matchFound, unsigned int mergeCondition);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    
  private:
    TrackFit::TrackWord trkWord;
    TrackFit::BarrelStubWord barrelStubArray[4][layerStubIndexSize]; 
    TrackFit::DiskStubWord diskStubArray[4][layerStubIndexSize];
    ap_uint<1> matchesFoundBarrel[4][layerStubIndexSize];
    ap_uint<1> matchesFoundDisk[4][layerStubIndexSize];
    ap_uint<1> stubPadding = 0;
    unsigned int debug = 0;
};
#endif