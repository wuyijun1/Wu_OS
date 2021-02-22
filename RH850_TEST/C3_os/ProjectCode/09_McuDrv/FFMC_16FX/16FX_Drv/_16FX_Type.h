/*******************************************************************************
| Module Name: MCU Drive for Fujitsu FFMC_16FX serial
| File Name: _16FX_Type.h
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
#ifndef FFMC_16FX_TYPE_H
#define FFMC_16FX_TYPE_H

#define DI()		do{extern volatile uint16 MCU_u16IntNest;__DI();++MCU_u16IntNest;}while(0)

#define EI()		do{extern volatile uint16 MCU_u16IntNest;if(MCU_u16IntNest>1u){--MCU_u16IntNest;}\
					else{MCU_u16IntNest=0;__EI();}}while(0)
					
#define EI_Force()		do{extern volatile uint16 MCU_u16IntNest;MCU_u16IntNest=0;__set_il(7);__EI();}while(0)

/*###########################################################
		Clock Attribute in this serial MCU
###########################################################*/
#define MCU_mOSC_Clock	4000000ul
#define MCU_mCPU_Clock	16000000ul
#define MCU_mCLK1_Clock	16000000ul
#define MCU_mCLK2_Clock	16000000ul
#define MCU_mSub_Clock	30000ul


/*###########################################################
		Port Attribute in this serial MCU
###########################################################*/
#define MCU_mRegisterHead_PortData		0x0000u	/*PDR00 to PDR20*/
#define MCU_mRegisterHead_PinStatus	0x04BCu	/*EPSR00 to EPSR20*/
#define MCU_mRegisterHead_PortDirect	0x0430u	/*DDR00 to DDR20*/
#define MCU_mRegisterHead_PortPullUp	0x04A8u	/*PUCR00 to PUCR20*/	
#define MCU_mRegisterHead_PortPullDown	0xE9890UL	/*PDCR00 to PDCR20*/
#define MCU_mRegisterHead_PortInputEn	0x0444u	/*PIER00 to PIER20*/
#define MCU_mRegisterHead_PortHighDrv	0x0494u	/*PHDR00 to PHDR20*/

#define MCU_mPinMode_Input		0u	/*set this value to direction register for input pin*/
#define MCU_mPinMode_Output		1u	/*set this value to direction register for output pin*/

#define MCU_mMaxPinsInPort		8U /*how many pins in one port gruop.it may be 8 or 16*/
#define MCU_mMaxPortInChip		20U /*how many pins in one port gruop.it may be 8 or 16*/


/*###########################################################
		Re-Load timer Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxReLoadTimerMount		5u/*how many timer max to mount in this serial MCU*/
#define MCU_mTimerMountGroup	1u

#define MCU_mTimerUnitSize		4u		/*timer register group size*/
#define MCU_mTimerDefaultPriLevel	3u

#define MCU_mTimerRegHead_TMCSR	0x0060u	/*&TMCSR0*/
#define MCU_mTimerRegHead_TMRLR	0x0062u	/*&TMCRLR0*/

#define MCU_mTimer_TMCSRvalue	0x041Bu	/*2^4div clock in 16M CLKP1,
										reload mode, 
										EI, 
										Run-enable, 
										start-now*/
/*###########################################################
		vector Attribute in this serial MCU
###########################################################*/

#define MCU_mMinVectNum	11u
#define MCU_mMAxVectNum	147u

#define MCU_mMaxPriLevel			0u/*interrupt priority highest*/
#define MCU_mMinPriLevel			7u/*Not inerrupt*/
#define MCU_mNotINTPriLevel		7u/*Not inerrupt*/


/*###########################################################
		PPG Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxPPGchannelMount		16u/*how many PPG max in a group to mount in this serial MCU*/
#define MCU_mMaxPPGPinRelocate			3u/*one ppg pin relocate in max*/

#define MCU_mPPGUnitSize		8u

#define MCU_mPPGRegHead_PCSR		0x007AU/*&PCSR0*/
#define MCU_mPPGRegHead_PDUT		0x007CU/*&PDUT0*/
#define MCU_mPPGRegHead_PCN			0x007EU/*&PCN0*/
#define MCU_mPPGRegHead_PRRR		0x04D8U/*&PRRR2*/
#define MCU_mPPGRegHead_EPCN		0x0A80U/*&EPCN10*/

#define MCU_mPPGReg_PCNValue			0xD800U/*
												start count wehn reset
												software triger
												PWM mode
												disable restart
												clock divide 16
												not output mask
												16bit PPG
												not external trig select
												not interrupt
												clear interrupt flag
												software trig to start
												output disable-----
												normal output level
												*/
