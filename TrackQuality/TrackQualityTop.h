#ifndef TrackQuality_TrackQuality_H_
#define TrackQuality_TrackQuality_H_

#include "BDT.h"
#include "parameters.h"
#include "TrackQualityMemory.h"


// Prototype of top level function for C-synthesis
void TrackQualityTop(
	const TTTrack& Track,
	score_arr_t score,
	score_t tree_scores[BDT::fn_classes(n_classes) * n_trees]);
#endif
