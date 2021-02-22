/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE  [Flash driver for MB96F673 MCU                                      ]
*-----------------------------------------------------------------------------
  .FILE   [ flash.h                                                         ]
  .AUTHOR [  Tan Fumin				                                     ]
*-----------------------------------------------------------------------------
 Version Date        		Author                       
Change                      
 -----------------------------------------------------------------------------
 Rev 00.00.00 2014/10/28    Tan Fumin      			 The first version  
                                                 update Telltales process
****************************** .FILE_HEADER_END ******************************/

#include "general.h"
#include "CFD_type.h"
#include "CFD_cfg.h"


#ifndef CFD_H
#define CFD_H


uint8 CFD_u8Init(void);
void CFD_vExit(void);
uint8 CFD_u8WriteData(uint32 u32FlsAddress, uint8 *pu8DataHead,uint16 u16DataLen);
uint8 CFD_u8WriteWord(uint32 u32Address, uint16 u16Data);
uint8 CFD_u8SectorErase(uint32 u32SectorAddress);
void CFD_DisableWritingPermanently(void);

#endif 

