/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE: TJA1075 Driver used on 32bit MCU RH850L by SPI 
*-----------------------------------------------------------------------------
  .FILE:L99PM62.c
  .AUTHOR:Zhusx		   
*-----------------------------------------------------------------------------

 Date        Author                       Change
 -----------------------------------------------------------------------------
2016.11.05  Zhusx 		   :create this module

*****************************************************************************/
#include "S_SPI.h"
#include "general.h"
#include "L99PM62.h"

uint32_t Reasd_SR_Result = 0;
static uint8_t WD_Trig_Flag = 0;
static uint8_t WD_Trig_Count = 0;
static uint8_t WD_Meacure_Flag=0;
/*******************************************************************************
* Function Name :SBC_vDrvInit
* Description   :call in Frame Reset ;  
                       Init PM62 LDO to normal state;
* Input          :
* Output        :
* Other         :	
* Date          :2016.11.10 
*******************************************************************************/
void L99PM62drv_vSpiInit(void)
{
    /*init spi configiration*/
	SPI_vDrvInit_CH1();
    /*
     SCSN: SPI chip select; active LOW
     SCK: SPI clock; default level is LOW due to low-power concept
     SDI: SPI data input
     SDO: SPI data output; floating when pin SCSN is HIGH
    */
}

/*******************************************************************************
* Function Name :SBC_vDrvExit
* Description   :deinit SPI and processure 
* Input         :
* Output        :
* Other         :
* Date          :2016.11.10 
*******************************************************************************/
void  L99PM62drv_vDrvExit(void)
{
    /*Deinit spi configiration*/
   SPI_vDrvDeInit_CH1();
    /*Deinit Flow controll*/
}

/******************************************************************************
* Description   :
* Input         :
* Output       :
* Other         :
* Date          : 2016.11.10 
******************************************************************************/
uint8_t L99PM62drv_PowerOn_Diagnosis(void)
{
	uint8_t temp = 0;
	uint32_t local_statusreg_1;
	uint32_t local_statusreg_2;
	uint32_t local_statusreg_3;
	
/********************************************/
//		diagnosis the device status						//
// 00 -- active
// 01 -- V1 standby
// 10 -- VBAT standby
// 11 -- flash

	//local_statusreg_3 = L99PM62drv_GetStatus3();
	
	//temp = ((local_statusreg_3 & (0x30U << 8)) >> 12);
	
	//return temp;
/********************************************/

	local_statusreg_1 = L99PM62drv_GetStatus1();
	

	if (local_statusreg_1 & 0x200000)
	{ 
	  //  COLD START
	  return COLD_START_FLAG;
	}
	if (local_statusreg_1 & 0x800000)
	{ 
	  //  POWER ON
	  return POWER_ON_FLAG;
	}
	if (local_statusreg_1 & 0x820000)
	{ 
	  //  POWER ON WEAK
	  return POWER_ON_WEAK_FLAG;
	}
	if (local_statusreg_1 & 0xc00000)
	{ 
	  //  COMMUNICATION ERROR
	  return COMMUNICATION_FLAG;
	}
	
	if (local_statusreg_1 & 0xa20000)
	{
		// OVER OR UNDER VOLTAGE
		return OV_UV_FLAG;
	}
	if (local_statusreg_1 & 0xa10000)
	{
		// WD FAIL
		return WD_FAIL_FLAG;
	}
	if (local_statusreg_1 & 0xa80000)
	{
		// TSD1
		return TSD1_FLAG;
	}
	if (local_statusreg_1 & 0xb90000)
	{
		// TSD2
		return TSD2_FLAG;
	}
	if (local_statusreg_1 & 0xa40000)
	{
		// V1<2V for t>2us
		return V1_FAIL_FLAG;
	}
	if (local_statusreg_1 & 0xa00000)
	{
		// OTHER FAIL
		return OTHER_FAIL_FLAG;
	}
	return UNKNOWN;
	//
}
/******************************************************************************
* Description   :
* Input         :
* Output       :
* Other         :
* Date          : 2016.11.10 
******************************************************************************/
void L99PM62drv_Set_Wakeup(void)
{

	// Set all inputs to static sense (64us)
	L99PM62drv_SetInputFilterMode (L99PM62DRV_MASK_WU1|L99PM62DRV_MASK_WU2|L99PM62DRV_MASK_WU3, L99PM62DRV_IN_FILTER_64);
	
	// Set pull up/down configuration for each input
	L99PM62drv_SetWUInputMode (L99PM62DRV_MASK_WU1, L99PM62DRV_WU_INPUT_MODE_CUR_SINK);
	L99PM62drv_SetWUInputMode (L99PM62DRV_MASK_WU2, L99PM62DRV_WU_INPUT_MODE_CUR_SINK);
	L99PM62drv_SetWUInputMode (L99PM62DRV_MASK_WU3, L99PM62DRV_WU_INPUT_MODE_CUR_SINK);	
	
	//Enable/Disable WU_inputs , Enable/Disable WU by OL
	L99PM62drv_DisableWakeupSource (L99PM62DRV_MASK_WU1|L99PM62DRV_MASK_WU2|L99PM62DRV_MASK_WU3, (FunctionalState)Fun_ENABLE);	
	#if 0
	//Select wake up timer
	L99PM62drv_SetWuTimerSelect (L99PM62DRV_WUTIMER_1);
	//Set timer1
	L99PM62drv_SetTimer1 (L99PM62DRV_TIMER1PERIOD_4000, L99PM62DRV_TIMER1ONTIME_10);
	//Enable/Disable wake up timer
	L99PM62drv_SetWuTimerEn (Fun_DISABLE);
	#endif
}

/******************************************************************************
 Function Name :void  L99PM62drv_ReadOrWrite(L99PM62drv_RWMode  mode,uint8_t Register)
* Description   :
Register= CtrlReg1[0] /CtrlReg2[0]/CtrlReg3[0]/CtrlReg4[0]/CtrlReg5[0]/CtrlReg6[0]
               StatReg1[0] /StatReg2[0] /StatReg3[0] 
               
* Input         :
* Output       :
* Other         : Use Test
* Date          : 2016.11.10 
******************************************************************************/

void  L99PM62drv_ReadOrWrite(L99PM62drv_RWMode  mode,uint8_t Register)
{
       Register&=0x3F;
	Register	|=(uint8_t)((uint8_t)mode<<6);
}

