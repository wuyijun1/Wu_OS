/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial, special chip is MB96F69xRx
| File Name: _16FX_IO_690.c
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
#ifdef MCU_C

/*###########################################################
		ADC resource mounted in MB96F69x
###########################################################*/
#define MCU_mADCresourceMount_Mask	0xFFFFDDDCUL

/*###########################################################
		ReLoadTime resource mounted in MB96F69x
###########################################################*/
#define MCU_mReTimerResourceMount_Mask	0x001Fu

/*###########################################################
		EINT resource mounted in MB96F69x
###########################################################*/
#define MCU_mEINTresourceMount_Mask	0xFFFFU

/*###########################################################
		DMA resource mounted in MB96F69x
###########################################################*/
#define MCU_mDMAresourceMount_Mask	0x000FU
 
/*###########################################################
		16bit PPG resource mounted in MB96F69x
###########################################################*/
#define MCU_mPPGresourceMount_Mask	0xC0FFU

/*###########################################################
		UART resource mounted in MB96F69x
###########################################################*/
#define MCU_mUARTresourceMount_SINn		0x0017U
#define MCU_mUARTresourceMount_SINn_R	0x0020U

/*###########################################################
		IIC resource mounted in MB96F69x
###########################################################*/
#define MCU_mIICresourceMount_Mask	0x0003U

/*###########################################################
		Input Captrue resource mounted in MB96F69x
###########################################################*/
#define MCU_mICUresourceMount_Mask	0x00f3U


