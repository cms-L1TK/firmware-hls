#include "Tools.hh"
#include "hls_stream.h"
#include "ap_int.h"

// --------------- FIXME ----------------------------

// * Right now comparison is for whole chunk of data in -- want to select bits of interest!
// * Template for various bit sizes (switch from int to ap_int)
// * Maybe some assumption on FIFO? 
// * For loop (add a break for MAX processing number allowed) 

// --------------------------------------------------

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
	)
{
	bool valid1 = (n1 > 0) && (addr1 < n1);
	bool valid2 = (n2 > 0) && (addr2 < n2);
	bool valid3 = (n3 > 0) && (addr3 < n3);
	bool valid4 = (n4 > 0) && (addr4 < n4);

	//bool read1 = false;
	//bool read2 = false;
	//bool read3 = false;
	//bool read4 = false;

	merge2layer(data1, valid1, read1,
				data2, valid2, read2,
				data3, valid3, read3,
				data4, valid4, read4,
				data_out, valid_data_out);

	std::cout << ".. VALDS: " << valid1 << " " << valid2 << " " << valid3 << " " << valid4 << std::endl;
	std::cout << ".. READS:  " << read1 << " " << read2 << " " << read3 << " " << read4 << std::endl;
	std::cout << ".. ADDRS:  " << addr1 << " " << addr2 << " " << addr3 << " " << addr4 << std::endl;

	/*
	if (read1) addr1++;
	if (read2) addr2++;
	if (read3) addr3++;
	if (read4) addr4++;
	*/
	/*
	std::cout << "..VALIDS: " << valid1 << " " << valid2 << " " << valid3 << " " << valid4 << std::endl;
	std::cout << "..READS:  " << read1 << " " << read2 << " " << read3 << " " << read4 << std::endl;
	std::cout << "..ADDRS:  " << addr1 << " " << addr2 << " " << addr3 << " " << addr4 << std::endl;
	*/

	std::cout << ".. OUTPUT (@ mergetop)  : " << data_out.raw() << " " << valid_data_out << std::endl;

};



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
	)
{

	HLSCandidateMatch L1_1;
	HLSCandidateMatch L1_2;
	bool outread_L1_1 = false;
	bool outread_L1_2 = false;
	bool valid_L1_1   = false;
	bool valid_L1_2   = false;
	bool inread       = true;
	bool sA1 = false;
	bool sB1 = false;
	bool sA2 = false;
	bool sB2 = false;
	bool sA  = false;
	bool sB  = false;

	/*
	basicmerger(in1, valid1, outread1,
				in2, valid2, outread2,
				inread, out, validout);
	std::cout << "Readouts here: " << outread1 << " " << outread2 << std::endl;
	*/

	std::cout << "~~~~Merger1" << std::endl;
	cleanmerger(in1, valid1, outread1,
				in2, valid2, outread2,
				outread_L1_1, L1_1, valid_L1_1, sA1, sB1);
	std::cout << "~~~~Merger2" << std::endl;
	cleanmerger(in3, valid3, outread3,
				in4, valid4, outread4,
				outread_L1_2, L1_2, valid_L1_2, sA2, sB2);
	std::cout << "~~~~~~ FinalMerge" << std::endl;
	cleanmerger(L1_1, valid_L1_1, outread_L1_1,
				L1_2, valid_L1_2, outread_L1_2,
				inread, out, validout, sA, sB);

	std::cout << "~ output of 1 : " << L1_1.raw() << " " << valid_L1_1 << std::endl;
	std::cout << "~ output of 2 : " << L1_2.raw() << " " << valid_L1_2 << std::endl;
	std::cout << "~ OUTPUT (@ merge2lay) : " << out.raw() << " " << validout << std::endl;

};

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
	)
{

	std::cout << "---------- Inputs to merger ---------------" << std::endl;
	std::cout << "A (raw,valid,readout,sA): " << inA.raw() << " " << validA << " " << readoutA << " " << sA << std::endl;
	std::cout << "B (raw,valid,readout,sB): " << inB.raw() << " " << validB << " " << readoutB << " " << sB << std::endl;
	std::cout << "Out (inread,out,vout): " << inread    << " " << out.raw() << " " << vout << std::endl;

	ap_uint<3> state = 0;
	if (sA && (inread || !vout) ) state = 1;
	if (sB && (inread || !vout) ) state = 2;
	if ((!sA && !sB) && (validA || validB) && !vout) state = 3;
	if (!sB && !sA && vout && inread) state = 4;

	std::cout << "~State: " << state << std::endl;

	switch(state)
	{
	case(0):
		std::cout << "IF0" << std::endl;
		out = HLSCandidateMatch();
		vout = false;
		break;
	case(1):
		out  = inA;
		vout = validA;
		sA = ( (inA.GetPIndex() <= inB.GetPIndex())  || !validB ) && validA;
		sB = ( !(inA.GetPIndex() <= inB.GetPIndex()) || !validA ) && validB;
		std::cout << "IF1 (sA,sB,out,vout): " << sA << " " << sB << " " << out.raw() << " " << vout << std::endl;
		break;
	case(2):
		out  = inB;
		vout = validB;
		sB = ( (inB.GetPIndex() < inA.GetPIndex())  || !validA ) && validB;
		sA = ( !(inB.GetPIndex() < inA.GetPIndex()) || !validB ) && validA;
		std::cout << "IF2 (sA,sB,out,vout): " << sA << " " << sB << " " << out.raw() << " " << vout << std::endl;
		break;
	case(3):
		sA   = ( (inA.GetPIndex() <= inB.GetPIndex())  && validA && validB) || (!validB && validA);
		sB   = ( !(inA.GetPIndex() <= inB.GetPIndex()) && validA && validB) || (!validA && validB);
		std::cout << "IF3 (sA,sB,out,vout): " << sA << " " << sB << " " << out.raw() << " " << vout << std::endl;
		break;
	case(4):
		vout = false;
		out  = HLSCandidateMatch();
		std::cout << "IF4 (sA,sB,out,vout): " << sA << " " << sB << " " << out.raw() << " " << vout << std::endl;
		break;
	}

};


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
	)
{

	static bool vA = 0;
	static bool vB = 0;
	static bool sA = 0;
	static bool sB = 0;

	HLSCandidateMatch A;
	HLSCandidateMatch B;

	std::cout << "* bools: " << sA << " " << sB << " " << inread << " " << vout << std::endl;


	ap_uint<3> state = 0;
	if (sA && (inread || !vout))                     state = 1;
	if (sB && (inread || !vout))                     state = 2;
	if ((!sA && !sB) && (validA || validB) && !vout) state = 3;
	if (!sB && !sA && vout && inread)                state = 4;

	std::cout << "* STATE: " << state << std::endl;

	switch(state)
	{
		default :
			vA   = false;
			vB   = false;
			sA   = false;
			sB   = false;
			vout = false;
			out  = HLSCandidateMatch();
			break;
		case (0): // reset
			vA   = false;
			vB   = false;
			sA   = false;
			sB   = false;
			vout = false;
			out  = HLSCandidateMatch();
			break;
		case (1):
			A    = inA;
			vA   = validA;
			out  = A;
			vout = vA;
			sA = ( (A.GetPIndex() <= B.GetPIndex())  || !vB ) && validA;
			sB = ( !(A.GetPIndex() <= B.GetPIndex()) || !validA ) && vB;
			break;
		case (2):
			B    = inB;
			vB   = validB;
			out  = B;
			vout = vB;
			sB = ( (B.GetPIndex() < A.GetPIndex())  || !vA ) && validB;
			sA = ( !(B.GetPIndex() < A.GetPIndex()) || !validB ) && vA;
			break;
		case (3):
			A    = inA;
			vA   = validA;
			B    = inB;
			vB   = validB;
			sA   = ( (A.GetPIndex() <= B.GetPIndex())  && validA && validB) || (!validB && validA);
			sB   = ( !(A.GetPIndex() <= B.GetPIndex()) && validA && validB) || (!validA && validB);

			std::cout << "* At case 3: " << A.raw() << " " << vA << " " << B.raw() << " " << vB << " " << sA << " " << sB << std::endl;

			break;
		case (4):
			vout = false;
			out  = HLSCandidateMatch();
			break;
	}


	readoutA = (((inread || !vout) && sA) || !vA) && validA;
	readoutB = (((inread || !vout) && sB) || !vB) && validB;

	std::cout << "* Readouts : " << readoutA << " " << readoutB << std::endl;
	std::cout << "* OUTPUT (@  merger) : " << out.raw() << " " << vout << std::endl;

};


