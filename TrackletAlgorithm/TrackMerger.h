#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackFitMemory.h"
#include "TrackHandler.h"

constexpr int kNComparisonModules = 16;
constexpr int kNBuffers = kNComparisonModules + 1;
constexpr int kMaxTrack = 50;
constexpr int kNLastTracks = kMaxTrack - kNComparisonModules;

class ComparisonModule{
    public:
    ComparisonModule(){};
    ~ComparisonModule(){};

    unsigned int getMatchFound(){return matchFound;}

    unsigned int getNProcessed(){return tracksProcessed;}

    unsigned int getEndOfStream(){return endOfStream;}

    ap_uint<trackWordSize> getMasterTrackWord(){return masterTrack._trackWord;}

    void process(const TrackStruct &inTrack, TrackStruct &outTrack);
    
    TrackStruct& getMasterTrackStruct();

    void resetCM();


  private:

    unsigned int matchFound{0};
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};
    unsigned int tracksProcessed{0};

    TrackStruct masterTrack;
    TrackHandler trackHandler;

    void fillTrackArray(const TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i);

    void loadTrack(
      const ap_uint<trackWordSize> trackWordIn,
      const ap_uint<stubWordSize> (stubWordsIn)[NStub],
      TrackStruct& aTrack
    );

    void unloadTrack(
      TrackStruct& aTrack,
      ap_uint<trackWordSize>& trackWordOut,
      ap_uint<stubWordSize> (&stubWordsOut)[NStub]  
    );


};

void TrackMerger(
  const ap_uint<trackWordSize>(trackWord)[kMaxTrack],
  const ap_uint<stubWordSize> (stubWords)[kMaxTrack][NStub],
  ap_uint<trackWordSize> (&trackWord_o)[kMaxTrack],
  ap_uint<stubWordSize> (&stubWords_o)[kMaxTrack][NStub]
  );


#endif