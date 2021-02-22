/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L_Type.h
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

#ifndef _F1L_TYPE_H_
#define _F1L_TYPE_H_


#define MCU_mMaskPinID(PinID)			((uint16)((PinID) & 0x1FU))
#define MCU_mMaskPortID(PinID)		((uint16)(((uint16)((PinID)>>8U)) & 0xFFU))
#define MCU_mMaskPortType(PinID)		((uint16)((PinID) & 0x00e0U)>>5)

typedef volatile struct
{
	uint16 u16Value;/*0x00*/
	uint16 Fill0;	/*0x02*/
}MCU_tstReg_U16;

typedef volatile struct
{
	uint8 u8Value;/*0x00*/
	uint8 Fill0[3];	/*0x01*/
}MCU_tstReg_U8;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		System setting   mapping
		@@@@@@@@@@		  
####################################################*/


#define MCU_mDNFA_BasicAddr_TAUD		0xFFC30000U
#define MCU_mDNFA_BasicAddr_TAUB0	0xFFC30020U
#define MCU_mDNFA_BasicAddr_TAUB1	0xFFC30040U
typedef volatile struct
{
	MCU_tstReg_U8 CTLsetting;				/*0x00-->noise filter parameter setting for each group channels*/
	MCU_tstReg_U16 ENable;				/*0x04-->filter control word, all channel*/
	MCU_tstReg_U16 ENable_LowByte;		/*0x08-->can be bit access,for each channel*/
	MCU_tstReg_U16 ENable_HighByte;		/*0x0C-->can be bit access,for each channel*/
	uint32 Fill5[(0x20-0x10)/sizeof(uint32)];	/*Fix to 0x20 bytes*/
}MCU_tstDNFA_Unit;

#define MCU_mProtCmd0_Addr		0xFFC14C00	
#define MCU_mProtStatus0_Addr		0xFFC14B00	
#define MCU_mProtCmd1_Addr		0xFFC14C24
#define MCU_mProtStatus1_Addr		0xFFC14B24
#define MCU_mProtCmdJ_Addr		0xFFC204C0
#define MCU_mProtStatusJ_Addr		0xFFC204B0

typedef volatile struct
{
	uint32 Commond;/*0x00*/
	uint32 Status;/*0x04*/
}  MCU_tstProtect_Unit;


typedef volatile struct
{
	uint32 Commond;	/*0x00*/
}MCU_tstPortProtectCMD_Unit;

typedef volatile struct
{
	uint32 Status;	/*0x00*/
}MCU_tstPortProtectStatus_Unit;


/***********************************************************
clock controller register protrct unit and block register map!!
************************************************************/
#define MCU_mProtect_AWO_Addr	0xFFF80000
#define MCU_mProtect_ISO_Addr		0xFFF88000


/***********************************************************
PLL unit and block register map!!
************************************************************/
#define MUC_mPLL0_BasicAddr	0xFFF89000
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
	uint32 Fill;/*0x10*/
	uint32 Fill1;/*0x14*/
	uint32 StopMask;/*0x18*/
	uint32 Fill2[(0x100-0x1c)/sizeof(uint32)];/*Fill in unit size to 0x100 byte*/

}  MCU_stExternalOsc_Unit;

typedef volatile struct
{
	MCU_stCLKSelector_Unit CKSC_CPUCLKS;	/*0xFFF8A000*/
	MCU_stCLKDivider_Unit CKSC_CPUCLKD;	/*0xFFF8A100-->use for CPUCLK divider ctrl and status!!*/
	MCU_stCLKSelector_Unit CKSC_IPERI1;		/*0xFFF8A200*/
	MCU_stCLKSelector_Unit CKSC_IPERI2;		/*0xFFF8A300*/
	MCU_stCLKSelector_Unit CKSC_ILINS;		/*0xFFF8A400*/
	MCU_stCLKSelector_Unit CKSC_IADCAS;	/*0xFFF8A500*/
	MCU_stCLKDivider_Unit CKSC_IADCAD;		/*0xFFF8A600-->use for CKSC_IADCA divider ctrl and status!!*/
	MCU_stCLKSelector_Unit Fill;				/*0xFFF8A700*/
	MCU_stCLKDivider_Unit CKSC_ILIND;		/*0xFFF8A800-->use for CKSC_ILIN divider ctrl and status!!*/
	MCU_stCLKSelector_Unit CKSC_ICANS;		/*0xFFF8A900*/
	MCU_stCLKDivider_Unit CKSC_ICANOSCD;	/*0xFFF8AA00-->use for CKSC_ICAN divider ctrl and status if using OSC for CAN clock!!*/
	MCU_stCLKSelector_Unit CKSC_ICSIS;		/*0xFFF8AB00*/
	
}  MCU_tstClkISO_Block;

typedef volatile struct
{
	MCU_stExternalOsc_Unit ROSC;	/*0xFFF81000*/
	MCU_stExternalOsc_Unit MOSC; 	/*0xFFF81100*/
	MCU_stExternalOsc_Unit SOSC; 	/*0xFFF81200*/
	uint32 Fill[(0xFFF82000 -0xFFF81300)/sizeof(uint32) ];
	MCU_stCLKDivider_Unit CKSC_AWDTAD; 	/*0xFFF82000*/
	
	MCU_stCLKSelector_Unit CKSC_ATAUJS; 	/*0xFFF82100*/
	MCU_stCLKDivider_Unit CKSC_ATAUJD; 	/*0xFFF82200*/
	
	MCU_stCLKSelector_Unit CKSC_ARTCAS; 	/*0xFFF82300*/
	MCU_stCLKDivider_Unit CKSC_ARTCAD; 	/*0xFFF82400*/
	
	MCU_stCLKSelector_Unit CKSC_AADCAS; 	/*0xFFF82500*/
	MCU_stCLKDivider_Unit CKSC_AADCAD; 	/*0xFFF82600*/

	MCU_stCLKSelector_Unit CKSC_AFOUTS; 	/*0xFFF82700*/
	MCU_stCLKDivider_Unit CKSC_AFOUTD; 	/*0xFFF82800*/
	
}  MCU_tstClkAWO_Block;



/////////////////////////////////////////////////////////////////////////////

#define MUC_mCLMABlock_BasicAddr 0xFFF8C000

typedef volatile struct
{
	MCU_tstReg_U8 Control;		/*0x00*/
	uint32 Fill1;		/*0x04*/
	MCU_tstReg_U16 CompareH;	/*0x08*/
	MCU_tstReg_U16 CompareL;	/*0x0c*/
	MCU_tstProtect_Unit ProtectUnit;/*0x10 -->0x14*/
	uint32 Filed2[(0x1000-0x18)/sizeof(uint32)]; /*fix to 0x1000 byte size*/
}  MCU_tstClkMonitor_Unit;

typedef volatile struct
{
	MCU_tstClkMonitor_Unit CLMA0_HS;		/*0xFFF8C000*/
	MCU_tstClkMonitor_Unit CLMA1_MainOsc;	/*0xFFF8D000*/
	MCU_tstClkMonitor_Unit CLMA2_CPLLCLK;	/*0xFFF8E000*/
	
}  MCU_tstClkMonitor_Block;

