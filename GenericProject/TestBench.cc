// Test Bench file

// local header files
#include "Constants.hh"
#include "Generic.hh"

#include <iostream>
#include <fstream>

// this function needs to be written
// reads data from input file named fname into
// arrays, with n_in entries
int get_data(const char* fname, int & n_in,
	         GenericData  input[MAX_SIZE] )
{
	std::ifstream infile(fname, std::ios::in);
	if ( ! infile ) {
		char cwd[256];
		getcwd(cwd, 256);
		std::cerr << "Can't open file " << fname
				  << " in directory " << cwd
				  << std::endl;
		return -1;
	}
	n_in = 0;
	while ( infile ) {
		int val ;
		infile >> val;
		std::cout << "val is " << val << std::endl;
		input[n_in] = val;
		++n_in;
		if ( n_in == MAX_SIZE) {
			n_in -= 1;
			break;
		}
	}
	return 0;
}


// this function needs to be written. Return 0 on success,
// non-zero on error (i.e., if they don't match)
int compare_output(int d1, GenericData data1[MAX_SIZE], 
		   int d2, GenericData data2[MAX_SIZE])
{
	int ret = 0;
	if ( d1 != d2 ) {
		return -1; // different size of inputs
	}
	else {
		ret = 0;
		for ( int i = 0; i < d2; ++i ) {
			if ( data1[i] != data2[i])
				++ret;
		}
	}
	return ret;
}


int main(int argc, char **argv, char **envp)
{
  std::cout << "Test Bench for Generic project " << std::endl;
//  for (char **env = envp; *env != 0; env++)
//  {
//    char *thisEnv = *env;
//    printf("%s\n", thisEnv);
//  }

  int nin1, nin2, nout1, nout2;
  GenericData input1[MAX_SIZE];
  GenericData input2[MAX_SIZE];
  GenericData output1[MAX_SIZE];
  GenericData output2[MAX_SIZE];

  get_data("../../../../input1.dat", nin1, input1);
  get_data("../../../../input2.dat", nin2, input2);

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
