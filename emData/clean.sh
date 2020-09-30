#!/usr/bin/env bash

# Exit with an error message if run from a directory other than emData/.
cwd=`pwd | xargs basename`
if [[ $cwd != "emData" ]]
then
  echo "Must be run from emData directory."
  exit 1
fi

# Remove everything except download.sh and clean.sh.
find -mindepth 1 -maxdepth 1 \
  ! -regex "^\.\/download\.sh$" \
  ! -regex "^\.\/clean\.sh$" \
  ! -regex "^\.\/dtclinklayerdisk\.dat$" 
  -exec rm -rfv {} \;
