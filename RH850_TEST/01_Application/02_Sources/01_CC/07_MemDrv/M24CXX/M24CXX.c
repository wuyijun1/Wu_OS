/*******************************************************************************
| Module Name: M24CXX EEPROM driver model
| File Name: M24CXX.c
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
|2014/10/28 Rev 00.00.00    Tan Fumin				The first version  
| 2015/06/09 Rev 01.00.00   Tan Fumin				update for MISRA C rules
| 2016/01/26 Rev 02.00.00   Tan Fumin				update to be standard for SVN basic code
********************************************************************************/


#include "./M24CXX.h"
#include "det.h"

void M24CXX_vWriteFinishCB(void);
void M24CXX_vReadFinishCB(void);
void M24CXX_vStartCondition(void);
void M24CXX_vStopCondition(void);
void M24CXX_vCommunicateInit(void);
void M24CXX_vSendData(void* datahead, uint16 u16DataLen_byte);
void M24CXX_vCommunicateDenit(void);
void M24CXX_vRecData(void* datahead, uint16 u16DataLen_byte);

uint8 M24CXX_au8IODataBuf[M24CXX_TempBuffSize];
M24CXX_stEEPROM M24Cxx;


/*****************************************************************************
 Function  : M24CXX_vDrvInit												 
 Description   :EEPROM Driver initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vDrvInit(void)
{	
	memset(&M24Cxx,(int16)0,sizeof(M24CXX_stEEPROM));
	memset(M24CXX_au8IODataBuf,0,M24CXX_TempBuffSize);
	M24CXX_WriteDisable();
	M24CXX_vCommunicateInit();	
	M24Cxx.ThisCmd=M24CXX_enCMD_Ready;
}

/*****************************************************************************
 Function  : M24CXX_vDrvExit												 
 Description   :EEPROM Driver De-init 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void M24CXX_vDrvExit(void)
{
	memset(&M24Cxx,0,sizeof(M24CXX_stEEPROM));
	memset(M24CXX_au8IODataBuf,0,M24CXX_TempBuffSize);
	M24CXX_WriteDisable();
	M24CXX_vCommunicateDenit();
}

/*****************************************************************************
 Function  : M24CXX_vCheckReady												 
 Description   :EEPROM Driver check ready status
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			call this function every 10ms to check data write finish or not!
*****************************************************************************/
void M24CXX_vCheckReady(void)
{
	uint16 u16Cmd,u6DataList;
  	uint16 u16RetVal=DET_Err_NotErr;
      
	if(M24Cxx.ExpCmd == M24CXX_enCMD_WaitReady)
	{
		M24Cxx.u16SendedLen+=M24Cxx.u8IObyteLen;
		M24Cxx.ToEpAddr+=M24Cxx.u8IObyteLen;
	
		if(M24Cxx.u16SendedLen >= M24Cxx.u16TotalLen)
		{
			M24Cxx.ThisCmd=M24CXX_enCMD_Ready;
			M24Cxx.ExpCmd = M24CXX_enCMD_Null;
			
			/*Send finish callback Function execute!!*/
			M24CXX_vWriteFinishCB();
		}
		else 
		{
			/*send a pagebytes*/
			if(M24Cxx.WritePageCnt>0u)
			{
				M24Cxx.WritePageCnt--;
				if(M24Cxx.u16TotalLen -M24Cxx.u16SendedLen>= M24CXX_MaxQueDataLen)
				{
					M24Cxx.u8IObyteLen=M24CXX_MaxQueDataLen;
				}
				else
				{
					M24Cxx.u8IObyteLen=M24Cxx.u16TotalLen - M24Cxx.u16SendedLen;
					M24Cxx.WritePageCnt=0U;
				}
				
				u16Cmd=M24CXX_WriteEEPaddr(M24Cxx.ToEpAddr);
				
				M24CXX_au8IODataBuf[0u]=(uint8)(u16Cmd>>8u);
				M24CXX_au8IODataBuf[1u]=(uint8)(u16Cmd&0xffU);
				
				if(M24Cxx.ThisCmd==M24CXX_enCMD_Write)
				{
					u6DataList = M24Cxx.u16SendedLen;
					memcpy(&M24CXX_au8IODataBuf[2],(void *)&M24Cxx.pau8DataPoint[u6DataList],M24Cxx.u8IObyteLen);
				}
				else if(M24Cxx.ThisCmd==M24CXX_enCMD_Erase)
				{
					memset(&M24CXX_au8IODataBuf[2],0xff,M24Cxx.u8IObyteLen);
				}
				else
				{
				}
				
				M24CXX_WriteEnable();
				M24CXX_mWriteDataFlowOut(M24CXX_au8IODataBuf,M24Cxx.u8IObyteLen+2U);
			}
			else 
			{	/*error !*/
				DET_ErrReport(DET_Err_M24CXX_OutOfRange);
				
				M24Cxx.ExpCmd = M24CXX_enCMD_Null;
			}
		}
	}

}

