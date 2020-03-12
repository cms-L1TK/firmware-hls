#include "InputRouter.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"


void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map)
{
  Map->write_mem(1, encodedMap, address);
} // link map function 
//
void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap)
{
  encodedMap = Map.read_mem(1, address);
} 

