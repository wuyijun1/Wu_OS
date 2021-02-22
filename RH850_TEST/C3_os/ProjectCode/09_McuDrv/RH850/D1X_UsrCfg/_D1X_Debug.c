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
#define PinFill_0		0u

#define PinConf(AltFun,PinResetLevel)	\
	{AltFun,1,PinResetLevel,0/*PullUp*/,1,0/*PullDown*/,1,0/*OpenD*/,1,0/*PinBufType*/,1,0/*HighSpeed*/,1,PinFill_0}

#define __ThisPin_NotMount__	{0xFF,1,0,0/*PullUp*/,1,0/*PullDown*/,1,0/*OpenD*/,1,0/*PinBufType*/,1,0/*HighSpeed*/,1,PinFill_0}


const MCU_tstPinCfg MCU_stPinUserCfg_Port[MCU_MaxPortMount * MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	PinFill_0}
*************************************************************************************/


/*##################*/
/*Pin ID =====Port 0*/
/*##################*/
/*P0_0*/PinConf(GPIO_In,1),
/*P0_1*/__ThisPin_NotMount__,
/*P0_2*/PinConf(AltIn_1,1),
/*P0_3*/__ThisPin_NotMount__,
/*P0_4*/PinConf(AltOut_3,1),
/*P0_5*/__ThisPin_NotMount__,
/*P0_6*/__ThisPin_NotMount__,
/*P0_7*/__ThisPin_NotMount__,
/*P0_8*/PinConf(GPIO_Out,1),//
/*P0_9*/__ThisPin_NotMount__,
/*P0_10*/__ThisPin_NotMount__,
/*P0_11*/__ThisPin_NotMount__,
/*P0_12*/__ThisPin_NotMount__,
/*P0_13*/__ThisPin_NotMount__,
/*P0_14*/__ThisPin_NotMount__,
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
/*P2_0*/PinConf(AltOut_3,1),
/*P2_1*/PinConf(AltOut_3,1),
/*P2_2*/PinConf(GPIO_Out,1),//
/*P2_3*/__ThisPin_NotMount__,
/*P2_4*/__ThisPin_NotMount__,
/*P2_5*/__ThisPin_NotMount__,
/*P2_6*/__ThisPin_NotMount__,
/*P2_7*/__ThisPin_NotMount__,
/*P2_8*/__ThisPin_NotMount__,
/*P2_9*/__ThisPin_NotMount__,
/*P2_10*/PinConf(AltOut_2,1),//__ThisPin_NotMount__,
/*P2_11*/PinConf(AltOut_4,0),
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
/*P10_0*/__ThisPin_NotMount__,
/*P10_1*/__ThisPin_NotMount__,
/*P10_2*/__ThisPin_NotMount__,
/*P10_3*/__ThisPin_NotMount__,
/*P10_4*/__ThisPin_NotMount__,
/*P10_5*/__ThisPin_NotMount__,
/*P10_6*/__ThisPin_NotMount__,
/*P10_7*/__ThisPin_NotMount__,
/*P10_8*/__ThisPin_NotMount__,
/*P10_9*/__ThisPin_NotMount__,
/*P10_10*/__ThisPin_NotMount__,
/*P10_11*/__ThisPin_NotMount__,
/*P10_12*/__ThisPin_NotMount__,
/*P10_13*/__ThisPin_NotMount__,
/*P10_14*/__ThisPin_NotMount__,
/*P10_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 11*/
/*##################*/
/*P11_0*/__ThisPin_NotMount__,
/*P11_1*/__ThisPin_NotMount__,
/*P11_2*/__ThisPin_NotMount__,
/*P11_3*/__ThisPin_NotMount__,
/*P11_4*/__ThisPin_NotMount__,
/*P11_5*/__ThisPin_NotMount__,
/*P11_6*/__ThisPin_NotMount__,
/*P11_7*/PinConf(GPIO_Out,1),//__ThisPin_NotMount__,
/*P11_8*/__ThisPin_NotMount__,
/*P11_9*/__ThisPin_NotMount__,
/*P11_10*/__ThisPin_NotMount__,
/*P11_11*/__ThisPin_NotMount__,
/*P11_12*/__ThisPin_NotMount__,
/*P11_13*/__ThisPin_NotMount__,
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
/*P17_10*/PinConf(GPIO_Out, 1),
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


