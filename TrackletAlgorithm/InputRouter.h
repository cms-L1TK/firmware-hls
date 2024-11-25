#ifndef TrackletAlgorithm_InputRouter_h
#define TrackletAlgorithm_InputRouter_h


#include <cassert>
#include "hls_stream.h"
#include "Constants.h"
#include "AllStubMemory.h"
#include "InputStubMemory.h"
#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

#define IR_DEBUG false
// link map
static const int kNBitsLnkDsc = 4; 
static const int kNBitsNLnks = 6; 
static const int kLINKMAPwidth = 20;
static const int kSizeLinkWord = 4; 
static const int kBINMAPwidth = 32;//12; 
static const int kSizeBinWord =  8;//3; 
static const int kNMEMwidth = 5;
#ifndef __SYNTHESIS__
#include <bitset> 
#endif


// LUT with phi corrections to the nominal radius. Only used by layers.
// Values are determined by the radius and the bend of the stub.
const int kPhiCorrtable_L1[] =
#include "../emData/LUTsSplit/VMPhiCorrL1.tab"
;
const int kPhiCorrtable_L2[] =
#include "../emData/LUTsSplit/VMPhiCorrL2.tab"
;
const int kPhiCorrtable_L3[] =
#include "../emData/LUTsSplit/VMPhiCorrL3.tab"
;
const int kPhiCorrtable_L4[] =
#include "../emData/LUTsSplit/VMPhiCorrL4.tab"
;
const int kPhiCorrtable_L5[] =
#include "../emData/LUTsSplit/VMPhiCorrL5.tab"
;
const int kPhiCorrtable_L6[] =
#include "../emData/LUTsSplit/VMPhiCorrL6.tab"
;


// // maximum number of IR memories 
// constexpr unsigned int kNIRMemories = 20;

// mxm number of coarse phi bins 
constexpr int kMaxPhiBnsPrLyr = 8; 

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
// bn wrd 
typedef ap_uint<kSizeBinWord> BnWrd;
// 
static const int kNBrlLyrs = 3;
static const int kFrstPSBrlLyr = 1; 
static const int kScndPSBrlLyr = 2;
static const int kThrdPSBrlLyr = 3; 
static const int kFrst2SBrlLyr = 4; 
static const int kScnd2SBrlLyr = 5; 
static const int kThrd2SBrlLyr = 6; 
// valid bit in DTC stub 
// these can change when tarball is modified 
static const int kVldBitSize = 1 ; 
static const int kLSBVldBt = 0;
static const int kMSBVldBt = 0;
// lyr bit in DTC stub 
// these can change when tarball is modified 
static const int kLyBitsSize = 2; 
static const int kLSBLyrBts = 1;
static const int kMSBLyrBts = 2;

constexpr unsigned int kMaxNmemories = 20;  

