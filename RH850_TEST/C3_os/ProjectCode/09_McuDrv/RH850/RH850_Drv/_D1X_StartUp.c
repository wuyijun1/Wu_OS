/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1X_StartUp.850
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2016 Huizhou Desay SV Automotive Co., Ltd.    All rights reserved.
|
| This software is copyright protected and proprietary to Desay SV Automotive Co., Ltd.
| Desay SV Automotive Co., Ltd grants to you only those rights as set out in the
| license conditions. All other rights remain with Desay SV Automotive Co., Ltd.
|
| REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
| Name                                  Company
| ---------------------     ---------------------------------------
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2016.05.06  V0.01	Tan, fumin	:create this module
********************************************************************************/


#include "..\D1X_UsrCfg\_D1X_UsrCfg.h"


#pragma asm

-------------------------------------------------------------------------------
----------need locate this in ROM intvect section, text type
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------


#ifdef __OS_HANDLES__      

	/* OS interrupt code can be added here */

  .offset 0x0000	

	jr	_MCUReset	--/*0x00000000 + 0x0000*/

#else /* __OS_HANDLES__ */ 

------------------------------------------------------------------------

------------------------------------------------------------------------
------system error interrupt table list, do not remove !----------------
------------------------------------------------------------------------

------------------------------------------------------------------------

 /*
				 a=allocated for downloading
				 w=writable
				 x=executable
 */
 
#if (APP_CODE_MAP_START !=0)

 .section".Boot_intvect","ax"
 .offset 0x0000	  

  jr  APP_CODE_MAP_START   --/*0x00000000 + 0x0000*/
  
#endif

  .section".App_intvect","ax"
  .offset 0x0000

	.extern	_Debug
	.extern	_EINTPRIO_0
	.extern	_EINTPRIO_1
	.extern	_EINTPRIO_10
	.extern	_EINTPRIO_11
	.extern	_EINTPRIO_12
	.extern	_EINTPRIO_13
	.extern	_EINTPRIO_14
	.extern	_EINTPRIO_15
	.extern	_EINTPRIO_2
	.extern	_EINTPRIO_3
	.extern	_EINTPRIO_4
	.extern	_EINTPRIO_5
	.extern	_EINTPRIO_6
	.extern	_EINTPRIO_7
	.extern	_EINTPRIO_8
	.extern	_EINTPRIO_9
	.extern	_EITRAP0
	.extern	_EITRAP1
	.extern	_FEINT
	.extern	_FENMI
	.extern	_FETRAPEX
	.extern	_FPP_FPI
	.extern	_HVTRAP
	.extern	_MAE
	.extern	_MCU_vNotExpINT
	.extern	_MIP_MDP
	.extern	_PIE
	.extern	_MCUReset
	.extern	_Reserved
	.extern	_RIEX
	.extern	_SYSERR
	.extern	_UCPOP
						
/*#########################################################

		-- this is software entry piont after MCU reset------
		
		--system interrupt function vector--
		
#########################################################*/	
								
	jr	_MCUReset		/*0x00000000 + 0x0000*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0004*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0008*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x000C*/				
	jr	_SYSERR			/*0x00000000 + 0x0010*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0014*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0018*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x001C*/				
	jr	_HVTRAP			/*0x00000000 + 0x0020*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0024*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0028*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x002C*/				
	jr	_FETRAPEX		/*0x00000000 + 0x0030*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0034*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0038*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x003C*/				
	jr	_EITRAP0		/*0x00000000 + 0x0040*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0044*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0048*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x004C*/				
	jr	_EITRAP1		/*0x00000000 + 0x0050*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0054*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0058*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x005C*/				
	jr	_RIEX			/*0x00000000 + 0x0060*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0064*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0068*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x006C*/				
	jr	_FPP_FPI		/*0x00000000 + 0x0070*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0074*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0078*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x007C*/				
	jr	_UCPOP			/*0x00000000 + 0x0080*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0084*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0088*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x008C*/				
	jr	_MIP_MDP		/*0x00000000 + 0x0090*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0094*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0098*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x009C*/				
	jr	_PIE			/*0x00000000 + 0x00A0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00A4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00A8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00AC*/				
	jr	_Debug			/*0x00000000 + 0x00B0*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00B4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00B8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00BC*/				
	jr	_MAE			/*0x00000000 + 0x00C0*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00C4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00C8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00CC*/				
	jr	_Reserved		/*0x00000000 + 0x00D0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00D4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00D8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00DC*/				
	jr	_FENMI			/*0x00000000 + 0x00E0*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00E4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00E8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00EC*/				
	jr	_FEINT			/*0x00000000 + 0x00F0*/		
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00F4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00F8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x00FC*/				
	jr	_EINTPRIO_0		/*0x00000000 + 0x0100 -->if RBASE.RINT=1, all EINTPRIO_x using this entry if using priority mode*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0104*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0108*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x010C*/				
	jr	_EINTPRIO_1		/*0x00000000 + 0x0110*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0114*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0118*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x011C*/				
	jr	_EINTPRIO_2		/*0x00000000 + 0x0120*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0124*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0128*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x012C*/				
	jr	_EINTPRIO_3		/*0x00000000 + 0x0130*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0134*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0138*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x013C*/				
	jr	_EINTPRIO_4		/*0x00000000 + 0x0140*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0144*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0148*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x014C*/				
	jr	_EINTPRIO_5		/*0x00000000 + 0x0150*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0154*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0158*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x015C*/				
	jr	_EINTPRIO_6		/*0x00000000 + 0x0160*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0164*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0168*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x016C*/				
	jr	_EINTPRIO_7		/*0x00000000 + 0x0170*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0174*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0178*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x017C*/				
	jr	_EINTPRIO_8		/*0x00000000 + 0x0180*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0184*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0188*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x018C*/				
	jr	_EINTPRIO_9		/*0x00000000 + 0x0190*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0194*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x0198*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x019C*/				
	jr	_EINTPRIO_10		/*0x00000000 + 0x01A0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01A4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01A8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01AC*/				
	jr	_EINTPRIO_11		/*0x00000000 + 0x01B0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01B4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01B8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01BC*/				
	jr	_EINTPRIO_12		/*0x00000000 + 0x01C0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01C4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01C8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01CC*/				
	jr	_EINTPRIO_13		/*0x00000000 + 0x01D0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01D4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01D8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01DC*/				
	jr	_EINTPRIO_14		/*0x00000000 + 0x01E0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01E4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01E8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01EC*/				
	jr	_EINTPRIO_15		/*0x00000000 + 0x01F0*/			
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01F4*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01F8*/				
	jr	_MCU_vNotExpINT		/*0x00000000 + 0x01FC*/				
								
								
		


