/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _RH850_Debug.c
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

#if _RH850_Debug !=0U

#include "../RH850_Drv/_F1L_RegisterMap.h"

/*********************************************************************************

MCU Driver debug macro, 
set the occording macro to 1 for the module debug!

*********************************************************************************/

#define MCU_Debug_Clock		0
#define MCU_Debug_OSTM		0		
#define MCU_Debug_WatchDog		0
#define MCU_Debug_ResetMonitor		0
#define MCU_Debug_CSIx		0
#define MCU_Debug_EINT		0
#define MCU_Debug_TAUx		0
#define MCU_Debug_WakeUp		0
#define MCU_Debug_ADC		0

/*********************************************************************************

MCU Driver debug macro, 
to set the dubug pin for monitor

*********************************************************************************/
/***************************
Debug pin for monitor module: clock
****************************/
#if MCU_Debug_Clock
#define Debug_SetPin_Clock(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_Clock(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: OSTM
****************************/
#if MCU_Debug_OSTM
#define Debug_SetPin_OSTM(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_OSTM(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: WatchDog
****************************/
#if MCU_Debug_WatchDog
#define Debug_SetPin_WD(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_WD(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: Reset Monitor
****************************/
#if MCU_Debug_ResetMonitor
#define Debug_SetPin_Reset(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_Reset(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: CSIx
****************************/
#if MCU_Debug_CSIx
#define Debug_SetPin_CSIx(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else	
#define Debug_SetPin_CSIx(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: EINT
****************************/
#if MCU_Debug_EINT
#define Debug_SetPin_EINT(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_EINT(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: TAUx
****************************/
#if MCU_Debug_TAUx
#define Debug_SetPin_TAUx(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_TAUx(port,pin,HighLow)
#endif
/***************************
Debug pin for monitor module: wakeup
****************************/
#if MCU_Debug_WakeUp
#define Debug_SetPin_WakeUp(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_WakeUp(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: ADC
****************************/
#if MCU_Debug_ADC
#define Debug_SetPin_ADC(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_ADC(port,pin,HighLow)
#endif


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
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillFill}
*************************************************************************************/


/*##################*/
/*Pin ID =====Port 0*/
/*##################*/
/*P0_0*/__ThisPin_NotMount__,
/*P0_1*/PinConf(AltOut_1,1), /*PPG_TAUD0O4*/
/*P0_2*/PinConf(In,1),
/*P0_3*/PinConf(AltOut_1,1),
/*P0_4*/__ThisPin_NotMount__,
/*P0_5*/__ThisPin_NotMount__,
/*P0_6*/__ThisPin_NotMount__,
/*P0_7*/__ThisPin_NotMount__,
/*P0_8*/PinConf(AltIn_4,1),// TAUB0I2
/*P0_9*/PinConf(AltIn_1,0),// INT12
/*P0_10*/PinConf(AltIn_1,1),
/*P0_11*/PinConf_IICpin(AltOut_1), /* IIC SDA*/
/*P0_12*/PinConf_IICpin(AltOut_1),/* IIC SCL*/
/*P0_13*/PinConf(GPIO_Out,1),/*EERPOM WC*/
/*P0_14*/PinConf(AltOut_4,1),
/*P0_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 1*/
/*##################*/
/*P1_0*/__ThisPin_NotMount__,
/*P1_1*/__ThisPin_NotMount__,
/*P1_2*/__ThisPin_NotMount__,
/*P1_3*/__ThisPin_NotMount__,
/*P1_4*/__ThisPin_NotMount__,
/*P1_5*/__ThisPin_NotMount__,
/*P1_6*/__ThisPin_NotMount__,
/*P1_7*/__ThisPin_NotMount__,
/*P1_8*/__ThisPin_NotMount__,
/*P1_9*/__ThisPin_NotMount__,
/*P1_10*/__ThisPin_NotMount__,
/*P1_11*/__ThisPin_NotMount__,
/*P1_12*/__ThisPin_NotMount__,
/*P1_13*/__ThisPin_NotMount__,
/*P1_14*/__ThisPin_NotMount__,
/*P1_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 2*/
/*##################*/
/*P2_0*/__ThisPin_NotMount__,
/*P2_1*/__ThisPin_NotMount__,
/*P2_2*/__ThisPin_NotMount__,
/*P2_3*/__ThisPin_NotMount__,
/*P2_4*/__ThisPin_NotMount__,
/*P2_5*/__ThisPin_NotMount__,
/*P2_6*/__ThisPin_NotMount__,
/*P2_7*/__ThisPin_NotMount__,
/*P2_8*/__ThisPin_NotMount__,
/*P2_9*/__ThisPin_NotMount__,
/*P2_10*/__ThisPin_NotMount__,
/*P2_11*/__ThisPin_NotMount__,
/*P2_12*/__ThisPin_NotMount__,
/*P2_13*/__ThisPin_NotMount__,
/*P2_14*/__ThisPin_NotMount__,
/*P2_15*/__ThisPin_NotMount__,


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
/*P8_0*/PinConf(AltOut_2, 0),
/*P8_1*/PinConf(AltOut_2, 0),
/*P8_2*/PinConf(AltOut_3, 0),
/*P8_3*/PinConf(AltOut_3, 0),
/*P8_4*/PinConf(GPIO_Out, 1),
/*P8_5*/PinConf(AltOut_1, 0),
/*P8_6*/__ThisPin_NotMount__,
/*P8_7*/__ThisPin_NotMount__,
/*P8_8*/__ThisPin_NotMount__,
/*P8_9*/__ThisPin_NotMount__,
/*P8_10*/__ThisPin_NotMount__,
/*P8_11*/__ThisPin_NotMount__,
/*P8_12*/PinConf(GPIO_Out, 1),
/*P8_13*/__ThisPin_NotMount__,
/*P8_14*/__ThisPin_NotMount__,
/*P8_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 9*/
/*##################*/
/*P9_0*/PinConf(AltOut_1, 0),
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
/*P10_0*/PinConf(AltOut_2,1), /*F-out*/
/*P10_1*/PinConf(Out,0),
/*P10_2*/__ThisPin_NotMount__,//IIC
/*P10_3*/__ThisPin_NotMount__,//IIC
/*P10_4*/__ThisPin_NotMount__,
/*P10_5*/__ThisPin_NotMount__,
/*P10_6*/PinConf(AltOut_2,1),/*STM_MOSI*/
/*P10_7*/PinConf(AltOut_2,1),/*STM_CLK*/
/*P10_8*/PinConf(AltIn_2,1),/*STM_MISO*/
/*P10_9*/PinConf(GPIO_Out,1),/*STM_RESET*/
/*P10_10*/PinConf(GPIO_Out,1),/*STM_CS*/
/*P10_11*/PinConf(AltIn_4,1),
/*P10_12*/__ThisPin_NotMount__,
/*P10_13*/PinConf(AltOut_4,0),
/*P10_14*/__ThisPin_NotMount__,
/*P10_15*/PinConf(Out,1),


