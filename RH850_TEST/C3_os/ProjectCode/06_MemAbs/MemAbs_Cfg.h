/*******************************************************************************
| Module Name: Memory Hardware Abstraction module
| File Name: MemAbs_Cfg.h
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
#ifndef _MemAbs_Cfg_H_
#define _MemAbs_Cfg_H_

#define MemAbs_MemEnable_EEPROM			1/*set this value to 1 if using this type memory*/
#define MemAbs_MemEnable_OnChipDataFlash	1	
#define MemAbs_MemEnable_CodeFlash		1
#define MemAbs_MemEnable_NandFlash		1

#define MemAbs_MaxMemOperReq		4


#define MemAbs_MemoryTypes 	(MemAbs_MemEnable_EEPROM +\
							MemAbs_MemEnable_OnChipDataFlash+\
							MemAbs_MemEnable_CodeFlash+\
							MemAbs_MemEnable_NandFlash) /*the using memory type number, please refer the the enum */






#endif/*end of this file*/

