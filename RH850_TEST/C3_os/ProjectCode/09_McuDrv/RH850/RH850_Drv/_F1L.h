/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _F1L.h
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

#define RH850_F1X

#define MCU_MaxPinPerPort		16u
#define MCU_MaxPortType		4u

#define MCU_MaxPortMount		21u
#define MCU_MaxAPortMount	0x2u
#define MCU_MaxJPortMount		0x1u
#define MCU_MaxIPortMount		0x1u

#define MCU_MaxADC0channelMount	36u
#define MCU_MaxADC1channelMount	24u
#define MCU_MaxTAUBunitMount		2u
#define MCU_MaxTAUDunitMount		1u
#define MCU_MaxTAUJunitMount		2u
#define MCU_MaxPWGAchannelMount	72u


/*##########################################################################*/
#define MCU_mPortBaseAddr			0xFFC10000UL
#define MCU_mJPortBaseAddr		0xFFC20000UL
#define MCU_mAPortBaseAddr		(MCU_mPortBaseAddr +0xc8)
#define MCU_mIPortBaseAddr		(MCU_mPortBaseAddr +0xf0)

#define MCU_mPortShift		0x100
#define MCU_mJPortShift	0x10
#define MCU_mAPortShift	0x100
#define MCU_mIPortShift	0x100

/*******************************
PortType Mask 
-----------------------------

bit5,6,7 using for Port type mask:

normal port: 	000
J-port:		001
A-port:		010
I-port:		011

********************************/
#define MCU_mPinTypetMask_Port	(0x0000<<5)
#define MCU_mPinTypetMask_JPort	(0x0001<<5)
#define MCU_mPinTypetMask_IPort	(0X0002<<5)
#define MCU_mPinTypetMask_APort	(0x0003<<5)
#define MCU_mPortMask			(0x0007<<5)

#define MCU_mPinTypeID_Port		(0x0000)
#define MCU_mPinTypeID_JPort	(0x0001)
#define MCU_mPinTypeID_IPort	(0X0002)
#define MCU_mPinTypeID_APort	(0x0003)
#define MCU_mPinTypeID_Max	(0X0004)


typedef enum 
{
	MCU_enOFF=0u,
	MCU_enON=1u,
}MCU_enOnOff;
#define GPIO_Out	0u
#define GPIO_In	1u


typedef enum 
{
	MCU_enPinAltFun_GPIO_Out=0u,
	MCU_enPinAltFun_GPIO_In = 1u,
	MCU_enPinAltFun_AltOut_1	=2u,
	MCU_enPinAltFun_AltIn_1	=3u,
	MCU_enPinAltFun_AltOut_2	=4u,
	MCU_enPinAltFun_AltIn_2	=5u,
	MCU_enPinAltFun_AltOut_3	=6u,
	MCU_enPinAltFun_AltIn_3	=7u,
	MCU_enPinAltFun_AltOut_4	=8u,
	MCU_enPinAltFun_AltIn_4	=9u,
	MCU_enPinAltFun_AltOut_5	=10u,
	MCU_enPinAltFun_AltIn_5	=11u,
	MCU_enPinAltFun_AltOut_6	=12u,
	MCU_enPinAltFun_AltIn_6	=13u,
	MCU_enPinAltFun_AltOut_7	=14u,
	MCU_enPinAltFun_AltIn_7	=15u,
	
}MCU_enPinAltFun;

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

	/*******************************			
	Pin ID define=====JPort 0			
	-----------------------------			
	********************************/			
	 MCU_mPinID_JP0_0	=	0x0000u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_1	=	0x0001u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_2	=	0x0002u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_3	=	0x0003u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_4	=	0x0004u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_5	=	0x0005u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_6	=	0x0006u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_7	=	0x0007u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_8	=	0x0008u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_9	=	0x0009u|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_10	=	0x000au|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_11	=	0x000bu|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_12	=	0x000cu|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_13	=	0x000du|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_14	=	0x000eu|MCU_mPinTypetMask_JPort ,
	 MCU_mPinID_JP0_15	=	0x000fu|MCU_mPinTypetMask_JPort ,
				
	/*******************************			
	Pin ID define=====APort 0			
	-----------------------------			
	********************************/			
	 MCU_mPinID_AP0_0	=	0x0000u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_1	=	0x0001u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_2	=	0x0002u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_3	=	0x0003u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_4	=	0x0004u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_5	=	0x0005u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_6	=	0x0006u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_7	=	0x0007u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_8	=	0x0008u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_9	=	0x0009u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_10	=	0x000au|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_11	=	0x000bu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_12	=	0x000cu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_13	=	0x000du|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_14	=	0x000eu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP0_15	=	0x000fu|MCU_mPinTypetMask_APort ,
				
	/*Pin ID define=====AP 1*/			
	 MCU_mPinID_AP1_0	=	0x0100u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_1	=	0x0101u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_2	=	0x0102u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_3	=	0x0103u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_4	=	0x0104u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_5	=	0x0105u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_6	=	0x0106u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_7	=	0x0107u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_8	=	0x0108u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_9	=	0x0109u|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_10	=	0x010au|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_11	=	0x010bu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_12	=	0x010cu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_13	=	0x010du|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_14	=	0x010eu|MCU_mPinTypetMask_APort ,
	 MCU_mPinID_AP1_15	=	0x010fu|MCU_mPinTypetMask_APort ,
				
	/*******************************			
	Pin ID define=====IPort 0			
	-----------------------------			
	********************************/			
	 MCU_mPinID_IP0_0	=	0x0000u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_1	=	0x0001u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_2	=	0x0002u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_3	=	0x0003u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_4	=	0x0004u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_5	=	0x0005u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_6	=	0x0006u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_7	=	0x0007u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_8	=	0x0008u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_9	=	0x0009u|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_10	=	0x000au|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_11	=	0x000bu|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_12	=	0x000cu|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_13	=	0x000du|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_14	=	0x000eu|MCU_mPinTypetMask_IPort ,
	 MCU_mPinID_IP0_15	=	0x000fu|MCU_mPinTypetMask_IPort ,
}MUC_enPinID;



