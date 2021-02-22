/*******************************************************************************
| Module Name: L9301
| File Name: L9301_Type.h
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

#ifndef _L9301_TYPE_H_
#define _L9301_TYPE_H_

#include "General.h"



/********************************
	Contorl Register Map === 0x00
**********************************/
typedef struct 
{
	uint32 CRC : 3;
	uint32 output_conf : 2;	/*vdduv_conf=[1-0]
		0 =====================================================
			IN1-4 ↙ DRN1-4, OUT1-4		8 low side channels with Rdson = 0.3 次
			IN5-8 ↙ OUT5-8
			
				每 IN1: OUT1 & OUT2;
				每 IN2: OUT3 & OUT4;
				每 IN3: DRN1 & DRN2;
				每 IN4: DRN3 & DRN4;	
		1 =====================================================	
			IN1-4 ↙ OUT1-4				4 low side channels with Rdson = 0.6 次
			IN5-8 ↙ OUT5-8				4 low side channels with Rdson = 0.3 次

				- IN1: OUT1 <--> SRC2;
				- IN2: OUT2 <--> SRC1;
				- IN3: OUT3 <--> SRC4;
				- IN4: OUT4 <--> SRC3;
		2 =====================================================
			IN1-4 ↙ SRC1-4,				4 high side channels with Rdson = 0.6 次
			IN5-8 ↙ OUT5-8				4 low side channels with Rdson = 0.3 次

				- IN1: SRC1 <--> OUT2;
				- IN2: SRC2 <--> OUT1;
				- IN3: SRC3 <--> OUT4;
				- IN4: SRC4 <--> OUT3
		3 =====================================================
			IN1-4 ↙ OUT1-4,				4 low side channels with Rdson = 0.6 次
			IN5-8 ↙ OUT5-8,				4 low side channels with Rdson = 0.3 次
			SPI ↙ DRN/SRC1-4			4 low/high side ch. with Rdson = 0.6 次*/
	uint32 vbov_conf : 1;	/*vdduv_conf=[2]->
						0 = no auto shut driver when vbov
						1 = auto shut driver when vbov*/

	uint32 vbuv_conf : 1;	/*vdduv_conf=[3]->
						0 = no auto shut driver when vbuv
						1 = auto shut driver when vbuv*/						
	uint32 vddov_conf : 1;	/*vdduv_conf=[4]->
						0 = no auto shut driver when vddov
						1 = auto shut driver when vddov*/
	uint32 vdduv_conf : 1;	/*vdduv_conf=[5]->
						0 = no auto shut driver when vdduv
						1 = auto shut driver when vdduv*/
	uint32 cpl_conf : 1;		/*cpl_conf=[6]->
						0 = no auto shut driver when charge pump low
						1 = auto shut driver when charge pump low*/						
	uint32 dloss_conf : 1;/*dloss_conf=[7]->
						0 = no auto shut driver when freewheeling diode loss
						1 = auto shut driver when freewheeling diode loss*/
	uint32 conf4_lshs : 4;/*conf4_lshs=[11-8]->
						[11] conf4_lshs[3]
							0 = HS is configured as high side driver during configuration4
							1 = HS is configured as low side driver during configuration4
						[10] conf4_lshs[2]
							0 = HS is configured as high side driver during configuration4
							1 = HS is configured as low side driver during configuration4
						[9] conf4_lshs[1]
							0 = HS is configured as high side driver during configuration4
							1 = HS is configured as low side driver during configuration4
						[8] conf4_lshs[0]
							0 = HS is configured as high side driver during configuration4
							1 = HS is configured as low side driver during configuration4*/

	uint32 RESERVED : 8;/*RESERVED=[19-12]*/
	uint32 RES :1;
	uint32 ADD :7;
	uint32 WR :1;
}Map_CR_0x00;

