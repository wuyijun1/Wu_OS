/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial, special MCU is MB96F693Rx
| File Name: _16FX_UsrCfg.c
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2015 Huizhou Desay SV Automotive Co., Ltd.    All rights reserved.
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
| 2015.07.28  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifdef MCU_C
/*This file ONLY include in MCU.c for compiler*/

#if MCU_mPortModeEnable!=0u
/*############################################################
			Pin resource user configeration for project
##############################################################*/
#define Hi		1u/*High level when reset*/
#define Lo		0u/*Low level when reset*/
#define Lock		0u/*Pin attribute Un-changeable*/
#define Unlock		1u/*Pin attribute changeable*/
#define In		MCU_mPinMode_Input/*input mode*/
#define Out		MCU_mPinMode_Output/*output mode*/
#define PU_Off		0u/*Pull-Up not use*/
#define PU_On		1u/*Pull-Up use*/
#define PD_Off		0u/*Pull-Down not use*/
#define PD_On		1u/*Pull-Down use*/
#define HD_Off		0u/*High-Drv not use*/
#define HD_On		1u/*High-Drv use*/


#define __ThisPin_NotMount__		{0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u}
#define _Pin_NotUse_				{0u,0u,Out,0u,0u,0u,0u,0u,0u,0u,0u}
#define _Pin_UseAltFunc_			{0u,0u,In,0u,0u,0u,0u,0u,0u,0u,0u}

#define FillField		0u

