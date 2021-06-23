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

// magic numbers for TP_L1L2D
template<> constexpr uint32_t TPROJMaskBarrel<TF::L1L2, TC::D>() {
  return 0x7733000;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L1L2, TC::D>() {
  return 0xFFFF;
}

// magic numbers for TP_L2L3C

template<> constexpr uint32_t TPROJMaskBarrel<TF::L2L3, TC::C>() {
  return 0xEE0078;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L2L3, TC::C>() {
  return 0xEEEE;
}
// magic numbers for TP_L3L4C

template<> constexpr uint32_t TPROJMaskBarrel<TF::L3L4, TC::C>() {
  return 0xEE00E78;
}
template<> constexpr uint32_t TPROJMaskDisk<TF::L3L4, TC::C>() {
  return 0xEE;
}


#endif