------------------------------------------------------------------------

------------------------------------------------------------------------
------user interrupt table list, all the function using table mode------
------------------------------------------------------------------------
------YES, we are also in intvect section,offset address only-----------
------------------------------------------------------------------------

  .offset IRQ_TABLE_START
			
	.extern	_MCU_vISR_0_INTWDTA0	
	.extern	_MCU_vISR_1_INTWDTA1	
	.extern	_MCU_vISR_2_INTRTCA01S	
	.extern	_MCU_vISR_3_INTRTCA0AL	
	.extern	_MCU_vISR_4_INTRTCA0R	
	.extern	_MCU_vISR_5_INTAWOT0	
	.extern	_MCU_vISR_6_INTP0	
	.extern	_MCU_vISR_7_INTP1	
	.extern	_MCU_vISR_8_INTP2	
	.extern	_MCU_vISR_9_INTP3	
	.extern	_MCU_vISR_10_INTP4	
	.extern	_MCU_vISR_11_INTP5	
	.extern	_MCU_vISR_12_INTP6	
	.extern	_MCU_vISR_13_INTP7	
	.extern	_MCU_vISR_14_INTP8	
	.extern	_MCU_vISR_15_INTP9	
	.extern	_MCU_vISR_16_INTP10	
	.extern	_MCU_vISR_17_INTTAUB0I0	
	.extern	_MCU_vISR_18_INTTAUB0I1	
	.extern	_MCU_vISR_19_INTTAUB0I2	
	.extern	_MCU_vISR_20_INTTAUB0I3	
	.extern	_MCU_vISR_21_INTTAUB0I4	
	.extern	_MCU_vISR_22_INTTAUB0I5	
	.extern	_MCU_vISR_23_INTTAUB0I6	
	.extern	_MCU_vISR_24_INTTAUB0I7	
	.extern	_MCU_vISR_25_INTTAUB0I8	
	.extern	_MCU_vISR_26_INTTAUB0I9	
	.extern	_MCU_vISR_27_INTTAUB0I10	
	.extern	_MCU_vISR_28_INTTAUB0I11	
	.extern	_MCU_vISR_29_INTTAUB0I12	
	.extern	_MCU_vISR_30_INTTAUB0I13	
	.extern	_MCU_vISR_31_INTTAUB0I14	
	.extern	_MCU_vISR_32_INTTAUB0I15	
	.extern	_MCU_vISR_33_INTTAUB1I0	
	.extern	_MCU_vISR_34_INTTAUB1I1	
	.extern	_MCU_vISR_35_INTTAUB1I2	
	.extern	_MCU_vISR_36_INTTAUB1I3	
	.extern	_MCU_vISR_37_INTTAUB1I4	
	.extern	_MCU_vISR_38_INTTAUB1I5	
	.extern	_MCU_vISR_39_INTTAUB1I6	
	.extern	_MCU_vISR_40_INTTAUB1I7	
	.extern	_MCU_vISR_41_INTTAUB1I8	
	.extern	_MCU_vISR_42_INTTAUB1I9	
	.extern	_MCU_vISR_43_INTTAUB1I10	
	.extern	_MCU_vISR_44_INTTAUB1I11	
	.extern	_MCU_vISR_45_INTTAUB1I12	
	.extern	_MCU_vISR_46_INTTAUB1I13	
	.extern	_MCU_vISR_47_INTTAUB1I14	
	.extern	_MCU_vISR_48_INTTAUB1I15	
	.extern	_MCU_vISR_49_INTTAUB2I0	
	.extern	_MCU_vISR_50_INTTAUB2I1	
	.extern	_MCU_vISR_51_INTTAUB2I2	
	.extern	_MCU_vISR_52_INTTAUB2I3	
	.extern	_MCU_vISR_53_INTTAUB2I4	
	.extern	_MCU_vISR_54_INTTAUB2I5	
	.extern	_MCU_vISR_55_INTTAUB2I6	
	.extern	_MCU_vISR_56_INTTAUB2I7	
	.extern	_MCU_vISR_57_INTTAUB2I8	
	.extern	_MCU_vISR_58_INTTAUB2I9	
	.extern	_MCU_vISR_59_INTTAUB2I10	
	.extern	_MCU_vISR_60_INTTAUB2I11	
	.extern	_MCU_vISR_61_INTTAUB2I12	
	.extern	_MCU_vISR_62_INTTAUB2I13	
	.extern	_MCU_vISR_63_INTTAUB2I14	
	.extern	_MCU_vISR_64_INTTAUB2I15	
	.extern	_MCU_vISR_65_INTADCE0TSN	
	.extern	_MCU_vISR_66_INTADCE0I1	
	.extern	_MCU_vISR_67_INTADCE0I2	
	.extern	_MCU_vISR_68_INTADCE0I3	
	.extern	_MCU_vISR_69_INTRCANGERR	
	.extern	_MCU_vISR_70_INTRCANGRECC	
	.extern	_MCU_vISR_71_INTRCAN0ERR	
	.extern	_MCU_vISR_72_INTRCAN0REC	
	.extern	_MCU_vISR_73_INTRCAN0TRX	
	.extern	_MCU_vISR_74_INTCSIGT0IRE	
	.extern	_MCU_vISR_75_INTCSIG0IR	
	.extern	_MCU_vISR_76_INTCSIG0IC	
	.extern	_MCU_vISR_77_INTCSIH0IRE	
	.extern	_MCU_vISR_78_INTCSIH0IR	
	.extern	_MCU_vISR_79_INTCSIH0IC	
	.extern	_MCU_vISR_80_INTCSIH0IJC	
	.extern	_MCU_vISR_81_INTRLIN30UR2	
	.extern	_MCU_vISR_82_INTRLIN30UR1	
	.extern	_MCU_vISR_83_INTRLIN30UR0	
	.extern	_MCU_vISR_84_INTRLIN31UR2	
	.extern	_MCU_vISR_85_INTRLIN31UR1	
	.extern	_MCU_vISR_86_INTRLIN31UR0	
	.extern	_MCU_vISR_87_INTSG0TI	
	.extern	_MCU_vISR_88_INTSG1TI	
	.extern	_MCU_vISR_89_INTSG2TI	
	.extern	_MCU_vISR_90_INTSG3TI	
	.extern	_MCU_vISR_91_INTSG4TI	
	.extern	_MCU_vISR_92_INTDCUTDI	
	.extern	_MCU_vISR_93_INTDMAERR	
	.extern	_MCU_vISR_94_INTDMA0	
	.extern	_MCU_vISR_95_INTDMA1	
	.extern	_MCU_vISR_96_INTDMA2	
	.extern	_MCU_vISR_97_INTDMA3	
	.extern	_MCU_vISR_98_INTDMA4	
	.extern	_MCU_vISR_99_INTDMA5	
	.extern	_MCU_vISR_100_INTDMA6	
	.extern	_MCU_vISR_101_INTDMA7	
	.extern	_MCU_vISR_102_INTDMA8	
	.extern	_MCU_vISR_103_INTDMA9	
	.extern	_MCU_vISR_104_INTDMA10	
	.extern	_MCU_vISR_105_INTDMA11	
	.extern	_MCU_vISR_106_INTDMA12	
	.extern	_MCU_vISR_107_INTDMA13	
	.extern	_MCU_vISR_108_INTDMA14	
	.extern	_MCU_vISR_109_INTDMA15	
	.extern	_MCU_vISR_110_INTRIIC0LEE	
	.extern	_MCU_vISR_111_INTRIIC0RI	
	.extern	_MCU_vISR_112_INTRIIC0TI	
	.extern	_MCU_vISR_113_INTRIIC0TEI	
	.extern	_MCU_vISR_114_INTRIIC1LEE	
	.extern	_MCU_vISR_115_INTRIIC1RI	
	.extern	_MCU_vISR_116_INTRIIC1TI	
	.extern	_MCU_vISR_117_INTRIIC1TEI	
	.extern	_MCU_vISR_118_INTRCAN1ERR	
	.extern	_MCU_vISR_119_INTRCAN1REC	
	.extern	_MCU_vISR_120_INTRCAN1TRX	
	.extern	_MCU_vISR_121_INTTAUJ0I0	
	.extern	_MCU_vISR_122_INTTAUJ0I1	
	.extern	_MCU_vISR_123_INTTAUJ0I2	
	.extern	_MCU_vISR_124_INTTAUJ0I3	
	.extern	_MCU_vISR_125_INTOSTM0	
	.extern	_MCU_vISR_126_INTOSTM1	
	.extern	_MCU_vISR_127_INTCSIGT1IRE	
	.extern	_MCU_vISR_128_INTCSIG1IR	
	.extern	_MCU_vISR_129_INTCSIG1IC	
	.extern	_MCU_vISR_130_INTCSIGT2IRE	
	.extern	_MCU_vISR_131_INTCSIG2IR	
	.extern	_MCU_vISR_132_INTCSIG2IC	
	.extern	_MCU_vISR_133_INTCSIGT3IRE	
	.extern	_MCU_vISR_134_INTCSIG3IR	
	.extern	_MCU_vISR_135_INTCSIG3IC	
	.extern	_MCU_vISR_136_INTCSIH1IRE	
	.extern	_MCU_vISR_137_INTCSIH1IR	
	.extern	_MCU_vISR_138_INTCSIH1IC	
	.extern	_MCU_vISR_139_INTCSIH1IJC	
	.extern	_MCU_vISR_140_INTQFULL	
	.extern	_MCU_vISR_141_INTPWGA0	
	.extern	_MCU_vISR_142_INTPWGA1	
	.extern	_MCU_vISR_143_INTPWGA2	
	.extern	_MCU_vISR_144_INTPWGA3	
	.extern	_MCU_vISR_145_INTPWGA4	
	.extern	_MCU_vISR_146_INTPWGA5	
	.extern	_MCU_vISR_147_INTPWGA6	
	.extern	_MCU_vISR_148_INTPWGA7	
	.extern	_MCU_vISR_149_INTPWGA8	
	.extern	_MCU_vISR_150_INTPWGA9	
	.extern	_MCU_vISR_151_INTPWGA10	
	.extern	_MCU_vISR_152_INTPWGA11	
	.extern	_MCU_vISR_153_INTPWGA12	
	.extern	_MCU_vISR_154_INTPWGA13	
	.extern	_MCU_vISR_155_INTPWGA14	
	.extern	_MCU_vISR_156_INTPWGA15	
	.extern	_MCU_vISR_157_INTPWGA16	
	.extern	_MCU_vISR_158_INTPWGA17	
	.extern	_MCU_vISR_159_INTPWGA18	
	.extern	_MCU_vISR_160_INTPWGA19	
	.extern	_MCU_vISR_161_INTPWGA20	
	.extern	_MCU_vISR_162_INTPWGA21	
	.extern	_MCU_vISR_163_INTPWGA22	
	.extern	_MCU_vISR_164_INTPWGA23	
	.extern	_MCU_vISR_165_INTICUSTWRDY	
	.extern	_MCU_vISR_166_INTICUSTRRDY	
	.extern	_MCU_vISR_167_Reserved	
	.extern	_MCU_vISR_168_Reserved	
	.extern	_MCU_vISR_169_Reserved	
	.extern	_MCU_vISR_170_Reserved	
	.extern	_MCU_vISR_171_Reserved	
	.extern	_MCU_vISR_172_INTFLENDNM	
	.extern	_MCU_vISR_173_Reserved	
	.extern	_MCU_vISR_174_INTLCBI0RDY	
	.extern	_MCU_vISR_175_INTLCBI0EMPTY	
	.extern	_MCU_vISR_176_INTLCBI0HALF	
	.extern	_MCU_vISR_177_INTLCBI0FULL	
	.extern	_MCU_vISR_178_INTLCBI0QTR	
	.extern	_MCU_vISR_179_INTLCBI03QTR	
	.extern	_MCU_vISR_180_INTRCAN2ERR	
	.extern	_MCU_vISR_181_INTRCAN2REC	
	.extern	_MCU_vISR_182_INTRCAN2TRX	
	.extern	_MCU_vISR_183_INTPCMP0FFIL	
	.extern	_MCU_vISR_184_INTPCMP0FERR	
	.extern	_MCU_vISR_185_INTISM0REACHED	
	.extern	_MCU_vISR_186_INTISM0DONE	
	.extern	_MCU_vISR_187_INTISM0ZPDAD	
	.extern	_MCU_vISR_188_Reserved	
	.extern	_MCU_vISR_189_INTSSIF0	
	.extern	_MCU_vISR_190_INTSSIF0RX	
	.extern	_MCU_vISR_191_INTSSIF0TX	
	.extern	_MCU_vISR_192_INTSSIF1	
	.extern	_MCU_vISR_193_INTSSIF1RX	
	.extern	_MCU_vISR_194_INTSSIF1TX	
	.extern	_MCU_vISR_195_Reserved	
	.extern	_MCU_vISR_196_Reserved	
	.extern	_MCU_vISR_197_Reserved	
	.extern	_MCU_vISR_198_Reserved	
	.extern	_MCU_vISR_199_Reserved	
	.extern	_MCU_vISR_200_Reserved	
	.extern	_MCU_vISR_201_Reserved	
	.extern	_MCU_vISR_202_Reserved	
	.extern	_MCU_vISR_203_Reserved	
	.extern	_MCU_vISR_204_Reserved	
	.extern	_MCU_vISR_205_Reserved	
	.extern	_MCU_vISR_206_Reserved	
	.extern	_MCU_vISR_207_Reserved	
	.extern	_MCU_vISR_208_Reserved	
	.extern	_MCU_vISR_209_Reserved	
	.extern	_MCU_vISR_210_Reserved	
	.extern	_MCU_vISR_211_Reserved	
	.extern	_MCU_vISR_212_Reserved	
	.extern	_MCU_vISR_213_Reserved	
	.extern	_MCU_vISR_214_Reserved	
	.extern	_MCU_vISR_215_INTRLIN32UR2	
	.extern	_MCU_vISR_216_INTRLIN32UR1	
	.extern	_MCU_vISR_217_INTRLIN32UR0	
	.extern	_MCU_vISR_218_INTRLIN33UR2	
	.extern	_MCU_vISR_219_INTRLIN33UR1	
	.extern	_MCU_vISR_220_INTRLIN33UR0	
	.extern	_MCU_vISR_221_Reserved	
	.extern	_MCU_vISR_222_Reserved	
	.extern	_MCU_vISR_223_Reserved	
	.extern	_MCU_vISR_224_Reserved	
	.extern	_MCU_vISR_225_Reserved	
	.extern	_MCU_vISR_226_Reserved	
	.extern	_MCU_vISR_227_Reserved	
	.extern	_MCU_vISR_228_Reserved	
	.extern	_MCU_vISR_229_Reserved	
	.extern	_MCU_vISR_230_Reserved	
	.extern	_MCU_vISR_231_Reserved	
	.extern	_MCU_vISR_232_Reserved	
	.extern	_MCU_vISR_233_Reserved	
	.extern	_MCU_vISR_234_Reserved	
	.extern	_MCU_vISR_235_Reserved	
	.extern	_MCU_vISR_236_Reserved	
	.extern	_MCU_vISR_237_Reserved	
	.extern	_MCU_vISR_238_Reserved	
	.extern	_MCU_vISR_239_Reserved	
	.extern	_MCU_vISR_240_Reserved	
	.extern	_MCU_vISR_241_Reserved	
	.extern	_MCU_vISR_242_Reserved	
	.extern	_MCU_vISR_243_Reserved	
	.extern	_MCU_vISR_244_Reserved	
	.extern	_MCU_vISR_245_Reserved	
	.extern	_MCU_vISR_246_Reserved	
	.extern	_MCU_vISR_247_Reserved	
	.extern	_MCU_vISR_248_INTMISRERR	
	.extern	_MCU_vISR_249_INTVPISG1OVFERR	
	.extern	_MCU_vISR_250_INTVPISG2OVFERR	
	.extern	_MCU_vISR_251_INTVPISG3OVFERR	
	.extern	_MCU_vISR_252_Reserved	
	.extern	_MCU_vISR_253_INTVPISG5OVFERR	
	.extern	_MCU_vISR_254_Reserved	
	.extern	_MCU_vISR_255_INTINTERNALBUSERR	

