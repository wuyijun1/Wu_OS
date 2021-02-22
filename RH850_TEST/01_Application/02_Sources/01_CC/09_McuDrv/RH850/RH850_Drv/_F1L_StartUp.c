/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1X_StartUp.850
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

#include "..\F1L_UsrCfg\_F1L_UsrCfg.h"

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

	jr	_MCUReset		--/*0x00000000 + 0x0000*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0004*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0008*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x000C*/			
	jr	_SYSERR			--/*0x00000000 + 0x0010*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0014*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0018*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x001C*/			
	jr	_HVTRAP			--/*0x00000000 + 0x0020*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0024*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0028*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x002C*/			
	jr	_FETRAPEX		--/*0x00000000 + 0x0030*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0034*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0038*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x003C*/			
	jr	_EITRAP0		--/*0x00000000 + 0x0040*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0044*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0048*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x004C*/			
	jr	_EITRAP1		--/*0x00000000 + 0x0050*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0054*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0058*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x005C*/			
	jr	_RIEX			--/*0x00000000 + 0x0060*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0064*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0068*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x006C*/			
	jr	_FPP_FPI		--/*0x00000000 + 0x0070*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0074*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0078*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x007C*/			
	jr	_UCPOP			--/*0x00000000 + 0x0080*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0084*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0088*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x008C*/			
	jr	_MIP_MDP		--/*0x00000000 + 0x0090*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0094*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0098*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x009C*/			
	jr	_PIE			--/*0x00000000 + 0x00A0*/
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00A4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00A8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00AC*/			
	jr	_Debug			--/*0x00000000 + 0x00B0*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00B4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00B8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00BC*/			
	jr	_MAE			--/*0x00000000 + 0x00C0*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00C4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00C8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00CC*/			
	jr	_Reserved		--/*0x00000000 + 0x00D0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00D4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00D8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00DC*/			
	jr	_FENMI			--/*0x00000000 + 0x00E0*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00E4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00E8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00EC*/			
	jr	_FEINT			--/*0x00000000 + 0x00F0*/	
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00F4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00F8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x00FC*/			
	jr	_EINTPRIO_0		--/*0x00000000 + 0x0100 -->if RBASE.RINT=1, all EINTPRIO_x using this entry if using priority mode*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0104*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0108*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x010C*/			
	jr	_EINTPRIO_1		--/*0x00000000 + 0x0110*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0114*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0118*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x011C*/			
	jr	_EINTPRIO_2		--/*0x00000000 + 0x0120*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0124*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0128*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x012C*/			
	jr	_EINTPRIO_3		--/*0x00000000 + 0x0130*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0134*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0138*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x013C*/			
	jr	_EINTPRIO_4		--/*0x00000000 + 0x0140*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0144*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0148*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x014C*/			
	jr	_EINTPRIO_5		--/*0x00000000 + 0x0150*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0154*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0158*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x015C*/			
	jr	_EINTPRIO_6		--/*0x00000000 + 0x0160*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0164*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0168*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x016C*/			
	jr	_EINTPRIO_7		--/*0x00000000 + 0x0170*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0174*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0178*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x017C*/			
	jr	_EINTPRIO_8		--/*0x00000000 + 0x0180*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0184*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0188*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x018C*/			
	jr	_EINTPRIO_9		--/*0x00000000 + 0x0190*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0194*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x0198*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x019C*/			
	jr	_EINTPRIO_10		--/*0x00000000 + 0x01A0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01A4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01A8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01AC*/			
	jr	_EINTPRIO_11		--/*0x00000000 + 0x01B0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01B4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01B8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01BC*/			
	jr	_EINTPRIO_12		--/*0x00000000 + 0x01C0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01C4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01C8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01CC*/			
	jr	_EINTPRIO_13		--/*0x00000000 + 0x01D0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01D4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01D8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01DC*/			
	jr	_EINTPRIO_14		--/*0x00000000 + 0x01E0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01E4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01E8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01EC*/			
	jr	_EINTPRIO_15		--/*0x00000000 + 0x01F0*/		
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01F4*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01F8*/			
	jr	_MCU_vNotExpINT		--/*0x00000000 + 0x01FC*/			