#define MCU_mPPGReg_EPCNValue			0x0300U/*
												output disable-----
												full range mode
												*/

												
/*###########################################################
		EINT Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxEINTchannelMount		16u/*how many EINT max in a group to mount in this serial MCU*/
#define MCU_mMaxEINTPinRelocate		2u/*one EINT pin relocate in max*/

#define MCU_mEINTDefaultPriLevel		4u

#define MCU_mEINTUnitSize		4u

#define MCU_mEINTRegHead_ENIR	0x58u	/*&ENIR0*/
#define MCU_mEINTRegHead_EIRR	0x59u	/*&EIRR0*/
#define MCU_mEINTRegHead_ELVR	0x5Au	/*&ELVR0*/
#define MCU_mEINTRegHead_PRRR	0x04D6u	/*&PRRR0*/




/*###########################################################
		ADC Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxADCchannelMount		32u/*how many ADC max in a group to mount in this serial MCU*/

#define MCU_mADCDefaultPriLevel		5u

#define MCU_mADCRegHead_ADER		0x4D0u/*ADC enable control*/

#define MCU_mADCRegHead_ADSR		0x001Cu/*ADC setting control register*/
#define MCU_mADCRegHead_ADCR		0x001Au/*ADC resault data*/

#define MCU_mADCRegHead_ADCS		0x0018u/*ADC model control register*/
#define MCU_mADCRegValue_ADCS		0xE240u/*ADC model control register:
											interrupt enable,start running,10bit, mode2
											*/


#define MCU_mADCRegValue_ADSR		0xf81fu/*0x001fu -->ADC resualt*/    /*ADC setting control register
											Sampling time = 4 CLKP1 cycles
											Comparison time = 22 CLKP1 cycles
											Start Channel =0
											End Channel=31
											*/
/*###########################################################
		DMA Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxDMAchannelMount		16u/*how many DMA max in a group to mount in this serial MCU*/

#define MCU_mDMAregisterHead_DSR		0x0390u	/*1bit 1 channel*/
#define MCU_mDMAregisterHead_DSSR	0x0392u
#define MCU_mDMAregisterHead_DER		0x0394u

#define MCU_mDMAregisterHead_BAPL	0x0100u	/*channel struct*/
#define MCU_mDMAregisterHead_BAPM	0x0101u
#define MCU_mDMAregisterHead_BAPH	0x0102u
#define MCU_mDMAregisterHead_DMACS	0x0103u
#define MCU_mDMAregisterHead_IOA		0x0104u
#define MCU_mDMAregisterHead_DCT		0x0106u

#define MCU_mDMADescriptSize			8u

#define MCU_mDMAregisterHead_DISEL	0x0380u	/*1byte a channel*/
#define MCU_mDMAregisterHead_IOABK	0x0A00u


/*###########################################################
		UART Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxUARTchannelMount		8u/*how many UART max to mount in this serial MCU*/
#define MCU_mUARTRegisterHead_ESR	0x0BABu
#define MCU_mUARTRegisterHead_EIER	0xE97C8ul

#define MCU_mUARTDefaultPriLevel		5u
#define MCU_mUARTReadyDefValue		0xFFFFu
#define MCU_mUARTUnitSize			0x0Au

/*###########################################################
		ICU Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxICUchannelMount		8u/*how many ICU max to mount in this serial MCU*/
#define MCU_mICURegisterHead_ICS	0x0040u
#define MCU_mICURegisterHead_PRRR4	0x04DAu

#define MCU_mICUDefaultPriLevel		5u
#define MCU_mICUUnitSize			0x06u

/*###########################################################
		LCD Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxLCDSegMount		72u/*how many LCD  max to mount in this serial MCU*/
#define MCU_mMaxCOMMount		4u/*how many LCD  max to mount in this serial MCU*/
#define MCU_mLCDRegisterHead_LCDER	0x061Cu
#define MCU_mLCDRegisterHead_VRAM	0x062Au

/*###########################################################
		I2C Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxIICMount		1u	/*how many i2c  max to mount in this serial MCU*/

#define MCU_mIICDefaultPriLevel		4u

