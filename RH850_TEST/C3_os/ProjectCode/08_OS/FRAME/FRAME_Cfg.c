/*******************************************************************************
| Module Name: Task config
| File Name: os_framecfg.c
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
|2016.4.14      a2.2             Li Ning		the first version for integration

********************************************************************************/

#ifndef OS_Framecfg
#define OS_Framecfg

/* System-headerfiles */

#include "FRAME.h"
#include "FRAME_cfg.h"

#include "pow.h"
#include "ign.h"


#if (FRAME_RteUsed==1)
#include "Rte.h"
#include "Rte_Sys.h"
#endif

/* Foreign headerfiles */
//#include "sbc.h"


/*------------------------task schedule------------------------------*/

/* wdg for task*/
#if(Frame_TaskWdgCfg==1)
const FRAME_AppWdgCfgType Frame_auAllTaskWdg[Frame_nTaskMax]=
{
	/*task1 10ms, task2 100ms, task3 reserve*/
	/*   task  id			MaxTime,		MaxCounter    if reset			functionL1	funL2: Maxtime count 1 per 10ms*/
  	{Frame_nTask1, 		4,			1,			1, 			NULL ,		NULL},
  	{Frame_nTask2, 		70,			1,			1, 			NULL,		NULL  },	  	
  	{Frame_nTask3, 		800,			2,			1, 			NULL,		NULL  },	  	
};


#endif

/*-----------foreground task list of schedule Active--------------*/
 const ThreadAction FRAME_axForegroundActiveThread[]={
	{ &FRAME_vFrameForegroundTick1s },
       /*here add app and bus main function	*/
	
	{ &FRAME_vFRAME_ForegroundReset }	
};

/*----------- foreground task list of schedule On--------------*/
const ThreadAction FRAME_axForegroundOnThread[]={
	#if (DebugOS_MaxLoadRate==1)
	{&OS_vMaxLoadStatisticStart},
	#endif
	{ &FRAME_vFrameForegroundTick1s },
	/*-------don't modify the above code-----*/
	/* add app and bus main function below	*/
	{&IGN_vMain},
	{&IGN_vMain},
		
  	{ &FRAME_vFRAME_ForegroundReset }
};


/*----------- background task list of schedule Active--------------*/
const ThreadAction FRAME_axBackgroundActiveThread[]={
	{&FRAME_vFrameBackgroundTick1s },		
	/*here add app and bus main function	*/
	
	{&FRAME_vFRAME_BackgroundReset },
};

/*-----------backgroud task list of schedule On--------------*/
const ThreadAction FRAME_axBackgroundOnThread[]={
	{ &FRAME_vFrameBackgroundTick1s },	
	/* add app and bus main function below	*/
	
	{&POW_vMain},
	{&POW_vMain},
	/*-------don't modify the below code-----*/
	/*task reset*/
	#if (DebugOS_MaxLoadRate==1)
	{&OS_vMaxLoadStatisticEnd},
	#endif
	{ &FRAME_vFRAME_BackgroundReset }	
	
};



/*-----------1ms task expended time must be less than 100us--------------*/
void FRAME_v1msTaskSchedule(void)
{
	/****1ms task below here******/
	
}


/*------------------------------------------
	1.always run task no matter k15 on or off
	2.run before all the app task 
	3.run per 10ms
	4.be care the perform time of task
--------------------------------------------*/
void FRAME_vExtAlwaysTaskSchedule(void)
{
	/****always task below here******/
	//SBC_vMain();
	//SBC_WDFeedDog();
}



/*-----------------------------app and bus --------------------------------*/

/*****************************************************************************
 Function      : FRAME_vFrameResetApp                                             *
 Description   : os main loop reset for app and bus       .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vMainLoop for app and bus
*****************************************************************************/
void FRAME_vFrameResetExt (void)
{
//   	SBC_vReset();
}


/*****************************************************************************
 Function      : FRAME_vFrameWakeUpApp                                             *
 Description   : action when system wake up from standb state   for app and bus     .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vFrameStandbyActive for app and bus
*****************************************************************************/
void FRAME_vFrameWakeUpExt (void)
{
	
}



/*****************************************************************************
 Function      : FRAME_vFrameActiveOnApp                                            *
 Description   : action when system state change from active to On   for app and bus                          *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vCONActionActiveOn for app and bus
*****************************************************************************/
void FRAME_vFrameActiveOnExt (void)
{	
   
}



/*****************************************************************************
 Function      : FRAME_vFrameOnActiveApp                                             *
 Description   : action when system state change from On to Active for app and bus      .                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vCONActionOnActive for app and bus
*****************************************************************************/
void FRAME_vFrameOnActiveExt (void)
{	
  
}



/*****************************************************************************
 Function      : FRAME_vFrameStandbyActiveApp                                             *
 Description   : action when system state change from Standby to Active for app and bus                *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by OS_vSysCONActionStandbyActiveApp
*****************************************************************************/
void FRAME_vFrameStandbyActiveExt(void)
{
	
}



/*****************************************************************************
 Function      : FRAME_vFrameActiveStandbyCfgIoApp                                             *
 Description   : action when system state change from Active to Standby for app and bus      .           *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by OS_vSysCONActionActiveStandbyApp
*****************************************************************************/
void FRAME_vFrameActiveStandbyCfgIOExt(void)
{
	
}



/*****************************************************************************
 Function      : FRAME_vFrameActiveStandbyApp                                             *
 Description   : action when system state change from Active to Standby for app and bus      .              *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vCONActionActiveStandby for app and bus
*****************************************************************************/
void FRAME_vFrameActiveStandbyExt(void)
{
       
	FRAME_vFrameActiveStandbyCfgIOExt();
	
}



void FRAME_vFrameUnusedPinCfg(void)
{

		
		
}



