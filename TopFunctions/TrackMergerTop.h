#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "../TrackletAlgorithm/TrackMerger.h"

void TrackMergerTop(
  const ap_uint<dinSize> din[kMaxTrack],
  ap_uint<doutSize> (&dout)[kMaxTrack]
);

#endif