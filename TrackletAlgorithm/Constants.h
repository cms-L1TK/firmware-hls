#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

constexpr int kMaxStubsFromLink = 256;

constexpr int kTMUX = 18;   //For hourglass project
constexpr int kMaxProc = kTMUX * 6;

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);

constexpr int kNBits_z = 3;

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// stub digitization constants
constexpr double kr = 0.0292969;
constexpr double kphi = 7.71297e-06;
constexpr double kz = 0.0585938;

// tracklet digitization constants
constexpr double krinv = 1.0284e-06;
constexpr double kphi0 = 1.54259e-05;
constexpr double kt = 0.00195312;
constexpr double kz0 = 0.0585938;

// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK};

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


#endif
