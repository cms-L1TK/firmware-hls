#ifndef TrackletAlgorithm_TrackBuilder_h
#define TrackletAlgorithm_TrackBuilder_h

#include "TrackletParameterMemory.h"
#include "FullMatchMemory.h"
#include "TrackFitMemory.h"

static const unsigned short kNBitsTBBuffer = 1;
static const unsigned short kMinNMatches = 2;
static const unsigned short kInvalidTrackletID = 0x3FFF;

static const unsigned short kNBitsTCID = FullMatchBase<BARREL>::kFMTCIDSize;
static const unsigned short kNBitsITC = FullMatchBase<BARREL>::kFMITCSize;
static const unsigned short kNBitsTrackletID = kNBitsTCID + kNBits_MemAddr;

typedef ap_uint<kNBitsTCID> TCIDType;
typedef ap_uint<kNBitsITC> ITCType;
typedef ap_uint<kNBits_MemAddr> IndexType;
typedef ap_uint<kNBitsTrackletID> TrackletIDType;

// Function to retrieve a full match and store the associated index and
// tracklet ID in one element of a circular buffer.
template<regionType RegionType> void
getFM(const BXType bx, const FullMatchMemory<RegionType> &fullMatches, const unsigned short i, FullMatch<RegionType> &fm)
{
  if (i < fullMatches.getEntries(bx)) {
    const auto &full_match = fullMatches.read_mem(bx, i);
    fm.setData(full_match.raw());
  }
  else
    // If there are no more full matches, set all data to dummy values.
    fm.setTrackletID(kInvalidTrackletID);
}

template <class FM>
class Merger {

 public:

  // Constructor
  Merger() {}

  void reset() {
    valid_A_ = false;
    valid_B_ = false;
  }

  // Extract the next element in the merger without advancing the merger
  const FM &peek() const {
    return first_A_ ? in_A_ : in_B_;
  }

  // Check if valid data
  bool valid() const {
    return valid_A_ || valid_B_;
  }

  void next(const FM &in_A, const bool valid_A, bool &read_A,
            const FM &in_B, const bool valid_B, bool &read_B,
            const bool read) {

    if (read) {
      if (first_A_) valid_A_ = false;
      else          valid_B_ = false;
    }

    read_A = false;
    read_B = false;

    if (!valid_A_) {
      in_A_    = in_A;
      valid_A_ = valid_A;
      read_A   = true;
    }

    if (!valid_B_) {
      in_B_    = in_B;
      valid_B_ = valid_B;
      read_B   = true;
    }

    first_A_ = (valid_A_ && valid_B_
            && (in_A_.getTrackletID() < in_B_.getTrackletID()))
            || (valid_A_ && (!valid_B_));

  }

 private:

  // valid data flags
  bool valid_A_, valid_B_;

  // flag to indicate if in_A is the next data to read
  bool first_A_;

  // data words
  FM in_A_, in_B_;

};

