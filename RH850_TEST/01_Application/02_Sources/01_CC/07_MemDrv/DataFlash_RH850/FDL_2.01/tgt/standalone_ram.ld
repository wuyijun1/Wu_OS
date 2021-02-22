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


