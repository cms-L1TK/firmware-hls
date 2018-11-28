
#include "Constants.hh"
#include "Generic.hh"

int TopLevel(const int n_in1, const GenericData input1[MAX_SIZE],
	     const int n_in2, const GenericData input2[MAX_SIZE],
	     int & n_out1, GenericData out1[MAX_SIZE],
	     int & n_out2, GenericData out2[MAX_SIZE]
	     )
{
#pragma HLS INTERFACE ap_ctrl_hs register port=return
  static GenericData d1[MAX_SIZE]; static int n_d1;
  static GenericData d2[MAX_SIZE]; static int n_d2;
  static GenericData d3[MAX_SIZE]; static int n_d3;

  static GenericData d4[MAX_SIZE]; static int n_d4;
  static GenericData d5[MAX_SIZE]; static int n_d5;
  static GenericData d6[MAX_SIZE]; static int n_d6;

  OneToThree(input1, n_in1, d1, d2, d3, n_d1, n_d2, n_d3);
  OneToThree(input2, n_in2, d4, d5, d6, n_d4, n_d5, n_d6);

  static GenericData f1[MAX_SIZE]; static int n_f1;
  static GenericData f2[MAX_SIZE]; static int n_f2;


  TwoToOne(d1, d2, n_d1, n_d2, f1, n_f1);
  TwoToOne(d3, d4, n_d3, n_d4, f2, n_f2);

#ifdef DF_BREAK
  static GenericData f1_2[MAX_SIZE]; static int n_f1_2;

  // this second read of an input breaks the dataflow directive
  TwoToOne(f1, input1, n_f1, n_in1, f1_2, n_f1_2); // intermediate with a buffered stage

  TwoToOne(f1_2, f2, n_f1_2, n_f2, out1, n_out1); // final output 1
#else
  TwoToOne(f1, f2, n_f1, n_f2, out1, n_out1); // final output 1
#endif
  TwoToOne(d5, d6, n_d5, n_d6, out2, n_out2); // final output 2

  return 0;
}
