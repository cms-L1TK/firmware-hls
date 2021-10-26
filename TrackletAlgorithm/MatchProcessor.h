#ifndef MATCHPROCESSOR_H
#define MATCHPROCESSOR_H

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMEMemoryCM.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "ProjectionRouterBufferArray.h"
#include "AllStubMemory.h"
#include "FullMatchMemory.h"
#include "MatchEngineUnit.h"
#include "hls_math.h"
#include <iostream>
#include <fstream>
#include <bitset>


namespace PR
{
  //////////////////////////////
  // Initialization
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  template<int nMEM, int NBits_Entries, class MemType>
  inline void init(BXType bx,
                   ap_uint<nMEM>& mem_hasdata,
                   ap_uint<NBits_Entries> nentries[nMEM],
                   const MemType mem[nMEM])
  {    
#pragma HLS inline  
    for(int i = 0; i < nMEM; ++i) {
#pragma HLS unroll
      ap_uint<kNBits_MemAddr+1> num = mem[i].getEntries(bx);
      nentries[i] = num;
      if (num > 0) mem_hasdata.set(i);
    }
  }
  
  //////////////////////////////
  // Priority encoder based input memory reading logic
  template<class DataType, class MemType, int nMEM>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const MemType inmem[nMEM])
  {
#pragma HLS inline
    for(int i = 0; i < nMEM; ++i) {
#pragma HLS unroll
    
      if (read_imem == i) {
        data = inmem[i].read_mem(bx, read_addr);
      }
    }
  }

  template<class DataType, class MemType, int nMEM, int NBits_Entries>
  bool read_input_mems(BXType bx,
                       ap_uint<nMEM>& mem_hasdata,
                       ap_uint<NBits_Entries> nentries[nMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       // memory pointers
                       const MemType mem[nMEM],
                       DataType& data, int& nproj)
  {
#pragma HLS inline
    if (mem_hasdata == 0) return false;

    // 5 bits memory index for up to 32 input memories
    // priority encoder
    ap_uint<5> read_imem = __builtin_ctz(mem_hasdata);

    // read the memory "read_imem" with the address "read_addr"
    read_inmem<DataType, MemType, nMEM>(data, bx, read_imem, read_addr, mem);

    // Increase the read address
    ++read_addr;

    if (read_addr >= nentries[read_imem]) {
      // All entries in the memory[read_imem] have been read out
      // Prepare to move to the next non-empty memory
      read_addr = 0;
      mem_hasdata.clear(read_imem);  // set the current lowest 1 bit to 0
      nproj++;
    }

    return true;
    
  } // read_input_mems


  /////////////////////////////////////////////////////
  // FIXME
  // Move the following to Constants.hh?
  // How to deal with these using enum?

  // number of bits for seed in tracklet index
  constexpr unsigned int nbits_seed = 3;

  // number of extra bits to keep when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_nbitsextra = 3;

  // value by which a z-projection is adjusted up & down when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_adjust_PSseed = 1;
  constexpr unsigned int zbins_adjust_2Sseed = 4;

  // Number of loop iterations subtracted from the full 108 so that the function
  // stays synchronized with other functions in the chain. Once we get these
  // functions to rewind correctly, this can be set to zero (or simply removed)
  constexpr unsigned int LoopItersCut = 0;

  inline void zbinLUTinit(ap_uint<2*MEBinsBits> zbinLUT[128], int zbins_adjust_PSseed, int zbins_adjust_2Sseed){

    for(unsigned int ibin=0; ibin<128; ibin++) {

      ap_uint<7> bin(ibin);

      ap_uint<1> psseed;
      ap_int<6> zbin6;

      (psseed,zbin6) =  bin;

      int zbins_adjust = psseed ? zbins_adjust_PSseed : zbins_adjust_2Sseed;
      ap_uint<6> zbinpos6 = (1<<(zbin6.length()-1))+zbin6;

      // Lower Bound
      auto zbinlower = zbinpos6<zbins_adjust ?
	ap_uint<MEBinsBits+zbins_nbitsextra>(0) :
	ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos6-zbins_adjust);
      // Upper Bound
      auto zbinupper = zbinpos6>((1<<(MEBinsBits+zbins_nbitsextra))-1-zbins_adjust) ? 
	ap_uint<MEBinsBits+zbins_nbitsextra>((1<<(MEBinsBits+zbins_nbitsextra))-1) :
	ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos6+zbins_adjust);
      
      ap_uint<MEBinsBits> zbin1 = zbinlower >> zbins_nbitsextra;
      ap_uint<MEBinsBits> zbin2 = zbinupper >> zbins_nbitsextra;
      
      zbinLUT[ibin] = (zbin1, zbin2);
    }
  }


} // namesapce PR


