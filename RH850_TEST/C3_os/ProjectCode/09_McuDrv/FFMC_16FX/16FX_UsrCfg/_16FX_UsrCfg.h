/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial, special MCU is MB96F693Rx
| File Name: _16FX_UsrCfg.h
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2015 Huizhou Desay SV Automotive Co., Ltd.    All rights reserved.
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
| 2015.07.28  V0.01	Tan, fumin	:create this module
| 2016.06.20  V0.03	Tan, fumin	add LVI disable configeration option!
********************************************************************************/

#ifndef FX16_USRCFG_H
#define FX16_USRCFG_H

/************************************************************
	MCU Basic setting:
	
LVI level setting:	
				min	Typic    Max
	LVL = 0000B 	2.70 [2.90] 3.10 V
	LVL = 0001B 	2.79 [3.00] 3.21 V
[[	LVL = 0010B 	2.98 [3.20] 3.42 V	]] <---default
	LVL = 0011B 	3.26 [3.50] 3.74 V
	LVL = 0100B 	3.45 [3.70] 3.95 V
	LVL = 0111B 	3.73 [4.00] 4.27 V
	LVL = 1001B 	3.91 [4.20] 4.49 V

	LVI disable = 0xFF
	
************************************************************/
#define MCU_mExternOSC_Frequency		/*set it in asm file!*/
#define MCU_mOSCwaitCount			/*set it in asm file!*/
#define MCU_mWatchDogInterval			/*set it in asm file!*/
#define MCU_mLVIlevelSetting			2U

/************************************************************
to enable the interrupt nesting function, set it to 1u:
WARNNING:
	if set this to 1, the interrput will nesting enable and the interrupt service
	run as the interrupt-prority queue and it need more stack for preemptived
	interrupt levels
************************************************************/
#define MCU_mINTNestingEnable		0u/*<--Always set to 0!*/


/************************************************************
to open the MCU_mChangeVectorPriority function, set it to 1u
************************************************************/
#define MCU_mINTPriorityChgEnable		0u

/************************************************************
to open the Port Model, set it to 1u
*************************************************************/
#define MCU_mPortModeEnable	0u

/************************************************************
to open the MCU_vPinWrite/MCU_u8PinRead function, set it to 1u
*************************************************************/
#define MCU_mPinDataOperEnable	0u

/************************************************************
to open the Pin write value function, if you want to check the pin resault, set it to 1u
WARNNING:
		if not special using, set this value to 0u to avoid system error!
************************************************************/
#define MCU_mPinWriteResaultChkEnable		0u

/************************************************************
to open the MCU_vPinDirectCfg function, set it to 1u
************************************************************/
#define MCU_mPinDirectOperEnable	0u

/************************************************************
to open the MCU_vPinPullUpCfg function, set it to 1u
************************************************************/
#define MCU_mPinPullUpOperEnable	0u

/************************************************************
to open the MCU_vPinPullDownCfg function, set it to 1u
************************************************************/
#define MCU_mPinPullDownOperEnable	0u

/************************************************************
to open the MCU_vPinHighDrvCfg function, set it to 1u
************************************************************/
#define MCU_mPinHighDrvOperEnable	0u

/************************************************************
to open the Re-LoadTimer model, set it to 1u
************************************************************/
#define MCU_mTimerModelEnable		0u

/************************************************************
to open the MCU_vReloadTimerChgInterval function, set it to 1u
************************************************************/
#define MCU_mTimerIntervalChgEnable		0u

/************************************************************
to open the PPG model, set it to 1u
************************************************************/
#define MCU_mPPGModeEnable		0u

/************************************************************
to open the MCU_vPPGDeInit function, set it to 1u
************************************************************/
#define MCU_mPPGDeInitEnable		0u

/************************************************************
to open the MCU_vPPGSetHz function, set it to 1u
************************************************************/
#define MCU_mPPGSetHzEnable		0u

/************************************************************
to open the External Interrupt Model, set it to 1u
************************************************************/
#define MCU_mEINTModelEnable		0u

/************************************************************
to open the MCU_vEINTchgIntCondition function, set it to 1u
************************************************************/
#define MCU_mEINTtrigChgFuncEnable		0u

/************************************************************
to open the MCU_vEINTenable function, set it to 1u
************************************************************/
#define MCU_mEINTOnOffCtrlFuncEnable		0u

/************************************************************
to open the MCU_vEINTDeInit function, set it to 1u
************************************************************/
#define MCU_mEINTDeInitFuncEnable		0u

/************************************************************
to open the ADCmodel, set it to 1u
************************************************************/
#define MCU_mADCModelEnable		0u

/************************************************************
to open the MCU_vADCDeInit function, set it to 1u
************************************************************/
#define MCU_mADCDeInitFuncEnable		0u

/************************************************************
to open the DMA model, set it to 1u
************************************************************/
#define MCU_mDMAmodelEnable		0u

/************************************************************
to open the DMA manage ADC interrupt function, set it to 1u
************************************************************/
#define MCU_mDMAforADCEnable		0u

/************************************************************
to open the MCU_vDMADeInit function, set it to 1u
************************************************************/
#define MCU_mDMADeInitFuncEnable		0u

/************************************************************
to open the UART model, set it to 1u
************************************************************/
#define MCU_mUARTmodelEnable		0u

/************************************************************
to open the MCU_vUARTDeInit function, set it to 1u
************************************************************/
#define MCU_mUARTDeInitFuncEnable		0u

/************************************************************
to open the ICU model, set it to 1u
************************************************************/
#define MCU_mICUmodelEnable		0u

/************************************************************
to open the on chip LCD module, set it to 1u
************************************************************/
#define MCU_mLCDmodelEnable		0u

/************************************************************
to open the on chip I2C module, set it to 1u
************************************************************/
#define MCU_mIICmodelEnable		0u

/************************************************************
to open the IMCU_vICUDeInit function, set it to 1u
************************************************************/
#define MCU_mIICUDeInitFuncEnable		0u

/************************************************************
to define the max slave divice mount in a channel
************************************************************/
#define MCU_mI2CMaxSlaveInOneMaster		1u

/************************************************************
to open MCUDbug module, set it to 1u

---set this value to 0u always---

************************************************************/
#define _16FX_Debug		0u

#endif


