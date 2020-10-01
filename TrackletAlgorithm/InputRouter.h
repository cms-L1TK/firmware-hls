#ifndef TrackletAlgorithm_InputRouter_h
#define TrackletAlgorithm_InputRouter_h


#include <cassert>
#include "Constants.h"
#include "AllStubMemory.h"


// link map
constexpr int kLINKMAPwidth = 20;
#ifndef __SYNTHESIS__
	#include <bitset> 
#endif


// maximum number of IR memories 
constexpr unsigned int kNIRMemories = 20;

// mxmium number of layers readout by a DTC 
constexpr unsigned int kNLayers = 4;

// Number of MSBs used for r index in phicorr LUTs
constexpr int kNBitsPhiCorrTableR = 3; // Found hardcoded in VMRouterphicorrtable.h
// size of link LUT 
constexpr int kSizeLinkTable = 12;
// size of phi correction table 
// for barrel PS
constexpr int kSizePhiCorrTablePS = 64;
// size of phi correction table 
// for barrel 2S
constexpr int kSizePhiCorrTable2S = 128;
// number of phi bins IR sorts 
// stubs into for first PS barrel 
constexpr int kNbitsPhiBinsPSL1 = 3; 
// number of phi bins IR sorts 
// stubs into for all regions of 
// the tracker 
// except for PS L1
constexpr int kNbitsPhiBinsTkr = 2; 

//
#define IR_DEBUG false

// Get the corrected phi, i.e. phi at the average radius of the barrel
// Corrected phi is used by ME and TE memories in the barrel
template<regionType InType>
inline typename AllStub<InType>::ASPHI getPhiCorr(
		const typename AllStub<InType>::ASPHI phi,
		const typename AllStub<InType>::ASR r,
		const typename AllStub<InType>::ASBEND bend, const int phicorrtable[]) 
{

	if (InType == DISKPS || InType == DISK2S)
		return phi; // Do nothing if disks

	constexpr auto rbins = 1 << kNBitsPhiCorrTableR; // The number of bins for r

	ap_uint<kNBitsPhiCorrTableR> rbin = (r + (1 << (r.length() - 1)))
			>> (r.length() - kNBitsPhiCorrTableR); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * rbins + rbin; // Index for where we find our correction value
	auto corrval = phicorrtable[index]; // The amount we need to correct our phi

	auto phicorr = phi - corrval; // the corrected phi
	
	// Check for overflow
	if (phicorr < 0)
		phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length())
		phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}


template<regionType ASType, unsigned int nCorrBns> 
void GetPhiBinBrl(const ap_uint<kNBits_DTC> inStub
	, const int kPhiCorrtable_L1[nCorrBns]
	, const int kPhiCorrtable_L2[nCorrBns]
	, const int kPhiCorrtable_L3[nCorrBns]
	, ap_uint<3> pLyrId 
	, ap_uint<3> &phiBn )
{
	#pragma HLS pipeline II=1 
	#pragma HLS inline 

	ap_uint<8> hPhiMSB = AllStub<ASType>::kASPhiMSB;
	ap_uint<8> hPhiLSB;
	if( pLyrId == 1 && ASType == BARRELPS ) 
		hPhiLSB = AllStub<ASType>::kASPhiMSB-(kNbitsPhiBinsPSL1-1);
	else
		hPhiLSB = AllStub<ASType>::kASPhiMSB-(kNbitsPhiBinsTkr-1);

	AllStub<ASType> hStub(inStub.range(kBRAMwidth-1,0));
	ap_uint<3> phiBnRaw = hStub.raw().range(hPhiMSB,hPhiLSB) & 0x7;

	#ifndef __SYNTHESIS__
			if( IR_DEBUG )
			{
				std::cout << "\t\t.. original phi bin is "
					<< phiBnRaw
					<< "\n";
			}
	#endif
	typename AllStub<ASType>::ASPHI hPhiCorrected; 
	if( pLyrId == 1 || pLyrId == 4 )
	{  
		//GetPhiCorrection<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L1,hPhiCorrected); 
		hPhiCorrected = getPhiCorr<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L1); 
	}
	else if( pLyrId == 2 || pLyrId == 5 )
	{  
		//GetPhiCorrection<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L2,hPhiCorrected); 
		hPhiCorrected = getPhiCorr<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L2); 
	}
	else if( pLyrId == 3 || pLyrId == 6 )
	{  
		//GetPhiCorrection<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L3,hPhiCorrected); 
		hPhiCorrected = getPhiCorr<ASType>(hStub.getPhi(), hStub.getR(), hStub.getBend(), kPhiCorrtable_L3); 
	}
	hStub.setPhi(hPhiCorrected);
	phiBn = hStub.raw().range(hPhiMSB,hPhiLSB) & 0x7;
	#ifndef __SYNTHESIS__
			if( IR_DEBUG )
			{
				std::cout << "\t\t.. after correction phi bin is "
					<< phiBn
					<< "\n";
			}
	#endif
	
}

template<regionType ASType> 
void GetPhiBinDsk(const ap_uint<kNBits_DTC> inStub
	, ap_uint<3> pLyrId 
	, ap_uint<3> &phiBn )
{
	#pragma HLS pipeline II=1 
	#pragma HLS inline 
	ap_uint<5> hPhiMSB = AllStub<ASType>::kASPhiMSB;
	ap_uint<5> hPhiLSB;
	if( pLyrId == 1 && ASType == BARRELPS ) 
		hPhiLSB = AllStub<ASType>::kASPhiMSB-(kNbitsPhiBinsPSL1-1);
	else
		hPhiLSB = AllStub<ASType>::kASPhiMSB-(kNbitsPhiBinsTkr-1);

	phiBn = inStub.range(hPhiMSB,hPhiLSB) & 0x7;
}

#endif