const MCU_tstPinCfg MCU_stPinUserCfg[MCU_mMaxPortInChip * MCU_mMaxPinsInPort]=
{
/*for exmpal:*******************************************************************************
{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	PD_Off,	Unlock,	HD_Off,	Lock,	FillField}
*************************************************************************************/
/*Port-00*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P00_0*/__ThisPin_NotMount__,									
/*P00_1*/__ThisPin_NotMount__,									
/*P00_2*/__ThisPin_NotMount__,									
/*P00_3*/__ThisPin_NotMount__,									
/*P00_4*/__ThisPin_NotMount__,									
/*P00_5*/__ThisPin_NotMount__,									
/*P00_6*/__ThisPin_NotMount__,									
/*P00_7*/__ThisPin_NotMount__,									

/*Port-01*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P01_0*/__ThisPin_NotMount__,									
/*P01_1*/__ThisPin_NotMount__,									
/*P01_2*/__ThisPin_NotMount__,									
/*P01_3*/__ThisPin_NotMount__,									
/*P01_4*/__ThisPin_NotMount__,									
/*P01_5*/__ThisPin_NotMount__,									
/*P01_6*/__ThisPin_NotMount__,									
/*P01_7*/__ThisPin_NotMount__,									


/*Port-02*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P02_0*/__ThisPin_NotMount__,									
/*P02_1*/__ThisPin_NotMount__,									
/*P02_2*/__ThisPin_NotMount__,									
/*P02_3*/__ThisPin_NotMount__,									
/*P02_4*/__ThisPin_NotMount__,									
/*P02_5*/__ThisPin_NotMount__,									
/*P02_6*/__ThisPin_NotMount__,									
/*P02_7*/__ThisPin_NotMount__,									

/*Port-03*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P03_0*/__ThisPin_NotMount__,									
/*P03_1*/__ThisPin_NotMount__,									
/*P03_2*/__ThisPin_NotMount__,									
/*P03_3*/__ThisPin_NotMount__,									
/*P03_4*/__ThisPin_NotMount__,									
/*P03_5*/__ThisPin_NotMount__,									
/*P03_6*/__ThisPin_NotMount__,									
/*P03_7*/__ThisPin_NotMount__,									


/*Port-04*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P04_0*/__ThisPin_NotMount__,									
/*P04_1*/__ThisPin_NotMount__,									
/*P04_2*/__ThisPin_NotMount__,									
/*P04_3*/__ThisPin_NotMount__,									
/*P04_4*/__ThisPin_NotMount__,									
/*P04_5*/__ThisPin_NotMount__,									
/*P04_6*/__ThisPin_NotMount__,									
/*P04_7*/__ThisPin_NotMount__,									

/*Port-05*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P05_0*/__ThisPin_NotMount__,									
/*P05_1*/__ThisPin_NotMount__,									
/*P05_2*/__ThisPin_NotMount__,									
/*P05_3*/__ThisPin_NotMount__,									
/*P05_4*/__ThisPin_NotMount__,									
/*P05_5*/__ThisPin_NotMount__,									
/*P05_6*/__ThisPin_NotMount__,									
/*P05_7*/__ThisPin_NotMount__,									


/*Port-06*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P06_0*/__ThisPin_NotMount__,									
/*P06_1*/__ThisPin_NotMount__,									
/*P06_2*/__ThisPin_NotMount__,									
/*P06_3*/__ThisPin_NotMount__,									
/*P06_4*/__ThisPin_NotMount__,									
/*P06_5*/__ThisPin_NotMount__,									
/*P06_6*/__ThisPin_NotMount__,									
/*P06_7*/__ThisPin_NotMount__,									


/*Port-07*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P07_0*/__ThisPin_NotMount__,									
/*P07_1*/__ThisPin_NotMount__,									
/*P07_2*/__ThisPin_NotMount__,									
/*P07_3*/__ThisPin_NotMount__,									
/*P07_4*/__ThisPin_NotMount__,									
/*P07_5*/__ThisPin_NotMount__,									
/*P07_6*/__ThisPin_NotMount__,									
/*P07_7*/__ThisPin_NotMount__,									


/*Port-08*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P08_0*/__ThisPin_NotMount__,									
/*P08_1*/__ThisPin_NotMount__,									
/*P08_2*/__ThisPin_NotMount__,									
/*P08_3*/__ThisPin_NotMount__,									
/*P08_4*/__ThisPin_NotMount__,									
/*P08_5*/__ThisPin_NotMount__,									
/*P08_6*/__ThisPin_NotMount__,									
/*P08_7*/__ThisPin_NotMount__,									


/*Port-09*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P09_0*/__ThisPin_NotMount__,									
/*P09_1*/__ThisPin_NotMount__,									
/*P09_2*/__ThisPin_NotMount__,									
/*P09_3*/__ThisPin_NotMount__,									
/*P09_4*/__ThisPin_NotMount__,									
/*P09_5*/__ThisPin_NotMount__,									
/*P09_6*/__ThisPin_NotMount__,									
/*P09_7*/__ThisPin_NotMount__,									


/*Port-10*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P10_0*/__ThisPin_NotMount__,									
/*P10_1*/__ThisPin_NotMount__,									
/*P10_2*/__ThisPin_NotMount__,									
/*P10_3*/__ThisPin_NotMount__,									
/*P10_4*/__ThisPin_NotMount__,									
/*P10_5*/__ThisPin_NotMount__,									
/*P10_6*/__ThisPin_NotMount__,									
/*P10_7*/__ThisPin_NotMount__,									


/*Port-11*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P11_0*/__ThisPin_NotMount__,									
/*P11_1*/__ThisPin_NotMount__,									
/*P11_2*/__ThisPin_NotMount__,									
/*P11_3*/__ThisPin_NotMount__,									
/*P11_4*/__ThisPin_NotMount__,									
/*P11_5*/__ThisPin_NotMount__,									
/*P11_6*/__ThisPin_NotMount__,									
/*P11_7*/__ThisPin_NotMount__,									


/*Port-12*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P12_0*/__ThisPin_NotMount__,									
/*P12_1*/__ThisPin_NotMount__,									
/*P12_2*/__ThisPin_NotMount__,									
/*P12_3*/__ThisPin_NotMount__,									
/*P12_4*/__ThisPin_NotMount__,									
/*P12_5*/__ThisPin_NotMount__,									
/*P12_6*/__ThisPin_NotMount__,									
/*P12_7*/__ThisPin_NotMount__,									


/*Port-13*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P13_0*/__ThisPin_NotMount__,									
/*P13_1*/__ThisPin_NotMount__,									
/*P13_2*/__ThisPin_NotMount__,									
/*P13_3*/__ThisPin_NotMount__,									
/*P13_4*/__ThisPin_NotMount__,									
/*P13_5*/__ThisPin_NotMount__,									
/*P13_6*/__ThisPin_NotMount__,									
/*P13_7*/__ThisPin_NotMount__,									


/*Port-14*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P14_0*/	__ThisPin_NotMount__,									
/*P14_1*/	__ThisPin_NotMount__,									
/*P14_2*/	__ThisPin_NotMount__,									
/*P14_3*/	__ThisPin_NotMount__,									
/*P14_4*/	__ThisPin_NotMount__,									
/*P14_5*/	__ThisPin_NotMount__,									
/*P14_6*/	__ThisPin_NotMount__,									
/*P14_7*/	__ThisPin_NotMount__,									


/*Port-15*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P15_0*/	__ThisPin_NotMount__,									
/*P15_1*/	__ThisPin_NotMount__,									
/*P15_2*/	__ThisPin_NotMount__,									
/*P15_3*/	__ThisPin_NotMount__,									
/*P15_4*/	__ThisPin_NotMount__,									
/*P15_5*/	__ThisPin_NotMount__,									
/*P15_6*/	__ThisPin_NotMount__,									
/*P15_7*/	__ThisPin_NotMount__,									


/*Port-16*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P16_0*/	__ThisPin_NotMount__,									
/*P16_1*/	__ThisPin_NotMount__,									
/*P16_2*/	__ThisPin_NotMount__,									
/*P16_3*/	__ThisPin_NotMount__,									
/*P16_4*/	__ThisPin_NotMount__,									
/*P16_5*/	__ThisPin_NotMount__,									
/*P16_6*/	__ThisPin_NotMount__,									
/*P16_7*/	__ThisPin_NotMount__,									


/*Port-17*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P17_0*/	__ThisPin_NotMount__,									
/*P17_1*/	__ThisPin_NotMount__,									
/*P17_2*/	__ThisPin_NotMount__,									
/*P17_3*/	__ThisPin_NotMount__,									
/*P17_4*/	__ThisPin_NotMount__,									
/*P17_5*/	__ThisPin_NotMount__,									
/*P17_6*/	__ThisPin_NotMount__,									
/*P17_7*/	__ThisPin_NotMount__,									


/*Port-18*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P18_0*/	__ThisPin_NotMount__,									
/*P18_1*/	__ThisPin_NotMount__,									
/*P18_2*/	__ThisPin_NotMount__,									
/*P18_3*/	__ThisPin_NotMount__,									
/*P18_4*/	__ThisPin_NotMount__,									
/*P18_5*/	__ThisPin_NotMount__,									
/*P18_6*/	__ThisPin_NotMount__,									
/*P18_7*/	__ThisPin_NotMount__,									


/*Port-19*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	PullDown|Lock,	HDrv|	Lock,	Reserve*/									
/*=================================================================================*/
/*P19_0*/	__ThisPin_NotMount__,									
/*P19_1*/	__ThisPin_NotMount__,									
/*P19_2*/	__ThisPin_NotMount__,									
/*P19_3*/	__ThisPin_NotMount__,									
/*P19_4*/	__ThisPin_NotMount__,									
/*P19_5*/	__ThisPin_NotMount__,									
/*P19_6*/	__ThisPin_NotMount__,									
/*P19_7*/	__ThisPin_NotMount__,									

};
#endif





