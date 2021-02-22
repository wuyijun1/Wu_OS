/*******************************************************************************
| Module Name: Error detect model
| File Name: DET.h
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
| 2015.07.31  V0.01	Tan, fumin	:create this module
| 2016.11.22  V0.02	Tan, fumin	:update the detect error ID for RH850
********************************************************************************/
#include "General.h"

#ifndef _DET_H_
#define _DET_H_


/*###############################################################
		Error ID for this platform
###############################################################*/

#define DET_Err_NotErr					0U
#define DET_Err_ParaOutOfRange		(DET_Err_NotErr+1U)
#define DET_Err_PinIndexOutOfRange		(DET_Err_ParaOutOfRange+1U)
#define DET_Err_PortIndexOutOfRange	(DET_Err_PinIndexOutOfRange+1U)
#define DET_Err_PortTypeOutOfRange		(DET_Err_PortIndexOutOfRange+1U)
#define DET_Err_WritePinValueFail		(DET_Err_PortTypeOutOfRange+1U)
#define DET_Err_ResourceNotMount		(DET_Err_ParaOutOfRange+1U)
#define DET_Err_CanNotReadOutPinValue	(DET_Err_ResourceNotMount+1U)
#define DET_Err_CanNotWritePinValue		(DET_Err_CanNotReadOutPinValue+1U)
#define DET_Err_CanNotWritePinDirct		(DET_Err_CanNotWritePinValue+1U)
#define DET_Err_CanNotWritePinPullUp	(DET_Err_CanNotWritePinDirct+1U)
#define DET_Err_CanNotWritePinPullDown	(DET_Err_CanNotWritePinPullUp+1U)
#define DET_Err_CanNotWritePinHDvr		(DET_Err_CanNotWritePinPullDown+1U)
#define DET_Err_CanNotWritePinOpenD		(DET_Err_CanNotWritePinHDvr+1U)

#define DET_Err_MianOscSpeedOutOfRange		(DET_Err_CanNotWritePinOpenD+1U)
#define DET_Err_ClockSetting			(DET_Err_MianOscSpeedOutOfRange+1U)
#define DET_Err_PLLSpeedOutOfRange		(DET_Err_ClockSetting+1U)
#define DET_Err_VCOOUTSpeedOutOfRange		(DET_Err_PLLSpeedOutOfRange+1U)
#define DET_Err_NrValueNotAllow		(DET_Err_VCOOUTSpeedOutOfRange+1U)
#define DET_Err_CLMAValueNotAllow		(DET_Err_NrValueNotAllow+1U)
#define DET_Err_ClockDividerNotFix			(DET_Err_CLMAValueNotAllow+1U)

#define DET_Err_TimerNotMount	(DET_Err_ClockDividerNotFix+1U)
#define DET_Err_TimerPinNotMount	(DET_Err_TimerNotMount+1U)

#define DET_Err_TimerIDOutOfRange	(DET_Err_TimerPinNotMount+1U)
#define DET_Err_TimerNotActive	(DET_Err_TimerIDOutOfRange+1U)
#define DET_Err_TimerSettingLock	(DET_Err_TimerNotActive+1U)
#define DET_Err_TimerNotInit	(DET_Err_TimerSettingLock+1U)
#define DET_Err_TimerCanNotINT	(DET_Err_TimerNotInit+1U)
#define DET_Err_TimerCanNotChg	(DET_Err_TimerCanNotINT+1U)
#define DET_Err_TimerAltFunNotActive	(DET_Err_TimerCanNotChg+1U)

#define DET_Err_OSTMIDOutOfRange	(DET_Err_TimerAltFunNotActive+1U)

#define DET_Err_RunModeCtrlOutOfRange	(DET_Err_OSTMIDOutOfRange+1U)

