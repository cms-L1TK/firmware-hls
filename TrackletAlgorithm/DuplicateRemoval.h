#ifndef TrackletAlgorithm_DuplicateRemoval_h
#define TrackletAlgorithm_DuplicateRemoval_h

#include "ap_int.h"

namespace dr {

  static constexpr int minSharedStubs = 3;
  static constexpr int numComparisonModules = 16;
  static constexpr int numLayers = 7;

  static constexpr int w_reset = 1;
  static constexpr int w_valid = 1;
  static constexpr int w_cm = 1;
  static constexpr int w_id = 7;

  static constexpr int w_dataStub = 42;
  static constexpr int w_dataTrack = 26;

  // represents incomming stubs
  struct StubIn {
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // stub id
    ap_int<w_id> id_ = 0;
    // data bits (r, phi z, ...)
    ap_int<w_dataStub> data_ = 0;
  };

  // represents stubs stored in comparison modules
  struct Stub {
    // compare with StubIn
    bool operator==(const StubIn& stubIn) const { return valid_ == 1 && stubIn.valid_ == 1 && id_ == stubIn.id_;}
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // stub id
    ap_int<w_id> id_ = 0;
  };

  // represents outgoing stubs
  struct StubOut {
    // convert from StubIn
    void operator=(const StubIn& stubIn) {
      valid_ = stubIn.valid_;
      data_ = stubIn.data_;
    }
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // data bits (r, phi z, ...)
    ap_int<w_dataStub> data_ = 0;
  };

  // represents incomming tracks
  struct TrackIn {
    // default constructor
    TrackIn() : reset_(0), valid_(0), data_(0) {
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = StubIn();
      }
    }
    // reset bit (marks new events)
    ap_uint<w_reset> reset_ = 0;
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // track data (inv2R, phiT, ...)
    ap_int<w_dataTrack> data_ = 0;
    // stubs forming this track
    StubIn stubs_[numLayers];
  };

  // represents intermediate tracks
  struct Track {
    // default constructor
    Track() : cm_(0), reset_(0), valid_(0), data_(0) {
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = StubIn();
      }
    }
    // convert from TrackIn
    void operator=(const TrackIn& trackIn) {
      cm_ = 0;
      reset_ = trackIn.reset_;
      valid_ = trackIn.valid_;
      data_ = trackIn.data_;
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = trackIn.stubs_[i];
      }
    }
    // marks if track is used in a comparion module
    ap_uint<w_cm> cm_ = 0;
    // reset bit (marks new events)
    ap_uint<w_reset> reset_ = 0;
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // track data (inv2R, phiT, ...)
    ap_int<w_dataTrack> data_ = 0;
    // stubs forming this track
    StubIn stubs_[numLayers];
  };

  // represents outgoing tracks
  struct TrackOut {
    // default constructor
    TrackOut() : reset_(0), valid_(0), data_(0) {
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = StubOut();
      }
    }
    // convert from Track
    void operator=(const Track& track) {
      reset_ = track.reset_;
      valid_ = track.valid_;
      data_ = track.data_;
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = track.stubs_[i];
      }
    }
    // reset bit (marks new events)
    ap_uint<w_reset> reset_ = 0;
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // track data (inv2R, phiT, ...)
    ap_int<w_dataTrack> data_ = 0;
    // stubs forming this track
    StubOut stubs_[numLayers];
  };

  // represents tracks stored in comparison modules
  struct CM {
    // default constructor
    CM() : valid_(0) {
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        stubs_[i] = Stub();
      }
    }
    // compare with Track
    bool operator==(const Track& track) const {
      int numSharedStubs(0);
      for (int i = 0; i < numLayers; i++) {
        #pragma HLS unroll
        if (stubs_[i] == track.stubs_[i])
          numSharedStubs++;
      }
      return numSharedStubs >= minSharedStubs;
    }
    // valid bit
    ap_uint<w_valid> valid_ = 0;
    // stubs forming this track
    Stub stubs_[numLayers];
  };

  // possible states inside chain comparison
  enum class State { reset, capture, kill, pass };

  // Duplicate Removal algorithm
  void DuplicateRemoval(const TrackIn& trackIn, TrackOut& trackOut);

}

#endif