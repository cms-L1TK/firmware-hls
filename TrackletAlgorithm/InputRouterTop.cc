#include "InputRouterTop.h"

void InputRouterTop( const BXType hBx
  , const ap_uint<6> hInputLinkId // link id 
  , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
  , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
  , const ap_uint<kNMEMwidth> hNmemories // number of memories filled by each IR module
  , const int kPhiCorrtable_L1[] // corrections frst brl lyr  
  , const int kPhiCorrtable_L2[] // corrections scnd brl lyr   
  , const int kPhiCorrtable_L3[] // corrections thrd brl lyr  
  , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]
  , DTCStubMemory hOutputStubs[cNMemories]) {

  #pragma HLS stream variable = hInputStubs depth = 1

  // LOOP_AssignToNull:
  // for (unsigned int cIndx = kLinkNMemories[hInputLinkId%12]; cIndx < kNIRMemories; cIndx++) 
  // {
  // #pragma HLS unroll
  //   DTCStubMemory* cPtr = hOutputStubs;//point to the nth element
  //   cPtr += cIndx; // move to the element I want to set to null 
  //   cPtr = nullptr; // set it to null 
  // }
  

#ifndef __SYNTHESIS__
  std::cout << "IR module reading out link " << +hInputLinkId
    << " is going to fill "
    <<  hNmemories
    << " memories\n";
#endif

if( hInputLinkId%12 == 6 ) 
  InputRouter<16>( hBx
      , hLinkWord
      , hPhBnWord
      , kPhiCorrtable_L1
      , kPhiCorrtable_L2
      , kPhiCorrtable_L3
      , hInputStubs
      , hOutputStubs);

// check 
#ifndef __SYNTHESIS__
  for( size_t cIndx=0; cIndx < cNMemories; cIndx++)
  {
    std::cout << "\t...Found " 
        << +hOutputStubs[cIndx].getEntries(hBx) 
        << " in memory#"
        << +cIndx 
        << " from HLS top level"
        << "\n";
  }
#endif
// if( (hInputLinkId%12) < 6 ) 
// {
//   switch(hInputLinkId%12) 
//   {
//     case 0:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       break;
//     case 1:
//       InputRouter<4>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 2:
//       InputRouter<4>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 3:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 4:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 5:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L4
//       , kPhiCorrtable_L5
//       , kPhiCorrtable_L6
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     default:
//       break;
//   }
// }
// else
// {
//   switch(hInputLinkId%12) 
//   {
//     case  6:
//       InputRouter<16>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       break;
//     case  7:
//       InputRouter<20>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case  8:
//       InputRouter<4>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case  9:
//       InputRouter<12>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 10:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     case 11:
//       InputRouter<8>( hBx
//       , hLinkWord
//       , hPhBnWord
//       , kPhiCorrtable_L1
//       , kPhiCorrtable_L2
//       , kPhiCorrtable_L3
//       , hInputStubs
//       , hOutputStubs);
//       // code block
//       break;
//     default:
//       break;  
//   }
// }

  // // clear stub counter
  // ap_uint<kNMEMwidth> hNStubs[kNIRMemories];
  // #pragma HLS array_partition variable = hNStubs complete
  // LOOP_ClearOutputMemories:
  // for (unsigned int cMemIndx = 0; cMemIndx < kNIRMemories ; cMemIndx++) 
  // {
  //   #pragma HLS unroll
  //    if( cMemIndx >= hNmemories )  continue;
  //    hNStubs[cMemIndx] = 0;
  //    #ifndef __SYNTHESIS__
  //     if (IR_DEBUG) {
  //     std::cout << ".........."
  //       << +(&hOutputStubs[cMemIndx])->getEntries(hBx) 
  //       << " entries... "
  //       << "\n";
  //     }
  //   #endif
  // }

  // LOOP_ProcessIR:
  // for (int cStubCounter = 0; cStubCounter < kMaxStubsFromLink; cStubCounter++) 
  // {
  //   #pragma HLS pipeline II = 1
  //   #pragma HLS PIPELINE rewind
  //     // decode stub
  //     // check which memory
  //     ap_uint<kNBits_DTC> hStub = hInputStubs[cStubCounter];
  //     // add check of valid bit here 
  //     if (hStub == 0)   continue;

  //     // named constants in InputRouter.h 
  //     ap_uint<3> hEncLyr = ap_uint<3>(hStub.range(kNBits_DTC - 1, kNBits_DTC - 2) & 0x3);
  //     ap_uint<kBRAMwidth> hStbWrd = hStub.range(kBRAMwidth - 1, 0);
  //     // get memory word
  //     DTCStub hMemWord(hStbWrd);
        
  //     // decode link wrd for this layer
  //     ap_uint<kSizeLinkWord> hWrd = hLinkWord.range(kSizeLinkWord * hEncLyr + (kSizeLinkWord-1), kSizeLinkWord * hEncLyr);
  //     ap_uint<1> hIsBrl = hWrd.range(1, 0);
  //     ap_uint<3> hLyrId = hWrd.range(3, 1);
      
  //     // get phi bin
  //     ap_uint<3> hPhiBn;
  //     if (hIsBrl == 1) 
  //     {
  //     if (hIs2S == 0)
  //       GetPhiBinBrl<BARRELPS, kSizePhiCorrTablePS>(hStub, kPhiCorrtable_L1, kPhiCorrtable_L2,
  //                                  kPhiCorrtable_L3, hLyrId, hPhiBn);
  //     else
  //       GetPhiBinBrl<BARREL2S, kSizePhiCorrTable2S>(hStub, kPhiCorrtable_L4, kPhiCorrtable_L5,
  //                                   kPhiCorrtable_L6, hLyrId, hPhiBn);
  //     } 
  //     else 
  //     {
  //     if (hIs2S == 0)
  //       GetPhiBinDsk<DISKPS>(hStub, hLyrId, hPhiBn);
  //     else
  //       GetPhiBinDsk<DISK2S>(hStub, hLyrId, hPhiBn);
  //     }

  //     // update index
  //     unsigned int cIndx = 0;
  //     unsigned int cNBns = 0;
  //     LOOP_UpdateMemIndx:
  //     for (int cLyr = 0; cLyr < kNLayers; cLyr++) 
  //     {
  //       #pragma HLS unroll
  //       // update index
  //       ap_uint<kSizeBinWord> hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
  //       cIndx += (cLyr < hEncLyr) ? (1+(unsigned int)(hBnWrd)) : 0; 
  //       cNBns += (hBnWrd == 0) ? 0 : (1 + (unsigned int)(hBnWrd)) ;
  //     }
  //     // and add phi bin 
  //     unsigned int cMemIndx = cIndx + hPhiBn;
  //     #ifndef __SYNTHESIS__
  //       std::cout << "Stub # " << cStubCounter 
  //         << " from layer #" << hEncLyr 
  //         << " (enc.) which is connected to "
  //         << cNBns 
  //         << " IR memories...\t filling memory index "
  //         << cMemIndx 
  //         << " since its phi bin "
  //         << hPhiBn
  //         << "\n";
  //     #endif

  //     // write to memory
  //     assert(cMemIndx < hNmemories);
  //     ap_uint<8> hEntries = hNStubs[cMemIndx];
  //     #ifndef __SYNTHESIS__
  //     if (IR_DEBUG) {
  //     std::cout << "\t.. Stub : " << std::hex << hStbWrd << std::dec
  //               << " [ EncLyrId " << hEncLyr << " ] "
  //               << "[ LyrId " << hLyrId << " ] IsBrl bit " << +hIsBrl
  //               << " PhiBn#" << +hPhiBn << " Mem#" << cMemIndx
  //               << " Current number of entries " << +hEntries << "\n";
  //     }
  //     #endif
  //     (&hOutputStubs[cMemIndx])->write_mem(hBx, hMemWord, hEntries);
  //     hNStubs[cMemIndx] = hEntries + 1;
  // }

  // InputRouter<10, kSizePhiCorrTablePS>( hBx
  // , kLinkLUT[hInputLinkId%12]
  // , kLinkPhiBinsLUT[hInputLinkId%12]
  // , kLinkNMemories[hInputLinkId%12] 
  // , kPhiCorrtable_L1
  // , kPhiCorrtable_L2
  // , kPhiCorrtable_L3
  // , hInputStubs
  // , hOutputStubs);




// // now call templated top level function 
// ap_uint<1> hIs2S= kLinkLUT[hInputLinkId%12].range(kLINKMAPwidth-3,kLINKMAPwidth-4);
// if( hIs2S == 1 ) 
//   InputRouter<kSizePhiCorrTable2S>( hBx
//   , kLinkLUT[hInputLinkId%12]
//   , kLinkPhiBinsLUT[hInputLinkId%12]
//   , kLinkNMemories[hInputLinkId%12] 
//   , kPhiCorrtable_L4
//   , kPhiCorrtable_L5
//   , kPhiCorrtable_L6
//   , hInputStubs
//   , hOutputStubs);
// else
//   InputRouter<kSizePhiCorrTablePS>(hBx
//   , kLinkLUT[hInputLinkId%12]
//   , kLinkPhiBinsLUT[hInputLinkId%12]
//   , kLinkNMemories[hInputLinkId%12] 
//   , kPhiCorrtable_L4
//   , kPhiCorrtable_L5
//   , kPhiCorrtable_L6
//   , hInputStubs
//   , hOutputStubs);

}
