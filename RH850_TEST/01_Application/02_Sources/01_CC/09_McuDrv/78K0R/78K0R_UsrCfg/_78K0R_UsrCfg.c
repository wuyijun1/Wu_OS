/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial, special MCU is upd78F1xxx
| File Name: _78K0R_UsrCfg.c
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
| 2015.11.28  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifdef MCU_C

/*This file ONLY include in MCU.c for compiler*/

#if _78K0R_Debug == 0u







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

#if MCU_mPortModeEnable!=0u

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
/*P03_0*/__ThisPin_NotMount__,									
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
/*P04_2*/__ThisPin_NotMount__,									
/*P04_3*/__ThisPin_NotMount__,									
/*P04_4*/__ThisPin_NotMount__,									
/*P04_5*/__ThisPin_NotMount__,									
/*P04_6*/__ThisPin_NotMount__,									
/*P04_7*/__ThisPin_NotMount__,									

/*Port-05*/
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
		/*	Pin Value|Lock,	Pin Direc|Lock,	PullUp|	Lock,	Reserve*/									
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
/*P12_0*/__ThisPin_NotMount__,									
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
/*P15_0*/	__ThisPin_NotMount__,									
/*P15_1*/	__ThisPin_NotMount__,									
/*P15_2*/	__ThisPin_NotMount__,									
/*P15_3*/	__ThisPin_NotMount__,									
/*P15_4*/	__ThisPin_NotMount__,									
/*P15_5*/	__ThisPin_NotMount__,									
/*P15_6*/	__ThisPin_NotMount__,									
/*P15_7*/	__ThisPin_NotMount__,									

};
#endif



/*############################################################

			Timer Array resource user configeration for project
##############################################################


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

					x=	|7		6		5		4		3		2		1		0
Timer-2x		-------------------------------------------------------------------------
			Normal_Pin	|P157	P156	P155	P154	P53		P52		P51		P50
			------------------------------------------------------------------------
			ReLoacte_Pin 	|X		X		X		X		X		X		X		P45	
========================================================================
##############################################################*/

#define RunInRst	1u
#define NotRunInRst	0u

#define Re_LoadTimer	0x0000u
#define PPG_Mst		0x0801u
#define PPG_Slv		0x0409u
#define Countertype	0x1006u
#define Fredivtype		0x1000u
#define ICUtype_period		0x0104u
#define ICUtype_level		0x020cu

#define Without_Pin	0xffu
#define Normal_Pin		0x00u
#define ReLoacte_Pin		0x01u

#define RisingEdg	0u
#define FailingEdg	1u
#define BothEdg	2u

#define LowLevel	2u
#define HighLevel	3u

/****************************************
timer configeration list!!!!
****************************************/
#define Timer(INTtime_us, chgable,RunInReset,CallB_V)					{Re_LoadTimer,(INTtime_us-1),(chgable),Without_Pin,(RunInReset),(CallB_V)}
#define ICU_period(EdgeType, chgable,PinSel,RunInReset,CallB_32)		{ICUtype_period,(EdgeType),(chgable),(PinSel),(RunInReset),(CallB_32)}
#define ICU_Level(LevelType, chgable,PinSel,RunInReset,CallB_32)		{ICUtype_level,(LevelType),(chgable),(PinSel),(RunInReset),(CallB_32)}
#define Counter(CounteNumber, EdgeType,chgable,PinSel,RunInReset,CallB_V)	{Countertype,(CounteNumber-1),((EdgeType<<1)|chgable),(PinSel),(RunInReset),(CallB_V)}
#define FreDiver(FreDiv,chgable,InputPinSel,RunInReset)					{Fredivtype,(FreDiv-1),((BothEdg<<1)|chgable),(InputPinSel),(RunInReset),(MCU_vNotExpINT)}
#define PPG_Master(HZ, chgable)									{PPG_Mst,(HZ),(chgable),Without_Pin,1,MCU_vNotExpINT}
#define PPG_Slave(duty, PinSel)									{PPG_Slv,(duty),Unlock,(PinSel),1,MCU_vNotExpINT}

