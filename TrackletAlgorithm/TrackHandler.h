#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"
#include "hls_stream.h"

const unsigned int kFullBarrelStubSize = TrackFit::kBarrelStubSize * 4;
const unsigned int kFullDiskStubSize = TrackFit::kDiskStubSize * 4;
const unsigned int kFullTrackWordSize = TrackFit::kTrackWordSize;
const unsigned int kBarrelStubIndexSizeMSB = TrackFit::kTFBarrelStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFZResidSize + TrackFit::kTFStubIndexSize;
const unsigned int kBarrelStubIndexSizeLSB = TrackFit::kTFBarrelStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFZResidSize;
const unsigned int kDiskStubIndexSizeMSB = TrackFit::kTFDiskStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFRResidSize + TrackFit::kTFStubIndexSize;
const unsigned int kDiskStubIndexSizeLSB = TrackFit::kTFDiskStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFRResidSize;
const unsigned int layerStubIndexSize = 1; // 7 stubs per layer

struct TrackStruct {
  
  TrackFit::TrackWord _trackWord = 0; 
  TrackFit::BarrelStubWord _barrelStubArray[4][layerStubIndexSize] = {0}; 
  TrackFit::DiskStubWord _diskStubArray[4][layerStubIndexSize] = {0};
};

class TrackHandler {
  public:
    TrackHandler(){};
    
    ~TrackHandler(){};

    
    bool compareTrack(TrackStruct& trk, TrackStruct& masterTrk, unsigned int& matchFound, unsigned int mergeCondition);

    void mergeTrack(TrackStruct& trk, TrackStruct& masterTrk);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    
  private:
    ap_uint<1> matchesFoundBarrel[4][layerStubIndexSize];
    ap_uint<1> matchesFoundDisk[4][layerStubIndexSize];
    ap_uint<1> stubPadding = 0;
    unsigned int debug = 0;
    ap_uint<12> mergedBarrelStubsMap;
    ap_uint<12> mergedDiskStubsMap;
    ap_uint<24> totalHitMap;
};



#endif