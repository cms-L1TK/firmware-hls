These scripts are all triggered by the [Makefile](https://github.com/cms-L1TK/firmware-hls/blob/master/IntegrationTests/ReducedConfig/IRtoKF/firmware/Makefile). There should be no need to use these manually.


* **convert_emData2EMP_Link.py**

This script takes the ".dat" files from the "emData/MemPrintsReduced" and generate an EMP input file to be used within the EMP framework for simulation and HW testing through buffers.

The script is made for the skinny chain.

Usage:

`-d`: folder path where the ".dat" files are stored
`-o`: path to store the output EMP text file

* **fwtosim_comparison.py**

The script is used to compare EMP FW simulation with the Out-of-context implementation of the skinny chain.
Currently the script is not used. To use it, something might need some fixing.

Usage:

`-e`: Input file name from EMP firmware simulation
`-s`: Input file name from out-of-context simulation

* **include_cores.py**

This file generates a "Makefile" file named "xciMaker" in order to generate a ".xci" file for each HLS core.

The ".xci" file is needed in order to include the HLS cores in the EMP firmware.

Usage:

`-s`: folder path where the HLS cores are stored

* **ip_tools.tcl**

TCL file needed by Vivado (used in the xciMaker file) to generate the ".xci" file for each HLS core

* **kf_link_mod.py**

The [repository from Thomas Schun](https://github.com/cms-L1TK/l1tk-for-emp) contains some files that needs to be modified in order to work with the skinny chain for EMP.

This script takes care of that.

* **lut_copy.py**

The "SectorProcessor" for the chain needs to have LUTs in the Vivado project directory. For the out-of-context implementation, this need is taken care by [pre.tcl](https://github.com/cms-L1TK/firmware-hls/blob/master/IntegrationTests/ReducedConfig/IRtoTB/script/pre.tcl) script.

In EMP this is a bit more complicated. EMP already uses a pre-synthesis script, so this script appends the needed TCL istructions at the end of the EMP pre-synthesis script.

The script is only used for HW synthesis.

Usage:

* `-s`: Path to the EMP pre-synthesis script

* **pre_msim.tcl/pre_qsim.tcl**

Same for "lut_copy.tcl", these scrips are needed to copy the LUTs used in the "SectorProcessor" into the Vivado/Questa project
