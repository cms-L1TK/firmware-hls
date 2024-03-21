#ifndef TrackletAlgorithm_TrackletCalculator_calculate_LXLY_h
#define TrackletAlgorithm_TrackletCalculator_calculate_LXLY_h
#include "TrackletProjectionCalculator.h"
#include "TrackletLUTs.h"


// This function does all the actual calculations in the TrackletCalculators
// for the barrel-only seeds (L1L2, L2L3, L3L4, and L5L6).
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_LXLY (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,

  TC::Types::rinv * const rinv_output,
  TrackletParameters::PHI0PAR * const phi0_output,
  TrackletParameters::TPAR * const t_output,
  TC::Types::z0 * const z0_output,
  TC::Types::phiL * const phiL_0_output,
  TC::Types::phiL * const phiL_1_output,
  TC::Types::phiL * const phiL_2_output,
  TC::Types::phiL * const phiL_3_output,
  TC::Types::zL * const zL_0_output,
  TC::Types::zL * const zL_1_output,
  TC::Types::zL * const zL_2_output,
  TC::Types::zL * const zL_3_output,
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
  TC::Types::der_rD * const der_rD_output
)
{

  //First convert input to right bits
  ap_uint<13> ir1abs = (ap_int<10>(r1_input) << 1) + rmean[seedLayers[Seed][0]];
  ap_uint<13> ir2abs = (ap_int<10>(r2_input) << 1) + rmean[seedLayers[Seed][1]];

  const ap_int<18> phi2c = ap_int<18>(phi2_input)<<((Seed == TF::L1L2 || Seed == TF::L2L3) ? 3 : 0);
  const ap_int<18> phi1c = ap_int<18>(phi1_input)<<((Seed == TF::L1L2 || Seed == TF::L2L3 || Seed == TF::L3L4) ? 3 : 0);

  const ap_int<12> z2c = ap_int<12>(z2_input)<<((Seed == TF::L3L4 || Seed == TF::L5L6) ? 4 : 0);
  const ap_int<12> z1c = ap_int<12>(z1_input)<<((Seed == TF::L5L6) ? 4 : 0);

  ap_int<12> idz = z2c - z1c;

  ap_int<10> idr = (ap_int<10>(r2_input - r1_input)) << 1;
  if (idr<0) idr+=512;

  static const InvdrLUT<Seed> lut_idrinv;
  ap_uint<20> invdr = lut_idrinv.lookup(idr);

  ap_int<18> idelta0 = ((phi2c - phi1c)*invdr) >> n_delta0_;
  ap_int<18> ideltaz = (idz*invdr) >> n_deltaz_;

  ap_int<20> idelta1 = (ir1abs*idelta0) >> n_delta1_;  
  ap_int<20> idelta2 = (ir2abs*idelta0) >> n_delta2_;

  ap_int<20> idelta12 = (idelta1*idelta2) >> n_delta12_;

  constexpr int iHG = phiHG_*phiHG_*(1 << n_HG_);

  ap_uint<n_a_+1> ia = ((1 << n_a_) - ((idelta12*iHG) >> (2*n_Deltar_ + 2*n_phi_ + n_HG_ - 2*n_delta0_ - n_delta1_ - n_delta2_ - n_delta12_ + 1 - n_a_)));

  constexpr int ir6fact = (1<<n_r6_)*phiHG_*phiHG_/6.0;
  ap_int<24> ir6 = (ir1abs+ir2abs)*ir6fact;

  ap_int<18> idelta02 = (idelta0*idelta2) >> n_delta02_;
  
  ap_int<n_x6_+2> ix6 = (-(1 << n_x6_)+((ir6*idelta02) >> (n_r6_ + 2*n_Deltar_ + 2*n_phi_ - n_x6_ - n_delta2_- n_delta02_ - 2*n_delta0_)));
  
  ap_int<18> it1 = (ir1abs*ideltaz) >> (n_Deltar_ - n_deltaz_);

  
  ap_int<14> irinv_new = ((-idelta0*ia) >> (n_phi_ + n_a_ - n_rinv_ + n_Deltar_ - n_delta0_ - n_r_ - 1));

  ap_int<18> iphi0_new = (phi1c >> (n_phi_ - n_phi0_))+((idelta1*ix6) >> (n_Deltar_ + n_x6_ + n_phi_ - n_delta0_ - n_delta1_ - n_phi0_));

  ap_int<14> it_new = ((ideltaz*ia) >> (n_Deltar_ + n_a_ + n_z_ - n_t_ - n_deltaz_ - n_r_));

  ap_int<11> iz0_new = z1c+((it1*ix6) >> n_x6_);


  constexpr int irproj0 = rmean[projectionLayers[Seed][0]];
  constexpr int irproj1 = rmean[projectionLayers[Seed][1]];
  constexpr int irproj2 = rmean[projectionLayers[Seed][2]];
  constexpr int irproj3 = rmean[projectionLayers[Seed][3]];

  constexpr int irprojtilde0 = irproj0*phiHG_/sqrtsix + 0.5;
  constexpr int irprojtilde1 = irproj1*phiHG_/sqrtsix + 0.5;
  constexpr int irprojtilde2 = irproj2*phiHG_/sqrtsix + 0.5;
  constexpr int irprojtilde3 = irproj3*phiHG_/sqrtsix + 0.5;

  const ap_int<13> rproj0 = irproj0;
  const ap_int<13> rproj1 = irproj1;
  const ap_int<13> rproj2 = irproj2;
  const ap_int<13> rproj3 = irproj3;

  const ap_int<13> rprojtilde0 = irprojtilde0;
  const ap_int<13> rprojtilde1 = irprojtilde1;
  const ap_int<13> rprojtilde2 = irprojtilde2;
  const ap_int<13> rprojtilde3 = irprojtilde3;
  
  projToLayer(rproj0, rprojtilde0, irinv_new, iphi0_new, it_new, iz0_new, *zL_0_output, *phiL_0_output);
  projToLayer(rproj1, rprojtilde1, irinv_new, iphi0_new, it_new, iz0_new, *zL_1_output, *phiL_1_output);
  projToLayer(rproj2, rprojtilde2, irinv_new, iphi0_new, it_new, iz0_new, *zL_2_output, *phiL_2_output);
  projToLayer(rproj3, rprojtilde3, irinv_new, iphi0_new, it_new, iz0_new, *zL_3_output, *phiL_3_output);
  
  *der_phiL_output = -(irinv_new >> (1+3));
  *der_zL_output = it_new >> 3;

  static const InvtLUT lut_itinv;

  ap_uint<20> itinv = lut_itinv.lookup(abs(it_new)&4095);

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

}

