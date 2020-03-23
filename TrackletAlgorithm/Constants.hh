#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

// DTC constants that we need to know about 
constexpr unsigned int kNBits_DTC = 38; 
// TF constants that we need to know about 
constexpr int kBRAMwidth = 36; 

constexpr int kMaxStubsFromLink = 256;

constexpr int kTMUX = 18;   //For hourglass project
constexpr int kMaxProc = kTMUX * 6;

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);


constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK};

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited

// link map word
constexpr int kLINKS = 24; 
constexpr int kLINKMAPwidth = 18;
constexpr int kNBits_LINK = 4;
typedef ap_uint<kNBits_LINK> LINK;  // temporary definition. need to be revisited

// data format 
constexpr unsigned int kNBits_Valid = 0;
constexpr unsigned int kNBits_LayerId = 2;
constexpr unsigned int kNBits_Debug = kNBits_Valid + kNBits_LayerId;

#endif
