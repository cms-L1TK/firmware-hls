#ifndef TrackletAlgorithm_MatchProcessor_parameters_h
#define TrackletAlgorithm_MatchProcessor_parameters_h

template<int kNBitsBuffer>
static const ap_uint<(1 << (2 * kNBitsBuffer))> nearFullUnit() {
  ap_uint<(1 << (2 * kNBitsBuffer))> lut;
  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> wptr, rptr;
    ap_uint<2 * kNBitsBuffer> address(i);
    (rptr,wptr) = address;
    auto wptr1 = wptr+1;
    auto wptr2 = wptr+2;
    bool result = wptr1==rptr || wptr2==rptr;
    lut[i] = result;
  }
  return lut;
}

template<int kNBitsBuffer>
static const ap_uint<(1 << (2 * kNBitsBuffer))> emptyUnit() {
  ap_uint<(1 << (2 * kNBitsBuffer))> lut;
  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> wptr, rptr;
    ap_uint<2 * kNBitsBuffer> address(i);
    (rptr,wptr) = address;
    bool result = wptr==rptr;
    lut[i] = result;
  }
  return lut;
}

template<int kNBitsBuffer>
static const ap_uint<(1 << (2 * kNBitsBuffer))> geq() {
  ap_uint<(1 << (2 * kNBitsBuffer))> lut;
  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> istub, nstubs;
    ap_uint<2 * kNBitsBuffer> address(i);
    (nstubs,istub) = address;
    bool result = istub+1>=nstubs;
    lut[i] = result;
  }
  return lut;
}

template<int kNBitsBuffer>
static const ap_uint<(1 << kNBitsBuffer)> nextUnit() {
  ap_uint<(1 << kNBitsBuffer)> lut;
  for(int i = 0; i < (1 << kNBitsBuffer); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> ptr(i);
    lut[i] = ptr+1;
  }
  return lut;
}

#endif
