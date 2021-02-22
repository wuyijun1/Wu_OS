/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L_UsrCfg.c
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


#define MCU_CLK_UsingDefault	0xFFFFFFFE

#define PLL_MainOsc_8M_80M	0
#define PLL_MainOsc_8M_64M	1
#define PLL_MainOsc_8M_40M	2
#define PLL_MainOsc_8M_30M	3

#define PLL_MainOsc_16M_80M	4
#define PLL_MainOsc_16M_64M	5
#define PLL_MainOsc_16M_40M	6
#define PLL_MainOsc_16M_30M	7

/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		system setting   
		@@@@@@@@@@		  
####################################################*/

/*################################################
			clock module configeration
################################################*/
MCU_tstClockUsrCfg MCU_stClockCfg_F1L=
{
	1000,			/* MainOsc_StableTime===>us*/
	1,				/* MainOscStopInStandbyMode===> Not stop MainOsc always*/
		
	0,				/* SubOsc_FTX_Speed*/
	0,				/* SubOsc_StableTime===>us*/
	/*0,				 SubOscStopInStandbyMode*/
		
	240000,			/* IntOscLS_FRL_Speed = 240000, can not change*/
	8000000,			/* IntOscHS_FRH_Speed = 8000000, can not change*/

	PLL_MainOsc_16M_64M,	/* CPLLCLK_Speed===>CPU clock from PLL*/
	0,					/* MEMCLK_Speed===>external memery controller clock from PLL*/

		
	2,					/* ClkDiv_C_AWO_WDTAD===>	00B: Setting prohibited
													01B: LS IntOSC / 128 (default)
													10B: LS IntOSC / 1*/
									
									
	/*1,					 WDTAStopInStandbyMode===> always stop the watchdog when STOP*/
		
	2,					/* ClkSel_C_AWO_TAUJS ==>	000B: Disabled
													001B: HS IntOSC (default)
													010B: MainOSC
													011B: LS IntOSC
													100B: PPLLLCLK/2*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_TAUJD===>	001B: X/1 (default)
													010B:  X/2
													011B:  X/4
													100B:  X/8*/
	1,					/* TAUJStopInStandbyMode*/
		
	MCU_CLK_UsingDefault,	/* ClkSel_C_AWO_RTCAS===>	00B: Disable (default)
													01B: SubOSC
													10B: MainOSC
													11B: LS IntOSC*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_RTCAD===>	001B: X/1 (default)
													010B:  X/2
													011B:  X/4
													100B:  X/8*/
	1,					/* RTCAStopInStandbyMode*/
									
	MCU_CLK_UsingDefault,	/* ClkSel_C_AWO_ADCAS===>	00B: Disabled
													01B: HS IntOSC (default)
													10B: MainOSC
													11B: PPLLCLK/2*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_ADCAD===>	001B: X/1 (default)
													010B:  X/2*/
									
	1,					/* ADCAStopInStandbyMode*/
		
	MCU_CLK_UsingDefault,	/* ClkSel_C_AWO_FOUT===>	000B: Disabled (default)
													001B: MainOSC
													010B: HS IntOSC
													011B: LS IntOSC
													100B: SubOSC
													101B: CPLLCLK/2
													110B: PPLLCLK/4*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_FOUT===>  1 to 63 divide*/
		
		
	3,					/* ClkSel_C_ISO_CPUCLKS===>	00B: Setting prohibited
													01B: EMCLK (default)
													10B: MainOSC
													11B: CPLLCLK--->we use defalu PLL output < -----*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_ISO_CPUCLKD===>	001B: X/1 (default)
													010B:  X/2
													011B:  X/4
													100B:  X/8*/
									
	MCU_CLK_UsingDefault,	/* ClkSel_C_ISO_PER1===>		00B: Disabled
													01B: CPUCLK/2 (default)
													10B: PPLLCLK*/
									
	MCU_CLK_UsingDefault,	/* ClkSel_C_ISO_PER2===>		00B: Disabled
													01B: CPUCLK/2 (default)
													10B: PPLLCLK*/
									
	2,					/* ClkSel_C_ISO_LINS===>		00B: Disabled
													01B: CPUCLK/2 (default)
													10B: MainOSC
													11B: PPLLCLK/2*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_ISO_ILIND===>		001B: X/1 (default)
													010B:  X/4
													011B: X/8*/								
	1,					/* LINStopInStandbyMode*/
		
	MCU_CLK_UsingDefault, 	/* ClkSel_C_ISO_ADCAS===>	00B: Disabled
													01B: HS IntOSC RH (8 MHz) (default)
													10B: MainOSC
													11B: PPLLCLK/2*/
									
	MCU_CLK_UsingDefault,	/* ClkDiv_C_ISO_ADCAD===>	001B: X/1 (default)
													010B:  X/2*/
									
	MCU_CLK_UsingDefault,	/* ClkSel_C_ISO_CANS===>	00B: Disabled
												01B: MainOSC
												10B: CPLLCLK
												11B: CPUCLK (default)*/
										
	1,					/* CANStopInStandbyMode*/
		
	MCU_CLK_UsingDefault,	/* ClkDiv_C_ISO_CANOSCD===>	00B: Disabled (default)
													01B: MainOSC /1
													10B: MainOSC /2
													11B: Setting prohibited*/
									
	1,					/* CANOSCStopInStandbyMode*/
		
	MCU_CLK_UsingDefault,	/* ClkSel_C_ISO_CSIS===>	00B: Disabled
												01B: CPUCLK (default)
												10B: PPLLCLK*/
								
	0,				/* CLMA0enable_HS===>CLMA0 monitor unit,sample clock = LS*/
	80,				/* CLMA0TolerancePercent*/
		
	0,				/* CLMA1enable_MainOsc===>CLMA1 monitor unit,sample clock = LS*/
	80,				/* CLMA1TolerancePercent*/
		
	0,				/* CLMA2enable_CPLLCLK===>CLMA2 monitor unit,sample clock = HS*/
	80				/* CLMA2TolerancePercent*/


};

/*################################################
			standby control configeration
################################################*/

