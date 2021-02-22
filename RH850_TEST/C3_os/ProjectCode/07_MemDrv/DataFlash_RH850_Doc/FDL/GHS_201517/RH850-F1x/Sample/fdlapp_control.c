/*********************************************************************************************************************
 * File Name     : $Source: fdlapp_control.c $
 * Mod. Revision : $Revision: 1.9 $
 * Mod. Date     : $Date: 2016/05/31 16:15:52JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Application sample program control module
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


/*********************************************************************************************************************
 * header files include
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "r_fdl.h"
#include "fdl_descriptor.h"
#include "target.h"

/*********************************************************************************************************************
 * Module internal function prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
   Function name:  SampleApp_FDL_Control
 *********************************************************************************************************************/
/**
    EEL sample function to handle FDL functionality. Executing a set of dummy Flash operations

    @param          ---
    @return         ---
 */  
/*********************************************************************************************************************/
void SampleApp_FDL_Control( void )
{

    r_fdl_status_t            fdlRet;
    r_fdl_request_t           req;
    uint8_t wBuf_au08[0x100] =  {   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                                    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
                                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
                                    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
                                    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
                                    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 
                                    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
                                    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f 
                                };
    uint32_t rBuf_au32[0x8];    /* Read buffer must be 32bit aligned as the read operation accesses it 32bit aligned */
    volatile uint16_t data;
    
    
    /* 1st initialize the FDL */
    fdlRet = R_FDL_Init( &sampleApp_fdlConfig_enu );
    if( R_FDL_OK != fdlRet )
    {   
        /* Error handler */
        while( 1 )
            ;
    }

    #ifndef R_FDL_LIB_V1_COMPATIBILITY
        /* Prepare the environment */
        req.command_enu     = R_FDL_CMD_PREPARE_ENV;
        req.idx_u32         = 0;
        req.cnt_u16         = 0;
        req.accessType_enu  = R_FDL_ACCESS_NONE;
        R_FDL_Execute( &req );
        
        while( R_FDL_BUSY == req.status_enu )
        {
            R_FDL_Handler();
        }
        if( R_FDL_OK != req.status_enu )
        {   
            /* Error handler */
            while( 1 )
                ;
        }
    #endif


    /* -----------------------------------------------------------------------
       Example...
       Read a Word --> address 0x0004 of the Data Flash
       1) Do a blank check to distinguish if the read value is based on erased
          data or written data. We can only trust written data
       2) read the data 
       ----------------------------------------------------------------------- */   
    req.command_enu     = R_FDL_CMD_BLANKCHECK;
    req.idx_u32         = 0x40;//0x0004;
    req.cnt_u16         = 1;
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    
    if( R_FDL_OK == req.status_enu )
    {   
        /* The half word is blank... we may not read */
    }
    else if( R_FDL_ERR_BLANKCHECK == req.status_enu )
    {
        /* Read the data */
        data = (*(uint16_t*)0xff200040/*0xff200004*/);
    }
    else
    {
        /* Error handler.. on an internal error */
        while( 1 )
            ;
    }


    /* -----------------------------------------------------------------------
       Example...
       Erase Flash block 0
       ----------------------------------------------------------------------- */   
    req.command_enu     = R_FDL_CMD_ERASE;
    req.idx_u32         = 0;
    req.cnt_u16         = 1;
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        /* Error handler */
        while( 1 )
            ;
    }
    
    /* -----------------------------------------------------------------------
       Write data:
       addresses 0x00000000 - 0x0000001F
       ----------------------------------------------------------------------- */   
    req.command_enu     = R_FDL_CMD_WRITE;
    req.idx_u32         = 0x0000;
    req.cnt_u16         = 0x8;
    req.bufAddr_u32     = (uint32_t)( &wBuf_au08[0] );
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        /* Error handler */
        while( 1 )
            ;
    }

    /* -----------------------------------------------------------------------
       Read data:
       addresses 0x00000000 - 0x0000001F
       ----------------------------------------------------------------------- */   
    req.command_enu     = R_FDL_CMD_READ;
    req.idx_u32         = 0x0000;
    req.cnt_u16         = 0x8;
    req.bufAddr_u32     = (uint32_t)( &rBuf_au32[0] );
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        /* Error handler */
        while( 1 )
            ;
    }

    /* -----------------------------------------------------------------------
       Read data:
       addresses 0x00000020 - 0x00000023 
       ... Most probably resulting in ECC error
       ----------------------------------------------------------------------- */   
    req.command_enu     = R_FDL_CMD_READ;
    req.idx_u32         = 0x0020;
    req.cnt_u16         = 0x1;
    req.bufAddr_u32     = (uint32_t)( &rBuf_au32[0] );
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    
    if( ( R_FDL_ERR_ECC_SED != req.status_enu ) &&
        ( R_FDL_ERR_ECC_DED != req.status_enu ) )
    {   
        /* Error handler */
        while( 1 )
            ;
    }
  
    return;
}
