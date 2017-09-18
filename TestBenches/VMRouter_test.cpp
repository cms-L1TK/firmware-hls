// VMRouter test bench
#include "HLSConstants.hh"
#include "HLSFullStubLayerPS.hh"
#include "HLSReducedStubLayer.hh"
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

void PrintRouted(HLSReducedStubLayer vmStubsPHXZX[MAX_nSTUBS*MAX_nSECTORS*MAX_nEVENTS], ReducedIndex nStubs[MAX_nSECTORS*MAX_nEVENTS], string outFileString)
{
  ReducedZ_Layer redZ;
  ReducedPhi_Layer redPhi;
  ReducedR_Layer redR;
  ReducedPt_Layer redPt;
  ReducedIndex redIndex;
  string strZ, strPhi, strR, strPt, strIndex;
  ofstream fout;
  char curFile[128];
  int sectorList[MAX_nSECTORS];
  for (int i=0; i<MAX_nSECTORS; i++)
  {
    sectorList[i] = i+1;
  }
  for (int i=0; i<MAX_nREGIONS; i++)
  {
    for (int j=0; j<MAX_nSECTORS; j++)
    {
      sprintf(curFile,"VMStubs_VMS_%s%sn1_%02d_new.dat", regionList[i].c_str(), outFileString.c_str(), sectorList[j]);
      fout.open(curFile);
      char outString[128];
      int BXCode;
      string strBXCode;
      int nRouted = 0;
      stringstream stream;
      string strnRouted;
      for (int k=0; k<MAX_nEVENTS; k++)
      {
        BXCode = k%8;
        strBXCode = bitset<3>(BXCode).to_string();
        sprintf(outString,"BX = %s Event : %d\n",strBXCode.c_str(),k+1);
        fout << outString;
        for (int l=0; l<nStubs[j + i*MAX_nSECTORS + k*MAX_nSECTORS*MAX_nREGIONS]; l++)
        {
          stream.str("");
          stream << setfill ('0') << setw(2) << hex << l;
          strnRouted = stream.str();
          redZ = vmStubsPHXZX[l + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + k*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].GetZ();
          redPhi = vmStubsPHXZX[l + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + k*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].GetPhi();
          redR = vmStubsPHXZX[l + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + k*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].GetR();
          redPt = vmStubsPHXZX[l + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + k*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].GetPt();
          redIndex = vmStubsPHXZX[l + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + k*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].GetIndex();
          strZ = bitset<4>(redZ.to_int()).to_string().c_str();
          strIndex = bitset<6>(redIndex.to_int()).to_string().c_str();
          strPhi = bitset<3>(redPhi.to_int()).to_string().c_str();
          strR = bitset<2>(redR.to_int()).to_string().c_str();
          strPt = bitset<3>(redPt.to_int()).to_string().c_str();
          sprintf(outString,"%s %s|%s|%s|%s|%s\n", strnRouted.c_str(), strPt.c_str(), strIndex.c_str(), strZ.c_str(), strPhi.c_str(), strR.c_str());
          fout << outString;
        }
      }
      fout.close();
    }
  }
}

