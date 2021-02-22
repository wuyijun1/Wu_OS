;=================================================================================================
; Project      = Flash self-programming library, MF2 single voltage flash 78K0R/Fx3
; Module       = fsl.inc
; Device:      = 78K0R/Fx3
; Version      = V1.01
; Date         = 23.03.2009 14:17:31
;=================================================================================================
;                                  COPYRIGHT
;=================================================================================================
; Copyright (c) 2009 by NEC Electronics (Europe) GmbH,
;               a company of the NEC Electronics Corporation
;=================================================================================================
; Purpose:
;              function interface specification for assembler projects
;
;=================================================================================================
;
; Warranty Disclaimer
;
; Because the Product(s) is licensed free of charge, there is no warranty of any kind
; whatsoever and expressly disclaimed and excluded by NEC, either expressed or implied,
; including but not limited to those for non-infringement of intellectual property,
; merchantability and/or fitness for the particular purpose. NEC shall not have any obligation
; to maintain, service or provide bug fixes for the supplied Product(s) and/or the Application.
;
; Each User is solely responsible for determining the appropriateness of using the Product(s)
; and assumes all risks associated with its exercise of rights under this Agreement,
; including, but not limited to the risks and costs of program errors, compliance with
; applicable laws, damage to or loss of data, programs or equipment, and unavailability or
; interruption of operations.
;
; Limitation of Liability
;
; In no event shall NEC be liable to the User for any incidental, consequential, indirect,
; or punitive damage (including but not limited to lost profits) regardless of whether
; such liability is based on breach of contract, tort, strict liability, breach of warranties,
; failure of essential purpose or otherwise and even if advised of the possibility of
; such damages. NEC shall not be liable for any services or products provided by third party
; vendors, developers or consultants identified or referred to the User by NEC in connection
; with the Product(s) and/or the Application.
;
;=================================================================================================
;
; Environment  = IAR environment for 78K0R (version V4.xx) 
;
;=================================================================================================


#ifdef __FSL_INC_INCLUDED

#else
#define __FSL_INC_INCLUDED




;==============================================================================================
; constant definitions                                                                         
;==============================================================================================

; status code definitions returned by the FSL functions

FSL_OK                  EQU  00H
FSL_ERR_FLMD0           EQU  01H
FSL_ERR_PARAMETER       EQU  05H
FSL_ERR_PROTECTION      EQU  010H
FSL_ERR_ERASE           EQU  01AH
FSL_ERR_BLANKCHECK      EQU  01BH
FSL_ERR_IVERIFY         EQU  01BH
FSL_ERR_WRITE           EQU  01CH
FSL_ERR_EEP_IVERIFY     EQU  01DH
FSL_ERR_EEP_BLANKCHECK  EQU  01EH
FSL_ERR_INTERRUPTION    EQU  01FH



;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      initialization of selfprogramming environment                                  
;               After initialization:                                                          
;               - the pointer to the data-buffer is stored                
;               - all timing data are re-calculated according to the used system clock         
;                                                                                              
;               CAUTION:                                                                       
;               The FSL_Init function is interruptible. Please use the           
;               FSL_Init_cont to recall it as long return status is 0x1F.        
;                                                                                              
; Input(far model):        over stack - address of data buffer of N...256 bytes                 
;                                       (used for data exchange between firmware and application)
;                                       [SP+0] = LOW( LWRD(data_buffer_addr) )
;                                       [SP+1] = HIGH( LWRD(data_buffer_addr) )
;                                       [SP+2] = LOW( HWRD(data_buffer_addr) )  
;                                       [SP+3] = HIGH( HWRD(data_buffer_addr) )  
;
;
; Input(near model):       AX - address of data buffer of N...256 bytes             
;                                 (used for data exchange between firmware and application)    
; Output:       -                                                                              
; Changed:      AX, data_buffer[0]                                                        
; Returned:     A, status code                                                                 
;                    = 0x00(FSL_OK), normal and means initialization OK                        
;                    = 0x05(FSL_ERR_PARAMETER), parameter error (not supported frequency) 
;                    = 0x1F(FSL_ERR_INTERRUPTION), initialization interrupted by user interrupt
;----------------------------------------------------------------------------------------------
 EXTERN FSL_Init
 EXTERN FSL_Init_cont


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      checks the voltage level (high or low) at FLMD0 pin                            
; Input:        -                                                                              
; Output:       -                                                                              
; Changed:      -                                                                
; Returned:     A, status code                                                           
;                    = 0x00(FSL_OK), normal and means FLMD0=HIGH                               
;                    = 0x01(FSL_ERR_FLMD0), error, FLMD0=LOW                                   
;----------------------------------------------------------------------------------------------
 EXTERN FSL_ModeCheck


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      checks if specified block is blank                                             
; Input:        AX - block number                                    
; Output:       -                                                                              
; Changed:      AX, ES
; Returned:     A, status code                                                           
;                    = 0x00(FSL_OK), normal and means "block is blank"                         
;                    = 0x05(FSL_ERR_PARAMETER), parameter error                                
;                    = 0x1B(FSL_ERR_BLANKCHECK), blank-check error, means "block not blank"    
;                    = 0x1F(FSL_ERR_INTERRUPTION), blank-check interrupted by user interrupt   
;----------------------------------------------------------------------------------------------
 EXTERN FSL_BlankCheck