// TrackBuilder top template function
template<unsigned Seed, int NFMPerStubBarrel0, int NFMPerStubBarrel, int NFMPerStubDisk, int NBarrelStubs, int NDiskStubs, unsigned TPAROffset>
void TrackBuilder(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    typename TrackFit<NBarrelStubs, NDiskStubs>::TrackWord trackWord[],
    typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord barrelStubWords[][kMaxProc],
    typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord diskStubWords[][kMaxProc],
    bool &done
)
{

  constexpr int NFMBarrel = NFMPerStubBarrel0 + (NBarrelStubs - 1) * NFMPerStubBarrel;
  constexpr int NFMDisk = NDiskStubs * NFMPerStubDisk;

  // Circular buffers for each of the input full-match memories.
  FullMatch<BARREL> barrel_fm[NFMBarrel][1<<kNBitsTBBuffer];
  FullMatch<DISK> disk_fm[NFMDisk][1<<kNBitsTBBuffer];
#pragma HLS array_partition variable=barrel_fm complete dim=0
#pragma HLS array_partition variable=disk_fm complete dim=0

  // Read and write indices for the circular buffers.
  ap_uint<kNBits_MemAddr> barrel_mem_index[NFMBarrel];
  ap_uint<kNBits_MemAddr> disk_mem_index[NFMDisk];
  ap_uint<kNBitsTBBuffer> barrel_read_index[NFMBarrel];
  ap_uint<kNBitsTBBuffer> disk_read_index[NFMDisk];
  ap_uint<kNBitsTBBuffer> barrel_write_index[NFMBarrel];
  ap_uint<kNBitsTBBuffer> disk_write_index[NFMDisk];
#pragma HLS array_partition variable=barrel_mem_index complete dim=0
#pragma HLS array_partition variable=disk_mem_index complete dim=0
#pragma HLS array_partition variable=barrel_read_index complete dim=0
#pragma HLS array_partition variable=disk_read_index complete dim=0
#pragma HLS array_partition variable=barrel_write_index complete dim=0
#pragma HLS array_partition variable=disk_write_index complete dim=0

  initialize_barrel_indices : for (short i = 0; NFMBarrel > 0 && i < NFMBarrel; i++) { // Note: need to have NFMBarrel > 0 to prevent compilation error due to -Werror=type-limits flag in CMSSW
#pragma HLS unroll
    barrel_mem_index[i] = 0;
    barrel_read_index[i] = 0;
    barrel_write_index[i] = 0;
  }

  initialize_disk_indices : for (short i = 0; NFMDisk > 0 && i < NFMDisk; i++) { // Note: need to have NFMDisk > 0 to prevent compilation error due to -Werror=type-limits flag in CMSSW
#pragma HLS unroll
    disk_mem_index[i] = 0;
    disk_read_index[i] = 0;
    disk_write_index[i] = 0;
  }

  IndexType nTracks = 0;
  done = false;
  bool done_latch = false;

  Merger<FullMatch<BARREL> > merger_L_top[4], merger_L_b1[4], merger_L_b2[4];
  int count_L_0[4], count_L_1[4], count_L_2[4], count_L_3[4];

  initialize_barrel_mergers : for (short i = 0; i < 4; i++) {
#pragma HLS unroll
    merger_L_top[i].reset();
    merger_L_b1[i].reset();
    merger_L_b2[i].reset();
    count_L_0[i] = count_L_1[i] = count_L_2[i] = count_L_3[i] = 0;
  }

  Merger<FullMatch<DISK> > merger_D_top[4], merger_D_b1[4], merger_D_b2[4];
  int count_D_0[4], count_D_1[4], count_D_2[4], count_D_3[4];

  initialize_disk_mergers : for (short i = 0; i < 4; i++) {
#pragma HLS unroll
    merger_D_top[i].reset();
    merger_D_b1[i].reset();
    merger_D_b2[i].reset();
    count_D_0[i] = count_D_1[i] = count_D_2[i] = count_D_3[i] = 0;
  }

  full_matches : for (unsigned short i = 0; i < kMaxProc; i++) {
#pragma HLS pipeline II=1 rewind
#pragma HLS latency min=4 max=4

    const ap_uint<1> empty = (i == 0);
    TrackletIDType min_id = kInvalidTrackletID;
    ap_uint<1> barrel_valid[NFMBarrel];
    ap_uint<1> disk_valid[NFMDisk];
#pragma HLS array_partition variable=barrel_valid complete dim=0
#pragma HLS array_partition variable=disk_valid complete dim=0

    bool smallest[8];

    for (unsigned int ii = 0 ; ii < 8; ii++) {

      int tid = kInvalidTrackletID;

      if (ii < 4) {
        if (merger_L_top[ii].valid())
          tid =  merger_L_top[ii].peek().getTrackletID();
      } else {
        if (merger_D_top[ii-4].valid())
          tid =  merger_D_top[ii-4].peek().getTrackletID();
      }

      smallest[ii] = true;

      for (unsigned int jj = 0 ; jj < 8; jj++) {

        int tid2 = kInvalidTrackletID;

        if (jj < 4) {
          if (merger_L_top[jj].valid())
            tid2 =  merger_L_top[jj].peek().getTrackletID();
        } else {
          if (merger_D_top[jj-4].valid())
            tid2 =  merger_D_top[jj-4].peek().getTrackletID();
        }

        if (tid2 < tid) smallest[ii] = false;
      }

      if (smallest[ii]) min_id = tid;
    }

    // We are done if no valid ID was found; all subsequent output tracks are
    // invalid
    done = !done_latch && !empty && (min_id == kInvalidTrackletID);
    done_latch = !empty && (min_id == kInvalidTrackletID);

    // Initialize a TrackFit object using the tracklet parameters associated
    // with the minimum tracklet ID.
    const TCIDType &TCID = (min_id != kInvalidTrackletID) ? (min_id >> kNBits_MemAddr) : TrackletIDType(TPAROffset);
    const ITCType &iTC = TCID.range(kNBitsITC - 1, 0);
    const typename TrackFit<NBarrelStubs, NDiskStubs>::TFPHIREGION phiRegionOuter = iTC / (Seed == TF::L1L2 ? 3 : (Seed == TF::L1D1 ? 2 : 1));
    const IndexType &trackletIndex = (min_id != kInvalidTrackletID) ? (min_id & TrackletIDType(0x7F)) : TrackletIDType(0);
    const auto &tpar = trackletParameters[TCID - TPAROffset].read_mem(bx, trackletIndex);

    TrackFit<NBarrelStubs, NDiskStubs> track(typename TrackFit<NBarrelStubs, NDiskStubs>::TFSEEDTYPE(TCID >> kNBitsITC));
    track.setPhiRegionInner(tpar.getPhiRegion());
    track.setPhiRegionOuter(phiRegionOuter);
    track.setStubIndexInner(tpar.getStubIndexInner());
    track.setStubIndexOuter(tpar.getStubIndexOuter());
    track.setRinv(tpar.getRinv());
    track.setPhi0(tpar.getPhi0());
    track.setZ0(tpar.getZ0());
    track.setT(tpar.getT());

    // Retrieve the full information for each full match that has the minimum
    // tracklet ID and assign it to the appropriate field of the TrackFit
    // object.
    ap_uint<3> nMatches = 0; // there can be up to eight matches (3 bits)

    barrel_stub_association : for (short j = 0; j < NBarrelStubs; j++) {

      const auto &barrel_stub = merger_L_top[j].peek();
      const bool barrel_stub_valid = merger_L_top[j].valid() && smallest[j];
      if (barrel_stub_valid) nMatches++;

      const auto &barrel_stub_index = (barrel_stub_valid ? barrel_stub.getStubIndex() : FullMatch<BARREL>::FMSTUBINDEX(0));
      const auto &barrel_stub_r = (barrel_stub_valid ? barrel_stub.getStubR() : FullMatch<BARREL>::FMSTUBR(0));
      const auto &barrel_phi_res = (barrel_stub_valid ? barrel_stub.getPhiRes() : FullMatch<BARREL>::FMPHIRES(0));
      const auto &barrel_z_res = (barrel_stub_valid ? barrel_stub.getZRes() : FullMatch<BARREL>::FMZRES(0));

      switch (j) {
        case 0:
          track.template setBarrelStub<0>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<0>(nTracks);
          break;
        case 1:
          track.template setBarrelStub<1>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<1>(nTracks);
          break;
        case 2:
          track.template setBarrelStub<2>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<2>(nTracks);
          break;
        case 3:
          track.template setBarrelStub<3>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<3>(nTracks);
          break;
        case 4:
          track.template setBarrelStub<4>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<4>(nTracks);
          break;
        case 5:
          track.template setBarrelStub<5>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<5>(nTracks);
          break;
        case 6:
          track.template setBarrelStub<6>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<6>(nTracks);
          break;
        case 7:
          track.template setBarrelStub<7>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          track.template setTrackIndex<7>(nTracks);
          break;
      }
    }

    disk_stub_association : for (short j = 0; j < NDiskStubs; j++) {

      const auto &disk_stub = merger_D_top[j].peek();
      const bool disk_stub_valid = merger_D_top[j].valid() && smallest[j+4];
      if (disk_stub_valid) nMatches++;

      const auto &disk_stub_index = (disk_stub_valid ? disk_stub.getStubIndex() : FullMatch<DISK>::FMSTUBINDEX(0));
      const auto &disk_stub_r = (disk_stub_valid ? disk_stub.getStubR() : FullMatch<DISK>::FMSTUBR(0));
      const auto &disk_phi_res = (disk_stub_valid ? disk_stub.getPhiRes() : FullMatch<DISK>::FMPHIRES(0));
      const auto &disk_z_res = (disk_stub_valid ? disk_stub.getZRes() : FullMatch<DISK>::FMZRES(0));

      switch (j) {
        case 0:
          track.template setDiskStub<NBarrelStubs>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs>(nTracks);
          break;
        case 1:
          track.template setDiskStub<NBarrelStubs + 1>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 1>(nTracks);
          break;
        case 2:
          track.template setDiskStub<NBarrelStubs + 2>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 2>(nTracks);
          break;
        case 3:
          track.template setDiskStub<NBarrelStubs + 3>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 3>(nTracks);
          break;
        case 4:
          track.template setDiskStub<NBarrelStubs + 4>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 4>(nTracks);
          break;
        case 5:
          track.template setDiskStub<NBarrelStubs + 5>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 5>(nTracks);
          break;
        case 6:
          track.template setDiskStub<NBarrelStubs + 6>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 6>(nTracks);
          break;
        case 7:
          track.template setDiskStub<NBarrelStubs + 7>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          track.template setTrackIndex<NBarrelStubs + 7>(nTracks);
          break;
      }
    }

    // Only tracks with at least two matches are valid.
    track.setTrackValid(!done && (nMatches >= kMinNMatches));

    // Output the track word and eight stub words associated with the TrackFit
    // object that was constructed.
    trackWord[nTracks] = track.getTrackWord();
    barrel_stub_words: for (short j = 0 ; NBarrelStubs > 0 && j < NBarrelStubs; j++) { // Note: need to have NBarrelStubs > 0 to prevent compilation error due to -Werror=type-limits flag in CMSSW
      switch (j) {
        case 0:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<0>();
          break;
        case 1:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<1>();
          break;
        case 2:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<2>();
          break;
        case 3:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<3>();
          break;
      }
    }
    disk_stub_words: for (short j = 0 ; NDiskStubs > 0 && j < NDiskStubs; j++) { // Note: need to have NDiskStubs > 0 to prevent compilation error due to -Werror=type-limits flag in CMSSW
      switch (j) {
        case 0:
          diskStubWords[j][nTracks] = track.template getDiskStubWord<NBarrelStubs>();
          break;
        case 1:
          diskStubWords[j][nTracks] = track.template getDiskStubWord<NBarrelStubs + 1>();
          break;
        case 2:
          diskStubWords[j][nTracks] = track.template getDiskStubWord<NBarrelStubs + 2>();
          break;
        case 3:
          diskStubWords[j][nTracks] = track.template getDiskStubWord<NBarrelStubs + 3>();
          break;
      }
    }
    nTracks += (track.getTrackValid() ? 1 : 0);

    //Next step

    barrel_merger : for (unsigned short ii = 0; ii < 4; ii++) {

      bool read_1, read_2;

      merger_L_top[ii].next(merger_L_b1[ii].peek(), merger_L_b1[ii].valid(), read_1,
                            merger_L_b2[ii].peek(), merger_L_b2[ii].valid(), read_2,
                            smallest[ii]);

      bool read_b1_1, read_b1_2, read_b2_1, read_b2_2;

      merger_L_b1[ii].next(barrelFullMatches[0+4*ii].read_mem(bx,count_L_0[ii]),
                           count_L_0[ii] < barrelFullMatches[0+4*ii].getEntries(bx),
                           read_b1_1,
                           barrelFullMatches[1+ii*4].read_mem(bx,count_L_1[ii]),
                           count_L_1[ii] < barrelFullMatches[1+ii*4].getEntries(bx),
                           read_b1_2,
                           read_1);

      if (read_b1_1) count_L_0[ii]++;
      if (read_b1_2) count_L_1[ii]++;

      merger_L_b2[ii].next(barrelFullMatches[2+ii*4].read_mem(bx,count_L_2[ii]),
                           count_L_2[ii] < barrelFullMatches[2+ii*4].getEntries(bx),
                           read_b2_1,
                           barrelFullMatches[3+ii*4].read_mem(bx,count_L_3[ii]),
                           count_L_3[ii] < barrelFullMatches[3+ii*4].getEntries(bx),
                           read_b2_2,
                           read_2);

      if (read_b2_1) count_L_2[ii]++;
      if (read_b2_2) count_L_3[ii]++;
    }

    disk_merger : for (unsigned int ii = 0 ; ii < 4; ii++) {

      bool read_1, read_2;

      merger_D_top[ii].next(merger_D_b1[ii].peek(), merger_D_b1[ii].valid(), read_1,
                            merger_D_b2[ii].peek(), merger_D_b2[ii].valid(), read_2,
                            smallest[ii+4]);

      bool read_b1_1, read_b1_2, read_b2_1, read_b2_2;

      merger_D_b1[ii].next(diskFullMatches[0+4*ii].read_mem(bx,count_D_0[ii]),
                           count_D_0[ii] < diskFullMatches[0+4*ii].getEntries(bx),
                           read_b1_1,
                           diskFullMatches[1+ii*4].read_mem(bx,count_D_1[ii]),
                           count_D_1[ii] < diskFullMatches[1+ii*4].getEntries(bx),
                           read_b1_2,
                           read_1);

      if (read_b1_1) count_D_0[ii]++;
      if (read_b1_2) count_D_1[ii]++;

      merger_D_b2[ii].next(diskFullMatches[2+ii*4].read_mem(bx,count_D_2[ii]),
                           count_D_2[ii] < diskFullMatches[2+ii*4].getEntries(bx),
                           read_b2_1,
                           diskFullMatches[3+ii*4].read_mem(bx,count_D_3[ii]),
                           count_D_3[ii] < diskFullMatches[3+ii*4].getEntries(bx),
                           read_b2_2,
                           read_2);

      if (read_b2_1) count_D_2[ii]++;
      if (read_b2_2) count_D_3[ii]++;
    }
  }

  bx_o = bx;
  done = !done_latch;
}

#endif
