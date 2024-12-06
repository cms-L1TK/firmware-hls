// Class template for memory module
#ifndef TrackletAlgorithm_MemoryTemplateTPROJ_h
#define TrackletAlgorithm_MemoryTemplateTPROJ_h

#include <iostream>
#include "../TestBenches/FileReadUtility.h"

//This is a bit of a hack, but until we find a cleaner
//way to implement this we will use this...
#include "SynthesisOptions.h"


template<int> class AllStub;

#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

#ifdef CMSSW_GIT_HASH
// L1 Track CMSSW Future SW currently assumes only 1 FPGA used,
// and hence 1 page of memory.
#define CMSSW_1FPGA
#endif

#ifdef CMSSW_GIT_HASH
#ifdef CMSSW_1FPGA
template<class DataType, unsigned int DUMMYA, unsigned int NBIT_ADDR, unsigned int DUMMYB >
#else
template<class DataType, unsigned int DUMMY, unsigned int NBIT_ADDR, unsigned int NPAGE = 4 >
#endif
#else
template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR, unsigned int NPAGE = 4 >
#endif

// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX;
// (1<<NBIT_ADDR): depth of the memory for each BX
// NPAGE is number of pages used within BX. This is used for the TPROJ memory
// to allow ordering of the different TP outputs
class MemoryTemplateTPROJ
{
private:
#ifdef CMSSW_GIT_HASH
  static constexpr unsigned int NBIT_BX = 0;
#ifdef CMSSW_1FPGA
  static constexpr unsigned int NPAGE = 1;
#endif
#endif

public:
  static constexpr unsigned int DEPTH_BX = 1<<NBIT_BX;
  static constexpr unsigned int DEPTH_ADDR = 1<<NBIT_ADDR;

  //Reduced to 63 to avoid nentry counter wrapping to zero
  static constexpr unsigned int MAX_TPROJ_PAGE_SIZE = 63;

  typedef typename DataType::BitWidths BitWidths;
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR> NEntryT;
  
protected:

  DataType dataarray_[DEPTH_BX][NPAGE*DEPTH_ADDR];  // data array
  NEntryT nentries_[DEPTH_BX*NPAGE];                  // number of entries
  ap_uint<NPAGE> mask_[DEPTH_BX]; //bitmask for hits
  
public:

  unsigned int getDepth() const {return DEPTH_ADDR;}
  unsigned int getNBX() const {return DEPTH_BX;}
  unsigned int getNPage() const {return NPAGE;}

  NEntryT getEntries(BunchXingT bx, unsigned int page = 0) const {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline
    return nentries_[bx*NPAGE+page];
  }

  ap_uint<NPAGE> getMask(BunchXingT bx) const {
#pragma HLS ARRAY_PARTITION variable=mask__ complete dim=0
#pragma HLS inline
    return mask_[bx];
  }
  