#define __ThisTimer_NotMount__		{0xFFFFu,0u,0u,0xffu,0u,MCU_vNotExpINT}
#define _Timer_NotUse_			{0xFFFFu,0u,0u,0xffu,0u,MCU_vNotExpINT}

#if MCU_mTimerModelEnable!=0u

const MCU_tstReloadTimerUserCfg MCU_stTimerArrayUsrCfg[MCU_mMaxTimerIDMount]=
{
/*for example:*********************************************************************
Timer-01 : Timer(1000, Lock,RunInRst,SYS_vTick),
********************************************************************************/

/*Timer-00*/	__ThisTimer_NotMount__,
/*Timer-01*/	__ThisTimer_NotMount__,
/*Timer-02*/	__ThisTimer_NotMount__,
/*Timer-03*/	__ThisTimer_NotMount__,
/*Timer-04*/	__ThisTimer_NotMount__,
/*Timer-05*/__ThisTimer_NotMount__,
/*Timer-06*/	__ThisTimer_NotMount__,
/*Timer-07*/ __ThisTimer_NotMount__,

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
/*Timer-25*/	__ThisTimer_NotMount__,
/*Timer-26*/	__ThisTimer_NotMount__,
/*Timer-27*/	__ThisTimer_NotMount__,

};

#endif



/*############################################################

			External Interrupt resource user configeration for project
##############################################################

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

#define Pin_INTP		0U
#define Pin_INTP_R	1U

#define __ThisEINT_NotMount__	{0xFFu,0u,0u,NotRunInRst,MCU_vNotExpINT}
#define _EINT_NotUse_			{0xFFu,0u,0u,NotRunInRst,MCU_vNotExpINT}

#define EINT_Conf(PinSel,EdgeType,EdgeChgable,RunInReset,INTservice)	{(PinSel),(EdgeType),(EdgeChgable),(RunInReset),(INTservice)}

#if MCU_mEINTModelEnable!=0u

const MCU_tstEINTCfg MCU_stEINTUsrCfg[MCU_mMaxEINTchannelMount]=
{
/*ExtInt_0 */	__ThisEINT_NotMount__,
/*ExtInt_1 */	__ThisEINT_NotMount__,
/*ExtInt_2 */	__ThisEINT_NotMount__,
/*ExtInt_3 */	__ThisEINT_NotMount__,
/*ExtInt_4 */	__ThisEINT_NotMount__,
/*ExtInt_5 */	__ThisEINT_NotMount__,
/*ExtInt_6 */	__ThisEINT_NotMount__,
/*ExtInt_7 */	__ThisEINT_NotMount__,
/*ExtInt_8 */	__ThisEINT_NotMount__,
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
	0x00000000UL,/*using channel need set it to 1*/
};
#endif


/*############################################################

			CSI  resource user configeration for project
##############################################################

#####   CSI00   #####:
---------------------------------------------------
			SSI00 	SCK00 	SI00 	SO00
=============================================
Normal_Pin :	P30 		P17 		P16 		P15
-----------------------------------------------------
ReLoacte_Pin :P63 		P60 		P61 		P62
=============================================

#####   CSI01   #####:
---------------------------------------------------
			SSI01 	SCK01 	SI01 	SO01
=============================================
Normal_Pin :	P77 		P76 		P75 		P74
-----------------------------------------------------
ReLoacte_Pin :X 		X 		X 		X
=============================================

#####    CSI10   #####:
---------------------------------------------------
			SSI10 	SCK10 	SI10 	SO10
=============================================
Normal_Pin :	X 		P10 		P11 		P12
-----------------------------------------------------
ReLoacte_Pin :X 		X 		X 		X
=============================================

#####    CSI11    #####:
---------------------------------------------------
			SSI10 	SCK10 	SI10 	SO10
=============================================
Normal_Pin :	X 		P10 		P11 		P12
-----------------------------------------------------
ReLoacte_Pin :X 		X 		X 		X
=============================================

*******************************************************************************/