/*###############################################################################

X0/X1	--[PLL]->   	CLKPLL	 ----[SC1S]--->	CLKS1	---[PC1D]---->CLKP1
							|						|
							|						|
							|						---[BCD]----->CLKB	(core bus)
							|
							|
							------[SC2S]--->	  CLKS2	----[PC2D]--->CLKP2

###############################################################################


#########################################################################
		Pin function list
#########################################################################

	PinNum	Function mounted in Pin
=================================================
	1			Supply	Vss				
	2			C					
	3	P03_7	INT1	SIN1	SEG40		
	4	P13_0	INT2	SOT1	SEG41		
	5	P13_1	INT3	SCK1	SEG42		
	6	P13_2	PPG0	TIN0	FRCK1	SEG43	
	7	P13_3	PPG1	TOT0	WOT	SEG44	
	8	P13_4	SIN0		INT6	SEG45		
	9	P13_5	SOT0	ADTG	INT7		
	10	P13_6	SCK0	CKOTX0			
	11	P04_4	PPG3	SDA0			
	12	P04_5	PPG4	SCL0			
	13	P06_2	AN2		INT5	SIN5		
	14	P06_3	AN3		FRCK0			
	15	P06_4	AN4		IN0	TTG0	TTG4	
	16	P06_6	AN6		TIN1	IN4_R		
	17	P06_7	AN7		TOT1	IN5_R		
	18			Supply	AVcc				
	19			AVRH					
	20			AVRL					
	21			Supply	AVss				
	22	P05_0	AN8				
	23	P05_2	AN10	OUT2	SGO1		
	24	P05_3	AN11	OUT3	SGA1		
	25			Supply	Vcc				
	26			Supply	Vss				
	27	P05_4	AN12	INT2_R	WOT_R		
	28	P05_6	AN14	TIN2	SGO1_R		
	29	P05_7	AN15	TOT2	SGA1_R		
	30	P08_0	PWM1P0	AN16			
	31	P08_1	PWM1M0	AN17			
	32	P08_2	PWM2P0	AN18			
	33	P08_3	PWM2M0	AN19			
	34	P08_4	PWM1P1	AN20			
	35			Supply	DVcc				
	36			Supply	DVss				
	37	P08_5	PWM1M1	AN21			
	38	P08_6	PWM2P1	AN22	PPG6_B		
	39	P08_7	PWM2M1	AN23	PPG7_B		
	40	P09_0	PWM1P2	AN24			
	41	P09_1	PWM1M2	AN25			
	42	P09_2	PWM2P2	AN26			
	43	P09_3	PWM2M2	AN27			
	44			Supply	DVcc				
	45			Supply	DVss				
	46	P10_0	PWM1P4	SIN2	TIN3	INT11	AN28
	47	P10_1	PWM1M4	SOT2	TOT3	AN29	
	48	P10_2	PWM2P4	SCK2	PPG6	AN30	
	49	P10_3	PWM2M4	PPG7	AN31		
	50			Supply	Vcc				
	51			Supply	Vss				
	52			DEBUG					
	53	P17_0					
	54			MD					
	55			X0					
	56			X1					
	57			Supply	Vss				
	58	P04_0	X0A				
	59	P04_1	X1A				
	60			RSTX					
	61	P11_0	COM0				
	62	P11_1	COM1	PPG0_R			
	63	P11_2	COM2	PPG1_R			
	64	P11_3	COM3	PPG2_R			
	65	P11_4	SEG0	PPG3_R			
	66	P11_5	SEG1	PPG4_R			
	67	P11_6	SEG2	FRCK0_R			
	68	P11_7	SEG3	IN0_R			
	69	P12_0	SEG4	IN1_R			
	70	P12_3	SEG7	OUT2_R			
	71	P12_7	SEG11	INT1_R			
	72	P00_0	SEG12	INT3_R			
	73	P00_1	SEG13	INT4_R			
	74	P00_2	SEG14	INT5_R			
	75			Supply	Vcc				
	76			Supply	Vss				
	77	P00_3	SEG15	INT6_R			
	78	P00_4	SEG16	INT7_R			
	79	P00_5	SEG17	IN6	TTG2	TTG6	
	80	P00_6	SEG18	IN7	TTG3	TTG7	
	81	P00_7	SEG19	SGO0	INT14		
	82	P01_0	SEG20	SGA0			
	83	P01_1	SEG21	CKOT1	OUT0		
	84	P01_2	SEG22	CKOTX1	OUT1	INT15	
	85	P01_3	SEG23	PPG5			
	86	P01_4	SEG24	SIN4	INT8		
	87	P01_5	SEG25	SOT4			
	88	P01_6	SEG26	SCK4	TTG12		
	89	P01_7	SEG27	CKOTX1_R	INT9	TTG13	
	90	P02_0	SEG28	CKOT1_R	INT10	TTG14	
	91	P02_2	SEG30	IN7_R		CKOT0_R	INT12	
	92	P02_5	SEG33	OUT0_R	INT13	SIN5_R	
	93	P03_0	V0	SEG36	PPG4_B		
	94	P03_1	V1	SEG37	PPG5_B		
	95	P03_2	V2	SEG38	PPG14_B		SOT5_R	
	96	P03_3	V3	SEG39	PPG15_B		SCK5_R	
	97	P03_4	RX0	INT4			
	98	P03_5	TX0				
	99	P03_6	INT0	NMI			
	100			Supply	Vcc				

***********************************************************************/


