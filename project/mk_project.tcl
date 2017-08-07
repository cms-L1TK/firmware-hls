# generate project, run with vivado_hls -f <filename>
# warning, this will wipe out the original project by the same name

set part "xc7vx690tffg1927-2"
set clockperiod 4

# better to delete to remove stale csim output
delete_project vmrouter_2 
open_project -reset vmrouter_2
set_top VMRouterDispatcher 

# source files
add_files ../TrackletAlgorithm/VMRouterDispatcher.cpp
add_files ../TrackletAlgorithm/VMRouter.cpp
add_files -tb ../TestBenches/VMRouter_test.cpp

# should figure out how to add header files right
add_files ../TrackletAlgorithm/HLSConstants.hh
add_files ../TrackletAlgorithm/HLSFullStubLayerPS.hh
add_files ../TrackletAlgorithm/HLSReducedStubLayer.hh
add_files ../TrackletAlgorithm/VMRouter.hh
add_files ../TrackletAlgorithm/VMRouterDispatcher.hh


# add data files
add_files -tb emData



# solutions
############################################################
# solution 1
open_solution "solution1-dependencies"

set_directive_inline "VMRouter"
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z2
set_directive_dependence -variable stubsInLayer -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable allStubs -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH1Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH2Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH3Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH4Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH1Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH2Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH3Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH4Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH1Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH2Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH3Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH4Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH1Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH2Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH3Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH4Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"

set_part  $part 
create_clock -period $clockperiod -name default

csim_design -O
csynth_design
#cosim_design


############################################################
# solution 2
open_solution "solution2-nodependencies"
set_directive_inline "VMRouter"
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z2

set_part  $part 
create_clock -period $clockperiod -name default
csim_design -O
csynth_design
#cosim_design

############################################################
#
# solution 3
open_solution "solution3-noinline"

set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z2



set_part  $part 
create_clock -period $clockperiod -name default

csim_design -O
csynth_design
#cosim_design
#export_design -format ip_catalog

# exit vivado_hls
quit
