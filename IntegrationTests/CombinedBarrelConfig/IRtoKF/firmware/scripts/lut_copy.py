import argparse

# Create argument parser
parser = argparse.ArgumentParser(description="Add pre synth instructions.")

# Optional arguments
parser.add_argument("-s", "--pre_synth_file", dest="preSynthPath", help="pre-synth file", type=str, default="../../../../../emp-fwk/components/info/firmware/cfg/set_generics_presynth.tcl")

# Parse arguments
args = parser.parse_args()

# Already added the line?
with open(args.preSynthPath) as psf:
    for line in psf:
        pass
    last_line = line

# Add lines
if (last_line != "# LUTs added"):
    with open(args.preSynthPath, "a") as presynth_file:
        presynth_file.write("\n# Copy LUTs to xsim or synth_1 directory")
        presynth_file.write("\nfile delete -force ./LUTs")
        presynth_file.write("\nfile copy -force ../../../../../src/firmware-hls/emData/LUTsCMBarrel ./LUTs")
        presynth_file.write("\n# LUTs added")
