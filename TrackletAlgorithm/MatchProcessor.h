#ifndef MATCHPROCESSOR_H
#define MATCHPROCESSOR_H

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
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
                   // bitmasks to indicate if memories are empty
                   ap_uint<nMEM>& mem_hasdata,
                   // number of entries for each memory
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
  //void read_inmem(DataType& data, MemType* datamem, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i, const MemType* const inmem)
  {
#pragma HLS inline
    
    if (read_imem == i) {
    //if (read_addr < inmem->getEntries(bx)) {
      data = inmem->read_mem(bx, read_addr);
      //datamem->write_mem(bx, data, i);
    }
  }

  template<class DataType, class MemType, class... Args>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
  //void read_inmem(DataType& data, MemType* datamem, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i,
                  const MemType* const inmem, Args... args)
  {
    if (read_imem == i) {
    //if (read_addr < inmem->getEntries(bx)) {
      data = inmem->read_mem(bx, read_addr);
      //datamem->write_mem(bx, data, i);
    }
    read_inmem(data, bx, read_imem, read_addr, i+1, args...);
    //read_inmem(data, datamem, bx, read_imem, read_addr, i+1, args...);
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
                       //DataType& data, MemType* datamem)
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

  // number of allstub memories for each layer
  constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
  // number of VMs in one allstub block for each layer
  constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

  // number of allstub memories for each disk
  constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
  
  // number of VMs in one allstub block for each disk
  constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};

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

  if (L==2) {
    bool tmp[256]=
#include "../emData/ME/tables/METable_L2.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

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
#include "../emData/MC/MC_L3PHIC/MC_L1PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L2PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L4PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L5PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L6PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else { // z cuts
    if (L==1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L1PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L2PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L4PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L5PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L6PHIC_zcut.tab"
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

template<regionType ASTYPE, regionType APTYPE, regionType VMSMEType, regionType FMTYPE, int LAYER=0, int PHISEC=0>
void MatchCalculator(BXType bx,
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjectionMemory<APTYPE>* allproj,
                     ap_uint<VMProjectionBase<BARREL>::kVMProjIndexSize> projid,
                     //const typename VMProjection<BARREL>::VMPID projid,
                     ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize> *stubids,
                     int nstubs,
                     //const typename VMStubMEMemory<VMSMEType>::VMSMEID stubid,
                     BXType& bx_o,
                     int &nmcout1,
                     int &nmcout2,
                     int &nmcout3,
                     int &nmcout4,
                     int &nmcout5,
                     int &nmcout6,
                     int &nmcout7,
                     int &nmcout8,
                     int &noutcandmatch,
                     FullMatchMemory<FMTYPE>* fullmatch1,
                     FullMatchMemory<FMTYPE>* fullmatch2,
                     FullMatchMemory<FMTYPE>* fullmatch3,
                     FullMatchMemory<FMTYPE>* fullmatch4,
                     FullMatchMemory<FMTYPE>* fullmatch5,
                     FullMatchMemory<FMTYPE>* fullmatch6,
                     FullMatchMemory<FMTYPE>* fullmatch7,
                     FullMatchMemory<FMTYPE>* fullmatch8,
		     CandidateMatchMemory* outcandmatch
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

  // Loop one past nstubs for pipelining
  MC_LOOP: for (int istub = 0; istub < kMaxProc-PR::LoopItersCut; ++istub) {
#pragma HLS PIPELINE II=1
  //MC_LOOP: for (int istub = 0; istub <= nstubs+1; ++istub) {

    // Don't read past nstubs (would read garbage)
    int istubtmp = istub > nstubs ? istub : nstubs;
    auto stubid = stubids[istub];
    CandidateMatch cmatch(projid.concat(stubid));
    /* FIXME
    std::cout << std::hex << "MC received cmatch=" << cmatch.raw() << std::endl;
    std::cout << std::hex << "MC received projid=" << projid << " stubid=" << stubid << std::endl;
    */
  
    // Use the stub and projection indices to pick up the stub and projection
    AllProjection<APTYPE> proj = allproj->read_mem(bx,projid);
    AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);
    /* FIXME
    std::cout << "proj=" << proj.raw() << std::endl;
    std::cout << "stub=" << stub.raw() << std::endl;
    */
  
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
    /* FIXME
    std::cout << "projstub=" << std::bitset<7>(projid) << "\t" << std::bitset<7>(stubid) << std::endl;
    std::cout << std::hex << "fm=" << fm.raw() << std::endl;
    std::cout << std::bitset<7>(fm_tcid) << "|"
              << std::bitset<7>(fm_tkid) << "|"
              << std::bitset<3>(fm_asphi)
              << std::bitset<7>(fm_asid) << "|"
              << std::bitset<12>(fm_phi) << "|"
              << std::bitset<9>(fm_z) << std::endl;
    */
  
    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
    //-----------------------------------------------------------------------------------------------------------
  
    typename AllProjection<APTYPE>::AProjTCSEED projseed_next;
    FullMatch<FMTYPE> bestmatch_next = FullMatch<FMTYPE>();
    bool goodmatch_next              = false;
  
    bool newtracklet = (istub==0 || istub>nstubs) ? true : false;
    /* FIXME
    std::cout << "new tracklet " << newtracklet << std::endl;
    std::cout << std::hex << "bestmatch=" << bestmatch.raw() << std::endl;
    std::cout << std::hex << "goodmatch=" << goodmatch << std::endl;
    */
  
    // For first tracklet, pick up the phi cut value
    best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;
  
    // Check that matches fall within the selection window of the projection 
    //bool match = (abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= LUT_matchcut_phi[proj_seed]);
    //bool match = (abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi);
    if ((abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi)){
      //std::cout << "match found!" << std::endl;
      // Update values of best phi parameters, so that the next match
      // will be compared to this value instead of the original selection cut
      best_delta_phi = abs_delta_phi;
  
      // Store bestmatch
      bestmatch_next = fm;
      goodmatch_next = true;
      projseed_next  = proj_seed;
    }
    else if (newtracklet){ // if is a new tracklet, do not make a match because it didn't pass the cuts
    //std::cout << "else new tracklet " << newtracklet << std::endl;
      bestmatch_next = FullMatch<FMTYPE>();
      goodmatch_next = false;
      projseed_next  = -1;
    }
    else { // if current match did not pass, but it is not a new tracklet, keep the previous best match for that tracklet
      //std::cout << "not new tracklet" << std::endl;
      bestmatch_next = bestmatch;
      goodmatch_next = goodmatch;
      projseed_next  = projseed;
    }
  
    if (0){
      // Reset output memories
      fullmatch1->clear(bx);
      fullmatch2->clear(bx);
      fullmatch3->clear(bx);
      fullmatch4->clear(bx);
      fullmatch5->clear(bx);
      fullmatch6->clear(bx);
      fullmatch7->clear(bx);
      fullmatch8->clear(bx);
    }
    else if(newtracklet && goodmatch==true) { // Write out only the best match, based on the seeding 
      //std::cout << "writing " << bestmatch.raw() << std::endl;
      //outcandmatch->write_mem(bx,cmatch,noutcandmatch);
      //noutcandmatch++;
      switch (projseed) {
      case 0:
      fullmatch1->write_mem(bx,bestmatch,nmcout1);//(newtracklet && goodmatch==true && projseed==0)); // L1L2 seed
      nmcout1++;
      break;
      case 1:
      fullmatch2->write_mem(bx,bestmatch,nmcout2);//(newtracklet && goodmatch==true && projseed==1)); // L3L4 seed
      nmcout2++;
      break;
      case 2:
      fullmatch3->write_mem(bx,bestmatch,nmcout3);//(newtracklet && goodmatch==true && projseed==2)); // L5L6 seed
      nmcout3++;
      break;
      case 3:
      fullmatch4->write_mem(bx,bestmatch,nmcout4);//(newtracklet && goodmatch==true && projseed==3)); // D1D2 seed
      nmcout4++;
      break;
      case 4:
      fullmatch5->write_mem(bx,bestmatch,nmcout5);//(newtracklet && goodmatch==true && projseed==4)); // D3D4 seed
      nmcout5++;
      break;
      case 5:
      fullmatch6->write_mem(bx,bestmatch,nmcout6);//(newtracklet && goodmatch==true && projseed==5)); // L1D1 seed
      nmcout6++;
      break;
      case 6:
      fullmatch7->write_mem(bx,bestmatch,nmcout7);//(newtracklet && goodmatch==true && projseed==6)); // L2D1 seed
      nmcout7++;
      break;
      case 7:
      fullmatch8->write_mem(bx,bestmatch,nmcout8);//(newtracklet && goodmatch==true && projseed==7)); // L2D1 seed
      nmcout8++;
      break;
      }
    }
  
    // pipeline the bestmatch registers
    bestmatch      = bestmatch_next;
    goodmatch      = goodmatch_next;
    projseed       = projseed_next;
  
    bx_o = bx;
    
  } //end istub
} //end MC


//////////////////////////////
// MatchProcessor
template<int L, regionType PROJTYPE, regionType VMSMEType, regionType VMPTYPE, regionType ASTYPE, regionType APTYPE, regionType FMTYPE, unsigned int nINMEM,
         int LAYER=0, int DISK=0, int PHISEC=0>
void MatchProcessor(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
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
                      const VMStubMEMemory<VMSMEType>* instubdata1,
                      const VMStubMEMemory<VMSMEType>* instubdata2,
                      const VMStubMEMemory<VMSMEType>* instubdata3,
                      const VMStubMEMemory<VMSMEType>* instubdata4,
                      const VMStubMEMemory<VMSMEType>* instubdata5,
                      const VMStubMEMemory<VMSMEType>* instubdata6,
                      const VMStubMEMemory<VMSMEType>* instubdata7,
                      const VMStubMEMemory<VMSMEType>* instubdata8,
                      const AllStubMemory<ASTYPE>* allstub,
                      const AllProjectionMemory<APTYPE>* allproj,
                      BXType& bx_o,
                      FullMatchMemory<FMTYPE>* fullmatch1,
                      FullMatchMemory<FMTYPE>* fullmatch2,
                      FullMatchMemory<FMTYPE>* fullmatch3,
                      FullMatchMemory<FMTYPE>* fullmatch4,
                      FullMatchMemory<FMTYPE>* fullmatch5,
                      FullMatchMemory<FMTYPE>* fullmatch6,
                      FullMatchMemory<FMTYPE>* fullmatch7,
                      FullMatchMemory<FMTYPE>* fullmatch8,
                         VMProjectionMemory<BARREL>* vmprojout1,
                         VMProjectionMemory<BARREL>* vmprojout2,
                         VMProjectionMemory<BARREL>* vmprojout3,
                         VMProjectionMemory<BARREL>* vmprojout4,
                         VMProjectionMemory<BARREL>* vmprojout5,
                         VMProjectionMemory<BARREL>* vmprojout6,
                         VMProjectionMemory<BARREL>* vmprojout7,
                         VMProjectionMemory<BARREL>* vmprojout8,
                         int &noutcandmatch,
		         CandidateMatchMemory* outcandmatch
){
#pragma HLS inline

#ifndef __SYNTHESIS__
  //Prinout of number of projections and stubs
  //std::cout << "In MatchrProcessor #stubs=";
  /*
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata1->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;
  */
#endif

  using namespace PR;

  //Initialize table for bend-rinv consistency
  bool table[(L<4)?256:512]; //FIXME Need to figure out how to replace 256 with meaningful const.
  readTable<L>(table);
  
/*
#pragma HLS resource variable=instubdata1 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata2 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata3 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata4 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata5 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata6 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata7 core=RAM_2P_LUTRAM
#pragma HLS resource variable=instubdata8 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch1 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch2 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch3 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch4 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch5 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch6 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch7 core=RAM_2P_LUTRAM
#pragma HLS resource variable=fullmatch8 core=RAM_2P_LUTRAM
*/
  // reset output memories
  fullmatch1->clear(bx);
  fullmatch2->clear(bx);
  fullmatch3->clear(bx);
  fullmatch4->clear(bx);
  fullmatch5->clear(bx);
  fullmatch6->clear(bx);
  fullmatch7->clear(bx);
  fullmatch8->clear(bx);

  vmprojout1->clear(bx);
  vmprojout2->clear(bx);
  vmprojout3->clear(bx);
  vmprojout4->clear(bx);
  vmprojout5->clear(bx);
  vmprojout6->clear(bx);
  vmprojout7->clear(bx);
  vmprojout8->clear(bx);
  outcandmatch->clear(bx);

  // initialization:
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  ap_uint<nINMEM> mem_hasdata = 0;
#pragma HLS dependence variable=mem_hasdata inter RAW true
  ap_uint<kNBits_MemAddr+1> numbersin[nINMEM];
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0

  //init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
  init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
    (bx, mem_hasdata, numbersin,0,
     proj1in,proj2in,proj3in,proj4in,proj5in,proj6in,proj7in,proj8in,
     proj9in,proj10in,proj11in,proj12in,proj13in,proj14in,proj15in,proj16in,
     proj17in,proj18in,proj19in,proj20in,proj21in,proj22in,proj23in,proj24in);
  
  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;

  constexpr unsigned int kNBitsBuffer=7;
  constexpr unsigned int kNMatchEngines=8;
  constexpr int kNBits_ProjBuffer =kNBits_MemAddrBinned + VMProjectionBase<BARREL>::kVMProjectionSize + 1 +kNBits_z +1;

  ap_uint<kNBitsBuffer> writeindex[kNBitsBuffer];
  //ap_uint<kNBitsBuffer> writeindextmp[kNBitsBuffer];
//#pragma HLS resource variable=writeindex core=RAM_2P_LUTRAM
//#pragma HLS resource variable=writeindextmp core=RAM_2P_LUTRAM
#pragma HLS RESOURCE variable=writeindex core=XPM_MEMORY uram
//#pragma HLS RESOURCE variable=writeindextmp core=XPM_MEMORY uram
#pragma HLS dependence variable=writeindex inter false
  ap_uint<kNBitsBuffer> readindex=0;

  // declare counters for each of the 8 output VMProj // !!!
  int nvmprojout1 = 0;
  int nvmprojout2 = 0;
  int nvmprojout3 = 0;
  int nvmprojout4 = 0;
  int nvmprojout5 = 0;
  int nvmprojout6 = 0;
  int nvmprojout7 = 0;
  int nvmprojout8 = 0;  
  int nallproj = 0;

  // declare counters for each of the 8 output VMProj // !!!
  int nmcout1 = 0;
  int nmcout2 = 0;
  int nmcout3 = 0;
  int nmcout4 = 0;
  int nmcout5 = 0;
  int nmcout6 = 0;
  int nmcout7 = 0;
  int nmcout8 = 0;  


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

    //ap_uint<kNBits_ProjBuffer> projbuffer[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> projbuffer[kNMatchEngines][1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=1
    /*
PRAG_LOOP: for(int i = 0; i < kNMatchEngines; ++i) 
#pragma HLS resource variable=projbuffer[i] core=RAM_2P_LUTRAM
    ProjectionRouterBuffer<BARREL> *projbuffer1[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer2[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer3[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer4[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer5[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer6[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer7[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBuffer<BARREL> *projbuffer8[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
    ProjectionRouterBufferMemory<BARREL> projbuffermem;  //projbuffer = nstub+projdata+finez
    */
//#pragma HLS resource variable=projbuffer core=RAM_2P_LUTRAM
//#pragma HLS dependence variable=istub intra WAR true
        //std::cout << "PR stage" << std::endl;
  PROC_LOOP: for (int istep = 0; istep < kMaxProc-LoopItersCut; ++istep) {
#pragma HLS PIPELINE II=1
#pragma HLS loop_flatten
//#pragma HLS unroll

    // read inputs
    TrackletProjection<PROJTYPE> projdata;
    TrackletProjectionMemory<PROJTYPE> tproj;
    //bool validin = read_input_mems<VMProjectionMemory<BARREL>,
//#pragma HLS dependence variable=mem_read_addr intra WAR true
    bool validin = read_input_mems<TrackletProjection<PROJTYPE>,
                                   TrackletProjectionMemory<PROJTYPE>,
                                   nINMEM, kNBits_MemAddr+1>
      (bx, mem_hasdata, numbersin, mem_read_addr,
       proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
       proj9in, proj10in, proj11in, proj12in, proj13in, proj14in, proj15in, proj16in,
       proj17in, proj18in, proj19in, proj20in, proj21in, proj22in, proj23in, proj24in,
       projdata, nproj);
       //projdata, &tproj);

    /*
    nproj=0;
    for(ap_uint<kNBits_MemAddr+1> inMEM=0; inMEM<nINMEM; ++inMEM)
      nproj+=numbersin[inMEM];
    std::cout << "iproj=" << iproj << "\tnproj=" << nproj << std::endl;

    nproj=0;
          if(proj1in!=nullptr) nproj += proj1in->getEntries(bx);
          if(proj2in!=nullptr) nproj += proj2in->getEntries(bx);
          if(proj3in!=nullptr) nproj += proj3in->getEntries(bx);
          if(proj4in!=nullptr) nproj += proj4in->getEntries(bx);
          if(proj5in!=nullptr) nproj += proj5in->getEntries(bx);
          if(proj6in!=nullptr) nproj += proj6in->getEntries(bx);
          if(proj7in!=nullptr) nproj += proj7in->getEntries(bx);
          if(proj8in!=nullptr) nproj += proj8in->getEntries(bx);
          if(proj9in!=nullptr) nproj += proj9in->getEntries(bx);
          if(proj10in!=nullptr) nproj += proj10in->getEntries(bx);
          if(proj11in!=nullptr) nproj += proj11in->getEntries(bx);
          if(proj12in!=nullptr) nproj += proj12in->getEntries(bx);
          if(proj13in!=nullptr) nproj += proj13in->getEntries(bx);
          if(proj14in!=nullptr) nproj += proj14in->getEntries(bx);
          if(proj15in!=nullptr) nproj += proj15in->getEntries(bx);
          if(proj16in!=nullptr) nproj += proj16in->getEntries(bx);
          if(proj17in!=nullptr) nproj += proj17in->getEntries(bx);
          if(proj18in!=nullptr) nproj += proj18in->getEntries(bx);
          if(proj19in!=nullptr) nproj += proj19in->getEntries(bx);
          if(proj20in!=nullptr) nproj += proj20in->getEntries(bx);
          if(proj21in!=nullptr) nproj += proj21in->getEntries(bx);
          if(proj22in!=nullptr) nproj += proj22in->getEntries(bx);
          if(proj23in!=nullptr) nproj += proj23in->getEntries(bx);
          if(proj24in!=nullptr) nproj += proj24in->getEntries(bx);
    */

    bool moreproj=iproj<nproj;

    if (validin) {

      auto iphiproj = projdata.getPhi();
      auto izproj = projdata.getRZ();
      auto iphider = projdata.getPhiDer();
      auto trackletid = projdata.getTCID();
      //std::cout << std::hex << "projdata=" << projdata.raw() << std::endl;

      // PS seed
      // top 3 bits of tracklet index indicate the seeding pair
      ap_uint<3> iseed = trackletid >> (trackletid.length()-3);
      // Cf. https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATrackletCalculator.hh#L166
      // and here?
      // https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATracklet.hh#L1621
      // NOTE: emulation fw_synch branch does not include L2L3 seeding; the master branch does

      // All seeding pairs are PS modules except L3L4 and L5L6
      bool psseed = not(iseed==1 or iseed==2); 
  
      //////////////////////////
      // hourglass configuration
     
      // top 5 bits of phi
      auto iphi5 = iphiproj>>(iphiproj.length()-5);

      // vmproj z
      // Separate the vm projections into zbins
      // The central bin e.g. zbin=4+(zproj.value()>>(zproj.nbits()-3));
      // (assume 8 bins; take top 3 bits of zproj and shift it to make it positive)
      // But we need some range (particularly for L5L6 seed projecting to L1-L3):
      // Lower bound
      ap_uint<MEBinsBits+1> zbin1tmp = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))-2)>>2);
      // Upper bound
      ap_uint<MEBinsBits+1> zbin2tmp = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))+2)>>2);
      if (zbin1tmp >= (1<<MEBinsBits)) zbin1tmp = 0; //note that zbin1 is unsigned
      if (zbin2tmp >= (1<<MEBinsBits)) zbin2tmp = (1<<MEBinsBits)-1;

      // One extra bit was used in the above calculation. Now take it away.
      ap_uint<MEBinsBits> zbin1 = zbin1tmp;
      ap_uint<MEBinsBits> zbin2 = zbin2tmp;
    
      typename VMProjection<VMPTYPE>::VMPZBIN projzbin = (zbin1, zbin2!=zbin1);
      // VM Projection
      typename VMProjection<VMPTYPE>::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zbin1,ap_uint<3>(0));
 
      // vmproj irinv
      // phider = -irinv/2
      // Note: auto does not work well here
      // auto infers 42 bits because -2 is treated as a 32-bit int
      ap_uint<TrackletProjection<PROJTYPE>::BitWidths::kTProjPhiDSize+1> irinv_tmp = iphider * (-2);

      // rinv in VMProjection takes only the top 5 bits
      // and is shifted to be positive
      typename VMProjection<VMPTYPE>::VMPRINV rinv = 16+(irinv_tmp>>(irinv_tmp.length()-5));
      /* FIXME
      {
        VMProjection<BARREL> vmproj(istep, projzbin, finez, rinv, psseed);
        std::cout << std::hex << "projid=" << vmproj.getIndex() << std::endl;
        //std::cout << std::hex << "vmproj=" << vmproj.raw() << std::endl;
      }
      */

      ///////////////////////////////////
      //This is where Anders calls the ME
      ///////////////////////////////////
      //If we have more projections and the buffer is not full we read
      //next projection and put in buffer if there are stubs in the 
      //memory the projection points to

      //auto iphiproj = allproj->read_mem(bx, istep).getPhi();
      //auto iphi5 = iphiproj>>(iphiproj.length()-5);
  constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};
  constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
  constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};
      auto nvm = LAYER!=0 ? nvmmelayers[LAYER-1]*nallstubslayers[LAYER-1] :
        nvmmedisks[DISK-1]*nallstubsdisks[DISK-1];
      auto nbins = LAYER!=0 ? nvmmelayers[LAYER-1] : nvmmedisks[DISK-1];
       iphi = (iphi5/(32/nvm))&(nbins-1);  // OPTIMIZE ME
       ap_uint<kNBitsBuffer> writeindextmp=writeindex[iphi];

        //if(iphi<6) continue;
      //prefetch and calculate write pointers for buffer
