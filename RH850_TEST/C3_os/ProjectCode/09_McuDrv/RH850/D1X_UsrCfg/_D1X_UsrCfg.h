/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L_UsrCfg.h
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2016 Huizhou Desay SV Automotive Co., Ltd.    All rights reserved.
|
| This software is copyright protected and proprietary to Desay SV Automotive Co., Ltd.
| Desay SV Automotive Co., Ltd grants to you only those rights as set out in the
| license conditions. All other rights remain with Desay SV Automotive Co., Ltd.
|
| REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
| Name                                  Company
| ---------------------     ---------------------------------------
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2016.02.23  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifndef _D1X_USRCFG_H_
#define _D1X_USRCFG_H_

/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@			system setting   
		@@@@@@@@@@		  

VERY IMPORTANT:

	the option byte_0 must set this value:
		OPT_byte0 = 0xFFFC8F8F;
		
####################################################*/
/********************************************
		===>>vector table start address:<<===
please refer to link document [.ld file]

IMPORTANT:

	if using the _F1L_Map_NotBootLoader.ld, set this value to 0
	if using the_F1L_Map_WithBootLoader.ld, set this value to same value with the
	end address of [iROM_Boot section] 
	
*********************************************/
#define APP_CODE_MAP_START                 0x0000000u

/********************************************
		===>>vector table start address:<<===
please refer to link document [.ld file]

IMPORTANT:

	adsolute address = [APP_CODE_MAP_START+IRQ_TABLE_START]
*********************************************/
#define IRQ_TABLE_START                 0x00000200u

/********************************************
to enable the interrupt nesting function, set it to 1u:

WARNNING:

	------ALWAYS set this value to 0u ------
	
	if set this to 1, the interrput will nesting enable and the interrupt service
	run as the interrupt-prority queue and it need more stack for preemptived
	interrupt levels
***********************************************/
#define MCU_mINTNestingEnable		0u/*<--Always set to 0!*/

/************************************************************
to open MCUDbug module, set it to 1u
************************************************************/
#define _RH850_Debug				0u/*<--Always set to 0!*/

/********************************************
to open the MCU_mChangeVectorPriority function, set it to 1u
***********************************************/
#define MCU_mINTPriorityChgEnable		0u

/*********************************************
to define the voltage level for LVI(Low Voltage Reset)

MCU_mLVI_Level:

	0: LVI is ignored
	1: 4.0+/-0.1 V (drop), 4.0+/-0.13 V (rise)
	2: 3.7+/-0.1 V (drop), 3.7+/-0.13 V (rise)
	3: 3.5+/-0.1 V (drop), 3.5+/-0.13 V (rise)

*****************************************/
#define MCU_mLVI_Level		0u/*<--Always set to 0 because D1X not mount this function !*/


/*****************************************
watchdog configuration:

 watchdog_0:
 ========================================
	  range = 0-->7
		 watchdog reset time = 
			 2^(9 +WatchDog1_Interval) * C_AWO_WDTA0  
		 
 watchdog_1:
 ========================================
	  range = 0-->7
		 watchdog reset time = 
			 2^(9 +WatchDog1_Interval) * (fRL/4)
			 = 2^(9 +WatchDog1_Interval) *60kHz
		
WARNING:

	please refer to the option byte setting, make sure set the watchdog as follow:
	1, enble all watchdog
	2,start type = software trigger start mode
	3,clean code mode OPWDVAC =0
	
*********************************************************************/
#define MCU_mResetTime_WD0		6u
#define MCU_mResetTime_WD1		6u

/************************************************************
to open the MCU_vClockInit_ClockMonitor function, set it to 1u
************************************************************/
#define MCU_mClockMonitorEnable		0u/*<--Always set to 0!*/

/************************************************************
to open the MCU_vStandbyCtrl_ChgToMode function, set it to 1u
************************************************************/
#define MCU_mCPUModeCtrlEnable		0u

/************************************************************
to open the MCU_u32GetWakeUpFactor function, set it to 1u
************************************************************/
#define MCU_mGetWakeUpFactorEnable		0u

/************************************************************
to open the FE interrupt partition, set it to 1u
************************************************************/
#define MCU_mFEinterruptEnable		0u

/************************************************************
to open the MCU_u16InterruptFlagClean function, set it to 1u
************************************************************/
#define MCU_mClearIF_Enable		0u

/************************************************************
to open the stack-related function, set it to 1u
************************************************************/
#define MCU_mSackFunctionEnable		0u

/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		port setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the Port Model, set it to 1u
*************************************************************/
#define MCU_mPortModuleEnable	1u

/************************************************************
to open the MCU_vPinWrite/MCU_u8PinRead function, set it to 1u
*************************************************************/
#define MCU_mPinDataOperEnable	0u

/************************************************************
to open the MCU_vPinDirectCfg function, set it to 1u
************************************************************/
#define MCU_mPinDirectOperEnable	0u

