#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"
#include "hls_stream.h"
const int NBarrelStub = 4;
const int NDiskStub = 4;
const unsigned int kFullBarrelStubSize = TrackFit<NBarrelStub, NDiskStub>::kBarrelStubSize * 4;
const unsigned int kFullDiskStubSize = TrackFit<NBarrelStub, NDiskStub>::kDiskStubSize * 4;
const unsigned int kFullTrackWordSize = TrackFit<NBarrelStub, NDiskStub>::kTrackWordSize;
const unsigned int kBarrelStubIndexSizeMSB = TrackFit<NBarrelStub, NDiskStub>::kTFBarrelStubRSize + TrackFit<NBarrelStub, NDiskStub>::kTFPhiResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFZResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFStubIndexSize;
const unsigned int kBarrelStubIndexSizeLSB = TrackFit<NBarrelStub, NDiskStub>::kTFBarrelStubRSize + TrackFit<NBarrelStub, NDiskStub>::kTFPhiResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFZResidSize;
const unsigned int kDiskStubIndexSizeMSB = TrackFit<NBarrelStub, NDiskStub>::kTFDiskStubRSize + TrackFit<NBarrelStub, NDiskStub>::kTFPhiResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFRResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFStubIndexSize;
const unsigned int kDiskStubIndexSizeLSB = TrackFit<NBarrelStub, NDiskStub>::kTFDiskStubRSize + TrackFit<NBarrelStub, NDiskStub>::kTFPhiResidSize + TrackFit<NBarrelStub, NDiskStub>::kTFRResidSize;
const unsigned int layerStubIndexSize = 1; // 7 stubs per layer

struct TrackStruct {
  
  TrackFit<NBarrelStub, NDiskStub>::TrackWord _trackWord = 0; 
  TrackFit<NBarrelStub, NDiskStub>::BarrelStubWord _barrelStubArray[4][layerStubIndexSize] = {0}; 
  TrackFit<NBarrelStub, NDiskStub>::DiskStubWord _diskStubArray[4][layerStubIndexSize] = {0};
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