/*
      ap_uint<kNBitsBuffer> writeindexplus=writeindex[iphi]+1;
#pragma HLS dependence variable=writeindexplus inter RAW true 
      ap_uint<kNBitsBuffer> writeindexplusplus=writeindex[iphi]+2;
#pragma HLS dependence variable=writeindexplusplus inter RAW true 
*/
  
      //Determine if buffere is full - or near full as a projection
      //can point to two z bins we might fill two slots in the buffer
      bool buffernotfull=(writeindextmp+1!=readindex)&&(writeindextmp+2!=readindex);
      //bool buffernotfull=(writeindex[iphi]+1!=readindex)&&(writeindex[iphi]+2!=readindex);
      //bool buffernotfull=(writeindexplus!=readindex)&&(writeindexplusplus!=readindex);
      //bool buffernotfull=(writeindexplus!=nproj)&&(writeindexplusplus!=nproj);
      /*
      {
      auto iphiproj = allproj->read_mem(bx, istep).getPhi();
      auto iphi5 = iphiproj>>(iphiproj.length()-5);
        if(iphi!=ivmphi) continue;
  constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};
  constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
  constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};
      auto nvm = LAYER!=0 ? nvmmelayers[LAYER-1]*nallstubslayers[LAYER-1] :
        nvmmedisks[DISK-1]*nallstubsdisks[DISK-1];
      auto nbins = LAYER!=0 ? nvmmelayers[LAYER-1] : nvmmedisks[DISK-1];
      ap_uint<3> iphi = (iphi5/(32/nvm))&(nbins-1);  // OPTIMIZE ME
        if(iphi==3 || 1) {
        VMProjection<BARREL> vmproj(istep, projzbin, finez, rinv, psseed);
        std::cout << "buffernotfull=" << buffernotfull << std::endl;
        std::cout << "moreproj=" << moreproj << std::endl;
        std::cout << "sending to buffer" <<  std::endl;
        std::cout << std::hex << "vmproj=" << vmproj.raw() << std::endl;
        std::cout << std::hex << "vmproj=" << std::bitset<VMProjectionBase<BARREL>::kVMProjectionSize>( vmproj.raw() ) << std::endl;
    std::cout << std::dec << std::bitset<VMProjectionBase<BARREL>::kVMProjIndexSize>(vmproj.getIndex()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjZBinSize>(vmproj.getZBin()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjFineZSize>(vmproj.getFineZ()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjRinvSize>(vmproj.getRInv()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjIsPSSeedSize>(vmproj.getIsPSSeed()) << std::endl << std::endl;
    std::cout << std::dec << "getIndex=" << vmproj.getIndex() << std::endl;
    std::cout << std::hex << "getZBin=" << vmproj.getZBin() << std::endl;
    std::cout << std::hex << "getFineZ=" << vmproj.getFineZ() << std::endl;
    std::cout << std::hex << "getRInv=" << vmproj.getRInv() << std::endl;
    std::cout << std::hex << "getIsPSSeed=" << vmproj.getIsPSSeed() << std::endl << std::endl;
    std::cout << std::dec <<  "index[iphi]=" << istep << std::endl
              << std::hex << "projfinez=" << finez << std::endl
              << "rinv=" << rinv << std::endl
              << "isPSSeed=" << isPSseed << std::endl << std::endl;
        std::cout << "###" << std::endl;
        std::cout << std::hex << "writeindex[iphi]=" << writeindex << "\treadindex[iphi]=" << readindex << std::endl;
        }
      }
      */

      if (buffernotfull){
      //if (moreproj&&buffernotfull){
        auto const iprojtmp=iproj;
        iproj++;
        moreproj=iproj<nproj;
        if(iproj>=nproj) iproj=0;

        //The first and last zbin the projection points to
        ap_uint<TEBinsBits> zfirst=projzbin.range(3,1);
        ap_uint<TEBinsBits> zlast=zfirst+projzbin.range(0,0);
      /* FIXME
      std::cout << "zfirst=" << zfirst << "\t"
                << "zlast=" << zlast << std::endl;
      */
  
        ///////////////
        // VMProjection
        static_assert(not DISK, "PR: Layer only for now.");
  
        //Check if there are stubs in the memory
        ProjectionRouterBufferMemory<BARREL>::NEntryT nstubfirst;
        ProjectionRouterBufferMemory<BARREL>::NEntryT  nstublast;
        switch (iphi) {
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
      /* FIXME
      std::cout << "nstubfirst=" << nstubfirst << "\t"
                << "nstublast=" << nstublast << std::endl;
      */
        bool savefirst=nstubfirst!=0;
        bool savelast=nstublast!=0&&projzbin.range(0,0);
//#pragma HLS dependence variable=writeindextmp inter false 
        //auto const writeindextmp=writeindex[iphi];
        //if(projdata.raw() == 0) {savefirst=0; savelast=0;} //FIXME cathing blank entries
      {
      /* FIXME
        if(iphi==3 && 1) {
        VMProjection<BARREL> vmproj(istep, projzbin, finez, rinv, psseed);
        std::cout << "written to buffer address=" << writeindextmp <<  std::endl;
        std::cout << "zbin=" << projzbin << std::endl;
        std::cout << std::hex << "data=" << vmproj.raw() << std::endl;
        std::cout << std::hex << "vmproj=" << std::bitset<VMProjectionBase<BARREL>::kVMProjectionSize>( vmproj.raw() ) << std::endl;
    std::cout << std::dec << std::bitset<VMProjectionBase<BARREL>::kVMProjIndexSize>(vmproj.getIndex()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjZBinSize>(vmproj.getZBin()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjFineZSize>(vmproj.getFineZ()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjRinvSize>(vmproj.getRInv()) << " "
              << std::bitset<VMProjectionBase<BARREL>::kVMProjIsPSSeedSize>(vmproj.getIsPSSeed()) << std::endl << std::endl;
    std::cout << std::dec << "getIndex=" << vmproj.getIndex() << std::endl;
    std::cout << std::hex << "getZBin=" << vmproj.getZBin() << std::endl;
    std::cout << std::hex << "getFineZ=" << vmproj.getFineZ() << std::endl;
    std::cout << std::hex << "getRInv=" << vmproj.getRInv() << std::endl;
    std::cout << std::hex << "getIsPSSeed=" << vmproj.getIsPSSeed() << std::endl << std::endl;
    std::cout << std::dec <<  "index[iphi]=" << istep << std::endl
              << std::hex << "projfinez=" << finez << std::endl
              << "rinv=" << rinv << std::endl
              << "isPSSeed=" << isPSseed << std::endl << std::endl;
        std::cout << "###" << std::endl;
        std::cout << std::hex << "\treadindex[iphi]=" << readindex << std::endl;
        }
      */
      }
  
        if (savefirst&&savelast) {
  	  //writeindex[iphi]=writeindex[iphi]+2;
  	  writeindex[iphi]=writeindextmp+2;
  	  //writeindex[iphi]=writeindexplusplus;
        } else if (savefirst||savelast) {
  	  //writeindex[iphi]=writeindex[iphi]+1;
  	  writeindex[iphi]=writeindextmp+1;
  	  //writeindex[iphi]=writeindexplus;
        }
        VMProjection<BARREL> vmproj(istep, projzbin, finez, rinv, psseed);
        /* FIXME
      if(!savefirst && !savelast) std::cout << std::hex << "vmproj=" << vmproj.raw() << " nstubfirst=" << nstubfirst << " nstublast=" << nstublast << " projzbin[0]=" << projzbin.range(0,0) << " zfirst=" << zfirst << " zlast=" << zlast << std::endl;
        if(!savefirst && !savelast) {
        std::cout << "Printing mem" << std::endl;
        switch (iphi) {
          case 0:  instubdata1->print_mem(bx);
          break;
          case 1:  instubdata2->print_mem(bx);
          break;
          case 2:  instubdata3->print_mem(bx);
          break;
          case 3:  instubdata4->print_mem(bx);
          break;
          case 4:  instubdata5->print_mem(bx);
          break;
          case 5:  instubdata6->print_mem(bx);
          break;
          case 6:  instubdata7->print_mem(bx);
          break;
          case 7:  instubdata8->print_mem(bx);
          break;
        }
        std::cout << "Done!" << std::endl;
        }
      //std::cout << savefirst << savelast << std::endl;
        std::cout << "writeindextmp=" << writeindextmp << std::endl;
        std::cout << "writeindex[" << iphi << "]=" << writeindex[iphi] << std::endl;
        std::cout << std::hex << "projid=" << vmproj.getIndex() << std::endl;
        */

        if(savefirst || savelast) {
          switch(iphi) {
            case 0: vmprojout1->write_mem(bx, vmproj, nvmprojout1);
            nvmprojout1++;
            break;
            case 1: vmprojout2->write_mem(bx, vmproj, nvmprojout2);
            nvmprojout2++;
            break;
            case 2: vmprojout3->write_mem(bx, vmproj, nvmprojout3);
            nvmprojout3++;
            break;
            case 3: vmprojout4->write_mem(bx, vmproj, nvmprojout4);
            nvmprojout4++;
            break;
            case 4: vmprojout5->write_mem(bx, vmproj, nvmprojout5);
            nvmprojout5++;
            break;
            case 5: vmprojout6->write_mem(bx, vmproj, nvmprojout6);
            nvmprojout6++;
            break;
            case 6: vmprojout7->write_mem(bx, vmproj, nvmprojout7);
            nvmprojout7++;
            break;
            case 7: vmprojout8->write_mem(bx, vmproj, nvmprojout8);
            nvmprojout8++;
            break;
          }
        }
        /*
        */
        if (savefirst) { //FIXME code needs to be cleaner
          ProjectionRouterBuffer<BARREL>::PRHASSEC sec=0;
            /* FIXME
            std::cout << "PRiphi=" << iphi << std::endl;
            std::cout << "save first" << std::endl;
            */
      //std::cout << std::hex << "iphi=" << iphi+1 << " vmproj=" << vmproj.raw() << std::endl;
          projbuffer[iphi][writeindextmp]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
        /*
          switch (iphi) {
            case 0: projbuffer1[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 1: projbuffer2[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 2: projbuffer3[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 3: projbuffer4[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 4: projbuffer5[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 5: projbuffer6[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 6: projbuffer7[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
            case 7: projbuffer8[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
            break;
          }
          projbuffer8[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstubfirst, zfirst, vmproj.raw(), 0);
        */
          //projbuffermem.write_mem(bx, *projbuffer[0][writeindextmp], writeindextmp);
        //std::cout << std::hex << "proj=" << projbuffer[writeindextmp]->raw() << std::endl;
        //std::cout << "who's proj=" << projbuffer[writeindextmp]->getProjection() << std::endl;
        /* FIXME
        */
        }
        if (savelast) {
          if (savefirst) {
            ProjectionRouterBuffer<BARREL>::PRHASSEC sec=1;
            projbuffer[iphi][writeindextmp+1]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            //projbuffer[iphi][writeindextmpplus]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstublast, zlast, vmproj.raw(), psseed);
        /*
          switch (iphi) {
            case 0: projbuffer1[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 1: projbuffer2[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 2: projbuffer3[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 3: projbuffer4[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 4: projbuffer5[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 5: projbuffer6[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 6: projbuffer7[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 7: projbuffer8[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
          }
            projbuffer8[writeindextmpplus]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
        */
        //std::cout << std::hex << "proj=" << projbuffer[writeindextmpplus]->raw() << std::endl;
        //std::cout << "who's proj=" << projbuffer[writeindextmpplus]->getProjection() << std::endl;
        /* FIXME
        std::cout << std::hex << "and vmproj=" << vmproj.raw() << std::endl;
        */
          //projbuffermem.write_mem(bx, *projbuffer[writeindextmpplus], writeindextmpplus);
          } else {
            ProjectionRouterBuffer<BARREL>::PRHASSEC sec=1;
            projbuffer[iphi][writeindextmp]=ProjectionRouterBuffer<BARREL>(trackletid, sec, istep, nstublast, zlast, vmproj.raw(), psseed);
          /*
          switch (iphi) {
            case 0: projbuffer1[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 1: projbuffer2[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 2: projbuffer3[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 3: projbuffer4[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 4: projbuffer5[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 5: projbuffer6[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 6: projbuffer7[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
            case 7: projbuffer8[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
            break;
          }
            projbuffer8[writeindextmp]=new ProjectionRouterBuffer<BARREL>(sec, istep, nstublast, zlast, vmproj.raw(), psseed);
          */
          //projbuffermem.write_mem(bx, *projbuffer[0][writeindextmp], writeindextmp);
        //std::cout << std::hex << "who's proj=" << projbuffer[writeindextmp]->getProjection() << std::endl;
        //std::cout << std::hex << "writeing proj=" << projbuffer[writeindextmp]->raw() << std::endl;
        /* FIXME
        */
          }
        }

      } // end if
      //std::cout << std::hex << "moreproj/buffernotfull" << " " << moreproj << " " << buffernotfull << std::endl;

/*
*/
    } // end if(validin)

  } //end loop

  //std::cout << "Starting ME loop" << std::endl;
  readindex=0;
  MatchEngineUnit<VMSMEType, BARREL, VMPTYPE> matchengine[kNMatchEngines];
