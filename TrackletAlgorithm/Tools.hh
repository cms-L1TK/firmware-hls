// Header for general tools
//

#include "ap_int.h"
#include "hls_stream.h"
#include "HLSCandidateMatch.hh"

using namespace std;

// --------------- FIXME ----------------------------

// * Right now comparison is for whole chunk of data in -- want to select bits of interest!
// * Template for various bit sizes (switch from int to ap_int)
// * There maybe some intrinsic assumption on FIFO?
// * In the for loop (add a break for MAX processing number allowed)

// --------------------------------------------------

// TEMPLATE THESE PARAMETERS
const int MAX   = 10; // maximum number of CMs
const int nBITS = 12;
const int MSB   = 11;
const int LSB   = 6;
const int nSB   = MSB-LSB+1;




void mergertop(
		HLSCandidateMatch data1,
		ap_uint<7>        n1,
		ap_uint<7>        & addr1,
		HLSCandidateMatch data2,
		ap_uint<7>        n2,
		ap_uint<7>        & addr2,
		HLSCandidateMatch data3,
		ap_uint<7>        n3,
		ap_uint<7>        & addr3,
		HLSCandidateMatch data4,
		ap_uint<7>        n4,
		ap_uint<7>        & addr4,
		HLSCandidateMatch & data_out,
		bool              & valid_data_out,
		bool              & read1,
		bool              & read2,
		bool              & read3,
		bool              & read4
	);

void merge2layer(
		HLSCandidateMatch in1,
		bool              valid1,
		bool              & outread1,
		HLSCandidateMatch in2,
		bool              valid2,
		bool              & outread2,
		HLSCandidateMatch in3,
		bool              valid3,
		bool              & outread3,
		HLSCandidateMatch in4,
		bool              valid4,
		bool              & outread4,
		HLSCandidateMatch & out,
		bool              & validout
	);


void cleanmerger(
		HLSCandidateMatch inA,
		bool              validA,
		bool              & readoutA,
		HLSCandidateMatch inB,
		bool              validB,
		bool              & readoutB,
		bool              inread,
		HLSCandidateMatch & out,
		bool              & vout,
		bool			  & sA,
		bool			  & sB
	);


void basicmerger(
		HLSCandidateMatch inA,
		bool              validA,
		bool              & readoutA,
		HLSCandidateMatch inB,
		bool              validB,
		bool              & readoutB,
		bool              inread,
		HLSCandidateMatch & out,
		bool              & vout
	);



void merger(
		HLSCandidateMatch in1,    // input data1
		ap_uint<7> n1,            // number in input1
		ap_uint<7> & subindex1,   // read addr1
		HLSCandidateMatch in2,    // input data2
		ap_uint<7> n2,            // number in input2
		ap_uint<7> & subindex2,   // read addr2
		HLSCandidateMatch & out,  // output data
		ap_uint<7> & nout         // number output
	);
