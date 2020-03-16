#include "InputRouterTop.h"

// barrel 2S input router 
void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
				  InputStubMemory<BARRELPS>& hMemory_L1 ,InputStubMemory<BARRELPS>& hMemory_L2, InputStubMemory<BARRELPS>& hMemory_L3,
				  InputStubMemory<DISKPS>& hMemory_D1, InputStubMemory<DISKPS>& hMemory_D2, InputStubMemory<DISKPS>& hMemory_D3 , InputStubMemory<DISKPS>& hMemory_D4, InputStubMemory<DISKPS>& hMemory_D5 )
{
	InputRouter<BARRELPS,DISKPS>(hDTCMapEncoded, bx, hIputLink,hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
}

// disk 2S input router 
void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
				  InputStubMemory<BARREL2S>& hMemory_L1 ,InputStubMemory<BARREL2S>& hMemory_L2, InputStubMemory<BARREL2S>& hMemory_L3,
				  InputStubMemory<DISK2S>& hMemory_D1, InputStubMemory<DISK2S>& hMemory_D2, InputStubMemory<DISK2S>& hMemory_D3 , InputStubMemory<DISK2S>& hMemory_D4, InputStubMemory<DISK2S>& hMemory_D5 )
{
	InputRouter<BARREL2S,DISK2S>(hDTCMapEncoded, bx, hIputLink, hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
}