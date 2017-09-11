# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 1 \
    name HLSReducedStubLayer_z_V_write \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_HLSReducedStubLayer_z_V_write \
    op interface \
    ports { HLSReducedStubLayer_z_V_write { I 4 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 2 \
    name HLSReducedStubLayer_phi_V_write \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_HLSReducedStubLayer_phi_V_write \
    op interface \
    ports { HLSReducedStubLayer_phi_V_write { I 3 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 3 \
    name HLSReducedStubLayer_r_V_write \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_HLSReducedStubLayer_r_V_write \
    op interface \
    ports { HLSReducedStubLayer_r_V_write { I 2 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 4 \
    name HLSReducedStubLayer_pt_V_write \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_HLSReducedStubLayer_pt_V_write \
    op interface \
    ports { HLSReducedStubLayer_pt_V_write { I 3 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 5 \
    name HLSReducedStubLayer_index_V_write \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_HLSReducedStubLayer_index_V_write \
    op interface \
    ports { HLSReducedStubLayer_index_V_write { I 6 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_return \
    type ap_return \
    reset_level 1 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 1 vector } } \
} "
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