/*##############################################################
	Pin attribute relation register mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMount_Port
{
	/*port data mount mask*/
	uint8 u8PortDataMask[MCU_mMaxPortInChip];
	
	/*port data direction mount mask*/
	uint8 u8PortDirectMask[MCU_mMaxPortInChip];
	
	/*port pull up mount mask*/
	uint8 u8PortPullUpMask[MCU_mMaxPortInChip];
	
	/*port pull down mount mask*/
	uint8 u8PortPullDownMask[MCU_mMaxPortInChip];
	
	/*port High driver mount mask*/
	uint8 u8PortHighDrvMask[MCU_mMaxPortInChip];	
}MCU_tstResourceMount_Port;		




/*########################################################
	Pin attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstPinCfg
{
	bitfield bitPindefalutValue :1;			/*pin default value when reset*/
	bitfield bitPinValueChgable :1;			/*pin value changeable or not*/
	
	bitfield bitPindefalutDirect :1;			/*pin default dircetion when reset*/
	bitfield bitPinDirectChgable :1;			/*pin dircetion changeable or not*/
	
	bitfield bitPinPullUpdefalutValue :1;		/*pin pull-up default value when reset*/
	bitfield bitPinPullUpChgable :1;		/*pin pull-up changeable or not*/

	bitfield bitPinPullDowndefalutValue :1;	/*pin pull-down default value when reset*/
	bitfield bitPinPullDownChgable :1;		/*pin pull-down changeable or not*/
	
	bitfield bitPinHighDrvdefalutValue :1;	/*pin High driver default value when reset*/
	bitfield bitPinHighDrvChgable :1;		/*pin High driver changeable or not*/

	bitfield bitReserve :6;				/*reserve bit filed*/
	
}MCU_tstPinCfg;




/*##############################################################
	Re-Load timer mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMount_ReloadTimer
{
	uint16 u16TimerMountList[MCU_mTimerMountGroup];/*record the mounted timer, one bit is one timer mounted*/
	uint16 u16VectorNumber[MCU_mMaxReLoadTimerMount];/*record the mounted timer vector number*/
}MCU_tstResourceMount_ReloadTimer;



/*########################################################
	Re-Load timer attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstReloadTimerUserCfg
{
	uint16 u16Interval_us;		/*interrupt timer interval*/
	uint16 u16VectorPriority;	/*record the mounted timer vector number*/
	uint8 u8IntervalChangeable;	/*interval timer changeable or not*/	
	vpFun	vpINTservice;		/*interrupt function to run when timer-out*/
}MCU_tstReloadTimerUserCfg;



/*##############################################################
	PPG channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMount_PPG
{
	uint16 u16PPGMountList_PinPPG;
	uint16 u16PPGMountList_PinPPG_R;
	uint16 u16PPGMountList_PinPPG_B;
	uint16 u16PPGCycleMatchVector[MCU_mMaxPPGchannelMount];
}MCU_tstResourceMount_PPG;




/*########################################################
	PPG channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstPPGCfg
{
	uint8 u8LocatPinMask;		/*mask for output pin*/
	uint16 u16Hz;				/*PPG frequency in defalue Run*/
	uint16 u16Duty;			/*PPG duty in defalue Run*/	
	uint8 u8HzChangeable;		/*mask frequency changeable or not*/
	uint8 u8DutyChangeable;	/*mask frequency changeable or not*/
}MCU_tstPPGCfg;


/*##############################################################
	External interrupt channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_EINT
{
	uint16 u16PinMount_INT;
	uint16 u16PinMount_INT_R;
	uint16 u16VectorNumber[MCU_mMaxEINTchannelMount];
}MCU_tstResourceMnt_EINT;


/*########################################################
	External interrupt channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstEINTCfg
{
	uint8 u8LocatPinMask;		/*mask for input pin*/
	uint8 u8DetectCondition;		/*what conditon to triger interrupt*/
	uint8 u8DetConditionChgable;	/*conditon to triger interrupt can be change or not*/
	uint8 u8RunWhenReset;		/*the interrupt will run when reset on*/
	uint16 u16VectorPriority;	/*record the mounted timer vector number*/
	vpFun	vpINTservice;		/*interrupt function to run when timer-out*/
}MCU_tstEINTCfg;


/*##############################################################
	ADC channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_ADC
{
	uint16 u16VectorNumber;
	uint32 u32ADCMountMask;/*max is 32 channel in this serial, so use 32bit to mask*/
}MCU_tstResourceMnt_ADC;


/*########################################################
	ADC channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstADCCfg
{
	uint16 u16VectorPriority;	/*record the mounted timer vector number*/
	uint32 u32ADCusing;		/*max is 32 channel in this serial, so use 32bit to mask*/
}MCU_tstADCCfg;


