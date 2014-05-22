library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
--use ieee.std_logic_arith.all;
entity code_lock is port(
CLOCK_50 , RESET , ENTER : in std_logic;
CODE 							 : in std_logic_vector(3 downto 0);
SEG							 : out std_logic_vector(6 downto 0);
LOCK   						 : out std_logic);
end code_lock;

architecture three_processes of code_lock is 

type state is ( s_idle , s_code1_accept , s_code2_accept , s_unlocked , s_wrong_code , s_perm_locked );

signal present_state, next_state : state;
signal err_cnt , next_err_cnt    : std_logic_vector(3 downto 0);
signal enter_event , enter_last  : std_logic;
signal lock_counter : unsigned(15 downto 0);

constant CODE1 : std_logic_vector(3 downto 0) :="0001";
constant CODE2 : std_logic_vector(3 downto 0) :="0011";
constant CODE3 : std_logic_vector(3 downto 0) :="0111";
 
begin

state_reg: process (CLOCK_50 , RESET) 

begin
	if RESET = '0' then 
		present_state <= s_idle;
		err_cnt <= "0000";
		enter_event <= '0';
		enter_last <= '1';
		lock_counter <= "0000000000000000";
	elsif rising_edge(CLOCK_50) then
		present_state <= next_state;
		err_cnt <= next_err_cnt;
		enter_last <= ENTER;
		enter_event <= '0';
		if enter_last = '1' and ENTER = '0' then
			enter_event <= '1';
		end if;
		if present_state = s_unlocked then
		   lock_counter <= lock_counter + 1;
		else
		   lock_counter <= "0000000000000000";
		end if;
	end if;
end process;

outputs: process (present_state)

begin
	case present_state is
		when s_idle =>
			LOCK <= '0';
		when s_code1_accept =>
			LOCK <= '0';
		when s_code2_accept =>
			LOCK <= '0';
		when s_unlocked =>
			LOCK <= '1';
		when s_wrong_code =>
			LOCK <= '0';
		when s_perm_locked =>
			LOCK <= '0';
	end case; 
end process;

nxt_state: process (present_state , enter_event , CODE , err_cnt , lock_counter)

begin
	case present_state is
	
		when s_idle =>	-- IDLE
		next_err_cnt <= err_cnt;
			if enter_event = '1' then
				if CODE = CODE1 then
					next_state <= s_code1_accept;
				else
					next_state <= s_wrong_code;
				end if;
			else
				next_state <= s_idle;
			end if;
			
		when s_code1_accept => -- CODE1 ACCEPTED
		next_err_cnt <= err_cnt;
			if enter_event = '1' then
				if CODE = CODE2 then
					next_state <= s_code2_accept;
				else
					next_state <= s_wrong_code;
				end if;
			else
				next_state <= s_code1_accept;
			end if;
			
		when s_code2_accept => -- CODE2 ACCEPTED
		next_err_cnt <= err_cnt;
			if enter_event = '1' then
				if CODE = CODE3 then
					next_state <= s_unlocked;
				else
					next_state <= s_wrong_code;
				end if;
			else
				next_state <= s_code2_accept;
			end if;
			
		when s_unlocked => -- UNLOCKED
		next_err_cnt <= err_cnt;
			if lock_counter < "1100001101010000" then	-- 1ms
				next_state <= s_unlocked;
			else
				next_err_cnt <= "0000";
				next_state <= s_idle;
			end if;

--		if enter_event = '1' then
--			next_state <= s_idle;
--		else
--			next_state <= s_unlocked;
--		end if;

		when s_wrong_code => -- WRONG CODE
			if err_cnt = "0000" then
				next_err_cnt <= "0001";
			elsif err_cnt = "0001" then
				next_err_cnt <= "0010";
			else
				next_err_cnt <= "0011";
			end if;
			if err_cnt >= "0011" then
				next_state <= s_perm_locked;
			else 
				next_state <= s_idle;
			end if;
			
		when s_perm_locked => -- PERMANTLY LOCKED
			next_state <= s_perm_locked;
	end case; 
end process;

-- ERROR INDICATOR ON HEX0 FOR TEST PURPOSE --
TEST1: work.bin_2_7_seg port map(dcba => err_cnt , seg => SEG); 

end three_processes;
