#ifndef TrackletAlgorithm_InputRouter_h
#define TrackletAlgorithm_InputRouter_h


#include <cassert>
#include "Constants.h"
#include "AllStubMemory.h"
#include "DTCStubMemory.h"


// link map
constexpr int kLINKMAPwidth = 20;
constexpr int kSizeLinkWord = 4; 
constexpr int kBINMAPwidth = 12; 
constexpr int kSizeBinWord =  3; 
constexpr int kNMEMwidth = 8;
#ifndef __SYNTHESIS__
	#include <bitset> 
#endif



// // maximum number of IR memories 
// constexpr unsigned int kNIRMemories = 20;

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

// typedefs
// encoded DTC layer id 
constexpr unsigned int kNBitsDTCLyrEnc=3;
typedef ap_uint<kNBitsDTCLyrEnc> EncodedDTCLyrId ;
// raw trakcker layer id 
constexpr unsigned int kNBitsLyrTk=3; 
typedef ap_uint<kNBitsLyrTk> TkLyrId ;
// barrel bit 
constexpr unsigned int kNBitsBrlBit=1;
typedef ap_uint<kNBitsBrlBit> BrlBit; 
//
constexpr unsigned int kNBitsPhi=3; 
typedef ap_uint<kNBitsPhi> LyrPhiBn; 
// link word 
constexpr unsigned int kNBitsLnkWrd=4;
typedef ap_uint<kNBitsLnkWrd> LnkWrd;

