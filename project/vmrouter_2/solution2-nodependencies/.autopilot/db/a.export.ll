; ModuleID = '/mnt/scratch/djc448/firmware-hls/project/vmrouter_2/solution2-nodependencies/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@llvm_global_ctors_1 = appending global [2 x void ()*] [void ()* @_GLOBAL__I_a, void ()* @_GLOBAL__I_a12]
@llvm_global_ctors_0 = appending global [2 x i32] [i32 65535, i32 65535]
@VMRouterDispatcher_s = internal unnamed_addr constant [19 x i8] c"VMRouterDispatcher\00"
@p_str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str = private unnamed_addr constant [9 x i8] c"STUBLOOP\00", align 1

declare i9 @llvm.part.select.i9(i9, i32, i32) nounwind readnone

declare i36 @llvm.part.select.i36(i36, i32, i32) nounwind readnone

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

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

define weak i32 @_ssdm_op_Read.ap_auto.i32P(i32*) {
entry:
  %empty = load i32* %0
  ret i32 %empty
}

define weak i32 @_ssdm_op_Read.ap_auto.i32(i32) {
entry:
  ret i32 %0
}

define weak i10 @_ssdm_op_Read.ap_auto.i10(i10) {
entry:
  ret i10 %0
}

declare i9 @_ssdm_op_PartSelect.i9.i10.i32.i32(i10, i32, i32) nounwind readnone

declare i6 @_ssdm_op_PartSelect.i6.i7.i32.i32(i7, i32, i32) nounwind readnone

declare i6 @_ssdm_op_PartSelect.i6.i10.i32.i32(i10, i32, i32) nounwind readnone

define weak i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36, i32, i32) nounwind readnone {
entry:
  %empty = call i36 @llvm.part.select.i36(i36 %0, i32 %1, i32 %2)
  %empty_7 = trunc i36 %empty to i5
  ret i5 %empty_7
}

define weak i4 @_ssdm_op_PartSelect.i4.i36.i32.i32(i36, i32, i32) nounwind readnone {
entry:
  %empty = call i36 @llvm.part.select.i36(i36 %0, i32 %1, i32 %2)
  %empty_8 = trunc i36 %empty to i4
  ret i4 %empty_8
}

define weak i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9, i32, i32) nounwind readnone {
entry:
  %empty = call i9 @llvm.part.select.i9(i9 %0, i32 %1, i32 %2)
  %empty_9 = trunc i9 %empty to i3
  ret i3 %empty_9
}

define weak i3 @_ssdm_op_PartSelect.i3.i36.i32.i32(i36, i32, i32) nounwind readnone {
entry:
  %empty = call i36 @llvm.part.select.i36(i36 %0, i32 %1, i32 %2)
  %empty_10 = trunc i36 %empty to i3
  ret i3 %empty_10
}

define weak i2 @_ssdm_op_PartSelect.i2.i36.i32.i32(i36, i32, i32) nounwind readnone {
entry:
  %empty = call i36 @llvm.part.select.i36(i36 %0, i32 %1, i32 %2)
  %empty_11 = trunc i36 %empty to i2
  ret i2 %empty_11
}

define weak i36 @_ssdm_op_Mux.ap_auto.5i36.i64(i36, i36, i36, i36, i36, i64) {
entry:
  switch i64 %5, label %case4 [
    i64 0, label %case0
    i64 1, label %case1
    i64 2, label %case2
    i64 3, label %case3
  ]

case0:                                            ; preds = %case4, %case3, %case2, %case1, %entry
  %merge = phi i36 [ %0, %entry ], [ %1, %case1 ], [ %2, %case2 ], [ %3, %case3 ], [ %4, %case4 ]
  ret i36 %merge

case1:                                            ; preds = %entry
  br label %case0

case2:                                            ; preds = %entry
  br label %case0

case3:                                            ; preds = %entry
  br label %case0

case4:                                            ; preds = %entry
  br label %case0
}

define weak i1 @_ssdm_op_BitSelect.i1.i7.i32(i7, i32) nounwind readnone {
entry:
  %empty = trunc i32 %1 to i7
  %empty_12 = shl i7 1, %empty
  %empty_13 = and i7 %0, %empty_12
  %empty_14 = icmp ne i7 %empty_13, 0
  ret i1 %empty_14
}

define weak i1 @_ssdm_op_BitSelect.i1.i36.i32(i36, i32) nounwind readnone {
entry:
  %empty = zext i32 %1 to i36
  %empty_15 = shl i36 1, %empty
  %empty_16 = and i36 %0, %empty_15
  %empty_17 = icmp ne i36 %empty_16, 0
  ret i1 %empty_17
}

define weak i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6, i5, i3, i4) nounwind readnone {
entry:
  %empty = zext i3 %2 to i7
  %empty_18 = zext i4 %3 to i7
  %empty_19 = shl i7 %empty, 4
  %empty_20 = or i7 %empty_19, %empty_18
  %empty_21 = zext i5 %1 to i12
  %empty_22 = zext i7 %empty_20 to i12
  %empty_23 = shl i12 %empty_21, 7
  %empty_24 = or i12 %empty_23, %empty_22
  %empty_25 = zext i6 %0 to i18
  %empty_26 = zext i12 %empty_24 to i18
  %empty_27 = shl i18 %empty_25, 12
  %empty_28 = or i18 %empty_27, %empty_26
  ret i18 %empty_28
}

declare void @_ssdm_SpecDependence(...) nounwind

declare void @_GLOBAL__I_a12() nounwind section ".text.startup"

declare void @_GLOBAL__I_a() nounwind section ".text.startup"

