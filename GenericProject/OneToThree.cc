// a generic module going one to two

#include "Constants.hh"


void OneToThree(
	      const GenericData *input, // input
	      const int n_in, // number of input data 
	      GenericData *out1,  // first output
	      GenericData *out2,  // second output
	      GenericData *out3,   // third output
	      int & n_out1, // number of first output
	      int & n_out2, // number of second output
	      int & n_out3  // number of third input
	      )
//notes: * = deference pointer: value pointed to by
//		 & = address of pointer: address of
{
	n_out1 = 0;
	n_out2 = 0;
	n_out3 = 0;
	for(int i = 0; i < n_in; i++){

		out1[i] = 4 * input[i];
		n_out1 += 1;
		out2[i] = 2 * input[i];
		n_out2 += 1;
		out3[i] = 3 * input[i];
		n_out3 += 1;

	}

	return;
}
