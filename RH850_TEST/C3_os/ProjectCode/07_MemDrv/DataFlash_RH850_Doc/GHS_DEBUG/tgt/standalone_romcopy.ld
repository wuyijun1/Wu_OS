MEMORY {
    sram_memory           : ORIGIN = 0xfede0000, LENGTH = 160K  // The first 128K is primary (fast) sram
    global_memory         : ORIGIN = 0xfedd8000, LENGTH = 32K
    sfr_memory		  : ORIGIN = 0xfffff000, LENGTH = 4K

    flash_rsvd1           : ORIGIN = 0x00000000, LENGTH = 0x1000
    flash_memory          : ORIGIN = .,          LENGTH = 2M - 0x1000

    flash_memory2         : ORIGIN = 0x01000000, LENGTH = 32K
    data_flash            : ORIGIN = 0xff200000, LENGTH = 48K 
    
    // These memory region(s) needed for the default linkmap
    zda_memory  : ORIGIN = 0, LENGTH = 0
    rozda_memory: ORIGIN = 0, LENGTH = 0
    dram_memory : ORIGIN = 0, LENGTH = 0
    iram_memory : ORIGIN = 0, LENGTH = 0
}
CONSTANTS {

    heap_reserve = 32K
    stack_reserve = 32K

}
//
// Program layout for starting in ROM, copying text and data to RAM,
// and then running out of RAM.
//

SECTIONS
{
//
// RAM SECTIONS
//
    .boottext ALIGN(4) : {
	  // All .text which is reachable between
	  // _start and __ghs_ind_crt1 needs to be
	  // pulled into .boottext and left
	  // uncompressed.
	  crt0.o(.text)
	  libstartup.a(*)(.text)
	  libsys.a(ind_crt1.o)(.text)
	  libarch.a(*)(.text)
    }							      > dram_memory,iram_memory,sram_memory
    .syscall					   ALIGN(4) : > .
    .callt						    : > .
    .text						    : > .

    .data					   ALIGN(16) : > dram_memory,sram_memory,global_memory
    .bss						    : > .
    .heap	                 ALIGN(16) PAD(heap_reserve) : > .

    .sda_start			                   ALIGN(16) : > sram_memory,global_memory
    .sdabase					            : > .
    .sdata					            : > .
    .sbss						    : > .
    .sda_end						    : > .


    .stack                  ALIGN(4) PAD(stack_reserve) ABS : > .
    .tdata					        ABS : > zda_memory,sram_memory,global_memory
    .zdata			                        ABS : > .
    .zbss					        ABS : > .

//
// ROM SECTIONS
//
    .reset						    : > flash_rsvd1,flash_memory
    .rozdata				                    : > rozda_memory,flash_memory
    .robase				           ALIGN(16) : > flash_memory
    .rosda_start			           ALIGN(16) : > .
    .rosdata						    : > .
    .rosda_end	  					    : > .
    .rodata						    : > .

    .ROM.boottext		    ALIGN(4) ROM(.boottext) : > .
    .ROM.syscall		     ALIGN(4) ROM(.syscall) : > .
    .secinfo						    : > .
    .fixaddr						    : > .
    .fixtype						    : > .

    .CROM.zdata				       CROM(.zdata) : > .
    .CROM.tdata				       CROM(.tdata) : > .
    .CROM.data				        CROM(.data) : > .
    .CROM.sdata				       CROM(.sdata) : > .
    .CROM.callt			                CROM(.callt) : > .
    .CROM.text			                CROM(.text) : > .

//
// These special symbols mark the bounds of RAM and ROM images of boot code.
// They are used by the GHS startup code (_start and __ghs_ind_crt0).
//
    ___ghs_rambootcodestart  = ADDR(.boottext);
    ___ghs_rambootcodeend    = ENDADDR(.text);	
    ___ghs_rombootcodestart  = ADDR(.ROM.boottext);
    ___ghs_rombootcodeend    = ENDADDR(.fixtype);

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    ___ghs_ramstart  = MEMADDR(sram_memory);
    ___ghs_ramend    = MEMENDADDR(sram_memory);
    ___ghs_romstart  = MEMADDR(flash_memory);
    ___ghs_romend    = MEMENDADDR(flash_memory);

//
// This special symbol marks the the first address executed after the
// ROM to RAM copy is complete.  It is used by the MULTI debugger.
//
    ___ghs_after_romcopy = ___ghs_ind_crt1;
}






