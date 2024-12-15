#ifndef TrackletAlgorithm_TrackBuilder_h
#define TrackletAlgorithm_TrackBuilder_h

#include "TrackletParameterMemory.h"
#include "FullMatchMemory.h"
#include "TrackFitMemory.h"
#include "TrackBuilder_parameters.h"

static const unsigned short kMinNMatches = 2;
static const unsigned short kInvalidTrackletID = 0x3FFF;

static const unsigned short kNBitsTCID = FullMatchBase<BARREL>::kFMTCIDSize;
static const unsigned short kNBitsTrackletID = kNBitsTCID + kNBits_MemAddr;

//First clock at which we allow to find a match. This allows the mergers of both depth 2 and 3
//to have the results
constexpr unsigned int min_istep = 6;

typedef ap_uint<kNBitsTCID> TCIDType;
typedef ap_uint<kNBitsITC> ITCType;
typedef ap_uint<kNBits_MemAddr> IndexType;
typedef ap_uint<kNBitsTrackletID> TrackletIDType;

template<int NBarrelStubs, int NDiskStubs> void
setTrackPars(TrackFit<NBarrelStubs, NDiskStubs> &track, const TrackletParameters &tpar)
{
  track.setPhiRegionInner(tpar.getPhiRegion());
  track.setStubIndexInner(tpar.getStubIndexInner());
  track.setStubIndexOuter(tpar.getStubIndexOuter());
  track.setRinv(tpar.getRinv());
  track.setPhi0(tpar.getPhi0());
  track.setZ0(tpar.getZ0());
  track.setT(tpar.getT());
}

template <class FM>
class Merger {

 public:

  // Constructor
  Merger() {}

  void reset() {
    valid_A_ = false;
    valid_B_ = false;
    valid_ = false;
  }

  // Extract the next element in the merger without advancing the merger
  const FM &peek() const {
    return out_;
  }

  // Check if valid data
  bool valid() const {
    return valid_;
  }

  void next(const FM &in_A, const bool valid_A, bool &read_A,
            const FM &in_B, const bool valid_B, bool &read_B,
            const bool read) {

    if (read or !valid_) {
      out_ = first_A_ ? in_A_ : in_B_;
      valid_ = valid_A_ || valid_B_;
      if (first_A_) valid_A_ = false;
      else          valid_B_ = false;
    }

    read_A = false;
    read_B = false;

    if (!valid_A_) {
      in_A_    = in_A;
      valid_A_ = valid_A;
      read_A   = valid_A;
    }

    if (!valid_B_) {
      in_B_    = in_B;
      valid_B_ = valid_B;
      read_B   = valid_B;
    }

    first_A_ = (valid_A_ && valid_B_
            && (in_A_.getTrackletID() < in_B_.getTrackletID()))
            || (valid_A_ && (!valid_B_));

  }

 private:

  // valid data flags
  bool valid_, valid_A_, valid_B_;

  // flag to indicate if in_A is the next data to read
  bool first_A_;

  // data words
  FM in_A_, in_B_;
  FM out_;

};

