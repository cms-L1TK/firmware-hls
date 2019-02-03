#ifndef PROJECTIONROUTER_HH
#define PROJECTIONROUTER_HH

// Projection Router
#include "Constants.hh"
#include "TrackletProjectionMemory.hh"
#include "AllProjectionMemory.hh"
#include "VMProjectionMemory.hh"

//#include <assert.h>

namespace PR
{

  //////////////////////////////
  // Initialization
  template<class MemType, int nMEM, int NBits_Entries>
  void init(BXType bx,
            // bitmasks to indicate if memories are empty
            ap_uint<nMEM>& mem_hasdata,
            // number of entries for each memory
            ap_uint<NBits_Entries> nentries[nMEM],
            // memory pointers
            const MemType* const mem0, const MemType* const mem1,
            const MemType* const mem2, const MemType* const mem3,
            const MemType* const mem4, const MemType* const mem5,
            const MemType* const mem6, const MemType* const mem7,
            const MemType* const mem8, const MemType* const mem9,
            const MemType* const mem10, const MemType* const mem11,
            const MemType* const mem12, const MemType* const mem13,
            const MemType* const mem14, const MemType* const mem15,
            const MemType* const mem16, const MemType* const mem17,
            const MemType* const mem18, const MemType* const mem19,
            const MemType* const mem20, const MemType* const mem21,
            const MemType* const mem22, const MemType* const mem23
            )
  {
    static_assert(nMEM<=24, "PR: maximum number of input memory allowed in 24.");
    
    mem_hasdata = 0;
    
    if (nMEM > 0) {
      ap_uint<NBits_Entries> num0 = mem0->getEntries(bx);
      nentries[0] = num0;
      if (num0 > 0) mem_hasdata.set(0);
    }
    if (nMEM > 1) {
      ap_uint<NBits_Entries> num1 = mem1->getEntries(bx);
      nentries[1] = num1;
      if (num1 > 0) mem_hasdata.set(1);
    }
    if (nMEM > 2) {
      ap_uint<NBits_Entries> num2 = mem2->getEntries(bx);
      nentries[2] = num2;
      if (num2 > 0) mem_hasdata.set(2);
    }
    if (nMEM > 3) {
      ap_uint<NBits_Entries> num3 = mem3->getEntries(bx);
      nentries[3] = num3;
      if (num3 > 0) mem_hasdata.set(3);
    }
    if (nMEM > 4) {
      ap_uint<NBits_Entries> num4 = mem4->getEntries(bx);
      nentries[4] = num4;
      if (num4 > 0) mem_hasdata.set(4);
    }
    if (nMEM > 5) {
      ap_uint<NBits_Entries> num5 = mem5->getEntries(bx);
      nentries[5] = num5;
      if (num5 > 0) mem_hasdata.set(5);
    }
    if (nMEM > 6) {
      ap_uint<NBits_Entries> num6 = mem6->getEntries(bx);
      nentries[6] = num6;
      if (num6 > 0) mem_hasdata.set(6);
    }
    if (nMEM > 7) {
      ap_uint<NBits_Entries> num7 = mem7->getEntries(bx);
      nentries[7] = num7;
      if (num7 > 0) mem_hasdata.set(7);
    }
    if (nMEM > 8) {
      ap_uint<NBits_Entries> num8 = mem8->getEntries(bx);
      nentries[8] = num8;
      if (num8 > 0) mem_hasdata.set(8);
    }
    if (nMEM > 9) {
      ap_uint<NBits_Entries> num9 = mem9->getEntries(bx);
      nentries[9] = num9;
      if (num9 > 0) mem_hasdata.set(9);
    }
    if (nMEM > 10) {
      ap_uint<NBits_Entries> num10 = mem10->getEntries(bx);
      nentries[10] = num10;
      if (num10 > 0) mem_hasdata.set(10);
    }
    if (nMEM > 11) {
      ap_uint<NBits_Entries> num11 = mem11->getEntries(bx);
      nentries[11] = num11;
      if (num11 > 0) mem_hasdata.set(11);
    }
    if (nMEM > 12) {
      ap_uint<NBits_Entries> num12 = mem12->getEntries(bx);
      nentries[12] = num12;
      if (num12 > 0) mem_hasdata.set(12);
    }
    if (nMEM > 13) {
      ap_uint<NBits_Entries> num13 = mem13->getEntries(bx);
      nentries[13] = num13;
      if (num13 > 0) mem_hasdata.set(13);
    }
    if (nMEM > 14) {
      ap_uint<NBits_Entries> num14 = mem14->getEntries(bx);
      nentries[14] = num14;
      if (num14 > 0) mem_hasdata.set(14);
    }
    if (nMEM > 15) {
      ap_uint<NBits_Entries> num15 = mem15->getEntries(bx);
      nentries[15] = num15;
      if (num15 > 0) mem_hasdata.set(15);
    }
    if (nMEM > 16) {
      ap_uint<NBits_Entries> num16 = mem16->getEntries(bx);
      nentries[16] = num16;
      if (num16 > 0) mem_hasdata.set(16);
    }
    if (nMEM > 17) {
      ap_uint<NBits_Entries> num17 = mem17->getEntries(bx);
      nentries[17] = num17;
      if (num17 > 0) mem_hasdata.set(17);
    }
    if (nMEM > 18) {
      ap_uint<NBits_Entries> num18 = mem18->getEntries(bx);
      nentries[18] = num18;
      if (num18 > 0) mem_hasdata.set(18);
    }
    if (nMEM > 19) {
      ap_uint<NBits_Entries> num19 = mem19->getEntries(bx);
      nentries[19] = num19;
      if (num19 > 0) mem_hasdata.set(19);
    }
    if (nMEM > 20) {
      ap_uint<NBits_Entries> num20 = mem20->getEntries(bx);
      nentries[20] = num20;
      if (num20 > 0) mem_hasdata.set(20);
    }
    if (nMEM > 21) {
      ap_uint<NBits_Entries> num21 = mem21->getEntries(bx);
      nentries[21] = num21;
      if (num21 > 0) mem_hasdata.set(21);
    }
    if (nMEM > 22) {
      ap_uint<NBits_Entries> num22 = mem22->getEntries(bx);
      nentries[22] = num22;
      if (num22 > 0) mem_hasdata.set(22);
    }
    if (nMEM > 23) {
      ap_uint<NBits_Entries> num23 = mem23->getEntries(bx);
      nentries[23] = num23;
      if (num23 > 0) mem_hasdata.set(23);
    }
    
  } // init

