/*******************************************************************************
| Module Name: Task interface
| File Name: Frame_If.c
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

|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 
|
|2016.5.13      a2.2             Li Ning		the first version for integration

********************************************************************************/

#ifndef Frame_If
#define Frame_If

/* System-headerfiles */
#include "Mcu_cfg.h"
/* Own headerfiles */
#include "frame_if.h"
#include "frame_cfg.h"
#include "frame_type.h"


/* Foreign headerfiles */


#if (FRAME_RteUsed==1)
//#include "Rte.h"
//#include "Rte_Sys.h"
#endif

#include "POW.h"
#include "IGN.h"
#include "IGN_cfg.h"
//#include "hal.h"



#if (FRAME_AppSleep==1)
/*****************************************************************************
 Function      : FRAME_vGetAspSleepStatus                                             *
 Description   : read sleep status of app module      .              *     *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                        *
 Note: 
*****************************************************************************/
 uint8 FRAME_vGetAspSleepStatus(void)
{
	/*sleep condition
	1:eeprom
	2.ict
	*/
	uint8 u8retvalue;
	u8retvalue=1;
	/*add sleep condition of app below*/
	/*get value from module directly*/
	
		if((1)
		#if (FRAME_EedSleep==1)
			&&(EED_u8GetValue(EED_nu8EnableSleep)==1)
		#endif		
		#if (FRAME_CtsSleep==1)
			&&(CTS_u8GetValue(CTS_nu8EnableSleep)==1)
		#endif
		)
		{
			u8retvalue=1;
		}
		else
		{
			u8retvalue=0;
		}
	
	
	return (u8retvalue);
	
}
#endif

#if (FRAME_BusSleep==1)
/*****************************************************************************
 Function      : FRAME_vGetBusSleepStatus                                             *
 Description   : read sleep status of app module      .              *     *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                         *
 Note: 
*****************************************************************************/
 uint8 FRAME_vGetBusSleepStatus(void)
{
	uint8 u8retvalue;
	u8retvalue=1;
	/*add sleep condition of bus below*/
	/*get value from module directly*/
	
	if((1)
		#if (FRAME_CanBusSleep==1)
			&&(CANAPP_u16GetValue(CANAPP_nu8EnableSleep)==1)
		#endif		
		#if (FRAME_LinBusSleep==1)
			&&(LINAPP_u8GetValue(LINAPP_nu8EnableSleep)==1)
		#endif
		#if (FRAME_KBusSleep==1)
			&&(KLINEAPP_u8GetValue(KLINE_nu8EnableSleep)==1)
		#endif
	)
	{
		u8retvalue=1;
	}
	else
	{
		u8retvalue=0;
	}
		
	
	return (u8retvalue);

	
}
#endif

#if (FRAME_RemoteSleep==1)
/*****************************************************************************
 Function      : FRAME_vGetRemoteSleepStatus                                             *
 Description   : read sleep status of remote signal      .              *     *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                         *
 Note: 
*****************************************************************************/
 uint8 FRAME_vGetRemoteSleepStatus(void)
{
	uint8 u8retvalue;
	u8retvalue=1;
	/*add sleep condition of remote signal below*/
	/*get value from module directly*/
	#if (FRAME_RteUsed==1)
		
	#else
	
	#endif
	return (u8retvalue);
	
}
#endif


/******************************************************************************************************
******************************************import functon definition*****************************************
*******************************************************************************************************/

