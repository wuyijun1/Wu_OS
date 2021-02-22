/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial, special MCU is upd78F1xxx
| File Name: _78K0R_UsrCfg.h
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
| 2015.11.28  V0.01	Tan, fumin	:create this module
| 2016.06.21  V0.07	Tan, fumin	1,add LVI enable or disable conf
|								2,add Clock monitor enable or disable
| 2016.07.22  V0.08	Tan, fumin	modify OSC stable time configeration setting to Index type.
********************************************************************************/

#ifndef _78K0R_USRCFG_H
#define _78K0R_USRCFG_H

/************************************************************

=====basic setting for platform information=======

1,---------------

	define the external OSC frequency for CPU clock setting, 
	it may 4000000ul or 8000000ul Hz, check it with EE

2,--------------
	OSC wait stable time:
		setting value					wait count	actual time(in 8M OSC)

	0 =	1 0 0 0 0 0 0 0(0x80U) 	 		2^8/fX 		min. 32.1us
	1 =	1 1 0 0 0 0 0 0(0xC0U) 	 		2^9/fX 		min. 64.2us
	2 =	1 1 1 0 0 0 0 0(0xE0U) 	 		2^10/fX 		min. 128.4us
	3 =	1 1 1 1 0 0 0 0(0xF0U) 	 		2^11/fX 		min. 256.8us
     [4] =	1 1 1 1 1 0 0 0(0xF8U)	 		2^13/fX 		min. 1.02 ms <-----default
	5 =	1 1 1 1 1 1 0 0 (0xFCU) 			2^15/fX 		min. 4.11 ms
	6 =	1 1 1 1 1 1 1 0(0xFEU) 	 		2^17/fX 		min. 16.44 ms
	7 =	1 1 1 1 1 1 1 1(0xFFU) 	 		2^18/fX 		min. 32.88 ms
3,--------------
		WatchDog Reset time setting:

		fIL= Internal low-speed oscillation clock frequency, typical is 30kHz
			
			0: (2^7)/fIL 	(4.27 ms)
			1: (2^8)/fIL 	(8.53 ms)
			2: (2^9)/fIL 	(17.07 ms)
			3: (2^10)/fIL 	(34.13 ms)
			4: (2^12)/fIL 	(136.5 ms)
			5: (2^14)/fIL 	(546.1 ms) <-----dafault
			6: (2^15)/fIL 	(1092 ms)
			7: (2^17)/fIL 	(4369 ms)


4,--------------
		Low Voltage reset setting:

			0 0 0 0 	VLVI0 	(4.22 ¡À0.1 V)
			0 0 0 1 	VLVI1 	(4.07 ¡À0.1 V)
			0 0 1 0 	VLVI2 	(3.92 ¡À0.1 V)
			0 0 1 1 	VLVI3 	(3.76 ¡À0.1 V)
			0 1 0 0 	VLVI4 	(3.61 ¡À0.1 V)
			0 1 0 1 	VLVI5 	(3.45 ¡À0.1 V) <-----dafault
			0 1 1 0 	VLVI6 	(3.30 ¡À0.1 V)
			0 1 1 1 	VLVI7 	(3.15 ¡À0.1 V)
			1 0 0 0 	VLVI8 	(2.99 ¡À0.1 V)
			1 0 0 1 	VLVI9 	(2.84 ¡À0.1 V)

!!!			LVI disable = 0xFF 
			
Note:=================================================

power_det: 

	NO veoltage: 1.61 +/- 0.9
	OFF veoltage: 1.59 +/- 0.9

RAM data retention:

	min = 1.5V, Max = 5.5V
	
************************************************************/
#define MCU_mExternOSC_Frequency		8000000ul
#define MCU_mOSCwaitCount			0x4
#define MCU_mWatchDogInterval			5U
#define MCU_mLVIlevelSetting			5U/*0xFF = Disable*/
#define MCU_mSwitchToInternalOSC		0U/*Enable/Disable use Interrnal OSC if MainOSC Error,
										0 = Use MainOSC anyway
										1 = Use Internal OSC if MainOSC Error*/

/************************************************************
to enable the interrupt nesting function, set it to 1u:

WARNNING:

	------ALWAYS set this value to 0u ------
	
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
to open the MCU_vPinDirectCfg function, set it to 1u
************************************************************/
#define MCU_mPinDirectOperEnable	0u

/************************************************************
to open the MCU_vPinPullUpCfg function, set it to 1u
************************************************************/
#define MCU_mPinPullUpOperEnable	0u

/************************************************************
to open the Re-LoadTimer model, set it to 1u
************************************************************/
#define MCU_mTimerModelEnable		0u

/************************************************************
to open the MCU_vReloadTimerChgInterval function, set it to 1u
************************************************************/
#define MCU_mTimerIntervalChgEnable		0u

/************************************************************
to open MCU_vTimerArrayDeinit function, set it to 1u
************************************************************/
#define MCU_mTimerDeintiEnable		0u

/************************************************************
to open the PPG model, set it to 1u
************************************************************/
#define MCU_mPPGModeEnable		0u

/************************************************************
to open the PPG Deinit model, set it to 1u
************************************************************/
#define MCU_mPPGDeInitEnable		0u

/************************************************************
to open the ICU model, set it to 1u
************************************************************/
#define MCU_mICUmodelEnable		0u

/************************************************************
to open the ICU Deinit model, set it to 1u
************************************************************/
#define MCU_mICUDeInitFuncEnable		0u

/************************************************************
to open the Counter model, set it to 1u
************************************************************/
#define MCU_mCountmodelEnable		0u

/************************************************************
to open the MCU_vCounterDeInit function, set it to 1u
************************************************************/
#define MCU_mCounterDeInitFuncEnable		0u

/************************************************************
to open the Frequency-divide model, set it to 1u
************************************************************/
#define MCU_mFreDivdmodelEnable		0u

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
to open the MCU_vDMADeInit function, set it to 1u
************************************************************/
#define MCU_mDMADeInitFuncEnable		0u

/************************************************************
to open the UART model, set it to 1u
************************************************************/
#define MCU_mSerialUartmodelEnable		0u

/************************************************************
to open the MCU_vSerialUartDeint function, set it to 1u
************************************************************/
#define MCU_mUARTDeInitFuncEnable		0u

/************************************************************
to open the LIN-UART model, set it to 1u
************************************************************/
#define MCU_mLinUart_modelEnable		0u

/************************************************************
to open the MCU_vLinUart_Deint function, set it to 1u
************************************************************/
#define MCU_mLinUart_DeInitFuncEnable		0u

/************************************************************
to open the on chip I2C module, set it to 1u
************************************************************/
#define MCU_mIICmodelEnable		0u

/************************************************************
to open the MCU_vIICdeinit function, set it to 1u
************************************************************/
#define MCU_mIICdeinitEnable		0u

/************************************************************
to define the max slave divice mount in a channel
************************************************************/
#define MCU_mI2CMaxSlaveInOneMaster		1u

/************************************************************
to open the on chip CSI module, set it to 1u
************************************************************/
#define MCU_mCSImodelEnable		0u

/************************************************************
to open the MCU_vCSIdeinit function, set it to 1u
************************************************************/
#define MCU_mCSIdeinitEnable		0u

/************************************************************
to open MCUDbug module, set it to 1u

---set this value to 0u always---

************************************************************/
#define _78K0R_Debug		0u

#endif


