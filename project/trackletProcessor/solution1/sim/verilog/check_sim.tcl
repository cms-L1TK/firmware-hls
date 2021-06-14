# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc sc_sim_check {ret err logfile} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set errfile "err.log"
    if {[file exists $errfile] && [file size $errfile] != 0} {
        set fl [open $errfile r]
        while {[gets $fl line] >= 0} {
            if {[string first "AESL_mErrNo = " $line] == 0} {
                set mismatch_num [string range $line [string length "AESL_mErrNo = "] end]
                if {$mismatch_num != 0} {
                    ::AP::printMsg ERR COSIM 403 COSIM_403_986 ${mismatch_num}
                    break
                }
            }
        }
    }
    if {$ret || $err != ""} {
        if { [lindex $::errorCode 0] eq "CHILDSTATUS"} {
            set status [lindex $::errorCode 2]
            if {$status != ""} {
                ::AP::printMsg ERR COSIM 404 COSIM_404_987 $status
            } else {
                ::AP::printMsg ERR COSIM 405 COSIM_405_988
            }
        } else {
            ::AP::printMsg ERR COSIM 405 COSIM_405_989
        }
    }
    if {[file exists $logfile]} {
        set cmdret [catch {eval exec "grep \"Error:\" $logfile"} err]
        file delete -force $logfile
        if {$cmdret == 0} {
            ::AP::printMsg ERR COSIM 405 COSIM_405_990
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
}

proc rtl_sim_check {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set errfile "err.log"
    if {[file exists $errfile] && [file size $errfile] != 0} {
        set fl [open $errfile r]
        set unmatch_num 0
        while {[gets $fl line] >= 0} {
            if {[string first "unmatched" $line] != -1} {
                set unmatch_num [expr $unmatch_num + 1]
            }
        }
        if {$unmatch_num != 0} {
            ::AP::printMsg ERR COSIM 406 COSIM_406_991 ${unmatch_num}
        }
    }
    if {[file exists ".aesl_error"]} {
        set errfl [open ".aesl_error" r]
        gets $errfl line
        if {$line != 0} {
            ::AP::printMsg ERR COSIM 407 COSIM_407_992 $line
        }
    }
    if {[file exists ".exit.err"]} {
        ::AP::printMsg ERR COSIM 405 COSIM_405_993
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
}

proc check_tvin_file {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set rtlfilelist {
         "c.TrackletProcessor_L2L3C.autotvin_bx_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_lut_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_regionlut_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_0_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_1_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_2_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_3_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_4_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_5_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_6_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_7_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_0_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_1_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_2_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_3_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_4_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_5_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_6_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_7_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_0_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_1_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_2_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_3_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_4_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_5_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_6_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_7_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerStubs_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_dataarray_data_V_0.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_dataarray_data_V_1.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_0.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_1.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_2.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_3.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_4.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_5.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_6.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_7.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_0.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_1.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_2.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_3.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_4.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_5.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_6.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_7.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_0.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_1.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_2.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_3.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_4.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_5.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_6.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_7.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_0.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_1.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_2.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_3.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_4.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_5.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_6.dat"
         "c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_7.dat"
         "c.TrackletProcessor_L2L3C.autotvin_trackletParameters_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_4_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_1_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_2_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_7_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_1_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_2_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_7_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_9_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_10_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_11_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_13_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_14_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvin_projout_disk_15_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_trackletParameters_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_4_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_1_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_2_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_7_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_1_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_2_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_3_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_5_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_6_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_7_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_9_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_10_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_11_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_13_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_14_dataarray_data_V.dat"
         "c.TrackletProcessor_L2L3C.autotvout_projout_disk_15_dataarray_data_V.dat"
    }
    foreach rtlfile $rtlfilelist {
        if {[file isfile $rtlfile]} {
        } else {
            ::AP::printMsg ERR COSIM 320 COSIM_320_994
            return 1
        }
        set ret [catch {eval exec "grep /runtime $rtlfile"} err]
        if { $ret } {
            ::AP::printMsg ERR COSIM 320 COSIM_320_995
            return 1
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
    return 0
}

proc check_tvout_file {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set rtlfilelist {
         "rtl.TrackletProcessor_L2L3C.autotvout_trackletParameters_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_3_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_4_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_5_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_6_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_1_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_2_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_3_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_5_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_6_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_7_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_1_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_2_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_3_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_5_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_6_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_7_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_9_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_10_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_11_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_13_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_14_dataarray_data_V.dat"
         "rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_15_dataarray_data_V.dat"
    }
    foreach rtlfile $rtlfilelist {
        if {[file isfile $rtlfile]} {
        } else {
            ::AP::printMsg ERR COSIM 303 COSIM_303_996
            return 1
        }
        set ret [catch {eval exec "grep /runtime $rtlfile"} err]
        if { $ret } {
            ::AP::printMsg ERR COSIM 303 COSIM_303_997
            return 1
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
    return 0
}
