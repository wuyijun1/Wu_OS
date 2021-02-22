/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1X_Vector.c
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

#if ( MCU_mINTNestingEnable==0U )

	#define MCU_INT_ENTRY()	do{DI();}while(0)
	#define MCU_INT_EXIT()	do{EI();}while(0)
	
#else

	#define MCU_INT_ENTRY()	do{EI_Force();}while(0)
	#define MCU_INT_EXIT()	do{}while(0)
	
#endif

#ifdef MCU_C

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt Reset
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void Reset(void)
{


}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt HVTRAP
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
#pragma interrupt UCPOP
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
#pragma interrupt Debug
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
#if (MCU_mEINTModuleEnable!=0u)
	MCU_vEINTIsr(MCU_mEINT_ID_NMI);
#endif
}

#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt FEINT
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void FEINT(void)
{

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


/*****************************
		 	WDTA0 	
*****************************/

/*###############################################################
 	75 % interrupt (INTWDTA0) 0 1000 The offset	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_0_INTWDTA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_0_INTWDTA0(void)
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



/*****************************
		 	WDTA1 	
*****************************/

/*###############################################################
 	75 % interrupt (INTWDTA1) 1 1001 +004H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_1_INTWDTA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_1_INTWDTA1(void)
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



/*****************************
		 	RTCA0 	
*****************************/

/*###############################################################
 	1 second interrupt (INTRTCA01S) 2 1002 +008H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_2_INTRTCA01S
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_2_INTRTCA01S(void)
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


/*###############################################################
 	Alarm interrupt (INTRTCA0AL) 3 1003 +00CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_3_INTRTCA0AL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_3_INTRTCA0AL(void)
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


/*###############################################################
 	Fixed interval interrupt (INTRTCA0R) 4 1004 +010H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_4_INTRTCA0R
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_4_INTRTCA0R(void)
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



/*****************************
		 	AWOT0 	
*****************************/

/*###############################################################
 	Timer interrupt (INTAWOT0) 5 1005 +014H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_5_INTAWOT0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_5_INTAWOT0(void)
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



/*****************************
		 	Port 	
*****************************/

/*###############################################################
 	External interrupt 0 (INTP0) 6 1006 +018H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_6_INTP0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_6_INTP0(void)
{
#if ( MCU_mEINTModuleEnable!=0 )
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


/*###############################################################
 	External interrupt 1 (INTP1) 7 1007 +01CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_7_INTP1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_7_INTP1(void)
{
#if ( MCU_mEINTModuleEnable!=0 )
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


/*###############################################################
 	External interrupt 2 (INTP2) 8 1008 +020H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_8_INTP2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_8_INTP2(void)
{
#if ( MCU_mEINTModuleEnable!=0 )
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


/*###############################################################
 	External interrupt 3 (INTP3) 9 1009 +024H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_9_INTP3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_9_INTP3(void)
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


/*###############################################################
 	External interrupt 4 (INTP4) 10 100A +028H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_10_INTP4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_10_INTP4(void)
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


/*###############################################################
 	External interrupt 5 (INTP5) 11 100B +02CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_11_INTP5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_11_INTP5(void)
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


/*###############################################################
 	External interrupt 6 (INTP6) 12 100C +030H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_12_INTP6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_12_INTP6(void)
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


/*###############################################################
 	External interrupt 7 (INTP7) 13 100D +034H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_13_INTP7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_13_INTP7(void)
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


/*###############################################################
 	External interrupt 8 (INTP8) 14 100E +038H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_14_INTP8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_14_INTP8(void)
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


/*###############################################################
 	External interrupt 9 (INTP9) 15 100F +03CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_15_INTP9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_15_INTP9(void)
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


/*###############################################################
 	External interrupt 10 (INTP10) 16 1010 +040H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_16_INTP10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_16_INTP10(void)
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



/*****************************
		 	TAUB0 	
*****************************/

/*###############################################################
 	Channel 0 interrupt (INTTAUB0I0) 17 1011 +044H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_17_INTTAUB0I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_17_INTTAUB0I0(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 1 interrupt (INTTAUB0I1) 18 1012 +048H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_18_INTTAUB0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_18_INTTAUB0I1(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 2 interrupt (INTTAUB0I2) 19 1013 +04CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_19_INTTAUB0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_19_INTTAUB0I2(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 3 interrupt (INTTAUB0I3) 20 1014 +050H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_20_INTTAUB0I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_20_INTTAUB0I3(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 4 interrupt (INTTAUB0I4) 21 1015 +054H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_21_INTTAUB0I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_21_INTTAUB0I4(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 5 interrupt (INTTAUB0I5) 22 1016 +058H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_22_INTTAUB0I5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_22_INTTAUB0I5(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 6 interrupt (INTTAUB0I6) 23 1017 +05CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_23_INTTAUB0I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_23_INTTAUB0I6(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 7 interrupt (INTTAUB0I7) 24 1018 +060H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_24_INTTAUB0I7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_24_INTTAUB0I7(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 8 interrupt (INTTAUB0I8) 25 1019 +064H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_25_INTTAUB0I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_25_INTTAUB0I8(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 9 interrupt (INTTAUB0I9) 26 101A +068H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_26_INTTAUB0I9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_26_INTTAUB0I9(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 10 interrupt (INTTAUB0I10) 27 101B +06CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_27_INTTAUB0I10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_27_INTTAUB0I10(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 11 interrupt (INTTAUB0I11) 28 101C +070H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_28_INTTAUB0I11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_28_INTTAUB0I11(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 12 interrupt (INTTAUB0I12) 29 101D +074H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_29_INTTAUB0I12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_29_INTTAUB0I12(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 13 interrupt (INTTAUB0I13) 30 101E +078H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_30_INTTAUB0I13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_30_INTTAUB0I13(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 14 interrupt (INTTAUB0I14) 31 101F +07CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_31_INTTAUB0I14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_31_INTTAUB0I14(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 15 interrupt (INTTAUB0I15) 32 1020 +080H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_32_INTTAUB0I15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_32_INTTAUB0I15(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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



/*****************************
		 	TAUB1 	
*****************************/

/*###############################################################
 	Channel 0 interrupt (INTTAUB1I0) 33 1021 The offset	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_33_INTTAUB1I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_33_INTTAUB1I0(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 1 interrupt (INTTAUB1I1) 34 1022 +088H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_34_INTTAUB1I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_34_INTTAUB1I1(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 2 interrupt (INTTAUB1I2) 35 1023 +08CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_35_INTTAUB1I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_35_INTTAUB1I2(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 3 interrupt (INTTAUB1I3) 36 1024 +090H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_36_INTTAUB1I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_36_INTTAUB1I3(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 4 interrupt (INTTAUB1I4) 37 1025 +094H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_37_INTTAUB1I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_37_INTTAUB1I4(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 5 interrupt (INTTAUB1I5) 38 1026 +098H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_38_INTTAUB1I5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_38_INTTAUB1I5(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 6 interrupt (INTTAUB1I6) 39 1027 +09CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_39_INTTAUB1I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_39_INTTAUB1I6(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 7 interrupt (INTTAUB1I7) 40 1028 +0A0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_40_INTTAUB1I7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_40_INTTAUB1I7(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 8 interrupt (INTTAUB1I8) 41 1029 +0A4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_41_INTTAUB1I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_41_INTTAUB1I8(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 9 interrupt (INTTAUB1I9) 42 102A +0A8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_42_INTTAUB1I9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_42_INTTAUB1I9(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 10 interrupt (INTTAUB1I10) 43 102B +0ACH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_43_INTTAUB1I10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_43_INTTAUB1I10(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 11 interrupt (INTTAUB1I11) 44 102C +0B0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_44_INTTAUB1I11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_44_INTTAUB1I11(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 12 interrupt (INTTAUB1I12) 45 102D +0B4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_45_INTTAUB1I12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_45_INTTAUB1I12(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 13 interrupt (INTTAUB1I13) 46 102E +0B8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_46_INTTAUB1I13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_46_INTTAUB1I13(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 14 interrupt (INTTAUB1I14) 47 102F +0BCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_47_INTTAUB1I14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_47_INTTAUB1I14(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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


/*###############################################################
 	Channel 15 interrupt (INTTAUB1I15) 48 1030 +0C0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_48_INTTAUB1I15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_48_INTTAUB1I15(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
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



/*****************************
		 	TAUB2 	
*****************************/

/*###############################################################
 	Channel 0 interrupt (INTTAUB2I0) 49 1031 +0C4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_49_INTTAUB2I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_49_INTTAUB2I0(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 1 interrupt (INTTAUB2I1) 50 1032 +0C8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_50_INTTAUB2I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_50_INTTAUB2I1(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 2 interrupt (INTTAUB2I2) 51 1033 +0CCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_51_INTTAUB2I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_51_INTTAUB2I2(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 3 interrupt (INTTAUB2I3) 52 1034 +0D0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_52_INTTAUB2I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_52_INTTAUB2I3(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 4 interrupt (INTTAUB2I4) 53 1035 +0D4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_53_INTTAUB2I4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_53_INTTAUB2I4(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_4);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 5 interrupt (INTTAUB2I5) 54 1036 +0D8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_54_INTTAUB2I5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_54_INTTAUB2I5(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_5);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 6 interrupt (INTTAUB2I6) 55 1037 +0DCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_55_INTTAUB2I6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_55_INTTAUB2I6(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_6);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 7 interrupt (INTTAUB2I7) 56 1038 +0E0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_56_INTTAUB2I7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_56_INTTAUB2I7(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_7);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 8 interrupt (INTTAUB2I8) 57 1039 +0E4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_57_INTTAUB2I8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_57_INTTAUB2I8(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_8);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 9 interrupt (INTTAUB2I9) 58 103A +0E8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_58_INTTAUB2I9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_58_INTTAUB2I9(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_9);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 10 interrupt (INTTAUB2I10) 59 103B +0ECH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_59_INTTAUB2I10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_59_INTTAUB2I10(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 11 interrupt (INTTAUB2I11) 60 103C +0F0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_60_INTTAUB2I11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_60_INTTAUB2I11(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 12 interrupt (INTTAUB2I12) 61 103D +0F4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_61_INTTAUB2I12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_61_INTTAUB2I12(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 13 interrupt (INTTAUB2I13) 62 103E +0F8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_62_INTTAUB2I13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_62_INTTAUB2I13(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 14 interrupt (INTTAUB2I14) 63 103F +0FCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_63_INTTAUB2I14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_63_INTTAUB2I14(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Channel 15 interrupt (INTTAUB2I15) 64 1040 +100H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_64_INTTAUB2I15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_64_INTTAUB2I15(void)
{
#if ( MCU_mTAUBDModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	
	MCU_vTAUx_Isr(MCU_mTAUB2_15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
	
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}



/*****************************
		 	ADCE0 	
*****************************/

/*###############################################################
 	Temperature Sensor interrupt (INTADCE0TSN) 65 1041 +104H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_65_INTADCE0TSN
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_65_INTADCE0TSN(void)
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


/*###############################################################
 	Scan group 1 interrupt (INTADCE0I1) 66 1042 +108H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_66_INTADCE0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_66_INTADCE0I1(void)
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


/*###############################################################
 	Scan group 2 interrupt (INTADCE0I2) 67 1043 +10CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_67_INTADCE0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_67_INTADCE0I2(void)
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


/*###############################################################
 	Scan group 3 interrupt (INTADCE0I3) 68 1044 +110H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_68_INTADCE0I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_68_INTADCE0I3(void)
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



/*****************************
		 	RSCAN 	
*****************************/

/*###############################################################
 	Channel 0 to 2 global error interrupt (INTRCANGERR) 69 1045 +114H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_69_INTRCANGERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_69_INTRCANGERR(void)
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


/*###############################################################
 	Channel 0 to 2 RX FIFO interrupt (INTRCANGRECC) ? 70 1046 +118H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_70_INTRCANGRECC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_70_INTRCANGRECC(void)
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


/*###############################################################
 	Channel 0 error interrupt (INTRCAN0ERR) ? 71 1047 +11CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_71_INTRCAN0ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_71_INTRCAN0ERR(void)
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


/*###############################################################
 	Channel 0 COM RX FIFO interrupt (INTRCAN0REC) ? 72 1048 +120H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_72_INTRCAN0REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_72_INTRCAN0REC(void)
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


/*###############################################################
 	Channel 0 TX interrupt (INTRCAN0TRX) ? 73 1049 +124H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_73_INTRCAN0TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_73_INTRCAN0TRX(void)
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



/*****************************
		 	CSIG0 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIGT0IRE) 74 104A +128H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_74_INTCSIGT0IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_74_INTCSIGT0IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIG0IR) 75 104B +12CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_75_INTCSIG0IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_75_INTCSIG0IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIG0IC) 76 104C +130H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_76_INTCSIG0IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_76_INTCSIG0IC(void)
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



/*****************************
		 	CSIH0 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIH0IRE) 77 104D +134H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_77_INTCSIH0IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_77_INTCSIH0IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIH0IR) 78 104E +138H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_78_INTCSIH0IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_78_INTCSIH0IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIH0IC) 79 104F +13CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_79_INTCSIH0IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_79_INTCSIH0IC(void)
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


/*###############################################################
 	Job completion interrupt (INTCSIH0IJC) 80 1050 +140H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_80_INTCSIH0IJC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_80_INTCSIH0IJC(void)
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



/*****************************
		 	RLIN30 	
*****************************/

/*###############################################################
 	Status interrupt (INTRLIN30UR2) 81 1051 The offset +144H 0 to 15 (15) High	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_81_INTRLIN30UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_81_INTRLIN30UR2(void)
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


/*###############################################################
 	Reception complete interrupt (INTRLIN30UR1) 82 1052 +148H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_82_INTRLIN30UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_82_INTRLIN30UR1(void)
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


/*###############################################################
 	Transmission interrupt (INTRLIN30UR0) 83 1053 +14CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_83_INTRLIN30UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_83_INTRLIN30UR0(void)
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



/*****************************
		 	RLIN31 	
*****************************/

/*###############################################################
 	Status interrupt (INTRLIN31UR2) 84 1054 +150H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_84_INTRLIN31UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_84_INTRLIN31UR2(void)
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


/*###############################################################
 	Reception complete interrupt (INTRLIN31UR1) 85 1055 +154H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_85_INTRLIN31UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_85_INTRLIN31UR1(void)
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


/*###############################################################
 	Transmission interrupt (INTRLIN31UR0) 86 1056 +158H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_86_INTRLIN31UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_86_INTRLIN31UR0(void)
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



/*****************************
		 	SG0 	
*****************************/

/*###############################################################
 	Threshold interrupt (INTSG0TI) 87 1057 +15CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_87_INTSG0TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_87_INTSG0TI(void)
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



/*****************************
		 	SG1	
*****************************/

/*###############################################################
 	Threshold interrupt (INTSG1TI) 88 1058 +160H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_88_INTSG1TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_88_INTSG1TI(void)
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



/*****************************
		 	SG2	
*****************************/

/*###############################################################
 	Threshold interrupt (INTSG2TI) 89 1059 +164H 0 to 15 15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_89_INTSG2TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_89_INTSG2TI(void)
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



/*****************************
		 	SG3	
*****************************/

/*###############################################################
 	Threshold interrupt (INTSG3TI) 90 105A +168H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_90_INTSG3TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_90_INTSG3TI(void)
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



/*****************************
		 	SG4	
*****************************/

/*###############################################################
 	Threshold interrupt (INTSG4TI) 91 105B +16CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_91_INTSG4TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_91_INTSG4TI(void)
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



/*****************************
		 	OCD/DCU 	
*****************************/

/*###############################################################
 	Debugger hot-attach interrupt (INTDCUTDI) ? 92 105C +170H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_92_INTDCUTDI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_92_INTDCUTDI(void)
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



/*****************************
		 	DMAC	
*****************************/

/*###############################################################
 	DMA Transfer Error (INTDMAERR) 93 105D +174H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_93_INTDMAERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_93_INTDMAERR(void)
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


/*###############################################################
 	DMA channel 0 transfer completion/transfer count compare match interrupt (INTDMA0)94 105E +178H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_94_INTDMA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_94_INTDMA0(void)
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


/*###############################################################
 	DMA channel 1 transfer completion/transfer count compare match interrupt (INTDMA1)95 105F +17CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_95_INTDMA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_95_INTDMA1(void)
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


/*###############################################################
 	DMA channel 2 transfer completion/transfer count compare match interrupt (INTDMA2)96 1060 +180H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_96_INTDMA2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_96_INTDMA2(void)
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


/*###############################################################
 	DMA channel 3 transfer completion/transfer count compare match interrupt (INTDMA3)97 1061 +184H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_97_INTDMA3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_97_INTDMA3(void)
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


/*###############################################################
 	DMA channel 4 transfer completion/transfer count compare match interrupt (INTDMA4)98 1062 +188H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_98_INTDMA4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_98_INTDMA4(void)
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


/*###############################################################
 	DMA channel 5 transfer completion/transfer count compare match interrupt (INTDMA5)99 1063 +18CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_99_INTDMA5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_99_INTDMA5(void)
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


/*###############################################################
 	DMA channel 6 transfer completion/transfer count compare match interrupt (INTDMA6)100 1064 +190H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_100_INTDMA6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_100_INTDMA6(void)
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


/*###############################################################
 	DMA channel 7 transfer completion/transfer count compare match interrupt (INTDMA7)101 1065 +194H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_101_INTDMA7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_101_INTDMA7(void)
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


/*###############################################################
 	DMA channel 8 transfer completion/transfer count compare match interrupt (INTDMA8)102 1066 +198H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_102_INTDMA8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_102_INTDMA8(void)
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


/*###############################################################
 	DMA channel 9 transfer completion/transfer countcompare match interrupt (INTDMA9)103 1067 +19CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_103_INTDMA9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_103_INTDMA9(void)
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


/*###############################################################
 	DMA channel 10 transfer completion/transfer countcompare match interrupt (INTDMA10)104 1068 +1A0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_104_INTDMA10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_104_INTDMA10(void)
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


/*###############################################################
 	DMA channel 11 transfer completion/transfer countcompare match interrupt (INTDMA11)105 1069 +1A4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_105_INTDMA11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_105_INTDMA11(void)
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


/*###############################################################
 	DMA channel 12 transfer completion/transfer countcompare match interrupt (INTDMA12)106 106A +1A8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_106_INTDMA12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_106_INTDMA12(void)
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


/*###############################################################
 	DMA channel 13 transfer completion/transfer countcompare match interrupt (INTDMA13)107 106B +1ACH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_107_INTDMA13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_107_INTDMA13(void)
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


/*###############################################################
 	DMA channel 14 transfer completion/transfer countcompare match interrupt (INTDMA14)108 106C +1B0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_108_INTDMA14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_108_INTDMA14(void)
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


/*###############################################################
 	DMA channel 15 transfer completion/transfer countcompare match interrupt (INTDMA15)109 106D +1B4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_109_INTDMA15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_109_INTDMA15(void)
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



/*****************************
		 	RIIC0 	
*****************************/

/*###############################################################
 	Receive error/event interrupt (INTRIIC0LEE) ? 110 106E +1B8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_110_INTRIIC0LEE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_110_INTRIIC0LEE(void)
{
#if ( MCU_mIICModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_Err(MCU_mRIIC_0);
		
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Data received interrupt (INTRIIC0RI) 111 106F +1BCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_111_INTRIIC0RI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_111_INTRIIC0RI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
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


/*###############################################################
 	Data buffer empty interrupt (INTRIIC0TI) 112 1070 +1C0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_112_INTRIIC0TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_112_INTRIIC0TI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
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


/*###############################################################
 	Data transmitted interrupt (INTRIIC0TEI) ? 113 1071 +1C4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_113_INTRIIC0TEI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_113_INTRIIC0TEI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
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



/*****************************
		 	RIIC1 	
*****************************/

/*###############################################################
 	Receive error/event interrupt (INTRIIC1LEE) ? 114 1072 +1C8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_114_INTRIIC1LEE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_114_INTRIIC1LEE(void)
{
#if ( MCU_mIICModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_Err(MCU_mRIIC_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Data received interrupt (INTRIIC1RI) 115 1073 +1CCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_115_INTRIIC1RI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_115_INTRIIC1RI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_ReadByteFinish(MCU_mRIIC_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Data buffer empty interrupt (INTRIIC1TI) 116 1074 +1D0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_116_INTRIIC1TI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_116_INTRIIC1TI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_WriteByteFinish(MCU_mRIIC_1,1u/*Empty request*/);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	Data transmitted interrupt (INTRIIC1TEI) ? 117 1075 +1D4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_117_INTRIIC1TEI
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_117_INTRIIC1TEI(void)
{
#if ( MCU_mIICModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vRIIC_Isr_WriteByteFinish(MCU_mRIIC_1,0u/*Send finish request*/);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}



/*****************************
		 	RSCAN1 	
*****************************/

/*###############################################################
 	Channel 1 error interrupt (INTRCAN1ERR) ? 118 1076 The offset+1D8H 0 to 15 (15) High	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_118_INTRCAN1ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_118_INTRCAN1ERR(void)
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


/*###############################################################
 	Channel 1 COM RX FIFO interrupt (INTRCAN1REC) ? 119 1077 +1DCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_119_INTRCAN1REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_119_INTRCAN1REC(void)
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


/*###############################################################
 	Channel 1 TX interrupt (INTRCAN1TRX) ? 120 1078 +1E0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_120_INTRCAN1TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_120_INTRCAN1TRX(void)
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



/*****************************
		 	TAUJ0 	
*****************************/

/*###############################################################
 	Channel 0 interrupt (INTTAUJ0I0) 121 1079 +1E4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_121_INTTAUJ0I0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_121_INTTAUJ0I0(void)
{
#if ( MCU_mTAUJModuleEnable!=0 )
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


/*###############################################################
 	Channel 1 interrupt (INTTAUJ0I1) 122 107A +1E8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_122_INTTAUJ0I1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_122_INTTAUJ0I1(void)
{
#if ( MCU_mTAUJModuleEnable!=0 )
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


/*###############################################################
 	Channel 2 interrupt (INTTAUJ0I2) 123 107B +1ECH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_123_INTTAUJ0I2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_123_INTTAUJ0I2(void)
{
#if ( MCU_mTAUJModuleEnable!=0 )
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


/*###############################################################
 	Channel 3 interrupt (INTTAUJ0I3) 124 107C +1F0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_124_INTTAUJ0I3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_124_INTTAUJ0I3(void)
{
#if ( MCU_mTAUJModuleEnable!=0 )
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



/*****************************
		 	OSTM0 	
*****************************/

/*###############################################################
 	Timer interrupt (INTOSTM0) 125 107D +1F4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_125_INTOSTM0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_125_INTOSTM0(void)
{
#if ( MCU_mOSTMModuleEnable!=0 )
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



/*****************************
		 	OSTM1 	
*****************************/

/*###############################################################
 	Timer interrupt (INTOSTM1) 126 107E +1F8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_126_INTOSTM1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_126_INTOSTM1(void)
{
#if ( MCU_mOSTMModuleEnable!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/
	MCU_vOSTM_Isr(MCU_mOSTM_1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}



/*****************************
		 	CSIG1 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIGT1IRE) 127 107F +1FCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_127_INTCSIGT1IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_127_INTCSIGT1IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIG1IR) 128 1080 +200H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_128_INTCSIG1IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_128_INTCSIG1IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIG1IC) 129 1081 +204H 0 to 15 15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_129_INTCSIG1IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_129_INTCSIG1IC(void)
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



/*****************************
		 	CSIG2 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIGT2IRE) 130 1082 +208H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_130_INTCSIGT2IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_130_INTCSIGT2IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIG2IR) 131 1083 +20CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_131_INTCSIG2IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_131_INTCSIG2IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIG2IC) 132 1084 +210H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_132_INTCSIG2IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_132_INTCSIG2IC(void)
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



/*****************************
		 	CSIG3 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIGT3IRE) 133 1085 +214H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_133_INTCSIGT3IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_133_INTCSIGT3IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIG3IR) 134 1086 +218H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_134_INTCSIG3IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_134_INTCSIG3IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIG3IC) 135 1087 +21CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_135_INTCSIG3IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_135_INTCSIG3IC(void)
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



/*****************************
		 	CSIH1 	
*****************************/

/*###############################################################
 	Reception error interrupt (INTCSIH1IRE) 136 1088 +220H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_136_INTCSIH1IRE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_136_INTCSIH1IRE(void)
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


/*###############################################################
 	Reception status interrupt (INTCSIH1IR) 137 1089 +224H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_137_INTCSIH1IR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_137_INTCSIH1IR(void)
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


/*###############################################################
 	Communication status interrupt (INTCSIH1IC) 138 108A +228H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_138_INTCSIH1IC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_138_INTCSIH1IC(void)
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


/*###############################################################
 	Job completion interrupt (INTCSIH1IJC) 139 108B +22CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_139_INTCSIH1IJC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_139_INTCSIH1IJC(void)
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



/*****************************
		 	PWGA Generators and Diagnostic	
*****************************/

/*###############################################################
 	A/D Converter trigger queue full interrupt (INTQFULL) 140 108C The offset+230H 0 to 15 (15) High	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_140_INTQFULL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_140_INTQFULL(void)
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


/*###############################################################
 	PWGA Generator channel 0 interrupt (INTPWGA0) 141 108D +234H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_141_INTPWGA0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_141_INTPWGA0(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA0);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 1 interrupt (INTPWGA1) 142 108E +238H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_142_INTPWGA1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_142_INTPWGA1(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA1);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 2 interrupt (INTPWGA2) 143 108F +23CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_143_INTPWGA2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_143_INTPWGA2(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA2);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 3 interrupt (INTPWGA3) 144 1090 +240H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_144_INTPWGA3
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_144_INTPWGA3(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA3);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 4 interrupt (INTPWGA4) 145 1091 +244H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_145_INTPWGA4
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_145_INTPWGA4(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA4);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 5 interrupt (INTPWGA5) 146 1092 +248H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_146_INTPWGA5
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_146_INTPWGA5(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA5);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 6 interrupt (INTPWGA6) 147 1093 +24CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_147_INTPWGA6
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_147_INTPWGA6(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA6);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 7 interrupt (INTPWGA7) 148 1094 +250H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_148_INTPWGA7
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_148_INTPWGA7(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA7);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 8 interrupt (INTPWGA8) 149 1095 +254H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_149_INTPWGA8
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_149_INTPWGA8(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA8);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 9 interrupt (INTPWGA9) 150 1096 +258H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_150_INTPWGA9
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_150_INTPWGA9(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA9);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 10 interrupt (INTPWGA10) 151 1097 +25CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_151_INTPWGA10
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_151_INTPWGA10(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA10);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 11 interrupt (INTPWGA11) 152 1098 +260H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_152_INTPWGA11
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_152_INTPWGA11(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA11);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 12 interrupt (INTPWGA12) 153 1099 +264H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_153_INTPWGA12
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_153_INTPWGA12(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA12);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 13 interrupt (INTPWGA13) 154 109A +268H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_154_INTPWGA13
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_154_INTPWGA13(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA13);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 14 interrupt (INTPWGA14) 155 109B +26CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_155_INTPWGA14
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_155_INTPWGA14(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA14);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 15 interrupt (INTPWGA15) 156 109C +270H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_156_INTPWGA15
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_156_INTPWGA15(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA15);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 16 interrupt (INTPWGA16) 157 109D +274H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_157_INTPWGA16
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_157_INTPWGA16(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA16);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 17 interrupt (INTPWGA17) 158 109E +278H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_158_INTPWGA17
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_158_INTPWGA17(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA17);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 18 interrupt (INTPWGA18) 159 109F +27CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_159_INTPWGA18
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_159_INTPWGA18(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA18);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 19 interrupt (INTPWGA19) 160 10A0 +280H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_160_INTPWGA19
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_160_INTPWGA19(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA19);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 20 interrupt (INTPWGA20) 161 10A1 +284H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_161_INTPWGA20
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_161_INTPWGA20(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA20);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 21 interrupt (INTPWGA21) 162 10A2 +288H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_162_INTPWGA21
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_162_INTPWGA21(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA21);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 22 interrupt (INTPWGA22) 163 10A3 +28CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_163_INTPWGA22
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_163_INTPWGA22(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA22);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}


/*###############################################################
 	PWGA Generator channel 23 interrupt (INTPWGA23) 164 10A4 +290H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_164_INTPWGA23
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_164_INTPWGA23(void)
{
#if ( 0!=0 )
	MCU_INT_ENTRY();
	/*user interrupt function below!*/

	MCU_vPWGACycUpdate(MCU_mPWGA23);
	
	/*user interrupt function above!*/
	MCU_INT_EXIT();
#else
	/*there is un-expected interrupt*/
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrReport(DET_Err_NotExpIntterupt);
#endif
}



