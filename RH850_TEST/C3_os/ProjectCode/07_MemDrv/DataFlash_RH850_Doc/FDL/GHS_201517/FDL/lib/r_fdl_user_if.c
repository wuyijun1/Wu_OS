#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_user_if.c $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.11 $
 * Mod. Revision : $Revision: 1.52 $
 * Mod. Date     : $Date: 2016/06/01 12:39:21JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL user interface functions
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
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0306)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 14.1 (QAC message 1503)
 * Reason:       This function is not used within the library, it is only used by the user
 *               application.
 * Verification: This function is part of the library API and therefore essential on the one hand.
 *               On the other hand the QAC warning is correct, because this function is never
 *               called within the library. To solve this dilemma it is necessary and suitable
 *               to disable the message.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 19.1 (QAC message 5087)
 * Reason:       The section mapping concept (Mapping code, constants and data to specific linker sections) bases on
 *               a central include file containing all section mapping  defines and pragmas. This need to be included
 *               multiple times within the code. The file itself only contains those defines and pragmas.
 * Verification: This is the standard concept defined for AUTOSAR implementations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 9.1 (QAC message 2962)
 * Reason:       Apparent using value of an uninitialized variable fcuCmd, used to convert API commands
 *              (see r_fdl_command_t enum) into commands passed to the hardware.
 * Verification: The variable fcuCmd is set properly for all commands except R_FDL_CMD_READ, for which is not used
 *               at all.
 *********************************************************************************************************************/

#define R_FDL_USERIF_C

/*********************************************************************************************************************
 * FDL header files include
 *********************************************************************************************************************/
#include "r_fdl_global.h"

/*********************************************************************************************************************
 * Module internal function prototypes
 *********************************************************************************************************************/