/************************************
	Contorl Register Map === 0x01->0x0C
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
	uint32 slew_rate : 1;	/*slew_rate=[0]->
						0 = slew rate is low
						1 = slew rate is high*/
	uint32 oc_thres : 1;		/*oc_thres=[1]->
						0 = normal over current threshold
						1 = enable double over current threshold*/

	uint32 oc_restart : 1;	/*oc_restart=[2]->
						0 = restart the channel only after clearing the fault bit
						1 = restart the channel without clearing the fault bit*/		


	uint32 diagoff_blank_sel : 1;	/*diagoff_blank_sel=[3]->
						0 = long blanking time
						1 = short blanking time*/
	uint32 dloss_act : 1;		/*dloss_act=[4]->
						0 = disable the dloss signal diagnosis
						1 = enable the dloss signal diagnosis*/

	uint32 dis_source : 1;	/*dis_source=[5]->
						0 = enable off diagnosis pull up current
						1 = disable off diagnosis pull up current*/

	uint32 dis_diagoff : 1;	/*dis_diagoff=[6]->
						0 = enable off diagnosis
						1 = disable off diagnosis*/

	uint32 pwm_en : 1;		/*pwm_en=[7]->
						0 = driver is disabled
						1 = driver is enabled
						available only in LS4-1 and HS4-1, used for diagoff test in configuration 2/3*/

	uint32 RESERVED : 12; 	/*RESERVED=[19-8]*/
						
        uint32 RES :1;
        uint32 ADD :7;
        uint32 WR :1;
}Map_CR_0x01_0x0C;


/************************************
	Contorl Register Map === 0x0D
*************************************/
typedef  struct 
{
         uint32 CRC : 3;
         
	uint32 cmd1 :1;	/*cmd1=[0]->
					Command OUT1 (in Configuration1 controls OUT1/OUT2)*/
	uint32 cmd2 :1;	/*cmd2=[1]->
					Command OUT2 (in Configuration1 controls OUT3/OUT4)*/
	uint32 cmd3 :1;	/*cmd3=[2]->
					Command OUT3 (in Configuration1 controls DRN/SRC1 DRN/SRC2)*/
	uint32 cmd4 :1;	/*cmd4=[3]->
					Command OUT4 (in Configuration1 controls DRN/SRC3 DRN/SRC4)*/
	uint32 cmd5 :1;	/*cmd5=[4]->
					Command OUT5*/
	uint32 cmd6 :1;	/*cmd6=[5]->
					Command OUT6*/						
	uint32 cmd7 :1;	/*cmd7=[6]->
					Command OUT7*/
	uint32 cmd8 :1;	/*cmd8=[7]->
					Command OUT8*/
	uint32 cmd9 :1;	/*cmd9=[8]->
					Command HS1*/

	uint32 cmd10 :1;	/*cmd10=[9]->
					Command HS2*/
	uint32 cmd11 :1;	/*cmd11=[10]->
					Command HS3*/
	uint32 cmd12 :1;	/*cmd12=[11]->
					Command HS4*/
	uint32 RESERVED : 8;/*RESERVED=[19-12]*/
					
        uint32 RES :1;
        uint32 ADD :7;
        uint32 WR :1;
        
}Map_CR_0x0D;


/************************************
	Contorl Register Map === 0x0E
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
	uint32 clkch_en :1;/*clkch_en=[0]->
					0 = disable clock check block
					1 = enable clock check block*/
	uint32 dr_s_chk :1;/*dr_s_chk=[1]->
					0 = normal
					1 = invert hv/lv and OC comparator input
					used in MCU controlled comparator test*/
	uint32 RESERVED : 18;/*RESERVED=[19-2]*/
	uint32 RES :1;
	uint32 ADD :7;
	uint32 WR :1;
}Map_CR_0x0E;



/*#####################################################
#######################################################*/

