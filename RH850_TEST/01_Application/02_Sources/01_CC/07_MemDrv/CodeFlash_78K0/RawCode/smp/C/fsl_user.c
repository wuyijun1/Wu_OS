/*==============================================================================================*/
/* Project      = Flash self-programming library, MF2 single voltage flash 78K0R/Fx3            */
/* Module       = fsl_user.c                                                                    */
/* Version      = V1.01                                                                         */
/* Date         = 23.03.2009 14:21:07                                                           */
/*==============================================================================================*/
/*                                  COPYRIGHT                                                   */
/*==============================================================================================*/
/* Copyright (c) 2009 by NEC Electronics (Europe) GmbH,                                         */
/*               a company of the NEC Electronics Corporation                                   */
/*==============================================================================================*/
/* Purpose:                                                                                     */
/*              contains the user defined part of the Self-Programming library                  */
/*                                                                                              */
/*==============================================================================================*/
/*                                                                                              */
/* Warranty Disclaimer                                                                          */
/*                                                                                              */
/* Because the Product(s) is licensed free of charge, there is no warranty of any kind          */
/* whatsoever and expressly disclaimed and excluded by NEC, either expressed or implied,        */
/* including but not limited to those for non-infringement of intellectual property,            */
/* merchantability and/or fitness for the particular purpose. NEC shall not have any obligation */
/* to maintain, service or provide bug fixes for the supplied Product(s) and/or the Application.*/
/*                                                                                              */
/* Each User is solely responsible for determining the appropriateness of using the Product(s)  */
/* and assumes all risks associated with its exercise of rights under this Agreement,           */
/* including, but not limited to the risks and costs of program errors, compliance with         */
/* applicable laws, damage to or loss of data, programs or equipment, and unavailability or     */
/* interruption of operations.                                                                  */
/*                                                                                              */
/* Limitation of Liability                                                                      */
/*                                                                                              */
/* In no event shall NEC be liable to the User for any incidental, consequential, indirect,     */
/* or punitive damage (including but not limited to lost profits) regardless of whether         */
/* such liability is based on breach of contract, tort, strict liability, breach of warranties, */
/* failure of essential purpose or otherwise and even if advised of the possibility of          */
/* such damages. NEC shall not be liable for any services or products provided by third party   */
/* vendors, developers or consultants identified or referred to the User by NEC in connection   */
/* with the Product(s) and/or the Application.                                                  */
/*                                                                                              */
/*==============================================================================================*/
/* Environment: IAR environment for 78K0R (version V4.xx)                                       */
/*==============================================================================================*/

/*==============================================================================================*/
/* compiler settings                                                                            */
/*==============================================================================================*/
#pragma language = default

/*==============================================================================================*/
/* include files list                                                                           */
/*==============================================================================================*/
#define __FSL_USER_C
  #include "fsl.h"
  #include "fsl_user.h"
#undef  __FSL_USER_C


/*==============================================================================================*/
/* include device information                                                                   */
/*==============================================================================================*/
#include	"io78f1845_a0.h"      
#include	"io78f1845_a0_ext.h" 


/*==============================================================================================*/
/* data definition                                                                              */
/*==============================================================================================*/

/*----------------------------------------------------------------------------------------------*/
/* set location context to FSL_UDAT data segment                                                */
/*----------------------------------------------------------------------------------------------*/
#pragma dataseg="FSL_UDAT"

/*----------------------------------------------------------------------------------------------*/
/* data buffer for data exchange between application and firmware                               */
/*----------------------------------------------------------------------------------------------*/
#if (FSL_DATA_BUFFER_SIZE>0)
  __no_init  fsl_u08  fsl_data_buffer[FSL_DATA_BUFFER_SIZE];
#endif

#ifdef   FSL_INT_BACKUP
  static  fsl_u08   fsl_MK0L_bak_u08;           /*    if (interrupt backup required)            */
  static  fsl_u08   fsl_MK0H_bak_u08;           /*    {                                         */
  static  fsl_u08   fsl_MK1L_bak_u08;           /*      reserve space for backup information    */
  static  fsl_u08   fsl_MK1H_bak_u08;           /*      of interrupt mask flags                 */
  static  fsl_u08   fsl_MK2L_bak_u08;           /*                                              */
  static  fsl_u08   fsl_MK2H_bak_u08;           /*                                              */
  static  fsl_u08   fsl_MK3L_bak_u08;           /*                                              */
  static  fsl_u08   fsl_MK3H_bak_u08;           /*    }                                         */
#endif