/*##############################################################
	DMA channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_DMA
{
	uint16 u16DMAmountMask;
}MCU_tstResourceMnt_DMA;


/*########################################################
	DMA channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstDMACfg
{
	uint32 u32SourceAddr;
	uint16 u16SourceChgType;		/*0= lock, 1=up, 2=down*/
	uint32 u32DestinationAddr;
	uint16 u16DestinationChgType;	/*0= lock, 1=up, 2=down*/
	uint16 u16DataUnitSize;			/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataTattolSize;		/*how many byte data to transfer*/
	uint16 u16VectorNum;			/*which interrupt to control*/
}MCU_tstDMACfg;

/*##############################################################
	UART channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_UART
{
	uint16 u16VectorNumber_RX[MCU_mMaxUARTchannelMount];
	uint16 u16VectorNumber_TX[MCU_mMaxUARTchannelMount];
	uint16 u16UARTMountMask_SINn;
	uint16 u16UARTMountMask_SINn_R;
}MCU_tstResourceMnt_UART;

/*########################################################
	UART channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstUARTCfg
{
	uint16 u16BaudRate;	/*transfer speed*/
	uint8 u8LocatPinMask;	/*mask for relocate pin*/
	uint8 u8MsbLsb;			/*data direction: MSB or LSB*/
	uint8 u8StopBit;		/*stop bit lenth, 1bit or 2bit*/
	uint8 u8Parity;			/*Parity type, Even Parity or Odd Parity enabled*/
	uint8 u8VectorPriority;
	
	vpFun vpSendFinish;				/*send finish callback*/
	vpFun_u8 vu8ErrCallBack;			/*error call back*/
	vpFun_u8 vu8RecCallBack;			/*recieve data callback*/
	
}MCU_tstUARTCfg;

/*########################################################
	UART channel attribute control for work status
########################################################*/
typedef struct _MCU_tstUARTCtrl
{
	uint16 u16TottalLen;
	uint16 u16SendingLen;
	uint8 *pDataHead;
}MCU_tstUARTCtrl;


/*##############################################################
	ICU channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_ICU
{
	uint16 u16InPutPin[MCU_mMaxICUchannelMount];
	uint16 u16InPutPin_R[MCU_mMaxICUchannelMount];
	uint16 u16ICUvectorTable[MCU_mMaxICUchannelMount];
	uint16 u16ICUMountMask;
}MCU_tstResourceMnt_ICU;

/*########################################################
	ICU channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstICUCfg
{
	uint8 u8LocatPinMask;	/*mask for relocate pin*/
	uint8 u8DetectEdge;	/*which edge to trig interrupt*/
	uint8 u8DetChgable;	/*the detcet level changeable or not*/
	uint8 u8VectorPriority;
	uint8 u8RunInRst;		/*ICU run or not after model init*/
	vpFun_u32_u8 vu32DetCallBack;			/*detect data callback*/
}MCU_tstICUCfg;

/*##############################################################
	LCD mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_LCD
{
	uint8 u8ComMount;					/*the select COM pins for LCD driver*/
	uint8 u8SegMount[MCU_mMaxLCDSegMount/8u];	/*the select segment pins for LCD driver*/
}MCU_tstResourceMnt_LCD;

/*########################################################
	LCD attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstLCDCfg
{
	uint8 u8VoltageDiv;			/*mask for LCD driver voltage divide connect internal or external*/
	uint8 u8DrvFrequency;		/*conf for LCD drv frequency, choose a OK value to LCD special to avoid shadow*/
	uint8 u8ComUse;			/*the select COM pins for LCD driver*/
	uint8 u8SegUse[MCU_mMaxLCDSegMount/8u];	/*the select segment pins for LCD driver*/
}MCU_tstLCDCfg;


/*##############################################################
	I2C mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_IIC
{
	uint16 u16I2CMounte;
	uint16 u16I2CvectorTable[MCU_mMaxIICMount];
}MCU_tstResourceMnt_IIC;

/*##############################################################
	I2C mount in this serial chip,configerate it for difference project
################################################################*/
typedef struct _MCU_tstIICCfg
{
	/*uint8 u8SlaveAddrLenth	7bit or 10bit*/
	uint8 u8VectorPriority;
	uint16 u16TansferSpeed;	/*IIC model clock setting*/
	
	struct {
		vpFun vpSendfinishCB;
		vpFun vpRecFinishCB;
		vpFun_u8 vu8ErrCB;
	}stSlaveCB[MCU_mI2CMaxSlaveInOneMaster];
}MCU_tstIICCfg;

