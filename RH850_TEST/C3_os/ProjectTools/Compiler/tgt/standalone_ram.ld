MEMORY {
    sram_memory           : ORIGIN = 0x00400000, LENGTH = 32M
    zda_memory            : ORIGIN = 0xffff8000, LENGTH = 28K
    sfr_memory		  : ORIGIN = 0xfffff000, LENGTH = 4K

    flash_rsvd1           : ORIGIN = 0x00000000, LENGTH = 0x1000
    flash_memory          : ORIGIN = .,          LENGTH = 4M - 0x1000

    // These memory region(s) needed for the default linkmap
    rozda_memory: ORIGIN = 0, LENGTH = 0
    dram_memory : ORIGIN = 0, LENGTH = 0
    iram_memory : ORIGIN = 0, LENGTH = 0
    global_memory: ORIGIN = 0, LENGTH = 0
}
DEFAULTS {

    heap_reserve = 1M
    stack_reserve = 512K

}
//
// Program layout for running out of RAM.
//
//

SECTIONS
{
//
// RAM SECTIONS
//
    .callt					   ALIGN(4) : > dram_memory,iram_memory,sram_memory
    .text						    : > .
    .reset						    : > .
    .syscall			                   ALIGN(4) : > .
    .secinfo						    : > .
    .fixaddr						    : > .
    .fixtype						    : > .
    .robase				           ALIGN(16) : > .
    .rosda_start				   ALIGN(16) : > sram_memory
    .rosdata						    : > .
    .rosda_end						    : > .
    .rodata						    : > .

 
    .sda_start			                   ALIGN(16) : > sram_memory
    .sdabase						    : > .
    .sdata						    : > .
    .sbss						    : > .
    .sda_end						    : > .

    .data				     	   ALIGN(16) : > dram_memory,sram_memory,global_memory
    .bss						    : > .

    .heap	                ALIGN(16)  PAD(heap_reserve) : > .

    .stack                  ALIGN(4) PAD(stack_reserve) ABS : > sram_memory,global_memory
    .tdata					        ABS : > zda_memory,sram_memory,global_memory
    .rozdata					  ALIGN(16) ABS : > .
    .zdata			                        ABS : > . 
    .zbss					        ABS : > . 


//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    ___ghs_ramstart  = MEMADDR(sram_memory);
    ___ghs_ramend    = MEMENDADDR(sram_memory);
    ___ghs_romstart  = MEMADDR(flash_memory);
    ___ghs_romend    = MEMENDADDR(flash_memory);
    
}


