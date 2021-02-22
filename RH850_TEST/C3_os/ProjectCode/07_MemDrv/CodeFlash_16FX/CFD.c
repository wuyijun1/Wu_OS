/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE  [Flash driver for MB96F673 MCU                                      ]
*-----------------------------------------------------------------------------
  .FILE   [ flash.c                                                         ]
  .AUTHOR [  Tan Fumin				                                     ]
*-----------------------------------------------------------------------------
 Version Date        		Author                       
Change                      
 -----------------------------------------------------------------------------
 Rev 00.00.00 2014/10/28    Tan Fumin      			 The first version  
                                                 update Telltales process
****************************** .FILE_HEADER_END ******************************/

#include "general.h"
#include "CFD.h"

static uint8 CFD_u8WriteEnabled      = FALSE;

static void CFD_vStatusReset(uint32 u32Address);

/*****************************************************************************
 Function  : CFD_u8Init												 
 Description   : Flash driver initialize 
 NOTE: NULL
 Return Value  : 0 is OK
 			   Not 0 is driver not ready
*****************************************************************************/
uint8 CFD_u8Init(void)
{
    // If the write access has been disabled during run-time, it cannot
    // be enabled again until next rest
    
    DFWC0A = 0x1f;
    DFWC1A = 0xc0;
    DFCA_WE = 1;
    DFCA_CSWE = 1;
    
    CFD_u8WriteEnabled = TRUE;

    return ERR_NULL;
}


/*****************************************************************************
 Function  : CFD_vExit												 
 Description   : Flash driver de-initialize 
 NOTE: NULL
 Return Value  :NULL
*****************************************************************************/
void CFD_vExit(void)
{
    DFCA_WE = 0;
    DFCA_CSWE = 0;
    
    CFD_u8WriteEnabled = FALSE;
}



/*****************************************************************************
 Function  : CFD_u8WriteByte												 
 Description   : write the data to the address
 			 u32Address : flash address
 			 u8Data : 1 byte data to writen
 NOTE: NULL
 Return Value  :0 is OK
 			   Not 0 is write failure
*****************************************************************************/
uint8 CFD_u8WriteData(uint32 u32FlsAddress, uint8 *pu8DataHead,uint16 u16DataLen)
{
	uint16 u16i;

	// Check if writing was enabled beforehand
	if (CFD_u8WriteEnabled == FALSE)
	{
		return ErrorInvalidMode;
	}

	// Check if Command Sequencer is idle
	if (DFSA_ST != 0)
	{
		return ErrorInvalidMode;
	}
	
	if(u32FlsAddress<CFD_MinFlsAddress || u32FlsAddress+u16DataLen >CFD_MaxFlsAddress)
		return ErrorInvalidParameter;

    
	for(u16i=0;u16i<u16DataLen;u16i++,pu8DataHead++,u32FlsAddress++)
	{
    	
		// Clear all status flags
		DFISA = 0x00;

		// Program the value
		*((__far volatile uint8 *) u32FlsAddress) = *pu8DataHead;

		// Wait for one of the relevant status flags to be set
		while((DFISA_FININT == 0) && (DFISA_ERINT == 0))
		{
			WDTCP_ = 0x00; // Watchdog clearing
		}

		// Check status flags
		if (DFISA_FININT == 1)
		{
			continue;
		}
		else if (DFISA_ERINT == 1)
		{
			if(DFISA_HANGINT == 1)
			{
				CFD_vStatusReset(u32FlsAddress);
			}
			return Error;
		}
		else
		{
			return Error;
		}
	}
	
	return ERR_NULL;
}

/*****************************************************************************
 Function  : CFD_u8ReadData												 
 Description   : Read the data from the address
 			 u32Address : flash address
 			 pu8DataHead : data buffer for read
 			 u16DataLen: data length for read
 NOTE: NULL
 Return Value  :0 is OK
 			   Not 0 is write failure
*****************************************************************************/
uint8 CFD_u8ReadData(uint32 u32FlsAddress, uint8 *pu8DataHead,uint16 u16DataLen)
{
	uint8 __far *p=(uint8 __far *)u32FlsAddress;
	uint16	u16Len;
	
	if(u32FlsAddress<CFD_MinFlsAddress || u32FlsAddress+u16DataLen >CFD_MaxFlsAddress)
		return ErrorInvalidParameter;
		
	// memcpy(pu8DataHead,(void *)u32FlsAddress,u16DataLen);
	 for(u16Len=0;u16Len<u16DataLen;u16Len++,pu8DataHead++,p++)
	 {
	 	*pu8DataHead=*p;
	 }
	 
	 return ERR_NULL;
}

