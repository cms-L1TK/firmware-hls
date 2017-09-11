#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /mnt/scratch/djc448/firmware-hls/project/vmrouter_2/solution2-nodependencies/.autopilot/db/a.g.bc ${1+"$@"}
