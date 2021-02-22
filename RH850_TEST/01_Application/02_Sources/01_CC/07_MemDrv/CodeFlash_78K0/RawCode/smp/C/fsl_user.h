/*==============================================================================================*/
/* Project      = Flash self-programming library, MF2 single voltage flash 78K0R/Fx3            */
/* Module       = fsl_user.h                                                                    */
/* Version      = V1.01                                                                         */
/* Date         = 23.03.2009 14:20:44                                                           */
/*==============================================================================================*/
/*                                  COPYRIGHT                                                   */
/*==============================================================================================*/
/* Copyright (c) 2009 by NEC Electronics (Europe) GmbH,                                         */
/*               a company of the NEC Electronics Corporation                                   */
/*==============================================================================================*/
/* Purpose:                                                                                     */
/*              user configurable constant/macros of the selfprogramming library                */
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


#ifndef __FSL_USER_H_INCLUDED
#define __FSL_USER_H_INCLUDED


#ifdef __FSL_USER_C
  #define EXTERN_FSL_USER
#else
  #define EXTERN_FSL_USER    extern
#endif

/*==============================================================================================*/
/* function prototypes                                                                          */
/*==============================================================================================*/
EXTERN_FSL_USER void  FSL_Open(void);
EXTERN_FSL_USER void  FSL_Close(void);


/*==============================================================================================*/
/* constant definitions                                                                         */
/*==============================================================================================*/


/* specify the CPU frequency in [Hz]                                                            */
#define   FSL_SYSTEM_FREQUENCY    24000000


/* define whether low-voltage mode is used or not                                               */
/* #define   FSL_LOW_VOLTAGE_MODE                                                               */

/* size of the common data buffer expressed in [bytes]                                          */
/* the data buffer is used for data-exchange between the firmware and the selflib.              */
#define   FSL_DATA_BUFFER_SIZE    256


/* customizable interrupt controller configuration during selfprogramming period                */
#define   FSL_MK0L_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK0H_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK1L_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK1H_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK2L_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK2H_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK3L_MASK   0xFF   /* all interrupts disabled during selfprogramming              */
#define   FSL_MK3H_MASK   0xFF   /* all interrupts disabled during selfprogramming              */

/* FLMD0 control bit                                                                            */
#define  FSL_FLMD0_HIGH   {BECTL_bit.no7 = 1;}
#define  FSL_FLMD0_LOW    {BECTL_bit.no7 = 0;}


/*----------------------------------------------------------------------------------------------*/
/* switch interrupt backu functionality ON/OFF                                                  */
/*----------------------------------------------------------------------------------------------*/
/* #define  FSL_INT_BACKUP */


#endif
