#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "TrackMerger.h"

void TrackMergerTop(const BXType bx, TrackFit::TrackWord trackWord [kMaxProc], TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc], 
TrackFit::DiskStubWord diskStubWords[4][kMaxProc]));

#endif