/*##############################################################
	I2C running status control
################################################################*/
typedef struct _MCU_tstIICctrl
{
	uint8 u8InitStatus;
	uint8 u8StartConditionNeed;
	uint8 u8SlaveChannel;
	uint8 u8RunningMode;
	uint8 u8Error;
	uint8 *pu8DataHead;
	uint16 u16WorkingDataLen;
	uint16 u16TottalDataLen;
}MCU_tstIICctrl;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} MCU_tstDDR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
}MCU_tstPDR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} MCU_tstPUCR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PD7:1;
			__BYTE	PD6:1;
			__BYTE	PD5:1;
			__BYTE	PD4:1;
			__BYTE	PD3:1;
			__BYTE	PD2:1;
			__BYTE	PD1:1;
			__BYTE	PD0:1;
#else
			__BYTE	PD0:1;
			__BYTE	PD1:1;
			__BYTE	PD2:1;
			__BYTE	PD3:1;
			__BYTE	PD4:1;
			__BYTE	PD5:1;
			__BYTE	PD6:1;
			__BYTE	PD7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PD7:1;
			__BYTE	PD6:1;
			__BYTE	PD5:1;
			__BYTE	PD4:1;
			__BYTE	PD3:1;
			__BYTE	PD2:1;
			__BYTE	PD1:1;
			__BYTE	PD0:1;
#else
			__BYTE	PD0:1;
			__BYTE	PD1:1;
			__BYTE	PD2:1;
			__BYTE	PD3:1;
			__BYTE	PD4:1;
			__BYTE	PD5:1;
			__BYTE	PD6:1;
			__BYTE	PD7:1;
#endif
	} bitc;
} MCU_tstPDCR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HD7:1;
			__BYTE	HD6:1;
			__BYTE	HD5:1;
			__BYTE	HD4:1;
			__BYTE	HD3:1;
			__BYTE	HD2:1;
			__BYTE	HD1:1;
			__BYTE	HD0:1;
#else
			__BYTE	HD0:1;
			__BYTE	HD1:1;
			__BYTE	HD2:1;
			__BYTE	HD3:1;
			__BYTE	HD4:1;
			__BYTE	HD5:1;
			__BYTE	HD6:1;
			__BYTE	HD7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HD7:1;
			__BYTE	HD6:1;
			__BYTE	HD5:1;
			__BYTE	HD4:1;
			__BYTE	HD3:1;
			__BYTE	HD2:1;
			__BYTE	HD1:1;
			__BYTE	HD0:1;
#else
			__BYTE	HD0:1;
			__BYTE	HD1:1;
			__BYTE	HD2:1;
			__BYTE	HD3:1;
			__BYTE	HD4:1;
			__BYTE	HD5:1;
			__BYTE	HD6:1;
			__BYTE	HD7:1;
#endif
	} bitc;
} MCU_tstPHDR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} MCU_tstPIER;
typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV10:1;
			__WORD	FSEL:1;
			__WORD	CSL:2;
			__WORD	MOD:3;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD:3;
			__WORD	CSL:2;
			__WORD	FSEL:1;
			__WORD	RESV10:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	CSL1:1;
			__WORD	CSL0:1;
			__WORD	MOD2:1;
			__WORD	MOD1:1;
			__WORD	MOD0:1;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD0:1;
			__WORD	MOD1:1;
			__WORD	MOD2:1;
			__WORD	CSL0:1;
			__WORD	CSL1:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bitc;
} MCU_tstTMCSR;
typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} MCU_tstEPCN;

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS:2;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS:2;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS:2;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS:2;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS:2;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS:2;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS1:1;
			__WORD	CKS0:1;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS1:1;
			__WORD	EGS0:1;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS1:1;
			__WORD	IRS0:1;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS0:1;
			__WORD	IRS1:1;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS0:1;
			__WORD	EGS1:1;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS0:1;
			__WORD	CKS1:1;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bitc;
} MCU_tstPCN;

typedef union {
	__BYTE	byte;
}MCU_tstPRRR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	EN7:1;
			__BYTE	EN6:1;
			__BYTE	EN5:1;
			__BYTE	EN4:1;
			__BYTE	EN3:1;
			__BYTE	EN2:1;
			__BYTE	EN1:1;
			__BYTE	EN0:1;
#else
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	EN3:1;
			__BYTE	EN4:1;
			__BYTE	EN5:1;
			__BYTE	EN6:1;
			__BYTE	EN7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	EN7:1;
			__BYTE	EN6:1;
			__BYTE	EN5:1;
			__BYTE	EN4:1;
			__BYTE	EN3:1;
			__BYTE	EN2:1;
			__BYTE	EN1:1;
			__BYTE	EN0:1;
