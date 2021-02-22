/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial
| File Name: _78K0R.h
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
| 2016.02.17	V0.02       Tan, fumin	:add UART control function interface
|								:add ADC_Sleep and ADC_wakeup function for low current
|								:in MCU halt/stop mode
********************************************************************************/

#ifndef _78K0R_H
#define _78K0R_H


/*******************************************************************************
	Pin ID define List, Max Pin mount in this serial MCU
*******************************************************************************/
#define MCU_mMaskPinID(PinID)			((uint16)((PinID) & 0xFFU))
#define MCU_mMaskPortID(PinID)		((uint16)(((uint16)((PinID)>>8U)) & 0xFFU))
#define MCU_mListIndex(Port,Pin)		((uint16)((uint16)(Port)<<3u)+(uint16)(Pin))/*convert the pinID to list index*/


/*Pin Index in Port-0*/
#define MCU_mPinID_P00_0	0x0000u
#define MCU_mPinID_P00_1	0x0001u
#define MCU_mPinID_P00_2	0x0002u
#define MCU_mPinID_P00_3	0x0003u
#define MCU_mPinID_P00_4	0x0004u
#define MCU_mPinID_P00_5	0x0005u
#define MCU_mPinID_P00_6	0x0006u
#define MCU_mPinID_P00_7	0x0007u

/*Pin Index in Port-1*/
#define MCU_mPinID_P01_0	0x0100u
#define MCU_mPinID_P01_1	0x0101u
#define MCU_mPinID_P01_2	0x0102u
#define MCU_mPinID_P01_3	0x0103u
#define MCU_mPinID_P01_4	0x0104u
#define MCU_mPinID_P01_5	0x0105u
#define MCU_mPinID_P01_6	0x0106u
#define MCU_mPinID_P01_7	0x0107u
	
/*Pin Index in Port-2*/
#define MCU_mPinID_P02_0	0x0200u
#define MCU_mPinID_P02_1	0x0201u
#define MCU_mPinID_P02_2	0x0202u
#define MCU_mPinID_P02_3	0x0203u
#define MCU_mPinID_P02_4	0x0204u
#define MCU_mPinID_P02_5	0x0205u
#define MCU_mPinID_P02_6	0x0206u
#define MCU_mPinID_P02_7	0x0207u

/*Pin Index in Port-3*/
#define MCU_mPinID_P03_0	0x0300u
#define MCU_mPinID_P03_1	0x0301u
#define MCU_mPinID_P03_2	0x0302u
#define MCU_mPinID_P03_3	0x0303u
#define MCU_mPinID_P03_4	0x0304u
#define MCU_mPinID_P03_5	0x0305u
#define MCU_mPinID_P03_6	0x0306u
#define MCU_mPinID_P03_7	0x0307u

/*Pin Index in Port-4*/
#define MCU_mPinID_P04_0	0x0400u
#define MCU_mPinID_P04_1	0x0401u
#define MCU_mPinID_P04_2	0x0402u
#define MCU_mPinID_P04_3	0x0403u
#define MCU_mPinID_P04_4	0x0404u
#define MCU_mPinID_P04_5	0x0405u
#define MCU_mPinID_P04_6	0x0406u
#define MCU_mPinID_P04_7	0x0407u

/*Pin Index in Port-5*/
#define MCU_mPinID_P05_0	0x0500u
#define MCU_mPinID_P05_1	0x0501u
#define MCU_mPinID_P05_2	0x0502u
#define MCU_mPinID_P05_3	0x0503u
#define MCU_mPinID_P05_4	0x0504u
#define MCU_mPinID_P05_5	0x0505u
#define MCU_mPinID_P05_6	0x0506u
#define MCU_mPinID_P05_7	0x0507u

/*Pin Index in Port-6*/
#define MCU_mPinID_P06_0	0x0600u
#define MCU_mPinID_P06_1	0x0601u
#define MCU_mPinID_P06_2	0x0602u
#define MCU_mPinID_P06_3	0x0603u
#define MCU_mPinID_P06_4	0x0604u
#define MCU_mPinID_P06_5	0x0605u
#define MCU_mPinID_P06_6	0x0606u
#define MCU_mPinID_P06_7	0x0607u

/*Pin Index in Port-7*/
#define MCU_mPinID_P07_0	0x0700u
#define MCU_mPinID_P07_1	0x0701u
#define MCU_mPinID_P07_2	0x0702u
#define MCU_mPinID_P07_3	0x0703u
#define MCU_mPinID_P07_4	0x0704u
#define MCU_mPinID_P07_5	0x0705u
#define MCU_mPinID_P07_6	0x0706u
#define MCU_mPinID_P07_7	0x0707u

