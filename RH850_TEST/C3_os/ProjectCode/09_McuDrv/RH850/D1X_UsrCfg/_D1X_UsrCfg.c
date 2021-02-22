/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1L_D1M_UsrCfg.c
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

#define PLL_MainOsc_8M_480M	0
#define PLL_MainOsc_8M_400M	1
#define PLL_MainOsc_8M_200M	2
#define PLL_MainOsc_8M_120M	3

#define PLL_MainOsc_16M_480M	4
#define PLL_MainOsc_16M_320M	5
#define PLL_MainOsc_16M_160M	6
#define PLL_MainOsc_16M_80M	7

#if ((MCU_UsingType > MCU_ID_RH850_D1M2H_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

#define PLL1_MainOsc_8M_960M	8
#define PLL1_MainOsc_8M_800M	9

#define PLL1_MainOsc_16M_960M		10
#define PLL1_MainOsc_16M_780M		11

#endif

MCU_tstClockUsrCfg MCU_stClockCfg_D1M2H=
{

/*******************************
	Basic clock module
******************************/
	3000,				/*uint32 MainOsc_StableTime ===>us*/
	MCU_CLK_UsingDefault,/*uint32 MainOscStopInStandbyMode;*/
	
	0,					/*uint32 SubOsc_FTX_Speed*/
	0,					/*uint32 SubOsc_StableTime;us*/
	/*MCU_CLK_UsingDefault,uint32 SubOscStopInStandbyMode;*/
	
	240000,				/*uint32 IntOscLS_FRL_Speed===>240000, can not change*/
	8000000,				/*uint32 IntOscHS_FRH_Speed===> 8000000, can not change*/
	
	PLL_MainOsc_8M_480M,/*uint32 PLL0_Speed;		clock from PLL 0 ===>default we use for CPU clock, not divider
						[D1M1A max = 960MHz, other max = 480MHz]*/
						
	PLL1_MainOsc_8M_960M,/*uint32 PLL1_Speed;		clock from PLL 1:
						[D1M2,D1M2H max = 960MHz, others max = 480MHz]*/
						
	PLL_MainOsc_8M_480M,/*uint32 PLL2_Speed;		clock from PLL 2*/
	
	MCU_CLK_UsingDefault,/*uint32 MEMCLK_Speed,external memery controller clock from PLL ===>ClkSel_CKSC_ISDRBS select the source clock*/


/*******************************
	ISO clock module
******************************/
	1,/*uint32 ClkSel_CKSC_ICLKJITS===>01B: CKDV_ICLKJITD_CTL selection
									10B: High Speed IntOsc fRH (default)

									NOTE: Max = 80 MHz*/
							
	8,/*uint32 ClkDiv_CKSC_ICLKJITD===>0000B: Disabled
									0100B: PLL0CLK /4
									0101B: PLL0CLK /5
									0110B: PLL0CLK /6 (default)
									1000B: PLL0CLK /8
									1010B: PLL0CLK /10*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ICLKFIXD===>	0000B: Disabled
														0110B: PLLFIXCLK /6 (default)
														1000B: PLLFIXCLK /8
														1010B: PLLFIXCLK /10
														1100B: PLLFIXCLK /12
									NOTE : Max = 80MHz*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ICLKFIXS===>	01B: CKDV_ICLKFIXD_CTL selection
														10B: High Speed IntOsc fRH (default)*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPLLFIXS===>	01B: PLL1CLK (default)
														10B: PLL2CLK (D1M2(H) only)
									NOTE : Max = 480MHz*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ISDRBS===>	0: Stop SDRBCLK clock (default)
														1: Activate SDRBCLK clock
									NOTE : D1M1H Max = 200MHz
										     D1M1A Max = 240MHz
										     D1M2/D1M2H Max = 480MHz
									*/
														
	3,/*uint32 ClkSel_CKSC_ICPUCLKS===>	001B: EMCLK (default)
										011B: PLL0CLK --->we use this value for CPU clock
										100B: PLL1CLK
										Selection of PLL0CLK for the C_ISO_CPUCLK clock domain is not allowed, when the DDR2-SDRAM
										Memory Controller (SDRB) is used.*/
								
	2,/*uint32 ClkDiv_CKSC_ICPUCLKD===>	001B: CKSC_ICPUCLKS_CTL selection /1 (default)
										010B: CKSC_ICPUCLKS_CTL selection /2
										011B: CKSC_ICPUCLKS_CTL selection /4
										100B: CKSC_ICPUCLKS_CTL selection /8
										101B: CKSC_ICPUCLKS_CTL selection /3*/
										
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCCLKS===>	0: Stop C_ISO_XCCLK (default)
														1: Activate C_ISO_XCCLK*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCETNBS===>	0: Stop ETNBPCLK clock (default)
														1: Activate ETNBPCLK clock*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCETNBS===>	0: Stop ETNBXCCLK clock (default)
														1: Activate ETNBXCCLK clock*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCMLBBS===>	0: Stop MLBBPCLK clock (default)
														1: Activate MLBBPCLK clock*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCMLBBS===>	0: Stop MLBBXCCLK clock (default)
														1: Activate MLBBXCCLK*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCRSCANS===>0: Stop RSCANPCLK clock
														1: Activate RSCANPCLK clock (default)*/

	MCU_CLK_UsingDefault,/*uint32 ClkSel_APB_CLK_RATIO===>	0: C_ISO_PCLK = C_ISO_CPUCLK / 2
														1: C_ISO_PCLK = C_ISO_CPUCLK / 4 (default)*/

/*******************************
	AWO clock module
******************************/

	2,/*uint32 ClkSel_CKSC_AAWOTS===>000B: Disabled
									001B: High Speed IntOsc fRH (default)
									010B: MainOsc fX
									011B: Low Speed IntOsc fRL*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_AAWOTD===>	001B: CKSC_AAWOTS_CTL selection /1 (default)
														010B: CKSC_AAWOTS_CTL selection /2
														011B: CKSC_AAWOTS_CTL selection /4
														100B: CKSC_AAWOTS_CTL selection /8
														101B: CKSC_AAWOTS_CTL selection /16*/
														
	0,				/*uint32 AAWOTStopInStandbyMode;*/
	
	1,				/*uint32 ClkDiv_CKSC_AWDTA0D===>	001B: Low Speed IntOsc fRL / 128 (default)
													010B: Low Speed IntOsc fRL / 1
													011B: Low Speed IntOsc fRL / 256
													100B: Low Speed IntOsc fRL / 512
													101B: Low Speed IntOsc fRL / 1024
													110B: Low Speed IntOsc fRL / 2048*/
													
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ARTCAS===>	000B: Disable (default)
														001B: SubOsc fTX
														010B: MainOsc fX
														011B: Low Speed IntOsc fRL
														100B: High Speed IntOsc fRH*/
														
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ARTCAD===>	000B: Disabled (default)
														001B: CKSC_ARTCAS_CTL selection /1
														010B: CKSC_ARTCAS_CTL selection /2
														011B: CKSC_ARTCAS_CTL selection /4
														100B: CKSC_ARTCAS_CTL selection /8
														101B: CKSC_ARTCAS_CTL selection /16*/
														
	0,/*uint32 ARTCAStopInStandbyMode;*/
	
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_AFOUTS===>	000B: Disabled (default)
									001B: MainOsc fX
									010B: High Speed IntOsc fRH
									011B: Low Speed IntOsc fRL
									100B: SubOsc fTX
									101B: PLL0CLK/4
									110B: PLL1CLK/4
									111B: PLL2CLK/4 (D1M2(H) only)*/
									
	120,/*uint32 ClkDiv_CKSC_AFOUTD:		[source = CKSC_AFOUTS]
								===>range: 0= disable, 1 <= range <=512	*/
		
	0,	/*uint32 AFOUTStopInStandbyMode;*/
	
/*******************************
	external clock module
******************************/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IMLBBS===>
	
							NOTE:Max = 120Mhz
							
								00B: Disabled (default)
								01B: PLL0CLK /2
								10B: PLL0CLK /4*/
								
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ISFMAS===>
	
							NOTE:Max = 240Mhz
	
								01B: PLL0CLK
								10B: PLL1CLK (default)*/
								
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ISFMAD===>
							
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
									All others: Setting prohibited*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_IRSCAND===>
	
							NOTE:Max = 40Mhz
							
								000B: Disabled
								001B: PLLFIXCLK /30
								010B: PLLFIXCLK /40
								011B: PLLFIXCLK /60
								100B: PLLFIXCLK /12 (default)
								101B: PLLFIXCLK /24*/
								
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IRSCANXINS===>
	
							NOTE:Max = 16Mhz
							
								0: Disabled
								1: MainOsc fX (default)*/
								
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKDV_ISSIFD===>
	
							NOTE:Max = 50Mhz
						
								source = PLLFIXCLK
								range: 0= disable, 1 <= range <=512*/
	
	1,/*uint32 ClkSel_CKSC_ITAUB01S===>
	
							NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8*/
								
	1,/*uint32 ClkSel_CKSC_ITAUB2S===>
	
							NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX*/
								
	1,/*uint32 ClkSel_CKSC_ITAUJS===>
	
							NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
								110B: C_ISO_CPUCLK /4*/
								
	1,/*uint32 ClkSel_CKSC_IOSTMS===>
	
							NOTE:Max = 80Mhz
							
								00B: Disabled
								01B: CLKJIT
								10B: C_ISO_CPUCLK /4 (default)
								11B: MainOsc fX*/
								
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ILCBIS===>
	
							NOTE:Max = 80Mhz
							
								0: Disabled (default)
								1: CLKJIT*/
							
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_IADCED===>
	
							NOTE:Max = 40Mhz
								
									01B: CLKJIT /2 (default)
									10B: CLKJIT /4*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IISMS===>
	
							NOTE:Max = 80Mhz
								
									0: Disabled (default)
									1: CLKJIT*/
									
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IRLINS===>
						
							NOTE:Max = 48Mhz(D1Lx)
								 :Max = 24Mhz(D1M1x)
								 :Max = 48Mhz(D1M2x)
							
								 D1M1(H):
									01B: PLLFIXCLK /10
									10B: CLKJIT /1
									11B: PLLFIXCLK /20 (default)
									
								 All other devices:
									01B: PLLFIXCLK /10
									10B: CLKJIT /1 (default)*/

/**** Clock Monitor ********************************************************************/		

	0,/*uint32 Video0_InClkFre;	*/				
	0,/*uint32 Video1_InClkFre;	*/	
	
	0,/*uint32 CLMA0enable_HS;		CLMA0 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA0TolerancePercent;*/
	
	0,/*uint32 CLMA1enable_LS;			CLMA1 monitor unit,sample clock = HS/256 = 31.25kHz*/
	0,/*uint32 CLMA1TolerancePercent;*/
	
	0,/*uint32 CLMA2enable_MainOsc;		CLMA2 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA2TolerancePercent;*/

	0,/*uint32 CLMA3enable_PLL0;		CLMA3 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA3TolerancePercent;*/

	0,/*uint32 CLMA4enable_PLL1;		CLMA4 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA4TolerancePercent;*/
	
	0,/*uint32 CLMA5enable_Vidoe0;		CLMA5 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA5TolerancePercent;*/

	0,/*uint32 CLMA6enable_Vidoe1;		CLMA6 monitor unit,sample clock = LS = 240kHz*/
	0,/*uint32 CLMA6TolerancePercent;*/
	
};



MCU_tstSTBC_UsrCfg MCU_stSTBCCfg=
{
		/******************************************
			WakeUp factor enable configeration
		******************************************/
		
		0, /*	INTDCUTDI		*/
		0, /*	INTP0_RLIN31RX	*/
		0, /*	INTP1			*/
		0, /*	INTP2_RLIN32RX	*/
		0, /*	INTP3			*/
		0, /*	INTP4_RLIN33RX	*/
		0, /*	INTP5			*/
		0, /*	INTP6_CAN0RX	*/
		0, /*	INTP7			*/
		0, /*	INTP8_CAN1RX_RLIN30RX	*/
		0, /*	INTP9			*/
		0, /*	INTP10_CAN2RX_RLIN30RX	*/
		0, /*	INTWDTA0	*/
		0, /*	INTRTCA01S	*/
		0, /*	INTRTCA0AL	*/
		0, /*	INTRTCA0R	*/
		0, /*	INTAWOT0	*/
		0, /*	ECMTI		*/
		0, /*	ECMTNMI 	*/
		0, /*	Fill			*/	
};