#else
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	EN3:1;
			__BYTE	EN4:1;
			__BYTE	EN5:1;
			__BYTE	EN6:1;
			__BYTE	EN7:1;
#endif
	} bitc;
} MCU_tstENIR;

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	LALB7:2;
			__WORD	LALB6:2;
			__WORD	LALB5:2;
			__WORD	LALB4:2;
			__WORD	LALB3:2;
			__WORD	LALB2:2;
			__WORD	LALB1:2;
			__WORD	LALB0:2;
#else
			__WORD	LALB0:2;
			__WORD	LALB1:2;
			__WORD	LALB2:2;
			__WORD	LALB3:2;
			__WORD	LALB4:2;
			__WORD	LALB5:2;
			__WORD	LALB6:2;
			__WORD	LALB7:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	LALB71:1;
			__WORD	LALB70:1;
			__WORD	LALB61:1;
			__WORD	LALB60:1;
			__WORD	LALB51:1;
			__WORD	LALB50:1;
			__WORD	LALB41:1;
			__WORD	LALB40:1;
			__WORD	LALB31:1;
			__WORD	LALB30:1;
			__WORD	LALB21:1;
			__WORD	LALB20:1;
			__WORD	LALB11:1;
			__WORD	LALB10:1;
			__WORD	LALB01:1;
			__WORD	LALB00:1;
#else
			__WORD	LALB00:1;
			__WORD	LALB01:1;
			__WORD	LALB10:1;
			__WORD	LALB11:1;
			__WORD	LALB20:1;
			__WORD	LALB21:1;
			__WORD	LALB30:1;
			__WORD	LALB31:1;
			__WORD	LALB40:1;
			__WORD	LALB41:1;
			__WORD	LALB50:1;
			__WORD	LALB51:1;
			__WORD	LALB60:1;
			__WORD	LALB61:1;
			__WORD	LALB70:1;
			__WORD	LALB71:1;
#endif
	} bitc;
} MCU_tstELVR;
typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ER7:1;
			__BYTE	ER6:1;
			__BYTE	ER5:1;
			__BYTE	ER4:1;
			__BYTE	ER3:1;
			__BYTE	ER2:1;
			__BYTE	ER1:1;
			__BYTE	ER0:1;
#else
			__BYTE	ER0:1;
			__BYTE	ER1:1;
			__BYTE	ER2:1;
			__BYTE	ER3:1;
			__BYTE	ER4:1;
			__BYTE	ER5:1;
			__BYTE	ER6:1;
			__BYTE	ER7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ER7:1;
			__BYTE	ER6:1;
			__BYTE	ER5:1;
			__BYTE	ER4:1;
			__BYTE	ER3:1;
			__BYTE	ER2:1;
			__BYTE	ER1:1;
			__BYTE	ER0:1;
#else
			__BYTE	ER0:1;
			__BYTE	ER1:1;
			__BYTE	ER2:1;
			__BYTE	ER3:1;
			__BYTE	ER4:1;
			__BYTE	ER5:1;
			__BYTE	ER6:1;
			__BYTE	ER7:1;
#endif
	} bitc;
} MCU_tstEIRR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BK7:1;
			__BYTE	BK6:1;
			__BYTE	BK5:1;
			__BYTE	BK4:1;
			__BYTE	BK3:1;
			__BYTE	BK2:1;
			__BYTE	BK1:1;
			__BYTE	BK0:1;
#else
			__BYTE	BK0:1;
			__BYTE	BK1:1;
			__BYTE	BK2:1;
			__BYTE	BK3:1;
			__BYTE	BK4:1;
			__BYTE	BK5:1;
			__BYTE	BK6:1;
			__BYTE	BK7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BK7:1;
			__BYTE	BK6:1;
			__BYTE	BK5:1;
			__BYTE	BK4:1;
			__BYTE	BK3:1;
			__BYTE	BK2:1;
			__BYTE	BK1:1;
			__BYTE	BK0:1;
#else
			__BYTE	BK0:1;
			__BYTE	BK1:1;
			__BYTE	BK2:1;
			__BYTE	BK3:1;
			__BYTE	BK4:1;
			__BYTE	BK5:1;
			__BYTE	BK6:1;
			__BYTE	BK7:1;