/////////////////////////////////////////////////////////////////////////////
typedef const struct
{
	uint32 MainOsc_StableTime;/*us*/
	uint32 MainOscStopInStandbyMode;
	
	uint32 SubOsc_FTX_Speed;
	uint32 SubOsc_StableTime;/*us*/
	/*uint32 SubOscStopInStandbyMode;*/
	
	uint32 IntOscLS_FRL_Speed;/*240000, can not change*/
	uint32 IntOscHS_FRH_Speed;/*8000000, can not change*/

	uint32 CPLLCLK_Speed;		/*CPU clock from PLL*/
	uint32 MEMCLK_Speed;		/*external memery controller clock from PLL*/

	
	uint32 ClkDiv_C_AWO_WDTAD;/*	00B: Setting prohibited
								01B: LS IntOSC / 128 (default)
								10B: LS IntOSC / 1*/
								
								
	/*uint32 WDTAStopInStandbyMode;*/
	
	uint32 ClkSel_C_AWO_TAUJS;/*	000B: Disabled
								001B: HS IntOSC (default)
								010B: MainOSC
								011B: LS IntOSC
								100B: PPLLLCLK/2*/
								
	uint32 ClkDiv_C_AWO_TAUJD;/*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
	uint32 TAUJStopInStandbyMode;
	
	uint32 ClkSel_C_AWO_RTCAS;/*	00B: Disable (default)
								01B: SubOSC
								10B: MainOSC
								11B: LS IntOSC*/
								
	uint32 ClkDiv_C_AWO_RTCAD;/*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
	uint32 RTCAStopInStandbyMode;
								
	uint32 ClkSel_C_AWO_ADCAS;/*	00B: Disabled
								01B: HS IntOSC (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
	uint32 ClkDiv_C_AWO_ADCAD;/*	001B: X/1 (default)
								010B:  X/2*/
								
	uint32 ADCAStopInStandbyMode;
	
	uint32 ClkSel_C_AWO_FOUT;/*	000B: Disabled (default)
								001B: MainOSC
								010B: HS IntOSC
								011B: LS IntOSC
								100B: SubOSC
								101B: CPLLCLK/2
								110B: PPLLCLK/4*/
								
	uint32 ClkDiv_C_AWO_FOUT;	/*1-->63 divide*/
	
	
	uint32 ClkSel_C_ISO_CPUCLKS;	/*00B: Setting prohibited
								01B: EMCLK (default)
								10B: MainOSC
								11B: CPLLCLK--->we use defalu PLL output < -----*/
								
	uint32 ClkDiv_C_ISO_CPUCLKD;	/*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
								
	uint32 ClkSel_C_ISO_PER1;/*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
	uint32 ClkSel_C_ISO_PER2;/*	00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
	uint32 ClkSel_C_ISO_LINS;/*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
	uint32 ClkDiv_C_ISO_ILIND;/*	001B: X/1 (default)
								010B:  X/4
								011B: X/8*/								
	uint32 LINStopInStandbyMode;
	
	uint32 ClkSel_C_ISO_ADCAS;/*	00B: Disabled
								01B: HS IntOSC RH (8 MHz) (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
	uint32 ClkDiv_C_ISO_ADCAD;/*	001B: X/1 (default)
								010B:  X/2*/
								
	uint32 ClkSel_C_ISO_CANS;/*	00B: Disabled
									01B: MainOSC
									10B: CPLLCLK
									11B: CPUCLK (default)*/
									
	uint32 CANStopInStandbyMode;
	
	uint32 ClkDiv_C_ISO_CANOSCD;/*	00B: Disabled (default)
								01B: MainOSC /1
								10B: MainOSC /2
								11B: Setting prohibited*/
								
	uint32 CANOSCStopInStandbyMode;
	
	uint32 ClkSel_C_ISO_CSIS;/*	00B: Disabled
							01B: CPUCLK (default)
							10B: PPLLCLK*/
							
	uint32 CLMA0enable_HS;		/*CLMA0 monitor unit,sample clock = LS*/
	uint32 CLMA0TolerancePercent;
	
	uint32 CLMA1enable_MainOsc;	/*CLMA1 monitor unit,sample clock = LS*/
	uint32 CLMA1TolerancePercent;
	
	uint32 CLMA2enable_CPLLCLK;	/*CLMA2 monitor unit,sample clock = HS*/
	uint32 CLMA2TolerancePercent;
	
}MCU_tstClockUsrCfg;

typedef struct
{
	
	uint32 MainOsc_Speed;		/*MainOsc*/
	uint32 SubOsc_Speed;		/*external Sub Osc*/
	
	uint32 IntOscLS_FRL_Speed;/*240000, can not change*/
	uint32 IntOscHS_FRH_Speed;/*8000000, can not change*/

	uint32 CPUCLK_Speed;		/*CPU clock from PLL*/
	uint32 PPLLCLK_Speed;		/*perpiler clock from PLL*/
	uint32 CPLLCLK_Speed;		/*PLL clock*/
	
	uint32 EMCLK_Speed;		/*emergency clock*/
	uint32 MEMCLK_Speed;		/*external memery controller clock from PLL*/

	uint32 ClkSpeed_C_AWO_FOUT;
	uint32 ClkSpeed_C_AWO_WDTAD;
	
	uint32 ClkSpeed_C_AWO_TAUJS;/*	000B: Disabled
								001B: HS IntOSC (default)
								010B: MainOSC
								011B: LS IntOSC
								100B: PPLLLCLK/2*/
								
	
	uint32 ClkSpeed_C_AWO_RTCAS;/*	00B: Disable (default)
								01B: SubOSC
								10B: MainOSC
								11B: LS IntOSC*/
								
								
	uint32 ClkSpeed_C_AWO_ADCAS;/*	00B: Disabled
								01B: HS IntOSC (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
	
	/*uint32 ClkSpeed_C_ISO_CPUCLKS;	00B: Setting prohibited
								01B: EMCLK (default)
								10B: MainOSC
								11B: CPLLCLK--->we use defalu PLL output < -----*/
								
								
	uint32 ClkSpeed_C_ISO_PER1;/*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
	uint32 ClkSpeed_C_ISO_PER2;/*	00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
	uint32 ClkSpeed_C_ISO_LINS;/*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
									
	uint32 ClkSpeed_C_ISO_ADCAS;/*	00B: Disabled
								01B: HS IntOSC RH (8 MHz) (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
								
	uint32 ClkSpeed_C_ISO_CANS;/*	00B: Disabled
									01B: MainOSC
									10B: CPLLCLK
									11B: CPUCLK (default)*/
	
	uint32 ClkSpeed_C_ISO_CSIS;/*	00B: Disabled
							01B: CPUCLK (default)
							10B: PPLLCLK*/
								
}MCU_tstClockRunStatus;


		
typedef struct
{
	uint32 MainOsc_Fre;
	uint32 PLL_Fre;
	uint32 Pr;
	uint32 Nr;
	uint32 Mr;
}MCU_tstPLLSettingTbl;

/*****************************************
	clock module Attribute struct 
****************************************/
typedef const struct
{
	MCU_tstClkAWO_Block *  AWOBlock_BasicAddr; 	/*MCU_tstClkAWO_Block*/
	MCU_tstClkISO_Block * ISOBlock_BasicAddr;	/*MCU_tstClkISO_Block*/
	MCU_stPLLCtrl_Unit * PLLCtrl;			/*MCU_stPLLCtrl_Unit*/
	
	MCU_stClkPLL_Unit * PLL0;					/*MCU_stClkPLL_Unit*/
	
	MCU_tstProtect_Unit * Protect_AWO_Addr;	/*MCU_tstProtect_Unit*/
	MCU_tstProtect_Unit * Protect_ISO_Addr;	/*MCU_tstProtect_Unit*/
	MCU_tstClkMonitor_Block *ClockMonitorBlock;		/*MCU_tstClkMonitor_Block*/
	MCU_tstClockUsrCfg * const ClockUsrCfgHead; /*MCU_tstClockUsrCfg*/
	
}MCU_stsClockModlueAttribute;