#pragma HLS dependence variable=istub inter false 
#pragma HLS resource variable=matchengine core=RAM_2P_LUTRAM
//#pragma HLS ARRAY_PARTITION variable=matchengine complete dim=0
  MEINIT_LOOP: for(int iphi = 0; iphi < kNMatchEngines; ++iphi) {
#pragma HLS unroll
/*
    const VMStubMEMemory<VMSMEType>* instubdata;
    switch (iphi) {
      case 0: instubdata=instubdata1;
      break;
      case 1: instubdata=instubdata2;
      break;
      case 2: instubdata=instubdata3;
      break;
      case 3: instubdata=instubdata4;
      break;
      case 4: instubdata=instubdata5;
      break;
      case 5: instubdata=instubdata6;
      break;
      case 6: instubdata=instubdata7;
      break;
      case 7: instubdata=instubdata8;
      break;
    }
*/
    matchengine[iphi].init(bx, writeindex[iphi], iphi);
  }

  int iMEbest=kNMatchEngines;
  typename AllProjection<APTYPE>::AProjTCID bestTCID=-1;
  bool bestInPipeline=false;
  ap_uint<3> ivmphi=0;
  ME_LOOP: for (int istep = 0; istep < kMaxProc-LoopItersCut; ++istep) {
  bool ready=false;
//#pragma HLS PIPELINE II=1
#pragma HLS loop_flatten
    /*
    MEPHI_LOOP: for(int ivmphi = 0; ivmphi < kNMatchEngines; ++ivmphi) {
#pragma HLS PIPELINE II=1
#pragma HLS unroll
    switch (ivmphi) {
      case 0: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata1, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 1: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata2, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 2: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata3, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 3: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata4, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 4: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata5, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 5: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata6, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 6: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata7, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
      case 7: if(!matchengine[ivmphi].done() && !matchengine[ivmphi].idle()) if(matchengine[ivmphi].step(table, instubdata8, projbuffer[ivmphi], outcandmatch, noutcandmatch)) { ready=true; }
      break;
    }
    switch (ivmphi) {
      case 0: matchengine[ivmphi].step(table, instubdata1, projbuffer[ivmphi]);
      break;
      case 1: matchengine[ivmphi].step(table, instubdata2, projbuffer[ivmphi]);
      break;
      case 2: matchengine[ivmphi].step(table, instubdata3, projbuffer[ivmphi]);
      break;
      case 3: matchengine[ivmphi].step(table, instubdata4, projbuffer[ivmphi]);
      break;
      case 4: matchengine[ivmphi].step(table, instubdata5, projbuffer[ivmphi]);
      break;
      case 5: matchengine[ivmphi].step(table, instubdata6, projbuffer[ivmphi]);
      break;
      case 6: matchengine[ivmphi].step(table, instubdata7, projbuffer[ivmphi]);
      break;
      case 7: matchengine[ivmphi].step(table, instubdata8, projbuffer[ivmphi]);
      break;
    }
    */
      if(!matchengine[0].done() && !ready) if(matchengine[0].step(table, instubdata1, projbuffer[0], outcandmatch, noutcandmatch)) { ivmphi=0; ready=true; }
      if(!matchengine[1].done() && !ready) if(matchengine[1].step(table, instubdata2, projbuffer[1], outcandmatch, noutcandmatch)) { ivmphi=1; ready=true; }
      if(!matchengine[2].done() && !ready) if(matchengine[2].step(table, instubdata3, projbuffer[2], outcandmatch, noutcandmatch)) { ivmphi=2; ready=true; }
      if(!matchengine[3].done() && !ready) if(matchengine[3].step(table, instubdata4, projbuffer[3], outcandmatch, noutcandmatch)) { ivmphi=3; ready=true; }
      if(!matchengine[4].done() && !ready) if(matchengine[4].step(table, instubdata5, projbuffer[4], outcandmatch, noutcandmatch)) { ivmphi=4; ready=true; }
      if(!matchengine[5].done() && !ready) if(matchengine[5].step(table, instubdata6, projbuffer[5], outcandmatch, noutcandmatch)) { ivmphi=5; ready=true; }
      if(!matchengine[6].done() && !ready) if(matchengine[6].step(table, instubdata7, projbuffer[6], outcandmatch, noutcandmatch)) { ivmphi=6; ready=true; }
      if(!matchengine[7].done() && !ready) if(matchengine[7].step(table, instubdata8, projbuffer[7], outcandmatch, noutcandmatch)) { ivmphi=7; ready=true; }
      typename VMProjection<BARREL>::VMPID projindex;
      typename MatchEngineUnit<VMSMEType, BARREL, VMPTYPE>::STUBID* stubid;
      typename MatchEngineUnit<VMSMEType, BARREL, VMPTYPE>::NSTUBS nstub;
      //if(matchengine[ivmphi].idle() && !matchengine[ivmphi].done() && !matchengine[ivmphi].empty()) {
      if(ready) {
        //if(!matchengine[ivmphi].idle()) continue;
        typename AllProjection<APTYPE>::AProjTCID currentTCID=-1;
        matchengine[ivmphi].read(currentTCID, projindex, stubid, nstub);
        //currentTCID=allproj->read_mem(bx, projindex).getTCID();
        //std::cout << "current=" << currentTCID << "\tbest=" << bestTCID << std::endl;
        if ((iMEbest==kNMatchEngines)||(currentTCID<bestTCID)) {
        //std::cout << iMEbest << "\t" << currentTCID << std::endl;
	  iMEbest=ivmphi;
	  bestTCID=currentTCID;
	  bestInPipeline=matchengine[ivmphi].empty();
	}
        /*
        */
        //if (iMEbest!=kNMatchEngines&&(!bestInPipeline)) {
        MatchCalculator<ASTYPE, APTYPE, VMSMEType, FMTYPE, LAYER, PHISEC>
                  //(bx, allstub, allproj, projindex, stubid, nstub, bx_o,
                  (bx, allstub, allproj, matchengine[ivmphi].getProjindex(), matchengine[ivmphi].getStubIds(), matchengine[ivmphi].getNStubs(), bx_o,
                   nmcout1, nmcout2, nmcout3, nmcout4, nmcout5, nmcout6, nmcout7, nmcout8, noutcandmatch,
                   fullmatch1, fullmatch2, fullmatch3, fullmatch4, fullmatch5, fullmatch6, fullmatch7, fullmatch8,outcandmatch);
        //}
      } //end MC if

    //} //end 8ME loop
    //ivmphi++;

  } //end loop
  //std::cout << "Ending ME" << std::endl;

} // end MatchProcessor()



#endif
