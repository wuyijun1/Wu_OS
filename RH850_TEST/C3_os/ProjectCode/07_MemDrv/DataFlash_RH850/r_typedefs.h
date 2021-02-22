#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * File Name     : $Source: r_typedefs.h $
 * Mod. Revision : $Revision: 1.7 $
 * Mod. Date     : $Date: 2016/05/31 16:15:24JST $
 * Device(s)     : All Renesas device families
 * Description   : This file contains the Renesas standard type definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER 
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products. 
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
 * applicable laws, including copyright laws. 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED 
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS 
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY 
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link: 
 * http://www.renesas.com/disclaimer 
 * 
 * Copyright (C) 2014-2016 Renesas Electronics Corporation. All rights reserved.     
 *********************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
 * Reason:       To support automatic insertion of revision, module name etc. by the source revision control system 
 *               it is necessary to violate the rule, because the system uses non basic characters as placeholders.
 * Verification: The placeholders are used in commentars only. Therefore rule violation cannot influency code 
 *               compilation.
 *********************************************************************************************************************/

#ifndef R_TYPEDEFS_H 
#define R_TYPEDEFS_H 

/*********************************************************************************************************************
 * standard types definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   QAC message 4623, 4600
 * Reason:       QAC requests to use <stdint.h> and <stdbool.h> for the standard types. However, in order to support
                 non C99 compliant compilers too, the Renesas include file explicitly defining the standard types 
                 is included into the library. 
 * Verification: Reviewed that the type definitions match the standard definitions (char = 8bit, short = 16bit, 
                 long = 32bit)
 *********************************************************************************************************************/
typedef signed char         int8_t;                                             /* PRQA S 4623 */
typedef unsigned char       uint8_t;                                            /* PRQA S 4623 */
typedef signed short        int16_t;                                            /* PRQA S 4623 */
typedef unsigned short      uint16_t;                                           /* PRQA S 4623 */
typedef signed long         int32_t;                                            /* PRQA S 4623 */
typedef unsigned long       uint32_t;                                           /* PRQA S 4623 */
typedef unsigned char       rBool;                                                 
 
#define bool                rBool                                               /* PRQA S 4600 */
#define false               0                                                   /* PRQA S 4600 */
#define true                1                                                   /* PRQA S 4600 */

/*********************************************************************************************************************/
#endif    /* #ifndef R_TYPEDEFS_H  */
