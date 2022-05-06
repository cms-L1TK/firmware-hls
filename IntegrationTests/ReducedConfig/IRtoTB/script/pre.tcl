# Copy LUTs to xsim or synth_1 directory
set cwd [file tail [pwd]]
file delete -force ./LUTs
if {$cwd == "xsim"} {
  # xsim
  file copy -force ../../../../../../../../../emData/LUTsReduced ./LUTs
} else {
  # synth_1
  file copy -force ../../../../../../../emData/LUTsReduced ./LUTs
}
