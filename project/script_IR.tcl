# Script to generate project for IR
#   vivado_hls -f script_IR.tcl
#   vivado_hls -p inputrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
array set modules_to_test {
    0 {PS10G_1_A}
    1 {PS10G_1_B}
    2 {PS10G_2_A}
    3 {PS10G_2_B}
    4 {PS10G_3_A}
    5 {PS10G_3_B}
    6 {PS10G_4_A}
    7 {PS10G_4_B}
    8 {PS_1_A}
    9 {PS_1_B}
    10 {PS_2_A}
    11 {PS_2_B}
    24 {2S_1_A}
    25 {2S_1_B}
    26 {2S_2_A}
    27 {2S_2_B}
    28 {2S_3_A}
    29 {2S_3_B}
    30 {2S_4_A}
    31 {2S_4_B}
    32 {2S_5_A}
    33 {2S_5_B}
    34 {2S_6_A}
    35 {2S_6_B}
}

#    12 {negPS10G_1_A}
#    13 {negPS10G_1_B}
#    14 {negPS10G_2_A}
#    15 {negPS10G_2_B}
#    16 {negPS10G_3_A}
#    17 {negPS10G_3_B}
#    18 {negPS10G_4_A}
#    19 {negPS10G_4_B}
#    20 {negPS_1_A}
#    21 {negPS_1_B}
#    22 {negPS_2_A}
#    23 {negPS_2_B}

#    36 {neg2S_1_A}
#    37 {neg2S_1_B}
#    38 {neg2S_2_A}
#    39 {neg2S_2_B}
#    40 {neg2S_3_A}
#    41 {neg2S_3_B}
#    42 {neg2S_4_A}
#    43 {neg2S_4_B}
#    44 {neg2S_5_A}
#    45 {neg2S_5_B}
#    46 {neg2S_6_A}
#    47 {neg2S_6_B}

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export InputRouterTop_IR_DTC_PS10G_3_A

# create new project (deleting any existing one of same name)
open_project -reset inputrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions/CombinedConfig}
add_files ../TopFunctions/CombinedConfig/InputRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/MemPrintsCM/InputStubs/
add_files -tb ../emData/LUTsCM/

set nProc [exec nproc]

foreach i [lsort -integer [array names modules_to_test]] {

    set module $modules_to_test($i)
    puts "======== TESTING IR_$module ========"

    # run C-simulation for each module in modules_to_test
    set top_func "InputRouterTop_IR_DTC_$module"
    set_top $top_func
    open_solution "solution_$top_func"

    create_clock -period 240MHz -name slow_clock 
    create_clock -period 360MHz -name fast_clock

    # Define FPGA, clock frequency & common HLS settings.
    source settings_hls.tcl

    # run C-simulation for each module in modules_to_test
    csim_design -mflags "-j$nProc"  -argv "--link,$i --tkNonant,4"

    # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
    if { $top_func == $module_to_export } {
        csynth_design
        cosim_design -argv "--link,$i --tkNonant,4"
        export_design -format ip_catalog
        # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
        #export_design -format ip_catalog -flow impl
    }
}

exit
