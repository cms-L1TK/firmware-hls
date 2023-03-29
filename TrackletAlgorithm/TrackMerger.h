#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "ap_int.h"

constexpr int kNComparisonModules = 16;
constexpr int kNBuffers = kNComparisonModules + 1;
constexpr int kMaxTrack = 108;
constexpr int kNLastTracks = kMaxTrack - kNComparisonModules;
constexpr int rst = 1;
constexpr int NStub = 7;
constexpr int trackWordSize = 27; // known at compile time
constexpr int trkVld = trackWordSize -1;
constexpr int stubWordSize = 1+1+4+7+12+13+12; // the stub Id is 7
constexpr int stubIdMSB = 7+12+13+12-1;
constexpr int stubIdLSB = 12+13+12;
constexpr int stubVld = stubWordSize-1;
constexpr int stubIDSize = 7;
constexpr int mergeCondition = 3;

constexpr int dinSize = rst + trackWordSize + NStub * stubWordSize;
constexpr int doutSize = dinSize-stubIDSize*NStub;

inline constexpr int getdinStubIdxHigh(int i){
  return dinSize - trackWordSize - (i+1) * stubWordSize -1;
}

inline constexpr int getdinStubIdxLow(int i){
  return dinSize - trackWordSize - (i+1) * stubWordSize - stubWordSize ;
}

inline constexpr int getdoutStubIdxHigh(int i){
  return doutSize - trackWordSize - (i+1) * stubWordSize -1;
}

inline constexpr int getdoutStubIdxLow(int i){
  return doutSize - trackWordSize - (i+1) * stubWordSize - stubWordSize ;
}

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

  void loadTrack(const ap_uint<dinSize>& din){
    #pragma HLS array_partition variable _stubArray
    // extract trackWord from din
     _trackWord = din.range(dinSize-1, dinSize-trackWordSize);

    // extract stubWord from din;
    for (int i = 0; i < NStub; i++) {
      #pragma HLS unroll
       _stubArray[i] = din.range(getdinStubIdxHigh(i), getdinStubIdxLow(i));
      }
  }
    

  void unloadTrack(ap_uint<doutSize>& dout) {
    #pragma HLS array_partition variable=_stubArray
    ap_uint<doutSize> tmp(0);
    // extract trackWord from dout
    tmp(doutSize-1, doutSize-trackWordSize) = _trackWord;
    // extract stubWord from dout
    for (int i = 0; i < NStub; i++) {
      #pragma HLS unroll
      tmp(getdoutStubIdxHigh(i), getdoutStubIdxLow(i)) =  _stubArray[i];
      }
      dout=tmp;
    
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
    const ap_uint<dinSize> din[kMaxTrack],
    ap_uint<doutSize> (&dout)[kMaxTrack]);


#endif