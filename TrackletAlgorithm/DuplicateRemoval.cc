#include "DuplicateRemoval.h"

namespace dr {

  // Duplicate Removal algorithm
  void DuplicateRemoval(const TrackIn& trackIn, TrackOut& trackOut) {
    // comparison modules
    static CM cms[numComparisonModules];
    // shift registers
    static Track srs[numComparisonModules + 1];
    // tracks entering
    srs[numComparisonModules] = trackIn;
    // chain propagation and comaprisons
    for (int i = 0; i < numComparisonModules; i++) {
      #pragma HLS unroll
      const Track& next = srs[i + 1];
      Track& sr = srs[i];
      CM& cm = cms[i];
      // compare shift register with comparison module
      State state = State::pass;
      if (next.reset_ == 1) // new event, clear comparison module
        state = State::reset;
      else if (next.valid_ == 1 && next.cm_ == 0) { // valid unused track
        if (cm.valid_ == 0) // empty comparison module
          state = State::capture;
        else if (cm == next) // compare track with comparison module
          state = State::kill;
      }
      // reset bit shifts anyway
      sr.reset_ = next.reset_;
      // invalidate dupliactes
      sr.valid_ = (state == State::kill) ? ap_uint<w_valid>(0) : next.valid_;
      sr.data_ = (state == State::kill) ? ap_int<w_dataTrack>(0) : next.data_;
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        sr.stubs_[i].valid_ = (state == State::kill) ? ap_uint<w_valid>(0) : next.stubs_[i].valid_;
        sr.stubs_[i].id_ = (state == State::kill) ? ap_int<w_id>(0) : next.stubs_[i].id_;
        sr.stubs_[i].data_ = (state == State::kill) ? ap_int<w_dataStub>(0) : next.stubs_[i].data_;
      }
      // mark tracks stored in a cm
      sr.cm_ = (state == State::capture) ? ap_uint<w_valid>(1) : next.cm_;
      // store track in cm or let in unchanged
      cm.valid_ = (state == State::reset || state == State::capture) ? next.valid_ : cm.valid_;
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        cm.stubs_[i].valid_ = (state == State::reset || state == State::capture) ? next.stubs_[i].valid_ : cm.stubs_[i].valid_;
        cm.stubs_[i].id_ = (state == State::reset || state == State::capture) ? next.stubs_[i].id_ : cm.stubs_[i].id_;
      }
    }
    // tracks leaving
    trackOut = srs[0];
  }

}