MCU_tstModuleEnable_UsrCfg MCU_stModuleEnableCfg=
{
		/******************************************
			module enable configeration
		******************************************/
		
		0,		/*	 VDCE0RES	*/
		0,		/*	 VDCE1RES	*/
		0,		/*	 ETNB0RES	*/
		0,		/*	 ISM0RES*/
		1,		/*	 ADCE0RES	*/
		0,		/*	 SG0RES 	*/
		0,		/*	 SG1RES */
		0,		/*	 SG2RES 	*/
		0,		/*	 SG3RES 	*/
		0,		/*	 SG4RES 	*/
		0,		/*	 LCBI0RES	*/
		0,		/*	 MLBB0RES*/
		0,		/*	 SDRB0RES*/
		0,		/*	 XC0RES */
		0,		/*	 Fill  */
		
};



/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		port setting   
			@@@@@@@@@@		  
####################################################*/

/*Pin function configeration*/
#define GPIO_Out	0u
#define GPIO_In	1u

#define AltOut_1	2u
#define AltIn_1	3u

#define AltOut_2	4u
#define AltIn_2	5u

#define AltOut_3	6u
#define AltIn_3	7u

#define AltOut_4	8u
#define AltIn_4	9u

#define AltOut_5	10u
#define AltIn_5	11u

#define AltOut_6	12u
#define AltIn_6	13u

#define AltOut_7	14u
#define AltIn_7	15u

#define ADinput 	GPIO_In

#define Hi		1u/*High level when reset*/
#define Lo		0u/*Low level when reset*/
#define Lock		0u/*Pin attribute Un-changeable*/
#define Unlock		1u/*Pin attribute changeable*/
#define In		GPIO_In/*input mode*/
#define Out		GPIO_Out/*output mode*/
#define PU_Off		0u/*Pull-Up not use*/
#define PU_On		1u/*Pull-Up use*/
#define PD_Off		0u/*Pull-Down not use*/
#define PD_On		1u/*Pull-Down use*/
#define OD_Off		0u/*OpenD not use*/
#define OD_On		1u/*OpenD use*/
#define FillField		0u

#define PinConf(AltFun,PinResetLevel)	                   {AltFun,PinResetLevel,0/*PullUp*/,0/*PullDown*/,0/*OpenD*/,0/*PinBufType*/,0/*HighSpeed*/,0/*PBDC*/,FillField}
#define PinConf_IICpin(AltFun)	                            {AltFun&(~1), 0/*level*/,     0/*PullUp*/,0/*PullDown*/,1/*OpenD*/,0/*PinBufType*/,0/*HighSpeed*/,1/*1PBDC*/,FillField}
#define __ThisPin_NotMount__	                            {0xFF,0,0/*PullUp*/,0/*PullDown*/,0/*OpenD*/,0/*PinBufType*/,0/*HighSpeed*/,0/*PBDC*/,FillField}

const MCU_tstPinCfg MCU_stPinUserCfg_Port[MCU_MaxPortMount*MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	PinFill_0}
*************************************************************************************/


