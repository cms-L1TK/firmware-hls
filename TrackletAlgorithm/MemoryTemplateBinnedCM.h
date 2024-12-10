// Class template for binned memory module
#ifndef TrackletAlgorithm_MemoryTemplateBinnedCM_h
#define TrackletAlgorithm_MemoryTemplateBinnedCM_h

#ifndef __SYNTHESIS__
#include <iostream>
#include <sstream>
#include <vector>
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

//This is a bit of a hack, but until we find a cleaner
//way to implement this we will use this...
#include "SynthesisOptions.h"

#ifdef CMSSW_GIT_HASH
template<class DataType, unsigned int DUMMY, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#else
template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#endif

// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BX): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX
// (1<<NBIT_ADDR): depth of the memory for each BX
// NBIT_BIN: number of bits used for binning; (1<<NBIT_BIN): number of bins
// NCOPY: is the number of memory copies - same as number of TE used

// N.B. The CMSSW version of this pretends to have NCOPY copies to anyone 
// using this class, but doesn't actually instantiate them, to save memory.

class MemoryTemplateBinnedCM{

private:
#ifdef CMSSW_GIT_HASH
  static constexpr bool isCMSSW = true;
  static constexpr unsigned int NBIT_BX = 0;
  static constexpr unsigned int NCP = 1;
#else
  static constexpr bool isCMSSW = false;
  static constexpr unsigned int NCP = NCOPY;
#endif

public:
  static constexpr unsigned int DEPTH_BX = 1<<NBIT_BX;
  static constexpr unsigned int DEPTH_ADDR = 1<<NBIT_ADDR;
  static constexpr unsigned int DEPTH_BIN = 1<<NBIT_BIN;
 
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR-NBIT_BIN> NEntryT;

protected:
  enum BitWidths {
    kNBxBins = DEPTH_BX,
    kNSlots = DEPTH_BIN,
    kNMemDepth = DEPTH_ADDR,
    kNBitsRZBinCM = NBIT_BIN-kNBitsphibinCM,
    kNBinsRZ = (1<<kNBitsRZBinCM),
    slots = (1<<(NBIT_BX+NBIT_BIN-kNBitsphibinCM))
  };

  DataType dataarray_[NCP][kNBxBins][kNMemDepth];  // data array
  BunchXingT write_bx_;                //BX for writing 

  ap_uint<8> binmask8_[kNBxBins][1<<kNBitsRZBinCM];
  ap_uint<64> nentries_[slots];

public:

  unsigned int getDepth() const {return kNMemDepth;}
  unsigned int getNBX() const {return kNBxBins;}
  unsigned int getNBins() const {return kNSlots;}
  unsigned int getNEntryPerBin() const {return (1<<(NBIT_ADDR-NBIT_BIN));}
  unsigned int getNCopy() const {return NCOPY;}

  void setWriteBX(const BunchXingT& ibx) {
    write_bx_ = ibx;
  }
  
  NEntryT getEntries(BunchXingT bx, ap_uint<NBIT_BIN> slot) const {
    ap_uint<kNBitsRZBinCM> ibin;
    ap_uint<kNBitsphibinCM> ireg;
    (ireg,ibin)=slot;
    return nentries_[bx][ibin].range(ireg*4+3,ireg*4);
  }

  ap_uint<64> getEntries(BunchXingT bx, ap_uint<kNBitsRZBinCM> ibin) const {
    return nentries_[bx*(1<<kNBitsRZBinCM)+ibin];
  }

  ap_uint<8> getBinMask8(BunchXingT bx, ap_uint<kNBitsRZBinCM> ibin) const {
#pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
    return binmask8_[bx][ibin];
  }

  NEntryT getEntries(BunchXingT bx) const {
    NEntryT val = 0;
    for ( auto i = 0; i < getDepth(); ++i ) {
      val += getEntries(bx, i);
    }
    return val;
  }

  const DataType (&getMem(unsigned int icopy) const)[DEPTH_BX][DEPTH_ADDR] {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    if (isCMSSW) icopy = 0;
    return dataarray_[icopy];
  }

#ifndef CMSSW_GIT_HASH
  const DataType (&get_mem() const)[NCOPY][DEPTH_BX][DEPTH_ADDR] {
    return dataarray_;
  }
#endif

  DataType read_mem(unsigned int icopy, BunchXingT ibx, ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {ibx = 0; icopy = 0;}
    return dataarray_[icopy][ibx][index];
  }
  
