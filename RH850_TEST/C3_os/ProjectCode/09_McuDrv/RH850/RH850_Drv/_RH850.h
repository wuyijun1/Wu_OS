/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _RH850.h
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
| 2016.02.23  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifndef _RH850_H
#define _RH850_H

#define MEGA(a)  ((uint32)((a)*1000000ul))

#define DI()	do{extern volatile uint32 MCU_IntNest;asm("DI");++MCU_IntNest;}while(0)

#define EI()		do{extern volatile uint32 MCU_IntNest;if(MCU_IntNest>1u){--MCU_IntNest;}\
					else{MCU_IntNest=0;asm("EI");}}while(0)
					
#define HALT()		do{asm("HALT");}while(0)

#define EI_Force()		do{extern volatile uint32 MCU_IntNest;MCU_IntNest=0;asm("EI");}while(0)





/*################################################
		Port model interface
#################################################*/
#if MCU_mPortModuleEnable !=0u
	#if MCU_mPinDataOperEnable!=0u
		uint16 MCU_u16PinRead(MUC_enPinID u16PinID, uint8 *u8PinValue);
		uint16 MCU_u16PinWrite(MUC_enPinID u16PinID,uint8 u8Value);
	#endif

	#if MCU_mPinDirectOperEnable!=0u
		uint16 MCU_u16PinDirectCfg(MUC_enPinID u16PinID,uint8 u8InOut);
	#endif

	#if MCU_mPinPullUpOperEnable!=0u
		uint16 MCU_u16PinPullUpCfg(MUC_enPinID u16PinID,uint8 u8OnOff);
	#endif

	#if MCU_mPinPullDownOperEnable!=0u
		uint16 MCU_u16PinPullDownCfg(MUC_enPinID u16PinID,uint8 u8OnOff);
	#endif
	
	#if MCU_mPinOpenDEnable!=0u
		uint16 MCU_u16PinOpenDCfg(MUC_enPinID u16PinID,uint8 u8OnOff);
	#endif
	#if (MCU_mPinAltFunChgEnable !=0u)
		uint16 MCU_u16PinAltFunCfg(MUC_enPinID u16PinID,MCU_enPinAltFun AltFun);
	#endif

#endif

/*################################################
		OS timer model interface
#################################################*/
#if MCU_mOSTMModuleEnable!=0u

	void MCU_vOSTM_Isr(MCU_enOstmID OSTM_ID);
	
	#if (MCU_mOstmChangeEnable !=0U)
		uint16 MCU_u16OSTMChgInterval(MCU_enOstmID OSTM_ID,uint32 u32Interval);
	#endif
	
	#if ((MCU_mOstmCtrlEnable !=0) || (MCU_mOstmChangeEnable !=0))
	uint16 MCU_u16OSTMctrl(MCU_enOstmID OSTM_ID,uint32 OnOff);
	#endif
	
#endif/*end of MCU_mOSTMModuleEnable*/


/*################################################
		PWGA model interface
#################################################*/
#if MCU_mPWGAModuleEnable!=0u

		#if MCU_mPWGAdutyChangeEnable!=0u
		uint16 MCU_u16PWGASetDuty(MCU_enPwgaID u16PPG_ID, uint16 u16Duty);
		#endif

#endif

/*################################################
		TUAX model interface
#################################################*/
#if ((MCU_mTAUBDModuleEnable!=0u) || (MCU_mTAUJModuleEnable!=0u))

	#if (MCU_mTAUBDModuleEnable!=0u)
		uint16 MCU_u16TAUBD_Init(void);
	#endif
		
	#if (MCU_mTAUJModuleEnable!=0u)
		uint16 MCU_u16TAUJ_Init(void);
	#endif

	#if MCU_mTauxSetCounterEnable!=0u
		uint16 MCU_u16TAUxSetCounter(MCU_enTauxID TauxID,uint32 u32NewCounte);
	#endif
	
	#if MCU_mTauxSetHzEnable!=0u
		uint16 MCU_u16TAUxPpgSetHz(MCU_enTauxID u32SlaveChID,uint32 u32Hz, uint16 u16Duty)	;
	#endif
	
	#if MCU_mTauxSetDutyEnable!=0u
		uint16 MCU_u16TAUxPpgSetDuty(MCU_enTauxID u32SlaveChID, uint16 u16Duty);
	#endif

	#if MCU_mTuaxRunCtrlEnale!=0u
		void MCU_vTAUxRunCtrl(MCU_enTauxID TauxID,MCU_enTauxRunCtrl OnOff );
	#endif

	#if MCU_mTauxGetCounterEnable!=0u
		uint32 MCU_u32TAUxGetCounter(MCU_enTauxID TauxID);
	#endif
	#if MCU_mTauxGetTimeEnable!=0u
		uint32 MCU_u32TAUxGetTime(MCU_enTauxID TauxID);
	#endif
	void MCU_vTAUx_INTctrl(MCU_enTauxID TauxID, uint32 IntEnable);

