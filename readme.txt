Forked Pasmo assembler

Example compile command line:

pasmo.exe--sna --alocal --cspecsymbols --snasmerrors --tracedata lowresdemo.asm lr.sna lr.sna.map





Extra Options:

--cspecsymbols
	Outputs map file in the format CSPEC emulator can read.

--snasmerrors
	Outputs errors messages in snasms format

--tracedata
	Outpus trace data for use with RemoteDebugger.


Comments:
You can now use // and ; to define line comments

Local labels:
You can now use @ in the same way as _ is pasmo.	



Commands:

SAVEBIN <filename>,<addr>,<length>
	On last pass file will be written to the hdd from the assembled memory, if pc is before the last address data is undefined.
example
	SAVEBIN "build/bank4.bin",$c000,PC-$c000



MESSAGE <messages>,...
	emits a message to console output , can output labels and string and constants. seperate with comma.
example
	MESSAGE "CURRENT PC=",PC

	use %d before varible to output as decimal , otherwise hex will be output.
	MESSAGE "Size=",%d size


PC
	PC can now be used as definition of the current compile address, as well as $.



HEX <hexbytes>
	you can now define big blocks of data using HEX statment

example
	HEX 0002008C8C8C8C8C8C49B6B6498C0001
	


ALIGN <value>
	Aligns ther PC the a boundry
example
	ALIGN 256 aligns the PC so lo byte of address will be 0.


RSSET <value>
	Sets the RS value to <value> if value is not there value will be 0 , used with RS & RW to define structs.
example
	RSSET 0 
	HWSPRITEDATA_OX: rb 1
	HWSPRITEDATA_OY: rb 1
	HWSPRITEDATA_SX: rw 1


SETBANK <addr>,<value>
	Sets the CURRENTBANK varible to value for addr to addr + 0x1fff (8k). Also all labels defined after this command will store the bank it was defined in.
	then you can do ?? before a label to get the bank of that label.
example
	SETBANK $2000,5   sets the code now compiled from $2000-$3fff to use bank 5
	SETBANK $4000,6   sets the code now compiled from $4000-$5fff to use bank 6

DATA:	HEX 0002008C8C8C8C8C8C49B6B6498C0001

	ld hl,DATA (sets the address of data)
	ld a,?? DATA (sets a to the bank "5", of the label data)

STRUCT <name>
	Define a structure

example
	STRUCT hello
		width   db 0		;single byte
		height  dw 0        ;single word (2 bytes)	
		control db 0,0,0    ;3 byte array
		data    ds 2        ;2 byte array
	ENDS

	Will define hello.width to 0 , hello.height to 1 , hello.control to 3 , hello.data to 6 & hello itself is the bytesize of 8.




Changes:
<0.1
	removed A32 and DEHL registers
	Fixed Next instruction ADD HL/DB/BC,A & ADD HL/DB/BC,XXXX you can now use minus numbers and identifiers.
	Fixed/removed warning when doing ld a,-10 
	Fixed CURRENTBANK define 

0.1
	added mac support

0.1.1
	added cspect new label support
	local labels correctly output names
	removed fillde
	fixed LDWS instruction
	added barrel shift instructions:
	BSLA DE,B
	BSRA DE,B
	BSRL  DE,B
	BSRF  DE,B
	BRLC  DE,B
	added instruction
	JP (C)

0.1.2
	Merged better offset IX & IY control from jounikor pasmo fork
	Merged STRUCT system from jounikor pasmo fork
	Can use %d in messages to output decimal.
	CSPECT -16bit support for symbols