  //////////////////////////////
  // Priority encoder based input memory reading logic
  template<class DataType, class MemType, int nMEM, int NBits_Entries>
  bool read_input_mems(BXType bx,
                       ap_uint<nMEM>& mem_hasdata,
                       ap_uint<NBits_Entries> nentries[nMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       // memory pointers
                       const MemType* const mem0, const MemType* const mem1,
                       const MemType* const mem2, const MemType* const mem3,
                       const MemType* const mem4, const MemType* const mem5,
                       const MemType* const mem6, const MemType* const mem7,
                       const MemType* const mem8, const MemType* const mem9,
                       const MemType* const mem10, const MemType* const mem11,
                       const MemType* const mem12, const MemType* const mem13,
                       const MemType* const mem14, const MemType* const mem15,
                       const MemType* const mem16, const MemType* const mem17,
                       const MemType* const mem18, const MemType* const mem19,
                       const MemType* const mem20, const MemType* const mem21,
                       const MemType* const mem22, const MemType* const mem23,
                       DataType& data)
  {
    if (mem_hasdata == 0) return false;

    // 5 bits memory index for up to 32 input memories
    // priority encoder
    ap_uint<5> read_imem = __builtin_ctz(mem_hasdata);

    // read the memory "read_imem" with the address "read_addr"
    switch (read_imem) {
    case 0:
      data = mem0->read_mem(bx, read_addr); break;
    case 1:
      data = mem1->read_mem(bx, read_addr); break;
    case 2:
      data = mem2->read_mem(bx, read_addr); break;
    case 3:
      data = mem3->read_mem(bx, read_addr); break;
    case 4:
      data = mem4->read_mem(bx, read_addr); break;
    case 5:
      data = mem5->read_mem(bx, read_addr); break;
    case 6:
      data = mem6->read_mem(bx, read_addr); break;
    case 7:
      data = mem7->read_mem(bx, read_addr); break;
    case 8:
      data = mem8->read_mem(bx, read_addr); break;
    case 9:
      data = mem9->read_mem(bx, read_addr); break;
    case 10:
      data = mem10->read_mem(bx, read_addr); break;
    case 11:
      data = mem11->read_mem(bx, read_addr); break;
    case 12:
      data = mem12->read_mem(bx, read_addr); break;
    case 13:
      data = mem13->read_mem(bx, read_addr); break;
    case 14:
      data = mem14->read_mem(bx, read_addr); break;
    case 15:
      data = mem15->read_mem(bx, read_addr); break;
    case 16:
      data = mem16->read_mem(bx, read_addr); break;
    case 17:
      data = mem17->read_mem(bx, read_addr); break;
    case 18:
      data = mem18->read_mem(bx, read_addr); break;
    case 19:
      data = mem19->read_mem(bx, read_addr); break;
    case 20:
      data = mem20->read_mem(bx, read_addr); break;
    case 21:
      data = mem21->read_mem(bx, read_addr); break;
    case 22:
      data = mem22->read_mem(bx, read_addr); break;
    case 23:
      data = mem23->read_mem(bx, read_addr); break;      
    }

    // Increase the read address
    ++read_addr;

    if (read_addr >= nentries[read_imem]) {
      // All entries in the memory[read_imem] have been read out
      // Prepare to move to the next non-empty memory
      read_addr = 0;
      mem_hasdata.clear(read_imem);  // set the current lowest 1 bit to 0
    }

    return true;
    
  } // read_input_mems

  /////////////////////////////////////////////////////
  // FIXME
  // Move the following to Constants.hh?
  // How to deal with these using enum?

  // number of allstub memories for each layer
  constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
  // number of VMs in one allstub block for each layer
  constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

  // number of allstub memories for each disk
  constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
  
  // number of VMs in one allstub block for each disk
  constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};
  
} // namesapce PR