template<int L>
void readTable(ap_uint<1> table[]){

  if (L==TF::L1) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L1.tab"
    for (int i=0;i<256;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

/* FIXME uncomment these out when testing L2,L5, and L6. Need to be added to download.sh to work.
  if (L==TF::L2) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L2.tab"
    for (int i=0;i<256;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }
*/

  if (L==TF::L3) {
    bool tmp[256]=
#include "../emData/MP/tables/METable_L3.tab"
    for (int i=0;i<256;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::L4) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L4.tab"
    for (int i=0;i<512;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

/*
  if (L==TF::L5) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L5.tab"
#pragma HLS unroll
    for (int i=0;i<512;++i){
      table[i]=tmp[i];
    }
  }

  if (L==TF::L6) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L6.tab"
#pragma HLS unroll
    for (int i=0;i<512;++i){
      table[i]=tmp[i];
    }
  }
*/



}



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
template<bool phi, TF::layerDisk L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (phi){ // phi cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L1PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L2PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L3PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L4PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L5PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L6PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else { // z cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L1PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L2PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L3PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L4PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L5PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#include "../emData/MP/tables/MP_L6PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  }

} // end readTable_Cuts

//-----------------------------------------------------------------------------------------------------------
//-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
//-----------------------------------------------------------------------------------------------------------

// MatchCalculator
namespace MC {
  enum imc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
}
template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask();
template<TF::layerDisk Layer, MC::imc PHI> constexpr uint32_t FMMask();
#include "MatchProcessor_parameters.h"

template<regionType ASTYPE, regionType APTYPE, regionType VMSMEType, regionType FMTYPE, int maxFullMatchCopies, TF::layerDisk LAYER=TF::L1, MC::imc PHISEC=MC::A>
void MatchCalculator(BXType bx,
                     ap_uint<1> newtracklet,
                     ap_uint<1>& savedMatch,
                     ap_uint<17>& best_delta_phi,
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjection<APTYPE>& proj,
                     ap_uint<VMProjectionBase<BARREL>::kVMProjIndexSize> projid,
                     ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> stubid,
                     BXType& bx_o,
                     int &nmcout1,
                     int &nmcout2,
                     int &nmcout3,
                     int &nmcout4,
                     int &nmcout5,
                     int &nmcout6,
                     int &nmcout7,
                     int &nmcout8,
                     FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
){

#pragma HLS inline

  using namespace PR;


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

  const auto kFact               = (LAYER < TF::L4)? 1 : (1<<(kNbitszprojL123-kNbitszprojL456)); // fact_ in emulation defined in MC
  const auto kPhi0_shift         = (LAYER < TF::L4)? 3 : 0;                                      // phi0shift_ in emulation defined in MC
  const auto kShift_phi0bit      = 1;                                                             // phi0bitshift in emulation defined in constants
  const ap_uint<10> kPhi_corr_shift_L123 = 7 + kNbitsdrinv + kShift_phi0bit - kShift_Rinv - kShift_Phider;                    // icorrshift for L123
  const ap_uint<10> kPhi_corr_shift_L456 = kPhi_corr_shift_L123 - 10 + kNbitsrL456;                                           // icorrshift for L456
  const auto kPhi_corr_shift     = (LAYER < TF::L4)? kPhi_corr_shift_L123 : kPhi_corr_shift_L456;                            // icorrshift_ in emulation
  const ap_uint<10> kZ_corr_shiftL123 = (-1-kShift_PS_zderL);                                                                 // icorzshift for L123 (6 in L3)
  const ap_uint<10> kZ_corr_shiftL456 = (-1-kShift_2S_zderL + kNbitszprojL123 - kNbitszprojL456 + kNbitsrL456 - kNbitsrL123); // icorzshift for L456
  const auto kZ_corr_shift       = (LAYER < TF::L4)? kZ_corr_shiftL123 : kZ_corr_shiftL456;                                  // icorzshift_ in emulation

  const auto LUT_matchcut_phi_width = 17;
  const auto LUT_matchcut_phi_depth = 12;
  const auto LUT_matchcut_z_width = 13;
  const auto LUT_matchcut_z_depth = 12;

  // Setup look up tables for match cuts
  ap_uint<LUT_matchcut_phi_width> LUT_matchcut_phi[LUT_matchcut_phi_depth];
  readTable_Cuts<true,LAYER,LUT_matchcut_phi_width,LUT_matchcut_phi_depth>(LUT_matchcut_phi);
  ap_uint<LUT_matchcut_z_width> LUT_matchcut_z[LUT_matchcut_z_depth];
  readTable_Cuts<false,LAYER,LUT_matchcut_z_width,LUT_matchcut_z_depth>(LUT_matchcut_z);

  bool goodmatch                   = false;

  CandidateMatch cmatch(projid.concat(stubid));
  
  // Use the stub and projection indices to pick up the stub and projection

  AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);
  
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
  const int kProj_phi_len = AllProjection<APTYPE>::kAProjPhiSize + 1;
  ap_int<kProj_phi_len> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction
  ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction

  // Get phi and z difference between the projection and stub
  ap_int<10> delta_z         = stub_z - proj_z_corr;
  ap_int<14> delta_z_fact   = delta_z * kFact;
  ap_int<18> stub_phi_long  = stub_phi;         // make longer to allow for shifting
  const ap_int<18> &proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
  ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
  ap_int<18> shiftprojphi   = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
  ap_int<17> delta_phi      = shiftstubphi - shiftprojphi;
  ap_uint<13> abs_delta_z   = iabs<13>( delta_z_fact ); // absolute value of delta z
  ap_uint<17> abs_delta_phi = iabs<17>( delta_phi );    // absolute value of delta phi

  // Full match parameters
  const typename FullMatch<FMTYPE>::FMTCID          &fm_tcid  = proj_tcid;
  const typename FullMatch<FMTYPE>::FMTrackletIndex &fm_tkid  = proj_tkid;
  const typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
  const typename FullMatch<FMTYPE>::FMSTUBID        &fm_asid  = stubid;
  const typename FullMatch<FMTYPE>::FMSTUBR         &fm_stubr = stub_r;
  const typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
  const typename FullMatch<FMTYPE>::FMZRES          fm_z     = delta_z;
  
  // Full match  
  typename AllProjection<APTYPE>::AProjTCSEED projseed_next;
  FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,(ap_uint<3>(2),fm_asid),fm_stubr,fm_phi,fm_z);

  //-----------------------------------------------------------------------------------------------------------
  //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
  //-----------------------------------------------------------------------------------------------------------
  
  if (newtracklet) {
    savedMatch = 0;
  }
  
  // For first tracklet, pick up the phi cut value
  best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;

  // Check that matches fall within the selection window of the projection 
  if ((abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi)){
    // Update values of best phi parameters, so that the next match
    // will be compared to this value instead of the original selection cut
    best_delta_phi = abs_delta_phi;

    // Store bestmatch
    goodmatch = true;
  }
  
  if(goodmatch) { // Write out only the best match, based on the seeding 
    switch (proj_seed) {
    case 0:
    if(FMMask<LAYER, PHISEC, TF::L1L2>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L1L2>()].write_mem(bx,fm,nmcout1-savedMatch); // L1L2 seed
      nmcout1+=1-savedMatch;
    }
    break;
    case 1:
    if(FMMask<LAYER, PHISEC, TF::L2L3>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L2L3>()].write_mem(bx,fm,nmcout2-savedMatch); // L2L3 seed
      nmcout2+=1-savedMatch;
    }
    break;
    case 2:
    if(FMMask<LAYER, PHISEC, TF::L3L4>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L3L4>()].write_mem(bx,fm,nmcout3-savedMatch); // L3L4 seed
      nmcout3+=1-savedMatch;
    }
    break;
    case 3:
    if(FMMask<LAYER, PHISEC, TF::L5L6>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L5L6>()].write_mem(bx,fm,nmcout4-savedMatch); // L5L6 seed
      nmcout4+=1-savedMatch;
    }
    break;
    case 4:
    if(FMMask<LAYER, PHISEC, TF::D1D2>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::D1D2>()].write_mem(bx,fm,nmcout5-savedMatch); // D1D2 seed
      nmcout5+=1-savedMatch;
    }
    break;
    case 5:
    if(FMMask<LAYER, PHISEC, TF::D3D4>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::D3D4>()].write_mem(bx,fm,nmcout6-savedMatch); // D3D4 seed
      nmcout6+=1-savedMatch;
    }
    break;
    case 6:
    if(FMMask<LAYER, PHISEC, TF::L1D1>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L1D1>()].write_mem(bx,fm,nmcout7-savedMatch); // L1D1 seed
      nmcout7+=1-savedMatch;
    }
    break;
    case 7:
    if(FMMask<LAYER, PHISEC, TF::L2D1>()) {
      fullmatch[FMCount<LAYER, PHISEC, TF::L2D1>()].write_mem(bx,fm,nmcout8-savedMatch); // L2D1 seed
      nmcout8+=1-savedMatch;
    }
    break;
    }
    savedMatch = 1;
  }
  
  bx_o = bx;
  
} //end MC

