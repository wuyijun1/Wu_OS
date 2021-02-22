/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1L_D1M_Type.h
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
| 2016.03.01  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifndef _D1X_TYPE_H_
#define _D1X_TYPE_H_

/*******************************************************************************
	Pin ID define List, Max Pin mount in this serial MCU
*******************************************************************************/
#define MCU_mMaskPinID(PinID)			((uint16)((PinID) & 0x1FU))
#define MCU_mMaskPortID(PinID)		((uint16)(((uint16)((PinID)>>8U)) & 0xFFU))
#define MCU_mMaskPortType(PinID)			((uint16)((PinID) & 0x00e0U)>>5)

typedef volatile struct
{
	uint16 u16Value;	/*0x00*/
	uint16 Fill0;		/*0x02*/
}MCU_tstReg_U16;

typedef volatile struct
{
	uint8 u8Value;	/*0x00*/
	uint8 Fill0[3];	/*0x03*/
}MCU_tstReg_U8;

typedef volatile struct
{
	uint32 Commond;/*0x00*/
	uint32 Status;/*0x04*/
}  MCU_tstProtect_Unit;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		system control mapping   
		@@@@@@@@@@		  
####################################################*/

/******************
Standby Control unit
********************/
#define MCU_mStanbyCtrl_BaseAddr	0xFFF80100
#define MCU_mStanbyCtrl_protect_Addr 0xFFF80000

/***********************************************************
clock controller register protrct unit and block register map!!
************************************************************/
#define MCU_mProtect_AWO_Addr	0xFFF80000 /*PROTCMD0*/
#define MCU_mProtect_ISO_Addr		0xFFF88000 /*PROTCMD1*/
#define MCU_mProtect_ISOExt_Addr	0xFFF87000 /*PROTCMDD1*/

/***********************************************************
PLL unit and block register map!!
************************************************************/

#define MUC_mPLL0_BasicAddr	0xFFF89000
#define MUC_mPLL1_BasicAddr	0xFFF89100
#define MUC_mPLL2_BasicAddr	0xFFF850C0
#define MUC_mPLLCtrl_BasicAddr	0xFFF89200

typedef volatile struct
{
	uint32 PLLEnable;/*0x00*/
	uint32 PLLStatus;/*0x04*/
	uint32 PLLCtrl;/*0x08*/

}  MCU_stClkPLL_Unit;

typedef volatile struct
{
	uint32 SSTP;/*0x00*/
	uint32 Fill;/*0x04*/
	uint32 SACT;/*0x08*/
	uint32 Fill2[(0x100-0x0c)/sizeof(uint32)];/*fix to size 0x100*/
}  MCU_stPLLCtrl_Unit;

typedef volatile struct
{
	MCU_stClkPLL_Unit PLL0;
}  MCU_tstPLL_Block;

typedef struct
{
	uint32 MainOsc_Fre;
	uint32 PLL_Fre;
	
	uint32 Pr;
	uint32 Nr;
	uint32 Mr;
	uint32 FVV;
	
}MCU_tstPLLSettingTbl;

/***********************************************************
ISO unit and block register map!!
************************************************************/

#define MUC_mISOBlock_BasicAddr	0xFFF8A000
#define MUC_mAWOBlock_BasicAddr	0xFFF81000

typedef volatile struct
{
	uint32 Divider;/*0x00*/
	uint32 Status;/*0x04*/
	uint32 Active;/*0x08*/
	uint32 Fill1;/*0x0C*/
	uint32 Fill2;/*0x10*/
	uint32 Fill3;/*0x14*/
	uint32 StopMask;/*0x18*/
	uint32 Fill4[(0x100-0x1c)/sizeof(uint32)];/*Fill in unit size to 0x100 byte*/

}  MCU_stCLKDivider_Unit;

typedef volatile struct
{
	uint32 SourceSel;/*0x00*/
	uint32 Fill0;/*0x04*/
	uint32 Active;/*0x08*/
	uint32 Fill1;/*0x0C*/
	uint32 Fill2;/*0x10*/
	uint32 Fill3;/*0x14*/
	uint32 StopMask;/*0x18*/
	uint32 Fill4[(0x100-0x1c)/sizeof(uint32)];/*Fill in unit size to 0x100 byte*/

}  MCU_stCLKSelector_Unit;

typedef volatile struct
{
	uint32 Enable;/*0x00*/
	uint32 Status;/*0x04*/
	uint32 Control;/*0x08*/
	uint32 StableTime;/*0x0c*/
	uint32 Fill0;/*0x10*/
	uint32 Fill1;/*0x14*/
	uint32 StopMask;/*0x18*/
	uint32 Fill2[(0x100-0x1c)/sizeof(uint32)];/*Fill in unit size to 0x100 byte*/

}  MCU_stExternalOsc_Unit;

typedef volatile struct
{
	MCU_stCLKSelector_Unit CKSC_ICPUCLKS;	/*0xFFF8A000*/
	MCU_stCLKDivider_Unit CKSC_ICPUCLKD;	/*0xFFF8A100-->use for CPUCLK divider ctrl and status!!*/

} MCU_tstClkISO_Block;

/***********************************************************
ISO external unit and block register map!!
************************************************************/

#define MUC_mISOExtBlock_BasicAddr	0xFFF85000

typedef volatile struct
{
	uint32 Divider;		/*0x00*/
	uint32 Status;		/*0x04*/
	uint32 Fill[(0x40-0x08)/sizeof(uint32)];/*fix to size in 0x40 bytes*/
	
} MCU_stCLKDivider_ExternalUnit;

typedef volatile struct
{
	uint32 SourceSel;	/*0x00*/
	uint32 Fill0;		/*0x04*/
	uint32 Active;		/*0x08*/
	uint32 Fill1[(0x40-0x0c)/sizeof(uint32)];/*fix to size in 0x40 bytes*/
} MCU_stCLKSelector_ExternalUnit;

typedef volatile struct
{

	MCU_stCLKSelector_ExternalUnit CKSC_IPLLFIXS;	/*0xFFF85000*/
	MCU_stCLKSelector_ExternalUnit Fill1;			/*0xFFF85040*/
	MCU_stCLKSelector_ExternalUnit Fill2;			/*0xFFF85080*/
	MCU_stCLKSelector_ExternalUnit Fill3;			/*0xFFF850C0--->PLL2 control*/
	MCU_stCLKSelector_ExternalUnit Fill4;			/*0xFFF85100*/
	MCU_stCLKSelector_ExternalUnit CKSC_ISDRBS;		/*0xFFF85140*/
	MCU_stCLKSelector_ExternalUnit CKSC_IXCCLKS;		/*0xFFF85180*/
	MCU_stCLKSelector_ExternalUnit CKSC_IXCETNBS;	/*0xFFF851C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_IXCMLBBS;	/*0xFFF85200*/
	MCU_stCLKSelector_ExternalUnit CKSC_IPCRSCANS;	/*0xFFF85240*/
	MCU_stCLKSelector_ExternalUnit CKSC_IPCETNBS;	/*0xFFF85280*/
	MCU_stCLKSelector_ExternalUnit CKSC_IPCMLBBS;	/*0xFFF852C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_IMLBBS;		/*0xFFF85300*/
	MCU_stCLKSelector_ExternalUnit CKSC_ISFMAS;		/*0xFFF85340*/
	MCU_stCLKDivider_ExternalUnit CKSC_ISFMAD;		/*0xFFF85380*/
	MCU_stCLKDivider_ExternalUnit CKDV_ICLKJITD;		/*0xFFF853C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_ICLKJITS;	/*0xFFF85400*/
	MCU_stCLKSelector_ExternalUnit CKSC_IISMS;		/*0xFFF85440*/
	MCU_stCLKDivider_ExternalUnit CKSC_IADCED;		/*0xFFF85480*/
	MCU_stCLKSelector_ExternalUnit CKSC_ILCBIS;		/*0xFFF854C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_IRLINS;		/*0xFFF85500*/
	MCU_stCLKSelector_ExternalUnit CKSC_ITAUB01S;	/*0xFFF85540*/
	MCU_stCLKSelector_ExternalUnit CKSC_ITAUB2S;	/*0xFFF85580*/
	MCU_stCLKSelector_ExternalUnit CKSC_ITAUJS;		/*0xFFF855C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_IOSTMS;		/*0xFFF85600*/
	MCU_stCLKSelector_ExternalUnit Fill5;			/*0xFFF85640*/
	MCU_stCLKSelector_ExternalUnit Fill6;			/*0xFFF85680*/
	MCU_stCLKSelector_ExternalUnit Fill7;			/*0xFFF856C0*/
	MCU_stCLKDivider_ExternalUnit CKDV_ICLKFIXD;		/*0xFFF85700*/
	MCU_stCLKSelector_ExternalUnit CKSC_ICLKFIXS;	/*0xFFF85740*/
	MCU_stCLKDivider_ExternalUnit CKSC_IRSCAND;		/*0xFFF85780*/
	MCU_stCLKDivider_ExternalUnit CKDV_ISSIFD;		/*0xFFF857C0*/
	MCU_stCLKSelector_ExternalUnit CKSC_IRSCANXINS;	/*0xFFF85800*/
	
} MCU_tstClkISO_ExtBlock;


typedef volatile struct
{
	MCU_stExternalOsc_Unit ROSC;	/*0xFFF81000*/
	MCU_stExternalOsc_Unit MOSC; 	/*0xFFF81100*/
	MCU_stExternalOsc_Unit SOSC; 	/*0xFFF81200*/
	uint32 Fill0[(0xFFF82000 -0xFFF81300)/sizeof(uint32) ];
	
	MCU_stCLKDivider_Unit CKSC_AWDTA0D; 	/*0xFFF82000*/
	
	MCU_stCLKSelector_Unit CKSC_AAWOTS;	/*0xFFF82100*/
	MCU_stCLKDivider_Unit CKSC_AAWOTD; 	/*0xFFF82200*/
	
	MCU_stCLKSelector_Unit CKSC_ARTCAS; 	/*0xFFF82300*/
	MCU_stCLKDivider_Unit CKSC_ARTCAD; 	/*0xFFF82400*/
	
	MCU_stCLKSelector_Unit Fill1; 			/*0xFFF82500*/
	MCU_stCLKDivider_Unit Fill2; 			/*0xFFF82600*/

	MCU_stCLKSelector_Unit CKSC_AFOUTS; 	/*0xFFF82700*/
	MCU_stCLKDivider_Unit CKSC_AFOUTD; 	/*0xFFF82800*/
	
}  MCU_tstClkAWO_Block;


