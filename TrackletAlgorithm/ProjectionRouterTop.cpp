#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<BARRELPS>* tproj1,
                         const TrackletProjectionMemory<BARRELPS>* tproj2,
                         const TrackletProjectionMemory<BARRELPS>* tproj3,
                         const TrackletProjectionMemory<BARRELPS>* tproj4,
                         const TrackletProjectionMemory<BARRELPS>* tproj5,
                         const TrackletProjectionMemory<BARRELPS>* tproj6,
                         const TrackletProjectionMemory<BARRELPS>* tproj7,
                         const TrackletProjectionMemory<BARRELPS>* tproj8,
                         BXType& bx_o,
                         AllProjectionMemory<BARRELPS>* allproj,
                         VMProjectionMemory<BARREL>* vmproj1,
                         VMProjectionMemory<BARREL>* vmproj2,
                         VMProjectionMemory<BARREL>* vmproj3,
                         VMProjectionMemory<BARREL>* vmproj4,
                         VMProjectionMemory<BARREL>* vmproj5,
                         VMProjectionMemory<BARREL>* vmproj6,
                         VMProjectionMemory<BARREL>* vmproj7,
                         VMProjectionMemory<BARREL>* vmproj8
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
