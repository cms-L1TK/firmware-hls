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


if {[regexp Vivado $exepath tool]} {
  set VitisOrVivado ""
} elseif {[regexp Vitis $exepath tool]} {
  set VitisOrVivado "_Vitis"
} else {
  puts "Compiling under neither Vivado nor Vitis."
}

