#ifndef TrackletAlgorithm_TrackletCalculator_parameters_h
#define TrackletAlgorithm_TrackletCalculator_parameters_h

// This file contains numbers of memories and bit masks that are specific to
// each TrackletCalculator and that come directly from the wiring.
//
// The specific inner all-stub memory that the indices in a given stub-pair
// memory correspond to is determined by ASInnerMask. The bits of this mask,
// from least significant to most significant, represent the stub-pair memories
// in the order they are passed to TrackletCalculator; e.g., the LSB
// corresponds to stubPairs[0]. The bit for a given stub-pair memory is the
// index (0 or 1) of the inner all-stub memory that should be used. Likewise,
// the specific outer all-stub memories are determined by ASOuterMask.
//
// The validity of each of the barrel TPROJ memories is determined by
// TPROJMaskBarrel. The bits of this mask, from least significant to most
// significant, represent the memories in the order they are passed to
// TrackletCalculator; e.g., the LSB corresponds to
// projout_barrel_ps[TC::L1PHIA]. If a bit is set, the corresponding memory is
// valid, if it is not, the corresponding memory is not valid. Likewise, the
// validity of each of the disk TPROJ memories is determined by TPROJMaskDisk
// in the same way.

// magic numbers for TC_L1L2A
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::A>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::A>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::A>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::A>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::A>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::A>() {
  return 0x2311000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::A>() {
  return 0x3333;
}

// magic numbers for TC_L1L2B
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::B>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::B>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::B>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::B>() {
  return 0x1FF0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::B>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::B>() {
  return 0x3333000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::B>() {
  return 0x3333;
}

// magic numbers for TC_L1L2C
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::C>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::C>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::C>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::C>() {
  return 0x1800;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::C>() {
  return 0x620;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::C>() {
  return 0x3333000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::C>() {
  return 0x3337;
}

// magic numbers for TC_L1L2D
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::D>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::D>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::D>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::D>() {
  return 0x1FF7;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::D>() {
  return 0x7733000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::D>() {
  return 0x7777;
}

// magic numbers for TC_L1L2E
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::E>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::E>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::E>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::E>() {
  return 0x1FE0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::E>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::E>() {
  return 0x7772000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::E>() {
  return 0x7777;
}

// magic numbers for TC_L1L2F
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::F>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::F>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::F>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::F>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::F>() {
  return 0xC40;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::F>() {
  return 0x7666000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::F>() {
  return 0x777F;
}

// magic numbers for TC_L1L2G
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::G>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::G>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::G>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::G>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::G>() {
  return 0x1FDC;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::G>() {
  return 0xE666000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::G>() {
  return 0xEEEF;
}

// magic numbers for TC_L1L2H
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::H>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::H>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::H>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::H>() {
  return 0x1F80;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::H>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::H>() {
  return 0xEEE4000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::H>() {
  return 0xEEEE;
}

// magic numbers for TC_L1L2I
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::I>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::I>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::I>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::I>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::I>() {
  return 0x1100;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::I>() {
  return 0xEECC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::I>() {
  return 0xEEEE;
}

// magic numbers for TC_L1L2J
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::J>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::J>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::J>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::J>() {
  return 0x1FFE;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::J>() {
  return 0x1FB9;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::J>() {
  return 0xCCCC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::J>() {
  return 0xCCCE;
}

// magic numbers for TC_L1L2K
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::K>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::K>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::K>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::K>() {
  return 0x1F00;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::K>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::K>() {
  return 0xCCC8000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::K>() {
  return 0xCCCC;
}

// magic numbers for TC_L1L2L
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::L>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::L>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::L>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::L>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::L>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::L>() {
  return 0x4C88000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::L>() {
  return 0xCCCC;
}

// magic numbers for TC_L3L4A
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::A>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::A>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::A>() {
  return 23;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::A>() {
  return 0x400000;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::A>() {
  return 0x300000;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::A>() {
  return 0x3300306;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::A>() {
  return 0x33;
}

// magic numbers for TC_L3L4D
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::D>() {
  return 23;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::D>() {
  return 0x7FFFFE;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::D>() {
  return 0x7FFFF9;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::D>() {
  return 0xCC00CE0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::D>() {
  return 0xCC;
}

// magic numbers for TC_L5L6A
template<> constexpr uint8_t NASMemInner<TF::L5L6, TC::A>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L5L6, TC::A>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L5L6, TC::A>() {
  return 30;
}
template<> constexpr uint32_t ASInnerMask<TF::L5L6, TC::A>() {
  return 0x30000000;
}
template<> constexpr uint32_t ASOuterMask<TF::L5L6, TC::A>() {
  return 0xE080000;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::A>() {
  return 0x3330E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::A>() {
  return 0x0;
}

// magic numbers for TC_L5L6D
template<> constexpr uint8_t NASMemInner<TF::L5L6, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L5L6, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L5L6, TC::D>() {
  return 30;
}
template<> constexpr uint32_t ASInnerMask<TF::L5L6, TC::D>() {
  return 0x3FFFFFFC;
}
template<> constexpr uint32_t ASOuterMask<TF::L5L6, TC::D>() {
  return 0x3FFFFBE3;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::D>() {
  return 0xCCCF0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::D>() {
  return 0x0;
}

#endif
