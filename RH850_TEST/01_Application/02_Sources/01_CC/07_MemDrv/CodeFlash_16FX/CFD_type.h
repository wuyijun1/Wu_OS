/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE  [Flash driver for MB96F673 MCU                                      ]
*-----------------------------------------------------------------------------
  .FILE   [ flash_type.h                                                         ]
  .AUTHOR [  Tan Fumin				                                     ]
*-----------------------------------------------------------------------------
 Version Date        		Author                       
Change                      
 -----------------------------------------------------------------------------
 Rev 00.00.00 2014/10/28    Tan Fumin      			 The first version  
                                                 update Telltales process
****************************** .FILE_HEADER_END ******************************/

#ifndef CFD_TYPE_H
#define CFD_TYPE_H


#define SECTOR_SAS       0xDF0000L
#define SECTOR_SA1       0xDF2000L
#define SECTOR_SA2       0xDF4000L
#define SECTOR_SA3       0xDF6000L
#define SECTOR_SA4       0xDF8000L
#define SECTOR_SA38      0xFE0000L
#define SECTOR_SA39      0xFF0000L




#define DQ7 0x80          // Data polling flag
#define DQ5 0x20          // Time limit exceeding flag
#define DQ3 0x08          // Sector erase timer flag

#endif