/*
{

    HLSCandidateMatch a = in1;           // full data word from input 1
    HLSCandidateMatch b = in2;           // full data word from input 2
    CM_proj_index inA = in1.GetPIndex(); // part of input 1 word used for sorting
    CM_proj_index inB = in2.GetPIndex(); // part of input 2 word used for sorting

	// setup states in FSM
	ap_uint<3> state = 0;
	if (subindex1 >= n1 && subindex2 >= n2) state = 1; // BOTH DONE
	else if (subindex1 >= n1)               state = 2; // 1 DONE
	else if (subindex2 >= n2)               state = 3; // 2 DONE
	else if (inA <= inB)                    state = 4; // 1 SMALLER
	else if (inA > inB)                     state = 5; // 2 SMALLER
	else                                    state = 6; // CATCHALL

	// case statements
	switch(state)
	{
		case (0): // init
			out = HLSCandidateMatch();
			break;
		case (1): // both done
			out = HLSCandidateMatch();
			break;
		case (2): // 1 done
			out = in2;
			subindex2++;
			nout++;
			break;
		case (3): // 2 done
			out = in1;
			subindex1++;
			nout++;
			break;
		case (4): // 1 smaller
			out = in1;
			subindex1++;
			nout++;
			break;
		case (5): // 2 smaller
			out = in2;
			subindex2++;
			nout++;
			break;
		case (6): // else
			out = HLSCandidateMatch();
			break;
		default : // default
			out = HLSCandidateMatch();
			break;
	}
};


	/*
    // loop up to number of inputs in
    MERGE_LOOP: for (int i = 0; i < n; i++)
    {
    	if (i < MAX){

			inA = a.GetPIndex(); //((a >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest
			inB = b.GetPIndex(); //((b >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest

			std::cout << "subindex 1 : " << subindex1 << " of " << n1 << std::endl;
			std::cout << "subindex 2 : " << subindex2 << " of " << n2 << std::endl;

			std::cout << "Part word A: " << inA << " of " << a.raw() << std::endl;
			std::cout << "Part word B: " << inB << " of " << b.raw() << std::endl;

			if (subindex1 > n1 && subindex2 > n2) // if read out everything
			{
				std::cout << " Both done " << std::endl;
				out[i] = HLSCandidateMatch();
			}
			else if (subindex1 > n1) // if read out all of in1, only read in2
			{
				std::cout << " Stream1 done" << std::endl;
				out[i] = b;
				if (subindex2 != n2) b = in2[subindex2];
				//if (!in2.empty()) in2.read(b);
				subindex2++;
			}
			else if (subindex2 > n2) // if read out all of in2, only read in1
			{
				std::cout << "Stream2 done" << std::endl;
				out[i] = a;
				if (subindex1 != n1) a = in1[subindex1];
				//if (!in1.empty()) in1.read(a);
				subindex1++;
			}
			// if data in both in1 and in2, read smaller data first
			else if (inA <= inB) // a is smaller
			{
				std::cout << "Stream1 smaller" << std::endl;
				out[i] = a;
				if (subindex1 != n1) a = in1[subindex1];
				//if (!in1.empty()) in1.read(a);
				subindex1++;
			}
			else // b is smaller
			{
				std::cout << "Stream2 smaller" << std::endl;
				out[i] = b;
				if (subindex2 != n2) b = in2[subindex2];
				//if (!in2.empty()) in2.read(b);
				subindex2++;
			}

			std::cout << "OUT: " << out[i].raw() << std::endl;
			//std::cout << "OUT: " << out.read() << std::endl;

    	}// end if less than MAX
    	else break; // break if reached max number of CMs allowed

    }// end for loop
	*/ // end merger function