/***********************************************************
clock monitor unit and block register map!!
************************************************************/

#define MUC_mCLMABlock_BasicAddr 	0xFFF8C000
#define MUC_mCLMA0_BasicAddr 		0xFFF8F000

typedef volatile struct
{
	MCU_tstReg_U8 Control;		/*0x00*/
	uint32 Fill1;				/*0x04*/
	MCU_tstReg_U16 CompareH;	/*0x08*/
	MCU_tstReg_U16 CompareL;	/*0x0c*/
	MCU_tstProtect_Unit ProtectUnit;/*0x10 -->0x14*/
	uint32 Filed2[(0x80-0x18)/sizeof(uint32)]; /*fix to 0x80 byte size*/
}  MCU_tstClkMonitor_Unit;

typedef volatile struct
{
	MCU_tstClkMonitor_Unit CLMA1_LS;		/*0xFFF8F000*/
	MCU_tstClkMonitor_Unit CLMA2_MainOsc;	/*0xFFF8F080*/
	MCU_tstClkMonitor_Unit CLMA3_PLL0;		/*0xFFF8F100*/
	MCU_tstClkMonitor_Unit CLMA4_PLL1;		/*0xFFF8F180*/
	MCU_tstClkMonitor_Unit CLMA5_Video0In;	/*0xFFF8F200*/
	MCU_tstClkMonitor_Unit CLMA6_Video1In;	/*0xFFF8F280*/
	
}  MCU_tstClkMonitor_Block;



/***********************************************************
 user configuration !!
************************************************************/
typedef const struct
{

/*******************************
	Basic clock module
******************************/
	uint32 MainOsc_StableTime;/*us*/
	uint32 MainOscStopInStandbyMode;
	
	uint32 SubOsc_FTX_Speed;
	uint32 SubOsc_StableTime;/*us*/
/*	uint32 SubOscStopInStandbyMode;*/
	
	uint32 IntOscLS_FRL_Speed;/*240000, can not change*/
	uint32 IntOscHS_FRH_Speed;/*8000000, can not change*/
	
	uint32 PLL0_Speed;		/*clock from PLL 0 --->default we use for CPU clock, not divider*/
	uint32 PLL1_Speed;		/*clock from PLL 1*/
	uint32 PLL2_Speed;		/*clock from PLL 2*/
	
	uint32 MEMCLK_Speed;		/*external memery controller clock from PLL*/

/*******************************
	ISO clock module
******************************/
	uint32 ClkSel_CKSC_ICLKJITS;
							/*
								01B: CKDV_ICLKJITD_CTL selection
								10B: High Speed IntOsc fRH (default)
							*/
							
	uint32 ClkDiv_CKSC_ICLKJITD;
							/*
								0000B: Disabled
								0100B: PLL0CLK /4
								0101B: PLL0CLK /5
								0110B: PLL0CLK /6 (default)
								1000B: PLL0CLK /8
								1010B: PLL0CLK /10
							*/
	uint32 ClkDiv_CKSC_ICLKFIXD;
								/*
									0000B: Disabled
									0110B: PLLFIXCLK /6 (default)
									1000B: PLLFIXCLK /8
									1010B: PLLFIXCLK /10
									1100B: PLLFIXCLK /12
								*/
	uint32 ClkSel_CKSC_ICLKFIXS;
								/*
									01B: CKDV_ICLKFIXD_CTL selection
									10B: High Speed IntOsc fRH (default)
								*/
	uint32 ClkSel_CKSC_IPLLFIXS;
								/*
									01B: PLL1CLK (default)
									10B: PLL2CLK (D1M2(H) only)
								*/
	uint32 ClkSel_CKSC_ISDRBS;
								/*
									0: Stop SDRBCLK clock (default)
									1: Activate SDRBCLK clock
								*/
	uint32 ClkSel_CKSC_ICPUCLKS;
								/*
									001B: EMCLK (default)
									011B: PLL0CLK --->we use this value for CPU clock
									100B: PLL1CLK
								*/
	uint32 ClkDiv_CKSC_ICPUCLKD;
								/*
									001B: CKSC_ICPUCLKS_CTL selection /1 (default)
									010B: CKSC_ICPUCLKS_CTL selection /2
									011B: CKSC_ICPUCLKS_CTL selection /4
									100B: CKSC_ICPUCLKS_CTL selection /8
									101B: CKSC_ICPUCLKS_CTL selection /3
								*/
	uint32 ClkSel_CKSC_IXCCLKS;
								/*
									0: Stop C_ISO_XCCLK (default)
									1: Activate C_ISO_XCCLK
								*/
	uint32 ClkSel_CKSC_IPCETNBS;
								/*
									0: Stop ETNBPCLK clock (default)
									1: Activate ETNBPCLK clock
								*/
	uint32 ClkSel_CKSC_IXCETNBS;
								/*
									0: Stop ETNBXCCLK clock (default)
									1: Activate ETNBXCCLK clock
								*/
	uint32 ClkSel_CKSC_IPCMLBBS;
								/*
									0: Stop MLBBPCLK clock (default)
									1: Activate MLBBPCLK clock
								*/
	uint32 ClkSel_CKSC_IXCMLBBS;
								/*
									0: Stop MLBBXCCLK clock (default)
									1: Activate MLBBXCCLK
								*/
	uint32 ClkSel_CKSC_IPCRSCANS;
								/*
									0: Stop RSCANPCLK clock
									1: Activate RSCANPCLK clock (default)
								*/
	uint32 ClkSel_APB_CLK_RATIO;
								/*
									0: C_ISO_PCLK = C_ISO_CPUCLK / 2
									1: C_ISO_PCLK = C_ISO_CPUCLK / 4 (default)
								*/

/*******************************
	AWO clock module
******************************/

	uint32 ClkSel_CKSC_AAWOTS;
							/*
								000B: Disabled
								001B: High Speed IntOsc fRH (default)
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
							*/
	uint32 ClkDiv_CKSC_AAWOTD;
							/*
								001B: CKSC_AAWOTS_CTL selection /1 (default)
								010B: CKSC_AAWOTS_CTL selection /2
								011B: CKSC_AAWOTS_CTL selection /4
								100B: CKSC_AAWOTS_CTL selection /8
								101B: CKSC_AAWOTS_CTL selection /16
							*/
	uint32 AAWOTStopInStandbyMode;
	
	uint32 ClkDiv_CKSC_AWDTA0D;
							/*
								001B: Low Speed IntOsc fRL / 128 (default)
								010B: Low Speed IntOsc fRL / 1
								011B: Low Speed IntOsc fRL / 256
								100B: Low Speed IntOsc fRL / 512
								101B: Low Speed IntOsc fRL / 1024
								110B: Low Speed IntOsc fRL / 2048
							*/
	uint32 ClkSel_CKSC_ARTCAS;
							/*
								000B: Disable (default)
								001B: SubOsc fTX
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
								100B: High Speed IntOsc fRH
							*/
	uint32 ClkDiv_CKSC_ARTCAD;
							/*
								000B: Disabled (default)
								001B: CKSC_ARTCAS_CTL selection /1
								010B: CKSC_ARTCAS_CTL selection /2
								011B: CKSC_ARTCAS_CTL selection /4
								100B: CKSC_ARTCAS_CTL selection /8
								101B: CKSC_ARTCAS_CTL selection /16
							*/
	uint32 ARTCAStopInStandbyMode;
	
	uint32 ClkSel_CKSC_AFOUTS;
							/*
								000B: Disabled (default)
								001B: MainOsc fX
								010B: High Speed IntOsc fRH
								011B: Low Speed IntOsc fRL
								100B: SubOsc fTX
								101B: PLL0CLK/4
								110B: PLL1CLK/4
								111B: PLL2CLK/4 (D1M2(H) only)
							*/
	uint32 ClkDiv_CKSC_AFOUTD;
							/*
								source = CKSC_AFOUTS
								range: 0= disable, 1 <= range <=512
							*/
		
	uint32 AFOUTStopInStandbyMode;
	
/*******************************
	external clock module
******************************/
	uint32 ClkSel_CKSC_IMLBBS;
							/*
								00B: Disabled (default)
								01B: PLL0CLK /2
								10B: PLL0CLK /4
							*/
	uint32 ClkSel_CKSC_ISFMAS;
							/*
								01B: PLL0CLK
								10B: PLL1CLK (default)
							*/
	uint32 ClkDiv_CKSC_ISFMAD;
							/*
								D1L2(H), D1M1(H), D1M2(H)
									Clock divider setting for C_ISO_SFMA
									000B: Disabled (default)
									001B: CKSC_ISFMAS_CTL selection /2
									010B: CKSC_ISFMAS_CTL selection /3
									011B: CKSC_ISFMAS_CTL selection /4
									100B: CKSC_ISFMAS_CTL selection /6
									All others: Setting prohibited
								D1L1
									Clock divider setting for C_ISO_SFMA
									000B: Disabled (default)
									100B: CKSC_ISFMAS_CTL selection /6
									All others: Setting prohibited

							*/
	uint32 ClkDiv_CKSC_IRSCAND;
							/*
								000B: Disabled
								001B: PLLFIXCLK /30
								010B: PLLFIXCLK /40
								011B: PLLFIXCLK /60
								100B: PLLFIXCLK /12 (default)
								101B: PLLFIXCLK /24
							*/
	uint32 ClkSel_CKSC_IRSCANXINS;
							/*
								0: Disabled
								1: MainOsc fX (default).
							*/
	uint32 ClkDiv_CKDV_ISSIFD;
						/*
							source = PLLFIXCLK
							range: 0= disable, 1 <= range <=512
						*/
	
	uint32 ClkSel_CKSC_ITAUB01S;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
							*/
	uint32 ClkSel_CKSC_ITAUB2S;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
							*/
	uint32 ClkSel_CKSC_ITAUJS;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
								110B: C_ISO_CPUCLK /4
							*/
	uint32 ClkSel_CKSC_IOSTMS;
							/*
								00B: Disabled
								01B: CLKJIT
								10B: C_ISO_CPUCLK /4 (default)
								11B: MainOsc fX
							*/
	uint32 ClkSel_CKSC_ILCBIS;
						/*
							0: Disabled (default)
							1: CLKJIT
						*/
	uint32 ClkDiv_CKSC_IADCED;
						/*
							01B: CLKJIT /2 (default)
							10B: CLKJIT /4
						*/
	uint32 ClkSel_CKSC_IISMS;
						/*
							0: Disabled (default)
							1: CLKJIT
						*/
	uint32 ClkSel_CKSC_IRLINS;
						/*
						 D1M1(H):
							01B: PLLFIXCLK /10
							10B: CLKJIT /1
							11B: PLLFIXCLK /20 (default)
						 All other devices:
							01B: PLLFIXCLK /10
							10B: CLKJIT /1 (default)
						*/
	uint32 Video0_InClkFre;					
	uint32 Video1_InClkFre;		
	
	uint32 CLMA0enable_HS;		/*CLMA0 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA0TolerancePercent;
	
	uint32 CLMA1enable_LS;			/*CLMA1 monitor unit,sample clock = HS/256 = 31.25kHz*/
	uint32 CLMA1TolerancePercent;
	
	uint32 CLMA2enable_MainOsc;	/*CLMA2 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA2TolerancePercent;

	uint32 CLMA3enable_PLL0;		/*CLMA3 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA3TolerancePercent;

	uint32 CLMA4enable_PLL1;		/*CLMA4 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA4TolerancePercent;
	
	uint32 CLMA5enable_Vidoe0;		/*CLMA5 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA5TolerancePercent;

	uint32 CLMA6enable_Vidoe1;		/*CLMA6 monitor unit,sample clock = LS = 240kHz*/
	uint32 CLMA6TolerancePercent;
	
}MCU_tstClockUsrCfg;


