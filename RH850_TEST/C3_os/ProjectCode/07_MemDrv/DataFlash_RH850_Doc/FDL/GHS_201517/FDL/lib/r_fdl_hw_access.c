#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_hw_access.c $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.11 $
 * Mod. Revision : $Revision: 1.70 $
 * Mod. Date     : $Date: 2016/06/01 12:39:20JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL hardware interface functions
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
#include "r_fdl_global.h"

/*********************************************************************************************************************
 * local function prototypes
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 8.8 (QAC message 3447)
 * Reason:       Function declared as external usable function, but is only used locally
 * Verification: Function must be declared global in order to avoid function inlining. The function contains assembler 
 *               code and relies on calling conventions. GHS may (in case of precompiled library creation) optimize by
 *               inlining. As the parameters are used in assbembler only, GHS will optimize call parameter preparation 
 *               away.
 *********************************************************************************************************************/ 
R_FDL_STATIC r_fdl_status_t   R_FDL_IFct_ChkAccessRight (r_fdl_accessType_t accType_enu,
                                                         uint32_t granularity_u32);
R_FDL_STATIC r_fdl_status_t   R_FDL_IFct_GetFWParam     (uint32_t addr_u32, uint32_t * buf);
#ifndef R_FDL_NO_BFA_SWITCH
R_FDL_STATIC void         R_FDL_FCUFct_InitRAM_Asm  (uint32_t * param_pu32);
R_FDL_STATIC void         R_FDL_IFct_GetFWParam_Asm (uint32_t * param_pu32);
R_FDL_STATIC uint32_t     R_FDL_IFct_GetBWCAdd      (void);
R_FDL_STATIC void         R_FDL_IFct_ExeCodeInRAM   (r_fdl_pFct_ExeInRAM pFct,
                                                     uint32_t *          param_pu32);
#endif
R_FDL_STATIC uint8_t          R_FDL_IFct_ReadMemoryU08  (uint32_t addr_u32);
R_FDL_STATIC uint16_t         R_FDL_IFct_ReadMemoryU16  (uint32_t addr_u32);
R_FDL_STATIC uint32_t         R_FDL_IFct_ReadMemoryU32  (uint32_t addr_u32);
R_FDL_STATIC void             R_FDL_IFct_WriteMemoryU16 (uint32_t addr_u32, uint16_t val_u16);
R_FDL_STATIC void             R_FDL_IFct_WriteMemoryU32 (uint32_t addr_u32, uint32_t val_u32);
             void             R_FDL_FCUFct_ChkReg_Asm   (uint32_t regAdd, uint32_t valMask,         /* PRQA S 3447 */
                                                         uint32_t to, uint32_t * ret);
/*********************************************************************************************************************
 * FDL internal section mapping definitions
 *********************************************************************************************************************/
#define R_FDL_START_SEC_CONST
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#if R_FDL_COMPILER == R_FDL_COMP_REC
    #define asm _asm
#endif


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ReadMemoryU32
 *********************************************************************************************************************/
/**
 * Function to read a 32-bit IO register or memory
 *
 * @param[in]  addr_u32 - source address
 * @return     32-bit register contents
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC uint32_t  R_FDL_IFct_ReadMemoryU32 (uint32_t addr_u32)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    return (test_cb_read_u32 (addr_u32) );
    #else
    return (*( (volatile uint32_t *)(addr_u32) ) );                                                 /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ReadMemoryU08
 *********************************************************************************************************************/
/**
 * Function to read a 8-bit IO register or memory
 *
 * @param[in]  addr_u32 - source address
 * @return     8-bit register contents
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
   MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
   Reason:       For effective embedded programming, integer to pointer conversions are used
   Verification: The converted addresses are essential for complete code execution. Incorrect
                 conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC uint8_t  R_FDL_IFct_ReadMemoryU08 (uint32_t addr_u32)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    return (test_cb_read_u8 (addr_u32) );
    #else
    return (*( (volatile uint8_t *)(addr_u32) ) );                                                  /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ReadMemoryU16
 *********************************************************************************************************************/
/**
 * Function to read a 16-bit IO register or memory
 *
 * @param[in]  addr_u32 - source address
 * @return     16-bit register contents
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC uint16_t  R_FDL_IFct_ReadMemoryU16 (uint32_t addr_u32)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    return (test_cb_read_u16 (addr_u32) );
    #else
    return (*( (volatile uint16_t *)(addr_u32) ) );                                                 /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_WriteMemoryU08
 *********************************************************************************************************************/
/**
 * Function to write a 8-bit IO register or memory
 *
 * @param[in]  addr_u32 - write destination address
 * @param[in]  val_u08  - 8-bit write data
 * @return     ---
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_IFct_WriteMemoryU08 (uint32_t addr_u32, uint8_t val_u08)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    test_cb_write_u8 (addr_u32, val_u08);
    #else
    (*( (volatile uint8_t *)(addr_u32) ) ) = val_u08;                                               /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_WriteMemoryU16
 *********************************************************************************************************************/
/**
 * Function to write a 16-bit IO register or memory
 *
 * @param[in]  addr_u32 - write destination address
 * @param[in]  val_u16  - 16-bit write data
 * @return     ---
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC void R_FDL_IFct_WriteMemoryU16 (uint32_t addr_u32, uint16_t val_u16)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    test_cb_write_u16 (addr_u32, val_u16);
    #else
    (*( (volatile uint16_t *)(addr_u32) ) ) = val_u16;                                              /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_WriteMemoryU32
 *********************************************************************************************************************/
/**
 * Function to write a 32-bit IO register or memory
 *
 * @param[in]  addr_u32 - write destination address
 * @param[in]  val_u32  - 32-bit write data
 * @return     ---
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303)
 * Reason:       For effective embedded programming, integer to pointer conversions are used
 * Verification: The converted addresses are essential for complete code execution. Incorrect
 *               conversion would result in test fails.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC void R_FDL_IFct_WriteMemoryU32 (uint32_t addr_u32, uint32_t val_u32)
{
    #if (defined TA_USE_TEST_CALLBACKS)
    test_cb_write_u32 (addr_u32, val_u32);
    #else
    (*( (volatile uint32_t *)(addr_u32) ) ) = val_u32;                                              /* PRQA S 0303 */
    #endif
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_CalcFOpUnitCnt_BC
 *********************************************************************************************************************/
/**
 * This function calculates the correct unit count for Flash operations.
 * Calculation basics: Blank Check may not overlap Flash macros
 * Smallest possible Flash macros are assumed. So, also operations within physical macros are cut, when a minimum
 * theoretical macro boundary is hit.
 *
 * @param[in,out]  cnt_pu32    - number of operation units. The input value is cut down to match the boundary conditions
 * @param[in]      addr_u32    - operation start address
 * @return         ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_IFct_CalcFOpUnitCnt_BC (uint32_t * cnt_pu32, uint32_t addr_u32)
{
    uint32_t cntTmp;
    uint32_t addMax;
    uint32_t cntTmpMax;

    cntTmp = (*cnt_pu32);

    /* Consider macro boundaries */
    addMax = ( (addr_u32 / R_MACROSIZE_MIN) * R_MACROSIZE_MIN); /* Calculate macro boundary */
    addMax += R_MACROSIZE_MIN;
    cntTmpMax = (addMax - addr_u32);                  /* Calculate remaining operations in the macro */

    /* Limit count to the macro maximum */
    if (cntTmpMax < cntTmp)
    {
        cntTmp = cntTmpMax;
    }

    *cnt_pu32 = cntTmp;

} /* R_FDL_IFct_CalcFOpUnitCnt_BC */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ChkAccessBoundaries
 *********************************************************************************************************************/
/**
 * This function checks if the Flash access boundaries are correct. Parameter error if:
 * - addStart granularity is not correct
 * - end address calc. wrap around
 * - end address overflow
 * - bCnt = 0
 * - selected block range is not in the correct pool (User/EEL)
 *
 * @param[in]  addrStart_u32   - Start address of the range to access
 * @param[in]  bCnt_u32        - Number of bytes to access
 * @param[in]  accType_enu     - type of FDL access (user or EEL)
 * @param[in]  granularity_u32 - Granularity for each command
 * @return     Returns the access check result
 *             - R_FDL_BUSY (check was OK)
 *             - R_FDL_ERR_PARAMETER (parameter error detected)
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 21.1 (QAC message 2912)
 * Reason:       Wraparound in unsigned arithmetic operation, used to detect parameter error.
 * Verification: A check against wraparound is performed immediately after the arithmetic operation in cause.
 *********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_IFct_ChkAccessBoundaries (uint32_t addrStart_u32,
                                               uint32_t bCnt_u32,
                                               r_fdl_accessType_t accType_enu,
                                               uint32_t granularity_u32)
{
    uint32_t       eelPoolStart;
    uint32_t       eelPoolSize;
    uint32_t       eelPoolEnd;
    uint32_t       fdlPoolEnd;
    uint32_t       addEnd;
    r_fdl_status_t ret;
    r_fdl_flag_t   inEelRange;

    ret = R_FDL_BUSY;

    eelPoolStart = (g_fdl_str.RTCfg_pstr->eelPoolStart_u16) << R_BLOCK_SIZE_2N;
    eelPoolSize  = (g_fdl_str.RTCfg_pstr->eelPoolSize_u16) << R_BLOCK_SIZE_2N;
    fdlPoolEnd   = ( (g_fdl_str.RTCfg_pstr->fdlPoolSize_u16) << R_BLOCK_SIZE_2N) - 1uL;

    inEelRange = R_FDL_FALSE;

    /* Byte count = 0 is parameter error */
    if (0uL == bCnt_u32)
    {
        ret = R_FDL_ERR_PARAMETER;
    }
    
    /* Byte count != 0 */
    else
    {
        addEnd = (addrStart_u32 + bCnt_u32) - 1uL;                                                 /* PRQA S 2912 */

        /* Start and end address checks against Data Flash size and Start address granularity */
        if ( (addrStart_u32 > addEnd) ||                /* end address calc. wrap around */
             ( (addEnd >= g_fdl_str.dfSize_u32) ||      /* end address overflow */
                                                        /* cnt parameter error.
                                                           Granularity is correct by default (user IF bases on block/word
                                                           count, lib. internally changed to byte cnt */
               ( (addrStart_u32 & (granularity_u32 - 1uL) ) != 0x00000000uL) ) )  /* address granularity */
        {
            ret = R_FDL_ERR_PARAMETER;
        }
        
        /* Addresses match to Data Flash, now check against EEL and FDL pool boundaries */
        else
        {

            /* EEL pool defined? */
            if (eelPoolSize > 0u)
            {
                eelPoolEnd   = (eelPoolStart + eelPoolSize) - 1u;

                /* Address range in EEL pool? */
                if ( (addrStart_u32 >= eelPoolStart) && (addEnd <= eelPoolEnd) )
                {
                    inEelRange = R_FDL_TRUE;
                }
                
                /* Should be outside EEL pool */
                else
                {
                    /* Are we overlapping boundaries? */
                    if (!( (addEnd < eelPoolStart) || (addrStart_u32 > eelPoolEnd) ) )
                    {
                        ret = R_FDL_ERR_PARAMETER;
                    }
                }
            }

            /* As EEL we must remain in the EEL range */
            if (R_FDL_ACCESS_EEL == accType_enu)
            {
                if (R_FDL_FALSE == inEelRange)
                {
                    ret = R_FDL_ERR_PARAMETER;
                }
            }
            
            /* As user ... */
            else if (R_FDL_ACCESS_USER == accType_enu)
            {
                /* we must remain in the Data Flash but outside EEL range */
                if ( (addEnd > fdlPoolEnd) || (R_FDL_TRUE == inEelRange) )
                {
                    ret = R_FDL_ERR_PARAMETER;
                }
            }
            else
            {
                ret = R_FDL_ERR_PARAMETER;
            }
        }
    }
    return (ret);
} /* R_FDL_IFct_ChkAccessBoundaries */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ChkAccessRight
 *********************************************************************************************************************/