/*#########################################################

		-- this is normal interrupt vector table list --
		
#########################################################*/			
	.word	_MCU_vISR_0_INTWDTA0	
	.word	_MCU_vISR_1_INTWDTA1	
	.word	_MCU_vISR_2_INTRTCA01S	
	.word	_MCU_vISR_3_INTRTCA0AL	
	.word	_MCU_vISR_4_INTRTCA0R	
	.word	_MCU_vISR_5_INTAWOT0	
	.word	_MCU_vISR_6_INTP0	
	.word	_MCU_vISR_7_INTP1	
	.word	_MCU_vISR_8_INTP2	
	.word	_MCU_vISR_9_INTP3	
	.word	_MCU_vISR_10_INTP4	
	.word	_MCU_vISR_11_INTP5	
	.word	_MCU_vISR_12_INTP6	
	.word	_MCU_vISR_13_INTP7	
	.word	_MCU_vISR_14_INTP8	
	.word	_MCU_vISR_15_INTP9	
	.word	_MCU_vISR_16_INTP10	
	.word	_MCU_vISR_17_INTTAUB0I0	
	.word	_MCU_vISR_18_INTTAUB0I1	
	.word	_MCU_vISR_19_INTTAUB0I2	
	.word	_MCU_vISR_20_INTTAUB0I3	
	.word	_MCU_vISR_21_INTTAUB0I4	
	.word	_MCU_vISR_22_INTTAUB0I5	
	.word	_MCU_vISR_23_INTTAUB0I6	
	.word	_MCU_vISR_24_INTTAUB0I7	
	.word	_MCU_vISR_25_INTTAUB0I8	
	.word	_MCU_vISR_26_INTTAUB0I9	
	.word	_MCU_vISR_27_INTTAUB0I10	
	.word	_MCU_vISR_28_INTTAUB0I11	
	.word	_MCU_vISR_29_INTTAUB0I12	
	.word	_MCU_vISR_30_INTTAUB0I13	
	.word	_MCU_vISR_31_INTTAUB0I14	
	.word	_MCU_vISR_32_INTTAUB0I15	
	.word	_MCU_vISR_33_INTTAUB1I0	
	.word	_MCU_vISR_34_INTTAUB1I1	
	.word	_MCU_vISR_35_INTTAUB1I2	
	.word	_MCU_vISR_36_INTTAUB1I3	
	.word	_MCU_vISR_37_INTTAUB1I4	
	.word	_MCU_vISR_38_INTTAUB1I5	
	.word	_MCU_vISR_39_INTTAUB1I6	
	.word	_MCU_vISR_40_INTTAUB1I7	
	.word	_MCU_vISR_41_INTTAUB1I8	
	.word	_MCU_vISR_42_INTTAUB1I9	
	.word	_MCU_vISR_43_INTTAUB1I10	
	.word	_MCU_vISR_44_INTTAUB1I11	
	.word	_MCU_vISR_45_INTTAUB1I12	
	.word	_MCU_vISR_46_INTTAUB1I13	
	.word	_MCU_vISR_47_INTTAUB1I14	
	.word	_MCU_vISR_48_INTTAUB1I15	
	.word	_MCU_vISR_49_INTTAUB2I0	
	.word	_MCU_vISR_50_INTTAUB2I1	
	.word	_MCU_vISR_51_INTTAUB2I2	
	.word	_MCU_vISR_52_INTTAUB2I3	
	.word	_MCU_vISR_53_INTTAUB2I4	
	.word	_MCU_vISR_54_INTTAUB2I5	
	.word	_MCU_vISR_55_INTTAUB2I6	
	.word	_MCU_vISR_56_INTTAUB2I7	
	.word	_MCU_vISR_57_INTTAUB2I8	
	.word	_MCU_vISR_58_INTTAUB2I9	
	.word	_MCU_vISR_59_INTTAUB2I10	
	.word	_MCU_vISR_60_INTTAUB2I11	
	.word	_MCU_vISR_61_INTTAUB2I12	
	.word	_MCU_vISR_62_INTTAUB2I13	
	.word	_MCU_vISR_63_INTTAUB2I14	
	.word	_MCU_vISR_64_INTTAUB2I15	
	.word	_MCU_vISR_65_INTADCE0TSN	
	.word	_MCU_vISR_66_INTADCE0I1	
	.word	_MCU_vISR_67_INTADCE0I2	
	.word	_MCU_vISR_68_INTADCE0I3	
	.word	_MCU_vISR_69_INTRCANGERR	
	.word	_MCU_vISR_70_INTRCANGRECC	
	.word	_MCU_vISR_71_INTRCAN0ERR	
	.word	_MCU_vISR_72_INTRCAN0REC	
	.word	_MCU_vISR_73_INTRCAN0TRX	
	.word	_MCU_vISR_74_INTCSIGT0IRE	
	.word	_MCU_vISR_75_INTCSIG0IR	
	.word	_MCU_vISR_76_INTCSIG0IC	
	.word	_MCU_vISR_77_INTCSIH0IRE	
	.word	_MCU_vISR_78_INTCSIH0IR	
	.word	_MCU_vISR_79_INTCSIH0IC	
	.word	_MCU_vISR_80_INTCSIH0IJC	
	.word	_MCU_vISR_81_INTRLIN30UR2	
	.word	_MCU_vISR_82_INTRLIN30UR1	
	.word	_MCU_vISR_83_INTRLIN30UR0	
	.word	_MCU_vISR_84_INTRLIN31UR2	
	.word	_MCU_vISR_85_INTRLIN31UR1	
	.word	_MCU_vISR_86_INTRLIN31UR0	
	.word	_MCU_vISR_87_INTSG0TI	
	.word	_MCU_vISR_88_INTSG1TI	
	.word	_MCU_vISR_89_INTSG2TI	
	.word	_MCU_vISR_90_INTSG3TI	
	.word	_MCU_vISR_91_INTSG4TI	
	.word	_MCU_vISR_92_INTDCUTDI	
	.word	_MCU_vISR_93_INTDMAERR	
	.word	_MCU_vISR_94_INTDMA0	
	.word	_MCU_vISR_95_INTDMA1	
	.word	_MCU_vISR_96_INTDMA2	
	.word	_MCU_vISR_97_INTDMA3	
	.word	_MCU_vISR_98_INTDMA4	
	.word	_MCU_vISR_99_INTDMA5	
	.word	_MCU_vISR_100_INTDMA6	
	.word	_MCU_vISR_101_INTDMA7	
	.word	_MCU_vISR_102_INTDMA8	
	.word	_MCU_vISR_103_INTDMA9	
	.word	_MCU_vISR_104_INTDMA10	
	.word	_MCU_vISR_105_INTDMA11	
	.word	_MCU_vISR_106_INTDMA12	
	.word	_MCU_vISR_107_INTDMA13	
	.word	_MCU_vISR_108_INTDMA14	
	.word	_MCU_vISR_109_INTDMA15	
	.word	_MCU_vISR_110_INTRIIC0LEE	
	.word	_MCU_vISR_111_INTRIIC0RI	
	.word	_MCU_vISR_112_INTRIIC0TI	
	.word	_MCU_vISR_113_INTRIIC0TEI	
	.word	_MCU_vISR_114_INTRIIC1LEE	
	.word	_MCU_vISR_115_INTRIIC1RI	
	.word	_MCU_vISR_116_INTRIIC1TI	
	.word	_MCU_vISR_117_INTRIIC1TEI	
	.word	_MCU_vISR_118_INTRCAN1ERR	
	.word	_MCU_vISR_119_INTRCAN1REC	
	.word	_MCU_vISR_120_INTRCAN1TRX	
	.word	_MCU_vISR_121_INTTAUJ0I0	
	.word	_MCU_vISR_122_INTTAUJ0I1	
	.word	_MCU_vISR_123_INTTAUJ0I2	
	.word	_MCU_vISR_124_INTTAUJ0I3	
	.word	_MCU_vISR_125_INTOSTM0	
	.word	_MCU_vISR_126_INTOSTM1	
	.word	_MCU_vISR_127_INTCSIGT1IRE	
	.word	_MCU_vISR_128_INTCSIG1IR	
	.word	_MCU_vISR_129_INTCSIG1IC	
	.word	_MCU_vISR_130_INTCSIGT2IRE	
	.word	_MCU_vISR_131_INTCSIG2IR	
	.word	_MCU_vISR_132_INTCSIG2IC	
	.word	_MCU_vISR_133_INTCSIGT3IRE	
	.word	_MCU_vISR_134_INTCSIG3IR	
	.word	_MCU_vISR_135_INTCSIG3IC	
	.word	_MCU_vISR_136_INTCSIH1IRE	
	.word	_MCU_vISR_137_INTCSIH1IR	
	.word	_MCU_vISR_138_INTCSIH1IC	
	.word	_MCU_vISR_139_INTCSIH1IJC	
	.word	_MCU_vISR_140_INTQFULL	
	.word	_MCU_vISR_141_INTPWGA0	
	.word	_MCU_vISR_142_INTPWGA1	
	.word	_MCU_vISR_143_INTPWGA2	
	.word	_MCU_vISR_144_INTPWGA3	
	.word	_MCU_vISR_145_INTPWGA4	
	.word	_MCU_vISR_146_INTPWGA5	
	.word	_MCU_vISR_147_INTPWGA6	
	.word	_MCU_vISR_148_INTPWGA7	
	.word	_MCU_vISR_149_INTPWGA8	
	.word	_MCU_vISR_150_INTPWGA9	
	.word	_MCU_vISR_151_INTPWGA10	
	.word	_MCU_vISR_152_INTPWGA11	
	.word	_MCU_vISR_153_INTPWGA12	
	.word	_MCU_vISR_154_INTPWGA13	
	.word	_MCU_vISR_155_INTPWGA14	
	.word	_MCU_vISR_156_INTPWGA15	
	.word	_MCU_vISR_157_INTPWGA16	
	.word	_MCU_vISR_158_INTPWGA17	
	.word	_MCU_vISR_159_INTPWGA18	
	.word	_MCU_vISR_160_INTPWGA19	
	.word	_MCU_vISR_161_INTPWGA20	
	.word	_MCU_vISR_162_INTPWGA21	
	.word	_MCU_vISR_163_INTPWGA22	
	.word	_MCU_vISR_164_INTPWGA23	
	.word	_MCU_vISR_165_INTICUSTWRDY	
	.word	_MCU_vISR_166_INTICUSTRRDY	
	.word	_MCU_vISR_167_Reserved	
	.word	_MCU_vISR_168_Reserved	
	.word	_MCU_vISR_169_Reserved	
	.word	_MCU_vISR_170_Reserved	
	.word	_MCU_vISR_171_Reserved	
	.word	_MCU_vISR_172_INTFLENDNM	
	.word	_MCU_vISR_173_Reserved	
	.word	_MCU_vISR_174_INTLCBI0RDY	
	.word	_MCU_vISR_175_INTLCBI0EMPTY	
	.word	_MCU_vISR_176_INTLCBI0HALF	
	.word	_MCU_vISR_177_INTLCBI0FULL	
	.word	_MCU_vISR_178_INTLCBI0QTR	
	.word	_MCU_vISR_179_INTLCBI03QTR	
	.word	_MCU_vISR_180_INTRCAN2ERR	
	.word	_MCU_vISR_181_INTRCAN2REC	
	.word	_MCU_vISR_182_INTRCAN2TRX	
	.word	_MCU_vISR_183_INTPCMP0FFIL	
	.word	_MCU_vISR_184_INTPCMP0FERR	
	.word	_MCU_vISR_185_INTISM0REACHED	
	.word	_MCU_vISR_186_INTISM0DONE	
	.word	_MCU_vISR_187_INTISM0ZPDAD	
	.word	_MCU_vISR_188_Reserved	
	.word	_MCU_vISR_189_INTSSIF0	
	.word	_MCU_vISR_190_INTSSIF0RX	
	.word	_MCU_vISR_191_INTSSIF0TX	
	.word	_MCU_vISR_192_INTSSIF1	
	.word	_MCU_vISR_193_INTSSIF1RX	
	.word	_MCU_vISR_194_INTSSIF1TX	
	.word	_MCU_vISR_195_Reserved	
	.word	_MCU_vISR_196_Reserved	
	.word	_MCU_vISR_197_Reserved	
	.word	_MCU_vISR_198_Reserved	
	.word	_MCU_vISR_199_Reserved	
	.word	_MCU_vISR_200_Reserved	
	.word	_MCU_vISR_201_Reserved	
	.word	_MCU_vISR_202_Reserved	
	.word	_MCU_vISR_203_Reserved	
	.word	_MCU_vISR_204_Reserved	
	.word	_MCU_vISR_205_Reserved	
	.word	_MCU_vISR_206_Reserved	
	.word	_MCU_vISR_207_Reserved	
	.word	_MCU_vISR_208_Reserved	
	.word	_MCU_vISR_209_Reserved	
	.word	_MCU_vISR_210_Reserved	
	.word	_MCU_vISR_211_Reserved	
	.word	_MCU_vISR_212_Reserved	
	.word	_MCU_vISR_213_Reserved	
	.word	_MCU_vISR_214_Reserved	
	.word	_MCU_vISR_215_INTRLIN32UR2	
	.word	_MCU_vISR_216_INTRLIN32UR1	
	.word	_MCU_vISR_217_INTRLIN32UR0	
	.word	_MCU_vISR_218_INTRLIN33UR2	
	.word	_MCU_vISR_219_INTRLIN33UR1	
	.word	_MCU_vISR_220_INTRLIN33UR0	
	.word	_MCU_vISR_221_Reserved	
	.word	_MCU_vISR_222_Reserved	
	.word	_MCU_vISR_223_Reserved	
	.word	_MCU_vISR_224_Reserved	
	.word	_MCU_vISR_225_Reserved	
	.word	_MCU_vISR_226_Reserved	
	.word	_MCU_vISR_227_Reserved	
	.word	_MCU_vISR_228_Reserved	
	.word	_MCU_vISR_229_Reserved	
	.word	_MCU_vISR_230_Reserved	
	.word	_MCU_vISR_231_Reserved	
	.word	_MCU_vISR_232_Reserved	
	.word	_MCU_vISR_233_Reserved	
	.word	_MCU_vISR_234_Reserved	
	.word	_MCU_vISR_235_Reserved	
	.word	_MCU_vISR_236_Reserved	
	.word	_MCU_vISR_237_Reserved	
	.word	_MCU_vISR_238_Reserved	
	.word	_MCU_vISR_239_Reserved	
	.word	_MCU_vISR_240_Reserved	
	.word	_MCU_vISR_241_Reserved	
	.word	_MCU_vISR_242_Reserved	
	.word	_MCU_vISR_243_Reserved	
	.word	_MCU_vISR_244_Reserved	
	.word	_MCU_vISR_245_Reserved	
	.word	_MCU_vISR_246_Reserved	
	.word	_MCU_vISR_247_Reserved	
	.word	_MCU_vISR_248_INTMISRERR	
	.word	_MCU_vISR_249_INTVPISG1OVFERR	
	.word	_MCU_vISR_250_INTVPISG2OVFERR	
	.word	_MCU_vISR_251_INTVPISG3OVFERR	
	.word	_MCU_vISR_252_Reserved	
	.word	_MCU_vISR_253_INTVPISG5OVFERR	
	.word	_MCU_vISR_254_Reserved	
	.word	_MCU_vISR_255_INTINTERNALBUSERR	

