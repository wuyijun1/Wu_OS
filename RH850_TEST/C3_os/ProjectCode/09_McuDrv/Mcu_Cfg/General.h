/*******************************************************************************
| Module Name: General define for platform
| File Name: General.h
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
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2015.07.28  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifndef GENERAL_H
#define GENERAL_H

typedef unsigned char 		uint8;
typedef signed  char 		int8;

typedef unsigned short	uint16;
typedef signed short	int16;

typedef unsigned long 		uint32;
typedef signed long			int32;

typedef unsigned int 		bitFill;

typedef void 	(*vpFun)(void);
typedef void 	(*vpFun_u8)(uint8 u8data);
typedef void 	(*vpFun_u16)(uint16 u16data);
typedef void 	(*vpFun_u32_u8)(uint32 u32data,uint8 u8data);
typedef void 	(*vpFunDumy)();
typedef uint16 (*u16Fun)(void);

typedef unsigned char Std_ReturnType;
typedef void 			(*tFuncPtr)(void);

typedef struct
{
   const tFuncPtr vfpAction;  	

}ThreadAction;

typedef struct
{
	uint8 CcpCommandFlag;
	uint8 CcpCommand;
	uint16 CcpContronData;
}tstCcpContronType;


#ifndef True
#define True	1   
#endif
#ifndef False
#define False	0   
#endif

#ifndef MIN_INT8
#define MIN_INT8		((int8)(0x80))/*((signed char)((((unsigned char)-1)>>1)+1))*/
#endif
#ifndef MAX_INT8
#define MAX_INT8		((int8)(0x7F))/*((signed char)((((unsigned char)-1)>>1)))*/
#endif
#ifndef MIN_INT16
#define MIN_INT16		((int16)(0x8000))/*((signed short)(((unsigned short)-1)>>1)+1)*/
#endif
#ifndef MAX_INT16
#define MAX_INT16	((int16)(0x7FFF))/*((signed short)(((unsigned short)-1)>>1))*/
#endif
#ifndef MIN_INT32
#define MIN_INT32		((int32)(0x80000000L))/*((signed long)((((unsigned long)-1)>>1)+1))*/
#endif
#ifndef MAX_INT32
#define MAX_INT32	((int32)(0x7FFFFFFFL))/*((signed long)((((unsigned long)-1)>>1)))*/
#endif

#ifndef MIN_UINT8
#define MIN_UINT8	((uint8)(0))/*((unsigned char)0)*/
#endif
#ifndef MAX_UINT8
#define MAX_UINT8	((uint8)(0xFF))/*((unsigned char)-1)*/
#endif
#ifndef MIN_UINT16
#define MIN_UINT16	((uint16)(0))/*((unsigned short)0)*/
#endif
#ifndef MAX_UINT16
#define MAX_UINT16	((uint16)(0xFFFF))/*((unsigned short)-1)*/
#endif
#ifndef MIN_UINT32
#define MIN_UINT32	((uint32)(0UL))/*((unsigned long)0)*/
#endif
#ifndef MAX_UINT32
#define MAX_UINT32	((uint32)(0xFFFFFFFFUL))/*((unsigned long)-1)*/
#endif

#ifndef MAX
#define MAX(a,b)	((a)>(b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b)	((a)<(b) ? (a) : (b))
#endif
#ifndef ABS
#define ABS(a)		((a)>(0) ? (a) :(-(a)))
#endif

#ifndef SetBit
#define SetBit(a,BitNum)		((a) |=(1<<(BitNum)))
#endif
#ifndef ClrBit
#define ClrBit(a,BitNum)			((a) &=(~(1<<(BitNum))))
#endif
#ifndef TestBit
#define TestBit(a,BitNum)			(((a)>>(BitNum)) & 1)
#endif

				
#endif/*end of this file*/

