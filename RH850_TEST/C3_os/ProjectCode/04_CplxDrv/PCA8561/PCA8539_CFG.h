/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: PCA8539_cfg.h
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

#ifndef PCA8539_CFG_H
#define PCA8539_CFG_H

/*####################################################################*/
/*####################################################################*/


/*####################################################################*/
/*####################################################################*/

void PCA8539_vDataSendOut(uint8 *u8DateHead,uint8 u8DateLen);
void PCA8539_vDataSendFinishCallBack(void);
void PCA8539_vStartCondition(void);
void PCA8539_vStopCondition(void);

#endif

