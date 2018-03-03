// a generic module going one to two

#include "Constants.hh"


void TwoToOne(
	      const GenericData *in1, // input1
	      const GenericData *in2, // input2
	      const int n_in1, // number of input 1
	      const int n_in2, // number of input 1
	      GenericData *out, // output
	      int & n_out // number of output 
	      )
{

	for(int i = 0; i < n_in1; i++){

		const GenericData avg = 0;
		*avg = (*in1[i] + *in2[i])/2;

		*out[i] = *avg;

	}

	return;
}

	     
