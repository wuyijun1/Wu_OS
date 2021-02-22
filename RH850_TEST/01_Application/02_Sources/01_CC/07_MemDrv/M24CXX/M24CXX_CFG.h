/*******************************************************************************
| Module Name: Extenal data proccess model
| File Name: M24CXX_CFG.h
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


#ifndef M24CXX__CFG_H
#define M24CXX__CFG_H

#include "MCU_CFG.h"		/*for example*/

#include "./M24CXX_Type.h"


/*####################################################################*/
/*####################################################################*/

#define M24CXX_DeviceType		(M24C16)			/*which EEPROM using*/

#define M24CXX_IicDeviceAddr	0x0Au				/*what is the EEPROM device address in this IIC bus*/

#define M24CXX_DriverBuffEnable		0u								

#define M24CXX_DataBuffLen		30u								/*for example*/

#define M24CXX_WriteEnable()	do{PM0_bit.no0 = 0;P0_bit.no0=1;}while(0)	/*for example*/
#define M24CXX_WriteDisable()	do{PM0_bit.no0 = 0;P0_bit.no0=0;}while(0)	/*for example*/

/*####################################################################*/
/*####################################################################*/


/*======do not edit below this line =======*/

/*Not Edit*/#define M24CXX_mWriteDataFlowOut(datahead,len)			\
/*Not Edit*/		do{M24CXX_vStartCondition();M24CXX_vSendData((datahead), (len));M24CXX_vStopCondition();}while(0)
/*Not Edit*/
/*Not Edit*/#define M24CXX_mReadCmdOutPart1(datahead)		\
/*Not Edit*/		do{M24CXX_vStartCondition();M24CXX_vSendData((datahead), (2u));}while(0)
/*Not Edit*/		
/*Not Edit*/#define M24CXX_mReadCmdOutPart2(datahead)		\
/*Not Edit*/		do{M24CXX_vStartCondition();M24CXX_vSendData((datahead), (1u));}while(0)
/*Not Edit*/
/*Not Edit*/#define M24CXX_mReceiveDataFlow(datahead,len)			\
/*Not Edit*/		do{M24CXX_vRecData((datahead), (len));M24CXX_vStopCondition();}while(0)
/*Not Edit*/
/*Not Edit*/#define M24CXX_MaxQueDataLen 16U
/*Not Edit*/#define M24CXX_TempBuffSize	(M24CXX_MaxQueDataLen+2U)		
/*Not Edit*/#define M24CXX_DATA_FORMAT	8U
/*Not Edit*/#define M24CXX_WriteEEPaddr(addr)		(uint16)(((uint16)((uint16)(M24CXX_IicDeviceAddr<<(4U+8U))|/*device addr*/\
/*Not Edit*/										(uint16)(((uint16)(addr)&0x700U)<<1U)|/*higher 3 bits*/\
/*Not Edit*/										(uint16)((uint16)(addr)&0xffU)/*lower 8 bits*/) & (uint16)(~0x0100U))/*Write bit Mask*/)		
/*Not Edit*/#define M24CXX_ReadEEPaddr(addr)		(uint16)(((uint16)((uint16)(M24CXX_IicDeviceAddr<<(4U+8U))|/*device addr*/\
/*Not Edit*/										(uint16)(((uint16)(addr)&0x700U)<<1U)|/*higher 3 bits*/\
/*Not Edit*/										(uint16)((uint16)(addr)&0xffU)/*lower 8 bits*/) | (uint16)(0x0100U))/*Read bit Mask*/)

/*Not Edit*/
/*Not Edit*/#define M24CXX_PageByteCnt(EpAddre,WriteLen)	do{\
/*Not Edit*/							if((((EpAddre)&0xfU)+(WriteLen)) > M24CXX_MaxQueDataLen){\
/*Not Edit*/								M24Cxx.WriteByteCnt=(uint8)(M24CXX_MaxQueDataLen-(EpAddre)&(0x000fU));\
/*Not Edit*/								M24Cxx.WritePageCnt=(uint8)((M24CXX_MaxQueDataLen+(WriteLen)-M24Cxx.WriteByteCnt)>>4U);\
/*Not Edit*/							}else{\
/*Not Edit*/								M24Cxx.WriteByteCnt=(uint8)(WriteLen);\
/*Not Edit*/								M24Cxx.WritePageCnt=0U;\
/*Not Edit*/							}}while(0)
/*Not Edit*/	
/*Not Edit*/
#if M24CXX_DeviceType ==M24C01
/*Not Edit*/	#define M24CXX_TOTTAL_SIZE 	128U/*byte*/
#elif M24CXX_DeviceType ==M24C02
/*Not Edit*/	#define M24CXX_TOTTAL_SIZE 	256U/*byte*/
#elif M24CXX_DeviceType ==M24C04
/*Not Edit*/	#define M24CXX_TOTTAL_SIZE 	512U/*byte*/
#elif M24CXX_DeviceType ==M24C08
/*Not Edit*/	#define M24CXX_TOTTAL_SIZE 	1024U/*byte*/
#elif M24CXX_DeviceType ==M24C16
/*Not Edit*/	#define M24CXX_TOTTAL_SIZE 	2048U/*byte*/
#else
/*Not Edit*/	#error "M24CXX_DeviceType is in Error type define!"
#endif


#endif 