/*Pin Index in Port-8*/
#define MCU_mPinID_P08_0	0x0800u
#define MCU_mPinID_P08_1	0x0801u
#define MCU_mPinID_P08_2	0x0802u
#define MCU_mPinID_P08_3	0x0803u
#define MCU_mPinID_P08_4	0x0804u
#define MCU_mPinID_P08_5	0x0805u
#define MCU_mPinID_P08_6	0x0806u
#define MCU_mPinID_P08_7	0x0807u

/*Pin Index in Port-9*/
#define MCU_mPinID_P09_0	0x0900u
#define MCU_mPinID_P09_1	0x0901u
#define MCU_mPinID_P09_2	0x0902u
#define MCU_mPinID_P09_3	0x0903u
#define MCU_mPinID_P09_4	0x0904u
#define MCU_mPinID_P09_5	0x0905u
#define MCU_mPinID_P09_6	0x0906u
#define MCU_mPinID_P09_7	0x0907u

/*Pin Index in Port-10*/
#define MCU_mPinID_P10_0	0x0A00u
#define MCU_mPinID_P10_1	0x0A01u
#define MCU_mPinID_P10_2	0x0A02u
#define MCU_mPinID_P10_3	0x0A03u
#define MCU_mPinID_P10_4	0x0A04u
#define MCU_mPinID_P10_5	0x0A05u
#define MCU_mPinID_P10_6	0x0A06u
#define MCU_mPinID_P10_7	0x0A07u

/*Pin Index in Port-11*/
#define MCU_mPinID_P11_0	0x0B00u
#define MCU_mPinID_P11_1	0x0B01u
#define MCU_mPinID_P11_2	0x0B02u
#define MCU_mPinID_P11_3	0x0B03u
#define MCU_mPinID_P11_4	0x0B04u
#define MCU_mPinID_P11_5	0x0B05u
#define MCU_mPinID_P11_6	0x0B06u
#define MCU_mPinID_P11_7	0x0B07u

/*Pin Index in Port-12*/
#define MCU_mPinID_P12_0	0x0C00u
#define MCU_mPinID_P12_1	0x0C01u
#define MCU_mPinID_P12_2	0x0C02u
#define MCU_mPinID_P12_3	0x0C03u
#define MCU_mPinID_P12_4	0x0C04u
#define MCU_mPinID_P12_5	0x0C05u
#define MCU_mPinID_P12_6	0x0C06u
#define MCU_mPinID_P12_7	0x0C07u

/*Pin Index in Port-13*/
#define MCU_mPinID_P13_0	0x0D00u
#define MCU_mPinID_P13_1	0x0D01u
#define MCU_mPinID_P13_2	0x0D02u
#define MCU_mPinID_P13_3	0x0D03u
#define MCU_mPinID_P13_4	0x0D04u
#define MCU_mPinID_P13_5	0x0D05u
#define MCU_mPinID_P13_6	0x0D06u
#define MCU_mPinID_P13_7	0x0D07u

/*Pin Index in Port-14*/
#define MCU_mPinID_P14_0	0x0E00u
#define MCU_mPinID_P14_1	0x0E01u
#define MCU_mPinID_P14_2	0x0E02u
#define MCU_mPinID_P14_3	0x0E03u
#define MCU_mPinID_P14_4	0x0E04u
#define MCU_mPinID_P14_5	0x0E05u
#define MCU_mPinID_P14_6	0x0E06u
#define MCU_mPinID_P14_7	0x0E07u

/*Pin Index in Port-15*/
#define MCU_mPinID_P15_0	0x0F00u
#define MCU_mPinID_P15_1	0x0F01u
#define MCU_mPinID_P15_2	0x0F02u
#define MCU_mPinID_P15_3	0x0F03u
#define MCU_mPinID_P15_4	0x0F04u
#define MCU_mPinID_P15_5	0x0F05u
#define MCU_mPinID_P15_6	0x0F06u
#define MCU_mPinID_P15_7	0x0F07u

/*Pin Index in Port-16*/
#define MCU_mPinID_P16_0	0x1000u
#define MCU_mPinID_P16_1	0x1001u
#define MCU_mPinID_P16_2	0x1002u
#define MCU_mPinID_P16_3	0x1003u
#define MCU_mPinID_P16_4	0x1004u
#define MCU_mPinID_P16_5	0x1005u
#define MCU_mPinID_P16_6	0x1006u
#define MCU_mPinID_P16_7	0x1007u

