/*******************************************************************************
| Module Name:  Low Side Driver for NCV7240,
| File Name: NCV7240_cfg.h
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
#ifndef NCV7240_CFG_H
#define NCV7240_CFG_H

/*####################################################################*/
/*####################################################################*/

#define NCV7240_ChannelEnable_1	1u
#define NCV7240_ChannelEnable_2	1u
#define NCV7240_ChannelEnable_3	1u
#define NCV7240_ChannelEnable_4	1u
#define NCV7240_ChannelEnable_5	1u
#define NCV7240_ChannelEnable_6	1u
#define NCV7240_ChannelEnable_7	0u
#define NCV7240_ChannelEnable_8	0u

/*####################################################################*/
/*####################################################################*/

/*======do not edit below this line =======*/
/*Not Edit*/#define  NCV7240_u8ChannelUsingMask		((uint16)((uint16)(NCV7240_ChannelEnable_1<<0u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_2<<1u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_3<<2u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_4<<3u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_5<<4u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_6<<5u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_7<<6u)|\
/*Not Edit*/									(uint16)(NCV7240_ChannelEnable_8<<7u)))

#endif

