/*******************************************************************************
| Module Name: M93CXX EEPROM driver model
| File Name: M93CXX_cfg.h
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
|2013.03.12  Tan, fumin		    create macro EP_CallBackFunction_Enable for driver call back for special flow
| 2016/01/26 Rev 02.00.00   Tan Fumin		update to be standard for SVN basic code
*****************************************************************************/

#include "general.h"
#include "mcu_cfg.h"

#ifndef M93CXX_CFG_H
#define M93CXX_CFG_H

/*####################################################################*/
/*####################################################################*/
#define EP_UsingType			M93C76/*for example*/

#define EP_CSI_Channel		CSI_ID_11_P153/*for example*/ 	/*which the CSI channel for using for EEPROM driverr*/

#define EP_Tranfer_Speed 			8	/*clock divide,it must 1-127 clock divide*/

#define EP_ReadOut_Before_Write	0	/*if open this denfine, then the data is not write when the EEPROM
									 data is same as the being write data*/
									 
#define EP_CallBackFunction_Enable	1	/*if open this define, you can call the function when driver finish its work*/

#define EP_DATA_FORMAT			16 	/*bit, it will be 8bit or 16bit data format for one time read out or write in
									--Always set this value 16*/

#define EP_ChipSeleEnable()			P0_bit.no0=1/*for example*/
#define EP_ChipSeleDisable()			P0_bit.no0=0/*for example*/
#define EP_CS_SetPinOutputMode()	PM0_bit.no0=0/*for example*/		

/*####################################################################*/
/*####################################################################*/


/*======do not edit below this line =======*/


#if EP_UsingType == M93C86
/*Not Edit*/	#define EP_TOTTAL_SIZE		2048			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		11			
#elif EP_UsingType == M93C76
/*Not Edit*/	#define EP_TOTTAL_SIZE		1024			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		11			
#elif EP_UsingType == M93C66
/*Not Edit*/	#define EP_TOTTAL_SIZE		512			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		9			
#elif EP_UsingType == M93C56
/*Not Edit*/	#define EP_TOTTAL_SIZE		256			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		9			
#elif EP_UsingType == M93C46
/*Not Edit*/	#define EP_TOTTAL_SIZE		128			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		7			
#elif EP_UsingType == M93C06
/*Not Edit*/	#define EP_TOTTAL_SIZE		32			/*EEPROM size in bytes*/
/*Not Edit*/	#define EP_ADDR_LEN_Raw		7			

#endif

#if EP_DATA_FORMAT==8
/*Not Edit*/#define EP_ADDR_LEN 		EP_ADDR_LEN_Raw /*bit, the address lenth of the EEPROM operation,uint is bit*/
/*Not Edit*/#define EP_DATASIZE uint8

#elif EP_DATA_FORMAT==16
/*Not Edit*/#define EP_ADDR_LEN 		(EP_ADDR_LEN_Raw-1) /*bit, the address lenth of the EEPROM operation,uint is bit*/
/*Not Edit*/#define EP_DATASIZE uint16

#else
/*Not Edit*/#error "Data format error!!"
#endif

#if EP_CSI_Channel==CSI_ID_00_P60
/*Not Edit*/#define _EP_Drv_PinRelocatin()		 STSEL|=0x10

#else
/*Not Edit*/#define _EP_Drv_PinRelocatin()	

#endif

