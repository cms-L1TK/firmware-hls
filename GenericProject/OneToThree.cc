// a generic module going one to three

#include "Constants.hh"


void OneToThree(
	      const GenericData input[MAX_SIZE], // input
	      const int n_in, // number of input data 
	      GenericData out1[MAX_SIZE],  // first output
	      GenericData out2[MAX_SIZE],  // second output
	      GenericData out3[MAX_SIZE],   // third output
	      int & n_out1, // number of first output
	      int & n_out2, // number of second output
	      int & n_out3  // number of third input
	      )
//notes: * = deference pointer: value pointed to by
//		 & = address of pointer: address of
{
//#pragma HLS pipeline II=1
	n_out1 = 0;
	n_out2 = 0;
	n_out3 = 0;
	LOOP_3_1: for(int i = 0; i < MAX_SIZE; ++i){

		if ( i == n_in) break;

		out1[i] = 4 * input[i];
		n_out1 += 1;
		out2[i] = 2 * input[i];
		n_out2 += 1;
		out3[i] = 3 * input[i];
		n_out3 += 1;

	}

	return;
}
