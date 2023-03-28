#include "TrackMergerTop.h"

void TrackMergerTop(
  const ap_uint<dinSize> din[kMaxTrack],
  ap_uint<doutSize> (&dout)[kMaxTrack]
){

    #pragma HLS inline recursive
    // #pragma HLS stream variable=din
    // #pragma HLS stream variable=dout



    TrackMerger(din, dout);
}