/*##################*/
/*Pin ID =====Port 11*/
/*##################*/
/*P11_0*/__ThisPin_NotMount__,
/*P11_1*/PinConf(AltOut_4,1),
/*P11_2*/PinConf(Out,0),
/*P11_3*/PinConf(Out,1),/*DC_Motor EN*/
/*P11_4*/PinConf(Out,1),/*DC_Motor CS*/
/*P11_5*/PinConf(AltIn_3,1),/*DC_Motor SI*/
/*P11_6*/PinConf(AltOut_3,1),/*DC_Motor SO*/
/*P11_7*/PinConf(AltOut_3,1),/*DC_Motor CLK*/
/*P11_8*/PinConf(AltIn_1,0),
/*P11_9*/PinConf(AltOut_1,1),
/*P11_10*/PinConf(AltOut_1,1),
/*P11_11*/__ThisPin_NotMount__,
/*P11_12*/__ThisPin_NotMount__,
/*P11_13*/PinConf(AltOut_3,0),
/*P11_14*/__ThisPin_NotMount__,
/*P11_15*/__ThisPin_NotMount__,


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
};

#define JPinConf(AltFun,PinResetLevel)	 PinConf(AltFun,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_JPort[MCU_MaxJPortMount *MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillFill}
*************************************************************************************/
/*##################*/
/*Pin ID =====JPort 0*/
/*##################*/
/*JP0_0*/__ThisPin_NotMount__,
/*JP0_1*/__ThisPin_NotMount__,
/*JP0_2*/__ThisPin_NotMount__,
/*JP0_3*/__ThisPin_NotMount__,
/*JP0_4*/__ThisPin_NotMount__,
/*JP0_5*/__ThisPin_NotMount__,
/*JP0_6*/__ThisPin_NotMount__,
/*JP0_7*/__ThisPin_NotMount__,
/*JP0_8*/__ThisPin_NotMount__,
/*JP0_9*/__ThisPin_NotMount__,
/*JP0_10*/__ThisPin_NotMount__,
/*JP0_11*/__ThisPin_NotMount__,
/*JP0_12*/__ThisPin_NotMount__,
/*JP0_13*/__ThisPin_NotMount__,
/*JP0_14*/__ThisPin_NotMount__,
/*JP0_15*/__ThisPin_NotMount__,
};



#define APinConf(InOut,PinResetLevel)	 PinConf(InOut,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_APort[MCU_MaxAPortMount*MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillFill}
*************************************************************************************/
/*##################*/
/*Pin ID =====APort 0*/
/*##################*/
/*AP0_0*/__ThisPin_NotMount__,
/*AP0_1*/__ThisPin_NotMount__,
/*AP0_2*/__ThisPin_NotMount__,
/*AP0_3*/__ThisPin_NotMount__,
/*AP0_4*/__ThisPin_NotMount__,
/*AP0_5*/__ThisPin_NotMount__,
/*AP0_6*/__ThisPin_NotMount__,
/*AP0_7*/__ThisPin_NotMount__,
/*AP0_8*/__ThisPin_NotMount__,
/*AP0_9*/__ThisPin_NotMount__,
/*AP0_10*/__ThisPin_NotMount__,
/*AP0_11*/__ThisPin_NotMount__,
/*AP0_12*/__ThisPin_NotMount__,
/*AP0_13*/__ThisPin_NotMount__,
/*AP0_14*/__ThisPin_NotMount__,
/*AP0_15*/__ThisPin_NotMount__,

/*##################*/
/*Pin ID =====APort 1*/
/*##################*/
/*AP1_0*/__ThisPin_NotMount__,
/*AP1_1*/__ThisPin_NotMount__,
/*AP1_2*/__ThisPin_NotMount__,
/*AP1_3*/__ThisPin_NotMount__,
/*AP1_4*/__ThisPin_NotMount__,
/*AP1_5*/__ThisPin_NotMount__,
/*AP1_6*/__ThisPin_NotMount__,
/*AP1_7*/__ThisPin_NotMount__,
/*AP1_8*/__ThisPin_NotMount__,
/*AP1_9*/__ThisPin_NotMount__,
/*AP1_10*/PinConf(Out,1),
/*AP1_11*/__ThisPin_NotMount__,
/*AP1_12*/__ThisPin_NotMount__,
/*AP1_13*/__ThisPin_NotMount__,
/*AP1_14*/__ThisPin_NotMount__,
/*AP1_15*/__ThisPin_NotMount__,

};


#define IPinConf(PinResetLevel)	PinConf(MCU_mPinFunConf_GPIO_In,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_IPort[MCU_MaxIPortMount*MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	FillFill}
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


