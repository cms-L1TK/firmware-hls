#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "hls_stream.h"
#include <cassert>
#include "TrackFitMemory.h"
#include "TrackHandler.h"

const unsigned int kNComparisonModules = 16;
const unsigned int kNBuffers = kNComparisonModules + 1;
const unsigned int kMaxTrack = 50;
const unsigned int kNLastTracks = kMaxTrack - kNComparisonModules;

class ComparisonModule{
    public:
    ComparisonModule(){};
    ~ComparisonModule(){};

    unsigned int getMatchFound(){return matchFound;}

    unsigned int getNProcessed(){return tracksProcessed;}

    unsigned int getEndOfStream(){return endOfStream;}

    TrackFitType::TrackWord getMasterTrackWord(){return masterTrack._trackWord;}

    void process(const TrackStruct &inTrack, TrackStruct &outTrack);
    
    TrackStruct& getMasterTrackStruct();

    void resetCM();


  private:

    unsigned int matchFound{0};
    unsigned int mergeCondition = 3;
    unsigned int endOfStream{0};
    unsigned int endOfModule{0};
    unsigned int tracksProcessed{0};

    TrackStruct masterTrack;
    TrackHandler trackHandler;

    void fillTrackArray(const TrackStruct& inTrack, TrackStruct* outTrack, unsigned int i);

    void loadTrack(
      const TrackFitType::TrackWord& trackWordIn,
      const TrackFitType::BarrelStubWord (&barrelStubWordsIn)[trklet::N_LAYER],
      const TrackFitType::DiskStubWord (&diskStubWordsIn)[trklet::N_DISK],
      TrackStruct& aTrack
    );

    void unloadTrack(
      TrackStruct& aTrack,
      TrackFitType::TrackWord& trackWordOut,
      TrackFitType::BarrelStubWord (&barrelStubWordsOut)[trklet::N_LAYER],  
      TrackFitType::DiskStubWord (&diskStubWordsOut)[trklet::N_DISK]
    );


};

void TrackMerger(const BXType bx,
  const TrackFitType::TrackWord trackWord[kMaxTrack],
  const TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][trklet::N_LAYER],
  const TrackFitType::DiskStubWord diskStubWords[kMaxTrack][trklet::N_DISK],
  BXType bx_o,
  TrackFitType::TrackWord (&trackWord_o)[kMaxTrack],
  TrackFitType::BarrelStubWord (&barrelStubWords_o)[kMaxTrack][trklet::N_LAYER], 
  TrackFitType::DiskStubWord (&diskStubWords_o)[kMaxTrack][trklet::N_DISK] 
  );


#endif