/*****************************
		 	ICU-S2 	
*****************************/

/*###############################################################
 	CMD registers ready to write interrupt (INTICUSTWRDY)165 10A5 +294H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_165_INTICUSTWRDY
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_165_INTICUSTWRDY(void)
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


/*###############################################################
 	CMD registers ready to read interrupt(INTICUSTRRDY)166 10A6 +298H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_166_INTICUSTRRDY
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_166_INTICUSTRRDY(void)
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 167 10A7 +29CH 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 168 10A8 +2A0H 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 169 10A9 +2A4H 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 170 10AA +2A8H 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 171 10AB +2ACH 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	Flash control 	
*****************************/

/*###############################################################
 	Flash sequencer ready (INTFLENDNM) 172 10AC +2B0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_172_INTFLENDNM
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_172_INTFLENDNM(void)
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



/*****************************
		 	每 Reserved	
*****************************/

/*###############################################################
 	Reserved 173 10AD +2B4H 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	LCBI0 	
*****************************/

/*###############################################################
 	Read data ready interrupt (INTLCBI0RDY) 174 10AE +2B8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_174_INTLCBI0RDY
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_174_INTLCBI0RDY(void)
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


/*###############################################################
 	Write buffer empty interrupt (INTLCBI0EMPTY) 175 10AF +2BCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_175_INTLCBI0EMPTY
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_175_INTLCBI0EMPTY(void)
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


/*###############################################################
 	Write buffer half full interrupt (INTLCBI0HALF) 176 10B0 +2C0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_176_INTLCBI0HALF
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_176_INTLCBI0HALF(void)
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


/*###############################################################
 	Write buffer full interrupt (INTLCBI0FULL) 177 10B1 +2C4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_177_INTLCBI0FULL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_177_INTLCBI0FULL(void)
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


/*###############################################################
 	Write buffer quarter full interrupt (INTLCBI0QTR) 178 10B2 +2C8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_178_INTLCBI0QTR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_178_INTLCBI0QTR(void)
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


/*###############################################################
 	Write buffer three quarters full interrupt(INTLCBI03QTR)179 10B3 +2CCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_179_INTLCBI03QTR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_179_INTLCBI03QTR(void)
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



/*****************************
		 	RSCAN2 	
*****************************/

