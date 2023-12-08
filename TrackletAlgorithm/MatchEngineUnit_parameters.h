#ifndef TrackAlgorithm_MatchEngineUnit_parameters_h
#define TrackAlgorithm_MatchEngineUnit_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each MEU and that come directly from the wiring.
//

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
static bool nearFullUnitBool(ap_uint<kNBitsBuffer> rptr, ap_uint<kNBitsBuffer> wptr) {
  auto wptr1 = wptr+1;
  auto wptr2 = wptr+2;
  return wptr1==rptr || wptr2==rptr;
}

template<int kNBitsBuffer>
static const ap_uint<(1 << (2 * kNBitsBuffer))> nearFull3Unit() {
  ap_uint<(1 << (2 * kNBitsBuffer))> lut;
  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> wptr, rptr;
    ap_uint<2 * kNBitsBuffer> address(i);
    (rptr,wptr) = address;
    ap_uint<kNBitsBuffer> wptr1 = wptr+1;
    ap_uint<kNBitsBuffer> wptr2 = wptr+2;
    ap_uint<kNBitsBuffer> wptr3 = wptr+3;
    bool result = wptr1==rptr || wptr2==rptr || wptr3==rptr;
    lut[i] = result;
  }
  return lut;
}

template<int kNBitsBuffer>
static bool nearFull3UnitBool(ap_uint<kNBitsBuffer> rptr, ap_uint<kNBitsBuffer> wptr) {
  ap_uint<kNBitsBuffer> wptr1 = wptr+1;
  ap_uint<kNBitsBuffer> wptr2 = wptr+2;
  ap_uint<kNBitsBuffer> wptr3 = wptr+3;
  return wptr1==rptr || wptr2==rptr || wptr3==rptr;
}

template<int kNBitsBuffer>
static const ap_uint<(1 << (2 * kNBitsBuffer))> nearFull4Unit() {
  ap_uint<(1 << (2 * kNBitsBuffer))> lut;
  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
#pragma HLS unroll
    ap_uint<kNBitsBuffer> wptr, rptr;
    ap_uint<2 * kNBitsBuffer> address(i);
    (rptr,wptr) = address;
    ap_uint<kNBitsBuffer> wptr1 = wptr+1;
    ap_uint<kNBitsBuffer> wptr2 = wptr+2;
    ap_uint<kNBitsBuffer> wptr3 = wptr+3;
    ap_uint<kNBitsBuffer> wptr4 = wptr+4;
    bool result = wptr1==rptr || wptr2==rptr || wptr3==rptr || wptr4==rptr;
    lut[i] = result;
  }
  return lut;
}

template<int kNBitsBuffer>
static bool nearFull4UnitBool(ap_uint<kNBitsBuffer> rptr, ap_uint<kNBitsBuffer> wptr) {
  ap_uint<kNBitsBuffer> wptr1 = wptr+1;
  ap_uint<kNBitsBuffer> wptr2 = wptr+2;
  ap_uint<kNBitsBuffer> wptr3 = wptr+3;
  ap_uint<kNBitsBuffer> wptr4 = wptr+4;
  return wptr1==rptr || wptr2==rptr || wptr3==rptr || wptr4==rptr;
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
static bool emptyUnitBool(ap_uint<kNBitsBuffer> wptr, ap_uint<kNBitsBuffer> rptr) {
  //for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {
//#pragma HLS unroll
    return wptr==rptr;
  //}
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

template<int nbits, int max, bool lessThan>
static const ap_uint<1 << nbits> isLessThanSize() {
  ap_uint<1 << nbits> tab(0);
  ap_uint<nbits> Max(max);
  ap_uint<nbits> Min(-max);
  for(int i = 0; i < 1<<nbits; ++i) {
#pragma HLS unroll
    if(lessThan) {
      if(i <= Max || i >= Min) tab[i] = 1;
    }
    else {
      if(i < Max || i > Min) tab[i] = 1;
    }
  }
  return tab;
}

template<int nbits, int max, bool lessThan, int proj, int stub>
static const ap_uint<1 << 2*nbits> isLessThanSize() {
  ap_uint<1 << 2*nbits> tab(0);
  ap_uint<nbits> Max(max);
  ap_uint<nbits> Min(-max);
  for(int i = 0; i < 1<<2*nbits; ++i) {
#pragma HLS unroll
    ap_uint<proj> projphi;
    ap_uint<stub> stubphi;
    ap_uint<proj+stub> address(i);
    (projphi,stubphi) = address;
    ap_uint<nbits> result = projphi - stubphi;
    if(lessThan) {
      if(result <= Max || result >= Min) tab[i] = 1;
    }
    else {
      if(result < Max || result > Min) tab[i] = 1;
    }
  }
  return tab;
}

template<int nbits, int max, bool lessThan, int proj, int stub>
static bool isLessThanSizeBool(ap_uint<nbits> projphi, ap_uint<nbits> stubphi) {
  ap_uint<nbits> Max(max);
  ap_uint<nbits> Min(-max);
  ap_uint<nbits> result = projphi - stubphi;
  //for(int i = 0; i < 1<<2*nbits; ++i) {
//#pragma HLS unroll
    if(lessThan) {
      if(result <= Max || result >= Min) return true;
    }
    else {
      if(result < Max || result > Min) return true;
    }
  //}
  return false;
}
#endif
