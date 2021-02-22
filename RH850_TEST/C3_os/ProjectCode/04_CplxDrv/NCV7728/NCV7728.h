/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: NCV7728.h
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
| 2015.04.28  V0.01		Tan, fumin	:create this module
| 2016/01/26 Rev 02.00.00   Tan Fumin				update to be standard for SVN basic code
********************************************************************************/

#ifndef NCV7728_H
#define NCV7728_H

#include "./NCV7728_type.h "
#include "./NCV7728_cfg.h"

void NCV7728_vReset(void);
void NCV7728_vInit(void);
void NCV7728_vDeinit(void);
void NCV7728_vDisableCtrl(void);
void NCV7728_vEnableCtrl(void);
uint8 NCV7728_u8ChannelCtrl(uint8 channel, NCV7728_enCtrlType status);
void NCV7728_vDrvStatusUpdate(void);
uint16 NCV7728_u16GetFeedBackStatus(void);

void NCV7728_vErrTSDProcess(void);
void NCV7728_vErrProcess(uint16 u16ErrFeedBack);

#endif