/*****************************************************************************
 Function  : M24CXX_u16ReadData												 
 Description   :Driver read data from EEPROM 
 
 In Parameter: 
 			FromEpAddr: 		EEPROM address
 			ToRamAddr: 		store data head
 			DataLen_Byte: 	totall read data bytes
 			
Return Value:
 			Standard error type
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 M24CXX_u16ReadData(uint16 FromEpAddr, uint8 ToRamAddr[], uint16 DataLen_Byte)
{
	uint16 u16temp;  /*u16WaitStatus=300*/
	
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*reading error lenth*/
	if(FromEpAddr + DataLen_Byte > M24CXX_TOTTAL_SIZE)
	{
		DET_ErrReport(DET_Err_M24CXX_Len);
	}
	else
	{
		M24Cxx.ThisCmd=M24CXX_enCMD_StartRead;
		M24Cxx.u8IObyteLen=DataLen_Byte;
		M24Cxx.EPaddrReading=FromEpAddr;
		
		
		u16temp=M24CXX_WriteEEPaddr(FromEpAddr);
		M24CXX_au8IODataBuf[0U]=(uint8)(u16temp>>8U);
		M24CXX_au8IODataBuf[1U]=(uint8)(u16temp&0xffU);
		M24CXX_au8IODataBuf[2U]=(uint8)(M24CXX_au8IODataBuf[0U]|1U);
		
		M24Cxx.ThisCmd=M24CXX_enCMD_Read;

		M24CXX_mReadCmdOutPart1(M24CXX_au8IODataBuf);
		M24CXX_mReadCmdOutPart2(&M24CXX_au8IODataBuf[2U]);
		M24CXX_mReceiveDataFlow(ToRamAddr,M24Cxx.u8IObyteLen);
		
		M24Cxx.ThisCmd = M24CXX_enCMD_Ready;
		
		M24CXX_vReadFinishCB();
		
	}
		
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : M24CXX_u16ReadDataWait												 
 Description   :Driver read data from EEPROM 
 
 In Parameter: 
 			FromEpAddr: 		EEPROM address
 			ToRamAddr: 		store data head
 			DataLen_Byte: 	totall read data bytes
 			
Return Value:
 			Standard error type
 			
 NOTE: 		
 			this function has same effect with M24CXX_u16ReadData if using the s_iic type
*****************************************************************************/
uint16 M24CXX_u16ReadDataWait(uint16 FromEpAddr, uint8 ToRamAddr[], uint16 DataLen_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	u16RetVal=M24CXX_u16ReadData( FromEpAddr, ToRamAddr,  DataLen_Byte);
	
	if(DET_Err_NotErr != u16RetVal)
	{
		DET_ErrReport(u16RetVal);
	}
	return u16RetVal;
}