------------------------------------------------------------------------
------user interrupt table list, all the function using table mode------
------------------------------------------------------------------------
------YES, we are also in intvect section,offset address only-----------
------------------------------------------------------------------------

  .offset IRQ_TABLE_START
	.extern _MCU_vISR_0_ICTAUD0I0_ICCSIH2IC_1
	.extern _MCU_vISR_1_ICTAUD0I2_ICCSIH3IC_1
	.extern _MCU_vISR_2_ICTAUD0I4
	.extern _MCU_vISR_3_ICTAUD0I6
	.extern _MCU_vISR_4_ICTAUD0I8
	.extern _MCU_vISR_5_ICTAUD0I10_ICCSIH3IR_1
	.extern _MCU_vISR_6_ICTAUD0I12_ICCSIH3IRE_1
	.extern _MCU_vISR_7_ICTAUD0I14_ICCSIH3IJC_1
	.extern _MCU_vISR_8_ICTAPA0IPEK0_ICCSIH1IC_1
	.extern _MCU_vISR_9_ICTAPA0IVLY0_ICCSIH1IR_1
	.extern _MCU_vISR_10_ICADCA0I0
	.extern _MCU_vISR_11_ICADCA0I1
	.extern _MCU_vISR_12_ICADCA0I2
	.extern _MCU_vISR_13_ICDCUTDI
	.extern _MCU_vISR_14_ICRCANGERR
	.extern _MCU_vISR_15_ICRCANGRECC
	.extern _MCU_vISR_16_ICRCAN0ERR
	.extern _MCU_vISR_17_ICRCAN0REC
	.extern _MCU_vISR_18_ICRCAN0TRX
	.extern _MCU_vISR_19_ICCSIG0IC_ICCSIH1IRE_1
	.extern _MCU_vISR_20_ICCSIG0IR_ICCSIH1IJC_1
	.extern _MCU_vISR_21_ICCSIH0IC
	.extern _MCU_vISR_22_ICCSIH0IR
	.extern _MCU_vISR_23_ICCSIH0IRE
	.extern _MCU_vISR_24_ICCSIH0IJC
	.extern _MCU_vISR_25_ICRLIN30
	.extern _MCU_vISR_26_ICRLIN30UR0
	.extern _MCU_vISR_27_ICRLIN30UR1
	.extern _MCU_vISR_28_ICRLIN30UR2
	.extern _MCU_vISR_29_ICP0_ICCSIH2IR_1
	.extern _MCU_vISR_30_ICP1_ICCSIH2IRE_1
	.extern _MCU_vISR_31_ICP2_ICCSIH2IJC_1
	.extern _MCU_vISR_32_ICWDTA0
	.extern _MCU_vISR_33_ICWDTA1
	.extern _MCU_vISR_34_ICP3
	.extern _MCU_vISR_35_ICP4
	.extern _MCU_vISR_36_ICP5
	.extern _MCU_vISR_37_ICP10
	.extern _MCU_vISR_38_ICP11
	.extern _MCU_vISR_39_ICTAUD0I1
	.extern _MCU_vISR_40_ICTAUD0I3
	.extern _MCU_vISR_41_ICTAUD0I5
	.extern _MCU_vISR_42_ICTAUD0I7
	.extern _MCU_vISR_43_ICTAUD0I9
	.extern _MCU_vISR_44_ICTAUD0I11
	.extern _MCU_vISR_45_ICTAUD0I13
	.extern _MCU_vISR_46_ICTAUD0I15
	.extern _MCU_vISR_47_ICADCA0ERR
	.extern _MCU_vISR_48_Reserved
	.extern _MCU_vISR_49_ICCSIG0IRE
	.extern _MCU_vISR_50_ICRLIN20
	.extern _MCU_vISR_51_ICRLIN21
	.extern _MCU_vISR_52_ICDMA0
	.extern _MCU_vISR_53_ICDMA1
	.extern _MCU_vISR_54_ICDMA2
	.extern _MCU_vISR_55_ICDMA3
	.extern _MCU_vISR_56_ICDMA4
	.extern _MCU_vISR_57_ICDMA5
	.extern _MCU_vISR_58_ICDMA6
	.extern _MCU_vISR_59_ICDMA7
	.extern _MCU_vISR_60_ICDMA8
	.extern _MCU_vISR_61_ICDMA9
	.extern _MCU_vISR_62_ICDMA10
	.extern _MCU_vISR_63_ICDMA11
	.extern _MCU_vISR_64_ICDMA12
	.extern _MCU_vISR_65_ICDMA13
	.extern _MCU_vISR_66_ICDMA14
	.extern _MCU_vISR_67_ICDMA15
	.extern _MCU_vISR_68_ICRIIC0TI
	.extern _MCU_vISR_69_ICRIIC0TEI
	.extern _MCU_vISR_70_ICRIIC0RI
	.extern _MCU_vISR_71_ICRIIC0EE
	.extern _MCU_vISR_72_ICTAUJ0I0
	.extern _MCU_vISR_73_ICTAUJ0I1
	.extern _MCU_vISR_74_ICTAUJ0I2
	.extern _MCU_vISR_75_ICTAUJ0I3
	.extern _MCU_vISR_76_ICOSTM0
	.extern _MCU_vISR_77_ICENCA0IOV_ICPWGA4
	.extern _MCU_vISR_78_ICENCA0IUD_ICPWGA5
	.extern _MCU_vISR_79_ICENCA0I0_ICPWGA6
	.extern _MCU_vISR_80_ICENCA0I1_ICPWGA7
	.extern _MCU_vISR_81_ICENCA0IEC
	.extern _MCU_vISR_82_ICKR0
	.extern _MCU_vISR_83_ICQFULL
	.extern _MCU_vISR_84_ICPWGA0
	.extern _MCU_vISR_85_ICPWGA1
	.extern _MCU_vISR_86_ICPWGA2
	.extern _MCU_vISR_87_ICPWGA3
	.extern _MCU_vISR_88_ICPWGA8
	.extern _MCU_vISR_89_ICPWGA9
	.extern _MCU_vISR_90_ICPWGA10
	.extern _MCU_vISR_91_ICPWGA11
	.extern _MCU_vISR_92_ICPWGA12
	.extern _MCU_vISR_93_ICPWGA13
	.extern _MCU_vISR_94_ICPWGA14
	.extern _MCU_vISR_95_ICPWGA15
	.extern _MCU_vISR_96_Reserved
	.extern _MCU_vISR_97_Reserved
	.extern _MCU_vISR_98_Reserved
	.extern _MCU_vISR_99_Reserved
	.extern _MCU_vISR_100_Reserved
	.extern _MCU_vISR_101_Reserved
	.extern _MCU_vISR_102_ICFLERR
	.extern _MCU_vISR_103_ICFLENDNM
	.extern _MCU_vISR_104_ICCWEND
	.extern _MCU_vISR_105_ICRCAN1ERR
	.extern _MCU_vISR_106_ICRCAN1REC
	.extern _MCU_vISR_107_ICRCAN1TRX
	.extern _MCU_vISR_108_ICCSIH1IC_ICTAPA0IPEK0_2
	.extern _MCU_vISR_109_ICCSIH1IR_ICTAPA0IVLY0_2
	.extern _MCU_vISR_110_ICCSIH1IRE_ICCSIG0IC_2
	.extern _MCU_vISR_111_ICCSIH1IJC_ICCSIG0IR_2
	.extern _MCU_vISR_112_ICRLIN31
	.extern _MCU_vISR_113_ICRLIN31UR0
	.extern _MCU_vISR_114_ICRLIN31UR1
	.extern _MCU_vISR_115_ICRLIN31UR2
	.extern _MCU_vISR_116_ICPWGA20
	.extern _MCU_vISR_117_ICPWGA21
	.extern _MCU_vISR_118_ICPWGA22
	.extern _MCU_vISR_119_ICPWGA23
	.extern _MCU_vISR_120_ICP6
	.extern _MCU_vISR_121_ICP7
	.extern _MCU_vISR_122_ICP8
	.extern _MCU_vISR_123_ICP12
	.extern _MCU_vISR_124_ICCSIH2IC_ICTAUD0I0_2
	.extern _MCU_vISR_125_ICCSIH2IR_ICP0_2
	.extern _MCU_vISR_126_ICCSIH2IRE_ICP1_2
	.extern _MCU_vISR_127_ICCSIH2IJC_ICP2_2
	.extern _MCU_vISR_128_Reserved
	.extern _MCU_vISR_129_Reserved
	.extern _MCU_vISR_130_Reserved
	.extern _MCU_vISR_131_Reserved
	.extern _MCU_vISR_132_Reserved
	.extern _MCU_vISR_133_Reserved
	.extern _MCU_vISR_134_ICTAUB0I0
	.extern _MCU_vISR_135_ICTAUB0I1
	.extern _MCU_vISR_136_ICTAUB0I2
	.extern _MCU_vISR_137_ICTAUB0I3_ICPWGA16
	.extern _MCU_vISR_138_ICTAUB0I4
	.extern _MCU_vISR_139_ICTAUB0I5_ICPWGA17
	.extern _MCU_vISR_140_ICTAUB0I6
	.extern _MCU_vISR_141_ICTAUB0I7_ICPWGA18
	.extern _MCU_vISR_142_ICTAUB0I8
	.extern _MCU_vISR_143_ICTAUB0I9_ICPWGA19
	.extern _MCU_vISR_144_ICTAUB0I10
	.extern _MCU_vISR_145_ICTAUB0I11_ICPWGA26
	.extern _MCU_vISR_146_ICTAUB0I12
	.extern _MCU_vISR_147_ICTAUB0I13_ICPWGA30
	.extern _MCU_vISR_148_ICTAUB0I14
	.extern _MCU_vISR_149_ICTAUB0I15_ICPWGA31
	.extern _MCU_vISR_150_ICCSIH3IC_ICTAUD0I2_2
	.extern _MCU_vISR_151_ICCSIH3IR_ICTAUD0I10_2
	.extern _MCU_vISR_152_ICCSIH3IRE_ICTAUD0I12_2
	.extern _MCU_vISR_153_ICCSIH3IJC_ICTAUD0I14_2
	.extern _MCU_vISR_154_ICRLIN22
	.extern _MCU_vISR_155_ICRLIN23
	.extern _MCU_vISR_156_ICRLIN32
	.extern _MCU_vISR_157_ICRLIN32UR0
	.extern _MCU_vISR_158_ICRLIN32UR1
	.extern _MCU_vISR_159_ICRLIN32UR2
	.extern _MCU_vISR_160_ICTAUJ1I0
	.extern _MCU_vISR_161_ICTAUJ1I1
	.extern _MCU_vISR_162_ICTAUJ1I2
	.extern _MCU_vISR_163_ICTAUJ1I3
	.extern _MCU_vISR_164_Reserved
	.extern _MCU_vISR_165_Reserved
	.extern _MCU_vISR_166_Reserved
	.extern _MCU_vISR_167_Reserved
	.extern _MCU_vISR_168_Reserved
	.extern _MCU_vISR_169_Reserved
	.extern _MCU_vISR_170_Reserved
	.extern _MCU_vISR_171_Reserved
	.extern _MCU_vISR_172_Reserved
	.extern _MCU_vISR_173_Reserved
	.extern _MCU_vISR_174_Reserved
	.extern _MCU_vISR_175_Reserved
	.extern _MCU_vISR_176_ICPWGA24
	.extern _MCU_vISR_177_ICPWGA25
	.extern _MCU_vISR_178_ICPWGA27
	.extern _MCU_vISR_179_ICPWGA28
	.extern _MCU_vISR_180_ICPWGA29
	.extern _MCU_vISR_181_ICPWGA32
	.extern _MCU_vISR_182_ICPWGA33
	.extern _MCU_vISR_183_ICPWGA34
	.extern _MCU_vISR_184_ICPWGA35
	.extern _MCU_vISR_185_ICPWGA36
	.extern _MCU_vISR_186_ICPWGA37
	.extern _MCU_vISR_187_ICPWGA38
	.extern _MCU_vISR_188_ICPWGA39
	.extern _MCU_vISR_189_ICPWGA40
	.extern _MCU_vISR_190_ICPWGA41
	.extern _MCU_vISR_191_ICPWGA42
	.extern _MCU_vISR_192_ICPWGA43
	.extern _MCU_vISR_193_ICPWGA44
	.extern _MCU_vISR_194_ICPWGA45
	.extern _MCU_vISR_195_ICPWGA46
	.extern _MCU_vISR_196_ICPWGA47
	.extern _MCU_vISR_197_ICP9
	.extern _MCU_vISR_198_ICP13
	.extern _MCU_vISR_199_ICP14
	.extern _MCU_vISR_200_ICP15
	.extern _MCU_vISR_201_ICRTCA01S
	.extern _MCU_vISR_202_ICRTCA0AL
	.extern _MCU_vISR_203_ICRTCA0R
	.extern _MCU_vISR_204_ICADCA1ERR
	.extern _MCU_vISR_205_ICADCA1I0
	.extern _MCU_vISR_206_ICADCA1I1
	.extern _MCU_vISR_207_ICADCA1I2
	.extern _MCU_vISR_208_Reserved
	.extern _MCU_vISR_209_ICRCAN2ERR
	.extern _MCU_vISR_210_ICRCAN2REC
	.extern _MCU_vISR_211_ICRCAN2TRX
	.extern _MCU_vISR_212_ICRCAN3ERR
	.extern _MCU_vISR_213_ICRCAN3REC
	.extern _MCU_vISR_214_ICRCAN3TRX
	.extern _MCU_vISR_215_ICCSIG1IC
	.extern _MCU_vISR_216_ICCSIG1IR
	.extern _MCU_vISR_217_ICCSIG1IRE
	.extern _MCU_vISR_218_ICRLIN24
	.extern _MCU_vISR_219_ICRLIN25
	.extern _MCU_vISR_220_ICRLIN33
	.extern _MCU_vISR_221_ICRLIN33UR0
	.extern _MCU_vISR_222_ICRLIN33UR1
	.extern _MCU_vISR_223_ICRLIN33UR2
	.extern _MCU_vISR_224_ICRLIN34
	.extern _MCU_vISR_225_ICRLIN34UR0
	.extern _MCU_vISR_226_ICRLIN34UR1
	.extern _MCU_vISR_227_ICRLIN34UR2
	.extern _MCU_vISR_228_ICRLIN35
	.extern _MCU_vISR_229_ICRLIN35UR0
	.extern _MCU_vISR_230_ICRLIN35UR1
	.extern _MCU_vISR_231_ICRLIN35UR2
	.extern _MCU_vISR_232_ICPWGA48
	.extern _MCU_vISR_233_ICPWGA49
	.extern _MCU_vISR_234_ICPWGA50
	.extern _MCU_vISR_235_ICPWGA51
	.extern _MCU_vISR_236_ICPWGA52
	.extern _MCU_vISR_237_ICPWGA53
	.extern _MCU_vISR_238_ICPWGA54
	.extern _MCU_vISR_239_ICPWGA55
	.extern _MCU_vISR_240_ICPWGA56
	.extern _MCU_vISR_241_ICPWGA57
	.extern _MCU_vISR_242_ICPWGA58
	.extern _MCU_vISR_243_ICPWGA59
	.extern _MCU_vISR_244_ICPWGA60
	.extern _MCU_vISR_245_ICPWGA61
	.extern _MCU_vISR_246_ICPWGA62
	.extern _MCU_vISR_247_ICPWGA63
	.extern _MCU_vISR_248_ICTAUB1I0
	.extern _MCU_vISR_249_ICTAUB1I1
	.extern _MCU_vISR_250_ICTAUB1I2
	.extern _MCU_vISR_251_ICTAUB1I3
	.extern _MCU_vISR_252_ICTAUB1I4
	.extern _MCU_vISR_253_ICTAUB1I5
	.extern _MCU_vISR_254_ICTAUB1I6
	.extern _MCU_vISR_255_ICTAUB1I7
	.extern _MCU_vISR_256_ICTAUB1I8
	.extern _MCU_vISR_257_ICTAUB1I9
	.extern _MCU_vISR_258_ICTAUB1I10
	.extern _MCU_vISR_259_ICTAUB1I11
	.extern _MCU_vISR_260_ICTAUB1I12
	.extern _MCU_vISR_261_ICTAUB1I13
	.extern _MCU_vISR_262_ICTAUB1I14
	.extern _MCU_vISR_263_ICTAUB1I15
	.extern _MCU_vISR_264_ICRCAN4ERR
	.extern _MCU_vISR_265_ICRCAN4REC
	.extern _MCU_vISR_266_ICRCAN4TRX
	.extern _MCU_vISR_267_ICRLIN26
	.extern _MCU_vISR_268_ICRLIN27
	.extern _MCU_vISR_269_ICPWGA64
	.extern _MCU_vISR_270_ICPWGA65
	.extern _MCU_vISR_271_ICPWGA66
	.extern _MCU_vISR_272_ICPWGA67
	.extern _MCU_vISR_273_ICPWGA68
	.extern _MCU_vISR_274_ICPWGA69
	.extern _MCU_vISR_275_ICPWGA70
	.extern _MCU_vISR_276_ICPWGA71
	.extern _MCU_vISR_277_ICRLIN28
	.extern _MCU_vISR_278_ICRLIN29
	.extern _MCU_vISR_279_ICRCAN5ERR
	.extern _MCU_vISR_280_ICRCAN5REC
	.extern _MCU_vISR_281_ICRCAN5TRX
	.extern _MCU_vISR_282_Reserved
	.extern _MCU_vISR_283_Reserved
	.extern _MCU_vISR_284_Reserved
	.extern _MCU_vISR_285_Reserved
	.extern _MCU_vISR_286_Reserved
	.extern _MCU_vISR_287_Reserved
	