#define MCU_CLK_UsingDefault	0xFFFFFFFE

#define PLL_MainOsc_8M_80M	0
#define PLL_MainOsc_8M_64M	1
#define PLL_MainOsc_8M_40M	2
#define PLL_MainOsc_8M_30M	3

#define PLL_MainOsc_16M_80M	4
#define PLL_MainOsc_16M_64M	5
#define PLL_MainOsc_16M_40M	6
#define PLL_MainOsc_16M_30M	7

MCU_tstClockUsrCfg MCU_stClockCfg_F1L=
{
1000,	/* MainOsc_StableTime*//*us*/
0,	/* MainOscStopInStandbyMode*/
	
0,	/* SubOsc_FTX_Speed*/
0,	/* SubOsc_StableTime*//*us*/
/*0,	 SubOscStopInStandbyMode*/
	
240000,	/* IntOscLS_FRL_Speed*/    /*240000, can not change*/
8000000,	/* IntOscHS_FRH_Speed*/   /*8000000, can not change*/

PLL_MainOsc_16M_64M,	/* CPLLCLK_Speed*/		/*CPU clock from PLL*/
0,	/* MEMCLK_Speed*/		/*external memery controller clock from PLL*/

	
2,	/* ClkDiv_C_AWO_WDTAD*//*	00B: Setting prohibited
								01B: LS IntOSC / 128 (default)
								10B: LS IntOSC */
								
								
/* 1,	WDTAStopInStandbyMode*/
	
2,	/* ClkSel_C_AWO_TAUJS*//*	000B: Disabled
								001B: HS IntOSC (default)
								010B: MainOSC
								011B: LS IntOSC
								100B: PPLLLCLK/2*/
								
1,	/* ClkDiv_C_AWO_TAUJD*//*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
0,	/* TAUJStopInStandbyMode*/
	
MCU_CLK_UsingDefault,	/* ClkSel_C_AWO_RTCAS*//*	00B: Disable (default)
								01B: SubOSC
								10B: MainOSC
								11B: LS IntOSC*/
								
MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_RTCAD*//*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
0,	/* RTCAStopInStandbyMode*/
								
2,	/* ClkSel_C_AWO_ADCAS*//*	00B: Disabled
								01B: HS IntOSC (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
MCU_CLK_UsingDefault,	/* ClkDiv_C_AWO_ADCAD*//*	001B: X/1 (default)
								010B:  X/2*/
								
0,	/* ADCAStopInStandbyMode*/
	
6,	/* ClkSel_C_AWO_FOUT*/ /*	000B: Disabled (default)
								001B: MainOSC
								010B: HS IntOSC
								011B: LS IntOSC
								100B: SubOSC
								101B: CPLLCLK/2
								110B: PPLLCLK/4*/
								
8,	/* ClkDiv_C_AWO_FOUT*/	/*1-->63 divide*/
	
	
3,	/* ClkSel_C_ISO_CPUCLKS*/	/*00B: Setting prohibited
								01B: EMCLK (default)
								10B: MainOSC
								11B: CPLLCLK--->we use defalu PLL output < -----*/
								
MCU_CLK_UsingDefault,	/* ClkDiv_C_ISO_CPUCLKD*/	/*	001B: X/1 (default)
								010B:  X/2
								011B:  X/4
								100B:  X/8*/
								
1,	/* ClkSel_C_ISO_PER1*/ /*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
1,	/* ClkSel_C_ISO_PER2*/ /*	00B: Disabled
								01B: CPUCLK/2 (default)
								10B: PPLLCLK*/
								
2,	/* ClkSel_C_ISO_LINS*/ /*		00B: Disabled
								01B: CPUCLK/2 (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
1,	/* ClkDiv_C_ISO_ILIND*//*	001B: X/1 (default)
								010B:  X/4
								011B: X/8*/								
0,	/* LINStopInStandbyMode*/
	
MCU_CLK_UsingDefault,// 2,	
/* ClkSel_C_ISO_ADCAS*//*	00B: Disabled
								01B: HS IntOSC RH (8 MHz) (default)
								10B: MainOSC
								11B: PPLLCLK/2*/
								
1,	/* ClkDiv_C_ISO_ADCAD*//*	001B: X/1 (default)
								010B:  X/2*/
								
1,	/* ClkSel_C_ISO_CANS*//*	00B: Disabled
									01B: MainOSC
									10B: CPLLCLK
									11B: CPUCLK (default)*/
									
0,	/* CANStopInStandbyMode*/
	
0,	/* ClkDiv_C_ISO_CANOSCD*//*	00B: Disabled (default)
								01B: MainOSC /1
								10B: MainOSC /2
								11B: Setting prohibited*/
								
0,	/* CANOSCStopInStandbyMode*/
	
1,	/* ClkSel_C_ISO_CSIS*//*	00B: Disabled
							01B: CPUCLK (default)
							10B: PPLLCLK*/
							
0,	/* CLMA0enable_HS*/		/*CLMA0 monitor unit,sample clock = LS*/
80,	/* CLMA0TolerancePercent*/
	
0,	/* CLMA1enable_MainOsc*/	/*CLMA1 monitor unit,sample clock = LS*/
80,	/* CLMA1TolerancePercent*/
	
0,	/* CLMA2enable_CPLLCLK*/	/*CLMA2 monitor unit,sample clock = HS*/
80	/* CLMA2TolerancePercent*/


};
/*
MCU_tstWatchDog_UsrCfg MCU_stWatchDogCfg=
{
	6,6
};
*/

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

void ISR_WatDog_0(void)
{
	Debug_SetPin_WD(11, 2,0);
}

void ISR_WatDog_1(void)
{
	Debug_SetPin_WD(11, 4,0);
}


