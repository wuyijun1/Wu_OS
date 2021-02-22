/*********************************************************************************************************************
 * File Name     : $Source: fdlapp_main.c $
 * Mod. Revision : $Revision: 1.7 $
 * Mod. Date     : $Date: 2014/09/10 16:24:34MESZ $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Application sample main module
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
#define EEELIB_INTDEF
#include "r_typedefs.h"
#include "target.h"
#include "fdl_user.h"

/*********************************************************************************************************************
 * External Function headers
 *********************************************************************************************************************/
void SampleApp_FDL_Control ( void );


/*********************************************************************************************************************
 * Function name:  main
 *********************************************************************************************************************/
/**
 * main function
 *
 * @param          ---
 * @return         ---
 */
/*********************************************************************************************************************/
void main (void)
{
    /*****************************************************************************************************************
     * CPU initialization
     *****************************************************************************************************************/
    /* Initialize the CPU and Peripheral clock system */
    INIT_CPU_AND_FPERIPHERAL_CLK

    #if (defined R_FDL_DEVICE_SPECIFIC_INIT)
        /* Some older devices like F1L WS2.0 need Flash authentication prior to switch mode */
        R_FDL_DEVICE_SPECIFIC_INIT;
    #endif

    /*****************************************************************************************************************
     * Open the FDL / Data Flash access
     *****************************************************************************************************************/
    /* Initialize the data FLash is required to be able to access the data Flash. As this is considered to be a user
       function, it is not part of the libraries, but part of the application sample */
    FDL_Open ();

    /*****************************************************************************************************************
     * Call sample functions
     *****************************************************************************************************************/
    /* Sample of FDL handling */
    SampleApp_FDL_Control ();

    /*****************************************************************************************************************
     * Close the FDL / Data Flash access
     *****************************************************************************************************************/
    FDL_Close ();

    /*****************************************************************************************************************
     * Wait forever
     *****************************************************************************************************************/
    while (1)
    {
        ;
    }

    /* Not reachable */
} /* main */

