#ifndef TrackletAlgorithm_TrackletLUTs_h
#define TrackletAlgorithm_TrackletLUTs_h

#include "Constants.h"

template<TF::seed Seed>
class InvdrLUT{

 public: 

  InvdrLUT() {

    if (Seed <= TF::L5L6) {
      for(int idr=-256; idr<256; idr++){
	int uidr = idr;
	if (uidr < 0) uidr += 512;
	int idrabs = idr + rmean[seedLayers[Seed][1]]-rmean[seedLayers[Seed][0]];
	lut_[uidr] = (1<<n_Deltar_)/idrabs;
      }
    } else if (Seed <= TF::D3D4) {
      for(unsigned int idr=0; idr<512; idr++){
	if (idr<10) {
	  lut_[idr] = 0;
	} else {
	  lut_[idr] = (1<<n_Deltar_Disk_)/idr;
	}
      }
    } else {
      for(unsigned int idr=0; idr<1024; idr++){
	if (idr<10) {
	  lut_[idr] = 0;
	} else {
	  lut_[idr] = (1<<n_Deltar_Overlap_)/idr;
	}
      }
    }
  }

  ap_uint<18> lookup(int address) const {
    return lut_[address];
  }
  
 private:

  ap_uint<18> lut_[(Seed<=TF::D3D4)?512:1024];
  
};


class InvtLUT{

 public:

  InvtLUT() {

    int nbits = n_t_ + n_tinv_;
  
    for (int it = 0; it < 4096; it++) {
      if (it<100) {
	lut_[it] =  0;
      } else {
	lut_[it] = (1 << nbits) / it;
      }
    }

  }

 ap_uint<18> lookup(int address) const {
   return lut_[address];
 }

 private:

 ap_uint<18> lut_[4096];

};


  /*
static void init_itinv(ap_uint<18> *lut) {

  int nbits = n_t_ + n_tinv_;
  
  for (int it = 0; it < 4096; it++) {
    if (it<100) {
      lut[it] =  0;
    } else {
      lut[it] = (1 << nbits) / it;
    }
  }
}


static ap_uint<18> lut_itinv(ap_uint<14> it){
  ap_uint<18> LUT_itinv_[4096];
  init_itinv(LUT_itinv_);
  return LUT_itinv_[it];
}

  */

template<TF::seed iSeed>
class TPRegionLUT {

 public:

  inline TPRegionLUT(const ap_uint<1> *tplutinner,
		     const ap_uint<2> iAllStub) {

    nirbits_ = 0;

    if (iSeed == TF::seed::D1D2 || iSeed == TF::seed::D3D4 || 
	iSeed == TF::seed::L1D1 || iSeed == TF::seed::L2D1) {
      nirbits_ = 3;
    }

    nbitsfinephi_ = 8;

    nbendbitsinner_ = 3;

    if (iSeed == TF::seed::L5L6) {
      nbendbitsinner_ = 4;
    }

    nvmte_ = 8;
    nfinephi_ = 8;
    nbitsallstubs_ = 2;
    nbitsfinephidiff_ = 5;

    if (iSeed ==  TF::seed::L5L6 || iSeed == TF::seed::L1D1 || iSeed == TF::seed::L2D1) {
      nbitsfinephidiff_ = 6;

    }

    int address = 0;

    for (int innerfinephi = 0; innerfinephi < (1 << nbitsfinephi_); innerfinephi++) {
      for (int innerbend = 0; innerbend < (1 << nbendbitsinner_); innerbend++) {
	for (int ir = 0; ir < (1 << nirbits_); ir++) {
	  lut_[address++] = get_usereg(innerfinephi, innerbend, ir, tplutinner, iAllStub); 
	}
      }
    }
  }


  ap_uint<8> lookup(int address) const {
#pragma HLS resource variable=lut_ latency=1
    return lut_[address];
  }

 private:

  int get_usereg(int innerfinephi, int innerbend, int ir,
		 const ap_uint<1> *tplutinner,
		 const ap_uint<2> iAllStub)  const {

    unsigned int usereg = 0;
    for (int ireg = 0; ireg < nvmte_; ireg++) {
      bool match = false;
      for (int ifinephiouter = 0; ifinephiouter < nfinephi_; ifinephiouter++) {
	int outerfinephi = iAllStub * (1 << (nbitsfinephi_ - nbitsallstubs_)) +
	  ireg * nfinephi_ + ifinephiouter;
	int idphi = outerfinephi - innerfinephi;
	bool inrange = (idphi < (1 << (nbitsfinephidiff_ - 1))) && (idphi >= -(1 << (nbitsfinephidiff_ - 1)));
	if (idphi < 0)
	  idphi = idphi + (1 << nbitsfinephidiff_);
	int idphi1 = idphi;
	if (iSeed >= 4)
	  idphi1 = (idphi << 3) + ir;
	int ptinnerindexnew = (idphi1 << nbendbitsinner_) + innerbend;
	match = match || (inrange && tplutinner[ptinnerindexnew]);
      }
      if (match) {
	usereg = usereg | (1 << ireg);
      }
    }

    return usereg;

  } 

  int nirbits_;
  int nbitsfinephi_;
  unsigned int nbendbitsinner_;
  int nvmte_;
  int nfinephi_;
  int nbitsallstubs_;
  int nbitsfinephidiff_;
   
  ap_uint<8> lut_[iSeed<4?(iSeed<3?2048:4096):16384];

};

#endif
