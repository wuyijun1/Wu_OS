/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1L_D1M.c
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


 
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		system setting   
		@@@@@@@@@@		  
####################################################*/

#define MCU_CLK_UsingDefault	0xFFFFFFFE

const MCU_tstPLLSettingTbl MCU_stPLL_CtrlValue[12]=
{
/*8M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr	FVV	SELMFREQ	SELMPERCENT		SELMPERCENT*/
			{MEGA(8),	MEGA(480),		0/*Pr=1*/,	60,	1,	3,	},// 3,			3,				7},	
			{MEGA(8),	MEGA(400),		0/*Pr=1*/,	50,	1,	1,	},// 3,			3,				7},		
			{MEGA(8),	MEGA(200),		1/*Pr=2*/,	50,	1,	1,	},// 3,			3,				7},		
			{MEGA(8),	MEGA(120),		2/*Pr=4*/,	60,	1,	3,	},// 3,			3,				7},		

/*16M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr	FVV	SELMFREQ	SELMPERCENT		SELMPERCENT*/
			{MEGA(16),	MEGA(480),		0/*Pr=1*/,	30,	1,	3,	},// 3,			3,				7},		
			{MEGA(16),	MEGA(320),		0/*Pr=1*/,	20,	1,	3,	},// 3,			3,				7},		
			{MEGA(16),	MEGA(160),		1/*Pr=2*/,	20,	1,	3,	},// 3,			3,				7},		
			{MEGA(16),	MEGA(80),		2/*Pr=4*/,	20,	1,	3,	},// 3,			3,				7},			

/*the below setting only for PLL1 D1M2H serial MCU*/
/*8M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr	FVV	SELMFREQ	SELMPERCENT		SELMPERCENT*/
			{MEGA(8),	MEGA(960),		0/*Pr=1*/,	120,	1,	3,	},// 3,			3,				7},	
			{MEGA(8),	MEGA(800),		0/*Pr=1*/,	100,	1,	1,	},// 3,			3,				7},		
			//{MEGA(8),	MEGA(640),		0/*Pr=1*/,	80,	1,	0,	},// 3,			3,				7},		


/*16M_OSC*/
			/*OSC		PLL				Pr			Nr	Mr	FVV	SELMFREQ	SELMPERCENT		SELMPERCENT*/
			{MEGA(16),	MEGA(960),		0/*Pr=1*/,	60,	1,	3,	},// 3,			3,				7},	
			{MEGA(16),	MEGA(780),		0/*Pr=1*/,	48,	1,	1,	},// 3,			3,				7},		
};