/*##################*/
/*Pin ID =====Port 21*/
/*##################*/
/*P21_0*/__ThisPin_NotMount__,
/*P21_1*/__ThisPin_NotMount__,
/*P21_2*/__ThisPin_NotMount__,
/*P21_3*/__ThisPin_NotMount__,
/*P21_4*/__ThisPin_NotMount__,
/*P21_5*/__ThisPin_NotMount__,
/*P21_6*/__ThisPin_NotMount__,
/*P21_7*/__ThisPin_NotMount__,
/*P21_8*/__ThisPin_NotMount__,
/*P21_9*/__ThisPin_NotMount__,
/*P21_10*/__ThisPin_NotMount__,
/*P21_11*/__ThisPin_NotMount__,
/*P21_12*/__ThisPin_NotMount__,
/*P21_13*/__ThisPin_NotMount__,
/*P21_14*/__ThisPin_NotMount__,
/*P21_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 22*/
/*##################*/
/*P22_0*/__ThisPin_NotMount__,
/*P22_1*/__ThisPin_NotMount__,
/*P22_2*/__ThisPin_NotMount__,
/*P22_3*/__ThisPin_NotMount__,
/*P22_4*/__ThisPin_NotMount__,
/*P22_5*/__ThisPin_NotMount__,
/*P22_6*/__ThisPin_NotMount__,
/*P22_7*/__ThisPin_NotMount__,
/*P22_8*/__ThisPin_NotMount__,
/*P22_9*/__ThisPin_NotMount__,
/*P22_10*/__ThisPin_NotMount__,
/*P22_11*/__ThisPin_NotMount__,
/*P22_12*/__ThisPin_NotMount__,
/*P22_13*/__ThisPin_NotMount__,
/*P22_14*/__ThisPin_NotMount__,
/*P22_15*/__ThisPin_NotMount__,


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
/*P40_0*/__ThisPin_NotMount__,
/*P40_1*/__ThisPin_NotMount__,
/*P40_2*/__ThisPin_NotMount__,
/*P40_3*/__ThisPin_NotMount__,
/*P40_4*/__ThisPin_NotMount__,
/*P40_5*/__ThisPin_NotMount__,
/*P40_6*/__ThisPin_NotMount__,
/*P40_7*/__ThisPin_NotMount__,
/*P40_8*/__ThisPin_NotMount__,
/*P40_9*/__ThisPin_NotMount__,
/*P40_10*/__ThisPin_NotMount__,
/*P40_11*/__ThisPin_NotMount__,
/*P40_12*/__ThisPin_NotMount__,
/*P40_13*/__ThisPin_NotMount__,
/*P40_14*/__ThisPin_NotMount__,
/*P40_15*/__ThisPin_NotMount__,


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
/*P42_0*/__ThisPin_NotMount__,
/*P42_1*/__ThisPin_NotMount__,
/*P42_2*/__ThisPin_NotMount__,
/*P42_3*/__ThisPin_NotMount__,
/*P42_4*/__ThisPin_NotMount__,
/*P42_5*/__ThisPin_NotMount__,
/*P42_6*/__ThisPin_NotMount__,
/*P42_7*/__ThisPin_NotMount__,
/*P42_8*/__ThisPin_NotMount__,
/*P42_9*/__ThisPin_NotMount__,
/*P42_10*/__ThisPin_NotMount__,
/*P42_11*/__ThisPin_NotMount__,
/*P42_12*/__ThisPin_NotMount__,
/*P42_13*/__ThisPin_NotMount__,
/*P42_14*/__ThisPin_NotMount__,
/*P42_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 43*/
/*##################*/
/*P43_0*/__ThisPin_NotMount__,
/*P43_1*/__ThisPin_NotMount__,
/*P43_2*/__ThisPin_NotMount__,
/*P43_3*/__ThisPin_NotMount__,
/*P43_4*/__ThisPin_NotMount__,
/*P43_5*/__ThisPin_NotMount__,
/*P43_6*/__ThisPin_NotMount__,
/*P43_7*/__ThisPin_NotMount__,
/*P43_8*/__ThisPin_NotMount__,
/*P43_9*/__ThisPin_NotMount__,
/*P43_10*/__ThisPin_NotMount__,
/*P43_11*/__ThisPin_NotMount__,
/*P43_12*/__ThisPin_NotMount__,
/*P43_13*/__ThisPin_NotMount__,
/*P43_14*/__ThisPin_NotMount__,
/*P43_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 44*/
/*##################*/
/*P44_0*/__ThisPin_NotMount__,
/*P44_1*/__ThisPin_NotMount__,
/*P44_2*/__ThisPin_NotMount__,
/*P44_3*/__ThisPin_NotMount__,
/*P44_4*/__ThisPin_NotMount__,
/*P44_5*/__ThisPin_NotMount__,
/*P44_6*/__ThisPin_NotMount__,
/*P44_7*/__ThisPin_NotMount__,
/*P44_8*/__ThisPin_NotMount__,
/*P44_9*/__ThisPin_NotMount__,
/*P44_10*/__ThisPin_NotMount__,
/*P44_11*/__ThisPin_NotMount__,
/*P44_12*/__ThisPin_NotMount__,
/*P44_13*/__ThisPin_NotMount__,
/*P44_14*/__ThisPin_NotMount__,
/*P44_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 45*/
/*##################*/
/*P45_0*/__ThisPin_NotMount__,
/*P45_1*/__ThisPin_NotMount__,
/*P45_2*/__ThisPin_NotMount__,
/*P45_3*/__ThisPin_NotMount__,
/*P45_4*/__ThisPin_NotMount__,
/*P45_5*/__ThisPin_NotMount__,
/*P45_6*/__ThisPin_NotMount__,
/*P45_7*/__ThisPin_NotMount__,
/*P45_8*/__ThisPin_NotMount__,
/*P45_9*/__ThisPin_NotMount__,
/*P45_10*/__ThisPin_NotMount__,
/*P45_11*/__ThisPin_NotMount__,
/*P45_12*/__ThisPin_NotMount__,
/*P45_13*/__ThisPin_NotMount__,
/*P45_14*/__ThisPin_NotMount__,
/*P45_15*/__ThisPin_NotMount__,


