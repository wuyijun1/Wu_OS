/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE: Data Flash driver for NEC 78F1845
*-----------------------------------------------------------------------------
  .FILE:FLS_Drv.c
  .AUTHOR:Tan, fumin
*-----------------------------------------------------------------------------

 Date        Author                       Change
 -----------------------------------------------------------------------------
2013.02.28  Tan, fumin		   :create this module
2013.03.13  Tan, fumin		     add funciton for driver status check:
						     inline uint8 FLS_u8GetSatus(void)
2013.03.15  Tan, fumin		     change the data_len size from uint8 to uint16,
						     change if the data_len is <4, then will not read or write
2013.04.09  Tan, fumin		    1, change the callback function call type for the case that callback function
							will call flash driver function
						    2, add function FLS_u8WriteDataWait
						    3, add function FLS_u8EraseWait
*****************************************************************************/

/************************************************************
internal data flash in 78f1845 layout:

BlockID 		Function Call Address			Physical address[abslute address]:
			[1 address = 4 bytes data]
0			0x0000-0x01FF[2k bytes]		0xE9800-0xE9FFF
1			0x0200-0x03FF[2k bytes]		0xEA000-0xEA7FF
2			0x0400-0x05FF[2k bytes]		0xEA800-0xEAFFF
3			0x0600-0x07FF[2k bytes]		0xEB000-0xEB7FF
4			0x0800-0x09FF[2k bytes]		0xEB800-0xEBFFF
5			0x0A00-0x0BFF[2k bytes]		0xEC000-0xEC7FF
6			0x0C00-0x0DFF[2k bytes]		0xEC800-0xECFFF
7//Max		0x0E00-0x0FFF [2k bytes]		0xED000-0xED7FF

************************************************************/


#include "General.h"

#include "Fdl.h"
#include "Fdl_descriptor.h"
#include "Fdl_types.h"

#include "FLS_Drv.h"

static  FLS_stFLS FLS_stCMD;
extern __far const fal_descriptor_t  fal_descriptor_str;

/*****************************************************************************
 Function  : FLS_vCheckReady												 
 Description   : Check the EEPROM Write or Erase finish, this function MUST called in 
			 while(1)
			 {
			   FLS_vCheckReady();
			   //belowe is your task container or task frame
			 }						
 NOTE: eeprom need 250us for writting a byte/word or neen 14ms for erase a block. so we need check it
 	    to avoid for a long time wait!
 Return Value  : NULL														 
*****************************************************************************/
void FLS_vCheckReady(void)
{
	vpFun CallBack=NULL;
	
	if(FLS_GetThisCmd()==FLS_enCMD_WaitReady)
	{
		if(FLS_GetExpCmd()==FLS_enCMD_Write)
		{
			if(FLS_GetHandleResult()==FAL_BUSY)
			{
				FAL_Handler();
			}
			else if(FLS_GetCurRamAddr()<FLS_GetEndRamAddr())
			{
				FLS_SetFlsData(*(FLS_GetCurRamAddr()));
				FLS_CmdExe(FAL_CMD_WRITE_WORD);
				
				FLS_CurRamAddr()++;
				FLS_FlsAddr()++;
				
				FLS_SetThisCmd(FLS_enCMD_WaitReady);
				FLS_SetExpCmd(FLS_enCMD_Write);
			}
			else
			{
				FLS_SetExpCmd(FLS_enCMD_Null);
				FLS_SetThisCmd(FLS_enCMD_Ready);
				//FAL_Close();
				
				#if FLS_CallBackFunction_Enable
				if(FLS_GetCallBackFun())
				{
					CallBack=FLS_GetCallBackFun();
					FLS_ClearCallBackFun();
					CallBack();
				}
				#endif
			}
		}
		else if(FLS_GetExpCmd()==FLS_enCMD_Erase)
		{
			if(FLS_GetHandleResult()==FAL_BUSY)
			{
				FAL_Handler();
			}
			else
			{
				FLS_SetExpCmd(FLS_enCMD_Null);
				FLS_SetThisCmd(FLS_enCMD_Ready);
				//FAL_Close();
				#if FLS_CallBackFunction_Enable
				if(FLS_GetCallBackFun())
				{
					CallBack=FLS_GetCallBackFun();
					FLS_ClearCallBackFun();
					CallBack();
				}
				#endif
			}
		}
	}
	#if FLS_CallBackFunction_Enable
	else if(FLS_GetThisCmd()==FLS_enCMD_DoCallBack)
	{
		FLS_SetThisCmd(FLS_enCMD_Ready);
		if(FLS_GetCallBackFun())
		{
			CallBack=FLS_GetCallBackFun();
			FLS_ClearCallBackFun();
			CallBack();
		}
	}
	#endif
}

/*****************************************************************************
 Function  : FLS_vDrvInit												 
 Description   : Flash driver initialization, call this function when system reset						
 NOTE: NULL
 Return Value  : NULL														 
*****************************************************************************/
void FLS_vDrvInit(void)
{
	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_SetExpCmd(FLS_enCMD_Null);
	
	FAL_Init(&fal_descriptor_str);
	FAL_Open();
}

