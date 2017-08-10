// VMRouter test bench
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
#include "VMRouter.hh"
#include "VMRouterDispatcher.hh"
#include "ap_int.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

void PrintRouted(HLSReducedStubLayer vmStubsPHXZX[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS], ReducedIndex nStubs[MAX_nROUTERS*MAX_nEVENTS], string outFileString)
{
  ReducedZ_Layer redZ;
  ReducedPhi_Layer redPhi;
  ReducedR_Layer redR;
  ReducedPt_Layer redPt;
  ReducedIndex redIndex;
  string strZ, strPhi, strR, strPt, strIndex;
  ofstream fout[MAX_nROUTERS];
  char curFile[128];
  string regionListFull[24] = {"L1D3","L2D3","L3D3","L4D3","L5D3","L6D3","L1D4","L2D4","L3D4","L4D4","L5D4","L6D4",
                               "L1D5","L2D5","L3D5","L4D5","L5D5","L6D5","L1D6","L2D6","L3D6","L4D6","L5D6","L6D6"};
  string regionList[MAX_nROUTERS];
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    regionList[i] = regionListFull[i];
  }
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    sprintf(curFile,"VMStubs_VMS_%s%sn1_03_new.dat", regionList[i].c_str(), outFileString.c_str());
    fout[i].open(curFile);
    char outString[128];
    int BXCode;
    string strBXCode;
    int nRouted = 0;
    stringstream stream;
    string strnRouted;
    for (int j=0; j<MAX_nEVENTS; j++)
    {
      BXCode = j%8;
      strBXCode = bitset<3>(BXCode).to_string();
      sprintf(outString,"BX = %s Event : %d\n",strBXCode.c_str(),j+1);
      fout[i] << outString;
      for (int k=0; k<nStubs[i + j*MAX_nROUTERS]; k++)
      {
        stream.str("");
        stream << setfill ('0') << setw(2) << hex << k;
        strnRouted = stream.str();
        redZ = vmStubsPHXZX[k + i*MAX_nSTUBS + j*MAX_nSTUBS*MAX_nROUTERS].GetZ();
        redPhi = vmStubsPHXZX[k + i*MAX_nSTUBS + j*MAX_nSTUBS*MAX_nROUTERS].GetPhi();
        redR = vmStubsPHXZX[k + i*MAX_nSTUBS + j*MAX_nSTUBS*MAX_nROUTERS].GetR();
        redPt = vmStubsPHXZX[k + i*MAX_nSTUBS + j*MAX_nSTUBS*MAX_nROUTERS].GetPt();
        redIndex = vmStubsPHXZX[k + i*MAX_nSTUBS + j*MAX_nSTUBS*MAX_nROUTERS].GetIndex();
        strZ = bitset<4>(redZ.to_int()).to_string().c_str();
        strIndex = bitset<6>(redIndex.to_int()).to_string().c_str();
        strPhi = bitset<3>(redPhi.to_int()).to_string().c_str();
        strR = bitset<2>(redR.to_int()).to_string().c_str();
        strPt = bitset<3>(redPt.to_int()).to_string().c_str();
        sprintf(outString,"%s %s|%s|%s|%s|%s\n", strnRouted.c_str(), strPt.c_str(), strIndex.c_str(), strZ.c_str(), strPhi.c_str(), strR.c_str());
        fout[i] << outString;
      }
    }
  }
}

