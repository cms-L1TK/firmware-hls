#ifndef TrackletAlgorithm_TrackletProcessorTop_h
#define TrackletAlgorithm_TrackletProcessorTop_h

#include "TrackletProcessor.h"

void TrackletProcessor_L1L2A(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::A,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::A,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::A,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2B(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::B,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::B,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::B,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2C(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::C,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::C,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::C,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2D(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::D,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::D,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::D,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2E(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::E,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::E,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::E,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2F(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::F,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::F,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::F,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2G(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::G,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::G,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::G,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2H(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::H,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::H,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::H,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2I(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::I,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::I,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::I,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2J(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::J,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::J,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::J,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2K(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::K,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::K,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::K,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L1L2L(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L1L2, TC::L,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L1L2, TC::L,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L1L2, TC::L,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L1L2]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L2L3A(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L2L3, TC::A,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L2L3, TC::A,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L2L3, TC::A,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L2L3B(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L2L3, TC::B,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L2L3, TC::B,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L2L3, TC::B,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L2L3C(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L2L3, TC::C,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L2L3, TC::C,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L2L3, TC::C,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L2L3D(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L2L3, TC::D,BARRELPS,BARRELPS>::kNBitsRZFine+TrackletEngineUnit<TF::L2L3, TC::D,BARRELPS,BARRELPS>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L2L3, TC::D,BARRELPS,BARRELPS>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L2L3>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARRELPS, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L2L3]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L3L4A(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L3L4, TC::A,BARRELPS,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L3L4, TC::A,BARRELPS,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L3L4, TC::A,BARRELPS,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L3L4B(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L3L4, TC::B,BARRELPS,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L3L4, TC::B,BARRELPS,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L3L4, TC::B,BARRELPS,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L3L4C(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L3L4, TC::C,BARRELPS,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L3L4, TC::C,BARRELPS,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L3L4, TC::C,BARRELPS,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L3L4D(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L3L4, TC::D,BARRELPS,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L3L4, TC::D,BARRELPS,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L3L4, TC::D,BARRELPS,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARRELPS>::kASBendSize+AllStubInner<BARRELPS>::kASFinePhiSize)],
    const AllStubInnerMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L3L4]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L5L6A(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L5L6, TC::A,BARREL2S,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L5L6, TC::A,BARREL2S,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L5L6, TC::A,BARREL2S,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARREL2S>::kASBendSize+AllStubInner<BARREL2S>::kASFinePhiSize)],
    const AllStubInnerMemory<BARREL2S> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L5L6B(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L5L6, TC::B,BARREL2S,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L5L6, TC::B,BARREL2S,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L5L6, TC::B,BARREL2S,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARREL2S>::kASBendSize+AllStubInner<BARREL2S>::kASFinePhiSize)],
    const AllStubInnerMemory<BARREL2S> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L5L6C(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L5L6, TC::C,BARREL2S,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L5L6, TC::C,BARREL2S,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L5L6, TC::C,BARREL2S,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARREL2S>::kASBendSize+AllStubInner<BARREL2S>::kASFinePhiSize)],
    const AllStubInnerMemory<BARREL2S> innerStubs[3],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletProcessor_L5L6D(
    const BXType bx,
    const ap_uint<1+2*TrackletEngineUnit<TF::L5L6, TC::D,BARREL2S,BARREL2S>::kNBitsRZFine+TrackletEngineUnit<TF::L5L6, TC::D,BARREL2S,BARREL2S>::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],
    const ap_uint<(1<<TrackletEngineUnit<TF::L5L6, TC::D,BARREL2S,BARREL2S>::kNBitsPhiBins)> regionlut[1<<(AllStubInner<BARREL2S>::kASBendSize+AllStubInner<BARREL2S>::kASFinePhiSize)],
    const AllStubInnerMemory<BARREL2S> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()>* outerStubs,
    const VMStubTEOuterMemoryCM<BARREL2S, kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::L5L6]> outerVMStubs,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

#endif
