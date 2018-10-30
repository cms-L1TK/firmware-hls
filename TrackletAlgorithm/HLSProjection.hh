// HLSProjection class

#pragma once
#include "ap_int.h"

const int MAX_nPROJ = 36;
const int nBITS_PROJ = 60;

// THESE ARE OLD DEFINITIONS OF TRACKLET PROJECTION
// bit size will change in new version but consistent with the input data at the time
// (ie. that of the current test bench)

const int nBITS_PROJ_TCID = 6;  // bits for tracket ID           -- think this should be 7 bits in new proj format
const int nBITS_PROJ_NUM  = 7;  // bits for tracklet number
const int nBITS_PROJ_PHI  = 14; // bits for phi
const int nBITS_PROJ_Z    = 12; // bits for z
const int nBITS_PROJ_PHID = 11; // bits for phi derivative       -- think this should be 10 bits in new proj format
const int nBITS_PROJ_ZD   = 10; // bits for z derivative

const int kLSB_PROJ_ZD   = 0;
const int kMSB_PROJ_ZD   = nBITS_PROJ_ZD-1;
const int kLSB_PROJ_PHID = kMSB_PROJ_ZD+1;
const int kMSB_PROJ_PHID = kLSB_PROJ_PHID+nBITS_PROJ_PHID-1;
const int kLSB_PROJ_Z    = kMSB_PROJ_PHID+1;
const int kMSB_PROJ_Z    = kLSB_PROJ_Z+nBITS_PROJ_Z-1;
const int kLSB_PROJ_PHI  = kMSB_PROJ_Z+1;
const int kMSB_PROJ_PHI  = kLSB_PROJ_PHI+nBITS_PROJ_PHI-1;
const int kLSB_PROJ_NUM  = kMSB_PROJ_PHI+1;
const int kMSB_PROJ_NUM  = kLSB_PROJ_NUM+nBITS_PROJ_NUM-1;
const int kLSB_PROJ_TCID = kMSB_PROJ_NUM+1;
const int kMSB_PROJ_TCID = kLSB_PROJ_TCID+nBITS_PROJ_TCID-1;

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
	HLSProjection(PROJ_TCID id, PROJ_TCNUM num, PROJ_PHI phi, PROJ_Z z, PROJ_PHID phid, PROJ_ZD zd)
	{
		data_ = (((((id,num),phi),z),phid),zd);
	}

	// Getters
	Projection raw() const { return data_; }
	PROJ_TCID  GetTCID() const { return data_.range(kMSB_PROJ_TCID,kLSB_PROJ_TCID); }
	PROJ_TCNUM GetIndex() const { return data_.range(kMSB_PROJ_NUM,kLSB_PROJ_NUM); }
	PROJ_PHI   GetPhi() const { return data_.range(kMSB_PROJ_PHI,kLSB_PROJ_PHI); }
	PROJ_Z     GetZ() const { return data_.range(kMSB_PROJ_Z,kLSB_PROJ_Z); }
	PROJ_PHID  GetPhiDeriv() const { return data_.range(kMSB_PROJ_PHID,kLSB_PROJ_PHID); }
	PROJ_ZD    GetZDeriv() const { return data_.range(kMSB_PROJ_ZD,kLSB_PROJ_ZD); }

	// Setters
	Projection AddProj(Projection newdata){ data_ = newdata; }


};
