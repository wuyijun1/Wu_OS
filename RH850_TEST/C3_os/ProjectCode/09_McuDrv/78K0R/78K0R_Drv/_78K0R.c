/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial
| File Name: _78K0R.c
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
| 2015.11.28   V0.01	Tan, fumin	:create this module
| 2016.02.17	V0.02       Tan, fumin	:add UART control function interface
|								:add ADC_Sleep and ADC_wakeup function for low current
|								:in MCU halt/stop mode
|
| 2016.04.26	V0.03       Tan, fumin	:fix IIC isr channel ID mirror BUG
| 2016.04.27	V0.04       Tan, fumin	:remask the clock monitor in option byte and OSC_Init function
|								:to avoid un-know clock monitor reset request in CLKRF 
|
|								:add DI/EI nest control, it need to update the key-code in furture!

| 2016.05.03	V0.05       Tan, fumin	:fix IIC start/stop condtion operation in ready mode only
| 2016.05.22	V0.06       Tan, fumin	:modify option byte check for option byte value may not be correct!
|								:remove reset reason check and using the external OSC any way
| 2016.06.21  V0.07	Tan, fumin	1,add LVI enable or disable conf
|								2,add Clock monitor enable or disable conf
| 2016.07.22  V0.08	Tan, fumin	modify OSC stable time configeration setting to Index type.
| 2016.10.14  V0.09	Tan, fumin	add DI/EI instruct between the operation registers!
********************************************************************************/

#ifdef MCU_C
/*This file ONLY include in MCU.c for compiler*/


/********************************************************************
special hardware setting in this serial MCU: option byte 

==================================================================
Option BYTE_0 @ 0x00C0
==================================================================
______________________________________________________________________________
7 			6 			5 			4 		3 		2 		1 		0
WDTINIT 	WINDOW1 	WINDOW0 	WDTON 	WDCS2 	WDCS1 	WDCS0 	WDSTBYON
______________________________________________________________________________
bit 7 :WDTINIT 
	=> use wacthdog interrupt or not

	[0]: Interval interrupt is not used.
	1: Interval interrupt is generated when 75% of the overflow time is reached.
	
bit 6_5:WINDOW_xx 
	=>timer window period
	
	0: 25%
	1: 50%
	2: 75%
	[3]: 100%

bit 4:WDTON
	=>watchdog run or not after reset
	
	0: counting stopped after reset
	[1]: counting started after reset

bit 3_2_1:WDCS_xxx
	=>watchdog overflow time 
	=>this value configeration by use using the Macro [MCU_mWatchDogInterval]
	
	fIL= Internal low-speed oscillation clock frequency, typical is 30kHz
	
	0: (2^7)/fIL 	(4.27 ms)
	1: (2^8)/fIL 	(8.53 ms)
	2: (2^9)/fIL 	(17.07 ms)
	3: (2^10)/fIL 	(34.13 ms)
	4: (2^12)/fIL 	(136.5 ms)
	5: (2^14)/fIL 	(546.1 ms)
	6: (2^15)/fIL 	(1092 ms)
	7: (2^17)/fIL 	(4369 ms)

bit 0: WDSTBYON
	=>watchdog run or not in hlat/stop mode

	[0]: Counter operation stopped in HALT/STOP mode
	1: Counter operation enabled in HALT/STOP mode

############################################
so byte_0 value is 0x70|((MCU_mWatchDogInterval & 7)<<1u)

==================================================================
Option BYTE_1 @ 0x00C1
==================================================================
______________________________________________________________________________
7 		6 			5 		4 		3 			2 		1 		0
LIOUSE 	LIOSTOPB 	LIOSYSB 	CLKMB 	RESOUTB 	OPTPLL 	SEL4M 	LVIOFF
______________________________________________________________________________
bit 7:LIOUSE
	=>internal low-speed OSC enable or not

	0: Stops internal low-speed oscillation operation.
	[1]: Enables internal low-speed oscillation operation.

bit 6:LIOUSE
	=>internal low-speed OSC stop or not in STOP mode

	[0]:Stops internal low-speed oscillation in STOP mode.
	1: Operates internal low-speed oscillation in STOP mode.
	
bit 5:LIOSYSB
	=>internal low-speed OSC use for CPU clock source or not

	0: Enables internal low-speed oscillation (fIL) operation setting for system clock (fCLK).
	[1]: Disables internal low-speed oscillation (fIL) operation setting for system clock (fCLK).

bit 4:CLKMB
	=>the internal low-speed OSC monitoring CPU Clock or not
	=>if enable, it will interrupt and clock through mode is selected by default and SELPLLS (but not SELPLL) is cleared,
			    when the CPU clock(PLL) is stop,
			    it will reset when oscillation of the main system clock stops

	0: Operates clock monitoring.
	[1]: Stops clock monitoring.
	
bit 3:RESOUTB
	=>P130 function selection

	0:	Uses P130 as RESOUT pin.
		Outputs low level during RESET.
		Automatically outputs high level when RESET released.
		Port latch value does not affect output.

	[1]:	Uses P130 as normal port (dedicated to output).
		Outputs low level during RESET.
		Outputs port latch after RESET release.

bit 2:OPTPLL
	=>PLL multiplication selection
	=>this value configeratin by use for different CPU clock setting
	
	[0]:x8 multiplication
	1:x6 multiplication

bit 1:SEL4M
	=>Internal high-speed oscillator frequency division selection
	=>this setting active only use configeration for using internal high-speed OSC
	=>this value configeratin by use for different CPU clock setting
	
	0: 8 MHz operation
	1: 4 MHz operation

bit 0:LVIOFF
	=>Low power reset(LVI) enable or not

	[0]: LVI is ON by default
	1:    LVI is OFF by default
	
############################################
so byte_1 value is :

8M OSC : 0xB9
4M OSC : 0xBB
***************if External OSC fail, it will use internal OSC intand****************
==================================================================
Option BYTE_2 @ 0x00C2
==================================================================
______________________________________________________________________________
7 		6 	5 	4 		3 		2 		1 		0
PCLOFF 	1 	1 	CSEL1B 	CSEL0B 	CCS2B 	CCS1B 	CCS0B
______________________________________________________________________________
bit 7:PCLOFF
	=>PCL pin output clock enable or not

	0 :PCL default output enable
	[1]: PCL default output disable

bit 6_5:
	=>not use bit. set them to 11b always

bit 4_3_2_1_0:
	=>the clock source for PCL output, max output frequency = 12MHz 

	1 1 1 1 1 fMAIN
	1 1 1 1 0 fMAIN/2
	1 1 1 0 1 fMAIN/2^2
	1 1 1 0 0 fMAIN/2^3
	1 1 0 1 1 fMAIN/2^4
	1 1 0 1 0 fMAIN/2^11
	1 1 0 0 1 fMAIN/2^12
	1 1 0 0 0 fMAIN/2^13
	
	1 0 1 1 1 fPLL
	1 0 1 1 0 fPLL/2
	1 0 1 0 1 fPLL/2^2
	1 0 1 0 0 fPLL/2^3
	1 0 0 1 1 fPLL/2^4
	1 0 0 1 0 fPLL/2^11
	1 0 0 0 1 fPLL/2^12
	1 0 0 0 0 fPLL/2^13
	
	0 1 1 1 1 fIL (always = 30 kHz)
	
	0 0 1 1 1 fSUB

	
############################################
so byte_2 value is 0xFF

==================================================================
Option BYTE_3 @ 0x00C3
==================================================================
______________________________________________________________________________
7 			6 	5 	4 	3 	2 	1 	0
OCDENSET 	0 	0 	0 	0 	1 	0 	OCDERSD
______________________________________________________________________________
bit 7_0:OCDENSET_OCDERSD
	=>On-chip Debug Option Byte
	
	0 0: Disables on-chip debug operation.
	0 1: Setting prohibited

	1 0: Enables on-chip debugging.
		=>Erases data of flash memory in case of failures in 
		     authenticating on-chip debug security ID.
		     
	[1 1]: Enables on-chip debugging.
		=>Does not erases data of flash memory in case of 
		    failures in authenticating on-chip debug security ID.
		    
############################################
so byte_3 value is 0x85

==================================================================
Option BYTE_4-13 @ 0x00C4-0x00CD
==================================================================
byte0-byte10:
	=>on-chip debug security ID setting area
	=>default value is 0xFF x 10byte
*********************************************************************/
#define MCU_mOptByte0	((uint8)(0x70u|(uint8)((uint8)(MCU_mWatchDogInterval & 7u)<<1u)))

#if MCU_mExternOSC_Frequency==8000000ul

	#if MCU_mLVIlevelSetting != MCU_mLVIDisable
		#define MCU_mOptByte1	(uint8)(0xB8U & ((uint8)~(uint8)(MCU_mSwitchToInternalOSC * 0x10u)))
	#else
		#define MCU_mOptByte1	(uint8)(0xB9U & ((uint8)~(uint8)(MCU_mSwitchToInternalOSC * 0x10u)))
	#endif
	
#elif MCU_mExternOSC_Frequency==4000000ul

	#if MCU_mLVIlevelSetting != MCU_mLVIDisable
		#define MCU_mOptByte1	(uint8)(0xBAU & ((uint8)~(uint8)(MCU_mSwitchToInternalOSC * 0x10u)))
	#else
		#define MCU_mOptByte1	(uint8)(0xBBU & ((uint8)~(uint8)(MCU_mSwitchToInternalOSC * 0x10u)))
	#endif
	
#endif

#define MCU_mOptByte2	0xFFU
#define MCU_mOptByte3	0x85U

#define MCU_mOptByte_SECU_ID	(0xFFU)

__root  __far static const uint8 MCU_au8OptionByteSetting[0x0Eu]@0x00C0={\
		MCU_mOptByte0,MCU_mOptByte1,\
		MCU_mOptByte2,MCU_mOptByte3,\
		/*secure ID code, dafault is 0xff, 10,bytes*/\
		MCU_mOptByte_SECU_ID,MCU_mOptByte_SECU_ID,\
		MCU_mOptByte_SECU_ID,MCU_mOptByte_SECU_ID,\
		MCU_mOptByte_SECU_ID,MCU_mOptByte_SECU_ID,\
		MCU_mOptByte_SECU_ID,MCU_mOptByte_SECU_ID,\
		MCU_mOptByte_SECU_ID,MCU_mOptByte_SECU_ID};


/*only for MCU Driver module debug!!!!*/
#if (_78K0R_Debug != 0u)
	#include "../78K0R/78K0R_Drv/_78K0R_Debug.c"
#endif


#if MCU_mPortModeEnable!=0u

			/*##################################################
				refer the extern configeration data of port
			###################################################*/
			extern const MCU_tstResourceMount_Port MCU_stResourcePort;
			extern const MCU_tstPinCfg MCU_stPinUserCfg[MCU_mMaxPortInChip * MCU_mMaxPinsInPort];

			static void MCU_vPortInit(void);

#endif


#if MCU_mTimerModelEnable!=0u

			/*##################################################
				refer the extern configeration data of timer
			###################################################*/
			extern const MCU_tstReloadTimerUserCfg MCU_stTimerArrayUsrCfg[MCU_mMaxTimerIDMount];

			/* timer running status record*/
			static uint32 MCU_u32TimerRun=0ul;
			
			/* timer running data record*/
			static uint16 MCU_au16TimerData[MCU_mMaxTimerIDMount]={0u};
			
			/* timer running as master data record*/
			static uint8 MCU_au8PPGMaster[MCU_mMaxTimerIDMount]={0u};
			
			static uint16 MCU_u16TimerArrayInit(void);
			
			void MCU_vTimerIsr(uint16 u16timerID);
			
#endif

#if MCU_mPPGModeEnable!=0u

			/*##################################################
				refer the extern configeration data of PPG
			###################################################*/	

			static uint16 MCU_u16PPGinit(void);
			void MCU_vPPGDeInit(void);

#endif

#if MCU_mCountmodelEnable!=0u

			static void MCU_vCounterIsr(uint16 u16Channel);
			
#endif

#if MCU_mICUmodelEnable!=0u

		static uint16 MCU_u16ICUinit(void);
		void MCU_vICUIsr(uint8 u8ICUid);
		uint16 MCU_u16ICUDetTrigCrtl(uint16 u16Channel, uint8 u8DetEdge);

#endif

#if MCU_mFreDivdmodelEnable!=0u

		uint16 MCU_u16FreDivdChg(uint16 u16Channel, uint16 u16FreDiv);
		uint16 MCU_u16FreDivdStop(uint16 u16Channel);

#endif

#if ((MCU_mFreDivdmodelEnable!=0u)||(MCU_mTimerModelEnable!=0u)\
	||(MCU_mPPGModeEnable!=0u)||(MCU_mCountmodelEnable!=0u)\
	||(MCU_mICUmodelEnable!=0u))
	
			static uint16 MCU_u16TimerChg(uint16 u16Channel, uint16 u16Number, uint8 u8DetEdge);
#endif

#if MCU_mEINTModelEnable!=0u

			/*##################################################
				refer the extern configeration data of Extern Interrupt
			###################################################*/
			extern const MCU_tstResourceMnt_EINT MCU_stResourceEINT;
			extern const MCU_tstEINTCfg MCU_stEINTUsrCfg[MCU_mMaxEINTchannelMount];

			/*entern interrupt initial status record*/
			static uint16 MCU_au16EINTStatus_Init[1u]={0u};

			/*entern running initial status record*/
			static uint16 MCU_au16EINTStatus_Run[1u]={0u};

			#if MCU_mEINTOnOffCtrlFuncEnable!=0u
			static uint16 MCU_u16EINTrunControl(uint16 u16EintID, uint8 u8On_Off);
			#endif

			static uint16 MCU_u16EINTinit(void);

#endif

#if MCU_mADCModelEnable!=0u

			/*##################################################
				refer the extern configeration data of ADC
			###################################################*/
			extern const MCU_tstResourceMnt_ADC MCU_stResourceADC;
			extern const MCU_tstADCCfg MCU_stADCUsrCfg;

			/*ADC initial status record*/
			static uint8 MCU_u8ADCStatus=0u;

			/*ADC channel resault index, to record the convorting AD channel*/
			uint8 MCU_u8ADCUsingChannel=0u;

			/*ADC resault buffer*/
			uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount]={0u};
	
			static uint16 MCU_u16ADCinit(void);
			void MCU_vADCIsr(void);

			
#endif


#if MCU_mLinUart_modelEnable!=0u

		/*##################################################
			refer the extern configeration data of LIN-UART
		###################################################*/
		extern const MCU_tstUARTCfg MCU_stLinUartUsrCfg[MCU_mMaxLinUartchannelMount];
		
		/*UART running status record*/
		MCU_tstUARTCtrl 	MCU_stLinUartRunStatus[MCU_mMaxLinUartchannelMount];
		
		static void MCU_vLinUart_Init(void);
		void MCU_vLinUartIsr_Rx(uint16 u16channel);
		void MCU_vLinUartIsr_Tx(uint16 u16channel);
		uint16 MCU_u16LinUartSend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen);
#endif


#if MCU_mSerialUartmodelEnable!=0u

		/*##################################################
			refer the extern configeration data of Serial-UART
		###################################################*/
		extern const MCU_tstUARTCfg MCU_stUARTUsrCfg;
		
		/*UART initial status record*/
		static uint16 MCU_u16UARTStatus_Init=0u;

		/*UART running status record*/
		MCU_tstUARTCtrl 	MCU_stSerialUartRunStatus;
		
		static void MCU_vSerialUartInit(void);

		void MCU_vSerialUartIsr_Rx(uint16 u16channel);
		void MCU_vSerialUartIsr_Tx(uint16 u16channel);
		
#endif


#if MCU_mIICmodelEnable !=0u

		/*##################################################
			refer the extern configeration data of IIC
		###################################################*/
		extern const MCU_tstIICCfg MCU_stI2CUsrCfg[MCU_mMaxIICMount];
		MCU_tstIICctrl 	MCU_stIICrunStatus[2];
				
		static void MCU_vIICinit(void);
		static void MCU_vIICIsr(uint16 u16Ch);
#endif

#if MCU_mCSImodelEnable !=0u

		MCU_tstCSIctrl 	MCU_stCSIrunStatus[4];
		static void MCU_vCSIinit(void);
		static void MCU_vCSIIsr(uint16 u16Ch);

#endif


#if ((MCU_mCSImodelEnable !=0u) || (MCU_mSerialUartmodelEnable !=0u) ||(MCU_mIICmodelEnable!=0u))

		uint8 MCU_au8SerialUsingType[6];
		extern const MCU_tstResourceMnt_Serial MCU_stResourceSerial;
#endif

#if MCU_mDMAmodelEnable !=0u

		/*##################################################
			refer the extern configeration data of DMA
		###################################################*/
		extern const MCU_tstResourceMnt_DMA MCU_stResourceDMA;
		extern const MCU_tstDMACfg MCU_stDMAUsrCfg[MCU_mMaxDMAchannelMount];
		
		/*DMA initial status record*/
		static uint16 MCU_u16DMAReady=0u;
		
		static uint16 MCU_u16DMAinit(void);

		 void MCU_vDMAIsr(uint16 u16channel);

#endif


int __low_level_init(void);
static void MCU_vOscInit(void);
static void MCU_vExtOscInit(void);
#if MCU_mSwitchToInternalOSC !=0u
static void MCU_vInternalOscInit(void);
#endif
static void MCU_vClockInit(void);
static void MCU_vWatchDogInit(void);
static void MCU_vLowVoltDetectInit(void);
static void MCU_vHWConfigCheck(void);

static uint8 MCU_u8UsingOSC;
volatile uint16 MCU_u16IntNest=0;

#if MCU_mPortModeEnable!=0u

