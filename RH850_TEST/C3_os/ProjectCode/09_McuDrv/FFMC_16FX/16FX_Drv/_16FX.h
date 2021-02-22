/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial
| File Name: _16FX.h
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
********************************************************************************/

#ifndef FFMC_16FX_H
#define FFMC_16FX_H


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

/*Pin Index in Port-18*/
#define MCU_mPinID_P18_0	0x1200u
#define MCU_mPinID_P18_1	0x1201u
#define MCU_mPinID_P18_2	0x1202u
#define MCU_mPinID_P18_3	0x1203u
#define MCU_mPinID_P18_4	0x1204u
#define MCU_mPinID_P18_5	0x1205u
#define MCU_mPinID_P18_6	0x1206u
#define MCU_mPinID_P18_7	0x1207u

/*Pin Index in Port-19*/
#define MCU_mPinID_P19_0	0x1300u
#define MCU_mPinID_P19_1	0x1301u
#define MCU_mPinID_P19_2	0x1302u
#define MCU_mPinID_P19_3	0x1303u
#define MCU_mPinID_P19_4	0x1304u
#define MCU_mPinID_P19_5	0x1305u
#define MCU_mPinID_P19_6	0x1306u
#define MCU_mPinID_P19_7	0x1307u


/*******************************************************************************
	Re-Load timer ID define List, Max Re-Load Timer  mount in this serial MCU
*******************************************************************************/
/*Re-Load Timer ID list*/
#define MCU_mReLoadTimer_0	0x00u
#define MCU_mReLoadTimer_1	0x01u
#define MCU_mReLoadTimer_2	0x02u
#define MCU_mReLoadTimer_3	0x03u
#define MCU_mReLoadTimer_6	0x04u

/*******************************************************************************
	PPG ID define List, Max PPG  mount in this serial MCU
*******************************************************************************/

#define MCU_mPPG_ID_PPG0	0u
#define MCU_mPPG_ID_PPG1	1u
#define MCU_mPPG_ID_PPG2	2u
#define MCU_mPPG_ID_PPG3	3u
#define MCU_mPPG_ID_PPG4	4u
#define MCU_mPPG_ID_PPG5	5u
#define MCU_mPPG_ID_PPG6	6u
#define MCU_mPPG_ID_PPG7	7u
#define MCU_mPPG_ID_PPG8	8u
#define MCU_mPPG_ID_PPG9	9u
#define MCU_mPPG_ID_PPG10	10u
#define MCU_mPPG_ID_PPG11	11u
#define MCU_mPPG_ID_PPG12	12u
#define MCU_mPPG_ID_PPG13	13u
#define MCU_mPPG_ID_PPG14	14u
#define MCU_mPPG_ID_PPG15	15u

#define MCU_mPPG_ID_PPG0_R	16u
#define MCU_mPPG_ID_PPG1_R	17u
#define MCU_mPPG_ID_PPG2_R	18u
#define MCU_mPPG_ID_PPG3_R	19u
#define MCU_mPPG_ID_PPG4_R	20u
#define MCU_mPPG_ID_PPG5_R	21u
#define MCU_mPPG_ID_PPG6_R	22u
#define MCU_mPPG_ID_PPG7_R	23u
#define MCU_mPPG_ID_PPG8_R	24u
#define MCU_mPPG_ID_PPG9_R	25u
#define MCU_mPPG_ID_PPG10_R	26u
#define MCU_mPPG_ID_PPG11_R	27u
#define MCU_mPPG_ID_PPG12_R	28u
#define MCU_mPPG_ID_PPG13_R	29u
#define MCU_mPPG_ID_PPG14_R	30u
#define MCU_mPPG_ID_PPG15_R	31u

