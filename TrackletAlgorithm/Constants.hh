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
// Input Stubs
//*****************************************
// Bit size for input stubs
constexpr unsigned int kISBendSize = 3;
constexpr unsigned int kISPhiSize = 14;
constexpr unsigned int kISZSize = 12;
constexpr unsigned int kISRSize = 7;
//Bit size for full input stubs
constexpr unsigned int kInputStubSize = kISBendSize + kISPhiSize + kISZSize + kISRSize;

//The least significant bit in the input stubs word for different fields
constexpr unsigned int kISBendLSB = 0;
constexpr unsigned int kISPhiLSB = kISBendLSB + kISBendSize;
constexpr unsigned int kISZLSB = kISPhiLSB + kISPhiSize;
constexpr unsigned int kISRLSB = kISZLSB + kISZSize;


//*****************************************
// VM Stubs
//*****************************************
//Bit size for VMStubs
constexpr unsigned int kVMSFineZSize = 4;
constexpr unsigned int kVMSBendSize = 3;
constexpr unsigned int kVMSIndexSize = 7;
//Bit size for full VMStubs
constexpr unsigned int kVMStubSize = kVMSFineZSize + kVMSBendSize + kVMSIndexSize;

//The least significant bit in the VMStub word for different fields
constexpr unsigned int kVMSFineZLSB = 0;
constexpr unsigned int kVMSBendLSB = kVMSFineZLSB + kVMSFineZSize;
constexpr unsigned int kVMSIndexLSB = kVMSBendLSB + kVMSBendSize;


//*****************************************
// All Stubs
//*****************************************
// Bit size for all stubs
constexpr unsigned int kASBendSize = 3;
constexpr unsigned int kASPhiSize = 14;
constexpr unsigned int kASZSize = 12;
constexpr unsigned int kASRSize = 7;
//Bit size for full all stubs
constexpr unsigned int kAllStubSize = kASBendSize + kASPhiSize + kASZSize + kASRSize;

//The least significant bit in the all stubs word for different fields
constexpr unsigned int kASBendLSB = 0;
constexpr unsigned int kASPhiLSB = kASBendLSB + kASBendSize;
constexpr unsigned int kASZLSB = kASPhiLSB + kASPhiSize;
constexpr unsigned int kASRLSB = kASZLSB + kASZSize;


//*****************************************
// Stub Pairs
//*****************************************
//Bit size for full stub pairs
constexpr unsigned int kStubPairSize=2*kNBits_MemAddr;
//The least significant bit in the stub pairs word for the different fields
constexpr unsigned int kSPOuterIndexLSB=0;
constexpr unsigned int kSPInnerIndexLSB=kNBits_MemAddr;


//*****************************************
// TrackletParameters
//*****************************************
//Bit sizes for tracklet parameters
constexpr unsigned int kTParRinvSize=14; //rinv
constexpr unsigned int kTParPhi0Size=17; //phi0
constexpr unsigned int kTParZ0Size=12; //z0
constexpr unsigned int kTParTSize=14; //t
//Bit size for full tracklet parameters 
constexpr unsigned int kTrackletParameterSize=kTParRinvSize+kTParPhi0Size+kTParZ0Size+kTParTSize+2*kNBits_MemAddr;

//The least significant bit in the track parameter word for the different fields
constexpr unsigned int kTParRinvLSB=0;        
constexpr unsigned int kTParPhi0LSB=kTParRinvLSB+kTParRinvSize;
constexpr unsigned int kTParZ0LSB=kTParPhi0LSB+kTParPhi0Size;
constexpr unsigned int kTParTLSB=kTParZ0LSB+kTParZ0Size;
constexpr unsigned int kTParStubIndexInnerLSB=kTParTLSB+kTParTSize;
constexpr unsigned int kTParStubIndexOuterLSB=kTParStubIndexInnerLSB+kNBits_MemAddr;


//*****************************************
// Tracklet Projections
//*****************************************
//Bit size for tracklet projections
constexpr unsigned int kTProjZDSize = 10;
constexpr unsigned int kTProjPhiDSize = 11;
constexpr unsigned int kTProjZSize = 12;
constexpr unsigned int kTProjPhiSize = 14;
constexpr unsigned int kTProjTCIndexSize = 13;
//Bit size for full tracklet projections
constexpr unsigned int kTrackletProjectionSize = 1 + 1 +kTProjTCIndexSize + kTProjPhiSize + kTProjZSize + kTProjPhiDSize + kTProjZDSize;

// The least significant bit in the tracklet projection word for different fields
constexpr unsigned int kTProjZDLSB = 0;
constexpr unsigned int kTProjPhiDLSB = kTProjZDLSB + kTProjZDSize;
constexpr unsigned int kTProjZLSB = kTProjPhiDLSB + kTProjPhiDSize;
constexpr unsigned int kTProjPhiLSB = kTProjZLSB + kTProjZSize;
constexpr unsigned int kTProjTCIndexLSB = kTProjPhiLSB + kTProjPhiSize;
constexpr unsigned int kTProjIsMinusNeighbourLSB = kTProjTCIndexLSB + kTProjTCIndexSize;
constexpr unsigned int kTProjIsPlusNeighbourLSB = kTProjIsMinusNeighbourLSB + 1;


