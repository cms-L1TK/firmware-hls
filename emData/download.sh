#!/usr/bin/env bash
set -e


#### generated with branch VMSMERouterCMSSW13, commit a2c799d ####
# Combined modules
memprints_url_cm="https://cernbox.cern.ch/remote.php/dav/public-files/P2URd03nlGDfpDt/MemPrints.tar.gz"
luts_url_cm="https://aryd.web.cern.ch/aryd/LUTs_Combined_231208.tgz"
# Split modules - i.e. with PC and VMSMER
memprints_url_split="https://aryd.web.cern.ch/aryd/MemPrints_Split_240405.tgz"
luts_url_split="https://aryd.web.cern.ch/aryd/LUTs_Split_240405.tgz"
# Reduced Combined modules
memprints_url_reducedcm="https://cernbox.cern.ch/remote.php/dav/public-files/kv2U49bw93chvZG/MemPrints_CMReduced_040424.tar.gz"
luts_url_reducedcm="https://aryd.web.cern.ch/aryd/LUTs_CMReduced_240121.tgz"
# Reduced Combined modules2
memprints_url_cm2="https://cernbox.cern.ch/remote.php/dav/public-files/MDQXOUkSMEM1KkH/MemPrints_CMReduced2_040424.tar.gz"
luts_url_cm2="https://aryd.web.cern.ch/aryd/LUTs_CMReduced2_240121.tgz"
# Combined barrel
memprints_url_cmbarrel="https://cernbox.cern.ch/remote.php/dav/public-files/lVII5Ho0VX7nwFA/MemPrints_Barrel_040424.tar.gz"
luts_url_cmbarrel="https://aryd.web.cern.ch/aryd/LUTs_Barrel_240121.tgz"

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
if [ -d "MemPrintsCM" ]
then
  echo "The emData directory must be cleaned for this script to work."
  exit 0
fi

# Download and unpack LUTs.tar.gz,
# unless LUTS directory already exists (due to previous "download.sh -t" run).

if [ ! -d "LUTs" ]
then
  wget --no-check-certificate -O LUTs.tgz --quiet ${luts_url_split}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsSplit
  rm -f LUTs.tgz
  wget --no-check-certificate -O LUTs.tgz --quiet ${luts_url_reducedcm}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCMReduced
  rm -f LUTs.tgz
  wget --no-check-certificate -O LUTs.tgz --quiet ${luts_url_cm}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCM
  rm -f LUTs.tgz
  wget --no-check-certificate -O LUTs.tgz --quiet ${luts_url_cm2}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCM2
  rm -f LUTs.tgz
  wget --no-check-certificate -O LUTs.tgz --quiet ${luts_url_cmbarrel}
  tar -xzmf LUTs.tgz
  mv LUTs LUTsCMBarrel
  rm -f LUTs.tgz
fi

# Run scripts to generate top functions in TopFunctions/
### combined config
mkdir -p ../TopFunctions/CombinedConfig
./generate_IR.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_VMRCM.py -a -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_VMSMER.py -a -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_PC.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_MP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TB.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
### reduced combined config
mkdir -p ../TopFunctions/ReducedCombinedConfig
./generate_IR.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_VMRCM.py -a -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_VMSMER.py -a -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_TP.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_PC.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_MP.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
./generate_TB.py       -w LUTsCMReduced/wires.dat -o ../TopFunctions/ReducedCombinedConfig
### reduced combined config 2
mkdir -p ../TopFunctions/ReducedCombinedConfig2
./generate_IR.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_VMRCM.py -a -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_VMSMER.py -a -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_TP.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_PC.py       -w LUTsCM/wires.dat  -o ../TopFunctions/ReducedCombinedConfig2
./generate_MP.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
./generate_TB.py       -w LUTsCM2/wires.dat -o ../TopFunctions/ReducedCombinedConfig2
### combined barrel config                      
mkdir -p ../TopFunctions/CombinedBarrelConfig
./generate_IR.py       -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
./generate_VMRCM.py -a -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
./generate_VMSMER.py -a -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
./generate_TP.py       -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
./generate_PC.py       -w LUTsCM/wires.dat       -o ../TopFunctions/CombinedBarrelConfig
./generate_MP.py       -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
./generate_TB.py       -w LUTsCMBarrel/wires.dat -o ../TopFunctions/CombinedBarrelConfig
### combined barrel config                      
mkdir -p ../TopFunctions/CombinedConfig_FPGA2
./generate_PC.py       -sp -w  LUTsSplit/wires.dat -o ../TopFunctions/CombinedConfig_FPGA2
./generate_VMSMER.py   --all -w LUTsSplit/wires.dat -o ../TopFunctions/CombinedConfig_FPGA2
./generate_MP.py       -sp -w LUTsSplit/wires.dat -o ../TopFunctions/CombinedConfig_FPGA2
./generate_TB.py       -sp -w LUTsSplit/wires.dat -o ../TopFunctions/CombinedConfig_FPGA2


