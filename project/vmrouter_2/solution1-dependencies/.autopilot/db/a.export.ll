; ModuleID = '/mnt/scratch/djc448/firmware-hls/project/vmrouter_2/solution1-dependencies/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@llvm_global_ctors_1 = appending global [2 x void ()*] [void ()* @_GLOBAL__I_a, void ()* @_GLOBAL__I_a14]
@llvm_global_ctors_0 = appending global [2 x i32] [i32 65535, i32 65535]
@VMRouterDispatcher_str = internal unnamed_addr constant [19 x i8] c"VMRouterDispatcher\00"
@p_str3 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str14 = private unnamed_addr constant [9 x i8] c"STUBLOOP\00", align 1

declare i7 @llvm.part.select.i7(i7, i32, i32) nounwind readnone

declare i14 @llvm.part.select.i14(i14, i32, i32) nounwind readnone

declare i12 @llvm.part.select.i12(i12, i32, i32) nounwind readnone

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define weak void @_ssdm_op_Write.ap_auto.i6P(i6*, i6) {
entry:
  store i6 %1, i6* %0
  ret void
}

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecRegionEnd(...) {
entry:
  ret i32 0
}

define weak i32 @_ssdm_op_SpecRegionBegin(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecPipeline(...) nounwind {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecLoopName(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

define weak i6 @_ssdm_op_Read.ap_auto.i6P(i6*) {
entry:
  %empty = load i6* %0
  ret i6 %empty
}

define weak i6 @_ssdm_op_Read.ap_auto.i6(i6) {
entry:
  ret i6 %0
}

define weak i4 @_ssdm_op_Read.ap_auto.i4(i4) {
entry:
  ret i4 %0
}

define weak i32 @_ssdm_op_Read.ap_auto.i32P(i32*) {
entry:
  %empty = load i32* %0
  ret i32 %empty
}

define weak i3 @_ssdm_op_Read.ap_auto.i3(i3) {
entry:
  ret i3 %0
}

define weak i2 @_ssdm_op_Read.ap_auto.i2(i2) {
entry:
  ret i2 %0
}

define weak i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12, i32, i32) nounwind readnone {
entry:
  %empty = call i12 @llvm.part.select.i12(i12 %0, i32 %1, i32 %2)
  %empty_8 = trunc i12 %empty to i4
  ret i4 %empty_8
}

define weak i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14, i32, i32) nounwind readnone {
entry:
  %empty = call i14 @llvm.part.select.i14(i14 %0, i32 %1, i32 %2)
  %empty_9 = trunc i14 %empty to i3
  ret i3 %empty_9
}

define weak i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7, i32, i32) nounwind readnone {
entry:
  %empty = call i7 @llvm.part.select.i7(i7 %0, i32 %1, i32 %2)
  %empty_10 = trunc i7 %empty to i2
  ret i2 %empty_10
}

define weak i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14, i32, i32) nounwind readnone {
entry:
  %empty = call i14 @llvm.part.select.i14(i14 %0, i32 %1, i32 %2)
  %empty_11 = trunc i14 %empty to i2
  ret i2 %empty_11
}

define weak i1 @_ssdm_op_BitSelect.i1.i7.i32(i7, i32) nounwind readnone {
entry:
  %empty = trunc i32 %1 to i7
  %empty_12 = shl i7 1, %empty
  %empty_13 = and i7 %0, %empty_12
  %empty_14 = icmp ne i7 %empty_13, 0
  ret i1 %empty_14
}

define weak i1 @_ssdm_op_BitSelect.i1.i12.i32(i12, i32) nounwind readnone {
entry:
  %empty = trunc i32 %1 to i12
  %empty_15 = shl i12 1, %empty
  %empty_16 = and i12 %0, %empty_15
  %empty_17 = icmp ne i12 %empty_16, 0
  ret i1 %empty_17
}

declare void @_GLOBAL__I_a14() nounwind section ".text.startup"

declare void @_GLOBAL__I_a() nounwind section ".text.startup"

define void @VMRouterDispatcher([64 x i12]* %stubsInLayer_0_z_V, [64 x i12]* %stubsInLayer_1_z_V, [64 x i12]* %stubsInLayer_2_z_V, [64 x i12]* %stubsInLayer_3_z_V, [64 x i12]* %stubsInLayer_4_z_V, [64 x i14]* %stubsInLayer_0_phi_V, [64 x i14]* %stubsInLayer_1_phi_V, [64 x i14]* %stubsInLayer_2_phi_V, [64 x i14]* %stubsInLayer_3_phi_V, [64 x i14]* %stubsInLayer_4_phi_V, [64 x i7]* %stubsInLayer_0_r_V, [64 x i7]* %stubsInLayer_1_r_V, [64 x i7]* %stubsInLayer_2_r_V, [64 x i7]* %stubsInLayer_3_r_V, [64 x i7]* %stubsInLayer_4_r_V, [64 x i3]* %stubsInLayer_0_pt_V, [64 x i3]* %stubsInLayer_1_pt_V, [64 x i3]* %stubsInLayer_2_pt_V, [64 x i3]* %stubsInLayer_3_pt_V, [64 x i3]* %stubsInLayer_4_pt_V, [64 x i12]* %allStubs_0_z_V, [64 x i12]* %allStubs_1_z_V, [64 x i12]* %allStubs_2_z_V, [64 x i12]* %allStubs_3_z_V, [64 x i12]* %allStubs_4_z_V, [64 x i14]* %allStubs_0_phi_V, [64 x i14]* %allStubs_1_phi_V, [64 x i14]* %allStubs_2_phi_V, [64 x i14]* %allStubs_3_phi_V, [64 x i14]* %allStubs_4_phi_V, [64 x i7]* %allStubs_0_r_V, [64 x i7]* %allStubs_1_r_V, [64 x i7]* %allStubs_2_r_V, [64 x i7]* %allStubs_3_r_V, [64 x i7]* %allStubs_4_r_V, [64 x i3]* %allStubs_0_pt_V, [64 x i3]* %allStubs_1_pt_V, [64 x i3]* %allStubs_2_pt_V, [64 x i3]* %allStubs_3_pt_V, [64 x i3]* %allStubs_4_pt_V, [64 x i4]* %vmStubsPH1Z1_0_z_V, [64 x i4]* %vmStubsPH1Z1_1_z_V, [64 x i4]* %vmStubsPH1Z1_2_z_V, [64 x i4]* %vmStubsPH1Z1_3_z_V, [64 x i4]* %vmStubsPH1Z1_4_z_V, [64 x i3]* %vmStubsPH1Z1_0_phi_V, [64 x i3]* %vmStubsPH1Z1_1_phi_V, [64 x i3]* %vmStubsPH1Z1_2_phi_V, [64 x i3]* %vmStubsPH1Z1_3_phi_V, [64 x i3]* %vmStubsPH1Z1_4_phi_V, [64 x i2]* %vmStubsPH1Z1_0_r_V, [64 x i2]* %vmStubsPH1Z1_1_r_V, [64 x i2]* %vmStubsPH1Z1_2_r_V, [64 x i2]* %vmStubsPH1Z1_3_r_V, [64 x i2]* %vmStubsPH1Z1_4_r_V, [64 x i3]* %vmStubsPH1Z1_0_pt_V, [64 x i3]* %vmStubsPH1Z1_1_pt_V, [64 x i3]* %vmStubsPH1Z1_2_pt_V, [64 x i3]* %vmStubsPH1Z1_3_pt_V, [64 x i3]* %vmStubsPH1Z1_4_pt_V, [64 x i6]* %vmStubsPH1Z1_0_index_V, [64 x i6]* %vmStubsPH1Z1_1_index_V, [64 x i6]* %vmStubsPH1Z1_2_index_V, [64 x i6]* %vmStubsPH1Z1_3_index_V, [64 x i6]* %vmStubsPH1Z1_4_index_V, [64 x i4]* %vmStubsPH2Z1_0_z_V, [64 x i4]* %vmStubsPH2Z1_1_z_V, [64 x i4]* %vmStubsPH2Z1_2_z_V, [64 x i4]* %vmStubsPH2Z1_3_z_V, [64 x i4]* %vmStubsPH2Z1_4_z_V, [64 x i3]* %vmStubsPH2Z1_0_phi_V, [64 x i3]* %vmStubsPH2Z1_1_phi_V, [64 x i3]* %vmStubsPH2Z1_2_phi_V, [64 x i3]* %vmStubsPH2Z1_3_phi_V, [64 x i3]* %vmStubsPH2Z1_4_phi_V, [64 x i2]* %vmStubsPH2Z1_0_r_V, [64 x i2]* %vmStubsPH2Z1_1_r_V, [64 x i2]* %vmStubsPH2Z1_2_r_V, [64 x i2]* %vmStubsPH2Z1_3_r_V, [64 x i2]* %vmStubsPH2Z1_4_r_V, [64 x i3]* %vmStubsPH2Z1_0_pt_V, [64 x i3]* %vmStubsPH2Z1_1_pt_V, [64 x i3]* %vmStubsPH2Z1_2_pt_V, [64 x i3]* %vmStubsPH2Z1_3_pt_V, [64 x i3]* %vmStubsPH2Z1_4_pt_V, [64 x i6]* %vmStubsPH2Z1_0_index_V, [64 x i6]* %vmStubsPH2Z1_1_index_V, [64 x i6]* %vmStubsPH2Z1_2_index_V, [64 x i6]* %vmStubsPH2Z1_3_index_V, [64 x i6]* %vmStubsPH2Z1_4_index_V, [64 x i4]* %vmStubsPH3Z1_0_z_V, [64 x i4]* %vmStubsPH3Z1_1_z_V, [64 x i4]* %vmStubsPH3Z1_2_z_V, [64 x i4]* %vmStubsPH3Z1_3_z_V, [64 x i4]* %vmStubsPH3Z1_4_z_V, [64 x i3]* %vmStubsPH3Z1_0_phi_V, [64 x i3]* %vmStubsPH3Z1_1_phi_V, [64 x i3]* %vmStubsPH3Z1_2_phi_V, [64 x i3]* %vmStubsPH3Z1_3_phi_V, [64 x i3]* %vmStubsPH3Z1_4_phi_V, [64 x i2]* %vmStubsPH3Z1_0_r_V, [64 x i2]* %vmStubsPH3Z1_1_r_V, [64 x i2]* %vmStubsPH3Z1_2_r_V, [64 x i2]* %vmStubsPH3Z1_3_r_V, [64 x i2]* %vmStubsPH3Z1_4_r_V, [64 x i3]* %vmStubsPH3Z1_0_pt_V, [64 x i3]* %vmStubsPH3Z1_1_pt_V, [64 x i3]* %vmStubsPH3Z1_2_pt_V, [64 x i3]* %vmStubsPH3Z1_3_pt_V, [64 x i3]* %vmStubsPH3Z1_4_pt_V, [64 x i6]* %vmStubsPH3Z1_0_index_V, [64 x i6]* %vmStubsPH3Z1_1_index_V, [64 x i6]* %vmStubsPH3Z1_2_index_V, [64 x i6]* %vmStubsPH3Z1_3_index_V, [64 x i6]* %vmStubsPH3Z1_4_index_V, [64 x i4]* %vmStubsPH4Z1_0_z_V, [64 x i4]* %vmStubsPH4Z1_1_z_V, [64 x i4]* %vmStubsPH4Z1_2_z_V, [64 x i4]* %vmStubsPH4Z1_3_z_V, [64 x i4]* %vmStubsPH4Z1_4_z_V, [64 x i3]* %vmStubsPH4Z1_0_phi_V, [64 x i3]* %vmStubsPH4Z1_1_phi_V, [64 x i3]* %vmStubsPH4Z1_2_phi_V, [64 x i3]* %vmStubsPH4Z1_3_phi_V, [64 x i3]* %vmStubsPH4Z1_4_phi_V, [64 x i2]* %vmStubsPH4Z1_0_r_V, [64 x i2]* %vmStubsPH4Z1_1_r_V, [64 x i2]* %vmStubsPH4Z1_2_r_V, [64 x i2]* %vmStubsPH4Z1_3_r_V, [64 x i2]* %vmStubsPH4Z1_4_r_V, [64 x i3]* %vmStubsPH4Z1_0_pt_V, [64 x i3]* %vmStubsPH4Z1_1_pt_V, [64 x i3]* %vmStubsPH4Z1_2_pt_V, [64 x i3]* %vmStubsPH4Z1_3_pt_V, [64 x i3]* %vmStubsPH4Z1_4_pt_V, [64 x i6]* %vmStubsPH4Z1_0_index_V, [64 x i6]* %vmStubsPH4Z1_1_index_V, [64 x i6]* %vmStubsPH4Z1_2_index_V, [64 x i6]* %vmStubsPH4Z1_3_index_V, [64 x i6]* %vmStubsPH4Z1_4_index_V, [64 x i4]* %vmStubsPH1Z2_0_z_V, [64 x i4]* %vmStubsPH1Z2_1_z_V, [64 x i4]* %vmStubsPH1Z2_2_z_V, [64 x i4]* %vmStubsPH1Z2_3_z_V, [64 x i4]* %vmStubsPH1Z2_4_z_V, [64 x i3]* %vmStubsPH1Z2_0_phi_V, [64 x i3]* %vmStubsPH1Z2_1_phi_V, [64 x i3]* %vmStubsPH1Z2_2_phi_V, [64 x i3]* %vmStubsPH1Z2_3_phi_V, [64 x i3]* %vmStubsPH1Z2_4_phi_V, [64 x i2]* %vmStubsPH1Z2_0_r_V, [64 x i2]* %vmStubsPH1Z2_1_r_V, [64 x i2]* %vmStubsPH1Z2_2_r_V, [64 x i2]* %vmStubsPH1Z2_3_r_V, [64 x i2]* %vmStubsPH1Z2_4_r_V, [64 x i3]* %vmStubsPH1Z2_0_pt_V, [64 x i3]* %vmStubsPH1Z2_1_pt_V, [64 x i3]* %vmStubsPH1Z2_2_pt_V, [64 x i3]* %vmStubsPH1Z2_3_pt_V, [64 x i3]* %vmStubsPH1Z2_4_pt_V, [64 x i6]* %vmStubsPH1Z2_0_index_V, [64 x i6]* %vmStubsPH1Z2_1_index_V, [64 x i6]* %vmStubsPH1Z2_2_index_V, [64 x i6]* %vmStubsPH1Z2_3_index_V, [64 x i6]* %vmStubsPH1Z2_4_index_V, [64 x i4]* %vmStubsPH2Z2_0_z_V, [64 x i4]* %vmStubsPH2Z2_1_z_V, [64 x i4]* %vmStubsPH2Z2_2_z_V, [64 x i4]* %vmStubsPH2Z2_3_z_V, [64 x i4]* %vmStubsPH2Z2_4_z_V, [64 x i3]* %vmStubsPH2Z2_0_phi_V, [64 x i3]* %vmStubsPH2Z2_1_phi_V, [64 x i3]* %vmStubsPH2Z2_2_phi_V, [64 x i3]* %vmStubsPH2Z2_3_phi_V, [64 x i3]* %vmStubsPH2Z2_4_phi_V, [64 x i2]* %vmStubsPH2Z2_0_r_V, [64 x i2]* %vmStubsPH2Z2_1_r_V, [64 x i2]* %vmStubsPH2Z2_2_r_V, [64 x i2]* %vmStubsPH2Z2_3_r_V, [64 x i2]* %vmStubsPH2Z2_4_r_V, [64 x i3]* %vmStubsPH2Z2_0_pt_V, [64 x i3]* %vmStubsPH2Z2_1_pt_V, [64 x i3]* %vmStubsPH2Z2_2_pt_V, [64 x i3]* %vmStubsPH2Z2_3_pt_V, [64 x i3]* %vmStubsPH2Z2_4_pt_V, [64 x i6]* %vmStubsPH2Z2_0_index_V, [64 x i6]* %vmStubsPH2Z2_1_index_V, [64 x i6]* %vmStubsPH2Z2_2_index_V, [64 x i6]* %vmStubsPH2Z2_3_index_V, [64 x i6]* %vmStubsPH2Z2_4_index_V, [64 x i4]* %vmStubsPH3Z2_0_z_V, [64 x i4]* %vmStubsPH3Z2_1_z_V, [64 x i4]* %vmStubsPH3Z2_2_z_V, [64 x i4]* %vmStubsPH3Z2_3_z_V, [64 x i4]* %vmStubsPH3Z2_4_z_V, [64 x i3]* %vmStubsPH3Z2_0_phi_V, [64 x i3]* %vmStubsPH3Z2_1_phi_V, [64 x i3]* %vmStubsPH3Z2_2_phi_V, [64 x i3]* %vmStubsPH3Z2_3_phi_V, [64 x i3]* %vmStubsPH3Z2_4_phi_V, [64 x i2]* %vmStubsPH3Z2_0_r_V, [64 x i2]* %vmStubsPH3Z2_1_r_V, [64 x i2]* %vmStubsPH3Z2_2_r_V, [64 x i2]* %vmStubsPH3Z2_3_r_V, [64 x i2]* %vmStubsPH3Z2_4_r_V, [64 x i3]* %vmStubsPH3Z2_0_pt_V, [64 x i3]* %vmStubsPH3Z2_1_pt_V, [64 x i3]* %vmStubsPH3Z2_2_pt_V, [64 x i3]* %vmStubsPH3Z2_3_pt_V, [64 x i3]* %vmStubsPH3Z2_4_pt_V, [64 x i6]* %vmStubsPH3Z2_0_index_V, [64 x i6]* %vmStubsPH3Z2_1_index_V, [64 x i6]* %vmStubsPH3Z2_2_index_V, [64 x i6]* %vmStubsPH3Z2_3_index_V, [64 x i6]* %vmStubsPH3Z2_4_index_V, [64 x i4]* %vmStubsPH4Z2_0_z_V, [64 x i4]* %vmStubsPH4Z2_1_z_V, [64 x i4]* %vmStubsPH4Z2_2_z_V, [64 x i4]* %vmStubsPH4Z2_3_z_V, [64 x i4]* %vmStubsPH4Z2_4_z_V, [64 x i3]* %vmStubsPH4Z2_0_phi_V, [64 x i3]* %vmStubsPH4Z2_1_phi_V, [64 x i3]* %vmStubsPH4Z2_2_phi_V, [64 x i3]* %vmStubsPH4Z2_3_phi_V, [64 x i3]* %vmStubsPH4Z2_4_phi_V, [64 x i2]* %vmStubsPH4Z2_0_r_V, [64 x i2]* %vmStubsPH4Z2_1_r_V, [64 x i2]* %vmStubsPH4Z2_2_r_V, [64 x i2]* %vmStubsPH4Z2_3_r_V, [64 x i2]* %vmStubsPH4Z2_4_r_V, [64 x i3]* %vmStubsPH4Z2_0_pt_V, [64 x i3]* %vmStubsPH4Z2_1_pt_V, [64 x i3]* %vmStubsPH4Z2_2_pt_V, [64 x i3]* %vmStubsPH4Z2_3_pt_V, [64 x i3]* %vmStubsPH4Z2_4_pt_V, [64 x i6]* %vmStubsPH4Z2_0_index_V, [64 x i6]* %vmStubsPH4Z2_1_index_V, [64 x i6]* %vmStubsPH4Z2_2_index_V, [64 x i6]* %vmStubsPH4Z2_3_index_V, [64 x i6]* %vmStubsPH4Z2_4_index_V, i32* %nStubs_0, i32* %nStubs_1, i32* %nStubs_2, i32* %nStubs_3, i32* %nStubs_4, i6* %nPH1Z1_0_V, i6* %nPH1Z1_1_V, i6* %nPH1Z1_2_V, i6* %nPH1Z1_3_V, i6* %nPH1Z1_4_V, i6* %nPH2Z1_0_V, i6* %nPH2Z1_1_V, i6* %nPH2Z1_2_V, i6* %nPH2Z1_3_V, i6* %nPH2Z1_4_V, i6* %nPH3Z1_0_V, i6* %nPH3Z1_1_V, i6* %nPH3Z1_2_V, i6* %nPH3Z1_3_V, i6* %nPH3Z1_4_V, i6* %nPH4Z1_0_V, i6* %nPH4Z1_1_V, i6* %nPH4Z1_2_V, i6* %nPH4Z1_3_V, i6* %nPH4Z1_4_V, i6* %nPH1Z2_0_V, i6* %nPH1Z2_1_V, i6* %nPH1Z2_2_V, i6* %nPH1Z2_3_V, i6* %nPH1Z2_4_V, i6* %nPH2Z2_0_V, i6* %nPH2Z2_1_V, i6* %nPH2Z2_2_V, i6* %nPH2Z2_3_V, i6* %nPH2Z2_4_V, i6* %nPH3Z2_0_V, i6* %nPH3Z2_1_V, i6* %nPH3Z2_2_V, i6* %nPH3Z2_3_V, i6* %nPH3Z2_4_V, i6* %nPH4Z2_0_V, i6* %nPH4Z2_1_V, i6* %nPH4Z2_2_V, i6* %nPH4Z2_3_V, i6* %nPH4Z2_4_V) {
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z2_4_index_V), !map !94
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z2_3_index_V), !map !100
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z2_2_index_V), !map !106
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z2_1_index_V), !map !112
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z2_0_index_V), !map !118
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_4_pt_V), !map !124
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_3_pt_V), !map !128
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_2_pt_V), !map !132
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_1_pt_V), !map !136
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_0_pt_V), !map !140
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z2_4_r_V), !map !144
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z2_3_r_V), !map !148
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z2_2_r_V), !map !152
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z2_1_r_V), !map !156
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z2_0_r_V), !map !160
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_4_phi_V), !map !164
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_3_phi_V), !map !168
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_2_phi_V), !map !172
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_1_phi_V), !map !176
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z2_0_phi_V), !map !180
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z2_4_z_V), !map !184
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z2_3_z_V), !map !188
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z2_2_z_V), !map !192
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z2_1_z_V), !map !196
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z2_0_z_V), !map !200
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z2_4_index_V), !map !204
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z2_3_index_V), !map !208
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z2_2_index_V), !map !212
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z2_1_index_V), !map !216
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z2_0_index_V), !map !220
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_4_pt_V), !map !224
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_3_pt_V), !map !228
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_2_pt_V), !map !232
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_1_pt_V), !map !236
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_0_pt_V), !map !240
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z2_4_r_V), !map !244
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z2_3_r_V), !map !248
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z2_2_r_V), !map !252
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z2_1_r_V), !map !256
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z2_0_r_V), !map !260
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_4_phi_V), !map !264
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_3_phi_V), !map !268
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_2_phi_V), !map !272
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_1_phi_V), !map !276
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z2_0_phi_V), !map !280
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z2_4_z_V), !map !284
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z2_3_z_V), !map !288
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z2_2_z_V), !map !292
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z2_1_z_V), !map !296
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z2_0_z_V), !map !300
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z2_4_index_V), !map !304
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z2_3_index_V), !map !308
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z2_2_index_V), !map !312
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z2_1_index_V), !map !316
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z2_0_index_V), !map !320
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_4_pt_V), !map !324
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_3_pt_V), !map !328
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_2_pt_V), !map !332
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_1_pt_V), !map !336
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_0_pt_V), !map !340
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z2_4_r_V), !map !344
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z2_3_r_V), !map !348
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z2_2_r_V), !map !352
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z2_1_r_V), !map !356
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z2_0_r_V), !map !360
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_4_phi_V), !map !364
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_3_phi_V), !map !368
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_2_phi_V), !map !372
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_1_phi_V), !map !376
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z2_0_phi_V), !map !380
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z2_4_z_V), !map !384
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z2_3_z_V), !map !388
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z2_2_z_V), !map !392
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z2_1_z_V), !map !396
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z2_0_z_V), !map !400
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z2_4_index_V), !map !404
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z2_3_index_V), !map !408
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z2_2_index_V), !map !412
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z2_1_index_V), !map !416
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z2_0_index_V), !map !420
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_4_pt_V), !map !424
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_3_pt_V), !map !428
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_2_pt_V), !map !432
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_1_pt_V), !map !436
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_0_pt_V), !map !440
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z2_4_r_V), !map !444
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z2_3_r_V), !map !448
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z2_2_r_V), !map !452
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z2_1_r_V), !map !456
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z2_0_r_V), !map !460
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_4_phi_V), !map !464
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_3_phi_V), !map !468
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_2_phi_V), !map !472
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_1_phi_V), !map !476
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z2_0_phi_V), !map !480
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z2_4_z_V), !map !484
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z2_3_z_V), !map !488
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z2_2_z_V), !map !492
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z2_1_z_V), !map !496
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z2_0_z_V), !map !500
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z1_4_index_V), !map !504
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z1_3_index_V), !map !508
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z1_2_index_V), !map !512
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z1_1_index_V), !map !516
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH4Z1_0_index_V), !map !520
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_4_pt_V), !map !524
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_3_pt_V), !map !528
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_2_pt_V), !map !532
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_1_pt_V), !map !536
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_0_pt_V), !map !540
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z1_4_r_V), !map !544
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z1_3_r_V), !map !548
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z1_2_r_V), !map !552
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z1_1_r_V), !map !556
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH4Z1_0_r_V), !map !560
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_4_phi_V), !map !564
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_3_phi_V), !map !568
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_2_phi_V), !map !572
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_1_phi_V), !map !576
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH4Z1_0_phi_V), !map !580
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z1_4_z_V), !map !584
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z1_3_z_V), !map !588
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z1_2_z_V), !map !592
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z1_1_z_V), !map !596
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH4Z1_0_z_V), !map !600
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z1_4_index_V), !map !604
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z1_3_index_V), !map !608
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z1_2_index_V), !map !612
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z1_1_index_V), !map !616
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH3Z1_0_index_V), !map !620
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_4_pt_V), !map !624
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_3_pt_V), !map !628
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_2_pt_V), !map !632
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_1_pt_V), !map !636
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_0_pt_V), !map !640
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z1_4_r_V), !map !644
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z1_3_r_V), !map !648
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z1_2_r_V), !map !652
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z1_1_r_V), !map !656
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH3Z1_0_r_V), !map !660
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_4_phi_V), !map !664
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_3_phi_V), !map !668
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_2_phi_V), !map !672
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_1_phi_V), !map !676
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH3Z1_0_phi_V), !map !680
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z1_4_z_V), !map !684
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z1_3_z_V), !map !688
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z1_2_z_V), !map !692
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z1_1_z_V), !map !696
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH3Z1_0_z_V), !map !700
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z1_4_index_V), !map !704
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z1_3_index_V), !map !708
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z1_2_index_V), !map !712
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z1_1_index_V), !map !716
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH2Z1_0_index_V), !map !720
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_4_pt_V), !map !724
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_3_pt_V), !map !728
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_2_pt_V), !map !732
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_1_pt_V), !map !736
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_0_pt_V), !map !740
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z1_4_r_V), !map !744
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z1_3_r_V), !map !748
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z1_2_r_V), !map !752
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z1_1_r_V), !map !756
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH2Z1_0_r_V), !map !760
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_4_phi_V), !map !764
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_3_phi_V), !map !768
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_2_phi_V), !map !772
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_1_phi_V), !map !776
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH2Z1_0_phi_V), !map !780
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z1_4_z_V), !map !784
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z1_3_z_V), !map !788
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z1_2_z_V), !map !792
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z1_1_z_V), !map !796
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH2Z1_0_z_V), !map !800
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z1_4_index_V), !map !804
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z1_3_index_V), !map !808
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z1_2_index_V), !map !812
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z1_1_index_V), !map !816
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i6]* %vmStubsPH1Z1_0_index_V), !map !820
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_4_pt_V), !map !824
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_3_pt_V), !map !828
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_2_pt_V), !map !832
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_1_pt_V), !map !836
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_0_pt_V), !map !840
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z1_4_r_V), !map !844
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z1_3_r_V), !map !848
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z1_2_r_V), !map !852
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z1_1_r_V), !map !856
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i2]* %vmStubsPH1Z1_0_r_V), !map !860
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_4_phi_V), !map !864
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_3_phi_V), !map !868
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_2_phi_V), !map !872
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_1_phi_V), !map !876
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %vmStubsPH1Z1_0_phi_V), !map !880
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z1_4_z_V), !map !884
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z1_3_z_V), !map !888
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z1_2_z_V), !map !892
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z1_1_z_V), !map !896
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i4]* %vmStubsPH1Z1_0_z_V), !map !900
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %allStubs_4_pt_V), !map !904
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %allStubs_3_pt_V), !map !908
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %allStubs_2_pt_V), !map !912
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %allStubs_1_pt_V), !map !916
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %allStubs_0_pt_V), !map !920
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %allStubs_4_r_V), !map !924
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %allStubs_3_r_V), !map !928
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %allStubs_2_r_V), !map !932
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %allStubs_1_r_V), !map !936
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %allStubs_0_r_V), !map !940
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %allStubs_4_phi_V), !map !944
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %allStubs_3_phi_V), !map !948
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %allStubs_2_phi_V), !map !952
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %allStubs_1_phi_V), !map !956
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %allStubs_0_phi_V), !map !960
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %allStubs_4_z_V), !map !964
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %allStubs_3_z_V), !map !968
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %allStubs_2_z_V), !map !972
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %allStubs_1_z_V), !map !976
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %allStubs_0_z_V), !map !980
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %nStubs_4), !map !984
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %nStubs_3), !map !990
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %nStubs_2), !map !996
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %nStubs_1), !map !1002
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %nStubs_0), !map !1008
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %stubsInLayer_4_pt_V), !map !1014
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %stubsInLayer_3_pt_V), !map !1018
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %stubsInLayer_2_pt_V), !map !1022
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %stubsInLayer_1_pt_V), !map !1026
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i3]* %stubsInLayer_0_pt_V), !map !1030
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %stubsInLayer_4_r_V), !map !1034
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %stubsInLayer_3_r_V), !map !1038
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %stubsInLayer_2_r_V), !map !1042
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %stubsInLayer_1_r_V), !map !1046
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i7]* %stubsInLayer_0_r_V), !map !1050
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %stubsInLayer_4_phi_V), !map !1054
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %stubsInLayer_3_phi_V), !map !1058
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %stubsInLayer_2_phi_V), !map !1062
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %stubsInLayer_1_phi_V), !map !1066
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i14]* %stubsInLayer_0_phi_V), !map !1070
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %stubsInLayer_4_z_V), !map !1074
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %stubsInLayer_3_z_V), !map !1078
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %stubsInLayer_2_z_V), !map !1082
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %stubsInLayer_1_z_V), !map !1086
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i12]* %stubsInLayer_0_z_V), !map !1090
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z2_4_V), !map !1094
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z2_3_V), !map !1098
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z2_2_V), !map !1102
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z2_1_V), !map !1106
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z2_0_V), !map !1110
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z1_4_V), !map !1114
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z1_3_V), !map !1118
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z1_2_V), !map !1122
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z1_1_V), !map !1126
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z1_0_V), !map !1130
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z2_4_V), !map !1134
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z2_3_V), !map !1138
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z2_2_V), !map !1142
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z2_1_V), !map !1146
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH3Z2_0_V), !map !1150
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z1_4_V), !map !1154
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z1_3_V), !map !1158
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z1_2_V), !map !1162
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z1_1_V), !map !1166
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z1_0_V), !map !1170
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z1_4_V), !map !1174
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z1_3_V), !map !1178
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z1_2_V), !map !1182
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z1_1_V), !map !1186
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z1_0_V), !map !1190
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z2_4_V), !map !1194
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z2_3_V), !map !1198
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z2_2_V), !map !1202
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z2_1_V), !map !1206
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH4Z2_0_V), !map !1210
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z1_4_V), !map !1214
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z1_3_V), !map !1218
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z1_2_V), !map !1222
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z1_1_V), !map !1226
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH1Z1_0_V), !map !1230
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z2_4_V), !map !1234
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z2_3_V), !map !1238
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z2_2_V), !map !1242
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z2_1_V), !map !1246
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %nPH2Z2_0_V), !map !1250
  call void (...)* @_ssdm_op_SpecTopModule([19 x i8]* @VMRouterDispatcher_str) nounwind
  %nStubs_0_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %nStubs_0)
  br label %1