/*Pin Index in Port-17*/
#define MCU_mPinID_P17_0	0x1100u
#define MCU_mPinID_P17_1	0x1101u
#define MCU_mPinID_P17_2	0x1102u
#define MCU_mPinID_P17_3	0x1103u
#define MCU_mPinID_P17_4	0x1104u
#define MCU_mPinID_P17_5	0x1105u
#define MCU_mPinID_P17_6	0x1106u
#define MCU_mPinID_P17_7	0x1107u



/*******************************************************************************
	Re-Load timer ID define List, Max Re-Load Timer  mount in this serial MCU
*******************************************************************************/
/*Timer Array ID list*/
#define MCU_mTimerArray_00	0u
#define MCU_mTimerArray_01	1u
#define MCU_mTimerArray_02	2u
#define MCU_mTimerArray_03	3u
#define MCU_mTimerArray_04	4u
#define MCU_mTimerArray_05	5u
#define MCU_mTimerArray_06	6u
#define MCU_mTimerArray_07	7u

#define MCU_mTimerArray_10	8u
#define MCU_mTimerArray_11	9u
#define MCU_mTimerArray_12	10u
#define MCU_mTimerArray_13	11u
#define MCU_mTimerArray_14	12u
#define MCU_mTimerArray_15	13u
#define MCU_mTimerArray_16	14u
#define MCU_mTimerArray_17	15u

#define MCU_mTimerArray_20	16u
#define MCU_mTimerArray_21	17u
#define MCU_mTimerArray_22	18u
#define MCU_mTimerArray_23	19u
#define MCU_mTimerArray_24	20u
#define MCU_mTimerArray_25	21u
#define MCU_mTimerArray_26	22u
#define MCU_mTimerArray_27	23u



/*******************************************************************************
	PPG ID define List, Max PPG  mount in this serial MCU
*******************************************************************************/

#define MCU_mPPG_ID_01	1u
#define MCU_mPPG_ID_02	2u
#define MCU_mPPG_ID_03	3u
#define MCU_mPPG_ID_04	4u
#define MCU_mPPG_ID_05	5u
#define MCU_mPPG_ID_06	6u
#define MCU_mPPG_ID_07	7u


#define MCU_mPPG_ID_11	9u
#define MCU_mPPG_ID_12	10u
#define MCU_mPPG_ID_13	11u
#define MCU_mPPG_ID_14	12u
#define MCU_mPPG_ID_15	13u
#define MCU_mPPG_ID_16	14u
#define MCU_mPPG_ID_17	15u


#define MCU_mPPG_ID_21	17u
#define MCU_mPPG_ID_22	18u
#define MCU_mPPG_ID_23	19u
#define MCU_mPPG_ID_24	20u
#define MCU_mPPG_ID_25	21u
#define MCU_mPPG_ID_26	22u
#define MCU_mPPG_ID_27	23u


/*******************************************************************************
	Serial ID define List, Max Serial  mount in this serial MCU
*******************************************************************************/
#define MCU_mSerial_ID_CSI00	0u
#define MCU_mSerial_ID_CSI01	1u
#define MCU_mSerial_ID_CSI10	2u
#define MCU_mSerial_ID_CSI11	3u

#define MCU_mSerial_ID_IIC11	3u
#define MCU_mSerial_ID_IIC20	4u

#define MCU_mSerial_ID_UART2	4u

#define MCU_mSerial_ID_UARTF0	5u	/*LIN-UART channel*/
#define MCU_mSerial_ID_UARTF1	6u	/*LIN-UART channel*/


/*******************************************************************************
	External interrupt ID define List, Max EINT  mount in this serial MCU
*******************************************************************************/

#define MCU_mEINT_ID_INT0	0U
#define MCU_mEINT_ID_INT1	1U
#define MCU_mEINT_ID_INT2	2U
#define MCU_mEINT_ID_INT3	3U
#define MCU_mEINT_ID_INT4	4U
#define MCU_mEINT_ID_INT5	5U
#define MCU_mEINT_ID_INT6	6U
#define MCU_mEINT_ID_INT7	7U
#define MCU_mEINT_ID_INT8	8U

/*******************************************************************************
	ADC ID define List, Max ADC  mount in this serial MCU
*******************************************************************************/