/**
 * The check is a robustness feature against modification from outside the library as the parameter
 * check during command initiation should have detected any parameter error already. This check
 * shall block wrong settings directly before starting the Flash hardware. So,
 * on violation, the returned error is a protection error, not a parameter error. \n
 * The function reads back the access parameters from the FCU for the check and compares them
 * against the access rights defined by the descriptor.
 *
 * @param[in]  accType_enu - type of FDL access (user or EEL)
 * @param[in]  granularity_u32 - Granularity for each command, used to determine if start address is aligned properly
 *
 * @return     Returns the access check result
 *             - R_FDL_BUSY (check was OK)
 *             - R_FDL_ERR_INTERNAL (parameter detected)
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_status_t R_FDL_IFct_ChkAccessRight (r_fdl_accessType_t accType_enu,
                                                       uint32_t granularity_u32)
{
    r_fdl_status_t ret;
    uint32_t       addStart, bCnt;

    addStart = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSADR_U32);
    bCnt     = (R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FEADR_U32) - addStart) + R_WRITE_SIZE;

    #ifdef PATCH_TO_SIMULATE_ERRORS
    R_FDL_COV_SAVEOFF
    if (tstData_str.simError_enu == R_FDL_TRUE)
    {
        if (R_FDL_SIM_ERROR_PROTECTION == tstData_str.simErrorType_enu)
        {
            /* bCnt = 0 must raise a protection error */
            bCnt = 0;
            tstData_str.simError_enu = R_FDL_FALSE;
        }
    }
    R_FDL_COV_RESTORE
    #endif


    ret = R_FDL_IFct_ChkAccessBoundaries (addStart, bCnt, accType_enu, granularity_u32);
    /* R_FDL_IFct_ChkAccessBoundaries returns PARAMETER error as it is used in R_FDL_Execute for
       parameter check. If we check directly before Flash operation start, we want to return
       R_FDL_ERR_INTERNAL in error case. So we patch the return value here */
    if (R_FDL_ERR_PARAMETER == ret)
    {
        ret = R_FDL_ERR_INTERNAL;
    }

    return (ret);
} /* R_FDL_IFct_ChkAccessRight */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ChkReg_Asm
 *********************************************************************************************************************/
/**
 * Assembler function to read a register and wait till the target value is reached.
 * The register check loop is timeout supervised
 * Note: Function must be declared global (See QAC comment below)
 *
 * @param[in]     regAdd: register address (r6)
 * @param[in]     valMask: target value mask (r7)
 * @param[in]     to: timeout value (r8)
 * @param[out]    ret: timeout check result (r9)
 *                     0: No error, 1: Timeout error
 * @return        ---
 */
/*********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3006)
 * Reason:       This function contains a mixture of in-line assembler statements and C statements.
 *               The function is copied to RAM into a memory range of fix size. So, the function itself must have a
 *               fix size which cannot be realized by a c-compiler. So, the function is written in Assembler
 * Verification: Review of the c-interface (only temporary registers are used and the stack size is unchanged
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 1006)
 * Reason:       In-line assembler construct is a language extension. The code has been ignored.
 * Verification: -
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3206)
 * Reason:       function parameter seems to be not used in the function as no c-code relates on
 *               it, but the assembler code uses the parameter
 * Verification: -
 *********************************************************************************************************************/
 /*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 8.10 (QAC message 1505)
 * Reason:       Function declared as external usable function, but is only used locally
 * Verification: Function must be declared global in order to avoid function inlining. The function contains assembler 
 *               code and relies on calling conventions. GHS may (in case of precompiled library creation) optimize by
 *               inlining. As the parameters are used in assbembler only, GHS will optimize call parameter preparation 
 *               away.
 *********************************************************************************************************************/ 

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

R_FDL_COV_SAVEOFF

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_GHS
void R_FDL_FCUFct_ChkReg_Asm (uint32_t regAdd, uint32_t valMask, uint32_t to, uint32_t * ret) /*PRQA S 3006,3206,1505*/
{
    /* Used registers: r6 ~ r10  */
    asm (" _R_FDL_FCUFct_ChkReg_Loop:           ");
    asm (" ld.w 0[r6], r10                      "); /* read register value */
    asm (" and     r7, r10                      "); /* mask the value */
    asm (" cmp     r10, r7                      "); /* equal target value? */
    asm (" bz      _R_FDL_FCUFct_ChkReg_Pass    ");
    asm (" add     -1, r8                       "); /* timeout check */
    asm (" bnz     _R_FDL_FCUFct_ChkReg_Loop    ");

    asm (" mov     1, r10                       "); /* timeout detected, return 1 */
    asm (" st.w    r10, 0[r9]                   ");
    asm (" br      _R_FDL_FCUFct_ChkReg_End     ");

    asm (" _R_FDL_FCUFct_ChkReg_Pass:           ");
    asm (" st.w    r0, 0[r9]                    "); /* timeout detected, return 0 */

    asm (" _R_FDL_FCUFct_ChkReg_End:            ");

} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_GHS */

#if R_FDL_COMPILER == R_FDL_COMP_IAR
void R_FDL_FCUFct_ChkReg_Asm (uint32_t regAdd, uint32_t valMask, uint32_t to, uint32_t * ret) /*PRQA S 3006,3206,1505*/
{
    /* IAR compiler uses with rh850 compiler onwards the same calling conventions as GHS */
    __asm (
        "_R_FDL_FCUFct_ChkReg_Loop:          \n"
        " ld.w 0[r6], r10                    \n"
        " and     r7, r10                    \n"
        " cmp     r10, r7                    \n"
        " bz      _R_FDL_FCUFct_ChkReg_Pass  \n"
        " add     -1, r8                     \n"
        " bnz     _R_FDL_FCUFct_ChkReg_Loop  \n"
        "                                    \n"
        " mov     1, r10                     \n"
        " st.w    r10, 0[r9]                 \n"
        " br      _R_FDL_FCUFct_ChkReg_End   \n"
        "                                    \n"
        "_R_FDL_FCUFct_ChkReg_Pass:          \n"
        " st.w    r0, 0[r9]                  \n"
        "                                    \n"
        "_R_FDL_FCUFct_ChkReg_End:           \n"
        );

} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_IAR */

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_REC
#pragma inline_asm R_FDL_FCUFct_ChkReg_Asm
void R_FDL_FCUFct_ChkReg_Asm (uint32_t regAdd, uint32_t valMask, uint32_t to, uint32_t * ret) /*PRQA S 3006,3206,1505*/
{
    .local _R_FDL_FCUFct_ChkReg_Loop
    .local _R_FDL_FCUFct_ChkReg_Pass
    .local _R_FDL_FCUFct_ChkReg_End

_R_FDL_FCUFct_ChkReg_Loop:
    ld.w    0[r6], r10
    and r7, r10
    cmp r10, r7
    bz _R_FDL_FCUFct_ChkReg_Pass
    add -1, r8
    bnz _R_FDL_FCUFct_ChkReg_Loop

    mov     1, r10
    st.w r10, 0[r9]
    br _R_FDL_FCUFct_ChkReg_End

_R_FDL_FCUFct_ChkReg_Pass:
    st.w r0, 0[r9]

_R_FDL_FCUFct_ChkReg_End:
} /* R_FDL_FCUFct_ChkReg_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_REC */

R_FDL_COV_RESTORE

#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ForcedStop
 *********************************************************************************************************************/
/**
 * Reset FCU and FACI registers
 *
 * @param[in,out] -
 * @return        Returns timeout check result
 *                - R_FDL_OK:             function passed
 *                - R_FDL_ERR_INTERNAL:   timeout error
  */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_ForcedStop (void)
{
    r_fdl_status_t ret;
    uint32_t       res;

    R_FDL_IFct_WriteMemoryU08 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_FORCED_STOP);

    /* Register check loop */
    R_FDL_FCUFct_ChkReg_Asm (R_FCU_REGADD_FSTATR_U32,
                             R_FCU_REGBIT_FSTATR_FRDY,
                             R_FDL_TIMEOUT_CHKREG,
                             &res);

    /* Patch the check loop result: 0 --> check passed */
    if (0x00000000uL == res)
    {
        ret = R_FDL_OK;
    }
    /* != 0 --> timeout in check loop */
    else
    {
        ret = R_FDL_ERR_INTERNAL;
    }

    return (ret);
} /* R_FDL_FCUFct_ForcedStop */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ClearStatus
 *********************************************************************************************************************/
/**
 * Clear (error) status of the sequencer by the clear status FCU command
 *
 * @param[in,out]   -
 * @return          ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_FCUFct_ClearStatus (void)
{
    uint32_t res32;
    uint8_t  res8;

    res32 = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    if (R_FCU_REGBIT_FSTATR_ILGERR == (R_FCU_REGBIT_FSTATR_ILGERR & res32) )
    {
        res8 = R_FDL_IFct_ReadMemoryU08 (R_FCU_REGADD_FASTAT_U08);
        /* Only CLDLK bit may be set, others have to be cleared */
        if (R_FCU_REGBIT_FASTAT_CMDLK != res8)
        {
            R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_FASTAT_U08, R_FCU_REGBIT_FASTAT_CMDLK);
        }
    }

    R_FDL_IFct_WriteMemoryU08 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_CLEARSTAT);
} /* R_FDL_FCUFct_ClearStatus */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_Switch_FAEINT
 *********************************************************************************************************************/
/**
 * Switch On/OFF FAEINT
 *
 * @param[in,out]   on_t    - R_FDL_TRUE:  Switch interrupt on
 *                          - R_FDL_FALSE: Switch interrupt off
 * @return          ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_FCUFct_Switch_FAEINT (r_fdl_flag_t on_t)
{
    if (R_FDL_FALSE == on_t)
    {
        R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_FAEINT_U08, R_FCU_REGVAL_FAEINT_DISABLE);
    }
    else
    {
        R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_FAEINT_U08, R_FCU_REGVAL_FAEINT_ENABLE);
    }

} /* R_FDL_FCUFct_Switch_FAEINT */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_GetBWCAdd
 *********************************************************************************************************************/
/**
 * Use intrinsic functions to evaluate BWC address from PID register
 *
 * @param      -
 * @return     BWC register address, 0x00000000uL  if no BWC available
 */
/*********************************************************************************************************************/
#ifdef R_FDL_NO_BFA_SWITCH
#else

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC uint32_t R_FDL_IFct_GetBWCAdd (void)
{
    uint32_t bwc;
    uint32_t pid;

    /* regID 6, selID 1 */
    #if R_FDL_COMPILER == R_FDL_COMP_GHS
    pid = __STSR (R_SYSTEM_REGISTER_PID);
    #elif R_FDL_COMPILER == R_FDL_COMP_IAR
    pid = __STSR (R_SYSTEM_REGISTER_PID);
    #elif R_FDL_COMPILER == R_FDL_COMP_REC
    pid = __stsr_rh (R_SYSTEM_REGISTER_PID);
    #endif

    pid &= R_PID_CORE_MASK;    /* Extract bits 5~7 */

    /* G3K core */
    if (R_PID_CORE_G3K == pid)
    {
        bwc = R_BWCBUF_G3K_ADD;
    }
    
    /* G3KH core */
    else if (R_PID_CORE_G3KH == pid)
    {
        bwc = R_BWCBUF_G3KH_ADD;
    }
    
    /* No G3K code --> no BWC buffer */
    else
    {
        bwc = 0x00000000uL;
    }

    return (bwc);
} /* R_FDL_IFct_GetBWCAdd */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#endif /* ifdef R_FDL_NO_BFA_SWITCH */

