#include "DuplicateRemovalTop.h"

using namespace dr;

void DuplicateRemovalTop(const TrackIn& tracksn, TrackOut& trackOut) {
  #pragma HLS inline recursive
  DuplicateRemoval(tracksIn, tracksOut);
}