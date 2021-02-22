/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial
| File Name: _78K0R_Type.h
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
#ifndef _78K0R_TYPE_H
#define _78K0R_TYPE_H

/*###########################################################
		Special liberary function macro in this serial MCU
###########################################################*/
#define DI()		do{extern volatile uint16 MCU_u16IntNest;__disable_interrupt();++MCU_u16IntNest;}while(0)

#define EI()		do{extern volatile uint16 MCU_u16IntNest;if(MCU_u16IntNest>1u){--MCU_u16IntNest;}\
					else{MCU_u16IntNest=0;__enable_interrupt();}}while(0)
					
#define EI_Force()		do{extern volatile uint16 MCU_u16IntNest;MCU_u16IntNest=0;__enable_interrupt();}while(0)
					
#define HALT()	do{extern volatile uint16 MCU_u16IntNest;MCU_u16IntNest=0;__enable_interrupt();__halt();}while(0)
#define STOP()	do{extern volatile uint16 MCU_u16IntNest;MCU_u16IntNest=0;__enable_interrupt();__stop();}while(0)
#define NOP()		do{__no_operation();}while(0)

/*###########################################################
		Port Attribute in this serial MCU
###########################################################*/
#define MCU_mRegisterHead_PortData		0xFF00u	/*PDR00 to PDR20*/
#define MCU_mRegisterHead_PortDirect	0xFF20u	/*DDR00 to DDR20*/
#define MCU_mRegisterHead_PortPullUp	0x0030u	/*PUCR00 to PUCR20*/	

#define MCU_mPinMode_Input		1u	/*set this value to direction register for input pin*/
#define MCU_mPinMode_Output		0u	/*set this value to direction register for output pin*/

#define MCU_mMaxPinsInPort		8U /*how many pins in one port gruop.it may be 8 or 16*/
#define MCU_mMaxPortInChip		16U /*how many pins in one port gruop.it may be 8 or 16*/

#define MCU_mLVIDisable	0xFF

/*###########################################################
		Re-Load timer Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxTimerIDMount		24u/*how many timer max to mount in this serial MCU*/
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

#define MCU_mTimerArrayRegHead	0x0180u
#define MCU_mTimerTDRRegHead	0xFF60u

/*###########################################################
		vector Attribute in this serial MCU
###########################################################*/

#define MCU_mMinVectNum	4u
#define MCU_mMAxVectNum	0x7Cu
#define MCU_mMaskBitHead	0xFFE4u
#define MCU_mIFBitHead	0xFFE0u

#define MCU_mMaxPriLevel			0u/*interrupt priority highest*/
#define MCU_mMinPriLevel			3u/*inerrupt priority lowest*/


												
/*###########################################################
		EINT Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxEINTchannelMount		9u/*how many EINT max in a group to mount in this serial MCU*/

#define MCU_mEINTUnitSize		2u

#define MCU_mEINTRegHead_EGP	0xFF38u	/*&EPG0*/


/*###########################################################
		ADC Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxADCchannelMount		24u/*how many ADC max in a group to mount in this serial MCU*/

#define MCU_mADCresaultHead		0x0280u


/*###########################################################
		serial Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxSerialchannelMount		6u/*how Serial max in a group to mount in this serial MCU*/
#define MCU_mMaxCSIchannelMount		4u/*how Serial max in a group to mount in this serial MCU*/

#define MCU_mSerialGroupHead		0x0100u
#define MCU_mSDRHead_Group0_1		0xff10u
#define MCU_mSDR2Head		0xff44u

/*###########################################################
		LIN-UART serial Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxUARTFchannelMount		2u/*how UARTF Serial max in a group to mount in this serial MCU*/


/*###########################################################
		DMA Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxDMAchannelMount		4u/*how many DMA max in a group to mount in this serial MCU*/

#define MCU_mMaxVecTblEnable		16u/*how many channel vector can request in one channel DMA*/

/*###########################################################
		Serial-Uart Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxSerialUartchannelMount		1u/*how many Serial-UART max to mount in this serial MCU*/

#define MCU_mUARTReadyDefValue		0xFFFFu