/*############################################################
			Pin resource mounted in MB96F69xRx
##############################################################

===========
===Port_00===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin00_0		1		1		1		0		0		1		pin 72 
		Pin00_1		1		1		1		0		0		1		pin 73
		Pin00_2		1		1		1		0		0		1		pin 74
		Pin00_3		1		1		1		0		0		1		pin 77
		Pin00_4		1		1		1		0		0		1		pin 78
		Pin00_5		1		1		1		0		0		1		pin 79
		Pin00_6		1		1		1		0		0		1		pin 80
		Pin00_7		1		1		1		0		0		1		pin 81
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_01===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================	
		Pin01_0		1		1		1		0		0		1		pin 82
		Pin01_1		1		1		1		0		0		1		pin 83
		Pin01_2		1		1		1		0		0		1		pin 84
		Pin01_3		1		1		1		0		0		1		pin 85
		Pin01_4		1		1		1		0		0		1		pin 86
		Pin01_5		1		1		1		0		0		1		pin 87
		Pin01_6		1		1		1		0		0		1		pin 88
		Pin01_7		1		1		1		0		0		1		pin 89
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_02===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin02_0		1		1		1		0		0		1		pin 90
		Pin02_1		####################################This_Pin_Not_Mount
		Pin02_2		1		1		1		0		0		1		pin 91
		Pin02_3		####################################This_Pin_Not_Mount
		Pin02_4		####################################This_Pin_Not_Mount
		Pin02_5		1		1		1		0		0		1		pin 92
		Pin02_6		####################################This_Pin_Not_Mount
		Pin02_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


===========
===Port_03===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin03_0		1		1		1		0		0		1		pin 93
		Pin03_1		1		1		1		0		0		1		pin 94
		Pin03_2		1		1		1		0		0		1		pin 95
		Pin03_3		1		1		1		0		0		1		pin 96
		Pin03_4		1		1		1		0		0		1		pin 97
		Pin03_5		1		1		1		0		0		1		pin 98
		Pin03_6		1		1		1		0		0		1		pin 99
		Pin03_7		1		1		1		0		0		1		pin 3
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_04===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin04_0		1		1		1		0		0		1		pin 58
		Pin04_1		1		1		1		0		0		1		pin 59
		Pin04_2		####################################This_Pin_Not_Mount
		Pin04_3		####################################This_Pin_Not_Mount
		Pin04_4		1		1		1		0		0		1		pin 11
		Pin04_5		1		1		1		0		0		1		pin 12
		Pin04_6		####################################This_Pin_Not_Mount
		Pin04_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_05===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================			
		Pin05_0		1		1		1		0		0		1		pin 22
		Pin05_1		####################################This_Pin_Not_Mount
		Pin05_2		1		1		1		0		0		1		pin 23
		Pin05_3		1		1		1		0		0		1		pin 24
		Pin05_4		1		1		1		0		0		1		pin 27
		Pin05_5		####################################This_Pin_Not_Mount
		Pin05_6		1		1		1		0		0		1		pin 28
		Pin05_7		1		1		1		0		0		1		pin 29
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


===========
===Port_06===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin06_0		####################################This_Pin_Not_Mount
		Pin06_1		####################################This_Pin_Not_Mount
		Pin06_2		1		1		1		0		0		1		pin 13
		Pin06_3		1		1		1		0		0		1		pin 14
		Pin06_4		1		1		1		0		0		1		pin 15
		Pin06_5		####################################This_Pin_Not_Mount
		Pin06_6		1		1		1		0		0		1		pin 16
		Pin06_7		1		1		1		0		0		1		pin 17
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_07===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin07_0		####################################This_Pin_Not_Mount
		Pin07_1		####################################This_Pin_Not_Mount
		Pin07_2		####################################This_Pin_Not_Mount
		Pin07_3		####################################This_Pin_Not_Mount
		Pin07_4		####################################This_Pin_Not_Mount
		Pin07_5		####################################This_Pin_Not_Mount
		Pin07_6		####################################This_Pin_Not_Mount
		Pin07_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


===========
===Port_08===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin08_0		1		1		1		1		1		1		pin 30
		Pin08_1		1		1		1		1		1		1		pin 31
		Pin08_2		1		1		1		1		1		1		pin 32
		Pin08_3		1		1		1		1		1		1		pin 33
		Pin08_4		1		1		1		1		1		1		pin 34
		Pin08_5		1		1		1		1		1		1		pin 37
		Pin08_6		1		1		1		1		1		1		pin 38
		Pin08_7		1		1		1		1		1		1		pin 39
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_09===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================			
		Pin09_0		1		1		1		1		1		1		pin 40
		Pin09_1		1		1		1		1		1		1		pin 41
		Pin09_2		1		1		1		1		1		1		pin 42
		Pin09_3		1		1		1		1		1		1		pin 43
		Pin09_4		####################################This_Pin_Not_Mount
		Pin09_5		####################################This_Pin_Not_Mount
		Pin09_6		####################################This_Pin_Not_Mount
		Pin09_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_10===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin10_0		1		1		1		1		1		1		pin 46
		Pin10_1		1		1		1		1		1		1		pin 47
		Pin10_2		1		1		1		1		1		1		pin 48
		Pin10_3		1		1		1		1		1		1		pin 49
		Pin10_4		####################################This_Pin_Not_Mount
		Pin10_5		####################################This_Pin_Not_Mount
		Pin10_6		####################################This_Pin_Not_Mount
		Pin10_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


===========
===Port_11===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================			
		Pin11_0		1		1		1		0		0		1		pin 61
		Pin11_1		1		1		1		0		0		1		pin 62
		Pin11_2		1		1		1		0		0		1		pin 63
		Pin11_3		1		1		1		0		0		1		pin 64
		Pin11_4		1		1		1		0		0		1		pin 65
		Pin11_5		1		1		1		0		0		1		pin 66
		Pin11_6		1		1		1		0		0		1		pin 67
		Pin11_7		1		1		1		0		0		1		pin 68
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_12===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin12_0		1		1		1		0		0		1		pin 69
		Pin12_1		####################################This_Pin_Not_Mount
		Pin12_2		####################################This_Pin_Not_Mount
		Pin12_3		1		1		1		0		0		1		pin 70
		Pin12_4		####################################This_Pin_Not_Mount
		Pin12_5		####################################This_Pin_Not_Mount
		Pin12_6		####################################This_Pin_Not_Mount
		Pin12_7		1		1		1		0		0		1		pin 71
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_13===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin13_0		1		1		1		0		0		1		pin 4
		Pin13_1		1		1		1		0		0		1		pin 5
		Pin13_2		1		1		1		0		0		1		pin 6
		Pin13_3		1		1		1		0		0		1		pin 7
		Pin13_4		1		1		1		0		0		1		pin 8
		Pin13_5		1		1		1		0		0		1		pin 9
		Pin13_6		1		1		1		0		0		1		pin 10
		Pin13_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


===========
===Port_14===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin14_0		####################################This_Pin_Not_Mount
		Pin14_1		####################################This_Pin_Not_Mount
		Pin14_2		####################################This_Pin_Not_Mount
		Pin14_3		####################################This_Pin_Not_Mount
		Pin14_4		####################################This_Pin_Not_Mount
		Pin14_5		####################################This_Pin_Not_Mount
		Pin14_6		####################################This_Pin_Not_Mount
		Pin14_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_15===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin15_0		####################################This_Pin_Not_Mount
		Pin15_1		####################################This_Pin_Not_Mount
		Pin15_2		####################################This_Pin_Not_Mount
		Pin15_3		####################################This_Pin_Not_Mount
		Pin15_4		####################################This_Pin_Not_Mount
		Pin15_5		####################################This_Pin_Not_Mount
		Pin15_6		####################################This_Pin_Not_Mount
		Pin15_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_16===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin16_0		####################################This_Pin_Not_Mount
		Pin16_1		####################################This_Pin_Not_Mount
		Pin16_2		####################################This_Pin_Not_Mount
		Pin16_3		####################################This_Pin_Not_Mount
		Pin16_4		####################################This_Pin_Not_Mount
		Pin16_5		####################################This_Pin_Not_Mount
		Pin16_6		####################################This_Pin_Not_Mount
		Pin16_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
										
===========
===Port_17===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin17_0		1		1		1		0		0		1		pin 53
		Pin17_1		####################################This_Pin_Not_Mount
		Pin17_2		####################################This_Pin_Not_Mount
		Pin17_3		####################################This_Pin_Not_Mount
		Pin17_4		####################################This_Pin_Not_Mount
		Pin17_5		####################################This_Pin_Not_Mount
		Pin17_6		####################################This_Pin_Not_Mount
		Pin17_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
										
===========
===Port_18===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin18_0		####################################This_Pin_Not_Mount
		Pin18_1		####################################This_Pin_Not_Mount
		Pin18_2		####################################This_Pin_Not_Mount
		Pin18_3		####################################This_Pin_Not_Mount
		Pin18_4		####################################This_Pin_Not_Mount
		Pin18_5		####################################This_Pin_Not_Mount
		Pin18_6		####################################This_Pin_Not_Mount
		Pin18_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

===========
===Port_19===		Data		Direct	PullUp	PullDown	HighDrv	InputEn	PinNumber
=====================================================================		
		Pin19_0		####################################This_Pin_Not_Mount
		Pin19_1		####################################This_Pin_Not_Mount
		Pin19_2		####################################This_Pin_Not_Mount
		Pin19_3		####################################This_Pin_Not_Mount
		Pin19_4		####################################This_Pin_Not_Mount
		Pin19_5		####################################This_Pin_Not_Mount
		Pin19_6		####################################This_Pin_Not_Mount
		Pin19_7		####################################This_Pin_Not_Mount
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Pin mount mask array, a bit is a pin resource mounted bit
*******************************************************************/

