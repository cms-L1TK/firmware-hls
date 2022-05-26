#ifndef TRACKLETENGINEUNIT_H
#define TRACKLETENGINEUNIT_H

#include "Constants.h"
#include "VMStubTEOuterMemoryCM.h"
#include "TrackletProcessor_parameters.h"

template<TF::seed Seed, TC::itc iTC, regionType innerRegion,regionType VMSTEType>
class TrackletEngineUnit {

 public:
  enum BitWidths{
    kNBitsBuffer=3,
    kNBitsRZBin=3,
    kNBitsRZFine=3,
    kNBitsPhiBins=3,
    kNBitsPTLutInner=(Seed==TF::L5L6)?1024:(Seed==(TF::L1L2||TF::L2L3)?256:512),
    kNBitsPTLutOuter=(Seed==TF::L5L6)?1024:(Seed==(TF::L1L2||TF::L2L3||TF::L3L4)?256:512)
  };

  typedef ap_uint<VMStubTEOuter<VMSTEType>::kVMSTEOIDSize+kNBits_MemAddr+AllStub<innerRegion>::kAllStubSize> STUBID;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUBS;
  typedef ap_uint<kNBitsBuffer> INDEX;
  typedef ap_uint<kNBitsRZBin> RZBIN;
  typedef ap_uint<kNBitsRZFine> RZFINE;
  typedef ap_uint<kNBitsPhiBins> PHIBIN;
  typedef ap_uint<kNBitsPhiBins+1> MEMINDEX;  //Index into MEMMASK and MEMSTUBS
  typedef ap_uint<2*(1<<kNBitsPhiBins)> MEMMASK;  //Bit mask for used bins for two RZbins
  typedef ap_uint<2*(1<<kNBitsPhiBins)*4> MEMSTUBS; //Number of stubs in bins for two RZbins //FIXME for 4


