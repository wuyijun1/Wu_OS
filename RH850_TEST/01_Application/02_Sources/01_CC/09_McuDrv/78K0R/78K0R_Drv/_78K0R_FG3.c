/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial, special chip is upd78F1xxx
| File Name: _78K0R_FG3.c
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
********************************************************************************/
#ifdef MCU_C

/*###########################################################
		ADC resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mADCresourceMount_Mask	0x00FFFFFFUL

/*###########################################################
		Time resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mTimerResourceMount_Mask	0x00FFFFFFUL

/*###########################################################
		Time I/O pin resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mTimerNormalPinMount_Mask	0x00FFFFFFUL

/*###########################################################
		Time I/O Re-locate pin resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mTimerRelocatPinMount_Mask	0x0000FFFFUL

/*###########################################################
		EINT resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mEINTresourceMount_Mask	0x01FFU

/*###########################################################
		DMA resource mounted in 78K0R_FG3
###########################################################*/
#define MCU_mDMAresourceMount_Mask	0x000FU
 


#if MCU_mPortModeEnable!=0u

const MCU_tstResourceMount_Port MCU_stResourcePort=
{

/*port-data*/
/*===================================================================================*/
			/*Port:	0		1		2		3		4		5		6		7		8		9*/	
				{	0x0Fu,	0xFFu,	0x00u,	0x07u,	0xFFu,	0xFFu,	0xFFu,	0xFFu,	0xFFu,	0xFFu,\
			/*Port:	10		11		12		13		14		15		*/	
					0xFFu,	0x00u,	0xFFu,	0x01u,	0x01u,	0xFFu,	},

/*port-direc*/	
/*===================================================================================*/
			/*Port:	0		1		2		3		4		5		6		7		8		9*/	
				{	0x0Fu,	0xFFu,	0x00u,	0x07u,	0xFFu,	0xFFu,	0xFFu,	0xFFu,	0xFFu,	0xFFu,\
			/*Port:	10		11		12		13-0 output ONLY 	14		15		*/	
					0xFFu,	0x00u,	0xFFu,	0x00u,			0x01u,	0xFFu,	},

/*port-Pull-up(it will active Only input mode )*/				
/*===================================================================================*/
			/*Port: 	0		1		2		3		4		5		6		7		8		9*/ 
				{	0x0Fu,	0xFFu,	0x00u,	0x07u,	0xFFu,	0xFFu,	0xFFu,	0xFFu,	0x00u,	0x00u,\
			/*Port:	10		11		12		13-0 output ONLY 	14		15		*/	
					0x00u,	0x00u,	0xFFu,	0x00u,			0x01u,	0xFFu,	},
};
#endif


#if ((MCU_mFreDivdmodelEnable!=0u)||(MCU_mTimerModelEnable!=0u)\
	||(MCU_mPPGModeEnable!=0u)||(MCU_mCountmodelEnable!=0u)\
	||(MCU_mICUmodelEnable!=0u))

/*############################################################
			16Bit Timer resource mounted in 78K0R_FG3
##############################################################*/
const MCU_tstResourceMount_TimerArray MCU_stResourceTimerArray=
{
	MCU_mTimerResourceMount_Mask,			/*record the mounted timer, one bit is one timer mounted*/
	MCU_mTimerNormalPinMount_Mask,
	MCU_mTimerRelocatPinMount_Mask,
	{0x2cu,0x2eu,0x30u,0x32u,0x42u,0x44u,0x46u,0x48u,	/*group 0*/\
	  0x56u,0x58u,0x5au,0x5cu,0x66u,0x68u,0x6au,0x6cu,	/*group 1*/\
	  0x6eu,0x70u,0x72u,0x74u,0xFFu,0x76u,0xFFu,0x78u,	/*group 2-TM24/TM26 not interrupt voctor, it share with TM25/TM27*/\
	},	/*record the mounted timer vector number*/
};

#endif