const MCU_tstResourceMount_Port MCU_stResourcePort=
{

/*port-data*/
/*===================================================================================*/
			/*Port:	0		1		2		3		4		5		6		7		8		9*/	
				{	0xFFu,	0xFFu,	0x25u,	0xFFu,	0x33u,	0xDDu,	0xDCu,	0x00u,	0xFFu,	0x0Fu,\
			/*Port:	10		11		12		13		14		15		16		17		18		19*/	
					0x0Fu,	0xFFu,	0x89u,	0x7Fu,	0x00u,	0x00u,	0x00u,	0x01u,	0x00u,	0x00u,},

/*port-direc*/	
/*===================================================================================*/
			/*Port:	0		1		2		3		4		5		6		7		8		9*/	
				{	0xFFu,	0xFFu,	0x25u,	0xFFu,	0x33u,	0xDDu,	0xDCu,	0x00u,	0xFFu,	0x0Fu,\
			/*Port:	10		11		12		13		14		15		16		17		18		19*/	
					0x0Fu,	0xFFu,	0x89u,	0x7Fu,	0x00u,	0x00u,	0x00u,	0x01u,	0x00u,	0x00u,},

/*port-Pull-up*/				
/*===================================================================================*/
			/*Port: 	0		1		2		3		4		5		6		7		8		9*/ 
				{	0xFFu,	0xFFu,	0x25u,	0xFFu,	0x33u,	0xDDu,	0xDCu,	0x00u,	0xFFu,	0x0Fu,\
			/*Port:	10		11		12		13		14		15		16		17		18		19*/	
					0x0Fu,	0xFFu,	0x89u,	0x7Fu,	0x00u,	0x00u,	0x00u,	0x01u,	0x00u,	0x00u,},
				
					
/*port-Pull-Down*/				
/*===================================================================================*/
			/*Port: 	0		1		2		3		4		5		6		7		8		9*/ 
				{	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0xFFu,	0x0Fu,\
			/*Port:	10		11		12		13		14		15		16		17		18		19*/	
					0x0Fu,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,},
					
/*High-Driver*/				
/*===================================================================================*/
			/*Port: 	0		1		2		3		4		5		6		7		8		9*/ 
				{	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0xFFu,	0x0Fu,\
			/*Port:	10		11		12		13		14		15		16		17		18		19*/	
					0x0Fu,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,	0x00u,},
};


