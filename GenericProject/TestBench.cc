// Test Bench file

// local header files
#include "Constants.hh"
#include "Generic.hh"

#include <iostream>

// this function needs to be written
// reads data from input file named fname into
// arrays, with n_in entries
void get_data(const char* fname, int & n_in,
	      GenericData  input[MAX_SIZE] );


// this function needs to be written. Return 0 on success,
// non-zero on error (i.e., if they don't match)
int compare_output(int d1, GenericData data1[MAX_SIZE], 
		   int d2, GenericData data2[MAX_SIZE]);


int main()
{
  std::cout << "Test Bench for Generic project " << std::endl;

  int nin1, nin2, nout1, nout2;
  GenericData input1[MAX_SIZE];
  GenericData input2[MAX_SIZE];
  GenericData output1[MAX_SIZE];
  GenericData output2[MAX_SIZE];

  get_data("input1.dat", nin1, input1);
  get_data("input2.dat", nin2, input2);

  TopLevel(nin1, input1, nin2, input2, nout1, output1, nout2, output2);

  // 
  GenericData exp_output1[MAX_SIZE]; int nexp_out1;
  GenericData exp_output2[MAX_SIZE]; int nexp_out2;

  get_data("expected_output1.dat", nexp_out1, exp_output1);
  get_data("expected_output2.dat", nexp_out2, exp_output2);

  int c1  = compare_output(nexp_out1, exp_output1,
			   nout1, output1);
  int c2  = compare_output(nexp_out2, exp_output2,
			   nout2, output2);

  // close and return
  return c1+c2;

}
