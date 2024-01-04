//
static void init_idr_disk(ap_uint<20> *lut) {

  for(unsigned int idr=0; idr<512; idr++){
    if (idr<10) {
      lut[idr] = 0;
    } else {
      lut[idr] = (1<<n_Deltar_Disk_)/idr;
    }
  }
}

static ap_uint<20> lut_idrinv_disk(ap_uint<10> idr){
  ap_uint<20> LUT_idrinv_[512];
  init_idr_disk(LUT_idrinv_);
  return LUT_idrinv_[idr];
}


#include "ap_int.h"
template <TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_DXDY (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,
  //const TC::Types::zmean z1mean_input,
  //const TC::Types::zmean z2mean_input,
  //const TC::Types::rmean rproj0_input,
  //const TC::Types::rmean rproj1_input,
  //const TC::Types::rmean rproj2_input,
  //const TC::Types::zmean  zproj0_input,
  //const TC::Types::zmean  zproj1_input,
  //const TC::Types::zmean  zproj2_input,
  const bool negDisk,

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
  TC::Types::rD * const rD_0_output,
  TC::Types::rD * const rD_1_output,
  TC::Types::rD * const rD_2_output,
  TC::Types::der_phiD * const der_phiD_output,
  TC::Types::der_rD * const der_rD_output

)
{
#pragma HLS pipeline II=1
#pragma HLS latency max=25


  //First convert input to right bits
  ap_uint<12> ir1c = r1_input;
  ap_uint<12> ir2c = r2_input;

  const ap_int<18> phi1c = ap_int<18>(phi1_input)<<3;
  const ap_int<18> phi2c = ap_int<18>(phi2_input)<<3;

  const TC::Types::zmean z1mean = zmean[seedLayers[Seed][0]];
  const TC::Types::zmean z2mean = zmean[seedLayers[Seed][1]];

  const ap_int<14> z1c = z1_input + (negDisk ? ap_int<14>(-z1mean) : ap_int<14>(z1mean));
  const ap_int<14> z2c = z2_input + (negDisk ? ap_int<14>(-z2mean) : ap_int<14>(z2mean));

  ap_int<12> idz = z2c - z1c;

  ap_uint<12> idr = ap_int<12>(ir2c - ir1c);
  ap_uint<20> invdr = lut_idrinv_disk(idr);

  ap_int<18> idelta0 = ((phi2c - phi1c)*invdr) >> n_delta0_;
  ap_int<18> ideltaz = (idz*invdr) >> n_deltaz_;

  ap_int<20> idelta1 = (ir1c*idelta0) >> n_delta1_;  
  ap_int<20> idelta2 = (ir2c*idelta0) >> n_delta2_;

  ap_int<20> idelta12 = (idelta1*idelta2) >> n_delta12_;

  constexpr int iHG = phiHG_*phiHG_*(1 << n_HG_);

  ap_uint<n_a_+1> ia = ((1 << n_a_) - ((idelta12*iHG) >> (2*n_Deltar_Disk_ + 2*n_phi_ + n_HG_ - 2*n_delta0_ - n_delta1_ - n_delta2_ - n_delta12_ + 1 - n_a_)));

  constexpr int ir6fact = (1<<n_r6_)*phiHG_*phiHG_/6.0;
  ap_int<24> ir6 = (ir1c+ir2c)*ir6fact;

  ap_int<18> idelta02 = (idelta0*idelta2) >> n_delta02_;
  
  ap_int<n_x6_+2> ix6 = (-(1 << n_x6_)+((ir6*idelta02) >> (n_r6_ + 2*n_Deltar_Disk_ + 2*n_phi_ - n_x6_ - n_delta2_- n_delta02_ - 2*n_delta0_)));
  
  ap_int<18> it1 = (ir1c*ideltaz) >> (n_Deltar_Disk_ - n_deltaz_);

  
  ap_int<15> irinv_new = ((-idelta0*ia) >> (n_phi_ + n_a_ - n_rinv_ + n_Deltar_Disk_ - n_delta0_ - n_r_ - 1));

  ap_int<18> iphi0_new = (phi1c >> (n_phi_ - n_phi0_))+((idelta1*ix6) >> (n_Deltar_Disk_ + n_x6_ + n_phi_ - n_delta0_ - n_delta1_ - n_phi0_));

  ap_int<14> it_new = ((ideltaz*ia) >> (n_Deltar_Disk_ + n_a_ + n_z_ - n_t_ - n_deltaz_ - n_r_));

  ap_int<12> iz0_new = z1c+((it1*ix6) >> n_x6_);

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

  const ap_int<14> zproj0 = izproj0;
  const ap_int<14> zproj1 = izproj1;
  const ap_int<14> zproj2 = izproj2;

  projToDisk(zproj0, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_0_output, *phiD_0_output);
  projToDisk(zproj1, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_1_output, *phiD_1_output);
  projToDisk(zproj2, itinv, irinv_new, iphi0_new, it_new, iz0_new, *rD_2_output, *phiD_2_output);

  *der_phiD_output = (-irinv_new*itinv) >> 17;
  *der_rD_output = itinv >> 5;

  if (it_new < 0 ) {
    *der_phiD_output = - *der_phiD_output;
    *der_rD_output =  - *der_rD_output;
  }

  std::cout << "Disk proj: " << *rD_0_output << " " << *phiD_0_output << " " << *der_phiD_output << " " << *der_rD_output << std::endl;
  
  //
  // wiring the outputs 
  //
  *rinv_output = irinv_new;
  *phi0_output = iphi0_new;
  *t_output = it_new;
  *z0_output = iz0_new;


<<<<<<< HEAD
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

// 18 bits 	 2^(-1)Kr^(0)Kz^(1)	0.0292969
const ap_int<31> x11_1_tmp = rproj1_input * t;
const ap_int<18> x11_1 = x11_1_tmp >> 13;
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

// 18 bits 	 2^(-3)Kr^(0)Kz^(1)	0.00732422
const ap_int<31> x23_1_tmp = x11_1 * x10_1;
const ap_int<18> x23_1 = x23_1_tmp >> 13;
//
// STEP 16

// 18 bits 	 2^(-2)Kz^(1)	0.0146484
const ap_int<20> zL_1_tmp = z0 + (ap_int<20>(x23_1)<<1);
const ap_int<18> zL_1 = zL_1_tmp >> 2;
//
// STEP 17

// 16 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<16> zL_1_final = zL_1 >> 2;

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

// 18 bits 	 2^(-1)Kr^(0)Kz^(1)	0.0292969
const ap_int<31> x11_2_tmp = rproj2_input * t;
const ap_int<18> x11_2 = x11_2_tmp >> 13;
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

// 18 bits 	 2^(-3)Kr^(0)Kz^(1)	0.00732422
const ap_int<31> x23_2_tmp = x11_2 * x10_2;
const ap_int<18> x23_2 = x23_2_tmp >> 13;
//
// STEP 16

// 18 bits 	 2^(-2)Kz^(1)	0.0146484
const ap_int<20> zL_2_tmp = z0 + (ap_int<20>(x23_2)<<1);
const ap_int<18> zL_2 = zL_2_tmp >> 2;
//
// STEP 17

// 16 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<16> zL_2_final = zL_2 >> 2;

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

// 17 bits 	 2^(-10)Kphi^(1)Kr^(-1)	2.61374e-07
const ap_int<17> x3 = rinv>>1;
;
// 17 bits 	 2^(-10)Kphi^(1)Kr^(-1)	2.61374e-07
const ap_int<17> der_phiL = -x3;
;
//
// STEP 12

// 12 bits 	 2^(-5)Kphi^(1)Kr^(-1)	8.36396e-06
const ap_int<12> der_phiL_final = der_phiL >> 5;

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

// 11 bits 	 2^(-7)Kr^(-1)Kz^(1)	0.015625
const ap_int<11> der_zL_final = t_final >> 3;

//
// calculating phiD_0_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj0 = t > 0 ? ap_int<14>(zproj0_input) : ap_int<14>(-zproj0_input-1);
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

// 18 bits 	 2^(-8)Kphi^(1)Kr^(-1)	1.04549e-06
const ap_int<35> x7_tmp = x2 * a2;
const ap_int<18> x7 = x7_tmp >> 17;
//
// STEP 10
const ap_uint<11> addr_invt = (t_final>>1) & 2047; // address for the LUT
ap_int<18> invt  = negDisk ? getInvtBackwardLUT<Seed>()[addr_invt] : getInvtForwardLUT<Seed>()[addr_invt];



//
// STEP 11

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_0_tmp = (ap_int<19>(zproj0)<<4) - z0;
const ap_int<18> x5_0 = x5_0_tmp >> 1;
//
// STEP 12

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_0_tmp = x5_0 * invt;
const ap_int<18> x13_0 = x13_0_tmp >> 16;
//
// STEP 13

// 18 bits 	 2^(0)Kphi^(1)Kr^(0)Kz^(0)	7.84121e-06
const ap_int<29> x25_0_tmp = x13_0 * x7;
const ap_int<18> x25_0 = x25_0_tmp >> 11;
//
// STEP 14

// 18 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiD_0_tmp = (ap_int<19>(phi0_final)<<1) + x25_0;
const ap_int<18> phiD_0 = phiD_0_tmp >> 1;
//
// STEP 15

// 16 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<16> phiD_0_final = phiD_0 >> 2;

//
// calculating phiD_1_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj1 = t > 0 ? ap_int<14>(zproj1_input) : ap_int<14>(-zproj1_input-1);
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

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_1_tmp = (ap_int<19>(zproj1)<<4) - z0;
const ap_int<18> x5_1 = x5_1_tmp >> 1;
//
// STEP 12

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_1_tmp = x5_1 * invt;
const ap_int<18> x13_1 = x13_1_tmp >> 16;
//
// STEP 13

// 18 bits 	 2^(0)Kphi^(1)Kr^(0)Kz^(0)	7.84121e-06
const ap_int<29> x25_1_tmp = x13_1 * x7;
const ap_int<18> x25_1 = x25_1_tmp >> 11;
//
// STEP 14

// 18 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiD_1_tmp = (ap_int<19>(phi0_final)<<1) + x25_1;
const ap_int<18> phiD_1 = phiD_1_tmp >> 1;
//
// STEP 15

// 16 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<16> phiD_1_final = phiD_1 >> 2;

//
// calculating phiD_2_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<14> zproj2 = t > 0 ? ap_int<14>(zproj2_input) : ap_int<14>(-zproj2_input-1);
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

// 18 bits 	 2^(-3)Kz^(1)	0.00732422
const ap_int<19> x5_2_tmp = (ap_int<19>(zproj2)<<4) - z0;
const ap_int<18> x5_2 = x5_2_tmp >> 1;
//
// STEP 12

// 18 bits 	 2^(-3)Kr^(1)Kz^(0)	0.00366211
const ap_int<34> x13_2_tmp = x5_2 * invt;
const ap_int<18> x13_2 = x13_2_tmp >> 16;
//
// STEP 13

// 18 bits 	 2^(0)Kphi^(1)Kr^(0)Kz^(0)	7.84121e-06
const ap_int<29> x25_2_tmp = x13_2 * x7;
const ap_int<18> x25_2 = x25_2_tmp >> 11;
//
// STEP 14

// 18 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiD_2_tmp = (ap_int<19>(phi0_final)<<1) + x25_2;
const ap_int<18> phiD_2 = phiD_2_tmp >> 1;
//
// STEP 15

// 16 bits 	 2^(3)Kphi^(1)	6.27297e-05
const ap_int<16> phiD_2_final = phiD_2 >> 2;

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

// 18 bits 	 2^(18)Kphi^(2)Kr^(0)Kz^(0)	1.61178e-05
const ap_int<36> x26_0_tmp = x25_0 * x25_0;
const ap_int<18> x26_0 = x26_0_tmp >> 18;
//
// STEP 15

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x26A_0_tmp = (x26_0 * 69225);
const ap_int<18> x26A_0 = x26A_0_tmp >> 17;
//
// STEP 16

// 18 bits 	 2^(-17)	7.62939e-06
const ap_int<35> x9_0_tmp = (x26A_0 * 87381);
const ap_int<18> x9_0 = x9_0_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<20> x27_0_tmp = (ap_int<20>(plus1)<<9) - x9_0;
const ap_int<18> x27_0 = x27_0_tmp >> 2;
//
// STEP 18

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<32> rD_0_tmp = x13_0 * x27_0;
const ap_int<18> rD_0 = rD_0_tmp >> 14;
//
// STEP 19

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

// 18 bits 	 2^(18)Kphi^(2)Kr^(0)Kz^(0)	1.61178e-05
const ap_int<36> x26_1_tmp = x25_1 * x25_1;
const ap_int<18> x26_1 = x26_1_tmp >> 18;
//
// STEP 15

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x26A_1_tmp = (x26_1 * 69225);
const ap_int<18> x26A_1 = x26A_1_tmp >> 17;
//
// STEP 16

// 18 bits 	 2^(-17)	7.62939e-06
const ap_int<35> x9_1_tmp = (x26A_1 * 87381);
const ap_int<18> x9_1 = x9_1_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<20> x27_1_tmp = (ap_int<20>(plus1)<<9) - x9_1;
const ap_int<18> x27_1 = x27_1_tmp >> 2;
//
// STEP 18

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<32> rD_1_tmp = x13_1 * x27_1;
const ap_int<18> rD_1 = rD_1_tmp >> 14;
//
// STEP 19

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

// 18 bits 	 2^(18)Kphi^(2)Kr^(0)Kz^(0)	1.61178e-05
const ap_int<36> x26_2_tmp = x25_2 * x25_2;
const ap_int<18> x26_2 = x26_2_tmp >> 18;
//
// STEP 15

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x26A_2_tmp = (x26_2 * 69225);
const ap_int<18> x26A_2 = x26A_2_tmp >> 17;
//
// STEP 16

// 18 bits 	 2^(-17)	7.62939e-06
const ap_int<35> x9_2_tmp = (x26A_2 * 87381);
const ap_int<18> x9_2 = x9_2_tmp >> 17;
//
// STEP 17

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<20> x27_2_tmp = (ap_int<20>(plus1)<<9) - x9_2;
const ap_int<18> x27_2 = x27_2_tmp >> 2;
//
// STEP 18

// 18 bits 	 2^(-4)Kr^(1)Kz^(0)	0.00183105
const ap_int<32> rD_2_tmp = x13_2 * x27_2;
const ap_int<18> rD_2 = rD_2_tmp >> 14;
//
// STEP 19

// 13 bits 	 2^(1)Kr^(1)Kz^(0)	0.0585938
const ap_int<13> rD_2_final = rD_2 >> 5;

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

// 18 bits 	 2^(-12)Kphi^(1)Kr^(0)Kz^(-1)	3.26717e-08
const ap_int<30> der_phiD_tmp = x7 * invt;
const ap_int<18> der_phiD = der_phiD_tmp >> 12;
//
// STEP 13

// 9 bits 	 2^(-3)Kphi^(1)Kr^(0)Kz^(-1)	1.67279e-05
const ap_int<9> der_phiD_final = der_phiD >> 9;

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
*rD_0_output = rD_0_final;
*rD_1_output = rD_1_final;
*rD_2_output = rD_2_final;
*der_phiD_output = der_phiD_final;
*der_rD_output = der_rD_final;
=======
>>>>>>> First commit of code that removes the iMath calculations for tracklet parameters and projections
}