/*EEPROM driver communication data format*/
/*Not Edit*/#define EP_Drv_WORK_MODE  	3u		/*<<== the operation for CSI working mode :*/
/*Not Edit*/									/*1=receive ONLY*/ 
/*Not Edit*/									/* 2=send ONLY*/
/*Not Edit*/									/* 3=receive and send enable*/
/*Not Edit*/									
/*Not Edit*/#define EP_Drv_CLK_PHASE_TYPE	3u	/*<<== the data in/out clock phase:refer to the spec page:572*/
/*Not Edit*/									/* 0=clock alway high, change data when clk low, and data out when clk rasing*/
/*Not Edit*/									/* 1=clock alway low, change data when clk high, and data out when clk falling*/
/*Not Edit*/									/* 2=clock alway high, change data when clk high, and data out when clk falling*/
/*Not Edit*/									/* 3=clock alway low, change data when clk low, and data out when clk rasing*/
/*Not Edit*/
/*Not Edit*/#define EP_Drv_PARIRY_TYPE		0u	/*<<==the data parity type use:*/
/*Not Edit*/									/* 0=not parity use*/
/*Not Edit*/									/* 1=parity zero*/
/*Not Edit*/									/* 2=parity EVEN*/
/*Not Edit*/									/* 3=parity ODD*/
/*Not Edit*/									
/*Not Edit*/#define EP_Drv_DATA_DIR		0u	/*<<==data transfer diretion*/
/*Not Edit*/									/* 0= MSB,the first in/out bit is the highest bit*/
/*Not Edit*/									/* 1= LSB, the first in/out bit is the lowest bit*/
/*Not Edit*/									
/*Not Edit*/#define EP_Drv_STOP_BIT		0u	/*<<==how many stop bits using at the end of data transfer*/
/*Not Edit*/									/*0=do not use stop bit*/
/*Not Edit*/									/*1=1 stop bit using*/
/*Not Edit*/									/*2= 2 stop bits using*/
/*Not Edit*/
/*Not Edit*/#define EP_Drv_SETTING		((EP_Drv_WORK_MODE<<14) | (	EP_Drv_CLK_PHASE_TYPE<<12) |(EP_Drv_PARIRY_TYPE <<8) |\
/*Not Edit*/							(EP_Drv_DATA_DIR << 7) |(EP_Drv_STOP_BIT<< 4) |(EP_DATA_FORMAT-1))
/*Not Edit*/
/*Not Edit*/#define EP_WriteEnable 		0u
/*Not Edit*/#define EP_WriteDisable 		1u
/*Not Edit*/#define EP_DataUnit_Len() 	sizeof(EP_DATASIZE)
/*Not Edit*/#define EP_DUMMY_DATA		0x0000u
/*Not Edit*/
/*Not Edit*/#define EP_START_BIT_LEN		1U/*bit*/
/*Not Edit*/#define EP_CMD_LEN			2U/*bit*/
/*Not Edit*/#define EP_ADDR_MASK		((1<<EP_ADDR_LEN)-1)
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/#define EP_CMD_FLOW_LEN	(EP_START_BIT_LEN+EP_CMD_LEN+EP_ADDR_LEN)
/*Not Edit*/
/*Not Edit*/#define 	EP_CMD_READ 		(0x06<<EP_ADDR_LEN)
/*Not Edit*/#define 	EP_CMD_WRITE		(0x05<<EP_ADDR_LEN)
/*Not Edit*/#define 	EP_CMD_WProtectOff (0x13<<(EP_ADDR_LEN-2))/*|((1<<(EP_ADDR_LEN-2))-1)*/
/*Not Edit*/#define 	EP_CMD_WProtectOn (0x10<<(EP_ADDR_LEN-2))/*|((1<<(EP_ADDR_LEN-2))-1)*/
/*Not Edit*/#define 	EP_CMD_ERASE		(0x12<<(EP_ADDR_LEN-2))
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/#define EP_GetEPWrttingAddr() 	EP_stEP.EPaddrWritting
/*Not Edit*/#define EP_WrttingEPAddr() 		EP_stEP.EPaddrWritting
/*Not Edit*/#define EP_SetWrttingAddr(addr) 	EP_stEP.EPaddrWritting=addr
/*Not Edit*/
/*Not Edit*/#define EP_GetReadingAddr() 		EP_stEP.EPaddrReading
/*Not Edit*/#define EP_ReadingAddr() 			EP_stEP.EPaddrReading
/*Not Edit*/#define EP_SetReadingAddr(addr) 	EP_stEP.EPaddrReading=addr
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/#define EP_SetRDataFlow(RamDataHead,Len) EP_stEP.RamAddrR_Cur=(EP_DATASIZE *)RamDataHead;\
/*Not Edit*/										EP_stEP.RamAddrR_E=EP_stEP.RamAddrR_Cur+(Len>>(sizeof(EP_DATASIZE)-1))
/*Not Edit*/#define EP_SetWDataFlow(RamDataHead,Len) EP_stEP.RamAddrW_Cur=(EP_DATASIZE *)RamDataHead;\
/*Not Edit*/											EP_stEP.RamAddrW_E=EP_stEP.RamAddrW_Cur+(Len>>(sizeof(EP_DATASIZE)-1))
/*Not Edit*/
/*Not Edit*/#define EP_CurRRamAddr()		EP_stEP.RamAddrR_Cur
/*Not Edit*/#define EP_GetRRamEndAddr() 	EP_stEP.RamAddrR_E
/*Not Edit*/
/*Not Edit*/#define EP_CurWRamAddr()		EP_stEP.RamAddrW_Cur
/*Not Edit*/#define EP_GetWRamEndAddr() 	EP_stEP.RamAddrW_E
/*Not Edit*/
/*Not Edit*/#define EP_SetThisCmd(cmd)		EP_stEP.ThisCmd=cmd
/*Not Edit*/#define EP_GetThisCmd()			EP_stEP.ThisCmd
/*Not Edit*/
/*Not Edit*/#define EP_SetExpCmd(cmd)		EP_stEP.ExpCmd=cmd
/*Not Edit*/#define EP_GetExpCmd()			EP_stEP.ExpCmd
/*Not Edit*/
/*Not Edit*/#define EP_SetCallBackFun(Function)	EP_stEP.CallBack=(vpFun)Function
/*Not Edit*/#define EP_GetCallBackFun()			EP_stEP.CallBack
/*Not Edit*/#define EP_RunCallBackFun()			EP_stEP.CallBack()
/*Not Edit*/#define EP_ClearCallBackFun()			EP_stEP.CallBack=NULL
/*Not Edit*/
/*Not Edit*/
#if EP_CSI_Channel==CSI_ID_00_P17
/*Not Edit*/#define Drv_Group	0
/*Not Edit*/#define Drv_SubIndex	00
/*Not Edit*/#define EP_Drv_Vector	INTCSI00_vect
/*Not Edit*/#define EP_OutPutPin(value)	P1_bit.no5/*SO pin*/
/*Not Edit*/#define EP_InPutPin()			P1_bit.no6/*SI pin*/
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/
#elif EP_CSI_Channel==CSI_ID_00_P60
/*Not Edit*/#define Drv_Group	0
/*Not Edit*/#define Drv_SubIndex	00
/*Not Edit*/#define EP_Drv_Vector	INTCSI00_vect
/*Not Edit*/#define EP_OutPutPin(value)	P6_bit.no2/*SO pin*/
/*Not Edit*/#define EP_InPutPin()			P6_bit.no1/*SI pin*/
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/
#elif EP_CSI_Channel==CSI_ID_01_P76
/*Not Edit*/#define Drv_Group	0
/*Not Edit*/#define Drv_SubIndex	01
/*Not Edit*/#define EP_Drv_Vector	INTCSI01_vect
/*Not Edit*/#define EP_OutPutPin(value)	P7_bit.no4/*SO pin*/
/*Not Edit*/#define EP_InPutPin()			P7_bit.no5/*SI pin*/
/*Not Edit*/
/*Not Edit*/
/*Not Edit*/
#elif EP_CSI_Channel==CSI_ID_10_P10
/*Not Edit*/#define Drv_Group	1
/*Not Edit*/#define Drv_SubIndex	10
/*Not Edit*/#define EP_Drv_Vector	INTCSI10_vect
/*Not Edit*/#define EP_OutPutPin(value)	P1_bit.no2/*SO pin*/
/*Not Edit*/#define EP_InPutPin()			P1_bit.no1/*SI pin*/
/*Not Edit*/
#elif EP_CSI_Channel==CSI_ID_11_P153
/*Not Edit*/#define Drv_Group	1
/*Not Edit*/#define Drv_SubIndex	11
/*Not Edit*/#define EP_Drv_Vector	INTCSI11_vect
/*Not Edit*/#define EP_OutPutPin(value)	P15_bit.no1/*SO pin*/
/*Not Edit*/#define EP_InPutPin()			P15_bit.no2/*SI pin*/
#else
#error "EP_CSI_Channel is NOT correct!!"
#endif


