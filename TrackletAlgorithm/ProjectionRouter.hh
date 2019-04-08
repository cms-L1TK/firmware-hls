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
  // check the number of entries in the input memories
  // fill the bit mask indicating if memories are empty or not
  template<int nMEM, int NBits_Entries, class MemType>
  inline void init(BXType bx,
                   // bitmasks to indicate if memories are empty
                   ap_uint<nMEM>& mem_hasdata,
                   // number of entries for each memory
                   ap_uint<NBits_Entries> nentries[nMEM],
                   const int i,
                   const MemType* const mem)
  {    
    ap_uint<kNBits_MemAddr+1> num = mem->getEntries(bx);
    nentries[i] = num;
    if (num > 0) mem_hasdata.set(i);
  }
  
  // recursive case
  template<int nMEM, int NBits_Entries, class MemType, class... Args>
  inline void init(BXType bx, ap_uint<nMEM>& mem_hasdata,
                   ap_uint<NBits_Entries> nentries[nMEM],
                   const int i,
                   const MemType* const mem, Args... args)
  { 
    ap_uint<kNBits_MemAddr+1> num = mem->getEntries(bx);
    nentries[i] = num;
    if (num > 0) mem_hasdata.set(i);

    if (i+1 < nMEM) init(bx, mem_hasdata, nentries, i+1, args...);
  }

  //////////////////////////////
  // Priority encoder based input memory reading logic
  template<class DataType, class MemType>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i, const MemType* const inmem)
  {
    if (read_imem == i) data = inmem->read_mem(bx, read_addr);
  }

  template<class DataType, class MemType, class... Args>
  void read_inmem(DataType& data, BXType bx, ap_uint<5> read_imem,
                  ap_uint<kNBits_MemAddr>& read_addr,
                  const int i,
                  const MemType* const inmem, Args... args)
  {
    if (read_imem == i) data = inmem->read_mem(bx, read_addr);
    read_inmem(data, bx, read_imem, read_addr, i+1, args...);
  }

  
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
    read_inmem(data, bx, read_imem, read_addr, 0,
               mem0,mem1,mem2,mem3,mem4,mem5,mem6,mem7,
               mem8,mem9,mem10,mem11,mem12,mem13,mem14,mem15,
               mem16,mem17,mem18,mem19,mem20,mem21,mem22,mem23);

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
template<regionType PROJTYPE, regionType VMPTYPE, unsigned int nINMEM,
         int LAYER=0, int DISK=0>
void ProjectionRouter(BXType bx,
                      // because Vivado HLS cannot synthesize an array of
                      // pointers that point to stuff other than scalar or
                      // array of scalar ...
                      const TrackletProjectionMemory<PROJTYPE>* const proj1in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj2in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj3in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj4in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj5in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj6in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj7in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj8in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj9in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj10in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj11in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj12in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj13in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj14in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj15in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj16in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj17in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj18in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj19in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj20in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj21in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj22in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj23in,
                      const TrackletProjectionMemory<PROJTYPE>* const proj24in,
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

  //init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
  init<nINMEM, kNBits_MemAddr+1, TrackletProjectionMemory<PROJTYPE>>
    (bx, mem_hasdata, numbersin,0,
     proj1in,proj2in,proj3in,proj4in,proj5in,proj6in,proj7in,proj8in,
     proj9in,proj10in,proj11in,proj12in,proj13in,proj14in,proj15in,proj16in,
     proj17in,proj18in,proj19in,proj20in,proj21in,proj22in,proj23in,proj24in);
  
  // declare index of input memory to be read
  ap_uint<kNBits_MemAddr> mem_read_addr = 0;
  
  PROC_LOOP: for (int i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1

    // read inputs
    TrackletProjection<PROJTYPE> tproj;
    bool validin = read_input_mems<TrackletProjection<PROJTYPE>,
                                   TrackletProjectionMemory<PROJTYPE>,
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
    bool psseed = not(iseed==1 or iseed==2); 

    // VM Projection
    VMProjection<VMPTYPE> vmproj(index, zbin, finez, rinv, psseed);

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
    AllProjection<PROJTYPE> aproj(tproj.raw());
    // write output
    allprojout->write_mem(bx, aproj);

    bx_o = bx;
    
  } // end of PROC_LOOP
  
} // ProjectionRouter

#endif
