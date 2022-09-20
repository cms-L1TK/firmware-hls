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
#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>

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
      //if (num > 0) mem_hasdata.set(i);
      mem_hasdata[i] = (num > 0); //can't use if statement with rewind
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

    data = inmem[read_imem].read_mem(bx, read_addr);

    //for(int i = 0; i < nMEM; ++i) {
    //#pragma HLS unroll
    //
    //  if (read_imem == i) {
    //    data = inmem[i].read_mem(bx, read_addr);
    //  }
    //}
  }

  template<class DataType, class MemType, int nMEM, int NBits_Entries>
  bool read_input_mems(BXType bx,
                       ap_uint<nMEM>& mem_hasdata,
                       ap_uint<NBits_Entries> nentries[nMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       // memory pointers
                       const MemType mem[nMEM],
                       DataType& data)
  {
#pragma HLS inline
    if (mem_hasdata == 0) return false;

    ap_uint<kNBits_MemAddr> read_addr_next = read_addr + 1;

    // 5 bits memory index for up to 32 input memories
    // priority encoder
    ap_uint<5> read_imem = __builtin_ctz(mem_hasdata);

    // read the memory "read_imem" with the address "read_addr"
    read_inmem<DataType, MemType, nMEM>(data, bx, read_imem, read_addr, mem);

    if (read_addr_next >= nentries[read_imem]) {
      // All entries in the memory[read_imem] have been read out
      // Prepare to move to the next non-empty memory
      read_addr = 0;
      mem_hasdata.clear(read_imem);  // set the current lowest 1 bit to 0
    } else {
      read_addr = read_addr_next;
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
  constexpr unsigned int rbins_adjust = 3;

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

/*
  inline void rbinLUTinit(ap_uint<2*MEBinsBits> zbinLUT[128], int rbins_adjust){

    constexpr unsigned int rbin_const = 8; // can this be derived from other constants?

    for(unsigned int ibin=0; ibin<128; ibin++) {

      ap_uint<7> bin(ibin);

      constexpr double projshiftdisk = 2 * kr;

      ap_uint<MEBinsBits> rbin1 = rbin_const * (
      ap_uint<MEBinsBits> rbin2 = zbinupper >> zbins_nbitsextra;

  }
*/


} // namesapce PR


template<int L>
void readTable(ap_uint<1> table[]){

  if (L==TF::L1) {
    bool tmp[256]=
#include "../emData/MP/tables/METable_L1.tab"
    for (int i=0;i<256;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::L2) {
    bool tmp[256]=
#include "../emData/MP/tables/METable_L2.tab"
    for (int i=0;i<256;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

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
#include "../emData/MP/tables/METable_L4.tab"
    for (int i=0;i<512;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::L5) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L5.tab"
    for (int i=0;i<512;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::L6) {
    bool tmp[512]=
#include "../emData/ME/tables/METable_L6.tab"
    for (int i=0;i<512;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D1) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D1.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D2) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D2.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D3) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D3.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D4) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D4.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D5) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D5.tab"
#pragma HLS unroll
    for (int i=0;i<768;++i){
      table[i]=tmp[i];
    }
  }

  if (L==TF::D1) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D1.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D2) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D2.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D3) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D3.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D4) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D4.tab"
    for (int i=0;i<768;++i){
#pragma HLS unroll
      table[i]=tmp[i];
    }
  }

  if (L==TF::D5) {
    bool tmp[768]=
#include "../emData/MP/tables/METable_D5.tab"
#pragma HLS unroll
    for (int i=0;i<768;++i){
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

// MatchCalculator
namespace MC {
  enum imc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
  enum lutType {PHICUT, ZCUT, PSPHICUT, SSPHICUT, PSRCUT, SSRCUT, ALPHAINNERCUT, ALPHAOUTERCUT, RDSSINNERCUT, RDSSOUTERCUT, RBEND};

  const auto LUT_matchcut_phi_width = 17;
  const auto LUT_matchcut_phi_depth = 12;
  const auto LUT_matchcut_z_width = 14;
  const auto LUT_matchcut_z_depth = 12;
  const auto LUT_matchcut_rphi_width = 20;
  const auto LUT_matchcut_rphi_depth = 12;
  const auto LUT_matchcut_alpha_depth = 10;
  const auto LUT_matchcut_r_width = 12;
  const auto LUT_matchcut_r_depth = 12;
  const auto LUT_matchcut_rDSS_width = 12;
  const auto LUT_matchcut_rDSS_depth = 10;

}

// Template to get look up tables

// Table for phi or z cuts
template<TF::layerDisk L, int width, int depth>
void readRbin_LUT(ap_uint<width> table[depth]) {
  if (L>=TF::D1){
    ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/ProjectionDiskRadius.tab")
#  include "../emData/MP/tables/ProjectionDiskRadius.tab"
#else
    {};
#endif
    for (int i = 0; i < depth; i++) table[i] = tmp[i];
  }
  else {
      static_assert(true, "Only DISKS 1 to 5 are valid");
  }
}

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (type==MC::PHICUT){ // phi cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L1PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L1PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L2PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L2PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L3PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L3PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L4PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L4PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L5PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L5PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L6PHIC_phicut.tab")
#  include "../emData/MP/tables/MP_L6PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else if(type==MC::PSPHICUT) { // PSphi cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_PSphicut.tab")
#  include "../emData/MP/tables/MP_D1PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_PSphicut.tab")
#  include "../emData/MP/tables/MP_D2PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_PSphicut.tab")
#  include "../emData/MP/tables/MP_D3PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_PSphicut.tab")
#  include "../emData/MP/tables/MP_D4PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_PSphicut.tab")
#  include "../emData/MP/tables/MP_D5PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end PSphi
  else if(type==MC::SSPHICUT) { // 2Sphi cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_2Sphicut.tab")
#  include "../emData/MP/tables/MP_D1PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_2Sphicut.tab")
#  include "../emData/MP/tables/MP_D2PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_2Sphicut.tab")
#  include "../emData/MP/tables/MP_D3PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_2Sphicut.tab")
#  include "../emData/MP/tables/MP_D4PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_2Sphicut.tab")
#  include "../emData/MP/tables/MP_D5PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end SSphi
  else if (type==MC::ZCUT) { // z cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L1PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L1PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L2PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L2PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L3PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L3PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L4PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L4PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L5PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L5PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_L6PHIC_zcut.tab")
#  include "../emData/MP/tables/MP_L6PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
  } // end z cuts
  else if(type==MC::PSRCUT) { // PSr cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_PSrcut.tab")
#  include "../emData/MP/tables/MP_D1PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_PSrcut.tab")
#  include "../emData/MP/tables/MP_D2PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_PSrcut.tab")
#  include "../emData/MP/tables/MP_D3PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_PSrcut.tab")
#  include "../emData/MP/tables/MP_D4PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_PSrcut.tab")
#  include "../emData/MP/tables/MP_D5PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end PSr
  else if(type==MC::SSRCUT) { // 2Sr cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_2Srcut.tab")
#  include "../emData/MP/tables/MP_D1PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_2Srcut.tab")
#  include "../emData/MP/tables/MP_D2PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_2Srcut.tab")
#  include "../emData/MP/tables/MP_D3PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_2Srcut.tab")
#  include "../emData/MP/tables/MP_D4PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_2Srcut.tab")
#  include "../emData/MP/tables/MP_D5PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end 2Sr
  else if(type==MC::ALPHAINNERCUT) { // alphainner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_alphainner.tab")
#  include "../emData/MP/tables/MP_D1PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_alphainner.tab")
#  include "../emData/MP/tables/MP_D2PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha inner");
    }
  }
  else if(type==MC::ALPHAOUTERCUT) { // alphaouter cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_alphaouter.tab")
#  include "../emData/MP/tables/MP_D1PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_alphaouter.tab")
#  include "../emData/MP/tables/MP_D2PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha outer");
    }
  }

} // end readTable_Cuts

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_disk(ap_uint<width> table[depth]){
  if(type==MC::ALPHAINNERCUT) { // alphainner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_alphainner.tab")
#  include "../emData/MP/tables/MP_D1PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_alphainner.tab")
#  include "../emData/MP/tables/MP_D2PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_alphainner.tab")
#  include "../emData/MP/tables/MP_D3PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha inner");
    }
  }
  else if(type==MC::ALPHAOUTERCUT) { // alphaouter cuts (//for disks only)
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_alphaouter.tab")
#  include "../emData/MP/tables/MP_D3PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_alphaouter.tab")
#  include "../emData/MP/tables/MP_D4PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_alphaouter.tab")
#  include "../emData/MP/tables/MP_D5PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 3 to 5 are valid for alpha outer");
    }
  }
} // end readTable_disk()

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_rbend(ap_uint<width> table[depth]){
  if(type==MC::RBEND) { // alphainner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D1.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D1.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D2.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D2.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D3.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D3.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D3.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D3.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D4.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D4.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_ProjectionBend_D5.tab")
#  include "../emData/MP/tables/MP_ProjectionBend_D5.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS for rinv bend");
    }
  }
} // end readTable_rbend()

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_rDSS(ap_uint<width> table[depth]){
  if(type==MC::RDSSINNERCUT) { // rDSSinner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D1PHIC_rDSSinner.tab")
#  include "../emData/MP/tables/MP_D1PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D2PHIC_rDSSinner.tab")
#  include "../emData/MP/tables/MP_D2PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_rDSSinner.tab")
#  include "../emData/MP/tables/MP_D3PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for rDSS inner");
    }
  }
  else if(type==MC::RDSSOUTERCUT) { // rDSSouter cuts (//for disks only)
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D3PHIC_rDSSouter.tab")
#  include "../emData/MP/tables/MP_D3PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D4PHIC_rDSSouter.tab")
#  include "../emData/MP/tables/MP_D4PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MP/tables/MP_D5PHIC_rDSSouter.tab")
#  include "../emData/MP/tables/MP_D5PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 3 to 5 are valid for rDSS outer");
    }
  }
} // end readTable_rDSS()
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
//-----------------------------------------------------------------------------------------------------------