const const MCU_tstFENMI_UsrCfg MCU_stFENMICfg=
{
	MCU_vNotExpINT,	/* TINM		0*/
	ISR_WatDog_0/*MCU_vNotExpINT*/,	/* WD0		1*/
	ISR_WatDog_1/*MCU_vNotExpINT*/,	/* WD1		2*/
};



//#include "PCA8539.h"
//#include "..\..\..\..\06_CplxDrv\DataFlash_RH850\FLS_Drv.h"

uint32 OSTM_INT;
uint32 duty=300,hz=1000;
uint16 cyctbl[10]={0xA0,-1,-1,500,800,1200,1500,2000,2500,3000};
uint16 RAW,RR;
uint16 Rectbl[10]={0xA0,-1,-1,500,800,1200,1500,2000,2500,3000};

uint16 testbuffer[50];
uint16 test_step;

extern MCU_tstCSIHModuleAttribute MCU_stCSIHAttribute;
uint8 u8Time;
uint8 u8TestStep=0;

#if 0
void OSTM_ISR(void)
{
            u8Time++;
            if((u8Time%10)==9)
            {
                u8TestStep++;
            }
            
	if(u8TestStep==0)/*PA-PB*/
	{
	    MCU_u16PinDirectCfg(MCU_mPinID_AP1_5, 0);
	    MCU_u16PinDirectCfg(MCU_mPinID_AP0_15, 1);
	    MCU_u16PinDirectCfg(MCU_mPinID_AP1_1, 0);
	    
	    MCU_u16PinWrite(MCU_mPinID_AP1_5, u8Time&1);/*output level*/
	    
	}
	else if(u8TestStep==1)/*PB-PA*/
	{

	    MCU_u16OSTMChgInterval(MCU_mOSTM_0, 500000);
	    
	    MCU_u16PinDirectCfg(MCU_mPinID_AP1_5, 1);
	    MCU_u16PinDirectCfg(MCU_mPinID_AP0_15, 0);
	    MCU_u16PinDirectCfg(MCU_mPinID_AP1_1, 0);
	    
	    MCU_u16PinWrite(MCU_mPinID_AP0_15, u8Time&1);/*output level*/
	    
	}
	else/*PA(ppg)-PB*/
	{

	    MCU_u16OSTMctrl(MCU_mOSTM_0, 0);
	}
	
}
#endif
uint32 get_current_stack(void)
{
#pragma asm    
         mov     r3,r10
#pragma endasm        
}

uint32 SP_Table[32];
void OSTM_ISR(void)
{
    uint16 Dutytable[6]={10,500,0,990,1200,80};
    static uint16 TblIndex;
    
    SP_Table[TblIndex]=get_current_stack();
    
    MCU_u16PWGASetDuty(MCU_mPWGA22, 990);
    MCU_u16PWGASetDuty(MCU_mPWGA23, 300);
    TblIndex++;

    TblIndex&=31;
}

#if 0
uint16 AD_Resalut_0[16];
uint16 AD_Resalut_1[16];
void OSTM_ISR(void)
{
        static  uint16 Testindex;
        
        Debug_SetPin_ADC(11,2,(Testindex+1)&1);  
        MCU_u16ADCgetResault(MCU_mADCID_ADCA0I0, &AD_Resalut_0[Testindex]);
        MCU_u16ADCgetResault(MCU_mADCID_ADCA1I0, &AD_Resalut_1[Testindex++]);
        if(Testindex>=16)
        {
           Testindex&=0xf;
        }
       
        MCU_u16ADCstart();
        
}
#endif
#if 0 
{
	MCU_tstDMA_SetUp stDMAsetup;

	++OSTM_INT;
	if(OSTM_INT==1000)
	{
//		MCU_u16PWGASetHz(MCU_mPWGA4,cyctbl[ duty++],800);


		stDMAsetup.u16AddrChgType=1;
		stDMAsetup.u16DataLenth=18;
		stDMAsetup.u16DataUnitSize=1;
		stDMAsetup.u16InterruptTrigID=41;
		stDMAsetup.u32DestAddr=(uint32)&MCU_stCSIHAttribute.CSIH[3].TX0H;
		stDMAsetup.u32DMAChannel=0;
		stDMAsetup.u32SourceAddr=(uint32)&cyctbl[0];
		
//		MCU_u16DMAsetup(stDMAsetup);		
		
		hz+=30;
		
		if(hz>4000)
			hz=100;

		OSTM_INT=0;		
		
//		duty++;
    
//		PCA8539_vDisplayUpdate( RAW&15, RR&31,cyctbl,10);
//		if(duty&1)
//		{
//			cyctbl[0]=0;
//			PCA8539_vDisplayUpdate( 1, 0,cyctbl,4);
//		}
//		else
//		{
//			cyctbl[0]=-1;
//			PCA8539_vDisplayUpdate( 1, 0,cyctbl,4);
//		}

//		MCU_u16DMAenable(0);
//		MCU_u16IIC_MasterStartCondition(0);
//		MCU_u16IIC_MasterSend(0,0, cyctbl, 3);

		MCU_u16ADCstart();
		
//		MCU_u16PWGASetDuty(MCU_mPWGA45, duty);
		if(duty>1000)
		{
			duty=0;
		}

//		MCU_u16TAUxPpgSetHz(MCU_mTAUB0_2, MCU_mTAUB0_10, hz, duty+=10);
//		MCU_u16RLIN3UartCtrl(MCU_mRLINUart3_0, 1, 1);

//		MCU_u16RLIN3UartSend(MCU_mRLINUart3_0, cyctbl, 16);

//		MCU_u16CSIG_MasterWrite(MCU_mCSIG_0, cyctbl, 10);
//		MCU_u16CSIG_MasterWrite(MCU_mCSIG_1, cyctbl, 10);
//		memset(Rectbl,0,sizeof(Rectbl));
//		MCU_u16CSIH_MasterSynchRW(MCU_mCSIH_3, cyctbl,Rectbl, 20);

//		MCU_u16TAUxPpgSetHz(MCU_mTAUB0_2, MCU_mTAUB0_12, hz, hz%1000);
//		MCU_u16TAUxPpgSetDuty(MCU_mTAUB0_2, MCU_mTAUB0_12,  hz%1000);
#if 0
	MCU_u16PinWrite(MCU_mPinID_P0_1,	testbuffer[0] &1);
	MCU_u16PinRead(MCU_mPinID_P0_0, &testbuffer[1]);
	
	testbuffer[0]++;

	if(test_step ==0)
	{
		test_step++;
		testbuffer[0]=FLS_u8EraseWait(0xFF200000ul, 64);
	}
	else if(test_step==1)
	{
		test_step++;
		memset(testbuffer,testbuffer[0],sizeof(testbuffer));
		testbuffer[0]=FLS_u8WriteDataWait(0xFF200000ul,testbuffer, 64);
	}
	else if(test_step==2)
	{
		test_step=0;
		memset(testbuffer,0,sizeof(testbuffer));
		testbuffer[0]=FLS_u8ReadDataWait(0xFF200000ul,testbuffer, 64);	
	}
#endif	
}

	
	
//	MCU_u16PinWrite(MCU_mPinID_JP0_3, testbuffer[0]&1);
//	MCU_u16PinWrite(MCU_mPinID_P10_7, testbuffer[0]&1);
	MCU_u16PinWrite(MCU_mPinID_P0_1,	testbuffer[0] &1);
//	MCU_u16PinWrite(MCU_mPinID_P10_6,	testbuffer[0] &1);

}
#endif