/*###############################################################
 	Channel 2 error interrupt (INTRCAN2ERR) ? 180 10B4 +2D0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_180_INTRCAN2ERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_180_INTRCAN2ERR(void)
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


/*###############################################################
 	Channel 2 COM RX FIFO interrupt (INTRCAN2REC) ? 181 10B5 +2D4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_181_INTRCAN2REC
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_181_INTRCAN2REC(void)
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


/*###############################################################
 	Channel 2 TX interrupt (INTRCAN2TRX) ? 182 10B6 +2D8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_182_INTRCAN2TRX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_182_INTRCAN2TRX(void)
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



/*****************************
		 	PCMP0 	
*****************************/

/*###############################################################
 	FIFO buffer fill interrupt (INTPCMP0FFIL) 183 10B7 +2DCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_183_INTPCMP0FFIL
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_183_INTPCMP0FFIL(void)
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


/*###############################################################
 	Error interrupt (INTPCMP0FERR) 184 10B8 +2E0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_184_INTPCMP0FERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_184_INTPCMP0FERR(void)
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



/*****************************
		 	ISM0 	
*****************************/

/*###############################################################
 	Target position reached interrupt(INTISM0REACHED)+2E4H 0 to 15 (15) High	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_185_INTISM0REACHED
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_185_INTISM0REACHED(void)
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


/*###############################################################
 	Idle state interrupt (INTISM0DONE) 186 10BA +2E8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_186_INTISM0DONE
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_186_INTISM0DONE(void)
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


/*###############################################################
 	ZPD measurement started interrupt(INTISM0ZPDAD)187 10BB +2ECH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_187_INTISM0ZPDAD
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_187_INTISM0ZPDAD(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	Reserved 188 10BC +2F0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_188_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_188_Reserved(void)
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



/*****************************
		 	SSIF0 	
*****************************/

