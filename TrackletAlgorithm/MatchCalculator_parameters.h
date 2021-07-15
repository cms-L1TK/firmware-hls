#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// magic numbers for MC L3PHIC

// masking out all but L1L2 and L5L6 seeding
template<TF::layerDisk Layer, MC::imc PHI> constexpr uint16_t FMMask() {
  return 0b00001001;
}

// return mask bit AND mask
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {
  return FMMask<Layer, PHI>() & (1<<Seed);
}

/*
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr  FMCount() {
  return ~Seed & FMMask<Layer, PHI>() >> Seed;
}
*/
// calculates the fullmatch array slot
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr ap_uint<1<<Seed> FMCount() {
  ap_uint<1<<Seed> bits;
  for(size_t i = 0; i <= Seed; ++i) {
    bits.set(i);
  }
  return __builtin_popcount(bits & FMMask<Layer, PHI>())-1;
}

#endif
