#ifndef TrackletAlgorithm_InputRouter_h
#define TrackletAlgorithm_InputRouter_h


#include <cassert>
#include "Constants.h"
#include "AllStubMemory.h"
#include "DTCStubMemory.h"


// link map
static const int kLINKMAPwidth = 20;
static const int kSizeLinkWord = 4; 
static const int kBINMAPwidth = 12; 
static const int kSizeBinWord =  3; 
static const int kNMEMwidth = 5;
#ifndef __SYNTHESIS__
	#include <bitset> 
#endif



// // maximum number of IR memories 
// constexpr unsigned int kNIRMemories = 20;

// mxmium number of layers readout by a DTC 
static const int kMaxLyrsPerDTC = 4; 

// Number of MSBs used for r index in phicorr LUTs
static const int kNBitsPhiCorrTableR = 3; // Found hardcoded in VMRouterphicorrtable.h
// size of link LUT 
static const int kSizeLinkTable = 12;
// size of phi correction table 
// for barrel PS
static const int kSizePhiCorrTablePS = 64;
// size of phi correction table 
// for barrel 2S
static const int kSizePhiCorrTable2S = 128;
// number of phi bins IR sorts 
// stubs into for first PS barrel 
static const int kNbitsPhiBinsPSL1 = 3; 
// number of phi bins IR sorts 
// stubs into for all regions of 
// the tracker 
// except for PS L1
static const int kNbitsPhiBinsTkr = 2; 

// typedefs
// encoded DTC layer id 
static const unsigned int kNBitsDTCLyrEnc=3;
typedef ap_uint<kNBitsDTCLyrEnc> EncodedDTCLyrId ;
// raw trakcker layer id 
static const unsigned int kNBitsLyrTk=3; 
typedef ap_uint<kNBitsLyrTk> TkLyrId ;
// barrel bit 
static const unsigned int kNBitsBrlBit=1;
typedef ap_uint<kNBitsBrlBit> BrlBit; 
//
static const unsigned int kNBitsPhi=3; 
typedef ap_uint<kNBitsPhi> LyrPhiBn; 
// link word 
typedef ap_uint<kSizeLinkWord> LnkWrd;

// 
static const int kNBrlLyrs = 3;
static const int kFrstPSBrlLyr = 1; 
static const int kScndPSBrlLyr = 2;
static const int kThrdPSBrlLyr = 3; 
static const int kFrst2SBrlLyr = 4; 
static const int kScnd2SBrlLyr = 5; 
static const int kThrd2SBrlLyr = 6; 
//
#define IR_DEBUG false

// Get the corrected phi, i.e. phi at the average radius of the barrel
// Corrected phi is used by ME and TE memories in the barrel
template<regionType InType>
typename AllStub<InType>::ASPHI getPhiCorr(
		const typename AllStub<InType>::ASPHI phi,
		const typename AllStub<InType>::ASR r,
		const typename AllStub<InType>::ASBEND bend, const int phicorrtable[]) 
{
	
	constexpr auto rbins = 1 << kNBitsPhiCorrTableR; // The number of bins for r
	ap_uint<kNBitsPhiCorrTableR> rbin = (r + (1 << (r.length() - 1)))
			>> (r.length() - kNBitsPhiCorrTableR); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * rbins + rbin; // Index for where we find our correction value
	auto corrval = phicorrtable[index]; // The amount we need to correct our phi
	auto phicorr = ((phi) - corrval); // the corrected phi
	
	// Check for overflow
	if (phicorr < 0)
		phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length())
		phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}


