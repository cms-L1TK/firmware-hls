--===========================================================================
--! @file
--! @brief 2-page memory module which stores data between the algorithm steps 
--         in the Hybrid L1 Tracking algorithm. Based on the Memory.v module. 
--! @author robert.glein@colorado.edu
--! @date 2021-01-05
--! @version v.1.0
--===========================================================================

--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;
--! Standard functions
library std;
--! Standard TextIO functions
use std.textio.all;

--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.tf_pkg.all;

entity tf_mem is
  generic (
    RAM_WIDTH       : natural := 18;               --! Specify RAM data width
    RAM_DEPTH       : natural := 1024;             --! Specify RAM depth (number of entries)
    INIT_FILE       : string := "";                --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : boolean := true;             --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE" --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
    );
  port (
    clka    : in  std_logic;                                      --! Write clock
    clkb    : in  std_logic;                                      --! Read clock
    wea     : in  std_logic;                                      --! Write enable
    enb     : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    rstb    : in  std_logic;                                      --! Output reset (does not affect memory contents)
    regceb  : in  std_logic;                                      --! Output register enable
    addra   : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Write address bus, width determined from RAM_DEPTH
    dina    : in  std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM input data
    addrb   : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    doutb   : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    nent_o  : out t_arr8_8b                                       --! Num entries per page
    );
end tf_mem;

architecture rtl of tf_mem is

-- ########################### Types ###########################
type t_arr_1d_slv_mem is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0); --! 1D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem. Needed here because of variable slv width!
impure function read_tf_mem_data (
file_path : string;      --! File path as string
hex_val   : boolean)     --! Read file vales as hex or bin
return t_arr_1d_slv_mem is --! Dataarray with read values
  file     file_in  : text open READ_MODE is file_path;                -- Text - a file of character strings
  variable line_in  : line;                                            -- Line - one string from a text file
  variable char     : character;                                       -- Character
  variable i_bx_row : integer;                                         -- Read row index
  variable data_arr : t_arr_1d_slv_mem := (others => (others => '0')); -- Output RAM array
begin
 i_bx_row := 0; -- Init
 l_rd_row : while not endfile(file_in) loop -- Read until EoF
   readline (file_in, line_in);
   if (hex_val=true) then
     if (line_in'length > 1) then
       read(line_in, char); read(line_in, char); -- Read '0' and 'x' chars
       hread(line_in, data_arr(i_bx_row)(RAM_WIDTH-1 downto 0)); -- Read value as hex slv (line_in'length in hex)
     else
       data_arr(i_bx_row) := (others => '0');
     end if;
   else
     read(line_in, data_arr(i_bx_row)(RAM_WIDTH-1 downto 0)); -- Read value as bin slv
   end if;
   i_bx_row := i_bx_row +1;
 end loop l_rd_row;
 file_close(file_in);
 return data_arr;
end read_tf_mem_data;

-- ########################### Signals ###########################
signal sa_RAM_data : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX); --! RAM data content
signal sv_RAM_row  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');  --! RAM data row
signal sa_nent     : t_arr8_8b;                                                 --! Number of entries

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data : signal is "block";

begin

-- The following code either initializes the memory values to a specified file or to all zeros to match hardware
process(clka)
begin
  if rising_edge(clka) then
    if (wea='1') then
      sa_RAM_data(to_integer(unsigned(addra))) <= dina;
    end if;
    --MAX_ENTRIES
  end if;
end process init_mem;

  
  --generate
  --  if (INIT_FILE != "") begin: use_init_file
  --    initial
  --      if (INIT_HEX)
  --          $readmemh(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
  --      else
  --          $readmemb(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
  --  end else begin: init_bram_to_zero
  --    integer ram_index;
  --    initial
  --      for (ram_index = 0; ram_index < RAM_DEPTH; ram_index = ram_index + 1)
  --        BRAM[ram_index] = {RAM_WIDTH{1'b0}};
  --  end
  --endgenerate


--  always @(posedge clka) begin
--    if (wea) begin
--      BRAM[addra] <= dina;
--    end
--  end


--  generate 
--    if (COUNT_NENT == 0) begin // Use nent input ports
--      always @(posedge clka) begin
--        if (nent_we0)
--          nent[0] <= nent_i0;
--        if (nent_we1)
--          nent[1] <= nent_i1;
--        if (nent_we2)
--          nent[2] <= nent_i2;
--        if (nent_we3)
--          nent[3] <= nent_i3;
--        if (nent_we4)
--          nent[4] <= nent_i4;
--        if (nent_we5)
--          nent[5] <= nent_i5;
--        if (nent_we6)
--          nent[6] <= nent_i6;
--        if (nent_we7)
--          nent[7] <= nent_i7;
--      end
--    end else begin // Count number of entries internally 
--      always @(posedge clka) begin
--        if (wea) begin
--          case (addra) inside
--           [1:0]: reg_out <= data_a;
--           [3:2]: reg_out <= data_b;
--          endcase
--          nent <= nent+1;
--        end
--      end
--    end
--  endgenerate


--  always @(posedge clkb)
--    if (enb)
--    begin
--      ram_data <= BRAM[addrb];
--    end

--  assign nent_o0 = nent[0];
--  assign nent_o1 = nent[1];
--  assign nent_o2 = nent[2];
--  assign nent_o3 = nent[3];
--  assign nent_o4 = nent[4];
--  assign nent_o5 = nent[5];
--  assign nent_o6 = nent[6];
--  assign nent_o7 = nent[7];

--  //  The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
--  generate
--    if (RAM_PERFORMANCE == "LOW_LATENCY") begin: no_output_register

--      // The following is a 1 clock cycle read latency at the cost of a longer clock-to-out timing
--       assign doutb = ram_data;

--    end else begin: output_register

--      // The following is a 2 clock cycle read latency with improve clock-to-out timing

--      reg [RAM_WIDTH-1:0] doutb_reg = {RAM_WIDTH{1'b0}};

--      always @(posedge clkb)
--        if (rstb)
--          doutb_reg <= {RAM_WIDTH{1'b0}};
--        else if (regceb)
--          doutb_reg <= ram_data;

--      assign doutb = doutb_reg;

--    end
--  endgenerate


--endmodule

end rtl;