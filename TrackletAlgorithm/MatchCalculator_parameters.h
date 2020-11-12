#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// magic numbers for MC L3PHIC

// masking out all but L1L2 and L5L6 seeding
template<TF::layer Layer, MC::imc PHI> constexpr uint16_t FMMask() {
  return 0b00001001;
}

// return mask bit AND mask
template<TF::layer Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {
  return FMMask<Layer, PHI>() & (1<<Seed);
}

#endif
