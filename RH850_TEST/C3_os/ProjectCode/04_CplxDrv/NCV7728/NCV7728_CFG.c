/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: NCV7728_cfg.c
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
#include "mcu_cfg.h" /*for example*/


/*Latched Thermal Shutdown error process*/
void NCV7728_vErrTSDProcess(void)
{
	
}


/*******************************************************************************

function :void NCV7728_vErrProcess(uint16 u16ErrFeedBack)

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
void NCV7728_vErrProcess(uint16 u16ErrFeedBack)
{
	
}



/*****************************************************************************
 Function  : NCV7728_vTransferData												 
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
void NCV7728_vTransferData(void * vpOutputDataHead,void * vpRecDataHead, uint16 u16DataLen)
{
	/*SPI_u16TranferData(vpOutputDataHead,vpRecDataHead,u16DataLen)*/  /*for exampl*/
}


/*##############################################################
	This define is for get IC_SO pin level after IC_CS = Selected, if it is High, notiefy that IC fatal
	error, it may over tepmerature or over current !
##############################################################*/
#define NCV7728_SOLevel	/*P0_bit.n3*/  /*for example*/


/*****************************************************************************
 Function  : NCV7728_vChipSelectControl												 
 Description   :Driver IC Chip Select control interface
 
 In Parameter: 
 			u8On_Off: expect IC active or not, 
 			0 = CS not active
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void NCV7728_vChipSelectControl(uint8 u8On_Off)
{


	/*P0_bit.no0=u8On_Off */    /*for example*/







	/*#######add your code above #########*/
	
	/*--->driver over temperature shut down process*/
	if((u8On_Off == 1u) && (NCV7728_SOLevel !=0u) )
	{
		NCV7728_vErrTSDProcess();
	}
	
}


/*****************************************************************************
 Function  : NCV7728_vCommunicateInit												 
 Description   :Driver communicate init interface
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			SPI init interface
*****************************************************************************/
void NCV7728_vCommunicateInit(void)
{
	/*SPI_vInit()*/  /*for exampl*/
}


/*****************************************************************************
 Function  : NCV7728_vCommunicateDeinit												 
 Description   :Driver communicate De-init interface
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			SPI de-init interface
*****************************************************************************/
void NCV7728_vCommunicateDeinit(void)
{
	/*SPI_vDeinit()*/  /*for exampl*/
}

/*****************************************************************************
 Function  : NCV7728_vFbStatusProcess												 
 Description   :NCV7728 status feed back Process	
 
 In Parameter: 
 			u16ICstatus: IC feedback status
 			
Return Value:
			NULL

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
void NCV7728_vFbStatusProcess(uint16 u16ICstatus)
{
	
}