/***********************************************************
	running status!!
************************************************************/
typedef  struct
{

/*******************************
	Basic clock module
******************************/
	uint32 MainOsc_Speed;		/*MainOsc*/
	uint32 SubOsc_Speed;		/*external Sub Osc*/
	
	uint32 IntOscLS_FRL_Speed;/*240000, can not change*/
	uint32 IntOscHS_FRH_Speed;/*8000000, can not change*/
	
	uint32 PLL0_Speed;		/*clock from PLL 0 */
	uint32 PLL1_Speed;		/*clock from PLL 1--->default we use for CPU clock, not divider*/
	uint32 PLL2_Speed;		/*clock from PLL 2*/
	uint32 CPUCLK_Speed;		/*CPU clock from PLL*/
	uint32 EMCLK_Speed;		/*emergency clock EMCLK*/
	
	uint32 MEMCLK_Speed;		/*external memery controller clock from PLL*/


/*******************************
	ISO clock module
******************************/
	uint32 ClkSpeed_CKSC_ICLKJITS;
							/*
								01B: CKDV_ICLKJITD_CTL selection
								10B: High Speed IntOsc fRH (default)
							*/
							
	uint32 ClkSpeed_CKSC_ICLKFIXS;
								/*
									01B: CKDV_ICLKFIXD_CTL selection
									10B: High Speed IntOsc fRH (default)
								*/
	uint32 ClkSpeed_CKSC_IPLLFIXS;
								/*
									01B: PLL1CLK (default)
									10B: PLL2CLK (D1M2(H) only)
								*/
	uint32 ClkSpeed_CKSC_ISDRBS;
								/*
									0: Stop SDRBCLK clock (default)
									1: Activate SDRBCLK clock
								*/
	uint32 ClkSpeed_CKSC_PCLK;
								/*
									001B: EMCLK (default)
									011B: PLL0CLK --->we use this value for CPU clock
									100B: PLL1CLK
								*/
	uint32 ClkSpeed_CKSC_IXCCLKS;
								/*
									0: Stop C_ISO_XCCLK (default)
									1: Activate C_ISO_XCCLK
								*/
	uint32 ClkSpeed_CKSC_IPCETNBS;
								/*
									0: Stop ETNBPCLK clock (default)
									1: Activate ETNBPCLK clock
								*/
	uint32 ClkSpeed_CKSC_IXCETNBS;
								/*
									0: Stop ETNBXCCLK clock (default)
									1: Activate ETNBXCCLK clock
								*/
	uint32 ClkSpeed_CKSC_IPCMLBBS;
								/*
									0: Stop MLBBPCLK clock (default)
									1: Activate MLBBPCLK clock
								*/
	uint32 ClkSpeed_CKSC_IXCMLBBS;
								/*
									0: Stop MLBBXCCLK clock (default)
									1: Activate MLBBXCCLK
								*/
	uint32 ClkSpeed_CKSC_IPCRSCANS;
								/*
									0: Stop RSCANPCLK clock
									1: Activate RSCANPCLK clock (default)
								*/

	uint32 ClkSpeed_APB_CLK_RATIO;
								/*
									0: C_ISO_PCLK = C_ISO_CPUCLK / 2
									1: C_ISO_PCLK = C_ISO_CPUCLK / 4 (default)
								*/
/*******************************
	AWO clock module
******************************/

	uint32 ClkSpeed_CKSC_AAWOTS;
							/*
								000B: Disabled
								001B: High Speed IntOsc fRH (default)
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
							*/
	
	uint32 ClkSpeed_CKSC_AWDTA0D;
							/*
								001B: Low Speed IntOsc fRL / 128 (default)
								010B: Low Speed IntOsc fRL / 1
								011B: Low Speed IntOsc fRL / 256
								100B: Low Speed IntOsc fRL / 512
								101B: Low Speed IntOsc fRL / 1024
								110B: Low Speed IntOsc fRL / 2048
							*/
	uint32 ClkSpeed_CKSC_ARTCAS;
							/*
								000B: Disable (default)
								001B: SubOsc fTX
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
								100B: High Speed IntOsc fRH
							*/
	uint32 ClkSpeed_CKSC_ARTCAD;
							/*
								000B: Disabled (default)
								001B: CKSC_ARTCAS_CTL selection /1
								010B: CKSC_ARTCAS_CTL selection /2
								011B: CKSC_ARTCAS_CTL selection /4
								100B: CKSC_ARTCAS_CTL selection /8
								101B: CKSC_ARTCAS_CTL selection /16
							*/

	
	uint32 ClkSpeed_CKSC_AFOUTS;
							/*
								000B: Disabled (default)
								001B: MainOsc fX
								010B: High Speed IntOsc fRH
								011B: Low Speed IntOsc fRL
								100B: SubOsc fTX
								101B: PLL0CLK/4
								110B: PLL1CLK/4
								111B: PLL2CLK/4 (D1M2(H) only)
							*/

	
/*******************************
	external clock module
******************************/
	uint32 ClkSpeed_CKSC_IMLBBS;
							/*
								00B: Disabled (default)
								01B: PLL0CLK /2
								10B: PLL0CLK /4
							*/
	uint32 ClkSpeed_CKSC_ISFMAS;
							/*
								01B: PLL0CLK
								10B: PLL1CLK (default)
							*/

	uint32 ClkSpeed_CKSC_IRSCAND;
							/*
								000B: Disabled
								001B: PLLFIXCLK /30
								010B: PLLFIXCLK /40
								011B: PLLFIXCLK /60
								100B: PLLFIXCLK /12 (default)
								101B: PLLFIXCLK /24
							*/
	uint32 ClkSpeed_CKSC_IRSCANXINS;
							/*
								0: Disabled
								1: MainOsc fX (default).
							*/
	uint32 ClkSpeed_CKDV_ISSIFD;
						/*
							source = PLLFIXCLK
							range: 0= disable, 1 <= range <=512
						*/
	
	uint32 ClkSpeed_CKSC_ITAUB01S;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
							*/
	uint32 ClkSpeed_CKSC_ITAUB2S;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
							*/
	uint32 ClkSpeed_CKSC_ITAUJS;
							/*
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
								110B: C_ISO_CPUCLK /4
							*/
	uint32 ClkSpeed_CKSC_IOSTMS;
							/*
								00B: Disabled
								01B: CLKJIT
								10B: C_ISO_CPUCLK /4 (default)
								11B: MainOsc fX
							*/
	uint32 ClkSpeed_CKSC_ILCBIS;
						/*
							0: Disabled (default)
							1: CLKJIT
						*/
	uint32 ClkSpeed_CKSC_IADCED;
						/*
							01B: CLKJIT /2 (default)
							10B: CLKJIT /4
						*/
	uint32 ClkSpeed_CKSC_IISMS;
						/*
							0: Disabled (default)
							1: CLKJIT
						*/
	uint32 ClkSpeed_CKSC_IRLINS;
						/*
						 D1M1(H):
							01B: PLLFIXCLK /10
							10B: CLKJIT /1
							11B: PLLFIXCLK /20 (default)
						 All other devices:
							01B: PLLFIXCLK /10
							10B: CLKJIT /1 (default)
						*/
	uint32 ClkSpeed_Video0_InClkFre;					
	uint32 ClkSpeed_Video1_InClkFre;		
		
}MCU_tstClockRunStatus;