# Run scripts to generate HDL top modules and test benches in IntegrationTests/
cd ../ # needed for older versions of git
git submodule init
git submodule update
cd emData/project_generation_scripts/
cp -fv ../LUTsCM/wires.dat ../LUTsCM/memorymodules.dat ../LUTsCM/processingmodules.dat ./
# Should these be auto generated? 
cp ../LUTsCMReduced/wires.dat reducedcm_wires.dat
cp ../LUTsCMReduced/processingmodules.dat reducedcm_processingmodules.dat
cp ../LUTsCMReduced/memorymodules.dat reducedcm_memorymodules.dat
cp ../LUTsCM2/wires.dat reducedcm2_wires.dat
cp ../LUTsCM2/processingmodules.dat reducedcm2_processingmodules.dat
cp ../LUTsCM2/memorymodules.dat reducedcm2_memorymodules.dat
cp ../LUTsCMBarrel/wires.dat cmbarrel_wires.dat
cp ../LUTsCMBarrel/processingmodules.dat cmbarrel_processingmodules.dat
cp ../LUTsCMBarrel/memorymodules.dat cmbarrel_memorymodules.dat
<<<<<<< HEAD
=======
# grep, awk, and sed should be fixed in CMSSW - no we can use the config from
# CMSSW instead of a hand made configuration. But it still needs tweaking...
grep -v vmstuboutPHI ../LUTsSplit/wires.dat | grep -v TP_ | grep -v IR_ > fpga2_wires.dat
echo "MPAR_L1L2ABCin input=> output=> PC_L1L2ABC.tparin" >> fpga2_wires.dat
echo "MPAR_L1L2DEin input=> output=> PC_L1L2DE.tparin" >> fpga2_wires.dat
echo "MPAR_L1L2Fin input=> output=> PC_L1L2F.tparin" >> fpga2_wires.dat
echo "MPAR_L1L2Gin input=> output=> PC_L1L2G.tparin" >> fpga2_wires.dat
echo "MPAR_L1L2HIin input=> output=> PC_L1L2HI.tparin" >> fpga2_wires.dat
echo "MPAR_L1L2JKLin input=> output=> PC_L1L2JKL.tparin" >> fpga2_wires.dat
echo "MPAR_L2L3ABCDin input=> output=> PC_L2L3ABCD.tparin" >> fpga2_wires.dat
echo "MPAR_L3L4ABin input=> output=> PC_L3L4AB.tparin" >> fpga2_wires.dat
echo "MPAR_L3L4CDin input=> output=> PC_L3L4CD.tparin" >> fpga2_wires.dat
echo "MPAR_L5L6ABCDin input=> output=> PC_L5L6ABCD.tparin" >> fpga2_wires.dat
echo "MPAR_D1D2ABCDin input=> output=> PC_D1D2ABCD.tparin" >> fpga2_wires.dat
echo "MPAR_D3D4ABCDin input=> output=> PC_D3D4ABCD.tparin" >> fpga2_wires.dat
echo "MPAR_L1D1ABCDin input=> output=> PC_L1D1ABCD.tparin" >> fpga2_wires.dat
echo "MPAR_L1D1EFGHin input=> output=> PC_L1D1EFGH.tparin" >> fpga2_wires.dat
echo "MPAR_L2D1ABCDin input=> output=> PC_L2D1ABCD.tparin" >> fpga2_wires.dat
sed -i 's/VMR_[L|D][1-9]PHI[A|B|C|D|E|F|G|H].allstubout//g' fpga2_wires.dat
sed -i 's/n1 input/in input/g' fpga2_wires.dat
grep -v VMR_ fpga2_wires.dat > tmp.dat
mv tmp.dat fpga2_wires.dat
cp ../LUTsSplit/memorymodules.dat fpga2_memorymodules.dat
sed -i 's/n1 \[42\]/in \[42\]/g' fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2ABCin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2DEin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2Fin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2Gin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2HIin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1L2JKLin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L2L3ABCDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L3L4ABin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L3L4CDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L5L6ABCDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_D1D2ABCDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_D3D4ABCDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1D1ABCDin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L1D1EFGHin [73]" >> fpga2_memorymodules.dat
echo "TrackletParameters: MPAR_L2D1ABCDin [73]" >> fpga2_memorymodules.dat

