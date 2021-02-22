/*******************************************************************************
| Module Name: L9301
| File Name: L9301.h
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

#ifndef _L9301_H_
#define _L9301_H_

#include "S_SPI.h"
#include "L9301_Type.h"
#include "L9301_cfg.h"


void L9301_vDeinit(void);
void L9301_vMain(void);
void L9301_vReset(void);
void L9301_vInit(void);
uint16 L9301_u16SetOutputValue(L9301_ChnID Ch, uint8 u8ExpectedLevel);

#endif/*end of this file*/


