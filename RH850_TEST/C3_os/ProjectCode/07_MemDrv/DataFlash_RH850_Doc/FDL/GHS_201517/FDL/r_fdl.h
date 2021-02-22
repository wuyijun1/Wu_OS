#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.11 $
 * Mod. Revision : $Revision: 1.12 $
 * Mod. Date     : $Date: 2016/06/01 12:39:16JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : User interface function prototypes
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
 * Copyright (C) 2015-2016 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
 * Reason:       To support automatic insertion of revision, module name etc. by the source revision control system
 *               it is necessary to violate the rule, because the system uses non basic characters as placeholders.
 * Verification: The placeholders are used in commentaries only. Therefore rule violation cannot influence code
 *               compilation.
 *********************************************************************************************************************/

#ifndef R_FDL_H
#define R_FDL_H

/*********************************************************************************************************************
 * Global compiler definitions
 *********************************************************************************************************************/
#define R_FDL_COMP_GHS 1
#define R_FDL_COMP_IAR 2
#define R_FDL_COMP_REC 3

#if defined (__IAR_SYSTEMS_ASM__)
    #define R_FDL_COMPILER R_FDL_COMP_IAR
#elif defined (__IAR_SYSTEMS_ICC__)
    #define R_FDL_COMPILER R_FDL_COMP_IAR
#elif defined (__v850e3v5__)
    #define R_FDL_COMPILER R_FDL_COMP_REC
#else /*GHS */
    #define R_FDL_COMPILER R_FDL_COMP_GHS
#endif

/*********************************************************************************************************************
 * Include list
 *********************************************************************************************************************/
#include "fdl_cfg.h"
#include "r_fdl_types.h"


#ifdef R_FDL_USERIF_C
    #define R_FDL_EXTERN
#else
    #define R_FDL_EXTERN extern
#endif
/*********************************************************************************************************************
 * Global function prototypes
 *********************************************************************************************************************/
/* FDL initialization function */
R_FDL_EXTERN r_fdl_status_t     R_FDL_Init (const r_fdl_descriptor_t * descriptor_pstr);

/* Flash operation initiation */
R_FDL_EXTERN void               R_FDL_Execute (r_fdl_request_t * request_pstr);

/* Flash operation forwarding and status check */
R_FDL_EXTERN void               R_FDL_Handler (void);

/* Flash operation suspend request */
R_FDL_EXTERN r_fdl_status_t     R_FDL_SuspendRequest (void);

/* Flash operation resume request after suspend */
R_FDL_EXTERN r_fdl_status_t     R_FDL_ResumeRequest (void);

/* Asynchronous function to prepare FDL for device power save modes */
R_FDL_EXTERN r_fdl_status_t     R_FDL_StandBy (void);

/* Asynchronous function to resume FDL after leaving device power save modes */
R_FDL_EXTERN r_fdl_status_t     R_FDL_WakeUp (void);

/* Flash operation cancel request */
R_FDL_EXTERN r_fdl_status_t     R_FDL_CancelRequest (void);

/* Return of FDL library version string */
R_FDL_EXTERN const uint8_t *    R_FDL_GetVersionString (void);


/*********************************************************************************************************************/
#endif /* ifndef R_FDL_H */

