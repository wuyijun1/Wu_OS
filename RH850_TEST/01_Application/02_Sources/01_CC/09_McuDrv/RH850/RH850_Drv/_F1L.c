/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L.c
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
| 2016.02.23  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifdef MCU_C

#include "./_RH850.h"


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		system setting   
		@@@@@@@@@@		  
####################################################*/

/*******************************************************************************

PLL_Clk= (OSC x Nr) / (Mr x Pr)

#######
8M_OSC:
#######

			PLL_CLK:	Pr	Nr	Mr	
			--------------------
			80M:		4	40	1	
			--------------------
			64M:		4	32	1	
			--------------------
			40M:		8	40	1	
			--------------------
			30M:		8	30	1	


 #######
16M_OSC:
#######

			PLL_CLK:	Pr	Nr	Mr	
			--------------------
			80M:		4	40	2	
			--------------------
			64M:		4	32	2	
			--------------------
			40M:		8	20	1	
			--------------------
			30M:		16	30	1	

*******************************************************************************/

const MCU_tstPLLSettingTbl MCU_stPLL_CtrlValue[8]=
{
/*8M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr*/
			{MEGA(8),	MEGA(80),		2/*Pr=4*/,	40,	1},	
			{MEGA(8),	MEGA(64),		2/*Pr=4*/,	32,	1},	
			{MEGA(8),	MEGA(40),		4/*Pr=8*/,	40,	1},	
			{MEGA(8),	MEGA(30),		4/*Pr=8*/,	30,	1},	

/*16M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr*/
			{MEGA(16),	MEGA(80),		2/*Pr=4*/,	40,	2},	
			{MEGA(16),	MEGA(64),		2/*Pr=4*/,	32,	2},	
			{MEGA(16),	MEGA(40),		4/*Pr=8*/,	20,	1},	
			{MEGA(16),	MEGA(30),		5/*Pr=16*/,	30,	1},			
};



MCU_stsClockModlueAttribute MCU_stClockAttribute=
{
	(MCU_tstClkAWO_Block *)MUC_mAWOBlock_BasicAddr,/*MCU_stClkAWO_Unit*/
	(MCU_tstClkISO_Block *)MUC_mISOBlock_BasicAddr,/*MCU_stClkISO_Unit*/
	(MCU_stPLLCtrl_Unit *)MUC_mPLLCtrl_BasicAddr,	/*MCU_stPLLCtrl_Unit*/
	
	(MCU_stClkPLL_Unit *)MUC_mPLL0_BasicAddr,/*MCU_stClkPLL_Unit, -->protect is MCU_mProtect_ISO_Addr*/
	(MCU_tstProtect_Unit *)MCU_mProtect_AWO_Addr,/*MCU_tstProtect_Unit*/
	(MCU_tstProtect_Unit *)MCU_mProtect_ISO_Addr,/*MCU_tstProtect_Unit*/
	(MCU_tstClkMonitor_Block *)MUC_mCLMABlock_BasicAddr,/*MCU_tstClkMonitor_Block*/
	&MCU_stClockCfg_F1L,
};


typedef volatile struct
{
	uint32 WDTE;	/*0x00*/
	uint32 EVAC;	/*0x04*/
	uint32 REF;	/*0x08*/
	uint32 MD;	/*0x0C*/
	uint32 Fill[(0x1000-0x10)/sizeof(uint32)];	/*fix to 0x1000 byte size*/
}MCU_tstWatchDog_Unit;

#define MCU_mWatcgDogBlock_BasicAddr	0xFFED0000
typedef struct
{
	MCU_tstWatchDog_Unit WDTA_0;	/*0xFFED0000*/
	MCU_tstWatchDog_Unit WDTA_1;	/*0xFFED1000*/
}MCU_tstWatchDog_Block;



typedef const struct
{
	MCU_tstWatchDog_Block * WDTAbasic_Addr;
}MCU_tstWatchDogModuleAttribute;


MCU_tstWatchDogModuleAttribute MCU_stWatchDogAttribute=
{
	(MCU_tstWatchDog_Block *)MCU_mWatcgDogBlock_BasicAddr,
};

#if (MCU_mLVI_Level !=0u)
MCU_stsVoltageMonitorModuleAttribute MCU_tsVoltageMonitorAttribute=
{
	(volatile uint32 *)MCU_mLVICNT_BasicAddr,
	(MCU_tstProtect_Unit *)MCU_mLVICNT_Protect_BasicAddr,
	(MCU_stsCVM_Unit *)MCU_mCVM_BasicAddr,
	(MCU_tstProtect_Unit *)MCU_mCVM_Protect_BasicAddr,
};
#endif

