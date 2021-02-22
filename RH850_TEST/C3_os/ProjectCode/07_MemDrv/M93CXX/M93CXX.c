/*******************************************************************************
| Module Name: M93CXX EEPROM driver model
| File Name: M93CXX.c
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
|
|Date        Author                       Change
| -----------------------------------------------------------------------------
|2013.02.06  Tan, fumin		   :create this module
|2013.03.12  Tan, fumin		    create function M93CXX_u8SetCallBackFun for driver call back for special flow
|2013.03.13  Tan, fumin		     add funciton for driver status check:
|						     uint8 M93CXX_u8GetSatus(void)
|2013.03.15  Tan, fumin		     change the data_len size from uint8 to uint16,
|						     change if the data_len is <=1 in 16bit mode, then will not read or write
|2013.04.09  Tan, fumin		    1, change the callback function call type for the case that callback function
|							will call EEPROM driver function
|						    2, Add function M93CXX_u8ReadDataWait for wait force
|2014.02.18  Tan, fumin		   Add function M93CXX_u8WriteDataWait for wait force 		
|2015.03.24  Tan, fumin		   fix the bug: 
|						   the reading address is wrong(if the EP_DATA_FORMAT==16,read addr shuold <<1) 
|						   when expect write commond in the commond section EP_enCMD_WpOff
|
| 2016/01/26 Rev 02.00.00   Tan Fumin		update to be standard for SVN basic code
|2016.05.29  Tan, fumin		change Writing CMD clock phase after data check!
|							because the phase changed by date checkout when data info flow output
|2016.12.29  Tan, fumin		fix the last byte address access bug!
*****************************************************************************/

#include "./M93CXX_Type.h"
#include "./m93cxx.h"


static EP_stEEPROM EP_stEP;

static void M93CXX_vWriteProtect(uint8 ON_OFF);
static void M93CXX_vDrvPinInit(uint8 ON_OFF);

 /*****************************************************************************
  Function	: M93CXX_vCheckReady 												  
  Description	: Check the EEPROM Write or Erase finish, this function MUST called in 
  			  while(1)
  			  {
  			  	M93CXX_vCheckReady();
  			  	//belowe is your task container or task frame
  			  }						 
  NOTE: eeprom need 2-3ms for writting a byte/word or neen 1.8 ms for erase. so we need check it
  Return Value	: NULL														  
 *****************************************************************************/
 void M93CXX_vCheckReady(void)
{
	
	vpFun CallBack=NULL;

	if(EP_GetThisCmd()==EP_enCMD_WaitReady)
	{
		if(EP_StatusPin())
		{	
			#if EP_ReadOut_Before_Write
			if(EP_GetExpCmd()==EP_enCMD_DataCheck)
			{
				if(EP_CurWRamAddr()<EP_GetWRamEndAddr())
				{
					EP_SetThisCmd(EP_enCMD_Ready);
					#if EP_DATA_FORMAT==16
					M93CXX_u8ReadData(EP_GetEPWrttingAddr()<<1, EP_CurWRamAddr(), EP_DataUnit_Len());				
					#else
					M93CXX_u8ReadData(EP_GetEPWrttingAddr(), EP_CurWRamAddr(), EP_DataUnit_Len()); 			
					#endif
				}
				else
				{
					EP_SetExpCmd(EP_enCMD_Null);
					EP_SetThisCmd(EP_enCMD_Ready);
					M93CXX_vWriteProtect(EP_WriteDisable);
				}
			}
			else
			#endif
			if(EP_GetExpCmd()==EP_enCMD_Write)
			{
				if(EP_CurWRamAddr()>=EP_GetWRamEndAddr())
				{
					EP_SetExpCmd(EP_enCMD_Null);
					EP_SetThisCmd(EP_enCMD_Ready);
					M93CXX_vWriteProtect(EP_WriteDisable);
				}
				else
				{
					EP_DrvType_CMD();//TAN FUMIN
					EP_SetExpCmd(EP_enCMD_Null);
					EP_SetThisCmd(EP_enCMD_StartWrite);

					EP_OutPut(1);
					EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
					EP_Drv_Output(EP_CMD_WRITE|EP_GetEPWrttingAddr());
					EP_WrttingEPAddr()++;			
				}
			}
			else if(EP_GetExpCmd()==EP_enCMD_Erase)
			{
				EP_SetExpCmd(EP_enCMD_Null);
				EP_SetThisCmd(EP_enCMD_Ready);
				M93CXX_vWriteProtect(EP_WriteDisable);
				
			}
		}
	}
	#if EP_CallBackFunction_Enable
	else if(EP_GetThisCmd()==EP_enCMD_DoCallBack)
	{
		EP_SetThisCmd(EP_enCMD_Ready);
		if(EP_GetCallBackFun())
		{
			CallBack=EP_GetCallBackFun();
			EP_ClearCallBackFun();
			CallBack();
		}
	}
	#endif
}