grep -v TP_ ../LUTsSplit/processingmodules.dat | grep -v VMR_ | grep -v IR_ > fpga2_processingmodules.dat
sed -i 's/VMStubMERouter/VMSMERouter/g' fpga2_processingmodules.dat
>>>>>>> 0a2ec65 (Updates to configuration file from CMSSW for the FPGA2 project)

./makeReducedConfig.py --no-graph -t "TP" -s "C" -o "reducedcm_"
cp -fv ../LUTsCM2/wires.dat ../LUTsCM2/memorymodules.dat ../LUTsCM2/processingmodules.dat ./
mv wires.dat reducedcm2_wires.dat
mv memorymodules.dat reducedcm2_memorymodules.dat
mv processingmodules.dat reducedcm2_processingmodules.dat
### Reduced Combined IRtoTB
echo "Reduced CM"
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm_wires.dat -p reducedcm_processingmodules.dat -m reducedcm_memorymodules.dat -de 1
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm_wires.dat -p reducedcm_processingmodules.dat -m reducedcm_memorymodules.dat -de 1 -x
mkdir -p ../../IntegrationTests/ReducedCombinedConfig/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedCombinedConfig/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedCombinedConfig/tb/
### Reduced Combined 2 IRtoTB
echo "Reduced CM2"
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm2_wires.dat -p reducedcm2_processingmodules.dat -m reducedcm2_memorymodules.dat
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w reducedcm2_wires.dat -p reducedcm2_processingmodules.dat -m reducedcm2_memorymodules.dat -x
mkdir -p ../../IntegrationTests/ReducedCombinedConfig2/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/ReducedCombinedConfig2/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/ReducedCombinedConfig2/tb/
### Reduced Combined 2 IRtoTB
echo "CM Barrel"
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w cmbarrel_wires.dat -p cmbarrel_processingmodules.dat -m cmbarrel_memorymodules.dat -de 1
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 4 -w cmbarrel_wires.dat -p cmbarrel_processingmodules.dat -m cmbarrel_memorymodules.dat -de 1 -x
mkdir -p ../../IntegrationTests/CombinedBarrelConfig/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/CombinedBarrelConfig/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/CombinedBarrelConfig/tb/
### Combined IRtoTP
echo "CombinedIRtoTP"
cp -fv ../LUTsCM/wires.dat ../LUTsCM/memorymodules.dat ../LUTsCM/processingmodules.dat ./
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 2 -w wires.dat -p processingmodules.dat -m memorymodules.dat -de 1 -sp
./generator_hdl.py ../../ --no_graph --mut IR -u 0 -d 2 -w wires.dat -p processingmodules.dat -m memorymodules.dat -de 1 -x -sp
mkdir -p ../../IntegrationTests/CombinedConfig/IRtoTP/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/CombinedConfig/IRtoTP/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/CombinedConfig/IRtoTP/tb/
### Combined PC/VMSMER to TB
echo "CM FPGA2"
./generator_hdl.py ../../ --no_graph --mut PC -u 0 -d 2 -w fpga2_wires.dat -p fpga2_processingmodules.dat -m fpga2_memorymodules.dat -de 1
./generator_hdl.py ../../ --no_graph --mut PC -u 0 -d 2 -w fpga2_wires.dat -p fpga2_processingmodules.dat -m fpga2_memorymodules.dat -de 1 -x
mkdir -p ../../IntegrationTests/CombinedConfig_FPGA2/{hdl,tb}
mv -fv memUtil_pkg.vhd SectorProcessor.vhd SectorProcessorFull.vhd ../../IntegrationTests/CombinedConfig_FPGA2/hdl/
mv -fv tb_tf_top.vhd ../../IntegrationTests/CombinedConfig_FPGA2/tb/

