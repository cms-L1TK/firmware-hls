#ifndef TrackletAlgorithm_TrackMergerTop_h
#define TrackletAlgorithm_TrackMergerTop_h

#include "../TrackletAlgorithm/TrackMerger.h"

void TrackMergerTop(
  const ap_uint<trackWordSize> trackWord[kMaxTrack],
  const ap_uint<stubWordSize> stubWords[kMaxTrack][NStub],
  ap_uint<trackWordSize> (&trackWord_o)[kMaxTrack],
  ap_uint<stubWordSize> (&stubWords_o)[kMaxTrack][NStub]
  );

#endif