; <label>:1                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71, %0
  %p_s = phi i6 [ 0, %0 ], [ %index_V, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71 ]
  %i_0_i1 = phi i7 [ 0, %0 ], [ %i, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71 ]
  %tmp = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i_0_i1, i32 6)
  %index_V = add i6 %p_s, 1
  br i1 %tmp, label %VMRouter.exit72, label %2

; <label>:2                                       ; preds = %1
  %i_0_i1_cast = zext i7 %i_0_i1 to i32
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str14) nounwind
  %tmp_2 = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str14)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str3) nounwind
  %tmp_1 = icmp slt i32 %i_0_i1_cast, %nStubs_0_read
  br i1 %tmp_1, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i67, label %VMRouter.exit72

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i67: ; preds = %2
  %p_1 = zext i6 %p_s to i64
  %stubsInLayer_0_z_V_addr = getelementptr [64 x i12]* %stubsInLayer_0_z_V, i64 0, i64 %p_1
  %stubsInLayer_0_phi_V_addr = getelementptr [64 x i14]* %stubsInLayer_0_phi_V, i64 0, i64 %p_1
  %stubsInLayer_0_r_V_addr = getelementptr [64 x i7]* %stubsInLayer_0_r_V, i64 0, i64 %p_1
  %stubsInLayer_0_pt_V_addr = getelementptr [64 x i3]* %stubsInLayer_0_pt_V, i64 0, i64 %p_1
  %curZ_V = load i12* %stubsInLayer_0_z_V_addr, align 2
  %curPhi_V = load i14* %stubsInLayer_0_phi_V_addr, align 2
  %curR_V = load i7* %stubsInLayer_0_r_V_addr, align 1
  %redPt_V = load i3* %stubsInLayer_0_pt_V_addr, align 1
  %allStubs_0_z_V_addr = getelementptr [64 x i12]* %allStubs_0_z_V, i64 0, i64 %p_1
  %allStubs_0_phi_V_addr = getelementptr [64 x i14]* %allStubs_0_phi_V, i64 0, i64 %p_1
  %allStubs_0_r_V_addr = getelementptr [64 x i7]* %allStubs_0_r_V, i64 0, i64 %p_1
  %allStubs_0_pt_V_addr = getelementptr [64 x i3]* %allStubs_0_pt_V, i64 0, i64 %p_1
  store i12 %curZ_V, i12* %allStubs_0_z_V_addr, align 2
  store i14 %curPhi_V, i14* %allStubs_0_phi_V_addr, align 2
  store i7 %curR_V, i7* %allStubs_0_r_V_addr, align 1
  store i3 %redPt_V, i3* %allStubs_0_pt_V_addr, align 1
  %redZ_V = call i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12 %curZ_V, i32 5, i32 8)
  %redPhi_V = call i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14 %curPhi_V, i32 9, i32 11)
  %redR_V = call i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7 %curR_V, i32 5, i32 6)
  %routePhi_V = call i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14 %curPhi_V, i32 12, i32 13)
  %routeZ_V = call i1 @_ssdm_op_BitSelect.i1.i12.i32(i12 %curZ_V, i32 9)
  br i1 %routeZ_V, label %4, label %3

; <label>:3                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i67
  switch i2 %routePhi_V, label %._crit_edge.i68 [
    i2 0, label %branch0
    i2 1, label %branch20675
    i2 -2, label %branch0735
    i2 -1, label %branch20931
  ]

branch0:                                          ; preds = %3
  %nPH1Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z1_0_V)
  %nPH1Z1_V_load1 = zext i6 %nPH1Z1_0_V_read to i64
  %vmStubsPH1Z1_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z1_0_z_V, i64 0, i64 %nPH1Z1_V_load1
  %vmStubsPH1Z1_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_0_phi_V, i64 0, i64 %nPH1Z1_V_load1
  %vmStubsPH1Z1_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z1_0_r_V, i64 0, i64 %nPH1Z1_V_load1
  %vmStubsPH1Z1_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_0_pt_V, i64 0, i64 %nPH1Z1_V_load1
  %vmStubsPH1Z1_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z1_0_index_V, i64 0, i64 %nPH1Z1_V_load1
  %call_ret2 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH1Z1_z_V_addr89_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret2, 0
  store i4 %vmStubsPH1Z1_z_V_addr89_ret, i4* %vmStubsPH1Z1_0_z_V_addr, align 1
  %vmStubsPH1Z1_phi_V_addr100_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret2, 1
  store i3 %vmStubsPH1Z1_phi_V_addr100_ret, i3* %vmStubsPH1Z1_0_phi_V_addr, align 1
  %vmStubsPH1Z1_r_V_addr111_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret2, 2
  store i2 %vmStubsPH1Z1_r_V_addr111_ret, i2* %vmStubsPH1Z1_0_r_V_addr, align 1
  %vmStubsPH1Z1_pt_V_addr122_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret2, 3
  store i3 %vmStubsPH1Z1_pt_V_addr122_ret, i3* %vmStubsPH1Z1_0_pt_V_addr, align 1
  %vmStubsPH1Z1_index_V_addr133_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret2, 4
  store i6 %vmStubsPH1Z1_index_V_addr133_r, i6* %vmStubsPH1Z1_0_index_V_addr, align 1
  %tmp_7 = add i6 %nPH1Z1_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z1_0_V, i6 %tmp_7)
  br label %._crit_edge.i68

branch20675:                                      ; preds = %3
  %nPH2Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z1_0_V)
  %nPH2Z1_V_load = zext i6 %nPH2Z1_0_V_read to i64
  %vmStubsPH2Z1_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z1_0_z_V, i64 0, i64 %nPH2Z1_V_load
  %vmStubsPH2Z1_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_0_phi_V, i64 0, i64 %nPH2Z1_V_load
  %vmStubsPH2Z1_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z1_0_r_V, i64 0, i64 %nPH2Z1_V_load
  %vmStubsPH2Z1_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_0_pt_V, i64 0, i64 %nPH2Z1_V_load
  %vmStubsPH2Z1_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z1_0_index_V, i64 0, i64 %nPH2Z1_V_load
  %call_ret3 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH2Z1_z_V_addr144_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret3, 0
  store i4 %vmStubsPH2Z1_z_V_addr144_ret, i4* %vmStubsPH2Z1_0_z_V_addr, align 1
  %vmStubsPH2Z1_phi_V_addr155_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret3, 1
  store i3 %vmStubsPH2Z1_phi_V_addr155_ret, i3* %vmStubsPH2Z1_0_phi_V_addr, align 1
  %vmStubsPH2Z1_r_V_addr166_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret3, 2
  store i2 %vmStubsPH2Z1_r_V_addr166_ret, i2* %vmStubsPH2Z1_0_r_V_addr, align 1
  %vmStubsPH2Z1_pt_V_addr177_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret3, 3
  store i3 %vmStubsPH2Z1_pt_V_addr177_ret, i3* %vmStubsPH2Z1_0_pt_V_addr, align 1
  %vmStubsPH2Z1_index_V_addr188_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret3, 4
  store i6 %vmStubsPH2Z1_index_V_addr188_r, i6* %vmStubsPH2Z1_0_index_V_addr, align 1
  %tmp_9 = add i6 %nPH2Z1_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z1_0_V, i6 %tmp_9)
  br label %._crit_edge.i68

branch0735:                                       ; preds = %3
  %nPH3Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z1_0_V)
  %nPH3Z1_V_load1 = zext i6 %nPH3Z1_0_V_read to i64
  %vmStubsPH3Z1_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z1_0_z_V, i64 0, i64 %nPH3Z1_V_load1
  %vmStubsPH3Z1_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_0_phi_V, i64 0, i64 %nPH3Z1_V_load1
  %vmStubsPH3Z1_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z1_0_r_V, i64 0, i64 %nPH3Z1_V_load1
  %vmStubsPH3Z1_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_0_pt_V, i64 0, i64 %nPH3Z1_V_load1
  %vmStubsPH3Z1_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z1_0_index_V, i64 0, i64 %nPH3Z1_V_load1
  %call_ret4 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH3Z1_z_V_addr199_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret4, 0
  store i4 %vmStubsPH3Z1_z_V_addr199_ret, i4* %vmStubsPH3Z1_0_z_V_addr, align 1
  %vmStubsPH3Z1_phi_V_addr210_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret4, 1
  store i3 %vmStubsPH3Z1_phi_V_addr210_ret, i3* %vmStubsPH3Z1_0_phi_V_addr, align 1
  %vmStubsPH3Z1_r_V_addr221_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret4, 2
  store i2 %vmStubsPH3Z1_r_V_addr221_ret, i2* %vmStubsPH3Z1_0_r_V_addr, align 1
  %vmStubsPH3Z1_pt_V_addr232_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret4, 3
  store i3 %vmStubsPH3Z1_pt_V_addr232_ret, i3* %vmStubsPH3Z1_0_pt_V_addr, align 1
  %vmStubsPH3Z1_index_V_addr243_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret4, 4
  store i6 %vmStubsPH3Z1_index_V_addr243_r, i6* %vmStubsPH3Z1_0_index_V_addr, align 1
  %tmp_10 = add i6 %nPH3Z1_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z1_0_V, i6 %tmp_10)
  br label %._crit_edge.i68

branch20931:                                      ; preds = %3
  %nPH4Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z1_0_V)
  %nPH4Z1_V_load = zext i6 %nPH4Z1_0_V_read to i64
  %vmStubsPH4Z1_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z1_0_z_V, i64 0, i64 %nPH4Z1_V_load
  %vmStubsPH4Z1_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_0_phi_V, i64 0, i64 %nPH4Z1_V_load
  %vmStubsPH4Z1_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z1_0_r_V, i64 0, i64 %nPH4Z1_V_load
  %vmStubsPH4Z1_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_0_pt_V, i64 0, i64 %nPH4Z1_V_load
  %vmStubsPH4Z1_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z1_0_index_V, i64 0, i64 %nPH4Z1_V_load
  %call_ret5 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH4Z1_z_V_addr254_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret5, 0
  store i4 %vmStubsPH4Z1_z_V_addr254_ret, i4* %vmStubsPH4Z1_0_z_V_addr, align 1
  %vmStubsPH4Z1_phi_V_addr265_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret5, 1
  store i3 %vmStubsPH4Z1_phi_V_addr265_ret, i3* %vmStubsPH4Z1_0_phi_V_addr, align 1
  %vmStubsPH4Z1_r_V_addr276_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret5, 2
  store i2 %vmStubsPH4Z1_r_V_addr276_ret, i2* %vmStubsPH4Z1_0_r_V_addr, align 1
  %vmStubsPH4Z1_pt_V_addr287_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret5, 3
  store i3 %vmStubsPH4Z1_pt_V_addr287_ret, i3* %vmStubsPH4Z1_0_pt_V_addr, align 1
  %vmStubsPH4Z1_index_V_addr298_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret5, 4
  store i6 %vmStubsPH4Z1_index_V_addr298_r, i6* %vmStubsPH4Z1_0_index_V_addr, align 1
  %tmp_11 = add i6 %nPH4Z1_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z1_0_V, i6 %tmp_11)
  br label %._crit_edge.i68

._crit_edge.i68:                                  ; preds = %branch20931, %branch0735, %branch20675, %branch0, %3
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71

; <label>:4                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i67
  switch i2 %routePhi_V, label %._crit_edge400.i69 [
    i2 0, label %branch0995
    i2 1, label %branch201181
    i2 -2, label %branch01245
    i2 -1, label %branch201425
  ]

branch0995:                                       ; preds = %4
  %nPH1Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z2_0_V)
  %nPH1Z2_V_load1 = zext i6 %nPH1Z2_0_V_read to i64
  %vmStubsPH1Z2_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z2_0_z_V, i64 0, i64 %nPH1Z2_V_load1
  %vmStubsPH1Z2_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_0_phi_V, i64 0, i64 %nPH1Z2_V_load1
  %vmStubsPH1Z2_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z2_0_r_V, i64 0, i64 %nPH1Z2_V_load1
  %vmStubsPH1Z2_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_0_pt_V, i64 0, i64 %nPH1Z2_V_load1
  %vmStubsPH1Z2_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z2_0_index_V, i64 0, i64 %nPH1Z2_V_load1
  %call_ret6 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH1Z2_z_V_addr309_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret6, 0
  store i4 %vmStubsPH1Z2_z_V_addr309_ret, i4* %vmStubsPH1Z2_0_z_V_addr, align 1
  %vmStubsPH1Z2_phi_V_addr320_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret6, 1
  store i3 %vmStubsPH1Z2_phi_V_addr320_ret, i3* %vmStubsPH1Z2_0_phi_V_addr, align 1
  %vmStubsPH1Z2_r_V_addr331_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret6, 2
  store i2 %vmStubsPH1Z2_r_V_addr331_ret, i2* %vmStubsPH1Z2_0_r_V_addr, align 1
  %vmStubsPH1Z2_pt_V_addr342_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret6, 3
  store i3 %vmStubsPH1Z2_pt_V_addr342_ret, i3* %vmStubsPH1Z2_0_pt_V_addr, align 1
  %vmStubsPH1Z2_index_V_addr353_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret6, 4
  store i6 %vmStubsPH1Z2_index_V_addr353_r, i6* %vmStubsPH1Z2_0_index_V_addr, align 1
  %tmp_3 = add i6 %nPH1Z2_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z2_0_V, i6 %tmp_3)
  br label %._crit_edge400.i69

branch201181:                                     ; preds = %4
  %nPH2Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z2_0_V)
  %nPH2Z2_V_load = zext i6 %nPH2Z2_0_V_read to i64
  %vmStubsPH2Z2_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z2_0_z_V, i64 0, i64 %nPH2Z2_V_load
  %vmStubsPH2Z2_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_0_phi_V, i64 0, i64 %nPH2Z2_V_load
  %vmStubsPH2Z2_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z2_0_r_V, i64 0, i64 %nPH2Z2_V_load
  %vmStubsPH2Z2_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_0_pt_V, i64 0, i64 %nPH2Z2_V_load
  %vmStubsPH2Z2_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z2_0_index_V, i64 0, i64 %nPH2Z2_V_load
  %call_ret7 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH2Z2_z_V_addr364_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret7, 0
  store i4 %vmStubsPH2Z2_z_V_addr364_ret, i4* %vmStubsPH2Z2_0_z_V_addr, align 1
  %vmStubsPH2Z2_phi_V_addr375_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret7, 1
  store i3 %vmStubsPH2Z2_phi_V_addr375_ret, i3* %vmStubsPH2Z2_0_phi_V_addr, align 1
  %vmStubsPH2Z2_r_V_addr386_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret7, 2
  store i2 %vmStubsPH2Z2_r_V_addr386_ret, i2* %vmStubsPH2Z2_0_r_V_addr, align 1
  %vmStubsPH2Z2_pt_V_addr397_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret7, 3
  store i3 %vmStubsPH2Z2_pt_V_addr397_ret, i3* %vmStubsPH2Z2_0_pt_V_addr, align 1
  %vmStubsPH2Z2_index_V_addr408_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret7, 4
  store i6 %vmStubsPH2Z2_index_V_addr408_r, i6* %vmStubsPH2Z2_0_index_V_addr, align 1
  %tmp_4 = add i6 %nPH2Z2_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z2_0_V, i6 %tmp_4)
  br label %._crit_edge400.i69

branch01245:                                      ; preds = %4
  %nPH3Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z2_0_V)
  %nPH3Z2_V_load1 = zext i6 %nPH3Z2_0_V_read to i64
  %vmStubsPH3Z2_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z2_0_z_V, i64 0, i64 %nPH3Z2_V_load1
  %vmStubsPH3Z2_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_0_phi_V, i64 0, i64 %nPH3Z2_V_load1
  %vmStubsPH3Z2_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z2_0_r_V, i64 0, i64 %nPH3Z2_V_load1
  %vmStubsPH3Z2_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_0_pt_V, i64 0, i64 %nPH3Z2_V_load1
  %vmStubsPH3Z2_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z2_0_index_V, i64 0, i64 %nPH3Z2_V_load1
  %call_ret8 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH3Z2_z_V_addr419_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret8, 0
  store i4 %vmStubsPH3Z2_z_V_addr419_ret, i4* %vmStubsPH3Z2_0_z_V_addr, align 1
  %vmStubsPH3Z2_phi_V_addr430_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret8, 1
  store i3 %vmStubsPH3Z2_phi_V_addr430_ret, i3* %vmStubsPH3Z2_0_phi_V_addr, align 1
  %vmStubsPH3Z2_r_V_addr441_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret8, 2
  store i2 %vmStubsPH3Z2_r_V_addr441_ret, i2* %vmStubsPH3Z2_0_r_V_addr, align 1
  %vmStubsPH3Z2_pt_V_addr452_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret8, 3
  store i3 %vmStubsPH3Z2_pt_V_addr452_ret, i3* %vmStubsPH3Z2_0_pt_V_addr, align 1
  %vmStubsPH3Z2_index_V_addr463_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret8, 4
  store i6 %vmStubsPH3Z2_index_V_addr463_r, i6* %vmStubsPH3Z2_0_index_V_addr, align 1
  %tmp_5 = add i6 %nPH3Z2_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z2_0_V, i6 %tmp_5)
  br label %._crit_edge400.i69

branch201425:                                     ; preds = %4
  %nPH4Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z2_0_V)
  %nPH4Z2_V_load = zext i6 %nPH4Z2_0_V_read to i64
  %vmStubsPH4Z2_0_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z2_0_z_V, i64 0, i64 %nPH4Z2_V_load
  %vmStubsPH4Z2_0_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_0_phi_V, i64 0, i64 %nPH4Z2_V_load
  %vmStubsPH4Z2_0_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z2_0_r_V, i64 0, i64 %nPH4Z2_V_load
  %vmStubsPH4Z2_0_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_0_pt_V, i64 0, i64 %nPH4Z2_V_load
  %vmStubsPH4Z2_0_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z2_0_index_V, i64 0, i64 %nPH4Z2_V_load
  %call_ret9 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V, i3 %redPhi_V, i2 %redR_V, i3 %redPt_V, i6 %p_s)
  %vmStubsPH4Z2_z_V_addr474_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret9, 0
  store i4 %vmStubsPH4Z2_z_V_addr474_ret, i4* %vmStubsPH4Z2_0_z_V_addr, align 1
  %vmStubsPH4Z2_phi_V_addr485_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret9, 1
  store i3 %vmStubsPH4Z2_phi_V_addr485_ret, i3* %vmStubsPH4Z2_0_phi_V_addr, align 1
  %vmStubsPH4Z2_r_V_addr496_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret9, 2
  store i2 %vmStubsPH4Z2_r_V_addr496_ret, i2* %vmStubsPH4Z2_0_r_V_addr, align 1
  %vmStubsPH4Z2_pt_V_addr507_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret9, 3
  store i3 %vmStubsPH4Z2_pt_V_addr507_ret, i3* %vmStubsPH4Z2_0_pt_V_addr, align 1
  %vmStubsPH4Z2_index_V_addr518_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret9, 4
  store i6 %vmStubsPH4Z2_index_V_addr518_r, i6* %vmStubsPH4Z2_0_index_V_addr, align 1
  %tmp_6 = add i6 %nPH4Z2_0_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z2_0_V, i6 %tmp_6)
  br label %._crit_edge400.i69

