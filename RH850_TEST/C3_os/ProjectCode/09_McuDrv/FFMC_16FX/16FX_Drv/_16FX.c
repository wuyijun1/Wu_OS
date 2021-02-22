/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial
| File Name: _16FX.c
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
| 2015.11.28  V0.02	Tan, fumin	1,fix LCD initialization BUG in funcition MCU_vLCDinit()
| 2016.06.20  V0.03	Tan, fumin	add LVI disable configeration option!
********************************************************************************/

#ifdef MCU_C
/*This file ONLY include in MCU.c for compiler*/

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
				refer the extern configeration data of Re-Load timer
			###################################################*/
			extern const MCU_tstResourceMount_ReloadTimer MCU_stResourceReLoadTimer;
			extern const MCU_tstReloadTimerUserCfg	MCU_stReloadTimerUsrCfg[MCU_mMaxReLoadTimerMount];

			/*reload timer initial status record*/
			static uint16 MCU_au16ReLoadTimerInit[1u]={0u};

			/*reload timer running status record*/
			static uint16 MCU_au16ReLoadTimerRun[1u]={0u};

			static uint16 MCU_u16ReLoadTimerInit(void);
			
			void MCU_vTimerIsr(uint16 u16timerID);
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
			uint8 MCU_u8ADCchannelCtrl=0u;

			/*ADC resault buffer*/
			#if MCU_mDMAforADCEnable !=0u
			__far uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount]={0u};
			#else
			uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount]={0u};
			#endif
	
			static uint16 MCU_u16ADCinit(void);

			
#endif

#if MCU_mPPGModeEnable!=0u

			/*##################################################
				refer the extern configeration data of PPG
			###################################################*/
			extern const MCU_tstResourceMount_PPG  MCU_stResourcePPG;
			extern const MCU_tstPPGCfg MCU_stPPGUsrCfg[MCU_mMaxPPGchannelMount];

			/*PPG register group header, it is not continuelity*/
			/*uint16 reigster bit lenth, array by: PCSR,PDUT,PCN, but the EPCN is continuelity*/
			static const uint16 MCU_au16PPGAddrHead[MCU_mMaxPPGchannelMount]=
			/*PPG	0		1		2		3		4		5		6		7	*/
			{		0x007Au,	0x0082u,	0x008Au,	0x0092u,	0x009Eu,	0x00A6u,	0x0566u,	0x056Eu,
			/*PPG	8		9		10		11		12		13		14		15	*/
					0x057Au,	0x582u,	0x58Au,	0x0592u,	0x059Eu,	0x05A6u,	0x05AEu,	0x05B6u};
					
					
			/*PPG channel status record, 1bit is one channel initialization*/		
			static uint16 MCU_au16PPGStatus[1u]={0u};

			
			static uint16 MCU_u16PPGInit(void);

#endif



#if MCU_mUARTmodelEnable!=0u

		/*##################################################
			refer the extern configeration data of UART
		###################################################*/
		extern const MCU_tstResourceMnt_UART MCU_stResourceUART;
		extern const MCU_tstUARTCfg MCU_stUARTUsrCfg[MCU_mMaxUARTchannelMount];
		
		/*UART register group header, it is not continuelity*/
		/*uint16 reigster bit lenth, array by: SMR,SCR,T/RDR,SSR,ECCR,ESCR,BGR, but the EPCN is continuelity*/
		const uint16 MCU_au16UARTAddrHead[MCU_mMaxUARTchannelMount]=
		/*UART	0		1		2		3		4		5		6		7	*/
		{		0x00C0u,	0x00CAu,	0x00D4u,	0x00DEu,	0x0520u,	0x052Au,	0x0534u,	0x053Eu};

		/*UART send lenth record for every channel*/
		uint16 MCU_u16UARTsendLenth[MCU_mMaxUARTchannelMount]={0u};

		/*UART initial status record*/
		static uint16 MCU_u16UARTStatus_Init=0u;

		/*UART running status record*/
		MCU_tstUARTCtrl MCU_stUARTStatus_Ctrl[MCU_mMaxUARTchannelMount]={0u};
		
		static uint16 MCU_u16UARTinit(void);

		void MCU_vUARTIsr_Rx(uint8 u8channel);
		void MCU_vUARTIsr_Tx(uint8 u8channel);
#endif

#if MCU_mICUmodelEnable!=0u

			/*##################################################
				refer the extern configeration data of ICU
			###################################################*/
			extern const MCU_tstResourceMnt_ICU MCU_stResourceICU;
			extern const MCU_tstICUCfg MCU_stICUUsrCfg[MCU_mMaxICUchannelMount];

			/*Free-Run-Timer Over Flowe record: waring: only use 2 FRT, if more than two, it will be wrong*/
			uint8 MCU_au8FRT_OVcnt[2u]={0u};

			/*ICU initial status record*/
			uint8 MCU_u8ICUStatus_Init=0u;

			/*ICU running status record*/
			static uint8 MCU_u8ICUStatus=0u;

			/*ICU timer counter record buffer for calc real pulse timer*/
			static uint16 MCU_au16ICULastCnt[MCU_mMaxICUchannelMount]={0u};
			static uint8 MCU_au8ICULastOVcnt[MCU_mMaxICUchannelMount]={0u};

			static uint16 MCU_u16ICUinit(void);
			
			void MCU_vICUIsr(uint8 u8ICUid);
#endif

#if MCU_mIICmodelEnable !=0u

		/*##################################################
			refer the extern configeration data of IIC
		###################################################*/
		extern const MCU_tstResourceMnt_IIC MCU_stResourceI2C;
		extern const MCU_tstIICCfg MCU_stI2CUsrCfg[MCU_mMaxIICMount];
		
		/*IIC status control*/
		MCU_tstIICctrl MCU_stIICStatus={0u};
		
		static uint16 MCU_u16IICinit(void);
		void MCU_vIICIsr(uint8 u8Channel);
#endif


#if MCU_mDMAmodelEnable !=0u

		/*##################################################
			refer the extern configeration data of DMA
		###################################################*/
		extern const MCU_tstResourceMnt_DMA MCU_stResourceDMA;
		extern const MCU_tstDMACfg MCU_stDMAUsrCfg[MCU_mMaxDMAchannelMount];
		
		static uint8 MCU_u8DMAsetting[MCU_mMaxDMAchannelMount]={0u};
		/*DMA initial status record*/
		static uint16 MCU_u16DMAStatus_Init=0u;
		
		static uint16 MCU_u16DMAinit(void);
#endif

#if MCU_mLCDmodelEnable!=0u

		/*##################################################
			refer the extern configeration data of LCD
		###################################################*/
		extern const MCU_tstResourceMnt_LCD MCU_stResourceLCD;
		extern const MCU_tstLCDCfg MCU_stLCDUsrCfg;
		
		/*LCD initial status record*/
		static uint8 MCU_vLCDStatus_Init=0u;
		
		static void MCU_vLCDinit(void);
#endif

static void MCU_vOscInit(void);
static void MCU_vClockInit(void);
static void MCU_vWatchDogInit(void);
static void MCU_vLowVoltDetectInit(void);
static void MCU_vHWConfigCheck(void);

#if MCU_mPortModeEnable!=0u

#if MCU_mPinDataOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinRead												 
 Description   : Read out hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
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
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstPDR));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstDDR *pDirect;
	volatile MCU_tstPDR *pData;

	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstDDR *)u16Address;
	
	u16Address=MCU_mRegisterHead_PortData;
	u16Address+=u16IndexOffset;
	pData=(volatile MCU_tstPDR *)u16Address;

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
	*u8PinValue=(((uint8)(pData->byte) & u8MaskValue) ==0u) ? 0u : 1u;
	
	/*return the operation resault*/
	return u16RetVal;
}


/*****************************************************************************
 Function  : MCU_u16PinWrite												 
 Description   : write the hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
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
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstPDR));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstDDR 	*pDirect;
	volatile MCU_tstPDR 	*pData;
	
	/*read back the pin status to check wrtie successful or not*/
	#if MCU_mPinWriteResaultChkEnable!=0u
	volatile EPSR00STR *pPinStatus;
	
	u16Address=MCU_mRegisterHead_PinStatus;
	u16Address+=u16IndexOffset;
	pPinStatus=(volatile EPSR00STR *)u16Address;
	#endif
	
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstDDR *)u16Address;
	
	u16Address=MCU_mRegisterHead_PortData;
	u16Address+=u16IndexOffset;
	pData=(volatile MCU_tstPDR *)u16Address;
	

	
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
	
	if(u8Value != 0u)
	{
		/*update the data to pin*/
		pData->byte |=u8MaskValue;
		
		/*read back the pin status to check wrtie successful or not*/
		#if MCU_mPinWriteResaultChkEnable!=0u
		DET_ErrCheck(((pPinStatus->byte & u8MaskValue) == u8MaskValue), DET_Err_WritePinValueFail);
		#endif
	}
	else
	{
		/*update the data to pin*/
		pData->byte &=(uint8)~u8MaskValue;
		
		/*read back the pin status to check wrtie successful or not*/
		#if MCU_mPinWriteResaultChkEnable!=0u
		DET_ErrCheck(((pPinStatus->byte & u8MaskValue) == 0U), DET_Err_WritePinValueFail);
		#endif
	}

	/*return the operation resault*/
	return u16RetVal;
}

#endif

#if MCU_mPinDirectOperEnable !=0u
/*****************************************************************************
 Function  : MCU_u16PinDirectCfg												 
 Description   : write the hardware Pin direction
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
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
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstDDR));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;

	volatile MCU_tstDDR *pDirect;
        
	u16PinListIndex++;/*compiler warning*/
        
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortDirect;
	u16Address+=u16IndexOffset;
	pDirect=(volatile MCU_tstDDR *)u16Address;

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
	
	/*return the operation resault*/
	return u16RetVal;

}
#endif

#if MCU_mPinPullUpOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinPullUpCfg												 
 Description   : write the hardware Pin pull-up configeration
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
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
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstPUCR));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;

	volatile MCU_tstPUCR *pPullUp;
	
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortPullUp;
	u16Address+=u16IndexOffset;
	pPullUp=(volatile MCU_tstPUCR *)u16Address;
	
	
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

	return u16RetVal;
}
#endif

