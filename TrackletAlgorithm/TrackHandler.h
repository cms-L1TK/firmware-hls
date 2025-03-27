#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"
#include "hls_stream.h"

typedef TrackFit<trklet::N_LAYER, trklet::N_DISK> TrackFitType;
const unsigned int kFullBarrelStubSize = TrackFitType::kBarrelStubSize * trklet::N_LAYER;
const unsigned int kFullDiskStubSize = TrackFitType::kDiskStubSize * trklet::N_DISK;
const unsigned int kFullTrackWordSize = TrackFitType::kTrackWordSize;
const unsigned int kBarrelStubIndexSizeMSB = TrackFitType::kTFBarrelStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFZResidSize + TrackFitType::kTFStubIndexSize;
const unsigned int kBarrelStubIndexSizeLSB = TrackFitType::kTFBarrelStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFZResidSize;
const unsigned int kDiskStubIndexSizeMSB = TrackFitType::kTFDiskStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFRResidSize + TrackFitType::kTFStubIndexSize;
const unsigned int kDiskStubIndexSizeLSB = TrackFitType::kTFDiskStubRSize + TrackFitType::kTFPhiResidSize + TrackFitType::kTFRResidSize;
const unsigned int maxNumStubs = 1; // 4 stubs per layer
const unsigned int kBarrelStubMap = TrackFitType::kTFHitCountSize * trklet::N_LAYER;
const unsigned int kDiskStubMap = TrackFitType::kTFHitCountSize * trklet::N_LAYER;
const unsigned int kTotHitMap = kBarrelStubMap + kDiskStubMap;

struct TrackStruct {
  
  TrackFitType::TrackWord _trackWord; 
  TrackFitType::BarrelStubWord _barrelStubArray[trklet::N_LAYER][maxNumStubs]; 
  TrackFitType::DiskStubWord _diskStubArray[trklet::N_DISK][maxNumStubs];

  TrackFitType::TrackWord getTrkWord() const {return _trackWord;};
  
  TrackFitType::BarrelStubWord getBarrelStub (unsigned int layerIndex, unsigned int stubIndex) const {
    return _barrelStubArray[layerIndex][stubIndex];
  }

  TrackFitType::DiskStubWord getDiskStub (unsigned int layerIndex, unsigned int stubIndex) const {
    return _diskStubArray[layerIndex][stubIndex];
  }

  void resetTracks();


};

class TrackHandler {
  public:
    TrackHandler(){};
    
    ~TrackHandler(){};

    bool compareTrack(const TrackStruct &trk, TrackStruct &masterTrk, unsigned int& matchFound, unsigned int mergeCondition);

    void mergeTrack(const TrackStruct &trk, TrackStruct &masterTrk);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    
  private:
    ap_uint<1> matchesFoundBarrel[trklet::N_LAYER][maxNumStubs];
    ap_uint<1> matchesFoundDisk[trklet::N_DISK][maxNumStubs];
    ap_uint<1> stubPadding = 0;
    unsigned int debug = 0;
    ap_uint<kBarrelStubMap> mergedBarrelStubsMap;
    ap_uint<kDiskStubMap> mergedDiskStubsMap;
    ap_uint<kTotHitMap> totalHitMap;
};



#endif
