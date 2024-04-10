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
  ! -regex "^\.\/generate_[A-Z]*\.py$" \
  ! -regex "^\.\/project_generation_scripts$" \
  ! -regex "^\.\/FPGA2_Config$" \
    -exec rm -rfv {} \;
  #! -regex "^\.\/dtclinklayerdisk\.dat$" \

# Remove everything in TopFunctions/, then restore the static top files
# currently in the repo.
rm -rfv ../TopFunctions/*
git checkout -- ../TopFunctions

# Remove all automatically generated files in IntegrationTests/.
find ../IntegrationTests/ -type f \( \
     -regex "^.*\/SectorProcessor\.vhd$" \
  -o -regex "^.*\/SectorProcessorFull\.vhd$" \
  -o -regex "^.*\/memUtil_pkg\.vhd$" \
  -o -regex "^.*\/tb_tf_top\.vhd$" \
  \) -exec rm -fv {} \;