/*****************************************
	clock module Attribute struct 
****************************************/
typedef const struct
{
	MCU_tstClkAWO_Block * AWOBlock_BasicAddr; 	/*MCU_tstClkAWO_Block*/
	MCU_tstClkISO_Block * ISOBlock_BasicAddr;	/*MCU_tstClkISO_Block*/
	MCU_tstClkISO_ExtBlock * ISOExtBlock_BasicAddr;	/*MCU_tstClkISO_ExtBlock*/
	MCU_stPLLCtrl_Unit *PLLCtrl;					/*MCU_stPLLCtrl_Unit*/
	
	MCU_stClkPLL_Unit * PLL0;					/*MCU_stClkPLL_Unit*/
	MCU_stClkPLL_Unit * PLL1;					/*MCU_stClkPLL_Unit*/
	MCU_stClkPLL_Unit * PLL2;					/*MCU_stClkPLL_Unit*/
	
	MCU_tstProtect_Unit * Protect_AWO_Addr;	/*MCU_tstProtect_Unit*/
	MCU_tstProtect_Unit * Protect_ISO_Addr;	/*MCU_tstProtect_Unit*/
	MCU_tstProtect_Unit * Protect_ISOExt_Addr;	/*MCU_tstProtect_Unit*/
	
	MCU_tstClkMonitor_Unit * ClockMonitor_CLMA0;	/*MCU_tstClkMonitor_Unit*/
	
	MCU_tstClkMonitor_Block * ClockMonitorBlock;	/*MCU_tstClkMonitor_Block*/
	MCU_tstClockUsrCfg * ClockUsrCfgHead; /*MCU_tstClockUsrCfg*/
	
}MCU_stsClockModlueAttribute;


///////////////////////////////////////////////////////////////////////////
/********
reset control unit
**********/

#define MCU_mResetReason_Addr			0xFFF80760

#define MCU_mSoftWareReset_Addr			0xFFF80A04
#define MCU_mSoftWareReset_ProtectAddr		0xFFF80000

#define MCU_mModuleReset_Addr				0xFFF8F400
#define MCU_mModuleReset_ProtectAddr		0xFFF8F480

//////////////////////////////////////////////////////////////////

#define MCU_mResetCtrl_BaseAddr			0xFFF80760
#define MCU_mMcuResetProtect_BaseAddr			0xFFF80000
#define MCU_mModuleResetProtect_BaseAddr		0xFFF8F480

typedef volatile struct
{
	uint32 RESFactor;	/*0xFFF80760*/
	uint32 Fill0;		/*0xFFF80764*/
	uint32 RESFClean;	/*0xFFF80768*/
	uint32 Fill1[(0x860-0x76C)/sizeof(uint32)];
	uint32 RESFRedun;		/*0xFFF80860*/
	uint32 Fill2;			/*0xFFF80864*/
	uint32 RESFCRedun;	/*0xFFF80868*/
	uint32 Fill3[(0xA04-0x86C)/sizeof(uint32)];
	uint32 SWRESrequest;	/*0xFFF80A04*/
	uint32 Fill4[(0xF400-0xA08)/sizeof(uint32)];
	uint32 MRSTCtrl;		/*0xFFF8F400*/
	uint32 Fill5[(0xF500-0xF404)/sizeof(uint32)];
	uint32 PWRGD_CNT;	/*0xFFF8F500*/
}MCU_stsResetCtrl_Unit;

typedef const struct
{
	uint32 VDCE0RES : 1;
	uint32 VDCE1RES : 1;
	uint32 ETNB0RES : 1;
	uint32 ISM0RES : 1;
	uint32 ADCE0RES : 1;
	uint32 SG0RES : 1;
	uint32 SG1RES : 1;
	uint32 SG2RES : 1;
	uint32 SG3RES : 1;
	uint32 SG4RES : 1;
	uint32 LCBI0RES : 1;
	uint32 MLBB0RES : 1;
	uint32 SDRB0RES : 1;
	uint32 XC0RES : 1;
	uint32 Fill : 18;
	
}MCU_tstModuleEnable_UsrCfg;

typedef const  struct
{
	MCU_tstProtect_Unit *McuReset_ProtectAddr; 	/*0xFFF80000*/
	MCU_tstProtect_Unit *ModuleReset_ProtectAddr; 		/*0xFFF8F480*/
	
	MCU_stsResetCtrl_Unit *ResetCtrl;
	
	MCU_tstModuleEnable_UsrCfg *ModuleEnableCfg;
}MCU_tstResetCtrlModuleAttribute;

#if 0

typedef volatile struct
{
	uint32 RESFactor;	/*0x00*/
	uint32 Fill;		/*0x04*/
	uint32 RESFClean;	/*0x08*/
}MCU_tstResetReason_Unit;

typedef const struct
{
	MCU_tstModuleEnable ModuleCtrl;
	
	MCU_tstResetReason_Unit *ResetReason;		/*0xFFF80760*/
	volatile uint32 * SWRESA_Trigger_Addr;		/*0xFFF80A04*/
	MCU_tstProtect_Unit *SWRESA_ProtectAddr; 	/*0xFFF80000*/
	
	volatile uint32 * MRSTC_Trigger_Addr;			/*0xFFF8F400 -->write 0 to reset module*/
	MCU_tstProtect_Unit *MRSTC_ProtectAddr; 	/*0xFFF8F480*/
											/*PWRGD_CNT --> not change, so not need this code*/

}MCU_tstResetCtrlModuleAttribute;

#endif

/*MCU reset control*/
#define MCU_mResetReason_ISOPWRES	(1<<15)
#define MCU_mResetReason_ECMRES		(1<<14)
#define MCU_mResetReason_ISORES		(1<<10)
#define MCU_mResetReason_POC0RES	(1<<9)
#define MCU_mResetReason_RESET		(1<<8)
#define MCU_mResetReason_CLMA0RES	(1<<3)
#define MCU_mResetReason_WDTA1RES	(1<<2)
#define MCU_mResetReason_WDTA0RES	(1<<1)
#define MCU_mResetReason_SWRES		(1<<0)

/*Module reset control*/
#define MCU_mModuleReset_XC0RES		(1<<13)
#define MCU_mModuleReset_SDRB0RES	(1<<12)
#define MCU_mModuleReset_MLBB0RES	(1<<11)
#define MCU_mModuleReset_LCBI0RES	(1<<10)
#define MCU_mModuleReset_SG4RES		(1<<9)
#define MCU_mModuleReset_SG3RES		(1<<8)
#define MCU_mModuleReset_SG2RES		(1<<7)
#define MCU_mModuleReset_SG1RES		(1<<6)
#define MCU_mModuleReset_SG0RES		(1<<5)
#define MCU_mModuleReset_ADCE0RES	(1<<4)
#define MCU_mModuleReset_ISM0RES		(1<<3)
#define MCU_mModuleReset_ETNB0RES	(1<<2)
#define MCU_mModuleReset_VDCE1RES	(1<<1)
#define MCU_mModuleReset_VDCE0RES	(1<<0)



/***********************************************************
 interrupt configuration !!
************************************************************/
#define MCU_INT_NoUse	((vpFun)0x00000000)

#define MCU_mEIC_BasicAddr_Hpr		0xFFFEEA00 /*interrupt number EIC0 -EIC31*/
#define MCU_mEIC_BasicAddr_Lpr		0xFFFFB000 /*interrupt number EIC32 -EIC255--->0xFFFFB040*/
#define MCU_mEIMR_HighPro_BasicAddr		0xFFFEEAF0 /*IMR0 for mask interrupt number EIC0 -EIC31, One bit = one channel mask*/
#define MCU_mEIMR_LowPro_BasicAddr		0xFFFFB400 /*IMR1~7 for mask interrupt number EIC32 -EIC255  0xFFFFB400-->0xFFFFB404*/

typedef volatile struct
{
	uint16 PRO : 4;		/*bit 0-3*/
	uint16 Fill4 : 2;	/*bit 4-5*/
	uint16 TB : 1;		/*bit 6*/
	uint16 MK : 1;		/*bit 7*/
	uint16 Fill3 : 4;	/*bit 8-11*/
	uint16 RF : 1;		/*bit 12*/
	uint16 Fill2 : 2;	/*bit 13-14*/
	uint16 CT : 1;		/*bit 15*/
	
}MCU_tstEIAttribute_Unint;


typedef  volatile uint32 MCU_vIMRtable;				/*Mask IMR is a bit for each channel*/

#define MCU_mMaxVectorNumber		256 /*Max vector number in this MCU*/
#define MCU_mMaxVectorPrority		16 /*Max vector prority in this MCU*/

typedef const struct
{
	/*system error type, can not control by user, it run interrupt function directely-----*/

	MCU_tstEIAttribute_Unint *EICtrl_Hpro ;	/*0xFFFEEAF0, up to more then 250 interrupts, 
											control the MKxx IFxx TBxx etc*/
											
	MCU_tstEIAttribute_Unint *EICtrl_Lpro ;	/*0xFFFFB404*/
	
	MCU_vIMRtable *IMR_Hprority;	/*0xFFFEEAF0 --> same effict with MKxx, so do not care it*/
	MCU_vIMRtable *IMR_Lprority;	/*0xFFFFB404 --> same effict with MKxx, so do not care it*/

	uint32 MaxVectorNumber;	/*MCU_mMaxVectorNumber*/

}MCU_tstInterruptModuleAttribute;



/***********************************************************
	standby configuration !!
************************************************************/
typedef volatile struct
{
	uint32 PSC;								/*0x00*/
	uint32 Fill0[(0x400-0x04)/sizeof(uint32)];		/*0x400 - 0x04*/
	uint32 WUF;								/*0x400*/
	uint32 WUFMSK;							/*0x404*/
	uint32 WUFC;								/*0x408*/
	uint32 Fill1[(0xB00-0x40C)/sizeof(uint32)];		/*0xB00 - 0x40C*/
	uint32 IoHold;								/*0xB00*/
	
}MCU_tstSTBC_Unit;

