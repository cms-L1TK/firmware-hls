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
  bool read_input_mems(BXType bx,
                       ap_uint<nINMEM>& mem_hasdata,
                       ap_uint<kNBits_MemAddr> nentries[nINMEM],
                       ap_uint<kNBits_MemAddr>& read_addr,
                       const TrackletProjectionMemory<PROJTYPE> projin[],
                       TrackletProjection<PROJTYPE>& data) 
  {
#pragma HLS inline

    if (mem_hasdata == 0) return false;
    // 5 bits memory index for up to 32 input memory priority encoder
    ap_uint<5> read_imem = __builtin_ctz(mem_hasdata);
    data = projin[read_imem].read_mem(bx, read_addr);
    ++read_addr;
    if (read_addr >= nentries[read_imem]) {
      // All entries in the memory[read_imem] have been read out - Prepare to move to the next non-empty memory
      read_addr = 0;
      mem_hasdata.clear(read_imem);  // set the current lowest 1 bit to 0
    }

    return true;

  } // read_input_mems

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

} // namespace PR

//////////////////////////////
// ProjectionRouter
template<regionType PROJTYPE, regionType VMPTYPE, unsigned int nINMEM,
         unsigned int nOUTMEM, int LAYER=0, int DISK=0>
void ProjectionRouter(BXType bx,
                      const TrackletProjectionMemory<PROJTYPE> projin[],
                      BXType& bx_o,
                      AllProjectionMemory<PROJTYPE>& allprojout,
                      VMProjectionMemory<VMPTYPE> vmprojout[])
{
#pragma HLS inline
#pragma HLS array_partition variable=projin complete dim=1
#pragma HLS array_partition variable=vmprojout complete dim=1

  using namespace PR;

  // Initialization
  ap_uint<kNBits_MemAddr> nallproj;
  ap_uint<kNBits_MemAddr> nvmprojout[nOUTMEM];
  ap_uint<nINMEM> mem_hasdata;
  ap_uint<kNBits_MemAddr> numbersin[nINMEM];
  ap_uint<kNBits_MemAddr> mem_read_addr;

  PROC_LOOP: for (int istep = 0; istep < kMaxProc - kMaxProcOffset(module::PR); ++istep) {
#pragma HLS PIPELINE II=1 rewind
    if (istep == 0) {

      // reset output memories & counters
      nallproj = 0;
#pragma HLS ARRAY_PARTITION variable=nvmprojout complete dim=0
      allprojout.clear(bx);
      for (int i=0; i<nOUTMEM; i++) {
#pragma HLS unroll
        vmprojout[i].clear(bx);
        nvmprojout[i] = 0;
      }
      // check the number of entries in the input memories
      // fill the bit mask indicating if memories are empty or not
      mem_hasdata = 0;
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0
      for (int i=0; i<nINMEM; i++) {
#pragma HLS unroll
        numbersin[i] = projin[i].getEntries(bx);
        if (numbersin[i] > 0) mem_hasdata.set(i);
      }
      mem_read_addr = 0;

    } else {

      // read inputs
      TrackletProjection<PROJTYPE> tproj;
      bool validin = read_input_mems<PROJTYPE,nINMEM>(bx, mem_hasdata, numbersin, mem_read_addr, projin, tproj);

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
        typename VMProjection<VMPTYPE>::VMPID index = nallproj;
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

        // All seeding pairs are PS modules except L3L4 and L5L6
        bool psseed = not(iseed==2 or iseed==3); 

        // VM Projection
        VMProjection<VMPTYPE> vmproj(index, zbin, finez, rinv, psseed);

        // write outputs
        //assert(iphi>=0 and iphi<4);
        vmprojout[iphi].write_mem(bx, vmproj, nvmprojout[iphi]);
        nvmprojout[iphi] ++;

        /////////////////
        // AllProjection
        AllProjection<PROJTYPE> aproj(tproj.raw());
        // write output
        allprojout.write_mem(bx, aproj, nallproj);
        nallproj ++;
      }
    }

    if (istep==kMaxProc-kMaxProcOffset(module::PR)-1) bx_o = bx;
 
  } // end of PROC_LOOP
  
} // ProjectionRouter

#endif