#if MCU_mTimerModelEnable!=0u
/*############################################################
			Re-Load Timer resource user configeration for project
##############################################################*/
#define __ThisTimer_NotMount__		{0u,MCU_mNotINTPriLevel,0u,MCU_vNotExpINT}
#define _Timer_NotUse_			{0u,MCU_mNotINTPriLevel,0u,MCU_vNotExpINT}

const MCU_tstReloadTimerUserCfg MCU_stReloadTimerUsrCfg[MCU_mMaxReLoadTimerMount]=
{
/*for example:*********************************************************************
{	1000u,		MCU_mTimerDefaultPriLevel,	Unlock,		TimerINT0}
********************************************************************************/
			/*INT timer-us	Vector Priority				Time chgable	Interrupt CallBack*/
/*Timer-0*/	__ThisTimer_NotMount__,
/*Timer-1*/	__ThisTimer_NotMount__,
/*Timer-2*/	__ThisTimer_NotMount__,
/*Timer-3*/	__ThisTimer_NotMount__,
/*Timer-6*/	__ThisTimer_NotMount__,
};

#endif




#if MCU_mPPGModeEnable!=0u
/*############################################################
			PPG resource user configeration for project
			
NOTE:
	the really output pin ID please refer to the _16FX_IO_xx0.c file for detial
	
##############################################################*/

