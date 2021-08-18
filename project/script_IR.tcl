# Script to generate project for IR
#   vivado_hls -f script_IR.tcl
#   vivado_hls -p inputrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset inputrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
add_files ../TrackletAlgorithm/InputRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/

set nProc [exec nproc]
set tkNonant 4 

# Link 0
set LinkId 0
open_solution "solution_PS10G_1_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_1_A
# csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
csynth_design
export_design -format ip_catalog

# # Link 1
# set LinkId 1
# open_solution "solution_PS10G_2_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS10G_2_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 2
# set LinkId 2
# open_solution "solution_PS10G_2_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS10G_2_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 3
# set LinkId 3
# open_solution "solution_PS10G_3_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS10G_2_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 4 
# set LinkId 4
# open_solution "solution_PS10G_3_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# # csim_design -mflags "-j$nProc" -argv "--link,4 --tkNonant,4"
# set_top InputRouterTop_IR_DTC_PS10G_3_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 5
# set LinkId 5
# open_solution "solution_PS_1_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS_1_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 6
# set LinkId 6
# open_solution "solution_PS_1_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock 
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS_1_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design 
# export_design -format ip_catalog 

# # Link 7 
# set LinkId 7
# open_solution "solution_PS_2_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS_2_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 8 
# set LinkId 8
# open_solution "solution_PS_2_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_PS_2_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 9
# set LinkId 9 
# open_solution "solution_2S_1_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_1_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 10
# set LinkId 10 
# open_solution "solution_2S_1_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_1_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 11 
# set LinkId 11
# open_solution "solution_2S_2_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_2_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# export_design -format ip_catalog

# # Link 12 
# set LinkId 12
# open_solution "solution_2S_2_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_2_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 13
# set LinkId 13
# open_solution "solution_2S_3_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_3_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 14
# set LinkId 14
# open_solution "solution_2S_3_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_3_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 15
# set LinkId 15
# open_solution "solution_2S_4_A"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_4_A
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

# # Link 16
# set LinkId 16
# open_solution "solution_2S_4_B"
# source settings_hls.tcl
# create_clock -period 240MHz -name slow_clock
# create_clock -period 360MHz -name fast_clock
# set_top InputRouterTop_IR_DTC_2S_4_B
# # csim_design -mflags "-j$nProc" -argv "--link,$LinkId --tkNonant,$tkNonant"
# csynth_design
# export_design -format ip_catalog

exit