#define DET_Err_TimerNotRuning	(DET_Err_RunModeCtrlOutOfRange+1U)
#define DET_Err_PPGmasterMustBeEven	(DET_Err_TimerNotRuning+1U)
#define DET_Err_PPGmasterSelect	(DET_Err_PPGmasterMustBeEven+1U)
#define DET_Err_PPGCycleOutOfRange 	(DET_Err_PPGmasterSelect+1U)

#define DET_Err_PpgIdOutOfRange	(DET_Err_PPGCycleOutOfRange+1U)
#define DET_Err_PpgIdNotMount	(DET_Err_PpgIdOutOfRange+1U)
#define DET_Err_PpgNotActive	(DET_Err_PpgIdNotMount+1U)
#define DET_Err_PpgDutyOutOfRange	(DET_Err_PpgNotActive+1U)
#define DET_Err_PpgDutyChgOnlyForSlav	(DET_Err_PpgDutyOutOfRange+1U)
#define DET_Err_PpgFrequencyOutOfRange	(DET_Err_PpgDutyChgOnlyForSlav+1U)
#define DET_Err_PpgMultMasterFreqCanNotChg	(DET_Err_PpgFrequencyOutOfRange+1U)
#define DET_Err_PpgCycleChg	(DET_Err_PpgMultMasterFreqCanNotChg+1U)

#define DET_Err_PpgNotInitial	(DET_Err_PpgCycleChg+1U)
#define DET_Err_VectNumberOutOfRange	(DET_Err_PpgNotInitial+1U)
#define DET_Err_VectPriorityOutOfRange	(DET_Err_VectNumberOutOfRange+1U)
#define DET_Err_VectNotMount	(DET_Err_VectPriorityOutOfRange+1U)

#define DET_Err_EINTNotMounted	(DET_Err_VectNumberOutOfRange+1U)
#define DET_Err_EINTIDOutOfRange	(DET_Err_EINTNotMounted+1U)
#define DET_Err_EINTtrigerIDOutOfRange	(DET_Err_EINTIDOutOfRange+1U)
#define DET_Err_EINTtrigerCanNotChg		(DET_Err_EINTtrigerIDOutOfRange+1U)

#define DET_Err_DMANotMounted		(DET_Err_VectPriorityOutOfRange+1U)
#define DET_Err_DMANotInitial		(DET_Err_DMANotMounted+1U)
#define DET_Err_DMAAddrOutOfRange		(DET_Err_DMANotInitial+1U)
#define DET_Err_DMAIDOutOfRange		(DET_Err_DMANotInitial+1U)
#define DET_Err_DMATriggerIDOutOfRange		(DET_Err_DMAIDOutOfRange+1U)
#define DET_Err_DMAIsBusy		(DET_Err_DMATriggerIDOutOfRange+1U)
#define DET_Err_DMADataLenOutOfRange		(DET_Err_DMAIsBusy+1U)

#define DET_Err_ADCNotMounted		(DET_Err_DMAAddrOutOfRange+1U)
#define DET_Err_ADCConfiguration		(DET_Err_ADCNotMounted+1U)

#define DET_Err_ADCNotInit		(DET_Err_ADCConfiguration+1U)
#define DET_Err_ADCchannelOutOfRange		(DET_Err_ADCNotInit+1U)

#define DET_Err_UARTNotMounted		(DET_Err_ADCchannelOutOfRange+1U)
#define DET_Err_UARTStopBitErr		(DET_Err_UARTNotMounted+1U)
#define DET_Err_UARTParityBitErr		(DET_Err_UARTStopBitErr+1U)
#define DET_Err_UARTbaudRateSetErr		(DET_Err_UARTParityBitErr+1U)
#define DET_Err_UARTNotActive		(DET_Err_UARTbaudRateSetErr+1U)
#define DET_Err_UARTIDOutOfRange		(DET_Err_UARTNotActive+1U)
#define DET_Err_UARTNotReady		(DET_Err_UARTIDOutOfRange+1U)
#define DET_Err_UARTLenthError		(DET_Err_UARTIDOutOfRange+1U)
#define DET_Err_UARTPinReloacteErr	(DET_Err_UARTLenthError+1U)
#define DET_Err_UARTBusy			(DET_Err_UARTPinReloacteErr+1U)

