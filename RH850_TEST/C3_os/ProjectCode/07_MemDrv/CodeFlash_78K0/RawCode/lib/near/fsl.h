/*==============================================================================================*/
/* Project      = Flash self-programming library, MF2 single voltage flash 78K0R/Fx3            */
/* Module       = fsl.h                                                                         */
/* Version      = V1.01                                                                         */
/* Date         = 23.03.2009 14:28:14                                                           */
/*==============================================================================================*/
/*                                  COPYRIGHT                                                   */
/*==============================================================================================*/
/* Copyright (c) 2009 by NEC Electronics (Europe) GmbH,                                         */
/*               a company of the NEC Electronics Corporation                                   */
/*==============================================================================================*/
/* Purpose:                                                                                     */
/*              constant, type and function prototype definitions used by the FSL               */
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

#ifndef __FSL_H_INCLUDED
#define __FSL_H_INCLUDED


/*==============================================================================================*/
/* FSL type definitions                                                                         */
/*==============================================================================================*/
typedef unsigned char       fsl_u08;
typedef unsigned int        fsl_u16;
typedef unsigned long int   fsl_u32;


/*==============================================================================================*/
/* constant definitions                                                                         */
/*==============================================================================================*/

/*status code definitions returned by the FSL functions                                         */
#define   FSL_OK                    0x00
#define   FSL_ERR_FLMD0             0x01
#define   FSL_ERR_PARAMETER         0x05
#define   FSL_ERR_PROTECTION        0x10
#define   FSL_ERR_ERASE             0x1A
#define   FSL_ERR_BLANKCHECK        0x1B
#define   FSL_ERR_IVERIFY           0x1B
#define   FSL_ERR_WRITE             0x1C
#define   FSL_ERR_EEP_IVERIFY       0x1D
#define   FSL_ERR_EEP_BLANKCHECK    0x1E
#define   FSL_ERR_INTERRUPTION      0x1F


/*==============================================================================================*/
/* global function prototypes                                                                   */
/*==============================================================================================*/


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      initialization of selfprogramming environment                                  */
/*               After initialization:                                                          */
/*               - the pointer to the data-buffer is stored                                     */
/*               - all timing data are re-calculated according to the used system clock         */
/*                                                                                              */
/*               CAUTION:                                                                       */
/*               The FSL_Init(&data_buffer) function is interruptible. Please use the           */
/*               FSL_Init_cont(&data_buffer) to recall it as long return status is 0x1F.        */
/*                                                                                              */
/* Input:        data_buffer_pu08 - pointer to a data buffer of N...256 bytes                   */
/*                                 (used for data exchange between firmware and application)    */
/* Output:       -                                                                              */
/* Changed:      data_buffer[0]                                                                 */
/* Returned:     u08, status_code                                                               */
/*                    = 0x00(FSL_OK), normal and means initialization OK                        */
/*                    = 0x05(FSL_ERR_PARAMETER), parameter error (not supported frequency)      */
/*                    = 0x1F(FSL_ERR_INTERRUPTION), initialization interrupted by user interrupt*/
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_Init(fsl_u08* data_buffer_pu08);
extern fsl_u08  FSL_Init_cont(fsl_u08* data_buffer_pu08);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      checks the voltage level (high or low) at FLMD0 pin                            */
/* Input:        -                                                                              */
/* Output:       -                                                                              */
/* Changed:      -                                                                              */
/* Returned:     fsl_u08, status_code                                                           */
/*                    = 0x00(FSL_OK), normal and means FLMD0=HIGH                               */
/*                    = 0x01(FSL_ERR_FLMD0), error, FLMD0=LOW                                   */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_ModeCheck(void);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      checks if specified block is blank                                             */
/* Input:        block_u16 - block number has to be checked                                     */
/* Output:       -                                                                              */
/* Changed:      -                                                                              */
/* Returned:     fsl_u08, status_code                                                           */
/*                    = 0x00(FSL_OK), normal and means "block is blank"                         */
/*                    = 0x05(FSL_ERR_PARAMETER), parameter error                                */
/*                    = 0x1B(FSL_ERR_BLANKCHECK), blank-check error, means "block not blank"    */
/*                    = 0x1F(FSL_ERR_INTERRUPTION), blank-check interrupted by user interrupt   */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_BlankCheck(fsl_u16 block_u16);


