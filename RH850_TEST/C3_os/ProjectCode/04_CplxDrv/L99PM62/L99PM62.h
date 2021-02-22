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
#include "general.h"
#ifndef L99PM62_H
#define L99PM62_H
#include "s_spi.h"
#include "L99PM62_Type.h"
#include "L99PM62_Private.h"
#define L99PM62_WR_Regs(OutDataHead,RecDataHead)		SPI_u16SlaveSelect_CH1(0,0);\
														SPI_u16TransferData_CH1(OutDataHead,RecDataHead,3);\
														SPI_u16SlaveSelect_CH1(0,1);\
														S_SPI_CH1_CSNDelay()	
														
#define L99PM62drv_WdTime 	L99PM62DRV_WDTIMER_200ms
/*
L99PM62DRV_WDTIMER_10  dont use
L99PM62DRV_WDTIMER_50
L99PM62DRV_WDTIMER_100
L99PM62DRV_WDTIMER_200
*/
/*
L99PM62DRV_WDTIMER_10,   Sfe Time 7.5---12ms
L99PM62DRV_WDTIMER_50,   Sfe Time 37.5---60ms
L99PM62DRV_WDTIMER_100,  Sfe Time 75---120ms
L99PM62DRV_WDTIMER_200,  safe time  150---240ms
*/				
#if (L99PM62drv_WdTime == L99PM62DRV_WDTIMER_50ms)
#define WD_Trig_Num   4u
#endif
#if (L99PM62drv_WdTime == L99PM62DRV_WDTIMER_100ms)
#define WD_Trig_Num   8u
#endif
#if (L99PM62drv_WdTime == L99PM62DRV_WDTIMER_200ms)
#define WD_Trig_Num   16u
#endif
#define L99PM62DRV_MASK_OUT1  0x10U
#define L99PM62DRV_MASK_OUT2  0x20U
#define L99PM62DRV_MASK_OUT3  0x40U
#define L99PM62DRV_MASK_OUT4  0x80U
#define L99PM62DRV_MASK_OUTHS 0x01U
#define L99PM62DRV_MASK_WU1   0x01U
#define L99PM62DRV_MASK_WU2   0x02U
#define L99PM62DRV_MASK_WU3   0x04U
#define L99PM62DRV_MASK_WU4   0x08U

#define L99PM62DRV_OUT_Off          0x00U
#define L99PM62DRV_OUT_ON          0x58U
#define L99PM62DRV_OUT_timer1    0x41U
#define L99PM62DRV_OUT_Timer2    0XC2U
#define L99PM62DRV_OUT_PWM1     0X00U
#define L99PM62DRV_OUT_PWM2     0XC0U
#define L99PM62DRV_OUT_PWM3     0X8CU
#define L99PM62DRV_OUT_PWM4     0XA0U
#define L99PM62DRV_OUT_FSO        0X00U
/*******************************************************************************
*********** Internal Constants and Protypes - non-application related **********
*******************************************************************************/

// start flag
#define COLD_START_FLAG			0x01u
#define POWER_ON_FLAG				0x02u
#define POWER_ON_WEAK_FLAG		0x03u
#define COMMUNICATION_FLAG		0x04u			
#define OV_UV_FLAG					0x05u
#define WD_FAIL_FLAG				0x06u
#define TSD1_FLAG					0x07u
#define TSD2_FLAG					0x08u
#define V1_FAIL_FLAG				0x09u
#define OTHER_FAIL_FLAG				0x0au
#define UNKNOWN					0x0bu
// wake up flag
#define WAKE_TIMER_INT_FLAG		0x10u
#define WAKE_LIN_FLAG				0x11u
#define WAKE_CAN_FLAG				0x12u
#define WU1_WAKE_FLAG				0x13u
#define WU2_WAKE_FLAG				0x14u
#define WU3_WAKE_FLAG				0x15u


/*! L99PM62drv_StatusRegType defines global data type for access to complete local
copy of L99PM62 Status registers 0 and 1. Access to internal structure and
particular bit variables of each status register is provided by set of mask
related to each bit variable inside the status register.*/



/*******************************************************************************
********************************** Functions ***********************************
*******************************************************************************/

/*! This module shall initialize the whole L99PM62 driver.*/
void L99PM62drv_Init (void);

//config1
/*! This module set WdgTrigger.*/
void L99PM62drv_WdgTrigger(void);

/*! This module set standby mode.*/
void L99PM62drv_SetStandbyMode(L99PM62drv_StandbyModeType mode);

/*! This module set VoltageReg2Mode.*/
void L99PM62drv_SetVoltageReg2Mode (L99PM62drv_VoltageReg2ModeType mode);
/*! This module set RelayOutput.*/
void L99PM62drv_SetRelayOutput (L99PM62drv_RelayOutputType value);

/*! This module set out Mode.*/
void L99PM62drv_SetOutMode (uint8_t mask, uint8_t L99PM62DRV_OUT_mode);

