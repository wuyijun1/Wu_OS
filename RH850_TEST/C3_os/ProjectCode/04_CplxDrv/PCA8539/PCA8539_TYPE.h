/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: PCA8539_type.h
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

#ifndef PCA8539_TYPE_H
#define PCA8539_TYPE_H

#include "general.h"
#include "mcu_cfg.h"

#define IIC_Read(value)	value/*((uint8)((value<<1)|1))	Master read data from slave*/
#define IIC_Write(value)	value/*((uint8)((value<<1)|0))	Master write data to slave*/

#define IIC_DUMMY	0xFF

#define RS_0	(0x0<<5)
#define RS_1	(0x1<<5)
#define RS_2	(0x2<<5)
#define RS_3	(0x3<<5)

#define CO_DataByte		(0x0<<7)
#define CO_CtrlByte		(0x1<<7)

#define LCD_X_LEN		(100/5)/*5bit in a byte*/
#define LCD_Y_LEN		18


#define DevCtrl_Init			IIC_Write(0x01)// ---> RS=0
#define DevCtrl_ClrRstFlg		IIC_Write(0x1f)// ---> RS=0
#define DevCtrl_OTP_Refresh	IIC_Write(0x02)// ---> RS=0

#define DevCtrl_Clk_Out_Ctrl(Pin_Clk)	IIC_Write(0x20|Pin_Clk)// ---> RS=0
						/*
							Pin_Clk=0, CLK pin = 3 status
							Pin_Clk=1, CLK pin signal valid
							
						*/
												
#define DevCtrl_Read_Reg_Sel(CS_Mode,SO_Mode)		IIC_Write(0x04|(CS_Mode<<1)|(SO_Mode))// ---> RS=0
						/*
							CS_Mode=0, checksum = XOR
							CS_Mode=1, checksum = CRC-8

							SO_Mode=0, Temperature info
							SO_Mode=1, status info
							
						*/

#define DevCtrl_Read_StatusReg()	IIC_Read(IIC_DUMMY)// ---> RS=0

#define DevCtrl_Graphic_Mode_Cfg(GMX)	IIC_Write(0x50|((GMX)<<2))// ---> RS=0
						/*
							GMX=0, 1:18 multiplex drive mode
							GMX=1, 1:12 multiplex drive mode
						*/

#define DevCtrl_Sel_Mem_bank(SMB)		IIC_Write(0x10|(SMB))// ---> RS=0
					/*
						SMB=0, general-purpose RAM 1 is selected
						SMB=1, display data RAM bank 1 is selected
						SMB=2, display data RAM bank 2 is selected
						SMB=3, display data RAM bank 3 is selected
						SMB=4, general-purpose RAM 2 is selected
					*/


#define DevCtrl_Set_Mem_addr(ADDR)		IIC_Write(0x80|(ADDR))// ---> RS=0
						/*
							ADDR:0x00~~0x7F = RAM address
						*/

/*#############################################################################*/
#define DevCtrl_Read_Data(ADDR)		IIC_Read(0x50|(ADDR)) // ---> RS=1
				/*
					ADDR:0x00~~0x7F = 
						read data from general-purpose RAM 1
						
					OR
					
					ADDR:0x00~~0x1F = 
						read data from display RAM bank 1 to 3 and
						general-purpose RAM 2
				*/
												
#define DevCtrl_Write_Data(ADDR)		IIC_Write(0x50|(ADDR))// ---> RS=1
				/*
					refer to read data!!
				*/


/*#############################################################################*/
#define DisCtrl_Entry_mode_set(I_D)	IIC_Write(0x28|((I_D)<<1))// ---> RS=2
				/*
					I_D=0
						display RAM or general-purpose RAM
						address decrements by 1

					I_D=1
						display RAM or general-purpose RAM
						address increments by 1
				*/
#define DisCtrl_Inversion_mode(INV)	IIC_Write(0x40|((INV)))// ---> RS=2
					/*
						INV=0:frame inversion mode
						INV=X: X-line inversion mode
							X=1~~7
					*/
