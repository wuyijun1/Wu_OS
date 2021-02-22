/*******************************************************************************
| Module Name:  Low Side Driver for NCV7240,
| File Name: NCV7240.c
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
| 2016/01/26 Rev 02.00.00   Tan Fumin	update to be standard for SVN basic code
********************************************************************************/

#include "./ncv7240.h"
#include "Det.h"

void NCV7240_vFbStatusProcess(uint16 u16ErrFeedBack);
void NCV7240_vErrTERProcess(void);
void NCV7240_vTransferData(void * vpOutputDataHead,void * vpRecDataHead, uint16 u16DataLen);
void NCV7240_vChipSelectControl(uint8 u8On_Off);
void NCV7240_vCommunicateInit(void);
void NCV7240_vCommunicateDeinit(void);

static NCV7240_stManage NCV7240_stInfo;

/*****************************************************************************
 Function  : NCV7240_vDrvInit												 
 Description   :Driver initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7240_vDrvInit(void)
{
	NCV7240_stInfo.u16ChannelCtrlStatus=0u;
	NCV7240_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7240_stInfo.u8DrvReady=0u;
	
	NCV7240_vCommunicateInit();
	NCV7240_vChipSelectControl(1u);
	NCV7240_vTransferData(&NCV7240_stInfo.u16ChannelCtrlStatus, &NCV7240_stInfo.u16ChannelFeedBackStatus,2);
	NCV7240_stInfo.u8DrvReady=1u;
}

/*****************************************************************************
 Function  : NCV7240_vShutdown												 
 Description   :Driver Shutdown
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7240_vShutdown(void)
{
	NCV7240_vChipSelectControl(1u);
	NCV7240_stInfo.u16ChannelCtrlStatus=(uint16)(1u<<15u);
	NCV7240_vTransferData(&NCV7240_stInfo.u16ChannelCtrlStatus, &NCV7240_stInfo.u16ChannelFeedBackStatus,2);
	
	NCV7240_stInfo.u16ChannelCtrlStatus=0u;
	NCV7240_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7240_stInfo.u8DrvReady=0u;
	NCV7240_vChipSelectControl(0u);
}

/*****************************************************************************
 Function  : NCV7240_vDrvExit												 
 Description   :Driver exit
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7240_vDrvExit(void)
{
	NCV7240_vChipSelectControl(1u);
	NCV7240_stInfo.u16ChannelCtrlStatus=(uint16)(1u<<15u);
	NCV7240_vTransferData(&NCV7240_stInfo.u16ChannelCtrlStatus, &NCV7240_stInfo.u16ChannelFeedBackStatus,2u);
	
	NCV7240_stInfo.u16ChannelCtrlStatus=0u;
	NCV7240_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7240_stInfo.u8DrvReady=0u;
	
	NCV7240_vChipSelectControl(0u);

	NCV7240_vCommunicateDeinit();
}

/*****************************************************************************
 Function  : NCV7240_u16ChannelCtrl												 
 Description   :Driver channel control ON/OFF
 
 In Parameter: 
 			channel: channel index
 			status: channel expect status
 			
Return Value:
 			execute resault
 			
 NOTE: 		
 			this function only update status, do not send data to Chip!!!
*****************************************************************************/
uint16 NCV7240_u16ChannelCtrl(uint8 channel, NCV7240_enCtrlType status)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
#define NCV7240_SetChanelValue(channel,status)	\
	do{NCV7240_stInfo.u16ChannelCtrlStatus &=(uint16)~(uint16)(3u<<(uint16)(channel<<1u))/*clean bits*/;\
	NCV7240_stInfo.u16ChannelCtrlStatus |=(uint16)((uint16)(status&3u)<<(uint16)(channel<<1u));}while(0)
	
	if(status>NCV7240_enOffMode)
	{
		DET_ErrReport(DET_Err_NCV7240_ParaOutOfRange);
	}
	else 	if((uint16)((uint16)(1ul<<channel) & NCV7240_u8ChannelUsingMask)==0u)
	{
		DET_ErrReport(DET_Err_NCV7240_ChannleOutOfRange);
	}
	else 	if(NCV7240_stInfo.u8DrvReady==0u)
	{
		DET_ErrReport(DET_Err_NCV7240_DrvNotReady);
	}
	else
	{
		NCV7240_SetChanelValue(channel,status);
	}

	
	return u16RetVal;
	
}


/*****************************************************************************
 Function  : NCV7240_vDrvStatusUpdate												 
 Description   :Driver channel information update
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			using SPI to update data and get the lastest status, call the status feedback proccess
 			function
*****************************************************************************/
void NCV7240_vDrvStatusUpdate(void)
{
	NCV7240_vTransferData(&NCV7240_stInfo.u16ChannelCtrlStatus, &NCV7240_stInfo.u16ChannelFeedBackStatus,2u);

	NCV7240_vFbStatusProcess(NCV7240_stInfo.u16ChannelFeedBackStatus);
}


