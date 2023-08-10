"surf_subset" is a subset of files from the [SURF repo](https://github.com/slaclab/surf) (SLAC Ultimate RTL Framework)

SURF is an open-source VHDL library for FPGA development, containing VHDL-based IPs for common modules such as
* FIFOs
* AXI4-Stream elements
* Synchronization elements
* etc.

developed and mantained by SLAC, TID-ID Electronics System Department.

The use of SURF library allows the user to implement these components without having to develop them themselfs or rely on Xilinx IP-cores.

This allows to keep under control the resource usage and timing (being open-source VHDL-based components) as well as reduce compile time (No need to synthesize the IP cores firsthand).

The surf FIFO has been sligtly modified in order to only use a subset of SURF instead of the whole repo. 
The possibility of instantiating a Xpm Fifo or a native Altera FIFO has been removed (commented out) from the Fifo.vhd file.