#define MCU_mADC_ID_AN0	0U
#define MCU_mADC_ID_AN1	1U
#define MCU_mADC_ID_AN2	2U
#define MCU_mADC_ID_AN3	3U
#define MCU_mADC_ID_AN4	4U
#define MCU_mADC_ID_AN5	5U
#define MCU_mADC_ID_AN6	6U
#define MCU_mADC_ID_AN7	7U
#define MCU_mADC_ID_AN8	8U
#define MCU_mADC_ID_AN9	9U
#define MCU_mADC_ID_AN10	10U
#define MCU_mADC_ID_AN11	11U
#define MCU_mADC_ID_AN12	12U
#define MCU_mADC_ID_AN13	13U
#define MCU_mADC_ID_AN14	14U
#define MCU_mADC_ID_AN15	15U
#define MCU_mADC_ID_AN16	16U
#define MCU_mADC_ID_AN17	17U
#define MCU_mADC_ID_AN18	18U
#define MCU_mADC_ID_AN19	19U
#define MCU_mADC_ID_AN20	20U
#define MCU_mADC_ID_AN21	21U
#define MCU_mADC_ID_AN22	22U
#define MCU_mADC_ID_AN23	23U


/*******************************************************************************
	DAM ID define List, Max DMA  mount in this serial MCU
*******************************************************************************/
#define MCU_mDMA_ID_DMA0	0U
#define MCU_mDMA_ID_DMA1	1U
#define MCU_mDMA_ID_DMA2	2U
#define MCU_mDMA_ID_DMA3	3U


/*******************************************************************************
	MCU running mode manage
	
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
			 
*******************************************************************************/
#define MCU_mRunMode_Halt	0U
#define MCU_mRunMode_Stop	1U



/*################################################
		Port model interface
#################################################*/
#if MCU_mPortModeEnable !=0u
	#if MCU_mPinDataOperEnable!=0u
		uint16 MCU_u16PinRead(uint16 u16PinID, uint8 *u8PinValue);
		uint16 MCU_u16PinWrite(uint16 u16PinID,uint8 u8Value);
	#endif

	#if MCU_mPinDirectOperEnable!=0u
		uint16 MCU_u16PinDirectCfg(uint16 u16PinID,uint8 u8InOut);
	#endif

	#if MCU_mPinPullUpOperEnable!=0u
		uint16 MCU_u16PinPullUpCfg(uint16 u16PinID,uint8 u8OnOff);
	#endif

#endif

/*################################################
		re-load timer model interface
#################################################*/
#if MCU_mTimerModelEnable!=0u
		uint16 MCU_u16ReloadTimerStop(uint16 u16TimerID);
		uint16 MCU_u16ReloadTimerStartDefConf(uint16 u16TimerID);

	#if MCU_mTimerIntervalChgEnable!=0u
		uint16 MCU_u16ReloadTimerChgInterval(uint16 u16TimerID,uint16 u16Interval_us);
	#endif
	
	#if MCU_mTimerDeintiEnable!=0u
		void MCU_vTimerArrayDeinit(void);
	#endif

	
#endif


/*################################################
		PPG model interface
#################################################*/
#if MCU_mPPGModeEnable!=0u

	#if MCU_mPPGDeInitEnable!=0u
		void MCU_vPPGDeInit(void);
	#endif
		uint16 MCU_u16PPGSetHz(uint16 u16PPG_ID, uint16 u16Hz,uint16 u16Duty);
#endif


/*################################################
		Input Captrue Unit model interface
#################################################*/
#if MCU_mICUmodelEnable!=0u
		uint16 MCU_u16ICUDetTrigCrtl(uint16 u16Channel, uint8 u8DetEdge);
		uint16 MCU_u16ICUstart(uint16 u16Channel,uint8 u8DetEdge);
		uint16 MCU_u16ICUstop(uint16 u16Channel);

	#if MCU_mICUDeInitFuncEnable!=0u
		void MCU_vICUDeInit(void);
	#endif

#endif

/*################################################
		frenquency divide Unit model interface
#################################################*/
#if MCU_mFreDivdmodelEnable!=0u

	uint16 MCU_u16FreDivdChg(uint16 u16Channel, uint16 u16FreDiv);
	uint16 MCU_u16FreDivdStop(uint16 u16Channel);

#endif


/*################################################
		Counter Unit model interface
#################################################*/
#if MCU_mCountmodelEnable!=0u

	uint16 MCU_u16CounterChg(uint16 u16Channel,uint16 u16Number,uint8 u8Edge);
	uint16 MCU_u16CounterStop(uint16 u16Channel);
	uint16 MCU_u16CounterStart(uint16 u16Channel,uint16 u16Number,uint8 u8Edge);

#endif


/*################################################
		IIC model interface
#################################################*/
#if MCU_mIICmodelEnable!=0u

		uint16 MCU_u16IIC_MasterStartCondition(uint8 u8I2C_masterID);
		uint16 MCU_u16IIC_MasterStopCondition(uint8 u8I2C_masterID);
		uint16 MCU_u16IIC_MasterSend(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 pDataHead[], uint16 u16Lenth);
		uint16 MCU_u16IIC_MasterRec(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 *pDataHead, uint16 u16Lenth);
		uint16 MCU_u16IIC_MasterChgToRecMode(uint16 u16Ch);
		uint16 MCU_u16IIC_MasterChgToSendMode(uint16 u16Ch);

	#if MCU_mIICdeinitEnable!=0u
		void MCU_vIICdeinit(void);
	#endif

