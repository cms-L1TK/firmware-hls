#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"
#include "hls_stream.h"
const int NBarrelStub = 4;
const int NDiskStub = 4;
typedef TrackFit<NBarrelStub, NDiskStub> TrackFitType;
const unsigned int kFullBarrelStubSize = TrackFitType::kBarrelStubSize * NBarrelStub;
const unsigned int kFullDiskStubSize = TrackFitType::kDiskStubSize * NDiskStub;
const unsigned int kFullTrackWordSize = TrackFitType::kTrackWordSize;
const unsigned int kBarrelStubIndexSizeMSB = TrackFitType::kTFBarrelStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFZResidSize + TrackFitType::kTFStubIndexSize;
const unsigned int kBarrelStubIndexSizeLSB = TrackFitType::kTFBarrelStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFZResidSize;
const unsigned int kDiskStubIndexSizeMSB = TrackFitType::kTFDiskStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFRResidSize + TrackFitType::kTFStubIndexSize;
const unsigned int kDiskStubIndexSizeLSB = TrackFitType::kTFDiskStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFRResidSize;
const unsigned int layerStubIndexSize = 1; // 7 stubs per layer
const unsigned int kBarrelStubMap = TrackFitType::kTFHitCountSize * NBarrelStub;
const unsigned int kDiskStubMap = TrackFitType::kTFHitCountSize * NBarrelStub;
const unsigned int kTotHitMap = kBarrelStubMap + kDiskStubMap;

struct TrackStruct {
  
  TrackFitType::TrackWord _trackWord = 0; 
  TrackFitType::BarrelStubWord _barrelStubArray[NBarrelStub][layerStubIndexSize] = {0}; 
  TrackFitType::DiskStubWord _diskStubArray[NDiskStub][layerStubIndexSize] = {0};
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
    ap_uint<1> matchesFoundBarrel[NBarrelStub][layerStubIndexSize];
    ap_uint<1> matchesFoundDisk[NDiskStub][layerStubIndexSize];
    ap_uint<1> stubPadding = 0;
    unsigned int debug = 0;
    ap_uint<kDiskStubMap> mergedBarrelStubsMap;
    ap_uint<kBarrelStubMap> mergedDiskStubsMap;
    ap_uint<kTotHitMap> totalHitMap;
};



#endif