#define MCU_mPPG_ID_PPG0_B	32U
#define MCU_mPPG_ID_PPG1_B	33U
#define MCU_mPPG_ID_PPG2_B	34U
#define MCU_mPPG_ID_PPG3_B	35U
#define MCU_mPPG_ID_PPG4_B	36U
#define MCU_mPPG_ID_PPG5_B	37U
#define MCU_mPPG_ID_PPG6_B	38U
#define MCU_mPPG_ID_PPG7_B	39U
#define MCU_mPPG_ID_PPG8_B	40U
#define MCU_mPPG_ID_PPG9_B	41U
#define MCU_mPPG_ID_PPG10_B	42U
#define MCU_mPPG_ID_PPG11_B	43U
#define MCU_mPPG_ID_PPG12_B	44U
#define MCU_mPPG_ID_PPG13_B	45U
#define MCU_mPPG_ID_PPG14_B	46U
#define MCU_mPPG_ID_PPG15_B	47U


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
#define MCU_mEINT_ID_INT9	9U
#define MCU_mEINT_ID_INT10	10U
#define MCU_mEINT_ID_INT11	11U
#define MCU_mEINT_ID_INT12	12U
#define MCU_mEINT_ID_INT13	13U
#define MCU_mEINT_ID_INT14	14U
#define MCU_mEINT_ID_INT15	15U

#define MCU_mEINT_ID_INT0_R	16U
#define MCU_mEINT_ID_INT1_R	17U
#define MCU_mEINT_ID_INT2_R	18U
#define MCU_mEINT_ID_INT3_R	19U
#define MCU_mEINT_ID_INT4_R	20U
#define MCU_mEINT_ID_INT5_R	21U
#define MCU_mEINT_ID_INT6_R	22U
#define MCU_mEINT_ID_INT7_R	23U
#define MCU_mEINT_ID_INT8_R	24U
#define MCU_mEINT_ID_INT9_R	25U
#define MCU_mEINT_ID_INT10_R	26U
#define MCU_mEINT_ID_INT11_R	27U
#define MCU_mEINT_ID_INT12_R	28U
#define MCU_mEINT_ID_INT13_R	29U
#define MCU_mEINT_ID_INT14_R	30U
#define MCU_mEINT_ID_INT15_R	31U

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
#define MCU_mADC_ID_AN24	24U
#define MCU_mADC_ID_AN25	25U
#define MCU_mADC_ID_AN26	26U
#define MCU_mADC_ID_AN27	27U
#define MCU_mADC_ID_AN28	28U
#define MCU_mADC_ID_AN29	29U
#define MCU_mADC_ID_AN30	30U
#define MCU_mADC_ID_AN31	31U


/*******************************************************************************
	DAM ID define List, Max DMA  mount in this serial MCU
*******************************************************************************/


#define MCU_mDMA_ID_DMA0	0U
#define MCU_mDMA_ID_DMA1	1U
#define MCU_mDMA_ID_DMA2	2U
#define MCU_mDMA_ID_DMA3	3U
#define MCU_mDMA_ID_DMA4	4U
#define MCU_mDMA_ID_DMA5	5U
#define MCU_mDMA_ID_DMA6	6U
#define MCU_mDMA_ID_DMA7	7U
#define MCU_mDMA_ID_DMA8	8U
#define MCU_mDMA_ID_DMA9	9U
#define MCU_mDMA_ID_DMA10	10U
#define MCU_mDMA_ID_DMA11	11U
#define MCU_mDMA_ID_DMA12	12U
#define MCU_mDMA_ID_DMA13	13U
#define MCU_mDMA_ID_DMA14	14U
#define MCU_mDMA_ID_DMA15	15U


/*******************************************************************************
	UART ID define List, Max UART  mount in this serial MCU
*******************************************************************************/


#define MCU_mUART_ID_UART0	0U
#define MCU_mUART_ID_UART1	1U
#define MCU_mUART_ID_UART2	2U
#define MCU_mUART_ID_UART3	3U
#define MCU_mUART_ID_UART4	4U
#define MCU_mUART_ID_UART5	5U
#define MCU_mUART_ID_UART6	6U
#define MCU_mUART_ID_UART7	7U

