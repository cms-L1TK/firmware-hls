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

	LOOP_2_1: for(int i = 0; i < MAX_SIZE; ++i){
		// alternative: BREAK out of loop. This means shorter latency
		// possible, but variable latency.
		if ( i < cnt ) {
			out[i] = (in1[i] + in2[i])/2;
		}
		else
			out[i] = 0;
	}
	n_out = cnt;

	return;
}

	     
