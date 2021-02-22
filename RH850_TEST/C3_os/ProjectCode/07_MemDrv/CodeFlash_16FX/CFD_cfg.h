/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE  [Flash driver for MB96F673 MCU                                      ]
*-----------------------------------------------------------------------------
  .FILE   [ flash_cfg.h                                                         ]
  .AUTHOR [  Tan Fumin				                                     ]
*-----------------------------------------------------------------------------
 Version Date        		Author                       
Change                      
 -----------------------------------------------------------------------------
 Rev 00.00.00 2014/10/28    Tan Fumin      			 The first version  
                                                 update Telltales process
****************************** .FILE_HEADER_END ******************************/

#ifndef CFD_CFG_H
#define CFD_CFG_H

//#define CFD_MinFlsAddressForPTS	0xDF8000UL//0xDF2000UL
//#define CFD_MaxFlsAddressForPTS	0xDF9FFFUL

#define CFD_MinFlsAddress		0x00DF2000UL//0xDF2000UL
#define CFD_MaxFlsAddress		0x00DF9FFFUL//0xDF7FFFUL
#define CFD_FlsIllagelAddress	0xFFFFFFFFUL
#define CFD_FlsBlockSize		(8*1024)



#endif

