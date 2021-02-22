/*********************************************************************************************************************
 * File Name     : $Source: fdl_descriptor.c $
 * Mod. Revision : $Revision: 1.11 $
 * Mod. Date     : $Date: 2016/05/31 16:15:26JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Descriptor variable definition
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


/*********************************************************************************************************************
 * FDL header files include
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "r_fdl.h"
#include "fdl_descriptor.h"

/*********************************************************************************************************************
 * FDL descriptor variable definition
 *********************************************************************************************************************/
/**< FDL descriptor structure */
const r_fdl_descriptor_t  sampleApp_fdlConfig_enu = 
{
    CPU_FREQUENCY_MHZ,      /**< CPU frequency in MHz */                  
    FDL_POOL_SIZE,          /**< Number of Data Flash blocks, accessible by the FDL.
                                 Typically no. of available Data Flash blocks */   
    EEL_POOL_START,         /**< 1st block of the EEL pool */                                  
    EEL_POOL_SIZE           /**< Number of blocks in the EEL pool */        
};                            
