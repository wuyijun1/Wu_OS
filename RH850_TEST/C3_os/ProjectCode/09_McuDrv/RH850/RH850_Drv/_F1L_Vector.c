/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L_Vector.c
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
| 2016.03.18  V0.01	Tan, fumin	:create this module
********************************************************************************/


#ifdef MCU_C

/*************************************
	external function reference
*************************************/
#if ( MCU_mTAUxModeEnable!=0u )
void MCU_vTAUx_Isr(MCU_enTauxID u32TAUxCh);
#endif
#if ( MCU_mIICModuleEnable!=0u )
void MCU_vRIIC_Isr_Err(MCU_enRiicID u16Ch);
void MCU_vRIIC_Isr_ReadByteFinish(MCU_enRiicID u16Ch);
void MCU_vRIIC_Isr_WriteByteFinish(MCU_enRiicID u16Ch,uint32 u32BufferEmpty_Req);

#endif

#if ( MCU_mDMAModuleEnable!=0u )
 void MCU_vDMAIsr(MCU_enDmaID u16channel);
#endif

#if ( MCU_mOSTMModuleEnable!=0)
void MCU_vOSTM_Isr(MCU_enOstmID OSTM_ID);
#endif


#if ( MCU_mINTNestingEnable==0U)
	#define MCU_INT_ENTRY()	do{DI();}while(0)
	#define MCU_INT_EXIT()	do{EI();}while(0)
#else
	#define MCU_INT_ENTRY()	do{EI_Force();}while(0)
	#define MCU_INT_EXIT()	do{}while(0)
#endif