// 
constexpr int kFrstPSBrlLyr = 1; 
constexpr int kScndPSBrlLyr = 2;; 
constexpr int kThrdPSBrlLyr = 3; 
constexpr int kFrst2SBrlLyr = 4; 
constexpr int kScnd2SBrlLyr = 5;; 
constexpr int kThrd2SBrlLyr = 6; 
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
  
  	ap_uint<1> hIs2S= hLinkWord.range(kLINKMAPwidth-3,kLINKMAPwidth-4);
	// clear stub counter
	ap_uint<kNMEMwidth> hNStubs[nOMems];
	//ap_uint<kNMEMwidth> *hNStubs = new ap_uint<kNMEMwidth>[(unsigned int)(hNmemories)];
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
	//#pragma HLS PIPELINE rewind
	  // decode stub
	  // check which memory
	  ap_uint<kNBits_DTC> hStub = hInputStubs[cStubCounter];
	  // add check of valid bit here 
	  if (hStub == 0)   continue;

	  // named constants in InputRouter.h 
	  EncodedDTCLyrId hEncLyr = EncodedDTCLyrId(hStub.range(kNBits_DTC - 1, kNBits_DTC - 2) & 0x3);
	  ap_uint<kBRAMwidth> hStbWrd = hStub.range(kBRAMwidth - 1, 0);
	  // get memory word
	  DTCStub hMemWord(hStbWrd);
	    
	  // decode link wrd for this layer
	  ap_uint<kSizeLinkWord> hWrd = hLinkWord.range(kSizeLinkWord * hEncLyr + (kSizeLinkWord-1), kSizeLinkWord * hEncLyr);
	  BrlBit hIsBrl = hWrd.range(hIsBrl.width, 0);
	  TkLyrId hLyrId = hWrd.range(hLyrId.width, hIsBrl.width);
	  // point to the correct 
	  // LUT with the phi 
	  // corrections 
	  const int* cLUT; 
	  if( hLyrId == kFrstPSBrlLyr || hLyrId == kFrst2SBrlLyr ) 
	  	cLUT = hPhiCorrtable_L1;
	  else if( hLyrId == kScndPSBrlLyr || hLyrId == kScnd2SBrlLyr ) 
	  	cLUT = hPhiCorrtable_L2;
	  else 
	  	cLUT = hPhiCorrtable_L3;
	  	
	  // get phi bin
	  LyrPhiBn hPhiBn = 0 ;
	  regionType cRegion = ( hIsBrl == 1 ) ? BARRELPS : DISKPS;
	  auto cIncrmntRegion = ( hIs2S == 1 ) ? 1 : 0;
	  cRegion = static_cast<regionType>(cIncrmntRegion+cRegion);
	  auto cPhiBitsOffset = ( hLyrId == 1  )  ?  kNbitsPhiBinsPSL1 : kNbitsPhiBinsTkr; 
	  if( cRegion == BARRELPS )  
	  {
	  	AllStub<BARRELPS> hAStub(hStub.range(kBRAMwidth-1,0));
	  	auto hPhiCorrected = getPhiCorr<BARRELPS>(hAStub.getPhi(), hAStub.getR(), hAStub.getBend(), cLUT); 
	  	hAStub.setPhi(hPhiCorrected);
	
	  	auto hPhiMSB = AllStub<BARRELPS>::kASPhiMSB;
		auto hPhiLSB = AllStub<BARRELPS>::kASPhiMSB-(cPhiBitsOffset-1);
	    hPhiBn = hAStub.raw().range(hPhiMSB,hPhiLSB) & 0x7;

	    #ifndef __SYNTHESIS__
	    {
	      if (IR_DEBUG) {
			  AllStub<BARRELPS> hRawStub(hStub.range(kBRAMwidth-1,0));
		      auto hPhiRaw = hRawStub.getPhi();
		      int cMemIndx=0;
		      for (int cLyr = 0; cLyr < kNLayers; cLyr++) 
			  {
			    #pragma HLS unroll
			    // update index
			    ap_uint<kSizeBinWord> hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
			    cMemIndx += (cLyr < hEncLyr) ? (1+(unsigned int)(hBnWrd)) : 0; 
			  }
		  	  std::cout << "\t.. Stub : " << std::hex << hRawStub.raw() << std::dec
		  			<< " Raw phi is " << hPhiRaw
		  			<< " Corrected phi is " <<  hPhiCorrected 
		            << " [ EncLyrId " << hEncLyr << " ] "
		            << "[ LyrId " << hLyrId << " ] IsBrl bit " << +hIsBrl
		            << " PhiBn#" << +hPhiBn   
		            << " there are already " << hNStubs[cMemIndx+hPhiBn] 
		            << " entries in this memory\n";
		 	}
		}
		#endif

	  }
	  else if( cRegion == DISKPS )
	  {
	  	auto hPhiMSB = AllStub<DISKPS>::kASPhiMSB;
		auto hPhiLSB = AllStub<DISKPS>::kASPhiMSB-(cPhiBitsOffset-1);
	    hPhiBn = hStub.range(hPhiMSB,hPhiLSB) & 0x7;
	  }
	  else if( cRegion == BARREL2S )
	  {
	  	AllStub<BARREL2S> hAStub(hStub.range(kBRAMwidth-1,0));
	  	auto hPhiCorrected = getPhiCorr<BARREL2S>(hAStub.getPhi(), hAStub.getR(), hAStub.getBend(), cLUT); 
	  	hAStub.setPhi(hPhiCorrected);
	
		auto hPhiMSB = AllStub<BARREL2S>::kASPhiMSB;
		auto hPhiLSB = AllStub<BARREL2S>::kASPhiMSB-(cPhiBitsOffset-1);
	    hPhiBn = hAStub.raw().range(hPhiMSB,hPhiLSB) & 0x7;
	  }
	  else if( cRegion == DISK2S )
	  {
	  	auto hPhiMSB = AllStub<DISK2S>::kASPhiMSB;
		auto hPhiLSB = AllStub<DISK2S>::kASPhiMSB-(cPhiBitsOffset-1);
	    hPhiBn = hStub.range(hPhiMSB,hPhiLSB) & 0x7;
	  }
	  
	  // update index
	  unsigned int cIndx = 0;
	  LOOP_UpdateMemIndx:
	  for (int cLyr = 0; cLyr < kNLayers; cLyr++) 
	  {
	    #pragma HLS unroll
	    // update index
	    ap_uint<kSizeBinWord> hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
	    cIndx += (cLyr < hEncLyr) ? (1+(unsigned int)(hBnWrd)) : 0; 
	  }
	  // and add phi bin 
	  unsigned int cMemIndx = cIndx + hPhiBn;
	  // write to memory
	  assert(cMemIndx < nOMems);
	  ap_uint<kNMEMwidth> hEntries = hNStubs[cMemIndx];
	  
	  #ifndef __SYNTHESIS__
	  if (IR_DEBUG) {
	  std::cout << "\t.. Stub : " << std::hex << hStbWrd << std::dec
	            << " [ EncLyrId " << hEncLyr << " ] "
	            << "[ LyrId " << hLyrId << " ] IsBrl bit " << +hIsBrl
	            << " PhiBn#" << +hPhiBn << " Mem#" << cMemIndx
	            << " Current number of entries " << +hEntries << "\n";
	  }
	  #endif
	  hOutputStubs[cMemIndx].write_mem(hBx, hMemWord, hEntries);
	  hNStubs[cMemIndx] = hEntries + 1;
	}
}


#endif


