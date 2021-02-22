/*===========================================================================*/
/* Module       = dr7f701412.ld                                              */
/* Version      = E1.00g                                                     */
/*                extracted from device file dr7f701412.dvf                  */
/*                by DeFiXRH850 0.7.5.1                                      */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2014 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose:     Template of linker directive file                            */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* Environment:                                                              */
/*              Device:         R7F701412                                    */
/*              IDE:            GHS Multi for V800  V6.xx or later           */
/*===========================================================================*/

CONSTANTS
{
  zero_start = 0xffff8000
}

MEMORY
 {
  iROM_0     : ORIGIN = 0x00000000,      LENGTH = 5120k
  iROM_0_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_0         : ORIGIN = 0xFEB80000,  LENGTH = 512k
  iRAM_0_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_1         : ORIGIN = 0xFED80000,  LENGTH = 512k
  iRAM_1_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_R         : ORIGIN = 0x3FCE4000,  LENGTH = 16k-2k
  iRAM_R_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_NotClear     : ORIGIN = 0x3FCE7800,  LENGTH = 2k
  iRAM_NotClear_TOP : ORIGIN = .         ,  LENGTH = 0
 }

SECTIONS
 {
 /*****************************************************************
             ROM map
 *******************************************************************/

  .App_intvect 				:> iROM_0
  .rozdata   align(4)                   :>.      /* constant datas in ZDA area */
  .robase   align(4)                    :>.      /* initialize textpointer TP for SDA addressing */
  .rosdata  align(4)                    :>.      /* constant datas in SDA area */
  .rodata   align(4)                    :>.      /* constant datas in normal area */
  .R_FDL_Const align(4)			:>.	 /*data_flash const data location*/
  .fixaddr  align(4)                    :>.      /* ghs internal (compiler) */
  .fixtype  align(4)                    :>.      /* ghs internal (compiler) */
  .secinfo  align(4)                    :>.      /* ghs internal (runtime library) */
  .syscall  align(4)                    :>.      /* ghs internal (linker) */
  .romdata  ROM(.data)                  :>.      /* constant data to initialize variables (copied to RAM at startup)*/
  .romzdata ROM(.zdata)                 :>.      /* constant data to initialize variables in ZDA area (copied to RAM at startup)*/
  .romsdata ROM(.sdata)                 :>.      /* constant data to initialize variables in SDA area (copied to RAM at startup)*/
  .romtdata ROM(.tdata)                 :>.      /* constant data to initialize variables in TDA area (copied to RAM at startup)*/
  .R_FDL_Text 	align(4)		:>.	 /*data_flash code location*/
  .text     align(4)                    :>.      /* program code area */
  .top_of_iROM_0 align(4)                :>iROM_0_TOP

 /*******************************************************************************
             iRAM_0 map(primary RAM, Hard clear by reset)
 ********************************************************************************/

  .ramtext  align(128) MAX_SIZE(0x2000) :>iRAM_0 /* initialized and zero-initialized data in TDA area */
  .tdata    align(4)   MAX_SIZE(0x0100) :>.      /* initialized and zero-initialized data in TDA area */
  .sdabase  align(4)                    :>.      /* initialize globalpointer GP for SDA addressing */
  .sdata    align(4)                    :>.      /* initialized data in SDA area*/
  .sbss     align(4)                    :>.      /* zero initialized data in SDA area*/
  .zdata    align(4)                    :>.      /* initialized data in ZDA area*/
  .zbss     align(4)                    :>.      /* zero initialized data in ZDA area*/
  .data     align(4)                    :>.
  .exec     align(128)                  :>.  
  .R_FDL_CodeRam 		      :>.		/*data_flash RAM code location*/
  .R_FDL_Data 			      :>.		/*data_flash grabol location*/
  .bss          align(4)              :>. 
  .top_of_iRAM_0 align(4)                :>iRAM_0_TOP

 /*******************************************************************************
             iRAM_1 map(Second RAM, Hard clear by reset)
 ********************************************************************************/

  .stack    align(4) pad(0x2800)        :>iRAM_1      /* definition of stack size */  .top_of_RAM_1 align(4)                :>iRAM_1_TOP



 /*******************************************************************************
             iRAM_R map(retention RAM,
	     HardWare Not clear by reset, but Clear by startup)
 ********************************************************************************/

  .rdata        align(4)              :>iRAM_R     /* user defined segment for initialized data located in retention RAM  */
  .rbss         align(4)              :>.          /* user defined segment for zero initialized data located in retention RAM */
  .top_of_iRAM_R   align(4)              :>iRAM_R_TOP



 /*******************************************************************************
             iRAM_R map(retention RAM,
	     HardWare Not clear by reset also Not Clear by startup)
 ********************************************************************************/
  .Not_Clear_RAM     align(4)           :>iRAM_NotClear     
  .top_of_RAM_NotClear align(4)         :>iRAM_NotClear_TOP


  ___ghs_romstart   = MEMADDR(iROM_0);
  ___ghs_romend     = MEMENDADDR(iROM_0);

  ___ghs_ramstart0   = MEMADDR(iRAM_0);
  ___ghs_ramend0     = MEMENDADDR(iRAM_0);

  ___ghs_ramstart1   = MEMADDR(iRAM_1);
  ___ghs_ramend1     = MEMENDADDR(iRAM_1);

  ___ghs_ramstartr  = MEMADDR(iRAM_R);
  ___ghs_ramendr    = MEMENDADDR(iRAM_R);

 }

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/