/*

void old_merger(
		HLSCandidateMatch in1[MAX],
		HLSCandidateMatch in2[MAX],
		int n1,
		int n2,
		HLSCandidateMatch out[MAX]
		)
{

    ap_uint<7> n = n1 + n2;   // total number of inputs
    HLSCandidateMatch a = in1[0];     // full data word from input 1
    HLSCandidateMatch b = in2[0];     // full data word from input 2
    CM_proj_index inA = 0;        // part of input 1 word for comparison
    CM_proj_index inB = 0;        // part of input 2 word for comparison
    ap_uint<7> subindex1 = 1; // counter for the reading of input 1
    ap_uint<7> subindex2 = 1; // counter for the reading of input 2

    // loop up to number of inputs in
    MERGE_LOOP: for (int i = 0; i < n; i++)
    {
    	if (i < MAX){

			inA = a.GetPIndex(); //((a >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest
			inB = b.GetPIndex(); //((b >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest

			std::cout << "subindex 1 : " << subindex1 << " of " << n1 << std::endl;
			std::cout << "subindex 2 : " << subindex2 << " of " << n2 << std::endl;

			std::cout << "Part word A: " << inA << " of " << a.raw() << std::endl;
			std::cout << "Part word B: " << inB << " of " << b.raw() << std::endl;

			if (subindex1 > n1 && subindex2 > n2) // if read out everything
			{
				std::cout << " Both done " << std::endl;
				out[i] = HLSCandidateMatch();
			}
			else if (subindex1 > n1) // if read out all of in1, only read in2
			{
				std::cout << " Stream1 done" << std::endl;
				out[i] = b;
				if (subindex2 != n2) b = in2[subindex2];
				//if (!in2.empty()) in2.read(b);
				subindex2++;
			}
			else if (subindex2 > n2) // if read out all of in2, only read in1
			{
				std::cout << "Stream2 done" << std::endl;
				out[i] = a;
				if (subindex1 != n1) a = in1[subindex1];
				//if (!in1.empty()) in1.read(a);
				subindex1++;
			}
			// if data in both in1 and in2, read smaller data first
			else if (inA <= inB) // a is smaller
			{
				std::cout << "Stream1 smaller" << std::endl;
				out[i] = a;
				if (subindex1 != n1) a = in1[subindex1];
				//if (!in1.empty()) in1.read(a);
				subindex1++;
			}
			else // b is smaller
			{
				std::cout << "Stream2 smaller" << std::endl;
				out[i] = b;
				if (subindex2 != n2) b = in2[subindex2];
				//if (!in2.empty()) in2.read(b);
				subindex2++;
			}

			std::cout << "OUT: " << out[i].raw() << std::endl;
			//std::cout << "OUT: " << out.read() << std::endl;

    	}// end if less than MAX
    	else break; // break if reached max number of CMs allowed

    }// end for loop

}; // end merger function

void stream_merger(
    hls::stream< ap_uint<nBITS> > &in1, // input stream 1
    hls::stream< ap_uint<nBITS> > &in2, // input stream 2
    int n1,                             // number of inputs in 1
    int n2,                             // number of inputs in 2
    hls::stream< ap_uint<nBITS> > &out  // merged output stream
    )
{

    ap_uint<7> n = n1 + n2;   // total number of inputs
    ap_uint<nBITS> a = 0;     // full data word from input 1
    ap_uint<nBITS> b = 0;     // full data word from input 2
    ap_uint<nSB> inA = 0;     // part of input 1 word for comparison
    ap_uint<nSB> inB = 0;     // part of input 2 word for comparison
    ap_uint<7> subindex1 = 1; // counter for the reading of input 1
    ap_uint<7> subindex2 = 1; // counter for the reading of input 2

    // read inputs
    std::cout << "Read input streams" << std::endl;
    if (!in1.empty()) in1.read(a);
    if (!in2.empty()) in2.read(b);

    // pick up the part of the word that is useful for the comparison
    // (ie. For the MC this is the tracklet index)
    // inA = a.GetPIndex();
    // inB = b.GetPIndex();

    // loop up to number of inputs in
    for (int i = 0; i < n; i++)
    {

    	inA = ((a >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest
    	inB = ((b >> nSB) & 0x3FUL); // FIXME: Picks up the 3F = 6 bits of interest

        std::cout << "subindex 1 : " << subindex1 << " of " << n1 << std::endl;
        std::cout << "subindex 2 : " << subindex2 << " of " << n2 << std::endl;

        std::cout << "Part word A: " << inA << " of " << a << std::endl;
        std::cout << "Part word B: " << inB << " of " << b << std::endl;

        if (subindex1 > n1 && subindex2 > n2) // if read out everything
        {
        	std::cout << " Both done " << std::endl;
        	out << 0;
        }
        else if (subindex1 > n1) // if read out all of in1, only read in2
        {
        	std::cout << " Stream1 done" << std::endl;
			out << b;
			if (!in2.empty()) in2.read(b);
			subindex2++;
        }
        else if (subindex2 > n2) // if read out all of in2, only read in1
        {
        	std::cout << "Stream2 done" << std::endl;
			out << a;
			if (!in1.empty()) in1.read(a);
			subindex1++;
        }
        // if data in both in1 and in2, read smaller data first
        else if (inA <= inB) // a is smaller
        {
        	std::cout << "Stream1 smaller" << std::endl;
			out << a;
			if (!in1.empty()) in1.read(a);
			subindex1++;
        }
        else // b is smaller
        {
        	std::cout << "Stream2 smaller" << std::endl;
			out << b;
			if (!in2.empty()) in2.read(b);
			subindex2++;
        }

        std::cout << "OUT: " << out.read() << std::endl;
    }

};

*/
