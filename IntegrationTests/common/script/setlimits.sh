#!/usr/bin/env bash

# Increase soft limit on number of open files to 4096 for parent (vivado),
# grandparent (loader), and great grandparent (vivado)
PPPID=`ps -o ppid= $PPID`
PPPPID=`ps -o ppid= $PPPID`
prlimit --pid $PPID --nofile=4096:
prlimit --pid $PPPID --nofile=4096:
prlimit --pid $PPPPID --nofile=4096:
