/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE: Data Flash driver for NEC 78F1845
*-----------------------------------------------------------------------------
  .FILE:FLS_Drv.h
  .AUTHOR:Tan, fumin
*-----------------------------------------------------------------------------

 Date        Author                       Change
 -----------------------------------------------------------------------------
2013.02.28  Tan, fumin		   :create this module

*****************************************************************************/
#include "General.h"

//3***************************************************************************************************************************************
/*******************
if open this define, you can call the function when driver finish its work
*******************/
#define FLS_CallBackFunction_Enable	1

/*******************
1 addr = 4 bytes data, it is a mirror address for lib driver
*******************/
#define FLS_END_ADDR		0x0FFF

/*******************
The size in one block for erase operation
*******************/
#define FLS_Block_Size		2048

/*******************
The mini size for read/write operation
*******************/
#define FLS_Address_Size		4

//3***************************************************************************************************************************************


#if HW_Architecture!=NEC_78F1845
#error "This driver NOT support for this MCU!!!"
#endif

#ifndef FLS_DRV_H
#define FLS_DRV_H

#include "fdl_types.h"

typedef struct {
	uint8 ThisCmd;
	uint8 ExpCmd;
	uint32 __far*RamAddr_Cur;
	uint32 __far*RamAddr_E;
	#if FLS_CallBackFunction_Enable
	vpFun CallBack;
	#endif
	fal_request_t InOutData;
}FLS_stFLS;

/*flash operation common list*/
enum
{
	FLS_enCMD_Null,
	FLS_enCMD_Ready,
	FLS_enCMD_Read,
	FLS_enCMD_Write,
	FLS_enCMD_WaitReady,
	FLS_enCMD_Erase,
	FLS_enCMD_DoCallBack,
};

#define FLS_Block_LogAddr	(FLS_Block_Size/FLS_Address_Size)

#define FLS_CmdExe(cmd) 	FLS_stCMD.InOutData.command_enu=cmd; FAL_Execute(&FLS_stCMD.InOutData)

#define FLS_SetFlsAddr(addr)	FLS_stCMD.InOutData.index_u16=addr
#define FLS_FlsAddr(addr)		FLS_stCMD.InOutData.index_u16


#define FLS_SetFlsData(flsdata)	FLS_stCMD.InOutData.data_u32=flsdata
#define FLS_GetFlsData()			FLS_stCMD.InOutData.data_u32

#define FLS_SetThisCmd(cmd)		FLS_stCMD.ThisCmd=cmd
#define FLS_GetThisCmd()			FLS_stCMD.ThisCmd

#define FLS_SetExpCmd(cmd)		FLS_stCMD.ExpCmd=cmd
#define FLS_GetExpCmd()			FLS_stCMD.ExpCmd

#define FLS_GetCurRamAddr()		FLS_stCMD.RamAddr_Cur
#define FLS_CurRamAddr()			FLS_stCMD.RamAddr_Cur
#define FLS_SetCurRamAddr(addr)	FLS_stCMD.RamAddr_Cur=(void __far*)addr

#define FLS_GetEndRamAddr()			FLS_stCMD.RamAddr_E
#define FLS_EndRamAddr()			FLS_stCMD.RamAddr_E
#define FLS_SetEndRamAddr(addr)		FLS_stCMD.RamAddr_E=(void __far*)addr

#define FLS_GetHandleResult()			FLS_stCMD.InOutData.status_enu


#define FLS_GetCallBackFun()			FLS_stCMD.CallBack
#define FLS_RunCallBackFun()			FLS_stCMD.CallBack()
#define FLS_ClearCallBackFun()			FLS_stCMD.CallBack=NULL

/*flash operation error list*/
#define FLS_ERR_NULL	0
#define FLS_ERR_Busy	1
#define FLS_ERR_OutOfRange	2
#define FLS_ERR_Len			3
#define FLS_ERR_WriteErr		4
#define FLS_ERR_EraseErr		5

void 	FLS_vCheckReady(void);
uint8 	FLS_u8ReadData(uint16 FromFlashAddr, void *ToRam, uint16 DataLen_Byte);
uint8 	FLS_u8WriteData(uint16 ToFlashAddr, void *FromRam, uint16 DataLen_Byte);
uint8 	FLS_u8Erase(uint16 FlsAddr);
uint8 	FLS_u8EraseWait(uint16 FlsAddr);
void 	FLS_vDrvInit(void);
void 	FLS_vDrvExit(void);
uint8 	FLS_u8SetCallBackFun(vpFun vpfFinishFunction);
uint8 	FLS_u8GetSatus(void);
void 	FLS_vSetCallBackFun(vpFun Function);

#endif



