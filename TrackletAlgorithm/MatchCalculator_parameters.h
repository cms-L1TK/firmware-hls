#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each MatchCalculator and that come directly from the wiring.
//
// The validity of each of the barrel CM memories is determined by
// FMMask. The bits of this mask, from least significant to most
// significant, represent the memories in the order they are passed to
// MatchCalculator; e.g., the LSB corresponds to
// TF::L1L2. If a bit is set, the corresponding memory is
// valid, if it is not, the corresponding memory is not valid.

// magic numbers for MC_L1PHIA
template<> constexpr uint32_t FMMask<TF::L1, MC::A>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIB
template<> constexpr uint32_t FMMask<TF::L1, MC::B>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIC
template<> constexpr uint32_t FMMask<TF::L1, MC::C>() {
  return 0xBE;
}

// magic numbers for MC_L1PHID
template<> constexpr uint32_t FMMask<TF::L1, MC::D>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIE
template<> constexpr uint32_t FMMask<TF::L1, MC::E>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIF
template<> constexpr uint32_t FMMask<TF::L1, MC::F>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIG
template<> constexpr uint32_t FMMask<TF::L1, MC::G>() {
  return 0xBE;
}

// magic numbers for MC_L1PHIH
template<> constexpr uint32_t FMMask<TF::L1, MC::H>() {
  return 0xBE;
}

// magic numbers for MC_L2PHIA
template<> constexpr uint32_t FMMask<TF::L2, MC::A>() {
  return 0x1C;
}

// magic numbers for MC_L2PHIB
template<> constexpr uint32_t FMMask<TF::L2, MC::B>() {
  return 0x1C;
}

// magic numbers for MC_L2PHIC
template<> constexpr uint32_t FMMask<TF::L2, MC::C>() {
  return 0x1C;
}

// magic numbers for MC_L2PHID
template<> constexpr uint32_t FMMask<TF::L2, MC::D>() {
  return 0x1C;
}

// magic numbers for MC_L3PHIA
template<> constexpr uint32_t FMMask<TF::L3, MC::A>() {
  return 0x9;
}

// magic numbers for MC_L3PHIB
template<> constexpr uint32_t FMMask<TF::L3, MC::B>() {
  return 0x9;
}

// magic numbers for MC_L3PHIC
template<> constexpr uint32_t FMMask<TF::L3, MC::C>() {
  return 0x9;
}

// magic numbers for MC_L3PHID
template<> constexpr uint32_t FMMask<TF::L3, MC::D>() {
  return 0x9;
}

// magic numbers for MC_L4PHIA
template<> constexpr uint32_t FMMask<TF::L4, MC::A>() {
  return 0xB;
}

// magic numbers for MC_L4PHIB
template<> constexpr uint32_t FMMask<TF::L4, MC::B>() {
  return 0xB;
}

// magic numbers for MC_L4PHIC
template<> constexpr uint32_t FMMask<TF::L4, MC::C>() {
  return 0xB;
}

// magic numbers for MC_L4PHID
template<> constexpr uint32_t FMMask<TF::L4, MC::D>() {
  return 0xB;
}

// magic numbers for MC_L5PHIA
template<> constexpr uint32_t FMMask<TF::L5, MC::A>() {
  return 0x7;
}

// magic numbers for MC_L5PHIB
template<> constexpr uint32_t FMMask<TF::L5, MC::B>() {
  return 0x7;
}

// magic numbers for MC_L5PHIC
template<> constexpr uint32_t FMMask<TF::L5, MC::C>() {
  return 0x7;
}

// magic numbers for MC_L5PHID
template<> constexpr uint32_t FMMask<TF::L5, MC::D>() {
  return 0x7;
}

// magic numbers for MC_L6PHIA
template<> constexpr uint32_t FMMask<TF::L6, MC::A>() {
  return 0x5;
}

// magic numbers for MC_L6PHIB
template<> constexpr uint32_t FMMask<TF::L6, MC::B>() {
  return 0x5;
}

// magic numbers for MC_L6PHIC
template<> constexpr uint32_t FMMask<TF::L6, MC::C>() {
  return 0x5;
}

// magic numbers for MC_L6PHID
template<> constexpr uint32_t FMMask<TF::L6, MC::D>() {
  return 0x5;
}

// return mask bit AND mask
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {
  return FMMask<Layer, PHI>() & (1<<Seed);
}

template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed>
static const ap_uint<1 << Seed> FMCount() {
  ap_uint<1<<Seed> bits(-1);
  return __builtin_popcount(bits & FMMask<Layer, PHI>())-1;
}

#endif
