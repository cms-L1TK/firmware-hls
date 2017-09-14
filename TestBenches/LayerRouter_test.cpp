
#include <cstdio>
#include <iostream>
#include "LayerRouter.hh"

int main()
{
  HLSFullStubLayerPS inData[MAX_nSTUBS];
  // HLSFullStubLayerPS outData1[MAX_nSTUBS];
  // HLSFullStubLayerPS outData2[MAX_nSTUBS];
  // HLSFullStubLayerPS outData3[MAX_nSTUBS];
  // HLSFullStubLayerPS outData4[MAX_nSTUBS];
  // HLSFullStubLayerPS outData5[MAX_nSTUBS];
  // HLSFullStubLayerPS outData6[MAX_nSTUBS];
  
  HLSFullStubLayerPS outDatas[6][MAX_nSTUBS];

  // = { outData1, outData2, outData3, outData4, 
  // 			    outData5, outData6}; 
  int nevts = 10;
  for (int i = 0; i < nevts; ++i ) {
    LayerRouter(inData, outDatas);
  }

  return 0;
}