// Get the corrected phi, bin
// i.e. phi at the average radius of the barrel
template<regionType InType>
void getCorrectedPhiBin(ap_uint<kBRAMwidth> hStbWrd
		, const int pLayerId 
		, int &phiBn ) 
{
#pragma HLS inline
//#pragma HLS array_partition variable = phicorrtable

  	AllStub<InType> hAStub(hStbWrd);
  	auto hPhi = hAStub.getPhi();
  	auto hR =  hAStub.getR();
  	auto hBend = hAStub.getBend();

	constexpr auto rbins = 1 << kNBitsPhiCorrTableR; // The number of bins for r
	ap_uint<kNBitsPhiCorrTableR> rbin = (hR + (1 << (AllStubBase<InType>::kASRSize - 1)))
			>> (AllStubBase<InType>::kASRSize - kNBitsPhiCorrTableR); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = hBend * rbins + rbin; // Index for where we find our correction value
	// The amount we need to correct our phi
 	int corrval = 0; 
 	int cNbits = 0;
	switch (pLayerId)  {
		case kFrstPSBrlLyr : 
			cNbits = kNbitsPhiBinsPSL1;
			corrval = kPhiCorrtable_L1[index];
			break;
		case kScndPSBrlLyr : 
			cNbits = kNbitsPhiBinsTkr;
			corrval = kPhiCorrtable_L2[index];
			break;
		case kThrdPSBrlLyr :
			cNbits = kNbitsPhiBinsTkr;
			corrval = kPhiCorrtable_L3[index];
			break;
		case kFrst2SBrlLyr : 
			cNbits = kNbitsPhiBinsTkr;
			corrval = kPhiCorrtable_L4[index];
			break;
		case kScnd2SBrlLyr : 
			cNbits = kNbitsPhiBinsTkr;
			corrval = kPhiCorrtable_L5[index];
			break;
		case kThrd2SBrlLyr : 
			cNbits = kNbitsPhiBinsTkr;
			corrval = kPhiCorrtable_L6[index];
			break;
	} 
	
 	// internal storage of phi value 
	auto hPhiCorr = hPhi - corrval; // the corrected phi
	// Check for overflow
	if (hPhiCorr < 0)
		hPhiCorr = 0; // can't be less than 0
	if (hPhiCorr >= 1 << AllStubBase<InType>::kASPhiSize)
		hPhiCorr = (1 << AllStubBase<InType>::kASPhiSize) - 1;  // can't be more than the max value

	auto cBn = hPhiCorr.range(AllStubBase<InType>::kASPhiSize-1, AllStubBase<InType>::kASPhiSize-cNbits);
	phiBn = cBn;
	#ifndef __SYNTHESIS__
		#if IR_DEBUG
	  	 	std::cout << "Un-corrected phi bin is " << hPhi.range(AllStubBase<InType>::kASPhiSize-1, AllStubBase<InType>::kASPhiSize-cNbits) 
	  	 		<< " Corrected phi bin is " << cBn << "\n";
	  	#endif
  	#endif
}


// Get the phi bin
// no correction needed [i.e. for diskPS/disk2S]
template<regionType InType>
void getPhiBin( ap_uint<kBRAMwidth> hStbWrd
		, const int cNbits 
		, int &phiBn ) 
{
#pragma HLS inline
  	
	AllStub<InType> hAStub(hStbWrd);
	//typename AllStub<InType>::ASPHI
	auto cPhi =  hAStub.getPhi();
	auto cBn = cPhi.range(AllStubBase<InType>::kASPhiSize-1, AllStubBase<InType>::kASPhiSize-cNbits);
	phiBn = cBn;
}

// clear internal counters 
template<unsigned int nEntriesSize>
void ClearCounters(ap_uint<kNBits_MemAddr> nEntries[nEntriesSize])
{
#pragma HLS inline
#pragma HLS array_partition variable = nEntries
  LOOP_ClearCounters:
	for (unsigned int cIndx = 0; cIndx < nEntriesSize ; cIndx++) 
  {
#pragma HLS unroll
    nEntries[cIndx]=0; 
  }
}

// internal memory counter
template<unsigned int nLyrs>
void CountMemories(const ap_uint<kBINMAPwidth> hPhBnWord 
	, unsigned int &nMems
	, unsigned int nMemsPerLyr[nLyrs]) 
{
#pragma HLS inline
#pragma HLS array_partition variable = nMemsPerLyr
  int cPrevSize=0; 
  LOOP_CountOutputMemories:
  for (unsigned int cLyr = 0; cLyr < kMaxLyrsPerDTC ; cLyr++) 
  {
#pragma HLS unroll
    //auto hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
    int cPrevSizeThisLyr=0;
    for( int cPhiBn = 0 ; cPhiBn < kMaxPhiBnsPrLyr; cPhiBn++)
    {
      auto hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + cPhiBn, kSizeBinWord * cLyr + cPhiBn);
      cPrevSizeThisLyr = (int)hBnWrd + cPrevSizeThisLyr;
    }
    nMemsPerLyr[cLyr] = cPrevSizeThisLyr;//(cLyr < nLyrs) ?  ((int)(hBnWrd)) : 0 ;
    nMems = (cLyr < nLyrs) ? (cPrevSize +  cPrevSizeThisLyr) : cPrevSize;
    cPrevSize = nMems;
  }
}