._crit_edge400.i69:                               ; preds = %branch201425, %branch01245, %branch201181, %branch0995, %4
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i71: ; preds = %._crit_edge400.i69, %._crit_edge.i68
  %empty_18 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str14, i32 %tmp_2)
  %i = add i7 %i_0_i1, 1
  br label %1

VMRouter.exit72:                                  ; preds = %1, %2
  %nStubs_1_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %nStubs_1)
  br label %5

; <label>:5                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53, %VMRouter.exit72
  %p_0 = phi i6 [ 0, %VMRouter.exit72 ], [ %index_V_1, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53 ]
  %i_0_i2 = phi i7 [ 0, %VMRouter.exit72 ], [ %i_1, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53 ]
  %tmp_13 = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i_0_i2, i32 6)
  %index_V_1 = add i6 %p_0, 1
  br i1 %tmp_13, label %VMRouter.exit54, label %6

; <label>:6                                       ; preds = %5
  %i_0_i2_cast8 = zext i7 %i_0_i2 to i32
  %empty_19 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str14) nounwind
  %tmp_8 = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str14)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str3) nounwind
  %tmp_s = icmp slt i32 %i_0_i2_cast8, %nStubs_1_read
  br i1 %tmp_s, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i49, label %VMRouter.exit54

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i49: ; preds = %6
  %p_6 = zext i6 %p_0 to i64
  %stubsInLayer_1_z_V_addr = getelementptr [64 x i12]* %stubsInLayer_1_z_V, i64 0, i64 %p_6
  %stubsInLayer_1_phi_V_addr = getelementptr [64 x i14]* %stubsInLayer_1_phi_V, i64 0, i64 %p_6
  %stubsInLayer_1_r_V_addr = getelementptr [64 x i7]* %stubsInLayer_1_r_V, i64 0, i64 %p_6
  %stubsInLayer_1_pt_V_addr = getelementptr [64 x i3]* %stubsInLayer_1_pt_V, i64 0, i64 %p_6
  %curZ_V_1 = load i12* %stubsInLayer_1_z_V_addr, align 2
  %curPhi_V_1 = load i14* %stubsInLayer_1_phi_V_addr, align 2
  %curR_V_1 = load i7* %stubsInLayer_1_r_V_addr, align 1
  %redPt_V_1 = load i3* %stubsInLayer_1_pt_V_addr, align 1
  %allStubs_1_z_V_addr = getelementptr [64 x i12]* %allStubs_1_z_V, i64 0, i64 %p_6
  %allStubs_1_phi_V_addr = getelementptr [64 x i14]* %allStubs_1_phi_V, i64 0, i64 %p_6
  %allStubs_1_r_V_addr = getelementptr [64 x i7]* %allStubs_1_r_V, i64 0, i64 %p_6
  %allStubs_1_pt_V_addr = getelementptr [64 x i3]* %allStubs_1_pt_V, i64 0, i64 %p_6
  store i12 %curZ_V_1, i12* %allStubs_1_z_V_addr, align 2
  store i14 %curPhi_V_1, i14* %allStubs_1_phi_V_addr, align 2
  store i7 %curR_V_1, i7* %allStubs_1_r_V_addr, align 1
  store i3 %redPt_V_1, i3* %allStubs_1_pt_V_addr, align 1
  %redZ_V_1 = call i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12 %curZ_V_1, i32 5, i32 8)
  %redPhi_V_1 = call i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14 %curPhi_V_1, i32 9, i32 11)
  %redR_V_1 = call i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7 %curR_V_1, i32 5, i32 6)
  %routePhi_V_1 = call i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14 %curPhi_V_1, i32 12, i32 13)
  %routeZ_V_1 = call i1 @_ssdm_op_BitSelect.i1.i12.i32(i12 %curZ_V_1, i32 9)
  br i1 %routeZ_V_1, label %8, label %7

; <label>:7                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i49
  switch i2 %routePhi_V_1, label %._crit_edge.i50 [
    i2 0, label %branch6
    i2 1, label %branch16665
    i2 -2, label %branch6763
    i2 -1, label %branch16921
  ]

branch6:                                          ; preds = %7
  %nPH1Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z1_1_V)
  %newIndex = zext i6 %nPH1Z1_1_V_read to i64
  %vmStubsPH1Z1_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z1_1_z_V, i64 0, i64 %newIndex
  %vmStubsPH1Z1_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_1_phi_V, i64 0, i64 %newIndex
  %vmStubsPH1Z1_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z1_1_r_V, i64 0, i64 %newIndex
  %vmStubsPH1Z1_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_1_pt_V, i64 0, i64 %newIndex
  %vmStubsPH1Z1_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z1_1_index_V, i64 0, i64 %newIndex
  %call_ret1 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH1Z1_z_V_addr_191_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret1, 0
  store i4 %vmStubsPH1Z1_z_V_addr_191_ret, i4* %vmStubsPH1Z1_1_z_V_addr, align 1
  %vmStubsPH1Z1_phi_V_addr_1102_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret1, 1
  store i3 %vmStubsPH1Z1_phi_V_addr_1102_r, i3* %vmStubsPH1Z1_1_phi_V_addr, align 1
  %vmStubsPH1Z1_r_V_addr_1113_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret1, 2
  store i2 %vmStubsPH1Z1_r_V_addr_1113_ret, i2* %vmStubsPH1Z1_1_r_V_addr, align 1
  %vmStubsPH1Z1_pt_V_addr_1124_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret1, 3
  store i3 %vmStubsPH1Z1_pt_V_addr_1124_re, i3* %vmStubsPH1Z1_1_pt_V_addr, align 1
  %vmStubsPH1Z1_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret1, 4
  store i6 %vmStubsPH1Z1_index_V_addr_s, i6* %vmStubsPH1Z1_1_index_V_addr, align 1
  %tmp_19 = add i6 %nPH1Z1_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z1_1_V, i6 %tmp_19)
  br label %._crit_edge.i50

branch16665:                                      ; preds = %7
  %nPH2Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z1_1_V)
  %newIndex1 = zext i6 %nPH2Z1_1_V_read to i64
  %vmStubsPH2Z1_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z1_1_z_V, i64 0, i64 %newIndex1
  %vmStubsPH2Z1_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_1_phi_V, i64 0, i64 %newIndex1
  %vmStubsPH2Z1_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z1_1_r_V, i64 0, i64 %newIndex1
  %vmStubsPH2Z1_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_1_pt_V, i64 0, i64 %newIndex1
  %vmStubsPH2Z1_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z1_1_index_V, i64 0, i64 %newIndex1
  %call_ret10 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH2Z1_z_V_addr_1146_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret10, 0
  store i4 %vmStubsPH2Z1_z_V_addr_1146_ret, i4* %vmStubsPH2Z1_1_z_V_addr, align 1
  %vmStubsPH2Z1_phi_V_addr_1157_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret10, 1
  store i3 %vmStubsPH2Z1_phi_V_addr_1157_r, i3* %vmStubsPH2Z1_1_phi_V_addr, align 1
  %vmStubsPH2Z1_r_V_addr_1168_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret10, 2
  store i2 %vmStubsPH2Z1_r_V_addr_1168_ret, i2* %vmStubsPH2Z1_1_r_V_addr, align 1
  %vmStubsPH2Z1_pt_V_addr_1179_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret10, 3
  store i3 %vmStubsPH2Z1_pt_V_addr_1179_re, i3* %vmStubsPH2Z1_1_pt_V_addr, align 1
  %vmStubsPH2Z1_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret10, 4
  store i6 %vmStubsPH2Z1_index_V_addr_s, i6* %vmStubsPH2Z1_1_index_V_addr, align 1
  %tmp_20 = add i6 %nPH2Z1_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z1_1_V, i6 %tmp_20)
  br label %._crit_edge.i50

branch6763:                                       ; preds = %7
  %nPH3Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z1_1_V)
  %newIndex2 = zext i6 %nPH3Z1_1_V_read to i64
  %vmStubsPH3Z1_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z1_1_z_V, i64 0, i64 %newIndex2
  %vmStubsPH3Z1_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_1_phi_V, i64 0, i64 %newIndex2
  %vmStubsPH3Z1_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z1_1_r_V, i64 0, i64 %newIndex2
  %vmStubsPH3Z1_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_1_pt_V, i64 0, i64 %newIndex2
  %vmStubsPH3Z1_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z1_1_index_V, i64 0, i64 %newIndex2
  %call_ret11 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH3Z1_z_V_addr_1201_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret11, 0
  store i4 %vmStubsPH3Z1_z_V_addr_1201_ret, i4* %vmStubsPH3Z1_1_z_V_addr, align 1
  %vmStubsPH3Z1_phi_V_addr_1212_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret11, 1
  store i3 %vmStubsPH3Z1_phi_V_addr_1212_r, i3* %vmStubsPH3Z1_1_phi_V_addr, align 1
  %vmStubsPH3Z1_r_V_addr_1223_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret11, 2
  store i2 %vmStubsPH3Z1_r_V_addr_1223_ret, i2* %vmStubsPH3Z1_1_r_V_addr, align 1
  %vmStubsPH3Z1_pt_V_addr_1234_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret11, 3
  store i3 %vmStubsPH3Z1_pt_V_addr_1234_re, i3* %vmStubsPH3Z1_1_pt_V_addr, align 1
  %vmStubsPH3Z1_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret11, 4
  store i6 %vmStubsPH3Z1_index_V_addr_s, i6* %vmStubsPH3Z1_1_index_V_addr, align 1
  %tmp_21 = add i6 %nPH3Z1_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z1_1_V, i6 %tmp_21)
  br label %._crit_edge.i50

branch16921:                                      ; preds = %7
  %nPH4Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z1_1_V)
  %newIndex3 = zext i6 %nPH4Z1_1_V_read to i64
  %vmStubsPH4Z1_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z1_1_z_V, i64 0, i64 %newIndex3
  %vmStubsPH4Z1_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_1_phi_V, i64 0, i64 %newIndex3
  %vmStubsPH4Z1_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z1_1_r_V, i64 0, i64 %newIndex3
  %vmStubsPH4Z1_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_1_pt_V, i64 0, i64 %newIndex3
  %vmStubsPH4Z1_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z1_1_index_V, i64 0, i64 %newIndex3
  %call_ret12 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH4Z1_z_V_addr_1256_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret12, 0
  store i4 %vmStubsPH4Z1_z_V_addr_1256_ret, i4* %vmStubsPH4Z1_1_z_V_addr, align 1
  %vmStubsPH4Z1_phi_V_addr_1267_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret12, 1
  store i3 %vmStubsPH4Z1_phi_V_addr_1267_r, i3* %vmStubsPH4Z1_1_phi_V_addr, align 1
  %vmStubsPH4Z1_r_V_addr_1278_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret12, 2
  store i2 %vmStubsPH4Z1_r_V_addr_1278_ret, i2* %vmStubsPH4Z1_1_r_V_addr, align 1
  %vmStubsPH4Z1_pt_V_addr_1289_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret12, 3
  store i3 %vmStubsPH4Z1_pt_V_addr_1289_re, i3* %vmStubsPH4Z1_1_pt_V_addr, align 1
  %vmStubsPH4Z1_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret12, 4
  store i6 %vmStubsPH4Z1_index_V_addr_s, i6* %vmStubsPH4Z1_1_index_V_addr, align 1
  %tmp_22 = add i6 %nPH4Z1_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z1_1_V, i6 %tmp_22)
  br label %._crit_edge.i50

._crit_edge.i50:                                  ; preds = %branch16921, %branch6763, %branch16665, %branch6, %7
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53

; <label>:8                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i49
  switch i2 %routePhi_V_1, label %._crit_edge400.i51 [
    i2 0, label %branch61011
    i2 1, label %branch161171
    i2 -2, label %branch61261
    i2 -1, label %branch161415
  ]

branch61011:                                      ; preds = %8
  %nPH1Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z2_1_V)
  %newIndex4 = zext i6 %nPH1Z2_1_V_read to i64
  %vmStubsPH1Z2_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z2_1_z_V, i64 0, i64 %newIndex4
  %vmStubsPH1Z2_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_1_phi_V, i64 0, i64 %newIndex4
  %vmStubsPH1Z2_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z2_1_r_V, i64 0, i64 %newIndex4
  %vmStubsPH1Z2_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_1_pt_V, i64 0, i64 %newIndex4
  %vmStubsPH1Z2_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z2_1_index_V, i64 0, i64 %newIndex4
  %call_ret13 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH1Z2_z_V_addr_1311_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret13, 0
  store i4 %vmStubsPH1Z2_z_V_addr_1311_ret, i4* %vmStubsPH1Z2_1_z_V_addr, align 1
  %vmStubsPH1Z2_phi_V_addr_1322_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret13, 1
  store i3 %vmStubsPH1Z2_phi_V_addr_1322_r, i3* %vmStubsPH1Z2_1_phi_V_addr, align 1
  %vmStubsPH1Z2_r_V_addr_1333_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret13, 2
  store i2 %vmStubsPH1Z2_r_V_addr_1333_ret, i2* %vmStubsPH1Z2_1_r_V_addr, align 1
  %vmStubsPH1Z2_pt_V_addr_1344_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret13, 3
  store i3 %vmStubsPH1Z2_pt_V_addr_1344_re, i3* %vmStubsPH1Z2_1_pt_V_addr, align 1
  %vmStubsPH1Z2_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret13, 4
  store i6 %vmStubsPH1Z2_index_V_addr_s, i6* %vmStubsPH1Z2_1_index_V_addr, align 1
  %tmp_12 = add i6 %nPH1Z2_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z2_1_V, i6 %tmp_12)
  br label %._crit_edge400.i51

branch161171:                                     ; preds = %8
  %nPH2Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z2_1_V)
  %newIndex5 = zext i6 %nPH2Z2_1_V_read to i64
  %vmStubsPH2Z2_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z2_1_z_V, i64 0, i64 %newIndex5
  %vmStubsPH2Z2_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_1_phi_V, i64 0, i64 %newIndex5
  %vmStubsPH2Z2_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z2_1_r_V, i64 0, i64 %newIndex5
  %vmStubsPH2Z2_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_1_pt_V, i64 0, i64 %newIndex5
  %vmStubsPH2Z2_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z2_1_index_V, i64 0, i64 %newIndex5
  %call_ret14 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH2Z2_z_V_addr_1366_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret14, 0
  store i4 %vmStubsPH2Z2_z_V_addr_1366_ret, i4* %vmStubsPH2Z2_1_z_V_addr, align 1
  %vmStubsPH2Z2_phi_V_addr_1377_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret14, 1
  store i3 %vmStubsPH2Z2_phi_V_addr_1377_r, i3* %vmStubsPH2Z2_1_phi_V_addr, align 1
  %vmStubsPH2Z2_r_V_addr_1388_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret14, 2
  store i2 %vmStubsPH2Z2_r_V_addr_1388_ret, i2* %vmStubsPH2Z2_1_r_V_addr, align 1
  %vmStubsPH2Z2_pt_V_addr_1399_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret14, 3
  store i3 %vmStubsPH2Z2_pt_V_addr_1399_re, i3* %vmStubsPH2Z2_1_pt_V_addr, align 1
  %vmStubsPH2Z2_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret14, 4
  store i6 %vmStubsPH2Z2_index_V_addr_s, i6* %vmStubsPH2Z2_1_index_V_addr, align 1
  %tmp_16 = add i6 %nPH2Z2_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z2_1_V, i6 %tmp_16)
  br label %._crit_edge400.i51

branch61261:                                      ; preds = %8
  %nPH3Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z2_1_V)
  %newIndex6 = zext i6 %nPH3Z2_1_V_read to i64
  %vmStubsPH3Z2_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z2_1_z_V, i64 0, i64 %newIndex6
  %vmStubsPH3Z2_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_1_phi_V, i64 0, i64 %newIndex6
  %vmStubsPH3Z2_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z2_1_r_V, i64 0, i64 %newIndex6
  %vmStubsPH3Z2_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_1_pt_V, i64 0, i64 %newIndex6
  %vmStubsPH3Z2_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z2_1_index_V, i64 0, i64 %newIndex6
  %call_ret15 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH3Z2_z_V_addr_1421_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret15, 0
  store i4 %vmStubsPH3Z2_z_V_addr_1421_ret, i4* %vmStubsPH3Z2_1_z_V_addr, align 1
  %vmStubsPH3Z2_phi_V_addr_1432_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret15, 1
  store i3 %vmStubsPH3Z2_phi_V_addr_1432_r, i3* %vmStubsPH3Z2_1_phi_V_addr, align 1
  %vmStubsPH3Z2_r_V_addr_1443_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret15, 2
  store i2 %vmStubsPH3Z2_r_V_addr_1443_ret, i2* %vmStubsPH3Z2_1_r_V_addr, align 1
  %vmStubsPH3Z2_pt_V_addr_1454_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret15, 3
  store i3 %vmStubsPH3Z2_pt_V_addr_1454_re, i3* %vmStubsPH3Z2_1_pt_V_addr, align 1
  %vmStubsPH3Z2_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret15, 4
  store i6 %vmStubsPH3Z2_index_V_addr_s, i6* %vmStubsPH3Z2_1_index_V_addr, align 1
  %tmp_17 = add i6 %nPH3Z2_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z2_1_V, i6 %tmp_17)
  br label %._crit_edge400.i51

branch161415:                                     ; preds = %8
  %nPH4Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z2_1_V)
  %newIndex7 = zext i6 %nPH4Z2_1_V_read to i64
  %vmStubsPH4Z2_1_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z2_1_z_V, i64 0, i64 %newIndex7
  %vmStubsPH4Z2_1_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_1_phi_V, i64 0, i64 %newIndex7
  %vmStubsPH4Z2_1_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z2_1_r_V, i64 0, i64 %newIndex7
  %vmStubsPH4Z2_1_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_1_pt_V, i64 0, i64 %newIndex7
  %vmStubsPH4Z2_1_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z2_1_index_V, i64 0, i64 %newIndex7
  %call_ret16 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_1, i3 %redPhi_V_1, i2 %redR_V_1, i3 %redPt_V_1, i6 %p_0)
  %vmStubsPH4Z2_z_V_addr_1476_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret16, 0
  store i4 %vmStubsPH4Z2_z_V_addr_1476_ret, i4* %vmStubsPH4Z2_1_z_V_addr, align 1
  %vmStubsPH4Z2_phi_V_addr_1487_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret16, 1
  store i3 %vmStubsPH4Z2_phi_V_addr_1487_r, i3* %vmStubsPH4Z2_1_phi_V_addr, align 1
  %vmStubsPH4Z2_r_V_addr_1498_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret16, 2
  store i2 %vmStubsPH4Z2_r_V_addr_1498_ret, i2* %vmStubsPH4Z2_1_r_V_addr, align 1
  %vmStubsPH4Z2_pt_V_addr_1509_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret16, 3
  store i3 %vmStubsPH4Z2_pt_V_addr_1509_re, i3* %vmStubsPH4Z2_1_pt_V_addr, align 1
  %vmStubsPH4Z2_index_V_addr_s = extractvalue { i4, i3, i2, i3, i6 } %call_ret16, 4
  store i6 %vmStubsPH4Z2_index_V_addr_s, i6* %vmStubsPH4Z2_1_index_V_addr, align 1
  %tmp_18 = add i6 %nPH4Z2_1_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z2_1_V, i6 %tmp_18)
  br label %._crit_edge400.i51

._crit_edge400.i51:                               ; preds = %branch161415, %branch61261, %branch161171, %branch61011, %8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i53: ; preds = %._crit_edge400.i51, %._crit_edge.i50
  %empty_20 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str14, i32 %tmp_8)
  %i_1 = add i7 %i_0_i2, 1
  br label %5

VMRouter.exit54:                                  ; preds = %5, %6
  %nStubs_2_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %nStubs_2)
  br label %9

; <label>:9                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35, %VMRouter.exit54
  %p_2 = phi i6 [ 0, %VMRouter.exit54 ], [ %index_V_2, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35 ]
  %i_0_i3 = phi i7 [ 0, %VMRouter.exit54 ], [ %i_2, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35 ]
  %tmp_35 = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i_0_i3, i32 6)
  %index_V_2 = add i6 %p_2, 1
  br i1 %tmp_35, label %VMRouter.exit36, label %10

; <label>:10                                      ; preds = %9
  %i_0_i3_cast6 = zext i7 %i_0_i3 to i32
  %empty_21 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str14) nounwind
  %tmp_14 = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str14)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str3) nounwind
  %tmp_15 = icmp slt i32 %i_0_i3_cast6, %nStubs_2_read
  br i1 %tmp_15, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i31, label %VMRouter.exit36

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i31: ; preds = %10
  %p_3 = zext i6 %p_2 to i64
  %stubsInLayer_2_z_V_addr = getelementptr [64 x i12]* %stubsInLayer_2_z_V, i64 0, i64 %p_3
  %stubsInLayer_2_phi_V_addr = getelementptr [64 x i14]* %stubsInLayer_2_phi_V, i64 0, i64 %p_3
  %stubsInLayer_2_r_V_addr = getelementptr [64 x i7]* %stubsInLayer_2_r_V, i64 0, i64 %p_3
  %stubsInLayer_2_pt_V_addr = getelementptr [64 x i3]* %stubsInLayer_2_pt_V, i64 0, i64 %p_3
  %curZ_V_2 = load i12* %stubsInLayer_2_z_V_addr, align 2
  %curPhi_V_2 = load i14* %stubsInLayer_2_phi_V_addr, align 2
  %curR_V_2 = load i7* %stubsInLayer_2_r_V_addr, align 1
  %redPt_V_2 = load i3* %stubsInLayer_2_pt_V_addr, align 1
  %allStubs_2_z_V_addr = getelementptr [64 x i12]* %allStubs_2_z_V, i64 0, i64 %p_3
  %allStubs_2_phi_V_addr = getelementptr [64 x i14]* %allStubs_2_phi_V, i64 0, i64 %p_3
  %allStubs_2_r_V_addr = getelementptr [64 x i7]* %allStubs_2_r_V, i64 0, i64 %p_3
  %allStubs_2_pt_V_addr = getelementptr [64 x i3]* %allStubs_2_pt_V, i64 0, i64 %p_3
  store i12 %curZ_V_2, i12* %allStubs_2_z_V_addr, align 2
  store i14 %curPhi_V_2, i14* %allStubs_2_phi_V_addr, align 2
  store i7 %curR_V_2, i7* %allStubs_2_r_V_addr, align 1
  store i3 %redPt_V_2, i3* %allStubs_2_pt_V_addr, align 1
  %redZ_V_2 = call i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12 %curZ_V_2, i32 5, i32 8)
  %redPhi_V_2 = call i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14 %curPhi_V_2, i32 9, i32 11)
  %redR_V_2 = call i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7 %curR_V_2, i32 5, i32 6)
  %routePhi_V_2 = call i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14 %curPhi_V_2, i32 12, i32 13)
  %routeZ_V_2 = call i1 @_ssdm_op_BitSelect.i1.i12.i32(i12 %curZ_V_2, i32 9)
  br i1 %routeZ_V_2, label %12, label %11

; <label>:11                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i31
  switch i2 %routePhi_V_2, label %._crit_edge.i32 [
    i2 0, label %branch12
    i2 1, label %branch12653
    i2 -2, label %branch12780
    i2 -1, label %branch12909
  ]

branch12:                                         ; preds = %11
  %nPH1Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z1_2_V)
  %newIndex8 = zext i6 %nPH1Z1_2_V_read to i64
  %vmStubsPH1Z1_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z1_2_z_V, i64 0, i64 %newIndex8
  %vmStubsPH1Z1_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_2_phi_V, i64 0, i64 %newIndex8
  %vmStubsPH1Z1_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z1_2_r_V, i64 0, i64 %newIndex8
  %vmStubsPH1Z1_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_2_pt_V, i64 0, i64 %newIndex8
  %vmStubsPH1Z1_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z1_2_index_V, i64 0, i64 %newIndex8
  %call_ret17 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH1Z1_z_V_addr_293_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret17, 0
  store i4 %vmStubsPH1Z1_z_V_addr_293_ret, i4* %vmStubsPH1Z1_2_z_V_addr, align 1
  %vmStubsPH1Z1_phi_V_addr_2104_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret17, 1
  store i3 %vmStubsPH1Z1_phi_V_addr_2104_r, i3* %vmStubsPH1Z1_2_phi_V_addr, align 1
  %vmStubsPH1Z1_r_V_addr_2115_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret17, 2
  store i2 %vmStubsPH1Z1_r_V_addr_2115_ret, i2* %vmStubsPH1Z1_2_r_V_addr, align 1
  %vmStubsPH1Z1_pt_V_addr_2126_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret17, 3
  store i3 %vmStubsPH1Z1_pt_V_addr_2126_re, i3* %vmStubsPH1Z1_2_pt_V_addr, align 1
  %vmStubsPH1Z1_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret17, 4
  store i6 %vmStubsPH1Z1_index_V_addr_1, i6* %vmStubsPH1Z1_2_index_V_addr, align 1
  %tmp_29 = add i6 %nPH1Z1_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z1_2_V, i6 %tmp_29)
  br label %._crit_edge.i32

