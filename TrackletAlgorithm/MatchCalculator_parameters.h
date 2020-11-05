#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// magic numbers for MC L3PHIC
// shift and mask values shouldn't depend on layer/disk and phi sector

// define masks
static const auto mask_L1L2 = 1 << TF::L1L2;
static const auto mask_L2L3 = 1 << TF::L2L3;
static const auto mask_L3L4 = 1 << TF::L3L4;
static const auto mask_L5L6 = 1 << TF::L5L6;
static const auto mask_D1D2 = 1 << TF::D1D2;
static const auto mask_D3D4 = 1 << TF::D3D4;
static const auto mask_L1D1 = 1 << TF::L1D1;
static const auto mask_L2D1 = 1 << TF::L2D1;
 
// masking out all but L1L2 and L5L6 seeding
template<TF::layer Layer, MC::imc PHI> constexpr uint16_t FMMask() {
  return 0b00001001;
}

// return mask bit AND mask
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L1L2>() {
  return FMMask<TF::L3, MC::C>() & mask_L1L2;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L2L3>() {
  return FMMask<TF::L3, MC::C>() & mask_L2L3;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L3L4>() {
  return FMMask<TF::L3, MC::C>() & mask_L3L4;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L5L6>() {
  return FMMask<TF::L3, MC::C>() & mask_L5L6;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::D1D2>() {
  return FMMask<TF::L3, MC::C>() & mask_D1D2;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::D3D4>() {
  return FMMask<TF::L3, MC::C>() & mask_D3D4;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L1D1>() {
  return FMMask<TF::L3, MC::C>() & mask_L1D1;
}
template<> constexpr bool FMMask<TF::L3, MC::C, TF::L2D1>() {
  return FMMask<TF::L3, MC::C>() & mask_L2D1;
}

#endif
