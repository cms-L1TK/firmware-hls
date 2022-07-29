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
const int layerStubIndexSize = 10; //7

struct TrackStruct {
  TrackFit::TrackWord _trackWord = 0;
  TrackFit::BarrelStubWord _barrelStub_0 = 0;  
  TrackFit::BarrelStubWord _barrelStub_1 = 0; 
  TrackFit::BarrelStubWord _barrelStub_2 = 0;
  TrackFit::BarrelStubWord _barrelStub_3 = 0;  
  TrackFit::DiskStubWord _diskStub_0 = 0;
  TrackFit::DiskStubWord _diskStub_1 = 0;
  TrackFit::DiskStubWord _diskStub_2 = 0;
  TrackFit::DiskStubWord _diskStub_3 = 0;
};

// struct TrackStruct {

//   TrackFit::TrackWord _trackWord;
//   TrackFit::BarrelStubWord _barrelStub_0;  
//   TrackFit::BarrelStubWord _barrelStub_1;  
//   TrackFit::BarrelStubWord _barrelStub_2; 
//   TrackFit::BarrelStubWord _barrelStub_3;  
//   TrackFit::DiskStubWord _diskStub_0;
//   TrackFit::DiskStubWord _diskStub_1;
//   TrackFit::DiskStubWord _diskStub_2;
//   TrackFit::DiskStubWord _diskStub_3;

  // TrackStruct(){_trackWord = 0, 
  //               _barrelStub_0 = 0, 
  //               _barrelStub_1 = 0, 
  //               _barrelStub_2 = 0,
  //               _barrelStub_3 = 0,
  //               _diskStub_0 = 0,
  //               _diskStub_1 = 0;
  //               _diskStub_2 = 0;
  //               _diskStub_3 = 0;}

// };

// struct EmptyTrackStruct : TrackStruct{
//   EmptyTrackStruct() : TrackStruct() {}
//   };






class TrackHandler{
  public:
    // TrackHandler(){};
    // TrackHandler(const TrackFit::TrackWord trackWord,
    //   const TrackFit::BarrelStubWord barrelStubWords[4],
    //   const TrackFit::DiskStubWord diskStubWords[4])
    // {
    //   // prepare the TrackHandler members
    //   // assign the bits to trackWord, barrelStubsWord, diskStubsWord
    //   // set the barrel and disk stub words in constructor using loop
    //   // all the information from the track and stub words;
    //   trkWord = trackWord;
    //   LOOP_THInputsBarrel:
    //   for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
    //     #pragma HLS unroll
    //     barrelStubArray[j][0] = barrelStubWords[j];
    //     #ifndef _SYNTHESIS_
    //     // std::cout << "brlStub: " << j << " " << barrelStubArray[j][0] << std::endl;
    //     #endif
    //   }
    //   LOOP_THInputsDisk:
    //   for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
    //     #pragma HLS unroll
    //     diskStubArray[k][0] = diskStubWords[k];
    //   }
    
    // }

    // TrackHandler()
    // { // sets words to 0
    //   trkWord = 0;
    //   LOOP_THInputsBarrel0:
    //   for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
    //     #pragma HLS unroll
    //     barrelStubArray[j][0] = 0;
    //   }
    //   LOOP_THInputsDisk0:
    //   for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
    //     #pragma HLS unroll
    //     diskStubArray[k][0] = 0;
    //   }

    TrackHandler(const TrackStruct input_track){
        trkWord = input_track._trackWord;
        barrelStubArray[1][0] = input_track._barrelStub_0;
        barrelStubArray[2][0] = input_track._barrelStub_1;
        barrelStubArray[3][0] = input_track._barrelStub_2;
        barrelStubArray[4][0] = input_track._barrelStub_3;
        diskStubArray[0][0] = input_track._diskStub_0;
        diskStubArray[1][0] = input_track._diskStub_1;
        diskStubArray[2][0] = input_track._diskStub_2;
        diskStubArray[3][0] = input_track._diskStub_3;


    }
    
    ~TrackHandler(){};

    TrackFit::TrackWord getTrackWord() const{
      return trkWord;
    }

    void setTrackWord(TrackFit::TrackWord trackWord){
      trkWord = trackWord;
    }
    
    void CompareTrack(TrackHandler track);

    bool MergeTrack(TrackHandler track, unsigned int& matchFound, unsigned int mergeCondition);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    TrackFit::BarrelStubWord getBarrelStubArray(unsigned int layerIndex, unsigned int stubIndex) const {
      return barrelStubArray[layerIndex][stubIndex];
    }

    TrackFit::DiskStubWord getDiskStubArray(unsigned int layerIndex, unsigned int stubIndex) const {
      return diskStubArray[layerIndex][stubIndex];
    }

    void setTrkWord(TrackStruct track);
    void setBarrelArray(TrackStruct track);
    void setDiskArray(TrackStruct track);
    
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