//config2
/*! This module set DisableWakeupSource.*/
void L99PM62drv_DisableWakeupSource(uint8_t mask, FunctionalState mode);

/*! This module set WUInputMode.*/
void L99PM62drv_SetWUInputMode(uint8_t mask, L99PM62drv_WUInputModeType mode);

/*! This module set InputFilterMode.*/
void L99PM62drv_SetInputFilterMode(uint8_t mask, L99PM62drv_InputFilterModeType mode);


//config3
/*! set wake up timer.*/
void L99PM62drv_SetWuTimerSelect (L99PM62drv_SetWuTimerSelectType mode);

/*! set wake up timer enable/disable.*/
void L99PM62drv_SetWuTimerEn (FunctionalState mode);

/*! set can as wake up source.*/
void L99PM62drv_SetWuCanEn (FunctionalState mode);

/*! set lin as wake up source.*/
void L99PM62drv_SetWuLinEn (FunctionalState mode);

/*! set watchdog.*/
void L99PM62drv_SetWdTime (L99PM62drv_WdTimeType mode);

/*! This module set Timer1.*/
void L99PM62drv_SetTimer1(L99PM62drv_Timer1PeriodType period, L99PM62drv_Timer1ONTimeType ontime);

/*! This module set Timer2.*/
void L99PM62drv_SetTimer2 (L99PM62drv_Timer2PeriodType period, L99PM62drv_Timer2ONTimeType ontime);


//config4
/*! enables/disables CAN receive only during Active mode.*/
void L99PM62drv_SetCanRecOnlyMode (FunctionalState mode);

/*! enables/disables CAN split termination during Active mode.*/
void L99PM62drv_SetCanSplitMode (FunctionalState mode);

/*! enables/disables CAN pattern wake.*/
void L99PM62drv_SetCanPattWakeMode (FunctionalState mode);

/*! enables/disables CAN loop.*/
void L99PM62drv_SetCanLoopMode (FunctionalState mode);

/*! enables/disables CAN active during Active mode.*/
void L99PM62drv_SetCanActMode (FunctionalState mode);

/*! This module set Lin.*/
void L99PM62drv_LinSetup(L99PM62drv_LinSetupType value);

/*! This module set ResetThresholdLevel.*/
void L99PM62drv_SetResetThresholdLevel(L99PM62drv_ResetThresholdLevelType level);

/*! This module set RelayShutdownMode.*/
void L99PM62drv_SetRelayShutdownMode(FunctionalState mode);

/*! This module set VsLockoutMode.*/
void L99PM62drv_SetVsLockoutMode(FunctionalState mode);

/*! This module set OutHS autorecovery.*/
void L99PM62drv_SetOutHSAutorecovery (FunctionalState mode);

/*! set VReg1 Current Monitor On.*/
void L99PM62drv_SetVReg1CurrentMonitorOn (FunctionalState mode);


//config5

/*! set L99PM62-internal pwm freqent.*/
void L99PM62drv_SetPWMFreq (L99PM62drv_PWMFreqType value);

/*! set L99PM62-internal pwm1 duty cycle.*/
void L99PM62drv_SetPWM1Duty(uint8_t L99PM62drv_PWM1Duty) ;

/*! set L99PM62-internal pwm2 duty cycle.*/
void L99PM62drv_SetPWM2Duty (uint8_t L99PM62drv_PWM2Duty);


//config6
/*! set L99PM62-internal pwm3 duty cycle.*/
void L99PM62drv_SetPWM3Duty (uint8_t L99PM62drv_PWM3Duty);

/*! set L99PM62-internal pwm4 duty cycle.*/
void L99PM62drv_SetPWM4Duty (uint8_t L99PM62drv_PWM4Duty);


/*! This module set GlobalErrorStatus.*/
boolean L99PM62drv_GetGlobalErrorStatus(void);

/*! This module set Status1.*/
uint32_t L99PM62drv_GetStatus1 (void);

/*! This module set Status2.*/
uint32_t L99PM62drv_GetStatus2 (void);

/*! This module set Status3.*/
uint32_t L99PM62drv_GetStatus3 (void);
/*******************************************************************************
********************************** Functions ***********************************
*******************************************************************************/

uint8_t L99PM62drv_Go_Standby(L99PM62drv_StandbyModeType mode);
uint8_t L99PM62drv_PowerOn_Diagnosis(void);
uint8_t L99PM62drv_WakeUp_Diagnosis(void);
uint8_t L99PM62drv_Set_Output(void);
void L99PM62drv_Set_Wakeup(void);
void L99PM62drv_Set_CAN(void);
void L99PM62drv_Set_LIN(void);
void L99PM62_WdgForegroundTrigger(void);
void  L99PM62_vInit(void);
void  L99PM62_vMain(void);
void  L99PM62_vReset(void);
void  L99PM62_vDeinit(void);
void  L99PM62_vActive(void);
void  L99PM62_vActiveStandby(void);

#endif