MCU_tstResetCtrlModuleAttribute MCU_stResetCtrlAttribute=
{
	(MCU_tstProtect_Unit *)MCU_mMcuResetProtect_BaseAddr,
	(MCU_stsResetCtrl_Unit *)MCU_mResetCtrl_BaseAddr,
};

MCU_tstSTBCModuleAttribute MCU_stSTBCAttribute=
{
	(MCU_tstSTBC_Unit *)MCU_mStanbyCtrl_BaseAddr,
	(MCU_tstProtect_Unit *)MCU_mStanbyCtrl_protect_Addr,
	(MCU_tstSTBC_UsrCfg *)&MCU_stSTBCCfg,	
};


#define MCU_mMaxIntSourceSel	23

MCU_tstInterruptModuleAttribute MCU_stInterruptCtrlAttribute=
{
	(MCU_tstFENMI_SettingBlock *)MCU_mFE_NMI_BasicAddr,		/*0xFFF80200*/
	(MCU_tstFENMI_UsrCfg *)&MCU_stFENMICfg,
	
	(MCU_tstFEMI_SettingBlock *)MCU_mFE_MI_BasicAddr,		/*0xFFF80300*/
	(MCU_tstFEMI_UsrCfg *)&MCU_stFEMICfg,
	MCU_mMaxIntSourceSel,
	
	(MCU_tstInterruptSel_Level *) MCU_mInerruptSel_BasicAddr,	/*0xFFBC0300*/
	(MCU_tstEIAttribute_Unint *)MCU_mEIC_BasicAddr_Hpro,			/*0xFFFF9000*/
	(MCU_tstEIAttribute_Unint *)MCU_mEIC_BasicAddr_Lpro,			/*0xFFFFA000 : (32 = 0xFFFFA040)*/
	
	(MCU_vIMRtable *)MCU_mEIMR_HighPro_BasicAddr,		/*0xFFFF90F0 IMR0 for mask interrupt number EIC0 -EIC31*/
	(MCU_vIMRtable *)MCU_mEIMR_LowPro_BasicAddr,		/*0xFFFFA400 IMR1~7 for mask interrupt number EIC32 -EIC255*/

	MCU_mMaxVectorNumber,								/*MCU_mMaxVectorNumber*/
	MCU_mMaxVectorNumber_FE,							/*MCU_mMaxVectorNumber_FE*/
};

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		PORT setting   
		@@@@@@@@@@		  
####################################################*/
extern const MCU_tstPinCfg MCU_stPinUserCfg_Port[MCU_MaxPortMount * MCU_MaxPinPerPort];
extern const MCU_tstPinCfg MCU_stPinUserCfg_JPort[MCU_MaxJPortMount*MCU_MaxPinPerPort];
extern const MCU_tstPinCfg MCU_stPinUserCfg_APort[MCU_MaxAPortMount*MCU_MaxPinPerPort];
extern const MCU_tstPinCfg MCU_stPinUserCfg_IPort[MCU_MaxIPortMount*MCU_MaxPinPerPort];
extern const MCU_tstClockUsrCfg MCU_stClockCfg_F1L;

MCU_stsPortAttribute MCU_stPortAttribute=
{

	{
		(MCU_tstPortProtectCMD_Unit *)MCU_mProtCmd0_Addr,
		(MCU_tstPortProtectCMD_Unit *)MCU_mProtCmd1_Addr,
		(MCU_tstPortProtectCMD_Unit *)MCU_mProtCmdJ_Addr,
	},
	{
		(MCU_tstPortProtectStatus_Unit *)MCU_mProtStatus0_Addr,
		(MCU_tstPortProtectStatus_Unit *)MCU_mProtStatus1_Addr,
		(MCU_tstPortProtectStatus_Unit *)MCU_mProtStatusJ_Addr,
	},
	
	/*Port*/
	MCU_MaxPortMount,			/* TottalPortMount*/
	(MCU_stsPinStruct_Port *)MCU_mPortBaseAddr,		/* BasicCtrlAddr*/
	MCU_stPinUserCfg_Port,				/*MCU_tstPinCfg*/
	
	/*Aport*/
	MCU_MaxAPortMount,			/* TottalPortMount*/
	(MCU_stsPinStruct_APort *)MCU_mAPortBaseAddr,		/* BasicCtrlAddr*/
	MCU_stPinUserCfg_APort,

	/*Jport*/
	MCU_MaxJPortMount,			/* TottalPortMount*/
	(MCU_stsPinStruct_JPort *)MCU_mJPortBaseAddr,		/* BasicCtrlAddr*/
	MCU_stPinUserCfg_JPort,
	
	/*Iport*/
	MCU_MaxIPortMount,			/* TottalPortMount*/
	(MCU_stsPinStruct_IPort *)MCU_mIPortBaseAddr,		/* BasicCtrlAddr*/
	MCU_stPinUserCfg_IPort,
	
};


