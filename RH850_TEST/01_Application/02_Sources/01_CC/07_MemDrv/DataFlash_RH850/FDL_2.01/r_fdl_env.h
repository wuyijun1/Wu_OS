#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/*********************************************************************************************************************
 * Library       : Data Flash Access Library for Renesas RH850 devices
 *
 * File Name     : $Source: r_fdl_env.h $
 * Lib. Version  : $RH850_FDL_LIB_VERSION_T01: V2.00 $
 * Mod. Revision : $Revision: 1.16 $
 * Mod. Date     : $Date: 2014/08/18 18:07:52MESZ $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Flash programming hardware related definitions
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

#ifndef R_FDL_ENV_H
#define R_FDL_ENV_H


/*********************************************************************************************************************
 * Global constants (define, const, ...)
 *********************************************************************************************************************/
/* ---------------- FCU definitions ---------------------------------------- */
#define R_FCU_BASE                    (0xFFA10000uL)

#define R_FCU_REGADD_FASTAT_U08       (R_FCU_BASE + 0x010uL)
#define R_FCU_REGBIT_FASTAT_CMDLK     (0x10u)

#define R_FCU_REGADD_FMATSELC_U16     (R_FCU_BASE + 0x020uL)
#define R_FCU_REGBIT_FMATSELC_KEY     (0x3B00u)
#define R_FCU_REGBIT_FMATSELC_EX3S    (0x0004u)               /* Select EXA3 */
#define R_FCU_REGBIT_FMATSELC_RESET   (0x0000u)

#define R_FCU_REGADD_FSADR_U32        (R_FCU_BASE + 0x030uL)
#define R_FCU_REGADD_FEADR_U32        (R_FCU_BASE + 0x034uL)

#define R_FCU_REGADD_FCURAME_U16      (R_FCU_BASE + 0x054uL)
#define R_FCU_REGBIT_FCURAME_KEY      (0xC400u)
#define R_FCU_REGBIT_FCURAME_FCRME    (0x0001u)               /* 1: on, 0: off */
#define R_FCU_REGBIT_FCURAME_FRAMTRAN (0x0002u)               /* 0: RW, 1: High speed */
#define R_FCU_REGBIT_FCURAME_RESET    (0x0000u)

#define R_FCU_REGADD_FSTATR_U32       (R_FCU_BASE + 0x080uL)
#define R_FCU_REGBIT_FSTATR_FRCRCT    (0x00000001uL)
#define R_FCU_REGBIT_FSTATR_FRDTCT    (0x00000002uL)
#define R_FCU_REGBIT_FSTATR_TBLDTCT   (0x00000008uL)
#define R_FCU_REGBIT_FSTATR_CFGDTCT   (0x00000020uL)
#define R_FCU_REGBIT_FSTATR_FHVEERR   (0x00000040uL)
#define R_FCU_REGBIT_FSTATR_FCUERR    (0x00000080uL)
#define R_FCU_REGBIT_FSTATR_PRGSPD    (0x00000100uL)
#define R_FCU_REGBIT_FSTATR_ERSSPD    (0x00000200uL)
#define R_FCU_REGBIT_FSTATR_DBFULL    (0x00000400uL)
#define R_FCU_REGBIT_FSTATR_SUSRDY    (0x00000800uL)
#define R_FCU_REGBIT_FSTATR_PRGERR    (0x00001000uL)
#define R_FCU_REGBIT_FSTATR_ERSERR    (0x00002000uL)
#define R_FCU_REGBIT_FSTATR_ILGERR    (0x00004000uL)
#define R_FCU_REGBIT_FSTATR_FRDY      (0x00008000uL)
#define R_FCU_REGBIT_FSTATR_OTPDTCT   (0x00020000uL)
#define R_FCU_REGBIT_FSTATR_RESET     (0x00000000uL)

#define R_FCU_REGADD_FENTRYR_U16      (R_FCU_BASE + 0x084uL)
#define R_FCU_REGBIT_FENTRY_FENTRYD   (0x0080u)
#define R_FCU_REGBIT_FENTRY_FENTRYC   (0x0001u)
#define R_FCU_REGBIT_FENTRY_KEY       (0xAA00u)
#define R_FCU_REGBIT_FENTRY_OFF       (0x0000u)
#define R_FCU_REGBIT_FENTRY_KEYMASK   (0x00FFu)
#define R_FCU_MODE_PE                 (R_FCU_REGBIT_FENTRY_FENTRYD)
#define R_FCU_MODE_CPE                (R_FCU_REGBIT_FENTRY_FENTRYC)
#define R_FCU_MODE_USER               (R_FCU_REGBIT_FENTRY_OFF)

#define R_FCU_REGADD_FBCSTAT_U08      (R_FCU_BASE + 0x0D4uL)
#define R_FCU_REGBIT_FBCSTAT_BCST     (0x01u)

#define R_FCU_REGADD_FPSADDR_U32      (R_FCU_BASE + 0x0D8uL)