/*###########################################################
		vector list in this serial MCU
###########################################################*/
typedef enum
{
	MCU_mFEISR_LVIL=0,		/*0*/
	MCU_mFEISR_Reverce1,	/*1*/
	MCU_mFEISR_Reverce2,	/*2*/
	MCU_mFEISR_Reverce3,	/*3*/
	MCU_mFEISR_ECCDEEP0,	/*4*/
	MCU_mFEISR_Reverce5,	/*5*/
	MCU_mFEISR_ECCDCNRAM,	/*6*/
	MCU_mFEISR_ECCDCSIH0,	/*7*/
	MCU_mFEISR_ECCDCSIH1,	/*8*/
	MCU_mFEISR_ECCDCSIH2,	/*9*/
	MCU_mFEISR_ECCDCSIH3,	/*10*/
	MCU_mFEISR_Reverce11,	/*11*/
	MCU_mFEISR_ECCSDFLI0,	/*12*/
	MCU_mFEISR_ECCRAM,	/*13*/
	MCU_mFEISR_OSTM_0,	/*14*/
	MCU_mFEISR_LVIH,		/*15*/	
}MCU_enIsrID_FE;

typedef enum
{
	MCU_mISR_0_ICTAUD0I0_ICCSIH2IC_1	=	0u,
	MCU_mISR_1_ICTAUD0I2_ICCSIH3IC_1	=	1u,
	MCU_mISR_2_ICTAUD0I4	=	2u,
	MCU_mISR_3_ICTAUD0I6	=	3u,
	MCU_mISR_4_ICTAUD0I8	=	4u,
	MCU_mISR_5_ICTAUD0I10_ICCSIH3IR_1	=	5u,
	MCU_mISR_6_ICTAUD0I12_ICCSIH3IRE_1	=	6u,
	MCU_mISR_7_ICTAUD0I14_ICCSIH3IJC_1	=	7u,
	MCU_mISR_8_ICTAPA0IPEK0_ICCSIH1IC_1 =	8u,
	MCU_mISR_9_ICTAPA0IVLY0_ICCSIH1IR_1 =	9u,
	MCU_mISR_10_ICADCA0I0	=	10u,
	MCU_mISR_11_ICADCA0I1	=	11u,
	MCU_mISR_12_ICADCA0I2	=	12u,
	MCU_mISR_13_ICDCUTDI	=	13u,
	MCU_mISR_14_ICRCANGERR	=	14u,
	MCU_mISR_15_ICRCANGRECC =	15u,
	MCU_mISR_16_ICRCAN0ERR	=	16u,
	MCU_mISR_17_ICRCAN0REC	=	17u,
	MCU_mISR_18_ICRCAN0TRX	=	18u,
	MCU_mISR_19_ICCSIG0IC_ICCSIH1IRE_1	=	19u,
	MCU_mISR_20_ICCSIG0IR_ICCSIH1IJC_1	=	20u,
	MCU_mISR_21_ICCSIH0IC	=	21u,
	MCU_mISR_22_ICCSIH0IR	=	22u,
	MCU_mISR_23_ICCSIH0IRE	=	23u,
	MCU_mISR_24_ICCSIH0IJC	=	24u,
	MCU_mISR_25_ICRLIN30	=	25u,
	MCU_mISR_26_ICRLIN30UR0 =	26u,
	MCU_mISR_27_ICRLIN30UR1 =	27u,
	MCU_mISR_28_ICRLIN30UR2 =	28u,
	MCU_mISR_29_ICP0_ICCSIH2IR_1	=	29u,
	MCU_mISR_30_ICP1_ICCSIH2IRE_1	=	30u,
	MCU_mISR_31_ICP2_ICCSIH2IJC_1	=	31u,
	MCU_mISR_32_ICWDTA0 =	32u,
	MCU_mISR_33_ICWDTA1 =	33u,
	MCU_mISR_34_ICP3	=	34u,
	MCU_mISR_35_ICP4	=	35u,
	MCU_mISR_36_ICP5	=	36u,
	MCU_mISR_37_ICP10	=	37u,
	MCU_mISR_38_ICP11	=	38u,
	MCU_mISR_39_ICTAUD0I1	=	39u,
	MCU_mISR_40_ICTAUD0I3	=	40u,
	MCU_mISR_41_ICTAUD0I5	=	41u,
	MCU_mISR_42_ICTAUD0I7	=	42u,
	MCU_mISR_43_ICTAUD0I9	=	43u,
	MCU_mISR_44_ICTAUD0I11	=	44u,
	MCU_mISR_45_ICTAUD0I13	=	45u,
	MCU_mISR_46_ICTAUD0I15	=	46u,
	MCU_mISR_47_ICADCA0ERR	=	47u,
	MCU_mISR_48_Reserved	=	48u,
	MCU_mISR_49_ICCSIG0IRE	=	49u,
	MCU_mISR_50_ICRLIN20	=	50u,
	MCU_mISR_51_ICRLIN21	=	51u,
	MCU_mISR_52_ICDMA0	=	52u,
	MCU_mISR_53_ICDMA1	=	53u,
	MCU_mISR_54_ICDMA2	=	54u,
	MCU_mISR_55_ICDMA3	=	55u,
	MCU_mISR_56_ICDMA4	=	56u,
	MCU_mISR_57_ICDMA5	=	57u,
	MCU_mISR_58_ICDMA6	=	58u,
	MCU_mISR_59_ICDMA7	=	59u,
	MCU_mISR_60_ICDMA8	=	60u,
	MCU_mISR_61_ICDMA9	=	61u,
	MCU_mISR_62_ICDMA10 =	62u,
	MCU_mISR_63_ICDMA11 =	63u,
	MCU_mISR_64_ICDMA12 =	64u,
	MCU_mISR_65_ICDMA13 =	65u,
	MCU_mISR_66_ICDMA14 =	66u,
	MCU_mISR_67_ICDMA15 =	67u,
	MCU_mISR_68_ICRIIC0TI	=	68u,
	MCU_mISR_69_ICRIIC0TEI	=	69u,
	MCU_mISR_70_ICRIIC0RI	=	70u,
	MCU_mISR_71_ICRIIC0EE	=	71u,
	MCU_mISR_72_ICTAUJ0I0	=	72u,
	MCU_mISR_73_ICTAUJ0I1	=	73u,
	MCU_mISR_74_ICTAUJ0I2	=	74u,
	MCU_mISR_75_ICTAUJ0I3	=	75u,
	MCU_mISR_76_ICOSTM0 =	76u,
	MCU_mISR_77_ICENCA0IOV_ICPWGA4	=	77u,
	MCU_mISR_78_ICENCA0IUD_ICPWGA5	=	78u,
	MCU_mISR_79_ICENCA0I0_ICPWGA6	=	79u,
	MCU_mISR_80_ICENCA0I1_ICPWGA7	=	80u,
	MCU_mISR_81_ICENCA0IEC	=	81u,
	MCU_mISR_82_ICKR0	=	82u,
	MCU_mISR_83_ICQFULL =	83u,
	MCU_mISR_84_ICPWGA0 =	84u,
	MCU_mISR_85_ICPWGA1 =	85u,
	MCU_mISR_86_ICPWGA2 =	86u,
	MCU_mISR_87_ICPWGA3 =	87u,
	MCU_mISR_88_ICPWGA8 =	88u,
	MCU_mISR_89_ICPWGA9 =	89u,
	MCU_mISR_90_ICPWGA10	=	90u,
	MCU_mISR_91_ICPWGA11	=	91u,
	MCU_mISR_92_ICPWGA12	=	92u,
	MCU_mISR_93_ICPWGA13	=	93u,
	MCU_mISR_94_ICPWGA14	=	94u,
	MCU_mISR_95_ICPWGA15	=	95u,
	MCU_mISR_96_Reserved	=	96u,
	MCU_mISR_97_Reserved	=	97u,
	MCU_mISR_98_Reserved	=	98u,
	MCU_mISR_99_Reserved	=	99u,
	MCU_mISR_100_Reserved	=	100u,
	MCU_mISR_101_Reserved	=	101u,
	MCU_mISR_102_ICFLERR	=	102u,
	MCU_mISR_103_ICFLENDNM	=	103u,
	MCU_mISR_104_ICCWEND	=	104u,
	MCU_mISR_105_ICRCAN1ERR =	105u,
	MCU_mISR_106_ICRCAN1REC =	106u,
	MCU_mISR_107_ICRCAN1TRX =	107u,
	MCU_mISR_108_ICCSIH1IC_ICTAPA0IPEK0_2	=	108u,
	MCU_mISR_109_ICCSIH1IR_ICTAPA0IVLY0_2	=	109u,
	MCU_mISR_110_ICCSIH1IRE_ICCSIG0IC_2 =	110u,
	MCU_mISR_111_ICCSIH1IJC_ICCSIG0IR_2 =	111u,
	MCU_mISR_112_ICRLIN31	=	112u,
	MCU_mISR_113_ICRLIN31UR0	=	113u,
	MCU_mISR_114_ICRLIN31UR1	=	114u,
	MCU_mISR_115_ICRLIN31UR2	=	115u,
	MCU_mISR_116_ICPWGA20	=	116u,
	MCU_mISR_117_ICPWGA21	=	117u,
	MCU_mISR_118_ICPWGA22	=	118u,
	MCU_mISR_119_ICPWGA23	=	119u,
	MCU_mISR_120_ICP6	=	120u,
	MCU_mISR_121_ICP7	=	121u,
	MCU_mISR_122_ICP8	=	122u,
	MCU_mISR_123_ICP12	=	123u,
	MCU_mISR_124_ICCSIH2IC_ICTAUD0I0_2	=	124u,
	MCU_mISR_125_ICCSIH2IR_ICP0_2	=	125u,
	MCU_mISR_126_ICCSIH2IRE_ICP1_2	=	126u,
	MCU_mISR_127_ICCSIH2IJC_ICP2_2	=	127u,
	MCU_mISR_128_Reserved	=	128u,
	MCU_mISR_129_Reserved	=	129u,
	MCU_mISR_130_Reserved	=	130u,
	MCU_mISR_131_Reserved	=	131u,
	MCU_mISR_132_Reserved	=	132u,
	MCU_mISR_133_Reserved	=	133u,
	MCU_mISR_134_ICTAUB0I0	=	134u,
	MCU_mISR_135_ICTAUB0I1	=	135u,
	MCU_mISR_136_ICTAUB0I2	=	136u,
	MCU_mISR_137_ICTAUB0I3_ICPWGA16 =	137u,
	MCU_mISR_138_ICTAUB0I4	=	138u,
	MCU_mISR_139_ICTAUB0I5_ICPWGA17 =	139u,
	MCU_mISR_140_ICTAUB0I6	=	140u,
	MCU_mISR_141_ICTAUB0I7_ICPWGA18 =	141u,
	MCU_mISR_142_ICTAUB0I8	=	142u,
	MCU_mISR_143_ICTAUB0I9_ICPWGA19 =	143u,
	MCU_mISR_144_ICTAUB0I10 =	144u,
	MCU_mISR_145_ICTAUB0I11_ICPWGA26	=	145u,
	MCU_mISR_146_ICTAUB0I12 =	146u,
	MCU_mISR_147_ICTAUB0I13_ICPWGA30	=	147u,
	MCU_mISR_148_ICTAUB0I14 =	148u,
	MCU_mISR_149_ICTAUB0I15_ICPWGA31	=	149u,
	MCU_mISR_150_ICCSIH3IC_ICTAUD0I2_2	=	150u,
	MCU_mISR_151_ICCSIH3IR_ICTAUD0I10_2 =	151u,
	MCU_mISR_152_ICCSIH3IRE_ICTAUD0I12_2	=	152u,
	MCU_mISR_153_ICCSIH3IJC_ICTAUD0I14_2	=	153u,
	MCU_mISR_154_ICRLIN22	=	154u,
	MCU_mISR_155_ICRLIN23	=	155u,
	MCU_mISR_156_ICRLIN32	=	156u,
	MCU_mISR_157_ICRLIN32UR0	=	157u,
	MCU_mISR_158_ICRLIN32UR1	=	158u,
	MCU_mISR_159_ICRLIN32UR2	=	159u,
	MCU_mISR_160_ICTAUJ1I0	=	160u,
	MCU_mISR_161_ICTAUJ1I1	=	161u,
	MCU_mISR_162_ICTAUJ1I2	=	162u,
	MCU_mISR_163_ICTAUJ1I3	=	163u,
	MCU_mISR_164_Reserved	=	164u,
	MCU_mISR_165_Reserved	=	165u,
	MCU_mISR_166_Reserved	=	166u,
	MCU_mISR_167_Reserved	=	167u,
	MCU_mISR_168_Reserved	=	168u,
	MCU_mISR_169_Reserved	=	169u,
	MCU_mISR_170_Reserved	=	170u,
	MCU_mISR_171_Reserved	=	171u,
	MCU_mISR_172_Reserved	=	172u,
	MCU_mISR_173_Reserved	=	173u,
	MCU_mISR_174_Reserved	=	174u,
	MCU_mISR_175_Reserved	=	175u,
	MCU_mISR_176_ICPWGA24	=	176u,
	MCU_mISR_177_ICPWGA25	=	177u,
	MCU_mISR_178_ICPWGA27	=	178u,
	MCU_mISR_179_ICPWGA28	=	179u,
	MCU_mISR_180_ICPWGA29	=	180u,
	MCU_mISR_181_ICPWGA32	=	181u,
	MCU_mISR_182_ICPWGA33	=	182u,
	MCU_mISR_183_ICPWGA34	=	183u,
	MCU_mISR_184_ICPWGA35	=	184u,
	MCU_mISR_185_ICPWGA36	=	185u,
	MCU_mISR_186_ICPWGA37	=	186u,
	MCU_mISR_187_ICPWGA38	=	187u,
	MCU_mISR_188_ICPWGA39	=	188u,
	MCU_mISR_189_ICPWGA40	=	189u,
	MCU_mISR_190_ICPWGA41	=	190u,
	MCU_mISR_191_ICPWGA42	=	191u,
	MCU_mISR_192_ICPWGA43	=	192u,
	MCU_mISR_193_ICPWGA44	=	193u,
	MCU_mISR_194_ICPWGA45	=	194u,
	MCU_mISR_195_ICPWGA46	=	195u,
	MCU_mISR_196_ICPWGA47	=	196u,
	MCU_mISR_197_ICP9	=	197u,
	MCU_mISR_198_ICP13	=	198u,
	MCU_mISR_199_ICP14	=	199u,
	MCU_mISR_200_ICP15	=	200u,
	MCU_mISR_201_ICRTCA01S	=	201u,
	MCU_mISR_202_ICRTCA0AL	=	202u,
	MCU_mISR_203_ICRTCA0R	=	203u,
	MCU_mISR_204_ICADCA1ERR =	204u,
	MCU_mISR_205_ICADCA1I0	=	205u,
	MCU_mISR_206_ICADCA1I1	=	206u,
	MCU_mISR_207_ICADCA1I2	=	207u,
	MCU_mISR_208_Reserved	=	208u,
	MCU_mISR_209_ICRCAN2ERR =	209u,
	MCU_mISR_210_ICRCAN2REC =	210u,
	MCU_mISR_211_ICRCAN2TRX =	211u,
	MCU_mISR_212_ICRCAN3ERR =	212u,
	MCU_mISR_213_ICRCAN3REC =	213u,
	MCU_mISR_214_ICRCAN3TRX =	214u,
	MCU_mISR_215_ICCSIG1IC	=	215u,
	MCU_mISR_216_ICCSIG1IR	=	216u,
	MCU_mISR_217_ICCSIG1IRE =	217u,
	MCU_mISR_218_ICRLIN24	=	218u,
	MCU_mISR_219_ICRLIN25	=	219u,
	MCU_mISR_220_ICRLIN33	=	220u,
	MCU_mISR_221_ICRLIN33UR0	=	221u,
	MCU_mISR_222_ICRLIN33UR1	=	222u,
	MCU_mISR_223_ICRLIN33UR2	=	223u,
	MCU_mISR_224_ICRLIN34	=	224u,
	MCU_mISR_225_ICRLIN34UR0	=	225u,
	MCU_mISR_226_ICRLIN34UR1	=	226u,
	MCU_mISR_227_ICRLIN34UR2	=	227u,
	MCU_mISR_228_ICRLIN35	=	228u,
	MCU_mISR_229_ICRLIN35UR0	=	229u,
	MCU_mISR_230_ICRLIN35UR1	=	230u,
	MCU_mISR_231_ICRLIN35UR2	=	231u,
	MCU_mISR_232_ICPWGA48	=	232u,
	MCU_mISR_233_ICPWGA49	=	233u,
	MCU_mISR_234_ICPWGA50	=	234u,
	MCU_mISR_235_ICPWGA51	=	235u,
	MCU_mISR_236_ICPWGA52	=	236u,
	MCU_mISR_237_ICPWGA53	=	237u,
	MCU_mISR_238_ICPWGA54	=	238u,
	MCU_mISR_239_ICPWGA55	=	239u,
	MCU_mISR_240_ICPWGA56	=	240u,
	MCU_mISR_241_ICPWGA57	=	241u,
	MCU_mISR_242_ICPWGA58	=	242u,
	MCU_mISR_243_ICPWGA59	=	243u,
	MCU_mISR_244_ICPWGA60	=	244u,
	MCU_mISR_245_ICPWGA61	=	245u,
	MCU_mISR_246_ICPWGA62	=	246u,
	MCU_mISR_247_ICPWGA63	=	247u,
	MCU_mISR_248_ICTAUB1I0	=	248u,
	MCU_mISR_249_ICTAUB1I1	=	249u,
	MCU_mISR_250_ICTAUB1I2	=	250u,
	MCU_mISR_251_ICTAUB1I3	=	251u,
	MCU_mISR_252_ICTAUB1I4	=	252u,
	MCU_mISR_253_ICTAUB1I5	=	253u,
	MCU_mISR_254_ICTAUB1I6	=	254u,
	MCU_mISR_255_ICTAUB1I7	=	255u,
	MCU_mISR_256_ICTAUB1I8	=	256u,
	MCU_mISR_257_ICTAUB1I9	=	257u,
	MCU_mISR_258_ICTAUB1I10 =	258u,
	MCU_mISR_259_ICTAUB1I11 =	259u,
	MCU_mISR_260_ICTAUB1I12 =	260u,
	MCU_mISR_261_ICTAUB1I13 =	261u,
	MCU_mISR_262_ICTAUB1I14 =	262u,
	MCU_mISR_263_ICTAUB1I15 =	263u,
	MCU_mISR_264_ICRCAN4ERR =	264u,
	MCU_mISR_265_ICRCAN4REC =	265u,
	MCU_mISR_266_ICRCAN4TRX =	266u,
	MCU_mISR_267_ICRLIN26	=	267u,
	MCU_mISR_268_ICRLIN27	=	268u,
	MCU_mISR_269_ICPWGA64	=	269u,
	MCU_mISR_270_ICPWGA65	=	270u,
	MCU_mISR_271_ICPWGA66	=	271u,
	MCU_mISR_272_ICPWGA67	=	272u,
	MCU_mISR_273_ICPWGA68	=	273u,
	MCU_mISR_274_ICPWGA69	=	274u,
	MCU_mISR_275_ICPWGA70	=	275u,
	MCU_mISR_276_ICPWGA71	=	276u,
	MCU_mISR_277_ICRLIN28	=	277u,
	MCU_mISR_278_ICRLIN29	=	278u,
	MCU_mISR_279_ICRCAN5ERR =	279u,
	MCU_mISR_280_ICRCAN5REC =	280u,
	MCU_mISR_281_ICRCAN5TRX =	281u,
	MCU_mISR_282_Reserved	=	282u,
	MCU_mISR_283_Reserved	=	283u,
	MCU_mISR_284_Reserved	=	284u,
	MCU_mISR_285_Reserved	=	285u,
	MCU_mISR_286_Reserved	=	286u,
	MCU_mISR_287_Reserved	=	287u,

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
	MCU_mPWGA24    =   24u, 								   
	MCU_mPWGA25    =   25u, 								   
	MCU_mPWGA26    =   26u, 								   
	MCU_mPWGA27    =   27u, 								   
	MCU_mPWGA28    =   28u, 								   
	MCU_mPWGA29    =   29u, 								   
	MCU_mPWGA30    =   30u, 								   
	MCU_mPWGA31    =   31u, 								   
	MCU_mPWGA32    =   32u, 								   
	MCU_mPWGA33    =   33u, 								   
	MCU_mPWGA34    =   34u, 								   
	MCU_mPWGA35    =   35u, 								   
	MCU_mPWGA36    =   36u, 								   
	MCU_mPWGA37    =   37u, 								   
	MCU_mPWGA38    =   38u, 								   
	MCU_mPWGA39    =   39u, 								   
	MCU_mPWGA40    =   40u, 								   
	MCU_mPWGA41    =   41u, 								   
	MCU_mPWGA42    =   42u, 								   
	MCU_mPWGA43    =   43u, 								   
	MCU_mPWGA44    =   44u, 								   
	MCU_mPWGA45    =   45u, 								   
	MCU_mPWGA46    =   46u, 								   
	MCU_mPWGA47    =   47u, 								   
	MCU_mPWGA48    =   48u, 								   
	MCU_mPWGA49    =   49u, 								   
	MCU_mPWGA50    =   50u, 								   
	MCU_mPWGA51    =   51u, 								   
	MCU_mPWGA52    =   52u, 								   
	MCU_mPWGA53    =   53u, 								   
	MCU_mPWGA54    =   54u, 								   
	MCU_mPWGA55    =   55u, 								   
	MCU_mPWGA56    =   56u, 								   
	MCU_mPWGA57    =   57u, 								   
	MCU_mPWGA58    =   58u, 								   
	MCU_mPWGA59    =   59u, 								   
	MCU_mPWGA60    =   60u, 								   
	MCU_mPWGA61    =   61u, 								   
	MCU_mPWGA62    =   62u, 								   
	MCU_mPWGA63    =   63u, 								   
	MCU_mPWGA64    =   64u, 								   
	MCU_mPWGA65    =   65u, 								   
	MCU_mPWGA66    =   66u, 								   
	MCU_mPWGA67    =   67u, 								   
	MCU_mPWGA68    =   68u, 								   
	MCU_mPWGA69    =   69u, 								   
	MCU_mPWGA70    =   70u, 								   
	MCU_mPWGA71    =   71u, 								   
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
											   
	MCU_mTAUD0_0   =   32u, 								   
	MCU_mTAUD0_1   =   33u, 								   
	MCU_mTAUD0_2   =   34u, 								   
	MCU_mTAUD0_3   =   35u, 								   
	MCU_mTAUD0_4   =   36u, 								   
	MCU_mTAUD0_5   =   37u, 								   
	MCU_mTAUD0_6   =   38u, 								   
	MCU_mTAUD0_7   =   39u, 								   
	MCU_mTAUD0_8   =   40u, 								   
	MCU_mTAUD0_9   =   41u, 								   
	MCU_mTAUD0_10  =   42u, 								   
	MCU_mTAUD0_11  =   43u, 								   
	MCU_mTAUD0_12  =   44u, 								   
	MCU_mTAUD0_13  =   45u, 								   
	MCU_mTAUD0_14  =   46u, 								   
	MCU_mTAUD0_15  =   47u, 								   
											   
	MCU_mTAUJ0_0   =   48u	,							   
	MCU_mTAUJ0_1   =   49u,								   
	MCU_mTAUJ0_2   =   50u,								   
	MCU_mTAUJ0_3   =   51u,								   
											   
	MCU_mTAUJ1_0   =   52u,								   
	MCU_mTAUJ1_1   =   53u,								   
	MCU_mTAUJ1_2   =   54u,								   
	MCU_mTAUJ1_3   =   55u,								   
}MCU_enTauxID;

