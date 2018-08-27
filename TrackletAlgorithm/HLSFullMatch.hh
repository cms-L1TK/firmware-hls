// HLSFullMatch class

#pragma once
#include "ap_int.h"

const int MAX_nFM = 5;  // max number of FMs that can be processed

const int nBITS_FM     = 40;
const int nBITS_FM_PID = 10; // 3b SEEDING + 7b INDEX
const int nBITS_FM_SID = 9;  // 2b ?? + 7b INDEX
const int nBITS_FM_PHI = 12;
const int nBITS_FM_Z   = 9;

typedef ap_uint<nBITS_FM>	    FullMatch;		// unsigned
typedef ap_uint<nBITS_FM_PID>   FM_PROJ_INDEX;	// unsigned
typedef ap_uint<nBITS_FM_SID>   FM_STUB_INDEX;	// unsigned
typedef ap_int<nBITS_FM_PHI>    FM_PHI;			// signed
typedef ap_int<nBITS_FM_Z>      FM_Z;			// signed

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
		std::cout << " FM : " << newphi << " " << newz <<  " " << std::endl;

		// setup full stub data by concatenating variables above
		// data_ = {proj index, stub index, phi residual, z residual}
		// need "to_long" for shifts otherwise data will truncate at current size
		data_   = (((newpindex.to_long() << (nBITS_FM_SID + nBITS_FM_PHI + nBITS_FM_Z) ) |
				  (newsindex.to_long()   << (nBITS_FM_PHI + nBITS_FM_Z) ) |
				  (newphi.to_long()      << (nBITS_FM_Z) ) |
				  (newz))
				  & ((1<<nBITS_FM)-1)); // protect to keep length at nBITS_FM
	}

	// other functions
	FullMatch raw() const
	{
		return data_;
	}

	FM_PROJ_INDEX GetPIndex() const
	{
		FM_PROJ_INDEX pid = ((data_ >> (nBITS_FM_SID+nBITS_FM_PHI+nBITS_FM_Z)) & 0x3FFUL);
		return pid;
	}
	FM_STUB_INDEX GetSIndex() const
	{
		FM_STUB_INDEX sid = ((data_ >> (nBITS_FM_PHI+nBITS_FM_Z)) & 0x1FFUL);
		return sid;
	}
	FM_PHI GetPhi() const
	{
		FM_PHI phi = ((data_ >> (nBITS_FM_Z)) & 0xFFFUL);
		return phi;
	}
	FM_Z GetZ() const
	{
		FM_Z z = (data_ & 0x1FFUL);
		return z;
	}

};
