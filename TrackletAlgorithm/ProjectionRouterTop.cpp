#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory* const tproj1,
                         const TrackletProjectionMemory* const tproj2,
                         const TrackletProjectionMemory* const tproj3,
                         const TrackletProjectionMemory* const tproj4,
                         const TrackletProjectionMemory* const tproj5,
                         const TrackletProjectionMemory* const tproj6,
                         //const TrackletProjectionMemory* const tproj7,
                         //const TrackletProjectionMemory* const tproj8,
                         BXType& bx_o,
                         AllProjectionMemory* const allproj,
                         VMProjectionMemory* const vmproj1,
                         VMProjectionMemory* const vmproj2,
                         VMProjectionMemory* const vmproj3,
                         VMProjectionMemory* const vmproj4
                         )
{
  // Instantiation of one ProjectionRouter
  ProjectionRouter<6>(bx,
                      tproj1, tproj2, tproj3, tproj4, tproj5, tproj6, 0, 0,
                      bx_o,
                      allproj, vmproj1, vmproj2, vmproj3, vmproj4);
}