//////////////////////////////
// ProjectionRouter
template<class MemTypeTProj, class MemTypeAProj, class MemTypeVMProj,
         class DataTypeTProj, class DataTypeAProj, class DataTypeVMProj,
         // Is there a way to infer data type from memory type?
         unsigned int nINMEM, int LAYER=0, int DISK=0>
void ProjectionRouter(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
                      const MemTypeTProj* const proj1in,
                      const MemTypeTProj* const proj2in,
                      const MemTypeTProj* const proj3in,
                      const MemTypeTProj* const proj4in,
                      const MemTypeTProj* const proj5in,
                      const MemTypeTProj* const proj6in,
                      const MemTypeTProj* const proj7in,
                      const MemTypeTProj* const proj8in,
                      const MemTypeTProj* const proj9in,
                      const MemTypeTProj* const proj10in,
                      const MemTypeTProj* const proj11in,
                      const MemTypeTProj* const proj12in,
                      const MemTypeTProj* const proj13in,
                      const MemTypeTProj* const proj14in,
                      const MemTypeTProj* const proj15in,
                      const MemTypeTProj* const proj16in,
                      const MemTypeTProj* const proj17in,
                      const MemTypeTProj* const proj18in,
                      const MemTypeTProj* const proj19in,
                      const MemTypeTProj* const proj20in,
                      const MemTypeTProj* const proj21in,
                      const MemTypeTProj* const proj22in,
                      const MemTypeTProj* const proj23in,
                      const MemTypeTProj* const proj24in,
                      BXType& bx_o,
                      MemTypeAProj* const allprojout,
                      MemTypeVMProj* const vmprojout1,
                      MemTypeVMProj* const vmprojout2,
                      MemTypeVMProj* const vmprojout3,
                      MemTypeVMProj* const vmprojout4,
                      MemTypeVMProj* const vmprojout5,
                      MemTypeVMProj* const vmprojout6,
                      MemTypeVMProj* const vmprojout7,
                      MemTypeVMProj* const vmprojout8
){
#pragma HLS inline off

  using namespace PR;
  
  // reset output memories
  allprojout->clear(bx);
  vmprojout1->clear(bx);
  vmprojout2->clear(bx);
  vmprojout3->clear(bx);
  vmprojout4->clear(bx);
  vmprojout5->clear(bx);
  vmprojout6->clear(bx);
  vmprojout7->clear(bx);
  vmprojout8->clear(bx);

  // initialization:
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  ap_uint<nINMEM> mem_hasdata = 0;
  ap_uint<kNBits_MemAddr+1> numbersin[nINMEM];
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0

  init<MemTypeTProj, nINMEM, kNBits_MemAddr+1>
    (bx, mem_hasdata, numbersin,
     proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
     proj9in, proj10in, proj11in, proj12in, proj13in, proj14in, proj15in, proj16in,
     proj17in, proj18in, proj19in, proj20in, proj21in, proj22in, proj23in, proj24in);
  
  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;
  
  PROC_LOOP: for (int i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1

    // read inputs
    DataTypeTProj tproj;
    bool validin = read_input_mems<DataTypeTProj, MemTypeTProj,
                                   nINMEM, kNBits_MemAddr+1>
      (bx, mem_hasdata, numbersin, mem_read_addr,
       proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
       proj9in, proj10in, proj11in, proj12in, proj13in, proj14in, proj15in, proj16in,
       proj17in, proj18in, proj19in, proj20in, proj21in, proj22in, proj23in, proj24in,
       tproj);

    if (not validin) continue;
    
    auto iphiproj = tproj.getPhi();
    auto izproj = tproj.getRZ();
    auto iphider = tproj.getPhiDer();
    auto trackletid = tproj.getTCID();

    //////////////////////////
    // hourglass configuration
   
    // top 5 bits of phi
    auto iphi5 = iphiproj>>(iphiproj.length()-5);
    
    // total number of VMs
    auto nvm = LAYER!=0 ? nvmmelayers[LAYER-1]*nallstubslayers[LAYER-1] :
      nvmmedisks[DISK-1]*nallstubsdisks[DISK-1];
    //assert(nvm>0);
    
    // number of VMs per module
    auto nbins = LAYER!=0 ? nvmmelayers[LAYER-1] : nvmmedisks[DISK-1];

    // routing
    ap_uint<3> iphi = (iphi5/(32/nvm))&(nbins-1);  // OPTIMIZE ME
    
    ///////////////
    // VMProjection
    static_assert(not DISK, "PR: Layer only for now.");
    
    // vmproj index
    typename DataTypeVMProj::VMPID index = i;
    //assert(i < (1<<index.length()));

    // vmproj z
    // Separate the vm projections into zbins
    // The central bin e.g. zbin=4+(zproj.value()>>(zproj.nbits()-3));
    // (assume 8 bins; take top 3 bits of zproj and shift it to make it positive)
    // But we need some range (particularly for L5L6 seed projecting to L1-L3):
    // Lower bound
    ap_uint<MEBinsBits+1> zbin1tmp = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))-2)>>2);
    // Upper bound
    ap_uint<MEBinsBits+1> zbin2tmp = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))+2)>>2);
    if (zbin1tmp >= (1<<MEBinsBits)) zbin1tmp = 0; //note that zbin1 is unsigned
    if (zbin2tmp >= (1<<MEBinsBits)) zbin2tmp = (1<<MEBinsBits)-1;

    // One extra bit was used in the above calculation. Now take it away.
    ap_uint<MEBinsBits> zbin1 = zbin1tmp;
    ap_uint<MEBinsBits> zbin2 = zbin2tmp;
    //assert(zbin1<=zbin2);
    //assert(zbin2-zbin1<=1);
    
    typename DataTypeVMProj::VMPZBIN zbin = (zbin1, zbin2!=zbin1);
    
    //fine vm z bits. Use 4 bits for fine position. starting at zbin 1
    // need to be careful about left shift of ap_(u)int
    typename DataTypeVMProj::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zbin1,ap_uint<3>(0));

    // vmproj irinv
    // phider = -irinv/2
    // Note: auto does not work well here
    // auto infers 42 bits because -2 is treated as a 32-bit int
    ap_uint<DataTypeTProj::BitWidths::kTProjPhiDSize+1> irinv_tmp = iphider * (-2);

    // rinv in VMProjection takes only the top 5 bits
    // and is shifted to be positive
    typename DataTypeVMProj::VMPRINV rinv = 16+(irinv_tmp>>(irinv_tmp.length()-5));
    //assert(rinv >=0 and rinv < 32);
    
    // PS seed
    // top 3 bits of tracklet index indicate the seeding pair
    ap_uint<3> iseed = trackletid >> (trackletid.length()-3);
    // Cf. https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATrackletCalculator.hh#L166
    // and here?
    // https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATracklet.hh#L1621
    // NOTE: emulation fw_synch branch does not include L2L3 seeding; the master branch does

    // All seeding pairs are PS modules except L3L4 and L5L6
    bool psseed = not(iseed==1 or iseed==2); 

    // VM Projection
    DataTypeVMProj vmproj(index, zbin, finez, rinv, psseed);

    // write outputs
    //assert(iphi>=0 and iphi<4);
    switch(iphi) {
    case 0:
      vmprojout1->write_mem(bx, vmproj); break;
    case 1:
      vmprojout2->write_mem(bx, vmproj); break;
    case 2:
      vmprojout3->write_mem(bx, vmproj); break;
    case 3:
      vmprojout4->write_mem(bx, vmproj); break;
    case 4:
      vmprojout5->write_mem(bx, vmproj); break;
    case 5:
      vmprojout6->write_mem(bx, vmproj); break;
    case 6:
      vmprojout7->write_mem(bx, vmproj); break;
    case 7:
      vmprojout8->write_mem(bx, vmproj); break;
    }

    /////////////////
    // AllProjection
    DataTypeAProj aproj(tproj.raw());
    // write output
    allprojout->write_mem(bx, aproj);

    bx_o = bx;
    
  } // end of PROC_LOOP
  
} // ProjectionRouter

#endif
