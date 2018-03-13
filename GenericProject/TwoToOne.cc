// a generic module going two to one

#include <algorithm>

#include "Constants.hh"


void TwoToOne(
	      const GenericData in1[MAX_SIZE], // input1
	      const GenericData in2[MAX_SIZE], // input2
	      const int n_in1, // number of input 1
	      const int n_in2, // number of input 1
	      GenericData out[MAX_SIZE], // output
	      int & n_out // number of output 
	      )
{
	int cnt = std::min(n_in1, n_in2);

//#pragma HLS pipeline II=1
	LOOP_2_1: for(int i = 0; i < MAX_SIZE; ++i){
		if ( i == cnt) break;

		out[i] = (in1[i] + in2[i])/2;
	}
	n_out = cnt;

	return;
}

	     
