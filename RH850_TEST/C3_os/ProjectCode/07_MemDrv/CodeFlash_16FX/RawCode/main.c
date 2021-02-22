/*****************************************************************************/
/*  F2MC-16FX Family Template Project V01L01                                 */
/*  ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011    */
/*  LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED    */
/*****************************************************************************/
/*****************************************************************************
  MAIN.C
  - description
  - See README.TXT for project description and disclaimer.
******************************************************************************/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "mcu.h"
#include "base_types.h"
#include "flash.h"


/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

// Some initial data is linked to sector SA4 to show that sector erasing is effective
#pragma segment FAR_CONST=my_initial_data, attr=CONST, locate=0xDF8000
static __far const uint8_t m_au8InitialData[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};
#pragma segment FAR_CONST

// Some RAM data that will be stored to SA4 by the application
static uint8_t m_au8DataToBeProgrammed[] = {0xaa, 0xbb, 0xcc, 0xdd};
static uint16_t m_au16DataToBeProgrammed[] = {0xfedc, 0xba98, 0x7654, 0x3210};

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/


/*****************************************************************************/
/*  Main application to control the program flow                             */
/*****************************************************************************/
void main(void)
{
    uint8_t u8Index;
    en_result_t enResult;
    
    // Allow all interrupt levels
    __set_il(7);
    // Enable interrupts
    __EI();
    
    // Configure 4 LEDs on starterkit
    PDR01 &= 0x0f;
    DDR01 |= 0xf0;

    // Flash writing must be enabled before any write/erase functions are executed
    enResult = Flash_EnableWriting();
        
    if (enResult == Ok)
    {
        enResult = Flash_SectorErase(SECTOR_SA4);
    }
    
    if (enResult == Ok)
    {
        // Store some byte values to Flash memory
        for(u8Index = 0; u8Index < (sizeof(m_au8DataToBeProgrammed) / sizeof(m_au8DataToBeProgrammed[0])); u8Index++)
        {
            enResult = Flash_Write8(SECTOR_SA4 + 0x20 + u8Index, m_au8DataToBeProgrammed[u8Index]);
            
            if (enResult != Ok)
            {
                break;
            }
        }
    }
    
    if (enResult == Ok)
    {
        // Store some 16-bit values to Flash memory
        for(u8Index = 0; u8Index < (sizeof(m_au16DataToBeProgrammed) / sizeof(m_au16DataToBeProgrammed[0])); u8Index++)
        {
            enResult = Flash_Write16(SECTOR_SA4 + 0x40 + (u8Index * 2), m_au16DataToBeProgrammed[u8Index]);
            
            if (enResult != Ok)
            {
                break;
            }
        }
    }
    
    // Flash writing can be disabled now, there is no more need to write/erase the Flash
    Flash_DisableWritingPermanently();
    
    if(enResult == Ok)
    {
        // Light all 4 LEDs in case of success
        PDR01 |= 0xf0;
    }
    else
    {
        // Light only 2 LEDs in case of failure
        PDR01 |= 0x90;
    }
    
    // Endless loop
    while(1)
    {
        WDTCP_ = 0x00; // Watchdog clearing
    }
}



