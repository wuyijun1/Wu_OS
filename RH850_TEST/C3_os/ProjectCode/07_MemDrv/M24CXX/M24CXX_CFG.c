/*******************************************************************************
| Module Name: Extenal data proccess model
| File Name: M24CXX_CFG.c
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
|Tan Fumin                            Desay SV Automotive Co., Ltd
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
|2014/10/28 Rev 00.00.00     Tan Fumin				The first version  
| 2015/06/09 Rev 01.00.00   Tan Fumin				update for MISRA C rules
| 2016/01/26 Rev 02.00.00   Tan Fumin				update to be standard for SVN basic code
********************************************************************************/
#include "general.h"


/*****************************************************************************
 Function  : M24CXX_vWriteFinishCB												 
 Description   :this function will be called if write data finish
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vWriteFinishCB(void)
{
	/*EEPROM_Write_finish = 1 */  /*for example*/
}

/*****************************************************************************
 Function  : M24CXX_vReadFinishCB												 
 Description   :this function will be called if read data finish
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vReadFinishCB(void)
{
	/*EEPROM_Read_finish = 1 */  /*for example*/
}


/*****************************************************************************
 Function  : M24CXX_vStartCondition												 
 Description   : start condition for prepare communicate
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vStartCondition(void)
{
	/*IIC_vStartCondition_CH1()*/  /*for example*/
}

/*****************************************************************************
 Function  : M24CXX_vStopCondition												 
 Description   : stop condition for finish communicate
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vStopCondition(void)
{
	/*IIC_vStartCondition_CH1()*/  /*for example*/
}

/*****************************************************************************
 Function  : M24CXX_vCommunicateInit												 
 Description   : IIC bus initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vCommunicateInit(void)
{
	/*IIC_vInit()*/  /*for example*/
}

/*****************************************************************************
 Function  : M24CXX_vCommunicateDenit												 
 Description   :  IIC bus de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vCommunicateDenit(void)
{
	/*IIC_vDeinit()*/  /*for example*/
}


/*****************************************************************************
 Function  : M24CXX_vSendData												 
 Description   : send data to EEPROM
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vSendData(void* datahead, uint16 u16DataLen_byte)
{
	/*IIC_u16SendData_CH1((datahead), (1u))*/  /*for example*/
}

/*****************************************************************************
 Function  : M24CXX_vRecData												 
 Description   : receive data from EEPROM
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vRecData(void* datahead, uint16 u16DataLen_byte)
{
	/*IIC_u16RecData_CH1((datahead), (10u))*/  /*for example*/
}