/*##################*/
/*Pin ID =====Port 0*/
/*##################*/
/*P0_0*/__ThisPin_NotMount__,	/*	1_I=>NMI				1_O=>RLIN31TX		2_I=>CSIH0SSI	2_O=>CSIH0CSS0		3_I=>TAUJ0I0	3_O=>TAUJ0O0	4_I=>INTP5	4_O=>OSTM0 TTOUT					*/
/*P0_1*/__ThisPin_NotMount__,	/*	1_I=>RLIN31RX/INTP0		2_O=>CSIH0SO		3_I=>TAUJ0I1	3_O=>TAUJ0O1		4_O=>ERROROUT										*/
/*P0_2*/__ThisPin_NotMount__,	/*	1_I=>INTP1				1_O=>RLIN32TX		2_I=>CSIH0SI		3_I=>TAUJ0I3		3_O=>TAUJ0O3	4_O=>AWOT0 TOUT					*/
/*P0_3*/__ThisPin_NotMount__,	/*	1_I=>RLIN32RX/INTP2		2_I=>CSIH0SC		2_O=>CSIH0SC	3_I=>TAUJ0I2		3_O=>TAUJ0O2	4_O=>CAN0DREN					*/
/*P0_4*/__ThisPin_NotMount__,	/*	1_I=>INTP5				1_O=>OSTM1 TTOUT	2_O=>TAUB1O3*1		3_I=>TAUB1I3	3_O=>CSCXFOUT	4_O=>CAN0TX					*/
/*P0_5*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I1			1_O=>TAUJ0O1		2_O=>TAUB1O5*1		3_I=>TAUB1I5	3_O=>RTCA0OUT	4_I=>CAN0RX/INTP6						*/
/*P0_6*/__ThisPin_NotMount__,	/*	1_I=>INTP7				1_O=>RLIN30TX		2_O=>TAUB1O7*1		3_I=>TAUB1I7	4_O=>CAN1TX										*/
/*P0_7*/__ThisPin_NotMount__,	/*	1_I=>RLIN30RX/INTP8		2_O=>TAUB1O9*1		3_I=>TAUJ0I0	3_O=>TAUJ0O0		4_I=>CAN1RX/INTP8	4_O=>CAN2DREN					*/
/*P0_8*/__ThisPin_NotMount__,	/*	1_I=>INTP9				1_O=>RLIN30TX		3_I=>TAUJ0I1	3_O=>TAUJ0O1		4_O=>CAN2TX					*/
/*P0_9*/__ThisPin_NotMount__,	/*	1_I=>RLIN30RX/INTP10	3_I=>TAUJ0I0		3_O=>TAUJ0O0	4_I=>CAN2RX/INTP10	4_O=>CAN1DREN					*/
/*P0_10*/__ThisPin_NotMount__,	/*													*/
/*P0_11*/__ThisPin_NotMount__,	/*													*/
/*P0_12*/__ThisPin_NotMount__,	/*													*/
/*P0_13*/__ThisPin_NotMount__,	/*													*/
/*P0_14*/__ThisPin_NotMount__,	/*													*/
/*P0_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 1*/
/*##################*/
/*P1_0*/__ThisPin_NotMount__,	/*	1_I=>TAUB1I2	1_O=>TAUB1O2	2_O=>CSIH1SO	3_I=>CSIG2RYI	3_O=>CSIG2RYO							*/
/*P1_1*/__ThisPin_NotMount__,	/*	1_I=>TAUB1I4	1_O=>TAUB1O4	2_I=>CSIH1SI		3_I=>CSIG2SSI	4_I=>CSIH0SSI	4_O=>CSIH0CSS0					*/
/*P1_2*/__ThisPin_NotMount__,	/*	1_I=>TAUB1I8	1_O=>TAUB1O8	2_I=>CSIH1SC	2_O=>CSIH1SC	4_I=>CSIH0RYI	4_O=>CSIH0RYO					*/
/*P1_3*/__ThisPin_NotMount__,	/*	1_O=>CSIG1SO	2_O=>CSIH0SO	4_I=>ADCE0 TRIGI3															*/
/*P1_4*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SI		2_I=>CSIH0SI		3_I=>CSIG0SSI	4_I=>CSIH1SSI	4_O=>CSIH1CSS0											*/
/*P1_5*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SC	1_O=>CSIG1SC	2_I=>CSIH0SC	2_O=>CSIH0SC	3_I=>CSIG0RYI	3_O=>CSIG0RYO	4_I=>CSIH1RYI	4_O=>CSIH1RYO					*/
/*P1_6*/__ThisPin_NotMount__,	/*	1_O=>CSIG2SO	4_I=>TAUB0I1	4_O=>TAUB0O1														*/
/*P1_7*/__ThisPin_NotMount__,	/*	1_I=>CSIG2SI		3_I=>CSIG1SSI	4_I=>TAUB0I2	4_O=>TAUB0O2							*/
/*P1_8*/__ThisPin_NotMount__,	/*	1_I=>CSIG2SC	1_O=>CSIG2SC	3_I=>CSIG1RYI	3_O=>CSIG1RYO	4_I=>TAUB0I3	4_O=>TAUB0O3					*/
/*P1_9*/__ThisPin_NotMount__,	/*	1_O=>CSIG0SO	4_I=>TAUB0I5	4_O=>TAUB0O5										*/
/*P1_10*/__ThisPin_NotMount__,	/*1_I=>CSIG0SI	4_I=>TAUB0I6	4_O=>TAUB0O6					*/
/*P1_11*/__ThisPin_NotMount__,	/*1_I=>CSIG0SC	1_O=>CSIG0SC	4_I=>TAUB0I7		4_O=>TAUB0O7					*/
/*P1_12*/__ThisPin_NotMount__,	/*													*/
/*P1_13*/__ThisPin_NotMount__,	/*													*/
/*P1_14*/__ThisPin_NotMount__,	/*													*/
/*P1_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 2*/
/*##################*/
/*P2_0*/__ThisPin_NotMount__,	/*	1_I=>CSIG3SSI	2_O=>PWGA0O	3_I=>RIIC1SDA	3_O=>RIIC2SDA	4_I=>TAUB2I1	4_O=>TAUB2O1					*/
/*P2_1*/__ThisPin_NotMount__,	/*	1_O=>CSIG3SO	2_O=>PWGA1O	3_I=>RIIC1SCL	3_O=>RIIC2SCL	4_I=>TAUB2I3	4_O=>TAUB2O3					*/
/*P2_2*/__ThisPin_NotMount__,	/*	1_I=>CSIG3SI		2_O=>PWGA2O	3_I=>TAUJ0I2	3_O=>TAUJ0O2	4_I=>TAUB2I5	4_O=>TAUB2O5					*/
/*P2_3*/__ThisPin_NotMount__,	/*	1_I=>CSIG3SC	1_O=>CSIG3SC	2_O=>PWGA3O	3_I=>TAUJ0I3	3_O=>TAUJ0O3	4_I=>TAUB2I7	4_O=>TAUB2O7					*/
/*P2_4*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SSI	2_O=>PWGA4O	3_I=>TAUB0I9	3_O=>TAUB0O9	4_I=>TAUB2I2	4_O=>TAUB2O2					*/
/*P2_5*/__ThisPin_NotMount__,	/*	1_O=>CSIG1SO	2_O=>PWGA5O	3_I=>TAUB0I10	3_O=>TAUB0O10	4_I=>TAUB2I6	4_O=>TAUB2O6					*/
/*P2_6*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SI		2_O=>PWGA6O	3_I=>TAUB0I11	3_O=>TAUB0O11	4_I=>TAUB2I9	4_O=>TAUB2O9					*/
/*P2_7*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SC	1_O=>CSIG1SC	2_O=>PWGA7O	3_I=>TAUB0I13	3_O=>TAUB0O13	4_I=>TAUB2I10	4_O=>TAUB2O10					*/
/*P2_8*/__ThisPin_NotMount__,	/*	1_I=>CSIG0SSI	2_O=>PWGA8O	3_I=>TAUB0I14	3_O=>TAUB0O14	4_I=>TAUB2I11	4_O=>TAUB2O11					*/
/*P2_9*/__ThisPin_NotMount__,	/*	2_O=>PWGA9O	3_I=>CSIH0SSI	3_O=>CSIH0CSS0	4_I=>TAUB2I13	4_O=>TAUB2O13					*/
/*P2_10*/__ThisPin_NotMount__,	/*1_I=>CSIG1SSI	2_O=>PWGA10O	3_I=>CSIH1SSI	3_O=>CSIH1CSS0	4_I=>TAUB2I14	4_O=>TAUB2O14					*/
/*P2_11*/__ThisPin_NotMount__,	/*1_I=>CSIG2SSI	2_O=>PWGA11O	4_I=>TAUB2I15	4_O=>TAUB2O15					*/
/*P2_12*/__ThisPin_NotMount__,	/*													*/
/*P2_13*/__ThisPin_NotMount__,	/*													*/
/*P2_14*/__ThisPin_NotMount__,	/*													*/
/*P2_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 3*/
/*##################*/
/*P3_0*/__ThisPin_NotMount__,	/*	1_I=>RIIC0SDA		1_O=>RIIC0SDA	2_I=>ETNB0MDIO	2_O=>ETNB0MDIO	4_I=>TAUB1I10	4_O=>TAUB1O10					*/
/*P3_1*/__ThisPin_NotMount__,	/*	1_I=>RIIC0SCL		1_O=>RIIC0SCL	2_O=>ETNB0MDC	4_I=>TAUB1I11	4_O=>TAUB1O11					*/
/*P3_2*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 AP0*1	2_I=>SSIF0RXD	2_O=>TAUB1O9	3_O=>SG0FAO*1	4_I=>TAUB0I4	4_O=>TAUB0O4					*/
/*P3_3*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 AN0*1	2_I=>TAUB1I11	2_O=>SSIF0TXD	3_I=>TAUB1I12	3_O=>SG1FAO	4_O=>SG0FAOL					*/
/*P3_4*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 AP1*1	2_I=>SSIF0SCK	2_O=>SSIF0SCK	3_I=>TAUB1I14	3_O=>SG2FAO	4_I=>TAUB0I8	4_O=>TAUB0O8					*/
/*P3_5*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 AN1*1	2_I=>SSIF0WS	2_O=>SSIF0WS	3_I=>TAUB2I12	3_O=>SG3FAO	4_O=>SG0AO					*/
/*P3_6*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 BP0*1	2_I=>SSIFACK	2_O=>SSIFACK	3_I=>TAUB2I14	3_O=>SG4FAO	4_I=>TAUB0I12	4_O=>TAUB0O12					*/
/*P3_7*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 BN0*1	2_I=>SSIF1WS	2_O=>SSIF1WS	3_O=>SG0FAOL*1	4_O=>SG0AO*1					*/
/*P3_8*/__ThisPin_NotMount__,	/*	1_O=>PCMP0BP1*1	2_I=>SSIF1SCK	2_O=>SSIF1SCK	3_I=>TAUB1I13	3_O=>SG1FAOL	4_O=>SG1AO					*/
/*P3_9*/__ThisPin_NotMount__,	/*	1_O=>PCMP0 BN1*1	2_I=>SSIF1RXD	2_O=>SSIF1TXD	3_I=>TAUB1I15	3_O=>SG2FAOL	4_O=>SG2AO					*/
/*P3_10*/__ThisPin_NotMount__,	/*1_I=>TAUB1I6		1_O=>PWGA12O	2_I=>SSIF1RXD	2_O=>TAUB1O6	3_I=>TAUB2I13	3_O=>SG3FAOL	4_O=>SG3AO					*/
/*P3_11*/__ThisPin_NotMount__,	/*1_O=>PWGA13O		2_I=>TAUB0I15	2_O=>TAUB0O15	3_I=>TAUB2I15	3_O=>SG4FAOL	4_O=>SG4AO					*/
/*P3_12*/__ThisPin_NotMount__,	/*1_O=>PWGA14O		2_I=>TAUB1I2	2_O=>TAUB1O2	4_I=>ADCE0 TRIGI1	4_O=>TAUB2O14					*/
/*P3_13*/__ThisPin_NotMount__,	/*1_O=>PWGA15O		2_I=>TAUB1I10	2_O=>TAUB1O10	4_I=>ADCE0 TRIGI2	4_O=>TAUB2O15					*/
/*P3_14*/__ThisPin_NotMount__,	/*													*/
/*P3_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 4*/
/*##################*/
/*P4_0*/__ThisPin_NotMount__,
/*P4_1*/__ThisPin_NotMount__,
/*P4_2*/__ThisPin_NotMount__,
/*P4_3*/__ThisPin_NotMount__,
/*P4_4*/__ThisPin_NotMount__,
/*P4_5*/__ThisPin_NotMount__,
/*P4_6*/__ThisPin_NotMount__,
/*P4_7*/__ThisPin_NotMount__,
/*P4_8*/__ThisPin_NotMount__,
/*P4_9*/__ThisPin_NotMount__,
/*P4_10*/__ThisPin_NotMount__,
/*P4_11*/__ThisPin_NotMount__,
/*P4_12*/__ThisPin_NotMount__,
/*P4_13*/__ThisPin_NotMount__,
/*P4_14*/__ThisPin_NotMount__,
/*P4_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 5*/
/*##################*/
/*P5_0*/__ThisPin_NotMount__,
/*P5_1*/__ThisPin_NotMount__,
/*P5_2*/__ThisPin_NotMount__,
/*P5_3*/__ThisPin_NotMount__,
/*P5_4*/__ThisPin_NotMount__,
/*P5_5*/__ThisPin_NotMount__,
/*P5_6*/__ThisPin_NotMount__,
/*P5_7*/__ThisPin_NotMount__,
/*P5_8*/__ThisPin_NotMount__,
/*P5_9*/__ThisPin_NotMount__,
/*P5_10*/__ThisPin_NotMount__,
/*P5_11*/__ThisPin_NotMount__,
/*P5_12*/__ThisPin_NotMount__,
/*P5_13*/__ThisPin_NotMount__,
/*P5_14*/__ThisPin_NotMount__,
/*P5_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 6*/
/*##################*/
/*P6_0*/__ThisPin_NotMount__,
/*P6_1*/__ThisPin_NotMount__,
/*P6_2*/__ThisPin_NotMount__,
/*P6_3*/__ThisPin_NotMount__,
/*P6_4*/__ThisPin_NotMount__,
/*P6_5*/__ThisPin_NotMount__,
/*P6_6*/__ThisPin_NotMount__,
/*P6_7*/__ThisPin_NotMount__,
/*P6_8*/__ThisPin_NotMount__,
/*P6_9*/__ThisPin_NotMount__,
/*P6_10*/__ThisPin_NotMount__,
/*P6_11*/__ThisPin_NotMount__,
/*P6_12*/__ThisPin_NotMount__,
/*P6_13*/__ThisPin_NotMount__,
/*P6_14*/__ThisPin_NotMount__,
/*P6_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 7*/
/*##################*/
/*P7_0*/__ThisPin_NotMount__,
/*P7_1*/__ThisPin_NotMount__,
/*P7_2*/__ThisPin_NotMount__,
/*P7_3*/__ThisPin_NotMount__,
/*P7_4*/__ThisPin_NotMount__,
/*P7_5*/__ThisPin_NotMount__,
/*P7_6*/__ThisPin_NotMount__,
/*P7_7*/__ThisPin_NotMount__,
/*P7_8*/__ThisPin_NotMount__,
/*P7_9*/__ThisPin_NotMount__,
/*P7_10*/__ThisPin_NotMount__,
/*P7_11*/__ThisPin_NotMount__,
/*P7_12*/__ThisPin_NotMount__,
/*P7_13*/__ThisPin_NotMount__,
/*P7_14*/__ThisPin_NotMount__,
/*P7_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 8*/
/*##################*/
/*P8_0*/__ThisPin_NotMount__,
/*P8_1*/__ThisPin_NotMount__,
/*P8_2*/__ThisPin_NotMount__,
/*P8_3*/__ThisPin_NotMount__,
/*P8_4*/__ThisPin_NotMount__,
/*P8_5*/__ThisPin_NotMount__,
/*P8_6*/__ThisPin_NotMount__,
/*P8_7*/__ThisPin_NotMount__,
/*P8_8*/__ThisPin_NotMount__,
/*P8_9*/__ThisPin_NotMount__,
/*P8_10*/__ThisPin_NotMount__,
/*P8_11*/__ThisPin_NotMount__,
/*P8_12*/__ThisPin_NotMount__,
/*P8_13*/__ThisPin_NotMount__,
/*P8_14*/__ThisPin_NotMount__,
/*P8_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 9*/
/*##################*/
/*P9_0*/__ThisPin_NotMount__,
/*P9_1*/__ThisPin_NotMount__,
/*P9_2*/__ThisPin_NotMount__,
/*P9_3*/__ThisPin_NotMount__,
/*P9_4*/__ThisPin_NotMount__,
/*P9_5*/__ThisPin_NotMount__,
/*P9_6*/__ThisPin_NotMount__,
/*P9_7*/__ThisPin_NotMount__,
/*P9_8*/__ThisPin_NotMount__,
/*P9_9*/__ThisPin_NotMount__,
/*P9_10*/__ThisPin_NotMount__,
/*P9_11*/__ThisPin_NotMount__,
/*P9_12*/__ThisPin_NotMount__,
/*P9_13*/__ThisPin_NotMount__,
/*P9_14*/__ThisPin_NotMount__,
/*P9_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 10*/
/*##################*/
/*P10_0*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I1	2_O=>TAUB0O1	3_I=>TAUB2I1	3_O=>TAUB2O1							*/
/*P10_1*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I2	2_O=>TAUB0O2	3_I=>TAUB2I2	3_O=>TAUB2O2							*/
/*P10_2*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I3	2_O=>TAUB0O3	3_I=>TAUB2I3	3_O=>TAUB2O3							*/
/*P10_3*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I5	2_O=>TAUB0O5	3_I=>TAUB2I5	3_O=>TAUB2O5							*/
/*P10_4*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I6	2_O=>TAUB0O6	3_I=>TAUB2I6	3_O=>TAUB2O6							*/
/*P10_5*/__ThisPin_NotMount__,	/*	1_I=>ADCE0 TRIGI1	2_I=>TAUB0I7	2_O=>TAUB0O7	3_I=>TAUB2I7	3_O=>TAUB2O7							*/
/*P10_6*/__ThisPin_NotMount__,	/*	1_I=>ADCE0 TRIGI2	2_I=>TAUB0I9	2_O=>TAUB0O9	3_I=>TAUB2I9	3_O=>TAUB2O9							*/
/*P10_7*/__ThisPin_NotMount__,	/*	1_I=>ADCE0 TRIGI3	2_I=>TAUB0I10	2_O=>TAUB0O10	3_I=>TAUB2I10	3_O=>TAUB2O10							*/
/*P10_8*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I11	2_O=>TAUB0O11	3_I=>TAUB2I11	3_O=>TAUB2O11							*/
/*P10_9*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I13	2_O=>TAUB0O13	3_I=>TAUB2I13	3_O=>TAUB2O13							*/
/*P10_10*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I14	2_O=>TAUB0O14	3_I=>TAUB2I14	3_O=>TAUB2O14							*/
/*P10_11*/__ThisPin_NotMount__,	/*	2_I=>TAUB0I15	2_O=>TAUB0O15	3_I=>TAUB2I15	3_O=>TAUB2O15							*/
/*P10_12*/__ThisPin_NotMount__,	/*													*/
/*P10_13*/__ThisPin_NotMount__,	/*													*/
/*P10_14*/__ThisPin_NotMount__,	/*													*/
/*P10_15*/__ThisPin_NotMount__,	/*													*/



