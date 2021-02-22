#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_user_if_init.c $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.11 $
 * Mod. Revision : $Revision: 1.7 $
 * Mod. Date     : $Date: 2016/06/01 12:39:22JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Source code for FDL initialization
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

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 19.1 (QAC message 5087)
 * Reason:       The section mapping concept (Mapping code, constants and data to specific linker sections) bases on
 *               a central include file containing all section mapping  defines and pragmas. This need to be included
 *               multiple times within the code. The file itself only contains those defines and pragmas.
 * Verification: This is the standard concept defined for AUTOSAR implementations
 *********************************************************************************************************************/


/*********************************************************************************************************************
 * FDL header files include
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "r_fdl.h"


/*********************************************************************************************************************
 * Global function prototypes
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 8.8 (QAC message 3447)
 * Reason:       Library is delivered as source code and as a precompiled object.
 *               The file r_fdl_user_if_init.c is not included on generation of the precompiled object.
 *               It is delivered as a separate file and cannot include any other header files, except the
 *               defined interface header files. The function is a library internal function and its declaration
 *               is not part of the interface header files.
 * Verification: -
 *********************************************************************************************************************/
extern r_fdl_status_t R_FDL_InitVariables (const r_fdl_descriptor_t * descriptor_pstr);            /* PRQA S 3447 */


/*********************************************************************************************************************
 * FDL internal section mapping definitions
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                         /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Init
 *********************************************************************************************************************/
/**
 * User interface function:
 * This function initializes the FDL. It must be called before any execution of a FDL function.
 * Sequence:
 * - Call the function to initialize the library RAM and do parameter checks
 * If compatibility mode is used then:
 * - Call the function to initialize the FCU RAM
 * - Call the function to set the frequency information with frequency check
 *   - Frequency is within reasonable range between R_FCU_FMIN and R_FCU_FMAX
 *
 * In error case the library is set to not initialized (R_FDL_ISTAT_NOINIT)
 *
 * @param[in]  descriptor_pstr - Pointer to the FDL descriptor structure
 * @return     Initialization status when returned from function call:
 *             - R_FDL_OK                - Initialization was successful
 *             - R_FDL_ERR_CONFIGURATION - FDL configuration parameter error
 *             If compatibility mode is used then following error codes may be returned:
 *             - R_FDL_ERR_PROTECTION    - Programming hardware reset was prohibited
 *             - R_FDL_ERR_INTERNAL      - Internal (HW) error during HW initialization
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 14.1 (QAC message 1503)
 * Reason:       This function is not used within the library, it is only used by the user
 *               application.
 * Verification: This function is part of the library API and therefore essential on the one hand.
 *               On the other hand the QAC warning is correct, because this function is never
 *               called within the library. To solve this dilemma it is necessary and suitable
 *               to disable the message.
 *********************************************************************************************************************/
#ifdef R_FDL_LIB_V1_COMPATIBILITY
    r_fdl_status_t R_FDL_Init (const r_fdl_descriptor_t * descriptor_pstr)                         /* PRQA S 1503 */
    {
        r_fdl_status_t  ret;
        r_fdl_request_t request;

        ret = R_FDL_InitVariables (descriptor_pstr);

        /* Init_Variables already does some configuration checks */
        if (R_FDL_OK == ret)
        {
            request.command_enu = R_FDL_CMD_PREPARE_ENV;
            R_FDL_Execute (&request);

            while (R_FDL_BUSY == request.status_enu)
            {
                R_FDL_Handler ();
            }

            ret = request.status_enu;
        }

        return (ret);
    } /* R_FDL_Init */
#else
    r_fdl_status_t R_FDL_Init (const r_fdl_descriptor_t * descriptor_pstr)                         /* PRQA S 1503 */
    {
        r_fdl_status_t ret;

        ret = R_FDL_InitVariables (descriptor_pstr);

        return (ret);
    } /* R_FDL_Init */
#endif /* ifdef R_FDL_LIB_V1_COMPATIBILITY */

/*********************************************************************************************************************/
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                         /* PRQA S 5087 */

/*********************************************************************************************************************/

