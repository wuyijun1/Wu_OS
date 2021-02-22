/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: PCA8539_cfg.c
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
|Tan Fumin                       Desay SV Automotive Co., Ltd
|
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2016.05.23  V0.01		Tan, fumin	:create this module
********************************************************************************/

#include "./PCA8539.h" /*for example*/
#include "../.././03_SYS/MCU/RH850/RH850_Drv/iodefine.h" /*for example*/

extern uint8 PCA8539_u8InitStep;
PCA8539_UsrCfg PCA8539_Cfg=
{
	0x74>>1,/*u8SlaveAddr*/
	0,	/*u8MultiplexNum,	0=18
						1=12*/
	2,	/*u8LineInv, 2line inv*/
	7,	/*u8LCDFrequency, 80Hz*/
	7,	/*u8TemperatureSet
					BIT2=TCE:	temperature compensation of VLCD enable or not
					BIT1=TMF:	digital temperature filter enabled or not
					BIT0=TME:	temperature measurement readout enable or not*/
	3,/*u8TSA*/
	2,/*u8TSB*/
	0,/*u8TSC*/
	2,/*u8TSD*/
	0xA7,/*u8EVvalue*/
	5,/*u8ChargeCtrl
			BIT0:
			
				CPE=0:using external Vlcd
				CPE=1:using internal Vlcd

			BIT1-2:
			
			CPC=x : 
				0   2 x Vdd
				1   3 x Vdd
				2   4 x Vdd

				3   Vlcd=Vdd2 (direct mode)*/
};



/*******************************************************************************
	interface configeration
*******************************************************************************/
void PCA8539_vIIC_Init(void)
{

return;

}

void PCA8539_vDataSendOut(uint8 *u8DateHead,uint8 u8DateLen)
{
	MCU_u16IIC_MasterSend(0, 0, u8DateHead,u8DateLen);
}

void PCA8539_vDataSendFinishCallBack(void)
{
	uint8 u8i=200;
	static uint8 u8Rambank_Select = 255;


		
	PCA8539_vStopCondition();
	while(u8i--);
	
	if(PCA8539_u8InitStep==1)
	{
		PCA8539_vDvrInit_P2();
	}
	else if(PCA8539_u8InitStep==2)
	{
		PCA8539_vDvrInit_P3();
	}
	else if(PCA8539_u8InitStep==3)
	{
		PCA8539_vDvrInit_P4();
	}
	else
	{
		if(u8Rambank_Select == 1)
		{
			PCA8539_vDisplayUpdate(RamBank2,RamStartAddr,u8RamBank2_Container,RamBankDataLen);
			u8Rambank_Select++;
		}
		else if(u8Rambank_Select == 2)
		{
			PCA8539_vDisplayUpdate(RamBank3,RamStartAddr,u8RamBank3_Container,RamBankDataLen);
			u8Rambank_Select++;
		}
		else
		{
			u8Rambank_Select = 1;
		}
	}
}

void PCA8539_vDataRecFinishCallBack(void)
{
	/* */
}

void PCA8539_vErrCallBack(void)
{
	/* */
}

void PCA8539_vStartCondition(void)
{
	MCU_u16IIC_MasterStartCondition(0);
}

void PCA8539_vStopCondition(void)
{
	MCU_u16IIC_MasterStopCondition(0);
}