/*****************************************************************************
 Function  : M93CXX_vDrvPinInit												 
 Description   : EEPROM driver initialization for Pin setting, call this function when system reset,
 			para list:
 			ON_OFF: if ON_OFF is 0, then set all pin to input mode, else initial for CSI driver
 NOTE: NULL
 Return Value  : NULL														 
*****************************************************************************/
static void M93CXX_vDrvPinInit(uint8 ON_OFF)
{
	#if EP_CSI_Channel==CSI_ID_00_P17
					/*CLK,  SI ,  SO*/
	uint8 u8PinList[]={0x17,0x16,0x15};
	#elif EP_CSI_Channel==CSI_ID_01_P76
	uint8 u8PinList[]={0x76,0x75,0x74};
	#elif EP_CSI_Channel==CSI_ID_10_P10
	uint8 u8PinList[]={0x10,0x11,0x12};
	#elif EP_CSI_Channel==CSI_ID_11_P153
	uint8 u8PinList[]={0xf3,0xf2,0xf1};
	#elif EP_CSI_Channel==CSI_ID_00_P60
	uint8 u8PinList[]={0x60,0x61,0x62};
	#endif
	
	uint8 *PM=(uint8 *)&PM0,*PD=(uint8 *)&P0;
	uint8 const *u8Value=u8PinList;

	PM+=*u8Value>>4;
	PD+=*u8Value>>4;
	
	if(ON_OFF)
	{
		*PM &=~(1<<(*u8Value&0x0f));	/*clk output*/
		*PD |=(1<<(*u8Value&0x0f)); 	/*clk value 1*/
		u8Value++;
		*PM |=(1<<(*u8Value&0x0f)); 	/*SI input*/
		u8Value++;
		*PM &=~(1<<(*u8Value&0x0f));	/*SO output*/
		*PD |=(1<<(*u8Value&0x0f)); /*SO value 1*/
	}
	else
	{
		*PM |=(1<<(*u8Value&0x0f)); 	/*clk input*/
		u8Value++;
		*PM |=(1<<(*u8Value&0x0f)); 	/*SI input*/
		u8Value++;
		*PM |=(1<<(*u8Value&0x0f)); 	/*SO input*/
	}
	/*set CS pin output mode*/
	EP_CS_SetPinOutputMode();
}



/*****************************************************************************
 Function  : M93CXX_vDrvInit												 
 Description   : EEPROM driver initialization, call this function when system reset						
 NOTE: NULL
 Return Value  : NULL														 
*****************************************************************************/
void M93CXX_vDrvInit(void)
{
	/*internal register initial*/
	EP_Drv_ClkOn();
	EP_Drv_RegInit();
	/*set the pin for clk,si,so and CS*/
	M93CXX_vDrvPinInit(1);
	
	EP_SetThisCmd(EP_enCMD_Ready);
	EP_SetExpCmd(EP_enCMD_Null);
}

/*****************************************************************************
 Function  : EEP_vDriverExit												 
 Description   : EEPROM driver DE_initialization, call this function when system halt						
 NOTE: NULL
 Return Value  : NULL														 
*****************************************************************************/
void M93CXX_vDrvExit(void)
{
	/*set the pin for clk,si,so and CS*/
	M93CXX_vDrvPinInit(0);
	
	EP_SetThisCmd(EP_enCMD_Null);
	EP_SetExpCmd(EP_enCMD_Null);
}