/******************************************************************************
 Function Name :void L99PM62drv_Init (void)
* Description   :
				This module shall initialize the whole L99PM62 driver (internal data structure
				etc). It does not care about L99PM62 SPI adaptation layer nor SPI interface nor 
				L99PM62 device itself. The SPI needs to be initialized earlier.
				Caveats: L99PM62drv can control just one L99PM62 device.
				This service should not be called during a running operation.

* Input         :
* Output       :
* Other         :
* Date          : 2016.11.10 
******************************************************************************/
void L99PM62drv_Init (void) {
      uint8_t i;
	InitFlag = 1U;  /* Flag to notice that L99PM62drv_Init()was already called*/

	for (i = 0U; i < 3U; i++)
	{
		CtrlReg1[i] = 0U;
		CtrlReg2[i] = 0U;
		CtrlReg3[i] = 0U;
		CtrlReg4[i] = 0U;
		CtrlReg5[i] = 0U;
		CtrlReg6[i] = 0U;
			CtrlReg_Result[i] = 0U;
		StatReg1[i] = 0U;
		StatReg2[i] = 0U;
		StatReg3[i] = 0U;
			StatReg_Result[i] = 0U;
	}
	CtrlReg4[2] |= 0x40U;  /*Must write 1*/
	CtrlReg1[0] = (uint8_t)(0x01U);
	CtrlReg2[0] = (uint8_t)(0x02U);
	CtrlReg3[0] = (uint8_t)(0x03U);
	CtrlReg4[0] = (uint8_t)(0x04U);
	CtrlReg5[0] = (uint8_t)(0x05U);
	CtrlReg6[0] = (uint8_t)(0x06U);
	

	L99PM62_WR_Regs(CtrlReg1,CtrlReg_Result);	
	L99PM62_WR_Regs(CtrlReg2,CtrlReg_Result);	
	L99PM62_WR_Regs(CtrlReg3,CtrlReg_Result);	
	L99PM62_WR_Regs(CtrlReg4,CtrlReg_Result);	
	L99PM62_WR_Regs(CtrlReg5,CtrlReg_Result);	
	L99PM62_WR_Regs(CtrlReg6,CtrlReg_Result);	
		
	StatReg1[0] = (uint8_t)(0x91U);
	StatReg2[0] = (uint8_t)(0x92U);
	StatReg3[0] = (uint8_t)(0x93U);

	L99PM62_WR_Regs(StatReg1, StatReg_Result);
	L99PM62_WR_Regs(StatReg2, StatReg_Result);
	L99PM62_WR_Regs(StatReg3, StatReg_Result);
}

/******************************************************************************
*Function Name :void L99PM62drv_Init (void)
* Description   :
				Function triggers the watchdog hardware. It has to be called periodically by 
				upper layer function (usually the watchdog manager) in order to prevent the 
				watchdog hardware from expiring. Right timing is essential. For more detail see
				L99PM62 datasheet. Affected register: CR1.00
				It is useful to periodically refresh dedicated bit positions of main internal 
				variables from security point of view. This function was chosen as right place
				to do it.
				Function writes internal copy of Control Register 1 to L99PM62 device via SPI.
				Function protects the user from taking care about special conditions related to
				WD handling after wake up from stand by modes.
				Caveats: Function waits until the data are transferred completely to L99PM62 
				via SPI.
				
				L99PM62DRV_WDTIMER_10,   Sfe Time 7.5---12ms
				L99PM62DRV_WDTIMER_50,   Sfe Time 37.5---60ms
				L99PM62DRV_WDTIMER_100,  Sfe Time 75---120ms
				L99PM62DRV_WDTIMER_200,  safetime  150---240ms
				
* Input         :
* Output       :
* Other         :
* Date          :2016.11.10 
******************************************************************************/
void L99PM62drv_WdgTrigger (void) {


/* It is useful to periodically refresh dedicated bit positions of main internal
      variables from security point of view. This function was chosen as right
      place to do it. */
    CtrlReg1[0] = (uint8_t)(0x01U);
    CtrlReg2[0] = (uint8_t)(0x02U);
    CtrlReg3[0] = (uint8_t)(0x03U);
    CtrlReg4[0] = (uint8_t)(0x04U);
    CtrlReg5[0] = (uint8_t)(0x05U);
    CtrlReg6[0] = (uint8_t)(0x06U);

    CtrlReg1[2] ^= 0x01U;           /* refresh WD */ 
    L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result);
}
/******************************************************************************
*Function Name :void L99PM62drv_Init (void)
* Description   :
				This function sets selected Stand by mode of the L99PM62 device.
				Affected register: CR1.1..2.
				Note: Function updates SW driver internal copy of Control Register 1 and the register is 
				immediately sent to L99PM62 via SPI.
				Caveats: It is necessary to decrease power consumption from L99PM62 V1 voltage
				regulator after set Stand by mode V1. Most often it means to set immediately 
				Halt mode of the MCU. It is necessary to take care also about Watchdog 
				triggering. The best time for the function calling is just after the calling of
				L99PM62drv_WdgTrigger(); function in its regular watch dog time window. Function 
				waits until both Control registers are transferred completely to L99PM62 via SPI.
* Input         :	mode    defines type of stand by mode to be set
* Output       :
* Other         :
* Date          :2016.11.10 
******************************************************************************/
void L99PM62drv_SetStandbyMode (L99PM62drv_StandbyModeType mode)
{	
	CtrlReg1[2] &= (uint8_t)~0x06U;
	switch (mode)
	{
		case L99PM62DRV_STANDBYMODE_V1:
			CtrlReg1[2] |= 0x06U;
			L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result);
			break;
		case L99PM62DRV_STANDBYMODE_VBAT:
			CtrlReg1[2] |= 0x02U;
			L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result); /* should cause power off */
			break;
		default:
			return;
	}
}
/******************************************************************************
*Function Name :L99PM62drv_SetVoltageReg2Mode (L99PM62drv_VoltageReg2ModeType mode) 
* Description   :
				Function controls Voltage regulator 2 mode of L99PM62.Affected register:CR1.4..5
				Note: Function updates SW driver internal copy of Control Register 1 and the
				register is immediately sent to L99PM62 via SPI.  
				Caveats: Function waits until the data are transferred completely to L99PM62
via SPI.
* Input         :	mode defines mode of Voltage regulator 2 to be set
* Output       :
* Other         :
* Date          :	2016.11.10 
******************************************************************************/
void L99PM62drv_SetVoltageReg2Mode (L99PM62drv_VoltageReg2ModeType mode)
{
	CtrlReg1[2] &= (uint8_t)~0x30U;
	CtrlReg1[2] |= (uint8_t)((uint8_t)mode << 4U) & 0x30U;
	L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result);
}
/******************************************************************************
*Function Name :void L99PM62drv_SetRelayOutput (L99PM62drv_RelayOutputType value)
* Description   :
				Function controls LS relay outputs of L99PM62. Affected register: CR1.6..7
				Note: Function updates SW driver internal copy of Control Register 1 and the 
				register is immediately sent to L99PM62 via SPI.
				Caveats: Function waits until the data are transferred completely to L99PM62
				via SPI.
				Caveats: Function waits until the data are transferred completely to L99PM62
via SPI.
* Input         :	mode defines mode of Voltage regulator 2 to be set
* Output       :
* Other         :
* Date          :	2016.11.10 
******************************************************************************/

