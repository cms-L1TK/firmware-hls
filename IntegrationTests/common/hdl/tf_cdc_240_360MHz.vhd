library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

library UNISIM;
use UNISIM.VComponents.all;

entity tf_cdc_240_360MHz is

port(
  clk_240MHz_i : std_logic;
  clk_360MHz_i : std_logic;
  din_i  : in lword;
  dout_o  : out lword
  );

end tf_cdc_240_360MHz;

architecture rtl of tf_cdc_240_360MHz is


-- DEMUX signals
signal din: lword := LWORD_NULL;
-- Signal for simulation purposes only
-- signal din_0: lword := LWORD_NULL;
-- Signals for DEMUX
signal din_1: lword := LWORD_NULL;
signal din_2: lword := LWORD_NULL;
signal toggle : std_logic := '0';
signal sticky_valid : std_logic := '0';
signal valid_dly1_sticky  : std_logic := '0';

--CDC control signals and flags
constant CNTR_NMBR_BITS: integer := 2;
constant nmbr_of_cycles_alignment: integer := 2;
signal alignment_cntr: unsigned(nmbr_of_cycles_alignment -1 downto 0) := (others => '0');
signal alignment_cntr_done: std_logic := '0';
signal alignment_flag: std_logic := '0';
signal cntr: unsigned(CNTR_NMBR_BITS - 1 downto 0) := (others => '0');
signal valid_dly0 : std_logic:= '0';
signal valid_dly1 : std_logic:= '0';

-- Alignment FSM

type state_type is (IDLE, COUNT_CYCLES, DONE);
signal state, next_state : state_type := IDLE;
signal cycle_count : integer range 0 to 2 := 0;

-- output
attribute dont_touch : string;

signal dout: lword := LWORD_NULL;
signal dout_1: lword := LWORD_NULL;
signal dout_2: lword := LWORD_NULL;
signal dout_1_reg0: lword := LWORD_NULL;
signal dout_2_reg0: lword := LWORD_NULL;
signal dout_1_reg1: lword := LWORD_NULL;
signal dout_2_reg1: lword := LWORD_NULL;
signal dout_1_reg2: lword := LWORD_NULL;

attribute dont_touch of din_1      : signal is "true";
attribute dont_touch of din_2      : signal is "true";

attribute dont_touch of dout_1      : signal is "true";
attribute dont_touch of dout_2      : signal is "true";
attribute dont_touch of dout_1_reg0 : signal is "true";
attribute dont_touch of dout_2_reg0 : signal is "true";
attribute dont_touch of dout_1_reg1 : signal is "true";
attribute dont_touch of dout_2_reg1 : signal is "true";
attribute dont_touch of dout_1_reg2 : signal is "true";

begin


dout_o <= dout;

din_valid_sticky : FDRE
generic map (
    INIT => '0'
)
port map (
    Q  => sticky_valid,
    C  => clk_240MHz_i,
    CE => din.valid,
    D  => '1',
    R  => '0'
);

-- Demux in clk 240 MHz domain
process ( clk_240MHz_i, din.valid, sticky_valid ) is
begin
if rising_edge( clk_240MHz_i ) then
--  din_0 <= din_i;
  din  <= din_i;
  if din.valid = '1' or sticky_valid= '1' then
    if toggle = '0' then
      din_1 <= din;
    else
      din_2 <= din;
    end if;
    toggle <= not toggle; -- toggle only when valid
 else
   toggle <='0';
   din_1 <= LWORD_NULL;
   din_2 <= LWORD_NULL;
  end if;
end if;
end process;


--   Move data from 240 MHz to 360 MHz domain
process ( clk_360MHz_i ) is
begin
if rising_edge( clk_360MHz_i ) then

  --Move to 360 MHz domain
  dout_1 <= din_1;
  dout_2 <= din_2;

  dout_1_reg0 <= dout_1;
  dout_2_reg0 <= dout_2;

  dout_1_reg1 <= dout_1_reg0;
  dout_2_reg1 <= dout_2_reg0;

  dout_1_reg2 <= dout_1_reg1;


end if;
end process;


-- Alignment in 360 MHz domain
-- FSM to monitor alignment between 2 streams generated in the Demux process
-- State register
process( clk_360MHz_i, cycle_count )
begin
  if rising_edge( clk_360MHz_i ) then
    state <= next_state;

    if state = COUNT_CYCLES then
        cycle_count <= cycle_count + 1;
    elsif state = IDLE then
        cycle_count <= 0;
    end if;
  end if;
end process;

-- Next state logic
process( state, dout_1.valid, dout_2.valid )
begin
next_state <= state;  -- default
case state is
  when IDLE =>
    if dout_1.valid = '1' then
        next_state <= COUNT_CYCLES;
    end if;

  when COUNT_CYCLES =>
    if dout_2.valid = '1' then
        next_state <= DONE;
    end if;

  when DONE =>
    if dout_1.valid = '0' then
        next_state <= IDLE;
    end if;

end case;
end process;

-- Output logic
process( state, cycle_count )
begin
if rising_edge( clk_360MHz_i ) then
  alignment_flag <= '0'; -- default
  if state = DONE then
    if cycle_count = 1 then
      alignment_flag <= '0';
    elsif cycle_count = 2 then
      alignment_flag <= '1';
    end if;
  end if;
end if;
end process;


-- Use alignment flag and valid signals to run MUX process
process ( clk_360MHz_i, alignment_flag ) is
begin
if rising_edge( clk_360MHz_i ) then
  if state = DONE then
    if alignment_flag = '0' then
      valid_dly0 <= dout_1_reg0.valid;
      valid_dly1 <= dout_1_reg0.valid;-- shorter path to start the FSM
    elsif alignment_flag  = '1' then
      valid_dly0 <= dout_1_reg1.valid;
      valid_dly1 <= valid_dly0;-- Pipeline output
    end if;
  else
    valid_dly0 <= '0';
    valid_dly1 <= '0';
  end if;
end if;
end process;

valid_dly_sticky : FDRE
generic map (
    INIT => '0'
)
port map (
    Q  => valid_dly1_sticky,
    C  => clk_360MHz_i,
    CE => valid_dly1,
    D  => '1',
    R  => '0'
);

process ( clk_360MHz_i, valid_dly1, valid_dly1_sticky ) is
begin

if rising_edge( clk_360MHz_i ) then
  if valid_dly1 = '1' or valid_dly1_sticky ='1' then
    if cntr >= CNTR_NMBR_BITS then
      cntr <= (others => '0');
    else
      cntr <= cntr + 1;
    end if;
  else
     cntr <= (others => '0');
  end if;
end if;

end process;

-- Merge streams

-- Mux process

process ( clk_360MHz_i, valid_dly1 ) is
variable tmp : lword;
begin
if rising_edge( clk_360MHz_i ) then
  case cntr is
    when "00" =>
      if valid_dly1 = '0' then
        dout <= LWORD_NULL;
      elsif valid_dly1 = '1' then
        if alignment_flag = '1' then
          dout <= dout_1_reg2;
        else
          dout <= dout_1_reg1;
        end if;
      end if;
    when "01" =>
      dout <= dout_2_reg1;
    when "10" =>
      if valid_dly1 = '1' then
        tmp := LWORD_NULL;
        tmp.valid := '1';
        dout <= tmp;
      end if;
    when others =>
      dout <= LWORD_NULL;
  end case;

end if;

end process;


end rtl;