#define LSB	1u
#define MSB	0u

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

#define CSI_conf(bps_K,Lsb,PinSel,ClkType,Transfinish,ErrCB)	\
			{Serial_CSI,ScrMap(1u,1u,ClkType,0U,Lsb,0U,15u),(uint16)((uint16)(16000u/2u/bps_K-1u)<<9u),(PinSel),Transfinish,MCU_vNotExpINT,ErrCB}
						
#define __This_CSI_NotMounted__	{0xFFFFU,0U,0U,0U,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

#if MCU_mCSImodelEnable!=0u
const MCU_tstCSICfg MCU_stCSIUsrCfg[MCU_mMaxCSIchannelMount]=
{
/*for example:*********************************************************************
CSI_01: CSI_conf(1000,MSB,Normal_Pin,CsiClkType_2,CSI_SendFinishCB,CSI_RecFinishCB,CSI_ErrCB)
********************************************************************************/
/*CSI_00*/	__This_CSI_NotMounted__,
/*CSI_01*/	__This_CSI_NotMounted__,
/*CSI_10*/	__This_CSI_NotMounted__,
/*CSI_11*/	__This_CSI_NotMounted__,
};

#endif


/*############################################################
			UART resource user configeration for project
##############################################################

				    Serial-UART2	
------------------------------------------------------
			 |	TXD2 	RXD2 	|	
=============================================
Normal_Pin :	 |	P42		P42		|	
-----------------------------------------------------
ReLoacte_Pin : |	X		X		|	
=============================================*/

#define ParityOdd	3u
#define ParityEven	2u
#define ParityZero	1u
#define ParityNone	0u

#define StpBit_1	0u
#define StpBit_2	1u

#define PinLogic_Normal		0u
#define PinLogic_Inversion	1u

#define __This_UART_NotMounted__	{0u,	0u,0u,0u,	0u,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u16}
#define _UART_NotUse_			{0u,	0u,0u,0u,	0u,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u16}

#define UART_Conf(bps,Lsb,ParityType,StopBits,LevelInvet,SendCB,RecCB,ErrCB)	\
				{(uint16)bps,Lsb,ParityType,StopBits,LevelInvet,SendCB,RecCB,ErrCB}

#if MCU_mSerialUartmodelEnable!=0u

/*for example:*********************************************************************
UART_2: UART_Conf(19200,MSB,ParityOdd,StpBit_1,PinLogic_Normal,UART2_SendFinishCB,UART2_RecCB,UART2_ErrCB)
********************************************************************************/

const MCU_tstUARTCfg MCU_stSerialUartUsrCfg=

__This_UART_NotMounted__;


#endif

/*############################################################
			Lin-UART resource user configeration for project
##############################################################

LIN-Uart Pin select configeration:

UARTF_1 pin select :  selectabel, 

			|	    LIN-UART0		|	    LIN-UAR1
------------------------------------------------------
			 |	LTXD0 	LRXD0 	|	LTXD1 	LRXD1 
=============================================
Normal_Pin :	 |	P13		P14		|	P10 		P11 		
-----------------------------------------------------
ReLoacte_Pin : |	X		X		|	P72 		P73 		
=============================================
******************************************************************************/

#define LIN_UARTConf(bps,Lsb,ParityType,StopBits,LevelInvet,PinSel,SendCB,RecCB,ErrCB)	\
				{(uint16)bps,Lsb,ParityType,StopBits,(LevelInvet |(PinSel<<1)),SendCB,RecCB,ErrCB}

#define __This_LinUART_NotMounted__ __This_UART_NotMounted__

#if MCU_mLinUart_modelEnable!=0u