//*****************************************
// VMProjections
//*****************************************
//Bit sizes for vmprojections
constexpr unsigned int kVMProjRinvSize = 5;
constexpr unsigned int kVMProjFineZSize = 4;
constexpr unsigned int kVMProjZBinSize = MEBinsBits+1;
constexpr unsigned int kVMProjIndexSize = 7;
//Bit size for full vmprojections
constexpr unsigned int kVMProjectionSize = kVMProjRinvSize + kVMProjFineZSize + kVMProjZBinSize + kVMProjIndexSize + 1;

// The least significant bit in the VMProjection word for different fields
constexpr unsigned int kVMProjRinvLSB = 1;
constexpr unsigned int kVMProjFineZLSB = kVMProjRinvLSB + kVMProjRinvSize;
constexpr unsigned int kVMProjZBinLSB = kVMFineZLSB + kVMFineZSize;
constexpr unsigned int kVMProjIndexLSB = kVMProjZBinLSB + kVMProjZBinSize;


//*****************************************
// All Projections
//*****************************************
//Bit size for all projections
constexpr unsigned int kAProjZDSize = 10;
constexpr unsigned int kAProjPhiDSize = 11;
constexpr unsigned int kAProjZSize = 12;
constexpr unsigned int kAProjPhiSize = 14;
constexpr unsigned int kAProjTCIndexSize = 13;
//Bit size for full all projections
constexpr unsigned int kAllProjectionSize = 1 + 1 +kAProjTCIndexSize + kAProjPhiSize + kAProjZSize + kAProjPhiDSize + kAProjZDSize;

// The least significant bit in the tracklet projection word for different fields
constexpr unsigned int kAProjZDLSB = 0;
constexpr unsigned int kAProjPhiDLSB = kAProjZDLSB + kAProjZDSize;
constexpr unsigned int kAProjZLSB = kAProjPhiDLSB + kAProjPhiDSize;
constexpr unsigned int kAProjPhiLSB = kAProjZLSB + kAProjZSize;
constexpr unsigned int kAProjTCIndexLSB = kAProjPhiLSB + kAProjPhiSize;
constexpr unsigned int kAProjIsMinusNeighbourLSB = kAProjTCIndexLSB + kAProjTCIndexSize;
constexpr unsigned int kAProjIsPlusNeighbourLSB = kAProjIsMinusNeighbourLSB + 1;


//*****************************************
// Candidate Matches
//*****************************************
//Bit size for full candidate matches
constexpr unsigned int kCandidateMatchSize=2*kNBits_MemAddr;
//The least significant bit in the candidate matches word for the different fields
constexpr unsigned int kCMStubIndexLSB=0;
constexpr unsigned int kCMProjIndexLSB=kNBits_MemAddr;


//*****************************************
// Full Matches
//*****************************************
//Bit size for full matches
constexpr unsigned int kFMZResSize = 9;
constexpr unsigned int kFMPhiResSize = 12;
constexpr unsigned int kFMStubIndexSize = 10;
constexpr unsigned int kFMTCIndexSize = 13;
//Bit size for full full matches
constexpr unsigned int kFullMatchSize = kFMTCIndexSize + kFMStubIndexSize + kFMPhiResSize + kFMZResSize;

// The least significant bit in the full matches word for different fields
constexpr unsigned int kFMZResLSB = 0;
constexpr unsigned int kFMPhiResLSB = kFMZResLSB + kFMZResSize;
constexpr unsigned int kFMStubIndexLSB = kFMPhiResLSB + kFMPhiResSize;
constexpr unsigned int kFMTCIndexLSB = kFMStubIndexLSB + kFMStubIndexSize;


//*****************************************
// Fit Track
//*****************************************
//Bit size for fit track
constexpr unsigned int kFTStubIndexSize = 10;
constexpr unsigned int kFTZ0Size = 10;
constexpr unsigned int kFTtSize = 14;
constexpr unsigned int kFTPhi0Size = 19;
constexpr unsigned int kFTpTSize = 15;
//Bit size for full fit track
constexpr unsigned int kFitTrackSize = kFTpTSize + kFTPhi0Size + kFTtSize + kFTZ0Size + 6*kFTStubIndexSize;

// The least significant bit in the fit track word for different fields
constexpr unsigned int kFTStubIndex6LSB = 0;
constexpr unsigned int kFTStubIndex5LSB = kFTStubIndex6LSB + kFTStubIndex6Size;
constexpr unsigned int kFTStubIndex4LSB = kFTStubIndex5LSB + kFTStubIndex5Size;
constexpr unsigned int kFTStubIndex3LSB = kFTStubIndex4LSB + kFTStubIndex4Size;
constexpr unsigned int kFTStubIndex2LSB = kFTStubIndex3LSB + kFTStubIndex3Size;
constexpr unsigned int kFTStubIndex1LSB = kFTStubIndex2LSB + kFTStubIndex2Size;
constexpr unsigned int kFTZ0LSB = kFTStubIndex1LSB + kFTStubIndex1Size;
constexpr unsigned int kFTTLSB = kFTZ0LSB + kFTZ0Size;
constexpr unsigned int kFTPhi0LSB = kFTTLSB + kFTTSize;
constexpr unsigned int kFTpTLSB = kFTPhi0LSB + kFTPhi0Size;


// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


#endif
