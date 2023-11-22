//
// This code is auto generated in the emulation by imath and should
// not be modified
//
#include "ap_int.h"
#include "Constants.h"
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_LXD1 (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,
  const TC::Types::rmean r1mean_input,
  const TC::Types::zmean z2mean_input,
  const TC::Types::rmean rproj0_input,
  const TC::Types::rmean rproj1_input,
  const TC::Types::rmean rproj2_input,
  const TC::Types::zmean  zproj0_input,
  const TC::Types::zmean  zproj1_input,
  const TC::Types::zmean  zproj2_input,
  const TC::Types::zmean  zproj3_input,

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
//
// calculating rinv_final
//
//
// STEP 0

// 10 bits 	 2^(-7)	0.0078125
static const ap_int<10> plus2 = 256;
// units 2^(0)Kr^(1)	0.0292969
const ap_int<8> r1 = ap_int<8>(r1_input)<<1;
// 13 bits 	 2^(0)Kr^(1)	0.0292969
// units 2^(0)Kphi^(1)	7.84121e-06
const ap_int<18> phi2 = ap_int<18>(phi2_input)<<3;
// units 2^(0)Kphi^(1)	7.84121e-06
const ap_int<18> phi1 = ap_int<18>(phi1_input)<<3;
// units 2^(0)Kr^(1)	0.0292969
const ap_int<13> r2 = ap_uint<12>(r2_input); //cast r2 as unsigned since all disk radii are positive only
//
// STEP 1

// 13 bits 	 2^(0)Kr^(1)	0.0292969
const ap_int<13> r1abs = r1 + r1mean_input;
// 16 bits 	 2^(0)Kphi^(1)	7.84121e-06
const ap_int<16> dphi = phi2 - phi1;
//
// STEP 2

// 12 bits 	 2^(0)Kr^(1)	0.0292969
const ap_int<11> dr = r2 - r1abs;
//
// STEP 3
//protection from wrong radii
*valid_radii = dr > (floatToInt(1.5,kr)); //FIXME this 1.5 is a magic number in emulation too

bool negDisk = z2mean_input<=0;

ap_int<19> drinv;
const ap_uint<11> addr_drinv = dr & 2047; // address for the LUT

if (Seed == TF::L1D1){
  if (negDisk){
#ifndef __SYNTHESIS__
    static ap_int<19> LUT_drinv[2048];
    readSWLUT<ap_int<19>,2048>(LUT_drinv, "../../../../../emData/LUTs/TC_L1B1_drinv.tab",false,true);
#else
    static const ap_int<19> LUT_drinv[2048] = {
  #if __has_include("../emData/LUTs/TC_L1B1_drinv.tab")
  #  include "../emData/LUTs/TC_L1B1_drinv.tab"
  #endif
    };
#endif
    drinv = LUT_drinv[addr_drinv];
  }
  else{
#ifndef __SYNTHESIS__
    static ap_int<19> LUT_drinv[2048];
    readSWLUT<ap_int<19>,2048>(LUT_drinv, "../../../../../emData/LUTs/TC_L1F1_drinv.tab",false,true);
#else
    static const ap_int<19> LUT_drinv[2048] = {
  #if __has_include("../emData/LUTs/TC_L1F1_drinv.tab")
  #  include "../emData/LUTs/TC_L1F1_drinv.tab"
  #endif
    };
#endif
    drinv = LUT_drinv[addr_drinv];
  }
}
else{
  if (negDisk){
#ifndef __SYNTHESIS__
    static ap_int<19> LUT_drinv[2048];
    readSWLUT<ap_int<19>,2048>(LUT_drinv, "../../../../../emData/LUTs/TC_L2B1_drinv.tab",false,true);
#else
    static const ap_int<19> LUT_drinv[2048] = {
  #if __has_include("../emData/LUTs/TC_L2B1_drinv.tab")
  #  include "../emData/LUTs/TC_L2B1_drinv.tab"
  #endif
    };
#endif
    drinv = LUT_drinv[addr_drinv];
  }
  else{
#ifndef __SYNTHESIS__
    static ap_int<19> LUT_drinv[2048];
    readSWLUT<ap_int<19>,2048>(LUT_drinv, "../../../../../emData/LUTs/TC_L2F1_drinv.tab",false,true);
#else
    static const ap_int<19> LUT_drinv[2048] = {
  #if __has_include("../emData/LUTs/TC_L2F1_drinv.tab")
  #  include "../emData/LUTs/TC_L2F1_drinv.tab"
  #endif
    };
#endif
    drinv = LUT_drinv[addr_drinv];
  }
}
//
// STEP 4

//
// STEP 5

// 18 bits 	 2^(-9)Kphi^(1)Kr^(-1)	5.22747e-07
const ap_int<32> delta0_tmp = dphi * drinv;
const ap_int<18> delta0 = delta0_tmp >> 14;
//
// STEP 6

// 18 bits 	 2^(4)Kphi^(1)Kr^(0)	0.000125459
const ap_int<31> delta1_tmp = r1abs * delta0;
const ap_int<18> delta1 = delta1_tmp >> 13;
// 18 bits 	 2^(4)Kphi^(1)Kr^(0)	0.000125459
const ap_int<31> delta2_tmp = r2 * delta0;
const ap_int<18> delta2 = delta2_tmp >> 13;
//
// STEP 7

// 18 bits 	 2^(19)Kphi^(2)Kr^(0)	3.22356e-05
const ap_int<29> a2a_tmp = delta1 * delta2;
const ap_int<18> a2a = a2a_tmp >> 11;
//
// STEP 8

// 18 bits 	 2^(-14)	6.10352e-05
const ap_int<35> a2b_tmp = (a2a * 69225);
const ap_int<18> a2b = a2b_tmp >> 17;
//
// STEP 9

// 17 bits 	 2^(-14)	6.10352e-05
const ap_int<17> a2 = (ap_int<17>(plus2)<<7) - a2b;
//
// STEP 10

// 17 bits 	 2^(-14)	6.10352e-05
const ap_int<17> a2n = -a2;
;
//
// STEP 11

// 18 bits 	 2^(-9)Kphi^(1)Kr^(-1)	5.22747e-07
const ap_int<32> rinv_tmp = a2n * delta0;
const ap_int<18> rinv = rinv_tmp >> 14;
//
// STEP 12

// 17 bits 	 2^(-8)Kphi^(1)Kr^(-1)	1.04549e-06
const ap_int<17> rinv_final = rinv >> 1;

//
// calculating phi0_final
//
//
// STEP 0

// 10 bits 	 2^(-8)	0.00390625
static const ap_int<10> minus1 = -256;
//
// STEP 1

//
// STEP 2

// 14 bits 	 2^(0)Kr^(1)	0.0292969
const ap_int<14> Rabs = r1abs + r2;
//
// STEP 3

// 14 bits 	 2^(-2)Kr^(1)	0.00732422
const ap_int<26> R6_tmp = (Rabs * 2730);
const ap_int<14> R6 = R6_tmp >> 12;
//
// STEP 4

//
// STEP 5

//
// STEP 6

// 18 bits 	 2^(3)Kphi^(1)Kr^(0)	6.27297e-05
const ap_int<32> x4_tmp = R6 * delta0;
const ap_int<18> x4 = x4_tmp >> 14;
//
// STEP 7

// 18 bits 	 2^(17)Kphi^(2)Kr^(0)	8.05891e-06
const ap_int<28> x6a_tmp = delta2 * x4;
const ap_int<18> x6a = x6a_tmp >> 10;
//
// STEP 8

// 18 bits 	 2^(-16)	1.52588e-05
const ap_int<35> x6b_tmp = (x6a * 69225);
const ap_int<18> x6b = x6b_tmp >> 17;
//
// STEP 9

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<19> x6m_tmp = (ap_int<19>(minus1)<<8) + x6b;
const ap_int<18> x6m = x6m_tmp >> 1;
//
// STEP 10

// 18 bits 	 2^(0)Kphi^(1)Kr^(0)	7.84121e-06
const ap_int<29> phi0a_tmp = delta1 * x6m;
const ap_int<18> phi0a = phi0a_tmp >> 11;
//
// STEP 11

// 18 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phi0_tmp = phi1 + phi0a;
const ap_int<18> phi0_final = phi0_tmp >> 1;
//
// STEP 12

// 18 bits 	 2^(1)Kphi^(1)	1.56824e-05

//
// calculating t_final
//
//
// STEP 0

// units 2^(0)Kz^(1)	0.0585938
const ap_int<7> z2 = ap_int<7>(z2_input);
// 14 bits 	 2^(0)Kz^(1)	0.0585938
// units 2^(0)Kz^(1)	0.0585938
const ap_int<12> z1 = ap_int<12>(z1_input);
//
// STEP 1

// 14 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<14> z2abs = z2 + z2mean_input;
//
// STEP 2

// 12 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<12> dz = z2abs - z1;
//
// STEP 3

//
// STEP 4

//
// STEP 5

// 18 bits 	 2^(-14)Kr^(-1)Kz^(1)	0.00012207
const ap_int<27> deltaZ_tmp = dz * drinv;
const ap_int<18> deltaZ = deltaZ_tmp >> 9;
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

// 16 bits 	 2^(-14)	6.10352e-05
const ap_int<16> a = a2>>1;
;
// 18 bits 	 2^(-15)Kr^(-1)Kz^(1)	6.10352e-05
const ap_int<31> t_tmp = a * deltaZ;
const ap_int<18> t = t_tmp >> 13;
//
// STEP 11

// 13 bits 	 2^(-10)Kr^(-1)Kz^(1)	0.00195312
const ap_int<14> t_final = t>>5;
//
// calculating z0_final
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

// 18 bits 	 2^(-4)Kr^(0)Kz^(1)	0.00366211
const ap_int<28> z0a_tmp = r1abs * deltaZ;
const ap_int<18> z0a = z0a_tmp >> 10;
//
// STEP 7

//
// STEP 8

//
// STEP 9

//
// STEP 10

// 18 bits 	 2^(-4)Kr^(0)Kz^(1)	0.00366211
const ap_int<33> z0b_tmp = z0a * x6m;
const ap_int<18> z0b = z0b_tmp >> 15;
//
// STEP 11

// 18 bits 	 2^(-4)Kz^(1)	0.00366211
const ap_int<18> z0 = (ap_int<18>(z1)<<4) + z0b;
//
// STEP 12

// 14 bits 	 2^(0)Kz^(1)	0.0585938
const ap_int<14> z0_final = z0 >> 4;

//
// calculating phiL_0_final
//
//
// STEP 0

// units 2^(0)Kr^(1)	0.0292969
// 10 bits 	 2^(-8)	0.00390625
static const ap_int<10> plus1 = 256;
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

// 17 bits 	 2^(-9)Kphi^(1)Kr^(-1)	5.22747e-07
const ap_int<17> x2 = delta0>>1;
;
// 18 bits 	 2^(3)Kphi^(1)Kr^(0)	6.27297e-05
const ap_int<30> x1_0_tmp = x2 * rproj0_input;
const ap_int<18> x1_0 = x1_0_tmp >> 12;
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

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<30> x8_0_tmp = x1_0 * a2n;
const ap_int<18> x8_0 = x8_0_tmp >> 12;
//
// STEP 12

// 18 bits 	 2^(20)Kphi^(2)Kr^(0)	6.44712e-05
const ap_int<36> x12_0_tmp = x8_0 * x8_0;
const ap_int<18> x12_0 = x12_0_tmp >> 18;
//
// STEP 13

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x12A_0_tmp = (x12_0 * 69225);
const ap_int<18> x12A_0 = x12A_0_tmp >> 17;
//
// STEP 14

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x20_0_tmp = (x12A_0 * 87381);
const ap_int<18> x20_0 = x20_0_tmp >> 17;
//
// STEP 15

// 18 bits 	 2^(-14)	6.10352e-05
const ap_int<19> x10_0_tmp = (ap_int<19>(plus1)<<7) + x20_0;
const ap_int<18> x10_0 = x10_0_tmp >> 1;
//
// STEP 16

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<32> x22_0_tmp = x8_0 * x10_0;
const ap_int<18> x22_0 = x22_0_tmp >> 14;
//
// STEP 17

// 19 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiL_0 = phi0_final - x22_0;
//
// STEP 18

// 20 bits 	 2^(0)Kphi^(1)	7.84121e-06
const ap_int<20> phiL_0_final = phiL_0 << 1;

//
// calculating phiL_1_final
//
//
// STEP 0

// units 2^(0)Kr^(1)	0.0292969
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

// 18 bits 	 2^(3)Kphi^(1)Kr^(0)	6.27297e-05
const ap_int<30> x1_1_tmp = x2 * rproj1_input;
const ap_int<18> x1_1 = x1_1_tmp >> 12;
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

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<30> x8_1_tmp = x1_1 * a2n;
const ap_int<18> x8_1 = x8_1_tmp >> 12;
//
// STEP 12

// 18 bits 	 2^(20)Kphi^(2)Kr^(0)	6.44712e-05
const ap_int<36> x12_1_tmp = x8_1 * x8_1;
const ap_int<18> x12_1 = x12_1_tmp >> 18;
//
// STEP 13

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x12A_1_tmp = (x12_1 * 69225);
const ap_int<18> x12A_1 = x12A_1_tmp >> 17;
//
// STEP 14

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x20_1_tmp = (x12A_1 * 87381);
const ap_int<18> x20_1 = x20_1_tmp >> 17;
//
// STEP 15

// 18 bits 	 2^(-14)	6.10352e-05
const ap_int<19> x10_1_tmp = (ap_int<19>(plus1)<<7) + x20_1;
const ap_int<18> x10_1 = x10_1_tmp >> 1;
//
// STEP 16

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<32> x22_1_tmp = x8_1 * x10_1;
const ap_int<18> x22_1 = x22_1_tmp >> 14;
//
// STEP 17

// 19 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiL_1 = phi0_final - x22_1;
//
// STEP 18

// 20 bits 	 2^(0)Kphi^(1)	7.84121e-06
const ap_int<20> phiL_1_final = phiL_1 << 1;

//
// calculating phiL_2_final
//
//
// STEP 0

// units 2^(0)Kr^(1)	0.0292969
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

// 18 bits 	 2^(3)Kphi^(1)Kr^(0)	6.27297e-05
const ap_int<30> x1_2_tmp = x2 * rproj2_input;
const ap_int<18> x1_2 = x1_2_tmp >> 12;
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

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<30> x8_2_tmp = x1_2 * a2n;
const ap_int<18> x8_2 = x8_2_tmp >> 12;
//
// STEP 12

// 18 bits 	 2^(20)Kphi^(2)Kr^(0)	6.44712e-05
const ap_int<36> x12_2_tmp = x8_2 * x8_2;
const ap_int<18> x12_2 = x12_2_tmp >> 18;
//
// STEP 13

// 18 bits 	 2^(-13)	0.00012207
const ap_int<35> x12A_2_tmp = (x12_2 * 69225);
const ap_int<18> x12A_2 = x12A_2_tmp >> 17;
//
// STEP 14

// 18 bits 	 2^(-15)	3.05176e-05
const ap_int<35> x20_2_tmp = (x12A_2 * 87381);
const ap_int<18> x20_2 = x20_2_tmp >> 17;
//
// STEP 15

// 18 bits 	 2^(-14)	6.10352e-05
const ap_int<19> x10_2_tmp = (ap_int<19>(plus1)<<7) + x20_2;
const ap_int<18> x10_2 = x10_2_tmp >> 1;
//
// STEP 16

// 18 bits 	 2^(1)Kphi^(1)Kr^(0)	1.56824e-05
const ap_int<32> x22_2_tmp = x8_2 * x10_2;
const ap_int<18> x22_2 = x22_2_tmp >> 14;
//
// STEP 17

// 19 bits 	 2^(1)Kphi^(1)	1.56824e-05
const ap_int<19> phiL_2 = phi0_final - x22_2;
//
// STEP 18

// 20 bits 	 2^(0)Kphi^(1)	7.84121e-06
const ap_int<20> phiL_2_final = phiL_2 << 1;

//
// calculating zL_0_final
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
const ap_int<31> x11_0_tmp = rproj0_input * t;
const ap_int<18> x11_0 = x11_0_tmp >> 13;
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
ap_int<18> invt;
if (Seed==TF::L1D1){
  if (negDisk){
#ifndef __SYNTHESIS__
    static ap_int<18> LUT_invt[2048];
    readSWLUT<ap_int<18>,2048>(LUT_invt, "../../../../../emData/LUTs/TC_L1B1_invt.tab",false,true);
#else
    static const ap_int<18> LUT_invt[2048] = {
#if __has_include("../emData/LUTs/TC_L1B1_invt.tab")
#  include "../emData/LUTs/TC_L1B1_invt.tab"
#endif
    };
#endif
    invt = LUT_invt[addr_invt];
  }
  else{
#ifndef __SYNTHESIS__
    static ap_int<18> LUT_invt[2048];
    readSWLUT<ap_int<18>,2048>(LUT_invt, "../../../../../emData/LUTs/TC_L1F1_invt.tab",false,true);
#else
    static const ap_int<18> LUT_invt[2048] = {
#if __has_include("../emData/LUTs/TC_L1F1_invt.tab")
#  include "../emData/LUTs/TC_L1F1_invt.tab"
#endif
    };
#endif
    invt = LUT_invt[addr_invt];
  }
}
else{
  if (negDisk){
#ifndef __SYNTHESIS__
    static ap_int<18> LUT_invt[2048];
    readSWLUT<ap_int<18>,2048>(LUT_invt, "../../../../../emData/LUTs/TC_L2B1_invt.tab",false,true);
#else
    static const ap_int<18> LUT_invt[2048] = {
#if __has_include("../emData/LUTs/TC_L2B1_invt.tab")
#  include "../emData/LUTs/TC_L2B1_invt.tab"
#endif
    };
#endif
    invt = LUT_invt[addr_invt];
  }
  else{
#ifndef __SYNTHESIS__
    static ap_int<18> LUT_invt[2048];
    readSWLUT<ap_int<18>,2048>(LUT_invt, "../../../../../emData/LUTs/TC_L2F1_invt.tab",false,true);
#else
    static const ap_int<18> LUT_invt[2048] = {
#if __has_include("../emData/LUTs/TC_L2F1_invt.tab")
#  include "../emData/LUTs/TC_L2F1_invt.tab"
#endif
    };
#endif
    invt = LUT_invt[addr_invt];
  }
}
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
}
