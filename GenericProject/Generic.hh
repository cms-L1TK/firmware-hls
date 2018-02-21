// header file for generic project

#pragma once

#include "Constants.hh"

int TopLevel(int n_in1, GenericData input1[MAX_SIZE],
	     int n_in2, GenericData input2[MAX_SIZE],
	     int & n_out1, GenericData out1[MAX_SIZE],
	     int & n_out2, GenericData out2[MAX_SIZE]
	     );


void TwoToOne(
	      const GenericData *in1, // input1
	      const GenericData *in2, // input2
	      const int n_in1, // number of input 1
	      const int n_in2, // number of input 1
	      GenericData *out, // output
	      int & n_out // number of output 
	      );


void OneToThree(
	      const GenericData *input, // input
	      const int n_in, // number of input data 
	      GenericData *out1,  // first output
	      GenericData *out2,  // second output
	      GenericData *out3,   // third output
	      int & n_out1, // number of first output
	      int & n_out2, // number of second output
	      int & n_out3  // number of third input
		);