#define MCU_mLVICNT_BasicAddr	0xFFF80A00
#define MCU_mLVICNT_Protect_BasicAddr	0xFFF80000
#define MCU_mCVM_BasicAddr		0xFFF5000
#define MCU_mCVM_Protect_BasicAddr 0xFFF50100

typedef volatile struct
{
	uint32 CVMFactor;	/*0x00*/
	uint32 CVMDetect;	/*0x04*/
	uint32 Fill1;		/*0x08*/
	uint32 Fill2;		/*0x0C*/
	uint32 Fill3;		/*0x10*/
	uint32 CVMDiag;	/*0x14*/
}MCU_stsCVM_Unit;



typedef const struct
{
	volatile uint32 *LVICNT_Addr;
	MCU_tstProtect_Unit *LVICNT_ProtectAddr;
	MCU_stsCVM_Unit *CVM_Addr;
	MCU_tstProtect_Unit *CVM_ProtectAddr;
}MCU_stsVoltageMonitorModuleAttribute;


///////////////////////////////////////////////////////////////////////////

#if 0
#define MCU_mResetReason_Addr		0xFFF80760
#define MCU_mSoftWareReset_Addr		0xFFF80A04
#define MCU_mSoftWareReset_ProtectAddr		0xFFF80000

typedef volatile struct
{
	uint32 RESFactor;	/*0x00*/
	uint32 Fill;		/*0x04*/
	uint32 RESFClean;	/*0x08*/
}MCU_tstResetReason_Unit;

typedef const struct
{
	MCU_tstResetReason_Unit *ResetReason;		/*0xFFF80760*/
	volatile uint32 * SWRESA_Trigger_Addr;		/*0xFFF80A04*/
	MCU_tstProtect_Unit *SWRESA_ProtectAddr; 	/*0xFFF80000*/
}MCU_tstResetCtrlModuleAttribute;
#endif

///////////////////////////////////////////////////////////////////////////
/********
reset control unit
**********/

//////////////////////////////////////////////////////////////////

#define MCU_mResetCtrl_BaseAddr			0xFFF80760
#define MCU_mMcuResetProtect_BaseAddr			0xFFF80000

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

typedef const  struct
{
	MCU_tstProtect_Unit *McuReset_ProtectAddr; 	/*0xFFF80000*/
	
	MCU_stsResetCtrl_Unit *ResetCtrl;
	
}MCU_tstResetCtrlModuleAttribute;

/*MCU reset control*/
#define MCU_mResetReason_DeepSTOP	(1<<10)
#define MCU_mResetReason_PowerUp		(1<<9)
#define MCU_mResetReason_ExternalReset	(1<<8)
#define MCU_mResetReason_CVM			(1<<7)
#define MCU_mResetReason_LVI			(1<<6)
#define MCU_mResetReason_CLMA2		(1<<5)
#define MCU_mResetReason_CLMA1		(1<<4)
#define MCU_mResetReason_CLMA0		(1<<3)
#define MCU_mResetReason_WDTA1		(1<<2)
#define MCU_mResetReason_WDTA0		(1<<1)
#define MCU_mResetReason_SoftwareRest	(1<<0)

////////////////////////////////////////////////////////////////

/*FE_Level No-maskable interrupt*/
#define MCU_mFE_NMI_BasicAddr		0xFFF80200

#define MCU_mFENMI_ID_TNMIF 		(1<<0)
#define MCU_mFENMI_ID_WDTA0NMIF (1<<2)
#define MCU_mFENMI_ID_WDTA1NMIF (1<<3)

typedef volatile struct
{
	uint32 WDTNMIFlag;	/*0x00*/
	uint32 Fill;			/*0x04*/
	uint32 WDTNMIFClean;	/*0x08*/
}MCU_tstFENMI_SettingBlock;

typedef const struct
{
	vpFun TNMInterrupt;	
	vpFun WDTA0_Isr;			
	vpFun WDTA1_Isr;			
}MCU_tstFENMI_UsrCfg;

/*FE_Level Maskable interrupt*/
#define MCU_mFE_MI_BasicAddr		0xFFF80300

#define MCU_mFEMI_ID_LVIHFEIF 		(1<<15)
#define MCU_mFEMI_ID_OSTM0FEIF 		(1<<14)
#define MCU_mFEMI_ID_ECCRAMFEIF 		(1<<13)
#define MCU_mFEMI_ID_ECCSDFLI0FEIF 	(1<<12)
#define MCU_mFEMI_ID_ECCDCSIH3FEIF 	(1<<10)
#define MCU_mFEMI_ID_ECCDCSIH2FEIF 	(1<<9)
#define MCU_mFEMI_ID_ECCDCSIH1FEIF 	(1<<8)
#define MCU_mFEMI_ID_ECCDCSIH0FEIF 	(1<<7)
#define MCU_mFEMI_ID_ECCDCNRAMFEIF 	(1<<6)
#define MCU_mFEMI_ID_ECCDEEP0FEIF 	(1<<4)
#define MCU_mFEMI_ID_LVILFEIF 		(1<<0)

typedef volatile struct
{
	uint32 FEINTFlag;		/*0x00*/
	uint32 FEINTFMask;		/*0x04*/
	uint32 FEINTFClean;	/*0x08*/
}MCU_tstFEMI_SettingBlock;



/*EI_Level Maskable interrupt*/
#define MCU_mEIC_BasicAddr_Hpro		0xFFFF9000
#define MCU_mEIC_BasicAddr_Lpro		0xFFFFA000	/*0xFFFFA040 = 32 vector , so offset to 0!*/

typedef volatile struct
{
	uint16 PRO : 3;		/*bit 0-2*/
	uint16 Fill4 : 3;		/*bit 3-5*/
	uint16 TB : 1;		/*bit 6*/
	uint16 MK : 1;		/*bit 7*/
	uint16 Fill3 : 4;		/*bit 8-11*/
	uint16 RF : 1;		/*bit 12*/
	uint16 Fill2 : 2;		/*bit 13-14*/
	uint16 CT : 1;		/*bit 15*/
	
}MCU_tstEIAttribute_Unint;


#define MCU_mInerruptSel_BasicAddr	0xFFBC0300
typedef volatile struct
{
	uint32 SELB_INTCtrl1;	/*0x00*/
	uint32 SELB_INTCtrl2;	/*0x04*/
}MCU_tstInterruptSel_Level;

typedef const struct
{
	vpFun LVIL;		/*0*/
	vpFun Reverce1;	/*1*/
	vpFun Reverce2;	/*2*/
	vpFun Reverce3;	/*3*/
	vpFun ECCDEEP0;	/*4*/
	vpFun Reverce5;	/*5*/
	vpFun ECCDCNRAM;	/*6*/
	vpFun ECCDCSIH0;	/*7*/
	vpFun ECCDCSIH1;	/*8*/
	vpFun ECCDCSIH2;	/*9*/
	vpFun ECCDCSIH3;	/*10*/
	vpFun Reverce11;	/*11*/
	vpFun ECCSDFLI0;	/*12*/
	vpFun ECCRAM;	/*13*/
	vpFun OSTM_0;	/*14*/
	vpFun LVIH;		/*15*/	
}MCU_tstFEMI_UsrCfg;