#define MCU_mMaxLinUartchannelMount		2u/*how many Lin-UART max to mount in this serial MCU*/

/*###########################################################
		I2C Attribute in this serial MCU
###########################################################*/
#define MCU_mMaxIICMount		2u	/*how many i2c  max to mount in this serial MCU*/
#define MCU_mIICdealyCount	20u

#define MCU_mSmallDelay(count) do{uint16 u16wait=(uint16)(count);while(u16wait--){;}}while(0)

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

	bitfield bitReserve :2;				/*reserve bit filed*/
	
}MCU_tstPinCfg;


/*##############################################################
	Re-Load timer mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMount_ReloadTimer
{
	uint32 u32TimerMountList;/*record the mounted timer, one bit is one timer mounted*/
	uint32 u32TimerNormalPinList;/*record the timer I/O pin , one bit is one timer pin mounted*/
	uint32 u32TimerRelocatePinList;/*record the timer I/O Re-Loacte pin , one bit is one timer pin mounted*/
	uint16 u16VectorNumber[MCU_mMaxTimerIDMount];/*record the mounted timer vector number*/
}MCU_tstResourceMount_TimerArray;

typedef struct _MCU_tstTimerArray
{
	uint16 u16TCR[8u];		/*Timer counter register*/
	uint16 u16TMR[8u];	/*Timer mode register*/
	uint16 u16TSR[8u];		/*Timer status register*/
	uint16 u16TE;			/*Timer channel enable status register*/
	uint16 u16TS;			/*Timer channel start trigger register*/
	uint16 u16TT;			/*Timer channel stop trigger register*/
	uint16 u16TPS; 		/*Timer clock select register*/
	uint16 u16TO;			/*Timer output level register*/
	uint16 u16TOE;		/*Timer output enable register*/
	uint16 u16TOL;		/*Timer output level logical control register*/
	uint16 u16TOM;		/*Timer output mode register*/
}MCU_tstTimerArray;


/*########################################################
	Re-Load timer attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstReloadTimerUserCfg
{
	uint16 u16TimerType;
	uint16 u16Interval_us;		/*interrupt timer interval/cycle count/ duty count/edge detect*/
	uint8 u8IntervalChangeable;	/*interval timer changeable or not*/	
	uint8 u8IOpinID;			/*for timer-pin using*/
	uint8 u8RunInRst;			/*run in reset or not*/
	vpFunDumy	vpINTservice;		/*interrupt function to run when timer-out*/
}MCU_tstReloadTimerUserCfg;


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
	uint32 u32ADCusing;		/*max is 32 channel in this serial, so use 32bit to mask*/
}MCU_tstADCCfg;

/*##############################################################
	Serial channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_Serial
{
	uint16 u16PinMount;
	uint16 u16CSImount;
	uint16 u16IICmount;
	uint16 u16UARTmount;/*bit 4 = uart2, bit 5 = lin-uart 0, bit 6 = lin-uart 1*/
	uint16 u16VectorNumber[MCU_mMaxSerialchannelMount];
}MCU_tstResourceMnt_Serial;


/*########################################################
	Serial channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstCSICfg
{
	uint16 u16SerialType;	/*serial functional type,SMR map!*/
	uint16 u16SCRmap;		/*for serial attribute merge !*/	
	uint16 u16SDRmap;		/*for serial speed setting merge, active value is high 7bit in SDR!*/	
	uint16 u16PinSel;		/*select the higher pin or not*/
	vpFun vpSendFinish;				/*send finish callback*/
	vpFun vRecCallBack;			/*recieve data callback*/
	vpFun_u16 vu16ErrCallBack;			/*error call back*/
}MCU_tstCSICfg;


typedef struct _MCU_tstSerialArray
{
	uint16 u16SSR[2];/*serial channel status for each channel*/
	uint16 u16SIR[2];/*serial channel status for each channel*/
	uint16 u16SMR[2];/*Serial mode register*/
	uint16 u16SCR[2];/*Serial communication operation setting register*/
	uint16 u16SE;		/*Serial channel enable status register*/
	uint16 u16SS;		/*Serial channel start trigger register*/
	uint16 u16ST;		/*Serial channel stop trigger register*/
	uint16 u16SPS;	/*Serial clock select register*/
	uint16 u16SO;		/*Serial output register, set initial value for the SCK/SO pin level in reset !*/
	uint16 u16SOE;	/*Serial output enable register*/
	uint16 u16SOL;	/*Serial output level register*/
	uint16 u16SSE;		/*Serial slave select enable register*/
	uint16 u16UnUsed[8];

}MCU_tstSerialArray;