/*#########################################################

		-- this is normal interrupt vector table list --
		
#########################################################*/	

	.word _MCU_vISR_0_ICTAUD0I0_ICCSIH2IC_1
	.word _MCU_vISR_1_ICTAUD0I2_ICCSIH3IC_1
	.word _MCU_vISR_2_ICTAUD0I4
	.word _MCU_vISR_3_ICTAUD0I6
	.word _MCU_vISR_4_ICTAUD0I8
	.word _MCU_vISR_5_ICTAUD0I10_ICCSIH3IR_1
	.word _MCU_vISR_6_ICTAUD0I12_ICCSIH3IRE_1
	.word _MCU_vISR_7_ICTAUD0I14_ICCSIH3IJC_1
	.word _MCU_vISR_8_ICTAPA0IPEK0_ICCSIH1IC_1
	.word _MCU_vISR_9_ICTAPA0IVLY0_ICCSIH1IR_1
	.word _MCU_vISR_10_ICADCA0I0
	.word _MCU_vISR_11_ICADCA0I1
	.word _MCU_vISR_12_ICADCA0I2
	.word _MCU_vISR_13_ICDCUTDI
	.word _MCU_vISR_14_ICRCANGERR
	.word _MCU_vISR_15_ICRCANGRECC
	.word _MCU_vISR_16_ICRCAN0ERR
	.word _MCU_vISR_17_ICRCAN0REC
	.word _MCU_vISR_18_ICRCAN0TRX
	.word _MCU_vISR_19_ICCSIG0IC_ICCSIH1IRE_1
	.word _MCU_vISR_20_ICCSIG0IR_ICCSIH1IJC_1
	.word _MCU_vISR_21_ICCSIH0IC
	.word _MCU_vISR_22_ICCSIH0IR
	.word _MCU_vISR_23_ICCSIH0IRE
	.word _MCU_vISR_24_ICCSIH0IJC
	.word _MCU_vISR_25_ICRLIN30
	.word _MCU_vISR_26_ICRLIN30UR0
	.word _MCU_vISR_27_ICRLIN30UR1
	.word _MCU_vISR_28_ICRLIN30UR2
	.word _MCU_vISR_29_ICP0_ICCSIH2IR_1
	.word _MCU_vISR_30_ICP1_ICCSIH2IRE_1
	.word _MCU_vISR_31_ICP2_ICCSIH2IJC_1
	.word _MCU_vISR_32_ICWDTA0
	.word _MCU_vISR_33_ICWDTA1
	.word _MCU_vISR_34_ICP3
	.word _MCU_vISR_35_ICP4
	.word _MCU_vISR_36_ICP5
	.word _MCU_vISR_37_ICP10
	.word _MCU_vISR_38_ICP11
	.word _MCU_vISR_39_ICTAUD0I1
	.word _MCU_vISR_40_ICTAUD0I3
	.word _MCU_vISR_41_ICTAUD0I5
	.word _MCU_vISR_42_ICTAUD0I7
	.word _MCU_vISR_43_ICTAUD0I9
	.word _MCU_vISR_44_ICTAUD0I11
	.word _MCU_vISR_45_ICTAUD0I13
	.word _MCU_vISR_46_ICTAUD0I15
	.word _MCU_vISR_47_ICADCA0ERR
	.word _MCU_vISR_48_Reserved
	.word _MCU_vISR_49_ICCSIG0IRE
	.word _MCU_vISR_50_ICRLIN20
	.word _MCU_vISR_51_ICRLIN21
	.word _MCU_vISR_52_ICDMA0
	.word _MCU_vISR_53_ICDMA1
	.word _MCU_vISR_54_ICDMA2
	.word _MCU_vISR_55_ICDMA3
	.word _MCU_vISR_56_ICDMA4
	.word _MCU_vISR_57_ICDMA5
	.word _MCU_vISR_58_ICDMA6
	.word _MCU_vISR_59_ICDMA7
	.word _MCU_vISR_60_ICDMA8
	.word _MCU_vISR_61_ICDMA9
	.word _MCU_vISR_62_ICDMA10
	.word _MCU_vISR_63_ICDMA11
	.word _MCU_vISR_64_ICDMA12
	.word _MCU_vISR_65_ICDMA13
	.word _MCU_vISR_66_ICDMA14
	.word _MCU_vISR_67_ICDMA15
	.word _MCU_vISR_68_ICRIIC0TI
	.word _MCU_vISR_69_ICRIIC0TEI
	.word _MCU_vISR_70_ICRIIC0RI
	.word _MCU_vISR_71_ICRIIC0EE
	.word _MCU_vISR_72_ICTAUJ0I0
	.word _MCU_vISR_73_ICTAUJ0I1
	.word _MCU_vISR_74_ICTAUJ0I2
	.word _MCU_vISR_75_ICTAUJ0I3
	.word _MCU_vISR_76_ICOSTM0
	.word _MCU_vISR_77_ICENCA0IOV_ICPWGA4
	.word _MCU_vISR_78_ICENCA0IUD_ICPWGA5
	.word _MCU_vISR_79_ICENCA0I0_ICPWGA6
	.word _MCU_vISR_80_ICENCA0I1_ICPWGA7
	.word _MCU_vISR_81_ICENCA0IEC
	.word _MCU_vISR_82_ICKR0
	.word _MCU_vISR_83_ICQFULL
	.word _MCU_vISR_84_ICPWGA0
	.word _MCU_vISR_85_ICPWGA1
	.word _MCU_vISR_86_ICPWGA2
	.word _MCU_vISR_87_ICPWGA3
	.word _MCU_vISR_88_ICPWGA8
	.word _MCU_vISR_89_ICPWGA9
	.word _MCU_vISR_90_ICPWGA10
	.word _MCU_vISR_91_ICPWGA11
	.word _MCU_vISR_92_ICPWGA12
	.word _MCU_vISR_93_ICPWGA13
	.word _MCU_vISR_94_ICPWGA14
	.word _MCU_vISR_95_ICPWGA15
	.word _MCU_vISR_96_Reserved
	.word _MCU_vISR_97_Reserved
	.word _MCU_vISR_98_Reserved
	.word _MCU_vISR_99_Reserved
	.word _MCU_vISR_100_Reserved
	.word _MCU_vISR_101_Reserved
	.word _MCU_vISR_102_ICFLERR
	.word _MCU_vISR_103_ICFLENDNM
	.word _MCU_vISR_104_ICCWEND
	.word _MCU_vISR_105_ICRCAN1ERR
	.word _MCU_vISR_106_ICRCAN1REC
	.word _MCU_vISR_107_ICRCAN1TRX
	.word _MCU_vISR_108_ICCSIH1IC_ICTAPA0IPEK0_2
	.word _MCU_vISR_109_ICCSIH1IR_ICTAPA0IVLY0_2
	.word _MCU_vISR_110_ICCSIH1IRE_ICCSIG0IC_2
	.word _MCU_vISR_111_ICCSIH1IJC_ICCSIG0IR_2
	.word _MCU_vISR_112_ICRLIN31
	.word _MCU_vISR_113_ICRLIN31UR0
	.word _MCU_vISR_114_ICRLIN31UR1
	.word _MCU_vISR_115_ICRLIN31UR2
	.word _MCU_vISR_116_ICPWGA20
	.word _MCU_vISR_117_ICPWGA21
	.word _MCU_vISR_118_ICPWGA22
	.word _MCU_vISR_119_ICPWGA23
	.word _MCU_vISR_120_ICP6
	.word _MCU_vISR_121_ICP7
	.word _MCU_vISR_122_ICP8
	.word _MCU_vISR_123_ICP12
	.word _MCU_vISR_124_ICCSIH2IC_ICTAUD0I0_2
	.word _MCU_vISR_125_ICCSIH2IR_ICP0_2
	.word _MCU_vISR_126_ICCSIH2IRE_ICP1_2
	.word _MCU_vISR_127_ICCSIH2IJC_ICP2_2
	.word _MCU_vISR_128_Reserved
	.word _MCU_vISR_129_Reserved
	.word _MCU_vISR_130_Reserved
	.word _MCU_vISR_131_Reserved
	.word _MCU_vISR_132_Reserved
	.word _MCU_vISR_133_Reserved
	.word _MCU_vISR_134_ICTAUB0I0
	.word _MCU_vISR_135_ICTAUB0I1
	.word _MCU_vISR_136_ICTAUB0I2
	.word _MCU_vISR_137_ICTAUB0I3_ICPWGA16
	.word _MCU_vISR_138_ICTAUB0I4
	.word _MCU_vISR_139_ICTAUB0I5_ICPWGA17
	.word _MCU_vISR_140_ICTAUB0I6
	.word _MCU_vISR_141_ICTAUB0I7_ICPWGA18
	.word _MCU_vISR_142_ICTAUB0I8
	.word _MCU_vISR_143_ICTAUB0I9_ICPWGA19
	.word _MCU_vISR_144_ICTAUB0I10
	.word _MCU_vISR_145_ICTAUB0I11_ICPWGA26
	.word _MCU_vISR_146_ICTAUB0I12
	.word _MCU_vISR_147_ICTAUB0I13_ICPWGA30
	.word _MCU_vISR_148_ICTAUB0I14
	.word _MCU_vISR_149_ICTAUB0I15_ICPWGA31
	.word _MCU_vISR_150_ICCSIH3IC_ICTAUD0I2_2
	.word _MCU_vISR_151_ICCSIH3IR_ICTAUD0I10_2
	.word _MCU_vISR_152_ICCSIH3IRE_ICTAUD0I12_2
	.word _MCU_vISR_153_ICCSIH3IJC_ICTAUD0I14_2
	.word _MCU_vISR_154_ICRLIN22
	.word _MCU_vISR_155_ICRLIN23
	.word _MCU_vISR_156_ICRLIN32
	.word _MCU_vISR_157_ICRLIN32UR0
	.word _MCU_vISR_158_ICRLIN32UR1
	.word _MCU_vISR_159_ICRLIN32UR2
	.word _MCU_vISR_160_ICTAUJ1I0
	.word _MCU_vISR_161_ICTAUJ1I1
	.word _MCU_vISR_162_ICTAUJ1I2
	.word _MCU_vISR_163_ICTAUJ1I3
	.word _MCU_vISR_164_Reserved
	.word _MCU_vISR_165_Reserved
	.word _MCU_vISR_166_Reserved
	.word _MCU_vISR_167_Reserved
	.word _MCU_vISR_168_Reserved
	.word _MCU_vISR_169_Reserved
	.word _MCU_vISR_170_Reserved
	.word _MCU_vISR_171_Reserved
	.word _MCU_vISR_172_Reserved
	.word _MCU_vISR_173_Reserved
	.word _MCU_vISR_174_Reserved
	.word _MCU_vISR_175_Reserved
	.word _MCU_vISR_176_ICPWGA24
	.word _MCU_vISR_177_ICPWGA25
	.word _MCU_vISR_178_ICPWGA27
	.word _MCU_vISR_179_ICPWGA28
	.word _MCU_vISR_180_ICPWGA29
	.word _MCU_vISR_181_ICPWGA32
	.word _MCU_vISR_182_ICPWGA33
	.word _MCU_vISR_183_ICPWGA34
	.word _MCU_vISR_184_ICPWGA35
	.word _MCU_vISR_185_ICPWGA36
	.word _MCU_vISR_186_ICPWGA37
	.word _MCU_vISR_187_ICPWGA38
	.word _MCU_vISR_188_ICPWGA39
	.word _MCU_vISR_189_ICPWGA40
	.word _MCU_vISR_190_ICPWGA41
	.word _MCU_vISR_191_ICPWGA42
	.word _MCU_vISR_192_ICPWGA43
	.word _MCU_vISR_193_ICPWGA44
	.word _MCU_vISR_194_ICPWGA45
	.word _MCU_vISR_195_ICPWGA46
	.word _MCU_vISR_196_ICPWGA47
	.word _MCU_vISR_197_ICP9
	.word _MCU_vISR_198_ICP13
	.word _MCU_vISR_199_ICP14
	.word _MCU_vISR_200_ICP15
	.word _MCU_vISR_201_ICRTCA01S
	.word _MCU_vISR_202_ICRTCA0AL
	.word _MCU_vISR_203_ICRTCA0R
	.word _MCU_vISR_204_ICADCA1ERR
	.word _MCU_vISR_205_ICADCA1I0
	.word _MCU_vISR_206_ICADCA1I1
	.word _MCU_vISR_207_ICADCA1I2
	.word _MCU_vISR_208_Reserved
	.word _MCU_vISR_209_ICRCAN2ERR
	.word _MCU_vISR_210_ICRCAN2REC
	.word _MCU_vISR_211_ICRCAN2TRX
	.word _MCU_vISR_212_ICRCAN3ERR
	.word _MCU_vISR_213_ICRCAN3REC
	.word _MCU_vISR_214_ICRCAN3TRX
	.word _MCU_vISR_215_ICCSIG1IC
	.word _MCU_vISR_216_ICCSIG1IR
	.word _MCU_vISR_217_ICCSIG1IRE
	.word _MCU_vISR_218_ICRLIN24
	.word _MCU_vISR_219_ICRLIN25
	.word _MCU_vISR_220_ICRLIN33
	.word _MCU_vISR_221_ICRLIN33UR0
	.word _MCU_vISR_222_ICRLIN33UR1
	.word _MCU_vISR_223_ICRLIN33UR2
	.word _MCU_vISR_224_ICRLIN34
	.word _MCU_vISR_225_ICRLIN34UR0
	.word _MCU_vISR_226_ICRLIN34UR1
	.word _MCU_vISR_227_ICRLIN34UR2
	.word _MCU_vISR_228_ICRLIN35
	.word _MCU_vISR_229_ICRLIN35UR0
	.word _MCU_vISR_230_ICRLIN35UR1
	.word _MCU_vISR_231_ICRLIN35UR2
	.word _MCU_vISR_232_ICPWGA48
	.word _MCU_vISR_233_ICPWGA49
	.word _MCU_vISR_234_ICPWGA50
	.word _MCU_vISR_235_ICPWGA51
	.word _MCU_vISR_236_ICPWGA52
	.word _MCU_vISR_237_ICPWGA53
	.word _MCU_vISR_238_ICPWGA54
	.word _MCU_vISR_239_ICPWGA55
	.word _MCU_vISR_240_ICPWGA56
	.word _MCU_vISR_241_ICPWGA57
	.word _MCU_vISR_242_ICPWGA58
	.word _MCU_vISR_243_ICPWGA59
	.word _MCU_vISR_244_ICPWGA60
	.word _MCU_vISR_245_ICPWGA61
	.word _MCU_vISR_246_ICPWGA62
	.word _MCU_vISR_247_ICPWGA63
	.word _MCU_vISR_248_ICTAUB1I0
	.word _MCU_vISR_249_ICTAUB1I1
	.word _MCU_vISR_250_ICTAUB1I2
	.word _MCU_vISR_251_ICTAUB1I3
	.word _MCU_vISR_252_ICTAUB1I4
	.word _MCU_vISR_253_ICTAUB1I5
	.word _MCU_vISR_254_ICTAUB1I6
	.word _MCU_vISR_255_ICTAUB1I7
	.word _MCU_vISR_256_ICTAUB1I8
	.word _MCU_vISR_257_ICTAUB1I9
	.word _MCU_vISR_258_ICTAUB1I10
	.word _MCU_vISR_259_ICTAUB1I11
	.word _MCU_vISR_260_ICTAUB1I12
	.word _MCU_vISR_261_ICTAUB1I13
	.word _MCU_vISR_262_ICTAUB1I14
	.word _MCU_vISR_263_ICTAUB1I15
	.word _MCU_vISR_264_ICRCAN4ERR
	.word _MCU_vISR_265_ICRCAN4REC
	.word _MCU_vISR_266_ICRCAN4TRX
	.word _MCU_vISR_267_ICRLIN26
	.word _MCU_vISR_268_ICRLIN27
	.word _MCU_vISR_269_ICPWGA64
	.word _MCU_vISR_270_ICPWGA65
	.word _MCU_vISR_271_ICPWGA66
	.word _MCU_vISR_272_ICPWGA67
	.word _MCU_vISR_273_ICPWGA68
	.word _MCU_vISR_274_ICPWGA69
	.word _MCU_vISR_275_ICPWGA70
	.word _MCU_vISR_276_ICPWGA71
	.word _MCU_vISR_277_ICRLIN28
	.word _MCU_vISR_278_ICRLIN29
	.word _MCU_vISR_279_ICRCAN5ERR
	.word _MCU_vISR_280_ICRCAN5REC
	.word _MCU_vISR_281_ICRCAN5TRX
	.word _MCU_vISR_282_Reserved
	.word _MCU_vISR_283_Reserved
	.word _MCU_vISR_284_Reserved
	.word _MCU_vISR_285_Reserved
	.word _MCU_vISR_286_Reserved
	.word _MCU_vISR_287_Reserved
	
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
------YES, we change the locate section from intvect to normal text section-----
  .text