define void @VMRouterDispatcher([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i32* %curnStubs_0, i32* %curnStubs_1, i32* %curnStubs_2, i32* %curnStubs_3, i32* %curnStubs_4, i6* %curnPH1Z1_0_V, i6* %curnPH1Z1_1_V, i6* %curnPH1Z1_2_V, i6* %curnPH1Z1_3_V, i6* %curnPH1Z1_4_V, i6* %curnPH2Z1_0_V, i6* %curnPH2Z1_1_V, i6* %curnPH2Z1_2_V, i6* %curnPH2Z1_3_V, i6* %curnPH2Z1_4_V, i6* %curnPH3Z1_0_V, i6* %curnPH3Z1_1_V, i6* %curnPH3Z1_2_V, i6* %curnPH3Z1_3_V, i6* %curnPH3Z1_4_V, i6* %curnPH4Z1_0_V, i6* %curnPH4Z1_1_V, i6* %curnPH4Z1_2_V, i6* %curnPH4Z1_3_V, i6* %curnPH4Z1_4_V, i6* %curnPH1Z2_0_V, i6* %curnPH1Z2_1_V, i6* %curnPH1Z2_2_V, i6* %curnPH1Z2_3_V, i6* %curnPH1Z2_4_V, i6* %curnPH2Z2_0_V, i6* %curnPH2Z2_1_V, i6* %curnPH2Z2_2_V, i6* %curnPH2Z2_3_V, i6* %curnPH2Z2_4_V, i6* %curnPH3Z2_0_V, i6* %curnPH3Z2_1_V, i6* %curnPH3Z2_2_V, i6* %curnPH3Z2_3_V, i6* %curnPH3Z2_4_V, i6* %curnPH4Z2_0_V, i6* %curnPH4Z2_1_V, i6* %curnPH4Z2_2_V, i6* %curnPH4Z2_3_V, i6* %curnPH4Z2_4_V) {
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z2_4_V), !map !115
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z2_3_V), !map !121
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z2_2_V), !map !127
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z2_1_V), !map !133
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z2_0_V), !map !139
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z2_4_V), !map !145
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z2_3_V), !map !149
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z2_2_V), !map !153
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z2_1_V), !map !157
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z2_0_V), !map !161
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z2_4_V), !map !165
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z2_3_V), !map !169
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z2_2_V), !map !173
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z2_1_V), !map !177
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z2_0_V), !map !181
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z2_4_V), !map !185
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z2_3_V), !map !189
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z2_2_V), !map !193
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z2_1_V), !map !197
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z2_0_V), !map !201
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z1_4_V), !map !205
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z1_3_V), !map !209
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z1_2_V), !map !213
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z1_1_V), !map !217
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH4Z1_0_V), !map !221
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z1_4_V), !map !225
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z1_3_V), !map !229
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z1_2_V), !map !233
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z1_1_V), !map !237
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH3Z1_0_V), !map !241
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z1_4_V), !map !245
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z1_3_V), !map !249
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z1_2_V), !map !253
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z1_1_V), !map !257
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH2Z1_0_V), !map !261
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z1_4_V), !map !265
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z1_3_V), !map !269
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z1_2_V), !map !273
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z1_1_V), !map !277
  call void (...)* @_ssdm_op_SpecBitsMap(i6* %curnPH1Z1_0_V), !map !281
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %curnStubs_4), !map !285
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %curnStubs_3), !map !289
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %curnStubs_2), !map !293
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %curnStubs_1), !map !297
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %curnStubs_0), !map !301
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z2_4_data_V), !map !305
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z2_3_data_V), !map !311
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z2_2_data_V), !map !317
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z2_1_data_V), !map !323
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z2_0_data_V), !map !329
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z2_4_data_V), !map !335
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z2_3_data_V), !map !339
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z2_2_data_V), !map !343
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z2_1_data_V), !map !347
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z2_0_data_V), !map !351
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z2_4_data_V), !map !355
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z2_3_data_V), !map !359
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z2_2_data_V), !map !363
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z2_1_data_V), !map !367
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z2_0_data_V), !map !371
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z2_4_data_V), !map !375
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z2_3_data_V), !map !379
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z2_2_data_V), !map !383
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z2_1_data_V), !map !387
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z2_0_data_V), !map !391
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z1_4_data_V), !map !395
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z1_3_data_V), !map !399
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z1_2_data_V), !map !403
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z1_1_data_V), !map !407
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH4Z1_0_data_V), !map !411
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z1_4_data_V), !map !415
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z1_3_data_V), !map !419
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z1_2_data_V), !map !423
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z1_1_data_V), !map !427
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH3Z1_0_data_V), !map !431
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z1_4_data_V), !map !435
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z1_3_data_V), !map !439
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z1_2_data_V), !map !443
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z1_1_data_V), !map !447
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH2Z1_0_data_V), !map !451
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z1_4_data_V), !map !455
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z1_3_data_V), !map !459
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z1_2_data_V), !map !463
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z1_1_data_V), !map !467
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i18]* %curvmStubsPH1Z1_0_data_V), !map !471
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curAllStubs_4_data_V), !map !475
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curAllStubs_3_data_V), !map !479
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curAllStubs_2_data_V), !map !483
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curAllStubs_1_data_V), !map !487
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curAllStubs_0_data_V), !map !491
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curStubsInLayer_4_data_V), !map !495
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curStubsInLayer_3_data_V), !map !499
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curStubsInLayer_2_data_V), !map !503
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curStubsInLayer_1_data_V), !map !507
  call void (...)* @_ssdm_op_SpecBitsMap([64 x i36]* %curStubsInLayer_0_data_V), !map !511
  call void (...)* @_ssdm_op_SpecTopModule([19 x i8]* @VMRouterDispatcher_s) nounwind
  %curnStubs_0_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %curnStubs_0)
  %curnPH1Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z1_0_V)
  %curnPH2Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z1_0_V)
  %curnPH3Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z1_0_V)
  %curnPH4Z1_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z1_0_V)
  %curnPH1Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z2_0_V)
  %curnPH2Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z2_0_V)
  %curnPH3Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z2_0_V)
  %curnPH4Z2_0_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z2_0_V)
  %tmp = call fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, i10 0, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, i10 0, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, i10 0, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, i10 0, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, i10 0, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, i10 0, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, i10 0, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, i10 0, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, i10 0, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i10 0, i32 %curnStubs_0_read, i6 %curnPH1Z1_0_V_read, i6 %curnPH2Z1_0_V_read, i6 %curnPH3Z1_0_V_read, i6 %curnPH4Z1_0_V_read, i6 %curnPH1Z2_0_V_read, i6 %curnPH2Z2_0_V_read, i6 %curnPH3Z2_0_V_read, i6 %curnPH4Z2_0_V_read)
  %curnPH1Z1_V_addr34_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 0
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z1_0_V, i6 %curnPH1Z1_V_addr34_r)
  %curnPH2Z1_V_addr37_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z1_0_V, i6 %curnPH2Z1_V_addr37_r)
  %curnPH3Z1_V_addr40_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 2
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z1_0_V, i6 %curnPH3Z1_V_addr40_r)
  %curnPH4Z1_V_addr43_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 3
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z1_0_V, i6 %curnPH4Z1_V_addr43_r)
  %curnPH1Z2_V_addr46_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 4
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z2_0_V, i6 %curnPH1Z2_V_addr46_r)
  %curnPH2Z2_V_addr49_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 5
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z2_0_V, i6 %curnPH2Z2_V_addr49_r)
  %curnPH3Z2_V_addr52_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 6
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z2_0_V, i6 %curnPH3Z2_V_addr52_r)
  %curnPH4Z2_V_addr55_r = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp, 7
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z2_0_V, i6 %curnPH4Z2_V_addr55_r)
  %curnStubs_1_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %curnStubs_1)
  %curnPH1Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z1_1_V)
  %curnPH2Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z1_1_V)
  %curnPH3Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z1_1_V)
  %curnPH4Z1_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z1_1_V)
  %curnPH1Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z2_1_V)
  %curnPH2Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z2_1_V)
  %curnPH3Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z2_1_V)
  %curnPH4Z2_1_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z2_1_V)
  %tmp_1 = call fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, i10 64, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, i10 64, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, i10 64, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, i10 64, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, i10 64, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, i10 64, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, i10 64, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, i10 64, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, i10 64, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i10 64, i32 %curnStubs_1_read, i6 %curnPH1Z1_1_V_read, i6 %curnPH2Z1_1_V_read, i6 %curnPH3Z1_1_V_read, i6 %curnPH4Z1_1_V_read, i6 %curnPH1Z2_1_V_read, i6 %curnPH2Z2_1_V_read, i6 %curnPH3Z2_1_V_read, i6 %curnPH4Z2_1_V_read)
  %curnPH1Z1_V_addr34_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 0
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z1_1_V, i6 %curnPH1Z1_V_addr34_r_1)
  %curnPH2Z1_V_addr37_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z1_1_V, i6 %curnPH2Z1_V_addr37_r_1)
  %curnPH3Z1_V_addr40_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 2
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z1_1_V, i6 %curnPH3Z1_V_addr40_r_1)
  %curnPH4Z1_V_addr43_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 3
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z1_1_V, i6 %curnPH4Z1_V_addr43_r_1)
  %curnPH1Z2_V_addr46_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 4
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z2_1_V, i6 %curnPH1Z2_V_addr46_r_1)
  %curnPH2Z2_V_addr49_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 5
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z2_1_V, i6 %curnPH2Z2_V_addr49_r_1)
  %curnPH3Z2_V_addr52_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 6
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z2_1_V, i6 %curnPH3Z2_V_addr52_r_1)
  %curnPH4Z2_V_addr55_r_1 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_1, 7
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z2_1_V, i6 %curnPH4Z2_V_addr55_r_1)
  %curnStubs_2_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %curnStubs_2)
  %curnPH1Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z1_2_V)
  %curnPH2Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z1_2_V)
  %curnPH3Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z1_2_V)
  %curnPH4Z1_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z1_2_V)
  %curnPH1Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z2_2_V)
  %curnPH2Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z2_2_V)
  %curnPH3Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z2_2_V)
  %curnPH4Z2_2_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z2_2_V)
  %tmp_2 = call fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, i10 128, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, i10 128, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, i10 128, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, i10 128, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, i10 128, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, i10 128, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, i10 128, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, i10 128, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, i10 128, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i10 128, i32 %curnStubs_2_read, i6 %curnPH1Z1_2_V_read, i6 %curnPH2Z1_2_V_read, i6 %curnPH3Z1_2_V_read, i6 %curnPH4Z1_2_V_read, i6 %curnPH1Z2_2_V_read, i6 %curnPH2Z2_2_V_read, i6 %curnPH3Z2_2_V_read, i6 %curnPH4Z2_2_V_read)
  %curnPH1Z1_V_addr34_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 0
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z1_2_V, i6 %curnPH1Z1_V_addr34_r_2)
  %curnPH2Z1_V_addr37_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z1_2_V, i6 %curnPH2Z1_V_addr37_r_2)
  %curnPH3Z1_V_addr40_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 2
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z1_2_V, i6 %curnPH3Z1_V_addr40_r_2)
  %curnPH4Z1_V_addr43_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 3
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z1_2_V, i6 %curnPH4Z1_V_addr43_r_2)
  %curnPH1Z2_V_addr46_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 4
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z2_2_V, i6 %curnPH1Z2_V_addr46_r_2)
  %curnPH2Z2_V_addr49_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 5
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z2_2_V, i6 %curnPH2Z2_V_addr49_r_2)
  %curnPH3Z2_V_addr52_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 6
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z2_2_V, i6 %curnPH3Z2_V_addr52_r_2)
  %curnPH4Z2_V_addr55_r_2 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_2, 7
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z2_2_V, i6 %curnPH4Z2_V_addr55_r_2)
  %curnStubs_3_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %curnStubs_3)
  %curnPH1Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z1_3_V)
  %curnPH2Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z1_3_V)
  %curnPH3Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z1_3_V)
  %curnPH4Z1_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z1_3_V)
  %curnPH1Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z2_3_V)
  %curnPH2Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z2_3_V)
  %curnPH3Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z2_3_V)
  %curnPH4Z2_3_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z2_3_V)
  %tmp_3 = call fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, i10 192, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, i10 192, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, i10 192, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, i10 192, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, i10 192, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, i10 192, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, i10 192, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, i10 192, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, i10 192, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i10 192, i32 %curnStubs_3_read, i6 %curnPH1Z1_3_V_read, i6 %curnPH2Z1_3_V_read, i6 %curnPH3Z1_3_V_read, i6 %curnPH4Z1_3_V_read, i6 %curnPH1Z2_3_V_read, i6 %curnPH2Z2_3_V_read, i6 %curnPH3Z2_3_V_read, i6 %curnPH4Z2_3_V_read)
  %curnPH1Z1_V_addr34_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 0
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z1_3_V, i6 %curnPH1Z1_V_addr34_r_3)
  %curnPH2Z1_V_addr37_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z1_3_V, i6 %curnPH2Z1_V_addr37_r_3)
  %curnPH3Z1_V_addr40_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 2
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z1_3_V, i6 %curnPH3Z1_V_addr40_r_3)
  %curnPH4Z1_V_addr43_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 3
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z1_3_V, i6 %curnPH4Z1_V_addr43_r_3)
  %curnPH1Z2_V_addr46_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 4
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z2_3_V, i6 %curnPH1Z2_V_addr46_r_3)
  %curnPH2Z2_V_addr49_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 5
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z2_3_V, i6 %curnPH2Z2_V_addr49_r_3)
  %curnPH3Z2_V_addr52_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 6
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z2_3_V, i6 %curnPH3Z2_V_addr52_r_3)
  %curnPH4Z2_V_addr55_r_3 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_3, 7
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z2_3_V, i6 %curnPH4Z2_V_addr55_r_3)
  %curnStubs_4_read = call i32 @_ssdm_op_Read.ap_auto.i32P(i32* %curnStubs_4)
  %curnPH1Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z1_4_V)
  %curnPH2Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z1_4_V)
  %curnPH3Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z1_4_V)
  %curnPH4Z1_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z1_4_V)
  %curnPH1Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH1Z2_4_V)
  %curnPH2Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH2Z2_4_V)
  %curnPH3Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH3Z2_4_V)
  %curnPH4Z2_4_V_read = call i6 @_ssdm_op_Read.ap_auto.i6P(i6* %curnPH4Z2_4_V)
  %tmp_4 = call fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* %curStubsInLayer_0_data_V, [64 x i36]* %curStubsInLayer_1_data_V, [64 x i36]* %curStubsInLayer_2_data_V, [64 x i36]* %curStubsInLayer_3_data_V, [64 x i36]* %curStubsInLayer_4_data_V, i10 256, [64 x i36]* %curAllStubs_0_data_V, [64 x i36]* %curAllStubs_1_data_V, [64 x i36]* %curAllStubs_2_data_V, [64 x i36]* %curAllStubs_3_data_V, [64 x i36]* %curAllStubs_4_data_V, i10 256, [64 x i18]* %curvmStubsPH1Z1_0_data_V, [64 x i18]* %curvmStubsPH1Z1_1_data_V, [64 x i18]* %curvmStubsPH1Z1_2_data_V, [64 x i18]* %curvmStubsPH1Z1_3_data_V, [64 x i18]* %curvmStubsPH1Z1_4_data_V, i10 256, [64 x i18]* %curvmStubsPH2Z1_0_data_V, [64 x i18]* %curvmStubsPH2Z1_1_data_V, [64 x i18]* %curvmStubsPH2Z1_2_data_V, [64 x i18]* %curvmStubsPH2Z1_3_data_V, [64 x i18]* %curvmStubsPH2Z1_4_data_V, i10 256, [64 x i18]* %curvmStubsPH3Z1_0_data_V, [64 x i18]* %curvmStubsPH3Z1_1_data_V, [64 x i18]* %curvmStubsPH3Z1_2_data_V, [64 x i18]* %curvmStubsPH3Z1_3_data_V, [64 x i18]* %curvmStubsPH3Z1_4_data_V, i10 256, [64 x i18]* %curvmStubsPH4Z1_0_data_V, [64 x i18]* %curvmStubsPH4Z1_1_data_V, [64 x i18]* %curvmStubsPH4Z1_2_data_V, [64 x i18]* %curvmStubsPH4Z1_3_data_V, [64 x i18]* %curvmStubsPH4Z1_4_data_V, i10 256, [64 x i18]* %curvmStubsPH1Z2_0_data_V, [64 x i18]* %curvmStubsPH1Z2_1_data_V, [64 x i18]* %curvmStubsPH1Z2_2_data_V, [64 x i18]* %curvmStubsPH1Z2_3_data_V, [64 x i18]* %curvmStubsPH1Z2_4_data_V, i10 256, [64 x i18]* %curvmStubsPH2Z2_0_data_V, [64 x i18]* %curvmStubsPH2Z2_1_data_V, [64 x i18]* %curvmStubsPH2Z2_2_data_V, [64 x i18]* %curvmStubsPH2Z2_3_data_V, [64 x i18]* %curvmStubsPH2Z2_4_data_V, i10 256, [64 x i18]* %curvmStubsPH3Z2_0_data_V, [64 x i18]* %curvmStubsPH3Z2_1_data_V, [64 x i18]* %curvmStubsPH3Z2_2_data_V, [64 x i18]* %curvmStubsPH3Z2_3_data_V, [64 x i18]* %curvmStubsPH3Z2_4_data_V, i10 256, [64 x i18]* %curvmStubsPH4Z2_0_data_V, [64 x i18]* %curvmStubsPH4Z2_1_data_V, [64 x i18]* %curvmStubsPH4Z2_2_data_V, [64 x i18]* %curvmStubsPH4Z2_3_data_V, [64 x i18]* %curvmStubsPH4Z2_4_data_V, i10 256, i32 %curnStubs_4_read, i6 %curnPH1Z1_4_V_read, i6 %curnPH2Z1_4_V_read, i6 %curnPH3Z1_4_V_read, i6 %curnPH4Z1_4_V_read, i6 %curnPH1Z2_4_V_read, i6 %curnPH2Z2_4_V_read, i6 %curnPH3Z2_4_V_read, i6 %curnPH4Z2_4_V_read)
  %curnPH1Z1_V_addr34_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 0
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z1_4_V, i6 %curnPH1Z1_V_addr34_r_4)
  %curnPH2Z1_V_addr37_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 1
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z1_4_V, i6 %curnPH2Z1_V_addr37_r_4)
  %curnPH3Z1_V_addr40_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 2
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z1_4_V, i6 %curnPH3Z1_V_addr40_r_4)
  %curnPH4Z1_V_addr43_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 3
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z1_4_V, i6 %curnPH4Z1_V_addr43_r_4)
  %curnPH1Z2_V_addr46_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 4
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH1Z2_4_V, i6 %curnPH1Z2_V_addr46_r_4)
  %curnPH2Z2_V_addr49_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 5
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH2Z2_4_V, i6 %curnPH2Z2_V_addr49_r_4)
  %curnPH3Z2_V_addr52_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 6
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH3Z2_4_V, i6 %curnPH3Z2_V_addr52_r_4)
  %curnPH4Z2_V_addr55_r_4 = extractvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %tmp_4, 7
  call void @_ssdm_op_Write.ap_auto.i6P(i6* %curnPH4Z2_4_V, i6 %curnPH4Z2_V_addr55_r_4)
  ret void
}

