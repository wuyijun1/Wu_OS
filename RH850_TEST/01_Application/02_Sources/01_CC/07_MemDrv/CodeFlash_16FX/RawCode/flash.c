/******************************************************************************
 * $Revision$
 * $Date$
 *****************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)                */
/*                                                                           */
/* The following software deliverable is intended for and must only be       */
/* used for reference and in an evaluation laboratory environment.           */
/* It is provided on an as-is basis without charge and is subject to         */
/* alterations.                                                              */
/* It is the user’s obligation to fully test the software in its             */
/* environment and to ensure proper functionality, qualification and         */
/* compliance with component specifications.                                 */
/*                                                                           */
/* In the event the software deliverable includes the use of open            */
/* source components, the provisions of the governing open source            */
/* license agreement shall apply with respect to such software               */
/* deliverable.                                                              */
/* FSEU does not warrant that the deliverables do not infringe any           */
/* third party intellectual property right (IPR). In the event that          */
/* the deliverables infringe a third party IPR it is the sole                */
/* responsibility of the customer to obtain necessary licenses to            */
/* continue the usage of the deliverable.                                    */
/*                                                                           */
/* To the maximum extent permitted by applicable law FSEU disclaims all      */
/* warranties, whether express or implied, in particular, but not            */
/* limited to, warranties of merchantability and fitness for a               */
/* particular purpose for which the deliverable is not designated.           */
/*                                                                           */
/* To the maximum extent permitted by applicable law, FSEU’s liability       */
/* is restricted to intentional misconduct and gross negligence.             */
/* FSEU is not liable for consequential damages.                             */
/*                                                                           */
/* (V1.5)                                                                    */
/*****************************************************************************/
/** \file empty.c
 **
 ** Add description here...
 **
 ** History:
 **   - 2012-01-26  1.00  CEy  First version 
 *****************************************************************************/


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "mcu.h"
#include "base_types.h"
#include "flash.h"


/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define DQ7 0x80          // Data polling flag
#define DQ5 0x20          // Time limit exceeding flag
#define DQ3 0x08          // Sector erase timer flag

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
static void ResetFlash(uint32_t u32Address);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static boolean_t m_bWriteDisabledOnce = FALSE;
static boolean_t m_bWriteEnabled      = FALSE;

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

// In this example, all functions in this module will be linked to Bank A of Flash A
// so that they can operate on Bank B of Flash A without the need to copy the
// functions to RAM and execute them from there
// Also refer linker project settings to see how this section is assigned to Bank A
#pragma segment FAR_CODE=my_flash_programming_code, attr=CODE



/**
 ******************************************************************************
 ** Enables erasing/writing of all Flash sectors
 **
 ** \retval Ok                Flash can be written/erased now 
 ** \retval ErrorInvalidMode  Flash could not be enabled for writing 
 *****************************************************************************/
en_result_t Flash_EnableWriting(void)
{
    // If the write access has been disabled during run-time, it cannot
    // be enabled again until next rest
    if (m_bWriteDisabledOnce == TRUE)
    {
        return ErrorInvalidMode;
    }
    
    DFWC0A = 0x1f;
    DFWC1A = 0xc0;
    DFCA_WE = 1;
    DFCA_CSWE = 1;
    
    m_bWriteEnabled = TRUE;

    return Ok;
}


/**
 ******************************************************************************
 ** Disables erasing/writing of all Flash sectors temporarily
 **
 ** \return none
 *****************************************************************************/
void Flash_DisableWriting(void)
{
    DFCA_WE = 0;
    DFCA_CSWE = 0;
    
    m_bWriteEnabled = FALSE;
}


/**
 ******************************************************************************
 ** Disables erasing/writing of all Flash sectors permanently because
 ** DFWC0A / DFWC1A registers are reset to '0' and cannot be set again until
 ** next MCU reset
 **
 ** \return none
 *****************************************************************************/
void Flash_DisableWritingPermanently(void)
{
    DFWC0A = 0x00;
    DFWC1A = 0x00;
    DFCA_WE = 0;
    DFCA_CSWE = 0;
    
    m_bWriteEnabled = FALSE;
    m_bWriteDisabledOnce = TRUE;
}


/**
 ******************************************************************************
 ** Writes a 8-bit value to the specified address
 **
 ** \param u32Address                 Address to be programmed
 ** \param u8Data                     Value to be programmed
 **
 ** \retval Ok                        Value was programmed successfully
 ** \retval Error                     Value could not be programmed
 ** \retval ErrorInvalidMode          Writing is not enabled or CS not idle
 ** \retval ErrorOperationInProgress  CS not idle
 *****************************************************************************/
en_result_t Flash_Write8(uint32_t u32Address, uint8_t u8Data)
{
    // Check if writing was enabled beforehand
    if (m_bWriteEnabled == FALSE)
    {
        return ErrorInvalidMode;
    }
    
    // Check if Command Sequencer is idle
    if (DFSA_ST != 0)
    {
        return ErrorInvalidMode;
    }
    
    // Clear all status flags
    DFISA = 0x00;
    
	// Program the value
	*((__far volatile uint8_t *) u32Address) = u8Data;
    
    // Wait for one of the relevant status flags to be set
    while((DFISA_FININT == 0) && (DFISA_ERINT == 0))
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
    
    // Check status flags
    if (DFISA_FININT == 1)
    {
        return Ok;
    }
    else if (DFISA_ERINT == 1)
    {
        if(DFISA_HANGINT == 1)
        {
            ResetFlash(u32Address);
        }
        return Error;
    }
    else
    {
        return Error;
    }
}