#if MCU_mPinDataOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinRead												 
 Description   : Read out hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in _78K0R.h
 			*u8PinValue : pionter of pin value output
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinRead(uint16 u16PinID,uint8 *u8PinValue)
{
	uint8 u8MaskValue;
	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstU8Reg));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstU8Reg *pDirect;
	volatile MCU_tstU8Reg *pData;

	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstU8Reg *)u16Address;
	
	u16Address=MCU_mRegisterHead_PortData;
	u16Address+=u16IndexOffset;
	pData=(volatile MCU_tstU8Reg *)u16Address;

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_mMaxPinsInPort, DET_Err_PinIndexOutOfRange);
	
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortIndex<MCU_mMaxPortInChip, DET_Err_PortIndexOutOfRange);

	/*mask value for calc*/
	u8MaskValue = (uint8)(1u<<u16PinIndex);
	
	/*check resource is mounted or not*/
	DET_ErrCheck((MCU_stResourcePort.u8PortDataMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check Pin can be read out or not*/
	DET_ErrCheck(((uint8)(pDirect->byte) & u8MaskValue) ==(uint8)(MCU_mPinMode_Input<<u16PinIndex), DET_Err_CanNotReadOutPinValue);

	/*output the reading pin value final*/
	DI();
	*u8PinValue=(((uint8)(pData->byte) & u8MaskValue) ==0u) ? 0u : 1u;
	EI();
	
	/*return the operation resault*/
	return u16RetVal;
}


/*****************************************************************************
 Function  : MCU_u16PinWrite												 
 Description   : write the hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in _78K0R.h
 			u8PinValue : value of pin value to write
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinWrite(uint16 u16PinID,uint8 u8Value)
{
	uint8 u8MaskValue;
	
	uint16 u16PinListIndex=0u;
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstU8Reg));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstU8Reg 	*pDirect;
	volatile MCU_tstU8Reg 	*pData;
	
	
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstU8Reg *)u16Address;
	
	u16Address=MCU_mRegisterHead_PortData;
	u16Address+=u16IndexOffset;
	pData=(volatile MCU_tstU8Reg *)u16Address;
	

	
	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_mMaxPinsInPort, DET_Err_PinIndexOutOfRange);
	
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortIndex<MCU_mMaxPortInChip, DET_Err_PortIndexOutOfRange);

	/*mask value for calc*/
	u8MaskValue = (uint8)(1u<<u16PinIndex);
	/*find the pin list position in array*/
	u16PinListIndex++;/*compiler warning*/
	u16PinListIndex=MCU_mListIndex(u16PortIndex,u16PinIndex);
	
	/*check resource is mounted or not*/
	DET_ErrCheck((MCU_stResourcePort.u8PortDataMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check pin value changeable or not*/
	DET_ErrCheck((MCU_stPinUserCfg[u16PinListIndex].bitPinValueChgable!=0u), DET_Err_CanNotWritePinValue);

	/*check Pin direction register is output or not*/
	if((MCU_stResourcePort.u8PortDirectMask[u16PortIndex] & u8MaskValue) !=0u)
	{
		/*check Pin can be write or not*/
		DET_ErrCheck(((uint8)(pDirect->byte) & u8MaskValue) ==(uint8)(MCU_mPinMode_Output<<u16PinIndex), DET_Err_CanNotWritePinValue);
	}

	DI();
	if(u8Value != 0u)
	{
		/*update the data to pin*/
		pData->byte |=u8MaskValue;
	}
	else
	{
		/*update the data to pin*/
		pData->byte &=(uint8)~u8MaskValue;
	}
	EI();
	
	/*return the operation resault*/
	return u16RetVal;
}

#endif

#if MCU_mPinDirectOperEnable !=0u
/*****************************************************************************
 Function  : MCU_u16PinDirectCfg												 
 Description   : write the hardware Pin direction
 
 In Parameter: 
 			u16PinID: Pin ID list in _78K0R.h
 			u8InOut : value of pin direction to write
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinDirectCfg(uint16 u16PinID,uint8 u8InOut)
{
	uint8 u8MaskValue;
	
	uint16 u16PinListIndex=0u;	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstU8Reg));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;

	volatile MCU_tstU8Reg *pDirect;
        
	u16PinListIndex++;/*compiler warning*/
        
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstU8Reg *)u16Address;

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_mMaxPinsInPort, DET_Err_PinIndexOutOfRange);
	
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortIndex<MCU_mMaxPortInChip, DET_Err_PortIndexOutOfRange);

	/*mask value for calc*/
	u8MaskValue = (uint8)(1u<<u16PinIndex);
	/*find the pin list position in array*/
	u16PinListIndex=MCU_mListIndex(u16PortIndex,u16PinIndex);

	/*check resource is mounted or not*/
	DET_ErrCheck((MCU_stResourcePort.u8PortDirectMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check pin direction value changeable or not*/
	DET_ErrCheck((MCU_stPinUserCfg[u16PinListIndex].bitPinDirectChgable!=0u), DET_Err_CanNotWritePinDirct);

	DI();
	if(u8InOut != 0u)
	{
		/*update the data to pin direction register*/
		pDirect->byte |=u8MaskValue;
	}
	else
	{
		/*update the data to pin*/
		pDirect->byte &=(uint8)~u8MaskValue;
	}
	EI();
	
	/*return the operation resault*/
	return u16RetVal;

}
#endif

#if MCU_mPinPullUpOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinPullUpCfg												 
 Description   : write the hardware Pin pull-up configeration
 
 In Parameter: 
 			u16PinID: Pin ID list in _78K0R.h
 			u8OnOff : value of pin pull-up to write
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinPullUpCfg(uint16 u16PinID,uint8 u8OnOff)
{
	uint8 u8MaskValue;
	
	uint16 u16PinListIndex=0u;
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstU8Reg));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;

	volatile MCU_tstU8Reg *pPullUp;
	
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortPullUp;
	u16Address+=u16IndexOffset;
	pPullUp=(volatile MCU_tstU8Reg *)u16Address;
	
	
	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_mMaxPinsInPort, DET_Err_PinIndexOutOfRange);
	
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortIndex<MCU_mMaxPortInChip, DET_Err_PortIndexOutOfRange);

	/*mask value for calc*/
	u8MaskValue = (uint8)(1u<<u16PinIndex);
	/*find the pin list position in array*/
        u16PinListIndex++;/*compiler warning*/
	u16PinListIndex=MCU_mListIndex(u16PortIndex,u16PinIndex);
	
	/*check resource is mounted or not*/
	DET_ErrCheck((MCU_stResourcePort.u8PortPullUpMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check pin pull up value changeable or not*/
	DET_ErrCheck((MCU_stPinUserCfg[u16PinListIndex].bitPinPullUpChgable !=0u), DET_Err_CanNotWritePinPullUp);

	DI();
	if(u8OnOff != 0u)
	{
		/*update the data to pin direction register*/
		pPullUp->byte |=u8MaskValue;
	}
	else
	{
		/*update the data to pin*/
		pPullUp->byte &=(uint8)(~u8MaskValue);
	}
	EI();
	
	return u16RetVal;
}
#endif

/*****************************************************************************
 Function  : MCU_vPortInit												 
 Description   :global port attribute configeration in reset
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static void MCU_vPortInit(void)
{

	uint8 u8Index,u8FinalData,u8TempData,u8PinIndex=0u;
	uint16 u16IndexOffset=0u;
	uint16 u16Address;
	
	/*relation register pionter*/
	volatile MCU_tstU8Reg *pPullUp;
	volatile MCU_tstU8Reg *pDirect;
	volatile MCU_tstU8Reg 	*pData;

	for(u8Index=0u;u8Index<MCU_mMaxPortInChip;u8Index++)
	{
		/*update the register addr for this loop---*/
		u16Address=MCU_mRegisterHead_PortData;
		u16Address+=u16IndexOffset;
		pData=(volatile MCU_tstU8Reg *)u16Address;
		
		u16Address=MCU_mRegisterHead_PortDirect;
		u16Address+=u16IndexOffset;
		pDirect=(volatile MCU_tstU8Reg *)u16Address;
		
		u16Address=MCU_mRegisterHead_PortPullUp;
		u16Address+=u16IndexOffset;
		pPullUp=(volatile MCU_tstU8Reg *)u16Address;
		
		/*clean the value for this loop*/
		u8FinalData=0u;
		/*find out port initial data in configuration array and update it into port data regitser*/
		u8TempData = MCU_stResourcePort.u8PortDataMask[u16IndexOffset];
		if( u8TempData !=0u)
		{
			/*fine the all pin default value in this port*/
			if(MCU_stPinUserCfg[u8PinIndex+0u].bitPindefalutValue!=0u)
				{u8FinalData |=1u;}
			if(MCU_stPinUserCfg[u8PinIndex+1u].bitPindefalutValue!=0u)
				{u8FinalData |=2u;}
			if(MCU_stPinUserCfg[u8PinIndex+2u].bitPindefalutValue!=0u)
				{u8FinalData |=4u;}
			if(MCU_stPinUserCfg[u8PinIndex+3u].bitPindefalutValue!=0u)
				{u8FinalData |=8u;}
			if(MCU_stPinUserCfg[u8PinIndex+4u].bitPindefalutValue!=0u)
				{u8FinalData |=0x10u;}
			if(MCU_stPinUserCfg[u8PinIndex+5u].bitPindefalutValue!=0u)
				{u8FinalData |=0x20u;}
			if(MCU_stPinUserCfg[u8PinIndex+6u].bitPindefalutValue!=0u)
				{u8FinalData |=0x40u;}
			if(MCU_stPinUserCfg[u8PinIndex+7u].bitPindefalutValue!=0u)
				{u8FinalData |=0x80u;}

			/*update the data to regitser---->if the pin is not mount, set it to 0 for default*/
			DI();
			pData->byte = (uint8)(u8FinalData & u8TempData);
			EI();
		}
		
		/*clean the value for this loop*/
		u8FinalData=0u;	
		/*find out port initial direction in configuration array and update it into port direction regitser*/
		u8TempData = MCU_stResourcePort.u8PortDirectMask[u16IndexOffset];
		if( u8TempData !=0u)
		{
			/*fine the all pin default value in this port*/
			if(MCU_stPinUserCfg[u8PinIndex+0u].bitPindefalutDirect!=0u)
				{u8FinalData |=1u;}
			if(MCU_stPinUserCfg[u8PinIndex+1u].bitPindefalutDirect!=0u)
				{u8FinalData |=2u;}
			if(MCU_stPinUserCfg[u8PinIndex+2u].bitPindefalutDirect!=0u)
				{u8FinalData |=4u;}
			if(MCU_stPinUserCfg[u8PinIndex+3u].bitPindefalutDirect!=0u)
				{u8FinalData |=8u;}
			if(MCU_stPinUserCfg[u8PinIndex+4u].bitPindefalutDirect!=0u)
				{u8FinalData |=0x10u;}
			if(MCU_stPinUserCfg[u8PinIndex+5u].bitPindefalutDirect!=0u)
				{u8FinalData |=0x20u;}
			if(MCU_stPinUserCfg[u8PinIndex+6u].bitPindefalutDirect!=0u)
				{u8FinalData |=0x40u;}
			if(MCU_stPinUserCfg[u8PinIndex+7u].bitPindefalutDirect!=0u)
				{u8FinalData |=0x80u;}

			/*update the data to regitser---->if the pin is not mount, set it to 0 for default*/
			DI();
			pDirect->byte = (uint8)(u8FinalData & u8TempData);	
			EI();
		}

		/*clean the value for this loop*/
		u8FinalData=0u;
		/*find out port initial data in configuration array and update it into port data regitser*/
		u8TempData = MCU_stResourcePort.u8PortPullUpMask[u16IndexOffset];
		if( u8TempData !=0u)
		{
			/*fine the all pin default value in this port*/
			if(MCU_stPinUserCfg[u8PinIndex+0u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=1u;}
			if(MCU_stPinUserCfg[u8PinIndex+1u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=2u;}
			if(MCU_stPinUserCfg[u8PinIndex+2u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=4u;}
			if(MCU_stPinUserCfg[u8PinIndex+3u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=8u;}
			if(MCU_stPinUserCfg[u8PinIndex+4u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=0x10u;}
			if(MCU_stPinUserCfg[u8PinIndex+5u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=0x20u;}
			if(MCU_stPinUserCfg[u8PinIndex+6u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=0x40u;}
			if(MCU_stPinUserCfg[u8PinIndex+7u].bitPinPullUpdefalutValue!=0u)
				{u8FinalData |=0x80u;}

			/*update the data to regitser---->if the pin is not mount, set it to 0 for default*/	
			DI();
			pPullUp->byte = (uint8)(u8FinalData & u8TempData);
			EI();
		}	

		/*index piont to next port, and there are 8-pins in a port, so +=8*/
		u8PinIndex+=MCU_mMaxPinsInPort;
		/*index point to next port*/
		u16IndexOffset++;
		
	}

}
#endif

#if ((MCU_mFreDivdmodelEnable!=0u)||(MCU_mPPGModeEnable!=0u)||\
	(MCU_mCountmodelEnable!=0u)||(MCU_mICUmodelEnable!=0u))
	
	#if (MCU_mTimerModelEnable!=0u)
	#else
		#error "Timer Modue define MCU_mTimerModelEnable MUST open!"
	#endif
#endif

#if MCU_mTimerModelEnable!=0u
/*****************************************************************************
 Function  : MCU_u16TimerArrayInit												 
 Description   :global timer attribute configeration in reset, it including :
 			1,re-load timer
 			2,ICU(high/low level detect and period detect)
 			3,counter
 			4,PWM(master and slave type)
 			5,frequency divider
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16TimerArrayInit(void)
{
	uint16 u16Loop,u16TimerType,u16MasterCyc=0u,u16InterVal;
	uint16 u16TMR=0u,	u16TDR=0u,u16ClkSupply=0u;
	uint16 u16GroupHead=MCU_mTimerArrayRegHead-sizeof(MCU_tstTimerArray),
		u6TDRhead=MCU_mTimerTDRRegHead-2u,u16EIneed=0u;
	uint16 u16RetVal=DET_Err_NotErr,u16MasterID=0u;
	
	uint32 u32TS=0ul,u32TOE=0ul,u32TOS=0ul,u32TOM=0ul,u32TIS=0ul,
		u32MaskBit=0ul,u32UsingTimer=0ul;
	
	volatile MCU_tstTimerArray *pTimerReg;
	volatile uint16 *pTDR;
	
	for(u16Loop = 0u; u16Loop < MCU_mMaxTimerIDMount; u16Loop++)
	{
		/*piont next group or ID*/
		if((uint16)(u16Loop & 0x07u)==0u)
		{
			u16MasterCyc=0u;
			u16GroupHead+=sizeof(MCU_tstTimerArray);
		}
		u6TDRhead+=2u;
		/*address shitf*/
		if(u6TDRhead == 0xFF80u)
		{
			u6TDRhead=0xFF90u;
		}
		
		u32MaskBit =(uint32)(1ul<<u16Loop);
		
		u16TimerType=MCU_stTimerArrayUsrCfg[u16Loop].u16TimerType;
		u16InterVal=MCU_stTimerArrayUsrCfg[u16Loop].u16Interval_us;
		
		if(u16TimerType == PPG_Mst)
		{
			DET_ErrCheck(((uint16)(u16Loop & 1u)) ==0u, DET_Err_PPGmasterMustBeOdd);
			DET_ErrCheck(((u16InterVal>20u)&&(u16InterVal <4000u)), DET_Err_PPGCycleOutOfRange);/*HZ too big, error to big*/
			
			/*record timer data*/
			MCU_au16TimerData[u16Loop]=u16InterVal;
			
			u16TMR=u16TimerType;
			u16InterVal=(uint16)(1000000ul/u16InterVal);
			u16TDR=u16InterVal;
			u16MasterCyc=u16InterVal;
			u32TS |=u32MaskBit;
			u32UsingTimer|=u32MaskBit;
			u16MasterID=u16Loop;		
		}
		else if(u16TimerType == PPG_Slv)
		{
			DET_ErrCheck((u16MasterCyc !=0u), DET_Err_PPGCycleOutOfRange);
			DET_ErrCheck((u16InterVal <=1000u), DET_Err_PpgDutyOutOfRange);
			
			/*record timer data*/
			MCU_au16TimerData[u16Loop]=u16InterVal;
			
			if(u16InterVal !=0u)
			{
				if(u16InterVal >= 1000u)
				{
					u16InterVal=0xFFFEu;
				}
				else
				{
					u16InterVal=(uint16)(((uint32)u16InterVal * u16MasterCyc) /(uint16)1000u ); /*duty percent to counter*/
				}
			}
			
			u16TDR=u16InterVal ; 
			u16TMR=u16TimerType;
			u32TS |=u32MaskBit;
			u32TOE |=u32MaskBit;
			u32TOM |=u32MaskBit;
			
			u32UsingTimer|=u32MaskBit;
			
			MCU_au8PPGMaster[u16Loop]=(uint8)u16MasterID;
			
			if(MCU_stTimerArrayUsrCfg[u16Loop].u8IOpinID ==ReLoacte_Pin)
			{
				u32TOS |=u32MaskBit;
			}

			
		}
		else
		{
			/*record timer data*/
			MCU_au16TimerData[u16Loop]=u16InterVal;
				
			if(u16TimerType == Re_LoadTimer)
			{
				u16TMR=u16TimerType;
				u16TDR=u16InterVal;
				u16EIneed=1u;
				u32UsingTimer|=u32MaskBit;
				
				/*if run in reset, then start the timer*/				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8RunInRst !=0u)
				{
					u32TS |=u32MaskBit;
				}
			}
			else if((u16TimerType == ICUtype_period) || (u16TimerType == ICUtype_level))
			{
				if(u16TimerType == ICUtype_period)
				{
					DET_ErrCheck(u16InterVal<3u, DET_Err_ICUEdgeOutOfRange);
				}
				else if(u16TimerType == ICUtype_level)
				{
					DET_ErrCheck(((u16InterVal==2u) ||(u16InterVal==3u)) , DET_Err_ICUEdgeOutOfRange);
				}
				else
				{
					
				}

				u16InterVal<<=6u;/*set edge type*/
				u16TMR=u16TimerType | u16InterVal;
				u16TDR=0u;
				u16EIneed=1u;
				u32UsingTimer|=u32MaskBit;
				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8IOpinID ==ReLoacte_Pin)
				{
					u32TIS |=u32MaskBit;
				}	
				/*if run in reset, then start the timer*/				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8RunInRst !=0u)
				{
					u32TS |=u32MaskBit;
				}				
			}
			else if(u16TimerType == Countertype)
			{
				u16TDR=u16InterVal;
				
				u16InterVal=(uint16)((uint16)MCU_stTimerArrayUsrCfg[u16Loop].u8IntervalChangeable & 0x06U);
				DET_ErrCheck(((uint16)(u16InterVal>>1))<3u, DET_Err_ICUEdgeOutOfRange);
				
				u16InterVal<<=5u;
				u16TMR=(uint16)(u16TimerType | u16InterVal);
				u16EIneed=1u;
				u32UsingTimer|=u32MaskBit;
				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8IOpinID ==ReLoacte_Pin)
				{
					u32TIS |=u32MaskBit;
				}				
				/*if run in reset, then start the timer*/				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8RunInRst !=0u)
				{
					u32TS |=u32MaskBit;
				}
			}
			else if(u16TimerType == Fredivtype)
			{
				u16TDR=u16InterVal;
				
				u16InterVal=(uint16)((uint16)MCU_stTimerArrayUsrCfg[u16Loop].u8IntervalChangeable & 0x06U);
				DET_ErrCheck(((uint16)(u16InterVal>>1))<3u, DET_Err_ICUEdgeOutOfRange);
				
				u16InterVal<<=5u;
				u16TMR=u16TimerType | u16InterVal;
				u32UsingTimer|=u32MaskBit;
				/*u16EIneed=1u test only, frequency divider can not interrupt to reduce CPU load*/
				u32TOE |=u32MaskBit;
				
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8IOpinID ==ReLoacte_Pin)
				{
					u32TIS |=u32MaskBit;	/*one pin input, other pin output*/
				}
				else
				{
					u32TOS |=u32MaskBit;
				}
				/*if run in reset, then start the timer*/
				if(MCU_stTimerArrayUsrCfg[u16Loop].u8RunInRst !=0u)
				{
					u32TS |=u32MaskBit;
				}
			}
			else
			{
				u16TMR=0u;
				u16TDR=0u;
				u16InterVal=0u;
			}
		}		
		
		/*check the resource for MCU type*/
		DET_ErrCheck((uint32)((uint32)(~MCU_stResourceTimerArray.u32TimerMountList) & u32UsingTimer) ==0ul, DET_Err_TimerNotMount);

		/*clock supply to the module*/
		if((((uint32)(0x000000FFUL & u32UsingTimer))!=0ul) && (((uint16)(u16ClkSupply & 1u))==0u))
		{
			u16ClkSupply |=1u;
			TAU0EN=1u;
			TPS0=0x0004u;/*devide to 1M clock for timer group*/
		}
		if((((uint32)(0x0000FF00UL & u32UsingTimer)) !=0ul)&& (((uint16)(u16ClkSupply & 2u))==0u))
		{
			u16ClkSupply |=2u;
			TAU1EN=1u;
			TPS1=0x0004u;
		}
		if((((uint32)(0x00FF0000UL & u32UsingTimer)) !=0ul)&& (((uint16)(u16ClkSupply & 4u))==0u))
		{
			u16ClkSupply |=4u;
			TAU2EN=1u;
			TPS2=0x0004u;
		}

		/*piont to register address*/
		pTimerReg=(volatile MCU_tstTimerArray *)u16GroupHead;
		pTDR=(volatile uint16 *)u6TDRhead;
		/*update value to register*/
		pTimerReg->u16TMR[(uint16)(u16Loop&7u)]=u16TMR;
		if(u16Loop ==0u)
		{
			TDR00=u16TDR;
		}
		else if(u16Loop ==1u)
		{
			TDR01=u16TDR;
		}
		else
		{
			DI();
			*pTDR=u16TDR;
			EI();
		}
		
		/*enable to timer interrupt*/
		if(u16EIneed !=0u)
		{
			u16EIneed = MCU_stResourceTimerArray.u16VectorNumber[u16Loop];
			DET_ErrCheck(u16EIneed !=0xFFu, DET_Err_TimerCanNotINT);
			MCU_u16InterruptCtrl(u16EIneed, 1u);
		}
		
		u16EIneed=0u;
		
	}


	/*check I/O pin reloacte*/
	DET_ErrCheck((uint32)((uint32)(~MCU_stResourceTimerArray.u32TimerRelocatePinList) & ((uint32)(u32TOS | u32TIS)))==0ul, DET_Err_TimerPinNotMount);

	/*output pin select control*/
	TOS0=(uint8)(u32TOS&0x000000FFul);
	u32TOS>>=8u;
	TOS1=(uint8)(u32TOS&0x000000FFul);
	
	/*input pin select control*/
	TIS0=(uint8)(u32TIS&0x000000FFul);
	u32TIS>>=8u;
	TIS1=(uint8)(u32TIS&0x000000FFul);

	/*record running timer*/
	MCU_u32TimerRun=u32TS;

	/*update the value to the register!!*/
	u16GroupHead=MCU_mTimerArrayRegHead;

	DI();
	for(u16Loop=0u; u16Loop<3u; u16Loop++)
	{
		pTimerReg=(volatile MCU_tstTimerArray *)u16GroupHead;
		
		pTimerReg->u16TOM=(uint16)(u32TOM&0x000000FFul);	/*output logic */
		pTimerReg->u16TOE=(uint16)(u32TOE&0x000000FFul);	/*output enable */
		pTimerReg->u16TS=(uint16)(u32TS&0x000000FFul);		/*timer start*/
														/*TO,TOL using dafault value*/
		u16GroupHead+=sizeof(MCU_tstTimerArray);
		u32TOM>>=8u;
		u32TOE>>=8u;
		u32TS>>=8u;
	}
	EI();
	
	/*aglin the master list for PPG setting*/
	for(u16Loop=0u;u16Loop<MCU_mMaxTimerIDMount;u16Loop++)
	{
		u16MasterID=MCU_au8PPGMaster[u16Loop];
		if(u16MasterID !=0u)
		{
			MCU_au8PPGMaster[u16MasterID]++;
		}
	}
	
	return u16RetVal;
}



