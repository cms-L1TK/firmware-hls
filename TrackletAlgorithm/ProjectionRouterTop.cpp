#include "ProjectionRouterTop.h"

void ProjectionRouterTop(BXType bx,
                         TrackletProjectionMemory *const tproj1,
                         TrackletProjectionMemory *const tproj2,
                         TrackletProjectionMemory *const tproj3,
                         TrackletProjectionMemory *const tproj4,
                         TrackletProjectionMemory *const tproj5,
                         TrackletProjectionMemory *const tproj6,
                         //TrackletProjectionMemory *const tproj7,
                         //TrackletProjectionMemory *const tproj8,
                         BXType& bx_o,
                         AllProjectionMemory *const allproj,
                         VMProjectionMemory *const vmproj1,
                         VMProjectionMemory *const vmproj2,
                         VMProjectionMemory *const vmproj3,
                         VMProjectionMemory *const vmproj4
                         )
{
  // Instantiation of one ProjectionRouter
  ProjectionRouter<6>(bx,
                      tproj1, tproj2, tproj3, tproj4, tproj5, tproj6, 0, 0,
                      bx_o,
                      allproj, vmproj1, vmproj2, vmproj3, vmproj4);
}
