#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /mnt/data1/jf847/firmware-hls/project/trackletProcessor/solution1/.autopilot/db/a.g.bc ${1+"$@"}