branch12653:                                      ; preds = %11
  %nPH2Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z1_2_V)
  %newIndex9 = zext i6 %nPH2Z1_2_V_read to i64
  %vmStubsPH2Z1_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z1_2_z_V, i64 0, i64 %newIndex9
  %vmStubsPH2Z1_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_2_phi_V, i64 0, i64 %newIndex9
  %vmStubsPH2Z1_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z1_2_r_V, i64 0, i64 %newIndex9
  %vmStubsPH2Z1_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_2_pt_V, i64 0, i64 %newIndex9
  %vmStubsPH2Z1_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z1_2_index_V, i64 0, i64 %newIndex9
  %call_ret18 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH2Z1_z_V_addr_2148_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret18, 0
  store i4 %vmStubsPH2Z1_z_V_addr_2148_ret, i4* %vmStubsPH2Z1_2_z_V_addr, align 1
  %vmStubsPH2Z1_phi_V_addr_2159_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret18, 1
  store i3 %vmStubsPH2Z1_phi_V_addr_2159_r, i3* %vmStubsPH2Z1_2_phi_V_addr, align 1
  %vmStubsPH2Z1_r_V_addr_2170_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret18, 2
  store i2 %vmStubsPH2Z1_r_V_addr_2170_ret, i2* %vmStubsPH2Z1_2_r_V_addr, align 1
  %vmStubsPH2Z1_pt_V_addr_2181_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret18, 3
  store i3 %vmStubsPH2Z1_pt_V_addr_2181_re, i3* %vmStubsPH2Z1_2_pt_V_addr, align 1
  %vmStubsPH2Z1_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret18, 4
  store i6 %vmStubsPH2Z1_index_V_addr_1, i6* %vmStubsPH2Z1_2_index_V_addr, align 1
  %tmp_30 = add i6 %nPH2Z1_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z1_2_V, i6 %tmp_30)
  br label %._crit_edge.i32

branch12780:                                      ; preds = %11
  %nPH3Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z1_2_V)
  %newIndex10 = zext i6 %nPH3Z1_2_V_read to i64
  %vmStubsPH3Z1_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z1_2_z_V, i64 0, i64 %newIndex10
  %vmStubsPH3Z1_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_2_phi_V, i64 0, i64 %newIndex10
  %vmStubsPH3Z1_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z1_2_r_V, i64 0, i64 %newIndex10
  %vmStubsPH3Z1_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_2_pt_V, i64 0, i64 %newIndex10
  %vmStubsPH3Z1_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z1_2_index_V, i64 0, i64 %newIndex10
  %call_ret19 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH3Z1_z_V_addr_2203_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret19, 0
  store i4 %vmStubsPH3Z1_z_V_addr_2203_ret, i4* %vmStubsPH3Z1_2_z_V_addr, align 1
  %vmStubsPH3Z1_phi_V_addr_2214_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret19, 1
  store i3 %vmStubsPH3Z1_phi_V_addr_2214_r, i3* %vmStubsPH3Z1_2_phi_V_addr, align 1
  %vmStubsPH3Z1_r_V_addr_2225_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret19, 2
  store i2 %vmStubsPH3Z1_r_V_addr_2225_ret, i2* %vmStubsPH3Z1_2_r_V_addr, align 1
  %vmStubsPH3Z1_pt_V_addr_2236_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret19, 3
  store i3 %vmStubsPH3Z1_pt_V_addr_2236_re, i3* %vmStubsPH3Z1_2_pt_V_addr, align 1
  %vmStubsPH3Z1_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret19, 4
  store i6 %vmStubsPH3Z1_index_V_addr_1, i6* %vmStubsPH3Z1_2_index_V_addr, align 1
  %tmp_31 = add i6 %nPH3Z1_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z1_2_V, i6 %tmp_31)
  br label %._crit_edge.i32

branch12909:                                      ; preds = %11
  %nPH4Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z1_2_V)
  %newIndex11 = zext i6 %nPH4Z1_2_V_read to i64
  %vmStubsPH4Z1_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z1_2_z_V, i64 0, i64 %newIndex11
  %vmStubsPH4Z1_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_2_phi_V, i64 0, i64 %newIndex11
  %vmStubsPH4Z1_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z1_2_r_V, i64 0, i64 %newIndex11
  %vmStubsPH4Z1_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_2_pt_V, i64 0, i64 %newIndex11
  %vmStubsPH4Z1_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z1_2_index_V, i64 0, i64 %newIndex11
  %call_ret20 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH4Z1_z_V_addr_2258_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret20, 0
  store i4 %vmStubsPH4Z1_z_V_addr_2258_ret, i4* %vmStubsPH4Z1_2_z_V_addr, align 1
  %vmStubsPH4Z1_phi_V_addr_2269_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret20, 1
  store i3 %vmStubsPH4Z1_phi_V_addr_2269_r, i3* %vmStubsPH4Z1_2_phi_V_addr, align 1
  %vmStubsPH4Z1_r_V_addr_2280_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret20, 2
  store i2 %vmStubsPH4Z1_r_V_addr_2280_ret, i2* %vmStubsPH4Z1_2_r_V_addr, align 1
  %vmStubsPH4Z1_pt_V_addr_2291_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret20, 3
  store i3 %vmStubsPH4Z1_pt_V_addr_2291_re, i3* %vmStubsPH4Z1_2_pt_V_addr, align 1
  %vmStubsPH4Z1_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret20, 4
  store i6 %vmStubsPH4Z1_index_V_addr_1, i6* %vmStubsPH4Z1_2_index_V_addr, align 1
  %tmp_32 = add i6 %nPH4Z1_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z1_2_V, i6 %tmp_32)
  br label %._crit_edge.i32

._crit_edge.i32:                                  ; preds = %branch12909, %branch12780, %branch12653, %branch12, %11
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35

; <label>:12                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i31
  switch i2 %routePhi_V_2, label %._crit_edge400.i33 [
    i2 0, label %branch121026
    i2 1, label %branch121159
    i2 -2, label %branch121275
    i2 -1, label %branch121403
  ]

branch121026:                                     ; preds = %12
  %nPH1Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z2_2_V)
  %newIndex12 = zext i6 %nPH1Z2_2_V_read to i64
  %vmStubsPH1Z2_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z2_2_z_V, i64 0, i64 %newIndex12
  %vmStubsPH1Z2_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_2_phi_V, i64 0, i64 %newIndex12
  %vmStubsPH1Z2_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z2_2_r_V, i64 0, i64 %newIndex12
  %vmStubsPH1Z2_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_2_pt_V, i64 0, i64 %newIndex12
  %vmStubsPH1Z2_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z2_2_index_V, i64 0, i64 %newIndex12
  %call_ret21 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH1Z2_z_V_addr_2313_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret21, 0
  store i4 %vmStubsPH1Z2_z_V_addr_2313_ret, i4* %vmStubsPH1Z2_2_z_V_addr, align 1
  %vmStubsPH1Z2_phi_V_addr_2324_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret21, 1
  store i3 %vmStubsPH1Z2_phi_V_addr_2324_r, i3* %vmStubsPH1Z2_2_phi_V_addr, align 1
  %vmStubsPH1Z2_r_V_addr_2335_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret21, 2
  store i2 %vmStubsPH1Z2_r_V_addr_2335_ret, i2* %vmStubsPH1Z2_2_r_V_addr, align 1
  %vmStubsPH1Z2_pt_V_addr_2346_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret21, 3
  store i3 %vmStubsPH1Z2_pt_V_addr_2346_re, i3* %vmStubsPH1Z2_2_pt_V_addr, align 1
  %vmStubsPH1Z2_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret21, 4
  store i6 %vmStubsPH1Z2_index_V_addr_1, i6* %vmStubsPH1Z2_2_index_V_addr, align 1
  %tmp_23 = add i6 %nPH1Z2_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z2_2_V, i6 %tmp_23)
  br label %._crit_edge400.i33

branch121159:                                     ; preds = %12
  %nPH2Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z2_2_V)
  %newIndex13 = zext i6 %nPH2Z2_2_V_read to i64
  %vmStubsPH2Z2_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z2_2_z_V, i64 0, i64 %newIndex13
  %vmStubsPH2Z2_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_2_phi_V, i64 0, i64 %newIndex13
  %vmStubsPH2Z2_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z2_2_r_V, i64 0, i64 %newIndex13
  %vmStubsPH2Z2_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_2_pt_V, i64 0, i64 %newIndex13
  %vmStubsPH2Z2_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z2_2_index_V, i64 0, i64 %newIndex13
  %call_ret22 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH2Z2_z_V_addr_2368_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret22, 0
  store i4 %vmStubsPH2Z2_z_V_addr_2368_ret, i4* %vmStubsPH2Z2_2_z_V_addr, align 1
  %vmStubsPH2Z2_phi_V_addr_2379_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret22, 1
  store i3 %vmStubsPH2Z2_phi_V_addr_2379_r, i3* %vmStubsPH2Z2_2_phi_V_addr, align 1
  %vmStubsPH2Z2_r_V_addr_2390_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret22, 2
  store i2 %vmStubsPH2Z2_r_V_addr_2390_ret, i2* %vmStubsPH2Z2_2_r_V_addr, align 1
  %vmStubsPH2Z2_pt_V_addr_2401_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret22, 3
  store i3 %vmStubsPH2Z2_pt_V_addr_2401_re, i3* %vmStubsPH2Z2_2_pt_V_addr, align 1
  %vmStubsPH2Z2_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret22, 4
  store i6 %vmStubsPH2Z2_index_V_addr_1, i6* %vmStubsPH2Z2_2_index_V_addr, align 1
  %tmp_24 = add i6 %nPH2Z2_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z2_2_V, i6 %tmp_24)
  br label %._crit_edge400.i33

branch121275:                                     ; preds = %12
  %nPH3Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z2_2_V)
  %newIndex14 = zext i6 %nPH3Z2_2_V_read to i64
  %vmStubsPH3Z2_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z2_2_z_V, i64 0, i64 %newIndex14
  %vmStubsPH3Z2_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_2_phi_V, i64 0, i64 %newIndex14
  %vmStubsPH3Z2_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z2_2_r_V, i64 0, i64 %newIndex14
  %vmStubsPH3Z2_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_2_pt_V, i64 0, i64 %newIndex14
  %vmStubsPH3Z2_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z2_2_index_V, i64 0, i64 %newIndex14
  %call_ret23 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH3Z2_z_V_addr_2423_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret23, 0
  store i4 %vmStubsPH3Z2_z_V_addr_2423_ret, i4* %vmStubsPH3Z2_2_z_V_addr, align 1
  %vmStubsPH3Z2_phi_V_addr_2434_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret23, 1
  store i3 %vmStubsPH3Z2_phi_V_addr_2434_r, i3* %vmStubsPH3Z2_2_phi_V_addr, align 1
  %vmStubsPH3Z2_r_V_addr_2445_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret23, 2
  store i2 %vmStubsPH3Z2_r_V_addr_2445_ret, i2* %vmStubsPH3Z2_2_r_V_addr, align 1
  %vmStubsPH3Z2_pt_V_addr_2456_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret23, 3
  store i3 %vmStubsPH3Z2_pt_V_addr_2456_re, i3* %vmStubsPH3Z2_2_pt_V_addr, align 1
  %vmStubsPH3Z2_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret23, 4
  store i6 %vmStubsPH3Z2_index_V_addr_1, i6* %vmStubsPH3Z2_2_index_V_addr, align 1
  %tmp_27 = add i6 %nPH3Z2_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z2_2_V, i6 %tmp_27)
  br label %._crit_edge400.i33

branch121403:                                     ; preds = %12
  %nPH4Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z2_2_V)
  %newIndex15 = zext i6 %nPH4Z2_2_V_read to i64
  %vmStubsPH4Z2_2_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z2_2_z_V, i64 0, i64 %newIndex15
  %vmStubsPH4Z2_2_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_2_phi_V, i64 0, i64 %newIndex15
  %vmStubsPH4Z2_2_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z2_2_r_V, i64 0, i64 %newIndex15
  %vmStubsPH4Z2_2_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_2_pt_V, i64 0, i64 %newIndex15
  %vmStubsPH4Z2_2_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z2_2_index_V, i64 0, i64 %newIndex15
  %call_ret24 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_2, i3 %redPhi_V_2, i2 %redR_V_2, i3 %redPt_V_2, i6 %p_2)
  %vmStubsPH4Z2_z_V_addr_2478_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret24, 0
  store i4 %vmStubsPH4Z2_z_V_addr_2478_ret, i4* %vmStubsPH4Z2_2_z_V_addr, align 1
  %vmStubsPH4Z2_phi_V_addr_2489_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret24, 1
  store i3 %vmStubsPH4Z2_phi_V_addr_2489_r, i3* %vmStubsPH4Z2_2_phi_V_addr, align 1
  %vmStubsPH4Z2_r_V_addr_2500_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret24, 2
  store i2 %vmStubsPH4Z2_r_V_addr_2500_ret, i2* %vmStubsPH4Z2_2_r_V_addr, align 1
  %vmStubsPH4Z2_pt_V_addr_2511_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret24, 3
  store i3 %vmStubsPH4Z2_pt_V_addr_2511_re, i3* %vmStubsPH4Z2_2_pt_V_addr, align 1
  %vmStubsPH4Z2_index_V_addr_1 = extractvalue { i4, i3, i2, i3, i6 } %call_ret24, 4
  store i6 %vmStubsPH4Z2_index_V_addr_1, i6* %vmStubsPH4Z2_2_index_V_addr, align 1
  %tmp_28 = add i6 %nPH4Z2_2_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z2_2_V, i6 %tmp_28)
  br label %._crit_edge400.i33

._crit_edge400.i33:                               ; preds = %branch121403, %branch121275, %branch121159, %branch121026, %12
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i35: ; preds = %._crit_edge400.i33, %._crit_edge.i32
  %empty_22 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str14, i32 %tmp_14)
  %i_2 = add i7 %i_0_i3, 1
  br label %9

VMRouter.exit36:                                  ; preds = %9, %10
  %nStubs_3_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %nStubs_3)
  br label %13

; <label>:13                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17, %VMRouter.exit36
  %p_4 = phi i6 [ 0, %VMRouter.exit36 ], [ %index_V_3, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17 ]
  %i_0_i6 = phi i7 [ 0, %VMRouter.exit36 ], [ %i_3, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17 ]
  %tmp_55 = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i_0_i6, i32 6)
  %index_V_3 = add i6 %p_4, 1
  br i1 %tmp_55, label %VMRouter.exit18, label %14

; <label>:14                                      ; preds = %13
  %i_0_i6_cast4 = zext i7 %i_0_i6 to i32
  %empty_23 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str14) nounwind
  %tmp_25 = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str14)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str3) nounwind
  %tmp_26 = icmp slt i32 %i_0_i6_cast4, %nStubs_3_read
  br i1 %tmp_26, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i13, label %VMRouter.exit18

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i13: ; preds = %14
  %p_5 = zext i6 %p_4 to i64
  %stubsInLayer_3_z_V_addr = getelementptr [64 x i12]* %stubsInLayer_3_z_V, i64 0, i64 %p_5
  %stubsInLayer_3_phi_V_addr = getelementptr [64 x i14]* %stubsInLayer_3_phi_V, i64 0, i64 %p_5
  %stubsInLayer_3_r_V_addr = getelementptr [64 x i7]* %stubsInLayer_3_r_V, i64 0, i64 %p_5
  %stubsInLayer_3_pt_V_addr = getelementptr [64 x i3]* %stubsInLayer_3_pt_V, i64 0, i64 %p_5
  %curZ_V_3 = load i12* %stubsInLayer_3_z_V_addr, align 2
  %curPhi_V_3 = load i14* %stubsInLayer_3_phi_V_addr, align 2
  %curR_V_3 = load i7* %stubsInLayer_3_r_V_addr, align 1
  %redPt_V_3 = load i3* %stubsInLayer_3_pt_V_addr, align 1
  %allStubs_3_z_V_addr = getelementptr [64 x i12]* %allStubs_3_z_V, i64 0, i64 %p_5
  %allStubs_3_phi_V_addr = getelementptr [64 x i14]* %allStubs_3_phi_V, i64 0, i64 %p_5
  %allStubs_3_r_V_addr = getelementptr [64 x i7]* %allStubs_3_r_V, i64 0, i64 %p_5
  %allStubs_3_pt_V_addr = getelementptr [64 x i3]* %allStubs_3_pt_V, i64 0, i64 %p_5
  store i12 %curZ_V_3, i12* %allStubs_3_z_V_addr, align 2
  store i14 %curPhi_V_3, i14* %allStubs_3_phi_V_addr, align 2
  store i7 %curR_V_3, i7* %allStubs_3_r_V_addr, align 1
  store i3 %redPt_V_3, i3* %allStubs_3_pt_V_addr, align 1
  %redZ_V_3 = call i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12 %curZ_V_3, i32 5, i32 8)
  %redPhi_V_3 = call i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14 %curPhi_V_3, i32 9, i32 11)
  %redR_V_3 = call i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7 %curR_V_3, i32 5, i32 6)
  %routePhi_V_3 = call i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14 %curPhi_V_3, i32 12, i32 13)
  %routeZ_V_3 = call i1 @_ssdm_op_BitSelect.i1.i12.i32(i12 %curZ_V_3, i32 9)
  br i1 %routeZ_V_3, label %16, label %15

; <label>:15                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i13
  switch i2 %routePhi_V_3, label %._crit_edge.i14 [
    i2 0, label %branch18
    i2 1, label %branch8641
    i2 -2, label %branch18794
    i2 -1, label %branch8894
  ]

branch18:                                         ; preds = %15
  %nPH1Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z1_3_V)
  %newIndex16 = zext i6 %nPH1Z1_3_V_read to i64
  %vmStubsPH1Z1_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z1_3_z_V, i64 0, i64 %newIndex16
  %vmStubsPH1Z1_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_3_phi_V, i64 0, i64 %newIndex16
  %vmStubsPH1Z1_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z1_3_r_V, i64 0, i64 %newIndex16
  %vmStubsPH1Z1_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_3_pt_V, i64 0, i64 %newIndex16
  %vmStubsPH1Z1_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z1_3_index_V, i64 0, i64 %newIndex16
  %call_ret25 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH1Z1_z_V_addr_395_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret25, 0
  store i4 %vmStubsPH1Z1_z_V_addr_395_ret, i4* %vmStubsPH1Z1_3_z_V_addr, align 1
  %vmStubsPH1Z1_phi_V_addr_3106_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret25, 1
  store i3 %vmStubsPH1Z1_phi_V_addr_3106_r, i3* %vmStubsPH1Z1_3_phi_V_addr, align 1
  %vmStubsPH1Z1_r_V_addr_3117_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret25, 2
  store i2 %vmStubsPH1Z1_r_V_addr_3117_ret, i2* %vmStubsPH1Z1_3_r_V_addr, align 1
  %vmStubsPH1Z1_pt_V_addr_3128_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret25, 3
  store i3 %vmStubsPH1Z1_pt_V_addr_3128_re, i3* %vmStubsPH1Z1_3_pt_V_addr, align 1
  %vmStubsPH1Z1_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret25, 4
  store i6 %vmStubsPH1Z1_index_V_addr_2, i6* %vmStubsPH1Z1_3_index_V_addr, align 1
  %tmp_40 = add i6 %nPH1Z1_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z1_3_V, i6 %tmp_40)
  br label %._crit_edge.i14

branch8641:                                       ; preds = %15
  %nPH2Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z1_3_V)
  %newIndex17 = zext i6 %nPH2Z1_3_V_read to i64
  %vmStubsPH2Z1_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z1_3_z_V, i64 0, i64 %newIndex17
  %vmStubsPH2Z1_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_3_phi_V, i64 0, i64 %newIndex17
  %vmStubsPH2Z1_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z1_3_r_V, i64 0, i64 %newIndex17
  %vmStubsPH2Z1_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_3_pt_V, i64 0, i64 %newIndex17
  %vmStubsPH2Z1_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z1_3_index_V, i64 0, i64 %newIndex17
  %call_ret26 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH2Z1_z_V_addr_3150_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret26, 0
  store i4 %vmStubsPH2Z1_z_V_addr_3150_ret, i4* %vmStubsPH2Z1_3_z_V_addr, align 1
  %vmStubsPH2Z1_phi_V_addr_3161_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret26, 1
  store i3 %vmStubsPH2Z1_phi_V_addr_3161_r, i3* %vmStubsPH2Z1_3_phi_V_addr, align 1
  %vmStubsPH2Z1_r_V_addr_3172_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret26, 2
  store i2 %vmStubsPH2Z1_r_V_addr_3172_ret, i2* %vmStubsPH2Z1_3_r_V_addr, align 1
  %vmStubsPH2Z1_pt_V_addr_3183_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret26, 3
  store i3 %vmStubsPH2Z1_pt_V_addr_3183_re, i3* %vmStubsPH2Z1_3_pt_V_addr, align 1
  %vmStubsPH2Z1_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret26, 4
  store i6 %vmStubsPH2Z1_index_V_addr_2, i6* %vmStubsPH2Z1_3_index_V_addr, align 1
  %tmp_41 = add i6 %nPH2Z1_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z1_3_V, i6 %tmp_41)
  br label %._crit_edge.i14

branch18794:                                      ; preds = %15
  %nPH3Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z1_3_V)
  %newIndex18 = zext i6 %nPH3Z1_3_V_read to i64
  %vmStubsPH3Z1_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z1_3_z_V, i64 0, i64 %newIndex18
  %vmStubsPH3Z1_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_3_phi_V, i64 0, i64 %newIndex18
  %vmStubsPH3Z1_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z1_3_r_V, i64 0, i64 %newIndex18
  %vmStubsPH3Z1_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_3_pt_V, i64 0, i64 %newIndex18
  %vmStubsPH3Z1_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z1_3_index_V, i64 0, i64 %newIndex18
  %call_ret27 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH3Z1_z_V_addr_3205_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret27, 0
  store i4 %vmStubsPH3Z1_z_V_addr_3205_ret, i4* %vmStubsPH3Z1_3_z_V_addr, align 1
  %vmStubsPH3Z1_phi_V_addr_3216_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret27, 1
  store i3 %vmStubsPH3Z1_phi_V_addr_3216_r, i3* %vmStubsPH3Z1_3_phi_V_addr, align 1
  %vmStubsPH3Z1_r_V_addr_3227_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret27, 2
  store i2 %vmStubsPH3Z1_r_V_addr_3227_ret, i2* %vmStubsPH3Z1_3_r_V_addr, align 1
  %vmStubsPH3Z1_pt_V_addr_3238_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret27, 3
  store i3 %vmStubsPH3Z1_pt_V_addr_3238_re, i3* %vmStubsPH3Z1_3_pt_V_addr, align 1
  %vmStubsPH3Z1_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret27, 4
  store i6 %vmStubsPH3Z1_index_V_addr_2, i6* %vmStubsPH3Z1_3_index_V_addr, align 1
  %tmp_42 = add i6 %nPH3Z1_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z1_3_V, i6 %tmp_42)
  br label %._crit_edge.i14

branch8894:                                       ; preds = %15
  %nPH4Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z1_3_V)
  %newIndex19 = zext i6 %nPH4Z1_3_V_read to i64
  %vmStubsPH4Z1_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z1_3_z_V, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_3_phi_V, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z1_3_r_V, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_3_pt_V, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z1_3_index_V, i64 0, i64 %newIndex19
  %call_ret28 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH4Z1_z_V_addr_3260_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret28, 0
  store i4 %vmStubsPH4Z1_z_V_addr_3260_ret, i4* %vmStubsPH4Z1_3_z_V_addr, align 1
  %vmStubsPH4Z1_phi_V_addr_3271_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret28, 1
  store i3 %vmStubsPH4Z1_phi_V_addr_3271_r, i3* %vmStubsPH4Z1_3_phi_V_addr, align 1
  %vmStubsPH4Z1_r_V_addr_3282_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret28, 2
  store i2 %vmStubsPH4Z1_r_V_addr_3282_ret, i2* %vmStubsPH4Z1_3_r_V_addr, align 1
  %vmStubsPH4Z1_pt_V_addr_3293_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret28, 3
  store i3 %vmStubsPH4Z1_pt_V_addr_3293_re, i3* %vmStubsPH4Z1_3_pt_V_addr, align 1
  %vmStubsPH4Z1_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret28, 4
  store i6 %vmStubsPH4Z1_index_V_addr_2, i6* %vmStubsPH4Z1_3_index_V_addr, align 1
  %tmp_43 = add i6 %nPH4Z1_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z1_3_V, i6 %tmp_43)
  br label %._crit_edge.i14

._crit_edge.i14:                                  ; preds = %branch8894, %branch18794, %branch8641, %branch18, %15
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17

; <label>:16                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i13
  switch i2 %routePhi_V_3, label %._crit_edge400.i15 [
    i2 0, label %branch181040
    i2 1, label %branch81144
    i2 -2, label %branch181289
    i2 -1, label %branch81391
  ]