/*****************************************************************************
 Function  : M93CXX_u8ReadData												 
 Description   : Read data from EEPROM, para list:
 
 			 FromEpAddr: the EEPROM absolute address
 			 ToRamAddr: head of the data store in the RAM when data read out from EEPROM
 			 DataLen_Byte: how many bytes read out from EEPROM
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   3 is the target address is out of range
 			   others is the driver is busy
*****************************************************************************/
uint8 M93CXX_u8ReadData(uint16 FromEpAddr, void *ToRamAddr, uint16 DataLen_Byte)
{
	/*driver has been initianized and not busy*/
	if(EP_GetThisCmd()==EP_enCMD_Ready)
	{
		#if EP_DATA_FORMAT==16
		/*it must even address in 16bit mode*/
		//if((FromEpAddr&1)||(DataLen_Byte&1))
		//	return DET_Err_M93CXX_Parity;
		if(DataLen_Byte<=1)
			return DET_Err_M93CXX_Len;
		#endif
		if(FromEpAddr+DataLen_Byte<=EP_TOTTAL_SIZE)
		{
			EP_ChipSeleEnable();
			#if EP_DATA_FORMAT==16
			FromEpAddr>>=1;
			#endif
			EP_SetReadingAddr(FromEpAddr);
			EP_SetRDataFlow(ToRamAddr, DataLen_Byte);
			
			EP_DrvType_CMD();
			EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
			EP_SetThisCmd(EP_enCMD_StartRead);
			EP_Drv_Output(EP_CMD_READ|(EP_GetReadingAddr()&EP_ADDR_MASK));
			EP_ReadingAddr()++;
			return DET_Err_M93CXX_NULL;
		}
		else
		{
			return DET_Err_M93CXX_OverAddr;
		}
	}
	else
	{
		return EP_GetThisCmd();
	}
}

/*****************************************************************************
 Function  : M93CXX_u8ReadDataWait												 
 Description   : Read data from EEPROM and wait finish fored, para list:
 
 			 FromEpAddr: the EEPROM absolute address
 			 ToRamAddr: head of the data store in the RAM when data read out from EEPROM
 			 DataLen_Byte: how many bytes read out from EEPROM
 			 
 NOTE: NULL
 Return Value  : 0 is OK and Load data finish
 			   else: refer to function M93CXX_u8ReadData return value!
*****************************************************************************/
uint8 M93CXX_u8ReadDataWait(uint16 FromEpAddr, void *ToRamAddr, uint16 DataLen_Byte)
{
	uint8 Res,waitcnt=5;
	
	#if EP_CallBackFunction_Enable
	if(EP_GetCallBackFun()) return DET_Err_M93CXX_Busy;
	#endif
	
	if(EP_GetThisCmd()!=EP_enCMD_Read&&EP_GetThisCmd()!=EP_enCMD_Ready) return DET_Err_M93CXX_Busy;
	while(EP_GetThisCmd()!=EP_enCMD_Ready)HAL_vWdtReset();
	
	Res=M93CXX_u8ReadData(FromEpAddr, ToRamAddr,DataLen_Byte);
	if(Res==DET_Err_M93CXX_NULL)
	{
		do
		{
			HAL_vWdtReset();
			if((EP_GetThisCmd()==EP_enCMD_Ready) &&
				( EP_GetExpCmd()==EP_enCMD_Null))
			{
				waitcnt--;
			}
			else 
			{
				waitcnt=5;
			}
		}while(waitcnt);
		
		return DET_Err_M93CXX_NULL;
	}
	else 
	{
		return Res;
	}
}