define internal fastcc { i6, i6, i6, i6, i6, i6, i6, i6 } @VMRouter([64 x i36]* nocapture %stubsInLayer_0_data, [64 x i36]* nocapture %stubsInLayer_1_data, [64 x i36]* nocapture %stubsInLayer_2_data, [64 x i36]* nocapture %stubsInLayer_3_data, [64 x i36]* nocapture %stubsInLayer_4_data, i10 %tmp_1, [64 x i36]* nocapture %allStubs_0_data_V, [64 x i36]* nocapture %allStubs_1_data_V, [64 x i36]* nocapture %allStubs_2_data_V, [64 x i36]* nocapture %allStubs_3_data_V, [64 x i36]* nocapture %allStubs_4_data_V, i10 %tmp_11, [64 x i18]* nocapture %vmStubsPH1Z1_0_data, [64 x i18]* nocapture %vmStubsPH1Z1_1_data, [64 x i18]* nocapture %vmStubsPH1Z1_2_data, [64 x i18]* nocapture %vmStubsPH1Z1_3_data, [64 x i18]* nocapture %vmStubsPH1Z1_4_data, i10 %tmp_12, [64 x i18]* nocapture %vmStubsPH2Z1_0_data, [64 x i18]* nocapture %vmStubsPH2Z1_1_data, [64 x i18]* nocapture %vmStubsPH2Z1_2_data, [64 x i18]* nocapture %vmStubsPH2Z1_3_data, [64 x i18]* nocapture %vmStubsPH2Z1_4_data, i10 %tmp_13, [64 x i18]* nocapture %vmStubsPH3Z1_0_data, [64 x i18]* nocapture %vmStubsPH3Z1_1_data, [64 x i18]* nocapture %vmStubsPH3Z1_2_data, [64 x i18]* nocapture %vmStubsPH3Z1_3_data, [64 x i18]* nocapture %vmStubsPH3Z1_4_data, i10 %tmp_14, [64 x i18]* nocapture %vmStubsPH4Z1_0_data, [64 x i18]* nocapture %vmStubsPH4Z1_1_data, [64 x i18]* nocapture %vmStubsPH4Z1_2_data, [64 x i18]* nocapture %vmStubsPH4Z1_3_data, [64 x i18]* nocapture %vmStubsPH4Z1_4_data, i10 %tmp_15, [64 x i18]* nocapture %vmStubsPH1Z2_0_data, [64 x i18]* nocapture %vmStubsPH1Z2_1_data, [64 x i18]* nocapture %vmStubsPH1Z2_2_data, [64 x i18]* nocapture %vmStubsPH1Z2_3_data, [64 x i18]* nocapture %vmStubsPH1Z2_4_data, i10 %tmp_16, [64 x i18]* nocapture %vmStubsPH2Z2_0_data, [64 x i18]* nocapture %vmStubsPH2Z2_1_data, [64 x i18]* nocapture %vmStubsPH2Z2_2_data, [64 x i18]* nocapture %vmStubsPH2Z2_3_data, [64 x i18]* nocapture %vmStubsPH2Z2_4_data, i10 %tmp_17, [64 x i18]* nocapture %vmStubsPH3Z2_0_data, [64 x i18]* nocapture %vmStubsPH3Z2_1_data, [64 x i18]* nocapture %vmStubsPH3Z2_2_data, [64 x i18]* nocapture %vmStubsPH3Z2_3_data, [64 x i18]* nocapture %vmStubsPH3Z2_4_data, i10 %tmp_18, [64 x i18]* nocapture %vmStubsPH4Z2_0_data, [64 x i18]* nocapture %vmStubsPH4Z2_1_data, [64 x i18]* nocapture %vmStubsPH4Z2_2_data, [64 x i18]* nocapture %vmStubsPH4Z2_3_data, [64 x i18]* nocapture %vmStubsPH4Z2_4_data, i10 %tmp_19, i32 %nStubs, i6 %nPH1Z1_V_read, i6 %nPH2Z1_V_read, i6 %nPH3Z1_V_read, i6 %nPH4Z1_V_read, i6 %nPH1Z2_V_read, i6 %nPH2Z2_V_read, i6 %nPH3Z2_V_read, i6 %nPH4Z2_V_read) {
  %nPH4Z2_V = alloca i6
  %nPH3Z2_V = alloca i6
  %nPH2Z2_V = alloca i6
  %nPH1Z2_V = alloca i6
  %nPH4Z1_V = alloca i6
  %nPH3Z1_V = alloca i6
  %nPH2Z1_V = alloca i6
  %nPH1Z1_V = alloca i6
  %nPH4Z2_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH4Z2_V_read)
  %nPH3Z2_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH3Z2_V_read)
  %nPH2Z2_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH2Z2_V_read)
  %nPH1Z2_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH1Z2_V_read)
  %nPH4Z1_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH4Z1_V_read)
  %nPH3Z1_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH3Z1_V_read)
  %nPH2Z1_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH2Z1_V_read)
  %nPH1Z1_V_read_1 = call i6 @_ssdm_op_Read.ap_auto.i6(i6 %nPH1Z1_V_read)
  %nStubs_read = call i32 @_ssdm_op_Read.ap_auto.i32(i32 %nStubs)
  %tmp_19_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_19)
  %tmp_18_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_18)
  %tmp_17_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_17)
  %tmp_16_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_16)
  %tmp_15_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_15)
  %tmp_14_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_14)
  %tmp_13_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_13)
  %tmp_12_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_12)
  %tmp_11_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_11)
  %tmp_1_read = call i10 @_ssdm_op_Read.ap_auto.i10(i10 %tmp_1)
  %tmp = trunc i10 %tmp_1_read to i6
  %tmp_2 = trunc i10 %tmp_11_read to i6
  %tmp_3 = trunc i10 %tmp_16_read to i6
  %tmp_5 = trunc i10 %tmp_17_read to i6
  %tmp_6 = trunc i10 %tmp_18_read to i6
  %tmp_7 = trunc i10 %tmp_19_read to i6
  %tmp_8 = trunc i10 %tmp_12_read to i6
  %tmp_9 = trunc i10 %tmp_13_read to i6
  %tmp_10 = trunc i10 %tmp_14_read to i6
  %tmp_20 = trunc i10 %tmp_15_read to i6
  %tmp_24 = trunc i10 %tmp_1_read to i9
  %tmp_39 = trunc i10 %tmp_11_read to i9
  %tmp_40 = trunc i10 %tmp_16_read to i9
  %tmp_41 = trunc i10 %tmp_17_read to i9
  %tmp_42 = trunc i10 %tmp_18_read to i9
  %tmp_43 = trunc i10 %tmp_19_read to i9
  %tmp_44 = trunc i10 %tmp_12_read to i9
  %tmp_45 = trunc i10 %tmp_13_read to i9
  %tmp_46 = trunc i10 %tmp_14_read to i9
  %tmp_47 = trunc i10 %tmp_15_read to i9
  store i6 %nPH1Z1_V_read_1, i6* %nPH1Z1_V
  store i6 %nPH2Z1_V_read_1, i6* %nPH2Z1_V
  store i6 %nPH3Z1_V_read_1, i6* %nPH3Z1_V
  store i6 %nPH4Z1_V_read_1, i6* %nPH4Z1_V
  store i6 %nPH1Z2_V_read_1, i6* %nPH1Z2_V
  store i6 %nPH2Z2_V_read_1, i6* %nPH2Z2_V
  store i6 %nPH3Z2_V_read_1, i6* %nPH3Z2_V
  store i6 %nPH4Z2_V_read_1, i6* %nPH4Z2_V
  br label %1

; <label>:1                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge, %0
  %p_0 = phi i6 [ 0, %0 ], [ %index_V, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge ]
  %i = phi i7 [ 0, %0 ], [ %i_1, %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge ]
  %tmp_48 = call i1 @_ssdm_op_BitSelect.i1.i7.i32(i7 %i, i32 6)
  %index_V = add i6 %p_0, 1
  br i1 %tmp_48, label %.loopexit, label %2