const MCU_tstUARTCfg MCU_stLinUartUsrCfg[MCU_mMaxLinUartchannelMount]=
{
/*for example:*********************************************************************
LIN-UART_0: LIN_UARTConf(19200,MSB,ParityOdd,StpBit_1,PinLogic_Normal,UARTF0_SendFinishCB,UARTF0_RecCB,UARTF0_ErrCB)
********************************************************************************/
/*LIN-UART_0*/__This_LinUART_NotMounted__,
/*LIN-UART_1*/__This_LinUART_NotMounted__,
};

#endif



/*############################################################
			IIC resource user configeration for project
##############################################################

			 SDA 	SCL 	
=============================================
IIC_11 :	 	P61 		P60 		
-----------------------------------------------------
IIC_20 : 		P43 		P42 		
=============================================

Note:

	if using the port-6(OD-pin), it can not output high-level, 
	so it must connect a  resistance to VCC external!!!
	
**************************************************************************/

#define __This_IIC_NotMount__	{0u,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}
#define _IIC_NotUsed_			{0u,{MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u8}}

#define IIC_Conf(bps_K,SendFinishCB,RecFinishCB,ErrCB)	{(uint16)((uint16)(1000u/2u/(bps_K)-1u)<<9u),\
												{(SendFinishCB),(RecFinishCB),(ErrCB)}}

#if MCU_mIICmodelEnable !=0u
const MCU_tstIICCfg MCU_stI2CUsrCfg[MCU_mMaxIICMount]=
{
/*for example:*********************************************************************
IIC_20: IIC_Conf(50,IIC20_SendFinishCB,IIC20_RecFinishCB,IIC20_ErrCB)
********************************************************************************/
	/*channel_0 callback service*/
	__This_IIC_NotMount__,
	
	/*channel_1 callback service*/
	__This_IIC_NotMount__,	
	
};

#endif



/*############################################################
			DMA resource user configeration for project
##############################################################

DMA0-1 Control interrupt : 

		INTTM01_vect,	INTTM03_vect,	INTTM05_vect,	INTTM07_vect,
		INTTM11_vect	,	INTTM13_vect,	INTCSI10_vect,	INTLT0_vect,		
		INTLR0_vect,		INTLT1_vect,		INTLR1_vect,		INTCSI00_vect,
		INTCSI01_vect,	INTMD_vect,		INTAD_vect

DMA2-3 Control interrupt : 

		INTTM15_vect,	INTTM17_vect,	INTTM21_vect,	INTTM23_vect,
		INTIIC11_vect,	INTIIC20_vect,	INTSR2_vect,		INTLT0_vect,		
		INTLR0_vect,		INTLT1_vect,		INTLR1_vect,		INTCSI00_vect,
		INTCSI01_vect,	INTMD_vect,		INTAD_vect	

NOTE: 

	if using the DMA interrupt control, the controlled resource interrupt will not request !!!
	
***************************************************************************/

#define UnitByte	0u
#define UnitWord	1u

#define RegisterToRam	0u
#define RamToRegister	1u

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	0u}
#define _This_DMA_NotUsed_		{0u,	0u,0u,0u,0u,0u,	0u}

#define DMA_Conf(RegAddr,RamAddr,Direct,UnitSize,TotalSize,VecNum,DMAfinsihCB)	\
		{(RegAddr),(RamAddr),/*AddrUp*/0u,(Direct),(UnitSize),(TotalSize),(VecNum),(DMAfinsihCB)}

#if MCU_mDMAmodelEnable !=0u

const MCU_tstDMACfg MCU_stDMAUsrCfg[MCU_mMaxDMAchannelMount]=
{
/*for example:*********************************************************************
DMA0: DMA_Conf(TDR01,&TimerArrayValue,RamToRegister,UnitWord,20bytes,INTTM01_vect,DMA0_FinishCB)
********************************************************************************/
/*DMA0*/	__This_DMA_NotMounted__,
/*DMA1*/	__This_DMA_NotMounted__,
/*DMA2*/	__This_DMA_NotMounted__,
/*DMA3*/	__This_DMA_NotMounted__,
};	

#endif







#endif/*end of MCU_Debug*/


#endif/*end of this file*/


