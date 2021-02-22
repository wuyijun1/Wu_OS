/*******************************************************************************
| Module Name: L9301
| File Name: L9301_Cfg.c
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
| 2017.03.13  V0.01	Tan, fumin	:create this module
********************************************************************************/
#include "L9301.h"

const L9301_CR_Map L9301_UsrCfg=
{
	/*CR_0x00*/
	{
		0,/*CRC*/
		0,/*output_conf=[1-0]	
			0 =Mode 1=================================================
				IN1-4 ↙ DRN1-4, OUT1-4		8 low side channels with Rdson = 0.3 次
				IN5-8 ↙ OUT5-8
				
					每 IN1: OUT1 & OUT2;
					每 IN2: OUT3 & OUT4;
					每 IN3: DRN1 & DRN2;
					每 IN4: DRN3 & DRN4;	
			1 =Mode 2=================================================	
				IN1-4 ↙ OUT1-4				4 low side channels with Rdson = 0.6 次
				IN5-8 ↙ OUT5-8				4 low side channels with Rdson = 0.3 次

					- IN1: OUT1 <--> SRC2;
					- IN2: OUT2 <--> SRC1;
					- IN3: OUT3 <--> SRC4;
					- IN4: OUT4 <--> SRC3;
			2 =Mode 3=================================================
				IN1-4 ↙ SRC1-4,				4 high side channels with Rdson = 0.6 次
				IN5-8 ↙ OUT5-8				4 low side channels with Rdson = 0.3 次

					- IN1: SRC1 <--> OUT2;
					- IN2: SRC2 <--> OUT1;
					- IN3: SRC3 <--> OUT4;
					- IN4: SRC4 <--> OUT3
			3 =Mode 4=================================================
				IN1-4 ↙ OUT1-4,				4 low side channels with Rdson = 0.6 次
				IN5-8 ↙ OUT5-8,				4 low side channels with Rdson = 0.3 次
				SPI ↙ DRN/SRC1-4			4 low/high side ch. with Rdson = 0.6 次*/
		0,/*vbov_conf -> 1 = auto shut driver when VB over-voltage*/
		0,/*vbuv_conf -> 1 = auto shut driver when VB under-voltage*/
		0,/*vddov_conf ->1 = auto shut driver when VDD over-voltage*/
		0,/*vdduv_conf -> 1 = auto shut driver when VDD under-voltage*/
		0,/*cpl_conf -> 1 =  auto shut driver when charge pump low*/
		0,/*dloss_conf -> 1 = auto shut driver when freewheeling diode loss*/
		0,/*conf4_lshs->configeration the HS.LS type for DRN(1-4)/SRC(1-4)*/
		0,/*RESERVED*/
		0,/*RES*/
		0,/*ADD*/
		0,/*WR*/
	},
	
	{
		/*CR_0x01 ==>Configeration for LS1*/
		{
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
		
	            /*CR_0x02 ==>Configeration for LS2*/
	            {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
		
                    /*CR_0x03 ==>Configeration for LS3*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
                    
                    /*CR_0x04 ==>Configeration for LS4*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
                    
                    /*CR_0x05 ==>Configeration for LS5*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
        
                /*CR_0x06 ==>Configeration for LS6*/
                {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
        
                    /*CR_0x07 ==>Configeration for LS7*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
                    
                    /*CR_0x08 ==>Configeration for LS8*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},

                    /*CR_0x09 ==>Configeration for HS1*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
                    
                    /*CR_0x0A ==>Configeration for HS2*/
                    {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
            
                        /*CR_0x0B ==>Configeration for HS3*/
                        {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},
                        
                        /*CR_0x0C ==>Configeration for HS4*/
                        {
			0,/*CRC*/
			0,/*slew_rate -> 1 = slew rate is high*/
			0,/*oc_thres -> 0 = normal over current threshold*/
			0,/*oc_restart -> 1 = restart the channel without clearing the fault bit*/
			0,/*diagoff_blank_sel -> 1 = short blanking time*/
			0,/*dloss_act -> 1 = enable the dloss signal diagnosis*/
			0,/*dis_source -> 1 = disable off diagnosis pull up current*/
			0,/*dis_diagoff -> 1 = disable off diagnosis*/
			0,/*pwm_en -> 1 = driver PWM mode is enabled, avild in mode 2-3*/
			0,/*RESERVED*/
			0,/*RES*/
			0,/*ADD*/
			0,/*WR*/
			
		},

                    
	},
	
	/*CR_0x0D*/
	{
		0,/*CRC*/
		0,/*cmd1 -> reset value for LS1*/
		0,/*cmd2 -> reset value for LS2*/
		0,/*cmd3 -> reset value for LS3*/
		0,/*cmd4 -> reset value for LS4*/
		0,/*cmd5 -> reset value for LS5*/
		0,/*cmd6 -> reset value for LS6*/
		0,/*cmd7 -> reset value for LS7*/
		0,/*cmd8 -> reset value for LS8*/
		0,/*cmd9 -> reset value for HS1*/
		0,/*cmd10 -> reset value for HS2*/
		0,/*cmd11 -> reset value for HS3*/
		0,/*cmd12 -> reset value for HS4*/
		0,/*RESERVED*/

		0,/*RES*/
		0,/*ADD*/
		0,/*WR*/

	},
	
	/*CR_0x0E*/
	{
		0,/*CRC*/
		0,/*clkch_en -> 1 = enable clock check block*/
		0,/*dr_s_chk -> 0 = normal*/
		0,/*RESERVED*/
		0,/*RES*/
		0,/*ADD*/
		0,/*WR*/
	},


	/*External Configer Bytes for InX -> OutX ctrl by Pin_INx or SPI bit */
	0,/*1bit = a channel, 	0 =  OutX control by SPI, in mode 4 DRN/SCR must control by SPI, 
						1 = OutX control by INx
						 the truth is that OutX logic = (INx | SPI_Bit)*/



};



/*****************************************************************************
 Function  : L9301_vOutPutEnCtrl												 
 Description   :L9301 OutX level enable control
 
 In Parameter: 
 			u8Enable : OutX level enable or not , 1 = Enable

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vOutPutEnCtrl(uint8 u8Enable)
{
	L9301_EN_PinCtrl(u8Enable);	
}

/*****************************************************************************
 Function  : L9301_vResetPinCtrl												 
 Description   :L9301 Reset control
 
 In Parameter: 
 			u8PinLevel : RES pin level , 1 = change to normal work mode and start self-test

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vResetPinCtrl(uint8 u8PinLevel)
{
    L9301_RES_PinCtrl(u8PinLevel);
    

}

/*****************************************************************************
 Function  : L9301_vCSPinCtrl												 
 Description   :L9301 chip-select pon control
 
 In Parameter: 
 			u8PinLevel : CS pin level , 0 = active L9301

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vCSPinCtrl(uint8 u8PinLevel)
{
    SPI_u16SlaveSelect_CH1(0,u8PinLevel);
}

/*****************************************************************************
 Function  : L9301_u16OUTxErrProccess												 
 Description   :L9301 error proccess interface,
 
 In Parameter: 
 			u32ErrInfo : Error information

Return Value:
 			
 			
 NOTE: 		
 		IMPORTANT:
 		
 			All of the error process need done by user!!!!!!!!!!!!!
			
*****************************************************************************/
uint16 L9301_u16OUTxErrProccess(L9301_ChnID channel, L9301_ChnError u32ErrInfo)
{

	/*Error process MUST done by user~~~~~~~~~~~*/
	
	return 1;
}

/*****************************************************************************
 Function  : L9301_u16VoltageErrProccess												 
 Description   :L9301 Voltage error proccess interface,
 
 In Parameter: 
 			u32ErrInfo : Error information

Return Value:
 			0: if the channel OutX CAN NOT be use any more, return 0 to re-mark the channel
			 1: if the channel OutX CAN be use and proccess error successfull, then return 1 to continue using
 			
 NOTE: 		
 		IMPORTANT:
 		
 			All of the error process need done by user!!!!!!!!!!!!!

 			the VDD or VB supply voltage error , this function will be called
 			
*****************************************************************************/
uint16 L9301_u16VoltageErrProccess(L9301_VoltageError u32ErrInfo)
{

	/*Error process MUST done by user~~~~~~~~~~~*/
	
	return 1;
}


/*****************************************************************************
 Function  : L9301_u16SPI_SendOutData												 
 Description   :L9301 SPI data in/out interface
 
 In Parameter: 
 			pOutDataHead : output data head, uint32 format
 			pRecDataHead: input data head, uint32 format

Return Value:
 			SPI resault
 			
 NOTE: 		
 			Null
*****************************************************************************/
uint16 L9301_u16SPI_SendOutData(void *pOutDataHead, void *pRecDataHead,uint16 u16DataLen)
{
	uint16 u16Res=0;
	
	L9301_vCSPinCtrl(0);/*CS->active*/
	u16Res=SPI_u16TransferData_CH1(pOutDataHead, pRecDataHead, u16DataLen);
	L9301_vCSPinCtrl(1);/*CS->non-active*/

	return u16Res;
}

/*****************************************************************************
 Function  : L9301_vSPI_Init												 
 Description   :L9301 SPI init interface
 
 In Parameter: 
 			Null

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vSPI_Init(void)
{
	SPI_vDrvInit_CH1();
#if L9301_SPI_CmdEnable !=0
        L9301_VDD_IO_PinCtrl(1);
#endif
}





