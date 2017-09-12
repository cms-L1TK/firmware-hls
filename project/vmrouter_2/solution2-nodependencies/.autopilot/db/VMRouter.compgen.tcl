# This script segment is generated automatically by AutoPilot

set id 1
set name VMRouterDispatchebkb
set corename simcore_mux
set op mux
set stage_num 1
set max_latency -1
set registered_input 1
set in1_width 36
set in1_signed 0
set in2_width 36
set in2_signed 0
set in3_width 36
set in3_signed 0
set in4_width 36
set in4_signed 0
set in5_width 36
set in5_signed 0
set in6_width 64
set in6_signed 0
set out_width 36
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mux] == "ap_gen_simcore_mux"} {
eval "ap_gen_simcore_mux { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    in2_width ${in2_width} \
    in2_signed ${in2_signed} \
    in3_width ${in3_width} \
    in3_signed ${in3_signed} \
    in4_width ${in4_width} \
    in4_signed ${in4_signed} \
    in5_width ${in5_width} \
    in5_signed ${in5_signed} \
    in6_width ${in6_width} \
    in6_signed ${in6_signed} \
    out_width ${out_width} \
}"
} else {
puts "@W \[IMPL-100\] Cannot find ap_gen_simcore_mux, check your AutoPilot builtin lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler ${name}
}