-------------------------------------------------------------------------------
-----end of interrupt table list ---------------------------------------------
-------------------------------------------------------------------------------



-------------------------------------------------------------------------------
-----user low level initialization functon--------------------------------------
-------------------------------------------------------------------------------
  .weak	___low_level_init

-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-----MCU reset fucntion in text section ---------------------------------------
-------------------------------------------------------------------------------
------YES, we change the locate section from intvect to normal text sectin-----
  .text
-------------------------------------------------------------------------------

--------------MCUReset function code -----------------------------------------
_MCUReset:

  movhi	hi(___ghsbegin_sdabase),zero,gp  -- Initialization of the global pointer
  movea	lo(___ghsbegin_sdabase),gp,gp

  movhi	hi(___ghsbegin_robase),zero,tp  -- Initialization of the text pointer
  movea	lo(___ghsbegin_robase),tp,tp

  movhi	hi(___ghsend_stack-4),zero,sp   -- Initialization of the stack pointer
  movea	lo(___ghsend_stack-4),sp,sp

  mov -4,r1
  and r1,sp
  
  mov (IRQ_TABLE_START+APP_CODE_MAP_START),r1  /*Initialization of the interrupt base pointer*/
  ldsr r1,intbp,1  	 /* base pointer value is set by user in _F1L_UsrCfg.h*/