/*----------------------------------------------------------------------------------------------*/
/*  Block type:   FSL command function                                                          */
/*----------------------------------------------------------------------------------------------*/
/*  Purpose:      erase specified block                                                         */
/*  Input:        block_u16 - block number has to be erase                                      */
/*  Output:       -                                                                             */
/*  Changed:      -                                                                             */
/*  Returned:     fsl_u08, status_code                                                          */
/*                     = 0x00(FSL_OK), normal and means "block erased successfully"             */
/*                     = 0x05(FSL_ERR_PARAMETER), parameter error                               */
/*                     = 0x10(FSL_ERR_PROTECTION), tried to erase protected area                */
/*                     = 0x1A(FSL_ERR_ERASE), erase error                                       */
/*                     = 0x1F(FSL_ERR_INTERRUPTION), erasing interrupted by user interrupt      */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_Erase(fsl_u16 block_u16);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      performs internal verify on specified block                                    */
/* Input:        block_u16 - block number has to be verified                                    */
/* Output:       -                                                                              */
/* Changed:      -                                                                              */
/* Returned:     fsl_u08, status_code                                                           */
/*                    = 0x00(FSL_OK), normal and means "block is verified"                      */
/*                    = 0x05(FSL_ERR_PARAMETER), parameter error                                */
/*                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            */
/*                    = 0x1F(FSL_ERR_INTERRUPTION), verify interrupted by user interrupt        */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_IVerify(fsl_u16 block_u16);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      writes N words from the data buffer into flash                                 */
/* Input:        s_address_u32 - starting flash address the data has to be written              */
/*                               See Condition  2) please.                                      */
/*               my_wordcount_u08  - number of words (4 bytes) has to be written                */
/* Output:       -                                                                              */
/* Condition:   1) (s_address_u32 MOD 4 == 0)                                                   */
/*              2) most significant byte (MSB) of  s_address_u32 has to be 0x00.                */
/*                 Means: 0x00abcdef 24 bit flash address allowed                               */
/*              3) (word_count_u08 <= sizeof(data buffer))  NOT CHECKED BY LIBRARY  !!!!!       */
/* Changed:     -                                                                               */
/* Returned:    fsl_u08, status code                                                            */
/*                   = 0x00(FSL_OK), normal                                                     */
/*                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 */
/*                   = 0x10(FSL_ERR_PROTECTION), protection error                               */
/*                   = 0x1C(FSL_ERR_WRITE), write error                                         */
/*                   = 0x1F(FSL_ERR_INTERRUPTION), write interrupted by user interrupt          */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_Write(fsl_u32 s_address_u32, fsl_u08 word_count_u08);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      writes N words from the data buffer into flash                                 */
/*               Before "writing" a N-word blankcheck is performed.                             */
/*               After "writing" a N-Word internal verify is performed.                         */
/* Input:        s_address_u32 - starting destination address has to be written                 */
/*               my_wordcount_u08  - number of words (4 bytes) has to be written                */
/* Output:       -                                                                              */
/* Condition:   1) (s_address_u32 MOD 4 == 0)                                                   */
/*              2) (word_count_u08 <= sizeof(data buffer))  NOT CHECKED BY FIRMWARE !!!!!       */
/* Changed:     -                                                                               */
/* Returned:    fsl_u08, status code                                                            */
/*                   = 0x00(FSL_OK), normal                                                     */
/*                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 */
/*                   = 0x10(FSL_ERR_PROTECTION), protection error                               */
/*                   = 0x1C(FSL_ERR_WRITE), write error                                         */
/*                   = 0x1D(FSL_ERR_EEP_IVERIFY), verify error                                  */
/*                   = 0x1E(FSL_ERR_EEP_BLANKCHECK), blankcheck error                           */
/*                   = 0x1F(FSL_ERR_INTERRUPTION), write interrupted by user interrupt          */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_EEPROMWrite(fsl_u32 s_address_u32, fsl_u08 word_count_u08);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      reads the security information                                                 */
/* Input:        destination_pu16 - destination address of the security info                    */
/*               The format of the security info is: "unsigned short int"                       */
/*                                                                                              */
/*               Format of the security info:                                                   */
/*               bit_0 = 0 -> chip erase command disabled, otherwise enabled                    */
/*               bit_1 = 0 -> block erase command disabled, otherwise enabled                   */
/*               bit_2 = 0 -> write command disabled, otherwise enabled                         */
/*               bit_4 = 0 -> boot-area re-programming disabled, otherwise enabled              */
/*               bit_8...bit_15 = 03H -> last block of the boot-area                            */
/*               other bits = 1                                                                 */
/* Output:       -                                                                              */
/* Changed:      data_buffer[0], data_buffer[1]                                                 */
/* Returned:     fsl_u08, status code                                                           */
/*                  = 0x00(FSL_OK), normal                                                      */
/*                  = 0x05(FSL_ERR_PARAMETER), parameter error                                  */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_GetSecurityFlags(fsl_u16* destination_pu16);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      read the boot flag i                                                           */
/* Input:        destination_pu08 - destination address of the bootflag info                    */
/*               The format of the boot-flag info is: "unsigned char"                           */
/*               The value of the boot info is 0x00 for cluster 0 and 0x01 for cluster 1.       */
/* Output:       -                                                                              */
/* Changed:      data_buffer[0]                                                                 */
/* Returned:     fsl_u08, status code                                                           */
/*                  = 0x00(FSL_OK), normal                                                      */
/*                  = 0x05(FSL_ERR_PARAMETER), parameter error                                  */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_GetActiveBootCluster(fsl_u08* destination_pu08);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     puts the last address of the specified block into *destination_pu32             */
/* Input:       *destination_pu32 - destination where the last-block-address                    */
/*                                  should be stored                                            */
/*              block_u16         - block number of the last address is needed                  */
/* Changed:     data_buffer[0] to data_buffer[3]                                                */
/* Returned:    fsl_u08, status code                                                            */
/*                   = 0x00(FSL_OK), normal                                                     */
/*                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_GetBlockEndAddr(fsl_u32* destination_pu32, fsl_u16 block_u16);


/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     puts the information about the protected flash area into the function parameter */
/* Input:       *start_block_pu16 - destination where the FSW start block should be stored      */
/*              *end_block_pu16   - destination where the FSW end block should be stored        */
/* Changed:     data_buffer[0] to data_buffer[3]                                                */
/* Returned:    fsl_u08, status code                                                            */
/*                   = 0x00(FSL_OK), normal                                                     */
/*                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_GetFlashShieldWindow(fsl_u16* start_block_pu16, fsl_u16* end_block_pu16);



/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     Inverts the security boot flag.                                                 */
/*                                                                                              */
/* Input:       -                                                                               */
/* Output:      -                                                                               */
/* Changed:     data_buffer[0] to data_buffer[4]                                                */
/* Returned:    fsl_u08, status code                                                            */
/*                   = 0x00(FSL_OK), normal                                                     */
/*                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 */
/*                   = 0x10(FSL_ERR_PROTECTION), protection error                               */
/*                   = 0x1A(FSL_ERR_ERASE), erase error                                         */
/*                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             */
/*                   = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt                */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_InvertBootFlag(void);