/*##################*/
/*Pin ID =====Port 46*/
/*##################*/
/*P46_0*/__ThisPin_NotMount__,
/*P46_1*/__ThisPin_NotMount__,
/*P46_2*/__ThisPin_NotMount__,
/*P46_3*/__ThisPin_NotMount__,
/*P46_4*/__ThisPin_NotMount__,
/*P46_5*/__ThisPin_NotMount__,
/*P46_6*/__ThisPin_NotMount__,
/*P46_7*/__ThisPin_NotMount__,
/*P46_8*/__ThisPin_NotMount__,
/*P46_9*/__ThisPin_NotMount__,
/*P46_10*/__ThisPin_NotMount__,
/*P46_11*/__ThisPin_NotMount__,
/*P46_12*/__ThisPin_NotMount__,
/*P46_13*/__ThisPin_NotMount__,
/*P46_14*/__ThisPin_NotMount__,
/*P46_15*/__ThisPin_NotMount__,

};

#define JPinConf(AltFun,PinResetLevel)	 PinConf(AltFun,PinResetLevel)

const MCU_tstPinCfg MCU_stPinUserCfg_JPort[MCU_MaxJPortMount *MCU_MaxPinPerPort]=
{
/*for exmpal:*******************************************************************************
{AltFun,	Lock,	Lo,	PU_Off,	lock,	PD_Off,	lock,	OD_Off,	Lock,	PinFill_0}
*************************************************************************************/
/*##################*/
/*Pin ID =====JPort 0*/
/*##################*/
/*JP0_0*/__ThisPin_NotMount__,
/*JP0_1*/__ThisPin_NotMount__,
/*JP0_2*/__ThisPin_NotMount__,
/*JP0_3*/PinConf(AltOut_3,1),
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
	3000,/*uint32 MainOsc_StableTime us*/
	MCU_CLK_UsingDefault,/*uint32 MainOscStopInStandbyMode;*/
	
	0,/*uint32 SubOsc_FTX_Speed*/
	0,/*uint32 SubOsc_StableTime;us*/
	MCU_CLK_UsingDefault,/*uint32 SubOscStopInStandbyMode;*/
	
	240000,/*uint32 IntOscLS_FRL_Speed;240000, can not change*/
	8000000,/*uint32 IntOscHS_FRH_Speed 8000000, can not change*/
	
	PLL_MainOsc_8M_480M,/*uint32 PLL0_Speed;		clock from PLL 0 --->default we use for CPU clock, not divider*/
	PLL1_MainOsc_8M_960M,/*uint32 PLL1_Speed;		clock from PLL 1*/
	PLL_MainOsc_8M_480M,/*uint32 PLL2_Speed;		clock from PLL 2*/
	
	MCU_CLK_UsingDefault,/*uint32 MEMCLK_Speed;		external memery controller clock from PLL --->ClkSel_CKSC_ISDRBS select the source clock*/


/*******************************
	ISO clock module
******************************/
	2,/*uint32 ClkSel_CKSC_ICLKJITS;
							
								01B: CKDV_ICLKJITD_CTL selection
								10B: High Speed IntOsc fRH (default)
							*/
							
	8,/*uint32 ClkDiv_CKSC_ICLKJITD;
							
								0000B: Disabled
								0100B: PLL0CLK /4
								0101B: PLL0CLK /5
								0110B: PLL0CLK /6 (default)
								1000B: PLL0CLK /8
								1010B: PLL0CLK /10
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ICLKFIXD;
								
									0000B: Disabled
									0110B: PLLFIXCLK /6 (default)
									1000B: PLLFIXCLK /8
									1010B: PLLFIXCLK /10
									1100B: PLLFIXCLK /12
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ICLKFIXS;
								
									01B: CKDV_ICLKFIXD_CTL selection
									10B: High Speed IntOsc fRH (default)
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPLLFIXS;
								
									01B: PLL1CLK (default)
									10B: PLL2CLK (D1M2(H) only)
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ISDRBS;
								
									0: Stop SDRBCLK clock (default)
									1: Activate SDRBCLK clock
								*/
	3,/*uint32 ClkSel_CKSC_ICPUCLKS;
								
									001B: EMCLK (default)
									011B: PLL0CLK --->we use this value for CPU clock
									100B: PLL1CLK

									Selection of PLL0CLK for the C_ISO_CPUCLK clock domain is not allowed, when the DDR2-SDRAM
									Memory Controller (SDRB) is used.
								*/
								
	2,/*uint32 ClkDiv_CKSC_ICPUCLKD;
								
									001B: CKSC_ICPUCLKS_CTL selection /1 (default)
									010B: CKSC_ICPUCLKS_CTL selection /2
									011B: CKSC_ICPUCLKS_CTL selection /4
									100B: CKSC_ICPUCLKS_CTL selection /8
									101B: CKSC_ICPUCLKS_CTL selection /3
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCCLKS;
								
									0: Stop C_ISO_XCCLK (default)
									1: Activate C_ISO_XCCLK
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCETNBS;
								
									0: Stop ETNBPCLK clock (default)
									1: Activate ETNBPCLK clock
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCETNBS;
								
									0: Stop ETNBXCCLK clock (default)
									1: Activate ETNBXCCLK clock
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCMLBBS;
								
									0: Stop MLBBPCLK clock (default)
									1: Activate MLBBPCLK clock
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IXCMLBBS;
								
									0: Stop MLBBXCCLK clock (default)
									1: Activate MLBBXCCLK
								*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IPCRSCANS;
								
									0: Stop RSCANPCLK clock
									1: Activate RSCANPCLK clock (default)
								*/

	MCU_CLK_UsingDefault,/*uint32 ClkSel_APB_CLK_RATIO;
								
									0: C_ISO_PCLK = C_ISO_CPUCLK / 2
									1: C_ISO_PCLK = C_ISO_CPUCLK / 4 (default)
								*/

/*******************************
	AWO clock module
******************************/

	2,/*uint32 ClkSel_CKSC_AAWOTS;
							
								000B: Disabled
								001B: High Speed IntOsc fRH (default)
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_AAWOTD;
							
								001B: CKSC_AAWOTS_CTL selection /1 (default)
								010B: CKSC_AAWOTS_CTL selection /2
								011B: CKSC_AAWOTS_CTL selection /4
								100B: CKSC_AAWOTS_CTL selection /8
								101B: CKSC_AAWOTS_CTL selection /16
							*/
	0,/*uint32 AAWOTStopInStandbyMode;*/
	
	1,/*uint32 ClkDiv_CKSC_AWDTA0D;
							
								001B: Low Speed IntOsc fRL / 128 (default)
								010B: Low Speed IntOsc fRL / 1
								011B: Low Speed IntOsc fRL / 256
								100B: Low Speed IntOsc fRL / 512
								101B: Low Speed IntOsc fRL / 1024
								110B: Low Speed IntOsc fRL / 2048
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ARTCAS;
							
								000B: Disable (default)
								001B: SubOsc fTX
								010B: MainOsc fX
								011B: Low Speed IntOsc fRL
								100B: High Speed IntOsc fRH
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ARTCAD;
							
								000B: Disabled (default)
								001B: CKSC_ARTCAS_CTL selection /1
								010B: CKSC_ARTCAS_CTL selection /2
								011B: CKSC_ARTCAS_CTL selection /4
								100B: CKSC_ARTCAS_CTL selection /8
								101B: CKSC_ARTCAS_CTL selection /16
							*/
	0,/*uint32 ARTCAStopInStandbyMode;*/
	
	5,/*uint32 ClkSel_CKSC_AFOUTS;
							
								000B: Disabled (default)
								001B: MainOsc fX
								010B: High Speed IntOsc fRH
								011B: Low Speed IntOsc fRL
								100B: SubOsc fTX
								101B: PLL0CLK/4
								110B: PLL1CLK/4
								111B: PLL2CLK/4 (D1M2(H) only)
							*/
	120,/*uint32 ClkDiv_CKSC_AFOUTD;
							
								source = CKSC_AFOUTS
								range: 0= disable, 1 <= range <=512
							*/
		
	0,/*uint32 AFOUTStopInStandbyMode;*/
	
/*******************************
	external clock module
******************************/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IMLBBS;
	
					NOTE:Max = 120Mhz
							
								00B: Disabled (default)
								01B: PLL0CLK /2
								10B: PLL0CLK /4
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ISFMAS
	
					NOTE:Max = 240Mhz
	
								01B: PLL0CLK
								10B: PLL1CLK (default)
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_ISFMAD;
							
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
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_IRSCAND;
					NOTE:Max = 40Mhz
							
								000B: Disabled
								001B: PLLFIXCLK /30
								010B: PLLFIXCLK /40
								011B: PLLFIXCLK /60
								100B: PLLFIXCLK /12 (default)
								101B: PLLFIXCLK /24
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IRSCANXINS;
					NOTE:Max = 16Mhz
							
								0: Disabled
								1: MainOsc fX (default).
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKDV_ISSIFD;
					NOTE:Max = 50Mhz
						
							source = PLLFIXCLK
							range: 0= disable, 1 <= range <=512
						*/
	
	1,/*uint32 ClkSel_CKSC_ITAUB01S;
					NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
							*/
	1,/*uint32 ClkSel_CKSC_ITAUB2S;
					NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
							*/
	1,/*uint32 ClkSel_CKSC_ITAUJS;
					NOTE:Max = 80Mhz
							
								000B: Disabled
								001B: CLKFIX /1
								010B: CLKFIX /8 (default)
								011B: CLKJIT /1
								100B: CLKJIT /8
								101B: MainOsc fX
								110B: C_ISO_CPUCLK /4
							*/
	1,/*uint32 ClkSel_CKSC_IOSTMS;
					NOTE:Max = 80Mhz
							
								00B: Disabled
								01B: CLKJIT
								10B: C_ISO_CPUCLK /4 (default)
								11B: MainOsc fX
							*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_ILCBIS;
					NOTE:Max = 80Mhz
						
							0: Disabled (default)
							1: CLKJIT
						*/
	MCU_CLK_UsingDefault,/*uint32 ClkDiv_CKSC_IADCED;
					NOTE:Max = 40Mhz
						
							01B: CLKJIT /2 (default)
							10B: CLKJIT /4
						*/
	MCU_CLK_UsingDefault,/*uint32 ClkSel_CKSC_IISMS;
					NOTE:Max = 80Mhz
						
							0: Disabled (default)
							1: CLKJIT
						*/
	2,/*uint32 ClkSel_CKSC_IRLINS;
						
					NOTE:Max = 48Mhz(D1Lx)
						 :Max = 24Mhz(D1M1x)
						 :Max = 48Mhz(D1M2x)
					
						 D1M1(H):
							01B: PLLFIXCLK /10
							10B: CLKJIT /1
							11B: PLLFIXCLK /20 (default)
							
						 All other devices:
							01B: PLLFIXCLK /10
							10B: CLKJIT /1 (default)
						*/

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


#if 0

MCU_tstFEMI_UsrCfg MCU_stFEMICfg=
{
	MCU_INT_NoUse,	/* LVIL		0*/
	MCU_INT_NoUse,	/* Reverce1	1*/
	MCU_INT_NoUse,	/* Reverce2	2*/
	MCU_INT_NoUse,	/* Reverce3	3*/
	MCU_INT_NoUse,	/* ECCDEEP0	4*/
	MCU_INT_NoUse,	/* Reverce5	5*/
	MCU_INT_NoUse,	/* ECCDCNRAM	6*/
	MCU_INT_NoUse,	/* ECCDCSIH0		7*/
	MCU_INT_NoUse,	/* ECCDCSIH1		8*/
	MCU_INT_NoUse,	/* ECCDCSIH2		9*/
	MCU_INT_NoUse,	/* ECCDCSIH3		10*/
	MCU_INT_NoUse,	/* Reverce11		11*/
	MCU_INT_NoUse,	/* ECCSDFLI0		12*/
	MCU_INT_NoUse,	/* ECCRAM		13*/
	MCU_INT_NoUse,	/* OSTM_0		14*/
	MCU_INT_NoUse,	/* LVIH			15*/	
};

const const MCU_tstFENMI_UsrCfg MCU_stFENMICfg=
{
	MCU_INT_NoUse,	/* TINM		0*/
	MCU_INT_NoUse,	/* WD0		1*/
	MCU_INT_NoUse,	/* WD1		2*/
};

#endif

uint32 OSTM_INT;
uint32 duty=0,hz=100;
uint8 cyctbl[18]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
uint8 RIICoutdata[16]={0};
uint8 RLIN3data[16]={0};
uint8 fixdata;

uint32 testcnt;

void OSTM_ISR(void)
{
	++OSTM_INT;
	if(OSTM_INT==250)
	{
		OSTM_INT=0;		
//		MCU_u16PWGASetHz(MCU_mPWGA4,cyctbl[ duty++],500);
		if(duty>=1000)
		{
			duty=0;
		}
		
		hz+=50;
		if(hz>4000)
		{
			hz=50;
		}
		
		MCU_u16PWGASetDuty(MCU_mPWGA10, duty);
		
		MCU_u16ADCstart();
		
		MCU_u16TAUxPpgSetHz(MCU_mTAUB2_0, MCU_mTAUB2_15, hz,  duty); duty+=50;
		MCU_u16PinWrite(MCU_mPinID_P17_10,	testcnt++ &1);
//		MCU_u16DMAenable(0);
#if 0
		outdata[0]=0xa1;/*slave address*/
		MCU_u16IIC_MasterStartCondition(1);
		MCU_u16IIC_MasterRec(1,0,outdata,16);
//#else		
		if(testcnt==0)
		{
			MCU_u16PinWrite(MCU_mPinID_P2_2,	0);
			fixdata++;
			memset(&cyctbl[2],fixdata,16);
			
			MCU_u16IIC_MasterStartCondition(1);
			cyctbl[0]=0xa0;/*slave address*/
			cyctbl[1]=0x00;/*eeprom address*/
			testcnt=1;
			//testcnt=0;
			
			MCU_u16IIC_MasterSend(1, 0,cyctbl, 18);/*write*/

//			MCU_u16RLIN3UartSend(MCU_mRLIN3_Uart30,RIICoutdata,16);
		}
		else if(testcnt==1)
		{
			MCU_u16IIC_MasterStartCondition(1);
			
//			cyctbl[1]=0x00;/*eeprom address*/
//			cyctbl[2]=0x00;/*eeprom address*/
			testcnt=2;
			//MCU_u16IIC_MasterSend(1, 0,cyctbl, 1);
			RIICoutdata[0]=0xa0;/*slave address*/
			RIICoutdata[1]=0x0;
			MCU_u16IIC_MasterSend(1, 0,RIICoutdata, 2);

		}
		else
		{
			testcnt=0;
		
		}
#endif

	}

	
}


MCU_tstOSTM_UsrCfg MCU_stOSTMCfg[MCU_mOSTM_Mun]=
{
	{1000,1,OSTM_ISR},
	{0,0,OSTM_ISR},
};

MCU_tstPWGA_UsrCfg MCU_stPWGACfg=
{
	{80,0,0,0},
	
	{0,0,0,0},
{	
	{0xff,0},//  0
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},// 9
	
	{0,0},//  0
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},
	{0xff,0},// 9
	
	{0xff,0},//  0
	{0xff,0},
	{0xff,0},
	{0xff,0},
},

};