/*##################*/
/*Pin ID =====Port 11*/
/*##################*/
/*P11_0*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I1	2_O=>TAUB1O1									*/
/*P11_1*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I2	2_O=>TAUB1O2									*/
/*P11_2*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I3	2_O=>TAUB1O3									*/
/*P11_3*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I5	2_O=>TAUB1O5									*/
/*P11_4*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I6	2_O=>TAUB1O6									*/
/*P11_5*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I7	2_O=>TAUB1O7									*/
/*P11_6*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I9	2_O=>TAUB1O9									*/
/*P11_7*/__ThisPin_NotMount__,	/*	2_I=>TAUB1I10	2_O=>TAUB1O10									*/
/*P11_8*/__ThisPin_NotMount__,	/*													*/
/*P11_9*/__ThisPin_NotMount__,	/*													*/
/*P11_10*/__ThisPin_NotMount__,	/*													*/
/*P11_11*/__ThisPin_NotMount__,	/*													*/
/*P11_12*/__ThisPin_NotMount__,	/*													*/
/*P11_13*/__ThisPin_NotMount__,	/*													*/
/*P11_14*/__ThisPin_NotMount__,	/*													*/
/*P11_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 12*/
/*##################*/
/*P12_0*/__ThisPin_NotMount__,
/*P12_1*/__ThisPin_NotMount__,
/*P12_2*/__ThisPin_NotMount__,
/*P12_3*/__ThisPin_NotMount__,
/*P12_4*/__ThisPin_NotMount__,
/*P12_5*/__ThisPin_NotMount__,
/*P12_6*/__ThisPin_NotMount__,
/*P12_7*/__ThisPin_NotMount__,
/*P12_8*/__ThisPin_NotMount__,
/*P12_9*/__ThisPin_NotMount__,
/*P12_10*/__ThisPin_NotMount__,
/*P12_11*/__ThisPin_NotMount__,
/*P12_12*/__ThisPin_NotMount__,
/*P12_13*/__ThisPin_NotMount__,
/*P12_14*/__ThisPin_NotMount__,
/*P12_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 13*/
/*##################*/
/*P13_0*/__ThisPin_NotMount__,
/*P13_1*/__ThisPin_NotMount__,
/*P13_2*/__ThisPin_NotMount__,
/*P13_3*/__ThisPin_NotMount__,
/*P13_4*/__ThisPin_NotMount__,
/*P13_5*/__ThisPin_NotMount__,
/*P13_6*/__ThisPin_NotMount__,
/*P13_7*/__ThisPin_NotMount__,
/*P13_8*/__ThisPin_NotMount__,
/*P13_9*/__ThisPin_NotMount__,
/*P13_10*/__ThisPin_NotMount__,
/*P13_11*/__ThisPin_NotMount__,
/*P13_12*/__ThisPin_NotMount__,
/*P13_13*/__ThisPin_NotMount__,
/*P13_14*/__ThisPin_NotMount__,
/*P13_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 14*/
/*##################*/
/*P14_0*/__ThisPin_NotMount__,
/*P14_1*/__ThisPin_NotMount__,
/*P14_2*/__ThisPin_NotMount__,
/*P14_3*/__ThisPin_NotMount__,
/*P14_4*/__ThisPin_NotMount__,
/*P14_5*/__ThisPin_NotMount__,
/*P14_6*/__ThisPin_NotMount__,
/*P14_7*/__ThisPin_NotMount__,
/*P14_8*/__ThisPin_NotMount__,
/*P14_9*/__ThisPin_NotMount__,
/*P14_10*/__ThisPin_NotMount__,
/*P14_11*/__ThisPin_NotMount__,
/*P14_12*/__ThisPin_NotMount__,
/*P14_13*/__ThisPin_NotMount__,
/*P14_14*/__ThisPin_NotMount__,
/*P14_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 15*/
/*##################*/
/*P15_0*/__ThisPin_NotMount__,
/*P15_1*/__ThisPin_NotMount__,
/*P15_2*/__ThisPin_NotMount__,
/*P15_3*/__ThisPin_NotMount__,
/*P15_4*/__ThisPin_NotMount__,
/*P15_5*/__ThisPin_NotMount__,
/*P15_6*/__ThisPin_NotMount__,
/*P15_7*/__ThisPin_NotMount__,
/*P15_8*/__ThisPin_NotMount__,
/*P15_9*/__ThisPin_NotMount__,
/*P15_10*/__ThisPin_NotMount__,
/*P15_11*/__ThisPin_NotMount__,
/*P15_12*/__ThisPin_NotMount__,
/*P15_13*/__ThisPin_NotMount__,
/*P15_14*/__ThisPin_NotMount__,
/*P15_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 16*/
/*##################*/
/*P16_0*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I1	1_O=>ISM11		2_O=>PWGA16O		3_O=>TAUB0O1*1		4_I=>TAUB0I0	4_O=>TAUB0O					*/
/*P16_1*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I3	1_O=>ISM12		2_O=>PWGA17O		3_O=>TAUB0O3*1		4_I=>TAUB1I0	4_O=>TAUB1O0					*/
/*P16_2*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I5	1_O=>ISM13		2_O=>PWGA18O		3_O=>TAUB0O5*1		4_I=>TAUB2I0	4_O=>TAUB2O0					*/
/*P16_3*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I7	1_O=>ISM14		2_O=>PWGA19O		3_O=>TAUB0O7*1								*/
/*P16_4*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I9	1_O=>ISM21		2_O=>PWGA20O		3_O=>TAUB0O9*1								*/
/*P16_5*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I11	1_O=>ISM22		2_O=>PWGA21O		3_O=>TAUB0O11*1							*/
/*P16_6*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I13	1_O=>ISM23		2_O=>PWGA22O		3_O=>TAUB0O13*1							*/
/*P16_7*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I15	1_O=>ISM24		2_O=>PWGA23O		3_O=>TAUB1O1*1		4_I=>TAUB1I1	4_O=>TAUB0O15					*/
/*P16_8*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I0	1_O=>ISM51		2_O=>TAUB1O11		3_O=>PCMP0 AP0*1							*/
/*P16_9*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I1	1_O=>ISM52		2_O=>TAUB1O13		3_O=>PCMP0 AN0*1							*/
/*P16_10*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I2	1_O=>ISM53		2_O=>TAUB1O14		3_O=>PCMP0 AP1*1							*/
/*P16_11*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I3	1_O=>ISM54		2_O=>TAUB1O15		3_O=>PCMP0 AN1*1							*/
/*P16_12*/__ThisPin_NotMount__,	/*													*/
/*P16_13*/__ThisPin_NotMount__,	/*													*/
/*P16_14*/__ThisPin_NotMount__,	/*													*/
/*P16_15*/__ThisPin_NotMount__,	/*													*/