MCU_tstSTBC_UsrCfg MCU_stSTBCCfg=
{
	{
/***********************************
wake up factor WU0

	1=enable
	0= diasble
*********************************/
		0,	/*	TNMI	*/
		0,	/*	WDTA0NMI	*/
		0,	/*	INTLVIL 	*/
		0,	/*	Fill0	*/
		0,	/*	Fill1	*/
		0,	/*	INTP0	*/
		0,	/*	INTP1	*/
		0,	/*	INTP2	*/
		0,	/*	INTWDTA0	*/
		0,	/*	INTP3	*/
		0,	/*	INTP4	*/
		0,	/*	INTP5	*/
		0,	/*	INTP10	*/
		0,	/*	INTP11	*/
		0,	/*	WUTRG1	*/
		0,	/*	INTTAUJ0I0	*/
		0,	/*	INTTAUJ0I1	*/
		0,	/*	INTTAUJ0I2	*/
		0,	/*	INTTAUJ0I3	*/
		0,	/*	WUTRG0	*/
		0,	/*	INTP6	*/
		0,	/*	INTP7	*/
		0,	/*	INTP8	*/
		0,	/*	INTP12	*/
		0,	/*	INTP9	*/
		0,	/*	INTP13	*/
		0,	/*	INTP14	*/
		0,	/*	INTP15	*/
		0,	/*	INTRTCA01S	*/
		0,	/*	INTRTCA0AL	*/
		0,	/*	INTRTCA0R	*/
		0,	/*	INTDCUTDI	*/

	},
	
	{
	/***********************************
	wake up factor WU_ISO0
	
		1=enable
		0= diasble
	*********************************/		
			0,	/*	Fill0	*/
			0,	/*	INTKR0	*/
			0,	/*	INTRCANGRECC	*/
			0,	/*	INTRCAN0REC 	*/
			0,	/*	INTRCAN1REC 	*/
			0,	/*	INTRCAN2REC 	*/
			0,	/*	INTRCAN3REC 	*/
			0,	/*	INTRCAN4REC 	*/
			0,	/*	INTRCAN5REC 	*/
			0,	/*	Fill1	*/
	},
	
	{
/***********************************
wake up factor WU20

	1=enable
	0= diasble
*********************************/
		
		0,	/*	INTADCA0I0	*/
		0,	/*	INTADCA0I1	*/
		0,	/*	INTADCA0I2	*/
		0,	/*	INTRLIN30	*/
		0,	/*	INTTAUJ0I0	*/
		0,	/*	INTTAUJ0I1	*/
		0,	/*	INTTAUJ0I2	*/
		0,	/*	INTTAUJ0I3	*/
		0,	/*	INTRLIN31	*/
		0,	/*	INTRLIN32	*/
		0,	/*	INTRTCA01S	*/
		0,	/*	INTRTCA0AL	*/
		0,	/*	INTRTCA0R	*/
		0,	/*	INTRLIN33	*/
		0,	/*	INTRLIN34	*/
		0,	/*	INTRLIN35	*/
		0,	/*	Fill0	*/
	},
	
};


/*################################################
			FEMI module configeration
################################################*/
MCU_tstFEMI_UsrCfg MCU_stFEMICfg=
{
	MCU_vNotExpINT,	/* LVIL		0*/
	MCU_vNotExpINT,	/* Reverce1	1*/
	MCU_vNotExpINT,	/* Reverce2	2*/
	MCU_vNotExpINT,	/* Reverce3	3*/
	MCU_vNotExpINT,	/* ECCDEEP0	4*/
	MCU_vNotExpINT,	/* Reverce5	5*/
	MCU_vNotExpINT,	/* ECCDCNRAM	6*/
	MCU_vNotExpINT,	/* ECCDCSIH0		7*/
	MCU_vNotExpINT,	/* ECCDCSIH1		8*/
	MCU_vNotExpINT,	/* ECCDCSIH2		9*/
	MCU_vNotExpINT,	/* ECCDCSIH3		10*/
	MCU_vNotExpINT,	/* Reverce11		11*/
	MCU_vNotExpINT,	/* ECCSDFLI0		12*/
	MCU_vNotExpINT,	/* ECCRAM		13*/
	MCU_vNotExpINT,	/* OSTM_0		14*/
	MCU_vNotExpINT,	/* LVIH			15*/	
};

/*################################################
			FENMI module configeration
			NOTE: these interrupts CAN NOT return if called!
################################################*/
const MCU_tstFENMI_UsrCfg MCU_stFENMICfg=
{
	MCU_vNotExpINT,	/* TINM		0*/
	MCU_vNotExpINT,	/* WD0		1*/
	MCU_vNotExpINT,	/* WD1		2*/
};



/*##################################################
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

const MCU_tstPinCfg MCU_stPinUserCfg_Port[MCU_MaxPortMount * MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillField}
*************************************************************************************/


/*##################*/
/*Pin ID =====Port 0*/
/*##################*
/*P0_0*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I2	1_O=>TAUD0O2	2_I=>RLIN20RX			2_O=>CAN0TX	3_O=>PWGA10O	4_I=>CSIH0SSI	4_O=>DPO		(RESETOUT)	*/
/*P0_1*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I4	1_O=>TAUD0O4	2_I=>CAN0RX/INTP0		2_O=>RLIN20TX	3_I=>INTP0		3_O=>PWGA11O	4_I=>CSIH0SI		4_O=>APO			*/
/*P0_2*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I6	1_O=>TAUD0O6	2_I=>CAN1RX/INTP1		2_O=>RLIN30TX	3_O=>PWGA12O	4_I=>CSIH0SC	5_I=>INTP1		5_O=>DPO	*/
/*P0_3*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I8	1_O=>TAUD0O8	2_I=>RLIN30RX/INTP10	2_O=>CAN1TX	3_I=>DPIN1		3_O=>PWGA13O	4_I=>CSIH0SO	5_I=>INTP10		*/
/*P0_4*/__ThisPin_NotMount__,	/*	1_I=>RLIN31RX/INTP11	1_O=>CAN2TX	2_I=>INTP11		2_O=>PWGA10O	3_I=>CSIH1SI		3_O=>SELDP0		4_I=>DPIN8				*/
/*P0_5*/__ThisPin_NotMount__,	/*	1_I=>CAN2RX/INTP2		1_O=>RLIN31TX	2_I=>DPIN9		2_O=>SELDP1		3_O=>CSIH1SO					*/
/*P0_6*/PinConf(GPIO_In,1),	/*k15 input detection*/	/*	1_I=>INTP2		2_I=>DPIN10		2_O=>SELDP2		3_I=>CSIH1SC						*/
/*P0_7*/__ThisPin_NotMount__,	/*	1_I=>RLIN21RX	2_I=>DPIN5		2_O=>CSCXFOUT	3_I=>CSIH1RYI	3_O=>CSIH1RYO	4_I=>TAUB0I0	4_O=>TAUB0O0	5_I=>INTP3		*/
/*P0_8*/__ThisPin_NotMount__,	/*	1_I=>RLIN21TX	2_I=>DPIN6		2_O=>CSIH1SSI	3_I=>TAUB0I2	3_O=>TAUB0O2	4_I=>CAN3TX				*/
/*P0_9*/__ThisPin_NotMount__,	/*	1_I=>INTP12		1_O=>CSIH1CSS0	2_I=>DPIN7		3_I=>RLIN22RX	4_I=>TAUB0I4	4_O=>TAUB0O4	5_I=>CAN4RX/INTP4		*/
/*P0_10*/__ThisPin_NotMount__,	/*	1_I=>INTP3	1_O=>CSIH1CSS1	2_I=>DPIN11		3_O=>RLIN22TX	4_I=>TAUB0I6	4_O=>TAUB0O6	5_O=>CAN4TX	*/
/*P0_11*/__ThisPin_NotMount__,	/*	1_I=>RIIC0SDA		1_O=>RIIC0SDA	2_I=>DPIN12		2_O=>CSIH1CSS2	3_I=>TAUB0I8	3_O=>TAUB0O8	4_I=>RLIN26RX				*/
/*P0_12*/__ThisPin_NotMount__,	/*	1_I=>RIIC0SCL		1_O=>RIIC0SCL	2_I=>DPIN13		2_O=>PWGA45O	3_I=>TAUB0I10	3_O=>TAUB0O10	4_I=>CSIG0SI		4_O=>RLIN26TX			*/
/*P0_13*/__ThisPin_NotMount__,	/*	1_I=>RLIN32RX/INTP12				2_I=>INTP12		2_O=>PWGA46O	3_I=>TAUB0I12	3_O=>TAUB0O12	4_O=>CSIG0SO	5_I=>CAN5RX/INTP5		*/
/*P0_14*/__ThisPin_NotMount__,	/*	1_O=>RLIN32TX		2_O=>PWGA47O	3_I=>TAUB0I14	3_O=>TAUB0O14	4_I=>CSIG0SC	5_O=>CAN5TX	*/
/*P0_15*/__ThisPin_NotMount__,	/*	1_I=>Pin Not Mount										*/