#define __Timer_Not_Mount__				{0xffu,0,0,0,0,MCU_vNotExpINT}

#define TimerMode(ClkSel,interval,RunInRest,CB)			{0u,ClkSel,interval,0,RunInRest,CB}
#define PinTriggerTimer(ClkSel,interval,Trigger,RunInRest,CB) 	{1u,ClkSel,interval,Trigger,CB}
#define FrequencyDivider(ClkSel,divider,Trigger,RunInRest)		{2u,ClkSel,2u,Trigger,RunInRest,MCU_vNotExpINT}
#define CounterMode(ClkSel,counter,Trigger,RunInRest,CB)		{3u,ClkSel,counter,Trigger,CB}
#define OnePulseOutPut(ClkSel,PulseLenth,Trigger,RunInRest)	{4u,ClkSel,PulseLenth,Trigger,MCU_vNotExpINT}
#define PulseInterval(ClkSel,Trigger,RunInRest,CB)				{5u,ClkSel,0,Trigger,RunInRest,CB}
#define PulseWidth(ClkSel,Level,RunInRest,CB)				{6u,ClkSel,0,Level,RunInRest,CB}
#define PulsePosition(ClkSel,Trigger,RunInRest,CB)				{7u,ClkSel,0,Trigger,RunInRest,CB}
#define PulseWidthCumulater(ClkSel,Level,RunInRest,CB)		{8u,ClkSel,0,Level,RunInRest,CB}
#define PulseIntervalJudgment(ClkSel,Trigger,RunInRest,CB)		{9u,ClkSel,0,Trigger,RunInRest,CB}
#define PulseWidthJudgment(ClkSel,Level,RunInRest,CB)		{10u,ClkSel,0,Level,RunInRest,CB}	
#define PulseWidthOVcheck(ClkSel,Level,RunInRest,CB)			{11u,ClkSel,0,Level,RunInRest,CB}
#define PulseWidthCumulaterOVcheck(ClkSel,Level,RunInRest,CB)	{12u,ClkSel,0,Level,RunInRest,CB}
#define PulseDetectDelayMaster(ClkSel,DelayLenth,Trigger,RunInRest,CB)	{0xFFu,ClkSel,DelayLenth,Trigger,RunInRest,CB}/*Not Use*/
#define PulseDetectDelaySlave(ClkSel,DelayLenth,Trigger,RunInRest,CB)	{0xFFu,ClkSel,DelayLenth,Trigger,RunInRest,CB}/*Not Use*/

