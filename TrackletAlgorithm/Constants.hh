#ifndef CONSTANTS_HH
#define CONSTANTS_HH

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

static const int kTMUX = 6;
static const int kMaxProc = kTMUX * 6;

// Memory
static const int kNBits_MemAddr = 7;
static const int kMemDepth = (1<<kNBits_MemAddr);
static const int kNBits_BX = 3;

const int MEBinsBits = 3;
const int TEBinsBits = 3;

#endif