//////////////////////////////
// MatchProcessor
template<regionType PROJTYPE, regionType VMSMEType, regionType VMPTYPE, regionType ASTYPE, regionType APTYPE, regionType FMTYPE, unsigned int nINMEM, int maxFullMatchCopies,
         TF::layerDisk LAYER=TF::L1, TF::layerDisk DISK=TF::D1, MC::imc PHISEC=MC::A>
void MatchProcessor(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
                      const TrackletProjectionMemory<PROJTYPE> projin[nINMEM],
                      const VMStubMEMemoryCM<VMSMEType, 3, 3, kNMatchEngines>& instubdata,
                      const AllStubMemory<ASTYPE>* allstub,
                      BXType& bx_o,
                      FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
){
#pragma HLS inline

  
  using namespace PR;

  //Initialize table for bend-rinv consistency
  ap_uint<1> table[kNMatchEngines][(LAYER<TF::L4)?256:512]; //FIXME Need to figure out how to replace 256 with meaningful const.
#pragma HLS ARRAY_PARTITION variable=table dim=0 complete
  readtable: for(int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll
    readTable<LAYER>(table[iMEU]); 
  } 

  // initialization:
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  ap_uint<nINMEM> mem_hasdata = 0;
#pragma HLS dependence variable=mem_hasdata inter RAW true
  ap_uint<kNBits_MemAddr+1> numbersin[nINMEM];
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0

  init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
    (bx, mem_hasdata, numbersin, projin);
  
  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;

  constexpr unsigned int kNBitsBuffer=3;

  // declare counters for each of the 8 output VMProj // !!!
  int nmcout1 = 0;
  int nmcout2 = 0;
  int nmcout3 = 0;
  int nmcout4 = 0;
  int nmcout5 = 0;
  int nmcout6 = 0;
  int nmcout7 = 0;
  int nmcout8 = 0;

  ap_uint<kNBits_MemAddr> nallproj;

  ////////////////////////////////////////////
  //Some ME stuff
  ////////////////////////////////////////////
  ap_uint<TEBinsBits> zbin=0;
  VMProjection<BARREL>::VMPFINEZ projfinez;
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  VMProjection<BARREL>::VMPRINV projrinv;
  bool isPSseed;
  bool second;
  ap_uint<kNBits_MemAddrBinned> istub=0;

  ap_uint<kNBits_MemAddr> iproj=0; //counter

  //The next projection to read, the number of projections and flag if we have
  //more projections to read
  auto nproj=0;

  ProjectionRouterBufferArray<3,APTYPE> projbufferarray;

  MatchEngineUnit<VMSMEType, BARREL, VMPTYPE, APTYPE> matchengine[kNMatchEngines];
#pragma HLS ARRAY_PARTITION variable=matchengine complete dim=0
#pragma HLS ARRAY_PARTITION variable=instubdata complete dim=1
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0
#pragma HLS dependence variable=istub inter false


  //These are used inside the MatchCalculator method and needs to be retained between iterations
  ap_uint<1> savedMatch;
  ap_uint<17> best_delta_phi;
  typename ProjectionRouterBuffer<BARREL, APTYPE>::TRKID lastTrkID(-1);

  TrackletProjection<PROJTYPE> projdata, projdata_;
  bool validin = false; 
  bool validin_ = false; 

  static ap_uint<2*MEBinsBits> zbinLUT[128];
#pragma HLS ARRAY_PARTITION variable=zbinLUT complete dim=0
  zbinLUTinit(zbinLUT, zbins_adjust_PSseed, zbins_adjust_2Sseed);

  ap_uint<4> nvmstubs[8][8]; 
#pragma HLS ARRAY_PARTITION variable=nvmstubs complete dim=0
  
 nstubsloop: for (unsigned int izbin=0;izbin<8;izbin++) {
#pragma HLS unroll      
    (nvmstubs[izbin][7],nvmstubs[izbin][6],nvmstubs[izbin][5],nvmstubs[izbin][4],
     nvmstubs[izbin][3],nvmstubs[izbin][2],nvmstubs[izbin][1],nvmstubs[izbin][0]) = instubdata.getEntries8(bx, izbin);
  }

 PROC_LOOP: for (int istep = 0; istep < kMaxProc-LoopItersCut; ++istep) {
#pragma HLS PIPELINE II=1 //rewind

    auto readptr = projbufferarray.getReadPtr();
    auto writeptr = projbufferarray.getWritePtr();
    bool empty = emptyUnit<kNBitsBuffer>()[(readptr,writeptr)];
    bool projBuffNearFull = nearFull3Unit<kNBitsBuffer>()[(readptr,writeptr)];
    
    ap_uint<3> iphi = 0;
    if (istep == 0) {
      nallproj = 0;
    }

    ap_uint<kNMatchEngines> idles;
    ap_uint<kNMatchEngines> emptys;
    typename ProjectionRouterBuffer<BARREL, ASTYPE>::TRKID trkids[kNMatchEngines];
#pragma HLS ARRAY_PARTITION variable=trkids complete dim=0


    bool anyidle = false;

  MEU_get_trkids: for(int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll      
      matchengine[iMEU].set_empty();
      idles[iMEU] = matchengine[iMEU].idle();
      anyidle = idles[iMEU] ? true : anyidle;
      emptys[iMEU] = matchengine[iMEU].empty();
      trkids[iMEU] = matchengine[iMEU].getTrkID();
    }
   
    
    ap_uint<kNMatchEngines> smallest = ~emptys;
#pragma HLS ARRAY_PARTITION variable=trkids complete dim=0
  MEU_smallest1: for(int iMEU1 = 0; iMEU1 < kNMatchEngines-1; ++iMEU1) {
#pragma HLS unroll
  MEU_smallest2: for(int iMEU2 = iMEU1+1; iMEU2 < kNMatchEngines; ++iMEU2) {
#pragma HLS unroll
	smallest[iMEU1] = smallest[iMEU1] & (trkids[iMEU1]<trkids[iMEU2]);
        smallest[iMEU2] = smallest[iMEU2] & (trkids[iMEU2]<trkids[iMEU1]);
      }
    }
      
    ap_uint<1> hasMatch = smallest.or_reduce();
    ap_uint<3> bestiMEU = __builtin_ctz(smallest);


    ProjectionRouterBuffer<BARREL,APTYPE> tmpprojbuff;
    if (anyidle && !empty) {
      tmpprojbuff = projbufferarray.read();
    }
    
    bool init = false;
  MEU_LOOP: for(unsigned int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll
      auto &meu = matchengine[iMEU];
      
      bool idle = idles[iMEU];

      if(idle && !empty && !init) {
        init =  true;
        auto iphi = tmpprojbuff.getPhi();
        meu.init(bx, tmpprojbuff, iphi, iMEU);
      }

      else meu.step(instubdata.getMem(iMEU));

      meu.processPipeLine(table[iMEU]);      

    } //end MEU loop
    
    if(hasMatch) {

      auto trkindex=matchengine[bestiMEU].getTrkID();
      
      typename VMProjection<BARREL>::VMPID projindex;
      
      ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> stubindex;
      ap_uint<AllProjection<APTYPE>::kAllProjectionSize> allproj;
      
      (stubindex,allproj) = matchengine[bestiMEU].read();
      
      ap_uint<1> newtracklet = lastTrkID != trkindex;
      
      lastTrkID = trkindex;

      MatchCalculator<ASTYPE, APTYPE, VMSMEType, FMTYPE, maxFullMatchCopies, LAYER, PHISEC>
	(bx, newtracklet, savedMatch, best_delta_phi, allstub, allproj, projindex, stubindex, bx_o,
	 nmcout1, nmcout2, nmcout3, nmcout4, nmcout5, nmcout6, nmcout7, nmcout8,
	 fullmatch);
    } //end MC if
    

      
    if (validin_) {
      auto iphiproj = projdata_.getPhi();
      auto izproj = projdata_.getRZ();
      auto iphider = projdata_.getPhiDer();
      auto trackletid = projdata_.getTCID();
      
      // PS seed
      // top 3 bits of tracklet index indicate the seeding pair
      ap_uint<nbits_seed> iseed = trackletid.range(trackletid.length()-1,trackletid.length()-nbits_seed);
      // Cf. https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATrackletCalculator.hh#L166
      // and here?
      // https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATracklet.hh#L1621
      // NOTE: emulation fw_synch branch does not include L2L3 seeding; the master branch does
      
      // All seeding pairs are PS modules except L3L4 and L5L6
      bool psseed = not(iseed==TF::L3L4 or iseed==TF::L5L6); 
      
      //////////////////////////
      // hourglass configuration
      
      // vmproj index
      const typename VMProjection<VMPTYPE>::VMPID &index = nallproj;
      
      // vmproj z
      // Separate the vm projections into zbins
      // To determine which zbin in VMStubsME the ME should look in to match this VMProjection,
      // the purpose of these lines is to take the top MEBinsBits (3) bits of zproj and shift it
      // to make it positive, which gives the bin index. But there is a range of possible z values
      // over which we want to look for matched stubs, and there is therefore possibly 2 bins that
      // we will have to look in. So we first take the first MEBinsBits+zbins_nbitsextra (3+3=6)
      // bits of zproj, adjust the value up and down by zbins_adjust (2), then truncate the
      // zbins_adjust (2) LSBs to get the lower & upper bins that we need to look in.
      
      ap_int<6> zbin6 = izproj.range(izproj.length()-1,izproj.length()-MEBinsBits-zbins_nbitsextra);

      //The first and last zbin the projection points to
      ap_uint<MEBinsBits> zfirst, zlast;

      (zfirst, zlast) = zbinLUT[(psseed,zbin6)];

      typename VMProjection<VMPTYPE>::VMPZBIN zbin = (zfirst, zfirst!=zlast);      

      // VM Projection
      typename VMProjection<VMPTYPE>::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zfirst,ap_uint<3>(0));
      
      //Extracts the rinv of the projection from the phider; recall phider = - rinv/2
      typename VMProjection<VMPTYPE>::VMPRINV rinv = (1<<(nbits_maxvm-1)) - 1 - iphider.range(iphider.length()-1,iphider.length()-nbits_maxvm);
      
      ///////////////////////////////////
      //This is where Anders calls the ME
      ///////////////////////////////////
      //If we have more projections and the buffer is not full we read
      //next projection and put in buffer if there are stubs in the 
      //memory the projection points to
      
      // number of bits used to distinguish the different modules in each layer/disk
      auto nbits_all = LAYER!=0 ? nbitsallstubs[LAYER-1] : nbitsallstubs[trklet::N_LAYER + DISK-1];
      
      // number of bits used to distinguish between VMs within a module
      auto nbits_vmme = LAYER!=0 ? nbits_vmmeall[LAYER-1] : nbits_vmmeall[trklet::N_LAYER + DISK-1];
      
      // bits used for routing
      iphi = iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);
      
      typename VMProjection<VMPTYPE>::VMPFINEPHI finephi = iphiproj.range(iphiproj.length()-nbits_all-nbits_vmme-1,
									  iphiproj.length()-nbits_all-nbits_vmme-3); 
      
      int nextrabits = 2;
      int overlapbits = nbits_vmme + nextrabits;
      
      unsigned int extrabits = iphiproj.range(iphiproj.length() - overlapbits-1, iphiproj.length() - overlapbits - nextrabits);
      
      unsigned int ivmPlus = iphi;
	
      ap_int<2> shift = 0;
      
      if (extrabits == ((1U << nextrabits) - 1) && iphi != ((1U << nbits_vmme) - 1)) {
	shift = 1;
	ivmPlus++;
      }
      unsigned int ivmMinus = iphi;
      if (extrabits == 0 && iphi != 0) {
	shift = -1;
	ivmMinus--;
      }
      
      ///////////////
      // VMProjection
      
      ap_uint<4> nstubfirstMinus=nvmstubs[zfirst][ivmMinus];
      ap_uint<4> nstublastMinus=nvmstubs[zlast][ivmMinus];
      ap_uint<4> nstubfirstPlus=nvmstubs[zfirst][ivmPlus];
      ap_uint<4> nstublastPlus=nvmstubs[zlast][ivmPlus];
      
      if (ivmMinus==ivmPlus) {
	nstubfirstPlus = 0;
	nstublastPlus = 0;
      }
      if (zfirst==zlast) {
	nstublastMinus = 0;
	nstublastPlus = 0;
      }
      
      ap_uint<16> nstubs=(nstublastPlus, nstubfirstPlus, nstublastMinus, nstubfirstMinus);
      
      VMProjection<BARREL> vmproj(index, zbin, finez, finephi, rinv, psseed);
      
      AllProjection<APTYPE> allproj(projdata_.getTCID(), projdata_.getTrackletIndex(), projdata_.getPhi(),
				    projdata_.getRZ(), projdata_.getPhiDer(), projdata_.getRZDer());
      if (nstubs!=0) { 
	ProjectionRouterBuffer<BARREL, APTYPE> projbuffertmp(allproj.raw(), ivmMinus, shift, trackletid, nstubs, zfirst, vmproj, psseed);
	projbufferarray.addProjection(projbuffertmp);
      }
      
    } // end if(validin)

    projdata_ = projdata;
    validin_ = validin;

    if (!projBuffNearFull){
      
      // read inputs
      validin = read_input_mems<TrackletProjection<PROJTYPE>,
	TrackletProjectionMemory<PROJTYPE>,
	nINMEM, kNBits_MemAddr+1>
	(bx, mem_hasdata, numbersin, mem_read_addr,
         projin, projdata, nproj);


 
    } else {
      validin = false;
    }// end if not near full

  } //end loop


} // end MatchProcessor()



#endif