#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt SYSERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void SYSERR(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt HVTRAP
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void HVTRAP(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt FETRAPEX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void FETRAPEX(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EITRAP0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EITRAP0(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EITRAP1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EITRAP1(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt RIEX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void RIEX(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt FPP_FPI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void FPP_FPI(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MIP_MDP
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void UCPOP(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MIP_MDP
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MIP_MDP(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt PIE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void PIE(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt Debug
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void Debug(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MAE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void MAE(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void Reserved(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt FENMI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void FENMI(void)
{
	uint32 loop,INTrequest = MCU_stInterruptCtrlAttribute.FENMI->WDTNMIFlag;
	vpFun *FunctionHead = (vpFun *)MCU_stInterruptCtrlAttribute.FENMI_Cfg;
	
	/*Run interrupt routin*/
	for(loop = 0; loop < 3;loop++)
	{
		if((INTrequest & (1<<loop)) !=0 )
		{
			/*clean flag*/
			MCU_stInterruptCtrlAttribute.FENMI->WDTNMIFClean |= (1<<loop);
			FunctionHead[loop]();
		}
	}
}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt FEINT
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void FEINT(void)
{
	uint32 loop,INTrequest = MCU_stInterruptCtrlAttribute.FEMI->FEINTFlag;
	vpFun *FunctionHead = (vpFun *)MCU_stInterruptCtrlAttribute.FEMI_Cfg;
	
	/*Run interrupt routin*/
	for(loop = 0; loop < 16;loop++)
	{
		if((INTrequest & (1<<loop)) !=0 )
		{
			/*clean flag*/
			MCU_stInterruptCtrlAttribute.FEMI->FEINTFClean |= (1<<loop);
			FunctionHead[loop]();
		}
	}
}


#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EINTPRIO_0(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EINTPRIO_1(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_2(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_3(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_4(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_5(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_6(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_7(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_8(void)
{


}


#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_9(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_10(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_11(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_12(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
 void EINTPRIO_13(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EINTPRIO_14(void)
{


}
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt EINTPRIO_15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void EINTPRIO_15(void)
{


}


/* ###########################################################################

	0	ICTAUD0I0 		INTTAUD0I0*6 Interrupt for TAUD0 channel 0 TAUD0 Edge 1000H 
		ICCSIH2IC_1 		INTCSIH2IC_1*6 CSIH2 communication status interrupt CSIH2 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_0_ICTAUD0I0_ICCSIH2IC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_0_ICTAUD0I0_ICCSIH2IC_1(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUD0_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	1	ICTAUD0I2 		INTTAUD0I2*6 Interrupt for TAUD0 channel 2 TAUD0 Edge 1001H *	
		ICCSIH3IC_1 		INTCSIH3IC_1*6 CSIH3 communication status interrupt CSIH3 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_1_ICTAUD0I2_ICCSIH3IC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_1_ICTAUD0I2_ICCSIH3IC_1(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUD0_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	2	ICTAUD0I4 		INTTAUD0I4 Interrupt for TAUD0 channel 4 TAUD0 Edge 1002H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_2_ICTAUD0I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_2_ICTAUD0I4(void)
{

#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_4);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	3	ICTAUD0I6 		INTTAUD0I6 Interrupt for TAUD0 channel 6 TAUD0 Edge 1003H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_3_ICTAUD0I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_3_ICTAUD0I6(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_6);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else	
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	4	ICTAUD0I8 		INTTAUD0I8 Interrupt for TAUD0 channel 8 TAUD0 Edge 1004H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_4_ICTAUD0I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_4_ICTAUD0I8(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_8);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	5	ICTAUD0I10 		INTTAUD0I10*6 Interrupt for TAUD0 channel 10 TAUD0 Edge 1005H *	
		ICCSIH3IR_1 		INTCSIH3IR_1*6 CSIH3 receive status interrupt CSIH3 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_5_ICTAUD0I10_ICCSIH3IR_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_5_ICTAUD0I10_ICCSIH3IR_1(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUD0_10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	6	ICTAUD0I12 		INTTAUD0I12*6 Interrupt for TAUD0 channel 12 TAUD0 Edge 1006H *	
		ICCSIH3IRE_1 		INTCSIH3IRE_1*6 CSIH3 communication error interrupt CSIH3 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_6_ICTAUD0I12_ICCSIH3IRE_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_6_ICTAUD0I12_ICCSIH3IRE_1(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUD0_12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	7	ICTAUD0I14 		INTTAUD0I14*6 Interrupt for TAUD0 channel 14 TAUD0 Edge 1007H *	
		ICCSIH3IJC_1 		INTCSIH3IJC_1*6 CSIH3 job completion interrupt CSIH3 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_7_ICTAUD0I14_ICCSIH3IJC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_7_ICTAUD0I14_ICCSIH3IJC_1(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUD0_14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	8	ICTAPA0IPEK0 		INTTAPA0IPEK0*6 TAPA0 peak interrupt 0 TAPA0 Edge 1008H 
		ICCSIH1IC_1 		INTCSIH1IC_1*6 CSIH1 communication status interrupt CSIH1 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_8_ICTAPA0IPEK0_ICCSIH1IC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_8_ICTAPA0IPEK0_ICCSIH1IC_1(void)
{
#if ( 0!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	9	ICTAPA0IVLY0 		INTTAPA0IVLY0*6 TAPA0 valley interrupt 0 TAPA0 Edge 1009H *	
		ICCSIH1IR_1 		INTCSIH1IR_1*6 CSIH1 receive status interrupt CSIH1 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_9_ICTAPA0IVLY0_ICCSIH1IR_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_9_ICTAPA0IVLY0_ICCSIH1IR_1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	10	ICADCA0I0 		INTADCA0I0 ADCA0 scan group 1 (SG1) end interrupt	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_10_ICADCA0I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_10_ICADCA0I0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	11	ICADCA0I1 		INTADCA0I1 ADCA0 scan group 2 (SG2) end interrupt	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_11_ICADCA0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_11_ICADCA0I1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	12	ICADCA0I2 		INTADCA0I2 ADCA0 scan group 3 (SG3) end interrupt	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_12_ICADCA0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_12_ICADCA0I2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	13	ICDCUTDI 		INTDCUTDI Dedicated interrupt for on-chip debug function Port Edge 100DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_13_ICDCUTDI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_13_ICDCUTDI(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	14	ICRCANGERR 		INTRCANGERR CAN global error interrupt RSCAN0 Level 100EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_14_ICRCANGERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_14_ICRCANGERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	15	ICRCANGRECC 		INTRCANGRECC CAN receive FIFO interrupt RSCAN0 Level 100FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_15_ICRCANGRECC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_15_ICRCANGRECC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	16	ICRCAN0ERR 		INTRCAN0ERR CAN0 error interrupt RSCAN0 Level 1010H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_16_ICRCAN0ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_16_ICRCAN0ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	17	ICRCAN0REC 		INTRCAN0REC CAN0 transmit receive FIFO receive complete interrupt RSCAN0 Level 1011H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_17_ICRCAN0REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_17_ICRCAN0REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	18	ICRCAN0TRX 		INTRCAN0TRX CAN0 transmit interrupt RSCAN0 Level 1012H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_18_ICRCAN0TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_18_ICRCAN0TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	19	ICCSIG0IC 		INTCSIG0IC*6 CSIG0 communication status interrupt CSIG0 Edge 1013H *
		ICCSIH1IRE_1 		INTCSIH1IRE_1*6 CSIH1 communication error interrupt CSIH1 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_19_ICCSIG0IC_ICCSIH1IRE_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_19_ICCSIG0IC_ICCSIH1IRE_1(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_WriteUnitFinish(MCU_mCSIG_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	20	ICCSIG0IR 		INTCSIG0IR*6 CSIG0 receive status interrupt CSIG0 Edge 1014H *
		ICCSIH1IJC_1 		INTCSIH1IJC_1*6 CSIH1 job complete interrupt CSIH1 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_20_ICCSIG0IR_ICCSIH1IJC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_20_ICCSIG0IR_ICCSIH1IJC_1(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_ReadUnitFinish(MCU_mCSIG_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	21	ICCSIH0IC 		INTCSIH0IC CSIH0 communication status interrupt CSIH0 Edge 1015H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_21_ICCSIH0IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_21_ICCSIH0IC(void)
{
#if ( MCU_mCSIHModuleEnable!=0)

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_WriteUnitFinish(MCU_mCSIH_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	22	ICCSIH0IR 		INTCSIH0IR CSIH0 receive status interrupt CSIH0 Edge 1016H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_22_ICCSIH0IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_22_ICCSIH0IR(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_ReadUnitFinsh(MCU_mCSIH_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	23	ICCSIH0IRE 		INTCSIH0IRE CSIH0 communication error interrupt CSIH0 Edge 1017H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_23_ICCSIH0IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_23_ICCSIH0IRE(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_Err(MCU_mCSIH_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	24	ICCSIH0IJC 		INTCSIH0IJC CSIH0 job completion interrupt CSIH0 Edge 1018H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_24_ICCSIH0IJC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_24_ICCSIH0IJC(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_JobFinish(MCU_mCSIH_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	25	ICRLIN30 		INTRLIN30 RLIN30 interrupt RLIN30 Edge 1019H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_25_ICRLIN30
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_25_ICRLIN30(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	26	ICRLIN30UR0 		INTRLIN30UR0 RLIN30 transmit interrupt RLIN30 Edge 101AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_26_ICRLIN30UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_26_ICRLIN30UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	27	ICRLIN30UR1 		INTRLIN30UR1 RLIN30 reception complete interrupt RLIN30 Edge 101BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_27_ICRLIN30UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_27_ICRLIN30UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	28	ICRLIN30UR2 		INTRLIN30UR2 RLIN30 status interrupt RLIN30 Edge 101CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_28_ICRLIN30UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_28_ICRLIN30UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	29	ICP0 		INTP0*6 External interrupt Port Edge Level101DH *	
		ICCSIH2IR_1 		INTCSIH2IR_1*6 CSIH2 reception status interrupt CSIH2 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_29_ICP0_ICCSIH2IR_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_29_ICP0_ICCSIH2IR_1(void)
{

#if ( ((MCU_mEINTModuleEnable!=0u )) )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);

#endif

}


/* ###########################################################################

	30	ICP1 		INTP1*6 External interrupt Port Edge Level101EH *	
		ICCSIH2IRE_1 		INTCSIH2IRE_1*6 CSIH2 communication error interrupt CSIH2 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_30_ICP1_ICCSIH2IRE_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_30_ICP1_ICCSIH2IRE_1(void)
{
#if ( ((MCU_mEINTModuleEnable!=0u )) )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	MCU_vEINTIsr(MCU_mEINT_ID_INT1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);

#endif

}


/* ###########################################################################

	31	ICP2 		INTP2*6 External interrupt Port Edge Level 101FH *
		ICCSIH2IJC_1 		INTCSIH2IJC_1*6 CSIH2 job completion interrupt CSIH2 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_31_ICP2_ICCSIH2IJC_1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_31_ICP2_ICCSIH2IJC_1(void)
{
#if ( ((MCU_mEINTModuleEnable!=0u )) )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT2);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);

#endif
	
}


/* ###########################################################################

	32	ICWDTA0 		INTWDTA0 WDTA0 75% interrupt WDTA0 Edge 1020H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_32_ICWDTA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_32_ICWDTA0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	33	ICWDTA1 		INTWDTA1 WDTA1 75% interrupt WDTA1 Edge 1021H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_33_ICWDTA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_33_ICWDTA1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	34	ICP3 		INTP3 External interrupt Port Edge Level 1022H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_34_ICP3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_34_ICP3(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	35	ICP4 		INTP4 External interrupt Port Edge Level1023H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_35_ICP4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_35_ICP4(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT4);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	36	ICP5 		INTP5 External interrupt Port Edge Level1024H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_36_ICP5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_36_ICP5(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT5);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	37	ICP10 		INTP10 External interrupt Port Edge Level1025H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_37_ICP10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_37_ICP10(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	38	ICP11 		INTP11 External interrupt Port Edge Level1026H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_38_ICP11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_38_ICP11(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	39	ICTAUD0I1 		INTTAUD0I1 Interrupt for TAUD0 channel 1 TAUD0 Edge 1027H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_39_ICTAUD0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_39_ICTAUD0I1(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	40	ICTAUD0I3 		INTTAUD0I3 Interrupt for TAUD0 channel 3 TAUD0 Edge 1028H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_40_ICTAUD0I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_40_ICTAUD0I3(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_3);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	41	ICTAUD0I5 		INTTAUD0I5 Interrupt for TAUD0 channel 5 TAUD0 Edge 1029H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_41_ICTAUD0I5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_41_ICTAUD0I5(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_5);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	42	ICTAUD0I7 		INTTAUD0I7 Interrupt for TAUD0 channel 7 TAUD0 Edge 102AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_42_ICTAUD0I7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_42_ICTAUD0I7(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_7);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	43	ICTAUD0I9 		INTTAUD0I9 Interrupt for TAUD0 channel 9 TAUD0 Edge 102BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_43_ICTAUD0I9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_43_ICTAUD0I9(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_9);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	44	ICTAUD0I11 		INTTAUD0I11 Interrupt for TAUD0 channel 11 TAUD0 Edge 102CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_44_ICTAUD0I11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_44_ICTAUD0I11(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_11);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	45	ICTAUD0I13 		INTTAUD0I13 Interrupt for TAUD0 channel 13 TAUD0 Edge 102DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_45_ICTAUD0I13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_45_ICTAUD0I13(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_13);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	46	ICTAUD0I15 		INTTAUD0I15 Interrupt for TAUD0 channel 15 TAUD0 Edge 102EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_46_ICTAUD0I15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_46_ICTAUD0I15(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUD0_15);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	47	ICADCA0ERR 		INTADCA0ERR ADCA0 error interrupt ADCA0 Edge 102FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_47_ICADCA0ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_47_ICADCA0ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	48					Reserved 1030H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_48_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_48_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	49	ICCSIG0IRE 		INTCSIG0IRE CSIG0 communication error interrupt CSIG0 Edge 1031H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_49_ICCSIG0IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_49_ICCSIG0IRE(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_Err(MCU_mCSIG_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	50	ICRLIN20 		INTRLIN20 RLIN20 interrupt RLIN240 Edge 1032H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_50_ICRLIN20
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_50_ICRLIN20(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	51	ICRLIN21 		INTRLIN21 RLIN21 interrupt RLIN240 Edge 1033H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_51_ICRLIN21
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_51_ICRLIN21(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	52	ICDMA0 		INTDMA0 DMA0 transfer completion DMAC Edge 1034H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_52_ICDMA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_52_ICDMA0(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	53	ICDMA1 		INTDMA1 DMA1 transfer completion DMAC Edge 1035H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_53_ICDMA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_53_ICDMA1(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	54	ICDMA2 		INTDMA2 DMA2 transfer completion DMAC Edge 1036H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_54_ICDMA2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_54_ICDMA2(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	55	ICDMA3 		INTDMA3 DMA3 transfer completion DMAC Edge 1037H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_55_ICDMA3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_55_ICDMA3(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	56	ICDMA4 		INTDMA4 DMA4 transfer completion DMAC Edge 1038H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_56_ICDMA4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_56_ICDMA4(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_4);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	57	ICDMA5 		INTDMA5 DMA5 transfer completion DMAC Edge 1039H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_57_ICDMA5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_57_ICDMA5(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_5);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	58	ICDMA6 		INTDMA6 DMA6 transfer completion DMAC Edge 103AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_58_ICDMA6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_58_ICDMA6(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_6);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	59	ICDMA7 		INTDMA7 DMA7 transfer completion DMAC Edge 103BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_59_ICDMA7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_59_ICDMA7(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_7);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	60	ICDMA8 		INTDMA8 DMA8 transfer completion DMAC Edge 103CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_60_ICDMA8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_60_ICDMA8(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_8);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	61	ICDMA9 		INTDMA9 DMA9 transfer completion DMAC Edge 103DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_61_ICDMA9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_61_ICDMA9(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_9);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	62	ICDMA10 		INTDMA10 DMA10 transfer completion DMAC Edge 103EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_62_ICDMA10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_62_ICDMA10(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	63	ICDMA11 		INTDMA11 DMA11 transfer completion DMAC Edge 103FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_63_ICDMA11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_63_ICDMA11(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	64	ICDMA12 		INTDMA12 DMA12 transfer completion DMAC Edge 1040H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_64_ICDMA12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_64_ICDMA12(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	65	ICDMA13 		INTDMA13 DMA13 transfer completion DMAC Edge 1041H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_65_ICDMA13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_65_ICDMA13(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	66	ICDMA14 		INTDMA14 DMA14 transfer completion DMAC Edge 1042H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_66_ICDMA14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_66_ICDMA14(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	67	ICDMA15 		INTDMA15 DMA15 transfer completion DMAC Edge 1043H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_67_ICDMA15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_67_ICDMA15(void)
{
#if ( MCU_mDMAModuleEnable!=0 )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vDMAIsr(MCU_mDMA_15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	68	ICRIIC0TI 		INTRIIC0TI RIIC transmit data empty interrupt RIIC0 Edge 1044H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_68_ICRIIC0TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_68_ICRIIC0TI(void)
{
#if ( MCU_mIICModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRIIC_Isr_WriteByteFinish(MCU_mRIIC_0,1u/*Empty request*/);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	69	ICRIIC0TEI 		INTRIIC0TEI RIIC transmit end interrupt RIIC0 Level 1045H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_69_ICRIIC0TEI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_69_ICRIIC0TEI(void)
{
#if ( MCU_mIICModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_WriteByteFinish(MCU_mRIIC_0,0u/*Send finish request*/);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	70	ICRIIC0RI 		INTRIIC0RI RIIC receive end interrupt RIIC0 Edge 1046H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_70_ICRIIC0RI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_70_ICRIIC0RI(void)
{
#if ( MCU_mIICModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRIIC_Isr_ReadByteFinish(MCU_mRIIC_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	71	ICRIIC0EE 		INTRIIC0EE RIIC communication error eventinterruptRIIC0 Level 1047H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_71_ICRIIC0EE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_71_ICRIIC0EE(void)
{
#if ( MCU_mIICModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRIIC_Isr_Err(MCU_mRIIC_0); /*--->IIC error happen, not use this time*/

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	72	ICTAUJ0I0 		INTTAUJ0I0 Interrupt for TAUJ0 channel 0 TAUJ0 Edge 1048H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_72_ICTAUJ0I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_72_ICTAUJ0I0(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ0_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	73	ICTAUJ0I1 		INTTAUJ0I1 Interrupt for TAUJ0 channel 1 TAUJ0 Edge 1049H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_73_ICTAUJ0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_73_ICTAUJ0I1(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ0_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	74	ICTAUJ0I2 		INTTAUJ0I2 Interrupt for TAUJ0 channel 2 TAUJ0 Edge 104AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_74_ICTAUJ0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_74_ICTAUJ0I2(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ0_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	75	ICTAUJ0I3 		INTTAUJ0I3 Interrupt for TAUJ0 channel 3 TAUJ0 Edge 104BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_75_ICTAUJ0I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_75_ICTAUJ0I3(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ0_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	76	ICOSTM0 		INTOSTM0*11 OSTM0 interrupt OSTM0 Edge 104CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_76_ICOSTM0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_76_ICOSTM0(void)
{
#if ( MCU_mOSTMModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vOSTM_Isr(MCU_mOSTM_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	77	ICENCA0IOV 		INTENCA0IOV*7 ENCA0 overflow interrupt ENCA0 Edge 104DH 
		ICPWGA4 		INTPWGA4*7 PWGA4 interrupt PWGA4 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_77_ICENCA0IOV_ICPWGA4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_77_ICENCA0IOV_ICPWGA4(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	if((MCU_stInterruptCtrlAttribute.SELB_INTC->SELB_INTCtrl2 & (1<<0))==0)
	{
		
	}
	else
	{
		MCU_vPWGACycUpdate(4);
	}
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	78	ICENCA0IUD 		INTENCA0IUD*7 ENCA0 underflow interrupt ENCA0 Edge 104EH *	
		ICPWGA5 		INTPWGA5*7 PWGA5 interrupt PWGA5 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_78_ICENCA0IUD_ICPWGA5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_78_ICENCA0IUD_ICPWGA5(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	if((MCU_stInterruptCtrlAttribute.SELB_INTC->SELB_INTCtrl2 & (1<<1))==0)
	{
		
	}
	else
	{
		MCU_vPWGACycUpdate(5);
	}
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	79	ICENCA0I0 		INTENCA0I0*7 ENCA0 capture compare matchinterrupt 0ENCA0 Edge 104FH *	
		ICPWGA6 		INTPWGA6*7 PWGA6 interrupt PWGA6 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_79_ICENCA0I0_ICPWGA6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_79_ICENCA0I0_ICPWGA6(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	/*user interrupt function*/
	if((MCU_stInterruptCtrlAttribute.SELB_INTC->SELB_INTCtrl2 & (1<<2))==0)
	{
		
	}
	else
	{
		MCU_vPWGACycUpdate(6);
	}
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	80	ICENCA0I1 		INTENCA0I1*7 ENCA0 capture compare match interrupt 1ENCA0 Edge 1050H *
		ICPWGA7 		INTPWGA7*7 PWGA7 interrupt PWGA7 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_80_ICENCA0I1_ICPWGA7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_80_ICENCA0I1_ICPWGA7(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	/*user interrupt function*/
	if((MCU_stInterruptCtrlAttribute.SELB_INTC->SELB_INTCtrl2 & (1<<3))==0)
	{
		
	}
	else
	{
		MCU_vPWGACycUpdate(7);
	}
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	81	ICENCA0IEC 		INTENCA0IEC ENCA0 encoder clear interrupt ENCA0 Edge 1051H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_81_ICENCA0IEC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_81_ICENCA0IEC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	82	ICKR0 		INTKR0 KR0 interrupt KR0 Edge 1052H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_82_ICKR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_82_ICKR0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	83	ICQFULL 		INTQFULL PWSA queue full interrupt PWSA Edge 1053H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_83_ICQFULL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_83_ICQFULL(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	84	ICPWGA0 		INTPWGA0 PWGA0 interrupt PWGA0 Edge 1054H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_84_ICPWGA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_84_ICPWGA0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(0);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	85	ICPWGA1 		INTPWGA1 PWGA1 interrupt PWGA1 Edge 1055H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_85_ICPWGA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_85_ICPWGA1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(1);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	86	ICPWGA2 		INTPWGA2 PWGA2 interrupt PWGA2 Edge 1056H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_86_ICPWGA2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_86_ICPWGA2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(2);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	87	ICPWGA3 		INTPWGA3 PWGA3 interrupt PWGA3 Edge 1057H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_87_ICPWGA3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_87_ICPWGA3(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(3);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	88	ICPWGA8 		INTPWGA8 PWGA8 interrupt PWGA8 Edge 1058H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_88_ICPWGA8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_88_ICPWGA8(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(8);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	89	ICPWGA9 		INTPWGA9 PWGA9 interrupt PWGA9 Edge 1059H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_89_ICPWGA9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_89_ICPWGA9(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(9);
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	90	ICPWGA10 		INTPWGA10 PWGA10 interrupt PWGA10 Edge 105AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_90_ICPWGA10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_90_ICPWGA10(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	91	ICPWGA11 		INTPWGA11 PWGA11 interrupt PWGA11 Edge 105BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_91_ICPWGA11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_91_ICPWGA11(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	92	ICPWGA12 		INTPWGA12 PWGA12 interrupt PWGA12 Edge 105CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_92_ICPWGA12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_92_ICPWGA12(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	93	ICPWGA13 		INTPWGA13 PWGA13 interrupt PWGA13 Edge 105DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_93_ICPWGA13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_93_ICPWGA13(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	94	ICPWGA14 		INTPWGA14 PWGA14 interrupt PWGA14 Edge 105EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_94_ICPWGA14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_94_ICPWGA14(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	95	ICPWGA15 		INTPWGA15 PWGA15 interrupt PWGA15 Edge 105FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_95_ICPWGA15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_95_ICPWGA15(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	96					Reserved 1060H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_96_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_96_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	97					Reserved 1061H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_97_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_97_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	98					Reserved 1062H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_98_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_98_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	99					Reserved 1063H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_99_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_99_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	100					Reserved 1064H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_100_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_100_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	101					Reserved 1065H 			

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_101_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_101_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	102	ICFLERR 			INTFLERR Flash sequencer access errorinterrupt*12Flash Level 1066H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_102_ICFLERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_102_ICFLERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	103	ICFLENDNM 		INTFLENDNM Flash sequencer end interrupt*12 Flash Edge 1067H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_103_ICFLENDNM
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_103_ICFLENDNM(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	104	ICCWEND 		INTCWEND LPS0 port polling end interrupt LPS Edge 1068H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_104_ICCWEND
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_104_ICCWEND(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	105	ICRCAN1ERR 		INTRCAN1ERR CAN1 error interrupt RSCAN0 Level 1069H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_105_ICRCAN1ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_105_ICRCAN1ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	106	ICRCAN1REC 		INTRCAN1REC CAN1 transmit receive FIFO receivecomplete interruptRSCAN0 Level 106AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_106_ICRCAN1REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_106_ICRCAN1REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	107	ICRCAN1TRX 		INTRCAN1TRX CAN1 transmit interrupt RSCAN0 Level 106BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_107_ICRCAN1TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_107_ICRCAN1TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	108	ICCSIH1IC 		INTCSIH1IC*6 CSIH1 communication status interrupt CSIH1 Edge 106CH 
		ICTAPA0IPEK0_2 		INTTAPA0IPEK0_2*6TAPA0 peak interrupt 0 TAPA0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_108_ICCSIH1IC_ICTAPA0IPEK0_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_108_ICCSIH1IC_ICTAPA0IPEK0_2(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_WriteUnitFinish(MCU_mCSIH_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	109	ICCSIH1IR 			INTCSIH1IR*6 CSIH1 receive status interrupt CSIH1 Edge 106DH *	
		ICTAPA0IVLY0_2 		INTTAPA0IVLY0_2*6TAPA0 valley interrupt 0 TAPA0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_109_ICCSIH1IR_ICTAPA0IVLY0_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_109_ICCSIH1IR_ICTAPA0IVLY0_2(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_ReadUnitFinsh(MCU_mCSIH_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	110	ICCSIH1IRE 		INTCSIH1IRE*6 CSIH1 communication error interrupt CSIH1 Edge 106EH 
		ICCSIG0IC_2 		INTCSIG0IC_2*6 CSIG0 communication status interrupt CSIG0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_110_ICCSIH1IRE_ICCSIG0IC_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_110_ICCSIH1IRE_ICCSIG0IC_2(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_Err(MCU_mCSIH_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	111	ICCSIH1IJC 		INTCSIH1IJC*6 CSIH1 job completion interrupt CSIH1 Edge 106FH *
		ICCSIG0IR_2 		INTCSIG0IR_2*6 CSIG0 receive status interrupt CSIG0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_111_ICCSIH1IJC_ICCSIG0IR_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_111_ICCSIH1IJC_ICCSIG0IR_2(void)
{
#if ( MCU_mCSIHModuleEnable!=0)
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIH_Isr_JobFinish(MCU_mCSIH_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	112	ICRLIN31 		INTRLIN31 RLIN31 interrupt RLIN31 Edge 1070H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_112_ICRLIN31
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_112_ICRLIN31(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	113	ICRLIN31UR0 		INTRLIN31UR0 RLIN31 transmit interrupt RLIN31 Edge 1071H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_113_ICRLIN31UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_113_ICRLIN31UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	114	ICRLIN31UR1 		INTRLIN31UR1 RLIN31 reception complete interrupt RLIN31 Edge 1072H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_114_ICRLIN31UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_114_ICRLIN31UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	115	ICRLIN31UR2 		INTRLIN31UR2 RLIN31 status interrupt RLIN31 Edge 1073H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_115_ICRLIN31UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_115_ICRLIN31UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	116	ICPWGA20 		INTPWGA20 PWGA20 interrupt PWGA20 Edge 1074H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_116_ICPWGA20
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_116_ICPWGA20(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(20);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	117	ICPWGA21 		INTPWGA21 PWGA21 interrupt PWGA21 Edge 1075H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_117_ICPWGA21
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_117_ICPWGA21(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(21);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	118	ICPWGA22 		INTPWGA22 PWGA22 interrupt PWGA22 Edge 1076H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_118_ICPWGA22
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_118_ICPWGA22(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(22);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	119	ICPWGA23 		INTPWGA23 PWGA23 interrupt PWGA23 Edge 1077H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_119_ICPWGA23
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_119_ICPWGA23(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(23);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	120	ICP6 		INTP6 External interrupt Port Edge Level1078H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_120_ICP6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_120_ICP6(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT6);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	121	ICP7 		INTP7 External interrupt Port Edge Level1079H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_121_ICP7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_121_ICP7(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT7);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	122	ICP8 		INTP8 External interrupt Port Edge Level107AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_122_ICP8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_122_ICP8(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT8);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	123	ICP12 		INTP12 External interrupt Port Edge Level107BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_123_ICP12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_123_ICP12(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	124	ICCSIH2IC 		INTCSIH2IC*6 CSIH2 communication status interrupt CSIH2 Edge 107CH *
		ICTAUD0I0_2 		INTTAUD0I0_2*6 Interrupt for TAUD0 channel 0 TAUD0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_124_ICCSIH2IC_ICTAUD0I0_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_124_ICCSIH2IC_ICTAUD0I0_2(void)
{
#if ((MCU_mCSIHModuleEnable!=0))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_WriteUnitFinish(MCU_mCSIH_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	125	ICCSIH2IR 		INTCSIH2IR*6 CSIH2 receive status interrupt CSIH2 Edge 107DH *	
		ICP0_2 		INTP0_2*6 External interrupt Port Edge Level	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_125_ICCSIH2IR_ICP0_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_125_ICCSIH2IR_ICP0_2(void)
{
#if ((MCU_mCSIHModuleEnable!=0))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_ReadUnitFinsh(MCU_mCSIH_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
	
#endif

}


/* ###########################################################################

	126	ICCSIH2IRE 		INTCSIH2IRE*6 CSIH2 communication error interrupt CSIH2 Edge 107EH 
		ICP1_2 		INTP1_2*6 External interrupt Port Edge Level	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_126_ICCSIH2IRE_ICP1_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_126_ICCSIH2IRE_ICP1_2(void)
{
#if ((MCU_mCSIHModuleEnable!=0))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_Err(MCU_mCSIH_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();

#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
	
#endif
}


/* ###########################################################################

	127	ICCSIH2IJC 		INTCSIH2IJC*6 CSIH2 job completion interrupt CSIH2 Edge 107FH *
		ICP2_2 		INTP2_2*6 External interrupt Port Edge Level	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_127_ICCSIH2IJC_ICP2_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_127_ICCSIH2IJC_ICP2_2(void)
{
#if ((MCU_mCSIHModuleEnable!=0))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_JobFinish(MCU_mCSIH_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
	
#endif
}


/* ###########################################################################

	128					Reserved 1080H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_128_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_128_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	129					Reserved 1081H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_129_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_129_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	130					Reserved 1082H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_130_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_130_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	131					Reserved 1083H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_131_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_131_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	132					Reserved 1084H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_132_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_132_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	133					Reserved 1085H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_133_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_133_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	134	ICTAUB0I0 		INTTAUB0I0 Interrupt for TAUB0 channel 0 TAUB0 Edge 1086H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_134_ICTAUB0I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_134_ICTAUB0I0(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	135	ICTAUB0I1 		INTTAUB0I1 Interrupt for TAUB0 channel 1 TAUB0 Edge 1087H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_135_ICTAUB0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_135_ICTAUB0I1(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	136	ICTAUB0I2 		INTTAUB0I2 Interrupt for TAUB0 channel 2 TAUB0 Edge 1088H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_136_ICTAUB0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_136_ICTAUB0I2(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_2);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	137	ICTAUB0I3 		INTTAUB0I3*7 Interrupt for TAUB0 channel 3 TAUB0 Edge 1089H *	
		ICPWGA16 		INTPWGA16*7 PWGA16 interrupt PWGA16 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_137_ICTAUB0I3_ICPWGA16
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_137_ICTAUB0I3_ICPWGA16(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	138	ICTAUB0I4 		INTTAUB0I4 Interrupt for TAUB0 channel 4 TAUB0 Edge 108AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_138_ICTAUB0I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_138_ICTAUB0I4(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_4);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	139	ICTAUB0I5 		INTTAUB0I5*7 Interrupt for TAUB0 channel 5 TAUB0 Edge 108BH *
		ICPWGA17 		INTPWGA17*7 PWGA17 interrupt PWGA17 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_139_ICTAUB0I5_ICPWGA17
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_139_ICTAUB0I5_ICPWGA17(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_5);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	140	ICTAUB0I6 		INTTAUB0I6 Interrupt for TAUB0 channel 6 TAUB0 Edge 108CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_140_ICTAUB0I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_140_ICTAUB0I6(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_6);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	141	ICTAUB0I7 		INTTAUB0I7*7 Interrupt for TAUB0 channel 7 TAUB0 Edge 108DH *	
		ICPWGA18 		INTPWGA18*7 PWGA18 interrupt PWGA18 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_141_ICTAUB0I7_ICPWGA18
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_141_ICTAUB0I7_ICPWGA18(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))


	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_7);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	142	ICTAUB0I8 		INTTAUB0I8 Interrupt for TAUB0 channel 8 TAUB0 Edge 108EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_142_ICTAUB0I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_142_ICTAUB0I8(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_8);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	143	ICTAUB0I9 		INTTAUB0I9*7 Interrupt for TAUB0 channel 9 TAUB0 Edge 108FH *
		ICPWGA19 		INTPWGA19*7 PWGA19 interrupt PWGA19 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_143_ICTAUB0I9_ICPWGA19
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_143_ICTAUB0I9_ICPWGA19(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_9);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	144	ICTAUB0I10 		INTTAUB0I10 Interrupt for TAUB0 channel 10 TAUB0 Edge 1090H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_144_ICTAUB0I10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_144_ICTAUB0I10(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_10);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	145	ICTAUB0I11 		INTTAUB0I11*7 Interrupt for TAUB0 channel 11 TAUB0 Edge 1091H *
		ICPWGA26 		INTPWGA26*7 PWGA26 interrupt PWGA26 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_145_ICTAUB0I11_ICPWGA26
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_145_ICTAUB0I11_ICPWGA26(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	146	ICTAUB0I12 		INTTAUB0I12 Interrupt for TAUB0 channel 12 TAUB0 Edge 1092H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_146_ICTAUB0I12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_146_ICTAUB0I12(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_12);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	147	ICTAUB0I13 		INTTAUB0I13*7 Interrupt for TAUB0 channel 13 TAUB0 Edge 1093H *
		ICPWGA30 		INTPWGA30*7 PWGA30 interrupt PWGA30 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_147_ICTAUB0I13_ICPWGA30
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_147_ICTAUB0I13_ICPWGA30(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))


	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
	
#endif
}


/* ###########################################################################

	148	ICTAUB0I14 		INTTAUB0I14 Interrupt for TAUB0 channel 14 TAUB0 Edge 1094H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_148_ICTAUB0I14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_148_ICTAUB0I14(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_14);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	149	ICTAUB0I15 		INTTAUB0I15*7 Interrupt for TAUB0 channel 15 TAUB0 Edge 1095H *
		ICPWGA31 		INTPWGA31*7 PWGA31 interrupt PWGA31 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_149_ICTAUB0I15_ICPWGA31
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_149_ICTAUB0I15_ICPWGA31(void)
{
#if ( (MCU_mTAUBDModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB0_15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	150	ICCSIH3IC 		INTCSIH3IC*6 CSIH3 communication status interrupt CSIH3 Edge 1096H *
		ICTAUD0I2_2 		INTTAUD0I2_2*6 Interrupt for TAUD0 channel 2 TAUD0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_150_ICCSIH3IC_ICTAUD0I2_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_150_ICCSIH3IC_ICTAUD0I2_2(void)
{
#if  ((MCU_mCSIHModuleEnable!=0) )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_WriteUnitFinish(MCU_mCSIH_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	151	ICCSIH3IR 		INTCSIH3IR*6 CSIH3 receive status interrupt CSIH3 Edge 1097H *	
		ICTAUD0I10_2 	INTTAUD0I10_2*6 Interrupt for TAUD0 channel 10 TAUD0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_151_ICCSIH3IR_ICTAUD0I10_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_151_ICCSIH3IR_ICTAUD0I10_2(void)
{
#if  ((MCU_mCSIHModuleEnable!=0) )


	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_ReadUnitFinsh(MCU_mCSIH_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	152	ICCSIH3IRE 		INTCSIH3IRE*6 CSIH3 communication error interrupt CSIH3 Edge 1098H 
		ICTAUD0I12_2 		INTTAUD0I12_2*6 Interrupt for TAUD0 channel 12 TAUD0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_152_ICCSIH3IRE_ICTAUD0I12_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_152_ICCSIH3IRE_ICTAUD0I12_2(void)
{
#if  ((MCU_mCSIHModuleEnable!=0) )


	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_Err(MCU_mCSIH_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	153	ICCSIH3IJC 		INTCSIH3IJC*6 CSIH3 job completion interrupt CSIH3 Edge 1099H *
		ICTAUD0I14_2 		INTTAUD0I14_2*6 Interrupt for TAUD0 channel 14 TAUD0 Edge	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_153_ICCSIH3IJC_ICTAUD0I14_2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_153_ICCSIH3IJC_ICTAUD0I14_2(void)
{
#if  ((MCU_mCSIHModuleEnable!=0) )

	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vCSIH_Isr_JobFinish(MCU_mCSIH_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	154	ICRLIN22 		INTRLIN22 RLIN22 interrupt RLIN240 Edge 109AH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_154_ICRLIN22
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_154_ICRLIN22(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	155	ICRLIN23 		INTRLIN23 RLIN23 interrupt RLIN240 Edge 109BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_155_ICRLIN23
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_155_ICRLIN23(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	156	ICRLIN32 		INTRLIN32 RLIN32 interrupt RLIN32 Edge 109CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_156_ICRLIN32
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_156_ICRLIN32(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	157	ICRLIN32UR0 		INTRLIN32UR0 RLIN32 transmit interrupt RLIN32 Edge 109DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_157_ICRLIN32UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_157_ICRLIN32UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_2);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	158	ICRLIN32UR1 		INTRLIN32UR1 RLIN32 reception complete interrupt RLIN32 Edge 109EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_158_ICRLIN32UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_158_ICRLIN32UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_2);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	159	ICRLIN32UR2 		INTRLIN32UR2 RLIN32 status interrupt RLIN32 Edge 109FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_159_ICRLIN32UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_159_ICRLIN32UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	160	ICTAUJ1I0 		INTTAUJ1I0 Interrupt for TAUJ1 channel 0 TAUJ1 Edge 10A0H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_160_ICTAUJ1I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_160_ICTAUJ1I0(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ1_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	161	ICTAUJ1I1 		INTTAUJ1I1 Interrupt for TAUJ1 channel 1 TAUJ1 Edge 10A1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_161_ICTAUJ1I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_161_ICTAUJ1I1(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ1_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	162	ICTAUJ1I2 		INTTAUJ1I2 Interrupt for TAUJ1 channel 2 TAUJ1 Edge 10A2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_162_ICTAUJ1I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_162_ICTAUJ1I2(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ1_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	163	ICTAUJ1I3 		INTTAUJ1I3 Interrupt for TAUJ1 channel 3 TAUJ1 Edge 10A3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_163_ICTAUJ1I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_163_ICTAUJ1I3(void)
{
#if ((MCU_mTAUJModuleEnable !=0 ))

	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vTAUx_Isr(MCU_mTAUJ1_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	164					Reserved 10A4H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_164_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_164_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	165					Reserved 10A5H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_165_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_165_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	166					Reserved 10A6H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_166_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_166_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	167					Reserved 10A7H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_167_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_167_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	168					Reserved 10A8H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_168_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_168_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	169					Reserved 10A9H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_169_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_169_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	170					Reserved 10AAH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_170_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_170_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	171					Reserved 10ABH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_171_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_171_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	172					Reserved 10ACH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_172_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_172_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	173					Reserved 10ADH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_173_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_173_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	174					Reserved 10AEH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_174_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_174_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	175					Reserved 10AFH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_175_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_175_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	176	ICPWGA24 		INTPWGA24 PWGA24 interrupt PWGA24 Edge 10B0H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_176_ICPWGA24
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_176_ICPWGA24(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(24);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	177	ICPWGA25 		INTPWGA25 PWGA25 interrupt PWGA25 Edge 10B1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_177_ICPWGA25
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_177_ICPWGA25(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(25);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	178	ICPWGA27 		INTPWGA27 PWGA27 interrupt PWGA27 Edge 10B2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_178_ICPWGA27
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_178_ICPWGA27(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(27);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	179	ICPWGA28 		INTPWGA28 PWGA28 interrupt PWGA28 Edge 10B3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_179_ICPWGA28
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_179_ICPWGA28(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(28);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	180	ICPWGA29 		INTPWGA29 PWGA29 interrupt PWGA29 Edge 10B4H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_180_ICPWGA29
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_180_ICPWGA29(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(29);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	181	ICPWGA32 		INTPWGA32 PWGA32 interrupt PWGA32 Edge 10B5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_181_ICPWGA32
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_181_ICPWGA32(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(32);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	182	ICPWGA33 		INTPWGA33 PWGA33 interrupt PWGA33 Edge 10B6H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_182_ICPWGA33
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_182_ICPWGA33(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(33);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	183	ICPWGA34 		INTPWGA34 PWGA34 interrupt PWGA34 Edge 10B7H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_183_ICPWGA34
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_183_ICPWGA34(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(34);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	184	ICPWGA35 		INTPWGA35 PWGA35 interrupt PWGA35 Edge 10B8H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_184_ICPWGA35
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_184_ICPWGA35(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(35);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	185	ICPWGA36 		INTPWGA36 PWGA36 interrupt PWGA36 Edge 10B9H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_185_ICPWGA36
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_185_ICPWGA36(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(36);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	186	ICPWGA37 		INTPWGA37 PWGA37 interrupt PWGA37 Edge 10BAH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_186_ICPWGA37
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_186_ICPWGA37(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(37);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	187	ICPWGA38 		INTPWGA38 PWGA38 interrupt PWGA38 Edge 10BBH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_187_ICPWGA38
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_187_ICPWGA38(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(38);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	188	ICPWGA39 		INTPWGA39 PWGA39 interrupt PWGA39 Edge 10BCH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_188_ICPWGA39
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_188_ICPWGA39(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(39);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	189	ICPWGA40 		INTPWGA40 PWGA40 interrupt PWGA40 Edge 10BDH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_189_ICPWGA40
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_189_ICPWGA40(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(40);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	190	ICPWGA41 		INTPWGA41 PWGA41 interrupt PWGA41 Edge 10BEH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_190_ICPWGA41
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_190_ICPWGA41(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(41);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	191	ICPWGA42 		INTPWGA42 PWGA42 interrupt PWGA42 Edge 10BFH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_191_ICPWGA42
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_191_ICPWGA42(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(42);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	192	ICPWGA43 		INTPWGA43 PWGA43 interrupt PWGA43 Edge 10C0H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_192_ICPWGA43
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_192_ICPWGA43(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(43);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	193	ICPWGA44 		INTPWGA44 PWGA44 interrupt PWGA44 Edge 10C1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_193_ICPWGA44
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_193_ICPWGA44(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(44);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	194	ICPWGA45 		INTPWGA45 PWGA45 interrupt PWGA45 Edge 10C2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_194_ICPWGA45
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_194_ICPWGA45(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(45);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	195	ICPWGA46 		INTPWGA46 PWGA46 interrupt PWGA46 Edge 10C3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_195_ICPWGA46
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_195_ICPWGA46(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(46);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	196	ICPWGA47 		INTPWGA47 PWGA47 interrupt PWGA47 Edge 10C4H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_196_ICPWGA47
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_196_ICPWGA47(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(47);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	197	ICP9 		INTP9 External interrupt Port Edge Level10C5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_197_ICP9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_197_ICP9(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT9);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	198	ICP13 		INTP13 External interrupt Port Edge Level10C5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_198_ICP13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_198_ICP13(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	199	ICP14 		INTP14 External interrupt Port Edge Level10C5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_199_ICP14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_199_ICP14(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	200	ICP15 		INTP15 External interrupt Port Edge Level10C5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_200_ICP15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_200_ICP15(void)
{
#if ( MCU_mEINTModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vEINTIsr(MCU_mEINT_ID_INT15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	201	ICRTCA01S 		INTRTCA01S RTCA0 1 second interval interrupt RTCA Edge 10C9H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_201_ICRTCA01S
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_201_ICRTCA01S(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	202	ICRTCA0AL 		INTRTCA0AL RTCA0 alarm interrupt RTCA Edge 10CAH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_202_ICRTCA0AL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_202_ICRTCA0AL(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	203	ICRTCA0R 		INTRTCA0R RTCA0 periodic interrupt RTCA Edge 10CBH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_203_ICRTCA0R
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_203_ICRTCA0R(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	204	ICADCA1ERR 		INTADCA1ERR ADCA1 error interrupt ADCA1 Edge 10CCH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_204_ICADCA1ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_204_ICADCA1ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	205	ICADCA1I0 		INTADCA1I0 ADCA1 scan group 1 (SG1) endinterrupt	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_205_ICADCA1I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_205_ICADCA1I0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vADCIsr();

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	206	ICADCA1I1 		INTADCA1I1 ADCA1 scan group 2 (SG2) endinterrupt ADCA1 Edge 10CEH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_206_ICADCA1I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_206_ICADCA1I1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vADCIsr();

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	207	ICADCA1I2 		INTADCA1I2 ADCA1 scan group 3 (SG3) endinterrupt ADCA1 Edge 10CFH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_207_ICADCA1I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_207_ICADCA1I2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vADCIsr();
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	208					Reserved 10D0H 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_208_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_208_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	209	ICRCAN2ERR 		INTRCAN2ERR CAN2 error interrupt RSCAN0 Level 10D1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_209_ICRCAN2ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_209_ICRCAN2ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	210	ICRCAN2REC 		INTRCAN2REC CAN2 transmit receive FIFO receive complete interrupt RSCAN0 Level 10D2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_210_ICRCAN2REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_210_ICRCAN2REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	211	ICRCAN2TRX 		INTRCAN2TRX CAN2 transmit interrupt RSCAN0 Level 10D3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_211_ICRCAN2TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_211_ICRCAN2TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	212	ICRCAN3ERR 		INTRCAN3ERR CAN3 error interrupt RSCAN0 Level 10D4H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_212_ICRCAN3ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_212_ICRCAN3ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	213	ICRCAN3REC 		INTRCAN3REC CAN3 transmit receive FIFO receive complete interrupt RSCAN0 Level 10D5H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_213_ICRCAN3REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_213_ICRCAN3REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	214	ICRCAN3TRX 		INTRCAN3TRX CAN3 transmit interrupt RSCAN0 Level 10D6H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_214_ICRCAN3TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_214_ICRCAN3TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	215	ICCSIG1IC 		INTCSIG1IC CSIG1 communication status interrupt CSIG1 Edge 10D7H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_215_ICCSIG1IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_215_ICCSIG1IC(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_WriteUnitFinish(MCU_mCSIG_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	216	ICCSIG1IR 		INTCSIG1IR CSIG1 receive status interrupt CSIG1 Edge 10D8H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_216_ICCSIG1IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_216_ICCSIG1IR(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_ReadUnitFinish(MCU_mCSIG_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	217	ICCSIG1IRE 		INTCSIG1IRE CSIG1 communication error interrupt CSIG1 Edge 10D9H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_217_ICCSIG1IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_217_ICCSIG1IRE(void)
{
#if ( MCU_mCSIGModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vCSIG_Isr_Err(MCU_mCSIG_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	218	ICRLIN24 		INTRLIN24 RLIN24 interrupt RLIN241 Edge 10DAH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_218_ICRLIN24
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_218_ICRLIN24(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	219	ICRLIN25 		INTRLIN25 RLIN25 interrupt RLIN241 Edge 10DBH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_219_ICRLIN25
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_219_ICRLIN25(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	220	ICRLIN33 		INTRLIN33 RLIN33 interrupt RLIN33 Edge 10DCH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_220_ICRLIN33
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_220_ICRLIN33(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	221	ICRLIN33UR0 		INTRLIN33UR0 RLIN33 transmit interrupt RLIN33 Edge 10DDH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_221_ICRLIN33UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_221_ICRLIN33UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_3);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	222	ICRLIN33UR1 		INTRLIN33UR1 RLIN33 reception complete interrupt RLIN33 Edge 10DEH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_222_ICRLIN33UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_222_ICRLIN33UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_3);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	223	ICRLIN33UR2 		INTRLIN33UR2 RLIN33 status interrupt RLIN33 Edge 10DFH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_223_ICRLIN33UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_223_ICRLIN33UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	224	ICRLIN34 		INTRLIN34 RLIN34 interrupt RLIN34 Edge 10E0H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_224_ICRLIN34
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_224_ICRLIN34(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	225	ICRLIN34UR0 		INTRLIN34UR0 RLIN34 transmit interrupt RLIN34 Edge 10E1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_225_ICRLIN34UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_225_ICRLIN34UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_4);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	226	ICRLIN34UR1 		INTRLIN34UR1 RLIN34 reception complete interrupt RLIN34 Edge 10E2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_226_ICRLIN34UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_226_ICRLIN34UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_5);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	227	ICRLIN34UR2 		INTRLIN34UR2 RLIN34 status interrupt RLIN34 Edge 10E3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_227_ICRLIN34UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_227_ICRLIN34UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	228	ICRLIN35 		INTRLIN35 RLIN35 interrupt RLIN35 Edge 10E4H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_228_ICRLIN35
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_228_ICRLIN35(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	229	ICRLIN35UR0 		INTRLIN35UR0 RLIN35 transmit interrupt RLIN35 Edge 10E5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_229_ICRLIN35UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_229_ICRLIN35UR0(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vRLIN3UartIsr_Tx(MCU_mRLINUart3_5);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	230	ICRLIN35UR1 		INTRLIN35UR1 RLIN35 reception complete interrupt RLIN35 Edge 10E6H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_230_ICRLIN35UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_230_ICRLIN35UR1(void)
{
#if ( MCU_mRLIN3UartModuleEnable!=0 ) 
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRLIN3UartIsr_Rx(MCU_mRLINUart3_5);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	231	ICRLIN35UR2 		INTRLIN35UR2 RLIN35 status interrupt RLIN35 Edge 10E7H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_231_ICRLIN35UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_231_ICRLIN35UR2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	232	ICPWGA48 		INTPWGA48 PWGA48 interrupt PWGA48 Edge 10E8H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_232_ICPWGA48
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_232_ICPWGA48(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(48);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	233	ICPWGA49 		INTPWGA49 PWGA49 interrupt PWGA49 Edge 10E9H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_233_ICPWGA49
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_233_ICPWGA49(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(49);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	234	ICPWGA50 		INTPWGA50 PWGA50 interrupt PWGA50 Edge 10EAH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_234_ICPWGA50
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_234_ICPWGA50(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(50);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	235	ICPWGA51 		INTPWGA51 PWGA51 interrupt PWGA51 Edge 10EBH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_235_ICPWGA51
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_235_ICPWGA51(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(51);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	236	ICPWGA52 		INTPWGA52 PWGA52 interrupt PWGA52 Edge 10ECH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_236_ICPWGA52
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_236_ICPWGA52(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(52);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	237	ICPWGA53 		INTPWGA53 PWGA53 interrupt PWGA53 Edge 10EDH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_237_ICPWGA53
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_237_ICPWGA53(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(53);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	238	ICPWGA54 		INTPWGA54 PWGA54 interrupt PWGA54 Edge 10EEH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_238_ICPWGA54
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_238_ICPWGA54(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(54);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	239	ICPWGA55 		INTPWGA55 PWGA55 interrupt PWGA55 Edge 10EFH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_239_ICPWGA55
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_239_ICPWGA55(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(55);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	240	ICPWGA56 		INTPWGA56 PWGA56 interrupt PWGA56 Edge 10F0H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_240_ICPWGA56
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_240_ICPWGA56(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(56);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	241	ICPWGA57 		INTPWGA57 PWGA57 interrupt PWGA57 Edge 10F1H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_241_ICPWGA57
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_241_ICPWGA57(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(57);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	242	ICPWGA58 		INTPWGA58 PWGA58 interrupt PWGA58 Edge 10F2H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_242_ICPWGA58
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_242_ICPWGA58(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(58);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	243	ICPWGA59 		INTPWGA59 PWGA59 interrupt PWGA59 Edge 10F3H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_243_ICPWGA59
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_243_ICPWGA59(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(59);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	244	ICPWGA60 		INTPWGA60 PWGA60 interrupt PWGA60 Edge 10F4H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_244_ICPWGA60
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_244_ICPWGA60(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(60);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	245	ICPWGA61 		INTPWGA61 PWGA61 interrupt PWGA61 Edge 10F5H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_245_ICPWGA61
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_245_ICPWGA61(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(61);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	246	ICPWGA62 		INTPWGA62 PWGA62 interrupt PWGA62 Edge 10F6H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_246_ICPWGA62
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_246_ICPWGA62(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(62);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	247	ICPWGA63 		INTPWGA63 PWGA63 interrupt PWGA63 Edge 10F7H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_247_ICPWGA63
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_247_ICPWGA63(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(63);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	248	ICTAUB1I0 		INTTAUB1I0 Interrupt for TAUB1 channel 0 TAUB1 Edge 10F8H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_248_ICTAUB1I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_248_ICTAUB1I0(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_0);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	249	ICTAUB1I1 		INTTAUB1I1 Interrupt for TAUB1 channel 1 TAUB1 Edge 10F9H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_249_ICTAUB1I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_249_ICTAUB1I1(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_1);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	250	ICTAUB1I2 		INTTAUB1I2 Interrupt for TAUB1 channel 2 TAUB1 Edge 10FAH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_250_ICTAUB1I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_250_ICTAUB1I2(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_2);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	251	ICTAUB1I3 		INTTAUB1I3 Interrupt for TAUB1 channel 3 TAUB1 Edge 10FBH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_251_ICTAUB1I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_251_ICTAUB1I3(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_3);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	252	ICTAUB1I4 		INTTAUB1I4 Interrupt for TAUB1 channel 4 TAUB1 Edge 10FCH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_252_ICTAUB1I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_252_ICTAUB1I4(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_4);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	253	ICTAUB1I5 		INTTAUB1I5 Interrupt for TAUB1 channel 5 TAUB1 Edge 10FDH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_253_ICTAUB1I5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_253_ICTAUB1I5(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_5);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	254	ICTAUB1I6 		INTTAUB1I6 Interrupt for TAUB1 channel 6 TAUB1 Edge 10FEH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_254_ICTAUB1I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_254_ICTAUB1I6(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_6);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	255	ICTAUB1I7 		INTTAUB1I7 Interrupt for TAUB1 channel 7 TAUB1 Edge 10FFH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_255_ICTAUB1I7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_255_ICTAUB1I7(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_7);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	256	ICTAUB1I8 		INTTAUB1I8 Interrupt for TAUB1 channel 8 TAUB1 Edge 1100H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_256_ICTAUB1I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_256_ICTAUB1I8(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_8);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	257	ICTAUB1I9 		INTTAUB1I9 Interrupt for TAUB1 channel 9 TAUB1 Edge 1101H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_257_ICTAUB1I9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_257_ICTAUB1I9(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_9);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	258	ICTAUB1I10 		INTTAUB1I10 Interrupt for TAUB1 channel 10 TAUB1 Edge 1102H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_258_ICTAUB1I10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_258_ICTAUB1I10(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_10);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else

	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	259	ICTAUB1I11 		INTTAUB1I11 Interrupt for TAUB1 channel 11 TAUB1 Edge 1103H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_259_ICTAUB1I11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_259_ICTAUB1I11(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_11);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	260	ICTAUB1I12 		INTTAUB1I12 Interrupt for TAUB1 channel 12 TAUB1 Edge 1104H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_260_ICTAUB1I12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_260_ICTAUB1I12(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_12);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	261	ICTAUB1I13 		INTTAUB1I13 Interrupt for TAUB1 channel 13 TAUB1 Edge 1105H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_261_ICTAUB1I13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_261_ICTAUB1I13(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_13);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	262	ICTAUB1I14 		INTTAUB1I14 Interrupt for TAUB1 channel 14 TAUB1 Edge 1106H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_262_ICTAUB1I14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_262_ICTAUB1I14(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_14);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	263	ICTAUB1I15 		INTTAUB1I15 Interrupt for TAUB1 channel 15 TAUB1 Edge 1107H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_263_ICTAUB1I15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_263_ICTAUB1I15(void)
{
#if (MCU_mTAUBDModuleEnable !=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB1_15);

	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	264	ICRCAN4ERR 		INTRCAN4ERR CAN4 error interrupt RSCAN0 Level 1108H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_264_ICRCAN4ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_264_ICRCAN4ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	265	ICRCAN4REC 		INTRCAN4REC CAN4 transmit receive FIFO receive complete interrupt RSCAN0 Level 1109H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_265_ICRCAN4REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_265_ICRCAN4REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	266	ICRCAN4TRX 		INTRCAN4TRX CAN4 transmit interrupt RSCAN0 Level 110AH	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_266_ICRCAN4TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_266_ICRCAN4TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	267	ICRLIN26 		INTRLIN26 RLIN26 interrupt RLIN241 Edge 110BH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_267_ICRLIN26
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_267_ICRLIN26(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	268	ICRLIN27 		INTRLIN27 RLIN27 interrupt RLIN241 Edge 110CH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_268_ICRLIN27
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_268_ICRLIN27(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	269	ICPWGA64 		INTPWGA64 PWGA64 interrupt PWGA64 Edge 110DH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_269_ICPWGA64
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_269_ICPWGA64(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(64);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	270	ICPWGA65 		INTPWGA65 PWGA65 interrupt PWGA65 Edge 110EH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_270_ICPWGA65
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_270_ICPWGA65(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(65);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	271	ICPWGA66 		INTPWGA66 PWGA66 interrupt PWGA66 Edge 110FH *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_271_ICPWGA66
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_271_ICPWGA66(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(66);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	272	ICPWGA67 		INTPWGA67 PWGA67 interrupt PWGA67 Edge 1110H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_272_ICPWGA67
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_272_ICPWGA67(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(67);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	273	ICPWGA68 		INTPWGA68 PWGA68 interrupt PWGA68 Edge 1111H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_273_ICPWGA68
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_273_ICPWGA68(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(68);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	274	ICPWGA69 		INTPWGA69 PWGA69 interrupt PWGA69 Edge 1112H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_274_ICPWGA69
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_274_ICPWGA69(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(69);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	275	ICPWGA70 		INTPWGA70 PWGA70 interrupt PWGA70 Edge 1113H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_275_ICPWGA70
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_275_ICPWGA70(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(70);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	276	ICPWGA71 		INTPWGA71 PWGA71 interrupt PWGA71 Edge 1114H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_276_ICPWGA71
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_276_ICPWGA71(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vPWGACycUpdate(71);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	277	ICRLIN28 		INTRLIN28 RLIN28 interrupt RLIN210 Edge 1115H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_277_ICRLIN28
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_277_ICRLIN28(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	278	ICRLIN29 		INTRLIN29 RLIN29 interrupt RLIN211 Edge 1116H *	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_278_ICRLIN29
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_278_ICRLIN29(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	279	ICRCAN5ERR 		INTRCAN5ERR CAN5 error interrupt RSCAN0 Level 1117H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_279_ICRCAN5ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_279_ICRCAN5ERR(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	280	ICRCAN5REC 		INTRCAN5REC CAN5 transmit receive FIFO receive complete interrupt RSCAN0 Level 1118H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_280_ICRCAN5REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_280_ICRCAN5REC(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	281	ICRCAN5TRX 		INTRCAN5TRX CAN5 transmit interrupt RSCAN0 Level 1119H	

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_281_ICRCAN5TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_281_ICRCAN5TRX(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	282					Reserved 111AH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_282_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_282_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	283					Reserved 111BH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_283_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_283_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	284					Reserved 111CH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_284_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_284_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	285					Reserved 111DH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_285_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_285_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	286					Reserved 111EH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_286_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_286_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/* ###########################################################################

	287					Reserved 111FH 

###########################################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_287_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_287_Reserved(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/


	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/******************************************************

locate at RBASE(default = 0x00000000)


	if PSW.EBV = 0, basic address = RBASE
	if PSW.EBV = 1, basic address = EBASE, reset and system_error vector not shift!!
	
--->>>>the interrupt mode dicided by channel control TBxxx bit	<<<<---

###################################
	priority interrupt service mode:
###################################

	if RBASE.RINT=1, All EINTPRIO_x vector using the same adrress,
				all offset = 0x100 for all
				
	if RBASE.RINT=0, All EINTPRIO_x vector using the its adrress, 
				offset = 0x10 for every one
				
	the EBASE bit 9-31 idencate the requesting interrupt 
	the ISPR idencate the requesting interrupt priority

	interrupt process for priority type:
		1, CPU run to EINTPRIO_x
		2,check the priority level(ISPR) and requesting interrupt vector(EBASE bit 9-31)
		3,run user service function
		
###################################
	table interrupt service mode:
###################################

	Exception handler address read position = 
		INTBP register + channel number x 4 bytes
		
	interrupt process:
	
	1, CPU run to request interrupt function directly and run user service function

**************************************************************/

#endif/*end of this file*/

