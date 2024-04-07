// Class template for memory module
#ifndef TrackletAlgorithm_MemoryTemplate_h
#define TrackletAlgorithm_MemoryTemplate_h

#include <iostream>

template<int> class AllStub;

#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

#ifdef CMSSW_GIT_HASH
template<class DataType, unsigned int DUMMY, unsigned int NBIT_ADDR>
#else
template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR>
#endif

// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX;
// (1<<NBIT_ADDR): depth of the memory for each BX
class MemoryTemplate
{
#ifdef CMSSW_GIT_HASH
  static constexpr unsigned int NBIT_BX = 0;
#endif

public:
  typedef typename DataType::BitWidths BitWidths;
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR> NEntryT;
  
protected:

  DataType dataarray_[1<<NBIT_BX][1<<NBIT_ADDR];  // data array
  NEntryT nentries_[1<<NBIT_BX];                  // number of entries
  
public:

  unsigned int getDepth() const {return (1<<NBIT_ADDR);}
  unsigned int getNBX() const {return (1<<NBIT_BX);}

  NEntryT getEntries(BunchXingT bx) const {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	return nentries_[bx];
  }

  const DataType (&get_mem() const)[1<<NBIT_BX][1<<NBIT_ADDR] {return dataarray_;}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index) const
  {
	// TODO: check if valid
	if(!NBIT_BX) ibx = 0;
	return dataarray_[ibx][index];
  }

  template<class SpecType>
  bool write_mem(BunchXingT ibx, SpecType data)
  {
#pragma HLS inline
    const NEntryT addr_index =
#ifdef __SYNTHESIS__
      0;
#else
      nentries_[ibx];
#endif
    return write_mem(ibx,data,addr_index);
  }

  template<class SpecType>
  bool write_mem(BunchXingT ibx, SpecType data, NEntryT addr_index)
  {
#pragma HLS inline
    if(!NBIT_BX) ibx = 0;
    static_assert(
      std::is_same<DataType, SpecType>::value
      || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISKPS> >::value)
      || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISK2S> >::value)
      , "Invalid conversion between data types");
    DataType sameData(data.raw());
    return write_mem(ibx,sameData,addr_index);
  }

  bool write_mem(BunchXingT ibx, DataType data)
  {
#pragma HLS inline
    const NEntryT addr_index =
#ifdef __SYNTHESIS__
      0;
#else
      nentries_[ibx];
#endif
    return write_mem(ibx,data,addr_index);
  }

  bool write_mem(BunchXingT ibx, DataType data, NEntryT addr_index)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline
    if(!NBIT_BX) ibx = 0;
    if (addr_index < (1<<NBIT_ADDR)) {
#ifdef __SYNTHESIS__
      //The vhd memory implementation will write to the correct address!!
      dataarray_[ibx][0] = data;
#else
      dataarray_[ibx][nentries_[ibx]++] = data;
#endif

#ifndef __SYNTHESIS__
      nentries_[ibx] = addr_index + 1;
#endif

      return true;
    } else {
      return false;
    }
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__
  MemoryTemplate()
  {
       clear();
  }

  ~MemoryTemplate(){}

  void clear()
  {
    DataType data("0",16);
    MEM_RST: for (size_t ibx=0; ibx<(1<<NBIT_BX); ++ibx) {
      nentries_[ibx] = 0;
      for (size_t addr=0; addr<(1<<NBIT_ADDR); ++addr) {
        write_mem(ibx,data,addr);
      }
    }
  }

  // write memory from text file
  bool write_mem(BunchXingT ibx, const char* datastr, int base=16)
  { 
        if(!NBIT_BX) ibx = 0;
	DataType data(datastr, base);
	NEntryT nent = nentries_[ibx]; 
	bool success = write_mem(ibx, data, nent);

	return success;
  }

  bool write_mem(BunchXingT ibx, const std::string datastr, int base=16)
  {
	return write_mem(ibx, datastr.c_str(), base);
  }

  // print memory contents
  void print_data(const DataType data) const
  {
    edm::LogVerbatim("L1trackHLS") << std::hex << data.raw() << std::endl;
        // TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, NEntryT index) const
  {
	print_data(dataarray_[bx][index]);
  }

  void print_mem(BunchXingT bx) const
  {
	for (unsigned int i = 0; i <  nentries_[bx]; ++i) {
	  edm::LogVerbatim("L1trackHLS") << bx << " " << i << " ";
	  print_entry(bx,i);
	}
  }

  void print_mem() const
  {
	for (unsigned int ibx = 0; ibx < (1<<NBIT_BX); ++ibx) {
	  for (unsigned int i = 0; i < nentries_[ibx]; ++i) {
	    edm::LogVerbatim("L1trackHLS") << ibx << " " << i << " ";
	    print_entry(ibx,i);
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