/*****************************************************************************
 Function  : MCU_u16ReloadTimerStartDefConf												 
 Description   : triger the timer to run within the default user setting
 
 In Parameter: 
 			u16TimerID: Timer ID list in _78K0R.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			this function should call after MCU_u16TimerArrayInit run
*****************************************************************************/
uint16 MCU_u16ReloadTimerStartDefConf(uint16 u16TimerID)
{

	/*use for store the timer uint head address*/
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*relation register*/
	volatile MCU_tstTimerArray *pTimerReg;

	/*Check the timer ID is in range*/
	DET_ErrCheck(u16TimerID<MCU_mMaxTimerIDMount, DET_Err_TimerIDOutOfRange);
	
	/*Check the timer is mount or not)*/
	DET_ErrCheck(((MCU_stResourceTimerArray.u32TimerMountList) &( (uint32)(1ul<<u16TimerID)))!=0u, DET_Err_ResourceNotMount);

	/*Check the timer is active or not*/
	DET_ErrCheck(MCU_stTimerArrayUsrCfg[u16TimerID].u16Interval_us!=0u, DET_Err_TimerNotActive);

	/*Check the timer is initial or not
	DET_ErrCheck((MCU_u32TimerInit & (uint32)(1ul<<u16TimerID))!=0u, DET_Err_TimerNotActive)*/
	/*update the register address*/
	pTimerReg=(volatile MCU_tstTimerArray *)MCU_mTimerArrayRegHead;
	pTimerReg+=(u16TimerID>>3u);
	
	DI();
	pTimerReg->u16TS |= (uint16)(1UL<<((uint16)(u16TimerID&7u)));
	EI();
	
	/*record timer is runing*/
	MCU_u32TimerRun |=(uint32)(1ul<<u16TimerID);

	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16ReloadTimerStop												 
 Description   : set the timer to stop running
 
 In Parameter: 
 			u16TimerID: timer ID list in _78K0R.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ReloadTimerStop(uint16 u16TimerID)
{
	return MCU_u16TimerChg(u16TimerID,0xFFFFu,0xFFu);
}
	
#if MCU_mTimerIntervalChgEnable!=0u
/*****************************************************************************
 Function  : MCU_u16ReloadTimerChgInterval												 
 Description   : set the timer interval and start running
 
 In Parameter: 
 			u16TimerID: timer ID list in _78K0R.h
 			u16Interval_us: new interval(us)
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ReloadTimerChgInterval(uint16 u16TimerID,uint16 u16Interval_us)
{
	return MCU_u16TimerChg(u16TimerID,u16Interval_us,0u);
}

#endif


/*****************************************************************************
 Function  : MCU_u16TimerChg												 
 Description   :global timer attribute configeration in reset, it including :
 			1,re-load timer
 			2,ICU(high/low level detect and period detect)
 			3,counter
 			4,PWM(master and slave type)
 			5,frequency divider
 In Parameter: 
 			u16Channel : timer channel
 			u16Number: timer new counter for TDRxx
 			u8DetEdge : for detect edge ID, 0xff is mask for timer channel stop
 			
Return Value:
 			u16RetVal
 			
 NOTE: 
 			NULL
*****************************************************************************/
static uint16 MCU_u16TimerChg(uint16 u16Channel, uint16 u16Number, uint8 u8DetEdge)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16TMRvalue;
	uint16 u16TimeSubID=(uint16)(u16Channel & 7u);
	uint16 u16Addr;
	
	/*relation register*/
	volatile uint16 *pTDR;
	volatile MCU_tstTimerArray *pTimerReg;

	/*Check the timer ID range*/
	DET_ErrCheck(u16Channel<MCU_mMaxTimerIDMount, DET_Err_ICUIDOutOfRange);
	/*Check the timer is mount or not*/
	DET_ErrCheck((MCU_stResourceTimerArray.u32TimerMountList & (uint32)(1ul<<u16Channel) )!=0u, DET_Err_ResourceNotMount);
	/*Check the timer is initial or not
	DET_ErrCheck((MCU_u32TimerInit & (uint32)(1ul<<u16Channel))!=0u, DET_Err_TimerNotActive)*/

	/*update the register address*/
	u16Addr =(uint16)(((uint16)(u16Channel & 0x0018u))<<3);
	u16Addr +=MCU_mTimerArrayRegHead;
	
	DI();
	pTimerReg=(volatile MCU_tstTimerArray *)u16Addr;
	
	/*stop timer for re-write register*/
	pTimerReg->u16TT |= (uint16)(1ul<<u16TimeSubID);

	/*stopped timer above*/
	if(u8DetEdge ==0xffu)
	{
		MCU_u32TimerRun &=(uint32)(~(uint32)(1ul<<u16TimeSubID));
	}
	/*not stop commond, then update the dectect edge*/
	else 
	{
		DET_ErrCheck(u8DetEdge<4u, DET_Err_ICUEdgeOutOfRange);
		DET_ErrCheck(u16Number !=0u, DET_Err_CounterNumberOutOfRange);
		DET_ErrCheck(((MCU_stTimerArrayUsrCfg[u16Channel].u8IntervalChangeable & 0x01u)!= 0u), DET_Err_TimerCanNotChg);
		
		u16Number -= 1u;/*change to actual count*/

		/*update the trigger edge*/
		u16TMRvalue=pTimerReg->u16TMR[u16TimeSubID];
		u16TMRvalue &=(uint16)(~0x00c0u);
		u16TMRvalue |=(uint16)((uint16)u8DetEdge<<6u);
		pTimerReg->u16TMR[u16TimeSubID]=u16TMRvalue;

		/*update number-->
		if using as ICU_prorio or Level, it OK to write TDR, TDRwill update by TCR if edge detect*/
		if(u16Channel == MCU_mTimerArray_00)
		{
			TDR00=u16Number;
		}
		else if(u16Channel == MCU_mTimerArray_01)
		{
			TDR01=u16Number;
		}
		else
		{
			u16Addr=(uint16)(u16Channel<<1u);
			u16Addr+=MCU_mTimerTDRRegHead;
			if(u16Channel>=MCU_mTimerArray_20)
			{
				u16Addr+=0x10u;
			}
			pTDR=(volatile uint16 *)u16Addr;
			*pTDR=u16Number;
		}		
		
		/*start timer again*/
		pTimerReg->u16TS |= (uint16)(1UL<<u16TimeSubID);
		MCU_u32TimerRun |=(uint32)(1ul<<u16Channel);
		
	}
	EI();
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vTimerIsr												 
 Description   :timer-array interrupt service
 
 In Parameter: 
 			u16timerID: timer ID list in _78K0R.h
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute ONLY in interrupt
*****************************************************************************/
void MCU_vTimerIsr(uint16 u16timerID)
{
	uint16 u16TimerType,u16Resault;
	uint16 u16RetVal=DET_Err_NotErr,u16Addr;
	uint32 u32Resault;
	volatile uint16 *pTDR;
	volatile MCU_tstTimerArray *pTimerReg;

	DET_ErrCheck(u16timerID<MCU_mMaxTimerIDMount, DET_Err_TimerIDOutOfRange);
	/*check the resource for MCU type*/
	DET_ErrCheck((uint32)(~MCU_stResourceTimerArray.u32TimerMountList & u16timerID) ==0ul, DET_Err_TimerNotMount);

	u16TimerType=MCU_stTimerArrayUsrCfg[u16timerID].u16TimerType;
	if((u16TimerType == Re_LoadTimer)/*timer type*/ ||\
		(u16TimerType == Countertype)/*counter type*/)
	{
		MCU_stTimerArrayUsrCfg[u16timerID].vpINTservice();
	}
	else if((u16TimerType == ICUtype_period)/*measurement the input frequency type*/||
		(u16TimerType == ICUtype_level)/*measurement the input High/Low level type*/)
	{
		DI();
		if(u16timerID == 0u)
		{
			u16Resault=TDR00;
		}
		else if(u16timerID == 1u)
		{
			u16Resault=TDR01;
		}
		else
		{
			u16Addr=u16timerID<<1u;
			u16Addr+=MCU_mTimerTDRRegHead;
			pTDR=(volatile uint16 *)u16Addr;
			u16Resault=*pTDR;
		}

		u16Addr=MCU_mTimerArrayRegHead;
		u16Addr +=(uint16)((uint16)(u16timerID&0x0018u))<<3u;/*sizeof(MCU_tstTimerArray)*(u16timerID>>3u), one uint is 64byte*/
		pTimerReg=(volatile  MCU_tstTimerArray *)u16Addr;
		EI();
		
		u32Resault=u16Resault;
		
		/*check OverFlow Bit*/
		/*if((uint16)((pTimerReg->u16TSR[(uint16)(u16timerID&7u)]) & (uint16)(1u<<((uint16)(u16timerID&3u)))) !=0u)*/
		if((pTimerReg->u16TSR[(uint16)(u16timerID&7u)]) !=0U)
		{
			u32Resault|=0x10000ul;
		}
		
		MCU_stTimerArrayUsrCfg[u16timerID].vpINTservice(u32Resault);
		
	}
	/***************************************************************
	else if(u16TimerType == Fredivtype)----->Frequency  divider can not interrupt to reduce CPU load
	{
		MCU_stTimerArrayUsrCfg[u16timerID].vpINTservice()
	}
	******************************************************************/
	else
	{
	
		DET_ErrReport(DET_Err_TimerIDOutOfRange);
	}
	
	u16RetVal+=1u;/*compiler warning*/
}

#if MCU_mTimerDeintiEnable!=0u
/*****************************************************************************
 Function  : MCU_vTimerArrayDeinit												 
 Description   : external interrupt model clear
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vTimerArrayDeinit(void)
{
	uint8 u8Loop;
	
	PER0 &=(uint8)~7u;	/*stop the timer array clock*/

	/*interrupt disable*/
	for(u8Loop=0u;u8Loop < MCU_mMaxTimerIDMount;u8Loop++)
	{
		MCU_u16InterruptCtrl(MCU_stResourceTimerArray.u16VectorNumber[u8Loop], 0u);	
	}
}

#endif

#endif/*end of timer moduel*/

#if MCU_mFreDivdmodelEnable!=0u
/*****************************************************************************
 Function  : MCU_u16FreDivdChg												 
 Description   :configerate the frequency attribute for a channel
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			u16FreDiv:new divider condition
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16FreDivdChg(uint16 u16Channel, uint16 u16FreDiv)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	  DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==Fredivtype) , DET_Err_ICUIDOutOfRange);
	 u16RetVal=MCU_u16TimerChg(u16Channel,u16FreDiv,BothEdg);
	 
        return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16FreDivdStop												 
 Description   :timer channel detect disable 
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16FreDivdStop(uint16 u16Channel)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==Fredivtype) , DET_Err_ICUIDOutOfRange);
	u16RetVal=MCU_u16TimerChg(u16Channel,0xFFFFU,0xFFU);
	
	return u16RetVal;
}

#endif/*end of frequency module*/

#if MCU_mPPGModeEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PPGSetHz												 
 Description   : set the PPG attribute and start PPG output
 
 In Parameter: 
 			u16PPG_ID: PPG ID list in _78K0R.h
 			u16Hz: new output frequency
 			u16Duty:new output percentage, range: 0-->1000(100%)
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16PPGSetHz(uint16 u16PPG_ID, uint16 u16Hz,uint16 u16Duty)
{
	uint16 u16FrChg=0u;
	uint16 u16MasterTDR,u16SlaveTDR;
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16MasterID,u16Addr=MCU_mTimerTDRRegHead;
	
	/*PPG relation register*/
	volatile uint16 *pTDR=(volatile uint16 *)MCU_mTimerTDRRegHead;
		
	/*check PPG ID is in range or not*/
	DET_ErrCheck(u16PPG_ID<MCU_mMaxTimerIDMount, DET_Err_PpgIdOutOfRange);
	/*check duty is in range or not*/
	DET_ErrCheck(u16Duty<=1000u, DET_Err_PpgDutyOutOfRange);
	
	/*check the resource for MCU type*/
	DET_ErrCheck((uint32)((uint32)(~MCU_stResourceTimerArray.u32TimerMountList) & (1ul<<u16PPG_ID)) ==0ul, DET_Err_PpgIdNotMount);
	
	/*check the slave channel*/
	DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16PPG_ID].u16TimerType == PPG_Slv), DET_Err_PpgDutyChgOnlyForSlav);

	/*check cycle, it can not change if the PPG has multiple channel*/
	u16MasterID=MCU_au8PPGMaster[u16PPG_ID];

	/*Master TDR address*/
	u16Addr+=(uint16)(u16MasterID<<1u);
	if(u16MasterID>=MCU_mTimerArray_20)/*TDR2x address*/
	{
		u16Addr+=0x10u;
	}
	pTDR=(volatile uint16 *)u16Addr;
	
	/*ONLY update if the data is different*/
	if((MCU_au16TimerData[u16MasterID] !=u16Hz) || (MCU_au16TimerData[u16PPG_ID] !=u16Duty))
	{
		if(MCU_au16TimerData[u16MasterID] !=u16Hz)
		{
			DET_ErrCheck(MCU_au8PPGMaster[u16MasterID] ==1u, DET_Err_PpgMultMasterFreqCanNotChg);
			DET_ErrCheck((u16Hz>20u) &&( u16Hz <5000u), DET_Err_PpgMultMasterFreqCanNotChg);
			MCU_au16TimerData[u16MasterID]=u16Hz;
			u16MasterTDR=(uint16)(1000000ul/u16Hz);
			
			u16MasterTDR--;
			
			u16FrChg=1u;
		}
		else
		{
			if(u16MasterID==MCU_mTimerArray_00)
			{
				u16MasterTDR=TDR00;
			}
			else
			{
				u16MasterTDR=*pTDR;
			}
		}

		if((MCU_au16TimerData[u16PPG_ID] !=u16Duty) || (u16FrChg !=0u))
		{
			MCU_au16TimerData[u16PPG_ID] =u16Duty;
			if(u16Duty == 0u)
			{
				u16SlaveTDR=0u;
			}
			else if(u16Duty >=1000u)
			{
				u16SlaveTDR=0xFFFE;
			}
			else
			{
				u16SlaveTDR=(uint16)(((uint32)u16MasterTDR * u16Duty) / (uint16)1000u);
			}
		}

		DI();
		/*master TDR*/
		if(u16MasterID==MCU_mTimerArray_00)
		{
			TDR00 =u16MasterTDR ;
		}
		else
		{
			*pTDR=u16MasterTDR;
		}

		/*slave TDR*/
		if(u16PPG_ID==MCU_mTimerArray_01)
		{
			TDR01 =u16SlaveTDR ;
		}
		else
		{
			u16Addr=MCU_mTimerTDRRegHead;
			u16Addr+=(uint16)(u16PPG_ID<<1u);
			if(u16PPG_ID>=MCU_mTimerArray_20)
			{
				u16Addr+=0x10u;
			}
			pTDR=(volatile uint16 *)u16Addr;/*piont to slave TDR*/
			*pTDR=u16SlaveTDR;
		}
		EI();
		
	}
	
	return u16RetVal;
		
}

/*****************************************************************************
 Function  : MCU_u16PPGinit												 
 Description   : PPG model initial in reset, 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			it execute before system-mainloop
 			
 			in this serial MCU, PPG module is meger in Timer-array, 
 			so PPG init has done in timer group
*****************************************************************************/
static uint16 MCU_u16PPGinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	return u16RetVal;
}

#endif /*end of PPG module */

#if MCU_mICUmodelEnable!=0u

/*****************************************************************************
 Function  : MCU_u16ICUDetTrigCrtl												 
 Description   :configerate the ICU triger interrupt condition
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			u8DetEdge:new interrupt triger condition
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUDetTrigCrtl(uint16 u16Channel, uint8 u8DetEdge)
{
	uint16 u16RetVal=MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType;
	
  	DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_period) ||\
  					(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_level), DET_Err_ICUIDOutOfRange);
	
	if( u16RetVal== ICUtype_period)
	{
		DET_ErrCheck(u8DetEdge<3u, DET_Err_EINTtrigerIDOutOfRange);
	}
	else 	if(u16RetVal== ICUtype_level)
	{
		DET_ErrCheck(((u8DetEdge==2u) || (u8DetEdge==3u)), DET_Err_EINTtrigerIDOutOfRange);
	}
	else
	{
		DET_ErrReport(DET_Err_ICUIDOutOfRange);
	}
	
	return MCU_u16TimerChg(u16Channel, 0xFFFFu, u8DetEdge);
}

/*****************************************************************************
 Function  : MCU_u16ICUstop												 
 Description   :ICU channel detect disable 
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUstop(uint16 u16Channel)
{
	uint16 u16RetVal=MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType;
	
  	DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_period) ||\
  					(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_level), DET_Err_ICUIDOutOfRange);
         u16RetVal=MCU_u16TimerChg(u16Channel, 0xFFFFu, 0xFFu);
         
        return u16RetVal;

}


/*****************************************************************************
 Function  : MCU_u16ICUstart												 
 Description   :ICU channel detect disable 
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			u8DetEdge: new detect edge
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUstart(uint16 u16Channel,uint8 u8DetEdge)
{
	uint16 u16RetVal=MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType;
	
  	DET_ErrCheck((MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_period) ||\
  					(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==ICUtype_level), DET_Err_ICUIDOutOfRange);
	u16RetVal=MCU_u16TimerChg(u16Channel,0xFFFFu,u8DetEdge);
	 
        return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_vICUIsr												 
 Description   :ICU interrupt service
 
 In Parameter: 
 			u8ICUid: timer ID list in _78K0R.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt

 			in this serial MCU, ICU module is meger in Timer-array, 
 			so ICU ISR has done in timer group
*****************************************************************************/
void MCU_vICUIsr(uint8 u8ICUid)
{
	/*it has done in timer group*/
}


/*****************************************************************************
 Function  : MCU_u16ICUinit												 
 Description   :initial ICU model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function execute before system-mailoop

 			in this serial MCU, ICU module is meger in Timer-array, 
 			so ICU init has done in timer group
*****************************************************************************/
static uint16 MCU_u16ICUinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	return u16RetVal;
}

#endif /*end of ICU module*/


