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

//*****************************************
//TrackletParameters
//*****************************************
//Bit sizes for tracklet parameters
constexpr unsigned int kRinvSize=14; //rinv
constexpr unsigned int kPhi0Size=17; //phi0
constexpr unsigned int kZ0Size=12; //z0
constexpr unsigned int kTSize=14; //t
//Bit size for full tracklet parameters 
constexpr unsigned int kTrackletParameterSize=kRinvSize+kPhi0Size+kZ0Size+kTSize+2*kNBits_MemAddr;

//The least significant bit in the track parameter word for the different fields
constexpr unsigned int kRinvLSB=0;        
constexpr unsigned int kPhi0LSB=kRinvLSB+kRinvSize;
constexpr unsigned int kZ0LSB=kPhi0LSB+kPhi0Size;
constexpr unsigned int kTLSB=kZ0LSB+kZ0Size;
constexpr unsigned int kStubIndexInnerLSB=kTLSB+kTSize;
constexpr unsigned int kStubIndexOuterLSB=kStubIndexInnerLSB+kNBits_MemAddr;



//*****************************************
// Candidate Matches
//*****************************************
//Bit size for full candidate matche 
constexpr unsigned int kCandidateMatchSize=2*kNBits_MemAddr;
//The least significant bit in the candidate matches word for the different fields
constexpr unsigned int kStubIndexLSB=0;
constexpr unsigned int kProjIndexLSB=kNBits_MemAddr;

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


#endif
