#!/usr/bin/env bash

# fw_synch_200515
tarball_url="https://cernbox.cern.ch/index.php/s/CipX7CfTXIj1lcK/download"

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # VMRouter
  "VMR_L1PHIE"

  # TrackletEngine
  "TE_L1PHIE18_L2PHIC17"

  # TrackletCalculator
  "TC_L1L2E"
  "TC_L1L2G"
  "TC_L3L4E"

  # ProjectionRouter
  "PR_L3PHIC"

  # MatchEngine
  "ME_L1PHIE20"
  "ME_L3PHIC20"
  "ME_L4PHIB12"

  # MatchCalculator
  "MC_L1PHIC"
  "MC_L3PHIC"
)

# If the MemPrints directory exists, assume the script has already been run,
# and simply exit.
if [ -d "MemPrints" ]
then
  exit 0
fi

# Exit with an error message if run from a directory other than emData/.
cwd=`pwd | xargs basename`
if [[ $cwd != "emData" ]]
then
  echo "Must be run from emData directory."
  exit 1
fi

# Download and unpack the tarball.
wget -O MemPrints.tar.gz --verbose "https://cernbox.cern.ch/index.php/s/CipX7CfTXIj1lcK/download"
tar -xzvf MemPrints.tar.gz
rm -fv MemPrints.tar.gz

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  target_dir=${module_type}/${module}

  rm -rfv ${target_dir}
  mkdir -pv ${target_dir}
  for mem in `grep "${module}\." wires_hourglass.dat | awk '{print $1}' | sort -u`;
  do
    find MemPrints/ -type f -regex ".*_${mem}_04\.dat$" -exec ln -sv ../../{} ${target_dir}/ \;
  done
done
