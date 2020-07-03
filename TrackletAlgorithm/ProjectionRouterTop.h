#ifndef TrackletAlgorithm_ProjectionRouterTop_h
#define TrackletAlgorithm_ProjectionRouterTop_h

#include "ProjectionRouter.h"

void ProjectionRouterTop(BXType bx,
                         const TrackletProjectionMemory<BARRELPS> projin[8],
                         BXType&,
                         AllProjectionMemory<BARRELPS>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*,
                         VMProjectionMemory<BARREL>*
                         );

#endif
