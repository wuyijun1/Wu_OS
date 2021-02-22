/***************************************************************************************************
                                TLC6C59 LED DRIVER                                
                                        
  .File Name  : TLC6C59.h
  
  .Description: This file is used for TLC6C59 LED driver.
  
  --------------------------------------------------------------------------------------------------
    Version     Date        Author          Change
  --------------------------------------------------------------------------------------------------
    V001        2017-01-10  Chen Xiongzhi   - Creat this module.
***************************************************************************************************/

#ifndef TLC6C59_H
#define TLC6C59_H

#include "MCU_CFG.h"
#include "s_spi.h"
#include "TLC6C59_Type.h "
#include "TLC6C59_Cfg.h"

void TLC6C59_vReset(void);
void TLC6C59_vInit(void);
void TLC6C59_vDeinit(void);
void TLC6C59_vMain(void);

#endif