/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_GetFWParam
 *********************************************************************************************************************/
/**
 * Call the assembler function to read out a firmware parameter from the Extra area
 *
 * @param[in]  addr_u32 - Read address
 * @param[out] buf - write buffer for the result value
 * @return     Returns timeout check result
 *             - R_FDL_OK:             function passed
 *             - R_FDL_ERR_INTERNAL:   timeout error
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC r_fdl_status_t R_FDL_IFct_GetFWParam (uint32_t addr_u32, uint32_t * buf)
{
    r_fdl_status_t ret;

    #ifdef R_FDL_NO_BFA_SWITCH
    ret = R_FDL_OK;
    (*buf) = R_FDL_IFct_ReadMemoryU32 (addr_u32);

    #else
    uint32_t getFWParam[5];

    /* Initialize the RAM function parameters */
    getFWParam[0] = addr_u32;                       /* Read address */
    getFWParam[1] = R_FDL_IFct_GetBWCAdd();         /* BWC buffer address */
    getFWParam[2] = 0x00000000uL;                   /* Reset result (only updated in case of no function error) */
    getFWParam[3] = R_FDL_TIMEOUT_CC;               /* Timeout loop count */
    getFWParam[4] = 0x00000000uL;                   /* Clear function call error */

    /* Execute Copy routine in RAM as BFA need to be temporarily switched on */
    R_FDL_IFct_ExeCodeInRAM (&R_FDL_IFct_GetFWParam_Asm, (uint32_t *)(&getFWParam[0]) );

    *buf = getFWParam[2];

    /* No timeout error */
    if (0x00000000uL == getFWParam[4])
    {
        ret = R_FDL_OK;
    }
    else
    {
        ret = R_FDL_ERR_INTERNAL;
    }
    #endif /* ifdef R_FDL_NO_BFA_SWITCH */

    return (ret);
} /* R_FDL_IFct_GetFWParam */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_GetFWParam_Asm
 *********************************************************************************************************************/
/**
 * Assembler function to read out a firmware parameter from the Extra area
 * The cache clear check loop is timeout supervised
 *
 * Note: the code for GHS, IAR and CC-RL is basically equal, only the style is compiler dependent and so, different.
 *       GHS code is fully commented, while the IAR and CC-RL code is partly or not commented. Refer to GHS comments
 *       to understand the code.
 *
 * @param[in,out]  param_pu32 \n
 *                 in  - Address to read \n
 *                 out - Read value
 * @return     ---
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3006)
 * Reason:       This function contains a mixture of in-line assembler statements and C statements.
 *               The function is copied to RAM into a memory range of fix size. So, the function itself must have a
 *               fix size which cannot be realized by a c-compiler. So, the function is written in Assembler
 * Verification: Review of the c-interface (only temporary registers are used and the stack size is unchanged
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 1006)
 * Reason:       In-line assembler construct is a language extension. The code has been ignored.
 * Verification: -
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3206)
 * Reason:       function parameter seems to be not used in the function as no c-code relates on
 *               it, but the assembler code uses the parameter
 * Verification: -
 *********************************************************************************************************************/
#ifdef R_FDL_NO_BFA_SWITCH
#else

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

R_FDL_COV_SAVEOFF

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_GHS
R_FDL_STATIC void R_FDL_IFct_GetFWParam_Asm (uint32_t * param_pu32)                             /* PRQA S 3006,3206 */
{
    /* GHS compilers use r6~r9 as scratch registers.
       r6: parameter address
       r7, r9: work register
       r8: value for switch BFA on/off
    */

    /* ----- Switch ON BFA ----- */
    asm (" mov 0x01, r8                         ");     /* Hard coded BFASEL value to switch on EXA3*/
    asm (" br _R_FDL_IFct_GetFWParam_Asm_SWBFA  ");

    asm (" _R_FDL_IFct_GetFWParam_Asm_Read:     ");

    /* Read requested data as one aligned word */
    asm (" ld.w 0[r6], r7                       ");
    asm (" ld.w 0[r7], r9                       ");
    asm (" st.w r9, 8[r6]                       ");

    /* ----- Switch OFF BFA ----- */
    asm (" mov r0, r8                           ");     /* Hard coded BFASEL value to switch off EXA3*/

    /* Switch BFA and clear the cache */
    /* & line buffer (Called twice) */
    asm (" _R_FDL_IFct_GetFWParam_Asm_SWBFA:    ");

    /* Switch EXA3 */
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" mov 0xffc59008, r7                   ");     /* Hard coded address of BFASEL */
    asm (" st.b r8, 0[r7]                       ");
    asm (" ld.b 0[r7], r7                       ");     /* dummy read from FCU register to wait one APB access cycle */
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" synci                                ");

    /* Clear the cache */
    asm (" stsr 24, r7, 4                       ");     /* system register 24, 4 is ICCTRL */
    asm (" ori 0x0100, r7, r7                   ");     /* set cache clear bit 8 */
    asm (" ldsr r7, 24, 4                       ");

    asm (" ld.w 12[r6], r9                      ");     /* read timeout value */
    asm (" _R_FDL_IFct_GetFWParam_Asm_Polling:  ");
    asm (" stsr 24, r7, 4                       ");     /* system register 24, 4 is ICCTRL */
    asm (" andi 0x0100, r7, r7");
    asm (" bz _R_FDL_IFct_GetFWParam_Asm_Polling_Pass"); /* exit loop when Cache is cleared (bit is 0) */
    asm (" add -1, r9");                                /* check timeout */
    asm (" bnz _R_FDL_IFct_GetFWParam_Asm_Polling");
    asm (" mov 1, r9");                                 /* store timeout error and continue*/
    asm (" st.w    r9, 16[r6]                   ");
    asm (" _R_FDL_IFct_GetFWParam_Asm_Polling_Pass:");

    asm (" synci                                ");

    /* Check the core - BWC buffer address == 0 --> clear cache
                        BWC buffer address != 0 --> clear BWC buffer */
    asm (" ld.w 4[r6], r9                       ");     /* get BWCBUFEN address */
    asm (" cmp r9, r0                           ");     /* BWCBUFEN address not available on G3M cores */
    asm (" be _R_FDL_IFct_GetFWParam_Asm_G3M    ");

    /* G3K core: Clear BWC */
    asm (" mov 0x01, r7                         ");     /* BWCBUFCLR bit */
    asm (" st.b r0, 0[r9]                       ");     /* BWCBUFCLR = 0 */
    asm (" st.b r7, 0[r9]                       ");     /* BWCBUFCLR = 1 */
    asm (" st.b r0, 0[r9]                       ");     /* BWCBUFCLR = 0 */
    asm (" ld.b 0[r9], r7                       ");
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" synci                                ");
    asm (" br _R_FDL_IFct_GetFWParam_Asm_CCEnd  ");

    /* G3M core: clear sub-cache */
    asm (" _R_FDL_IFct_GetFWParam_Asm_G3M:      ");
    asm (" stsr 24, r7, 13                      ");     /* system register 24, 13 is CDBCR */
    asm (" ori 0x02, r7, r7                     ");     /* set cache clear bit 1 */
    asm (" ldsr r7, 24, 13                      ");
    asm (" stsr 24, r7, 13                      ");     /* Dummy read to system register to complete the operation */

    asm (" _R_FDL_IFct_GetFWParam_Asm_CCEnd:    ");

    /* Check where to continue */
    asm (" cmp r8, r0                           ");     /* we check here against the hard coded BFASEL value */
    asm (" bnz _R_FDL_IFct_GetFWParam_Asm_Read  ");
} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_GHS */

#if R_FDL_COMPILER == R_FDL_COMP_IAR
R_FDL_STATIC void R_FDL_IFct_GetFWParam_Asm (uint32_t * param_pu32)                             /* PRQA S 3006,3206 */
{
    /* IAR compiler uses with rh850 compiler onwards the same calling conventions as GHS */
    __asm ("                                         \n"
           " mov 0x01, r8                            \n"
           " br _R_FDL_IFct_GetFWParam_Asm_SWBFA     \n"
           "                                         \n"
           "_R_FDL_IFct_GetFWParam_Asm_Read:         \n"
           "                                         \n"
           " /* Read requested data as one aligned word */ \n"
           " ld.w 0[r6], r7                          \n"
           " ld.w 0[r7], r9                          \n"
           " st.w r9, 8[r6]                          \n"
           "                                         \n"
           " /* ----- Switch OFF BFA ----- */        \n"
           " mov r0, r8                              \n"
           "                                         \n"
           " /* Switch BFA and clear the cache */    \n"
           " /* & line buffer (Called twice) */      \n"
           "_R_FDL_IFct_GetFWParam_Asm_SWBFA:        \n"
           "                                         \n"
           " /* Switch EXA3 */                       \n"
           " syncp                                   \n"
           " mov 0xffc59008, r7                      \n"
           " st.b r8, 0[r7]                          \n"
           " ld.b 0[r7], r7                          \n"
           " syncp                                   \n"
           " synci                                   \n"
           "                                         \n"
           " /* Clear the cache */                   \n"
           " stsr 24, r7, 4                          \n"
           " ori 0x0100, r7, r7                      \n"
           " ldsr r7, 24, 4                          \n"
           "                                         \n"
           " ld.w 12[r6], r9                         \n"
           "_R_FDL_IFct_GetFWParam_Asm_Polling:      \n"
           " stsr 24, r7, 4                          \n"
           " andi 0x0100, r7, r7                     \n"
           " bz _R_FDL_IFct_GetFWParam_Asm_Polling_Pass \n"
           " add -1, r9                              \n"
           " bnz _R_FDL_IFct_GetFWParam_Asm_Polling  \n"
           " mov 1, r9                               \n"
           " st.w    r9, 16[r6]                      \n"
           "_R_FDL_IFct_GetFWParam_Asm_Polling_Pass: \n"
           "                                         \n"
           " synci                                   \n"
           "                                         \n"
           " /* Check the core ... */                \n"
           " ld.w 4[r6], r9                          \n"
           " cmp r9, r0                              \n"
           " be _R_FDL_IFct_GetFWParam_Asm_G3M       \n"
           "                                         \n"
           " /* G3K core: Clear BWC */               \n"
           " mov 0x01, r7                            \n"
           " st.b r0, 0[r9]                          \n"
           " st.b r7, 0[r9]                          \n"
           " st.b r0, 0[r9]                          \n"
           " ld.b 0[r9], r7                          \n"
           " syncp                                   \n"
           " synci                                   \n"
           " br _R_FDL_IFct_GetFWParam_Asm_CCEnd     \n"
           "                                         \n"
           " /* G3M core: clear sub-cache */         \n"
           "_R_FDL_IFct_GetFWParam_Asm_G3M:          \n"
           " stsr 24, r7, 13                         \n"
           " ori 0x02, r7, r7                        \n"
           " ldsr r7, 24, 13                         \n"
           " stsr 24, r7, 13                         \n"
           "                                         \n"
           "_R_FDL_IFct_GetFWParam_Asm_CCEnd:        \n"
           "                                         \n"
           " /* Check where to continue */           \n"
           " cmp r8, r0                              \n"
           " bnz _R_FDL_IFct_GetFWParam_Asm_Read     \n"
           );

} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_IAR */

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_REC
#pragma inline_asm R_FDL_IFct_GetFWParam_Asm
R_FDL_STATIC void R_FDL_IFct_GetFWParam_Asm (uint32_t * param_pu32)
{
    mov 0x01, r8
    br _R_FDL_IFct_GetFWParam_Asm_SWBFA

_R_FDL_IFct_GetFWParam_Asm_Read:

    ld.w 0[r6], r7
    ld.w 0[r7], r9
    st.w r9, 8[r6]

    mov r0, r8

_R_FDL_IFct_GetFWParam_Asm_SWBFA:

    syncp
    mov 0xffc59008, r7
    st.b r8, 0[r7]
    ld.b 0[r7], r7
    syncp
    synci

    stsr 24, r7, 4
    ori 0x0100, r7, r7
    ldsr r7, 24, 4

    ld.w 12[r6], r9
_R_FDL_IFct_GetFWParam_Asm_Polling:
    stsr 24, r7, 4
    andi 0x0100, r7, r7
    bz _R_FDL_IFct_GetFWParam_Asm_Polling_Pass
    add -1, r9
    bnz _R_FDL_IFct_GetFWParam_Asm_Polling
    mov 1, r9
    st.w r9, 16[r6]
_R_FDL_IFct_GetFWParam_Asm_Polling_Pass:

    synci

    ld.w 4[r6], r9
    cmp r9, r0
    be _R_FDL_IFct_GetFWParam_Asm_G3M

    mov 0x01, r7
    st.b r0, 0[r9]
    st.b r7, 0[r9]
    st.b r0, 0[r9]
    ld.b 0[r9], r7
    syncp
    synci
    br _R_FDL_IFct_GetFWParam_Asm_CCEnd

_R_FDL_IFct_GetFWParam_Asm_G3M:
    stsr 24, r7, 13
    ori 0x02, r7, r7
    ldsr r7, 24, 13
    stsr 24, r7, 13

_R_FDL_IFct_GetFWParam_Asm_CCEnd:

    cmp r8, r0
    bnz _R_FDL_IFct_GetFWParam_Asm_Read
} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_REC */