typedef enum 
{
	MCU_mTAUxID_B0   =   0u,								   
	MCU_mTAUxID_B1   =   1u,
	MCU_mTAUxID_D0   =   2u,								   
	MCU_mTAUxID_J0   =   3u,								   
	MCU_mTAUxID_J1   =   4u,								   
}MCU_enTauxGrpID;

typedef enum 
{
	MCU_mTAUx_Stop   =   0u,								   
	MCU_mTAUx_Run   =   1u,								   
}MCU_enTauxRunCtrl;



typedef enum 
{
    MCU_enTAUxTrigger_FaillingEdge=0,
    MCU_enTAUxTrigger_RisingEdge,
    MCU_enTAUxTrigger_LowLevel,
    MCU_enTAUxTrigger_HighLevel,
    
}MCU_enTAUxTriggerID;

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


/********************************************************

	RIIC unit

********************************************************/
typedef enum 
{
	MCU_mRIIC_0	 =	0u,
}MCU_enRiicID;



typedef enum 
{
	MCU_enRIIC_Ready	 =	0u,
	MCU_enRIIC_Reading	 =	1u,
	MCU_enRIIC_Writting	 =	2u,
	
}MCU_enRiicStatus;

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
/**********************************************************
DMA trriger for channel 0-7!
**********************************************************/
	
	MCU_mDMAtrig_INTTAUD0I0=0u,
	MCU_mDMAtrig_INTTAUD0I4=1u,
	MCU_mDMAtrig_INTTAUD0I8=2u,
	MCU_mDMAtrig_INTTAUD0I12=3u,
	MCU_mDMAtrig_INTADCA0I0=4u,
	MCU_mDMAtrig_INTADCA0I1=5u,
	MCU_mDMAtrig_INTADCA0I2=6u,
	MCU_mDMAtrig_ADC_CONV_END0=7u,
	MCU_mDMAtrig_INTCSIG0IC=8u,
	MCU_mDMAtrig_INTCSIG0IR=9u,
	MCU_mDMAtrig_INTRLIN30UR0=10u,
	MCU_mDMAtrig_INTRLIN30UR1=11u,
	MCU_mDMAtrig_INTP0=12u,
	MCU_mDMAtrig_INTP2=13u,
	MCU_mDMAtrig_INTP4=14u,
	MCU_mDMAtrig_INTTAUD0I1=15u,
	MCU_mDMAtrig_INTTAUD0I5=16u,
	MCU_mDMAtrig_INTTAUD0I9=17u,
	MCU_mDMAtrig_INTTAUD0I13=18u,
	MCU_mDMAtrig_INTRIIC0TI=19u,
	MCU_mDMAtrig_INTRIIC0RI=20u,
	MCU_mDMAtrig_INTTAUJ0I0=21u,
	MCU_mDMAtrig_INTTAUJ0I3=22u,
	MCU_mDMAtrig_Reserved23=23u,
	MCU_mDMAtrig_Reserved24=24u,
	MCU_mDMAtrig_Reserved25=25u,
	MCU_mDMAtrig_Reserved26=26u,
	MCU_mDMAtrig_Reserved27=27u,
	MCU_mDMAtrig_INTCSIH1IC=28u,
	MCU_mDMAtrig_INTCSIH1IR=29u,
	MCU_mDMAtrig_INTCSIH1IJC=30u,
	MCU_mDMAtrig_INTP6=31u,
	MCU_mDMAtrig_INTP8=32u,
	MCU_mDMAtrig_INTTAUB0I0=33u,
	MCU_mDMAtrig_INTTAUB0I2=34u,
	MCU_mDMAtrig_INTTAUB0I4=35u,
	MCU_mDMAtrig_INTTAUB0I6=36u,
	MCU_mDMAtrig_INTTAUB0I9=37u,
	MCU_mDMAtrig_INTTAUB0I11=38u,
	MCU_mDMAtrig_INTTAUB0I13=39u,
	MCU_mDMAtrig_INTTAUB0I15=40u,
	MCU_mDMAtrig_INTCSIH3IC=41u,
	MCU_mDMAtrig_INTCSIH3IR=42u,
	MCU_mDMAtrig_INTCSIH3IJC=43u,
	MCU_mDMAtrig_INTRLIN32UR0=44u,
	MCU_mDMAtrig_INTRLIN32UR1=45u,
	MCU_mDMAtrig_INTTAUJ1I0=46u,
	MCU_mDMAtrig_INTTAUJ1I2=47u,
	MCU_mDMAtrig_Reserved48=48u,
	MCU_mDMAtrig_Reserved49=49u,
	MCU_mDMAtrig_INTRLIN34UR0=50u,
	MCU_mDMAtrig_INTRLIN34UR1=51u,
	MCU_mDMAtrig_INTTAUB1I0=52u,
	MCU_mDMAtrig_INTTAUB1I2=53u,
	MCU_mDMAtrig_INTTAUB1I4=54u,
	MCU_mDMAtrig_INTTAUB1I6=55u,
	MCU_mDMAtrig_INTTAUB1I9=56u,
	MCU_mDMAtrig_INTTAUB1I11=57u,
	MCU_mDMAtrig_INTTAUB1I13=58u,
	MCU_mDMAtrig_INTTAUB1I15=59u,
	MCU_mDMAtrig_Reserved60=60u,
	MCU_mDMAtrig_Reserved61=61u,
	MCU_mDMAtrig_Reserved62=62u,
	MCU_mDMAtrig_Reserved63=63u,
	
