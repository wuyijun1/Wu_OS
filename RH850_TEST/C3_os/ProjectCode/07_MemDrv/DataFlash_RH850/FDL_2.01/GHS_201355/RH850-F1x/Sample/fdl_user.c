/*********************************************************************************************************************
 * File Name     : $Source: fdl_user.c $
 * Mod. Revision : $Revision: 1.12 $
 * Mod. Date     : $Date: 2014/09/10 16:23:10MESZ $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : library related functions, which may be edited by the user
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

/*********************************************************************************************************************
 * FDL header files include
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "app.h"
#include "target.h"

/*********************************************************************************************************************
 * Compiler specific defines
 *********************************************************************************************************************/
#if   APP_COMPILER == APP_COMP_GHS
#elif APP_COMPILER == APP_COMP_IAR
    #define asm __asm
#elif APP_COMPILER == APP_COMP_REC
#endif    

/*********************************************************************************************************************
 * module global variable
 *********************************************************************************************************************/
uint32_t  PSWSafe; /* Variable to backup the PSW value before disabling ID/NP */

/*********************************************************************************************************************
 * Function name:  FDL_User_CriticalSetionBegin
 *********************************************************************************************************************/
/**
 * Function to disable Maskable / non maskable exceptions and NMI when critical code shall be 
 * executed that allows no access to the code Flash or might have problems with synchronization
 * 
 * @param          ---
 * @return         ---
 */  
/*********************************************************************************************************************/
#if APP_COMPILER == APP_COMP_GHS
void FDL_User_CriticalSetionBegin( void )
{
    asm( "ldsr    r0, 31" );                            /* select system register bank 0 
                                                          (contains PSW)*/
    asm( "stsr    0x05, r7" );                          /* load PSW (register 5) */
    asm( "mov     _PSWSafe, r6" );                      /* backup PSW */
    asm( "st.w    r7, 0[r6]" );                         /* " */
    asm( "movea   0x00A0, r0, r6" );                    /* NMI Flag=1, ID=1 */ 
    asm( "or      r7, r6 ");                            /* " */
    asm( "ldsr    r6, 5" );                             /* write PSW */
}
#elif APP_COMPILER == APP_COMP_REC
#pragma inline_asm FDL_User_CriticalSetionBegin
void FDL_User_CriticalSetionBegin( void )
{
    ldsr    r0, 31                                      /* select system register bank 0 */
                                                        /* (contains PSW) */
    stsr    0x05, r7                                    /* load PSW (register 5) */
    mov     #_PSWSafe, r6                               /* backup PSW */
    st.w    r7, 0[r6]                                   /* " */
    movea   0x00A0, r0, r6                              /* NMI Flag=1, ID=1 */
    or      r7, r6                                      /* " */
    ldsr    r6, 5                                       /* write PSW */
}
#else
/* IAR */
void FDL_User_CriticalSetionBegin( void )
{
    __asm("  ldsr    r0, 31         \n"
          "  stsr    0x05, r7       \n"
          "  mov     _PSWSafe, r6   \n"
          "  st.w    r7, 0[r6]      \n"
          "  movea   0x00A0, r0, r6 \n"
          "  or      r7, r6         \n"
          "  ldsr    r6, 5          \n"
         );
}
#endif
/*********************************************************************************************************************
 * Function name:  FDL_User_CriticalSetionEnd
 *********************************************************************************************************************/
/**
 * Function to enable Maskable / non maskable exceptions and NMI after critical code has been 
 * executed
 * 
 * @param          ---
 * @return         ---
 */  
/*********************************************************************************************************************/
#if APP_COMPILER == APP_COMP_GHS
void FDL_User_CriticalSetionEnd( void )
{
    asm( "ldsr    r0, 31" );                            /* select system register bank 0 
                                                          (contains PSW)*/
    asm( "mov     _PSWSafe, r6" );                      /* Restore PSW value */
    asm( "ld.w    0[r6], r7" );                         /* " */
    asm( "ldsr    r7, 5" );                             /* write PSW */
}
#elif APP_COMPILER == APP_COMP_REC
#pragma inline_asm FDL_User_CriticalSetionEnd
void FDL_User_CriticalSetionEnd( void )
{
    ldsr    r0, 31                                      /* select system register bank 0 
                                                          (contains PSW) */
    mov     #_PSWSafe, r6                               /* Restore PSW value */
    ld.w    0[r6], r7                                   /* " */
    ldsr    r7, 5                                       /* write PSW */
}
#else
/* IAR */
void FDL_User_CriticalSetionEnd( void )
{
    __asm("  ldsr    r0, 31         \n"
          "  mov     _PSWSafe, r6   \n"
          "  ld.w    0[r6], r7      \n"
          "  ldsr    r7, 5          \n"
         );
}
#endif

/*********************************************************************************************************************
 * Function name:  FDL_Open
 *********************************************************************************************************************/
/**
 * Function to open the FDL operation. 
 * The user modifiable function e.g. Initializes/Configures the Data Flash access
 * 
 * @param          ---
 * @return         ---
 */  
/*********************************************************************************************************************/
void FDL_Open( void )
{
    INIT_FLASHACCESS
}

/*********************************************************************************************************************
 *  Function name:  FDL_Close
 *********************************************************************************************************************/
/**
 * Function to close the FDL operation. 
 * The user modifyable function might disable Flash access, ... currently, it is empty
 * 
 * @param          ---
 * @return         ---
 */  
/*********************************************************************************************************************/
void FDL_Close( void )
{
    DISABLE_FLASHACCESS
}