 TrackletEngineUnit() {

#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew_ complete dim=1
#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew_ complete dim=1

/////  Grabs the appropriate lut based on seed and iTC
if (Seed==TF::L1L2&& iTC==TC::A){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2A_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2A_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2A_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2A_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::B){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2B_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2B_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2B_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2B_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::C){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2C_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2C_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2C_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2C_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::D){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2D_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2D_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2D_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2D_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::E){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2E_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2E_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2E_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2E_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::F){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2F_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2F_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2F_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2F_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::G){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2G_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2G_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2G_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2G_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::H){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2H_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2H_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2H_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2H_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::I){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2I_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2I_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2I_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2I_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::J){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2J_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2J_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2J_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2J_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::K){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2K_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2K_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2K_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2K_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L1L2&& iTC==TC::L){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2L_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L1L2L_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L1L2L_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L1L2L_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L2L3&& iTC==TC::A){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3A_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L2L3A_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3A_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L2L3A_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L2L3&& iTC==TC::B){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3B_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L2L3B_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3B_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L2L3B_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L2L3&& iTC==TC::C){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3C_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L2L3C_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3C_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L2L3C_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L2L3&& iTC==TC::D){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3D_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L2L3D_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L2L3D_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L2L3D_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L3L4&& iTC==TC::A){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4A_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L3L4A_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4A_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L3L4A_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L3L4&& iTC==TC::B){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4B_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L3L4B_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4B_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L3L4B_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L3L4&& iTC==TC::C){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4C_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L3L4C_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4C_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L3L4C_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L3L4&& iTC==TC::D){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4D_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L3L4D_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L3L4D_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L3L4D_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L5L6&& iTC==TC::A){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6A_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L5L6A_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6A_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L5L6A_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L5L6&& iTC==TC::B){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6B_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L5L6B_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6B_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L5L6B_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L5L6&& iTC==TC::C){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6C_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L5L6C_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6C_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L5L6C_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
else if (Seed==TF::L5L6&& iTC==TC::D){
      const ap_uint<1> stubptinnertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6D_stubptinnercut.tab")
#  include "../emData/TP/tables/TP_L5L6D_stubptinnercut.tab"
#else
    {};
#endif
      const ap_uint<1> stubptoutertmp[]=
#if __has_include("../emData/TP/tables/TP_L5L6D_stubptoutercut.tab")
#  include "../emData/TP/tables/TP_L5L6D_stubptoutercut.tab"
#else
    {};
#endif
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }

 

////
    idle_ = true;
    }


 MEMSTUBS nstub16() const {
#pragma HLS array_partition variable=ns complete dim=1
   return (ns[15],ns[14],ns[13],ns[12],ns[11],ns[10],ns[9],ns[8],ns[7],ns[6],ns[5],ns[4],ns[3],ns[2],ns[1],ns[0]);
 }

 void setnstub16(MEMSTUBS nstubs) {
#pragma HLS array_partition variable=ns complete dim=1
   (ns[15],ns[14],ns[13],ns[12],ns[11],ns[10],ns[9],ns[8],ns[7],ns[6],ns[5],ns[4],ns[3],ns[2],ns[1],ns[0]) = nstubs;
 }

 NSTUBS calcNStubs(MEMSTUBS nstubs, MEMMASK mask) {

 NSTUBS n[16];
#pragma HLS array_partition variable=n complete dim=1
   (n[15],n[14],n[13],n[12],n[11],n[10],n[9],n[8],n[7],n[6],n[5],n[4],n[3],n[2],n[1],n[0]) = nstubs;
   
   return mask.test(0) ? n[0] :
     mask.test(1) ? n[1] :
     mask.test(2) ? n[2] :
     mask.test(3) ? n[3] :
     mask.test(4) ? n[4] :
     mask.test(5) ? n[5] :
     mask.test(6) ? n[6] :
     mask.test(7) ? n[7] :
     mask.test(8) ? n[8] :
     mask.test(9) ? n[9] :
     mask.test(10) ? n[10] :
     mask.test(11) ? n[11] :
     mask.test(12) ? n[12] :
     mask.test(13) ? n[13] :
     mask.test(14) ? n[14] : n[15];
 }

 void reset(int instance) {
   writeindex_ = 0;
   readindex_ = 0;
   idle_ = true;
   good__ = 0;
   good___ = 0;
   memmask_ = 0;
   istub_ = 0;
   instance_ = instance;
 }

bool empty() {
#pragma HLS inline  
  return (writeindex_==readindex_);
}

bool idle() {
#pragma HLS inline  
  return idle_;
}

bool full() {
#pragma HLS inline  
  return (writeindex_+1==readindex_);
}

bool nearfull() {
#pragma HLS inline  
  return ((writeindex_+2==readindex_)||(writeindex_+1==readindex_));
}

STUBID read() {
#pragma HLS inline  
  return stubids_[readindex_++];
}

void write(STUBID stubs) {
#pragma HLS inline  
  stubids_[writeindex_++]=stubs;
}


 MEMMASK memmask_;

 RZBIN rzbin_;
 RZFINE rzbinfirst__, rzbinfirst___;
 RZFINE rzbindiffmax__, rzbindiffmax___;

 MEMINDEX lastmemindex;

 AllStubInner<innerRegion> innerstub__, innerstub___;
 ap_uint<1> good__, good___;
 ap_uint<1> next__, next___;
 PHIBIN ireg__, ireg___;

 VMStubTEOuter<VMSTEType> outervmstub__, outervmstub___;

 NSTUBS ns[16];

 INDEX writeindex_;
 INDEX readindex_;
 bool idle_;
 
 NSTUBS istub_;
 STUBID stubids_[1<<kNBitsBuffer];

 int instance_;

 ap_uint<1> stubptinnerlutnew_[kNBitsPTLutInner];    
 ap_uint<1> stubptouterlutnew_[kNBitsPTLutOuter];


 private:

}; // end class


#endif