/*****************************************************************************
 Function  : M93CXX_u8WriteData												 
 Description   : write data into EEPROM, para list:
 
 			 ToEpAddr: the EEPROM absolute address
 			 FromRamAddr: head of the data store in the RAM which will be write into EEPROM
 			 DataLen_Byte: how many bytes read out from EEPROM
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   3 is the target address is out of range
 			   others is the driver is busy
*****************************************************************************/
uint8 M93CXX_u8WriteData(uint16 ToEpAddr, void *FromRamAddr, uint16 DataLen_Byte)
{
	/*driver has been initianized and not busy*/
	if(EP_GetThisCmd()==EP_enCMD_Ready)
	{
		#if EP_DATA_FORMAT==16
		/*it must even address in 16bit mode*/
		//if((ToEpAddr&1) ||(DataLen_Byte&1))
		//	return DET_Err_M93CXX_Parity;
		if(DataLen_Byte<=1)
			return DET_Err_M93CXX_Len;
		#endif

		if(ToEpAddr+DataLen_Byte<=EP_TOTTAL_SIZE)
		{
			#if EP_DATA_FORMAT==16
			ToEpAddr>>=1;
			#endif
			EP_SetWrttingAddr(ToEpAddr);
			EP_SetWDataFlow(FromRamAddr, DataLen_Byte);
			
			EP_SetExpCmd(EP_enCMD_Write);
			M93CXX_vWriteProtect(EP_WriteEnable);

			return DET_Err_M93CXX_NULL;
		}
		else
		{
			return DET_Err_M93CXX_OverAddr;
		}
	}
	else
	{
		return EP_GetThisCmd();
	}
}

/*****************************************************************************
 Function  : M93CXX_u8WriteDataWait												 
 Description   : write data into EEPROM, para list:
 
 			 ToEpAddr: the EEPROM absolute address
 			 FromRamAddr: head of the data store in the RAM which will be write into EEPROM
 			 DataLen_Byte: how many bytes read out from EEPROM
 			 
 NOTE: NULL
 Return Value  : 0 is OK and driver working on
 			   3 is the target address is out of range
 			   others is the driver is busy
*****************************************************************************/
uint8 M93CXX_u8WriteDataWait(uint16 ToEpAddr, void *FromRamAddr, uint16 DataLen_Byte)
{
	uint8 u8Err,u8RetryTime=3;
	
	if(EP_GetThisCmd()!=EP_enCMD_Read&&EP_GetThisCmd()!=EP_enCMD_Ready) return DET_Err_M93CXX_Busy;
	while(EP_GetThisCmd()!=EP_enCMD_Ready)HAL_vWdtReset();

	if(u8Err=M93CXX_u8WriteData(ToEpAddr,FromRamAddr,DataLen_Byte))return u8Err;
	
	while(u8RetryTime>0)
	{		
		HAL_vWdtReset();
		M93CXX_vCheckReady();
		if((EP_GetThisCmd()==EP_enCMD_Ready) &&
			( EP_GetExpCmd()==EP_enCMD_Null))
		{
			u8RetryTime--;
		}
		else
		{
			u8RetryTime=3;
		}
	}
	return 0;
}

/*****************************************************************************
 Function  : M93CXX_vWriteProtect												 
 Description   : make the EEPROM write enable or not:para list:
 			 ON_OFF: if ON_OFF == 0, then the EEPROM is writeable, or then unwriteable 			 
 NOTE: you should not call this function alone!
 Return Value  : NULL
*****************************************************************************/
static void M93CXX_vWriteProtect(uint8 ON_OFF)
{
	if(EP_GetThisCmd()==EP_enCMD_Ready)
	{
		EP_ChipSeleEnable();
		EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
		EP_DrvType_CMD();
		if(ON_OFF)
		{
			EP_SetThisCmd(EP_enCMD_WpOn);
			EP_Drv_Output(EP_CMD_WProtectOn);
		}
		else
		{
			EP_SetThisCmd(EP_enCMD_WpOff);
			EP_Drv_Output(EP_CMD_WProtectOff);
		}
	}
}

/*****************************************************************************
 Function  : M93CXX_u8Erase												 
 Description   : Erase the EEPROM, after called this function, all data reset to 0XFFFF
 NOTE: NULL
 Return Value  : 0 is OK
 			   Not 0 is driver is busy
*****************************************************************************/
uint8 M93CXX_u8Erase(void)
{
	if(EP_GetThisCmd()==EP_enCMD_Ready)
	{
		EP_ChipSeleEnable();
		EP_SetExpCmd(EP_enCMD_Erase);
		M93CXX_vWriteProtect(EP_WriteEnable);

		return DET_Err_M93CXX_NULL;
	}
	else
	{
		return EP_GetThisCmd();
	}
}


