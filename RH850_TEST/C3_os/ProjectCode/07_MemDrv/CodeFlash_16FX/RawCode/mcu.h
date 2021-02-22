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
/** \file mcu.h
 **
 ** MCU description file
 **
 ** History:
 **   - 2009-10-02  0.01  JWa  First version
 **   - 2009-10-21  0.02  JWa  removed __far and __near macros
 **                            (use CPU_TYPE for differentiation)
 **   - 2010-03-19  0.03  JWa  modifiy SVN keywords
 **   - 2010-03-19  0.04  JWa  add clock definitions and MCU series
 *****************************************************************************/

#ifndef __MCU_H__
#define __MCU_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "_ffmc16.h"	// include mcu register header file

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

// -------------------------------------------------------------------
// C P U   T Y P E
// -------------------------------------------------------------------

#define CPU_TYPE_8BIT              8          ///< CPU_TYPE: 8-bit
#define CPU_TYPE_16BIT             16         ///< CPU_TYPE: 16-bit
#define CPU_TYPE_32BIT             32         ///< CPU_TYPE: 32-bit

#ifndef CPU_TYPE
    /** CPU type setting (8-, 16-, 32-bit) */
    #define CPU_TYPE               CPU_TYPE_16BIT
#endif

// -------------------------------------------------------------------
// M C U   S E R I E S
// -------------------------------------------------------------------

#define MCU_SERIES_96300		   96300       ///< MCU_SERIES: 16FX MB96300
#define MCU_SERIES_96600		   96600       ///< MCU_SERIES: 16FX MB96600
#define MCU_SERIES_91460		   91460       ///< MCU_SERIES: FR MB91460
#define MCU_SERIES_9E126		   0x9E126     ///< MCU_SERIES: FCR4 MB9E126 (Calypso)

/** MCU series setting */
#define MCU_SERIES				   MCU_SERIES_96600

//-----------------------------------------------------------------------------
// C L O C K   S E T T I N G S
// -------------------------------------------------------------------

//------------------------------------------------------------------
//  Source clocks
//------------------------------------------------------------------

#ifndef MCU_FREQ_CLK_MAIN_HZ
    /** Input frequency of main oscillation in Hertz */
    #define MCU_FREQ_CLK_MAIN_HZ   4000000UL
#endif

#ifndef MCU_FREQ_CLK_SUB_HZ
    /** Input frequency of main oscillation in Hertz */
    #define MCU_FREQ_CLK_SUB_HZ    32768UL
#endif


/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __MCU_H__ */