int main()
{
  // ****** DECLARE ALL ARRAY VARIABLES ******
  HLSFullStubLayerPS stubsInLayer[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSFullStubLayerPS allStubs[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH1Z1[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH2Z1[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH3Z1[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH4Z1[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH1Z2[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH2Z2[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH3Z2[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH4Z2[MAX_nSTUBS*MAX_nROUTERS*MAX_nEVENTS];

  HLSFullStubLayerPS curStubsInLayer_1[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_1[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_1[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_2[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_2[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_2[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_3[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_3[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_3[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_4[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_4[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_4[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_5[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_5[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_5[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_6[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_6[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_6[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_7[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_7[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_7[MAX_nSTUBS];
  HLSFullStubLayerPS curStubsInLayer_8[MAX_nSTUBS];
  HLSFullStubLayerPS curAllStubs_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z1_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z1_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z1_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z1_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH1Z2_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH2Z2_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH3Z2_8[MAX_nSTUBS];
  HLSReducedStubLayer curvmStubsPH4Z2_8[MAX_nSTUBS];

  ReducedIndex nPH1Z1[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH2Z1[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH3Z1[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH4Z1[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH1Z2[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH2Z2[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH3Z2[MAX_nROUTERS*MAX_nEVENTS];
  ReducedIndex nPH4Z2[MAX_nROUTERS*MAX_nEVENTS];
  for (int i=0; i<MAX_nROUTERS*MAX_nEVENTS; i++)
  {
    nPH1Z1[i] = 0;
    nPH2Z1[i] = 0;
    nPH3Z1[i] = 0;
    nPH4Z1[i] = 0;
    nPH1Z2[i] = 0;
    nPH2Z2[i] = 0;
    nPH3Z2[i] = 0;
    nPH4Z2[i] = 0;
  }

  ReducedIndex curnPH1Z1_1 = 0;
  ReducedIndex curnPH2Z1_1 = 0;
  ReducedIndex curnPH3Z1_1 = 0;
  ReducedIndex curnPH4Z1_1 = 0;
  ReducedIndex curnPH1Z2_1 = 0;
  ReducedIndex curnPH2Z2_1 = 0;
  ReducedIndex curnPH3Z2_1 = 0;
  ReducedIndex curnPH4Z2_1 = 0;
  ReducedIndex curnPH1Z1_2 = 0;
  ReducedIndex curnPH2Z1_2 = 0;
  ReducedIndex curnPH3Z1_2 = 0;
  ReducedIndex curnPH4Z1_2 = 0;
  ReducedIndex curnPH1Z2_2 = 0;
  ReducedIndex curnPH2Z2_2 = 0;
  ReducedIndex curnPH3Z2_2 = 0;
  ReducedIndex curnPH4Z2_2 = 0;
  ReducedIndex curnPH1Z1_3 = 0;
  ReducedIndex curnPH2Z1_3 = 0;
  ReducedIndex curnPH3Z1_3 = 0;
  ReducedIndex curnPH4Z1_3 = 0;
  ReducedIndex curnPH1Z2_3 = 0;
  ReducedIndex curnPH2Z2_3 = 0;
  ReducedIndex curnPH3Z2_3 = 0;
  ReducedIndex curnPH4Z2_3 = 0;
  ReducedIndex curnPH1Z1_4 = 0;
  ReducedIndex curnPH2Z1_4 = 0;
  ReducedIndex curnPH3Z1_4 = 0;
  ReducedIndex curnPH4Z1_4 = 0;
  ReducedIndex curnPH1Z2_4 = 0;
  ReducedIndex curnPH2Z2_4 = 0;
  ReducedIndex curnPH3Z2_4 = 0;
  ReducedIndex curnPH4Z2_4 = 0;
  ReducedIndex curnPH1Z1_5 = 0;
  ReducedIndex curnPH2Z1_5 = 0;
  ReducedIndex curnPH3Z1_5 = 0;
  ReducedIndex curnPH4Z1_5 = 0;
  ReducedIndex curnPH1Z2_5 = 0;
  ReducedIndex curnPH2Z2_5 = 0;
  ReducedIndex curnPH3Z2_5 = 0;
  ReducedIndex curnPH4Z2_5 = 0;
  ReducedIndex curnPH1Z1_6 = 0;
  ReducedIndex curnPH2Z1_6 = 0;
  ReducedIndex curnPH3Z1_6 = 0;
  ReducedIndex curnPH4Z1_6 = 0;
  ReducedIndex curnPH1Z2_6 = 0;
  ReducedIndex curnPH2Z2_6 = 0;
  ReducedIndex curnPH3Z2_6 = 0;
  ReducedIndex curnPH4Z2_6 = 0;
  ReducedIndex curnPH1Z1_7 = 0;
  ReducedIndex curnPH2Z1_7 = 0;
  ReducedIndex curnPH3Z1_7 = 0;
  ReducedIndex curnPH4Z1_7 = 0;
  ReducedIndex curnPH1Z2_7 = 0;
  ReducedIndex curnPH2Z2_7 = 0;
  ReducedIndex curnPH3Z2_7 = 0;
  ReducedIndex curnPH4Z2_7 = 0;
  ReducedIndex curnPH1Z1_8 = 0;
  ReducedIndex curnPH2Z1_8 = 0;
  ReducedIndex curnPH3Z1_8 = 0;
  ReducedIndex curnPH4Z1_8 = 0;
  ReducedIndex curnPH1Z2_8 = 0;
  ReducedIndex curnPH2Z2_8 = 0;
  ReducedIndex curnPH3Z2_8 = 0;
  ReducedIndex curnPH4Z2_8 = 0;

  int nStubs[MAX_nROUTERS*MAX_nEVENTS];

  FullZ_Layer_PS inZ;
  FullPhi_Layer_PS inPhi;
  FullR_Layer_PS inR;
  FullPt_Layer_PS inPt;

  FullZ_Layer_PS allZ;
  FullPhi_Layer_PS allPhi;
  FullR_Layer_PS allR;
  FullPt_Layer_PS allPt;



  // ****** READ IN DATA FOR ALL EVENTS AND DETECTOR REGIONS ******
  ifstream fin[MAX_nROUTERS];
  char curFile[128];
  string regionListFull[24] = {"L1D3","L2D3","L3D3","L4D3","L5D3","L6D3","L1D4","L2D4","L3D4","L4D4","L5D4","L6D4",
                               "L1D5","L2D5","L3D5","L4D5","L5D5","L6D5","L1D6","L2D6","L3D6","L4D6","L5D6","L6D6"};
  string regionList[MAX_nROUTERS];
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    regionList[i] = regionListFull[i];
  }
  string token;
  int curEvent;
  int curStub = 0;
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    curEvent = 0;
    sprintf(curFile,"emData/LayerStubs_SL1_%s_03.dat",regionList[i].c_str());
    fin[i].open(curFile);
    if ( ! fin[i] ) {
    	char cwd[1024]; getcwd(cwd, 1024);
    	std::cerr << "Problem opening file " << curFile
    			  << ": " << strerror(errno) << "," << std::endl
				  << "in directory " << cwd
    			  << std::endl;
    	std::cerr << "Aborting test." << std::endl;
    	return -1;
    }
    getline(fin[i],token);
    while (getline(fin[i],token,' '))
    {
      if (token[0] == 'B')
      {
        nStubs[i+curEvent*MAX_nROUTERS] = curStub;
        curStub = 0;
        curEvent ++;
        getline(fin[i],token);
      }
      else
      {
        getline(fin[i],token,'|');
        inPt.set_VAL(strtol(token.c_str(),NULL,2));
        getline(fin[i],token,'|');
        inR.set_VAL(strtol(token.c_str(),NULL,2));
        getline(fin[i],token,'|');
        inZ.set_VAL(strtol(token.c_str(),NULL,2));
        getline(fin[i],token,'\n');
        inPhi.set_VAL(strtol(token.c_str(),NULL,2));
        stubsInLayer[curStub + i*MAX_nSTUBS + curEvent*MAX_nSTUBS*MAX_nROUTERS].AddStub(inZ, inPhi, inR, inPt);
        curStub++;
      }
    }
    fin[i].close();
  }



  // ****** LOOP OVER ALL EVENTS, SENDING EACH EVENT TO VMROUTERDISPATCHER ******
  int curnStubs_1;
  int curnStubs_2;
  int curnStubs_3;
  int curnStubs_4;
  int curnStubs_5;
  int curnStubs_6;
  int curnStubs_7;
  int curnStubs_8;
  for (int i=0; i<MAX_nEVENTS; i++)
  {
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS,curStubsInLayer_1);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS,curStubsInLayer_2);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS,curStubsInLayer_3);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS,curStubsInLayer_4);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS,curStubsInLayer_5);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS,curStubsInLayer_6);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS,curStubsInLayer_7);
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS, stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS + 8*MAX_nSTUBS,curStubsInLayer_8);

    curnStubs_1 = nStubs[i*MAX_nROUTERS + 0];
    curnStubs_2 = nStubs[i*MAX_nROUTERS + 1];
    curnStubs_3 = nStubs[i*MAX_nROUTERS + 2];
    curnStubs_4 = nStubs[i*MAX_nROUTERS + 3];
    curnStubs_5 = nStubs[i*MAX_nROUTERS + 4];
    curnStubs_6 = nStubs[i*MAX_nROUTERS + 5];
    curnStubs_7 = nStubs[i*MAX_nROUTERS + 6];
    curnStubs_8 = nStubs[i*MAX_nROUTERS + 7];

    VMRouterDispatcher(curStubsInLayer_1, curStubsInLayer_2, curStubsInLayer_3, curStubsInLayer_4,
                       curStubsInLayer_5, curStubsInLayer_6, curStubsInLayer_7, curStubsInLayer_8,
		       curAllStubs_1, curAllStubs_2, curAllStubs_3, curAllStubs_4,
		       curAllStubs_5, curAllStubs_6, curAllStubs_7, curAllStubs_8,
		       curvmStubsPH1Z1_1, curvmStubsPH1Z1_2, curvmStubsPH1Z1_3, curvmStubsPH1Z1_4,
		       curvmStubsPH1Z1_5, curvmStubsPH1Z1_6, curvmStubsPH1Z1_7, curvmStubsPH1Z1_8,
		       curvmStubsPH2Z1_1, curvmStubsPH2Z1_2, curvmStubsPH2Z1_3, curvmStubsPH2Z1_4,
       		       curvmStubsPH2Z1_5, curvmStubsPH2Z1_6, curvmStubsPH2Z1_7, curvmStubsPH2Z1_8,
		       curvmStubsPH3Z1_1, curvmStubsPH3Z1_2, curvmStubsPH3Z1_3, curvmStubsPH3Z1_4,
       		       curvmStubsPH3Z1_5, curvmStubsPH3Z1_6, curvmStubsPH3Z1_7, curvmStubsPH3Z1_8,
		       curvmStubsPH4Z1_1, curvmStubsPH4Z1_2, curvmStubsPH4Z1_3, curvmStubsPH4Z1_4,
       		       curvmStubsPH4Z1_5, curvmStubsPH4Z1_6, curvmStubsPH4Z1_7, curvmStubsPH4Z1_8,
		       curvmStubsPH1Z2_1, curvmStubsPH1Z2_2, curvmStubsPH1Z2_3, curvmStubsPH1Z2_4,
       		       curvmStubsPH1Z2_5, curvmStubsPH1Z2_6, curvmStubsPH1Z2_7, curvmStubsPH1Z2_8,
		       curvmStubsPH2Z2_1, curvmStubsPH2Z2_2, curvmStubsPH2Z2_3, curvmStubsPH2Z2_4,
       		       curvmStubsPH2Z2_5, curvmStubsPH2Z2_6, curvmStubsPH2Z2_7, curvmStubsPH2Z2_8,
		       curvmStubsPH3Z2_1, curvmStubsPH3Z2_2, curvmStubsPH3Z2_3, curvmStubsPH3Z2_4,
       		       curvmStubsPH3Z2_5, curvmStubsPH3Z2_6, curvmStubsPH3Z2_7, curvmStubsPH3Z2_8,
		       curvmStubsPH4Z2_1, curvmStubsPH4Z2_2, curvmStubsPH4Z2_3, curvmStubsPH4Z2_4,
       		       curvmStubsPH4Z2_5, curvmStubsPH4Z2_6, curvmStubsPH4Z2_7, curvmStubsPH4Z2_8,
		       curnStubs_1, curnStubs_2, curnStubs_3, curnStubs_4,
		       curnStubs_5, curnStubs_6, curnStubs_7, curnStubs_8,
		       &curnPH1Z1_1, &curnPH1Z1_2, &curnPH1Z1_3, &curnPH1Z1_4,
		       &curnPH1Z1_5, &curnPH1Z1_6, &curnPH1Z1_7, &curnPH1Z1_8,
		       &curnPH2Z1_1, &curnPH2Z1_2, &curnPH2Z1_3, &curnPH2Z1_4,
       		       &curnPH2Z1_5, &curnPH2Z1_6, &curnPH2Z1_7, &curnPH2Z1_8,
		       &curnPH3Z1_1, &curnPH3Z1_2, &curnPH3Z1_3, &curnPH3Z1_4,
       		       &curnPH3Z1_5, &curnPH3Z1_6, &curnPH3Z1_7, &curnPH3Z1_8,
		       &curnPH4Z1_1, &curnPH4Z1_2, &curnPH4Z1_3, &curnPH4Z1_4,
       		       &curnPH4Z1_5, &curnPH4Z1_6, &curnPH4Z1_7, &curnPH4Z1_8,
		       &curnPH1Z2_1, &curnPH1Z2_2, &curnPH1Z2_3, &curnPH1Z2_4,
       		       &curnPH1Z2_5, &curnPH1Z2_6, &curnPH1Z2_7, &curnPH1Z2_8,
		       &curnPH2Z2_1, &curnPH2Z2_2, &curnPH2Z2_3, &curnPH2Z2_4,
       		       &curnPH2Z2_5, &curnPH2Z2_6, &curnPH2Z2_7, &curnPH2Z2_8,
		       &curnPH3Z2_1, &curnPH3Z2_2, &curnPH3Z2_3, &curnPH3Z2_4,
       		       &curnPH3Z2_5, &curnPH3Z2_6, &curnPH3Z2_7, &curnPH3Z2_8,
		       &curnPH4Z2_1, &curnPH4Z2_2, &curnPH4Z2_3, &curnPH4Z2_4,
       		       &curnPH4Z2_5, &curnPH4Z2_6, &curnPH4Z2_7, &curnPH4Z2_8);

    copy(curAllStubs_1, curAllStubs_1 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curAllStubs_2, curAllStubs_2 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curAllStubs_3, curAllStubs_3 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curAllStubs_4, curAllStubs_4 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curAllStubs_5, curAllStubs_5 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curAllStubs_6, curAllStubs_6 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curAllStubs_7, curAllStubs_7 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curAllStubs_8, curAllStubs_8 + MAX_nSTUBS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH1Z1_1, curvmStubsPH1Z1_1 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_2, curvmStubsPH1Z1_2 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_3, curvmStubsPH1Z1_3 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_4, curvmStubsPH1Z1_4 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_5, curvmStubsPH1Z1_5 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_6, curvmStubsPH1Z1_6 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_7, curvmStubsPH1Z1_7 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH1Z1_8, curvmStubsPH1Z1_8 + MAX_nSTUBS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    //printf("curvmStubsPH1Z1_1: %d\n", curvmStubsPH1Z1_1[1].GetIndex().to_int());

    copy(curvmStubsPH2Z1_1, curvmStubsPH2Z1_1 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_2, curvmStubsPH2Z1_2 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_3, curvmStubsPH2Z1_3 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_4, curvmStubsPH2Z1_4 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_5, curvmStubsPH2Z1_5 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_6, curvmStubsPH2Z1_6 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_7, curvmStubsPH2Z1_7 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH2Z1_8, curvmStubsPH2Z1_8 + MAX_nSTUBS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH3Z1_1, curvmStubsPH3Z1_1 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_2, curvmStubsPH3Z1_2 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_3, curvmStubsPH3Z1_3 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_4, curvmStubsPH3Z1_4 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_5, curvmStubsPH3Z1_5 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_6, curvmStubsPH3Z1_6 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_7, curvmStubsPH3Z1_7 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH3Z1_8, curvmStubsPH3Z1_8 + MAX_nSTUBS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH4Z1_1, curvmStubsPH4Z1_1 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_2, curvmStubsPH4Z1_2 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_3, curvmStubsPH4Z1_3 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_4, curvmStubsPH4Z1_4 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_5, curvmStubsPH4Z1_5 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_6, curvmStubsPH4Z1_6 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_7, curvmStubsPH4Z1_7 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH4Z1_8, curvmStubsPH4Z1_8 + MAX_nSTUBS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH1Z2_1, curvmStubsPH1Z2_1 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_2, curvmStubsPH1Z2_2 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_3, curvmStubsPH1Z2_3 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_4, curvmStubsPH1Z2_4 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_5, curvmStubsPH1Z2_5 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_6, curvmStubsPH1Z2_6 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_7, curvmStubsPH1Z2_7 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH1Z2_8, curvmStubsPH1Z2_8 + MAX_nSTUBS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH2Z2_1, curvmStubsPH2Z2_1 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_2, curvmStubsPH2Z2_2 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_3, curvmStubsPH2Z2_3 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_4, curvmStubsPH2Z2_4 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_5, curvmStubsPH2Z2_5 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_6, curvmStubsPH2Z2_6 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_7, curvmStubsPH2Z2_7 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH2Z2_8, curvmStubsPH2Z2_8 + MAX_nSTUBS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH3Z2_1, curvmStubsPH3Z2_1 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_2, curvmStubsPH3Z2_2 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_3, curvmStubsPH3Z2_3 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_4, curvmStubsPH3Z2_4 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_5, curvmStubsPH3Z2_5 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_6, curvmStubsPH3Z2_6 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_7, curvmStubsPH3Z2_7 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH3Z2_8, curvmStubsPH3Z2_8 + MAX_nSTUBS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    copy(curvmStubsPH4Z2_1, curvmStubsPH4Z2_1 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 0*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_2, curvmStubsPH4Z2_2 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 1*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_3, curvmStubsPH4Z2_3 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 2*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_4, curvmStubsPH4Z2_4 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 3*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_5, curvmStubsPH4Z2_5 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 4*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_6, curvmStubsPH4Z2_6 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 5*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_7, curvmStubsPH4Z2_7 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 6*MAX_nSTUBS);
    copy(curvmStubsPH4Z2_8, curvmStubsPH4Z2_8 + MAX_nSTUBS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS + 7*MAX_nSTUBS);

    //printf("curnPH1Z1_1: %d\n", curnPH1Z1_1.to_int());
    nPH1Z1[i*MAX_nROUTERS + 0] = curnPH1Z1_1;
    nPH1Z1[i*MAX_nROUTERS + 1] = curnPH1Z1_2;
    nPH1Z1[i*MAX_nROUTERS + 2] = curnPH1Z1_3;
    nPH1Z1[i*MAX_nROUTERS + 3] = curnPH1Z1_4;
    nPH1Z1[i*MAX_nROUTERS + 4] = curnPH1Z1_5;
    nPH1Z1[i*MAX_nROUTERS + 5] = curnPH1Z1_6;
    nPH1Z1[i*MAX_nROUTERS + 6] = curnPH1Z1_7;
    nPH1Z1[i*MAX_nROUTERS + 7] = curnPH1Z1_8;

    nPH2Z1[i*MAX_nROUTERS + 0] = curnPH2Z1_1;
    nPH2Z1[i*MAX_nROUTERS + 1] = curnPH2Z1_2;
    nPH2Z1[i*MAX_nROUTERS + 2] = curnPH2Z1_3;
    nPH2Z1[i*MAX_nROUTERS + 3] = curnPH2Z1_4;
    nPH2Z1[i*MAX_nROUTERS + 4] = curnPH2Z1_5;
    nPH2Z1[i*MAX_nROUTERS + 5] = curnPH2Z1_6;
    nPH2Z1[i*MAX_nROUTERS + 6] = curnPH2Z1_7;
    nPH2Z1[i*MAX_nROUTERS + 7] = curnPH2Z1_8;

    nPH3Z1[i*MAX_nROUTERS + 0] = curnPH3Z1_1;
    nPH3Z1[i*MAX_nROUTERS + 1] = curnPH3Z1_2;
    nPH3Z1[i*MAX_nROUTERS + 2] = curnPH3Z1_3;
    nPH3Z1[i*MAX_nROUTERS + 3] = curnPH3Z1_4;
    nPH3Z1[i*MAX_nROUTERS + 4] = curnPH3Z1_5;
    nPH3Z1[i*MAX_nROUTERS + 5] = curnPH3Z1_6;
    nPH3Z1[i*MAX_nROUTERS + 6] = curnPH3Z1_7;
    nPH3Z1[i*MAX_nROUTERS + 7] = curnPH3Z1_8;

    nPH4Z1[i*MAX_nROUTERS + 0] = curnPH4Z1_1;
    nPH4Z1[i*MAX_nROUTERS + 1] = curnPH4Z1_2;
    nPH4Z1[i*MAX_nROUTERS + 2] = curnPH4Z1_3;
    nPH4Z1[i*MAX_nROUTERS + 3] = curnPH4Z1_4;
    nPH4Z1[i*MAX_nROUTERS + 4] = curnPH4Z1_5;
    nPH4Z1[i*MAX_nROUTERS + 5] = curnPH4Z1_6;
    nPH4Z1[i*MAX_nROUTERS + 6] = curnPH4Z1_7;
    nPH4Z1[i*MAX_nROUTERS + 7] = curnPH4Z1_8;

    nPH1Z2[i*MAX_nROUTERS + 0] = curnPH1Z2_1;
    nPH1Z2[i*MAX_nROUTERS + 1] = curnPH1Z2_2;
    nPH1Z2[i*MAX_nROUTERS + 2] = curnPH1Z2_3;
    nPH1Z2[i*MAX_nROUTERS + 3] = curnPH1Z2_4;
    nPH1Z2[i*MAX_nROUTERS + 4] = curnPH1Z2_5;
    nPH1Z2[i*MAX_nROUTERS + 5] = curnPH1Z2_6;
    nPH1Z2[i*MAX_nROUTERS + 6] = curnPH1Z2_7;
    nPH1Z2[i*MAX_nROUTERS + 7] = curnPH1Z2_8;

    nPH2Z2[i*MAX_nROUTERS + 0] = curnPH2Z2_1;
    nPH2Z2[i*MAX_nROUTERS + 1] = curnPH2Z2_2;
    nPH2Z2[i*MAX_nROUTERS + 2] = curnPH2Z2_3;
    nPH2Z2[i*MAX_nROUTERS + 3] = curnPH2Z2_4;
    nPH2Z2[i*MAX_nROUTERS + 4] = curnPH2Z2_5;
    nPH2Z2[i*MAX_nROUTERS + 5] = curnPH2Z2_6;
    nPH2Z2[i*MAX_nROUTERS + 6] = curnPH2Z2_7;
    nPH2Z2[i*MAX_nROUTERS + 7] = curnPH2Z2_8;

    nPH3Z2[i*MAX_nROUTERS + 0] = curnPH3Z2_1;
    nPH3Z2[i*MAX_nROUTERS + 1] = curnPH3Z2_2;
    nPH3Z2[i*MAX_nROUTERS + 2] = curnPH3Z2_3;
    nPH3Z2[i*MAX_nROUTERS + 3] = curnPH3Z2_4;
    nPH3Z2[i*MAX_nROUTERS + 4] = curnPH3Z2_5;
    nPH3Z2[i*MAX_nROUTERS + 5] = curnPH3Z2_6;
    nPH3Z2[i*MAX_nROUTERS + 6] = curnPH3Z2_7;
    nPH3Z2[i*MAX_nROUTERS + 7] = curnPH3Z2_8;

    nPH4Z2[i*MAX_nROUTERS + 0] = curnPH4Z2_1;
    nPH4Z2[i*MAX_nROUTERS + 1] = curnPH4Z2_2;
    nPH4Z2[i*MAX_nROUTERS + 2] = curnPH4Z2_3;
    nPH4Z2[i*MAX_nROUTERS + 3] = curnPH4Z2_4;
    nPH4Z2[i*MAX_nROUTERS + 4] = curnPH4Z2_5;
    nPH4Z2[i*MAX_nROUTERS + 5] = curnPH4Z2_6;
    nPH4Z2[i*MAX_nROUTERS + 6] = curnPH4Z2_7;
    nPH4Z2[i*MAX_nROUTERS + 7] = curnPH4Z2_8;

    curnPH1Z1_1 = 0;
    curnPH1Z1_2 = 0;
    curnPH1Z1_3 = 0;
    curnPH1Z1_4 = 0;
    curnPH1Z1_5 = 0;
    curnPH1Z1_6 = 0;
    curnPH1Z1_7 = 0;
    curnPH1Z1_8 = 0;

    curnPH2Z1_1 = 0;
    curnPH2Z1_2 = 0;
    curnPH2Z1_3 = 0;
    curnPH2Z1_4 = 0;
    curnPH2Z1_5 = 0;
    curnPH2Z1_6 = 0;
    curnPH2Z1_7 = 0;
    curnPH2Z1_8 = 0;

    curnPH3Z1_1 = 0;
    curnPH3Z1_2 = 0;
    curnPH3Z1_3 = 0;
    curnPH3Z1_4 = 0;
    curnPH3Z1_5 = 0;
    curnPH3Z1_6 = 0;
    curnPH3Z1_7 = 0;
    curnPH3Z1_8 = 0;

    curnPH4Z1_1 = 0;
    curnPH4Z1_2 = 0;
    curnPH4Z1_3 = 0;
    curnPH4Z1_4 = 0;
    curnPH4Z1_5 = 0;
    curnPH4Z1_6 = 0;
    curnPH4Z1_7 = 0;
    curnPH4Z1_8 = 0;

    curnPH1Z2_1 = 0;
    curnPH1Z2_2 = 0;
    curnPH1Z2_3 = 0;
    curnPH1Z2_4 = 0;
    curnPH1Z2_5 = 0;
    curnPH1Z2_6 = 0;
    curnPH1Z2_7 = 0;
    curnPH1Z2_8 = 0;

    curnPH2Z2_1 = 0;
    curnPH2Z2_2 = 0;
    curnPH2Z2_3 = 0;
    curnPH2Z2_4 = 0;
    curnPH2Z2_5 = 0;
    curnPH2Z2_6 = 0;
    curnPH2Z2_7 = 0;
    curnPH2Z2_8 = 0;

    curnPH3Z2_1 = 0;
    curnPH3Z2_2 = 0;
    curnPH3Z2_3 = 0;
    curnPH3Z2_4 = 0;
    curnPH3Z2_5 = 0;
    curnPH3Z2_6 = 0;
    curnPH3Z2_7 = 0;
    curnPH3Z2_8 = 0;

    curnPH4Z2_1 = 0;
    curnPH4Z2_2 = 0;
    curnPH4Z2_3 = 0;
    curnPH4Z2_4 = 0;
    curnPH4Z2_5 = 0;
    curnPH4Z2_6 = 0;
    curnPH4Z2_7 = 0;
    curnPH4Z2_8 = 0;
  }



  // ****** WRITE OUT ALL THE ROUTED STUBS TO THE APPROPRIATE FILES ******
  //printf("vmStubsPH1Z1: %d\n", vmStubsPH1Z1[1].GetIndex().to_int());
  //printf("nPH2Z1: %d\n", nPH2Z1[0].to_int());
  PrintRouted(vmStubsPH1Z1,nPH1Z1,"PHI1X1");
  PrintRouted(vmStubsPH2Z1,nPH2Z1,"PHI2X1");
  PrintRouted(vmStubsPH3Z1,nPH3Z1,"PHI3X1");
  PrintRouted(vmStubsPH4Z1,nPH4Z1,"PHI4X1");
  PrintRouted(vmStubsPH1Z2,nPH1Z2,"PHI1X2");
  PrintRouted(vmStubsPH2Z2,nPH2Z2,"PHI2X2");
  PrintRouted(vmStubsPH3Z2,nPH3Z2,"PHI3X2");
  PrintRouted(vmStubsPH4Z2,nPH4Z2,"PHI4X2");



  // ****** COMPARE ALL OUTPUT FILES TO THE OUTPUT FILES FROM THE EMULATOR ******
  int allPass = 0;
  string routeList[8] = {"PHI1X1", "PHI2X1", "PHI3X1", "PHI4X1", "PHI1X2", "PHI2X2", "PHI3X2", "PHI4X2"};
  char curCommand[128];
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    for (int j=0; j<8; j++)
    {
      sprintf(curCommand,"diff  -s emData/VMStubs_VMS_%s%sn1_03.dat VMStubs_VMS_%s%sn1_03_new.dat", regionList[i].c_str(), routeList[j].c_str(), regionList[i].c_str(), routeList[j].c_str());
      if (system(curCommand)) {
    	  allPass = i*8+j;
      }
    }
  }
  return allPass;

}