#if MCU_mCountmodelEnable!=0u
/*****************************************************************************
 Function  : MCU_u16CounterChg												 
 Description   :configerate the counter triger interrupt condition or counter number
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			u16Number: how many edge detect to interrupt
 			u8DetEdge:new triger condition
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16CounterChg(uint16 u16Channel,uint16 u16Number,uint8 u8Edge)
{
	uint16 u16RetVal=DET_Err_NotErr;

  	DET_ErrCheck(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==Countertype , DET_Err_CounterIDOutOfRange);
	DET_ErrCheck(u8Edge<3u, DET_Err_EINTtrigerIDOutOfRange);
	
	u16RetVal=MCU_u16TimerChg(u16Channel,u16Number,u8Edge);
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16CounterStop												 
 Description   :counter channel detect disable 
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16CounterStop(uint16 u16Channel)
{
	uint16 u16RetVal=DET_Err_NotErr;

  	DET_ErrCheck(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==Countertype , DET_Err_CounterIDOutOfRange);
	u16RetVal=MCU_u16TimerChg(u16Channel,0xFFFFu,0xFFu);
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16CounterStart												 
 Description   :counter channel detect update setting and enable 
 
 In Parameter: 
 			u16Channel:timer ID list in _78K0R.h
 			u16Number: new counter number
 			u8Edge: new counter valib edge
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16CounterStart(uint16 u16Channel,uint16 u16Number,uint8 u8Edge)
{
	uint16 u16RetVal=DET_Err_NotErr;

  	DET_ErrCheck(MCU_stTimerArrayUsrCfg[u16Channel].u16TimerType ==Countertype , DET_Err_CounterIDOutOfRange);
	DET_ErrCheck(u8Edge<3u, DET_Err_EINTtrigerIDOutOfRange);
	
	u16RetVal=MCU_u16TimerChg(u16Channel,u16Number,u8Edge);
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_vCounterIsr												 
 Description   :Counter interrupt service
 
 In Parameter: 
 			u16Channel: timer ID list in _78K0R.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt

 			in this serial MCU, ICU module is meger in Timer-array, 
 			so ICU ISR has done in timer group
*****************************************************************************/
static void MCU_vCounterIsr(uint16 u16Channel)
{
	/*it has done in timer group*/
}

#endif/*end of Counter module*/


/*****************************************************************************
 Function  : MCU_u16InterruptCtrl												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptCtrl(uint16 u16VectNum,uint8 u8IntEnable)
{

	volatile uint16 *MKBits;
	uint16 u16MaskValue;
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8BitPos=(uint8)((u16VectNum-4u)>>1u);
	
	DET_ErrCheck(((u16VectNum>=MCU_mMinVectNum)&&(u16VectNum<=MCU_mMAxVectNum)), DET_Err_VectNumberOutOfRange);
	DET_ErrCheck((MCU_au8VectorMask[(uint8)((uint8)((u16VectNum)-4u)>>4u)] & (1u<<(uint8)((uint8)((uint8)((u16VectNum)-4u)>>1) &7u)))!=0u , DET_Err_VectNotMount);
	
	MKBits = (volatile uint16 *)(0xffe4u-(uint16)((uint16)((uint16)u8BitPos & 0x20u)>>1u) + (uint16)((uint16)((uint16)(((uint16)((uint16)u8BitPos & 0x10u))>>3u)))) ;
	u16MaskValue = (uint16)(1ul<<((uint16)((uint16)u8BitPos&0xfu)));

	DI();
	if(u8IntEnable !=0u)
	{
		/*interrupt enable, so clean the MK bit*/
		*MKBits &=(uint16)~u16MaskValue;
	}
	else
	{
		/*interrupt disable, so set the MK bit*/
		*MKBits |=u16MaskValue;
	}
	EI();
	
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_u16InterruptFlagClean												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number IF to clean
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			IF is clean by hardware auto if progma run into vector_table
*****************************************************************************/
uint16 MCU_u16InterruptFlagClean(uint16 u16VectNum)
{
	volatile uint16 *IFBits;
	uint16 u16MaskValue;
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8BitPos=(uint8)((u16VectNum-4u)>>1u);
	
	DET_ErrCheck(((u16VectNum>=MCU_mMinVectNum)&&(u16VectNum<=MCU_mMAxVectNum)), DET_Err_VectNumberOutOfRange);
	DET_ErrCheck((MCU_au8VectorMask[(uint8)((uint8)((u16VectNum)-4u)>>4u)] & (1u<<(uint8)((uint8)((uint8)((u16VectNum)-4u)>>1) &7u)))!=0u , DET_Err_VectNotMount);
	
	IFBits = (volatile uint16 *)(0xffe0u-(uint16)((uint16)((uint16)u8BitPos & 0x20u)>>1u) + (uint16)((uint16)((uint16)(((uint16)((uint16)u8BitPos & 0x10u))>>3u)))) ;
	u16MaskValue = (uint16)(1ul<<((uint16)((uint16)u8BitPos&0xfu)));

	DI();
	/*clean the IF bit -->
	WAINING: it may lose IF if the IRQ request happen between this time !!*/
	*IFBits &=(uint16)~u16MaskValue;
	EI();
	
	return u16RetVal;

}

#if MCU_mINTPriorityChgEnable!=0u
/*****************************************************************************
 Function  : MCU_u16ChangeVectorPriority												 
 Description   : change a vector number interrupt priority
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u16TargePri: new interrupt priority for u16VectNum
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			u16TargePri: 	0 ----->highest priority
 						3----->lowest priority
*****************************************************************************/
uint16 MCU_u16ChangeVectorPriority(uint16 u16VectNum,uint16 u16TargePri)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile uint16 *MKBits;
	uint16 u16MaskValue;
	uint8 u8BitPos=(uint8)((u16VectNum-4u)>>1u);
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(((u16VectNum>=MCU_mMinVectNum)&&(u16VectNum<=MCU_mMAxVectNum)), DET_Err_VectNumberOutOfRange);
	DET_ErrCheck(u16TargePri<4u, DET_Err_VectPriorityOutOfRange);
	DET_ErrCheck((MCU_au8VectorMask[(uint8)((uint8)((u16VectNum)-4u)>>4u)] & (1u<<(uint8)((uint8)((uint8)((u16VectNum)-4u)>>1) &7u)))!=0u , DET_Err_VectNotMount);

	
	MKBits = (volatile uint16 *)(0xffe8u-(uint16)((uint16)((uint16)u8BitPos & 0x20u)>>1u) + (uint16)((uint16)((uint16)(((uint16)((uint16)u8BitPos & 0x10u))>>3u)))) ;
	u16MaskValue = (uint16)(1ul<<((uint16)((uint16)u8BitPos&0xfu)));

	DI();
	/*PRxxL*/
	if((uint8)(u16TargePri & 0x01) ==0u)
	{
		*MKBits &=~u16MaskValue;
	}
	else
	{
		*MKBits |=u16MaskValue;
	}
	
	/*PRxxH*/
	MKBits++;
	if((uint8)(u16TargePri & 0x02) ==0u)
	{
		*MKBits &=~u16MaskValue;
	}
	else
	{
		*MKBits |=u16MaskValue;
	}	
	EI();
	
	return u16RetVal;
}

#endif


#if MCU_mEINTModelEnable!=0u

/*****************************************************************************
 Function  : MCU_u16EINTinit												 
 Description   : external interrupt model initial in reset
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			it execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16EINTinit(void)
{
	uint8 u8Loop,u8PinLocate;
	uint16 u16TrigLevel_0=0u,u16TrigLevel_1=0u,u16StartRun=0u;
	uint16 u16ENITusing=0u,u16Mask,u16Trigger,u16IdMask;
	uint16 u16RetVal=DET_Err_NotErr;
	
	
	/*relative register*/
	volatile uint8 *pEGP;
	
	/*Init the record*/
	MCU_au16EINTStatus_Init[0u]=0u;
	MCU_au16EINTStatus_Run[0u]=0u;

	for(u8Loop=0u;u8Loop<MCU_mMaxEINTchannelMount;u8Loop++)
	{
		u8PinLocate=MCU_stEINTUsrCfg[u8Loop].u8LocatPinMask;
		if(u8PinLocate !=0xFFu)
		{
			u16IdMask=(uint16)(1ul<<(uint16)u8Loop);
			
			/*check the resource is mounted or not*/
			if(u8PinLocate == 0u)
			{
				/*normal pin using*/
				DET_ErrCheck((((uint16)(MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u) ), DET_Err_EINTNotMounted);
			}
			else
			{
				/*higher pin using*/
				DET_ErrCheck((((uint16)(MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u)), DET_Err_EINTNotMounted);
				IPSEL0 |=(uint8)(1ul<<u8Loop);
			}

			u16Mask=(uint16)(1ul<<u8Loop);
			
			u16ENITusing|=u16Mask;

		
			/*check the triger ID is in ragne or not*/
			u16Trigger=(uint16)MCU_stEINTUsrCfg[u8Loop].u8DetectCondition;
			DET_ErrCheck(u16Trigger<=3u, DET_Err_EINTtrigerIDOutOfRange);

			/*setting value for edge detect register*/
			u16TrigLevel_1 |=(uint16)((uint16)(u16Trigger & 1u)<<u8Loop);
			u16Trigger>>=1U;
			u16TrigLevel_0 |=(uint16)((uint16)(u16Trigger & 1u)<<u8Loop);
			
			/*check it need run in reset or not*/
			if(MCU_stEINTUsrCfg[u8Loop].u8RunWhenReset == 1u)
			{
				u16StartRun |=u16Mask;
				MCU_u16InterruptCtrl(MCU_stResourceEINT.u16VectorNumber[u8Loop],1u);
			}
			
		}
		else
		{
			/*set interrupt level-->not interrupt
			MCU_u16InterruptCtrl(MCU_stResourceEINT.u16VectorNumber[u8Loop],0u)*/
		}
		
	}

	DI();
	/*EGP0 & EGN*/
	pEGP=(volatile uint8 *)MCU_mEINTRegHead_EGP;
	/*merge the EGP0 and EGN0 value to uint16 and update them in 16bit format*/
	*pEGP=(uint8)(u16TrigLevel_0 & 0x00FFu);
	pEGP++;
	*pEGP=(uint8)(u16TrigLevel_1 & 0x00FFu);

	/*merge the EGP1 and EGN1 value to uint16 and update them in 16bit format*/
	pEGP++;
	*pEGP=(uint8)((uint8)(u16TrigLevel_0>>8u) & 0x00FFu);
	pEGP++;
	*pEGP=(uint8)((uint8)(u16TrigLevel_1>>8u) & 0x00FFu);
	EI();
	
	/*update record*/
	MCU_au16EINTStatus_Init[0U]=u16ENITusing;
	MCU_au16EINTStatus_Run[0u]=u16StartRun;
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vEINTIsr												 
 Description   : external interrupt service
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			 			
Return Value:
 			NULLt
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vEINTIsr(uint16 u16EINTid)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u16EINTid<MCU_mMaxEINTchannelMount, DET_Err_EINTIDOutOfRange);

	/*run callback function*/
	MCU_stEINTUsrCfg[u16EINTid].vpINTservice();
	
	u16RetVal+=1u;/*compiler warning*/
}


#if MCU_mEINTOnOffCtrlFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_u16EINTrunControl												 
 Description   : external interrupt detect control
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			u8On_Off: detect the interrupt enable or not
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static uint16 MCU_u16EINTrunControl(uint16 u16EintID, uint8 u8On_Off)
{
	uint16 u16IdMask=(uint16)(1ul<<u16EintID);
	uint16 u16RetVal=DET_Err_NotErr;
		
	/*check ID is in range*/
	DET_ErrCheck(u16EintID<MCU_mMaxEINTchannelMount , DET_Err_EINTIDOutOfRange);
	/*check the ID is in use*/
	DET_ErrCheck(MCU_stEINTUsrCfg[u16EintID].u8LocatPinMask!=(uint8)0xffu, DET_Err_EINTIDOutOfRange);

	/*check the resource is mounted or not*/
	if(MCU_stEINTUsrCfg[u16EintID].u8LocatPinMask == 0u)
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	else
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	
	if(u8On_Off !=0u)
	{
		/*open maskbit to enable interrupt*/
		MCU_u16InterruptCtrl(MCU_stResourceEINT.u16VectorNumber[u16EintID], 1u);
		MCU_au16EINTStatus_Run[0u] |=(uint16)(1ul<<u16EintID);
	}
	else
	{
		/*close maskbit to disable interrupt*/
		MCU_u16InterruptCtrl(MCU_stResourceEINT.u16VectorNumber[u16EintID], 0u);
		MCU_au16EINTStatus_Run[0u] &=(uint16)~(uint16)(1ul<<u16EintID);
	}

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16EINTenable												 
 Description   : external interrupt detect enable control
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTenable(uint16 u16EintID)
{
	return MCU_u16EINTrunControl(u16EintID,1u);	
}

/*****************************************************************************
 Function  : MCU_u16EINTdisable												 
 Description   : external interrupt detect disable control
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTdisable(uint16 u16EintID)
{
	return MCU_u16EINTrunControl(u16EintID,0u);	
}

#endif

#if MCU_mEINTtrigChgFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_u16EINTchgIntCondition												 
 Description   : external interrupt detect condition control
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTchgIntCondition(uint16 u16EintID,uint8 u8NewTrigerCondition)
{
	uint16 u16IdMask=(uint16)(1ul<<u16EintID);
	uint16 u16Address=MCU_mEINTRegHead_EGP;
	uint16 u16RetVal=DET_Err_NotErr;

	/*relative register*/
	volatile uint8 *pEGP;
	
	/*check ID is in range*/
	DET_ErrCheck(u16EintID<MCU_mMaxEINTchannelMount , DET_Err_EINTIDOutOfRange);
	
	/*check the triger ID input is right*/
	DET_ErrCheck(u8NewTrigerCondition<=3u, DET_Err_EINTtrigerIDOutOfRange);

	/*check the EINT triger is changeable*/
	DET_ErrCheck(MCU_stEINTUsrCfg[u16EintID].u8DetConditionChgable!=0u, DET_Err_EINTtrigerCanNotChg);

	/*check the resource is mounted or not*/
	if(MCU_stEINTUsrCfg[u16EintID].u8LocatPinMask == 0u)
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	else
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	
	if(u16EintID>=8u)
	{
		u16Address+=MCU_mEINTUnitSize;
		u16EintID-=8u;
	}

	DI();
	/*point to EGP*/
	pEGP=(volatile uint8 *)u16Address;
	if((u8NewTrigerCondition & 1u) !=0u)
	{
		*pEGP |=(uint8)(1u<<u16EintID);
	}
	else
	{
		*pEGP &=(uint8)(~(uint8)(1u<<u16EintID));
	}

	/*point to EGN*/
	pEGP++;
	if((u8NewTrigerCondition & 2u) !=0u)
	{
		*pEGP |=(uint8)(1u<<u16EintID);
	}
	else
	{
		*pEGP &=(uint8)(~(uint8)(1u<<u16EintID));
	}
	EI();
	
	return 	u16RetVal;

}

#endif

#if MCU_mEINTDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vEINTDeInit												 
 Description   : external interrupt model clear
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vEINTDeInit(void)
{
	uint8 u8Loop;
	
	/*relative register*/
	volatile uint16 *pEGP;

	/*Init the record*/
	MCU_au16EINTStatus_Init[0u]=0u;
	MCU_au16EINTStatus_Run[0u]=0u;

	DI();
	/*clean EGP0 and EGN0*/
	pEGP=(volatile uint16 *)MCU_mEINTRegHead_EGP;
	*pEGP=0u;
	
	/*clean EGP1 and EGN1*/
	pEGP++;
	*pEGP=0u;
	EI();
	
	for(u8Loop=0u;u8Loop<MCU_mMaxEINTchannelMount;u8Loop++)
	{
		/*close maskbit to disable interrupt*/
		MCU_u16InterruptCtrl(MCU_stResourceEINT.u16VectorNumber[u8Loop], 0u);		
	}
}

#endif

#endif/*end of EINT module*/

#if MCU_mADCModelEnable!=0u

/*****************************************************************************
 Function  : MCU_u16ADCinit												 
 Description   : ADC model initial in reset
 
 In Parameter: 
 			NULL

Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			this function execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16ADCinit(void)
{
	uint32 u32ADCchannel;
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8ChannelNum=0u,u8Loop;
	
	ADCEN = 1U;	/* supply AD clock */
	
	DET_ErrCheck((uint32)((~MCU_stResourceADC.u32ADCMountMask) & (MCU_stADCUsrCfg.u32ADCusing)) ==0ul , DET_Err_ADCNotMounted);
	/*the ADC value must use continue*/
	u32ADCchannel = MCU_stADCUsrCfg.u32ADCusing;
	DET_ErrCheck((uint16)((u32ADCchannel +1ul) & (u32ADCchannel)) ==0ul , DET_Err_ADCConfiguration);

	/*check how many ADC channel using*/
	while(u32ADCchannel>=1ul)
	{
		u32ADCchannel>>=1u;
		u8ChannelNum++;
	}

	/*at least one of ADC channel using*/
	DET_ErrCheck(u8ChannelNum !=0ul , DET_Err_ADCConfiguration);
	
	MCU_u8ADCStatus=1u;	
	
	ADM0 = 0x0u;
	
	ADPC = u8ChannelNum;
	ADM1 = 0x00u;	/* use software trigger for start singal */
	/*ADC module work enable*/
	ADCE=1u;
	ADSMP =0x7u;/*clock = 16M*/

	ADIF = 0U;	/* clear INTAD interrupt flag */
	ADMK = 0U;	/* enable INTAD interrupt */

	/* Set AD contorl register */		
	ADS = u8ChannelNum-1u;
	ADM0 |= 0x70u;/*interrupt after all channel finished and stop*/


	/*set pin direction to INPUT mode -->
	this operation is finish in Port_init*/
	
	/*clear RAM data in reset*/
	for(u8Loop=0u;u8Loop<MCU_mMaxADCchannelMount;u8Loop++)
	{
		MCU_au16AdcResault[u8Loop]=0u;
	}

	MCU_u8ADCUsingChannel = u8ChannelNum;
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCstart												 
 Description   : ADC model start to convort
 
 In Parameter: 
 			NULL
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCstart(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(MCU_u8ADCStatus !=0u , DET_Err_ADCNotInit);
	
	MCU_u8ADCStatus=2u;
	
	/*start ADC*/
	ADCS = 1U;

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCstop												 
 Description   : ADC model stop to convort
 
 In Parameter: 
			NULL
			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCstop(void)
{
	
	/*stop ADC*/
	ADCS = 0U;	/* disable AD conversion */
	MCU_u8ADCStatus=3u;
	
	return DET_Err_NotErr;

}

/*****************************************************************************
 Function  : MCU_u16ADCsleep												 
 Description   : ADC module go to sleep before system into standby mode
 
 In Parameter: 
 			NULL
 			
Return Value:
 			DET_Err_NotErr
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCsleep(void)
{
	
	MCU_u8ADCStatus=0u;	
	
	ADMK = 1U;	/* disable INTAD interrupt */
	ADIF = 0U;	/* clear INTAD interrupt flag */
	ADM0 = 0u;	/* disable AD conversion and clear ADM0 register */
	ADPC=0u;
	ADS=0u;
	ADSMP=0u;
	
	ADCEN = 0U;	/* never supply AD clock */
	
	return DET_Err_NotErr;

}

