#ifndef TrackletAlgorithm_TrackletProcessor_parameters_h
#define TrackletAlgorithm_TrackletProcessor_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each TrackletProcessor and that come directly from the wiring.
//
// The validity of each of the barrel TPROJ memories is determined by
// TPROJMaskBarrel. The bits of this mask, from least significant to most
// significant, represent the memories in the order they are passed to
// TrackletProcessor; e.g., the LSB corresponds to
// projout_barrel_ps[TC::L1PHIA]. If a bit is set, the corresponding memory is
// valid, if it is not, the corresponding memory is not valid. Likewise, the
// validity of each of the disk TPROJ memories is determined by TPROJMaskDisk
// in the same way.
namespace TC{
  enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
   }
template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskBarrel();
template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskDisk();

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::A>() {
  return 0x3311000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::A>() {
  return 0x3333;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::B>() {
  return 0x3333000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::B>() {
  return 0x3333;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::C>() {
  return 0x3333000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::C>() {
  return 0x3333;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::D>() {
  return 0x7733000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::D>() {
  return 0x7777;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::E>() {
  return 0x7776000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::E>() {
  return 0x7777;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::F>() {
  return 0x7766000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::F>() {
  return 0x7777;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::G>() {
  return 0xEE66000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::G>() {
  return 0xEEEE;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::H>() {
  return 0xEEEE000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::H>() {
  return 0xEEEE;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::I>() {
  return 0xEECC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::I>() {
  return 0xEEEE;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::J>() {
  return 0xCCCC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::J>() {
  return 0xCCCC;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::K>() {
  return 0xCCCC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::K>() {
  return 0xCCCC;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::L>() {
  return 0xCC88000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::L>() {
  return 0xCCCC;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L2L3, TC::A>() {
  return 0x330007;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L2L3, TC::A>() {
  return 0x3333;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L2L3, TC::B>() {
  return 0x77001E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L2L3, TC::B>() {
  return 0x7777;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L2L3, TC::C>() {
  return 0xEE0078;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L2L3, TC::C>() {
  return 0xEEEE;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L2L3, TC::D>() {
  return 0xCC00E0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L2L3, TC::D>() {
  return 0xCCCC;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::A>() {
  return 0x3300307;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::A>() {
  return 0x33;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::B>() {
  return 0x770071E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::B>() {
  return 0x77;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::C>() {
  return 0xEE00E78;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::C>() {
  return 0xEE;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::D>() {
  return 0xCC00CE0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::D>() {
  return 0xCC;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::A>() {
  return 0x3330F;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::A>() {
  return 0x0;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::B>() {
  return 0x7773E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::B>() {
  return 0x0;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::C>() {
  return 0xEEE7C;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::C>() {
  return 0x0;
}

template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::D>() {
  return 0xCCCF0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::D>() {
  return 0x0;
}

#endif