# Remove untracked file and return to emData/
rm -fv script_sectproc.tcl
cd ../

if [[ $tables_only == 0 ]]
then
  # Get memory test data: download and unpack the tarball.
  wget --no-check-certificate -O MemPrints.tgz --quiet ${memprints_url_split}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsSplit
  rm -f MemPrints.tgz

  wget --no-check-certificate -O MemPrints.tgz --quiet ${memprints_url_reducedcm}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsReducedCM
  rm -f MemPrints.tgz

  wget --no-check-certificate -O MemPrints.tgz --quiet ${memprints_url_cm2}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsReducedCM2

  wget --no-check-certificate -O MemPrints.tgz --quiet ${memprints_url_cmbarrel}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsCMBarrel
  rm -f MemPrints.tgz

  wget --no-check-certificate -O MemPrints.tgz --quiet ${memprints_url_cm}
  tar -xzmf MemPrints.tgz
  mv MemPrints MemPrintsCM
  rm -f MemPrints.tgz

fi

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

mod_types=(IR FT PD VMRCM TP MP)

for module_type in ${mod_types[@]}
do
  echo "PROCESSING TYPE ${module_type}"
(

# Create a list of all processing modules. The VMRs in the combined config get
# a special name.
processing_modules=`sed "s/VMRouterCM: VMR/&CM/g" LUTsCM/processingmodules.dat | awk '{print $2}' | sort -u | grep ${module_type}`

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  echo ${module}
  memprint_location="MemPrintsSplit"
  memprint_location_reducedcm="MemPrintsReducedCM"
  memprint_location_reducedcm2="MemPrintsReducedCM2"
  table_location="LUTsSplit"
  if [[ ${module_type} == "VMRCM" ]]
  then
    module=`echo ${module} | sed "s/CM//"`
  fi
  wires="${table_location}/wires.dat"

  if [[ $tables_only == 0 ]]
  then
    # Create directories containing memory test data specific to each module type.
    target_dir=${module_type}/${module}

    rm -rf ${target_dir}
    mkdir -p ${target_dir}/ReducedCombinedConfig
    mkdir -p ${target_dir}/ReducedCombinedConfig2

    for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
    do
      find ${memprint_location} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
      find ${memprint_location_reducedcm} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedCombinedConfig/ \;
      find ${memprint_location_reducedcm2} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedCombinedConfig2/ \;
    done
  fi

  # Create directories containing LUT tables specific to each module type.
  table_target_dir="${module_type}/tables"
  if [[ ! -d "${table_target_dir}" ]]
  then
          mkdir -p ${table_target_dir}
  fi

  if [[ ${module_type} == "TP" ]]
  then
          seed=`echo ${module} | sed "s/.*_\([L|D][1-6][L|D][1-6]\).*$/\1/g"`
          find ${table_location} -type f -name "TP_${seed}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "TP_${seed}.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "TC_${seed}_invt.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "TC_${seed}_drinv.dat" -exec ln -sf ../../{} ${table_target_dir}/ \;

  elif [[ ${module_type} == "MP" ]]
  then
          layer=`echo ${module} | sed "s/.*_\([L|D][1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "ProjectionDiskRadius.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "MP_ProjectionBend_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "VMRCM" ]]
  then
          layer=`echo ${module} | sed "s/VMR_\(..\).*/\1/g"`
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "VM*${layer}*" ! -name "*PHI*" -exec ln -sf ../../{} ${table_target_dir}/ \;
          for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
          do
            find ${table_location} -type f -name "${mem}*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          done
  fi
done # loop over module
) & # Run entire loop as background process, so all loops run in parallel
done # loop over module_type

# Wait for all background processes to finish.
wait