set op mux
set corename MuxnS
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_pipemux] == "::AESL_LIB_VIRTEX::xil_gen_pipemux"} {
eval "::AESL_LIB_VIRTEX::xil_gen_pipemux { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    in2_width ${in2_width} \
    in2_signed ${in2_signed} \
    in3_width ${in3_width} \
    in3_signed ${in3_signed} \
    in4_width ${in4_width} \
    in4_signed ${in4_signed} \
    in5_width ${in5_width} \
    in5_signed ${in5_signed} \
    in6_width ${in6_width} \
    in6_signed ${in6_signed} \
    out_width ${out_width} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_pipemux, check your platform lib"
}
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 2 \
    name stubsInLayer_0_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_0_data \
    op interface \
    ports { stubsInLayer_0_data_address0 { O 6 vector } stubsInLayer_0_data_ce0 { O 1 bit } stubsInLayer_0_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 3 \
    name stubsInLayer_1_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_1_data \
    op interface \
    ports { stubsInLayer_1_data_address0 { O 6 vector } stubsInLayer_1_data_ce0 { O 1 bit } stubsInLayer_1_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 4 \
    name stubsInLayer_2_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_2_data \
    op interface \
    ports { stubsInLayer_2_data_address0 { O 6 vector } stubsInLayer_2_data_ce0 { O 1 bit } stubsInLayer_2_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 5 \
    name stubsInLayer_3_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_3_data \
    op interface \
    ports { stubsInLayer_3_data_address0 { O 6 vector } stubsInLayer_3_data_ce0 { O 1 bit } stubsInLayer_3_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 6 \
    name stubsInLayer_4_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_4_data \
    op interface \
    ports { stubsInLayer_4_data_address0 { O 6 vector } stubsInLayer_4_data_ce0 { O 1 bit } stubsInLayer_4_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 8 \
    name allStubs_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_0_data_V \
    op interface \
    ports { allStubs_0_data_V_address0 { O 6 vector } allStubs_0_data_V_ce0 { O 1 bit } allStubs_0_data_V_we0 { O 1 bit } allStubs_0_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 9 \
    name allStubs_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_1_data_V \
    op interface \
    ports { allStubs_1_data_V_address0 { O 6 vector } allStubs_1_data_V_ce0 { O 1 bit } allStubs_1_data_V_we0 { O 1 bit } allStubs_1_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 10 \
    name allStubs_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_2_data_V \
    op interface \
    ports { allStubs_2_data_V_address0 { O 6 vector } allStubs_2_data_V_ce0 { O 1 bit } allStubs_2_data_V_we0 { O 1 bit } allStubs_2_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 11 \
    name allStubs_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_3_data_V \
    op interface \
    ports { allStubs_3_data_V_address0 { O 6 vector } allStubs_3_data_V_ce0 { O 1 bit } allStubs_3_data_V_we0 { O 1 bit } allStubs_3_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 12 \
    name allStubs_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_4_data_V \
    op interface \
    ports { allStubs_4_data_V_address0 { O 6 vector } allStubs_4_data_V_ce0 { O 1 bit } allStubs_4_data_V_we0 { O 1 bit } allStubs_4_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 14 \
    name vmStubsPH1Z1_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_0_data \
    op interface \
    ports { vmStubsPH1Z1_0_data_address0 { O 6 vector } vmStubsPH1Z1_0_data_ce0 { O 1 bit } vmStubsPH1Z1_0_data_we0 { O 1 bit } vmStubsPH1Z1_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 15 \
    name vmStubsPH1Z1_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_1_data \
    op interface \
    ports { vmStubsPH1Z1_1_data_address0 { O 6 vector } vmStubsPH1Z1_1_data_ce0 { O 1 bit } vmStubsPH1Z1_1_data_we0 { O 1 bit } vmStubsPH1Z1_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 16 \
    name vmStubsPH1Z1_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_2_data \
    op interface \
    ports { vmStubsPH1Z1_2_data_address0 { O 6 vector } vmStubsPH1Z1_2_data_ce0 { O 1 bit } vmStubsPH1Z1_2_data_we0 { O 1 bit } vmStubsPH1Z1_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 17 \
    name vmStubsPH1Z1_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_3_data \
    op interface \
    ports { vmStubsPH1Z1_3_data_address0 { O 6 vector } vmStubsPH1Z1_3_data_ce0 { O 1 bit } vmStubsPH1Z1_3_data_we0 { O 1 bit } vmStubsPH1Z1_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 18 \
    name vmStubsPH1Z1_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_4_data \
    op interface \
    ports { vmStubsPH1Z1_4_data_address0 { O 6 vector } vmStubsPH1Z1_4_data_ce0 { O 1 bit } vmStubsPH1Z1_4_data_we0 { O 1 bit } vmStubsPH1Z1_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 20 \
    name vmStubsPH2Z1_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_0_data \
    op interface \
    ports { vmStubsPH2Z1_0_data_address0 { O 6 vector } vmStubsPH2Z1_0_data_ce0 { O 1 bit } vmStubsPH2Z1_0_data_we0 { O 1 bit } vmStubsPH2Z1_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 21 \
    name vmStubsPH2Z1_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_1_data \
    op interface \
    ports { vmStubsPH2Z1_1_data_address0 { O 6 vector } vmStubsPH2Z1_1_data_ce0 { O 1 bit } vmStubsPH2Z1_1_data_we0 { O 1 bit } vmStubsPH2Z1_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 22 \
    name vmStubsPH2Z1_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_2_data \
    op interface \
    ports { vmStubsPH2Z1_2_data_address0 { O 6 vector } vmStubsPH2Z1_2_data_ce0 { O 1 bit } vmStubsPH2Z1_2_data_we0 { O 1 bit } vmStubsPH2Z1_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 23 \
    name vmStubsPH2Z1_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_3_data \
    op interface \
    ports { vmStubsPH2Z1_3_data_address0 { O 6 vector } vmStubsPH2Z1_3_data_ce0 { O 1 bit } vmStubsPH2Z1_3_data_we0 { O 1 bit } vmStubsPH2Z1_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 24 \
    name vmStubsPH2Z1_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_4_data \
    op interface \
    ports { vmStubsPH2Z1_4_data_address0 { O 6 vector } vmStubsPH2Z1_4_data_ce0 { O 1 bit } vmStubsPH2Z1_4_data_we0 { O 1 bit } vmStubsPH2Z1_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 26 \
    name vmStubsPH3Z1_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_0_data \
    op interface \
    ports { vmStubsPH3Z1_0_data_address0 { O 6 vector } vmStubsPH3Z1_0_data_ce0 { O 1 bit } vmStubsPH3Z1_0_data_we0 { O 1 bit } vmStubsPH3Z1_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 27 \
    name vmStubsPH3Z1_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_1_data \
    op interface \
    ports { vmStubsPH3Z1_1_data_address0 { O 6 vector } vmStubsPH3Z1_1_data_ce0 { O 1 bit } vmStubsPH3Z1_1_data_we0 { O 1 bit } vmStubsPH3Z1_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 28 \
    name vmStubsPH3Z1_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_2_data \
    op interface \
    ports { vmStubsPH3Z1_2_data_address0 { O 6 vector } vmStubsPH3Z1_2_data_ce0 { O 1 bit } vmStubsPH3Z1_2_data_we0 { O 1 bit } vmStubsPH3Z1_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 29 \
    name vmStubsPH3Z1_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_3_data \
    op interface \
    ports { vmStubsPH3Z1_3_data_address0 { O 6 vector } vmStubsPH3Z1_3_data_ce0 { O 1 bit } vmStubsPH3Z1_3_data_we0 { O 1 bit } vmStubsPH3Z1_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 30 \
    name vmStubsPH3Z1_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_4_data \
    op interface \
    ports { vmStubsPH3Z1_4_data_address0 { O 6 vector } vmStubsPH3Z1_4_data_ce0 { O 1 bit } vmStubsPH3Z1_4_data_we0 { O 1 bit } vmStubsPH3Z1_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 32 \
    name vmStubsPH4Z1_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_0_data \
    op interface \
    ports { vmStubsPH4Z1_0_data_address0 { O 6 vector } vmStubsPH4Z1_0_data_ce0 { O 1 bit } vmStubsPH4Z1_0_data_we0 { O 1 bit } vmStubsPH4Z1_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 33 \
    name vmStubsPH4Z1_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_1_data \
    op interface \
    ports { vmStubsPH4Z1_1_data_address0 { O 6 vector } vmStubsPH4Z1_1_data_ce0 { O 1 bit } vmStubsPH4Z1_1_data_we0 { O 1 bit } vmStubsPH4Z1_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 34 \
    name vmStubsPH4Z1_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_2_data \
    op interface \
    ports { vmStubsPH4Z1_2_data_address0 { O 6 vector } vmStubsPH4Z1_2_data_ce0 { O 1 bit } vmStubsPH4Z1_2_data_we0 { O 1 bit } vmStubsPH4Z1_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 35 \
    name vmStubsPH4Z1_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_3_data \
    op interface \
    ports { vmStubsPH4Z1_3_data_address0 { O 6 vector } vmStubsPH4Z1_3_data_ce0 { O 1 bit } vmStubsPH4Z1_3_data_we0 { O 1 bit } vmStubsPH4Z1_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 36 \
    name vmStubsPH4Z1_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_4_data \
    op interface \
    ports { vmStubsPH4Z1_4_data_address0 { O 6 vector } vmStubsPH4Z1_4_data_ce0 { O 1 bit } vmStubsPH4Z1_4_data_we0 { O 1 bit } vmStubsPH4Z1_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 38 \
    name vmStubsPH1Z2_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_0_data \
    op interface \
    ports { vmStubsPH1Z2_0_data_address0 { O 6 vector } vmStubsPH1Z2_0_data_ce0 { O 1 bit } vmStubsPH1Z2_0_data_we0 { O 1 bit } vmStubsPH1Z2_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 39 \
    name vmStubsPH1Z2_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_1_data \
    op interface \
    ports { vmStubsPH1Z2_1_data_address0 { O 6 vector } vmStubsPH1Z2_1_data_ce0 { O 1 bit } vmStubsPH1Z2_1_data_we0 { O 1 bit } vmStubsPH1Z2_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 40 \
    name vmStubsPH1Z2_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_2_data \
    op interface \
    ports { vmStubsPH1Z2_2_data_address0 { O 6 vector } vmStubsPH1Z2_2_data_ce0 { O 1 bit } vmStubsPH1Z2_2_data_we0 { O 1 bit } vmStubsPH1Z2_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 41 \
    name vmStubsPH1Z2_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_3_data \
    op interface \
    ports { vmStubsPH1Z2_3_data_address0 { O 6 vector } vmStubsPH1Z2_3_data_ce0 { O 1 bit } vmStubsPH1Z2_3_data_we0 { O 1 bit } vmStubsPH1Z2_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 42 \
    name vmStubsPH1Z2_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_4_data \
    op interface \
    ports { vmStubsPH1Z2_4_data_address0 { O 6 vector } vmStubsPH1Z2_4_data_ce0 { O 1 bit } vmStubsPH1Z2_4_data_we0 { O 1 bit } vmStubsPH1Z2_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 44 \
    name vmStubsPH2Z2_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_0_data \
    op interface \
    ports { vmStubsPH2Z2_0_data_address0 { O 6 vector } vmStubsPH2Z2_0_data_ce0 { O 1 bit } vmStubsPH2Z2_0_data_we0 { O 1 bit } vmStubsPH2Z2_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 45 \
    name vmStubsPH2Z2_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_1_data \
    op interface \
    ports { vmStubsPH2Z2_1_data_address0 { O 6 vector } vmStubsPH2Z2_1_data_ce0 { O 1 bit } vmStubsPH2Z2_1_data_we0 { O 1 bit } vmStubsPH2Z2_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 46 \
    name vmStubsPH2Z2_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_2_data \
    op interface \
    ports { vmStubsPH2Z2_2_data_address0 { O 6 vector } vmStubsPH2Z2_2_data_ce0 { O 1 bit } vmStubsPH2Z2_2_data_we0 { O 1 bit } vmStubsPH2Z2_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 47 \
    name vmStubsPH2Z2_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_3_data \
    op interface \
    ports { vmStubsPH2Z2_3_data_address0 { O 6 vector } vmStubsPH2Z2_3_data_ce0 { O 1 bit } vmStubsPH2Z2_3_data_we0 { O 1 bit } vmStubsPH2Z2_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 48 \
    name vmStubsPH2Z2_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_4_data \
    op interface \
    ports { vmStubsPH2Z2_4_data_address0 { O 6 vector } vmStubsPH2Z2_4_data_ce0 { O 1 bit } vmStubsPH2Z2_4_data_we0 { O 1 bit } vmStubsPH2Z2_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 50 \
    name vmStubsPH3Z2_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_0_data \
    op interface \
    ports { vmStubsPH3Z2_0_data_address0 { O 6 vector } vmStubsPH3Z2_0_data_ce0 { O 1 bit } vmStubsPH3Z2_0_data_we0 { O 1 bit } vmStubsPH3Z2_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 51 \
    name vmStubsPH3Z2_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_1_data \
    op interface \
    ports { vmStubsPH3Z2_1_data_address0 { O 6 vector } vmStubsPH3Z2_1_data_ce0 { O 1 bit } vmStubsPH3Z2_1_data_we0 { O 1 bit } vmStubsPH3Z2_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 52 \
    name vmStubsPH3Z2_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_2_data \
    op interface \
    ports { vmStubsPH3Z2_2_data_address0 { O 6 vector } vmStubsPH3Z2_2_data_ce0 { O 1 bit } vmStubsPH3Z2_2_data_we0 { O 1 bit } vmStubsPH3Z2_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 53 \
    name vmStubsPH3Z2_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_3_data \
    op interface \
    ports { vmStubsPH3Z2_3_data_address0 { O 6 vector } vmStubsPH3Z2_3_data_ce0 { O 1 bit } vmStubsPH3Z2_3_data_we0 { O 1 bit } vmStubsPH3Z2_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 54 \
    name vmStubsPH3Z2_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_4_data \
    op interface \
    ports { vmStubsPH3Z2_4_data_address0 { O 6 vector } vmStubsPH3Z2_4_data_ce0 { O 1 bit } vmStubsPH3Z2_4_data_we0 { O 1 bit } vmStubsPH3Z2_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_4_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 56 \
    name vmStubsPH4Z2_0_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_0_data \
    op interface \
    ports { vmStubsPH4Z2_0_data_address0 { O 6 vector } vmStubsPH4Z2_0_data_ce0 { O 1 bit } vmStubsPH4Z2_0_data_we0 { O 1 bit } vmStubsPH4Z2_0_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_0_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 57 \
    name vmStubsPH4Z2_1_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_1_data \
    op interface \
    ports { vmStubsPH4Z2_1_data_address0 { O 6 vector } vmStubsPH4Z2_1_data_ce0 { O 1 bit } vmStubsPH4Z2_1_data_we0 { O 1 bit } vmStubsPH4Z2_1_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_1_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 58 \
    name vmStubsPH4Z2_2_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_2_data \
    op interface \
    ports { vmStubsPH4Z2_2_data_address0 { O 6 vector } vmStubsPH4Z2_2_data_ce0 { O 1 bit } vmStubsPH4Z2_2_data_we0 { O 1 bit } vmStubsPH4Z2_2_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_2_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 59 \
    name vmStubsPH4Z2_3_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_3_data \
    op interface \
    ports { vmStubsPH4Z2_3_data_address0 { O 6 vector } vmStubsPH4Z2_3_data_ce0 { O 1 bit } vmStubsPH4Z2_3_data_we0 { O 1 bit } vmStubsPH4Z2_3_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_3_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 60 \
    name vmStubsPH4Z2_4_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_4_data \
    op interface \
    ports { vmStubsPH4Z2_4_data_address0 { O 6 vector } vmStubsPH4Z2_4_data_ce0 { O 1 bit } vmStubsPH4Z2_4_data_we0 { O 1 bit } vmStubsPH4Z2_4_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_4_data'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 7 \
    name tmp_1 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_1 \
    op interface \
    ports { tmp_1 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 13 \
    name tmp_11 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_11 \
    op interface \
    ports { tmp_11 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 19 \
    name tmp_12 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_12 \
    op interface \
    ports { tmp_12 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 25 \
    name tmp_13 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_13 \
    op interface \
    ports { tmp_13 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 31 \
    name tmp_14 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_14 \
    op interface \
    ports { tmp_14 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 37 \
    name tmp_15 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_15 \
    op interface \
    ports { tmp_15 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 43 \
    name tmp_16 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_16 \
    op interface \
    ports { tmp_16 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 49 \
    name tmp_17 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_17 \
    op interface \
    ports { tmp_17 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 55 \
    name tmp_18 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_18 \
    op interface \
    ports { tmp_18 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 61 \
    name tmp_19 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_19 \
    op interface \
    ports { tmp_19 { I 10 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 62 \
    name nStubs \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nStubs \
    op interface \
    ports { nStubs { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 63 \
    name nPH1Z1_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH1Z1_V_read \
    op interface \
    ports { nPH1Z1_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 64 \
    name nPH2Z1_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH2Z1_V_read \
    op interface \
    ports { nPH2Z1_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 65 \
    name nPH3Z1_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH3Z1_V_read \
    op interface \
    ports { nPH3Z1_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 66 \
    name nPH4Z1_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH4Z1_V_read \
    op interface \
    ports { nPH4Z1_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 67 \
    name nPH1Z2_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH1Z2_V_read \
    op interface \
    ports { nPH1Z2_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 68 \
    name nPH2Z2_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH2Z2_V_read \
    op interface \
    ports { nPH2Z2_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 69 \
    name nPH3Z2_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH3Z2_V_read \
    op interface \
    ports { nPH3Z2_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 70 \
    name nPH4Z2_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nPH4Z2_V_read \
    op interface \
    ports { nPH4Z2_V_read { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -2 \
    name ap_return \
    type ap_return \
    reset_level 1 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 1 vector } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -4 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


