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

// TrackBuilder top template function
// !!! CURRENTLY ONLY TESTED FOR L1L2 !!!
template<unsigned NFMBarrel, unsigned NFMDisk, unsigned NBarrelStubs, unsigned NDiskStubs>
void TrackBuilder(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    typename TrackFit<NBarrelStubs, NDiskStubs>::TrackWord trackWord[],
    typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord barrelStubWords[][kMaxProc],
    typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord diskStubWords[][kMaxProc]
)
{

  constexpr unsigned NFMPerLayer = (NBarrelStubs > 0) ? (NFMBarrel / NBarrelStubs) : 0;
  constexpr unsigned NFMPerDisk = (NDiskStubs > 0) ? (NFMDisk / NDiskStubs) : 0;

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

  initialize_barrel_indices : for (short i = 0; i < NFMBarrel; i++) {
#pragma HLS unroll
    barrel_mem_index[i] = 0;
    barrel_read_index[i] = 0;
    barrel_write_index[i] = 0;
  }

  initialize_disk_indices : for (short i = 0; i < NFMDisk; i++) {
#pragma HLS unroll
    disk_mem_index[i] = 0;
    disk_read_index[i] = 0;
    disk_write_index[i] = 0;
  }

  IndexType nTracks = 0;

  full_matches : for (unsigned short i = 0; i < kMaxProc; i++) {
#pragma HLS pipeline II=1 rewind

    const ap_uint<1> empty = (i == 0);
    TrackletIDType min_id = kInvalidTrackletID;
    ap_uint<1> barrel_valid[NFMBarrel];
    ap_uint<1> disk_valid[NFMDisk];
#pragma HLS array_partition variable=barrel_valid complete dim=0
#pragma HLS array_partition variable=disk_valid complete dim=0

    // First determine the minimum tracklet ID from the current set of full
    // matches.
    barrel_min_id : for (short j = 0; j < NFMBarrel; j++) {

      const auto &barrel_stub_0 = barrel_fm[j][barrel_read_index[j]];
      const auto &barrel_id_0 = barrel_stub_0.getTrackletID();
      barrel_valid[j] = (!empty && barrel_id_0 != kInvalidTrackletID);

      // Compare the given barrel and disk IDs against each barrel ID.
      barrel_barrel_id_comp : for (short k = 0; k < NFMBarrel; k++) {
        const auto &barrel_stub_1 = barrel_fm[k][barrel_read_index[k]];
        const auto &barrel_id_1 = barrel_stub_1.getTrackletID();
        barrel_valid[j] = (barrel_valid[j] && barrel_id_0 <= barrel_id_1);
      }
      // Compare the given barrel and disk IDs against each disk ID.
      barrel_disk_id_comp : for (short k = 0; k < NFMDisk; k++) {
        const auto &disk_stub_1 = disk_fm[k][disk_read_index[k]];
        const auto &disk_id_1 = disk_stub_1.getTrackletID();
        barrel_valid[j] = (barrel_valid[j] && barrel_id_0 <= disk_id_1);
      }

      min_id = (barrel_valid[j] ? barrel_id_0 : min_id);
    }

    disk_min_id : for (short j = 0; j < NFMDisk; j++) {

      const auto &disk_stub_0 = disk_fm[j][disk_read_index[j]];
      const auto &disk_id_0 = disk_stub_0.getTrackletID();
      disk_valid[j] = (!empty && disk_id_0 != kInvalidTrackletID);

      // Compare the given barrel and disk IDs against each barrel ID.
      disk_barrel_id_comp : for (short k = 0; k < NFMBarrel; k++) {
        const auto &barrel_stub_1 = barrel_fm[k][barrel_read_index[k]];
        const auto &barrel_id_1 = barrel_stub_1.getTrackletID();
        disk_valid[j] = (disk_valid[j] && disk_id_0 <= barrel_id_1);
      }
      // Compare the given barrel and disk IDs against each disk ID.
      disk_disk_id_comp : for (short k = 0; k < NFMDisk; k++) {
        const auto &disk_stub_1 = disk_fm[k][disk_read_index[k]];
        const auto &disk_id_1 = disk_stub_1.getTrackletID();
        disk_valid[j] = (disk_valid[j] && disk_id_0 <= disk_id_1);
      }

      min_id = (disk_valid[j] ? disk_id_0 : min_id);
    }

    // Initialize a TrackFit object using the tracklet parameters associated
    // with the minimum tracklet ID.
    const TCIDType &TCID = (min_id != kInvalidTrackletID) ? (min_id >> kNBits_MemAddr) : TrackletIDType(0);
    TrackFit<NBarrelStubs, NDiskStubs> track(nTracks, TCID >> kNBitsITC);
    const IndexType &trackletIndex = (min_id != kInvalidTrackletID) ? (min_id & TrackletIDType(0x7F)) : TrackletIDType(0);
    const auto &tpar = trackletParameters[TCID].read_mem(bx, trackletIndex);
    track.setRinv(tpar.getRinv());
    track.setPhi0(tpar.getPhi0());
    track.setZ0(tpar.getZ0());
    track.setT(tpar.getT());

    // Retrieve the full information for each full match that has the minimum
    // tracklet ID and assign it to the appropriate field of the TrackFit
    // object.
    ap_uint<3> nMatches = 0; // there can be up to eight matches (3 bits)

    barrel_stub_association : for (short j = 0; j < NBarrelStubs; j++) {

      ap_uint<1> barrel_stub_valid = false;
      barrel_stub_valid : for (short k = 0; k < NFMPerLayer; k++)
        barrel_stub_valid = (barrel_stub_valid || barrel_valid[j * NFMPerLayer + k]);
      nMatches += (barrel_stub_valid ? 1 : 0);

      static_assert(NFMPerLayer <= 8, "Number of FM memories per layer cannot exceed eight.");
      const auto &barrel_stub = ((NFMPerLayer > 7 && barrel_valid[j * NFMPerLayer + 7]) ? barrel_fm[j * NFMPerLayer + 7][barrel_read_index[j * NFMPerLayer + 7]] :
                                ((NFMPerLayer > 6 && barrel_valid[j * NFMPerLayer + 6]) ? barrel_fm[j * NFMPerLayer + 6][barrel_read_index[j * NFMPerLayer + 6]] :
                                ((NFMPerLayer > 5 && barrel_valid[j * NFMPerLayer + 5]) ? barrel_fm[j * NFMPerLayer + 5][barrel_read_index[j * NFMPerLayer + 5]] :
                                ((NFMPerLayer > 4 && barrel_valid[j * NFMPerLayer + 4]) ? barrel_fm[j * NFMPerLayer + 4][barrel_read_index[j * NFMPerLayer + 4]] :
                                ((NFMPerLayer > 3 && barrel_valid[j * NFMPerLayer + 3]) ? barrel_fm[j * NFMPerLayer + 3][barrel_read_index[j * NFMPerLayer + 3]] :
                                ((NFMPerLayer > 2 && barrel_valid[j * NFMPerLayer + 2]) ? barrel_fm[j * NFMPerLayer + 2][barrel_read_index[j * NFMPerLayer + 2]] :
                                ((NFMPerLayer > 1 && barrel_valid[j * NFMPerLayer + 1]) ? barrel_fm[j * NFMPerLayer + 1][barrel_read_index[j * NFMPerLayer + 1]] :
                                                                                          barrel_fm[j * NFMPerLayer][barrel_read_index[j * NFMPerLayer]])))))));

      const auto &barrel_stub_index = (barrel_stub_valid ? barrel_stub.getStubIndex() : FullMatch<BARREL>::FMSTUBINDEX(0));
      const auto &barrel_stub_r = (barrel_stub_valid ? barrel_stub.getStubR() : FullMatch<BARREL>::FMSTUBR(0));
      const auto &barrel_phi_res = (barrel_stub_valid ? barrel_stub.getPhiRes() : FullMatch<BARREL>::FMPHIRES(0));
      const auto &barrel_z_res = (barrel_stub_valid ? barrel_stub.getZRes() : FullMatch<BARREL>::FMZRES(0));

      switch (j) {
        case 0:
          track.template setBarrelStub<0>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 1:
          track.template setBarrelStub<1>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 2:
          track.template setBarrelStub<2>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 3:
          track.template setBarrelStub<3>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 4:
          track.template setBarrelStub<4>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 5:
          track.template setBarrelStub<5>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 6:
          track.template setBarrelStub<6>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
        case 7:
          track.template setBarrelStub<7>(barrel_stub_valid, barrel_stub_index, barrel_stub_r, barrel_phi_res, barrel_z_res);
          break;
      }
    }

    disk_stub_association : for (short j = 0; j < NDiskStubs; j++) {

      ap_uint<1> disk_stub_valid = false;
      disk_stub_valid : for (short k = 0; k < NFMPerDisk; k++)
        disk_stub_valid = (disk_stub_valid || disk_valid[j * NFMPerDisk + k]);
      nMatches += (disk_stub_valid ? 1 : 0);

      static_assert(NFMPerDisk <= 6, "Number of FM memories per disk cannot exceed six.");
      const auto &disk_stub = ((NFMPerDisk > 7 && disk_valid[j * NFMPerDisk + 7]) ? disk_fm[j * NFMPerDisk + 7][disk_read_index[j * NFMPerDisk + 7]] :
                              ((NFMPerDisk > 6 && disk_valid[j * NFMPerDisk + 6]) ? disk_fm[j * NFMPerDisk + 6][disk_read_index[j * NFMPerDisk + 6]] :
                              ((NFMPerDisk > 5 && disk_valid[j * NFMPerDisk + 5]) ? disk_fm[j * NFMPerDisk + 5][disk_read_index[j * NFMPerDisk + 5]] :
                              ((NFMPerDisk > 4 && disk_valid[j * NFMPerDisk + 4]) ? disk_fm[j * NFMPerDisk + 4][disk_read_index[j * NFMPerDisk + 4]] :
                              ((NFMPerDisk > 3 && disk_valid[j * NFMPerDisk + 3]) ? disk_fm[j * NFMPerDisk + 3][disk_read_index[j * NFMPerDisk + 3]] :
                              ((NFMPerDisk > 2 && disk_valid[j * NFMPerDisk + 2]) ? disk_fm[j * NFMPerDisk + 2][disk_read_index[j * NFMPerDisk + 2]] :
                              ((NFMPerDisk > 1 && disk_valid[j * NFMPerDisk + 1]) ? disk_fm[j * NFMPerDisk + 1][disk_read_index[j * NFMPerDisk + 1]] :
                                                                                    disk_fm[j * NFMPerDisk][disk_read_index[j * NFMPerDisk]])))))));

      const auto &disk_stub_index = (disk_stub_valid ? disk_stub.getStubIndex() : FullMatch<DISK>::FMSTUBINDEX(0));
      const auto &disk_stub_r = (disk_stub_valid ? disk_stub.getStubR() : FullMatch<DISK>::FMSTUBR(0));
      const auto &disk_phi_res = (disk_stub_valid ? disk_stub.getPhiRes() : FullMatch<DISK>::FMPHIRES(0));
      const auto &disk_z_res = (disk_stub_valid ? disk_stub.getZRes() : FullMatch<DISK>::FMZRES(0));

      switch (j) {
        case 0:
          track.template setDiskStub<NBarrelStubs>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 1:
          track.template setDiskStub<NBarrelStubs + 1>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 2:
          track.template setDiskStub<NBarrelStubs + 2>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 3:
          track.template setDiskStub<NBarrelStubs + 3>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 4:
          track.template setDiskStub<NBarrelStubs + 4>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 5:
          track.template setDiskStub<NBarrelStubs + 5>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 6:
          track.template setDiskStub<NBarrelStubs + 6>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
        case 7:
          track.template setDiskStub<NBarrelStubs + 7>(disk_stub_valid, disk_stub_index, disk_stub_r, disk_phi_res, disk_z_res);
          break;
      }
    }

    // Only tracks with at least two matches are valid.
    track.setTrackValid(nMatches >= kMinNMatches);

    // Output the track word and eight stub words associated with the TrackFit
    // object that was constructed.
    if (track.getTrackValid()) {
      trackWord[nTracks] = track.getTrackWord();
      barrel_stub_words: for (short j = 0 ; j < NBarrelStubs; j++) {
        switch (j) {
          case 0:
            barrelStubWords[j][nTracks] = track.template getStubValid<0>() ? track.template getBarrelStubWord<0>() : typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord(0);
            break;
          case 1:
            barrelStubWords[j][nTracks] = track.template getStubValid<1>() ? track.template getBarrelStubWord<1>() : typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord(0);
            break;
          case 2:
            barrelStubWords[j][nTracks] = track.template getStubValid<2>() ? track.template getBarrelStubWord<2>() : typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord(0);
            break;
          case 3:
            barrelStubWords[j][nTracks] = track.template getStubValid<3>() ? track.template getBarrelStubWord<3>() : typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord(0);
            break;
        }
      }
      disk_stub_words: for (short j = 0 ; j < NDiskStubs; j++) {
        switch (j) {
          case 0:
            diskStubWords[j][nTracks] = track.template getStubValid<4>() ? track.template getDiskStubWord<4>() : typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord(0);
            break;
          case 1:
            diskStubWords[j][nTracks] = track.template getStubValid<5>() ? track.template getDiskStubWord<5>() : typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord(0);
            break;
          case 2:
            diskStubWords[j][nTracks] = track.template getStubValid<6>() ? track.template getDiskStubWord<6>() : typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord(0);
            break;
          case 3:
            diskStubWords[j][nTracks] = track.template getStubValid<7>() ? track.template getDiskStubWord<7>() : typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord(0);
            break;
        }
      }
    }
    nTracks += (nMatches >= kMinNMatches ? 1 : 0);

    // Update the circular buffer indices and read a new element from each of
    // the input full-match memories.
    barrel_circular_buffer_update : for (short j = 0; j < NFMBarrel; j++) {
      barrel_read_index[j] += (barrel_valid[j] ? 1 : 0);
      const ap_uint<kNBitsTBBuffer> barrel_next_write_index = barrel_write_index[j] + 1;
      const ap_uint<1> barrel_not_full = (barrel_next_write_index != barrel_read_index[j]);
      getFM<BARREL>(bx, barrelFullMatches[j], barrel_mem_index[j], barrel_fm[j][barrel_write_index[j]]);
      barrel_mem_index[j] += ((empty || barrel_not_full) ? 1 : 0);
      barrel_write_index[j] += ((empty || barrel_not_full) ? 1 : 0);
    }

    disk_circular_buffer_update : for (short j = 0; j < NFMDisk; j++) {
      disk_read_index[j] += (disk_valid[j] ? 1 : 0);
      const ap_uint<kNBitsTBBuffer> disk_next_write_index = disk_write_index[j] + 1;
      const ap_uint<1> disk_not_full = (disk_next_write_index != disk_read_index[j]);
      getFM<DISK>(bx, diskFullMatches[j], disk_mem_index[j], disk_fm[j][disk_write_index[j]]);
      disk_mem_index[j] += ((empty || disk_not_full) ? 1 : 0);
      disk_write_index[j] += ((empty || disk_not_full) ? 1 : 0);
    }
  }

  bx_o = bx;
}

#endif