/************************************
	Status Register Map === 0x10
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
        uint32 vbov :1;/*vbov=[0]->
				0 = no VB over voltage
				1 = VB over voltage*/

        uint32 vbuv :1;/*vbuv=[1]->
				0 = no VB under voltage
				1 = VB under voltage*/

        uint32 vddov :1;/*vddov=[2]->
				0 = no VDD over voltage
				1 = VDD over voltage*/

        uint32 vdduv :1;/*vdduv=[3]->
				0 = no VDD under voltage
				1 = VDD under voltage*/

        uint32 got :1;	/*got=[4]->
				0 = no over temperature
				1 = logic OR combination of bit 0 of all the Driver status register*/

        uint32 cpl :1;	/*cpl=[5]->
			        	0 = no charge pump low
				1 = charge pump low*/
        uint32 gf :1;	/*gf=[6]->
			        	0 = no fault in all the channels
				1 = logic OR combination of bit 1/2/3/4/5/6/8 of all the Driver status register*/

	 uint32 RESERVE :1;/*RESERVE=[7]*/

	uint32 clkbad :1;/*clkbad=[8]->
					0 = main clock and diagnosis clock frequency deviation within 25%
					1 = main clock and diagnosis clock frequency deviation over 25%*/

	uint32 RESERVED : 11;/*RESERVED=[19-9]*/
					
	uint32 CHExcp0_vbov : 1;		/*vbov: bit 0 of General device diagnostic register*/
	uint32 CHExcp1_vbuv: 1;		/*vbuv: bit 1 of General device diagnostic register*/
	uint32 CHExcp2_vddov : 1;		/*vddov: bit 2 of General device diagnostic register*/
	uint32 CHExcp3_vdduv : 1;		/*vdduv: bit 3 of General device diagnostic register*/
	uint32 CHExcp4_got : 1;		        /*got: bit 4 of General device diagnostic register*/
	uint32 CHExcp5_gf : 1;		        /*gf: bit 6 of General device diagnostic register*/
	
	uint32 SPIErr0_CRC : 1;		/*SPI CRC Error: SPI CRC checksum error*/
	uint32 SPIErr1_LF: 1;		        /*SPI Long Frame: a more-than-32bit SPI frame was received*/
	uint32 SPIErr2_SF : 1;		        /*SPI Short Frame: a less-than-32bit SPI frame was received*/


}Map_SR_0x10;


/************************************
	Status Register Map === 0x11->0x1C
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
        uint32 t_sd :1;	/*t_sd=[0]->
				0 = no over temperature occurring
				1 = over temperature occurring (live bit)*/
        uint32 t_sdl :1;	/*t_sdl=[1]->
				0 = no over temperature
				1 = over temperature*/
        uint32 oc :1;	/*oc=[2]->
				0 = no over current
				1 = over current*/

        uint32 dloss :1;	/*vddov=[3]->
				0 = no diode loss
				1 = diode loss*/

        uint32 shgnd :1;/*shgnd=[4]->
				0 = no short to GND
				1 = short to GND*/

        uint32 shvb :1;	/*shvb=[5]->
				0 = no short to VB
				1 = short to VB
				available only in SR9-SR12*/
        uint32 ol :1;	/*ol=[6]->
				0 = no open load
				1 = open load*/
        uint32 cs :1;	/*cs=[7]->
				0 = CR13 or pin IN1-8 put driver to off status
				1 = CR13 or pin IN1-8 put driver to on status*/				
        uint32 os :1;/*os=[8]->
				0 = driver status is aligned to the command in on state
				1 = driver output is not aligned to the command in on state*/

	uint32 oc_comp_f :1;/*oc_comp_f=[9]->
					0 = no comparator self test fail
					1 = over current comparator self test fail*/
	uint32 RESERVED : 10;/*RESERVED=[19-10]*/
				
	uint32 CHExcp0_vbov : 1;		/*vbov: bit 0 of General device diagnostic register*/
	uint32 CHExcp1_vbuv: 1;		/*vbuv: bit 1 of General device diagnostic register*/
	uint32 CHExcp2_vddov : 1;		/*vddov: bit 2 of General device diagnostic register*/
	uint32 CHExcp3_vdduv : 1;		/*vdduv: bit 3 of General device diagnostic register*/
	uint32 CHExcp4_got : 1;		        /*got: bit 4 of General device diagnostic register*/
	uint32 CHExcp5_gf : 1;		        /*gf: bit 6 of General device diagnostic register*/
	
	uint32 SPIErr0_CRC : 1;		/*SPI CRC Error: SPI CRC checksum error*/
	uint32 SPIErr1_LF: 1;		        /*SPI Long Frame: a more-than-32bit SPI frame was received*/
	uint32 SPIErr2_SF : 1;		        /*SPI Short Frame: a less-than-32bit SPI frame was received*/
}Map_SR_0x11_0x1C;


