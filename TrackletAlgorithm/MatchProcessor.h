#ifndef MATCHPROCESSOR_H
#define MATCHPROCESSOR_H

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "ProjectionRouterBufferArray.h"
#include "AllStubMemory.h"
#include "AllProjectionMemory.h"
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
                   const int i,
                   const MemType* const mem)
  {    
#pragma HLS inline  
    ap_uint<kNBits_MemAddr+1> num = mem->getEntries(bx);
    nentries[i] = num;
    if (num > 0) mem_hasdata.set(i);
  }
  
  // recursive case
  template<int nMEM, int NBits_Entries, class MemType, class... Args>
  inline void init(BXType bx, ap_uint<nMEM>& mem_hasdata,
                   ap_uint<NBits_Entries> nentries[nMEM],
                   const int i,
                   const MemType* const mem, Args... args)
  {
#pragma HLS inline 
    ap_uint<kNBits_MemAddr+1> num = mem->getEntries(bx);
    nentries[i] = num;
    if (num > 0) mem_hasdata.set(i);

    if (i+1 < nMEM) init(bx, mem_hasdata, nentries, i+1, args...);
  }
  
  //////////////////////////////
  // Priority encoder based input memory reading logic
  template<class DataType, class MemType>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i, const MemType* const inmem)
  {
#pragma HLS inline
    
    if (read_imem == i) {
      data = inmem->read_mem(bx, read_addr);
    }
  }

  template<class DataType, class MemType, class... Args>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i,
                  const MemType* const inmem, Args... args)
  {
    if (read_imem == i) {
      data = inmem->read_mem(bx, read_addr);
    }
    read_inmem(data, bx, read_imem, read_addr, i+1, args...);
  }

  template<class DataType, class MemType, int nMEM, int NBits_Entries>
  bool read_input_mems(BXType bx,
                       ap_uint<nMEM>& mem_hasdata,
                       ap_uint<NBits_Entries> nentries[nMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       // memory pointers
                       const MemType* const mem0, const MemType* const mem1,
                       const MemType* const mem2, const MemType* const mem3,
                       const MemType* const mem4, const MemType* const mem5,
                       const MemType* const mem6, const MemType* const mem7,
                       const MemType* const mem8, const MemType* const mem9,
                       const MemType* const mem10, const MemType* const mem11,
                       const MemType* const mem12, const MemType* const mem13,
                       const MemType* const mem14, const MemType* const mem15,
                       const MemType* const mem16, const MemType* const mem17,
                       const MemType* const mem18, const MemType* const mem19,
                       const MemType* const mem20, const MemType* const mem21,
                       const MemType* const mem22, const MemType* const mem23,
                       DataType& data, int& nproj)
  {
#pragma HLS inline
    if (mem_hasdata == 0) return false;

    // 5 bits memory index for up to 32 input memories
    // priority encoder
    ap_uint<5> read_imem = __builtin_ctz(mem_hasdata);

    // read the memory "read_imem" with the address "read_addr"
    read_inmem(data, bx, read_imem, read_addr, 0,
    //read_inmem(data, datamem, bx, read_imem, read_addr, 0,
               mem0,mem1,mem2,mem3,mem4,mem5,mem6,mem7,
               mem8,mem9,mem10,mem11,mem12,mem13,mem14,mem15,
               mem16,mem17,mem18,mem19,mem20,mem21,mem22,mem23);

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

  // number of bits used to distinguish allstub memories for each layer
  constexpr unsigned int nbits_allstubslayers[6]={3,2,2,2,2,2};
  // number of bits used to distinguish VMs in one allstub block for each layer
  constexpr unsigned int nbits_vmmelayers[6]={2,3,3,3,3,3};

  // number of bits used to distinguish allstub memories for each disk
  constexpr unsigned int nbits_allstubsdisks[5]={2,2,2,2,2};
  
  // number of bits used to distinguish VMs in one allstub block for each disk
  constexpr unsigned int nbits_vmmedisks[5]={3,2,2,2,2};

  // number of bits for seed in tracklet index
  constexpr unsigned int nbits_seed = 3;

  // number of extra bits to keep when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_nbitsextra = 3;

  // value by which a z-projection is adjusted up & down when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_adjust = 1;

  // Number of loop iterations subtracted from the full 108 so that the function
  // stays synchronized with other functions in the chain. Once we get these
  // functions to rewind correctly, this can be set to zero (or simply removed)
  constexpr unsigned int LoopItersCut = 6;// - 95; 

} // namesapce PR


template<int L>
void readTable(bool table[256]){

  if (L==1) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L1.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

/*
  if (L==2) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L2.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }
*/

  if (L==3) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L3.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

  if (L==4) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L4.tab"
    for (int i=0;i<512;i++){
      table[i]=tmp[i];
    }
  }

/*
  if (L==5) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L5.tab"
    for (int i=0;i<512;i++){
      table[i]=tmp[i];
    }
  }

  if (L==6) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L6.tab"
    for (int i=0;i<512;i++){
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
template<bool phi, int L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (phi){ // phi cuts
    if (L==1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L1PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L2PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L3PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L4PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L5PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L6PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else { // z cuts
    if (L==1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L1PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L2PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L3PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L4PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L5PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/tables/MC_L6PHIC_zcut.tab"
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

template<regionType ASTYPE, regionType APTYPE, regionType VMSMEType, regionType FMTYPE, int maxFullMatchCopies,int LAYER=0, int PHISEC=0>
void MatchCalculator(BXType bx,
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjectionMemory<APTYPE>* allproj,
                     ap_uint<VMProjectionBase<BARREL>::kVMProjIndexSize> projid,
                     ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize> stubid,
                     int nstubs,
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

  //std::cout << "MC received nstubs=" << nstubs << std::endl;

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

  // Full match shift register to store best match
  typename AllProjection<APTYPE>::AProjTCSEED projseed;
  FullMatch<FMTYPE> bestmatch      = FullMatch<FMTYPE>();
  bool goodmatch                   = false;

    // Don't read past nstubs (would read garbage)
    CandidateMatch cmatch(projid.concat(stubid));
    std::cout << "MC received projid=" << projid << "\tstubid=" << stubid << std::endl;
  
    // Use the stub and projection indices to pick up the stub and projection
    AllProjection<APTYPE> proj = allproj->read_mem(bx,projid);
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
    ap_int<15> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction
    ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction
  
    // Get phi and z difference between the projection and stub
    ap_int<9> delta_z         = stub_z - proj_z_corr;
    ap_int<13> delta_z_fact   = delta_z * kFact;
    ap_int<18> stub_phi_long  = stub_phi;         // make longer to allow for shifting
    ap_int<18> proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
    ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
    ap_int<18> shiftprojphi   = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
    ap_int<17> delta_phi      = shiftstubphi - shiftprojphi;
    ap_uint<13> abs_delta_z   = iabs<13>( delta_z_fact ); // absolute value of delta z
    ap_uint<17> abs_delta_phi = iabs<17>( delta_phi );    // absolute value of delta phi
  
    // Full match parameters
    typename FullMatch<FMTYPE>::FMTCID          fm_tcid  = proj_tcid;
    typename FullMatch<FMTYPE>::FMTrackletIndex fm_tkid  = proj_tkid;
    typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
    typename FullMatch<FMTYPE>::FMSTUBID        fm_asid  = stubid;
    typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
    typename FullMatch<FMTYPE>::FMZRES          fm_z     = delta_z;
  
    // Full match  
    FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,fm_asphi,fm_asid,fm_phi,fm_z);
for(int i = 0; i < maxFullMatchCopies; ++i) {
#pragma HLS unroll
#pragma HLS dependence variable=fullmatch[i] intra RAW true
}
    //std::cout << std::hex << "MC received projid=" << projid << "\tstubid=" << stubid << "\tfm=" << fm.raw() << std::endl;
  
    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
    //-----------------------------------------------------------------------------------------------------------
  
    typename AllProjection<APTYPE>::AProjTCSEED projseed_next;
    FullMatch<FMTYPE> bestmatch_next = FullMatch<FMTYPE>();
    bool goodmatch_next              = false;
  
    bool newtracklet = true;
    /* FIXME
    std::cout << "new tracklet " << newtracklet << std::endl;
    std::cout << std::hex << "bestmatch=" << bestmatch.raw() << std::endl;
    std::cout << std::hex << "goodmatch=" << goodmatch << std::endl;
    */
  
    // For first tracklet, pick up the phi cut value
    best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;
  
    // Check that matches fall within the selection window of the projection 
    if ((abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi)){
      // Update values of best phi parameters, so that the next match
      // will be compared to this value instead of the original selection cut
      best_delta_phi = abs_delta_phi;
  
      // Store bestmatch
      bestmatch = fm;
      goodmatch = true;
      projseed  = proj_seed;
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
      fullmatch[0].write_mem(bx,bestmatch,nmcout1);//(newtracklet && goodmatch==true && projseed==0)); // L1L2 seed
      nmcout1++;
      break;
      case 1:
      fullmatch[1].write_mem(bx,bestmatch,nmcout2);//(newtracklet && goodmatch==true && projseed==1)); // L3L4 seed
      nmcout2++;
      break;
      case 2:
      fullmatch[2].write_mem(bx,bestmatch,nmcout3);//(newtracklet && goodmatch==true && projseed==2)); // L5L6 seed
      nmcout3++;
      break;
      case 3:
      fullmatch[3].write_mem(bx,bestmatch,nmcout4);//(newtracklet && goodmatch==true && projseed==3)); // D1D2 seed
      nmcout4++;
      break;
      case 4:
      fullmatch[4].write_mem(bx,bestmatch,nmcout5);//(newtracklet && goodmatch==true && projseed==4)); // D3D4 seed
      nmcout5++;
      break;
      case 5:
      fullmatch[5].write_mem(bx,bestmatch,nmcout6);//(newtracklet && goodmatch==true && projseed==5)); // L1D1 seed
      nmcout6++;
      break;
      case 6:
      fullmatch[6].write_mem(bx,bestmatch,nmcout7);//(newtracklet && goodmatch==true && projseed==6)); // L2D1 seed
      nmcout7++;
      break;
      case 7:
      fullmatch[7].write_mem(bx,bestmatch,nmcout8);//(newtracklet && goodmatch==true && projseed==7)); // L2D1 seed
      nmcout8++;
      break;
      }
    }
  
    // pipeline the bestmatch registers
    bestmatch      = bestmatch_next;
    goodmatch      = goodmatch_next;
    projseed       = projseed_next;
  
    bx_o = bx;
    
} //end MC