#define MCU_mEIMR_HighPro_BasicAddr		0xFFFF90F0 /*IMR0 for mask interrupt number EIC0 -EIC31*/
#define MCU_mEIMR_LowPro_BasicAddr		0xFFFFA400 /*IMR1~7 for mask interrupt number EIC32 -EIC255*/

typedef  volatile uint32 MCU_vIMRtable;				/*Mask IMR is a bit for each channel*/


#define MCU_mMaxVectorNumber		288 /*Max vector number in this MCU*/
#define MCU_mMaxVectorPrority		8 /*Max vector prority in this MCU*/
#define MCU_mMaxVectorNumber_FE		16 /*Max FE vector number in this MCU*/
#define MCU_mMaxVectorNumber_FENM		3 /*Max FE No-Mask vector number in this MCU*/


typedef const struct
{
	/*system error type, can not control by user, it run interrupt function directely-----*/

	
	/*FENMI error type, can not control by user but can run user function-----*/
	MCU_tstFENMI_SettingBlock *FENMI;			/*0xFFF80200*/
	MCU_tstFENMI_UsrCfg * FENMI_Cfg;
	
	/*FEMI error type, can not control by user but can run user function-----*/
	MCU_tstFEMI_SettingBlock *FEMI;				/*0xFFF80300*/
	MCU_tstFEMI_UsrCfg * FEMI_Cfg;
	#if 0
	const uint32 *INTSourceSel;
	#endif
	uint32 MaxSourceSelect;
	
	/*Normal interrupt type, control by user and can run user function-----*/
	MCU_tstInterruptSel_Level * SELB_INTC;		/*0xFFBC0300*/
	MCU_tstEIAttribute_Unint *EICtrl_Hpro ;	/*0xFFFF9000, control 0-31 interrupts, 
												control the MKxx IFxx TBxx etc*/
	MCU_tstEIAttribute_Unint *EICtrl_Lpro ;	/*0xFFFFA040, 32 to more then 250 interrupts, 
												control the MKxx IFxx TBxx etc*/
										
	MCU_vIMRtable *IMR_Hprority;	/*0xFFFF90F0 --> same effict with MKxx, so do not care it*/
	MCU_vIMRtable *IMR_Lprority;	/*0xFFFFA400 --> same effict with MKxx, so do not care it*/

	uint32 MaxVectorNumber;	/*MCU_mMaxVectorNumber*/
	uint32 MaxVectorNumber_FE;	/*MCU_mMaxVectorNumber*/
}MCU_tstInterruptModuleAttribute;


//////////////////////////////////////////////////////////////////////////////////

/******************
Standby Control unit
********************/
#define MCU_mStanbyCtrl_BaseAddr	0xFFF80100
#define MCU_mStanbyCtrl_protect_Addr 0xFFF80000

typedef volatile struct
{
	uint32 PSC;								/*0x100*/
	uint32 Fill1[(0x110-0x104)/sizeof(uint32)];		/*0x110 - 0x104*/
	uint32 STPT;								/*0x110*/
	uint32 Fill2[(0x400-0x114)/sizeof(uint32)];		/*0x110 - 0x04*/
	uint32 WUF_0;								/*0x400*/
	uint32 WUFMSK_0;							/*0x404*/
	uint32 WUFC_0;							/*0x408*/
	uint32 Fill3[(0x520-0x40C)/sizeof(uint32)];		/*0x520 - 0x40C*/
	uint32 WUF_20;							/*0x520*/
	uint32 WUFMSK_20;						/*0x524*/
	uint32 WUFC_20;							/*0x528*/
	uint32 Fill4[(0xB00-0x52C)/sizeof(uint32)];		/*0xB00 - 0x52C*/
	uint32 IoHold;								/*0xB00*/
	uint32 Fill5[(0x8110-0xB04)/sizeof(uint32)];		/*0x8110 - 0xB04*/
	uint32 WUF_Iso0;							/*0x8110*/
	uint32 WUFMSK_Iso0;						/*0x8114*/
	uint32 WUFC_Iso0;							/*0x8118*/
}MCU_tstSTBC_Unit;

/********************************************
	######wake up factor 1  ########
*********************************************/
typedef const struct
{
	uint32	TNMI	 : 1;		/* wake factor		@	WUF0[0] 	*/
	uint32	WDTA0NMI	 : 1;	/* wake factor		@	WUF0[1] 	*/
	uint32	INTLVIL 	 : 1;		/* wake factor		@	WUF0[2] 	*/
	uint32	Fill0		 : 1;		/*						WUF0[3] */
	uint32	Fill1		 : 1;		/*						WUF0[4] */
	uint32	INTP0	 : 1;		/* wake factor		@	WUF0[5] 	*/
	uint32	INTP1	 : 1;		/* wake factor		@	WUF0[6] 	*/
	uint32	INTP2	 : 1;		/* wake factor		@	WUF0[7] 	*/
	uint32	INTWDTA0	 : 1;	/* wake factor		@	WUF0[8] 	*/
	uint32	INTP3	 : 1;		/* wake factor		@	WUF0[9] 	*/
	uint32	INTP4	 : 1;		/* wake factor		@	WUF0[10]	*/
	uint32	INTP5	 : 1;		/* wake factor		@	WUF0[11]	*/
	uint32	INTP10	 : 1;		/* wake factor		@	WUF0[12]	*/
	uint32	INTP11	 : 1;		/* wake factor		@	WUF0[13]	*/
	uint32	WUTRG1	 : 1;		/* wake factor		@	WUF0[14]	*/
	uint32	INTTAUJ0I0	 : 1;	/* wake factor		@	WUF0[15]	*/
	uint32	INTTAUJ0I1	 : 1;	/* wake factor		@	WUF0[16]	*/
	uint32	INTTAUJ0I2	 : 1;	/* wake factor		@	WUF0[17]	*/
	uint32	INTTAUJ0I3	 : 1;	/* wake factor		@	WUF0[18]	*/
	uint32	WUTRG0	 : 1;		/* wake factor		@	WUF0[19]	*/
	uint32	INTP6	 : 1;		/* wake factor		@	WUF0[20]	*/
	uint32	INTP7	 : 1;		/* wake factor		@	WUF0[21]	*/
	uint32	INTP8	 : 1;		/* wake factor		@	WUF0[22]	*/
	uint32	INTP12	 : 1;		/* wake factor		@	WUF0[23]	*/
	uint32	INTP9	 : 1;		/* wake factor		@	WUF0[24]	*/
	uint32	INTP13	 : 1;		/* wake factor		@	WUF0[25]	*/
	uint32	INTP14	 : 1;		/* wake factor		@	WUF0[26]	*/
	uint32	INTP15	 : 1;		/* wake factor		@	WUF0[27]	*/
	uint32	INTRTCA01S	 : 1;	/* wake factor		@	WUF0[28]	*/
	uint32	INTRTCA0AL	 : 1;	/* wake factor		@	WUF0[29]	*/
	uint32	INTRTCA0R	 : 1;	/* wake factor		@	WUF0[30]	*/
	uint32	INTDCUTDI	 : 1;	/* wake factor		@	WUF0[31]	*/

}MCU_tstWakeUpFactorEnable_WU0;