/************************************
	Status Register Map === 0x1D
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
	uint32 silicon_version :6;/*silicon version=[5-0]->
						silicon version*/
	uint32 RESERVED : 14;/*RESERVED=[19-16]*/
	
	uint32 CHExcp0_vbov : 1;		/*vbov: bit 0 of General device diagnostic register*/
	uint32 CHExcp1_vbuv: 1;		/*vbuv: bit 1 of General device diagnostic register*/
	uint32 CHExcp2_vddov : 1;		/*vddov: bit 2 of General device diagnostic register*/
	uint32 CHExcp3_vdduv : 1;		/*vdduv: bit 3 of General device diagnostic register*/
	uint32 CHExcp4_got : 1;		        /*got: bit 4 of General device diagnostic register*/
	uint32 CHExcp5_gf : 1;		        /*gf: bit 6 of General device diagnostic register*/
	
	uint32 SPIErr0_CRC : 1;		/*SPI CRC Error: SPI CRC checksum error*/
	uint32 SPIErr1_LF: 1;		        /*SPI Long Frame: a more-than-32bit SPI frame was received*/
	uint32 SPIErr2_SF : 1;		        /*SPI Short Frame: a less-than-32bit SPI frame was received*/
}Map_SR_0x1D;/*Device status register map*/


/************************************
	Status Register Map === 0x1E
*************************************/
typedef  struct 
{
	uint32 CRC : 3;
	uint32 lbist_pass :1;/*lbist pass=[0]->
					0 = bist is not finished yet or finished with error
					1 = bist finished without error*/
	uint32 lbist_end :1;/*lbist end=[1]->
					0 = bist unfinished yet
					1 = bist finished*/
	uint32 lbist_run :1;/*lbist run=[2]->
					0 = bist is not currently running
					1 = bist is currently running*/	
	uint32 RESERVED : 17;/*RESERVED=[19-3]*/
					
	uint32 CHExcp0_vbov : 1;		/*vbov: bit 0 of General device diagnostic register*/
	uint32 CHExcp1_vbuv: 1;		/*vbuv: bit 1 of General device diagnostic register*/
	uint32 CHExcp2_vddov : 1;		/*vddov: bit 2 of General device diagnostic register*/
	uint32 CHExcp3_vdduv : 1;		/*vdduv: bit 3 of General device diagnostic register*/
	uint32 CHExcp4_got : 1;		        /*got: bit 4 of General device diagnostic register*/
	uint32 CHExcp5_gf : 1;		        /*gf: bit 6 of General device diagnostic register*/
	
	uint32 SPIErr0_CRC : 1;		/*SPI CRC Error: SPI CRC checksum error*/
	uint32 SPIErr1_LF: 1;		        /*SPI Long Frame: a more-than-32bit SPI frame was received*/
	uint32 SPIErr2_SF : 1;		        /*SPI Short Frame: a less-than-32bit SPI frame was received*/
}Map_SR_0x1E;


/************************************************************************
	#### L9301 register Normal Type ####
************************************************************************/
typedef union 
{
	struct
	{
		uint32 CRC : 3;		/*CRC*/
		uint32 DATA : 20;	/*Data*/
		uint32 RES :1 ;		/*Reserved*/
		uint32 ADD : 7;		/*Address*/
		uint32 WriteRead : 1;/*1=W, 0 = R*/
	}Bit;
	uint32 Dword;
}L9301_RegisterNormalType_MOSI;