branch181040:                                     ; preds = %16
  %nPH1Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z2_3_V)
  %newIndex20 = zext i6 %nPH1Z2_3_V_read to i64
  %vmStubsPH1Z2_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z2_3_z_V, i64 0, i64 %newIndex20
  %vmStubsPH1Z2_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_3_phi_V, i64 0, i64 %newIndex20
  %vmStubsPH1Z2_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z2_3_r_V, i64 0, i64 %newIndex20
  %vmStubsPH1Z2_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_3_pt_V, i64 0, i64 %newIndex20
  %vmStubsPH1Z2_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z2_3_index_V, i64 0, i64 %newIndex20
  %call_ret29 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH1Z2_z_V_addr_3315_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret29, 0
  store i4 %vmStubsPH1Z2_z_V_addr_3315_ret, i4* %vmStubsPH1Z2_3_z_V_addr, align 1
  %vmStubsPH1Z2_phi_V_addr_3326_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret29, 1
  store i3 %vmStubsPH1Z2_phi_V_addr_3326_r, i3* %vmStubsPH1Z2_3_phi_V_addr, align 1
  %vmStubsPH1Z2_r_V_addr_3337_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret29, 2
  store i2 %vmStubsPH1Z2_r_V_addr_3337_ret, i2* %vmStubsPH1Z2_3_r_V_addr, align 1
  %vmStubsPH1Z2_pt_V_addr_3348_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret29, 3
  store i3 %vmStubsPH1Z2_pt_V_addr_3348_re, i3* %vmStubsPH1Z2_3_pt_V_addr, align 1
  %vmStubsPH1Z2_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret29, 4
  store i6 %vmStubsPH1Z2_index_V_addr_2, i6* %vmStubsPH1Z2_3_index_V_addr, align 1
  %tmp_33 = add i6 %nPH1Z2_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z2_3_V, i6 %tmp_33)
  br label %._crit_edge400.i15

branch81144:                                      ; preds = %16
  %nPH2Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z2_3_V)
  %newIndex21 = zext i6 %nPH2Z2_3_V_read to i64
  %vmStubsPH2Z2_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z2_3_z_V, i64 0, i64 %newIndex21
  %vmStubsPH2Z2_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_3_phi_V, i64 0, i64 %newIndex21
  %vmStubsPH2Z2_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z2_3_r_V, i64 0, i64 %newIndex21
  %vmStubsPH2Z2_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_3_pt_V, i64 0, i64 %newIndex21
  %vmStubsPH2Z2_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z2_3_index_V, i64 0, i64 %newIndex21
  %call_ret30 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH2Z2_z_V_addr_3370_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret30, 0
  store i4 %vmStubsPH2Z2_z_V_addr_3370_ret, i4* %vmStubsPH2Z2_3_z_V_addr, align 1
  %vmStubsPH2Z2_phi_V_addr_3381_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret30, 1
  store i3 %vmStubsPH2Z2_phi_V_addr_3381_r, i3* %vmStubsPH2Z2_3_phi_V_addr, align 1
  %vmStubsPH2Z2_r_V_addr_3392_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret30, 2
  store i2 %vmStubsPH2Z2_r_V_addr_3392_ret, i2* %vmStubsPH2Z2_3_r_V_addr, align 1
  %vmStubsPH2Z2_pt_V_addr_3403_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret30, 3
  store i3 %vmStubsPH2Z2_pt_V_addr_3403_re, i3* %vmStubsPH2Z2_3_pt_V_addr, align 1
  %vmStubsPH2Z2_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret30, 4
  store i6 %vmStubsPH2Z2_index_V_addr_2, i6* %vmStubsPH2Z2_3_index_V_addr, align 1
  %tmp_34 = add i6 %nPH2Z2_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z2_3_V, i6 %tmp_34)
  br label %._crit_edge400.i15

branch181289:                                     ; preds = %16
  %nPH3Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z2_3_V)
  %newIndex22 = zext i6 %nPH3Z2_3_V_read to i64
  %vmStubsPH3Z2_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z2_3_z_V, i64 0, i64 %newIndex22
  %vmStubsPH3Z2_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_3_phi_V, i64 0, i64 %newIndex22
  %vmStubsPH3Z2_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z2_3_r_V, i64 0, i64 %newIndex22
  %vmStubsPH3Z2_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_3_pt_V, i64 0, i64 %newIndex22
  %vmStubsPH3Z2_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z2_3_index_V, i64 0, i64 %newIndex22
  %call_ret31 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH3Z2_z_V_addr_3425_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret31, 0
  store i4 %vmStubsPH3Z2_z_V_addr_3425_ret, i4* %vmStubsPH3Z2_3_z_V_addr, align 1
  %vmStubsPH3Z2_phi_V_addr_3436_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret31, 1
  store i3 %vmStubsPH3Z2_phi_V_addr_3436_r, i3* %vmStubsPH3Z2_3_phi_V_addr, align 1
  %vmStubsPH3Z2_r_V_addr_3447_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret31, 2
  store i2 %vmStubsPH3Z2_r_V_addr_3447_ret, i2* %vmStubsPH3Z2_3_r_V_addr, align 1
  %vmStubsPH3Z2_pt_V_addr_3458_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret31, 3
  store i3 %vmStubsPH3Z2_pt_V_addr_3458_re, i3* %vmStubsPH3Z2_3_pt_V_addr, align 1
  %vmStubsPH3Z2_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret31, 4
  store i6 %vmStubsPH3Z2_index_V_addr_2, i6* %vmStubsPH3Z2_3_index_V_addr, align 1
  %tmp_38 = add i6 %nPH3Z2_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z2_3_V, i6 %tmp_38)
  br label %._crit_edge400.i15

branch81391:                                      ; preds = %16
  %nPH4Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z2_3_V)
  %newIndex23 = zext i6 %nPH4Z2_3_V_read to i64
  %vmStubsPH4Z2_3_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z2_3_z_V, i64 0, i64 %newIndex23
  %vmStubsPH4Z2_3_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_3_phi_V, i64 0, i64 %newIndex23
  %vmStubsPH4Z2_3_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z2_3_r_V, i64 0, i64 %newIndex23
  %vmStubsPH4Z2_3_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_3_pt_V, i64 0, i64 %newIndex23
  %vmStubsPH4Z2_3_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z2_3_index_V, i64 0, i64 %newIndex23
  %call_ret32 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_3, i3 %redPhi_V_3, i2 %redR_V_3, i3 %redPt_V_3, i6 %p_4)
  %vmStubsPH4Z2_z_V_addr_3480_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret32, 0
  store i4 %vmStubsPH4Z2_z_V_addr_3480_ret, i4* %vmStubsPH4Z2_3_z_V_addr, align 1
  %vmStubsPH4Z2_phi_V_addr_3491_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret32, 1
  store i3 %vmStubsPH4Z2_phi_V_addr_3491_r, i3* %vmStubsPH4Z2_3_phi_V_addr, align 1
  %vmStubsPH4Z2_r_V_addr_3502_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret32, 2
  store i2 %vmStubsPH4Z2_r_V_addr_3502_ret, i2* %vmStubsPH4Z2_3_r_V_addr, align 1
  %vmStubsPH4Z2_pt_V_addr_3513_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret32, 3
  store i3 %vmStubsPH4Z2_pt_V_addr_3513_re, i3* %vmStubsPH4Z2_3_pt_V_addr, align 1
  %vmStubsPH4Z2_index_V_addr_2 = extractvalue { i4, i3, i2, i3, i6 } %call_ret32, 4
  store i6 %vmStubsPH4Z2_index_V_addr_2, i6* %vmStubsPH4Z2_3_index_V_addr, align 1
  %tmp_39 = add i6 %nPH4Z2_3_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z2_3_V, i6 %tmp_39)
  br label %._crit_edge400.i15

._crit_edge400.i15:                               ; preds = %branch81391, %branch181289, %branch81144, %branch181040, %16
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i17: ; preds = %._crit_edge400.i15, %._crit_edge.i14
  %empty_24 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str14, i32 %tmp_25)
  %i_3 = add i7 %i_0_i6, 1
  br label %13

VMRouter.exit18:                                  ; preds = %13, %14
  %nStubs_4_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %nStubs_4)
  br label %17

; <label>:17                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i, %VMRouter.exit18
  %p_7 = phi i6 [ 0, %VMRouter.exit18 ], [ %index_V_4, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i ]
  %i_0_i = phi i7 [ 0, %VMRouter.exit18 ], [ %i_4, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i ]
  %tmp_57 = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i_0_i, i32 6)
  %index_V_4 = add i6 %p_7, 1
  br i1 %tmp_57, label %VMRouter.exit, label %18

; <label>:18                                      ; preds = %17
  %i_0_i_cast2 = zext i7 %i_0_i to i32
  %empty_25 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str14) nounwind
  %tmp_36 = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str14)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str3) nounwind
  %tmp_37 = icmp slt i32 %i_0_i_cast2, %nStubs_4_read
  br i1 %tmp_37, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i, label %VMRouter.exit

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i: ; preds = %18
  %p_8 = zext i6 %p_7 to i64
  %stubsInLayer_4_z_V_addr = getelementptr [64 x i12]* %stubsInLayer_4_z_V, i64 0, i64 %p_8
  %stubsInLayer_4_phi_V_addr = getelementptr [64 x i14]* %stubsInLayer_4_phi_V, i64 0, i64 %p_8
  %stubsInLayer_4_r_V_addr = getelementptr [64 x i7]* %stubsInLayer_4_r_V, i64 0, i64 %p_8
  %stubsInLayer_4_pt_V_addr = getelementptr [64 x i3]* %stubsInLayer_4_pt_V, i64 0, i64 %p_8
  %curZ_V_4 = load i12* %stubsInLayer_4_z_V_addr, align 2
  %curPhi_V_4 = load i14* %stubsInLayer_4_phi_V_addr, align 2
  %curR_V_4 = load i7* %stubsInLayer_4_r_V_addr, align 1
  %redPt_V_4 = load i3* %stubsInLayer_4_pt_V_addr, align 1
  %allStubs_4_z_V_addr = getelementptr [64 x i12]* %allStubs_4_z_V, i64 0, i64 %p_8
  %allStubs_4_phi_V_addr = getelementptr [64 x i14]* %allStubs_4_phi_V, i64 0, i64 %p_8
  %allStubs_4_r_V_addr = getelementptr [64 x i7]* %allStubs_4_r_V, i64 0, i64 %p_8
  %allStubs_4_pt_V_addr = getelementptr [64 x i3]* %allStubs_4_pt_V, i64 0, i64 %p_8
  store i12 %curZ_V_4, i12* %allStubs_4_z_V_addr, align 2
  store i14 %curPhi_V_4, i14* %allStubs_4_phi_V_addr, align 2
  store i7 %curR_V_4, i7* %allStubs_4_r_V_addr, align 1
  store i3 %redPt_V_4, i3* %allStubs_4_pt_V_addr, align 1
  %redZ_V_4 = call i4 @_ssdm_op_PartSelect.i4.i12.i32.i32(i12 %curZ_V_4, i32 5, i32 8)
  %redPhi_V_4 = call i3 @_ssdm_op_PartSelect.i3.i14.i32.i32(i14 %curPhi_V_4, i32 9, i32 11)
  %redR_V_4 = call i2 @_ssdm_op_PartSelect.i2.i7.i32.i32(i7 %curR_V_4, i32 5, i32 6)
  %routePhi_V_4 = call i2 @_ssdm_op_PartSelect.i2.i14.i32.i32(i14 %curPhi_V_4, i32 12, i32 13)
  %routeZ_V_4 = call i1 @_ssdm_op_BitSelect.i1.i12.i32(i12 %curZ_V_4, i32 9)
  br i1 %routeZ_V_4, label %20, label %19

; <label>:19                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i
  switch i2 %routePhi_V_4, label %._crit_edge.i [
    i2 0, label %branch24
    i2 1, label %branch4629
    i2 -2, label %branch24808
    i2 -1, label %branch4869
  ]

branch24:                                         ; preds = %19
  %nPH1Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z1_4_V)
  %newIndex24 = zext i6 %nPH1Z1_4_V_read to i64
  %vmStubsPH1Z1_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z1_4_z_V, i64 0, i64 %newIndex24
  %vmStubsPH1Z1_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_4_phi_V, i64 0, i64 %newIndex24
  %vmStubsPH1Z1_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z1_4_r_V, i64 0, i64 %newIndex24
  %vmStubsPH1Z1_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z1_4_pt_V, i64 0, i64 %newIndex24
  %vmStubsPH1Z1_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z1_4_index_V, i64 0, i64 %newIndex24
  %call_ret33 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH1Z1_z_V_addr_497_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret33, 0
  store i4 %vmStubsPH1Z1_z_V_addr_497_ret, i4* %vmStubsPH1Z1_4_z_V_addr, align 1
  %vmStubsPH1Z1_phi_V_addr_4108_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret33, 1
  store i3 %vmStubsPH1Z1_phi_V_addr_4108_r, i3* %vmStubsPH1Z1_4_phi_V_addr, align 1
  %vmStubsPH1Z1_r_V_addr_4119_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret33, 2
  store i2 %vmStubsPH1Z1_r_V_addr_4119_ret, i2* %vmStubsPH1Z1_4_r_V_addr, align 1
  %vmStubsPH1Z1_pt_V_addr_4130_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret33, 3
  store i3 %vmStubsPH1Z1_pt_V_addr_4130_re, i3* %vmStubsPH1Z1_4_pt_V_addr, align 1
  %vmStubsPH1Z1_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret33, 4
  store i6 %vmStubsPH1Z1_index_V_addr_3, i6* %vmStubsPH1Z1_4_index_V_addr, align 1
  %tmp_48 = add i6 %nPH1Z1_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z1_4_V, i6 %tmp_48)
  br label %._crit_edge.i

branch4629:                                       ; preds = %19
  %nPH2Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z1_4_V)
  %newIndex25 = zext i6 %nPH2Z1_4_V_read to i64
  %vmStubsPH2Z1_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z1_4_z_V, i64 0, i64 %newIndex25
  %vmStubsPH2Z1_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_4_phi_V, i64 0, i64 %newIndex25
  %vmStubsPH2Z1_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z1_4_r_V, i64 0, i64 %newIndex25
  %vmStubsPH2Z1_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z1_4_pt_V, i64 0, i64 %newIndex25
  %vmStubsPH2Z1_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z1_4_index_V, i64 0, i64 %newIndex25
  %call_ret34 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH2Z1_z_V_addr_4152_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret34, 0
  store i4 %vmStubsPH2Z1_z_V_addr_4152_ret, i4* %vmStubsPH2Z1_4_z_V_addr, align 1
  %vmStubsPH2Z1_phi_V_addr_4163_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret34, 1
  store i3 %vmStubsPH2Z1_phi_V_addr_4163_r, i3* %vmStubsPH2Z1_4_phi_V_addr, align 1
  %vmStubsPH2Z1_r_V_addr_4174_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret34, 2
  store i2 %vmStubsPH2Z1_r_V_addr_4174_ret, i2* %vmStubsPH2Z1_4_r_V_addr, align 1
  %vmStubsPH2Z1_pt_V_addr_4185_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret34, 3
  store i3 %vmStubsPH2Z1_pt_V_addr_4185_re, i3* %vmStubsPH2Z1_4_pt_V_addr, align 1
  %vmStubsPH2Z1_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret34, 4
  store i6 %vmStubsPH2Z1_index_V_addr_3, i6* %vmStubsPH2Z1_4_index_V_addr, align 1
  %tmp_49 = add i6 %nPH2Z1_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z1_4_V, i6 %tmp_49)
  br label %._crit_edge.i

branch24808:                                      ; preds = %19
  %nPH3Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z1_4_V)
  %newIndex26 = zext i6 %nPH3Z1_4_V_read to i64
  %vmStubsPH3Z1_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z1_4_z_V, i64 0, i64 %newIndex26
  %vmStubsPH3Z1_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_4_phi_V, i64 0, i64 %newIndex26
  %vmStubsPH3Z1_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z1_4_r_V, i64 0, i64 %newIndex26
  %vmStubsPH3Z1_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z1_4_pt_V, i64 0, i64 %newIndex26
  %vmStubsPH3Z1_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z1_4_index_V, i64 0, i64 %newIndex26
  %call_ret35 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH3Z1_z_V_addr_4207_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret35, 0
  store i4 %vmStubsPH3Z1_z_V_addr_4207_ret, i4* %vmStubsPH3Z1_4_z_V_addr, align 1
  %vmStubsPH3Z1_phi_V_addr_4218_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret35, 1
  store i3 %vmStubsPH3Z1_phi_V_addr_4218_r, i3* %vmStubsPH3Z1_4_phi_V_addr, align 1
  %vmStubsPH3Z1_r_V_addr_4229_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret35, 2
  store i2 %vmStubsPH3Z1_r_V_addr_4229_ret, i2* %vmStubsPH3Z1_4_r_V_addr, align 1
  %vmStubsPH3Z1_pt_V_addr_4240_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret35, 3
  store i3 %vmStubsPH3Z1_pt_V_addr_4240_re, i3* %vmStubsPH3Z1_4_pt_V_addr, align 1
  %vmStubsPH3Z1_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret35, 4
  store i6 %vmStubsPH3Z1_index_V_addr_3, i6* %vmStubsPH3Z1_4_index_V_addr, align 1
  %tmp_50 = add i6 %nPH3Z1_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z1_4_V, i6 %tmp_50)
  br label %._crit_edge.i

branch4869:                                       ; preds = %19
  %nPH4Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z1_4_V)
  %newIndex27 = zext i6 %nPH4Z1_4_V_read to i64
  %vmStubsPH4Z1_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z1_4_z_V, i64 0, i64 %newIndex27
  %vmStubsPH4Z1_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_4_phi_V, i64 0, i64 %newIndex27
  %vmStubsPH4Z1_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z1_4_r_V, i64 0, i64 %newIndex27
  %vmStubsPH4Z1_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z1_4_pt_V, i64 0, i64 %newIndex27
  %vmStubsPH4Z1_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z1_4_index_V, i64 0, i64 %newIndex27
  %call_ret36 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH4Z1_z_V_addr_4262_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret36, 0
  store i4 %vmStubsPH4Z1_z_V_addr_4262_ret, i4* %vmStubsPH4Z1_4_z_V_addr, align 1
  %vmStubsPH4Z1_phi_V_addr_4273_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret36, 1
  store i3 %vmStubsPH4Z1_phi_V_addr_4273_r, i3* %vmStubsPH4Z1_4_phi_V_addr, align 1
  %vmStubsPH4Z1_r_V_addr_4284_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret36, 2
  store i2 %vmStubsPH4Z1_r_V_addr_4284_ret, i2* %vmStubsPH4Z1_4_r_V_addr, align 1
  %vmStubsPH4Z1_pt_V_addr_4295_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret36, 3
  store i3 %vmStubsPH4Z1_pt_V_addr_4295_re, i3* %vmStubsPH4Z1_4_pt_V_addr, align 1
  %vmStubsPH4Z1_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret36, 4
  store i6 %vmStubsPH4Z1_index_V_addr_3, i6* %vmStubsPH4Z1_4_index_V_addr, align 1
  %tmp_51 = add i6 %nPH4Z1_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z1_4_V, i6 %tmp_51)
  br label %._crit_edge.i

._crit_edge.i:                                    ; preds = %branch4869, %branch24808, %branch4629, %branch24, %19
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i

; <label>:20                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit.i
  switch i2 %routePhi_V_4, label %._crit_edge400.i [
    i2 0, label %branch241054
    i2 1, label %branch41119
    i2 -2, label %branch241303
    i2 -1, label %branch41379
  ]

branch241054:                                     ; preds = %20
  %nPH1Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH1Z2_4_V)
  %newIndex28 = zext i6 %nPH1Z2_4_V_read to i64
  %vmStubsPH1Z2_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH1Z2_4_z_V, i64 0, i64 %newIndex28
  %vmStubsPH1Z2_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_4_phi_V, i64 0, i64 %newIndex28
  %vmStubsPH1Z2_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH1Z2_4_r_V, i64 0, i64 %newIndex28
  %vmStubsPH1Z2_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH1Z2_4_pt_V, i64 0, i64 %newIndex28
  %vmStubsPH1Z2_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH1Z2_4_index_V, i64 0, i64 %newIndex28
  %call_ret37 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH1Z2_z_V_addr_4317_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret37, 0
  store i4 %vmStubsPH1Z2_z_V_addr_4317_ret, i4* %vmStubsPH1Z2_4_z_V_addr, align 1
  %vmStubsPH1Z2_phi_V_addr_4328_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret37, 1
  store i3 %vmStubsPH1Z2_phi_V_addr_4328_r, i3* %vmStubsPH1Z2_4_phi_V_addr, align 1
  %vmStubsPH1Z2_r_V_addr_4339_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret37, 2
  store i2 %vmStubsPH1Z2_r_V_addr_4339_ret, i2* %vmStubsPH1Z2_4_r_V_addr, align 1
  %vmStubsPH1Z2_pt_V_addr_4350_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret37, 3
  store i3 %vmStubsPH1Z2_pt_V_addr_4350_re, i3* %vmStubsPH1Z2_4_pt_V_addr, align 1
  %vmStubsPH1Z2_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret37, 4
  store i6 %vmStubsPH1Z2_index_V_addr_3, i6* %vmStubsPH1Z2_4_index_V_addr, align 1
  %tmp_44 = add i6 %nPH1Z2_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH1Z2_4_V, i6 %tmp_44)
  br label %._crit_edge400.i

branch41119:                                      ; preds = %20
  %nPH2Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH2Z2_4_V)
  %newIndex29 = zext i6 %nPH2Z2_4_V_read to i64
  %vmStubsPH2Z2_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH2Z2_4_z_V, i64 0, i64 %newIndex29
  %vmStubsPH2Z2_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_4_phi_V, i64 0, i64 %newIndex29
  %vmStubsPH2Z2_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH2Z2_4_r_V, i64 0, i64 %newIndex29
  %vmStubsPH2Z2_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH2Z2_4_pt_V, i64 0, i64 %newIndex29
  %vmStubsPH2Z2_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH2Z2_4_index_V, i64 0, i64 %newIndex29
  %call_ret38 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH2Z2_z_V_addr_4372_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret38, 0
  store i4 %vmStubsPH2Z2_z_V_addr_4372_ret, i4* %vmStubsPH2Z2_4_z_V_addr, align 1
  %vmStubsPH2Z2_phi_V_addr_4383_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret38, 1
  store i3 %vmStubsPH2Z2_phi_V_addr_4383_r, i3* %vmStubsPH2Z2_4_phi_V_addr, align 1
  %vmStubsPH2Z2_r_V_addr_4394_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret38, 2
  store i2 %vmStubsPH2Z2_r_V_addr_4394_ret, i2* %vmStubsPH2Z2_4_r_V_addr, align 1
  %vmStubsPH2Z2_pt_V_addr_4405_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret38, 3
  store i3 %vmStubsPH2Z2_pt_V_addr_4405_re, i3* %vmStubsPH2Z2_4_pt_V_addr, align 1
  %vmStubsPH2Z2_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret38, 4
  store i6 %vmStubsPH2Z2_index_V_addr_3, i6* %vmStubsPH2Z2_4_index_V_addr, align 1
  %tmp_45 = add i6 %nPH2Z2_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH2Z2_4_V, i6 %tmp_45)
  br label %._crit_edge400.i

branch241303:                                     ; preds = %20
  %nPH3Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH3Z2_4_V)
  %newIndex30 = zext i6 %nPH3Z2_4_V_read to i64
  %vmStubsPH3Z2_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH3Z2_4_z_V, i64 0, i64 %newIndex30
  %vmStubsPH3Z2_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_4_phi_V, i64 0, i64 %newIndex30
  %vmStubsPH3Z2_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH3Z2_4_r_V, i64 0, i64 %newIndex30
  %vmStubsPH3Z2_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH3Z2_4_pt_V, i64 0, i64 %newIndex30
  %vmStubsPH3Z2_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH3Z2_4_index_V, i64 0, i64 %newIndex30
  %call_ret39 = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH3Z2_z_V_addr_4427_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret39, 0
  store i4 %vmStubsPH3Z2_z_V_addr_4427_ret, i4* %vmStubsPH3Z2_4_z_V_addr, align 1
  %vmStubsPH3Z2_phi_V_addr_4438_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret39, 1
  store i3 %vmStubsPH3Z2_phi_V_addr_4438_r, i3* %vmStubsPH3Z2_4_phi_V_addr, align 1
  %vmStubsPH3Z2_r_V_addr_4449_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret39, 2
  store i2 %vmStubsPH3Z2_r_V_addr_4449_ret, i2* %vmStubsPH3Z2_4_r_V_addr, align 1
  %vmStubsPH3Z2_pt_V_addr_4460_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret39, 3
  store i3 %vmStubsPH3Z2_pt_V_addr_4460_re, i3* %vmStubsPH3Z2_4_pt_V_addr, align 1
  %vmStubsPH3Z2_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret39, 4
  store i6 %vmStubsPH3Z2_index_V_addr_3, i6* %vmStubsPH3Z2_4_index_V_addr, align 1
  %tmp_46 = add i6 %nPH3Z2_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH3Z2_4_V, i6 %tmp_46)
  br label %._crit_edge400.i

