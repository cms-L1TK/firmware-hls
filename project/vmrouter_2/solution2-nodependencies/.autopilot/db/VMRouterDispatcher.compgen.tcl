# This script segment is generated automatically by AutoPilot

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
    id 71 \
    name curStubsInLayer_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename curStubsInLayer_0_data_V \
    op interface \
    ports { curStubsInLayer_0_data_V_address0 { O 6 vector } curStubsInLayer_0_data_V_ce0 { O 1 bit } curStubsInLayer_0_data_V_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curStubsInLayer_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 72 \
    name curStubsInLayer_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename curStubsInLayer_1_data_V \
    op interface \
    ports { curStubsInLayer_1_data_V_address0 { O 6 vector } curStubsInLayer_1_data_V_ce0 { O 1 bit } curStubsInLayer_1_data_V_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curStubsInLayer_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 73 \
    name curStubsInLayer_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename curStubsInLayer_2_data_V \
    op interface \
    ports { curStubsInLayer_2_data_V_address0 { O 6 vector } curStubsInLayer_2_data_V_ce0 { O 1 bit } curStubsInLayer_2_data_V_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curStubsInLayer_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 74 \
    name curStubsInLayer_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename curStubsInLayer_3_data_V \
    op interface \
    ports { curStubsInLayer_3_data_V_address0 { O 6 vector } curStubsInLayer_3_data_V_ce0 { O 1 bit } curStubsInLayer_3_data_V_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curStubsInLayer_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 75 \
    name curStubsInLayer_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename curStubsInLayer_4_data_V \
    op interface \
    ports { curStubsInLayer_4_data_V_address0 { O 6 vector } curStubsInLayer_4_data_V_ce0 { O 1 bit } curStubsInLayer_4_data_V_q0 { I 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curStubsInLayer_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 76 \
    name curAllStubs_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curAllStubs_0_data_V \
    op interface \
    ports { curAllStubs_0_data_V_address0 { O 6 vector } curAllStubs_0_data_V_ce0 { O 1 bit } curAllStubs_0_data_V_we0 { O 1 bit } curAllStubs_0_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curAllStubs_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 77 \
    name curAllStubs_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curAllStubs_1_data_V \
    op interface \
    ports { curAllStubs_1_data_V_address0 { O 6 vector } curAllStubs_1_data_V_ce0 { O 1 bit } curAllStubs_1_data_V_we0 { O 1 bit } curAllStubs_1_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curAllStubs_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 78 \
    name curAllStubs_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curAllStubs_2_data_V \
    op interface \
    ports { curAllStubs_2_data_V_address0 { O 6 vector } curAllStubs_2_data_V_ce0 { O 1 bit } curAllStubs_2_data_V_we0 { O 1 bit } curAllStubs_2_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curAllStubs_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 79 \
    name curAllStubs_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curAllStubs_3_data_V \
    op interface \
    ports { curAllStubs_3_data_V_address0 { O 6 vector } curAllStubs_3_data_V_ce0 { O 1 bit } curAllStubs_3_data_V_we0 { O 1 bit } curAllStubs_3_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curAllStubs_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 80 \
    name curAllStubs_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curAllStubs_4_data_V \
    op interface \
    ports { curAllStubs_4_data_V_address0 { O 6 vector } curAllStubs_4_data_V_ce0 { O 1 bit } curAllStubs_4_data_V_we0 { O 1 bit } curAllStubs_4_data_V_d0 { O 36 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curAllStubs_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 81 \
    name curvmStubsPH1Z1_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z1_0_data_V \
    op interface \
    ports { curvmStubsPH1Z1_0_data_V_address0 { O 6 vector } curvmStubsPH1Z1_0_data_V_ce0 { O 1 bit } curvmStubsPH1Z1_0_data_V_we0 { O 1 bit } curvmStubsPH1Z1_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z1_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 82 \
    name curvmStubsPH1Z1_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z1_1_data_V \
    op interface \
    ports { curvmStubsPH1Z1_1_data_V_address0 { O 6 vector } curvmStubsPH1Z1_1_data_V_ce0 { O 1 bit } curvmStubsPH1Z1_1_data_V_we0 { O 1 bit } curvmStubsPH1Z1_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z1_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 83 \
    name curvmStubsPH1Z1_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z1_2_data_V \
    op interface \
    ports { curvmStubsPH1Z1_2_data_V_address0 { O 6 vector } curvmStubsPH1Z1_2_data_V_ce0 { O 1 bit } curvmStubsPH1Z1_2_data_V_we0 { O 1 bit } curvmStubsPH1Z1_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z1_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 84 \
    name curvmStubsPH1Z1_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z1_3_data_V \
    op interface \
    ports { curvmStubsPH1Z1_3_data_V_address0 { O 6 vector } curvmStubsPH1Z1_3_data_V_ce0 { O 1 bit } curvmStubsPH1Z1_3_data_V_we0 { O 1 bit } curvmStubsPH1Z1_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z1_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 85 \
    name curvmStubsPH1Z1_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z1_4_data_V \
    op interface \
    ports { curvmStubsPH1Z1_4_data_V_address0 { O 6 vector } curvmStubsPH1Z1_4_data_V_ce0 { O 1 bit } curvmStubsPH1Z1_4_data_V_we0 { O 1 bit } curvmStubsPH1Z1_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z1_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 86 \
    name curvmStubsPH2Z1_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z1_0_data_V \
    op interface \
    ports { curvmStubsPH2Z1_0_data_V_address0 { O 6 vector } curvmStubsPH2Z1_0_data_V_ce0 { O 1 bit } curvmStubsPH2Z1_0_data_V_we0 { O 1 bit } curvmStubsPH2Z1_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z1_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 87 \
    name curvmStubsPH2Z1_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z1_1_data_V \
    op interface \
    ports { curvmStubsPH2Z1_1_data_V_address0 { O 6 vector } curvmStubsPH2Z1_1_data_V_ce0 { O 1 bit } curvmStubsPH2Z1_1_data_V_we0 { O 1 bit } curvmStubsPH2Z1_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z1_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 88 \
    name curvmStubsPH2Z1_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z1_2_data_V \
    op interface \
    ports { curvmStubsPH2Z1_2_data_V_address0 { O 6 vector } curvmStubsPH2Z1_2_data_V_ce0 { O 1 bit } curvmStubsPH2Z1_2_data_V_we0 { O 1 bit } curvmStubsPH2Z1_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z1_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 89 \
    name curvmStubsPH2Z1_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z1_3_data_V \
    op interface \
    ports { curvmStubsPH2Z1_3_data_V_address0 { O 6 vector } curvmStubsPH2Z1_3_data_V_ce0 { O 1 bit } curvmStubsPH2Z1_3_data_V_we0 { O 1 bit } curvmStubsPH2Z1_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z1_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 90 \
    name curvmStubsPH2Z1_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z1_4_data_V \
    op interface \
    ports { curvmStubsPH2Z1_4_data_V_address0 { O 6 vector } curvmStubsPH2Z1_4_data_V_ce0 { O 1 bit } curvmStubsPH2Z1_4_data_V_we0 { O 1 bit } curvmStubsPH2Z1_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z1_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 91 \
    name curvmStubsPH3Z1_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z1_0_data_V \
    op interface \
    ports { curvmStubsPH3Z1_0_data_V_address0 { O 6 vector } curvmStubsPH3Z1_0_data_V_ce0 { O 1 bit } curvmStubsPH3Z1_0_data_V_we0 { O 1 bit } curvmStubsPH3Z1_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z1_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 92 \
    name curvmStubsPH3Z1_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z1_1_data_V \
    op interface \
    ports { curvmStubsPH3Z1_1_data_V_address0 { O 6 vector } curvmStubsPH3Z1_1_data_V_ce0 { O 1 bit } curvmStubsPH3Z1_1_data_V_we0 { O 1 bit } curvmStubsPH3Z1_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z1_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 93 \
    name curvmStubsPH3Z1_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z1_2_data_V \
    op interface \
    ports { curvmStubsPH3Z1_2_data_V_address0 { O 6 vector } curvmStubsPH3Z1_2_data_V_ce0 { O 1 bit } curvmStubsPH3Z1_2_data_V_we0 { O 1 bit } curvmStubsPH3Z1_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z1_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 94 \
    name curvmStubsPH3Z1_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z1_3_data_V \
    op interface \
    ports { curvmStubsPH3Z1_3_data_V_address0 { O 6 vector } curvmStubsPH3Z1_3_data_V_ce0 { O 1 bit } curvmStubsPH3Z1_3_data_V_we0 { O 1 bit } curvmStubsPH3Z1_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z1_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 95 \
    name curvmStubsPH3Z1_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z1_4_data_V \
    op interface \
    ports { curvmStubsPH3Z1_4_data_V_address0 { O 6 vector } curvmStubsPH3Z1_4_data_V_ce0 { O 1 bit } curvmStubsPH3Z1_4_data_V_we0 { O 1 bit } curvmStubsPH3Z1_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z1_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 96 \
    name curvmStubsPH4Z1_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z1_0_data_V \
    op interface \
    ports { curvmStubsPH4Z1_0_data_V_address0 { O 6 vector } curvmStubsPH4Z1_0_data_V_ce0 { O 1 bit } curvmStubsPH4Z1_0_data_V_we0 { O 1 bit } curvmStubsPH4Z1_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z1_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 97 \
    name curvmStubsPH4Z1_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z1_1_data_V \
    op interface \
    ports { curvmStubsPH4Z1_1_data_V_address0 { O 6 vector } curvmStubsPH4Z1_1_data_V_ce0 { O 1 bit } curvmStubsPH4Z1_1_data_V_we0 { O 1 bit } curvmStubsPH4Z1_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z1_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 98 \
    name curvmStubsPH4Z1_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z1_2_data_V \
    op interface \
    ports { curvmStubsPH4Z1_2_data_V_address0 { O 6 vector } curvmStubsPH4Z1_2_data_V_ce0 { O 1 bit } curvmStubsPH4Z1_2_data_V_we0 { O 1 bit } curvmStubsPH4Z1_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z1_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 99 \
    name curvmStubsPH4Z1_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z1_3_data_V \
    op interface \
    ports { curvmStubsPH4Z1_3_data_V_address0 { O 6 vector } curvmStubsPH4Z1_3_data_V_ce0 { O 1 bit } curvmStubsPH4Z1_3_data_V_we0 { O 1 bit } curvmStubsPH4Z1_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z1_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 100 \
    name curvmStubsPH4Z1_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z1_4_data_V \
    op interface \
    ports { curvmStubsPH4Z1_4_data_V_address0 { O 6 vector } curvmStubsPH4Z1_4_data_V_ce0 { O 1 bit } curvmStubsPH4Z1_4_data_V_we0 { O 1 bit } curvmStubsPH4Z1_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z1_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 101 \
    name curvmStubsPH1Z2_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z2_0_data_V \
    op interface \
    ports { curvmStubsPH1Z2_0_data_V_address0 { O 6 vector } curvmStubsPH1Z2_0_data_V_ce0 { O 1 bit } curvmStubsPH1Z2_0_data_V_we0 { O 1 bit } curvmStubsPH1Z2_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z2_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 102 \
    name curvmStubsPH1Z2_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z2_1_data_V \
    op interface \
    ports { curvmStubsPH1Z2_1_data_V_address0 { O 6 vector } curvmStubsPH1Z2_1_data_V_ce0 { O 1 bit } curvmStubsPH1Z2_1_data_V_we0 { O 1 bit } curvmStubsPH1Z2_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z2_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 103 \
    name curvmStubsPH1Z2_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z2_2_data_V \
    op interface \
    ports { curvmStubsPH1Z2_2_data_V_address0 { O 6 vector } curvmStubsPH1Z2_2_data_V_ce0 { O 1 bit } curvmStubsPH1Z2_2_data_V_we0 { O 1 bit } curvmStubsPH1Z2_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z2_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 104 \
    name curvmStubsPH1Z2_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z2_3_data_V \
    op interface \
    ports { curvmStubsPH1Z2_3_data_V_address0 { O 6 vector } curvmStubsPH1Z2_3_data_V_ce0 { O 1 bit } curvmStubsPH1Z2_3_data_V_we0 { O 1 bit } curvmStubsPH1Z2_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z2_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 105 \
    name curvmStubsPH1Z2_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH1Z2_4_data_V \
    op interface \
    ports { curvmStubsPH1Z2_4_data_V_address0 { O 6 vector } curvmStubsPH1Z2_4_data_V_ce0 { O 1 bit } curvmStubsPH1Z2_4_data_V_we0 { O 1 bit } curvmStubsPH1Z2_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH1Z2_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 106 \
    name curvmStubsPH2Z2_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z2_0_data_V \
    op interface \
    ports { curvmStubsPH2Z2_0_data_V_address0 { O 6 vector } curvmStubsPH2Z2_0_data_V_ce0 { O 1 bit } curvmStubsPH2Z2_0_data_V_we0 { O 1 bit } curvmStubsPH2Z2_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z2_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 107 \
    name curvmStubsPH2Z2_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z2_1_data_V \
    op interface \
    ports { curvmStubsPH2Z2_1_data_V_address0 { O 6 vector } curvmStubsPH2Z2_1_data_V_ce0 { O 1 bit } curvmStubsPH2Z2_1_data_V_we0 { O 1 bit } curvmStubsPH2Z2_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z2_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 108 \
    name curvmStubsPH2Z2_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z2_2_data_V \
    op interface \
    ports { curvmStubsPH2Z2_2_data_V_address0 { O 6 vector } curvmStubsPH2Z2_2_data_V_ce0 { O 1 bit } curvmStubsPH2Z2_2_data_V_we0 { O 1 bit } curvmStubsPH2Z2_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z2_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 109 \
    name curvmStubsPH2Z2_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z2_3_data_V \
    op interface \
    ports { curvmStubsPH2Z2_3_data_V_address0 { O 6 vector } curvmStubsPH2Z2_3_data_V_ce0 { O 1 bit } curvmStubsPH2Z2_3_data_V_we0 { O 1 bit } curvmStubsPH2Z2_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z2_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 110 \
    name curvmStubsPH2Z2_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH2Z2_4_data_V \
    op interface \
    ports { curvmStubsPH2Z2_4_data_V_address0 { O 6 vector } curvmStubsPH2Z2_4_data_V_ce0 { O 1 bit } curvmStubsPH2Z2_4_data_V_we0 { O 1 bit } curvmStubsPH2Z2_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH2Z2_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 111 \
    name curvmStubsPH3Z2_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z2_0_data_V \
    op interface \
    ports { curvmStubsPH3Z2_0_data_V_address0 { O 6 vector } curvmStubsPH3Z2_0_data_V_ce0 { O 1 bit } curvmStubsPH3Z2_0_data_V_we0 { O 1 bit } curvmStubsPH3Z2_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z2_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 112 \
    name curvmStubsPH3Z2_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z2_1_data_V \
    op interface \
    ports { curvmStubsPH3Z2_1_data_V_address0 { O 6 vector } curvmStubsPH3Z2_1_data_V_ce0 { O 1 bit } curvmStubsPH3Z2_1_data_V_we0 { O 1 bit } curvmStubsPH3Z2_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z2_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 113 \
    name curvmStubsPH3Z2_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z2_2_data_V \
    op interface \
    ports { curvmStubsPH3Z2_2_data_V_address0 { O 6 vector } curvmStubsPH3Z2_2_data_V_ce0 { O 1 bit } curvmStubsPH3Z2_2_data_V_we0 { O 1 bit } curvmStubsPH3Z2_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z2_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 114 \
    name curvmStubsPH3Z2_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z2_3_data_V \
    op interface \
    ports { curvmStubsPH3Z2_3_data_V_address0 { O 6 vector } curvmStubsPH3Z2_3_data_V_ce0 { O 1 bit } curvmStubsPH3Z2_3_data_V_we0 { O 1 bit } curvmStubsPH3Z2_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z2_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 115 \
    name curvmStubsPH3Z2_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH3Z2_4_data_V \
    op interface \
    ports { curvmStubsPH3Z2_4_data_V_address0 { O 6 vector } curvmStubsPH3Z2_4_data_V_ce0 { O 1 bit } curvmStubsPH3Z2_4_data_V_we0 { O 1 bit } curvmStubsPH3Z2_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH3Z2_4_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 116 \
    name curvmStubsPH4Z2_0_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z2_0_data_V \
    op interface \
    ports { curvmStubsPH4Z2_0_data_V_address0 { O 6 vector } curvmStubsPH4Z2_0_data_V_ce0 { O 1 bit } curvmStubsPH4Z2_0_data_V_we0 { O 1 bit } curvmStubsPH4Z2_0_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z2_0_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 117 \
    name curvmStubsPH4Z2_1_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z2_1_data_V \
    op interface \
    ports { curvmStubsPH4Z2_1_data_V_address0 { O 6 vector } curvmStubsPH4Z2_1_data_V_ce0 { O 1 bit } curvmStubsPH4Z2_1_data_V_we0 { O 1 bit } curvmStubsPH4Z2_1_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z2_1_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 118 \
    name curvmStubsPH4Z2_2_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z2_2_data_V \
    op interface \
    ports { curvmStubsPH4Z2_2_data_V_address0 { O 6 vector } curvmStubsPH4Z2_2_data_V_ce0 { O 1 bit } curvmStubsPH4Z2_2_data_V_we0 { O 1 bit } curvmStubsPH4Z2_2_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z2_2_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 119 \
    name curvmStubsPH4Z2_3_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z2_3_data_V \
    op interface \
    ports { curvmStubsPH4Z2_3_data_V_address0 { O 6 vector } curvmStubsPH4Z2_3_data_V_ce0 { O 1 bit } curvmStubsPH4Z2_3_data_V_we0 { O 1 bit } curvmStubsPH4Z2_3_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z2_3_data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 120 \
    name curvmStubsPH4Z2_4_data_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename curvmStubsPH4Z2_4_data_V \
    op interface \
    ports { curvmStubsPH4Z2_4_data_V_address0 { O 6 vector } curvmStubsPH4Z2_4_data_V_ce0 { O 1 bit } curvmStubsPH4Z2_4_data_V_we0 { O 1 bit } curvmStubsPH4Z2_4_data_V_d0 { O 18 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'curvmStubsPH4Z2_4_data_V'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 121 \
    name curnStubs_0 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_curnStubs_0 \
    op interface \
    ports { curnStubs_0 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 122 \
    name curnStubs_1 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_curnStubs_1 \
    op interface \
    ports { curnStubs_1 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 123 \
    name curnStubs_2 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_curnStubs_2 \
    op interface \
    ports { curnStubs_2 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 124 \
    name curnStubs_3 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_curnStubs_3 \
    op interface \
    ports { curnStubs_3 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 125 \
    name curnStubs_4 \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_curnStubs_4 \
    op interface \
    ports { curnStubs_4 { I 32 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 126 \
    name curnPH1Z1_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z1_0_V \
    op interface \
    ports { curnPH1Z1_0_V_i { I 6 vector } curnPH1Z1_0_V_o { O 6 vector } curnPH1Z1_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 127 \
    name curnPH1Z1_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z1_1_V \
    op interface \
    ports { curnPH1Z1_1_V_i { I 6 vector } curnPH1Z1_1_V_o { O 6 vector } curnPH1Z1_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 128 \
    name curnPH1Z1_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z1_2_V \
    op interface \
    ports { curnPH1Z1_2_V_i { I 6 vector } curnPH1Z1_2_V_o { O 6 vector } curnPH1Z1_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 129 \
    name curnPH1Z1_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z1_3_V \
    op interface \
    ports { curnPH1Z1_3_V_i { I 6 vector } curnPH1Z1_3_V_o { O 6 vector } curnPH1Z1_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 130 \
    name curnPH1Z1_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z1_4_V \
    op interface \
    ports { curnPH1Z1_4_V_i { I 6 vector } curnPH1Z1_4_V_o { O 6 vector } curnPH1Z1_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 131 \
    name curnPH2Z1_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z1_0_V \
    op interface \
    ports { curnPH2Z1_0_V_i { I 6 vector } curnPH2Z1_0_V_o { O 6 vector } curnPH2Z1_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 132 \
    name curnPH2Z1_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z1_1_V \
    op interface \
    ports { curnPH2Z1_1_V_i { I 6 vector } curnPH2Z1_1_V_o { O 6 vector } curnPH2Z1_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 133 \
    name curnPH2Z1_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z1_2_V \
    op interface \
    ports { curnPH2Z1_2_V_i { I 6 vector } curnPH2Z1_2_V_o { O 6 vector } curnPH2Z1_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 134 \
    name curnPH2Z1_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z1_3_V \
    op interface \
    ports { curnPH2Z1_3_V_i { I 6 vector } curnPH2Z1_3_V_o { O 6 vector } curnPH2Z1_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 135 \
    name curnPH2Z1_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z1_4_V \
    op interface \
    ports { curnPH2Z1_4_V_i { I 6 vector } curnPH2Z1_4_V_o { O 6 vector } curnPH2Z1_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 136 \
    name curnPH3Z1_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z1_0_V \
    op interface \
    ports { curnPH3Z1_0_V_i { I 6 vector } curnPH3Z1_0_V_o { O 6 vector } curnPH3Z1_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 137 \
    name curnPH3Z1_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z1_1_V \
    op interface \
    ports { curnPH3Z1_1_V_i { I 6 vector } curnPH3Z1_1_V_o { O 6 vector } curnPH3Z1_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 138 \
    name curnPH3Z1_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z1_2_V \
    op interface \
    ports { curnPH3Z1_2_V_i { I 6 vector } curnPH3Z1_2_V_o { O 6 vector } curnPH3Z1_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 139 \
    name curnPH3Z1_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z1_3_V \
    op interface \
    ports { curnPH3Z1_3_V_i { I 6 vector } curnPH3Z1_3_V_o { O 6 vector } curnPH3Z1_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 140 \
    name curnPH3Z1_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z1_4_V \
    op interface \
    ports { curnPH3Z1_4_V_i { I 6 vector } curnPH3Z1_4_V_o { O 6 vector } curnPH3Z1_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 141 \
    name curnPH4Z1_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z1_0_V \
    op interface \
    ports { curnPH4Z1_0_V_i { I 6 vector } curnPH4Z1_0_V_o { O 6 vector } curnPH4Z1_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 142 \
    name curnPH4Z1_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z1_1_V \
    op interface \
    ports { curnPH4Z1_1_V_i { I 6 vector } curnPH4Z1_1_V_o { O 6 vector } curnPH4Z1_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 143 \
    name curnPH4Z1_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z1_2_V \
    op interface \
    ports { curnPH4Z1_2_V_i { I 6 vector } curnPH4Z1_2_V_o { O 6 vector } curnPH4Z1_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 144 \
    name curnPH4Z1_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z1_3_V \
    op interface \
    ports { curnPH4Z1_3_V_i { I 6 vector } curnPH4Z1_3_V_o { O 6 vector } curnPH4Z1_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 145 \
    name curnPH4Z1_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z1_4_V \
    op interface \
    ports { curnPH4Z1_4_V_i { I 6 vector } curnPH4Z1_4_V_o { O 6 vector } curnPH4Z1_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 146 \
    name curnPH1Z2_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z2_0_V \
    op interface \
    ports { curnPH1Z2_0_V_i { I 6 vector } curnPH1Z2_0_V_o { O 6 vector } curnPH1Z2_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 147 \
    name curnPH1Z2_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z2_1_V \
    op interface \
    ports { curnPH1Z2_1_V_i { I 6 vector } curnPH1Z2_1_V_o { O 6 vector } curnPH1Z2_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 148 \
    name curnPH1Z2_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z2_2_V \
    op interface \
    ports { curnPH1Z2_2_V_i { I 6 vector } curnPH1Z2_2_V_o { O 6 vector } curnPH1Z2_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 149 \
    name curnPH1Z2_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z2_3_V \
    op interface \
    ports { curnPH1Z2_3_V_i { I 6 vector } curnPH1Z2_3_V_o { O 6 vector } curnPH1Z2_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 150 \
    name curnPH1Z2_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH1Z2_4_V \
    op interface \
    ports { curnPH1Z2_4_V_i { I 6 vector } curnPH1Z2_4_V_o { O 6 vector } curnPH1Z2_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 151 \
    name curnPH2Z2_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z2_0_V \
    op interface \
    ports { curnPH2Z2_0_V_i { I 6 vector } curnPH2Z2_0_V_o { O 6 vector } curnPH2Z2_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 152 \
    name curnPH2Z2_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z2_1_V \
    op interface \
    ports { curnPH2Z2_1_V_i { I 6 vector } curnPH2Z2_1_V_o { O 6 vector } curnPH2Z2_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 153 \
    name curnPH2Z2_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z2_2_V \
    op interface \
    ports { curnPH2Z2_2_V_i { I 6 vector } curnPH2Z2_2_V_o { O 6 vector } curnPH2Z2_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 154 \
    name curnPH2Z2_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z2_3_V \
    op interface \
    ports { curnPH2Z2_3_V_i { I 6 vector } curnPH2Z2_3_V_o { O 6 vector } curnPH2Z2_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 155 \
    name curnPH2Z2_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH2Z2_4_V \
    op interface \
    ports { curnPH2Z2_4_V_i { I 6 vector } curnPH2Z2_4_V_o { O 6 vector } curnPH2Z2_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 156 \
    name curnPH3Z2_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z2_0_V \
    op interface \
    ports { curnPH3Z2_0_V_i { I 6 vector } curnPH3Z2_0_V_o { O 6 vector } curnPH3Z2_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 157 \
    name curnPH3Z2_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z2_1_V \
    op interface \
    ports { curnPH3Z2_1_V_i { I 6 vector } curnPH3Z2_1_V_o { O 6 vector } curnPH3Z2_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 158 \
    name curnPH3Z2_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z2_2_V \
    op interface \
    ports { curnPH3Z2_2_V_i { I 6 vector } curnPH3Z2_2_V_o { O 6 vector } curnPH3Z2_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 159 \
    name curnPH3Z2_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z2_3_V \
    op interface \
    ports { curnPH3Z2_3_V_i { I 6 vector } curnPH3Z2_3_V_o { O 6 vector } curnPH3Z2_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 160 \
    name curnPH3Z2_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH3Z2_4_V \
    op interface \
    ports { curnPH3Z2_4_V_i { I 6 vector } curnPH3Z2_4_V_o { O 6 vector } curnPH3Z2_4_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 161 \
    name curnPH4Z2_0_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z2_0_V \
    op interface \
    ports { curnPH4Z2_0_V_i { I 6 vector } curnPH4Z2_0_V_o { O 6 vector } curnPH4Z2_0_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 162 \
    name curnPH4Z2_1_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z2_1_V \
    op interface \
    ports { curnPH4Z2_1_V_i { I 6 vector } curnPH4Z2_1_V_o { O 6 vector } curnPH4Z2_1_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 163 \
    name curnPH4Z2_2_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z2_2_V \
    op interface \
    ports { curnPH4Z2_2_V_i { I 6 vector } curnPH4Z2_2_V_o { O 6 vector } curnPH4Z2_2_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 164 \
    name curnPH4Z2_3_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z2_3_V \
    op interface \
    ports { curnPH4Z2_3_V_i { I 6 vector } curnPH4Z2_3_V_o { O 6 vector } curnPH4Z2_3_V_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 165 \
    name curnPH4Z2_4_V \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_curnPH4Z2_4_V \
    op interface \
    ports { curnPH4Z2_4_V_i { I 6 vector } curnPH4Z2_4_V_o { O 6 vector } curnPH4Z2_4_V_o_ap_vld { O 1 bit } } \
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


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
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
    id -3 \
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


