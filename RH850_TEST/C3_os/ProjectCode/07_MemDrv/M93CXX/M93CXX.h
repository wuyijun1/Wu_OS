/*******************************************************************************
| Module Name: M93CXX EEPROM driver model
| File Name: M93CXX.h
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
|Tan Fumin                       Desay SV Automotive Co., Ltd
|
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
|
|Date        Author                       Change
| -----------------------------------------------------------------------------
|2013.02.06  Tan, fumin		   :create this module
|2013.03.12  Tan, fumin		    create macro EP_CallBackFunction_Enable for driver call back for special flow
| 2016/01/26 Rev 02.00.00   Tan Fumin		update to be standard for SVN basic code
*****************************************************************************/

#include "general.h"
#include "mcu_cfg.h"	/*for example*/

#ifndef M93CXX_H
#define M93CXX_H

void 	M93CXX_vDrvInit(void);
void 	M93CXX_vDrvExit(void);
void 	M93CXX_vCheckReady(void);
uint8 M93CXX_u8ReadData(uint16 FromEpAddr, void *ToRamAddr, uint16 DataLen_Byte);
uint8 M93CXX_u8ReadDataWait(uint16 FromEpAddr, void *ToRamAddr, uint16 DataLen_Byte);
uint8 M93CXX_u8WriteData(uint16 ToEpAddr, void *FromRamAddr, uint16 DataLen_Byte);
uint8 M93CXX_u8Erase(void);
uint8 M93CXX_u8SetCallBackFun(vpFun vpfFinishFunction);
uint8 M93CXX_u8GetSatus(void);
uint8 M93CXX_u8WriteDataWait(uint16 ToEpAddr, void *FromRamAddr, uint16 DataLen_Byte);

#endif