R_FDL_COV_RESTORE

#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#endif /* ifdef R_FDL_NO_BFA_SWITCH */

/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_GetDFSize
 *********************************************************************************************************************/
/**
 * Get Data Flash size \n
 *
 * @param[out]      size - Size in Bytes
 * @return          Operation result
 *                  - R_FDL_OK: Operation successfully completed
 *                  - R_FDL_ERR_INTERNAL: Timeout during parameter read
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_GetDFSize (uint32_t * size)
{
    uint32_t       data;
    uint32_t       dataAddr;
    r_fdl_status_t ret;

    ret = R_FDL_IFct_GetFWParam (R_EXTRA3_SCDSADD, &dataAddr);    /* Entry tells where to find the PRD* information */

    if (R_FDL_OK == ret)
    {
        data = R_FDL_IFct_ReadMemoryU32 (dataAddr + R_PRDSEL3_OFFSET);
        data &= 0x0000FFFFuL;       /* Lower 16Byte are the DF size in kB. So, multiply accordingly */
        *size = data * 1024;
    }

    return (ret);
} /* R_FDL_FCUFct_GetDFSize */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_SetFrequency
 *********************************************************************************************************************/
/**
 * Set the FCU frequency. \n
 * APBFrequency - FCU frequency, set in MHz taken from descriptor is needed
 * The function may return an error if the frequency could not be set (Timeout of command error).
 *
 * @param[in,out]   -
 * @return     configuration result
 *             - R_FDL_OK                - Frequency set successfully
 *             - R_FDL_ERR_CONFIGURATION - Frequency parameter out of range
 *             - R_FDL_ERR_INTERNAL      - timeout during parameter read
 */
/*********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 9.1 (QAC message 2962)
 * Reason:       Possible use of uninitialized variable. 
 * Verification: Claimed variables initialization is done conditionally if iErr is false. However usage of the variable
 *               is also bound to this condition. So, no issue
 *********************************************************************************************************************/

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_SetFrequency (void)
{
    r_fdl_status_t ret;
    uint16_t       fCpu;
    uint16_t       fFaci;
    uint32_t       fwVal;
    uint8_t        fwVer, fDivider;
    uint32_t       fMin, fMax, fPClk;
    uint32_t       dataAddr, data;

    fCpu = g_fdl_str.RTCfg_pstr->cpuFrequencyMHz_u16;

    /* Get firmware parameters */
    /* FW version is 1 Byte on not word aligned address, so we read word aligned and calculate the correct byte */
    ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FWVER & (~0x00000003uL), &fwVal);
    fwVer    = (uint8_t)( (fwVal >> 8) & 0xFFu);

    /* Firmware version is > 1 (version 1 is marked with 0xFF)
       and no error during parameter read */
    if (    (0xFF != fwVer)
            && (R_FDL_OK == ret) )
    {
        /* Frequency is 32bit value in Hz. We need to calculate MHz from that */
        ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FMIN, &fwVal);
        fMin     = fwVal / 1000000uL;

        if (R_FDL_OK == ret)
        {
            ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FMAX, &fwVal);
            fMax     = fwVal / 1000000uL;
        }

        /* versions 2/3 and no error during parameter read*/
        if (fwVer < R_FCU_FWVER_04)
        {
            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                /* Divider 1 Byte only but on a word aligned address,
                   so we read word aligned and calculate the correct byte */
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FDIV_FWVER_03, &fwVal);
                fDivider = (uint8_t)(fwVal & 0xFFu);
            }

            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                /* PCLK Frequency is 32bit value in Hz. We need to calculate MHz from that */
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FPCLK_FWVER_03, &fwVal);
                fPClk    = fwVal / 1000000uL;
            }

            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                /* Entry tells where to find the PRD* information */
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_SCDSADD, &dataAddr);
            }

            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                data = R_FDL_IFct_ReadMemoryU32 (dataAddr + R_PRDNAME2_OFFSET);                     /* PRQA S 2962 */

                /* for devices F1x and R1x */
                if (R_PRDNAME_010x == (data & 0x00FFFFFFu) )
                {
                    g_fdl_str.baseAddrECC_u32 = R_DECC_BASE_F1X;
                }
                else
                {
                    g_fdl_str.baseAddrECC_u32 = R_DECC_BASE_E1X;
                }
            }
        }
        
        /* version 4 and upper */
        else
        {
            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                /* Divider 1 Byte only on a byte aligned address,
                   so we read word aligned and calculate the correct byte */
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FDIV_FWVER_04 & (~0x00000003uL), &fwVal);
                fDivider = (uint8_t)( (fwVal >> 8) & 0xFFu);
            }

            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                /* PCLK Frequency is 32bit value in Hz. We need to calculate MHz from that */
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_FPCLK_FWVER_04, &fwVal);
                fPClk    = fwVal / 1000000uL;
            }

            if (R_FDL_OK == ret)    /* no error during parameter read */
            {
                ret = R_FDL_IFct_GetFWParam (R_EXTRA3_ECCADDR, &(g_fdl_str.baseAddrECC_u32) );
            }
        }

        if (R_FDL_OK == ret)    /* no error during parameter read */
        {
            /* CPU frequency is within boundaries */
            if ( (fCpu >= fMin) && (fCpu <= fMax) )                                                 /* PRQA S 2962 */
            {
                /* FCU frequency is fix and independent from the CPU frequency */
                if (0xFF == fDivider)                                                               /* PRQA S 2962 */
                {
                    fFaci = (uint16_t)fPClk;                                                        /* PRQA S 2962 */
                }
                
                /* FCU frequency calculation (including frequency round up) */
                else
                {
                    fFaci = (fCpu + fDivider) - 1;
                    fFaci = fFaci / fDivider;
                }

                /* Set frequency */
                R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_PCKAR_U16, R_FCU_REGBIT_PCKAR_KEY + fFaci);
            }
            
            /* CPU frequency is out of bounds */
            else
            {
                ret = R_FDL_ERR_CONFIGURATION;
            }
        }
    }
    return (ret);
} /* R_FDL_FCUFct_SetFrequency */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_VerifyChecksum
 *********************************************************************************************************************/
/**
 * Function to verify the FCURAM checksum. \n
 *
 * @param[in,out]   -
 * @return
 *                  - R_FDL_BUSY
 *                  - R_FDL_ERR_INTERNAL (code in FCU RAM not OK)
 *
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_VerifyChecksum (void)
{
    r_fdl_status_t ret;

    #ifdef R_FDL_NO_BFA_SWITCH
    ret = R_FDL_BUSY;

    #else
    uint32_t add;
    uint32_t addEnd;
    uint32_t chkSum;

    /* Set FCU RAM to RW */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FCURAME_U16, R_FCU_REGBIT_FCURAME_FCRME + R_FCU_REGBIT_FCURAME_KEY);

    /* Calculate and compare FCU RAM checksum */
    addEnd = g_fdl_str.chksumEndAddr_u32;
    addEnd <<= 2;
    addEnd += R_FCU_RAM_ADD;
    chkSum = 0x00000000uL;

    /* Calculate the checksum over the FCU RAM */
    for (add = R_FCU_RAM_ADD; add < addEnd; add += 2)
    {
        chkSum += (uint32_t)(R_FDL_IFct_ReadMemoryU16 (add) );
    }

    /* Checksum correct */
    if (chkSum == g_fdl_str.chksumVal_u32)
    {
        ret = R_FDL_BUSY;
    }
        
    /* Checksum error */
    else
    {
        ret = R_FDL_ERR_INTERNAL;
    }

    /* Deactivate FCU RAM access */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FCURAME_U16,
                               R_FCU_REGBIT_FCURAME_RESET + R_FCU_REGBIT_FCURAME_KEY);
    #endif /* ifdef R_FDL_NO_BFA_SWITCH */

    return (ret);
} /* R_FDL_FCUFct_VerifyChecksum */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_InitRAM
 *********************************************************************************************************************/
