#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"

const unsigned int kFullBarrelStubSize = TrackFit::kBarrelStubSize * 4;
const unsigned int kFullDiskStubSize = TrackFit::kDiskStubSize * 4;
const unsigned int kFullTrackWordSize = TrackFit::kTrackWordSize;
const unsigned int kBarrelStubIndexSizeMSB = TrackFit::kTFBarrelStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFZResidSize + TrackFit::kTFStubIndexSize;
const unsigned int kBarrelStubIndexSizeLSB = TrackFit::kTFBarrelStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFZResidSize;
const unsigned int kDiskStubIndexSizeMSB = TrackFit::kTFDiskStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFRResidSize + TrackFit::kTFStubIndexSize;
const unsigned int kDiskStubIndexSizeLSB = TrackFit::kTFDiskStubRSize + TrackFit::kTFPhiResidSize + TrackFit::kTFRResidSize;
const int layerStubIndexSize = 10; //7

class TrackHandler{
  public:
    // TrackHandler(){};
    TrackHandler(const TrackFit::TrackWord trackWord,
      const TrackFit::BarrelStubWord barrelStubWords[4],
      const TrackFit::DiskStubWord diskStubWords[4])
    {
      // prepare the TrackHandler members
      // assign the bits to trackWord, barrelStubsWord, diskStubsWord
      // set the barrel and disk stub words in constructor using loop
      // all the information from the track and stub words;
      trkWord = trackWord;
      LOOP_THInputsBarrel:
      for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
        #pragma HLS unroll
        barrelStubArray[j][0] = barrelStubWords[j];
        #ifndef _SYNTHESIS_
        // std::cout << "brlStub: " << j << " " << barrelStubArray[j][0] << std::endl;
        #endif
      }
      LOOP_THInputsDisk:
      for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
        #pragma HLS unroll
        diskStubArray[k][0] = diskStubWords[k];
      }
    
    }

    TrackHandler()
    { // sets words to 0
      trkWord = 0;
      LOOP_THInputsBarrel0:
      for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
        #pragma HLS unroll
        barrelStubArray[j][0] = 0;
      }
      LOOP_THInputsDisk0:
      for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
        #pragma HLS unroll
        diskStubArray[k][0] = 0;
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

    int MergeTrack(TrackHandler track, unsigned int& matchFound, unsigned int mergeCondition);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    TrackFit::BarrelStubWord getBarrelStubArray(unsigned int layerIndex, unsigned int stubIndex) const {
      return barrelStubArray[layerIndex][stubIndex];
    }

    TrackFit::DiskStubWord getDiskStubArray(unsigned int layerIndex, unsigned int stubIndex) const {
      return diskStubArray[layerIndex][stubIndex];
    }


    
  private:
    TrackFit::TrackWord trkWord;
    TrackFit::BarrelStubWord barrelStubArray[4][layerStubIndexSize]; 
    TrackFit::DiskStubWord diskStubArray[4][layerStubIndexSize];
    ap_uint<1> matchesFoundBarrel[4][layerStubIndexSize];
    ap_uint<1> matchesFoundDisk[4][layerStubIndexSize];
    ap_uint<1> stubPadding = 0;
    unsigned int debug = 0;
    ap_uint<12> mergedBarrelStubsMap;
    ap_uint<12> mergedDiskStubsMap;
    ap_uint<24> totalHitMap;
};
#endif