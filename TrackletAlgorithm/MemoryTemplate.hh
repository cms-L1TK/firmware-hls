// Class template for memory module
#ifndef MEMORYTEMPLATE_HH
#define MEMORYTEMPLATE_HH

#include <iostream>

template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR>
// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX;
// (1<<NBIT_ADDR): depth of the memory for each BX
class MemoryTemplate
{
public:
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

  DataType* get_mem() {return dataarray_;}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index) const
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	// TODO: check if valid
	return dataarray_[ibx][index];
  }

  bool write_mem(BunchXingT ibx, DataType data, const bool enable = true)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS dependence variable=nentries_ intra WAR true
#pragma HLS inline

	NEntryT nentry_ibx = nentries_[ibx];

	if (nentry_ibx <= (1<<NBIT_ADDR)) {
	  dataarray_[ibx][nentry_ibx] = data;
	  if (enable) nentries_[ibx] = nentry_ibx + 1;
	  return true;
	}
	else {
	  return false;
	}
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__
  
  // write memory from text file
  bool write_mem(BunchXingT ibx, const char* datastr, int base=16)
  {
	DataType data(datastr, base);
	// std::cout << "write_mem " << data << std::endl;
	return write_mem(ibx, data);
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
  
#endif
  
};

#endif