;----------------------------------------------------------------------------------------------
;  Block type:   FSL command function                                                          
;----------------------------------------------------------------------------------------------
;  Purpose:      erase specified block                                                         
;  Input:        AX - block number                                      
;  Output:       -                                                                             
; Changed:       AX, ES
;  Returned:     A, status code                                                          
;                     = 0x00(FSL_OK), normal and means "block erased successfully"             
;                     = 0x05(FSL_ERR_PARAMETER), parameter error                               
;                     = 0x10(FSL_ERR_PROTECTION), tried to erase protected area                
;                     = 0x1A(FSL_ERR_ERASE), erase error        
;                     = 0x1F(FSL_ERR_INTERRUPTION), erasing interrupted by user interrupt      
;----------------------------------------------------------------------------------------------
 EXTERN FSL_Erase


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      performs internal verify on specified block                                    
; Input:        AX - block number                                   
; Output:       -                                                                              
; Changed:      AX, ES
; Returned:     A, status code                                                           
;                    = 0x00(FSL_OK), normal and means "block is verified"                      
;                    = 0x05(FSL_ERR_PARAMETER), parameter error                                
;                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            
;                    = 0x1F(FSL_ERR_INTERRUPTION), verify interrupted by user interrupt        
;----------------------------------------------------------------------------------------------
 EXTERN FSL_IVerify


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      writes N words from the data buffer into flash                                 
; Input:        AX = HIGH(address)        - starting flash address the data has to be written  
;               BC = LOW(address)           See Condition  2) please.                          
;               D  = word_count           - number of words (on word 4 bytes) has to be written
; Output:       -                                                                              
; Condition:   1) (address MOD 4 == 0)                                                   
;              2) most significant byte (MSB) of  address has to be 0x00.                
;                 Means: 0x00abcdef 24 bit flash address allowed                               
;              3) (word_count <= sizeof(data buffer))  NOT CHECKED BY LIBRARY !!!!!       
; Changed:     AX, BC, ES                                                                      
; Returned:    A, status code                                                            
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1F(FSL_ERR_INTERRUPTION), write interrupted by user interrupt          
;----------------------------------------------------------------------------------------------
 EXTERN FSL_Write


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      writes N words from the data buffer into flash                                 
;               Before "writing" a N-word blankcheck is performed.                             
;               After "writing" a N-Word internal verify is performed.                         
; Input:        AX = HIGH(address)        - starting flash address the data has to be written  
;               BC = LOW(address)           See Condition  2) please.                         
;               D  = word_count           - number of words (on word 4 bytes) has to be written
; Output:       -                                                                              
; Condition:   1) (address MOD 4 == 0)                                                   
;              2) most significant byte (MSB) of  address has to be 0x00.                
;                 Means: 0x00abcdef 24 bit flash address allowed                               
;              3) (word_count <= sizeof(data buffer))  NOT CHECKED BY LIBRARY !!!!!      
; Changed:     AX, BC, ES                                                                      
; Returned:    A, status code                                                            
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1C(FSL_ERR_WRITE), write error                                         
;                   = 0x1D(FSL_ERR_EEP_IVERIFY), verify error                                  
;                   = 0x1E(FSL_ERR_EEP_BLANKCHECK), blankcheck error                           
;                   = 0x1F(FSL_ERR_INTERRUPTION), write interrupted by user interrupt          
;----------------------------------------------------------------------------------------------
 EXTERN FSL_EEPROMWrite


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      reads the security information                              
; Input(far model):  over stack - destination address of security info    
;                                 [SP+0] = LOW( LWRD(dest_addr) ) 
;                                 [SP+1] = HIGH( LWRD(dest_addr) )
;                                 [SP+2] = LOW( HWRD(dest_addr) ) 
;                                 [SP+3] = HIGH( HWRD(dest_addr) )
;      
; Input(near model): AX - destination address of security info                                
;                                                                                              
;               Format of the security info:                                                   
;               bit_0 = 0 -> chip erase command disabled, otherwise enabled                    
;               bit_1 = 0 -> block erase command disabled, otherwise enabled                   
;               bit_2 = 0 -> write command disabled, otherwise enabled                         
;               bit_4 = 0 -> boot-area re-programming disabled, otherwise enabled              
;               bit_8...bit_15 = 03H -> last block of the boot-area                            
;               other bits = 1                                                                 
; Output:       -                                                                              
; Changed:      AX, BX and data_buffer[0], data_buffer[1]                                      
; Returned:     A, status code                                                           
;                  = 0x00(FSL_OK), normal                                                      
;                  = 0x05(FSL_ERR_PARAMETER), parameter error 
;               [destination address], security information                                  
;----------------------------------------------------------------------------------------------
 EXTERN FSL_GetSecurityFlags


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      read the boot flag i                                               
;               The value of the boot info is 0x00 for cluster 0 and 0x01 for cluster 1.    
; Input(far model):  over stack - destination address of the bootflag info     
;                                 [SP+0] = LOW( LWRD(dest_addr) )               
;                                 [SP+1] = HIGH( LWRD(dest_addr) )              
;                                 [SP+2] = LOW( HWRD(dest_addr) )               
;                                 [SP+3] = HIGH( HWRD(dest_addr) )              
;                                                                              
; Input(near model): AX - destination address of the bootflag info                           
;                    ATTENTION: the size of the destination varibale must be min. size 1 byte 
; Output:       -                                                                              
; Changed:      data_buffer[0]
; Returned:     A, status code                                                           
;                  = 0x00(FSL_OK), normal                                                      
;                  = 0x05(FSL_ERR_PARAMETER), parameter error 
;               [destination address], active bootcluster information                     
;----------------------------------------------------------------------------------------------
 EXTERN FSL_GetActiveBootCluster


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      puts the last address of the specified block into *destination_pu32           
; Input(far model):  over stack - destination where the last-block-address should be stored
;                    ATTENTION: the size of the destination varibale must be min. size 4 byte 
;                                 [SP+0] = LOW( LWRD(dest_addr) )        
;                                 [SP+1] = HIGH( LWRD(dest_addr) )       
;                                 [SP+2] = LOW( HWRD(dest_addr) )        
;                                 [SP+3] = HIGH( HWRD(dest_addr) )                           
;                                 AX - block number
;
; Input(near model): AX - destination where the last-block-address should be stored
;                    ATTENTION: the size of the destination varibale must be min. size 4 byte
;                    BC - block number
;
; Changed:     AX, data_buffer[0] to data_buffer[3]                                
; Returned:    A, status code                                                            
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;----------------------------------------------------------------------------------------------
 EXTERN FSL_GetBlockEndAddr


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:     puts the information about the protected flash area into the function parameter 
; Input(far model):  over stack - destination where the FSW start block should be stored     
;                    over stack - destination where the FSW end block should be stored 
;                                 [SP+0] = LOW( LWRD(FSW_start_block) )  
;                                 [SP+1] = HIGH( LWRD(FSW_start_block) ) 
;                                 [SP+2] = LOW( HWRD(FSW_start_block) )  
;                                 [SP+3] = HIGH( HWRD(FSW_start_block) ) 
;                                 [SP+4] = LOW( LWRD(FSW_end_block) )  
;                                 [SP+5] = HIGH( LWRD(FSW_end_block) ) 
;                                 [SP+6] = LOW( HWRD(FSW_end_block) )  
;                                 [SP+7] = HIGH( HWRD(FSW_end_block) ) 
;
; Input(near model): AX - destination where the FSW start block should be stored      
;                    BC - destination where the FSW end block should be stored
;                    ATTENTION: the size of the destination varibales must be min. size 2 byte
;
; Changed:     data_buffer[0] to data_buffer[3]                                    
; Returned:    A, status code                                                            
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;----------------------------------------------------------------------------------------------
 EXTERN FSL_GetFlashShieldWindow


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:     Inverts the security boot flag.                                                 
;                                                                                              
; Input:       -                                                                               
; Output:      -
; Changed:     data_buffer[0] to data_buffer[4]                                               
; Returned:    A, status code                                                            
;                   = 0x00(FSL_OK), normal                                                     
;                   = 0x05(FSL_ERR_PARAMETER), parameter error                                 
;                   = 0x10(FSL_ERR_PROTECTION), protection error                               
;                   = 0x1A(FSL_ERR_ERASE), erase error                                         
;                   = 0x1B(FSL_ERR_IVERIFY), internal verify error                             
;                   = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt               
;----------------------------------------------------------------------------------------------
 EXTERN FSL_InvertBootFlag



