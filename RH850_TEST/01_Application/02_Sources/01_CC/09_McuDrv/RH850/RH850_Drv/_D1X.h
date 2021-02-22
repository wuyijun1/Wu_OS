/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _D1L_D1M.h
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

#ifndef _D1X_H_
#define _D1X_H_

#define MCU_MaxPinPerPort		16u
#define MCU_MaxPortMount		47u
#define MCU_MaxPortType		2u

#define MCU_MaxAPortMount	0x0u
#define MCU_MaxJPortMount		0x1u
#define MCU_MaxIPortMount		0x0u

#define MCU_MaxADC0channelMount	19u
#define MCU_MaxADC1channelMount	0u
#define MCU_MaxTAUBunitMount		3u
#define MCU_MaxTAUDunitMount		0u
#define MCU_MaxTAUJunitMount		1u
#define MCU_MaxPWGAchannelMount	72u


#define MCU_mPortBaseAddr_P0 			0xFF618000ul
#define MCU_mPortExtAddr_P0 			(0xFFC18000ul+0x4000ul)
#define MCU_mPortBaseAddr_PCR0 		(MCU_mPortBaseAddr_P0+0x2000ul)

#define MCU_mPortBaseAddr				(0xFF610000UL)				
#define MCU_mPortExtAddr				(0xFFC10000UL+0x4000ul)		
#define MCU_mPortBaseAddr_PCR 		(MCU_mPortBaseAddr+0x2000ul)

#define MCU_mJPortBaseAddr_JP0		0xFF620000UL	
#define MCU_mJPortExtAddr_JP0			(0xFFC20000UL+0x4000ul)
#define MCU_mJPortBaseAddr_JPCR0 		(MCU_mJPortBaseAddr_JP0+0x2000ul)


/*******************************
PortType Mask 
-----------------------------

bit5,6,7 using for Port type mask:

normal port: 	000
J-port:		001
A-port:		010
I-port:		011

********************************/
#define MCU_mPinTypetMask_Port	((uint32)(0x0000u<<5))
#define MCU_mPinTypetMask_JPort	((uint32)(0x0001u<<5))
#define MCU_mPinTypetMask_IPort	((uint32)(0X0002u<<5))
#define MCU_mPinTypetMask_APort	((uint32)(0x0003u<<5))
#define MCU_mPortMask			((uint32)(0x0007u<<5))

#define MCU_mPinTypeID_Port		(0x0000u)
#define MCU_mPinTypeID_JPort	(0x0001u)
#define MCU_mPinTypeID_IPort	(0X0002u)
#define MCU_mPinTypeID_APort	(0x0003u)
#define MCU_mPinTypeID_Max	(0X0004u)