/*##################*/
/*Pin ID =====Port 17*/
/*##################*/
/*P17_0*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I4	1_O=>ISM61		2_O=>TAUB2O1		3_O=>PCMP0 BP0*1							*/
/*P17_1*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I5	1_O=>ISM62		2_I=>ADCE0 TRIGI1	2_O=>TAUB2O2		3_O=>PCMP0 BN0*1							*/
/*P17_2*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I6	1_O=>ISM63		2_I=>ADCE0 TRIGI2	2_O=>TAUB2O3		3_O=>PCMP0 BP1*1							*/
/*P17_3*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I7	1_O=>ISM64		2_I=>ADCE0 TRIGI3	2_O=>TAUB2O5		3_O=>PCMP0 BN1*1							*/
/*P17_4*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I8	1_O=>ISM31		2_O=>TAUB2O6									*/
/*P17_5*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I9	1_O=>ISM32		2_O=>TAUB2O7									*/
/*P17_6*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I10	1_O=>ISM33		2_O=>TAUB2O9									*/
/*P17_7*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I11	1_O=>ISM34		2_O=>TAUB2O10									*/
/*P17_8*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I12	1_O=>ISM41		2_O=>TAUB2O11									*/
/*P17_9*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I13	1_O=>ISM42		2_O=>TAUB2O13									*/
/*P17_10*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I14	1_O=>ISM43		2_O=>TAUB2O14									*/
/*P17_11*/__ThisPin_NotMount__,	/*	1_I=>TAUB2I15	1_O=>ISM44		2_O=>TAUB2O15									*/
/*P17_12*/__ThisPin_NotMount__,	/*													*/
/*P17_13*/__ThisPin_NotMount__,	/*													*/
/*P17_14*/__ThisPin_NotMount__,	/*													*/
/*P17_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 18*/
/*##################*/
/*P18_0*/__ThisPin_NotMount__,
/*P18_1*/__ThisPin_NotMount__,
/*P18_2*/__ThisPin_NotMount__,
/*P18_3*/__ThisPin_NotMount__,
/*P18_4*/__ThisPin_NotMount__,
/*P18_5*/__ThisPin_NotMount__,
/*P18_6*/__ThisPin_NotMount__,
/*P18_7*/__ThisPin_NotMount__,
/*P18_8*/__ThisPin_NotMount__,
/*P18_9*/__ThisPin_NotMount__,
/*P18_10*/__ThisPin_NotMount__,
/*P18_11*/__ThisPin_NotMount__,
/*P18_12*/__ThisPin_NotMount__,
/*P18_13*/__ThisPin_NotMount__,
/*P18_14*/__ThisPin_NotMount__,
/*P18_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 19*/
/*##################*/
/*P19_0*/__ThisPin_NotMount__,
/*P19_1*/__ThisPin_NotMount__,
/*P19_2*/__ThisPin_NotMount__,
/*P19_3*/__ThisPin_NotMount__,
/*P19_4*/__ThisPin_NotMount__,
/*P19_5*/__ThisPin_NotMount__,
/*P19_6*/__ThisPin_NotMount__,
/*P19_7*/__ThisPin_NotMount__,
/*P19_8*/__ThisPin_NotMount__,
/*P19_9*/__ThisPin_NotMount__,
/*P19_10*/__ThisPin_NotMount__,
/*P19_11*/__ThisPin_NotMount__,
/*P19_12*/__ThisPin_NotMount__,
/*P19_13*/__ThisPin_NotMount__,
/*P19_14*/__ThisPin_NotMount__,
/*P19_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 20*/
/*##################*/
/*P20_0*/__ThisPin_NotMount__,
/*P20_1*/__ThisPin_NotMount__,
/*P20_2*/__ThisPin_NotMount__,
/*P20_3*/__ThisPin_NotMount__,
/*P20_4*/__ThisPin_NotMount__,
/*P20_5*/__ThisPin_NotMount__,
/*P20_6*/__ThisPin_NotMount__,
/*P20_7*/__ThisPin_NotMount__,
/*P20_8*/__ThisPin_NotMount__,
/*P20_9*/__ThisPin_NotMount__,
/*P20_10*/__ThisPin_NotMount__,
/*P20_11*/__ThisPin_NotMount__,
/*P20_12*/__ThisPin_NotMount__,
/*P20_13*/__ThisPin_NotMount__,
/*P20_14*/__ThisPin_NotMount__,
/*P20_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 21*/
/*##################*/
/*P21_0*/__ThisPin_NotMount__,	/*	1_O=>SFMA0CLK	2_I=>TAUB0I13	2_O=>TAUB0O13	3_O=>MCK							*/
/*P21_1*/__ThisPin_NotMount__,	/*	1_O=>SFMA0SSL	2_I=>TAUB0I11	2_O=>TAUB0O11	3_O=>MCS							*/
/*P21_2*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I00	1_O=>SFMA0O00	2_I=>TAUB0I10	2_O=>TAUB0O10	3_I=>MDQI0		3_O=>MDQO0							*/
/*P21_3*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I10	1_O=>SFMA0O10	2_I=>TAUB0I9	2_O=>TAUB0O9	3_I=>MDQI1		3_O=>MDQO1							*/
/*P21_4*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I20	1_O=>SFMA0O20	2_I=>TAUB0I7	2_O=>TAUB0O7	3_I=>MDQI2		3_O=>MDQO2							*/
/*P21_5*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I30	1_O=>SFMA0O30	2_I=>TAUB0I6	2_O=>TAUB0O6	3_I=>MDQI3		3_O=>MDQO3							*/
/*P21_6*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I01	1_O=>SFMA0O01	2_I=>TAUB0I5	2_O=>TAUB0O5	3_I=>MDQI4		3_O=>MDQO4							*/
/*P21_7*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I11	1_O=>SFMA0O11	2_I=>TAUB0I3	2_O=>TAUB0O3	3_I=>MDQI5		3_O=>MDQO5							*/
/*P21_8*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I21	1_O=>SFMA0O21	2_I=>TAUB0I2	2_O=>TAUB0O2	3_I=>MDQI6		3_O=>MDQO6							*/
/*P21_9*/__ThisPin_NotMount__,	/*	1_I=>SFMA0I31	1_O=>SFMA0O31	2_I=>TAUB0I1	2_O=>TAUB0O1	3_I=>MDQI7		3_O=>MDQO7							*/
/*P21_10*/__ThisPin_NotMount__,	/*	1_I=>MLBB0CLK	2_I=>TAUB0I4	2_O=>TAUB0O4	3_I=>TAUB0I0	3_O=>TAUB0O0							*/
/*P21_11*/__ThisPin_NotMount__,	/*	1_I=>MLBB0DAT	1_O=>MLBB0DAT	2_I=>TAUB0I14	2_O=>TAUB0O14									*/
/*P21_12*/__ThisPin_NotMount__,	/*	1_I=>MLBB0SIG	1_O=>MLBB0SIG	2_I=>TAUB0I15	2_O=>TAUB0O15									*/
/*P21_13*/__ThisPin_NotMount__,	/*													*/
/*P21_14*/__ThisPin_NotMount__,	/*													*/
/*P21_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 22*/
/*##################*/
/*P22_0*/__ThisPin_NotMount__,	/*													*/
/*P22_1*/__ThisPin_NotMount__,	/*													*/
/*P22_2*/__ThisPin_NotMount__,	/*													*/
/*P22_3*/__ThisPin_NotMount__,	/*													*/
/*P22_4*/__ThisPin_NotMount__,	/*													*/
/*P22_5*/__ThisPin_NotMount__,	/*													*/
/*P22_6*/__ThisPin_NotMount__,	/*													*/
/*P22_7*/__ThisPin_NotMount__,	/*													*/
/*P22_8*/__ThisPin_NotMount__,	/*													*/
/*P22_9*/__ThisPin_NotMount__,	/*													*/
/*P22_10*/__ThisPin_NotMount__,	/*	3_O=>MDQS										*/
/*P22_11*/__ThisPin_NotMount__,	/*													*/
/*P22_12*/__ThisPin_NotMount__,	/*													*/
/*P22_13*/__ThisPin_NotMount__,	/*													*/
/*P22_14*/__ThisPin_NotMount__,	/*													*/
/*P22_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 23*/
/*##################*/
/*P23_0*/__ThisPin_NotMount__,
/*P23_1*/__ThisPin_NotMount__,
/*P23_2*/__ThisPin_NotMount__,
/*P23_3*/__ThisPin_NotMount__,
/*P23_4*/__ThisPin_NotMount__,
/*P23_5*/__ThisPin_NotMount__,
/*P23_6*/__ThisPin_NotMount__,
/*P23_7*/__ThisPin_NotMount__,
/*P23_8*/__ThisPin_NotMount__,
/*P23_9*/__ThisPin_NotMount__,
/*P23_10*/__ThisPin_NotMount__,
/*P23_11*/__ThisPin_NotMount__,
/*P23_12*/__ThisPin_NotMount__,
/*P23_13*/__ThisPin_NotMount__,
/*P23_14*/__ThisPin_NotMount__,
/*P23_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 24*/
/*##################*/
/*P24_0*/__ThisPin_NotMount__,
/*P24_1*/__ThisPin_NotMount__,
/*P24_2*/__ThisPin_NotMount__,
/*P24_3*/__ThisPin_NotMount__,
/*P24_4*/__ThisPin_NotMount__,
/*P24_5*/__ThisPin_NotMount__,
/*P24_6*/__ThisPin_NotMount__,
/*P24_7*/__ThisPin_NotMount__,
/*P24_8*/__ThisPin_NotMount__,
/*P24_9*/__ThisPin_NotMount__,
/*P24_10*/__ThisPin_NotMount__,
/*P24_11*/__ThisPin_NotMount__,
/*P24_12*/__ThisPin_NotMount__,
/*P24_13*/__ThisPin_NotMount__,
/*P24_14*/__ThisPin_NotMount__,
/*P24_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 25*/
/*##################*/
/*P25_0*/__ThisPin_NotMount__,
/*P25_1*/__ThisPin_NotMount__,
/*P25_2*/__ThisPin_NotMount__,
/*P25_3*/__ThisPin_NotMount__,
/*P25_4*/__ThisPin_NotMount__,
/*P25_5*/__ThisPin_NotMount__,
/*P25_6*/__ThisPin_NotMount__,
/*P25_7*/__ThisPin_NotMount__,
/*P25_8*/__ThisPin_NotMount__,
/*P25_9*/__ThisPin_NotMount__,
/*P25_10*/__ThisPin_NotMount__,
/*P25_11*/__ThisPin_NotMount__,
/*P25_12*/__ThisPin_NotMount__,
/*P25_13*/__ThisPin_NotMount__,
/*P25_14*/__ThisPin_NotMount__,
/*P25_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 26*/
/*##################*/
/*P26_0*/__ThisPin_NotMount__,
/*P26_1*/__ThisPin_NotMount__,
/*P26_2*/__ThisPin_NotMount__,
/*P26_3*/__ThisPin_NotMount__,
/*P26_4*/__ThisPin_NotMount__,
/*P26_5*/__ThisPin_NotMount__,
/*P26_6*/__ThisPin_NotMount__,
/*P26_7*/__ThisPin_NotMount__,
/*P26_8*/__ThisPin_NotMount__,
/*P26_9*/__ThisPin_NotMount__,
/*P26_10*/__ThisPin_NotMount__,
/*P26_11*/__ThisPin_NotMount__,
/*P26_12*/__ThisPin_NotMount__,
/*P26_13*/__ThisPin_NotMount__,
/*P26_14*/__ThisPin_NotMount__,
/*P26_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 27*/
/*##################*/
/*P27_0*/__ThisPin_NotMount__,
/*P27_1*/__ThisPin_NotMount__,
/*P27_2*/__ThisPin_NotMount__,
/*P27_3*/__ThisPin_NotMount__,
/*P27_4*/__ThisPin_NotMount__,
/*P27_5*/__ThisPin_NotMount__,
/*P27_6*/__ThisPin_NotMount__,
/*P27_7*/__ThisPin_NotMount__,
/*P27_8*/__ThisPin_NotMount__,
/*P27_9*/__ThisPin_NotMount__,
/*P27_10*/__ThisPin_NotMount__,
/*P27_11*/__ThisPin_NotMount__,
/*P27_12*/__ThisPin_NotMount__,
/*P27_13*/__ThisPin_NotMount__,
/*P27_14*/__ThisPin_NotMount__,
/*P27_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 28*/
/*##################*/
/*P28_0*/__ThisPin_NotMount__,
/*P28_1*/__ThisPin_NotMount__,
/*P28_2*/__ThisPin_NotMount__,
/*P28_3*/__ThisPin_NotMount__,
/*P28_4*/__ThisPin_NotMount__,
/*P28_5*/__ThisPin_NotMount__,
/*P28_6*/__ThisPin_NotMount__,
/*P28_7*/__ThisPin_NotMount__,
/*P28_8*/__ThisPin_NotMount__,
/*P28_9*/__ThisPin_NotMount__,
/*P28_10*/__ThisPin_NotMount__,
/*P28_11*/__ThisPin_NotMount__,
/*P28_12*/__ThisPin_NotMount__,
/*P28_13*/__ThisPin_NotMount__,
/*P28_14*/__ThisPin_NotMount__,
/*P28_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 29*/
/*##################*/
/*P29_0*/__ThisPin_NotMount__,
/*P29_1*/__ThisPin_NotMount__,
/*P29_2*/__ThisPin_NotMount__,
/*P29_3*/__ThisPin_NotMount__,
/*P29_4*/__ThisPin_NotMount__,
/*P29_5*/__ThisPin_NotMount__,
/*P29_6*/__ThisPin_NotMount__,
/*P29_7*/__ThisPin_NotMount__,
/*P29_8*/__ThisPin_NotMount__,
/*P29_9*/__ThisPin_NotMount__,
/*P29_10*/__ThisPin_NotMount__,
/*P29_11*/__ThisPin_NotMount__,
/*P29_12*/__ThisPin_NotMount__,
/*P29_13*/__ThisPin_NotMount__,
/*P29_14*/__ThisPin_NotMount__,
/*P29_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 30*/
/*##################*/
/*P30_0*/__ThisPin_NotMount__,
/*P30_1*/__ThisPin_NotMount__,
/*P30_2*/__ThisPin_NotMount__,
/*P30_3*/__ThisPin_NotMount__,
/*P30_4*/__ThisPin_NotMount__,
/*P30_5*/__ThisPin_NotMount__,
/*P30_6*/__ThisPin_NotMount__,
/*P30_7*/__ThisPin_NotMount__,
/*P30_8*/__ThisPin_NotMount__,
/*P30_9*/__ThisPin_NotMount__,
/*P30_10*/__ThisPin_NotMount__,
/*P30_11*/__ThisPin_NotMount__,
/*P30_12*/__ThisPin_NotMount__,
/*P30_13*/__ThisPin_NotMount__,
/*P30_14*/__ThisPin_NotMount__,
/*P30_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 31*/
/*##################*/
/*P31_0*/__ThisPin_NotMount__,
/*P31_1*/__ThisPin_NotMount__,
/*P31_2*/__ThisPin_NotMount__,
/*P31_3*/__ThisPin_NotMount__,
/*P31_4*/__ThisPin_NotMount__,
/*P31_5*/__ThisPin_NotMount__,
/*P31_6*/__ThisPin_NotMount__,
/*P31_7*/__ThisPin_NotMount__,
/*P31_8*/__ThisPin_NotMount__,
/*P31_9*/__ThisPin_NotMount__,
/*P31_10*/__ThisPin_NotMount__,
/*P31_11*/__ThisPin_NotMount__,
/*P31_12*/__ThisPin_NotMount__,
/*P31_13*/__ThisPin_NotMount__,
/*P31_14*/__ThisPin_NotMount__,
/*P31_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 32*/
/*##################*/
/*P32_0*/__ThisPin_NotMount__,
/*P32_1*/__ThisPin_NotMount__,
/*P32_2*/__ThisPin_NotMount__,
/*P32_3*/__ThisPin_NotMount__,
/*P32_4*/__ThisPin_NotMount__,
/*P32_5*/__ThisPin_NotMount__,
/*P32_6*/__ThisPin_NotMount__,
/*P32_7*/__ThisPin_NotMount__,
/*P32_8*/__ThisPin_NotMount__,
/*P32_9*/__ThisPin_NotMount__,
/*P32_10*/__ThisPin_NotMount__,
/*P32_11*/__ThisPin_NotMount__,
/*P32_12*/__ThisPin_NotMount__,
/*P32_13*/__ThisPin_NotMount__,
/*P32_14*/__ThisPin_NotMount__,
/*P32_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 33*/
/*##################*/
/*P33_0*/__ThisPin_NotMount__,
/*P33_1*/__ThisPin_NotMount__,
/*P33_2*/__ThisPin_NotMount__,
/*P33_3*/__ThisPin_NotMount__,
/*P33_4*/__ThisPin_NotMount__,
/*P33_5*/__ThisPin_NotMount__,
/*P33_6*/__ThisPin_NotMount__,
/*P33_7*/__ThisPin_NotMount__,
/*P33_8*/__ThisPin_NotMount__,
/*P33_9*/__ThisPin_NotMount__,
/*P33_10*/__ThisPin_NotMount__,
/*P33_11*/__ThisPin_NotMount__,
/*P33_12*/__ThisPin_NotMount__,
/*P33_13*/__ThisPin_NotMount__,
/*P33_14*/__ThisPin_NotMount__,
/*P33_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 34*/
/*##################*/
/*P34_0*/__ThisPin_NotMount__,
/*P34_1*/__ThisPin_NotMount__,
/*P34_2*/__ThisPin_NotMount__,
/*P34_3*/__ThisPin_NotMount__,
/*P34_4*/__ThisPin_NotMount__,
/*P34_5*/__ThisPin_NotMount__,
/*P34_6*/__ThisPin_NotMount__,
/*P34_7*/__ThisPin_NotMount__,
/*P34_8*/__ThisPin_NotMount__,
/*P34_9*/__ThisPin_NotMount__,
/*P34_10*/__ThisPin_NotMount__,
/*P34_11*/__ThisPin_NotMount__,
/*P34_12*/__ThisPin_NotMount__,
/*P34_13*/__ThisPin_NotMount__,
/*P34_14*/__ThisPin_NotMount__,
/*P34_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 35*/
/*##################*/
/*P35_0*/__ThisPin_NotMount__,
/*P35_1*/__ThisPin_NotMount__,
/*P35_2*/__ThisPin_NotMount__,
/*P35_3*/__ThisPin_NotMount__,
/*P35_4*/__ThisPin_NotMount__,
/*P35_5*/__ThisPin_NotMount__,
/*P35_6*/__ThisPin_NotMount__,
/*P35_7*/__ThisPin_NotMount__,
/*P35_8*/__ThisPin_NotMount__,
/*P35_9*/__ThisPin_NotMount__,
/*P35_10*/__ThisPin_NotMount__,
/*P35_11*/__ThisPin_NotMount__,
/*P35_12*/__ThisPin_NotMount__,
/*P35_13*/__ThisPin_NotMount__,
/*P35_14*/__ThisPin_NotMount__,
/*P35_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 36*/
/*##################*/
/*P36_0*/__ThisPin_NotMount__,
/*P36_1*/__ThisPin_NotMount__,
/*P36_2*/__ThisPin_NotMount__,
/*P36_3*/__ThisPin_NotMount__,
/*P36_4*/__ThisPin_NotMount__,
/*P36_5*/__ThisPin_NotMount__,
/*P36_6*/__ThisPin_NotMount__,
/*P36_7*/__ThisPin_NotMount__,
/*P36_8*/__ThisPin_NotMount__,
/*P36_9*/__ThisPin_NotMount__,
/*P36_10*/__ThisPin_NotMount__,
/*P36_11*/__ThisPin_NotMount__,
/*P36_12*/__ThisPin_NotMount__,
/*P36_13*/__ThisPin_NotMount__,
/*P36_14*/__ThisPin_NotMount__,
/*P36_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 37*/
/*##################*/
/*P37_0*/__ThisPin_NotMount__,
/*P37_1*/__ThisPin_NotMount__,
/*P37_2*/__ThisPin_NotMount__,
/*P37_3*/__ThisPin_NotMount__,
/*P37_4*/__ThisPin_NotMount__,
/*P37_5*/__ThisPin_NotMount__,
/*P37_6*/__ThisPin_NotMount__,
/*P37_7*/__ThisPin_NotMount__,
/*P37_8*/__ThisPin_NotMount__,
/*P37_9*/__ThisPin_NotMount__,
/*P37_10*/__ThisPin_NotMount__,
/*P37_11*/__ThisPin_NotMount__,
/*P37_12*/__ThisPin_NotMount__,
/*P37_13*/__ThisPin_NotMount__,
/*P37_14*/__ThisPin_NotMount__,
/*P37_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 38*/
/*##################*/
/*P38_0*/__ThisPin_NotMount__,
/*P38_1*/__ThisPin_NotMount__,
/*P38_2*/__ThisPin_NotMount__,
/*P38_3*/__ThisPin_NotMount__,
/*P38_4*/__ThisPin_NotMount__,
/*P38_5*/__ThisPin_NotMount__,
/*P38_6*/__ThisPin_NotMount__,
/*P38_7*/__ThisPin_NotMount__,
/*P38_8*/__ThisPin_NotMount__,
/*P38_9*/__ThisPin_NotMount__,
/*P38_10*/__ThisPin_NotMount__,
/*P38_11*/__ThisPin_NotMount__,
/*P38_12*/__ThisPin_NotMount__,
/*P38_13*/__ThisPin_NotMount__,
/*P38_14*/__ThisPin_NotMount__,
/*P38_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 39*/
/*##################*/
/*P39_0*/__ThisPin_NotMount__,
/*P39_1*/__ThisPin_NotMount__,
/*P39_2*/__ThisPin_NotMount__,
/*P39_3*/__ThisPin_NotMount__,
/*P39_4*/__ThisPin_NotMount__,
/*P39_5*/__ThisPin_NotMount__,
/*P39_6*/__ThisPin_NotMount__,
/*P39_7*/__ThisPin_NotMount__,
/*P39_8*/__ThisPin_NotMount__,
/*P39_9*/__ThisPin_NotMount__,
/*P39_10*/__ThisPin_NotMount__,
/*P39_11*/__ThisPin_NotMount__,
/*P39_12*/__ThisPin_NotMount__,
/*P39_13*/__ThisPin_NotMount__,
/*P39_14*/__ThisPin_NotMount__,
/*P39_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 40*/
/*##################*/
/*P40_0*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_ DATA0P							*/
/*P40_1*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_ DATA0N							*/
/*P40_2*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_DATA1P							*/
/*P40_3*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_DATA1N							*/
/*P40_4*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_CLKP								*/
/*P40_5*/__ThisPin_NotMount__,	/*	1_I=>MIPI0_VI_CLKN								*/
/*P40_6*/__ThisPin_NotMount__,	/*													*/
/*P40_7*/__ThisPin_NotMount__,	/*													*/
/*P40_8*/__ThisPin_NotMount__,	/*													*/
/*P40_9*/__ThisPin_NotMount__,	/*													*/
/*P40_10*/__ThisPin_NotMount__,	/*													*/
/*P40_11*/__ThisPin_NotMount__,	/*													*/
/*P40_12*/__ThisPin_NotMount__,	/*													*/
/*P40_13*/__ThisPin_NotMount__,	/*													*/
/*P40_14*/__ThisPin_NotMount__,	/*													*/
/*P40_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 41*/
/*##################*/
/*P41_0*/__ThisPin_NotMount__,
/*P41_1*/__ThisPin_NotMount__,
/*P41_2*/__ThisPin_NotMount__,
/*P41_3*/__ThisPin_NotMount__,
/*P41_4*/__ThisPin_NotMount__,
/*P41_5*/__ThisPin_NotMount__,
/*P41_6*/__ThisPin_NotMount__,
/*P41_7*/__ThisPin_NotMount__,
/*P41_8*/__ThisPin_NotMount__,
/*P41_9*/__ThisPin_NotMount__,
/*P41_10*/__ThisPin_NotMount__,
/*P41_11*/__ThisPin_NotMount__,
/*P41_12*/__ThisPin_NotMount__,
/*P41_13*/__ThisPin_NotMount__,
/*P41_14*/__ThisPin_NotMount__,
/*P41_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 42*/
/*##################*/	
/*P42_0*/__ThisPin_NotMount__,	/*	1_O=>ETNB0TXD3		2_I=>VDCE0_VI_DATA7_ITU	2_O=>PWGA0O	3_I=>VDCE0_VI DATA17	3_O=>TAUB2O1	4_I=>RIIC1SDA	4_O=>RIIC1SDA	5_O=>NAND_CE	6_O=>SFMA1CLK	*/
/*P42_1*/__ThisPin_NotMount__,	/*	1_O=>ETNB0TXD2		2_I=>VDCE0_VI_DATA6_ITU	2_O=>PWGA1O	3_I=>VDCE0_VI_ DATA16	3_O=>TAUB2O3	4_I=>RIIC1SCL	4_O=>RIIC1SCL	5_O=>NAND_CLE	6_O=>SFMA1SSL	*/
/*P42_2*/__ThisPin_NotMount__,	/*	1_O=>ETNB0TXD1		2_I=>VDCE0_VI_DATA5_ITU	2_O=>PWGA2O	3_I=>VDCE0_VI_DATA15	3_O=>TAUB2O5	4_I=>CSIG0SSI	5_O=>NAND_ALE	6_I=>SFMA1I00	6_O=>SFMA1O00	*/
/*P42_3*/__ThisPin_NotMount__,	/*	1_I=>CSIH0SSI		1_O=>ETNB0TXD0			2_I=>VDCE0_VI_DATA4_ITU	2_O=>PWGA3O	3_I=>VDCE0_VI_DATA14	3_O=>TAUB2O7	4_O=>CSIG0SO	5_O=>NAND_REB		6_I=>SFMA1I10	6_O=>SFMA1O10	*/
/*P42_4*/__ThisPin_NotMount__,	/*	1_I=>CSIH1SSI		1_O=>ETNB0TXEN			2_I=>VDCE0_VI_DATA3_ITU	2_O=>PWGA4O	3_I=>VDCE0_VI_DATA13	3_O=>TAUB2O2	4_I=>CSIG0SI		5_O=>NAND_WEB		6_I=>SFMA1I20	6_O=>SFMA1O20	*/
/*P42_5*/__ThisPin_NotMount__,	/*	1_I=>CSIG2SSI		1_O=>ETNB0TXER			2_I=>VDCE0_VI_DATA2_ITU	2_O=>PWGA5O	3_I=>VDCE0_VI_DATA12	3_O=>TAUB2O6	4_I=>CSIG0SC	4_O=>CSIG0SC	5_I=>NAND_RB0		6_I=>SFMA1I30	6_O=>SFMA1O30					*/
/*P42_6*/__ThisPin_NotMount__,	/*	1_I=>ETNB0COL		2_I=>VDCE0_VI_DATA1_ITU	2_O=>PWGA6O	3_I=>VDCE0_VI_DATA11	3_O=>TAUB2O9			4_I=>CSIG3RYI	4_O=>CSIG3RYO	5_I=>NAND_DI[0]	5_O=>NAND_DO[0]	6_I=>SFMA1I01	6_O=>SFMA1O01					*/
/*P42_7*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 CRSDV	1_O=>SG3FAOL			2_I=>VDCE0_VI_DATA0_ITU	2_O=>PWGA12O	3_I=>VDCE0_VI_DATA10	3_O=>TAUB1O6	4_I=>CSIG3SSI	4_O=>SG3AO		5_I=>NAND_DI[1]		5_O=>NAND_DO[1]6_I=>SFMA1I11	6_O=>SFMA1O11	*/
/*P42_8*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 TXCLK	1_O=>SG3FAO			2_I=>VDCE0_VI_CLK		2_O=>PWGA13O	3_I=>VDCE0_VI_DATA9	3_O=>TAUB0O15		4_O=>CSIG3SO	5_I=>NAND_DI[2]	5_O=>NAND_DO[2]	6_I=>SFMA1I21	6_O=>SFMA1O21					*/
/*P42_9*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXCLK	1_O=>SG4FAOL			2_I=>VDCE0_VI_HSYNC		2_O=>PWGA14O	3_I=>VDCE0_VI_DATA8	3_O=>TAUB1O2	4_I=>CSIG3SI		4_O=>SG4AO		5_I=>NAND_DI[3]		5_O=>NAND_DO[3]	6_I=>SFMA1I31	6_O=>SFMA1O31	*/
/*P42_10*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXD3		1_O=>SG4FAO			2_I=>VDCE0_VI_VSYNC		2_O=>PWGA15O	3_I=>VDCE0_VI_DATA7	3_O=>TAUB1O10	4_I=>CSIG3SC	4_O=>CSIG3SC	5_I=>NAND_DI[4]		5_O=>NAND_DO[4]	6_I=>CSIG3SC	6_O=>CSIG3SC	*/
/*P42_11*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXD2		1_O=>VDCE0_VO_TCON3	2_I=>TAUB2I9			2_O=>PWGA7O	3_I=>VDCE0_VI_DATA6	3_O=>TAUB2O10	4_I=>TAUB0I14	4_O=>TAUB0O14	5_I=>NAND_DI[5]		5_O=>NAND_DO[5]	6_I=>CSIG3SI						*/
/*P42_12*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXD1		1_O=>VDCE0_VO_TCON1	2_I=>TAUB2I10			2_O=>PWGA8O	3_I=>VDCE0_VI_DATA5	3_O=>TAUB2O11	4_I=>TAUJ0I2	4_O=>TAUJ0O2	5_I=>NAND_DI[6]		5_O=>NAND_DO[6]	6_O=>CSIG3SO					*/
/*P42_13*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXD0		1_O=>VDCE0_VO_TCON4	2_I=>TAUB2I11			2_O=>PWGA9O	3_I=>VDCE0_VI_DATA4	3_O=>TAUB2O13	4_I=>TAUJ0I3	4_O=>TAUJ0O3	5_I=>NAND_DI[7]		5_O=>NAND_DO[7]	6_I=>CSIG3SSI					*/
/*P42_14*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXDV		1_O=>VDCE0_VO_TCON5	2_I=>ADCE0 TRIGI1		2_O=>PWGA10O	3_I=>VDCE0_VI_DATA3	3_O=>TAUB2O14	4_I=>TAUB1I2	5_I=>INTP7				*/
/*P42_15*/__ThisPin_NotMount__,	/*	1_I=>ETNB0 RXER		1_O=>VDCE0_VO_TCON6	2_I=>ADCE0 TRIGI2		2_O=>PWGA11O	3_I=>VDCE0_VI_DATA2	3_O=>TAUB2O15	4_I=>TAUB1I10	5_I=>INTP4				*/