/**
 * Function to copy the firmware to the FCU RAM. \n
 * As BFLASH need to be activated to copy code from device firmware to FCU RAM, some code needs to
 * be executed from RAM. \n
 * This function:
 * - prepares the parameter structure for the function to be executed in RAM
 * - calls the function to copy and execute the code in RAM
 * - saves the checksum related values for later processing
 * - clear the cache
 *
 * @param[in,out]   -
 * @return     Returns timeout check result
 *             - R_FDL_OK:             function passed
 *             - R_FDL_ERR_INTERNAL:   timeout error
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_InitRAM (void)
{
    r_fdl_status_t ret;

    #ifdef R_FDL_NO_BFA_SWITCH
    ret = R_FDL_OK;

    #else
    uint32_t initRamParam[8];

    /* Initialize the RAM function parameters */
    initRamParam[0] = R_FCU_RAM_SRC_ADD;
    initRamParam[1] = R_FCU_RAM_ADD;
    initRamParam[2] = R_FCU_RAM_SIZE;
    initRamParam[3] = R_FCU_RAM_ADD_CHKSUM_END;
    initRamParam[4] = R_FCU_RAM_ADD_CHKSUM;
    initRamParam[5] = R_FDL_IFct_GetBWCAdd();
    initRamParam[6] = R_FDL_TIMEOUT_CC;                 /* Timeout loop count */
    initRamParam[7] = 0x00000000uL;                     /* Reset function return value (Only set in case of an error) */

    /* Activate FCU RAM access */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FCURAME_U16,   R_FCU_REGBIT_FCURAME_FCRME + R_FCU_REGBIT_FCURAME_FRAMTRAN
                               + R_FCU_REGBIT_FCURAME_KEY);

    /* Execute Copy routine in RAM as BFA need to be temporarily switched on */
    R_FDL_IFct_ExeCodeInRAM (&R_FDL_FCUFct_InitRAM_Asm, (uint32_t *)(&initRamParam[0]) );

    /* Save checksum values, needed for later processing */
    g_fdl_str.chksumEndAddr_u32 = initRamParam[0];
    g_fdl_str.chksumVal_u32     = initRamParam[1];

    /* Deactivate FCU RAM access */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FCURAME_U16, R_FCU_REGBIT_FCURAME_RESET + R_FCU_REGBIT_FCURAME_KEY);

    /* No timeout error */
    if (0x00000000uL == initRamParam[7])
    {
        ret = R_FDL_OK;
    }
    else
    {
        ret = R_FDL_ERR_INTERNAL;
    }
    #endif /* ifdef R_FDL_NO_BFA_SWITCH */

    return (ret);


} /* R_FDL_FCUFct_InitRAM */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_InitRAM_Asm
 *********************************************************************************************************************/
/**
 * Copy the firmware to the FCU RAM --> This function is executed in RAM \n
 * Sequence is:
 * - Switch on BFA
 * - Copy code to FCU
 * - Switch off BFA
 * - Clear Cache
 * The cache clear check loop is timeout supervised
 *
 * Note: the code for GHS, IAR and CC-RL is basically equal, only the style is compiler dependent and so, different.
 *       GHS code is fully commented, while the IAR and CC-RL code is partly or not commented. Refer to GHS comments
 *       to understand the code.
 *
* @param[in]  param_pu32 - Parameter array containing addresses and data for the assembler
 *                          function
 * @return     ---
 */
/*********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3006)
 * Reason:       This function contains a mixture of in-line assembler statements and C statements.
 *               The function is copied to RAM into a memory range of fix size. So, the function itself must have a
 *               fix size which cannot be realized by a c-compiler. So, the function is written in Assembler
 * Verification: Review of the c-interface (only temporary registers are used and the stack size is unchanged
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 1006)
 * Reason:       In-line assembler construct is a language extension. The code has been ignored.
 * Verification: -
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 3206)
 * Reason:       function parameter seems to be not used in the function as no c-code relates on
 *               it, but the assembler code uses the parameter
 * Verification: -
 *********************************************************************************************************************/

#ifdef R_FDL_NO_BFA_SWITCH
#else

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

R_FDL_COV_SAVEOFF

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_GHS
R_FDL_STATIC void R_FDL_FCUFct_InitRAM_Asm (uint32_t * param_pu32)                              /* PRQA S 3006,3206 */
{
    /* GHS compilers use r6~r10 as scratch registers. This function requires r6~r9 */

    /* ----- Switch ON BFA ----- */
    asm (" movea 0x01, r0, r8                   ");     /* Hard coded BFASEL value to switch on EXA3*/
    asm (" br _R_FDL_FCUFct_InitRAM_Asm_SWBFA   ");

    asm (" _R_FDL_FCUFct_InitRAM_Asm_Copy:      ");

    /* Copy FW to RAM */
    /* r7: src, r8: dest, r9: cnt, */
    /* r10: read buffer */
    asm (" ld.w 0[r6], r7                       ");
    asm (" ld.w 4[r6], r8                       ");
    asm (" ld.w 8[r6], r9                       ");

    asm (" _R_FDL_FCUFct_InitRAM_Asm_Loop:      ");
    asm (" ld.w 0[r7], r10                      ");
    asm (" add 4, r7                            ");
    asm (" add 4, r8                            ");
    asm (" add -4, r9                           ");
    asm (" st.w r10, -4[r8]                     ");
    asm (" bnz _R_FDL_FCUFct_InitRAM_Asm_Loop   ");

    /* Copy end address and checksum */
    asm (" ld.w 12[r6], r7                      ");
    asm (" ld.w 0[r7], r10                      ");
    asm (" st.w r10, 0[r6]                      ");
    asm (" ld.w 16[r6], r7                      ");
    asm (" ld.w 0[r7], r10                      ");
    asm (" st.w r10, 4[r6]                      ");

    /* ----- Switch OFF BFA ----- */
    asm (" mov r0, r8                           ");     /* Hard coded BFASEL value to switch off EXA3*/

    /* Switch BFA and clear the cache */
    /* & line buffer (Called twice) */
    asm (" _R_FDL_FCUFct_InitRAM_Asm_SWBFA:     ");

    /* Switch EXA3 */
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" mov 0xffc59008, r7                   ");     /* Hard coded address of BFASEL */
    asm (" st.b r8, 0[r7]                       ");
    asm (" ld.b 0[r7], r7                       ");     /* Dummy read from FCU register to wait one APB access cycle */
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" synci                                ");

    /* Clear the cache */
    asm (" stsr 24, r7, 4                       ");     /* system register 24, 4 is ICCTRL */
    asm (" ori 0x0100, r7, r7                   ");     /* set cache clear bit 8 */
    asm (" ldsr r7, 24, 4                       ");

    asm (" ld.w 24[r6], r9                      ");     /* read timeout value */

    asm ("_R_FDL_IFct_InitRAM_Asm_Polling:      ");
    asm (" stsr 24, r7, 4                       ");     /* system register 24, 4 is ICCTRL */
    asm (" andi 0x0100, r7, r7                  ");
    asm (" bz _R_FDL_IFct_InitRAM_Asm_Polling_Pass");   /* exit loop when Cache is cleared (bit is 0) */
    asm (" add -1, r9                           ");     /* check timeout */
    asm (" bnz _R_FDL_IFct_InitRAM_Asm_Polling  ");

    asm (" mov 1, r9                            ");     /* store timeout error and continue*/
    asm (" st.w r9, 28[r6]                      ");
    asm (" _R_FDL_IFct_InitRAM_Asm_Polling_Pass: ");

    asm (" synci                                ");

    /* Check the core - BWC buffer address == 0 --> clear cache
                        BWC buffer address != 0 --> clear BWC buffer */
    asm (" ld.w 20[r6], r9                      ");     /* get BWCBUFEN address */
    asm (" cmp r9, r0                           ");     /* BWCBUFEN address not available on G3M cores */
    asm (" be _R_FDL_FCUFct_InitRAM_Asm_G3M     ");

    /* G3K core: Clear BWC */
    asm (" mov 0x01, r7                         ");     /* BWCBUFCLR bit */
    asm (" st.b r0, 0[r9]                       ");     /* BWCBUFCLR = 0 */
    asm (" st.b r7, 0[r9]                       ");     /* BWCBUFCLR = 1 */
    asm (" st.b r0, 0[r9]                       ");     /* BWCBUFCLR = 0 */
    asm (" ld.b 0[r9], r7                       ");
    asm (" syncp                                ");     /* sync to peripheral access */
    asm (" synci                                ");
    asm (" br _R_FDL_FCUFct_InitRAM_Asm_CCEnd   ");

    /* G3M core: clear sub-cache */
    asm (" _R_FDL_FCUFct_InitRAM_Asm_G3M:       ");
    asm (" stsr 24, r7, 13                      ");     /* system register 24, 13 is CDBCR */
    asm (" ori 0x02, r7, r7                     ");     /* set cache clear bit 1 */
    asm (" ldsr r7, 24, 13                      ");
    asm (" stsr 24, r7, 13                      ");     /* Dummy read to system register to complete the operation */

    asm (" _R_FDL_FCUFct_InitRAM_Asm_CCEnd:     ");

    /* Check where to continue */
    asm (" cmp r8, r0                           ");     /* we check here against the hard coded BFASEL value */
    asm (" bnz _R_FDL_FCUFct_InitRAM_Asm_Copy   ");
} /* R_FDL_FCUFct_InitRAM_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_GHS */

#if R_FDL_COMPILER == R_FDL_COMP_IAR
R_FDL_STATIC void R_FDL_FCUFct_InitRAM_Asm (uint32_t * param_pu32)                              /* PRQA S 3006,3206 */
/* IAR compiler uses with rh850 compiler onwards the same calling conventions as GHS */
{
    __asm ("                                         \n"
           " /* ----- Switch ON BFA ----- */         \n"
           " movea 0x01, r0, r8                      \n"
           " br _R_FDL_FCUFct_InitRAM_Asm_SWBFA      \n"
           "                                         \n"
           "_R_FDL_FCUFct_InitRAM_Asm_Copy:          \n"
           "                                         \n"
           " /* Copy FW to RAM */                    \n"
           " /* r7: src, r8: dest, r9: cnt, */       \n"
           " /* r10: read buffer */                  \n"
           " ld.w 0[r6], r7                          \n"
           " ld.w 4[r6], r8                          \n"
           " ld.w 8[r6], r9                          \n"
           "                                         \n"
           "_R_FDL_FCUFct_InitRAM_Asm_Loop:          \n"
           " ld.w 0[r7], r10                         \n"
           " add 4, r7                               \n"
           " add 4, r8                               \n"
           " add -4, r9                              \n"
           " st.w r10, -4[r8]                        \n"
           " bnz _R_FDL_FCUFct_InitRAM_Asm_Loop      \n"
           "                                         \n"
           " /* Copy end address and checksum */     \n"
           " ld.w 12[r6], r7                         \n"
           " ld.w 0[r7], r10                         \n"
           " st.w r10, 0[r6]                         \n"
           " ld.w 16[r6], r7                         \n"
           " ld.w 0[r7], r10                         \n"
           " st.w r10, 4[r6]                         \n"
           "                                         \n"
           " /* ----- Switch OFF BFA ----- */        \n"
           " mov r0, r8                              \n"
           "                                         \n"
           " /* Switch BFA and clear the cache */    \n"
           " /* & line buffer (Called twice) */      \n"
           "_R_FDL_FCUFct_InitRAM_Asm_SWBFA:         \n"
           "                                         \n"
           " /* Switch EXA3 */                       \n"
           " syncp                                   \n"
           " mov 0xffc59008, r7                      \n"
           " st.b r8, 0[r7]                          \n"
           " ld.b 0[r7], r7                          \n"
           " syncp                                   \n"
           " synci                                   \n"
           "                                         \n"
           " /* Clear the cache */                   \n"
           " stsr 24, r7, 4                          \n"
           " ori 0x0100, r7, r7                      \n"
           " ldsr r7, 24, 4                          \n"
           "                                         \n"
           " ld.w 24[r6], r9                         \n"
           "_R_FDL_IFct_InitRAM_Asm_Polling:         \n"
           " stsr 24, r7, 4                          \n"
           " andi 0x0100, r7, r7                     \n"
           " bz _R_FDL_IFct_InitRAM_Asm_Polling_Pass \n"
           " add -1, r9                              \n"
           " bnz _R_FDL_IFct_InitRAM_Asm_Polling     \n"
           "                                         \n"
           " mov 1, r9                               \n"
           " st.w r9, 28[r6]                         \n"
           "                                         \n"
           "_R_FDL_IFct_InitRAM_Asm_Polling_Pass:    \n"
           " synci                                   \n"
           "                                         \n"
           " /* Check the core ... */                \n"
           " ld.w 20[r6], r9                         \n"
           " cmp r9, r0                              \n"
           " be _R_FDL_FCUFct_InitRAM_Asm_G3M        \n"
           "                                         \n"
           " /* G3K core: Clear BWC */               \n"
           " mov 0x01, r7                            \n"
           " st.b r0, 0[r9]                          \n"
           " st.b r7, 0[r9]                          \n"
           " st.b r0, 0[r9]                          \n"
           " ld.b 0[r9], r7                          \n"
           " syncp                                   \n"
           " synci                                   \n"
           " br _R_FDL_FCUFct_InitRAM_Asm_CCEnd      \n"
           "                                         \n"
           " /* G3M core: clear sub-cache */         \n"
           "_R_FDL_FCUFct_InitRAM_Asm_G3M:           \n"
           " stsr 24, r7, 13                         \n"
           " ori 0x02, r7, r7                        \n"
           " ldsr r7, 24, 13                         \n"
           " stsr 24, r7, 13                         \n"
           "                                         \n"
           "_R_FDL_FCUFct_InitRAM_Asm_CCEnd:         \n"
           "                                         \n"
           " /* Check where to continue */           \n"
           " cmp r8, r0                              \n"
           " bnz _R_FDL_FCUFct_InitRAM_Asm_Copy      \n"
           );
} /* R_FDL_IFct_GetFWParam_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_IAR */

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 1006
#endif