/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     defines a new Flash-Shield-Window area inside the flash memory                  */
/* Input:       start_block_u16 - starting block of the Flash-Shield-Window (FSW)               */
/*              end_block_u16   - ending block of the flash-Shield-Window (FSW)                 */
/* Changed:     data_buffer[0] to data_buffer[4]                                                */
/* Returned:    fsl_u08, status code                                                            */
/*                    = 0x00(FSL_OK), normal                                                    */
/*                    = 0x05(FSL_ERR_PARAMETER), parameter error                                */
/*                    = 0x10(FSL_ERR_PROTECTION), protection error                              */
/*                    = 0x1A(FSL_ERR_ERASE), erase error                                        */
/*                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            */
/*                    = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt               */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_SetFlashShieldWindow(fsl_u16 start_block_u16, fsl_u16 end_block_u16);





/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:      sets specified security flag by dedicated command-function.                    */
/*                                                                                              */
/*               There are following security levels:                                           */
/*               a) chip-erase protection   (cannot be reset by programmer !!!)                 */
/*               b) block-erase protection  (can be reset by chip-erase on programmer)          */
/*               c) write protection        (can be reset by chip-erase on programmer)          */
/*               d) boot-cluster protection (cannot be reset by programmer !!!)                 */
/*                                                                                              */
/*               CAUTION !!!!                                                                   */
/*               1) mask all interrupts before using this commands (DI is not enough)           */
/*               2) each security flag can be written by the application only once              */
/*                                                                                              */
/* Input:        -                                                                              */
/* Output:       -                                                                              */
/* Changed:      data_buffer[0] to data_buffer[4]                                               */
/* Returned:     fsl_u08, status code                                                           */
/*                    = 0x00(FSL_OK), normal                                                    */
/*                    = 0x05(FSL_ERR_PARAMETER), parameter error                                */
/*                    = 0x10(FSL_ERR_PROTECTION), protection error                              */
/*                    = 0x1A(FSL_ERR_ERASE), erase error                                        */
/*                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            */
/*                    = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt               */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08  FSL_SetChipEraseProtectFlag(void);
extern fsl_u08  FSL_SetBlockEraseProtectFlag(void);
extern fsl_u08  FSL_SetWriteProtectFlag(void);
extern fsl_u08  FSL_SetBootClusterProtectFlag(void);





