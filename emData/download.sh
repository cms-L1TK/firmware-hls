#!/usr/bin/env bash
set -e

#### fw_synch_230620 ####
# Standard configuration
memprints_url="https://cernbox.cern.ch/remote.php/dav/public-files/H6ICoefkQU7Lzy5/MemPrints.tar.gz"
luts_url="https://cernbox.cern.ch/remote.php/dav/public-files/h1x7phQ9EKvj7gx/LUTs.tar.gz"
# Reduced configuration
memprints_url_reduced="https://cernbox.cern.ch/remote.php/dav/public-files/s7nv7Qy2tiKKX3m/MemPrints.tar.gz"
luts_url_reduced="https://cernbox.cern.ch/remote.php/dav/public-files/uYQJKob271Lwq0i/LUTs.tar.gz"
# Combined modules
memprints_url_cm="https://cernbox.cern.ch/s/luEENjQBPTGNSYd/download"
luts_url_cm="https://cernbox.cern.ch/s/YrntTfrxwIasgxV/download"
# Reduced Combined modules                                                      
memprints_url_reducedcm="https://aryd.web.cern.ch/aryd/MemPrints_CombinedReduced_220807.tgz"
luts_url_reducedcm="https://aryd.web.cern.ch/aryd/LUTs_CombinedReduced_220807.tgz"
# Reduced Combined modules2
memprints_url_cm2="https://cernbox.cern.ch/remote.php/dav/public-files/hAQSPKPZDs9BCq9/MemPrints.tar.gz"
luts_url_cm2="https://cernbox.cern.ch/remote.php/dav/public-files/KXjCYaFVkVXwiK3/LUTs.tar.gz"

# Barrel-only configuration
# N.B.: currently untagged but produced with following commit:
# e5047997b33dc6cfb1d7ce35aa34dfc56c0fe9bf
memprints_url_barrel="https://cernbox.cern.ch/remote.php/dav/public-files/2Ju0bMoBnRK1B8n/MemPrints.tar.gz"
luts_url_barrel="https://cernbox.cern.ch/remote.php/dav/public-files/DLJv9VGrjFrZUSQ/LUTs.tar.gz"

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
  tar -xzmf LUTs.tgz
  mv LUTs LUTsReduced
  rm -f LUTs.tgz
  wget -O LUTs.tgz --quiet ${luts_url_barrel}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsBarrel
  wget -O LUTs.tgz --quiet ${luts_url_reducedcm}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCMReduced
  rm -f LUTs.tgz
  wget -O LUTs.tgz --quiet ${luts_url_cm}
  tar -xzf LUTs.tgz
  mv LUTs LUTsCM
  rm -f LUTs.tgz
  wget -O LUTs.tgz --quiet ${luts_url_cm2}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCM2
  rm -f LUTs.tgz
  wget -O LUTs.tar.gz --quiet ${luts_url}
  tar -xzmf LUTs.tar.gz
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
### barrel config
mkdir -p ../TopFunctions/BarrelConfig
./generate_IR.py     -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_VMR.py -a -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_TC.py     -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_PR.py     -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_ME.py -s  -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_MC.py     -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
./generate_TB.py     -w LUTsBarrel/wires.dat -o ../TopFunctions/BarrelConfig
### combined config
mkdir -p ../TopFunctions/CombinedConfig
./generate_VMRCM.py -a -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_MP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TB.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
### reduced combined config
mkdir -p ../TopFunctions/ReducedCombinedConfig
./generate_IR.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_VMRCM.py -a -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_TP.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_MP.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_TB.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
### reduced combined config 2
mkdir -p ../TopFunctions/ReducedCombinedConfig2
./generate_IR.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_VMRCM.py -a -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_TP.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_MP.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_TB.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2