/************************************************************
to open the MCU_vPinPullUpCfg function, set it to 1u
************************************************************/
#define MCU_mPinPullUpOperEnable	0u

/************************************************************
to open the MCU_vPinPullUpCfg function, set it to 1u
************************************************************/
#define MCU_mPinPullDownOperEnable	0u

/************************************************************
to open the MCU_u16PinOpenDCfg function, set it to 1u
************************************************************/
#define MCU_mPinOpenDEnable	0u

/************************************************************
to open the MCU_u16PinOpenDCfg function, set it to 1u
************************************************************/
#define MCU_mPinAltFunChgEnable	0u

/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		OSTM setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the OSTM model, set it to 1u
************************************************************/
#define MCU_mOSTMModuleEnable		0u

/************************************************************
to open the MCU_u16OSTMctrl function, set it to 1u
************************************************************/
#define MCU_mOstmCtrlEnable		0u

/************************************************************
to open the MCU_u16OSTMChgInterval function, set it to 1u
************************************************************/
#define MCU_mOstmChangeEnable		0u


/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		PWGA setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the PPG model, set it to 1u
************************************************************/
#define MCU_mPWGAModuleEnable		0u

/************************************************************
to open the MCU_u16PWGASetDuty function, set it to 1u
************************************************************/
#define MCU_mPWGAdutyChangeEnable		0u


/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		TAUX setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the TAUBD model, set it to 1u
************************************************************/
#define MCU_mTAUBDModuleEnable		0u

/************************************************************
to open the TAUBJ model, set it to 1u
************************************************************/
#define MCU_mTAUJModuleEnable		0u

/************************************************************
to open the MCU_u16TAUxSetCounter function, set it to 1u
************************************************************/
#define MCU_mTauxSetCounterEnable		0u

/************************************************************
to open the MCU_u16TAUxPpgSetHz function, set it to 1u
************************************************************/
#define MCU_mTauxSetHzEnable		0u

/************************************************************
to open the MCU_u16TAUxPpgSetDuty function, set it to 1u
************************************************************/
#define MCU_mTauxSetDutyEnable		0u

/************************************************************
to open the MCU_vTAUxRunCtrl function, set it to 1u
************************************************************/
#define MCU_mTuaxRunCtrlEnale		0u

/************************************************************
to open the MCU_u32TAUxGetCounter function, set it to 1u
************************************************************/
#define MCU_mTauxGetCounterEnable		0u

/************************************************************
to open the MCU_u32TAUxGetTime function, set it to 1u
************************************************************/
#define MCU_mTauxGetTimeEnable		0u


/*##################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		EINT setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the External Interrupt Model, set it to 1u
************************************************************/
#define MCU_mEINTModuleEnable		0u

/************************************************************
to open the MCU_u16EINTchgIntCondition function, set it to 1u
************************************************************/
#define MCU_mEINTtrigChgFuncEnable		0u

/************************************************************
to open the MCU_u16EINTenable function, set it to 1u
************************************************************/
#define MCU_mEINTOnOffCtrlFuncEnable		0u

/************************************************************
to open the MCU_vEINTDeInit function, set it to 1u
************************************************************/
#define MCU_mEINTDeInitFuncEnable		0u


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		ADC setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the ADCmodel, set it to 1u
************************************************************/
#define MCU_mADCModuleEnable		0u

/************************************************************
to open the MCU_u16ADCstop, set it to 1u
************************************************************/
#define MCU_mADCstopEnable		0u
 
/************************************************************
to open the MCU_u16ADCsleep/ wakeup function, set it to 1u
***********************************************************
#define MCU_mADCSleepEnable		0u*/

/************************************************************
to open the MCU_vADCDeInit function, set it to 1u
************************************************************/
#define MCU_mADCDeInitFuncEnable		0u


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		DMA setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the DMA model, set it to 1u
************************************************************/
#define MCU_mDMAModuleEnable		0u/*<--Always set to 0! it not finish in D1X*/

/************************************************************
to open the DMA model function MCU_u16DMAsetup, set it to 1u
************************************************************/
#define MCU_mDMASetUpIfEnable		0u


/************************************************************
to open the DMA model function MCU_u16DMADefaultSetup, set it to 1u
************************************************************/
#define MCU_DMAdefaultSetEnable		0u


/************************************************************
to open the MCU_vDMADeInit function, set it to 1u
************************************************************/
#define MCU_mDMADeInitFuncEnable		0u


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		RLIN3 setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the LIN-UART model, set it to 1u
************************************************************/
#define MCU_mRLIN3UartModuleEnable		0u

/************************************************************
to open the MCU_u16RLIN3UartCtrl function, set it to 1u
************************************************************/
#define MCU_mRlin3CtrlEnale		0u

/************************************************************
to open the MCU_vLinUart_Deint function, set it to 1u
************************************************************/
#define MCU_mRLIN3DeInitFuncEnable		0u


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		IIC setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the on ship IIC model, set it to 1u
************************************************************/
#define MCU_mIICModuleEnable		0u

