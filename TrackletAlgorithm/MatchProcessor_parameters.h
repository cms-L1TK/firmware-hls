#ifndef TrackletAlgorithm_MatchProcessor_parameters_h
#define TrackletAlgorithm_MatchProcessor_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each MatchProcessor and that come directly from the wiring.
//
// The validity of each of the barrel Tracklet Parameter memories is determined by
// FMMask. The bits of this mask, from least significant to most
// significant, represent the memories in the order they are passed to
// MatchProcessor; e.g., the LSB corresponds to
// TF::L1L2. If a bit is set, the corresponding memory is
// valid, if it is not, the corresponding memory is not valid.

// magic numbers for MP_L1PHIA
template<> constexpr uint32_t FMMask<TF::L1, MC::A>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIB
template<> constexpr uint32_t FMMask<TF::L1, MC::B>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIC
template<> constexpr uint32_t FMMask<TF::L1, MC::C>() {
  return 0xBE;
}

// magic numbers for MP_L1PHID
template<> constexpr uint32_t FMMask<TF::L1, MC::D>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIE
template<> constexpr uint32_t FMMask<TF::L1, MC::E>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIF
template<> constexpr uint32_t FMMask<TF::L1, MC::F>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIG
template<> constexpr uint32_t FMMask<TF::L1, MC::G>() {
  return 0xBE;
}

// magic numbers for MP_L1PHIH
template<> constexpr uint32_t FMMask<TF::L1, MC::H>() {
  return 0xBE;
}

// magic numbers for MP_L2PHIA
template<> constexpr uint32_t FMMask<TF::L2, MC::A>() {
  return 0x1C;
}

// magic numbers for MP_L2PHIB
template<> constexpr uint32_t FMMask<TF::L2, MC::B>() {
  return 0x1C;
}

// magic numbers for MP_L2PHIC
template<> constexpr uint32_t FMMask<TF::L2, MC::C>() {
  return 0x1C;
}

// magic numbers for MP_L2PHID
template<> constexpr uint32_t FMMask<TF::L2, MC::D>() {
  return 0x1C;
}

// magic numbers for MP_L3PHIA
template<> constexpr uint32_t FMMask<TF::L3, MC::A>() {
  return 0x9;
}

// magic numbers for MP_L3PHIB
template<> constexpr uint32_t FMMask<TF::L3, MC::B>() {
  return 0x9;
}

// magic numbers for MP_L3PHIC
template<> constexpr uint32_t FMMask<TF::L3, MC::C>() {
  return 0x9;
}

// magic numbers for MP_L3PHID
template<> constexpr uint32_t FMMask<TF::L3, MC::D>() {
  return 0x9;
}

// magic numbers for MP_L4PHIA
template<> constexpr uint32_t FMMask<TF::L4, MC::A>() {
  return 0xB;
}

// magic numbers for MP_L4PHIB
template<> constexpr uint32_t FMMask<TF::L4, MC::B>() {
  return 0xB;
}

// magic numbers for MP_L4PHIC
template<> constexpr uint32_t FMMask<TF::L4, MC::C>() {
  return 0xB;
}

// magic numbers for MP_L4PHID
template<> constexpr uint32_t FMMask<TF::L4, MC::D>() {
  return 0xB;
}

// magic numbers for MP_L5PHIA
template<> constexpr uint32_t FMMask<TF::L5, MC::A>() {
  return 0x7;
}

// magic numbers for MP_L5PHIB
template<> constexpr uint32_t FMMask<TF::L5, MC::B>() {
  return 0x7;
}

// magic numbers for MP_L5PHIC
template<> constexpr uint32_t FMMask<TF::L5, MC::C>() {
  return 0x7;
}

// magic numbers for MP_L5PHID
template<> constexpr uint32_t FMMask<TF::L5, MC::D>() {
  return 0x7;
}

// magic numbers for MP_L6PHIA
template<> constexpr uint32_t FMMask<TF::L6, MC::A>() {
  return 0x5;
}

// magic numbers for MP_L6PHIB
template<> constexpr uint32_t FMMask<TF::L6, MC::B>() {
  return 0x5;
}

// magic numbers for MP_L6PHIC
template<> constexpr uint32_t FMMask<TF::L6, MC::C>() {
  return 0x5;
}

// magic numbers for MP_L6PHID
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
  ap_uint<1<<Seed> mask = bits & FMMask<Layer, PHI>();
  int slot = 0;
  for(int i = 0; i < Seed; ++i) {
    slot += mask.range(i,i);
  }
  return slot;
}

#endif