/*##################*/
/*Pin ID =====Port 1*/
/*##################*/	
/*P1_0*/__ThisPin_NotMount__,	/*	1_I=>RLIN33RX/INTP13	2_I=>INTP13								*/
/*P1_1*/__ThisPin_NotMount__,	/*	1_O=>RLIN33TX									*/
/*P1_2*/__ThisPin_NotMount__,	/*	1_I=>CAN3RX/INTP3		2_I=>INTP3								*/
/*P1_3*/__ThisPin_NotMount__,	/*	1_O=>CAN3TX			2_I=> DPIN23								*/
/*P1_4*/__ThisPin_NotMount__,	/*	1_I=>RLIN35RX/INTP15	2_I=>INTP15								*/
/*P1_5*/__ThisPin_NotMount__,	/*	1_I=>ADCA1TRG0			1_O=>RLIN35TX	2_I=>DPIN17								*/
/*P1_6*/__ThisPin_NotMount__,	/*	1_I=>RLIN25RX			2_I=>DPIN18								*/
/*P1_7*/__ThisPin_NotMount__,	/*	1_I=>ADCA1TRG1			1_O=>RLIN25TX	2_I=>DPIN19								*/
/*P1_8*/__ThisPin_NotMount__,	/*	1_I=>RLIN34RX/INTP14	2_I=>INTP14								*/
/*P1_9*/__ThisPin_NotMount__,	/*	1_O=>RLIN34TX			2_I=>DPIN20								*/
/*P1_10*/__ThisPin_NotMount__,	/*	1_I=>RLIN24RX		2_I=>DPIN21								*/
/*P1_11*/__ThisPin_NotMount__,	/*	1_I=>ADCA1TRG2		1_O=>RLIN24TX	2_I=>DPIN22								*/
/*P1_12*/__ThisPin_NotMount__,	/*	1_I=>CAN4RX/INTP4	2_I=>INTP4								*/
/*P1_13*/__ThisPin_NotMount__,	/*	1_O=>CAN4TX									*/
/*P1_14*/__ThisPin_NotMount__,	/*	1_I=>RLIN23RX										*/
/*P1_15*/__ThisPin_NotMount__,	/*	1_O=>RLIN23TX									*/


/*##################*/
/*Pin ID =====Port 2*/
/*##################*/
/*P2_0*/__ThisPin_NotMount__,	/*	1_I=>RLIN27RX										*/
/*P2_1*/__ThisPin_NotMount__,	/*	1_O=>RLIN27TX									*/
/*P2_2*/__ThisPin_NotMount__,	/*	1_I=>RLIN28RX										*/
/*P2_3*/__ThisPin_NotMount__,	/*	1_O=>RLIN28TX									*/
/*P2_4*/__ThisPin_NotMount__,	/*	1_I=>RLIN29RX										*/
/*P2_5*/__ThisPin_NotMount__,	/*	1_O=>RLIN29TX									*/
/*P2_6*/__ThisPin_NotMount__,	/*											*/
/*P2_7*/__ThisPin_NotMount__,	/*											*/
/*P2_8*/__ThisPin_NotMount__,	/*											*/
/*P2_9*/__ThisPin_NotMount__,	/*											*/
/*P2_10*/__ThisPin_NotMount__,	/*											*/
/*P2_11*/__ThisPin_NotMount__,	/*											*/
/*P2_12*/__ThisPin_NotMount__,	/*											*/
/*P2_13*/__ThisPin_NotMount__,	/*											*/
/*P2_14*/__ThisPin_NotMount__,	/*											*/
/*P2_15*/__ThisPin_NotMount__,	/*											*/


/*##################*/
/*Pin ID =====Port 3*/
/*##################*/
/*P3_0*/__ThisPin_NotMount__,
/*P3_1*/__ThisPin_NotMount__,
/*P3_2*/__ThisPin_NotMount__,
/*P3_3*/__ThisPin_NotMount__,
/*P3_4*/__ThisPin_NotMount__,
/*P3_5*/__ThisPin_NotMount__,
/*P3_6*/__ThisPin_NotMount__,
/*P3_7*/__ThisPin_NotMount__,
/*P3_8*/__ThisPin_NotMount__,
/*P3_9*/__ThisPin_NotMount__,
/*P3_10*/__ThisPin_NotMount__,
/*P3_11*/__ThisPin_NotMount__,
/*P3_12*/__ThisPin_NotMount__,
/*P3_13*/__ThisPin_NotMount__,
/*P3_14*/__ThisPin_NotMount__,
/*P3_15*/__ThisPin_NotMount__,


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
/*P8_0*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I0	1_O=>TAUJ0O0	2_I=>DPIN2	2_O=>PWGA14O	3_I=>INTP4	3_O=>CSIH0CSS0	(ADCA0I0S)				*/
/*P8_1*/__ThisPin_NotMount__,	/*	1_I=>TAPA0ESO 	1_O=>TAUJ0O1	2_I=>DPIN0 	2_O=>PWGA15O 	3_I=>INTP5	3_O=>CSIH1CSS3	(ADCA0I1S)				*/
/*P8_2*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I0	1_O=>TAUJ0O0	2_I=>DPIN2	2_O=>CSIH0CSS0	3_I=>INTP6	3_O=>PWGA22O	(ADCA0I4S)				*/
/*P8_3*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I1	1_O=>TAUJ0O1	2_I=>DPIN3	2_O=>CSIH0CSS1	3_I=>INTP7	3_O=>PWGA23O	(ADCA0I5S)				*/
/*P8_4*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I2	1_O=>TAUJ0O2	2_I=>DPIN4	2_O=>CSIH0CSS2	3_I=>INTP8	3_O=>PWGA36O	(ADCA0I6S)				*/
/*P8_5*/__ThisPin_NotMount__,	/*	1_I=>TAUJ0I3	1_O=>TAUJ0O3	2_O=>CSIH0CSS3	3_I=>INTP9	3_O=>PWGA37O				(ADCA0I7S)	*/
/*P8_6*/__ThisPin_NotMount__,	/*	1_I=>NMI		1_O=>CSIH0CSS4	2_O=>PWGA38O	3_O=>RTCA0OUT					                  (ADCA0I8S)*/
/*P8_7*/__ThisPin_NotMount__,	/*	1_O=>CSIH3CSS0	2_O=>PWGA39O	                                            (ADCA0I14S)						*/
/*P8_8*/__ThisPin_NotMount__,	/*	1_O=>CSIH3CSS1	2_O=>PWGA40O	                                            (ADCA0I15S)						*/
/*P8_9*/PinConf(GPIO_Out,1),	/*pin test*/	/*	1_O=>CSIH3CSS2	2_O=>PWGA41O	                                            (ADCA0I16S)						*/
/*P8_10*/__ThisPin_NotMount__,	/*	1_O=>CSIH3CSS3	2_I=>DPIN14		2_O=>PWGA42O	(ADCA0I17S)						*/
/*P8_11*/__ThisPin_NotMount__,	/*	1_I=>TAUJ1I2	1_O=>TAUJ1O2	2_I=>DPIN15	2_O=>PWGA43O	3_O=>CSIH1CSS4	(ADCA0I18S)				*/
/*P8_12*/__ThisPin_NotMount__,	/*	1_I=>TAUJ1I3	1_O=>TAUJ1O3	2_I=>DPIN16	2_O=>PWGA44O	3_O=>CSIH1CSS5	(ADCA0I19S)				*/
/*P8_13*/__ThisPin_NotMount__,	/*											*/
/*P8_14*/__ThisPin_NotMount__,	/*											*/
/*P8_15*/__ThisPin_NotMount__,	/*											*/



