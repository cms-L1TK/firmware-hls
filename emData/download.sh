#!/usr/bin/env bash

# fw_synch_200515
memprints_url="https://cernbox.cern.ch/index.php/s/QvV86Qcc8n9R4sg/download"
luts_url="https://cernbox.cern.ch/index.php/s/YSER9ne7WVxiKXI/download"

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # VMRouter
  "VMR_L1PHIE"
  "VMR_D1PHIA"

  # TrackletEngine
  "TE_L1PHIE18_L2PHIC17"

  # TrackletCalculator
  "TC_L1L2E"
  "TC_L1L2G"
  "TC_L3L4E"
  "TC_L5L6D"

  # ProjectionRouter
  "PR_L3PHIC"

  # MatchEngine
  "ME_L1PHIE20"
  "ME_L3PHIC20"
  "ME_L4PHIB12"

  # MatchCalculator
  "MC_L1PHIC"
  "MC_L2PHIC"
  "MC_L3PHIC"
  "MC_L4PHIC"
  "MC_L5PHIC"
  "MC_L6PHIC"
)

# Function that prints information regarding the usage of this command
function usage() {
  echo "$(basename $0) [-h|--help] [-t|--tables]"
  echo ""
  echo "Without any options, downloads and unpacks MemPrints.tar.gz and LUTs.tar.gz."
  echo "MemPrints.tar.gz contains test vectors produced by the emulation, and"
  echo "LUTs.tar.gz contains lookup tables and other small miscellaneous files."
  echo ""
  echo "Options:"
  echo "  -h, --help    show this help message and exit"
  echo "  -t, --tables  download and unpack only LUTs.tar.gz"
}

# Parse the command line options.
tables_only=0
while [[ $1 != "" ]]
do
  case $1 in
    -t | --tables )  tables_only=1
                     ;;
    -h | --help )    usage
                     exit
                     ;;
    * )              usage
                     exit 1
  esac
  shift
done

# If either the MemPrints or the LUTs directory exists, assume the script has
# already been run, and simply exit.
if [ -d "MemPrints" ] || [ -d "LUTs" ]
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

# Download and unpack LUTs.tar.gz.
wget -O LUTs.tar.gz --quiet ${luts_url}
tar -xzf LUTs.tar.gz
rm -f LUTs.tar.gz

# Exit now if we are only downloading and unpacking LUTs.tar.gz.
if [[ $tables_only != 0 ]]
then
  exit 0
fi

# Download and unpack MemPrints.tar.gz.
wget -O MemPrints.tar.gz --quiet ${memprints_url}
tar -xzf MemPrints.tar.gz
rm -f MemPrints.tar.gz

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  target_dir=${module_type}/${module}

  rm -rf ${target_dir}
  mkdir -p ${target_dir}
  for mem in `grep "${module}\." wires_hourglass.dat | awk '{print $1}' | sort -u`;
  do
    find MemPrints/ -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
  done

  # Table linking logic specific to each module type
  table_location="LUTs/"
  table_target_dir="${module_type}/tables"
  if [[ ! -d "${table_target_dir}" ]]
  then
          mkdir -p ${table_target_dir}
  fi

  if [[ ${module_type} == "TC" ]]
  then
          layer_pair=`echo ${module} | sed "s/\(.*\)./\1/g"`
          find ${table_location} -type f -name "${layer_pair}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "ME" ]]
  then
          layer=`echo ${module} | sed "s/.*_\(L[1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MC" ]] || [[ ${module_type} == "TE" ]]
  then
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "VMR" ]]
  then
          layer=`echo ${module} | sed "s/VMR_\(..\).*/\1/g"`
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "VM*${layer}*" ! -name "*PHI*" -exec ln -sf ../../{} ${table_target_dir}/ \;
          for mem in `grep "${module}\." wires_hourglass.dat | awk '{print $1}' | sort -u`;
          do
            find ${table_location} -type f -name "${mem}*.tab" -exec ln -s ../../{} ${table_target_dir}/ \;
          done
  fi
done
