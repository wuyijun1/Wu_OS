/*******************************************************************************
| Module Name: Error detect model
| File Name: DET.c
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
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2015.07.31  V0.01	Tan, fumin	:create this module
********************************************************************************/

#include "DET.h"

#if DET_HaltWhenErrorHappen!=0u

static int16 DET_i16ErrLine=0u;
static uint16 DET_u16ErrType=DET_Err_NotErr;
uint16 DET_u16FatalErr(int16 i16ErrLineNum, uint16 u16ErrID)	
{
	/*restore which line error hapens!*/
	DET_i16ErrLine=i16ErrLineNum;
	
	/*restore which error type hapens!*/
	DET_u16ErrType=u16ErrID;

	/*stop excute commond and halt if error happen!*/
	while((DET_i16ErrLine>0) && (DET_u16ErrType>0u))
	{
		DET_u16ErrType=DET_u16ErrType;	//Test by ln
	}

	return u16ErrID;
}

#endif









