Recipe for synthesizing the project:
```bash
./compileHLS.sh
vivado -mode tcl -source ./makeProject.tcl
vivado -mode tcl -source ../../common/script/synth.tcl
```
