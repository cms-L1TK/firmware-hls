//
// HLSAllStubs class
//
// Contains AllStub definition
// currently assuming Layer 1-3 format
//
#pragma once
#include "ap_int.h"

const int MAX_nSTUB   = 5;

const int nBITS_STUB  = 36;
const int nBITS_R     = 7;
const int nBITS_Z	  = 12;
const int nBITS_PHI   = 14;
const int nBITS_BEND  = 3;

// Raw all stub width
typedef ap_uint<nBITS_STUB> AllStub;

// Define bit width for all stub memories
typedef ap_int<nBITS_R>			AS_r;         // signed
typedef ap_int<nBITS_Z>			AS_z;         // signed
typedef ap_uint<nBITS_PHI>		AS_phi;       // unsigned
typedef ap_uint<nBITS_BEND> 	AS_bend;      // unsigned

class HLSAllStubs
{
private: 
	AllStub		data_;
	AS_r		stub_r;
	AS_z		stub_z;
	AS_phi		stub_phi;
	AS_bend		stub_bend;
	
public:
	// constructors
	HLSAllStubs(AllStub newdata):
		data_(newdata)
	{
	}
	HLSAllStubs():
		data_(0)
	{
		stub_r    = 0;
		stub_z    = 0;
		stub_phi  = 0;
		stub_bend = 0;
	}
	HLSAllStubs(const AS_r   new_stub_r,   const AS_z    new_stub_z,
			    const AS_phi new_stub_phi, const AS_bend new_stub_bend)
	{
		AddStub(new_stub_r,new_stub_z,new_stub_phi,new_stub_bend);
	}

	// other functions

	// return the raw stub
	AllStub raw() const
	{
		return data_;
	}
	// return values
	AS_r GetR() const
	{
		AS_r r = ((data_ >> (nBITS_Z+nBITS_PHI+nBITS_BEND)) & 0x7FUL);//((1<<nBITS_R-1)-1));
		return r;
	}
	AS_z GetZ() const
	{
		AS_z z = ((data_ >> (nBITS_PHI+nBITS_BEND)) & 0xFFFUL); //((1<<nBITS_Z-1)-1));
		return z;

	}
	AS_phi GetPhi() const
	{
		AS_phi phi = ((data_ >> nBITS_BEND) & 0x3FFFUL);//((1<<nBITS_PHI)-1));
		return phi;
	}
	AS_bend GetBend() const
	{
		AS_bend bend = (data_ & 0x7UL); //(data_ & ((1 << nBITS_BEND)-1));
		return bend;
	}

	// construct a stub
	void AddStub(const AllStub newStub)
	{
		data_ = newStub;
	}
	void AddStub(const AS_r   new_stub_r,   const AS_z    new_stub_z,
				 const AS_phi new_stub_phi, const AS_bend new_stub_bend)
	{
		stub_r    = new_stub_r;
		stub_z    = new_stub_z;
		stub_phi  = new_stub_phi;
		stub_bend = new_stub_bend;
		// setup full stub data by concatenating variables above
		// data_ = {r, z, phi, bend}
		// need "to_long" for shifts otherwise data will truncate at current size
		data_     = (((new_stub_r.to_long()  << (nBITS_Z + nBITS_PHI + nBITS_BEND -1)) |
					 (new_stub_z.to_long()   << (nBITS_PHI + nBITS_BEND -1)) |
					 (new_stub_phi.to_long() << (nBITS_BEND -1)) |
					 (new_stub_bend))
					 & ((1<<nBITS_STUB)-1));  // protect to keep length at nBITS_STUB
	}

};