template <TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_DXDY (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,
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

  const ap_int<18> phi1c = ap_int<18>(phi1_input)<<3;
  const ap_int<18> phi2c = ap_int<18>(phi2_input)<<3;

  const TC::Types::zmean z1mean = zmean[seedLayers[Seed][0]];
  const TC::Types::zmean z2mean = zmean[seedLayers[Seed][1]];

  const ap_int<14> z1c = z1_input + (negDisk ? ap_int<14>(-z1mean) : ap_int<14>(z1mean));
  const ap_int<14> z2c = z2_input + (negDisk ? ap_int<14>(-z2mean) : ap_int<14>(z2mean));

  ap_int<12> idz = z2c - z1c;

  ap_uint<12> idr = ap_int<12>(r2_input - r1_input);

  static const InvdrLUT<Seed> lut_idrinv;
  ap_uint<18> invdr = lut_idrinv.lookup(idr);

  ap_int<18> idelta0 = ((phi2c - phi1c)*invdr) >> n_delta0_;
  ap_int<18> ideltaz = (idz*invdr) >> n_deltaz_;

  ap_int<20> idelta1 = (r1_input*idelta0) >> n_delta1_;  
  ap_int<20> idelta2 = (r2_input*idelta0) >> n_delta2_;

  ap_int<20> idelta12 = (idelta1*idelta2) >> n_delta12_;

  constexpr int iHG = phiHG_*phiHG_*(1 << n_HG_);

  ap_uint<n_a_+1> ia = ((1 << n_a_) - ((idelta12*iHG) >> (2*n_Deltar_Disk_ + 2*n_phi_ + n_HG_ - 2*n_delta0_ - n_delta1_ - n_delta2_ - n_delta12_ + 1 - n_a_)));

  constexpr int ir6fact = (1<<n_r6_)*phiHG_*phiHG_/6.0;
  ap_int<24> ir6 = (r1_input+r2_input)*ir6fact;

  ap_int<18> idelta02 = (idelta0*idelta2) >> n_delta02_;
  
  ap_int<n_x6_+2> ix6 = (-(1 << n_x6_)+((ir6*idelta02) >> (n_r6_ + 2*n_Deltar_Disk_ + 2*n_phi_ - n_x6_ - n_delta2_- n_delta02_ - 2*n_delta0_)));
  
  ap_int<18> it1 = (r1_input*ideltaz) >> (n_Deltar_Disk_ - n_deltaz_);

  
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

  static const InvtLUT lut_itinv;

  ap_uint<20> itinv = lut_itinv.lookup(abs(it_new)&4095);

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

  
  //
  // wiring the outputs 
  //
  *rinv_output = irinv_new;
  *phi0_output = iphi0_new;
  *t_output = it_new;
  *z0_output = iz0_new;

}