// internal calculation 
// of memory index 
template<unsigned int nLyrs>
void GetMemoryIndex(const ap_uint<kBINMAPwidth> hPhBnWord 
	, ap_uint<kLyBitsSize> hEncLyr 
	, int &hPhiBn
	, unsigned int &hIndx ) 
{
#pragma HLS inline
	// update index
	//int cCalculatedIndx=0; 
	int cPrevIndx=0; 
	int cOffst = 0; 
	LOOP_UpdateMemIndxGetOffst:
	for (int cLyr = 0; cLyr < kMaxLyrsPerDTC ; cLyr++) 
  	{
  		#pragma HLS unroll
		for( int cPhiBn = 0 ; cPhiBn < kMaxPhiBnsPrLyr; cPhiBn++)
  	 	{
  	 		#pragma HLS unroll
			auto hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + cPhiBn, kSizeBinWord * cLyr + cPhiBn);
  	 		int cUpdate = (cLyr < hEncLyr ) ? (int)hBnWrd : 0;
			cOffst = cPrevIndx + cUpdate; 
			cPrevIndx = cOffst;
  	 	}
  	}
	cPrevIndx = 0; 
	LOOP_UpdateMemIndx:
	for( int cPhiBn = 0 ; cPhiBn < kMaxPhiBnsPrLyr; cPhiBn++)
  	{
#pragma HLS unroll
		auto hBnWrd = hPhBnWord.range(kSizeBinWord * hEncLyr + cPhiBn, kSizeBinWord * hEncLyr + cPhiBn);
		int cUpdate = (cPhiBn < hPhiBn ) ? (int)hBnWrd : 0;
		hIndx = cPrevIndx + cUpdate; 
		cPrevIndx = hIndx;
	}
	hIndx = cPrevIndx + cOffst;
	
	#ifndef __SYNTHESIS__
		#if IR_DEBUG
	  	 	std::cout << "EncLyr#" << hEncLyr 
	  	 		<< " Complete bn word is " << std::bitset<kBINMAPwidth>(hPhBnWord)
	  	 		<< " BnWrd is " << std::bitset<kSizeBinWord>(hPhBnWord.range(kSizeBinWord*hEncLyr+kMaxPhiBnsPrLyr-1,kSizeBinWord*hEncLyr)) 
	  	 		<< " Offset is " << cOffst
	  	 		<< " MemIndex " << hIndx << " phiBn is " << +hPhiBn << "\n";
	  	#endif
  	#endif
}