  const DataType (&get_mem() const)[DEPTH_BX][(DEPTH_ADDR)*NPAGE] {return dataarray_;}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index, unsigned int page = 0) const
  {
    //assert(page < NPAGE);    
    // TODO: check if valid  
    if(!NBIT_BX) ibx = 0;
    return dataarray_[ibx][DEPTH_ADDR*page+index];
  }

  template<class SpecType>
  bool write_mem(BunchXingT ibx, SpecType data, NEntryT addr_index, unsigned int page)
  {
#pragma HLS inline
    if(!NBIT_BX) ibx = 0;
    static_assert(
                  std::is_same<DataType, SpecType>::value
                  || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISKPS> >::value)
                  || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISK2S> >::value)
                  , "Invalid conversion between data types");
    DataType sameData(data.raw());
    return write_mem(ibx, sameData, addr_index, page);
  }

  bool write_mem(BunchXingT ibx, DataType data, NEntryT addr_index, unsigned int page = 0)
  {
    //assert(page < NPAGE);        
#pragma HLS inline
    if(!NBIT_BX) ibx = 0;
    if (addr_index < DEPTH_ADDR) {
      //dataarray_[ibx][addr_index] = data;
#if defined __SYNTHESIS__  && !defined SYNTHESIS_TEST_BENCH
      //The vhd memory implementation will write to the correct address!!
      dataarray_[ibx][DEPTH_ADDR*page+addr_index] = data;
#else
      //NBIT_BX==1 is to identify the projection memories
      if (NBIT_BX==1 && nentries_[ibx*NPAGE+page]>=MAX_TPROJ_PAGE_SIZE) {
	return false;
      }
      dataarray_[ibx][DEPTH_ADDR*page+nentries_[ibx*NPAGE+page]++] = data;
      mask_[ibx].set(page);
      
#endif
      
      return true;
    } else {
      return false;
    }
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__
  MemoryTemplateTPROJ()
  {
    clear();
  }

  ~MemoryTemplateTPROJ(){}

  void clear()
  {
    DataType data("0",16);
  MEM_RST: for (size_t ibx=0; ibx<DEPTH_BX; ++ibx) {
      mask_[ibx]=0;
      for (size_t page = 0; page < NPAGE; page++) {
        nentries_[ibx*NPAGE+page] = 0;
        for (size_t addr=0; addr<DEPTH_ADDR; ++addr) {
          dataarray_[ibx][DEPTH_ADDR*page+addr] = data;
        }
      }
    }
  }

  bool write_mem_clear(BunchXingT ibx, DataType data, NEntryT addr_index, unsigned int page)
  {
    if(!NBIT_BX) ibx = 0;
    if (addr_index < DEPTH_ADDR) {
      //FIXME - shoudl this method be removed?
      return true;
    } else {
      return false;
    }
  }


  // write memory from text file
  bool write_mem(BunchXingT ibx, const char* datastr, int base=16, unsigned int page = 0 ) { 


    if(!NBIT_BX) ibx = 0;

    DataType data(datastr, base);
    NEntryT nent = nentries_[ibx*NPAGE+page]; 
    bool success = write_mem(ibx, data, nent, page);
    
    return success;
  }

  bool write_mem(BunchXingT ibx, const std::string& line, int base=16)
  {
    assert(split(line,' ').size()==4);

    const std::string datastr = split(line,' ').back();

    const std::string pagestr = split(line,' ').front();

    unsigned int page = NPAGE;
    if (pagestr=="0x00") page = 0;
    if (pagestr=="0x01") page = 1;
    if (pagestr=="0x02") page = 2;
    if (pagestr=="0x03") page = 3;
    assert(page < NPAGE);

    if(!NBIT_BX) ibx = 0;
    DataType data(datastr.c_str(), base);
    NEntryT nent = nentries_[ibx*NPAGE+page];
    bool success = write_mem(ibx, data, nent, page);

    return success;
  }

  // print memory contents
  void print_data(const DataType data) const
  {
    edm::LogVerbatim("L1trackHLS") << std::hex << data.raw() << std::endl;
    // TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, NEntryT index, unsigned int page = 0) const
  {
    print_data(dataarray_[bx][DEPTH_ADDR*page+index]);
  }

  void print_mem(BunchXingT bx) const {
    for (unsigned int page = 0; page < NPAGE; ++page) {
      for (unsigned int i = 0; i <  nentries_[bx*NPAGE+page]; ++i) {
        edm::LogVerbatim("L1trackHLS") << bx << " " << i << " ";
        print_entry(bx, i, page);
      }
    }
  }

  void print_mem() const
  {
    for (unsigned int ibx = 0; ibx < DEPTH_BX; ++ibx) {
      for (unsigned int page = 0; page < NPAGE; ++page) {
        for (unsigned int i = 0; i < nentries_[ibx*NPAGE+page]; ++i) {
          edm::LogVerbatim("L1trackHLS") << ibx << " " << page << " " << i << " ";
          print_entry(ibx, i, page);
        }
      }
    }
  }

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