;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:     defines a new Flash-Shield-Window area inside the flash memory                  
; Input:       AX - starting block of the Flash-Shield-Window (FSW)               
;              BC - end block of the flash-Shield-Window (FSW)                 
; Changed:     data_buffer[0] to data_buffer[4]                                                
; Returned:    A, status code                                                            
;                    = 0x00(FSL_OK), normal                                                    
;                    = 0x05(FSL_ERR_PARAMETER), parameter error                                
;                    = 0x10(FSL_ERR_PROTECTION), protection error                              
;                    = 0x1A(FSL_ERR_ERASE), erase error                                        
;                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            
;                    = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt               
;----------------------------------------------------------------------------------------------
 EXTERN FSL_SetFlashShieldWindow


;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:      sets specified security flag by dedicated command-function.                    
;                                                                                              
;               There are following security levels:                                           
;               a) chip-erase protection   (cannot be reset by programmer !!!)                 
;               b) block-erase protection  (can be reset by chip-erase on programmer)          
;               c) write protection        (can be reset by chip-erase on programmer)          
;               d) boot-cluster protection (cannot be reset by programmer !!!)                 
;                                                                                              
;               CAUTION !!!!                                                                   
;               1) mask all interrupts before using this commands (DI is not enough)           
;               2) each security flag can be written by the application only once              
;                                                                                              
; Input:        -                                                                              
; Output:       - 
; Changed:      data_buffer[0] to data_buffer[4]                                           
; Returned:     A, status code                                                           
;                    = 0x00(FSL_OK), normal                                                    
;                    = 0x05(FSL_ERR_PARAMETER), parameter error                                
;                    = 0x10(FSL_ERR_PROTECTION), protection error                              
;                    = 0x1A(FSL_ERR_ERASE), erase error                                        
;                    = 0x1B(FSL_ERR_IVERIFY), internal verify error                            
;                    = 0x1F(FSL_ERR_INTERRUPTION), interrupted by user interrupt               
;----------------------------------------------------------------------------------------------
 EXTERN FSL_SetChipEraseProtectFlag
 EXTERN FSL_SetBlockEraseProtectFlag
 EXTERN FSL_SetWriteProtectFlag
 EXTERN FSL_SetBootClusterProtectFlag





