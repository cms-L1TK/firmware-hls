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

  std::cout << "r1_input r2_input " << r1_input << " " << r2_input << std::endl;

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


}