#if (APP_CODE_MAP_START !=0)

  mov APP_CODE_MAP_START, r10/* First set EBASE register address*/

  ldsr r10, EBASE, 1  /* set 0x0 or 0x1 to EBASE.RINT for reduced interrupt,ori  1, r10 */

  stsr PSW, r10, 0 /* then set 1 to PSW.EBV -> RBASE!=EBASE*/
  mov  0x8000, r11
  or   r11, r10
  ldsr r10, PSW, 0
  
#endif

  --------------------------- Clear local RAM0 data to 0x00000000 at reset_up
  mov ___ghs_ramstart0,  r6  -- start of local main RAM
  mov ___ghs_ramend0,   r7   -- end of local main RAM
  mov r0, r1

1:
  st.dw   r0, 0[r6]
  addi    8, r6, r6
  cmp r7, r6
  bl 1b

  --------------------------- Clear local RAM1 data to 0x00000000 at reset_up
  mov ___ghs_ramstart1,  r6  -- start of local main RAM
  mov ___ghs_ramend1,   r7   -- end of local main RAM
  mov r0, r1

2:
  st.dw   r0, 0[r6]
  addi    8, r6, r6
  cmp r7, r6
  bl 2b


 --------------------------- Clear Retention RAM data to 0x00000000 at reset_up
  mov ___ghs_ramstartr,   r6  -- start of local Retention RAM
  mov ___ghs_ramendr,   r7    -- end of local Retention RAM
  mov r0, r1

3:
  st.dw   r0, 0[r6]
  addi    8, r6, r6
  cmp r7, r6
  bl 3b

----------------------------------------------------
----Either disable ECC------------------------------
----------------------------------------------------

-- mov 0xFFC65400, r6
-- mov 0x4001, r7 
-- st.w   r7, 0[r6]   
----------------------------------------------------

----------------------------------------------------
-- enable coprocessor (required by sdram init) -----
----------------------------------------------------

  mov 0x00010000, r6 
  stsr 5, r7  -- store PSW to r7
  or  r6, r7  -- set bit 16 
  ldsr r7, 5  -- write PSW
----------------------------------------------------


  jarl	___low_level_init, lp    -- Jump to the HW initialisation function

  jr    __start   	-- Jump to the initialisation functions of the library
			-- for data initialize
			--and from there to C function main()


-------end of MCUReset function code -----------------------------------------


#endif   /* __OS_HANDLES__ */  

#pragma endasm
#pragma ghs section text = default

