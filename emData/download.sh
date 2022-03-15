#!/usr/bin/env bash
set -e

#### fw_synch_220220 ####
# Standard configuration
memprints_url="https://cernbox.cern.ch/index.php/s/7H3StfracwrVUAe/download"
luts_url="https://cernbox.cern.ch/index.php/s/SUd6tEO970wKNnZ/download"
# Reduced configuration
memprints_url_reduced="https://cernbox.cern.ch/index.php/s/qBKvAmfu83SpAGD/download"
luts_url_reduced="https://cernbox.cern.ch/index.php/s/GJZA1zLnWg3hP4y/download"
# Combined modules
memprints_url_cm="https://cernbox.cern.ch/index.php/s/YcqX3KUgFdZyMG6/download"
luts_url_cm="https://cernbox.cern.ch/index.php/s/lKrxzKJ0XmelE0j/download"

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

# If the MemPrints directory exists, assume the script has already been run,
# and simply exit.
if [ -d "MemPrints" ]
then
  echo "The emData directory must be cleaned for this script to work."
  exit 0
fi

# Download and unpack LUTs.tar.gz,
# unless LUTS directory already exists (due to previous "download.sh -t" run).

if [ ! -d "LUTs" ]
then
  wget -O LUTs.tgz --quiet ${luts_url_reduced}
  tar -xzf LUTs.tgz
  mv LUTs LUTsReduced
  rm -f LUTs.tgz
  wget -O LUTs.tgz --quiet ${luts_url_cm}
  tar -xzf LUTs.tgz
  mv LUTs LUTsCM
  rm -f LUTs.tgz
  wget -O LUTs.tar.gz --quiet ${luts_url}
  tar -xzf LUTs.tar.gz
  rm -f LUTs.tar.gz
fi

# Run scripts to generate top functions in TopFunctions/
### full config
./generate_IR.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_VMR.py -a -w LUTs/wires.dat -o ../TopFunctions
./generate_TC.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_PR.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_ME.py -s  -w LUTs/wires.dat -o ../TopFunctions
./generate_MC.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_TB.py     -w LUTs/wires.dat -o ../TopFunctions
### reduced config
mkdir -p ../TopFunctions/ReducedConfig
./generate_IR.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_VMR.py -a -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_TC.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_PR.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_ME.py -s  -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_MC.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_TB.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
### combined config
mkdir -p ../TopFunctions/CombinedConfig
./generate_VMRCM.py -a -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_MP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig

# Run scripts to generate HDL top modules and test benches in IntegrationTests/
git submodule init
git submodule update
cp -fv LUTs/wires.dat LUTs/memorymodules.dat LUTs/processingmodules.dat project_generation_scripts/
cd project_generation_scripts/
./makeReducedConfig.py
### IRVMR
./generator_hdl.py ../../ --no_graph --uut VMR_L2PHIA -u 1 -d 0
./generator_hdl.py ../../ --no_graph --uut VMR_L2PHIA -u 1 -d 0 -x
mkdir -p ../../IntegrationTests/IRVMR/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/IRVMR/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/IRVMR/tb/
### PRMEMC
./generator_hdl.py ../../ --no_graph --uut PR_L3PHIC -u 0 -d 2
./generator_hdl.py ../../ --no_graph --uut PR_L3PHIC -u 0 -d 2 -x
mkdir -p ../../IntegrationTests/PRMEMC/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/PRMEMC/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/PRMEMC/tb/
### TETC
./generator_hdl.py ../../ --no_graph --uut TC_L1L2E -u 1 -d 0
./generator_hdl.py ../../ --no_graph --uut TC_L1L2E -u 1 -d 0 -x
mkdir -p ../../IntegrationTests/TETC/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/TETC/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/TETC/tb/
### Reduced IRtoTB
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 7 -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 7 -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat -x
mkdir -p ../../IntegrationTests/ReducedConfig/IRtoTB/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedConfig/IRtoTB/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedConfig/IRtoTB/tb/
### Reduced MCTB
./generator_hdl.py ../../ --no_graph --mut FT -u 1 -d 0 -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut FT -u 1 -d 0 -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat -x
mkdir -p ../../IntegrationTests/ReducedConfig/MCTB/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedConfig/MCTB/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedConfig/MCTB/tb/

# Removed untracked files and return to emData/
rm -fv TrackletProject.pdf script_sectproc.tcl
cd ../

if [[ $tables_only == 0 ]]
then
  # Get memory test data: download and unpack the tarball.
  wget -O MemPrints.tgz --quiet ${memprints_url_reduced}
  tar -xzf MemPrints.tgz
  mv MemPrints MemPrintsReduced
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_cm}
  tar -xzf MemPrints.tgz
  mv MemPrints MemPrintsCM
  rm -f MemPrints.tgz

  wget -O MemPrints.tar.gz --quiet ${memprints_url}
  tar -xzf MemPrints.tar.gz
  rm -f MemPrints.tar.gz

fi

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# Create a list of all processing modules. The VMRs in the combined config get
# a special name.
processing_modules=`sed "s/VMRouterCM: VMR/&CM/g" LUTs/processingmodules.dat LUTsCM/processingmodules.dat LUTsReduced/processingmodules.dat | awk '{print $2}' | sort -u`

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  echo ${module}
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  memprint_location="MemPrints"
  memprint_location_reduced="MemPrintsReduced"
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

  if [[ $tables_only == 0 ]]
  then
    # Create directories containing memory test data specific to each module type.
    target_dir=${module_type}/${module}

    rm -rf ${target_dir}
    mkdir -p ${target_dir}/ReducedConfig

    for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
    do
      find ${memprint_location} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
      find ${memprint_location_reduced} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedConfig/ \;
    done
  fi

  # Create directories containing LUT tables specific to each module type.
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
          layer=`echo ${module} | sed "s/.*_\([L|D][1-9]\).*$/\1/g"`
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
