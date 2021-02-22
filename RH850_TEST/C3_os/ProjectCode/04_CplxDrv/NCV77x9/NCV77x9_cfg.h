/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE   DC Motor Driver for NCV77x9, 	                             ]
*-----------------------------------------------------------------------------
  .FILE   NCV77x9_cfg.c                                                      ]
   .AUTHOR [  tan fumin 				                                     ]
*-----------------------------------------------------------------------------
NOTE:
		This software package only for DC motor driver nvc771!
 	
 Version Date        Author                       Change
 -----------------------------------------------------------------------------
 Rev 1.0 2015-4-28   tan fumin         module template update. 
 
****************************** .FILE_HEADER_END ******************************/

#ifndef NCV77x9_CFG_H
#define NCV77x9_CFG_H

#define MDVR_UnderLoadDetEnable	0
#define MDVR_OverVoltageLockOutEnable	0
#define MDVR_HBSEL          1


#define MDVR_ChannelEnable_1	1
#define MDVR_ChannelEnable_2	1
#define MDVR_ChannelEnable_3	1
#define MDVR_ChannelEnable_4	1
#define MDVR_ChannelEnable_5	1
#define MDVR_ChannelEnable_6	1

#define OutPutChannel1			0
#define OutPutChannel2			1
#define OutPutChannel3			2
#define OutPutChannel4			3
#define OutPutChannel5			4
#define OutPutChannel6			5
#define OutPutChannel7		       6
#define OutPutChannel8			7
#define OutPutChannel9			8
#define OutPutChannel10			9
#define OutPutChannel11			10
#define OutPutChannel12			11
#define OutPutChannel13			12
#define OutPutChannel14			13
#define OutPutChannel15			14
#define OutPutChannel16			15


#define	MDVR_EnPin_PortID	HAL_mPortID_P10
#define	MDVR_EnPin_PinID	HAL_mPinID_9

#define MDVR_EnPinEnable()	HAL_PinWrite(MDVR_EnPin_PortID,MDVR_EnPin_PinID,1);\
						HAL_PinConfig(MDVR_EnPin_PortID,MDVR_EnPin_PinID,HAL_mPinOutput)
						
#define MDVR_EnPinDisable()	HAL_PinWrite(MDVR_EnPin_PortID,MDVR_EnPin_PinID,0);\
						HAL_PinConfig(MDVR_EnPin_PortID,MDVR_EnPin_PinID,HAL_mPinOutput)



#define  MDVR_u8ChannlMaks				((MDVR_ChannelEnable_1<<0)|\
									(MDVR_ChannelEnable_2<<1)|\
									(MDVR_ChannelEnable_3<<2)|\
									(MDVR_ChannelEnable_4<<3)|\
									(MDVR_ChannelEnable_5<<4)|\
									(MDVR_ChannelEnable_6<<5))

#endif

