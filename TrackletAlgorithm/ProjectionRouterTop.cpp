#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<BARRELPS>* proj1in,
                         const TrackletProjectionMemory<BARRELPS>* proj2in,
                         const TrackletProjectionMemory<BARRELPS>* proj3in,
                         const TrackletProjectionMemory<BARRELPS>* proj4in,
                         const TrackletProjectionMemory<BARRELPS>* proj5in,
                         const TrackletProjectionMemory<BARRELPS>* proj6in,
                         const TrackletProjectionMemory<BARRELPS>* proj7in,
                         const TrackletProjectionMemory<BARRELPS>* proj8in,
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
 #pragma HLS resource variable=proj1in latency=2
 #pragma HLS resource variable=proj2in latency=2
 #pragma HLS resource variable=proj3in latency=2
 #pragma HLS resource variable=proj4in latency=2
 #pragma HLS resource variable=proj5in latency=2
 #pragma HLS resource variable=proj6in latency=2
 #pragma HLS resource variable=proj7in latency=2
 #pragma HLS resource variable=proj8in latency=2
  // PR_L3PHIC
 PR_L3PHIC: ProjectionRouter<BARRELPS, BARREL, 8, 3, 0>
    (bx,
     proj1in, proj2in, proj3in, proj4in, proj5in, proj6in, proj7in, proj8in,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     bx_o,
     allprojout,
     vmprojout1, vmprojout2, vmprojout3, vmprojout4, vmprojout5, vmprojout6, vmprojout7, vmprojout8
     );
}