; <label>:2                                       ; preds = %1
  %i_cast4 = zext i7 %i to i32
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 64, i64 32)
  call void (...)* @_ssdm_op_SpecLoopName([9 x i8]* @p_str) nounwind
  %tmp_s = call i32 (...)* @_ssdm_op_SpecRegionBegin([9 x i8]* @p_str)
  call void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, [1 x i8]* @p_str1) nounwind
  %tmp_4 = icmp slt i32 %i_cast4, %nStubs_read
  br i1 %tmp_4, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit, label %.loopexit

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit: ; preds = %2
  %tmp_5_cast = zext i7 %i to i9
  %tmp_49 = trunc i7 %i to i6
  %sum = add i9 %tmp_24, %tmp_5_cast
  %arrayNo = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum, i32 6, i32 8)
  %arrayNo_cast = zext i3 %arrayNo to i64
  %newIndex = add i6 %tmp, %tmp_49
  %newIndex1 = zext i6 %newIndex to i64
  %stubsInLayer_0_data_1 = getelementptr [64 x i36]* %stubsInLayer_0_data, i64 0, i64 %newIndex1
  %stubsInLayer_0_data_2 = load i36* %stubsInLayer_0_data_1, align 8
  %stubsInLayer_1_data_1 = getelementptr [64 x i36]* %stubsInLayer_1_data, i64 0, i64 %newIndex1
  %stubsInLayer_1_data_2 = load i36* %stubsInLayer_1_data_1, align 8
  %stubsInLayer_2_data_1 = getelementptr [64 x i36]* %stubsInLayer_2_data, i64 0, i64 %newIndex1
  %stubsInLayer_2_data_2 = load i36* %stubsInLayer_2_data_1, align 8
  %stubsInLayer_3_data_1 = getelementptr [64 x i36]* %stubsInLayer_3_data, i64 0, i64 %newIndex1
  %stubsInLayer_3_data_2 = load i36* %stubsInLayer_3_data_1, align 8
  %stubsInLayer_4_data_1 = getelementptr [64 x i36]* %stubsInLayer_4_data, i64 0, i64 %newIndex1
  %stubsInLayer_4_data_2 = load i36* %stubsInLayer_4_data_1, align 8
  %HLSFullStubLayerPS_d = call i36 @_ssdm_op_Mux.ap_auto.5i36.i64(i36 %stubsInLayer_0_data_2, i36 %stubsInLayer_1_data_2, i36 %stubsInLayer_2_data_2, i36 %stubsInLayer_3_data_2, i36 %stubsInLayer_4_data_2, i64 %arrayNo_cast)
  %sum1 = add i9 %tmp_39, %tmp_5_cast
  %arrayNo1_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum1, i32 6, i32 8)
  %newIndex2 = add i6 %tmp_2, %tmp_49
  %newIndex3 = zext i6 %newIndex2 to i64
  %allStubs_0_data_V_s = getelementptr [64 x i36]* %allStubs_0_data_V, i64 0, i64 %newIndex3
  %allStubs_1_data_V_s = getelementptr [64 x i36]* %allStubs_1_data_V, i64 0, i64 %newIndex3
  %allStubs_2_data_V_s = getelementptr [64 x i36]* %allStubs_2_data_V, i64 0, i64 %newIndex3
  %allStubs_3_data_V_s = getelementptr [64 x i36]* %allStubs_3_data_V, i64 0, i64 %newIndex3
  %allStubs_4_data_V_s = getelementptr [64 x i36]* %allStubs_4_data_V, i64 0, i64 %newIndex3
  switch i3 %arrayNo1_cast_cast, label %branch4 [
    i3 0, label %branch0
    i3 1, label %branch1
    i3 2, label %branch2
    i3 3, label %branch3
  ]

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54: ; preds = %branch4, %branch3, %branch2, %branch1, %branch0
  %redZ_V = call i4 @_ssdm_op_PartSelect.i4.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 5, i32 8)
  %redPhi_V = call i3 @_ssdm_op_PartSelect.i3.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 21, i32 23)
  %routePhi_V = call i2 @_ssdm_op_PartSelect.i2.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 24, i32 25)
  %routeZ_V = call i1 @_ssdm_op_BitSelect.i1.i36.i32(i36 %HLSFullStubLayerPS_d, i32 9)
  br i1 %routeZ_V, label %12, label %3

; <label>:3                                       ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54
  switch i2 %routePhi_V, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge [
    i2 0, label %4
    i2 1, label %6
    i2 -2, label %8
    i2 -1, label %10
  ]

; <label>:4                                       ; preds = %3
  %nPH1Z1_V_load_2 = load i6* %nPH1Z1_V
  %tmp_10_cast = zext i6 %nPH1Z1_V_load_2 to i9
  %sum6 = add i9 %tmp_10_cast, %tmp_44
  %arrayNo6_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum6, i32 6, i32 8)
  %newIndex12 = add i6 %tmp_8, %nPH1Z1_V_load_2
  %newIndex13 = zext i6 %newIndex12 to i64
  %vmStubsPH1Z1_0_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z1_0_data, i64 0, i64 %newIndex13
  %vmStubsPH1Z1_1_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z1_1_data, i64 0, i64 %newIndex13
  %vmStubsPH1Z1_2_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z1_2_data, i64 0, i64 %newIndex13
  %vmStubsPH1Z1_3_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z1_3_data, i64 0, i64 %newIndex13
  %vmStubsPH1Z1_4_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z1_4_data, i64 0, i64 %newIndex13
  %tmp_29 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_s = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_29, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo6_cast_cast, label %branch9 [
    i3 0, label %branch5
    i3 1, label %branch6
    i3 2, label %branch7
    i3 3, label %branch8
  ]

; <label>:5                                       ; preds = %branch9, %branch8, %branch7, %branch6, %branch5
  %nPH1Z1_V_load = load i6* %nPH1Z1_V
  %tmp_32 = add i6 %nPH1Z1_V_load, 1
  store i6 %tmp_32, i6* %nPH1Z1_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:6                                       ; preds = %3
  %nPH2Z1_V_load_2 = load i6* %nPH2Z1_V
  %tmp_24_cast = zext i6 %nPH2Z1_V_load_2 to i9
  %sum7 = add i9 %tmp_24_cast, %tmp_45
  %arrayNo7_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum7, i32 6, i32 8)
  %newIndex14 = add i6 %tmp_9, %nPH2Z1_V_load_2
  %newIndex15 = zext i6 %newIndex14 to i64
  %vmStubsPH2Z1_0_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z1_0_data, i64 0, i64 %newIndex15
  %vmStubsPH2Z1_1_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z1_1_data, i64 0, i64 %newIndex15
  %vmStubsPH2Z1_2_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z1_2_data, i64 0, i64 %newIndex15
  %vmStubsPH2Z1_3_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z1_3_data, i64 0, i64 %newIndex15
  %vmStubsPH2Z1_4_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z1_4_data, i64 0, i64 %newIndex15
  %tmp_30 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_1 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_30, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo7_cast_cast, label %branch14 [
    i3 0, label %branch10
    i3 1, label %branch11
    i3 2, label %branch12
    i3 3, label %branch13
  ]

; <label>:7                                       ; preds = %branch14, %branch13, %branch12, %branch11, %branch10
  %nPH2Z1_V_load = load i6* %nPH2Z1_V
  %tmp_33 = add i6 %nPH2Z1_V_load, 1
  store i6 %tmp_33, i6* %nPH2Z1_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:8                                       ; preds = %3
  %nPH3Z1_V_load_2 = load i6* %nPH3Z1_V
  %tmp_41_cast = zext i6 %nPH3Z1_V_load_2 to i9
  %sum8 = add i9 %tmp_41_cast, %tmp_46
  %arrayNo8_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum8, i32 6, i32 8)
  %newIndex16 = add i6 %tmp_10, %nPH3Z1_V_load_2
  %newIndex17 = zext i6 %newIndex16 to i64
  %vmStubsPH3Z1_0_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z1_0_data, i64 0, i64 %newIndex17
  %vmStubsPH3Z1_1_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z1_1_data, i64 0, i64 %newIndex17
  %vmStubsPH3Z1_2_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z1_2_data, i64 0, i64 %newIndex17
  %vmStubsPH3Z1_3_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z1_3_data, i64 0, i64 %newIndex17
  %vmStubsPH3Z1_4_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z1_4_data, i64 0, i64 %newIndex17
  %tmp_36 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_2 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_36, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo8_cast_cast, label %branch19 [
    i3 0, label %branch15
    i3 1, label %branch16
    i3 2, label %branch17
    i3 3, label %branch18
  ]

; <label>:9                                       ; preds = %branch19, %branch18, %branch17, %branch16, %branch15
  %nPH3Z1_V_load = load i6* %nPH3Z1_V
  %tmp_34 = add i6 %nPH3Z1_V_load, 1
  store i6 %tmp_34, i6* %nPH3Z1_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:10                                      ; preds = %3
  %nPH4Z1_V_load_2 = load i6* %nPH4Z1_V
  %tmp_43_cast = zext i6 %nPH4Z1_V_load_2 to i9
  %sum9 = add i9 %tmp_43_cast, %tmp_47
  %arrayNo9_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum9, i32 6, i32 8)
  %newIndex18 = add i6 %tmp_20, %nPH4Z1_V_load_2
  %newIndex19 = zext i6 %newIndex18 to i64
  %vmStubsPH4Z1_0_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z1_0_data, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_1_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z1_1_data, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_2_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z1_2_data, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_3_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z1_3_data, i64 0, i64 %newIndex19
  %vmStubsPH4Z1_4_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z1_4_data, i64 0, i64 %newIndex19
  %tmp_37 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_3 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_37, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo9_cast_cast, label %branch24 [
    i3 0, label %branch20
    i3 1, label %branch21
    i3 2, label %branch22
    i3 3, label %branch23
  ]

; <label>:11                                      ; preds = %branch24, %branch23, %branch22, %branch21, %branch20
  %nPH4Z1_V_load = load i6* %nPH4Z1_V
  %tmp_35 = add i6 %nPH4Z1_V_load, 1
  store i6 %tmp_35, i6* %nPH4Z1_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:12                                      ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54
  switch i2 %routePhi_V, label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge [
    i2 0, label %13
    i2 1, label %15
    i2 -2, label %17
    i2 -1, label %19
  ]

; <label>:13                                      ; preds = %12
  %nPH1Z2_V_load_2 = load i6* %nPH1Z2_V
  %tmp_2_cast = zext i6 %nPH1Z2_V_load_2 to i9
  %sum2 = add i9 %tmp_2_cast, %tmp_40
  %arrayNo2_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum2, i32 6, i32 8)
  %newIndex4 = add i6 %tmp_3, %nPH1Z2_V_load_2
  %newIndex5 = zext i6 %newIndex4 to i64
  %vmStubsPH1Z2_0_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z2_0_data, i64 0, i64 %newIndex5
  %vmStubsPH1Z2_1_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z2_1_data, i64 0, i64 %newIndex5
  %vmStubsPH1Z2_2_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z2_2_data, i64 0, i64 %newIndex5
  %vmStubsPH1Z2_3_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z2_3_data, i64 0, i64 %newIndex5
  %vmStubsPH1Z2_4_data_1 = getelementptr [64 x i18]* %vmStubsPH1Z2_4_data, i64 0, i64 %newIndex5
  %tmp_22 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_4 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_22, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo2_cast_cast, label %branch29 [
    i3 0, label %branch25
    i3 1, label %branch26
    i3 2, label %branch27
    i3 3, label %branch28
  ]

; <label>:14                                      ; preds = %branch29, %branch28, %branch27, %branch26, %branch25
  %nPH1Z2_V_load = load i6* %nPH1Z2_V
  %tmp_31 = add i6 %nPH1Z2_V_load, 1
  store i6 %tmp_31, i6* %nPH1Z2_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:15                                      ; preds = %12
  %nPH2Z2_V_load_2 = load i6* %nPH2Z2_V
  %tmp_3_cast = zext i6 %nPH2Z2_V_load_2 to i9
  %sum3 = add i9 %tmp_3_cast, %tmp_41
  %arrayNo3_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum3, i32 6, i32 8)
  %newIndex6 = add i6 %tmp_5, %nPH2Z2_V_load_2
  %newIndex7 = zext i6 %newIndex6 to i64
  %vmStubsPH2Z2_0_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z2_0_data, i64 0, i64 %newIndex7
  %vmStubsPH2Z2_1_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z2_1_data, i64 0, i64 %newIndex7
  %vmStubsPH2Z2_2_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z2_2_data, i64 0, i64 %newIndex7
  %vmStubsPH2Z2_3_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z2_3_data, i64 0, i64 %newIndex7
  %vmStubsPH2Z2_4_data_1 = getelementptr [64 x i18]* %vmStubsPH2Z2_4_data, i64 0, i64 %newIndex7
  %tmp_26 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_5 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_26, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo3_cast_cast, label %branch34 [
    i3 0, label %branch30
    i3 1, label %branch31
    i3 2, label %branch32
    i3 3, label %branch33
  ]

