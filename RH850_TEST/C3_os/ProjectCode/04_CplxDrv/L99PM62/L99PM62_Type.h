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
#ifndef L99PM62_Type_H
#define L99PM62_Type_H


typedef enum {
  Fun_DISABLE = 0,
  Fun_ENABLE = !DISABLE
} FunctionalState;

/*! Defines Stand by modes of L99PM62. */
typedef enum { 
    L99PM62DRV_STANDBYMODE_V1,    /*!< Switch L99PM62 to V1 stand by mode. */
    L99PM62DRV_STANDBYMODE_VBAT   /*!< Switch L99PM62 to Vbat stand by mode. */
}L99PM62drv_StandbyModeType;

typedef enum {
    L99PM62DRV_Write_Mode,    
    L99PM62DRV_Read_Mode,   
    L99PM62DRV_ReadAndClear,   
    L99PM62DRV_ReadDeviceInformation           
} L99PM62drv_RWMode;


/*! Defines modes of L99PM62 voltage regulator 2.*/
typedef enum {
    L99PM62DRV_VOLTAGE_REG2_OFF,          /*!< Switch voltage regulator 2 always
                                            off.*/
    L99PM62DRV_VOLTAGE_REG2_ON_ACTIVE,    /*!< Switch voltage regulator 2 on only
                                            when L99PM62 is in active mode.*/
    L99PM62DRV_VOLTAGE_REG2_ON_V1,        /*!< Switch voltage regulator 2 on only
                                            when L99PM62 is in active mode or V1
                                            standby mode.*/
    L99PM62DRV_VOLTAGE_REG2_ON            /*!< Switch voltage regulator 2 always
                                            on.*/
} L99PM62drv_VoltageReg2ModeType;

/*! Defines states for relay outputs controlling.*/
typedef enum {
    RELAYOUTPUT_OFF_OFF,   /*!< Switch both relays off.*/
    RELAYOUTPUT_ON_OFF,     /*!< Switch relay REL1 on and REL2 off.*/
    RELAYOUTPUT_OFF_ON,     /*!< Switch relay REL1 off and REL2 on.*/
    RELAYOUTPUT_ON_ON,       /*!< Switch both relays on.*/
    RELAYOUTPUT_OFF_X,       /*!< Switch relay REL1 off and refresh previous 
                               				 state of REL2 (don't change).*/
    RELAYOUTPUT_ON_X,        /*!< Switch relay REL1 on and refresh previous 
                               				 stateof REL2 (don't change).*/
    RELAYOUTPUT_X_OFF,       /*!< Switch relay REL2 off and refresh previous
                                		 	state of REL1 (don't  change).*/
    RELAYOUTPUT_X_ON          /*!< Switch relay REL2 on and refresh previous
                                			state of REL1 (don't change).*/
} L99PM62drv_RelayOutputType;
/*! Defines output mode of HS outputs. */
typedef enum {
    L99PM62DRV_OUT_MODE_OFF,      /*!< Driver is OFF in all modes.*/
    L99PM62DRV_OUT_MODE_TIMER1,   /*!< Driver is cyclic ON with the timing of
                                    Timer1 in active mode and stand by modes.*/		
    L99PM62DRV_OUT_MODE_PWM4,      /*!< Driver is controlled by the PWM4 input.*/
    L99PM62DRV_OUT_MODE_TIMER2,   /*!< Driver is cyclic ON with the timing of
                                    Timer2 in active mode and stand by modes.*/
    L99PM62DRV_OUT_MODE_PWM1,     /*!< Driver is controlled by the PWM1 input.*/
    L99PM62DRV_OUT_MODE_ON,       /*!< Driver is ON in active mode, OFF in standby
                                    mode.*/
    L99PM62DRV_OUT_MODE_PWM3,      /*!< Driver is controlled by the PWM3 input.*/
    L99PM62DRV_OUT_MODE_PWM2,      /*!< Driver is controlled by the PWM2 input.*/
    L99PM62DRV_OUT_MODE_FSO       /*!< Driver is controlled by the FSO input.*/
} L99PM62drv_OutModeType;

/*! Defines current source / current sink  mode for related WU inputs.*/
typedef enum {
    L99PM62DRV_WU_INPUT_MODE_CUR_SINK,/*!< Defines current sink (pull down)
                                            mode for related WU input.*/
    L99PM62DRV_WU_INPUT_MODE_CUR_SOURCE   /*!< Defines current source 
                                        (pull up) mode for related WU input.*/
} L99PM62drv_WUInputModeType;

/*! Defines input filter configuration for related WU inputs.*/
typedef enum {
    L99PM62DRV_IN_FILTER_64,         /*!< Defines input filter time value
                                           to 64us unsynchronized.*/
    L99PM62DRV_IN_FILTER_80_TIMER2,  /*!< Defines input filter time value
                                            to 80us synchronized with timer 2.*/
    L99PM62DRV_IN_FILTER_800_TIMER2, /*!< Defines input filter time value
                                           to 800us synchronized with timer 2.*/
    L99PM62DRV_IN_FILTER_800_TIMER1  /*!< Defines input filter time value
                                           to 800us synchronized with timer 1.*/
} L99PM62drv_InputFilterModeType;