template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask();
template<TF::layerDisk Layer, MC::imc PHI> constexpr uint32_t FMMask();
#include "MatchProcessor_parameters.h"

template<regionType ASTYPE, regionType APTYPE, regionType VMSMEType, regionType FMTYPE, int maxFullMatchCopies, TF::layerDisk LAYER=TF::L1, TF::phiRegion PHISEC=TF::A>
void MatchCalculator(BXType bx,
                     ap_uint<1> newtracklet,
                     ap_uint<1>& savedMatch,
                     ap_uint<MC::LUT_matchcut_z_width>& best_delta_z,
                     ap_uint<MC::LUT_matchcut_phi_width>& best_delta_phi,
                     ap_uint<MC::LUT_matchcut_rphi_width>& best_delta_rphi,
                     ap_uint<MC::LUT_matchcut_r_width>& best_delta_r,
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjection<APTYPE>& proj,
                     ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> stubid,
                     int &nmcout1,
                     int &nmcout2,
                     int &nmcout3,
                     int &nmcout4,
                     int &nmcout5,
                     int &nmcout6,
                     int &nmcout7,
                     int &nmcout8,
                     FullMatchMemory<FMTYPE> fullmatch[maxFullMatchCopies]
){

#pragma HLS inline
#pragma HLS array_partition variable=fullmatch complete dim=1

  using namespace PR;

  // Setup constants depending on which layer/disk working on
  // probably should move these to constants file
  const ap_uint<4> kNbitszprojL123 = 12; // nbitszprojL123 in emulation (defined in constants) 
  const ap_uint<4> kNbitszprojL456 = 8;  // nbitszprojL456 in emulation (defined in constants)
  const ap_uint<4> kNbitsphiprojD  = 14; // nbitsphiprojD in emulation (defined in constants) 
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
  const ap_uint<10> kPhi_corr_shift_L456 = kPhi_corr_shift_L123 - 10 + kNbitsrL456; //FIXME was  + kNbitsrL456;                                           // icorrshift for L456
  const auto kPhi_corr_shift     = (LAYER < TF::D1) ? ((LAYER < TF::L4)? kPhi_corr_shift_L123 : kPhi_corr_shift_L456) : ap_uint<10>(6);                            // icorrshift_/shifttmp  in emulation
  const ap_uint<10> kZ_corr_shiftL123 = (-1-kShift_PS_zderL);                                                                 // icorzshift for L123 (6 in L3)
  const ap_uint<10> kZ_corr_shiftL456 = (-1-kShift_2S_zderL + kNbitszprojL123 - kNbitszprojL456 + kNbitsrL456 - kNbitsrL123); // icorzshift for L456
  const auto kZ_corr_shift       = (LAYER < TF::L4)? kZ_corr_shiftL123 : kZ_corr_shiftL456;                                  // icorzshift_ in emulation
  const auto kr_corr_shift       = (LAYER < TF::D1)? 0 : 7;                                  // shifttmp2 in emulation

  const auto LUT_matchcut_alpha_width = (LAYER < TF::D3) ? 9 : 10;
  const auto LUT_matchcut_phi_width = 17;
  const auto LUT_matchcut_phi_depth = 12;
  const auto LUT_matchcut_z_width = 13;
  const auto LUT_matchcut_z_depth = 12;

  // Setup look up tables for match cuts
  ap_uint<MC::LUT_matchcut_phi_width> LUT_matchcut_phi[MC::LUT_matchcut_phi_depth];
  readTable_Cuts<MC::PHICUT,LAYER,MC::LUT_matchcut_phi_width,MC::LUT_matchcut_phi_depth>(LUT_matchcut_phi);
  ap_uint<MC::LUT_matchcut_z_width> LUT_matchcut_z[MC::LUT_matchcut_z_depth];
  readTable_Cuts<MC::ZCUT,LAYER,MC::LUT_matchcut_z_width,MC::LUT_matchcut_z_depth>(LUT_matchcut_z);

  ap_uint<MC::LUT_matchcut_rphi_width> LUT_matchcut_PSrphi[MC::LUT_matchcut_rphi_depth];
  readTable_Cuts<MC::PSPHICUT,LAYER,MC::LUT_matchcut_rphi_width,MC::LUT_matchcut_rphi_depth>(LUT_matchcut_PSrphi);

  ap_uint<MC::LUT_matchcut_rphi_width> LUT_matchcut_2Srphi[MC::LUT_matchcut_rphi_depth];
  readTable_Cuts<MC::SSPHICUT,LAYER,MC::LUT_matchcut_rphi_width,MC::LUT_matchcut_rphi_depth>(LUT_matchcut_2Srphi);

  ap_uint<MC::LUT_matchcut_r_width> LUT_matchcut_PSr[MC::LUT_matchcut_r_depth];
  readTable_Cuts<MC::PSRCUT,LAYER,MC::LUT_matchcut_r_width,MC::LUT_matchcut_r_depth>(LUT_matchcut_PSr);

  ap_uint<MC::LUT_matchcut_r_width> LUT_matchcut_2Sr[MC::LUT_matchcut_r_depth];
  readTable_Cuts<MC::SSRCUT,LAYER,MC::LUT_matchcut_r_width,MC::LUT_matchcut_r_depth>(LUT_matchcut_2Sr);

  ap_uint<LUT_matchcut_alpha_width> LUT_matchcut_alpha[MC::LUT_matchcut_alpha_depth];
  constexpr enum MC::lutType ALPHA = (LAYER < TF::D3) ? MC::ALPHAINNERCUT : MC::ALPHAOUTERCUT;
  readTable_disk<ALPHA,LAYER,LUT_matchcut_alpha_width,MC::LUT_matchcut_alpha_depth>(LUT_matchcut_alpha);

  ap_uint<MC::LUT_matchcut_rDSS_width> LUT_matchcut_rDSS[MC::LUT_matchcut_rDSS_depth];
  constexpr enum MC::lutType RDSS = (LAYER < TF::D3) ? MC::RDSSINNERCUT : MC::RDSSOUTERCUT;
  readTable_rDSS<RDSS,LAYER,MC::LUT_matchcut_rDSS_width,MC::LUT_matchcut_rDSS_depth>(LUT_matchcut_rDSS);

  bool goodmatch                   = false;

  // Use the stub and projection indices to pick up the stub and projection

  AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);
  AllStub<DISKPS>       stub_ps = AllStub<DISKPS>(allstub->read_mem(bx,stubid).raw());
  AllStub<DISK2S>       stub_2s = AllStub<DISK2S>(allstub->read_mem(bx,stubid).raw());

  constexpr bool isDisk = LAYER >= TF::D1;
  // Stub parameters
  typename AllStub<ASTYPE>::ASR     stub_r     = stub.getR();
  typename AllStub<ASTYPE>::ASZ     stub_z     = stub.getZ();
  typename AllStub<ASTYPE>::ASPHI   stub_phi   = stub.getPhi();
  typename AllStub<ASTYPE>::ASBEND  stub_bend  = stub.getBend();       
  typename AllStub<DISKPS>::ASR    stub_ps_r    = stub_ps.getR();
  typename AllStub<DISKPS>::ASZ    stub_ps_z    = stub_ps.getZ();
  typename AllStub<DISKPS>::ASPHI  stub_ps_phi  = stub_ps.getPhi();
  typename AllStub<DISKPS>::ASBEND stub_ps_bend = stub_ps.getBend();       
  ap_uint<12>                      stub_2s_r    = stub_2s.getR();
  typename AllStub<DISK2S>::ASZ    stub_2s_z    = stub_2s.getZ();
  typename AllStub<DISK2S>::ASPHI  stub_2s_phi  = stub_2s.getPhi();
  typename AllStub<DISK2S>::ASBEND stub_2s_bend = stub_2s.getBend();       
  typename AllStub<DISK2S>::ASALPHA stub_2s_alpha = stub_2s.getAlpha();       
  auto isPSStub = stub_ps.isPSStub();

  // Projection parameters
  typename AllProjection<APTYPE>::AProjTCID          proj_tcid = proj.getTCID();
  typename AllProjection<APTYPE>::AProjTrackletIndex proj_tkid = proj.getTrackletIndex();
  typename AllProjection<APTYPE>::AProjTCSEED        proj_seed = proj.getSeed();
  typename AllProjection<APTYPE>::AProjPHI           proj_phi  = proj.getPhi();
  typename AllProjection<APTYPE>::AProjRZ            proj_z    = proj.getRZ();
  typename AllProjection<APTYPE>::AProjPHIDER        proj_phid = proj.getPhiDer();
  typename AllProjection<APTYPE>::AProjRZDER         proj_zd   = proj.getRZDer(); 
  bool isProjDisk = proj_seed >= TF::D1;

  // Calculate residuals
  // Get phi and z correction
  ap_int<22> full_phi_corr = stub_r * proj_phid; // full corr has enough bits for full multiplication
  ap_int<18> full_z_corr   = stub_r * proj_zd;   // full corr has enough bits for full multiplication
  ap_int<18> full_r_corr   = stub_z * proj_zd;   // full corr has enough bits for full multiplication
  ap_int<11> phi_corr      = full_phi_corr >> kPhi_corr_shift;                        // only keep needed bits
  //ap_uint<3> shifttmp = 6;
  constexpr auto shifttmp = (LAYER < trklet::N_LAYER) ? log2barrel : log2disk;
  if(isDisk && isPSStub)
    phi_corr = (stub_ps_z * proj_phid) >> shifttmp;
  else if(isDisk && !isPSStub)
    phi_corr = (stub_2s_z * proj_phid) >> shifttmp;
  ap_int<12> z_corr        = (full_z_corr + (1<<(kZ_corr_shift-1))) >> kZ_corr_shift; // only keep needed bits
  ap_int<12> r_corr        = full_r_corr >> kr_corr_shift; // only keep needed bits
    std::string ld[] = {"L1", "L2", "L3", "L4", "L5", "L6", "D1", "D2", "D3", "D4", "D5"};
   
  // Apply the corrections
  const int kProj_phi_len = AllProjection<APTYPE>::kAProjPhiSize + 1;
  ap_int<kProj_phi_len> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction iphi in emulation
  ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction

  // Get phi and z difference between the projection and stub
  ap_int<12> delta_z        = stub_z - proj_z_corr;
  ap_int<14> delta_z_fact   = delta_z * kFact;
  const ap_int<18> &stub_phi_long  = stub_phi;         // make longer to allow for shifting
  const ap_int<18> &proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
  //ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
  ap_int<18> shiftstubphi   = kPhi0_shift > 0 ? stub_phi_long << kPhi0_shift : stub_phi_long;                        // shift
  if(isDisk && isPSStub)
    //shiftstubphi = stub_ps_phi << kPhi0_shift;
    shiftstubphi = kPhi0_shift > 0 ? stub_ps_phi << kPhi0_shift : stub_ps_phi;                        // shift
  else if(isDisk && !isPSStub) {
    //shiftstubphi = stub_2s_phi << kPhi0_shift;
    shiftstubphi = kPhi0_shift > 0 ? stub_2s_phi << kPhi0_shift : stub_2s_phi;                        // shift
  }
  ap_int<18> shiftprojphi = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
  constexpr int dphibit = 20;
  ap_int<dphibit> delta_phi      = shiftstubphi - shiftprojphi;
  ap_uint<3> shiftprojz     = 7;
  ap_int<7> proj_r_corr    = (stub_z * proj_zd) >> shiftprojz;
  if(isDisk && isPSStub)
    proj_r_corr = (stub_ps_z * proj_zd) >> shiftprojz;
  else if(isDisk)
    proj_r_corr = (stub_2s_z * proj_zd) >> shiftprojz;
  const ap_uint<13> &proj_r_long  = proj_z + proj_r_corr;
  ap_uint<1> shiftr         = 1;
  ap_int<12> delta_r        = (stub_r >> shiftr) - proj_r_long; // proj_z = RZ
  ap_uint<12> tmp_stubr = isProjDisk ? LUT_matchcut_rDSS[ap_uint<12>(stub_2s_r)] : LUT_matchcut_rDSS[ap_uint<12>(stub_r)]; //FIXME

  if(isDisk && isPSStub) {
    delta_r   = (ap_uint<12>(stub_ps_r) >> shiftr) - proj_r_long; // proj_z = RZ
  }
  else if(isDisk && !isPSStub) {
    auto alpha_fact = LUT_matchcut_alpha[ap_uint<12>(stub_2s_r)];
    tmp_stubr = LUT_matchcut_rDSS[ap_uint<4>(stub_2s_r)]; 
    delta_r   = ((tmp_stubr >> shiftr) - proj_r_long); // proj_z = RZ
    ap_uint<4> alpha_shift = 12;
    ap_uint<12> alpha_corr = ap_int<24>(ap_int<24>(delta_r) * stub_2s_alpha * alpha_fact) >> alpha_shift;
    delta_phi += alpha_corr;
  }
  constexpr int adphibit = isDisk ? 12 : 17;
  ap_uint<dphibit> abs_delta_phi = iabs<adphibit>( delta_phi );    // absolute value of delta phi
  ap_int<12> abs_delta_r    = iabs<11>( delta_r );

  // Full match parameters
  const typename FullMatch<FMTYPE>::FMTCID          &fm_tcid  = proj_tcid;
  const typename FullMatch<FMTYPE>::FMTrackletIndex &fm_tkid  = proj_tkid;
  const typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
  const typename FullMatch<FMTYPE>::FMSTUBID        &fm_asid  = stubid;
  const typename FullMatch<FMTYPE>::FMSTUBR         &fm_stubr = isDisk ? (isPSStub ? ap_int<FullMatch<FMTYPE>::kFMStubRSize>(stub_ps_r) : ap_int<FullMatch<FMTYPE>::kFMStubRSize>(stub_2s_r)) : ap_int<FullMatch<FMTYPE>::kFMStubRSize>(stub_r);
  const typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
  //const typename FullMatch<FMTYPE>::FMZRES          fm_z     = delta_z;
  const typename FullMatch<FMTYPE>::FMZRES          fm_z     = (!isDisk) ? delta_z : ap_int<12>(delta_r);
  
  // Full match  
  FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,fm_asphi,fm_asid,fm_stubr,fm_phi,fm_z);

  //-----------------------------------------------------------------------------------------------------------
  //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
  //-----------------------------------------------------------------------------------------------------------
  
  if (newtracklet) {
    savedMatch = 0;
  }
  
  // For first tracklet, pick up the phi cut value
  best_delta_z = (newtracklet)? LUT_matchcut_z[proj_seed] : best_delta_z;
  best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;
  if(newtracklet) {
    if(isPSStub) {
      best_delta_rphi = LUT_matchcut_PSrphi[proj_seed];
      best_delta_r = LUT_matchcut_PSr[proj_seed];
    }
    else  {
      best_delta_rphi = LUT_matchcut_2Srphi[proj_seed];
      best_delta_r = LUT_matchcut_2Sr[proj_seed];
    }
  }

  // Check that matches fall within the selection window of the projection 
  bool barrel_match = (delta_z_fact < best_delta_z) && (delta_z_fact >= -best_delta_z) && (abs_delta_phi <= best_delta_phi);
  bool disk_match = isPSStub ? ((abs_delta_phi * ap_uint<12>(stub_ps_r)) < best_delta_rphi) && (abs_delta_r < best_delta_r) : ((abs_delta_phi * ap_uint<12>(tmp_stubr)) < best_delta_rphi) && (abs_delta_r < best_delta_r);
  if ((!isDisk && barrel_match) || (isDisk && disk_match)){
    // Update values of best phi parameters, so that the next match
    // will be compared to this value instead of the original selection cut
    if(isDisk) {
      best_delta_rphi = isPSStub ? ap_uint<20>(abs_delta_phi * ap_uint<12>(stub_ps_r)) : ap_uint<20>(abs_delta_phi * tmp_stubr);
      best_delta_r    = abs_delta_r;
    }
    else {
      best_delta_z = iabs<14>(delta_z_fact);
      best_delta_phi = abs_delta_phi;
    }

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
  
} //end MC