template<unsigned int nOMems>
void InputRouter( const BXType hBx
	, const ap_uint<kLINKMAPwidth> hLinkWord
	, const ap_uint<kBINMAPwidth> hPhBnWord 
	, const int hPhiCorrtable_L1[]
	, const int hPhiCorrtable_L2[]
	, const int hPhiCorrtable_L3[]
	, ap_uint<kNBits_DTC> hInputStubs[]
	, DTCStubMemory hOutputStubs[])
{

	#pragma HLS clock domain = slow_clock
  	#pragma HLS interface ap_memory port = hPhiCorrtable_L1
  	#pragma HLS interface ap_memory port = hPhiCorrtable_L2
  	#pragma HLS interface ap_memory port = hPhiCorrtable_L3
  
  	ap_uint<1> hIs2S= hLinkWord.range(kLINKMAPwidth-4,kLINKMAPwidth-4);
	// clear stub counter
	ap_uint<kNBits_MemAddr> hNStubs[nOMems];
	#pragma HLS array_partition variable = hNStubs complete
	LOOP_ClearOutputMemories:
	for (unsigned int cMemIndx = 0; cMemIndx < nOMems ; cMemIndx++) 
	{
	#pragma HLS unroll
	hNStubs[cMemIndx] = 0;
	 #ifndef __SYNTHESIS__
	  if (IR_DEBUG) {
	  std::cout << ".........."
	    << +(&hOutputStubs[cMemIndx])->getEntries(hBx) 
	    << " entries... "
	    << "\n";
	  }
	#endif
	}

	LOOP_ProcessIR:
	for (int cStubCounter = 0; cStubCounter < kMaxStubsFromLink; cStubCounter++) 
	{
	#pragma HLS pipeline II = 1
	#pragma HLS PIPELINE rewind
	  // decode stub
	  // check which memory
	  ap_uint<kNBits_DTC> hStub = hInputStubs[cStubCounter];
	  // add check of valid bit here 
	  if (hStub == 0)   continue;

	  ap_uint<kBRAMwidth> hStbWrd = ap_uint<kBRAMwidth>(hStub.range(kBRAMwidth - 1, 0));
	  int hEncLyr = (hStub.range(kNBits_DTC - 1, kNBits_DTC - 2) & 0x7);
	  // get memory word
	  DTCStub hMemWord(hStbWrd);
	    
	  // decode link wrd for this layer
	  int hIsBrl= hLinkWord.range(kSizeLinkWord * hEncLyr, kSizeLinkWord * hEncLyr);
	  int hLyrId= hLinkWord.range(3 + kSizeLinkWord * hEncLyr, 1 + kSizeLinkWord * hEncLyr);

	  // point to the correct 
	  // LUT with the phi 
	  // corrections 
	  static const int* cLUT; 
	  if( hLyrId == kFrstPSBrlLyr || hLyrId == kFrst2SBrlLyr ) 
	  	cLUT = hPhiCorrtable_L1;
	  else if( hLyrId == kScndPSBrlLyr || hLyrId == kScnd2SBrlLyr ) 
	  	cLUT = hPhiCorrtable_L2;
	  else 
	  	cLUT = hPhiCorrtable_L3;
	  
	  // update index
	  // and add phi bin 
	  int cMemIndx = 0;
	  int cIndx = 0;
	  LOOP_UpdateMemIndx:
	  for (int cLyr = 0; cLyr < kMaxLyrsPerDTC; cLyr++) 
	  {
	    #pragma HLS unroll
	    // update index
	    auto hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
	   	cIndx += (cLyr < hEncLyr) ? (1+(int)(hBnWrd)) : 0; 
	  }
	  
	  // get phi bin
	  // regionType cRegion = ( hIsBrl == 1 ) ? BARRELPS : DISKPS;
	  // cRegion = ( hIs2S == 1 ) ? static_cast<regionType>(cRegion+1) : cRegion ;
	  // barrel PS 
	  //if( cRegion == BARRELPS )  
	  if( hIsBrl == 1 && hIs2S == 0 )
	  {
	  	AllStub<BARRELPS> hAStub(hStub.range(kBRAMwidth-1,0));
	  	auto hPhiCorrected = getPhiCorr<BARRELPS>(hAStub.getPhi(), hAStub.getR(), hAStub.getBend(), cLUT); 
	  	const int hPhiBn = hPhiCorrected.range(hPhiCorrected.length()-1,hPhiCorrected.length()-kNbitsPhiBinsPSL1);
	  	cMemIndx = cIndx + hPhiBn;
	  }
	  else if( hIsBrl == 0 && hIs2S == 0 )
	  //else if( cRegion == DISKPS )
	  {
	  	auto hPhiMSB = AllStub<DISKPS>::kASPhiMSB;
		auto hPhiLSB = AllStub<DISKPS>::kASPhiMSB-(kNbitsPhiBinsTkr-1);
	    const int  hPhiBn = hStub.range(hPhiMSB,hPhiLSB) ;
		cMemIndx = cIndx + hPhiBn;
	  }
	  else if(  hIs2S == 0 )
	  //else if( cRegion == BARREL2S )
	  {
	  	AllStub<BARREL2S> hAStub(hStub.range(kBRAMwidth-1,0));
	  	auto hPhiCorrected = getPhiCorr<BARREL2S>(hAStub.getPhi(), hAStub.getR(), hAStub.getBend(), cLUT); 
	  	const int hPhiBn = hPhiCorrected.range(hPhiCorrected.length()-1,hPhiCorrected.length()-kNbitsPhiBinsTkr);
	    cMemIndx = cIndx + hPhiBn;
	  }
	  else if(  hIs2S == 1 )
	  //else if( cRegion == DISK2S )
	  {
	  	auto hPhiMSB = AllStub<DISK2S>::kASPhiMSB;
		auto hPhiLSB = AllStub<DISK2S>::kASPhiMSB-(kNbitsPhiBinsTkr-1);
	    const int hPhiBn = hStub.range(hPhiMSB,hPhiLSB);
	    cMemIndx = cIndx + hPhiBn;
	  }
	  assert(cMemIndx < (int)(nOMems));
	  
	  // write to memory
	  #ifndef __SYNTHESIS__
	  std::cout << "\t.. Stub : " << std::hex << hStbWrd << std::dec
	            << " Mem#" << cIndx
	            << " MemIndx#" << cMemIndx
	            << "\n";
	  #endif
	  int hEntries = int(hNStubs[cMemIndx]);
	  
	  #ifndef __SYNTHESIS__
	  if (IR_DEBUG) {
	  std::cout << "\t.. Stub : " << std::hex << hStbWrd << std::dec
	            << " [ EncLyrId " << hEncLyr << " ] "
	            << "[ LyrId " << hLyrId << " ] IsBrl bit " << +hIsBrl
	            << " Mem#" << cMemIndx
	            << " Current number of entries " << +hEntries << "\n";
	  }
	  #endif
	  (&hOutputStubs[cMemIndx])->write_mem(hBx, hMemWord, hEntries);
	  hNStubs[cMemIndx] = hEntries + 1;
	}
}


#endif