#endif



/*################################################
		IIC model interface
#################################################*/
#if MCU_mIICModuleEnable!=0u

		/*uint16 MCU_u16IIC_MasterStartCondition(MCU_enRiicID u8I2C_masterID)
		uint16 MCU_u16IIC_MasterStopCondition(MCU_enRiicID u8I2C_masterID)*/
                 uint16 MCU_u16IIC_MasterWrite(MCU_enRiicID u8I2C_masterID,uint8 u8SalveAddr, uint8 pDataHead[], uint16 u16Lenth);
		
	#if (MCU_mIICReadFunctionEnable !=0u)
                uint16 MCU_u16IIC_MasterRead(MCU_enRiicID u8I2C_masterID,uint8 u8SalveAddr, uint8 *pDataHead, uint16 u16Lenth);
	#endif
		
	#if (MCU_mIICRestartEnable !=0u)
		uint16 MCU_u16IIC_MasterReStartCondition(MCU_enRiicID u8I2C_masterID);
	#endif
		void MCU_vRIIC_Isr_Err(MCU_enRiicID u16Ch);
		void MCU_vRIIC_Isr_WriteByteFinish(MCU_enRiicID u16Ch,uint32 u32BufferEmpty_Req);
		void MCU_vRIIC_Isr_ReadByteFinish(MCU_enRiicID u16Ch);

	#if MCU_mIICdeinitEnable!=0u
		void MCU_vIICdeinit(void);
	#endif

#endif



/*################################################
		Lin-UART model interface
#################################################*/

#if MCU_mRLIN3UartModuleEnable!=0u
		uint16 MCU_u16RLIN3UartSend(MCU_enRlin3UartID u16channel, uint8 pu8DataHead[], uint16 u16SendLen);
		#if (MCU_mRlin3CtrlEnale !=0u)
		uint16 MCU_u16RLIN3UartCtrl(MCU_enRlin3UartID u16channel, uint8 u8SendEnable, uint8 u8RecEnable);
		#endif
		
		void MCU_vRLIN3UartIsr_Tx(MCU_enRlin3UartID u16channel);
		void MCU_vRLIN3UartIsr_Rx(MCU_enRlin3UartID u16channel);

	#if MCU_mRLIN3DeInitFuncEnable!=0u
		void MCU_vRLIN3Uart_Deinit(void);	
	#endif
	
#endif


/*################################################
		interrupt priority control model interface
#################################################*/
#if MCU_mINTPriorityChgEnable!=0u

		uint16 MCU_u16ChangeVectorPriority(MCU_enIsrID u16VectNum,uint16 u16TargePri);
		
#endif


/*################################################
		External Interrupt model interface
#################################################*/
#if MCU_mEINTModuleEnable!=0u

	void MCU_vEINTIsr(MCU_enEintID u32EINTid);
	
	#if MCU_mEINTtrigChgFuncEnable!=0u
		uint16 MCU_u16EINTchgIntCondition(MCU_enEintID u32EintID,MCU_enEintTriggerID u32NewTrigerCondition);
	#endif

	#if MCU_mEINTOnOffCtrlFuncEnable!=0u
		uint16 MCU_u16EINTctrl(MCU_enEintID u32EintID, uint32 OnOff);
	#endif

	#if MCU_mEINTDeInitFuncEnable!=0u
		void MCU_vEINTDeInit(void);
	#endif
	
#endif

/*################################################
		DMA model interface
#################################################*/
#if MCU_mDMAModuleEnable !=0u

	#if (MCU_DMAdefaultSetEnable !=0u)
		  uint16 MCU_u16DMADefaultSetup(MCU_enDmaID u32DMAchn) ;
	#endif
	
	#if (MCU_mDMASetUpIfEnable !=0u)
		uint16 MCU_u16DMAsetup(MCU_tstDMA_SetUp stDMAsetup);		  
	#endif

	#if MCU_mDMADeInitFuncEnable
		  void MCU_vDMADeInit(void);
	#endif

#endif