#define PpgMaster(ClkSel,DefaultCnt)				{15u,ClkSel,DefaultCnt,0,1,MCU_vNotExpINT}
#define PpgSlave(ClkSel,DefaultCnt)				{16u,ClkSel,DefaultCnt,0,1,MCU_vNotExpINT}

#define TUAx_MaxFun		17


/*################################################
	############################################
	
			TAUx module configeration
			
	############################################	
################################################*/

#define TAUxClk_Div(PreScale_0,PreScale_1,PreScale_2,PreScale_3)	{PreScale_0,PreScale_1,PreScale_2,PreScale_3}

MCU_tstTAUxClkDiv_UsrCfg MCU_stTAUxClkDivCfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+MCU_mTAUJ_Unit][4]=
{
/*clock divider is {SourceClk / (2^SettingValue)}*/

	/*TAUB0 group*/TAUxClk_Div(0,1,2,3),
	/*TAUB1 group*/TAUxClk_Div(0,1,2,3),
	/*TAUB2 group*/TAUxClk_Div(0,1,2,3),
	/*TAUJ0 group*/ TAUxClk_Div(0,1,2,3),
};

void Timer1(void);
void Timer2(void);
void Timer3(void);
void Timer4(void);


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
TimerMode(0,1000,1,Timer1),
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
__Timer_Not_Mount__,//TimerMode(2000,Timer2),
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,

