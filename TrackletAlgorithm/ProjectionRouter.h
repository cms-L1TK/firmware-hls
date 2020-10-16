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

  // number of bits used to distinguish allstub memories for each layer
  constexpr unsigned int nbits_allstubslayers[6]={3,2,2,2,2,2};
  // number of bits used to distinguish VMs in one allstub block for each layer
  constexpr unsigned int nbits_vmmelayers[6]={2,3,3,3,3,3};

  // number of bits used to distinguish allstub memories for each disk
  constexpr unsigned int nbits_allstubsdisks[5]={2,2,2,2,2};
  
  // number of bits used to distinguish VMs in one allstub block for each disk
  constexpr unsigned int nbits_vmmedisks[5]={3,2,2,2,2};

  // number of bits for seed in tracklet index
  constexpr unsigned int nbits_seed = 3;

  // number of extra bits to keep when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_nbitsextra = 2;

  // value by which a z-projection is adjusted up & down when calculating which zbin(s) a projection should go to
  constexpr unsigned int zbins_adjust = 2;

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

        // number of bits used to distinguish the different modules in each layer/disk
        auto nbits_all = LAYER!=0 ? nbits_allstubslayers[LAYER-1] : nbits_allstubsdisks[DISK-1];

        // number of bits used to distinguish between VMs within a module
        auto nbits_vmme = LAYER!=0 ? nbits_vmmelayers[LAYER-1] : nbits_vmmedisks[DISK-1];

        // bits used for routing
        auto iphi = iphiproj.range(iphiproj.length()-nbits_all-1,iphiproj.length()-nbits_all-nbits_vmme);

        ///////////////
        // VMProjection
        static_assert(not DISK, "PR: Layer only for now.");
    
        // vmproj index
        typename VMProjection<VMPTYPE>::VMPID index = nallproj;

        // vmproj z
        // Separate the vm projections into zbins
        // To determine which zbin in VMStubsME the ME should look in to match this VMProjection,
        // the purpose of these lines is to take the top MEBinsBits (3) bits of zproj and shift it
        // to make it positive, which gives the bin index. But there is a range of possible z values
        // over which we want to look for matched stubs, and there is therefore possibly 2 bins that
        // we will have to look in. So we first take the first MEBinsBits+zbins_nbitsextra (3+2=5)
        // bits of zproj, adjust the value up and down by zbins_adjust (2), then truncate the
        // zbins_adjust (2) LSBs to get the lower & upper bins that we need to look in.
        auto zbinposfull = (1<<(izproj.length()-1))+izproj;
        auto zbinpos5 = zbinposfull.range(izproj.length()-1,izproj.length()-MEBinsBits-zbins_nbitsextra);

        // Lower Bound
        auto zbinlower = zbinpos5<zbins_adjust ?
                         ap_uint<MEBinsBits+zbins_nbitsextra>(0) :
                         ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos5-zbins_adjust);
        // Upper Bound
        auto zbinupper = zbinpos5>((1<<(MEBinsBits+zbins_nbitsextra))-1-zbins_adjust) ? 
                         ap_uint<MEBinsBits+zbins_nbitsextra>((1<<(MEBinsBits+zbins_nbitsextra))-1) :
                         ap_uint<MEBinsBits+zbins_nbitsextra>(zbinpos5+zbins_adjust);

        ap_uint<MEBinsBits> zbin1 = zbinlower >> zbins_nbitsextra;
        ap_uint<MEBinsBits> zbin2 = zbinupper >> zbins_nbitsextra;
        
        typename VMProjection<VMPTYPE>::VMPZBIN zbin = (zbin1, zbin2!=zbin1);
    
        //fine vm z bits. Use 4 bits for fine position. starting at zbin 1
        // need to be careful about left shift of ap_(u)int
        auto nfinebits = VMProjection<VMPTYPE>::BitWidths::kVMProjFineZSize;
        ap_uint<VMProjection<VMPTYPE>::BitWidths::kVMProjFineZSize+zbins_nbitsextra-MEBinsBits> zeropad(0);
        typename VMProjection<VMPTYPE>::VMPFINEZ finez = (1<<(nfinebits+zbins_nbitsextra-1))+(izproj.range(izproj.length()-1,izproj.length()-nfinebits-zbins_nbitsextra))-(zbin1,zeropad);

        // vmproj irinv
        // phider = -irinv/2
        // Note: auto does not work well here
        // auto infers 42 bits because -2 is treated as a 32-bit int
        ap_uint<TrackletProjection<PROJTYPE>::BitWidths::kTProjPhiDSize+1> irinv_tmp = iphider * (-2);

        // rinv in VMProjection takes only the top 5 bits
        // and is shifted to be positive
        typename VMProjection<VMPTYPE>::VMPRINV rinv = (1<<(nbits_maxvm-1))+irinv_tmp.range(irinv_tmp.length()-1,irinv_tmp.length()-nbits_maxvm);
        //assert(rinv >=0 and rinv < 32);
    
        // PS seed
        // top 3 bits of tracklet index indicate the seeding pair
        ap_uint<nbits_seed> iseed = trackletid.range(trackletid.length()-1,trackletid.length()-nbits_seed);
        // Cf. https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATrackletCalculator.hh#L166
        // and here?
        // https://github.com/cms-tracklet/fpga_emulation_longVM/blob/fw_synch/FPGATracklet.hh#L1621

        // All seeding pairs are PS modules except L3L4 and L5L6
        bool psseed = not(iseed==TF::L3L4 or iseed==TF::L5L6); 

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