/************************************************************
to open the MCU_u16IIC_MasterRec function, set it to 1u
************************************************************/
#define MCU_mIICReadFunctionEnable		0u

/************************************************************
to open the MCU_u16IIC_MasterReStartCondition function, set it to 1u
************************************************************/
#define MCU_mIICRestartEnable		0u

/************************************************************
to configeration the slave node number in a IIC net, more then 1 !
************************************************************/
#define MCU_mI2CMaxSlaveInMaster		1u

/************************************************************
to open the MCU_vIICdeinit function, set it to 1u
************************************************************/
#define MCU_mIICdeinitEnable		0u

/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIG setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the on chip CSIG module, set it to 1u
************************************************************/
#define MCU_mCSIGModuleEnable		0u

/************************************************************
to open the MCU_u16CSIG_MasterSynchRW function, set it to 1u
************************************************************/
#define MCU_mCSIGMasterSynchRWEnable		0u


/************************************************************
to open the MCU_u16CSIG_MasterWrite function, set it to 1u
************************************************************/
#define MCU_mCSIGMasterWriteEnable		0u


/************************************************************
to open the MCU_u16CSIG_MasterRead function, set it to 1u
************************************************************/
#define MCU_mCSIGMasterReadEnable		0u


/************************************************************
to open the MCU_u16CSIG_ChgClkType function, set it to 1u
************************************************************/
#define MCU_mCSIGClkPhaseChgEnable		0u


/************************************************************
to open the MCU_vCSIGdeinit function, set it to 1u
************************************************************/
#define MCU_mCSIGdeinitEnable		0u


/*################################################
		@@@@@@@@@@		     
@@@@@@@@@@@@@@@@@		CSIH setting   
		@@@@@@@@@@		  
####################################################*/

/************************************************************
to open the on chip CSIH module, set it to 1u
************************************************************/
#define MCU_mCSIHModuleEnable		0u

/************************************************************
to open the MCU_u16CSIH_MasterSynchRW function, set it to 1u
************************************************************/
#define MCU_mCSIHMasterSynchRWEnable		0u


/************************************************************
to open the MCU_u16CSIH_MasterWrite function, set it to 1u
************************************************************/
#define MCU_mCSIHMasterWriteEnable		0u


/************************************************************
to open the MCU_u16CSIH_MasterRead function, set it to 1u
************************************************************/
#define MCU_mCSIHMasterReadEnable		0u


/************************************************************
to open the MCU_u16CSIH_ChgClkType function, set it to 1u
************************************************************/
#define MCU_mCSIHClkPhaseChgEnable		0u

/************************************************************
to open the Job concept function, set it to 1u
************************************************************/
#define MCU_mCSIHJobEnable		0u

/************************************************************
to open the MCU_vCSIHdeinit function, set it to 1u
************************************************************/
#define MCU_mCSIHdeinitEnable		0u

#if _RH850_Debug !=0

#define MCU_Debug_Clock		0
#define MCU_Debug_OSTM		0		
#define MCU_Debug_WatchDog		0
#define MCU_Debug_ResetMonitor		0
#define MCU_Debug_CSIx		0
#define MCU_Debug_EINT		0
#define MCU_Debug_TAUx		0
#define MCU_Debug_WakeUp		0
#define MCU_Debug_ADC		0

/******************************************************************************
***

MCU Driver debug macro, 
to set the dubug pin for monitor

*******************************************************************************
**/
/***************************
Debug pin for monitor module: clock
****************************/
#if MCU_Debug_Clock
#define Debug_SetPin_Clock(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_Clock(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: OSTM
****************************/
#if MCU_Debug_OSTM
#define Debug_SetPin_OSTM(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_OSTM(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: WatchDog
****************************/
#if MCU_Debug_WatchDog
#define Debug_SetPin_WD(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_WD(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: Reset Monitor
****************************/
#if MCU_Debug_ResetMonitor
#define Debug_SetPin_Reset(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_Reset(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: CSIx
****************************/
#if MCU_Debug_CSIx
#define Debug_SetPin_CSIx(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else	
#define Debug_SetPin_CSIx(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: EINT
****************************/
#if MCU_Debug_EINT
#define Debug_SetPin_EINT(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_EINT(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: TAUx
****************************/
#if MCU_Debug_TAUx
#define Debug_SetPin_TAUx(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_TAUx(port,pin,HighLow)
#endif
/***************************
Debug pin for monitor module: wakeup
****************************/
#if MCU_Debug_WakeUp
#define Debug_SetPin_WakeUp(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_WakeUp(port,pin,HighLow)
#endif

/***************************
Debug pin for monitor module: ADC
****************************/
#if MCU_Debug_ADC
#define Debug_SetPin_ADC(port,pin,HighLow) do{PM##port &=~(1<<(pin));if((HighLow)==0)P##port &=~(1<<(pin)); else P##port |=(1<<(pin));}while(0)
#else
#define Debug_SetPin_ADC(port,pin,HighLow)
#endif
#endif

#endif /*end of this file*/