# Run scripts to generate HDL top modules and test benches in IntegrationTests/
cd ../ # needed for older versions of git
git submodule init
git submodule update
cd emData/project_generation_scripts/
cp -fv ../LUTsCM/wires.dat ../LUTsCM/memorymodules.dat ../LUTsCM/processingmodules.dat ./
./makeReducedConfig.py --no-graph -t "TP" -s "C" -o "reducedcm_"
cp -fv ../LUTsCM2/wires.dat ../LUTsCM2/memorymodules.dat ../LUTsCM2/processingmodules.dat ./
mv wires.dat reducedcm2_wires.dat
mv memorymodules.dat reducedcm2_memorymodules.dat
mv processingmodules.dat reducedcm2_processingmodules.dat
cp -fv ../LUTs/wires.dat ../LUTs/memorymodules.dat ../LUTs/processingmodules.dat ./
./makeReducedConfig.py --no-graph
./makeBarrelConfig.py
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
### Barrel IRtoTB
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 7 -w barrel_wires.dat -p barrel_processingmodules.dat -m barrel_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 7 -w barrel_wires.dat -p barrel_processingmodules.dat -m barrel_memorymodules.dat -x
mkdir -p ../../IntegrationTests/BarrelConfig/IRtoTB/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/BarrelConfig/IRtoTB/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/BarrelConfig/IRtoTB/tb/
### Reduced Combined IRtoTB
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm_wires.dat -p reducedcm_processingmodules.dat -m reducedcm_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm_wires.dat -p reducedcm_processingmodules.dat -m reducedcm_memorymodules.dat -x
mkdir -p ../../IntegrationTests/ReducedCombinedConfig/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedCombinedConfig/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedCombinedConfig/tb/
### Reduced Combined 2 IRtoTB
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm2_wires.dat -p reducedcm2_processingmodules.dat -m reducedcm2_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm2_wires.dat -p reducedcm2_processingmodules.dat -m reducedcm2_memorymodules.dat -x
mkdir -p ../../IntegrationTests/ReducedCombinedConfig2/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedCombinedConfig2/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedCombinedConfig2/tb/

# Remove untracked file and return to emData/
rm -fv script_sectproc.tcl
cd ../

if [[ $tables_only == 0 ]]
then
  # Get memory test data: download and unpack the tarball.
  wget -O MemPrints.tgz --quiet ${memprints_url_reduced}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsReduced
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_barrel}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsBarrel
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_reducedcm}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsReducedCM
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_cm2}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsReducedCM2
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_cm}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsCM
  rm -f MemPrints.tgz

  wget -O MemPrints.tar.gz --quiet ${memprints_url}
  tar -xzmf MemPrints.tar.gz
  rm -f MemPrints.tar.gz
fi

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# Create a list of all processing modules. The VMRs in the combined config get
# a special name.
processing_modules=`sed "s/VMRouterCM: VMR/&CM/g" LUTs/processingmodules.dat LUTsCM/processingmodules.dat LUTsReduced/processingmodules.dat LUTsBarrel/processingmodules.dat | awk '{print $2}' | sort -u`

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  echo ${module}
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  memprint_location="MemPrints"
  memprint_location_reduced="MemPrintsReduced"
  memprint_location_reducedcm="MemPrintsReducedCM"
  memprint_location_reducedcm2="MemPrintsReducedCM2"
  memprint_location_barrel="MemPrintsBarrel"
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
    mkdir -p ${target_dir}/BarrelConfig
    mkdir -p ${target_dir}/ReducedCombinedConfig
    mkdir -p ${target_dir}/ReducedCombinedConfig2

    for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
    do
      find ${memprint_location} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
      find ${memprint_location_reduced} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedConfig/ \;
      find ${memprint_location_reducedcm} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedCombinedConfig/ \;
      find ${memprint_location_reducedcm2} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedCombinedConfig2/ \;
      find ${memprint_location_barrel} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/BarrelConfig/ \;
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
          find ${table_location} -type f -name "TP_${seed}.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MC" ]] || [[ ${module_type} == "TE" ]]
  then
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MP" ]]
  then
          layer=`echo ${module} | sed "s/.*_\([L|D][1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "ProjectionDiskRadius.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "MP_ProjectionBend_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
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
