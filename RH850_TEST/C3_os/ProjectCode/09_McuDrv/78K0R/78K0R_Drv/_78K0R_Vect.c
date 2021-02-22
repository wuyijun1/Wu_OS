/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial
| File Name: _78K0R_Vect.c
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

/*This file ONLY include in MCU.c for compiler*/

#if MCU_mADCModelEnable!=0u
	void MCU_vADCIsr(void);
#endif

#if MCU_mTimerModelEnable!=0u
	void MCU_vTimerIsr(uint16 u16timerID);
#endif

#if MCU_mEINTModelEnable!=0u
	void MCU_vEINTIsr(uint16 u16EINTid);
#endif

#if ((MCU_mCSImodelEnable !=0u) || (MCU_mSerialUartmodelEnable !=0u) ||(MCU_mIICmodelEnable!=0u))
	void MCU_vSerialISR(uint16 u16Ch);
#endif

#if MCU_mLinUart_modelEnable!=0u
	void MCU_vLinUartIsr_Tx(uint16 u16channel);
	void MCU_vLinUartIsr_Rx(uint16 u16channel);
#endif

#if MCU_mDMAmodelEnable!=0u
	 void MCU_vDMAIsr(uint16 u16channel);
#endif

 
#define VectBitPos(vect)	((uint8)((uint8)((vect)-4u)>>1u))
#define MCU_IFclean(vector)		do{}while(0)

#if DET_HaltWhenErrorHappen!=0u
	#define MCU_VectorChk(vector)		do{}while(0)/*do{uint16 u16RetVal=0u;\
		u16RetVal++;DET_ErrCheck((uint8)(MCU_au8VectorMask[(uint8)((uint8)((vector)-4u)>>4u)] & \
						(1u<<(uint8)((uint8)((uint8)((vector)-4u)>>1u) & 7u)))!=0u , \
									DET_Err_VectNotMount);}while(0u)*/
#else
	#define MCU_VectorChk(vector)	do{}while(0)
#endif

#if MCU_mINTNestingEnable==0U
	#define MCU_INT_ENTRY()	do{DI();}while(0)
	#define MCU_INT_EXIT()	do{EI();}while(0)
#else
	#define MCU_INT_ENTRY()	do{EI_Force();}while(0)
	#define MCU_INT_EXIT()	do{}while(0)
#endif


__interrupt void MD_RST(void);
__interrupt void MD_INTWDTI(void);
__interrupt void MD_INTLVI(void);
__interrupt void MD_INTP0(void);
__interrupt void MD_INTP1(void);
__interrupt void MD_INTP2(void);
__interrupt void MD_INTP3(void);
__interrupt void MD_INTP4(void);
__interrupt void MD_INTP5(void);
__interrupt void MD_INTCLM(void);/*it will interrupt if fPLL stops, if fMain is stop, it will reset! */
__interrupt void MD_INTCSI00(void);
__interrupt void MD_INTCSI01(void);
__interrupt void MD_INTDMA0(void);
__interrupt void MD_INTDMA1(void);
__interrupt void MD_INTWUTM(void);
__interrupt void MD_INTFL(void);
__interrupt void MD_INTLT0(void);
__interrupt void MD_INTLR0(void);
__interrupt void MD_INTLS0(void);
__interrupt void MD_INTPLR0(void);
__interrupt void MD_INTP8(void);
__interrupt void MD_INTTM00(void);
__interrupt void MD_INTTM01(void);
__interrupt void MD_INTTM02(void);
__interrupt void MD_INTTM03(void);
__interrupt void MD_INTAD(void);
__interrupt void MD_INTLT1(void);
__interrupt void MD_INTLR1(void);
__interrupt void MD_INTLS1(void);
__interrupt void MD_INTPLR1(void);
__interrupt void MD_INTCSI10(void);
__interrupt void MD_INTCSI11(void);
__interrupt void MD_INTIIC11(void); 
__interrupt void MD_INTTM04(void);
__interrupt void MD_INTTM05(void);
__interrupt void MD_INTTM06(void);
__interrupt void MD_INTTM07(void);
__interrupt void MD_INTKR(void);
__interrupt void MD_INTP6(void);
__interrupt void MD_INTP7(void);

#if 0 /*CAN interrupt use by vector code, so it no-active here*/
__interrupt void MD_INTC0ERR(void);
__interrupt void MD_INTC0WUP(void);
__interrupt void MD_INTC0REC(void);
__interrupt void MD_INTC0TRX(void);
#endif