typedef const struct
{
	
	uint32	INTDCUTDI	:1;
	uint32	INTP0_RLIN31RX	:1;
	uint32	INTP1	:1;
	uint32	INTP2_RLIN32RX	:1;
	uint32	INTP3	:1;
	uint32	INTP4_RLIN33RX	:1;
	uint32	INTP5	:1;
	uint32	INTP6_CAN0RX	:1;
	uint32	INTP7	:1;
	uint32	INTP8_CAN1RX_RLIN30RX	:1;
	uint32	INTP9	:1;
	uint32	INTP10_CAN2RX_RLIN30RX	:1;
	uint32	INTWDTA0	:1;
	uint32	INTRTCA01S	:1;
	uint32	INTRTCA0AL	:1;
	uint32	INTRTCA0R	:1;
	uint32	INTAWOT0	:1;
	uint32	ECMTI	:1;
	uint32	ECMTNMI :1;
	uint32	Fill	:13;
}MCU_tstWakeUpFactorEnable;


typedef const struct
{
	MCU_tstWakeUpFactorEnable WakeUpEnable;	
}MCU_tstSTBC_UsrCfg;

typedef const struct
{
	MCU_tstSTBC_Unit *STBC;
	MCU_tstProtect_Unit *ProtectAddr;
	MCU_tstSTBC_UsrCfg *STBC_UsrCfg;	
}MCU_tstSTBCModuleAttribute;


#define MCU_mDNFA_BasicAddr	0xFFC30000U

typedef volatile struct
{
	MCU_tstReg_U8 CTLsetting;				/*0x00-->noise filter parameter setting for each group channels*/
	MCU_tstReg_U16 ENable;				/*0x04-->filter control word, all channel*/
	uint32 Fill5[(0x100-0x8)/sizeof(uint32)];/*Fix to 0x100 bytes*/
}MCU_tstDNFA_Unit;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		port setting   mapping
		@@@@@@@@@@		  
####################################################*/
typedef volatile uint32  MCU_tstIOHold;


/*########################################################
	Pin attribute configeration for user,configerate it for difference project
########################################################*/
	
typedef const struct
{
	uint32 AltFun : 8;			/*bit31-24: PMn,PMCn,PIBCn,PFCn,PFCEn,PFCAEn,*/
	uint32 ResetLevel : 1;		/*bit23: P*/

	uint32 PullUpEnable : 1;		/*bit22:	PUn*/
	uint32 PullDownEnable : 1;	/*bit21:	PDn*/
	uint32 OpenDEnable : 1; 	         /*bit20:	PODCn*/
	uint32 PinPutBufType : 1;	/*bit19:	PISn*/
	uint32 PinHighSpeedEnable : 1;/*bit18:	PDSCn*/
	uint32 PbdcEnable : 1;              /*bit17:	PBDCn-->one pin need input/output mode, for example: IIC_SDA*/
	uint32 Fill : 17;		/*bit16-0*/

}MCU_tstPinCfg;


/*****************************************
	Port struct 
****************************************/
typedef volatile struct
{
	MCU_tstReg_U16 P;/*MCU_mPortBaseAddr + 0x00*/
	uint32 PSR;			/*+ 0x04*/
	MCU_tstReg_U16 PNOT;	/*+ 0x08*/
	MCU_tstReg_U16 PPR;	/*+ 0x0C*/
	MCU_tstReg_U16 PM;	/*+ 0x10*/
	MCU_tstReg_U16 PMC;	/*+ 0x14*/
	MCU_tstReg_U16 PFC;	/*+ 0x18*/
	MCU_tstReg_U16 PFCE;	/*+ 0x1C*/
	uint32 PMSR;			/*+ 0x20*/
	uint32 PMCSR;			/*+ 0x24*/
	MCU_tstReg_U16 PFCAE;/*+ 0x28*/
	uint32 Fill8;			/*+ 0x2C*/
	MCU_tstReg_U16 PINV;	/*+ 0x30*/
	uint32 Fill10[(0x40u-0x34u)/sizeof(uint32)];/*Fix to 0x40byte size*/
	
}MCU_stsPinStruct_PortBasic;

typedef volatile struct
{
	MCU_tstReg_U16 PIBC;	/*MCU_mPortBaseAddr + 0x4000 + 0x00*/
	MCU_tstReg_U16 PBDC;	/*+ 0x04*/
	MCU_tstReg_U16 PIPC;	/*+ 0x08*/
	MCU_tstReg_U16 PU;	/*+ 0x0C*/
	MCU_tstReg_U16 PD;	/*+ 0x10*/
	uint32 PODC;			/*+ 0x14*/
	uint32 PDSC;			/*+ 0x18*/
	MCU_tstReg_U16 PIS;	/*+ 0x1C*/
	uint32 Filed1;			/*+ 0x20*/
	MCU_tstReg_U16 PISA;	/*+ 0x24*/
	uint32 Fill7[(0x40-0x28)/sizeof(uint32)];/*Fix to 0x40byte size*/
}MCU_stsPinStruct_PortExt;

typedef volatile struct
{
	uint32 Fill31:	1;	/*bit31*/
	uint32 PINV : 	1;	/*bit30*/
	uint32 Fill29:	1;	/*bit29*/
	uint32 PODC:	1;	/*bit28*/
	uint32 Fill27:	1;	/*bit27*/
	uint32 Fill26:	1;	/*bit26*/
	uint32 Fill25:	1;	/*bit25*/
	uint32 PDSC:	1;	/*bit24*/
	uint32 Fill23:	1;	/*bit23*/
	uint32 PISA:	1;	/*bit22*/
	uint32 Fill22:	1;	/*bit21*/
	uint32 PIS:	1;	/*bit20*/
	uint32 PU:	1;	/*bit19*/
	uint32 PD:	1;	/*bit18*/
	uint32 PBDC:	1;	/*bit17*/
	uint32 PIBC:	1;	/*bit16*/
	uint32 Fill15:	1;	/*bit15*/
	uint32 Fill14:	1;	/*bit14*/
	uint32 Fill13:	1;	/*bit13*/
	uint32 P	:	1;	/*bit12*/
	uint32 Fill11:	1;	/*bit11*/
	uint32 Fill10:	1;	/*bit10*/
	uint32 Fill9:	1;	/*bit9*/
	uint32 PPR:	1;	/*bit8*/
	uint32 Fill7:	1;	/*bit7*/
	uint32 PMC:	1;	/*bit6*/
	uint32 PIPC:	1;	/*bit5*/
	uint32 PM:	1;	/*bit4*/
	uint32 Fill3:	1;	/*bit3*/
	uint32 Fill2:	1;	/*bit2*/
	uint32 PFCE:	1;	/*bit1*/
	uint32 PFC:	1;	/*bit0*/
	
}MCU_stsPinStruct_PortPCR;



#define MCU_mProtCmd_Addr_P0		0xFFC1C02C	
#define MCU_mProtCmd_Addr		0xFFC1406C	
#define MCU_mProtCmd_Addr_JP0	0xFFC2402C

typedef volatile struct
{
	uint32 Commond;	/*0x00*/
	uint32 Filed1;		/*0x04*/ 
	uint32 Status;		/*0x08*/ 
	uint32 Filed2[(0x40-0x0c)/sizeof(uint32)];/*fix to 0x40 byte size*/
}MCU_tstPortProtect_Unit;


/*****************************************
	Port Attribute struct 
****************************************/
typedef const struct
{

	MCU_tstPortProtect_Unit * PortProtectAddr_P0;	/*MCU_tstPortProtect_Unit*/
	MCU_tstPortProtect_Unit * PortProtectAddr;	/*MCU_tstPortProtect_Unit*/
	MCU_tstPortProtect_Unit * JPortProtectAddr_JP0;/*MCU_tstPortProtect_Unit*/
	
	/*Port*/
	uint32 TottalPortNumber_Port;
	MCU_stsPinStruct_PortBasic *PortAddr;
	MCU_stsPinStruct_PortExt *PortAddrExt;
	MCU_stsPinStruct_PortPCR (*PortAddrPCR)[0x40/sizeof(MCU_stsPinStruct_PortPCR)] ;
	
	MCU_stsPinStruct_PortBasic *PortAddr_P0;
	MCU_stsPinStruct_PortExt *PortAddrExt_P0;
	MCU_stsPinStruct_PortPCR *PortAddrPCR_P0;
	
	MCU_tstPinCfg * const PinCfgHead_Port; 

	/*JPort*/
	uint32 TottalPortNumber_JPort;
	
	MCU_stsPinStruct_PortBasic *JPortAddr_JP0;
	MCU_stsPinStruct_PortExt *JPortAddrExt_JP0;
	MCU_stsPinStruct_PortPCR *JPortAddrPCR_JP0;
	
	MCU_tstPinCfg * const PinCfgHead_JPort; 
	
}MCU_stsPortAttribute;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		EINT setting   mapping
		@@@@@@@@@@		  
####################################################*/

#define MCU_mMaxEINTchannelMount	12
#define MCU_mFCLA0_BasicAddr	0xFFC34000u
#define MCU_mFCLA1_BasicAddr	0xFFC34100U

typedef volatile struct
{
	MCU_tstReg_U8 CTL[8];			/*0x00*/
	uint32 Fill[(0x100U-8*sizeof(uint32))/sizeof(uint32)];	/*fix to 0x100*/
}MCU_tstFCLA_Unit;


typedef const struct 
{
	uint16 u16DetectCondition;
	uint16 u16RunWhenReset;
	vpFun	vpINTservice;		/*interrupt function when DMA finish!*/
}MCU_tstEINT_UsrCfg;


typedef const struct
{
	MCU_tstFCLA_Unit *FCLA;
	uint16 u16EINTvectList[1];
	MCU_tstEINT_UsrCfg *EINT_UsrCfg;	
}MCU_tstEINTModuleAttribute;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		OSTM setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mOSTM_BasicAddr	0xFFEC0000
#define MCU_mOSTM_Mun	2
#define MCU_mOSTM_IRQNum	ISR_125_INTOSTM0

typedef volatile struct
{
	uint32 CMP;			/*0x00*/
	uint32 CNT;			/*0x04*/
	MCU_tstReg_U8 TO;	/*0x08*/
	MCU_tstReg_U8 TOE;	/*0x0C*/
	MCU_tstReg_U8 TE;	/*0x10*/
	MCU_tstReg_U8 TS;	/*0x14*/
	MCU_tstReg_U8 TT;	/*0x18*/
	uint32 Fill5;			/*0x1C*/
	MCU_tstReg_U8 CTL;	/*0x20*/
	MCU_tstReg_U8 EMU;	/*0x24*/
	uint32 Fill8[(0x1000 - 0x28)/sizeof(uint32)];/*fix to 0x1000 byte size for a unit!!*/
}MCU_tstOSTM_Unit;