#if R_FDL_COMPILER == R_FDL_COMP_REC
#pragma inline_asm R_FDL_FCUFct_InitRAM_Asm
R_FDL_STATIC void R_FDL_FCUFct_InitRAM_Asm (uint32_t * param_pu32)
{
    movea 0x01, r0, r8
    br _R_FDL_FCUFct_InitRAM_Asm_SWBFA

_R_FDL_FCUFct_InitRAM_Asm_Copy:

    ld.w 0[r6], r7
    ld.w 4[r6], r8
    ld.w 8[r6], r9

_R_FDL_FCUFct_InitRAM_Asm_Loop:
    ld.w 0[r7], r10
    add 4, r7
    add 4, r8
    add -4, r9                              
    st.w r10, -4[r8]
    bnz _R_FDL_FCUFct_InitRAM_Asm_Loop

    ld.w 12[r6], r7
    ld.w 0[r7], r10
    st.w r10, 0[r6]
    ld.w 16[r6], r7
    ld.w 0[r7], r10
    st.w r10, 4[r6]

    mov r0, r8

_R_FDL_FCUFct_InitRAM_Asm_SWBFA:

    syncp
    mov 0xffc59008, r7
    st.b r8, 0[r7]
    ld.b 0[r7], r7
    syncp
    synci

    stsr 24, r7, 4
    ori 0x0100, r7, r7
    ldsr r7, 24, 4

    ld.w 24[r6], r9
_R_FDL_IFct_InitRAM_Asm_Polling:
    stsr 24, r7, 4
    andi 0x0100, r7, r7
    bz _R_FDL_IFct_InitRAM_Asm_Polling_Pass
    add -1, r9
    bnz _R_FDL_IFct_InitRAM_Asm_Polling
    mov 1, r9
    st.w r9, 28[r6]
_R_FDL_IFct_InitRAM_Asm_Polling_Pass:

    synci

    ld.w 20[r6], r9
    cmp r9, r0
    be _R_FDL_FCUFct_InitRAM_Asm_G3M

    mov 0x01, r7
    st.b r0, 0[r9]
    st.b r7, 0[r9]
    st.b r0, 0[r9]
    ld.b 0[r9], r7
    syncp
    synci
    br _R_FDL_FCUFct_InitRAM_Asm_CCEnd

_R_FDL_FCUFct_InitRAM_Asm_G3M:
    stsr 24, r7, 13
    ori 0x02, r7, r7
    ldsr r7, 24, 13
    stsr 24, r7, 13

_R_FDL_FCUFct_InitRAM_Asm_CCEnd:

    cmp r8, r0
    bnz _R_FDL_FCUFct_InitRAM_Asm_Copy
} /* R_FDL_FCUFct_InitRAM_Asm */
#endif /* if R_FDL_COMPILER == R_FDL_COMP_REC */

R_FDL_COV_RESTORE

#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#endif /* ifdef R_FDL_NO_BFA_SWITCH */

/*********************************************************************************************************************
 * Function name:  R_FDL_IFct_ExeCodeInRAM
 *********************************************************************************************************************/
/**
 * Execute a function in RAM. \n
 * This function copies a function to the RAM and jumps to the RAM.
 * Stack is used as storage location for the function to be copied.
 *
 * @param[in]  pFct         - function to execute
 * @param[in]  param_pu32   - parameter structure that will be used by the function in RAM. The
 *                            structure pointer is just passed to the function.
 * @return     ---
 */
/*********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0310)
 * Reason:       Casting to different object pointer type is used because function code need
 *               to be copied to RAM.
 * Verification: Copy destination is g_fdl_str.
 *              - This is re-initialized afterwards in R_FDL_Init
 *              - Copy size is limited by "sizeof"
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * MISRA Rule:   MISRA-C 2004 rule 11.3 (QAC message 0303, 0305, 0306)
 * Reason:       Casts between a pointer and other data types are used because function
 *               code need to be copied to RAM and finally a jump to RAM is done
 * Verification: None as complete system would crash if this does not work.
 *********************************************************************************************************************/

/********************************************************************************************************************
* MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0491)
* Reason:       Array subscripting applied to an object of pointer type required to copy data to
*               RAM location
* Verification: Check copy boundaries and address
*********************************************************************************************************************/
#ifdef R_FDL_NO_BFA_SWITCH
#else

#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
R_FDL_STATIC void R_FDL_IFct_ExeCodeInRAM (r_fdl_pFct_ExeInRAM pFct, uint32_t * param_pu32)
{
    uint32_t size,
             i,
             add,
             addAl;

    volatile uint16_t * pSrc;
    r_fdl_pFct_ExeInRAM pFctExe;

#ifdef R_FDL_EXE_INIT_CODE_ON_STACK
    /* Code size calculation described in r_fdl_global.h */
    volatile uint16_t g_fdl_ramCodeBuf_au16[R_FDL_RAM_CODE_SIZE_HW];
#endif

    /* Copy code to the 16byte aligned buffer address */
    add   = (uint32_t)(&g_fdl_ramCodeBuf_au16[0]);                                                  /* PRQA S 0306 */
    addAl = ( ( (add + 15uL) >> 4) << 4);
    pSrc  = (uint16_t *)( (uint32_t)pFct - (addAl - add) );                                     /* PRQA S 0305, 0306 */
    size  = sizeof (g_fdl_ramCodeBuf_au16) >> 1;

    for (i = 0; i < size; i++)
    {
        g_fdl_ramCodeBuf_au16[i] = pSrc[i];                                                         /* PRQA S 0491 */
    }

    pFctExe = (r_fdl_pFct_ExeInRAM)(addAl);                                                         /* PRQA S 0305 */

    /* Critical section start - disable all interrupts and exceptions */
    FDL_CRITICAL_SECTION_BEGIN
    /* Execute code in RAM */
    pFctExe (param_pu32);

    /* Critical section end - enable interrupts and exceptions again */
    FDL_CRITICAL_SECTION_END
} /* R_FDL_IFct_ExeCodeInRAM */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#endif /* ifdef R_FDL_NO_BFA_SWITCH */

/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_SwitchMode_Start
 *********************************************************************************************************************/
/**
 * Switch FCU mode to Programming/User mode
 *
 * @param      mode_u16 - Mode (R_FCU_MODE_PE / R_FCU_MODE_CPE / R_FCU_MODE_USER)
 * @return
 * @li         R_FDL_OK
 * @li         R_FDL_ERR_PROTECTION
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_SwitchMode_Start (uint16_t mode_u16)
{
    volatile uint16_t regFENTRYR;
    uint32_t          regFSTATR;
    uint32_t          cmp;
    r_fdl_status_t    ret;

    ret = R_FDL_OK;

    /* switch target is user mode */
    if (R_FCU_MODE_USER == mode_u16)
    {
        /* Clear FCU errors */
        regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);
        cmp = R_FCU_REGBIT_FSTATR_ILGERR + R_FCU_REGBIT_FSTATR_ERSERR + R_FCU_REGBIT_FSTATR_PRGERR;
        if (R_FCU_REGBIT_FSTATR_RESET != (regFSTATR & cmp) )
        {
            R_FDL_FCUFct_ClearStatus();
        }
        R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FENTRYR_U16, mode_u16 + R_FCU_REGBIT_FENTRY_KEY);
        g_fdl_str.flashMode_u16 = mode_u16;

    }
    
    /* switch target is PE mode */
    else
    {
        /* Check if any Code flash operation is on-going (try to switch from Code Flash PE mode) */
        regFENTRYR =  R_FDL_IFct_ReadMemoryU16 (R_FCU_REGADD_FENTRYR_U16);
        if ( (regFENTRYR & R_FCU_MODE_CPE) == R_FCU_MODE_CPE)
        {
            ret = R_FDL_ERR_PROTECTION;
        }
        
        /* switch from read mode */
        else
        {
            /* Check if the mode is already set. If yes, setting it again would toggle the mode.
               So, don't set it again */
            if (mode_u16 != regFENTRYR)
            {
                R_FDL_IFct_WriteMemoryU16 (R_FCU_REGADD_FENTRYR_U16, mode_u16 + R_FCU_REGBIT_FENTRY_KEY);

                /* also clear FSADDRR and FEADDRR when entering P/E mode in order to allow access address
                   checking by R_FDL_IFct_ChkAccessRight */
                R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FSADR_U32, 0x00000000uL);
                R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FEADR_U32, 0x00000000uL);
            }
            g_fdl_str.flashMode_u16 = mode_u16;
        }
    }

    return (ret);
} /* R_FDL_FCUFct_SwitchMode_Start */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_SwitchMode_Check
 *********************************************************************************************************************/
/**
 * This function checks if the Flash sequencer operation mode switch is performed correctly
 *
 * @param[in,out]   -
 * @return
 * @li              R_FDL_OK
 * @li              R_FDL_BUSY
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_SwitchMode_Check (void)
{
    volatile uint16_t regFENTRYR;
    r_fdl_status_t    ret;

    ret = R_FDL_BUSY;

    /* We need a dummy read as the mode is not changed immediately on some devices */
    /* this is required because in automatic switch mode acceptance, the switch mode check function
       may only be called once to ensure correct operation for interrupt support */
    regFENTRYR =  R_FDL_IFct_ReadMemoryU16 (R_FCU_REGADD_FENTRYR_U16);
    regFENTRYR =  R_FDL_IFct_ReadMemoryU16 (R_FCU_REGADD_FENTRYR_U16);

    if (g_fdl_str.flashMode_u16 == regFENTRYR)
    {
        ret = R_FDL_OK;
    }

    return (ret);
} /* R_FDL_FCUFct_SwitchMode_Check */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_GetStat
 *********************************************************************************************************************/