/*****************************************************************************
 Function  : MCU_u16ADCwakeUp												 
 Description   : ADC module leave sleep mode after system out form halt/stop mode
 
 In Parameter: 
 			NULL
 			
Return Value:
 			DET_Err_NotErr
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCwakeUp(void)
{
	uint32 u32ADCchannel;
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8ChannelNum=0u,u8Loop;
	
	ADCEN = 1U;	/* supply AD clock */
	
	DET_ErrCheck((uint32)((~MCU_stResourceADC.u32ADCMountMask) & (MCU_stADCUsrCfg.u32ADCusing)) ==0ul , DET_Err_ADCNotMounted);
	/*the ADC value must use continue*/
	u32ADCchannel = MCU_stADCUsrCfg.u32ADCusing;
	DET_ErrCheck((uint16)((u32ADCchannel +1ul) & (u32ADCchannel)) ==0ul , DET_Err_ADCConfiguration);

	/*check how many ADC channel using*/
	while(u32ADCchannel>=1ul)
	{
		u32ADCchannel>>=1u;
		u8ChannelNum++;
	}

	/*at least one of ADC channel using*/
	DET_ErrCheck(u8ChannelNum !=0ul , DET_Err_ADCConfiguration);
	
	MCU_u8ADCStatus=1u;	
	
	ADM0 = 0x0u;
	
	ADPC = u8ChannelNum;
	ADM1 = 0x00u;	/* use software trigger for start singal */
	/*ADC module work enable*/
	ADCE=1u;
	ADSMP =0x7u;/*clock = 16M*/

	ADIF = 0U;	/* clear INTAD interrupt flag */
	ADMK = 0U;	/* enable INTAD interrupt */

	/* Set AD contorl register */		
	ADS = u8ChannelNum-1u;
	ADM0 |= 0x70u;/*interrupt after all channel finished and stop*/


	/*set pin direction to INPUT mode -->
	this operation is finish in Port_init*/
	
	MCU_u8ADCUsingChannel = u8ChannelNum;
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCstart												 
 Description   : external interrupt detect condition control
 
 In Parameter: 
 			u16EintID: EINT ID list in _78K0R.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vADCIsr(void)
{
	uint8 u8i;
	volatile uint16 *pu16AdcAddr=(volatile uint16 *)MCU_mADCresaultHead;
	
	/*ADIF = 0U	 clear INTAD interrupt flag -->clear auto */
	
	for(u8i=0u;u8i<MCU_u8ADCUsingChannel;u8i++)
	{
		MCU_au16AdcResault[u8i]=(uint16)(pu16AdcAddr[u8i]>>6u);
	}

}

/*****************************************************************************
 Function  : MCU_u16ADCgetResault												 
 Description   :get the ADC resault
 
 In Parameter: 
 			u8ChannelID: ADC ID list in _78K0R.h
 			*u16AD_Resault: ADC output resault address
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCgetResault(uint8 u8ChannelID, uint16 *u16AD_Resault)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u8ChannelID<MCU_u8ADCUsingChannel , DET_Err_ADCNotInit);
	DET_ErrCheck(((~MCU_stResourceADC.u32ADCMountMask) & ((uint32)(1ul<<u8ChannelID))) ==0ul , DET_Err_ADCNotMounted);
	DET_ErrCheck(MCU_u8ADCStatus !=0u , DET_Err_ADCNotInit);
	DET_ErrCheck((uint32)((uint32)(1ul<<u8ChannelID) & (MCU_stADCUsrCfg.u32ADCusing)) !=0ul , DET_Err_ADCNotMounted);

	*u16AD_Resault=MCU_au16AdcResault[u8ChannelID];
	
   	 return u16RetVal;
}

#if MCU_mADCDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vADCDeInit												 
 Description   :clean the ADC model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vADCDeInit(void)
{
	uint8 u8Loop;
	
	MCU_u8ADCStatus=0u;	
	MCU_u8ADCUsingChannel=0u;
	
	ADMK = 1U;	/* disable INTAD interrupt */
	ADIF = 0U;	/* clear INTAD interrupt flag */
	ADM0 = 0u;	/* disable AD conversion and clear ADM0 register */
	ADPC=0u;
	ADS=0u;
	ADSMP=0u;
	
	ADCEN = 0U;	/* never supply AD clock */
	/*clear RAM data to reset value*/
	for(u8Loop=0u;u8Loop<MCU_mMaxADCchannelMount;u8Loop++)
	{
		MCU_au16AdcResault[u8Loop]=0u;
	}

}

#endif

#endif/*end of ADC module*/


#if ((MCU_mCSImodelEnable !=0u) || (MCU_mSerialUartmodelEnable !=0u) ||(MCU_mIICmodelEnable!=0u))
/*****************************************************************************
 Function  : MCU_vSerialISR												 
 Description   :Serial Array model interrupt
 
 In Parameter: 
 			u16Ch: Serial channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it will contorl all of serial interrupt type
*****************************************************************************/
void MCU_vSerialISR(uint16 u16Ch)
{
	uint16 u16SerialType=(uint16)MCU_au8SerialUsingType[u16Ch];
	uint16 u16RetVal=DET_Err_NotErr;

	#if MCU_mSerialUartmodelEnable !=0u
	/*UART RX interrupt!!*/
	if(u16Ch == 5u)
	{
		MCU_vSerialUartIsr_Rx(MCU_mSerial_ID_UART2);
	}
	else
	#endif
	{
		#if MCU_mCSImodelEnable !=0u
		/*CSI TX/RX interrupt*/
		if(u16SerialType == SerialType_CSI)
		{
			MCU_vCSIIsr(u16Ch);
		}
		/*IIC TX/RX interrupt*/
		else
		#endif
		
		#if MCU_mIICmodelEnable !=0u
		if(u16SerialType == SerialType_IIC)
		{
			MCU_vIICIsr(u16Ch);
		}
		/*UART TX interrupt!!*/
		else 
		#endif
		
		#if MCU_mSerialUartmodelEnable !=0u
		if(u16SerialType == SerialType_UART)
		{
			MCU_vSerialUartIsr_Tx(MCU_mSerial_ID_UART2);
		}
		else
		#endif
		{
			DET_ErrReport(DET_Err_RunModeOutOfRange);
		}
	}

}
#endif

#if MCU_mCSImodelEnable!=0u
/*****************************************************************************
 Function  : MCU_vCSIinit												 
 Description   : serial model initial in reset
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			this function execute before system-mainloop
*****************************************************************************/
static void MCU_vCSIinit(void)
{
	uint16 u16LoopGruop,u16LoopUnit,u16Index=0u,u16SMRTemp,u16MaskBit;
	uint16 u16SO,u16SOE,u16SE,u16SMR[2],u16SCR[2],u16SDR,u16SPS=0x0004u;/*CLK1=16M,CLK0=1M defalut*/
	uint16 u16SOL;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstSerialArray *pSerial = (volatile MCU_tstSerialArray *)MCU_mSerialGroupHead;
	volatile uint16 *pSDR=(volatile uint16 *)MCU_mSDRHead_Group0_1;
	
	for(u16LoopGruop=0u;u16LoopGruop<2u;u16LoopGruop++)
	{
		u16MaskBit=1u;
		u16SO=0u;
		u16SOE=0u;
		u16SE=0u;
		u16SOL=0u;
		
		u16SMR[0u]=0u;
		u16SMR[1u]=0u;
		
		u16SCR[0u]=0u;
		u16SCR[1u]=0u;
		
		u16SDR=0u;
                
		for(u16LoopUnit=0u;u16LoopUnit<2u;u16LoopUnit++)
		{
			u16SE=0u;
			u16MaskBit<<=u16LoopUnit;
			u16SMRTemp=MCU_stCSIUsrCfg[u16Index].u16SerialType; 
			
			if(u16SMRTemp !=0xFFFFU)
			{
				/*check resource mount or not!!*/
				DET_ErrCheck((uint16)(MCU_stResourceSerial.u16CSImount & (uint16)(1ul<<u16Index )) !=0u, DET_Err_SerialTypeOutOfRange);

				/*check resource has  used or not!!*/
				DET_ErrCheck(MCU_au8SerialUsingType[u16Index]==SerialType_NULL, DET_Err_SerialInUsing);
				
				/*spuuly clock to the unit!*/
				if(u16LoopGruop == 0u)
				{
					PER0 |= (uint8)(1u<<3u);
				}
				else
				{
					PER0 |= (uint8)(1u<<4u);
				}
				
				u16SMR[u16LoopUnit]=u16SMRTemp;
				u16SCR[u16LoopUnit]=MCU_stCSIUsrCfg[u16Index].u16SCRmap;
				u16SDR=MCU_stCSIUsrCfg[u16Index].u16SDRmap;
				
				u16SO |=u16MaskBit;			/*check SO type level,default is HIGH*/
				if((uint16)(u16SDR & 0x2000u)!=0u)	/*check clk type level*/
				{
					u16SO |=(uint16)(u16MaskBit<<8u);
				}
				u16SOE|=u16MaskBit;		/*output enable defalut*/
				u16SE|=u16MaskBit;		/*serial unit enable defalut*/

				/*interrupt enable in default*/
				MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[u16Index], 1u);

				/*Record Serial type for proccess!*/
				MCU_au8SerialUsingType[u16Index]=SerialType_CSI;
				
				*pSDR = u16SDR;	/*update SDR value first, it not in the group!*/
				
			}			
			
			pSDR++;			/*Piont to next SDR!*/
			u16Index++;
		}

		DI();
		/*this group serial is in use, so need update register value after info collected */
		if(u16SE !=0u)
		{
			pSerial->u16SPS = u16SPS;	/*Clock config*/
			pSerial->u16SMR[0u]=u16SMR[0u];		/*SMR*/
			pSerial->u16SMR[1u]=u16SMR[1u];
			pSerial->u16SCR[0u]=u16SCR[0u];		/*SCR*/
			pSerial->u16SCR[1u]=u16SCR[1u];

			pSerial->u16SOL=u16SOL;			/*Output logic*/
			pSerial->u16SO=u16SO;				/*Output level*/
			pSerial->u16SOE=u16SE;			/*Output Enable*/
			pSerial->u16SS=u16SE;				/*serial start run!!!*/
		}	
		EI();
		
		pSerial++;		/*piont to next serial group*/
		
	}

	/*check the CSI-00 Pin sel !!*/
	if((MCU_stCSIUsrCfg[0u].u16PinSel !=0u) && (MCU_au8SerialUsingType[0u] !=0u))
	{
		DI();
		STSEL |= (uint8)(1u<<4u);
		EI();
	}
	
}

/*****************************************************************************
 Function  : MCU_u16CSI_MasterTransfer												 
 Description   :CSI send / receive data control, master mode
 
 In Parameter: 
 			u16CsiID:CSI ID list in _78K0R.h
 			pu16DataHead: need send data head 
 			pu16RecDataHead : need receive data head 
 			u16DataLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16CSI_MasterTransfer(uint16 u16CsiID,uint16 pu16SendDataHead[], uint16 pu16RecDataHead[],uint16 u16DataLen)
{
	uint16 u16RetVal=DET_Err_NotErr;

	volatile uint16 *pSDR=(volatile uint16 *)MCU_mSDRHead_Group0_1;

	DET_ErrCheck(MCU_au8SerialUsingType[u16CsiID]==SerialType_CSI, DET_Err_SerialTypeOutOfRange);
	DET_ErrCheck(((pu16SendDataHead !=NULL) ||(pu16RecDataHead !=NULL)) , DET_Err_SerialParaInvalib);
	
	if(MCU_stCSIrunStatus[u16CsiID].u8RunMode ==SerialReady)/*CSI is ready*/
	{
		MCU_stCSIrunStatus[u16CsiID].u16TottalDataLen=u16DataLen>>1u;
		MCU_stCSIrunStatus[u16CsiID].pu16DataHead=pu16SendDataHead;
		MCU_stCSIrunStatus[u16CsiID].puRecDataHead=pu16RecDataHead;
		
		MCU_stCSIrunStatus[u16CsiID].u16WorkingDataLen=0u;
		MCU_stCSIrunStatus[u16CsiID].u8RunMode=SerialSending;	/*1 is send mode!*/	
		
		pSDR+=u16CsiID;

		DI();
		if(pu16SendDataHead != NULL)
		{
			*pSDR = pu16SendDataHead[0u];
		}
		else
		{
			*pSDR = Serial_Dummy_u16Data;
		}
		EI();
		
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_vCSIIsr												 
 Description   :CSI model interrupt
 
 In Parameter: 
 			u16Ch: CSI channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vCSIIsr(uint16 u16Ch)
{
	uint16 u16Err,u16Lenth,u16ReceiveData;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstSerialArray *pSerial = (volatile MCU_tstSerialArray *)MCU_mSerialGroupHead;
	volatile uint16 *pSDR;

	DET_ErrCheck(u16Ch<MCU_mMaxCSIchannelMount, DET_Err_SerialIDOutOfRange);
	DET_ErrCheck(MCU_au8SerialUsingType[u16Ch] ==SerialType_CSI, DET_Err_SerialTypeOutOfRange);
	
	u16Lenth=MCU_stCSIrunStatus[u16Ch].u16WorkingDataLen;

	/*fine out serial group!!*/
	pSerial +=u16Ch>>1u;
	
	/*find out SDR position*/
	pSDR=(volatile uint16 *)MCU_mSDRHead_Group0_1;
	pSDR+=u16Ch;

	/*get the receive data any way*/
	u16ReceiveData=*pSDR;

	/*check error happen or not*/
	u16Err=pSerial->u16SSR[(uint16)(u16Ch&1u)];
	u16Err&=7u;
	
	if(u16Err !=0u)
	{
		MCU_stCSIrunStatus[u16Ch].u16Error = u16Err;
		pSerial->u16SIR[(uint16)(u16Ch&1u)]=7u;/*clear error bit*/
	}

	/*data receive, store it*/
	if(MCU_stCSIrunStatus[u16Ch].puRecDataHead != NULL)
	{
		MCU_stCSIrunStatus[u16Ch].puRecDataHead[u16Lenth]=u16ReceiveData;
	}

	/*working lenth process*/
	MCU_stCSIrunStatus[u16Ch].u16WorkingDataLen++;
	u16Lenth++;
	
	if(u16Lenth>= MCU_stCSIrunStatus[u16Ch].u16TottalDataLen)
	{
		/*send finish, then set the status to ready*/
		MCU_stCSIrunStatus[u16Ch].u8RunMode = SerialReady;
		
		if(MCU_stCSIrunStatus[u16Ch].u16Error!=0u)
		{
			/*error happen, need call err_CB before call finish_CB*/
			MCU_stCSIUsrCfg[u16Ch].vu16ErrCallBack(MCU_stCSIrunStatus[u16Ch].u16Error);
			MCU_stCSIrunStatus[u16Ch].u16Error=0u;/*clear record!*/
		}
		
		/*Transfer finish, then call Transfer_CB*/
		MCU_stCSIUsrCfg[u16Ch].vpSendFinish();
	}
	else
	{
		/*transfer not finish, then continue to send out data! CSI mode defalut is 16bit lenth*/
		if(MCU_stCSIrunStatus[u16Ch].pu16DataHead !=NULL)
		{
			*pSDR = MCU_stCSIrunStatus[u16Ch].pu16DataHead[u16Lenth];
		}
		else
		{
			*pSDR = Serial_Dummy_u16Data;
		}
	}
		
}

#if MCU_mCSIdeinitEnable!=0u
/*****************************************************************************
 Function  : MCU_vCSIdeinit												 
 Description   :CSI model de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			ALL IIC channel can not be used until MCU reset
*****************************************************************************/
void MCU_vCSIdeinit(void)
{
	PER0 &= ~(uint8)(3u<<3u);/*clock supply disable*/

	MCU_stCSIrunStatus[0u].u8RunMode=0xFFu;
	MCU_stCSIrunStatus[1u].u8RunMode=0xFFu;
	MCU_stCSIrunStatus[2u].u8RunMode=0xFFu;
	MCU_stCSIrunStatus[3u].u8RunMode=0xFFu;

	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[0u], 0u);
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[1u], 0u);
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[2u], 0u);
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[3u], 0u);

}

#endif



#endif	 /*end of CSI module*/

#if MCU_mSerialUartmodelEnable !=0u
/*****************************************************************************
 Function  : MCU_u16UARTinit												 
 Description   :initial the UART model
 
 In Parameter: 
 			NULL

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function run before system-mainloop
*****************************************************************************/
static void MCU_vSerialUartInit(void)
{
	uint16 u16SCR,u16SPS=0x0004u;/*CLK1=16M,CLK0=1M defalut*/
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16BaudRate;
	
	/*UART 2 initial*/
	if(MCU_stSerialUartUsrCfg.u16BaudRate !=0u)
	{
		/*check resource mount or not!!*/
		DET_ErrCheck((uint16)(MCU_stResourceSerial.u16UARTmount & (uint16)(1u<<4u )) !=0u, DET_Err_SerialTypeOutOfRange);

		/*check resource has  used or not!!*/
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_UART2]==SerialType_NULL, DET_Err_SerialInUsing);

		PER1 |=(uint8)(1u<<3u);		/*serial group clock supply*/	
		
		/*interrupt enable in default-TX interrupt*/
		MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[4u], 1u);
		/*interrupt enable in default-RX interrupt*/
		MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[5u], 1u);
				
		SPS2 = u16SPS; /*clock divide*/

		/*Transmission channel!*/
		SMR20=Serial_UART_S;

		u16SCR =  (uint16)((uint16)((uint16)MCU_stSerialUartUsrCfg.u8Parity & 3u) <<8u);/*parity type*/
		if(MCU_stSerialUartUsrCfg.u8MsbLsb !=0u)			/*lsb/msb type*/
		{
			u16SCR |=(uint16)(1ul<<7u);
		}
		u16SCR |=(uint16)((uint16)((uint16)MCU_stSerialUartUsrCfg.u8StopBit & 3u) <<4u);/*stop bit type*/
		u16SCR |=0x0007u; /*bit lenth is 8bits*/
		SCR20=u16SCR|0x8000u;		/*TX only*/

		u16BaudRate = ((uint16)((uint32)(1000000ul/2u)/MCU_stSerialUartUsrCfg.u16BaudRate-1u)<<9u);
		
		SDR20 = u16BaudRate;

		/*Reception channel!*/
		SMR21=Serial_UART_R;
		
		if(MCU_stSerialUartUsrCfg.u8IOReverse !=0u)	
		{
			SOL2 |=0x0001u;/*level logic reverse---->output channel*/
			SMR21 |=(uint16)(1u<<6u);/*level logic reverse---->input channel*/
		}
		SCR21=u16SCR|0x4000u;		/*RX only*/

		SDR21 =u16BaudRate;
		
		SO2 |=0x0001u;/*TX channel output enable!*/
		SOE2 |= 0x0001u;
		
		SS2 |= 3u;		/*RX/TX start!*/
		
		/*Record Serial type for proccess!*/
		MCU_au8SerialUsingType[MCU_mSerial_ID_UART2]=SerialType_UART;
		
		MCU_stSerialUartRunStatus.u16TottalDataLen =MCU_mUARTReadyDefValue;
		
	}	

}


/*****************************************************************************
 Function  : MCU_u16SerialUartSend												 
 Description   :UART send data control
 
 In Parameter: 
 			u16channel:UART ID list in _78K0R.h
 			pu8DataHead: need send data head 
 			u16SendLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16SerialUartSend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen)
{
	uint16 u16RetVal=DET_Err_NotErr;
		
	if(u16channel == MCU_mSerial_ID_UART2)
	{
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_UART2] ==SerialType_UART, DET_Err_SerialTypeOutOfRange);

		if((MCU_stSerialUartRunStatus.u16TottalDataLen==MCU_mUARTReadyDefValue) &&
			(u16SendLen>0u))
		{
			MCU_stSerialUartRunStatus.u16TottalDataLen = u16SendLen;
			MCU_stSerialUartRunStatus.u16WorkingDataLen= 0u;
			MCU_stSerialUartRunStatus.pu8DataHead= pu8DataHead;
			
			SDR20 = pu8DataHead[0u];
		}
		else
		{
			if(u16SendLen==0u)
			{
				u16RetVal=DET_Err_UARTLenthError;
			}
			else
			{
				u16RetVal=DET_Err_UARTNotReady;
			}
		}
	}
	else
	{
		DET_ErrReport(DET_Err_UARTIDOutOfRange);
	}

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16SerialUartCtrl												 
 Description   :UART send and receive control
 
 In Parameter: 
 			u16channel:UART ID list in _78K0R.h
 			u8SendEnable: enable send data or not
 			u8RecEnable: enable receive data or not
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16SerialUartCtrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;

	if(u16channel == MCU_mSerial_ID_UART2)
	{
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_UART2] ==SerialType_UART, DET_Err_SerialTypeOutOfRange);

		if(u8SendEnable !=0u)
		{
			SCR20 |= (uint16)(1u<<15U);
		}
		else
		{
			SCR20 &= (uint16)~(uint16)(1u<<15U);
		}

		if(u8RecEnable !=0u)
		{
			SCR21 |= (uint16)(1u<<14U);
		}
		else
		{
			SCR21 &= (uint16)~(uint16)(1u<<14U);
		}
	}
	else
	{
		DET_ErrReport(DET_Err_SerialTypeOutOfRange);
	}

	return u16RetVal;
	
}

#if MCU_mUARTDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vSerialUartDeint												 
 Description   :clean UART model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vSerialUartDeint(void)
{	
	/*interrupt disable*/
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[4u], 0u);
	/*interrupt disable*/
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[5u], 0u);
	
	MCU_stSerialUartRunStatus.u16TottalDataLen =0u;

	PER1 &=~(uint8)(1u<<3u);		/*serial group clock supply disable*/	
}