/*##################*/
/*Pin ID =====Port 43*/
/*##################*/
/*P43_0*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON2	2_O=>VDCE0_VO_TCON3	3_O=>LCBI0 HSYNC	4_O=>LCBI0CS					*/
/*P43_1*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON0	3_O=>LCBI0 VSYNC		4_O=>LCBI0WRRW				*/
/*P43_2*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON3	2_I=>VDCE1_VI_DATA7_ITU										*/
/*P43_3*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON1	2_I=>VDCE1_VI_DATA6_ITU										*/
/*P43_4*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON4	2_I=>VDCE1_VI_DATA5_ITU										*/
/*P43_5*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON5	2_I=>VDCE1_VI_DATA4_ITU										*/
/*P43_6*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_TCON6	2_I=>VDCE1_VI_DATA3_ITU		2_O=>VDCE1_VO_TCON3									*/
/*P43_7*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA23	2_I=>VDCE1_VI_DATA2_ITU		3_I=>VDCE0_VI_DATA2_ITU		4_I=>TAUB0I9	4_O=>TAUB0O9					*/
/*P43_8*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA22	2_I=>VDCE1_VI_DATA1_ITU		3_I=>VDCE0_VI_DATA1_ITU		4_I=>TAUB0I10	4_O=>TAUB0O10					*/
/*P43_9*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA21	2_I=>VDCE1_VI_DATA0_ITU		3_I=>VDCE0_VI_DATA0_ITU		4_I=>TAUB0I11	4_O=>TAUB0O11					*/
/*P43_10*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA20	2_I=>VDCE1_VI_CLK			3_I=>VDCE0_VI_CLK			4_I=>TAUB0I13	4_O=>TAUB0O13					*/
/*P43_11*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA19	2_I=>VDCE1_VI_HSYNC			3_I=>VDCE0_VI_HSYNC			4_I=>TAUB0I14	4_O=>TAUB0O14					*/
/*P43_12*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA18	2_I=>VDCE1_VI_VSYNC			3_I=>VDCE0_VI_VSYNC			4_I=>TAUB0I15	4_O=>TAUB0O15					*/
/*P43_13*/__ThisPin_NotMount__,	/*													*/
/*P43_14*/__ThisPin_NotMount__,	/*													*/
/*P43_15*/__ThisPin_NotMount__,	/*													*/



