// HLSProjection class

#pragma once
#include "ap_int.h"

const int MAX_nPROJ = 5;
const int nBITS_PROJ = 56;

const int nBITS_PROJ_TCID = 6;  // bits for tracket ID
const int nBITS_PROJ_NUM  = 6;  // bits for tracklet number
const int nBITS_PROJ_PHI  = 14; // bits for phi
const int nBITS_PROJ_Z    = 12; // bits for z
const int nBITS_PROJ_PHID = 11; // bits for phi derivative
const int nBITS_PROJ_ZD   = 10; // bits for z derivative

// defintion of raw projection
typedef ap_uint<nBITS_PROJ> Projection;

// define bit width for projection variables
typedef ap_uint<nBITS_PROJ_TCID> PROJ_TCID;		// unsigned
typedef ap_uint<nBITS_PROJ_NUM>  PROJ_TCNUM;	// unsigned
typedef ap_uint<nBITS_PROJ_PHI>  PROJ_PHI;		// unsigned
typedef ap_int<nBITS_PROJ_Z>     PROJ_Z;		// signed
typedef ap_int<nBITS_PROJ_PHID>  PROJ_PHID;		// signed
typedef ap_int<nBITS_PROJ_ZD>    PROJ_ZD;		// signed

class HLSProjection
{
private:
	Projection data_;
	PROJ_TCID  tcid;
	PROJ_TCNUM tcnum;
	PROJ_PHI   proj_phi;
	PROJ_Z     proj_z;
	PROJ_PHID  proj_phid;
	PROJ_ZD    proj_zd;

public:
	// constructors
	HLSProjection(Projection newdata):
		data_(newdata)
	{
	}
	HLSProjection():
		data_(0)
	{
	}
	
	// other functions

	// build up projection
	void AddProj(const Projection newproj)
	{
		data_ = newproj;
	}
	
	// return raw values
	Projection raw() const
	{
		return data_;
	}

	PROJ_PHI GetPhi() const
	{
		PROJ_PHI phi = ((data_ >> (nBITS_PROJ_ZD+nBITS_PROJ_PHID+nBITS_PROJ_Z)) & 0x3FFFUL);
		return phi;
	}
	PROJ_Z GetZ() const
	{
		PROJ_Z z = ((data_ >> (nBITS_PROJ_ZD+nBITS_PROJ_PHID)) & 0xFFFUL);
		return z;
	}
	PROJ_PHID GetPhiDeriv() const
	{
		PROJ_PHID phid = ((data_ >> (nBITS_PROJ_ZD)) & 0x7FFUL);
		return phid;
	}
	PROJ_ZD GetZDeriv() const
	{
		PROJ_ZD zd = (data_ & 0x3FFUL);
		return zd;
	}

};
