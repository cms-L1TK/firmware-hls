#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

constexpr int kTMUX = 6;
constexpr int kMaxProc = kTMUX * 6;

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;


//TrackletParameters
constexpr unsigned int kRinvSize=14;
constexpr unsigned int kPhi0Size=17;
constexpr unsigned int kZ0Size=12;
constexpr unsigned int kTSize=14;

constexpr unsigned int kRinvStart=0;
constexpr unsigned int kPhi0Start=KRinvStart+kRinvSize;
constexpr unsigned int kZ0Start=KPhi0Start+kPhi0Size;
constexpr unsigned int kTStart=KZ0Start+kZ0Size;
constexpr unsigned int kStubInnerStart=KTStart+kTSize;
constexpr unsigned int kStubOuterStart=KStubInnerStart+kNBits_MemAddr;


// Global BX type
typedef ap_uint <3> BXType;  // temporary definition. need to be revisited

#endif
