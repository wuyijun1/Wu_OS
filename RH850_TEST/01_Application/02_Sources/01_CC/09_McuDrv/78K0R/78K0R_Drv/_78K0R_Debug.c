/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial
| File Name: _78K0R_Debug.h
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
| 2016.01.20  V0.01	Tan, fumin	:create this module
********************************************************************************/
#if _78K0R_Debug !=0U


#if 1 /*map for usrcfg.c  and bebug sample code!!!*/

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
#define PU_On		1u/*Pull-Up use, it active only in input mode*/
#define FillField		0u


#define __ThisPin_NotMount__		{0u,0u,Out/*1u*/,0u,0u,0u,0u}
#define _Pin_NotUse_				{0u,0u,Out,0u,0u,0u,0u}
#define _Pin_UseAltFunc_			{0u,0u,1u,0u,0u,0u,0u,}


const MCU_tstPinCfg MCU_stPinUserCfg[MCU_mMaxPortInChip * MCU_mMaxPinsInPort]=
{
/*for exmpal:*******************************************************************************
{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField}
*************************************************************************************/
/*Port-00*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P03_0*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P03_1*/__ThisPin_NotMount__,									
/*P03_2*/__ThisPin_NotMount__,									
/*P03_3*/__ThisPin_NotMount__,									
/*P03_4*/__ThisPin_NotMount__,									
/*P03_5*/__ThisPin_NotMount__,									
/*P03_6*/__ThisPin_NotMount__,									
/*P03_7*/__ThisPin_NotMount__,									


/*Port-04*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P04_0*/__ThisPin_NotMount__,									
/*P04_1*/__ThisPin_NotMount__,									
/*P04_2*/{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P04_3*/{	Hi,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P04_4*/{	Lo,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P04_5*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P04_6*/__ThisPin_NotMount__,									
/*P04_7*/__ThisPin_NotMount__,									

/*Port-05*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P05_0*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P05_1*/__ThisPin_NotMount__,									
/*P05_2*/__ThisPin_NotMount__,									
/*P05_3*/__ThisPin_NotMount__,									
/*P05_4*/__ThisPin_NotMount__,									
/*P05_5*/__ThisPin_NotMount__,									
/*P05_6*/__ThisPin_NotMount__,									
/*P05_7*/__ThisPin_NotMount__,									


/*Port-06*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P06_0*/{	Hi,		Unlock,	Out,		Unlock,	PU_On,	Unlock,	FillField},									
/*P06_1*/{	Hi,		Unlock,	Out,		Unlock,	PU_On,	Unlock,	FillField},									
/*P06_2*/__ThisPin_NotMount__,									
/*P06_3*/__ThisPin_NotMount__,									
/*P06_4*/__ThisPin_NotMount__,									
/*P06_5*/__ThisPin_NotMount__,									
/*P06_6*/__ThisPin_NotMount__,									
/*P06_7*/__ThisPin_NotMount__,									


/*Port-07*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P07_0*/__ThisPin_NotMount__,									
/*P07_1*/__ThisPin_NotMount__,									
/*P07_2*/{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P07_3*/{	Hi,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P07_4*/{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P07_5*/{	Hi,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P07_6*/{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P07_7*/{	Hi,		Unlock,	Out,		Unlock,	PU_Off,	Unlock,	FillField},									


/*Port-08*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P08_0*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_1*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_2*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_3*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_4*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_5*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_6*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P08_7*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									


/*Port-09*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P09_0*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_1*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_2*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_3*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_4*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_5*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_6*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P09_7*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									


/*Port-10*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P10_0*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_1*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_2*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_3*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_4*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_5*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_6*/{	Lo,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P10_7*/{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									


/*Port-11*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P12_0*/{	Lo,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P12_1*/__ThisPin_NotMount__,									
/*P12_2*/__ThisPin_NotMount__,									
/*P12_3*/__ThisPin_NotMount__,									
/*P12_4*/__ThisPin_NotMount__,									
/*P12_5*/__ThisPin_NotMount__,									
/*P12_6*/__ThisPin_NotMount__,									
/*P12_7*/__ThisPin_NotMount__,									


/*Port-13*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P13_0--Output ONLY*/__ThisPin_NotMount__,									
/*P13_1*/__ThisPin_NotMount__,									
/*P13_2*/__ThisPin_NotMount__,									
/*P13_3*/__ThisPin_NotMount__,									
/*P13_4*/__ThisPin_NotMount__,									
/*P13_5*/__ThisPin_NotMount__,									
/*P13_6*/__ThisPin_NotMount__,									
/*P13_7*/__ThisPin_NotMount__,									


/*Port-14*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
/*=================================================================================*/
/*P15_0*/	{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P15_1*/	{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P15_2*/	{	Hi,		Unlock,	In,		Lock,	PU_Off,	Unlock,	FillField},									
/*P15_3*/	{	Hi,		Unlock,	Out,		Lock,	PU_Off,	Unlock,	FillField},									
/*P15_4*/	__ThisPin_NotMount__,									
/*P15_5*/	__ThisPin_NotMount__,									
/*P15_6*/	__ThisPin_NotMount__,									
/*P15_7*/	__ThisPin_NotMount__,									

};
#endif




#if MCU_mTimerModelEnable!=0u

/*############################################################
			Timer Array resource user configeration for project


timer input/output pin select map:

					x=	|7		6		5		4		3		2		1		0
Timer-0x		-------------------------------------------------------------------------
			Normal_Pin	|P41	P14		P40		P13		P125	P11		P30		P10
			------------------------------------------------------------------------
			ReLoacte_Pin 	|P44	P02		P00		P01		P127	P67		P126	P66
========================================================================

					x=	|7		6		5		4		3		2		1			0
Timer-1x		-------------------------------------------------------------------------
			Normal_Pin	|P71	P12		P70		P17		P32		P16		(P54 or P120)	P15
			------------------------------------------------------------------------
			ReLoacte_Pin 	|P57	P65		P56		P64		P55		P46		P31			P45	
========================================================================

		
##############################################################*/

#define Re_LoadTimer	0x0000u
#define PPG_Mst		0x0801u
#define PPG_Slv		0x0409u
#define Countertype	0x1006u
#define Fredivtype		0x1000u
#define ICUtype_period		0x0104u
#define ICUtype_level		0x020cu

#define Without_Pin	0xffu
#define Normal_Pin		0x00u
#define ReLoacte_Pin		0xfeu


#define Timer(INTtime, chgable,RunInReset,CallB_V)					{Re_LoadTimer,(INTtime-1),(chgable),Without_Pin,(RunInReset),(CallB_V)}
#define ICU_period(EdgeType, chgable,PinSel,RunInReset,CallB_32)		{ICUtype_period,(EdgeType),(chgable),(PinSel),(RunInReset),(CallB_32)}
#define ICU_Level(LevelType, chgable,PinSel,RunInReset,CallB_32)		{ICUtype_level,(LevelType),(chgable),(PinSel),(RunInReset),(CallB_32)}
#define Counter(CounteNumber, EdgeType,chgable,PinSel,RunInReset,CallB_V)	{Countertype,(CounteNumber-1),((EdgeType<<1)|chgable),(PinSel),(RunInReset),(CallB_V)}
#define FreDiver(FreDiv,chgable,PinSel,RunInReset)					{Fredivtype,(FreDiv-1),((BothEdg<<1)|chgable),(PinSel),(RunInReset),(MCU_vNotExpINT)}
#define PPG_Master(HZ, chgable)									{PPG_Mst,(HZ),(chgable),Without_Pin,1,MCU_vNotExpINT}
#define PPG_Slave(duty, PinSel)									{PPG_Slv,(duty),Unlock,(PinSel),1,MCU_vNotExpINT}

#define __ThisTimer_NotMount__		{0xFFFFu,0u,0u,0xffu,0u,MCU_vNotExpINT}
#define _Timer_NotUse_			{0xFFFFu,0u,0u,0xffu,0u,MCU_vNotExpINT}

#define RisingEdg	0u
#define FailingEdg	1u
#define BothEdg	2u

#define LowLevel	2u
#define HighLevel	3u

void Time1(void);
void Time2(void);
void ICU_CB(uint16 u16Value);

const MCU_tstReloadTimerUserCfg MCU_stTimerArrayUsrCfg[MCU_mMaxTimerIDMount]=
{
/*for example:*********************************************************************
{	Re_LoadTimer,	1000u	Unlock,		Without_Pin,	TimerINT0}
********************************************************************************/
			/*timer-type 		INT timer-us	Time chgable	using pin		runInReset	Interrupt CallBack*/
/*Timer-00*/	__ThisTimer_NotMount__,//PPG_Master(300,0),
/*Timer-01*/	__ThisTimer_NotMount__,
/*Timer-02*/	__ThisTimer_NotMount__,
/*Timer-03*/	__ThisTimer_NotMount__,
/*Timer-04*/	__ThisTimer_NotMount__,//PPG_Slave(200,0),
/*Timer-05*/__ThisTimer_NotMount__,//	PPG_Slave(200,0),
/*Timer-06*/	__ThisTimer_NotMount__,//PPG_Master(400,1),
/*Timer-07*/__ThisTimer_NotMount__,//	PPG_Slave(300,ReLoacte_Pin),

/*Timer-10*/	__ThisTimer_NotMount__,
/*Timer-11*/	__ThisTimer_NotMount__,
/*Timer-12*/	__ThisTimer_NotMount__,
/*Timer-13*/	__ThisTimer_NotMount__,
/*Timer-14*/	__ThisTimer_NotMount__,
/*Timer-15*/	__ThisTimer_NotMount__,
/*Timer-16*/	__ThisTimer_NotMount__,
/*Timer-17*/	__ThisTimer_NotMount__,

/*Timer-20*/	__ThisTimer_NotMount__,
/*Timer-21*/	__ThisTimer_NotMount__,
/*Timer-22*/	__ThisTimer_NotMount__,
/*Timer-23*/	__ThisTimer_NotMount__,
/*Timer-24*/	__ThisTimer_NotMount__,
/*Timer-25*/	__ThisTimer_NotMount__,//Timer(30000, 1,1,Time1),
/*Timer-26*/	__ThisTimer_NotMount__,
/*Timer-27*/	__ThisTimer_NotMount__,

};

#endif



#if MCU_mEINTModelEnable!=0u
/*############################################################

			External Interrupt resource user configeration for project

Interrupt input pin select:::::

		INT_ID:	0	1	2	3	4	5	6	7	8	
-------------------------------------------------------------
Pin_INTP		|   P120 P125  P30  P12   P32  P70  P71  P00  P47
-------------------------------------------------------------
Pin_INTP_R	|	X	X	P31	P50	X	X	X	X	X
-------------------------------------------------------------
############################################################*/

#define NotDetect 0u
#define Failling 1u
#define Rising	2u
#define Bothedge 3u

#define RunInRst	1u
#define NotRunInRst	0u

#define Pin_INTP		0U
#define Pin_INTP_R	1U

#define __ThisEINT_NotMount__	{0xFFu,0u,0u,NotRunInRst,MCU_vNotExpINT}
#define _EINT_NotUse_			{0xFFu,0u,0u,NotRunInRst,MCU_vNotExpINT}

const MCU_tstEINTCfg MCU_stEINTUsrCfg[MCU_mMaxEINTchannelMount]=
{
/*for example:*********************************************************************
{INT_R,		Rising,		Lock,	NotRunInRst,	TimerINT0}
********************************************************************************/
			/*input Pin	INTcondition |Lock		RunInRst		Interrupt CallBack*/
/*ExtInt_0 */	__ThisEINT_NotMount__,
/*ExtInt_1 */	__ThisEINT_NotMount__,
/*ExtInt_2 */	{Pin_INTP,		Failling,		Lock,	RunInRst,	MCU_vNotExpINT},
/*ExtInt_3 */	{Pin_INTP_R,		Bothedge,	Lock,	RunInRst,	MCU_vNotExpINT},
/*ExtInt_4 */	{Pin_INTP,		Bothedge,	Lock,	RunInRst,	MCU_vNotExpINT},
/*ExtInt_5 */	__ThisEINT_NotMount__,
/*ExtInt_6 */	__ThisEINT_NotMount__,
/*ExtInt_7 */	__ThisEINT_NotMount__,
/*ExtInt_8 */	{Pin_INTP,		Bothedge,	Lock,	RunInRst,	MCU_vNotExpINT},
	
};
#endif


#if MCU_mADCModelEnable!=0u
/*############################################################
			ADC resource user configeration for project
##############################################################*/
const MCU_tstADCCfg MCU_stADCUsrCfg=
{
/*for example:*********************************************************************
{	0x0000FFFF}
********************************************************************************/
	0x0000FFFFUL,/*using channel need set it to 1*/
};
#endif


#define SIN	0u
#define SIN_R	3u	
#define LSB	1u
#define MSB	0u
#define StpB1	0u
#define StpB2	1u

#define ParityOdd	3u
#define ParityEven	2u
#define ParityZero	1u
#define ParityNone	0u

#define Serial_CSI	0x8020u	/*select high speed clock for CSI, 16M default*/
#define Serial_IIC	0x0024u	/*select low speed clock for IIC & UART, 1M default*/
#define Serial_UART_S	0x0022u /*send*/
#define Serial_UART_R	0x0122u	/*receive*/

#define SerialType_NULL	0u
#define SerialType_CSI		1u
#define SerialType_IIC		2u
#define SerialType_UART	3u
#define SerialType_LIN_UART	4u

#define SerialReady		0u
#define SerialSending		1u
#define SerialReceiving		2u

#define CsiClkType_1	0u
#define CsiClkType_2	1u
#define CsiClkType_3	2u
#define CsiClkType_4	3u

#define Serial_Dummy_u8Data	0xffu
#define Serial_Dummy_u16Data	0xffffu

#define ScrMap(TX,RX,ClkTy,Pari,LMsb,StpBit,BitNum)	\
				(uint16)((uint16)((TX)<<15)|(uint16)((RX)<<14)|(uint16)((ClkTy)<<12)|(uint16)((Pari)<<8)|\
					(uint16)((LMsb)<<7)|(uint16)((StpBit)<<4)|(uint16)(BitNum))


/******************************************************************************
HighPin only for CSI_00

			SSI00 	SCK00 	SI00 	SO00
=============================================
HighPin =0 :	P30 		P17 		P16 		P15
-----------------------------------------------------
HighPin =1 :	P63 		P60 		P61 		P62
=============================================

*******************************************************************************/
#if MCU_mCSImodelEnable!=0u

#define CSI_conf(bps_K,Lsb,PinSel,ClkType,Transfinish,ErrCB)	\
			{Serial_CSI,ScrMap(1u,1u,ClkType,0U,Lsb,0U,15u),(uint16)((uint16)(16000u/2u/bps_K-1u)<<9u),(PinSel),Transfinish,MCU_vNotExpINT,ErrCB}
			
void CSI_SendFinish(void);
void CSI_ErrCallBack(uint16 u16Err);
void CSI_RecFinishCallBack(void);
void MCU_vNotExpINT_u16(uint16 u16Dummy);
			
#define __This_CSI_NotMounted__	{0xFFFFU,0U,0U,0U,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

const MCU_tstCSICfg MCU_stCSIUsrCfg[MCU_mMaxCSIchannelMount]=
{
/*CSI_00*/	__This_CSI_NotMounted__,
/*CSI_01*/	CSI_conf(2000, 0, 0,CsiClkType_2, CSI_SendFinish,  CSI_ErrCallBack),
/*CSI_10*/	__This_CSI_NotMounted__,
/*CSI_11*/	__This_CSI_NotMounted__,
		
};

#endif

#define __This_UART_NotMounted__	{0u,	0u,0u,0u,	0u,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u16}
#define _UART_NotUse_			{0u,	0u,0u,0u,	0u,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u16}

#if MCU_mSerialUartmodelEnable!=0u
/*############################################################
			UART resource user configeration for project
##############################################################*/
void UART2_SendCB(void);
void UART2_RecCB(uint8 u8data);
void UART2_ErrCB(uint16 u8err);

#define UARTConf(bps,Lsb,ParityType,StopBits,LevelInvet,SendCB,RecCB,ErrCB)	\
				{(uint16)bps,Lsb,ParityType,StopBits,LevelInvet,SendCB,RecCB,ErrCB}

/*Serial-UART2 configeration*/ 
const MCU_tstUARTCfg MCU_stSerialUartUsrCfg=
/*for example:*********************************************************************
		bps				L/MSB	StopBit	Parity				
		{19200u,			MSB,	StpB1,	ParityOdd,	
		send end callback	Error callback	recieve data callback
		UartSendFinish,		UartSendErr,	UartRecCallBack}
********************************************************************************/
/*__This_UART_NotMounted__*/
UARTConf(0, 1, ParityEven, 1, 0, UART2_SendCB,UART2_RecCB, UART2_ErrCB);

#endif

#if MCU_mLinUart_modelEnable!=0u
/******************************************************************************
LIN-Uart Pin select configeration:

UARTF_0 pin select : Can not selectabel, 
LTXD0 = P13,
LRXD0 = P14

UARTF_0 pin select :  selectabel, 
---------------------------------------------------
	PinSel: 	0			1
---------------------------------------------------
	LTXD1 	P10			P72
	LRXD1 	P11			P73
--------------------------------------------------------------

******************************************************************************/
#define LIN_UARTConf(bps,Lsb,ParityType,StopBits,LevelInvet,PinSel,SendCB,RecCB,ErrCB)	\
				{(uint16)bps,Lsb,ParityType,StopBits,(LevelInvet |(PinSel<<1)),SendCB,RecCB,ErrCB}

const MCU_tstUARTCfg MCU_stLinUartUsrCfg[MCU_mMaxLinUartchannelMount]=
{
/*for example:*********************************************************************
		bps				L/MSB	StopBit	Parity				
		{19200u,			MSB,	StpB1,	ParityOdd,	
		send end callback	Error callback	recieve data callback
		UartSendFinish,		UartSendErr,	UartRecCallBack}
********************************************************************************/

/*LIN -UARTconfigeration*/ 
/*__This_UART_NotMounted__*/
__This_UART_NotMounted__,
LIN_UARTConf(19200, 0, ParityEven, 1, 0, 1, UART2_SendCB,UART2_RecCB, UART2_ErrCB),

};

#endif


#if MCU_mIICmodelEnable !=0u
void IIC_ch20_Sendfinish(void);
void IIC_ch20_Recfinish(void);
void IIC_ch20_Err(uint8 u8err);
void IIC_ch11_Sendfinish(void);
void IIC_ch11_Recfinish(void);
void IIC_ch11_Err(uint8 u8err);

/*############################################################
			IIC resource user configeration for project
##############################################################*/
#define __This_IIC_NotMount__	{0u,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}
#define _IIC_NotUsed_			{0u,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}


#define IIC_SpeedConf(bps_K)	(uint16)((uint16)(1000u/2u/bps_K-1u)<<9u)

const MCU_tstIICCfg MCU_stI2CUsrCfg[MCU_mMaxIICMount]=
{
	{/*channel_0 callback service*/
		/* IIC speed*/
		0,//IIC_SpeedConf(10),
		{/*slave_0 callback service*/
			IIC_ch11_Sendfinish,IIC_ch11_Recfinish,IIC_ch11_Err,
		},		
	},
	
	{/*channel_1 callback service*/
		/* IIC speed */
		0,//IIC_SpeedConf(50),
		{/*slave_1 callback service*/
			IIC_ch20_Sendfinish,IIC_ch20_Recfinish,IIC_ch20_Err,
		},		
	}
	
};
#endif



#if MCU_mDMAmodelEnable !=0u
/*############################################################
			DMA resource user configeration for project
##############################################################*/

extern uint16 u16IICBUFF_11[50];
extern uint16 u16IICBUFF_20[50];

#define UnitByte	0u
#define UnitWord	1u

#define AddrUp	0u

#define RegisterToRam	0u
#define RamToRegister	1u

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	0u}
#define _This_DMA_NotUsed_		{0u,	0u,0u,0u,0u,0u,	0u}

const MCU_tstDMACfg MCU_stDMAUsrCfg[MCU_mMaxDMAchannelMount]=
{
/*for example:*********************************************************************
{0x001Au,		AddrLock	,	(uint32)MCU_au16AdcResault,	AddrUp,		UnitWord,	64u,		98u}
********************************************************************************/
		/*	Register		RAM					type	-Up-Only		direction 			unit			lenth	vectNum FinishCB	*/
/*DMA0*/	
/*DMA3*/	{(uint16)&SDR01,		(uint16)&u16IICBUFF_20[0],	AddrUp,		RegisterToRam,	UnitWord,		100,		INTCSI01_vect,		IIC_ch11_Recfinish},
			{(uint16)&SDR01,		(uint16)&u16IICBUFF_11[0],	AddrUp,		RamToRegister,	UnitWord,		100,		INTCSI01_vect,		IIC_ch11_Recfinish},
/*DMA1*/	__This_DMA_NotMounted__,
/*DMA2*/	__This_DMA_NotMounted__,
};	
#endif

#endif


/*************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************
**************************************************************************/

uint16 u16CSIBuff[10];

uint16 timer1,time2;
uint16 LEVEL=20;

uint16 u16EEP=6<<10;
uint16 u16IICBUFF_11[50];
uint16 u16IICBUFF_20[50];

void Time1(void)
{
	uint16 u16=800;
	timer1++;
	
//	MCU_u16PinDirectCfg(0x600, MCU_mPinMode_Output);
//	MCU_u16PinDirectCfg(0x601, MCU_mPinMode_Output);
	
//	MCU_u16PinWrite(0x600, timer1&1);
//	MCU_u16PinWrite(0x601, timer1&1);
	
//		CSIMK01=1;


//		for(LEVEL=0;LEVEL<50;LEVEL++)
	//	{
		//	u16IICBUFF_11[LEVEL]=0xffff;
//		}

//		u16IICBUFF_11[0]=u16EEP;

//	if(timer1 == 20)
//	{
//		timer1 =0;
//		for(LEVEL=0;LEVEL<50;LEVEL++)
//		{
//			u16IICBUFF_20[LEVEL]=0xaaaa;
//		}
			
//		MCU_u16DMAenable(0);
//		MCU_u16DMAenable(1);
		
//		MCU_u16PinWrite(0x707, 1);
		
//		SDR01=u16IICBUFF_11[0];
		
//		MCU_u16CSI_MasterSend(1, &u16EEP, 2);

//		MCU_u16IIC_MasterStartCondition(MCU_mSerial_ID_IIC11);

//		MCU_u16DMAStartTrig(2);
//		MCU_u16IIC_MasterSend(MCU_mSerial_ID_IIC11, 0, (uint8 *)&u16IICBUFF_11[0], 20);
		
//		MCU_u16IIC_MasterStartCondition(MCU_mSerial_ID_IIC20);
//		MCU_u16IIC_MasterSend(MCU_mSerial_ID_IIC20, 0, (uint8 *)&u16IICBUFF_20[0], 20);

//		MCU_u16SerialUartSend(MCU_mSerial_ID_UART2, (uint8 *)&u16IICBUFF_11[0], 20);
//		MCU_u16UARTsend(MCU_mSerial_ID_UARTF1, (uint8 *)&u16IICBUFF_11[0], 1);

	}

//}

void Time2(void)
{

/*	time2++;

	if(time2==2000)
	{
		MCU_u16FreDivdChg(MCU_mTimerArray_10, 10);
	}
	else if(time2==4000)
	{

		MCU_u16FreDivdChg(MCU_mTimerArray_10, 20);
		time2=0;
	}
	MCU_u16PinWrite(0x404, time2&1);
*/	
	
}

uint16 ICU_Time;
void ICU_CB(uint16 u16Value)
{


}


void MCU_vDebugMain(void)
{

	while(1)
	{

	
	}

}

uint16 u16CSIsendFinish,u16CSIerror;
uint16 u16EEPRec[100];
void CSI_SendFinish(void)
{
	u16CSIsendFinish++;

//	MCU_u16CSI_MasterRec(1, u16EEPRec, 100);
	
}

void CSI_ErrCallBack(uint16 u16Err)
{
	u16CSIerror++;
}

void CSI_RecFinishCallBack(void)
{
	u16CSIerror=99;
	MCU_u16PinWrite(0x707, 0);
	memset(u16EEPRec, 0xaaaa, 200);

}

uint8 u8IICerr_11,u8IICsend_11,u8IICrec_11;
uint8 u8IICerr_20,u8IICsend_20,u8IICrec_20;

void IIC_ch20_Sendfinish(void)
{
//	MCU_u16IIC_MasterStopCondition(MCU_mSerial_ID_IIC20);
	u8IICsend_20++;
}

void IIC_ch20_Recfinish(void)
{
	u8IICrec_20++;
}

void IIC_ch20_Err(uint8 u8err)
{
	u8IICerr_20=u8err;
}
void IIC_ch11_Sendfinish(void)
{
	MCU_u16IIC_MasterStopCondition(MCU_mSerial_ID_IIC11);
	u8IICsend_11++;
}

void IIC_ch11_Recfinish(void)
{
	u8IICrec_11++;

	MCU_u16PinWrite(0x707, 0);

}

void IIC_ch11_Err(uint8 u8err)
{
	u8IICerr_11=u8err;
}

uint16 u16UART2_ERR,u16UART2_Send,u16UART2_Rec;

void UART2_SendCB(void)
{
	u16UART2_Send = 0xaa;
	memset(u16IICBUFF_11,(uint8)u16UART2_Send, 20);
	
}
void UART2_RecCB(uint8 u8data)
{
	u16IICBUFF_20[u16UART2_Rec++] = u8data;

	if(u16UART2_Rec>=20)
		u16UART2_Rec=0;
}

void UART2_ErrCB(uint16 u8err)
{
	u16UART2_ERR=u8err;
}

#endif

