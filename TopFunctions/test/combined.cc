#include "combined.h"

void
combined(
  const BXType bx
  , const ap_uint<kLINKMAPwidth> hLinkWord_1
  , const ap_uint<kBINMAPwidth> hPhBnWord_1
  , ap_uint<kNBits_DTC> hInputStubs_1[kMaxProc]
  , const ap_uint<kLINKMAPwidth> hLinkWord_2
  , const ap_uint<kBINMAPwidth> hPhBnWord_2
  , ap_uint<kNBits_DTC> hInputStubs_2[kMaxProc]
  , AllStubMemory<outputType_A> memoriesAS_A[numASCopies_A]
  , AllStubInnerMemory<outputType_A> memoriesASInner_A[numASInnerCopies_A]
  , VMStubMEMemoryCM<outputType_A, kNbitsrzbinME_A, kNbitsphibin, kNMatchEngines> *memoryME_A
  , AllStubMemory<outputType_B> memoriesAS_B[numASCopies_B]
  , AllStubInnerMemory<outputType_B> memoriesASInner_B[numASInnerCopies_B]
  , VMStubMEMemoryCM<outputType_B, kNbitsrzbinME_B, kNbitsphibin, kNMatchEngines> *memoryME_B
)
{
#pragma HLS dataflow

  hls::stream<InputStub<BARRELPS> > IL_L1PHIA_PS10G_1_A;
  hls::stream<InputStub<BARRELPS> > IL_L1PHIB_PS10G_1_A;
  hls::stream<InputStub<BARRELPS> > IL_L1PHIA_PS10G_2_A;
  hls::stream<InputStub<BARRELPS> > IL_L1PHIB_PS10G_2_A;

  InputRouterTop_IR_DTC_PS10G_1_A(bx, hLinkWord_1, hPhBnWord_1, hInputStubs_1, IL_L1PHIA_PS10G_1_A, IL_L1PHIB_PS10G_1_A);
  InputRouterTop_IR_DTC_PS10G_2_A(bx, hLinkWord_2, hPhBnWord_2, hInputStubs_2, IL_L1PHIA_PS10G_2_A, IL_L1PHIB_PS10G_2_A);

  VMRouterCMTop_L1PHIA(bx, IL_L1PHIA_PS10G_1_A, IL_L1PHIA_PS10G_2_A, memoriesAS_A, memoriesASInner_A, memoryME_A);
  VMRouterCMTop_L1PHIB(bx, IL_L1PHIB_PS10G_1_A, IL_L1PHIB_PS10G_2_A, memoriesAS_B, memoriesASInner_B, memoryME_B);
}