/**********************************************************
DMA trriger for channel 8-15, it will morror to 0 index in code!!!
**********************************************************/
	MCU_mDMAtrig_INTTAUD0I2=64u,
	MCU_mDMAtrig_INTTAUD0I6=65u,
	MCU_mDMAtrig_INTTAUD0I10=66u,
	MCU_mDMAtrig_INTTAUD0I14=67u,
	MCU_mDMAtrig_Reserved68=68u,
	MCU_mDMAtrig_Reserved69=69u,
	MCU_mDMAtrig_INTCSIH0IC=70u,
	MCU_mDMAtrig_INTCSIH0IR=71u,
	MCU_mDMAtrig_INTCSIH0IJC=72u,
	MCU_mDMAtrig_INTP1=73u,
	MCU_mDMAtrig_INTP3=74u,
	MCU_mDMAtrig_INTP5=75u,
	MCU_mDMAtrig_INTTAUD0I3=76u,
	MCU_mDMAtrig_INTTAUD0I7=77u,
	MCU_mDMAtrig_INTTAUD0I11=78u,
	MCU_mDMAtrig_INTTAUD0I15=79u,
	MCU_mDMAtrig_INTTAUJ0I1=80u,
	MCU_mDMAtrig_INTTAUJ0I2=81u,
	MCU_mDMAtrig_Reserved82=82u,
	MCU_mDMAtrig_Reserved83=83u,
	MCU_mDMAtrig_Reserved84=84u,
	MCU_mDMAtrig_INTDMAFL=85u,
	MCU_mDMAtrig_INTRLIN31UR0=86u,
	MCU_mDMAtrig_INTRLIN31UR1=87u,
	MCU_mDMAtrig_INTP7=88u,
	MCU_mDMAtrig_INTCSIH2IC=89u,
	MCU_mDMAtrig_INTCSIH2IR=90u,
	MCU_mDMAtrig_INTCSIH2IJC=91u,
	MCU_mDMAtrig_INTTAUB0I1=92u,
	MCU_mDMAtrig_INTTAUB0I3=93u,
	MCU_mDMAtrig_INTTAUB0I5=94u,
	MCU_mDMAtrig_INTTAUB0I7=95u,
	MCU_mDMAtrig_INTTAUB0I8=96u,
	MCU_mDMAtrig_INTTAUB0I10=97u,
	MCU_mDMAtrig_INTTAUB0I12=98u,
	MCU_mDMAtrig_INTTAUB0I14=99u,
	MCU_mDMAtrig_INTTAUJ1I1=100u,
	MCU_mDMAtrig_INTTAUJ1I3=101u,
	MCU_mDMAtrig_INTP9=102u,
	MCU_mDMAtrig_INTADCA1I0=103u,
	MCU_mDMAtrig_INTADCA1I1=104u,
	MCU_mDMAtrig_INTADCA1I2=105u,
	MCU_mDMAtrig_ADC_CONV_END1=106u,
	MCU_mDMAtrig_Reserved107=107u,
	MCU_mDMAtrig_Reserved108=108u,
	MCU_mDMAtrig_INTCSIG1IC=109u,
	MCU_mDMAtrig_INTCSIG1IR=110u,
	MCU_mDMAtrig_INTRLIN33UR0=111u,
	MCU_mDMAtrig_INTRLIN33UR1=112u,
	MCU_mDMAtrig_INTRLIN35UR0=113u,
	MCU_mDMAtrig_INTRLIN35UR1=114u,
	MCU_mDMAtrig_INTTAUB1I1=115u,
	MCU_mDMAtrig_INTTAUB1I3=116u,
	MCU_mDMAtrig_INTTAUB1I5=117u,
	MCU_mDMAtrig_INTTAUB1I7=118u,
	MCU_mDMAtrig_INTTAUB1I8=119u,
	MCU_mDMAtrig_INTTAUB1I10=120u,
	MCU_mDMAtrig_INTTAUB1I12=121u,
	MCU_mDMAtrig_INTTAUB1I14=122u,
	MCU_mDMAtrig_Reserved123=123u,
	MCU_mDMAtrig_Reserved124=124u,
	MCU_mDMAtrig_Reserved125=125u,
	MCU_mDMAtrig_Reserved126=126u,
	MCU_mDMAtrig_Reserved127=127u,
}MCU_enDmaTriggerID;

