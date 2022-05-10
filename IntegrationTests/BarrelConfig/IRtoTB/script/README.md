## Synthesize and implement project

```bash
vivado_hls -f compileHLS.tcl
vivado -mode batch -source ./makeProject.tcl
vivado -mode batch -source ./common/script/synth.tcl
vivado -mode batch -source ./common/script/impl.tcl
```

## Generate USER_SLR_ASSIGNMENT commands

```bash
cd ../hdl/
./user_slr_assignment.py memUtil_pkg.vhd SectorProcessor.vhd
# copy output to IntegrationTests/common/script/impl.tcl
```
