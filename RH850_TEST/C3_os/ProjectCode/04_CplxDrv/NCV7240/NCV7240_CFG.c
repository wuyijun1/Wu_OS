/*******************************************************************************
| Module Name:  Low Side Driver for NCV7240,
| File Name: NCV7240_cfg.c
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

#include "general.h"

/*****************************************************************************
 Function  : NCV7240_vErrTERProcess												 
 Description   :Driver IC fatal error, it will be overtemp or over current, it will stop working !!
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it need to process APP layer to stop using the Driver
*****************************************************************************/
void NCV7240_vErrTERProcess(void)
{
	/*driver disable*/		/*for example*/
}



/*******************************************************************************
 Function  : NCV7240_vFbStatusProcess												 
 Description   :Driver status feedback and process by APP interface
 
 In Parameter: 
 			u16ErrFeedBack
 			
Return Value:
 			NULL
 			
 NOTE: 		

=====>Driver status feedback data struct:

		bit14-bit15:	channel8 status feedback
		bit12-bit12:	channel7 status feedback
		bit10-bit11:	channel6 status feedback
		bit8-bit9:		channel5 status feedback
		bit6-bit7:		channel4 status feedback
		bit4-bit5:		channel3 status feedback
		bit2-bit3:		channel2 status feedback
		bit0-bit1:		channel1 status feedback

			status High bit:	Open Load
			
							0 Normal Operation
							1 Fault detected
					
			status Low bit:	Over Load or Over Temperature
			
							0 Normal Operation
							1 Fault detected

*******************************************************************************/
void NCV7240_vFbStatusProcess(uint16 u16ErrFeedBack)
{
	
}

/*****************************************************************************
 Function  : NCV7240_vTransferData												 
 Description   :Driver data communicate interface
 
 In Parameter: 
 			vpOutputDataHead: data head which are output to IC
 			vpRecDataHead: data head which are output from IC
 			u16DataLen:data lenth
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7240_vTransferData(void * vpOutputDataHead,void * vpRecDataHead, uint16 u16DataLen)
{
	/*SPI_u16TranferData(vpOutputDataHead,vpRecDataHead,u16DataLen)*/  /*for exampl*/
}



/*##############################################################
	This define is for get IC_SO pin level after IC_CS = Selected, if it is High, notiefy that IC fatal
	error, it may over tepmerature or over current !
##############################################################*/
#define NCV7240_SOLevel	/*P0_bit.n3*/  /*for example*/




/*****************************************************************************
 Function  : NCV7240_vChipSelectControl												 
 Description   :Driver IC Chip Select control interface
 
 In Parameter: 
 			u8On_Off: expect IC active or not, 
 			0 = CS not active
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7240_vChipSelectControl(uint8 u8On_Off)
{

	/*P0_bit.no0=u8On_Off */    /*for example*/







	/*#######add your code above #########*/
	
	/*--->driver over temperature shut down process*/
	if((u8On_Off == 1u) && (NCV7240_SOLevel !=0u) )
	{
		NCV7240_vErrTERProcess();
	}
	
}


/*****************************************************************************
 Function  : NCV7240_vCommunicateInit												 
 Description   :Driver communicate init interface
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			SPI init interface
*****************************************************************************/
void NCV7240_vCommunicateInit(void)
{
	/*SPI_vInit()*/  /*for exampl*/
}


/*****************************************************************************
 Function  : NCV7240_vCommunicateDeinit												 
 Description   :Driver communicate De-init interface
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			SPI de-init interface
*****************************************************************************/
void NCV7240_vCommunicateDeinit(void)
{
	/*SPI_vDeinit()*/  /*for exampl*/
}