/*############################################################
			Re-Load Timer resource mounted in MB96F69xRx
##############################################################

Relative register:

	TMCSRn	:timer control register
	TMRn	:timer counting number
	TMRLRn	:timer reload data for counting

================
===Re-Load Timer===		Mounted	VectorNumber		
=========================================================		
		Timer_0			1			58
		Timer_1			1			59
		Timer_2			1			60
		Timer_3			1			61
		Timer_4		############################This_Timer_Not_Mount
		Timer_5		############################This_Timer_Not_Mount
		Timer_6			1			64
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const MCU_tstResourceMount_ReloadTimer MCU_stResourceReLoadTimer=
{
	{MCU_mReTimerResourceMount_Mask},			/*record the mounted timer, one bit is one timer mounted*/
	{58u,59u,60u,61u,64u},	/*record the mounted timer vector number*/
};



/*############################################################
			16bit PPG resource mounted in MB96F69xRx
##############################################################

Relatice register:
	PCNn	:PPG control register
	PCSRn	:cycle data buffer for re-load
	PDUTn	:duty data buffer for re-load
	
output pins:
	PPGn	:16bit PPG First Pin output
	PPGn_R	:16bit PPG Second Pin output
	PPGn_B	:16 bit PPG Third Pin output,

================
===PPG channel===		Mounted			FirstPin		SecondPin(_R)	ThirdPin(_B)	VectorNumber		
=====================================================================		
		PPG_00			1				P13_2(pin 6)	P11_1(pin 62)		NotMount		38
		PPG_01			1				P13_3(pin 7)	P11_2(pin 63)		NotMount		39
		PPG_02			1				NotMount		P11_3(pin 64)		NotMount		40
		PPG_03			1				P04_4(pin 11)	P11_4(pin 65)		NotMount		41
		PPG_04			1				P04_5(pin 12)	P11_5(pin 66)		P03_0(pin 93)	42
		PPG_05			1				P01_3(pin 85)	NotMount			P03_1(pin 94)	43
		PPG_06			1				P10_2(pin 48)	NotMount			P08_6(pin 38)	44
		PPG_07			1				P10_3(pin 49)	NotMount			P08_7(pin 39)	45
		PPG_08			############################################################This_PPG_Not_Mount
		PPG_09			############################################################This_PPG_Not_Mount
		PPG_10			############################################################This_PPG_Not_Mount
		PPG_11			############################################################This_PPG_Not_Mount
		PPG_12			############################################################This_PPG_Not_Mount
		PPG_13			############################################################This_PPG_Not_Mount
		PPG_14			1				NotMount		NotMount			P03_2(pin 95)	52
		PPG_15			1				NotMount		NotMount			P03_3(pin 96)	53
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const MCU_tstResourceMount_PPG  MCU_stResourcePPG=
{

/*============================================================================*/					
/*PPG_Pin*/		0x00FFu,
					