/*****************************************************************************
 Function  : CFD_u8WriteWord												 
 Description   : write the data to the address
 
 			 u32Address : flash address
 			 u16Data : 1 word data to writen
 NOTE: NULL
 Return Value  :0 is OK
 			   Not 0 is write failure
*****************************************************************************/
uint8 CFD_u8WriteWord(uint32 u32FlsAddress, uint16 u16Data)
{
    // Check if writing was enabled beforehand
    if (CFD_u8WriteEnabled == FALSE)
    {
        return ErrorInvalidMode;
    }
    
    // Check if address is 16-bit aligned
    if ((u32FlsAddress & 0x1) != 0)
    {
        return ErrorInvalidParameter;
    }
    
    // Check if Command Sequencer is idle
    if (DFSA_ST != 0)
    {
        return ErrorOperationInProgress;
    }
    
	if(u32FlsAddress<CFD_MinFlsAddress || u32FlsAddress+1 >CFD_MaxFlsAddress)
		return ErrorInvalidParameter;

    // Clear all status flags
    DFISA = 0x00;
    
    // Program the value
	*((__far volatile uint16 *) u32FlsAddress) = u16Data;
    
    // Wait for one of the relevant status flags to be set
    while((DFISA_FININT == 0) && (DFISA_ERINT == 0))
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
    
    // Check status flags
    if (DFISA_FININT == 1)
    {
        return ERR_NULL;
    }
    else if (DFISA_ERINT == 1)
    {
        if(DFISA_HANGINT == 1)
        {
            CFD_vStatusReset(u32FlsAddress);
        }
        return Error;
    }
    else
    {
        return Error;
    }
}


/*****************************************************************************
 Function  : CFD_u8SectorErase												 
 Description   : erase the special sector
 
 			 u32Address : flash sector address
 NOTE: NULL
 Return Value  :0 is OK
 			   Not 0 is write failure
*****************************************************************************/
uint8 CFD_u8SectorErase(uint32 u32SectorAddress)
{
    __far volatile uint8 * pu8Sector;
    uint8 enRetVal;
    
    // Check if writing was enabled beforehand
    if (CFD_u8WriteEnabled == FALSE)
    {
        return ErrorInvalidMode;
    }
    
   if(u32SectorAddress<CFD_MinFlsAddress || u32SectorAddress >CFD_MaxFlsAddress)
	return ErrorInvalidParameter;
		
		
    // Command Sequencer must be disabled in order to execute the sector erase command sequences
    DFCA_CSWE = 0;
    
    // Ensure 0 at low nibbles because the "special command address offsets" will be added later
    u32SectorAddress &= 0xfffff000;
    // For better readability
    pu8Sector = (__far volatile uint8 *) u32SectorAddress;
    
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
            enRetVal = ERR_NULL;
            break;
        }
        
        // Check time-out flag
        if((*pu8Sector & DQ5) == DQ5)
        {
            // DQ7  must be checked again because it could have been set just before
            // time-out flag is checked
            if((*pu8Sector & DQ7) == DQ7)
            {
                enRetVal = ERR_NULL;
            }
            else
            {
                CFD_vStatusReset(u32SectorAddress);
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
static void CFD_vStatusReset(uint32 u32Address)
{
    uint8 bComSeqState;
    
    // Save current state of Command Sequencer (because this function can be
    // called from functions which have CS enabled or disabled)
    bComSeqState = (DFCA_CSWE == 1) ? TRUE : FALSE;
        
    // Command Sequencer must be disabled in order to execute the read/reset command
    DFCA_CSWE = 0;
    
    // Ensure an even address
    u32Address &= 0xfffffffe;

    // Execute the read/reset command
    *((__far volatile uint8 *) u32Address) = 0xf0;
        
    // Wait until Flash is ready again
    while (DFSA_RDY == 0)
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
    
    // Restore state of Command Sequencer
    DFCA_CSWE = (bComSeqState == TRUE) ? 1 : 0;
}