typedef const struct
{
	uint32 u32Interval_Us;
	uint32 u32RunInRst;
	vpFun vpOSTM_IRQ;
}MCU_tstOSTM_UsrCfg;


typedef const struct
{
	uint32 IRQ_Num;
	MCU_tstOSTM_Unit *OSTM_BasicAddr;
	MCU_tstOSTM_UsrCfg *OSTM_Cfg;
}MCU_tstOSTMModuleAttribute;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		PWGA setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mPWBA_BasicAddr	0xFFE45800
#define MCU_mPWGA_BasicAddr	0xFFE44000
#define MCU_mPWSA_BasicAddr	0xFFE45A00
#define MCU_mSLPWGA_BasicAddr	0xFFE45900
#define MCU_mPWBA_MaxChannel	4
#define MCU_mPWSA_MaxTrigGroup	8
#define MCU_mPWGA_MaxChannel		24

typedef volatile struct
{
	MCU_tstReg_U16 BRS[MCU_mPWBA_MaxChannel];	/*0X00-0x10*/
	MCU_tstReg_U8 TE;						/*0x10*/
	MCU_tstReg_U8 TS;						/*0x14*/
	MCU_tstReg_U8 TT;						/*0x18*/
	MCU_tstReg_U8 EMU;						/*0x1C*/
}MCU_tstPWBA_Unit;

typedef volatile struct
{
	MCU_tstReg_U16 CSDR;	/*0x00*/
	MCU_tstReg_U16 CRDR;	/*0x04*/
	MCU_tstReg_U16 CTDR;	/*0x08*/
	MCU_tstReg_U8 RDT;	/*0x0C*/
	MCU_tstReg_U8 RSF;	/*0x10*/
	MCU_tstReg_U16 CNT;	/*0x14*/
	uint32 Fill1;			/*0x18*/
	uint32 Fill2;			/*0x1C*/
	MCU_tstReg_U8 CTL;	/*0x20*/
	MCU_tstReg_U16 CSBR;	/*0x24*/
	MCU_tstReg_U16 CRBR;	/*0x28*/
	MCU_tstReg_U16 CTBR;	/*0x2C*/
	uint32 Fill3[(0x100-0x30)/sizeof(uint32)];/*fix to size 0x100*/
}MCU_tstPWGA_Unit;

typedef volatile uint32 MCU_tstSLPWGA;

typedef volatile struct
{
	MCU_tstReg_U8 CTL;	/*0X00*/
	MCU_tstReg_U8 STR;	/*0X04*/				
	MCU_tstReg_U8 STC;	/*0X08*/				
	MCU_tstReg_U8 EMU;	/*0x0C*/
	uint32 Filed[(0x20-0x10)/sizeof(uint32)];	/*0x10-0x20*/
	MCU_tstReg_U8 QUE[MCU_mPWSA_MaxTrigGroup];	/*0x20 -0x40*/
	uint16 PVCR[MCU_mPWGA_MaxChannel];	/*0x40 -*/
}MCU_tstPWSA_Unit;

typedef const struct
{
	uint32 Frequency[MCU_mPWBA_MaxChannel];
	
	struct
	{
		uint32 FrequencySelect;
		uint32 DefaultDuty;
	} ChannelCfg[MCU_mPWGA_MaxChannel];
}MCU_tstPWGA_UsrCfg;

/*running control*/
typedef struct
{
	uint32 Duty;
	uint32 Hz;
}MCU_tstPWGAUpdateStatus;

typedef struct
{
	MCU_tstPWGAUpdateStatus UpdateStatus[MCU_mPWBA_MaxChannel];
	uint16 PWGAclkUsing[MCU_mPWBA_MaxChannel];
}MCU_tstPWGARunStatus;

typedef const struct
{
	MCU_tstPWBA_Unit *PWBA;
	MCU_tstPWGA_Unit *PWGA;
	MCU_tstSLPWGA *SLPWGA;
	MCU_tstPWSA_Unit *PWSA;
	#if 0
	uint16 *VectNumList;
	#endif
	MCU_tstPWGA_UsrCfg *PWGA_Cfg;
}MCU_tstPWGAModuleAttribute;



/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		TAUX setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mTAUB_Unit	3
#define MCU_mTAUB0_Channel	16
#define MCU_mTAUB0_BasicAddr	0xFFE30000
#define MCU_mTAUB1_Channel	16
#define MCU_mTAUB1_BasicAddr	0xFFE31000

#define MCU_mTAUB2_Channel	16
#define MCU_mTAUB2_BasicAddr	0xFFE32000

#define MCU_mTAUD_Unit	0
#define MCU_mTAUD0_Channel	16

#define MCU_mTAUBD_MaxID	MCU_mTAUB2_15

#define MCU_mTAUJ_Unit	1
#define MCU_mTAUJ0_Channel	4
#define MCU_mTAUJ0_BasicAddr	0xFFE50000


typedef volatile struct
{
	MCU_tstReg_U16 CDR[MCU_mTAUB0_Channel];	/*0x00-0x40*/
	MCU_tstReg_U16 TOL;					/*0x40*/
	MCU_tstReg_U16 RDT;					/*0x44*/
	MCU_tstReg_U16 RSF;					/*0x48*/
	uint32 Filed1;							/*0x4C*/
	uint32 Filed2;							/*0x50*/
	MCU_tstReg_U16 TDL;					/*0x54*/
	MCU_tstReg_U16 TO;					/*0x58*/
	MCU_tstReg_U16 TOE;					/*0x5C*/
	uint32 Filed3[(0x80-0x60)/sizeof(uint32)];	/*0x60-0x80*/
	MCU_tstReg_U16 CNT[MCU_mTAUB0_Channel];		/*0x80-0xC0*/
	MCU_tstReg_U8 CMUR[MCU_mTAUB0_Channel];		/*0xC0-0x100*/
	uint32 Filed4[(0x140-0x100)/sizeof(uint32)];/*0x100-0x140*/
	MCU_tstReg_U8 CSR[MCU_mTAUB0_Channel];		/*0x140-0x180*/
	MCU_tstReg_U8 CSC[MCU_mTAUB0_Channel];		/*0x180-0x1C0*/
	MCU_tstReg_U16 TE;					/*0x1C0*/
	MCU_tstReg_U16 TS;					/*0x1C4*/
	MCU_tstReg_U16 TT;					/*0x1C8*/
	uint32 Filed5[(0x200-0x1CC)/sizeof(uint32)];/*0x1CC-0x200*/
	MCU_tstReg_U16 CMOR[MCU_mTAUB0_Channel];		/*0x200-0x240*/
	MCU_tstReg_U16 TPS;					/*0x240*/
	uint32 Filed6;							/*0x244*/
	MCU_tstReg_U16 TOM;					/*0x248*/
	MCU_tstReg_U16 TOC;					/*0x24C*/
	MCU_tstReg_U16 TDE;					/*0x250*/
	uint32 Filed7[(0x260-0x254)/sizeof(uint32)];/*0x254-0x260*/
	MCU_tstReg_U16 RDE;					/*0x260*/
	MCU_tstReg_U16 RDM;					/*0x264*/
	MCU_tstReg_U16 RDS;					/*0x268*/
	MCU_tstReg_U16 RDC;					/*0x26C*/
	uint32 Filed8[(0x290-0x270)/sizeof(uint32)];/*0x270-0x290*/
	MCU_tstReg_U8 EMU;					/*0x290*/
	uint32 Filed9[(0x1000-0x294)/sizeof(uint32)];/*Fix to 0x1000 bytes in a unit*/	
}MCU_tstTAUBD_Unit;

typedef volatile struct
{
	uint32 CDR[MCU_mTAUJ0_Channel];	/*0x00-0x10*/
	uint32 CNT[MCU_mTAUJ0_Channel];	/*0x10-0x20*/
	MCU_tstReg_U8 CMUR[MCU_mTAUJ0_Channel];	/*0x20-0x30*/
	MCU_tstReg_U8 CSR[MCU_mTAUJ0_Channel];	/*0x30-0x40*/
	MCU_tstReg_U8 CSC[MCU_mTAUJ0_Channel];	/*0x40-0x50*/
	MCU_tstReg_U8 TE;						/*0x50*/
	MCU_tstReg_U8 TS;						/*0x54*/
	MCU_tstReg_U8 TT;						/*0x58*/
	MCU_tstReg_U8 TO;						/*0x5C*/
	MCU_tstReg_U8 TOE;						/*0x60*/
	MCU_tstReg_U8 TOL;						/*0x64*/
	MCU_tstReg_U8 RDT;						/*0x68*/
	MCU_tstReg_U8 RSF;						/*0x6C*/
	uint32 Filed1[(0x80-0x70)/sizeof(uint32)];	/*0x70-0x80*/
	MCU_tstReg_U16 CMOR[MCU_mTAUJ0_Channel];		/*0x80-0x90*/
	MCU_tstReg_U16 TPS;						/*0x90*/
	MCU_tstReg_U8 BRS;						/*0x94*/
	MCU_tstReg_U8 TOM;						/*0x98*/
	MCU_tstReg_U8 TOC;						/*0x9C*/
	MCU_tstReg_U8 RDE;						/*0xA0*/
	MCU_tstReg_U8 RDM;						/*0xA4*/
	MCU_tstReg_U8 EMU;						/*0xA8*/
	uint32 Filed2[(0x1000-0xAC)/sizeof(uint32)];/*Fix to 0x1000 bytes in a unit*/	
}MCU_tstTAUJ_Unit;

typedef const struct
{
	uint32 CMOR;
	uint32 TimerIOSeting;
}MCU_tstTAUx_RegisterValue;

