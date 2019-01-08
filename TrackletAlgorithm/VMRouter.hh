// VMRouter
// Log
// -------

// First tracklet 2.0 version -- December 2018 -- wittich

#pragma once
#include "ap_int.h"

#include "InputStubMemory.hh"
#include "AllStubMemory.hh"
#include "VMStubMEMemory.hh"
#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"

void VMRouter(
		const int layer_, const int disk_, const bool isPSmodule,
		const BXType bx,
		const InputStubMemory* const a0,
		const InputStubMemory* const a1,
		const InputStubMemory* const a2,
		const InputStubMemory* const a3,
		const InputStubMemory* const a4,
		AllStubMemory* allstub,
		VMStubMEMemory *m0,
		VMStubMEMemory *m1,
		VMStubMEMemory *m2,
		VMStubMEMemory *m3,
		VMStubMEMemory *m4,
		VMStubMEMemory *m5,
		VMStubMEMemory *m6,
		VMStubMEMemory *m7);
