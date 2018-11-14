#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

constexpr int kTMUX = 12;   //For hourglass project
constexpr int kMaxProc = kTMUX * 6;

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);


constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;


//TrackletParameters
constexpr unsigned int kRinvSize=14;
constexpr unsigned int kPhi0Size=17;
constexpr unsigned int kZ0Size=12;
constexpr unsigned int kTSize=14;

constexpr unsigned int kRinvStart=0;
constexpr unsigned int kPhi0Start=kRinvStart+kRinvSize;
constexpr unsigned int kZ0Start=kPhi0Start+kPhi0Size;
constexpr unsigned int kTStart=kZ0Start+kZ0Size;
constexpr unsigned int kStubInnerStart=kTStart+kTSize;
constexpr unsigned int kStubOuterStart=kStubInnerStart+kNBits_MemAddr;

// Candidate Matches

constexpr unsigned int kStubIndexStart=0;
constexpr unsigned int kProjIndexStart=kNBits_MemAddr;

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


#endif