__interrupt void MD_INTTM10(void);
__interrupt void MD_INTTM11(void);
__interrupt void MD_INTTM12(void);
__interrupt void MD_INTTM13(void);
__interrupt void MD_INTMD(void);
__interrupt void MD_INTIIC20(void); 
__interrupt void MD_INTST2(void);
__interrupt void MD_INTSR2(void);
__interrupt void MD_INTPR2(void);
__interrupt void MD_INTTM14(void);
__interrupt void MD_INTTM15(void);
__interrupt void MD_INTTM16(void);
__interrupt void MD_INTTM17(void);
__interrupt void MD_INTTM20(void);
__interrupt void MD_INTTM21(void);
__interrupt void MD_INTTM22(void);
__interrupt void MD_INTTM23(void);
__interrupt void MD_INTTM25(void);
__interrupt void MD_INTTM27(void);
__interrupt void MD_INTDMA2(void);
__interrupt void MD_INTDMA3(void);
__interrupt void MD_BRK_I(void);


#pragma vector =	INTWDTI_vect
__interrupt void MD_INTWDTI(void)	
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
	MCU_VectorChk(INTWDTI_vect);
	MCU_IFclean(INTWDTI_vect);

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#pragma vector =	INTLVI_vect
__interrupt void MD_INTLVI(void)	
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTLVI_vect);
	MCU_IFclean(INTLVI_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#pragma vector =	INTP0_vect
__interrupt void MD_INTP0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP0_vect);
	MCU_IFclean(INTP0_vect);
	MCU_vEINTIsr(0U);
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP1_vect
__interrupt void MD_INTP1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP1_vect);
	MCU_IFclean(INTP1_vect);
	MCU_vEINTIsr(1U);
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP2_vect
__interrupt void MD_INTP2(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP2_vect);
	MCU_IFclean(INTP2_vect);
	MCU_vEINTIsr(2U);
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP3_vect
__interrupt void MD_INTP3(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP3_vect);
	MCU_IFclean(INTP3_vect);
	MCU_vEINTIsr(3U);
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP4_vect
__interrupt void MD_INTP4(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP4_vect);
	MCU_IFclean(INTP4_vect);
	MCU_vEINTIsr(4U);
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP5_vect
__interrupt void MD_INTP5(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mEINTModelEnable!=0u
	MCU_VectorChk(INTP5_vect);
	MCU_IFclean(INTP5_vect);
	MCU_vEINTIsr(5U);
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTCLM_vect
__interrupt void MD_INTCLM(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTCLM_vect);
	MCU_IFclean(INTCLM_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTCSI00_vect
__interrupt void MD_INTCSI00(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mCSImodelEnable  != 0u

	MCU_VectorChk(INTCSI00_vect);
	MCU_IFclean(INTCSI00_vect);
	MCU_vSerialISR(MCU_mSerial_ID_CSI00);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTCSI01_vect
__interrupt void MD_INTCSI01(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mCSImodelEnable  != 0u

	MCU_VectorChk(INTCSI01_vect);
	MCU_IFclean(INTCSI01_vect);
	MCU_vSerialISR(MCU_mSerial_ID_CSI01);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTDMA0_vect
__interrupt void MD_INTDMA0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mDMAmodelEnable  != 0u

	MCU_VectorChk(INTDMA0_vect);
	MCU_IFclean(INTDMA0_vect);
	MCU_vDMAIsr(MCU_mDMA_ID_DMA0);
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTDMA1_vect
__interrupt void MD_INTDMA1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mDMAmodelEnable  != 0u

	MCU_VectorChk(INTDMA1_vect);
	MCU_IFclean(INTDMA1_vect);
	MCU_vDMAIsr(MCU_mDMA_ID_DMA1);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTWUTM_vect
__interrupt void MD_INTWUTM(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTWUTM_vect);
	MCU_IFclean(INTWUTM_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTFL_vect
__interrupt void MD_INTFL(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTFL_vect);
	MCU_IFclean(INTFL_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLT0_vect
__interrupt void MD_INTLT0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLT0_vect);
	MCU_IFclean(INTLT0_vect);
	MCU_vLinUartIsr_Tx(MCU_mSerial_ID_UARTF0);
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLR0_vect
__interrupt void MD_INTLR0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLR0_vect);
	MCU_IFclean(INTLR0_vect);
	MCU_vLinUartIsr_Rx(MCU_mSerial_ID_UARTF0);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLS0_vect
__interrupt void MD_INTLS0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLS0_vect);
	MCU_IFclean(INTLS0_vect);
	
#endif
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTPLR0_vect
__interrupt void MD_INTPLR0(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/


	MCU_VectorChk(INTPLR0_vect);
	MCU_IFclean(INTPLR0_vect);
	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP8_vect
__interrupt void MD_INTP8(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mEINTModelEnable!=0u

	MCU_VectorChk(INTP8_vect);
	MCU_IFclean(INTP8_vect);
	MCU_vEINTIsr(8U);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM00_vect
__interrupt void MD_INTTM00(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM00_vect);
	MCU_IFclean(INTTM00_vect);
	MCU_vTimerIsr(MCU_mTimerArray_00);
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM01_vect
__interrupt void MD_INTTM01(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM01_vect);
	MCU_IFclean(INTTM01_vect);
	MCU_vTimerIsr(MCU_mTimerArray_01);
	
#endif	

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM02_vect
__interrupt void MD_INTTM02(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM02_vect);
	MCU_IFclean(INTTM02_vect);
	MCU_vTimerIsr(MCU_mTimerArray_02);
	
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM03_vect
__interrupt void MD_INTTM03(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM03_vect);
	MCU_IFclean(INTTM03_vect);
	MCU_vTimerIsr(MCU_mTimerArray_03);
	
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTAD_vect
__interrupt void MD_INTAD(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mADCModelEnable  != 0u

	MCU_VectorChk(INTAD_vect);
	MCU_IFclean(INTAD_vect);
	MCU_vADCIsr();
	
#endif		

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLT1_vect
__interrupt void MD_INTLT1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLT1_vect);
	MCU_IFclean(INTLT1_vect);
	MCU_vLinUartIsr_Tx(MCU_mSerial_ID_UARTF1);

#endif	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLR1_vect
__interrupt void MD_INTLR1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLR1_vect);
	MCU_IFclean(INTLR1_vect);
	MCU_vLinUartIsr_Rx(MCU_mSerial_ID_UARTF1);
	
#endif	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTLS1_vect
__interrupt void MD_INTLS1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mLinUart_modelEnable!=0u

	MCU_VectorChk(INTLS1_vect);
	MCU_IFclean(INTLS1_vect);
	
#endif	

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTPLR1_vect
__interrupt void MD_INTPLR1(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTPLR1_vect);
	MCU_IFclean(INTPLR1_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTCSI10_vect
__interrupt void MD_INTCSI10(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mCSImodelEnable  != 0u

	MCU_VectorChk(INTCSI10_vect);
	MCU_IFclean(INTCSI10_vect);
	MCU_vSerialISR(MCU_mSerial_ID_CSI10);
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#pragma vector =	INTCSI11_vect
__interrupt void MD_INTCSI11(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/


	MCU_VectorChk(INTCSI11_vect);
	MCU_IFclean(INTCSI11_vect);
	
#if MCU_mCSImodelEnable  != 0u  ||  MCU_mIICmodelEnable !=0

	MCU_vSerialISR(MCU_mSerial_ID_IIC11);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#if 0
#pragma vector =	INTIIC11_vect
__interrupt void MD_INTIIC11(void) 	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#endif

#pragma vector =	INTTM04_vect
__interrupt void MD_INTTM04(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM04_vect);
	MCU_IFclean(INTTM04_vect);
	MCU_vTimerIsr(MCU_mTimerArray_04);
	
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM05_vect
__interrupt void MD_INTTM05(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM05_vect);
	MCU_IFclean(INTTM05_vect);
	MCU_vTimerIsr(MCU_mTimerArray_05);
	
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM06_vect
__interrupt void MD_INTTM06(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM06_vect);
	MCU_IFclean(INTTM06_vect);
	MCU_vTimerIsr(MCU_mTimerArray_06);
	
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM07_vect
__interrupt void MD_INTTM07(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u

	MCU_VectorChk(INTTM07_vect);
	MCU_IFclean(INTTM07_vect);
	MCU_vTimerIsr(MCU_mTimerArray_07);
	
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#if 0
#pragma vector =	INTKR_vect
__interrupt void MD_INTKR(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#endif
#pragma vector =	INTP6_vect
__interrupt void MD_INTP6(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mEINTModelEnable!=0u

	MCU_VectorChk(INTP6_vect);
	MCU_IFclean(INTP6_vect);
	MCU_vEINTIsr(6U);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTP7_vect
__interrupt void MD_INTP7(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
#if MCU_mEINTModelEnable!=0u

	MCU_VectorChk(INTP7_vect);
	MCU_IFclean(INTP7_vect);
	MCU_vEINTIsr(7U);
	
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}




#if 0 /*CAN interrupt use by vector code, so it no-active here*/

#pragma vector =	INTC0ERR_vect
__interrupt void MD_INTC0ERR(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTC0WUP_vect
__interrupt void MD_INTC0WUP(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTC0REC_vect
__interrupt void MD_INTC0REC(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTC0TRX_vect
__interrupt void MD_INTC0TRX(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#endif


#pragma vector =	INTTM10_vect
__interrupt void MD_INTTM10(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM10_vect);
	MCU_IFclean(INTTM10_vect);
	MCU_vTimerIsr(MCU_mTimerArray_10);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM11_vect
__interrupt void MD_INTTM11(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM11_vect);
	MCU_IFclean(INTTM11_vect);
	MCU_vTimerIsr(MCU_mTimerArray_11);
#endif	

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM12_vect
__interrupt void MD_INTTM12(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM12_vect);
	MCU_IFclean(INTTM12_vect);
	MCU_vTimerIsr(MCU_mTimerArray_12);
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM13_vect
__interrupt void MD_INTTM13(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM13_vect);
	MCU_IFclean(INTTM13_vect);
	MCU_vTimerIsr(MCU_mTimerArray_13);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTMD_vect
__interrupt void MD_INTMD(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTMD_vect);
	MCU_IFclean(INTMD_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}

#if ((MCU_mIICmodelEnable !=0u) || (MCU_mSerialUartmodelEnable !=0u))

#pragma vector =	INTIIC20_vect
__interrupt void MD_INTIIC20(void) 	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	

	MCU_VectorChk(INTIIC20_vect);
	MCU_IFclean(INTIIC20_vect);
	
#if MCU_mIICmodelEnable !=0u
	MCU_vSerialISR(MCU_mSerial_ID_IIC20);
#else
	MCU_vSerialISR(MCU_mSerial_ID_UART2);
#endif
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
#else

#pragma vector =	INTST2_vect
__interrupt void MD_INTST2(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTST2_vect);
	MCU_IFclean(INTST2_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}
#endif


#pragma vector =	INTSR2_vect
__interrupt void MD_INTSR2(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mSerialUartmodelEnable !=0u

	MCU_VectorChk(INTSR2_vect);
	MCU_IFclean(INTSR2_vect);
	MCU_vSerialISR(5u);/*UART-2 RX intyerrupt*/
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTPR2_vect
__interrupt void MD_INTPR2(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(INTPR2_vect);
	MCU_IFclean(INTPR2_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM14_vect
__interrupt void MD_INTTM14(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM14_vect);
	MCU_IFclean(INTTM14_vect);
	MCU_vTimerIsr(MCU_mTimerArray_14);
#endif	

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM15_vect
__interrupt void MD_INTTM15(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM15_vect);
	MCU_IFclean(INTTM15_vect);
	MCU_vTimerIsr(MCU_mTimerArray_15);
#endif	

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM16_vect
__interrupt void MD_INTTM16(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM16_vect);
	MCU_IFclean(INTTM16_vect);
	MCU_vTimerIsr(MCU_mTimerArray_16);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM17_vect
__interrupt void MD_INTTM17(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM17_vect);
	MCU_IFclean(INTTM17_vect);
	MCU_vTimerIsr(MCU_mTimerArray_17);
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM20_vect
__interrupt void MD_INTTM20(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM20_vect);
	MCU_IFclean(INTTM20_vect);
	MCU_vTimerIsr(MCU_mTimerArray_20);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM21_vect
__interrupt void MD_INTTM21(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM21_vect);
	MCU_IFclean(INTTM21_vect);
	MCU_vTimerIsr(MCU_mTimerArray_21);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM22_vect
__interrupt void MD_INTTM22(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM22_vect);
	MCU_IFclean(INTTM22_vect);
	MCU_vTimerIsr(MCU_mTimerArray_22);
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM23_vect
__interrupt void MD_INTTM23(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM23_vect);
	MCU_IFclean(INTTM23_vect);
	MCU_vTimerIsr(MCU_mTimerArray_23);
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM25_vect
__interrupt void MD_INTTM25(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM25_vect);
	MCU_IFclean(INTTM25_vect);
	MCU_vTimerIsr(MCU_mTimerArray_25);
#endif	

	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTTM27_vect
__interrupt void MD_INTTM27(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mTimerModelEnable!=0u
	MCU_VectorChk(INTTM27_vect);
	MCU_IFclean(INTTM27_vect);
	MCU_vTimerIsr(MCU_mTimerArray_27);
#endif	
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTDMA2_vect
__interrupt void MD_INTDMA2(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/
	
#if MCU_mDMAmodelEnable!=0u

	MCU_VectorChk(INTDMA2_vect);
	MCU_IFclean(INTDMA2_vect);
	MCU_vDMAIsr(MCU_mDMA_ID_DMA2);

#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	INTDMA3_vect
__interrupt void MD_INTDMA3(void)	
 {
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

#if MCU_mDMAmodelEnable!=0u

	MCU_VectorChk(INTDMA3_vect);
	MCU_IFclean(INTDMA3_vect);
	MCU_vDMAIsr(MCU_mDMA_ID_DMA3);
	
#endif

	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}


#pragma vector =	BRK_I_vect
__interrupt void MD_BRK_I(void)	
{
	MCU_INT_ENTRY();
	/*####@@==add your code below!==@@####*/

	MCU_VectorChk(BRK_I_vect);
	MCU_IFclean(BRK_I_vect);
	
	/*####@@==add your code above! ==@@####*/
	MCU_INT_EXIT();
}



#endif/*end of this file*/

