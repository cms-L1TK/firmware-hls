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

void stream_merger(
		hls::stream< ap_uint<nBITS> > &in1, // input stream 1
		hls::stream< ap_uint<nBITS> > &in2, // input stream 2
		int n1,                             // number of inputs in 1
		int n2,                             // number of inputs in 2
		hls::stream< ap_uint<nBITS> > &out  // merged output stream
    );

void stream_merger_v2(
		hls::stream< ap_uint<nBITS> > &in1, // input stream 1
		hls::stream< ap_uint<nBITS> > &in2, // input stream 2
		bool & read1,
		bool & read2,
		ap_uint<7> n1,                      // number of inputs in 1
		ap_uint<7> n2,                      // number of inputs in 2
		ap_uint<7> & subindex1,				// read in number 1
		ap_uint<7> & subindex2,				// read in number 2
		hls::stream< ap_uint<nBITS> > &out,  // merged output stream
		bool finallayer
    );

void new_merger(
		HLSCandidateMatch in1[MAX_nCM],
		HLSCandidateMatch in2[MAX_nCM],
		HLSCandidateMatch in3[MAX_nCM],
		HLSCandidateMatch in4[MAX_nCM],
		ap_uint<7>        nin1,
		ap_uint<7>        nin2,
		ap_uint<7>        nin3,
		ap_uint<7>        nin4,
		hls::stream< ap_uint<12> > & out,
		bool              newtracklet
	);
