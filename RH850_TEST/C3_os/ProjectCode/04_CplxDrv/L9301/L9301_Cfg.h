/*******************************************************************************
| Module Name: L9301
| File Name: L9301_Cfg.h
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
| 2017.03.13  V0.01	Tan, fumin	:create this module
********************************************************************************/

#include "dr7f701035_0.h"

#ifndef _L9301_CFG_H_
#define  _L9301_CFG_H_

#define L9301_SPI_CmdEnable	1/*if you using the SPI to control this chip, set it to 1*/

#define SetPin(Port,Pin,Value) do{PM##Port&=~(1<<Pin);if(Value){P##Port|=(1<<Pin);}else{P##Port&=~(1<<Pin);}}while(0)
							
/*the VDD-IO and RES pin control interface*/
#define L9301_VDD_IO_PinCtrl(High_Low)	SetPin(11,7,High_Low)
#define L9301_RES_PinCtrl(High_Low)	SetPin(11,4,High_Low)

/*the INx control interface*/
#define L9301_EN_PinCtrl(High_Low)	SetPin(11,5,High_Low)
#define L9301_IN1_PinCtrl(High_Low)	SetPin(8,8,High_Low)
#define L9301_IN2_PinCtrl(High_Low)	SetPin(8,7,High_Low)
#define L9301_IN3_PinCtrl(High_Low)	SetPin(8,6,High_Low)
#define L9301_IN4_PinCtrl(High_Low)	SetPin(8,5,High_Low)
#define L9301_IN5_PinCtrl(High_Low)	SetPin(8,4,High_Low)
#define L9301_IN6_PinCtrl(High_Low)	SetPin(8,3,High_Low)
#define L9301_IN7_PinCtrl(High_Low)	SetPin(8,1,High_Low)
#define L9301_IN8_PinCtrl(High_Low)	SetPin(8,0,High_Low)


#endif/*end of this file*/

