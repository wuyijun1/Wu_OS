/*******************************************************************************
| Module Name: Memory Hardware Abstraction module
| File Name: MemAbs_Type.h
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2016 Huizhou Desay SV Automotive Co., Ltd.    All rights reserved.
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
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2017.01.11  V0.01	Tan, fumin	:create this module
********************************************************************************/
#ifndef _MemAbs_Type_H_
#define _MemAbs_Type_H_


typedef enum 
{
#if MemAbs_MemEnable_EEPROM!=0
	MemAbs_MemType_EEPROM,
#endif
#if MemAbs_MemEnable_OnChipDataFlash!=0
	MemAbs_MemType_OnChipDataFlash,
#endif
#if MemAbs_MemEnable_CodeFlash!=0
 	MemAbs_MemType_CodeFlash,
#endif
#if MemAbs_MemEnable_NandFlash!=0
	MemAbs_MemType_NandFlash,
#endif

}MemAbs_enMemType;

typedef enum 
{
	MemAbs_MemOverWrite,
	MemAbs_MemPendingWrite,
};

typedef enum 
{
	MemAbs_MemOperat_MMI,
	MemAbs_MemOperat_DTC,
	MemAbs_MemOperat_OAT,
	MemAbs_MemOperat_UserConf,
	MemAbs_MemOperat_PTS_Area,
	MemAbs_MemOperat_Mile,
	
	MemAbs_MemOperat_Max,
}MemAbs_enOperationReqType;

typedef enum 
{
	MemAbs_DeviceOperat_Null,
	MemAbs_DeviceOperat_Read,
	MemAbs_DeviceOperat_Write,
	MemAbs_DeviceOperat_Erase,
	MemAbs_DeviceOperat_BlankCheck,
	MemAbs_DeviceOperat_ProtectCtrl,
	MemAbs_DeviceOperat_ReadForCheck,/*check the data write OK or not~~*/
	
	MemAbs_DeviceOperat_Max,
}MemAbs_enDeviceOperatType;

typedef const struct 
{
	MemAbs_enOperationReqType OperatReqType;
	MemAbs_enMemType MemType;
	uint32 LogicStartAddr;/*need ??*/
	uint32 PhysicalStartAddr;
	uint32 MapLenth;	
	uint16 Pending;/*using the memory pending or not, if pending, it roll using, else it will overwrite every time*/	
	uint16 UnitSize;/*this member using only in pending mode*/	
}MemAbs_tstMemMapping;


typedef char      DevName;
typedef uint16  (*DevOpen)(uint16 type);
typedef uint16  (*DevClose)(uint16 type);
typedef uint16  (*DevRead)(uint32 PhysicalAddr,void *ToDataHead,uint32 DataLen);
typedef uint16  (*DevWrite)(uint32 PhysicalAddr,void *FromDataHead,uint32 DataLen);
typedef uint16  (*DevErase)(uint32 PhysicalAddr,uint32 DataLen);
typedef uint16  (*DevBlankCheck)(uint32 PhysicalAddr,uint32 DataLen);/*check the data in non-voliatle memory is writen or not */
typedef uint16  (*DevProtect)(uint16 type);
typedef uint16  (*DevHandle)(void);
typedef uint16  (*DevInquire)(void);

typedef const struct 
{
	DevName *Name;
	DevOpen Open;
	DevClose Close;
	DevRead Read;
	DevWrite Write;
	DevErase Erase;
	DevProtect Protect;
	DevBlankCheck BlankCheck;
	DevInquire Inquire;
	DevHandle  Handle;
}MemAbs_tstMemDeviceIf;


typedef struct
{
	uint16 u16InIndex;
	uint16 u16OutIndex;
	struct 
	{
		MemAbs_enDeviceOperatType DevOperatReq;
		uint16 DataLen_Byte;
		uint32 DeviceAddr;
		uint32 RamAddr;
	}Request[MemAbs_MaxMemOperReq];
}MemAbs_tstMemRequestList;



#endif/*end of this file*/