template<unsigned int nOMems >
void InputRouter( const BXType bx
	, const ap_uint<kLINKMAPwidth> hLinkWord
	, const ap_uint<kBINMAPwidth> hPhBnWord 
	, ap_uint<kNBits_DTC>* hInputStubs
	, hls::stream<InputStub<BARRELPS> > &hOutputStubs_0
	, hls::stream<InputStub<BARRELPS> > &hOutputStubs_1)
{
	
#pragma HLS inline

	ap_uint<1> hIs2S= hLinkWord.range(kLINKMAPwidth-4,kLINKMAPwidth-4);
	#ifndef __SYNTHESIS__
		#if IR_DEBUG
			std::cout << "Nmemories is " << nOMems << "\n";
		#endif
    #endif
     
	// count memories 
	unsigned int nMems=0;
	unsigned int nMemsPerLyr[kMaxLyrsPerDTC]; 
	CountMemories<kMaxLyrsPerDTC>(hPhBnWord, nMems, nMemsPerLyr);
	// clear stub counters
	ap_uint<kNBits_MemAddr> hNStubs[nOMems];
	ClearCounters<nOMems>(hNStubs);

	LOOP_ProcessIR:
	for (int cStubCounter = 0; cStubCounter < kMaxProc; cStubCounter++) 
	{
#pragma HLS pipeline II = 1 rewind
	  // decode stub
	  auto hStub = hInputStubs[cStubCounter];
	  // add check of valid bit here 
	  if (hStub == 0)   continue;
	  // check valid bit
	  auto hVldBt = hStub.range( kMSBVldBt ,  kLSBVldBt);
	  if( hVldBt == 0 ){ 
#ifndef __SYNTHESIS__
#if IR_DEBUG
	    edm::LogWarning("L1trackHLS") << "\t.. Invalid Stub : " << std::hex << hStub << std::dec << "\n";
#endif
#endif
	    continue;
	  }
	  // check which memory
	  // needs to be filled 
	  // encoded layer 
	  auto hEncLyr = hStub.range(kMSBLyrBts, kLSBLyrBts);
	  // get memory word
	  // discard LSBs
	  auto hStbWrd = ap_uint<kBRAMwidth>(hStub.range(kNBits_DTC - 1, kLyBitsSize + kVldBitSize));	
	  // old data format 
	  // discard MSBs
	  //auto hStbWrd = ap_uint<kBRAMwidth>(hStub.range(kBRAMwidth - 1, 0));
	  InputStub<BARRELPS> hMemWord(hStbWrd);
	    
	  // decode link wrd for this layer
	  auto hIsBrl= hLinkWord.range((kNBitsBrlBit-1) + kSizeLinkWord * hEncLyr, kSizeLinkWord * hEncLyr);
	  auto hLyrId= hLinkWord.range((kNBitsLyrTk-1) + kSizeLinkWord * hEncLyr + kNBitsBrlBit, kNBitsBrlBit + kSizeLinkWord * hEncLyr);
	  
	  // get phi bin
	  int cIndxThisBn = 0;
	  // for the barrel need to correct 
	  if( hIsBrl == 1 )
	  {
	  	if( hIs2S == 0 ) getCorrectedPhiBin<BARRELPS>(hStbWrd, hLyrId, cIndxThisBn);
	  	else getCorrectedPhiBin<BARREL2S>(hStbWrd, hLyrId, cIndxThisBn);
	  }
	  else
	  {
	  	if( hIs2S == 0 ) getPhiBin<DISKPS>( hStbWrd , kNbitsPhiBinsTkr , cIndxThisBn ) ;
	  	else getPhiBin<DISK2S>( hStbWrd , kNbitsPhiBinsTkr , cIndxThisBn ) ;
	  }
	  // get bin word 
	  // this stops you from filling a memory which isn't actually connected 
	  unsigned int hIsActive = hPhBnWord.range(kSizeBinWord * hEncLyr + cIndxThisBn, kSizeBinWord * hEncLyr + cIndxThisBn);
	  if( hIsActive == 0 ){ 
	  	#ifndef __SYNTHESIS__
	  		#if IR_DEBUG
	  			std::cout << "Bn#" << +cIndxThisBn << " connected to Lyr#" << hLyrId << " is not connected to this IR module\n" ; 
	 		#endif
	  	#endif
	  	continue; 
	  }

	  // update index
	  unsigned int cMemIndx = 0;
	  GetMemoryIndex<kMaxLyrsPerDTC>( hPhBnWord, hEncLyr, cIndxThisBn , cMemIndx);
	  
	  // assign memory index
	  assert(cMemIndx < nMems);
#ifndef __SYNTHESIS__
#if IR_DEBUG
	  edm::LogVerbatim("L1trackHLS") << "\t.. Stub : " << std::hex << hStub << std::dec 
		   				<< " rel. parts : " << std::hex << hStbWrd << std::dec
			            << " [ EncLyrId " << hEncLyr << " ] "
						<< "[ LyrId " << hLyrId << " ] "
			            << "[ IsBrl " << +hIsBrl << " ] "
						<< " [ Nmemories " << nMems << " ] "
			            << " [ IndxThisBn " << cMemIndx << " ] "
			            << "\n";
#endif
#endif
	  
	  // update  counters 
	  auto hEntries = hNStubs[cMemIndx];
	  hNStubs[cMemIndx] = hEntries + 1;
	  // fill memory 
          if (cMemIndx == 0)
            (&hOutputStubs_0)->write(hMemWord);
          else
            (&hOutputStubs_1)->write(hMemWord);
	}
}


#endif
