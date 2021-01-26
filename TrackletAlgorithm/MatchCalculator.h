#ifndef TrackletAlgorithm_MatchCalculator_h
#define TrackletAlgorithm_MatchCalculator_h

// MatchCalculator

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "AllStubMemory.h"
#include "AllProjectionMemory.h"
#include "FullMatchMemory.h"
#include "bitset"

//////////////////////////////////////////////////////////////

template<int MaxMatchCopies>
inline bool read_input_mems(BXType bx,
                     const CandidateMatchMemory match[MaxMatchCopies],
                     //bool read_addr[MaxMatchCopies],
                     ap_uint<kNBits_MemAddr> read_addr[MaxMatchCopies],
                     bool read[MaxMatchCopies],
                     CandidateMatch &cm) {
#pragma HLS inline
    ap_uint<8> best_imem = 0;
    CandidateMatch tmpcm;
    cm = CandidateMatch();

    // search the buffer for the smallest projid
    CM_BEST: for(int i = 0; i < MaxMatchCopies; ++i) {
#pragma HLS unroll
      tmpcm = match[i].read_mem(bx, read_addr[i]);
      if(tmpcm.raw() != 0) { // the first non-zero CM was read
        if(cm.raw() == 0) {
          cm = tmpcm;
          best_imem = i;
        }
        else if(tmpcm.getProjIndex() < cm.getProjIndex()) { // look for the lowest projid
          cm = tmpcm;
          best_imem = i;
        }
      }
    }

    // increment best read address
    read_addr[best_imem] = read_addr[best_imem] + 1;
    CM_ADDR: for(int i = 0; i < MaxMatchCopies; ++i) {
#pragma HLS unroll
      read[i] = (i == best_imem);
    }

    return true;
} //read_input_mems


//////////////////////////////////////////////////////////////

// Absolute value template

template< int width >
ap_uint<width> iabs( ap_int<width> value )
{
  ap_uint<width> absval;
  if (value < 0) absval = -value;
  else           absval = value;
  return absval;
};

//////////////////////////////////////////////////////////////

// Template to get look up tables

// Table for phi or z cuts
template<bool phi, TF::layer L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (phi){ // phi cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L1PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L2PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L3PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L4PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L5PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L6PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else { // z cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L1PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L2PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L3PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L4PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L5PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L6PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  }

} // end readTable_Cuts


//////////////////////////////////////////////////////////////

// MatchCalculator
namespace MC {
  enum imc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
}
template<TF::layer, MC::imc, TF::seed> constexpr bool FMMask();
#include "MatchCalculator_parameters.h"