/*##################*/
/*Pin ID =====Port 9*/
/*##################*/
/*P9_0*/__ThisPin_NotMount__,	/*	1_I=>NMI	1_O=>PWGA8O		2_I=>TAUD0I0	2_O=>TAUD0O0	3_I=>ADCA0TRG0	3_O=>CSIH2CSS0	4_I=>KR0I4	(ADCA0I2S)			*/
/*P9_1*/__ThisPin_NotMount__,	/*	1_I=>INTP11	1_O=>PWGA9O		2_I=>TAUD0I2	2_O=>TAUD0O2	3_I=>KR0I5		3_O=>CSIH2CSS1				(ADCA0I3S)	*/
/*P9_2*/__ThisPin_NotMount__,	/*	1_I=>KR0I6	1_O=>PWGA20O		2_I=>TAPA0ESO	2_O=>CSIH2CSS2	(ADCA0I9S)						*/
/*P9_3*/__ThisPin_NotMount__,	/*	1_I=>KR0I7	1_O=>PWGA21O		2_O=>CSIH2CSS3	                                   (ADCA0I10S)						*/
/*P9_4*/__ThisPin_NotMount__,	/*	1_O=>CSIH0CSS5	2_O=>PWGA33O	3_I=>TAUJ1I0	3_O=>TAUJ1O0	(ADCA0I11S)				*/
/*P9_5*/__ThisPin_NotMount__,	/*	1_O=>CSIH0CSS6	2_O=>PWGA34O	3_I=>TAUJ1I1	3_O=>TAUJ1O1	(ADCA0I12S)				*/
/*P9_6*/__ThisPin_NotMount__,	/*	1_O=>CSIH0CSS7	2_O=>PWGA35O	(ADCA0I13S)						*/
/*P9_7*/__ThisPin_NotMount__,	/*											*/
/*P9_8*/__ThisPin_NotMount__,	/*											*/
/*P9_9*/__ThisPin_NotMount__,	/*											*/
/*P9_10*/__ThisPin_NotMount__,	/*											*/
/*P9_11*/__ThisPin_NotMount__,	/*											*/
/*P9_12*/__ThisPin_NotMount__,	/*											*/
/*P9_13*/__ThisPin_NotMount__,	/*											*/
/*P9_14*/__ThisPin_NotMount__,	/*											*/
/*P9_15*/__ThisPin_NotMount__,	/*											*/


/*##################*/
/*Pin ID =====Port 10*/
/*##################*/
/*P10_0*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I1	1_O=>TAUD0O1	2_I=>CAN0RX/INTP0	2_O=>CSCXFOUT				3_O=>PWGA0O		4_O=>TAPA0UP	5_I=>CSIH1SI	5_O=>MEMC0 A19	*/
/*P10_1*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I3	1_O=>TAUD0O3	2_O=>CAN0TX		3_O=>PWGA1O				4_O=>TAPA0UN		5_I=>CSIH1SC	5_O=>CSIH1SC	(MODE0)*/
/*P10_2*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I5	1_O=>TAUD0O5	2_O=>RIIC0SDA	3_I=>KR0I0	3_O=>PWGA2O		4_I=>ADCA0TRG0		4_O=>TAPA0VP	5_O=>CSIH1SO	(MODE1)*/
/*P10_3*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I7	1_O=>TAUD0O7	2_O=>RIIC0SCL	3_I=>KR0I1	3_O=>PWGA3O		4_I=>ADCA0TRG1		4_O=>TAPA0VN	5_I=>CSIH1SSI	5_O=>MEMC0CLK	*/
/*P10_4*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I9	1_O=>TAUD0O9	2_I=>RLIN21RX	3_I=>KR0I2	3_O=>ADCA0SEL0		4_I=>ADCA0TRG2		4_O=>TAPA0WP	5_I=>CSIG0SSI		*/
/*P10_5*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I11	1_O=>TAUD0O11	2_O=>RLIN21TX	3_I=>KR0I3		3_O=>ADCA0SEL1	4_O=>TAPA0WN		5_I=>CSIG0RYI	5_O=>CSIG0RYO	*/
/*P10_6*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I13	1_O=>TAUD0O13	2_O=>CSIG0SO	3_I=>ENCA0TIN0	3_O=>ADCA0SEL2	4_I=>CAN1RX/INTP1	5_I=>MEMC0AD0	5_O=>MEMC0AD0	*/
/*P10_7*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I15	1_O=>TAUD0O15	2_I=>CSIG0SC	2_O=>CSIG0SC	3_I=>ENCA0TIN1	3_O=>PWGA4O		4_O=>CAN1TX	5_I=>MEMC0AD1	5_O=>MEMC0AD1	*/
/*P10_8*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I10	1_O=>TAUD0O10	2_I=>CSIG0SI		3_I=>ENCA0EC	3_O=>PWGA5O	4_I=>MEMC0AD2		4_O=>MEMC0AD2			(FLMD1)*/
/*P10_9*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I12	1_O=>TAUD0O12	2_I=>RLIN30RX/INTP10	3_I=>ENCA0E0	3_O=>PWGA6O		4_I=>CSIH0RYI	4_O=>CSIH0RYO	5_I=>MEMC0AD3	5_O=>MEMC0AD3	*/
/*P10_10*/__ThisPin_NotMount__,	/*	1_I=>TAUD0I14	1_O=>TAUD0O14	2_O=>RLIN30TX			3_I=>ENCA0E1	3_O=>PWGA7O		4_O=>CSIH0CSS1	5_I=>MEMC0AD4	5_O=>MEMC0AD4	*/
/*P10_11*/__ThisPin_NotMount__,	/*	1_O=>PWGA16O	2_I=>RLIN31RX/INTP11					3_O=>CSIH1CSS0	4_I=>TAUB0I1		4_O=>TAUB0O1	5_I=>MEMC0AD5	5_O=>MEMC0AD5	*/
/*P10_12*/__ThisPin_NotMount__,	/*	1_O=>PWGA17O	2_O=>RLIN31TX	3_O=>CSIH1CSS1			4_I=>TAUB0I3		4_O=>TAUB0O3	5_I=>MEMC0AD6	5_O=>MEMC0AD6	*/
/*P10_13*/__ThisPin_NotMount__,	/*	1_I=>CSIH0SSI	1_O=>PWGA18O	2_I=>RLIN32RX/INTP12	4_I=>TAUB0I5		4_O=>TAUB0O5	5_I=>MEMC0AD7	5_O=>MEMC0AD7	*/
/*P10_14*/__ThisPin_NotMount__,	/*	1_I=>ADCA1TRG0	1_O=>PWGA19O	2_O=>RLIN32TX	3_I=>CSIH3SSI	4_I=>TAUB0I7	4_O=>TAUB0O7	5_I=>MEMC0AD8	5_O=>MEMC0AD8	*/
/*P10_15*/PinConf(GPIO_Out, 1),/*WD FREE*//*	1_I=>CSIH3RYI	1_O=>CSIH3RYO	2_O=>PWGA24O	3_I=>RLIN22RX	4_I=>TAUB0I9	4_O=>TAUB0O9	5_O=>MEMC0RD	*/