void merger(
		HLSCandidateMatch in1,   // input data1
		ap_uint<7> n1,           // number in input1
		ap_uint<7> & subindex1,  // read addr1
		HLSCandidateMatch in2,   // input data2
		ap_uint<7> n2,           // number in input2
		ap_uint<7> & subindex2,  // read addr2
		HLSCandidateMatch & out, // output data
		ap_uint<7> & nout        // number output
	)
{

	//#pragma HLS INLINE
#pragma HLS PIPELINE II=1
//#pragma HLS DATAFLOW

    HLSCandidateMatch a = in1;           // full data word from input 1
    HLSCandidateMatch b = in2;           // full data word from input 2
    CM_proj_index inA = in1.GetPIndex(); // part of input 1 word used for sorting
    CM_proj_index inB = in2.GetPIndex(); // part of input 2 word used for sorting

	// setup states in FSM
	ap_uint<3> state = 0;
	if (subindex1 >= n1 && subindex2 >= n2) state = 0; // BOTH DONE
	else if (subindex1 >= n1)               state = 1; // 1 DONE
	else if (subindex2 >= n2)               state = 2; // 2 DONE
	else if (inA <= inB)                    state = 3; // 1 SMALLER
	else if (inA > inB)                     state = 4; // 2 SMALLER
	else                                    state = 0; // CATCHALL

	// case statements
	switch(state)
	{
		case (0): // init or catchall or both done
			out = HLSCandidateMatch();
			break;
		case (1): // 1 done
			out = in2;
			subindex2++;
			nout++;
			break;
		case (2): // 2 done
			out = in1;
			subindex1++;
			nout++;
			break;
		case (3): // 1 smaller
			out = in1;
			subindex1++;
			nout++;
			break;
		case (4): // 2 smaller
			out = in2;
			subindex2++;
			nout++;
			break;
		default : // default
			out = HLSCandidateMatch();
			break;
	}
};

