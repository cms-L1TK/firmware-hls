#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "../TrackletAlgorithm/TrackMerger.h"
#include "../TrackletAlgorithm/TrackHandler.h"

void TrackMergerTop(const BXType bx,
  const TrackFitType::TrackWord trackWord[kMaxTrack],
  const TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][NBarrelStub],
  const TrackFitType::DiskStubWord diskStubWords[kMaxTrack][NDiskStub],
  BXType bx_o,
  TrackFitType::TrackWord (&trackWord_o)[kMaxTrack],
  TrackFitType::BarrelStubWord (&barrelStubWords_o)[kMaxTrack][NBarrelStub],
  TrackFitType::DiskStubWord (&diskStubWords_o)[kMaxTrack][NDiskStub]
  );

#endif