MCU_tstOSTM_UsrCfg MCU_stOSTMCfg[MCU_mOSTM_Mun]=
{
	{300,0,OSTM_ISR}
};

#define __ThisPWGA_NotMount__			{0xFFu,0u}
#define _Hz_NotUsed_			0xffffffff
#define PWGAconfig(FrequcySel,ResetDuty) {FrequcySel,ResetDuty}

MCU_tstPWGA_UsrCfg MCU_stPWGACfg=
{
	{
            	1300,
            	300,
            	_Hz_NotUsed_,
            	_Hz_NotUsed_
	},/*frequency in HZ*/
	
	{	
		__ThisPWGA_NotMount__,//  0
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 

		__ThisPWGA_NotMount__,// 10
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 

		__ThisPWGA_NotMount__,// 20
		__ThisPWGA_NotMount__,
		PWGAconfig(0,300),  // 22
		PWGAconfig(1,880), // 23
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 
		
		__ThisPWGA_NotMount__,// 30
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 

		__ThisPWGA_NotMount__,// 40
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 
		
		__ThisPWGA_NotMount__,// 50
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 
		
		__ThisPWGA_NotMount__,// 60
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,
		__ThisPWGA_NotMount__,// 

	
		__ThisPWGA_NotMount__,//70
		__ThisPWGA_NotMount__, 
	},

};

 /*   uint16 u16CntTbl[4]={3*(32*MEGA(1)/(1024*16)),
                                            5*(32*MEGA(1)/(1024*16)),
                                            7*(32*MEGA(1)/(1024*16)),
                                            4*(32*MEGA(1)/(1024*16))};
    MCU_u16TAUxSetCounter(MCU_mTAUB1_4,u16CntTbl[u32Time_B1_4&3]);
    */
uint32 u32Time_B1_4;
void Timer_B1_4(void)
{
    uint16 SetupTable[4]={ 1000,5000,400};
    static uint16 testduty=0;
return;

    if(testduty>=10)
    {
        u32Time_B1_4&=3;
        testduty=0;
        MCU_u16TAUxPpgSetHz(MCU_mTAUD0_4,SetupTable[u32Time_B1_4],++testduty*100);
        u32Time_B1_4++;
    }
    else
    {
        testduty+=3;
        if(testduty>=10)testduty=10;
        MCU_u16TAUxPpgSetDuty(MCU_mTAUD0_4,testduty*100);
    }
}

unsigned int CountCnt,TimeCnt,PulseIntervalCnt,PulseWidthCnt,FreDivCnt,UARTTest;
uint32 u32PulseTimeUS[4],u32PulseClkNum[4];
void Timer(void)
{
    TimeCnt++;
    Debug_SetPin_TAUx(11,2,TimeCnt&1);   
}
void Counter(void)
{
    uint32 u32CounterList[4]={10,20,30,40};
    static uint32 Cntindex;
    
    CountCnt++;
    Debug_SetPin_TAUx(11,3,CountCnt&1);
    MCU_u16TAUxSetCounter(MCU_mTAUB0_1,u32CounterList[Cntindex++&3]);
}

void PulseInterval_CB(void)
{

    PulseIntervalCnt++;
    Debug_SetPin_TAUx(11,4,PulseIntervalCnt&1);
    u32PulseTimeUS[PulseIntervalCnt&3]=MCU_u32TAUxGetTime(MCU_mTAUB0_2);
    u32PulseClkNum[PulseIntervalCnt&3]=MCU_u32TAUxGetCounter(MCU_mTAUB0_2);
}

void PulseWidth_CB(void)
{

    PulseWidthCnt++;
    Debug_SetPin_TAUx(11,5,PulseWidthCnt&1);

}
void FreDiv_CB(void)
{

    FreDivCnt++;
    Debug_SetPin_TAUx(10,5,FreDivCnt&1);
}

uint8 u8Uart_TxBuff[20],TX_Finish;
uint8 u8Uart_RxBuff[20],u8RxIndex;
void UART_test(void)
{
    uint16 loop;
    
    UARTTest++;
    UARTTest &=0xff;
    
    for(loop=0;loop<20;loop++)
    {
        u8Uart_TxBuff[loop]=loop+UARTTest;
    }

    MCU_u16RLIN3UartSend(MCU_mRLINUart3_0, u8Uart_TxBuff, 20);
    
}

