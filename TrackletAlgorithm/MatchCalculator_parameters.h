#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// magic numbers for MC L3PHIC
// shift and mask values shouldn't depend on layer/disk and phi sector

// define shifts
static const uint8_t shift_L1L2 = 0;
static const uint8_t shift_L2L3 = shift_L1L2 + 1;
static const uint8_t shift_L3L4 = shift_L2L3 + 1;
static const uint8_t shift_L5L6 = shift_L3L4 + 1;
static const uint8_t shift_D1D2 = shift_L5L6 + 1;
static const uint8_t shift_D3D4 = shift_D1D2 + 1;
static const uint8_t shift_L1D1 = shift_D3D4 + 1;
static const uint8_t shift_L2D1 = shift_L1D1 + 1;

// define masks
static const uint16_t mask_L1L2 = 1 << shift_L1L2;
static const uint16_t mask_L2L3 = 1 << shift_L2L3;
static const uint16_t mask_L3L4 = 1 << shift_L3L4;
static const uint16_t mask_L5L6 = 1 << shift_L5L6;
static const uint16_t mask_D1D2 = 1 << shift_D1D2;
static const uint16_t mask_D3D4 = 1 << shift_D3D4;
static const uint16_t mask_L1D1 = 1 << shift_L1D1;
static const uint16_t mask_L2D1 = 1 << shift_L2D1;
 
// masking out all but L1L2 and L5L6 seeding
template<> constexpr uint16_t FMMask<TF::L3, MC::C>() {
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
