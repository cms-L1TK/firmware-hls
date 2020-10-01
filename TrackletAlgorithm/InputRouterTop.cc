#include "InputRouterTop.h"

void InputRouterTop( const BXType hBx
  , const ap_uint<6> hInputLinkId 
  , const ap_uint<kLINKMAPwidth> kInputLinkLUT[kSizeLinkTable]
  , const int kPhiCorrtable_L1[kSizePhiCorrTablePS]
  , const int kPhiCorrtable_L2[kSizePhiCorrTablePS]
  , const int kPhiCorrtable_L3[kSizePhiCorrTablePS]
  , const int kPhiCorrtable_L4[kSizePhiCorrTable2S]
  , const int kPhiCorrtable_L5[kSizePhiCorrTable2S]
  , const int kPhiCorrtable_L6[kSizePhiCorrTable2S]
  , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]
  , DTCStubMemory hOutputStubs[kNIRMemories]) {

#pragma HLS clock domain = slow_clock
#pragma HLS interface ap_none port = hInputLinkId
#pragma HLS interface ap_memory port = kInputLinkLUT
#pragma HLS stream variable = hInputStubs depth = 1

  ap_uint<kLINKMAPwidth> hLinkWord = kInputLinkLUT[hInputLinkId % 12];
  ap_uint<3> hNLayers = hLinkWord.range(kLINKMAPwidth - 1, kLINKMAPwidth - 3);
  ap_uint<1> hIs2S = hLinkWord.range(kLINKMAPwidth - 4, kLINKMAPwidth - 4);
#ifndef __SYNTHESIS__
  if (IR_DEBUG) {
    std::cout << "Link# " << +hInputLinkId 
              << " Link Word is " << std::bitset<kLINKMAPwidth>(hLinkWord)
              << " - Is2S bit is set to " << hIs2S << "\n";
  }
#endif

  // prepare variable needed
  // to be able to move through
  // the array of memories
  unsigned int cNMemories = 0;
  ap_uint<4> hNPhiBns[kNLayers];  // at most 4 layers
  ap_uint<1> hBrlBits[kNLayers];  // at most 4 layers
#pragma HLS array_partition variable = hNPhiBns complete
#pragma HLS array_partition variable = hBrlBits complete
LOOP_GetNPhiBns:
  for (unsigned int cIndx = 0; cIndx < kNLayers; cIndx++) {
#pragma HLS unroll
    if (cIndx < hNLayers) {
      ap_uint<4> hWrd = hLinkWord.range(4 * cIndx + 3, 4 * cIndx);
      ap_uint<1> hIsBrl = hWrd.range(0, 0);
      ap_uint<3> hLyrId = hWrd.range(3, 1);
      hNPhiBns[cIndx] = ((hIs2S == 0) && hLyrId == 1 && hIsBrl) ? 8 : 4;
      hBrlBits[cIndx] = hIsBrl;
#ifndef __SYNTHESIS__
      if (IR_DEBUG) {
        std::cout << "Lyr#" << cIndx << " encoded word " << std::bitset<4>(hWrd)
                  << " - " << hNPhiBns[cIndx] << " phi bins"
                  << " -- layer id is " << +hLyrId 
                  << "\n";
      }
#endif
      cNMemories += (unsigned int)(hNPhiBns[cIndx]);
    }
  }
// clear memories and stub counter
ap_uint<8> hNStubs[kNIRMemories];
#pragma HLS array_partition variable = hNStubs complete
LOOP_ClearOutputMemories:
  for (unsigned int cMemIndx = 0; cMemIndx < kNIRMemories; cMemIndx++) {
#pragma HLS unroll
    hNStubs[cMemIndx] = 0;
    (&hOutputStubs[cMemIndx])->clear(hBx);
#ifndef __SYNTHESIS__
    if (IR_DEBUG) {
    std::cout << ".........."
      << +(&hOutputStubs[cMemIndx])->getEntries(hBx) 
      << " entries... "
      << "\n";
    }
#endif
  }

LOOP_ProcessIR:
  for (int cStubCounter = 0; cStubCounter < kMaxStubsFromLink; cStubCounter++) {
#pragma HLS pipeline II = 1
#pragma HLS PIPELINE rewind
    // decode stub
    // check which memory
    ap_uint<kNBits_DTC> hStub = hInputStubs[cStubCounter];
    if (hStub == 0)
      continue;

    ap_uint<3> hEncLyr = ap_uint<3>(hStub.range(kNBits_DTC - 1, kNBits_DTC - 2) & 0x3);
    ap_uint<kBRAMwidth> hStbWrd = hStub.range(kBRAMwidth - 1, 0);
    // get memory word
    DTCStub hMemWord(hStbWrd);
    
    // decode link wrd for this layer
    ap_uint<4> hWrd = hLinkWord.range(4 * hEncLyr + 3, 4 * hEncLyr);
    ap_uint<1> hIsBrl = hWrd.range(1, 0);
    ap_uint<3> hLyrId = hWrd.range(3, 1);
    // get phi bin
    ap_uint<3> hPhiBn;
    if (hIsBrl == 1) {
      if (hIs2S == 0)
        GetPhiBinBrl<BARRELPS, kSizePhiCorrTablePS>(hStub, kPhiCorrtable_L1, kPhiCorrtable_L2,
                                   kPhiCorrtable_L3, hLyrId, hPhiBn);
      else
        GetPhiBinBrl<BARREL2S, kSizePhiCorrTable2S>(hStub, kPhiCorrtable_L4, kPhiCorrtable_L5,
                                    kPhiCorrtable_L6, hLyrId, hPhiBn);
    } else {
      if (hIs2S == 0)
        GetPhiBinDsk<DISKPS>(hStub, hLyrId, hPhiBn);
      else
        GetPhiBinDsk<DISK2S>(hStub, hLyrId, hPhiBn);
    }

    // update index
    unsigned int cIndx = 0;
  LOOP_UpdateMemIndx:
    for (int cLyr = 0; cLyr < kNLayers; cLyr++) {
#pragma HLS unroll
      // update index
      cIndx += (cLyr < hEncLyr) ? (unsigned int)(hNPhiBns[cLyr]) : 0;
    }
    
    // write to memory
    unsigned int cMemIndx = cIndx + hPhiBn;
    assert(cMemIndx < cNMemories);
    ap_uint<8> hEntries = hNStubs[cMemIndx];
#ifndef __SYNTHESIS__
    if (IR_DEBUG) {
      std::cout << "\t.. Stub : " << std::hex << hStbWrd << std::dec
                << " [ EncLyrId " << hEncLyr << " ] "
                << "[ LyrId " << hLyrId << " ] IsBrl bit " << +hIsBrl
                << " PhiBn#" << +hPhiBn << " Mem#" << cMemIndx
                << " Current number of entries " << +hEntries << "\n";
    }
#endif
    (&hOutputStubs[cMemIndx])->write_mem(hBx, hMemWord, hEntries);
    hNStubs[cMemIndx] = hEntries + 1;
  }

#ifndef __SYNTHESIS__
  if (IR_DEBUG) {
    std::cout << "After processing...\n";
    for (unsigned int cMemIndx = 0; cMemIndx < kNIRMemories; cMemIndx++) {
      std::cout << ".........."
        << +(&hOutputStubs[cMemIndx])->getEntries(hBx) 
        << " entries... "
        << "\n";
    }
  }
#endif

}