#define DET_Err_ICUNotMounted		(DET_Err_UARTLenthError+1U)
#define DET_Err_ICUNotInit		(DET_Err_ICUNotMounted+1U)
#define DET_Err_ICUIDOutOfRange		(DET_Err_ICUNotInit+1U)
#define DET_Err_ICUEdgeOutOfRange		(DET_Err_ICUIDOutOfRange+1U)

#define DET_Err_CounterIDOutOfRange		(DET_Err_ICUEdgeOutOfRange+1U)
#define DET_Err_CounterCanNotChg		(DET_Err_CounterIDOutOfRange+1U)

#define DET_Err_CounterNumberOutOfRange		(DET_Err_CounterCanNotChg+1U)
#define DET_Err_FredivdIDOutOfRange		(DET_Err_ICUEdgeOutOfRange+1U)
#define DET_Err_FredivdEdgeOutOfRange		(DET_Err_FredivdIDOutOfRange+1U)
		 
#define DET_Err_LCDNotIint		(DET_Err_ICUEdgeOutOfRange +1u)
#define DET_Err_LCDSegNotMout		(DET_Err_LCDNotIint +1u)
#define DET_Err_LCDVramOutOfRange		(DET_Err_LCDSegNotMout +1u)

#define DET_Err_IICNotMounted		(DET_Err_LCDSegNotMout +1u)
#define DET_Err_IICBpsOutOfRange		(DET_Err_IICNotMounted +1u)
#define DET_Err_IICAddrLenOutOfRange		(DET_Err_IICBpsOutOfRange +1u)
#define DET_Err_IICCanNotTrigStartCondi		(DET_Err_IICAddrLenOutOfRange +1u)
#define DET_Err_IICNotReady		(DET_Err_IICCanNotTrigStartCondi +1u)
#define DET_Err_IICIsBusy		(DET_Err_IICNotReady +1u)
#define DET_Err_IICSlaveIDOutOfRange		(DET_Err_IICIsBusy +1u)
#define DET_Err_IICVectLvOutOfRange		(DET_Err_IICSlaveIDOutOfRange +1u)
#define DET_Err_IICIDOutOfRange		(DET_Err_IICVectLvOutOfRange +1u)
#define DET_Err_IICSlaveNotAck		(DET_Err_IICIDOutOfRange +1u)

#define DET_Err_NotExpIntterupt		(DET_Err_IICSlaveNotAck +1u)

#define DET_Err_RunModeOutOfRange		(DET_Err_NotExpIntterupt +1u)
#define DET_Err_SerialTypeOutOfRange	(DET_Err_RunModeOutOfRange+1u)
#define DET_Err_SerialIDOutOfRange	(DET_Err_SerialTypeOutOfRange+1u)
#define DET_Err_SerialStatusOutOfRange	(DET_Err_SerialIDOutOfRange+1u)
#define DET_Err_SerialIsBusy	(DET_Err_SerialStatusOutOfRange+1u)
#define DET_Err_SerialInUsing	(DET_Err_SerialIsBusy+1u)
#define DET_Err_SerialParaInvalib	(DET_Err_SerialInUsing+1u)
#define DET_Err_SerialLenInvalib	(DET_Err_SerialParaInvalib+1u)
#define DET_Err_BufferOverLap	(DET_Err_SerialLenInvalib+1u)
#define DET_Err_SPINotReady	(DET_Err_BufferOverLap+1u)
#define DET_Err_LinUartIDOutOfRange	(DET_Err_SPINotReady+1u)

#define DET_Err_AltFunOutOfRange	(DET_Err_LinUartIDOutOfRange+1u)


