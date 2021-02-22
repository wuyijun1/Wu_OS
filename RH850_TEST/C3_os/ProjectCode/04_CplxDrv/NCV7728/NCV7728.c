/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: NCV7728.c
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

#include "./NCV7728.h"
#include "Det.h"

void NCV7728_vFbStatusProcess(uint16 u16ErrFeedBack);
void NCV7728_vErrTERProcess(void);
void NCV7728_vTransferData(void * vpOutputDataHead,void * vpRecDataHead, uint16 u16DataLen);
void NCV7728_vChipSelectControl(uint8 u8On_Off);
void NCV7728_vCommunicateInit(void);
void NCV7728_vCommunicateDeinit(void);
void NCV7728_vFbStatusProcess(uint16 u16ICstatus);


static NCV7728_stManage NCV7728_stInfo;

/*****************************************************************************
 Function  : NCV7728_vDvrInit												 
 Description   :NCV7728 init
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7728_vDvrInit(void)
{
	NCV7728_stInfo.u16ChannelCtrlStatus=(uint16)(1u<<15u);/*internal reset need*/
	NCV7728_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7728_stInfo.u8DrvReady=0u;
	
	NCV7728_vChipSelectControl(1u);
	NCV7728_vCommunicateInit();
	NCV7728_vTransferData(&NCV7728_stInfo.u16ChannelCtrlStatus, &NCV7728_stInfo.u16ChannelFeedBackStatus,2u);
	NCV7728_stInfo.u8DrvReady=1u;
	NCV7728_stInfo.u16ChannelCtrlStatus=0u;
}

/*****************************************************************************
 Function  : NCV7728_vShutdown												 
 Description   :NCV7728 shutdown
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7728_vShutdown(void)
{
	NCV7728_stInfo.u16ChannelCtrlStatus=0u;
	NCV7728_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7728_stInfo.u8DrvReady=0u;

	NCV7728_vChipSelectControl(1u);
	NCV7728_vTransferData(&NCV7728_stInfo.u16ChannelCtrlStatus, &NCV7728_stInfo.u16ChannelFeedBackStatus,2u);
	NCV7728_vChipSelectControl(0u);
}

/*****************************************************************************
 Function  : NCV7728_vExit												 
 Description   :NCV7728 exit
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7728_vDrvExit(void)
{
	NCV7728_stInfo.u16ChannelCtrlStatus=0u;
	NCV7728_stInfo.u16ChannelFeedBackStatus=0u;
	NCV7728_stInfo.u8DrvReady=0u;

	NCV7728_vChipSelectControl(1u);
	NCV7728_vTransferData(&NCV7728_stInfo.u16ChannelCtrlStatus, &NCV7728_stInfo.u16ChannelFeedBackStatus,2u);
	NCV7728_vChipSelectControl(0u);
	
	NCV7728_vCommunicateDeinit();
}

/*****************************************************************************
 Function  : NCV7728_u8ChannelCtrl												 
 Description   :NCV7728 control a channel ON/OFF
 
 In Parameter: 
 			channel: channel index
 			status: expect channel status
 			
Return Value:
 			execute resault
 			
 NOTE: 		
 			this function not update data to IC, to updata data, you need call 
 			function : NCV7728_vDrvStatusUpdate
*****************************************************************************/
uint8 NCV7728_u8ChannelCtrl(uint8 channel, NCV7728_enCtrlType status)
{
#define NCV7728_ClearChannelBit(ch)	NCV7728_stInfo.u16ChannelCtrlStatus &=(uint16)~(uint16)((uint16)(1u<<(7u+ch)) | (1u<<(1u+ch)))

	uint16 u16RetVal=DET_Err_NotErr;
	
	if(status>NCV7728_enOutputHigh)
	{
		DET_ErrReport(DET_Err_NCV7728_ParaOutOfRange);
	}
	else 	if((uint16)((uint16)(1u<<channel) & NCV7728_u8ChannelUsingMask)==0u)
	{
		DET_ErrReport(DET_Err_NCV7728_ChannleOutOfRange);
	}
	else 	if(NCV7728_stInfo.u8DrvReady==0u)
	{
		DET_ErrReport(DET_Err_NCV7728_DrvNotReady);
	}
	else
	{
			
		/*clear bits for control*/
		NCV7728_ClearChannelBit(channel);
		
		NCV7728_stInfo.u16ChannelCtrlStatus |=(uint16)(NCV7728_OverVoltageLockOutEnable<<0u);
		NCV7728_stInfo.u16ChannelCtrlStatus |=(uint16)(NCV7728_UnderLoadDetEnable<<13u);
		
		if(status == NCV7728_enHighZ)
		{
			/*disable channel and set the output bits to 0*/
			NCV7728_ClearChannelBit(channel);
		}
		else if(status == NCV7728_enOutputLow)
		{
			NCV7728_stInfo.u16ChannelCtrlStatus |=(uint16)(1u<<(7u+channel));
			NCV7728_stInfo.u16ChannelCtrlStatus &=(uint16)~(uint16)(1u<<(1u+channel));
		} 
		else if(status == NCV7728_enOutputHigh)
		{
			NCV7728_stInfo.u16ChannelCtrlStatus |=(uint16)((uint16)(1u<<(7u+channel)) | (uint16)(1u<<(1u+channel)));
		} 
		
	}
	
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : NCV7728_vDrvStatusUpdate												 
 Description   :NCV7728 update status, using SPI to transfer data
 
 In Parameter: 
 			NULL
 			
Return Value:
 			execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7728_vDrvStatusUpdate(void)
{
	NCV7728_vTransferData(&NCV7728_stInfo.u16ChannelCtrlStatus, &NCV7728_stInfo.u16ChannelFeedBackStatus,2u);

	NCV7728_vFbStatusProcess(NCV7728_stInfo.u16ChannelFeedBackStatus);
}


/*****************************************************************************
 Function  : NCV7728_u16GetFeedBackStatus												 
 Description   :NCV7728 status feed back
 
 In Parameter: 
 			NULL
 			
Return Value:
			NCV7728 status

================================================================			
Driver status feedback data struct:

PRE_bit15 : Latched Thermal Shutdown

			0 = No Fault
			1 = Fault
			
bit15:Over Current Shutdown Global Notification

			0 = No Fault
			1 = Fault			
			
bit14:Power Supply Failure on VS1 and/or VS2 Under Voltage and Over Voltage Monitoring

			0 = No Fault
			1 = Fault			
			
bit13:Under Load Detection Global Notification

			0 = No Fault
			1 = Fault		
			
bit12-11:	Half Bridge 6 Status			
bit10-9:	Half Bridge 5 Status
bit8-7:	Half Bridge 4 Status
bit6-5:	Half Bridge 3 Status
bit4-3:	Half Bridge 2 Status
bit2-1:	Half Bridge 1 Status

		00b 每 Output Disable
		01b 每 Over Current Shutdown
		10b 每 Under Load Detection
		11b 每 Output Enabled 	
		
bit0:Thermal Warning Global Notification

			0 = No Fault
			1 = Fault

***********************************************************************************/
uint16 NCV7728_u16GetFeedBackStatus(void)
{
	return NCV7728_stInfo.u16ChannelFeedBackStatus;
}