void L99PM62drv_SetRelayOutput (L99PM62drv_RelayOutputType value)
{

    switch (value) 
		{
        case RELAYOUTPUT_OFF_OFF:   /* Switch both relays off. */
            REL1_OFF;
            REL2_OFF;
            break;
        case RELAYOUTPUT_ON_OFF:    /* Switch relay REL1 on and REL2 off.*/
            REL1_ON;
            REL2_OFF;
            break;
        case RELAYOUTPUT_OFF_ON:    /* Switch relay REL1 off and REL2 on.*/
            REL1_OFF;
            REL2_ON;
            break;
        case RELAYOUTPUT_ON_ON:     /* Switch both relays on.*/
            REL1_ON;
            REL2_ON;
            break;
        case RELAYOUTPUT_OFF_X:     /* Switch relay REL1 off and refresh 
                                       		 previous state of REL2 (don't change).*/
            REL1_OFF;
            break;
        case RELAYOUTPUT_ON_X:      /* Switch relay REL1 on and refresh 
                                        		previous stateof REL2 (don't  change).*/
            REL1_ON;
            break;
        case RELAYOUTPUT_X_OFF:     /* Switch relay REL2 off and refresh 
                                        		previous state of REL1 (don't change).*/
            REL2_OFF;
            break;
        case RELAYOUTPUT_X_ON:      /* Switch relay REL2 on and refresh
                                        		previous state of REL1 (don't  change).*/
            REL2_ON;
            break;
        default:
            return;                 /* parameter value out of range */
    }
    L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result);
}
/******************************************************************************/
/*
*Function Name :void L99PM62drv_SetOutMode (uint8_t mask, L99PM62drv_OutModeType mode) 
* Description   :
				 mask    sets by mask which output will be changed.
	                    Range: 0x00..0xF1
	                    Bit 11.14.15:  1 = Mask is active for OUTHS,      0 = Mask is not active for OUTHS.
																		 
	                    Bit 8:  			 1 = Mask is active for OUT1,  0 = Mask is not active for OUT1.
																		 
	                    Bit 9:  			 1 = Mask is active for OUT2,  0 = Mask is not active for OUT2.
																		
	                    Bit 10:  			 1 = Mask is active for OUT3,  0 = Mask is not active for OUT3.
																		
	                    Bit 12.13:  	       1 = Mask is active for OUT4,  0 = Mask is not active for OUT4.

mask=	              L99PM62DRV_MASK_OUT1, L99PM62DRV_MASK_OUT2, L99PM62DRV_MASK_OUT3,
	                    L99PM62DRV_MASK_OUT4, L99PM62DRV_MASK_OUTHS.
                          
L99PM62DRV_OUT_mode=	 L99PM62DRV_OUT_Off       
						 L99PM62DRV_OUT_ON        
						 L99PM62DRV_OUT_timer1  
						 L99PM62DRV_OUT_Timer2   
						 L99PM62DRV_OUT_PWM1   
						 L99PM62DRV_OUT_PWM2     
						 L99PM62DRV_OUT_PWM3    
						 L99PM62DRV_OUT_PWM4     
Example: OUT_MODE_MASK_OUT1 | OUT_MODE_MASK_OUT2 ? mask is
active for OUT1 and OUT2.				
* Input         :	mode defines defines type of stand by mode to be sett
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetOutMode (uint8_t mask,uint8_t L99PM62DRV_OUT_mode) 
{


    if (mask & L99PM62DRV_MASK_OUT1) 
    {
        CtrlReg1[1] &= (uint8_t)~0x01U;
        CtrlReg1[1] |= (uint8_t)L99PM62DRV_OUT_mode & 0x01U;
    }
    if (mask & L99PM62DRV_MASK_OUT2) {
        CtrlReg1[1] &= (uint8_t)~0x02U;
        CtrlReg1[1] |= (uint8_t)L99PM62DRV_OUT_mode & 0x02U;
    }
    if (mask & L99PM62DRV_MASK_OUT3) {
        CtrlReg1[1] &= (uint8_t)~0x04U;
        CtrlReg1[1] |= (uint8_t)L99PM62DRV_OUT_mode & 0x04U;
    }
    if (mask & L99PM62DRV_MASK_OUT4) {
        CtrlReg1[1] &= (uint8_t)~0x30U;
        CtrlReg1[1] |= (uint8_t)L99PM62DRV_OUT_mode & 0x30U;
    }
    if (mask & L99PM62DRV_MASK_OUTHS) {
        CtrlReg1[1] &= (uint8_t)~0xC8U;
        CtrlReg1[1] |= (uint8_t)L99PM62DRV_OUT_mode & 0xC8U;
    }
    L99PM62_WR_Regs(CtrlReg1, CtrlReg_Result);
}
/******************************************************************************/
/*
*Function Name : void L99PM62drv_DisableWakeupSource (uint8_t mask, FunctionalState mode)
* Description   :
			mask sets wakeup source to be changed.
			Range: 0x00..0xFF
			Bit 0: 1 = Mask is active for WU1,0 = Mask is not active for WU1.
			Bit 1: 1 = Mask is active for WU2,0 = Mask is not active for WU2.
			Bit 2: 1 = Mask is active for WU3,0 = Mask is not active for WU3.
			Bit 4: 1 = Mask is active for open load of OUT1 wake up source,
			0 = Mask is not active for open load of OUT1 wake up source.
			Bit 5: 1 = Mask is active for open load of OUT2 wake up source,
			0 = Mask is not active for open load of OUT2 wake up source.
			Bit 6: 1 = Mask is active for open load of OUT3 wake up source,
			0 = Mask is not active for open load of OUT3 wake up source.
			Following constants are defined in L99PM62drv.h file:
			L99PM62DRV_MASK_OUT1, L99PM62DRV_MASK_OUT2, L99PM62DRV_MASK_OUT3,
			L99PM62DRV_MASK_OUT4, L99PM62DRV_MASK_WU1, L99PM62DRV_MASK_WU2,
			L99PM62DRV_MASK_WU3.
			Example1: L99PM62DRV_MASK_OUT1 | L99PM62DRV_MASK_WU3 
			?mask is active for WU1 and openload of OUT3.
			Or better by using predefined constants:
			L99PM62drv_DisableWakeupSource(L99PM62DRV_MASK_OUT1 | L99PM62DRV_MASK_OUT2
			| L99PM62DRV_MASK_WU2, L99PM62DRV_MASK_OUT1 | L99PM62DRV_MASK_WU2);
			Function disables wakeup source from OUT1 and WU2; and enables 
			wakeup source from OUT2. The rest reminds unchanged.

			bitpattern  Disables/enables wakeup functionality separately
			for each wake up source. Particular bits are related to 
			relevant wakeup sources in the same order as are defined by 
			masks (see above). Each bit=1 disables related wakeup source
			and each bit = 0 enables related wakeup source.      
			Function enables / disables wakeup functionality separately for each wake up 
			source defined by mask. Affected register: CR2.0..2 Note: Function updates SW 
			driver internal copy of Control Register 1 and the register is immediately sent
			to L99PM62 via SPI. 			
* Input         :	mode defines defines type of stand by mode to be sett
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_DisableWakeupSource (uint8_t mask, FunctionalState mode) 
{
    
	if (mask & L99PM62DRV_MASK_WU1) 
	{
		if (mode == Fun_DISABLE)
		{
			CtrlReg2[2] &= (uint8_t)~0x01U;
		}
		else 
		{
			CtrlReg2[2] |= 0x01U;
		}
	}
	if (mask & L99PM62DRV_MASK_WU2)
	{
		if (mode == Fun_DISABLE) 
		{
			CtrlReg2[2] &= (uint8_t)~0x02U;
		}
		else 
		{
			CtrlReg2[2] |= 0x02U;
		}
	}
	if (mask & L99PM62DRV_MASK_WU3)
	{
		if (mode == Fun_DISABLE) 
		{
			CtrlReg2[2] &= (uint8_t)~0x04U;
		}
		else 
		{
			CtrlReg2[2] |= 0x04U;
		}
	}
	L99PM62_WR_Regs(CtrlReg2, CtrlReg_Result);
}
/******************************************************************************/
/*
*Function Name : void L99PM62drv_SetWUInputMode (uint8_t mask, L99PM62drv_WUInputModeType mode)
* Description   :
			 mask sets WU input mode to be changed.
                    Following constants are defined in L99PM62drv.h file:
                    L99PM62DRV_MASK_WU1, L99PM62DRV_MASK_WU2, L99PM62DRV_MASK_WU3.
                    Example: L99PM62DRV_MASK_WU2 | L99PM62DRV_MASK_WU3 
                    ?mask is active for WU2 and WU3.
			Function sets mode (current source / current sink) for digital wake up inputs 
			WU1, WU2, WU3 and WU4 of L99PM62. Affected register: CR1.4..6. Note: Function 
			updates SW driver internal copy of Control Register 1 and the register is 
			immediately sent to L99PM62 via SPI.                     
* Input         :	mode describes mode (current source / current sink) 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWUInputMode (uint8_t mask, L99PM62drv_WUInputModeType mode) 
{
	if (mask & L99PM62DRV_MASK_WU1) 
	{
		if (mode == L99PM62DRV_WU_INPUT_MODE_CUR_SINK)
		{
			CtrlReg2[2] &= (uint8_t)~0x10U;
		}
		else 
		{
			CtrlReg2[2] |= 0x10U;
		}
	}
	if (mask & L99PM62DRV_MASK_WU2) 
	{
		if (mode == L99PM62DRV_WU_INPUT_MODE_CUR_SINK) 
		{
			CtrlReg2[2] &= (uint8_t)~0x20U;
		}
		else {
			CtrlReg2[2] |= 0x20U;
		}
	}
	if (mask & L99PM62DRV_MASK_WU3)
	{
		if (mode == L99PM62DRV_WU_INPUT_MODE_CUR_SINK) 
		{
			CtrlReg2[2] &= (uint8_t)~0x40U;
		}
		else
		{
			CtrlReg2[2] |= 0x40U;
		}
	}
      L99PM62_WR_Regs(CtrlReg2 ,CtrlReg_Result); 
}
/******************************************************************************/
/*
*Function Name :  void L99PM62drv_SetInputFilterMode (uint8_t mask, L99PM62drv_InputFilterModeType mode)
* Description   :
			  mask sets which WU input filter settings will be changed.
                    Range: 0x00 .. 0x0F
                    Bit 0:  1 = Mask is active for WU1, 
                            0 = Mask is not active for WU1.
                    Bit 1:  1 = Mask is active for WU2, 
                            0 = Mask is not active for WU2.
                    Bit 2:  1 = Mask is active for WU3, 
                            0 = Mask is not active for WU3.
                    Following constants are defined in L99PM62drv.h file:
                    L99PM62DRV_MASK_WU1, L99PM62DRV_MASK_WU2, L99PM62DRV_MASK_WU3.
                    Example: L99PM62DRV_MASK_WU1 | L99PM62DRV_MASK_WU3 ?
                    mask is active for WU1 and WU3.
			 Function controls filter for digital wake up inputs WU1, WU2 and WU3 of 
			L99PM62. Affected register: CR1.8..13 Note: Function updates SW driver internal
			copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.                   
* Input         :	mode sets filter timing for related WU inputs.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetInputFilterMode (uint8_t mask, L99PM62drv_InputFilterModeType mode) {

    if (mask & L99PM62DRV_MASK_WU1)
   {
        CtrlReg2[1] &= (uint8_t)~0x03U;
        CtrlReg2[1] |= (uint8_t)((uint8_t)mode << 0) & 0x03U;
    }
    if (mask & L99PM62DRV_MASK_WU2) {
        CtrlReg2[1] &= (uint8_t)~0x0CU;
        CtrlReg2[1] |= (uint8_t)((uint8_t)mode << 2) & 0x0CU;
    }
    if (mask & L99PM62DRV_MASK_WU3) {
        CtrlReg2[1] &= (uint8_t)~0x30U;
        CtrlReg2[1] |= (uint8_t)((uint8_t)mode << 4) & 0x30U;
    }
   L99PM62_WR_Regs(CtrlReg2 ,CtrlReg_Result);
}
/******************************************************************************/
/*
*Function Name :  void L99PM62drv_SetWuTimerSelect (L99PM62drv_SetWuTimerSelectType mode)
* Description   :
				mode sets which internal timer as the wake up source.
				Bit 0:  0 = Timer2, 
				Bit 0:  1 = Timer1, 
				Following constants are defined in L99PM62drv.h file:
				L99PM62DRV_WUTIMER_1, L99PM62DRV_WUTIMER_2.
				Function controls which internal timer for wake up inputs WU1, WU2 and WU3 of 
				L99PM62. Affected register: CR3.0 Note: Function updates SW driver internal
				copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.                    
* Input         :	mode sets timer selected.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWuTimerSelect (L99PM62drv_SetWuTimerSelectType mode) 
{
 
	if(mode == L99PM62DRV_WUTIMER_1)
		CtrlReg3[2] |= (uint8_t)mode & 0x01U;
	else
		CtrlReg3[2] &= (uint8_t)~0x01U;
	
	L99PM62_WR_Regs(CtrlReg3 ,CtrlReg_Result);   
}
/******************************************************************************/
/*
*Function Name :   L99PM62drv_SetWuTimerEn (FunctionalState mode)
* Description   :
				mode sets internal timer enable/disable for wake up.
				Bit 1:  0 = Disable, 
				Bit 1:  1 = Enable, 
				Following constants are defined in L99PM62drv.h file:
				L99PM62DRV_WUTIMER_ENABLE, L99PM62DRV_WUTIMER_DISABLE.   
				Function controls enable/disable timer for wake up inputs WU1, WU2 and WU3 of 
				L99PM62. Affected register: CR3.1 Note: Function updates SW driver internal
				copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.
* Input         :	mode sets internal timer enable/disable for wake up.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWuTimerEn (FunctionalState mode) 
{

	if(mode == Fun_DISABLE)
		CtrlReg3[2] &= (uint8_t)~0x02U;
	else
		CtrlReg3[2] |= (uint8_t)((uint8_t)mode << 1) & 0x02U;
	
	L99PM62_WR_Regs(CtrlReg3 ,CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				mode sets CAN enable/disable for wake up.
				Bit 2:  0 = Disable, 
				Bit 2:  1 = Enable, 
				Following constants are defined in L99PM62drv.h file:
				L99PM62DRV_WUCAN_ENABLE, L99PM62DRV_WUCAN_DISABLE.
				Function controls enable/disable CAN for wake up inputs WU1, WU2 and WU3 of 
				L99PM62. Affected register: CR3.2 Note: Function updates SW driver internal
				copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWuCanEn (FunctionalState mode) 
{
	if(mode == Fun_DISABLE)
		CtrlReg3[2] &= (uint8_t)~0x04U;
	else
		CtrlReg3[2] |= (uint8_t)((uint8_t)mode << 2) & 0x04U;
	
	L99PM62_WR_Regs(CtrlReg3 ,CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				mode sets LIN enable/disable for wake up.
				Bit 3:  0 = Disable, 
				Bit 3:  1 = Enable, 
				Following constants are defined in L99PM62drv.h file:
				L99PM62DRV_WULIN_ENABLE, L99PM62DRV_WULIN_DISABLE.
				Function controls enable/disable LIN for wake up inputs WU1, WU2 and WU3 of 
				L99PM62. Affected register: CR3.3 Note: Function updates SW driver internal
				copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWuLinEn (FunctionalState mode) {


	if(mode == Fun_DISABLE)
		CtrlReg3[2] &= (uint8_t)~0x08U;
	else
		CtrlReg3[2] |= (uint8_t)((uint8_t)mode << 3) & 0x08U;
	
	L99PM62_WR_Regs(CtrlReg3 ,CtrlReg_Result);
    
}
/******************************************************************************/
/*
* Description   :
				mode sets watchdog time.
				Bit 5.4:  00 = 10ms,   Sfe Time 7.5---12ms
				Bit 5.4:  01 = 50ms,   Sfe Time 37.5---60ms
				Bit 5.4:  10 = 100ms,  Sfe Time 75---120ms
				Bit 5.4:  11 = 200ms,  safetime  150---240ms
				Following constants are defined in L99PM62drv.h file:
				L99PM62DRV_WDTIMER_10, L99PM62DRV_WDTIMER_50, L99PM62DRV_WDTIMER_100,
				L99PM62DRV_WDTIMER_200.
				unction controls time for watchdog of L99PM62. 
				Affected register: CR3.4..5 Note: Function updates SW driver internal
				copy of Control Register2 and the register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetWdTime (L99PM62drv_WdTimeType mode) {

    CtrlReg3[2] &= (uint8_t)~0x30U;
    CtrlReg3[2] |= (uint8_t)((uint8_t)mode << 4);

    L99PM62_WR_Regs(CtrlReg3, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function controls Timer1 of L99PM62. Affected register: CR3.12..14
				Note: Function updates SW driver internal copy of Control Register 3 and the 
				register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetTimer1 (L99PM62drv_Timer1PeriodType period, L99PM62drv_Timer1ONTimeType ontime) {



    CtrlReg3[1] &= (uint8_t)~0x70U;
    CtrlReg3[1] |= (uint8_t)((uint8_t)ontime << 6) & (uint8_t)(0x01U << 6);
    CtrlReg3[1] |= (uint8_t)((uint8_t)period << 4) & 0x30U;

    L99PM62_WR_Regs(CtrlReg3, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function controls timer2 of L99PM62. Affected register: CR1.8..10
				Note: Function updates SW driver internal copy of Control Register 3 and the 
				register is immediately sent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetTimer2 (L99PM62drv_Timer2PeriodType period, L99PM62drv_Timer2ONTimeType ontime) {

    CtrlReg3[1] &= (uint8_t)~0x07U;
    CtrlReg3[1] |= (uint8_t)((uint8_t)ontime << 2) & (uint8_t)(0x01U << 2);
    CtrlReg3[1] |= (uint8_t)((uint8_t)period >> 0) & 0x03U;

    L99PM62_WR_Regs(CtrlReg3, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables/disables CAN receive only during Active mode.
				Affected register: CR4.0
				Note: Function updates SW driver internal copy of Control Register 4 and 
				the register is immediatelysent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetCanRecOnlyMode (FunctionalState mode) {

    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[2] &= (uint8_t)~0x01U;
            break;
        case Fun_ENABLE:
            CtrlReg4[2] |= 0x01U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}

/******************************************************************************/
/*
* Description   :
				Function enables/disables CAN split termination during Active mode.
				Affected register: CR4.1
				Note: Function updates SW driver internal copy of Control Register 4 and 
				the register is immediatelysent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetCanSplitMode (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[2] &= (uint8_t)~0x02U;
            break;
        case Fun_ENABLE:
            CtrlReg4[2] |= 0x02U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables/disables CAN pattern wake.
				Affected register: CR4.2
				Note: Function updates SW driver internal copy of Control Register 4 and 
				the register is immediatelysent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetCanPattWakeMode (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[2] &= (uint8_t)~0x04U;
            break;
        case Fun_ENABLE:
            CtrlReg4[2] |= 0x04U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables/disables CAN loop.
				Affected register: CR4.3
				Note: Function updates SW driver internal copy of Control Register 4 and 
				the register is immediatelysent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetCanLoopMode (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[2] &= (uint8_t)~0x08U;
            break;
        case Fun_ENABLE:
            CtrlReg4[2] |= 0x08U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables/disables CAN active during Active mode.
				Affected register: CR4.4 
				Note: Function updates SW driver internal copy of Control Register 4 and 
				the register is immediatelysent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetCanActMode (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[2] &= (uint8_t)~0x10U;
            break;
        case Fun_ENABLE:
            CtrlReg4[2] |= 0x10U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function sets LIN configuration. Affected register: CR4.5, 4.7.
				Note: Function updates SW driver internal copy of Control Register 4 and the
				register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
#define TXD_TOUT_EN  (CtrlReg4[2] |= 0x20U)
#define TXD_TOUT_DIS (CtrlReg4[2] &= (uint8_t)~0x20U)

#define PUP_EN  (CtrlReg4[2] |= 0x80U)
#define PUP_DIS (CtrlReg4[2] &= (uint8_t)~0x80U)

void L99PM62drv_LinSetup (L99PM62drv_LinSetupType value) {
    switch (value) {
        case L99PM62DRV_LIN_TIM_EN_PUP_EN:
            TXD_TOUT_EN;
            PUP_EN;
            break;
        case L99PM62DRV_LIN_TIM_EN_PUP_DI:
            TXD_TOUT_EN;
            PUP_DIS;
            break;
        case L99PM62DRV_LIN_TIM_DI_PUP_EN:
            TXD_TOUT_DIS;
            PUP_EN;
            break;
        case L99PM62DRV_LIN_TIM_DI_PUP_DI:
            TXD_TOUT_DIS;
            PUP_DIS;
            break;
        default:
            return;                 /* parameter value out of range */
    }
    L99PM62_WR_Regs(CtrlReg4 ,CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function sets reset threshold level of L99PM62. Affected register: CR4.8..9
				Note: Function updates SW driver internal copy of Control Register 4 and the 
				register is immediately sent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/

void L99PM62drv_SetResetThresholdLevel (L99PM62drv_ResetThresholdLevelType level) {

    switch (level) {
    case L99PM62DRV_RESET_THRESHOLD_4600:
        CtrlReg4[1] &= (uint8_t)~0x03U;
        break;
    case L99PM62DRV_RESET_THRESHOLD_4350:
        CtrlReg4[1] &= (uint8_t)~0x03U;
        CtrlReg4[1] |= 0x01U;
        break;
    case L99PM62DRV_RESET_THRESHOLD_4100:
        CtrlReg4[1] &= (uint8_t)~0x03U;
        CtrlReg4[1] |= 0x02U;
        break;
    case L99PM62DRV_RESET_THRESHOLD_3800:
        CtrlReg4[1] &= (uint8_t)~0x03U;
        CtrlReg4[1] |= 0x03U;
        break;
    default:
        return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}

/******************************************************************************/
/*
* Description   :
				Function enables automatic shutdown of relay outputs during 
				Vs over/under-voltage of L99PM62. Affected register: CR2.10 Note: Function updates
				SW driver internal copy of Control Register 4 and the register is immediately
				sent to L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetRelayShutdownMode (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[1] &= (uint8_t)~0x04U;
            break;
        case Fun_ENABLE:
            CtrlReg4[1] |= 0x04U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables automatic recovery after Vs over/under-voltage recovery of
				L99PM62. Affected register: CR4.12 Note: Function updates SW driver internal copy
				of Control Register 4 and the register is immediately sent to L99PM62 via SPI.
				Function waits until the data are transferred completely to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetVsLockoutMode (FunctionalState mode) {

    switch (mode) {
        case Fun_DISABLE:
            CtrlReg4[1] &= (uint8_t)~0x10U;
            break;
        case Fun_ENABLE:
            CtrlReg4[1] |= 0x10U;
            break;
        default:
            return;
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function enables/disables autorecovery functionality for OUT HS output of L99PM62.
				Affected register: CR4.13
				Note: Function updates SW driver internal copy of Control Register 4 and the 
				register is immediately sent to L99PM62 via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetOutHSAutorecovery (FunctionalState mode) {
    switch (mode) {
        case Fun_DISABLE:    
            CtrlReg4[1] &= (uint8_t)~0x20U;
            break;
        case Fun_ENABLE:
            CtrlReg4[1] |= 0x20U;
            break;
        default:
            return;                 /* parameter value out of range */
    }
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function for internal purpose only.
				Function sets ON Voltage regulator 1 current monitoring mode of L99PM62 in V1 
				stand by mode. Affected register: CR4.14. Note: Function updates SW driver 
				internal copy of Control Register 4 and the register is immediately sent to 
				L99PM62 via SPI. Function refreshes driver internal copy of Status0 register
				from L99PM62 via SPI. 
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetVReg1CurrentMonitorOn (FunctionalState mode) {

    switch (mode) {
        case Fun_ENABLE:
					CtrlReg4[1] &= (uint8_t)~0x40U;
					break;
        case Fun_DISABLE:
					CtrlReg4[1] &= (uint8_t)~0x40U;
					CtrlReg4[1] |= (uint8_t)0x40U;
					break;
        default:
					return;
    }
		
    L99PM62_WR_Regs(CtrlReg4, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :
				Function set the PWM4 Frequent in L99PM62 via SPI. 
				Caveats: Function waits until the data are transferred completely to L99PM62
				via SPI.
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62drv_SetPWMFreq (L99PM62drv_PWMFreqType value) {

		switch(value){
		case Freq_128:
			CtrlReg5[2] &= (uint8_t)~0x80U;
			CtrlReg5[2] |= (uint8_t)((uint8_t)value << 6) & 0x80U;
			break;
		case Freq_256:
			CtrlReg5[2] &= (uint8_t)~0x80U;
			CtrlReg5[2] |= (uint8_t)((uint8_t)value << 6) & 0x80U;			
			break;
		default:
			break;
	}
    L99PM62_WR_Regs(CtrlReg5, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :   L99PM62drv_PWM1Duty=0--100
				Function set the PWM1 duty cycle in L99PM62 via SPI. 
				*PWM1_ON_DC   6	5	4	3	2	1	0
								1	1	1	1	1	1 	1     100%,   HS ON 
								..................................          ...         
								0	 0	 0	 0	 0 	1	 0    1.5%
								0 	 0	 0 	 0 	 0 	0 	 1    0.75%
								0      0     0    0     0    0      0    0%       HS OFF
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
/*void L99PM62drv_SetPWM1 (L99PM62drv_PWMOnType value)
{

    CtrlReg5[2] &= (uint8_t)~0x7fU;
    CtrlReg5[2] |= (uint8_t)value & 0x7fU;

    L99PM62_WR_Regs(CtrlReg5, CtrlReg_Result);
}
*/
void L99PM62drv_SetPWM1Duty (uint8_t L99PM62drv_PWM1Duty ) 
{	
	L99PM62drv_PWM1Duty=(uint8_t)(L99PM62drv_PWM1Duty*4u/3u);
	if(L99PM62drv_PWM1Duty >= 0x7fU)
	{
		L99PM62drv_PWM1Duty=0x7fU;
	}
	CtrlReg5[2] &= (uint8_t)~0x7fU;
	CtrlReg5[2] |= (uint8_t)L99PM62drv_PWM1Duty & 0x7fU;

	L99PM62_WR_Regs(CtrlReg5, CtrlReg_Result);
}	

/******************************************************************************/
/*
* Description   :  L99PM62drv_PWM2Duty=0--100
*PWM2_OFF_DC  6	5	4	3	2	1	0
 				1	1	1	1	1	1 	1     0%,      HS OFF 
 				  ..................................          ...         
				0	 0	 0	 0	 0 	1	 0   98.5%
				0 	 0	 0 	 0 	 0 	0 	 1   99.25%
				0      0     0    0     0    0      0   100%     HS ON	

				PWM_Duty=100-value*3/4
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
/*void L99PM62drv_SetPWM2 (L99PM62drv_PWMOffType value) 
{

    CtrlReg5[1] &= (uint8_t)~0x7fU;
    CtrlReg5[1] |= (uint8_t)value & 0x7fU;

    L99PM62_WR_Regs(CtrlReg5, CtrlReg_Result);
}
*/
void L99PM62drv_SetPWM2Duty (uint8_t L99PM62drv_PWM2Duty )
{

    	L99PM62drv_PWM2Duty=(uint8_t)((100-L99PM62drv_PWM2Duty)*4/3);
	if(L99PM62drv_PWM2Duty>=0x7fU)
	{
		L99PM62drv_PWM2Duty=0x7fU;	
	}
   	CtrlReg5[1] &= (uint8_t)~0x7fU;
    	CtrlReg5[1] |= (uint8_t)L99PM62drv_PWM2Duty & 0x7fU;
   	 L99PM62_WR_Regs(CtrlReg5, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :  L99PM62drv_PWM3Duty=0--100
			PWM3_ON_DC       6	5	4	3	2	1	0
			 				1	1	1	1	1	1 	1     100%,       HS ON 
			 				  ..................................          ...         
							0	 0	 0	 0	 0 	1	 0    1.5%
							0 	 0	 0 	 0 	 0 	0 	 1    0.75%
							0      0     0    0     0    0      0    100%        HS OFF	
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
/*void L99PM62drv_SetPWM3 (L99PM62drv_PWMOnType value){

	CtrlReg6[2] &= (uint8_t)~0x7fU;
	CtrlReg6[2] |= (uint8_t)value & 0x7fU;

	L99PM62_WR_Regs(CtrlReg6, CtrlReg_Result);
}
*/
void L99PM62drv_SetPWM3Duty (uint8_t L99PM62drv_PWM3Duty ) 
{
	L99PM62drv_PWM3Duty=(uint8_t)(L99PM62drv_PWM3Duty*4/3);
	if(L99PM62drv_PWM3Duty>=0x7fU)
	{
		L99PM62drv_PWM3Duty=0x7fU;
	}
	CtrlReg6[2] &= (uint8_t)~0x7fU;
	CtrlReg6[2] |= (uint8_t)L99PM62drv_PWM3Duty & 0x7fU;

	L99PM62_WR_Regs(CtrlReg6, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :    L99PM62drv_PWM4Duty=0--100
				PWM4_OFF_DC      6	5	4	3	2	1	0
				 				1	1	1	1	1	1 	1     100%,   HS OFF 
				 				  ..................................          ...         
								0	 0	 0	 0	 0 	1	 0    98.5%
								0 	 0	 0 	 0 	 0 	0 	 1    99.25%
								0      0     0    0     0    0      0    0%    HS ON
	
* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
/*void L99PM62drv_SetPWM4 (L99PM62drv_PWMOffType value)
{	
	CtrlReg6[1] &= (uint8_t)~0x7fU;
	CtrlReg6[1] |= (uint8_t)value & 0x7fU;

	L99PM62_WR_Regs(CtrlReg6, CtrlReg_Result);
}
*/
void L99PM62drv_SetPWM4Duty (uint8_t L99PM62drv_PWM4Duty ) 
{

    	L99PM62drv_PWM4Duty=(uint8_t)((100-L99PM62drv_PWM4Duty)*4/3);
	if(L99PM62drv_PWM4Duty>=0x7fU)
	{
		L99PM62drv_PWM4Duty=0x7fU;	
	}
   	CtrlReg6[1] &= (uint8_t)~0x7fU;
    	CtrlReg6[1] |= (uint8_t)L99PM62drv_PWM4Duty & 0x7fU;
   	L99PM62_WR_Regs(CtrlReg6, CtrlReg_Result);
}
/******************************************************************************/
/*
* Description   :

* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
uint32_t L99PM62drv_GetStatus1 (void) {

    StatReg1[0] = (uint8_t)(0x91U);
    L99PM62_WR_Regs(StatReg1, StatReg_Result);
    Reasd_SR_Result	 = (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[0]<<16)
             + (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[1]<<8)
             + (L99PM62drv_StatusRegType)StatReg_Result[2];
		return Reasd_SR_Result;
}
/******************************************************************************/
/*
* Description   :

* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
uint32_t L99PM62drv_GetStatus2 (void) {

    StatReg2[0] = (uint8_t)(0x92U);
    L99PM62_WR_Regs(StatReg2, StatReg_Result);
    Reasd_SR_Result	 = (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[0]<<16)
             + (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[1]<<8)
             + (L99PM62drv_StatusRegType)StatReg_Result[2];
		return Reasd_SR_Result;
}

/******************************************************************************/
/*
* Description   :

* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
uint32_t L99PM62drv_GetStatus3 (void) {

    StatReg3[0] = (uint8_t)(0x93U);
    L99PM62_WR_Regs(StatReg3, StatReg_Result);
    Reasd_SR_Result	 = (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[0]<<16)
             + (L99PM62drv_StatusRegType)((L99PM62drv_StatusRegType)StatReg_Result[1]<<8)
             + (L99PM62drv_StatusRegType)StatReg_Result[2];
		return Reasd_SR_Result;
}

/******************************************************************************/
/*
* Description   :

L99PM62DRV_WDTIMER_10,   Sfe Time 7.5---12ms
L99PM62DRV_WDTIMER_50,   Sfe Time 37.5---60ms
L99PM62DRV_WDTIMER_100,  Sfe Time 75---120ms
L99PM62DRV_WDTIMER_200,  safetime  150---240ms

* Output       :
* Other         :
* Date          :	2016.11.10 
*/
/******************************************************************************/
void L99PM62_WD_Meacure(uint8 Off_Or_On)
{
if( Off_Or_On==0)
{
	L99PM62drv_SetRelayOutput (RELAYOUTPUT_OFF_OFF);
}
else
	L99PM62drv_SetRelayOutput (RELAYOUTPUT_ON_ON);
}

/*
L99PM62DRV_WDTIMER_10,   Sfe Time 7.5---12ms
L99PM62DRV_WDTIMER_50,   Sfe Time 37.5---60ms
L99PM62DRV_WDTIMER_100,  Sfe Time 75---120ms
L99PM62DRV_WDTIMER_200,  safetime  150---240ms
*/
void L99PM62_WdgForegroundTrigger(void)
{	
	if(InitFlag==1)
	{
		WD_Trig_Count++;
		if(WD_Trig_Count>=WD_Trig_Num)
		{
			WD_Trig_Count=0;
			L99PM62drv_WdgTrigger();
			
			WD_Meacure_Flag=~WD_Meacure_Flag;
			L99PM62_WD_Meacure(WD_Meacure_Flag);
		}
	}
    else
    {
        WD_Trig_Count = 0u;
    }
}
void L99PM62drv_Set_CAN(void)
{
	L99PM62drv_SetWuCanEn (Fun_ENABLE);
	L99PM62drv_SetCanRecOnlyMode (Fun_DISABLE);
	L99PM62drv_SetCanSplitMode (Fun_DISABLE);
	L99PM62drv_SetCanPattWakeMode (Fun_ENABLE);
	L99PM62drv_SetCanLoopMode (Fun_DISABLE);
	L99PM62drv_SetCanActMode (Fun_ENABLE);
}
void L99PM62drv_Set_LIN(void)
{
	L99PM62drv_SetWuLinEn(Fun_ENABLE);
	L99PM62drv_LinSetup (L99PM62DRV_LIN_TIM_DI_PUP_EN);
}

void  L99PM62_vInit(void)
{     
	L99PM62drv_vSpiInit();
	L99PM62drv_Init();
	L99PM62drv_PowerOn_Diagnosis();
	    
	L99PM62drv_SetPWMFreq (Freq_128);	
	L99PM62drv_SetOutMode(L99PM62DRV_MASK_OUT1,L99PM62DRV_OUT_PWM1);
	L99PM62drv_SetOutMode(L99PM62DRV_MASK_OUT2,L99PM62DRV_OUT_PWM2);
	L99PM62drv_SetOutMode(L99PM62DRV_MASK_OUT3,L99PM62DRV_OUT_FSO);
	L99PM62drv_SetOutMode(L99PM62DRV_MASK_OUT4,L99PM62DRV_OUT_PWM4);
	L99PM62drv_SetOutMode(L99PM62DRV_MASK_OUTHS,L99PM62DRV_OUT_PWM3);
	L99PM62drv_SetPWM1Duty ( 100 );
	L99PM62drv_SetPWM2Duty ( 100 );
	L99PM62drv_SetPWM3Duty ( 100 );
	L99PM62drv_SetPWM4Duty ( 100 );
	L99PM62drv_SetOutHSAutorecovery (Fun_ENABLE);
    
	L99PM62drv_Set_Wakeup();
	L99PM62drv_SetVoltageReg2Mode (L99PM62DRV_VOLTAGE_REG2_ON_ACTIVE);
	L99PM62drv_Set_CAN();
	L99PM62drv_Set_LIN();
	L99PM62drv_SetWdTime ((L99PM62drv_WdTimeType)L99PM62drv_WdTime);
	L99PM62drv_WdgTrigger ();  // L99PM62 WdgTrigger Reverse in 65ms	
	
}
void  L99PM62_vMain(void)
{     
	/*To Something*/		
       L99PM62drv_PowerOn_Diagnosis();
}
void  L99PM62_vReset(void)
{     
	//L99PM62_vInit();
	
}

void  L99PM62_vDeinit(void)
{
	//may deinit WD_and_Status register, when KL15 off

}
void  L99PM62_vActive(void)
{
	/*To Something*/ 
}
void  L99PM62_vActiveStandby(void)
{	
	L99PM62drv_SetPWM1Duty ( 0 );
	L99PM62drv_SetPWM2Duty ( 0 );
	L99PM62drv_SetPWM3Duty ( 0 );
	L99PM62drv_SetPWM4Duty ( 0 );
	L99PM62drv_SetCanActMode(Fun_DISABLE);
	
	L99PM62drv_Set_Wakeup();
	L99PM62drv_SetWuCanEn (Fun_ENABLE);
	L99PM62drv_SetWuLinEn (Fun_ENABLE);
	L99PM62drv_SetStandbyMode (L99PM62DRV_STANDBYMODE_VBAT);
}

