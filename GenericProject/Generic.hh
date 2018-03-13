// header file for generic project

#pragma once

#include "Constants.hh"

int TopLevel(int n_in1, GenericData input1[MAX_SIZE],
	     int n_in2, GenericData input2[MAX_SIZE],
	     int & n_out1, GenericData out1[MAX_SIZE],
	     int & n_out2, GenericData out2[MAX_SIZE]
	     );


void TwoToOne(
	      const GenericData in1[MAX_SIZE], // input1
	      const GenericData in2[MAX_SIZE], // input2
	      const int n_in1, // number of input 1
	      const int n_in2, // number of input 1
	      GenericData out[MAX_SIZE], // output
	      int & n_out // number of output 
	      );


void OneToThree(
	      const GenericData input[MAX_SIZE], // input
	      const int n_in, // number of input data 
	      GenericData out1[MAX_SIZE],  // first output
	      GenericData out2[MAX_SIZE],  // second output
	      GenericData out3[MAX_SIZE],   // third output
	      int & n_out1, // number of first output
	      int & n_out2, // number of second output
	      int & n_out3  // number of third input
		);