template<regionType ASTYPE, regionType APTYPE, regionType FMTYPE, int MaxMatchCopies, int MaxFullMatchCopies, TF::layer LAYER=TF::L1, TF::disk DISK=TF::D1, MC::imc PHISEC=MC::A>
void MatchCalculator(BXType bx,
                     const CandidateMatchMemory match[MaxMatchCopies],
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjectionMemory<APTYPE>* allproj,
                     BXType& bx_o,
                     FullMatchMemory<FMTYPE> fullmatch[MaxFullMatchCopies]
){
#pragma HLS inline
#pragma HLS array_partition variable=match complete dim=1
#pragma HLS array_partition variable=fullmatch complete dim=1

  // Initialization
 
  // Setup constants depending on which layer/disk working on
  // probably should move these to constants file
  const ap_uint<4> kNbitszprojL123 = 12; // nbitszprojL123 in emulation (defined in constants) 
  const ap_uint<4> kNbitszprojL456 = 8;  // nbitszprojL456 in emulation (defined in constants)
  const ap_uint<5> kNbitsdrinv = 19;     // idrinvbits     in emulation (defined in constants)
  const ap_uint<4> kShift_Rinv = 13;     // rinvbitshift   in emulation (defined in constants)
  const ap_uint<3> kShift_Phider = 7;    // phiderbitshift in emulation (defined in constants)
  const ap_uint<3> kNbitsrL123 = 7;      // nbitsrL123     in emulation (defined in constants)
  const ap_uint<3> kNbitsrL456 = 7;      // nbitsrL456     in emulation (defined in constants) 
  const ap_int<4>  kShift_PS_zderL = -7; // PS_zderL_shift in emulation (defined in constants)
  const ap_int<4>  kShift_2S_zderL = -7; // SS_zderL_shift in emulation (defined in constants)

  const auto kFact               = (1 <= LAYER <= 3)? 1 : (1<<(kNbitszprojL123-kNbitszprojL456)); // fact_ in emulation defined in MC
  const auto kPhi0_shift         = (1 <= LAYER <= 3)? 3 : 0;                                      // phi0shift_ in emulation defined in MC
  const auto kShift_phi0bit      = 1;                                                             // phi0bitshift in emulation defined in constants
  const ap_uint<10> kPhi_corr_shift_L123 = 7 + kNbitsdrinv + kShift_phi0bit - kShift_Rinv - kShift_Phider;                    // icorrshift for L123
  const ap_uint<10> kPhi_corr_shift_L456 = kPhi_corr_shift_L123 - 10 - kNbitsrL456;                                           // icorrshift for L456
  const auto kPhi_corr_shift     = (1 <= LAYER <= 3)? kPhi_corr_shift_L123 : kPhi_corr_shift_L456;                            // icorrshift_ in emulation
  const ap_uint<10> kZ_corr_shiftL123 = (-1-kShift_PS_zderL);                                                                 // icorzshift for L123 (6 in L3)
  const ap_uint<10> kZ_corr_shiftL456 = (-1-kShift_2S_zderL + kNbitszprojL123 - kNbitszprojL456 + kNbitsrL456 - kNbitsrL123); // icorzshift for L456
  const auto kZ_corr_shift       = (1 <= LAYER <= 3)? kZ_corr_shiftL123 : kZ_corr_shiftL456;                                  // icorzshift_ in emulation

  const auto LUT_matchcut_phi_width = 17;
  const auto LUT_matchcut_phi_depth = 12;
  const auto LUT_matchcut_z_width = 13;
  const auto LUT_matchcut_z_depth = 12;

  // Setup look up tables for match cuts
  ap_uint<LUT_matchcut_phi_width> LUT_matchcut_phi[LUT_matchcut_phi_depth];
  readTable_Cuts<true,LAYER,LUT_matchcut_phi_width,LUT_matchcut_phi_depth>(LUT_matchcut_phi);
  ap_uint<LUT_matchcut_z_width> LUT_matchcut_z[LUT_matchcut_z_depth];
  readTable_Cuts<false,LAYER,LUT_matchcut_z_width,LUT_matchcut_z_depth>(LUT_matchcut_z);

  // Initialize MC delta phi cut variables
  ap_uint<17> best_delta_phi;

  // Bool and ID needed for determining if processing a new tracklet
  CandidateMatch::CMProjIndex id;
  CandidateMatch::CMProjIndex id_next;

  // Initialize read addresses for candidate matches
  ap_uint<kNBits_MemAddr> read_addr[MaxMatchCopies] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Read signals for the input candidate matches
  bool read[MaxMatchCopies] = {false, false, false, false, false, false, false, false};

  // Setup candidate match data stream that goes into match calculations
  CandidateMatch datastream = CandidateMatch();

  // Full match shift register to store best match
  typename AllProjection<APTYPE>::AProjTCSEED projseed;
  FullMatch<FMTYPE> bestmatch      = FullMatch<FMTYPE>();
  bool goodmatch                   = false;


  //-----------------------------------------------------------------------------------------------------------
  //-------------------------------- DATA PROCESSING STARTS ---------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------
  // declare counters for each of the 8 output VMProj // !!!
  ap_uint<kNBits_MemAddr> nmcout1 = 0;
  ap_uint<kNBits_MemAddr> nmcout2 = 0;
  ap_uint<kNBits_MemAddr> nmcout3 = 0;
  ap_uint<kNBits_MemAddr> nmcout4 = 0;
  ap_uint<kNBits_MemAddr> nmcout5 = 0;
  ap_uint<kNBits_MemAddr> nmcout6 = 0;
  ap_uint<kNBits_MemAddr> nmcout7 = 0;
  ap_uint<kNBits_MemAddr> nmcout8 = 0;  

  MC_LOOP: for (ap_uint<kNBits_MemAddr> istep = 0; istep < kMaxProc - kMaxProcOffset(module::MC); istep++)
  {

#pragma HLS PIPELINE II=1 

    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------- MERGE INPUT CANDIDATE MATCHES --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    bool validin = read_input_mems<MaxMatchCopies>(bx, match, read_addr, read, datastream);
    datastream = validin ? datastream : CandidateMatch(); // ignore if no valid CM was found

    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // Extract the stub and projection indices from the candidate match
    auto projid = datastream.getProjIndex();
    auto stubid = datastream.getStubIndex();
    // Use the stub and projection indices to pick up the stub and projection
    AllProjection<APTYPE> proj = allproj->read_mem(bx,projid);
    AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);

    // Check if processing a new tracklet or not 
    // Later we only want to store the single best match per tracklet
    id      = id_next; // pipelined id
    id_next = projid;  
    bool newtracklet = (istep==0 || (id_next != id))? true : false;

    // Stub parameters
    typename AllStub<ASTYPE>::ASR    stub_r    = stub.getR();
    typename AllStub<ASTYPE>::ASZ    stub_z    = stub.getZ();
    typename AllStub<ASTYPE>::ASPHI  stub_phi  = stub.getPhi();
    typename AllStub<ASTYPE>::ASBEND stub_bend = stub.getBend();       

    // Projection parameters
    typename AllProjection<APTYPE>::AProjTCID          proj_tcid = proj.getTCID();
    typename AllProjection<APTYPE>::AProjTrackletIndex proj_tkid = proj.getTrackletIndex();
    typename AllProjection<APTYPE>::AProjTCSEED        proj_seed = proj.getSeed();
    typename AllProjection<APTYPE>::AProjPHI           proj_phi  = proj.getPhi();
    typename AllProjection<APTYPE>::AProjRZ            proj_z    = proj.getRZ();
    typename AllProjection<APTYPE>::AProjPHIDER        proj_phid = proj.getPhiDer();
    typename AllProjection<APTYPE>::AProjRZDER         proj_zd   = proj.getRZDer(); 

    // Calculate residuals
    // Get phi and z correction
    ap_int<22> full_phi_corr = stub_r * proj_phid; // full corr has enough bits for full multiplication
    ap_int<18> full_z_corr   = stub_r * proj_zd;   // full corr has enough bits for full multiplication
    ap_int<11> phi_corr      = full_phi_corr >> kPhi_corr_shift;                        // only keep needed bits
    ap_int<12> z_corr        = (full_z_corr + (1<<(kZ_corr_shift-1))) >> kZ_corr_shift; // only keep needed bits
     
    // Apply the corrections
    ap_int<15> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction
    ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction

    // Get phi and z difference between the projection and stub
    ap_int<10> delta_z         = stub_z - proj_z_corr;
    ap_int<14> delta_z_fact   = delta_z * kFact;
    ap_int<18> stub_phi_long  = stub_phi;         // make longer to allow for shifting
    ap_int<18> proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
    ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
    ap_int<18> shiftprojphi   = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
    ap_int<17> delta_phi      = shiftstubphi - shiftprojphi;
    ap_uint<13> abs_delta_z   = iabs<13>( delta_z_fact ); // absolute value of delta z
    ap_uint<17> abs_delta_phi = iabs<17>( delta_phi );    // absolute value of delta phi

    // Full match parameters
    typename FullMatch<FMTYPE>::FMTCID          &fm_tcid  = proj_tcid;
    typename FullMatch<FMTYPE>::FMTrackletIndex &fm_tkid  = proj_tkid;
    typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
    typename FullMatch<FMTYPE>::FMSTUBID        &fm_asid  = stubid;
    typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
    typename FullMatch<FMTYPE>::FMZRES          fm_z     = delta_z;

    // Full match  
    FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,fm_asphi,fm_asid,fm_phi,fm_z);

    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
    //-----------------------------------------------------------------------------------------------------------
 
    typename AllProjection<APTYPE>::AProjTCSEED projseed_next;
    FullMatch<FMTYPE> bestmatch_next = FullMatch<FMTYPE>();
    bool goodmatch_next              = false;

    // For first tracklet, pick up the phi cut value
    best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;
  
    // Check that matches fall within the selection window of the projection 
    if ((abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi)){
      // Update values of best phi parameters, so that the next match
      // will be compared to this value instead of the original selection cut
      best_delta_phi = abs_delta_phi;

      // Store bestmatch
      bestmatch_next = fm;
      goodmatch_next = true;
      projseed_next  = proj_seed;
    }
    else if (newtracklet){ // if is a new tracklet, do not make a match because it didn't pass the cuts
      bestmatch_next = FullMatch<FMTYPE>();
      goodmatch_next = false;
      projseed_next  = -1;
    }
    else { // if current match did not pass, but it is not a new tracklet, keep the previous best match for that tracklet
      bestmatch_next = bestmatch;
      goodmatch_next = goodmatch;
      projseed_next  = projseed;
    }

    if(newtracklet && goodmatch==true) { // Write out only the best match, based on the seeding 
      switch (projseed) {
        case 0:
        if(FMMask<LAYER, PHISEC, TF::L1L2>()) {
          fullmatch[0].write_mem(bx,bestmatch,nmcout1); // L1L2 seed
          nmcout1++;
        }
        break;
        case 1:
        if(FMMask<LAYER, PHISEC, TF::L2L3>()) {
          fullmatch[1].write_mem(bx,bestmatch,nmcout2); // L2L3 seed
          nmcout2++;
        }
        break;
        case 2:
        if(FMMask<LAYER, PHISEC, TF::L3L4>()) {
          fullmatch[2].write_mem(bx,bestmatch,nmcout3); // L3L4 seed
          nmcout3++;
        }
        break;
        case 3:
        if(FMMask<LAYER, PHISEC, TF::L5L6>()) {
          fullmatch[3].write_mem(bx,bestmatch,nmcout4); // L5L6 seed
          nmcout4++;
        }
        break;
        case 4:
        if(FMMask<LAYER, PHISEC, TF::D1D2>()) {
          fullmatch[4].write_mem(bx,bestmatch,nmcout5); // D1D2 seed
          nmcout5++;
        }
        break;
        case 5:
        if(FMMask<LAYER, PHISEC, TF::D3D4>()) {
          fullmatch[5].write_mem(bx,bestmatch,nmcout6); // D3D4 seed
          nmcout6++;
        }
        break;
        case 6:
        if(FMMask<LAYER, PHISEC, TF::L1D1>()) {
          fullmatch[6].write_mem(bx,bestmatch,nmcout7); // L1D1 seed
          nmcout7++;
        }
        break;
        case 7:
        if(FMMask<LAYER, PHISEC, TF::L2D1>()) {
          fullmatch[7].write_mem(bx,bestmatch,nmcout8); // L2D1 seed
          nmcout8++;
        }
        break;
      }
    }

    // pipeline the bestmatch registers
    bestmatch      = bestmatch_next;
    goodmatch      = goodmatch_next;
    projseed       = projseed_next;

    if (istep==kMaxProc-kMaxProcOffset(module::MC)-1) bx_o = bx;

  }// end MC_LOOP 

  /*
  // finish by writing out the last match made (to minimize truncation) -- can't do this because not in the loop 
  fullmatch[0].write_mem(bx,bestmatch,(goodmatch=true && projseed==0)); // L1L2 seed
  fullmatch[1].write_mem(bx,bestmatch,(goodmatch=true && projseed==1)); // L3L4 seed
  fullmatch[2].write_mem(bx,bestmatch,(goodmatch=true && projseed==2)); // L5L6 seed
  fullmatch[3].write_mem(bx,bestmatch,(goodmatch=true && projseed==3)); // D1D2 seed
  fullmatch[4].write_mem(bx,bestmatch,(goodmatch=true && projseed==4)); // D3D4 seed
  fullmatch[5].write_mem(bx,bestmatch,(goodmatch=true && projseed==5)); // L1D1 seed
  fullmatch[6].write_mem(bx,bestmatch,(goodmatch=true && projseed==6)); // L2D1 seed
  */

}// end MatchCalculator

#endif