/*
void Timer2(void)
{
Time2Cnt++;
}
void Timer3(void)
{
Time3Cnt++;
}
void Timer4(void)
{
        Time4Cnt++;
        if(Time4Cnt &1)
            	Debug_SetPin_OSTM(11,2,1);
	else 
	{
            	Debug_SetPin_OSTM(11,2,0);

            	MCU_vStandbyCtrl_CleanAllWakeUpFactor();
            	MCU_vStandbyCtrl_ChgToMode(MCU_mStopMode);
	}

}
*/
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
SettingValue range= [0 ,15] */

	/*TAUB0 group*/TAUxClk_Div(0,1,2,3),
	/*TAUB1 group*/TAUxClk_Div(0,1,6,3),
	/*TAUD0 group*/TAUxClk_Div(0,1,2,3),
	/*TAUJ0 group*/ TAUxClk_Div(0,1,2,3),
	/*TAUJ1 group*/ TAUxClk_Div(0,1,10,3),
};


void IIC_test(void);
void CSIH_Test(void);
void CSIG_Test(void);
void DMA_Test(void);

void TAUB0_1()
{
	static uint8 i;
	MCU_u16PinWrite(MCU_mPinID_P8_9, i++&1);
}


MCU_tstTAUx_UsrCfg MCU_stTAUXCfg[MCU_mTAUB0_Channel * MCU_mTAUB_Unit + \
								MCU_mTAUD0_Channel * MCU_mTAUD_Unit+\
								MCU_mTAUJ0_Channel * MCU_mTAUJ_Unit]=
{
/*TAUB0 group*/
TimerMode(0,100,1,Timer),
	TimerMode(0,100,1,Timer),
PulseInterval(3,TAUxTrige_BothEdge,0,PulseInterval_CB),
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
TimerMode(2,50000,1,Timer_B1_4),
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

/*TAUD0 group*/
PpgMaster(3,10000),
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
PpgSlave(650),
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
FrequencyDivider(12,1,FreDiv_CB),
__Timer_Not_Mount__,
__Timer_Not_Mount__,

/*TAUJ0 group*/
PpgMaster(0,20),
__Timer_Not_Mount__,
__Timer_Not_Mount__,
PpgSlave(400),


/*TAUJ1 group*/
TimerMode(2,1000,1,DMA_Test),/*TAUJ1_0 for DMA test*/
TimerMode(2,800000,1,CSIH_Test),/*TAUJ1_1 for CSIH test*/
//TimerMode(2,800000,1,CSIG_Test),/*TAUJ1_2 for CSIG test*/
TimerMode(2,800000,1,IIC_test),/*TAUJ1_3 for IIC test*/
__Timer_Not_Mount__
};

uint16 CSGI_Send,CSGI_Rec,CSGI_Err;
void CSGI_SendFinish(void)
{
        MCU_u16PinWrite(MCU_mPinID_P10_10, 1);
	CSGI_Send++;

}

void CSGI_RecFinish(void)
{
	CSGI_Rec++;

}

void CSGI_ErrCB(uint16 u16Err)
{
	CSGI_Err++;

}
uint16 CSIG_TestBuff[4]={0x83,0x55};
void CSIG_Test(void)
{
    static uint8 CSIG_Index;
    return;
    if(CSIG_Index<10)
    {
        CSIG_Index++;
        if(CSIG_Index &1)
        {
                MCU_u16PinWrite(MCU_mPinID_P10_10, 0);
                CSIG_TestBuff[0]=0x180f;
                CSIG_TestBuff[1]=0xffff;
                MCU_u16CSIG_MasterSynchRW(MCU_mCSIG_0, &CSIG_TestBuff[0], &CSIG_TestBuff[1], 2);
        }
        else
        {
                MCU_u16PinWrite(MCU_mPinID_P10_10, 0);
                CSIG_TestBuff[0]=0x20f0;
                CSIG_TestBuff[1]=0xffff;
                MCU_u16CSIG_MasterWrite(MCU_mCSIG_0, &CSIG_TestBuff[0], 2);        
        }
    }
}

#define CSGI_Cfg(lsb,clktype,bps,parity,SendCB,RecCB,ErrCB)	{lsb,clktype,bps,0,0,parity,SendCB,RecCB,ErrCB}
#define __CSGI_Not_Mount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIG_UsrCfg MCU_tstCSIGCfg[MCU_mCSIG_MaxChn]=
{
//	CSGI_Cfg(0,2,1500000,0,CSGI_SendFinish,CSGI_RecFinish,CSGI_ErrCB),
	CSGI_Cfg(1500000,0,2,0,CSIG_Test,MCU_vNotExpINT,MCU_vNotExpINT_u16),
	__CSGI_Not_Mount__,
};

uint16 CSHI_Send,CSHI_Rec,CSHI_Err;
void CSHI_SendFinish(void)
{
	CSHI_Send++;
         MCU_u16PinWrite(MCU_mPinID_P11_4, 1);

}

void CSHI_RecFinish(void)
{
	CSHI_Rec++;

}

void CSHI_ErrCB(uint16 u16Err)
{
	CSHI_Err++;

}