//////////////////////////////
// MatchProcessor
template<int L, regionType PROJTYPE, regionType VMSMEType, regionType VMPTYPE, regionType ASTYPE, regionType APTYPE, regionType FMTYPE, int maxInCopies, int maxFullMatchCopies, int maxTrackletProjections, unsigned int nINMEM,
         int LAYER=0, int DISK=0, int PHISEC=0>
void MatchProcessor(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
                      const TrackletProjectionMemory<PROJTYPE> tprojarray[maxTrackletProjections], 
                      const TrackletProjectionMemory<PROJTYPE>* const proj1in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj2in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj3in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj4in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj5in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj6in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj7in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj8in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj9in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj10in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj11in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj12in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj13in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj14in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj15in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj16in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj17in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj18in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj19in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj20in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj21in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj22in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj23in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj24in,
                      const VMStubMEMemory<VMSMEType,3> instubdata[maxInCopies],
                      const AllStubMemory<ASTYPE>* allstub,
                      AllProjectionMemory<APTYPE>* allproj,
                      BXType& bx_o,
                      FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]
){
#pragma HLS inline


  using namespace PR;

  //Initialize table for bend-rinv consistency
  bool table[(L<4)?256:512]; //FIXME Need to figure out how to replace 256 with meaningful const.
  readTable<L>(table);
  
  // reset output memories
  /*
  fullmatch[0].clear(bx);
  fullmatch[1].clear(bx);
  fullmatch[2].clear(bx);
  fullmatch[3].clear(bx);
  fullmatch[4].clear(bx);
  fullmatch[5].clear(bx);
  fullmatch[6].clear(bx);
  fullmatch[7].clear(bx);
  */

  // initialization:
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  ap_uint<nINMEM> mem_hasdata = 0;
#pragma HLS dependence variable=mem_hasdata inter RAW true
  ap_uint<kNBits_MemAddr+1> numbersin[nINMEM];
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0
#pragma HLS ARRAY_PARTITION variable=tprojarray complete dim=0
//#pragma HLS resource variable=fullmatch core=RAM_2P_LUTRAM
#pragma HLS ARRAY_PARTITION variable=fullmatch complete dim=0

  init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
    (bx, mem_hasdata, numbersin,0,
     /*
     &tprojarray[1],&tprojarray[2],&tprojarray[3],&tprojarray[4],&tprojarray[5],&tprojarray[6],&tprojarray[7],&tprojarray[8],
     &tprojarray[9],&tprojarray[10],&tprojarray[11],&tprojarray[12],&tprojarray[13],&tprojarray[14],&tprojarray[15],&tprojarray[16],
     &tprojarray[17],&tprojarray[18],&tprojarray[19],&tprojarray[20],&tprojarray[21],&tprojarray[22],&tprojarray[23],&tprojarray[24]);
     */
     proj1in,proj2in,proj3in,proj4in,proj5in,proj6in,proj7in,proj8in,
     proj9in,proj10in,proj11in,proj12in,proj13in,proj14in,proj15in,proj16in,
     proj17in,proj18in,proj19in,proj20in,proj21in,proj22in,proj23in,proj24in);
  
  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;

  constexpr unsigned int kNBitsBuffer=7;
  constexpr unsigned int kNMatchEngines=8;

  static ap_uint<kNBitsBuffer> writeindex[kNBitsBuffer]; //no fullmatch if not static, not passing to MEU?
#pragma HLS resource variable=writeindex core=RAM_2P_LUTRAM
#pragma HLS dependence variable=writeindex inter false
  static ap_uint<kNBitsBuffer> readindex=0;

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
  ap_uint<kNBits_MemAddrBinned> nstubs=0;
  ap_uint<kNBits_MemAddrBinned> istub=0;
  ap_uint<3> iphi = 0;

  ap_uint<kNBits_MemAddr> iproj=0; //counter

  //The next projection to read, the number of projections and flag if we have
  //more projections to read
  auto nproj=0;

  //const VMStubMEMemory<VMSMEType,3>* instubdata[kNMatchEngines] = {instubdata1, instubdata2, instubdata3, instubdata4, instubdata5, instubdata6, instubdata7, instubdata8};
  //ProjectionRouterBuffer<BARREL> projbuffer[kNMatchEngines][1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
  ProjectionRouterBufferArray<kNBitsBuffer> projbufferarray;//[kNMatchEngines];
  MatchEngineUnit<VMSMEType, BARREL, VMPTYPE> matchengine[kNMatchEngines];
#pragma HLS resource variable=matchengine core=RAM_2P_LUTRAM
//#pragma HLS ARRAY_PARTITION variable=matchengine complete dim=1
//#pragma HLS dependence variable=matchengine intra RAW true
#pragma HLS dependence variable=istub inter false 
//#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=1
  PROC_LOOP: for (int istep = 0; istep < kMaxProc-LoopItersCut; ++istep) {
#pragma HLS PIPELINE II=1 //rewind
    if (istep == 0) {

      // reset output memories & counters
      nallproj = 0;
    }
    //std::cout << "istep=" << istep << std::endl;

    // read inputs
    TrackletProjection<PROJTYPE> projdata;
    TrackletProjectionMemory<PROJTYPE> tproj;
    bool validin = read_input_mems<TrackletProjection<PROJTYPE>,
                                   TrackletProjectionMemory<PROJTYPE>,
                                   nINMEM, kNBits_MemAddr+1>
      (bx, mem_hasdata, numbersin, mem_read_addr,
       proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
       proj9in, proj10in, proj11in, proj12in, proj13in, proj14in, proj15in, proj16in,
       proj17in, proj18in, proj19in, proj20in, proj21in, proj22in, proj23in, proj24in,
       projdata, nproj);


    bool moreproj=iproj<nproj;

    if (validin) {
      auto iphiproj = projdata.getPhi();
      auto izproj = projdata.getRZ();
      auto iphider = projdata.getPhiDer();
      auto trackletid = projdata.getTCID();

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
      typename VMProjection<VMPTYPE>::VMPID index = nallproj;

      // vmproj z
      // Separate the vm projections into zbins
      // To determine which zbin in VMStubsME the ME should look in to match this VMProjection,
      // the purpose of these lines is to take the top MEBinsBits (3) bits of zproj and shift it
      // to make it positive, which gives the bin index. But there is a range of possible z values
      // over which we want to look for matched stubs, and there is therefore possibly 2 bins that
      // we will have to look in. So we first take the first MEBinsBits+zbins_nbitsextra (3+2=5)
      // bits of zproj, adjust the value up and down by zbins_adjust (2), then truncate the
      // zbins_adjust (2) LSBs to get the lower & upper bins that we need to look in.
      auto zbinposfull = (1<<(izproj.length()-1))+izproj;
      auto zbinpos5 = zbinposfull.range(izproj.length()-1,izproj.length()-MEBinsBits-zbins_nbitsextra);

      // Lower Bound
      auto zbinlower = zbinpos5<zbins_adjust ?
                       ap_uint<MEBinsBits+zbins_nbitsextra>(0) :
                       ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos5-zbins_adjust);
      // Upper Bound
      auto zbinupper = zbinpos5>((1<<(MEBinsBits+zbins_nbitsextra))-1-zbins_adjust) ? 
                       ap_uint<MEBinsBits+zbins_nbitsextra>((1<<(MEBinsBits+zbins_nbitsextra))-1) :
                       ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos5+zbins_adjust);

      ap_uint<MEBinsBits> zbin1 = zbinlower >> zbins_nbitsextra;
      ap_uint<MEBinsBits> zbin2 = zbinupper >> zbins_nbitsextra;
      
      typename VMProjection<VMPTYPE>::VMPZBIN zbin = (zbin1, zbin2!=zbin1);
    
      // VM Projection
      typename VMProjection<VMPTYPE>::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zbin1,ap_uint<3>(0));
 
      // vmproj irinv
      // phider = -irinv/2
      // Note: auto does not work well here
      // auto infers 42 bits because -2 is treated as a 32-bit int
      ap_uint<TrackletProjection<PROJTYPE>::BitWidths::kTProjPhiDSize+1> irinv_tmp = iphider * (-2);

      // rinv in VMProjection takes only the top 5 bits
      // and is shifted to be positive
      typename VMProjection<VMPTYPE>::VMPRINV rinv = (1<<(nbits_maxvm-1))+irinv_tmp.range(irinv_tmp.length()-1,irinv_tmp.length()-nbits_maxvm);

      ///////////////////////////////////
      //This is where Anders calls the ME
      ///////////////////////////////////
      //If we have more projections and the buffer is not full we read
      //next projection and put in buffer if there are stubs in the 
      //memory the projection points to

      //////////////////////////
      // hourglass configuration

      // number of bits used to distinguish the different modules in each layer/disk
      auto nbits_all = LAYER!=0 ? nbits_allstubslayers[LAYER-1] : nbits_allstubsdisks[DISK-1];

      // number of bits used to distinguish between VMs within a module
      auto nbits_vmme = LAYER!=0 ? nbits_vmmelayers[LAYER-1] : nbits_vmmedisks[DISK-1];

      // bits used for routing
      iphi = iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);
      ap_uint<kNBitsBuffer> writeindextmp=writeindex[iphi];
      ap_uint<kNBitsBuffer> readindextmp=readindex;

      bool buffernotfull=(writeindextmp+1!=readindextmp)&&(writeindextmp+2!=readindextmp);

      if (buffernotfull){
        auto const iprojtmp=iproj;
        iproj++;
        moreproj=iproj<nproj;
        if(iproj>=nproj) iproj=0;

        //The first and last zbin the projection points to
        ap_uint<TEBinsBits> zfirst=zbin.range(3,1);
        ap_uint<TEBinsBits> zlast=zfirst+zbin.range(0,0);
  
        ///////////////
        // VMProjection
        static_assert(not DISK, "PR: Layer only for now.");
  
        //Check if there are stubs in the memory
        ProjectionRouterBufferMemory<BARREL>::NEntryT nstubfirst;
        ProjectionRouterBufferMemory<BARREL>::NEntryT  nstublast;
        nstubfirst=instubdata[iphi].getEntries(bx,zfirst);
        nstublast= instubdata[iphi].getEntries(bx,zlast);
        /*
        switch (iphi) {
          break;
          case 0:  nstubfirst=instubdata1->getEntries(bx,zfirst);
                    nstublast=instubdata1->getEntries(bx,zlast);
          break;
          case 1:  nstubfirst=instubdata2->getEntries(bx,zfirst);
                    nstublast=instubdata2->getEntries(bx,zlast);
          break;
          case 2:  nstubfirst=instubdata3->getEntries(bx,zfirst);
                    nstublast=instubdata3->getEntries(bx,zlast);
          break;
          case 3:  nstubfirst=instubdata4->getEntries(bx,zfirst);
                    nstublast=instubdata4->getEntries(bx,zlast);
          break;
          case 4:  nstubfirst=instubdata5->getEntries(bx,zfirst);
                    nstublast=instubdata5->getEntries(bx,zlast);
          break;
          case 5:  nstubfirst=instubdata6->getEntries(bx,zfirst);
                    nstublast=instubdata6->getEntries(bx,zlast);
          break;
          case 6:  nstubfirst=instubdata7->getEntries(bx,zfirst);
                    nstublast=instubdata7->getEntries(bx,zlast);
          break;
          case 7:  nstubfirst=instubdata8->getEntries(bx,zfirst);
                    nstublast=instubdata8->getEntries(bx,zlast);
          break;
        }
        */
        bool savefirst=nstubfirst!=0;
        bool savelast=nstublast!=0&&zbin.range(0,0);
  
        if (savefirst&&savelast) {
  	  writeindex[iphi]=writeindextmp+2;
        } else if (savefirst||savelast) {
  	  writeindex[iphi]=writeindextmp+1;
        }
        VMProjection<BARREL> vmproj(index, zbin, finez, rinv, psseed);

        ProjectionRouterBuffer<BARREL> projbuffertmp;
        if (savefirst) { //FIXME code needs to be cleaner
          ProjectionRouterBuffer<BARREL>::PRHASSEC sec=0;
          //projbuffer[iphi][writeindextmp]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
          projbuffertmp=ProjectionRouterBuffer<BARREL>(trackletid, sec, nstubfirst, zfirst, vmproj, 0);
          projbuffertmp.setPhi(iphi);
          projbufferarray.add(projbuffertmp);
          //projbufferarray[iphi].add(projbuffertmp);
        }
        if (savelast) {
          if (savefirst) {
            ProjectionRouterBuffer<BARREL>::PRHASSEC sec=1;
            //projbuffer[iphi][writeindextmp+1]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            projbuffertmp=ProjectionRouterBuffer<BARREL>(trackletid, sec, nstublast, zlast, vmproj, psseed);
            projbuffertmp.setPhi(iphi);
            projbufferarray.add(projbuffertmp);
            //projbufferarray[iphi].add(projbuffertmp);
          } else {
            ProjectionRouterBuffer<BARREL>::PRHASSEC sec=1;
            //projbuffer[iphi][writeindextmp]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            projbuffertmp=ProjectionRouterBuffer<BARREL>(trackletid, sec, nstublast, zlast, vmproj, psseed);
            projbuffertmp.setPhi(iphi);
            projbufferarray.add(projbuffertmp);
            //projbufferarray[iphi].add(projbuffertmp);
          }
        }

      } // end if

      AllProjection<APTYPE> aproj(projdata.raw());
      allproj->write_mem(bx,aproj,nallproj);//(newtracklet && goodmatch==true && projseed==0)); // L1L2 seed
      nallproj++;

    } // end if(validin)

    MEU_LOOP: for(int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
      #pragma HLS unroll
      bool ready = false;
      bool idle = matchengine[iMEU].idle();
      bool done = matchengine[iMEU].done();
      bool empty = projbufferarray.empty();
      if(idle && !empty) {
        auto tmpprojbuff = projbufferarray.read();
        auto iphi = tmpprojbuff.getPhi();
        const VMStubMEMemory<VMSMEType,3> *instub = &(instubdata[iphi]);
        matchengine[iMEU].init(bx, tmpprojbuff, writeindex[iphi], iMEU);
        //matchengine[iphi].init(bx, projbufferarray[iphi].read(), instubdata[iphi], iphi, writeindex[iphi]);
      }
      if(!done) { 
        ready = matchengine[iMEU].step(table, instubdata);
        ready = matchengine[iMEU].ready();
      }

      if(ready) {
        typename VMProjection<BARREL>::VMPID projindex;
        typename MatchEngineUnit<VMSMEType, BARREL, VMPTYPE>::STUBID stubid;
        typename MatchEngineUnit<VMSMEType, BARREL, VMPTYPE>::NSTUBS nstubs;
        typename AllProjection<APTYPE>::AProjTCID currentTCID=-1;
        matchengine[iMEU].readNext(currentTCID, projindex, stubid);
        //std::cout << "Sending to MC projid=" << projindex << "\tstubid=" << stubid << std::endl;
        MatchCalculator<ASTYPE, APTYPE, VMSMEType, FMTYPE, maxFullMatchCopies, LAYER, PHISEC>
                  //(bx, allstub, allproj, matchengine[iMEU].getProjindex(), matchengine[iMEU].getStubIds(), matchengine[iMEU].getNStubs(), bx_o,
                  (bx, allstub, allproj, projindex, stubid, nstubs, bx_o,
                   nmcout1, nmcout2, nmcout3, nmcout4, nmcout5, nmcout6, nmcout7, nmcout8,
                   fullmatch);
      } //end MC if

    } //end MEU loop

  //} //end loop
  } //end loop


} // end MatchProcessor()



#endif
