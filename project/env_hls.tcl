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
set ::env(CCFLAG) "-Werror=main -Werror=pointer-arith -Werror=overlength-strings -Wno-vla -Werror=overflow -Werror=array-bounds -Werror=format-contains-nul -Werror=type-limits -Wall -Wno-non-template-friend -Wno-long-long -Wreturn-type -Wno-cast-function-type -Wno-unused-but-set-parameter -Wno-ignored-qualifiers -Wno-deprecated-copy -Wno-unused-parameter -Wunused -Wparentheses -Wno-deprecated -Werror=return-type -Werror=missing-braces -Werror=unused-value -Werror=address -Werror=format -Werror=sign-compare -Werror=write-strings -Werror=delete-non-virtual-dtor -Werror=strict-aliasing -Werror=narrowing -Werror=unused-but-set-variable -Werror=reorder -Werror=unused-variable -Werror=conversion-null -Werror=return-local-addr -Wnon-virtual-dtor -Werror=switch -Wno-unused-local-typedefs -Wno-attributes -Wno-psabi -Wno-unused-label"
