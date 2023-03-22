#ifndef TrackletAlgorithm_TrackHandler_h
#define TrackletAlgorithm_TrackHandler_h
#include "TrackFitMemory.h"
#include "hls_stream.h"
// constexpr int NBarrelStub = 4;
// constexpr int NDiskStub = 4;

constexpr int NStub = 8;
constexpr int trackWordSize = 27; // known at compile time
constexpr int trkVld = trackWordSize -1;
constexpr int stubWordSize = 1+1+4+7+12+13+12; // the stub Id is 7
constexpr int stubIdMSB = 7+12+13+12-1;
constexpr int stubIdLSB = 12+13+12;
constexpr int stubVld = stubWordSize-1;
constexpr int stubIDSize = 7;
constexpr int mergeCondition = 3;

ap_uint<stubIDSize> getStubId(const ap_uint<stubWordSize>& stubWrd){
  return stubWrd.range(stubIdMSB, stubIdLSB);
}
ap_uint<stubIDSize> getStubValid(const ap_uint<stubWordSize>& stubWrd){
  return stubWrd.range(stubVld, stubVld);
}
bool getTrackValid(const ap_uint<trackWordSize>& trackWrd){
  return trackWrd.range(trkVld, trkVld) == 1;
}



struct TrackStruct {
  
  ap_uint<trackWordSize> _trackWord; 
  ap_uint<stubWordSize> _stubArray[NStub]; 


  ap_uint<trackWordSize> getTrkWord() const {return _trackWord;};
  
  ap_uint<stubWordSize> getStub (unsigned int layerIndex) const {
    // #pragma HLS array_partion variable=_stubArray
    return _stubArray[layerIndex];
  }

  ap_uint<stubIDSize> getStubId(int layerIndex) const{
    return getStubId(_stubArray[layerIndex]);
  }

  ap_uint<stubVld> getStubValid(int layerIndex) const{
    return getStubValid(_stubArray[layerIndex]);
  }

  void resetTracks();


};

class TrackHandler {
  public:
    TrackHandler(){};
    
    ~TrackHandler(){};

    bool compareTrack(const TrackStruct &trk, TrackStruct &masterTrk);

    void setDebugFlag(unsigned int debugFlag){
      debug = debugFlag;
    }

    
  private:
    ap_uint<1> matchesFoundStubs[NStub];
    unsigned int debug = 0;

};



#endif