uint16 CSIH_TestBuff[4]={0x83,0x55};
void CSIH_Test(void)
{
    static uint8 CSIH_Index;
    if(CSIH_Index<10)
    {
        CSIH_Index++;
        if(CSIH_Index &1)
        {
                MCU_u16PinWrite(MCU_mPinID_P11_4, 0);
                CSIH_TestBuff[0]=0x83;
                CSIH_TestBuff[1]=0xff;
                MCU_u16CSIH_MasterSynchRW(MCU_mCSIH_3, &CSIH_TestBuff[0], &CSIH_TestBuff[1], 2);
        }
        else
        {
                MCU_u16PinWrite(MCU_mPinID_P11_4, 0);
                CSIH_TestBuff[0]=0xf0e3;
                CSIH_TestBuff[1]=0xaa;
                MCU_u16CSIH_MasterWrite(MCU_mCSIH_3, &CSIH_TestBuff[0], 2);        
        }
    }
}

#define CSHI_Cfg(lsb,clktype,bps,parity,SendCB,RecCB,ErrCB)	{lsb,clktype,bps,0,0,parity,SendCB,RecCB,ErrCB}
#define __CSHI_Not_Mount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT_u16}

MCU_tstCSIH_UsrCfg MCU_tstCSIHCfg[MCU_mCSIH_MaxChn]=
{

	__CSHI_Not_Mount__,
	__CSHI_Not_Mount__,
	__CSHI_Not_Mount__,
	CSHI_Cfg(1,2,1000000,0,CSHI_SendFinish,CSHI_RecFinish,CSHI_ErrCB),
	
};



