
#include "Constants.hh"
#include "Generic.hh"

int TopLevel(int n_in1, GenericData input1[MAX_SIZE],
	     int n_in2, GenericData input2[MAX_SIZE],
	     int & n_out1, GenericData out1[MAX_SIZE],
	     int & n_out2, GenericData out2[MAX_SIZE]
	     )
{
  GenericData d1[MAX_SIZE]; int n_d1;
  GenericData d2[MAX_SIZE]; int n_d2;
  GenericData d3[MAX_SIZE]; int n_d3;

  GenericData d4[MAX_SIZE]; int n_d4;
  GenericData d5[MAX_SIZE]; int n_d5;
  GenericData d6[MAX_SIZE]; int n_d6;

  OneToThree(input1, n_in1, d1, d2, d3, n_d1, n_d2, n_d3);
  OneToThree(input2, n_in2, d4, d5, d6, n_d4, n_d5, n_d6);

  GenericData f1[MAX_SIZE]; int n_f1;
  GenericData f2[MAX_SIZE]; int n_f2;


  TwoToOne(d1, d2, n_d1, n_d2, f1, n_f1);
  TwoToOne(d3, d4, n_d3, n_d4, f2, n_f2);

  TwoToOne(f1, f2, n_f1, n_f2, out1, n_out1); // final output 1
  TwoToOne(d5, d6, n_d5, n_d6, out2, n_out2); // final output 2
}
