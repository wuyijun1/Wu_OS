/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE: Data Flash driver for NEC 1022 32bit
*-----------------------------------------------------------------------------
  .FILE:FLS_Drv.c
  .AUTHOR:Tan, fumin
*-----------------------------------------------------------------------------

 Date        Author                       Change
 -----------------------------------------------------------------------------
2015.05.12  Tan, fumin		   :create this module

*****************************************************************************/

/************************************************************
internal data flash in 1022 layout:

Totall data flash size = 64byte/block  * 512 block = 32KBytes

erase times : 125k times for 20years retain
			250k times for 3years retain

BlockID 		Function Call Address			Physical address[abslute address]:

0			0xFF20 0000-0xFF20 003F[64 bytes]		
1			0xFF20 0040-0xFF20 007F[64 bytes]	

....			.......
511			0xFF20 7FC0-0xFF20 7FFF[64 bytes]	
			
************************************************************/


#include "../../03_SYS/MCU/MCU/General.h"

#include "./FLS_Drv.h"

#include "./fdl_descriptor.c"
#include "./fdl_user.c"
#include "./r_fdl_hw_access.c"
#include "./r_fdl_user_if.c"
#include "./r_fdl_user_if_init.c"


FLS_stFLS FLS_stCMD;

static void FLS_vSetCallBackFun(vpFun Function);

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
	uint32 FlsAddr;
	uint16 u16RetVal=DET_Err_NotErr;

	if(FLS_GetThisCmd()==FLS_enCMD_WaitReady)
	{
		if(FLS_GetExpCmd()==FLS_enCMD_Write)
		{
			if(FLS_GetHandleResult()==R_FDL_BUSY)
			{
				R_FDL_Handler();
			}
			else if(FLS_GetFlowCurRamAddr()<FLS_GetFlowEndRamAddr())/*flow check,160625*/
			{
				FLS_GetFlowCurRamAddr() +=(FLS_DataFlow_Size>>2);/*write 4 byte, every flow*/
				FLS_FlsAddr()+=FLS_DataFlow_Size;
				
				//FLS_SetCurRamAddr(*(FLS_GetFlowCurRamAddr()));/*copy ram to write*/
				FLS_SetCurRamAddr(FLS_GetFlowCurRamAddr());/*copy ram to write*/
				
				FLS_SetDataLenth(FLS_DataFlow_Size); /*write 4 byte,every flow,160625*/
					
				FLS_CmdExe(R_FDL_CMD_WRITE);
				
				R_FDL_Handler();/*execute operation*/
				
				if( R_FDL_OK != FLS_GetHandleResult())
				{	
					/* Error handler */
					DET_ErrReport(FLS_GetHandleResult());
				}
				
				FLS_SetThisCmd(FLS_enCMD_WaitReady);
				FLS_SetExpCmd(FLS_enCMD_Write);
			}
			else
			{
				FLS_SetExpCmd(FLS_enCMD_Null);
				FLS_SetThisCmd(FLS_enCMD_Ready);
				FLS_CleanCmd();
				
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
			if(FLS_GetHandleResult()==R_FDL_BUSY)
			{
				R_FDL_Handler();
			}
			else if(FLS_GetFlowCurFlsAddr()<FLS_GetFlowEndFlsAddr())/*flow check,160625*/
			{
				/*convert address to block ID*/
				FlsAddr = FLS_GetFlowCurFlsAddr();
				FlsAddr-=FLS_BaseAddress;
				FlsAddr/=FLS_Block_Size;
				/*set operation block ID*/
				FLS_SetFlsAddr(FlsAddr);
	
				FLS_GetFlowCurFlsAddr() +=FLS_Block_Size;/*erase 1 block (64 byte), every flow*/
				//FLS_FlsAddr()+=1;
				
				FLS_stCMD.InOutData.cnt_u16 =1;
				
				FLS_SetThisCmd(FLS_enCMD_Erase);

				FLS_CmdExe(R_FDL_CMD_ERASE);
				
				R_FDL_Handler();
				
				FLS_SetThisCmd(FLS_enCMD_WaitReady);
				FLS_SetExpCmd(FLS_enCMD_Erase);
			}
			else
			{
				FLS_SetExpCmd(FLS_enCMD_Null);
				FLS_SetThisCmd(FLS_enCMD_Ready);
				FLS_CleanCmd();

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
		FLS_CleanCmd();
		
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
	uint16 u16RetVal=DET_Err_NotErr;

	#ifdef R_FDL_DEVICE_SPECIFIC_INIT
	R_FDL_DEVICE_SPECIFIC_INIT
	#endif
	
	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_SetExpCmd(FLS_enCMD_Null);
	FLS_CleanCmd();
	
	FDL_Open();
	
	if( R_FDL_OK != R_FDL_Init( &sampleApp_fdlConfig_enu ) )
	{   
	    /* Error handler */
		DET_ErrReport(FLS_ERR_Init);
	}

	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_SetCurRamAddr(0);
	FLS_SetFlsAddr(0);
	FLS_SetDataLenth(0);
	
	FLS_stCMD.InOutData.command_enu=R_FDL_CMD_PREPARE_ENV;
	FLS_stCMD.InOutData.accessType_enu  = R_FDL_ACCESS_NONE;
	R_FDL_Execute(&FLS_stCMD.InOutData);
        
	while( R_FDL_BUSY == FLS_GetHandleResult())
        {
            R_FDL_Handler();
        }

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
	FLS_CleanCmd();
	
	FDL_Close();
}

/*****************************************************************************
 Function  : FLS_u8ReadData												 
 Description   : Read data from Flash, para list:
 
 			 FromFlashAddr: [it MUST be multiple of 4] the Flash physical address,
 			 ToRamAddr: head of the data store in the RAM when data read out from EEPROM
 			 DataLen_Byte: [it MUST be multiple of 4] how many bytes read out from Flash,
 			 
 NOTE:Len of ToFlashAddr: 0xFF20 0000~0xFF20 7FFF
 Return Value  : 0 is OK and driver working on and load data finished
 			   1 is the driver is busy
 			   2 is address range is out 
 			   
 			   11 or 12 is the reading address data is a empty data(not write before!!)
 			   13 is flashdriver internal error
*****************************************************************************/
uint8 FLS_u8ReadDataWait(uint32 FromFlashAddr, void *ToRamAddr, uint16 DataLen_Byte)
{	
	uint16 u16RetVal=DET_Err_NotErr;
	
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
	{
		DET_ErrReport(FLS_ERR_Busy);
		return FLS_ERR_Busy;
	}
		
	if(FromFlashAddr+DataLen_Byte>FLS_END_ADDR)
	{
		DET_ErrReport(FLS_ERR_OutOfRange);
		return FLS_ERR_OutOfRange;
	}
		
	if((DataLen_Byte<4) || (DataLen_Byte&3))
	{
		DET_ErrReport(FLS_ERR_Len);
		return FLS_ERR_Len;
	}
	
	/*convert to internal address*/
	FromFlashAddr-=FLS_BaseAddress;
	
	FLS_SetThisCmd(FLS_enCMD_Read);
	FLS_SetCurRamAddr(ToRamAddr);
	FLS_SetFlsAddr(FromFlashAddr);
	FLS_SetDataLenth(DataLen_Byte);
	
	FLS_CmdExe(R_FDL_CMD_READ);
	
	while( R_FDL_BUSY == FLS_GetHandleResult())
	{
	//	R_FDL_Handler(); ---not need run this function in read operation!!!
	//	HAL_vWdtReset();
		MCU_vWatchDogClean();
	}
	
	if( R_FDL_OK != FLS_GetHandleResult())
	{	
		/* Error handler */
		DET_ErrReport(FLS_GetHandleResult());
	}

	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_CleanCmd();
	
	#if FLS_CallBackFunction_Enable
		if(FLS_GetCallBackFun())
		{
			FLS_SetThisCmd(FLS_enCMD_DoCallBack);
		}
		else
	#endif
		{
			FLS_SetThisCmd(FLS_enCMD_Ready);
		}
	
	return FLS_GetHandleResult();
}

/*****************************************************************************
 Function  : FLS_u8WriteData												 
 Description   : write data into Flash, para list:
 
 			 ToFlashAddr: [it MUST be multiple of 4]the Flash physical address
 			 FromRamAddr: head of the data store in the RAM which will be write into Flash
 			 DataLen_Byte: [it MUST be multiple of 4]how many bytes read out from Flash
 			 
 NOTE: you MUST erase before when you write the data into flash!
 	Len of ToFlashAddr: 0xFF20 0000~0xFF20 7FFF
 
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out 
			   
			6 is driver is writting operation on going
			7 is writting address is written before, it need to erase then can be write!
			13 is flashdriver internal error
			
*****************************************************************************/
uint8 FLS_u8WriteData(uint32 ToFlashAddr, void *FromRam, uint16 DataLen_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;

	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
	{
		DET_ErrReport(FLS_ERR_Busy);
		return FLS_ERR_Busy;
	}
		
	if(ToFlashAddr+DataLen_Byte>FLS_END_ADDR)
	{
		DET_ErrReport(FLS_ERR_OutOfRange);
		return FLS_ERR_OutOfRange;
	}
		
	if((DataLen_Byte<4) || (DataLen_Byte&3))
	{
		DET_ErrReport(FLS_ERR_Len);
		return FLS_ERR_Len;
	}

	/*convert to internal address*/
	ToFlashAddr-=FLS_BaseAddress;
	
	FLS_SetThisCmd(FLS_enCMD_Write);
	FLS_SetCurRamAddr(FromRam);
	FLS_SetFlsAddr(ToFlashAddr);
	FLS_SetFlowCurRamAddr(FromRam);
	FLS_EndFlowRamAddr()=(uint32 *)(FLS_GetCurRamAddr()+DataLen_Byte);
	//FLS_EndFlowRamAddr()=FLS_GetCurRamAddr()+(DataLen_Byte>>2)+1;/*record end ram for next flow*/
	//FLS_SetDataLenth(DataLen_Byte);/*delete ,160625*/
	FLS_SetDataLenth(FLS_DataFlow_Size); /*write 4 byte,every flow,160625*/
		
	FLS_CmdExe(R_FDL_CMD_WRITE);
	
	R_FDL_Handler();/*execute operation*/
	
	if( R_FDL_OK != FLS_GetHandleResult())
	{	
		/* Error handler */
		DET_ErrReport(FLS_GetHandleResult());
	}
	
	FLS_SetThisCmd(FLS_enCMD_WaitReady);
	FLS_SetExpCmd(FLS_enCMD_Write);
	
	return FLS_GetHandleResult();
}

/*****************************************************************************
 Function  : FLS_u8WriteData												 
 Description   : write data into Flash, para list:
 
 			 ToFlashAddr: [it MUST be multiple of 4]the Flash physical address
 			 FromRamAddr: head of the data store in the RAM which will be write into Flash
 			 DataLen_Byte: [it MUST be multiple of 4]how many bytes read out from Flash
 			 
 NOTE: you MUST erase before when you write the data into flash!
 
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out
			   
			   6 is driver is writting operation on going
			   7 is writting address is written before, it need to erase then can be write!
			   13 is flashdriver internal error
			   
*****************************************************************************/
uint8 FLS_u8WriteDataWait(uint32 ToFlashAddr, void *FromRam, uint16 DataLen_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;

	if(FLS_GetThisCmd() !=FLS_enCMD_Ready)
	{
		DET_ErrReport(FLS_ERR_Busy);
		return FLS_ERR_Busy;
	}
		
	if(ToFlashAddr+DataLen_Byte>FLS_END_ADDR)
	{
		DET_ErrReport(FLS_ERR_OutOfRange);
		return FLS_ERR_OutOfRange;
	}
		
	if((DataLen_Byte<4) || (DataLen_Byte&3))
	{
		DET_ErrReport(FLS_ERR_Len);
		return FLS_ERR_Len;
	}

	/*convert to internal address*/
	ToFlashAddr-=FLS_BaseAddress;

	FLS_SetThisCmd(FLS_enCMD_Write);
	FLS_SetCurRamAddr(FromRam);
	FLS_SetFlsAddr(ToFlashAddr);
	FLS_SetDataLenth(DataLen_Byte);
		
	FLS_CmdExe(R_FDL_CMD_WRITE);
	
	while( R_FDL_BUSY == FLS_GetHandleResult())
	{
		R_FDL_Handler();
		//	HAL_vWdtReset();
			MCU_vWatchDogClean();
	}
	
	if( R_FDL_OK != FLS_GetHandleResult())
	{	
		/* Error handler */
		DET_ErrReport(FLS_GetHandleResult());
	}
	
	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_CleanCmd();
	
	return FLS_GetHandleResult();
}


/*****************************************************************************
 Function  : FLS_u8Erase												 
 Description   : erase the flash, all the flash data set to 0xffffffff, para list:
 
 			 FlsAddr: [it MUST be multiple of 64]the Flash address, then this function will erase the block data
 			 DataLen_Byte: how many data space to be erased
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out 
*****************************************************************************/
uint8 FLS_u8Erase(uint32 FlsAddr,uint16 DataLen_Byte)
{
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready) 
		return FLS_ERR_Busy;
	if(FlsAddr>FLS_END_ADDR ||FlsAddr< FLS_BaseAddress)
		return FLS_ERR_OutOfRange;
		
	/*if the first address is not first address of the block,or
		data lenth is not the size of one block size, then will not erase!*/
	if((FlsAddr & (FLS_Block_Size-1)) || (DataLen_Byte & (FLS_Block_Size-1)))
		return FLS_ERR_Address;

	/*record current and end flash address*/
	FLS_SetFlowCurFlsAddr((FlsAddr+FLS_Block_Size)); /*erase 1 block in this functions*/
	FLS_EndFlowFlsAddr()=FLS_CurFlowFlsAddr()+DataLen_Byte;
	/*convert address to block ID*/
	FlsAddr-=FLS_BaseAddress;
	FlsAddr/=FLS_Block_Size;
	/*set operation block ID*/
	FLS_SetFlsAddr(FlsAddr);
	
	/*convert data lenth to block number*/
	//DataLen_Byte/=FLS_Block_Size;
	DataLen_Byte =1; /*erase 1 block erery cycle*/
	FLS_stCMD.InOutData.cnt_u16=	DataLen_Byte;
	
	FLS_SetThisCmd(FLS_enCMD_Erase);

	FLS_CmdExe(R_FDL_CMD_ERASE);
	
	R_FDL_Handler();
	
	FLS_SetThisCmd(FLS_enCMD_WaitReady);
	FLS_SetExpCmd(FLS_enCMD_Erase);
	
	return FLS_ERR_NULL;
}

/*****************************************************************************
 Function  : FLS_u8Erase												 
 Description   : erase the flash, all the flash data set to 0xffffffff, para list:
 
 			 FlsAddr: [it MUST be multiple of 64]the Flash physical address, then this function will erase the block data
 			 DataLen_Byte: how many data space to be erased
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   1 is the driver is busy
			   2 is address range is out
			   4 is erase error
*****************************************************************************/
uint8 FLS_u8EraseWait(uint32 FlsAddr,uint16 DataLen_Byte)
{
	if(FLS_GetThisCmd() !=FLS_enCMD_Ready) 
		return FLS_ERR_Busy;
	if(FlsAddr>FLS_END_ADDR ||FlsAddr< FLS_BaseAddress)
		return FLS_ERR_OutOfRange;
		
	/*if the first address is not first address of the block,or
		data lenth is not the size of one block size, then will not erase!*/
	if((FlsAddr & (FLS_Block_Size-1)) || (DataLen_Byte & (FLS_Block_Size-1)))
		return FLS_ERR_Address;
		
	/*convert address to block ID*/
	FlsAddr-=FLS_BaseAddress;
	FlsAddr/=FLS_Block_Size;
	/*set operation block ID*/
	FLS_SetFlsAddr(FlsAddr);
	
	/*convert data lenth to block number*/
	DataLen_Byte/=FLS_Block_Size;
	FLS_stCMD.InOutData.cnt_u16=	DataLen_Byte;
	
	FLS_SetThisCmd(FLS_enCMD_Erase);

	FLS_CmdExe(R_FDL_CMD_ERASE);
	
	while(FLS_GetHandleResult()==R_FDL_BUSY)
	{
		R_FDL_Handler();
		//	HAL_vWdtReset();
			MCU_vWatchDogClean();
	}
	
	FLS_SetThisCmd(FLS_enCMD_Ready);
	FLS_SetExpCmd(FLS_enCMD_Null);
	
	return FLS_GetHandleResult();
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

static void FLS_vSetCallBackFun(vpFun Function)
{
	FLS_stCMD.CallBack=Function;
}