/*****************************************************************************
 Function  : M93CXX_u8SetCallBackFun												 
 Description   : Set the EEPROM driver what to do when it finish its work!
 NOTE: NULL
 Return Value  : NULL
*****************************************************************************/
uint8 M93CXX_u8SetCallBackFun(vpFun vpfFinishFunction)
{
	#if EP_CallBackFunction_Enable
	if(EP_GetThisCmd()==EP_enCMD_Ready)
	{
		EP_SetCallBackFun(vpfFinishFunction);
		
		return DET_Err_M93CXX_NULL;
	}
	else
	{
		return EP_GetThisCmd();
	}
	#else
		return DET_Err_M93CXX_NULL;
	#endif
}


/*****************************************************************************
 Function  : M93CXX_u8GetSatus												 
 Description   : check EEPROM driver status						
 NOTE: NULL
 Return Value  : driver current satus														 
*****************************************************************************/
uint8 M93CXX_u8GetSatus(void)
{
	return EP_GetThisCmd();
}

/*****************************************************************************
 Function  : M93CXX_vIntService												 
 Description   : CSI bus interrupt servce, called by vector ONLY!
 NOTE: NULL
 Return Value  : NULL
*****************************************************************************/
#pragma vector = EP_Drv_Vector
__interrupt void M93CXX_vIntService(void)
{
	EP_DATASIZE ReceiveData,Err=EP_Drv_GetTsfErr();
	uint8 wait=2;

	EP_Drv_WaitFinish();
	EP_Drv_ClearTsfErr();
	
	if(EP_GetThisCmd()==EP_enCMD_StartRead)
	{		
		#if EP_ReadOut_Before_Write
		if(EP_GetExpCmd()==EP_enCMD_DataCheck)
		{
			EP_SetExpCmd(EP_enCMD_Null);
			EP_SetThisCmd(EP_enCMD_DataCheck);
		}
		else
		#endif
		{
			EP_SetThisCmd(EP_enCMD_Read);
		}
		EP_Drv_SetTranfDataBits(EP_DATA_FORMAT);
		EP_DrvType_Data();
		EP_Drv_Output(EP_DUMMY_DATA);
	}
	else if(EP_GetThisCmd()==EP_enCMD_Read)
	{
		ReceiveData=EP_Drv_ReceiveData();
		*EP_CurRRamAddr()=ReceiveData;
		EP_CurRRamAddr()++;
			
		if(EP_CurRRamAddr()>=EP_GetRRamEndAddr())
		{
			/*the last byte, then set the ready status*/
			EP_ChipSeleDisable();
			#if EP_CallBackFunction_Enable
			if(EP_GetCallBackFun())
				EP_SetThisCmd(EP_enCMD_DoCallBack);
			else
				EP_SetThisCmd(EP_enCMD_Ready); 
			#else
			EP_SetThisCmd(EP_enCMD_Ready); 
			#endif
		}
		else
		{
			/*receive go no*/
			EP_DrvType_Data();//TAN FUMIN
			EP_Drv_Output(EP_DUMMY_DATA);		
		}
	}
	#if EP_ReadOut_Before_Write
	else if(EP_GetThisCmd()==EP_enCMD_DataCheck)
	{
		EP_ChipSeleDisable();
		ReceiveData=EP_Drv_ReceiveData();
		
		if(*EP_CurWRamAddr()==ReceiveData)
		{

			EP_WrttingEPAddr()++;/*piont to next data!!*/
			EP_CurWRamAddr()++;
			
			if(EP_CurWRamAddr()<EP_GetWRamEndAddr())
			{
				EP_SetExpCmd(EP_enCMD_DataCheck);
				EP_SetThisCmd(EP_enCMD_Ready);
				
				#if EP_DATA_FORMAT==16
				M93CXX_u8ReadData(EP_WrttingEPAddr()<<1, EP_CurWRamAddr(),EP_DataUnit_Len());				
				#else
				M93CXX_u8ReadData(EP_WrttingEPAddr(), EP_CurWRamAddr(), EP_DataUnit_Len()); 			
				#endif
			}
			else
			{
				EP_SetExpCmd(EP_enCMD_Null);
				EP_SetThisCmd(EP_enCMD_Ready);
				M93CXX_vWriteProtect(EP_WriteDisable);
			}
		}
		else
		{
			/*data need write*/
			EP_DrvType_CMD();//TAN FUMIN============
			EP_SetExpCmd(EP_enCMD_Null);
			EP_SetThisCmd(EP_enCMD_StartWrite);
			EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
			EP_ChipSeleEnable();
			EP_Drv_Output(EP_CMD_WRITE|EP_GetEPWrttingAddr());
			EP_WrttingEPAddr()++;
		}		
	}
	#endif
	else if(EP_GetThisCmd()==EP_enCMD_WpOn)/*then can not write data into eeprom*/
	{
		EP_ChipSeleDisable();
		#if EP_CallBackFunction_Enable
		if(EP_GetCallBackFun())
			EP_SetThisCmd(EP_enCMD_DoCallBack);
		else
			EP_SetThisCmd(EP_enCMD_Ready); 
		#else
		EP_SetThisCmd(EP_enCMD_Ready); 
		#endif
	}
	else if(EP_GetThisCmd()==EP_enCMD_WpOff)
	{
		EP_ChipSeleDisable();
		if(EP_GetExpCmd()==EP_enCMD_Write)
		{
			#if EP_ReadOut_Before_Write
			EP_SetExpCmd(EP_enCMD_DataCheck);
			EP_SetThisCmd(EP_enCMD_Ready);
			#if EP_DATA_FORMAT==16
				M93CXX_u8ReadData(EP_GetEPWrttingAddr()<<1, EP_CurWRamAddr(),EP_DataUnit_Len());				
			#else
				M93CXX_u8ReadData(EP_GetEPWrttingAddr(), EP_CurWRamAddr(), EP_DataUnit_Len());			
			#endif
			#else
				EP_DrvType_CMD();//TAN FUMIN
			EP_SetExpCmd(EP_enCMD_Null);
			EP_SetThisCmd(EP_enCMD_StartWrite);
			EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
			EP_ChipSeleEnable();
			
			EP_Drv_Output(EP_CMD_WRITE|(EP_GetEPWrttingAddr()));
			EP_WrttingEPAddr()++;
			#endif
		}
		else if(EP_GetExpCmd()==EP_enCMD_Erase)
		{
			EP_DrvType_CMD();//TAN FUMIN
			EP_SetExpCmd(EP_enCMD_Null);
			EP_SetThisCmd(EP_enCMD_Erase);
			EP_Drv_SetTranfDataBits(EP_CMD_FLOW_LEN);
			EP_ChipSeleEnable();
			EP_Drv_Output(EP_CMD_ERASE);
		}
		else
		{
			EP_SetThisCmd(EP_enCMD_Ready);
		}
	}
	else if(EP_GetThisCmd()==EP_enCMD_StartWrite)
	{
		EP_DrvType_CMD();//TAN FUMIN
		EP_Drv_SetTranfDataBits(EP_DATA_FORMAT);
		EP_SetThisCmd(EP_enCMD_Write);
		EP_Drv_Output(*EP_CurWRamAddr());
		EP_CurWRamAddr()++;			
	}
	else if(EP_GetThisCmd()==EP_enCMD_Write)
	{
		EP_ChipSeleDisable();
		for(wait=5;wait;wait--)HAL_NOP();
		EP_OutPut(0);
		EP_ChipSeleEnable();
		#if EP_ReadOut_Before_Write
		EP_SetExpCmd(EP_enCMD_DataCheck);
		#else
		EP_SetExpCmd(EP_enCMD_Write);
		#endif
		EP_SetThisCmd(EP_enCMD_WaitReady);
	}	
	else if(EP_GetThisCmd()==EP_enCMD_Erase)
	{
		EP_ChipSeleDisable();
		for(wait=5;wait;wait--)HAL_NOP();
		EP_OutPut(0);
		EP_ChipSeleEnable();
		/*for 1ms timer check ready and write continue!!*/
		EP_SetExpCmd(EP_enCMD_Erase);
		EP_SetThisCmd(EP_enCMD_WaitReady);
	}
}


