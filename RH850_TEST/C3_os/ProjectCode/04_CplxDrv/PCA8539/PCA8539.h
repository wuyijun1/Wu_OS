/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: PCA8539.h
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
| 2016.05.23  V0.01		Tan, fumin	:create this module
********************************************************************************/

#ifndef PCA8539_H
#define PCA8539_H

#include "./PCA8539_type.h "
#include "./PCA8539_cfg.h"

void PCA8539_vIIC_Init(void);
void PCA8539_vDvrInit(void);
void PCA8539_vDvrInit_P1(void);
void PCA8539_vDvrInit_P2(void);
void PCA8539_vDvrInit_P3(void);
void PCA8539_vDvrInit_P4(void);
void PCA8539_vShutdown(void);
void PCA8539_vDrvExit(void);
void PCA8539_vDisplayUpdate(uint8 u8RAMbank,uint8 u8RAWaddr,uint8 *u8DispalyRAM,uint8 dataLen);


#endif