R_FDL_STATIC void           R_FDL_UFct_EndCurrentOperation             (r_fdl_status_t ret_enu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_UFct_FlashOpStart                    (r_fdl_request_t * request_pstr,
                                                                        r_fdl_status_t * tmpStat_penu,
                                                                        r_fdl_flag_t isCalledFromExecute_enu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_BusyAndSuspendPossible       (void);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_ChkResume                    (r_fdl_status_t * tmpStat_penu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_ReactOnFatalErrors           (r_fdl_status_t * tmpStat_penu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_StatusCheckAndSuspendOnReady (r_fdl_status_t * tmpStat_penu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_MultiOperation               (r_fdl_status_t * tmpStat_penu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_UFct_StateNotStandBy                 (void);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_OperationStates              (r_fdl_status_t * tmpStat_penu);
R_FDL_STATIC r_fdl_flag_t   R_FDL_Handler_CancelReq                    (r_fdl_status_t * tmpStat_penu);

/*********************************************************************************************************************
 * Global variables
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   QAC message 2022
 * Reason:       Basically, global variables should be initialized. However, as the library is used for multiple
 *               compilers and not all compilers support explicit initialization for variables in not standard
 *               sections, this variable is initialized in the library initialization function rather than by the
 *               compiler.
 * Verification: test case
 *********************************************************************************************************************/
/* Note:
 * The define "R_FDL_COV_ENABLED" is a specific define for library testing purpose only.
 * The user application shall not set this define */
#if (!defined R_FDL_COV_ENABLED)
    #define R_FDL_START_SEC_VAR
    #include "r_fdl_mem_map.h"                                                                      /* PRQA S 5087 */

    R_FDL_NOINIT r_fdl_data_t g_fdl_str;                                                            /* PRQA S 2022 */

    #define R_FDL_STOP_SEC_VAR
    #include "r_fdl_mem_map.h"                                                                      /* PRQA S 5087 */

    #ifndef R_FDL_EXE_INIT_CODE_ON_STACK
        #define R_FDL_START_SEC_CODERAM
        #include "r_fdl_mem_map.h"                                                                  /* PRQA S 5087 */

        /* Code size calculation described in r_fdl_global.h */
        R_FDL_NOINIT uint16_t g_fdl_ramCodeBuf_au16[R_FDL_RAM_CODE_SIZE_HW];                        /* PRQA S 2022 */

        #define R_FDL_STOP_SEC_CODERAM
        #include "r_fdl_mem_map.h"                                                                  /* PRQA S 5087 */
    #endif

#else /* #if (!defined R_FDL_COV_ENABLED) */
    R_FDL_NOINIT r_fdl_data_t g_fdl_str;                                                            /* PRQA S 2022 */
    #ifndef R_FDL_EXE_INIT_CODE_ON_STACK
        R_FDL_NOINIT uint16_t g_fdl_ramCodeBuf_au16[R_FDL_RAM_CODE_SIZE_HW];                        /* PRQA S 2022 */
    #endif
    
#endif /* #else #if (!defined R_FDL_COV_ENABLED) */


/*********************************************************************************************************************
 * Function name:  R_FDL_InitVariables
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Init function.
 * This function initializes the FDL internal variables and does the FDL configuration parameter checks.
 * The following parameter checks are done:
 * - Descriptor variable is defined
 * - FDL pool is defined
 * - EEL pool is within FDL pool
 *
 * In error case the library is set to not initialized (R_FDL_ISTAT_NOINIT)
 *
 * @param[in]  descriptor_pstr - Pointer to the FDL descriptor structure
 * @return     Initialization status when returned from function call:
 *             - R_FDL_OK                - Initialization was successful
 *             - R_FDL_ERR_CONFIGURATION - FDL configuration parameter error
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 8.8 (QAC message 3408)
 * Reason:       Library is delivered as source code and as a precompiled object.
 *               The file r_fdl_user_if_init.c is not included on generation of the precompiled object.
 *               It is delivered as a separate file and cannot include any other header files, except the
 *               defined interface header files. The function is a library internal function and its declaration
 *               is not part of the interface header files.
 * Verification: -
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_InitVariables (const r_fdl_descriptor_t * descriptor_pstr)                     /* PRQA S 3408 */
{
    r_fdl_status_t ret;
    uint32_t       fdAdd;
    uint32_t       i;
    uint16_t       blkEnd;

    /* Initially clear the complete r_fdl_data structure */
    fdAdd = (uint32_t)(&g_fdl_str);                                                                 /* PRQA S 0306 */
    for (i = 0; i < sizeof (g_fdl_str); i++)
    {
        R_FDL_IFct_WriteMemoryU08 (fdAdd, 0u);
        fdAdd++;
    }

    g_fdl_str.iStat_enu = R_FDL_ISTAT_NOINIT;
    ret = R_FDL_OK;

    /*  We have a descriptor at all */
    if (R_FDL_DESCRIPTOR_POINTER_UNDEFINED != descriptor_pstr)
    {
        /* Set pointer to FDL static configuration */
        g_fdl_str.RTCfg_pstr = descriptor_pstr;

        /* Parameter independent initializations */
        (g_fdl_str.reqSuspend_pstr)    = R_FDL_REQUEST_POINTER_UNDEFINED;
        (g_fdl_str.reqInt_pstr)        = R_FDL_REQUEST_POINTER_UNDEFINED;

        /* Reset misc flags */
        g_fdl_str.cancelRequest_enu    = R_FDL_FALSE;
        g_fdl_str.spdSpdRequest_enu    = R_FDL_FALSE;
        g_fdl_str.spdResRequest_enu    = R_FDL_FALSE;
        g_fdl_str.flashMode_u16        = R_FCU_MODE_USER;
        g_fdl_str.opStatus_enu         = R_FDL_OP_IDLE;

        /* FDL Pool is available */
        if (0u != g_fdl_str.RTCfg_pstr->fdlPoolSize_u16)
        {
            blkEnd =   (g_fdl_str.RTCfg_pstr->eelPoolStart_u16)
                     + (g_fdl_str.RTCfg_pstr->eelPoolSize_u16);
            
            /* EEL Pool fits into FDL pool */
            if (blkEnd >= (g_fdl_str.RTCfg_pstr->fdlPoolSize_u16 + 1u) )
            {
                ret = R_FDL_ERR_CONFIGURATION;
            }
        }
        else
        {
            ret = R_FDL_ERR_CONFIGURATION;
        }
    }

    /*  We don't have a descriptor at all */
    else
    {
        ret = R_FDL_ERR_CONFIGURATION;
    }

    /* Only if no error occurred, the library status is set to initialized */
    if (R_FDL_OK == ret)
    {
        g_fdl_str.iStat_enu = R_FDL_ISTAT_INIT;
    }

    return (ret);
} /* R_FDL_InitVariables */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Execute
 *********************************************************************************************************************/
/**
 * User interface function:
 * This function initiates a Flash operation (Erase/Write/Read/Prepare Environment).
 * After initiation, the function R_FDL_Handler need to be called regularly to finish the operation.
 *
 * @param[in, out] request_pstr   Pointer to the operation request structure.
 *                                - Structure input elements: \n
 *                                  command_enu, bufAddr_u32, idx_u32, cnt_u16, accessType_enu
 *                                - Structure output element: \n
 *                                  status_enu
 * @return      ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void  R_FDL_Execute (r_fdl_request_t * request_pstr)                                                /* PRQA S 1503 */
{
    r_fdl_status_t reqErr;

    reqErr = R_FDL_ERR_REJECTED;

    /* Request structure pointer parameter is not "0x00" */
    if (R_FDL_REQUEST_POINTER_UNDEFINED != request_pstr)
    {

        /* library internal request structure pointer is "0x00" (No operation ongoing) */
        if (R_FDL_REQUEST_POINTER_UNDEFINED == g_fdl_str.reqInt_pstr)
        {

            /* Library is initialized */
            if (R_FDL_ISTAT_INIT == g_fdl_str.iStat_enu)
            {

                /* Only Prepare command is allowed when teh library is in initialized status */
                if (R_FDL_CMD_PREPARE_ENV == request_pstr->command_enu)
                {
                    reqErr = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
                    
                    /* No invalid FACI programming mode detected */
                    if (R_FDL_OK == reqErr)
                    {
                        reqErr = R_FDL_BUSY;
                        g_fdl_str.opStatus_enu = R_FDL_OP_EXECUTE_SYNC_ON;
                    }
                }
            }
            
            /* Library is prepared and not busy and no cancel request */
            else if ( (R_FDL_ISTAT_NORMALOP  == g_fdl_str.iStat_enu) ||
                      ( (R_FDL_ISTAT_SUSPENDED == g_fdl_str.iStat_enu) &&
                        (R_FDL_FALSE == g_fdl_str.cancelRequest_enu) ) )
            {
                /* Command selection */
                switch (request_pstr->command_enu)
                {
                    case R_FDL_CMD_BLANKCHECK:
                    {
                        (void)R_FDL_UFct_FlashOpStart (request_pstr, &reqErr, R_FDL_TRUE);
                        break;
                    }

        #if (defined ENABLE_CMD_WRITE16B)
                    case R_FDL_CMD_WRITE16B:
        #endif
                    case R_FDL_CMD_ERASE:
                    case R_FDL_CMD_WRITE:
                    {
                        /* Check FACI suspend flags points out that the command can be started */
                        if (R_FDL_TRUE == R_FDL_FCUFct_ChkStartable (request_pstr->command_enu) )
                        {
                            (void)R_FDL_UFct_FlashOpStart (request_pstr, &reqErr, R_FDL_TRUE);
                        }
                        break;
                    }

                    case R_FDL_CMD_READ:
                    {
                        (void)R_FDL_UFct_FlashOpStart (request_pstr, &reqErr, R_FDL_TRUE);
                        break;
                    }

                    case R_FDL_CMD_PREPARE_ENV:
                    {
                        reqErr = R_FDL_ERR_REJECTED;
                        break;
                    }

                    default:
                    {
                        reqErr = R_FDL_ERR_COMMAND;
                        break;
                    }
                } /* switch */
            }
            else
            {
                /* Nothing to do, added to fix QAC warning message 2004 */
            }
        }

        /* Command execution started */
        if (R_FDL_BUSY == reqErr)
        {
            /* set internal pointer to the request structure, required by the handler */
            g_fdl_str.reqInt_pstr = request_pstr;

        }
        
        /* Command execution rejected */
        else
        {
            /* At operations end (In error case or if the operation requires no handler calls), reset
               the access type */
            request_pstr->accessType_enu = R_FDL_ACCESS_NONE;

            g_fdl_str.opStatus_enu = R_FDL_OP_IDLE;
        }

        /* Set the return state */
        request_pstr->status_enu = reqErr;
    }

    return;
} /* R_FDL_Execute */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_CancelReq
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 * This function cancels an ongoing Flash operation if:
 * - cancel request flag set
 * - switch mode is performed
 *
 * @param[out] tmpStat_penu - Status return value. Is modified, if an operation is cancelled.
 * @return     handler function flow may continue after this function or handler need to exit
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_CancelReq (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t    cont;
    r_fdl_status_t  res;
    
    cont = R_FDL_TRUE;

    /* Only do something is cancel request flag is not already set */
    if (R_FDL_TRUE == g_fdl_str.cancelRequest_enu)
    {
        if (R_FDL_OK == R_FDL_FCUFct_SwitchMode_Check() )
        {
            /* FACI in programming mode */
            if (R_FCU_MODE_PE == g_fdl_str.flashMode_u16)
            {
                res = R_FDL_FCUFct_ForcedStop();
                
                /* Timeout error in forced stop - internal error 
                   Note: If FACI remains busy, it might happen that a mode switch will not be performed. 
                         Thus, don't try to do it but finish with internal error immediately.
                         This means that DF is possibly not readable */
                if (R_FDL_OK != res)
                {
                    (*tmpStat_penu)         = R_FDL_ERR_INTERNAL;
                    cont                    = R_FDL_FALSE;
                }
                
                /* After forced stop, switch to user mode */
                else
                {
                    (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);
                    g_fdl_str.opResult_enu  = R_FDL_CANCELLED;
                    (*tmpStat_penu)         = R_FDL_BUSY;
                    g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                }

            }
            
            /* FACI is idle */
            else
            {
                (*tmpStat_penu) = R_FDL_CANCELLED;
                cont = R_FDL_FALSE;
            }

            g_fdl_str.cancelRequest_enu = R_FDL_FALSE;
            g_fdl_str.spdSpdRequest_enu = R_FDL_FALSE;
            g_fdl_str.spdResRequest_enu = R_FDL_FALSE;
            g_fdl_str.iStat_enu         = R_FDL_ISTAT_NORMALOP;

            /* In case of suspended Flash operation, also the suspended operation's request 
               structure need to be updated */
            if (R_FDL_REQUEST_POINTER_UNDEFINED != g_fdl_str.reqSuspend_pstr)
            {
                g_fdl_str.reqSuspend_pstr->status_enu = R_FDL_CANCELLED;
                g_fdl_str.reqSuspend_pstr             = R_FDL_REQUEST_POINTER_UNDEFINED;
            }
        }
        else
        {
            cont = R_FDL_FALSE;
        }
    }

    return (cont);
} /* R_FDL_Handler_CancelReq */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_BusyAndSuspendPossible
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 * This function suspends an ongoing Flash operation if:
 * - suspend request flag set
 * - function is suspendable
 *
 * @param[in,out]   -
 * @return          Handler function flow may continue afte this function or handler need to exit
 *                  - R_FDL_TRUE  - continue handler
 *                  - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_BusyAndSuspendPossible (void)
{
    r_fdl_flag_t cont;

    cont = R_FDL_TRUE;

    /* Handle a suspend request */
    if (R_FDL_TRUE == g_fdl_str.spdSpdRequest_enu)
    {

        /* FACI allows suspending */
        if (R_FDL_TRUE == R_FDL_FCUFct_ChkSuspendable() )
        {
            /* Must be called before changing g_fdl_str.iStat_enu because
               g_fdl_str.iStat_enu is checked in R_FDL_Standby! */
            R_FDL_FCUFct_Suspend();

            g_fdl_str.spdSpdRequest_enu = R_FDL_FALSE;
            g_fdl_str.iStat_enu         = R_FDL_ISTAT_SUSPEND_PR;
            cont                        = R_FDL_FALSE;
        }
    }

    return (cont);
} /* R_FDL_Handler_BusyAndSuspendPossible */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_ChkResume
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 * This function resumes a suspended Flash operation if:
 * - resume request flag set (can only be set if a function was suspended)
 * - No Flash operation is ongoing
 *
 * @param[out] tmpStat_penu - Status return value. Is modified, if an operation is resumed.
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_ChkResume (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t   cont;
    r_fdl_status_t res;

    cont = R_FDL_FALSE;

    /* Resume request flag set and no operation ongoing */
    if ( (R_FDL_REQUEST_POINTER_UNDEFINED == g_fdl_str.reqInt_pstr)
         && (R_FDL_TRUE == g_fdl_str.spdResRequest_enu) )
    {
        g_fdl_str.spdResRequest_enu = R_FDL_FALSE;

        /* We need to resume a Flash operation */
        if (R_FDL_BUSY == g_fdl_str.spdResStatus_enu)
        {
            res = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
            /* protection error during mode switching */
            if (R_FDL_OK != res)
            {
                g_fdl_str.reqSuspend_pstr->status_enu = res;
            }
            
            /* Continue resuming */
            else
            {
                g_fdl_str.opStatus_enu  = R_FDL_OP_RESUME_SYNC_ON;
                cont                    = R_FDL_TRUE;
                g_fdl_str.iStat_enu     = R_FDL_ISTAT_NORMALOP;
            }
        }
        
        /* We need to resume to command execution end or to start of a new Flash operation */
        else
        {

            /* In order to support continuing Multi-Operations, we need to patch the
               R_FDL_OK to R_FDL_BUSY. Errors result in operation end (Write, Erase, BC errors) */
            if ( (R_FDL_OK == g_fdl_str.spdResStatus_enu)
                 && (g_fdl_str.spdMulOp_str.flashAdd_u32 < g_fdl_str.spdMulOp_str.flashAddEnd_u32) )
            {
                res = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
                /* protection error during mode switching */
                if (R_FDL_OK != res)
                {
                    g_fdl_str.reqSuspend_pstr->status_enu = res;
                }
                
                /* Continue with next resume step */
                else
                {
                    g_fdl_str.opStatus_enu            = R_FDL_OP_RESUME_MULTI_SYNC_ON;
                    g_fdl_str.spdResStatus_enu        = R_FDL_BUSY;
                    cont                              = R_FDL_TRUE;
                    g_fdl_str.iStat_enu               = R_FDL_ISTAT_NORMALOP;
                }
            }
            
            /* Operation ends */
            else
            {
                g_fdl_str.iStat_enu = R_FDL_ISTAT_NORMALOP;
                (*tmpStat_penu) = g_fdl_str.spdResStatus_enu;
            }

        }

        /* on successful resume, restore the FDL operation data */
        if (R_FDL_ISTAT_SUSPENDED != g_fdl_str.iStat_enu)
        {
            /* Restore variables for resume */
            g_fdl_str.reqInt_pstr               = g_fdl_str.reqSuspend_pstr;
            /* if operation finished, the result will be set in the end of the handler function */
            g_fdl_str.reqInt_pstr->status_enu   = R_FDL_BUSY;
            g_fdl_str.reqSuspend_pstr           = R_FDL_REQUEST_POINTER_UNDEFINED;
            g_fdl_str.mulOp_str.flashAdd_u32    = g_fdl_str.spdMulOp_str.flashAdd_u32;
            g_fdl_str.mulOp_str.bufAdd_u32      = g_fdl_str.spdMulOp_str.bufAdd_u32;
            g_fdl_str.mulOp_str.flashAddEnd_u32 = g_fdl_str.spdMulOp_str.flashAddEnd_u32;
            g_fdl_str.mulOp_str.accessType_enu  = g_fdl_str.spdMulOp_str.accessType_enu;
        }
    }
    else
    {
        cont = R_FDL_TRUE;
    }

    return (cont);
} /* R_FDL_Handler_ChkResume */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_ReactOnFatalErrors
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 * Read out Flash operation error status after operation end and react on fatal errors.
 *
 * @param[out] tmpStat_penu - Status return value. Is set to internal error in case of detection
 *                            of a fatal HW error
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_ReactOnFatalErrors (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t   cont;
    r_fdl_status_t stat;

    cont = R_FDL_TRUE;

    /* Check for fatal error (protection  or internal error) */
    stat = R_FDL_FCUFct_CheckFatalError();

    /* Error case */
    if (R_FDL_OK != stat)
    {
        R_FDL_FCUFct_ClearStatus();
        (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);

        /* Switch mode function passed */
        if (R_FDL_BUSY == R_FDL_FCUFct_SwitchMode_Check() )
        {
            g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
            /* save status, will be returned on mode switch confirmation */
            g_fdl_str.opResult_enu = stat;
            (*tmpStat_penu)        = R_FDL_BUSY;
        }
        else
        {
            (*tmpStat_penu) = stat;
        }

        cont = R_FDL_FALSE;
    }

    return (cont);
} /* R_FDL_Handler_ReactOnFatalErrors */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_StatusCheckAndSuspendOnReady
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 * Get and judge Flash operation result (not fatal errors, just operation results) and
 * do further suspend processing in case of pending suspend request or already suspended
 * Flash operation.
 *
 * @param[out] tmpStat_penu - Status return value. Is set to operation result or to suspended in
 *                            case of suspend processing.
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_StatusCheckAndSuspendOnReady (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t   cont;
    r_fdl_status_t res;

    cont = R_FDL_TRUE;

    /* Get operation status after operation end and reset the hardware status */
    (*tmpStat_penu) = R_FDL_FCUFct_GetStat();
    R_FDL_FCUFct_ClearStatus();

    /* Suspend handling
       - suspend possible, part 2 (Flash operation is suspended now) -or-
       - suspend impossible (operation finished but suspend request still active) */
    if (R_FDL_TRUE == g_fdl_str.spdSpdRequest_enu)
    {
        /* suspend was impossible --> handle it now after operation completion */
        g_fdl_str.spdSpdRequest_enu = R_FDL_FALSE;
        g_fdl_str.iStat_enu = R_FDL_ISTAT_SUSPEND_PR;
    }
    
    if (R_FDL_ISTAT_SUSPEND_PR == g_fdl_str.iStat_enu)
    {
        g_fdl_str.spdResStatus_enu = (*tmpStat_penu);

        (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);
        res = R_FDL_FCUFct_SwitchMode_Check();

        /* Mode already switched */
        if (R_FDL_OK == res)
        {
            (*tmpStat_penu) = R_FDL_SUSPENDED;

            /* Backup variables for resume */
            g_fdl_str.reqSuspend_pstr = g_fdl_str.reqInt_pstr;

            g_fdl_str.iStat_enu = R_FDL_ISTAT_SUSPENDED;
        }
        
        /* Wait for mode switch confirmation */
        else
        {
            (*tmpStat_penu) = R_FDL_BUSY;
            
            g_fdl_str.opStatus_enu = R_FDL_OP_SUSPEND_SYNC_OFF;
        }

        g_fdl_str.spdMulOp_str.flashAdd_u32    = g_fdl_str.mulOp_str.flashAdd_u32;
        g_fdl_str.spdMulOp_str.bufAdd_u32      = g_fdl_str.mulOp_str.bufAdd_u32;
        g_fdl_str.spdMulOp_str.flashAddEnd_u32 = g_fdl_str.mulOp_str.flashAddEnd_u32;
        g_fdl_str.spdMulOp_str.accessType_enu  = g_fdl_str.mulOp_str.accessType_enu;

        cont = R_FDL_FALSE;
    }

    return (cont);
} /* R_FDL_Handler_StatusCheckAndSuspendOnReady */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_MultiOperation
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 *
 * In case of multi-operations (erase multiple blocks or write multiple half words), after end
 * of a single Flash erase/write Flash operation, the next operation is started.
 *
 * @param[in, out] tmpStat_penu - current operation status. Used to judge previous operation result
 *                                and is updated in case of multi-operation requiring start of new
 *                                Flash operation
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_MultiOperation (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t    cont;
    uint32_t        cnt;
    r_fdl_command_t cmd;

    cont = R_FDL_TRUE;
    cmd  = g_fdl_str.reqInt_pstr->command_enu;

    /* Check if more data to handle:
       - erase, write, blank check operation
       - internal status = OK
       - more data to erase/write */
    if ( (R_FDL_OK == (*tmpStat_penu) )
         && (g_fdl_str.mulOp_str.flashAdd_u32 < g_fdl_str.mulOp_str.flashAddEnd_u32) )
    {
        /* Write command starts a new FACI write operation */
#if (defined ENABLE_CMD_WRITE16B)
        if ( (R_FDL_CMD_WRITE == cmd) || (R_FDL_CMD_WRITE16B == cmd) )                              /* PRQA S 0505 */
#else
        if (R_FDL_CMD_WRITE == cmd)
#endif
        {
#if (defined ENABLE_CMD_WRITE16B)
            if (R_FDL_CMD_WRITE == cmd)
            {
                cnt = R_WRITE_SIZE;
            }
            else
            {
                cnt = R_WRITE_SIZE_16B;
            }
#else
            cnt = R_WRITE_SIZE;
#endif

            (*tmpStat_penu) = R_FDL_FCUFct_StartWriteOperation (g_fdl_str.mulOp_str.bufAdd_u32,
                                                                g_fdl_str.mulOp_str.flashAdd_u32,
                                                                cnt,
                                                                g_fdl_str.mulOp_str.accessType_enu);

            g_fdl_str.mulOp_str.flashAdd_u32 += cnt;
            g_fdl_str.mulOp_str.bufAdd_u32   += cnt;
        }
        
        /* Erase command starts a new FACI erase operation */
        else if (R_FDL_CMD_ERASE == cmd)                                                            /* PRQA S 0505 */
        {
            (*tmpStat_penu) = R_FDL_FCUFct_StartBCEraseOperation (g_fdl_str.mulOp_str.flashAdd_u32,
                                                                  (g_fdl_str.mulOp_str.flashAdd_u32 + R_BLOCK_SIZE) - 1u,
                                                                  R_FCU_CMD_ERASE,
                                                                  g_fdl_str.mulOp_str.accessType_enu);

            g_fdl_str.mulOp_str.flashAdd_u32 += R_BLOCK_SIZE;
        }
        
        /* Blank Check command (exceeding 4kB boundary) starts a new FACI blank check operation */
        else
        {
            cnt = ( (g_fdl_str.mulOp_str.flashAddEnd_u32 + 1uL) - g_fdl_str.mulOp_str.flashAdd_u32);
            /* Limit count to max */
            R_FDL_IFct_CalcFOpUnitCnt_BC (&cnt, g_fdl_str.mulOp_str.flashAdd_u32);

            (*tmpStat_penu) = R_FDL_FCUFct_StartBCEraseOperation (g_fdl_str.mulOp_str.flashAdd_u32,
                                                                  ( (g_fdl_str.mulOp_str.flashAdd_u32 + cnt) - 1u),
                                                                  R_FCU_CMD_BLANKCHECK,
                                                                  g_fdl_str.mulOp_str.accessType_enu);

            g_fdl_str.mulOp_str.flashAdd_u32 += cnt;
        }

        /* In command execution end (OK or error) */
        if (R_FDL_BUSY != (*tmpStat_penu) )
        {
            (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);
        
            /* Mode already switched */
            if (R_FDL_BUSY == R_FDL_FCUFct_SwitchMode_Check() )
            {
                g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                /* save status, will be returned on mode switch confirmation */
                g_fdl_str.opResult_enu = (*tmpStat_penu);
                (*tmpStat_penu) = R_FDL_BUSY;
            }
        }

        cont = R_FDL_FALSE;
    }

    return (cont);
} /* R_FDL_Handler_MultiOperation */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler_OperationStates
 *********************************************************************************************************************/
/**
 * Part of the R_FDL_Handler function.
 *
 * This function checks if switch mode is performed.
 * If yes, it executes different operations depending on internal operation status.
 * Prepare environment is performed here also.
 * If not, do nothing
 *
 * @param[in, out] tmpStat_penu - current operation status. Used to judge previous operation result
 *                                and is updated in case of start of new Flash operation
 *
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_Handler_OperationStates (r_fdl_status_t * tmpStat_penu)
{
    r_fdl_flag_t cont;
    r_fdl_status_t res;
    
    cont = R_FDL_TRUE;

    if ( (R_FDL_OP_IDLE != g_fdl_str.opStatus_enu) &&
         (R_FDL_OP_BUSY != g_fdl_str.opStatus_enu) )
    {
        (*tmpStat_penu) = R_FDL_FCUFct_SwitchMode_Check();

        /* Mode switch passed */
        if (R_FDL_OK == (*tmpStat_penu) )
        {
            
            /* Select current operation status */
            switch (g_fdl_str.opStatus_enu)
            {
                /* Next step after mode switch confirmation for normal operations and prepare */
                case R_FDL_OP_EXECUTE_SYNC_ON:
                {
                    if (R_FDL_CMD_PREPARE_ENV == g_fdl_str.reqInt_pstr->command_enu)
                    {
                        res = R_FDL_FCUFct_ForcedStop();

                        (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);

                        /* No timeout during forced stop processing */
                        if (R_FDL_OK == res)
                        {
                            g_fdl_str.opStatus_enu = R_FDL_OP_PREPARE_START;
                        }
                        else
                        {
                            g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                            g_fdl_str.opResult_enu = R_FDL_ERR_INTERNAL;
                        }

                        cont                   = R_FDL_FALSE;
                        (*tmpStat_penu)        = R_FDL_BUSY;
                    }
                    else
                    {
                        cont = R_FDL_UFct_FlashOpStart (g_fdl_str.reqInt_pstr, tmpStat_penu, R_FDL_FALSE);
                    }
                    break;
                }

                /* Prepare operation 1st state */
                case R_FDL_OP_PREPARE_START:
                {
                    /* Disable FCU error interrupt which will occur always during FCU initialization from power up */
                    R_FDL_FCUFct_Switch_FAEINT (R_FDL_FALSE);
                    
                    /* Initialize the FCU code RAM */
                    (*tmpStat_penu) = R_FDL_FCUFct_InitRAM();
                    
                    /* No timeout error during RAM initialization */
                    if (R_FDL_OK == (*tmpStat_penu) )
                    {
                        (*tmpStat_penu) = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
                        
                        /* No protection error during mode switch */
                        if (R_FDL_OK == (*tmpStat_penu) )
                        {
                            (*tmpStat_penu)        = R_FDL_BUSY;
                            g_fdl_str.opStatus_enu = R_FDL_OP_PREPARE_RST_FCU;
                        }
                    }
                    
                    /* In error case we need to activate the FAEINT again as the operation will immediately finish */
                    if (R_FDL_BUSY != (*tmpStat_penu) )
                    {
                        R_FDL_FCUFct_Switch_FAEINT (R_FDL_TRUE);
                    }

                    cont = R_FDL_FALSE;
                    break;
                }

                /* Prepare operation 2nd state */
                case R_FDL_OP_PREPARE_RST_FCU:
                {
                    /* Reset FCU again to clear any possible ECC errors */
                    res = R_FDL_FCUFct_ForcedStop();
                    R_FDL_FCUFct_ClearStatus();

                    (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);
                    
                    /* Enable FCU error interrupt again, now we expect no more ECC error */
                    R_FDL_FCUFct_Switch_FAEINT (R_FDL_TRUE);
                    
                    /* No timeout during forced stop processing */
                    if (R_FDL_OK == res)
                    {
                        g_fdl_str.opStatus_enu = R_FDL_OP_PREPARE_END;
                    }
                    else
                    {
                        g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                        g_fdl_str.opResult_enu = R_FDL_ERR_INTERNAL;
                    }

                    (*tmpStat_penu)        = R_FDL_BUSY;
                    cont                   = R_FDL_FALSE;
                    break;
                }

                /* Prepare operation 3rd state */
                case R_FDL_OP_PREPARE_END:
                {
                    (*tmpStat_penu) = R_FDL_FCUFct_VerifyChecksum();

                    /* Checksum check passed */
                    if (R_FDL_BUSY == (*tmpStat_penu) )
                    {
                        (*tmpStat_penu) = R_FDL_FCUFct_GetDFSize (&(g_fdl_str.dfSize_u32) );
                        #ifdef R_FDL_F1L_PATCH_DF_OVERSIZE
                            g_fdl_str.dfSize_u32 *= 2uL;
                        #endif

                        if (R_FDL_OK == (*tmpStat_penu) )
                        {
                            /* FDL pool size does not exceed Data FLash size */
                            if (g_fdl_str.RTCfg_pstr->fdlPoolSize_u16 <= (g_fdl_str.dfSize_u32 >> R_BLOCK_SIZE_2N) )
                            {
                                /* Configure the FCU frequency */
                                (*tmpStat_penu) = R_FDL_FCUFct_SetFrequency();
                            }
                            else
                            {
                                (*tmpStat_penu) = R_FDL_ERR_CONFIGURATION;
                            }
                        }
                    }

                    if (R_FDL_OK == (*tmpStat_penu) )
                    {
                        g_fdl_str.iStat_enu = R_FDL_ISTAT_NORMALOP;
                    }

                    cont = R_FDL_FALSE;
                    break;
                }

                /* Resume command execution (FACI resume) */
                case R_FDL_OP_RESUME_SYNC_ON:
                {
                    R_FDL_FCUFct_Resume();
                    g_fdl_str.opStatus_enu = R_FDL_OP_BUSY;
                    (*tmpStat_penu)        = R_FDL_BUSY;
                    break;
                }

                /* Resume command execution (Start new operation) */
                case R_FDL_OP_RESUME_MULTI_SYNC_ON:
                {
                    g_fdl_str.opStatus_enu = R_FDL_OP_BUSY;
                    (*tmpStat_penu)        = R_FDL_BUSY;
                    break;
                }

                /* Command execution end */
                case R_FDL_OP_END_SYNC_OFF:
                {
                    g_fdl_str.opStatus_enu = R_FDL_OP_IDLE;
                    (*tmpStat_penu)        = g_fdl_str.opResult_enu;
                    cont                   = R_FDL_FALSE;
                    break;
                }

                /* suspend processing end */
                case R_FDL_OP_SUSPEND_SYNC_OFF:
                {
                    (*tmpStat_penu)                        = R_FDL_SUSPENDED;
                    /* Backup variables for resume */
                    g_fdl_str.reqSuspend_pstr              = g_fdl_str.reqInt_pstr;
                    g_fdl_str.iStat_enu                    = R_FDL_ISTAT_SUSPENDED;
                    cont                                   = R_FDL_FALSE;
                    break;
                }

                default:
                {
                    /* Nothing to do */
                    break;
                }
            } /* switch */
        }
        else
        {
            cont = R_FDL_FALSE;
        }
    }
    return (cont);
} /* R_FDL_Handler_OperationStates */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Handler
 *********************************************************************************************************************/
/**
 * User interface function:
 * This function forwards an initiated Flash operation until it is finished. At operation end the
 * result is set in the request structure.
 * After initiation by R_FDL_Execute, the function R_FDL_Handler need to be called regularly to finish
 * the operation.

 * @param[in,out]  -
 * @return         ---
 *
 * The function returns the operation result in the status variable, passed to
 * the R_FDL_Execute variable (request.status_enu)
 */
/*********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 1.2 (QAC message 0505)
 * Reason:       QAC claims referencing a possibly undefined pointer.
 * Verification: Reviewed, that this is not possible. The pointer is always defined
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_Handler (void)                                                                           /* PRQA S 1503 */
{
    r_fdl_flag_t   contHdrFct;
    r_fdl_status_t tmpStatus;
    r_fdl_status_t res;

    tmpStatus = R_FDL_BUSY;

    /* Check if the handler has something to do, block on not initialized library and on StandBy processing */
    if ( (R_FDL_TRUE == R_FDL_UFct_StateNotStandBy() ) &&
         ( (R_FDL_REQUEST_POINTER_UNDEFINED != g_fdl_str.reqInt_pstr) ||
         (R_FDL_TRUE == g_fdl_str.spdResRequest_enu) ||
           (R_FDL_TRUE == g_fdl_str.cancelRequest_enu) ) )
    {
        /* Cancel Request management */
        contHdrFct = R_FDL_Handler_CancelReq (&tmpStatus);

        /* continue handler execution: Suspend handling (suspend possible, part 1)*/
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_BusyAndSuspendPossible();
        }

        /* continue handler execution: Resume handling */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_ChkResume (&tmpStatus);
        }

        /* continue handler execution: command processing execution */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_OperationStates (&tmpStatus);
        }

        /* continue handler execution: check if the FCU is busy */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_FCUFct_ChkReady();
        }

        /* continue handler execution: Fatal error evaluation */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_ReactOnFatalErrors (&tmpStatus);
        }

        /* continue handler execution: judge operation status and do suspend handling part 2 */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_StatusCheckAndSuspendOnReady (&tmpStatus);
        }

        /* continue handler execution: multi operation (Write/Erase) state machine */
        if (R_FDL_TRUE == contHdrFct)
        {
            contHdrFct = R_FDL_Handler_MultiOperation (&tmpStatus);
        }

        /* continue handler execution: normal operation end */
        if (R_FDL_TRUE == contHdrFct)
        {
            (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);
            res = R_FDL_FCUFct_SwitchMode_Check();
            if (R_FDL_BUSY == res)
            {
                g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                /* save status, will be returned on mode switch confirmation */
                g_fdl_str.opResult_enu = tmpStatus;
                tmpStatus = R_FDL_BUSY;
            }
        }

        /* Operation end, return status to user */
        if (R_FDL_BUSY != tmpStatus)
        {
            R_FDL_UFct_EndCurrentOperation (tmpStatus);
        }

        #ifdef PATCH_TO_SIMULATE_ERRORS
            tstData_str.simCntHdr_u32++;
        #endif

    }
} /* R_FDL_Handler */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_GetVersionString
 *********************************************************************************************************************/
