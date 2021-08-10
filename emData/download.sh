#!/usr/bin/env bash

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # VMRouter
  "VMR_L1PHID"
  "VMR_L2PHIA"
  "VMR_L2PHIB"
  "VMR_L3PHIA"
  "VMR_L4PHIA"
  "VMR_L5PHIA"
  "VMR_L6PHIA"
  "VMR_D1PHIA"
  "VMR_D2PHIA"
  "VMR_D3PHIA"
  "VMR_D4PHIA"
  "VMR_D5PHIA"

  # VMRouter CM
  "VMRCM_L1PHIA"
  "VMRCM_L2PHIA"
  "VMRCM_L3PHIA"
  "VMRCM_L4PHIA"
  "VMRCM_L5PHIA"
  "VMRCM_L6PHIA"
  "VMRCM_D1PHIA"
  "VMRCM_D2PHIA"
  "VMRCM_D3PHIA"
  "VMRCM_D4PHIA"
  "VMRCM_D5PHIA"

  # TrackletEngine
  "TE_L1PHIC12_L2PHIB12"
  "TE_L1PHIE18_L2PHIC17"

  # TrackletCalculator
  "TC_L1L2A"
  "TC_L1L2B"
  "TC_L1L2C"
  "TC_L1L2D"
  "TC_L1L2E"
  "TC_L1L2F"
  "TC_L1L2G"
  "TC_L1L2H"
  "TC_L1L2I"
  "TC_L1L2J"
  "TC_L1L2K"
  "TC_L1L2L"
  "TC_L3L4A"
  "TC_L3L4B"
  "TC_L3L4C"
  "TC_L3L4D"
  "TC_L3L4E"
  "TC_L3L4F"
  "TC_L3L4G"
  "TC_L3L4H"
  "TC_L5L6A"
  "TC_L5L6B"
  "TC_L5L6C"
  "TC_L5L6D"

  # ProjectionRouter
  "PR_L1PHIB"
  "PR_L2PHIB"
  "PR_L3PHIB"
  "PR_L4PHIB"
  "PR_L5PHIB"
  "PR_L6PHIB"
  "PR_L1PHIC"
  "PR_L2PHIC"
  "PR_L3PHIC"
  "PR_L4PHIC"
  "PR_L5PHIC"
  "PR_L6PHIC"

  # MatchEngine
  "ME_L1PHIE20"
  "ME_L3PHIC20"
  "ME_L4PHIB12"

  # MatchCalculator
  "MC_L1PHIB"
  "MC_L2PHIB"
  "MC_L3PHIB"
  "MC_L4PHIB"
  "MC_L5PHIB"
  "MC_L6PHIB"
  "MC_L1PHIC"
  "MC_L2PHIC"
  "MC_L3PHIC"
  "MC_L4PHIC"
  "MC_L5PHIC"
  "MC_L6PHIC"

  # MatchProcessor
  "MP_L3PHIC"

  # TrackBuilder (aka FitTrack)
  "FT_L1L2"
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

# Exit with an error message if run from a directory other than emData/.
cwd=`pwd | xargs basename`
if [[ $cwd != "emData" ]]
then
  echo "Must be run from emData directory."
  exit 1
fi

# Download and unpack LUTs.tar.gz.
if [[ $memprints_only == 0 ]]
then
  wget -O LUTs.tgz --quiet ${luts_url_cm}
  tar -xzf LUTs.tgz
  mv LUTs LUTsCM
  rm -f LUTs.tgz
  wget -O LUTs.tar.gz --quiet ${luts_url}
  tar -xzf LUTs.tar.gz
  rm -f LUTs.tar.gz
fi

# Run scripts to generate top functions in TrackletAlgorithm/
./generate_IR.py
./generate_VMR.py -a -w LUTs/wires.dat
./generate_TC.py LUTs/wires.dat
./generate_PR.py LUTs/wires.dat
./generate_MC.py LUTs/wires.dat
./generate_TB.py LUTs/wires.dat

# Exit now if we are only downloading and unpacking LUTs.tar.gz.
if [[ $tables_only != 0 ]]
then
  exit 0
fi

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  echo ${module}
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  memprint_location="MemPrints"
  table_location="LUTs"
  if [[ ${module_type} == "TP" || ${module_type} == "MP" || ${module_type} == "VMRCM" ]]
  then
    memprint_location="MemPrintsCM"
    table_location="LUTsCM"
    if [[ ${module_type} == "VMRCM" ]]
    then
      module=`echo ${module} | sed "s/CM//"`
    fi
  fi
  wires="${table_location}/wires.dat"

  target_dir=${module_type}/${module}

  rm -rf ${target_dir}
  mkdir -p ${target_dir}

  for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
  do
    find ${memprint_location} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
  done

  # Table linking logic specific to each module type
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
  elif [[ ${module_type} == "TP" ]]
  then
          seed=`echo ${module} | sed "s/.*_\(L[1-6]L[1-6]\).*$/\1/g"`
          find ${table_location} -type f -name "TP_${seed}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MC" ]] || [[ ${module_type} == "TE" ]]
  then
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MP" ]]
  then
          layer=`echo ${module} | sed "s/.*_\(L[1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_phicut.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_zcut.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "VMR" ]] || [[ ${module_type} == "VMRCM" ]]
  then
          layer=`echo ${module} | sed "s/VMR_\(..\).*/\1/g"`
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "VM*${layer}*" ! -name "*PHI*" -exec ln -sf ../../{} ${table_target_dir}/ \;
          for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
          do
            find ${table_location} -type f -name "${mem}*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          done
  fi
done