typedef const struct
{	
	uint32		Fill0		 		:1;  /*				WUF_ISO0 [0]	*/
	uint32		INTKR0			:1; /* wakeup factor   @	WUF_ISO0 [1]	*/
	uint32		INTRCANGRECC	:1; /* wakeup factor   @	WUF_ISO0 [2]	*/
	uint32		INTRCAN0REC 	:1; /* wakeup factor   @	WUF_ISO0 [3]	*/
	uint32		INTRCAN1REC 	:1; /* wakeup factor   @	WUF_ISO0 [4]	*/
	uint32		INTRCAN2REC 	:1; /* wakeup factor   @	WUF_ISO0 [5]	*/
	uint32		INTRCAN3REC 	:1; /* wakeup factor   @	WUF_ISO0 [6]	*/
	uint32		INTRCAN4REC 	:1; /* wakeup factor   @	WUF_ISO0 [7]	*/
	uint32		INTRCAN5REC 	:1; /* wakeup factor   @	WUF_ISO0 [8]	*/
	uint32		Fill1	:23;	 		     /* wakeup factor   @	WUF20[9 -31]*/
}MCU_tstWakeUpFactorEnable_ISO;


/********************************************
	######wake up factor 2  ########
*********************************************/

typedef const struct
{
	uint32		INTADCA0I0	:1; /* wakeup factor   @	WUF20[0]	*/
	uint32		INTADCA0I1	:1; /* wakeup factor   @	WUF20[1]	*/
	uint32		INTADCA0I2	:1; /* wakeup factor   @	WUF20[2]	*/
	uint32		INTRLIN30	:1; /* wakeup factor   @	WUF20[3]	*/
	uint32		INTTAUJ0I0	:1; /* wakeup factor   @	WUF20[4]	*/
	uint32		INTTAUJ0I1	:1; /* wakeup factor   @	WUF20[5]	*/
	uint32		INTTAUJ0I2	:1; /* wakeup factor   @	WUF20[6]	*/
	uint32		INTTAUJ0I3	:1; /* wakeup factor   @	WUF20[7]	*/
	uint32		INTRLIN31	:1; /* wakeup factor   @	WUF20[8]	*/
	uint32		INTRLIN32	:1; /* wakeup factor   @	WUF20[9]	*/
	uint32		INTRTCA01S	:1; /* wakeup factor   @	WUF20[10]	*/
	uint32		INTRTCA0AL	:1; /* wakeup factor   @	WUF20[11]	*/
	uint32		INTRTCA0R	:1; /* wakeup factor   @	WUF20[12]	*/
	uint32		INTRLIN33	:1; /* wakeup factor   @	WUF20[13]	*/
	uint32		INTRLIN34	:1; /* wakeup factor   @	WUF20[14]	*/
	uint32		INTRLIN35	:1; /* wakeup factor   @	WUF20[15]	*/
	uint32		Fill0	:16; 		     /* wakeup factor   @	WUF20[16-31]*/
}MCU_tstWakeUpFactorEnable_WU20;


typedef const struct
{
	MCU_tstWakeUpFactorEnable_WU0 WakeUpEnable_WU1;/*factor 1*/
	MCU_tstWakeUpFactorEnable_ISO WakeUpEnable_ISO0;
	
	MCU_tstWakeUpFactorEnable_WU20 WakeUpEnable_WU20;/*factor 2*/
}MCU_tstSTBC_UsrCfg;

typedef const struct
{
	MCU_tstSTBC_Unit *STBC;
	MCU_tstProtect_Unit *ProtectAddr;
	MCU_tstSTBC_UsrCfg *STBC_UsrCfg;	
}MCU_tstSTBCModuleAttribute;



/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		Port setting   mapping
		@@@@@@@@@@		  