#endif
	} bitc;
} MCU_tstIOABK;
typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} MCU_tstDMA;
typedef struct _stUART{
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	MD:2;
			uint8	OTO:1;
			uint8	EXT:1;
			uint8	REST:1;
			uint8	UPCL:1;
			uint8	SCKE:1;
			uint8	SOE:1;
#else
			uint8	SOE:1;
			uint8	SCKE:1;
			uint8	UPCL:1;
			uint8	REST:1;
			uint8	EXT:1;
			uint8	OTO:1;
			uint8	MD:2;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	MD1:1;
			uint8	MD0:1;
			uint8	OTO:1;
			uint8	EXT:1;
			uint8	REST:1;
			uint8	UPCL:1;
			uint8	SCKE:1;
			uint8	SOE:1;
#else
			uint8	SOE:1;
			uint8	SCKE:1;
			uint8	UPCL:1;
			uint8	REST:1;
			uint8	EXT:1;
			uint8	OTO:1;
			uint8	MD0:1;
			uint8	MD1:1;
#endif
		} bitc;
	} SMR0;
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	PEN:1;
			uint8	P:1;
			uint8	SBL:1;
			uint8	CL:1;
			uint8	AD:1;
			uint8	CRE:1;
			uint8	RXE:1;
			uint8	TXE:1;
#else
			uint8	TXE:1;
			uint8	RXE:1;
			uint8	CRE:1;
			uint8	AD:1;
			uint8	CL:1;
			uint8	SBL:1;
			uint8	P:1;
			uint8	PEN:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	PEN:1;
			uint8	P:1;
			uint8	SBL:1;
			uint8	CL:1;
			uint8	AD:1;
			uint8	CRE:1;
			uint8	RXE:1;
			uint8	TXE:1;
#else
			uint8	TXE:1;
			uint8	RXE:1;
			uint8	CRE:1;
			uint8	AD:1;
			uint8	CL:1;
			uint8	SBL:1;
			uint8	P:1;
			uint8	PEN:1;
#endif
		} bitc;
	} SCR0;
	uint8	RDR0;
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	PE:1;
			uint8	ORE:1;
			uint8	FRE:1;
			uint8	RDRF:1;
			uint8	TDRE:1;
			uint8	BDS:1;
			uint8	RIE:1;
			uint8	TIE:1;
#else
			uint8	TIE:1;
			uint8	RIE:1;
			uint8	BDS:1;
			uint8	TDRE:1;
			uint8	RDRF:1;
			uint8	FRE:1;
			uint8	ORE:1;
			uint8	PE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	PE:1;
			uint8	ORE:1;
			uint8	FRE:1;
			uint8	RDRF:1;
			uint8	TDRE:1;
			uint8	BDS:1;
			uint8	RIE:1;
			uint8	TIE:1;
#else
			uint8	TIE:1;
			uint8	RIE:1;
			uint8	BDS:1;
			uint8	TDRE:1;
			uint8	RDRF:1;
			uint8	FRE:1;
			uint8	ORE:1;
			uint8	PE:1;
#endif
		} bitc;
	} SSR0;
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	INV:1;
			uint8	LBR:1;
			uint8	MS:1;
			uint8	SCDE:1;
			uint8	SSM:1;
			uint8	BIE:1;
			uint8	RBI:1;
			uint8	TBI:1;
#else
			uint8	TBI:1;
			uint8	RBI:1;
			uint8	BIE:1;
			uint8	SSM:1;
			uint8	SCDE:1;
			uint8	MS:1;
			uint8	LBR:1;
			uint8	INV:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	INV:1;
			uint8	LBR:1;
			uint8	MS:1;
			uint8	SCDE:1;
			uint8	SSM:1;
			uint8	BIE:1;
			uint8	RBI:1;
			uint8	TBI:1;
#else
			uint8	TBI:1;
			uint8	RBI:1;
			uint8	BIE:1;
			uint8	SSM:1;
			uint8	SCDE:1;
			uint8	MS:1;
			uint8	LBR:1;
			uint8	INV:1;
#endif
		} bitc;
	} ECCR0;
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	LBIE:1;
			uint8	LBD:1;
			uint8	LBL:2;
			uint8	SOPE:1;
			uint8	SIOP:1;
			uint8	CCO:1;
			uint8	SCES:1;
#else
			uint8	SCES:1;
			uint8	CCO:1;
			uint8	SIOP:1;
			uint8	SOPE:1;
			uint8	LBL:2;
			uint8	LBD:1;
			uint8	LBIE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	LBIE:1;
			uint8	LBD:1;
			uint8	LBL1:1;
			uint8	LBL0:1;
			uint8	SOPE:1;
			uint8	SIOP:1;
			uint8	CCO:1;
			uint8	SCES:1;