/*****************************************************************************
 Function  : FLS_vDrvExit												 
 Description   : Flash driver exit, call this function when system halt						
 NOTE: NULL
 Return Value  : NULL														 
*****************************************************************************/
void FLS_vDrvExit(void)
{
	FLS_SetThisCmd(FLS_enCMD_Null);
	FLS_SetExpCmd(FLS_enCMD_Null);
//	FAL_Close();
}

/*****************************************************************************
 Function  : FLS_u8ReadData												 
 Description   : Read data from Flash, para list:
 
 			 FromFlashAddr: [it MUST be multiple of 2] the Flash address, range is 0x0000 to 2048 * BlockNumber(BLockNumber<=7)
 			 ToRamAddr: head of the data store in the RAM when data read out from EEPROM
 			 DataLen_Byte: [it MUST be multiple of 4] how many bytes read out from Flash,
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on and load data finished
 			   1 is the driver is busy
 			   2 is address range is out 
*****************************************************************************/
uint8 FLS_u8ReadData(uint16 FromFlashAddr, void *ToRamAddr, uint16 DataLen_Byte)
{	
	
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
		return FLS_ERR_Busy;
		
	if(FromFlashAddr+DataLen_Byte>FLS_END_ADDR)
		return FLS_ERR_OutOfRange;
		
	if(DataLen_Byte<4)
		return FLS_ERR_Len;
		
//	FAL_Init(&fal_descriptor_str);
//	FAL_Open();
	
	FLS_SetThisCmd(FLS_enCMD_Read);
	
	FLS_SetCurRamAddr(ToRamAddr);
	FLS_SetFlsAddr(FromFlashAddr);
	FLS_EndRamAddr()=FLS_CurRamAddr()+(DataLen_Byte>>2);
	
	for(;FLS_GetCurRamAddr()<=FLS_GetEndRamAddr();FLS_CurRamAddr()++)
	{	
		FLS_CmdExe(FAL_CMD_READ_WORD);
		if(FLS_GetHandleResult()==FAL_OK)
		{
			*FLS_GetCurRamAddr()=FLS_GetFlsData();
		}
		else
		{
			*FLS_GetCurRamAddr()=0xaaaa;
		}
		
		FLS_FlsAddr()++;
	}
//	FAL_Close();
	#if FLS_CallBackFunction_Enable
	if(FLS_GetCallBackFun())
		FLS_SetThisCmd(FLS_enCMD_DoCallBack);
	else
		FLS_SetThisCmd(FLS_enCMD_Ready);
	#else
	FLS_SetThisCmd(FLS_enCMD_Ready);
	#endif
	return FLS_ERR_NULL;
}

/*****************************************************************************
 Function  : FLS_u8WriteData												 
 Description   : write data into Flash, para list:
 
 			 ToFlashAddr: [it MUST be multiple of 2]the Flash address
 			 FromRamAddr: head of the data store in the RAM which will be write into Flash
 			 DataLen_Byte: [it MUST be multiple of 4]how many bytes read out from Flash
 			 
 NOTE: you MUST erase before when you write the data into flash!
 
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out 
*****************************************************************************/
uint8 FLS_u8WriteData(uint16 ToFlashAddr, void *FromRam, uint16 DataLen_Byte)
{
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
		return FLS_ERR_Busy;
	
	if(ToFlashAddr+DataLen_Byte>FLS_END_ADDR)
		return FLS_ERR_OutOfRange;
	
	if(DataLen_Byte<4)
		return FLS_ERR_Len;
		
	//FAL_Init(&fal_descriptor_str);
	//FAL_Open();
	
	
	FLS_SetThisCmd(FLS_enCMD_Write);
	FLS_SetCurRamAddr(FromRam);
	FLS_SetFlsAddr(ToFlashAddr);
	FLS_EndRamAddr()=FLS_GetCurRamAddr()+(DataLen_Byte>>2)+1;
	
	FLS_SetFlsData(*FLS_GetCurRamAddr());
	
	FLS_CmdExe(FAL_CMD_WRITE_WORD);
	FAL_Handler();
	
	FLS_CurRamAddr()++;
	FLS_FlsAddr()++;

	FLS_SetThisCmd(FLS_enCMD_WaitReady);
	FLS_SetExpCmd(FLS_enCMD_Write);
	
	return FLS_ERR_NULL;
}