#define DisCtrl_Frame_frequency(FF)	IIC_Write(0x80|((FF)))// ---> RS=2
					/*
					FF=		LCD_fre=
						0		45
						1		50
						10		55
						11		60
						100		65
						101		70
						110		75
						111		80[default]
						1000	85
						1001	90
						1010	95
						1011	100
						1100	110
						1101	120
						1110	130
						1111	145
						10000	160
						10001	180
						10010	210
						10011	240
						10100	290
						other	360
					*/
					
#define DisCtrl_Display_control(D)		IIC_Write(0x20|((D)<<2))// ---> RS=2
					/*
						D=0 display is off [default]
						D=1 display is on
					*/
					
#define DisCtrl_Display_config(P)	IIC_Write(0x04|((P)<<1))// ---> RS=2
				/*
					P=0 segment data: left to right; [default]
					P=1 segment data: right to left;
				*/

/*#############################################################################*/
#define DevCtrl_Charge_pump_ctrl(CPE_CPC)	IIC_Write(0x80|(CPE_CPC))// ---> RS=3
				/*
					CPE=0:using external Vlcd
					CPE=1:using internal Vlcd

					CPC=x : 
						0   2 x Vdd
						1   3 x Vdd
						2   4 x Vdd
						3   Vlcd=Vdd2 (direct mode)
				*/
				
#define DevCtrl_Set_VLCD_Msb(VLCD)	IIC_Write(0xA0|VLCD)// ---> RS=3
#define DevCtrl_Set_VLCD_Lsb(VLCD)	IIC_Write(0x90|VLCD)// ---> RS=3
				/*
					VLCD: Vlcd value
				*/		
#define DevCtrl_Temperature_ctrl(TCE_TMF_TME)	IIC_Write(TCE_TMF_TME)// ---> RS=3
				/*
					TCE:	temperature compensation of VLCD enable or not
					TMF:	digital temperature filter enabled or not
					TME:temperature measurement readout enable or not
				*/			
				
#define DevCtrl_TC_slope_TSA(X)	IIC_Write(0x08|X)// ---> RS=3
#define DevCtrl_TC_slope_TSB(X)	IIC_Write(0x10|X)// ---> RS=3
#define DevCtrl_TC_slope_TSC(X)	IIC_Write(0x18|X)// ---> RS=3
#define DevCtrl_TC_slope_TSD(X)	IIC_Write(0x20|X)// ---> RS=3
			/*
				TSx		slopeFactor(mV/C)
				000		 0 				0.000	[default]
				001 		-6 				-0.125
				010 		-12 				-0.250
				011 		-24 				-0.500
				100 		-60				-1.250
				101 		+6 				+0.125
				110 		+12 				+0.250
				111 		+24 				+0.500
			*/		


/*#############################################################################*/

typedef const struct
{
	uint8 u8SlaveAddr;
	uint8 u8MultiplexNum;
						/*	GMX=0, 1:18 multiplex drive mode
							GMX=1, 1:12 multiplex drive mode	*/
							
	uint8 u8LineInv;		/*	INV=0:frame inversion mode
							INV=X: X-line inversion mode
							X=1~~7	*/
	uint8 u8LCDFrequency;
			/*u8LCDFrequency		LCD_fre=
						0		45
						1		50
						10		55
						11		60
						100		65
						101		70
						110		75
						111		80[default]
						1000	85
						1001	90
						1010	95
						1011	100
						1100	110
						1101	120
						1110	130
						1111	145
						10000	160
						10001	180
						10010	210
						10011	240
						10100	290
						other	360*/
					
	uint8 u8TemperatureSet;
				/*
					BIT2=TCE:	temperature compensation of VLCD enable or not
					BIT1=TMF:	digital temperature filter enabled or not
					BIT0=TME:	temperature measurement readout enable or not
				*/			


	uint8 u8TSA;
	uint8 u8TSB;
	uint8 u8TSC;
	uint8 u8TSD;
	
	uint8 u8EVvalue;
	uint8 u8ChargeCtrl;
				/*BIT0:
				
					CPE=0:using external Vlcd
					CPE=1:using internal Vlcd

				BIT1-2:
				
				CPC=x : 
					0   2 x Vdd
					1   3 x Vdd
					2   4 x Vdd
					3   Vlcd=Vdd2 (direct mode)*/
					
				

	
}PCA8539_UsrCfg;



#endif

