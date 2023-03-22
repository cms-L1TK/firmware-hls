#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "ap_int.h"

constexpr int kNComparisonModules = 16;
constexpr int kNBuffers = kNComparisonModules + 1;
constexpr int kMaxTrack = 108;
constexpr int kNLastTracks = kMaxTrack - kNComparisonModules;

constexpr int NStub = 7;
constexpr int trackWordSize = 27; // known at compile time
constexpr int trkVld = trackWordSize -1;
constexpr int stubWordSize = 1+1+4+7+12+13+12; // the stub Id is 7
constexpr int stubIdMSB = 7+12+13+12-1;
constexpr int stubIdLSB = 12+13+12;
constexpr int stubVld = stubWordSize-1;
constexpr int stubIDSize = 7;
constexpr int mergeCondition = 3;



struct TrackStruct {
  
  ap_uint<trackWordSize> _trackWord; 
  ap_uint<stubWordSize> _stubArray[NStub]; 

  void resetTracks() {
    _trackWord = 0;
    LOOP_StubReset: 
    for (unsigned int stubIdx= 0; stubIdx < NStub; stubIdx++){
      #pragma HLS unroll
      _stubArray[stubIdx]= 0;
    }
  }

  ap_uint<stubIDSize> getStubId(int layer) const {
    return _stubArray[layer].range(stubIdMSB, stubIdLSB);
  }
  ap_uint<stubIDSize> getStubValid(int layer) const {
    return _stubArray[layer].range(stubVld, stubVld);
  }
  bool getTrackValid() const {
    return _trackWord.range(trkVld, trkVld) == 1;
  }

  bool compareTrack(const TrackStruct &trk) {
    // Compare the two tracks, masterTrack and trk
    #pragma HLS array_partition variable=_stubArray complete dim=0
    #pragma HLS array_partition variable=trk._stubArray complete dim=0
    int matchesFound(0);
    LOOP_CompareStubs:
    for (unsigned int stubNum = 0; stubNum < NStub; stubNum++){
      #pragma HLS unroll
      ap_uint<stubIDSize> masterStubIndex = getStubId(stubNum);
      ap_uint<stubIDSize> inputStubIndex = trk.getStubId(stubNum);
      ap_uint<stubVld> masterStubValid = getStubValid(stubNum);
      ap_uint<stubVld> inputStubValid = trk.getStubValid(stubNum);
      
      if((masterStubIndex == inputStubIndex) && masterStubValid == 1 && inputStubValid == 1)
        matchesFound++;
    }
    return matchesFound >= mergeCondition;
  }

  void loadTrack(const ap_uint<trackWordSize> trackWordIn, const ap_uint<stubWordSize> (stubWordsIn)[NStub]) {
    #pragma HLS array_partition variable=stubWordsIn
    _trackWord = trackWordIn;
    for (unsigned int i = 0; i < NStub; i++){
      #pragma HLS unroll
      _stubArray[i] = stubWordsIn[i];
    }   
  }  

  void unloadTrack(ap_uint<trackWordSize>& trackWordOut, ap_uint<stubWordSize> (&stubWordsOut)[NStub]) {
  #pragma HLS array_partition variable=stubWordsOut
  trackWordOut = _trackWord; 
  for (unsigned int i = 0; i < NStub; i++){
    #pragma HLS unroll
    stubWordsOut[i] = _stubArray[i];
    }

  return;
}


};

class ComparisonModule{
    public:
    ComparisonModule(){};
    ~ComparisonModule(){};

    ap_uint<trackWordSize> getMasterTrackWord(){return masterTrack._trackWord;}

    void process(const TrackStruct &inTrack, TrackStruct &outTrack);
    
    TrackStruct& getMasterTrackStruct();

    void resetCM();


  private:
    int tracksProcessed;

    TrackStruct masterTrack;

    void fillTrackArray(const TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i);


};

void TrackMerger(
  const ap_uint<trackWordSize> trackWord[kMaxTrack],
  const ap_uint<stubWordSize> stubWords[kMaxTrack][NStub],
  ap_uint<trackWordSize> (&trackWord_o)[kMaxTrack],
  ap_uint<stubWordSize> (&stubWords_o)[kMaxTrack][NStub]
  );


#endif