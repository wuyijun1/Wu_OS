/******************************************************************************
 * $Revision$
 * $Date$
 *****************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)                */
/*                                                                           */
/* The following software deliverable is intended for and must only be       */
/* used for reference and in an evaluation laboratory environment.           */
/* It is provided on an as-is basis without charge and is subject to         */
/* alterations.                                                              */
/* It is the user’s obligation to fully test the software in its             */
/* environment and to ensure proper functionality, qualification and         */
/* compliance with component specifications.                                 */
/*                                                                           */
/* In the event the software deliverable includes the use of open            */
/* source components, the provisions of the governing open source            */
/* license agreement shall apply with respect to such software               */
/* deliverable.                                                              */
/* FSEU does not warrant that the deliverables do not infringe any           */
/* third party intellectual property right (IPR). In the event that          */
/* the deliverables infringe a third party IPR it is the sole                */
/* responsibility of the customer to obtain necessary licenses to            */
/* continue the usage of the deliverable.                                    */
/*                                                                           */
/* To the maximum extent permitted by applicable law FSEU disclaims all      */
/* warranties, whether express or implied, in particular, but not            */
/* limited to, warranties of merchantability and fitness for a               */
/* particular purpose for which the deliverable is not designated.           */
/*                                                                           */
/* To the maximum extent permitted by applicable law, FSEU’s liability       */
/* is restricted to intentional misconduct and gross negligence.             */
/* FSEU is not liable for consequential damages.                             */
/*                                                                           */
/* (V1.5)                                                                    */
/*****************************************************************************/
/** \file flash.h
 **
 ** Add description here...
 **
 ** History:
 **   - 2012-01-26  1.00  CEy  First version 
 *****************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/


/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

#define SECTOR_SAS       0xDF0000L
#define SECTOR_SA1       0xDF2000L
#define SECTOR_SA2       0xDF4000L
#define SECTOR_SA3       0xDF6000L
#define SECTOR_SA4       0xDF8000L
#define SECTOR_SA38      0xFE0000L
#define SECTOR_SA39      0xFF0000L


/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/
extern en_result_t Flash_EnableWriting(void);
extern void Flash_DisableWriting(void);
extern en_result_t Flash_Write8(uint32_t u32Address, uint8_t u8Data);
extern en_result_t Flash_Write16(uint32_t u32Address, uint16_t u16Data);
extern en_result_t Flash_SectorErase(uint32_t u32SectorAddress);

#endif /* __FLASH_H__ */

