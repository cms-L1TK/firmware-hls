#ifndef TopFunctions_InputRouterTop_h
#define TopFunctions_InputRouterTop_h
#include "InputRouter.h"
#include "InputRouter_parameters.h"

void InputRouterTop_IR_DTC_PS10G_1_A(
    const BXType bx
    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs 
    , hls::stream<InputStub<BARRELPS> > &hOutputStubs_0
    , hls::stream<InputStub<BARRELPS> > &hOutputStubs_1);

void InputRouterTop_IR_DTC_PS10G_2_A(
    const BXType bx
    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs 
    , hls::stream<InputStub<BARRELPS> > &hOutputStubs_0
    , hls::stream<InputStub<BARRELPS> > &hOutputStubs_1);
#endif
