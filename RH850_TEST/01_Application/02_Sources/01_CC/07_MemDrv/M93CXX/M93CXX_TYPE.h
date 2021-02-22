/*******************************************************************************
| Module Name: M93CXX EEPROM driver model
| File Name: M93CXX_type.h
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

#include "./M93CXX_CFG.h"

#ifndef M93CXX_TYPE_H
#define M93CXX_TYPE_H

/*only for 78k0r serial MCU like 78f1845*/
#define CSI_ID_00_P17		(0u|0x1000u)
#define CSI_ID_01_P76		(1u|0x1000u)
#define CSI_ID_10_P10		(2u|0x1000u)
#define CSI_ID_11_P153	(3u|0x1000u)
#define CSI_ID_00_P60		(4u|0x1000u)

#define M93C86  1/*2048  bytes*/
#define M93C76  2/*1024   bytes*/
#define M93C66  3/*512   bytes*/
#define M93C56  4/*256   bytes*/
#define M93C46  5/*128   bytes*/
#define M93C06  6/*32   bytes*/

/*cmd enum*/
enum
{
	EP_enCMD_Null,
	EP_enCMD_Ready,
	EP_enCMD_StartRead,/*read cmd*/
	EP_enCMD_Read,/*read data*/
	EP_enCMD_StartWrite,/*write cmd*/
	EP_enCMD_Write,/*write data*/
	EP_enCMD_WpOn,
	EP_enCMD_WpOff,
	EP_enCMD_DataCheck,
	EP_enCMD_Erase,
	EP_enCMD_Clock,
	EP_enCMD_WaitReady,
	EP_enCMD_DoCallBack,
};


typedef struct {
	EP_DATASIZE *RamAddrR_E;
	EP_DATASIZE *RamAddrR_Cur;
	
	EP_DATASIZE *RamAddrW_E;
	EP_DATASIZE *RamAddrW_Cur;
	
	uint16 EPaddrReading;
	uint16 EPaddrWritting;
	#if EP_CallBackFunction_Enable
	vpFun CallBack;
	#endif
	uint8 ThisCmd;
	uint8 ExpCmd;
}EP_stEEPROM;


#endif