/*##################*/
/*Pin ID =====Port 44*/
/*##################*/	
/*P44_0*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA23	4_I=>CSIG2RYI			4_O=>CSIG2RYO																	*/
/*P44_1*/__ThisPin_NotMount__,	/*	1_I=>TAUB1I10			1_O=>VDCE0_VO_DATA22	3_I=>VDCE0_VI_DATA1	3_O=>LCBI0RDE		4_I=>CSIG2SSI	4_O=>TAUB1O10					*/
/*P44_2*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA21	2_I=>RIIC0SDA			2_O=>RIIC0SDA		3_I=>VDCE0_VI_DATA0	3_O=>LCBI0A0DE	4_O=>CSIG2SO					*/
/*P44_3*/__ThisPin_NotMount__,	/*	1_I=>TAUB1I11			1_O=>VDCE0_VO_DATA20	2_I=>RIIC0SCL		2_O=>RIIC0SCL		3_I=>VDCE0_VI_CLK	3_O=>LCBI0CS	4_I=>CSIG2SI	4_O=>TAUB1O11					*/
/*P44_4*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA19	2_O=>PWGA14O		3_I=>VDCE0_VI_HSYNC		3_O=>LCBI0 WRRW	4_I=>CSIG2SC	4_O=>CSIG2SC					*/
/*P44_5*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA18	2_O=>PWGA15O		3_I=>VDCE0_VI_VSYNC																				*/
/*P44_6*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA17	2_I=>INTP3			2_O=>PWGA0O	3_I=>LCBI0D0			3_O=>LCBI0D0		4_I=>CSIG3SSI	4_O=>RLIN33TX					*/
/*P44_7*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA16	2_I=>RLIN33RX/INTP4	2_O=>PWGA1O	3_I=>LCBI0D1			3_O=>LCBI0D1		4_O=>CSIG3SO					*/
/*P44_8*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA15	2_I=>NMI			2_O=>PWGA2O	3_I=>LCBI0D2			3_O=>LCBI0D2		4_I=>CSIG3SI		4_O=>TAUB2O4					*/
/*P44_9*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA14	2_I=>INTP1			2_O=>PWGA3O	3_I=>LCBI0D3			3_O=>LCBI0D3		4_I=>CSIG3SC	4_O=>CSIG3SC					*/
/*P44_10*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA13	2_I=>INTP5			2_O=>PWGA4O	3_I=>LCBI0D4			3_O=>LCBI0D4		4_I=>RIIC1SDA	4_O=>RIIC1SDA					*/
/*P44_11*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA12	2_I=>INTP7			2_O=>PWGA5O	3_I=>LCBI0D5			3_O=>LCBI0D5		4_I=>RIIC1SCL	4_O=>RIIC1SCL					*/
/*P44_12*/__ThisPin_NotMount__,	/*													*/
/*P44_13*/__ThisPin_NotMount__,	/*													*/
/*P44_14*/__ThisPin_NotMount__,	/*													*/
/*P44_15*/__ThisPin_NotMount__,	/*													*/



/*##################*/
/*Pin ID =====Port 45*/
/*##################*/
/*P45_0*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_CLKP		2_O=>PWGA13O	3_I=>ADCE0 TRIGI1	3_O=>LCBI0RDE	4_I=>TAUB2I6	4_O=>TAUB2O6					*/
/*P45_1*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_CLKN		2_O=>PWGA12O	3_I=>ADCE0 TRIGI2	3_O=>LCBI0A0DE	4_I=>TAUB2I8	4_O=>VDCE0_VO_TCON3			*/
/*P45_2*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA11	2_O=>PWGA6O	3_I=>LCBI0D6		3_O=>LCBI0D6	4_I=>CSIG0SSI	4_O=>TAUB2O12					*/
/*P45_3*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA10	2_O=>PWGA7O	3_I=>LCBI0D7		3_O=>LCBI0D7	4_O=>CSIG0SO					*/
/*P45_4*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA9	2_O=>PWGA8O	3_I=>LCBI0D8		3_O=>LCBI0D8	4_I=>CSIG0SI		4_O=>TAUB2O10					*/
/*P45_5*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA8	2_O=>PWGA9O	3_I=>LCBI0D9		3_O=>LCBI0D9	4_I=>CSIG0SC	4_O=>CSIG0SC					*/
/*P45_6*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA7	2_O=>PWGA10O	3_I=>LCBI0D10		3_O=>LCBI0D10	4_I=>TAUJ0I2	4_O=>TAUJ0O2					*/
/*P45_7*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA6	2_O=>PWGA11O	3_I=>LCBI0D11		3_O=>LCBI0D11	4_I=>TAUJ0I3	4_O=>TAUJ0O3					*/
/*P45_8*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I2	1_O=>VDCE0_VO_DATA5	2_O=>TAUB1O3*1		3_I=>LCBI0D12	3_O=>LCBI0D12	4_I=>TAUB1I3	4_O=>TAUB0O2					*/
/*P45_9*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I6	1_O=>VDCE0_VO_DATA4	2_O=>TAUB1O5*1		3_I=>LCBI0D13	3_O=>LCBI0D13	4_I=>TAUB1I5	4_O=>TAUB0O6					*/
/*P45_10*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I10	1_O=>VDCE0_VO_DATA3	2_O=>TAUB1O7*1		3_I=>LCBI0D14	3_O=>LCBI0D14	4_I=>CSIG1SSI	4_O=>TAUB0O10					*/
/*P45_11*/__ThisPin_NotMount__,	/*	1_I=>TAUB0I14	1_O=>VDCE0_VO_DATA2	2_O=>TAUB1O9*1		3_I=>LCBI0D15	3_O=>LCBI0D15	4_I=>CSIG1SI		4_O=>TAUB0O14					*/
/*P45_12*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA1	3_I=>LCBI0D16	3_O=>LCBI0D16		4_O=>CSIG1SO					*/
/*P45_13*/__ThisPin_NotMount__,	/*	1_O=>VDCE0_VO_DATA0	3_I=>LCBI0D17	3_O=>LCBI0D17		4_I=>CSIG1SC	4_O=>CSIG1SC					*/
/*P45_14*/__ThisPin_NotMount__,	/*													*/
/*P45_15*/__ThisPin_NotMount__,	/*													*/


/*##################*/
/*Pin ID =====Port 46*/
/*##################*/
/*P46_0*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA23	1_O=>VDCE1_VO_DATA23	2_I=>VDCE1_VI_DATA7_ITU	2_O=>VDCE1_VO_TCON3	3_I=>VDCE0_VI_DATA7_ITU								*/
/*P46_1*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA22	1_O=>VDCE1_VO_DATA22	2_I=>VDCE1_VI_DATA6_ITU	2_O=>VDCE1_VO_TCON1	3_I=>VDCE0_VI_DATA6_ITU								*/
/*P46_2*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA21	1_O=>VDCE1_VO_DATA21	2_I=>VDCE1_VI_DATA5_ITU	2_O=>VDCE1_VO_TCON4	3_I=>VDCE0_VI_DATA5_ITU								*/
/*P46_3*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA20	1_O=>VDCE1_VO_DATA20	2_I=>VDCE1_VI_DATA4_ITU	2_O=>VDCE1_VO_TCON5	3_I=>VDCE0_VI_DATA4_ITU								*/
/*P46_4*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA19	1_O=>VDCE1_VO_DATA19	2_I=>VDCE1_VI_DATA3_ITU	2_O=>VDCE1_VO_TCON6	3_I=>VDCE0_VI_DATA3_ITU								*/
/*P46_5*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA18	1_O=>VDCE1_VO_DATA18											*/
/*P46_6*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA17	1_O=>VDCE1_VO_DATA17	2_O=>ETNB0TXD3									*/
/*P46_7*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA16	1_O=>VDCE1_VO_DATA16	2_O=>ETNB0TXD2									*/
/*P46_8*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA15	1_O=>VDCE1_VO_DATA15	2_O=>ETNB0TXD1									*/
/*P46_9*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA14	1_O=>VDCE1_VO_DATA14	2_O=>ETNB0TXD0									*/
/*P46_10*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA13	1_O=>VDCE1_VO_DATA13	2_O=>ETNB0TXEN									*/
/*P46_11*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA12	1_O=>VDCE1_VO_DATA12	2_O=>ETNB0TXER									*/
/*P46_12*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA11	1_O=>VDCE1_VO_DATA11	2_I=>ETNB0 COL										*/
/*P46_13*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA10	1_O=>VDCE1_VO_DATA10	2_I=>ETNB0 CRSDV										*/
/*P46_14*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA9		1_O=>VDCE1_VO_DATA9	2_I=>ETNB0 TXCLK										*/
/*P46_15*/__ThisPin_NotMount__,	/*	1_I=>VDCE1_VI_DATA8		1_O=>VDCE1_VO_DATA8	2_I=>ETNB0 RXCLK										*/


};

#define JPinConf(AltFun,PinResetLevel)	 PinConf(AltFun,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_JPort[MCU_MaxJPortMount*MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	PinFill_0}
*************************************************************************************/
/*##################*/
/*Pin ID =====JPort 0*/
/*##################*/	
/*JP0_0*/__ThisPin_NotMount__,	/*	1_I=>INTP0	2_I=>TAUB2I8	2_O=>TAUB2O8	3_I=>FLSCI3RXD	3_O=>FLSCI3TXD							*/
/*JP0_1*/__ThisPin_NotMount__,	/*	1_I=>INTP9	2_I=>TAUB1I6	2_O=>TAUB1O6	3_O=>FLSCI3TXD							*/
/*JP0_2*/__ThisPin_NotMount__,	/*	1_I=>INTP7	2_I=>TAUB1I12	2_O=>TAUB1O12	3_I=>FLSCI3SCKI	4_O=>ERROROUT			*/
/*JP0_3*/__ThisPin_NotMount__,	/*	1_I=>INTP3	1_O=>RLIN33TX	2_I=>TAUJ0I2	2_O=>TAUJ0O2	3_O=>CSCXFOUT							*/
/*JP0_4*/__ThisPin_NotMount__,	/*																												*/
/*JP0_5*/__ThisPin_NotMount__,	/*	1_I=>RLIN33RX/INTP4			2_I=>TAUJ0I3	2_O=>TAUJ0O3	3_O=>RTCA0OUT							*/
/*JP0_6*/__ThisPin_NotMount__,	/*													*/
/*JP0_7*/__ThisPin_NotMount__,	/*													*/
/*JP0_8*/__ThisPin_NotMount__,	/*													*/
/*JP0_9*/__ThisPin_NotMount__,	/*													*/
/*JP0_10*/__ThisPin_NotMount__,	/*													*/
/*JP0_11*/__ThisPin_NotMount__,	/*													*/
/*JP0_12*/__ThisPin_NotMount__,	/*													*/
/*JP0_13*/__ThisPin_NotMount__,	/*													*/
/*JP0_14*/__ThisPin_NotMount__,	/*													*/
/*JP0_15*/__ThisPin_NotMount__,	/*													*/

};