template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
void TC::calculate_LXD1 (
  const typename AllStub<InnerRegion>::ASR r1_input,
  const typename AllStub<InnerRegion>::ASPHI phi1_input,
  const typename AllStub<InnerRegion>::ASZ z1_input,
  const typename AllStub<OuterRegion>::ASR r2_input,
  const typename AllStub<OuterRegion>::ASPHI phi2_input,
  const typename AllStub<OuterRegion>::ASZ z2_input,

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

  const ap_int<18> phi1c = ap_int<18>(phi1_input)<<3;
  const ap_int<18> phi2c = ap_int<18>(phi2_input)<<3;

  const TC::Types::zmean z2mean = zmean[seedLayers[Seed][1]];

  const ap_int<14> z1c = z1_input;
  const ap_int<14> z2c = ap_int<7>(z2_input) + (z1c > 0 ? ap_int<14>(z2mean) : ap_int<14>(-z2mean));

  ap_int<12> idz = z2c - z1c;

  ap_uint<12> idr = (ap_int<12>(r2_input - ir1c));

  static const InvdrLUT<Seed> lut_idrinv;
  ap_uint<18> invdr = lut_idrinv.lookup(idr);

  *valid_radii = idr > floatToInt(((Seed == TF::L1D1)?1.5:2.0),kr); 
  //FIXME this 1.5 and 2.0 is a magic number

  ap_int<18> idelta0 = ((phi2c - phi1c)*invdr) >> n_delta0_Overlap_;
  ap_int<18> ideltaz = (idz*invdr) >> n_deltaz_Overlap_;

  ap_int<20> idelta1 = (ir1c*idelta0) >> n_delta1_;  
  ap_int<20> idelta2 = (r2_input*idelta0) >> n_delta2_;

  ap_int<20> idelta12 = (idelta1*idelta2) >> n_delta12_;

  constexpr int iHG = phiHG_*phiHG_*(1 << n_HG_);

  ap_uint<n_a_Overlap_+1> ia = ((1 << n_a_Overlap_) - ((idelta12*iHG) >> (2*n_Deltar_Overlap_ + 2*n_phi_ + n_HG_ - 2*n_delta0_Overlap_ - n_delta1_ - n_delta2_ - n_delta12_ + 1 - n_a_Overlap_)));

  constexpr int ir6fact = (1<<n_r6_Overlap_)*phiHG_*phiHG_/6.0;
  ap_int<24> ir6 = (ir1c+r2_input)*ir6fact;

  ap_int<18> idelta02 = (idelta0*idelta2) >> n_delta02_;
  
  ap_int<n_x6_+2> ix6 = (-(1 << n_x6_)+((ir6*idelta02) >> (n_r6_Overlap_ + 2*n_Deltar_Overlap_ + 2*n_phi_ - n_x6_ - n_delta2_- n_delta02_ - 2*n_delta0_Overlap_)));
  
  ap_int<18> it1 = (ir1c*ideltaz) >> (n_Deltar_Overlap_ - n_deltaz_Overlap_);

  
  ap_int<15> irinv_new = ((-idelta0*ia) >> (n_phi_ + n_a_Overlap_ - n_rinv_ + n_Deltar_Overlap_ - n_delta0_Overlap_ - n_r_ - 1));

  ap_int<18> iphi0_new = (phi1c >> (n_phi_ - n_phi0_))+((idelta1*ix6) >> (n_Deltar_Overlap_ + n_x6_ + n_phi_ - n_delta0_Overlap_ - n_delta1_ - n_phi0_));

  ap_int<14> it_new = ((ideltaz*ia) >> (n_Deltar_Overlap_ + n_a_Overlap_ + n_z_ - n_t_ - n_deltaz_Overlap_ - n_r_));

  ap_int<11> iz0_new = z1c + ((it1*ix6) >> n_x6_);
  
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

  static const InvtLUT lut_itinv;

  ap_uint<20> itinv = lut_itinv.lookup(abs(it_new)&4095);

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

}



#endif