#if MCU_mPinPullDownOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinPullDownCfg												 
 Description   : write the hardware Pin pull-down configeration
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
 			u8OnOff : value of pin pull-down to write
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinPullDownCfg(uint16 u16PinID,uint8 u8OnOff)
{
	uint8 u8MaskValue;
	
	uint16 u16PinListIndex=0u;	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstPDCR));
	uint16 u16RetVal=DET_Err_NotErr;

	uint32 u32Address;
	
	volatile __far MCU_tstPDCR *pPullDown;
	
	/*relation register pionter*/
	u32Address=MCU_mRegisterHead_PortPullDown;
	u32Address+=u16IndexOffset;
	pPullDown=(volatile __far MCU_tstPDCR *)u32Address;

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
	DET_ErrCheck((MCU_stResourcePort.u8PortPullDownMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check pin pull up value changeable or not*/
	DET_ErrCheck((MCU_stPinUserCfg[u16PinListIndex].bitPinPullDownChgable!=0u), DET_Err_CanNotWritePinPullDown);

	if(u8OnOff != 0u)
	{
		/*update the data to pin direction register*/
		pPullDown->byte |=u8MaskValue;
	}
	else
	{
		/*update the data to pin*/
		pPullDown->byte &=(uint8)~u8MaskValue;
	}

	return u16RetVal;
}
#endif

#if MCU_mPinHighDrvOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinHighDrvCfg												 
 Description   : write the hardware Pin High-Drive configeration
 
 In Parameter: 
 			u16PinID: Pin ID list in _16FX.h
 			u8OnOff : value of pin High-Drive to write
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinHighDrvCfg(uint16 u16PinID,uint8 u8OnOff)
{
	uint8 u8MaskValue;
	
	uint16 u16PinListIndex=0u;	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16IndexOffset=u16PortIndex * (uint8)(sizeof(MCU_tstPHDR));
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstPHDR *pHighDrv;
	
	/*relation register pionter*/
	u16Address=MCU_mRegisterHead_PortHighDrv;
	u16Address+=u16IndexOffset;
	pHighDrv=(volatile MCU_tstPHDR *)u16Address;

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
	DET_ErrCheck((MCU_stResourcePort.u8PortHighDrvMask[u16PortIndex] & u8MaskValue) !=0u, DET_Err_ResourceNotMount);
	
	/*check pin pull up value changeable or not*/
	DET_ErrCheck((MCU_stPinUserCfg[u16PinListIndex].bitPinHighDrvChgable!=0u), DET_Err_CanNotWritePinHDvr);

	if(u8OnOff != 0u)
	{
		/*update the data to pin direction register*/
		pHighDrv->byte |=u8MaskValue;
	}
	else
	{
		/*update the data to pin*/
		pHighDrv->byte &=(uint8)~u8MaskValue;
	}

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
	uint32 u32Address;
	
	/*relation register pionter*/
	volatile MCU_tstPHDR *pHighDrv;
	volatile __far MCU_tstPDCR *pPullDown;
	volatile MCU_tstPUCR *pPullUp;
	volatile MCU_tstDDR *pDirect;
	volatile MCU_tstPDR 	*pData;
	volatile MCU_tstPIER *pInputEn;

	for(u8Index=0u;u8Index<MCU_mMaxPortInChip;u8Index++)
	{
		/*update the register addr for this loop---*/
		u16Address=MCU_mRegisterHead_PortData;
		u16Address+=u16IndexOffset;
		pData=(volatile MCU_tstPDR *)u16Address;
		
		u16Address=MCU_mRegisterHead_PortDirect;
		u16Address+=u16IndexOffset;
		pDirect=(volatile MCU_tstDDR *)u16Address;
		
		u16Address=MCU_mRegisterHead_PortPullUp;
		u16Address+=u16IndexOffset;
		pPullUp=(volatile MCU_tstPUCR *)u16Address;
		
		u32Address=MCU_mRegisterHead_PortPullDown;
		u32Address+=u16IndexOffset;
		pPullDown=(volatile __far MCU_tstPDCR *)u32Address;
		
		u16Address=MCU_mRegisterHead_PortInputEn;
		u16Address+=u16IndexOffset;
		pInputEn=(volatile MCU_tstPIER *)u16Address;

		u16Address=MCU_mRegisterHead_PortHighDrv;
		u16Address+=u16IndexOffset;
		pHighDrv=(volatile MCU_tstPHDR *)u16Address;
		
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
			pData->byte = (uint8)(u8FinalData & u8TempData);

			/*update the data to regitser---->enable input switch for all pins*/	
			pInputEn->byte = u8TempData;
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
			pDirect->byte = (uint8)(u8FinalData & u8TempData);	
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
			pPullUp->byte = (uint8)(u8FinalData & u8TempData);
		}

		/*clean the value for this loop*/
		u8FinalData=0u;
		/*find out port initial data in configuration array and update it into port data regitser*/
		u8TempData = MCU_stResourcePort.u8PortPullDownMask[u16IndexOffset];
		if( u8TempData !=0u)
		{
			/*fine the all pin default value in this port*/
			if(MCU_stPinUserCfg[u8PinIndex+0u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=1u;}
			if(MCU_stPinUserCfg[u8PinIndex+1u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=2u;}
			if(MCU_stPinUserCfg[u8PinIndex+2u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=4u;}
			if(MCU_stPinUserCfg[u8PinIndex+3u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=8u;}
			if(MCU_stPinUserCfg[u8PinIndex+4u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=0x10u;}
			if(MCU_stPinUserCfg[u8PinIndex+5u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=0x20u;}
			if(MCU_stPinUserCfg[u8PinIndex+6u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=0x40u;}
			if(MCU_stPinUserCfg[u8PinIndex+7u].bitPinPullDowndefalutValue!=0u)
				{u8FinalData |=0x80u;}

			/*update the data to regitser---->if the pin is not mount, set it to 0 for default*/	
			pPullDown->byte = (uint8)(u8FinalData & u8TempData);
		}

		/*clean the value for this loop*/
		u8FinalData=0u;
		/*find out port data in configuration array and update it into port data regitser*/
		u8TempData = MCU_stResourcePort.u8PortHighDrvMask[u16IndexOffset];
		if( u8TempData !=0u)
		{
			/*fine the all pin default value in this port*/
			if(MCU_stPinUserCfg[u8PinIndex+0u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=1u;}
			if(MCU_stPinUserCfg[u8PinIndex+1u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=2u;}
			if(MCU_stPinUserCfg[u8PinIndex+2u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=4u;}
			if(MCU_stPinUserCfg[u8PinIndex+3u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=8u;}
			if(MCU_stPinUserCfg[u8PinIndex+4u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=0x10u;}
			if(MCU_stPinUserCfg[u8PinIndex+5u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=0x20u;}
			if(MCU_stPinUserCfg[u8PinIndex+6u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=0x40u;}
			if(MCU_stPinUserCfg[u8PinIndex+7u].bitPinHighDrvdefalutValue!=0u)
				{u8FinalData |=0x80u;}

			/*update the data to regitser---->if the pin is not mount, set it to 0 for default*/	
			pHighDrv->byte = (uint8)(u8FinalData & u8TempData);
		}

		/*index piont to next port, and there are 8-pins in a port, so +=8*/
		u8PinIndex+=MCU_mMaxPinsInPort;
		/*index piont to next port*/
		u16IndexOffset++;
		
	}

}
#endif


#if MCU_mTimerModelEnable!=0u

/*****************************************************************************
 Function  : MCU_u16ReLoadTimerInit												 
 Description   :global timer attribute configeration in reset
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16ReLoadTimerInit(void)
{
	/*to supply clock, init the register for ready to run*/
	uint16 u16VectNumber,u16VectPri,u16Loop;
	uint16 u16TimerInit=0u;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u16Loop=0u;u16Loop<MCU_mMaxReLoadTimerMount;u16Loop++)
	{
		u16VectNumber=MCU_stResourceReLoadTimer.u16VectorNumber[u16Loop];
		DET_ErrCheck(((u16VectNumber>=MCU_mMinVectNum) && (u16VectNumber<=MCU_mMAxVectNum)), DET_Err_VectNumberOutOfRange);
		
		/*Timer is active use*/
		if(MCU_stReloadTimerUsrCfg[u16Loop].u16Interval_us !=0u)
		{
			/*get the interrupt priority*/
			u16VectPri=MCU_stReloadTimerUsrCfg[u16Loop].u16VectorPriority;
			DET_ErrCheck((u16VectPri<=MCU_mMinPriLevel), DET_Err_VectPriorityOutOfRange);
			u16TimerInit |=(uint16)(1ul<<u16Loop);
		}
		else
		{
			u16VectPri=MCU_mNotINTPriLevel;/*disable the timer interrupt*/
		}
				 /*higher 8bit is VectNum,lower 8bit is VectPri*/
		ICR=(uint16)((u16VectNumber <<8u)	|u16VectPri);
	}

	/*record re-load timer is initial*/
	MCU_au16ReLoadTimerInit[0]=u16TimerInit;
	MCU_au16ReLoadTimerRun[0]=0u;

	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_vTimerIsr												 
 Description   :re-load timer interrupt service
 
 In Parameter: 
 			u8timerID: timer ID list in _16FX.h
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute ONLY in interrupt
*****************************************************************************/
void MCU_vTimerIsr(uint16 u16timerID)
{
	uint16 u16Address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u16timerID<MCU_mMaxReLoadTimerMount, DET_Err_TimerIDOutOfRange);
	
	u16Address=(uint16)(MCU_mTimerUnitSize*(uint16)u16timerID);
	u16Address+=MCU_mTimerRegHead_TMCSR;
	/*clear interrupt flag*/
	*(volatile uint16 *)u16Address  &=(uint16)~4u;
	MCU_stReloadTimerUsrCfg[u16timerID].vpINTservice();
	u16RetVal+=1u;/*compiler warning*/
}

/*****************************************************************************
 Function  : MCU_u16ReloadTimerStartDefConf												 
 Description   : triger the timer to run within the default user setting
 
 In Parameter: 
 			u16TimerID: Pin ID list in _16FX.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			this function should call after MCU_u16ReLoadTimerInit run
*****************************************************************************/
uint16 MCU_u16ReloadTimerStartDefConf(uint16 u16TimerID)
{
	/*uint8 u8TimerGrp=u16TimerID>>3*/

	/*use for store the timer uint head address*/
	uint16 u16TimerRegisterHead;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*relation register*/
	volatile MCU_tstTMCSR *pTMCSR;
	volatile __WORD *pTMRLR;
		
	/*Check the timer ID is in range*/
	DET_ErrCheck(u16TimerID<MCU_mMaxReLoadTimerMount, DET_Err_TimerIDOutOfRange);
	
	/*Check the timer is mount or not)*/
	DET_ErrCheck(((MCU_stResourceReLoadTimer.u16TimerMountList[0]) & (uint16)(1ul<<u16TimerID))!=0u, DET_Err_ResourceNotMount);

	/*Check the timer is active or not*/
	DET_ErrCheck(MCU_stReloadTimerUsrCfg[u16TimerID].u16Interval_us!=0u, DET_Err_TimerNotActive);

	/*Check the timer is initial or not*/
	DET_ErrCheck((MCU_au16ReLoadTimerInit[0] & (uint16)(1ul<<u16TimerID))!=0u, DET_Err_TimerNotActive);

	/*update the register address*/
	u16TimerRegisterHead=(uint8)MCU_mTimerUnitSize *u16TimerID;
	u16TimerRegisterHead+=MCU_mTimerRegHead_TMCSR;
	pTMCSR=(volatile MCU_tstTMCSR *)u16TimerRegisterHead;
	/*stop the timer first*/
	pTMCSR->word=0u;
	
	u16TimerRegisterHead+=2u;
	pTMRLR=(volatile __WORD *)u16TimerRegisterHead;

	/*update the value to the register and re-start the timer*/
	*pTMRLR = MCU_stReloadTimerUsrCfg[u16TimerID].u16Interval_us;
	pTMCSR->word=(uint16)MCU_mTimer_TMCSRvalue;

	/*record timer is runing*/
	MCU_au16ReLoadTimerRun[0] |=(uint16)(1ul<<u16TimerID);

	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16ReloadTimerStop												 
 Description   : set the timer to stop running
 
 In Parameter: 
 			u16TimerID: Pin ID list in _16FX.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ReloadTimerStop(uint16 u16TimerID)
{
	/*uint8 u8TimerGrp=u16TimerID>>3*/
	
	/*use for store the timer uint head address*/
	uint16 u16TimerRegisterHead;
	uint16 u16RetVal=DET_Err_NotErr;

	/*relation register*/
	volatile MCU_tstTMCSR *pTMCSR;
	volatile __WORD *pTMRLR;
	
	/*Check the timer ID is in range*/
	DET_ErrCheck(u16TimerID<MCU_mMaxReLoadTimerMount, DET_Err_TimerIDOutOfRange);
	
	/*Check the timer is mount or not*/
	DET_ErrCheck((MCU_stResourceReLoadTimer.u16TimerMountList[0] & (uint16)(1ul<<u16TimerID) )!=0u, DET_Err_ResourceNotMount);

	/*Check the timer is active or not*/
	DET_ErrCheck(MCU_stReloadTimerUsrCfg[u16TimerID].u16Interval_us!=0u, DET_Err_TimerNotActive);

	/*update the register address*/
	u16TimerRegisterHead=(uint8)MCU_mTimerUnitSize *u16TimerID;
	u16TimerRegisterHead+=MCU_mTimerRegHead_TMCSR;
	pTMCSR=(volatile MCU_tstTMCSR *)u16TimerRegisterHead;
	
	u16TimerRegisterHead+=2u;
	pTMRLR=(volatile __WORD *)u16TimerRegisterHead;

	/*update the value to the register*/
	pTMCSR->word=0u;
	*pTMRLR = 0u;

	/*record timer is stop*/
	MCU_au16ReLoadTimerRun[0] &=(uint16)(~(uint16)(1ul<<u16TimerID));

	return u16RetVal;
}

#if MCU_mTimerIntervalChgEnable!=0u
/*****************************************************************************
 Function  : MCU_u16ReloadTimerChgInterval												 
 Description   : set the timer interval and start running
 
 In Parameter: 
 			u16TimerID: timer ID list in _16FX.h
 			u16Interval_us: new interval(us)
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ReloadTimerChgInterval(uint16 u16TimerID,uint16 u16Interval_us)
{
	/*uint8 u8TimerGrp=u16TimerID>>3*/

	uint16 u16Adrres;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*relation register*/
	volatile __WORD *pTMRLR;
	volatile MCU_tstTMCSR *pTMCSR;
	
	/*Check the timer ID is in range*/
	DET_ErrCheck(u16TimerID<MCU_mMaxReLoadTimerMount, DET_Err_TimerIDOutOfRange);
	
	/*Check the timer is mount or not*/
	DET_ErrCheck((MCU_stResourceReLoadTimer.u16TimerMountList[0] & (uint16)(1ul<<u16TimerID) )!=0u, DET_Err_ResourceNotMount);

	/*Check the timer is active or not*/
	DET_ErrCheck(MCU_stReloadTimerUsrCfg[u16TimerID].u16Interval_us!=0u, DET_Err_TimerNotActive);

	/*Check the timer is active or not*/
	DET_ErrCheck(MCU_stReloadTimerUsrCfg[u16TimerID].u8IntervalChangeable!=0u, DET_Err_TimerSettingLock);

	/*Check the timer is initial or not*/
	DET_ErrCheck((MCU_au16ReLoadTimerInit[0] & (uint16)(1ul<<u16TimerID))!=0u, DET_Err_TimerNotActive);

	/*update the register address*/
	u16Adrres=(uint8)MCU_mTimerUnitSize *u16TimerID;
	u16Adrres+=MCU_mTimerRegHead_TMRLR;
	pTMRLR=(volatile __WORD *)u16Adrres;

	u16Adrres=(uint8)MCU_mTimerUnitSize *u16TimerID;
	u16Adrres+=MCU_mTimerRegHead_TMCSR;
	pTMCSR=(volatile MCU_tstTMCSR *)u16Adrres;

	/*update the value to the register*/
	*pTMRLR = (__WORD)u16Interval_us;
	/*update the value to register to re-start the timer*/
	pTMCSR->word=(uint16)MCU_mTimer_TMCSRvalue;

	/*record timer is runing*/
	MCU_au16ReLoadTimerRun[0] |=(uint16)(1ul<<u16TimerID);

	return u16RetVal;
}
#endif
#endif

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
 						6----->lowest priority
 						7----->interrupt disable
*****************************************************************************/
uint16 MCU_u16ChangeVectorPriority(uint16 u16VectNum,uint16 u16TargePri)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*Check the vector number is in range*/
	DET_ErrCheck(((u16VectNum>=MCU_mMinVectNum)&&(u16VectNum<=MCU_mMAxVectNum)), DET_Err_VectNumberOutOfRange);

	/*Check the priority level is in range*/
	DET_ErrCheck((u16VectNum<=MCU_mMinPriLevel), DET_Err_VectPriorityOutOfRange);

	/*update the priority control register*/
	ICR=(uint16)((uint16)(((uint32)(u16VectNum))<<8u) |(u16TargePri));

	return u16RetVal;
}
#endif

#if MCU_mPPGModeEnable!=0u

/*****************************************************************************
 Function  : MCU_u16PPGInit												 
 Description   : PPG model initial in reset, 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			it execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16PPGInit(void)
{
	uint16 u16LoopIndex,u16CycleCnt,u16DutyCnt;
	uint16 u16PpgRegsiterHead,u16PinLocate,u16Pcn_OE,u16Epcn_OE2,u16Prrr_PPGx;
	uint16 u16PpgRecord=0u,u16IdMask;
	uint16 u16RetVal=DET_Err_NotErr;

	/*PPG relation register*/
	volatile __WORD *pPCSR;
	volatile __WORD *pPDUT;
	volatile MCU_tstEPCN *pEPCN1;
	volatile MCU_tstPCN *pPCN;
	volatile MCU_tstPRRR *pPRRR;

	for(u16LoopIndex = 0u; u16LoopIndex< MCU_mMaxPPGchannelMount;u16LoopIndex++)
	{
		/*Disable PPG interrupt in this serial MCU*/
		ICR =(uint16)((uint16)(MCU_stResourcePPG.u16PPGCycleMatchVector[u16LoopIndex]<<8u)|MCU_mNotINTPriLevel);

		/*check PPG channel is active or not--*/
		u16PinLocate=(uint16)MCU_stPPGUsrCfg[u16LoopIndex].u8LocatPinMask;
		u16CycleCnt=MCU_stPPGUsrCfg[u16LoopIndex].u16Hz;
		if(( u16PinLocate!=0xFFu) && (u16CycleCnt !=0U))
		{
			/*record PPG status*/
			u16IdMask=(uint16)(1ul<<u16LoopIndex);
			u16PpgRecord |=u16IdMask;
			
			if(u16PinLocate == 0u/*pin PPG*/)
			{
				/*to check this ID is mount*/
				DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
				u16Pcn_OE=1u;
				u16Epcn_OE2=0u;
				u16Prrr_PPGx=0u;
			}
			else if(u16PinLocate == 1u/*pin PPG_R*/)
			{
				/*to check this ID is mount*/
				DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG_R & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
				u16Pcn_OE=1u;
				u16Epcn_OE2=0u;
				u16Prrr_PPGx=1u;
			}
			else if(u16PinLocate == 2u/*pin PPG_B*/)
			{
				/*to check this ID is mount*/
				DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG_B & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
				u16Pcn_OE=0u;
				u16Epcn_OE2=1u;
				u16Prrr_PPGx=0u;
			}
			else
			{
				DET_ErrReport(DET_Err_ParaOutOfRange);
			}

			
			u16PpgRegsiterHead=MCU_au16PPGAddrHead[u16LoopIndex];
			pPCSR=(volatile __WORD *)u16PpgRegsiterHead;
			
			u16PpgRegsiterHead+=2u;
			pPDUT=(volatile __WORD *)u16PpgRegsiterHead;
			
			u16PpgRegsiterHead+=2u;
			pPCN=(volatile MCU_tstPCN *)u16PpgRegsiterHead;

			u16PpgRegsiterHead=u16LoopIndex *(uint8)sizeof(MCU_tstEPCN);
			u16PpgRegsiterHead+=MCU_mPPGRegHead_EPCN;
			pEPCN1=(volatile MCU_tstEPCN *)u16PpgRegsiterHead;
			
			u16PpgRegsiterHead=u16LoopIndex>>3u;/*PRRR one bit is one channel*/
			u16PpgRegsiterHead+=MCU_mPPGRegHead_PRRR;
			pPRRR=(volatile MCU_tstPRRR *)u16PpgRegsiterHead;
			
			/*calc cycle count*/
			u16CycleCnt=(uint16)((uint32)(MCU_mCLK1_Clock / 16u) / u16CycleCnt);
			
			/*calc duty count*/
			u16DutyCnt=MCU_stPPGUsrCfg[u16LoopIndex].u16Duty;
			DET_ErrCheck(u16DutyCnt<=1000u, DET_Err_PpgDutyOutOfRange);
			if(u16DutyCnt == 0u)
			{
				u16DutyCnt=0u;
			}
			else if(u16DutyCnt >= 1000u)
			{
				u16DutyCnt=u16CycleCnt;
			}
			else
			{
				u16DutyCnt=(uint16)(((uint32)u16CycleCnt * u16DutyCnt)/(uint16)1000u);
			}

			/*update cycle register*/
			*pPCSR=u16CycleCnt;

			/*update duty register*/
			*pPDUT=u16DutyCnt;

			/*update PRRR2 register*/
			if(u16Prrr_PPGx == 0u)
			{
				/*PPG channel reloat pin control*/
				pPRRR->byte&=(uint8)(~(uint8)(1u<<(uint8)(u16LoopIndex&7u)));
			}
			else
			{
				pPRRR->byte |=(uint8)((uint8)(1u<<(uint8)(u16LoopIndex&7u)));
			}
			
			
			/*update EPCN register*/
			pEPCN1->word=(uint16)(MCU_mPPGReg_EPCNValue |(uint16)(u16Epcn_OE2 <<10u));
			
			/*update PCN register and start PPG counting*/
			pPCN->word=(uint16)(MCU_mPPGReg_PCNValue |(uint16)(u16Pcn_OE <<1u));
		}
		
	}

	/*PPG record the running status*/
	MCU_au16PPGStatus[0]=u16PpgRecord;

	return u16RetVal;
}

#if MCU_mPPGDeInitEnable!=0u
/*****************************************************************************
 Function  : MCU_vPPGDeInit												 
 Description   : clear PPG model setting
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vPPGDeInit(void)
{
	uint16 u16LoopIndex;
	uint16 u16PpgRegsiterHead;
	
	/*PPG relation register*/
	volatile __WORD *pPCSR;
	volatile __WORD *pPDUT;
	volatile MCU_tstEPCN *pEPCN1;
	volatile MCU_tstPCN *pPCN;
	volatile MCU_tstPRRR *pPRRR;

	for(u16LoopIndex = 0u; u16LoopIndex< MCU_mMaxPPGchannelMount;u16LoopIndex++)
	{
		/*Disable PPG interrupt in this serial MCU*/
		ICR =(uint16)((uint16)(MCU_stResourcePPG.u16PPGCycleMatchVector[u16LoopIndex]<<8u)|MCU_mMinPriLevel);

		/*check PPG channel is active or not--*/
		if(MCU_stPPGUsrCfg[u16LoopIndex].u8LocatPinMask!=0xFFu)
		{
			u16PpgRegsiterHead=MCU_au16PPGAddrHead[u16LoopIndex];
			pPCSR=(volatile __WORD *)u16PpgRegsiterHead;
			
			u16PpgRegsiterHead+=2u;
			pPDUT=(volatile __WORD *)u16PpgRegsiterHead;
			
			u16PpgRegsiterHead+=2u;
			pPCN=(volatile MCU_tstPCN *)u16PpgRegsiterHead;

			u16PpgRegsiterHead=u16LoopIndex *(uint8)sizeof(MCU_tstEPCN);
			u16PpgRegsiterHead+=MCU_mPPGRegHead_EPCN;
			pEPCN1=(volatile MCU_tstEPCN *)u16PpgRegsiterHead;

			u16PpgRegsiterHead=u16LoopIndex>>3u;
			u16PpgRegsiterHead+=MCU_mPPGRegHead_PRRR;
			pPRRR=(volatile MCU_tstPRRR *)u16PpgRegsiterHead;

			/*update PCN register and start PPG counting*/
			pPCN->word=(uint16)0u;
			
			/*update EPCN register*/
			pEPCN1->word=(uint16)0u;
			
			/*update PRRR register*/
			pPRRR->byte&=(uint8)(~(uint8)(1u<<(uint8)(u16LoopIndex&7u)));

			/*update cycle register*/
			*pPCSR=0u;

			/*update duty register*/
			*pPDUT=0u;
		}
	}
	
	/*PPG record the running status*/
	MCU_au16PPGStatus[0]=0u;
	
}
#endif

#if MCU_mPPGSetHzEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PPGSetHz												 
 Description   : set the PPG attribute and start PPG output
 
 In Parameter: 
 			u16PPG_ID: PPG ID list in _16FX.h
 			u16Hz: new output frequency
 			u16Duty:new output percentage, range: 0-->1000(100%)
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16PPGSetHz(uint16 u16PPG_ID, uint16 u16Hz,uint16 u16Duty)
{
	uint16 u16PpgSubID=(uint16)(u16PPG_ID &(MCU_mMaxPPGchannelMount-1u));
	uint16 u16PpgGroupID=(uint16)(u16PPG_ID>>4u);
	uint16 u16CycleCnt,u16DutyCnt=0u,u16IdMask;
	uint16 u16PpgRegsiterHead;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*PPG relation register*/
	volatile __WORD *pPCSR;
	volatile __WORD *pPDUT;
		
	/*check PPG ID is in range or not*/
	DET_ErrCheck(u16PPG_ID<(MCU_mMaxPPGchannelMount * MCU_mMaxPPGPinRelocate), DET_Err_PpgIdOutOfRange);

	/*check duty is in range or not*/
	DET_ErrCheck(u16Duty<=1000u, DET_Err_PpgDutyOutOfRange);
	if(u16Duty>1000u)
	{
		u16Duty=1000u;
	}

	u16IdMask=(uint16)(1ul<<(uint16)(u16PPG_ID & 0x0Fu));
	/*check PPG ID is mounted or not*/
	if(u16PpgGroupID==0u)
	{
		DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
	}
	else 	if(u16PpgGroupID==1u)
	{
		DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG_R & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
	}
	else 	if(u16PpgGroupID==2u)
	{
		DET_ErrCheck(((uint16)(MCU_stResourcePPG.u16PPGMountList_PinPPG_B & u16IdMask) !=0u ), DET_Err_PpgIdNotMount);
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}
	

	/*check PPG ID is active or not*/
	DET_ErrCheck(MCU_stPPGUsrCfg[u16PpgSubID].u8LocatPinMask ==(uint8)u16PpgGroupID, DET_Err_PpgNotActive);

	/*check PPG Frequency  is active or not*/
	DET_ErrCheck(u16Hz>0u, DET_Err_PpgFrequencyOutOfRange);

	/*PPG record the running status: check PPG  is initialization or not*/
	u16PPG_ID &=(MCU_mMaxPPGchannelMount-1u);
	DET_ErrCheck((MCU_au16PPGStatus[0] & (uint16)(1ul<<u16PPG_ID))!=0u, DET_Err_PpgNotInitial);
	
	/*fine the register address*/
	u16PpgRegsiterHead=MCU_au16PPGAddrHead[u16PpgSubID];
	pPCSR=(volatile __WORD *)u16PpgRegsiterHead;
	
	u16PpgRegsiterHead+=2u;
	pPDUT=(volatile __WORD *)u16PpgRegsiterHead;
	
	/*update PPG duty in range 0% --100%*/
	if((u16Duty > 0u) && (u16Duty<1000u))
	{
		u16CycleCnt=(uint16)((MCU_mCLK1_Clock / 16u) / u16Hz);
		u16DutyCnt=(uint16)(((uint32)u16CycleCnt * u16Duty)/(uint16)1000u);
	}
	/*duty range is 0% or 100%*/
	else
	{
		if(u16Duty == 0u)
		{
			u16CycleCnt=0xFFF0u;
			u16DutyCnt=0u;
		}
		else if(u16Duty >= 1000u)
		{	
			u16CycleCnt=0xFFF0u;
			u16DutyCnt=u16CycleCnt;
		}
	}

	/*update the register value and it will reload when in next cycle match*/
	*pPCSR=u16CycleCnt;
	*pPDUT=u16DutyCnt;

	return u16RetVal;
}

#endif
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
	uint16 u16PRRR=0u,u16ENITusing=0u,u16Mask,u16Trigger,u16IdMask;
	uint16 u16RetVal=DET_Err_NotErr;
	
	
	/*relative register*/
	volatile MCU_tstENIR *pENIR;
	volatile MCU_tstELVR *pELVR;
	volatile __WORD *pPRRR;
	
	/*
		Note: EIRR0-->the interrupr quest flag not clearn in reset to avoid miss the interrupt!!
	*/
	
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
			DET_ErrCheck((((MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u) ||\
				((MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u)), DET_Err_EINTNotMounted);

			u16Mask=(uint16)(1ul<<u8Loop);
			
			u16ENITusing|=u16Mask;
			if(u8PinLocate ==1u/*INTn_R Pin*/)
			{
				u16PRRR |=u16Mask;
			}/*INT pin is default*/
		
			/*check the triger ID is in ragne or not*/
			u16Trigger=(uint16)MCU_stEINTUsrCfg[u8Loop].u8DetectCondition;
			DET_ErrCheck(u16Trigger<=3u, DET_Err_EINTtrigerIDOutOfRange);

			if(u8Loop<=7u)
			{
				u16TrigLevel_0 |=(uint16)(u16Trigger<<(uint8)(u8Loop<<1u));
			}
			else
			{
				u16TrigLevel_1 |=(uint16)(u16Trigger<<(uint8)((uint8)(u8Loop-8u)<<1u));
			}
			
			/*check it need run in reset or not*/
			if(MCU_stEINTUsrCfg[u8Loop].u8RunWhenReset == 1u)
			{
				u16StartRun |=u16Mask;
			}
			
			/*set interrupt level*/
			ICR =(uint16)((uint16)(MCU_stResourceEINT.u16VectorNumber[u8Loop]<<8u)|MCU_stEINTUsrCfg[u8Loop].u16VectorPriority);

		}
		else
		{
			/*set interrupt level-->not interrupt*/
			ICR =(uint16)((uint16)(MCU_stResourceEINT.u16VectorNumber[u8Loop]<<8u)|MCU_mNotINTPriLevel);
		}
		
	}


	/*update register value*/
	pPRRR=(volatile __WORD*)MCU_mEINTRegHead_PRRR;
	*pPRRR=u16PRRR;
	
	/*ELVR0*/
	pELVR=(volatile MCU_tstELVR *)MCU_mEINTRegHead_ELVR;
	pELVR->word=u16TrigLevel_0;
	
	/*ELVR1*/
	pELVR=(volatile MCU_tstELVR *)(MCU_mEINTRegHead_ELVR+MCU_mEINTUnitSize);
	pELVR->word=u16TrigLevel_1;

	/*update record*/
	MCU_au16EINTStatus_Init[0U]=u16ENITusing;
	MCU_au16EINTStatus_Run[0u]=u16StartRun;
	
	/*ENIR0---enable run-----*/
	pENIR=(volatile MCU_tstENIR *)MCU_mEINTRegHead_ENIR;
	pENIR->byte=(uint8)(u16StartRun&0x00ffu);
	
	/*ENIR1---enable run-----*/
	pENIR=(volatile MCU_tstENIR *)(MCU_mEINTRegHead_ENIR+MCU_mEINTUnitSize);
	pENIR->byte=(uint8)((uint16)(u16StartRun>>8u)&0x00ffu);

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vEINTIsr												 
 Description   : external interrupt service
 
 In Parameter: 
 			u16EintID: EINT ID list in _16FX.h
 			 			
Return Value:
 			NULLt
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vEINTIsr(uint16 u16EINTid)
{
	uint16 u16Address=MCU_mEINTRegHead_EIRR;
	uint8 u8Group,u8SubIndex;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstEIRR *pEIRR;
	
	DET_ErrCheck(u16EINTid<MCU_mMaxEINTchannelMount, DET_Err_EINTIDOutOfRange);

	u8Group=(uint8)(u16EINTid>>3u);
	u8SubIndex=(uint8)(u16EINTid&7u);
	
	if(u8Group!=0u)
	{
		u16Address+=MCU_mEINTUnitSize;
	}

	/*clear the flag*/
	pEIRR=(volatile MCU_tstEIRR *)u16Address;
	pEIRR->byte &=(uint8)~(uint8)(1u<<u8SubIndex);
	/*run callback function*/
	MCU_stEINTUsrCfg[u16EINTid].vpINTservice();
	
	u16RetVal+=1u;/*compiler warning*/

}


#if MCU_mEINTOnOffCtrlFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_u16EINTrunControl												 
 Description   : external interrupt detect control
 
 In Parameter: 
 			u16EintID: EINT ID list in _16FX.h
 			u8On_Off: detect the interrupt enable or not
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static uint16 MCU_u16EINTrunControl(uint16 u16EintID, uint8 u8On_Off)
{
	uint16 u16EintGrp=0u;
	uint16 u16MaskValue=0u,u16Address,u16IdMask;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*relative register*/
	volatile MCU_tstENIR *pENIR;
        u16EintGrp++;/*compiler warning*/
	u16EintGrp=(u16EintID>>4u);
	/*check ID is in range*/
	DET_ErrCheck(u16EintID<MCU_mMaxEINTchannelMount * MCU_mMaxEINTPinRelocate, DET_Err_EINTIDOutOfRange);

	u16IdMask=(uint16)(1ul<<(uint16)(u16EintID & 0x0Fu));

	/*check the resource is mounted or not*/
	if(u16EintID<MCU_mMaxEINTchannelMount)
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	else
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	

	/*mask for real ID*/
	u16EintID&=0x000fu;
	
	/*check the ID input is right in the EINT group*/
	DET_ErrCheck(MCU_stEINTUsrCfg[u16EintID].u8LocatPinMask==(uint8)u16EintGrp, DET_Err_EINTIDOutOfRange);
	
	/*mask value for mask*/
	u16MaskValue |=(uint16)(1ul<<u16EintID);

	/*update address*/
	u16Address = MCU_mEINTRegHead_ENIR;
	if(u16MaskValue>=0x0080u)
	{
		/*Not in first group*/
		u16Address +=MCU_mEINTUnitSize;
		u16MaskValue>>=8u;/*mask high 8bit*/
	}
	pENIR=(volatile MCU_tstENIR *)u16Address;
	
	if(u8On_Off !=0u)
	{
		/*ENIR1---run enable -----*/
		pENIR->byte |=(uint8)((uint16)(u16MaskValue&0x00ffu));
		MCU_au16EINTStatus_Run[0u] |=(uint16)(1ul<<u16EintID);
	}
	else
	{
		/*ENIR1---run disable -----*/
		pENIR->byte &=(uint8)~((uint16)(u16MaskValue&0x00ffu));
		MCU_au16EINTStatus_Run[0u] &=(uint16)~(uint16)(1ul<<u16EintID);
	}

	return 	u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16EINTenable												 
 Description   : external interrupt detect enable control
 
 In Parameter: 
 			u16EintID: EINT ID list in _16FX.h
 			
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
 			u16EintID: EINT ID list in _16FX.h
 			
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
 			u16EintID: EINT ID list in _16FX.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTchgIntCondition(uint16 u16EintID,uint8 u8NewTrigerCondition)
{
	uint16 u16EintGrp=0u,u16IdMask;
	uint16 u16MaskValue=0u,u16Address_ELVR,u16Address_ENIR;
	uint16 u16RetVal=DET_Err_NotErr;

	/*relative register*/
	volatile MCU_tstELVR *pELVR;
	volatile MCU_tstENIR *pENIR;
        u16EintGrp++;/*compiler warning*/
	u16EintGrp=(u16EintID>>4u);
	/*check ID is in range*/
	DET_ErrCheck(u16EintID<MCU_mMaxEINTchannelMount * MCU_mMaxEINTPinRelocate, DET_Err_EINTIDOutOfRange);

	/*check the resource is mounted or not*/
	u16IdMask=(uint16)(1ul<<(uint16)(u16EintID & 0x0Fu));

	/*check the resource is mounted or not*/
	if(u16EintID<MCU_mMaxEINTchannelMount)
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}
	else
	{
		DET_ErrCheck(((uint16)(MCU_stResourceEINT.u16PinMount_INT_R & u16IdMask) !=0u), DET_Err_EINTNotMounted);
	}

	
	/*mask for real ID*/
	u16EintID&=0x000fu;
	
	/*check the ID input is right in the EINT group*/
	DET_ErrCheck(MCU_stEINTUsrCfg[u16EintID].u8LocatPinMask==(uint8)u16EintGrp, DET_Err_EINTIDOutOfRange);

	/*check the EINT triger is changeable*/
	DET_ErrCheck(MCU_stEINTUsrCfg[u16EintID].u8DetConditionChgable!=0u, DET_Err_EINTtrigerCanNotChg);

	/*check the triger ID input is right*/
	DET_ErrCheck(u8NewTrigerCondition<=3u, DET_Err_EINTtrigerIDOutOfRange);

	u16Address_ELVR=MCU_mEINTRegHead_ELVR;
	u16Address_ENIR=MCU_mEINTRegHead_ENIR;
	
	if(u16EintID>=8u)
	{
		u16Address_ELVR+=MCU_mEINTUnitSize;
		u16Address_ENIR+=MCU_mEINTUnitSize;
		u16EintID-=8u;
	}
	
	/*disable EINT*/
	pENIR=(volatile MCU_tstENIR *)u16Address_ENIR;
	pENIR->byte&=(uint8)~(uint8)(1u<<u16EintID);

	/*update interrupt level*/
	u16MaskValue=(uint16)u8NewTrigerCondition;
	u16MaskValue<<=(uint8)((uint8)(u16EintID<<1u));
	pELVR=(volatile MCU_tstELVR *)u16Address_ELVR;
	
	/*clear old value*/
	pELVR->word &=(uint16)~(uint16)(3ul<<((uint8)(u16EintID<<1u)));
	/*update new value*/
	pELVR->word |=u16MaskValue;

	/*enable EINT*/
	pENIR=(volatile MCU_tstENIR *)u16Address_ENIR;
	pENIR->byte|=(uint8)(1u<<u16EintID);

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
	volatile MCU_tstENIR *pENIR;
	volatile MCU_tstELVR *pELVR;
	volatile __WORD *pPRRR;

	/*Init the record*/
	MCU_au16EINTStatus_Init[0u]=0u;
	MCU_au16EINTStatus_Run[0u]=0u;
	
	for(u8Loop=0u;u8Loop<MCU_mMaxEINTchannelMount;u8Loop++)
	{
		/*set interrupt level-->not interrupt*/
		ICR =(uint16)((uint16)(MCU_stResourceEINT.u16VectorNumber[u8Loop]<<8u)|MCU_mNotINTPriLevel);
	}

	/*ENIR0---disable run-----*/
	pENIR=(volatile MCU_tstENIR *)MCU_mEINTRegHead_ENIR;
	pENIR->byte=0u;
	
	/*ENIR1---disable run-----*/
	pENIR=(volatile MCU_tstENIR *)(MCU_mEINTRegHead_ENIR+MCU_mEINTUnitSize);
	pENIR->byte=0u;
	
	/*update register value*/
	pPRRR=(volatile __WORD *)MCU_mEINTRegHead_PRRR;
	*pPRRR=(uint8)0u;/*only EINT0-7 can be re-locate*/
	
	/*ELVR0*/
	pELVR=(volatile MCU_tstELVR *)MCU_mEINTRegHead_ELVR;
	pELVR->word=0u;
	
	/*ELVR1*/
	pELVR=(volatile MCU_tstELVR *)(MCU_mEINTRegHead_ELVR+MCU_mEINTUnitSize);
	pELVR->word=0u;
	
}
#endif

#endif

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
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8Loop;
	
	DET_ErrCheck(((~MCU_stResourceADC.u32ADCMountMask) & (MCU_stADCUsrCfg.u32ADCusing)) ==0ul , DET_Err_ADCNotMounted);

	MCU_u8ADCStatus=1u;	
	MCU_u8ADCchannelCtrl=0u;
	/*stop ADC*/
	*(volatile __WORD*)MCU_mADCRegHead_ADCS=0u;
	/*Enable ADC function*/
	*(volatile uint32 *)MCU_mADCRegHead_ADER=MCU_stADCUsrCfg.u32ADCusing;
	*(volatile __WORD*)MCU_mADCRegHead_ADSR=MCU_mADCRegValue_ADSR;
	
	ICR =(uint16)((uint16)(MCU_stResourceADC.u16VectorNumber<<8u)|MCU_mADCDefaultPriLevel);

	/*clear RAM data in reset*/
	for(u8Loop=0u;u8Loop<MCU_mMaxADCchannelMount;u8Loop++)
	{
		MCU_au16AdcResault[u8Loop]=0u;
	}
	
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
	MCU_u8ADCchannelCtrl=0u;
	/*start ADC*/
	*(volatile __WORD*)MCU_mADCRegHead_ADCS=MCU_mADCRegValue_ADCS;    

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCstart												 
 Description   : external interrupt detect condition control
 
 In Parameter: 
 			u16EintID: EINT ID list in _16FX.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCstop(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(MCU_u8ADCStatus !=0u , DET_Err_ADCNotInit);
	
	/*stop ADC*/
	MCU_u8ADCStatus=3u;
	MCU_u8ADCchannelCtrl=0u;
	*(volatile __WORD*)MCU_mADCRegHead_ADCS=0u;

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCgetResault												 
 Description   :get the ADC resault
 
 In Parameter: 
 			u8ChannelID: ADC ID list in _16FX.h
 			*u16AD_Resault: ADC output resault address
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCgetResault(uint8 u8ChannelID, uint16 *u16AD_Resault)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u8ChannelID<MCU_mMaxADCchannelMount , DET_Err_ADCNotInit);
	DET_ErrCheck(((~MCU_stResourceADC.u32ADCMountMask) & ((uint32)(1ul<<u8ChannelID))) ==0ul , DET_Err_ADCNotMounted);
	DET_ErrCheck(MCU_u8ADCStatus !=0u , DET_Err_ADCNotInit);
	DET_ErrCheck(((uint32)(1ul<<u8ChannelID) & (MCU_stADCUsrCfg.u32ADCusing)) !=0ul , DET_Err_ADCNotMounted);

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


	/*stop ADC*/
	ADCSH=0U;
	ADCSL=0U;
	ADSR=0U;
	
	/*Enable ADC function*/
	*(volatile uint32 *)MCU_mADCRegHead_ADER=0ul;
	
	MCU_u8ADCStatus=0u;	
	ICR =(uint16)((uint16)(MCU_stADCUsrCfg.u16VectorPriority<<8u)|MCU_mNotINTPriLevel);

	/*clear RAM data in reset*/
	for(u8Loop=0u;u8Loop<MCU_mMaxADCchannelMount;u8Loop++)
	{
		MCU_au16AdcResault[u8Loop]=0u;
	}

}
#endif

#endif

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
	uint16 u16Loop,u16DMACSset;
	
	DER=0U;
 	DSR=0u;/*clear all request first*/
 	DSSR=0u;/*clear all request first*/
 	
 	/*clear all of the DMA discription data in RAM---->RAM data is not accessiable if the DMA is not mount!
	memset((void *)MCU_mDMAregisterHead_BAPL,0x00,MCU_mMaxDMAchannelMount*8u)*/
 	/*clear all of the DMA DESL data in RAM---->RAM data is not accessiable if the DMA is not mount!
	memset((void *)MCU_mDMAregisterHead_DISEL,0x00,MCU_mMaxDMAchannelMount)*/
	
	MCU_u16DMAStatus_Init=0u;
	for(u16Loop=0u;u16Loop<MCU_mMaxDMAchannelMount;u16Loop++)
	{
		u16DMACSset=0u;
		if(MCU_stDMAUsrCfg[u16Loop].u16VectorNum !=0u)
		{
			DET_ErrCheck((MCU_stResourceDMA.u16DMAmountMask & (uint16)(1ul<<u16Loop)) !=0u, DET_Err_DMANotMounted);
			DET_ErrCheck(MCU_stDMAUsrCfg[u16Loop].u32SourceAddr < 0xfffffful, DET_Err_DMAAddrOutOfRange);
			DET_ErrCheck(MCU_stDMAUsrCfg[u16Loop].u32DestinationAddr< 0xfffffful, DET_Err_DMAAddrOutOfRange);

			/*IO change type--->default is lock*/
			if(MCU_stDMAUsrCfg[u16Loop].u16DestinationChgType==0u/*un-lock, up*/)
			{
				u16DMACSset |=(uint16)(1u<<12u);
			}
			
			/*Buffer change type*/
			/*lock*/		
			if(MCU_stDMAUsrCfg[u16Loop].u16SourceChgType==0u)
			{
				u16DMACSset |=(uint16)(1u<<10u);
			}
			/*un-lock, down*/
			else if(MCU_stDMAUsrCfg[u16Loop].u16SourceChgType==2u)
			{
				u16DMACSset |=(uint16)(1u<<13u);
			}
			/*--->default = un-lock, up*/
			else if(MCU_stDMAUsrCfg[u16Loop].u16SourceChgType==1u)
			{
			}
			else
			{
				DET_ErrReport(DET_Err_ParaOutOfRange);
			}
			
			/*BUFFER to IO mode*/
			/*not need run other intterupt*/
			u16DMACSset |=(uint16)(1u<<9u);
			
			/*word or byte tranfer type*/
			if(MCU_stDMAUsrCfg[u16Loop].u16DataUnitSize !=0u)/*word type transfer*/
			{
				u16DMACSset |=(uint16)(1<<11);
			}			
			
			MCU_u8DMAsetting[u16Loop]=(uint8)(u16DMACSset>>8u);
			MCU_u16DMAStatus_Init |=(uint16)(1ul<<u16Loop);
	 		
		}
	}

	return u16RetVal;

 }
/*****************************************************************************
 Function  : MCU_u16DMAenable												 
 Description   :enable the DMA channel and run
 
 In Parameter: 
 			u8DMAchn: DMA ID list in _16FX.h

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16DMAenable(uint8 u8DMAchn)
{
	uint32 u32SetAddr;
	uint16 u16Address,u16Offset;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile __BYTE *pDISEL;
	volatile MCU_tstIOABK *pIOABK;
	
	volatile uint32 *pBAP;
	volatile MCU_tstDMA *pDMACS;
	volatile __WORD *pIOA;
	volatile __WORD *pDCT;
		
	DET_ErrCheck(MCU_stDMAUsrCfg[u8DMAchn].u16VectorNum !=0u, DET_Err_DMAIDOutOfRange);
	DET_ErrCheck((MCU_stResourceDMA.u16DMAmountMask & (uint16)(1ul<<u8DMAchn)) !=0u, DET_Err_DMANotMounted);
	DET_ErrCheck((MCU_u16DMAStatus_Init & (uint16)(1ul<<u8DMAchn)) !=0u, DET_Err_DMANotInitial);

	u16Offset=(uint16)((uint16)u8DMAchn<<3u);/*every channel discription buffer size is 8bytes, so x8*/
	
	/********************vector number********************/
	u16Address=MCU_mDMAregisterHead_DISEL ;
	u16Address+=u8DMAchn;
	pDISEL=(volatile __BYTE *)u16Address;
	*pDISEL=MCU_stDMAUsrCfg[u8DMAchn].u16VectorNum;


	/*******************buffer address--24bit*******************/
	u32SetAddr=MCU_stDMAUsrCfg[u8DMAchn].u32SourceAddr;
	u16Address=MCU_mDMAregisterHead_BAPL;
	u16Address+=u16Offset;
	pBAP=(volatile uint32 *)u16Address;
	*pBAP=u32SetAddr;

	/******************IO address, 8bit bank + 16bit Lower*************/
	u32SetAddr=MCU_stDMAUsrCfg[u8DMAchn].u32DestinationAddr;
	/*IO bank address --->higher 8bit*/
	u16Address=MCU_mDMAregisterHead_IOABK;
	u16Address+=u8DMAchn;
	pIOABK=(volatile MCU_tstIOABK *)u16Address;
	pIOABK->byte=(uint8)(u32SetAddr>>16u);
	/*IO address-->lower 16bit*/
	u16Address=MCU_mDMAregisterHead_IOA;
	u16Address+=u16Offset;
	pIOA=(volatile __WORD *)u16Address;
	*pIOA=(uint16)(u32SetAddr);
	
	/*************************data size control**********************/
	u16Address=MCU_mDMAregisterHead_DCT;
	u16Address+=u16Offset;
	pDCT=(volatile __WORD *)u16Address;
	*pDCT=MCU_stDMAUsrCfg[u8DMAchn].u16DataTattolSize;
	
	/********************transfer attribute control (over write BAP highest 8bit)*****/
	u16Address=MCU_mDMAregisterHead_DMACS;
	u16Address+=u16Offset;
	pDMACS=(volatile MCU_tstDMA *)u16Address;
	pDMACS->byte=MCU_u8DMAsetting[u8DMAchn];

	/********************run the DMA**********************************/
	DSR &=(uint16)~(uint16)(1ul<<u8DMAchn);
	DSSR&=(uint16)~(uint16)(1ul<<u8DMAchn);
	DER |=(uint16)(1Ul<<u8DMAchn);

	return u16RetVal;

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
	DER =0u;
	DSR =0u;
	DSSR=0u;
	
 	/*clear all of the DMA discription data in RAM---->RAM data is not accessiable if the DMA is not mount!
	memset((void *)MCU_mDMAregisterHead_BAPL,0x00,MCU_mMaxDMAchannelMount*8u)*/
 	/*clear all of the DMA DESL data in RAM---->RAM data is not accessiable if the DMA is not mount!
	memset((void *)MCU_mDMAregisterHead_DISEL,0x00,MCU_mMaxDMAchannelMount)*/
 }
 
/******************************************************

not perform, because DMA is enough to use, not multiple use

void MCU_vDMAconfigerate(uint8 u8DMAchn,uint16 setting)
{
}
************************************************************/
#endif

#endif

#if MCU_mUARTmodelEnable !=0u
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
static uint16 MCU_u16UARTinit(void)
{
	uint16 u16Loop,u16BaudRate;
	uint16 u16SCRvalue=0u;
	uint16 u16Temp,u16PrrrAddr;
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32EIERAddr=(uint32)(MCU_mUARTRegisterHead_EIER-16ul);
	
	/*register group pionter*/
	volatile MCU_tstUART *pUart;
	volatile __far MCU_tstEIER *pEIER;
	volatile __BYTE *pPRRR;
	
	MCU_u16UARTStatus_Init=0u;
	
	for(u16Loop=0u;u16Loop<MCU_mMaxUARTchannelMount;u16Loop++)
	{
		u32EIERAddr+=(uint32)(1ul<<4u);/*EIER address in 16byte a unit*/
		
		u16BaudRate=MCU_stUARTUsrCfg[u16Loop].u16BaudRate; 
		u16SCRvalue=0u;
		if(u16BaudRate!=0u)
		{
			/*check the resource is mounted in this MCU*/
			DET_ErrCheck(((MCU_stResourceUART.u16UARTMountMask_SINn & (uint16)(1ul<<u16Loop))!=0u )||\
						((MCU_stResourceUART.u16UARTMountMask_SINn_R & (uint16)(1ul<<u16Loop))!=0u), DET_Err_UARTNotMounted);

			pUart=(volatile MCU_tstUART *)MCU_au16UARTAddrHead[u16Loop];

			/***************Parity setting***************************************/
			u16Temp=(uint16)MCU_stUARTUsrCfg[u16Loop].u8Parity;
			DET_ErrCheck(u16Temp<=3u, DET_Err_UARTParityBitErr);
			u16SCRvalue |=(uint16)(u16Temp<<14u);
			
			/***************stop bit setting***************************************/
			u16Temp=MCU_stUARTUsrCfg[u16Loop].u8StopBit;
			DET_ErrCheck(u16Temp<=1u, DET_Err_UARTStopBitErr);
			u16SCRvalue |=(uint16)(u16Temp<<13u);
			
			/***************data lenth setting, default is 8bit**************************/
			u16SCRvalue |=1u<<12u;
			/***************data attibute setting, default is data frame*****************/
			/***************Error clear***************************************/
			u16SCRvalue |=1u<<10u;
			
			/***************Rec disable when init**********************************/
			/***************Send disable when init****************************/

			/**update register value**/
			pUart->SCR0.byte=(uint8)(u16SCRvalue>>8u);
			
			/***************BaudRate setting******************************/
			u16Temp=MCU_stUARTUsrCfg[u16Loop].u16BaudRate;
			DET_ErrCheck(u16Temp>=1000u, DET_Err_UARTbaudRateSetErr);
			/**update register value**/
			pUart->BGR0.word= (uint16)(MCU_mCLK1_Clock/u16Temp) -1u;

			/**************LSB/MSB setting*********************************/
			u16Temp=0u;
			if(MCU_stUARTUsrCfg[u16Loop].u8MsbLsb !=0u/*0=LSB,1=MSB*/)
			{
				u16Temp=1u<<10u;/*u16Temp data must overwrite*/
			}
			
			/**************RX/TX interrupt setting: disable *************************/
			/*u16Temp|=3u<<8u*/
			
			/**update register value**/
			pUart->SSR0.byte = (uint8)(u16Temp>>8u);
			pUart->SMR0.bit.UPCL=1u;/*restart counter*/

			/*interrupt in send finish*/
			pEIER=(volatile __far MCU_tstEIER *)u32EIERAddr;
			pEIER->bitc.LBSOIE=1u;
			
			/*Pin re-locate setting*/
			if(MCU_stUARTUsrCfg[u16Loop].u8LocatPinMask !=0u)
			{
				if(u16Loop == 5u)/*UART5-R*/
				{
					u16PrrrAddr=0x0662u;/*PRRR12: BIT->7 6 5*/
					pPRRR=(volatile __BYTE *)u16PrrrAddr;
					*pPRRR = (uint8)((uint8)(MCU_stUARTUsrCfg[5u].u8LocatPinMask & 7u )<<5u);/*YES, over write other bits*/
				}
				else if(u16Loop == 7u)/*UART7-R*/
				{
					u16PrrrAddr=0x04DEu;/*PRRR8: BIT->2 1 0*/
					pPRRR=(volatile __BYTE *)u16PrrrAddr;
					*pPRRR = (uint8)((uint8)(MCU_stUARTUsrCfg[7u].u8LocatPinMask & 7u));/*YES, over write other bits*/
				}
				else
				{
					DET_ErrReport(DET_Err_UARTPinReloacteErr);
				}
			}

			/*interrupt setting*/
			ICR=(uint16)((MCU_stResourceUART.u16VectorNumber_RX[u16Loop]<<8U) |MCU_stUARTUsrCfg[u16Loop].u8Parity);
			ICR=(uint16)((MCU_stResourceUART.u16VectorNumber_TX[u16Loop]<<8U) |MCU_stUARTUsrCfg[u16Loop].u8Parity);

			MCU_u16UARTStatus_Init |=(uint16)(1ul<<u16Loop);
			MCU_stUARTStatus_Ctrl[u16Loop].u16TottalLen=0u;
			
		}
	}

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vUARTIsr_Tx												 
 Description   :UART model Tx interrupt service
 
 In Parameter: 
 			u8channel:UART ID list in _16FX.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vUARTIsr_Tx(uint8 u8channel)
{
	uint16 u16RetVal=DET_Err_NotErr,u16Wait=20u;
	
	/*register group pionter*/
	volatile MCU_tstUART *pUart=(volatile MCU_tstUART *)MCU_au16UARTAddrHead[u8channel];

	volatile MCU_tstESR *pESR;
	uint16 u16Address;
	
	/*check ID in range*/
	DET_ErrCheck(u8channel<MCU_mMaxUARTchannelMount, DET_Err_UARTIDOutOfRange);

	/*send data correctly or not, send continue anyway*/
	MCU_stUARTStatus_Ctrl[u8channel].u16SendingLen++;
	if(MCU_stUARTStatus_Ctrl[u8channel].u16SendingLen>=MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen)
	{	
		/*pionte to the ESR*/
		u16Address=MCU_mUARTRegisterHead_ESR;
		u16Address+=(uint16)((uint16)u8channel<<1u);	
		pESR=(volatile MCU_tstESR *)u16Address;
		while((pESR->bit.LBSOF == 0u) && (u16Wait>0u)){u16Wait--;}/*wait  the data output finish*/
		pESR->bit.LBSOF = 0u;/*clear interrupt flag*/
		
		/*TX disable*/
		pUart->SCR0.bit.TXE=0u;
		
		/*set driver to ready*/
		MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen=MCU_mUARTReadyDefValue;
		MCU_stUARTStatus_Ctrl[u8channel].u16SendingLen=0u;
		
		/*send finish, then call the send finish handle*/
		MCU_stUARTUsrCfg[u8channel].vpSendFinish();
	}
	else
	{
		/*send not finish, then continue------------------*/
		pUart->RDR0= MCU_stUARTStatus_Ctrl[u8channel].pDataHead[MCU_stUARTStatus_Ctrl[u8channel].u16SendingLen];
	}
        u16RetVal+=1u;/*compiler warning*/
}

/*****************************************************************************
 Function  : MCU_vUARTIsr_Rx												 
 Description   :UART model Rx interrupt service
 
 In Parameter: 
 			u8channel:UART ID list in _16FX.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vUARTIsr_Rx(uint8 u8channel)
{
	uint8 u8Err;
	uint8 u8Data;
	
	uint16 u16RetVal=DET_Err_NotErr;

	/*register group pionter*/
	volatile MCU_tstUART *pUart=(volatile MCU_tstUART *)MCU_au16UARTAddrHead[u8channel];

	/*check ID in range*/
	DET_ErrCheck(u8channel<MCU_mMaxUARTchannelMount, DET_Err_UARTIDOutOfRange);
	
	u8Err=pUart->SSR0.byte & 0xE0U;/*check the parity error,over run error,frame error*/
	u8Data=pUart->RDR0;/*read out data and clear RDRF int request*/

	if(u8Err !=0u)
	{
		/*clear the error*/
		pUart->SCR0.bit.CRE=0x01u;
		/*happen error, then call the error handle*/
		MCU_stUARTUsrCfg[u8channel].vu8ErrCallBack(u8Err);
	}
	
	/*Not care recivced data correctly or not, then call the recivce handle*/
	MCU_stUARTUsrCfg[u8channel].vu8RecCallBack(u8Data);
        u16RetVal+=1u;/*compiler warning*/
}


/*****************************************************************************
 Function  : MCU_u16UARTctrl												 
 Description   :control the UART model Tx/Rx
 
 In Parameter: 
 			u8channel:UART ID list in _16FX.h
 			u8TxCtrl: send data enable or not
 			u8RxCtrl: receive data enable or not
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16UARTctrl(uint8 u8channel, uint8 u8TxCtrl, uint8 u8RxCtrl)
{
	uint16 u16SCRvalue=0u,u16SMRvalue=0u,u16SSRvalue=0u;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*register group pionter*/
	volatile MCU_tstUART *pUart=(volatile MCU_tstUART *)MCU_au16UARTAddrHead[u8channel];

	/*check input range*/
	DET_ErrCheck(u8channel<MCU_mMaxUARTchannelMount, DET_Err_UARTIDOutOfRange);
	
	/*check UART is initialized*/
	DET_ErrCheck((MCU_u16UARTStatus_Init & (uint16)(1ul<<u8channel))!=0u, DET_Err_UARTNotMounted);

	/*clear error*/
	u16SCRvalue |=(uint16)(1u<<10u);

	if(u8RxCtrl !=0u)
	{
		/*RX enable, clear the error flag*/
		u16SCRvalue |=(uint16)(3u<<9u);
		/*RX interrupt enable*/
		u16SSRvalue |=(uint16)(1u<<9u);
	}

	if( u8TxCtrl!=0u)
	{		
		/*output enable*/
		u16SMRvalue=1u;
		/*set to ready*/
		MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen=MCU_mUARTReadyDefValue;
	}
	else
	{
		/*set driver to not ready for send*/
		MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen=0u;
	}

	/*********update register value********************************/
	pUart->SCR0.byte &=(uint8)~3u;/*clear RXE,TXE*/
	pUart->SCR0.byte |=(uint8)(u16SCRvalue>>8u);/*update RXE,TXE*/

	pUart->SSR0.byte &=(uint8)~3u;/*clear RIE,TIE*/
	pUart->SSR0.byte |=(uint8)(u16SSRvalue>>8u);/*update RIE,TIE*/

	if((u8RxCtrl != 0u)||(u8TxCtrl  != 0u))
	{
		/*clear or set SOE, mode is 0,  UART/BaudRate counter not clear,*/
		pUart->SMR0.byte = (uint8)u16SMRvalue;
	}
	else
	{
		pUart->SMR0.byte =0x00u;
	}
	
	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_u16UARTsend												 
 Description   :UART send data control
 
 In Parameter: 
 			u8channel:UART ID list in _16FX.h
 			*DataHead: need send data head 
 			u16SendLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16UARTsend(uint8 u8channel, uint8 *DataHead, uint16 u16SendLen)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	/*register group pionter*/
	volatile MCU_tstUART *pUart=(volatile MCU_tstUART *)MCU_au16UARTAddrHead[u8channel];
	
	/*check input range*/
	if(u8channel<(uint8)MCU_mMaxUARTchannelMount)
	{
		DET_ErrCheck(MCU_stResourceUART.u16UARTMountMask_SINn, DET_Err_UARTNotMounted);
	}
	else if(u8channel<(uint8)(MCU_mMaxUARTchannelMount<<1U))
	{
		DET_ErrCheck((MCU_stResourceUART.u16UARTMountMask_SINn_R & \
			(uint16)(1ul<<(uint8)(u8channel - MCU_mMaxUARTchannelMount)) )!=0u, DET_Err_UARTNotMounted);
	}
	else
	{
		DET_ErrReport(DET_Err_UARTIDOutOfRange);
	}

	u8channel &= (uint8)(MCU_mMaxUARTchannelMount-1u);
	/*check UART is initialized*/
	DET_ErrCheck((MCU_u16UARTStatus_Init & (uint16)(1ul<<u8channel))!=0u, DET_Err_UARTNotMounted);
	
	/*check UART is ready or not: 
	it is ready only after intial success 
	and control Tx enable in first time,
	or send finish in other condition*/
	if((MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen==MCU_mUARTReadyDefValue) && 
		(u16SendLen>0u))
	{
		/*clear it to record send bytes*/
		MCU_stUARTStatus_Ctrl[u8channel].u16SendingLen=0u;
		MCU_stUARTStatus_Ctrl[u8channel].u16TottalLen=u16SendLen;
		MCU_stUARTStatus_Ctrl[u8channel].pDataHead=DataHead;
		
		/*send out data------------------------*/
		pUart->RDR0 = *DataHead;
		
		/*TX interrupt enable*/
		pUart->SCR0.bit.TXE=1u;
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


#if MCU_mUARTDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vUARTDeInit												 
 Description   :clean UART model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vUARTDeInit(void)
{
	uint8 u8Loop;

	/*clear register data*/
	for(u8Loop=0u;u8Loop<MCU_mMaxUARTchannelMount;u8Loop++)
	{
		memset((void *)MCU_au16UARTAddrHead[u8Loop],0x00,MCU_mUARTUnitSize);
	}
	/*clear lenth control*/
	memset((void *)MCU_stUARTStatus_Ctrl,0x00,sizeof(MCU_stUARTStatus_Ctrl));
	
}
#endif

#endif

#if MCU_mICUmodelEnable!=0u
/*****************************************************************************
 Function  : MCU_u16ICUinit												 
 Description   :initial ICU model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function execute before system-mailoop
*****************************************************************************/
static uint16 MCU_u16ICUinit(void)
{
	uint8 u8SetValue;
	uint16 u16Loop;
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16address=MCU_mICURegisterHead_PRRR4;
	
	volatile MCU_tstPRRR * PRRR=(volatile MCU_tstPRRR *)u16address;
	volatile MCU_tstICS * pICS;
	
	/*set the counter to 1us/count----
	warining: only set FRT0&1, if more than these FRT, modify this pragma*/
	TCCS0=0x03u;
	TCCS1=0x03u;
	
	MCU_u8ICUStatus=0u;
	MCU_u8ICUStatus_Init=0u;
	
	memset((void *)MCU_au8ICULastOVcnt,0,sizeof(MCU_au8ICULastOVcnt));
	memset((void *)MCU_au16ICULastCnt,0,sizeof(MCU_au16ICULastCnt));
	memset((void *)MCU_au8FRT_OVcnt,0,sizeof(MCU_au8FRT_OVcnt));
	
	for(u16Loop=0u;u16Loop<MCU_mMaxICUchannelMount;u16Loop++)
	{
		/*ICU is conf for user*/
		if(MCU_stICUUsrCfg[u16Loop].u8LocatPinMask !=0xffu)
		{
			DET_ErrCheck(((1ul<<u16Loop)&MCU_mICUresourceMount_Mask)!=0u, DET_Err_ICUNotMounted);

			/**************Pin Re-Locate*************************/
			if(MCU_stICUUsrCfg[u16Loop].u8LocatPinMask)
			{
				PRRR->byte |=(uint8)(1u<<u16Loop);
			}

			/**************interrupt enable and flag clear*************************/
			u8SetValue=1u<<4u;/*YES, update the new value*/
			
			/**************setting the edge, if not run in reset, keep value 0u*************************/
			if(MCU_stICUUsrCfg[u16Loop].u8RunInRst !=0u)
			{
				u8SetValue |=MCU_stICUUsrCfg[u16Loop].u8DetectEdge;
			}

			/*convert to register setting: one register contain two channel setting*/
			if((u16Loop &1u)!=0u)
			{
								/*****interrupt part				edge part***/
				u8SetValue=(uint8)((u8SetValue&0xf0u)<<1u)|(uint8)((u8SetValue&0x0fu)<<2u);
			}

			/*update value to register*/
			u16address=(uint16)(MCU_mICUUnitSize*(uint16)(u16Loop>>1u));
			u16address+=MCU_mICURegisterHead_ICS;
			pICS=(volatile MCU_tstICS *)u16address;
			pICS->byte |=u8SetValue;

			/**************interrupt priority setting*************************/
			ICR =(uint16)(((uint16)(MCU_stResourceICU.u16ICUvectorTable[u16Loop]<<8U))|MCU_stICUUsrCfg[u16Loop].u8VectorPriority);

			/*record the status*/
			MCU_u8ICUStatus|=(uint8)(1u<<u16Loop);
		}
	}

	return u16RetVal;

}
/*****************************************************************************
 Function  : MCU_vICUIsr												 
 Description   :ICU interrupt service
 
 In Parameter: 
 			u8ICUid: ICU ID list in _16FX.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/

void MCU_vICUIsr(uint8 u8ICUid)
{
	uint8 u8IFBitIndex;
	uint8 u8EdgeBitIndex;
	uint8 u8DetEdge;
	uint8 u8OverCycle;
	uint8 u8FRTid=u8ICUid>>3u;
	
	uint16 u16address,u16ThisCnt,u16Temp;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstICS *pICS;
	volatile MCU_tstICE *pICE;
	volatile __WORD *pIPCP;
	
	DET_ErrCheck(u8ICUid<MCU_mMaxICUchannelMount, DET_Err_ICUIDOutOfRange);

	/*fisrt ICU in group*/
	if((u8ICUid&1u)==0u)
	{
		u8EdgeBitIndex=1u;
		u8IFBitIndex=6u;
	}
	else
	{
		u8EdgeBitIndex=2u;
		u8IFBitIndex=7u;
	}

	/*set the head address of this ICU*/
	u16address=(uint16)(MCU_mICUUnitSize*(uint16)((uint16)u8ICUid>>1u));
	u16address+=MCU_mICURegisterHead_ICS;
	
	/*clear interrupt bit*/
	pICS=(volatile MCU_tstICS *)u16address;
	pICS->byte &=(uint8)~(uint8)(1u<<u8IFBitIndex);
	
	/*read out detect edge*/
	u16address++;
	pICE=(volatile MCU_tstICE *)u16address;
	u8DetEdge=(uint8)pICE->byte;
	
	/*read out time counte*/
	if((u8ICUid&1u)==0u){
		u16address++;
	}else{
		u16address+=3u;
	}
	
	pIPCP=(volatile __WORD *)u16address;
	u16ThisCnt=*pIPCP;
	u16Temp=u16ThisCnt;

	/*not in first interrupt, then calc the timing-------------*/
	if((MCU_u8ICUStatus_Init & (uint8)(1u<<u8ICUid))!=0u)
	{
		if(u16ThisCnt<=MCU_au16ICULastCnt[u8ICUid])/*over cycle*/
		{
			u16ThisCnt=MCU_au16ICULastCnt[u8ICUid]-u16ThisCnt;
			u16ThisCnt=~u16ThisCnt;
		}
		else
		{
			u16ThisCnt=u16ThisCnt-MCU_au16ICULastCnt[u8ICUid];
		}

		/*get the over flow cycle to calc real time*/
		u8OverCycle=MCU_au8FRT_OVcnt[u8FRTid]-MCU_au8ICULastOVcnt[u8ICUid];
		if(MCU_au8ICULastOVcnt[u8ICUid]<MCU_au8FRT_OVcnt[u8FRTid])
		{
			u8OverCycle =~u8OverCycle;
		}
		
		u8DetEdge=((u8DetEdge&u8EdgeBitIndex) != 0u) ? 0u : 1u;	

		/*record this cycle data for next*/
		MCU_au16ICULastCnt[u8ICUid]=u16Temp;
		MCU_au8ICULastOVcnt[u8ICUid]=MCU_au8FRT_OVcnt[u8FRTid];
		
		/*call the app layer function */
		MCU_stICUUsrCfg[u8ICUid].vu32DetCallBack((uint32)((uint32)u16ThisCnt+(uint32)(((uint32)u8OverCycle)<<16u)),u8DetEdge);
	}
	else
	{
		/*record first start piont*/
		MCU_u8ICUStatus_Init|=(uint8)(1u<<u8ICUid);
		MCU_au16ICULastCnt[u8ICUid]=u16Temp;
		MCU_au8ICULastOVcnt[u8ICUid]=MCU_au8FRT_OVcnt[u8FRTid];
	}

        u16RetVal+=1u;/*compiler warning*/
}

/*****************************************************************************
 Function  : MCU_u16ICUDetTrigCrtl												 
 Description   :configerate the ICU triger interrupt condition
 
 In Parameter: 
 			u8Channel:ICU ID list in _16FX.h
 			u8DetEdge:new interrupt triger condition
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUDetTrigCrtl(uint8 u8Channel, uint8 u8DetEdge)
{
	uint8 u8SetValue=0u,u8maskvalue=3u;
	uint16 u16address;
	uint16 u16RetVal=DET_Err_NotErr;
	
	volatile MCU_tstICS * pICS;

	DET_ErrCheck(u8Channel<MCU_mMaxICUchannelMount, DET_Err_ICUIDOutOfRange);

	if((MCU_u8ICUStatus & (uint8)(1u<<u8Channel))!=0u)
	{
		DET_ErrCheck(u8DetEdge<=3u, DET_Err_ICUEdgeOutOfRange);
		
		/*it will stop this ICU*/
		if(u8DetEdge == 0u)
		{
			MCU_u8ICUStatus_Init&=(uint8)~(uint8)(1u<<u8Channel);
		}
		
		if((u8Channel &1u) !=0u)
		{
			u8DetEdge<<=2u;
			u8maskvalue<<=3u;
		}
		
		u8maskvalue =~u8maskvalue;
		
		/*update value to register*/
		u16address=(uint16)(MCU_mICUUnitSize*(uint16)((uint16)u8Channel>>1u));
		u16address+=MCU_mICURegisterHead_ICS;
		pICS=(volatile MCU_tstICS *)u16address;
		pICS->byte &=u8maskvalue;/*clear bits*/
		pICS->byte |=u8SetValue;/*update new bits*/
		
	}
	else
	{
		DET_ErrReport(DET_Err_ICUNotInit);
	}

	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ICUstop												 
 Description   :ICU channel detect disable 
 
 In Parameter: 
 			u8Channel:ICU ID list in _16FX.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUstop(uint8 u8Channel)
{
        return MCU_u16ICUDetTrigCrtl(u8Channel,0u);
}


/*****************************************************************************
 Function  : MCU_u16ICUstop												 
 Description   :ICU channel detect disable 
 
 In Parameter: 
 			u8Channel:ICU ID list in _16FX.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ICUstart(uint8 u8Channel,uint8 u8DetEdge)
{
	return MCU_u16ICUDetTrigCrtl(u8Channel,u8DetEdge);
}

#if MCU_mIICUDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vICUDeInit												 
 Description   :clean ICU model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vICUDeInit(void)
{
	memset((void *)MCU_mICURegisterHead_ICS,0u,0x57-0x40);
	memset((void *)MCU_au16ICULastCnt,0u,sizeof(MCU_au16ICULastCnt));

	MCU_u8ICUStatus=0u;
	MCU_u8ICUStatus_Init=0u;
}

#endif

#endif


#if MCU_mLCDmodelEnable!=0u
/*****************************************************************************
 Function  : MCU_vLCDinit												 
 Description   :LCD model initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function execute before system-mailoop
*****************************************************************************/
static void MCU_vLCDinit(void)
{
	uint8 u8LCDvalue=0u;
	uint8 u8LCDVR=0u,u8ComMask;
	uint8 u8Loop;
	
	uint16 u16RetVal=DET_Err_NotErr;
	
	MCU_vLCDStatus_Init=0u;
	
	/*using the Peripheral clock (CLKP1)*/
	/*do not in timer mode*/
	
	if(MCU_stLCDUsrCfg.u8VoltageDiv !=0u)
	{
		/*using internal voltage----*/
		u8LCDvalue |=(uint8)(1u<<5u);
	}
	else
	{
		/*use external voltage, anble the voltage input to driver*/
		u8LCDVR=(uint8)(1u<<(uint8)(MCU_stLCDUsrCfg.u8ComUse & 3u))-1u;
	}

	/*enable working
	u8LCDvalue |=(uint8)(1u<<4u)*/

	/*set using com number*/
	u8ComMask =(uint8)((uint8)MCU_stLCDUsrCfg.u8ComUse & 3u);
	u8LCDvalue |=(uint8)(u8ComMask<<2u);

	/*set driver frequency*/
	u8LCDvalue |=(uint8)(MCU_stLCDUsrCfg.u8DrvFrequency & 3u);

	/*check resource configeration is OK*/
	for(u8Loop=0u;u8Loop<(uint8)(MCU_mMaxLCDSegMount/8u);u8Loop++)
	{
		DET_ErrCheck((((uint8)~MCU_stResourceLCD.u8SegMount[u8Loop]) & MCU_stLCDUsrCfg.u8SegUse[u8Loop]) ==0u,DET_Err_LCDSegNotMout);
	}
	
	/*clear the VRAM*/
	memset((void *)MCU_mLCDRegisterHead_VRAM,0,(MCU_mMaxLCDSegMount>>1u));

	/*set using segment number*/
	memcpy((void *)MCU_mLCDRegisterHead_LCDER,(void *)MCU_stLCDUsrCfg.u8SegUse,sizeof(MCU_stLCDUsrCfg.u8SegUse));

         /*update register value*/
         LCDVER=u8LCDVR; 
         LCR=u8LCDvalue;                       
         u8ComMask++;
         LCDCMR=(uint8)((uint8)(1u<<u8ComMask)-1u);
         LECR=0u;       
		
	
	MCU_vLCDStatus_Init=1u;
	
}

/**************************************************************************
 Function  : MUC_u16LcdDisplayUpdate												 
 Description   :LCD dispaly control
 
 In Parameter: 
 			*pu8VRAMHead: display information data head
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			the segment and com pin map to the display RAM register mapping as follows:

=====================================================

	COM pin :		COM3	COM2	COM1	COM0
---------------------------------------------------------------
		|lowBit: 	bit3		bit2		bit1		bit0 	|	 SEG_(2n) pin
VRAM_n  	|-----------------------------------|+++++++++++++++
		|HighBit:	bit7		bit6		bit5		bit4	|	 SEG_(2n+1) pin
---------------------------------------------------------------

=======================================================
******************************************************************************/
uint16 MUC_u16LcdDisplayUpdate(uint8 pu8VRAMHead[], uint8 u8BuffLen)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(MCU_vLCDStatus_Init !=0u, DET_Err_LCDNotIint);
	DET_ErrCheck(u8BuffLen<=(MCU_mMaxLCDSegMount>>1u), DET_Err_LCDVramOutOfRange);

	memcpy((void *)MCU_mLCDRegisterHead_VRAM,(void *)pu8VRAMHead,u8BuffLen);

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
static uint16 MCU_u16IICinit(void)
{
	uint16 u16Temp;
	uint16 u16RetVal=DET_Err_NotErr;

	MCU_stIICStatus.u8InitStatus=0u;
	MCU_stIICStatus.u8StartConditionNeed=0u;

	/*configuration for using IIC*/
	u16Temp=MCU_stI2CUsrCfg[0u].u16TansferSpeed;
	if(u16Temp !=0xffu)
	{
		DET_ErrCheck((MCU_stResourceI2C.u16I2CMounte & (uint16)(1u<<0u)) !=0u,DET_Err_IICNotMounted);
		DET_ErrCheck(((u16Temp >0u) && (u16Temp <32u)),DET_Err_IICBpsOutOfRange);

		/*Only use the 7bit address mode*/
		IIC0_ISMK0_ENSB =1u;/*7bit*/
		#if 0
		u16Temp=MCU_stI2CUsrCfg[0u].u8SlaveAddrLenth;
		DET_ErrCheck((u16Temp <2u),DET_Err_IICAddrLenOutOfRange);
		
		/*setting slave address lenth*/
		if(u16Temp == 0u)
		{
			IIC0_ISMK0_ENSB =1u;/*7bit*/
		}
		else
		{
			IIC0_ITMK0_ENTB =1u;/*10bit*/
		}
		#endif
		/*setting bps*/
		IIC0_ICCR0 = MCU_stI2CUsrCfg[0u].u16TansferSpeed;
		
		MCU_stIICStatus.u8InitStatus |=(uint8)(1u<<0u);
		MCU_stIICStatus.u8RunningMode=0u;
		
		/**************interrupt priority setting*************************/
		DET_ErrCheck(MCU_stI2CUsrCfg[0u].u8VectorPriority<=7u,DET_Err_IICVectLvOutOfRange);
		ICR =(uint16)(((uint16)(96u<<8u))|MCU_stI2CUsrCfg[0u].u8VectorPriority);
		
	}
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterStartCondition												 
 Description   :IIC triger start-condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _16FX.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterStartCondition(uint8 u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(((MCU_stIICStatus.u8InitStatus !=0u) && (MCU_stIICStatus.u16WorkingDataLen==0xffffu)&&
				(MCU_stIICStatus.u8StartConditionNeed ==0u)),DET_Err_IICNotReady);

	MCU_stIICStatus.u8StartConditionNeed=1u;
	u8I2C_masterID=0u;
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterStopCondition												 
 Description   :IIC triger stop -condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _16FX.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterStopCondition(uint8 u8I2C_masterID)
{
	/*If a "0" is written to it during a master interrupt (MSS="1" and INT="1"), 
	the INT bit is cleared automatically, a stop condition will be generated 
	and the data transfer ends.*/
	if((IIC0_IBCR0_MSS ==1u) && (IIC0_IBCR0_INT ==1u))
	{
		IIC0_IBCR0_MSS=0u;
	}
	
	IIC0_IBCR0=0u;
	u8I2C_masterID=0u;
	
	return 0u;
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterSend												 
 Description   :IIC master node send out data to the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _16FX.h
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
	uint16 u16IBCRValue=0u;
	uint16 u16ICCRvalue=0u;
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u8SalveDevice_index<MCU_mI2CMaxSlaveInOneMaster, DET_Err_IICSlaveIDOutOfRange);
	DET_ErrCheck(MCU_stIICStatus.u8InitStatus !=0u, DET_Err_IICNotReady);

	if(MCU_stIICStatus.u8RunningMode==0u)
	{
		if(MCU_stIICStatus.u8StartConditionNeed !=0u)
		{
			MCU_stIICStatus.u8StartConditionNeed=0u;
			/*A repeated start condition is generated if a "1" is written to this bit 
			while an interrupt in master mode (MSS="1" and INT="1") 
			and the INT bit is cleared automatically.*/
			if((IIC0_IBCR0_MSS ==1u) && (IIC0_IBCR0_INT ==1u))
			{
				/*IIC0_IBCR0_SCC=1u*/
				u16IBCRValue|=(uint16)(1u<<13u);
			}
			/*If a "1" is written to it while the bus is idle (MSS="0" and BB="0"), 
			a start condition is generated and the contents of the IDAR register 
			(which should be address data) is sent.*/
			else 	if((IIC0_IBCR0_MSS ==0u) && (IIC0_IBSR0_BB==0u))/*if fattal error happen, it will run this case*/
			{
				/*IIC0_IBCR0_MSS=1u*/
				u16IBCRValue|=(uint16)(1u<<12u);
			}
			else
			{
				/*can not genernal start condition*/
				DET_ErrReport(DET_Err_IICCanNotTrigStartCondi);
			}
			
		}
		
		
		/*record bus working status*/		
		MCU_stIICStatus.u16WorkingDataLen=0u;
		MCU_stIICStatus.u16TottalDataLen=u16Lenth;
		MCU_stIICStatus.u8SlaveChannel=u8SalveDevice_index;
		MCU_stIICStatus.pu8DataHead=pDataHead;
		MCU_stIICStatus.u8RunningMode=1u;/*sending mode*/

		/*fill data in shift-buffer for transfer out*/
		IIC0_IDAR0 = pDataHead[0];
		
		/*triger for IIC start working*/
		/*err dectect and interrupt enable, Master mode,clear INT bit*/
		u16IBCRValue |=(uint16)(1ul<<14u)|(uint16)(1ul<<12u)|(uint16)(1ul<<9u);
		u16IBCRValue>>=8u;
		IIC0_IBCR0 = (uint8)u16IBCRValue; /*it will send out data now*/

		/*IIC enable and start working*/
		if(IIC0_ICCR0_EN ==0u)
		{
			IIC0_ICCR0 |=0x60u;
		}	
	}
	else
	{
		u16RetVal=DET_Err_IICIsBusy;
	}
	u8I2C_masterID=0u;
	
	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16IIC_MasterRec												 
 Description   :IIC master node receive data from the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _16FX.h
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
	uint16 u16IBCRValue=0u;
	uint16 u16ICCRvalue=0u;
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u8SalveDevice_index<MCU_mI2CMaxSlaveInOneMaster, DET_Err_IICSlaveIDOutOfRange);
	DET_ErrCheck(MCU_stIICStatus.u8InitStatus !=0u, DET_Err_IICNotReady);

	if(MCU_stIICStatus.u8RunningMode==0u)
	{
		/*record bus working status*/		
		MCU_stIICStatus.u16WorkingDataLen=0u;
		MCU_stIICStatus.u16TottalDataLen=u16Lenth;
		MCU_stIICStatus.u8SlaveChannel=u8SalveDevice_index;
		MCU_stIICStatus.pu8DataHead=pDataHead;
		MCU_stIICStatus.u8RunningMode=2u;/*receive mode*/

		/*fill dummy data in shift-buffer for transfer out*/
		IIC0_IDAR0 = 0xFFu;
		
		/*triger for IIC start working*/
		/*err dectect and interrupt enable, Master mode,clear INT bit*/
		u16IBCRValue |=(uint16)(1ul<<14u)|(uint16)(1ul<<12u)|(uint16)(1ul<<9u);
		if(u16Lenth>1u)
		{
			u16IBCRValue|=(uint16)(1ul<<11u);/*will ACK the slave if lenth more then 1byte*/
		}
		u16IBCRValue>>=8u;
		IIC0_IBCR0 = (uint8)u16IBCRValue;/*it will start tansfer now*/
		
		/*IIC enable and start working*/
		if(IIC0_ICCR0_EN ==0u)
		{
			IIC0_ICCR0 |=0x60u;
		}
		
	}
	else
	{
		u16RetVal=DET_Err_IICIsBusy;
	}
	u8I2C_masterID=0u;
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vIICIsr												 
 Description   :IIC interrupt service
 
 In Parameter: 
 			u8Channel: IIC ID list in _16FX.h
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vIICIsr(uint8 u8Channel)
{
	/*bus error happen:not-expect start/stop conditon detect or Arbitration loss*/
	if((IIC0_IBCR0_BER ==1u) ||(IIC0_IBSR0_AL==1u))
	{
		IIC0_ICCR0_EN=0u;/*IIC disable and clear err flag, it need to re-start IIC*/
		IIC0_IBCR0_BER=0u;/*clear error flag*/
		MCU_stIICStatus.u8Error |=1u;/*IIC timing error*/
	}
	/*slave NotAck err*/
	else if(IIC0_IBSR0_LRB ==1u)
	{
		/*IIC0_IBCR0=0u  start condition to clear this error*/
		MCU_stIICStatus.u8Error |=2u;/*IIC slave not respond*/
	}
	else
	{
		/*not care other condition*/
	}
	
	if(MCU_stIICStatus.u8RunningMode==1u)/*sending mode*/
	{
		MCU_stIICStatus.u16WorkingDataLen++;
		if(MCU_stIICStatus.u16WorkingDataLen>=MCU_stIICStatus.u16TottalDataLen)
		{
			/*error happend callback */
			if(MCU_stIICStatus.u8Error !=0u)
			{
				MCU_stI2CUsrCfg[0u].stSlaveCB[MCU_stIICStatus.u8SlaveChannel].vu8ErrCB(MCU_stIICStatus.u8Error);
				MCU_stIICStatus.u8Error=0u;
			}

			/*send finishand callback*/
			MCU_stIICStatus.u8RunningMode=0u;		
			/*IIC0_IBCR0=0u--->do not triger stop condition, it will control by user app*/
			MCU_stI2CUsrCfg[0u].stSlaveCB[MCU_stIICStatus.u8SlaveChannel].vpSendfinishCB();
		}
		else
		{
			/*continue send out data*/
			IIC0_IDAR0 = MCU_stIICStatus.pu8DataHead[MCU_stIICStatus.u16WorkingDataLen];/*fill data in shift-buffer for transfer out*/
			/*IIC enable and start working*/
			if(IIC0_ICCR0_EN ==0u)
			{
				IIC0_ICCR0 |=0x60u;
				IIC0_IBCR0 =0X52U;/*restart iic(it will triger start-condition), master mode,INTE=1*/
			}
			else
			{
				IIC0_IBCR0_INTE=1u;
				IIC0_IBCR0_INT=0u;/*it will start tansfer now*/
			}
		}

	}
	else if(MCU_stIICStatus.u8RunningMode==2u)/*receive mode*/
	{
		MCU_stIICStatus.pu8DataHead[MCU_stIICStatus.u16WorkingDataLen]=(uint8)IIC0_IDAR0;
		MCU_stIICStatus.u16WorkingDataLen++;
		
		if(MCU_stIICStatus.u16WorkingDataLen>=MCU_stIICStatus.u16TottalDataLen)
		{
			/*error happend callback */
			if(MCU_stIICStatus.u8Error !=0u)
			{
				MCU_stI2CUsrCfg[0u].stSlaveCB[MCU_stIICStatus.u8SlaveChannel].vu8ErrCB(MCU_stIICStatus.u8Error);
				MCU_stIICStatus.u8Error=0u;
			}

			/*receive finish, output stop condition and callback*/
			MCU_stIICStatus.u8RunningMode=0u;		
			/*IIC0_IBCR0=0u--->do not triger stop condition, it will control by user app*/
			MCU_stI2CUsrCfg[0u].stSlaveCB[MCU_stIICStatus.u8SlaveChannel].vpRecFinishCB();
		}
		else
		{
			/*continue send out data*/
			IIC0_IDAR0 = 0xFFu;/*fill dummy data in shift-buffer for transfer out*/
			/*IIC enable and start working*/
			if(IIC0_ICCR0_EN ==0u)
			{
				IIC0_ICCR0 |=0x60u;
				IIC0_IBCR0 =0X52U;/*restart iic(it will triger start-condition), master mode,INTE=1*/
			}
			else
			{
				IIC0_IBCR0_INTE=1u;
				IIC0_IBCR0_INT=0u;/*it will start tansfer now*/
			}

			if(MCU_stIICStatus.u16WorkingDataLen<MCU_stIICStatus.u16TottalDataLen-1u)
			{
				/*not the last byte, then ack the slave*/
				IIC0_IBCR0_ACK=1u;
			}
			else
			{
				/*in the last byte, then Not ack the slave for prepare stop tranfer*/
				IIC0_IBCR0_ACK=0u;
			}
			
		}
		
	}
	else
	{
		MCU_stIICStatus.u8Error |=4u;/*bus status control error*/
		MCU_stIICStatus.u8RunningMode=0u;	
	}
	u8Channel=0u;
}

#endif


/*****************************************************************************
 Function  : MCU_vOscInit												 
 Description   :OSC initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in asm in this serial chip
*****************************************************************************/
static void MCU_vOscInit(void)
{

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
 			it has done in asm in this serial chip
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
	WDTCP_= 0u;
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
*****************************************************************************/
static void MCU_vLowVoltDetectInit(void)
{

#if MCU_mLVIDisable != MCU_mLVIlevelSetting

	/*LVI Interrupt disable and clean flag,
	Big hysteresis selected to avoid reset frequency,
	Oscillation mode,
	Low Voltage Detection = 3.2V*/
	CILCR=MCU_mLVIlevelSetting;

	/*if low voltage, then reset MCU*/
	RCR_LVRE =1u;

	/*LVI enable and run!!*/
	RCR_LVDE =1u;
	
#else

	/*LVI disable reset or interrupt!!*/
	RCR_LVRE =0u;
	RCR_LVDE =0u;
	CILCR=0u;
	
#endif

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
	RCR_SRSTG=1u;
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
        
       #if _16FX_Debug!=0u
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
        
       #if _16FX_Debug!=0u
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
        
       #if _16FX_Debug!=0u
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
	/*check the register value is they writen right or not, 
	if the value is not right, then not run program*/
	if(*((__far uint32 *)0xDF0034ul)  != 0x292D3A7Bul)
	{
		while(1)
		{
			;
		}
	}
}


/*****************************************************************************
 Function  : MCU_u16RunModeCtrl												 
 Description   :MCU running mode control, to enter normal-mode, standby-mode, halt-mode ect
 
 In Parameter: 
 			u8ExpMode :MCU expected running mode 

						0: running mode =>
							MCU run normally
							
						1: Sleep mode =>
							only cut off CPU clock supply, other clock and resource keep running
							
						2: Timer mode =>
							cut off CPU and resource clock, only the physical clock keep running, 
							ect PLL, sub-OSC, main-OSC is running, but it not supply to CPU or resource
							
						3: Stop mode =>

							All clock stops, include sub-OSC, main-OSC, PLL, CPU,..... 
							it is the lowest power consumption in this mode
							
 			u8PinHighZ :  set pin status to high-impedance  or not 

						0: Pin keep output level in expect mode
						1: Pin keep high-impedance(High-Z mode) in expect mode

 			
Return Value:
 			NULL
 			
 NOTE: 		
 
			CPU will not excute next commond until wait the clock stable!
		
*****************************************************************************/
uint16 MCU_u16RunModeCtrl(uint8 u8ExpMode, uint8 u8PinHighZ )
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8SetValue;
	
	DET_ErrCheck(u8ExpMode <= 3u, DET_Err_RunModeOutOfRange);
	
	u8SetValue = u8ExpMode;
	
	if((u8PinHighZ !=0u) && (u8ExpMode !=0u))
	{
		u8SetValue |=4u;
	}
	
	SMCR = u8SetValue;

	return u16RetVal;
}


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

/********************************
	Import external APP layer interface
*********************************/
extern void SYS_vMainLoop(void);

void main(void)
{
	DI();

	MCU_vOscInit();
	MCU_vClockInit();
	MCU_vWatchDogInit();
	MCU_vLowVoltDetectInit();
	MCU_vHWConfigCheck();
	
	#if MCU_mPortModeEnable !=0u
	MCU_vPortInit();
	#endif
	
	#if MCU_mTimerModelEnable!=0u
	MCU_u16ReLoadTimerInit();
	#endif
	
	#if MCU_mPPGModeEnable!=0u
	MCU_u16PPGInit();
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
	
	#if MCU_mDMAmodelEnable !=0u
	MCU_u16DMAinit();
	#endif	

	#if MCU_mUARTmodelEnable!=0u
	MCU_u16UARTinit();
	#endif

	#if MCU_mIICmodelEnable!=0u
	MCU_u16IICinit();
	#endif

	#if MCU_mLCDmodelEnable!=0u
	MCU_vLCDinit();
	#endif
	
	EI_Force();

	SYS_vMainLoop();

	/*MCU reset if out of mainloop*/
	RCR_SRSTG=1u;    
	while(1)
	{
		;
	}	
}

#endif/*end of this file*/