/*============================================================================*/					
/*PPG_Pin_R*/	0x001Fu,
					
/*============================================================================*/					
/*PPG_Pin_B*/	0xC0F0u,

/*============================================================================*/					
/*PPG_CycleMatch VectNum:*/
				/*	0		1		2		3		4		5		6		7			*/		
				{	38u,		39u,		40u,		41u,		42u,		43u,		44u,		45u,		
				/*	8		9		10		11		12		13		14		15		*/
					46u,		47u,		48u,		49u,		50u,		51u,		52u,		53u,		},

};



/*############################################################
			External Interrupt resource mounted in MB96F69xRx
##############################################################

Relative register:
	ENIRn	:External interrupt enable control
	EIRRn	:interrupt request flag
	ELVRn	:interrupt request level control
input pins:
	INTn	:External Interrupt First Pin Input
	INTn_R	:External Interrupt Second Pin Input

================
===Ext INT channel===	Mounted		FirstPin	SecondPin(_R)	VectorNumber		
=====================================================================		
ExtInt_0:				1			P03_6(pin 99)		NotMount			17
ExtInt_1:				1			P03_7(pin 3)		P12_7(pin 71)		18
ExtInt_2:				1			P13_0(pin 4)		P05_4(pin 27)		19
ExtInt_3:				1			P13_1(pin 5)		P00_0(pin 72)		20
ExtInt_4:				1			P03_4(pin 97)		P00_1(pin 73)		21
ExtInt_5:				1			P06_2(pin 13)		P00_2(pin 74)		22
ExtInt_6:				1			P13_4(pin 8)		P00_3(pin 77)		23
ExtInt_7:				1			P13_5(pin 9)		P00_4(pin 78)		24
ExtInt_8:				1			P01_4(pin 86)		NotMount			25
ExtInt_9:				1			P01_7(pin 89)		NotMount			26
ExtInt_10:			1			P02_0(pin 90)		NotMount			27
ExtInt_11:			1			P10_0(pin 46)		NotMount			28
ExtInt_12:			1			P02_2(pin 91)		NotMount			29
ExtInt_13:			1			P02_5(pin 92)		NotMount			30
ExtInt_14:			1			P00_7(pin 81)		NotMount			31
ExtInt_15:			1			P01_2(pin 84)		NotMount			32
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


const MCU_tstResourceMnt_EINT MCU_stResourceEINT=
{
/*============================================================================*/					
/*EINT_Pin*/		0xFFFFU,
					