#endif


/*****************************************************************************
 Function  : MCU_vSerialUartIsr_Rx												 
 Description   :serial UART model Rx interrupt
 
 In Parameter: 
 			u16channel: channel ID, always = MCU_mSerial_ID_UART2
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vSerialUartIsr_Rx(uint16 u16channel)
{
	uint16 u16Err;
	uint16 u16data;
	uint16 u16RetVal=DET_Err_NotErr;
	
	if(MCU_mSerial_ID_UART2 == u16channel)
	{
		u16data=SDR21;
		u16Err = SSR21;
		
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_UART2] ==SerialType_UART, DET_Err_SerialTypeOutOfRange);
		if((uint16)(u16Err & 7u) !=0u)
		{
			SIR21=7u;/*clear error bit*/
			/*error happen, need call err_CB before call finish_CB*/
			MCU_stSerialUartUsrCfg.vu16ErrCallBack(u16Err);
		}
		
		/*send finish, then call finish_CB*/
		MCU_stSerialUartUsrCfg.vu8RecCallBack((uint8)u16data);
	}
	else
	{
		DET_ErrReport(DET_Err_UARTIDOutOfRange);
	}
}

/*****************************************************************************
 Function  : MCU_vSerialUartIsr_Tx												 
 Description   :serial UART model Tx interrupt
 
 In Parameter: 
 			u16channel: channel ID, always = MCU_mSerial_ID_UART2
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vSerialUartIsr_Tx(uint16 u16channel)
{
	uint16 u16Err;
	uint16 u16Lenth;
	uint16 u16RetVal=DET_Err_NotErr;

	if(MCU_mSerial_ID_UART2 == u16channel)
	{
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_UART2] ==SerialType_UART, DET_Err_SerialTypeOutOfRange);

		u16Err = SSR20;
		if(u16Err !=0u)
		{
			SIR20=7u;/*clear error bit*/
			MCU_stSerialUartRunStatus.u16Error=u16Err;
			/*MCU_stSerialUsrCfg[2u].vu16ErrCallBack(u16Err)*/
		}
		
		/*send finish, index add first!*/
		MCU_stSerialUartRunStatus.u16WorkingDataLen++;
		u16Lenth=MCU_stSerialUartRunStatus.u16WorkingDataLen;
		
		if(u16Lenth>= MCU_stSerialUartRunStatus.u16TottalDataLen)
		{
			/*send finish, then set the status to ready*/
			MCU_stSerialUartRunStatus.u16TottalDataLen =MCU_mUARTReadyDefValue;
			
			if(MCU_stSerialUartRunStatus.u16Error!=0u)
			{
				/*error happen, need call err_CB before call finish_CB*/
				MCU_stSerialUartUsrCfg.vu16ErrCallBack(MCU_stSerialUartRunStatus.u16Error);
				MCU_stSerialUartRunStatus.u16Error=0u;/*clear record!*/
			}
			
			/*send finish, then call finish_CB*/
			MCU_stSerialUartUsrCfg.vpSendFinish();
		}
		else
		{
			/*send not finish, then continue to send out data! CSI mode defalut is 16bit lenth*/
			SDR20 = MCU_stSerialUartRunStatus.pu8DataHead[u16Lenth];
		}
	}
	else
	{
		DET_ErrReport(DET_Err_UARTIDOutOfRange);
	}
	
}

#endif


#if MCU_mLinUart_modelEnable !=0u
/*****************************************************************************
 Function  : MCU_u16UARTinit												 
 Description   :initial the UART model
 
 In Parameter: 
 			NULL

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function run before system-mainloop
*****************************************************************************/
static void MCU_vLinUart_Init(void)
{
	uint16 u16BaudRate;
	uint16 u16RetVal=DET_Err_NotErr;

	uint16 u16Ctl1[2];
	
	uint8 u8Ctl0[2],u8Opt0[2]={0x14u,0x14u},u8Opt1[2],u8Opt2[2],u8Loop,u8Ctl0Temp;

	/*LIN-UART0 initial*/
	for(u8Loop = 0u;u8Loop<2u;u8Loop++)
	{
		if(MCU_stLinUartUsrCfg[u8Loop].u16BaudRate !=0u)
		{
			/*check resource mount or not!!*/
			DET_ErrCheck(MCU_stResourceLinUart.u16VectorNumber_RX[u8Loop] != 0xFFFFu , DET_Err_SerialTypeOutOfRange);

			/*baudRate Seting*/
			u16BaudRate = (uint16)(1000000ul/MCU_stLinUartUsrCfg[u8Loop].u16BaudRate);
			u16BaudRate |=0x6000u;/*set base clock to 1M*/
			u16Ctl1[u8Loop] = u16BaudRate;

			/*In/Out logic*/
			if((uint8)(MCU_stLinUartUsrCfg[u8Loop].u8IOReverse & 1u) != 0u)/*check In/Out level is revers or not*/
			{
				u8Opt0[u8Loop] |=3u;/*bit0 = Rx logc, bit1 = Tx logic*/
			}
			
			/*set to UART mode*/
			u8Opt1[u8Loop] = 0u;	
			/*Tx finish interrupt and Rx not use niose filter*/
			u8Opt2[u8Loop] =0x03u; 
			
			/*proccess the parity, it different to serial index!*/
			u8Ctl0Temp =MCU_stLinUartUsrCfg[u8Loop].u8Parity; 
			if(u8Ctl0Temp ==2u){
				u8Ctl0Temp =(uint8)(3u<<2u);
			}else if(u8Ctl0Temp == 3u){
				u8Ctl0Temp=(uint8)(2u<<2u);
			}else
			{
				u8Ctl0Temp<<=2u;
			}
			
			/*data direction, 1 =  LSB*/
			if(MCU_stLinUartUsrCfg[u8Loop].u8MsbLsb !=0u)
			{
				u8Ctl0Temp |=(uint8)(1u<<4u);
			}
			
			/*transfer data lenth, defalut is 8bit*/
			u8Ctl0Temp |=(uint8)(1u<<1u);
			
			/*set stop bit number, defalut is 1bit*/
			if(MCU_stLinUartUsrCfg[u8Loop].u8StopBit ==2u)
			{
				u8Ctl0Temp |=1u;
			}
		
			/*update value to register*/
			u8Ctl0[u8Loop]=u8Ctl0Temp | 0x60u;/*TX/RX enable*/

			/*interrupt enable in default*/
			MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_RX[u8Loop] , 1u);
			/*interrupt enable in default*/
			MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_TX[u8Loop] , 1u);

			MCU_stLinUartRunStatus[u8Loop].u16TottalDataLen =MCU_mUARTReadyDefValue;
			
		}	
		else
		{
			MCU_stLinUartRunStatus[u8Loop].u16TottalDataLen =0u;
		}

	}
	
	if(MCU_stLinUartRunStatus[0u].u16TottalDataLen ==MCU_mUARTReadyDefValue )
	{
		PER0 |=(uint8)(1u<<5u);		/*LIN-UART 0  group clock supply*/	
		
		for(u8Loop=0u;u8Loop<4u;u8Loop++)
		{
                        /*small delay*/
			;
		}
	
		UF0CTL1 =u16Ctl1[0u];
		UF0OPT0=u8Opt0[0u];
		UF0OPT1=u8Opt1[0u];
		UF0OPT2=u8Opt2[0u];
		UF0CTL0 =u8Ctl0[0u];
	}
	
	if(MCU_stLinUartRunStatus[1u].u16TottalDataLen ==MCU_mUARTReadyDefValue )
	{
		PER0 |=(uint8)(1u<<6u);		/*LIN-UART 1  group clock supply*/	

		for(u8Loop=0u;u8Loop<4u;u8Loop++)
		{
                        /*small delay*/
			;
		}
		/*In/Out pin select*/
		if((MCU_stLinUartUsrCfg[1u].u8IOReverse & 2u) != 0u)
		{
			STSEL |=(uint8)(1u<<7u);
		}	
		
		UF1CTL1 =u16Ctl1[1u];
		UF1OPT0=u8Opt0[1u];
		UF1OPT1=u8Opt1[1u];
		UF1OPT2=u8Opt2[1u];
		UF1CTL0 =u8Ctl0[1u];		
	}
	
}

/*****************************************************************************
 Function  : MCU_u16LinUartSend												 
 Description   :Lin-UART send data control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _78K0R.h
 			pu8DataHead: need send data head 
 			u16SendLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16LinUartSend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(((u16channel==MCU_mSerial_ID_UARTF0 )||(u16channel==MCU_mSerial_ID_UARTF1 )), DET_Err_LinUartIDOutOfRange);

	/*mirror to internal ID*/
	if(u16channel==MCU_mSerial_ID_UARTF1)
	{
		u16channel=1u;
	}
	else
	{
		u16channel=0u;
	}
	
	if((MCU_stLinUartRunStatus[u16channel].u16TottalDataLen ==MCU_mUARTReadyDefValue) &&
		(u16SendLen>0u))
	{
		MCU_stLinUartRunStatus[u16channel].u16TottalDataLen = u16SendLen;
		MCU_stLinUartRunStatus[u16channel].u16WorkingDataLen= 0u;
		MCU_stLinUartRunStatus[u16channel].pu8DataHead= pu8DataHead;

		if(u16channel == 0u)
		{
			UF0TXB = pu8DataHead[0u];
		}
		else
		{
			UF1TXB = pu8DataHead[0u];
		}
	}
	else
	{
		if(u16SendLen==0u)
		{
			u16RetVal=DET_Err_UARTLenthError;
		}
		else
		{
			u16RetVal=DET_Err_UARTNotReady;
		}
	}

	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_u16LinUartCtrl												 
 Description   :Lin-UART send and receive control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _78K0R.h
 			u8SendEnable: enable send data or not
 			u8RecEnable: enable receive data or not
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16LinUartCtrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(((u16channel==MCU_mSerial_ID_UARTF0 )||(u16channel==MCU_mSerial_ID_UARTF1 )), DET_Err_LinUartIDOutOfRange);

	if(u16channel==MCU_mSerial_ID_UARTF0 )
	{
		if(u8SendEnable !=0u)
		{
			UF0CTL0 |= (uint8)(1u<<6u);
		}
		else
		{
			UF0CTL0 &=(uint8)(~ (uint8)(1u<<6u));
		}

		if(u8RecEnable !=0u)
		{
			UF0CTL0 |= (uint8)(1u<<5u);
		}
		else
		{
			UF0CTL0 &=(uint8)(~ (uint8)(1u<<5u));
		}
	}
	else
	{
		if(u8SendEnable !=0u)
		{
			UF1CTL0 |= (uint8)(1u<<6u);
		}
		else
		{
			UF1CTL0 &=(uint8)(~ (uint8)(1u<<6u));
		}

		if(u8RecEnable !=0u)
		{
			UF1CTL0 |= (uint8)(1u<<5u);
		}
		else
		{
			UF1CTL0 &=(uint8)(~ (uint8)(1u<<5u));
		}
	}

	return u16RetVal;
}


/*****************************************************************************
 Function  : MCU_vLinUartIsr_Tx												 
 Description   :LIN UART model Tx interrupt
 
 In Parameter: 
 			u16channel: channel ID, 
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vLinUartIsr_Tx(uint16 u16channel)
{
	uint8 u8Err,u8Data;
	uint16 u16Lenth;
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(((u16channel==MCU_mSerial_ID_UARTF0 )||(u16channel==MCU_mSerial_ID_UARTF1 )), DET_Err_LinUartIDOutOfRange);

	/*mirror to internal ID*/
	if(u16channel==MCU_mSerial_ID_UARTF1)
	{
		u16channel=1u;
	}
	else
	{
		u16channel=0u;
	}
	
	if(u16channel == 0u)
	{
		u8Err=(uint8)(UF0STR & 0x07U);
		MCU_stLinUartRunStatus[0u].u16Error=(uint16)u8Err;
		UF0STC |=7u;/*clear error bit*/
	}
	else
	{
		u8Err=(uint8)(UF1STR & 0x07U);
		MCU_stLinUartRunStatus[1u].u16Error=(uint16)u8Err;
		UF1STC |=7u;/*clear error bit*/
	}
	
	/*send finish, index add first!*/
	MCU_stLinUartRunStatus[u16channel].u16WorkingDataLen++;
	u16Lenth=MCU_stLinUartRunStatus[u16channel].u16WorkingDataLen;
	
	if(u16Lenth>= MCU_stLinUartRunStatus[u16channel].u16TottalDataLen)
	{
		/*send finish, then set the status to ready*/
		MCU_stLinUartRunStatus[u16channel].u16TottalDataLen =MCU_mUARTReadyDefValue;
		
		if(MCU_stLinUartRunStatus[u16channel].u16Error!=0u)
		{
			/*error happen, need call err_CB before call finish_CB*/
			MCU_stSerialUartUsrCfg.vu16ErrCallBack(MCU_stLinUartRunStatus[u16channel].u16Error);
			MCU_stLinUartRunStatus[u16channel].u16Error=0u;/*clear record!*/
		}
		
		/*send finish, then call finish_CB*/
		MCU_stSerialUartUsrCfg.vpSendFinish();
	}
	else
	{
		/*send data not finish, then send next byte continue*/
		u8Data= MCU_stLinUartRunStatus[u16channel].pu8DataHead[u16Lenth];
		if(u16channel == 0u)
		{
			UF0TXB =u8Data;
		}
		else
		{
			UF1TXB = u8Data;
		}
	}
}

/*****************************************************************************
 Function  : MCU_vLinUartIsr_Rx												 
 Description   :LIN UART model Rx interrupt
 
 In Parameter: 
 			u16channel: channel ID, 
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vLinUartIsr_Rx(uint16 u16channel)
{
	uint8 u8Err=0u;
	uint8 u8data;
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(((u16channel==MCU_mSerial_ID_UARTF0 )||(u16channel==MCU_mSerial_ID_UARTF1 )), DET_Err_LinUartIDOutOfRange);

	/*mirror to internal ID*/
	if(u16channel==MCU_mSerial_ID_UARTF1)
	{
		u16channel=1u;
	}
	else 
	{
		u16channel=0u;
	}

	if(u16channel == 0u)
	{
		u8data=UF0RXB;
		u8Err=(uint8)(UF0STR & 0x07U);
		UF0STC |=7u;/*clear error bit*/

		if(u8Err !=0u)
		{
			MCU_stLinUartUsrCfg[0u].vu16ErrCallBack((uint16)u8Err);
		}
		
		MCU_stLinUartUsrCfg[0u].vu8RecCallBack(u8data);
		

	}
	else if(u16channel == 1u)
	{
		u8data=UF1RXB;
		u8Err=(uint8)(UF1STR & 0x07U);
		UF1STC |=7u;/*clear error bit*/

		if(u8Err !=0u)
		{
			MCU_stLinUartUsrCfg[1u].vu16ErrCallBack((uint16)u8Err);
		}
		
		MCU_stLinUartUsrCfg[1u].vu8RecCallBack(u8data);

	}	
	else
	{
		DET_ErrReport(DET_Err_UARTIDOutOfRange);
	}
	
}

#if MCU_mLinUart_DeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vSerialUartDeint												 
 Description   :clean UART model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vLinUart_Deinit(void)
{	
	/*interrupt disable*/
	MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_RX[0u] , 0u);
	MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_TX[0u] , 0u);
	MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_RX[1u] , 0u);
	MCU_u16InterruptCtrl(MCU_stResourceLinUart.u16VectorNumber_TX[1u] , 0u);
	
	MCU_stLinUartRunStatus[0u].u16TottalDataLen =0u;
	MCU_stLinUartRunStatus[1u].u16TottalDataLen =0u;

	PER0 &=~(uint8)(3u<<5u);		/*serial group clock supply disable*/	
}

#endif

#endif/*end of LIN-UART module*/

#if ((MCU_mLinUart_modelEnable!=0u) ||(MCU_mSerialUartmodelEnable !=0u))
/*****************************************************************************
 Function  : MCU_u16UARTsend												 
 Description   :Lin-UART or Serial UART send data control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _78K0R.h
 			pu8DataHead: need send data head 
 			u16SendLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			it will control all type of uart to send data 
*****************************************************************************/
uint16 MCU_u16UARTsend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	#if MCU_mSerialUartmodelEnable !=0u
		/*send data in serial-UART*/
		if(u16channel == MCU_mSerial_ID_UART2)
		{
			u16RetVal=MCU_u16SerialUartSend(u16channel, pu8DataHead, u16SendLen);
		}
		else
	#endif
	#if MCU_mLinUart_modelEnable!=0u
		/*send data in LIN-UART*/
		{
			u16RetVal=MCU_u16LinUartSend(u16channel, pu8DataHead, u16SendLen);
		}
		
	#endif
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16UartCtrl												 
 Description   :Lin-UART or Serial UART send/receive enable control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _78K0R.h
 			u8SendEnable: send enable or not
 			u8RecEnable: receive enable or not
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16UARTctrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	#if MCU_mSerialUartmodelEnable !=0u
		/*send data in serial-UART*/
		if(u16channel == MCU_mSerial_ID_UART2)
		{
			u16RetVal=MCU_u16SerialUartCtrl(u16channel, u8SendEnable, u8RecEnable);
		}
		else
	#endif
	
	#if MCU_mLinUart_modelEnable!=0u
		/*send data in LIN-UART*/
		{
			u16RetVal=MCU_u16LinUartCtrl(u16channel, u8SendEnable, u8RecEnable);
		}
		
	#endif
	
	return u16RetVal;
}


#endif


