/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: NCV7728_type.h
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

#ifndef NCV7728_TYPE_H
#define NCV7728_TYPE_H

#include "general.h"

#define NCV7728_ChannelID_1	0u
#define NCV7728_ChannelID_2	1u
#define NCV7728_ChannelID_3	2u
#define NCV7728_ChannelID_4	3u
#define NCV7728_ChannelID_5	4u
#define NCV7728_ChannelID_6	5u


typedef enum
{
	NCV7728_enHighZ=0u,	/*driver out is High-Z status*/
	NCV7728_enOutputLow,		/*driver out is Low level and lowside is shut cut to GND*/
	NCV7728_enOutputHigh,		/*driver out is High level and highside is shut cut to VDD*/
}NCV7728_enCtrlType;


typedef struct
{
	uint16 u16ChannelCtrlStatus;
	uint16 u16ChannelFeedBackStatus;
	uint8 u8DrvReady;
}NCV7728_stManage;


#endif