/*TAUB2 group*/
PpgMaster(0,20000),
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
__Timer_Not_Mount__,//TimerMode(3000,Timer3),
__Timer_Not_Mount__,
__Timer_Not_Mount__,
PpgSlave(0,15000),

/*TAUJ0 group*/
__Timer_Not_Mount__,
__Timer_Not_Mount__,
__Timer_Not_Mount__,//TimerMode(3000,Timer4),
__Timer_Not_Mount__,


};

unsigned int Time1Cnt,Time2Cnt,Time3Cnt,Time4Cnt;

void Timer1(void)
{
Time1Cnt++;

MCU_u16PinWrite(MCU_mPinID_P0_8,	Time1Cnt &1);
}
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
}


int RIIC_T,RIIC_R,RIIC_E;
extern 	uint8 intcont;
void RIIC_TX(void)
{
	if(testcnt==1)
	//if(testcnt==0)
	{
		MCU_u16IIC_MasterStopCondition(1);
		MCU_u16PinWrite(MCU_mPinID_P2_2,	1);
	}
	else if(testcnt==2)
	{
		testcnt=0;
		RIICoutdata[0]=0xa0+1;

		MCU_u16IIC_MasterReStartCondition(1);
		//MCU_u16IIC_MasterStopCondition(1);
		//MCU_u16IIC_MasterStartCondition(1);
		MCU_u16IIC_MasterRec(1,0,RIICoutdata,16);
	}
	
	RIIC_T++;
}
void RIIC_RX(void)
{
//	MCU_u16IIC_MasterStopCondition(1);

	RIIC_R++;
	
}
void RIIC_ERR(uint8 u8err)
{
	RIIC_E=u8err;
	RIIC_E++;
}
uint32 DMA_Done;
void DMA_Finish(void)
{
	DMA_Done++;

	MCU_u16IIC_MasterStopCondition(1);
	
}