uint8 RIIC_TxBufer[18]={0xa0/*Addr_W*/,20/*addr*/,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
uint8 RIIC_RxBufer[18]={0xa1/*Addr_R*/,20/*addr*/,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
uint8 RIIC_DrvStatus;
uint8 RIIC_T,RIIC_R,RIIC_E;

void RIIC_Isr_TX(void)
{
	RIIC_T++;
        if(RIIC_DrvStatus==0){
               MCU_u16PinWrite(MCU_mPinID_P0_13, 1);
        }
        else if(RIIC_DrvStatus==1)
        {/*read data from eerpom: step_2 = read out data from eeprom*/
            RIIC_DrvStatus=2;
           MCU_u16IIC_MasterRead(MCU_mRIIC_0, 0x50, &RIIC_RxBufer[2], 3);
        }
}
void RIIC_Isr_RX(void)
{    
    RIIC_DrvStatus=0;
}
void RIIC_Isr_ERR(uint8 u8err)
{
	RIIC_E=u8err;
}

static uint8 IICIndex;
void IIC_test(void)
{
     uint8 loop;
     return ;
    if(IICIndex<10)
    {
        IICIndex++;
        if(IICIndex&1)/*write data to eeprom*/
        {
            MCU_u16PinWrite(MCU_mPinID_P0_13, 0);
            for(loop=0;loop<16;loop++){
                RIIC_TxBufer[loop]=loop+0xe0;
            }
            RIIC_DrvStatus=0;
            RIIC_TxBufer[1]=20;/*EEPROM address*/
            MCU_u16IIC_MasterWrite(MCU_mRIIC_0, 0x50, &RIIC_TxBufer[1], 4);
        }
        else
        {/*read data from eerpom: step_1 = set eeprom address*/
                for(loop=0;loop<16;loop++){
                    RIIC_RxBufer[loop+2]=0xFF;
                }
                RIIC_DrvStatus=1;
                MCU_u16IIC_MasterWrite(MCU_mRIIC_0, 0x50, &RIIC_RxBufer[1], 1);
        }
    }
    Debug_SetPin_TAUx(10,3,IICIndex&1);
}


MCU_tstRIIC_UsrCfg MCU_tstRIICCfg=
{
	100000,/*bps*/
	{0x50,MCU_vNotExpINT,RIIC_Isr_TX,RIIC_Isr_RX,RIIC_Isr_ERR},/*slave 0 conf*/
};



#define Source_Increment_Dest_Increment		0
#define Source_Increment_Dest_Fix		1
#define Source_Fix_Dest_Increment		4
#define Source_Fix_Dest_Fix				5

#define DMA_Uint_8bit	0
#define DMA_Uint_16bit	1
#define DMA_Uint_32bit	2

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	MCU_vNotExpINT}

extern MCU_tstCSGICtrl MCU_stCsigRunStatus[MCU_mCSIG_MaxChn];
extern MCU_tstCSIGModuleAttribute MCU_stCSIGAttribute;
uint16 DMA_Done,DMA_TestBuff[20];
void DMA_Finish(void);

MCU_tstDMA_UsrCfg MCU_stDMACfg[MCU_mDMA_MaxChn]=
{
	{(uint32)&DMA_TestBuff[0],0xFFDB1008ul,Source_Increment_Dest_Fix,DMA_Uint_16bit,10,8,DMA_Finish},
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
void DMA_Finish(void)
{
        uint16 loop;
        
	DMA_Done++;
         MCU_u16PinWrite(MCU_mPinID_P10_10, 1);
        for(loop=0;loop<sizeof(DMA_TestBuff)/sizeof(uint16);loop++)
        {
            DMA_TestBuff[loop]=DMA_Done+loop;
        }
	/*YES, clear the status to ready for next*/
	MCU_stCsigRunStatus[0].u16WorkingMode=MCU_mCSIG_Ready;
}

void DMA_Test(void)
{
    static uint16 DMA_Index,loop;
    MCU_tstDMA_SetUp stDMAsetup;

     MCU_u16PinWrite(MCU_mPinID_P10_10, 0);
    if(DMA_Index++ & 1)
    {
        	stDMAsetup.u32DMAChannel=MCU_mDMA_0;
	stDMAsetup.u32SourceAddr=(uint32)&DMA_TestBuff[0];
	stDMAsetup.u32DestAddr=(uint32)&MCU_stCSIGAttribute.CSIG[0].TX0H.u16Value;
	stDMAsetup.u16AddrChgType=Source_Increment_Dest_Fix;
	stDMAsetup.u16DataUnitSize=DMA_Uint_16bit;		/*8bit or 16bit at once step, 1=byte, 2=word*/
	stDMAsetup.u16DataLenth=20;		/*how many byte data to transfer*/
	stDMAsetup.u16InterruptTrigID=MCU_mDMAtrig_INTCSIG0IC;
	stDMAsetup.vpINTservice=DMA_Finish;		/*interrupt function when DMA finish!*/

        MCU_u16DMAsetup(stDMAsetup);
        MCU_u16CSIG_MasterWrite(MCU_mCSIG_0, &DMA_TestBuff[0], 2);        

    }
    else
    {
         for(loop=0;loop<sizeof(DMA_TestBuff)/sizeof(uint16);loop++)
        {
            DMA_TestBuff[loop]=0x5ff5;
        }
        MCU_u16DMADefaultSetup(MCU_mDMA_0);
        MCU_u16CSIG_MasterWrite(MCU_mCSIG_0, &DMA_TestBuff[0], 2);        
        
    }
    
}


uint16 EINTCnt;

void EINT(void)
{
	EINTCnt++;
	Debug_SetPin_EINT(11,2,EINTCnt&1);
	
	if((EINTCnt/5) ==1)
	{
	    MCU_u16EINTchgIntCondition(MCU_mEINT_ID_INT12, MCU_enEintTrigger_RisingEdge);
	}
	else if((EINTCnt/5) ==2)
	{
	    MCU_u16EINTchgIntCondition(MCU_mEINT_ID_INT12, MCU_enEintTrigger_FaillingEdge);
	}
	else if((EINTCnt/5) ==3)
	{
	    MCU_u16EINTchgIntCondition(MCU_mEINT_ID_INT12, MCU_enEintTrigger_BothEdge);
	}
	else if((EINTCnt/5) ==4)
	{
	    MCU_u16EINTctrl(MCU_mEINT_ID_INT12, 0);
	}

}


#define DetDisable		0u
#define RisingEdge		1u
#define FaillingEdge 	2u
#define BothEdge 	3u
#define LowLevel	4u
#define HighLevel	5u
#define EINT_NotUse 0xFFFFu

#define __ThisEINT_NotMount__	{EINT_NotUse,0u,MCU_vNotExpINT}

MCU_tstEINT_UsrCfg MCU_stEINTCfg[MCU_mMaxEINTchannelMount]=
{
	__ThisEINT_NotMount__,/*ICP_0*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	{BothEdge,1,EINT},
	
	__ThisEINT_NotMount__,/*ICP_4*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,/*ICP_8*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	{BothEdge,1,EINT},/*ICP_12*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
};

MCU_tstADCA_UsrCfg MCU_stADCACfg=
{
	1,
	0,
	1,
	0,
};

void RLIN3_TxFinish(void)
{
    TX_Finish++;
}

void RLIN3_Rx(uint8 data)
{
          u8Uart_RxBuff[u8RxIndex++]=data;
	if(u8RxIndex>=20)
	{
          	u8RxIndex=0;
	}
}

void RLIN3_Err(uint8 err)
{
}

#define LSB	0u
#define MSB	1u
#define StpB1	0u
#define StpB2	1u
#define ParityNone	0u
#define ParityEven	1u
#define ParityZero	2u
#define ParityOdd	3u

#define __ThisRLIN3UART_NotMount__	{0,0,0,0,0,0,MCU_vNotExpINT,MCU_vNotExpINT_u8,MCU_vNotExpINT_u8}

#define RLIN3Uartconfig(bps,MSB,StopBit,Parity,RxInve,TxInve,SendCB,RecCB,ErrCB)	\
	{bps,MSB,StopBit,Parity,RxInve,TxInve,SendCB,RecCB,ErrCB}

MCU_tstLinUart_UsrCfg MCU_stRLIN3UsrCfg[MCU_mRLIN3Uint_Number]=
{
	RLIN3Uartconfig(19200,LSB,StpB1,ParityEven,0,0,RLIN3_TxFinish,RLIN3_Rx,RLIN3_Err),/*channel 0*/
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
	
	__ThisRLIN3UART_NotMount__,/*channel 3*/
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
};

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
		1,	/*	INTTAUJ0I3	*/
		0,	/*	WUTRG0	*/
		0,	/*	INTP6	*/
		0,	/*	INTP7	*/
		0,	/*	INTP8	*/
		1,	/*	INTP12	*/
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




//PCA8539_vDvrInit();

//	FLS_vDrvInit();
//	Debug_SetPinHigh(11, 4);
	//Debug_SetPinHigh(11, 2);

//	MCU_u16OSTMChgInterval(MCU_mOSTM_0,5000 );
//	MCU_vStandbyCtrl_ChgToMode(MCU_mStopMode);
//	MCU_vStandbyCtrl_ChgToMode(MCU_mStopMode);
//		*(uint32 *)0xFFC30028=1;
//		*(uint32 *)0xFFC30020=0X24;
//	flag=MCU_u32GetResetReason();	
//        MCU_vTAUxRunCtrl(MCU_mTAUJ0_3,1);

 //       MCU_u16EINTctrl(MCU_mEINT_ID_INT12, 1);

uint32 StackTop,StackButom;
extern int __ghsbegin_stack,__ghsbegin_stack;
void MCU_vDebugMain(void)
{
    uint16 i=9;
      i=  MCU_u16ADCstart();

/*      
      MCU_vTAUxRunCtrl(MCU_mTAUB0_0,1);
      MCU_vTAUxRunCtrl(MCU_mTAUB0_1,1);
      MCU_vTAUxRunCtrl(MCU_mTAUB0_2,1);
     MCU_vTAUxRunCtrl(MCU_mTAUB1_4,1);
    */ 

    MCU_u16RLIN3UartCtrl(MCU_mRLINUart3_0,1,1);
    
	while(1)
	{
                MCU_vWatchDogClean();
	}
}

#endif

