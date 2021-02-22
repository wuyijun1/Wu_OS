/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial
| File Name: _16FX_Vect.c
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
/*This file ONLY include in MCU.c for compiler*/

#if MCU_mADCModelEnable!=0u
extern uint8 MCU_u8ADCchannelCtrl;
	#if MCU_mDMAforADCEnable !=0u
		extern __far uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount];
	#else
		extern uint16 MCU_au16AdcResault[MCU_mMaxADCchannelMount];
	#endif
#endif

#if MCU_mICUmodelEnable!=0u
extern uint8 MCU_au8FRT_OVcnt[2u];
void MCU_vICUIsr(uint8 u8ICUid);
#endif

#if MCU_mTimerModelEnable!=0u
void MCU_vTimerIsr(uint16 u16timerID);
#endif
#if MCU_mEINTModelEnable!=0u
void MCU_vEINTIsr(uint16 u16EINTid);
#endif
#if MCU_mUARTmodelEnable!=0u
void MCU_vUARTIsr_Tx(uint8 u8ICUid);
void MCU_vUARTIsr_Rx(uint8 u8ICUid);
#endif
#if MCU_mIICmodelEnable!=0u
void MCU_vIICIsr(uint8 u8Channel);
#endif

#if MCU_mINTNestingEnable==0U
	#define MCU_INT_ENTRY()	do{DI();}while(0)
	#define MCU_INT_EXIT()	do{EI();}while(0)
#else
	#define MCU_INT_ENTRY()	do{EI_Force();}while(0)
	#define MCU_INT_EXIT()	do{}while(0)
#endif