#define MCU_mUART_ID_UART0_R	8U
#define MCU_mUART_ID_UART1_R	9U
#define MCU_mUART_ID_UART2_R	10U
#define MCU_mUART_ID_UART3_R	11U
#define MCU_mUART_ID_UART4_R	12U
#define MCU_mUART_ID_UART5_R	13U
#define MCU_mUART_ID_UART6_R	14U
#define MCU_mUART_ID_UART7_R	15U

/*******************************************************************************
	IIC ID define List, Max UART  mount in this serial MCU
*******************************************************************************/
#define MCU_mIIC_ID_IIC0	0U


/*******************************************************************************
	MCU running mode manage

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
*******************************************************************************/
#define MCU_mRunMode_Normal	0U
#define MCU_mRunMode_Sleep	1U
#define MCU_mRunMode_Timer	2U
#define MCU_mRunMode_Stop	3U



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

	#if MCU_mPinPullDownOperEnable!=0u
		uint16 MCU_u16PinPullDownCfg(uint16 u16PinID,uint8 u8OnOff);
	#endif

	#if MCU_mPinHighDrvOperEnable!=0u
		uint16 MCU_u16PinHighDrvCfg(uint16 u16PinID,uint8 u8OnOff);
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
	
#endif


/*################################################
		interrupt priority control model interface
#################################################*/
#if MCU_mINTPriorityChgEnable!=0u
		uint16 MCU_u16ChangeVectorPriority(uint16 u16VectNum,uint16 u16TargePri);
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
		uint16 MCU_u16ADCgetResault(uint8 u8ChannelID, uint16 *u16AD_Resault);
		
	#if MCU_mADCDeInitFuncEnable!=0u
		void MCU_vADCDeInit(void);
	#endif
	
#endif


/*################################################
		UART model interface
#################################################*/
#if MCU_mUARTmodelEnable !=0u

		uint16 MCU_u16UARTctrl(uint8 u8channel, uint8 u8TxCtrl, uint8 u8RxCtrl);
		uint16 MCU_u16UARTsend(uint8 u8channel, uint8 *DataHead, uint16 u16SendLen);
	#if MCU_mUARTDeInitFuncEnable!=0u
		void MCU_vUARTDeInit(void);
	#endif
	
#endif


/*################################################
		LCD model interface
#################################################*/
#if MCU_mLCDmodelEnable!=0u
	uint16 MUC_u16LcdDisplayUpdate(uint8 pu8VRAMHead[], uint8 u8BuffLen);
#endif


/*################################################
		Input Captrue Unit model interface
#################################################*/
#if MCU_mICUmodelEnable!=0u
		uint16 MCU_u16ICUDetTrigCrtl(uint8 u8Channel, uint8 u8DetEdge);
		uint16 MCU_u16ICUstart(uint8 u8Channel,uint8 u8DetEdge);
		uint16 MCU_u16ICUstop(uint8 u8Channel);

	#if MCU_mIICUDeInitFuncEnable!=0u
		void MCU_vICUDeInit(void);
	#endif

#endif

/*################################################
		IIC model interface
#################################################*/
#if MCU_mIICmodelEnable!=0u

		uint16 MCU_u16IIC_MasterStartCondition(uint8 u8I2C_masterID);
		uint16 MCU_u16IIC_MasterStopCondition(uint8 u8I2C_masterID);
		uint16 MCU_u16IIC_MasterSend(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 pDataHead[], uint16 u16Lenth);
		uint16 MCU_u16IIC_MasterRec(uint8 u8I2C_masterID,uint8 u8SalveDevice_index, uint8 *pDataHead, uint16 u16Lenth);

#endif
void MCU_vWatchDogClean(void);
void MCU_vReset(void);
void MCU_vNotExpINT(void);
void MCU_vNotExpINT_u8(uint8 u8Dummy);
void MCU_vNotExpINT_u32_8(uint32 u32Dummy,uint8 u8DUMMY);
uint16 MCU_u16RunModeCtrl(uint8 u8ExpMode, uint8 u8PinHighZ );



#endif /*end of this file*/