#else
			uint8	SCES:1;
			uint8	CCO:1;
			uint8	SIOP:1;
			uint8	SOPE:1;
			uint8	LBL0:1;
			uint8	LBL1:1;
			uint8	LBD:1;
			uint8	LBIE:1;
#endif
		} bitc;
	} ESCR0;
	union {
		uint16	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint16	BGRH0:8;
			uint16	BGRL0:8;
#else
			uint16	BGRL0:8;
			uint16	BGRH0:8;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint16	BGRH07:1;
			uint16	BGRH06:1;
			uint16	BGRH05:1;
			uint16	BGRH04:1;
			uint16	BGRH03:1;
			uint16	BGRH02:1;
			uint16	BGRH01:1;
			uint16	BGRH00:1;
			uint16	BGRL07:1;
			uint16	BGRL06:1;
			uint16	BGRL05:1;
			uint16	BGRL04:1;
			uint16	BGRL03:1;
			uint16	BGRL02:1;
			uint16	BGRL01:1;
			uint16	BGRL00:1;
#else
			uint16	BGRL00:1;
			uint16	BGRL01:1;
			uint16	BGRL02:1;
			uint16	BGRL03:1;
			uint16	BGRL04:1;
			uint16	BGRL05:1;
			uint16	BGRL06:1;
			uint16	BGRL07:1;
			uint16	BGRH00:1;
			uint16	BGRH01:1;
			uint16	BGRH02:1;
			uint16	BGRH03:1;
			uint16	BGRH04:1;
			uint16	BGRH05:1;
			uint16	BGRH06:1;
			uint16	BGRH07:1;
#endif
		} bitc;
	} BGR0;
	union {
		uint8	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	RESV87:1;
			uint8	RESV86:1;
			uint8	RESV85:1;
			uint8	RESV84:1;
			uint8	TDRE:1;
			uint8	RDRF:1;
			uint8	RBI:1;
			uint8	AICD:1;
#else
			uint8	AICD:1;
			uint8	RBI:1;
			uint8	RDRF:1;
			uint8	TDRE:1;
			uint8	RESV84:1;
			uint8	RESV85:1;
			uint8	RESV86:1;
			uint8	RESV87:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			uint8	RESV87:1;
			uint8	RESV86:1;
			uint8	RESV85:1;
			uint8	RESV84:1;
			uint8	TDRE:1;
			uint8	RDRF:1;
			uint8	RBI:1;
			uint8	AICD:1;
#else
			uint8	AICD:1;
			uint8	RBI:1;
			uint8	RDRF:1;
			uint8	TDRE:1;
			uint8	RESV84:1;
			uint8	RESV85:1;
			uint8	RESV86:1;
			uint8	RESV87:1;
#endif
		} bitc;
	} ESIR0;
	uint8	FIDR0;
}MCU_tstUART;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bitc;
} MCU_tstEIER;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} MCU_tstESR;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP1:1;
			__BYTE	ICP0:1;
			__BYTE	ICE1:1;
			__BYTE	ICE0:1;
			__BYTE	EG1:2;
			__BYTE	EG0:2;
#else
			__BYTE	EG0:2;
			__BYTE	EG1:2;
			__BYTE	ICE0:1;
			__BYTE	ICE1:1;
			__BYTE	ICP0:1;
			__BYTE	ICP1:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP1:1;
			__BYTE	ICP0:1;
			__BYTE	ICE1:1;
			__BYTE	ICE0:1;
			__BYTE	EG11:1;
			__BYTE	EG10:1;
			__BYTE	EG01:1;
			__BYTE	EG00:1;
#else
			__BYTE	EG00:1;
			__BYTE	EG01:1;
			__BYTE	EG10:1;
			__BYTE	EG11:1;
			__BYTE	ICE0:1;
			__BYTE	ICE1:1;
			__BYTE	ICP0:1;
			__BYTE	ICP1:1;
#endif
	} bitc;
} MCU_tstICS;

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS0:1;
			__BYTE	IEI1:1;
			__BYTE	IEI0:1;
#else
			__BYTE	IEI0:1;
			__BYTE	IEI1:1;
			__BYTE	ICUS0:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS0:1;
			__BYTE	IEI1:1;
			__BYTE	IEI0:1;
#else
			__BYTE	IEI0:1;
			__BYTE	IEI1:1;
			__BYTE	ICUS0:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} MCU_tstICE;

#endif/*end of this file*/


