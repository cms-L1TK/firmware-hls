#include "InputRouterTop.h"

// barrel 2S input router 
// void InputRouterTopPS(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
// 				  InputStubMemory<BARRELPS>& hMemory_L1 ,InputStubMemory<BARRELPS>& hMemory_L2, InputStubMemory<BARRELPS>& hMemory_L3,
// 				  InputStubMemory<DISKPS>& hMemory_D1, InputStubMemory<DISKPS>& hMemory_D2, InputStubMemory<DISKPS>& hMemory_D3 , InputStubMemory<DISKPS>& hMemory_D4, InputStubMemory<DISKPS>& hMemory_D5 )
// {
// 	InputRouter<BARRELPS,DISKPS>(hDTCMapEncoded, bx, hIputLink,hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
// }

// // disk 2S input router 
// void InputRouterTop2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
// 				  InputStubMemory<BARREL2S>& hMemory_L1 ,InputStubMemory<BARREL2S>& hMemory_L2, InputStubMemory<BARREL2S>& hMemory_L3,
// 				  InputStubMemory<DISK2S>& hMemory_D1, InputStubMemory<DISK2S>& hMemory_D2, InputStubMemory<DISK2S>& hMemory_D3 , InputStubMemory<DISK2S>& hMemory_D4, InputStubMemory<DISK2S>& hMemory_D5 )
// {
// 	InputRouter<BARREL2S,DISK2S>(hDTCMapEncoded, bx, hIputLink, hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
// }

void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S)
{
	hIs2S  =  hDTCMapEncoded.range(kLINKMAPwidth-2,kLINKMAPwidth-2);
}
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst)
{
	hIsFirst  =  hDTCMapEncoded.range(kLINKMAPwidth-1,kLINKMAPwidth-1);
}

// now this could have all the possible memories 
void InputRouterGeneric(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink])
{
	
	ap_uint<1> cIsFirstLayer; isFirst(hDTCMapEncoded, cIsFirstLayer);
	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	#ifndef __SYNTHESIS__
	  std::cout << "\t.. First layer bit is set to " << +cIsFirstLayer << " ... 2S bit is set to " << +cIs2S << "\n";
	#endif
}


// generic input router 
void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
				  TFStubMemory &hMemory_L1 ,TFStubMemory &hMemory_L2, TFStubMemory &hMemory_L3,
				  TFStubMemory &hMemory_D1, TFStubMemory &hMemory_D2, TFStubMemory &hMemory_D3, TFStubMemory &hMemory_D4, TFStubMemory &hMemory_D5 )
{
	
	ap_uint<1> cIsFirstLayer; isFirst(hDTCMapEncoded, cIsFirstLayer);
	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	#ifndef __SYNTHESIS__
	  std::cout << "\t.. First layer bit is set to " << +cIsFirstLayer << " ... 2S bit is set to " << +cIs2S << "\n";
	#endif
	if( !cIs2S )
	{
		InputRouter<BARRELPS,DISKPS>(hDTCMapEncoded, bx, hIputLink,hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
	}
	else
	{
		InputRouter<BARREL2S,DISK2S>(hDTCMapEncoded, bx, hIputLink,hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
	}
}