/**
 ******************************************************************************
 ** Writes a 16-bit value to the specified address
 **
 ** \param u32Address                 Address to be programmed
 ** \param u16Data                    Value to be programmed
 **
 ** \retval Ok                        Value was programmed successfully
 ** \retval Error                     Value could not be programmed
 ** \retval ErrorInvalidParameter     Address is not 16-bit aligned
 ** \retval ErrorInvalidMode          Writing is not enabled or CS not idle
 ** \retval ErrorOperationInProgress  CS not idle
 *****************************************************************************/
en_result_t Flash_Write16(uint32_t u32Address, uint16_t u16Data)
{
    // Check if writing was enabled beforehand
    if (m_bWriteEnabled == FALSE)
    {
        return ErrorInvalidMode;
    }
    
    // Check if address is 16-bit aligned
    if ((u32Address & 0x1) != 0)
    {
        return ErrorInvalidParameter;
    }
    
    // Check if Command Sequencer is idle
    if (DFSA_ST != 0)
    {
        return ErrorOperationInProgress;
    }
    
    // Clear all status flags
    DFISA = 0x00;
    
    // Program the value
	*((__far volatile uint16_t *) u32Address) = u16Data;
    
    // Wait for one of the relevant status flags to be set
    while((DFISA_FININT == 0) && (DFISA_ERINT == 0))
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
    
    // Check status flags
    if (DFISA_FININT == 1)
    {
        return Ok;
    }
    else if (DFISA_ERINT == 1)
    {
        if(DFISA_HANGINT == 1)
        {
            ResetFlash(u32Address);
        }
        return Error;
    }
    else
    {
        return Error;
    }
}


/**
 ******************************************************************************
 ** Erases the specified sector
 **
 ** \param u32SectorAddress    Any address in the sector to be erased
 **
 ** \retval Ok                 Sector erase was successful
 ** \retval ErrorTimeout       Time-out occured while erasing the sector
 ** \retval ErrorInvalidMode   Writing is not enabled
 *****************************************************************************/
en_result_t Flash_SectorErase(uint32_t u32SectorAddress)
{
    __far volatile uint8_t * pu8Sector;
    en_result_t enRetVal;
    
    // Check if writing was enabled beforehand
    if (m_bWriteEnabled == FALSE)
    {
        return ErrorInvalidMode;
    }
    
    // Command Sequencer must be disabled in order to execute the sector erase command sequences
    DFCA_CSWE = 0;
    
    // Ensure 0 at low nibbles because the "special command address offsets" will be added later
    u32SectorAddress &= 0xfffff000;
    // For better readability
    pu8Sector = (__far volatile uint8_t *) u32SectorAddress;
    
    // Execute the sector erase command sequence
    *(pu8Sector + 0xaaa) = 0xaa;
    *(pu8Sector + 0x554) = 0x55;
    *(pu8Sector + 0xaaa) = 0x80;
    *(pu8Sector + 0xaaa) = 0xaa;
    *(pu8Sector + 0x554) = 0x55;
    *(pu8Sector)         = 0x30;
    
    // Wait until sector erase starts
    while ((*pu8Sector & DQ3) != DQ3)
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
	
    while(1)
    {
        WDTCP_ = 0x00; // Watchdog clearing
        
        // Check for success
        if((*pu8Sector & DQ7) == DQ7)
        {
            enRetVal = Ok;
            break;
        }
        
        // Check time-out flag
        if((*pu8Sector & DQ5) == DQ5)
        {
            // DQ7  must be checked again because it could have been set just before
            // time-out flag is checked
            if((*pu8Sector & DQ7) == DQ7)
            {
                enRetVal = Ok;
            }
            else
            {
                ResetFlash(u32SectorAddress);
                enRetVal = ErrorTimeout;
            }
            break;
        }
    }
    
    // Command Sequencer can now be re-enabled
    DFCA_CSWE = 1;
    
    return enRetVal;
}

/**
 ******************************************************************************
 ** Executes the read/reset command to the Flash macro
 **
 ** \param u32Address          Any address of the Flash
 **
 ** \return    none
 *****************************************************************************/
static void ResetFlash(uint32_t u32Address)
{
    boolean_t bComSeqState;
    
    // Save current state of Command Sequencer (because this function can be
    // called from functions which have CS enabled or disabled)
    bComSeqState = (DFCA_CSWE == 1) ? TRUE : FALSE;
        
    // Command Sequencer must be disabled in order to execute the read/reset command
    DFCA_CSWE = 0;
    
    // Ensure an even address
    u32Address &= 0xfffffffe;

    // Execute the read/reset command
    *((__far volatile uint8_t *) u32Address) = 0xf0;
        
    // Wait until Flash is ready again
    while (DFSA_RDY == 0)
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
    
    // Restore state of Command Sequencer
    DFCA_CSWE = (bComSeqState == TRUE) ? 1 : 0;
}