-------------------------------------------------------------------------------

--------------MCUReset function code -----------------------------------------
_MCUReset:

  movhi	hi(___ghsbegin_sdabase),zero,gp  -- Initialization of the global pointer
  movea	lo(___ghsbegin_sdabase),gp,gp

  movhi	hi(___ghsbegin_robase),zero,tp  -- Initialization of the text pointer
  movea	lo(___ghsbegin_robase),tp,tp

  movhi	hi(___ghsend_stack-4),zero,sp -- Initialization of the stack pointer
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

  --------------------------- Clear local RAM data to 0x00000000 at reset_up
  mov ___ghs_ramstart,  r6  -- start of local main RAM
  mov ___ghs_ramend,   r7   -- end of local main RAM
  mov r0, r1

1:
  st.dw   r0, 0[r6]
  addi    8, r6, r6
  cmp r7, r6
  bl 1b


 --------------------------- Clear retention RAM data to 0x00000000 at reset_up
  mov ___ghs_rramstart,   r6  -- start of local Retention RAM
  mov ___ghs_rramend,   r7    -- end of local Retention RAM
  mov r0, r1

2:
  st.dw   r0, 0[r6]
  addi    8, r6, r6
  cmp r7, r6
  bl 2b

 
  jarl	___low_level_init, lp    -- Jump to the HW initialisation function

  jr __start   		-- Jump to the initialisation functions of the library
			-- for data initialize
			--and from there to C function main()

-------end of MCUReset function code -----------------------------------------


#endif   /* __OS_HANDLES__ */  

#pragma endasm
#pragma ghs section text = default

