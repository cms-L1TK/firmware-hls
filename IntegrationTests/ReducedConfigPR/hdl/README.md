Recipe for generating these files:
```bash
git clone -b ir_phibinword_update https://github.com/cms-L1TK/project_generation_scripts.git
git clone https://github.com/cms-L1TK/firmware-hls.git

cd firmware-hls/emData/
./download.sh -t
cd ../../project_generation_scripts/
cp ../firmware-hls/emData/LUTs/*.dat ./

./makeReducedConfig.py -n True
sed -i "s/ PD\.trackin//g" reduced_wires.dat # remove output of TF_L1L2
sed -i '$d' reduced_wires.dat                # remove CT_L1L2 wires
sed -i '$d' reduced_processingmodules.dat    # remove PurgeDuplicates
sed -i '$d' reduced_memorymodules.dat        # remove CleanTrack

# SectorProcessor.vhd
./generator_hdl.py -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat
# SectorProcessorFull.vhd
./generator_hdl.py -w reduced_wires.dat -p reduced_processingmodules.dat -m reduced_memorymodules.dat -x
```