/*##################*/
/*Pin ID =====Port 11*/
/*##################*/	
/*P11_0*/__ThisPin_NotMount__,	/*	1_I=>CSIH2RYI	1_O=>CSIH2RYO	2_I=>ADCA1TRG2	2_O=>PWGA25O	3_O=>RLIN22TX	4_I=>TAUB0I11		4_O=>TAUB0O11	5_O=>MEMC0WR	*/
/*P11_1*/__ThisPin_NotMount__,	/*	1_I=>CSIH2SSI	2_I=>RLIN20RX	3_O=>PWGA26O	4_I=>TAUB0I13	4_O=>TAUB0O13	5_I=>MEMC0AD9		5_O=>MEMC0AD9						*/
/*P11_2*/__ThisPin_NotMount__,	/*	1_O=>CSIH2SO	2_O=>RLIN20TX	3_O=>PWGA27O	4_I=>TAUB0I15	4_O=>TAUB0O15	5_I=>MEMC0AD10		5_O=>MEMC0AD10									*/
/*P11_3*/__ThisPin_NotMount__,	/*	1_I=>CSIH2SC	1_O=>CSIH2SC	2_I=>CAN3RX/INTP3	2_O=>PWGA28O	3_I=>TAUB1I1	3_O=>TAUB1O1	4_I=>MEMC0AD11	4_O=>MEMC0AD11			*/
/*P11_4*/__ThisPin_NotMount__,	/*	1_I=>CSIH2SI		1_O=>CAN3TX	2_O=>PWGA29O		3_I=>TAUB1I3	3_O=>TAUB1O3	4_I=>MEMC0AD12	4_O=>MEMC0AD12									*/
/*P11_5*/__ThisPin_NotMount__,	/*	1_I=>CAN5RX/INTP5		1_O=>RLIN33TX	2_O=>PWGA30O	3_I=>CSIH3SI		4_I=>TAUB1I5	4_O=>TAUB1O5	5_I=>MEMC0AD13	5_O=>MEMC0AD13	*/
/*P11_6*/__ThisPin_NotMount__,	/*	1_I=>RLIN33RX/INTP13	1_O=>CAN5TX	2_I=>ADCA1TRG1	2_O=>PWGA31O	3_O=>CSIH3SO	4_I=>TAUB1I7	4_O=>TAUB1O7	5_I=>MEMC0AD14	5_O=>MEMC0AD14		*/
/*P11_7*/__ThisPin_NotMount__,	/*	1_I=>INTP5		2_O=>PWGA32O			3_I=>CSIH3SC	3_O=>CSIH3SC	4_I=>TAUB1I9	4_O=>TAUB1O9	5_I=>MEMC0AD15	5_O=>MEMC0AD15			*/
/*P11_8*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SSI	1_O=>RLIN35TX			2_O=>PWGA48O	3_I=>TAUB1I11	3_O=>TAUB1O11	4_O=>MEMC0CS0			*/
/*P11_9*/__ThisPin_NotMount__,	/*	1_O=>CSIG1SO	2_I=>RLIN35RX/INTP15	2_O=>PWGA49O	3_I=>TAUB1I13	3_O=>TAUB1O13	4_O=>MEMC0CS1			*/
/*P11_10*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SC	1_O=>CSIG1SC		2_O=>PWGA50O	3_I=>TAUB1I15	3_O=>TAUB1O15		4_O=>MEMC0CS2			*/
/*P11_11*/__ThisPin_NotMount__,	/*	1_I=>CSIG1SI		1_O=>RLIN25TX		2_O=>PWGA51O	3_I=>TAUB1I0	3_O=>TAUB1O0		4_O=>MEMC0CS3			*/
/*P11_12*/__ThisPin_NotMount__,	/*	1_I=>RLIN25RX	2_O=>PWGA52O		3_I=>TAUB1I2	3_O=>TAUB1O2	4_I=>MEMC0WAIT									*/
/*P11_13*/__ThisPin_NotMount__,	/*	1_I=>RLIN24RX	2_O=>PWGA53O		3_I=>TAUB1I4	3_O=>TAUB1O4	4_O=>MEMC0BEN0									*/
/*P11_14*/__ThisPin_NotMount__,	/*	1_O=>RLIN24TX		2_O=>PWGA54O	3_I=>TAUB1I6	3_O=>TAUB1O6	4_O=>MEMC0BEN1								*/
/*P11_15*/__ThisPin_NotMount__,	/*	1_I=>CAN2RX/INTP2	1_O=>CSIH2CSS4	2_O=>PWGA55O	3_I=>TAUB1I8	3_O=>TAUB1O8	4_O=>MEMC0ASTB			*/


