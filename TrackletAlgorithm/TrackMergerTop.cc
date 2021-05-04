#include "TrackMergerTop.h"

void TrackMergerTop(const BXType bx, TrackFit::Trackword trackWord [kMaxProc], TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc], 
TrackFit::DiskStubWord diskStubWords[4][kMaxProc])){
    TrackMerger(bx, inputTracks, outputTracks);
}
