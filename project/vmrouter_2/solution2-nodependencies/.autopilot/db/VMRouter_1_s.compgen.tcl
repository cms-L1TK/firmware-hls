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
set in6_width 36
set in6_signed 0
set in7_width 36
set in7_signed 0
set in8_width 36
set in8_signed 0
set in9_width 36
set in9_signed 0
set in10_width 64
set in10_signed 0
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
    in7_width ${in7_width} \
    in7_signed ${in7_signed} \
    in8_width ${in8_width} \
    in8_signed ${in8_signed} \
    in9_width ${in9_width} \
    in9_signed ${in9_signed} \
    in10_width ${in10_width} \
    in10_signed ${in10_signed} \
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
    in7_width ${in7_width} \
    in7_signed ${in7_signed} \
    in8_width ${in8_width} \
    in8_signed ${in8_signed} \
    in9_width ${in9_width} \
    in9_signed ${in9_signed} \
    in10_width ${in10_width} \
    in10_signed ${in10_signed} \
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
    id 7 \
    name stubsInLayer_5_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_5_data \
    op interface \
    ports { stubsInLayer_5_data_address0 { O 6 vector } stubsInLayer_5_data_ce0 { O 1 bit } stubsInLayer_5_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_5_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 8 \
    name stubsInLayer_6_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_6_data \
    op interface \
    ports { stubsInLayer_6_data_address0 { O 6 vector } stubsInLayer_6_data_ce0 { O 1 bit } stubsInLayer_6_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_6_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 9 \
    name stubsInLayer_7_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_7_data \
    op interface \
    ports { stubsInLayer_7_data_address0 { O 6 vector } stubsInLayer_7_data_ce0 { O 1 bit } stubsInLayer_7_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_7_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 10 \
    name stubsInLayer_8_data \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename stubsInLayer_8_data \
    op interface \
    ports { stubsInLayer_8_data_address0 { O 6 vector } stubsInLayer_8_data_ce0 { O 1 bit } stubsInLayer_8_data_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'stubsInLayer_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 12 \
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
    id 13 \
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
    id 14 \
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
    id 15 \
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
    id 16 \
    name allStubs_8_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename allStubs_8_data_V \
    op interface \
    ports { allStubs_8_data_V_address0 { O 6 vector } allStubs_8_data_V_ce0 { O 1 bit } allStubs_8_data_V_we0 { O 1 bit } allStubs_8_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'allStubs_8_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 18 \
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
    id 19 \
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
    id 20 \
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
    id 21 \
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
    id 22 \
    name vmStubsPH1Z1_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z1_8_data \
    op interface \
    ports { vmStubsPH1Z1_8_data_address0 { O 6 vector } vmStubsPH1Z1_8_data_ce0 { O 1 bit } vmStubsPH1Z1_8_data_we0 { O 1 bit } vmStubsPH1Z1_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z1_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 24 \
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
    id 25 \
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
    id 26 \
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
    id 27 \
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
    id 28 \
    name vmStubsPH2Z1_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z1_8_data \
    op interface \
    ports { vmStubsPH2Z1_8_data_address0 { O 6 vector } vmStubsPH2Z1_8_data_ce0 { O 1 bit } vmStubsPH2Z1_8_data_we0 { O 1 bit } vmStubsPH2Z1_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z1_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 30 \
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
    id 31 \
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
    id 32 \
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
    id 33 \
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
    id 34 \
    name vmStubsPH3Z1_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z1_8_data \
    op interface \
    ports { vmStubsPH3Z1_8_data_address0 { O 6 vector } vmStubsPH3Z1_8_data_ce0 { O 1 bit } vmStubsPH3Z1_8_data_we0 { O 1 bit } vmStubsPH3Z1_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z1_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 36 \
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
    id 37 \
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
    id 38 \
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
    id 39 \
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
    id 40 \
    name vmStubsPH4Z1_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z1_8_data \
    op interface \
    ports { vmStubsPH4Z1_8_data_address0 { O 6 vector } vmStubsPH4Z1_8_data_ce0 { O 1 bit } vmStubsPH4Z1_8_data_we0 { O 1 bit } vmStubsPH4Z1_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z1_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 42 \
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
    id 43 \
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
    id 44 \
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
    id 45 \
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
    id 46 \
    name vmStubsPH1Z2_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH1Z2_8_data \
    op interface \
    ports { vmStubsPH1Z2_8_data_address0 { O 6 vector } vmStubsPH1Z2_8_data_ce0 { O 1 bit } vmStubsPH1Z2_8_data_we0 { O 1 bit } vmStubsPH1Z2_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH1Z2_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 48 \
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
    id 49 \
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
    id 50 \
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
    id 51 \
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
    id 52 \
    name vmStubsPH2Z2_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH2Z2_8_data \
    op interface \
    ports { vmStubsPH2Z2_8_data_address0 { O 6 vector } vmStubsPH2Z2_8_data_ce0 { O 1 bit } vmStubsPH2Z2_8_data_we0 { O 1 bit } vmStubsPH2Z2_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH2Z2_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 54 \
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
    id 55 \
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
    id 56 \
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
    id 57 \
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
    id 58 \
    name vmStubsPH3Z2_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH3Z2_8_data \
    op interface \
    ports { vmStubsPH3Z2_8_data_address0 { O 6 vector } vmStubsPH3Z2_8_data_ce0 { O 1 bit } vmStubsPH3Z2_8_data_we0 { O 1 bit } vmStubsPH3Z2_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH3Z2_8_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 60 \
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
    id 61 \
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
    id 62 \
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
    id 63 \
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
    id 64 \
    name vmStubsPH4Z2_8_data \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename vmStubsPH4Z2_8_data \
    op interface \
    ports { vmStubsPH4Z2_8_data_address0 { O 6 vector } vmStubsPH4Z2_8_data_ce0 { O 1 bit } vmStubsPH4Z2_8_data_we0 { O 1 bit } vmStubsPH4Z2_8_data_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'vmStubsPH4Z2_8_data'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 11 \
    name tmp_1 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_1 \
    op interface \
    ports { tmp_1 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 17 \
    name tmp_11 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_11 \
    op interface \
    ports { tmp_11 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 23 \
    name tmp_12 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_12 \
    op interface \
    ports { tmp_12 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 29 \
    name tmp_13 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_13 \
    op interface \
    ports { tmp_13 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 35 \
    name tmp_14 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_14 \
    op interface \
    ports { tmp_14 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 41 \
    name tmp_15 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_15 \
    op interface \
    ports { tmp_15 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 47 \
    name tmp_16 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_16 \
    op interface \
    ports { tmp_16 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 53 \
    name tmp_17 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_17 \
    op interface \
    ports { tmp_17 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 59 \
    name tmp_18 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_18 \
    op interface \
    ports { tmp_18 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 65 \
    name tmp_19 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_tmp_19 \
    op interface \
    ports { tmp_19 { I 9 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 66 \
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
    id 67 \
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
    id 68 \
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
    id 69 \
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
    id 70 \
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
    id 71 \
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
    id 72 \
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
    id 73 \
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
    id 74 \
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