#if (MCU_mOSTMModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		OSTM setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstOSTMModuleAttribute MCU_stOSTMAttribute=
{
	MCU_mOSTM_IRQNum,
	(MCU_tstOSTM_Unit *)MCU_mOSTM_BasicAddr,
	(MCU_tstOSTM_UsrCfg *)&MCU_stOSTMCfg,

};
#endif

#if (MCU_mPWGAModuleEnable !=0u)
MCU_tstPWGAModuleAttribute MCU_stPWGAAttribute=
{
	(MCU_tstPWBA_Unit *)MCU_mPWBA_BasicAddr,
	(MCU_tstPWGA_Unit *)MCU_mPWGA_BasicAddr,
	(MCU_tstSLPWGA *)MCU_mSLPWGA_BasicAddr,
	(MCU_tstPWSA_Unit *)MCU_mPWSA_BasicAddr,
	&MCU_stPWGACfg,
};
#endif

#if ((MCU_mTAUBDModuleEnable !=0u)||(MCU_mTAUJModuleEnable !=0u))
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		TAUX setting   
		@@@@@@@@@@		  
####################################################*/

#define TimerIO(TOE,TO,TOM,TOC,TOL)	((uint32)((TOE)|\
											((TO)<<1u)|\
											((TOM)<<2u)|\
											((TOC)<<4u)|\
											((TOL)<<5u))\
									)
									
#define SimuReWrite(RDE,RDS,RDM,RDC)	((uint32)((RDE)<<16U)|\
											((RDS)<<17u)|\
											((RDM)<<18u)|\
											((RDC)<<19u)\
									)