void stream_merger_v2(
	hls::stream< ap_uint<12> > &in1, // input stream 1
	hls::stream< ap_uint<12> > &in2, // input stream 2
	bool & read1,
	bool & read2,
	ap_uint<7> n1,                      // number of inputs in 1
	ap_uint<7> n2,                      // number of inputs in 2
	ap_uint<7> & subindex1,				// index of input 1
	ap_uint<7> & subindex2,				// index of input 2
	hls::stream< ap_uint<nBITS> > &out,  // merged output stream
	bool finallayer
	)
{

	ap_uint<7> n = n1 + n2;

	ap_uint<12> a = 0;
	ap_uint<12> b = 0;
	if (read1 && !in1.empty()){ std::cout << "Reading in 1" << std::endl; in1.read(a); }
	if (read2 && !in2.empty()){ std::cout << "Reading in 2" << std::endl; in2.read(b); }
	ap_uint<6> inA = a.range(11,6);
	ap_uint<6> inB = b.range(11,6);

	std::cout << "Data in : " << a << " " << inA << " , " << b << " " << inB << std::endl;

	// setup states in FSM
	ap_uint<3> state = 0;
	if (subindex1 >= n1 && subindex2 >= n2) state = 0; // BOTH DONE
	else if (subindex1 >= n1)               state = 1; // 1 DONE
	else if (subindex2 >= n2)               state = 2; // 2 DONE
	else if (inA <= inB)                    state = 3; // 1 SMALLER
	else if (inA > inB)                     state = 4; // 2 SMALLER
	else                                    state = 0; // CATCHALL

	if (state==0) std::cout << "State: " << state << " = Nothing to do " << std::endl;
	if (state==1) std::cout << "State: " << state << " = in1 is done " << std::endl;
	if (state==2) std::cout << "State: " << state << " = in2 is done " << std::endl;
	if (state==3) std::cout << "State: " << state << " = in1 is smaller " << std::endl;
	if (state==4) std::cout << "State: " << state << " = in2 is smaller " << std::endl;

	// case statements
	switch(state)
	{
	default:
		//out << 0;
		read1 = false;
		read2 = false;
		break;
	case (0): // catchall
		//out << 0;
		read1 = false;
		read2 = false;
		break;
	case (1): // 1 is done
		out << b;
		read1 = false;
		read2 = true;
		subindex2++;
		break;
	case (2): // 2 is done
		out << a;
		read1 = true;
		read2 = false;
		subindex1++;
		break;
	case (3): // 1 is smaller
		out << a;
		read1 = true;
		read2 = false;
		subindex1++;
		break;
	case (4): // 2 is smaller
		out << b;
		read1 = false;
		read2 = true;
		subindex2++;
		break;
	}

	if (!out.empty()) std::cout << "Output: " << out.read() << std::endl;
	else              std::cout << "Output: EMPTY" << std::endl;

};



