// HLSFullMatch class

#pragma once
#include "ap_int.h"

const int MAX_nFM = 5;  // max number of FMs that can be processed

const int nBITS_FM     = 42;
const int nBITS_FM_ID  = 6;
const int nBITS_FM_PHI = 12;
const int nBITS_FM_Z   = 9;

typedef ap_uint<nBITS_FM>	    FullMatch;
typedef ap_uint<nBITS_FM_ID>    FM_PROJ_INDEX;
typedef ap_uint<nBITS_FM_ID>    FM_STUB_INDEX;
typedef ap_uint<nBITS_FM_PHI>   FM_PHI;
typedef ap_uint<nBITS_FM_Z>     FM_Z;

class HLSFullMatch
{
private:
	FullMatch 		data_;
	FM_PROJ_INDEX	p_index;
	FM_STUB_INDEX	s_index;
	FM_PHI			FM_phi;
	FM_Z			FM_z;

public:
	// constructors
	HLSFullMatch(FullMatch newdata):
		data_(newdata)
	{
	}
	HLSFullMatch():
		data_(0)
	{
	}
	HLSFullMatch(const FM_PROJ_INDEX newpindex, const FM_STUB_INDEX newsindex,
				 const FM_PHI        newphi,    const FM_Z newz)
	{
		AddFM(newpindex,newsindex,newphi,newz);
	}
	
	void AddFM(const FullMatch newdata)
	{
		data_ = newdata;
	}
	void AddFM(const FM_PROJ_INDEX newpindex, const FM_STUB_INDEX newsindex,
			   const FM_PHI        newphi,    const FM_Z newz)
	{
		p_index = newpindex;
		s_index = newsindex;
		FM_phi  = newphi;
		FM_z    = newz;
		// setup full stub data by concatenating variables above
		// data_ = {proj index, stub index, phi residual, z residual}
		// need "to_long" for shifts otherwise data will truncate at current size
		data_   = (((newpindex.to_long() << (nBITS_FM_ID + nBITS_FM_PHI + nBITS_FM_Z -1) ) |
				  (newsindex.to_long() << (nBITS_FM_PHI + nBITS_FM_Z -1) ) |
				  (newphi.to_long() << (nBITS_FM_Z -1) ) |
				  (newz))
				  & ((1<<nBITS_FM)-1)); // protect to keep length at nBITS_FM
	}

	// other functions
	FullMatch raw() const
	{
		return data_;
	}

};
