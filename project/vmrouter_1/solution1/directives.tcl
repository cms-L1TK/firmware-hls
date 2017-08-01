############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_inline "VMRouter"
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH3Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH4Z2
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH1Z1
set_directive_array_partition -type complete -dim 1 "VMRouterDispatcher" nPH2Z2
set_directive_dependence -variable stubsInLayer -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable allStubs -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH1Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH2Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH3Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH4Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH1Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH2Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH3Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable vmStubsPH4Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH1Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH2Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH3Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH4Z1 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH1Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH2Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH3Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
set_directive_dependence -variable nPH4Z2 -type inter -dependent false "VMRouterDispatcher/ROUTERLOOP"
