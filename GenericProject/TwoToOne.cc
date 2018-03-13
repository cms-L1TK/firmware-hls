// a generic module going one to two

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

	for(int i = 0; i < n_in1; i++){

		const GenericData avg = (in1[i] + in2[i])/2;

		out[i] = avg;

	}
	n_out = n_in1;

	return;
}

	     