#define Pin_PPG		0u
#define Pin_PPG_R		1u
#define Pin_PPG_B		2u
#define _PPG_NotUse_			{0xFFu,0u,0u,0u,0u}
#define __ThisPPG_NotMount__	{0xFFu,0u,0u,0u,0u}

const MCU_tstPPGCfg MCU_stPPGUsrCfg[MCU_mMaxPPGchannelMount]=
{
/*for example:*********************************************************************
{PPG_R,		130u,		950u,				0u,			1u}
********************************************************************************/
		/*OutputPin	HZ in defalut,	duty in defalut		HZ chgable	dutychgable*/
/*PPG0*/__ThisPPG_NotMount__,
/*PPG1*/__ThisPPG_NotMount__,
/*PPG2*/__ThisPPG_NotMount__,
/*PPG3*/__ThisPPG_NotMount__,
/*PPG4*/__ThisPPG_NotMount__,
/*PPG5*/__ThisPPG_NotMount__,
/*PPG6*/__ThisPPG_NotMount__,
/*PPG7*/__ThisPPG_NotMount__,
/*PPG8*/__ThisPPG_NotMount__,
/*PPG9*/__ThisPPG_NotMount__,
/*PPG10*/__ThisPPG_NotMount__,
/*PPG11*/__ThisPPG_NotMount__,
/*PPG12*/__ThisPPG_NotMount__,
/*PPG13*/__ThisPPG_NotMount__,
/*PPG14*/__ThisPPG_NotMount__,
/*PPG15*/__ThisPPG_NotMount__,
};
#endif


#if MCU_mEINTModelEnable!=0u
/*############################################################
			External Interrupt resource user configeration for project

NOTE:
	the really output pin ID please refer to the _16FX_IO_xx0.c file for detial

##############################################################*/
#define Pin_INT		0U
#define Pin_INT_R	1U
#define LowL	0u
#define HighL	1u
#define Rising	2u
#define Failling 3u
#define RunInRst	1u
#define NotRunInRst	0u

#define __ThisEINT_NotMount__	{0xFFu,0u,0u,NotRunInRst,MCU_mNotINTPriLevel,MCU_vNotExpINT}
#define _EINT_NotUse_			{0xFFu,0u,0u,NotRunInRst,MCU_mNotINTPriLevel,MCU_vNotExpINT}

const MCU_tstEINTCfg MCU_stEINTUsrCfg[MCU_mMaxEINTchannelMount]=
{
/*for example:*********************************************************************
{INT_R,		Rising,		Lock,	NotRunInRst,	MCU_mEINTDefaultPriLevel,	TimerINT0}
********************************************************************************/
			/*input Pin	INTcondition |Lock		RunInRst		Vector Priority				Interrupt CallBack*/
/*ExtInt_0 */	__ThisEINT_NotMount__,
/*ExtInt_1 */	__ThisEINT_NotMount__,
/*ExtInt_2 */	__ThisEINT_NotMount__,
/*ExtInt_3 */	__ThisEINT_NotMount__,
/*ExtInt_4 */	__ThisEINT_NotMount__,
/*ExtInt_5 */	__ThisEINT_NotMount__,
/*ExtInt_6 */	__ThisEINT_NotMount__,
/*ExtInt_7 */	__ThisEINT_NotMount__,
/*ExtInt_8 */	__ThisEINT_NotMount__,
/*ExtInt_9 */	__ThisEINT_NotMount__,
/*ExtInt_10 */__ThisEINT_NotMount__,
/*ExtInt_11 */__ThisEINT_NotMount__,
/*ExtInt_12 */__ThisEINT_NotMount__,
/*ExtInt_13 */__ThisEINT_NotMount__,
/*ExtInt_14 */__ThisEINT_NotMount__,
/*ExtInt_15 */__ThisEINT_NotMount__,
	
};
#endif






