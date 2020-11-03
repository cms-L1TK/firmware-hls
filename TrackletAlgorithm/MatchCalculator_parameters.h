#ifndef TrackletAlgorithm_MatchCalculator_parameters_h
#define TrackletAlgorithm_MatchCalculator_parameters_h

// magic numbers for MC L3PHIC
template<> constexpr uint16_t FMMask<TF::L3, MC::C>() {
  return 0b00001001;
}

#endif