/**
 * Return FCU Flash operation result
 *
 * @param[in,out]   -
 * @return          Operation result:
 *                  - R_FDL_ERR_BLANKCHECK
 *                  - R_FDL_ERR_WRITE
 *                  - R_FDL_ERR_ERASE
 *                  - R_FDL_BUSY
 *                  - R_FDL_OK
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_GetStat (void)
{
    r_fdl_status_t    stat;
    volatile uint32_t regFSTATR;
    volatile uint8_t  regFBCSTAT;

    /* For BC we need to check the command too because the bit cannot be reset after BC execution
       and so stays valid until next BC */
    regFBCSTAT = R_FDL_IFct_ReadMemoryU08 (R_FCU_REGADD_FBCSTAT_U08);

    /* Blank check command and blank error detected */
    if ( (R_FCU_REGBIT_FBCSTAT_BCST == (regFBCSTAT & R_FCU_REGBIT_FBCSTAT_BCST) ) &&
         (R_FDL_CMD_BLANKCHECK == g_fdl_str.reqInt_pstr->command_enu) )
    {
        stat = R_FDL_ERR_BLANKCHECK;
        g_fdl_str.opFailAddr_u32 = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FPSADDR_U32);
    }
    
    /* No Blank Check error or other command the Blank Check */
    else
    {
        regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

        #ifdef PATCH_TO_SIMULATE_ERRORS
        R_FDL_COV_SAVEOFF
        if (tstData_str.simError_enu == R_FDL_TRUE)
        {
            switch (tstData_str.simErrorType_enu)
            {
                case R_FDL_SIM_ERROR_ERASE:
                {
                    regFSTATR |= R_FCU_REGBIT_FSTATR_ERSERR;
                    tstData_str.simError_enu = R_FDL_FALSE;
                    break;
                }

                case R_FDL_SIM_ERROR_WRITE:
                {
                    regFSTATR |= R_FCU_REGBIT_FSTATR_PRGERR;
                    tstData_str.simError_enu = R_FDL_FALSE;
                    break;
                }

                default:
                {
                    break;
                }
            }     /* switch */

        }
        R_FDL_COV_RESTORE
        #endif /* ifdef PATCH_TO_SIMULATE_ERRORS */

        /* Detected programming error */
        if (R_FCU_REGBIT_FSTATR_PRGERR == (regFSTATR & R_FCU_REGBIT_FSTATR_PRGERR) )
        {
            stat = R_FDL_ERR_WRITE;
        }
        else
        {

            /* Detected Erase error */
            if (R_FCU_REGBIT_FSTATR_ERSERR == (regFSTATR & R_FCU_REGBIT_FSTATR_ERSERR) )
            {
                stat = R_FDL_ERR_ERASE;
            }
            else
            {

                /* In case of program or erase suspend bit set, returned status remains busy as
                   this is the resume status */
                if ( ( (R_FCU_REGBIT_FSTATR_PRGSPD == (regFSTATR & R_FCU_REGBIT_FSTATR_PRGSPD) ) &&
                       (R_FDL_CMD_WRITE == g_fdl_str.reqInt_pstr->command_enu) ) ||
                     ( (R_FCU_REGBIT_FSTATR_ERSSPD == (regFSTATR & R_FCU_REGBIT_FSTATR_ERSSPD) ) &&
                       (R_FDL_CMD_ERASE == g_fdl_str.reqInt_pstr->command_enu) ) )
                {
                    stat = R_FDL_BUSY;
                }
                else
                {
                    stat = R_FDL_OK;
                }
            }
        }
    }

    return (stat);
} /* R_FDL_FCUFct_GetStat */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_StartWriteOperation
 *********************************************************************************************************************/
/**
 * This function configures the Flash programming sequencer and starts the operation
 *
 * @param[in]  addSrc_u32  - source data address
 * @param[in]  addDest_u32 - EEP Flash write address, relative to EEP Flash base address
 * @param[in]  cnt_u32     - Number of words to write. Allowed is 1 or 4 words
 * @param[in]  accType_enu - User/EEL access (check of access rights)
 *
 * @return     Parameter check result:
 *             - R_FDL_BUSY
 *             - R_FDL_ERR_PROTECTION
 *             - R_FDL_ERR_INTERNAL
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_StartWriteOperation (uint32_t addSrc_u32,
                                                 uint32_t addDest_u32,
                                                 uint32_t cnt_u32,
                                                 r_fdl_accessType_t accType_enu)
{
    volatile uint32_t regFSTATR;
    uint32_t          i;
    r_fdl_status_t    ret;
    r_fdl_status_t    res;
    uint16_t          data;

    ret = R_FDL_BUSY;

    R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FSADR_U32, addDest_u32);

    /* We just write the end address to this register for the access rights check because the
       hardware does not store the write end address in a readable register
       Note: Writing the register is only possible before the write command is issued afterwards
             it is no longer possible*/
    R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FEADR_U32, addDest_u32 + (cnt_u32 - 1uL) );

#ifdef R_FDL_TST_WA_F1L_RESETBLOCKING
    {
        uint32_t loop;
        EEL_ROBUSTNESSTEST_DISABLE_RESET
        for (loop = 0; loop < 10000; loop++)
        {
        }
    }
#endif

    R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_WRITE);

    /* copy to FCU is 2 bytes at once */
    cnt_u32 /= R_FCU_DATA_TRANSFERSIZE;

    R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, (uint16_t)cnt_u32);

    /* Transfer write data to FACI */
    for (i = 0; i < cnt_u32; ++i)
    {
        /* assume reading of unaligned source buffer */
        data = (uint16_t)R_FDL_IFct_ReadMemoryU08 (addSrc_u32 + 1);
        data <<= 8;
        data += (uint16_t)R_FDL_IFct_ReadMemoryU08 (addSrc_u32);

        addSrc_u32 += 2;
        R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, data);

        /* DBFull signal may never occur */
        regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);
        if (R_FCU_REGBIT_FSTATR_DBFULL == (regFSTATR & R_FCU_REGBIT_FSTATR_DBFULL) )
        {
            ret = R_FDL_ERR_INTERNAL;
        }
    }

    if (R_FDL_BUSY == ret)
    {
        ret = R_FDL_IFct_ChkAccessRight (accType_enu, (cnt_u32 * R_FCU_DATA_TRANSFERSIZE) );
    }

    /* Check if an error occurred. Then, the library shall exit the P/E mode and return to read mode
      (possible if FRDY = 1) */
    if (R_FDL_BUSY == ret)
    {
        R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_EXE);
    }
    else
    {
        /* At this point the FRDY = 0, and by calling the ForcedStop, the FCU generates an intentional illegal error
           and FRDY bit becomes 1 */
        res = R_FDL_FCUFct_ForcedStop();
        if (R_FDL_OK != res)
        {
            ret = res; /* Internal error overrules a potential protection error */
        }
    }

#ifdef R_FDL_TST_WA_F1L_RESETBLOCKING
    EEL_ROBUSTNESSTEST_ENABLE_RESET
#endif

    return (ret);
} /* R_FDL_FCUFct_StartWriteOperation */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_StartBCEraseOperation
 *********************************************************************************************************************/
/**
 * This function configures the Flash programming sequencer and starts the operation
 *
 * @param[in]  addStart_u32 - Start address (1st block address for erase, 1st address for BC)
 * @param[in]  addEnd_u32   - End address (last block address for erase, last address for BC)
 * @param[in]  fcuCmd_u08   - Type of command. Erase / BC
 * @param[in]  accType_enu  - User/EEL access (check of access rights)
 *
 * @return status of the operation to start
 *         - R_FDL_BUSY - operation started
 *         - R_FDL_ERR_PROTECTION - operation blocked due to protection
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_StartBCEraseOperation (uint32_t addStart_u32,
                                                   uint32_t addEnd_u32,
                                                   uint8_t fcuCmd_u08,
                                                   r_fdl_accessType_t accType_enu)
{
    r_fdl_status_t ret;
    r_fdl_status_t res;

    R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FSADR_U32, addStart_u32);
    R_FDL_IFct_WriteMemoryU32 (R_FCU_REGADD_FEADR_U32, addEnd_u32);

    R_FDL_IFct_WriteMemoryU08 (R_FCU_DFLASH_CMD_ADD, fcuCmd_u08);

    ret = R_FDL_IFct_ChkAccessRight (accType_enu, R_WRITE_SIZE);

    /* Check if an error occurred. Then, the library shall exit the P/E mode and return to read mode
      (possible if FRDY = 1) */
    if (R_FDL_BUSY == ret)
    {
        R_FDL_IFct_WriteMemoryU08 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_EXE);
    }
    else
    {
        /* At this point the FRDY = 0, and by calling the ForcedStop, the FCU generates an intentional illegal error
           and FRDY bit becomes 1 */
        res = R_FDL_FCUFct_ForcedStop();
        if (R_FDL_OK != res)
        {
            ret = res; /* Internal error overrules a potential protection error */
        }
    }

    return (ret);
} /* R_FDL_FCUFct_StartBCEraseOperation */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ReadOperation
 *********************************************************************************************************************/
/**
 * This function reads data from the Data Flash. Doing so, it disables the ECC error interrupts to
 * avoid interrupt generation on accepted ECC errors when reading e.g. blank or partly written
 * Flash words. Instead, the error and fail address is returned to the calling function.
 * Note: Detecting a single bit error does not stop reading the Data Flash. Instead, the error
 *       is returned together with the fail address and the user application / EEL can still
 *       judge if it trusts the data. If later on a double bit error is detected, the function
 *       stop reading the data and the single bit error indication and address is overwritten
 *       with the double bit error indication and address
 *
 * @param[in,out]  pAddSrc_u32 \n
 *                 in:  Data Flash src address (byte index) to read. \n
 *                 out: In ECC error case the fail address is returned
 * @param[in]      addDest_u32 - destination buffer address
 * @param[in]      cnt_u32 - number of words to read
 *
 * @return     Parameter check result:
 *             - R_FDL_OK
 *             - R_FDL_ERR_ECC_SED (Single bit error detected during read)
 *             - R_FDL_ERR_ECC_DED (Double bit error detected during read)
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_ReadOperation (volatile uint32_t * pAddSrc_u32,
                                           uint32_t addDest_u32,
                                           uint32_t cnt_u32)
{
    r_fdl_status_t ret;
    uint32_t       addEnd;
    uint32_t       add;
    uint32_t       data;
    uint8_t        regDFERINT;
    uint32_t       regDFERSTR;


    ret     = R_FDL_OK;
    add     = (*pAddSrc_u32) + R_FCU_DFLASH_READ_ADD;
    addEnd  = add + (cnt_u32 * R_WRITE_SIZE);

    /* Clear ECC errors */
    R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_DFERSTC_U08, R_FCU_REGBIT_DFERSTC_ERRCLR);

    /* Backup and Disable ECC error interrupts */
    regDFERINT = R_FDL_IFct_ReadMemoryU08 (R_FCU_REGADD_DFERINT_U08);
    R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_DFERINT_U08, R_FCU_REGVAL_DFERINT_NOINT);

    /* Loop over all addresses to read */
    do
    {
        data = R_FDL_IFct_ReadMemoryU32 (add);
        R_FDL_IFct_WriteMemoryU32 (addDest_u32, data);

        regDFERSTR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_DFERSTR_U32);
        #ifdef PATCH_TO_SIMULATE_ERRORS
        R_FDL_COV_SAVEOFF
        if (tstData_str.simError_enu == R_FDL_TRUE)
        {
            if (R_FDL_SIM_ERROR_BITCHECK == tstData_str.simErrorType_enu)
            {
                if (2 == tstData_str.simErrorVal_u32)     /*simulate double bit error*/
                {
                    regDFERSTR |= R_FCU_REGBIT_DFERSTR_DEDF;
                    tstData_str.simError_enu = R_FDL_FALSE;
                }
                else     /*simulate single bit error*/
                {
                    regDFERSTR |= R_FCU_REGBIT_DFERSTR_SEDF;
                    tstData_str.simError_enu = R_FDL_FALSE;
                }
            }
        }
        R_FDL_COV_RESTORE
        #endif /* ifdef PATCH_TO_SIMULATE_ERRORS */


        /* Do we have an ECC error? */
        if (R_FCU_REGVAL_DFERSTR_NOERR != regDFERSTR)
        {

            /* Double error detected */
            if (R_FCU_REGBIT_DFERSTR_DEDF == (R_FCU_REGBIT_DFERSTR_DEDF & regDFERSTR) )
            {
                (*pAddSrc_u32) = add - R_FCU_DFLASH_READ_ADD;
                ret = R_FDL_ERR_ECC_DED;
            }
            
            /* On single bit error ... */
            else
            {
                /* ... note first error occurrence address */
                if (R_FDL_OK == ret)
                {
                    (*pAddSrc_u32) = add - R_FCU_DFLASH_READ_ADD;
                    ret = R_FDL_ERR_ECC_SED;
                }
            }

            /* Clear ECC errors */
            R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_DFERSTC_U08, R_FCU_REGBIT_DFERSTC_ERRCLR);
        }
        add += R_WRITE_SIZE;
        addDest_u32 += R_WRITE_SIZE;
    }
    while ( (add < addEnd) && (R_FDL_ERR_ECC_DED != ret) );

    /* Restore the ECC error interrupts */
    R_FDL_IFct_WriteMemoryU08 (R_FCU_REGADD_DFERINT_U08, regDFERINT);

    return (ret);
} /* R_FDL_FCUFct_ReadOperation */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ChkStartable
 *********************************************************************************************************************/
