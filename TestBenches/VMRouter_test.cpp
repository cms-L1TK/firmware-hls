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

  HLSFullStubLayerPS curStubsInLayer[MAX_nSTUBS*MAX_nROUTERS];
  HLSFullStubLayerPS curAllStubs[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH1Z1[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH2Z1[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH3Z1[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH4Z1[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH1Z2[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH2Z2[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH3Z2[MAX_nSTUBS*MAX_nROUTERS];
  HLSReducedStubLayer curvmStubsPH4Z2[MAX_nSTUBS*MAX_nROUTERS];

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

  ReducedIndex curnPH1Z1[MAX_nROUTERS];
  ReducedIndex curnPH2Z1[MAX_nROUTERS];
  ReducedIndex curnPH3Z1[MAX_nROUTERS];
  ReducedIndex curnPH4Z1[MAX_nROUTERS];
  ReducedIndex curnPH1Z2[MAX_nROUTERS];
  ReducedIndex curnPH2Z2[MAX_nROUTERS];
  ReducedIndex curnPH3Z2[MAX_nROUTERS];
  ReducedIndex curnPH4Z2[MAX_nROUTERS];
  for (int i=0; i<MAX_nROUTERS; i++)
  {
    curnPH1Z1[i] = 0;
    curnPH2Z1[i] = 0;
    curnPH3Z1[i] = 0;
    curnPH4Z1[i] = 0;
    curnPH1Z2[i] = 0;
    curnPH2Z2[i] = 0;
    curnPH3Z2[i] = 0;
    curnPH4Z2[i] = 0;
  }

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
  int curnStubs[MAX_nROUTERS];
  for (int i=0; i<MAX_nEVENTS; i++)
  {
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nROUTERS, stubsInLayer + (i+1)*MAX_nSTUBS*MAX_nROUTERS,curStubsInLayer);
    copy(nStubs + i*MAX_nROUTERS, nStubs + (i+1)*MAX_nROUTERS, curnStubs);
    VMRouterDispatcher(curStubsInLayer, curAllStubs,
           curvmStubsPH1Z1, curvmStubsPH2Z1,
           curvmStubsPH3Z1, curvmStubsPH4Z1,
           curvmStubsPH1Z2, curvmStubsPH2Z2,
           curvmStubsPH3Z2, curvmStubsPH4Z2,
           curnStubs,
           curnPH1Z1, curnPH2Z1,
           curnPH3Z1, curnPH4Z1,
           curnPH1Z2, curnPH2Z2,
           curnPH3Z2, curnPH4Z2);
    copy(curAllStubs, curAllStubs + MAX_nSTUBS*MAX_nROUTERS, allStubs + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH1Z1, curvmStubsPH1Z1 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH2Z1, curvmStubsPH2Z1 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH3Z1, curvmStubsPH3Z1 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH4Z1, curvmStubsPH4Z1 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH1Z2, curvmStubsPH1Z2 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH2Z2, curvmStubsPH2Z2 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH3Z2, curvmStubsPH3Z2 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curvmStubsPH4Z2, curvmStubsPH4Z2 + MAX_nSTUBS*MAX_nROUTERS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nROUTERS);
    copy(curnPH1Z1, curnPH1Z1 + MAX_nROUTERS, nPH1Z1 + i*MAX_nROUTERS);
    copy(curnPH2Z1, curnPH2Z1 + MAX_nROUTERS, nPH2Z1 + i*MAX_nROUTERS);
    copy(curnPH3Z1, curnPH3Z1 + MAX_nROUTERS, nPH3Z1 + i*MAX_nROUTERS);
    copy(curnPH4Z1, curnPH4Z1 + MAX_nROUTERS, nPH4Z1 + i*MAX_nROUTERS);
    copy(curnPH1Z2, curnPH1Z2 + MAX_nROUTERS, nPH1Z2 + i*MAX_nROUTERS);
    copy(curnPH2Z2, curnPH2Z2 + MAX_nROUTERS, nPH2Z2 + i*MAX_nROUTERS);
    copy(curnPH3Z2, curnPH3Z2 + MAX_nROUTERS, nPH3Z2 + i*MAX_nROUTERS);
    copy(curnPH4Z2, curnPH4Z2 + MAX_nROUTERS, nPH4Z2 + i*MAX_nROUTERS);
    for (int j=0; j<MAX_nROUTERS; j++)
    {
      curnPH1Z1[j] = 0;
      curnPH2Z1[j] = 0;
      curnPH3Z1[j] = 0;
      curnPH4Z1[j] = 0;
      curnPH1Z2[j] = 0;
      curnPH2Z2[j] = 0;
      curnPH3Z2[j] = 0;
      curnPH4Z2[j] = 0;
    }
  }



  // ****** WRITE OUT ALL THE ROUTED STUBS TO THE APPROPRIATE FILES ******
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




