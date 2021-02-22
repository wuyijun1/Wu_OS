/*******************************************************************************
| Module Name: simulation IIC  model
| File Name: S_SPI_cfg.h
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
|2014/10/28 Rev 01.00.00     Tan Fumin			The first version  
|2016/01/26 Rev 02.00.00   Tan Fumin				update to be standard for SVN basic code
********************************************************************************/

#include "MCU_CFG.h"		/*for example*/

#ifndef S_SPI_CFG_H
#define S_SPI_CFG_H

#define S_SPI_CHANNEL_NUMBER	2u

#define S_SPI_DataField_LSB		1u
#define S_SPI_DataField_MSB	2u

#define S_SPI_RisingEdge	1u
#define S_SPI_FailingEdge	2u

#if S_SPI_CHANNEL_NUMBER>=1u

#define S_SPI_CH1_Enable	1u

/*####################################################################*/
/*####################################################################*/

#define S_SPI_CH1_DataField	S_SPI_DataField_MSB/*1=LSB, 2=MSB*/

#define S_SPI_CH1_DataInEdge	S_SPI_RisingEdge/*1=Raising, 2=Failling*/
#define S_SPI_CH1_DataOutEdge	S_SPI_RisingEdge/*1=Raising, 2=Failling*/

#define S_SPI_CH1_CLKReadyLevel		0u	/*if out this level to CLKpin, the CLKpin status is ready!*/
#define S_SPI_CH1_SODummyLevel		1u	/*SO level dummy data*/

#define S_SPI_CH1_DataUnit				16u 	/*how many bits data in a frame*/
#define S_SPI_CH1_DataBuffEnable		0u 	/*enable or disable data store in buffer for transfer*/
#define S_SPI_CH1_DataBuffSize			2u 	/*how many byte data store for transfer*/
#define S_SPI_CH1_TransfDelayCnt		3u	/*small delay count between data bit transfer!*/

#define S_SPI_CH1_SetClkHigh()			(P0_bit.no0=1) 	/*for example*/
#define S_SPI_CH1_SetClkLow()			(P0_bit.no0=0) 	/*for example*/
#define S_SPI_CH1_SetClkReady()		(P0_bit.no0=S_SPI_CH1_CLKReadyLevel) /*for example*/
#define S_SPI_CH1_SetClkOutPutMode()	(PM0_bit.no0=0) 	/*for example*/

#define S_SPI_CH1_SetSoHigh()			(P0_bit.no1=1) 	/*for example*/
#define S_SPI_CH1_SetSoLow()			(P0_bit.no1=0) 	/*for example*/
#define S_SPI_CH1_SetSoOutPutMode()	(PM0_bit.no1=0) 	/*for example*/

#define S_SPI_CH1_GetSiValue()			(P0_bit.no2=0) 	/*for example*/
#define S_SPI_CH1_SetSiInPutMode()		(PM0_bit.no2=0) 	/*for example*/

/*####################################################################*/
/*####################################################################*/


/*======do not edit below this line =======*/



/*Not Edit*/#define S_SPI_CH1_Init()	do{\
/*Not Edit*/							S_SPI_CH1_SetClkReady();\
/*Not Edit*/							S_SPI_CH1_SetSoHigh();\
/*Not Edit*/							S_SPI_CH1_SetClkOutPutMode();\
/*Not Edit*/							S_SPI_CH1_SetSoOutPutMode();\
/*Not Edit*/							S_SPI_CH1_SetSiInPutMode();\
/*Not Edit*/						     }while(0)
/*Not Edit*/
/*Not Edit*/#define S_SPI_CH1_SetReady()		do{S_SPI_CH1_Init();SPI_u8CH1_SpiSatus=SPI_enReady;}while(0)
/*Not Edit*/#define S_SPI_CH1_Exit()			do{S_SPI_CH1_Init();SPI_u8CH1_SpiSatus=SPI_enNotReady;}while(0)
/*Not Edit*/
/*Not Edit*/#define S_SPI_CH1_ClkDelay()	do{uint16 u16WaitCnt=S_SPI_CH1_TransfDelayCnt;while(u16WaitCnt!=0u){u16WaitCnt--;}}while(0)
/*Not Edit*/
#if S_SPI_CH1_DataUnit == 16u
	#if S_SPI_CH1_SODummyLevel != 0u
		#define S_SPI_CH1_SODummyOut		0xFFFFu
	#else
		#define S_SPI_CH1_SODummyOut		0u
	#endif
#elif S_SPI_CH1_DataUnit == 8u
	#if S_SPI_CH1_SODummyLevel != 0u
		#define S_SPI_CH1_SODummyOut		0xFFu
	#else
		#define S_SPI_CH1_SODummyOut		0u
	#endif
	
#elif S_SPI_CH1_DataUnit == 32u

	#if S_SPI_CH1_SODummyLevel != 0u
		#define S_SPI_CH1_SODummyOut		0xFFFFFFFFu
	#else
		#define S_SPI_CH1_SODummyOut		0u
	#endif

#endif


#endif
















#endif /*end of this file*/