####################################################*/
	
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
		MCU_tstReg_U16 P[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*MCU_mPortBaseAddr + 0x000*/
		uint32 PSR[MCU_mPortShift/sizeof(uint32)];							/*+ 0x100*/
		MCU_tstReg_U16 PPR[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x200*/
		MCU_tstReg_U16 PM[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x300*/
		MCU_tstReg_U16 PMC[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x400*/
		MCU_tstReg_U16 PFC[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x500*/
		MCU_tstReg_U16 PFCE[MCU_mPortShift/sizeof(MCU_tstReg_U16)]; /*+ 0x600*/
		MCU_tstReg_U16 PNOT[MCU_mPortShift/sizeof(MCU_tstReg_U16)]; /*+ 0x700*/
		uint32 PMSR[MCU_mPortShift/sizeof(uint32)]; 						/*+ 0x800*/
		uint32 PMCSR[MCU_mPortShift/sizeof(uint32)];							/*+ 0x900*/
		MCU_tstReg_U16 PFCAE[MCU_mPortShift/sizeof(MCU_tstReg_U16)];	/*+ 0xA00*/
	
		uint32 Fill[(0x4000-0xB00)/sizeof(uint32)]; /*Fill data*/
		MCU_tstReg_U16 PIBC[MCU_mPortShift/sizeof(MCU_tstReg_U16)]; /*MCU_mPortBaseAddr + 0x4000*/
		MCU_tstReg_U16 PBDC[MCU_mPortShift/sizeof(MCU_tstReg_U16)]; /*+ 0x4100*/
		MCU_tstReg_U16 PIPC[MCU_mPortShift/sizeof(MCU_tstReg_U16)]; /*+ 0x4200*/
		MCU_tstReg_U16 PU[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x4300*/
		MCU_tstReg_U16 PD[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x4400*/
		uint32 PODC[MCU_mPortShift/sizeof(uint32)]; 						/*+ 0x4500*/
		uint32 PDSC[MCU_mPortShift/sizeof(uint32)]; 						/*+ 0x4600*/
		MCU_tstReg_U16 PIS[MCU_mPortShift/sizeof(MCU_tstReg_U16)];		/*+ 0x4700*/
		uint32 Fill2[(0x4B00 -( 0x4700+ MCU_mPortShift ))/sizeof(uint32)];
		MCU_tstReg_U16 PPROTS[MCU_mPortShift/sizeof(MCU_tstReg_U16)];	/*+ 0x4B00*/
		MCU_tstReg_U16 PPCMD[MCU_mPortShift/sizeof(MCU_tstReg_U16)];	/*+ 0x4C00*/
	}MCU_stsPinStruct_Port;
	
	
	
	/*****************************************
		J-Port struct 
	****************************************/
	typedef volatile struct
	{
		MCU_tstReg_U8 JP[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];			/*MCU_mJPortBaseAddr + 0x000*/
		uint32 JPSR[MCU_mJPortShift/sizeof(uint32)];									/*+ 0x10*/
		MCU_tstReg_U8 JPPR[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];		/*+ 0x20*/
		MCU_tstReg_U8 JPM[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];		/*+ 0x30*/
		MCU_tstReg_U8 JPMC[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];		/*+ 0x40*/
		MCU_tstReg_U8 JPFC[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];		/*+ 0x50*/
		uint32 /*JPFCE*/Fill1[MCU_mJPortShift/sizeof(uint32)];							/*+ 0x60*/
		MCU_tstReg_U8 JPNOT[MCU_mJPortShift/sizeof(MCU_tstReg_U8)]; 	/*+ 0x70*/
		uint32 JPMSR[MCU_mJPortShift/sizeof(uint32)];									/*+ 0x80*/
		uint32 JPMCSR[MCU_mJPortShift/sizeof(uint32)];								/*+ 0x90*/
		uint32 Fill2[(0x400-0xA0)/sizeof(uint32)];										/*+ 0xA0*/
	
		MCU_tstReg_U8 JPIBC[MCU_mJPortShift/sizeof(MCU_tstReg_U8)]; 	/*MCU_mJPortBaseAddr + 0x400*/
		MCU_tstReg_U8 JPBDC[MCU_mJPortShift/sizeof(MCU_tstReg_U8)]; 	/*+ 0x410*/
		uint32 /*JPIPC*/Fill4[MCU_mJPortShift/sizeof(uint32)];							/*+ 0x420*/
		MCU_tstReg_U8 JPU[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];			/*+ 0x430*/
		MCU_tstReg_U8 JPD[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];			/*+ 0x440*/
		uint32 JPODC[MCU_mJPortShift/sizeof(MCU_tstReg_U8)]; 	/*+ 0x450*/
		uint32 /*JPDSC*/Fill5[MCU_mJPortShift/sizeof(uint32)];							/*+ 0x460*/
		uint32 /*JPIS*/Fill6[MCU_mJPortShift/sizeof(uint32)];							/*+ 0x470*/
		uint32 Fill7[(0x4B0 -( 0x470+ MCU_mJPortShift ))/sizeof(MCU_tstReg_U8)];
		MCU_tstReg_U8 JPPROTS[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];	/*+ 0x4B0*/
		MCU_tstReg_U8 JPPCMD[MCU_mJPortShift/sizeof(MCU_tstReg_U8)];		/*+ 0x4C0*/
	}MCU_stsPinStruct_JPort;
	
	
	/*****************************************
		A-Port struct 
	****************************************/
	typedef volatile struct
	{
		MCU_tstReg_U16 AP[MCU_mAPortShift/sizeof(MCU_tstReg_U16)];		/*MCU_mAPortBaseAddr + 0x000*/
		uint32 APSR[MCU_mAPortShift/sizeof(uint32)];										/*+ 0x100*/
		MCU_tstReg_U16 APPR[MCU_mAPortShift/sizeof(MCU_tstReg_U16)];				/*+ 0x200*/
		MCU_tstReg_U16 APM[MCU_mAPortShift/sizeof(MCU_tstReg_U16)]; 			/*+ 0x300*/
		uint32 /*APMC*/Fill1[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x400*/
		uint32 /*APFC*/Fill2[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x500*/
		uint32 /*APFCE*/Fill3[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x600*/
		MCU_tstReg_U16 APNOT[MCU_mAPortShift/sizeof(MCU_tstReg_U16)];				/*+ 0x700*/
		uint32 APMSR[MCU_mAPortShift/sizeof(uint32)];									/*+ 0x800*/
		uint32 /*APMCSR*/Fill4[MCU_mAPortShift/sizeof(uint32)]; 						/*+ 0x900*/
		uint32 /*APFCAE*/Fill5[MCU_mAPortShift/sizeof(uint32)]; 							/*+ 0xA00*/
		uint32 Fill6[(0x4000-0xB00)/sizeof(uint32)];											
	
		MCU_tstReg_U16 APIBC[MCU_mAPortShift/sizeof(MCU_tstReg_U16)];	/*MCU_mAPortBaseAddr + 0x4000*/
		MCU_tstReg_U16 APBDC[MCU_mAPortShift/sizeof(MCU_tstReg_U16)];				/*+ 0x4100*/
		uint32 /*APIPC*/Fill7[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x4200*/
		uint32 /*APU*/Fill8[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x4300*/
		uint32 /*APD*/Fill9[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x4400*/
		uint32 /*APODC*/Fill10[MCU_mAPortShift/sizeof(uint32)]; 						/*+ 0x4500*/
		uint32 /*APDSC*/Fill11[MCU_mAPortShift/sizeof(uint32)]; 							/*+ 0x4600*/
		uint32 /*APIS*/Fill12[MCU_mAPortShift/sizeof(uint32)];								/*+ 0x4700*/
		uint32 Fill13[(0x4B00 -( 0x4700+ MCU_mAPortShift ))/sizeof(uint32)];
		uint32 /* APPROTS*/Fill14[MCU_mAPortShift/sizeof(uint32)];							/*+ 0x4B00*/
		uint32 /*APPCMD*/Fill15[MCU_mAPortShift/sizeof(uint32)];							/*+ 0x4C00*/
	
	}MCU_stsPinStruct_APort;
	
	
	/*****************************************
		I-Port struct 
	****************************************/
	typedef volatile struct
	{
		uint32 /*IP*/Fill1[MCU_mIPortShift/sizeof(uint32)]; 	/*MCU_mAPortBaseAddr + 0x000*/
		uint32 /*IPSR*/Fill2[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x100*/
		MCU_tstReg_U16 IPPR[MCU_mIPortShift/sizeof(MCU_tstReg_U16)];	/*+ 0x200*/
		uint32 /*IPM*/Fill3[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x300*/
		uint32 /*IPMC*/Fill4[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x400*/
		uint32 /*IPFC*/Fill5[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x500*/
		uint32 /*IPFCE*/Fill6[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x600*/
		uint32 /*IPNOT*/Fill7[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x700*/
		uint32 /*IPMSR*/Fill8[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x800*/
		uint32 /*IPMCSR*/Fill9[MCU_mIPortShift/sizeof(uint32)]; 				/*+ 0x900*/
		uint32 /*IPFCAE*/Fill10[MCU_mIPortShift/sizeof(uint32)];					/*+ 0xA00*/
	
		uint32 Fill11[(0x4000-0xB00)/sizeof(uint32)];				
		MCU_tstReg_U16 IPIBC[MCU_mIPortShift/sizeof(MCU_tstReg_U16)];/*MCU_mAPortBaseAddr + 0x4000*/
		uint32 /*IPBDC*/Fill12[MCU_mIPortShift/sizeof(uint32)]; 				/*+ 0x4100*/
		uint32 /*IPIPC*/Fill13[MCU_mIPortShift/sizeof(uint32)]; 				/*+ 0x4200*/
		uint32 /*IPU*/Fill14[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x4300*/
		uint32 /*IPD*/Fill15[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x4400*/
		uint32 /*IPODC*/Fill16[MCU_mIPortShift/sizeof(uint32)]; 				/*+ 0x4500*/
		uint32 /*IPDSC*/Fill17[MCU_mIPortShift/sizeof(uint32)]; 				/*+ 0x4600*/
		uint32 /*IPIS*/Fill18[MCU_mIPortShift/sizeof(uint32)];					/*+ 0x4700*/
		uint32 Fill19[(0x4B00 -( 0x4700+ MCU_mIPortShift ))/sizeof(uint32)];
		uint32 /* APPROTS*/Fill20[MCU_mIPortShift/sizeof(uint32)];				/*+ 0x4B00*/
		uint32 /*IPPCMD*/Fill21[MCU_mIPortShift/sizeof(uint32)];				/*+ 0x4C00*/
	
	}MCU_stsPinStruct_IPort;
	
	
	/*****************************************
		Port Attribute struct 
	****************************************/
	typedef const struct
	{
		
		MCU_tstPortProtectCMD_Unit * PODCProtectCMD[3];
		MCU_tstPortProtectStatus_Unit *PODCProtectStatus[3];
				
		/*Port*/
		uint32 TottalPortNumber_Port;
		MCU_stsPinStruct_Port *PortAddr;
		MCU_tstPinCfg * const PinCfgHead_Port; 
	
		/*APort*/
		uint32 TottalPortNumber_APort;
		MCU_stsPinStruct_APort *APortAddr;
		MCU_tstPinCfg * const PinCfgHead_APort; 
	
		/*JPort*/
		uint32 TottalPortNumber_JPort;
		MCU_stsPinStruct_JPort *JPortAddr;
		MCU_tstPinCfg * const PinCfgHead_JPort; 
	
		/*IPort*/
		uint32 TottalPortNumber_IPort;
		MCU_stsPinStruct_IPort *IPortAddr;
		MCU_tstPinCfg * const PinCfgHead_IPort; 
		
	}MCU_stsPortAttribute;
	
	
	

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		OSTM setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mOSTM_BasicAddr	0xFFEC0000
#define MCU_mOSTM_Mun	1
#define MCU_mOSTM_IRQNum	MCU_mISR_76_ICOSTM0

typedef volatile struct
{
	uint32 CMP;			/*0x00*/
	uint32 CNT;			/*0x04*/
	uint32 Fill1;			/*0x08*/
	uint32 Fill2;			/*0x0C*/
	MCU_tstReg_U8 TE;	/*0x10*/
	MCU_tstReg_U8 TS;	/*0x14*/
	MCU_tstReg_U8 TT;	/*0x18*/
	uint32 Fill3;	/*0x1C*/
	MCU_tstReg_U8 CTL;	/*0x20*/
	MCU_tstReg_U8 EMU;	/*0x24*/
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
@@@@@@@@@@@@@@@@@		PWGAsetting   mapping
		@@@@@@@@@@		  
####################################################*/

#define MCU_mPWBA_BasicAddr	0xFFE72800
#define MCU_mPWGA_BasicAddr	0xFFE71000
#define MCU_mPWSA_BasicAddr	0xFFE70000
#define MCU_mSLPWGA_BasicAddr	0xFFBC1000
#define MCU_mPWBA_MaxChannel	4
#define MCU_mPWSA_MaxTrigGroup	8
#define MCU_mPWGA_MaxChannel		72

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
	uint32 Fill6;			/*0x18*/
	uint32 Fill7;			/*0x1C*/
	MCU_tstReg_U8 CTL;	/*0x20*/
	MCU_tstReg_U16 CSBR;	/*0x24*/
	MCU_tstReg_U16 CRBR;	/*0x28*/
	MCU_tstReg_U16 CTBR;	/*0x2C*/
	uint32 Fill3[(0x40-0x30)/sizeof(uint32)];/*fix to size 0x40*/
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
#define MCU_mTAUB_Unit	2
#define MCU_mTAUB0_Channel	16
#define MCU_mTAUB0_BasicAddr	0xFFE30000
#define MCU_mTAUB1_Channel	16
#define MCU_mTAUB1_BasicAddr	0xFFE31000

#define MCU_mTAUD_Unit	1
#define MCU_mTAUD0_Channel	16
#define MCU_mTAUD0_BasicAddr	0xFFE20000

#define MCU_mTAUBD_MaxID	MCU_mTAUD0_15

#define MCU_mTAUJ_Unit	2
#define MCU_mTAUJ0_Channel	4
#define MCU_mTAUJ0_BasicAddr	0xFFE50000
#define MCU_mTAUJ1_Channel	4
#define MCU_mTAUJ1_BasicAddr	0xFFE51000

typedef volatile struct
{
	MCU_tstReg_U16 CDR[MCU_mTAUB0_Channel];	/*0x00-0x40*/
	MCU_tstReg_U16 TOL;					/*0x40*/
	MCU_tstReg_U16 RDT;					/*0x44*/
	MCU_tstReg_U16 RSF;					/*0x48*/
	uint32 Filed1;					/*0x4C*/
	uint32 Filed2;					/*0x50*/
	MCU_tstReg_U16 TDL;					/*0x54*/
	MCU_tstReg_U16 TO;					/*0x58*/
	MCU_tstReg_U16 TOE;					/*0x5C*/
	uint32 Filed3[(0x80-0x60)/sizeof(uint32)];	/*0x60-0x80*/
	MCU_tstReg_U16 CNT[MCU_mTAUB0_Channel];		/*0x80-0xC0*/
	MCU_tstReg_U8 CMUR[MCU_mTAUB0_Channel];		/*0xC0-0x100*/
	uint32 Filed4[(0x140-0x100)/sizeof(uint32)];/*0x100-0x140*/
	MCU_tstReg_U16 CSR[MCU_mTAUB0_Channel];		/*0x140-0x180*/
	MCU_tstReg_U16 CSC[MCU_mTAUB0_Channel];		/*0x180-0x1C0*/
	MCU_tstReg_U16 TE;					/*0x1C0*/
	MCU_tstReg_U16 TS;					/*0x1C4*/
	MCU_tstReg_U16 TT;					/*0x1C8*/
	uint32 Filed5[(0x200-0x1CC)/sizeof(uint32)];/*0x1CC-0x200*/
	MCU_tstReg_U16 CMOR[MCU_mTAUB0_Channel];		/*0x200-0x240*/
	MCU_tstReg_U16 TPS;					/*0x240*/
	uint32 Filed6;					/*0x244*/
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


typedef const struct
{
	MCU_tstTAUBD_Unit *TAUBD[MCU_mTAUB_Unit+MCU_mTAUD_Unit];
	MCU_tstTAUJ_Unit *TAUJ[MCU_mTAUJ_Unit];
	uint32 VectList[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit];
	uint32 TimerAltFun[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit];
	MCU_tstTAUx_RegisterValue *TAUx_RegVal;
	uint32 (*TAUxClkDiv_Cfg)[4];
	MCU_tstDNFA_Unit *DNFA[MCU_mTAUB_Unit+MCU_mTAUD_Unit];/*Only TAUB/TAUD has NDFA register*/
	MCU_tstTAUx_UsrCfg *TAUx_Cfg;
}MCU_tstTAUxModuleAttribute;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RIIC setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mRIIC_Unit	1
#define MCU_mRIIC_BasicAddr	0xFFCA0000U

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


typedef const struct
{
	MCU_tstRIIC_Unit *RIIC;
	struct{
		MCU_enIsrID BufferEmptyVect;
		MCU_enIsrID SendFinshVect;
		MCU_enIsrID ReceiveVect;
		MCU_enIsrID ErrorVect;
	}VectList[MCU_mRIIC_Unit];
	
	MCU_tstRIIC_UsrCfg *RIIC_UsrCfg;
}MCU_tstRIICModuleAttribute;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		DMA setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mDMA_MaxChn	16
#define MCU_mDMA_BasicAddr	0xFFFF8300U

typedef volatile struct 
{
	uint32 DSA;							/*0x14*/
	uint32 Fill2[(0x24-0x18)/sizeof(uint32)];	/*0x24--0x18*/
	uint32 DDA;							/*0x24*/
	uint32 Fill3[(0x30-0x28)/sizeof(uint32)];	/*0x30--0x28*/
	uint16 Fill4;							/*0x30*/	
	uint16 DTC;							/*0x32*/
	uint32 Fill5[(0x38-0x34)/sizeof(uint32)];	/*0x34--0x38*/
	uint16 DTCT;							/*0x38*/
	uint16 DTS;							/*0x3A--byte*/
	uint32 Fill6[(0x30 + 0x14 -0x3c)/sizeof(uint32)];	/*fix to 0x30 size*/
	
}DMA_Channel;

typedef volatile struct 
{
	MCU_tstReg_U8 DTRC;								/*0x00*/
	MCU_tstReg_U16 DMCM;							/*0x04*/
	uint32 Fill1[(0x14-0x08)/sizeof(uint32)];				/*0x14--0x08*/
	DMA_Channel DMA_0_7[MCU_mDMA_MaxChn/2];		/*0x30 * 8 +0x14*/
	uint32 Fill6[(0x94-0x14)/sizeof(uint32)];				/*0x30 * 8 +0x94*/
	DMA_Channel DMA_8_15[MCU_mDMA_MaxChn/2];		/*0x30 * 16 +0x94*/
	uint32 Fill7[(0x800 - (0x14 + 0x80 + 0x30 * 16))/sizeof(uint32)];	/*0x800*/
	uint16 DTFR[MCU_mDMA_MaxChn];					/*0x800-0x820*/
	uint32 Fill8[(0x840-0x820)/sizeof(uint32)];				/*0x840-0x820*/
	uint32 DRQClear;									/*0x840*/
	uint32 DRQSTRequest;								/*0x844*/
}MCU_tstDMA_Unit;



/*########################################################
	DMA channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef const struct 
{
	uint32 u32SourceAddr;
	uint32 u32DestAddr;
	uint16 u16AddrChgType;
	uint16 u16DataUnitSize;		/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataLenth;		/*how many byte data to transfer*/
	uint16 u16InterruptTrigID;

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
	uint32 u32DMAChannel;
	uint32 u32SourceAddr;
	uint32 u32DestAddr;
	uint16 u16AddrChgType;
	uint16 u16DataUnitSize;		/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataLenth;		/*how many byte data to transfer*/
	uint16 u16InterruptTrigID;

	vpFun	vpINTservice;		/*interrupt function when DMA finish!*/
}MCU_tstDMA_SetUp;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		EINT setting   mapping
		@@@@@@@@@@		  
####################################################*/

/********************************
trigger for input pins configuration unit
*********************************/
#define MCU_mPinTrigModuleNum		

typedef volatile struct
{
	MCU_tstReg_U8 DNFA_CTL;	/*pin noise control*/
	MCU_tstReg_U16 DNFA_EN;	/*pin noise elimination control*/	
}MCU_tstPinNoiseCtlUnit;

typedef volatile struct
{	
	MCU_tstReg_U8 FCLA_CTL;/*pin filter control*/
}MCU_tstPinFilterCtlUnit;

#define MCU_mFCLA_BasicAddr	0xFFC34020U
typedef volatile struct
{
	uint32 CTL[16]; 		/*0x00*/
}MCU_tstFCLA_Unit;

#define MCU_mMaxEINTchannelMount	16
typedef const struct 
{
	uint16 u16DetectCondition;
	uint16 u16RunWhenReset;
	vpFun	vpINTservice;		/*interrupt function when DMA finish!*/
}MCU_tstEINT_UsrCfg;


typedef const struct
{
	MCU_tstFCLA_Unit *FCLA;
	MCU_enIsrID u16EINTvectList[MCU_mMaxEINTchannelMount];
	MCU_tstEINT_UsrCfg *EINT_UsrCfg;	
}MCU_tstEINTModuleAttribute;

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		ADC setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mADCAUint_Number		2
#define MCU_mADCA_BasicAddr	0xFFF20000U
#define MCU_mAPM_BasicAddr	0xFFC103C8U

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
	 MCU_tstReg_U8 EMU ;	/* 0x388 */
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
	uint32 u32ADCusingMask_ADCA0_P1;/*channel 0~31*/
	uint32 u32ADCusingMask_ADCA0_P2;/*channel 32~63*/
	
	uint32 u32ADCusingMask_ADCA1_P1;/*channel 0~31*/
	uint32 u32ADCusingMask_ADCA1_P2;/*channel 32~63*/
	
}MCU_tstADCA_UsrCfg;

typedef const struct
{
	MCU_tstADCA_Unit *ADCA;
	volatile uint32 *APM;
	uint32 ChnlNumInUint[MCU_mADCAUint_Number];
	uint16 u16ADCAvectList_SG1_finish[MCU_mADCAUint_Number];
	MCU_tstADCA_UsrCfg *ADCA_UsrCfg;	
}MCU_tstADCAModuleAttribute;


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RLIN3 setting   mapping
		@@@@@@@@@@		  
####################################################*/
#define MCU_mRLIN3Uint_Number		6
#define MCU_mRLIN3_BasicAddr	0xFFCF0000

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
	uint8 Fill3;	/* 0x0F   */
	uint8 LTRC ;	/* 0x10   */
	uint8 LMST ;	/* 0x11   */
	uint8 LST ;	/* 0x12   */
	uint8 LEST ;	/* 0x13   */
	uint8 LDFC ;	/* 0x14   */
	uint8 LIDB ;	/* 0x15   */
	uint8 LCBR ;	/* 0x16   */
	uint8 LUDB[9] ;/* 0x17 --  0x1F */
	uint8 LUOER ;	/* 0x20   */
	uint8 LUOR1 ;	/* 0x21   */
	uint16 Fill4;	/* 0x22   */	
	uint16 LUTDR ;	/* 0x24   */
	uint16 LURDR ;	/* 0x26   */
	uint16 LUWTDR ;	/* 0x28   */
	uint16 Fill5[(0x40-0x2A)/sizeof(uint16)]; /*fix to 0x40 byte size*/
	
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
	vpFun_u8 vu8RecCallBack;			/*recieve data callback*/
	vpFun_u8 vu8ErrCallBack;			/*error call back*/
	
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
#define MCU_mCSIG_BaseAddr	0xFFDB0000ul
#define MCU_mCSIG_MaxChn	2

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
	MCU_enIsrID VectList[MCU_mCSIG_MaxChn][3];
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
#define MCU_mCSIH_BaseAddr	0xFFD80000ul
#define MCU_mCSIH_MaxChn	4

typedef volatile struct
{
	MCU_tstReg_U8 CTL0;	/*0x00*/
	uint32 STR0;			/*0x04*/
	MCU_tstReg_U16 STCR0;/*0x08*/
	uint32 Fill2;			/*0x0C*/
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
	MCU_tstReg_U16 MCTL0;	/*0x1040*/
	uint32 CFG[8];				/*0x1044-->0x1060*/
	uint32 Fill9;				/*0x1064*/
	MCU_tstReg_U16 BRS[4];	/*0x1068*/
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

#if 0
//////////////////////////////////////////////////////////////////////////////////

/********
SVM unit (supply voltage monitor uint)
-------------->done in MCU_stsVoltageMonitorModuleAttribute
**********/

#define MCU_mSVM_BaseAddr	0xFFF50000ul
#define MCU_mSVM_ProtectUnitBaseAddr	0xFFF80000

typedef volatile struct
{
	uint32 CVMFactor;			/*0xFFF50000+0x00*/
	uint32 CVMDEnable;					/*0x04*/
	uint32 Fill0[(0x14-0x08)/sizeof(uint32)];
	uint32 CVMDiag;						/*0x14*/
	uint32 Fill1[(0xFFF80980-0xFFF50018)/sizeof(uint32)];
	uint32 VLVFlag;			/*0xFFF80980+0x00*/
	uint32 Fill2;
	uint32 VLVFClean;						/*0x08*/
	uint32 Fill3[(0xFFF80A00-0xFFF8098c)/sizeof(uint32)];
	uint32 LVICnt;					/*0xFFF80A00*/
}MCU_tstSVM_Unit;

typedef const struct
{
	MCU_tstSVM_Unit *SVM;
	MCU_tstProtect_Unit *ProtectUnit;
}MCU_tstSVMModuleAttribute;
#endif

#endif/*end of this file*/