  DataType read_mem(unsigned int icopy, BunchXingT ibx, ap_uint<NBIT_BIN> slot,
                    ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {ibx = 0; icopy = 0;}
    return dataarray_[icopy][ibx][getNEntryPerBin()*slot+index];
  }

  bool write_mem(ap_uint<NBIT_BIN> slot, DataType data) {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
#pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline

    if (isCMSSW && !NBIT_BX) {write_bx_ = 0;}

#if defined __SYNTHESIS__  && !defined SYNTHESIS_TEST_BENCH

    dataarray_[0][write_bx_][getNEntryPerBin()*slot] = data;

#else

    // write address for slot: getNEntryPerBin() * slot + nentry_ibx

    ap_uint<kNBitsRZBinCM> ibin;
    ap_uint<kNBitsphibinCM> ireg;
    (ibin,ireg)=slot;

    unsigned int nentry = nentries_[write_bx_*kNBinsRZ+ibin].range(ireg*4+3,ireg*4);

    if (nentry == ((1 << (NBIT_ADDR-NBIT_BIN)) - 1)) return false;

    nentries_[write_bx_*kNBinsRZ+ibin].range(ireg*4+3,ireg*4)=nentry+1;
    if (ibin!=0) {
      nentries_[write_bx_*kNBinsRZ+ibin-1].range((ireg+8)*4+3,(ireg+8)*4)=nentry+1;
    }
    binmask8_[write_bx_][ibin].set_bit(ireg,true);

    //icopy comparison must be signed int or future SW fails
  writememloop:for (signed int icopy=0;icopy< (signed) NCP;icopy++) {
#pragma HLS unroll
      dataarray_[icopy][write_bx_][getNEntryPerBin()*slot+nentry] = data;
    }
    return true;
#endif      
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__

  MemoryTemplateBinnedCM() {
    clear();
  }

  ~MemoryTemplateBinnedCM() {}

  void clear() {

    DataType data("0",16);
    for (size_t ibx=0; ibx<(kNBxBins); ++ibx) {
      for (size_t icopy=0; icopy < NCP; icopy++) {
        for (size_t ibin=0; ibin < kNMemDepth; ibin++) {
          dataarray_[icopy][ibx][ibin] = data;
        }
      }
      // Clear nentries and binmask8
      for (unsigned int ibin = 0; ibin < getNBins()/8; ++ibin) {
        nentries_[ibx*kNBinsRZ+ibin] = 0;
        binmask8_[ibx][ibin] = 0;
      }
    }
  }

  // write memory from text file
  bool write_mem(const std::vector<std::string>& split_line, int base=16) {

    assert(split_line.size()==4);

    if (isCMSSW) {write_bx_ = 0;}

    std::string datastr = split_line.back();

    int slot = (int)strtol(split_line.front().c_str(), nullptr, base); // Convert string (in hexadecimal) to int

    DataType data(datastr.c_str(), base);

    bool success = write_mem(slot, data);
    
    return success;
  }

  
  // print memory contents
  void print_data(const DataType data) const
  {
    edm::LogVerbatim("L1trackHLS") << std::hex << data.raw() << std::endl;
    // TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, ap_uint<NBIT_ADDR> index) const
  {
    print_data(dataarray_[bx][index]);
  }

  //These are broken - comment out for now (ryd, 2024-10-27)
  /*
    void print_mem(BunchXingT bx) const {
      for(unsigned int ibin=0;ibin<8;ibin++) {
        for(unsigned int ireg=0;ireg<8;ireg++) {
          for (unsigned int i = 0; i < nentries_[ibx*kNBinsRZ+ibin].range(ireg*4+3,ireg*4); ++i) {
            edm::LogVerbatim("L1trackHLS") << bx << " " << i << " ";
            print_entry(bx, i + slot*getNEntryPerBin() );
          }
        }
      }
    }

    void print_mem() const {
      for (unsigned int ibx = 0; ibx < kNBxBins; ++ibx) {
        for (unsigned int i = 0; i < 8; ++i) {
          edm::LogVerbatim("L1trackHLS") << ibx << " " << i << " ";
          print_entry(ibx,i);
        }
      }
    }
  */
  
  static constexpr int getWidth() {return DataType::getWidth();}

#endif

#ifdef CMSSW_GIT_HASH
  std::string name_;
  void setName(std::string name) { name_ = name;}
  std::string const& getName() const { return name_;}

  unsigned int iSector_;
  void setSector(unsigned int iS) { iSector_ = iS;}
  unsigned int getSector() const { return iSector_;}
#endif
};

#endif
