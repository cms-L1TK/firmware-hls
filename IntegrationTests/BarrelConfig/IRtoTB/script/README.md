## Synthesize and implement project

```bash
make -j `nproc` Work
make Work/Work.runs/synth_1
make Work/Work.runs/impl_1
```

## Generate USER_SLR_ASSIGNMENT commands

```bash
cd ../hdl/
./user_slr_assignment.py memUtil_pkg.vhd SectorProcessor.vhd
# copy output to IntegrationTests/common/hdl/constraints.xdc
```