/*============================================================================*/					
/*EINT_Pin_R*/	0x00FEU,

/*============================================================================*/					
/*EINT_ID:*/		/*	0		1		2		3		4		5		6		7			*/		
/*VectorNum*/	{	17u,		18U,		19U,		20U,		21U,		22U,		23U,		24U,		
				/*	8		9		10		11		12		13		14		15		*/
					25U,		26U,		27U,		28U,		29U,		30U,		31U,		32U,	},
};

/*############################################################
			ADC resource mounted in MB96F69xRx
##############################################################

Relative register:
	ADERn	:ADC channel enable control
	ADCS	:ADC channel control status
	ADCR	:ADC resault data
	ADSR	:ADC channel setting register
	
input pins:
	ANn		:analog Pin Input
================
===ADC channel===	PinNumber				
=====================================================================		
	AN0:				#####################This_ADC_Not_Mount		
	AN1:				#####################This_ADC_Not_Mount		
	AN2:				P06_2(pin 13)
	AN3:				P06_3(pin 14)
	AN4:				P06_4(pin 15)
	AN5:				#####################This_ADC_Not_Mount
	AN6:				P06_6(pin 16)
	AN7:				P06_7(pin 17)
	AN8:				P05_0(pin 22)
	AN9:				#####################This_ADC_Not_Mount
	AN10:			P05_2(pin 23)
	AN11:			P05_3(pin 24)
	AN12:			P05_4(pin 27)
	AN13:			#####################This_ADC_Not_Mount
	AN14:			P05_6(pin 28)
	AN15:			P05_7(pin 29)
	AN16:			P08_0(pin 30)
	AN17:			P08_1(pin 31)
	AN18:			P08_2(pin 32)
	AN19:			P08_3(pin 33)
	AN20:			P08_4(pin 34)
	AN21:			P08_5(pin 37)
	AN22:			P08_6(pin 38)
	AN23:			P08_7(pin 39)
	AN24:			P09_0(pin 40)
	AN25:			P09_1(pin 41)
	AN26:			P09_2(pin 42)
	AN27:			P09_3(pin 43)
	AN28:			P10_0(pin 46)
	AN29:			P10_1(pin 47)
	AN30:			P10_2(pin 48)
	AN31:			P10_3(pin 49)
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const MCU_tstResourceMnt_ADC MCU_stResourceADC=
{
	98u,								/*interrupt number*/
	MCU_mADCresourceMount_Mask,		/*channel mounted mask word*/
};




/*############################################################
			DMA resource mounted in MB96F69xRx
##############################################################

Relative register:
	DISEL:	 DMA Interrupt Request Select Register 
	DSR:		 DMA Status Register 
	DSSR:	 DMA Stop Status Register 
	DER:		 DMA Enable Register 

================
===DMA channel===Resource Mounted					
=====================================================================		
	DMA0:				1
	DMA1:				1
	DMA2:				1
	DMA3:				1
	DMA4:	#####################This_DMA_Not_Mount
	DMA5:	#####################This_DMA_Not_Mount
	DMA6:	#####################This_DMA_Not_Mount
	DMA7:	#####################This_DMA_Not_Mount
	DMA8:	#####################This_DMA_Not_Mount
	DMA9:	#####################This_DMA_Not_Mount
	DMA10:	#####################This_DMA_Not_Mount
	DMA11:	#####################This_DMA_Not_Mount
	DMA12:	#####################This_DMA_Not_Mount
	DMA13:	#####################This_DMA_Not_Mount
	DMA14:	#####################This_DMA_Not_Mount
	DMA15:	#####################This_DMA_Not_Mount
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#if MCU_mDMAmodelEnable !=0u

const MCU_tstResourceMnt_DMA MCU_stResourceDMA=
{
	MCU_mDMAresourceMount_Mask,/*4 channels mounte in MB96F690*/
};

