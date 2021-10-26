#ifndef TrackAlgorithm_MatchProcessor_parameters_h
#define TrackAlgorithm_MatchProcessor_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each MatchProcessor and that come directly from the wiring.
//
// The validity of each of the barrel CM memories is determined by
// FMMask. The bits of this mask, from least significant to most
// significant, represent the memories in the order they are passed to
// MatchProcessor; e.g., the LSB corresponds to
// TF::L1L2. If a bit is set, the corresponding memory is
// valid, if it is not, the corresponding memory is not valid.

// magic numbers for MP_L3PHIB
template<> constexpr uint32_t FMMask<TF::L3, MC::B>() {
  return 0x9;
}

// magic numbers for MP_L3PHIC
template<> constexpr uint32_t FMMask<TF::L3, MC::C>() {
  return 0x9;
}

// magic numbers for MP_L4PHIB
template<> constexpr uint32_t FMMask<TF::L4, MC::B>() {
  return 0xB;
}

// magic numbers for MP_L5PHIB
template<> constexpr uint32_t FMMask<TF::L5, MC::B>() {
  return 0x7;
}

// magic numbers for MP_L6PHIB
template<> constexpr uint32_t FMMask<TF::L6, MC::B>() {
  return 0x5;
}

// return mask bit AND mask
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {
  return FMMask<Layer, PHI>() & (1<<Seed);
}

template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed>
static const ap_uint<1 << Seed> FMCount() {
  ap_uint<1<<Seed> bits(-1);
  ap_uint<1<<Seed> mask = bits & FMMask<Layer, PHI>();
  int slot = 0;
  for(int i = 0; i < Seed; ++i) {
    slot += mask.range(i,i);
  }
  return slot;
}

#endif