/*----------------------------------------------------------------------------------------------*/
/* set location context to standard data segment                                                */
/*----------------------------------------------------------------------------------------------*/
#pragma dataseg=default

/*----------------------------------------------------------------------------------------------*/
/* set location context to FSL_UCOD code segment                                                */
/*----------------------------------------------------------------------------------------------*/
#pragma location="FSL_UCOD"

/*----------------------------------------------------------------------------------------------*/
/* create and enter "user room" for the self-programming                                        */
/*----------------------------------------------------------------------------------------------*/
void FSL_Open(void)
{
  /* save the configuration of the interrupt controller and set */
  #ifdef   FSL_INT_BACKUP
    fsl_MK0L_bak_u08 = MK0L;                  /* if (interrupt backup required)                 */
    fsl_MK0H_bak_u08 = MK0H;                  /* {                                              */
    fsl_MK1L_bak_u08 = MK1L;                  /*                                                */
    fsl_MK1H_bak_u08 = MK1H;                  /*        save interrupt controller               */
    fsl_MK2L_bak_u08 = MK2L;                  /*        configuration                           */
    fsl_MK2H_bak_u08 = MK2H;                  /*                                                */
    fsl_MK3L_bak_u08 = MK3L;                  /*                                                */
    fsl_MK3H_bak_u08 = MK3H;                  /*                                                */
    MK0L = FSL_MK0L_MASK;                     /*                                                */
    MK0H = FSL_MK0H_MASK;                     /*                                                */
    MK1L = FSL_MK1L_MASK;                     /*        prepare interrupt controller            */
    MK1H = FSL_MK1H_MASK;                     /*        for selfprogramming                     */
    MK2L = FSL_MK2L_MASK;                     /*                                                */
    MK2H = FSL_MK2H_MASK;                     /*                                                */
    MK3L = FSL_MK3L_MASK;                     /*                                                */
    MK3H = FSL_MK3H_MASK;                     /* }                                              */
 #endif


  /* switch FLMD0 to HIGH       */
  FSL_FLMD0_HIGH;

  /* USER ROOM:                                                                                 */
  /* ..... Room for user specific code necessary for opening a selfrogramming session.          */
  /* ..... For example interface used for application update can be activated here.             */
  /* .....                                                                                      */

}

/*----------------------------------------------------------------------------------------------*/
/* set location context to FSL_UCOD code segment                                                */
/*----------------------------------------------------------------------------------------------*/
#pragma location="FSL_UCOD"  

/*----------------------------------------------------------------------------------------------*/
/* leave the "user room" and restore previous conditions                                        */
/*----------------------------------------------------------------------------------------------*/
void FSL_Close(void)
{

  /* USER ROOM:                                                                                 */
  /* ..... Room for user specific code necessary for closing a selfrogramming session.          */
  /* ..... For example interface used for application update can be deactivated here.           */
  /* .....                                                                                      */


  /* switch FLMD0 to LOW        */
  FSL_FLMD0_LOW;

  /* restore the configuration of the interrupt controller if backup required                   */
  #ifdef   FSL_INT_BACKUP
    MK0L = fsl_MK0L_bak_u08;                  /*   do{                                          */
    MK0H = fsl_MK0H_bak_u08;                  /*        restore interrupt controller            */
    MK1L = fsl_MK1L_bak_u08;                  /*        configuration                           */
    MK1H = fsl_MK1H_bak_u08;                  /*                                                */
    MK2L = fsl_MK2L_bak_u08;                  /*                                                */
    MK2H = fsl_MK2H_bak_u08;                  /*                                                */
    MK3L = fsl_MK3L_bak_u08;                  /*                                                */
    MK3H = fsl_MK3H_bak_u08;                  /*   }                                            */
  #endif
}


/*----------------------------------------------------------------------------------------------*/
/* DO NOT CHANGE/DELETE THE FOLLOWING CODE  !!!!!!                                              */
/*----------------------------------------------------------------------------------------------*/

 /* calculate f_MHz = round-up(FSL_SYSTEM_FREQUENCY)   */
 #define fsl_fx_MHz_c08 (FSL_SYSTEM_FREQUENCY+999999)/1000000

 /* frequency as ROM constant  */
 /* -------------------------  */

 #pragma location="FSL_CNST"
 const fsl_u08 fsl_fx_MHz_u08   =  fsl_fx_MHz_c08;
   
#ifndef FSL_LOW_VOLTAGE_MODE
  const fsl_u08 fsl_low_voltage_u08   =  0x00; 
#else
  const fsl_u08 fsl_low_voltage_u08   =  0x01; 
#endif