/*Not Edit*/#define EP_StatusPin()	EP_InPutPin()
/*Not Edit*/#define EP_OutPut(value)	EP_OutPutPin(value)


/*Not Edit*/#define _EP_Drv_ClkOn_(Group)	SAU##Group##EN = 1U;HAL_NOP();HAL_NOP();HAL_NOP();HAL_NOP()
/*Not Edit*/#define _EP_Drv_ClkOn(Group) _EP_Drv_ClkOn_(Group)

/*Not Edit*/#define _EP_Drv_RegInit_(Group,subId)	 SIR##subId =0x07;SMR##subId =0x20;SCR##subId =EP_Drv_SETTING;	SDR##subId=((uint16)(EP_Tranfer_Speed &0x7f))<<9;\
/*Not Edit*/							CSIIF##subId=0;CSIMK##subId=0;SS##Group|=1<<(EP_CSI_Channel&1);SOE##Group|=1<<(EP_CSI_Channel&1)
/*Not Edit*/#define _EP_Drv_RegInit(Group,subId)  _EP_Drv_RegInit_(Group,subId)

/*Not Edit*/#define	_EP_Dvr_Exit_(Group,subId) ST##Group|=1<<(EP_CSI_Channel&1);SOE##Group&=1<<(EP_CSI_Channel&1);CSIMK##subId=1
/*Not Edit*/#define _EP_Dvr_Exit(Group,subId)	 _EP_Dvr_Exit_(Group,subId)

