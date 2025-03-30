#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "../TrackletAlgorithm/TrackMerger.h"
#include "../TrackletAlgorithm/TrackHandler.h"

void TrackMergerTop(const BXType bx,
		    const TrackFitType::TrackWord trackWord[kMaxTrack],
		    const TrackFitType::BarrelStubWord barrelStubWords[kMaxTrack][trklet::N_LAYER],
		    const TrackFitType::DiskStubWord diskStubWords[kMaxTrack][trklet::N_DISK],
		    BXType bx_o,
		    TrackFitType::TrackWord (&trackWord_o)[kMaxTrack],
		    TrackFitType::BarrelStubWord (&barrelStubWords_o)[kMaxTrack][trklet::N_LAYER],
		    TrackFitType::DiskStubWord (&diskStubWords_o)[kMaxTrack][trklet::N_DISK]
		    );

#endif