#if MCU_mADCModelEnable!=0u
/*############################################################
			ADC resource user configeration for project

NOTE:
	the really output pin ID please refer to the _16FX_IO_xx0.c file for detial

##############################################################*/
const MCU_tstADCCfg MCU_stADCUsrCfg=
{
/*for example:*********************************************************************
{5,		0x0FF00000}
********************************************************************************/
	MCU_mADCDefaultPriLevel,
	0x00000000UL,/*using channel set it to 1*/
};
#endif





#if MCU_mDMAmodelEnable !=0u
/*############################################################
			DMA resource user configeration for project
##############################################################*/

#define AddrLock	0u
#define AddrUp	1u
/*#define AddrDown	2u---->IOtype can not down, so do not use it*/
#define UnitByte	0u
#define UnitWord	1u

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	0u}
#define _This_DMA_NotUsed_		{0u,	0u,0u,0u,0u,0u,	0u}

extern __far uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount];
const MCU_tstDMACfg MCU_stDMAUsrCfg[MCU_mMaxDMAchannelMount]=
{
/*for example:*********************************************************************
extern __far uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount]---->the buffer or IO adrres must be __far type;
{0x001Au,		AddrLock	,	(uint32)MCU_au16AdcResault,	AddrUp,		UnitWord,	64u,		98u}
********************************************************************************/
		/*	From-		type			To-		type			unit			lenth	vectNum	*/
/*DMA0*/	{0x001Au,		AddrLock	,	(uint32)MCU_au16AdcResault,	AddrUp,		UnitWord,	64u,		98u},
/*DMA1*/	__This_DMA_NotMounted__,
/*DMA2*/	__This_DMA_NotMounted__,
/*DMA3*/	__This_DMA_NotMounted__,
/*DMA4*/	__This_DMA_NotMounted__,
/*DMA5*/	__This_DMA_NotMounted__,
/*DMA6*/	__This_DMA_NotMounted__,
/*DMA7*/	__This_DMA_NotMounted__,
/*DMA8*/	__This_DMA_NotMounted__,
/*DMA9*/	__This_DMA_NotMounted__,
/*DMA10*/	__This_DMA_NotMounted__,
/*DMA11*/	__This_DMA_NotMounted__,
/*DMA12*/	__This_DMA_NotMounted__,
/*DMA13*/	__This_DMA_NotMounted__,
/*DMA14*/	__This_DMA_NotMounted__,
/*DMA15*/	__This_DMA_NotMounted__,
};	
#endif






#if MCU_mUARTmodelEnable!=0u
/*############################################################
			UART resource user configeration for project

NOTE:
	the really output pin ID please refer to the _16FX_IO_xx0.c file for detial


##############################################################*/
#define SIN	0u
#define SIN_R	3u	/*reloacte pin can set independent:[ bit2=SCK_R,bit1 = SOT_R, bit0 = SIN_R ]*/
#define LSB	0u
#define MSB	1u
#define StpB1	0u
#define StpB2	1u

#define ParityOdd	3u
#define ParityEven	2u
#define ParityNone	0u

#define __This_UART_NotMounted__	{0u,	0u,0u,0u,	0u,MCU_mNotINTPriLevel,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u8}
#define _UART_NotUse_			{0u,	0u,0u,0u,	0u,MCU_mNotINTPriLevel,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u8}

const MCU_tstUARTCfg MCU_stUARTUsrCfg[MCU_mMaxUARTchannelMount]=
{
/*for example:*********************************************************************
		bps		PinR		L/MSB	StopBit	Parity		priority		
		{19200u,	SIN,		MSB,	StpB1,	ParityOdd,	MCU_mUARTDefaultPriLevel,
		send end callback	Error callback	recieve data callback
		UartSendFinish,		UartSendErr,	UartRecCallBack}
********************************************************************************/
/*UART0*/__This_UART_NotMounted__,
/*UART1*/__This_UART_NotMounted__,
/*UART2*/__This_UART_NotMounted__,
/*UART3*/__This_UART_NotMounted__,
/*UART4*/__This_UART_NotMounted__,
/*UART5*/__This_UART_NotMounted__,
/*UART6*/__This_UART_NotMounted__,
/*UART7*/__This_UART_NotMounted__,

};
#endif



