#!/usr/bin/env bash

#### fw_synch_210611 ####
# Standard configuration
memprints_url="https://cernbox.cern.ch/index.php/s/hUJUsqvCnKv2YdQ/download"
luts_url="https://cernbox.cern.ch/index.php/s/9Yms3LCKJsg7UmF/download"
# Combined modules
memprints_url_cm="https://cernbox.cern.ch/index.php/s/RFpmFiSnFC84x0O/download"
luts_url_cm="https://cernbox.cern.ch/index.php/s/kqZu8R7Ftu0YPoO/download"

#### fw_synch_210503 ####
# Standard configuration
#memprints_url="https://cernbox.cern.ch/index.php/s/CipX7CfTXIj1lcK/download"
#luts_url="https://cernbox.cern.ch/index.php/s/UDSvClVZksBr1Pq/download"
# Combined modules
#memprints_url_cm="https://www.dropbox.com/s/lf088lvyvg2t6jh/MemPrintsCombined_210319.tgz?dl=0"
#luts_url_cm="https://www.dropbox.com/s/legrvm3gyu5hrth/LUTsCombined_210319.tgz?dl=0"

#### fw_synch_201005 ####
#memprints_url="https://cernbox.cern.ch/index.php/s/y7IWeDG4x7Sg7Im/download"
#luts_url="https://cernbox.cern.ch/index.php/s/DuhCjcykSHZLRhM/download"

#### fw_synch_200515 ####
#memprints_url="https://cernbox.cern.ch/index.php/s/QvV86Qcc8n9R4sg/download"
#luts_url="https://cernbox.cern.ch/index.php/s/YSER9ne7WVxiKXI/download"

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # VMRouter
  "VMR_L1PHIE"
  "VMR_L1PHID"
  "VMR_L2PHIA"
  "VMR_L2PHIB"
  "VMR_L3PHIA"
  "VMR_L4PHIA"
  "VMR_L5PHIA"
  "VMR_L6PHIA"
  "VMR_D1PHIA"
  "VMR_D2PHIA"

  # VMRouter CM
  "VMRCM_L2PHIA"

  # TrackletEngine
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

  # MatchProcessor
  "MP_L3PHIC"

  # TrackBuilder (aka FitTrack)
  "FT_L1L2"

  # Tracklet Processor
  "TP_L1L2D" 
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

# If the MemPrints directory exists, assume the script has already been run,
# and simply exit.
if [ -d "MemPrints" ]
then
  exit 0
fi

# If the LUTs directory exists, assume LUTs.tar.gz has already been downloaded
# and unpacked, and only download and unpack MemPrints.tar.gz.
memprints_only=0
if [ -d "LUTs" ]
then
  memprints_only=1
fi

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

# Exit now if we are only downloading and unpacking LUTs.tar.gz.
if [[ $tables_only != 0 ]]
then
  exit 0
fi

# Download and unpack the tarball.
wget -O MemPrints.tgz --quiet ${memprints_url_cm}
tar -xzf MemPrints.tgz
mv MemPrints MemPrintsCM
rm -f MemPrints.tgz

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