#pragma	intvect	MCU_vISR_11	11	/* Non-Maskable Interrupt	*/
#pragma	intvect	MCU_vISR_12	12	/* Delayed Interrupt	*/
#pragma	intvect	MCU_vISR_13	13	/* RC Timer	*/
#pragma	intvect	MCU_vISR_14	14	/* Main Clock Timer	*/
#pragma	intvect	MCU_vISR_15	15	/* Sub Clock Timer	*/
#pragma	intvect	MCU_vISR_16	16	/* LVD-interrupt	*/
#pragma	intvect	MCU_vISR_17	17	/* External Interrupt 0	*/
#pragma	intvect	MCU_vISR_18	18	/* External Interrupt 1	*/
#pragma	intvect	MCU_vISR_19	19	/* External Interrupt 2	*/
#pragma	intvect	MCU_vISR_20	20	/* External Interrupt 3	*/
#pragma	intvect	MCU_vISR_21	21	/* External Interrupt 4	*/
#pragma	intvect	MCU_vISR_22	22	/* External Interrupt 5	*/
#pragma	intvect	MCU_vISR_23	23	/* External Interrupt 6	*/
#pragma	intvect	MCU_vISR_24	24	/* External Interrupt 7	*/
#pragma	intvect	MCU_vISR_25	25	/* External Interrupt 8	*/
#pragma	intvect	MCU_vISR_26	26	/* External Interrupt 9	*/
#pragma	intvect	MCU_vISR_27	27	/* External Interrupt 10	*/
#pragma	intvect	MCU_vISR_28	28	/* External Interrupt 11	*/
#pragma	intvect	MCU_vISR_29	29	/* External Interrupt 12	*/
#pragma	intvect	MCU_vISR_30	30	/* External Interrupt 13	*/
#pragma	intvect	MCU_vISR_31	31	/* External Interrupt 14	*/
#pragma	intvect	MCU_vISR_32	32	/* External Interrupt 15	*/
#pragma	intvect	MCU_vISR_33	33	/* CAN Controller 0	*/
#pragma	intvect	MCU_vISR_34	34	/* CAN Controller 1	*/
#pragma	intvect	MCU_vISR_35	35	/* CAN Controller 2	*/
#pragma	intvect	MCU_vISR_36	36	/* Reserved	*/
#pragma	intvect	MCU_vISR_37	37	/* Reserved	*/
#pragma	intvect	MCU_vISR_38	38	/* Programmable Pulse Generator 0	*/
#pragma	intvect	MCU_vISR_39	39	/* Programmable Pulse Generator 1	*/
#pragma	intvect	MCU_vISR_40	40	/* Programmable Pulse Generator 2	*/
#pragma	intvect	MCU_vISR_41	41	/* Programmable Pulse Generator 3	*/
#pragma	intvect	MCU_vISR_42	42	/* Programmable Pulse Generator 4	*/
#pragma	intvect	MCU_vISR_43	43	/* Programmable Pulse Generator 5	*/
#pragma	intvect	MCU_vISR_44	44	/* Programmable Pulse Generator 6	*/
#pragma	intvect	MCU_vISR_45	45	/* Programmable Pulse Generator 7	*/
#pragma	intvect	MCU_vISR_46	46	/* Programmable Pulse Generator 8	*/
#pragma	intvect	MCU_vISR_47	47	/* Programmable Pulse Generator 9	*/
#pragma	intvect	MCU_vISR_48	48	/* Programmable Pulse Generator 10	*/
#pragma	intvect	MCU_vISR_49	49	/* Programmable Pulse Generator 11	*/
#pragma	intvect	MCU_vISR_50	50	/* Programmable Pulse Generator 12	*/
#pragma	intvect	MCU_vISR_51	51	/* Programmable Pulse Generator 13	*/
#pragma	intvect	MCU_vISR_52	52	/* Programmable Pulse Generator 14	*/
#pragma	intvect	MCU_vISR_53	53	/* Programmable Pulse Generator 15	*/
#pragma	intvect	MCU_vISR_54	54	/* Programmable Pulse Generator 16	*/
#pragma	intvect	MCU_vISR_55	55	/* Programmable Pulse Generator 17	*/
#pragma	intvect	MCU_vISR_56	56	/* Programmable Pulse Generator 18	*/
#pragma	intvect	MCU_vISR_57	57	/* Programmable Pulse Generator 19	*/
#pragma	intvect	MCU_vISR_58	58	/* Reload Timer 0	*/
#pragma	intvect	MCU_vISR_59	59	/* Reload Timer 1	*/
#pragma	intvect	MCU_vISR_60	60	/* Reload Timer 2	*/
#pragma	intvect	MCU_vISR_61	61	/* Reload Timer 3	*/
#pragma	intvect	MCU_vISR_62	62	/* Reload Timer 4 ############dummy#########	*/
#pragma	intvect	MCU_vISR_63	63	/* Reload Timer 5 ############dummy#########	*/
#pragma	intvect	MCU_vISR_64	64	/* Reload Timer 6 - dedicated for PPG	*/
#pragma	intvect	MCU_vISR_65	65	/* Input Capture Unit 0	*/
#pragma	intvect	MCU_vISR_66	66	/* Input Capture Unit 1	*/
#pragma	intvect	MCU_vISR_67	67	/* Input Capture Unit 2	*/
#pragma	intvect	MCU_vISR_68	68	/* Input Capture Unit 3	*/
#pragma	intvect	MCU_vISR_69	69	/* Input Capture Unit 4	*/
#pragma	intvect	MCU_vISR_70	70	/* Input Capture Unit 5	*/
#pragma	intvect	MCU_vISR_71	71	/* Input Capture Unit 6	*/
#pragma	intvect	MCU_vISR_72	72	/* Input Capture Unit 7	*/
#pragma	intvect	MCU_vISR_73	73	/* Input Capture Unit 8	*/
#pragma	intvect	MCU_vISR_74	74	/* Input Capture Unit 9	*/
#pragma	intvect	MCU_vISR_75	75	/* Input Capture Unit 10	*/
#pragma	intvect	MCU_vISR_76	76	/* Input Capture Unit 11	*/
#pragma	intvect	MCU_vISR_77	77	/* Output Compare Unit 0	*/
#pragma	intvect	MCU_vISR_78	78	/* Output Compare Unit 1	*/
#pragma	intvect	MCU_vISR_79	79	/* Output Compare Unit 2	*/
#pragma	intvect	MCU_vISR_80	80	/* Output Compare Unit 3	*/
#pragma	intvect	MCU_vISR_81	81	/* Output Compare Unit 4	*/
#pragma	intvect	MCU_vISR_82	82	/* Output Compare Unit 5	*/
#pragma	intvect	MCU_vISR_83	83	/* Output Compare Unit 6	*/
#pragma	intvect	MCU_vISR_84	84	/* Output Compare Unit 7	*/
#pragma	intvect	MCU_vISR_85	85	/* Output Compare Unit 8	*/
#pragma	intvect	MCU_vISR_86	86	/* Output Compare Unit 9	*/
#pragma	intvect	MCU_vISR_87	87	/* Output Compare Unit 10	*/
#pragma	intvect	MCU_vISR_88	88	/* Output Compare Unit 11	*/
#pragma	intvect	MCU_vISR_89	89	/* Free Running Timer 0	*/
#pragma	intvect	MCU_vISR_90	90	/* Free Running Timer 1	*/
#pragma	intvect	MCU_vISR_91	91	/* Free Running Timer 2	*/
#pragma	intvect	MCU_vISR_92	92	/* Free Running Timer 3	*/
#pragma	intvect	MCU_vISR_93	93	/* Real Timer Clock	*/
#pragma	intvect	MCU_vISR_94	94	/* Clock Calibration Unit	*/
#pragma	intvect	MCU_vISR_95	95	/* Sound Generator 0	*/
#pragma	intvect	MCU_vISR_96	96	/* I2C interface 0	*/
#pragma	intvect	MCU_vISR_97	97	/* I2C interface 1	*/
#pragma	intvect	MCU_vISR_98	98	/* A/D Converter	*/
#pragma	intvect	MCU_vISR_99	99	/* Reserved	*/
#pragma	intvect	MCU_vISR_100	100	/* Reserved	*/
#pragma	intvect	MCU_vISR_101	101	/* LIN USART 0 RX	*/
#pragma	intvect	MCU_vISR_102	102	/* LIN USART 0 TX	*/
#pragma	intvect	MCU_vISR_103	103	/* LIN USART 1 RX	*/
#pragma	intvect	MCU_vISR_104	104	/* LIN USART 1 TX	*/
#pragma	intvect	MCU_vISR_105	105	/* LIN USART 2 RX	*/
#pragma	intvect	MCU_vISR_106	106	/* LIN USART 2 TX	*/
#pragma	intvect	MCU_vISR_107	107	/* LIN USART 3 RX	*/
#pragma	intvect	MCU_vISR_108	108	/* LIN USART 3 TX	*/
#pragma	intvect	MCU_vISR_109	109	/* LIN USART 4 RX	*/
#pragma	intvect	MCU_vISR_110	110	/* LIN USART 4 TX	*/
#pragma	intvect	MCU_vISR_111	111	/* LIN USART 5 RX	*/
#pragma	intvect	MCU_vISR_112	112	/* LIN USART 5 TX	*/
#pragma	intvect	MCU_vISR_113	113	/* LIN USART 6 RX	*/
#pragma	intvect	MCU_vISR_114	114	/* LIN USART 6 TX	*/
#pragma	intvect	MCU_vISR_115	115	/* LIN USART 7 RX	*/
#pragma	intvect	MCU_vISR_116	116	/* LIN USART 7 TX	*/
#pragma	intvect	MCU_vISR_117	117	/* LIN USART 8 RX	*/
#pragma	intvect	MCU_vISR_118	118	/* LIN USART 8 TX	*/
#pragma	intvect	MCU_vISR_119	119	/* LIN USART 9 RX	*/
#pragma	intvect	MCU_vISR_120	120	/* LIN USART 9 TX	*/
#pragma	intvect	MCU_vISR_121	121	/* Sound Generator 1	*/
#pragma	intvect	MCU_vISR_122	122	/* Reserved	*/
#pragma	intvect	MCU_vISR_123	123	/* Reserved	*/
#pragma	intvect	MCU_vISR_124	124	/* Reserved	*/
#pragma	intvect	MCU_vISR_125	125	/* Reserved	*/
#pragma	intvect	MCU_vISR_126	126	/* Reserved	*/
#pragma	intvect	MCU_vISR_127	127	/* Reserved	*/
#pragma	intvect	MCU_vISR_128	128	/* Reserved	*/
#pragma	intvect	MCU_vISR_129	129	/* Reserved	*/
#pragma	intvect	MCU_vISR_130	130	/* Reserved	*/
#pragma	intvect	MCU_vISR_131	131	/* Reserved	*/
#pragma	intvect	MCU_vISR_132	132	/* Reserved	*/
#pragma	intvect	MCU_vISR_133	133	/* Dual operation Flash A	*/
#pragma	intvect	MCU_vISR_134	134	/* Dual operation Flash B	*/
#pragma	intvect	MCU_vISR_135	135	/* Reserved	*/
#pragma	intvect	MCU_vISR_136	136	/* Reserved	*/
#pragma	intvect	MCU_vISR_137	137	/* Quad Possition/Revolution counter 0	*/
#pragma	intvect	MCU_vISR_138	138	/* Quad Possition/Revolution counter 1	*/
#pragma	intvect	MCU_vISR_139	139	/* A/D Converter 0 - Range Comparator	*/
#pragma	intvect	MCU_vISR_140	140	/* A/D Converter 0 - Pulse detection	*/
#pragma	intvect	MCU_vISR_141	141	/* Reserved	*/
#pragma	intvect	MCU_vISR_142	142	/* Reserved	*/
#pragma	intvect	MCU_vISR_143	143	/* Reserved	*/
#pragma	intvect	MCU_vISR_144	144	/* Reserved	*/
#pragma	intvect	MCU_vISR_145	145	/* Reserved	*/
#pragma	intvect	MCU_vISR_146	146	/* Reserved	*/
#pragma	intvect	MCU_vISR_147	147	/* Reserved	*/