; <label>:16                                      ; preds = %branch34, %branch33, %branch32, %branch31, %branch30
  %nPH2Z2_V_load = load i6* %nPH2Z2_V
  %tmp_21 = add i6 %nPH2Z2_V_load, 1
  store i6 %tmp_21, i6* %nPH2Z2_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:17                                      ; preds = %12
  %nPH3Z2_V_load_2 = load i6* %nPH3Z2_V
  %tmp_20_cast = zext i6 %nPH3Z2_V_load_2 to i9
  %sum4 = add i9 %tmp_20_cast, %tmp_42
  %arrayNo4_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum4, i32 6, i32 8)
  %newIndex8 = add i6 %tmp_6, %nPH3Z2_V_load_2
  %newIndex9 = zext i6 %newIndex8 to i64
  %vmStubsPH3Z2_0_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z2_0_data, i64 0, i64 %newIndex9
  %vmStubsPH3Z2_1_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z2_1_data, i64 0, i64 %newIndex9
  %vmStubsPH3Z2_2_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z2_2_data, i64 0, i64 %newIndex9
  %vmStubsPH3Z2_3_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z2_3_data, i64 0, i64 %newIndex9
  %vmStubsPH3Z2_4_data_1 = getelementptr [64 x i18]* %vmStubsPH3Z2_4_data, i64 0, i64 %newIndex9
  %tmp_27 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_6 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_27, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo4_cast_cast, label %branch39 [
    i3 0, label %branch35
    i3 1, label %branch36
    i3 2, label %branch37
    i3 3, label %branch38
  ]

; <label>:18                                      ; preds = %branch39, %branch38, %branch37, %branch36, %branch35
  %nPH3Z2_V_load = load i6* %nPH3Z2_V
  %tmp_23 = add i6 %nPH3Z2_V_load, 1
  store i6 %tmp_23, i6* %nPH3Z2_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

; <label>:19                                      ; preds = %12
  %nPH4Z2_V_load_2 = load i6* %nPH4Z2_V
  %tmp_22_cast = zext i6 %nPH4Z2_V_load_2 to i9
  %sum5 = add i9 %tmp_22_cast, %tmp_43
  %arrayNo5_cast_cast = call i3 @_ssdm_op_PartSelect.i3.i9.i32.i32(i9 %sum5, i32 6, i32 8)
  %newIndex10 = add i6 %tmp_7, %nPH4Z2_V_load_2
  %newIndex11 = zext i6 %newIndex10 to i64
  %vmStubsPH4Z2_0_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z2_0_data, i64 0, i64 %newIndex11
  %vmStubsPH4Z2_1_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z2_1_data, i64 0, i64 %newIndex11
  %vmStubsPH4Z2_2_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z2_2_data, i64 0, i64 %newIndex11
  %vmStubsPH4Z2_3_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z2_3_data, i64 0, i64 %newIndex11
  %vmStubsPH4Z2_4_data_1 = getelementptr [64 x i18]* %vmStubsPH4Z2_4_data, i64 0, i64 %newIndex11
  %tmp_28 = call i5 @_ssdm_op_PartSelect.i5.i36.i32.i32(i36 %HLSFullStubLayerPS_d, i32 31, i32 35)
  %HLSReducedStubLayer_7 = call i18 @_ssdm_op_BitConcatenate.i18.i6.i5.i3.i4(i6 %p_0, i5 %tmp_28, i3 %redPhi_V, i4 %redZ_V)
  switch i3 %arrayNo5_cast_cast, label %branch44 [
    i3 0, label %branch40
    i3 1, label %branch41
    i3 2, label %branch42
    i3 3, label %branch43
  ]

; <label>:20                                      ; preds = %branch44, %branch43, %branch42, %branch41, %branch40
  %nPH4Z2_V_load = load i6* %nPH4Z2_V
  %tmp_25 = add i6 %nPH4Z2_V_load, 1
  store i6 %tmp_25, i6* %nPH4Z2_V
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge

_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit._crit_edge: ; preds = %20, %18, %16, %14, %12, %11, %9, %7, %5, %3
  %empty_29 = call i32 (...)* @_ssdm_op_SpecRegionEnd([9 x i8]* @p_str, i32 %tmp_s)
  %i_1 = add i7 %i, 1
  br label %1

.loopexit:                                        ; preds = %1, %2
  %nPH4Z2_V_load_1 = load i6* %nPH4Z2_V
  %nPH3Z2_V_load_1 = load i6* %nPH3Z2_V
  %nPH2Z2_V_load_1 = load i6* %nPH2Z2_V
  %nPH1Z2_V_load_1 = load i6* %nPH1Z2_V
  %nPH4Z1_V_load_1 = load i6* %nPH4Z1_V
  %nPH3Z1_V_load_1 = load i6* %nPH3Z1_V
  %nPH2Z1_V_load_1 = load i6* %nPH2Z1_V
  %nPH1Z1_V_load_1 = load i6* %nPH1Z1_V
  %mrv = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } undef, i6 %nPH1Z1_V_load_1, 0
  %mrv_1 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv, i6 %nPH2Z1_V_load_1, 1
  %mrv_2 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_1, i6 %nPH3Z1_V_load_1, 2
  %mrv_3 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_2, i6 %nPH4Z1_V_load_1, 3
  %mrv_4 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_3, i6 %nPH1Z2_V_load_1, 4
  %mrv_5 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_4, i6 %nPH2Z2_V_load_1, 5
  %mrv_6 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_5, i6 %nPH3Z2_V_load_1, 6
  %mrv_7 = insertvalue { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_6, i6 %nPH4Z2_V_load_1, 7
  ret { i6, i6, i6, i6, i6, i6, i6, i6 } %mrv_7

branch0:                                          ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit
  store i36 %HLSFullStubLayerPS_d, i36* %allStubs_0_data_V_s, align 8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54

branch1:                                          ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit
  store i36 %HLSFullStubLayerPS_d, i36* %allStubs_1_data_V_s, align 8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54

branch2:                                          ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit
  store i36 %HLSFullStubLayerPS_d, i36* %allStubs_2_data_V_s, align 8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54

branch3:                                          ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit
  store i36 %HLSFullStubLayerPS_d, i36* %allStubs_3_data_V_s, align 8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54

branch4:                                          ; preds = %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit
  store i36 %HLSFullStubLayerPS_d, i36* %allStubs_4_data_V_s, align 8
  br label %_ZrsILi12ELb0EE11ap_int_baseIXT_EXT0_EXleT_Li64EEERKS1_i.exit54

branch5:                                          ; preds = %4
  store i18 %HLSReducedStubLayer_s, i18* %vmStubsPH1Z1_0_data_1, align 4
  br label %5

branch6:                                          ; preds = %4
  store i18 %HLSReducedStubLayer_s, i18* %vmStubsPH1Z1_1_data_1, align 4
  br label %5

branch7:                                          ; preds = %4
  store i18 %HLSReducedStubLayer_s, i18* %vmStubsPH1Z1_2_data_1, align 4
  br label %5

branch8:                                          ; preds = %4
  store i18 %HLSReducedStubLayer_s, i18* %vmStubsPH1Z1_3_data_1, align 4
  br label %5

branch9:                                          ; preds = %4
  store i18 %HLSReducedStubLayer_s, i18* %vmStubsPH1Z1_4_data_1, align 4
  br label %5

branch10:                                         ; preds = %6
  store i18 %HLSReducedStubLayer_1, i18* %vmStubsPH2Z1_0_data_1, align 4
  br label %7

branch11:                                         ; preds = %6
  store i18 %HLSReducedStubLayer_1, i18* %vmStubsPH2Z1_1_data_1, align 4
  br label %7

branch12:                                         ; preds = %6
  store i18 %HLSReducedStubLayer_1, i18* %vmStubsPH2Z1_2_data_1, align 4
  br label %7

branch13:                                         ; preds = %6
  store i18 %HLSReducedStubLayer_1, i18* %vmStubsPH2Z1_3_data_1, align 4
  br label %7

branch14:                                         ; preds = %6
  store i18 %HLSReducedStubLayer_1, i18* %vmStubsPH2Z1_4_data_1, align 4
  br label %7

branch15:                                         ; preds = %8
  store i18 %HLSReducedStubLayer_2, i18* %vmStubsPH3Z1_0_data_1, align 4
  br label %9

branch16:                                         ; preds = %8
  store i18 %HLSReducedStubLayer_2, i18* %vmStubsPH3Z1_1_data_1, align 4
  br label %9

branch17:                                         ; preds = %8
  store i18 %HLSReducedStubLayer_2, i18* %vmStubsPH3Z1_2_data_1, align 4
  br label %9

branch18:                                         ; preds = %8
  store i18 %HLSReducedStubLayer_2, i18* %vmStubsPH3Z1_3_data_1, align 4
  br label %9

branch19:                                         ; preds = %8
  store i18 %HLSReducedStubLayer_2, i18* %vmStubsPH3Z1_4_data_1, align 4
  br label %9

branch20:                                         ; preds = %10
  store i18 %HLSReducedStubLayer_3, i18* %vmStubsPH4Z1_0_data_1, align 4
  br label %11

branch21:                                         ; preds = %10
  store i18 %HLSReducedStubLayer_3, i18* %vmStubsPH4Z1_1_data_1, align 4
  br label %11

branch22:                                         ; preds = %10
  store i18 %HLSReducedStubLayer_3, i18* %vmStubsPH4Z1_2_data_1, align 4
  br label %11

branch23:                                         ; preds = %10
  store i18 %HLSReducedStubLayer_3, i18* %vmStubsPH4Z1_3_data_1, align 4
  br label %11

branch24:                                         ; preds = %10
  store i18 %HLSReducedStubLayer_3, i18* %vmStubsPH4Z1_4_data_1, align 4
  br label %11

branch25:                                         ; preds = %13
  store i18 %HLSReducedStubLayer_4, i18* %vmStubsPH1Z2_0_data_1, align 4
  br label %14

branch26:                                         ; preds = %13
  store i18 %HLSReducedStubLayer_4, i18* %vmStubsPH1Z2_1_data_1, align 4
  br label %14

branch27:                                         ; preds = %13
  store i18 %HLSReducedStubLayer_4, i18* %vmStubsPH1Z2_2_data_1, align 4
  br label %14

branch28:                                         ; preds = %13
  store i18 %HLSReducedStubLayer_4, i18* %vmStubsPH1Z2_3_data_1, align 4
  br label %14

branch29:                                         ; preds = %13
  store i18 %HLSReducedStubLayer_4, i18* %vmStubsPH1Z2_4_data_1, align 4
  br label %14

branch30:                                         ; preds = %15
  store i18 %HLSReducedStubLayer_5, i18* %vmStubsPH2Z2_0_data_1, align 4
  br label %16

branch31:                                         ; preds = %15
  store i18 %HLSReducedStubLayer_5, i18* %vmStubsPH2Z2_1_data_1, align 4
  br label %16

branch32:                                         ; preds = %15
  store i18 %HLSReducedStubLayer_5, i18* %vmStubsPH2Z2_2_data_1, align 4
  br label %16

branch33:                                         ; preds = %15
  store i18 %HLSReducedStubLayer_5, i18* %vmStubsPH2Z2_3_data_1, align 4
  br label %16

branch34:                                         ; preds = %15
  store i18 %HLSReducedStubLayer_5, i18* %vmStubsPH2Z2_4_data_1, align 4
  br label %16

branch35:                                         ; preds = %17
  store i18 %HLSReducedStubLayer_6, i18* %vmStubsPH3Z2_0_data_1, align 4
  br label %18

branch36:                                         ; preds = %17
  store i18 %HLSReducedStubLayer_6, i18* %vmStubsPH3Z2_1_data_1, align 4
  br label %18

branch37:                                         ; preds = %17
  store i18 %HLSReducedStubLayer_6, i18* %vmStubsPH3Z2_2_data_1, align 4
  br label %18

branch38:                                         ; preds = %17
  store i18 %HLSReducedStubLayer_6, i18* %vmStubsPH3Z2_3_data_1, align 4
  br label %18

branch39:                                         ; preds = %17
  store i18 %HLSReducedStubLayer_6, i18* %vmStubsPH3Z2_4_data_1, align 4
  br label %18

branch40:                                         ; preds = %19
  store i18 %HLSReducedStubLayer_7, i18* %vmStubsPH4Z2_0_data_1, align 4
  br label %20

branch41:                                         ; preds = %19
  store i18 %HLSReducedStubLayer_7, i18* %vmStubsPH4Z2_1_data_1, align 4
  br label %20

branch42:                                         ; preds = %19
  store i18 %HLSReducedStubLayer_7, i18* %vmStubsPH4Z2_2_data_1, align 4
  br label %20

branch43:                                         ; preds = %19
  store i18 %HLSReducedStubLayer_7, i18* %vmStubsPH4Z2_3_data_1, align 4
  br label %20

branch44:                                         ; preds = %19
  store i18 %HLSReducedStubLayer_7, i18* %vmStubsPH4Z2_4_data_1, align 4
  br label %20
}