/*****************************************************************************
 Function  : FLS_u8WriteData												 
 Description   : write data into Flash, para list:
 
 			 ToFlashAddr: [it MUST be multiple of 2]the Flash address
 			 FromRamAddr: head of the data store in the RAM which will be write into Flash
 			 DataLen_Byte: [it MUST be multiple of 4]how many bytes read out from Flash
 			 
 NOTE: you MUST erase before when you write the data into flash!
 
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out
			   4 is write error
*****************************************************************************/
uint8 FLS_u8WriteDataWait(uint16 ToFlashAddr, void *FromRam, uint16 DataLen_Byte)
{

	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
		return FLS_ERR_Busy;

	if(ToFlashAddr+DataLen_Byte>FLS_END_ADDR)
		return FLS_ERR_OutOfRange;

	if(DataLen_Byte<4)
		return FLS_ERR_Len;
		
	//FAL_Init(&fal_descriptor_str);
	//FAL_Open();


	FLS_SetThisCmd(FLS_enCMD_Write);
	FLS_SetCurRamAddr(FromRam);
	FLS_SetFlsAddr(ToFlashAddr);
	FLS_EndRamAddr()=FLS_GetCurRamAddr()+(DataLen_Byte>>2);


	for(;FLS_GetCurRamAddr()<=FLS_GetEndRamAddr();FLS_CurRamAddr()++)
	{
		FLS_SetFlsData(*FLS_GetCurRamAddr());

		FLS_CmdExe(FAL_CMD_WRITE_WORD);
		FAL_Handler();
		
		while(FLS_GetHandleResult()==FAL_BUSY)
		{
			FAL_Handler();
			HAL_vWdtReset();
		}
		/*write error!!*/
		if(FLS_GetHandleResult()!=FAL_OK)
		{
			//FAL_Close();
			FLS_SetThisCmd(FLS_enCMD_Ready);
			return FLS_ERR_WriteErr;
		}
		FLS_FlsAddr()++;
		FLS_SetFlsAddr(FLS_FlsAddr());
	}

	//FAL_Close();
	FLS_SetThisCmd(FLS_enCMD_Ready);
	return FLS_ERR_NULL;
}



/*****************************************************************************
 Function  : FLS_u8Erase												 
 Description   : erase the flash, all the flash data set to 0xffffffff, para list:
 
 			 FlsAddr: [it MUST be multiple of 2]the Flash address, then this function will erase the block data
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out 
*****************************************************************************/
uint8 FLS_u8Erase(uint16 FlsAddr)
{
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready) 
		return FLS_ERR_Busy;
	if(FlsAddr>FLS_END_ADDR)
		return FLS_ERR_OutOfRange;
		
//	FAL_Init(&fal_descriptor_str);
//	FAL_Open();
	
	FLS_SetFlsAddr(FlsAddr);
	FLS_SetThisCmd(FLS_enCMD_Erase);
	FLS_CmdExe(FAL_CMD_ERASE_BLOCK);
	FAL_Handler();
	
	FLS_SetThisCmd(FLS_enCMD_WaitReady);
	FLS_SetExpCmd(FLS_enCMD_Erase);
	
	return FLS_ERR_NULL;
}

/*****************************************************************************
 Function  : FLS_u8Erase												 
 Description   : erase the flash, all the flash data set to 0xffffffff, para list:
 
 			 FlsAddr: [it MUST be multiple of 2]the Flash address, then this function will erase the block data
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out
			   4 is erase error
*****************************************************************************/
uint8 FLS_u8EraseWait(uint16 FlsAddr)
{
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready) 
		return FLS_ERR_Busy;
	if(FlsAddr>FLS_END_ADDR)
		return FLS_ERR_OutOfRange;
		
	//FAL_Init(&fal_descriptor_str);
	//FAL_Open();
	
	FLS_SetFlsAddr(FlsAddr);
	FLS_SetThisCmd(FLS_enCMD_Erase);
	FLS_CmdExe(FAL_CMD_ERASE_BLOCK);
	
	FAL_Handler();
	
	while(FLS_GetHandleResult()==FAL_BUSY)
	{
		FAL_Handler();
		HAL_vWdtReset();
	}
	/*write error!!*/
	//FAL_Close();
	FLS_SetThisCmd(FLS_enCMD_Ready);
	
	if(FLS_GetHandleResult()!=FAL_OK)
	{
		return FLS_ERR_EraseErr;
	}

	return FLS_ERR_NULL;
}

/*****************************************************************************
 Function  : FLS_u8SetCallBackFun												 
 Description   : Set the Flash driver what to do when it finish its work!
 NOTE: NULL
 Return Value  : NULL
*****************************************************************************/
uint8 FLS_u8SetCallBackFun(vpFun vpfFinishFunction)
{
	#if FLS_CallBackFunction_Enable
	if(FLS_GetThisCmd()==FLS_enCMD_Ready)
	{
		FLS_vSetCallBackFun(vpfFinishFunction);
		
		return FLS_ERR_NULL;
	}
	else
	{
		return FLS_GetThisCmd();
	}
	#else
		return FLS_ERR_NULL;
	#endif
}

/*****************************************************************************
 Function  : EEP_u8GetSatus												 
 Description   : check EEPROM driver status						
 NOTE: NULL
 Return Value  : driver current satus														 
*****************************************************************************/
uint8 FLS_u8GetSatus(void)
{
	return FLS_GetThisCmd();
}

void FLS_vSetCallBackFun(vpFun Function)
{
	FLS_stCMD.CallBack=Function;
}