__interrupt void MCU_vISR_11(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_12(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_13(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_14(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_15(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_16(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


/*###########################################################
		EINT-0  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_17(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-1  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_18(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(1u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-2  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_19(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(2u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-3  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_20(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(3u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-4  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_21(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(4u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-5  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_22(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(5u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-6  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_23(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(6u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-7  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_24(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(7u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-8  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_25(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(8u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-9  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_26(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(9u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-10  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_27(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(10u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-11  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_28(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(11u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-12  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_29(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(12u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-13  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_30(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(13u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-14  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_31(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(14u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		EINT-15  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_32(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mEINTModelEnable!=0u
	MCU_vEINTIsr(15u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_33(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_34(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_35(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_36(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_37(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_38(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_39(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_40(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_41(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_42(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_43(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_44(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_45(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_46(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_47(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_48(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_49(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_50(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_51(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_52(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_53(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_54(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_55(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_56(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_57(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


/*###########################################################
		Re-Load timer0  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_58(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mTimerModelEnable!=0u
	MCU_vTimerIsr(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		Re-Load timer1  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_59(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mTimerModelEnable!=0u
	MCU_vTimerIsr(1u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


/*###########################################################
		Re-Load timer2  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_60(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mTimerModelEnable!=0u
	MCU_vTimerIsr(2u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


/*###########################################################
		Re-Load timer3  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_61(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mTimerModelEnable!=0u
	MCU_vTimerIsr(3u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_62(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_63(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		Re-Load timer6  interrupt function in vector table-->Timer ID is 4!
###########################################################*/
__interrupt void MCU_vISR_64(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mTimerModelEnable!=0u
	MCU_vTimerIsr(4u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		ICU0 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_65(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		ICU1 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_66(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(1u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU2 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_67(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(2u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU3 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_68(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(3u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU4 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_69(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(4u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU5 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_70(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(5u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU6 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_71(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(6u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
/*###########################################################
		ICU7 interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_72(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	MCU_vICUIsr(7u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_73(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_74(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_75(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_76(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_77(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_78(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_79(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_80(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_81(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_82(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_83(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_84(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_85(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_86(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_87(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_88(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_89(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	TCCS0_IVF=0;
	MCU_au8FRT_OVcnt[0u]++;
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_90(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mICUmodelEnable!=0u
	TCCS1_IVF=0;
	MCU_au8FRT_OVcnt[1u]++;
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_91(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_92(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_93(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_94(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_95(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		IIC-0  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_96(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mIICmodelEnable!=0u
	MCU_vIICIsr(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_97(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		ADC  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_98(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mADCModelEnable  != 0u

	#if MCU_mDMAforADCEnable == 0u
	MCU_au16AdcResault[MCU_u8ADCchannelCtrl]=ADCR_DATA10;
	MCU_u8ADCchannelCtrl++;
	#endif
	
	ADCSH_INT=0u;
	ADCSH_PAUS=0u;
#endif	


	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_99(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_100(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART0 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_101(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART0 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_102(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(0u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART1 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_103(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(1u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART1 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_104(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(1u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


/*###########################################################
		UART2 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_105(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(2u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART2 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_106(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(2u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART3 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_107(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(3u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART3 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_108(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(3u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART4 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_109(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(4u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART4 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_110(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(4u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART5 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_111(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(5u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART5 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_112(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(5u);
	#endif

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART6 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_113(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(6u);
	#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART6 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_114(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(6u);
	#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART7 RX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_115(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Rx(7u);
	#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

/*###########################################################
		UART7 TX  interrupt function in vector table
###########################################################*/
__interrupt void MCU_vISR_116(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	#if MCU_mUARTmodelEnable!=0u
	MCU_vUARTIsr_Tx(7u);
	#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

__interrupt void MCU_vISR_117(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_118(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_119(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_120(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_121(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_122(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_123(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_124(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_125(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_126(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_127(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_128(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_129(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_130(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_131(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_132(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_133(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_134(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_135(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_136(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_137(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_138(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_139(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_140(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_141(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_142(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_143(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_144(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_145(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_146(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
__interrupt void MCU_vISR_147(void)
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#endif/*end of this file*/

