#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<BARRELPS> projin[8],
                         BXType& bx_o,
                         AllProjectionMemory<BARRELPS>* allprojout,
                         VMProjectionMemory<BARREL>* vmprojout1,
                         VMProjectionMemory<BARREL>* vmprojout2,
                         VMProjectionMemory<BARREL>* vmprojout3,
                         VMProjectionMemory<BARREL>* vmprojout4,
                         VMProjectionMemory<BARREL>* vmprojout5,
                         VMProjectionMemory<BARREL>* vmprojout6,
                         VMProjectionMemory<BARREL>* vmprojout7,
                         VMProjectionMemory<BARREL>* vmprojout8
                         )
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
  // PR_L3PHIC
 PR_L3PHIC: ProjectionRouter<BARRELPS, BARREL, 8, 3, 0>
    (bx,
     projin, bx_o, allprojout, vmprojout1, vmprojout2, vmprojout3, vmprojout4, vmprojout5, vmprojout6, vmprojout7, vmprojout8
     );
}
