//
#include "ap_int.h"
#include "Constants.h"

static void init_idr_overlap(ap_uint<18> *lut) {

  for(unsigned int idr=0; idr<1024; idr++){
    if (idr<10) {
      lut[idr] = 0;
    } else {
      lut[idr] = (1<<n_Deltar_Overlap_)/idr;
    }
  }

}

static ap_uint<18> lut_idrinv_overlap(ap_uint<10> idr){
  ap_uint<18> LUT_idrinv_[1024];
  init_idr_overlap(LUT_idrinv_);
  return LUT_idrinv_[idr];
}

template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_LXD1 (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,
  //const TC::Types::rmean r1mean_input,
  //const TC::Types::zmean z2mean_input,
  //const TC::Types::rmean rproj0_input,
  //const TC::Types::rmean rproj1_input,
  //const TC::Types::rmean rproj2_input,
  //const TC::Types::zmean  zproj0_input,
  //const TC::Types::zmean  zproj1_input,
  //const TC::Types::zmean  zproj2_input,
  //const TC::Types::zmean  zproj3_input,

  bool * const valid_radii,
  TC::Types::rinv * const rinv_output,
  TrackletParameters::PHI0PAR * const phi0_output,
  TrackletParameters::TPAR * const t_output,
  TC::Types::z0 * const z0_output,
  TC::Types::phiL * const phiL_0_output,
  TC::Types::phiL * const phiL_1_output,
  TC::Types::phiL * const phiL_2_output,
  TC::Types::zL * const zL_0_output,
  TC::Types::zL * const zL_1_output,
  TC::Types::zL * const zL_2_output,
  TC::Types::der_phiL * const der_phiL_output,
  TC::Types::der_zL * const der_zL_output,
  TC::Types::phiD * const phiD_0_output,
  TC::Types::phiD * const phiD_1_output,
  TC::Types::phiD * const phiD_2_output,
  TC::Types::phiD * const phiD_3_output,
  TC::Types::rD * const rD_0_output,
  TC::Types::rD * const rD_1_output,
  TC::Types::rD * const rD_2_output,
  TC::Types::rD * const rD_3_output,
  TC::Types::der_phiD * const der_phiD_output,
  TC::Types::der_rD * const der_rD_output)
{
#pragma HLS pipeline II=1
#pragma HLS latency max=25

  //First convert input to right bits
  ap_uint<12> ir1c = (ap_int<10>(r1_input) << 1) + rmean[seedLayers[Seed][0]];
  ap_uint<12> ir2c = r2_input;

  const ap_int<18> phi1c = ap_int<18>(phi1_input)<<3;
  const ap_int<18> phi2c = ap_int<18>(phi2_input)<<3;

  const TC::Types::zmean z2mean = zmean[seedLayers[Seed][1]];

  const ap_int<14> z1c = z1_input;
  const ap_int<14> z2c = ap_int<7>(z2_input) + (z1c > 0 ? ap_int<14>(z2mean) : ap_int<14>(-z2mean));

  ap_int<12> idz = z2c - z1c;

  ap_uint<12> idr = (ap_int<12>(ir2c - ir1c));
  ap_uint<18> invdr = lut_idrinv_overlap(idr);

  *valid_radii = idr > floatToInt(1.5,kr); //FIXME this 1.5 is a magic number in emulation too

  ap_int<18> idelta0 = ((phi2c - phi1c)*invdr) >> n_delta0_Overlap_;
  ap_int<18> ideltaz = (idz*invdr) >> n_deltaz_Overlap_;

  ap_int<20> idelta1 = (ir1c*idelta0) >> n_delta1_;  
  ap_int<20> idelta2 = (ir2c*idelta0) >> n_delta2_;

  ap_int<20> idelta12 = (idelta1*idelta2) >> n_delta12_;

  constexpr int iHG = phiHG_*phiHG_*(1 << n_HG_);

  ap_uint<n_a_Overlap_+1> ia = ((1 << n_a_Overlap_) - ((idelta12*iHG) >> (2*n_Deltar_Overlap_ + 2*n_phi_ + n_HG_ - 2*n_delta0_Overlap_ - n_delta1_ - n_delta2_ - n_delta12_ + 1 - n_a_Overlap_)));

  constexpr int ir6fact = (1<<n_r6_Overlap_)*phiHG_*phiHG_/6.0;
  ap_int<24> ir6 = (ir1c+ir2c)*ir6fact;

  ap_int<18> idelta02 = (idelta0*idelta2) >> n_delta02_;
  
  ap_int<n_x6_+2> ix6 = (-(1 << n_x6_)+((ir6*idelta02) >> (n_r6_Overlap_ + 2*n_Deltar_Overlap_ + 2*n_phi_ - n_x6_ - n_delta2_- n_delta02_ - 2*n_delta0_Overlap_)));
  
  ap_int<18> it1 = (ir1c*ideltaz) >> (n_Deltar_Overlap_ - n_deltaz_Overlap_);

  
  ap_int<15> irinv_new = ((-idelta0*ia) >> (n_phi_ + n_a_Overlap_ - n_rinv_ + n_Deltar_Overlap_ - n_delta0_Overlap_ - n_r_ - 1));

  ap_int<18> iphi0_new = (phi1c >> (n_phi_ - n_phi0_))+((idelta1*ix6) >> (n_Deltar_Overlap_ + n_x6_ + n_phi_ - n_delta0_Overlap_ - n_delta1_ - n_phi0_));

  ap_int<14> it_new = ((ideltaz*ia) >> (n_Deltar_Overlap_ + n_a_Overlap_ + n_z_ - n_t_ - n_deltaz_Overlap_ - n_r_));

  ap_int<11> iz0_new = z1c+((it1*ix6) >> n_x6_);
  
  std::cout << "pars : " << irinv_new << " " << iphi0_new << " " << iz0_new << " " << it_new << std::endl; 


  constexpr int irproj0 = rmean[projectionLayers[Seed][0]];
  constexpr int irproj1 = rmean[projectionLayers[Seed][1]];
  constexpr int irproj2 = rmean[projectionLayers[Seed][2]];

  constexpr int irprojtilde0 = irproj0*phiHG_/sqrtsix + 0.5;
  constexpr int irprojtilde1 = irproj1*phiHG_/sqrtsix + 0.5;
  constexpr int irprojtilde2 = irproj2*phiHG_/sqrtsix + 0.5;

  const ap_int<13> rproj0 = irproj0;
  const ap_int<13> rproj1 = irproj1;
  const ap_int<13> rproj2 = irproj2;

  const ap_int<13> rprojtilde0 = irprojtilde0;
  const ap_int<13> rprojtilde1 = irprojtilde1;
  const ap_int<13> rprojtilde2 = irprojtilde2;
  
  projToLayer(rproj0, rprojtilde0, irinv_new, iphi0_new, it_new, iz0_new, *zL_0_output, *phiL_0_output);
  projToLayer(rproj1, rprojtilde1, irinv_new, iphi0_new, it_new, iz0_new, *zL_1_output, *phiL_1_output);
  projToLayer(rproj2, rprojtilde2, irinv_new, iphi0_new, it_new, iz0_new, *zL_2_output, *phiL_2_output);
  
  *der_phiL_output = -(irinv_new >> (1+3));
  *der_zL_output = it_new >> 3;

  ap_uint<20> itinv = lut_itinv(abs(it_new)&4095);

  constexpr int izproj0 = zmean[projectionDisks[Seed][0]];
  constexpr int izproj1 = zmean[projectionDisks[Seed][1]];
  constexpr int izproj2 = zmean[projectionDisks[Seed][2]];
  constexpr int izproj3 = zmean[projectionDisks[Seed][3]];

  const ap_int<14> zproj0 = izproj0;
  const ap_int<14> zproj1 = izproj1;
  const ap_int<14> zproj2 = izproj2;
  const ap_int<14> zproj3 = izproj3;

  projToDisk(zproj0, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_0_output, *phiD_0_output);
  projToDisk(zproj1, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_1_output, *phiD_1_output);
  projToDisk(zproj2, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_2_output, *phiD_2_output);
  projToDisk(zproj3, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_3_output, *phiD_3_output);

  *der_phiD_output = (-irinv_new*itinv) >> 17;
  *der_rD_output = itinv >> 5;
  
  if (it_new < 0 ) {
    *der_phiD_output = - *der_phiD_output;
    *der_rD_output =  - *der_rD_output;
  }

  //
  // wiring the outputs 
  //
  *rinv_output = irinv_new;
  *phi0_output = iphi0_new;
  *t_output = it_new;
  *z0_output = iz0_new;



<<<<<<< HEAD
//
// STEP 16

// 18 bits 	 2^(-4)Kr^(0)Kz^(1)	0.00366211
const ap_int<30> x23_0_tmp = x11_0 * x10_0;
const ap_int<18> x23_0 = x23_0_tmp >> 12;
//
// STEP 17

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> zL_0_tmp = z0 + x23_0;
const ap_int<18> zL_0 = zL_0_tmp >> 1;
//
// STEP 18

// 15 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<15> zL_0_final = zL_0 >> 3;

//
// calculating zL_1_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

// 18 bits 	 2^(-2)Kr^(0)Kz^(1)	0.0146484
const ap_int<31> x11_1_tmp = rproj1_input * t;
const ap_int<18> x11_1 = x11_1_tmp >> 13;
//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

//
// STEP 16

// 18 bits 	 2^(-4)Kr^(0)Kz^(1)	0.00366211
const ap_int<30> x23_1_tmp = x11_1 * x10_1;
const ap_int<18> x23_1 = x23_1_tmp >> 12;
//
// STEP 17

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> zL_1_tmp = z0 + x23_1;
const ap_int<18> zL_1 = zL_1_tmp >> 1;
//
// STEP 18

// 15 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<15> zL_1_final = zL_1 >> 3;

//
// calculating zL_2_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

// 18 bits 	 2^(-2)Kr^(0)Kz^(1)	0.0146484
const ap_int<31> x11_2_tmp = rproj2_input * t;
const ap_int<18> x11_2 = x11_2_tmp >> 13;
//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

//
// STEP 16

// 18 bits 	 2^(-4)Kr^(0)Kz^(1)	0.00366211
const ap_int<30> x23_2_tmp = x11_2 * x10_2;
const ap_int<18> x23_2 = x23_2_tmp >> 12;
//
// STEP 17

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> zL_2_tmp = z0 + x23_2;
const ap_int<18> zL_2 = zL_2_tmp >> 1;
//
// STEP 18

// 15 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<15> zL_2_final = zL_2 >> 3;

//
// calculating der_phiL_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

// 17 bits 	 2^(-9)Kphi^(1)Kr^(-1)	5.22747e-07
const ap_int<17> x3 = rinv>>1;
;
// 17 bits 	 2^(-9)Kphi^(1)Kr^(-1)	5.22747e-07
const ap_int<17> der_phiL = -x3;
;
//
// STEP 13

// 13 bits 	 2^(-5)Kphi^(1)Kr^(-1)	8.36396e-06
const ap_int<13> der_phiL_final = der_phiL >> 4;

//
// calculating der_zL_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

// 10 bits 	 2^(-7)Kr^(-1)Kz^(1)	0.015625
const ap_int<10> der_zL_final = t_final >> 3;

//
// calculating phiD_0_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj0 = t > 0 ? ap_int<14>(zproj0_input) : ap_int<14>(-zproj0_input-1);
//const ap_int<14> zproj0 = zproj0_input;
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

// 18 bits 	 2^(-7)Kphi^(1)Kr^(-1)	2.09099e-06
const ap_int<34> x7_tmp = x2 * a2;
const ap_int<18> x7 = x7_tmp >> 16;
//
// STEP 11
const ap_uint<11> addr_invt = (t_final>>1) & 2047; // address for the LUT
ap_int<18> invt = negDisk ? getInvtBackwardLUT<Seed>()[addr_invt] : getInvtForwardLUT<Seed>()[addr_invt];
//
// STEP 12

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_0_tmp = (ap_int<19>(zproj0)<<4) - z0;
const ap_int<18> x5_0 = x5_0_tmp >> 1;
//
// STEP 13

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_0_tmp = x5_0 * invt;
const ap_int<18> x13_0 = x13_0_tmp >> 16;
//
// STEP 14

// 18 bits 	 2^(2)Kphi^(1)Kr^(0)Kz^(0)	3.13648e-05
const ap_int<30> x25_0_tmp = x13_0 * x7;
const ap_int<18> x25_0 = x25_0_tmp >> 12;
//
// STEP 15

// 18 bits 	 2^(2)Kphi^(1)	3.13648e-05
const ap_int<19> phiD_0_tmp = phi0_final + (ap_int<19>(x25_0)<<1);
const ap_int<18> phiD_0 = phiD_0_tmp >> 1;
//
// STEP 16

// 17 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<17> phiD_0_final = phiD_0 >> 1;

//
// calculating phiD_1_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj1 = t > 0 ? ap_int<14>(zproj1_input) : ap_int<14>(-zproj1_input-1);
//const ap_int<14> zproj1 = zproj1_input;
//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_1_tmp = (ap_int<19>(zproj1)<<4) - z0;
const ap_int<18> x5_1 = x5_1_tmp >> 1;
//
// STEP 13

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_1_tmp = x5_1 * invt;
const ap_int<18> x13_1 = x13_1_tmp >> 16;
//
// STEP 14

// 18 bits 	 2^(2)Kphi^(1)Kr^(0)Kz^(0)	3.13648e-05
const ap_int<30> x25_1_tmp = x13_1 * x7;
const ap_int<18> x25_1 = x25_1_tmp >> 12;
//
// STEP 15

// 18 bits 	 2^(2)Kphi^(1)	3.13648e-05
const ap_int<19> phiD_1_tmp = phi0_final + (ap_int<19>(x25_1)<<1);
const ap_int<18> phiD_1 = phiD_1_tmp >> 1;
//
// STEP 16

// 17 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<17> phiD_1_final = phiD_1 >> 1;

//
// calculating phiD_2_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj2 = t > 0 ? ap_int<14>(zproj2_input) : ap_int<14>(-zproj2_input-1);
//const ap_int<14> zproj2 = zproj2_input;
//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_2_tmp = (ap_int<19>(zproj2)<<4) - z0;
const ap_int<18> x5_2 = x5_2_tmp >> 1;
//
// STEP 13

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_2_tmp = x5_2 * invt;
const ap_int<18> x13_2 = x13_2_tmp >> 16;
//
// STEP 14

// 18 bits 	 2^(2)Kphi^(1)Kr^(0)Kz^(0)	3.13648e-05
const ap_int<30> x25_2_tmp = x13_2 * x7;
const ap_int<18> x25_2 = x25_2_tmp >> 12;
//
// STEP 15

// 18 bits 	 2^(2)Kphi^(1)	3.13648e-05
const ap_int<19> phiD_2_tmp = phi0_final + (ap_int<19>(x25_2)<<1);
const ap_int<18> phiD_2 = phiD_2_tmp >> 1;
//
// STEP 16

// 17 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<17> phiD_2_final = phiD_2 >> 1;

//
// calculating phiD_3_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj3 = t > 0 ? ap_int<14>(zproj3_input) : ap_int<14>(-zproj3_input-1);
//const ap_int<14> zproj3 = zproj3_input;
//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_3_tmp = (ap_int<19>(zproj3)<<4) - z0;
const ap_int<18> x5_3 = x5_3_tmp >> 1;
//
// STEP 13

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_3_tmp = x5_3 * invt;
const ap_int<18> x13_3 = x13_3_tmp >> 16;
//
// STEP 14

// 18 bits 	 2^(2)Kphi^(1)Kr^(0)Kz^(0)	3.13648e-05
const ap_int<30> x25_3_tmp = x13_3 * x7;
const ap_int<18> x25_3 = x25_3_tmp >> 12;
//
// STEP 15

// 18 bits 	 2^(2)Kphi^(1)	3.13648e-05
const ap_int<19> phiD_3_tmp = phi0_final + (ap_int<19>(x25_3)<<1);
const ap_int<18> phiD_3 = phiD_3_tmp >> 1;
//
// STEP 16

// 17 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<17> phiD_3_final = phiD_3 >> 1;

//
// calculating rD_0_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

// 18 bits 	 2^(22)Kphi^(2)Kr^(0)Kz^(0)	0.000257885
const ap_int<36> x26_0_tmp = x25_0 * x25_0;
const ap_int<18> x26_0 = x26_0_tmp >> 18;
//
// STEP 16

// 18 bits 	 2^(-11)	0.000488281
const ap_int<35> x26A_0_tmp = (x26_0 * 69225);
const ap_int<18> x26A_0 = x26A_0_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x9_0_tmp = (x26A_0 * 87381);
const ap_int<18> x9_0 = x9_0_tmp >> 17;
//
// STEP 18

// 18 bits 	 2^(-12)	0.000244141
const ap_int<19> x27_0_tmp = (ap_int<19>(plus1)<<5) - x9_0;
const ap_int<18> x27_0 = x27_0_tmp >> 1;
//
// STEP 19

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<29> rD_0_tmp = x13_0 * x27_0;
const ap_int<18> rD_0 = rD_0_tmp >> 11;
//
// STEP 20

// 13 bits 	 2^(1)Kr^(1)Kz^(0)	0.0585938
const ap_int<13> rD_0_final = rD_0 >> 5;

//
// calculating rD_1_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

// 18 bits 	 2^(22)Kphi^(2)Kr^(0)Kz^(0)	0.000257885
const ap_int<36> x26_1_tmp = x25_1 * x25_1;
const ap_int<18> x26_1 = x26_1_tmp >> 18;
//
// STEP 16

// 18 bits 	 2^(-11)	0.000488281
const ap_int<35> x26A_1_tmp = (x26_1 * 69225);
const ap_int<18> x26A_1 = x26A_1_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x9_1_tmp = (x26A_1 * 87381);
const ap_int<18> x9_1 = x9_1_tmp >> 17;
//
// STEP 18

// 18 bits 	 2^(-12)	0.000244141
const ap_int<19> x27_1_tmp = (ap_int<19>(plus1)<<5) - x9_1;
const ap_int<18> x27_1 = x27_1_tmp >> 1;
//
// STEP 19

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<29> rD_1_tmp = x13_1 * x27_1;
const ap_int<18> rD_1 = rD_1_tmp >> 11;
//
// STEP 20

// 13 bits 	 2^(1)Kr^(1)Kz^(0)	0.0585938
const ap_int<13> rD_1_final = rD_1 >> 5;

//
// calculating rD_2_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

// 18 bits 	 2^(22)Kphi^(2)Kr^(0)Kz^(0)	0.000257885
const ap_int<36> x26_2_tmp = x25_2 * x25_2;
const ap_int<18> x26_2 = x26_2_tmp >> 18;
//
// STEP 16

// 18 bits 	 2^(-11)	0.000488281
const ap_int<35> x26A_2_tmp = (x26_2 * 69225);
const ap_int<18> x26A_2 = x26A_2_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x9_2_tmp = (x26A_2 * 87381);
const ap_int<18> x9_2 = x9_2_tmp >> 17;
//
// STEP 18

// 18 bits 	 2^(-12)	0.000244141
const ap_int<19> x27_2_tmp = (ap_int<19>(plus1)<<5) - x9_2;
const ap_int<18> x27_2 = x27_2_tmp >> 1;
//
// STEP 19

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<29> rD_2_tmp = x13_2 * x27_2;
const ap_int<18> rD_2 = rD_2_tmp >> 11;
//
// STEP 20

// 13 bits 	 2^(1)Kr^(1)Kz^(0)	0.0585938
const ap_int<13> rD_2_final = rD_2 >> 5;

//
// calculating rD_3_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

//
// STEP 14

//
// STEP 15

// 18 bits 	 2^(22)Kphi^(2)Kr^(0)Kz^(0)	0.000257885
const ap_int<36> x26_3_tmp = x25_3 * x25_3;
const ap_int<18> x26_3 = x26_3_tmp >> 18;
//
// STEP 16

// 18 bits 	 2^(-11)	0.000488281
const ap_int<35> x26A_3_tmp = (x26_3 * 69225);
const ap_int<18> x26A_3 = x26A_3_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x9_3_tmp = (x26A_3 * 87381);
const ap_int<18> x9_3 = x9_3_tmp >> 17;
//
// STEP 18

// 18 bits 	 2^(-12)	0.000244141
const ap_int<19> x27_3_tmp = (ap_int<19>(plus1)<<5) - x9_3;
const ap_int<18> x27_3 = x27_3_tmp >> 1;
//
// STEP 19

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<29> rD_3_tmp = x13_3 * x27_3;
const ap_int<18> rD_3 = rD_3_tmp >> 11;
//
// STEP 20

// 13 bits 	 2^(1)Kr^(1)Kz^(0)	0.0585938
const ap_int<13> rD_3_final = rD_3 >> 5;

//
// calculating der_phiD_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

// 18 bits 	 2^(-10)Kphi^(1)Kr^(0)Kz^(-1)	1.30687e-07
const ap_int<31> der_phiD_tmp = x7 * invt;
const ap_int<18> der_phiD = der_phiD_tmp >> 13;
//
// STEP 14

// 11 bits 	 2^(-3)Kphi^(1)Kr^(0)Kz^(-1)	1.67279e-05
const ap_int<11> der_phiD_final = der_phiD >> 7;

//
// calculating der_rD_final
//
//
// STEP 0

//
// STEP 1

//
// STEP 2

//
// STEP 3

//
// STEP 4

//
// STEP 5

//
// STEP 6

//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

//
// STEP 11

//
// STEP 12

//
// STEP 13

// 8 bits 	 2^(-6)Kr^(1)Kz^(-1)	0.0078125
const ap_int<8> der_rD_final = invt >> 10;



//
// wiring the outputs 
//
*rinv_output = rinv_final;
*phi0_output = phi0_final;
*t_output = t_final;
*z0_output = z0_final;
*phiL_0_output = phiL_0_final;
*phiL_1_output = phiL_1_final;
*phiL_2_output = phiL_2_final;
*zL_0_output = zL_0_final;
*zL_1_output = zL_1_final;
*zL_2_output = zL_2_final;
*der_phiL_output = der_phiL_final;
*der_zL_output = der_zL_final;
*phiD_0_output = phiD_0_final;
*phiD_1_output = phiD_1_final;
*phiD_2_output = phiD_2_final;
*phiD_3_output = phiD_3_final;
*rD_0_output = rD_0_final;
*rD_1_output = rD_1_final;
*rD_2_output = rD_2_final;
*rD_3_output = rD_3_final;
*der_phiD_output = der_phiD_final;
*der_rD_output = der_rD_final;
=======
>>>>>>> First commit of code that removes the iMath calculations for tracklet parameters and projections
}