/**
 * function to check if write or erase may be started. BC or bit error check may always be started
 * so this test is not necessary there
 * - Erase may only start when no operation is suspended
 * - Write may only start if no write is suspended
 *
 * @param[in]  cmd_enu - command to be executed (erase/write/BC)
 * @return     check result
 *             - R_FDL_TRUE  - Flash operation is startable
 *             - R_FDL_FALSE - Flash operation is not startable
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_flag_t R_FDL_FCUFct_ChkStartable (r_fdl_command_t cmd_enu)
{
    volatile uint32_t regFSTATR;
    r_fdl_flag_t      ret;

    ret = R_FDL_TRUE;

    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    /* For the write command ... */
#if (defined ENABLE_CMD_WRITE16B)
    if ( (R_FDL_CMD_WRITE == cmd_enu) || (R_FDL_CMD_WRITE16B == cmd_enu) )
#else
    if (R_FDL_CMD_WRITE == cmd_enu)
#endif
    {
        /* check if the write suspend flag is set */
        if (0x00000000uL != (regFSTATR & R_FCU_REGBIT_FSTATR_PRGSPD) )
        {
            ret = R_FDL_FALSE;
        }
    }
    
    /* For the erase command ... */
    else
    {
        /* check if the write or erase suspend flag is set */
        if (0x00000000uL != (regFSTATR & (R_FCU_REGBIT_FSTATR_ERSSPD + R_FCU_REGBIT_FSTATR_PRGSPD) ) )
        {
            ret = R_FDL_FALSE;
        }
    }

    return (ret);
} /* R_FDL_FCUFct_ChkStartable */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ChkSuspendable
 *********************************************************************************************************************/
/**
 * Checks if a Flash operation may be suspended. \n
 * A Flash operation may be suspeded if the SUSRDY bit in FSTATR is set
 *
 * @param[in,out]   -
 * @return     check result
 *             - R_FDL_TRUE  - Flash operation is suspendable
 *             - R_FDL_FALSE - Flash operation is not suspendable
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_flag_t R_FDL_FCUFct_ChkSuspendable (void)
{
    volatile uint32_t regFSTATR;
    r_fdl_flag_t      ret;

    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    /* Check if the operation can be suspended */
    if (R_FCU_REGBIT_FSTATR_SUSRDY == (regFSTATR & R_FCU_REGBIT_FSTATR_SUSRDY) )
    {
        ret = R_FDL_TRUE;
        #if (defined ENABLE_CMD_WRITE16B)
        if (R_FDL_CMD_WRITE16B == g_fdl_str.reqInt_pstr->command_enu)
        {
            ret = R_FDL_FALSE;
        }
        #endif
    }
    else
    {
        ret = R_FDL_FALSE;
    }

    return (ret);
} /* R_FDL_FCUFct_ChkSuspendable */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_Suspend
 *********************************************************************************************************************/
/**
 * Suspends an ongoing Flash Flash operation
 *
 * @param[in,out]   -
 * @return          ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_FCUFct_Suspend (void)
{
    /* Suspend command */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_SUSPEND);
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ResumeChkNeed
 *********************************************************************************************************************/
/**
 * Checks if a formerly suspended Flash erase operation need to be resumed (not finished yet). \n
 * This is done by checking the PRGSPD and ERSSPD bits in FSTATR
 *
 * @param[in,out]   -
 * @return          check result
 *                  - R_FDL_TRUE  - Need to resume
 *                  - R_FDL_FALSE - Need no resume
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_flag_t R_FDL_FCUFct_ResumeChkNeed (void)
{
    volatile uint32_t regFSTATR;
    r_fdl_flag_t      ret;


    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    /* Any suspend flag set in the FACI? */
    if (0x00000000uL == (regFSTATR & (R_FCU_REGBIT_FSTATR_PRGSPD + R_FCU_REGBIT_FSTATR_ERSSPD) ) )
    {
        ret = R_FDL_FALSE;
    }
    else
    {
        ret = R_FDL_TRUE;
    }

    return (ret);
} /* R_FDL_FCUFct_ResumeChkNeed */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_Resume
 *********************************************************************************************************************/
/**
 * Resumes a formerly suspended Flash operation
 *
 * @param[in,out]   -
 * @return          ---
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
void R_FDL_FCUFct_Resume (void)
{
    /* Resume command */
    R_FDL_IFct_WriteMemoryU16 (R_FCU_DFLASH_CMD_ADD, R_FCU_CMD_EXE);
}
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_ChkReady
 *********************************************************************************************************************/
/**
 * Returns sequencer busy/Ready status \n
 * Ready if FSTATR.FRDY = 1
 *
 * @param[in,out]   -
 * @return          Status of the sequencer
 *                  - R_FDL_TRUE  - Sequencer is not busy with a Flash operation
 *                  - R_FDL_FALSE - Sequencer is busy with a Flash operation
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_flag_t R_FDL_FCUFct_ChkReady (void)
{
    r_fdl_flag_t      ret;
    volatile uint32_t regFSTATR;

    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    #ifdef PATCH_TO_SIMULATE_ERRORS
    R_FDL_COV_SAVEOFF
    if ( (tstData_str.simError_enu == R_FDL_TRUE) &&
         (R_FDL_SIM_FCU_TIMEOUT == tstData_str.simErrorType_enu) )
    {
        regFSTATR &= (~R_FCU_REGBIT_FSTATR_FRDY);
    }
    R_FDL_COV_RESTORE
    #endif

    /* Check if the FACI is ready */
    if (R_FCU_REGBIT_FSTATR_FRDY == (regFSTATR & R_FCU_REGBIT_FSTATR_FRDY) )
    {
        ret = R_FDL_TRUE;

    #ifdef PATCH_TO_SIMULATE_ERRORS
        R_FDL_COV_SAVEOFF
        if ( (tstData_str.simError_enu == R_FDL_TRUE) &&
             (tstData_str.simErrorType_enu == R_FDL_SIM_ERROR_FATALERROR) )
        {
            tstData_str.simErrorCnt_u32++;
        }
        R_FDL_COV_RESTORE
    #endif
    }
    else
    {
        ret = R_FDL_FALSE;
    }

    return (ret);
} /* R_FDL_FCUFct_ChkReady */
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */


/*********************************************************************************************************************
 * Function name:  R_FDL_FCUFct_CheckFatalError
 *********************************************************************************************************************/
/**
 * Returns information if a fatal error occurred in the FCU (e.g. double bit ECC errors, FCU internal errors,
 * protection error ...).\n
 *
 * @param[in,out]   -
 * @return          check result
 *                  - R_FDL_OK               - No fatal error in the FCU
 *                  - R_FDL_ERR_PROTECTION   - Protection error caused by FHVE
 *                  - R_FDL_ERR_INTERNAL     - Other fatal FCU errors
 */
/*********************************************************************************************************************/
#define R_FDL_START_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */
r_fdl_status_t R_FDL_FCUFct_CheckFatalError (void)
{
    r_fdl_status_t    ret;
    volatile uint32_t regFSTATR;
    uint32_t          checkVal;

    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);

    #ifdef PATCH_TO_SIMULATE_ERRORS
    R_FDL_COV_SAVEOFF
    if (tstData_str.simError_enu == R_FDL_TRUE)
    {
        if (R_FDL_SIM_ERROR_FATALERROR == tstData_str.simErrorType_enu)
        {
            if ( (tstData_str.simErrorCntSet_u32 == 0)
                 || ( (tstData_str.simErrorCntSet_u32 != 0)
                      && (tstData_str.simErrorCntSet_u32 == tstData_str.simErrorCnt_u32) ) )
            {

                while ( (regFSTATR & R_FCU_REGBIT_FSTATR_FRDY) != R_FCU_REGBIT_FSTATR_FRDY)
                {
                    regFSTATR = R_FDL_IFct_ReadMemoryU32 (R_FCU_REGADD_FSTATR_U32);
                }
                regFSTATR |= ( (uint16_t)tstData_str.simErrorVal_u32);
                tstData_str.simError_enu = R_FDL_FALSE;
            }
        }
        else if (R_FDL_SIM_ERROR_FHVE == tstData_str.simErrorType_enu)
        {
            regFSTATR |= ( (uint16_t)tstData_str.simErrorVal_u32);
            tstData_str.simError_enu = R_FDL_FALSE;
        }
    }
    R_FDL_COV_RESTORE
    #endif /* ifdef PATCH_TO_SIMULATE_ERRORS */

    ret = R_FDL_OK;
    checkVal = ( ( ( ( ( R_FCU_REGBIT_FSTATR_FRDTCT
                       + R_FCU_REGBIT_FSTATR_TBLDTCT )
                       + R_FCU_REGBIT_FSTATR_CFGDTCT )
                       + R_FCU_REGBIT_FSTATR_FCUERR )
                       + R_FCU_REGBIT_FSTATR_ILGERR )
                       + R_FCU_REGBIT_FSTATR_OTPDTCT );

    /* Any detected error flag results in internal error (fatal error) */
    if ( (checkVal & regFSTATR) != 0x00000000u)
    {
        ret = R_FDL_ERR_INTERNAL;
    }
    else
    {
        checkVal = R_FCU_REGBIT_FSTATR_FHVEERR;

        /* Check FV`HVE protection error */
        if ( (checkVal & regFSTATR) != 0x00000000u)
        {
            ret = R_FDL_ERR_PROTECTION;
        }
    }

    return (ret);
} /* R_FDL_FCUFct_CheckFatalError */

/*********************************************************************************************************************/
#define R_FDL_STOP_SEC_PUBLIC_CODE
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

#define R_FDL_STOP_SEC_CONST
#include "r_fdl_mem_map.h"                                                                          /* PRQA S 5087 */

/*********************************************************************************************************************/
