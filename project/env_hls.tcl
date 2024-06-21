# Determine which executable is running
set exepath [info nameofexecutable]
set exe [file tail $exepath]
set version_string [exec $exe -version]
set result [regexp {([20][20][0-9][0-9]\.[1-4])} $version_string version]
set year [string range $version 0 3]

if { ([string first "vitis" $exe] > -1) && ($year > 2019) } {
  interp hide {} open_solution
  interp alias {} open_solution {} interp invokehidden {} -- open_solution -flow_target vivado
} else {
	interp hide {} cosim_design
	interp alias {} cosim_design {} interp invokehidden {} -- cosim_design -verbose
}

# CXXFLAGS adapted from CMSSW_12_6_0_pre5
# Retrieved by running the following:
#   $ scram b echo_CXXFLAGS
set ::env(CCFLAG_CMSSW) "-Wall -Werror=address -Werror=array-bounds -Werror=conversion-null -Werror=delete-non-virtual-dtor -Werror=format -Werror=format-contains-nul -Werror=main -Werror=missing-braces -Werror=narrowing -Werror=overflow -Werror=overlength-strings -Werror=pointer-arith -Werror=reorder -Werror=return-local-addr -Werror=return-type -Werror=strict-aliasing -Werror=switch -Werror=type-limits -Werror=unused-but-set-variable -Werror=unused-value -Werror=unused-variable -Werror=write-strings -Wno-attributes -Wno-deprecated -Wno-ignored-qualifiers -Wno-long-long -Wno-non-template-friend -Wnon-virtual-dtor -Wno-psabi -Wno-unused-but-set-parameter -Wno-unused-label -Wno-unused-local-typedefs -Wno-unused-parameter -Wno-vla -Wparentheses -Wreturn-type -Wunused"
