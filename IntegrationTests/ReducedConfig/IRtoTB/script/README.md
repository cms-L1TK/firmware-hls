### Synthesis

Recipe for synthesizing the project:
```bash
./compileHLS.sh
vivado -mode tcl -source ./makeProject.tcl
vivado -mode tcl -source ../../common/script/synth.tcl
```

### Simulation

Recipe for simulating the project and comparing the results with those of the emulation:
```bash
# follow the above recipe for synthesis
vivado -mode tcl -source ./runSim.tcl
rm -f dataOut/TW_* dataOut/BW_* # comparison script cannot handle these outputs
python3 ../../common/script/CompareMemPrintsFW.py -p -s
```