/********************************************************

	OSTM unit

********************************************************/
typedef enum 
{
	MCU_mOSTM_0	 =	0u,
}MCU_enOstmID;

/********************************************************

	EINT unit

********************************************************/
typedef enum 
{
	MCU_mEINT_ID_INT0  =   0u,
	MCU_mEINT_ID_INT1  =   1u,
	MCU_mEINT_ID_INT2  =   2u,
	MCU_mEINT_ID_INT3  =   3u,
	MCU_mEINT_ID_INT4  =   4u,
	MCU_mEINT_ID_INT5  =   5u,
	MCU_mEINT_ID_INT6  =   6u,
	MCU_mEINT_ID_INT7  =   7u,
	MCU_mEINT_ID_INT8  =   8u,
	MCU_mEINT_ID_INT9  =   9u,
	MCU_mEINT_ID_INT10 =   10u,
	MCU_mEINT_ID_INT11 =   11u,
	MCU_mEINT_ID_INT12 =   12u,
	MCU_mEINT_ID_INT13 =   13u,
	MCU_mEINT_ID_INT14 =   14u,
	MCU_mEINT_ID_INT15 =   15u,
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

	ADCA unit

********************************************************/
#define MCU_mADC_MaxChPerUnit	60
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
	MCU_mADCID_ADCA0I0S    =   16u, 								   
	MCU_mADCID_ADCA0I1S    =   17u, 								   
	MCU_mADCID_ADCA0I2S    =   18u, 								   
	MCU_mADCID_ADCA0I3S    =   19u, 								   
	MCU_mADCID_ADCA0I4S    =   20u, 								   
	MCU_mADCID_ADCA0I5S    =   21u, 								   
	MCU_mADCID_ADCA0I6S    =   22u, 								   
	MCU_mADCID_ADCA0I7S    =   23u, 								   
	MCU_mADCID_ADCA0I8S    =   24u, 								   
	MCU_mADCID_ADCA0I9S    =   25u, 								   
	MCU_mADCID_ADCA0I10S   =   26u, 								   
	MCU_mADCID_ADCA0I11S   =   27u, 								   
	MCU_mADCID_ADCA0I12S   =   28u, 								   
	MCU_mADCID_ADCA0I13S   =   29u, 								   
	MCU_mADCID_ADCA0I14S   =   30u, 								   
	MCU_mADCID_ADCA0I15S   =   31u, 								   
	MCU_mADCID_ADCA0I16S   =   32u, 								   
	MCU_mADCID_ADCA0I17S   =   33u, 								   
	MCU_mADCID_ADCA0I18S   =   34u, 								   
	MCU_mADCID_ADCA0I19S   =   35u, 								   
	MCU_mADCID_ADCA1I0 =   (MCU_mADC_MaxChPerUnit + 0u),								   
	MCU_mADCID_ADCA1I1 =   (MCU_mADC_MaxChPerUnit + 1u),								   
	MCU_mADCID_ADCA1I2 =   (MCU_mADC_MaxChPerUnit + 2u),								   
	MCU_mADCID_ADCA1I3 =   (MCU_mADC_MaxChPerUnit + 3u),								   
	MCU_mADCID_ADCA1I4 =   (MCU_mADC_MaxChPerUnit + 4u),								   
	MCU_mADCID_ADCA1I5 =   (MCU_mADC_MaxChPerUnit + 5u),								   
	MCU_mADCID_ADCA1I6 =   (MCU_mADC_MaxChPerUnit + 6u),								   
	MCU_mADCID_ADCA1I7 =   (MCU_mADC_MaxChPerUnit + 7u),								   
	MCU_mADCID_ADCA1I8 =   (MCU_mADC_MaxChPerUnit + 8u),								   
	MCU_mADCID_ADCA1I9 =   (MCU_mADC_MaxChPerUnit + 9u),								   
	MCU_mADCID_ADCA1I10    =   (MCU_mADC_MaxChPerUnit + 10u),								   
	MCU_mADCID_ADCA1I11    =   (MCU_mADC_MaxChPerUnit + 11u),								   
	MCU_mADCID_ADCA1I12    =   (MCU_mADC_MaxChPerUnit + 12u),								   
	MCU_mADCID_ADCA1I13    =   (MCU_mADC_MaxChPerUnit + 13u),								   
	MCU_mADCID_ADCA1I14    =   (MCU_mADC_MaxChPerUnit + 14u),								   
	MCU_mADCID_ADCA1I15    =   (MCU_mADC_MaxChPerUnit + 15u),								   
	MCU_mADCID_ADCA1I0S    =   (MCU_mADC_MaxChPerUnit + 16u),								   
	MCU_mADCID_ADCA1I1S    =   (MCU_mADC_MaxChPerUnit + 17u),								   
	MCU_mADCID_ADCA1I2S    =   (MCU_mADC_MaxChPerUnit + 18u),								   
	MCU_mADCID_ADCA1I3S    =   (MCU_mADC_MaxChPerUnit + 19u),								   
	MCU_mADCID_ADCA1I4S    =   (MCU_mADC_MaxChPerUnit + 20u),								   
	MCU_mADCID_ADCA1I5S    =   (MCU_mADC_MaxChPerUnit + 21u),								   
	MCU_mADCID_ADCA1I6S    =   (MCU_mADC_MaxChPerUnit + 22u),								   
	MCU_mADCID_ADCA1I7S    =   (MCU_mADC_MaxChPerUnit + 23u),								   
}MCU_enAdcaID;