/*****************************************************************************
 Function  : M24CXX_u16WriteData												 
 Description   :Driver write data To EEPROM 
 
 In Parameter: 
 			ToEpAddr: 		EEPROM address
 			FromRamAddr: 	need write data head
 			DataLen_Byte: 	totall read data bytes
 			
Return Value:
 			Standard error type
 			
 NOTE: 		
 			this function has same effect with M24CXX_u16ReadData if using the s_iic type
*****************************************************************************/
uint16 M24CXX_u16WriteData(uint16 ToEpAddr, uint8 FromRamAddr[], uint16 DataLen_Byte)
{
	uint16 u16temp;     /*u16WaitStatus=300*/
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*reading error lenth*/
	if(ToEpAddr + DataLen_Byte > M24CXX_TOTTAL_SIZE)
	{
		DET_ErrReport(DET_Err_M24CXX_Len);
	}
	/*Driver is busy!!*/
	else if(M24Cxx.ThisCmd !=M24CXX_enCMD_Ready)
	{
		DET_ErrReport(DET_Err_M24CXX_Busy);
	}
#if M24CXX_DriverBuffEnable !=0u		
	else if(DataLen_Byte>M24CXX_DataBuffLen)
	{
		DET_ErrReport(DET_Err_M24CXX_Len);
	}
#endif
	else
	{
		M24Cxx.ThisCmd=M24CXX_enCMD_Write;
		
		M24Cxx.u16TotalLen=DataLen_Byte;
		M24Cxx.u16SendedLen=0U;
		M24Cxx.ToEpAddr=ToEpAddr;
		
#if M24CXX_DriverBuffEnable !=0u		
		/*M24Cxx.pau8DataPoint = FromRamAddr*/
		if(DataLen_Byte>M24CXX_DataBuffLen)
		{
			DataLen_Byte=0U;
			/*error here!!!*/
			DET_ErrReport(DET_Err_M24CXX_OutOfRange);
		}
		
		memcpy((void *)&M24Cxx.pau8DataPoint[0],(void *)FromRamAddr,DataLen_Byte);
#else
		M24Cxx.pau8DataPoint=(uint8 *)FromRamAddr;
#endif

		u16temp=M24CXX_WriteEEPaddr(ToEpAddr);
		M24CXX_au8IODataBuf[0U]=(uint8)(u16temp>>8U);
		M24CXX_au8IODataBuf[1U]=(uint8)(u16temp&0xffU);
		M24CXX_PageByteCnt(ToEpAddr,DataLen_Byte);
		
		if(M24Cxx.WriteByteCnt >0U)
		{
			u16temp=M24Cxx.WriteByteCnt;
			M24Cxx.u8IObyteLen=M24Cxx.WriteByteCnt;
			M24Cxx.WriteByteCnt=0U;
		}
		else if(M24Cxx.WritePageCnt > 0U)
		{
			u16temp=M24CXX_MaxQueDataLen;
			M24Cxx.u8IObyteLen=M24CXX_MaxQueDataLen;
			M24Cxx.WritePageCnt--;
		}
		else
		{
			/*error here!!!*/
			u16RetVal=DET_Err_M24CXX_OutOfRange;
		}
		
		if(u16RetVal==DET_Err_NotErr)
		{
			if(u16temp>=16u)
			{
				u16temp=16u;/*max data lenth in a frame is 16bytes*/
			}
			memcpy(&M24CXX_au8IODataBuf[2U],(void *)FromRamAddr,u16temp);
			
			M24CXX_WriteEnable();
			
			M24CXX_mWriteDataFlowOut(M24CXX_au8IODataBuf,u16temp+2U);
			
			M24CXX_WriteDisable();
			M24Cxx.ExpCmd = M24CXX_enCMD_WaitReady;
		}
		
	}
	
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : M24CXX_u16GetSatus												 
 Description   :get driver status 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			driver status
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 M24CXX_u16GetSatus(void)
{
	return M24Cxx.ThisCmd;
}

