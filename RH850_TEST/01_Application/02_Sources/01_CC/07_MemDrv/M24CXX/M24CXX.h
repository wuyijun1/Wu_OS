/*******************************************************************************
| Module Name: Extenal data proccess model
| File Name: M24CXX.H
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
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
|2014/10/28 Rev 00.00.00     Tan Fumin				The first version  
| 2015/06/09 Rev 01.00.00   Tan Fumin				update for MISRA C rules
| 2016/01/26 Rev 02.00.00   Tan Fumin				update to be standard for SVN basic code
********************************************************************************/


#ifndef M24CXXH
#define M24CXXH

#include "./M24CXX_Cfg.h"
#include "./M24CXX_Type.h"

void		M24CXX_vDrvInit(void);
void		M24CXX_vDrvExit(void);
void		M24CXX_vCheckReady(void);
uint16	M24CXX_u16ReadData(uint16 FromEpAddr, uint8 ToRamAddr[], uint16 DataLen_Byte);
uint16	M24CXX_u16ReadDataWait(uint16 FromEpAddr, uint8 ToRamAddr[], uint16 DataLen_Byte);
uint16	M24CXX_u16WriteData(uint16 ToEpAddr, uint8 FromRamAddr[], uint16 DataLen_Byte);
uint16	M24CXX_u8SetCallBackFun(vpFun vpfFinishFunction);
uint16	M24CXX_u16GetSatus(void);

#endif