/*Not Edit*/#define _EP_Drv_SetTranfDataBits_(subId,bits) SCR##subId&=0xfff0;SCR##subId|=(bits-1)&0x0f
/*Not Edit*/#define _EP_Drv_SetTranfDataBits(subId,bits) _EP_Drv_SetTranfDataBits_(subId,bits)

/*Not Edit*/#define _EP_Drv_Output_(SubIndex,data)	CSIMK##SubIndex=1;SDR##SubIndex=data;CSIMK##SubIndex=0
/*Not Edit*/#define _EP_Drv_Output(SubIndex,data) _EP_Drv_Output_(SubIndex,data)

/*Not Edit*/#define _EP_Drv_ReceiveData_(SubIndex) SDR##SubIndex
/*Not Edit*/#define _EP_Drv_ReceiveData(SubIndex)  _EP_Drv_ReceiveData_(SubIndex)

/*Not Edit*/#define _EP_Drv_GetTsfErr_(SubIndex)	SSR##SubIndex&7
/*Not Edit*/#define _EP_Drv_GetTsfErr(SubIndex)	_EP_Drv_GetTsfErr_(SubIndex)

/*Not Edit*/#define _EP_Drv_TransfFinish_(SubIndex)	SSR##SubIndex&(1<<6)/*SSR--TSF bit indicate finish or not, 1=Not finish*/
/*Not Edit*/#define _EP_Drv_TransfFinish(SubIndex)	_EP_Drv_TransfFinish_(SubIndex)

/*Not Edit*/#define _EP_Drv_ClearTsfErr_(SubIndex)		SIR##SubIndex=7
/*Not Edit*/#define _EP_Drv_ClearTsfErr(SubIndex)	_EP_Drv_ClearTsfErr_(SubIndex)

/*Not Edit*/#define _EP_DrvType_CMD_(SubIndex) EP_OutPut(1);SCR##SubIndex&=0xCFFF;SCR##SubIndex|=0x3000
/*Not Edit*/#define _EP_DrvType_CMD(SubIndex)	 _EP_DrvType_CMD_(SubIndex)

/*Not Edit*/#define _EP_DrvType_Data_(SubIndex) SCR##SubIndex&=0xCFFF;SCR##SubIndex|=0x1000
/*Not Edit*/#define _EP_DrvType_Data(SubIndex)	 _EP_DrvType_Data_(SubIndex)


/*Not Edit*/#define EP_Drv_ClkOn()				_EP_Drv_ClkOn(Drv_Group)
/*Not Edit*/#define EP_Drv_RegInit()			 	_EP_Drv_RegInit(Drv_Group,Drv_SubIndex);_EP_Drv_PinRelocatin()	
/*Not Edit*/#define EP_Dvr_Exit()				_EP_Dvr_Exit(Drv_Group,Drv_SubIndex)
/*Not Edit*/#define EP_Drv_SetTranfDataBits(bits) 	_EP_Drv_SetTranfDataBits(Drv_SubIndex,bits)
/*Not Edit*/#define EP_Drv_Output(data)			_EP_Drv_Output(Drv_SubIndex,data)
/*Not Edit*/#define EP_Drv_ReceiveData()			_EP_Drv_ReceiveData(Drv_SubIndex)
/*Not Edit*/#define EP_Drv_GetTsfErr()			_EP_Drv_GetTsfErr(Drv_SubIndex)
/*Not Edit*/#define EP_Drv_ClearTsfErr()			_EP_Drv_ClearTsfErr(Drv_SubIndex)
/*Not Edit*/#define EP_DrvType_Data()			_EP_DrvType_Data(Drv_SubIndex)
/*Not Edit*/#define EP_DrvType_CMD()			_EP_DrvType_CMD(Drv_SubIndex)
/*Not Edit*/#define EP_Drv_WaitFinish()			while(_EP_Drv_TransfFinish(Drv_SubIndex))

#endif

