/*******************************************************************************
| Module Name: Extenal data proccess model
| File Name: M24CXX__Type.h
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


#ifndef M24CXX_TYPE_H
#define M24CXX_TYPE_H

#include "DET.h"
#include "general.h"

/*M24Cxx  IIC driver EEPROM type list!*/
#define M24C01	1
#define M24C02	2
#define M24C04	3
#define M24C08	4
#define M24C16	5


typedef struct {

#if M24CXX_DriverBuffEnable !=0u		
	uint8 pau8DataPoint[M24CXX_DataBuffLen];
#else
	uint8 *pau8DataPoint;
#endif

	uint16 u16TotalLen;
	uint16 u16SendedLen;
	
	uint16 EPaddrReading;
	uint16 EPaddrWritting;
	uint16 ToEpAddr;
	uint16 u8IObyteLen;

	uint8 ThisCmd;
	uint8 ExpCmd;
	uint8 WritePageCnt;
	uint8 WriteByteCnt;
	
}M24CXX_stEEPROM;


/*cmd enum*/
enum
{
	M24CXX_enCMD_Null,
	M24CXX_enCMD_Ready,
	M24CXX_enCMD_StartRead,/*read cmd*/
	M24CXX_enCMD_Read,/*read data*/
	M24CXX_enCMD_StartWrite,/*write cmd*/
	M24CXX_enCMD_Write,/*write data*/
	M24CXX_enCMD_WpOn,
	M24CXX_enCMD_WpOff,
	M24CXX_enCMD_DataCheck,
	M24CXX_enCMD_Erase,
	M24CXX_enCMD_Clock,
	M24CXX_enCMD_WaitReady,
	M24CXX_enCMD_DoCallBack,
};



#endif