MCU_tstRIIC_UsrCfg MCU_tstRIICCfg[2]=
{
	{/*master--0*/
	
		0,/*bps*/
		MCU_mPinID_P2_0,
		MCU_mPinID_P2_1,	
		{DMA_Finish,MCU_vNotExpINT,MCU_vNotExpINT,MCU_vNotExpINT},/*slave 0 conf*/
	},
	
	{/*master--1*/
	
		50000,/*bps*/
		MCU_mPinID_P2_0,
		MCU_mPinID_P2_1,
		{MCU_vNotExpINT,RIIC_TX,RIIC_RX,RIIC_ERR},/*slave 0 conf*/
	},

	
};


#define Source_Increment_Dest_Increment		0
#define Source_Increment_Dest_Fix		1
#define Source_Fix_Dest_Increment		4
#define Source_Fix_Dest_Fix				5

#define DMA_Uint_8bit	0
#define DMA_Uint_16bit	1
#define DMA_Uint_32bit	2

#define __This_DMA_NotMounted__	{0u,	0u,0u,0u,0u,0u,	MCU_vNotExpINT}

MCU_tstDMA_UsrCfg MCU_stDMACfg[MCU_mDMA_MaxChn]=
{
	{(uint32)&cyctbl[0],0xFFDB103c,Source_Increment_Dest_Fix,DMA_Uint_8bit,20,111,DMA_Finish},
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

uint16 EINTCnt;

void EINT(void)
{
	EINTCnt++;
}

#define DetDisable	0u
#define RisingEdge	1u
#define FaillingEdge 2u
#define BothEdge 3u
#define LowLevel	4u
#define HighLevel	5u

#define __ThisEINT_NotMount__	{0xFFFFu,0u,MCU_vNotExpINT}

MCU_tstEINT_UsrCfg MCU_stEINTCfg[MCU_mMaxEINTchannelMount]=
{
	__ThisEINT_NotMount__, /*NMI*/
	
		
	__ThisEINT_NotMount__,/*INT0*/
		{BothEdge,1,EINT},
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
		
	__ThisEINT_NotMount__,/*INT4*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
	
	__ThisEINT_NotMount__,/*INT8*/
	__ThisEINT_NotMount__,
	__ThisEINT_NotMount__,
};

MCU_tstADCA_UsrCfg MCU_stADCACfg=
{
	0x00FFFFFF,
	0,
	0,
	0,
};

uint16 RLIN3Tx,RLIN3Rx,RLIN3Err;
void UART_TX(void)
{
	RLIN3Tx++;
}

void UART_RX(uint8 data)
{
	RLIN3data[RLIN3Rx++]=data;
	if(RLIN3Rx>=16)RLIN3Rx=0;
}

void UART_ER(uint8 err)
{
	RLIN3Err++;
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
	RLIN3Uartconfig(20000,0,1,ParityEven,0,0,UART_TX,UART_RX,UART_ER),
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,
	__ThisRLIN3UART_NotMount__,

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


/*
	INTTAUD0I14 (Channel 7)
	INTCSIH3IJC (Channel 153)

	INTCSIH3IJC_1 (Channel 7)
	INTTAUD0I14_2 (Channel 153)
*/
void MCU_vDebugMain(void)
{
	uint16 i=0;

	while(1)
	{
		MCU_vWatchDogClean();

		++i;
		MCU_u16PinWrite(MCU_mPinID_P0_2,	i &1);
	}


}
#endif