#define R_FCU_REGADD_PCKAR_U16        (R_FCU_BASE + 0x0E4uL)
#define R_FCU_REGBIT_PCKAR_KEY        (0x1E00u)

#define R_DECC_BASE_E1X               (0xFFC62C00uL)
#define R_DECC_BASE_F1X               (0xFFC66000uL)
#define R_DECC_BASE                   (g_fdl_str.baseAddrECC_u32)

#define R_FCU_REGADD_DFERSTR_U32      (R_DECC_BASE + 0x004uL)
#define R_FCU_REGBIT_DFERSTR_SEDF     (0x00000001u)
#define R_FCU_REGBIT_DFERSTR_DEDF     (0x00000002u)
#define R_FCU_REGVAL_DFERSTR_NOERR    (0x00000000u)

#define R_FCU_REGADD_DFERSTC_U08      (R_DECC_BASE + 0x008uL)
#define R_FCU_REGBIT_DFERSTC_ERRCLR   (0x01u)

#define R_FCU_REGADD_DFERINT_U08      (R_DECC_BASE + 0x014uL)
#define R_FCU_REGVAL_DFERINT_NOINT    (0x00u)


/* The BFA defines are just dummy defines in order to remember that the values are required.
   The values are used in in-line assembly code and cannot be derived from this header file */
#define R_CCIB_BASE                   (0xFFC59000uL)

#define R_FCU_REGADD_BFASELR_U08      (R_CCIB_BASE + 0x008uL)
#define R_FCU_REGBIT_BFASELR_BFASEL   (0x01u)
#define R_FCU_REGBIT_BFASELR_RESET    (0x00u)


/* ---------------- Other Data Flash related defines ----------------------- */
#define R_FDL_FCU_RAM_ADD             (0xFFA12000uL)
#define R_FDL_FCU_RAM_SIZE            (0x00001000uL)
#define R_FDL_FCU_RAM_SRC_ADD         (0x00017000uL)
#define R_FDL_FCU_RAM_ADD_CHKSUM_END  (0x00017FF8uL)
#define R_FDL_FCU_RAM_ADD_CHKSUM      (0x00017FFCuL)
#define R_FDL_EXTRA3_FWVER            (0x00010219uL)
#define R_FDL_EXTRA3_FMAX             (0x00010234uL)
#define R_FDL_EXTRA3_FMIN             (0x00010238uL)
#define R_FDL_EXTRA3_FDIV_FWVER_03    (0x00010264uL)
#define R_FDL_EXTRA3_FPCLK_FWVER_03   (0x00010274uL)
#define R_FDL_EXTRA3_FDIV_FWVER_04    (0x00010265uL)
#define R_FDL_EXTRA3_FPCLK_FWVER_04   (0x00010278uL)
#define R_FDL_EXTRA3_SCDSADD          (0x00010270uL)
#define R_FDL_EXTRA3_ECCADDR          (0x00010288uL)

#define R_FDL_FCU_FWVER_03            (0x03u)
#define R_FDL_FCU_FWVER_04            (0x04u)

#define R_FDL_PRDSEL3_OFFSET          (0xC8uL)
#define R_FDL_PRDNAME2_OFFSET         (0xD4uL)
#define R_PRDNAME_010x                (0x00303130u)

#define R_FCU_DFLASH_CMD_ADD          (0xFFA20000uL)
#define R_FCU_DFLASH_READ_ADD         (0xFF200000uL)

#define R_FCU_CMD_ERASE               (0x20u)                 /* FCU erase command */
#define R_FCU_CMD_CLEARSTAT           (0x50u)                 /* FCU clear status reg. command */
#define R_FCU_CMD_BLANKCHECK          (0x71u)                 /* FCU BC command */
#define R_FCU_CMD_SUSPEND             (0xB0u)                 /* FCU suspend command */
#define R_FCU_CMD_FORCED_STOP         (0xB3u)                 /* Stop and reset FCU */
#define R_FCU_CMD_WRITE               (0xE8u)                 /* FCU write command */
#define R_FCU_CMD_EXE                 (0xD0u)                 /* FCU start execution */

#define R_FDL_FCU_DATA_TRANSFERSIZE   (0x02uL)

#define R_FDL_FCU_FMIN                (0x0004u)
#define R_FDL_FCU_FMAX                (0x0064u)

#define R_FDL_BLOCK_SIZE              (0x0040u)               /* EEP Flash block size in bytes */
#define R_FDL_BLOCK_SIZE_2N           (0x0006u)               /* EEP block size as 2^N Bytes */
#define R_FDL_WRITE_SIZE              (0x00000004uL)          /* Normal write granularity */
#define R_FDL_WRITE_SIZE_16B          (0x00000010uL)          /* 16 bytes write granularity */
#define R_FDL_MACROSIZE_MIN           (0x00001000uL)          /* Minimum Flash macro size */


/* ---------------------------- Other defines ------------------------------ */
#define R_FDL_U32_ALIGNED             (0x03u)

/*********************************************************************************************************************/
#endif /* ifndef R_FDL_ENV_H */

