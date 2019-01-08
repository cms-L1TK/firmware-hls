#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<INNER>* const tproj1,
                         const TrackletProjectionMemory<INNER>* const tproj2,
                         const TrackletProjectionMemory<INNER>* const tproj3,
                         const TrackletProjectionMemory<INNER>* const tproj4,
                         const TrackletProjectionMemory<INNER>* const tproj5,
                         const TrackletProjectionMemory<INNER>* const tproj6,
                         const TrackletProjectionMemory<INNER>* const tproj7,
                         const TrackletProjectionMemory<INNER>* const tproj8,
                         BXType& bx_o,
                         AllProjectionMemory* const allproj,
                         VMProjectionMemory* const vmproj1,
                         VMProjectionMemory* const vmproj2,
                         VMProjectionMemory* const vmproj3,
                         VMProjectionMemory* const vmproj4,
                         VMProjectionMemory* const vmproj5,
                         VMProjectionMemory* const vmproj6,
                         VMProjectionMemory* const vmproj7,
                         VMProjectionMemory* const vmproj8
                         )
{
  // PR_L3PHIC
 PR_L3PHIC: ProjectionRouter<TrackletProjectionMemory<INNER>, AllProjectionMemory,
                             VMProjectionMemory, TrackletProjection<INNER>,
                             AllProjection, VMProjection, 8, 3, 0>
    (bx,
     tproj1, tproj2, tproj3, tproj4, tproj5, tproj6, tproj7, tproj8,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     bx_o,
     allproj,
     vmproj1, vmproj2, vmproj3, vmproj4, vmproj5, vmproj6, vmproj7, vmproj8
     );
}