MCU_stsClockModlueAttribute MCU_stClockAttribute=
{
	(MCU_tstClkAWO_Block *)MUC_mAWOBlock_BasicAddr,/*MCU_stClkAWO_Unit*/
	(MCU_tstClkISO_Block *)MUC_mISOBlock_BasicAddr,/*MCU_stClkISO_Unit*/
	(MCU_tstClkISO_ExtBlock *)MUC_mISOExtBlock_BasicAddr,/*MCU_tstClkISO_ExtBlock*/
	(MCU_stPLLCtrl_Unit *)MUC_mPLLCtrl_BasicAddr,	/*MCU_stPLLCtrl_Unit*/
	
	(MCU_stClkPLL_Unit *)MUC_mPLL0_BasicAddr,/*MCU_stClkPLL_Unit*/
	(MCU_stClkPLL_Unit *)MUC_mPLL1_BasicAddr,/*MCU_stClkPLL_Unit*/
	(MCU_stClkPLL_Unit *)MUC_mPLL2_BasicAddr,/*MCU_stClkPLL_Unit*/
	
	(MCU_tstProtect_Unit *)MCU_mProtect_AWO_Addr,/*MCU_tstProtect_Unit*/
	(MCU_tstProtect_Unit *)MCU_mProtect_ISO_Addr,/*MCU_tstProtect_Unit*/
	(MCU_tstProtect_Unit *)MCU_mProtect_ISOExt_Addr,/*MCU_tstProtect_Unit*/

	(MCU_tstClkMonitor_Unit *)MUC_mCLMA0_BasicAddr,
	(MCU_tstClkMonitor_Block *)MUC_mCLMABlock_BasicAddr,
	
	&MCU_stClockCfg_D1M2H,
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

MCU_tstResetCtrlModuleAttribute MCU_stResetCtrlAttribute=
{
	(MCU_tstProtect_Unit *)MCU_mMcuResetProtect_BaseAddr,
	(MCU_tstProtect_Unit *)MCU_mModuleResetProtect_BaseAddr,
	(MCU_stsResetCtrl_Unit *)MCU_mResetCtrl_BaseAddr,
	&MCU_stModuleEnableCfg,
};

MCU_tstSTBCModuleAttribute MCU_stSTBCAttribute=
{
	(MCU_tstSTBC_Unit *)MCU_mStanbyCtrl_BaseAddr,
	(MCU_tstProtect_Unit *)MCU_mStanbyCtrl_protect_Addr,
	&MCU_stSTBCCfg,
};

#if 0
MCU_tstResetCtrlModuleAttribute MCU_stResetCtrlAttribute=
{
	(MCU_tstResetReason_Unit *)MCU_mResetReason_Addr,
	(volatile uint32 * )MCU_mSoftWareReset_Addr,
	(MCU_tstProtect_Unit *)MCU_mSoftWareReset_ProtectAddr,
	
	(volatile uint32 *)MCU_mModuleReset_Addr,
	(MCU_tstProtect_Unit *)MCU_mModuleReset_ProtectAddr,
};
#endif

MCU_tstInterruptModuleAttribute MCU_stInterruptCtrlAttribute=
{
	(MCU_tstEIAttribute_Unint *) MCU_mEIC_BasicAddr_Hpr,		/*0xFFFEEA00*/
	(MCU_tstEIAttribute_Unint *)MCU_mEIC_BasicAddr_Lpr,		/*0xFFFFB000-->0xFFFFB040*/
	(MCU_vIMRtable *)MCU_mEIMR_HighPro_BasicAddr,			/*0xFFFEEAF0*/
	(MCU_vIMRtable *)MCU_mEIMR_LowPro_BasicAddr,			/*0xFFFFB400--->0xFFFFB404*/
	MCU_mMaxVectorNumber,								/*MCU_mMaxVectorNumber*/
};


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		PORT setting   
		@@@@@@@@@@		  
####################################################*/
MCU_stsPortAttribute MCU_stPortAttribute=
{
	(MCU_tstPortProtect_Unit *)MCU_mProtCmd_Addr_P0,	/*MCU_tstPortProtect_Unit * */
	(MCU_tstPortProtect_Unit *)MCU_mProtCmd_Addr,		/*MCU_tstPortProtect_Unit * */
	(MCU_tstPortProtect_Unit *)MCU_mProtCmd_Addr_JP0,	/*MCU_tstPortProtect_Unit * */
	
	/*Port*/
	MCU_MaxPortMount,			/* TottalPortNumber_Port*/
	(MCU_stsPinStruct_PortBasic *)MCU_mPortBaseAddr,			/* PortAddr*/
	(MCU_stsPinStruct_PortExt*)MCU_mPortExtAddr,			/* PortAddrExt*/
	(MCU_stsPinStruct_PortPCR (*)[0x40/sizeof(MCU_stsPinStruct_PortPCR)])MCU_mPortBaseAddr_PCR,		/* PortAddrPCR;*/
	
	(MCU_stsPinStruct_PortBasic *)MCU_mPortBaseAddr_P0,			/* PortAddr_P0*/
	(MCU_stsPinStruct_PortExt*)MCU_mPortExtAddr_P0,			/* PortAddrExt_P0*/
	(MCU_stsPinStruct_PortPCR *)MCU_mPortBaseAddr_PCR0,		/* PortAddrPCR_P0;*/
	
	MCU_stPinUserCfg_Port,				/*MCU_tstPinCfg*/
	
	/*Jport*/
	MCU_MaxJPortMount,			/* TottalPortNumber_JPort*/
	(MCU_stsPinStruct_PortBasic *)MCU_mJPortBaseAddr_JP0,		/* JPortAddr_JP0*/
	(MCU_stsPinStruct_PortExt*)MCU_mJPortExtAddr_JP0,	/* JPortAddrExt_JP0*/
	(MCU_stsPinStruct_PortPCR *)MCU_mJPortBaseAddr_JPCR0,/* JPortAddrPCR_JP0;*/
	
	MCU_stPinUserCfg_JPort,
	
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
/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		PWGA setting   
		@@@@@@@@@@		  
####################################################*/
MCU_tstPWGAModuleAttribute MCU_stPWGAAttribute=
{
	(MCU_tstPWBA_Unit *)MCU_mPWBA_BasicAddr,
	(MCU_tstPWGA_Unit *)MCU_mPWGA_BasicAddr,
	(MCU_tstSLPWGA *)MCU_mSLPWGA_BasicAddr,
	(MCU_tstPWSA_Unit *)MCU_mPWSA_BasicAddr,
	#if 0
	MCU_au16PWMvectList,
	#endif
	&MCU_stPWGACfg,
};
#endif


#if ((MCU_mTAUBDModuleEnable !=0u) ||(MCU_mTAUJModuleEnable !=0u))
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
		{0x1001,TimerIO(1,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 0 --> run INT if Edge detect, output enable*/
/*Counter mode RegVal*/
		{0x1006,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*OnePulseOutPut mode RegVal*/
		{0x0114,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},
/*PulseInterval mode RegVal*/
		{0x0144,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
/*PulseWidth mode RegVal*/
		{0x024c,TimerIO(0,0,0,0,0)|SimuReWrite(0,0,0,0)},/*bit 6-7 --> OV condition*/
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
		(MCU_tstTAUBD_Unit *)MCU_mTAUB2_BasicAddr,
	},
	
	{
		(MCU_tstTAUJ_Unit *)MCU_mTAUJ0_BasicAddr,
	},
	
	{	
		ISR_17_INTTAUB0I0,
		ISR_33_INTTAUB1I0,
		ISR_49_INTTAUB2I0,
		ISR_121_INTTAUJ0I0,
	},
	
	{	
		0xFFFFFFFF,	/*TAUB0 Alt Fun*/
		0xFFFFFFFF,	/*TAUB1 Alt Fun*/
		0xFFFFFFFF,	/*TAUB2 Alt Fun*/
		0xFFFFFFFF,	/*TAUJ0 Alt Fun*/
	},
	
	MCU_stTAUxRegisterValue,
	MCU_stTAUxClkDivCfg,
	(MCU_tstDNFA_Unit *)MCU_mDNFA_BasicAddr,
	MCU_stTAUxCfg,
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
	{
		{ISR_112_INTRIIC0TI,ISR_113_INTRIIC0TEI,ISR_111_INTRIIC0RI,ISR_110_INTRIIC0LEE},
		{ISR_116_INTRIIC1TI,ISR_117_INTRIIC1TEI,ISR_115_INTRIIC1RI,ISR_114_INTRIIC1LEE},
	},
	MCU_tstRIICCfg,
	
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
	ISR_94_INTDMA0,
	MCU_stDMACfg,
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
	(MCU_tstFCLA_Unit  *)MCU_mFCLA0_BasicAddr,
	(ISR_6_INTP0),/*NMI0 is fisrt*/
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
	{MCU_mADC_MaxChPerUnit},
	{ISR_66_INTADCE0I1},
	&MCU_stADCACfg,
};
#endif

#if (MCU_mRLIN3UartModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		ADC setting   
			@@@@@@@@@@		  
####################################################*/
MCU_tstRLIN3ModuleAttribute MCU_stRLIN3Attribute=
{
	(MCU_tstRLIN3_Unit *)MCU_mRLIN3_BasicAddr,
	{
		ISR_83_INTRLIN30UR0,			ISR_86_INTRLIN31UR0,
		ISR_217_INTRLIN32UR0,		ISR_220_INTRLIN33UR0,
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
	{ISR_74_INTCSIGT0IRE,ISR_127_INTCSIGT1IRE,ISR_130_INTCSIGT2IRE,ISR_133_INTCSIGT3IRE},
	MCU_stCSIGCfg,
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
		ISR_77_INTCSIH0IRE,
		ISR_136_INTCSIH1IRE,
	},
	MCU_stCSIHCfg,
};
#endif