branch41379:                                      ; preds = %20
  %nPH4Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %nPH4Z2_4_V)
  %newIndex31 = zext i6 %nPH4Z2_4_V_read to i64
  %vmStubsPH4Z2_4_z_V_addr = getelementptr [64 x i4]* %vmStubsPH4Z2_4_z_V, i64 0, i64 %newIndex31
  %vmStubsPH4Z2_4_phi_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_4_phi_V, i64 0, i64 %newIndex31
  %vmStubsPH4Z2_4_r_V_addr = getelementptr [64 x i2]* %vmStubsPH4Z2_4_r_V, i64 0, i64 %newIndex31
  %vmStubsPH4Z2_4_pt_V_addr = getelementptr [64 x i3]* %vmStubsPH4Z2_4_pt_V, i64 0, i64 %newIndex31
  %vmStubsPH4Z2_4_index_V_addr = getelementptr [64 x i6]* %vmStubsPH4Z2_4_index_V, i64 0, i64 %newIndex31
  %call_ret = call fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %redZ_V_4, i3 %redPhi_V_4, i2 %redR_V_4, i3 %redPt_V_4, i6 %p_7)
  %vmStubsPH4Z2_z_V_addr_4482_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret, 0
  store i4 %vmStubsPH4Z2_z_V_addr_4482_ret, i4* %vmStubsPH4Z2_4_z_V_addr, align 1
  %vmStubsPH4Z2_phi_V_addr_4493_r = extractvalue { i4, i3, i2, i3, i6 } %call_ret, 1
  store i3 %vmStubsPH4Z2_phi_V_addr_4493_r, i3* %vmStubsPH4Z2_4_phi_V_addr, align 1
  %vmStubsPH4Z2_r_V_addr_4504_ret = extractvalue { i4, i3, i2, i3, i6 } %call_ret, 2
  store i2 %vmStubsPH4Z2_r_V_addr_4504_ret, i2* %vmStubsPH4Z2_4_r_V_addr, align 1
  %vmStubsPH4Z2_pt_V_addr_4515_re = extractvalue { i4, i3, i2, i3, i6 } %call_ret, 3
  store i3 %vmStubsPH4Z2_pt_V_addr_4515_re, i3* %vmStubsPH4Z2_4_pt_V_addr, align 1
  %vmStubsPH4Z2_index_V_addr_3 = extractvalue { i4, i3, i2, i3, i6 } %call_ret, 4
  store i6 %vmStubsPH4Z2_index_V_addr_3, i6* %vmStubsPH4Z2_4_index_V_addr, align 1
  %tmp_47 = add i6 %nPH4Z2_4_V_read, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %nPH4Z2_4_V, i6 %tmp_47)
  br label %._crit_edge400.i

._crit_edge400.i:                                 ; preds = %branch41379, %branch241303, %branch41119, %branch241054, %20
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge.i: ; preds = %._crit_edge400.i, %._crit_edge.i
  %empty_26 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str14, i32 %tmp_36)
  %i_4 = add i7 %i_0_i, 1
  br label %17

VMRouter.exit:                                    ; preds = %17, %18
  ret void
}

define internal fastcc { i4, i3, i2, i3, i6 } @VMRouterDispatcher_AddStub(i4 %HLSReducedStubLayer_z_V_write, i3 %HLSReducedStubLayer_phi_V_write, i2 %HLSReducedStubLayer_r_V_write, i3 %HLSReducedStubLayer_pt_V_write, i6 %HLSReducedStubLayer_index_V_write) readnone {
  %HLSReducedStubLayer_index_V_wr = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %HLSReducedStubLayer_index_V_write)
  %HLSReducedStubLayer_pt_V_write_1 = call i3 @_ssdm_op_Read.ap_auto.i3(i3 %HLSReducedStubLayer_pt_V_write)
  %HLSReducedStubLayer_r_V_write_s = call i2 @_ssdm_op_Read.ap_auto.i2(i2 %HLSReducedStubLayer_r_V_write)
  %HLSReducedStubLayer_phi_V_writ = call i3 @_ssdm_op_Read.ap_auto.i3(i3 %HLSReducedStubLayer_phi_V_write)
  %HLSReducedStubLayer_z_V_write_s = call i4 @_ssdm_op_Read.ap_auto.i4(i4 %HLSReducedStubLayer_z_V_write)
  %mrv = insertvalue { i4, i3, i2, i3, i6 } undef, i4 %HLSReducedStubLayer_z_V_write_s, 0
  %mrv_1 = insertvalue { i4, i3, i2, i3, i6 } %mrv, i3 %HLSReducedStubLayer_phi_V_writ, 1
  %mrv_2 = insertvalue { i4, i3, i2, i3, i6 } %mrv_1, i2 %HLSReducedStubLayer_r_V_write_s, 2
  %mrv_3 = insertvalue { i4, i3, i2, i3, i6 } %mrv_2, i3 %HLSReducedStubLayer_pt_V_write_1, 3
  %mrv_4 = insertvalue { i4, i3, i2, i3, i6 } %mrv_3, i6 %HLSReducedStubLayer_index_V_wr, 4
  ret { i4, i3, i2, i3, i6 } %mrv_4
}

