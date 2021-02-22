#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_global.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.00 $
 * Mod. Revision : $Revision: 1.29 $
 * Mod. Date     : $Date: 2014/08/18 18:08:17MESZ $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : FDL internal definitions and global functions
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
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
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

#ifndef R_FDL_GLOBAL_H
#define R_FDL_GLOBAL_H


/*********************************************************************************************************************
 * Include list
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "r_fdl.h"
#include "r_fdl_env.h"

/*********************************************************************************************************************
 * Global constants (define, const, ...)
 *********************************************************************************************************************/
/* -------------------- Library version string ----------------------------- */
#define R_FDL_VERSION_STRING                    "DH850T01xxxxxxV200"

/* -------------------- Misc constants ------------------------------------- */
/* Reset value of request pointers */
#define R_FDL_REQUEST_POINTER_UNDEFINED         (r_fdl_request_t *)(0x00000000uL)
#define R_FDL_DESCRIPTOR_POINTER_UNDEFINED      (r_fdl_descriptor_t *)(0x00000000uL)
#define R_FDL_NULL                              (0x00000000uL)


/*********************************************************************************************************************
 * Global type definitions
 *********************************************************************************************************************/
/**
   @enum r_fdl_flag_t
   standard FDL internal flag definition
*/
typedef enum R_FDL_FLAG_T
{
    R_FDL_FALSE,                                    /**< Flag false */
    R_FDL_TRUE                                      /**< Flag true */
} r_fdl_flag_t;

/**
   @enum r_fdl_int_status_t
   definition of the FDL operational status
*/
typedef enum R_FDL_INT_STATUS_T
{
    R_FDL_ISTAT_NOINIT          = 0x00000000uL,     /**< Pattern for uninitialized library (0x00000000) */
    R_FDL_ISTAT_INIT            = 0x55555554uL,     /**< Pattern for initialized library after R_FDL_Init */
    R_FDL_ISTAT_NORMALOP        = 0x55555555uL,     /**< Pattern for prepared library after
                                                         R_FDL_CMD_PREPARE_ENV execution */
    R_FDL_ISTAT_SUSPEND_PR      = 0x55555556uL,     /**< Pattern for library in suspend processing */
    R_FDL_ISTAT_SUSPENDED       = 0x55555557uL,     /**< Pattern for library in suspend status */
    R_FDL_ISTAT_STANDBY_PR      = 0x55555558uL,     /**< Pattern for library in standby processing */
    R_FDL_ISTAT_STANDBY         = 0x55555559uL      /**< Pattern for library in standby */
} r_fdl_int_status_t;

/**
   @typedef r_fdl_pFct_ExeInRAM
   pointer to a function. Is used in e.g. R_FDL_FCUFct_InitRAM_...
*/
typedef void (* r_fdl_pFct_ExeInRAM)(uint32_t * param_pu32);

/**
   @enum r_fdl_op_status_t
   definition of the internal operation status required for switch mode handling
*/
typedef enum R_FDL_OP_STATUS_T
{
    R_FDL_OP_IDLE                 = 0,              /**< No on-going operation */
    R_FDL_OP_EXECUTE_SYNC_ON      = 1,              /**< Operation ready to start, switch mode 
                                                         to P/E requested */
    R_FDL_OP_PREPARE_START        = 2,              /**< Prepare environment operation ready to start, 
                                                         switch mode to P/E requested */
    R_FDL_OP_PREPARE_RST_FCU      = 3,              /**< Prepare environment operation started,
                                                         switch mode to P/E requested */
    R_FDL_OP_PREPARE_END          = 4,              /**< Prepare environment operation on-going, FCU reset performed, 
                                                         switch mode to read requested */
    R_FDL_OP_RESUME_SYNC_ON       = 5,              /**< Resume request accepted, switch mode 
                                                         to P/E requested */
    R_FDL_OP_RESUME_MULTI_SYNC_ON = 6,              /**< Resume request accepted to restart a multiple operation, 
                                                         switch mode to P/E requested */
    R_FDL_OP_BUSY                 = 7,              /**< On-going operation */
    R_FDL_OP_SUSPEND_SYNC_OFF     = 8,              /**< Suspend processing finished, switch mode to read requested */
    R_FDL_OP_END_SYNC_OFF         = 9               /**< Operation finished, switch mode to read requested */
} r_fdl_op_status_t;

/**
   @struct r_fdl_multiOp_t
   structure containing the data required for multi operations (erase multiple blocks, write multiple half words data)
*/
typedef struct R_FDL_MULTIOP_T
{
    uint32_t            flashAdd_u32;               /**< source data pointer */
    uint32_t            bufAdd_u32;                 /**< destination data pointer */
    uint32_t            flashAddEnd_u32;            /**< last source address to write */
    r_fdl_accessType_t  accessType_enu;             /**< access type */
} r_fdl_multiOp_t;