/**
 * User interface function:
 * Returns the pointer to the library version string, stores in the library code section.
 *
 * @param[in,out]   -
 * @return          Pointer to the version string in Flash
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_CONST
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
const uint8_t *R_FDL_GetVersionString (void)                                                        /* PRQA S 1503 */
{
    static const uint8_t r_fdl_vStr[] = R_FDL_VERSION_STRING;

    return (&r_fdl_vStr[0]);
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
#define R_FDL_STOP_SEC_CONST
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

/*********************************************************************************************************************
 * Function name:  R_FDL_SuspendRequest
 *********************************************************************************************************************/
/**
 * User interface function:
 * Sets the suspend request flag for the write or erase operation
 *
 * Note:
 * The operation is not immediately suspended. Suspend handling is controlled by R_FDL_Handler.
 * The suspend status is returned by the status variable of the request structure (Set in
 * R_FDL_Handler).
 *
 * Suspend request handling:
 * - Reject if
 *     - we have no active Flash operation
 *     - we have already a Flash operation suspended
 *     - we have a cancel request
 * - Reset resume request if set (then we have a not yet handled resume request)
 * - Set suspend request if we have an operation ongoing and we are not already in suspend
 *   processing
 *
 * @param[in,out]   -
 * @return          result of the suspend request
 *                  - R_FDL_OK           - Request accepted
 *                  - R_FDL_ERR_REJECTED - Request rejected
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_SuspendRequest (void)                                                          /* PRQA S 1503 */
{
    r_fdl_status_t ret;

    ret = R_FDL_ERR_REJECTED;

    /* Block on:
          - not initialized library
          - StandBy processing       */
    if (R_FDL_TRUE == R_FDL_UFct_StateNotStandBy() )
    {
    
        /* Set the request flag only if we are busy and not in suspend state or suspend processing */
        if ( (R_FDL_REQUEST_POINTER_UNDEFINED != g_fdl_str.reqInt_pstr)
            && (R_FDL_REQUEST_POINTER_UNDEFINED == g_fdl_str.reqSuspend_pstr)
            && (R_FDL_ISTAT_NORMALOP == g_fdl_str.iStat_enu)
             && (R_FDL_FALSE == g_fdl_str.cancelRequest_enu) )
        {
            ret = R_FDL_OK;
            g_fdl_str.spdSpdRequest_enu = R_FDL_TRUE;
        }
    }

    return (ret);
} /* R_FDL_SuspendRequest */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_ResumeRequest
 *********************************************************************************************************************/
/**
 * User interface function:
 * Sets the resume request flag for the write or erase operation
 *
 * Note:
 * The operation is not immediately resumed. Resume handling is controlled by R_FDL_Handler.
 * The status is returned by the status variable of the request structure (Set in
 * R_FDL_Handler).
 *
 * Resume request handling:
 * - Reset suspend request if set (then we have a not yet handled suspend request)
 * - Set resume request if we have a suspended operation (reqSuspend_pstr defined)
 *   and we have not already a resume request
 * - Reject all other conditions
 *
 * @param[in,out]   -
 * @return          result of the resume request
 *                  - R_FDL_OK           - Request accepted
 *                  - R_FDL_ERR_REJECTED - Request rejected
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_ResumeRequest (void)                                                           /* PRQA S 1503 */
{
    r_fdl_status_t ret;

    ret = R_FDL_OK;

    /* Block on not initialized library and on StandBy processing */
    if (R_FDL_TRUE == R_FDL_UFct_StateNotStandBy() )
    {
    
        /* Set the request flag only if we are already suspended */
        if ( (R_FDL_ISTAT_SUSPENDED == g_fdl_str.iStat_enu)
             && (R_FDL_FALSE == g_fdl_str.cancelRequest_enu) )
        {
            g_fdl_str.spdResRequest_enu = R_FDL_TRUE;
        }
        else
        {
            ret = R_FDL_ERR_REJECTED;
        }
    }
    else
    {
        ret = R_FDL_ERR_REJECTED;
    }

    return (ret);
} /* R_FDL_ResumeRequest */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_Standby
 *********************************************************************************************************************/
/**
 * User interface function:
 * Prepares the HW for fast standby entry:
 * - on write end erase
 * - blank check is not suspendable, here the function is without effect
 *
 * This function can be called asynchronous (e.g. interrupt function) and so need to take
 * care of the current hardware status in order to restore it later on during wakeup
 *
 * Note:
 * the function need to be called continuously until the result is != R_FDL_BUSY
 *
 * @param[in,out]   -
 * @return          result of the standby operation
 *                  - R_FDL_OK           - Flash hardware is in standby or ready (no more Flash operation)
 *                  - R_FDL_BUSY         - Flash hardware is still busy. Repeat calling the function
 *                  - R_FDL_ERR_REJECTED - Rejected, as the library is not initialized
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_StandBy (void)                                                                 /* PRQA S 1503 */
{
    r_fdl_status_t ret;

    /* Allow execution in each initialized state except StandBy and Init */
    if ( ( (R_FDL_TRUE == R_FDL_UFct_StateNotStandBy() ) &&
           (R_FDL_ISTAT_INIT != g_fdl_str.iStat_enu) )
         || (R_FDL_ISTAT_STANDBY_PR == g_fdl_str.iStat_enu) )
    {

        /* On Standby processing start, backup the internal Status */
        if (R_FDL_ISTAT_STANDBY_PR != g_fdl_str.iStat_enu)
        {
            g_fdl_str.stByIStatBackUp_enu = g_fdl_str.iStat_enu;

            /* Set to standby processing. By that, other EEL operations are blocked */
            g_fdl_str.iStat_enu = R_FDL_ISTAT_STANDBY_PR;
        }

        /* only operate standby, if any Flash operation is ongoing */
        if (R_FDL_FALSE == R_FDL_FCUFct_ChkReady() )
        {
            /* hardware is still busy */
            ret = R_FDL_BUSY;

            /* only operate standby if the Flash operation is suspendable
               additionally check if we are  not already suspended or in suspend
               processing */
            if (R_FDL_TRUE == R_FDL_FCUFct_ChkSuspendable() )
            {
                R_FDL_FCUFct_Suspend();
            }
        }

        /* hardware is no longer busy, set library into standby */
        else
        {
            g_fdl_str.iStat_enu = R_FDL_ISTAT_STANDBY;
            ret = R_FDL_OK;
        }
    }
    else
    {
        /* library is not initialized */
        ret = R_FDL_ERR_REJECTED;
    }

    return (ret);
} /* R_FDL_StandBy */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_WakeUp
 *********************************************************************************************************************/
/**
 * User interface function:
 * Wake up the hardware from standby
 *
 * @param[in,out]   -
 * @return          result of the initialization check
 *                  - R_FDL_OK           - Wakeup succeeded
 *                  - R_FDL_ERR_REJECTED - Rejected, as the library is not initialized
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_WakeUp (void)                                                                  /* PRQA S 1503 */
{
    r_fdl_status_t ret;

    /* We can only wakeup if we have been in standby before */
    if (R_FDL_ISTAT_STANDBY == g_fdl_str.iStat_enu)
    {
        ret = R_FDL_OK;

        g_fdl_str.iStat_enu = g_fdl_str.stByIStatBackUp_enu;

        /* check if we need to wakeup */
        if (R_FDL_TRUE == R_FDL_FCUFct_ResumeChkNeed() )
        {
            R_FDL_FCUFct_Resume();
        }
    }
    else
    {
        ret = R_FDL_ERR_REJECTED;
    }

    return (ret);
} /* R_FDL_WakeUp */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_CancelRequest
 *********************************************************************************************************************/
/**
 * User interface function:
 * Sets the cancel request flag for an ongoing operation (exception Prepare environment cmd)
 *
 * Note:
 * The operation is not immediately cancelled. Cancel handling is controlled by R_FDL_Handler.
 * The status is returned by the status variable of the request structure (Set in
 * R_FDL_Handler).
 *
 * Cancel request handling:
 * - Set cancel request if we do not have a standby operation
 *   and we have not already a cancel request
 * - Reject all other conditions
 *
 * @param[in,out]   -
 * @return          result of the cancel request
 *                  - R_FDL_OK           - Request accepted
 *                  - R_FDL_ERR_REJECTED - Request rejected
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_CancelRequest (void)                                                           /* PRQA S 1503 */
{
    r_fdl_status_t ret;

    ret = R_FDL_OK;

    /* Block on not initialized library and on StandBy processing */
    if ( (R_FDL_TRUE ==  R_FDL_UFct_StateNotStandBy() ) &&
        (R_FDL_ISTAT_INIT != g_fdl_str.iStat_enu)      &&
         (R_FDL_FALSE == g_fdl_str.cancelRequest_enu) )
    {

        /* Library is in suspended state, no operation on-going */
        if ( (R_FDL_ISTAT_SUSPENDED == g_fdl_str.iStat_enu) &&
             (R_FDL_REQUEST_POINTER_UNDEFINED == g_fdl_str.reqInt_pstr) )
        {
            ret = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
        }
        
        /* No operation ongoing */
        else if ( (R_FDL_ISTAT_NORMALOP == g_fdl_str.iStat_enu) &&
                  (R_FDL_REQUEST_POINTER_UNDEFINED == g_fdl_str.reqInt_pstr) )
        {
            ret = R_FDL_ERR_REJECTED;
        }
        else
        {
            /* Nothing to do, added to fix QAC warning message 2004 */
        }

        /* All conditions fulfilled for cancel */
        if (R_FDL_OK == ret)
        {
            g_fdl_str.cancelRequest_enu = R_FDL_TRUE;
        }
    }
    else
    {
        ret = R_FDL_ERR_REJECTED;
    }

    return (ret);
} /* R_FDL_CancelRequest */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_UFct_FlashOpStart
 *********************************************************************************************************************/
/**
 * Extract information required for a Flash operation and call the function which starts the operation.
 *
 * @param[in]  request_pstr - pointer to the operation request structure
 * @param[out] tmpStat_penu - Status return value. Is set to operation result. Possible values:
 *                              - R_FDL_BUSY
 *                              - R_FDL_ERR_PARAMETER
 *                              - R_FDL_ERR_PROTECTION
 *                              - R_FDL_OK (Read operation)
 *                              - R_FDL_ERR_ECC_SED (Read operation)
 *                              - R_FDL_ERR_ECC_DED (Read operation)
 * @param[in]  isCalledFromExecute_enu - flag to distinguish if the function is called from:
 *                                       - R_FDL_Execute: value R_FDL_TRUE
 *                                       - R_FDL_Handler: value R_FDL_FALSE
 *
 * @return     handler function flow may continue after this function or handler need to exit:
 *             - R_FDL_TRUE  - continue handler
 *             - R_FDL_FALSE - exit handler
 *             In case the function is called from R_FDL_Execute, the return value can be ignored.
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_UFct_FlashOpStart (r_fdl_request_t * request_pstr, 
                                                   r_fdl_status_t  * tmpStat_penu, 
                                                   r_fdl_flag_t      isCalledFromExecute_enu)
{
    uint32_t           addFlash;
    uint32_t           cntTotal;
    uint32_t           addBuf;
    uint32_t           granularityCurOp;
    uint32_t           cntCurOp;
    uint32_t           addEndCurOp;
    r_fdl_command_t    cmd;
    r_fdl_accessType_t accType;
    r_fdl_flag_t       cont;
    uint8_t            fcuCmd;

    addFlash         = (request_pstr->idx_u32);
    cntTotal         = (request_pstr->cnt_u16);
    cmd              = (request_pstr->command_enu);
    accType          = (request_pstr->accessType_enu);
    addBuf           = (request_pstr->bufAddr_u32);
    /* granularityCurOp has the default value for all commands except WRITE_16B */
    granularityCurOp = R_WRITE_SIZE;
    cont             = R_FDL_TRUE;
    (*tmpStat_penu)  = R_FDL_BUSY;


    if (R_FDL_CMD_ERASE == cmd)
    {
        addFlash <<= R_BLOCK_SIZE_2N;
        cntTotal <<= R_BLOCK_SIZE_2N;

        /* granularityCurOp has the default value */
        cntCurOp = (1 << R_BLOCK_SIZE_2N);

        /* Set buffer address to a valid address */
        addBuf   = 0x00000001uL;

        fcuCmd   = R_FCU_CMD_ERASE;
    }
    else if (R_FDL_CMD_BLANKCHECK == cmd)
    {
        cntTotal *= R_WRITE_SIZE;
        cntCurOp = cntTotal;

        /* Limit count to max */
        R_FDL_IFct_CalcFOpUnitCnt_BC (&cntCurOp, addFlash);

        /* Set buffer address to a valid address */
        addBuf   = 0x00000001uL;

        fcuCmd   = R_FCU_CMD_BLANKCHECK;
    }

    /* write 4 bytes (1 words) at once */
    else if (R_FDL_CMD_WRITE == cmd)
    {
        cntCurOp = R_WRITE_SIZE;
        cntTotal *= R_WRITE_SIZE;

        fcuCmd   = R_FCU_CMD_WRITE;
    }
#if (defined ENABLE_CMD_WRITE16B)

    /* write 16 bytes (4 words) at once */
    else if (R_FDL_CMD_WRITE16B == cmd)
    {
        cntCurOp = R_WRITE_SIZE_16B;
        cntTotal *= R_WRITE_SIZE_16B;

        granularityCurOp = cntCurOp;

        fcuCmd   = R_FCU_CMD_WRITE;
    }
#endif

    /* Read command */
    else
    {
        cntTotal *= R_WRITE_SIZE;
        cntCurOp = cntTotal;

        /* for the read cmd there is not equivalent FCU cmd, it is initialized here to fix QAC error message */
        fcuCmd = 0x00;
    }

    addEndCurOp = (addFlash + cntCurOp) - 1uL;

    /* Check against invalid buffer address (R_FDL_CMD_WRITE, R_FDL_CMD_WRITE16B, R_FDL_CMD_READ)
       - Only if function is called by R_FDL_Execute */
    if (R_FDL_TRUE == isCalledFromExecute_enu)
    {
        if (R_FDL_NULL == addBuf)
        {
            (*tmpStat_penu) = R_FDL_ERR_PARAMETER;
        }
        else
        {
            (*tmpStat_penu) = R_FDL_IFct_ChkAccessBoundaries (addFlash, cntTotal, accType, granularityCurOp);
        }

        /* Reset flag; it is updated later on in case the switch mode to PE is performed correctly */
        cont = R_FDL_FALSE;
    }

    if (R_FDL_BUSY == (*tmpStat_penu) )
    {
        /* Read command is treated only in R_FDL_Execute,
           no need to check given parameter isCalledFromExecute_enu */
        if (R_FDL_CMD_READ == cmd)
        {
            /* user destination buffer must be 4 bytes aligned */
            if (0 == (addBuf & R_U32_ALIGNED) )
            {
                (*tmpStat_penu) = R_FDL_FCUFct_ReadOperation ( (volatile uint32_t *)(&addFlash),
                                                              addBuf,
                                                               (cntTotal / R_WRITE_SIZE) );
                request_pstr->idx_u32 = addFlash;   /* Store possible fail address to request structure */
            }
            else
            {
                (*tmpStat_penu) = R_FDL_ERR_PARAMETER;
            }
        }
        
        /* all commands except Read */
        else
        {
            /* Switch mode only required once */
            if (R_FDL_TRUE == isCalledFromExecute_enu)
            {
                (*tmpStat_penu) = R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_PE);
                if (R_FDL_OK == (*tmpStat_penu) )
                {
                    (*tmpStat_penu) = R_FDL_FCUFct_SwitchMode_Check();
                    if (R_FDL_OK == (*tmpStat_penu) )
                    {
                        cont = R_FDL_TRUE;
                    }
                    else
                    {
                        g_fdl_str.opStatus_enu = R_FDL_OP_EXECUTE_SYNC_ON;
                    }
                }
            }

            /* continue if mode switch passed (either immediately after the mode switch 
               start or if the function is later on called by the handler */
            if (R_FDL_TRUE == cont)
            {
                if ( (R_FDL_CMD_ERASE == cmd) || (R_FDL_CMD_BLANKCHECK == cmd) )
                {
                    (*tmpStat_penu) = R_FDL_FCUFct_StartBCEraseOperation (addFlash, addEndCurOp, fcuCmd, accType);
                }
                
                /* Write command */
                else
                {
                    (*tmpStat_penu) = R_FDL_FCUFct_StartWriteOperation (addBuf, addFlash, cntCurOp, accType);

                    g_fdl_str.mulOp_str.bufAdd_u32 = addBuf + cntCurOp;          /* Next Source Address */
                }

                /* command can be executed */
                if (R_FDL_BUSY == (*tmpStat_penu) )
                {
                    g_fdl_str.opStatus_enu = R_FDL_OP_BUSY;

                    /* Prepare for multi-word write */
                    g_fdl_str.mulOp_str.flashAdd_u32     = addEndCurOp + 1uL;
                    g_fdl_str.mulOp_str.flashAddEnd_u32  = (addFlash + cntTotal) - 1uL;   /* Source End Address */
                    g_fdl_str.mulOp_str.accessType_enu   = accType;
                }
                
                /* error --> switch back to user mode */
                else
                {
                    (void)R_FDL_FCUFct_SwitchMode_Start (R_FCU_MODE_USER);

                    /* save operation status and return it after switch mode confirmation */
                    g_fdl_str.opResult_enu = (*tmpStat_penu);
                    g_fdl_str.opStatus_enu = R_FDL_OP_END_SYNC_OFF;
                    cont = R_FDL_FALSE;
                    (*tmpStat_penu) = R_FDL_BUSY;
                }
            }
        }
    }

    return (cont);
} /* R_FDL_UFct_FlashOpStart */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_UFct_EndCurrentOperation
 *********************************************************************************************************************/