#if (FRAME_RteUsed== 1)
	/*for complier pass*/
	/*Std_ReturnType Rte_AcccProto_AcccForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_AirdProto_AirdForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_Bctl1Proto_BctlForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_Bctl2Proto_BctlDrvForceControl(uint32 ForceIoControlWord) 
	{return(1);}


	Std_ReturnType Rte_CcsProto_CcsForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_CtsProto_CtsForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DcmProto_DcmForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DimProto_DimForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_ClearAllDtc(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_DtcForceIoControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_GetExtendData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_GetMaskFaultDtcList(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_GetMaskFaultDtcNum(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_GetSnapShotData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DiagProto_GetSupportDtcList(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_ClearAllDtc(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_DtcForceIoControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetExtendData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetMaskFaultDtcList(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetMaskFaultDtcNum(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetSnapShotData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetSupportDtcList(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_EvapProto_EvapForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_HctProto_HctForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_IctProto_IctForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_IonProto_IonForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_Istp_IstpForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_KeyProto_KeyForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_MacProto_MacForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_MmiProto_MmiForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_Ncv77x9_Ncv77x9ForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_OatProto_OatForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_RevProto_RevForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_RfaProto_RfaForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_SunProto_SunForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_VelProto_VelForceControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Eed_u8ReadGroupData(EedData portDefArg1, EedData * EedData, EedDataLen EedDataLen)
	{return(1);}

	Std_ReturnType Eed_u8WriteGroupData(EedData portDefArg1, EedData * EedData, EedDataLen EepDataLen)
	{return(1);}
	
	Std_ReturnType Rte_RdcProto_RdcForceControl(UInt32 ForceIoControlWord)
	{return(1);}
	
	Std_ReturnType Rte_AqsProto_AqsForceControl(uint32 ForceIoControlWord) 
	{return(1);}*/

	Std_ReturnType Rte_DtcProto_ForceIoControl(UInt32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_ClearAllDtc(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_DtcForceIoControl(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetExtendData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetMaskFaultDtcList(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetMaskFaultDtcNum(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetSnapShotData(uint32 ForceIoControlWord) 
	{return(1);}

	Std_ReturnType Rte_DtcProto_GetSupportDtcList(uint32 ForceIoControlWord) 
	{return(1);}



   
	

#endif

/*****************************don't modify below**************************************/

/*****************************************************************************
 Function      : FRAME_axGetForegroundActiveThread                                             *
 Description   : reculate the lenth of oregroundActiveThread       .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vMainLoop
*****************************************************************************/

uint8 FRAME_axGetForegroundActiveThread(void)
{
	uint8 u8lenth;
	u8lenth=sizeof(FRAME_axForegroundActiveThread)/sizeof(ThreadAction);
       return u8lenth;
}

/*****************************************************************************
 Function      : FRAME_axGetForegroundOnThread                                             *
 Description   : reculate the lenth of oregroundOnThread       .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vMainLoop
*****************************************************************************/

uint8 FRAME_axGetForegroundOnThread(void)
{
	uint8 u8lenth;
	u8lenth=sizeof(FRAME_axForegroundOnThread)/sizeof(ThreadAction);	
       return u8lenth;
}



/*****************************************************************************
 Function      : FRAME_axGetBackgroundActiveThread                                             *
 Description   : reculate the lenth of BackgroundActiveThread       .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vMainLoop
*****************************************************************************/

uint8 FRAME_axGetBackgroundActiveThread(void)
{
       return sizeof(FRAME_axBackgroundActiveThread)/sizeof(ThreadAction);
}

/*****************************************************************************
 Function      : FRAME_axGetBackgroundOnThread                                             *
 Description   : reculate the lenth of BackgroundOnThread       .                                       *
                                                             *
 Takes         : None                                              *
 Return Value  : None                                                        *
 Note: 	this function be call by FRAME_vMainLoop
*****************************************************************************/

uint8 FRAME_axGetBackgroundOnThread(void)
{
	uint8 u8lenth;
	u8lenth=sizeof(FRAME_axBackgroundOnThread)/sizeof(ThreadAction);
	return u8lenth;
}








/*****************************************************************************
 Function      : FRAME_u8TaskWdgDet                                 
 Description   : detect running time of all task
 Takes         : Nothing
 Return Value  : None                                                *
*****************************************************************************/
void FRAME_vTaskWdgDet(void)
{
	
	#if (Frame_TaskWdgCfg==1)	
		uint8 i=0;	
		for(; i<Frame_nTaskMax;i++)
		{
			if(Frame_RunningTick[i]<Frame_auAllTaskWdg[i].u16MaxTick)
			{
				Frame_RunningTick[i]++;
			}
			else
			{
				/*clear tick*/
				Frame_RunningTick[i]=0;

				
				if(Frame_OverflowTick[i]<Frame_auAllTaskWdg[i].u8OverflowCounter)
				{
					Frame_OverflowTick[i]++;
				}

				/*overflow process*/
				if(Frame_auAllTaskWdg[i].u8ResetMCU==True)
				{
					//Level1
					if(Frame_OverflowTick[i]==OverflowL1)
					{
						if(Frame_auAllTaskWdg[i].vfunTaskWdgprocL1!=NULL)
						{
							Frame_auAllTaskWdg[i].vfunTaskWdgprocL1();
						}					
					}

					//Level2
					if(Frame_OverflowTick[i]==OverflowL2)
					{
						if(Frame_auAllTaskWdg[i].vfunTaskWdgprocL2!=NULL)
						{
							Frame_auAllTaskWdg[i].vfunTaskWdgprocL2();
						}					
					}
					
				}
				else
				{
					//do noting
				}
			}
				
		}
		  
	#endif
	
}


#endif
/*****************************************************************************
* EOF:
******************************************************************************/