typedef enum 
{
	/*******************************
	Pin ID define=====Port 0 
	-----------------------------
	Port ID mask = 0x0ZZZ
	********************************/
	
	/*Pin ID define=====Port 0*/											
	 MCU_mPinID_P0_0	=	0x0000u,									
	 MCU_mPinID_P0_1	=	0x0001u,									
	 MCU_mPinID_P0_2	=	0x0002u,									
	 MCU_mPinID_P0_3	=	0x0003u,									
	 MCU_mPinID_P0_4	=	0x0004u,									
	 MCU_mPinID_P0_5	=	0x0005u,									
	 MCU_mPinID_P0_6	=	0x0006u,									
	 MCU_mPinID_P0_7	=	0x0007u,									
	 MCU_mPinID_P0_8	=	0x0008u,									
	 MCU_mPinID_P0_9	=	0x0009u,									
	 MCU_mPinID_P0_10	=	0x000au,									
	 MCU_mPinID_P0_11	=	0x000bu,									
	 MCU_mPinID_P0_12	=	0x000cu,									
	 MCU_mPinID_P0_13	=	0x000du,									
	 MCU_mPinID_P0_14	=	0x000eu,									
	 MCU_mPinID_P0_15	=	0x000fu,									

	/*Pin ID define=====Port 1*/											
	 MCU_mPinID_P1_0	=	0x0100u,									
	 MCU_mPinID_P1_1	=	0x0101u,									
	 MCU_mPinID_P1_2	=	0x0102u,									
	 MCU_mPinID_P1_3	=	0x0103u,									
	 MCU_mPinID_P1_4	=	0x0104u,									
	 MCU_mPinID_P1_5	=	0x0105u,									
	 MCU_mPinID_P1_6	=	0x0106u,									
	 MCU_mPinID_P1_7	=	0x0107u,									
	 MCU_mPinID_P1_8	=	0x0108u,									
	 MCU_mPinID_P1_9	=	0x0109u,									
	 MCU_mPinID_P1_10	=	0x010au,									
	 MCU_mPinID_P1_11	=	0x010bu,									
	 MCU_mPinID_P1_12	=	0x010cu,									
	 MCU_mPinID_P1_13	=	0x010du,									
	 MCU_mPinID_P1_14	=	0x010eu,									
	 MCU_mPinID_P1_15	=	0x010fu,									

	/*Pin ID define=====Port 2*/										
	 MCU_mPinID_P2_0	=	0x0200u,									
	 MCU_mPinID_P2_1	=	0x0201u,									
	 MCU_mPinID_P2_2	=	0x0202u,									
	 MCU_mPinID_P2_3	=	0x0203u,									
	 MCU_mPinID_P2_4	=	0x0204u,									
	 MCU_mPinID_P2_5	=	0x0205u,									
	 MCU_mPinID_P2_6	=	0x0206u,									
	 MCU_mPinID_P2_7	=	0x0207u,									
	 MCU_mPinID_P2_8	=	0x0208u,									
	 MCU_mPinID_P2_9	=	0x0209u,									
	 MCU_mPinID_P2_10	=	0x020au,									
	 MCU_mPinID_P2_11	=	0x020bu,									
	 MCU_mPinID_P2_12	=	0x020cu,									
	 MCU_mPinID_P2_13	=	0x020du,									
	 MCU_mPinID_P2_14	=	0x020eu,									
	 MCU_mPinID_P2_15	=	0x020fu,									

	/*Pin ID define=====Port 3*/											
	 MCU_mPinID_P3_0	=	0x0300u,									
	 MCU_mPinID_P3_1	=	0x0301u,									
	 MCU_mPinID_P3_2	=	0x0302u,									
	 MCU_mPinID_P3_3	=	0x0303u,									
	 MCU_mPinID_P3_4	=	0x0304u,									
	 MCU_mPinID_P3_5	=	0x0305u,									
	 MCU_mPinID_P3_6	=	0x0306u,									
	 MCU_mPinID_P3_7	=	0x0307u,									
	 MCU_mPinID_P3_8	=	0x0308u,									
	 MCU_mPinID_P3_9	=	0x0309u,									
	 MCU_mPinID_P3_10	=	0x030au,									
	 MCU_mPinID_P3_11	=	0x030bu,									
	 MCU_mPinID_P3_12	=	0x030cu,									
	 MCU_mPinID_P3_13	=	0x030du,									
	 MCU_mPinID_P3_14	=	0x030eu,									
	 MCU_mPinID_P3_15	=	0x030fu,									

	/*Pin ID define=====Port 4*/											
	 MCU_mPinID_P4_0	=	0x0400u,									
	 MCU_mPinID_P4_1	=	0x0401u,									
	 MCU_mPinID_P4_2	=	0x0402u,									
	 MCU_mPinID_P4_3	=	0x0403u,									
	 MCU_mPinID_P4_4	=	0x0404u,									
	 MCU_mPinID_P4_5	=	0x0405u,									
	 MCU_mPinID_P4_6	=	0x0406u,									
	 MCU_mPinID_P4_7	=	0x0407u,									
	 MCU_mPinID_P4_8	=	0x0408u,									
	 MCU_mPinID_P4_9	=	0x0409u,									
	 MCU_mPinID_P4_10	=	0x040au,									
	 MCU_mPinID_P4_11	=	0x040bu,									
	 MCU_mPinID_P4_12	=	0x040cu,									
	 MCU_mPinID_P4_13	=	0x040du,									
	 MCU_mPinID_P4_14	=	0x040eu,									
	 MCU_mPinID_P4_15	=	0x040fu,									

	/*Pin ID define=====Port 5*/											
	 MCU_mPinID_P5_0	=	0x0500u,									
	 MCU_mPinID_P5_1	=	0x0501u,									
	 MCU_mPinID_P5_2	=	0x0502u,									
	 MCU_mPinID_P5_3	=	0x0503u,									
	 MCU_mPinID_P5_4	=	0x0504u,									
	 MCU_mPinID_P5_5	=	0x0505u,									
	 MCU_mPinID_P5_6	=	0x0506u,									
	 MCU_mPinID_P5_7	=	0x0507u,									
	 MCU_mPinID_P5_8	=	0x0508u,									
	 MCU_mPinID_P5_9	=	0x0509u,									
	 MCU_mPinID_P5_10	=	0x050au,									
	 MCU_mPinID_P5_11	=	0x050bu,									
	 MCU_mPinID_P5_12	=	0x050cu,									
	 MCU_mPinID_P5_13	=	0x050du,									
	 MCU_mPinID_P5_14	=	0x050eu,									
	 MCU_mPinID_P5_15	=	0x050fu,									

	/*Pin ID define=====Port 6*/											
	 MCU_mPinID_P6_0	=	0x0600u,									
	 MCU_mPinID_P6_1	=	0x0601u,									
	 MCU_mPinID_P6_2	=	0x0602u,									
	 MCU_mPinID_P6_3	=	0x0603u,									
	 MCU_mPinID_P6_4	=	0x0604u,									
	 MCU_mPinID_P6_5	=	0x0605u,									
	 MCU_mPinID_P6_6	=	0x0606u,									
	 MCU_mPinID_P6_7	=	0x0607u,									
	 MCU_mPinID_P6_8	=	0x0608u,									
	 MCU_mPinID_P6_9	=	0x0609u,									
	 MCU_mPinID_P6_10	=	0x060au,									
	 MCU_mPinID_P6_11	=	0x060bu,									
	 MCU_mPinID_P6_12	=	0x060cu,									
	 MCU_mPinID_P6_13	=	0x060du,									
	 MCU_mPinID_P6_14	=	0x060eu,									
	 MCU_mPinID_P6_15	=	0x060fu,									

	/*Pin ID define=====Port 7*/											
	 MCU_mPinID_P7_0	=	0x0700u,									
	 MCU_mPinID_P7_1	=	0x0701u,									
	 MCU_mPinID_P7_2	=	0x0702u,									
	 MCU_mPinID_P7_3	=	0x0703u,									
	 MCU_mPinID_P7_4	=	0x0704u,									
	 MCU_mPinID_P7_5	=	0x0705u,									
	 MCU_mPinID_P7_6	=	0x0706u,									
	 MCU_mPinID_P7_7	=	0x0707u,									
	 MCU_mPinID_P7_8	=	0x0708u,									
	 MCU_mPinID_P7_9	=	0x0709u,									
	 MCU_mPinID_P7_10	=	0x070au,									
	 MCU_mPinID_P7_11	=	0x070bu,									
	 MCU_mPinID_P7_12	=	0x070cu,									
	 MCU_mPinID_P7_13	=	0x070du,									
	 MCU_mPinID_P7_14	=	0x070eu,									
	 MCU_mPinID_P7_15	=	0x070fu,									

	/*Pin ID define=====Port 8*/											
	 MCU_mPinID_P8_0	=	0x0800u,									
	 MCU_mPinID_P8_1	=	0x0801u,									
	 MCU_mPinID_P8_2	=	0x0802u,									
	 MCU_mPinID_P8_3	=	0x0803u,									
	 MCU_mPinID_P8_4	=	0x0804u,									
	 MCU_mPinID_P8_5	=	0x0805u,									
	 MCU_mPinID_P8_6	=	0x0806u,									
	 MCU_mPinID_P8_7	=	0x0807u,									
	 MCU_mPinID_P8_8	=	0x0808u,									
	 MCU_mPinID_P8_9	=	0x0809u,									
	 MCU_mPinID_P8_10	=	0x080au,									
	 MCU_mPinID_P8_11	=	0x080bu,									
	 MCU_mPinID_P8_12	=	0x080cu,									
	 MCU_mPinID_P8_13	=	0x080du,									
	 MCU_mPinID_P8_14	=	0x080eu,									
	 MCU_mPinID_P8_15	=	0x080fu,									

	/*Pin ID define=====Port 9*/											
	 MCU_mPinID_P9_0	=	0x0900u,									
	 MCU_mPinID_P9_1	=	0x0901u,									
	 MCU_mPinID_P9_2	=	0x0902u,									
	 MCU_mPinID_P9_3	=	0x0903u,									
	 MCU_mPinID_P9_4	=	0x0904u,									
	 MCU_mPinID_P9_5	=	0x0905u,									
	 MCU_mPinID_P9_6	=	0x0906u,									
	 MCU_mPinID_P9_7	=	0x0907u,									
	 MCU_mPinID_P9_8	=	0x0908u,									
	 MCU_mPinID_P9_9	=	0x0909u,									
	 MCU_mPinID_P9_10	=	0x090au,									
	 MCU_mPinID_P9_11	=	0x090bu,									
	 MCU_mPinID_P9_12	=	0x090cu,									
	 MCU_mPinID_P9_13	=	0x090du,									
	 MCU_mPinID_P9_14	=	0x090eu,									
	 MCU_mPinID_P9_15	=	0x090fu,									

	/*Pin ID define=====Port 10*/											
	 MCU_mPinID_P10_0	=	0x0a00u,									
	 MCU_mPinID_P10_1	=	0x0a01u,									
	 MCU_mPinID_P10_2	=	0x0a02u,									
	 MCU_mPinID_P10_3	=	0x0a03u,									
	 MCU_mPinID_P10_4	=	0x0a04u,									
	 MCU_mPinID_P10_5	=	0x0a05u,									
	 MCU_mPinID_P10_6	=	0x0a06u,									
	 MCU_mPinID_P10_7	=	0x0a07u,									
	 MCU_mPinID_P10_8	=	0x0a08u,									
	 MCU_mPinID_P10_9	=	0x0a09u,									
	 MCU_mPinID_P10_10	=	0x0a0au,									
	 MCU_mPinID_P10_11	=	0x0a0bu,									
	 MCU_mPinID_P10_12	=	0x0a0cu,									
	 MCU_mPinID_P10_13	=	0x0a0du,									
	 MCU_mPinID_P10_14	=	0x0a0eu,									
	 MCU_mPinID_P10_15	=	0x0a0fu,									

	/*Pin ID define=====Port 11*/											
	 MCU_mPinID_P11_0	=	0x0b00u,									
	 MCU_mPinID_P11_1	=	0x0b01u,									
	 MCU_mPinID_P11_2	=	0x0b02u,									
	 MCU_mPinID_P11_3	=	0x0b03u,									
	 MCU_mPinID_P11_4	=	0x0b04u,									
	 MCU_mPinID_P11_5	=	0x0b05u,									
	 MCU_mPinID_P11_6	=	0x0b06u,									
	 MCU_mPinID_P11_7	=	0x0b07u,									
	 MCU_mPinID_P11_8	=	0x0b08u,									
	 MCU_mPinID_P11_9	=	0x0b09u,									
	 MCU_mPinID_P11_10	=	0x0b0au,									
	 MCU_mPinID_P11_11	=	0x0b0bu,									
	 MCU_mPinID_P11_12	=	0x0b0cu,									
	 MCU_mPinID_P11_13	=	0x0b0du,									
	 MCU_mPinID_P11_14	=	0x0b0eu,									
	 MCU_mPinID_P11_15	=	0x0b0fu,									

	/*Pin ID define=====Port 12*/											
	 MCU_mPinID_P12_0	=	0x0c00u,									
	 MCU_mPinID_P12_1	=	0x0c01u,									
	 MCU_mPinID_P12_2	=	0x0c02u,									
	 MCU_mPinID_P12_3	=	0x0c03u,									
	 MCU_mPinID_P12_4	=	0x0c04u,									
	 MCU_mPinID_P12_5	=	0x0c05u,									
	 MCU_mPinID_P12_6	=	0x0c06u,									
	 MCU_mPinID_P12_7	=	0x0c07u,									
	 MCU_mPinID_P12_8	=	0x0c08u,									
	 MCU_mPinID_P12_9	=	0x0c09u,									
	 MCU_mPinID_P12_10	=	0x0c0au,									
	 MCU_mPinID_P12_11	=	0x0c0bu,									
	 MCU_mPinID_P12_12	=	0x0c0cu,									
	 MCU_mPinID_P12_13	=	0x0c0du,									
	 MCU_mPinID_P12_14	=	0x0c0eu,									
	 MCU_mPinID_P12_15	=	0x0c0fu,									

	/*Pin ID define=====Port 13*/											
	 MCU_mPinID_P13_0	=	0x0d00u,									
	 MCU_mPinID_P13_1	=	0x0d01u,									
	 MCU_mPinID_P13_2	=	0x0d02u,									
	 MCU_mPinID_P13_3	=	0x0d03u,									
	 MCU_mPinID_P13_4	=	0x0d04u,									
	 MCU_mPinID_P13_5	=	0x0d05u,									
	 MCU_mPinID_P13_6	=	0x0d06u,									
	 MCU_mPinID_P13_7	=	0x0d07u,									
	 MCU_mPinID_P13_8	=	0x0d08u,									
	 MCU_mPinID_P13_9	=	0x0d09u,									
	 MCU_mPinID_P13_10	=	0x0d0au,									
	 MCU_mPinID_P13_11	=	0x0d0bu,									
	 MCU_mPinID_P13_12	=	0x0d0cu,									
	 MCU_mPinID_P13_13	=	0x0d0du,									
	 MCU_mPinID_P13_14	=	0x0d0eu,									
	 MCU_mPinID_P13_15	=	0x0d0fu,									

	/*Pin ID define=====Port 14*/											
	 MCU_mPinID_P14_0	=	0x0e00u,									
	 MCU_mPinID_P14_1	=	0x0e01u,									
	 MCU_mPinID_P14_2	=	0x0e02u,									
	 MCU_mPinID_P14_3	=	0x0e03u,									
	 MCU_mPinID_P14_4	=	0x0e04u,									
	 MCU_mPinID_P14_5	=	0x0e05u,									
	 MCU_mPinID_P14_6	=	0x0e06u,									
	 MCU_mPinID_P14_7	=	0x0e07u,									
	 MCU_mPinID_P14_8	=	0x0e08u,									
	 MCU_mPinID_P14_9	=	0x0e09u,									
	 MCU_mPinID_P14_10	=	0x0e0au,									
	 MCU_mPinID_P14_11	=	0x0e0bu,									
	 MCU_mPinID_P14_12	=	0x0e0cu,									
	 MCU_mPinID_P14_13	=	0x0e0du,									
	 MCU_mPinID_P14_14	=	0x0e0eu,									
	 MCU_mPinID_P14_15	=	0x0e0fu,									

	/*Pin ID define=====Port 15*/											
	 MCU_mPinID_P15_0	=	0x0f00u,									
	 MCU_mPinID_P15_1	=	0x0f01u,									
	 MCU_mPinID_P15_2	=	0x0f02u,									
	 MCU_mPinID_P15_3	=	0x0f03u,									
	 MCU_mPinID_P15_4	=	0x0f04u,									
	 MCU_mPinID_P15_5	=	0x0f05u,									
	 MCU_mPinID_P15_6	=	0x0f06u,									
	 MCU_mPinID_P15_7	=	0x0f07u,									
	 MCU_mPinID_P15_8	=	0x0f08u,									
	 MCU_mPinID_P15_9	=	0x0f09u,									
	 MCU_mPinID_P15_10	=	0x0f0au,									
	 MCU_mPinID_P15_11	=	0x0f0bu,									
	 MCU_mPinID_P15_12	=	0x0f0cu,									
	 MCU_mPinID_P15_13	=	0x0f0du,									
	 MCU_mPinID_P15_14	=	0x0f0eu,									
	 MCU_mPinID_P15_15	=	0x0f0fu,									

	/*Pin ID define=====Port 16*/											
	 MCU_mPinID_P16_0	=	0x1000u,									
	 MCU_mPinID_P16_1	=	0x1001u,									
	 MCU_mPinID_P16_2	=	0x1002u,									
	 MCU_mPinID_P16_3	=	0x1003u,									
	 MCU_mPinID_P16_4	=	0x1004u,									
	 MCU_mPinID_P16_5	=	0x1005u,									
	 MCU_mPinID_P16_6	=	0x1006u,									
	 MCU_mPinID_P16_7	=	0x1007u,									
	 MCU_mPinID_P16_8	=	0x1008u,									
	 MCU_mPinID_P16_9	=	0x1009u,									
	 MCU_mPinID_P16_10	=	0x100au,									
	 MCU_mPinID_P16_11	=	0x100bu,									
	 MCU_mPinID_P16_12	=	0x100cu,									
	 MCU_mPinID_P16_13	=	0x100du,									
	 MCU_mPinID_P16_14	=	0x100eu,									
	 MCU_mPinID_P16_15	=	0x100fu,									

	/*Pin ID define=====Port 17*/											
	 MCU_mPinID_P17_0	=	0x1100u,									
	 MCU_mPinID_P17_1	=	0x1101u,									
	 MCU_mPinID_P17_2	=	0x1102u,									
	 MCU_mPinID_P17_3	=	0x1103u,									
	 MCU_mPinID_P17_4	=	0x1104u,									
	 MCU_mPinID_P17_5	=	0x1105u,									
	 MCU_mPinID_P17_6	=	0x1106u,									
	 MCU_mPinID_P17_7	=	0x1107u,									
	 MCU_mPinID_P17_8	=	0x1108u,									
	 MCU_mPinID_P17_9	=	0x1109u,									
	 MCU_mPinID_P17_10	=	0x110au,									
	 MCU_mPinID_P17_11	=	0x110bu,									
	 MCU_mPinID_P17_12	=	0x110cu,									
	 MCU_mPinID_P17_13	=	0x110du,									
	 MCU_mPinID_P17_14	=	0x110eu,									
	 MCU_mPinID_P17_15	=	0x110fu,									

	/*Pin ID define=====Port 18*/											
	 MCU_mPinID_P18_0	=	0x1200u,									
	 MCU_mPinID_P18_1	=	0x1201u,									
	 MCU_mPinID_P18_2	=	0x1202u,									
	 MCU_mPinID_P18_3	=	0x1203u,									
	 MCU_mPinID_P18_4	=	0x1204u,									
	 MCU_mPinID_P18_5	=	0x1205u,									
	 MCU_mPinID_P18_6	=	0x1206u,									
	 MCU_mPinID_P18_7	=	0x1207u,									
	 MCU_mPinID_P18_8	=	0x1208u,									
	 MCU_mPinID_P18_9	=	0x1209u,									
	 MCU_mPinID_P18_10	=	0x120au,									
	 MCU_mPinID_P18_11	=	0x120bu,									
	 MCU_mPinID_P18_12	=	0x120cu,									
	 MCU_mPinID_P18_13	=	0x120du,									
	 MCU_mPinID_P18_14	=	0x120eu,									
	 MCU_mPinID_P18_15	=	0x120fu,									

	/*Pin ID define=====Port 19*/										
	 MCU_mPinID_P19_0	=	0x1300u,									
	 MCU_mPinID_P19_1	=	0x1301u,									
	 MCU_mPinID_P19_2	=	0x1302u,									
	 MCU_mPinID_P19_3	=	0x1303u,									
	 MCU_mPinID_P19_4	=	0x1304u,									
	 MCU_mPinID_P19_5	=	0x1305u,									
	 MCU_mPinID_P19_6	=	0x1306u,									
	 MCU_mPinID_P19_7	=	0x1307u,									
	 MCU_mPinID_P19_8	=	0x1308u,									
	 MCU_mPinID_P19_9	=	0x1309u,									
	 MCU_mPinID_P19_10	=	0x130au,									
	 MCU_mPinID_P19_11	=	0x130bu,									
	 MCU_mPinID_P19_12	=	0x130cu,									
	 MCU_mPinID_P19_13	=	0x130du,									
	 MCU_mPinID_P19_14	=	0x130eu,									
	 MCU_mPinID_P19_15	=	0x130fu,									

	/*Pin ID define=====Port 20*/										
	 MCU_mPinID_P20_0	=	0x1400u,									
	 MCU_mPinID_P20_1	=	0x1401u,									
	 MCU_mPinID_P20_2	=	0x1402u,									
	 MCU_mPinID_P20_3	=	0x1403u,									
	 MCU_mPinID_P20_4	=	0x1404u,									
	 MCU_mPinID_P20_5	=	0x1405u,									
	 MCU_mPinID_P20_6	=	0x1406u,									
	 MCU_mPinID_P20_7	=	0x1407u,									
	 MCU_mPinID_P20_8	=	0x1408u,									
	 MCU_mPinID_P20_9	=	0x1409u,									
	 MCU_mPinID_P20_10	=	0x140au,									
	 MCU_mPinID_P20_11	=	0x140bu,									
	 MCU_mPinID_P20_12	=	0x140cu,									
	 MCU_mPinID_P20_13	=	0x140du,									
	 MCU_mPinID_P20_14	=	0x140eu,									
	 MCU_mPinID_P20_15	=	0x140fu,									

	/*Pin ID define=====Port 21*/											
	 MCU_mPinID_P21_0	=	0x1500u,									
	 MCU_mPinID_P21_1	=	0x1501u,									
	 MCU_mPinID_P21_2	=	0x1502u,									
	 MCU_mPinID_P21_3	=	0x1503u,									
	 MCU_mPinID_P21_4	=	0x1504u,									
	 MCU_mPinID_P21_5	=	0x1505u,									
	 MCU_mPinID_P21_6	=	0x1506u,									
	 MCU_mPinID_P21_7	=	0x1507u,									
	 MCU_mPinID_P21_8	=	0x1508u,									
	 MCU_mPinID_P21_9	=	0x1509u,									
	 MCU_mPinID_P21_10	=	0x150au,									
	 MCU_mPinID_P21_11	=	0x150bu,									
	 MCU_mPinID_P21_12	=	0x150cu,									
	 MCU_mPinID_P21_13	=	0x150du,									
	 MCU_mPinID_P21_14	=	0x150eu,									
	 MCU_mPinID_P21_15	=	0x150fu,									

	/*Pin ID define=====Port 22*/											
	 MCU_mPinID_P22_0	=	0x1600u,									
	 MCU_mPinID_P22_1	=	0x1601u,									
	 MCU_mPinID_P22_2	=	0x1602u,									
	 MCU_mPinID_P22_3	=	0x1603u,									
	 MCU_mPinID_P22_4	=	0x1604u,									
	 MCU_mPinID_P22_5	=	0x1605u,									
	 MCU_mPinID_P22_6	=	0x1606u,									
	 MCU_mPinID_P22_7	=	0x1607u,									
	 MCU_mPinID_P22_8	=	0x1608u,									
	 MCU_mPinID_P22_9	=	0x1609u,									
	 MCU_mPinID_P22_10	=	0x160au,									
	 MCU_mPinID_P22_11	=	0x160bu,									
	 MCU_mPinID_P22_12	=	0x160cu,									
	 MCU_mPinID_P22_13	=	0x160du,									
	 MCU_mPinID_P22_14	=	0x160eu,									
	 MCU_mPinID_P22_15	=	0x160fu,									

	/*Pin ID define=====Port 23*/											
	 MCU_mPinID_P23_0	=	0x1700u,									
	 MCU_mPinID_P23_1	=	0x1701u,									
	 MCU_mPinID_P23_2	=	0x1702u,									
	 MCU_mPinID_P23_3	=	0x1703u,									
	 MCU_mPinID_P23_4	=	0x1704u,									
	 MCU_mPinID_P23_5	=	0x1705u,									
	 MCU_mPinID_P23_6	=	0x1706u,									
	 MCU_mPinID_P23_7	=	0x1707u,									
	 MCU_mPinID_P23_8	=	0x1708u,									
	 MCU_mPinID_P23_9	=	0x1709u,									
	 MCU_mPinID_P23_10	=	0x170au,									
	 MCU_mPinID_P23_11	=	0x170bu,									
	 MCU_mPinID_P23_12	=	0x170cu,									
	 MCU_mPinID_P23_13	=	0x170du,									
	 MCU_mPinID_P23_14	=	0x170eu,									
	 MCU_mPinID_P23_15	=	0x170fu,									

	/*Pin ID define=====Port 24*/											
	 MCU_mPinID_P24_0	=	0x1800u,									
	 MCU_mPinID_P24_1	=	0x1801u,									
	 MCU_mPinID_P24_2	=	0x1802u,									
	 MCU_mPinID_P24_3	=	0x1803u,									
	 MCU_mPinID_P24_4	=	0x1804u,									
	 MCU_mPinID_P24_5	=	0x1805u,									
	 MCU_mPinID_P24_6	=	0x1806u,									
	 MCU_mPinID_P24_7	=	0x1807u,									
	 MCU_mPinID_P24_8	=	0x1808u,									
	 MCU_mPinID_P24_9	=	0x1809u,									
	 MCU_mPinID_P24_10	=	0x180au,									
	 MCU_mPinID_P24_11	=	0x180bu,									
	 MCU_mPinID_P24_12	=	0x180cu,									
	 MCU_mPinID_P24_13	=	0x180du,									
	 MCU_mPinID_P24_14	=	0x180eu,									
	 MCU_mPinID_P24_15	=	0x180fu,									

	/*Pin ID define=====Port 25*/											
	 MCU_mPinID_P25_0	=	0x1900u,									
	 MCU_mPinID_P25_1	=	0x1901u,									
	 MCU_mPinID_P25_2	=	0x1902u,									
	 MCU_mPinID_P25_3	=	0x1903u,									
	 MCU_mPinID_P25_4	=	0x1904u,									
	 MCU_mPinID_P25_5	=	0x1905u,									
	 MCU_mPinID_P25_6	=	0x1906u,									
	 MCU_mPinID_P25_7	=	0x1907u,									
	 MCU_mPinID_P25_8	=	0x1908u,									
	 MCU_mPinID_P25_9	=	0x1909u,									
	 MCU_mPinID_P25_10	=	0x190au,									
	 MCU_mPinID_P25_11	=	0x190bu,									
	 MCU_mPinID_P25_12	=	0x190cu,									
	 MCU_mPinID_P25_13	=	0x190du,									
	 MCU_mPinID_P25_14	=	0x190eu,									
	 MCU_mPinID_P25_15	=	0x190fu,									

	/*Pin ID define=====Port 26*/											
	 MCU_mPinID_P26_0	=	0x1a00u,									
	 MCU_mPinID_P26_1	=	0x1a01u,									
	 MCU_mPinID_P26_2	=	0x1a02u,									
	 MCU_mPinID_P26_3	=	0x1a03u,									
	 MCU_mPinID_P26_4	=	0x1a04u,									
	 MCU_mPinID_P26_5	=	0x1a05u,									
	 MCU_mPinID_P26_6	=	0x1a06u,									
	 MCU_mPinID_P26_7	=	0x1a07u,									
	 MCU_mPinID_P26_8	=	0x1a08u,									
	 MCU_mPinID_P26_9	=	0x1a09u,									
	 MCU_mPinID_P26_10	=	0x1a0au,									
	 MCU_mPinID_P26_11	=	0x1a0bu,									
	 MCU_mPinID_P26_12	=	0x1a0cu,									
	 MCU_mPinID_P26_13	=	0x1a0du,									
	 MCU_mPinID_P26_14	=	0x1a0eu,									
	 MCU_mPinID_P26_15	=	0x1a0fu,									

	/*Pin ID define=====Port 27*/											
	 MCU_mPinID_P27_0	=	0x1b00u,									
	 MCU_mPinID_P27_1	=	0x1b01u,									
	 MCU_mPinID_P27_2	=	0x1b02u,									
	 MCU_mPinID_P27_3	=	0x1b03u,									
	 MCU_mPinID_P27_4	=	0x1b04u,									
	 MCU_mPinID_P27_5	=	0x1b05u,									
	 MCU_mPinID_P27_6	=	0x1b06u,									
	 MCU_mPinID_P27_7	=	0x1b07u,									
	 MCU_mPinID_P27_8	=	0x1b08u,									
	 MCU_mPinID_P27_9	=	0x1b09u,									
	 MCU_mPinID_P27_10	=	0x1b0au,									
	 MCU_mPinID_P27_11	=	0x1b0bu,									
	 MCU_mPinID_P27_12	=	0x1b0cu,									
	 MCU_mPinID_P27_13	=	0x1b0du,									
	 MCU_mPinID_P27_14	=	0x1b0eu,									
	 MCU_mPinID_P27_15	=	0x1b0fu,									

	/*Pin ID define=====Port 28*/											
	 MCU_mPinID_P28_0	=	0x1c00u,									
	 MCU_mPinID_P28_1	=	0x1c01u,									
	 MCU_mPinID_P28_2	=	0x1c02u,									
	 MCU_mPinID_P28_3	=	0x1c03u,									
	 MCU_mPinID_P28_4	=	0x1c04u,									
	 MCU_mPinID_P28_5	=	0x1c05u,									
	 MCU_mPinID_P28_6	=	0x1c06u,									
	 MCU_mPinID_P28_7	=	0x1c07u,									
	 MCU_mPinID_P28_8	=	0x1c08u,									
	 MCU_mPinID_P28_9	=	0x1c09u,									
	 MCU_mPinID_P28_10	=	0x1c0au,									
	 MCU_mPinID_P28_11	=	0x1c0bu,									
	 MCU_mPinID_P28_12	=	0x1c0cu,									
	 MCU_mPinID_P28_13	=	0x1c0du,									
	 MCU_mPinID_P28_14	=	0x1c0eu,									
	 MCU_mPinID_P28_15	=	0x1c0fu,									

	/*Pin ID define=====Port 29*/											
	 MCU_mPinID_P29_0	=	0x1d00u,									
	 MCU_mPinID_P29_1	=	0x1d01u,									
	 MCU_mPinID_P29_2	=	0x1d02u,									
	 MCU_mPinID_P29_3	=	0x1d03u,									
	 MCU_mPinID_P29_4	=	0x1d04u,									
	 MCU_mPinID_P29_5	=	0x1d05u,									
	 MCU_mPinID_P29_6	=	0x1d06u,									
	 MCU_mPinID_P29_7	=	0x1d07u,									
	 MCU_mPinID_P29_8	=	0x1d08u,									
	 MCU_mPinID_P29_9	=	0x1d09u,									
	 MCU_mPinID_P29_10	=	0x1d0au,									
	 MCU_mPinID_P29_11	=	0x1d0bu,									
	 MCU_mPinID_P29_12	=	0x1d0cu,									
	 MCU_mPinID_P29_13	=	0x1d0du,									
	 MCU_mPinID_P29_14	=	0x1d0eu,									
	 MCU_mPinID_P29_15	=	0x1d0fu,									

	/*Pin ID define=====Port 30*/											
	 MCU_mPinID_P30_0	=	0x1e00u,									
	 MCU_mPinID_P30_1	=	0x1e01u,									
	 MCU_mPinID_P30_2	=	0x1e02u,									
	 MCU_mPinID_P30_3	=	0x1e03u,									
	 MCU_mPinID_P30_4	=	0x1e04u,									
	 MCU_mPinID_P30_5	=	0x1e05u,									
	 MCU_mPinID_P30_6	=	0x1e06u,									
	 MCU_mPinID_P30_7	=	0x1e07u,									
	 MCU_mPinID_P30_8	=	0x1e08u,									
	 MCU_mPinID_P30_9	=	0x1e09u,									
	 MCU_mPinID_P30_10	=	0x1e0au,									
	 MCU_mPinID_P30_11	=	0x1e0bu,									
	 MCU_mPinID_P30_12	=	0x1e0cu,									
	 MCU_mPinID_P30_13	=	0x1e0du,									
	 MCU_mPinID_P30_14	=	0x1e0eu,									
	 MCU_mPinID_P30_15	=	0x1e0fu,									

	/*Pin ID define=====Port 31*/											
	 MCU_mPinID_P31_0	=	0x1f00u,									
	 MCU_mPinID_P31_1	=	0x1f01u,									
	 MCU_mPinID_P31_2	=	0x1f02u,									
	 MCU_mPinID_P31_3	=	0x1f03u,									
	 MCU_mPinID_P31_4	=	0x1f04u,									
	 MCU_mPinID_P31_5	=	0x1f05u,									
	 MCU_mPinID_P31_6	=	0x1f06u,									
	 MCU_mPinID_P31_7	=	0x1f07u,									
	 MCU_mPinID_P31_8	=	0x1f08u,									
	 MCU_mPinID_P31_9	=	0x1f09u,									
	 MCU_mPinID_P31_10	=	0x1f0au,									
	 MCU_mPinID_P31_11	=	0x1f0bu,									
	 MCU_mPinID_P31_12	=	0x1f0cu,									
	 MCU_mPinID_P31_13	=	0x1f0du,									
	 MCU_mPinID_P31_14	=	0x1f0eu,									
	 MCU_mPinID_P31_15	=	0x1f0fu,									

	/*Pin ID define=====Port 32*/											
	 MCU_mPinID_P32_0	=	0x2000u,									
	 MCU_mPinID_P32_1	=	0x2001u,									
	 MCU_mPinID_P32_2	=	0x2002u,									
	 MCU_mPinID_P32_3	=	0x2003u,									
	 MCU_mPinID_P32_4	=	0x2004u,									
	 MCU_mPinID_P32_5	=	0x2005u,									
	 MCU_mPinID_P32_6	=	0x2006u,									
	 MCU_mPinID_P32_7	=	0x2007u,									
	 MCU_mPinID_P32_8	=	0x2008u,									
	 MCU_mPinID_P32_9	=	0x2009u,									
	 MCU_mPinID_P32_10	=	0x200au,									
	 MCU_mPinID_P32_11	=	0x200bu,									
	 MCU_mPinID_P32_12	=	0x200cu,									
	 MCU_mPinID_P32_13	=	0x200du,									
	 MCU_mPinID_P32_14	=	0x200eu,									
	 MCU_mPinID_P32_15	=	0x200fu,									

	/*Pin ID define=====Port 33*/											
	 MCU_mPinID_P33_0	=	0x2100u,									
	 MCU_mPinID_P33_1	=	0x2101u,									
	 MCU_mPinID_P33_2	=	0x2102u,									
	 MCU_mPinID_P33_3	=	0x2103u,									
	 MCU_mPinID_P33_4	=	0x2104u,									
	 MCU_mPinID_P33_5	=	0x2105u,									
	 MCU_mPinID_P33_6	=	0x2106u,									
	 MCU_mPinID_P33_7	=	0x2107u,									
	 MCU_mPinID_P33_8	=	0x2108u,									
	 MCU_mPinID_P33_9	=	0x2109u,									
	 MCU_mPinID_P33_10	=	0x210au,									
	 MCU_mPinID_P33_11	=	0x210bu,									
	 MCU_mPinID_P33_12	=	0x210cu,									
	 MCU_mPinID_P33_13	=	0x210du,									
	 MCU_mPinID_P33_14	=	0x210eu,									
	 MCU_mPinID_P33_15	=	0x210fu,									

	/*Pin ID define=====Port 34*/											
	 MCU_mPinID_P34_0	=	0x2200u,									
	 MCU_mPinID_P34_1	=	0x2201u,									
	 MCU_mPinID_P34_2	=	0x2202u,									
	 MCU_mPinID_P34_3	=	0x2203u,									
	 MCU_mPinID_P34_4	=	0x2204u,									
	 MCU_mPinID_P34_5	=	0x2205u,									
	 MCU_mPinID_P34_6	=	0x2206u,									
	 MCU_mPinID_P34_7	=	0x2207u,									
	 MCU_mPinID_P34_8	=	0x2208u,									
	 MCU_mPinID_P34_9	=	0x2209u,									
	 MCU_mPinID_P34_10	=	0x220au,									
	 MCU_mPinID_P34_11	=	0x220bu,									
	 MCU_mPinID_P34_12	=	0x220cu,									
	 MCU_mPinID_P34_13	=	0x220du,									
	 MCU_mPinID_P34_14	=	0x220eu,									
	 MCU_mPinID_P34_15	=	0x220fu,									

	/*Pin ID define=====Port 35*/											
	 MCU_mPinID_P35_0	=	0x2300u,									
	 MCU_mPinID_P35_1	=	0x2301u,									
	 MCU_mPinID_P35_2	=	0x2302u,									
	 MCU_mPinID_P35_3	=	0x2303u,									
	 MCU_mPinID_P35_4	=	0x2304u,									
	 MCU_mPinID_P35_5	=	0x2305u,									
	 MCU_mPinID_P35_6	=	0x2306u,									
	 MCU_mPinID_P35_7	=	0x2307u,									
	 MCU_mPinID_P35_8	=	0x2308u,									
	 MCU_mPinID_P35_9	=	0x2309u,									
	 MCU_mPinID_P35_10	=	0x230au,									
	 MCU_mPinID_P35_11	=	0x230bu,									
	 MCU_mPinID_P35_12	=	0x230cu,									
	 MCU_mPinID_P35_13	=	0x230du,									
	 MCU_mPinID_P35_14	=	0x230eu,									
	 MCU_mPinID_P35_15	=	0x230fu,									

	/*Pin ID define=====Port 36*/											
	 MCU_mPinID_P36_0	=	0x2400u,									
	 MCU_mPinID_P36_1	=	0x2401u,									
	 MCU_mPinID_P36_2	=	0x2402u,									
	 MCU_mPinID_P36_3	=	0x2403u,									
	 MCU_mPinID_P36_4	=	0x2404u,									
	 MCU_mPinID_P36_5	=	0x2405u,									
	 MCU_mPinID_P36_6	=	0x2406u,									
	 MCU_mPinID_P36_7	=	0x2407u,									
	 MCU_mPinID_P36_8	=	0x2408u,									
	 MCU_mPinID_P36_9	=	0x2409u,									
	 MCU_mPinID_P36_10	=	0x240au,									
	 MCU_mPinID_P36_11	=	0x240bu,									
	 MCU_mPinID_P36_12	=	0x240cu,									
	 MCU_mPinID_P36_13	=	0x240du,									
	 MCU_mPinID_P36_14	=	0x240eu,									
	 MCU_mPinID_P36_15	=	0x240fu,									

	/*Pin ID define=====Port 37*/											
	 MCU_mPinID_P37_0	=	0x2500u,									
	 MCU_mPinID_P37_1	=	0x2501u,									
	 MCU_mPinID_P37_2	=	0x2502u,									
	 MCU_mPinID_P37_3	=	0x2503u,									
	 MCU_mPinID_P37_4	=	0x2504u,									
	 MCU_mPinID_P37_5	=	0x2505u,									
	 MCU_mPinID_P37_6	=	0x2506u,									
	 MCU_mPinID_P37_7	=	0x2507u,									
	 MCU_mPinID_P37_8	=	0x2508u,									
	 MCU_mPinID_P37_9	=	0x2509u,									
	 MCU_mPinID_P37_10	=	0x250au,									
	 MCU_mPinID_P37_11	=	0x250bu,									
	 MCU_mPinID_P37_12	=	0x250cu,									
	 MCU_mPinID_P37_13	=	0x250du,									
	 MCU_mPinID_P37_14	=	0x250eu,									
	 MCU_mPinID_P37_15	=	0x250fu,									

	/*Pin ID define=====Port 38*/											
	 MCU_mPinID_P38_0	=	0x2600u,									
	 MCU_mPinID_P38_1	=	0x2601u,									
	 MCU_mPinID_P38_2	=	0x2602u,									
	 MCU_mPinID_P38_3	=	0x2603u,									
	 MCU_mPinID_P38_4	=	0x2604u,									
	 MCU_mPinID_P38_5	=	0x2605u,									
	 MCU_mPinID_P38_6	=	0x2606u,									
	 MCU_mPinID_P38_7	=	0x2607u,									
	 MCU_mPinID_P38_8	=	0x2608u,									
	 MCU_mPinID_P38_9	=	0x2609u,									
	 MCU_mPinID_P38_10	=	0x260au,									
	 MCU_mPinID_P38_11	=	0x260bu,									
	 MCU_mPinID_P38_12	=	0x260cu,									
	 MCU_mPinID_P38_13	=	0x260du,									
	 MCU_mPinID_P38_14	=	0x260eu,									
	 MCU_mPinID_P38_15	=	0x260fu,									

	/*Pin ID define=====Port 39*/											
	 MCU_mPinID_P39_0	=	0x2700u,									
	 MCU_mPinID_P39_1	=	0x2701u,									
	 MCU_mPinID_P39_2	=	0x2702u,									
	 MCU_mPinID_P39_3	=	0x2703u,									
	 MCU_mPinID_P39_4	=	0x2704u,									
	 MCU_mPinID_P39_5	=	0x2705u,									
	 MCU_mPinID_P39_6	=	0x2706u,									
	 MCU_mPinID_P39_7	=	0x2707u,									
	 MCU_mPinID_P39_8	=	0x2708u,									
	 MCU_mPinID_P39_9	=	0x2709u,									
	 MCU_mPinID_P39_10	=	0x270au,									
	 MCU_mPinID_P39_11	=	0x270bu,									
	 MCU_mPinID_P39_12	=	0x270cu,									
	 MCU_mPinID_P39_13	=	0x270du,									
	 MCU_mPinID_P39_14	=	0x270eu,									
	 MCU_mPinID_P39_15	=	0x270fu,									

	/*Pin ID define=====Port 40*/											
	 MCU_mPinID_P40_0	=	0x2800u,									
	 MCU_mPinID_P40_1	=	0x2801u,									
	 MCU_mPinID_P40_2	=	0x2802u,									
	 MCU_mPinID_P40_3	=	0x2803u,									
	 MCU_mPinID_P40_4	=	0x2804u,									
	 MCU_mPinID_P40_5	=	0x2805u,									
	 MCU_mPinID_P40_6	=	0x2806u,									
	 MCU_mPinID_P40_7	=	0x2807u,									
	 MCU_mPinID_P40_8	=	0x2808u,									
	 MCU_mPinID_P40_9	=	0x2809u,									
	 MCU_mPinID_P40_10	=	0x280au,									
	 MCU_mPinID_P40_11	=	0x280bu,									
	 MCU_mPinID_P40_12	=	0x280cu,									
	 MCU_mPinID_P40_13	=	0x280du,									
	 MCU_mPinID_P40_14	=	0x280eu,									
	 MCU_mPinID_P40_15	=	0x280fu,									

	/*Pin ID define=====Port 41*/											
	 MCU_mPinID_P41_0	=	0x2900u,									
	 MCU_mPinID_P41_1	=	0x2901u,									
	 MCU_mPinID_P41_2	=	0x2902u,									
	 MCU_mPinID_P41_3	=	0x2903u,									
	 MCU_mPinID_P41_4	=	0x2904u,									
	 MCU_mPinID_P41_5	=	0x2905u,									
	 MCU_mPinID_P41_6	=	0x2906u,									
	 MCU_mPinID_P41_7	=	0x2907u,									
	 MCU_mPinID_P41_8	=	0x2908u,									
	 MCU_mPinID_P41_9	=	0x2909u,									
	 MCU_mPinID_P41_10	=	0x290au,									
	 MCU_mPinID_P41_11	=	0x290bu,									
	 MCU_mPinID_P41_12	=	0x290cu,									
	 MCU_mPinID_P41_13	=	0x290du,									
	 MCU_mPinID_P41_14	=	0x290eu,									
	 MCU_mPinID_P41_15	=	0x290fu,									

	/*Pin ID define=====Port 42*/											
	 MCU_mPinID_P42_0	=	0x2a00u,									
	 MCU_mPinID_P42_1	=	0x2a01u,									
	 MCU_mPinID_P42_2	=	0x2a02u,									
	 MCU_mPinID_P42_3	=	0x2a03u,									
	 MCU_mPinID_P42_4	=	0x2a04u,									
	 MCU_mPinID_P42_5	=	0x2a05u,									
	 MCU_mPinID_P42_6	=	0x2a06u,									
	 MCU_mPinID_P42_7	=	0x2a07u,									
	 MCU_mPinID_P42_8	=	0x2a08u,									
	 MCU_mPinID_P42_9	=	0x2a09u,									
	 MCU_mPinID_P42_10	=	0x2a0au,									
	 MCU_mPinID_P42_11	=	0x2a0bu,									
	 MCU_mPinID_P42_12	=	0x2a0cu,									
	 MCU_mPinID_P42_13	=	0x2a0du,									
	 MCU_mPinID_P42_14	=	0x2a0eu,									
	 MCU_mPinID_P42_15	=	0x2a0fu,									

	/*Pin ID define=====Port 43*/											
	 MCU_mPinID_P43_0	=	0x2b00u,									
	 MCU_mPinID_P43_1	=	0x2b01u,									
	 MCU_mPinID_P43_2	=	0x2b02u,									
	 MCU_mPinID_P43_3	=	0x2b03u,									
	 MCU_mPinID_P43_4	=	0x2b04u,									
	 MCU_mPinID_P43_5	=	0x2b05u,									
	 MCU_mPinID_P43_6	=	0x2b06u,									
	 MCU_mPinID_P43_7	=	0x2b07u,									
	 MCU_mPinID_P43_8	=	0x2b08u,									
	 MCU_mPinID_P43_9	=	0x2b09u,									
	 MCU_mPinID_P43_10	=	0x2b0au,									
	 MCU_mPinID_P43_11	=	0x2b0bu,									
	 MCU_mPinID_P43_12	=	0x2b0cu,									
	 MCU_mPinID_P43_13	=	0x2b0du,									
	 MCU_mPinID_P43_14	=	0x2b0eu,									
	 MCU_mPinID_P43_15	=	0x2b0fu,									

	/*Pin ID define=====Port 44*/											
	 MCU_mPinID_P44_0	=	0x2c00u,									
	 MCU_mPinID_P44_1	=	0x2c01u,									
	 MCU_mPinID_P44_2	=	0x2c02u,									
	 MCU_mPinID_P44_3	=	0x2c03u,									
	 MCU_mPinID_P44_4	=	0x2c04u,									
	 MCU_mPinID_P44_5	=	0x2c05u,									
	 MCU_mPinID_P44_6	=	0x2c06u,									
	 MCU_mPinID_P44_7	=	0x2c07u,									
	 MCU_mPinID_P44_8	=	0x2c08u,									
	 MCU_mPinID_P44_9	=	0x2c09u,									
	 MCU_mPinID_P44_10	=	0x2c0au,									
	 MCU_mPinID_P44_11	=	0x2c0bu,									
	 MCU_mPinID_P44_12	=	0x2c0cu,									
	 MCU_mPinID_P44_13	=	0x2c0du,									
	 MCU_mPinID_P44_14	=	0x2c0eu,									
	 MCU_mPinID_P44_15	=	0x2c0fu,									

	/*Pin ID define=====Port 45*/										
	 MCU_mPinID_P45_0	=	0x2d00u,									
	 MCU_mPinID_P45_1	=	0x2d01u,									
	 MCU_mPinID_P45_2	=	0x2d02u,									
	 MCU_mPinID_P45_3	=	0x2d03u,									
	 MCU_mPinID_P45_4	=	0x2d04u,									
	 MCU_mPinID_P45_5	=	0x2d05u,									
	 MCU_mPinID_P45_6	=	0x2d06u,									
	 MCU_mPinID_P45_7	=	0x2d07u,									
	 MCU_mPinID_P45_8	=	0x2d08u,									
	 MCU_mPinID_P45_9	=	0x2d09u,									
	 MCU_mPinID_P45_10	=	0x2d0au,									
	 MCU_mPinID_P45_11	=	0x2d0bu,									
	 MCU_mPinID_P45_12	=	0x2d0cu,									
	 MCU_mPinID_P45_13	=	0x2d0du,									
	 MCU_mPinID_P45_14	=	0x2d0eu,									
	 MCU_mPinID_P45_15	=	0x2d0fu,									

	/*Pin ID define=====Port 46*/											
	 MCU_mPinID_P46_0	=	0x2e00u,									
	 MCU_mPinID_P46_1	=	0x2e01u,									
	 MCU_mPinID_P46_2	=	0x2e02u,									
	 MCU_mPinID_P46_3	=	0x2e03u,									
	 MCU_mPinID_P46_4	=	0x2e04u,									
	 MCU_mPinID_P46_5	=	0x2e05u,									
	 MCU_mPinID_P46_6	=	0x2e06u,									
	 MCU_mPinID_P46_7	=	0x2e07u,									
	 MCU_mPinID_P46_8	=	0x2e08u,									
	 MCU_mPinID_P46_9	=	0x2e09u,									
	 MCU_mPinID_P46_10	=	0x2e0au,									
	 MCU_mPinID_P46_11	=	0x2e0bu,									
	 MCU_mPinID_P46_12	=	0x2e0cu,									
	 MCU_mPinID_P46_13	=	0x2e0du,									
	 MCU_mPinID_P46_14	=	0x2e0eu,									
	 MCU_mPinID_P46_15	=	0x2e0fu,									

/*******************************
Pin ID define=====JPort 0 
-----------------------------
	********************************/
	 MCU_mPinID_JP0_0	=	(0x0000u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_1	=	(0x0001u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_2	=	(0x0002u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_3	=	(0x0003u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_4	=	(0x0004u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_5	=	(0x0005u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_6	=	(0x0006u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_7	=	(0x0007u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_8	=	(0x0008u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_9	=	(0x0009u|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_10	=	(0x000au|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_11	=	(0x000bu|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_12	=	(0x000cu|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_13	=	(0x000du|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_14	=	(0x000eu|MCU_mPinTypetMask_JPort),
	 MCU_mPinID_JP0_15	=	(0x000fu|MCU_mPinTypetMask_JPort),

}MUC_enPinID;												

/*###########################################################
		vector list in this serial MCU
###########################################################*/

typedef enum 
{	   
	ISR_0_INTWDTA0 =   0u,
	ISR_1_INTWDTA1 =   1u,
	ISR_2_INTRTCA01S   =   2u,
	ISR_3_INTRTCA0AL   =   3u,
	ISR_4_INTRTCA0R    =   4u,
	ISR_5_INTAWOT0 =   5u,
	ISR_6_INTP0    =   6u,
	ISR_7_INTP1    =   7u,
	ISR_8_INTP2    =   8u,
	ISR_9_INTP3    =   9u,
	ISR_10_INTP4   =   10u,
	ISR_11_INTP5   =   11u,
	ISR_12_INTP6   =   12u,
	ISR_13_INTP7   =   13u,
	ISR_14_INTP8   =   14u,
	ISR_15_INTP9   =   15u,
	ISR_16_INTP10  =   16u,
	ISR_17_INTTAUB0I0  =   17u,
	ISR_18_INTTAUB0I1  =   18u,
	ISR_19_INTTAUB0I2  =   19u,
	ISR_20_INTTAUB0I3  =   20u,
	ISR_21_INTTAUB0I4  =   21u,
	ISR_22_INTTAUB0I5  =   22u,
	ISR_23_INTTAUB0I6  =   23u,
	ISR_24_INTTAUB0I7  =   24u,
	ISR_25_INTTAUB0I8  =   25u,
	ISR_26_INTTAUB0I9  =   26u,
	ISR_27_INTTAUB0I10 =   27u,
	ISR_28_INTTAUB0I11 =   28u,
	ISR_29_INTTAUB0I12 =   29u,
	ISR_30_INTTAUB0I13 =   30u,
	ISR_31_INTTAUB0I14 =   31u,
	ISR_32_INTTAUB0I15 =   32u,
	ISR_33_INTTAUB1I0  =   33u,
	ISR_34_INTTAUB1I1  =   34u,
	ISR_35_INTTAUB1I2  =   35u,
	ISR_36_INTTAUB1I3  =   36u,
	ISR_37_INTTAUB1I4  =   37u,
	ISR_38_INTTAUB1I5  =   38u,
	ISR_39_INTTAUB1I6  =   39u,
	ISR_40_INTTAUB1I7  =   40u,
	ISR_41_INTTAUB1I8  =   41u,
	ISR_42_INTTAUB1I9  =   42u,
	ISR_43_INTTAUB1I10 =   43u,
	ISR_44_INTTAUB1I11 =   44u,
	ISR_45_INTTAUB1I12 =   45u,
	ISR_46_INTTAUB1I13 =   46u,
	ISR_47_INTTAUB1I14 =   47u,
	ISR_48_INTTAUB1I15 =   48u,
	ISR_49_INTTAUB2I0  =   49u,
	ISR_50_INTTAUB2I1  =   50u,
	ISR_51_INTTAUB2I2  =   51u,
	ISR_52_INTTAUB2I3  =   52u,
	ISR_53_INTTAUB2I4  =   53u,
	ISR_54_INTTAUB2I5  =   54u,
	ISR_55_INTTAUB2I6  =   55u,
	ISR_56_INTTAUB2I7  =   56u,
	ISR_57_INTTAUB2I8  =   57u,
	ISR_58_INTTAUB2I9  =   58u,
	ISR_59_INTTAUB2I10 =   59u,
	ISR_60_INTTAUB2I11 =   60u,
	ISR_61_INTTAUB2I12 =   61u,
	ISR_62_INTTAUB2I13 =   62u,
	ISR_63_INTTAUB2I14 =   63u,
	ISR_64_INTTAUB2I15 =   64u,
	ISR_65_INTADCE0TSN =   65u,
	ISR_66_INTADCE0I1  =   66u,
	ISR_67_INTADCE0I2  =   67u,
	ISR_68_INTADCE0I3  =   68u,
	ISR_69_INTRCANGERR =   69u,
	ISR_70_INTRCANGRECC    =   70u,
	ISR_71_INTRCAN0ERR =   71u,
	ISR_72_INTRCAN0REC =   72u,
	ISR_73_INTRCAN0TRX =   73u,
	ISR_74_INTCSIGT0IRE    =   74u,
	ISR_75_INTCSIG0IR  =   75u,
	ISR_76_INTCSIG0IC  =   76u,
	ISR_77_INTCSIH0IRE =   77u,
	ISR_78_INTCSIH0IR  =   78u,
	ISR_79_INTCSIH0IC  =   79u,
	ISR_80_INTCSIH0IJC =   80u,
	ISR_81_INTRLIN30UR2    =   81u,
	ISR_82_INTRLIN30UR1    =   82u,
	ISR_83_INTRLIN30UR0    =   83u,
	ISR_84_INTRLIN31UR2    =   84u,
	ISR_85_INTRLIN31UR1    =   85u,
	ISR_86_INTRLIN31UR0    =   86u,
	ISR_87_INTSG0TI    =   87u,
	ISR_88_INTSG1TI    =   88u,
	ISR_89_INTSG2TI    =   89u,
	ISR_90_INTSG3TI    =   90u,
	ISR_91_INTSG4TI    =   91u,
	ISR_92_INTDCUTDI   =   92u,
	ISR_93_INTDMAERR   =   93u,
	ISR_94_INTDMA0 =   94u,
	ISR_95_INTDMA1 =   95u,
	ISR_96_INTDMA2 =   96u,
	ISR_97_INTDMA3 =   97u,
	ISR_98_INTDMA4 =   98u,
	ISR_99_INTDMA5 =   99u,
	ISR_100_INTDMA6    =   100u,
	ISR_101_INTDMA7    =   101u,
	ISR_102_INTDMA8    =   102u,
	ISR_103_INTDMA9    =   103u,
	ISR_104_INTDMA10   =   104u,
	ISR_105_INTDMA11   =   105u,
	ISR_106_INTDMA12   =   106u,
	ISR_107_INTDMA13   =   107u,
	ISR_108_INTDMA14   =   108u,
	ISR_109_INTDMA15   =   109u,
	ISR_110_INTRIIC0LEE    =   110u,
	ISR_111_INTRIIC0RI =   111u,
	ISR_112_INTRIIC0TI =   112u,
	ISR_113_INTRIIC0TEI    =   113u,
	ISR_114_INTRIIC1LEE    =   114u,
	ISR_115_INTRIIC1RI =   115u,
	ISR_116_INTRIIC1TI =   116u,
	ISR_117_INTRIIC1TEI    =   117u,
	ISR_118_INTRCAN1ERR    =   118u,
	ISR_119_INTRCAN1REC    =   119u,
	ISR_120_INTRCAN1TRX    =   120u,
	ISR_121_INTTAUJ0I0 =   121u,
	ISR_122_INTTAUJ0I1 =   122u,
	ISR_123_INTTAUJ0I2 =   123u,
	ISR_124_INTTAUJ0I3 =   124u,
	ISR_125_INTOSTM0   =   125u,
	ISR_126_INTOSTM1   =   126u,
	ISR_127_INTCSIGT1IRE   =   127u,
	ISR_128_INTCSIG1IR =   128u,
	ISR_129_INTCSIG1IC =   129u,
	ISR_130_INTCSIGT2IRE   =   130u,
	ISR_131_INTCSIG2IR =   131u,
	ISR_132_INTCSIG2IC =   132u,
	ISR_133_INTCSIGT3IRE   =   133u,
	ISR_134_INTCSIG3IR =   134u,
	ISR_135_INTCSIG3IC =   135u,
	ISR_136_INTCSIH1IRE    =   136u,
	ISR_137_INTCSIH1IR =   137u,
	ISR_138_INTCSIH1IC =   138u,
	ISR_139_INTCSIH1IJC    =   139u,
	ISR_140_INTQFULL   =   140u,
	ISR_141_INTPWGA0   =   141u,
	ISR_142_INTPWGA1   =   142u,
	ISR_143_INTPWGA2   =   143u,
	ISR_144_INTPWGA3   =   144u,
	ISR_145_INTPWGA4   =   145u,
	ISR_146_INTPWGA5   =   146u,
	ISR_147_INTPWGA6   =   147u,
	ISR_148_INTPWGA7   =   148u,
	ISR_149_INTPWGA8   =   149u,
	ISR_150_INTPWGA9   =   150u,
	ISR_151_INTPWGA10  =   151u,
	ISR_152_INTPWGA11  =   152u,
	ISR_153_INTPWGA12  =   153u,
	ISR_154_INTPWGA13  =   154u,
	ISR_155_INTPWGA14  =   155u,
	ISR_156_INTPWGA15  =   156u,
	ISR_157_INTPWGA16  =   157u,
	ISR_158_INTPWGA17  =   158u,
	ISR_159_INTPWGA18  =   159u,
	ISR_160_INTPWGA19  =   160u,
	ISR_161_INTPWGA20  =   161u,
	ISR_162_INTPWGA21  =   162u,
	ISR_163_INTPWGA22  =   163u,
	ISR_164_INTPWGA23  =   164u,
	ISR_165_INTICUSTWRDY   =   165u,
	ISR_166_INTICUSTRRDY   =   166u,
	ISR_167_Reserved   =   167u,
	ISR_168_Reserved   =   168u,
	ISR_169_Reserved   =   169u,
	ISR_170_Reserved   =   170u,
	ISR_171_Reserved   =   171u,
	ISR_172_INTFLENDNM =   172u,
	ISR_173_Reserved   =   173u,
	ISR_174_INTLCBI0RDY    =   174u,
	ISR_175_INTLCBI0EMPTY  =   175u,
	ISR_176_INTLCBI0HALF   =   176u,
	ISR_177_INTLCBI0FULL   =   177u,
	ISR_178_INTLCBI0QTR    =   178u,
	ISR_179_INTLCBI03QTR   =   179u,
	ISR_180_INTRCAN2ERR    =   180u,
	ISR_181_INTRCAN2REC    =   181u,
	ISR_182_INTRCAN2TRX    =   182u,
	ISR_183_INTPCMP0FFIL   =   183u,
	ISR_184_INTPCMP0FERR   =   184u,
	ISR_185_INTISM0REACHED =   185u,
	ISR_186_INTISM0DONE    =   186u,
	ISR_187_INTISM0ZPDAD   =   187u,
	ISR_188_Reserved   =   188u,
	ISR_189_INTSSIF0   =   189u,
	ISR_190_INTSSIF0RX =   190u,
	ISR_191_INTSSIF0TX =   191u,
	ISR_192_INTSSIF1   =   192u,
	ISR_193_INTSSIF1RX =   193u,
	ISR_194_INTSSIF1TX =   194u,
	ISR_195_Reserved   =   195u,
	ISR_196_Reserved   =   196u,
	ISR_197_Reserved   =   197u,
	ISR_198_Reserved   =   198u,
	ISR_199_Reserved   =   199u,
	ISR_200_Reserved   =   200u,
	ISR_201_Reserved   =   201u,
	ISR_202_Reserved   =   202u,
	ISR_203_Reserved   =   203u,
	ISR_204_Reserved   =   204u,
	ISR_205_Reserved   =   205u,
	ISR_206_Reserved   =   206u,
	ISR_207_Reserved   =   207u,
	ISR_208_Reserved   =   208u,
	ISR_209_Reserved   =   209u,
	ISR_210_Reserved   =   210u,
	ISR_211_Reserved   =   211u,
	ISR_212_Reserved   =   212u,
	ISR_213_Reserved   =   213u,
	ISR_214_Reserved   =   214u,
	ISR_215_INTRLIN32UR2   =   215u,
	ISR_216_INTRLIN32UR1   =   216u,
	ISR_217_INTRLIN32UR0   =   217u,
	ISR_218_INTRLIN33UR2   =   218u,
	ISR_219_INTRLIN33UR1   =   219u,
	ISR_220_INTRLIN33UR0   =   220u,
	ISR_221_Reserved   =   221u,
	ISR_222_Reserved   =   222u,
	ISR_223_Reserved   =   223u,
	ISR_224_Reserved   =   224u,
	ISR_225_Reserved   =   225u,
	ISR_226_Reserved   =   226u,
	ISR_227_Reserved   =   227u,
	ISR_228_Reserved   =   228u,
	ISR_229_Reserved   =   229u,
	ISR_230_Reserved   =   230u,
	ISR_231_Reserved   =   231u,
	ISR_232_Reserved   =   232u,
	ISR_233_Reserved   =   233u,
	ISR_234_Reserved   =   234u,
	ISR_235_Reserved   =   235u,
	ISR_236_Reserved   =   236u,
	ISR_237_Reserved   =   237u,
	ISR_238_Reserved   =   238u,
	ISR_239_Reserved   =   239u,
	ISR_240_Reserved   =   240u,
	ISR_241_Reserved   =   241u,
	ISR_242_Reserved   =   242u,
	ISR_243_Reserved   =   243u,
	ISR_244_Reserved   =   244u,
	ISR_245_Reserved   =   245u,
	ISR_246_Reserved   =   246u,
	ISR_247_Reserved   =   247u,
	ISR_248_INTMISRERR =   248u,
	ISR_249_INTVPISG1OVFERR    =   249u,
	ISR_250_INTVPISG2OVFERR    =   250u,
	ISR_251_INTVPISG3OVFERR    =   251u,
	ISR_252_Reserved   =   252u,
	ISR_253_INTVPISG5OVFERR    =   253u,
	ISR_254_Reserved   =   254u,
	ISR_255_INTINTERNALBUSERR  =   255u,
}MCU_enIsrID;

/***********************************************
	PWGA ID marco list
***********************************************/
typedef enum 
{
	MCU_mPWGA0 =   0u,
	MCU_mPWGA1 =   1u,
	MCU_mPWGA2 =   2u,
	MCU_mPWGA3 =   3u,
	MCU_mPWGA4 =   4u,
	MCU_mPWGA5 =   5u,
	MCU_mPWGA6 =   6u,
	MCU_mPWGA7 =   7u,
	MCU_mPWGA8 =   8u,
	MCU_mPWGA9 =   9u,
	MCU_mPWGA10    =   10u,
	MCU_mPWGA11    =   11u,
	MCU_mPWGA12    =   12u,
	MCU_mPWGA13    =   13u,
	MCU_mPWGA14    =   14u,
	MCU_mPWGA15    =   15u,
	MCU_mPWGA16    =   16u,
	MCU_mPWGA17    =   17u,
	MCU_mPWGA18    =   18u,
	MCU_mPWGA19    =   19u,
	MCU_mPWGA20    =   20u,
	MCU_mPWGA21    =   21u,
	MCU_mPWGA22    =   22u,
	MCU_mPWGA23    =   23u,
}MCU_enPwgaID;


/********************************************************

	TUAx timer unit

********************************************************/
typedef enum 
{
	MCU_mTAUB0_0   =   0u,
	MCU_mTAUB0_1   =   1u,
	MCU_mTAUB0_2   =   2u,
	MCU_mTAUB0_3   =   3u,
	MCU_mTAUB0_4   =   4u,
	MCU_mTAUB0_5   =   5u,
	MCU_mTAUB0_6   =   6u,
	MCU_mTAUB0_7   =   7u,
	MCU_mTAUB0_8   =   8u,
	MCU_mTAUB0_9   =   9u,
	MCU_mTAUB0_10  =   10u,
	MCU_mTAUB0_11  =   11u,
	MCU_mTAUB0_12  =   12u,
	MCU_mTAUB0_13  =   13u,
	MCU_mTAUB0_14  =   14u,
	MCU_mTAUB0_15  =   15u,
		   
	MCU_mTAUB1_0   =   16u,
	MCU_mTAUB1_1   =   17u,
	MCU_mTAUB1_2   =   18u,
	MCU_mTAUB1_3   =   19u,
	MCU_mTAUB1_4   =   20u,
	MCU_mTAUB1_5   =   21u,
	MCU_mTAUB1_6   =   22u,
	MCU_mTAUB1_7   =   23u,
	MCU_mTAUB1_8   =   24u,
	MCU_mTAUB1_9   =   25u,
	MCU_mTAUB1_10  =   26u,
	MCU_mTAUB1_11  =   27u,
	MCU_mTAUB1_12  =   28u,
	MCU_mTAUB1_13  =   29u,
	MCU_mTAUB1_14  =   30u,
	MCU_mTAUB1_15  =   31u,
		   
	MCU_mTAUB2_0   =   32u,
	MCU_mTAUB2_1   =   33u,
	MCU_mTAUB2_2   =   34u,
	MCU_mTAUB2_3   =   35u,
	MCU_mTAUB2_4   =   36u,
	MCU_mTAUB2_5   =   37u,
	MCU_mTAUB2_6   =   38u,
	MCU_mTAUB2_7   =   39u,
	MCU_mTAUB2_8   =   40u,
	MCU_mTAUB2_9   =   41u,
	MCU_mTAUB2_10  =   42u,
	MCU_mTAUB2_11  =   43u,
	MCU_mTAUB2_12  =   44u,
	MCU_mTAUB2_13  =   45u,
	MCU_mTAUB2_14  =   46u,
	MCU_mTAUB2_15  =   47u,
		   
	MCU_mTAUJ0_0   =   48u,
	MCU_mTAUJ0_1   =   49u,
	MCU_mTAUJ0_2   =   50u,
	MCU_mTAUJ0_3   =   51u,
}MCU_enTauxID;

typedef enum 
{
    MCU_enTAUxAltFun_Timer=0,
    MCU_enTAUxAltFun_PinTriggerTimer=1,
    MCU_enTAUxAltFun_FrequencyDivider=2,
    MCU_enTAUxAltFun_Counter=3,
    MCU_enTAUxAltFun_PinTrigAndDelayOnePulse=4,
    MCU_enTAUxAltFun_PulseInterval=5,
    MCU_enTAUxAltFun_PulseWidth=6,
    MCU_enTAUxAltFun_PulsePosition=7,
    MCU_enTAUxAltFun_PulseWidthCumulater=8,
    MCU_enTAUxAltFun_PulseIntervalJudg=9,
    MCU_enTAUxAltFun_PulseWidthJudg=10,
    MCU_enTAUxAltFun_PulseWidthOVcheck=11,
    MCU_enTAUxAltFun_PulseWidthCumulaterOVcheck=12,
    MCU_enTAUxAltFun_PulseDetectDelayMaster=13,
    MCU_enTAUxAltFun_PulseDetectDelaySlave=14,
    MCU_enTAUxAltFun_PpgMaster=15,
    MCU_enTAUxAltFun_PpgSlave=16,
    MCU_enTAUxAltFun_Max=17,
    
}MCU_enTAUxAltFunID;

typedef enum 
{
    MCU_enTAUxTrigger_FaillingEdge=0,
    MCU_enTAUxTrigger_RisingEdge,
    MCU_enTAUxTrigger_LowLevel,
    MCU_enTAUxTrigger_HighLevel,
    
}MCU_enTAUxTriggerID;

typedef enum 
{
	MCU_mTAUx_Stop   =   0u,								   
	MCU_mTAUx_Run   =   1u,								   
}MCU_enTauxRunCtrl;

/********************************************************

	EINT unit

********************************************************/
typedef enum 
{
	MCU_mEINT_ID_NMI   =   0u,
	MCU_mEINT_ID_INT0  =   1u,
	MCU_mEINT_ID_INT1  =   2u,
	MCU_mEINT_ID_INT2  =   3u,
	MCU_mEINT_ID_INT3  =   4u,
	MCU_mEINT_ID_INT4  =   5u,
	MCU_mEINT_ID_INT5  =   6u,
	MCU_mEINT_ID_INT6  =   7u,
	MCU_mEINT_ID_INT7  =   8u,
	MCU_mEINT_ID_INT8  =   9u,
	MCU_mEINT_ID_INT9  =   10u,
	MCU_mEINT_ID_INT10 =   11u,
}MCU_enEintID;

typedef enum 
{
    MCU_enEintTrigger_Disable=0,
    MCU_enEintTrigger_RisingEdge,
    MCU_enEintTrigger_FaillingEdge,
    MCU_enEintTrigger_BothEdge,
    MCU_enEintTrigger_LowLevel,
    MCU_enEintTrigger_HighLevel,
    
}MCU_enEintTriggerID;

/********************************************************

	RIIC unit

********************************************************/
typedef enum 
{
	MCU_mRIIC_0	 =	0u,
	MCU_mRIIC_1	 =	1u,
}MCU_enRiicID;

typedef enum 
{
	MCU_enRIIC_Ready	 =	0u,
	MCU_enRIIC_Reading	 =	1u,
	MCU_enRIIC_Writting	 =	2u,
	
}MCU_enRiicStatus;

/********************************************************

	OSTM unit

********************************************************/
typedef enum 
{
	MCU_mOSTM_0	 =	0u,
	MCU_mOSTM_1	 =	1u,
}MCU_enOstmID;




/********************************************************

	ADCA unit

********************************************************/
#define MCU_mADC_MaxChPerUnit	20
typedef enum 
{
	MCU_mADCID_ADCA0I0 =   0u,
	MCU_mADCID_ADCA0I1 =   1u,
	MCU_mADCID_ADCA0I2 =   2u,
	MCU_mADCID_ADCA0I3 =   3u,
	MCU_mADCID_ADCA0I4 =   4u,
	MCU_mADCID_ADCA0I5 =   5u,
	MCU_mADCID_ADCA0I6 =   6u,
	MCU_mADCID_ADCA0I7 =   7u,
	MCU_mADCID_ADCA0I8 =   8u,
	MCU_mADCID_ADCA0I9 =   9u,
	MCU_mADCID_ADCA0I10    =   10u,
	MCU_mADCID_ADCA0I11    =   11u,
	MCU_mADCID_ADCA0I12    =   12u,
	MCU_mADCID_ADCA0I13    =   13u,
	MCU_mADCID_ADCA0I14    =   14u,
	MCU_mADCID_ADCA0I15    =   15u,
	MCU_mADCID_ADCA0I16    =   16u,
	MCU_mADCID_ADCA0I17    =   17u,
	MCU_mADCID_ADCA0I18    =   18u,
	MCU_mADCID_ADCA0I19    =   19u,
	MCU_mADCID_ADCA0I20_ISOVDD =   20u/*Analog input channel 20===> Isolated-Area power supply ISOVDD*/,
	MCU_mADCID_ADCA0_PWGADiag	=	22u,/*if using the PWGA diag, it need to set the VIR for special channel via PWSAnPVCRx_y*/
	MCU_mADCID_ADCA0_CPUtemperature    =  37u/* Analog input channel 37===> Temperatur Sensor output*/,
}MCU_enAdcaID;


/********************************************************

	DMA unit

********************************************************/
typedef enum
{
	MCU_mDMA_0	= 0,
	MCU_mDMA_1	= 1,
	MCU_mDMA_2	= 2,
	MCU_mDMA_3	= 3,
	MCU_mDMA_4	= 4,
	MCU_mDMA_5	= 5,
	MCU_mDMA_6	= 6,
	MCU_mDMA_7	= 7,
	MCU_mDMA_8	= 8,
	MCU_mDMA_9	= 9,
	MCU_mDMA_10 = 10,
	MCU_mDMA_11 = 11,
	MCU_mDMA_12 = 12,
	MCU_mDMA_13 = 13,
	MCU_mDMA_14 = 14,
	MCU_mDMA_15 = 15,
}MCU_enDmaID;

typedef enum
{
	MCU_mDMAtrig_INTP0=0u,
	MCU_mDMAtrig_INTP1=1u,
	MCU_mDMAtrig_INTP2=2u,
	MCU_mDMAtrig_INTP3=3u,
	MCU_mDMAtrig_INTP4=4u,
	MCU_mDMAtrig_INTP5=5u,
	MCU_mDMAtrig_INTP6=6u,
	MCU_mDMAtrig_INTP7=7u,
	MCU_mDMAtrig_INTP8=8u,
	MCU_mDMAtrig_INTP9=9u,
	MCU_mDMAtrig_INTP10=10u,
	MCU_mDMAtrig_Reserved=11u,
	MCU_mDMAtrig_INTLCBI0RDY=12u,
	MCU_mDMAtrig_INTLCBI0EMPTY=13u,
	MCU_mDMAtrig_INTLCBI0HALF=14u,
	MCU_mDMAtrig_INTLCBI0FULL=15u,
	MCU_mDMAtrig_INTLCBI0QTR=16u,
	MCU_mDMAtrig_INTLCBI03QTR=17u,
	MCU_mDMAtrig_INTPWGA0=18u,
	MCU_mDMAtrig_INTPWGA1=19u,
	MCU_mDMAtrig_INTPWGA2=20u,
	MCU_mDMAtrig_INTPWGA3=21u,
	MCU_mDMAtrig_INTPWGA4=22u,
	MCU_mDMAtrig_INTPWGA5=23u,
	MCU_mDMAtrig_INTPWGA6=24u,
	MCU_mDMAtrig_INTPWGA7=25u,
	MCU_mDMAtrig_INTPWGA8=26u,
	MCU_mDMAtrig_INTPWGA9=27u,
	MCU_mDMAtrig_INTPWGA10=28u,
	MCU_mDMAtrig_INTPWGA11=29u,
	MCU_mDMAtrig_INTPWGA12=30u,
	MCU_mDMAtrig_INTPWGA13=31u,
	MCU_mDMAtrig_INTPWGA14=32u,
	MCU_mDMAtrig_INTPWGA15=33u,
	MCU_mDMAtrig_INTPWGA16=34u,
	MCU_mDMAtrig_INTTAUB0I0=35u,
	MCU_mDMAtrig_INTTAUB0I1=36u,
	MCU_mDMAtrig_INTTAUB0I2=37u,
	MCU_mDMAtrig_INTTAUB0I3=38u,
	MCU_mDMAtrig_INTTAUB0I4=39u,
	MCU_mDMAtrig_INTTAUB0I5=40u,
	MCU_mDMAtrig_INTTAUB0I6=41u,
	MCU_mDMAtrig_INTTAUB0I7=42u,
	MCU_mDMAtrig_INTTAUB0I8=43u,
	MCU_mDMAtrig_INTTAUB0I9=44u,
	MCU_mDMAtrig_INTTAUB0I10=45u,
	MCU_mDMAtrig_INTTAUB0I11=46u,
	MCU_mDMAtrig_INTTAUB0I12=47u,
	MCU_mDMAtrig_INTTAUB0I13=48u,
	MCU_mDMAtrig_INTTAUB0I14=49u,
	MCU_mDMAtrig_INTTAUB0I15=50u,
	MCU_mDMAtrig_INTTAUB1I0=51u,
	MCU_mDMAtrig_INTTAUB1I1=52u,
	MCU_mDMAtrig_INTTAUB1I2=53u,
	MCU_mDMAtrig_INTTAUB1I3=54u,
	MCU_mDMAtrig_INTTAUB1I4=55u,
	MCU_mDMAtrig_INTTAUB1I5=56u,
	MCU_mDMAtrig_INTTAUB1I6=57u,
	MCU_mDMAtrig_INTTAUB1I7=58u,
	MCU_mDMAtrig_INTTAUB1I8=59u,
	MCU_mDMAtrig_INTTAUB1I9=60u,
	MCU_mDMAtrig_INTTAUB1I10=61u,
	MCU_mDMAtrig_INTTAUB1I11=62u,
	MCU_mDMAtrig_INTTAUB1I12=63u,
	MCU_mDMAtrig_INTTAUB1I13=64u,
	MCU_mDMAtrig_INTTAUB1I14=65u,
	MCU_mDMAtrig_INTTAUB1I15=66u,
	MCU_mDMAtrig_INTTAUB2I0=67u,
	MCU_mDMAtrig_INTTAUB2I1=68u,
	MCU_mDMAtrig_INTTAUB2I2=69u,
	MCU_mDMAtrig_INTTAUB2I3=70u,
	MCU_mDMAtrig_INTTAUB2I4=71u,
	MCU_mDMAtrig_INTTAUB2I5=72u,
	MCU_mDMAtrig_INTTAUB2I6=73u,
	MCU_mDMAtrig_INTTAUB2I7=74u,
	MCU_mDMAtrig_INTTAUB2I8=75u,
	MCU_mDMAtrig_INTTAUB2I9=76u,
	MCU_mDMAtrig_INTTAUB2I10=77u,
	MCU_mDMAtrig_INTTAUB2I11=78u,
	MCU_mDMAtrig_INTTAUB2I12=79u,
	MCU_mDMAtrig_INTTAUB2I13=80u,
	MCU_mDMAtrig_INTTAUB2I14=81u,
	MCU_mDMAtrig_INTTAUB2I15=82u,
	MCU_mDMAtrig_INTTAUJ0I0=83u,
	MCU_mDMAtrig_INTTAUJ0I1=84u,
	MCU_mDMAtrig_INTTAUJ0I2=85u,
	MCU_mDMAtrig_INTTAUJ0I3=86u,
	MCU_mDMAtrig_INTRLIN30UR0=87u,
	MCU_mDMAtrig_INTRLIN30UR1=88u,
	MCU_mDMAtrig_INTRLIN31UR0=89u,
	MCU_mDMAtrig_INTRLIN31UR1=90u,
	MCU_mDMAtrig_INTRLIN32UR0=91u,
	MCU_mDMAtrig_INTRLIN32UR1=92u,
	MCU_mDMAtrig_INTRLIN33UR0=93u,
	MCU_mDMAtrig_INTRLIN33UR1=94u,
	MCU_mDMAtrig_INTCSIG0IC=95u,
	MCU_mDMAtrig_INTCSIG0IR=96u,
	MCU_mDMAtrig_INTCSIG1IC=97u,
	MCU_mDMAtrig_INTCSIG1IR=98u,
	MCU_mDMAtrig_INTCSIG2IC=99u,
	MCU_mDMAtrig_INTCSIG2IR=100u,
	MCU_mDMAtrig_INTCSIG3IC=101u,
	MCU_mDMAtrig_INTCSIG3IR=102u,
	MCU_mDMAtrig_INTCSIH0IC=103u,
	MCU_mDMAtrig_INTCSIH0IR=104u,
	MCU_mDMAtrig_INTCSIH0IJC=105u,
	MCU_mDMAtrig_INTCSIH1IC=106u,
	MCU_mDMAtrig_INTCSIH1IR=107u,
	MCU_mDMAtrig_INTCSIH1IJC=108u,
	MCU_mDMAtrig_INTRIIC0TI=109u,
	MCU_mDMAtrig_INTRIIC0RI=110u,
	MCU_mDMAtrig_INTRIIC1TI=111u,
	MCU_mDMAtrig_INTRIIC1RI=112u,
	MCU_mDMAtrig_INTSSIF0TX=113u,
	MCU_mDMAtrig_INTSSIF0RX=114u,
	MCU_mDMAtrig_INTSSIF1TX=115u,
	MCU_mDMAtrig_INTSSIF1RX=116u,
	MCU_mDMAtrig_INTPCMP0FFIL=117u,
	MCU_mDMAtrig_INTSG0TI=118u,
	MCU_mDMAtrig_INTSG1TI=119u,
	MCU_mDMAtrig_INTSG2TI=120u,
	MCU_mDMAtrig_INTSG3TI=121u,
	MCU_mDMAtrig_INTSG4TI=122u,
	MCU_mDMAtrig_INTADCE0I1=123u,
	MCU_mDMAtrig_INTADCE0I2=124u,
	MCU_mDMAtrig_INTADCE0I3=125u,
	MCU_mDMAtrig_DMA_WR_REQ=126u,
	MCU_mDMAtrig_DMA_RD_REQ=127u,
}MCU_enDmaTriggerID;



/********************************************************

	RLIN3 unit

********************************************************/
typedef enum 
{
	MCU_mRLIN3_Uart30 =	0U,
	MCU_mRLIN3_Uart31 =	1U,
	MCU_mRLIN3_Uart32 =	2U,
	MCU_mRLIN3_Uart33 =	3U,
}MCU_enRlin3UartID;

 /********************************************************
 
	 Standby unit
 
 ********************************************************/
 typedef enum 
 {
	 MCU_mHaltMode 		= 0U,
	 MCU_mDeepStopMode 	= 1U,
 }MCU_enRunModeID;
 
 typedef enum 
 {
	MCU_mWakeUpID_INTDCUTDI		 =0u,
	MCU_mWakeUpID_INTP0_RLIN31RX 	 =1u,
	MCU_mWakeUpID_INTP1		 =2u,
	MCU_mWakeUpID_INTP2_RLIN32RX 	 =3u,
	MCU_mWakeUpID_INTP3		 =4u,
	MCU_mWakeUpID_INTP4_RLIN33RX 	 =5u,
	MCU_mWakeUpID_INTP5		 =6u,
	MCU_mWakeUpID_INTP6_CAN0RX		 =7u,
	MCU_mWakeUpID_INTP7		 =8u,
	MCU_mWakeUpID_INTP8_CAN1RX_RLIN30RX		 =9u,
	MCU_mWakeUpID_INTP9		 =10u,
	MCU_mWakeUpID_INTP10_CAN2RX_RLIN30RX 	 =11u,
	MCU_mWakeUpID_INTWDTA0		 =12u,
	MCU_mWakeUpID_INTRTCA01S 	 =13u,
	MCU_mWakeUpID_INTRTCA0AL 	 =14u,
	MCU_mWakeUpID_INTRTCA0R		 =15u,
	MCU_mWakeUpID_INTAWOT0		 =16u,
	MCU_mWakeUpID_ECMTI		 =17u,
	MCU_mWakeUpID_ECMTNMI	 =18u,
  }MCU_enWakeFactorID;
  
  /********************************************************
  
	  ResetControl unit
  
  ********************************************************/
  typedef enum 
  {
	  MCU_mModuleActive 	 = 0U,
	  MCU_mModuleNotActive  = 1U,
  }MCU_enModuleCtrlID;


 /********************************************************
 
	MCU Module resource list
 
 ********************************************************/
#define MCU_mTottalModule 	12
 typedef enum
 {
	 MCU_mModule_IO =0u,
	 MCU_mModule_OSTM =1u,
	 MCU_mModule_TAUx =2u,
	 MCU_mModule_PWGA =3u,
	 MCU_mModule_EINT =4u,
	 MCU_mModule_ADCA =5u,
	 MCU_mModule_RIIC =6u,
	 MCU_mModule_RLIN3 =7u,
	 MCU_mModule_CLOCK =8u,
	 MCU_mModule_DMA =9u,
	 MCU_mModule_CSHI =10u,
	 MCU_mModule_CSGI =11u,  
	 
	 /*interrupt control*/
	 /*standby control*/
	 /*reset control*/
	 /*LVI contorl*/
	 /*watchdog control*/
	 
 }MCU_enModuleID;

 /********************************************************
 
	CSIG Module resource list
 
 ********************************************************/
 typedef enum
 {
	MCU_mCSIG_0=0u,
	MCU_mCSIG_1=1u,
	MCU_mCSIG_2=2u,
	MCU_mCSIG_3=3u,
	
 }MCU_enCsigID;
 
 typedef enum
 {
	MCU_mCSIG_ClkType0=0u,	/*Clk = High, DataTransf = Rising edge*/
	MCU_mCSIG_ClkType1=1u,	/*Clk = High, DataTransf = Failing edge*/
	MCU_mCSIG_ClkType2=2u,	/*Clk = Low, DataTransf = Rising edge*/
	MCU_mCSIG_ClkType3=3u,	/*Clk = Low, DataTransf = Failing edge*/
 }MCU_enCsig_ClkType;

 
 typedef enum
 {
	MCU_mCSIG_Ready=0u,
	MCU_mCSIG_RxOnly=1u,
	MCU_mCSIG_TxOnly=2u,
	MCU_mCSIG_TxRx=3u,
 }MCU_enCsig_WorkingMode;


 /********************************************************
 
	CSIH Module resource list
 
 ********************************************************/
 typedef enum
 {
	MCU_mCSIH_0=0u,
	MCU_mCSIH_1=1u,
 }MCU_enCsihID;
 
 typedef enum
 {
	MCU_mCSIH_ClkType0=0u,	/*Clk = High, DataTransf = Rising edge*/
	MCU_mCSIH_ClkType1=1u,	/*Clk = High, DataTransf = Failing edge*/
	MCU_mCSIH_ClkType2=2u,	/*Clk = Low, DataTransf = Rising edge*/
	MCU_mCSIH_ClkType3=3u,	/*Clk = Low, DataTransf = Failing edge*/
 }MCU_enCsih_ClkType;

 
 typedef enum
 {
	MCU_mCSIH_Ready=0u,
	MCU_mCSIH_RxOnly=1u,
	MCU_mCSIH_TxOnly=2u,
	MCU_mCSIH_TxRx=3u,
 }MCU_enCsih_WorkingMode;


#endif/*end of this file*/
 