/*##################*/
/*Pin ID =====Port 12*/
/*##################*/
/*P12_0*/__ThisPin_NotMount__,	/*	1_O=>CAN2TX			2_O=>PWGA56O	3_I=>TAUB1I10	3_O=>TAUB1O10	4_O=>MEMC0A16			*/
/*P12_1*/__ThisPin_NotMount__,	/*	1_I=>RLIN34RX/INTP14	1_O=>CSIH2CSS5	2_O=>PWGA57O	3_I=>TAUB1I12	3_O=>TAUB1O12	4_O=>MEMC0A17			*/
/*P12_2*/__ThisPin_NotMount__,	/*	1_O=>RLIN34TX		2_O=>PWGA58O		3_I=>TAUB1I14	3_O=>TAUB1O14	4_O=>MEMC0A18			*/
/*P12_3*/__ThisPin_NotMount__,	/*	1_I=>RLIN27RX		2_O=>PWGA68O							*/
/*P12_4*/__ThisPin_NotMount__,	/*	1_O=>RLIN27TX		2_O=>PWGA69O							*/
/*P12_5*/__ThisPin_NotMount__,	/*	1_O=>PWGA70O									*/
/*P12_6*/__ThisPin_NotMount__,	/*											*/
/*P12_7*/__ThisPin_NotMount__,	/*											*/
/*P12_8*/__ThisPin_NotMount__,	/*											*/
/*P12_9*/__ThisPin_NotMount__,	/*											*/
/*P12_10*/__ThisPin_NotMount__,	/*											*/
/*P12_11*/__ThisPin_NotMount__,	/*											*/
/*P12_12*/__ThisPin_NotMount__,	/*											*/
/*P12_13*/__ThisPin_NotMount__,	/*											*/
/*P12_14*/__ThisPin_NotMount__,	/*											*/
/*P12_15*/__ThisPin_NotMount__,	/*											*/


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
/*P16_0*/__ThisPin_NotMount__,
/*P16_1*/__ThisPin_NotMount__,
/*P16_2*/__ThisPin_NotMount__,
/*P16_3*/__ThisPin_NotMount__,
/*P16_4*/__ThisPin_NotMount__,
/*P16_5*/__ThisPin_NotMount__,
/*P16_6*/__ThisPin_NotMount__,
/*P16_7*/__ThisPin_NotMount__,
/*P16_8*/__ThisPin_NotMount__,
/*P16_9*/__ThisPin_NotMount__,
/*P16_10*/__ThisPin_NotMount__,
/*P16_11*/__ThisPin_NotMount__,
/*P16_12*/__ThisPin_NotMount__,
/*P16_13*/__ThisPin_NotMount__,
/*P16_14*/__ThisPin_NotMount__,
/*P16_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 17*/
/*##################*/
/*P17_0*/__ThisPin_NotMount__,
/*P17_1*/__ThisPin_NotMount__,
/*P17_2*/__ThisPin_NotMount__,
/*P17_3*/__ThisPin_NotMount__,
/*P17_4*/__ThisPin_NotMount__,
/*P17_5*/__ThisPin_NotMount__,
/*P17_6*/__ThisPin_NotMount__,
/*P17_7*/__ThisPin_NotMount__,
/*P17_8*/__ThisPin_NotMount__,
/*P17_9*/__ThisPin_NotMount__,
/*P17_10*/__ThisPin_NotMount__,
/*P17_11*/__ThisPin_NotMount__,
/*P17_12*/__ThisPin_NotMount__,
/*P17_13*/__ThisPin_NotMount__,
/*P17_14*/__ThisPin_NotMount__,
/*P17_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 18*/
/*##################*/
/*P18_0*/__ThisPin_NotMount__,	/*	1_I=>CSIG1RYI	1_O=>CSIG1RYO	2_O=>PWGA61O	(ADCA1I0S)		*/
/*P18_1*/__ThisPin_NotMount__,	/*	1_O=>PWGA62O	(ADCA1I1S)								*/
/*P18_2*/__ThisPin_NotMount__,	/*	1_O=>PWGA63O	(ADCA1I2S)								*/
/*P18_3*/__ThisPin_NotMount__,	/*	1_O=>PWGA71O	(ADCA1I3S)								*/
/*P18_4*/__ThisPin_NotMount__,	/*	1_O=>CSIH1CSS4	(ADCA1I4S)								*/
/*P18_5*/__ThisPin_NotMount__,	/*	1_O=>CSIH1CSS5	(ADCA1I5S)								*/
/*P18_6*/__ThisPin_NotMount__,	/*	(ADCA1I6S)										*/
/*P18_7*/__ThisPin_NotMount__,	/*	(ADCA1I7S)										*/
/*P18_8*/__ThisPin_NotMount__,	/*											*/
/*P18_9*/__ThisPin_NotMount__,	/*											*/
/*P18_10*/__ThisPin_NotMount__,	/*											*/
/*P18_11*/__ThisPin_NotMount__,	/*											*/
/*P18_12*/__ThisPin_NotMount__,	/*											*/
/*P18_13*/__ThisPin_NotMount__,	/*											*/
/*P18_14*/__ThisPin_NotMount__,	/*											*/
/*P18_15*/__ThisPin_NotMount__,	/*											*/



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
/*P20_0*/__ThisPin_NotMount__,	/*	1_I=>RLIN26RX		2_O=>PWGA64O							*/
/*P20_1*/__ThisPin_NotMount__,	/*	1_O=>RLIN26TX		2_O=>PWGA65O							*/
/*P20_2*/__ThisPin_NotMount__,	/*	1_I=>CAN4RX/INTP4	2_O=>PWGA66O							*/
/*P20_3*/__ThisPin_NotMount__,	/*	1_O=>CAN4TX		2_O=>PWGA67O							*/
/*P20_4*/__ThisPin_NotMount__,	/*	1_I=>RLIN23RX		2_O=>PWGA59O							*/
/*P20_5*/__ThisPin_NotMount__,	/*	1_O=>RLIN23RX		2_O=>PWGA60O							*/
/*P20_6*/__ThisPin_NotMount__,	/*											*/
/*P20_7*/__ThisPin_NotMount__,	/*											*/
/*P20_8*/__ThisPin_NotMount__,	/*											*/
/*P20_9*/__ThisPin_NotMount__,	/*											*/
/*P20_10*/__ThisPin_NotMount__,	/*											*/
/*P20_11*/__ThisPin_NotMount__,	/*											*/
/*P20_12*/__ThisPin_NotMount__,	/*											*/
/*P20_13*/__ThisPin_NotMount__,	/*											*/
/*P20_14*/__ThisPin_NotMount__,	/*											*/
/*P20_15*/__ThisPin_NotMount__,	/*											*/

};