/**
 * At the end of a Flash operation, this function updates the request structure elements and
 * resets the library internal pointer to this structure.
 *
 * @param[in]  ret_enu - status return value
 * @return     ---
 *
 * The function modifies the global structure g_fdl_str.reqInt_pstr to set the operation
 * status
*/
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC void R_FDL_UFct_EndCurrentOperation (r_fdl_status_t ret_enu)
{
    (g_fdl_str.reqInt_pstr)->status_enu = ret_enu;

    /* For Blank Check, return fail address too */
    if ( (R_FDL_CMD_BLANKCHECK == (g_fdl_str.reqInt_pstr)->command_enu) && (R_FDL_ERR_BLANKCHECK == ret_enu) )
    {
        (g_fdl_str.reqInt_pstr)->idx_u32 = g_fdl_str.opFailAddr_u32;
    }
    (g_fdl_str.reqInt_pstr)->accessType_enu = R_FDL_ACCESS_NONE;
    (g_fdl_str.reqInt_pstr)                 = R_FDL_REQUEST_POINTER_UNDEFINED;
     g_fdl_str.opStatus_enu                 = R_FDL_OP_IDLE;
    
    /* In case of internal error enforce re-initialization. No more command execution will be allowed */
    if (R_FDL_ERR_INTERNAL == ret_enu)
    {
        g_fdl_str.iStat_enu = R_FDL_ISTAT_NOINIT;
    }
} /* R_FDL_UFct_EndCurrentOperation */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_UFct_StateNotStandBy
 *********************************************************************************************************************/
/**
 * Check if the library is initialized and not in StandBy or StandBy processing
 *
 * @param[in,out]   -
 * @return          - R_FDL_TRUE   Library is initialized
 *                  - R_FDL_FALSE  Library is not initialized
*/
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_flag_t R_FDL_UFct_StateNotStandBy (void)
{
    r_fdl_flag_t ret;

    /* Any states except StandBy related states or uninitialized state */
    if ( (R_FDL_ISTAT_NORMALOP == g_fdl_str.iStat_enu)
        || (R_FDL_ISTAT_INIT == g_fdl_str.iStat_enu)
         || ( (R_FDL_ISTAT_SUSPEND_PR == g_fdl_str.iStat_enu)
              || (R_FDL_ISTAT_SUSPENDED == g_fdl_str.iStat_enu) ) )
    {
        ret = R_FDL_TRUE;
    }
    /* StandBy related state or uninitialized state */
    else
    {
        ret = R_FDL_FALSE;
    }


    return (ret);
} /* R_FDL_UFct_StateNotStandBy */

/*********************************************************************************************************************/
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

/*********************************************************************************************************************/