#if MCU_mIICmodelEnable!=0u
/*****************************************************************************
 Function  : MCU_u16IICinit												 
 Description   :IIC model initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function execute before system-mailoop
*****************************************************************************/
static void MCU_vIICinit(void)
{
	uint16 u16SPS=0x0004u;/*CLK1=16M,CLK0=1M defalut*/
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*IIC config using*/
	if(MCU_stI2CUsrCfg[0u].u16TansferSpeed !=0u)
	{
		/*check resource mount or not!!*/
		DET_ErrCheck((uint16)(MCU_stResourceSerial.u16IICmount & (uint16)(1u<<3u )) !=0u, DET_Err_SerialTypeOutOfRange);

		/*check resource in using or not!!*/
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_IIC11]==SerialType_NULL, DET_Err_SerialInUsing);

		PER0 |= (uint8)(1u<<4u);		/*serial group clock supply*/	
		
		/*interrupt enable in default*/
		MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[3u], 1u);

		/*Pin Select for IIC 11*/
		STSEL |= (uint8)(1u<<5u);
		
		SPS1 = u16SPS;
		
		/*Record Serial type for proccess!*/
		MCU_au8SerialUsingType[MCU_mSerial_ID_IIC11]=SerialType_IIC;
		
		SDR11 = MCU_stI2CUsrCfg[0u].u16TansferSpeed;
		SMR11=Serial_IIC;
		SCR11=ScrMap(0u,0u,0u,0u,0u,1u,7u);

		SO1 |=0x0202u;
		
	}

	/*IIC config using*/
	if(MCU_stI2CUsrCfg[1u].u16TansferSpeed !=0u)
	{
		/*check resource mount or not!!*/
		DET_ErrCheck((uint16)(MCU_stResourceSerial.u16IICmount & (uint16)(1u<<4u )) !=0u, DET_Err_SerialTypeOutOfRange);

		/*check resource in using or not!!*/
		DET_ErrCheck(MCU_au8SerialUsingType[MCU_mSerial_ID_IIC20]==SerialType_NULL, DET_Err_SerialInUsing);

		PER1 |= (uint8)(1u<<3u);		/*serial group clock supply*/	
		
		/*interrupt enable in default*/
		MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[4u], 1u);

		SPS2 = u16SPS;
		
		/*Record Serial type for proccess!*/
		MCU_au8SerialUsingType[MCU_mSerial_ID_IIC20]=SerialType_IIC;
		
		SDR20 = MCU_stI2CUsrCfg[1u].u16TansferSpeed;
		SMR20=Serial_IIC;
		SCR20=ScrMap(0u,0u,0u,0u,0u,1u,7u);
		
		SO2 |=0x0101u;

	}
	
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterStartCondition												 
 Description   :IIC triger start-condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _78K0R.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterStartCondition(uint8 u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(((u8I2C_masterID ==MCU_mSerial_ID_IIC20)  || (u8I2C_masterID==MCU_mSerial_ID_IIC11)),DET_Err_IICIDOutOfRange);
	DET_ErrCheck((uint16)(MCU_stResourceSerial.u16IICmount & (1Ul<<u8I2C_masterID))!=0u, DET_Err_IICNotMounted);

	DET_ErrCheck(MCU_au8SerialUsingType[u8I2C_masterID]==SerialType_IIC, DET_Err_SerialTypeOutOfRange);

	if(u8I2C_masterID ==MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			SO1 &= (uint16)~0x0002u;	/* clear IIC11 SDA */
			SOE1 |= 0x0002u;	/* enable IIC11 out */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO1 &= (uint16)~0x0200u;	/* clear IIC11 SCL */

			SS1 |= 0x0002u;	/* enable IIC11 */
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			SO2 &= (uint16)~0x0001u;	/* clear IIC20 SDA */
			SOE2 |= 0x0001u;	/* enable IIC20 out */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO2 &= (uint16)~0x0100u;	/* clear IIC20 SCL */
			
			SS2 |= 0x0001u;	/* enable IIC20 */
			EI();
			
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
		
	}
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterStopCondition												 
 Description   :IIC triger stop -condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _78K0R.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterStopCondition(uint8 u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(((u8I2C_masterID ==MCU_mSerial_ID_IIC11)  || (u8I2C_masterID==MCU_mSerial_ID_IIC20)),DET_Err_IICIDOutOfRange);
	DET_ErrCheck((MCU_stResourceSerial.u16IICmount & (1ul<<u8I2C_masterID))!=0u, DET_Err_IICNotMounted);

	DET_ErrCheck(MCU_au8SerialUsingType[u8I2C_masterID]==SerialType_IIC, DET_Err_SerialTypeOutOfRange);

	if(u8I2C_masterID ==MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			ST1 |= 0x0002u;	/* disable IIC11 */
			SOE1 &=(uint16) ~0x0002u;	/* disable IIC11 out */
			
			SO1 &= (uint16)~0x0002u;	/* clear IIC11 SDA */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO1 |= 0x0200u;	/* set IIC11 SCL */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO1 |= 0x0002u;	/* set IIC11 SDA */
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			ST2 |= 0x0001u;	/* disable IIC20 */
			SOE2 &= (uint16)~0x0001u;	/* disable IIC20 out */
			
			SO2 &= (uint16)~0x0001u;	/* clear IIC20 SDA */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO2 |= 0x0100u;	/* set IIC20 SCL */
			
			MCU_mSmallDelay(MCU_mIICdealyCount);
			SO2 |= 0x0001u;	/* set IIC20 SDA */
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}

	}
	
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterSend												 
 Description   :IIC master node send out data to the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _78K0R.h
 			u8SalveDevice_index: slave index in this IIC net
 			pDataHead[]: send out data head
 			u16Lenth: send out data tottal lenth
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterSend(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 pDataHead[], uint16 u16Lenth)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u8SalveDevice_index<MCU_mI2CMaxSlaveInOneMaster, DET_Err_IICSlaveIDOutOfRange);

	DET_ErrCheck(MCU_au8SerialUsingType[u8I2C_masterID]==SerialType_IIC, DET_Err_SerialTypeOutOfRange);

	if(u8I2C_masterID == MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			SCR11 &= (uint16)~0xC000u;
			SCR11 |= 0x8000u;	/*send only*/
			EI();
			
			MCU_stIICrunStatus[0u].u16WorkingDataLen=0u;
			MCU_stIICrunStatus[0u].u16TottalDataLen=u16Lenth;
			MCU_stIICrunStatus[0u].u8SlaveChannel=u8SalveDevice_index;
			MCU_stIICrunStatus[0u].pu8DataHead=pDataHead;
			MCU_stIICrunStatus[0u].u8Runmode=SerialSending;/*sending mode*/

			SDR11 =pDataHead[0u];
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else if(u8I2C_masterID == MCU_mSerial_ID_IIC20)
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			SCR20 &= (uint16)~0xC000u;
			SCR20 |= 0x8000u;	/*send only*/
			EI();
			
			MCU_stIICrunStatus[1u].u16WorkingDataLen=0u;
			MCU_stIICrunStatus[1u].u16TottalDataLen=u16Lenth;
			MCU_stIICrunStatus[1u].u8SlaveChannel=u8SalveDevice_index;
			MCU_stIICrunStatus[1u].pu8DataHead=pDataHead;
			MCU_stIICrunStatus[1u].u8Runmode=SerialSending;/*sending mode*/

			SDR20 =pDataHead[0u];
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		DET_ErrReport(DET_Err_IICIDOutOfRange);
	}

	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16IIC_MasterRec												 
 Description   :IIC master node receive data from the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _78K0R.h
 			u8SalveDevice_index: slave index in this IIC net
 			*pDataHead: send out data head
 			u16Lenth: receive data tottal lenth
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterRec(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 *pDataHead, uint16 u16Lenth)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u8SalveDevice_index<MCU_mI2CMaxSlaveInOneMaster, DET_Err_IICSlaveIDOutOfRange);

	DET_ErrCheck(MCU_au8SerialUsingType[u8I2C_masterID]==SerialType_IIC, DET_Err_SerialTypeOutOfRange);

	if(u8I2C_masterID == MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			SCR11 &=(uint16)~0xC000u;
			SCR11 |= 0x4000u;	/*receive only*/
			EI();
			
			MCU_stIICrunStatus[0u].u16WorkingDataLen=0u;
			MCU_stIICrunStatus[0u].u16TottalDataLen=u16Lenth;
			MCU_stIICrunStatus[0u].u8SlaveChannel=u8SalveDevice_index;
			MCU_stIICrunStatus[0u].pu8DataHead=pDataHead;
			MCU_stIICrunStatus[0u].u8Runmode=SerialReceiving;/*sending mode*/

			SDR11 =Serial_Dummy_u8Data;
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else if(u8I2C_masterID == MCU_mSerial_ID_IIC20)
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			SCR20 &= (uint16)~0xC000u;
			SCR20 |= (uint16)0x4000u;	/*receive only*/
			EI();

			MCU_stIICrunStatus[1u].u16WorkingDataLen=0u;
			MCU_stIICrunStatus[1u].u16TottalDataLen=u16Lenth;
			MCU_stIICrunStatus[1u].u8SlaveChannel=u8SalveDevice_index;
			MCU_stIICrunStatus[1u].pu8DataHead=pDataHead;
			MCU_stIICrunStatus[1u].u8Runmode=SerialReceiving;/*sending mode*/

			SDR20 =Serial_Dummy_u8Data;
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		DET_ErrReport(DET_Err_IICIDOutOfRange);
	}

	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_vIICIsr												 
 Description   :IIC model interrupt
 
 In Parameter: 
 			u16Ch: IIC channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vIICIsr(uint16 u16Ch)
{
	uint8 u8SlaveID;
	uint16 u16Lenth=0u,u16Err;
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(MCU_au8SerialUsingType[u16Ch] ==SerialType_IIC, DET_Err_SerialTypeOutOfRange);
	
	if(u16Ch == MCU_mSerial_ID_IIC20)
	{
		u16Ch = 1u;/*mirror to control table list*/
		u16Err=SSR20;
		SIR20=7U;
	}
	else
	{
		u16Ch = 0u;/*mirror to control table list*/
		u16Err=SSR11;
		SIR11=7U;
	}

	if(u16Err !=0u)
	{
		MCU_stIICrunStatus[u16Ch].u8Error=(uint8)u16Err;
	}
	
	u8SlaveID=MCU_stIICrunStatus[u16Ch].u8SlaveChannel;
	u16Lenth=MCU_stIICrunStatus[u16Ch].u16WorkingDataLen;

	/*IIC is running in send mode*/
	if(MCU_stIICrunStatus[u16Ch].u8Runmode == SerialSending)	
	{
		/*send finish, index add first!*/
		MCU_stIICrunStatus[u16Ch].u16WorkingDataLen++;
		u16Lenth++;
		
		if(u16Lenth>= MCU_stIICrunStatus[u16Ch].u16TottalDataLen)
		{
			/*send finish, then set the status to ready*/
			MCU_stIICrunStatus[u16Ch].u8Runmode = SerialReady;
			
			if(MCU_stIICrunStatus[u16Ch].u8Error!=0u)
			{
				/*error happen, need call err_CB before call finish_CB*/
				MCU_stI2CUsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(MCU_stIICrunStatus[u16Ch].u8Error);
				MCU_stIICrunStatus[u16Ch].u8Error=0u;/*clear record!*/
			}
			
			/*send finish, then call finish_CB*/
			MCU_stI2CUsrCfg[u16Ch].stSlaveCB[u8SlaveID].vpSendfinishCB();
		}
		else
		{
			/*send not finish, then continue to send out data! IIC mode defalut is 8bit lenth*/
			if(u16Ch == 0u)
			{
				SDR11L = MCU_stIICrunStatus[0u].pu8DataHead[u16Lenth];
			}
			else
			{
				SDR20L = MCU_stIICrunStatus[1u].pu8DataHead[u16Lenth];
			}
		}
	}	
	/*IIC work in receive mode*/
	else if(MCU_stIICrunStatus[u16Ch].u8Runmode == SerialReceiving)
	{
		/*data receive, store it*/
		if(u16Ch == 0u)
		{
			MCU_stIICrunStatus[0u].pu8DataHead[u16Lenth]=SDR11L;
		}
		else
		{
			MCU_stIICrunStatus[1u].pu8DataHead[u16Lenth]=SDR20L;
		}
	
		/*receive a byte finish, index add first!*/
		MCU_stIICrunStatus[u16Ch].u16WorkingDataLen++;
		u16Lenth++;
		
		if(u16Lenth>= MCU_stIICrunStatus[u16Ch].u16TottalDataLen)
		{
			/*send finish, then set the status to ready*/
			MCU_stIICrunStatus[u16Ch].u8Runmode = SerialReady;
			
			if(MCU_stIICrunStatus[u16Ch].u8Error!=0u)
			{
				/*error happen, need call err_CB before call finish_CB*/
				MCU_stI2CUsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(MCU_stIICrunStatus[u16Ch].u8Error);
				MCU_stIICrunStatus[u16Ch].u8Error=0u;/*clear record!*/
			}
			
			/*receive finish, then call finish_CB*/
			MCU_stI2CUsrCfg[u16Ch].stSlaveCB[u8SlaveID].vpRecFinishCB();
		}
		else
		{
			/*output dummy data for clock supply*/
			if(u16Ch == 0u)
			{
				SDR11L=Serial_Dummy_u8Data;
			}
			else
			{
				SDR20L=Serial_Dummy_u8Data;
			}
		}

	}
	else
	{
		DET_ErrReport(DET_Err_RunModeOutOfRange);
	}

}



/*****************************************************************************
 Function  : MCU_u16IIC_MasterChgToSendMode												 
 Description   :IIC model change to send data mode
 
 In Parameter: 
 			u16Ch: IIC channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterChgToSendMode(uint16 u16Ch)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	if(u16Ch == MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			SCR11 &= (uint16)~0xC000u;
			SCR11 |= 0x8000u;	/*send only*/
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
		
	}
	else if(u16Ch == MCU_mSerial_ID_IIC20)
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			SCR20 &= (uint16)~0xC000u;
			SCR20 |= 0x8000u;	/*send only*/
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		DET_ErrReport(DET_Err_IICIDOutOfRange);
	}

	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterChgToRecMode												 
 Description   :IIC model change to receive data mode
 
 In Parameter: 
 			u16Ch: IIC channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterChgToRecMode(uint16 u16Ch)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	if(u16Ch == MCU_mSerial_ID_IIC11)
	{
		if(MCU_stIICrunStatus[0u].u8Runmode== SerialReady)
		{
			DI();
			SCR11 &=(uint16)~0xC000u;
			SCR11 |= 0x4000u;	/*receive only*/
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
		
	}
	else if(u16Ch == MCU_mSerial_ID_IIC20)
	{
		if(MCU_stIICrunStatus[1u].u8Runmode== SerialReady)
		{
			DI();
			SCR20 &=(uint16)~0xC000u;
			SCR20 |= 0x4000u;	/*receive only*/
			EI();
		}
		else
		{
			u16RetVal=DET_Err_IICIsBusy;
		}
	}
	else
	{
		DET_ErrReport(DET_Err_IICIDOutOfRange);
	}
	
	return u16RetVal;
	
}

#if MCU_mIICdeinitEnable!=0u
/*****************************************************************************
 Function  : MCU_vIICdeinit												 
 Description   :IIC model de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			ALL IIC channel can not be used until MCU reset
*****************************************************************************/
void MCU_vIICdeinit(void)
{

	/*interrupt disable*/
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[3u], 0u);
	MCU_u16InterruptCtrl(MCU_stResourceSerial.u16VectorNumber[4u], 0u);

	MCU_stIICrunStatus[0u].u8Runmode= 0xFFu;
	MCU_stIICrunStatus[1u].u8Runmode= 0xFFu;

	MCU_au8SerialUsingType[MCU_mSerial_ID_IIC11]=0u;
	MCU_au8SerialUsingType[MCU_mSerial_ID_IIC20]=0u;
	
	PER1 &= ~(uint8)(1u<<3u);		/*serial group clock supply*/	
	PER0 &= ~(uint8)(1u<<4u);		/*serial group clock supply*/	

}
#endif

#endif/*end of IIC module*/

#if MCU_mDMAmodelEnable !=0u
/*****************************************************************************
 Function  : MCU_u16DMAinit												 
 Description   :initial the DMA model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			this function execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16DMAinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16Loop;

	uint16 u16VectorNum,u16VectFine,u16FineVect;

 	uint8 u8DMC[4]={0u,0u,0u,0u},u8DSA[4]={0u,0u,0u,0u};
		
	MCU_u16DMAReady=0u;
	for(u16Loop=0u;u16Loop<MCU_mMaxDMAchannelMount;u16Loop++)
	{
		u16VectorNum=MCU_stDMAUsrCfg[u16Loop].u16VectorNum;
		if(u16VectorNum !=0u)
		{
			/*fine the using vector can use DMA or not*/
			for(u16VectFine = 0u; u16VectFine < MCU_mMaxVecTblEnable;u16VectFine++)
			{
				if(u16Loop <=1u)/*CH0_1 control*/
				{
					u16FineVect = MCU_stResourceDMA.au8VectTrigerTbl_CH0_1[u16VectFine];
				}
				else/*CH2_3 control*/
				{
					u16FineVect = MCU_stResourceDMA.au8VectTrigerTbl_CH2_3[u16VectFine];
				}
				/*we fine the vector can be control by DMA, then break!*/
				if(u16FineVect == u16VectorNum)
				{
					break;
				}
			}
			/*vector can not be control by DMA, then report error!*/
			if(u16VectFine >=MCU_mMaxVecTblEnable)
			{
				DET_ErrReport(DET_Err_DMANotMounted);
			}
			
			DET_ErrCheck((MCU_stResourceDMA.u16DMAmountMask & (uint16)(1ul<<u16Loop)) !=0u, DET_Err_DMANotMounted);
			DET_ErrCheck(MCU_stDMAUsrCfg[u16Loop].u16RegsterAddr >= 0xFF00u, DET_Err_DMAAddrOutOfRange);

			/*Important:
				will not interrupt if using the DMA*/
			MCU_u16InterruptCtrl(u16VectorNum, 0u);
			
			/*setting register address*/
			u8DSA[u16Loop]=(uint8)(MCU_stDMAUsrCfg[u16Loop].u16RegsterAddr & 0x00ffu);

			/*Set control vector*/
			u8DMC[u16Loop]=(uint8)u16VectFine;
			
			/*set data direction*/
			if(MCU_stDMAUsrCfg[u16Loop].u8DataDirection !=0u)
			{
				u8DMC[u16Loop] |=(uint8)(1u<<6u);
			}
			
			/*set data unit, byte or word operation*/
			if(MCU_stDMAUsrCfg[u16Loop].u8DataUnitSize !=0u)
			{
				u8DMC[u16Loop] |=(uint8)(1u<<5u);
			}
		}
	}

	if(u8DMC[0U] !=0u)
	{
		DEN0=1U;
		DMAMK0 =0U;
		DMC0=u8DMC[0U] ;
		DSA0 = u8DSA[0U] ;
	}
	
	if(u8DMC[1U] !=0u)
	{
		DEN1=1U;
		DMAMK1 =0U;
		DMC1=u8DMC[1U] ;
		DSA1 = u8DSA[1U] ;
	}
	
	if(u8DMC[2U] !=0u)
	{
		DEN2=1u;
		DMAMK2 =0U;
		DMC2=u8DMC[2U] ;
		DSA2 = u8DSA[2U] ;
	}
	
	if(u8DMC[3U] !=0u)
	{
		DEN3=1U;
		DMAMK3 =0U;
		DMC3=u8DMC[3U] ;
		DSA3 = u8DSA[3U] ;
	}	
	
	return u16RetVal;

 }
 
/*****************************************************************************
 Function  : MCU_u16DMAenable												 
 Description   :enable the DMA channel and wait the start trigger to run
 
 In Parameter: 
 			u8DMAchn: DMA ID list in _78K0R.h

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16DMAenable(uint8 u8DMAchn)
{
	uint16 u16RetVal=DET_Err_NotErr;

	uint16 u16DateLen,u16RamAddr;
		
	DET_ErrCheck(u8DMAchn< MCU_mMaxDMAchannelMount, DET_Err_DMAIDOutOfRange);

	u16DateLen = MCU_stDMAUsrCfg[u8DMAchn].u16DataTattolSize;
	u16RamAddr = MCU_stDMAUsrCfg[u8DMAchn].u16RamAddr;
	
	if(MCU_stDMAUsrCfg[u8DMAchn].u8DataUnitSize !=0u)/*word data*/
	{
		DET_ErrCheck((u16DateLen & 1u )== 0u, DET_Err_DMADataLenOutOfRange);
		DET_ErrCheck((u16RamAddr & 1u )== 0u, DET_Err_DMAAddrOutOfRange);
		
		u16DateLen>>=1u;
	}
	
	DET_ErrCheck((u16DateLen < 1024u), DET_Err_DMADataLenOutOfRange);

	DI();
	if(u8DMAchn == MCU_mDMA_ID_DMA0)
	{
		/*check DMA is busy or not!*/

			DRC0 = 0x80u; 		/*DMA enable*/
			DBC0=u16DateLen;		/*transfer setting*/
			DRA0 = u16RamAddr;
			DRC0 |= 0x01u; 		/*DMA enable transfer*/

			MCU_u16DMAReady |=(uint16)(1U<<0U);

		
	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA1)
	{
			DRC1 = 0x80u; 		/*DMA enable*/
			DBC1=u16DateLen;		/*transfer setting*/
			DRA1 = u16RamAddr;
			DRC1 |= 0x01u; 		/*DMA enable transfer*/
			
			MCU_u16DMAReady |=(uint16)(1U<<1U);
	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA2)
	{
			DRC2 = 0x80u; 		/*DMA enable*/
			DBC2=u16DateLen;		/*transfer setting*/
			DRA2 = u16RamAddr;
			DRC2 |= 0x01u; 		/*DMA enable transfer*/
			
			MCU_u16DMAReady |=(uint16)(1U<<2U);

	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA3)
	{
			DRC3 = 0x80u; 		/*DMA enable*/
			DBC3=u16DateLen;		/*transfer setting*/
			DRA3 = u16RamAddr;
			DRC3 |= 0x01u; 		/*DMA enable transfer*/

			MCU_u16DMAReady |=(uint16)(1U<<3U);
		
	}
	else
	{
		DET_ErrReport(DET_Err_DMAIDOutOfRange);
	}
	EI();
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16DMAStartTrig												 
 Description   :enable the DMA channel run by setting the software_start_trigger,
 			this function always use in condition RAM data to Register such as 
 			serial data send out,
 			serial data receive will trigger by hardware interrupt!!
 
 In Parameter: 
 			u8DMAchn: DMA ID list in _78K0R.h

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16DMAStartTrig(uint8 u8DMAchn)
{
	uint16 u16RetVal=DET_Err_NotErr;
		
	DET_ErrCheck((MCU_u16DMAReady & (uint16)(1ul<<u8DMAchn)) !=0u, DET_Err_DMANotInitial);
	DET_ErrCheck(u8DMAchn< MCU_mMaxDMAchannelMount, DET_Err_DMAIDOutOfRange);

	
	if(u8DMAchn == MCU_mDMA_ID_DMA0)
	{
		/*check DMA is busy or not!*/
		DET_ErrCheck(DST0 ==0U, DET_Err_DMAIsBusy);
		STG0 = 1U; /*Software tigger to start transfer data*/
	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA1)
	{
		/*check DMA is busy or not!*/
		DET_ErrCheck(DST1 ==0U, DET_Err_DMAIsBusy);
		STG1 = 1U; /*Software tigger to start transfer data*/
	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA2)
	{
		/*check DMA is busy or not!*/
		DET_ErrCheck(DST2 ==0U, DET_Err_DMAIsBusy);
		STG2 = 1U; /*Software tigger to start transfer data*/
	}
	else if(u8DMAchn == MCU_mDMA_ID_DMA3)
	{
		/*check DMA is busy or not!*/
		DET_ErrCheck(DST3 ==0U, DET_Err_DMAIsBusy);
		STG3 = 1U; /*Software tigger to start transfer data*/
	}
	else
	{
		DET_ErrReport(DET_Err_DMAIDOutOfRange);
	}

	return u16RetVal;

}

 
/******************************************************

not perform, because DMA is enough to use, not multiple use

void MCU_vDMAconfigerate(uint8 u8DMAchn,uint16 setting)
{
}
************************************************************/