#endif

/*################################################
		CSI model interface
#################################################*/
#if MCU_mCSImodelEnable!=0u

		uint16 MCU_u16CSI_MasterTransfer(uint16 u16CsiID,uint16 pu16SendDataHead[], uint16 pu16RecDataHead[],uint16 u16DataLen);

	#if MCU_mCSIdeinitEnable!=0u
		void MCU_vCSIdeinit(void);
	#endif

#endif

/*################################################
		serial-UART model interface
#################################################*/
#if MCU_mSerialUartmodelEnable !=0u

		uint16 MCU_u16SerialUartSend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen);
		uint16 MCU_u16SerialUartCtrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable);
	#if MCU_mUARTDeInitFuncEnable!=0u
		void MCU_vSerialUartDeint(void);
	#endif
	
#endif

/*################################################
		Lin-UART model interface
#################################################*/

#if MCU_mLinUart_modelEnable!=0u
		uint16 MCU_u16LinUartSend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen);
		uint16 MCU_u16LinUartCtrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable);

	#if MCU_mLinUart_DeInitFuncEnable!=0u
		void MCU_vLinUart_Deinit(void);	
	#endif
	
#endif

#if ((MCU_mLinUart_DeInitFuncEnable!=0u) ||(MCU_mSerialUartmodelEnable !=0u))

		uint16 MCU_u16UARTsend(uint16 u16channel, uint8 pu8DataHead[], uint16 u16SendLen);
		uint16 MCU_u16UARTctrl(uint16 u16channel, uint8 u8SendEnable, uint8 u8RecEnable);

#endif

/*################################################
		interrupt priority control model interface
#################################################*/
#if MCU_mINTPriorityChgEnable!=0u

		uint16 MCU_u16ChangeVectorPriority(uint16 u16VectNum,uint16 u16TargePri);
		
#endif

/*################################################
		interrupt control model interface
#################################################*/
		uint16 MCU_u16InterruptFlagClean(uint16 u16VectNum);
		uint16 MCU_u16InterruptCtrl(uint16 u16VectNum,uint8 u8IntEnable);


/*################################################
		External Interrupt model interface
#################################################*/
#if MCU_mEINTModelEnable!=0u

	#if MCU_mEINTtrigChgFuncEnable!=0u
		uint16 MCU_u16EINTchgIntCondition(uint16 u16EintID,uint8 u8NewTrigerCondition);
	#endif

	#if MCU_mEINTOnOffCtrlFuncEnable!=0u
		uint16 MCU_u16EINTenable(uint16 u16EintID);
		uint16 MCU_u16EINTdisable(uint16 u16EintID);
	#endif

	#if MCU_mEINTDeInitFuncEnable!=0u
		void MCU_vEINTDeInit(void);
	#endif
	
#endif

/*################################################
		DMA model interface
#################################################*/
#if MCU_mDMAmodelEnable !=0u

		uint16 MCU_u16DMAenable(uint8 u8DMAchn);
		uint16 MCU_u16DMAStartTrig(uint8 u8DMAchn);

	#if MCU_mDMADeInitFuncEnable
		  void MCU_vDMADeInit(void);
	#endif

#endif

/*################################################
		ADC model interface
#################################################*/
#if MCU_mADCModelEnable!=0u

		uint16 MCU_u16ADCstart(void);
		uint16 MCU_u16ADCstop(void);
		uint16 MCU_u16ADCsleep(void);
		uint16 MCU_u16ADCwakeUp(void);
		uint16 MCU_u16ADCgetResault(uint8 u8ChannelID, uint16 *u16AD_Resault);
		
	#if MCU_mADCDeInitFuncEnable!=0u
		void MCU_vADCDeInit(void);
	#endif
	
#endif



/*################################################
		MCU Run mode control interface
#################################################*/
uint16 MCU_u16RunModeCtrl(uint8 u8ExpMode);


void MCU_vWatchDogClean(void);
void MCU_vReset(void);

void MCU_vNotExpINT(void);
void MCU_vNotExpINT_u8(uint8 u8Dummy);
void MCU_vNotExpINT_u16(uint16 u16Dummy);
void MCU_vNotExpINT_u32_8(uint32 u32Dummy,uint8 u8DUMMY);



#endif /*end of this file*/