#if MCU_mICUmodelEnable!=0u
/*############################################################
			ICU resource user configeration for project

NOTE:
	the really output pin ID please refer to the _16FX_IO_xx0.c file for detial

##############################################################*/
#define INn	0u
#define INn_R		1u

#define RisingEdg	1u
#define FailingEdg	2u
#define BothEdg	3u
#define __This_ICU_NotMounted__	{0xffu,0u,0u,MCU_mNotINTPriLevel,0u,MCU_vNotExpINT_u32_8}
#define _ICU_NotUsed_				{0xffu,0u,0u,MCU_mNotINTPriLevel,0u,MCU_vNotExpINT_u32_8}

const MCU_tstICUCfg MCU_stICUUsrCfg[MCU_mMaxICUchannelMount]=
{
/*for example:*********************************************************************
			{INn,		BothEdg,Lock,	MCU_mICUDefaultPriLevel,	RunInRst,	ICU_vDetCB}
********************************************************************************/
			/*PinLocate	DetLevl	Level	Lock	priority				RunInRst		callbakc*/
/*ICU0*/	__This_ICU_NotMounted__,
/*ICU1*/	__This_ICU_NotMounted__,
/*ICU2*/	__This_ICU_NotMounted__,
/*ICU3*/	__This_ICU_NotMounted__,
/*ICU4*/	__This_ICU_NotMounted__,
/*ICU5*/	__This_ICU_NotMounted__,
/*ICU6*/	__This_ICU_NotMounted__,
/*ICU7*/	__This_ICU_NotMounted__,
};
#endif



#if MCU_mLCDmodelEnable!=0u
/*############################################################
			ICU resource user configeration for project
##############################################################

=====================================================

	COM pin :		com3	com2	com1	com0
---------------------------------------------------------------
		|lowBit: 	bit3		bit2		bit1		bit0 	|	pin SEG_(2n)
VRAM_n  	|-----------------------------------|+++++++++++++++
		|HighBit:	bit7		bit6		bit5		bit4	|	pin SEG_(2n+1)
---------------------------------------------------------------
=======================================================*/
#define InternalVol		1u
#define ExternalVol		0u

#define Fre_13	0u
#define Fre_15	1u
#define Fre_17	2u
#define Fre_19	3u

#define Com_2	1u
#define Com_3	2u
#define Com_4	3u

const MCU_tstLCDCfg MCU_stLCDUsrCfg=
{
	/*voltage connect*/
	ExternalVol,
	/*driver frequency : = 16M / ((2^this_value) x Com_number))*/
	0,
	/*Com using mask*/
	0,
	/*Segment using mask, 1bit = one channel*/
	{
		/*Seg  7->0*/
		0x00u,
		/*Seg 15 ->8*/
		0x00u,
		/*Seg 23 ->16*/
		0x00u,
		/*Seg 31 ->24*/
		0x00u,
		/*Seg 39 ->32*/
		0x00u,
		/*Seg 47 ->40*/
		0x00u,
		/*Seg 55 ->48*/
		0x00u,
		/*Seg 63 ->56*/
		0x00u,
		/*Seg 71 ->64*/
		0x00u,
	},
	
};

#endif




#if MCU_mIICmodelEnable !=0u
/*############################################################
			IIC resource user configeration for project
##############################################################*/
#define __This_IIC_NotMount__	{0u,0xFFu,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}
#define _IIC_NotUsed_			{0u,0xFFu,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}



const MCU_tstIICCfg MCU_stI2CUsrCfg[MCU_mMaxIICMount]=
{
	{/*channel_0 callback service*/
		/*VectorPriority*/
		MCU_mIICDefaultPriLevel,
		/* IIC speed = 16M/((This_value * 12) + 17), This_value range is: 1u to 31u */
		0,
		
		{
			{/*slave_0 callback service*/
				MCU_vNotExpINT,
				MCU_vNotExpINT,
				MCU_vNotExpINT_u8,
			},		
		},
	},
};
#endif


#endif/*end of this file*/