/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     Swap physically boot cluster 0 and boot cluster 1 without setting               */
/*              the security flag. After swap the library jumps to the address of the           */
/*              reset vector.                                                                   */
/*              CAUTION:  After reset the boot cluster will be switched                         */
/*                        regarding the security flag.                                          */
/*                                                                                              */
/*                                                                                              */
/* Input:       -                                                                               */
/* Output:      -                                                                               */
/* Changed:     data_buffer[0] to data_buffer[61]                                               */
/* Returned:    fsl_u08, status code                                                            */
/*                    = 0x00(FSL_OK), normal                                                    */
/*                    = 0x10(FSL_ERR_PROTECTION), protection error                              */
/*----------------------------------------------------------------------------------------------*/
extern fsl_u08 FSL_SwapBootCluster(void);




/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL command function                                                           */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     Forces a hardware reset via illegal instruction                                 */
/*                                                                                              */
/* Input:       -                                                                               */
/* Output:      -                                                                               */
/* Changed:     -                                                                               */
/* Returned:    -                                                                               */
/*----------------------------------------------------------------------------------------------*/
extern void FSL_ForceReset(void);




/*----------------------------------------------------------------------------------------------*/
/* Block type:   FSL function                                                                   */
/*----------------------------------------------------------------------------------------------*/
/* Purpose:     This function forces to leave the running FSL_XXX function as                   */
/*              fast as possible. It must be called only inside ISRs.                           */
/* Input:       -                                                                               */
/* Changed:     -                                                                               */
/* Returned:    -                                                                               */
/*----------------------------------------------------------------------------------------------*/
extern void  FSL_SetInterruptMode(void);

#endif