/*################################################
		ADC model interface
#################################################*/
#if MCU_mADCModuleEnable!=0u

		uint16 MCU_u16ADCgetResault(MCU_enAdcaID u32ChannelID, uint16 *u16AD_Resault);
		uint16 MCU_u16ADCstart(void);
	#if (MCU_mADCstopEnable !=0u)
		uint16 MCU_u16ADCstop(void);
	#endif
	
	#if (MCU_mADCSleepEnable !=0u)
		uint16 MCU_u16ADCsleep(void);
		uint16 MCU_u16ADCwakeUp(void);
	#endif
		
	#if MCU_mADCDeInitFuncEnable!=0u
		void MCU_vADCDeInit(void);
	#endif
	
#endif

/*################################################
		CSI model interface
#################################################*/
#if MCU_mCSIGModuleEnable!=0u

	void MCU_vCSIG_Isr_WriteUnitFinish(MCU_enCsigID u32CsigID);
	void MCU_vCSIG_Isr_ReadUnitFinish(MCU_enCsigID u32CsigID);
	void MCU_vCSIG_Isr_Err(MCU_enCsigID u32CsigID);
	
	#if (MCU_mCSIGMasterWriteEnable !=0u)
		uint16 MCU_u16CSIG_MasterWrite(MCU_enCsigID u32CsigID,uint16 pDataHead[], uint16 u16Lenth_Byte);
	#endif
	#if (MCU_mCSIGMasterSynchRWEnable !=0u)
		uint16 MCU_u16CSIG_MasterSynchRW(MCU_enCsigID u32CsigID,uint16 pSendDataHead[], uint16 pRecDataHead[], uint16 u16Lenth_Byte);
	#endif
	#if (MCU_mCSIGClkPhaseChgEnable !=0u)
		uint16 MCU_u16CSIG_ChgClkType(MCU_enCsigID u32CsigID, MCU_enCsig_ClkType ExpectType);
	#endif
	#if (MCU_mCSIGdeinitEnable!=0u)
		void MCU_vCSIGdeinit(void);
	#endif

#endif

#if (MCU_mCSIHModuleEnable!=0u)

	void MCU_vCSIH_Isr_WriteUnitFinish(MCU_enCsihID u32CsihID);
	void MCU_vCSIH_Isr_ReadUnitFinsh(MCU_enCsihID u32CsihID);
	void MCU_vCSIH_Isr_Err(MCU_enCsihID u32CsihID);

	#if (MCU_mCSIHMasterWriteEnable !=0u)
		uint16 MCU_u16CSIH_MasterWrite(MCU_enCsihID u32CsihID,uint16 pDataHead[], uint16 u16Lenth_Byte);
	#endif
	#if (MCU_mCSIHMasterSynchRWEnable !=0u)
		uint16 MCU_u16CSIH_MasterSynchRW(MCU_enCsihID u32CsihID,uint16 pSendDataHead[], uint16 pRecDataHead[], uint16 u16Lenth_Byte);
	#endif
	#if (MCU_mCSIHClkPhaseChgEnable !=0u)
		uint16 MCU_u16CSIH_ChgClkType(MCU_enCsihID u32CsihID, MCU_enCsih_ClkType ExpectType);
	#endif
	#if (MCU_mCSIHdeinitEnable!=0u)
			void MCU_vCSIHdeinit(void);
	#endif

#endif

/*################################################
		MCU Run mode control interface
#################################################*/

uint16 MCU_u16InterruptCtrl(MCU_enIsrID u16VectNum,uint8 u8IntEnable);
#if (MCU_mClearIF_Enable !=0u)
uint16 MCU_u16InterruptFlagClean(MCU_enIsrID u16VectNum);
#endif


#if (MCU_mFEinterruptEnable !=0u)
uint16 MCU_u16InterruptCtrl_FE(MCU_enIsrID_FE u16VectNum,uint8 u8IntEnable);
/*uint16 MCU_u16InterruptFlagClean_FE(MCU_enIsrID_FE u16VectNum)==> clear by ISR code, not need this function*/
#endif

void MCU_vWatchDogClean(void);

void MCU_vNotExpINT(void);
void MCU_vNotExpINT_u8(uint8 u8Dummy);
void MCU_vNotExpINT_u16(uint16 u16Dummy);
void MCU_vNotExpINT_u32_8(uint32 u32Dummy,uint8 u8DUMMY);

void MCU_vResetCtrl_Reset(void);
void MCU_vStandbyCtrl_ChgToMode(MCU_enRunModeID u8ExpMode);
void MCU_vStandbyCtrl_CleanAllWakeUpFactor(void);
uint32 MCU_u32GetResetReason(void);
 
 #if (MCU_mSackFunctionEnable!=0)
uint32 MCU_u32GetStackBottom(void);
uint32 MCU_u32GetStackTop(void);
uint32 MCU_u32GetCurrentStack(void);
#endif

#endif /*end of this file*/