/*##############################################################
	I2C running status control
################################################################*/
typedef struct _MCU_tstCSIctrl
{
	uint8 u8RunMode;	/*send or receive mode!*/
	uint16 u16Error;
	uint16 *pu16DataHead;
	uint16 *puRecDataHead; /*Only for CSI receive*/
	uint16 u16WorkingDataLen;
	uint16 u16TottalDataLen;
}MCU_tstCSIctrl;

/*##############################################################
	Lin-Uart channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_UARTF
{
	uint16 u16PinMount;
	uint16 u16PinMount_R;
	uint16 u16VectorNumber_RX[MCU_mMaxUARTFchannelMount];
	uint16 u16VectorNumber_TX[MCU_mMaxUARTFchannelMount];
	uint16 u16VectorNumber_ERR[MCU_mMaxUARTFchannelMount];
	
}MCU_tstResourceMnt_UARTF;


/*##############################################################
	DMA channel mount in this serial chip,configerate it for difference chip type
################################################################*/
typedef struct _MCU_tstResourceMnt_DMA
{
	uint16 u16DMAmountMask;
	uint16 u16VectorNumber[MCU_mMaxDMAchannelMount];
	uint8 au8VectTrigerTbl_CH0_1[MCU_mMaxVecTblEnable];
	uint8 au8VectTrigerTbl_CH2_3[MCU_mMaxVecTblEnable];
}MCU_tstResourceMnt_DMA;


/*########################################################
	DMA channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstDMACfg
{
	uint16 u16RegsterAddr;
	uint16 u16RamAddr;
	uint8 u8DataChgType;		/*Up Only in this serial MCU*/
	uint8 u8DataDirection;		/*Register to RAM or RAM to Register*/
	uint8 u8DataUnitSize;			/*8bit or 16bit at once step, 1=byte, 2=word*/
	uint16 u16DataTattolSize;		/*how many byte data to transfer*/
	uint16 u16VectorNum;			/*which interrupt to control*/
	vpFun	vpINTservice;		/*interrupt function when DMA finish!*/
}MCU_tstDMACfg;


/*########################################################
	UART channel attribute control for work status
########################################################*/
typedef struct _MCU_tstUARTCtrl
{
	uint16 u16Error;
	uint8 *pu8DataHead;
	uint16 u16WorkingDataLen;
	uint16 u16TottalDataLen;
}MCU_tstUARTCtrl;

/*########################################################
	UART channel attribute configeration for user,configerate it for difference project
########################################################*/
typedef struct _MCU_tstUARTCfg
{
	uint16 u16BaudRate;	/*transfer speed*/
	uint8 u8MsbLsb;			/*data direction: MSB or LSB*/
	uint8 u8Parity;			/*Parity type, Even Parity or Odd Parity enabled*/
	uint8 u8StopBit;		/*stop bit lenth, 1bit or 2bit*/
	uint8 u8IOReverse;		/*in/out level logic is normal or not*/
	
	vpFun vpSendFinish;				/*send finish callback*/
	vpFun_u8 vu8RecCallBack;			/*recieve data callback*/
	vpFun_u16 vu16ErrCallBack;			/*error call back*/
	
}MCU_tstUARTCfg;


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
	uint8 u8SlaveChannel;
	uint8 u8Runmode;/*send or receive mode record*/
	uint8 u8Error;
	uint8 *pu8DataHead;
	uint16 u16WorkingDataLen;
	uint16 u16TottalDataLen;
}MCU_tstIICctrl;


#pragma pack(push,1)

typedef union {
	__BYTE	byte;
} MCU_tstU8Reg;

#pragma pack(pop)

#endif/*end of this file*/