!opencl.kernels = !{!0, !7, !13, !13, !7, !19, !7, !7, !7, !22, !22, !7, !22, !22, !7, !7, !24, !30, !30, !7, !32, !7, !7, !35, !35, !37, !7, !7, !7, !22, !22, !7, !7, !39, !41, !43, !43, !45, !7, !7, !7, !22, !22, !7, !7, !47, !49, !51, !51, !53, !7, !7, !7, !55, !55, !7, !7, !7, !7, !57, !7, !7, !7, !63, !65, !65, !7, !67, !7, !7, !69, !69, !71, !73, !75, !75, !7, !7, !77, !79, !7, !7, !85, !87, !51, !51, !75, !75, !7, !7, !89, !7, !91, !7, !93, !95, !95, !7, !97, !7, !7, !99, !99, !101, !101, !7, !101, !101, !7, !101, !101, !7, !101, !101, !103, !7, !7}
!hls.encrypted.func = !{}
!llvm.map.gv = !{!108}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 0, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"int", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"const", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"stubsInLayer", metadata !"allStubs", metadata !"vmStubsPH1Z1", metadata !"vmStubsPH2Z1", metadata !"vmStubsPH3Z1", metadata !"vmStubsPH4Z1", metadata !"vmStubsPH1Z2", metadata !"vmStubsPH2Z2", metadata !"vmStubsPH3Z2", metadata !"vmStubsPH4Z2", metadata !"nStubs", metadata !"nPH1Z1", metadata !"nPH2Z1", metadata !"nPH3Z1", metadata !"nPH4Z1", metadata !"nPH1Z2", metadata !"nPH2Z2", metadata !"nPH3Z2", metadata !"nPH4Z2"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{null, metadata !8, metadata !9, metadata !10, metadata !11, metadata !12, metadata !6}
!8 = metadata !{metadata !"kernel_arg_addr_space"}
!9 = metadata !{metadata !"kernel_arg_access_qual"}
!10 = metadata !{metadata !"kernel_arg_type"}
!11 = metadata !{metadata !"kernel_arg_type_qual"}
!12 = metadata !{metadata !"kernel_arg_name"}
!13 = metadata !{null, metadata !14, metadata !15, metadata !16, metadata !17, metadata !18, metadata !6}
!14 = metadata !{metadata !"kernel_arg_addr_space", i32 0}
!15 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none"}
!16 = metadata !{metadata !"kernel_arg_type", metadata !"int"}
!17 = metadata !{metadata !"kernel_arg_type_qual", metadata !""}
!18 = metadata !{metadata !"kernel_arg_name", metadata !"op"}
!19 = metadata !{null, metadata !14, metadata !15, metadata !20, metadata !17, metadata !21, metadata !6}
!20 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<1, false> &"}
!21 = metadata !{metadata !"kernel_arg_name", metadata !"op2"}
!22 = metadata !{null, metadata !14, metadata !15, metadata !23, metadata !17, metadata !18, metadata !6}
!23 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<32, false> &"}
!24 = metadata !{null, metadata !25, metadata !26, metadata !27, metadata !28, metadata !29, metadata !6}
!25 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0}
!26 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none"}
!27 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"uint"}
!28 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !""}
!29 = metadata !{metadata !"kernel_arg_name", metadata !"op", metadata !"i_op"}
!30 = metadata !{null, metadata !14, metadata !15, metadata !31, metadata !17, metadata !18, metadata !6}
!31 = metadata !{metadata !"kernel_arg_type", metadata !"uint"}
!32 = metadata !{null, metadata !25, metadata !26, metadata !33, metadata !28, metadata !34, metadata !6}
!33 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"const ap_int_base<32, false> &"}
!34 = metadata !{metadata !"kernel_arg_name", metadata !"op", metadata !"op2"}
!35 = metadata !{null, metadata !14, metadata !15, metadata !36, metadata !17, metadata !18, metadata !6}
!36 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &"}
!37 = metadata !{null, metadata !25, metadata !26, metadata !38, metadata !28, metadata !34, metadata !6}
!38 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<7, false> &", metadata !"int"}
!39 = metadata !{null, metadata !25, metadata !26, metadata !40, metadata !28, metadata !29, metadata !6}
!40 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"uint"}
!41 = metadata !{null, metadata !25, metadata !26, metadata !42, metadata !28, metadata !34, metadata !6}
!42 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"const ap_int_base<32, false> &"}
!43 = metadata !{null, metadata !14, metadata !15, metadata !44, metadata !17, metadata !18, metadata !6}
!44 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &"}
!45 = metadata !{null, metadata !25, metadata !26, metadata !46, metadata !28, metadata !34, metadata !6}
!46 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<14, false> &", metadata !"int"}
!47 = metadata !{null, metadata !25, metadata !26, metadata !48, metadata !28, metadata !29, metadata !6}
!48 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"uint"}
!49 = metadata !{null, metadata !25, metadata !26, metadata !50, metadata !28, metadata !34, metadata !6}
!50 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"const ap_int_base<32, false> &"}
!51 = metadata !{null, metadata !14, metadata !15, metadata !52, metadata !17, metadata !18, metadata !6}
!52 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &"}
!53 = metadata !{null, metadata !25, metadata !26, metadata !54, metadata !28, metadata !34, metadata !6}
!54 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"int"}
!55 = metadata !{null, metadata !14, metadata !15, metadata !16, metadata !17, metadata !56, metadata !6}
!56 = metadata !{metadata !"kernel_arg_name", metadata !"val"}
!57 = metadata !{null, metadata !58, metadata !59, metadata !60, metadata !61, metadata !62, metadata !6}
!58 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 0, i32 0, i32 0}
!59 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!60 = metadata !{metadata !"kernel_arg_type", metadata !"ReducedZ_Layer", metadata !"ReducedPhi_Layer", metadata !"ReducedR_Layer", metadata !"ReducedPt_Layer", metadata !"ReducedIndex"}
!61 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!62 = metadata !{metadata !"kernel_arg_name", metadata !"newZ", metadata !"newPhi", metadata !"newR", metadata !"newPt", metadata !"newIndex"}
!63 = metadata !{null, metadata !25, metadata !26, metadata !64, metadata !28, metadata !29, metadata !6}
!64 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<4, false> &", metadata !"long"}
!65 = metadata !{null, metadata !14, metadata !15, metadata !66, metadata !17, metadata !18, metadata !6}
!66 = metadata !{metadata !"kernel_arg_type", metadata !"long"}
!67 = metadata !{null, metadata !25, metadata !26, metadata !68, metadata !28, metadata !34, metadata !6}
!68 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<4, false> &", metadata !"const ap_int_base<64, true> &"}
!69 = metadata !{null, metadata !14, metadata !15, metadata !70, metadata !17, metadata !18, metadata !6}
!70 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<4, false> &"}
!71 = metadata !{null, metadata !25, metadata !26, metadata !72, metadata !28, metadata !29, metadata !6}
!72 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<64, true> &", metadata !"long"}
!73 = metadata !{null, metadata !25, metadata !26, metadata !74, metadata !28, metadata !34, metadata !6}
!74 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<64, true> &", metadata !"const ap_int_base<64, true> &"}
!75 = metadata !{null, metadata !14, metadata !15, metadata !76, metadata !17, metadata !18, metadata !6}
!76 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<64, true> &"}
!77 = metadata !{null, metadata !14, metadata !15, metadata !78, metadata !17, metadata !21, metadata !6}
!78 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<18> &"}
!79 = metadata !{null, metadata !80, metadata !81, metadata !82, metadata !83, metadata !84, metadata !6}
!80 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 0, i32 0}
!81 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!82 = metadata !{metadata !"kernel_arg_type", metadata !"FullZ_Layer_PS", metadata !"FullPhi_Layer_PS", metadata !"FullR_Layer_PS", metadata !"FullPt_Layer_PS"}
!83 = metadata !{metadata !"kernel_arg_type_qual", metadata !"const", metadata !"const", metadata !"const", metadata !"const"}
!84 = metadata !{metadata !"kernel_arg_name", metadata !"newZ", metadata !"newPhi", metadata !"newR", metadata !"newPt"}
!85 = metadata !{null, metadata !25, metadata !26, metadata !86, metadata !28, metadata !29, metadata !6}
!86 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"long"}
!87 = metadata !{null, metadata !25, metadata !26, metadata !88, metadata !28, metadata !34, metadata !6}
!88 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<12, false> &", metadata !"const ap_int_base<64, true> &"}
!89 = metadata !{null, metadata !14, metadata !15, metadata !90, metadata !17, metadata !21, metadata !6}
!90 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_uint<36> &"}
!91 = metadata !{null, metadata !25, metadata !26, metadata !92, metadata !28, metadata !34, metadata !6}
!92 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<36, false> &", metadata !"int"}
!93 = metadata !{null, metadata !25, metadata !26, metadata !94, metadata !28, metadata !29, metadata !6}
!94 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<36, false> &", metadata !"ulong"}
!95 = metadata !{null, metadata !14, metadata !15, metadata !96, metadata !17, metadata !18, metadata !6}
!96 = metadata !{metadata !"kernel_arg_type", metadata !"ulong"}
!97 = metadata !{null, metadata !25, metadata !26, metadata !98, metadata !28, metadata !34, metadata !6}
!98 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<36, false> &", metadata !"const ap_int_base<64, false> &"}
!99 = metadata !{null, metadata !14, metadata !15, metadata !100, metadata !17, metadata !18, metadata !6}
!100 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<36, false> &"}
!101 = metadata !{null, metadata !14, metadata !15, metadata !102, metadata !17, metadata !18, metadata !6}
!102 = metadata !{metadata !"kernel_arg_type", metadata !"const ap_int_base<64, false> &"}
!103 = metadata !{null, metadata !104, metadata !2, metadata !105, metadata !106, metadata !107, metadata !6}
!104 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1}
!105 = metadata !{metadata !"kernel_arg_type", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSFullStubLayerPS*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"class HLSReducedStubLayer*", metadata !"int*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*", metadata !"ReducedIndex*"}
!106 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !"", metadata !""}
!107 = metadata !{metadata !"kernel_arg_name", metadata !"curStubsInLayer", metadata !"curAllStubs", metadata !"curvmStubsPH1Z1", metadata !"curvmStubsPH2Z1", metadata !"curvmStubsPH3Z1", metadata !"curvmStubsPH4Z1", metadata !"curvmStubsPH1Z2", metadata !"curvmStubsPH2Z2", metadata !"curvmStubsPH3Z2", metadata !"curvmStubsPH4Z2", metadata !"curnStubs", metadata !"curnPH1Z1", metadata !"curnPH2Z1", metadata !"curnPH3Z1", metadata !"curnPH4Z1", metadata !"curnPH1Z2", metadata !"curnPH2Z2", metadata !"curnPH3Z2", metadata !"curnPH4Z2"}
!108 = metadata !{metadata !109, [2 x i32]* @llvm_global_ctors_0}
!109 = metadata !{metadata !110}
!110 = metadata !{i32 0, i32 31, metadata !111}
!111 = metadata !{metadata !112}
!112 = metadata !{metadata !"llvm.global_ctors.0", metadata !113, metadata !"", i32 0, i32 31}
!113 = metadata !{metadata !114}
!114 = metadata !{i32 0, i32 1, i32 1}
!115 = metadata !{metadata !116}
!116 = metadata !{i32 0, i32 5, metadata !117}
!117 = metadata !{metadata !118}
!118 = metadata !{metadata !"curnPH4Z2.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!119 = metadata !{metadata !120}
!120 = metadata !{i32 4, i32 4, i32 2}
!121 = metadata !{metadata !122}
!122 = metadata !{i32 0, i32 5, metadata !123}
!123 = metadata !{metadata !124}
!124 = metadata !{metadata !"curnPH4Z2.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!125 = metadata !{metadata !126}
!126 = metadata !{i32 3, i32 3, i32 2}
!127 = metadata !{metadata !128}
!128 = metadata !{i32 0, i32 5, metadata !129}
!129 = metadata !{metadata !130}
!130 = metadata !{metadata !"curnPH4Z2.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!131 = metadata !{metadata !132}
!132 = metadata !{i32 2, i32 2, i32 2}
!133 = metadata !{metadata !134}
!134 = metadata !{i32 0, i32 5, metadata !135}
!135 = metadata !{metadata !136}
!136 = metadata !{metadata !"curnPH4Z2.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!137 = metadata !{metadata !138}
!138 = metadata !{i32 1, i32 1, i32 2}
!139 = metadata !{metadata !140}
!140 = metadata !{i32 0, i32 5, metadata !141}
!141 = metadata !{metadata !142}
!142 = metadata !{metadata !"curnPH4Z2.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!143 = metadata !{metadata !144}
!144 = metadata !{i32 0, i32 0, i32 2}
!145 = metadata !{metadata !146}
!146 = metadata !{i32 0, i32 5, metadata !147}
!147 = metadata !{metadata !148}
!148 = metadata !{metadata !"curnPH3Z2.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!149 = metadata !{metadata !150}
!150 = metadata !{i32 0, i32 5, metadata !151}
!151 = metadata !{metadata !152}
!152 = metadata !{metadata !"curnPH3Z2.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!153 = metadata !{metadata !154}
!154 = metadata !{i32 0, i32 5, metadata !155}
!155 = metadata !{metadata !156}
!156 = metadata !{metadata !"curnPH3Z2.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!157 = metadata !{metadata !158}
!158 = metadata !{i32 0, i32 5, metadata !159}
!159 = metadata !{metadata !160}
!160 = metadata !{metadata !"curnPH3Z2.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!161 = metadata !{metadata !162}
!162 = metadata !{i32 0, i32 5, metadata !163}
!163 = metadata !{metadata !164}
!164 = metadata !{metadata !"curnPH3Z2.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!165 = metadata !{metadata !166}
!166 = metadata !{i32 0, i32 5, metadata !167}
!167 = metadata !{metadata !168}
!168 = metadata !{metadata !"curnPH2Z2.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!169 = metadata !{metadata !170}
!170 = metadata !{i32 0, i32 5, metadata !171}
!171 = metadata !{metadata !172}
!172 = metadata !{metadata !"curnPH2Z2.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!173 = metadata !{metadata !174}
!174 = metadata !{i32 0, i32 5, metadata !175}
!175 = metadata !{metadata !176}
!176 = metadata !{metadata !"curnPH2Z2.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!177 = metadata !{metadata !178}
!178 = metadata !{i32 0, i32 5, metadata !179}
!179 = metadata !{metadata !180}
!180 = metadata !{metadata !"curnPH2Z2.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!181 = metadata !{metadata !182}
!182 = metadata !{i32 0, i32 5, metadata !183}
!183 = metadata !{metadata !184}
!184 = metadata !{metadata !"curnPH2Z2.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!185 = metadata !{metadata !186}
!186 = metadata !{i32 0, i32 5, metadata !187}
!187 = metadata !{metadata !188}
!188 = metadata !{metadata !"curnPH1Z2.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!189 = metadata !{metadata !190}
!190 = metadata !{i32 0, i32 5, metadata !191}
!191 = metadata !{metadata !192}
!192 = metadata !{metadata !"curnPH1Z2.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!193 = metadata !{metadata !194}
!194 = metadata !{i32 0, i32 5, metadata !195}
!195 = metadata !{metadata !196}
!196 = metadata !{metadata !"curnPH1Z2.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!197 = metadata !{metadata !198}
!198 = metadata !{i32 0, i32 5, metadata !199}
!199 = metadata !{metadata !200}
!200 = metadata !{metadata !"curnPH1Z2.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!201 = metadata !{metadata !202}
!202 = metadata !{i32 0, i32 5, metadata !203}
!203 = metadata !{metadata !204}
!204 = metadata !{metadata !"curnPH1Z2.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!205 = metadata !{metadata !206}
!206 = metadata !{i32 0, i32 5, metadata !207}
!207 = metadata !{metadata !208}
!208 = metadata !{metadata !"curnPH4Z1.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!209 = metadata !{metadata !210}
!210 = metadata !{i32 0, i32 5, metadata !211}
!211 = metadata !{metadata !212}
!212 = metadata !{metadata !"curnPH4Z1.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!213 = metadata !{metadata !214}
!214 = metadata !{i32 0, i32 5, metadata !215}
!215 = metadata !{metadata !216}
!216 = metadata !{metadata !"curnPH4Z1.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!217 = metadata !{metadata !218}
!218 = metadata !{i32 0, i32 5, metadata !219}
!219 = metadata !{metadata !220}
!220 = metadata !{metadata !"curnPH4Z1.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!221 = metadata !{metadata !222}
!222 = metadata !{i32 0, i32 5, metadata !223}
!223 = metadata !{metadata !224}
!224 = metadata !{metadata !"curnPH4Z1.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!225 = metadata !{metadata !226}
!226 = metadata !{i32 0, i32 5, metadata !227}
!227 = metadata !{metadata !228}
!228 = metadata !{metadata !"curnPH3Z1.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!229 = metadata !{metadata !230}
!230 = metadata !{i32 0, i32 5, metadata !231}
!231 = metadata !{metadata !232}
!232 = metadata !{metadata !"curnPH3Z1.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!233 = metadata !{metadata !234}
!234 = metadata !{i32 0, i32 5, metadata !235}
!235 = metadata !{metadata !236}
!236 = metadata !{metadata !"curnPH3Z1.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!237 = metadata !{metadata !238}
!238 = metadata !{i32 0, i32 5, metadata !239}
!239 = metadata !{metadata !240}
!240 = metadata !{metadata !"curnPH3Z1.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!241 = metadata !{metadata !242}
!242 = metadata !{i32 0, i32 5, metadata !243}
!243 = metadata !{metadata !244}
!244 = metadata !{metadata !"curnPH3Z1.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!245 = metadata !{metadata !246}
!246 = metadata !{i32 0, i32 5, metadata !247}
!247 = metadata !{metadata !248}
!248 = metadata !{metadata !"curnPH2Z1.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!249 = metadata !{metadata !250}
!250 = metadata !{i32 0, i32 5, metadata !251}
!251 = metadata !{metadata !252}
!252 = metadata !{metadata !"curnPH2Z1.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!253 = metadata !{metadata !254}
!254 = metadata !{i32 0, i32 5, metadata !255}
!255 = metadata !{metadata !256}
!256 = metadata !{metadata !"curnPH2Z1.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!257 = metadata !{metadata !258}
!258 = metadata !{i32 0, i32 5, metadata !259}
!259 = metadata !{metadata !260}
!260 = metadata !{metadata !"curnPH2Z1.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!261 = metadata !{metadata !262}
!262 = metadata !{i32 0, i32 5, metadata !263}
!263 = metadata !{metadata !264}
!264 = metadata !{metadata !"curnPH2Z1.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!265 = metadata !{metadata !266}
!266 = metadata !{i32 0, i32 5, metadata !267}
!267 = metadata !{metadata !268}
!268 = metadata !{metadata !"curnPH1Z1.V", metadata !119, metadata !"uint6", i32 0, i32 5}
!269 = metadata !{metadata !270}
!270 = metadata !{i32 0, i32 5, metadata !271}
!271 = metadata !{metadata !272}
!272 = metadata !{metadata !"curnPH1Z1.V", metadata !125, metadata !"uint6", i32 0, i32 5}
!273 = metadata !{metadata !274}
!274 = metadata !{i32 0, i32 5, metadata !275}
!275 = metadata !{metadata !276}
!276 = metadata !{metadata !"curnPH1Z1.V", metadata !131, metadata !"uint6", i32 0, i32 5}
!277 = metadata !{metadata !278}
!278 = metadata !{i32 0, i32 5, metadata !279}
!279 = metadata !{metadata !280}
!280 = metadata !{metadata !"curnPH1Z1.V", metadata !137, metadata !"uint6", i32 0, i32 5}
!281 = metadata !{metadata !282}
!282 = metadata !{i32 0, i32 5, metadata !283}
!283 = metadata !{metadata !284}
!284 = metadata !{metadata !"curnPH1Z1.V", metadata !143, metadata !"uint6", i32 0, i32 5}
!285 = metadata !{metadata !286}
!286 = metadata !{i32 0, i32 31, metadata !287}
!287 = metadata !{metadata !288}
!288 = metadata !{metadata !"curnStubs", metadata !119, metadata !"int", i32 0, i32 31}
!289 = metadata !{metadata !290}
!290 = metadata !{i32 0, i32 31, metadata !291}
!291 = metadata !{metadata !292}
!292 = metadata !{metadata !"curnStubs", metadata !125, metadata !"int", i32 0, i32 31}
!293 = metadata !{metadata !294}
!294 = metadata !{i32 0, i32 31, metadata !295}
!295 = metadata !{metadata !296}
!296 = metadata !{metadata !"curnStubs", metadata !131, metadata !"int", i32 0, i32 31}
!297 = metadata !{metadata !298}
!298 = metadata !{i32 0, i32 31, metadata !299}
!299 = metadata !{metadata !300}
!300 = metadata !{metadata !"curnStubs", metadata !137, metadata !"int", i32 0, i32 31}
!301 = metadata !{metadata !302}
!302 = metadata !{i32 0, i32 31, metadata !303}
!303 = metadata !{metadata !304}
!304 = metadata !{metadata !"curnStubs", metadata !143, metadata !"int", i32 0, i32 31}
!305 = metadata !{metadata !306}
!306 = metadata !{i32 0, i32 17, metadata !307}
!307 = metadata !{metadata !308}
!308 = metadata !{metadata !"curvmStubsPH4Z2.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!309 = metadata !{metadata !310}
!310 = metadata !{i32 256, i32 319, i32 1}
!311 = metadata !{metadata !312}
!312 = metadata !{i32 0, i32 17, metadata !313}
!313 = metadata !{metadata !314}
!314 = metadata !{metadata !"curvmStubsPH4Z2.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!315 = metadata !{metadata !316}
!316 = metadata !{i32 192, i32 255, i32 1}
!317 = metadata !{metadata !318}
!318 = metadata !{i32 0, i32 17, metadata !319}
!319 = metadata !{metadata !320}
!320 = metadata !{metadata !"curvmStubsPH4Z2.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!321 = metadata !{metadata !322}
!322 = metadata !{i32 128, i32 191, i32 1}
!323 = metadata !{metadata !324}
!324 = metadata !{i32 0, i32 17, metadata !325}
!325 = metadata !{metadata !326}
!326 = metadata !{metadata !"curvmStubsPH4Z2.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!327 = metadata !{metadata !328}
!328 = metadata !{i32 64, i32 127, i32 1}
!329 = metadata !{metadata !330}
!330 = metadata !{i32 0, i32 17, metadata !331}
!331 = metadata !{metadata !332}
!332 = metadata !{metadata !"curvmStubsPH4Z2.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!333 = metadata !{metadata !334}
!334 = metadata !{i32 0, i32 63, i32 1}
!335 = metadata !{metadata !336}
!336 = metadata !{i32 0, i32 17, metadata !337}
!337 = metadata !{metadata !338}
!338 = metadata !{metadata !"curvmStubsPH3Z2.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!339 = metadata !{metadata !340}
!340 = metadata !{i32 0, i32 17, metadata !341}
!341 = metadata !{metadata !342}
!342 = metadata !{metadata !"curvmStubsPH3Z2.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!343 = metadata !{metadata !344}
!344 = metadata !{i32 0, i32 17, metadata !345}
!345 = metadata !{metadata !346}
!346 = metadata !{metadata !"curvmStubsPH3Z2.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!347 = metadata !{metadata !348}
!348 = metadata !{i32 0, i32 17, metadata !349}
!349 = metadata !{metadata !350}
!350 = metadata !{metadata !"curvmStubsPH3Z2.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!351 = metadata !{metadata !352}
!352 = metadata !{i32 0, i32 17, metadata !353}
!353 = metadata !{metadata !354}
!354 = metadata !{metadata !"curvmStubsPH3Z2.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!355 = metadata !{metadata !356}
!356 = metadata !{i32 0, i32 17, metadata !357}
!357 = metadata !{metadata !358}
!358 = metadata !{metadata !"curvmStubsPH2Z2.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!359 = metadata !{metadata !360}
!360 = metadata !{i32 0, i32 17, metadata !361}
!361 = metadata !{metadata !362}
!362 = metadata !{metadata !"curvmStubsPH2Z2.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!363 = metadata !{metadata !364}
!364 = metadata !{i32 0, i32 17, metadata !365}
!365 = metadata !{metadata !366}
!366 = metadata !{metadata !"curvmStubsPH2Z2.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!367 = metadata !{metadata !368}
!368 = metadata !{i32 0, i32 17, metadata !369}
!369 = metadata !{metadata !370}
!370 = metadata !{metadata !"curvmStubsPH2Z2.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!371 = metadata !{metadata !372}
!372 = metadata !{i32 0, i32 17, metadata !373}
!373 = metadata !{metadata !374}
!374 = metadata !{metadata !"curvmStubsPH2Z2.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!375 = metadata !{metadata !376}
!376 = metadata !{i32 0, i32 17, metadata !377}
!377 = metadata !{metadata !378}
!378 = metadata !{metadata !"curvmStubsPH1Z2.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!379 = metadata !{metadata !380}
!380 = metadata !{i32 0, i32 17, metadata !381}
!381 = metadata !{metadata !382}
!382 = metadata !{metadata !"curvmStubsPH1Z2.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!383 = metadata !{metadata !384}
!384 = metadata !{i32 0, i32 17, metadata !385}
!385 = metadata !{metadata !386}
!386 = metadata !{metadata !"curvmStubsPH1Z2.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!387 = metadata !{metadata !388}
!388 = metadata !{i32 0, i32 17, metadata !389}
!389 = metadata !{metadata !390}
!390 = metadata !{metadata !"curvmStubsPH1Z2.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!391 = metadata !{metadata !392}
!392 = metadata !{i32 0, i32 17, metadata !393}
!393 = metadata !{metadata !394}
!394 = metadata !{metadata !"curvmStubsPH1Z2.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!395 = metadata !{metadata !396}
!396 = metadata !{i32 0, i32 17, metadata !397}
!397 = metadata !{metadata !398}
!398 = metadata !{metadata !"curvmStubsPH4Z1.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!399 = metadata !{metadata !400}
!400 = metadata !{i32 0, i32 17, metadata !401}
!401 = metadata !{metadata !402}
!402 = metadata !{metadata !"curvmStubsPH4Z1.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!403 = metadata !{metadata !404}
!404 = metadata !{i32 0, i32 17, metadata !405}
!405 = metadata !{metadata !406}
!406 = metadata !{metadata !"curvmStubsPH4Z1.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!407 = metadata !{metadata !408}
!408 = metadata !{i32 0, i32 17, metadata !409}
!409 = metadata !{metadata !410}
!410 = metadata !{metadata !"curvmStubsPH4Z1.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!411 = metadata !{metadata !412}
!412 = metadata !{i32 0, i32 17, metadata !413}
!413 = metadata !{metadata !414}
!414 = metadata !{metadata !"curvmStubsPH4Z1.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!415 = metadata !{metadata !416}
!416 = metadata !{i32 0, i32 17, metadata !417}
!417 = metadata !{metadata !418}
!418 = metadata !{metadata !"curvmStubsPH3Z1.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!419 = metadata !{metadata !420}
!420 = metadata !{i32 0, i32 17, metadata !421}
!421 = metadata !{metadata !422}
!422 = metadata !{metadata !"curvmStubsPH3Z1.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!423 = metadata !{metadata !424}
!424 = metadata !{i32 0, i32 17, metadata !425}
!425 = metadata !{metadata !426}
!426 = metadata !{metadata !"curvmStubsPH3Z1.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!427 = metadata !{metadata !428}
!428 = metadata !{i32 0, i32 17, metadata !429}
!429 = metadata !{metadata !430}
!430 = metadata !{metadata !"curvmStubsPH3Z1.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!431 = metadata !{metadata !432}
!432 = metadata !{i32 0, i32 17, metadata !433}
!433 = metadata !{metadata !434}
!434 = metadata !{metadata !"curvmStubsPH3Z1.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!435 = metadata !{metadata !436}
!436 = metadata !{i32 0, i32 17, metadata !437}
!437 = metadata !{metadata !438}
!438 = metadata !{metadata !"curvmStubsPH2Z1.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!439 = metadata !{metadata !440}
!440 = metadata !{i32 0, i32 17, metadata !441}
!441 = metadata !{metadata !442}
!442 = metadata !{metadata !"curvmStubsPH2Z1.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!443 = metadata !{metadata !444}
!444 = metadata !{i32 0, i32 17, metadata !445}
!445 = metadata !{metadata !446}
!446 = metadata !{metadata !"curvmStubsPH2Z1.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!447 = metadata !{metadata !448}
!448 = metadata !{i32 0, i32 17, metadata !449}
!449 = metadata !{metadata !450}
!450 = metadata !{metadata !"curvmStubsPH2Z1.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!451 = metadata !{metadata !452}
!452 = metadata !{i32 0, i32 17, metadata !453}
!453 = metadata !{metadata !454}
!454 = metadata !{metadata !"curvmStubsPH2Z1.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!455 = metadata !{metadata !456}
!456 = metadata !{i32 0, i32 17, metadata !457}
!457 = metadata !{metadata !458}
!458 = metadata !{metadata !"curvmStubsPH1Z1.data_.V", metadata !309, metadata !"uint18", i32 0, i32 17}
!459 = metadata !{metadata !460}
!460 = metadata !{i32 0, i32 17, metadata !461}
!461 = metadata !{metadata !462}
!462 = metadata !{metadata !"curvmStubsPH1Z1.data_.V", metadata !315, metadata !"uint18", i32 0, i32 17}
!463 = metadata !{metadata !464}
!464 = metadata !{i32 0, i32 17, metadata !465}
!465 = metadata !{metadata !466}
!466 = metadata !{metadata !"curvmStubsPH1Z1.data_.V", metadata !321, metadata !"uint18", i32 0, i32 17}
!467 = metadata !{metadata !468}
!468 = metadata !{i32 0, i32 17, metadata !469}
!469 = metadata !{metadata !470}
!470 = metadata !{metadata !"curvmStubsPH1Z1.data_.V", metadata !327, metadata !"uint18", i32 0, i32 17}
!471 = metadata !{metadata !472}
!472 = metadata !{i32 0, i32 17, metadata !473}
!473 = metadata !{metadata !474}
!474 = metadata !{metadata !"curvmStubsPH1Z1.data_.V", metadata !333, metadata !"uint18", i32 0, i32 17}
!475 = metadata !{metadata !476}
!476 = metadata !{i32 0, i32 35, metadata !477}
!477 = metadata !{metadata !478}
!478 = metadata !{metadata !"curAllStubs.data_.V", metadata !309, metadata !"uint36", i32 0, i32 35}
!479 = metadata !{metadata !480}
!480 = metadata !{i32 0, i32 35, metadata !481}
!481 = metadata !{metadata !482}
!482 = metadata !{metadata !"curAllStubs.data_.V", metadata !315, metadata !"uint36", i32 0, i32 35}
!483 = metadata !{metadata !484}
!484 = metadata !{i32 0, i32 35, metadata !485}
!485 = metadata !{metadata !486}
!486 = metadata !{metadata !"curAllStubs.data_.V", metadata !321, metadata !"uint36", i32 0, i32 35}
!487 = metadata !{metadata !488}
!488 = metadata !{i32 0, i32 35, metadata !489}
!489 = metadata !{metadata !490}
!490 = metadata !{metadata !"curAllStubs.data_.V", metadata !327, metadata !"uint36", i32 0, i32 35}
!491 = metadata !{metadata !492}
!492 = metadata !{i32 0, i32 35, metadata !493}
!493 = metadata !{metadata !494}
!494 = metadata !{metadata !"curAllStubs.data_.V", metadata !333, metadata !"uint36", i32 0, i32 35}
!495 = metadata !{metadata !496}
!496 = metadata !{i32 0, i32 35, metadata !497}
!497 = metadata !{metadata !498}
!498 = metadata !{metadata !"curStubsInLayer.data_.V", metadata !309, metadata !"uint36", i32 0, i32 35}
!499 = metadata !{metadata !500}
!500 = metadata !{i32 0, i32 35, metadata !501}
!501 = metadata !{metadata !502}
!502 = metadata !{metadata !"curStubsInLayer.data_.V", metadata !315, metadata !"uint36", i32 0, i32 35}
!503 = metadata !{metadata !504}
!504 = metadata !{i32 0, i32 35, metadata !505}
!505 = metadata !{metadata !506}
!506 = metadata !{metadata !"curStubsInLayer.data_.V", metadata !321, metadata !"uint36", i32 0, i32 35}
!507 = metadata !{metadata !508}
!508 = metadata !{i32 0, i32 35, metadata !509}
!509 = metadata !{metadata !510}
!510 = metadata !{metadata !"curStubsInLayer.data_.V", metadata !327, metadata !"uint36", i32 0, i32 35}
!511 = metadata !{metadata !512}
!512 = metadata !{i32 0, i32 35, metadata !513}
!513 = metadata !{metadata !514}
!514 = metadata !{metadata !"curStubsInLayer.data_.V", metadata !333, metadata !"uint36", i32 0, i32 35}