#define DET_Err_M24CXX_NULL		(DET_Err_LinUartIDOutOfRange+1u)
#define DET_Err_M24CXX_NoInit		(DET_Err_M24CXX_NULL+1u)
#define DET_Err_M24CXX_Busy		(DET_Err_M24CXX_NoInit+1u)
#define DET_Err_M24CXX_OverAddr	(DET_Err_M24CXX_Busy+1u)
#define DET_Err_M24CXX_Parity		(DET_Err_M24CXX_OverAddr+1u)
#define DET_Err_M24CXX_Len		(DET_Err_M24CXX_Parity+1u)
#define DET_Err_M24CXX_OutOfRange	(DET_Err_M24CXX_Len+1u)

#define DET_Err_M93CXX_NULL		(DET_Err_M24CXX_OutOfRange+1u)
#define DET_Err_M93CXX_NoInit		(DET_Err_M93CXX_NULL+1u)
#define DET_Err_M93CXX_Busy		(DET_Err_M93CXX_NoInit+1u)
#define DET_Err_M93CXX_OverAddr	(DET_Err_M93CXX_Busy+1u)
#define DET_Err_M93CXX_Parity		(DET_Err_M93CXX_OverAddr+1u)
#define DET_Err_M93CXX_Len		(DET_Err_M93CXX_Parity+1u)

#define DET_Err_PCA8539_NULL				(DET_Err_M93CXX_Len+1u)
#define DET_Err_PCA8539_ParaOutOfRange	(DET_Err_PCA8539_NULL+1u)
#define DET_Err_PCA8539_ChannleOutOfRange	(DET_Err_PCA8539_ParaOutOfRange+1u)
#define DET_Err_PCA8539_DrvNotReady		(DET_Err_PCA8539_ChannleOutOfRange+1u)
#define DET_Err_PCA8539_DrvFatalErr			(DET_Err_PCA8539_DrvNotReady+1u)

#define DET_Err_NCV7240_ParaOutOfRange		(DET_Err_PCA8539_DrvFatalErr+1u)
#define DET_Err_NCV7240_ChannleOutOfRange		(DET_Err_NCV7240_ParaOutOfRange+1u)
#define DET_Err_NCV7240_DrvNotReady			(DET_Err_NCV7240_ChannleOutOfRange+1u)
#define DET_Err_NCV7240_DrvFatalErr				(DET_Err_NCV7240_DrvNotReady+1u)

#define DET_Err_MemOpTypeOutOfRange				(DET_Err_NCV7240_DrvFatalErr+1u)
#define DET_Err_MemDevAddrOutOfRange				(DET_Err_MemOpTypeOutOfRange+1u)
#define DET_Err_MemDataLenOutOfRange				(DET_Err_MemDevAddrOutOfRange+1u)

/*###############################################################
		for Error monitor
###############################################################*/
#define DET_HaltWhenErrorHappen	1u

#if DET_HaltWhenErrorHappen !=0u
	uint16 DET_u16FatalErr(int16 i16ErrLineNum, uint16 u16ErrID);	

	#define DET_ErrCheck(TrueCondition,ErrType)	do{if(!(TrueCondition)){/*u16RetVal++;compiler warning*/u16RetVal=DET_u16FatalErr(__LINE__,(uint16)(ErrType));}}while(0)
	#define DET_ErrReport(ErrType)				do{/*u16RetVal++;compiler warning*/u16RetVal=DET_u16FatalErr(__LINE__,(uint16)(ErrType));}while(0)
#else
	#define DET_ErrCheck(TrueCondition,ErrType) 	do{if(!(TrueCondition)){u16RetVal++;/*compiler warning*/u16RetVal=ErrType;}}while(0)
	#define DET_ErrReport(ErrType)				 do{u16RetVal++;/*compiler warning*/u16RetVal=ErrType;}while(0)
#endif


#endif/*end of this file*/