/********************************************************

	RLIN3 unit

********************************************************/
typedef enum 
{
	MCU_mRLINUart3_0   =   0u,
	MCU_mRLINUart3_1   =   1u,
	MCU_mRLINUart3_2   =   2u,
	MCU_mRLINUart3_3   =   3u,
	MCU_mRLINUart3_4   =   4u,
	MCU_mRLINUart3_5   =   5u,
}MCU_enRlin3UartID;

/********************************************************

	Standby unit

********************************************************/
typedef enum 
{
	MCU_mHaltMode	   = 0U,
	MCU_mDeepStopMode  = 1U,
	MCU_mStopMode  = 2U,
	MCU_mCyclicRunMode=3U,
	MCU_mCyclicStopMode=4U,
}MCU_enRunModeID;

typedef enum 
{
	/*WU_0  = factor1*/
	MCU_mWakeUpID_TNMI	=0u,				
	MCU_mWakeUpID_WDTA0NMI	=1u,
	MCU_mWakeUpID_INTLVIL	=2u,
	MCU_mWakeUpID_Fill0 =3u,
	MCU_mWakeUpID_Fill1 =4u,
	MCU_mWakeUpID_INTP0 	=5u,
	MCU_mWakeUpID_INTP1 	=6u,
	MCU_mWakeUpID_INTP2 	=7u,
	MCU_mWakeUpID_INTWDTA0	=8u,
	MCU_mWakeUpID_INTP3 	=9u,
	MCU_mWakeUpID_INTP4 	=10u,
	MCU_mWakeUpID_INTP5 	=11u,
	MCU_mWakeUpID_INTP10	=12u,
	MCU_mWakeUpID_INTP11	=13u,
	MCU_mWakeUpID_WUTRG1	=14u,
	MCU_mWakeUpID_INTTAUJ0I0	=15u,
	MCU_mWakeUpID_INTTAUJ0I1	=16u,
	MCU_mWakeUpID_INTTAUJ0I2	=17u,
	MCU_mWakeUpID_INTTAUJ0I3	=18u,
	MCU_mWakeUpID_WUTRG0	=19u,
	MCU_mWakeUpID_INTP6 	=20u,
	MCU_mWakeUpID_INTP7 	=21u,
	MCU_mWakeUpID_INTP8 	=22u,
	MCU_mWakeUpID_INTP12	=23u,
	MCU_mWakeUpID_INTP9 	=24u,
	MCU_mWakeUpID_INTP13	=25u,
	MCU_mWakeUpID_INTP14	=26u,
	MCU_mWakeUpID_INTP15	=27u,
	MCU_mWakeUpID_INTRTCA01S	=28u,
	MCU_mWakeUpID_INTRTCA0AL	=29u,
	MCU_mWakeUpID_INTRTCA0R 	=30u,
	MCU_mWakeUpID_INTDCUTDI 	=31u,
	MCU_mWakeUpID_INTADCA0I0	=32u,
	
	/*WU_ISO  = factor1*/
	MCU_mWakeUpID_INTADCA0I1	=33u,	
	MCU_mWakeUpID_INTADCA0I2	=34u,
	MCU_mWakeUpID_INTRLIN30 	=35u,
	MCU_mWakeUpID_INTTAUJ0I0_Iso	=36u,
	MCU_mWakeUpID_INTTAUJ0I1_Iso	=37u,
	MCU_mWakeUpID_INTTAUJ0I2_Iso	=38u,
	MCU_mWakeUpID_INTTAUJ0I3_Iso	=39u,
	MCU_mWakeUpID_INTRLIN31 	=40u,
	MCU_mWakeUpID_INTRLIN32 	=41u,
	MCU_mWakeUpID_INTRTCA01S_Iso	=42u,
	MCU_mWakeUpID_INTRTCA0AL_Iso	=43u,
	MCU_mWakeUpID_INTRTCA0R_Iso 	=44u,
	MCU_mWakeUpID_INTRLIN33 	=45u,
	MCU_mWakeUpID_INTRLIN34 	=46u,
	MCU_mWakeUpID_INTRLIN35 	=47u,
	
	/*WU_20  = factor2*/
	MCU_mWakeUpID_Fill2	=48u,
	MCU_mWakeUpID_INTKR0	=49u,
	MCU_mWakeUpID_INTRCANGRECC	=50u,
	MCU_mWakeUpID_INTRCAN0REC	=51u,
	MCU_mWakeUpID_INTRCAN1REC	=52u,
	MCU_mWakeUpID_INTRCAN2REC	=53u,
	MCU_mWakeUpID_INTRCAN3REC	=54u,
	MCU_mWakeUpID_INTRCAN4REC	=55u,
	MCU_mWakeUpID_INTRCAN5REC	=56u,
	
}MCU_enWakeFactorID;
#if 0
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
#endif
 /********************************************************
 
	CSIG Module resource list
 
 ********************************************************/
 typedef enum
 {
	MCU_mCSIG_0=0u,
	MCU_mCSIG_1=1u,
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
	MCU_mCSIH_2=2u,
	MCU_mCSIH_3=3u,
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