/**
   @struct r_fdl_data_t
   this structure contains all FDL internal data
*/
typedef struct R_FDL_DATA_T
{
    const r_fdl_descriptor_t *  RTCfg_pstr;         /**< pointer to descriptor structure, initialized by
                                                         R_FDL_ISTAT_INIT */
    r_fdl_multiOp_t     mulOp_str;                  /**< multi operation (erase/write) variables. Set when a multi
                                                         operation is started, checked/updated when a single
                                                         erase/write is finished */
    r_fdl_multiOp_t     spdMulOp_str;               /**< multi operation variables backup for FDL suspend */
    r_fdl_request_t *   reqSuspend_pstr;            /**< request structure pointer backup buffer for suspend/resume */
    r_fdl_request_t *   reqInt_pstr;                /**< request structure pointer for current operation */
    r_fdl_op_status_t   opStatus_enu;               /**< Operation status required for switch mode handling */
    uint32_t            opFailAddr_u32;             /**< fail address of the blank check operation */
    uint32_t            dfSize_u32;                 /**< Data Flash size, required for boundary checks */
    uint32_t            baseAddrECC_u32;            /**< ECC base address determined on firmware
                                                         parameter version */
    uint32_t            chksumEndAddr_u32;          /**< Checksum end address */
    uint32_t            chksumVal_u32;              /**< Checksum value */
    uint16_t            flashMode_u16;              /**< Current Flash operating mode: P/E or Read */
    r_fdl_status_t      spdResStatus_enu;           /**< result backup buffer for suspend/resume */
    r_fdl_status_t      opResult_enu;               /**< result backup buffer for switch mode handling */
    r_fdl_flag_t        cancelRequest_enu;          /**< cancel request indication to the handler */
    r_fdl_flag_t        spdSpdRequest_enu;          /**< suspend request indication to the handler */
    r_fdl_flag_t        spdResRequest_enu;          /**< resume request indication to the handler */
    r_fdl_int_status_t  stByIStatBackUp_enu;        /**< internal status backup for StandBy processing */
    r_fdl_int_status_t  iStat_enu;                  /**< FDL operational status variable */
} r_fdl_data_t;


/*********************************************************************************************************************
 * Global macros
 *********************************************************************************************************************/
/* Static functions definition */
#ifndef R_FDL_STATIC
    #define R_FDL_STATIC static
#endif


/*********************************************************************************************************************
 * Global function prototypes
 *********************************************************************************************************************/
r_fdl_status_t  R_FDL_FCUFct_CheckFatalError       (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkReady              (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkSuspendable        (void);
r_fdl_flag_t    R_FDL_FCUFct_ChkStartable          (r_fdl_command_t     cmd_enu);
void            R_FDL_FCUFct_ClearStatus           (void);
r_fdl_status_t  R_FDL_FCUFct_GetStat               (void);
void            R_FDL_FCUFct_InitRAM               (void);
r_fdl_status_t  R_FDL_FCUFct_ReadOperation         (volatile uint32_t * pAddSrc_u32, 
                                                    uint32_t            addDest_u32, 
                                                    uint32_t            cnt_u32);
r_fdl_flag_t    R_FDL_FCUFct_ResumeChkNeed         (void);
void            R_FDL_FCUFct_Resume                (void);
r_fdl_status_t  R_FDL_FCUFct_SetFrequency          (void);
uint32_t        R_FDL_FCUFct_GetDFSize             (void);
r_fdl_status_t  R_FDL_FCUFct_StartBCEraseOperation (uint32_t            addStart_u32, 
                                                    uint32_t            addEnd_u32,
                                                    uint8_t             fcuCmd_u08,    
                                                    r_fdl_accessType_t  accType_enu);
r_fdl_status_t  R_FDL_FCUFct_StartWriteOperation   (uint32_t            addSrc_u32,   
                                                    uint32_t            addDest_u32,
                                                    uint32_t            cnt_u32,      
                                                    r_fdl_accessType_t  accType_enu);
void            R_FDL_FCUFct_Suspend               (void);
r_fdl_status_t  R_FDL_FCUFct_SwitchMode_Start      (uint16_t            mode_u16);
r_fdl_status_t  R_FDL_FCUFct_SwitchMode_Check      (void);
r_fdl_status_t  R_FDL_IFct_ChkAccessBoundaries     (uint32_t            addrStart_u32, 
                                                    uint32_t            bCnt_u32,
                                                    r_fdl_accessType_t  accType_enu, 
                                                    uint32_t            granularity_u32);
void            R_FDL_IFct_WriteMemoryU08          (uint32_t            addr_u32, 
                                                    uint8_t             val_u08);
void            R_FDL_IFct_CalcFOpUnitCnt_BC       (uint32_t *          cnt_pu32, 
                                                    uint32_t            addr_u32);
void            R_FDL_FCUFct_ForcedStop            (void);
r_fdl_status_t  R_FDL_FCUFct_VerifyChecksum        (void);


/*********************************************************************************************************************
 * Global data declarations
 *********************************************************************************************************************/
    #define R_FDL_START_SEC_VAR
    #include "r_fdl_mem_map.h"

    #if R_FDL_COMPILER == R_FDL_COMP_GHS
        #define R_FDL_NOINIT
    #elif R_FDL_COMPILER == R_FDL_COMP_IAR
        #define R_FDL_NOINIT __no_init
    #elif R_FDL_COMPILER == R_FDL_COMP_REC
        #define R_FDL_NOINIT
    #endif

extern R_FDL_NOINIT r_fdl_data_t   g_fdl_str;         /**< fdl global variable structure */

    #define R_FDL_STOP_SEC_VAR
    #include "r_fdl_mem_map.h"

/*********************************************************************************************************************/


/*********************************************************************************************************************
 * Add test defines and typedefs
 *********************************************************************************************************************/
#ifdef PATCH_TO_SIMULATE_ERRORS
    #include "FDL-tc_common.h"
#endif

    /* specific defines for coverage measurement */
    #ifdef _BullseyeCoverage
        #define R_FDL_COV_SAVEOFF _Pragma ("BullseyeCoverage save off")
        #define R_FDL_COV_RESTORE _Pragma ("BullseyeCoverage restore")
    #else
        #define R_FDL_COV_SAVEOFF
        #define R_FDL_COV_RESTORE
    #endif
/*********************************************************************************************************************/
#endif /* ifndef R_FDL_GLOBAL_H */

