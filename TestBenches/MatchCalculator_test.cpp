// MatchCalculator test bench
#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"
#include "HLSFullMatch.hh"
#include "MatchCalculator.hh"
#include <iostream>
#include <fstream>
#include "ap_int.h"

using namespace std;

const int nevents = 1; // specify how many events you want to loop over

int main()
{
  
	// declare all arrays
	HLSCandidateMatch inPHI1[nevents][MAX_nCM];   // input CM
	HLSCandidateMatch inPHI2[nevents][MAX_nCM];   // input CM
	HLSCandidateMatch inPHI3[nevents][MAX_nCM];   // input CM
	HLSCandidateMatch inPHI4[nevents][MAX_nCM];   // input CM
    HLSAllStubs       inStub[nevents][MAX_nSTUB]; // input stubs
    HLSProjection     inProj[nevents][MAX_nPROJ]; // input projections
    HLSFullMatch	  outMatch[nevents][MAX_nFM]; // output FMs
    ap_int<7>         nMatches[nevents];          // output num of FMs (7b allow for up to 64)


    // initialize
	for (int i = 0; i < nevents; i++){
		for (int j = 0; j < MAX_nCM;   j++) inPHI1[i][j]   = HLSCandidateMatch();
		for (int j = 0; j < MAX_nCM;   j++) inPHI2[i][j]   = HLSCandidateMatch();
		for (int j = 0; j < MAX_nCM;   j++) inPHI3[i][j]   = HLSCandidateMatch();
		for (int j = 0; j < MAX_nCM;   j++) inPHI4[i][j]   = HLSCandidateMatch();
		for (int j = 0; j < MAX_nSTUB; j++) inStub[i][j]   = HLSAllStubs();
		for (int j = 0; j < MAX_nPROJ; j++) inProj[i][j]   = HLSProjection();
		for (int j = 0; j < MAX_nFM;   j++) outMatch[i][j] = HLSFullMatch();
	}

	CM_proj_index in_p_index;
	CM_stub_index in_s_index;


	// counter for which CM in the event is being read in
	ap_uint<7> cur_CM = 0;

	// read in files
	ifstream fin_CM;
	string token;
	string str_p_index;
	string str_s_index;
    fin_CM.open("emData_MC/test_CM.dat");
    if (!fin_CM){
    	std::cerr << "ERROR opening file" << std::endl;
    	return -1; // abort test
    }
    while (getline(fin_CM,token)){

        if (cur_CM < MAX_nCM){
            // read in lines
			std::cout << "Reading in file" << std::endl;

			// top bits are projection index, bottom bits are stub index
			str_p_index = token.substr(0,nBITS_INDEX);           // take nBITS_INDEX starting at position 0 (MSB)
			str_s_index = token.substr(nBITS_INDEX,nBITS_INDEX); // take nBITS_INDEX starting at position nBITS_INDEX (MSB)

			// convert string to int
			// ap_[u]int method (string,n) allows for converting string of base n
			in_p_index = CM_proj_index(str_p_index.c_str(),2);
			in_s_index = CM_stub_index(str_s_index.c_str(),2);

			// make the CM
			inPHI1[0][cur_CM].AddCM(in_p_index,in_s_index);

        }
        else{ // cur_CM >= MAX_nCM
        	std::cout << "Hit max number of CMs allowed" << std::endl;
        	break;
        }

        //increment counter of CMs
        cur_CM++;
    }
    fin_CM.close();

    // hack to get a stub and projection in more quickly
    ap_uint<nBITS_STUB> stub  = 0xA81E3ACE0UL;
    ap_uint<nBITS_PROJ> proj1 = 0xA06B7E1F807010UL;
    ap_uint<nBITS_PROJ> proj2 = 0x2A06B781F006C0EUL;
    ap_uint<nBITS_PROJ> proj3 = 0x2A0EB6E1080701AUL;
    ap_uint<7> num2 = 1;
    ap_uint<7> num3 = 0;
    ap_uint<7> num4 = 0;

    inPHI2[0][0].AddCM(0,0);
    inStub[0][0].AddStub(stub);
	inProj[0][0].AddProj(proj1);
	inProj[0][1].AddProj(proj2);
	inProj[0][2].AddProj(proj3);

	// loop over events
	for (int i = 0; i < nevents; i++){
		// run the MatchCalculator
		// MatchCalculator (SEED, LAYER, CM1, CM2, CM3, CM4, nCM1, nCM2, nCM3, nCM4, AS, PROJ, FM out, nFM out)
		MatchCalculator( 0, 2,
				        inPHI1[i], inPHI2[i], inPHI3[i], inPHI4[i],
				        cur_CM, num2, num3, num4,
						inStub[i], inProj[i] , outMatch[i], nMatches[i]
					   );
	}

	// setup hw and sw outputs for comparison
	ap_uint<nBITS_FM> hw_result[nevents][MAX_nFM];
	for (int i = 0; i < nevents; i++){
		for (int j = 0; j < nMatches[i]; j++){
			hw_result[i][j] = outMatch[i][j].raw();
		}
	}

	// hardcode the output expected
	ap_uint<nBITS_FM> sw_result[nevents][MAX_nFM];
	sw_result[0][0] = 16384;
	sw_result[0][1] = 1073766403;

	// check output between hw and sw
	int err_cnt = 0;
	FILE * fp; // file to store results
	fp = fopen("results.dat","w");
	printf("Testing DUT results");
	for (int i = 0; i < nevents; i++){
		for (int j = 0; j < nMatches[i]; j++){
			// FIXME: can't print ap_ints directly. is there a better way to do the comparison w/o using to_long?
			fprintf(fp,"%d %d \n",hw_result[i][j].to_long(),sw_result[i][j].to_long());
			if (hw_result[i][j] != sw_result[i][j]){
				err_cnt++; // increase error counter if they don't match
				printf("\n!!! ERROR at Event %d and FM %d -- expected %d , observed %d !!!\n",
						i, j, sw_result[i][j].to_long(), hw_result[i][j].to_long());
			}
		}
	}
	fclose(fp);
	printf("\n");

	// print final status message
	if (err_cnt) printf("!!! TEST FAILED : %d errors detected !!!\n",err_cnt);
	else         printf("*** Test Passed ***\n");

	// must return 0 otherwise vivado_hls will think it crashed
	return err_cnt;
}
