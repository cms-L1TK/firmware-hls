#include "TrackMergerTop.h"

void TrackMergerTop(
  const ap_uint<trackWordSize> trackWord[kMaxTrack],
  const ap_uint<stubWordSize> stubWords[kMaxTrack][NStub],
  ap_uint<trackWordSize> (&trackWord_o)[kMaxTrack],
  ap_uint<stubWordSize> (&stubWords_o)[kMaxTrack][NStub]
  ){
    #pragma HLS inline recursive
    #pragma HLS stream variable=trackWord
    #pragma HLS stream variable=stubWords
    #pragma HLS stream variable=trackWord_o
    #pragma HLS stream variable=stubWords_o


    TrackMerger(trackWord,
                stubWords,
                trackWord_o,
                stubWords_o);
}