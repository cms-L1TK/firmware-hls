// MatchCalculator test bench
#include "HLSCandidateMatch.hh"
#include "MatchCalculator.hh"
#include <iostream>
#include <fstream>
#include "ap_int.h"

using namespace std;

const int nevents = 1; // specify how many events you want to loop over

int main()
{
  
	// declare all arrays

	HLSCandidateMatch inData1[nevents-1][MAX_nCM-1];
	for (int i = 0; i < nevents; i++){
		for (int j = 0; j < MAX_nCM; j++){
			inData1[i][j] = HLSCandidateMatch();
		}
	}

	CM_proj_index in_p_index;
	CM_stub_index in_s_index;

	// total number CM in
	int num_CM = 3;
	// counter for which CM in the event is being read in
	int cur_CM = 0;

	// read in files
	ifstream fin;
	string token;
	string str_p_index;
	string str_s_index;
    fin.open("emData_MC/test_CM.dat");
    if (!fin){
    	std::cerr << "ERROR opening file" << std::endl;
    	return -1; // abort test
    }
    while (getline(fin,token)){
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
			inData1[0][cur_CM].AddCM(in_p_index,in_s_index);

			// increment counter of CMs
			//cur_CM++;
        }
        else{
        	std::cout << "Hit max number of CMs allowed" << std::endl;
        	break;
        }
        cur_CM++;
    }
    fin.close();

	// loop over events
	for (int i = 0; i < nevents; i++){
		// run the MatchCalculator
		MatchCalculator( inData1[i], cur_CM );
	}

	// must return 0 otherwise vivado_hls will think it crashed
	return 0;
}