MCU_tstTAUx_RegisterValue MCU_stTAUxRegisterValue[TUAx_MaxFun]=
{
/*Timer mode RegVal*/
		{0x0000,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*Pin Trigger Timer mode RegVal*/
		{0x0100,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 0 --> run INT if Edge detect*/
/*FrequencyDivider mode RegVal*/
		{0x1001,TimerIO(0/*1*/,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 0 --> run INT if Edge detect, output enable*/
/*Counter mode RegVal*/
		{0x1006,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*OnePulseOutPut mode RegVal*/
		{0x0114,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseInterval mode RegVal*/
		{0x0144,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
/*PulseWidth mode RegVal*/
		{0x028c,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
/*PulsePosition mode RegVal*/
		{0x0156,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
/*PulseWidthCumulater mode RegVal*/
		{0x025a,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
/*PulseIntervalJudgment mode RegVal*/
		{0x0102,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseWidthJudgment mode RegVal*/
		{0x020e,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseWidthOVcheck mode RegVal*/
		{0x0208,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseWidthCumulaterOVcheck mode RegVal*/
		{0x0218,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseDetectDelayMaster mode RegVal*/
		{0x0801,TimerIO(0,0,0,0,0)|SimuReWrite(1,0,0,0)},
/*PulseDetectDelaySlave mode RegVal*/
		{0x0409,TimerIO(1,0,1,0,0)|SimuReWrite(1,0,0,0)},
/*PpgMaster mode RegVal*/
		{0x0801,TimerIO(0,0,0,0,0)|SimuReWrite(1,0,0,0)},
/*PpgSlave mode RegVal*/
		{0x0409,TimerIO(1,0,1,0,0)|SimuReWrite(0,0,0,0)},

};

MCU_tstTAUxModuleAttribute MCU_stTAUxAttribute=
{
	{
		(MCU_tstTAUBD_Unit *)MCU_mTAUB0_BasicAddr,
		(MCU_tstTAUBD_Unit *)MCU_mTAUB1_BasicAddr,
		(MCU_tstTAUBD_Unit *)MCU_mTAUD0_BasicAddr,
	},
	
	{
		(MCU_tstTAUJ_Unit *)MCU_mTAUJ0_BasicAddr,
		(MCU_tstTAUJ_Unit *)MCU_mTAUJ1_BasicAddr
	},
	
	{	
		MCU_mISR_134_ICTAUB0I0,
		MCU_mISR_248_ICTAUB1I0,
		MCU_mISR_0_ICTAUD0I0_ICCSIH2IC_1,
		MCU_mISR_72_ICTAUJ0I0,
		MCU_mISR_160_ICTAUJ1I0
	},
	
	{	
		0xFFFFFFFF,	/*TAUB0 Alt Fun*/
		0xFFFFFFFF,	/*TAUB1 Alt Fun*/
		0xFFFFFFFF,	/*TAUD0 Alt Fun*/
		0xFFFFFFFF,	/*TAUJ0 Alt Fun*/
		0xFFFFFFFF	/*TAUJ1 Alt Fun*/
	},
	
	MCU_stTAUxRegisterValue,
	MCU_stTAUxClkDivCfg,
	{
		 (MCU_tstDNFA_Unit *)MCU_mDNFA_BasicAddr_TAUB0,	/*group index 0*/
		(MCU_tstDNFA_Unit *) MCU_mDNFA_BasicAddr_TAUB1,	/*group index 1*/
		(MCU_tstDNFA_Unit *) MCU_mDNFA_BasicAddr_TAUD,	/*group index 2*/
	},
	MCU_stTAUXCfg
};
#endif

#if (MCU_mIICModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		IIC setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstRIICModuleAttribute MCU_stRIICAttribute=
{
	(MCU_tstRIIC_Unit *)MCU_mRIIC_BasicAddr,
	{MCU_mISR_68_ICRIIC0TI,MCU_mISR_69_ICRIIC0TEI,MCU_mISR_70_ICRIIC0RI,MCU_mISR_71_ICRIIC0EE},
	&MCU_tstRIICCfg,
	
};
#endif


#if (MCU_mEINTModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		EINT setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstEINTModuleAttribute MCU_stEINTAttribute=
{
	(MCU_tstFCLA_Unit  *)MCU_mFCLA_BasicAddr,
	{
		MCU_mISR_29_ICP0_ICCSIH2IR_1,		MCU_mISR_30_ICP1_ICCSIH2IRE_1,		
		MCU_mISR_31_ICP2_ICCSIH2IJC_1,		MCU_mISR_34_ICP3,
		MCU_mISR_35_ICP4,		MCU_mISR_36_ICP5,		MCU_mISR_120_ICP6,	MCU_mISR_121_ICP7,
		MCU_mISR_122_ICP8,		MCU_mISR_197_ICP9,		MCU_mISR_37_ICP10,	MCU_mISR_38_ICP11,
		MCU_mISR_123_ICP12,		MCU_mISR_198_ICP13,		MCU_mISR_199_ICP14,	MCU_mISR_200_ICP15
	},
	MCU_stEINTCfg,
};
#endif

#if (MCU_mADCModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		ADC setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstADCAModuleAttribute MCU_stADCAAttribute=
{
	(MCU_tstADCA_Unit *)MCU_mADCA_BasicAddr,
	(volatile uint32 *)MCU_mAPM_BasicAddr,
	{36,24},
	{MCU_mISR_10_ICADCA0I0,MCU_mISR_39_ICTAUD0I1},
	&MCU_stADCACfg,
};
#endif

#if (MCU_mDMAModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		DMA setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstDMAModuleAttribute MCU_stDMAAttribute=
{
	(MCU_tstDMA_Unit *)MCU_mDMA_BasicAddr,
	MCU_mISR_52_ICDMA0,
	MCU_stDMACfg,
};
#endif

#if (MCU_mRLIN3UartModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RLIN3 setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstRLIN3ModuleAttribute MCU_stRLIN3Attribute=
{
	(MCU_tstRLIN3_Unit *)MCU_mRLIN3_BasicAddr,
	{
		MCU_mISR_25_ICRLIN30,MCU_mISR_112_ICRLIN31,MCU_mISR_156_ICRLIN32,
		MCU_mISR_220_ICRLIN33,MCU_mISR_224_ICRLIN34,MCU_mISR_228_ICRLIN35,
	},
	MCU_stRLIN3UsrCfg,
};
#endif

#if (MCU_mCSIGModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIG setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstCSIGModuleAttribute MCU_stCSIGAttribute=
{
	(MCU_tstCSIG_Unit *)MCU_mCSIG_BaseAddr,
	{
		/*TX*/								/*RX*/								/*Err*/
		{MCU_mISR_19_ICCSIG0IC_ICCSIH1IRE_1,MCU_mISR_20_ICCSIG0IR_ICCSIH1IJC_1,MCU_mISR_49_ICCSIG0IRE},
		{MCU_mISR_215_ICCSIG1IC,MCU_mISR_216_ICCSIG1IR,MCU_mISR_217_ICCSIG1IRE},
	},
	MCU_tstCSIGCfg,
};
#endif


#if (MCU_mCSIHModuleEnable !=0u)
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIH setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstCSIHModuleAttribute MCU_stCSIHAttribute=
{
	(MCU_tstCSIH_Unit *)MCU_mCSIH_BaseAddr,
	{
		MCU_mISR_21_ICCSIH0IC,
		MCU_mISR_108_ICCSIH1IC_ICTAPA0IPEK0_2,
		MCU_mISR_124_ICCSIH2IC_ICTAUD0I0_2,
		MCU_mISR_150_ICCSIH3IC_ICTAUD0I2_2
	},
	MCU_tstCSIHCfg,
};
#endif



#endif/*end of this file*/