// TrackBuilder top template function
// NFMPerStubBarrel/Disk uses 3 bits for each layer and disk
//
template<TF::seed Seed, int NFMPerStubBarrel, int NFMPerStubDisk, int NBarrelStubs, int NDiskStubs, int TPARMask>
void TrackBuilder(
    const BXType bx,
    const TrackletParameterMemory1 trackletParameters1[],
    const TrackletParameterMemory2 trackletParameters2[],
    const TrackletParameterMemory3 trackletParameters3[],
    const TrackletParameterMemory4 trackletParameters4[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    typename TrackFit<NBarrelStubs, NDiskStubs>::TrackWord trackWord[],
    typename TrackFit<NBarrelStubs, NDiskStubs>::BarrelStubWord barrelStubWords[][kMaxProc],
    typename TrackFit<NBarrelStubs, NDiskStubs>::DiskStubWord diskStubWords[][kMaxProc],
    bool &done
)
{

  constexpr unsigned int mergerDepth = 3;
  constexpr unsigned int maxFMLayer = (1<<mergerDepth);

  constexpr int NStubs = NBarrelStubs + NDiskStubs;

  constexpr unsigned int NFMBarrel[NBarrelStubs] = {
    NFMPerStubBarrel&15,
    (NFMPerStubBarrel>>4)&15, 
    (NFMPerStubBarrel>>8)&15, 
    (NFMPerStubBarrel>>12)&15,
    (NFMPerStubBarrel>>16)&15,
    (NFMPerStubBarrel>>20)&15
  };

  constexpr unsigned int NFMDisk[NDiskStubs] = {
    NFMPerStubDisk&15,
    (NFMPerStubDisk>>4)&15,
    (NFMPerStubDisk>>8)&15,
    (NFMPerStubDisk>>12)&15,
    (NFMPerStubDisk>>16)&15};

  constexpr unsigned int FMBarrelStart[NBarrelStubs] = {
    0,
    NFMBarrel[0],
    NFMBarrel[0]+NFMBarrel[1],
    NFMBarrel[0]+NFMBarrel[1]+NFMBarrel[2],
    NFMBarrel[0]+NFMBarrel[1]+NFMBarrel[2]+NFMBarrel[3],
    NFMBarrel[0]+NFMBarrel[1]+NFMBarrel[2]+NFMBarrel[3]+NFMBarrel[4]};
  
  constexpr unsigned int FMDiskStart[NDiskStubs] = {
    0,
    NFMDisk[0],
    NFMDisk[0]+NFMDisk[1],
    NFMDisk[0]+NFMDisk[1]+NFMDisk[2],
    NFMDisk[0]+NFMDisk[1]+NFMDisk[2]+NFMDisk[3]};

  /*
  std::cout << "NFMBarrel:";
  for(unsigned int i=0; i<NBarrelStubs; i++) {
    std::cout << " " << NFMBarrel[i];
  }
  std::cout << std::endl;

  std::cout << "NFMDisk:";
  for(unsigned int i=0; i<NDiskStubs; i++) {
    std::cout << " " << NFMDisk[i];
  }
  std::cout << std::endl;

  std::cout << "FMBarrelStart:";
  for(unsigned int i=0; i<NBarrelStubs; i++) {
    std::cout << " " << FMBarrelStart[i];
  }
  std::cout << std::endl;
  
  std::cout << "FMDiskStart:";
  for(unsigned int i=0; i<NDiskStubs; i++) {
    std::cout << " " << FMDiskStart[i];
  }
  std::cout << std::endl;
  */
  
  IndexType nTracks = 0;
  done = false;
  bool done_latch = false;

  Merger<FullMatch<BARREL> >
    merger_L_top[NBarrelStubs], // root node
    merger_L_b1[NBarrelStubs],
    merger_L_b2[NBarrelStubs], // first level
    merger_L_b1_b1[NBarrelStubs],
    merger_L_b1_b2[NBarrelStubs],
    merger_L_b2_b1[NBarrelStubs],
    merger_L_b2_b2[NBarrelStubs];
  
  Merger<FullMatch<DISK> >
    merger_D_top[NDiskStubs], // root node
    merger_D_b1[NDiskStubs],
    merger_D_b2[NDiskStubs], // first level
    merger_D_b1_b1[NDiskStubs],
    merger_D_b1_b2[NDiskStubs],
    merger_D_b2_b1[NDiskStubs],
    merger_D_b2_b2[NDiskStubs];

  
  // counters for each possible leaf node in the merge tree
  // (up to eight for stub 0)
  int count_barrel[NBarrelStubs][maxFMLayer];

  initialize_barrel_mergers : for (short i = 0; NBarrelStubs > 0 && i < NBarrelStubs; i++) {
#pragma HLS unroll
    merger_L_top[i].reset();
    merger_L_b1[i].reset();
    merger_L_b2[i].reset();
    merger_L_b1_b1[i].reset();
    merger_L_b1_b2[i].reset();
    merger_L_b2_b1[i].reset();
    merger_L_b2_b2[i].reset();
    for(unsigned int j=0; j<maxFMLayer; j++) {
#pragma HLS unroll
      count_barrel[i][j]=0;
    }
  }
 
  // counters for each possible leaf node in the merge tree
  int count_disk[NDiskStubs][maxFMLayer];

  initialize_disk_mergers : for (short i = 0; NDiskStubs > 0 && i < NDiskStubs; i++) {
#pragma HLS unroll
    merger_D_top[i].reset();
    merger_D_b1[i].reset();
    merger_D_b2[i].reset();
    merger_D_b1_b1[i].reset();
    merger_D_b1_b2[i].reset();
    merger_D_b2_b1[i].reset();
    merger_D_b2_b2[i].reset();
    for(unsigned int j=0; j<maxFMLayer; j++) {
#pragma HLS unroll
      count_disk[i][j]=0;
    }

  }

  full_matches : for (unsigned short i = 0; i < kMaxProc; i++) {
#pragma HLS pipeline II=1 rewind
#pragma HLS latency min=6 max=6

    TrackletIDType min_id = kInvalidTrackletID;
    bool smallest[NStubs];

    // First determine the minimum tracklet ID from the current set of full
    // matches.

    min_id_outer : for (unsigned int j = 0; j < NStubs; j++) {

      int tid = kInvalidTrackletID;

      if (j < NBarrelStubs) {
        if (merger_L_top[j].valid()){
          tid = merger_L_top[j].peek().getTrackletID();
	}
      } else {
        if (merger_D_top[j-NBarrelStubs].valid()){
          tid = merger_D_top[j-NBarrelStubs].peek().getTrackletID();
	}
      }

      smallest[j] = true;


      min_id_inner : for (unsigned int k = 0 ; k < NStubs; k++) {

        int tid2 = kInvalidTrackletID;

        if (k < NBarrelStubs) {
          if (merger_L_top[k].valid())
            tid2 = merger_L_top[k].peek().getTrackletID();
        } else {
          if (merger_D_top[k-NBarrelStubs].valid())
            tid2 = merger_D_top[k-NBarrelStubs].peek().getTrackletID();
        }

        if (tid2 < tid) smallest[j] = false;
      }

      if (i < min_istep) smallest[j] = false;

      if (smallest[j]) min_id = tid;
    }

    // We are done if no valid ID was found; all subsequent output tracks are
    // invalid
    done = !done_latch && (i >= min_istep) && (min_id == kInvalidTrackletID);
    done_latch = (i >= min_istep) && (min_id == kInvalidTrackletID);

    // Initialize a TrackFit object using the tracklet parameters associated
    // with the minimum tracklet ID.
    const TCIDType &TCID = (min_id != kInvalidTrackletID) ? (min_id >> kNBits_MemAddr) : TrackletIDType(0);
    const ITCType &iTC = TCID.range(kNBitsITC - 1, 0);
    typename TrackFit<NBarrelStubs, NDiskStubs>::TFSEEDTYPE iseed = TCID >> kNBitsITC; //TCID.range(3+kNBitsITC-1,kNBitsITC);

    //These are actually not needed any more...
    auto mparNPages = getMPARNPages<Seed>(iTC);
    auto mparMem = getMPARMem<Seed>(iTC);
    auto mparPage = getMPARPage<Seed>(iTC);
    //This block is for AAAA
    //This should be automatically generate by the generate_TB.py script...
    if (iseed==0) {
      if (iTC==0) {mparNPages=3; mparMem=0; mparPage=0;}
      if (iTC==1) {mparNPages=3; mparMem=0; mparPage=1;}
      if (iTC==2) {mparNPages=3; mparMem=0; mparPage=2;}
      if (iTC==3) {mparNPages=2; mparMem=0; mparPage=0;}
      if (iTC==4) {mparNPages=2; mparMem=0; mparPage=1;}
      if (iTC==5) {mparNPages=1; mparMem=0; mparPage=0;}
      if (iTC==6) {mparNPages=1; mparMem=1; mparPage=0;}
      if (iTC==7) {mparNPages=2; mparMem=1; mparPage=0;}
      if (iTC==8) {mparNPages=2; mparMem=1; mparPage=1;}
      if (iTC==9) {mparNPages=3; mparMem=1; mparPage=0;}
      if (iTC==10) {mparNPages=3; mparMem=1; mparPage=1;}
      if (iTC==11) {mparNPages=3; mparMem=1; mparPage=2;}
    }
    if (iseed==1) {
      if (iTC==0) {mparNPages=4; mparMem=0; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=0; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=0; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=0; mparPage=3;}
    }
    if (iseed==3) {
      if (iTC==0) {mparNPages=4; mparMem=1; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=1; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=1; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=1; mparPage=3;}
    }
    if (iseed==7) {
      if (iTC==0) {mparNPages=4; mparMem=2; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=2; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=2; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=2; mparPage=3;}
    }
    //This block is for BBBB
    if (iseed==2) {
      if (iTC==0) {mparNPages=2; mparMem=0; mparPage=0;}
      if (iTC==1) {mparNPages=2; mparMem=0; mparPage=1;}
      if (iTC==2) {mparNPages=2; mparMem=1; mparPage=0;}
      if (iTC==3) {mparNPages=2; mparMem=1; mparPage=1;}
    }
    if (iseed==4) {
      if (iTC==0) {mparNPages=4; mparMem=0; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=0; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=0; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=0; mparPage=3;}
    }
    if (iseed==5) {
      if (iTC==0) {mparNPages=4; mparMem=1; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=1; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=1; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=1; mparPage=3;}
    }
    if (iseed==6) {
      if (iTC==0) {mparNPages=4; mparMem=2; mparPage=0;}
      if (iTC==1) {mparNPages=4; mparMem=2; mparPage=1;}
      if (iTC==2) {mparNPages=4; mparMem=2; mparPage=2;}
      if (iTC==3) {mparNPages=4; mparMem=2; mparPage=3;}
    }

    const IndexType &trackletIndex = (min_id != kInvalidTrackletID) ? (min_id & TrackletIDType(0x7F)) : TrackletIDType(0);
    const typename TrackFit<NBarrelStubs, NDiskStubs>::TFPHIREGION phiRegionOuter = iTC / (iseed == TF::L1L2 ? 3 : (iseed == TF::L1D1 ? 2 : 1));

    TrackFit<NBarrelStubs, NDiskStubs> track(iseed);
    track.setPhiRegionOuter(phiRegionOuter);
    if ((TPARMask & 0x1) && mparNPages == 1) {
      const auto &tpar = trackletParameters1[mparMem].read_mem(bx, trackletIndex);
      setTrackPars<NBarrelStubs, NDiskStubs>(track, tpar);
    }
    else if ((TPARMask & 0x2) && mparNPages == 2) {
      const auto &tpar = trackletParameters2[mparMem].read_mem(bx, trackletIndex, mparPage);
      setTrackPars<NBarrelStubs, NDiskStubs>(track, tpar);
    }
    else if ((TPARMask & 0x4) && mparNPages == 3) {
      const auto &tpar = trackletParameters3[mparMem].read_mem(bx, trackletIndex, mparPage);
      setTrackPars<NBarrelStubs, NDiskStubs>(track, tpar);
    }
    else if ((TPARMask & 0x8) && mparNPages == 4) {
      const auto &tpar = trackletParameters4[mparMem].read_mem(bx, trackletIndex, mparPage);
      setTrackPars<NBarrelStubs, NDiskStubs>(track, tpar);
    }   
    
    // Retrieve the full information for each full match that has the minimum
    // tracklet ID and assign it to the appropriate field of the TrackFit
    // object.
    ap_uint<3> nMatches = 0; // there can be up to eight matches (3 bits)

    //This is a hack to match the emulation where for D1D2 seeds
    //We don't use both L2 and D3 matches
    bool barrelD1D2Match1 = false;

    barrel_stub_association : for (short j = 0; j < NBarrelStubs; j++) {

      const auto &barrel_stub = merger_L_top[j].peek();
      const bool barrel_stub_valid = merger_L_top[j].valid() && smallest[j];
      if (barrel_stub_valid) {
	nMatches++;
	barrelD1D2Match1 = Seed == TF::D1D2 && j == 1;
      }

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
      bool disk_stub_valid = merger_D_top[j].valid() && smallest[j+NBarrelStubs];
      if (disk_stub_valid) {
	nMatches++;
	if (Seed == TF::D1D2 and j==0 && barrelD1D2Match1) {
	  //Hack to not allow D1D2 seed with L2 and D3 match - skip disk match
	  nMatches--;
	}
      }

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
      case 5: //should never get here?
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

    // Output the track word and eleven stub words associated with the TrackFit
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
        case 4:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<4>();
          break;
        case 5:
          barrelStubWords[j][nTracks] = track.template getBarrelStubWord<5>();
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
        case 4:
          diskStubWords[j][nTracks] = track.template getDiskStubWord<NBarrelStubs + 4>();
          break;
      }
    }
    nTracks += (track.getTrackValid() ? 1 : 0);

    // Do the next set of pairwise comparisons in the merge trees.
    barrel_merger : for (unsigned short j = 0; j < NBarrelStubs; j++) {
#pragma HLS unroll

      bool read_1, read_2;

      merger_L_top[j].next(merger_L_b1[j].peek(), merger_L_b1[j].valid(), read_1,
                            merger_L_b2[j].peek(), merger_L_b2[j].valid(), read_2,
                            smallest[j]);

      bool read_b1_1, read_b1_2, read_b2_1, read_b2_2,
	read_b1_b1_1, read_b1_b1_2, read_b1_b2_1, read_b1_b2_2,
	read_b2_b1_1, read_b2_b1_2, read_b2_b2_1, read_b2_b2_2;
      
      merger_L_b1[j].next(merger_L_b1_b1[j].peek(), merger_L_b1_b1[j].valid(), read_b1_1,
			  merger_L_b1_b2[j].peek(), merger_L_b1_b2[j].valid(), read_b1_2,
			  read_1);

      bool validmatch[maxFMLayer]={false};
      FullMatch<BARREL> fullmatch[maxFMLayer];
      for (unsigned int k=0; k < NFMBarrel[j]; k++) {
#pragma HLS unroll
	validmatch[k] = count_barrel[j][k] < barrelFullMatches[k+FMBarrelStart[j]].getEntries(bx);
	fullmatch[k] = barrelFullMatches[k+FMBarrelStart[j]].read_mem(bx,count_barrel[j][k]);
      }

      merger_L_b1_b1[j].next(fullmatch[0],
			  validmatch[0],
			  read_b1_b1_1,
			  fullmatch[1],
			  validmatch[1],
			  read_b1_b1_2,
			  read_b1_1);

      if (read_b1_b1_1) count_barrel[j][0]++;
      if (read_b1_b1_2) count_barrel[j][1]++;

      merger_L_b1_b2[j].next(fullmatch[2],
			  validmatch[2],
			  read_b1_b2_1,
			  fullmatch[3],
			  validmatch[3],
			  read_b1_b2_2,
			  read_b1_2);
      
      if (read_b1_b2_1) count_barrel[j][2]++;
      if (read_b1_b2_2) count_barrel[j][3]++;

      merger_L_b2[j].next(merger_L_b2_b1[j].peek(), merger_L_b2_b1[j].valid(), read_b2_1,
			  merger_L_b2_b2[j].peek(), merger_L_b2_b2[j].valid(), read_b2_2,
			  read_2);

      merger_L_b2_b1[j].next(fullmatch[4],
			  validmatch[4],
			  read_b2_b1_1,
			  fullmatch[5],
			  validmatch[5],
			  read_b2_b1_2,
			  read_b2_1);

      if (read_b2_b1_1) count_barrel[j][4]++;
      if (read_b2_b1_2) count_barrel[j][5]++;

      merger_L_b2_b2[j].next(fullmatch[6],
			  validmatch[6],
			  read_b2_b2_1,
			  fullmatch[7],
			  validmatch[7],
			  read_b2_b2_2,
			  read_b2_2);

      if (read_b2_b2_1) count_barrel[j][6]++;
      if (read_b2_b2_2) count_barrel[j][7]++;

    }

  disk_merger : for (unsigned int j = 0 ; j < NDiskStubs; j++) {
#pragma HLS unroll

      bool read_1, read_2;

      merger_D_top[j].next(merger_D_b1[j].peek(), merger_D_b1[j].valid(), read_1,
                            merger_D_b2[j].peek(), merger_D_b2[j].valid(), read_2,
                            smallest[j+NBarrelStubs]);

      bool read_b1_1, read_b1_2, read_b2_1, read_b2_2,
	read_b1_b1_1, read_b1_b1_2, read_b1_b2_1, read_b1_b2_2,
	read_b2_b1_1, read_b2_b1_2, read_b2_b2_1, read_b2_b2_2;
      
      merger_D_b1[j].next(merger_D_b1_b1[j].peek(), merger_D_b1_b1[j].valid(), read_b1_1,
			  merger_D_b1_b2[j].peek(), merger_D_b1_b2[j].valid(), read_b1_2,
			  read_1);

      bool validmatch[maxFMLayer]={false};
      FullMatch<DISK> fullmatch[maxFMLayer];
      for (unsigned int k=0; k<NFMDisk[j]; k++) {
#pragma HLS unroll
	validmatch[k] = count_disk[j][k] < diskFullMatches[k+FMDiskStart[j]].getEntries(bx);
	fullmatch[k] = diskFullMatches[k+FMDiskStart[j]].read_mem(bx,count_disk[j][k]);
      }
      
      merger_D_b1_b1[j].next(fullmatch[0],
			  validmatch[0],
			  read_b1_b1_1,
			  fullmatch[1],
			  validmatch[1],
			  read_b1_b1_2,
			  read_b1_1);

      if (read_b1_b1_1) count_disk[j][0]++;
      if (read_b1_b1_2) count_disk[j][1]++;
      
      merger_D_b1_b2[j].next(fullmatch[2],
			  validmatch[2],
			  read_b1_b2_1,
			  fullmatch[3],
			  validmatch[3],
			  read_b1_b2_2,
			  read_b1_2);
      
      if (read_b1_b2_1) count_disk[j][2]++;
      if (read_b1_b2_2) count_disk[j][3]++;
      
      merger_D_b2[j].next(merger_D_b2_b1[j].peek(), merger_D_b2_b1[j].valid(), read_b2_1,
			  merger_D_b2_b2[j].peek(), merger_D_b2_b2[j].valid(), read_b2_2,
			  read_2);

      merger_D_b2_b1[j].next(fullmatch[4],
			  validmatch[4],
			  read_b2_b1_1,
			  fullmatch[5],
			  validmatch[5],
			  read_b2_b1_2,
			  read_b2_1);
      
      if (read_b2_b1_1) count_disk[j][4]++;
      if (read_b2_b1_2) count_disk[j][5]++;

      merger_D_b2_b2[j].next(fullmatch[6],
			  validmatch[6],
			  read_b2_b2_1,
			  fullmatch[7],
			  validmatch[7],
			  read_b2_b2_2,
			  read_b2_2);
      
      if (read_b2_b2_1) count_disk[j][6]++;
      if (read_b2_b2_2) count_disk[j][7]++;

    }

  }

  bx_o = bx;
  done = !done_latch;
}

#endif