//////////////////////////////
// MatchProcessor
template<regionType PROJTYPE, regionType VMSMEType, regionType VMPTYPE, regionType ASTYPE, regionType APTYPE, regionType FMTYPE, unsigned int nINMEM, int maxFullMatchCopies,
         TF::layerDisk LAYER=TF::L1, TF::layerDisk DISK=TF::D1, TF::phiRegion PHISEC=TF::A>
void MatchProcessor(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
                      const TrackletProjectionMemory<PROJTYPE> projin[nINMEM],
                      const VMStubMEMemoryCM<VMSMEType, 3, 3, kNMatchEngines>& instubdata,
                      const AllStubMemory<ASTYPE>* allstub,
                      BXType& bx_o,
                      FullMatchMemory<FMTYPE> fullmatch[maxFullMatchCopies]
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

  // declare counters for each of the 8 different seeds.
  //FIXME should have propoer seven bit type
  int nmcout1 = 0;
  int nmcout2 = 0;
  int nmcout3 = 0;
  int nmcout4 = 0;
  int nmcout5 = 0;
  int nmcout6 = 0;
  int nmcout7 = 0;
  int nmcout8 = 0;

  ap_uint<kNBits_MemAddr> nallproj = 0;

  ap_uint<kNBits_MemAddr> iproj=0; //counter

  //The next projection to read, the number of projections and flag if we have
  //more projections to read

  constexpr int nPRBAbits = 3;
  ProjectionRouterBufferArray<nPRBAbits,VMPTYPE,APTYPE> projbufferarray;

  MatchEngineUnit<VMSMEType, VMPTYPE, APTYPE, LAYER, ASTYPE> matchengine[kNMatchEngines];
#pragma HLS ARRAY_PARTITION variable=matchengine complete dim=0
#pragma HLS ARRAY_PARTITION variable=instubdata complete dim=1
#pragma HLS ARRAY_PARTITION variable=projin dim=1
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0
  


  for(unsigned int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll
  matchengine[iMEU].reset();
#ifndef __SYNTHESIS__
    matchengine[iMEU].setUnit(iMEU);
#endif
  }

  //These are used inside the MatchCalculator method and needs to be retained between iterations
  ap_uint<1> savedMatch;
  typename ProjectionRouterBuffer<VMPTYPE, APTYPE>::TRKID lastTrkID(-1);

  TrackletProjection<PROJTYPE> projdata, projdata_;
  bool validin = false; 
  bool validin_ = false; 

  static ap_uint<2*MEBinsBits> zbinLUT[128];
#pragma HLS ARRAY_PARTITION variable=zbinLUT complete dim=0
  zbinLUTinit(zbinLUT, zbins_adjust_PSseed, zbins_adjust_2Sseed);

  bool validproj__ = false;
  ProjectionRouterBuffer<BARREL, APTYPE> projbuffer__;


  ap_uint<8> vmstubsmask[8];
#pragma HLS array_partition variable=vmstubsmask complete dim=1

  entriesloop:for(unsigned int i=0;i<8;i++) {
#pragma HLS unroll
    vmstubsmask[i]=instubdata.getBinMask8(bx,i);
  }
// constants used in reading VMSME memories
  constexpr int NUM_PHI_BINS = 1 << kNbitsphibin;
  constexpr int NUM_RZ_BINS = 1 << kNbitsrzbin;
  constexpr int PAGE_LENGTH_CM = 1024;
  constexpr int BIN_ADDR_WIDTH = 4;
  //Can't figure out how to do this calculation at compile
  //constexpr int BIN_ADDR_WIDTH = ceil(log2(PAGE_LENGTH_CM/(NUM_PHI_BINS*NUM_RZ_BINS)));

  /*
  ap_uint<4> nvmstubs[8][8]; 
  //ap_uint<4> nvmstubs[8][8]; 
#pragma HLS ARRAY_PARTITION variable=nvmstubs complete dim=0
  
 nstubsloop: for (unsigned int izbin=0;izbin<8;izbin++) {
#pragma HLS unroll      
    (nvmstubs[izbin][7],nvmstubs[izbin][6],nvmstubs[izbin][5],nvmstubs[izbin][4],
     nvmstubs[izbin][3],nvmstubs[izbin][2],nvmstubs[izbin][1],nvmstubs[izbin][0]) = instubdata.getEntries8(bx, izbin);
  }
  */
 PROC_LOOP: for (ap_uint<kNBits_MemAddr> istep = 0; istep < kMaxProc - kMaxProcOffset(module::MP); istep++) {
#pragma HLS PIPELINE II=1 rewind

    auto readptr = projbufferarray.getReadPtr();
    auto writeptr = projbufferarray.getWritePtr();
    bool empty = emptyUnit<kNBitsBuffer>()[(readptr,writeptr)];
    bool projBuffNearFull = nearFull4Unit<kNBitsBuffer>()[(readptr,writeptr)];
    
    ap_uint<3> iphi = 0;

    ap_uint<kNMatchEngines> idles;
    ap_uint<kNMatchEngines> emptys;

    typename MatchEngineUnit<VMSMEType, VMPTYPE, APTYPE, LAYER, ASTYPE>::MATCH matches[kNMatchEngines];
    #pragma HLS ARRAY_PARTITION variable=matches complete dim=0
    ap_uint<kNBits_MemAddr> projseqs[kNMatchEngines];
#pragma HLS ARRAY_PARTITION variable=projseqs complete dim=0


    bool anyidle = false;

  MEU_get_trkids: for(int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll      
      matchengine[iMEU].set_empty();
      idles[iMEU] = matchengine[iMEU].idle();
      anyidle = idles[iMEU] ? true : anyidle;
      emptys[iMEU] = matchengine[iMEU].empty();
      projseqs[iMEU] = matchengine[iMEU].getProjSeq();
      matches[iMEU] =  matchengine[iMEU].peek();
    }

    //This printout exactly matches printout in emulation for tracking code differences
    /* 
    std::cout << "istep = " << istep << " projBuff: " << readptr << " " << writeptr << " " << projBuffNearFull;
    for(int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
      std::cout << " MEU"<<iMEU<<": "<<matchengine[iMEU].readIndex()<<" "<<matchengine[iMEU].writeIndex()<<" "<<matchengine[iMEU].idle()
		<<" "<<matchengine[iMEU].empty()<<" "<<matchengine[iMEU].getTrkID();
    }
    std::cout << std::endl;
    */
    
    //New code
    ap_uint<kNBits_MemAddr>  projseq01tmp, projseq23tmp, projseq0123tmp;
    ap_uint<1> Bit01 = projseqs[0]<projseqs[1];
    ap_uint<1> Bit23 = projseqs[2]<projseqs[3];

    projseq01tmp = Bit01 ? projseqs[0] : projseqs[1];
    projseq23tmp = Bit23 ? projseqs[2] : projseqs[3];
    
    ap_uint<1> Bit0123 = projseq01tmp < projseq23tmp;

    projseq0123tmp = Bit0123 ? projseq01tmp : projseq23tmp;
    
    ap_uint<2> bestiMEU = (~Bit0123, Bit0123 ? ~Bit01 : ~Bit23 );

    ap_uint<1> hasMatch = !emptys[bestiMEU];
    
/*
    // old code - keep for now
    ap_uint<kNMatchEngines> smallest = ~emptys;
#pragma HLS ARRAY_PARTITION variable=projseqs complete dim=0
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
*/    

    if (hasMatch) {
      matchengine[bestiMEU].advance();
    }


    ProjectionRouterBuffer<VMPTYPE,APTYPE> tmpprojbuff = projbufferarray.peek();
    if (anyidle && !empty) {
      projbufferarray.advance();
    }
    
    bool init = false;
  MEU_LOOP: for(unsigned int iMEU = 0; iMEU < kNMatchEngines; ++iMEU) {
#pragma HLS unroll
      auto &meu = matchengine[iMEU];
      
      bool idle = idles[iMEU];

      if(idle && !empty && !init) {
        init =  true;
        meu.init(bx, tmpprojbuff, istep);
      }
      //can not get to here on first cycle, but compile don't seem to realize 
      //this and fail to reach II=1
      else if (istep != 0) meu.step(instubdata.getMem(iMEU));
      
      meu.processPipeLine(table[iMEU]);      

    } //end MEU loop
    
    if (hasMatch) {
 
      ap_uint<VMStubMECMBase<VMSMEType>::kVMSMEIDSize> stubindex;
      ap_uint<AllProjection<APTYPE>::kAllProjectionSize> allprojdata;
      
      (stubindex,allprojdata) = matches[bestiMEU];
      //matchengine[bestiMEU].advance();

      AllProjection<APTYPE> allproj(allprojdata);

      auto trkindex=(allproj.getTCID(), allproj.getTrackletIndex());
    
      ap_uint<1> newtracklet = lastTrkID != trkindex;
      
      lastTrkID = trkindex;

      MatchCalculator<ASTYPE, APTYPE, VMSMEType, FMTYPE, maxFullMatchCopies, LAYER, PHISEC>
        (bx, newtracklet, savedMatch, best_delta_z, best_delta_phi, best_delta_rphi, best_delta_r, allstub, allproj, stubindex,
         nmcout1, nmcout2, nmcout3, nmcout4, nmcout5, nmcout6, nmcout7, nmcout8,
         fullmatch);
    } //end MC if
    if (validproj__) {

      projbufferarray.saveProjection(projbuffer__);
      projbufferarray.incProjection();
     
    }

      
    if (validin_) {
      auto iphiproj = projdata_.getPhi();
      auto izproj = projdata_.getZ();
      auto iphider = projdata_.getPhiDer();
      auto izder = projdata_.getRZDer();
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
      //The -1 here is due to not using the full range of bits. Should be fixed.
      ap_uint<8> rbin8 = izproj >> (izproj.length()-8-1);//izproj.range(izproj.length()-1,izproj.length()-8-1);

      //The first and last zbin the projection points to
      constexpr int nZbinBits = ProjectionRouterBuffer<VMPTYPE, APTYPE>::kPRBufferZBinSize - 1; // zbin = (zfirst,zflag)
      ap_uint<nZbinBits> zfirst, zlast, rtmp, rfirst;
      ap_uint<1> rsecond;

      //(zfirst, zlast) = zbinLUT[(psseed,zbin6)];
      ap_uint<nRbinBits> rbin = rbinLUT[rbin8];
      typename VMProjection<VMPTYPE>::VMPFINEZ finer = rbin >> nZbinBits;
      rtmp = rbin.range(nZbinBits, 0);
      rfirst = rtmp >> 1;
      rsecond = rtmp & 1;
      //(finer,rfirst,rsecond) = rbin;//.range(nZbinBits, 0);
      //rfirst = izder < 0 ? ap_uint<nZbinBits>(rfirst + (1<<MEBinsBits)) : rfirst;
      rfirst = (izder.range(izder.length()-1, izder.length()-1)  == 1) ? ap_uint<nZbinBits>(rfirst + (1<<MEBinsBits)) : rfirst;
      (zfirst, zlast) = zbinLUT[(psseed,zbin6)];
      //rfirst = (projdata_.getRZDer()>0) ? rfirst : ap_uint<nZbinBits>(rfirst + (1<<nRbinBits));
      //rbin.range(nZbinBits+1, 1) = (projdata_.getRZDer()>0) ? rbin.range(nZbinBits, 1) : rbin.range(nZbinBits+1, 1) + (1<<kNbitsrzbin);

      typename VMProjection<VMPTYPE>::VMPZBIN zbin = (LAYER < trklet::N_LAYER) ? (zfirst, zfirst!=zlast) : (rfirst,rsecond);

      // VM Projection
      typename VMProjection<VMPTYPE>::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zfirst,ap_uint<3>(0));
      finez = (LAYER < trklet::N_LAYER) ?  finez : finer;
      
      //Extracts the rinv of the projection from the phider; recall phider = - rinv/2
      typename VMProjection<VMPTYPE>::VMPRINV rinv = (1<<(nbits_maxvm-1)) - 1 - iphider.range(iphider.length()-1,iphider.length()-nbits_maxvm);
      if (LAYER >= trklet::N_LAYER) {
        // The next lines looks up the predicted bend based on:
        // 1 - r projections
        // 2 - phi derivative
        // 3 - the sign - i.e. if track is forward or backward
        auto projrz = projdata_.getR();
        auto projder = projdata_.getRZDer();
        auto phiprojder = projdata_.getPhiDer();
        int signindex = projder < 0;
        int nrbits_ = 5;
        int nphiderbits_ = 6;
        int rindex = (projrz >> (AllProjectionBase<APTYPE>::kAProjRZSize - nrbits_)) & ((1 << nrbits_) - 1);
        int phiderindex = (phiprojder >> (AllProjectionBase<APTYPE>::kAProjPhiDSize - nphiderbits_)) & ((1 << nphiderbits_) - 1);
        int bendindex = (signindex << (nphiderbits_ + nrbits_)) + (rindex << (nphiderbits_)) + phiderindex;
        rinv = LUT_matchcut_rbend[bendindex];
        //projdata_.setRZ(rinv);
      }
      
      ///////////////////////////////////
      //This is where Anders calls the ME
      ///////////////////////////////////
      //If we have more projections and the buffer is not full we read
      //next projection and put in buffer if there are stubs in the 
      //memory the projection points to
      
      // number of bits used to distinguish the different modules in each layer/disk
      constexpr auto nbits_all = nbitsallstubs[LAYER];
      
      // number of bits used to distinguish between VMs within a module
      constexpr auto nbits_vmme = nbits_vmmeall[LAYER];
      constexpr auto nvmbits_ = nbits_vmme + nbitsallstubs[LAYER];
      constexpr auto nbins_vmme = 1 << nbits_vmme;
      
      // bits used for routing
      iphi = iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);
      //iphi = iphiproj.range(iphiproj.length()-nbins_vmme-1,iphiproj.length()-nbits_all-nbits_vmme);
      //iphi = iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);
      //iphi = (iphiproj >> (iphiproj.length() - 1 - (nbits_vmme + nbits_all))) & (nbins_vmme - 1);//iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);
                //<< (iphiproj >> (iphiproj.length() - 1 - (nbits_vmme + nbits_all)) & (nbins_vmme - 1)) << std::endl;
      
      constexpr int kNfineBits = 3;
      typename VMProjection<VMPTYPE>::VMPFINEPHI finephi = (iphiproj >> (iphiproj.length() - (nvmbits_ + kNfineBits))) & ((1 << kNfineBits) - 1);
      /*
      typename VMProjection<VMPTYPE>::VMPFINEPHI finephi = iphiproj.range(iphiproj.length()-nbits_all-nbits_vmme-1,
                                      iphiproj.length()-nbits_all-nbits_vmme-3); 
      */
      
      constexpr int nextrabits = 2;
      constexpr int overlapbits = nbits_vmme + nbits_all + nextrabits;
      
      unsigned int extrabits = (iphiproj >> (iphiproj.length() - overlapbits -  nextrabits)) & ((1<<nextrabits) - 1);
      //unsigned int extrabits = iphiproj.range(iphiproj.length() - overlapbits, iphiproj.length() - overlapbits - nextrabits);

      unsigned int ivmPlus = iphi;
	
      //ap_int<2> shift = 0;
      
      //If the projection goes to the first (ivmMinus) phiProjBin is zero but
      //if the projection goes to the second bin ivmMinus+1 phiProjBin is one
      typename ProjectionRouterBuffer<BARREL, APTYPE>::PHIPROJBIN phiProjBin  = 0; 

      if (extrabits == ((1U << nextrabits) - 1) && iphi != ((1U << nbits_vmme) - 1)) {
	//shift = 1;
	ivmPlus++;
      }
      unsigned int ivmMinus = iphi;
      if (extrabits == 0 && iphi != 0) {
	phiProjBin = 1; //projection is to next been, but we also search here
	//shift = -1;
	ivmMinus--;
      }
      
      ///////////////
      // VMProjection
      // New code for using new VMSME memory module

      ap_uint<BIN_ADDR_WIDTH> entries_zfirst[NUM_PHI_BINS];
#pragma HLS ARRAY_PARTITION variable=entries_zfirst dim=0 complete
      ap_uint<BIN_ADDR_WIDTH> entries_zlast[NUM_PHI_BINS];
#pragma HLS ARRAY_PARTITION variable=entries_zlast dim=0 complete

      for (int phibin = 0; phibin < NUM_PHI_BINS; phibin++){
#pragma HLS unroll
        entries_zfirst[phibin]= instubdata.get_mem_entries8A()[(bx&3)*NUM_PHI_BINS+zfirst].range(phibin*BIN_ADDR_WIDTH+BIN_ADDR_WIDTH-1,phibin*BIN_ADDR_WIDTH);
        entries_zlast[phibin]= instubdata.get_mem_entries8B()[(bx&3)*NUM_PHI_BINS+zlast].range(phibin*BIN_ADDR_WIDTH+BIN_ADDR_WIDTH-1,phibin*BIN_ADDR_WIDTH);
      }

      /*
      std::cout << " z phi: " << zfirst << " " << ivmMinus << " "
           << nvmstubs[zfirst][ivmMinus]<< " " << entries_zfirst[ivmMinus]
      << std::endl;
      */

      ap_uint<1> stubfirstMinus = vmstubsmask[zfirst][ivmMinus];
      ap_uint<1> stubfirstPlus = vmstubsmask[zfirst][ivmPlus]&&
                                 (ivmMinus!=ivmPlus);
      ap_uint<1> stublastMinus = vmstubsmask[zlast][ivmMinus]&&
                                 (zfirst!=zlast);
      ap_uint<1> stublastPlus = vmstubsmask[zlast][ivmPlus]&&
                                 (zfirst!=zlast)&&(ivmMinus!=ivmPlus);;
      
      ap_uint<BIN_ADDR_WIDTH> nstubfirstMinus = entries_zfirst[ivmMinus];
      ap_uint<BIN_ADDR_WIDTH> nstubfirstPlus = entries_zfirst[ivmPlus];
      ap_uint<BIN_ADDR_WIDTH> nstublastMinus = entries_zlast[ivmMinus];
      ap_uint<BIN_ADDR_WIDTH> nstublastPlus = entries_zlast[ivmPlus];
      


      //if (ivmMinus==ivmPlus) {
      //	nstubfirstPlus = 0;
      //	nstublastPlus = 0;
      //}
      //if (zfirst==zlast) {
      //	nstublastMinus = 0;
      //	nstublastPlus = 0;
      //}

      ap_uint<4> maskstubs=(stublastPlus, stubfirstPlus, stublastMinus, stubfirstMinus);
      
/*
      for (int i = 0; i<4; i++){
        std::cout<<"maskstubs"<<i<<": "<<((maskstubs<<i)&1)<<" | ";
      }
      std::cout<<std::endl;
*/
      ap_uint<16> nstubs=(nstublastPlus, nstubfirstPlus, nstublastMinus, nstubfirstMinus);
      
      
      VMProjection<VMPTYPE> vmproj = (VMPTYPE == BARREL) ? VMProjection<VMPTYPE>(index, zbin, finez, finephi, rinv, psseed) : VMProjection<VMPTYPE>(index, zbin, finez, finephi, rinv);
      //vmproj.Print();
      
      AllProjection<APTYPE> allproj(projdata_.getTCID(), projdata_.getTrackletIndex(), projdata_.getPhi(),
                    projdata_.getZ(), projdata_.getPhiDer(), projdata_.getRZDer());

      ProjectionRouterBuffer<BARREL, APTYPE> projbuffertmp(allproj.raw(), ivmMinus, phiProjBin, trackletid, nstubs, maskstubs, zfirst, vmproj, psseed);

      projbuffer__ = projbuffertmp;

      validproj__ = maskstubs != 0;

      //projbufferarray.saveProjection(projbuffertmp);

      //if (maskstubs!=0) {
      //	projbufferarray.incProjection();
      //}
      
    } else {
      validproj__ = false;
    }// end if(validin)
    
    projdata_ = projdata;
    validin_ = validin;

    if (!projBuffNearFull){
      
      // read inputs
      validin = read_input_mems<TrackletProjection<PROJTYPE>,
      TrackletProjectionMemory<PROJTYPE>,
      nINMEM, kNBits_MemAddr+1>
      (bx, mem_hasdata, numbersin, mem_read_addr,
         projin, projdata);
      //std::cout << "Loading proj=" << projdata.raw() << " into MP" << std::endl;
 
    } else {
      validin = false;
    }// end if not near full
     
  } //end loop

  bx_o = bx;

} // end MatchProcessor()



#endif