#define JPinConf(AltFun,PinResetLevel)	 PinConf(AltFun,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_JPort[MCU_MaxJPortMount *MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillField}
*************************************************************************************/
/*##################*/
/*Pin ID =====JPort 0*/
/*##################*/
/*JP0_0*/__ThisPin_NotMount__,	/*	1_I=>INTP0																			*/
/*JP0_1*/__ThisPin_NotMount__,	/*	1_I=>INTP1	2_I=>TAUJ0I0	2_O=>TAUJ0O0							*/
/*JP0_2*/__ThisPin_NotMount__,	/*	1_I=>INTP2	2_I=>TAUJ0I1	2_O=>TAUJ0O1							*/
/*JP0_3*/__ThisPin_NotMount__,	/*	1_I=>INTP3	1_O=>CSCXFOUT	2_I=>TAUJ0I2	2_O=>TAUJ0O2							*/
/*JP0_4*/PinConf(GPIO_Out, 1),/*5v output pin*/	/*																						*/
/*JP0_5*/__ThisPin_NotMount__,	/*	1_I=>NMI	1_O=>RTCA0OUT	2_I=>TAUJ0I3	2_O=>TAUJ0O3							*/
/*JP0_6*/__ThisPin_NotMount__,	/*																						*/
/*JP0_7*/__ThisPin_NotMount__,	/*																						*/
/*JP0_8*/__ThisPin_NotMount__,	/*																						*/
/*JP0_9*/__ThisPin_NotMount__,	/*																						*/
/*JP0_10*/__ThisPin_NotMount__,	/*																					*/
/*JP0_11*/__ThisPin_NotMount__,	/*																					*/
/*JP0_12*/__ThisPin_NotMount__,	/*																					*/
/*JP0_13*/__ThisPin_NotMount__,	/*																					*/
/*JP0_14*/__ThisPin_NotMount__,	/*																					*/
/*JP0_15*/__ThisPin_NotMount__,	/*																					*/


};



#define APinConf(InOut,PinResetLevel)	 PinConf(InOut,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_APort[MCU_MaxAPortMount*MCU_MaxPinPerPort]=
{
/********************************************************************************
This port only configuration for GPIO in/out, it has AD function in default
*************************************************************************************/
/*##################*/
/*Pin ID =====APort 0*/
/*##################*/
/*AP0_0*/__ThisPin_NotMount__,/*ADCA0I0*/
/*AP0_1*/__ThisPin_NotMount__,/*ADCA0I1*/
/*AP0_2*/__ThisPin_NotMount__,/*ADCA0I2*/
/*AP0_3*/__ThisPin_NotMount__,/*ADCA0I3*/
/*AP0_4*/__ThisPin_NotMount__,/*ADCA0I4*/
/*AP0_5*/__ThisPin_NotMount__,/*ADCA0I5*/
/*AP0_6*/__ThisPin_NotMount__,/*ADCA0I6*/
/*AP0_7*/__ThisPin_NotMount__,/*ADCA0I7*/
/*AP0_8*/__ThisPin_NotMount__,/*ADCA0I8*/
/*AP0_9*/__ThisPin_NotMount__,/*ADCA0I9*/
/*AP0_10*/__ThisPin_NotMount__,/*ADCA0I10*/
/*AP0_11*/__ThisPin_NotMount__,/*ADCA0I11*/
/*AP0_12*/__ThisPin_NotMount__,/*ADCA0I12*/
/*AP0_13*/__ThisPin_NotMount__,/*ADCA0I13*/
/*AP0_14*/__ThisPin_NotMount__,/*ADCA0I14*/
/*AP0_15*/__ThisPin_NotMount__,/*ADCA0I15*/

/*##################*/
/*Pin ID =====APort 1*/
/*##################*/
/*AP1_0*/__ThisPin_NotMount__,/*ADCA1I0*/
/*AP1_1*/__ThisPin_NotMount__,/*ADCA1I1*/
/*AP1_2*/__ThisPin_NotMount__,/*ADCA1I2*/
/*AP1_3*/__ThisPin_NotMount__,/*ADCA1I3*/
/*AP1_4*/__ThisPin_NotMount__,/*ADCA1I4*/
/*AP1_5*/__ThisPin_NotMount__,/*ADCA1I5*/
/*AP1_6*/__ThisPin_NotMount__,/*ADCA1I6*/
/*AP1_7*/__ThisPin_NotMount__,/*ADCA1I7*/
/*AP1_8*/__ThisPin_NotMount__,/*ADCA1I8*/
/*AP1_9*/__ThisPin_NotMount__,/*ADCA1I9*/
/*AP1_10*/__ThisPin_NotMount__,/*ADCA1I10*/
/*AP1_11*/__ThisPin_NotMount__,/*ADCA1I11*/
/*AP1_12*/__ThisPin_NotMount__,/*ADCA1I12*/
/*AP1_13*/__ThisPin_NotMount__,/*ADCA1I13*/
/*AP1_14*/__ThisPin_NotMount__,/*ADCA1I14*/
/*AP1_15*/__ThisPin_NotMount__,/*ADCA1I15*/

};


#define IPinConf(PinResetLevel)	PinConf(GPIO_In,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_IPort[MCU_MaxIPortMount*MCU_MaxPinPerPort]=
{
/********************************************************************************
This pin input only!!!                                                              
*************************************************************************************/
/*##################*/
/*Pin ID =====IPort 0*/
/*##################*/
/*IP0_0*/__ThisPin_NotMount__,
/*IP0_1*/__ThisPin_NotMount__,
/*IP0_2*/__ThisPin_NotMount__,
/*IP0_3*/__ThisPin_NotMount__,
/*IP0_4*/__ThisPin_NotMount__,
/*IP0_5*/__ThisPin_NotMount__,
/*IP0_6*/__ThisPin_NotMount__,
/*IP0_7*/__ThisPin_NotMount__,
/*IP0_8*/__ThisPin_NotMount__,
/*IP0_9*/__ThisPin_NotMount__,
/*IP0_10*/__ThisPin_NotMount__,
/*IP0_11*/__ThisPin_NotMount__,
/*IP0_12*/__ThisPin_NotMount__,
/*IP0_13*/__ThisPin_NotMount__,
/*IP0_14*/__ThisPin_NotMount__,
/*IP0_15*/__ThisPin_NotMount__,
};






#if (MCU_mOSTMModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		OSTM setting   
		@@@@@@@@@@		  
####################################################*/

#define __ThisOSTM_NotMount__			{0u,0u,MCU_vNotExpINT}
#define OSTMconfig(tick_us, startWhenReset,callback)	{tick_us, startWhenReset,callback}

void FRAME_vTick(void);
MCU_tstOSTM_UsrCfg MCU_stOSTMCfg[MCU_mOSTM_Mun]=
{
	OSTMconfig(1000, 1,FRAME_vTick),
	//__ThisOSTM_NotMount__,
};



#endif /*end of MCU_mOSTMModuleEnable*/





#if (MCU_mPWGAModuleEnable !=0u)
/*##################################################
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
		/*******************************/
		__ThisPWGA_NotMount__,/*channel 0*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,

		/*******************************/
		__ThisPWGA_NotMount__,/*channel 10*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 20*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 30*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 40*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 50*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 60*/ 
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,


		/*******************************/
		__ThisPWGA_NotMount__,/*channel 70*/ 
		__ThisPWGA_NotMount__,


	},

};
#endif /*end of MCU_mPWGAModuleEnable*/

