#ifndef TRACKLETENGINEUNIT_H
#define TRACKLETENGINEUNIT_H

#include "Constants.h"
#include "VMStubTEOuterMemoryCM.h"
#include "TrackletProcessor_parameters.h"
#include "TrackletParameterMemory.h"

template<TF::seed Seed, TP::itc iTC, regionType innerRegion,regionType VMSTEType>
class TrackletEngineUnit {

 public:
  enum BitWidths{
    kNBitsBuffer=3,
    kNBitsRZBin=3,
    kNBitsRZFine=3,
    kNBitsPhiBins=3,
    kNBitsNegDiskSize=1,
    kNBitsPTLutInner=(Seed==TF::L5L6||Seed==TF::L1D1||Seed==TF::L2D1||Seed==TF::D1D2||Seed==TF::D3D4)?1024:(Seed==TF::L1L2||Seed==TF::L2L3||Seed==TF::L3L4)?256:512,
    kNBitsPTLutOuter=(Seed==TF::L5L6||Seed==TF::L1D1||Seed==TF::L2D1||Seed==TF::D1D2||Seed==TF::D3D4)?1024:(Seed==TF::L1L2||Seed==TF::L2L3)?256:512
  };

  typedef ap_uint<VMStubTEOuter<VMSTEType>::kVMSTEOIDSize+AllStub<innerRegion>::kAllStubSize+TrackletParameters::kTParPhiRegionSize+kNBits_MemAddr> STUBID;
  typedef ap_uint<kNBitsNegDiskSize> NEGDISK;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUBS;
  typedef ap_uint<kNBitsBuffer> INDEX;
  typedef ap_uint<kNBitsRZBin> RZBIN;
  typedef ap_uint<kNBitsRZFine> RZFINE;
  typedef ap_uint<kNBitsPhiBins> PHIBIN;
  typedef ap_uint<kNBitsPhiBins+1> MEMINDEX;  //Index into MEMMASK and MEMSTUBS
  typedef ap_uint<2*(1<<kNBitsPhiBins)> MEMMASK;  //Bit mask for used bins for two RZbins
  typedef ap_uint<2*(1<<kNBitsPhiBins)*4> MEMSTUBS; //Number of stubs in bins for two RZbins //FIXME for 4


 TrackletEngineUnit() {

#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew_ dim=1

   //
   // The multiple copies 1_, 2_, .. _4 of the LUTs is due to an 
   // HLS limit where we can only have 1024 entries and we work 
   // around this by having four separate LUTs.
   //
#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew1_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew2_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew3_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptinnerlutnew4_ dim=1

#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew1_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew2_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew3_ dim=1
#pragma HLS ARRAY_PARTITION variable=stubptouterlutnew4_ dim=1

/////  Grabs the appropriate lut based on seed and iTC

   const ap_uint<1>* stubptinnertmp = TP::getPTInnerLUT<Seed,iTC>();
   const ap_uint<1>* stubptoutertmp = TP::getPTOuterLUT<Seed,iTC>();
    if ( Seed <= TF::L5L6 ){
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew_[i] = stubptinnertmp[i];
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew_[i] = stubptoutertmp[i];
      }
    }
//split the LUTs for overlaps/disks Vivado can only handle up to 1024 length LUT
    else if ( Seed >= TF::D1D2){   //Split 4 ways for overlaps, 2 ways for disks
      for(unsigned int i=0;i<kNBitsPTLutInner;i++) {
#pragma HLS unroll
        stubptinnerlutnew1_[i] = stubptinnertmp[i];
        stubptinnerlutnew2_[i] = stubptinnertmp[i+1024];
        if (Seed >= TF::L1D1){
          stubptinnerlutnew3_[i] = stubptinnertmp[i+2048];
          stubptinnerlutnew4_[i] = stubptinnertmp[i+3072];
        }
      }
      for(unsigned int i=0;i<kNBitsPTLutOuter;i++) {
#pragma HLS unroll
        stubptouterlutnew1_[i] = stubptoutertmp[i];
        stubptouterlutnew2_[i] = stubptoutertmp[i+1024];
        if (Seed >= TF::L1D1){
          stubptouterlutnew3_[i] = stubptoutertmp[i+2048];
          stubptouterlutnew4_[i] = stubptoutertmp[i+3072];
        }
      }
    }
    idle_ = true;
 }


 MEMSTUBS nstub16() const {
#pragma HLS array_partition variable=ns dim=1
   return (ns[15],ns[14],ns[13],ns[12],ns[11],ns[10],ns[9],ns[8],ns[7],ns[6],ns[5],ns[4],ns[3],ns[2],ns[1],ns[0]);
 }

 void setnstub16(MEMSTUBS nstubs) {
#pragma HLS array_partition variable=ns dim=1
   (ns[15],ns[14],ns[13],ns[12],ns[11],ns[10],ns[9],ns[8],ns[7],ns[6],ns[5],ns[4],ns[3],ns[2],ns[1],ns[0]) = nstubs;
 }

 NSTUBS calcNStubs(MEMSTUBS nstubs, MEMMASK mask) {

 NSTUBS n[16];
#pragma HLS array_partition variable=n dim=1
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
 RZBIN ibin__, ibin___;
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
 NEGDISK negDisk_[1<<kNBitsBuffer];

 int instance_;

 ap_uint<1> stubptinnerlutnew_[kNBitsPTLutInner];
 ap_uint<1> stubptouterlutnew_[kNBitsPTLutOuter];


 ap_uint<1> stubptinnerlutnew1_[kNBitsPTLutInner];
 ap_uint<1> stubptinnerlutnew2_[kNBitsPTLutInner];
 ap_uint<1> stubptinnerlutnew3_[kNBitsPTLutInner];
 ap_uint<1> stubptinnerlutnew4_[kNBitsPTLutInner];

 ap_uint<1> stubptouterlutnew1_[kNBitsPTLutOuter];
 ap_uint<1> stubptouterlutnew2_[kNBitsPTLutOuter];
 ap_uint<1> stubptouterlutnew3_[kNBitsPTLutOuter];
 ap_uint<1> stubptouterlutnew4_[kNBitsPTLutOuter];


 private:

}; // end class


#endif
