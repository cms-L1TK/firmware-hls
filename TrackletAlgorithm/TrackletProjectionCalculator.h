#ifndef TrackletAlgorithm_TrackletProjectionCalculator_h
#define TrackletAlgorithm_TrackletProjectionCalculator_h
#include "Constants.h"

inline void projToLayer(ap_uint<13> ir, ap_uint<13> irtilde, 
			int irinv, int iphi0, int it,int iz0, 
			TP::Types::zL &iz, TP::Types::phiL &iphi) {

  ap_int<20> is =  (irtilde*irinv) >> n_s_;

  ap_uint<n_s6_+2> is6 =  (1 << n_s6_) + ((is*is) >> (2 + 2*n_r_ + 2*n_rinv_ - 2*n_s_ - n_s6_));

  ap_int<20> iu = (ir*irinv) >> (n_r_ + n_rinv_ + 1 - n_phi_);

  iphi = (iphi0 << (n_phi_ - n_phi0_)) - ((iu*is6) >> n_s6_);

  ap_int<20> iv = (it*ir) >> (n_r_ + n_t_ - n_z_);

  iz = iz0 + ((iv*is6) >> n_s6_);

}

inline void projToDisk(int iz, int itinv, int irinv, int iphi0,
		       int it,int iz0, TP::Types::rD  &ir, 
		       TP::Types::phiD  &iphi) {

  ap_int<14> iz0_sign = (it>0)?iz0:-iz0;
  
  ap_int<14> iw = (((iz << (n_r_ - n_z_)) - (iz0_sign << (n_r_ - n_z_)))*itinv) >> n_tinv_;

  iphi = (iphi0 >> (n_phi0_ - n_phidisk_)) - ((iw*irinv) >> (1 + n_r_ + n_rinv_ - n_phidisk_));

  constexpr int ifact = (1 << n_y_)*phiHG_/sqrtsix;

  ap_int<14> iy = (ifact * irinv) >> n_y_;

  ap_int<20> ix = (iw*iy) >> n_x_;

  ap_uint<n_xx6_+1> ix6 = (1 << n_xx6_) - ( (ix*ix) >> (2 + 2*n_r_ + 2*n_rinv_ - 2*n_x_ - n_xx6_));

  ir = (iw*ix6) >> (n_r_ - n_rdisk_ + n_xx6_);

}


#endif