!opencl.kernels = !{!0, !7, !7, !13, !7, !17, !17, !7, !23, !7, !7, !7, !26, !26, !7, !26, !26, !7, !7, !28, !34, !34, !7, !36, !7, !7, !39, !39, !41, !7, !7, !7, !26, !26, !7, !7, !43, !45, !47, !47, !49, !7, !7, !7, !26, !26, !7, !7, !51, !53, !55, !55, !57, !7, !7, !7, !59, !59, !7, !7, !7, !7, !61, !67, !69, !71, !73, !75, !81, !83, !85, !7, !7, !7, !7}
!hls.encrypted.func = !{}
!llvm.map.gv = !{!87}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"int*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"stubsInLayer", metadata !"allStubs", metadata !"vmStubsPH1Z1", metadata !"vmStubsPH2Z1", metadata !"vmStubsPH3Z1", metadata !"vmStubsPH4Z1", metadata !"vmStubsPH1Z2", metadata !"vmStubsPH2Z2", metadata !"vmStubsPH3Z2", metadata !"vmStubsPH4Z2", metadata !"nStubs", metadata !"nPH1Z1", metadata !"nPH2Z1", metadata !"nPH3Z1", metadata !"nPH4Z1", metadata !"nPH1Z2", metadata !"nPH2Z2", metadata !"nPH3Z2", metadata !"nPH4Z2"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{null, metadata !8, metadata !9, metadata !10, metadata !11, metadata !12, metadata !6}
!8 = metadata !{metadata !"kernel_arg_addr_space"}
!9 = metadata !{metadata !"kernel_arg_access_qual"}
!10 = metadata !{metadata !"kernel_arg_type"}
!11 = metadata !{metadata !"kernel_arg_type_qual"}
!12 = metadata !{metadata !"kernel_arg_name"}
!13 = metadata !{null, metadata !14, metadata !2, metadata !15, metadata !16, metadata !5, metadata !6}
!14 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 0, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1}
!15 = metadata !{metadata !"kernel_arg_type", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"int", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*"}
!16 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"const", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!17 = metadata !{null, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !6}
!18 = metadata !{metadata !"kernel_arg_addr_space", i32 0}
!19 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none"}
!20 = metadata !{metadata !"kernel_arg_type", metadata !"int"}
!21 = metadata !{metadata !"kernel_arg_type_qual", metadata !""}
!22 = metadata !{metadata !"kernel_arg_name", metadata !"op"}
!23 = metadata !{null, metadata !18, metadata !19, metadata !24, metadata !21, metadata !25, metadata !6}
!24 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<1, false> &"}
!25 = metadata !{metadata !"kernel_arg_name", metadata !"op2"}
!26 = metadata !{null, metadata !18, metadata !19, metadata !27, metadata !21, metadata !22, metadata !6}
!27 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<32, false> &"}
!28 = metadata !{null, metadata !29, metadata !30, metadata !31, metadata !32, metadata !33, metadata !6}
!29 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0}
!30 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none"}
!31 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"uint"}
!32 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !""}
!33 = metadata !{metadata !"kernel_arg_name", metadata !"op", metadata !"i_op"}
!34 = metadata !{null, metadata !18, metadata !19, metadata !35, metadata !21, metadata !22, metadata !6}
!35 = metadata !{metadata !"kernel_arg_type", metadata !"uint"}
!36 = metadata !{null, metadata !29, metadata !30, metadata !37, metadata !32, metadata !38, metadata !6}
!37 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"const ap_int_base<32, false> &"}
!38 = metadata !{metadata !"kernel_arg_name", metadata !"op", metadata !"op2"}
!39 = metadata !{null, metadata !18, metadata !19, metadata !40, metadata !21, metadata !22, metadata !6}
!40 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &"}
!41 = metadata !{null, metadata !29, metadata !30, metadata !42, metadata !32, metadata !38, metadata !6}
!42 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"int"}
!43 = metadata !{null, metadata !29, metadata !30, metadata !44, metadata !32, metadata !33, metadata !6}
!44 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"uint"}
!45 = metadata !{null, metadata !29, metadata !30, metadata !46, metadata !32, metadata !38, metadata !6}
!46 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"const ap_int_base<32, false> &"}
!47 = metadata !{null, metadata !18, metadata !19, metadata !48, metadata !21, metadata !22, metadata !6}
!48 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &"}
!49 = metadata !{null, metadata !29, metadata !30, metadata !50, metadata !32, metadata !38, metadata !6}
!50 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"int"}
!51 = metadata !{null, metadata !29, metadata !30, metadata !52, metadata !32, metadata !33, metadata !6}
!52 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"uint"}
!53 = metadata !{null, metadata !29, metadata !30, metadata !54, metadata !32, metadata !38, metadata !6}
!54 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"const ap_int_base<32, false> &"}
!55 = metadata !{null, metadata !18, metadata !19, metadata !56, metadata !21, metadata !22, metadata !6}
!56 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &"}
!57 = metadata !{null, metadata !29, metadata !30, metadata !58, metadata !32, metadata !38, metadata !6}
!58 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"int"}
!59 = metadata !{null, metadata !18, metadata !19, metadata !20, metadata !21, metadata !60, metadata !6}
!60 = metadata !{metadata !"kernel_arg_name", metadata !"val"}
!61 = metadata !{null, metadata !62, metadata !63, metadata !64, metadata !65, metadata !66, metadata !6}
!62 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 0, i32 0, i32 0}
!63 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!64 = metadata !{metadata !"kernel_arg_type", metadata !"ReducedZ_Layer", metadata !"ReducedPhi_Layer", metadata !"ReducedR_Layer", metadata !"ReducedPt_Layer", metadata !"ReducedIndex"}
!65 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!66 = metadata !{metadata !"kernel_arg_name", metadata !"newZ", metadata !"newPhi", metadata !"newR", metadata !"newPt", metadata !"newIndex"}
!67 = metadata !{null, metadata !18, metadata !19, metadata !68, metadata !21, metadata !25, metadata !6}
!68 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<6> &"}
!69 = metadata !{null, metadata !18, metadata !19, metadata !70, metadata !21, metadata !25, metadata !6}
!70 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<2> &"}
!71 = metadata !{null, metadata !18, metadata !19, metadata !72, metadata !21, metadata !25, metadata !6}
!72 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<3> &"}
!73 = metadata !{null, metadata !18, metadata !19, metadata !74, metadata !21, metadata !25, metadata !6}
!74 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<4> &"}
!75 = metadata !{null, metadata !76, metadata !77, metadata !78, metadata !79, metadata !80, metadata !6}
!76 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 0, i32 0}
!77 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!78 = metadata !{metadata !"kernel_arg_type", metadata !"FullZ_Layer_PS", metadata !"FullPhi_Layer_PS", metadata !"FullR_Layer_PS", metadata !"FullPt_Layer_PS"}
!79 = metadata !{metadata !"kernel_arg_type_qual", metadata !"const", metadata !"const", metadata !"const", metadata !"const"}
!80 = metadata !{metadata !"kernel_arg_name", metadata !"newZ", metadata !"newPhi", metadata !"newR", metadata !"newPt"}
!81 = metadata !{null, metadata !18, metadata !19, metadata !82, metadata !21, metadata !25, metadata !6}
!82 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<7> &"}
!83 = metadata !{null, metadata !18, metadata !19, metadata !84, metadata !21, metadata !25, metadata !6}
!84 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<14> &"}
!85 = metadata !{null, metadata !18, metadata !19, metadata !86, metadata !21, metadata !25, metadata !6}
!86 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<12> &"}
!87 = metadata !{metadata !88, [2 x i32]* @llvm_global_ctors_0}
!88 = metadata !{metadata !89}
!89 = metadata !{i32 0, i32 31, metadata !90}
!90 = metadata !{metadata !91}
!91 = metadata !{metadata !"llvm.global_ctors.0", metadata !92, metadata !"", i32 0, i32 31}
!92 = metadata !{metadata !93}
!93 = metadata !{i32 0, i32 1, i32 1}
!94 = metadata !{metadata !95}
!95 = metadata !{i32 0, i32 5, metadata !96}
!96 = metadata !{metadata !97}
!97 = metadata !{metadata !"vmStubsPH4Z2.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!98 = metadata !{metadata !99}
!99 = metadata !{i32 256, i32 319, i32 1}
!100 = metadata !{metadata !101}
!101 = metadata !{i32 0, i32 5, metadata !102}
!102 = metadata !{metadata !103}
!103 = metadata !{metadata !"vmStubsPH4Z2.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!104 = metadata !{metadata !105}
!105 = metadata !{i32 192, i32 255, i32 1}
!106 = metadata !{metadata !107}
!107 = metadata !{i32 0, i32 5, metadata !108}
!108 = metadata !{metadata !109}
!109 = metadata !{metadata !"vmStubsPH4Z2.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!110 = metadata !{metadata !111}
!111 = metadata !{i32 128, i32 191, i32 1}
!112 = metadata !{metadata !113}
!113 = metadata !{i32 0, i32 5, metadata !114}
!114 = metadata !{metadata !115}
!115 = metadata !{metadata !"vmStubsPH4Z2.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!116 = metadata !{metadata !117}
!117 = metadata !{i32 64, i32 127, i32 1}
!118 = metadata !{metadata !119}
!119 = metadata !{i32 0, i32 5, metadata !120}
!120 = metadata !{metadata !121}
!121 = metadata !{metadata !"vmStubsPH4Z2.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!122 = metadata !{metadata !123}
!123 = metadata !{i32 0, i32 63, i32 1}
!124 = metadata !{metadata !125}
!125 = metadata !{i32 0, i32 2, metadata !126}
!126 = metadata !{metadata !127}
!127 = metadata !{metadata !"vmStubsPH4Z2.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!128 = metadata !{metadata !129}
!129 = metadata !{i32 0, i32 2, metadata !130}
!130 = metadata !{metadata !131}
!131 = metadata !{metadata !"vmStubsPH4Z2.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!132 = metadata !{metadata !133}
!133 = metadata !{i32 0, i32 2, metadata !134}
!134 = metadata !{metadata !135}
!135 = metadata !{metadata !"vmStubsPH4Z2.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!136 = metadata !{metadata !137}
!137 = metadata !{i32 0, i32 2, metadata !138}
!138 = metadata !{metadata !139}
!139 = metadata !{metadata !"vmStubsPH4Z2.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!140 = metadata !{metadata !141}
!141 = metadata !{i32 0, i32 2, metadata !142}
!142 = metadata !{metadata !143}
!143 = metadata !{metadata !"vmStubsPH4Z2.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!144 = metadata !{metadata !145}
!145 = metadata !{i32 0, i32 1, metadata !146}
!146 = metadata !{metadata !147}
!147 = metadata !{metadata !"vmStubsPH4Z2.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!148 = metadata !{metadata !149}
!149 = metadata !{i32 0, i32 1, metadata !150}
!150 = metadata !{metadata !151}
!151 = metadata !{metadata !"vmStubsPH4Z2.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!152 = metadata !{metadata !153}
!153 = metadata !{i32 0, i32 1, metadata !154}
!154 = metadata !{metadata !155}
!155 = metadata !{metadata !"vmStubsPH4Z2.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!156 = metadata !{metadata !157}
!157 = metadata !{i32 0, i32 1, metadata !158}
!158 = metadata !{metadata !159}
!159 = metadata !{metadata !"vmStubsPH4Z2.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!160 = metadata !{metadata !161}
!161 = metadata !{i32 0, i32 1, metadata !162}
!162 = metadata !{metadata !163}
!163 = metadata !{metadata !"vmStubsPH4Z2.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!164 = metadata !{metadata !165}
!165 = metadata !{i32 0, i32 2, metadata !166}
!166 = metadata !{metadata !167}
!167 = metadata !{metadata !"vmStubsPH4Z2.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!168 = metadata !{metadata !169}
!169 = metadata !{i32 0, i32 2, metadata !170}
!170 = metadata !{metadata !171}
!171 = metadata !{metadata !"vmStubsPH4Z2.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!172 = metadata !{metadata !173}
!173 = metadata !{i32 0, i32 2, metadata !174}
!174 = metadata !{metadata !175}
!175 = metadata !{metadata !"vmStubsPH4Z2.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!176 = metadata !{metadata !177}
!177 = metadata !{i32 0, i32 2, metadata !178}
!178 = metadata !{metadata !179}
!179 = metadata !{metadata !"vmStubsPH4Z2.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!180 = metadata !{metadata !181}
!181 = metadata !{i32 0, i32 2, metadata !182}
!182 = metadata !{metadata !183}
!183 = metadata !{metadata !"vmStubsPH4Z2.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!184 = metadata !{metadata !185}
!185 = metadata !{i32 0, i32 3, metadata !186}
!186 = metadata !{metadata !187}
!187 = metadata !{metadata !"vmStubsPH4Z2.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!188 = metadata !{metadata !189}
!189 = metadata !{i32 0, i32 3, metadata !190}
!190 = metadata !{metadata !191}
!191 = metadata !{metadata !"vmStubsPH4Z2.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!192 = metadata !{metadata !193}
!193 = metadata !{i32 0, i32 3, metadata !194}
!194 = metadata !{metadata !195}
!195 = metadata !{metadata !"vmStubsPH4Z2.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!196 = metadata !{metadata !197}
!197 = metadata !{i32 0, i32 3, metadata !198}
!198 = metadata !{metadata !199}
!199 = metadata !{metadata !"vmStubsPH4Z2.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!200 = metadata !{metadata !201}
!201 = metadata !{i32 0, i32 3, metadata !202}
!202 = metadata !{metadata !203}
!203 = metadata !{metadata !"vmStubsPH4Z2.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!204 = metadata !{metadata !205}
!205 = metadata !{i32 0, i32 5, metadata !206}
!206 = metadata !{metadata !207}
!207 = metadata !{metadata !"vmStubsPH3Z2.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!208 = metadata !{metadata !209}
!209 = metadata !{i32 0, i32 5, metadata !210}
!210 = metadata !{metadata !211}
!211 = metadata !{metadata !"vmStubsPH3Z2.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!212 = metadata !{metadata !213}
!213 = metadata !{i32 0, i32 5, metadata !214}
!214 = metadata !{metadata !215}
!215 = metadata !{metadata !"vmStubsPH3Z2.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!216 = metadata !{metadata !217}
!217 = metadata !{i32 0, i32 5, metadata !218}
!218 = metadata !{metadata !219}
!219 = metadata !{metadata !"vmStubsPH3Z2.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!220 = metadata !{metadata !221}
!221 = metadata !{i32 0, i32 5, metadata !222}
!222 = metadata !{metadata !223}
!223 = metadata !{metadata !"vmStubsPH3Z2.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!224 = metadata !{metadata !225}
!225 = metadata !{i32 0, i32 2, metadata !226}
!226 = metadata !{metadata !227}
!227 = metadata !{metadata !"vmStubsPH3Z2.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!228 = metadata !{metadata !229}
!229 = metadata !{i32 0, i32 2, metadata !230}
!230 = metadata !{metadata !231}
!231 = metadata !{metadata !"vmStubsPH3Z2.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!232 = metadata !{metadata !233}
!233 = metadata !{i32 0, i32 2, metadata !234}
!234 = metadata !{metadata !235}
!235 = metadata !{metadata !"vmStubsPH3Z2.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!236 = metadata !{metadata !237}
!237 = metadata !{i32 0, i32 2, metadata !238}
!238 = metadata !{metadata !239}
!239 = metadata !{metadata !"vmStubsPH3Z2.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!240 = metadata !{metadata !241}
!241 = metadata !{i32 0, i32 2, metadata !242}
!242 = metadata !{metadata !243}
!243 = metadata !{metadata !"vmStubsPH3Z2.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!244 = metadata !{metadata !245}
!245 = metadata !{i32 0, i32 1, metadata !246}
!246 = metadata !{metadata !247}
!247 = metadata !{metadata !"vmStubsPH3Z2.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!248 = metadata !{metadata !249}
!249 = metadata !{i32 0, i32 1, metadata !250}
!250 = metadata !{metadata !251}
!251 = metadata !{metadata !"vmStubsPH3Z2.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!252 = metadata !{metadata !253}
!253 = metadata !{i32 0, i32 1, metadata !254}
!254 = metadata !{metadata !255}
!255 = metadata !{metadata !"vmStubsPH3Z2.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!256 = metadata !{metadata !257}
!257 = metadata !{i32 0, i32 1, metadata !258}
!258 = metadata !{metadata !259}
!259 = metadata !{metadata !"vmStubsPH3Z2.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!260 = metadata !{metadata !261}
!261 = metadata !{i32 0, i32 1, metadata !262}
!262 = metadata !{metadata !263}
!263 = metadata !{metadata !"vmStubsPH3Z2.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!264 = metadata !{metadata !265}
!265 = metadata !{i32 0, i32 2, metadata !266}
!266 = metadata !{metadata !267}
!267 = metadata !{metadata !"vmStubsPH3Z2.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!268 = metadata !{metadata !269}
!269 = metadata !{i32 0, i32 2, metadata !270}
!270 = metadata !{metadata !271}
!271 = metadata !{metadata !"vmStubsPH3Z2.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!272 = metadata !{metadata !273}
!273 = metadata !{i32 0, i32 2, metadata !274}
!274 = metadata !{metadata !275}
!275 = metadata !{metadata !"vmStubsPH3Z2.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!276 = metadata !{metadata !277}
!277 = metadata !{i32 0, i32 2, metadata !278}
!278 = metadata !{metadata !279}
!279 = metadata !{metadata !"vmStubsPH3Z2.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!280 = metadata !{metadata !281}
!281 = metadata !{i32 0, i32 2, metadata !282}
!282 = metadata !{metadata !283}
!283 = metadata !{metadata !"vmStubsPH3Z2.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!284 = metadata !{metadata !285}
!285 = metadata !{i32 0, i32 3, metadata !286}
!286 = metadata !{metadata !287}
!287 = metadata !{metadata !"vmStubsPH3Z2.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!288 = metadata !{metadata !289}
!289 = metadata !{i32 0, i32 3, metadata !290}
!290 = metadata !{metadata !291}
!291 = metadata !{metadata !"vmStubsPH3Z2.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!292 = metadata !{metadata !293}
!293 = metadata !{i32 0, i32 3, metadata !294}
!294 = metadata !{metadata !295}
!295 = metadata !{metadata !"vmStubsPH3Z2.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!296 = metadata !{metadata !297}
!297 = metadata !{i32 0, i32 3, metadata !298}
!298 = metadata !{metadata !299}
!299 = metadata !{metadata !"vmStubsPH3Z2.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!300 = metadata !{metadata !301}
!301 = metadata !{i32 0, i32 3, metadata !302}
!302 = metadata !{metadata !303}
!303 = metadata !{metadata !"vmStubsPH3Z2.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!304 = metadata !{metadata !305}
!305 = metadata !{i32 0, i32 5, metadata !306}
!306 = metadata !{metadata !307}
!307 = metadata !{metadata !"vmStubsPH2Z2.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!308 = metadata !{metadata !309}
!309 = metadata !{i32 0, i32 5, metadata !310}
!310 = metadata !{metadata !311}
!311 = metadata !{metadata !"vmStubsPH2Z2.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!312 = metadata !{metadata !313}
!313 = metadata !{i32 0, i32 5, metadata !314}
!314 = metadata !{metadata !315}
!315 = metadata !{metadata !"vmStubsPH2Z2.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!316 = metadata !{metadata !317}
!317 = metadata !{i32 0, i32 5, metadata !318}
!318 = metadata !{metadata !319}
!319 = metadata !{metadata !"vmStubsPH2Z2.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!320 = metadata !{metadata !321}
!321 = metadata !{i32 0, i32 5, metadata !322}
!322 = metadata !{metadata !323}
!323 = metadata !{metadata !"vmStubsPH2Z2.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!324 = metadata !{metadata !325}
!325 = metadata !{i32 0, i32 2, metadata !326}
!326 = metadata !{metadata !327}
!327 = metadata !{metadata !"vmStubsPH2Z2.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!328 = metadata !{metadata !329}
!329 = metadata !{i32 0, i32 2, metadata !330}
!330 = metadata !{metadata !331}
!331 = metadata !{metadata !"vmStubsPH2Z2.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!332 = metadata !{metadata !333}
!333 = metadata !{i32 0, i32 2, metadata !334}
!334 = metadata !{metadata !335}
!335 = metadata !{metadata !"vmStubsPH2Z2.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!336 = metadata !{metadata !337}
!337 = metadata !{i32 0, i32 2, metadata !338}
!338 = metadata !{metadata !339}
!339 = metadata !{metadata !"vmStubsPH2Z2.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!340 = metadata !{metadata !341}
!341 = metadata !{i32 0, i32 2, metadata !342}
!342 = metadata !{metadata !343}
!343 = metadata !{metadata !"vmStubsPH2Z2.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!344 = metadata !{metadata !345}
!345 = metadata !{i32 0, i32 1, metadata !346}
!346 = metadata !{metadata !347}
!347 = metadata !{metadata !"vmStubsPH2Z2.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!348 = metadata !{metadata !349}
!349 = metadata !{i32 0, i32 1, metadata !350}
!350 = metadata !{metadata !351}
!351 = metadata !{metadata !"vmStubsPH2Z2.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!352 = metadata !{metadata !353}
!353 = metadata !{i32 0, i32 1, metadata !354}
!354 = metadata !{metadata !355}
!355 = metadata !{metadata !"vmStubsPH2Z2.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!356 = metadata !{metadata !357}
!357 = metadata !{i32 0, i32 1, metadata !358}
!358 = metadata !{metadata !359}
!359 = metadata !{metadata !"vmStubsPH2Z2.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!360 = metadata !{metadata !361}
!361 = metadata !{i32 0, i32 1, metadata !362}
!362 = metadata !{metadata !363}
!363 = metadata !{metadata !"vmStubsPH2Z2.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!364 = metadata !{metadata !365}
!365 = metadata !{i32 0, i32 2, metadata !366}
!366 = metadata !{metadata !367}
!367 = metadata !{metadata !"vmStubsPH2Z2.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!368 = metadata !{metadata !369}
!369 = metadata !{i32 0, i32 2, metadata !370}
!370 = metadata !{metadata !371}
!371 = metadata !{metadata !"vmStubsPH2Z2.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!372 = metadata !{metadata !373}
!373 = metadata !{i32 0, i32 2, metadata !374}
!374 = metadata !{metadata !375}
!375 = metadata !{metadata !"vmStubsPH2Z2.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!376 = metadata !{metadata !377}
!377 = metadata !{i32 0, i32 2, metadata !378}
!378 = metadata !{metadata !379}
!379 = metadata !{metadata !"vmStubsPH2Z2.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!380 = metadata !{metadata !381}
!381 = metadata !{i32 0, i32 2, metadata !382}
!382 = metadata !{metadata !383}
!383 = metadata !{metadata !"vmStubsPH2Z2.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!384 = metadata !{metadata !385}
!385 = metadata !{i32 0, i32 3, metadata !386}
!386 = metadata !{metadata !387}
!387 = metadata !{metadata !"vmStubsPH2Z2.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!388 = metadata !{metadata !389}
!389 = metadata !{i32 0, i32 3, metadata !390}
!390 = metadata !{metadata !391}
!391 = metadata !{metadata !"vmStubsPH2Z2.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!392 = metadata !{metadata !393}
!393 = metadata !{i32 0, i32 3, metadata !394}
!394 = metadata !{metadata !395}
!395 = metadata !{metadata !"vmStubsPH2Z2.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!396 = metadata !{metadata !397}
!397 = metadata !{i32 0, i32 3, metadata !398}
!398 = metadata !{metadata !399}
!399 = metadata !{metadata !"vmStubsPH2Z2.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!400 = metadata !{metadata !401}
!401 = metadata !{i32 0, i32 3, metadata !402}
!402 = metadata !{metadata !403}
!403 = metadata !{metadata !"vmStubsPH2Z2.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!404 = metadata !{metadata !405}
!405 = metadata !{i32 0, i32 5, metadata !406}
!406 = metadata !{metadata !407}
!407 = metadata !{metadata !"vmStubsPH1Z2.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!408 = metadata !{metadata !409}
!409 = metadata !{i32 0, i32 5, metadata !410}
!410 = metadata !{metadata !411}
!411 = metadata !{metadata !"vmStubsPH1Z2.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!412 = metadata !{metadata !413}
!413 = metadata !{i32 0, i32 5, metadata !414}
!414 = metadata !{metadata !415}
!415 = metadata !{metadata !"vmStubsPH1Z2.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!416 = metadata !{metadata !417}
!417 = metadata !{i32 0, i32 5, metadata !418}
!418 = metadata !{metadata !419}
!419 = metadata !{metadata !"vmStubsPH1Z2.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!420 = metadata !{metadata !421}
!421 = metadata !{i32 0, i32 5, metadata !422}
!422 = metadata !{metadata !423}
!423 = metadata !{metadata !"vmStubsPH1Z2.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!424 = metadata !{metadata !425}
!425 = metadata !{i32 0, i32 2, metadata !426}
!426 = metadata !{metadata !427}
!427 = metadata !{metadata !"vmStubsPH1Z2.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!428 = metadata !{metadata !429}
!429 = metadata !{i32 0, i32 2, metadata !430}
!430 = metadata !{metadata !431}
!431 = metadata !{metadata !"vmStubsPH1Z2.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!432 = metadata !{metadata !433}
!433 = metadata !{i32 0, i32 2, metadata !434}
!434 = metadata !{metadata !435}
!435 = metadata !{metadata !"vmStubsPH1Z2.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!436 = metadata !{metadata !437}
!437 = metadata !{i32 0, i32 2, metadata !438}
!438 = metadata !{metadata !439}
!439 = metadata !{metadata !"vmStubsPH1Z2.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!440 = metadata !{metadata !441}
!441 = metadata !{i32 0, i32 2, metadata !442}
!442 = metadata !{metadata !443}
!443 = metadata !{metadata !"vmStubsPH1Z2.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!444 = metadata !{metadata !445}
!445 = metadata !{i32 0, i32 1, metadata !446}
!446 = metadata !{metadata !447}
!447 = metadata !{metadata !"vmStubsPH1Z2.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!448 = metadata !{metadata !449}
!449 = metadata !{i32 0, i32 1, metadata !450}
!450 = metadata !{metadata !451}
!451 = metadata !{metadata !"vmStubsPH1Z2.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!452 = metadata !{metadata !453}
!453 = metadata !{i32 0, i32 1, metadata !454}
!454 = metadata !{metadata !455}
!455 = metadata !{metadata !"vmStubsPH1Z2.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!456 = metadata !{metadata !457}
!457 = metadata !{i32 0, i32 1, metadata !458}
!458 = metadata !{metadata !459}
!459 = metadata !{metadata !"vmStubsPH1Z2.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!460 = metadata !{metadata !461}
!461 = metadata !{i32 0, i32 1, metadata !462}
!462 = metadata !{metadata !463}
!463 = metadata !{metadata !"vmStubsPH1Z2.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!464 = metadata !{metadata !465}
!465 = metadata !{i32 0, i32 2, metadata !466}
!466 = metadata !{metadata !467}
!467 = metadata !{metadata !"vmStubsPH1Z2.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!468 = metadata !{metadata !469}
!469 = metadata !{i32 0, i32 2, metadata !470}
!470 = metadata !{metadata !471}
!471 = metadata !{metadata !"vmStubsPH1Z2.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!472 = metadata !{metadata !473}
!473 = metadata !{i32 0, i32 2, metadata !474}
!474 = metadata !{metadata !475}
!475 = metadata !{metadata !"vmStubsPH1Z2.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!476 = metadata !{metadata !477}
!477 = metadata !{i32 0, i32 2, metadata !478}
!478 = metadata !{metadata !479}
!479 = metadata !{metadata !"vmStubsPH1Z2.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!480 = metadata !{metadata !481}
!481 = metadata !{i32 0, i32 2, metadata !482}
!482 = metadata !{metadata !483}
!483 = metadata !{metadata !"vmStubsPH1Z2.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!484 = metadata !{metadata !485}
!485 = metadata !{i32 0, i32 3, metadata !486}
!486 = metadata !{metadata !487}
!487 = metadata !{metadata !"vmStubsPH1Z2.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!488 = metadata !{metadata !489}
!489 = metadata !{i32 0, i32 3, metadata !490}
!490 = metadata !{metadata !491}
!491 = metadata !{metadata !"vmStubsPH1Z2.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!492 = metadata !{metadata !493}
!493 = metadata !{i32 0, i32 3, metadata !494}
!494 = metadata !{metadata !495}
!495 = metadata !{metadata !"vmStubsPH1Z2.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!496 = metadata !{metadata !497}
!497 = metadata !{i32 0, i32 3, metadata !498}
!498 = metadata !{metadata !499}
!499 = metadata !{metadata !"vmStubsPH1Z2.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!500 = metadata !{metadata !501}
!501 = metadata !{i32 0, i32 3, metadata !502}
!502 = metadata !{metadata !503}
!503 = metadata !{metadata !"vmStubsPH1Z2.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!504 = metadata !{metadata !505}
!505 = metadata !{i32 0, i32 5, metadata !506}
!506 = metadata !{metadata !507}
!507 = metadata !{metadata !"vmStubsPH4Z1.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!508 = metadata !{metadata !509}
!509 = metadata !{i32 0, i32 5, metadata !510}
!510 = metadata !{metadata !511}
!511 = metadata !{metadata !"vmStubsPH4Z1.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!512 = metadata !{metadata !513}
!513 = metadata !{i32 0, i32 5, metadata !514}
!514 = metadata !{metadata !515}
!515 = metadata !{metadata !"vmStubsPH4Z1.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!516 = metadata !{metadata !517}
!517 = metadata !{i32 0, i32 5, metadata !518}
!518 = metadata !{metadata !519}
!519 = metadata !{metadata !"vmStubsPH4Z1.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!520 = metadata !{metadata !521}
!521 = metadata !{i32 0, i32 5, metadata !522}
!522 = metadata !{metadata !523}
!523 = metadata !{metadata !"vmStubsPH4Z1.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!524 = metadata !{metadata !525}
!525 = metadata !{i32 0, i32 2, metadata !526}
!526 = metadata !{metadata !527}
!527 = metadata !{metadata !"vmStubsPH4Z1.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!528 = metadata !{metadata !529}
!529 = metadata !{i32 0, i32 2, metadata !530}
!530 = metadata !{metadata !531}
!531 = metadata !{metadata !"vmStubsPH4Z1.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!532 = metadata !{metadata !533}
!533 = metadata !{i32 0, i32 2, metadata !534}
!534 = metadata !{metadata !535}
!535 = metadata !{metadata !"vmStubsPH4Z1.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!536 = metadata !{metadata !537}
!537 = metadata !{i32 0, i32 2, metadata !538}
!538 = metadata !{metadata !539}
!539 = metadata !{metadata !"vmStubsPH4Z1.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!540 = metadata !{metadata !541}
!541 = metadata !{i32 0, i32 2, metadata !542}
!542 = metadata !{metadata !543}
!543 = metadata !{metadata !"vmStubsPH4Z1.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!544 = metadata !{metadata !545}
!545 = metadata !{i32 0, i32 1, metadata !546}
!546 = metadata !{metadata !547}
!547 = metadata !{metadata !"vmStubsPH4Z1.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!548 = metadata !{metadata !549}
!549 = metadata !{i32 0, i32 1, metadata !550}
!550 = metadata !{metadata !551}
!551 = metadata !{metadata !"vmStubsPH4Z1.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!552 = metadata !{metadata !553}
!553 = metadata !{i32 0, i32 1, metadata !554}
!554 = metadata !{metadata !555}
!555 = metadata !{metadata !"vmStubsPH4Z1.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!556 = metadata !{metadata !557}
!557 = metadata !{i32 0, i32 1, metadata !558}
!558 = metadata !{metadata !559}
!559 = metadata !{metadata !"vmStubsPH4Z1.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!560 = metadata !{metadata !561}
!561 = metadata !{i32 0, i32 1, metadata !562}
!562 = metadata !{metadata !563}
!563 = metadata !{metadata !"vmStubsPH4Z1.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!564 = metadata !{metadata !565}
!565 = metadata !{i32 0, i32 2, metadata !566}
!566 = metadata !{metadata !567}
!567 = metadata !{metadata !"vmStubsPH4Z1.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!568 = metadata !{metadata !569}
!569 = metadata !{i32 0, i32 2, metadata !570}
!570 = metadata !{metadata !571}
!571 = metadata !{metadata !"vmStubsPH4Z1.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!572 = metadata !{metadata !573}
!573 = metadata !{i32 0, i32 2, metadata !574}
!574 = metadata !{metadata !575}
!575 = metadata !{metadata !"vmStubsPH4Z1.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!576 = metadata !{metadata !577}
!577 = metadata !{i32 0, i32 2, metadata !578}
!578 = metadata !{metadata !579}
!579 = metadata !{metadata !"vmStubsPH4Z1.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!580 = metadata !{metadata !581}
!581 = metadata !{i32 0, i32 2, metadata !582}
!582 = metadata !{metadata !583}
!583 = metadata !{metadata !"vmStubsPH4Z1.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!584 = metadata !{metadata !585}
!585 = metadata !{i32 0, i32 3, metadata !586}
!586 = metadata !{metadata !587}
!587 = metadata !{metadata !"vmStubsPH4Z1.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!588 = metadata !{metadata !589}
!589 = metadata !{i32 0, i32 3, metadata !590}
!590 = metadata !{metadata !591}
!591 = metadata !{metadata !"vmStubsPH4Z1.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!592 = metadata !{metadata !593}
!593 = metadata !{i32 0, i32 3, metadata !594}
!594 = metadata !{metadata !595}
!595 = metadata !{metadata !"vmStubsPH4Z1.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!596 = metadata !{metadata !597}
!597 = metadata !{i32 0, i32 3, metadata !598}
!598 = metadata !{metadata !599}
!599 = metadata !{metadata !"vmStubsPH4Z1.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!600 = metadata !{metadata !601}
!601 = metadata !{i32 0, i32 3, metadata !602}
!602 = metadata !{metadata !603}
!603 = metadata !{metadata !"vmStubsPH4Z1.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!604 = metadata !{metadata !605}
!605 = metadata !{i32 0, i32 5, metadata !606}
!606 = metadata !{metadata !607}
!607 = metadata !{metadata !"vmStubsPH3Z1.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!608 = metadata !{metadata !609}
!609 = metadata !{i32 0, i32 5, metadata !610}
!610 = metadata !{metadata !611}
!611 = metadata !{metadata !"vmStubsPH3Z1.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!612 = metadata !{metadata !613}
!613 = metadata !{i32 0, i32 5, metadata !614}
!614 = metadata !{metadata !615}
!615 = metadata !{metadata !"vmStubsPH3Z1.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!616 = metadata !{metadata !617}
!617 = metadata !{i32 0, i32 5, metadata !618}
!618 = metadata !{metadata !619}
!619 = metadata !{metadata !"vmStubsPH3Z1.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!620 = metadata !{metadata !621}
!621 = metadata !{i32 0, i32 5, metadata !622}
!622 = metadata !{metadata !623}
!623 = metadata !{metadata !"vmStubsPH3Z1.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!624 = metadata !{metadata !625}
!625 = metadata !{i32 0, i32 2, metadata !626}
!626 = metadata !{metadata !627}
!627 = metadata !{metadata !"vmStubsPH3Z1.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!628 = metadata !{metadata !629}
!629 = metadata !{i32 0, i32 2, metadata !630}
!630 = metadata !{metadata !631}
!631 = metadata !{metadata !"vmStubsPH3Z1.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!632 = metadata !{metadata !633}
!633 = metadata !{i32 0, i32 2, metadata !634}
!634 = metadata !{metadata !635}
!635 = metadata !{metadata !"vmStubsPH3Z1.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!636 = metadata !{metadata !637}
!637 = metadata !{i32 0, i32 2, metadata !638}
!638 = metadata !{metadata !639}
!639 = metadata !{metadata !"vmStubsPH3Z1.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!640 = metadata !{metadata !641}
!641 = metadata !{i32 0, i32 2, metadata !642}
!642 = metadata !{metadata !643}
!643 = metadata !{metadata !"vmStubsPH3Z1.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!644 = metadata !{metadata !645}
!645 = metadata !{i32 0, i32 1, metadata !646}
!646 = metadata !{metadata !647}
!647 = metadata !{metadata !"vmStubsPH3Z1.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!648 = metadata !{metadata !649}
!649 = metadata !{i32 0, i32 1, metadata !650}
!650 = metadata !{metadata !651}
!651 = metadata !{metadata !"vmStubsPH3Z1.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!652 = metadata !{metadata !653}
!653 = metadata !{i32 0, i32 1, metadata !654}
!654 = metadata !{metadata !655}
!655 = metadata !{metadata !"vmStubsPH3Z1.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!656 = metadata !{metadata !657}
!657 = metadata !{i32 0, i32 1, metadata !658}
!658 = metadata !{metadata !659}
!659 = metadata !{metadata !"vmStubsPH3Z1.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!660 = metadata !{metadata !661}
!661 = metadata !{i32 0, i32 1, metadata !662}
!662 = metadata !{metadata !663}
!663 = metadata !{metadata !"vmStubsPH3Z1.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!664 = metadata !{metadata !665}
!665 = metadata !{i32 0, i32 2, metadata !666}
!666 = metadata !{metadata !667}
!667 = metadata !{metadata !"vmStubsPH3Z1.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!668 = metadata !{metadata !669}
!669 = metadata !{i32 0, i32 2, metadata !670}
!670 = metadata !{metadata !671}
!671 = metadata !{metadata !"vmStubsPH3Z1.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!672 = metadata !{metadata !673}
!673 = metadata !{i32 0, i32 2, metadata !674}
!674 = metadata !{metadata !675}
!675 = metadata !{metadata !"vmStubsPH3Z1.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!676 = metadata !{metadata !677}
!677 = metadata !{i32 0, i32 2, metadata !678}
!678 = metadata !{metadata !679}
!679 = metadata !{metadata !"vmStubsPH3Z1.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!680 = metadata !{metadata !681}
!681 = metadata !{i32 0, i32 2, metadata !682}
!682 = metadata !{metadata !683}
!683 = metadata !{metadata !"vmStubsPH3Z1.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!684 = metadata !{metadata !685}
!685 = metadata !{i32 0, i32 3, metadata !686}
!686 = metadata !{metadata !687}
!687 = metadata !{metadata !"vmStubsPH3Z1.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!688 = metadata !{metadata !689}
!689 = metadata !{i32 0, i32 3, metadata !690}
!690 = metadata !{metadata !691}
!691 = metadata !{metadata !"vmStubsPH3Z1.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!692 = metadata !{metadata !693}
!693 = metadata !{i32 0, i32 3, metadata !694}
!694 = metadata !{metadata !695}
!695 = metadata !{metadata !"vmStubsPH3Z1.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!696 = metadata !{metadata !697}
!697 = metadata !{i32 0, i32 3, metadata !698}
!698 = metadata !{metadata !699}
!699 = metadata !{metadata !"vmStubsPH3Z1.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!700 = metadata !{metadata !701}
!701 = metadata !{i32 0, i32 3, metadata !702}
!702 = metadata !{metadata !703}
!703 = metadata !{metadata !"vmStubsPH3Z1.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!704 = metadata !{metadata !705}
!705 = metadata !{i32 0, i32 5, metadata !706}
!706 = metadata !{metadata !707}
!707 = metadata !{metadata !"vmStubsPH2Z1.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!708 = metadata !{metadata !709}
!709 = metadata !{i32 0, i32 5, metadata !710}
!710 = metadata !{metadata !711}
!711 = metadata !{metadata !"vmStubsPH2Z1.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!712 = metadata !{metadata !713}
!713 = metadata !{i32 0, i32 5, metadata !714}
!714 = metadata !{metadata !715}
!715 = metadata !{metadata !"vmStubsPH2Z1.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!716 = metadata !{metadata !717}
!717 = metadata !{i32 0, i32 5, metadata !718}
!718 = metadata !{metadata !719}
!719 = metadata !{metadata !"vmStubsPH2Z1.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!720 = metadata !{metadata !721}
!721 = metadata !{i32 0, i32 5, metadata !722}
!722 = metadata !{metadata !723}
!723 = metadata !{metadata !"vmStubsPH2Z1.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!724 = metadata !{metadata !725}
!725 = metadata !{i32 0, i32 2, metadata !726}
!726 = metadata !{metadata !727}
!727 = metadata !{metadata !"vmStubsPH2Z1.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!728 = metadata !{metadata !729}
!729 = metadata !{i32 0, i32 2, metadata !730}
!730 = metadata !{metadata !731}
!731 = metadata !{metadata !"vmStubsPH2Z1.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!732 = metadata !{metadata !733}
!733 = metadata !{i32 0, i32 2, metadata !734}
!734 = metadata !{metadata !735}
!735 = metadata !{metadata !"vmStubsPH2Z1.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!736 = metadata !{metadata !737}
!737 = metadata !{i32 0, i32 2, metadata !738}
!738 = metadata !{metadata !739}
!739 = metadata !{metadata !"vmStubsPH2Z1.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!740 = metadata !{metadata !741}
!741 = metadata !{i32 0, i32 2, metadata !742}
!742 = metadata !{metadata !743}
!743 = metadata !{metadata !"vmStubsPH2Z1.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!744 = metadata !{metadata !745}
!745 = metadata !{i32 0, i32 1, metadata !746}
!746 = metadata !{metadata !747}
!747 = metadata !{metadata !"vmStubsPH2Z1.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!748 = metadata !{metadata !749}
!749 = metadata !{i32 0, i32 1, metadata !750}
!750 = metadata !{metadata !751}
!751 = metadata !{metadata !"vmStubsPH2Z1.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!752 = metadata !{metadata !753}
!753 = metadata !{i32 0, i32 1, metadata !754}
!754 = metadata !{metadata !755}
!755 = metadata !{metadata !"vmStubsPH2Z1.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!756 = metadata !{metadata !757}
!757 = metadata !{i32 0, i32 1, metadata !758}
!758 = metadata !{metadata !759}
!759 = metadata !{metadata !"vmStubsPH2Z1.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!760 = metadata !{metadata !761}
!761 = metadata !{i32 0, i32 1, metadata !762}
!762 = metadata !{metadata !763}
!763 = metadata !{metadata !"vmStubsPH2Z1.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!764 = metadata !{metadata !765}
!765 = metadata !{i32 0, i32 2, metadata !766}
!766 = metadata !{metadata !767}
!767 = metadata !{metadata !"vmStubsPH2Z1.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!768 = metadata !{metadata !769}
!769 = metadata !{i32 0, i32 2, metadata !770}
!770 = metadata !{metadata !771}
!771 = metadata !{metadata !"vmStubsPH2Z1.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!772 = metadata !{metadata !773}
!773 = metadata !{i32 0, i32 2, metadata !774}
!774 = metadata !{metadata !775}
!775 = metadata !{metadata !"vmStubsPH2Z1.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!776 = metadata !{metadata !777}
!777 = metadata !{i32 0, i32 2, metadata !778}
!778 = metadata !{metadata !779}
!779 = metadata !{metadata !"vmStubsPH2Z1.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!780 = metadata !{metadata !781}
!781 = metadata !{i32 0, i32 2, metadata !782}
!782 = metadata !{metadata !783}
!783 = metadata !{metadata !"vmStubsPH2Z1.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!784 = metadata !{metadata !785}
!785 = metadata !{i32 0, i32 3, metadata !786}
!786 = metadata !{metadata !787}
!787 = metadata !{metadata !"vmStubsPH2Z1.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!788 = metadata !{metadata !789}
!789 = metadata !{i32 0, i32 3, metadata !790}
!790 = metadata !{metadata !791}
!791 = metadata !{metadata !"vmStubsPH2Z1.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!792 = metadata !{metadata !793}
!793 = metadata !{i32 0, i32 3, metadata !794}
!794 = metadata !{metadata !795}
!795 = metadata !{metadata !"vmStubsPH2Z1.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!796 = metadata !{metadata !797}
!797 = metadata !{i32 0, i32 3, metadata !798}
!798 = metadata !{metadata !799}
!799 = metadata !{metadata !"vmStubsPH2Z1.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!800 = metadata !{metadata !801}
!801 = metadata !{i32 0, i32 3, metadata !802}
!802 = metadata !{metadata !803}
!803 = metadata !{metadata !"vmStubsPH2Z1.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!804 = metadata !{metadata !805}
!805 = metadata !{i32 0, i32 5, metadata !806}
!806 = metadata !{metadata !807}
!807 = metadata !{metadata !"vmStubsPH1Z1.index.V", metadata !98, metadata !"uint6", i32 0, i32 5}
!808 = metadata !{metadata !809}
!809 = metadata !{i32 0, i32 5, metadata !810}
!810 = metadata !{metadata !811}
!811 = metadata !{metadata !"vmStubsPH1Z1.index.V", metadata !104, metadata !"uint6", i32 0, i32 5}
!812 = metadata !{metadata !813}
!813 = metadata !{i32 0, i32 5, metadata !814}
!814 = metadata !{metadata !815}
!815 = metadata !{metadata !"vmStubsPH1Z1.index.V", metadata !110, metadata !"uint6", i32 0, i32 5}
!816 = metadata !{metadata !817}
!817 = metadata !{i32 0, i32 5, metadata !818}
!818 = metadata !{metadata !819}
!819 = metadata !{metadata !"vmStubsPH1Z1.index.V", metadata !116, metadata !"uint6", i32 0, i32 5}
!820 = metadata !{metadata !821}
!821 = metadata !{i32 0, i32 5, metadata !822}
!822 = metadata !{metadata !823}
!823 = metadata !{metadata !"vmStubsPH1Z1.index.V", metadata !122, metadata !"uint6", i32 0, i32 5}
!824 = metadata !{metadata !825}
!825 = metadata !{i32 0, i32 2, metadata !826}
!826 = metadata !{metadata !827}
!827 = metadata !{metadata !"vmStubsPH1Z1.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!828 = metadata !{metadata !829}
!829 = metadata !{i32 0, i32 2, metadata !830}
!830 = metadata !{metadata !831}
!831 = metadata !{metadata !"vmStubsPH1Z1.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!832 = metadata !{metadata !833}
!833 = metadata !{i32 0, i32 2, metadata !834}
!834 = metadata !{metadata !835}
!835 = metadata !{metadata !"vmStubsPH1Z1.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!836 = metadata !{metadata !837}
!837 = metadata !{i32 0, i32 2, metadata !838}
!838 = metadata !{metadata !839}
!839 = metadata !{metadata !"vmStubsPH1Z1.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!840 = metadata !{metadata !841}
!841 = metadata !{i32 0, i32 2, metadata !842}
!842 = metadata !{metadata !843}
!843 = metadata !{metadata !"vmStubsPH1Z1.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!844 = metadata !{metadata !845}
!845 = metadata !{i32 0, i32 1, metadata !846}
!846 = metadata !{metadata !847}
!847 = metadata !{metadata !"vmStubsPH1Z1.r.V", metadata !98, metadata !"uint2", i32 0, i32 1}
!848 = metadata !{metadata !849}
!849 = metadata !{i32 0, i32 1, metadata !850}
!850 = metadata !{metadata !851}
!851 = metadata !{metadata !"vmStubsPH1Z1.r.V", metadata !104, metadata !"uint2", i32 0, i32 1}
!852 = metadata !{metadata !853}
!853 = metadata !{i32 0, i32 1, metadata !854}
!854 = metadata !{metadata !855}
!855 = metadata !{metadata !"vmStubsPH1Z1.r.V", metadata !110, metadata !"uint2", i32 0, i32 1}
!856 = metadata !{metadata !857}
!857 = metadata !{i32 0, i32 1, metadata !858}
!858 = metadata !{metadata !859}
!859 = metadata !{metadata !"vmStubsPH1Z1.r.V", metadata !116, metadata !"uint2", i32 0, i32 1}
!860 = metadata !{metadata !861}
!861 = metadata !{i32 0, i32 1, metadata !862}
!862 = metadata !{metadata !863}
!863 = metadata !{metadata !"vmStubsPH1Z1.r.V", metadata !122, metadata !"uint2", i32 0, i32 1}
!864 = metadata !{metadata !865}
!865 = metadata !{i32 0, i32 2, metadata !866}
!866 = metadata !{metadata !867}
!867 = metadata !{metadata !"vmStubsPH1Z1.phi.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!868 = metadata !{metadata !869}
!869 = metadata !{i32 0, i32 2, metadata !870}
!870 = metadata !{metadata !871}
!871 = metadata !{metadata !"vmStubsPH1Z1.phi.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!872 = metadata !{metadata !873}
!873 = metadata !{i32 0, i32 2, metadata !874}
!874 = metadata !{metadata !875}
!875 = metadata !{metadata !"vmStubsPH1Z1.phi.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!876 = metadata !{metadata !877}
!877 = metadata !{i32 0, i32 2, metadata !878}
!878 = metadata !{metadata !879}
!879 = metadata !{metadata !"vmStubsPH1Z1.phi.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!880 = metadata !{metadata !881}
!881 = metadata !{i32 0, i32 2, metadata !882}
!882 = metadata !{metadata !883}
!883 = metadata !{metadata !"vmStubsPH1Z1.phi.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!884 = metadata !{metadata !885}
!885 = metadata !{i32 0, i32 3, metadata !886}
!886 = metadata !{metadata !887}
!887 = metadata !{metadata !"vmStubsPH1Z1.z.V", metadata !98, metadata !"uint4", i32 0, i32 3}
!888 = metadata !{metadata !889}
!889 = metadata !{i32 0, i32 3, metadata !890}
!890 = metadata !{metadata !891}
!891 = metadata !{metadata !"vmStubsPH1Z1.z.V", metadata !104, metadata !"uint4", i32 0, i32 3}
!892 = metadata !{metadata !893}
!893 = metadata !{i32 0, i32 3, metadata !894}
!894 = metadata !{metadata !895}
!895 = metadata !{metadata !"vmStubsPH1Z1.z.V", metadata !110, metadata !"uint4", i32 0, i32 3}
!896 = metadata !{metadata !897}
!897 = metadata !{i32 0, i32 3, metadata !898}
!898 = metadata !{metadata !899}
!899 = metadata !{metadata !"vmStubsPH1Z1.z.V", metadata !116, metadata !"uint4", i32 0, i32 3}
!900 = metadata !{metadata !901}
!901 = metadata !{i32 0, i32 3, metadata !902}
!902 = metadata !{metadata !903}
!903 = metadata !{metadata !"vmStubsPH1Z1.z.V", metadata !122, metadata !"uint4", i32 0, i32 3}
!904 = metadata !{metadata !905}
!905 = metadata !{i32 0, i32 2, metadata !906}
!906 = metadata !{metadata !907}
!907 = metadata !{metadata !"allStubs.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!908 = metadata !{metadata !909}
!909 = metadata !{i32 0, i32 2, metadata !910}
!910 = metadata !{metadata !911}
!911 = metadata !{metadata !"allStubs.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!912 = metadata !{metadata !913}
!913 = metadata !{i32 0, i32 2, metadata !914}
!914 = metadata !{metadata !915}
!915 = metadata !{metadata !"allStubs.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!916 = metadata !{metadata !917}
!917 = metadata !{i32 0, i32 2, metadata !918}
!918 = metadata !{metadata !919}
!919 = metadata !{metadata !"allStubs.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!920 = metadata !{metadata !921}
!921 = metadata !{i32 0, i32 2, metadata !922}
!922 = metadata !{metadata !923}
!923 = metadata !{metadata !"allStubs.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!924 = metadata !{metadata !925}
!925 = metadata !{i32 0, i32 6, metadata !926}
!926 = metadata !{metadata !927}
!927 = metadata !{metadata !"allStubs.r.V", metadata !98, metadata !"uint7", i32 0, i32 6}
!928 = metadata !{metadata !929}
!929 = metadata !{i32 0, i32 6, metadata !930}
!930 = metadata !{metadata !931}
!931 = metadata !{metadata !"allStubs.r.V", metadata !104, metadata !"uint7", i32 0, i32 6}
!932 = metadata !{metadata !933}
!933 = metadata !{i32 0, i32 6, metadata !934}
!934 = metadata !{metadata !935}
!935 = metadata !{metadata !"allStubs.r.V", metadata !110, metadata !"uint7", i32 0, i32 6}
!936 = metadata !{metadata !937}
!937 = metadata !{i32 0, i32 6, metadata !938}
!938 = metadata !{metadata !939}
!939 = metadata !{metadata !"allStubs.r.V", metadata !116, metadata !"uint7", i32 0, i32 6}
!940 = metadata !{metadata !941}
!941 = metadata !{i32 0, i32 6, metadata !942}
!942 = metadata !{metadata !943}
!943 = metadata !{metadata !"allStubs.r.V", metadata !122, metadata !"uint7", i32 0, i32 6}
!944 = metadata !{metadata !945}
!945 = metadata !{i32 0, i32 13, metadata !946}
!946 = metadata !{metadata !947}
!947 = metadata !{metadata !"allStubs.phi.V", metadata !98, metadata !"uint14", i32 0, i32 13}
!948 = metadata !{metadata !949}
!949 = metadata !{i32 0, i32 13, metadata !950}
!950 = metadata !{metadata !951}
!951 = metadata !{metadata !"allStubs.phi.V", metadata !104, metadata !"uint14", i32 0, i32 13}
!952 = metadata !{metadata !953}
!953 = metadata !{i32 0, i32 13, metadata !954}
!954 = metadata !{metadata !955}
!955 = metadata !{metadata !"allStubs.phi.V", metadata !110, metadata !"uint14", i32 0, i32 13}
!956 = metadata !{metadata !957}
!957 = metadata !{i32 0, i32 13, metadata !958}
!958 = metadata !{metadata !959}
!959 = metadata !{metadata !"allStubs.phi.V", metadata !116, metadata !"uint14", i32 0, i32 13}
!960 = metadata !{metadata !961}
!961 = metadata !{i32 0, i32 13, metadata !962}
!962 = metadata !{metadata !963}
!963 = metadata !{metadata !"allStubs.phi.V", metadata !122, metadata !"uint14", i32 0, i32 13}
!964 = metadata !{metadata !965}
!965 = metadata !{i32 0, i32 11, metadata !966}
!966 = metadata !{metadata !967}
!967 = metadata !{metadata !"allStubs.z.V", metadata !98, metadata !"uint12", i32 0, i32 11}
!968 = metadata !{metadata !969}
!969 = metadata !{i32 0, i32 11, metadata !970}
!970 = metadata !{metadata !971}
!971 = metadata !{metadata !"allStubs.z.V", metadata !104, metadata !"uint12", i32 0, i32 11}
!972 = metadata !{metadata !973}
!973 = metadata !{i32 0, i32 11, metadata !974}
!974 = metadata !{metadata !975}
!975 = metadata !{metadata !"allStubs.z.V", metadata !110, metadata !"uint12", i32 0, i32 11}
!976 = metadata !{metadata !977}
!977 = metadata !{i32 0, i32 11, metadata !978}
!978 = metadata !{metadata !979}
!979 = metadata !{metadata !"allStubs.z.V", metadata !116, metadata !"uint12", i32 0, i32 11}
!980 = metadata !{metadata !981}
!981 = metadata !{i32 0, i32 11, metadata !982}
!982 = metadata !{metadata !983}
!983 = metadata !{metadata !"allStubs.z.V", metadata !122, metadata !"uint12", i32 0, i32 11}
!984 = metadata !{metadata !985}
!985 = metadata !{i32 0, i32 31, metadata !986}
!986 = metadata !{metadata !987}
!987 = metadata !{metadata !"nStubs", metadata !988, metadata !"int", i32 0, i32 31}
!988 = metadata !{metadata !989}
!989 = metadata !{i32 4, i32 4, i32 2}
!990 = metadata !{metadata !991}
!991 = metadata !{i32 0, i32 31, metadata !992}
!992 = metadata !{metadata !993}
!993 = metadata !{metadata !"nStubs", metadata !994, metadata !"int", i32 0, i32 31}
!994 = metadata !{metadata !995}
!995 = metadata !{i32 3, i32 3, i32 2}
!996 = metadata !{metadata !997}
!997 = metadata !{i32 0, i32 31, metadata !998}
!998 = metadata !{metadata !999}
!999 = metadata !{metadata !"nStubs", metadata !1000, metadata !"int", i32 0, i32 31}
!1000 = metadata !{metadata !1001}
!1001 = metadata !{i32 2, i32 2, i32 2}
!1002 = metadata !{metadata !1003}
!1003 = metadata !{i32 0, i32 31, metadata !1004}
!1004 = metadata !{metadata !1005}
!1005 = metadata !{metadata !"nStubs", metadata !1006, metadata !"int", i32 0, i32 31}
!1006 = metadata !{metadata !1007}
!1007 = metadata !{i32 1, i32 1, i32 2}
!1008 = metadata !{metadata !1009}
!1009 = metadata !{i32 0, i32 31, metadata !1010}
!1010 = metadata !{metadata !1011}
!1011 = metadata !{metadata !"nStubs", metadata !1012, metadata !"int", i32 0, i32 31}
!1012 = metadata !{metadata !1013}
!1013 = metadata !{i32 0, i32 0, i32 2}
!1014 = metadata !{metadata !1015}
!1015 = metadata !{i32 0, i32 2, metadata !1016}
!1016 = metadata !{metadata !1017}
!1017 = metadata !{metadata !"stubsInLayer.pt.V", metadata !98, metadata !"uint3", i32 0, i32 2}
!1018 = metadata !{metadata !1019}
!1019 = metadata !{i32 0, i32 2, metadata !1020}
!1020 = metadata !{metadata !1021}
!1021 = metadata !{metadata !"stubsInLayer.pt.V", metadata !104, metadata !"uint3", i32 0, i32 2}
!1022 = metadata !{metadata !1023}
!1023 = metadata !{i32 0, i32 2, metadata !1024}
!1024 = metadata !{metadata !1025}
!1025 = metadata !{metadata !"stubsInLayer.pt.V", metadata !110, metadata !"uint3", i32 0, i32 2}
!1026 = metadata !{metadata !1027}
!1027 = metadata !{i32 0, i32 2, metadata !1028}
!1028 = metadata !{metadata !1029}
!1029 = metadata !{metadata !"stubsInLayer.pt.V", metadata !116, metadata !"uint3", i32 0, i32 2}
!1030 = metadata !{metadata !1031}
!1031 = metadata !{i32 0, i32 2, metadata !1032}
!1032 = metadata !{metadata !1033}
!1033 = metadata !{metadata !"stubsInLayer.pt.V", metadata !122, metadata !"uint3", i32 0, i32 2}
!1034 = metadata !{metadata !1035}
!1035 = metadata !{i32 0, i32 6, metadata !1036}
!1036 = metadata !{metadata !1037}
!1037 = metadata !{metadata !"stubsInLayer.r.V", metadata !98, metadata !"uint7", i32 0, i32 6}
!1038 = metadata !{metadata !1039}
!1039 = metadata !{i32 0, i32 6, metadata !1040}
!1040 = metadata !{metadata !1041}
!1041 = metadata !{metadata !"stubsInLayer.r.V", metadata !104, metadata !"uint7", i32 0, i32 6}
!1042 = metadata !{metadata !1043}
!1043 = metadata !{i32 0, i32 6, metadata !1044}
!1044 = metadata !{metadata !1045}
!1045 = metadata !{metadata !"stubsInLayer.r.V", metadata !110, metadata !"uint7", i32 0, i32 6}
!1046 = metadata !{metadata !1047}
!1047 = metadata !{i32 0, i32 6, metadata !1048}
!1048 = metadata !{metadata !1049}
!1049 = metadata !{metadata !"stubsInLayer.r.V", metadata !116, metadata !"uint7", i32 0, i32 6}
!1050 = metadata !{metadata !1051}
!1051 = metadata !{i32 0, i32 6, metadata !1052}
!1052 = metadata !{metadata !1053}
!1053 = metadata !{metadata !"stubsInLayer.r.V", metadata !122, metadata !"uint7", i32 0, i32 6}
!1054 = metadata !{metadata !1055}
!1055 = metadata !{i32 0, i32 13, metadata !1056}
!1056 = metadata !{metadata !1057}
!1057 = metadata !{metadata !"stubsInLayer.phi.V", metadata !98, metadata !"uint14", i32 0, i32 13}
!1058 = metadata !{metadata !1059}
!1059 = metadata !{i32 0, i32 13, metadata !1060}
!1060 = metadata !{metadata !1061}
!1061 = metadata !{metadata !"stubsInLayer.phi.V", metadata !104, metadata !"uint14", i32 0, i32 13}
!1062 = metadata !{metadata !1063}
!1063 = metadata !{i32 0, i32 13, metadata !1064}
!1064 = metadata !{metadata !1065}
!1065 = metadata !{metadata !"stubsInLayer.phi.V", metadata !110, metadata !"uint14", i32 0, i32 13}
!1066 = metadata !{metadata !1067}
!1067 = metadata !{i32 0, i32 13, metadata !1068}
!1068 = metadata !{metadata !1069}
!1069 = metadata !{metadata !"stubsInLayer.phi.V", metadata !116, metadata !"uint14", i32 0, i32 13}
!1070 = metadata !{metadata !1071}
!1071 = metadata !{i32 0, i32 13, metadata !1072}
!1072 = metadata !{metadata !1073}
!1073 = metadata !{metadata !"stubsInLayer.phi.V", metadata !122, metadata !"uint14", i32 0, i32 13}
!1074 = metadata !{metadata !1075}
!1075 = metadata !{i32 0, i32 11, metadata !1076}
!1076 = metadata !{metadata !1077}
!1077 = metadata !{metadata !"stubsInLayer.z.V", metadata !98, metadata !"uint12", i32 0, i32 11}
!1078 = metadata !{metadata !1079}
!1079 = metadata !{i32 0, i32 11, metadata !1080}
!1080 = metadata !{metadata !1081}
!1081 = metadata !{metadata !"stubsInLayer.z.V", metadata !104, metadata !"uint12", i32 0, i32 11}
!1082 = metadata !{metadata !1083}
!1083 = metadata !{i32 0, i32 11, metadata !1084}
!1084 = metadata !{metadata !1085}
!1085 = metadata !{metadata !"stubsInLayer.z.V", metadata !110, metadata !"uint12", i32 0, i32 11}
!1086 = metadata !{metadata !1087}
!1087 = metadata !{i32 0, i32 11, metadata !1088}
!1088 = metadata !{metadata !1089}
!1089 = metadata !{metadata !"stubsInLayer.z.V", metadata !116, metadata !"uint12", i32 0, i32 11}
!1090 = metadata !{metadata !1091}
!1091 = metadata !{i32 0, i32 11, metadata !1092}
!1092 = metadata !{metadata !1093}
!1093 = metadata !{metadata !"stubsInLayer.z.V", metadata !122, metadata !"uint12", i32 0, i32 11}
!1094 = metadata !{metadata !1095}
!1095 = metadata !{i32 0, i32 5, metadata !1096}
!1096 = metadata !{metadata !1097}
!1097 = metadata !{metadata !"nPH1Z2.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1098 = metadata !{metadata !1099}
!1099 = metadata !{i32 0, i32 5, metadata !1100}
!1100 = metadata !{metadata !1101}
!1101 = metadata !{metadata !"nPH1Z2.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1102 = metadata !{metadata !1103}
!1103 = metadata !{i32 0, i32 5, metadata !1104}
!1104 = metadata !{metadata !1105}
!1105 = metadata !{metadata !"nPH1Z2.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1106 = metadata !{metadata !1107}
!1107 = metadata !{i32 0, i32 5, metadata !1108}
!1108 = metadata !{metadata !1109}
!1109 = metadata !{metadata !"nPH1Z2.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1110 = metadata !{metadata !1111}
!1111 = metadata !{i32 0, i32 5, metadata !1112}
!1112 = metadata !{metadata !1113}
!1113 = metadata !{metadata !"nPH1Z2.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1114 = metadata !{metadata !1115}
!1115 = metadata !{i32 0, i32 5, metadata !1116}
!1116 = metadata !{metadata !1117}
!1117 = metadata !{metadata !"nPH3Z1.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1118 = metadata !{metadata !1119}
!1119 = metadata !{i32 0, i32 5, metadata !1120}
!1120 = metadata !{metadata !1121}
!1121 = metadata !{metadata !"nPH3Z1.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1122 = metadata !{metadata !1123}
!1123 = metadata !{i32 0, i32 5, metadata !1124}
!1124 = metadata !{metadata !1125}
!1125 = metadata !{metadata !"nPH3Z1.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1126 = metadata !{metadata !1127}
!1127 = metadata !{i32 0, i32 5, metadata !1128}
!1128 = metadata !{metadata !1129}
!1129 = metadata !{metadata !"nPH3Z1.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1130 = metadata !{metadata !1131}
!1131 = metadata !{i32 0, i32 5, metadata !1132}
!1132 = metadata !{metadata !1133}
!1133 = metadata !{metadata !"nPH3Z1.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1134 = metadata !{metadata !1135}
!1135 = metadata !{i32 0, i32 5, metadata !1136}
!1136 = metadata !{metadata !1137}
!1137 = metadata !{metadata !"nPH3Z2.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1138 = metadata !{metadata !1139}
!1139 = metadata !{i32 0, i32 5, metadata !1140}
!1140 = metadata !{metadata !1141}
!1141 = metadata !{metadata !"nPH3Z2.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1142 = metadata !{metadata !1143}
!1143 = metadata !{i32 0, i32 5, metadata !1144}
!1144 = metadata !{metadata !1145}
!1145 = metadata !{metadata !"nPH3Z2.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1146 = metadata !{metadata !1147}
!1147 = metadata !{i32 0, i32 5, metadata !1148}
!1148 = metadata !{metadata !1149}
!1149 = metadata !{metadata !"nPH3Z2.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1150 = metadata !{metadata !1151}
!1151 = metadata !{i32 0, i32 5, metadata !1152}
!1152 = metadata !{metadata !1153}
!1153 = metadata !{metadata !"nPH3Z2.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1154 = metadata !{metadata !1155}
!1155 = metadata !{i32 0, i32 5, metadata !1156}
!1156 = metadata !{metadata !1157}
!1157 = metadata !{metadata !"nPH4Z1.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1158 = metadata !{metadata !1159}
!1159 = metadata !{i32 0, i32 5, metadata !1160}
!1160 = metadata !{metadata !1161}
!1161 = metadata !{metadata !"nPH4Z1.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1162 = metadata !{metadata !1163}
!1163 = metadata !{i32 0, i32 5, metadata !1164}
!1164 = metadata !{metadata !1165}
!1165 = metadata !{metadata !"nPH4Z1.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1166 = metadata !{metadata !1167}
!1167 = metadata !{i32 0, i32 5, metadata !1168}
!1168 = metadata !{metadata !1169}
!1169 = metadata !{metadata !"nPH4Z1.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1170 = metadata !{metadata !1171}
!1171 = metadata !{i32 0, i32 5, metadata !1172}
!1172 = metadata !{metadata !1173}
!1173 = metadata !{metadata !"nPH4Z1.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1174 = metadata !{metadata !1175}
!1175 = metadata !{i32 0, i32 5, metadata !1176}
!1176 = metadata !{metadata !1177}
!1177 = metadata !{metadata !"nPH2Z1.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1178 = metadata !{metadata !1179}
!1179 = metadata !{i32 0, i32 5, metadata !1180}
!1180 = metadata !{metadata !1181}
!1181 = metadata !{metadata !"nPH2Z1.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1182 = metadata !{metadata !1183}
!1183 = metadata !{i32 0, i32 5, metadata !1184}
!1184 = metadata !{metadata !1185}
!1185 = metadata !{metadata !"nPH2Z1.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1186 = metadata !{metadata !1187}
!1187 = metadata !{i32 0, i32 5, metadata !1188}
!1188 = metadata !{metadata !1189}
!1189 = metadata !{metadata !"nPH2Z1.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1190 = metadata !{metadata !1191}
!1191 = metadata !{i32 0, i32 5, metadata !1192}
!1192 = metadata !{metadata !1193}
!1193 = metadata !{metadata !"nPH2Z1.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1194 = metadata !{metadata !1195}
!1195 = metadata !{i32 0, i32 5, metadata !1196}
!1196 = metadata !{metadata !1197}
!1197 = metadata !{metadata !"nPH4Z2.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1198 = metadata !{metadata !1199}
!1199 = metadata !{i32 0, i32 5, metadata !1200}
!1200 = metadata !{metadata !1201}
!1201 = metadata !{metadata !"nPH4Z2.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1202 = metadata !{metadata !1203}
!1203 = metadata !{i32 0, i32 5, metadata !1204}
!1204 = metadata !{metadata !1205}
!1205 = metadata !{metadata !"nPH4Z2.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1206 = metadata !{metadata !1207}
!1207 = metadata !{i32 0, i32 5, metadata !1208}
!1208 = metadata !{metadata !1209}
!1209 = metadata !{metadata !"nPH4Z2.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1210 = metadata !{metadata !1211}
!1211 = metadata !{i32 0, i32 5, metadata !1212}
!1212 = metadata !{metadata !1213}
!1213 = metadata !{metadata !"nPH4Z2.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1214 = metadata !{metadata !1215}
!1215 = metadata !{i32 0, i32 5, metadata !1216}
!1216 = metadata !{metadata !1217}
!1217 = metadata !{metadata !"nPH1Z1.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1218 = metadata !{metadata !1219}
!1219 = metadata !{i32 0, i32 5, metadata !1220}
!1220 = metadata !{metadata !1221}
!1221 = metadata !{metadata !"nPH1Z1.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1222 = metadata !{metadata !1223}
!1223 = metadata !{i32 0, i32 5, metadata !1224}
!1224 = metadata !{metadata !1225}
!1225 = metadata !{metadata !"nPH1Z1.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1226 = metadata !{metadata !1227}
!1227 = metadata !{i32 0, i32 5, metadata !1228}
!1228 = metadata !{metadata !1229}
!1229 = metadata !{metadata !"nPH1Z1.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1230 = metadata !{metadata !1231}
!1231 = metadata !{i32 0, i32 5, metadata !1232}
!1232 = metadata !{metadata !1233}
!1233 = metadata !{metadata !"nPH1Z1.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
!1234 = metadata !{metadata !1235}
!1235 = metadata !{i32 0, i32 5, metadata !1236}
!1236 = metadata !{metadata !1237}
!1237 = metadata !{metadata !"nPH2Z2.V", metadata !988, metadata !"uint6", i32 0, i32 5}
!1238 = metadata !{metadata !1239}
!1239 = metadata !{i32 0, i32 5, metadata !1240}
!1240 = metadata !{metadata !1241}
!1241 = metadata !{metadata !"nPH2Z2.V", metadata !994, metadata !"uint6", i32 0, i32 5}
!1242 = metadata !{metadata !1243}
!1243 = metadata !{i32 0, i32 5, metadata !1244}
!1244 = metadata !{metadata !1245}
!1245 = metadata !{metadata !"nPH2Z2.V", metadata !1000, metadata !"uint6", i32 0, i32 5}
!1246 = metadata !{metadata !1247}
!1247 = metadata !{i32 0, i32 5, metadata !1248}
!1248 = metadata !{metadata !1249}
!1249 = metadata !{metadata !"nPH2Z2.V", metadata !1006, metadata !"uint6", i32 0, i32 5}
!1250 = metadata !{metadata !1251}
!1251 = metadata !{i32 0, i32 5, metadata !1252}
!1252 = metadata !{metadata !1253}
!1253 = metadata !{metadata !"nPH2Z2.V", metadata !1012, metadata !"uint6", i32 0, i32 5}