/*###############################################################
 	Multi-purpose interrupt (INTSSIF0) ? 189 10BD +2F4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_189_INTSSIF0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_189_INTSSIF0(void)
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


/*###############################################################
 	Reception data full interrupt (INTSSIF0RX) ? 190 10BE +2F8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_190_INTSSIF0RX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_190_INTSSIF0RX(void)
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


/*###############################################################
 	Transmission data empty interrupt (INTSSIF0TX) ? 191 10BF +2FCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_191_INTSSIF0TX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_191_INTSSIF0TX(void)
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



/*****************************
		 	SSIF1 	
*****************************/

/*###############################################################
 	Multi-purpose interrupt (INTSSIF1) ? 192 10C0 +300H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_192_INTSSIF1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_192_INTSSIF1(void)
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


/*###############################################################
 	Reception data full interrupt (INTSSIF1RX) ? 193 10C1 +304H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_193_INTSSIF1RX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_193_INTSSIF1RX(void)
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


/*###############################################################
 	Transmission data empty interrupt (INTSSIF1TX) ? 194 10C2 +308H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_194_INTSSIF1TX
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_194_INTSSIF1TX(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 195 10C3 +30CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_195_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_195_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 196 10C4 +310H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_196_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_196_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 197 10C5 +314H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_197_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_197_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 198 10C6 +318H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_198_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_198_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 199 10C7 +31CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_199_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_199_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 200 10C8 +320H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_200_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_200_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 201 10C9 +324H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_201_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_201_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 202 10CA +328H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_202_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_202_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 203 10CB +32CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_203_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_203_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 204 10CC +330H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_204_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_204_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 205 10CD +334H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_205_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_205_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 206 10CE +338H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_206_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_206_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 207 10CF +33CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_207_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_207_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 208 10D0 +340H 0 to 15 (15)	
###############################################################*/
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 209 10D1 +344H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_209_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_209_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 210 10D2 +348H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_210_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_210_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 211 10D3 +34CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_211_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_211_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 212 10D4 +350H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_212_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_212_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 213 10D5 +354H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_213_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_213_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 214 10D6 +358H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_214_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_214_Reserved(void)
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



