#include "InputRouter.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"

//constexpr unsigned int kInputLinkSize = 38;
//typedef ap_uint<kInputLinkSize> InputLinkData;

void InputRouter(const BXType bx, hls::stream<ap_uint<38> >& IL, InputStubMemory<BARRELPS> *R0PhiA, InputStubMemory<BARRELPS> *R0PhiB,
               InputStubMemory<BARRELPS> *R0PhiC, InputStubMemory<BARRELPS> *R0PhiD, InputStubMemory<BARRELPS> *R1PhiA, InputStubMemory<BARRELPS> *R1PhiB,
               InputStubMemory<BARRELPS> *R2PhiA, InputStubMemory<BARRELPS> *R2PhiB, InputStubMemory<BARRELPS> *R3PhiA, InputStubMemory<BARRELPS> *R3PhiB, bool fromL1)
{
//   ap_uint<38> din;
//   InputStub<BARRELPS> dout;
//   ap_uint<2> region;
//   ap_uint<2> phiDivision;
//   for (int i=0; i<kMaxStubsFromLink; ++i)
//   {
//     #pragma HLS PIPELINE II=1
// //    IL.read(din);
//     if (IL.read_nb(din))
//     {
//       region = din.range(37,36);
//       if (fromL1 && region==0) {
//         phiDivision = din.range(15,14);
//       } else {
//         phiDivision = din.range(15,15);
//       }
//       dout = InputStub<BARRELPS>(din.range(35,0));
//       if (region == 0) {
//         if (phiDivision == 0) {
//           R0PhiA->write_mem(bx,dout);
//         } else if (phiDivision == 1) {
//           R0PhiB->write_mem(bx,dout);
//         } else if (phiDivision == 2) {
//           R0PhiC->write_mem(bx,dout);
//         } else if (phiDivision == 3) {
//           R0PhiD->write_mem(bx,dout);
//         }
//       } else if (region == 1) {
//         if (phiDivision == 0) {
//           R1PhiA->write_mem(bx,dout);
//         } else if (phiDivision == 1) {
//           R1PhiB->write_mem(bx,dout);
//         }
//       } else if (region == 2) {
//         if (phiDivision == 0) {
//           R2PhiA->write_mem(bx,dout);
//         } else if (phiDivision == 1) {
//           R2PhiB->write_mem(bx,dout);
//         }
//       } else if (region == 3) {
//         if (phiDivision == 0) {
//           R3PhiA->write_mem(bx,dout);
//         } else if (phiDivision == 1) {
//           R3PhiB->write_mem(bx,dout);
//         } // inner switch
//       } // outer switch
//     } // read if
//   } // stub loop
} // input router function
 
