#!/usr/bin/env bash

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # InputRouter
  "IR_PS10G_1_A"
  "IR_PS10G_2_A"
  "IR_PS10G_2_B"
  "IR_PS10G_3_A"
  "IR_PS10G_3_B"
  "IR_PS_1_A"
  "IR_PS_1_B"
  "IR_PS_2_A"
  "IR_PS_2_B"
  "IR_2S_1_A"
  "IR_2S_1_B"
  "IR_2S_2_A"
  "IR_2S_2_B"
  "IR_2S_3_A"
  "IR_2S_3_B"
  "IR_2S_4_A"
  "IR_2S_4_B"

  # VMRouter
  "VMR_L1PHID"
  "VMR_L2PHIB"
  "VMR_L3PHIB"
  "VMR_L4PHIB"
  "VMR_L5PHIB"
  "VMR_L6PHIB"

  # TrackletEngine
  "TE_L1PHID14_L2PHIB15"
  "TE_L1PHID14_L2PHIB16"
  "TE_L1PHID15_L2PHIB13"
  "TE_L1PHID15_L2PHIB14"
  "TE_L1PHID15_L2PHIB15"
  "TE_L1PHID15_L2PHIB16"
  "TE_L1PHID16_L2PHIB14"
  "TE_L1PHID16_L2PHIB15"
  "TE_L1PHID16_L2PHIB16"

  # TrackletCalculator
  "TC_L1L2F"

  # ProjectionRouter
  "PR_L3PHIB"
  "PR_L4PHIB"
  "PR_L5PHIB"
  "PR_L6PHIB"

  # MatchEngine
  "ME_L3PHIB9"
  "ME_L3PHIB10"
  "ME_L3PHIB11"
  "ME_L3PHIB12"
  "ME_L3PHIB13"
  "ME_L3PHIB14"
  "ME_L3PHIB15"
  "ME_L3PHIB16"
  "ME_L4PHIB9"
  "ME_L4PHIB10"
  "ME_L4PHIB11"
  "ME_L4PHIB12"
  "ME_L4PHIB13"
  "ME_L4PHIB14"
  "ME_L4PHIB15"
  "ME_L4PHIB16"
  "ME_L5PHIB9"
  "ME_L5PHIB10"
  "ME_L5PHIB11"
  "ME_L5PHIB12"
  "ME_L5PHIB13"
  "ME_L5PHIB14"
  "ME_L5PHIB15"
  "ME_L5PHIB16"
  "ME_L6PHIB9"
  "ME_L6PHIB10"
  "ME_L6PHIB11"
  "ME_L6PHIB12"
  "ME_L6PHIB13"
  "ME_L6PHIB14"
  "ME_L6PHIB15"
  "ME_L6PHIB16"

  # MatchCalculator
  "MC_L3PHIB"
  "MC_L4PHIB"
  "MC_L5PHIB"
  "MC_L6PHIB"

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
