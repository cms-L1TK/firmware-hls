#ifndef TrackletAlgorithm_ProjectionRouter_h
#define TrackletAlgorithm_ProjectionRouter_h

// Projection Router
#include "Constants.h"
#include "TrackletProjectionMemory.h"
#include "AllProjectionMemory.h"
#include "VMProjectionMemory.h"

//#include <assert.h>

namespace PR
{
  template<regionType PROJTYPE, unsigned int nINMEM>
  bool new_read_input_mems(BXType bx,
                       ap_uint<nINMEM>& mem_hasdata,
                       ap_uint<kNBits_MemAddr> nentries[nINMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       const TrackletProjectionMemory<PROJTYPE> projin[],
                       TrackletProjection<PROJTYPE>& data) 
  {
#pragma HLS inline

    if (mem_hasdata == 0) return false;
    // 3 bits memory index for up to 8 input memory priority encoder
    ap_uint<3> read_imem = __builtin_ctz(mem_hasdata);
    data = projin[read_imem].read_mem(bx, read_addr);
    ++read_addr;
    if (read_addr >= nentries[read_imem]) {
      // All entries in the memory[read_imem] have been read out - Prepare to move to the next non-empty memory
      read_addr = 0;
      mem_hasdata.clear(read_imem);  // set the current lowest 1 bit to 0
    }

    return true;

  } // new_read_input_mems

  /////////////////////////////////////////////////////
  // FIXME
  // Move the following to Constants.h?
  // How to deal with these using enum?

  // number of allstub memories for each layer
  constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
  // number of VMs in one allstub block for each layer
  constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

  // number of allstub memories for each disk
  constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
  
  // number of VMs in one allstub block for each disk
  constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};

  // Number of loop iterations subtracted from the full 108 so that the function
  // stays synchronized with other functions in the chain. Once we get these
  // functions to rewind correctly, this can be set to zero (or simply removed)
  constexpr unsigned int LoopItersCut = 6; 
  
} // namesapce PR

//////////////////////////////
// ProjectionRouter
template<regionType PROJTYPE, regionType VMPTYPE, unsigned int nINMEM,
         int LAYER=0, int DISK=0>
void ProjectionRouter(BXType bx,
                      const TrackletProjectionMemory<PROJTYPE> projin[],
                      BXType& bx_o,
                      AllProjectionMemory<PROJTYPE>* const allprojout,
                      VMProjectionMemory<VMPTYPE>* const vmprojout1,
                      VMProjectionMemory<VMPTYPE>* const vmprojout2,
                      VMProjectionMemory<VMPTYPE>* const vmprojout3,
                      VMProjectionMemory<VMPTYPE>* const vmprojout4,
                      VMProjectionMemory<VMPTYPE>* const vmprojout5,
                      VMProjectionMemory<VMPTYPE>* const vmprojout6,
                      VMProjectionMemory<VMPTYPE>* const vmprojout7,
                      VMProjectionMemory<VMPTYPE>* const vmprojout8
){
#pragma HLS inline
#pragma HLS array_partition variable=projin complete dim=1

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
  ap_uint<kNBits_MemAddr> numbersin[nINMEM];
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0
  for (int i=0; i<nINMEM; i++) {
#pragma HLS unroll
    numbersin[i] = projin[i].getEntries(bx);
    if (numbersin[i] > 0) mem_hasdata.set(i);
  }

  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;

  // declare counters for each of the 8 output VMProj // !!!
  int nvmprojout1 = 0;
  int nvmprojout2 = 0;
  int nvmprojout3 = 0;
  int nvmprojout4 = 0;
  int nvmprojout5 = 0;
  int nvmprojout6 = 0;
  int nvmprojout7 = 0;
  int nvmprojout8 = 0;  
  int nallproj = 0;

  PROC_LOOP: for (int i = 0; i < kMaxProc-LoopItersCut; ++i) {
#pragma HLS PIPELINE II=1

    // read inputs
    TrackletProjection<PROJTYPE> tproj;
    bool validin = new_read_input_mems<PROJTYPE,nINMEM>(bx, mem_hasdata, numbersin, mem_read_addr, projin, tproj);

    if (validin) {
    
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
      typename VMProjection<VMPTYPE>::VMPID index = i;
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
    
      typename VMProjection<VMPTYPE>::VMPZBIN zbin = (zbin1, zbin2!=zbin1);
    
      //fine vm z bits. Use 4 bits for fine position. starting at zbin 1
      // need to be careful about left shift of ap_(u)int
      typename VMProjection<VMPTYPE>::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zbin1,ap_uint<3>(0));

      // vmproj irinv
      // phider = -irinv/2
      // Note: auto does not work well here
      // auto infers 42 bits because -2 is treated as a 32-bit int
      ap_uint<TrackletProjection<PROJTYPE>::BitWidths::kTProjPhiDSize+1> irinv_tmp = iphider * (-2);

      // rinv in VMProjection takes only the top 5 bits
      // and is shifted to be positive
      typename VMProjection<VMPTYPE>::VMPRINV rinv = 16+(irinv_tmp>>(irinv_tmp.length()-5));
      //assert(rinv >=0 and rinv < 32);
    
      // PS seed
      // top 3 bits of tracklet index indicate the seeding pair
      ap_uint<3> iseed = trackletid >> (trackletid.length()-3);
      // Cf. https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATrackletCalculator.hh#L166
      // and here?
      // https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATracklet.hh#L1621
      // NOTE: emulation fw_synch branch does not include L2L3 seeding; the master branch does

      // All seeding pairs are PS modules except L3L4 and L5L6
      bool psseed = not(iseed==2 or iseed==3); 

      // VM Projection
      VMProjection<VMPTYPE> vmproj(index, zbin, finez, rinv, psseed);

      // write outputs
      //assert(iphi>=0 and iphi<4);
      switch(iphi) {
      case 0:
        vmprojout1->write_mem(bx, vmproj, nvmprojout1);
        nvmprojout1 ++;
        break;
      case 1:
        vmprojout2->write_mem(bx, vmproj, nvmprojout2);
        nvmprojout2 ++;
        break;
      case 2:
        vmprojout3->write_mem(bx, vmproj, nvmprojout3);
        nvmprojout3 ++;
        break;
      case 3:
        vmprojout4->write_mem(bx, vmproj, nvmprojout4);
        nvmprojout4 ++;
        break;
      case 4:
        vmprojout5->write_mem(bx, vmproj, nvmprojout5);
        nvmprojout5 ++;
        break;
      case 5:
        vmprojout6->write_mem(bx, vmproj, nvmprojout6);
        nvmprojout6 ++;
        break;
      case 6:
        vmprojout7->write_mem(bx, vmproj, nvmprojout7);
        nvmprojout7 ++;
        break;
      case 7:
        vmprojout8->write_mem(bx, vmproj, nvmprojout8);
        nvmprojout8 ++;
        break;
      }

      /////////////////
      // AllProjection
      AllProjection<PROJTYPE> aproj(tproj.raw());
      // write output
      allprojout->write_mem(bx, aproj, nallproj);
      nallproj ++;
    }

    if (i==kMaxProc-LoopItersCut-1) bx_o = bx;
 
  } // end of PROC_LOOP
  
} // ProjectionRouter

#endif