/*****************************
		 	RLIN32 	
*****************************/

/*###############################################################
 	Status interrupt interrupt (INTRLIN32UR2) 215 10D7 +35CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_215_INTRLIN32UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_215_INTRLIN32UR2(void)
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


/*###############################################################
 	Reception complete interrupt (INTRLIN32UR1) 216 10D8 +360H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_216_INTRLIN32UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_216_INTRLIN32UR1(void)
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


/*###############################################################
 	Transmission interrupt (INTRLIN32UR0) 217 10D9 +364H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_217_INTRLIN32UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_217_INTRLIN32UR0(void)
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



/*****************************
		 	RLIN33 	
*****************************/

/*###############################################################
 	Status interrupt (INTRLIN33UR2) 218 10DA +368H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_218_INTRLIN33UR2
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_218_INTRLIN33UR2(void)
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


/*###############################################################
 	Reception complete interrupt (INTRLIN33UR1) 219 10DB +36CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_219_INTRLIN33UR1
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_219_INTRLIN33UR1(void)
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


/*###############################################################
 	Transmission interrupt (INTRLIN33UR0) 220 10DC +370H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_220_INTRLIN33UR0
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_220_INTRLIN33UR0(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 221 10DD +374H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_221_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_221_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 222 10DE +378H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_222_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_222_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 223 10DF +37CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_223_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_223_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 224 10E0 +380H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_224_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_224_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 225 10E1 +384H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_225_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_225_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 226 10E2 +388H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_226_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_226_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 227 10E3 +38CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_227_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_227_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 228 10E4 +390H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_228_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_228_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 229 10E5 +394H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_229_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_229_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 230 10E6 +398H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_230_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_230_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 231 10E7 +39CH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_231_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_231_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	每 Reserved 232 10E8 The offset+3A0H 0 to 15 (15) High	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_232_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_232_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 233 10E9 +3A4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_233_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_233_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 234 10EA +3A8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_234_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_234_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 235 10EB +3ACH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_235_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_235_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 236 10EC +3B0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_236_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_236_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 237 10ED +3B4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_237_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_237_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 238 10EE +3B8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_238_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_238_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 239 10EF +3BCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_239_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_239_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 240 10F0 +3C0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_240_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_240_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 241 10F1 +3C4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_241_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_241_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 242 10F2 +3C8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_242_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_242_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 243 10F3 +3CCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_243_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_243_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 244 10F4 +3D0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_244_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_244_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 245 10F5 +3D4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_245_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_245_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 246 10F6 +3D8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_246_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_246_Reserved(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 247 10F7 +3DCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_247_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_247_Reserved(void)
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



/*****************************
		 	CPU Subsystem MISR Error 	
*****************************/

