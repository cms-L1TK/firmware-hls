#include "TrackletProcessorTop.h"

ap_uint<1> nearFullTEBuff(const ap_uint<TEBuffer<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBufferDepthBits>& writeptr,
			  const ap_uint<TEBuffer<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBufferDepthBits>& readptr) {
  ap_uint<3> writeptr1=writeptr+1;
  ap_uint<3> writeptr2=writeptr+2;
  ap_uint<3> writeptr3=writeptr+3;
  ap_uint<1> result=writeptr1==readptr||writeptr2==readptr||writeptr3==readptr;
  return result;
}
ap_uint<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer))> nearFullTEUnitInit() {
  ap_uint<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer))> lut(0);
  int i;
  for(i=0;i<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer));i++) {
    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr,rptr;
    ap_uint<2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> address(i);
    (rptr,wptr)=address;
    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr1=wptr+1;
    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr2=wptr+2;
    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr3=wptr+3;
    ap_uint<1> result=wptr1==rptr||wptr2==rptr||wptr3==rptr;
    lut[i]=result;
  }
  return lut;
 }
////////////////////////////////////////////////////////////////////////////////
// Top functions for various TrackletProcessors (TP). For each iteration of
// the main processing loop, a TC retrieves a pair of stub indices from one of
// the stub-pair memories, and in turn, these indices are used to retrieve one
// stub each from an inner and an outer all-stub memory. This pair of stubs is
// used to calculate a rough set of helix parameters, which are written to the
// tracklet-parameter memory if the tracklet passes cuts on rinv and z0. Rough
// projections to additional layers and disks are also calculated and are
// written to the appropriate tracklet-projection memories.
////////////////////////////////////////////////////////////////////////////////

void TrackletProcessor_L1L2A(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2A: TrackletProcessor<
  TF::L1L2,
  TC::A,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  1,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2B(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2B: TrackletProcessor<
  TF::L1L2,
  TC::B,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2C(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2C: TrackletProcessor<
  TF::L1L2,
  TC::C,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2D(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2D: TrackletProcessor<
  TF::L1L2,
  TC::D,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2E(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2E: TrackletProcessor<
  TF::L1L2,
  TC::E,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2F(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2F: TrackletProcessor<
  TF::L1L2,
  TC::F,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2G(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2G: TrackletProcessor<
  TF::L1L2,
  TC::G,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2H(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2H: TrackletProcessor<
  TF::L1L2,
  TC::H,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2I(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2I: TrackletProcessor<
  TF::L1L2,
  TC::I,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2J(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2J: TrackletProcessor<
  TF::L1L2,
  TC::J,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2K(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2K: TrackletProcessor<
  TF::L1L2,
  TC::K,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L1L2L(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L1L2L: TrackletProcessor<
  TF::L1L2,
  TC::L,
  kNTEUnits[TF::L1L2],
  BARRELPS,
  BARRELPS,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  1,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L2L3A(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L2L3A: TrackletProcessor<
  TF::L2L3,
  TC::A,
  kNTEUnits[TF::L2L3],
  BARRELPS,
  BARRELPS,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L2L3B(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L2L3B: TrackletProcessor<
  TF::L2L3,
  TC::B,
  kNTEUnits[TF::L2L3],
  BARRELPS,
  BARRELPS,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L2L3C(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L2L3C: TrackletProcessor<
  TF::L2L3,
  TC::C,
  kNTEUnits[TF::L2L3],
  BARRELPS,
  BARRELPS,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L2L3D(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L2L3D: TrackletProcessor<
  TF::L2L3,
  TC::D,
  kNTEUnits[TF::L2L3],
  BARRELPS,
  BARRELPS,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L3L4A(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L3L4A: TrackletProcessor<
  TF::L3L4,
  TC::A,
  kNTEUnits[TF::L3L4],
  BARRELPS,
  BARREL2S,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L3L4B(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L3L4B: TrackletProcessor<
  TF::L3L4,
  TC::B,
  kNTEUnits[TF::L3L4],
  BARRELPS,
  BARREL2S,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L3L4C(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L3L4C: TrackletProcessor<
  TF::L3L4,
  TC::C,
  kNTEUnits[TF::L3L4],
  BARRELPS,
  BARREL2S,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L3L4D(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[2048],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L3L4D: TrackletProcessor<
  TF::L3L4,
  TC::D,
  kNTEUnits[TF::L3L4],
  BARRELPS,
  BARREL2S,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L5L6A(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[4096],
    const AllStubInnerMemory<BARREL2S> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L5L6A: TrackletProcessor<
  TF::L5L6,
  TC::A,
  kNTEUnits[TF::L5L6],
  BARREL2S,
  BARREL2S,
  0,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L5L6B(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[4096],
    const AllStubInnerMemory<BARREL2S> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L5L6B: TrackletProcessor<
  TF::L5L6,
  TC::B,
  kNTEUnits[TF::L5L6],
  BARREL2S,
  BARREL2S,
  1,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L5L6C(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[4096],
    const AllStubInnerMemory<BARREL2S> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=innerStubs[2].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L5L6C: TrackletProcessor<
  TF::L5L6,
  TC::C,
  kNTEUnits[TF::L5L6],
  BARREL2S,
  BARREL2S,
  2,
  kNbitsrzbin,
  kNbitsphibin,
  3,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletProcessor_L5L6D(
    const BXType bx,
    const ap_uint<10> lut[2048],
    const ap_uint<8> regionlut[4096],
    const AllStubInnerMemory<BARREL2S> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs ,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2
#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs->get_mem() latency=2
#pragma HLS resource variable=outerVMStubs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TP_L5L6D: TrackletProcessor<
  TF::L5L6,
  TC::D,
  kNTEUnits[TF::L5L6],
  BARREL2S,
  BARREL2S,
  3,
  kNbitsrzbin,
  kNbitsphibin,
  2,
 108>(
    bx,
    lut,
    regionlut,
    innerStubs,
    outerStubs,
    outerVMStubs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

////////////////////////////////////////////////////////////////////////////////