typedef const struct
{
	uint16 TimerMode;
	uint16 ClkSelect;
	uint32 Counter;
	uint32 Condition;
	uint32 AutoRun;/*it will run auto after reset*/
	vpFun TimerCB;
}MCU_tstTAUx_UsrCfg;

typedef uint32 MCU_tstTAUxClkDiv_UsrCfg;

typedef const struct
{
	MCU_tstTAUBD_Unit *TAUBD[MCU_mTAUB_Unit+MCU_mTAUD_Unit];
	MCU_tstTAUJ_Unit *TAUJ[MCU_mTAUJ_Unit];
	uint32 VectList[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit];
	uint32 TimerAltFun[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit];
	MCU_tstTAUx_RegisterValue *TAUx_RegVal;
	MCU_tstTAUxClkDiv_UsrCfg (*TAUxClkDiv_Cfg)[4];
	MCU_tstDNFA_Unit *DNFA;
	MCU_tstTAUx_UsrCfg *TAUx_Cfg;
}MCU_tstTAUxModuleAttribute;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RIIC setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mRIIC_Unit	2
#define MCU_mRIIC_BasicAddr	0xFFDB0000U

typedef volatile struct 
{
	uint32 CR1;	/*0x00*/
	uint32 CR2;	/*0x04*/
	uint32 MR1;	/*0x08*/
	uint32 MR2;	/*0x0C*/
	uint32 MR3;	/*0x10*/
	uint32 FER;	/*0x14*/
	uint32 SER;	/*0x18*/
	uint32 IER;	/*0x1C*/
	uint32 SR1;	/*0x20*/
	uint32 SR2;	/*0x24*/
	uint32 SAR0;	/*0x28*/
	uint32 SAR1;	/*0x2C*/
	uint32 SAR2;	/*0x30*/
	uint32 BRL;	/*0x34*/
	uint32 BRH;	/*0x38*/
	uint32 DRT;	/*0x3C*/
	uint32 DRR;	/*0x40*/

	uint32 Fill[(0x1000 - 0x44)/sizeof(uint32)];/*fix to 0x1000 byte size*/
}MCU_tstRIIC_Unit;

typedef const struct 
{
	uint32 u32TansferSpeed;
	
	struct {
	         uint32 u32SlaveAddr;
		vpFun vpSendfinishCB_BuffEmpty;
		vpFun vpSendfinishCB;
		vpFun vpRecFinishCB;
		vpFun_u8 vu8ErrCB;
	}stSlaveCB[MCU_mI2CMaxSlaveInMaster];
}MCU_tstRIIC_UsrCfg;

typedef struct _MCU_tstIICctrl
{
	uint8 u8SlaveChannel;
	uint8 u8Runmode;/*send or receive mode record*/
	uint8 u8Error;
	uint8 *pu8DataHead;
	uint16 u16WorkingDataLen;
	uint16 u16TottalDataLen;
}MCU_tstIICctrl;

#define RIIC_Ready		0u
#define RIIC_Sending		1u
#define RIIC_Receiving		2u
#define RIIC_DUMMY		0xFFu

typedef const struct
{
	MCU_tstRIIC_Unit *RIIC;
	struct{
		uint32 BufferEmptyVect;
		uint32 SendFinshVect;
		uint32 ReceiveVect;
		uint32 ErrorVect;
	}VectList[MCU_mRIIC_Unit];
	
	MCU_tstRIIC_UsrCfg *RIIC_UsrCfg;
}MCU_tstRIICModuleAttribute;

#if 0
//////////////////////////////////////////////////////////////////////////////////

/********
DMA unit
**********/
#define MCU_mDMA_MaxChn	16
#define MCU_mDMA_BasicAddr	0xFFFF8000U

typedef volatile struct 
{
	uint32 DSA;							/*0x00*/
	uint32 DDA;							/*0x04*/
	uint32 DTC;							/*0x08*/
	uint32 DTCT;							/*0x0C*/
	uint32 DRSA;							/*0x10*/
	uint32 DRDA;							/*0x14*/
	uint32 DRTC;							/*0x18*/
	uint32 DTCC;							/*0x1C*/
	uint32 DCEN;							/*0x20*/
	uint32 DCST;							/*0x24*/
	uint32 DCSTS;							/*0x28*/
	uint32 DCSTC;							/*0x2C*/
	uint32 DTFR;							/*0x30*/
	uint32 DTFRRQ;						/*0x34*/	
	uint32 DTFRRQC;						/*0x38*/
	
	uint32 Fill1[(0x40 -0x3C)/sizeof(uint32)];	/*fix to 0x40 size*/
	
}DMA_Channel;

typedef volatile struct 
{
	uint32 DMACTL;										/*0x00*/
	uint32 Fill1[(0x20-0x04)/sizeof(uint32)];				/*0x20--0x04*/
	uint32 DMACER;									/*0x20*/
	uint32 Fill2[(0x30-0x24)/sizeof(uint32)];				/*0x30--0x24*/
	uint32 DM0CMV;									/*0x30*/
	uint32 DM1CMV;									/*0x34*/
	uint32 Fill3;										/*0x38*/
	uint32 CMVC;										/*0x3C*/
	uint32 Fill4[(0x100-0x40)/sizeof(uint32)];				/*0x40 ---0x100*/
	uint32 DMxxCM[MCU_mDMA_MaxChn];					/*0x100 --0x140*/
	uint32 Fill5[(0x400-0x140)/sizeof(uint32)];			/*0x400*/
	
	DMA_Channel DMA_0_15[MCU_mDMA_MaxChn];			/*0x400--0x800*/

}MCU_tstDMA_Unit;



/*########################################################
	DMA channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef const struct 
{
	uint32 u32SourceAddr;
	uint32 u32DestAddr;
	uint16 u16AddrControl;
	uint16 u16DataUnitSize;		/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataLenth;		/*how many byte data to transfer*/
	uint16 u16TrigVecNum;

	vpFun	vpINTservice;		/*interrupt function when DMA finish!*/
}MCU_tstDMA_UsrCfg;

typedef const struct
{
	MCU_tstDMA_Unit *DMA;
	uint32 u32DMAvectList;
	MCU_tstDMA_UsrCfg *DMA_UsrCfg;
	
}MCU_tstDMAModuleAttribute;


typedef struct 
{
	MCU_enDmaID u32DMAChannel;
	uint32 u32SourceAddr;
	uint32 u32DestAddr;
	uint16 u16AddrControl;
	uint16 u16DataUnitSize;		/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataLenth;		/*how many byte data to transfer*/
	uint16 u16TrigVecNum;

}MCU_tstDMA_SetUp;

#endif


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		ADC setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mADCAUint_Number		1
#define MCU_mADCA_BasicAddr	0xFFF20000U

typedef volatile struct
{
	uint32 SGSTCR ; 	/*0x00*/
	uint32 Fill;		/*0x04*/
	uint32 SGCR  ;		/*0x08*/
	uint32 SGVCSP ;	/*0x0C*/
	uint32 SGVCEP  ;	/*0x10*/
	uint32 SGMCYCR  ;	/*0x14*/
	uint32 SGSEFCR  ;	/*0x18*/
	uint32 SGTSEL  ;	/*0x1C*/
	uint32 Fill1[(0x40-0x20)/sizeof(uint32)];/*fix to 0x40 byte size*/
	
}MCU_tstSGGroup_Unit;

//--------------D1X only----------------------
typedef volatile struct
{
	uint32 Fill1 ; 		/*0x00*/
	uint32 Fill2;		/*0x04*/
	uint32 TSNSGCR ;	/*0x08*/
	uint32 Fill3 ;		/*0x0C*/
	uint32 Fill4  ;		/*0x10*/
	uint32 Fill5  ;		/*0x14*/
	uint32 TSNSGSEFCR;/*0x18*/
	uint32 TSNSGTSEL  ;/*0x1C*/
	uint32 Fill7[(0x40-0x20)/sizeof(uint32)];/*fix to 0x40 byte size*/
	
}MCU_tstTempSenserGroup_Unit;

#define ADCA_INTPEDGCTL 0xFFC0603C /*Trigger select address*/
//--------------D1X only----------------------

typedef volatile struct
{
	uint32 VCR[(0xF0-0x00)/sizeof(uint32)];	/*0x00-0xF0*/
	uint32 TSNVCR;						/*0xF0 -->D1X Only*/
	uint32 PWDVCR;						/*0xF4*/
	uint32 Fill1[(0x100-0xF8)/sizeof(uint32)];
	uint16 DR[(0x178-0x100)/sizeof(uint16)];	/*0x100-0x178 (2byte a unit!!!)*/
	uint32 PWDTSNDR;						/*0x178*/ 
	uint32 Fill2[(0x200-0x17C)/sizeof(uint32)];
	uint32 DIR[(0x2F0-0x200)/sizeof(uint32)];	/*0x200*/
	uint32 TSNDIR;						/*0x2F0 -->D1X Only*/ 
	uint32 PWDDIR;						/*0x2F4*/ 
	uint32 Fill3[(0x300-0x2F8)/sizeof(uint32)];
	
	 uint32 ADHALTR ;		/* 0x300 */
	 uint32 ADCR ;			/* 0x304 */
	 uint32 SGSTR ;		/* 0x308 */
	 uint32 MPXCURR ;		/* 0x30C */
	 uint32 Fill4;			/* 0x310 */
	 uint32 THSMPSTCR ;	/* 0x314 */
	 uint32 THCR ;			/* 0x318 */
	 uint32 THAHLDSTCR ;	/* 0x31C */
	 uint32 THBHLDSTCR ;	/* 0x320 */
	 uint32 THACR ;		/* 0x324 */
	 uint32 THBCR ;		/* 0x328 */
	 uint32 THER ;			/* 0x32C */
	 uint32 THGSR ;		/* 0x330 */
	 uint32 SFTCR ;		/* 0x334 */
	 uint32 ULLMTBR0 ;		/* 0x338 */
	 uint32 ULLMTBR1 ;		/* 0x33C */
	 uint32 ULLMTBR2 ;		/* 0x340 */
	 uint32 ECR ;			/* 0x344 */
	 uint32 ULER ;			/* 0x348 */
	 uint32 OWER ;		/* 0x34C */
	 uint32 DGCTL0 ;		/* 0x350 */
	 uint32 DGCTL1;		/* 0x354 */
	 uint32 PGCTL1;		/* 0x358 */
	 uint32 PGCTL2;		/* 0x35C */
	 uint32 Fill5[(0x380-0x360)/sizeof(uint32)];	
	 uint32 SMPCR ;		/* 0x380 */
	 uint32 TSNSMPCR;		/* 0x384 -->D1X Only */
	 MCU_tstReg_U8 EMU ;			/* 0x388 */
	 uint32 SGPRCR;		/* 0x38C -->D1X Only */	 
	 uint32 Fill7[(0x400-0x390)/sizeof(uint32)];	
	 
	 MCU_tstTempSenserGroup_Unit TSG; /*0x400-0x440*/
	 MCU_tstSGGroup_Unit SG1_3[3]; /*0x440 + 0x40 x 3*/
	 
	 uint32 Fill8[(0x508-0x500)/sizeof(uint32)];		
	 uint32 PWDSGCR ;		/* 0x508 */
	 uint32 Fill9[(0x518-0x50C)/sizeof(uint32)];	
	 uint32 PWDSGSEFCR ;	/* 0x518 */
	 uint32 Fill10[(0x1000-0x51C)/sizeof(uint32)];/*fix to 0x1000 byte size*/
	 
}MCU_tstADCA_Unit;


