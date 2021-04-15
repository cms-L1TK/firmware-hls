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
  return 0x3333000;
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
  return 0x7333000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::B>() {
  return 0x7777;
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
  return 0x7733000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::C>() {
  return 0x7777;
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
  return 0x8;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::D>() {
  return 0x7777000;
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
  return 0xF777000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::E>() {
  return 0xFFFF;
}

// magic numbers for TC_L1L2F
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::F>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::F>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::F>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::F>() {
  return 0x1000;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::F>() {
  return 0xC40;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::F>() {
  return 0xFF66000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::F>() {
  return 0xFFFF;
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
  return 0x1FEE;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::G>() {
  return 0xFEE6000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::G>() {
  return 0xFFFF;
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
  return 0x1FC0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::H>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::H>() {
  return 0xEEEE000;
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
  return 0x1880;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::I>() {
  return 0xEECC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::I>() {
  return 0xEEEE;
}

// magic numbers for TC_L1L2J
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::J>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::J>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::J>() {
  return 13;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::J>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::J>() {
  return 0x1FDC;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::J>() {
  return 0xECCC000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::J>() {
  return 0xEEEE;
}

// magic numbers for TC_L1L2K
template<> constexpr uint8_t NASMemInner<TF::L1L2, TC::K>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L1L2, TC::K>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L1L2, TC::K>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L1L2, TC::K>() {
  return 0xF80;
}
template<> constexpr uint32_t ASOuterMask<TF::L1L2, TC::K>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::K>() {
  return 0xCCCC000;
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
  return 0xCCC8000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::L>() {
  return 0xCCCC;
}

// magic numbers for TC_L3L4A
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::A>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::A>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::A>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::A>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::A>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::A>() {
  return 0x330030E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::A>() {
  return 0x33;
}

// magic numbers for TC_L3L4B
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::B>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::B>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::B>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::B>() {
  return 0xC00;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::B>() {
  return 0x300;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::B>() {
  return 0x730031E;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::B>() {
  return 0x77;
}

// magic numbers for TC_L3L4C
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::C>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::C>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::C>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::C>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::C>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::C>() {
  return 0x770063C;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::C>() {
  return 0x77;
}

// magic numbers for TC_L3L4D
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::D>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::D>() {
  return 12;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::D>() {
  return 0xC00;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::D>() {
  return 0x300;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::D>() {
  return 0xF600678;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::D>() {
  return 0xFF;
}

// magic numbers for TC_L3L4E
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::E>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::E>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::E>() {
  return 11;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::E>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::E>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::E>() {
  return 0xEE00CF0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::E>() {
  return 0xEE;
}

// magic numbers for TC_L3L4F
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::F>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::F>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::F>() {
  return 11;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::F>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::F>() {
  return 0x600;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::F>() {
  return 0xEC00CE0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::F>() {
  return 0xEE;
}

// magic numbers for TC_L3L4G
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::G>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::G>() {
  return 2;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::G>() {
  return 11;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::G>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::G>() {
  return 0x7FC;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::G>() {
  return 0xCC008C0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::G>() {
  return 0xCC;
}

// magic numbers for TC_L3L4H
template<> constexpr uint8_t NASMemInner<TF::L3L4, TC::H>() {
  return 1;
}
template<> constexpr uint8_t NASMemOuter<TF::L3L4, TC::H>() {
  return 1;
}
template<> constexpr uint8_t NSPMem<TF::L3L4, TC::H>() {
  return 11;
}
template<> constexpr uint32_t ASInnerMask<TF::L3L4, TC::H>() {
  return 0x0;
}
template<> constexpr uint32_t ASOuterMask<TF::L3L4, TC::H>() {
  return 0x0;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::H>() {
  return 0xC8008C0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::H>() {
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
  return 0x3771E;
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
  return 0x41C;
}
template<> constexpr uint32_t TPROJMaskBarrel<TF::L5L6, TC::D>() {
  return 0xCCCE0;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L5L6, TC::D>() {
  return 0x0;
}

#endif