/*****************************************************************************
 Function  : MCU_vDMAIsr												 
 Description   :DMA transfer finish interrupt service
 
 In Parameter: 
 			u16channel: DMA channel ID

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
 void MCU_vDMAIsr(uint16 u16channel)
 {
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u16channel< MCU_mMaxDMAchannelMount, DET_Err_DMAIDOutOfRange);

	if(u16channel == MCU_mDMA_ID_DMA0)
	{
		DEN0 =0u;
		MCU_u16DMAReady &=(uint16)~(uint16)(1U<<0U);

		MCU_stDMAUsrCfg[0u].vpINTservice();
	}
	else  if(u16channel == MCU_mDMA_ID_DMA1)
	{
		DEN1 =0u;
		MCU_u16DMAReady &=(uint16)~(uint16)(1U<<1U);
		
		MCU_stDMAUsrCfg[1u].vpINTservice();
	}
	else if(u16channel == MCU_mDMA_ID_DMA2)
	{
		DEN2 =0u;
		MCU_u16DMAReady &=(uint16)~(uint16)(1U<<2U);
		
		MCU_stDMAUsrCfg[2u].vpINTservice();
	}
	else if(u16channel == MCU_mDMA_ID_DMA3)
	{
		DEN3 =0u;
		MCU_u16DMAReady &=(uint16)~(uint16)(1U<<3U);
		
		MCU_stDMAUsrCfg[3u].vpINTservice();
	}
	else 
	{
		DET_ErrReport(DET_Err_DMAIDOutOfRange);
	}
	
 }
 
 #if MCU_mDMADeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vDMADeInit												 
 Description   :clean the DMA model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
 void MCU_vDMADeInit(void)
 {
	MCU_u16DMAReady=0u;

	DRC0 = 0U;
	DRC1 = 0U;
	DRC2 = 0U;
	DRC3 = 0U;
	
	DMAMK0 =1U;
	DMAMK1 =1U;
	DMAMK2 =1U;
	DMAMK3 =1U;

 }
#endif

#endif /*end of DMA Module*/

/*****************************************************************************
 Function  : MCU_vOscInit												 
 Description   :OSC MCU_vOscInit
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in asm in this serial chip
*****************************************************************************/
static void MCU_vOscInit(void)
{

	#if MCU_mSwitchToInternalOSC !=0u
	
		/*if OSC is normal, then using the external OSC*/
		if((uint8)(RESF & 4u) ==0u)
		{
			MCU_u8UsingOSC=0u;
			MCU_vExtOscInit();
		}
		/*if OSC fail and cause the reset, then using the internal OSC instand*/
		else
		{
			MCU_u8UsingOSC=1u;
			MCU_vInternalOscInit();
		}
	
	#else
	
		MCU_u8UsingOSC=0u;
		MCU_vExtOscInit();
	
	#endif
	
	
}

#if MCU_mSwitchToInternalOSC !=0u
/*****************************************************************************
 Function  : MCU_vInternalOscInit												 
 Description   :internal OSC using only when external OSC fail
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vInternalOscInit(void)
{
	uint16 i;
	uint8 temp_stabset, temp_stabwait;
	
	/* Set fMX */
	CMC = 0u;
	GUARD |= (uint8)1u;
	
	HIOSTOP=0U;
	MSTOP = 0U;
	/* Main OSC keep running -->
	WARNNING::::::::::it should be stop if Error happend but CAN module always using this!! 
	MSTOP = 0U;
	temp_stabset = MCU_mOSCwaitCount;
	do
	{
		temp_stabwait = OSTC;
		temp_stabwait &= temp_stabset;
	}
	while (temp_stabwait != temp_stabset);-->it may can not counter fX bacause MainOSC not work!!*/
	
	/* Set clock using Interrnal OSC */
	MCM0 = 0U;
	/* Set fPLL */
	GUARD |= (uint8)2u;
	#if MCU_mExternOSC_Frequency==4000000UL
	PLLCTL = 0x60u;
	#elif MCU_mExternOSC_Frequency==8000000UL
	PLLCTL = 0x70u;
	#else
	#error "MCU_mExternOSC_Frequency setting is not correct!!"
	#endif

	PLLON = 1U;
	/* Software wait 100us or more */
	for( i=0U; i<=2400u; i++ )
	{
		NOP();
	}
	while (LOCK != 1U)
	{
		;
	}
	SELPLL = 1U;
	while (SELPLLS != 1U)
	{
		;
	}
	GUARD &= (uint8)~2u;
	/* Set fSUB */
	XTSTOP = 1U;
	/* Set fCLK */
	/*DI()*/
	OSMC = 1u;
	NOP();
	NOP();
	/*EI()*/
	CSS = 0U;
	CKC &= (uint8)~7u;
	CKC |= (uint8)0u;
	/* Set fIH */
	HIOSTOP = 0U;
	GUARD &= (uint8)~1u;
	
}
#endif

/*****************************************************************************
 Function  : MCU_vExtOscInit												 
 Description   :external OSC using when power on an OSC is normal
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vExtOscInit(void)
{
	uint16 i;
	uint8 temp_stabset, temp_stabwait;
	uint8 ClkTimeTbl[8u]={0x80U,0xC0U,0xE0U,0xF0U,0xF8U,0xFCU,0xFEU,0xFFU};
	
	/* Set fMX */
	#if MCU_mExternOSC_Frequency >=2000000UL && MCU_mExternOSC_Frequency<=10000000UL
	CMC =0x40u;
	#elif MCU_mExternOSC_Frequency >10000000UL && MCU_mExternOSC_Frequency<=20000000UL
	CMC =0x41u;
	#else
	#error "the external physical OSC clock is out of range!!"
	#endif
	OSTS = MCU_mOSCwaitCount;
	GUARD |= (uint8)1u;
	MSTOP = 0U;
	temp_stabset = ClkTimeTbl[MCU_mOSCwaitCount];
	do
	{
		temp_stabwait = OSTC;
		temp_stabwait &= temp_stabset;
	}
	while (temp_stabwait != temp_stabset);
	/* Set fMAIN */
	MCM0 = 1U;
	/* Set fPLL */
	GUARD |= (uint8)0x02u;
	#if MCU_mExternOSC_Frequency==4000000UL
	PLLCTL = 0x60u;
	#elif MCU_mExternOSC_Frequency==8000000UL
	PLLCTL = 0x70u;
	#else
	#error "MCU_mExternOSC_Frequency setting is not correct!!"
	#endif
	PLLON = 1U;
	/* Software wait 100us or more */
	for( i=0U; i<=2400u; i++ )
	{
		NOP();
	}
	while (LOCK != 1U)
	{
		;
	}
	SELPLL = 1U;
	while (SELPLLS != 1U)
	{
		;
	}
	GUARD &= (uint8)~0x02u;
	/* Set fSUB */
	XTSTOP = 1U;
	/* Set fCLK */
	/*DI()*/
	OSMC = 1u;
	NOP();
	NOP();
	/*EI()*/
	CSS = 0U;
	CKC &= (uint8)~7u;
	CKC |= (uint8)0u;
	/* Set fIH -stop internal-high-speed-osc*/
	HIOSTOP = 1U;
	GUARD &= (uint8)~1u;
	
}

/*****************************************************************************
 Function  : MCU_vClockInit												 
 Description   :CPU and peripheral clock initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in asm in this serial chip
*****************************************************************************/
static void MCU_vClockInit(void)
{

}

/*****************************************************************************
 Function  : MCU_vWatchDogInit												 
 Description   :internal software watchdog setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in option byte
*****************************************************************************/
static void MCU_vWatchDogInit(void)
{

}

/*****************************************************************************
 Function  : MCU_vWatchDogClean												 
 Description   :clean internal software watchdog counter
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in asm in this serial chip
*****************************************************************************/
void MCU_vWatchDogClean(void)
{
	 WDTE = 0xACu;		/* restart watch dog timer */
}

/*****************************************************************************
 Function  : MCU_vLowVoltDetectInit												 
 Description   :Low voltage detect setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it will while(1){MCU Reset} after call this function if the 5V supply is below the lowest voltage

LVIS setting and detect voltage value!

	0 0 0 0 	VLVI0 	(4.22 ¡À0.1 V)
	0 0 0 1 	VLVI1 	(4.07 ¡À0.1 V)
	0 0 1 0 	VLVI2 	(3.92 ¡À0.1 V)
	0 0 1 1 	VLVI3 	(3.76 ¡À0.1 V)
	0 1 0 0 	VLVI4 	(3.61 ¡À0.1 V)
       [0 1 0 1] 	VLVI5 	(3.45 ¡À0.1 V) default
	0 1 1 0 	VLVI6 	(3.30 ¡À0.1 V)
	0 1 1 1 	VLVI7 	(3.15 ¡À0.1 V)
	1 0 0 0 	VLVI8 	(2.99 ¡À0.1 V)
	1 0 0 1 	VLVI9 	(2.84 ¡À0.1 V)

	Other than above Setting prohibited
	
*****************************************************************************/
static void MCU_vLowVoltDetectInit(void)
{
	uint8 u8i;
	
	GUARD |= (uint8)2u;	/*register write protect open*/
	
#if MCU_mLVIlevelSetting != MCU_mLVIDisable
	
	LVIMK = 1u; 	/*can not interrupt*/
	LVISEL  = 0u;	/*monitor the VDD voltage*/
	LVIS = MCU_mLVIlevelSetting; 	/*set LVI voltage level*/

	LVION = 1u;	/*voltage detcet starting*/
	
	/* Wait time >= 250 us */	
	for( u8i=0U; u8i<255u; u8i++ )
	{	
		NOP();
	}
	
	/*Low voltage is detceted, 
	so suspend here until voltage is OK	*/
	while(LVIF == 1u) 
	{
		NOP();
	}

	LVIMD = 1u;	/*after that, it will reset if low voltage datect!!*/
	
#else

	LVION = 0U;
	LVIMK = 1U;
	LVIIF = 0U;
		
#endif

	GUARD &=(uint8)~2u;	/*register write protect close*/
	
}

/*****************************************************************************
 Function  : MCU_vReset												 
 Description   :MCU software reset request, it will reset MCU and re-run from start.asm
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vReset(void)
{
	WDTE = 0x00U;		/* it will reset MCU if the data write to WDTE is NOT 0xAC*/
}

/*****************************************************************************
 Function  : MCU_vNotExpINT												 
 Description   :one of the not-expected interrupt happen if this fucntion run
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt, it will halt system and reset MCU
*****************************************************************************/
void MCU_vNotExpINT(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
        u16RetVal+=1u;/*compiler warning*/
        #if _78K0R_Debug !=0u
	do{}while(1u);
	#endif
}

/*****************************************************************************
 Function  : MCU_vNotExpINT_u8												 
 Description   :one of the not-expected interrupt happen if this fucntion run
 
 In Parameter: 
 			u8Dummy: a dummy data
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt, it will halt system and reset MCU
*****************************************************************************/
void MCU_vNotExpINT_u8(uint8 u8Dummy)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
	u8Dummy=0u;
        u8Dummy+=1u;/*compiler warning*/
        u16RetVal+=1u;/*compiler warning*/
        #if _78K0R_Debug !=0u
	do{}while(1u);
	#endif
}

void MCU_vNotExpINT_u16(uint16 u16Dummy)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
	u16Dummy=0u;
        u16Dummy+=1u;/*compiler warning*/
        u16RetVal+=1u;/*compiler warning*/
	#if _78K0R_Debug !=0u
	do{}while(1u);
	#endif

}

/*****************************************************************************
 Function  : MCU_vNotExpINT_u32_8												 
 Description   :one of the not-expected interrupt happen if this fucntion run
 
 In Parameter: 
 			u32Dummy: a dummy data
 			u8DUMMY: a dummy data
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt, it will halt system and reset MCU
*****************************************************************************/
void MCU_vNotExpINT_u32_8(uint32 u32Dummy,uint8 u8DUMMY)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrReport(DET_Err_NotExpIntterupt);
        u8DUMMY=0u;
	u32Dummy=0ul;
	u8DUMMY+=1u;
	u32Dummy+=1ul;
        u16RetVal+=1u;/*compiler warning*/
        
        #if _78K0R_Debug !=0u
	do{}while(1u);
	#endif

}

/*****************************************************************************
 Function  : MCU_vHWConfigCheck												 
 Description   :check the mainline download the HEX file currectly! it will halt if not
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vHWConfigCheck(void)
{
	/*check MCU option byte is OK or not

	--->for bootloader option byte MUST same as APP option byte<-----
	--->for ROM configuration option MUST selected<-----
	*/
	if(
		(MCU_au8OptionByteSetting[0u] != MCU_mOptByte0) ||
		(MCU_au8OptionByteSetting[1u] != MCU_mOptByte1) ||
		(MCU_au8OptionByteSetting[2u] != MCU_mOptByte2) ||
		(MCU_au8OptionByteSetting[3u] != MCU_mOptByte3) 
	)
	{
		while(1u)
		{
			/*key option not correct, need shut down to modify!!!*/
			;
		}
	}
}


/*****************************************************************************
 Function  : MCU_u16RunModeCtrl												 
 Description   :MCU running mode control, to enter normal-mode, standby-mode, halt-mode ect
 
 In Parameter: 
 			u8ExpMode :MCU expected running mode 

						0: Halt mode =>
						
							the CPU operation clock 						--->stopped. 
							
							 the highspeed system clock oscillator, 			--->running
							 internal high-speed oscillator, 				--->running
							 internal low-speed oscillator  clock continues.	--->running
														
						1: Stop mode =>
						
							the CPU operation clock						 --->stopped. 

							 the highspeed system clock oscillator			--->stopped. 
							 internal high-speed oscillator					--->stopped. 
							 internal low-speed oscillator  clock continues	--->stopped. 
							 
Return Value:

			NULL
 			
 NOTE: 		
 
			CPU will not excute next commond until wake up!
		
*****************************************************************************/
uint16 MCU_u16RunModeCtrl(uint8 u8ExpMode)
{
	uint16 u16RetVal=DET_Err_NotErr,u16Wait=2400u;
	uint8 temp_stabset,temp_stabwait;
	
	DET_ErrCheck(u8ExpMode <= 2u, DET_Err_RunModeOutOfRange);

	if(u8ExpMode == MCU_mRunMode_Halt)
	{
		/*EI()-->do it is HALT macro*/
		HALT();
		
		/*MCU is wake up if it run here!!!!*/
		
	}
	else
	{

		/*EI()-->do it is STOP macro*/
		STOP();

		if(MCU_u8UsingOSC== 0u)
		{
			/*MCU is wake up if it run here,
			need wait OSC stable if wake up from stop_mode!!!!*/
			temp_stabset = MCU_mOSCwaitCount;
			do
			{
				temp_stabwait = OSTC;
				temp_stabwait &= temp_stabset;
			}
			while (temp_stabwait != temp_stabset);
		}
		else
		{
			while(u16Wait--)
			{
				/*small delay to wait internal OSC stable*/
				;
			}
		}

	}
	
	return u16RetVal;
}


/*****************************************************************************
 Function  : __low_level_init												 
 Description   :MCU low level init, this function called by _78K0R_start.s26 file and run before main()
 			to initialiaztion the base hardware before C-pragma (main function entry)
 
 In Parameter: 
 			NULL
 			
Return Value:
 			always 1
 			if the return value is 0, MCU will not initial other RAM data, and it is wrong!!!
 			
 NOTE: 		
 			NULL
*****************************************************************************/
int __low_level_init(void)
{
	DI();
	MCU_vOscInit();
	MCU_vClockInit();
	MCU_vWatchDogInit();
	MCU_vLowVoltDetectInit();
	MCU_vHWConfigCheck();
	
	return 1;/*return value must 1!*/
}

/********************************
	Import external APP layer interface
*********************************/

#if (_78K0R_Debug !=0u)
	extern void MCU_vDebugMain(void);
#else
	extern void SYS_vMainLoop(void);
	extern void SYS_vPeripheralInit(void);
	
#endif

/*****************************************************************************
 Function  : main												 
 Description   : C pragma entry pionte, it will nerver return back
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			
		YES! I AM  AN AMAZING  BUG  AS YOU!
				_
			       :   `                     _..-=-=-=-.._.--.
			        `-._ ___,..-'" -~~`	~~~~  ~ >__')
			            `'"---'"`>>"'~~"~"~~>>'`
=====================```========```======== 

*****************************************************************************/
void main(void)
{
	
	#if MCU_mPortModeEnable !=0u
  	MCU_vPortInit();
	#endif
		
	#if MCU_mPPGModeEnable!=0u
	MCU_u16PPGinit();
	#endif
	
	#if MCU_mICUmodelEnable!=0u
	MCU_u16ICUinit();
	#endif
	
	#if MCU_mADCModelEnable!=0u
	MCU_u16ADCinit();
	#endif
	
	#if MCU_mEINTModelEnable!=0u
	MCU_u16EINTinit();
	#endif
	
	#if MCU_mSerialUartmodelEnable!=0u
	MCU_vSerialUartInit();
	#endif

	#if MCU_mIICmodelEnable!=0u
	MCU_vIICinit();
	#endif

	#if MCU_mCSImodelEnable!=0u
	MCU_vCSIinit();
	#endif
	
	#if MCU_mLinUart_modelEnable !=0u
  	MCU_vLinUart_Init();
  	#endif
  	
	#if MCU_mTimerModelEnable!=0u
	MCU_u16TimerArrayInit();
	#endif

	#if MCU_mDMAmodelEnable !=0u
	MCU_u16DMAinit();
	#endif	

#if (_78K0R_Debug !=0u)
	EI_Force();
	MCU_vDebugMain();
#else

	SYS_vPeripheralInit();
	
	EI_Force();
	SYS_vMainLoop();
#endif

	EI();
	MCU_vReset();
	
}

#endif/*end of this file*/

