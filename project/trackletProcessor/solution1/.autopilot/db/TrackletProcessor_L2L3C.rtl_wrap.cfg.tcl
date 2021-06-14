set lang "C++"
set moduleName "TrackletProcessor_L2L3C"
set moduleIsExternC "0"
set rawDecl ""
set globalVariable ""
set PortList ""
set PortName0 "bx"
set BitWidth0 "8"
set ArrayOpt0 ""
set Const0 "1"
set Volatile0 "0"
set Pointer0 "0"
set Reference0 "0"
set Dims0 [list 0]
set Interface0 "wire"
set DataType0 "[list ap_uint 3 ]"
set Port0 [list $PortName0 $Interface0 $DataType0 $Pointer0 $Dims0 $Const0 $Volatile0 $ArrayOpt0]
lappend PortList $Port0
set PortName1 "lut"
set BitWidth1 "64"
set ArrayOpt1 ""
set Const1 "1"
set Volatile1 "0"
set Pointer1 "0"
set Reference1 "0"
set Dims1 [list 2048]
set Interface1 "wire"
set DataType1 "[list ap_uint 10 ]"
set Port1 [list $PortName1 $Interface1 $DataType1 $Pointer1 $Dims1 $Const1 $Volatile1 $ArrayOpt1]
lappend PortList $Port1
set PortName2 "regionlut"
set BitWidth2 "64"
set ArrayOpt2 ""
set Const2 "1"
set Volatile2 "0"
set Pointer2 "0"
set Reference2 "0"
set Dims2 [list 2048]
set Interface2 "wire"
set DataType2 "[list ap_uint 8 ]"
set Port2 [list $PortName2 $Interface2 $DataType2 $Pointer2 $Dims2 $Const2 $Volatile2 $ArrayOpt2]
lappend PortList $Port2
set PortName3 "innerStubs"
set BitWidth3 "64"
set ArrayOpt3 ""
set Const3 "1"
set Volatile3 "0"
set Pointer3 "0"
set Reference3 "0"
set Dims3 [list 3]
set Interface3 "wire"
set structMem3 ""
set PortName30 "dataarray_"
set BitWidth30 "65536"
set ArrayOpt30 ""
set Const30 "0"
set Volatile30 "0"
set Pointer30 "0"
set Reference30 "0"
set Dims30 [list  8 128]
set Interface30 "wire"
set structMem30 ""
set PortName300 "data_"
set BitWidth300 "64"
set ArrayOpt300 ""
set Const300 "0"
set Volatile300 "0"
set Pointer300 "0"
set Reference300 "0"
set Dims300 [list 0]
set Interface300 "wire"
set DataType300 "[list ap_uint 51 ]"
set Port300 [list $PortName300 $Interface300 $DataType300 $Pointer300 $Dims300 $Const300 $Volatile300 $ArrayOpt300]
lappend structMem30 $Port300
set DataType30tp0 "int"
set structParameter30 [list [list $DataType30tp0 ASType] ]
set structArgument30 [list 0 ]
set NameSpace30 [list ]
set structIsPacked30 "0"
set DataType30 [list "AllStubInner<0>" "struct AllStubInner" $structMem30 1 0 $structParameter30 $structArgument30 $NameSpace30 $structIsPacked30]
set Port30 [list $PortName30 $Interface30 $DataType30 $Pointer30 $Dims30 $Const30 $Volatile30 $ArrayOpt30]
lappend structMem3 $Port30
set PortName31 "nentries_"
set BitWidth31 "64"
set ArrayOpt31 ""
set Const31 "0"
set Volatile31 "0"
set Pointer31 "0"
set Reference31 "0"
set Dims31 [list  8]
set Interface31 "wire"
set DataType31 "[list ap_uint 7 ]"
set Port31 [list $PortName31 $Interface31 $DataType31 $Pointer31 $Dims31 $Const31 $Volatile31 $ArrayOpt31]
lappend structMem3 $Port31
set DataType3tp1 "unsigned int"
set DataType3tp2 "unsigned int"
set structParameter3 [list [list typename DataType] [list $DataType3tp1 NBIT_BX] [list $DataType3tp2 NBIT_ADDR] ]
set structMem3ta0 ""
set PortName3ta00 "data_"
set BitWidth3ta00 "64"
set ArrayOpt3ta00 ""
set Const3ta00 "0"
set Volatile3ta00 "0"
set Pointer3ta00 "0"
set Reference3ta00 "0"
set Dims3ta00 [list 0]
set Interface3ta00 "wire"
set DataType3ta00 "[list ap_uint 51 ]"
set Port3ta00 [list $PortName3ta00 $Interface3ta00 $DataType3ta00 $Pointer3ta00 $Dims3ta00 $Const3ta00 $Volatile3ta00 $ArrayOpt3ta00]
lappend structMem3ta0 $Port3ta00
set DataType3ta0tp0 "int"
set structParameter3ta0 [list [list $DataType3ta0tp0 ASType] ]
set structArgument3ta0 [list 0 ]
set NameSpace3ta0 [list ]
set structIsPacked3ta0 "0"
set DataType3ta0 [list "AllStubInner<0>" "struct AllStubInner" $structMem3ta0 1 0 $structParameter3ta0 $structArgument3ta0 $NameSpace3ta0 $structIsPacked3ta0]
set structArgument3 [list $DataType3ta0 3 7 ]
set NameSpace3 [list ]
set structIsPacked3 "0"
set DataType3 [list "MemoryTemplate<AllStubInner<0>, 3, 7>" "struct MemoryTemplate" $structMem3 1 0 $structParameter3 $structArgument3 $NameSpace3 $structIsPacked3]
set Port3 [list $PortName3 $Interface3 $DataType3 $Pointer3 $Dims3 $Const3 $Volatile3 $ArrayOpt3]
lappend PortList $Port3
set PortName4 "outerStubs"
set BitWidth4 "64"
set ArrayOpt4 ""
set Const4 "1"
set Volatile4 "0"
set Pointer4 "1"
set Reference4 "0"
set Dims4 [list 0]
set Interface4 "wire"
set structMem4 ""
set PortName40 "dataarray_"
set BitWidth40 "65536"
set ArrayOpt40 ""
set Const40 "0"
set Volatile40 "0"
set Pointer40 "0"
set Reference40 "0"
set Dims40 [list  8 128]
set Interface40 "wire"
set structMem40 ""
set PortName400 "data_"
set BitWidth400 "64"
set ArrayOpt400 ""
set Const400 "0"
set Volatile400 "0"
set Pointer400 "0"
set Reference400 "0"
set Dims400 [list 0]
set Interface400 "wire"
set DataType400 "[list ap_uint 36 ]"
set Port400 [list $PortName400 $Interface400 $DataType400 $Pointer400 $Dims400 $Const400 $Volatile400 $ArrayOpt400]
lappend structMem40 $Port400
set DataType40tp0 "int"
set structParameter40 [list [list $DataType40tp0 ASType] ]
set structArgument40 [list 0 ]
set NameSpace40 [list ]
set structIsPacked40 "0"
set DataType40 [list "AllStub<0>" "struct AllStub" $structMem40 1 0 $structParameter40 $structArgument40 $NameSpace40 $structIsPacked40]
set Port40 [list $PortName40 $Interface40 $DataType40 $Pointer40 $Dims40 $Const40 $Volatile40 $ArrayOpt40]
lappend structMem4 $Port40
set PortName41 "nentries_"
set BitWidth41 "64"
set ArrayOpt41 ""
set Const41 "0"
set Volatile41 "0"
set Pointer41 "0"
set Reference41 "0"
set Dims41 [list  8]
set Interface41 "wire"
set DataType41 "[list ap_uint 7 ]"
set Port41 [list $PortName41 $Interface41 $DataType41 $Pointer41 $Dims41 $Const41 $Volatile41 $ArrayOpt41]
lappend structMem4 $Port41
set DataType4tp1 "unsigned int"
set DataType4tp2 "unsigned int"
set structParameter4 [list [list typename DataType] [list $DataType4tp1 NBIT_BX] [list $DataType4tp2 NBIT_ADDR] ]
set structMem4ta0 ""
set PortName4ta00 "data_"
set BitWidth4ta00 "64"
set ArrayOpt4ta00 ""
set Const4ta00 "0"
set Volatile4ta00 "0"
set Pointer4ta00 "0"
set Reference4ta00 "0"
set Dims4ta00 [list 0]
set Interface4ta00 "wire"
set DataType4ta00 "[list ap_uint 36 ]"
set Port4ta00 [list $PortName4ta00 $Interface4ta00 $DataType4ta00 $Pointer4ta00 $Dims4ta00 $Const4ta00 $Volatile4ta00 $ArrayOpt4ta00]
lappend structMem4ta0 $Port4ta00
set DataType4ta0tp0 "int"
set structParameter4ta0 [list [list $DataType4ta0tp0 ASType] ]
set structArgument4ta0 [list 0 ]
set NameSpace4ta0 [list ]
set structIsPacked4ta0 "0"
set DataType4ta0 [list "AllStub<0>" "struct AllStub" $structMem4ta0 1 0 $structParameter4ta0 $structArgument4ta0 $NameSpace4ta0 $structIsPacked4ta0]
set structArgument4 [list $DataType4ta0 3 7 ]
set NameSpace4 [list ]
set structIsPacked4 "0"
set DataType4 [list "MemoryTemplate<AllStub<0>, 3, 7>" "struct MemoryTemplate" $structMem4 1 0 $structParameter4 $structArgument4 $NameSpace4 $structIsPacked4]
set Port4 [list $PortName4 $Interface4 $DataType4 $Pointer4 $Dims4 $Const4 $Volatile4 $ArrayOpt4]
lappend PortList $Port4
set PortName5 "outerVMStubs"
set BitWidth5 "66176"
set ArrayOpt5 ""
set Const5 "1"
set Volatile5 "0"
set Pointer5 "0"
set Reference5 "0"
set Dims5 [list 0]
set Interface5 "wire"
set structMem5 ""
set PortName50 "dataarray_"
set BitWidth50 "65536"
set ArrayOpt50 ""
set Const50 "0"
set Volatile50 "0"
set Pointer50 "0"
set Reference50 "0"
set Dims50 [list  2 2 1024]
set Interface50 "wire"
set structMem50 ""
set PortName500 "data_"
set BitWidth500 "16"
set ArrayOpt500 ""
set Const500 "0"
set Volatile500 "0"
set Pointer500 "0"
set Reference500 "0"
set Dims500 [list 0]
set Interface500 "wire"
set DataType500 "[list ap_uint 16 ]"
set Port500 [list $PortName500 $Interface500 $DataType500 $Pointer500 $Dims500 $Const500 $Volatile500 $ArrayOpt500]
lappend structMem50 $Port500
set DataType50tp0 "int"
set structParameter50 [list [list $DataType50tp0 VMSTEOType] ]
set structArgument50 [list 0 ]
set NameSpace50 [list ]
set structIsPacked50 "0"
set DataType50 [list "VMStubTEOuter<0>" "struct VMStubTEOuter" $structMem50 1 0 $structParameter50 $structArgument50 $NameSpace50 $structIsPacked50]
set Port50 [list $PortName50 $Interface50 $DataType50 $Pointer50 $Dims50 $Const50 $Volatile50 $ArrayOpt50]
lappend structMem5 $Port50
set PortName51 "binmask8_"
set BitWidth51 "128"
set ArrayOpt51 ""
set Const51 "0"
set Volatile51 "0"
set Pointer51 "0"
set Reference51 "0"
set Dims51 [list  2 8]
set Interface51 "wire"
set DataType51 "[list ap_uint 8 ]"
set Port51 [list $PortName51 $Interface51 $DataType51 $Pointer51 $Dims51 $Const51 $Volatile51 $ArrayOpt51]
lappend structMem5 $Port51
set PortName52 "nentries8_"
set BitWidth52 "512"
set ArrayOpt52 ""
set Const52 "0"
set Volatile52 "0"
set Pointer52 "0"
set Reference52 "0"
set Dims52 [list  2 8]
set Interface52 "wire"
set DataType52 "[list ap_uint 32 ]"
set Port52 [list $PortName52 $Interface52 $DataType52 $Pointer52 $Dims52 $Const52 $Volatile52 $ArrayOpt52]
lappend structMem5 $Port52
set DataType5tp1 "unsigned int"
set DataType5tp2 "unsigned int"
set DataType5tp3 "unsigned int"
set DataType5tp4 "unsigned int"
set structParameter5 [list [list typename DataType] [list $DataType5tp1 NBIT_BX] [list $DataType5tp2 NBIT_ADDR] [list $DataType5tp3 NBIT_BIN] [list $DataType5tp4 NCOPY] ]
set structMem5ta0 ""
set PortName5ta00 "data_"
set BitWidth5ta00 "16"
set ArrayOpt5ta00 ""
set Const5ta00 "0"
set Volatile5ta00 "0"
set Pointer5ta00 "0"
set Reference5ta00 "0"
set Dims5ta00 [list 0]
set Interface5ta00 "wire"
set DataType5ta00 "[list ap_uint 16 ]"
set Port5ta00 [list $PortName5ta00 $Interface5ta00 $DataType5ta00 $Pointer5ta00 $Dims5ta00 $Const5ta00 $Volatile5ta00 $ArrayOpt5ta00]
lappend structMem5ta0 $Port5ta00
set DataType5ta0tp0 "int"
set structParameter5ta0 [list [list $DataType5ta0tp0 VMSTEOType] ]
set structArgument5ta0 [list 0 ]
set NameSpace5ta0 [list ]
set structIsPacked5ta0 "0"
set DataType5ta0 [list "VMStubTEOuter<0>" "struct VMStubTEOuter" $structMem5ta0 1 0 $structParameter5ta0 $structArgument5ta0 $NameSpace5ta0 $structIsPacked5ta0]
set structArgument5 [list $DataType5ta0 1 10 6 2 ]
set NameSpace5 [list ]
set structIsPacked5 "0"
set DataType5 [list "MemoryTemplateBinnedCM<VMStubTEOuter<0>, 1, 10, 6, 2>" "struct MemoryTemplateBinnedCM" $structMem5 1 0 $structParameter5 $structArgument5 $NameSpace5 $structIsPacked5]
set Port5 [list $PortName5 $Interface5 $DataType5 $Pointer5 $Dims5 $Const5 $Volatile5 $ArrayOpt5]
lappend PortList $Port5
set PortName6 "trackletParameters"
set BitWidth6 "64"
set ArrayOpt6 ""
set Const6 "0"
set Volatile6 "0"
set Pointer6 "1"
set Reference6 "0"
set Dims6 [list 0]
set Interface6 "wire"
set structMem6 ""
set PortName60 "dataarray_"
set BitWidth60 "131072"
set ArrayOpt60 ""
set Const60 "0"
set Volatile60 "0"
set Pointer60 "0"
set Reference60 "0"
set Dims60 [list  8 128]
set Interface60 "wire"
set structMem60 ""
set PortName600 "data_"
set BitWidth600 "128"
set ArrayOpt600 ""
set Const600 "0"
set Volatile600 "0"
set Pointer600 "0"
set Reference600 "0"
set Dims600 [list 0]
set Interface600 "wire"
set DataType600 "[list ap_uint 70 ]"
set Port600 [list $PortName600 $Interface600 $DataType600 $Pointer600 $Dims600 $Const600 $Volatile600 $ArrayOpt600]
lappend structMem60 $Port600
set structParameter60 [list ]
set structArgument60 [list ]
set NameSpace60 [list ]
set structIsPacked60 "0"
set DataType60 [list "TrackletParameters" "struct TrackletParameters" $structMem60 1 0 $structParameter60 $structArgument60 $NameSpace60 $structIsPacked60]
set Port60 [list $PortName60 $Interface60 $DataType60 $Pointer60 $Dims60 $Const60 $Volatile60 $ArrayOpt60]
lappend structMem6 $Port60
set PortName61 "nentries_"
set BitWidth61 "64"
set ArrayOpt61 ""
set Const61 "0"
set Volatile61 "0"
set Pointer61 "0"
set Reference61 "0"
set Dims61 [list  8]
set Interface61 "wire"
set DataType61 "[list ap_uint 7 ]"
set Port61 [list $PortName61 $Interface61 $DataType61 $Pointer61 $Dims61 $Const61 $Volatile61 $ArrayOpt61]
lappend structMem6 $Port61
set DataType6tp1 "unsigned int"
set DataType6tp2 "unsigned int"
set structParameter6 [list [list typename DataType] [list $DataType6tp1 NBIT_BX] [list $DataType6tp2 NBIT_ADDR] ]
set structMem6ta0 ""
set PortName6ta00 "data_"
set BitWidth6ta00 "128"
set ArrayOpt6ta00 ""
set Const6ta00 "0"
set Volatile6ta00 "0"
set Pointer6ta00 "0"
set Reference6ta00 "0"
set Dims6ta00 [list 0]
set Interface6ta00 "wire"
set DataType6ta00 "[list ap_uint 70 ]"
set Port6ta00 [list $PortName6ta00 $Interface6ta00 $DataType6ta00 $Pointer6ta00 $Dims6ta00 $Const6ta00 $Volatile6ta00 $ArrayOpt6ta00]
lappend structMem6ta0 $Port6ta00
set structParameter6ta0 [list ]
set structArgument6ta0 [list ]
set NameSpace6ta0 [list ]
set structIsPacked6ta0 "0"
set DataType6ta0 [list "TrackletParameters" "struct TrackletParameters" $structMem6ta0 1 0 $structParameter6ta0 $structArgument6ta0 $NameSpace6ta0 $structIsPacked6ta0]
set structArgument6 [list $DataType6ta0 3 7 ]
set NameSpace6 [list ]
set structIsPacked6 "0"
set DataType6 [list "MemoryTemplate<TrackletParameters, 3, 7>" "struct MemoryTemplate" $structMem6 0 0 $structParameter6 $structArgument6 $NameSpace6 $structIsPacked6]
set Port6 [list $PortName6 $Interface6 $DataType6 $Pointer6 $Dims6 $Const6 $Volatile6 $ArrayOpt6]
lappend PortList $Port6
set PortName7 "projout_barrel_ps"
set BitWidth7 "64"
set ArrayOpt7 ""
set Const7 "0"
set Volatile7 "0"
set Pointer7 "0"
set Reference7 "0"
set Dims7 [list 16]
set Interface7 "wire"
set structMem7 ""
set PortName70 "dataarray_"
set BitWidth70 "16384"
set ArrayOpt70 ""
set Const70 "0"
set Volatile70 "0"
set Pointer70 "0"
set Reference70 "0"
set Dims70 [list  2 128]
set Interface70 "wire"
set structMem70 ""
set PortName700 "data_"
set BitWidth700 "64"
set ArrayOpt700 ""
set Const700 "0"
set Volatile700 "0"
set Pointer700 "0"
set Reference700 "0"
set Dims700 [list 0]
set Interface700 "wire"
set DataType700 "[list ap_uint 60 ]"
set Port700 [list $PortName700 $Interface700 $DataType700 $Pointer700 $Dims700 $Const700 $Volatile700 $ArrayOpt700]
lappend structMem70 $Port700
set DataType70tp0 "int"
set structParameter70 [list [list $DataType70tp0 TProjType] ]
set structArgument70 [list 0 ]
set NameSpace70 [list ]
set structIsPacked70 "0"
set DataType70 [list "TrackletProjection<0>" "struct TrackletProjection" $structMem70 1 0 $structParameter70 $structArgument70 $NameSpace70 $structIsPacked70]
set Port70 [list $PortName70 $Interface70 $DataType70 $Pointer70 $Dims70 $Const70 $Volatile70 $ArrayOpt70]
lappend structMem7 $Port70
set PortName71 "nentries_"
set BitWidth71 "16"
set ArrayOpt71 ""
set Const71 "0"
set Volatile71 "0"
set Pointer71 "0"
set Reference71 "0"
set Dims71 [list  2]
set Interface71 "wire"
set DataType71 "[list ap_uint 7 ]"
set Port71 [list $PortName71 $Interface71 $DataType71 $Pointer71 $Dims71 $Const71 $Volatile71 $ArrayOpt71]
lappend structMem7 $Port71
set DataType7tp1 "unsigned int"
set DataType7tp2 "unsigned int"
set structParameter7 [list [list typename DataType] [list $DataType7tp1 NBIT_BX] [list $DataType7tp2 NBIT_ADDR] ]
set structMem7ta0 ""
set PortName7ta00 "data_"
set BitWidth7ta00 "64"
set ArrayOpt7ta00 ""
set Const7ta00 "0"
set Volatile7ta00 "0"
set Pointer7ta00 "0"
set Reference7ta00 "0"
set Dims7ta00 [list 0]
set Interface7ta00 "wire"
set DataType7ta00 "[list ap_uint 60 ]"
set Port7ta00 [list $PortName7ta00 $Interface7ta00 $DataType7ta00 $Pointer7ta00 $Dims7ta00 $Const7ta00 $Volatile7ta00 $ArrayOpt7ta00]
lappend structMem7ta0 $Port7ta00
set DataType7ta0tp0 "int"
set structParameter7ta0 [list [list $DataType7ta0tp0 TProjType] ]
set structArgument7ta0 [list 0 ]
set NameSpace7ta0 [list ]
set structIsPacked7ta0 "0"
set DataType7ta0 [list "TrackletProjection<0>" "struct TrackletProjection" $structMem7ta0 1 0 $structParameter7ta0 $structArgument7ta0 $NameSpace7ta0 $structIsPacked7ta0]
set structArgument7 [list $DataType7ta0 1 7 ]
set NameSpace7 [list ]
set structIsPacked7 "0"
set DataType7 [list "MemoryTemplate<TrackletProjection<0>, 1, 7>" "struct MemoryTemplate" $structMem7 1 0 $structParameter7 $structArgument7 $NameSpace7 $structIsPacked7]
set Port7 [list $PortName7 $Interface7 $DataType7 $Pointer7 $Dims7 $Const7 $Volatile7 $ArrayOpt7]
lappend PortList $Port7
set PortName8 "projout_barrel_2s"
set BitWidth8 "64"
set ArrayOpt8 ""
set Const8 "0"
set Volatile8 "0"
set Pointer8 "0"
set Reference8 "0"
set Dims8 [list 12]
set Interface8 "wire"
set structMem8 ""
set PortName80 "dataarray_"
set BitWidth80 "16384"
set ArrayOpt80 ""
set Const80 "0"
set Volatile80 "0"
set Pointer80 "0"
set Reference80 "0"
set Dims80 [list  2 128]
set Interface80 "wire"
set structMem80 ""
set PortName800 "data_"
set BitWidth800 "64"
set ArrayOpt800 ""
set Const800 "0"
set Volatile800 "0"
set Pointer800 "0"
set Reference800 "0"
set Dims800 [list 0]
set Interface800 "wire"
set DataType800 "[list ap_uint 58 ]"
set Port800 [list $PortName800 $Interface800 $DataType800 $Pointer800 $Dims800 $Const800 $Volatile800 $ArrayOpt800]
lappend structMem80 $Port800
set DataType80tp0 "int"
set structParameter80 [list [list $DataType80tp0 TProjType] ]
set structArgument80 [list 1 ]
set NameSpace80 [list ]
set structIsPacked80 "0"
set DataType80 [list "TrackletProjection<1>" "struct TrackletProjection" $structMem80 1 0 $structParameter80 $structArgument80 $NameSpace80 $structIsPacked80]
set Port80 [list $PortName80 $Interface80 $DataType80 $Pointer80 $Dims80 $Const80 $Volatile80 $ArrayOpt80]
lappend structMem8 $Port80
set PortName81 "nentries_"
set BitWidth81 "16"
set ArrayOpt81 ""
set Const81 "0"
set Volatile81 "0"
set Pointer81 "0"
set Reference81 "0"
set Dims81 [list  2]
set Interface81 "wire"
set DataType81 "[list ap_uint 7 ]"
set Port81 [list $PortName81 $Interface81 $DataType81 $Pointer81 $Dims81 $Const81 $Volatile81 $ArrayOpt81]
lappend structMem8 $Port81
set DataType8tp1 "unsigned int"
set DataType8tp2 "unsigned int"
set structParameter8 [list [list typename DataType] [list $DataType8tp1 NBIT_BX] [list $DataType8tp2 NBIT_ADDR] ]
set structMem8ta0 ""
set PortName8ta00 "data_"
set BitWidth8ta00 "64"
set ArrayOpt8ta00 ""
set Const8ta00 "0"
set Volatile8ta00 "0"
set Pointer8ta00 "0"
set Reference8ta00 "0"
set Dims8ta00 [list 0]
set Interface8ta00 "wire"
set DataType8ta00 "[list ap_uint 58 ]"
set Port8ta00 [list $PortName8ta00 $Interface8ta00 $DataType8ta00 $Pointer8ta00 $Dims8ta00 $Const8ta00 $Volatile8ta00 $ArrayOpt8ta00]
lappend structMem8ta0 $Port8ta00
set DataType8ta0tp0 "int"
set structParameter8ta0 [list [list $DataType8ta0tp0 TProjType] ]
set structArgument8ta0 [list 1 ]
set NameSpace8ta0 [list ]
set structIsPacked8ta0 "0"
set DataType8ta0 [list "TrackletProjection<1>" "struct TrackletProjection" $structMem8ta0 1 0 $structParameter8ta0 $structArgument8ta0 $NameSpace8ta0 $structIsPacked8ta0]
set structArgument8 [list $DataType8ta0 1 7 ]
set NameSpace8 [list ]
set structIsPacked8 "0"
set DataType8 [list "MemoryTemplate<TrackletProjection<1>, 1, 7>" "struct MemoryTemplate" $structMem8 1 0 $structParameter8 $structArgument8 $NameSpace8 $structIsPacked8]
set Port8 [list $PortName8 $Interface8 $DataType8 $Pointer8 $Dims8 $Const8 $Volatile8 $ArrayOpt8]
lappend PortList $Port8
set PortName9 "projout_disk"
set BitWidth9 "64"
set ArrayOpt9 ""
set Const9 "0"
set Volatile9 "0"
set Pointer9 "0"
set Reference9 "0"
set Dims9 [list 16]
set Interface9 "wire"
set structMem9 ""
set PortName90 "dataarray_"
set BitWidth90 "16384"
set ArrayOpt90 ""
set Const90 "0"
set Volatile90 "0"
set Pointer90 "0"
set Reference90 "0"
set Dims90 [list  2 128]
set Interface90 "wire"
set structMem90 ""
set PortName900 "data_"
set BitWidth900 "64"
set ArrayOpt900 ""
set Const900 "0"
set Volatile900 "0"
set Pointer900 "0"
set Reference900 "0"
set Dims900 [list 0]
set Interface900 "wire"
set DataType900 "[list ap_uint 59 ]"
set Port900 [list $PortName900 $Interface900 $DataType900 $Pointer900 $Dims900 $Const900 $Volatile900 $ArrayOpt900]
lappend structMem90 $Port900
set DataType90tp0 "int"
set structParameter90 [list [list $DataType90tp0 TProjType] ]
set structArgument90 [list 6 ]
set NameSpace90 [list ]
set structIsPacked90 "0"
set DataType90 [list "TrackletProjection<6>" "struct TrackletProjection" $structMem90 1 0 $structParameter90 $structArgument90 $NameSpace90 $structIsPacked90]
set Port90 [list $PortName90 $Interface90 $DataType90 $Pointer90 $Dims90 $Const90 $Volatile90 $ArrayOpt90]
lappend structMem9 $Port90
set PortName91 "nentries_"
set BitWidth91 "16"
set ArrayOpt91 ""
set Const91 "0"
set Volatile91 "0"
set Pointer91 "0"
set Reference91 "0"
set Dims91 [list  2]
set Interface91 "wire"
set DataType91 "[list ap_uint 7 ]"
set Port91 [list $PortName91 $Interface91 $DataType91 $Pointer91 $Dims91 $Const91 $Volatile91 $ArrayOpt91]
lappend structMem9 $Port91
set DataType9tp1 "unsigned int"
set DataType9tp2 "unsigned int"
set structParameter9 [list [list typename DataType] [list $DataType9tp1 NBIT_BX] [list $DataType9tp2 NBIT_ADDR] ]
set structMem9ta0 ""
set PortName9ta00 "data_"
set BitWidth9ta00 "64"
set ArrayOpt9ta00 ""
set Const9ta00 "0"
set Volatile9ta00 "0"
set Pointer9ta00 "0"
set Reference9ta00 "0"
set Dims9ta00 [list 0]
set Interface9ta00 "wire"
set DataType9ta00 "[list ap_uint 59 ]"
set Port9ta00 [list $PortName9ta00 $Interface9ta00 $DataType9ta00 $Pointer9ta00 $Dims9ta00 $Const9ta00 $Volatile9ta00 $ArrayOpt9ta00]
lappend structMem9ta0 $Port9ta00
set DataType9ta0tp0 "int"
set structParameter9ta0 [list [list $DataType9ta0tp0 TProjType] ]
set structArgument9ta0 [list 6 ]
set NameSpace9ta0 [list ]
set structIsPacked9ta0 "0"
set DataType9ta0 [list "TrackletProjection<6>" "struct TrackletProjection" $structMem9ta0 1 0 $structParameter9ta0 $structArgument9ta0 $NameSpace9ta0 $structIsPacked9ta0]
set structArgument9 [list $DataType9ta0 1 7 ]
set NameSpace9 [list ]
set structIsPacked9 "0"
set DataType9 [list "MemoryTemplate<TrackletProjection<6>, 1, 7>" "struct MemoryTemplate" $structMem9 1 0 $structParameter9 $structArgument9 $NameSpace9 $structIsPacked9]
set Port9 [list $PortName9 $Interface9 $DataType9 $Pointer9 $Dims9 $Const9 $Volatile9 $ArrayOpt9]
lappend PortList $Port9
set globalAPint "" 
set returnAPInt "" 
set hasCPPAPInt 1 
set argAPInt "" 
set hasCPPAPFix 0 
set hasSCFix 0 
set hasCBool 0 
set hasCPPComplex 0 
set isTemplateTop 0
set hasHalf 0 
set dataPackList ""
set module [list $moduleName $PortList $rawDecl $argAPInt $returnAPInt $dataPackList]
