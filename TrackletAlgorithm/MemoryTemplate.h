// Class template for memory module
#ifndef TrackletAlgorithm_MemoryTemplate_h
#define TrackletAlgorithm_MemoryTemplate_h

#include <iostream>

template<int> class AllStub;

template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR>
// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX;
// (1<<NBIT_ADDR): depth of the memory for each BX
class MemoryTemplate
{
public:
  typedef typename DataType::BitWidths BitWidths;
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR+1> NEntryT;
  
protected:

  DataType dataarray_[1<<NBIT_BX][1<<NBIT_ADDR];  // data array
  NEntryT nentries_[1<<NBIT_BX];                  // number of entries
  
public:

  MemoryTemplate()
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	clear();
  }

  ~MemoryTemplate(){}

  void clear()
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline
  MEM_RST: for (size_t ibx=0; ibx<(1<<NBIT_BX); ++ibx) {
#pragma HLS UNROLL
	  nentries_[ibx] = 0;
	}
  }

  void clear(BunchXingT bx) {
#pragma HLS inline
    nentries_[bx] = 0;
  }

  unsigned int getDepth() const {return (1<<NBIT_ADDR);}
  unsigned int getNBX() const {return (1<<NBIT_BX);}

  NEntryT getEntries(BunchXingT bx) const {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	return nentries_[bx];
  }

  const DataType (&get_mem() const)[1<<NBIT_BX][1<<NBIT_ADDR] {return dataarray_;}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index) const
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	// TODO: check if valid
	return dataarray_[ibx][index];
  }

  template<class SpecType>
  bool write_mem(BunchXingT ibx, SpecType data, int addr_index)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline
    static_assert(
      std::is_same<DataType, SpecType>::value
      || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISKPS> >::value)
      || (std::is_same<DataType, AllStub<DISK> >::value && std::is_same<SpecType, AllStub<DISK2S> >::value)
      , "Invalid conversion between data types");
    DataType sameData(data.raw());
    return write_mem(ibx,sameData,addr_index);
  }

  bool write_mem(BunchXingT ibx, DataType data, int addr_index)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline
    if (addr_index < (1<<NBIT_ADDR)) {
      dataarray_[ibx][addr_index] = data;
      nentries_[ibx] = addr_index + 1;
      return true;
    } else {
      return false;
    }
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__
  
  // write memory from text file
  bool write_mem(BunchXingT ibx, const char* datastr, int base=16)
  {
	DataType data(datastr, base);
        int nent = nentries_[ibx];
	// std::cout << "write_mem " << data << std::endl;
	return write_mem(ibx, data, nent);
  }
  bool write_mem(BunchXingT ibx, const std::string datastr, int base=16)
  {
    DataType data(datastr.c_str(), base);
        int nent = nentries_[ibx];
	// std::cout << "write_mem " << data << std::endl;
	return write_mem(ibx, data, nent);
  }

  // print memory contents
  void print_data(const DataType data) const
  {
	std::cout << std::hex << data.raw() << std::endl;
	// TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, ap_uint<NBIT_ADDR> index) const
  {
	print_data(dataarray_[bx][index]);
  }

  void print_mem(BunchXingT bx) const
  {
	for (int i = 0; i <  nentries_[bx]; ++i) {
	  std::cout << bx << " " << i << " ";
	  print_entry(bx,i);
	}
  }

  void print_mem() const
  {
	for (int ibx = 0; ibx < (1<<NBIT_BX); ++ibx) {
	  for (int i = 0; i < nentries_[ibx]; ++i) {
		std::cout << ibx << " " << i << " ";
		print_entry(ibx,i);
	  }
	}
  }

  static constexpr int getWidth() {return DataType::getWidth();}
  
#endif
  
};

#endif
