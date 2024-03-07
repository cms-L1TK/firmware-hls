-------------------------------------------------------------------------------
-- Title      : CDC firmware for slowed down track finding
-- Project    : 
-------------------------------------------------------------------------------
-- File       : emp_cdc.vhd
-- Author     : Michael Oshiro  <moshiro@cornell.edu>
-- Company    : Cornell University
-- Created    : 2023-10-27
-- Last update: 
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: Crosses clock domain to/from EMP datapath and TF firmware
-- Notes      : Currently, hard-coded for EMP links used in barrel FW test
-------------------------------------------------------------------------------
-- Copyright (c) 2023 Cornell University
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author   Description
-- 2023-10-27  1.0      mcoshiro Created
-------------------------------------------------------------------------------
library ieee;
library UNISIM;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.emp_data_types.all;
use work.emp_device_decl.all;
use work.emp_ttc_decl.all;
use work.tf_pkg.all;
use work.memUtil_pkg.all;
use UNISIM.vcomponents.all;

entity emp_cdc is
  generic (
    channel_first        : integer range 0 to (4*N_REGION-1) := 68;
    channel_last         : integer range 0 to (4*N_REGION-1) := 107
    );
  port (
    clk_i                : in  std_logic;
    clk_o                : in  std_logic;
    rst_i                : in  std_logic;
    din_i                : in  ldata(4 * N_REGION - 1 downto 0);
    din_o                : out ldata(4 * N_REGION - 1 downto 0);
    rst_o                : out std_logic
    );
end entity emp_cdc;

architecture rtl of emp_cdc is

  type arr_fifodout is array(channel_last downto channel_first) of std_logic_vector(63 downto 0);
  type arr_fifodoutp is array(channel_last downto channel_first) of std_logic_vector(7 downto 0);
  signal fifodout         : arr_fifodout;
  signal fifodoutp        : arr_fifodoutp;
  signal startread_toggle : std_logic := '0';
  signal startread_d      : std_logic := '0';
  signal startread_dd     : std_logic := '0';
  signal startread_ddd    : std_logic := '0';
  signal startread        : std_logic := '0';
  signal fiforead         : std_logic := '0';
  signal rst_q            : std_logic := '0';
  signal d_out            : ldata(4 * N_REGION - 1 downto 0) := (others => LWORD_NULL);

begin  -- architecture rtl

  --reset CDC
  cdc_reset : process (clk_o) is
  begin
    if rising_edge(clk_o) then  
      rst_q <= rst_i;
      rst_o <= rst_q;
    end if;
  end process cdc_reset;

  --toggle synchronizer
  cdc_startread_a : process (clk_i) is
  begin
    if rising_edge(clk_i) then  
      startread_toggle <= startread_toggle xor din_i(channel_first).last;
    end if;
  end process cdc_startread_a;
  cdc_startread_b : process (clk_o) is
  begin 
    if rising_edge(clk_o) then     
      startread_d <= startread_toggle;
      startread_dd <= startread_d;
      startread_ddd <= startread_dd;
      startread <= startread_d xor startread_dd;
    end if;
  end process cdc_startread_b;

  --fifo read logic
  p_fiforead : process (clk_o) is
  begin
    if rising_edge(clk_o) then     
      if startread = '1' then
        fiforead <= '1';
      elsif fifodoutp(channel_first)(4) = '1' then
        fiforead <= '0';
      else
        fiforead <= fiforead; --latch
      end if;
    end if;
  end process p_fiforead;

  GEN_FIFOS: for i in channel_first to channel_last generate

    --output logic
    p_output: process (clk_o) is
    begin  -- process p_delay_data
      if rising_edge(clk_o) then     -- rising clock edge
        if fiforead = '1' then
          d_out(i).data           <= fifodout(i);
          d_out(i).valid          <= fifodoutp(i)(0);
          d_out(i).start          <= fifodoutp(i)(1);
          d_out(i).start_of_orbit <= fifodoutp(i)(2);
          d_out(i).strobe         <= fifodoutp(i)(3);
          d_out(i).last           <= fifodoutp(i)(4);
        else
          d_out(i).data           <= x"0000000000000000";
          d_out(i).valid          <= '0';
          d_out(i).start          <= '0';
          d_out(i).start_of_orbit <= '0';
          d_out(i).strobe         <= '0';
          d_out(i).last           <= '0';
        end if;
      end if;
    end process p_output;
    din_o(i) <= d_out(i);

    --FIFO
    FIFO36_inst : FIFO36E2
           generic map (
              CLOCK_DOMAINS => "INDEPENDENT",     
              FIRST_WORD_FALL_THROUGH => "TRUE",  
              PROG_EMPTY_THRESH => 2,             
              PROG_FULL_THRESH => 64,             
              READ_WIDTH => 72,                    
              REGISTER_MODE => "REGISTERED",      
              RSTREG_PRIORITY => "RSTREG",        
              WRITE_WIDTH => 72
           )
           port map (
              CASDOUT => open,
              CASDOUTP => open,
              CASNXTEMPTY => open,
              CASPRVRDEN => open,
              DOUT => fifodout(i),
              DOUTP => fifodoutp(i),
              EMPTY => open,
              FULL => open,
              PROGEMPTY => open,
              PROGFULL => open,
              RDCOUNT => open,
              RDERR => open,
              RDRSTBUSY => open,
              WRCOUNT => open,
              WRERR => open,
              WRRSTBUSY => open,
              CASDIN => X"0000000000000000",
              CASDINP => X"00",
              CASDOMUX => '0',
              CASDOMUXEN => '1',
              CASNXTRDEN => '0',
              CASOREGIMUX => '0',
              CASOREGIMUXEN => '1',
              CASPRVEMPTY => '0',
              RDCLK => clk_o,
              RDEN => fiforead,
              REGCE => '1',
              RSTREG => '0',
              SLEEP => '0',
              RST => rst_i,    
              WRCLK => clk_i,       
              WREN => din_i(i).valid,
              DIN =>  din_i(i).data,
              DINP => "000" & din_i(i).last & din_i(i).strobe & din_i(i).start_of_orbit & din_i(i).start & din_i(i).valid,
              INJECTDBITERR => '0',
              INJECTSBITERR => '0',
              DBITERR => open,
              SBITERR => open,
              ECCPARITY => open
           );
  end generate GEN_FIFOS;

end architecture rtl;
