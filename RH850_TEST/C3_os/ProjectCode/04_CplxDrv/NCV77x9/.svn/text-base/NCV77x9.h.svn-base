/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE   DC Motor Driver for NCV77x9, 	                             ]
*-----------------------------------------------------------------------------
  .FILE   NCV77x9.h                                                      ]
   .AUTHOR [  tan fumin 				                                     ]
*-----------------------------------------------------------------------------
NOTE:
		This software package only for DC motor driver nvc771!
 	
 Version Date        Author                       Change
 -----------------------------------------------------------------------------
 Rev 1.0 2015-4-28   tan fumin         module template update. 
 
****************************** .FILE_HEADER_END ******************************/

#ifndef NCV77x9_H
#define NCV77x9_H

#include "hal.h"

#include "s_spi.h"
#include	"NCV77x9_type.h "
#include "NCV77x9_cfg.h"

void MDVR_vReset(void);
void MDVR_vInit(void);
void MDVR_vDeinit(void);
void MDVR_vDisableCtrl(void);
void MDVR_vEnableCtrl(void);
uint8 MDVR_u8ChannelCtrl(uint8 channel, MDVR_enCtrlType status);
void MDVR_vDrvStatusUpdate(void);
uint16 MDVR_u16GetFeedBackStatus(void);

void MDVR_vErrTSDProcess(void);
void MDVR_vErrProcess(uint16 u16ErrFeedBack);

#endif

