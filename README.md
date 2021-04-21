# Vivado_HLS_AXI_MASTER
A basic project showing a Vivado HLS accelerator, and a baremetal Vivado SDK project to show application use

This project is intended to show people a VERY basic project using the following:

1. An Arty Z7 dev board from Digilent (using the Z7020 processor).

2. Vivado HLS (2019.1): Makes an AXI Master interface that reads an "input array" of float values starting from 
one DDR memory location (the processor side), adds a float value to this, and then writes the result 
"output array" of floats to a different location in DDR memory (back to the processor).  
The "value to add", the "input array" memory location, and the "output array" memory location, and the "size"
of the arrays to read are all specified as parameters from the AXI Lite bus.

3. Vivado 2019: Uses the above accelerator function in a block diagram with an HP port (HP0) of the Zynq processor.

4. Vivado 2019 SDK: Shows a simple baremetal application in C of how to use this accelerator block.
