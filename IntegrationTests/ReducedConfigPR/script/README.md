### Synthesis

Recipe for synthesizing the project:
```bash
./compileHLS.sh
vivado -mode tcl -source ./makeProject.tcl
vivado -mode tcl -source ../../common/script/synth.tcl
```

### Simulation

Recipe for simulating the project:
```bash
# follow the above recipe for synthesis
vivado -mode tcl -source ./runSim.tcl
```