#if ((MCU_mTAUBDModuleEnable !=0u)||(MCU_mTAUJModuleEnable !=0u))
/*##################################################
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

uint32 MCU_stTAUxClkDivCfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit][4]=
{
/*clock divider is [SourceClk / (2^SettingValue)]
        SettingValue range= [0 ,15]         */

	/*TAUB0 group*/TAUxClk_Div(0,0,0,0),
	/*TAUB1 group*/TAUxClk_Div(0,0,0,0),
	/*TAUD0 group*/TAUxClk_Div(0,0,0,0),
	/*TAUJ0 group*/ TAUxClk_Div(0,0,0,0),
	/*TAUJ1 group*/ TAUxClk_Div(0,0,0,0),
};

void FRAME_vTaskTimeTick(void);
MCU_tstTAUx_UsrCfg MCU_stTAUXCfg[MCU_mTAUB0_Channel * MCU_mTAUB_Unit + \
								MCU_mTAUD0_Channel * MCU_mTAUD_Unit+\
								MCU_mTAUJ0_Channel * MCU_mTAUJ_Unit]=
{

	/***********TAUB0*************/
	__Timer_Not_Mount__,/*channel 0*/
	TimerMode(0,100,0,FRAME_vTaskTimeTick),/*use for measure the task time*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,/*channel 8*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	
	/***********TAUB1*************/
	__Timer_Not_Mount__,/*channel 0*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,/*channel 8*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	
	/***********TAUD0*************/
	__Timer_Not_Mount__,/*channel 0*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,/*channel 8*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	
	/***********TAUJ0*************/
	__Timer_Not_Mount__,/*channel 0*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	
	/***********TAUJ1*************/
	__Timer_Not_Mount__,/*channel 0*/
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	__Timer_Not_Mount__,
	
};
#endif /*end of ((MCU_mTAUBDModuleEnable !=0u)||(MCU_mTAUJModuleEnable !=0u))*/




#if (MCU_mIICModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		IIC setting   
		@@@@@@@@@@		  
####################################################*/

#define __ThisRIIC_NotMount__	{0x00,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}

MCU_tstRIIC_UsrCfg MCU_tstRIICCfg=
{
	0,/*bps*/
	__ThisRIIC_NotMount__,/*slave 0 config*/
};
#endif /*end of MCU_mIICModuleEnable*/




#if (MCU_mRLIN3UartModuleEnable !=0u)
/*##################################################
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
	__ThisRLIN3UART_NotMount__,/*channel 0*/
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
	
	__ThisRLIN3UART_NotMount__,/*channel 3*/
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
};
#endif /*end of MCU_mRLIN3UartModuleEnable*/


#if (MCU_mDMAModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		DMA setting   
		@@@@@@@@@@		  
####################################################*/

#define Source_Increment_Dest_Increment		0
#define Source_Increment_Dest_Fix		1
#define Source_Fix_Dest_Increment		4
#define Source_Fix_Dest_Fix				5

#define DMA_Uint_8bit	0
#define DMA_Uint_16bit	1
#define DMA_Uint_32bit	2

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	MCU_vNotExpINT}
#define DMAconfig(source,dest,AddrCtrl,DataSize,DataLen,StartTrigNum)		{source,dest,AddrCtrl,DataSize,DataLen,StartTrigNum,MCU_vNotExpINT}

MCU_tstDMA_UsrCfg MCU_stDMACfg[MCU_mDMA_MaxChn]=
{
	__This_DMA_NotMounted__,/*channel 0*/
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,/*channel 8*/
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
	__This_DMA_NotMounted__,
};
#endif /*end of MCU_mDMAModuleEnable*/

#if (MCU_mEINTModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		EINT setting   
		@@@@@@@@@@		  
####################################################*/

#define RisingEdge		1u
#define FaillingEdge 	2u
#define BothEdge 	3u
#define LowLevel	4u
#define HighLevel	5u
#define EINT_NotUse 0xFFFFu

#define __ThisEINT_NotMount__				{EINT_NotUse,0u,MCU_vNotExpINT}
#define EINTconfig(trigger,RunInReset,Callback)	{trigger,RunInReset,Callback}


void IGN_ifIgn2ExternInterrupt(void);
MCU_tstEINT_UsrCfg MCU_stEINTCfg[MCU_mMaxEINTchannelMount]=
{
	__ThisEINT_NotMount__,/*channel 0*/
	__ThisEINT_NotMount__,
	EINTconfig(RisingEdge,0,IGN_ifIgn2ExternInterrupt),	/*k15 intp*/
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,/*channel 8*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
};
#endif /*end of MCU_mEINTModuleEnable*/

#if (MCU_mADCModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		ADC setting   
		@@@@@@@@@@		  

ADCA0I0 ID = 0          (12Bit AD, use 10bit Only)
ADCA0I0S ID = 16      (10Bit AD,)

####################################################*/

MCU_tstADCA_UsrCfg MCU_stADCACfg=
{
	0, /*	ADCA0: 	channel 0 ~31*/
	0, /*			channel 32 ~63*/
	
	0, /*	ADCA1: 	channel 0 ~31*/
	0, /*			channel 32 ~63*/
	
};
#endif /*end of MCU_mADCModuleEnable*/

#define SpiClkType0	0
#define SpiClkType1	1
#define SpiClkType2	2
#define SpiClkType3	3
#define SpiParityNone	0u
#define SpiParityZero	1u
#define SpiParityOdd	2u
#define SpiParityEven	3u


#if (MCU_mCSIGModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIG setting   
		@@@@@@@@@@		  
####################################################*/
#define CSGI_Cfg(bps,lsb,clktype,parity,SendCB,RecCB,ErrCB)	{bps,lsb,clktype,0,0,parity,SendCB,RecCB,ErrCB}
#define __CSGI_Not_Mount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIG_UsrCfg MCU_tstCSIGCfg[MCU_mCSIG_MaxChn]=
{
	__CSGI_Not_Mount__,
	__CSGI_Not_Mount__,
};
#endif /*end of MCU_mCSIGModuleEnable*/



#if (MCU_mCSIHModuleEnable !=0u)
/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIH setting   
		@@@@@@@@@@		  
####################################################*/
#define CSHI_Cfg(lsb,clktype,bps,parity,SendCB,RecCB,ErrCB)	{lsb,clktype,bps,0,0,parity,SendCB,RecCB,ErrCB}
#define __CSHI_Not_Mount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIH_UsrCfg MCU_tstCSIHCfg[MCU_mCSIH_MaxChn]=
{

	__CSHI_Not_Mount__,
	__CSHI_Not_Mount__,
	__CSHI_Not_Mount__,
	__CSHI_Not_Mount__,
	
};
#endif /*end of MCU_mCSIHModuleEnable*/

/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		Dummy define for debug test_pin   
		@@@@@@@@@@		  
####################################################*/

#define Debug_SetPin_Clock(port,pin,HighLow)
#define Debug_SetPin_OSTM(port,pin,HighLow)
#define Debug_SetPin_WD(port,pin,HighLow)
#define Debug_SetPin_Reset(port,pin,HighLow)
#define Debug_SetPin_CSIx(port,pin,HighLow)
#define Debug_SetPin_EINT(port,pin,HighLow)
#define Debug_SetPin_TAUx(port,pin,HighLow)