int main()
{
  // ****** DECLARE ALL ARRAY VARIABLES ******
  HLSFullStubLayerPS stubsInLayer[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSFullStubLayerPS allStubs[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH1Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH2Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH3Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH4Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH1Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH2Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH3Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  HLSReducedStubLayer vmStubsPH4Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];

  HLSFullStubLayerPS curStubsInLayer[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSFullStubLayerPS curAllStubs[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH1Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH2Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH3Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH4Z1[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH1Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH2Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH3Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];
  HLSReducedStubLayer curvmStubsPH4Z2[MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS];

  ReducedIndex nPH1Z1[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH2Z1[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH3Z1[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH4Z1[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH1Z2[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH2Z2[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH3Z2[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  ReducedIndex nPH4Z2[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];
  for (int i=0; i<MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS; i++)
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
  ReducedIndex curnPH1Z1[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH2Z1[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH3Z1[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH4Z1[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH1Z2[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH2Z2[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH3Z2[MAX_nSECTORS*MAX_nREGIONS];
  ReducedIndex curnPH4Z2[MAX_nSECTORS*MAX_nREGIONS];
  for (int i=0; i<MAX_nSECTORS*MAX_nREGIONS; i++)
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
  int nStubs[MAX_nSECTORS*MAX_nREGIONS*MAX_nEVENTS];

  FullZ_Layer_PS inZ;
  FullPhi_Layer_PS inPhi;
  FullR_Layer_PS inR;
  FullPt_Layer_PS inPt;

  FullZ_Layer_PS allZ;
  FullPhi_Layer_PS allPhi;
  FullR_Layer_PS allR;
  FullPt_Layer_PS allPt;



  // ****** READ IN DATA FOR ALL EVENTS AND DETECTOR REGIONS ******
  ifstream fin;
  char curFile[128];
  int sectorList[MAX_nSECTORS];
  for (int i=0; i<MAX_nSECTORS; i++)
  {
    sectorList[i] = i+1;
  }
  string token;
  int curEvent;
  int curStub = 0;
  for (int i=0; i<MAX_nREGIONS; i++)
  {
    for (int j=0; j<MAX_nSECTORS; j++)
    {
      curEvent = 0;
      sprintf(curFile,"emData/LayerStubs_SL1_%s_%02d.dat",regionList[i].c_str(),sectorList[j]);
      fin.open(curFile);
      if ( ! fin )
      {
        char cwd[1024]; getcwd(cwd, 1024);
        std::cerr << "Problem opening file " << curFile
        << ": " << strerror(errno) << "," << std::endl
        << "in directory " << cwd
        << std::endl;
        std::cerr << "Aborting test." << std::endl;
        return -1;
      }
      getline(fin,token);
      while (getline(fin,token,' '))
      {
        if (token[0] == 'B')
        {
          nStubs[j + i*MAX_nSECTORS + curEvent*MAX_nSECTORS*MAX_nREGIONS] = curStub;
          curStub = 0;
          curEvent ++;
          getline(fin,token);
        }
        else
        {
          getline(fin,token,'|');
          inPt.set_VAL(strtol(token.c_str(),NULL,2));
          getline(fin,token,'|');
          inR.set_VAL(strtol(token.c_str(),NULL,2));
          getline(fin,token,'|');
          inZ.set_VAL(strtol(token.c_str(),NULL,2));
          getline(fin,token,'\n');
          inPhi.set_VAL(strtol(token.c_str(),NULL,2));
          stubsInLayer[curStub + j*MAX_nSTUBS + i*MAX_nSTUBS*MAX_nSECTORS + curEvent*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS].AddStub(inZ, inPhi, inR, inPt);
          curStub++;
        }
      }
      fin.close();
    }
  }



  // ****** LOOP OVER ALL EVENTS, SENDING EACH EVENT TO VMROUTERDISPATCHER ******
  int curnStubs[MAX_nSECTORS*MAX_nREGIONS];
  for (int i=0; i<MAX_nEVENTS; i++)
  {
    copy(stubsInLayer + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, stubsInLayer + (i+1)*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, curStubsInLayer);
    for (int j=0; j<MAX_nSECTORS*MAX_nREGIONS; j++)
    {
      curnStubs[j] = nStubs[j + i*MAX_nSECTORS*MAX_nREGIONS];
    }
    VMRouterDispatcher(curStubsInLayer, curAllStubs, curvmStubsPH1Z1, curvmStubsPH2Z1, curvmStubsPH3Z1,
                       curvmStubsPH4Z1, curvmStubsPH1Z2, curvmStubsPH2Z2, curvmStubsPH3Z2, curvmStubsPH4Z2,
                       curnStubs, curnPH1Z1, curnPH2Z1, curnPH3Z1, curnPH4Z1, curnPH1Z2, curnPH2Z2, curnPH3Z2, curnPH4Z2);

    copy(curAllStubs, curAllStubs + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, allStubs + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH1Z1, curvmStubsPH1Z1 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH1Z1 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH2Z1, curvmStubsPH2Z1 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH2Z1 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH3Z1, curvmStubsPH3Z1 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH3Z1 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH4Z1, curvmStubsPH4Z1 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH4Z1 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH1Z2, curvmStubsPH1Z2 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH1Z2 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH2Z2, curvmStubsPH2Z2 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH2Z2 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH3Z2, curvmStubsPH3Z2 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH3Z2 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);
    copy(curvmStubsPH4Z2, curvmStubsPH4Z2 + MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS, vmStubsPH4Z2 + i*MAX_nSTUBS*MAX_nSECTORS*MAX_nREGIONS);

    for (int j=0; j<MAX_nSECTORS*MAX_nREGIONS; j++)
    {
      nPH1Z1[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH1Z1[j];
      nPH2Z1[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH2Z1[j];
      nPH3Z1[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH3Z1[j];
      nPH4Z1[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH4Z1[j];
      nPH1Z2[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH1Z2[j];
      nPH2Z2[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH2Z2[j];
      nPH3Z2[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH3Z2[j];
      nPH4Z2[j + i*MAX_nSECTORS*MAX_nREGIONS] = curnPH4Z2[j];
    }
    for (int j=0; j<MAX_nSECTORS*MAX_nREGIONS; j++)
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
  string routeList[8] = {"PHI1X1", "PHI1X2", "PHI2X1", "PHI2X2", "PHI3X1", "PHI3X2", "PHI4X1", "PHI4X2"};
  char curCommand[128];
  for (int i=0; i<MAX_nREGIONS; i++)
  {
    for (int j=0; j<MAX_nSECTORS; j++)
    {
      for (int k=0; k<nroutes[i]; k++)
      {
        sprintf(curCommand,"diff  -s emData/VMStubs_VMS_%s%sn1_%02d.dat VMStubs_VMS_%s%sn1_%02d_new.dat", regionList[i].c_str(), routeList[k].c_str(), sectorList[j], regionList[i].c_str(), routeList[k].c_str(), sectorList[j]);
        if (system(curCommand))
        {
    	  allPass = i*8+j;
        }
      }
    }
  }
  return allPass;


}




