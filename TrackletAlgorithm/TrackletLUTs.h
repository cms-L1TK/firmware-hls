#ifndef TrackletAlgorithm_TrackletLUTs_h
#define TrackletAlgorithm_TrackletLUTs_h

#include "Constants.h"

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

  TPRegionLUT(const ap_uint<1> *tplutinner,
	      const ap_uint<2> iAllStub) {

    int nirbits = 0;
    if (iSeed == TF::seed::D1D2 || iSeed == TF::seed::D3D4 || iSeed == TF::seed::L1D1 || iSeed == TF::seed::L2D1) {
      nirbits = 3;
    }

    int nbitsfinephi = 8;

    unsigned int nbendbitsinner = 3;

    if (iSeed == TF::seed::L5L6) {
      nbendbitsinner = 4;
    }

    int nvmte = 8;
    int nfinephi = 8;
    //int iAllStub = 4;
    int nbitsallstubs = 2;
    int nbitsfinephidiff = 5;
    if (iSeed ==  TF::seed::L5L6 || iSeed == TF::seed::L1D1 || iSeed == TF::seed::L2D1) {
      nbitsfinephidiff = 6;
    }

    int address = 0;

    for (int innerfinephi = 0; innerfinephi < (1 << nbitsfinephi); innerfinephi++) {
      for (int innerbend = 0; innerbend < (1 << nbendbitsinner); innerbend++) {
	for (int ir = 0; ir < (1 << nirbits); ir++) {
	  unsigned int usereg = 0;
	  for (int ireg = 0; ireg < nvmte; ireg++) {
	    bool match = false;
	    for (int ifinephiouter = 0; ifinephiouter < nfinephi; ifinephiouter++) {
	      int outerfinephi = iAllStub * (1 << (nbitsfinephi - nbitsallstubs)) +
		ireg * nfinephi + ifinephiouter;
	      int idphi = outerfinephi - innerfinephi;
	      bool inrange = (idphi < (1 << (nbitsfinephidiff - 1))) && (idphi >= -(1 << (nbitsfinephidiff - 1)));
	      if (idphi < 0)
		idphi = idphi + (1 << nbitsfinephidiff);
	      int idphi1 = idphi;
	      if (iSeed >= 4)
		idphi1 = (idphi << 3) + ir;
	      int ptinnerindexnew = (idphi1 << nbendbitsinner) + innerbend;
	      if (address == 8174) {
		if (inrange) {
		  std::cout << "inrange idphi nbitsfinephidiff ptinnerindexnew tplutinner : "<<
		    inrange << " " << idphi << " " << nbitsfinephidiff 
			    << " " << ptinnerindexnew << " " 
			    << tplutinner[ptinnerindexnew]<<std::endl;
		} else {
		  std::cout << "inrange idphi ptinnerindexnew tplutinner : "<<
		    inrange << " " << idphi << " " << ptinnerindexnew << " --------" <<std::endl;
		}
	      }
	      match = match || (inrange && tplutinner[ptinnerindexnew]);
	    }
	    if (match) {
	      usereg = usereg | (1 << ireg);
	    }
	  }
	  if (address == 8173) {
	    std::cout << "LUT address usereg : " << address << " " << usereg << std::endl;
	  }
	  lut_[address++] = usereg;
	}
      }
    }
  }

 ap_uint<8> lookup(int address) const {
   return lut_[address];
 }

 private:

 ap_uint<8> lut_[iSeed<4?(iSeed<3?2048:4096):16384];

};

#endif