/************************************************************************
	#### L9301 register Normal Type ####
************************************************************************/
typedef union 
{
	struct
	{
		uint32 CRC : 3;		/*CRC*/
		uint32 DATA : 20;	/*Data*/
		
		uint32 CHExcp0_vbov : 1;		/*vbov: bit 0 of General device diagnostic register*/
		uint32 CHExcp1_vbuv: 1;		/*vbuv: bit 1 of General device diagnostic register*/
		uint32 CHExcp2_vddov : 1;		/*vddov: bit 2 of General device diagnostic register*/
		uint32 CHExcp3_vdduv : 1;		/*vdduv: bit 3 of General device diagnostic register*/
		uint32 CHExcp4_got : 1;		        /*got: bit 4 of General device diagnostic register*/
		uint32 CHExcp5_gf : 1;		        /*gf: bit 6 of General device diagnostic register*/
		
		uint32 SPIErr0_CRC : 1;		/*SPI CRC Error: SPI CRC checksum error*/
		uint32 SPIErr1_LF: 1;		        /*SPI Long Frame: a more-than-32bit SPI frame was received*/
		uint32 SPIErr2_SF : 1;		        /*SPI Short Frame: a less-than-32bit SPI frame was received*/
	}Bit;
	uint32 Dword;
}L9301_RegisterNormalType_MISO;


/************************************************************************
	#### L9301 Control register Map ####
************************************************************************/
typedef struct
{
	Map_CR_0x00 CR_0x00;
	Map_CR_0x01_0x0C CR_0x01_0x0C[0x0c];
	Map_CR_0x0D CR_0x0D;
	Map_CR_0x0E CR_0x0E;
	uint32 PinCtrlMode;/*NotUsed;-->not use bytes in chip, using these bytes to mask the OutX control source mode, InX ctrl OR SPI ctrl*/
}L9301_CR_Map;


/************************************************************************
	#### L9301 Status register Map ####
************************************************************************/
typedef union 
{
	struct
	{
		Map_SR_0x10 SR_0x10;
		Map_SR_0x11_0x1C SR_0x11_0x1C[0x0c];
		Map_SR_0x1D SR_0x1D;
		Map_SR_0x1E SR_0x1E;	
		uint32 NotUsed;
	}Bit;
	uint32 RegTable[0x10];
}L9301_SR_Map;

typedef union
{
	struct
	{
	        L9301_CR_Map    CR;
	        L9301_SR_Map    SR;
	}Struct;
	uint32 Table[0x20];
}L9301_RegisterMap;



/************************************************************************
	#### L9301 register Type ####
************************************************************************/

typedef enum
{
	/*contorl register*/
	L9301_Cfg_CR00=0,/*Device general configuration register*/
	L9301_LS1_CR01,/*Device configuration register for LS1*/
	L9301_LS2_CR02,/*Device configuration register for LS2*/
	L9301_LS3_CR03,/*Device configuration register for LS3*/
	L9301_LS4_CR04,/*Device configuration register for LS4*/
	L9301_LS5_CR05,/*Device configuration register for LS5*/
	L9301_LS6_CR06,/*Device configuration register for LS6*/
	L9301_LS7_CR07,/*Device configuration register for LS7*/
	L9301_LS8_CR08,/*Device configuration register for LS8*/
	L9301_HS1_CR09,/*Device configuration register for HS1*/
	L9301_HS2_CR0A,/*Device configuration register for HS2*/
	L9301_HS3_CR0B,/*Device configuration register for HS3*/
	L9301_HS4_CR0C,/*Device configuration register for HS4*/
	L9301_CMD_CR0D,/*Driver command register for each HS/LS channel, one bit control one channel OutX */
	L9301_CmpChk_CR0E,/*MCU controlled comparator test and clock check register*/
	L9301_NONE_CR0F,
	
         L9301_GeneralSatus_SR10,/*General device status register*/
        L9301_LS1_SR11,/*Device status register for LS1*/
        L9301_LS2_SR12,/*Device status register for LS2*/
        L9301_LS3_SR13,/*Device status register for LS3*/
        L9301_LS4_SR14,/*Device status register for LS4*/
        L9301_LS5_SR15,/*Device status register for LS5*/
        L9301_LS6_SR16,/*Device status register for LS6*/
        L9301_LS7_SR17,/*Device status register for LS7*/
        L9301_LS8_SR18,/*Device status register for LS8*/
        L9301_HS1_SR19,/*Device status register for HS1*/
        L9301_HS2_SR1A,/*Device status register for HS2*/
        L9301_HS3_SR1B,/*Device status register for HS3*/
        L9301_HS4_SR1C,/*Device status register for HS4*/
        L9301_SiliconVersion_SR1D,/*IC version register*/
        L9301_BIST,/*Bist status register*/
        L9301_NONE_SR0F,
        
}L9301_RegisterMapList;

