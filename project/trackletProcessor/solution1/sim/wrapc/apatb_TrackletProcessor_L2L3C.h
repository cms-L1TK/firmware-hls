// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

extern void AESL_WRAP_TrackletProcessor_L2L3C (
const ap_uint<3> bx,
const ap_uint<10> lut[2048],
const ap_uint<8> regionlut[2048],
const struct MemoryTemplate<AllStubInner<0 >, 3, 7 > innerStubs[3],
const struct MemoryTemplate<AllStub<0 >, 3, 7 >* outerStubs,
const struct MemoryTemplateBinnedCM<VMStubTEOuter<0 >, 1, 10, 6, 2 > outerVMStubs,
MemoryTemplate<TrackletParameters, 3, 7 >* trackletParameters,
struct MemoryTemplate<TrackletProjection<0 >, 1, 7 > projout_barrel_ps[16],
struct MemoryTemplate<TrackletProjection<1 >, 1, 7 > projout_barrel_2s[12],
struct MemoryTemplate<TrackletProjection<6 >, 1, 7 > projout_disk[16]);