#if (MCU_mOSTMModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		OSTM setting   
			@@@@@@@@@@		  
####################################################*/

#define __ThisOSTM_NotMount__			{0u,0u,MCU_vNotExpINT}
#define OSTMconfig(tick_us, startWhenReset,callback)	{tick_us, startWhenReset,callback}

MCU_tstOSTM_UsrCfg MCU_stOSTMCfg[MCU_mOSTM_Mun]=
{
	{0,0,MCU_vNotExpINT},
	{0,0,MCU_vNotExpINT}
};
#endif



#if (MCU_mPWGAModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		PWGA setting   
			@@@@@@@@@@		  
####################################################*/
#define __ThisPWGA_NotMount__			{0xFFu,0u}
#define _Hz_NotUsed_			0xffffffff

#define PWGAconfig(FrequcySel,ResetDuty) {FrequcySel,ResetDuty}

MCU_tstPWGA_UsrCfg MCU_stPWGACfg=
{
	{
            	_Hz_NotUsed_,
            	_Hz_NotUsed_,
            	_Hz_NotUsed_,
            	_Hz_NotUsed_
	},/*frequency in HZ*/
	
	{	
		__ThisPWGA_NotMount__,// 0
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 9

		__ThisPWGA_NotMount__,// 10
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 19

		__ThisPWGA_NotMount__,// 20
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
	},

};
#endif

#if ((MCU_mTAUBDModuleEnable !=0u)||(MCU_mTAUJModuleEnable !=0u))
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		TAUX setting   
			@@@@@@@@@@		  
####################################################*/

#define __Timer_Not_Mount__				{0xffu,0,0,Not_Triggre,0,MCU_vNotExpINT}
#define Not_Triggre 0xff

#define TimerMode(ClkSel,interval_us,RunInRest,CB)			         {0u,ClkSel,interval_us,Not_Triggre,RunInRest,CB}
#define PinTriggerTimer(ClkSel,interval_us,Trigger,RunInRest,CB) 	{1u,ClkSel,interval_us,Trigger,RunInRest,CB}
#define FrequencyDivider(divider,RunInRest,CB)		                  {2u,0,divider,2/*TAUxTrige_BothEdge*/,RunInRest,CB} /*Not-valib in TAUJ !!!*/
#define CounterMode(ClkSel,counter,Trigger,RunInRest,CB)		{3u,ClkSel,counter,Trigger,RunInRest,CB}                        /*Not-valib in TAUJ !!!*/
#define OnePulseOutPut(ClkSel,Delay_us,Trigger,RunInRest)	         {4u,ClkSel,Delay_us,Trigger,MCU_vNotExpINT}               /*Not-valib in TAUJ !!!*/
#define PulseInterval(ClkSel,Trigger,RunInRest,CB)				{5u,ClkSel,0,Trigger,RunInRest,CB}
#define PulseWidth(ClkSel,Level,RunInRest,CB)				         {6u,ClkSel,0,Level,RunInRest,CB}
#define PulsePosition(ClkSel,Trigger,RunInRest,CB)				{7u,ClkSel,0,Trigger,RunInRest,CB}
#define PulseWidthCumulater(ClkSel,Level,RunInRest,CB)		         {8u,ClkSel,0,Level,RunInRest,CB}
#define PulseIntervalJudgment(ClkSel,Trigger,RunInRest,CB)		{9u,ClkSel,0,Trigger,RunInRest,CB}               /*Not-valib in TAUJ !!!*/
#define PulseWidthJudgment(ClkSel,Level,RunInRest,CB)		         {10u,ClkSel,0,Level,RunInRest,CB}               /*Not-valib in TAUJ !!!*/	
#define PulseWidthOVcheck(ClkSel,Level,RunInRest,CB)			{11u,ClkSel,0,Level,RunInRest,CB}
#define PulseWidthCumulaterOVcheck(ClkSel,Level,RunInRest,CB)	{12u,ClkSel,0,Level,RunInRest,CB}

#define PpgMaster(ClkSel,DefaultHZ)				{15u,ClkSel,DefaultHZ,Not_Triggre,1,MCU_vNotExpINT}
#define PpgSlave(DefaultDuty)				        {16u,0,DefaultDuty,Not_Triggre,1,MCU_vNotExpINT}

#define PulseDetectDelayMaster(ClkSel,DelayLenth,Trigger,RunInRest,CB)	{0xFFu,ClkSel,DelayLenth,Trigger,RunInRest,CB}/*Not Use*/ /*Not-valib in TAUJ !!!*/
#define PulseDetectDelaySlave(ClkSel,DelayLenth,Trigger,RunInRest,CB)	        {0xFFu,ClkSel,DelayLenth,Trigger,RunInRest,CB}/*Not Use*/  /*Not-valib in TAUJ !!!*/

#define TUAx_MaxFun		17

#define TAUxTrige_Failing	0
#define TAUxTrige_Rising	1
#define TAUxTrige_BothEdge  2
#define TAUxTrige_LowLevel	    2
#define TAUxTrige_HighLevel	    3

#define TAUxClk_Div(PreScale_0,PreScale_1,PreScale_2,PreScale_3)	{PreScale_0,PreScale_1,PreScale_2,PreScale_3}

MCU_tstTAUxClkDiv_UsrCfg MCU_stTAUxClkDivCfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit][4]=
{
/*clock divider is [SourceClk / (2^SettingValue)]*/

	/*TAUB0 group*/TAUxClk_Div(0,1,2,3),
	/*TAUB1 group*/TAUxClk_Div(0,1,2,3),
	/*TAUB2 group*/TAUxClk_Div(0,1,2,3),
	/*TAUJ0 group*/ TAUxClk_Div(0,1,2,3),
};

MCU_tstTAUx_UsrCfg MCU_stTAUxCfg[MCU_mTAUB0_Channel * MCU_mTAUB_Unit + \
								MCU_mTAUD0_Channel * MCU_mTAUD_Unit+\
								MCU_mTAUJ0_Channel * MCU_mTAUJ_Unit]=
{
/*TAUB0 group*/
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,

/*TAUB1 group*/
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,

/*TAUB2 group*/
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,

/*TAUJ0 group*/
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,


};
#endif

#if (MCU_mIICModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		IIC setting   
			@@@@@@@@@@		  
####################################################*/

#define __ThisIIC_Not_Mount__ 	{0/*bps*/,{0x00,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}
MCU_tstRIIC_UsrCfg MCU_tstRIICCfg[2]=
{
	__ThisIIC_Not_Mount__,
	__ThisIIC_Not_Mount__,	
};

#endif

#if 0/****DMA for D1X is not finish !!***************/
#define Source_Increment_Dest_Increment		0
#define Source_Increment_Dest_Fix		1
#define Source_Fix_Dest_Increment		4
#define Source_Fix_Dest_Fix				5

#define DMA_Uint_8bit	0
#define DMA_Uint_16bit	1
#define DMA_Uint_32bit	2

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	MCU_vNotExpINT}

/*################################################
	############################################
	
			DMA module configeration
			
	############################################	
################################################*/
MCU_tstDMA_UsrCfg MCU_stDMACfg[MCU_mDMA_MaxChn]=
{
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
};
#endif

#if (MCU_mEINTModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		IIC setting   
			@@@@@@@@@@		  
####################################################*/
#define DetDisable	0u
#define RisingEdge	1u
#define FaillingEdge 2u
#define BothEdge 3u
#define LowLevel	4u
#define HighLevel	5u
#define EINT_NotUse 0xFFFFu

#define __ThisEINT_NotMount__	{0xFFFFu,0u,MCU_vNotExpINT}
#define EINTconfig(trigger,RunInReset,Callback)	    {trigger,RunInReset,Callback}

MCU_tstEINT_UsrCfg MCU_stEINTCfg[MCU_mMaxEINTchannelMount]=
{
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
};
#endif

#if (MCU_mADCModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		ADC setting   
			@@@@@@@@@@		  
####################################################*/
MCU_tstADCA_UsrCfg MCU_stADCACfg=
{
	0, /*	ADCA0: 	channel 0 ~31====> channel 20 is [Isolated-Area power supply ISOVDD]*/
	0, /*			channel 32 ~63====> channel 37 is [CPU Temperatur Sensor output]*/
	
	0, /*	ADCA1: 	channel 0 ~31*/
	0, /*			channel 32 ~63*/
};
#endif


#if (MCU_mRLIN3UartModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		RLIN3 setting   
			@@@@@@@@@@		  
####################################################*/

#define RLin_LSB	0u
#define RLin_MSB	1u
#define RLin_StpB1	0u
#define RLin_StpB2	1u
#define RLin_ParityNone	0u
#define RLin_ParityEven	1u
#define RLin_ParityZero	2u
#define RLin_ParityOdd	3u

#define __ThisRLIN3UART_NotMount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u8}

#define RLIN3Uartconfig(bps,MSB,StopBit,Parity,RxInve,TxInve,SendCB,RecCB,ErrCB)	\
	{bps,MSB,StopBit,Parity,RxInve,TxInve,SendCB,RecCB,ErrCB}

MCU_tstLinUart_UsrCfg MCU_stRLIN3UsrCfg[MCU_mRLIN3Uint_Number]=
{
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,

};
#endif

#define SpiClkType0	0
#define SpiClkType1	1
#define SpiClkType2	2
#define SpiClkType3	3
#define SpiParityNone	0u
#define SpiParityZero	1u
#define SpiParityOdd	2u
#define SpiParityEven	3u

#if (MCU_mCSIGModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		CSIG setting   
			@@@@@@@@@@		  
####################################################*/

#define CSIGconf(Bps,LSBType,ClkType,HankShake,Parity,SendFinshCB,RecFinshCB,ErrCB)		\
		{Bps,LSBType,ClkType,HankShake,0/*Slave*/,Parity,SendFinshCB,RecFinshCB,ErrCB}

#define __ThisCSIG_NotMount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIG_UsrCfg MCU_stCSIGCfg[MCU_mCSIG_MaxChn]=
{
	__ThisCSIG_NotMount__,
	__ThisCSIG_NotMount__,
	__ThisCSIG_NotMount__,
	__ThisCSIG_NotMount__,
};
#endif

#if (MCU_mCSIHModuleEnable !=0u)
/*################################################
			@@@@@@@@@@			 
	@@@@@@@@@@@@@@@@@		CSIH setting   
			@@@@@@@@@@		  
####################################################*/

#define CSIHconf(Bps,LSBType,ClkType,HankShake,Parity,SendFinshCB,RecFinshCB,ErrCB)		\
		{Bps,LSBType,ClkType,HankShake,0/*Slave*/,Parity,SendFinshCB,RecFinshCB,ErrCB}

#define __ThisCSIH_NotMount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIH_UsrCfg MCU_stCSIHCfg[MCU_mCSIH_MaxChn]=
{
	__ThisCSIH_NotMount__,
	__ThisCSIH_NotMount__,
};

#endif

#define Debug_SetPin_Clock(port,pin,HighLow)
#define Debug_SetPin_OSTM(port,pin,HighLow)
#define Debug_SetPin_WD(port,pin,HighLow)
#define Debug_SetPin_Reset(port,pin,HighLow)
#define Debug_SetPin_CSIx(port,pin,HighLow)
#define Debug_SetPin_EINT(port,pin,HighLow)
#define Debug_SetPin_TAUx(port,pin,HighLow)


