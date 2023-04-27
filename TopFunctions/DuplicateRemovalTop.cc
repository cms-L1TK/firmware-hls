#include "DuplicateRemovalTop.h"

using namespace dr;

void DuplicateRemovalTop(const TrackIn& trackIn, TrackOut& trackOut) {
  #pragma HLS inline recursive
  DuplicateRemoval(trackIn, trackOut);
}