typedef enum
{
    L9301_OutputChn_LS1=0,/*Output channel ID  for LS1*/
    L9301_OutputChn_LS2,/*Output channel ID  for LS2*/
    L9301_OutputChn_LS3,/*Output channel ID  for LS3*/
    L9301_OutputChn_LS4,/*Output channel ID  for LS4*/
    L9301_OutputChn_LS5,/*Output channel ID  for LS5*/
    L9301_OutputChn_LS6,/*Output channel ID  for LS6*/
    L9301_OutputChn_LS7,/*Output channel ID  for LS7*/
    L9301_OutputChn_LS8,/*Output channel ID  for LS8*/
    L9301_OutputChn_HS1,/*Output channel ID  for HS1*/
    L9301_OutputChn_HS2,/*Output channel ID  for HS2*/
    L9301_OutputChn_HS3,/*Output channel ID  for HS3*/
    L9301_OutputChn_HS4,/*Output channel ID  for HS4*/

}L9301_ChnID;


typedef union
{
    struct{
	uint32 VB_OverVoltage :1;
	uint32 VB_UnderVoltage:1;
	uint32 VDD_OverVoltage:1;
	uint32 VDD_UnderVoltage:1;
	uint32 RES :28;
	}Bits;
	uint32 Dword;
}L9301_VoltageError;

typedef union
{
    struct{
	uint32 OverTempOccurring:1;/*may not a error, this is testing bit*/
	uint32 OverTemp:1;
	uint32 OverCurrent:1;
	uint32 DiodeLoss:1;
	uint32 ShutToGND:1;
	uint32 ShutToVB:1;/*available only in SR9-SR12*/
	uint32 OpenLoad:1;
	uint32 CommandStatus:1;/*SPI control OUTx level, it is not a error*/
	uint32 OutputStatus:1;     /*OUTx level, it is not a error*/
	uint32 OverCurrentComparator:1;/*Current monitor error during OFF status*/
	uint32 RES :22;
	}Bits;
	uint32 Dword;
}L9301_ChnError;

typedef enum
{
	L9301_NotInit=0,
	L9301_Ready,
	L9301_Busy,
	L9301_Error,
	
}L9301_DrvSatus;

typedef struct
{
	L9301_DrvSatus DrvSatus;
	uint32 ExpOutX_Level;
	uint32 ChannelErrMask;
	
}L9301_DrvSatusCtrl;


#define L9301_ReadCmdMerge(Addr,MergeFinal)	do{(MergeFinal = ((uint32)Addr)<<24 );\
												MergeFinal =(L9301_u32CrcCompute(MergeFinal) );}while(0)
												
#define L9301_WriteCmdMerge(Addr,Data_20Bit,MergeFinal)	do{(MergeFinal = (1<<31) |((((uint32)Addr)&0x7f)<<24) |(((Data_20Bit) & 0xFFFFF)<<3));\
													MergeFinal =(L9301_u32CrcCompute(MergeFinal) );}while(0)

#endif/*end of this file*/