/*****************************************************************************
 Function      : FRAME_vImpIDIgnStaticOn                                             *
 Description   :get staticOn                        *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vImpIDIgnStaticOn(void)
{
	uint16 u16retvalue;
	
	u16retvalue=IGN_u16GetValue(IGN_nu16IgnStaticOn);
	
	
	return(u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vImpIDIgnStable                                             *
 Description   :get stable                        *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vImpIDIgnStable(void)
{
	uint16 u16retvalue;
	
	u16retvalue=IGN_u16GetValue(IGN_nu16IgnStable);
	
	
	return(u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vImpIDIgnIgn2IoStauts                                             *
 Description   :get ign2 io staus from ign module                       *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vImpIDIgnIgn2IoStauts(void)
{
	uint16 u16retvalue;
	
	u16retvalue=IGN_u16GetValue(IGN_nu16IGN2IoStatus);
	
	
	return(u16retvalue);
}


/*****************************************************************************
 Function      : FRAME_vImpIDIgnIgn2IoStauts                                             *
 Description   :get ign2 io staus from hal  immediately                     *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                         *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vImpIDHalIgn2IoStauts(void)
{
	uint16 u16retvalue;
	uint8 u8temp;
	u8temp=u8temp;
	u16retvalue=1;
	/*if use ign from bus , it need not judge when bus sleep*/
	#if(FRAME_HwIgnUsed==1)
		MCU_u16PinRead((MUC_enPinID)FRAME_nIGN2PortPin,&u8temp);		/*P06 set as k15 */
		u16retvalue=(uint16)u8temp;
		u16retvalue=(~u16retvalue)&0x0001;								/*k15 port set low then enable  sleep*/
	#endif
	
	


	
	
	
	return(u16retvalue);
}


/******************************************************************************************************
******************************************export functon definition*****************************************
*******************************************************************************************************/


/*****************************************************************************
 Function      : FRAME_vExpIDSysBackground1s                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vExpIDSysBackground1s(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	#if (FRAME_RteUsed ==1)			
		Rte_IWrite_Sys_vMain_SysPutFlag1000MS_BG_SysFlag(FRAME_u16Array[SYS_nu16Flag1000MS_BG] );
	#else
		/*getvalue:read data by getvalue function with no rte layer
		    here place nothing*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vExpIDSysForeground1s                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vExpIDSysForeground1s(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed ==1)			
		Rte_IWrite_Sys_vMain_SysPutFlag1000MS_FG_SysFlag(FRAME_u16Array[SYS_nu16Flag1000MS_FG] );
	#else
		/*getvalue:read data by getvalue function with no rte layer,
		    here place nothing*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
	
}

/*****************************************************************************
 Function      : FRAME_vExpIDSysInfo                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
static uint16 FRAME_vExpIDSysInfo(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed ==1)			
		Rte_IWrite_Sys_vMain_SysPutInfo_SysInfo(FRAME_u16Array[SYS_nu16Info]);
	#else
		/*getvalue:read data by getvalue function with no rte layer*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vExpIDSwVersion                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
static uint16 FRAME_vExpIDSwVersion(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed ==1)			
		Rte_IWrite_Sys_vMain_SysPutSwVersion_Version(FRAME_u16Array[SYS_nu16SwVersion]);
	#else
		/*getvalue:read data by getvalue function with no rte layer*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}


/*****************************************************************************
 Function      : FRAME_vExpIDErrorCode                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
static uint16 FRAME_vExpIDErrorCode(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed ==1)			
		Rte_IWrite_Sys_vMain_SysPutErrorCode_u16ErrorCode(FRAME_u16Array[SYS_nu16ErrorCode]);
	#else
		/*getvalue:read data by getvalue function with no rte layer*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vExpIDSwInitTime                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
static uint16 FRAME_vExpIDSwInitTime(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed ==1)			
		#if (DebugOS_SwInitTime==1)
			Rte_IWrite_Sys_vMain_SysPutOSSwInitTimeOut_SysTimeOut(get_bSysSwInitCounter());
		#endif
	#else
		/*getvalue:read data by getvalue function with no rte layer*/
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vExpIDAll                                             *
 Description   :update the output  internal data                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vExpIDAll(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	FRAME_vExpIDSysBackground1s();
	FRAME_vExpIDSysForeground1s();
	FRAME_vExpIDSysInfo();
	FRAME_vExpIDSwVersion();
	FRAME_vExpIDErrorCode();
	FRAME_vExpIDSwInitTime();

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_u16GetValue                                             *
 Description   :other module get the variable from frame module      .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	the varible value which other module want to get. 
*****************************************************************************/
uint16 FRAME_u16GetValue(SYS_ten16VarNumber Num)
{
	uint16 u16Ret=0U;
	
	if(Num<SYS_nu16Max)
	{
		u16Ret= (FRAME_u16Array[Num]);
	}
	else
	{
		 u16Ret=(FRAME_u16Array[SYS_nu16Max-1U]);
	}
	
	return u16Ret;
}

/******************************************************************************************************
******************************************other functon definition*****************************************
*******************************************************************************************************/

/*****************************************************************************
 Function      : FRAME_vIfOpenRouser                                             *
 Description   :open wake up source                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vIfOpenRouser(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RouserIgnUsed ==1)			
		/* open the interrupt of k15  use both edge to deal with k15 high level when the system change to standby	*/
		
		MCU_u16EINTctrl(FRAME_IGN_EXT_ID,1);
	
	#endif

	#if (FRAME_RouserRemoteUsed ==1)			
		//MCU_u16EINTctrl(FRAME_REMOTE_EXT_ID,IGN_ifRemoteExternInterrupt);
	#endif

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vIfCloseRouser                                             *
 Description   :close wake up source                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vIfCloseRouser(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RouserIgnUsed ==1)			
		MCU_u16EINTctrl(FRAME_IGN_EXT_ID,0);
	#endif

	#if (FRAME_RouserRemoteUsed ==1)			
		
	#endif
	

	u16retvalue = 1;
	return (u16retvalue);
}

