/*******************************************************************************
| Module Name:  Low Side Driver for NCV7240,
| File Name: NCV7240_type.h
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

#ifndef NCV7240_TYPE_H
#define NCV7240_TYPE_H

#include "general.h"


#define NCV7240_ChannelID_1	0u
#define NCV7240_ChannelID_2	1u
#define NCV7240_ChannelID_3	2u
#define NCV7240_ChannelID_4	3u
#define NCV7240_ChannelID_5	4u
#define NCV7240_ChannelID_6	5u
#define NCV7240_ChannelID_7	6u
#define NCV7240_ChannelID_8	7u



typedef enum
{
	NCV7240_enStandbyOff=0u,	/*lowside out is cut off and goto standby mode*/
	NCV7240_enInputMode,		/*lowside output is controlled by INx Pin*/
	NCV7240_enOnMode,		/*lowside output is ON*/
	NCV7240_enOffMode		/*lowside output is OFF .do not used this config, has leakage current*/
}NCV7240_enCtrlType;


typedef struct
{
	uint16 u16ChannelCtrlStatus;
	uint16 u16ChannelFeedBackStatus;
	uint8 u8DrvReady;
}NCV7240_stManage;


#endif

