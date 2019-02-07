#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<BARRELPS>* const tproj1,
                         const TrackletProjectionMemory<BARRELPS>* const tproj2,
                         const TrackletProjectionMemory<BARRELPS>* const tproj3,
                         const TrackletProjectionMemory<BARRELPS>* const tproj4,
                         const TrackletProjectionMemory<BARRELPS>* const tproj5,
                         const TrackletProjectionMemory<BARRELPS>* const tproj6,
                         const TrackletProjectionMemory<BARRELPS>* const tproj7,
                         const TrackletProjectionMemory<BARRELPS>* const tproj8,
                         BXType& bx_o,
                         AllProjectionMemory<BARRELPS>* const allproj,
                         VMProjectionMemory<BARREL>* const vmproj1,
                         VMProjectionMemory<BARREL>* const vmproj2,
                         VMProjectionMemory<BARREL>* const vmproj3,
                         VMProjectionMemory<BARREL>* const vmproj4,
                         VMProjectionMemory<BARREL>* const vmproj5,
                         VMProjectionMemory<BARREL>* const vmproj6,
                         VMProjectionMemory<BARREL>* const vmproj7,
                         VMProjectionMemory<BARREL>* const vmproj8
                         )
{
  // PR_L3PHIC
 PR_L3PHIC: ProjectionRouter<BARRELPS, BARREL, 8, 3, 0>
    (bx,
     tproj1, tproj2, tproj3, tproj4, tproj5, tproj6, tproj7, tproj8,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     bx_o,
     allproj,
     vmproj1, vmproj2, vmproj3, vmproj4, vmproj5, vmproj6, vmproj7, vmproj8
     );
}
