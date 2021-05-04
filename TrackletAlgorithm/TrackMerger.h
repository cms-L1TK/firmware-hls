#ifndef TrackletAlgorithm_TrackMerger_h
#define TrackletAlgorithm_TrackMerger_h

#include "TrackFitMemory.h"

void TrackMerger(const BXType bx, TrackFit::Trackword trackWord [kMaxProc], TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc], 
TrackFit::DiskStubWord diskStubWords[4][kMaxProc]));

#endif