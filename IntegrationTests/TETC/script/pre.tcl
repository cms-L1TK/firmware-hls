# Copy LUTs to xim or synth_1 directory
set cwd [file tail [pwd]]
file delete -force ./LUTs
if {$cwd == "xsim"} {
  # xsim
  puts "xsim"
  file copy -force ../../../../../../../../emData/LUTs ./LUTs
} else {
  # synth_1
  puts "synth"
  file copy -force ../../../../../../emData/LUTs ./LUTs
}