void stream_merger(
    hls::stream< ap_uint<nBITS> > &in1, // input stream 1
    hls::stream< ap_uint<nBITS> > &in2, // input stream 2
    int n1,                             // number of inputs in 1
    int n2,                             // number of inputs in 2
    hls::stream< ap_uint<nBITS> > &out  // merged output stream
    )
{

	#pragma HLS PIPELINE II=1
	#pragma HLS DATAFLOW

    ap_uint<7> n = n1 + n2;   // total number of inputs
    ap_uint<12> a = 0;        // full data word from input 1
    ap_uint<12> b = 0;        // full data word from input 2
    ap_uint<6> inA = 0;       // part of input 1 word for comparison
    ap_uint<6> inB = 0;       // part of input 2 word for comparison
    ap_uint<7> subindex1 = 1; // counter for the reading of input 1
    ap_uint<7> subindex2 = 1; // counter for the reading of input 2

    bool read1 = true;
    bool read2 = true;

    // read inputs
    //if (!in1.empty()) in1.read_nb(a);
    //if (!in2.empty()) in2.read_nb(b);

    // loop up to max number allowed
    for (int i = 0; i < 37; i++) // need a fixed trip count
    {
	#pragma HLS PIPELINE II=1

    	    if (read1 && !in1.empty()) in1.read_nb(a);
    	    if (read2 && !in2.empty()) in2.read_nb(b);
			inA = a.range(11,6);
			inB = b.range(11,6);

			if (subindex1 > n1 && subindex2 > n2) // if read out everything
			{
				read1 = false;
				read2 = false;
				out.write_nb(0);
			}
			else if (subindex1 > n1) // if read out all of in1, only read in2
			{
				out.write_nb(b);
				read1 = false;
				read2 = true;
				//if (!in2.empty()) in2.read_nb(b);
				subindex2++;
			}
			else if (subindex2 > n2) // if read out all of in2, only read in1
			{
				out.write_nb(a);
				read1 = true;
				read2 = false;
				//if (!in1.empty()) in1.read_nb(a);
				subindex1++;
			}
			// if data in both in1 and in2, read smaller data first
			else if (inA <= inB) // a is smaller
			{
				out.write_nb(a);
				read1 = true;
				read2 = false;
				//if (!in1.empty()) in1.read_nb(a);
				subindex1++;
			}
			else if (inB <= inA)// b is smaller
			{
				out.write_nb(b);
				read1 = false;
				read2 = false;
				//if (!in2.empty()) in2.read_nb(b);
				subindex2++;
			}
			else // catchall
			{
				read1 = false;
				read2 = false;
				out.write_nb(0);
			}
    }// end for loop

};

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
		)
{

	#pragma HLS PIPELINE II=1

	ap_uint<7> addr1 = 0;
	ap_uint<7> addr2 = 0;
	ap_uint<7> addr3 = 0;
	ap_uint<7> addr4 = 0;

	ap_uint<12> dataout = -1;
	ap_uint<12> dumby   = -1;

	ap_uint<7> id[MAX_nCM];


	for (int i = 0; i < MAX_nCM; ++i)
	{

		if (i==0){ newtracklet = true; }
		else if (id[i]!=id[i-1]){ newtracklet = true; }
		else { newtracklet = false; }

		ap_uint<12> data1 = (addr1 < nin1) ? in1[addr1].raw() : dumby;
		ap_uint<12> data2 = (addr2 < nin2) ? in2[addr2].raw() : dumby;
		ap_uint<12> data3 = (addr3 < nin3) ? in3[addr3].raw() : dumby;
		ap_uint<12> data4 = (addr4 < nin4) ? in4[addr4].raw() : dumby;

		ap_uint<6> index1 = data1.range(11,6);
		ap_uint<6> index2 = data2.range(11,6);
		ap_uint<6> index3 = data3.range(11,6);
		ap_uint<6> index4 = data4.range(11,6);

		if (index1 <= index2 and index1 <= index3 and index1 <= index4){
			dataout = data1;
			addr1++;
		}
		else if (index2 <= index1 and index2 <= index3 and index2 <= index4){
			dataout = data2;
			addr2++;
		}
		else if (index3 <= index1 and index3 <= index2 and index3 <= index4){
			dataout = data3;
			addr3++;
		}
		else if (index4 <= index1 and index4 <= index2 and index4 <= index3){
			dataout = data4;
			addr4++;
		}
		else{
			dataout = -1;
		}

		id[i] = dataout.range(11,6);
		out.write_nb(dataout);
	}


};