/*###############################################################
 	(INTMISRERR) 248 10F8 +3E0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_248_INTMISRERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_248_INTMISRERR(void)
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


/*###############################################################
 	PBUS I/F 1 overflow (INTVPISG1OVFERR) 249 10F9 +3E4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_249_INTVPISG1OVFERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_249_INTVPISG1OVFERR(void)
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


/*###############################################################
 	PBUS I/F 2 overflow (INTVPISG2OVFERR) 250 10FA +3E8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_250_INTVPISG2OVFERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_250_INTVPISG2OVFERR(void)
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


/*###############################################################
 	PBUS I/F 3 overflow (INTVPISG3OVFERR) 251 10FB +3ECH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_251_INTVPISG3OVFERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_251_INTVPISG3OVFERR(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 252 10FC +3F0H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_252_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_252_Reserved(void)
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



/*****************************
		 	CPU Subsystem 	
*****************************/

/*###############################################################
 	PBUS I/F 5overflow (INTVPISG5OVFERR) 253 10FD +3F4H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_253_INTVPISG5OVFERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_253_INTVPISG5OVFERR(void)
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



/*****************************
		 	每 Reserved 	
*****************************/

/*###############################################################
 	-Reserved 254 10FE +3F8H 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_254_Reserved
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif	
void MCU_vISR_254_Reserved(void)
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



/*****************************
		 	Internal bus errors	
*****************************/

/*###############################################################
 	(INTINTERNALBUSERR)This interrupt is a logical OR combination of various internal bus error indications.
 	The exact cause of this error interrupt evaluated by use of the bus error status registers.can be Refer to Section 7.4.7, 
 	Bus error status registers for details.255 10FF +3FCH 0 to 15 (15)	
###############################################################*/
#if ( COMPILER_TYPE==RENESAS_CSplus )
#pragma interrupt MCU_vISR_255_INTINTERNALBUSERR
#elif ( COMPILER_TYPE==RENESAS_GreenHills )
#pragma ghs interrupt
#endif
void MCU_vISR_255_INTINTERNALBUSERR(void)
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


#endif/*end of this file*/

