// HLSFullMatch class

#pragma once
#include "ap_int.h"

const int MAX_nFM = 36;  // max number of FMs that can be processed

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
		// setup full stub data by concatenating variables above
		// data_ = {proj index, stub index, phi residual, z residual}
		data_   = (((newpindex,newsindex),newphi),newz);
	}

	// other functions
	FullMatch raw() const
	{
		return data_;
	}

	FM_PROJ_INDEX GetPIndex() const
	{
		FM_PROJ_INDEX pid = data_.range(39,30);
		return pid;
	}
	FM_STUB_INDEX GetSIndex() const
	{
		FM_STUB_INDEX sid = data_.range(29,21);
		return sid;
	}
	FM_PHI GetPhi() const
	{
		FM_PHI phi = data_.range(20,9);
		return phi;
	}
	FM_Z GetZ() const
	{
		FM_Z z = data_.range(8,0);
		return z;
	}

};