#if (DebugOS_MonitorTaskTimer==1)
/*****************************************************************************
 Function      : FRAME_vHalTaskTimeStart_DebugTimer                                             *
 Description   :start timer                         *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vHalTaskTimeStart_DebugTimer(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	MCU_vTAUxRunCtrl((MCU_enTauxID)HAL_DebugOSTimerID,1);	

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalTaskTimeStop_DebugTimer                                             *
 Description   :stop timer                         *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by FRAME_vFRAMEAlways
*****************************************************************************/
 uint16 FRAME_vHalTaskTimeStop_DebugTimer(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	MCU_vTAUxRunCtrl((MCU_enTauxID)HAL_DebugOSTimerID,0);

	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalTimerRegiste_DebugTimer                                             *
 Description   :                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 /*uint16 FRAME_vHalTimerRegiste_DebugTimer()
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_32bitUsed ==1)		
		HAL_vTimerRegiste(HAL_DebugOSTimerID,100U,0)
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}
*/
#endif

/*****************************************************************************
 Function      : FRAME_vHalTimerRegiste                                             *
 Description   :                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 /*uint16 FRAME_vHalTimerRegiste_SysTimer(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_32bitUsed ==1)		
		//HAL_vTimerRegiste(HAL_SystemTimerID,1000U,0);
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}*/

/*****************************************************************************
 Function      : FRAME_vHalStopMode                                             *
 Description   :stop mode                         *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: not used deepstop mode	
*****************************************************************************/
 uint16 FRAME_vHalStopMode(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	
	MCU_vStandbyCtrl_ChgToMode(MCU_mStopMode);
	

	u16retvalue = 1;
	return (u16retvalue);
}





/*****************************************************************************
 Function      : FRAME_vHalDI                                             *
 Description   :DI                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalDi(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	asm("DI");
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalEI                                             *
 Description   :EI                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalEi(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	asm("EI");
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalIgnMain                                             *
 Description   :ign main                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalIgnMain(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		Rte_IgnProto_Ign_vMain();			
	#else
		IGN_vMain();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalPowMain                                             *
 Description   :pow main                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalPowMain(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		Rte_PowProto_Pow_vMain();
	#else
		POW_vMain();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalIgnReset                                             *
 Description   :ign reset                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalIgnReset(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		IGN_vReset();			
	#else
		IGN_vReset();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalPowReset                                             *
 Description   :pow reset                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalPowReset(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		POW_vReset();			
	#else
		POW_vReset();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}



/*****************************************************************************
 Function      : FRAME_vHalIgnInit                                             *
 Description   :ign init                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalIgnInit(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		IGN_vInit();			
	#else
		IGN_vInit();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalPowInit                                             *
 Description   :pow init                           *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalPowInit(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_RteUsed == 1)
		POW_vInit();			
	#else
		POW_vInit();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}




/*****************************************************************************
 Function      : FRAME_vHalTimerRegiste                                             *
 Description   : sw watch dog clr                         *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalSwWdtReset(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	#if (FRAME_32bitUsed ==1)
		MCU_vWatchDogClean();
	#else
		MCU_vWatchDogClean();
	#endif
	
	u16retvalue = 1;
	return (u16retvalue);
}

/*****************************************************************************
 Function      : FRAME_vHalInit                                             *
 Description   : hal init                          *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vHalInit(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;

	u16retvalue = 1;
	return (u16retvalue);
}

/* ===========================================================================
* Function   : uint16 FRAME_vHWdogClr(void)
* Description: hardware wdg clr
* Input      : the variable number which other module want to get.
* Returns    : the varible value which other module want to get.
*/

uint16 FRAME_vHWdogClr( void)
{	
	uint16 u16flip;
	
	uint16 u16Ret=0U;

	u16flip=u16flip;
	
	#if (FRAME_HwWdgUsed==1)		
		u16flip++;
		u16flip&=0x01;
		MCU_u16PinWrite(FRAME_HWwatchdog_PortPin,u16flip);		
	#endif

	u16Ret=1;
	return u16Ret;
}

/* ===========================================================================
* Function   : uint16 FRAME_vRteProto_Update(void)
* Description: hardware wdg clr
* Input      : the variable number which other module want to get.
* Returns    : the varible value which other module want to get.
*/

uint16 FRAME_vRteProto_Update( void)
{	
	uint16 u16flip;
	
	uint16 u16Ret=0U;
	u16flip=u16flip;
	
	
	#if (FRAME_RteUsed==1)		
		Rte_SysProto_Sys_vMain();
	#else
		
	#endif

	u16Ret=1;
	return u16Ret;
}

/*****************************************************************************
 Function      : FRAME_vFinalSleepCheck                                             *
 Description   :be sure to go into sleep                           *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                        *
 Note: 	
*****************************************************************************/
 uint16 FRAME_vFinalSleepCheck(void)
{
	uint16 u16retvalue;
	u16retvalue = 0;
	
	if((1)
	#if (FRAME_HwIgnUsed==1)
		&&( FRAME_vImpIDHalIgn2IoStauts() == 1)
	#endif
	#if (FRAME_BusSleep==1)
		&&( FRAME_vGetBusSleepStatus() == 1)
	#endif
	#if (FRAME_AppSleep==1)
		&&( FRAME_vGetAspSleepStatus() == 1)
	#endif
	#if (FRAME_RemoteSleep==1)
		&&( FRAME_vGetRemoteSleepStatus() == 1)
	#endif	
	)
	{
		u16retvalue = 1;	/* enable sleep*/
	}
	else
	{
		u16retvalue = 0;	/* disable sleep*/
	}
	return (u16retvalue);
}

#if (FRAME_HwSBCUsed==1)
/*****************************************************************************
 Function      : FRAME_vDoSBCSleepCmd                                             *
 Description   : read sleep status of remote signal      .              *     *
 Takes         : None                                              *
 Return Value  : 1=enable sleep,0=disable sleep                                                         *
 Note: 
*****************************************************************************/
 uint16 FRAME_vDoSBCSleepCmd(void)
{
	uint16 u16retvalue;
	u16retvalue=1;
	/*add sleep condition of SBC signal below*/
	/*get value from module directly*/
	#if (FRAME_RteUsed==1)
		
	#else
	
	#endif
	return (u16retvalue);
	
}
#endif


/*****************************************************************************
 Function      : SYS_vPeripheralInit                                             *
 Description   :init for periphera                         *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function  be call by main function
*****************************************************************************/
void SYS_vPeripheralInit(void)
{
	
}

#endif


/*****************************************************************************
* EOF:
******************************************************************************/