typedef const struct
{
	uint32 u32ADCusingMask_ADCA0_P1;/*channel 0~31---> channel 20 input source is Isolated-Area power supply ISOVDD*/
	uint32 u32ADCusingMask_ADCA0_P2;/*channel 32~63 --->channel 37 input source is CPU temperture sensor !!*/
	
	uint32 u32ADCusingMask_ADCA1_P1;/*channel 0~31  -->not mount in D1X*/
	uint32 u32ADCusingMask_ADCA1_P2;/*channel 32~63 -->not mount in D1X*/
	
}MCU_tstADCA_UsrCfg;

typedef const struct
{
	MCU_tstADCA_Unit *ADCA;
	uint32 ChnlNumInUint[MCU_mADCAUint_Number];
	uint16 u16ADCAvectList_SG1_finish[MCU_mADCAUint_Number];
	MCU_tstADCA_UsrCfg *ADCA_UsrCfg;	
}MCU_tstADCAModuleAttribute;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RLIN3 setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mRLIN3Uint_Number		4
#define MCU_mRLIN3_BasicAddr	0xFFCE0000

typedef volatile struct
{
	uint8 Fill1 ;	/* 0x00   */
	uint8 LWBR ;	/* 0x01   */
	uint8 LBRP0 ;	/* 0x02   */
	uint8 LBRP1 ;	/* 0x03   */
	uint8 LSTC ;	/* 0x04   */
	uint8 Fill2[0x08-0x05];
	uint8 LMD ;	/* 0x08   */
	uint8 LBFC ;	/* 0x09   */
	uint8 LSC ;	/* 0x0A   */
	uint8 LWUP ;	/* 0x0B   */
	uint8 LIE ;	/* 0x0C   */
	uint8 LEDE ;	/* 0x0D   */
	uint8 LCUC ;	/* 0x0E   */
	uint8 Fill3;
	uint8 LTRC ;	/* 0x10   */
	uint8 LMST ;	/* 0x11   */
	uint8 LST ;	/* 0x12   */
	uint8 LEST ;	/* 0x13   */
	uint8 LDFC ;	/* 0x14   */
	uint8 LIDB ;	/* 0x15   */
	uint8 LCBR ;	/* 0x16   */
	uint8 LUDB[0x20 - 0x17] ;/* 0x17 --  0x1F */
	uint8 LUOER ;	/* 0x20   */
	uint8 LUOR1 ;	/* 0x21   */
	uint16 Fill4;	/* 0x22   */
	uint16 LUTDR ;	/* 0x24   */
	uint16 LURDR ;	/* 0x26   */
	uint16 LUWTDR ;	/* 0x28   */
	uint16 Fill5[(0x1000-0x2A)/sizeof(uint16)]; /*fix to 0x1000 byte size*/
	
}MCU_tstRLIN3_Unit;


typedef const struct
{
	uint16 u16BaudRate;	/*transfer speed*/
	uint16 u16Msb;			/*data direction: MSB or LSB*/
	uint16 u16StopBit;		/*stop bit lenth, 1bit or 2bit*/
	uint16 u16Parity;			/*Parity type, Even Parity or Odd Parity enabled*/
		
	uint16 u16Rx_InversionOutput;
	uint16 u16Tx_InversionInput;
	
	vpFun vpSendFinish;				/*send finish callback*/
	vpFun_u8 vu8ErrCallBack;			/*error call back*/
	vpFun_u8 vu8RecCallBack;			/*recieve data callback*/
	
}MCU_tstLinUart_UsrCfg;

typedef struct 
{
	uint16 u16TottalDataLen;
	uint16 u16WorkingDataLen;
	uint8 *pu8DataHead;
}MCU_tstRLIN3UartCtrl;

typedef const struct
{
	MCU_tstRLIN3_Unit *RLIN3;
	uint16 VectList[MCU_mRLIN3Uint_Number];/*ONLY record first interrupt vector number for each channel*/
	MCU_tstLinUart_UsrCfg *RLIN3_UsrCfg;	
	
}MCU_tstRLIN3ModuleAttribute;



/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIG setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mCSIG_BaseAddr	0xFFDA0000
#define MCU_mCSIG_MaxChn	4

typedef volatile struct
{
	MCU_tstReg_U8 CTL0;	/*0x00*/
	uint32 STR0;			/*0x04*/
	MCU_tstReg_U16 STCR0;/*0x08*/
	uint32 Fill2;			/*0x0C*/
	uint32 CTL1;			/*0x10*/
	MCU_tstReg_U16 CTL2;	/*0x14*/
	MCU_tstReg_U8 EMU;	/*0x18*/
	uint32 Fill5[(0x1000-0x1c)/sizeof(uint32)];	/*0x1000-0x1C*/
	MCU_tstReg_U8 BCTL0;	/*0x1000*/
	uint32 TX0W;			/*0x1004*/
	MCU_tstReg_U16 TX0H;	/*0x1008*/
	MCU_tstReg_U16 RX0;	/*0x100C*/
	uint32 CFG0;			/*0x1010*/
	uint32 Fill9[(0x2000-0x1014)/sizeof(uint32)];/*Fix to 0x2000 byte size*/
}MCU_tstCSIG_Unit;

typedef const struct
{
	uint32 Bps;
	uint32 LSB_shift;
	uint32 ClkType;
	uint32 HankShakeEnable;
	uint32 SlaveMode;
	uint32 Parity;

	vpFun SendFinshCB;
	vpFun RecFinshCB;
	vpFun_u16 ErrCB;
	
}MCU_tstCSIG_UsrCfg;


typedef const struct
{
	MCU_tstCSIG_Unit *CSIG;
	MCU_enIsrID VectList[MCU_mCSIG_MaxChn];
	MCU_tstCSIG_UsrCfg *CSIG_UsrCfg;
}MCU_tstCSIGModuleAttribute;

typedef struct 
{
	uint16 u16TottalDataLen;
	uint16 u16WorkingDataLen;
	uint16 u16WorkingMode;
	uint16 *pu16SendDataHead;
	uint16 *pu16RecDataHead;
	
}MCU_tstCSGICtrl;



/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIH setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mCSIH_BaseAddr	0xFFDA8000ul
#define MCU_mCSIH_MaxChn	2

typedef volatile struct
{
	MCU_tstReg_U8 CTL0;	/*0x0*/
	uint32 STR0;			/*0x4*/
	MCU_tstReg_U16 STCR0;/*0x8*/
	uint32 Fill2;			/*0xC*/
	uint32 CTL1;			/*0x10*/
	MCU_tstReg_U16 CTL2;	/*0x14*/
	MCU_tstReg_U8 EMU;	/*0x18*/
	uint32 Fill4[(0x1000-0x1C)/sizeof(uint32)];	/*0x1C--->0x1000*/
	uint32 MCTL1;			/*0x1000*/
	uint32 MCTL2;			/*0x1004*/
	uint32 TX0W;			/*0x1008*/
	MCU_tstReg_U16 TX0H;	/*0x 100C*/
	uint32 RX0W;			/*0x1010*/
	MCU_tstReg_U16 RX0H;	/*0x1014*/
	uint32 MRWP0;		/*0x1018*/
	uint32 Fill7[(0x1040-0x101C)/sizeof(uint32)];
	MCU_tstReg_U16 MCTL0;/*0x1040*/
	uint32 CFG[8];			/*0x1044-->0x1060*/
	uint32 Fill9;			/*0x1064*/
	MCU_tstReg_U16 BRS[4];/*0x1068*/
	uint32 Fill10[(0x2000-0x1078)/sizeof(uint32)];/*Fix to 0x2000 byte size*/
}MCU_tstCSIH_Unit;

typedef const struct
{
	uint32 Bps;
	uint32 LSB_shift;
	uint32 ClkType;
	uint32 HankShakeEnable;
	uint32 SlaveMode;
	uint32 Parity;

	vpFun SendFinshCB;
	vpFun RecFinshCB;
	vpFun_u16 ErrCB;
	
}MCU_tstCSIH_UsrCfg;


typedef const struct
{
	MCU_tstCSIH_Unit *CSIH;
	MCU_enIsrID VectList[MCU_mCSIH_MaxChn];
	MCU_tstCSIH_UsrCfg *CSIH_UsrCfg;
}MCU_tstCSIHModuleAttribute;

typedef struct 
{
	uint16 u16TottalDataLen;
	uint16 u16WorkingDataLen;
	uint16 u16WorkingMode;
	uint16 *pu16SendDataHead;
	uint16 *pu16RecDataHead;
	
}MCU_tstCSHICtrl;


#endif/*end of this file*/