/*############################################################
			interrupt resource mounted in 78K0R_FG3
	one bit is one vector has mounted 
##############################################################*/

const uint8 MCU_au8VectorMask[8u]=
{
	0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu
};

#if MCU_mEINTModelEnable!=0u
/*############################################################
			External Interrupt resource mounted in 78K0R_FG3
##############################################################*/
const MCU_tstResourceMnt_EINT MCU_stResourceEINT=
{
/*============================================================================*/					
/*Lower_Pin*/	0x01FFU,
					
/*============================================================================*/					
/*Higher_Pin_R*/	0x000CU,

/*============================================================================*/					
/*EINT_ID:*/		/*	0		1		2		3		4		5		6		7			*/		
/*VectorNum*/	{	8u,		0x0AU,	0x0CU,	0x0EU,	0x10U,	0x12U,	0x4AU,	0x4CU,		
				/*	8		*/
					0x02AU,	},
};

#endif

#if MCU_mADCModelEnable!=0u
/*############################################################
			ADC resource mounted in 78K0R_FG3
##############################################################*/
const MCU_tstResourceMnt_ADC MCU_stResourceADC=
{
	0x34u,								/*interrupt number*/
	MCU_mADCresourceMount_Mask,		/*channel mounted mask word*/
};
#endif

#if ((MCU_mCSImodelEnable !=0u) || (MCU_mSerialUartmodelEnable !=0u) ||(MCU_mIICmodelEnable!=0u))

/*############################################################
			serial-array resource mounted in 78K0R_FG3
##############################################################*/
const MCU_tstResourceMnt_Serial MCU_stResourceSerial=
{
	0x003fU,	/*pin mount mask*/
	0x000FU,	/*CSI channel mask*/
	0x0018U,	/*IIC channel mask*/
	0x0010U,	/*UART-2 channel moust mask*/
	{0x16u,0x18u,0x3eu,0x40u,0x60u,0x62u}, /*vector list in serial interrupt*/
};
#endif

#if MCU_mLinUart_modelEnable!=0u
/*############################################################
			Lin-Uart resource mounted in 78K0R_FG3
##############################################################*/
const MCU_tstResourceMnt_UARTF MCU_stResourceLinUart=
{
	0x0003U,	/*LIN-UART pin moust*/
	0x0002U,	/*LIN-UART R_pin moust*/
	{0x24u,0x38u},	/*RX vector*/
	{0x22u,0x36u},	/*TX vector*/
	{0x26u,0x3Au}	/*Error vector*/
};
#endif

/*############################################################
			DMA resource mounted in 78K0R_FG3
##############################################################*/
#if MCU_mDMAmodelEnable !=0u

const MCU_tstResourceMnt_DMA MCU_stResourceDMA=
{
	0x0fu,	/*which channel DMA mouonted mask byte*/
	
	/*DMA finish vector*/
	{INTDMA0_vect,INTDMA1_vect,INTDMA2_vect,INTDMA3_vect},		
	
/*CH0_1 control list*/	{0xFFU,	INTTM01_vect,	INTTM03_vect,	INTTM05_vect,	INTTM07_vect,
							INTTM11_vect	,	INTTM13_vect,	INTCSI10_vect,	INTLT0_vect,		
							INTLR0_vect,		INTLT1_vect,		INTLR1_vect,		INTCSI00_vect,
							INTCSI01_vect,	INTMD_vect,		INTAD_vect},
							
/*CH2_3 control list*/	{0xFFU,	INTTM15_vect,	INTTM17_vect,	INTTM21_vect,	INTTM23_vect,
							INTIIC11_vect,	INTIIC20_vect,	INTSR2_vect,		INTLT0_vect,		
							INTLR0_vect,		INTLT1_vect,		INTLR1_vect,		INTCSI00_vect,
							INTCSI01_vect,	INTMD_vect,		INTAD_vect},
};

#endif



#endif/*end of this file*/


