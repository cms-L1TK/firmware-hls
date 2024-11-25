#ifndef TopFunctions_combined_h
#define TopFunctions_combined_h

#include "InputRouterTop.h"
#include "VMRouterCMTop_L1PHIA.h"
#include "VMRouterCMTop_L1PHIB.h"

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
);

#endif
