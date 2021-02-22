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
#include "mcu_cfg.h"


#include "./r_typedefs.h"
#include "./app.h"
#include "./r_fdl_types.h"
#include "./r_fdl_env.h"
#include "./r_fdl_global.h"
/*#include "./r_fdl_mem_map.h"*/
#include "./r_fdl.h"
#include "./fdl_cfg.h"
#include "./fdl_cfg.h"
#include "./fdl_descriptor.h"
#include "./fdl_user.h"
#include "./target.h"

//3***************************************************************************************************************************************
/*******************
if open this define, you can call the function when driver finish its work
*******************/
#define FLS_CallBackFunction_Enable	1

/*******************
1 addr = 4 bytes data, it is a mirror address for lib driver
*******************/
#define FLS_END_ADDR		0xFF207FFFul

/*******************
The base address of the flash 
*******************/
#define FLS_BaseAddress		0xFF200000ul


/*******************
The size in one block for erase operation
*******************/
#define FLS_Block_Size		64

/*******************
The mini size for read/write operation
*******************/
#define FLS_Address_Size		4


#define FLS_DataFlow_Size		4

//3***************************************************************************************************************************************


#ifndef FLS_DRV_H
#define FLS_DRV_H


typedef struct {
	uint8 ThisCmd;
	uint8 ExpCmd;
	uint32 FlsAddr_Cur; /*erase flash flow,160702*/
	uint32 FlsAddr_E;	
	uint32* RamAddr_Cur;
	uint32* RamAddr_E;
	#if FLS_CallBackFunction_Enable
	vpFun CallBack;
	#endif
	r_fdl_request_t InOutData;
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


#define FLS_CmdExe(cmd) 	FLS_stCMD.InOutData.command_enu=cmd;\
							FLS_stCMD.InOutData.accessType_enu  = R_FDL_ACCESS_USER;\
							R_FDL_Execute(&FLS_stCMD.InOutData)

#define FLS_FlsAddr(addr)		FLS_stCMD.InOutData.idx_u32
#define FLS_SetFlsAddr(addr)	FLS_stCMD.InOutData.idx_u32=addr
#define FLS_SetDataLenth(len)		FLS_stCMD.InOutData.cnt_u16=((len) +((len)&3))>>2
#define FLS_SetCurRamAddr(addr)		FLS_stCMD.InOutData.bufAddr_u32=(uint32)addr
#define FLS_GetCurRamAddr() 		FLS_stCMD.InOutData.bufAddr_u32
#define FLS_GetHandleResult()			FLS_stCMD.InOutData.status_enu

#define FLS_SetThisCmd(cmd)		FLS_stCMD.ThisCmd=cmd
#define FLS_GetThisCmd()			FLS_stCMD.ThisCmd

#define FLS_SetExpCmd(cmd)		FLS_stCMD.ExpCmd=cmd
#define FLS_GetExpCmd()			FLS_stCMD.ExpCmd

#define FLS_GetFlowCurRamAddr()		FLS_stCMD.RamAddr_Cur /*160625*/
#define FLS_CurFlowRamAddr()		FLS_stCMD.RamAddr_Cur
#define FLS_SetFlowCurRamAddr(addr)	FLS_stCMD.RamAddr_Cur=(void *)addr

#define FLS_GetFlowEndRamAddr()			FLS_stCMD.RamAddr_E
#define FLS_EndFlowRamAddr()			FLS_stCMD.RamAddr_E
#define FLS_SetFlowEndRamAddr(addr)		FLS_stCMD.RamAddr_E=(void *)addr

#define FLS_CleanCmd() 	FLS_stCMD.InOutData.accessType_enu=R_FDL_ACCESS_NONE;\
						FLS_stCMD.InOutData.bufAddr_u32=0;\
						FLS_stCMD.InOutData.cnt_u16=0;\
						FLS_stCMD.InOutData.command_enu=0xff;\
						FLS_stCMD.InOutData.idx_u32=0xffffffff

#define FLS_GetFlowCurFlsAddr()		FLS_stCMD.FlsAddr_Cur /*160702*/
#define FLS_CurFlowFlsAddr()		FLS_stCMD.FlsAddr_Cur
#define FLS_SetFlowCurFlsAddr(addr)	FLS_stCMD.FlsAddr_Cur=addr

#define FLS_GetFlowEndFlsAddr()			FLS_stCMD.FlsAddr_E
#define FLS_EndFlowFlsAddr()			FLS_stCMD.FlsAddr_E
#define FLS_SetFlowEndFlsAddr(addr)		FLS_stCMD.FlsAddr_E=addr

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
#define FLS_ERR_Address		6
#define FLS_ERR_Init		7


uint8 	FLS_u8SetCallBackFun(vpFun vpfFinishFunction);
uint8 	FLS_u8GetSatus(void);
void 	FLS_vCheckReady(void);
void 	FLS_vDrvInit(void);
void 	FLS_vDrvExit(void);
uint8 	FLS_u8ReadDataWait(uint32 FromFlashAddr, void *ToRam, uint16 DataLen_Byte);
uint8 	FLS_u8WriteDataWait(uint32 ToFlashAddr, void *FromRam, uint16 DataLen_Byte);
uint8 	FLS_u8WriteData(uint32 ToFlashAddr, void *FromRam, uint16 DataLen_Byte);
uint8 	FLS_u8Erase(uint32 FlsAddr,uint16 DataLen_Byte);
uint8 	FLS_u8EraseWait(uint32 FlsAddr,uint16 DataLen_Byte);

//extern void FDL_Open( void );


#endif