#endif
/*############################################################
			UART resource mounted in MB96F69xRx
##############################################################

Relative register:
BGRn:	Baud Rate Generation/Reload Register 
ESCRn:	Extended.Status/Control Register
ECCRn:	Extended Communication Control Register
SSRn:	Serial Status Register 
RDRn:	Reception Register 

TDRn:	Transmission Register 
SCRn:	Serial Control Register 
SMRn:	Serial Mode Register 
================
===UART channel=== Mounted	RX(SINn)		TX(SOTn)		RX_R(SINn_R)	TX_R(SOTn_R)	
=====================================================================
UART_0:				1		P13_4(pin 8)	P13_5(pin 9)		NotMount			NotMount
UART_1:				1		P03_7(pin 3)	P13_0(pin 4)		NotMount			NotMount
UART_2:				1		P10_0(pin 46)	P10_1(pin 47)		NotMount			NotMount
UART_3:		###############################################This_UART_Not_Mount
UART_4:				1		P01_4(pin 86)	P01_5(pin 87)		NotMount			NotMount
UART_5:				1		NotMount		P06_2(pin 13)		P02_5(pin 92)		P03_2(pin 95)
UART_6:		###############################################This_UART_Not_Mount
UART_7:		###############################################This_UART_Not_Mount
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
const MCU_tstResourceMnt_UART MCU_stResourceUART=
{
	{101u,	103u,	105u,	107u,	109u,	111u,	113u,	115u},
	{102u,	104u,	106u,	108u,	110u,	112u,	114u,	116u},
	MCU_mUARTresourceMount_SINn,
	MCU_mUARTresourceMount_SINn_R,
};


/*############################################################
			ICU resource mounted in MB96F69xRx
##############################################################

Relative register:

================
===ICU channel=== Mounted	INn			INn_R		
=====================================================================
ICU_0:				1		P06_4(pin 15)	P11_7(pin 68)		
ICU_1:				1		NotMount		P12_0(pin 69)		
ICU_2:		#################################This_ICU_Not_Mount
ICU_3:		#################################This_ICU_Not_Mount
ICU_4:				1		NotMount		P06_6(pin 16)
ICU_5:				1		NotMount		P06_7(pin 17)		
ICU_6:				1		P00_5(pin 79)	NotMount		
ICU_7:				1		P00_6(pin 80)	NotMount			
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const MCU_tstResourceMnt_ICU MCU_stResourceICU=
{
/*INn pin list:		0		1		2		3		4		5		6		7		*/
				{0x0604u,	0xffffu,	0xffffu,	0xffffu,	0xffffu,	0xffffu,	0x0005u,	0x0006u},
/*INn_R pin list:	0		1		2		3		4		5		6		7		*/
				{0x0b07u,	0x0c00u,	0xffffu,	0xffffu,	0x0606u,	0x0607u,	0xffffu,	0x0202u},
/*Vector Table	0		1		2		3		4		5		6		7		*/
				{65u,	66u,		67u,		68u,		69u,		70u,		71u,		72u,},
				MCU_mICUresourceMount_Mask,
};


#if MCU_mLCDmodelEnable!=0u

/*############################################################
			LCD resource mounted in MB96F69xRx
##############################################################

Relative register:

================
===LCD resource=== Mounted			
=====================================================================
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
const MCU_tstResourceMnt_LCD MCU_stResourceLCD=
{
	0x0fu,/*COM mount*/
	/*segment mount*/
	{
		/*channel 0 ->7*/
		0x9fu,
		/*channel 8 ->15*/
		0xf8u,
		/*channel 16 ->23*/
		0xffu,
		/*channel 24 ->31*/
		0x5fu,
		/*channel 32 ->39*/
		0xf2u,
		/*channel 40 ->47*/
		0x3fu,
		/*channel 48 ->55*/
		0x00u,
		/*channel 56 ->63*/
		0x00u,
		/*channel 64 ->71*/
		0x00u,
	},	
};
#endif

#if MCU_mIICmodelEnable !=0u

/*############################################################
			I2C resource mounted in MB96F69xRx
##############################################################

Relative register:

================
===I2C resource=== Mounted			
=====================================================================
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
const MCU_tstResourceMnt_IIC MCU_stResourceI2C=
{
	/*resource mount mask*/
	0x0001u,
	/*vector table index*/
	{96u},
};
#endif

#endif/*end of this file*/