;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:     Swap physically boot cluster 0 and boot cluster 1 without setting               
;              the security flag. After swap the library jumps to the address of the           
;              reset vector.                                                                   
;              CAUTION:  After reset the boot cluster will be switched                         
;                        regarding the security flag.                                          
;                                                                                              
;                                                                                              
; Input:       -                                                                               
; Output:      -                                                                               
; Changed:     AX, BC, ES, CS, and data_buffer[0] to data_buffer[61]                           
; Returned:    A, status code                                                           
;                    = 0x00(FSL_OK), normal                                                    
;                    = 0x10(FSL_ERR_PROTECTION), protection error
;----------------------------------------------------------------------------------------------

 EXTERN FSL_SwapBootCluster



;----------------------------------------------------------------------------------------------
; Block type:   FSL command function                                                           
;----------------------------------------------------------------------------------------------
; Purpose:     Forces a hardware reset via illegal instruction                                 
;                                                                                              
; Input:       -                                                                               
; Output:      - 
; Changed:     -                                                                              
; Returned:    -                                                                               
;----------------------------------------------------------------------------------------------
 EXTERN FSL_ForceReset 
 
 

;----------------------------------------------------------------------------------------------
; Block type:   FSL function                                                                   
;----------------------------------------------------------------------------------------------
; Purpose:     This function forces to leave the running FSL_XXX function as                   
;              fast as possible. It must be called only inside ISRs.                           
; Input:       -  
; Output:      -                                                                              
; Changed:     -                                                                               
; Returned:    -                                                                               
;----------------------------------------------------------------------------------------------
 EXTERN FSL_SetInterruptMode






#endif
