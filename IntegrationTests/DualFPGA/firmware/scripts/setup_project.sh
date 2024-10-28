#/bin/bash
set -e -x

# uses ssh key authentication for gitlab.cern.ch, make sure you have that set up

PROJ_DIR=dual_fpga_2

[ -d ${PROJ_DIR} ] && rm -rf ${PROJ_DIR}
ipbb init ${PROJ_DIR}
cd ${PROJ_DIR}
ipbb -e add git ssh://git@gitlab.cern.ch:7999/p2-xware/firmware/emp-fwk.git -b v0.9.0-alpha2
ipbb -e add git https://github.com/apollo-lhc/CM_FPGA_FW -b v3.0.0


ipbb add git https://gitlab.cern.ch/ttc/legacy_ttc.git -b v2.1
ipbb add git ssh://git@gitlab.cern.ch:7999/cms-tcds/cms-tcds2-firmware.git -b v0_1_1
ipbb add git ssh://git@gitlab.cern.ch:7999/hptd/tclink.git -r fda0bcf
ipbb add git https://github.com/ipbus/ipbus-firmware -b v1.9
ipbb add git ssh://git@gitlab.cern.ch:7999/dth_p1-v2/slinkrocket_ips.git -b v03.12
ipbb add git ssh://git@gitlab.cern.ch:7999/dth_p1-v2/slinkrocket.git -b v03.12
ipbb add git ssh://git@github.com/cms-l1tk/firmware-hls.git -b dual_fpga

export PATH=/opt/cactus/bin/uhal/tools:$PATH 
export LD_LIBRARY_PATH=/opt/cactus/lib:${LD_LIBRARY_PATH}

BASEDIR=$(pwd)

export COLUMNS=120

# FPGA 1 Simulation
ipbb proj create vivado vsim_f1 firmware-hls:IntegrationTests/DualFPGA/ vsim_f1.dep
cd proj/vsim_f1/
ipbb vivado generate-project --single

cd $BASEDIR
# FPGA 1
ipbb proj create vivado tf_f1 firmware-hls:IntegrationTests/DualFPGA/ apollo_f1.dep
cd proj/tf_f1/
ipbb ipbus gendecoders
ipbb vivado generate-project --single
ipbb vivado synth -j16 impl -j16 package

cd $BASEDIR
# FPGA 2 Simulation
ipbb proj create vivado vsim_f2 firmware-hls:IntegrationTests/DualFPGA/ vsim_f2.dep
cd proj/vsim_f2/
ipbb vivado generate-project --single

cd $BASEDIR
# FPGA 2
ipbb proj create vivado tf_f2 firmware-hls:IntegrationTests/DualFPGA/ apollo_f2.dep
cd proj/tf_f2/
ipbb ipbus gendecoders
ipbb vivado generate-project --single
ipbb vivado synth -j16 impl -j16 package