/*! Defines timer select for wakeup.*/
typedef enum {
    L99PM62DRV_WUTIMER_2,            /*!< Select wake up timer2.*/
    L99PM62DRV_WUTIMER_1              /*!< Select wake up timer1.*/
} L99PM62drv_SetWuTimerSelectType;

/*! Defines WD timer period.*/

typedef enum {
    L99PM62DRV_WDTIMER_10,     /*!< Set wdtimer period to 10ms.*/
    L99PM62DRV_WDTIMER_50,     /*!< Set wdtimer period to 50ms.*/
    L99PM62DRV_WDTIMER_100,     /*!< Set wdtimer period to 100ms.*/
    L99PM62DRV_WDTIMER_200      /*!< Set wdtimer period to 200ms.*/
} L99PM62drv_WdTimeType;

#define L99PM62DRV_WDTIMER_10ms 	0
#define L99PM62DRV_WDTIMER_50ms		1
#define L99PM62DRV_WDTIMER_100ms		2
#define L99PM62DRV_WDTIMER_200ms	3

/*! Defines period of L99PM62 timer 1.*/
typedef enum {
    L99PM62DRV_TIMER1PERIOD_1000,     /*!< Set timer 1 period to 1s.*/
    L99PM62DRV_TIMER1PERIOD_2000,     /*!< Set timer 1 period to 2s.*/
    L99PM62DRV_TIMER1PERIOD_3000,     /*!< Set timer 1 period to 3s.*/
    L99PM62DRV_TIMER1PERIOD_4000      /*!< Set timer 1 period to 4s.*/
} L99PM62drv_Timer1PeriodType;

/*! Defines ON Time parameter of L99PM62 timer 1.*/
typedef enum {
    L99PM62DRV_TIMER1ONTIME_10,       /*!< Defines ON time value 10ms.*/
    L99PM62DRV_TIMER1ONTIME_20        /*!< Defines ON time value 20ms.*/
} L99PM62drv_Timer1ONTimeType;

/*! Defines period of L99PM62 timer 2.*/
typedef enum {
    L99PM62DRV_TIMER2PERIOD_10,     /*!< Set timer 1 period to 10ms.*/
    L99PM62DRV_TIMER2PERIOD_20,     /*!< Set timer 1 period to 20ms.*/
    L99PM62DRV_TIMER2PERIOD_50,     /*!< Set timer 1 period to 50ms.*/
    L99PM62DRV_TIMER2PERIOD_200      /*!< Set timer 1 period to 200ms.*/
} L99PM62drv_Timer2PeriodType;

/*! Defines ON Time parameter of L99PM62 timer 2.*/
typedef enum {
    L99PM62DRV_TIMER2ONTIME_0_1,       /*!< Defines ON time value 0.1ms.*/
    L99PM62DRV_TIMER2ONTIME_1        /*!< Defines ON time value 1ms.*/
} L99PM62drv_Timer2ONTimeType;


/*! Defines all possible configurations related to L99PM62 LIN interface. One of
them to be chosen. */
typedef enum {
    L99PM62DRV_LIN_TIM_EN_PUP_EN,   /*!< Enables master pullup LINPU and
      enables TxD dominant timeout for LIN and enables alternative LIN slope.*/
    L99PM62DRV_LIN_TIM_EN_PUP_DI,   /*!< Disables master pullup LINPU and
      enables TxD dominant timeout for LIN and enables alternative LIN slope.*/
    L99PM62DRV_LIN_TIM_DI_PUP_EN,   /*!< Enables master pullup LINPU and
      disables TxD dominant timeout for LIN and enables alternative LIN slope.*/
    L99PM62DRV_LIN_TIM_DI_PUP_DI    /*!< Disables master pullup LINPU and
      disables TxD dominant timeout for LIN and enables alternative LIN slope.*/
} L99PM62drv_LinSetupType;

/*! Defines reset threshold level value.*/
typedef enum {
    L99PM62DRV_RESET_THRESHOLD_4600,    /*!< Defines reset threshold level 
                                                4,60V.*/
    L99PM62DRV_RESET_THRESHOLD_4350,       /*!< Defines reset threshold level 
                                                4,35V.*/
    L99PM62DRV_RESET_THRESHOLD_4100,    /*!< Defines reset threshold level 
                                                4,10V.*/
    L99PM62DRV_RESET_THRESHOLD_3800       /*!< Defines reset threshold level 
                                                3,80V.*/
} L99PM62drv_ResetThresholdLevelType;


/*! Defines PWM duty cycle for PWM1 and PWM3.*/
//typedef uint8_t L99PM62drv_PWMOnType;

/*! Defines PWM duty cycle for PWM2 and PWM4.*/
//typedef uint8_t L99PM62drv_PWMOffType;

/*! Defines PWM frequent for PWM.*/
typedef enum {
    Freq_128,     /*!< Set PWM frequent to 128hz.*/
    Freq_256      /*!< Set PWM frequent to 256hz.*/
} L99PM62drv_PWMFreqType;

/*! Defines cyclic sense mode.*/
typedef enum {
    CYCLIC_SENSE_TIMER1,     /*!< Set timer1 cyclic sense.*/
    CYCLIC_SENSE_TIMER2,     /*!< Set timer2 cyclic sense.*/
		STATIC_SENSE
}L99PM62drv_CyclicSenseModeType;

#endif
