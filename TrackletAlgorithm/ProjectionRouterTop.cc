#include "ProjectionRouterTop.h"

void ProjectionRouterTop_L3PHIC(BXType bx,
                         const TrackletProjectionMemory<BARRELPS> projin[8],
                         BXType& bx_o,
                         AllProjectionMemory<BARRELPS>& allprojout,
                         VMProjectionMemory<BARREL> vmprojout[8])
{
 #pragma HLS inline off
 #pragma HLS interface register port=bx_o
 #pragma HLS resource variable=projin[0]->get_mem() latency=2
 #pragma HLS resource variable=projin[1]->get_mem() latency=2
 #pragma HLS resource variable=projin[2]->get_mem() latency=2
 #pragma HLS resource variable=projin[3]->get_mem() latency=2
 #pragma HLS resource variable=projin[4]->get_mem() latency=2
 #pragma HLS resource variable=projin[5]->get_mem() latency=2
 #pragma HLS resource variable=projin[6]->get_mem() latency=2
 #pragma HLS resource variable=projin[7]->get_mem() latency=2
 // Constants specific to PR_L3PHIC
 constexpr unsigned int nInMem = 8;
 constexpr unsigned int nOutMem = 8;
 constexpr int layer = 3;
 constexpr int disk = 0;
 PR_L3PHIC: ProjectionRouter<BARRELPS, BARREL, nInMem, nOutMem, layer, disk>
    (bx, projin, bx_o, allprojout, vmprojout);
}
