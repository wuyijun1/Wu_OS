/*******************************************************************************
| Module Name: MCU Drive for Renesas RH850 serial
| File Name: _RH850.c
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
| 2016.12.26  V0.02	Tan, fumin	:fix PinRead function struct member
| 2017.01.17  V0.03	Tan, fumin	:Add function MCU_u16PinAltFunCfg
| 2017.04.27  V0.04	Tan, fumin	:modify port module for PODC control and IIC pin setting in usrcfg attributtion
| 2017.05.05  V0.05	Tan, fumin	:change CSIG,CSIH interface name
********************************************************************************/

#ifdef MCU_C
/*This file ONLY include in MCU.c for compiler*/

/*this variable use for controlling the interrupt nest count*/
volatile uint32 MCU_IntNest=0U;

/*this variable use for recording current reset factor*/
uint32 MCU_u32ResetReason=0;

/*this variable use for recording all clock running frequency*/
MCU_tstClockRunStatus MCU_stClockStatus;

#if (MCU_mPortModuleEnable!=0u)

/*****************************************************************************
 Function  : MCU_u16PortInit_Port												 
 Description   :global port attribute configeration in reset, this function only config the Px ports
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop

 			it must note that the P0_0 is output mode and Open-D is enable by any reset!
 			
*****************************************************************************/
static uint16 MCU_u16PortInit_Port(void)
{
	uint32 u32PortIndex,u32PinIndex,u32ListIndex=0ul,u32MaskBit;
	uint32 u32PinAltFun,u32NeedUpdateReg=0ul;
	
	uint32 PMn,PMCn,PIBCn,PFCn,PFCEn,PFCAEn,Pn,PUn,PDn,PISn,PDSCn,PODCn,PBDCn;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u32PortIndex=0u;u32PortIndex<MCU_stPortAttribute.TottalPortNumber_Port;u32PortIndex++)
	{
		u32MaskBit=1u;
		PMn=0xFFFFFFFFul;PMCn=0ul;	PIBCn=0ul;
		PFCn=0ul;	PFCEn=0ul;	PFCAEn=0ul;
		Pn=0ul;		PUn=0ul;		PDn=0ul;
		PISn=0ul;	PDSCn=0ul;      PODCn=0ul;
                  PBDCn=0ul;
		u32NeedUpdateReg = MCU_MaxPinPerPort;
		for(u32PinIndex=0;u32PinIndex<MCU_MaxPinPerPort;u32PinIndex++)
		{
			u32MaskBit=1u<<u32PinIndex;
			u32PinAltFun = MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].AltFun;
			
			if(u32PinAltFun == 0xFFu)
			{
				u32NeedUpdateReg--;
			}
			else
			{	
				if(u32PinAltFun == GPIO_In)
				{
					PMn |=u32MaskBit;
					PIBCn |=u32MaskBit;
				}
				else if(u32PinAltFun == GPIO_Out)
				{
					PMn &=~u32MaskBit;
					if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].ResetLevel !=0u)
					{
						Pn |=u32MaskBit;
					} 
				}
				else
				{
					u32PinAltFun -=2u; /*set to AltFun Index!*/
					
					PMCn |=u32MaskBit;/*AltFun Setting*/
					
					if((u32PinAltFun&1ul) == 0ul)
					{
						PMn 	&=~u32MaskBit;	
					}
					if((u32PinAltFun&2) != 0ul)
					{
						PFCn |=u32MaskBit;	
					}
					if((u32PinAltFun&4) != 0ul)
					{
						PFCEn |=u32MaskBit;	
					}
					if((u32PinAltFun&8) != 0ul)
					{
						PFCAEn |=u32MaskBit;	
					}
					/*PIPC not setting!!!*/
				}

				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].PullDownEnable!=0u)
				{
					PDn |=u32MaskBit;
				}
				
				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].PullUpEnable !=0u)
				{
					PUn |=u32MaskBit;
				}	
				
				
				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].OpenDEnable !=0u)
				{
					PODCn|=u32MaskBit;
				}
				
				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].PinPutBufType!=0u)
				{
					PISn|=u32MaskBit;
				}	
				
				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].PinHighSpeedEnable!=0u)
				{
					PDSCn|=u32MaskBit;
				}	
				if(MCU_stPortAttribute.PinCfgHead_Port[u32ListIndex].PbdcEnable!=0u)
				{
					PBDCn|=u32MaskBit;
				}	
				
			}

			/*pionte to next pin setting!!!!*/
			u32ListIndex++;
			
		/*end of pin index looper!!*/
		}
		
		
		/*Update port group register value!!!!!*/
		if(u32NeedUpdateReg !=0ul)
		{
			u32NeedUpdateReg=0ul;
			
			DI();
			
	/*****RH850_F1X serial**************/			
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
			
			MCU_stPortAttribute.PortAddr->PIBC[u32PortIndex].u16Value=0;
			MCU_stPortAttribute.PortAddr->PBDC[u32PortIndex].u16Value=0;
			MCU_stPortAttribute.PortAddr->PM[u32PortIndex].u16Value = 0xFFFF;
			MCU_stPortAttribute.PortAddr->PMC[u32PortIndex].u16Value =0;
			MCU_stPortAttribute.PortAddr->PIPC[u32PortIndex].u16Value =0;
			
			MCU_stPortAttribute.PortAddr->PDSC[u32PortIndex] =PDSCn;
			MCU_stPortAttribute.PortAddr->PU[u32PortIndex].u16Value =(uint16)PUn;
			MCU_stPortAttribute.PortAddr->PD[u32PortIndex].u16Value =(uint16)PDn;
			MCU_stPortAttribute.PortAddr->PIS[u32PortIndex].u16Value =(uint16)PISn;
			
			MCU_stPortAttribute.PortAddr->PFC[u32PortIndex].u16Value =(uint16)PFCn;
			MCU_stPortAttribute.PortAddr->PFCE[u32PortIndex].u16Value =(uint16)PFCEn;
			MCU_stPortAttribute.PortAddr->PFCAE[u32PortIndex].u16Value =(uint16)PFCAEn;	
			
			MCU_stPortAttribute.PortAddr->PIPC[u32PortIndex].u16Value =0;

			MCU_stPortAttribute.PortAddr->P[u32PortIndex].u16Value =(uint16)Pn;
			MCU_stPortAttribute.PortAddr->PMC[u32PortIndex].u16Value =(uint16)PMCn;
			MCU_stPortAttribute.PortAddr->PM[u32PortIndex].u16Value = (uint16)PMn;
			MCU_stPortAttribute.PortAddr->PIBC[u32PortIndex].u16Value=(uint16)PIBCn;
			MCU_stPortAttribute.PortAddr->PBDC[u32PortIndex].u16Value=(uint16)PBDCn;

                            /*Open-D setting*/
			if(u32PortIndex <=8){
			    	MCU_stPortAttribute.PODCProtectCMD[0]->Commond=0xa5;
			}
			else{
				MCU_stPortAttribute.PODCProtectCMD[1]->Commond=0xa5;
			}
			MCU_stPortAttribute.PortAddr->PODC[u32PortIndex] =PODCn;
			MCU_stPortAttribute.PortAddr->PODC[u32PortIndex] =~PODCn;
			MCU_stPortAttribute.PortAddr->PODC[u32PortIndex] =PODCn;
			
		
	/*****RH850_D1X serial**************/			
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	
		if(u32PortIndex !=0ul)
		{
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PIBC.u16Value=0;
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PBDC.u16Value=0;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PM.u16Value = 0xFFFF;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PMC.u16Value =0;
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PIPC.u16Value=0;


			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PDSC =PDSCn;
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PU.u16Value =(uint16)PUn;
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PD.u16Value =(uint16)PDn;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PFC.u16Value =(uint16)PFCn;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PFCE.u16Value =(uint16)PFCEn;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PFCAE.u16Value =(uint16)PFCAEn;
			
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PIPC.u16Value=0;

			MCU_stPortAttribute.PortAddr[u32PortIndex].P.u16Value =(uint16)Pn;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PMC.u16Value =(uint16)PMCn;
			MCU_stPortAttribute.PortAddr[u32PortIndex].PM.u16Value = (uint16)PMn;
			
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PIS.u16Value =(uint16)PISn;
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PIBC.u16Value=(uint16)PIBCn;		
			MCU_stPortAttribute.PortAddrExt[u32PortIndex].PBDC.u16Value=(uint16)PBDCn;

			/*Open-D setting*/
			MCU_stPortAttribute.PortProtectAddr->Commond=0xa5;
			MCU_stPortAttribute.PortAddrExt_P0[u32PortIndex].PODC =PODCn;
			MCU_stPortAttribute.PortAddrExt_P0[u32PortIndex].PODC =~PODCn;
			MCU_stPortAttribute.PortAddrExt_P0[u32PortIndex].PODC =PODCn;
			
		}
		else
		{
			MCU_stPortAttribute.PortAddrExt_P0[0].PBDC.u16Value=0;
			MCU_stPortAttribute.PortAddrExt_P0[0].PIBC.u16Value=0;
			MCU_stPortAttribute.PortAddr_P0[0].PM.u16Value = 0xFFFF;
			MCU_stPortAttribute.PortAddr_P0[0].PMC.u16Value =0;
			MCU_stPortAttribute.PortAddrExt_P0[0].PIPC.u16Value=0;


			MCU_stPortAttribute.PortAddrExt_P0[0].PDSC =PDSCn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PU.u16Value =(uint16)PUn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PD.u16Value =(uint16)PDn;
			MCU_stPortAttribute.PortAddr_P0[0].PFC.u16Value =(uint16)PFCn;
			MCU_stPortAttribute.PortAddr_P0[0].PFCE.u16Value =(uint16)PFCEn;
			MCU_stPortAttribute.PortAddr_P0[0].PFCAE.u16Value =(uint16)PFCAEn;
			
			MCU_stPortAttribute.PortAddrExt_P0[0].PIPC.u16Value=0;

			MCU_stPortAttribute.PortAddr_P0[0].P.u16Value =(uint16)Pn;
			MCU_stPortAttribute.PortAddr_P0[0].PMC.u16Value =(uint16)PMCn;
			MCU_stPortAttribute.PortAddr_P0[0].PM.u16Value = (uint16)PMn;
			
			MCU_stPortAttribute.PortAddrExt_P0[0].PIBC.u16Value=(uint16)PIBCn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PIS.u16Value =(uint16)PISn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PBDC.u16Value=(uint16)PBDCn;

			MCU_stPortAttribute.PortProtectAddr_P0->Commond=0xa5;
			MCU_stPortAttribute.PortAddrExt_P0[0].PODC =PODCn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PODC =~PODCn;
			MCU_stPortAttribute.PortAddrExt_P0[0].PODC =PODCn;
		
		}
		
	#endif

		EI();
		
		}
			
	}


	return u16RetVal;
	
}

/*****************************************************************************
 Function  : MCU_u16PortInit_JPort												 
 Description   :global port attribute configeration in reset, this function only config the JPx ports
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16PortInit_JPort(void)
{
	uint32 u32PortIndex,u32PinIndex,u32ListIndex=0ul,u32MaskBit;
	uint32 u32PinAltFun,u32NeedUpdateReg=0ul;
	
	uint32 PMn,PMCn,PIBCn,PFCn,PFCEn,PFCAEn,Pn,PUn,PDn,PISn,PDSCn,PODCn,PBDCn;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u32PortIndex=0u;u32PortIndex<MCU_stPortAttribute.TottalPortNumber_JPort;u32PortIndex++)
	{
		u32MaskBit=1u;
		PMn=0xFFFFFFFFul;	PIBCn=0ul;  PODCn=0ul;
		PBDCn=0ul;
		
		u32NeedUpdateReg =MCU_MaxPinPerPort;
		for(u32PinIndex=0;u32PinIndex<MCU_MaxPinPerPort;u32PinIndex++)
		{
			u32MaskBit=1u<<u32PinIndex;
			u32PinAltFun = MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].AltFun;
			if(u32PinAltFun == 0xFFu)
			{
				u32NeedUpdateReg --;
			}
			else
			{								
				if(u32PinAltFun == GPIO_In)
				{
					PMn |=u32MaskBit;
					PIBCn |=u32MaskBit;
				}
				else if(u32PinAltFun == GPIO_Out)
				{
					PMn &=~u32MaskBit;
					if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].ResetLevel !=0u)
					{
						Pn |=u32MaskBit;
					} 
				}
				else
				{
					u32PinAltFun -=2u; /*set to AltFun Index!*/
					
					PMCn |=u32MaskBit;/*AltFun Setting*/
					
					if((u32PinAltFun&1ul) == 0ul)
					{
						PMn 	&=~u32MaskBit;	
					}
					if((u32PinAltFun&2) != 0ul)
					{
						PFCn |=u32MaskBit;	
					}
					if((u32PinAltFun&4) != 0ul)
					{
						PFCEn |=u32MaskBit;	
					}
					if((u32PinAltFun&8) != 0ul)
					{
						PFCAEn |=u32MaskBit;	
					}
					/*PIPC not setting!!!*/
				}

				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].PullDownEnable!=0u)
				{
					PDn |=u32MaskBit;
				}
				
				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].PullUpEnable !=0u)
				{
					PUn |=u32MaskBit;
				}	
				
				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].OpenDEnable !=0u)
				{
					PODCn|=u32MaskBit;
				}	
				
				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].PinPutBufType!=0u)
				{
					PISn|=u32MaskBit;
				}	
				
				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].PinHighSpeedEnable!=0u)
				{
					PDSCn|=u32MaskBit;
				}	
				if(MCU_stPortAttribute.PinCfgHead_JPort[u32ListIndex].PbdcEnable!=0u)
				{
					PBDCn|=u32MaskBit;
				}	
				
			}	
				
			/*pionte to next pin setting!!!!*/
			u32ListIndex++;
			
		}
	
	#if (MCU_UsingType > MCU_ID_RH850_F1L_Start  && MCU_UsingType<MCU_ID_RH850_F1L_End)
		/*Update port group register value!!!!!*/
		if(u32NeedUpdateReg !=0ul)
		{
			u32NeedUpdateReg=0ul;
			DI();
			MCU_stPortAttribute.JPortAddr->JPIBC[u32PortIndex].u8Value=0;
			MCU_stPortAttribute.JPortAddr->JPBDC[u32PortIndex].u8Value=0;
			MCU_stPortAttribute.JPortAddr->JPM[u32PortIndex].u8Value = 0xFF;
			MCU_stPortAttribute.JPortAddr->JPMC[u32PortIndex].u8Value =0;
			
			MCU_stPortAttribute.JPortAddr->JPU[u32PortIndex].u8Value =(uint8)PUn;
			MCU_stPortAttribute.JPortAddr->JPD[u32PortIndex].u8Value =(uint8)PDn;
			
			MCU_stPortAttribute.JPortAddr->JPFC[u32PortIndex].u8Value =(uint8)PFCn;
			
			MCU_stPortAttribute.JPortAddr->JP[u32PortIndex].u8Value =(uint8)Pn;
			MCU_stPortAttribute.JPortAddr->JPMC[u32PortIndex].u8Value =(uint8)PMCn;
			MCU_stPortAttribute.JPortAddr->JPM[u32PortIndex].u8Value = (uint8)PMn;
			MCU_stPortAttribute.JPortAddr->JPIBC[u32PortIndex].u8Value=(uint8)PIBCn;
			MCU_stPortAttribute.JPortAddr->JPBDC[u32PortIndex].u8Value=(uint8)PBDCn;

                            /*Open - D setting*/
			MCU_stPortAttribute.PODCProtectCMD[2]->Commond=0xa5;
			MCU_stPortAttribute.JPortAddr->JPODC[u32PortIndex] =PODCn;
			MCU_stPortAttribute.JPortAddr->JPODC[u32PortIndex] =~PODCn;
			MCU_stPortAttribute.JPortAddr->JPODC[u32PortIndex] =PODCn;

			EI();
			
		}	
		
	/*****RH850_D1X serial**************/			
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

		if(u32NeedUpdateReg !=0ul)
		{
			u32NeedUpdateReg=0ul;
			DI();

			MCU_stPortAttribute.JPortAddrExt_JP0[0].PBDC.u16Value=0;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PIBC.u16Value=0;
			MCU_stPortAttribute.JPortAddr_JP0[0].PM.u16Value = 0xFFFF;
			MCU_stPortAttribute.JPortAddr_JP0[0].PMC.u16Value =0;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PIPC.u16Value=0;


			MCU_stPortAttribute.JPortAddrExt_JP0[0].PDSC =PDSCn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PU.u16Value =(uint16)PUn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PD.u16Value =(uint16)PDn;
			MCU_stPortAttribute.JPortAddr_JP0[0].PFC.u16Value =(uint16)PFCn;
			MCU_stPortAttribute.JPortAddr_JP0[0].PFCE.u16Value =(uint16)PFCEn;
			MCU_stPortAttribute.JPortAddr_JP0[0].PFCAE.u16Value =(uint16)PFCAEn;
			
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PIPC.u16Value=0;

			MCU_stPortAttribute.JPortAddr_JP0[0].P.u16Value =(uint16)Pn;
			MCU_stPortAttribute.JPortAddr_JP0[0].PMC.u16Value =(uint16)PMCn;
			MCU_stPortAttribute.JPortAddr_JP0[0].PM.u16Value = (uint16)PMn;
			
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PIS.u16Value =(uint16)PISn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PIBC.u16Value=(uint16)PIBCn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PBDC.u16Value=(uint16)PBDCn;

                           MCU_stPortAttribute.JPortProtectAddr_JP0->Commond=0xa5;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PODC =PODCn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PODC =~PODCn;
			MCU_stPortAttribute.JPortAddrExt_JP0[0].PODC =PODCn;
			EI();
		}
		
#endif
	/*end of pin index looper!!*/
	}	
	
	return u16RetVal;
		
}

#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

/*****************************************************************************
 Function  : MCU_u16PortInit_APort												 
 Description   :global port attribute configeration in reset, this function only config the APx ports
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16PortInit_APort(void)
{
	uint32 u32PortIndex,u32PinIndex,u32ListIndex=0ul,u32MaskBit;
	uint32 u32PinAltFun,u32NeedUpdateReg=0ul;
	
	uint32 PMn,PIBCn,Pn,PBDCn;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u32PortIndex=0u;u32PortIndex<MCU_stPortAttribute.TottalPortNumber_APort;u32PortIndex++)
	{
		u32MaskBit=1u;
		PMn=0xFFFFFFFFul;	PIBCn=0ul;
		Pn=0ul;                             PBDCn=0ul;
		
		u32NeedUpdateReg =MCU_MaxPinPerPort;
		for(u32PinIndex=0;u32PinIndex<MCU_MaxPinPerPort;u32PinIndex++)
		{
			u32MaskBit=1u<<u32PinIndex;
			u32PinAltFun = MCU_stPortAttribute.PinCfgHead_APort[u32ListIndex].AltFun;
			
			if(u32PinAltFun == 0xFFu)
			{
				u32NeedUpdateReg--;
			}
			else
			{
				if(u32PinAltFun == GPIO_In)
				{
					PMn |=u32MaskBit;
					PIBCn |=u32MaskBit;
				}
				else if(u32PinAltFun == GPIO_Out)
				{
					PMn &=~u32MaskBit;
					if(MCU_stPortAttribute.PinCfgHead_APort[u32ListIndex].ResetLevel !=0u)
					{
						Pn |=u32MaskBit;
					} 
					if(MCU_stPortAttribute.PinCfgHead_APort[u32ListIndex].PbdcEnable!=0u)
					{
						PBDCn |=u32MaskBit;
					} 
				}
				else
				{
					/*PIPC not setting!!!*/
				}	
				
			}

			/*pionte to next pin setting!!!!*/
			u32ListIndex++;
			
		/*end of pin index looper!!*/
		}
		
		/*Update port group register value!!!!!*/
		if(u32NeedUpdateReg !=0ul)
		{
			u32NeedUpdateReg=0ul;
			DI();
			MCU_stPortAttribute.APortAddr->AP[u32PortIndex].u16Value =Pn;
			MCU_stPortAttribute.APortAddr->APM[u32PortIndex].u16Value = PMn;
			MCU_stPortAttribute.APortAddr->APIBC[u32PortIndex].u16Value=PIBCn;
			MCU_stPortAttribute.APortAddr->APBDC[u32PortIndex].u16Value=PBDCn;
			EI();
		}	
					
	}
	
	return u16RetVal;
		
}

/*****************************************************************************
 Function  : MCU_u16PortInit_IPort												 
 Description   :global port attribute configeration in reset, this function only config the IPx ports
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16PortInit_IPort(void)
{
	uint32 u32PortIndex,u32PinIndex,u32ListIndex=0ul,u32MaskBit;
	uint32 u32PinAltFun,u32NeedUpdateReg=0ul;
	
	uint32 PIBCn;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u32PortIndex=0u;u32PortIndex<MCU_stPortAttribute.TottalPortNumber_IPort;u32PortIndex++)
	{
		
		u32MaskBit=1u;
		PIBCn=0ul;

		u32NeedUpdateReg =MCU_MaxPinPerPort;
		for(u32PinIndex=0;u32PinIndex<MCU_MaxPinPerPort;u32PinIndex++)
		{
			u32MaskBit=1u<<u32PinIndex;
			u32PinAltFun = MCU_stPortAttribute.PinCfgHead_IPort[u32ListIndex].AltFun;
			
			if(u32PinAltFun == 0xFFu)
			{
				u32NeedUpdateReg--;
			}
			else
			{
				if(u32PinAltFun == GPIO_In)
				{
					PIBCn |=u32MaskBit;
				}
				else
				{
					DET_ErrReport(DET_Err_ParaOutOfRange);/*Pin input only*/
				}
			}	
			
			/*pionte to next pin setting!!!!*/
			u32ListIndex++;
				
		}

		
		/*Update port group register value!!!!!*/
		if(u32NeedUpdateReg !=0ul)
		{
			u32NeedUpdateReg=0ul;
			DI();
			MCU_stPortAttribute.IPortAddr->IPIBC[u32PortIndex].u16Value=PIBCn;
			EI();
		}	
		
	/*end of pin index looper!!*/
	}
	
	return u16RetVal;
		
}

#endif

/*****************************************************************************
 Function  : MCU_u16PortInit												 
 Description   :global port attribute configeration in reset, it is all port type initialization entry
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 
 			this function execute in reset before system-mainloop
*****************************************************************************/
static uint16 MCU_u16PortInit(void)
{
	MCU_u16PortInit_Port();
	MCU_u16PortInit_JPort();
	
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	MCU_u16PortInit_APort();
	MCU_u16PortInit_IPort();
	#endif

	return DET_Err_NotErr;
}

#if MCU_mPinDataOperEnable!=0u
/*****************************************************************************
 Function  : MCU_u16PinRead												 
 Description   : Read out hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			*u8PinValue : pionter of pin value output
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinRead(MUC_enPinID u16PinID, uint8 *u8PinValue)
{
	uint32 u32MaskBit;
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	uint16 u16RetVal=DET_Err_NotErr;
	

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_MaxPinPerPort, DET_Err_PinIndexOutOfRange);
		
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortType<MCU_mPinTypeID_Max, DET_Err_PortTypeOutOfRange);
	
	/*mask value for calc*/
	u32MaskBit = (uint32)(1u<<u16PinIndex);
	
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		*u8PinValue=((uint16)(MCU_stPortAttribute.PortAddr->PPR[u16PortIndex].u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_APort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_APort), DET_Err_PortIndexOutOfRange);

		DI();
		*u8PinValue=((uint16)(MCU_stPortAttribute.APortAddr->APPR[u16PortIndex].u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		*u8PinValue=((uint8)(MCU_stPortAttribute.JPortAddr->JPPR[u16PortIndex].u8Value & (uint8)u32MaskBit) ==0u) ? 0u : 1u;
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_IPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_IPort), DET_Err_PortIndexOutOfRange);

		DI();
		*u8PinValue=((uint16)(MCU_stPortAttribute.IPortAddr->IPPR[u16PortIndex].u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		EI();
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}

	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u16PortIndex !=0)
		{
			*u8PinValue=((uint16)(MCU_stPortAttribute.PortAddr[u16PortIndex].PPR.u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		}
		else
		{
			*u8PinValue=((uint16)(MCU_stPortAttribute.PortAddr_P0[0u].PPR.u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		}
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		*u8PinValue=((uint16)(MCU_stPortAttribute.JPortAddr_JP0[0u].PPR.u16Value & (uint16)u32MaskBit) ==0u) ? 0u : 1u;
		EI();
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}	
	#endif
	
	/*return the operation resault*/
	return u16RetVal;

}


/*****************************************************************************
 Function  : MCU_u16PinWrite												 
 Description   : write hardware Pin value
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			u8PinValue : expected pin value output
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinWrite(MUC_enPinID u16PinID,uint8 u8PinValue)
{
	uint32 u32MaskBit;

	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	uint16 u16RetVal=DET_Err_NotErr;
	

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_MaxPinPerPort, DET_Err_PinIndexOutOfRange);
		
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortType<MCU_mPinTypeID_Max, DET_Err_PortTypeOutOfRange);
	
	/*mask value for calc*/
	u32MaskBit = (uint32)(1u<<u16PinIndex);
	
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8PinValue ==0 )
		{
			MCU_stPortAttribute.PortAddr->P[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.PortAddr->P[u16PortIndex].u16Value |=(uint16)u32MaskBit;
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_APort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_APort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8PinValue ==0 )
		{
			MCU_stPortAttribute.APortAddr->AP[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.APortAddr->AP[u16PortIndex].u16Value |= (uint16)u32MaskBit;
		}
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8PinValue ==0 )
		{
			MCU_stPortAttribute.JPortAddr->JP[u16PortIndex].u8Value &=(uint8)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.JPortAddr->JP[u16PortIndex].u8Value |= (uint8)u32MaskBit;
		}
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_IPort)
	{
		/*Input only, cannot write pin value!*/
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}

	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u16PortIndex !=0)
		{
			if(u8PinValue !=0u)
			{
				MCU_stPortAttribute.PortAddr[u16PortIndex].P.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr[u16PortIndex].P.u16Value &=(uint16)(~ u32MaskBit);
			}
		}
		else
		{
			if(u8PinValue !=0u)
			{
				MCU_stPortAttribute.PortAddr_P0[0u].P.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr_P0[0u].P.u16Value &= (uint16)(~u32MaskBit);
			}
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8PinValue !=0u)
		{
			MCU_stPortAttribute.JPortAddr_JP0[0u].P.u16Value |= (uint16)u32MaskBit;
		}
		else
		{
			MCU_stPortAttribute.JPortAddr_JP0[0u].P.u16Value &= (uint16)(~u32MaskBit);
		}
		EI();
		
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}	
	#endif
	
	/*return the operation resault*/
	return u16RetVal;

}
#endif

#if (MCU_mPinDirectOperEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16PinDirectCfg												 
 Description   : pin data direction configuration
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			u8InOut : expected pin direction
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinDirectCfg(MUC_enPinID u16PinID,uint8 u8InOut)
{
	uint32 u32MaskBit;

	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	uint16 u16RetVal=DET_Err_NotErr;
	

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_MaxPinPerPort, DET_Err_PinIndexOutOfRange);
		
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortType<MCU_mPinTypeID_Max, DET_Err_PortTypeOutOfRange);
	
	/*mask value for calc*/
	u32MaskBit = (uint32)(1u<<u16PinIndex);
	
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8InOut ==0 )
		{
			MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value |= (uint16)u32MaskBit;
			MCU_stPortAttribute.PortAddr->PIBC[u16PortIndex].u16Value |= (uint16)u32MaskBit;
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_APort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_APort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8InOut ==0 )
		{
			MCU_stPortAttribute.APortAddr->APM[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.APortAddr->APM[u16PortIndex].u16Value |= (uint16)u32MaskBit;
			MCU_stPortAttribute.APortAddr->APIBC[u16PortIndex].u16Value |= (uint16)u32MaskBit;
		}
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8InOut ==0 )
		{
			MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u8Value &=(uint8)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u8Value |= (uint8)u32MaskBit;
			MCU_stPortAttribute.JPortAddr->JPIBC[u16PortIndex].u8Value |= (uint8)u32MaskBit;
		}
		EI();
	}
	else	if(u16PortType == MCU_mPinTypeID_IPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_IPort), DET_Err_PortIndexOutOfRange);
		
		if(u8InOut !=GPIO_In )
		{
			/*This port input only*/
			DET_ErrReport(DET_Err_CanNotWritePinDirct);
		}
		else
		{
			DI();
			MCU_stPortAttribute.IPortAddr->IPPR[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			MCU_stPortAttribute.IPortAddr->IPIBC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			EI();
		}

	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}

	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u16PortIndex !=0)
		{
			if(u8InOut !=0u)
			{
				MCU_stPortAttribute.PortAddr[u16PortIndex].PM.u16Value |= (uint16)u32MaskBit;
				MCU_stPortAttribute.PortAddrExt[u16PortIndex].PIBC.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr[u16PortIndex].PM.u16Value &=(uint16)(~ u32MaskBit);
			}
		}
		else
		{
			if(u8InOut !=0u)
			{
				MCU_stPortAttribute.PortAddr_P0[0u].PM.u16Value |= (uint16)u32MaskBit;
				MCU_stPortAttribute.PortAddrExt_P0[0u].PIBC.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr_P0[0u].PM.u16Value &=(uint16)( ~u32MaskBit);
			}
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8InOut !=0u)
		{
			MCU_stPortAttribute.JPortAddr_JP0[0u].PM.u16Value |= (uint16)u32MaskBit;
			MCU_stPortAttribute.JPortAddrExt_JP0[0u].PIBC.u16Value |= (uint16)u32MaskBit;
		}
		else
		{
			MCU_stPortAttribute.JPortAddr_JP0[0u].PM.u16Value &= (uint16)(~u32MaskBit);
		}
		EI();
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}	
	#endif
	
	/*return the operation resault*/
	return u16RetVal;

}

#endif

#if (MCU_mPinPullUpOperEnable!=0u)

/*****************************************************************************
 Function  : MCU_u16PinPullUpCfg												 
 Description   : pin pull up resister configuration
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			u8InOut : expected pin direction
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinPullUpCfg(MUC_enPinID u16PinID,uint8 u8OnOff)
{
	uint32 u32MaskBit;

	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	uint16 u16RetVal=DET_Err_NotErr;
	

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_MaxPinPerPort, DET_Err_PinIndexOutOfRange);
		
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortType<MCU_mPinTypeID_Max, DET_Err_PortTypeOutOfRange);
	
	/*mask value for calc*/
	u32MaskBit = (uint32)(1u<<u16PinIndex);
	
	/*======RH850 F1X serial======*/
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff ==0 )
		{
			MCU_stPortAttribute.PortAddr->PU[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.PortAddr->PU[u16PortIndex].u16Value |=(uint16)u32MaskBit;
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff ==0 )
		{
			MCU_stPortAttribute.JPortAddr->JPU[u16PortIndex].u8Value &=(uint8)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.JPortAddr->JPU[u16PortIndex].u8Value |= (uint8)u32MaskBit;
		}
		EI();
	}
	else	if((u16PortType == MCU_mPinTypeID_APort) ||(u16PortType == MCU_mPinTypeID_IPort))
	{
		/*No pull-up function*/
		DET_ErrReport(DET_Err_CanNotWritePinPullUp);
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}

	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u16PortIndex !=0)
		{
			if(u8OnOff !=0u)
			{
				MCU_stPortAttribute.PortAddrExt[u16PortIndex].PU.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddrExt[u16PortIndex].PU.u16Value &=(uint16)(~ u32MaskBit);
			}
		}
		else
		{
			if(u8OnOff !=0u)
			{
				MCU_stPortAttribute.PortAddrExt_P0[0u].PU.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddrExt_P0[0u].PU.u16Value &= (uint16)(~u32MaskBit);
			}
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff !=0u)
		{
			MCU_stPortAttribute.JPortAddrExt_JP0[0u].PU.u16Value |= (uint16)u32MaskBit;
		}
		else
		{
			MCU_stPortAttribute.JPortAddrExt_JP0[0u].PU.u16Value &= (uint16)(~u32MaskBit);
		}
		EI();
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}	
	#endif
	
	/*return the operation resault*/
	return u16RetVal;

}

#endif

#if (MCU_mPinPullDownOperEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16PinPullDownCfg												 
 Description   : pin pull down resister configuration
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			u8InOut : expected pin direction
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinPullDownCfg(MUC_enPinID u16PinID,uint8 u8OnOff)
{
	uint32 u32MaskBit;

	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	uint16 u16RetVal=DET_Err_NotErr;
	

	/*check Pin index is within range or not*/
	DET_ErrCheck(u16PinIndex<MCU_MaxPinPerPort, DET_Err_PinIndexOutOfRange);
		
	/*check Port index is within range or not*/
	DET_ErrCheck(u16PortType<MCU_mPinTypeID_Max, DET_Err_PortTypeOutOfRange);
	
	/*mask value for calc*/
	u32MaskBit = (uint32)(1u<<u16PinIndex);
	
	
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff ==0 )
		{
			MCU_stPortAttribute.PortAddr->PD[u16PortIndex].u16Value &=(uint16)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.PortAddr->PD[u16PortIndex].u16Value |= (uint16)(u32MaskBit);
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff ==0 )
		{
			MCU_stPortAttribute.JPortAddr->JPD[u16PortIndex].u8Value &=(uint8)(~ u32MaskBit);
		}
		else
		{
			MCU_stPortAttribute.JPortAddr->JPD[u16PortIndex].u8Value |= (uint8)(u32MaskBit);
		}
		EI();
	}
	else	if((u16PortType == MCU_mPinTypeID_APort) ||(u16PortType == MCU_mPinTypeID_IPort))
	{
		/*No pull-up function*/
		DET_ErrReport(DET_Err_CanNotWritePinPullDown);
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}

	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/*output the reading pin value final*/
	if(u16PortType == MCU_mPinTypeID_Port)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

		DI();
		if(u16PortIndex !=0)
		{
			if(u8OnOff !=0u)
			{
				MCU_stPortAttribute.PortAddrExt[u16PortIndex].PD.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddrExt[u16PortIndex].PD.u16Value &=(uint16)(~ u32MaskBit);
			}
		}
		else
		{
			if(u8OnOff !=0u)
			{
				MCU_stPortAttribute.PortAddrExt_P0[0u].PD.u16Value |= (uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddrExt_P0[0u].PD.u16Value &= (uint16)(~u32MaskBit);
			}
		}
		EI();
		
	}
	else	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		/*check Port index is in port group not*/
		DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

		DI();
		if(u8OnOff !=0u)
		{
			MCU_stPortAttribute.JPortAddrExt_JP0[0u].PD.u16Value |= (uint16)u32MaskBit;
		}
		else
		{
			MCU_stPortAttribute.JPortAddrExt_JP0[0u].PD.u16Value &= (uint16)(~u32MaskBit);
		}
		EI();
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}	
	#endif
	
	/*return the operation resault*/
	return u16RetVal;

}	
#endif

#if (MCU_mPinOpenDEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16PinOpenDCfg												 
 Description   : pin Open-Drain resister configuration
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			u8InOut : expected pin direction
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinOpenDCfg(MUC_enPinID u16PinID,uint8 u8OnOff)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	
	uint32 u32Group,u32WriteValue;
	
	/*======RH850 F1X serial======*/
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	DET_ErrCheck(((u16PortType == MCU_mPinTypeID_JPort) || (u16PortType == MCU_mPinTypeID_Port)), DET_Err_PortTypeOutOfRange);

	if(u16PortType == MCU_mPinTypeID_Port)
	{
            	if(u16PortIndex<=8)
            		u32Group=0;
            	else 
            		u32Group=1;
            		
            	u32WriteValue=MCU_stPortAttribute.PortAddr->PODC[u16PortIndex];
            	if(u8OnOff !=0u){
            		u32WriteValue |=(1<<u16PinID);
            	}
            	else{
            		u32WriteValue &=~(1<<u16PinID);
            	}
            	
                	DI();
                	MCU_stPortAttribute.PODCProtectCMD[u32Group]->Commond=0xa5;
                	MCU_stPortAttribute.PortAddr->PODC[u16PortIndex] =u32WriteValue;
                	MCU_stPortAttribute.PortAddr->PODC[u16PortIndex] =~u32WriteValue;
                	MCU_stPortAttribute.PortAddr->PODC[u16PortIndex] =u32WriteValue;
                	EI();
                	
	}
	else if(u16PortType == MCU_mPinTypeID_JPort)
	{
                	u32WriteValue=MCU_stPortAttribute.JPortAddr->JPODC[u16PortIndex];
             	if(u8OnOff !=0u){
            		u32WriteValue |=(1<<u16PinID);
            	}
            	else{
            		u32WriteValue &=~(1<<u16PinID);
            	}
               	
                	DI();
                	MCU_stPortAttribute.PODCProtectCMD[2]->Commond=0xa5;
		MCU_stPortAttribute.JPortAddr->JPODC[u16PortIndex] =u16PortIndex;
		MCU_stPortAttribute.JPortAddr->JPODC[u16PortIndex] =~u16PortIndex;
		MCU_stPortAttribute.JPortAddr->JPODC[u16PortIndex] =u16PortIndex;
                	EI();
	}
	else
	{
	        DET_ErrReport(DET_Err_CanNotWritePinOpenD);/*port not has this function*/
	}
	
	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	if(u16PortType == MCU_mPinTypeID_JPort)
	{
		u32WriteValue = MCU_stPortAttribute.JPortAddrExt_JP0->PODC;
		if(u8OnOff !=0)
			u32WriteValue |=1<<u16PinIndex;
		else
			u32WriteValue &=~(1<<u16PinIndex);
		
		MCU_stPortAttribute.JPortProtectAddr_JP0->Commond =0xa5;
		MCU_stPortAttribute.JPortAddrExt_JP0->PODC = u32WriteValue;
		MCU_stPortAttribute.JPortAddrExt_JP0->PODC =~u32WriteValue;
		MCU_stPortAttribute.JPortAddrExt_JP0->PODC = u32WriteValue;
		
	}
	else if(u16PortType == MCU_mPinTypeID_Port)
	{
		if(u16PortIndex == 0)
		{
			u32WriteValue = MCU_stPortAttribute.PortAddrExt_P0->PODC;
			if(u8OnOff !=0)
				u32WriteValue |=1<<u16PinIndex;
			else
				u32WriteValue &=~(1<<u16PinIndex);
			
			MCU_stPortAttribute.PortProtectAddr_P0->Commond =0xa5;
			MCU_stPortAttribute.PortAddrExt_P0->PODC = u32WriteValue;
			MCU_stPortAttribute.PortAddrExt_P0->PODC =~u32WriteValue;
			MCU_stPortAttribute.PortAddrExt_P0->PODC = u32WriteValue;
			
		}
		else
		{
			u32WriteValue = MCU_stPortAttribute.PortAddrExt[u16PortIndex].PODC;
			if(u8OnOff !=0)
				u32WriteValue |=1<<u16PinIndex;
			else
				u32WriteValue &=~(1<<u16PinIndex);
			
			MCU_stPortAttribute.PortProtectAddr->Commond =0xa5;
			MCU_stPortAttribute.PortAddrExt[u16PortIndex].PODC = u32WriteValue;
			MCU_stPortAttribute.PortAddrExt[u16PortIndex].PODC =~u32WriteValue;
			MCU_stPortAttribute.PortAddrExt[u16PortIndex].PODC = u32WriteValue;
		}
		
	}
	else
	{
		DET_ErrReport(DET_Err_ParaOutOfRange);
	}
		
	#endif

	
	/*return the operation resault*/
	return u16RetVal;
}
#endif

#if (MCU_mPinAltFunChgEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16PinAltFunCfg												 
 Description   : pin AltFun configuration
 
 In Parameter: 
 			u16PinID: Pin ID list in Head File
 			AltFun : expected pin AltFun
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: NULL
*****************************************************************************/
uint16 MCU_u16PinAltFunCfg(MUC_enPinID u16PinID,MCU_enPinAltFun AltFun)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	uint16 u16PinIndex=MCU_mMaskPinID(u16PinID);
	uint16 u16PortIndex=MCU_mMaskPortID(u16PinID);
	uint16 u16PortType=MCU_mMaskPortType(u16PinID);
	
	uint32 PMn=0,PIBCn=0,PMCn=0,u32MaskBit=0,PFCn=0,PFCEn=0,PFCAEn=0;
	

	u32MaskBit=1u<<u16PinIndex;
	if(AltFun == MCU_enPinAltFun_GPIO_In)
	{
		PMn =u32MaskBit;
		PIBCn =u32MaskBit;
	}
	else if(AltFun == MCU_enPinAltFun_GPIO_Out)
	{

	}
	else
	{
		AltFun -=2u; /*set to AltFun Index!*/
		PMCn =u32MaskBit;/*AltFun Setting*/
		
		if((AltFun&1ul) != 0ul)
		{
			PMn =u32MaskBit;
		}
		if((AltFun&2) != 0ul)
		{
			PFCn =u32MaskBit;	
		}
		if((AltFun&4) != 0ul)
		{
			PFCEn =u32MaskBit; 
		}
		if((AltFun&8) != 0ul)
		{
			PFCAEn =u32MaskBit;	
		}
		
	}

			/*======RH850 F1X serial======*/
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
		/*output the reading pin value final*/
		if(u16PortType == MCU_mPinTypeID_Port)
		{
			/*check Port index is in port group not*/
			DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);
		
			DI();
			if(PMn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCEn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFCE[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFCE[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCAEn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFCAE[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFCAE[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PMCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PMC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PMC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PIBCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PIBC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PIBC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			EI();
		}
		else	if(u16PortType == MCU_mPinTypeID_APort)
		{
			DET_ErrReport(DET_Err_PortIndexOutOfRange);
		}
		else	if(u16PortType == MCU_mPinTypeID_JPort)
		{
			/*check Port index is in port group not*/
			DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);
		
			DI();
			if(PMn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u8Value |=(uint8)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u8Value &=(uint8)~u32MaskBit;
			}
			if(PFCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPFC[u16PortIndex].u8Value |=(uint8)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPFC[u16PortIndex].u8Value &=(uint8)~u32MaskBit;
			}
			if(PFCEn!=0u)
			{
				DET_ErrReport(DET_Err_PortIndexOutOfRange);
			}
			if(PFCAEn!=0u)
			{
				DET_ErrReport(DET_Err_PortIndexOutOfRange);
			}
			if(PMCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPMC[u16PortIndex].u8Value |=(uint8)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPMC[u16PortIndex].u8Value &=(uint8)~u32MaskBit;
			}
			
			if(PIBCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPIBC[u16PortIndex].u8Value |=(uint8)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPIBC[u16PortIndex].u8Value &=(uint8)~u32MaskBit;
			}
			EI();

		}
		else	if(u16PortType == MCU_mPinTypeID_IPort)
		{
			DET_ErrReport(DET_Err_PortIndexOutOfRange);
		}
		else
		{
			DET_ErrReport(DET_Err_ParaOutOfRange);
		}
		
	/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		/*output the reading pin value final*/
		if(u16PortType == MCU_mPinTypeID_Port)
		{
			/*check Port index is in port group not*/
			DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_Port), DET_Err_PortIndexOutOfRange);

			DI();
			if(PMn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PM[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCEn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFCE[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFCE[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCAEn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PFCAE[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PFCAE[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PMCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PMC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PMC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PIBCn!=0u)
			{
				MCU_stPortAttribute.PortAddr->PIBC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.PortAddr->PIBC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			EI();
		}
		else	if(u16PortType == MCU_mPinTypeID_JPort)
		{
			/*check Port index is in port group not*/
			DET_ErrCheck((u16PortIndex < MCU_stPortAttribute.TottalPortNumber_JPort), DET_Err_PortIndexOutOfRange);

			DI();
			if(PMn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPM[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPFC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPFC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			if(PFCEn!=0u)
			{
				DET_ErrReport(DET_Err_PortIndexOutOfRange);
			}
			if(PFCAEn!=0u)
			{
				DET_ErrReport(DET_Err_PortIndexOutOfRange);
			}
			if(PMCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPMC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPMC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			
			if(PIBCn!=0u)
			{
				MCU_stPortAttribute.JPortAddr->JPIBC[u16PortIndex].u16Value |=(uint16)u32MaskBit;
			}
			else
			{
				MCU_stPortAttribute.JPortAddr->JPIBC[u16PortIndex].u16Value &=(uint16)~u32MaskBit;
			}
			EI();

		}
		else
		{
			DET_ErrReport(DET_Err_ParaOutOfRange);
		}
#endif


	/*return the operation resault*/
	return u16RetVal;
}
#endif

#endif/*end of port module*/


#if (MCU_mOSTMModuleEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16OSTMinit												 
 Description   : OS timer initialization 
 
 In Parameter: 
 			NULL
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 
 	NULL
*****************************************************************************/
static uint16 MCU_u16OSTMinit(void)
{
	uint32 u32Loop;
	uint32 u32Data;
	
	uint32 u32VectNum=MCU_stOSTMAttribute.IRQ_Num;
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	uint32 OSTMclk=MCU_stClockStatus.CPUCLK_Speed/2;
	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	uint32 OSTMclk=MCU_stClockStatus.ClkSpeed_CKSC_IOSTMS;
	#endif

	DI();
	for(u32Loop=0u;u32Loop<MCU_mOSTM_Mun;u32Loop++)
	{	

		u32Data=MCU_stOSTMAttribute.OSTM_Cfg[u32Loop].u32Interval_Us;
		if(u32Data >1)
		{
			/*update OSTMnCMP: counter number*/
			MCU_stOSTMAttribute.OSTM_BasicAddr[u32Loop].CMP =(MCU_stOSTMAttribute.OSTM_Cfg[u32Loop].u32Interval_Us * ( OSTMclk / MEGA(1)))  - 1;

			/*update OSTMnCTL:interval mode, and not interrupt when start*/
			MCU_stOSTMAttribute.OSTM_BasicAddr[u32Loop].CTL.u8Value=0;
			
			/*update OSTMnTE:Timer enable*/
			MCU_stOSTMAttribute.OSTM_BasicAddr[u32Loop].TE.u8Value= 1;
			
			/*interrupt enable*/
			MCU_u16InterruptCtrl((MCU_enIsrID)u32VectNum,1);

			/*start or not*/
			if(MCU_stOSTMAttribute.OSTM_Cfg[u32Loop].u32RunInRst !=0)
			{
				/*update OSTMnTS:Timer counte start*/
				MCU_stOSTMAttribute.OSTM_BasicAddr[u32Loop].TS.u8Value= 1;
			}
			
		}
	
	}
	EI();

	return DET_Err_NotErr;
	
}

#if ((MCU_mOstmCtrlEnable !=0) || (MCU_mOstmChangeEnable !=0))
/*****************************************************************************
 Function  : MCU_u16OSTMctrl												 
 Description   : OS timer stop control 
 
 In Parameter: 
 			OSTM_ID : OSTM ID list in head file
 			OnOff : expected status, 0=Off, other = On
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE:

 	NULL
*****************************************************************************/
uint16 MCU_u16OSTMctrl(MCU_enOstmID OSTM_ID,uint32 OnOff)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(OSTM_ID<MCU_mOSTM_Mun, DET_Err_OSTMIDOutOfRange);

	DI();
	if(OnOff !=0)
	{
		/*update OSTMnTS:Timer counte start*/
		MCU_stOSTMAttribute.OSTM_BasicAddr[OSTM_ID].TS.u8Value= 1;
	}
	else
	{
		/*update OSTMnTS:Timer counte stop*/
		MCU_stOSTMAttribute.OSTM_BasicAddr[OSTM_ID].TT.u8Value= 1;
	}
	EI();
	
	return u16RetVal;
}
#endif

#if (MCU_mOstmChangeEnable !=0)
/*****************************************************************************
 Function  : MCU_u16OSTMChgInterval												 
 Description   : OS timer interrupt interval change function 
 
 In Parameter: 
 			OSTM_ID : OSTM ID list in head file
 			u16Interval : counter number for interrupt interval 
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 
 		NULL
*****************************************************************************/
uint16 MCU_u16OSTMChgInterval(MCU_enOstmID OSTM_ID,uint32 u32Interval_Us)
{
	uint16 u16RetVal=DET_Err_NotErr;
	/*======RH850 F1X serial======*/
	#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	uint32 OSTMclk=MCU_stClockStatus.CPUCLK_Speed/2;
	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	uint32 OSTMclk=MCU_stClockStatus.ClkSpeed_CKSC_PCLK;
	#endif

	DET_ErrCheck(OSTM_ID<MCU_mOSTM_Mun, DET_Err_OSTMIDOutOfRange);
	
	DI();
	/*update OSTMnTS:Timer counte stopt*/
	MCU_stOSTMAttribute.OSTM_BasicAddr[OSTM_ID].TT.u8Value= 1;
	
	if(u32Interval_Us >1)
	{
		/*update OSTMnCMP: counter number*/
		MCU_stOSTMAttribute.OSTM_BasicAddr[OSTM_ID].CMP = (u32Interval_Us * ( OSTMclk / MEGA(1)))  - 1;

		/*update OSTMnTS:Timer counte start*/
		MCU_stOSTMAttribute.OSTM_BasicAddr[OSTM_ID].TS.u8Value= 1;
	}
	else
	{
		MCU_u16OSTMctrl(OSTM_ID,0);
	}
	EI();
	

	return u16RetVal;
	
}
#endif

/*****************************************************************************
 Function  : MCU_vOSTM_Isr												 
 Description   : OS timer ISR function 
 
 In Parameter: 
 			OSTM_ID : OSTM ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE:

 	NULL
*****************************************************************************/
void MCU_vOSTM_Isr(MCU_enOstmID OSTM_ID)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(OSTM_ID<MCU_mOSTM_Mun, DET_Err_OSTMIDOutOfRange);
	
	MCU_stOSTMAttribute.OSTM_Cfg[OSTM_ID].vpOSTM_IRQ();
}

#endif/*end of MCU_mOSTMModuleEnable*/


#if (MCU_mPWGAModuleEnable!=0u)

#if (MCU_mPWGAdutyChangeEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16PWGASetDuty												 
 Description   : PWGA change output duty function 
 
 In Parameter: 
 			u16PPG_ID : PWGA ID list in head file
 			u16Duty : expected output duty, 
 			
	 				1000 = 100%
	 				0 = 0%
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 
 		if u16Duty >= 1000, PWGA will output a high level!
 		
*****************************************************************************/
uint16 MCU_u16PWGASetDuty(MCU_enPwgaID u16PPG_ID, uint16 u16Duty)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32Duty=u16Duty;
	uint32 CSDR,CRDR;
	
	DET_ErrCheck(u16PPG_ID<MCU_mPWGA_MaxChannel, DET_Err_PpgIdOutOfRange);
	
	/*calc duty counter~*/
	if(u32Duty ==0)
	{
		CRDR=0xFFF;/*low level first*/
		CSDR = CRDR;/*output low*/
	}
	else if(u32Duty >=1000)
	{
		CRDR=0xFFF +1 ;/*High level output*/
		CSDR = 0;
	}
	else 
	{
		CRDR=0xFFF;/*low level first*/
		CSDR = (( 0xFFF +1 ) * u32Duty) /1000U ;
		CSDR = 0xFFF-CSDR;/*low level first, so need re-cale the counter*/
	}

	DI();
	/*update register*/
	MCU_stPWGAAttribute.PWGA[u16PPG_ID].CTDR.u16Value= (uint16)CRDR;/*trigger*/
	MCU_stPWGAAttribute.PWGA[u16PPG_ID].CRDR.u16Value = (uint16)CRDR;/*cycle*/
	MCU_stPWGAAttribute.PWGA[u16PPG_ID].CSDR.u16Value = (uint16)CSDR;/*duty*/
	/*duty buffer update triggre*/
	MCU_stPWGAAttribute.PWGA[u16PPG_ID].RDT.u8Value = 1;
	EI();
	
	return u16RetVal;
		
}
#endif

/*****************************************************************************
 Function  : MCU_u16PWGAinit												 
 Description   : PWGA model initialization in reset, 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			it execute before system-mainloop
 			
*****************************************************************************/
static uint16 MCU_u16PWGAinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32Loop,u32Hz,u32Duty,u32MaskBit;
	uint32 BRS,CSDR,CRDR,CTL;
		
	/*======RH850 F1X serial======*/
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	uint32 u32ClkSource = MCU_stClockStatus.ClkSpeed_C_ISO_PER2;
	/*======RH850 D1X serial======*/
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	uint32 u32ClkSource =MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
	#endif

	/*update the clock source first*/
	for(u32Loop=0;u32Loop<MCU_mPWBA_MaxChannel;u32Loop++)
	{		
		u32MaskBit = 1<<u32Loop;
		u32Hz=MCU_stPWGAAttribute.PWGA_Cfg->Frequency[u32Loop];
		if(u32Hz !=_Hz_NotUsed_)
		{
			/*MCU_stPWGARunStatus.UpdateStatus[u32Loop].Hz=u32Hz;*/
			
			BRS=u32ClkSource/(4096*2)/u32Hz;
			DET_ErrCheck((BRS<=2047), DET_Err_PpgFrequencyOutOfRange);
			
			DI();
			MCU_stPWGAAttribute.PWBA->BRS[u32Loop].u16Value = (uint16)BRS;
			/*clock output enable*/
			MCU_stPWGAAttribute.PWBA->TS.u8Value|=(uint8)u32MaskBit;
			EI();
		}
	}

	/*update every channel data*/
	for(u32Loop=0;u32Loop<MCU_mPWGA_MaxChannel;u32Loop++)
	{
		CTL = MCU_stPWGAAttribute.PWGA_Cfg->ChannelCfg[u32Loop].FrequencySelect;
		if(CTL < MCU_mPWBA_MaxChannel)
		{
			/*check setting frequency*/
			DET_ErrCheck(MCU_stPWGAAttribute.PWGA_Cfg->Frequency[CTL] !=0, DET_Err_PpgFrequencyOutOfRange);

			u32Duty=MCU_stPWGAAttribute.PWGA_Cfg->ChannelCfg[u32Loop].DefaultDuty;
			
			/*calc duty counter~*/
			if(u32Duty ==0)
			{
				CRDR=0xFFF;/*low level first*/
				CSDR = CRDR;/*output low*/
			}
			else if(u32Duty >=1000)
			{
				CRDR=0xFFF +1 ;/*High level output*/
				CSDR = 0;
			}
			else 
			{
				CRDR=0xFFF;/*low level first*/
				CSDR = (( 0xFFF +1 ) * u32Duty) /1000 ;
				CSDR = 0xFFF-CSDR;/*low level first, so need re-cale the counter*/
			}

			DI();
			/*update register*/
			MCU_stPWGAAttribute.PWGA[u32Loop].CTDR.u16Value= (uint16)CRDR;/*trigger*/
			MCU_stPWGAAttribute.PWGA[u32Loop].CRDR.u16Value = (uint16)CRDR;/*cycle-->update in 0xFFF dafault*/
			MCU_stPWGAAttribute.PWGA[u32Loop].CSDR.u16Value= (uint16)CSDR;/*duty*/
			
			MCU_stPWGAAttribute.PWGA[u32Loop].CTL.u8Value = (uint8)CTL;/*clock connect*/
			/*start trigger*/
			MCU_stPWGAAttribute.SLPWGA[u32Loop>>5/*32 channel in a unit*/] |= 1<<(u32Loop&31);
			EI();

		}
		
	}

	
	return u16RetVal;
	
}

#endif /*end of PWGA module */


#if ((MCU_mTAUBDModuleEnable!=0u)||(MCU_mTAUJModuleEnable!=0u))
/*****************************************************************************
 Function  : MCU_u16TAUxClkDivSetting												 
 Description   : TAUX model clock supply setting 
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it execute before TAUX timer init
 			
*****************************************************************************/
static void MCU_u16TAUxClkDivSetting(void)
{
	uint32 u32loop,PreScale_3,PreScale_2,PreScale_1,PreScale_0;
					
	DI();
	#if (MCU_mTAUBDModuleEnable!=0u)
	for(u32loop=0;u32loop<(MCU_mTAUB_Unit+MCU_mTAUD_Unit);u32loop++)
	{
		PreScale_0=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[u32loop][0];
		PreScale_1=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[u32loop][1];
		PreScale_2=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[u32loop][2];
		PreScale_3=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[u32loop][3];
		MCU_stTAUxAttribute.TAUBD[u32loop]->TPS.u16Value=((PreScale_3<<12)+(PreScale_2<<8)+(PreScale_1<<4)+(PreScale_0));
	}
	#endif
	#if (MCU_mTAUJModuleEnable!=0u)
	for(u32loop=0;u32loop<MCU_mTAUJ_Unit;u32loop++)
	{
		PreScale_0=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+u32loop][0];
		PreScale_1=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+u32loop][1];
		PreScale_2=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+u32loop][2];
		PreScale_3=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[MCU_mTAUB_Unit+MCU_mTAUD_Unit+u32loop][3];
		MCU_stTAUxAttribute.TAUJ[u32loop]->TPS.u16Value=((PreScale_3<<12)+(PreScale_2<<8)+(PreScale_1<<4)+(PreScale_0));
	}
	#endif
	EI();
	
}

/*****************************************************************************
 Function  : MCU_vTAUx_Isr												 
 Description   : TAUX ISR function 
 
 In Parameter: 
 			u32TAUxCh : TAUx ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it call by interrupt!
 			
*****************************************************************************/
void MCU_vTAUx_Isr(MCU_enTauxID u32TAUxCh)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u32TAUxCh<MCU_mTAUB0_Channel * MCU_mTAUB_Unit + \
								MCU_mTAUD0_Channel * MCU_mTAUD_Unit+\
								MCU_mTAUJ0_Channel * MCU_mTAUJ_Unit, DET_Err_TimerIDOutOfRange);
								
	MCU_stTAUxAttribute.TAUx_Cfg[u32TAUxCh].TimerCB();
	
}

/*****************************************************************************
 Function  : MCU_vTAUx_INTctrl												 
 Description   : TAUX ISR control
 
 In Parameter: 
 			TauxID : TAUx ID list in head file
 			IntEnable: interrupt enable control
 			
 				0 = disable taux interrupt
 				others = enable taux interrupt
Return Value:
 		NULL
 			
 NOTE: 		
 		NULL
 			
*****************************************************************************/
void MCU_vTAUx_INTctrl(MCU_enTauxID TauxID, uint32 IntEnable)
{
	uint16 u16VectNum=0xFFFFu;
	uint32 u32Grp,TimerSubID;
	
	if(TauxID<MCU_mTAUJ0_0)
	{
		u32Grp = TauxID / MCU_mTAUB0_Channel;
		TimerSubID = TauxID & (MCU_mTAUB0_Channel-1);
	}
	else
	{
		TauxID-=MCU_mTAUJ0_0;
		u32Grp = MCU_mTAUD_Unit + MCU_mTAUB_Unit + (TauxID / (MCU_mTAUJ0_Channel));
		TimerSubID =(TauxID & (MCU_mTAUJ0_Channel-1));
	}
	
/*======RH850 F1X serial======*/
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	if(u32Grp == MCU_mTAUxID_D0/*it is the TAUD index*/)
	{
		if((TimerSubID&1)!=0u)
		{
			u16VectNum=MCU_mISR_39_ICTAUD0I1 + (TimerSubID>>1);
		}
		else
		{
			u16VectNum=MCU_mISR_0_ICTAUD0I0_ICCSIH2IC_1 + (TimerSubID>>1);
		}
	}
	else
	{
		
		u16VectNum = MCU_stTAUxAttribute.VectList[u32Grp] + TimerSubID;
	}
		
	/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	u16VectNum = MCU_stTAUxAttribute.VectList[u32Grp] + TimerSubID;

#endif

	if(u16VectNum !=0xFFFFu)
	{
		MCU_u16InterruptCtrl((MCU_enIsrID)u16VectNum, IntEnable);
	}

}

/*****************************************************************************
 Function  : MCU_u32GetTAUxClkFrequency												 
 Description   : get the timer supply clock frequency
 
 In Parameter: 
 			TauxID : TAUx ID list in head file

Return Value:

 		the clock frequency of TauxID 
 			
 NOTE: 		
 		NULL
 			
*****************************************************************************/
uint32 MCU_u32GetTAUxClkFrequency(MCU_enTauxID TauxID)
{
	uint32 GroupSourceClk,Grp,DivSel;

	/*======RH850 F1X serial======*/
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	if(TauxID<=MCU_mTAUB1_15)/*get hardware clock source*/
	{
	         /*TAUB0, TAUB1*/
		GroupSourceClk=MCU_stClockStatus.ClkSpeed_C_ISO_PER2;
	}
	else if((TauxID>=MCU_mTAUJ0_0) &&(TauxID<=MCU_mTAUJ0_3))
	{
	         /*TAUJ0*/
		GroupSourceClk=MCU_stClockStatus.ClkSpeed_C_AWO_TAUJS;
	}
	else
	{
	         /*TAUD, TAUJ1*/
		GroupSourceClk=MCU_stClockStatus.ClkSpeed_C_ISO_PER1;
	}
	
	/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		if(TauxID<=MCU_mTAUB1_15)/*get hardware clock source*/
		{
			GroupSourceClk=MCU_stClockStatus.ClkSpeed_CKSC_ITAUB01S;
		}
		else if(TauxID<=MCU_mTAUB2_15) 
		{
			GroupSourceClk=MCU_stClockStatus.ClkSpeed_CKSC_ITAUB2S;
		}
		else
		{
			GroupSourceClk=MCU_stClockStatus.ClkSpeed_CKSC_ITAUJS;
		}
		
#endif

	DivSel=MCU_stTAUxAttribute.TAUx_Cfg[TauxID].ClkSelect;/*get selector*/
	
	if(TauxID<=MCU_mTAUBD_MaxID)
	{
		Grp=TauxID/MCU_mTAUB0_Channel;
	}
	else
	{
		Grp=(TauxID-MCU_mTAUJ0_0)/MCU_mTAUJ0_Channel;
		Grp +=MCU_mTAUB_Unit + MCU_mTAUD_Unit;
	}
	
	DivSel=MCU_stTAUxAttribute.TAUxClkDiv_Cfg[Grp][DivSel];
	
	return GroupSourceClk / (1<< DivSel);

}

#if (MCU_mTAUBDModuleEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16TAUBD_Init 											 
 Description   : TUAB/TAUD timer initialization (16Bit timer)
 
 In Parameter: 
			NULL

Return Value:

		NULL
			
 NOTE:		
		it run in reset before system mainloop
			
*****************************************************************************/
uint16 MCU_u16TAUBD_Init(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	uint32 u32TUAxGroup,u32TUAxIndx,u32TimerList=0u,u32RunMode,TimerIOSeting,u32MaskBit;
	uint32 u32TimerAltFun;
	uint32 TOE,TO,TOM,TOC,TOL,TS,RDE,RDS,RDM,RDC;
	uint32 MasterCnt,CounterValue,u32ClkSel;

	u32TimerList = MCU_mTAUB0_0;

	/*TAUB/TAUD unit initial*/
	for(u32TUAxGroup=0;u32TUAxGroup<(MCU_mTAUB_Unit+MCU_mTAUD_Unit);u32TUAxGroup++)
	{
		TOE=0u;TS=0u;TOC=0u;RDE=0u;RDS=0u;
		TO=0u;TOL=0u;TOM=0u;RDM=0u;RDC=0u;
		
		u32TimerAltFun=MCU_stTAUxAttribute.TimerAltFun[u32TUAxGroup];
		u32ClkSel = 0xff;
		MasterCnt=0;/*clear for next group*/
		
		for(u32TUAxIndx=0;u32TUAxIndx<MCU_mTAUB0_Channel;u32TUAxIndx++)
		{
			/*timer is in using*/
			u32RunMode=MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerMode;
			u32MaskBit=1ul<<u32TUAxIndx;
			
			if( u32RunMode < TUAx_MaxFun)
			{
				DET_ErrCheck((u32TimerAltFun & u32MaskBit)!=0u, DET_Err_TimerAltFunNotActive);

				DI();
                                    if(u32RunMode == MCU_enTAUxAltFun_PpgMaster)/*PPG master*/
                                    {
        				    u32ClkSel =MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].ClkSelect;
				}
				
        				MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value=(uint16)(MCU_stTAUxAttribute.TAUx_RegVal[u32RunMode].CMOR);
                                    /*in PPG slave mode, using the clock scale same as Master~~~~~*/
				if(u32RunMode == MCU_enTAUxAltFun_PpgSlave)
				{
                				/*basic mode control*/
				        DET_ErrCheck(u32ClkSel<4, DET_Err_ParaOutOfRange);/*Ii may PPG_Mater not set in this group*/
				        MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value |=(uint16)(u32ClkSel<<14);
				}
				else
				{
                				/*basic mode control*/
				        MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value |=(uint16)(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].ClkSelect<<14);
				}
				

				/*Valib edge setting*/	
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Condition <=MCU_enTAUxTrigger_HighLevel)
				{
            				/*timer valid condition setting*/
            				MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CMUR[u32TUAxIndx].u8Value=\
            						(uint8)MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Condition;
            						
					#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
					/*timer input pin setting, need set the NDFA ctrl bit to enable pin detect! */
					MCU_stTAUxAttribute.DNFA[u32TUAxGroup]->ENable.u16Value |=(uint16)u32MaskBit;
					
					#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
					MCU_stTAUxAttribute.DNFA[u32TUAxGroup].ENable.u16Value |=(uint16)u32MaskBit;
					
					#endif
				}

				/*timer counter setting*/
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter !=0)
				{
					if(u32RunMode == MCU_enTAUxAltFun_PpgMaster)/*PPG master*/
					{
						DET_ErrCheck((u32TimerList&1) ==0, DET_Err_PPGmasterMustBeEven);/*16bit timer counter range check!*/
						MasterCnt = MCU_u32GetTAUxClkFrequency((MCU_enTauxID)u32TimerList);
						MasterCnt = MasterCnt / MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter -1;
						DET_ErrCheck(MasterCnt<0xFFFF, DET_Err_ParaOutOfRange);/*16bit timer counter range check!*/
						
						MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CDR[u32TUAxIndx].u16Value=(uint16)MasterCnt;
					}
					else if(u32RunMode == MCU_enTAUxAltFun_PpgSlave)/*PPG slave*/
					{
						/*set 100% duty*/
						if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter >=1000)
						{
							MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CDR[u32TUAxIndx].u16Value=(uint16)(MasterCnt+1u);
						}
						/*set normal duty*/
						else
						{
							MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CDR[u32TUAxIndx].u16Value= \
								(uint16)((MasterCnt *MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter)/1000u);
						}
					}
					else
					{
                                                    CounterValue=MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter;
                                                    if((u32RunMode == MCU_enTAUxAltFun_Counter)||(u32RunMode == MCU_enTAUxAltFun_FrequencyDivider))
                                                    {
                                                            /*in counter or frequency divider mode, the setting counter is needed value, not need convort to clock numbers*/
                                                    }
                                                    else
                                                    {
                                                            /*in other mode, the setting value may time-base, so it need to convort to clock number for counting*/
            						 CounterValue=CounterValue*(MCU_u32GetTAUxClkFrequency((MCU_enTauxID)u32TimerList)/1000);
            						 CounterValue /=1000;/*avoid OverFlow*/
                                                    }

						DET_ErrCheck(CounterValue<(0xFFFF+1), DET_Err_ParaOutOfRange);/*16bit timer counter range check!*/
						MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->CDR[u32TUAxIndx].u16Value=(uint16)CounterValue-1;
					}
					
				}
				
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].AutoRun !=0u){
					TS|=u32MaskBit;
				}
				EI();
				
				/*IO setting part!!*/
				TimerIOSeting=MCU_stTAUxAttribute.TAUx_RegVal[u32RunMode].TimerIOSeting;
				if((TimerIOSeting & 1) !=0u)
				{
					TOE |=u32MaskBit;
					if((TimerIOSeting & 2) !=0u){
						TO |=u32MaskBit;
					}
					if((TimerIOSeting & 4) !=0u){
						TOM |=u32MaskBit;
					}
					if((TimerIOSeting & 8) !=0u){
						TOC |=u32MaskBit;
					}
					if((TimerIOSeting & 16) !=0u){
						TOL |=u32MaskBit;
					}
				}

				/*Simultaneous rewrite part!!*/
				TimerIOSeting &=0xFFFF0000;
				TimerIOSeting>>=16;
				if((TimerIOSeting & 1) !=0u)
				{
					RDE |=u32MaskBit;
					if((TimerIOSeting & 2) !=0u){
						RDS |=u32MaskBit;
					}
					if((TimerIOSeting & 4) !=0u){
						RDM |=u32MaskBit;
					}
					if((TimerIOSeting & 8) !=0u){
						RDC |=u32MaskBit;
					}
				}

				/*timer interrupt CB is need*/
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerCB != MCU_vNotExpINT)
				{
					 MCU_vTAUx_INTctrl((MCU_enTauxID)u32TimerList, 1);
				}
				
			}


			u32TimerList++;
			
		}
		
		DI();
		/*one group data update!*/
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TOL.u16Value=TOL;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TOC.u16Value=TOC;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TO.u16Value=TO;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TOM.u16Value=TOM;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TOE.u16Value=TOE;

		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->RDE.u16Value=RDE;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->RDS.u16Value=RDS;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->RDM.u16Value=RDM;
		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->RDC.u16Value=RDC;

		MCU_stTAUxAttribute.TAUBD[u32TUAxGroup]->TS.u16Value =TS;
		EI();
		
	}

	return u16RetVal;
	
}
#endif

#if (MCU_mTAUJModuleEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16TAUJ_Init 											 
 Description   : TUAJ timer initialization (32Bit timer)
 
 In Parameter: 
			NULL

Return Value:

		NULL
			
 NOTE:		
		it run in reset before system mainloop
			
*****************************************************************************/
uint16 MCU_u16TAUJ_Init(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	uint32 u32TUAxGroup,u32TUAxIndx,u32TimerList=0u,u32RunMode,TimerIOSeting,u32MaskBit;
	uint32 u32TimerAltFun;
	uint32 TOE,TO,TOM,TOC,TOL,TS,RDE,RDS,RDM,RDC;
	uint32 MasterCnt,u32ClkSel,CounterValue;

	u32TimerList = MCU_mTAUJ0_0;
	
	/*TAUJ unit initial*/
	for(u32TUAxGroup=0;u32TUAxGroup<MCU_mTAUJ_Unit;u32TUAxGroup++)
	{
		TOE=0u;TS=0u;TOC=0u;
		TO=0u;TOL=0u;TOM=0u;
		RDE=0u,RDS=0u,RDM=0u,RDC=0u;
		
		u32ClkSel = 0xff;
		MasterCnt=0;/*clear for next group*/
		
		u32TimerAltFun=MCU_stTAUxAttribute.TimerAltFun[u32TUAxGroup+MCU_mTAUB_Unit+MCU_mTAUD_Unit];
		for(u32TUAxIndx=0;u32TUAxIndx<MCU_mTAUJ0_Channel;u32TUAxIndx++)
		{
			/*timer is in using*/
			u32RunMode=MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerMode;
			u32MaskBit=1ul<<u32TUAxIndx;
			
			if( u32RunMode < TUAx_MaxFun)
			{
				DET_ErrCheck((u32TimerAltFun & u32MaskBit)!=0u, DET_Err_TimerAltFunNotActive);

				DI();
                                    if(u32RunMode == MCU_enTAUxAltFun_PpgMaster)/*PPG master*/
                                    {
        				    u32ClkSel =MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].ClkSelect;
				}
				
        				MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value=(uint16)(MCU_stTAUxAttribute.TAUx_RegVal[u32RunMode].CMOR);
                                    /*in PPG slave mode, using the clock scale same as Master~~~~~*/
				if(u32RunMode == MCU_enTAUxAltFun_PpgSlave)
				{
                				/*basic mode control*/
				        DET_ErrCheck(u32ClkSel<4, DET_Err_ParaOutOfRange);/*Ii may PPG_Mater not set in this group*/
				        MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value |=(uint16)(u32ClkSel<<14);
				}
				else
				{
                				/*basic mode control*/
				        MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CMOR[u32TUAxIndx].u16Value |=(uint16)(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].ClkSelect<<14);
				}


                                    if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Condition <=MCU_enTAUxTrigger_HighLevel)
                                    {
            				/*timer valid condition setting*/
            				MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CMUR[u32TUAxIndx].u8Value=\
            						(uint8)MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Condition;
            						
            				#if ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
            				/*Only in D1X need set this register!!!!!*/
            				if((u32RunMode != 15) &&(u32RunMode != 16)&&(u32RunMode != 0))
            				{
            					/*timer input pin setting, need set the NDFA ctrl bit to enable pin detect! */
            					MCU_stTAUxAttribute.DNFA[u32TUAxGroup+MCU_mTAUB_Unit+MCU_mTAUD_Unit].ENable.u16Value |=(uint16)u32MaskBit;
            				}
				        #endif
				}
				
				/*timer counter setting*/
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter !=0)
				{
					if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerMode == MCU_enTAUxAltFun_PpgMaster)/*PPG master*/
					{
						MasterCnt = MCU_u32GetTAUxClkFrequency((MCU_enTauxID)u32TimerList);
						MasterCnt = MasterCnt / MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter -1;
						MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CDR[u32TUAxIndx]=MasterCnt;
					}
					else if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerMode == MCU_enTAUxAltFun_PpgSlave)/*PPG slave*/
					{
						/*set 100% duty*/
						if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter >=1000)
						{
							MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CDR[u32TUAxIndx]=MasterCnt+1;
						}
						/*set normal duty*/
						else
						{
							MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CDR[u32TUAxIndx]= \
								(MasterCnt * MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter )/1000u;
						}
					}
					else
					{
                                                    CounterValue=MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].Counter;
            				        CounterValue=CounterValue*(MCU_u32GetTAUxClkFrequency((MCU_enTauxID)u32TimerList)/1000);
            				        CounterValue /=1000;/*avoid OverFlow*/
						MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->CDR[u32TUAxIndx]=CounterValue-1;
					}
					
				}		
				EI();
				
				if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].AutoRun !=0u){
					TS|=u32MaskBit;
				}
				
				/*IO setting part!!*/
				TimerIOSeting=MCU_stTAUxAttribute.TAUx_RegVal[u32RunMode].TimerIOSeting;
				if((TimerIOSeting & 1) !=0u)
				{
					TOE |=u32MaskBit;
					if((TimerIOSeting & 2) !=0u){
						TO |=u32MaskBit;
					}
					
					if((TimerIOSeting & 4) !=0u){
						TOM |=u32MaskBit;
					}
					
					if((TimerIOSeting & 8) !=0u){
						TOC |=u32MaskBit;
					}
					
					if((TimerIOSeting & 16) !=0u){
						TOL |=u32MaskBit;
					}
				}

				/*Simultaneous rewrite part!!*/
				TimerIOSeting &=0xFFFF0000;
				TimerIOSeting>>=16;
				if((TimerIOSeting & 1) !=0u)
				{
					RDE |=u32MaskBit;
					if((TimerIOSeting & 2) !=0u){
						RDS |=u32MaskBit;
					}
					
					if((TimerIOSeting & 4) !=0u){
						RDM |=u32MaskBit;
					}
					
					if((TimerIOSeting & 8) !=0u){
						RDC |=u32MaskBit;
					}
				}
			}

			/*timer interrupt CB is need*/
			if(MCU_stTAUxAttribute.TAUx_Cfg[u32TimerList].TimerCB != MCU_vNotExpINT)
			{
				MCU_vTAUx_INTctrl((MCU_enTauxID)u32TimerList, 1);
			}

			u32TimerList++;
			
		}
		
		DI();
		/*one group data update!*/
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TOL.u8Value=TOL;
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TOC.u8Value=TOC;
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TO.u8Value=TO;
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TOM.u8Value=TOM;
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TOE.u8Value=TOE;

		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->RDE.u8Value=RDE;
		/*MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->RDS=RDS;*/
		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->RDM.u8Value=RDM;
		/*MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->RDC=RDC;*/

		MCU_stTAUxAttribute.TAUJ[u32TUAxGroup]->TS.u8Value=TS;
		EI();
		
	}
	
	return u16RetVal;
	
}

#endif

/*****************************************************************************
 Function  : MCU_u16TAUxInit 											 
 Description   : TUAx timer initialization
 
 In Parameter: 
			NULL

Return Value:

		NULL
			
 NOTE:		
		it run in reset before system mainloop
			
*****************************************************************************/
static uint16 MCU_u16TAUxInit(void)
{
   
	/*Clock  initial first*/
	MCU_u16TAUxClkDivSetting();
	
	#if (MCU_mTAUBDModuleEnable!=0u)
	MCU_u16TAUBD_Init();
	#endif
	
	#if (MCU_mTAUJModuleEnable!=0u)
	MCU_u16TAUJ_Init();
	#endif

	return DET_Err_NotErr;
}

#if (MCU_mTauxSetCounterEnable !=0U)
/*****************************************************************************
 Function  : MCU_u16TAUxCounterUpdate 											 
 Description   : TUAx timer counter update
 
 In Parameter: 
			TauxID: TUAx ID list in head file
			u32NewCounte: expected interval counter

Return Value:

		function execute resault
			
 NOTE:		
		NULL
			
*****************************************************************************/
uint16 MCU_u16TAUxSetCounter(MCU_enTauxID TauxID,uint32 u32NewCounte)
{
	uint32 Grp,SubIndex;

	DI();
	if(TauxID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
		Grp=TauxID/MCU_mTAUB0_Channel;
		SubIndex=TauxID & (MCU_mTAUB0_Channel-1);
		MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndex].u16Value=(uint16)u32NewCounte;
		MCU_stTAUxAttribute.TAUBD[Grp]->RDT.u16Value |=(uint16)(1u<<SubIndex);/*RE-Write trigger!!*/
	#endif
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		TauxID -=MCU_mTAUJ0_0;
		Grp=TauxID/MCU_mTAUJ0_Channel;
		SubIndex=TauxID & (MCU_mTAUJ0_Channel-1);
		MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndex]=u32NewCounte;
		MCU_stTAUxAttribute.TAUJ[Grp]->RDT.u8Value |=(uint8)(1u<<SubIndex);/*RE-Write trigger!!*/
	#endif
	}
	EI();

	return DET_Err_NotErr;
}
#endif

#if ((MCU_mTauxSetDutyEnable !=0u)||(MCU_mTauxSetHzEnable !=0))
static uint16 MCU_u16TAUxPpgGetMasterID(MCU_enTauxID u32SlaveChID)
{
        uint32 u32GroupIndex ,u32Loop, u32FindOut=0xFFFF;

        if(u32SlaveChID<=MCU_mTAUBD_MaxID)
        {
            u32GroupIndex=u32SlaveChID - (u32SlaveChID&(MCU_mTAUB0_Channel-1));
        }
        else
        {
            u32GroupIndex=u32SlaveChID - (u32SlaveChID&(MCU_mTAUJ0_Channel-1));
        }

        for(u32Loop=u32GroupIndex; u32Loop < u32SlaveChID; u32Loop++)
        {
                if(MCU_stTAUxAttribute.TAUx_Cfg[u32Loop].TimerMode == MCU_enTAUxAltFun_PpgMaster)
                {
                        u32FindOut=u32Loop;
                }
        }

        return u32FindOut;
        
}

#endif

#if (MCU_mTauxSetHzEnable !=0)
/*****************************************************************************
 Function  : MCU_u16TAUxPpgSetHz 											 
 Description   : TUAx timer counter update for PPG channel using
 
 In Parameter: 
			u32MasterChID: 	TUAx ID list in head file, this ID must use as master mode, even channel ID
			u32SlaveChID: 	TUAx ID list in head file, this ID must use as slave mode,
			u32Hz: 			expected output frequency
			u16Duty:			expected output duty, 1000 = 100%
			
Return Value:

		function execute resault
			
 NOTE:		
		NULL
			
*****************************************************************************/
uint16 MCU_u16TAUxPpgSetHz(MCU_enTauxID u32SlaveChID,uint32 u32Hz, uint16 u16Duty)
{
	uint32 Grp,SubIndexMaster,SubIndexSlave;
	uint32 SourceClk;
	uint32 MasterCnt,SlaveCnt;
	uint16 u16RetVal=DET_Err_NotErr;
        MCU_enTauxID u32MasterChID=MCU_u16TAUxPpgGetMasterID(u32SlaveChID);
        
	DET_ErrCheck(u32Hz!=0, DET_Err_PpgFrequencyOutOfRange);
	/*DET_ErrCheck(u16Duty<=1000, DET_Err_PpgDutyOutOfRange);*/
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	DET_ErrCheck(u32MasterChID<MCU_mTAUJ1_3, DET_Err_PpgDutyOutOfRange);
	
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	DET_ErrCheck(u32MasterChID<MCU_mTAUJ0_3, DET_Err_PpgDutyOutOfRange);
        #endif
	/*get running clock frequency!*/
	SourceClk=MCU_u32GetTAUxClkFrequency(u32MasterChID);

	/*calc timer counter number!*/
	MasterCnt=(SourceClk/u32Hz)-1;
	
	if(u16Duty>=1000)
	{
		SlaveCnt=MasterCnt+1;
	}
	else
	{
		SlaveCnt=(MasterCnt*u16Duty)/1000;
	}
	
	if(u32MasterChID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
        	        DET_ErrCheck(MasterCnt<0xFFFF, DET_Err_ParaOutOfRange);/*16bit timer ragne change*/
		Grp=u32MasterChID/MCU_mTAUB0_Channel;
		SubIndexMaster = u32MasterChID&(MCU_mTAUB0_Channel-1);
		SubIndexSlave = u32SlaveChID&(MCU_mTAUB0_Channel-1);
		DI();
		MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndexMaster].u16Value=(uint16)MasterCnt;
		MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndexSlave].u16Value=(uint16)SlaveCnt;
		
		MCU_stTAUxAttribute.TAUBD[Grp]->RDT.u16Value |=(uint16)((1<<SubIndexMaster)/* |(1<<SubIndexSlave)*/);/*RE-Write trigger!! slave counter is update by master trigger*/
		EI();
	#endif
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		u32MasterChID -=MCU_mTAUJ0_0;
		Grp=u32MasterChID/MCU_mTAUJ0_Channel;
		SubIndexMaster = u32MasterChID&(MCU_mTAUJ0_Channel-1);
		SubIndexSlave = u32SlaveChID&(MCU_mTAUJ0_Channel-1);

		DI();
		MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndexMaster]=MasterCnt;
		MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndexSlave]=SlaveCnt;
		
		MCU_stTAUxAttribute.TAUJ[Grp]->RDT.u8Value |=(uint8)((1<<SubIndexMaster)/* |(1<<SubIndexSlave)*/);/*RE-Write trigger!! slave counter is update by master trigger*/
		EI();
	#endif
	}
	
	return u16RetVal;
	
}
#endif

#if (MCU_mTauxSetDutyEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16TAUxPpgSetDuty 											 
 Description   : TUAx timer counter update for PPG channel using
 
 In Parameter: 
			u32MasterChID: 	TUAx ID list in head file, this ID must use as master mode, even channel ID
			u32SlaveChID: 	TUAx ID list in head file, this ID must use as slave mode,
			u16Duty:			expected output duty, 1000 = 100%
			
Return Value:

		function execute resault
			
 NOTE:		
		NULL
			
*****************************************************************************/
uint16 MCU_u16TAUxPpgSetDuty(MCU_enTauxID u32SlaveChID, uint16 u16Duty)
{
	uint32 Grp,SubIndexMaster,SubIndexSlave;
	uint32 MasterCnt,SlaveCnt;
        MCU_enTauxID u32MasterChID=MCU_u16TAUxPpgGetMasterID(u32SlaveChID);
	uint16 u16RetVal=DET_Err_NotErr;

	/*DET_ErrCheck(u16Duty<=1000, DET_Err_PpgDutyOutOfRange);*/
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	DET_ErrCheck(u32MasterChID<MCU_mTAUJ1_3, DET_Err_PpgDutyOutOfRange);
	
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	DET_ErrCheck(u32MasterChID<MCU_mTAUJ0_3, DET_Err_PpgDutyOutOfRange);
        #endif
        
	if(u32MasterChID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
		Grp=u32MasterChID/MCU_mTAUB0_Channel;
		SubIndexMaster = u32MasterChID&(MCU_mTAUB0_Channel-1);
		SubIndexSlave = u32SlaveChID&(MCU_mTAUB0_Channel-1);
		
		MasterCnt=MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndexMaster].u16Value;
		if(u16Duty>=1000){
			SlaveCnt=MasterCnt+1;
		}
		else{
			SlaveCnt=(MasterCnt*u16Duty)/1000;
		}

		DI();
		MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndexSlave].u16Value=(uint16)SlaveCnt;
		EI();
		
		/*MCU_stTAUxAttribute.TAUBD[Grp]->RDT|=((1<<SubIndexSlave));RE-Write trigger!!--> Rewrite by master trigger*/
	#endif
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		u32MasterChID -=MCU_mTAUJ0_0;
		Grp=u32MasterChID/MCU_mTAUJ0_Channel;
		SubIndexMaster = u32MasterChID&(MCU_mTAUJ0_Channel-1);
		SubIndexSlave = u32SlaveChID&(MCU_mTAUJ0_Channel-1);

		MasterCnt=MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndexMaster];
		if(u16Duty>=1000){
			SlaveCnt=MasterCnt+1;
		}
		else{
			SlaveCnt=(MasterCnt*u16Duty)/1000;
		}

		DI();
		MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndexSlave]=SlaveCnt;
		EI();
		/*MCU_stTAUxAttribute.TAUJ[Grp]->RDT|=(|(1<<SubIndexSlave));RE-Write trigger!! --> Rewrite by master trigger*/
	#endif
	}
	
	return u16RetVal;
	
}
#endif

#if (MCU_mTuaxRunCtrlEnale !=0u)
/*****************************************************************************
 Function  : MCU_vTAUxRunCtrl 											 
 Description   : TUAx timer run control
 
 In Parameter: 
			TauxID: 	TUAx ID list in head file
			OnOff: 	expext run status, 
					0 = stop
					other = run
Return Value:

		NULL
			
 NOTE:		
		NULL
			
*****************************************************************************/
void MCU_vTAUxRunCtrl(MCU_enTauxID TauxID,MCU_enTauxRunCtrl OnOff )
{
	uint32 Grp,SubIndex;

	DI();
	if(TauxID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
		Grp=TauxID/MCU_mTAUB0_Channel;
		SubIndex=TauxID & (MCU_mTAUB0_Channel-1);

		if(OnOff == MCU_mTAUx_Stop)
		{
			MCU_stTAUxAttribute.TAUBD[Grp]->TT.u16Value|=(uint16)(1u<<SubIndex);
		}
		else
		{
			MCU_stTAUxAttribute.TAUBD[Grp]->TS.u16Value|=(uint16)(1u<<SubIndex);
		}
	#endif	
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		TauxID -=MCU_mTAUJ0_0;
		Grp=TauxID/MCU_mTAUJ0_Channel;
		SubIndex=TauxID & (MCU_mTAUJ0_Channel-1);

		if(OnOff == MCU_mTAUx_Stop)
		{
			MCU_stTAUxAttribute.TAUJ[Grp]->TT.u8Value |=(uint8)(1u<<SubIndex);
		}
		else
		{
			MCU_stTAUxAttribute.TAUJ[Grp]->TS.u8Value|=(uint8)(1u<<SubIndex);
		}
	#endif
	}
	EI();
}
#endif

#if (MCU_mTauxGetCounterEnable !=0u)
/*****************************************************************************
 Function  : MCU_u32TAUxGetCounter 											 
 Description   : get TUAx timer counter
 
 In Parameter: 
			TauxID: 	TUAx ID list in head file

Return Value:
			timer counter value
			
 NOTE:		
		NULL
*****************************************************************************/
uint32 MCU_u32TAUxGetCounter(MCU_enTauxID TauxID)
{
	uint32 u32TimerCnt=0u;
	uint32 Grp,SubIndex;
	
	if(TauxID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
		Grp=TauxID/MCU_mTAUB0_Channel;
		SubIndex=TauxID & (MCU_mTAUB0_Channel-1);
		u32TimerCnt=MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndex].u16Value;
	#endif
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		TauxID -=MCU_mTAUJ0_0;
		Grp=TauxID/MCU_mTAUJ0_Channel;
		SubIndex=TauxID & (MCU_mTAUJ0_Channel-1);
		u32TimerCnt=MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndex];
	#endif
	}

	return u32TimerCnt+1;
	
}
#endif

#if (MCU_mTauxGetTimeEnable !=0u)
/*****************************************************************************
 Function  : MCU_u32TAUxGetTime 											 
 Description   : get TUAx timer time for ICU unit ect
 
 In Parameter: 
			TauxID: 	TUAx ID list in head file

Return Value:
			time value(us)
			
 NOTE:		
		return value is base [us] uint
		
*****************************************************************************/
uint32 MCU_u32TAUxGetTime(MCU_enTauxID TauxID)
{
	uint32 u32TimerCnt=0u;
	uint32 Grp,SubIndex;
	uint32 u32TimerClkSpeed=(MCU_u32GetTAUxClkFrequency((MCU_enTauxID)TauxID));

	
	if(TauxID<=MCU_mTAUBD_MaxID)
	{
	#if (MCU_mTAUBDModuleEnable!=0u)
		Grp=TauxID/MCU_mTAUB0_Channel;
		SubIndex=TauxID & (MCU_mTAUB0_Channel-1);
		u32TimerCnt=MCU_stTAUxAttribute.TAUBD[Grp]->CDR[SubIndex].u16Value;
	#endif
	}
	else
	{
	#if (MCU_mTAUJModuleEnable!=0u)
		TauxID -=MCU_mTAUJ0_0;
		Grp=TauxID/MCU_mTAUJ0_Channel;
		SubIndex=TauxID & (MCU_mTAUJ0_Channel-1);
		u32TimerCnt=MCU_stTAUxAttribute.TAUJ[Grp]->CDR[SubIndex];
	#endif
	}

	/*Note: if CDR > 0x10000, the time calc may overflow!!!
	                if CDR <20, the time calc may = 0*/
	u32TimerCnt= u32TimerCnt*50000/u32TimerClkSpeed;
	u32TimerCnt*=20;/*for avoid OverFlow*/
	
	return u32TimerCnt;
	
}

#endif 

#endif /*end of TAUX module */


#if (MCU_mEINTModuleEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16EINTinit												 
 Description   : external interrupt model initial in reset
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			it execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16EINTinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32Loop;

	for(u32Loop=0u;u32Loop<MCU_mMaxEINTchannelMount;u32Loop++)
	{
		if(MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].u16DetectCondition != EINT_NotUse)
		{
			DI();
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

			MCU_stEINTAttribute.FCLA->CTL[u32Loop]=MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].u16DetectCondition;
			
			/*interrupt condition setting*/
			if((MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].u16RunWhenReset !=0u) && \
			    (MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].vpINTservice !=MCU_vNotExpINT))
			{
            			/*interrupt request enable!!*/
            			MCU_u16InterruptCtrl(MCU_stEINTAttribute.u16EINTvectList[u32Loop], 1);
                    	}
#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

			MCU_stEINTAttribute.FCLA[u32Loop>>3].CTL[u32Loop&7].u8Value=(uint8)MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].u16DetectCondition;
			if(((u32Loop !=0u)&&(MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].u16RunWhenReset !=0u))&& \
			    (MCU_stEINTAttribute.EINT_UsrCfg[u32Loop].vpINTservice !=MCU_vNotExpINT ))
			{
				/*interrupt request enable!!*/
				MCU_u16InterruptCtrl((MCU_enIsrID)(MCU_stEINTAttribute.u16EINTvectList[0]+u32Loop-1), 1);
			}
	
#endif	
			EI();
			
		}
			
	}
			
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_vEINTIsr												 
 Description   : external interrupt service
 
 In Parameter: 
 			u16EintID: EINT ID list in _RH850.h
 			 			
Return Value:
 			NULLt
 			
 NOTE: 		
 			this function ONLY run in interrupt
*****************************************************************************/
void MCU_vEINTIsr(MCU_enEintID u32EINTid)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u32EINTid<MCU_mMaxEINTchannelMount, DET_Err_EINTIDOutOfRange);

	/*run callback function*/
	MCU_stEINTAttribute.EINT_UsrCfg[u32EINTid].vpINTservice();
	
	u16RetVal+=1u;/*compiler warning*/
}


#if MCU_mEINTOnOffCtrlFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_u16EINTctrl												 
 Description   : external interrupt detect enable/disable control
 
 In Parameter: 
 			u16EintID: EINT ID list in _RH850.h
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTctrl(MCU_enEintID u32EintID, uint32 OnOff)
{
	uint16 u16VectNum;
	
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	u16VectNum=MCU_stEINTAttribute.u16EINTvectList[u32EintID];
	
#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	u16VectNum=MCU_stEINTAttribute.u16EINTvectList[0]+u32EintID;
	
#endif	

	return MCU_u16InterruptCtrl((MCU_enIsrID)u16VectNum, OnOff);

}

#endif

#if MCU_mEINTtrigChgFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_u16EINTchgIntCondition												 
 Description   : external interrupt detect condition control
 
 In Parameter: 
 			u16EintID: EINT ID list in _RH850.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16EINTchgIntCondition(MCU_enEintID u32EintID,MCU_enEintTriggerID u32NewTrigerCondition)
{
	uint16 u16RetVal=DET_Err_NotErr;

	/*check ID is in range*/
	DET_ErrCheck(u32EintID<MCU_mMaxEINTchannelMount , DET_Err_EINTIDOutOfRange);
	
	/*check the triger ID input is right*/
	DET_ErrCheck(u32NewTrigerCondition<=HighLevel, DET_Err_EINTtrigerIDOutOfRange);
	DI();
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	MCU_stEINTAttribute.FCLA->CTL[u32EintID]=u32NewTrigerCondition;
	
#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	MCU_stEINTAttribute.FCLA[u32EintID>>3].CTL[u32EintID&7].u8Value=(uint8)u32NewTrigerCondition;
	
#endif	
	EI();
	return 	u16RetVal;

}

#endif

#if MCU_mEINTDeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vEINTDeInit												 
 Description   : external interrupt model clear
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vEINTDeInit(void)
{
}

#endif

#endif/*end of EINT module*/

#if (MCU_mADCModuleEnable!=0u)
uint32 MCU_u32ADCAUsingUnit;

/*****************************************************************************
 Function  : MCU_u16ADCinit												 
 Description   : ADC model initial in reset
 
 In Parameter: 
 			NULL

Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			this function execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16ADCinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32Loop,u32ChnUsed_P1,u32ChnUsed_P2,u32VirCh,u32ChnNumber;

	MCU_u32ADCAUsingUnit=0;
	for(u32Loop=0;u32Loop<MCU_mADCAUint_Number;u32Loop++)
	{
		if(u32Loop==0)
		{
			u32ChnUsed_P1=MCU_stADCAAttribute.ADCA_UsrCfg->u32ADCusingMask_ADCA0_P1;
			u32ChnUsed_P2=MCU_stADCAAttribute.ADCA_UsrCfg->u32ADCusingMask_ADCA0_P2;
			#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		                /*part1 AP port control by APM, other xS channel control by ALT function control*/
		                MCU_stADCAAttribute.APM[0]|=u32ChnUsed_P1 & 0xffff;
			#endif
		}
		else
		{
			u32ChnUsed_P1=MCU_stADCAAttribute.ADCA_UsrCfg->u32ADCusingMask_ADCA1_P1;
			u32ChnUsed_P2=MCU_stADCAAttribute.ADCA_UsrCfg->u32ADCusingMask_ADCA1_P2;
			#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
			if(u32ChnUsed_P2 !=0)
			{
		                /*part1 AP port control by APM, other xS channel control by ALT function control*/
		                MCU_stADCAAttribute.APM[1]|=u32ChnUsed_P2 & 0xffff;
			}
			#endif
		}

		/*ADCA unit is using!!*/
		if((u32ChnUsed_P1 !=0u) || (u32ChnUsed_P2 !=0u))
		{
			MCU_u32ADCAUsingUnit |=1<<u32Loop;
			
			/*set the virtual channel to phy channel one-to-one*/
			u32ChnNumber=MCU_stADCAAttribute.ChnlNumInUint[u32Loop];
			for(u32VirCh=0;u32VirCh<u32ChnNumber;u32VirCh++)
			{
			#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
				if(u32VirCh<32)
				{
					if((u32ChnUsed_P1 >>u32VirCh)==0)
					{
						if(u32ChnUsed_P2==0)
						{
				                            break;/*channel not set, then piont to next group*/
						}
						else
						{
							continue;
						}
					}
				}
				else
				{
					if((u32ChnUsed_P2 >>(u32VirCh-32))==0)
					{
						break;
					}
				}

				MCU_stADCAAttribute.ADCA[u32Loop].VCR[u32VirCh]=u32VirCh;
				
			#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)	&& (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
					
				if((u32ChnUsed_P1 >>u32VirCh)==0)
				{
					break;
				}

				if(u32VirCh <=MCU_mADCID_ADCA0I19)
				{
					MCU_stADCAAttribute.ADCA[u32Loop].VCR[u32VirCh]=u32VirCh+16;
				}
				else
				{
					if(u32VirCh ==MCU_mADCID_ADCA0I20_ISOVDD)
					{
						MCU_stADCAAttribute.ADCA[u32Loop].VCR[u32VirCh]=0x0f;
					}
					else if(u32VirCh ==MCU_mADCID_ADCA0_CPUtemperature)
					{
						MCU_stADCAAttribute.ADCA[u32Loop].TSNVCR=0x25;
					}
					else if(u32VirCh ==MCU_mADCID_ADCA0_PWGADiag)
					{
						MCU_stADCAAttribute.ADCA[u32Loop].PWDVCR=0/*the monitor channel setting*/;
					}
				}

				/*belowe is not finish!!*/
				/*ISOVDD diag channel vir control is ADCEnVCR20, 
						vir channel setting index must 1111B(vir 20),
						the diag ADC resault stroe in vir 20 resault DR*/
						
				/*PWGA diag channel vir control is ADCEnPWDVCR, 
						vir channel setting index as above,
						the diag ADC resault stroe in ADCEnPWDTSNDR , High 16bit*/
						
				/*Temperature Sensor diag channel vir control is ADCEnTSNVCR, 
						vir channel setting index must 100101B(vir 37),
						the diag ADC resault stroe in ADCEnPWDTSNDR , low 16bit*/
				
			#endif
			}
					
			MCU_stADCAAttribute.ADCA[u32Loop].ECR = 0x0c;	/*clear error flag*/
			MCU_stADCAAttribute.ADCA[u32Loop].ADCR = 0x12;	/*only use 10bit AD*/
			MCU_stADCAAttribute.ADCA[u32Loop].SMPCR = 0x18;/*set the clock speed to 24cycle*/
			MCU_stADCAAttribute.ADCA[u32Loop].SFTCR = 0;	/*keep DR value after read out!!*/
			
			MCU_stADCAAttribute.ADCA[u32Loop].SG1_3[0].SGCR= 0x00;/*multi mode, convert end interrupt disable*/
			MCU_stADCAAttribute.ADCA[u32Loop].SG1_3[0].SGVCSP=0;
			MCU_stADCAAttribute.ADCA[u32Loop].SG1_3[0].SGVCEP=u32ChnNumber;/*scan all of the channel*/
			MCU_stADCAAttribute.ADCA[u32Loop].SG1_3[0].SGMCYCR=0;/*scan the channel only once*/

		}
		
	}
	
	return u16RetVal;

}

/*****************************************************************************
 Function  : MCU_u16ADCstart												 
 Description   : ADC model start to convort
 
 In Parameter: 
 			NULL
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			ADC module using the one-shut mode, so please call this function if you need ADC resault
*****************************************************************************/
uint16 MCU_u16ADCstart(void)
{
		/*======RH850 F1X serial======*/
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
		if(MCU_u32ADCAUsingUnit & 1)
		{
			MCU_stADCAAttribute.ADCA[0].SG1_3[0].SGSTCR= 0x01;/*start trigger for convert*/
		}
		
		if(MCU_u32ADCAUsingUnit & 2)
		{
			MCU_stADCAAttribute.ADCA[1].SG1_3[0].SGSTCR= 0x01;/*start trigger for convert*/
		}
	
		/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	
		if(MCU_u32ADCAUsingUnit & 1)
		{
			MCU_stADCAAttribute.ADCA[0].SG1_3[0].SGSTCR= 0x01;/*start trigger for convert*/
		}

		/*CPU temp monitor is enable*/
		if(MCU_stADCAAttribute.ADCA[0].TSNVCR == 0x25)
		{
			MCU_stADCAAttribute.ADCA[0].TSG.TSNSGCR=1;
		}
		/*the PWGA-Diag is not suport because the PWGA need set trigger in PWSAnPVCRx_y */	
		
#endif

	return DET_Err_NotErr;

}

#if (MCU_mADCstopEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16ADCstop												 
 Description   : ADC model stop to convort
 
 In Parameter: 
			NULL
			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCstop(void)
{

/*======RH850 F1X serial======*/
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
			
	
	if(MCU_u32ADCAUsingUnit & 1)
	{
		MCU_stADCAAttribute.ADCA[0].SG1_3[0].SGCR &= ~0x01;/*multi mode, convert end interrupt disable*/
		MCU_stADCAAttribute.ADCA[0].ADHALTR =1;/*ADCA change to HALT*/
	}
	
	if(MCU_u32ADCAUsingUnit & 2)
	{
		MCU_stADCAAttribute.ADCA[1].SG1_3[0].SGCR &= ~0x01;/*multi mode, convert end interrupt disable*/
		MCU_stADCAAttribute.ADCA[1].ADHALTR =1;/*ADCA change to HALT*/
	}

/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	if(MCU_u32ADCAUsingUnit & 2)
	{
		MCU_stADCAAttribute.ADCA[1].SG1_3[0].SGCR &= ~0x01;/*multi mode, convert end interrupt disable*/
		MCU_stADCAAttribute.ADCA[1].ADHALTR =1;/*ADCA change to HALT*/
	}
	
#endif
	
	return DET_Err_NotErr;

}
#endif

#if 0/*(MCU_mADCSleepEnable !=0u)*/
/*****************************************************************************
 Function  : MCU_u16ADCsleep												 
 Description   : ADC module go to sleep before system into standby mode
 
 In Parameter: 
 			NULL
 			
Return Value:
 			DET_Err_NotErr
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCsleep(void)
{
	
	
	return DET_Err_NotErr;

}

/*****************************************************************************
 Function  : MCU_u16ADCwakeUp												 
 Description   : ADC module leave sleep mode after system out form halt/stop mode
 
 In Parameter: 
 			NULL
 			
Return Value:
 			DET_Err_NotErr
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCwakeUp(void)
{

	return DET_Err_NotErr;
}
#endif
/*****************************************************************************
 Function  : MCU_u16ADCstart												 
 Description   : external interrupt detect condition control
 
 In Parameter: 
 			u16EintID: EINT ID list in _RH850.h
 			u8NewTrigerCondition: new detect condition for external interrupt request
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			this ISR is not use, we using the one-shut mode, it will auto stop if convert finish
*****************************************************************************/
void MCU_vADCIsr(void)
{

}

/*****************************************************************************
 Function  : MCU_u16ADCgetResault												 
 Description   :get the ADC resault
 
 In Parameter: 
 			u8ChannelID: ADC ID list in _RH850.h
 			*u16AD_Resault: ADC output resault address
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16ADCgetResault(MCU_enAdcaID u32ChannelID, uint16 *u16AD_Resault)
{
	uint16 u16RetVal=DET_Err_NotErr;
		
		/*======RH850 F1X serial======*/
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	if(u32ChannelID < MCU_mADC_MaxChPerUnit)
	{
		*u16AD_Resault=MCU_stADCAAttribute.ADCA[0].DR[u32ChannelID];
	}
	else
	{
		*u16AD_Resault=MCU_stADCAAttribute.ADCA[1].DR[u32ChannelID-MCU_mADC_MaxChPerUnit];
	}
		
		/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	if(u32ChannelID <= MCU_mADC_MaxChPerUnit)
	{
		*u16AD_Resault=MCU_stADCAAttribute.ADCA[0].DR[u32ChannelID];
	}
	else if(u32ChannelID==MCU_mADCID_ADCA0_CPUtemperature)
	{
		*u16AD_Resault=(uint16)(MCU_stADCAAttribute.ADCA[0].PWDTSNDR & 0xFFFF);
	}
	else if(u32ChannelID==MCU_mADCID_ADCA0_PWGADiag)
	{
		*u16AD_Resault=(uint16)((MCU_stADCAAttribute.ADCA[0].PWDTSNDR>>16) & 0xFFFF);
	}
	else
	{
		*u16AD_Resault=0;
		DET_ErrReport(DET_Err_ADCchannelOutOfRange);
	}
	
#endif
	
   	 return u16RetVal;
}

#if (MCU_mADCDeInitFuncEnable!=0u)
/*****************************************************************************
 Function  : MCU_vADCDeInit												 
 Description   :clean the ADC model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vADCDeInit(void)
{

}

#endif

#endif/*end of ADC module*/


#if (MCU_mRLIN3UartModuleEnable !=0u)

MCU_tstRLIN3UartCtrl	MCU_stRLIN3UartRunStatus[MCU_mRLIN3Uint_Number];


/*****************************************************************************
 Function  : MCU_u16RLIN3Uart_Init												 
 Description   :initial the RLIN3 UART model
 
 In Parameter: 
 			NULL

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function run before system-mainloop
*****************************************************************************/
static uint16 MCU_u16RLIN3Uart_Init(void)
{

	uint32 u32Loop,u32BaudRateValue;
	
	/*======RH850 F1X serial======*/
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	
	uint32 u32ClK=MCU_stClockStatus.ClkSpeed_C_ISO_LINS;
	
	/*======RH850 D1X serial======*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	uint32 u32ClK=MCU_stClockStatus.ClkSpeed_CKSC_IRLINS;

#endif

	uint16 u16BaudRate,u16ComunicatSetting,u16VectNum;
	uint16 u16RetVal=DET_Err_NotErr;
	
	for(u32Loop = 0u;u32Loop<MCU_mRLIN3Uint_Number;u32Loop++)
	{
		u16BaudRate=MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16BaudRate;
		if(u16BaudRate !=0u)
		{

			DI();
			
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LCUC=0;		/*internal reset*/
			while(MCU_stRLIN3Attribute.RLIN3[u32Loop].LMST !=0U);	/*wait reset status*/
			
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LMD=1;		/*YES, we only using the UART mode*/


			u32ClK/= (8); /*default setting is 8 sample, 0 divider*/
			u32BaudRateValue=u32ClK/u16BaudRate;
			
			DET_ErrCheck(u32BaudRateValue<=0xffff, DET_Err_SerialParaInvalib);
			u32BaudRateValue -=1;
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LWBR=0x70;	/*default setting is 8 sample, 0 divider*/
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LBRP0=u32BaudRateValue & 0xff;		/*baudrate setting*/
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LBRP1=(u32BaudRateValue>>8) & 0xff;		/*baudrate setting*/
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LUOR1=0x08;								/*internal when tranfer finish data*/
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LSC=0x00/*0x30*/;								/*0bit space between byte transfer*/
			
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LEDE=0x00;	/*default setting is error detect disable*/

			u16ComunicatSetting=0<<0;														/*0=8bit, 1=7bit*/
			u16ComunicatSetting|=MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16Msb<<1;		/*LSB=0,MSB=1*/
			u16ComunicatSetting|=(MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16StopBit)<<2;	/*0=stopbit_1, 1= stopBit_2*/
			u16ComunicatSetting|=MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16Parity<<3;		/*	00: Parity prohibited
																							01: Even Parity
																							10: 0 Parity
																							11: Odd parity*/
																							
			u16ComunicatSetting |=MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16Rx_InversionOutput<<5;	/*RX Inversion or not*/
			u16ComunicatSetting |=MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].u16Tx_InversionInput<<6;	/*TX Inversion or not*/
			MCU_stRLIN3Attribute.RLIN3[u32Loop].LBFC=u16ComunicatSetting & 0xff;


			u16VectNum=MCU_stRLIN3Attribute.VectList[u32Loop];
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

                            if(MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].vpSendFinish !=MCU_vNotExpINT)
                            {
            			MCU_u16InterruptCtrl((MCU_enIsrID)(u16VectNum+1), 1);/*TX interrupt enable*/
                            }
                            
                            if(MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].vu8RecCallBack !=MCU_vNotExpINT_u8)
                            {
            			MCU_u16InterruptCtrl((MCU_enIsrID)(u16VectNum+2), 1);/*RX interrupt enable*/
                            }
											     				/*other interrupt disable in default*/
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

                            if(MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].vpSendFinish !=MCU_vNotExpINT)
                            {
			        MCU_u16InterruptCtrl((MCU_enIsrID)(u16VectNum), 1);	/*TX interrupt enable*/
                            }
                            if(MCU_stRLIN3Attribute.RLIN3_UsrCfg[u32Loop].vu8RecCallBack !=MCU_vNotExpINT_u8)
                            {
			        MCU_u16InterruptCtrl((MCU_enIsrID)(u16VectNum+1), 1);/*RX interrupt enable*/
                            }
											     				/*other interrupt disable in default*/

#endif

			MCU_stRLIN3Attribute.RLIN3[u32Loop].LCUC=1;		/*internal reset cancel*/
			while(MCU_stRLIN3Attribute.RLIN3[u32Loop].LMST !=1);	/*wait reset status*/

			EI();
			
		}	

	}
	
	return u16RetVal;
}

/*****************************************************************************
 Function  : MCU_u16LinUartSend												 
 Description   :Lin-UART send data control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _RH850.h
 			pu8DataHead: need send data head 
 			u16SendLen: tottal bytes data to send
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16RLIN3UartSend(MCU_enRlin3UartID u16channel, uint8 pu8DataHead[], uint16 u16SendLen)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32Loop,u32BufferShift;
	
	DET_ErrCheck(u16channel<=MCU_mRLIN3Uint_Number, DET_Err_LinUartIDOutOfRange);
	DET_ErrCheck(u16SendLen!=0u, DET_Err_UARTLenthError);

	if(MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen==0)
	{
		MCU_stRLIN3UartRunStatus[u16channel].pu8DataHead=pu8DataHead;
		MCU_stRLIN3UartRunStatus[u16channel].u16TottalDataLen=u16SendLen;
		if(u16SendLen>=9)
		{
			/*if data lenth is 9, the fisrt buffer is buff[0]*/
			MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen=9;
			u32BufferShift=0;
			u16SendLen=9;
		}
		else
		{
			/*if data lenth is other lenth, the fisrt buffer is buff[1]*/
			MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen=u16SendLen;
			u32BufferShift=1;
		}

		/*update data to buffer*/
		for(u32Loop=0;u32Loop<u16SendLen;u32Loop++)
		{
			MCU_stRLIN3Attribute.RLIN3[u16channel].LUDB[u32BufferShift++]=pu8DataHead[u32Loop];
		}
		
		
		MCU_stRLIN3Attribute.RLIN3[u16channel].LDFC = (uint8)u16SendLen;/*transfer data lenth*/
		MCU_stRLIN3Attribute.RLIN3[u16channel].LTRC = 2;/*transfer data from buffer and trigger to start send*/
		
	}
	else
	{
		u16RetVal=DET_Err_SerialIsBusy;
	}

	return u16RetVal;
	
}

#if (MCU_mRlin3CtrlEnale !=0u)
/*****************************************************************************
 Function  : MCU_u16RLIN3UartCtrl												 
 Description   :Lin-UART send and receive control
 
 In Parameter: 
 			u16channel:LIN-UART ID list in _RH850.h
 			u8SendEnable: enable send data or not
 			u8RecEnable: enable receive data or not
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16RLIN3UartCtrl(MCU_enRlin3UartID u16channel, uint8 u8SendEnable, uint8 u8RecEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
	DET_ErrCheck(u16channel<MCU_mRLIN3Uint_Number, DET_Err_LinUartIDOutOfRange);

	if(u8SendEnable !=0u)
	{
		MCU_stRLIN3Attribute.RLIN3[u16channel].LUOER |=(uint8)1;
	}
	else
	{
		MCU_stRLIN3Attribute.RLIN3[u16channel].LUOER &=(uint8)(~1);
	}

	if(u8RecEnable !=0u)
	{
		MCU_stRLIN3Attribute.RLIN3[u16channel].LUOER |=(uint8)2;
	}
	else
	{
		MCU_stRLIN3Attribute.RLIN3[u16channel].LUOER &=(uint8)(~2);
	}
	
	return u16RetVal;
	
}
#endif

/*****************************************************************************
 Function  : MCU_vRLIN3UartIsr_Tx												 
 Description   :LIN UART model Tx interrupt
 
 In Parameter: 
 			u16channel: channel ID, 
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vRLIN3UartIsr_Tx(MCU_enRlin3UartID u16channel)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 u16SendLen;
	uint32 u32BufferShift,u32Loop,u32WorkingBufIndex;
	
	DET_ErrCheck(u16channel<MCU_mRLIN3Uint_Number, DET_Err_LinUartIDOutOfRange);

	while((MCU_stRLIN3Attribute.RLIN3[u16channel].LST&1)==0);/*wait data shift finish*/
	
	if(MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen>= \
			MCU_stRLIN3UartRunStatus[u16channel].u16TottalDataLen)
	{
		/*send finish*/
		MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen=0;
		MCU_stRLIN3Attribute.RLIN3_UsrCfg[u16channel].vpSendFinish();
	}
	else
	{
		u16SendLen=MCU_stRLIN3UartRunStatus[u16channel].u16TottalDataLen -\
			MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen;

		u32WorkingBufIndex=MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen;/*record work buffer index*/
		if(u16SendLen>=9)
		{
			/*if data lenth is 9, the fisrt buffer is buff[0]*/
			MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen +=9;
			u32BufferShift =0;
			u16SendLen=9;
		}
		else
		{
			/*if data lenth is other lenth, the fisrt buffer is buff[1]*/
			MCU_stRLIN3UartRunStatus[u16channel].u16WorkingDataLen +=u16SendLen;
			u32BufferShift=1;
		}

		/*update data to buffer*/
		for(u32Loop=0;u32Loop<u16SendLen;u32Loop++)
		{
			MCU_stRLIN3Attribute.RLIN3[u16channel].LUDB[u32BufferShift++]=\
					MCU_stRLIN3UartRunStatus[u16channel].pu8DataHead[u32WorkingBufIndex++];
		}
				
		MCU_stRLIN3Attribute.RLIN3[u16channel].LDFC =(uint8)u16SendLen;/*transfer data lenth*/
		MCU_stRLIN3Attribute.RLIN3[u16channel].LTRC = 2;/*transfer data from buffer and trigger to start send*/
			
	}
	

}

/*****************************************************************************
 Function  : MCU_vRLIN3UartIsr_Rx												 
 Description   :LIN UART model Rx interrupt
 
 In Parameter: 
 			u16channel: channel ID, 
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vRLIN3UartIsr_Rx(MCU_enRlin3UartID u16channel)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint8 u8RecData,u8Err;
	
	DET_ErrCheck(u16channel<MCU_mRLIN3Uint_Number, DET_Err_LinUartIDOutOfRange);

	u8RecData=MCU_stRLIN3Attribute.RLIN3[u16channel].LURDR;
	u8Err=MCU_stRLIN3Attribute.RLIN3[u16channel].LEST;
	
	MCU_stRLIN3Attribute.RLIN3[u16channel].LEST=0x00;/*clear error*/
	
	if( u8Err & (uint8)((uint8)(1u<<6)|(uint8)(1u<<2)))/*over run or parity error*/
	{
		u8Err &=(uint8)((uint8)(1u<<6)|(uint8)(1u<<2));/*clear other error*/
		MCU_stRLIN3Attribute.RLIN3_UsrCfg[u16channel].vu8ErrCallBack(u8Err);
	}

	/*receive data callback function*/
	MCU_stRLIN3Attribute.RLIN3_UsrCfg[u16channel].vu8RecCallBack(u8RecData);

}

#if (MCU_mRLIN3DeInitFuncEnable!=0u)
/*****************************************************************************
 Function  : MCU_vRLIN3Uart_Deinit												 
 Description   :clean UART model
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void MCU_vRLIN3Uart_Deinit(void)
{	

}

#endif

#endif/*end of LIN-UART module*/



#if (MCU_mIICModuleEnable!=0u)

MCU_tstIICctrl MCU_stIICrunStatus[MCU_mRIIC_Unit];

/*****************************************************************************
 Function  : MCU_u16IICinit												 
 Description   :IIC model initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			this function execute before system-mailoop
*****************************************************************************/
static uint16 MCU_u16IICinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;

	uint32 u32Loop,u32SlaveIndex,PinIndex,PortIndex,u32WriteValue;
	uint32 u32ClkSpeed,u32ClkDivider,u32Group;
	
	#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
	u32ClkSpeed =MCU_stClockStatus.CPUCLK_Speed/2;
	#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	u32ClkSpeed = MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
	#endif

	DI();
	for(u32Loop=0;u32Loop<MCU_mRIIC_Unit;u32Loop++)
	{
		if(MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].u32TansferSpeed  !=0u)
		{
			#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
			u32ClkSpeed =MCU_stClockStatus.CPUCLK_Speed/2;
			#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
			u32ClkSpeed = MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
			#endif 
			
			u32ClkSpeed/=MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].u32TansferSpeed ;

			u32ClkDivider=0;
			while(u32ClkSpeed > 64)
			{
				u32ClkSpeed>>=1;
				u32ClkDivider++;
			}
			
			DET_ErrCheck(u32ClkDivider<=7, DET_Err_IICBpsOutOfRange);

			MCU_stRIICAttribute.RIIC[u32Loop].CR1 &=~(1<<7);/*disable IIC*/
			MCU_stRIICAttribute.RIIC[u32Loop].CR1 |= (1<<6);/*reset IIC*/
			MCU_stRIICAttribute.RIIC[u32Loop].CR1 |= (1<<7);/*enable IIC*/
			MCU_stRIICAttribute.RIIC[u32Loop].CR1 &=~(3<<2);/*disable IIC*/		
			
			MCU_stRIICAttribute.RIIC[u32Loop].MR1 = (1<<7)|(u32ClkDivider<<4);	
			u32ClkSpeed/=2;
			u32ClkSpeed--;
					
			MCU_stRIICAttribute.RIIC[u32Loop].BRH=0xe0+u32ClkSpeed ;	/*baud rate setting*/
			MCU_stRIICAttribute.RIIC[u32Loop].BRL= 0xe0+u32ClkSpeed ;	/*baud rate setting*/
			
			MCU_stRIICAttribute.RIIC[u32Loop].MR2 = 0x40;	/*SDA small delay*/
			MCU_stRIICAttribute.RIIC[u32Loop].MR3 = 0x10;	/*ask and other timing config, keep defalut,BUT ACKBR/ACKBT changeable*/
			MCU_stRIICAttribute.RIIC[u32Loop].FER = 0x00;		/*ask and other communicate config, keep defalut*/
			/*MCU_stRIICAttribute.RIIC[u32Loop].SAR0= 0xAA;		slave Address -->only use in slave mode*/
			MCU_stRIICAttribute.RIIC[u32Loop].SER = 0x00;		/*slave communicate config, keep defalut*/

			MCU_stRIICAttribute.RIIC[u32Loop].CR2  = (3<<5);/*master mode, Tx mode in default*/
            		MCU_stRIICAttribute.RIIC[u32Loop].IER = (1<<6)|(1<<7)|(1<<5);/*RX,Tx,Tx_Empty interrupt enable*/
			

			for(u32SlaveIndex=0;u32SlaveIndex<MCU_mI2CMaxSlaveInMaster;u32SlaveIndex++)
			{
				if(MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].stSlaveCB[u32SlaveIndex].vpSendfinishCB_BuffEmpty !=MCU_vNotExpINT)
				{
					MCU_u16InterruptCtrl((MCU_enIsrID)MCU_stRIICAttribute.VectList[u32Loop].BufferEmptyVect, 1);		/*RIIC Transmit buffer Empty  interrupt*/
				}
				
				if(MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].stSlaveCB[u32SlaveIndex].vpSendfinishCB !=MCU_vNotExpINT)
				{
					MCU_u16InterruptCtrl((MCU_enIsrID)MCU_stRIICAttribute.VectList[u32Loop].SendFinshVect, 1);		/*RIIC Transmit end interrupt*/
				}
				
				if(MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].stSlaveCB[u32SlaveIndex].vpRecFinishCB !=MCU_vNotExpINT)
				{
					MCU_u16InterruptCtrl((MCU_enIsrID)MCU_stRIICAttribute.VectList[u32Loop].ReceiveVect, 1);		/*RIIC Receive end interrupt*/
				}
				
				/*==>error interrupt, we only proccess only once before send/receive finish callback*/
				if(MCU_stRIICAttribute.RIIC_UsrCfg[u32Loop].stSlaveCB[u32SlaveIndex].vu8ErrCB !=MCU_vNotExpINT_u8)
				{
					MCU_u16InterruptCtrl((MCU_enIsrID)MCU_stRIICAttribute.VectList[u32Loop].ErrorVect, 1);		/*RIIC communication error / event generation interrupt*/
				}
				
			}
			
			MCU_stRIICAttribute.RIIC[u32Loop].CR1 &=~((1<<6));/*Not reset IIC*/

		}		
		
	}

	EI();

	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16IIC_MasterStartCondition												 
 Description   :IIC triger start-condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static uint16 MCU_u16IIC_MasterStartCondition(MCU_enRiicID u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u8I2C_masterID<MCU_mRIIC_Unit, DET_Err_IICIDOutOfRange);

	while((MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 & (uint32)(1u<<7)) !=0u )/*busy bit*/
	{
		;/*wait */
	}	

	DI();
	MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 |= (uint32)(1U<<1);/*START condition request*/
	EI();
	
	while((MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 & (uint32)(1U<<2)) ==0u )/*wait start condition finish*/
	{
		;/*wait */
	}
	
	return u16RetVal;
	
}


/*****************************************************************************
 Function  : MCU_u16IIC_MasterStopCondition												 
 Description   :IIC triger stop -condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static uint16 MCU_u16IIC_MasterStopCondition(MCU_enRiicID u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 wait=0x800;

	DET_ErrCheck(u8I2C_masterID<MCU_mRIIC_Unit, DET_Err_IICIDOutOfRange);
	
	DI();
//	MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 &= ~(uint32)((1u<<6)|(1<<3));/*clear RIICnTEND and RIICnSTOP*/
         MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 =0;/*clear all flag*/
	MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 |= (uint32)(1u<<3);/*STOP condition request*/
	EI();
	
	while((MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 & (uint32)(1u<<3)) ==0u )/*wait stop condition finish*/
	{
		;/*wait */
	}
	
	return u16RetVal;
	
}


#if (MCU_mIICRestartEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16IIC_MasterReStartCondition												 
 Description   :IIC triger Restart-condition
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterReStartCondition(MCU_enRiicID u8I2C_masterID)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 wait=0x800;
	uint32 u32SetVal;
	
	DET_ErrCheck(u8I2C_masterID<MCU_mRIIC_Unit, DET_Err_IICIDOutOfRange);

        if((MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 & (1<<7)) == 0)
        {
                /*RE-Start condition only valib in busy status!!*/
                DET_ErrReport(DET_Err_IICNotReady);
        }
        else
        {
            	DI();
            	MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 &=~(1<<2);/*clear start flag*/
            	MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 /*|*/= (uint32)((1u<<2)|(0x60));/*RE-START condition request, Tx Master mode*/
            	EI();
            	
            	while((MCU_stRIICAttribute.RIIC[u8I2C_masterID].SR2 & (uint32)(1u<<2)) ==0u )/*wait start condition finish*/
            	{
            		;/*wait */
            	}
        }
		
	return u16RetVal;
}
#endif

/*****************************************************************************
 Function  : MCU_u8IIC_GetSlaveIndex												 
 Description   :find out the slave index in the master channel list
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			u8SalveDevice_index: slave index in this IIC net
 			
Return Value:
 			u32Loop:slave index in master list
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static uint8 MCU_u8IIC_GetSlaveIndex(MCU_enRiicID u8I2C_masterID,uint8 u8SalveAddr)
{
        uint32 u32Loop;
        uint16 u16RetVal=DET_Err_NotErr;

        for(u32Loop=0;u32Loop<MCU_mI2CMaxSlaveInMaster;u32Loop++)
        {
            if((uint8)MCU_stRIICAttribute.RIIC_UsrCfg[u8I2C_masterID].stSlaveCB[u32Loop].u32SlaveAddr == u8SalveAddr)
            {
                break;
            }
        }

        DET_ErrCheck(u32Loop<MCU_mI2CMaxSlaveInMaster, DET_Err_IICSlaveIDOutOfRange);
        
        return (uint8)u32Loop;
        
}

/*****************************************************************************
 Function  : MCU_u16IIC_MasterWrite												 
 Description   :IIC master node send out data to the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			u8SalveDevice_index: slave index in this IIC net
 			pDataHead[]: send out data head pionter
 			u16Lenth: send out data tottal lenth
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterWrite(MCU_enRiicID u8I2C_masterID,uint8 u8SalveAddr, uint8 pDataHead[], uint16 u16Lenth)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 wait=0x800;
	
	DET_ErrCheck(u8I2C_masterID<MCU_mRIIC_Unit, DET_Err_IICIDOutOfRange);

	/*Start-Condition*/
	MCU_u16IIC_MasterStartCondition(u8I2C_masterID);
	
	if(MCU_stIICrunStatus[u8I2C_masterID].u8Runmode == MCU_enRIIC_Ready)
	{
		DI();
		MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 /*|*/=(uint32)(3u<<5);
		MCU_stRIICAttribute.RIIC[u8I2C_masterID].MR3 &=~(1<<2);/*0 as the ACK bit level, defalut the N-ACK signal is not-proccess*/
		EI();
					        
		MCU_stIICrunStatus[u8I2C_masterID].u8Runmode=MCU_enRIIC_Writting;		
		MCU_stIICrunStatus[u8I2C_masterID].pu8DataHead=pDataHead;
		MCU_stIICrunStatus[u8I2C_masterID].u16TottalDataLen=u16Lenth;
		MCU_stIICrunStatus[u8I2C_masterID].u16WorkingDataLen=0;
		MCU_stIICrunStatus[u8I2C_masterID].u8SlaveChannel=MCU_u8IIC_GetSlaveIndex(u8I2C_masterID,u8SalveAddr);
		
		MCU_stRIICAttribute.RIIC[u8I2C_masterID].DRT=(u8SalveAddr<<1)+0 ;	/*SEND out address and Write_bit !!*/

	}	
	else
	{
		u16RetVal = DET_Err_IICIsBusy;
	}
	
	return u16RetVal;
	
}


#if (MCU_mIICReadFunctionEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16IIC_MasterRead												 
 Description   :IIC master node receive data from the slave node
 
 In Parameter: 
 			u8I2C_masterID: IIC ID list in _RH850.h
 			u8SalveDevice_index: slave index in this IIC net
 			*pDataHead: send out data head, but the fisrt byte is slave address!!!
 			u16Lenth: receive data tottal lenth
 			
Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16IIC_MasterRead(MCU_enRiicID u8I2C_masterID,uint8 u8SalveAddr, uint8 *pDataHead, uint16 u16Lenth)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32DummyRead;
	
	DET_ErrCheck(u8I2C_masterID<MCU_mRIIC_Unit, DET_Err_IICIDOutOfRange);
	
	/*Start-Condition*/
	MCU_u16IIC_MasterStartCondition(u8I2C_masterID);
	
	if(MCU_stIICrunStatus[u8I2C_masterID].u8Runmode == MCU_enRIIC_Ready)
	{
		DI();
		MCU_stRIICAttribute.RIIC[u8I2C_masterID].CR2 =(uint32)(3u<<5);
		if(u16Lenth<=2)
		{
		        MCU_stRIICAttribute.RIIC[u8I2C_masterID].MR3 |=(uint32)(1U<<6u);/* WAIT-BIT */
		}
		else
		{
		        MCU_stRIICAttribute.RIIC[u8I2C_masterID].MR3 &=~(uint32)(1U<<6u);/* WAIT-BIT */
		}
		EI();
		
		MCU_stIICrunStatus[u8I2C_masterID].u8Runmode=MCU_enRIIC_Reading;
		MCU_stIICrunStatus[u8I2C_masterID].pu8DataHead=pDataHead;
		MCU_stIICrunStatus[u8I2C_masterID].u16TottalDataLen=u16Lenth;
		MCU_stIICrunStatus[u8I2C_masterID].u16WorkingDataLen=0;
		MCU_stIICrunStatus[u8I2C_masterID].u8SlaveChannel=MCU_u8IIC_GetSlaveIndex(u8I2C_masterID,u8SalveAddr);
		
		MCU_stRIICAttribute.RIIC[u8I2C_masterID].DRT=(u8SalveAddr<<1)|1 ;	/*SEND out address and Read_Bit !!*/
	}
	else
	{
		u16RetVal = DET_Err_IICIsBusy;
	}	
	
	return u16RetVal;
	
}

#endif

/*****************************************************************************
 Function  : MCU_vRIIC_Isr_WriteByteFinish												 
 Description   :IIC master node send finish ISR
 
 In Parameter: 
 			u16Ch: IIC ID list in _RH850.h
 			u32BufferEmpty_Req: interrupt request type,
 			
 				0 = send fihish type
 				1 = send buffer empty type
			
Return Value:
 		NULL
 			
 NOTE: 		
 		NULL
*****************************************************************************/
void MCU_vRIIC_Isr_WriteByteFinish(MCU_enRiicID u16Ch,uint32 u32BufferEmpty_Req)
{
	uint8 u8SlaveID=MCU_stIICrunStatus[u16Ch].u8SlaveChannel;
	uint16 u16Lenth=0u;
	uint16 u16RetVal=DET_Err_NotErr;
	
	MCU_stIICrunStatus[u16Ch].u8Error |=MCU_stRIICAttribute.RIIC[u16Ch].SR2& 0x13;
	/*IIC is running in send mode*/
	if(MCU_stIICrunStatus[u16Ch].u8Runmode == MCU_enRIIC_Writting)	
	{

                /*Slave Not-ACK, then stop the transfer and stop-condition*/
	        if((MCU_stRIICAttribute.RIIC[u16Ch].SR2 & (1<<4)) !=0u)
	        {
                         MCU_u16IIC_MasterStopCondition(u16Ch);
	                MCU_stIICrunStatus[u16Ch].u8Runmode =MCU_enRIIC_Ready;
	                
		        MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(MCU_stIICrunStatus[u16Ch].u8Error);
		        MCU_stIICrunStatus[u16Ch].u8Error=0u;/*clear record!*/
		        
	        }
	        else
                {
            		/*send finish, index add first!*/
	                  u16Lenth=MCU_stIICrunStatus[u16Ch].u16WorkingDataLen++;
            		
            		/*Len index add one only in send finish,
            		if we in empty interrupt request, we add one in next interrupt loop
            		if(u32BufferEmpty_Req ==0)
            		{
            			u16Lenth++;
            		}*/
            		
            		if(u16Lenth>= MCU_stIICrunStatus[u16Ch].u16TottalDataLen)
            		{
            			while((MCU_stRIICAttribute.RIIC[u16Ch].SR2 & (1<<6)) ==0u)
            			{
            				;/*wait data last bit shift finish*/
            			}
            			
            			/*STOP-condition at the end of data send*/
                                    MCU_u16IIC_MasterStopCondition(u16Ch);

            			/*send finish, then set the status to ready*/
            			MCU_stIICrunStatus[u16Ch].u8Runmode = MCU_enRIIC_Ready;
            			
            			if(MCU_stIICrunStatus[u16Ch].u8Error!=0u)
            			{
            				/*error happen, need call err_CB before call finish_CB*/
            				MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(MCU_stIICrunStatus[u16Ch].u8Error);
            				MCU_stIICrunStatus[u16Ch].u8Error=0u;/*clear record!*/
            			}
            			
            			/*send finish, then call finish_CB*/
            			if(u32BufferEmpty_Req ==0)
            			{
            				MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vpSendfinishCB();
            			}
            			else
            			{
            				MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vpSendfinishCB_BuffEmpty();
            			}

            		}
            		else
            		{		        
            			/*send not finish, then continue to send out data! IIC mode defalut is 8bit lenth*/
            			MCU_stRIICAttribute.RIIC[u16Ch].DRT= MCU_stIICrunStatus[u16Ch].pu8DataHead[u16Lenth];
            		}
            		
            	}
	
	}	
	else
	{
		DET_ErrReport(DET_Err_IICIsBusy);
	}
	
}


/*****************************************************************************
 Function  : MCU_vRIIC_Isr_DataRecive												 
 Description   :IIC master node receive data ISR
 
 In Parameter: 
 			u16Ch: IIC ID list in _RH850.h
			
Return Value:
 		NULL
 			
 NOTE: 		
 		NULL
*****************************************************************************/
void MCU_vRIIC_Isr_ReadByteFinish(MCU_enRiicID u16Ch)
{

#if (MCU_mIICReadFunctionEnable !=0u)

	uint8 u8SlaveID=MCU_stIICrunStatus[u16Ch].u8SlaveChannel;
	uint16 u16Lenth;
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 u32DummyRead;

	if(MCU_stIICrunStatus[u16Ch].u8Runmode == MCU_enRIIC_Reading)
	{
                /*Slave Not-ACK, then stop the transfer and stop-condition*/
	        if((MCU_stRIICAttribute.RIIC[u16Ch].SR2 & (1<<4)) !=0u)
	        {
                          MCU_u16IIC_MasterStopCondition(u16Ch);
	                MCU_stIICrunStatus[u16Ch].u8Runmode =MCU_enRIIC_Ready;
	                
		        MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(MCU_stIICrunStatus[u16Ch].u8Error);
		        MCU_stIICrunStatus[u16Ch].u8Error=0u;/*clear record!*/
	        }
            	else
                 {
                          /*first byte, dummy read for clock output*/
                          u16Lenth=MCU_stIICrunStatus[u16Ch].u16WorkingDataLen++;		
                          
        	                 if(u16Lenth== MCU_stIICrunStatus[u16Ch].u16TottalDataLen-2u)
        	                 {
        	                           MCU_stRIICAttribute.RIIC[u16Ch].MR3 |=(uint32)(1U<<6u);/* WAIT-BIT */
        	                 }
        	                 else if(u16Lenth== MCU_stIICrunStatus[u16Ch].u16TottalDataLen-1u)
        	                 {
        	                 		MCU_stRIICAttribute.RIIC[u16Ch].MR3 |=(uint32)(3U<<3u);/*N-ACKBT in last byte and WAIT-BIT in last byte*/
        	                 }
        	                 
            	        if(u16Lenth == 0)
            	        {
            			u32DummyRead=MCU_stRIICAttribute.RIIC[u16Ch].DRR;/*read data to supply clock output!!*/				
            	        }
            	        else
            	        {
            	            	if(u16Lenth>= MCU_stIICrunStatus[u16Ch].u16TottalDataLen)
            			{
            			        /*STOP Condition*/
                                        	MCU_stRIICAttribute.RIIC[u16Ch].SR2 &= ~(uint32)((1u<<6u)|(1<<3u));/*clear RIICnTEND and RIICnSTOP*/
                                        	MCU_stRIICAttribute.RIIC[u16Ch].CR2 |= (uint32)(1u<<3u);/*STOP condition request*/
            				
            				/*data receive, store it*/
            				MCU_stIICrunStatus[u16Ch].pu8DataHead[u16Lenth-1]=MCU_stRIICAttribute.RIIC[u16Ch].DRR;
                        	                  MCU_stRIICAttribute.RIIC[u16Ch].MR3 &=~(uint32)(1U<<6u);/* WAIT-BIT */
            	                    	while((MCU_stRIICAttribute.RIIC[u16Ch].SR2 & (uint32)(1u<<3u)) ==0u )/*wait stop condition finish*/
                                            {
                                            	;/*wait */
                                            }
                                            	
                                            /*clear all flag*/
                            	           MCU_stRIICAttribute.RIIC[u16Ch].SR2 =0;

            				/*send finish, then set the status to ready*/
            				MCU_stIICrunStatus[u16Ch].u8Runmode = MCU_enRIIC_Ready;
            				MCU_stIICrunStatus[u16Ch].u16WorkingDataLen=0;
            							
            				/*receive finish, then call finish_CB*/
            				MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vpRecFinishCB();

            			}
            			else
            			{
            				/*read data and output clock for next byte!!*/
            				MCU_stIICrunStatus[u16Ch].pu8DataHead[u16Lenth-1]=MCU_stRIICAttribute.RIIC[u16Ch].DRR;
            			}

            	        }
                }
	        
	}
	else
	{
		DET_ErrReport(DET_Err_RunModeOutOfRange);
	}
	
#endif

}

/*****************************************************************************
 Function  : MCU_vRIIC_Isr_Err												 
 Description   :IIC model Error interrupt
 
 In Parameter: 
 			u16Ch: IIC channel ID
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this is a dummy function, we only do once error process before calling send/receive
 			finish fucntion!!
*****************************************************************************/
void MCU_vRIIC_Isr_Err(MCU_enRiicID u16Ch)
{
	uint8 u8SlaveID=MCU_stIICrunStatus[u16Ch].u8SlaveChannel,u8Err;
	
	u8Err=MCU_stRIICAttribute.RIIC[u16Ch].SR2;
	
	/*STOP-condition if error happen*/
        MCU_u16IIC_MasterStopCondition(u16Ch);
        
	MCU_stIICrunStatus[u16Ch].u8Runmode = MCU_enRIIC_Ready;
	MCU_stIICrunStatus[u16Ch].u16WorkingDataLen=0;

	MCU_stRIICAttribute.RIIC_UsrCfg[u16Ch].stSlaveCB[u8SlaveID].vu8ErrCB(u8Err);

}


#if (MCU_mIICdeinitEnable!=0u)
/*****************************************************************************
 Function  : MCU_vIICdeinit												 
 Description   :IIC model de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			ALL IIC channel can not be used until MCU reset
*****************************************************************************/
void MCU_vIICdeinit(void)
{


}
#endif

#endif/*end of IIC module*/



#if (MCU_mCSIGModuleEnable!=0u)

MCU_tstCSGICtrl MCU_stCsigRunStatus[MCU_mCSIG_MaxChn];

/*****************************************************************************
 Function  : MCU_u16CSIGinit												 
 Description   :CSIG model de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function run before system mainloop
 			
*****************************************************************************/
static uint16 MCU_u16CSIGinit(void)
{
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	uint32 u32ClkSpeed=MCU_stClockStatus.ClkSpeed_C_ISO_CSIS;

#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	uint32 u32ClkSpeed=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
#endif

	uint32 Cfg0,Ctl1,Ctl2,BPS,SlaveMode,ClkType,u32Loop;

	for(u32Loop=0;u32Loop<MCU_mCSIG_MaxChn;u32Loop++)
	{
		MCU_stCsigRunStatus[u32Loop].u16WorkingMode=MCU_mCSIG_Ready;
		
		BPS=MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].Bps;
		if( BPS!=0u)
		{
			SlaveMode=MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].SlaveMode;
			ClkType = MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].ClkType;
			

			Ctl1=(ClkType & 2 )<<16;/*bit17: clock type*/
			Ctl1|=0<<16;	/*bit16:interrupt when Data Transfer finish*/
						/*bit7: data lenth is 16bit force*/
			Ctl1|=1<<5;	/*bit5: Pin data check in send out data*/		
			Ctl1|=0<<3;	/*bit3: Loop-back mode NOT activated*/
			Ctl1|=1<<2;	/*bit2: Interrupt delay half colck*/
						/*bit1: Enables/disables handshake mode.*/
			Ctl1|=MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].HankShakeEnable<<1;
						/*bit0: Enables/disables slave select function*/
			Ctl1|=SlaveMode<<0;

			if(SlaveMode==0)/*in Master mode*/
			{
				Ctl2=0;/*higher 3bit: Clock not divide*/
				Ctl2+=((u32ClkSpeed/2/BPS) & 0x0FFF) -1;				
			}
			else
			{
				Ctl2=0xF000;/*in slave mode*/
			}

			Cfg0 = MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].Parity<<28;/*bit28,29: parity setting*/
																/*bit24~27: DataLen, keep 16bit setting(0)*/
			Cfg0 |=MCU_stCSIGAttribute.CSIG_UsrCfg[u32Loop].LSB_shift<<18;/*bit18: data direction setting, 1 = Lsb*/
			Cfg0 |=(ClkType & 1)<<16;								/*bit16: clock type setting*/

			DI();
			/*Register value update*/
			MCU_stCSIGAttribute.CSIG[u32Loop].CTL0.u8Value=0;
			MCU_stCSIGAttribute.CSIG[u32Loop].CTL1=Ctl1;
			MCU_stCSIGAttribute.CSIG[u32Loop].CTL2.u16Value=Ctl2;
			MCU_stCSIGAttribute.CSIG[u32Loop].CFG0=Cfg0;
			MCU_stCSIGAttribute.CSIG[u32Loop].BCTL0.u8Value=0;
			EI();
			
		}
		
	}

	return DET_Err_NotErr;
	
}

#if (MCU_mCSIGMasterSynchRWEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIG_MasterSynchRW												 
 Description   :CSIG model send data and receive data function
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			pSendDataHead: send out data head pionter
 			pRecDataHead: receive data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			this function send out one data and receive one data at the same time
 			
*****************************************************************************/
uint16 MCU_u16CSIG_MasterSynchRW(MCU_enCsigID u32CsigID,uint16 pSendDataHead[], uint16 pRecDataHead[], uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 VectNum;
	
	if(MCU_stCsigRunStatus[u32CsigID].u16WorkingMode==MCU_mCSIG_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		
		/*parameter*/
		MCU_stCsigRunStatus[u32CsigID].pu16SendDataHead=pSendDataHead;
		MCU_stCsigRunStatus[u32CsigID].pu16RecDataHead=pRecDataHead;		
		MCU_stCsigRunStatus[u32CsigID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen=0;
		MCU_stCsigRunStatus[u32CsigID].u16WorkingMode=MCU_mCSIG_TxRx;
		
		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL0.u8Value=0xE1;/*TX/RX mode*/
		MCU_stCSIGAttribute.CSIG[u32CsigID].BCTL0.u8Value=0x00;
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                 {
            		MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][0], 1); /*TX INT*/
                 }
                 
		MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][1], 0); /*RX INT -->disable, get receive data is TX INT*/
		
                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].ErrCB != MCU_vNotExpINT_u16)
                 {
		        MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][2], 1); /*Error INT*/
                 }
			
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIGAttribute.VectList[u32CsigID];
                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].ErrCB != MCU_vNotExpINT_u16)
                 {
		        MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1);	/*Receive Error INT*/
                 }
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT -->disable, get receive data is TX INT*/
		
                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                 {
		        MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1); /*TX INT*/
                 }
		
#endif
		
		MCU_stCSIGAttribute.CSIG[u32CsigID].TX0H.u16Value= pSendDataHead[0];/*send out data, base 16bit word*/
		
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}
#endif

#if (MCU_mCSIGMasterWriteEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIG_MasterWrite												 
 Description   :CSIG model send data function
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			pDataHead: send out data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
uint16 MCU_u16CSIG_MasterWrite(MCU_enCsigID u32CsigID,uint16 pDataHead[], uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint32 VectNum;

	if(MCU_stCsigRunStatus[u32CsigID].u16WorkingMode==MCU_mCSIG_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		
		/*parameter*/
		MCU_stCsigRunStatus[u32CsigID].pu16SendDataHead=pDataHead;
		MCU_stCsigRunStatus[u32CsigID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen=0;
		MCU_stCsigRunStatus[u32CsigID].u16WorkingMode=MCU_mCSIG_TxOnly;

		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL0.u8Value=0xC1;/*TX mode*/
		MCU_stCSIGAttribute.CSIG[u32CsigID].BCTL0.u8Value=0x00;
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                 {
		        MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][0], 1); /*TX INT*/
		}
		MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][1], 0); /*RX INT -->disable, get receive data is TX INT*/
		MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][2], 0); /*Error INT*/
					
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIGAttribute.VectList[u32CsigID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 0);	/*Receive Error INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT */
		
                 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                 {
		        MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1); /*TX INT*/
		}
#endif		

		MCU_stCSIGAttribute.CSIG[u32CsigID].TX0H.u16Value= pDataHead[0];/*send out data, base 16bit word*/
		
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}
#endif

#if (MCU_mCSIGMasterReadEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIG_MasterRead												 
 Description   :CSIG model receive data function
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			pDataHead: receive data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
uint16 MCU_u16CSIG_MasterRead(MCU_enCsigID u32CsigID,uint16 pDataHead[], uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr,u16Dummy;
	uint32 VectNum;

	if(MCU_stCsigRunStatus[u32CsigID].u16WorkingMode==MCU_mCSIG_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		/*parameter*/
		MCU_stCsigRunStatus[u32CsigID].pu16RecDataHead=pDataHead;
		MCU_stCsigRunStatus[u32CsigID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen=0;
		MCU_stCsigRunStatus[u32CsigID].u16WorkingMode=MCU_mCSIG_RxOnly;

		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL0.u8Value=0xA1;/*RX mode*/
		MCU_stCSIGAttribute.CSIG[u32CsigID].BCTL0.u8Value=0x01;
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
		MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][0], 0); /*TX INT*/
		
		 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                 {
		        MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][1], 1); /*RX INT */
                 }
                
		 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].ErrCB != MCU_vNotExpINT_u16)
                 {
		        MCU_u16InterruptCtrl(MCU_stCSIGAttribute.VectList[u32CsigID][2], 1); /*Rx Error INT*/
                 }
					
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIGAttribute.VectList[u32CsigID];
		if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].ErrCB != MCU_vNotExpINT_u16)
                 {
		        MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1);	/*Receive Error INT*/
		}
		
		 if(MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB != MCU_vNotExpINT)
                  {
		        MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 1); /*RX INT*/
		}
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 0); /*TX INT*/
#endif

		u16Dummy=MCU_stCSIGAttribute.CSIG[u32CsigID].RX0.u16Value;/*Read Dummy data, base 16bit word*/
		u16Dummy+=1;/*warning!!*/
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;


}
#endif

/*****************************************************************************
 Function  : MCU_vCSIG_Isr_WriteUnitFinish												 
 Description   :CSIG model send data ISR
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIG_Isr_WriteUnitFinish(MCU_enCsigID u32CsigID)
{
#if ((MCU_mCSIGMasterSynchRWEnable !=0u) ||(MCU_mCSIGMasterWriteEnable !=0))
	uint32 WorkLen;
	
	WorkLen=++MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen;

	/*store receive data*/
	if(MCU_stCsigRunStatus[u32CsigID].u16WorkingMode==MCU_mCSIG_TxRx)
	{
		MCU_stCsigRunStatus[u32CsigID].pu16RecDataHead[WorkLen-1]=\
			MCU_stCSIGAttribute.CSIG[u32CsigID].RX0.u16Value;
	}
	
	if(WorkLen>=MCU_stCsigRunStatus[u32CsigID].u16TottalDataLen)
	{
		/*send finish, call finish function*/
		MCU_stCsigRunStatus[u32CsigID].u16WorkingMode=MCU_mCSIG_Ready;
		MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].SendFinshCB();
	}
	else
	{
	
		/*send Not finish, Continue*/
		MCU_stCSIGAttribute.CSIG[u32CsigID].TX0H.u16Value= \
			MCU_stCsigRunStatus[u32CsigID].pu16SendDataHead[WorkLen];/*send out data, base 16bit word*/
	}
#endif
}

/*****************************************************************************
 Function  : MCU_vCSIG_Isr_ReadUnitFinish												 
 Description   :CSIG model receive data ISR
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIG_Isr_ReadUnitFinish(MCU_enCsigID u32CsigID)
{
#if (MCU_mCSIGMasterReadEnable !=0u)
	uint16 WorkLen;
	uint16 u16RecData;
	
	WorkLen=MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen;
	if(WorkLen>=MCU_stCsigRunStatus[u32CsigID].u16TottalDataLen-1)
	{
		/*send finish, call finish function*/
		MCU_stCSIGAttribute.CSIG[u32CsigID].BCTL0.u8Value= 0;/*if in TX/RX mode, clear it to 0 is OK!*/
		MCU_stCsigRunStatus[u32CsigID].u16WorkingMode=MCU_mCSIG_Ready;
		
		u16RecData=MCU_stCSIGAttribute.CSIG[u32CsigID].RX0.u16Value;
		MCU_stCsigRunStatus[u32CsigID].pu16RecDataHead[WorkLen]=u16RecData;
		
		MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].RecFinshCB();
	}
	else
	{
		/*Read Not finish, Continue*/
		u16RecData = 	MCU_stCSIGAttribute.CSIG[u32CsigID].RX0.u16Value;/*Read out data, base 16bit word*/
		MCU_stCsigRunStatus[u32CsigID].pu16RecDataHead[WorkLen]=u16RecData;
		MCU_stCsigRunStatus[u32CsigID].u16WorkingDataLen++;
	}
#endif
}


/*****************************************************************************
 Function  : MCU_vCSIG_Isr_Err												 
 Description   :CSIG model ERR ISR
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIG_Isr_Err(MCU_enCsigID u32CsigID)
{
	uint32 u32Err=(uint32)(MCU_stCSIGAttribute.CSIG[u32CsigID].STR0 & 0x8B);

	MCU_stCSIGAttribute.CSIG[u32CsigID].STCR0.u16Value |=0x8B;/*Error Clear*/
	
	MCU_stCSIGAttribute.CSIG_UsrCfg[u32CsigID].ErrCB((uint16)u32Err);
}

#if (MCU_mCSIGClkPhaseChgEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIG_ChgClkType												 
 Description   :CSIG model change the clock phase type
 
 In Parameter: 
 			u32CsigID: CSIG ID list in head file
 			ExpectType: expected clock type, the phase type please refer to the SPEC
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
uint16 MCU_u16CSIG_ChgClkType(MCU_enCsigID u32CsigID, MCU_enCsig_ClkType ExpectType)
{
	uint32 u32SetValue;
	uint16 u16RetVal=DET_Err_NotErr;
	
	if(MCU_stCsigRunStatus[u32CsigID].u16WorkingMode==MCU_mCSIG_Ready)
	{
		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL0.u8Value &=(uint8)(~0x80);/*Clear PWR bit*/
		
		u32SetValue = MCU_stCSIGAttribute.CSIG[u32CsigID].CTL1;
		if((ExpectType & 2 ) == 0)
		{
			u32SetValue &=~(1<<17);/*bit17: clock type*/
		}
		else
		{
			u32SetValue |=(1<<17);/*bit17: clock type*/
		}
		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL1=u32SetValue ;		

	
		u32SetValue = MCU_stCSIGAttribute.CSIG[u32CsigID].CFG0;
		if((ExpectType & 1 ) == 0)
		{
			u32SetValue &=~(1<<16);/*bit16: clock type*/
		}
		else
		{
			u32SetValue |=(1<<16);/*bit16: clock type*/
		}
		MCU_stCSIGAttribute.CSIG[u32CsigID].CFG0=u32SetValue ;	

		MCU_stCSIGAttribute.CSIG[u32CsigID].CTL0.u8Value |=0x80;/*Set PWR bit*/

	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}
#endif

#if (MCU_mCSIGdeinitEnable!=0u)
void MCU_vCSIGdeinit(void)
{


}

#endif

#endif/*end of CSIG module*/


#if (MCU_mCSIHModuleEnable!=0u)

MCU_tstCSHICtrl MCU_stCsihRunStatus[MCU_mCSIH_MaxChn];

/*****************************************************************************
 Function  : MCU_u16CSIHinit												 
 Description   :CSIH model de-initial
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function run before system mainloop
 			
*****************************************************************************/
static uint16 MCU_u16CSIHinit(void)
{
#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

	uint32 u32ClkSpeed=MCU_stClockStatus.ClkSpeed_C_ISO_CSIS;

#elif((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	uint32 u32ClkSpeed=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
#endif

	uint32 Cfg0,Ctl0,Ctl1,Ctl2,BPS,SlaveMode,ClkType,u32Loop;

	for(u32Loop=0;u32Loop<MCU_mCSIH_MaxChn;u32Loop++)
	{
		MCU_stCsihRunStatus[u32Loop].u16WorkingMode=MCU_mCSIH_Ready;
		
		BPS=MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].Bps;
		if( BPS!=0u)
		{
			SlaveMode=MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].SlaveMode;
			ClkType = MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].ClkType;
			
			Ctl0=0;

			Ctl1 =0<<24;/*internal synchronization timing for receive data input
						0 = Rising edge of PCLK
						1 = Falling edge of PCLK
						*/
			Ctl1|=(ClkType & 2 )<<16;/*bit17: clock type*/
			Ctl1|=0<<16;	/*interrupt type: 0 = interrupt after finish
									    1 = interrupt if TX0W/H is empty*/
			Ctl1|=0<<6; /*bit6: Job concept disable*/		
			Ctl1|=1<<2; /*bit2: Interrupt delay half clock for interrupt*/
						/*bit1: Enables/disables handshake mode.*/
			Ctl1|=MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].HankShakeEnable<<1;
						/*bit0: Enables/disables slave select function*/
			Ctl1|=SlaveMode<<0;
			
			Ctl2= (SlaveMode ? 0xF000 : 0x0000);/*in slave/Master mode*/
																/*bit31-30: BRS select: keerp default select = BRS0*/
			Cfg0 = MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].Parity<<28;/*bit28,29: parity setting*/
																/*bit24~27: DataLen, keep 16bit setting(0)*/
			Cfg0 |=MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].LSB_shift<<18;/*bit18: data direction setting, 1 = Lsb*/
			/*Cfg0 |=(MCU_stCSIHAttribute.CSIH_UsrCfg[u32Loop].UnitLenth & 1)<<24;bit24: data unit lenth*/
			Cfg0 |=(ClkType & 1)<<16;								/*bit16: clock type setting*/

			DI();
			/*Register value update*/
			MCU_stCSIHAttribute.CSIH[u32Loop].CTL0.u8Value=Ctl0;
			MCU_stCSIHAttribute.CSIH[u32Loop].CTL1=Ctl1;
			MCU_stCSIHAttribute.CSIH[u32Loop].CTL2.u16Value=Ctl2;
			MCU_stCSIHAttribute.CSIH[u32Loop].CFG[0]=Cfg0;/*Only used the CFG0 default*/
			MCU_stCSIHAttribute.CSIH[u32Loop].BRS[0].u16Value=(u32ClkSpeed/2/BPS)-1;
			
			EI();
			
		}
		
	}

	return DET_Err_NotErr;

}

#if (MCU_mCSIHMasterSynchRWEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIH_MasterSynchRW												 
 Description   :CSIH model send data and receive data function
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			pSendDataHead: send out data head pionter
 			pRecDataHead: receive data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			this function send out one data and receive one data at the same time
 			
*****************************************************************************/
uint16 MCU_u16CSIH_MasterSynchRW(MCU_enCsihID u32CsihID,uint16 pSendDataHead[], uint16 pRecDataHead[], uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_enIsrID VectNum;
	
	if(MCU_stCsihRunStatus[u32CsihID].u16WorkingMode==MCU_mCSIH_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		
		/*parameter*/
		MCU_stCsihRunStatus[u32CsihID].pu16SendDataHead=pSendDataHead;
		MCU_stCsihRunStatus[u32CsihID].pu16RecDataHead=pRecDataHead;		
		MCU_stCsihRunStatus[u32CsihID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen=0;
		MCU_stCsihRunStatus[u32CsihID].u16WorkingMode=MCU_mCSIH_TxRx;
		
		MCU_stCSIHAttribute.CSIH[u32CsihID].CTL0.u8Value=0xE1;/*TX/RX mode*/
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT -->disable, get receive data is TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1);	/*Error INT*/
			
			
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT -->disable, get receive data is TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1);	/*Error INT*/
		
#endif
		
		MCU_stCSIHAttribute.CSIH[u32CsihID].TX0H.u16Value= pSendDataHead[0];/*send out data, base 16bit word*/
		
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}
#endif


#if (MCU_mCSIHMasterWriteEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIH_MasterWrite												 
 Description   :CSIH model send data function
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			pDataHead: send out data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
uint16 MCU_u16CSIH_MasterWrite(MCU_enCsihID u32CsihID,uint16 pDataHead[],  uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_enIsrID VectNum;

	if(MCU_stCsihRunStatus[u32CsihID].u16WorkingMode==MCU_mCSIH_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		
		/*parameter*/
		MCU_stCsihRunStatus[u32CsihID].pu16SendDataHead=pDataHead;
		MCU_stCsihRunStatus[u32CsihID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen=0;
		MCU_stCsihRunStatus[u32CsihID].u16WorkingMode=MCU_mCSIH_TxOnly;

		MCU_stCSIHAttribute.CSIH[u32CsihID].CTL0.u8Value=0xC1;/*TX mode*/
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT */
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 0); /*Error INT*/
					
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 0); /*RX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 0);	/*Error INT*/
#endif		

		MCU_stCSIHAttribute.CSIH[u32CsihID].TX0H.u16Value= pDataHead[0];/*send out data, base 16bit word*/
		
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;
	
}
#endif		


#if (MCU_mCSIHMasterReadEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16CSIH_MasterRead												 
 Description   :CSIH model receive data function
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			pDataHead: receive data head pionter
 			u16Lenth_Byte: send/receive data lenth
 			
Return Value:
 			function execute resault
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
uint16 MCU_u16CSIH_MasterRead(MCU_enCsihID u32CsihID,uint16 pDataHead[], uint16 u16Lenth_Byte)
{
	uint16 u16RetVal=DET_Err_NotErr,u16Dummy;
	MCU_enIsrID VectNum;

	if(MCU_stCsihRunStatus[u32CsihID].u16WorkingMode==MCU_mCSIH_Ready)
	{
		DET_ErrCheck((u16Lenth_Byte & 1) ==0, DET_Err_SerialLenInvalib);
		/*parameter*/
		MCU_stCsihRunStatus[u32CsihID].pu16RecDataHead=pDataHead;
		MCU_stCsihRunStatus[u32CsihID].u16TottalDataLen=u16Lenth_Byte/2;/*YES, base 16bit Word*/
		MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen=0;
		MCU_stCsihRunStatus[u32CsihID].u16WorkingMode=MCU_mCSIH_RxOnly;

		MCU_stCSIHAttribute.CSIH[u32CsihID].CTL0.u8Value=0xA1;/*RX mode*/
		
#if ((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))
		
		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 0); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 1); /*RX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 1);	/*Error INT*/
					
#elif ((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		
		VectNum = MCU_stCSIHAttribute.VectList[u32CsihID];
		
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+2), 0); /*TX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+1), 1); /*RX INT*/
		MCU_u16InterruptCtrl((MCU_enIsrID)(VectNum+0), 1);	/*Error INT*/
#endif

		u16Dummy=MCU_stCSIHAttribute.CSIH[u32CsihID].RX0H.u16Value;/*Read Dummy data, base 16bit word*/
		u16Dummy+=1;/*warning!!*/
	}
	else
	{
		DET_ErrReport(DET_Err_SerialIsBusy);
	}

	return u16RetVal;


}
#endif

/*****************************************************************************
 Function  : MCU_u16CSIH_Isr_SendFinish												 
 Description   :CSIH model send data ISR
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIH_Isr_WriteUnitFinish(MCU_enCsihID u32CsihID)
{
#if ((MCU_mCSIHMasterSynchRWEnable !=0u) ||(MCU_mCSIHMasterWriteEnable !=0u))
	uint32 WorkLen;
	
	WorkLen=++MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen;

	/*store receive data*/
	if(MCU_stCsihRunStatus[u32CsihID].u16WorkingMode==MCU_mCSIH_TxRx)
	{
		MCU_stCsihRunStatus[u32CsihID].pu16RecDataHead[WorkLen-1]=\
			MCU_stCSIHAttribute.CSIH[u32CsihID].RX0H.u16Value;
	}
	
	if(WorkLen>=MCU_stCsihRunStatus[u32CsihID].u16TottalDataLen)
	{
		/*send finish, call finish function*/
		MCU_stCsihRunStatus[u32CsihID].u16WorkingMode=MCU_mCSIH_Ready;
		MCU_stCSIHAttribute.CSIH_UsrCfg[u32CsihID].SendFinshCB();
	}
	else
	{
	
		/*send Not finish, Continue*/
		MCU_stCSIHAttribute.CSIH[u32CsihID].TX0H.u16Value= \
			MCU_stCsihRunStatus[u32CsihID].pu16SendDataHead[WorkLen];/*send out data, base 16bit word*/
	}
#endif
}


/*****************************************************************************
 Function  : MCU_vCSIH_Isr_ReadUnitFinsh												 
 Description   :CSIH model receive data ISR
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIH_Isr_ReadUnitFinsh(MCU_enCsihID u32CsihID)
{
#if (MCU_mCSIHMasterReadEnable !=0u)
	uint16 WorkLen;
	uint16 u16RecData;
	
	WorkLen=MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen;
	if(WorkLen>=MCU_stCsihRunStatus[u32CsihID].u16TottalDataLen-1)
	{
		/*send finish, call finish function*/
		MCU_stCSIHAttribute.CSIH[u32CsihID].CTL0.u8Value= 0;
		MCU_stCsihRunStatus[u32CsihID].u16WorkingMode=MCU_mCSIH_Ready;
		
		u16RecData=MCU_stCSIHAttribute.CSIH[u32CsihID].RX0H.u16Value;
		MCU_stCsihRunStatus[u32CsihID].pu16RecDataHead[WorkLen]=u16RecData;
		
		MCU_stCSIHAttribute.CSIH_UsrCfg[u32CsihID].RecFinshCB();
	}
	else
	{
		/*Read Not finish, Continue*/
		u16RecData =	MCU_stCSIHAttribute.CSIH[u32CsihID].RX0H.u16Value;/*Read out data, base 16bit word*/
		MCU_stCsihRunStatus[u32CsihID].pu16RecDataHead[WorkLen]=u16RecData;
		MCU_stCsihRunStatus[u32CsihID].u16WorkingDataLen++;
	}
#endif
}


/*****************************************************************************
 Function  : MCU_vCSIH_Isr_Err												 
 Description   :CSIH model ERR ISR
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIH_Isr_Err(MCU_enCsihID u32CsihID)
{
	uint32 u32Err=(uint32)(MCU_stCSIHAttribute.CSIH[u32CsihID].STR0 & 0xC10B);

	MCU_stCSIHAttribute.CSIH[u32CsihID].STCR0.u16Value=0xC10B;/*Error Clear*/
	
	MCU_stCSIHAttribute.CSIH_UsrCfg[u32CsihID].ErrCB((uint16)u32Err);
}


/*****************************************************************************
 Function  : MCU_vCSIH_Isr_JobFinish												 
 Description   :CSIH model Job finish ISR
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIH_Isr_JobFinish(MCU_enCsihID u32CsihID)
{
	/*dummy function*/
#if (MCU_mCSIHJobEnable !=0u)

#endif

}

#if (MCU_mCSIHJobEnable !=0u)
/*****************************************************************************
 Function  : MCU_vCSIHJobLastData												 
 Description   :CSIH model Job index before the last data send out, 
 			it will cause a job-finish interrupt once the last data send finish 
 
 In Parameter: 
 			u32CsihID: CSIH ID list in head file
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
void MCU_vCSIHJobLastData(MCU_enCsihID u32CsihID)
{
	/*dummy function*/


}

#endif

#if (MCU_mCSIHdeinitEnable!=0u)
void MCU_vCSIHdeinit(void)
{


}
#endif

#endif/*end of CSIH module*/


#if((MCU_UsingType > MCU_ID_RH850_F1L_Start)  && (MCU_UsingType<MCU_ID_RH850_F1L_End))

/*****************************************************************************
 Function  : MCU_vClockInit_Basic												 
 Description   : CPU clock init, base part:
 			PLL, MainOsc, SubOsc,high speed interrnal Osc, Low speed interrnal Osc
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_Basic(void)
{
	uint32 u32MOSC=3,Mr=1,Pr,Nr,OscSpeed,Speed,PLLCvalue;
	uint16 u16RetVal=DET_Err_NotErr;
	
	/******************************************
			MainOsc setting and start it!
	*********************************************/
	OscSpeed = MCU_stClockAttribute.ClockUsrCfgHead->CPLLCLK_Speed;
	
	if( OscSpeed <=PLL_MainOsc_8M_30M)
	{
		u32MOSC =3;
	}
	else 	if( OscSpeed <=PLL_MainOsc_16M_30M)
	{
		u32MOSC =2;
	}
	else
	{
		DET_ErrReport(DET_Err_MianOscSpeedOutOfRange);
	}

	/*Record running clock speed !!*/
	MCU_stClockStatus.MainOsc_Speed=MCU_stPLL_CtrlValue[OscSpeed].MainOsc_Fre;
	MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Control |= u32MOSC;
	MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.StableTime = MCU_stClockAttribute.ClockUsrCfgHead->MainOsc_StableTime *8;/*stable coounter is FHR*/

	Debug_SetPin_Clock(11,2,1);
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = 1;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = ~1;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = 1;
	}
	while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
	
	while((MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Status & 4) ==0);
	Debug_SetPin_Clock(11,2,0);


	/*main osc not stop in standby mode ===> always run MainOsc in default
	if(MCU_stClockAttribute.ClockUsrCfgHead->MainOscStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.StopMask |= 1;
	}*/
	
	/******************************************
			SubOsc setting and start it!
	*********************************************/
	MCU_stClockStatus.SubOsc_Speed=0;
	if(MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_FTX_Speed == 32768)
	{
	
		MCU_stClockStatus.SubOsc_Speed=32768;
		/*MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Control |= u32MOSC*/
		
		if(MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_StableTime != MCU_CLK_UsingDefault)
		{
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.StableTime = 
				MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_StableTime * 8;/*stable coounter is FHR*/
		}
		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = 1;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = ~1;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = 1;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Status & 4) ==0);
		
		
		/*sub osc not stop in standby mode
		if(MCU_stClockAttribute.ClockUsrCfgHead->SubOscStopInStandbyMode ==0)
		{
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.StopMask |= 1;
		}*/
		
	}
	

	/******************************************
			PLL setting and start it!
	*********************************************/
	MCU_stClockStatus.CPLLCLK_Speed=MCU_stPLL_CtrlValue[OscSpeed].PLL_Fre;
	MCU_stClockStatus.PPLLCLK_Speed=MCU_stClockStatus.CPLLCLK_Speed;
	
	Speed = MCU_stClockAttribute.ClockUsrCfgHead->CPLLCLK_Speed;

	Nr=MCU_stPLL_CtrlValue[Speed].Nr-1;
	Mr = MCU_stPLL_CtrlValue[Speed].Mr-1;
	Pr=MCU_stPLL_CtrlValue[Speed].Pr;

	PLLCvalue = ((Mr <<11) | (Pr<<8) | Nr);

	MCU_stClockAttribute.PLL0->PLLCtrl= PLLCvalue;
	
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
		MCU_stClockAttribute.PLL0->PLLEnable= 1;
		MCU_stClockAttribute.PLL0->PLLEnable = ~1;
		MCU_stClockAttribute.PLL0->PLLEnable = 1;
	}
	while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
	
	while((MCU_stClockAttribute.PLL0->PLLStatus & 4) ==0);
	
	/*PLL0 output
	MCU_stClockAttribute.PLLCtrl[0].SSTP=1;
	while(MCU_stClockAttribute.PLLCtrl[0].SACT==0);*/


	/******************************************
			CPU clock source select and devide setting!
	*********************************************/
	
	/*PLL to CPU clock, default not Divide
		write protect register	

		MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_CPUCLKD.SourceSel= 1; -->Div=1
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_CPUCLKD.SourceSel = ~1;
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_CPUCLKD.SourceSel = 1;
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_CPUCLKD.Active & 1) ==0);
	*/
	
	/*PLL to CPU clock, default select PLL ===>now CPU is run in PLL speed!!!*/
	do
	{
		MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_CPUCLKS.SourceSel = 3;/*3 = PLL*/
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_CPUCLKS.SourceSel = ~3;
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_CPUCLKS.SourceSel = 3;
	}
	while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
	
	while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_CPUCLKS.Active & 3) !=3);
	
	/*--->now CPU is run in PLL speed!!!*/
	MCU_stClockStatus.CPUCLK_Speed=MCU_stClockStatus.CPLLCLK_Speed;

	/******************************************
			Keep FRH/FRL runing!!!-->default
	*********************************************/

}


/*****************************************************************************
 Function  : MCU_vClockInit_AWO												 
 Description   : CPU clock init, AWO part:
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_AWO(void)
{
	uint32 SetValue;
	
	/*Now, its peripheral clock proccess time!!*/
	
	/********************************
			C_AWO_WDTA
	************************************/
	
	MCU_stClockStatus.ClkSpeed_C_AWO_WDTAD=MCU_stClockStatus.IntOscLS_FRL_Speed/128;
	
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_WDTAD ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_C_AWO_WDTAD=MCU_stClockStatus.IntOscLS_FRL_Speed;
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTAD.Divider = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTAD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTAD.Divider = SetValue;
		}while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTAD.Active /*& SetValue*/) !=SetValue);

		
	}

			
	/*watch dog not stop in standby mode ==>always stop it by default value
	if(MCU_stClockAttribute.ClockUsrCfgHead->WDTAStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTAD.StopMask |= 1;
	}*/

	/********************************
			C_AWO_TAUJ
	************************************/
	MCU_stClockStatus.ClkSpeed_C_AWO_TAUJS=MCU_stClockStatus.IntOscHS_FRH_Speed;

	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_AWO_TAUJS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[5]={0,
						MCU_stClockStatus.IntOscHS_FRH_Speed,
						MCU_stClockStatus.MainOsc_Speed, 
						MCU_stClockStatus.IntOscLS_FRL_Speed,
						MCU_stClockStatus.PPLLCLK_Speed/2};
						
		MCU_stClockStatus.ClkSpeed_C_AWO_TAUJS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJS.Active /*& SetValue*/) !=SetValue);

	}
	
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_TAUJD ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_C_AWO_TAUJS >>=(SetValue-1);
		
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJD.Divider = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJD.Active /*& SetValue*/) !=SetValue);
	}	

	/*TAUJ not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->TAUJStopInStandbyMode == 0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ATAUJD.StopMask |= 1;
	}
	
	/********************************
			C_AWO_RTCA
	************************************/
	MCU_stClockStatus.ClkSpeed_C_AWO_RTCAS=0;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_AWO_RTCAS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.SubOsc_Speed,
						MCU_stClockStatus.MainOsc_Speed, 
						MCU_stClockStatus.IntOscLS_FRL_Speed};
		MCU_stClockStatus.ClkSpeed_C_AWO_RTCAS = ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.Active /*& SetValue*/) !=SetValue);
	}
	
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_RTCAD ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_C_AWO_RTCAS>>=(SetValue-1);
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Active /*& SetValue*/) !=SetValue);
	}	

	/*RTCA not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->RTCAStopInStandbyMode == 0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.StopMask |= 1;
	}

	
	/********************************
			C_AWO_ADCA
	************************************/
	MCU_stClockStatus.ClkSpeed_C_AWO_ADCAS=MCU_stClockStatus.IntOscHS_FRH_Speed;
	
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_AWO_ADCAS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.IntOscHS_FRH_Speed,
						MCU_stClockStatus.MainOsc_Speed, 
						MCU_stClockStatus.PPLLCLK_Speed/2};
		MCU_stClockStatus.ClkSpeed_C_AWO_ADCAS= ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAS.Active /*& SetValue*/) !=SetValue);
	}
	
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_ADCAD ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_C_AWO_ADCAS>>=(SetValue-1);
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAD.Divider = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAD.Active /*& SetValue*/) !=SetValue);
	}	

	/*ADCA not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->ADCAStopInStandbyMode == 0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AADCAD.StopMask |= 1;
	}


	/********************************
			C_AWO_FOUT
	************************************/
	MCU_stClockStatus.ClkSpeed_C_AWO_FOUT=0;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_AWO_FOUT;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[7]={0,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.IntOscHS_FRH_Speed, 
						MCU_stClockStatus.IntOscLS_FRL_Speed,
						MCU_stClockStatus.SubOsc_Speed,
						MCU_stClockStatus.CPLLCLK_Speed/2,
						MCU_stClockStatus.PPLLCLK_Speed/4};
						
		MCU_stClockStatus.ClkSpeed_C_AWO_FOUT=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.Active /*& SetValue*/) !=SetValue);

		SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_FOUT ;
		if(SetValue !=MCU_CLK_UsingDefault)
		{
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTD.Divider = SetValue;
		}	

		/*FOUT stop in standby mode -->Clock supplied by CPUCLK2*/
	}
	
}


/*****************************************************************************
 Function  : MCU_vClockInit_ISO												 
 Description   : CPU clock init, ISO part:
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_ISO(void)
{
	uint32 SetValue;

	/*CKSC_CPUCLKS and CKSC_CPUCLKD
	---> has done in basic clock init<-----*/


	/********************************
			C_ISO_PER1
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_PER1=MCU_stClockStatus.CPUCLK_Speed/2;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_PER1;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,
						MCU_stClockStatus.CPUCLK_Speed/2,
						MCU_stClockStatus.PPLLCLK_Speed};
						
		MCU_stClockStatus.ClkSpeed_C_ISO_PER1=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI1.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI1.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI1.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI1.Active /*& SetValue*/) !=SetValue);

	}

	/********************************
			C_ISO_PER2
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_PER2=MCU_stClockStatus.CPUCLK_Speed/2;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_PER2;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,
						MCU_stClockStatus.CPUCLK_Speed/2,
						MCU_stClockStatus.PPLLCLK_Speed};
		MCU_stClockStatus.ClkSpeed_C_ISO_PER2=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI2.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI2.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI2.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IPERI2.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ILINS
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_LINS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_LINS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.CPUCLK_Speed/2,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.PPLLCLK_Speed/2};
		MCU_stClockStatus.ClkSpeed_C_ISO_LINS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILINS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILINS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILINS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILINS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ILIND
	************************************/
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_ISO_ILIND;
	if((SetValue !=MCU_CLK_UsingDefault) && (SetValue !=1))
	{
		MCU_stClockStatus.ClkSpeed_C_ISO_LINS>>=(SetValue);
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILIND.Divider = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILIND.Divider = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILIND.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILIND.Active /*& SetValue*/) !=SetValue);

	}
	/*clock not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->LINStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ILIND.StopMask |=1;
	}	
	
	
	/********************************
			C_ISO_ADCA
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_ADCAS=MCU_stClockStatus.IntOscHS_FRH_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_ADCAS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.IntOscHS_FRH_Speed,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.PPLLCLK_Speed/2};
		MCU_stClockStatus.ClkSpeed_C_ISO_ADCAS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAS.Active /*& SetValue*/) !=SetValue);
	}
	
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_AWO_ADCAD;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_C_ISO_ADCAS>>=(SetValue-1);
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAD.Divider = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAD.Divider = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAD.Active /*& SetValue*/) !=SetValue);

	}
	/*clock not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->ADCAStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_IADCAD.StopMask |=1;
	}	


	
	/********************************
			C_ISO_CAN
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_CANS=MCU_stClockStatus.CPUCLK_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_CANS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.CPLLCLK_Speed,
						MCU_stClockStatus.CPUCLK_Speed};
		MCU_stClockStatus.ClkSpeed_C_ISO_CANS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANS.Active /*& SetValue*/) !=SetValue);
	}	
	
	/*clock not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->CANStopInStandbyMode ==0)
	{	
		/*CANS_STPM contorl in selector reigster!!!*/
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANS.StopMask |=1;
	}	

	
	/********************************
			C_ISO_CANOSC
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_CANS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_C_ISO_CANOSCD;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.MainOsc_Speed/2};
		MCU_stClockStatus.ClkSpeed_C_ISO_CANS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANOSCD.Divider = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANOSCD.Divider = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANOSCD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANOSCD.Active /*& SetValue*/) !=SetValue);
	}	
	
	/*clock not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->CANOSCStopInStandbyMode ==0)
	{	
		MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICANOSCD.StopMask |=1;
	}	

	
	/********************************
			C_ISO_CSI
	************************************/
	MCU_stClockStatus.ClkSpeed_C_ISO_CSIS=MCU_stClockStatus.CPLLCLK_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_C_ISO_CSIS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,
						MCU_stClockStatus.CPUCLK_Speed,
						MCU_stClockStatus.CPLLCLK_Speed};
		MCU_stClockStatus.ClkSpeed_C_ISO_CSIS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICSIS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICSIS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICSIS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICSIS.Active /*& SetValue*/) !=SetValue);
	}	

	
}

#if (MCU_mClockMonitorEnable !=0u)
/*****************************************************************************
 Function  : MCU_vClockInit_ClockMonitor												 
 Description   : CPU clock monitor,-->not finish, it will reset once call this function!!
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_ClockMonitor(void)
{
	uint32 SetValue,TolerancePercent,MainOscValue =MEGA(8);
	uint32 Hvalue,Lvalue,PLLClk,PLLClkindex;
	uint16 u16RetVal=DET_Err_NotErr;


	/*******************************************
	CLMA0:
	internal high speed OSC monitor setting:
	
	sample clock = interrnal low speed OSC = 240 kHz
	Monitor HS = 8M
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA0enable_HS;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA0TolerancePercent;
		Hvalue =( MCU_stClockStatus.IntOscHS_FRH_Speed* (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Hvalue*=16;
		Hvalue+=1;
		
		Lvalue =( MCU_stClockStatus.IntOscHS_FRH_Speed * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Lvalue*=16;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);
		DET_ErrCheck(Hvalue < 0xFFF, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.CompareH.u16Value= Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.CompareL.u16Value=Lvalue;

		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.Control.u8Value= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.Control.u8Value= 0xFE;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.Control.u8Value= 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA0_HS.Control.u8Value!=1ul);
		
	}

	/*******************************************
	CLMA1:
	Main OSC monitor setting:
	
	sample clock = interrnal low speed OSC = 240 kHz
	Monitor  = MainOSC
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA1enable_MainOsc;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		PLLClkindex = MCU_stClockAttribute.ClockUsrCfgHead->CPLLCLK_Speed;
		MainOscValue=MCU_stPLL_CtrlValue[PLLClkindex].MainOsc_Fre;
	
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA1TolerancePercent;
		Hvalue =( MainOscValue * (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Hvalue*=16;
		Hvalue+=1;
		
		Lvalue =( MainOscValue * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Lvalue*=16;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.CompareH.u16Value= Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.CompareL.u16Value=Lvalue;

		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.Control.u8Value= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.Control.u8Value= ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.Control.u8Value= 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA1_MainOsc.ProtectUnit.Status !=0ul);
		
	}

	
	/*******************************************
	CLMA2:
	CPLLCLK monitor setting:
	
	sample clock = interrnal High speed OSC = 8 MHz
	Monitor  = CPLLCLK
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA2enable_CPLLCLK;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		PLLClkindex = MCU_stClockAttribute.ClockUsrCfgHead->CPLLCLK_Speed;
		PLLClk=MCU_stPLL_CtrlValue[PLLClkindex].PLL_Fre;

		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA2TolerancePercent;

		Hvalue =( PLLClk * (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscHS_FRH_Speed * 100) ;
		Hvalue*=16;
		Hvalue+=1;
		
		Lvalue =( PLLClk * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscHS_FRH_Speed * 100) ;
		Lvalue*=16;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.CompareH.u16Value= Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.CompareL.u16Value=Lvalue;

		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.Control.u8Value= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.Control.u8Value= ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.Control.u8Value= 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA2_CPLLCLK.ProtectUnit.Status !=0ul);
		
	}
	
}
#endif

/*****************************************************************************
 Function  : MCU_vLowVoltDetectInit												 
 Description   :Low voltage detect setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it will while(1){MCU Reset} after call this function if the 5V supply is below the lowest voltage


*****************************************************************************/
static void MCU_vLowVoltDetectInit(void)
{
#if (MCU_mLVI_Level !=0u)

	uint32 u32SetValue;
	uint32 u32waitTime = 2* 8000 /2;/*mini = 2ms in HS clock*/
	
	/*mask the interrupt or reset function first*/
	do
	{
		MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Commond = 0xA5;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =4;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =~4;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =4;
	}
	while(MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Status !=0ul);
	
	/*user setting voltage*/
	u32SetValue = MCU_mLVI_Level;
	u32SetValue |=4;

	/*update datect voltage*/
	do
	{
		MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Commond = 0xA5;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =u32SetValue;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =~u32SetValue;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =u32SetValue;
	}
	while(MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Status !=0ul);

	/*wait time: 2ms in HS (8M)*/
	while(u32waitTime !=0ul)
	{
		u32waitTime --;
	}

	/*enable datect voltage*/
	u32SetValue = MCU_mLVI_Level;
	do
	{
		MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Commond = 0xA5;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =u32SetValue;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =~u32SetValue;
		*MCU_tsVoltageMonitorAttribute.LVICNT_Addr =u32SetValue;
	}
	while(MCU_tsVoltageMonitorAttribute.LVICNT_ProtectAddr->Status !=0ul);
	
#endif

}

 
 /*****************************************************************************
  Function	: MCU_vStandbyCtrl_IoHold											  
  Description	:Low voltage detect setting initialization
  
  In Parameter: 
			 PortIDmaskBit : always set it to 0 in F1L
			 
 Return Value:
			 NULL
			 
  NOTE: 	 
			 call this function when reset from deep-stop mode
 
 *****************************************************************************/
 static void MCU_vStandbyCtrl_IoHold(uint32 PortIDmaskBit)
 {
	 if(PortIDmaskBit == 0)
	 {
		 DI();
		 do
		 {
			 MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
			 MCU_stSTBCAttribute.STBC->IoHold=0;/*it will auto set to 1 only by entry deepstop mode!!!*/
			 MCU_stSTBCAttribute.STBC->IoHold=~0;
			 MCU_stSTBCAttribute.STBC->IoHold=0;
		 }
		 /*wait IO released!!*/
		 while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);
		 
		 EI();
	 }
 }

 
#if (MCU_mCPUModeCtrlEnable !=0u)
 /*****************************************************************************
  Function	: MCU_vStandbyCtrl_ChgToMode											  
  Description	:MCU running mode control, to enter normal-mode, standby-mode, halt-mode ect
  
  In Parameter: 
			 u8ExpMode :MCU expected running mode 
 
						 0: Halt mode =>
						 
							 the CPU operation clock						 --->stopped. 
							 
							  the highspeed system clock oscillator,			 --->running
							  internal high-speed oscillator,				 --->running
							  internal low-speed oscillator  clock continues.	 --->running
														 
						 1: Stop mode =>
						 
							 the CPU operation clock					  --->stopped. 
 
							  the highspeed system clock oscillator 		 --->stopped. 
							  internal high-speed oscillator				 --->stopped. 
							  internal low-speed oscillator  clock continues --->stopped. 
							  
 Return Value:
 
			 NULL
			 
  NOTE: 	 
  
			 CPU will not excute next commond until wake up once it sleep successful!
		 
 *****************************************************************************/
 void MCU_vStandbyCtrl_ChgToMode(MCU_enRunModeID u8ExpMode)
 {
	 uint16 u16RetVal=DET_Err_NotErr;

	 if(u8ExpMode == MCU_mHaltMode)
	 {
		 EI_Force();
		 HALT();
		 /*it will wakeup to run mode by any interrupt happen!!!*/
 
		 /*need check what to do ~~~~~~~~~~~~~*/
	 }
	 else if(u8ExpMode == MCU_mDeepStopMode)
	 {
		 
		 EI_Force();	 
		 do
		 {
			 /*go to deep standby mode!!!*/
			 MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
			 MCU_stSTBCAttribute.STBC->PSC=2;
			 MCU_stSTBCAttribute.STBC->PSC=~2;
			 MCU_stSTBCAttribute.STBC->PSC=2;
		 }
		 /*wait IO released!!*/
		 while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);
		 
		 MCU_stSTBCAttribute.STBC->WUFC_0 = 0xFFFFFFFF;/*clean wakeup factor for new wakeup again !!*/
		 MCU_stSTBCAttribute.STBC->WUFC_20 = 0xFFFFFFFF;
		 MCU_stSTBCAttribute.STBC->WUFC_Iso0 = 0xFFFFFFFF;
		 
		 /*wait MCU reset Or wakeup to retain-RAM here!!!*/
		 /**while(1);*--->not use while(1), it will retry if it happen wakeup signal*/
		 
	 }
	 else if(u8ExpMode == MCU_mStopMode )
	 {
		 
		 if(MCU_stSTBCAttribute.STBC->PSC==2)
		 {
			 /*this mode entry only in run mode~~~~*/
			 DET_ErrReport(DET_Err_RunModeCtrlOutOfRange);
		 }
		 else
		 {
			 EI_Force();	 
			 do
			 {
				 /*go to deep standby mode!!!*/
				 MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
				 MCU_stSTBCAttribute.STBC->STPT=1;
				 MCU_stSTBCAttribute.STBC->STPT=~1;
				 MCU_stSTBCAttribute.STBC->STPT=1;
			 }
			 /*wait IO released!!*/
			 while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);

			 MCU_stSTBCAttribute.STBC->WUFC_0 = 0xFFFFFFFF;/*clean wakeup factor for new wakeup again !!*/
			 MCU_stSTBCAttribute.STBC->WUFC_20 = 0xFFFFFFFF;
			 MCU_stSTBCAttribute.STBC->WUFC_Iso0 = 0xFFFFFFFF;

			 /*wait stop mode release!!!!*/
			 /**while(MCU_stSTBCAttribute.STBC->STPT==1);--->not use while(1), it will retry if it happen wakeup signal**/
			 /*it will wakeup to run mode only by factor1 !!!*/
			 
			 
		 }
		 
	 
	 }
	 else if(u8ExpMode ==MCU_mCyclicStopMode)
	 {
 
		 if(MCU_stSTBCAttribute.STBC->PSC==2)
		 {
			 
			 EI_Force();	 
			 do
			 {
				 /*go to deep standby mode!!!*/
				 MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
				 MCU_stSTBCAttribute.STBC->STPT=1;
				 MCU_stSTBCAttribute.STBC->STPT=~1;
				 MCU_stSTBCAttribute.STBC->STPT=1;
			 }
			 while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);
			 
			 MCU_stSTBCAttribute.STBC->WUFC_0 = 0xFFFFFFFF;/*clean wakeup factor for new wakeup again !!*/
			 MCU_stSTBCAttribute.STBC->WUFC_20 = 0xFFFFFFFF;
			 MCU_stSTBCAttribute.STBC->WUFC_Iso0 = 0xFFFFFFFF;
			 /*wait MCU reset Or wakeup to retain-RAM here!!!*/
			 /**while(1);*--->not use while(1), it will retry if it happen wakeup signal*/
		 }
		 else
		 {
			 /*this mode entry only in deelstop mode~~~~*/
			 DET_ErrReport(DET_Err_RunModeCtrlOutOfRange);
		 }
		 
	 }
	 else if(u8ExpMode == MCU_mCyclicRunMode)
	 {
		 DET_ErrReport(DET_Err_RunModeCtrlOutOfRange);
		 
		 /*MCU_mCyclicRunMode:
		 
			 entry when wakeup by factor2 in deepstop mode!!!
			 it will run pragma in retain-RAM, address is 0xFEE00000~~~~~*/
 
		 /*MCU_mCyclicStopMode:
		 
			 only entry when go to stop in MCU_mCyclicRunMode !!
			 it will entry MCU_mCyclicRunMode if wakeup by factor1 or factor2!!!
			 (run to 0xFEE00000 after wakeup!!)*/
	 }
	 else
	 {
		 DET_ErrReport(DET_Err_RunModeCtrlOutOfRange);
	 }
	 
 }

 
 /*****************************************************************************
  Function	: MCU_vStandbyCtrl_SetWakeUpFactor											  
  Description	:Wake Up Factor setting initialization
  
  In Parameter: 
			 NULL
			 
 Return Value:
			 NULL
			 
  NOTE: 	 
			 call this function before system mainloop
 
 *****************************************************************************/
static void MCU_vStandbyCtrl_SetWakeUpFactor(void)
 {
	 DI();
	 
	 MCU_stSTBCAttribute.STBC->WUFMSK_0  =~*(uint32 *)&MCU_stSTBCAttribute.STBC_UsrCfg->WakeUpEnable_WU1;	 
	 MCU_stSTBCAttribute.STBC->WUFMSK_Iso0 =~*(uint32 *)&MCU_stSTBCAttribute.STBC_UsrCfg->WakeUpEnable_ISO0; 
	 
	 MCU_stSTBCAttribute.STBC->WUFMSK_20 =~*(uint32 *)&MCU_stSTBCAttribute.STBC_UsrCfg->WakeUpEnable_WU20;	 
	 
	 EI();
 }
 
 /*****************************************************************************
  Function	: MCU_vStandbyCtrl_CleanAllWakeUpFactor											  
  Description	:clean the Wake Up Factor before change mode to stop,
  
  In Parameter: 
			 NULL
			 
 Return Value:
			 NULL
			 
  NOTE: 	 
			 call this function before system mainloop
 
 *****************************************************************************/
 void MCU_vStandbyCtrl_CleanAllWakeUpFactor(void)
 {
	 DI();
	 
	 MCU_stSTBCAttribute.STBC->WUFC_0 = 0xFFFFFFFF;/*clean wakeup factor*/
	 MCU_stSTBCAttribute.STBC->WUFC_20 = 0xFFFFFFFF;
	 MCU_stSTBCAttribute.STBC->WUFC_Iso0 = 0xFFFFFFFF;
	 
	 EI();
 }

#if (MCU_mGetWakeUpFactorEnable !=0u) 
 /*****************************************************************************
  Function	: MCU_u32GetWakeUpFactor											  
  Description	:get Wake Up Factor 
  
  In Parameter: 
			 NULL
			 
 Return Value:
			 Wake Up Factor  ID
			 
  NOTE: 	 
			 NULL
 
 *****************************************************************************/
 MCU_enWakeFactorID MCU_u32GetWakeUpFactor(void)
 {
 
	 uint32 u32WakeupFactor[3],u32Loop,u32Mask,u32FinalID=0,u32LoopSubIndx;
	 uint32 u32FactorTbl[3]={32,9,16};
	 
	 u32WakeupFactor[0]=MCU_stSTBCAttribute.STBC->WUFC_0;					 /*factor 1*/
	 u32WakeupFactor[1]=MCU_stSTBCAttribute.STBC->WUFC_Iso0 &(((1ul<<9)-1)-1);/*factor 1*/
 
	 u32WakeupFactor[2]=MCU_stSTBCAttribute.STBC->WUFC_20 & ((1ul<<16)-1);		 /*factor 2*/
 
	 for(u32Loop=0;u32Loop<3;u32Loop++)
	 {
		 if(u32WakeupFactor[u32Loop]!=0)
		 {
			 u32Mask=1;
			 for(u32LoopSubIndx=0;u32LoopSubIndx<u32FactorTbl[u32Loop];u32LoopSubIndx++)
			 {
				 if((u32Mask & u32WakeupFactor[u32Loop]) !=0)
				 {
					 u32FinalID+=u32LoopSubIndx;
					 break;
				 }
				 else
				 {
					 u32Mask<<=1;
				 }
			 }
			 
		 }
		 else
		 {
			 u32FinalID +=u32FactorTbl[u32Loop];
		 }
		 
	 }
	 
	 return (MCU_enWakeFactorID)u32FinalID;
	 
 }
#endif
 
#endif

 /*****************************************************************************
 Function  : MCU_vResetCtrl_Reset 										  
 Description   :MCU software reset request, it will reset MCU and re-run from file starup.850
 
 In Parameter: 
		 NULL
		 
 Return Value:
		 NULL
		 
 NOTE:		 
		 NULL
 *****************************************************************************/
 void MCU_vResetCtrl_Reset(void)
 {
	 do
	 {
		 MCU_stResetCtrlAttribute.McuReset_ProtectAddr->Commond = 0xA5;
		 MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =1;
		 MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =~1;
		 MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =1;
	 }
	 while(MCU_stResetCtrlAttribute.McuReset_ProtectAddr->Status !=0ul);
 
	 while(1); /*stop here to wait reset!*/
 
 }

 
 /*****************************************************************************
  Function	: MCU_u32GetResetReason 											  
  Description	: get reset factor
  
  In Parameter: 
			 NULL
 Return Value:
			 reset factor register value
			 
  NOTE:  
  
 !!!!!!!! only call this function once, then clear the reset factor!!!!!!!!!!!!!
 
 the return value index the reset factor list follow:
 
	 MCU_mResetReason_DeepSTOP		 bit_10
	 MCU_mResetReason_PowerUp		 bit_9
	 MCU_mResetReason_ExternalReset  	 bit_8
	 MCU_mResetReason_CVM			 bit_7
	 MCU_mResetReason_LVI			 bit_6
	 MCU_mResetReason_CLMA2 		 bit_5
	 MCU_mResetReason_CLMA1 		 bit_4
	 MCU_mResetReason_CLMA0 		 bit_3
	 MCU_mResetReason_WDTA1 		 bit_2
	 MCU_mResetReason_WDTA0 		 bit_1
	 MCU_mResetReason_SoftwareRest	 bit_0
 
 *****************************************************************************/
 uint32 MCU_u32GetResetReason(void)
 {
	 if(MCU_u32ResetReason ==0)
	 {
		 MCU_u32ResetReason=MCU_stResetCtrlAttribute.ResetCtrl->RESFactor;	 
		 MCU_stResetCtrlAttribute.ResetCtrl->RESFClean=0x7FFF;
	 }
	 
	 return  MCU_u32ResetReason;
 }
	 

	 
#if (MCU_mFEinterruptEnable !=0u)
 /*IF is clean by hardware auto, so it is not need this function*/
/*****************************************************************************
 Function  : MCU_u16InterruptInit_FE												 
 Description   : FE level init to usring configeration
 
 In Parameter: 
 			NULL
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptInit_FE(void)
{
	uint16 u16RetVal=DET_Err_NotErr,MaskValue=1;
	uint32 u32Loop;
	vpFun *p=(vpFun *)MCU_stInterruptCtrlAttribute.FEMI_Cfg;
	
	for(u32Loop=0;u32Loop<MCU_stInterruptCtrlAttribute.MaxVectorNumber_FE;u32Loop++)
	{
		if(p[u32Loop] !=MCU_vNotExpINT)
		{
			MCU_stInterruptCtrlAttribute.FEMI->FEINTFMask &=~MaskValue;
		}
		
		MaskValue<<=1;
	}

	return u16RetVal;
}


/*****************************************************************************
 Function  : MCU_u16InterruptCtrl_FE												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptCtrl_FE(MCU_enIsrID_FE u16VectNum,uint8 u8IntEnable)
{
	uint16 MaskValue=1<<u16VectNum;
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber_FE, DET_Err_VectNumberOutOfRange);

	if(u8IntEnable)
	{
		MCU_stInterruptCtrlAttribute.FEMI->FEINTFMask &=~MaskValue;
	}
	else
	{
		MCU_stInterruptCtrlAttribute.FEMI->FEINTFMask |= MaskValue;
	}
	
	return u16RetVal;
}



 /*IF is clean by hardware auto, so it is not need this function*/
/*****************************************************************************
 Function  : MCU_u16InterruptFlagClean_FE												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
#if 0
uint16 MCU_u16InterruptFlagClean_FE(MCU_enIsrID_FE u16VectNum)
{
	uint16 u16RetVal=DET_Err_NotErr;
	uint16 MaskValue=1<<u16VectNum;

	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber_FE, DET_Err_VectNumberOutOfRange);

	MCU_stInterruptCtrlAttribute.FEMI->FEINTFClean |=MaskValue;
	
	return u16RetVal;
}
#endif

#endif

/*****************************************************************************
 Function  : MCU_u16InterruptCtrl												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptCtrl(MCU_enIsrID u16VectNum,uint8 u8IntEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;
	
	
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}

	if(u8IntEnable!=0)
	{
		pEIC->TB =1;/*-->yes, we using table mode as default*/
		pEIC->MK =0;
	}
	else
	{
		pEIC->MK =1;
	}
	
	return u16RetVal;
	
}

#if (MCU_mClearIF_Enable !=0u)
 /*IF is clean by hardware auto, so it is not need this function*/
/*****************************************************************************
 Function  : MCU_u16InterruptCtrl												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptFlagClean(MCU_enIsrID u16VectNum)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;
	
	
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}
	
	pEIC->RF =0;

	return u16RetVal;
	
}
#endif


#if (MCU_mINTPriorityChgEnable!=0u)
/*****************************************************************************
 Function  : MCU_u16ChangeVectorPriority												 
 Description   : change a vector number interrupt priority
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u16TargePri: new interrupt priority for u16VectNum
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			u16TargePri: 	0 ----->highest priority
 						7----->lowest priority
*****************************************************************************/
uint16 MCU_u16ChangeVectorPriority(MCU_enIsrID u16VectNum,uint16 u16TargePri)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;

	DET_ErrCheck(u16TargePri<MCU_mMaxVectorPrority , DET_Err_VectPriorityOutOfRange);
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}

	/*DI();--can not DI here to avoid loss interrput!!!*/
	/*WARNING:
		this operation may loss RF bit value !!!!*/
		
	pEIC->PRO= u16TargePri & 7;
	
	/*EI();*/
	
	return u16RetVal;
}

#endif

#if (MCU_mDMAModuleEnable !=0u)

#if (MCU_mDMASetUpIfEnable!=0)

vpFun MCU_vpDMA_CallBack[MCU_mDMA_MaxChn];

/*****************************************************************************
 Function  : MCU_u16DMAsetup												 
 Description   :setting the DMA channel and wait the start trigger to run
 
 In Parameter: 
 			stDMAsetup: expected DMA setting 

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16DMAsetup(MCU_tstDMA_SetUp stDMAsetup)
{
	uint16 u16RetVal=DET_Err_NotErr,u16DTCT,u16DataUnit;
	uint16 u16Trigger=stDMAsetup.u16InterruptTrigID;
	uint32 u32DMAchn=stDMAsetup.u32DMAChannel;
	
	DMA_Channel *DMAch;
	
	if(u32DMAchn<MCU_mDMA_MaxChn/2)
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_0_7[u32DMAchn]);
	}
	else
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_8_15[u32DMAchn-(MCU_mDMA_MaxChn/2)]);
	}

	if(stDMAsetup.u16InterruptTrigID <= MCU_mDMAtrig_Reserved63)
	{
		DET_ErrCheck(u32DMAchn< 8, DET_Err_DMAIDOutOfRange);
	}
	else if(stDMAsetup.u16InterruptTrigID <= MCU_mDMAtrig_Reserved127)
	{
		DET_ErrCheck(u32DMAchn>= 8 && u32DMAchn<=15, DET_Err_DMAIDOutOfRange);
		u16Trigger &=0x3F;/*mirror to 0 index!!*/
	}
	else
	{
		DET_ErrReport(DET_Err_DMATriggerIDOutOfRange);
	}
	
	u16DTCT=stDMAsetup.u16DataUnitSize;
	u16DataUnit=u16DTCT;
	u16DTCT=(u16DTCT&3)<<13;
	u16DTCT|=(stDMAsetup.u16AddrChgType&5)<<5;
			
#if (MCU_mDMASetUpIfEnable!=0)	
	MCU_vpDMA_CallBack[u32DMAchn]=stDMAsetup.vpINTservice;
#endif

	DI();
	DMAch->DTS &=~0x81;
	MCU_stDMAAttribute.DMA->DRQClear |=1<<u32DMAchn;
	MCU_stDMAAttribute.DMA->DTRC.u8Value=0x00;/*clear error and suspended DMA!*/
	DMAch->DSA=stDMAsetup.u32SourceAddr;
	DMAch->DDA=stDMAsetup.u32DestAddr;
	DMAch->DTCT=u16DTCT;
	DMAch->DTC=(stDMAsetup.u16DataLenth>>u16DataUnit)-1;/*bacause the first unit is work by HW trigger*/
	MCU_stDMAAttribute.DMA->DTFR[u32DMAchn]=0x8000u+u16Trigger;/*enable trigger*/	
	DMAch->DTS |=1;/*enable DMA run and wait for hardware interrupt*/
	EI();
		
	MCU_u16InterruptCtrl((MCU_enIsrID)(u32DMAchn+MCU_mISR_52_ICDMA0), 1u);

	return u16RetVal;

}

#endif

/*****************************************************************************
 Function  : MCU_u16DMAinit												 
 Description   :initial the DMA model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			this function execute before system-mainloop
*****************************************************************************/
static uint16 MCU_u16DMAinit(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	
#if (MCU_mDMASetUpIfEnable!=0)
	uint32 u32Loop;
	for(u32Loop=0;u32Loop<MCU_mDMA_MaxChn;u32Loop++)
	{
		MCU_vpDMA_CallBack[u32Loop]=MCU_vNotExpINT;
	}
#endif

	MCU_stDMAAttribute.DMA->DMCM.u16Value=0x0;
	MCU_stDMAAttribute.DMA->DRQClear=0xFFFF;/*clear request first*/
	
	return u16RetVal;

 }

 #if (MCU_DMAdefaultSetEnable !=0u)
/*****************************************************************************
 Function  : MCU_u16DMADefaultSetup												 
 Description   :init the DMA channel in default setting and wait the start trigger to run
 
 In Parameter: 
 			u32DMAchn: DMA ID list in _RH850.h

Return Value:
 			u16RetVal:function execute resault
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint16 MCU_u16DMADefaultSetup(MCU_enDmaID u32DMAchn)
{
	uint16 u16RetVal=DET_Err_NotErr,u16DTCT,u16DataUnit,u16Trigger;
	DMA_Channel *DMAch;
	
	DET_ErrCheck(u32DMAchn< MCU_mDMA_MaxChn, DET_Err_DMAIDOutOfRange);
	
	
	if(u32DMAchn<MCU_mDMA_MaxChn/2)
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_0_7[u32DMAchn]);
	}
	else
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_8_15[u32DMAchn-(MCU_mDMA_MaxChn/2)]);
	}
	
	u16Trigger=MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u16InterruptTrigID;
	if( u16Trigger<= MCU_mDMAtrig_Reserved63)
	{
		DET_ErrCheck(u32DMAchn< 8, DET_Err_DMAIDOutOfRange);
	}
	else if(u16Trigger <= MCU_mDMAtrig_Reserved127)
	{
		DET_ErrCheck(u32DMAchn>= 8 && u32DMAchn<=15, DET_Err_DMAIDOutOfRange);
		u16Trigger &=0x3F;/*mirror to 0 index!!*/
	}
	else
	{
		DET_ErrReport(DET_Err_DMATriggerIDOutOfRange);
	}

	u16DTCT=MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u16DataUnitSize;
	u16DataUnit=u16DTCT;
	u16DTCT=(u16DTCT&3)<<13;
	u16DTCT|=(MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u16AddrChgType&5)<<5;

#if (MCU_mDMASetUpIfEnable!=0)
	MCU_vpDMA_CallBack[u32DMAchn]=MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].vpINTservice;
#endif

	DI();
	DMAch->DTS &=~0x81;
	MCU_stDMAAttribute.DMA->DRQClear |=1<<u32DMAchn;
	MCU_stDMAAttribute.DMA->DTRC.u8Value=0x00;/*clear error and suspended DMA!*/
	DMAch->DSA=MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u32SourceAddr;
	DMAch->DDA=MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u32DestAddr;
	DMAch->DTCT=u16DTCT;
	DMAch->DTC=(MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].u16DataLenth>>u16DataUnit)-1;/*bacause the first unit is work by HW trigger*/
	MCU_stDMAAttribute.DMA->DTFR[u32DMAchn]=0x8000u+u16Trigger;/*enable trigger*/	
	DMAch->DTS |=1;/*enable DMA run and wait for hardware interrupt*/
	EI();
	
	MCU_u16InterruptCtrl((MCU_enIsrID)(u32DMAchn+MCU_mISR_52_ICDMA0), 1u);

	return u16RetVal;

}

#endif

/*****************************************************************************
 Function  : MCU_vDMAIsr												 
 Description   :DMA transfer finish interrupt service
 
 In Parameter: 
 			u16channel: DMA channel ID

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
 void MCU_vDMAIsr(MCU_enDmaID u32DMAchn)
 {
	uint16 u16RetVal=DET_Err_NotErr;
	
	DMA_Channel *DMAch;
	
		
	DET_ErrCheck(u32DMAchn< MCU_mDMA_MaxChn, DET_Err_DMAIDOutOfRange);
	
	if(u32DMAchn<MCU_mDMA_MaxChn/2)
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_0_7[u32DMAchn]);
	}
	else
	{
		DMAch=&(MCU_stDMAAttribute.DMA->DMA_8_15[u32DMAchn-MCU_mDMA_MaxChn/2]);
	}
	
	/*wait transfer finish before update*/
	while((DMAch->DTS & 0x80) ==0);
	
	DMAch->DTS &=~0x80;
	
	MCU_stDMAAttribute.DMA->DRQClear |=1<<u32DMAchn;
	MCU_stDMAAttribute.DMA->DTRC.u8Value=0x00;/*clear error and suspended DMA!*/

	
#if (MCU_mDMASetUpIfEnable!=0)
	if((MCU_vpDMA_CallBack[u32DMAchn]!=MCU_vNotExpINT)&&\
		MCU_vpDMA_CallBack[u32DMAchn]!=(vpFun)0)
	{
		MCU_vpDMA_CallBack[u32DMAchn]();
		MCU_vpDMA_CallBack[u32DMAchn]=MCU_vNotExpINT;
	}
	else
#endif
	MCU_stDMAAttribute.DMA_UsrCfg[u32DMAchn].vpINTservice();
	
 }
 
 #if MCU_mDMADeInitFuncEnable!=0u
/*****************************************************************************
 Function  : MCU_vDMADeInit												 
 Description   :clean the DMA model
 
 In Parameter: 
 			NULL

Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
 void MCU_vDMADeInit(void)
 {

 }
#endif

#endif /*end of DMA*/

#endif /*end of F1X*/


#if((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

/*****************************************************************************
 Function  : MCU_vClockInit_Basic												 
 Description   : CPU clock init, base part:
 			PLL, MainOsc, SubOsc,high speed interrnal Osc, Low speed interrnal Osc
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_Basic(void)
{
	uint32 u32MOSC=3,Mr=1,Pr,Nr,OscSpeed,Speed,FVV,PLLCvalue;
	
	uint16 u16RetVal=DET_Err_NotErr;
	
	/******************************************
			MainOsc setting and start it!
	*********************************************/
	OscSpeed = MCU_stClockAttribute.ClockUsrCfgHead->PLL0_Speed;/* --> find out Main OSC fre*/
	
	if( OscSpeed <=PLL_MainOsc_8M_120M)
	{
		u32MOSC =1;
	}
	else 	if( OscSpeed <=PLL_MainOsc_16M_80M)
	{
		u32MOSC =0;
	}
	#if ((MCU_UsingType > MCU_ID_RH850_D1M2H_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	else if( OscSpeed <=PLL1_MainOsc_8M_800M)
	{
		u32MOSC =1;
	}
	else 	if( OscSpeed <=PLL1_MainOsc_16M_780M)
	{
		u32MOSC =0;
	}
	#endif
	else
	{
		DET_ErrReport(DET_Err_MianOscSpeedOutOfRange);
	}
	
	MCU_stClockStatus.MainOsc_Speed=MCU_stPLL_CtrlValue[OscSpeed].MainOsc_Fre;

	MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Control = 6 | u32MOSC;
	MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.StableTime = MCU_stClockAttribute.ClockUsrCfgHead->MainOsc_StableTime *8;/*stable coounter is FHR*/

	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = 1;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = ~1;
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Enable = 1;
	}
	while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
	while((MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.Status & 4) ==0);


	/*main osc not stop in standby mode*/
	if(MCU_stClockAttribute.ClockUsrCfgHead->MainOscStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->MOSC.StopMask |= 1;
	}
	
	/******************************************
			SubOsc setting and start it!
	*********************************************/
	if(MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_FTX_Speed == 32768)
	{
		/*MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Control |= u32MOSC*/
		
		if(MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_StableTime != MCU_CLK_UsingDefault)
		{
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.StableTime = 
				MCU_stClockAttribute.ClockUsrCfgHead->SubOsc_StableTime * 8;/*stable coounter is FHR*/
		}

		MCU_stClockStatus.SubOsc_Speed=32768;
		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = 1;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = ~1;
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Enable = 1;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.Status & 4) ==0);
		
		/*sub osc not stop in standby mode
		if(MCU_stClockAttribute.ClockUsrCfgHead->SubOscStopInStandbyMode ==0)
		{
			MCU_stClockAttribute.AWOBlock_BasicAddr->SOSC.StopMask |= 1;
		}*/
		
	}
	
	/******************************************
			PLLs setting and start it!

	PLL0
	*********************************************/
	
	Speed = MCU_stClockAttribute.ClockUsrCfgHead->PLL0_Speed;
	DET_ErrCheck((Speed>=PLL_MainOsc_8M_480M) && \
				(Speed<=PLL_MainOsc_16M_80M), DET_Err_PLLSpeedOutOfRange);
	
	MCU_stClockStatus.PLL0_Speed=MCU_stPLL_CtrlValue[Speed].PLL_Fre;
	
	Mr =MCU_stPLL_CtrlValue[Speed].Mr-1;
	Pr=MCU_stPLL_CtrlValue[Speed].Pr;/*---->this value calc by use in the table!!*/
	Nr=MCU_stPLL_CtrlValue[Speed].Nr-1;
									
	FVV = MCU_stPLL_CtrlValue[Speed].FVV ;
	
	PLLCvalue = ((FVV<<29)|(Mr <<11) | (Pr<<8) | Nr);
			/*SELMFREQ | SSMODE |SELMPERCENT*/
//	PLLCvalue |=( 3<<24)|(3<<13)  |(7<<20);	
	
	MCU_stClockAttribute.PLL0->PLLCtrl= PLLCvalue;
	
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_ISO_Addr->Commond=0xA5;
		MCU_stClockAttribute.PLL0->PLLEnable= 1;
		MCU_stClockAttribute.PLL0->PLLEnable= ~1;
		MCU_stClockAttribute.PLL0->PLLEnable = 1;
	}
	while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
	while((MCU_stClockAttribute.PLL0->PLLStatus& 4) ==0);

	/*PLL0 output*/
	MCU_stClockAttribute.PLLCtrl[0].SSTP=1;
	while(MCU_stClockAttribute.PLLCtrl[0].SACT==0);

	/******************************************
			PLLs setting and start it!

	PLL1
	*********************************************/
	
#if ((MCU_UsingType > MCU_ID_RH850_D1M2H_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	Speed = MCU_stClockAttribute.ClockUsrCfgHead->PLL1_Speed;
	DET_ErrCheck((Speed>=PLL1_MainOsc_8M_960M) && \
				(Speed<=PLL1_MainOsc_16M_780M), DET_Err_PLLSpeedOutOfRange);
				
	MCU_stClockStatus.PLL1_Speed=MCU_stPLL_CtrlValue[Speed].PLL_Fre;
	
	Mr =MCU_stPLL_CtrlValue[Speed].Mr-1;
	Pr=MCU_stPLL_CtrlValue[Speed].Pr;
	Nr=(MCU_stPLL_CtrlValue[Speed].Nr)/2-1;/*PLL1 value Nr calc is different from others!!*/
	
	FVV = MCU_stPLL_CtrlValue[Speed].FVV;	
	
	PLLCvalue = ((FVV<<29)|(Mr <<11) | (Pr<<8) | Nr);
	MCU_stClockAttribute.PLL1->PLLCtrl= PLLCvalue;
	
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_ISO_Addr->Commond=0xA5;
		MCU_stClockAttribute.PLL1->PLLEnable= 1;
		MCU_stClockAttribute.PLL1->PLLEnable= ~1;
		MCU_stClockAttribute.PLL1->PLLEnable = 1;
	}
	while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
	
	while((MCU_stClockAttribute.PLL1->PLLStatus& 4) ==0);


#else
	Speed = MCU_stClockAttribute.ClockUsrCfgHead->PLL1_Speed;
	DET_ErrCheck((Speed>=PLL_MainOsc_8M_480M) && \
				(Speed<=PLL_MainOsc_16M_80M), DET_Err_PLLSpeedOutOfRange);
	
	MCU_stClockStatus.PLL1_Speed=MCU_stPLL_CtrlValue[Speed].PLL_Fre;
	
	Mr =MCU_stPLL_CtrlValue[Speed].Mr-1;
	Pr=MCU_stPLL_CtrlValue[Speed].Pr;
	Nr=MCU_stPLL_CtrlValue[Speed].Nr-1;
	
	FVV = 0;	
	
	PLLCvalue = ((FVV<<29)|(Mr <<11) | (Pr<<8) | Nr);
	MCU_stClockAttribute.PLL1->PLLCtrl= PLLCvalue;
	
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_ISO_Addr->Commond=0xA5;
		MCU_stClockAttribute.PLL1->PLLEnable= 1;
		MCU_stClockAttribute.PLL1->PLLEnable= ~1;
		MCU_stClockAttribute.PLL1->PLLEnable = 1;
	}
	while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
	while((MCU_stClockAttribute.PLL1->PLLStatus& 4) ==0);



#endif

	/*PLL1 output*/
	MCU_stClockAttribute.PLLCtrl[1].SSTP=1;
	while(MCU_stClockAttribute.PLLCtrl[1].SACT==0);

	
#if ((MCU_UsingType > MCU_ID_RH850_D1M2H_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))

	/******************************************
			PLLs setting and start it!

	PLL2
	*********************************************/
	Speed = MCU_stClockAttribute.ClockUsrCfgHead->PLL2_Speed;
	DET_ErrCheck((Speed>=PLL_MainOsc_8M_480M) && \
				(Speed<=PLL_MainOsc_16M_80M), DET_Err_PLLSpeedOutOfRange);
				
	MCU_stClockStatus.PLL2_Speed=MCU_stPLL_CtrlValue[Speed].PLL_Fre;
	
	Mr =MCU_stPLL_CtrlValue[Speed].Mr-1;
	Pr=MCU_stPLL_CtrlValue[Speed].Pr;
	Nr=MCU_stPLL_CtrlValue[Speed].Nr-1;
	
	FVV = 0;	
	
	PLLCvalue = ((FVV<<29)|(Mr <<11) | (Pr<<8) | Nr);
	MCU_stClockAttribute.PLL2->PLLCtrl= PLLCvalue;
	
	/*write protect register*/
	do
	{
		MCU_stClockAttribute.Protect_ISOExt_Addr->Commond=0xA5;
		MCU_stClockAttribute.PLL2->PLLEnable= 1;
		MCU_stClockAttribute.PLL2->PLLEnable= ~1;
		MCU_stClockAttribute.PLL2->PLLEnable = 1;
	}
	while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
	
	while((MCU_stClockAttribute.PLL2->PLLStatus& 4) ==0);

#else
	MCU_stClockStatus.PLL2_Speed=0;

#endif

}


/*****************************************************************************
 Function  : MCU_vClockInit_AWO												 
 Description   : CPU clock init, AWO part:
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vClockInit_AWO(void)
{
	uint32 SetValue;
	
	/********************************
			CKSC_AAWOTS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_AAWOTS=MCU_stClockStatus.IntOscHS_FRH_Speed;

	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_AAWOTS ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
				MCU_stClockStatus.IntOscHS_FRH_Speed,
				MCU_stClockStatus.MainOsc_Speed, 
				MCU_stClockStatus.IntOscLS_FRL_Speed};
		MCU_stClockStatus.ClkSpeed_CKSC_AAWOTS=ClockTbl[SetValue];
		
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTS.SourceSel= SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTS.SourceSel = SetValue;
		}while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTS.Active /*& SetValue*/) !=SetValue);
		
	}
			
	if(MCU_stClockAttribute.ClockUsrCfgHead->AAWOTStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTS.StopMask |= 1;
	}
	
	/********************************
			CKSC_AAWOTD
	************************************/
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_AAWOTD ;
	if((SetValue !=MCU_CLK_UsingDefault)&&(MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_AAWOTS !=0))
	{
		MCU_stClockStatus.ClkSpeed_CKSC_AAWOTS>>=(SetValue-1);
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTD.Divider= SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTD.Divider = SetValue;
		}while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AAWOTD.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_AWDTA0D
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_AWDTA0D=MCU_stClockStatus.IntOscLS_FRL_Speed/128;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_AWDTA0D ;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[7]={0,128,1,256, 512,1024,2048};

		if(ClockTbl[SetValue] ==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_AAWOTS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_AAWOTS=MCU_stClockStatus.IntOscLS_FRL_Speed/ClockTbl[SetValue];
		}

		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTA0D.Divider= SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTA0D.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTA0D.Divider = SetValue;
		}while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AWDTA0D.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ARTCAS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ARTCAS=0;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ARTCAS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[5]={0,
				MCU_stClockStatus.SubOsc_Speed,
				MCU_stClockStatus.MainOsc_Speed, 
				MCU_stClockStatus.IntOscLS_FRL_Speed,
				MCU_stClockStatus.IntOscHS_FRH_Speed};
		MCU_stClockStatus.ClkSpeed_CKSC_ARTCAS=ClockTbl[SetValue];
				
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.Active /*& SetValue*/) !=SetValue);
	}
	
	if(MCU_stClockAttribute.ClockUsrCfgHead->ARTCAStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAS.StopMask |= 1;
	}
	
	/********************************
			CKSC_ARTCAD
	************************************/
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_ARTCAD;
	if((SetValue !=MCU_CLK_UsingDefault)&&(MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ARTCAS !=0))
	{
		if(SetValue ==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ARTCAS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ARTCAS>>=(SetValue-1);
		}

		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_ARTCAD.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_AFOUTS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_AFOUTS=0;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_AFOUTS;
	if(SetValue !=MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[8]={0,
						MCU_stClockStatus.MainOsc_Speed, 
						MCU_stClockStatus.IntOscHS_FRH_Speed,
						MCU_stClockStatus.IntOscLS_FRL_Speed,
						MCU_stClockStatus.SubOsc_Speed,
						MCU_stClockStatus.PLL0_Speed/4,
						MCU_stClockStatus.PLL1_Speed/4,
						MCU_stClockStatus.PLL2_Speed/4};
						
		MCU_stClockStatus.ClkSpeed_CKSC_AFOUTS=ClockTbl[SetValue];

		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.Active /*& SetValue*/) !=SetValue);
	}
	
	if(MCU_stClockAttribute.ClockUsrCfgHead->AFOUTStopInStandbyMode ==0)
	{
		MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTS.StopMask |= 1;
	}

	/********************************
			CKSC_AFOUTD
	************************************/
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_AFOUTD;
	if((SetValue !=MCU_CLK_UsingDefault) &&(MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_AFOUTS !=0))
	{
		if(SetValue==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_AFOUTS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_AFOUTS/=SetValue;
		}
		
		do
		{
			MCU_stClockAttribute.Protect_AWO_Addr->Commond =0xA5;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTD.Divider= SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTD.Divider = ~SetValue;
			MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_AWO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.AWOBlock_BasicAddr->CKSC_AFOUTD.Status) != 3);
	}
	

}



/*****************************************************************************
 Function  : MCU_vClockInit_ISO												 
 Description   : CPU clock init, ISO part:
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vClockInit_ISO(void)
{
	uint32 SetValue,Div=1;
	uint32 u32wait_1us=960;
	uint32 DivList[6]={1,1,2,4,8,3};
	
	/********************************
			CKSC_ICPUCLKD
	************************************/
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_ICPUCLKD;
	
	if(SetValue ==MCU_CLK_UsingDefault)
	{
		SetValue=1;
	}
	
	 if(SetValue<6)
	{
		Div=SetValue;
		/*SetValue = 1;001B: CKSC_ICPUCLKS_CTL selection /1 (default) -->we use this value for CPU 
					010B: CKSC_ICPUCLKS_CTL selection /2
					011B: CKSC_ICPUCLKS_CTL selection /4
					100B: CKSC_ICPUCLKS_CTL selection /8
					101B: CKSC_ICPUCLKS_CTL selection /3*/
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKD.Divider= SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKD.Divider = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKD.Divider = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		while(u32wait_1us--){;}
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKD.Active /*& SetValue*/) !=SetValue);
	}
	
	
	/********************************
			CKSC_ICPUCLKS
	************************************/
	MCU_stClockStatus.CPUCLK_Speed=MCU_stClockStatus.IntOscHS_FRH_Speed;
	SetValue =MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ICPUCLKS;
	
	/*SetValue = 4;001B: EMCLK (default)
				011B: PLL0CLK 
				100B: PLL1CLK*/
	if((SetValue !=MCU_CLK_UsingDefault) && (SetValue<=4))
	{
		uint32 ClockTbl[5]={0,
						MCU_stClockStatus.IntOscHS_FRH_Speed,
						0,
						MCU_stClockStatus.PLL0_Speed,
						MCU_stClockStatus.PLL1_Speed};
		do
		{
			MCU_stClockAttribute.Protect_ISO_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISO_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOBlock_BasicAddr->CKSC_ICPUCLKS.Active /*& SetValue*/) !=SetValue);
		
		MCU_stClockStatus.CPUCLK_Speed=ClockTbl[SetValue];
	}
	
	MCU_stClockStatus.CPUCLK_Speed/=DivList[Div];
	MCU_stClockStatus.ClkSpeed_CKSC_PCLK=MCU_stClockStatus.CPUCLK_Speed/4;/*CPU clock div4 to PCLK*/
	
}

/*****************************************************************************
 Function  : MCU_vClockInit_ExtISO												 
 Description   : CPU clock init, ExtISO part:
 
 In Parameter: 
 			NULL
Return Value:
 			NULL
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vClockInit_ExtISO(void)
{
	uint32 SetValue;

	/********************************
			CKSC_IPLLFIXS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS=MCU_stClockStatus.PLL1_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IPLLFIXS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={MCU_stClockStatus.PLL1_Speed,
						MCU_stClockStatus.PLL2_Speed};
						
		MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPLLFIXS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPLLFIXS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPLLFIXS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPLLFIXS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ISDRBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ISDRBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ISDRBS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={0,
						MCU_stClockStatus.PLL1_Speed/2};
		MCU_stClockStatus.ClkSpeed_CKSC_ISDRBS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISDRBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISDRBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISDRBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISDRBS.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_IXCCLKS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IXCCLKS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IXCCLKS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={0,
						MCU_stClockStatus.CPUCLK_Speed/2};
		MCU_stClockStatus.ClkSpeed_CKSC_IXCCLKS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCCLKS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCCLKS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCCLKS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCCLKS.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_IXCETNBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IXCETNBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IXCETNBS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_IXCCLKS};
		MCU_stClockStatus.ClkSpeed_CKSC_IXCETNBS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCETNBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCETNBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCETNBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCETNBS.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_IXCMLBBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IXCMLBBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IXCMLBBS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_IXCCLKS};
		MCU_stClockStatus.ClkSpeed_CKSC_IXCMLBBS=ClockTbl[SetValue];
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCMLBBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCMLBBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCMLBBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IXCMLBBS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ICLKFIXS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS=MCU_stClockStatus.IntOscHS_FRH_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ICLKFIXS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue ==2)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS=MCU_stClockStatus.IntOscHS_FRH_Speed;
		}
		else
		{
			/*Keep value!!*/
		}
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKFIXS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKFIXS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKFIXS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKFIXS.Active /*& SetValue*/) !=SetValue);
	}

	
	/********************************
			CKDV_ICLKFIXD
	************************************/
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_ICLKFIXD;
	if((SetValue != MCU_CLK_UsingDefault) && (MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ICLKFIXS==1))
	{
		uint32 ClockTbl[5]={0,6,8,10,12};
		if(ClockTbl[SetValue]==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/ClockTbl[SetValue];
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKFIXD.Divider= SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKFIXD.Divider= ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKFIXD.Divider= SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKFIXD.Status/*& SetValue*/) !=SetValue);
	}
	

	/********************************
			CKSC_IPCRSCANS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IPCRSCANS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IPCRSCANS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue !=0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IPCRSCANS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IPCRSCANS=0;
		}
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCRSCANS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCRSCANS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCRSCANS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCRSCANS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_IPCMLBBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IPCMLBBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IPCMLBBS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[2]={0,
						MCU_stClockStatus.CPUCLK_Speed/4};
		MCU_stClockStatus.ClkSpeed_CKSC_IPCMLBBS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCMLBBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCMLBBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCMLBBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCMLBBS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_IMLBBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IMLBBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IMLBBS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,
						MCU_stClockStatus.PLL0_Speed/2,
						MCU_stClockStatus.PLL0_Speed/4,};
		MCU_stClockStatus.ClkSpeed_CKSC_IMLBBS=ClockTbl[SetValue];
						
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IMLBBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IMLBBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IMLBBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IMLBBS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ISFMAS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ISFMAS=MCU_stClockStatus.PLL1_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ISFMAS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[3]={0,MCU_stClockStatus.PLL0_Speed,
						MCU_stClockStatus.PLL1_Speed,};
		MCU_stClockStatus.ClkSpeed_CKSC_ISFMAS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAS.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_ISFMAD
	************************************/
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_ISFMAD;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[5]={0,2,3,4,6};
		if(ClockTbl[SetValue]==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ISFMAS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ISFMAS/=ClockTbl[SetValue];
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAD.Divider= SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAD.Divider= ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAD.Divider= SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ISFMAD.Status /*& SetValue*/) !=SetValue);
	}
	else
	{
		MCU_stClockStatus.ClkSpeed_CKSC_ISFMAS=0;
	}
	
	/********************************
			CKSC_ICLKJITS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS=MCU_stClockStatus.IntOscHS_FRH_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ICLKJITS;
	if(SetValue ==1)
	{
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKJITS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKJITS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKJITS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ICLKJITS.Active /*& SetValue*/) !=SetValue);

		MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS=MCU_stClockStatus.PLL0_Speed;
	}

	
	
	/********************************
			CKDV_ICLKJITD
	************************************/
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_ICLKJITD;
	if(MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ICLKJITS ==1)
	{
		if(SetValue == MCU_CLK_UsingDefault )
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/=6;
		}
		else
		{
			if(SetValue==0)
			{
				MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS=0;
			}
			else
			{
				do
				{
					MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
					MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKJITD.Divider= SetValue;
					MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKJITD.Divider= ~SetValue;
					MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKJITD.Divider= SetValue;
				}
				while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
				while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ICLKJITD.Status /*& SetValue*/) !=3/*clock and divider active!!*/);
				
				MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS /=SetValue;
			}
		}
	}


	
	/********************************
			CKSC_IISMS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IISMS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IISMS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_CKSC_IISMS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IISMS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IISMS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IISMS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IISMS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_IADCED
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IADCED=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/2;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_IADCED;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		MCU_stClockStatus.ClkSpeed_CKSC_IADCED=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/4;
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IADCED.Divider= SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IADCED.Divider= ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IADCED.Divider= SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IADCED.Status /*& SetValue*/) !=SetValue);
	}


	/********************************
			CKSC_ILCBIS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ILCBIS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ILCBIS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue!=0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_ILCBIS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
		
			do
			{
				MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
				MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ILCBIS.SourceSel = SetValue;
				MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ILCBIS.SourceSel = ~SetValue;
				MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ILCBIS.SourceSel = SetValue;
			}
			while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
			
			while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ILCBIS.Active /*& SetValue*/) !=SetValue);
		}
	}

	/********************************
			CKSC_IRLINS
	************************************/

	/*D1M1H MCU clock default value is different from others!!*/
	#if ((MCU_UsingType > MCU_ID_RH850_D1M1H_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M1H_End))
	MCU_stClockStatus.ClkSpeed_CKSC_IRLINS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
	#else
	MCU_stClockStatus.ClkSpeed_CKSC_IRLINS=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/20;
	#endif
	
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IRLINS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue==1)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRLINS=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/10;
		}
		else if(SetValue==2)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRLINS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS;
		}
		else
		{
			/*keep default value!!*/
			/*MCU_stClockStatus.ClkSpeed_CKSC_IRLINS=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/20*/
			
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRLINS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRLINS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRLINS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRLINS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_ITAUB01S
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ITAUB01S=MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ITAUB01S;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[5]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/8};
						
		MCU_stClockStatus.ClkSpeed_CKSC_ITAUB01S=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB01S.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB01S.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB01S.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB01S.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_ITAUB2S
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ITAUB2S=MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ITAUB2S;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[6]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/8,
						MCU_stClockStatus.MainOsc_Speed};
						
		MCU_stClockStatus.ClkSpeed_CKSC_ITAUB2S=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB2S.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB2S.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB2S.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUB2S.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_ITAUJS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_ITAUJS=MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_ITAUJS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[8]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKFIXS/8,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS/8,
						MCU_stClockStatus.MainOsc_Speed,
						MCU_stClockStatus.CPUCLK_Speed/4	};
						
		MCU_stClockStatus.ClkSpeed_CKSC_ITAUJS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUJS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUJS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUJS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_ITAUJS.Active /*& SetValue*/) !=SetValue);
	}
	
	/********************************
			CKSC_IOSTMS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IOSTMS=MCU_stClockStatus.CPUCLK_Speed/4;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IOSTMS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[4]={0,
						MCU_stClockStatus.ClkSpeed_CKSC_ICLKJITS,
						MCU_stClockStatus.CPUCLK_Speed/4,
						MCU_stClockStatus.MainOsc_Speed};
						
		MCU_stClockStatus.ClkSpeed_CKSC_IOSTMS=ClockTbl[SetValue];
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IOSTMS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IOSTMS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IOSTMS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IOSTMS.Active /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_IRSCAND
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IRSCAND=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/12;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKSC_IRSCAND;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		uint32 ClockTbl[6]={0,30,40,60,12,24};
		if(ClockTbl[SetValue]==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRSCAND=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRSCAND=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/ClockTbl[SetValue];
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCAND.Divider= SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCAND.Divider= ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCAND.Divider= SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCAND.Status /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKDV_ISSIFD
	************************************/
	MCU_stClockStatus.ClkSpeed_CKDV_ISSIFD=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/10;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkDiv_CKDV_ISSIFD;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue==0)
		{
			MCU_stClockStatus.ClkSpeed_CKDV_ISSIFD=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKDV_ISSIFD=MCU_stClockStatus.ClkSpeed_CKSC_IPLLFIXS/SetValue;
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ISSIFD.Divider= SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ISSIFD.Divider= ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ISSIFD.Divider= SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKDV_ISSIFD.Status /*& SetValue*/) !=SetValue);
	}

	/********************************
			CKSC_IRSCANXINS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IRSCANXINS=MCU_stClockStatus.MainOsc_Speed;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IRSCANXINS;
	if(SetValue != MCU_CLK_UsingDefault)
	{
		if(SetValue==0)
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRSCANXINS=0;
		}
		else
		{
			MCU_stClockStatus.ClkSpeed_CKSC_IRSCANXINS=MCU_stClockStatus.MainOsc_Speed;
		}
		
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCANXINS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCANXINS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCANXINS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IRSCANXINS.Active /*& SetValue*/) !=SetValue);
	}


	/********************************
			CKSC_IPCETNBS
	************************************/
	MCU_stClockStatus.ClkSpeed_CKSC_IPCETNBS=0;
	SetValue = MCU_stClockAttribute.ClockUsrCfgHead->ClkSel_CKSC_IPCETNBS;
	if(SetValue ==1)
	{
		do
		{
			MCU_stClockAttribute.Protect_ISOExt_Addr->Commond =0xA5;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCETNBS.SourceSel = SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCETNBS.SourceSel = ~SetValue;
			MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCETNBS.SourceSel = SetValue;
		}
		while(MCU_stClockAttribute.Protect_ISOExt_Addr->Status !=0ul);
		
		while((MCU_stClockAttribute.ISOExtBlock_BasicAddr->CKSC_IPCETNBS.Active /*& SetValue*/) !=SetValue);
		
		MCU_stClockStatus.ClkSpeed_CKSC_IPCETNBS=MCU_stClockStatus.ClkSpeed_CKSC_PCLK;
	}

}

#if (MCU_mClockMonitorEnable !=0u)
/*****************************************************************************
 Function  : MCU_vClockInit_ClockMonitor												 
 Description   : CPU clock monitor,-->not finish, it will reset once call this function!!
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
 			
*****************************************************************************/
static void MCU_vClockInit_ClockMonitor(void)
{
	uint32 SetValue,TolerancePercent,MainOscValue =MEGA(8);
	uint32 Hvalue,Lvalue,PLLClk,PLLClkindex;
	uint16 u16RetVal=DET_Err_NotErr;

	/*******************************************
	CLMA0:
	internal high speed OSC monitor setting:
	
	sample clock = interrnal low speed OSC = 240 kHz
	Monitor HS = 8M
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA0enable_HS;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA0TolerancePercent;
		Hvalue =( MCU_stClockStatus.IntOscHS_FRH_Speed* (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Hvalue+=1;
		
		Lvalue =( MCU_stClockStatus.IntOscHS_FRH_Speed * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitor_CLMA0->CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitor_CLMA0->CompareL =Lvalue;
		
		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitor_CLMA0->ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitor_CLMA0->Control= 1;
			MCU_stClockAttribute.ClockMonitor_CLMA0->Control=  ~1;
			MCU_stClockAttribute.ClockMonitor_CLMA0->Control=  1;
		}
		while(MCU_stClockAttribute.ClockMonitor_CLMA0->ProtectUnit.Status !=0ul);
		
	}

	/*******************************************
	CLMA1:
	LS monitor setting:
	
	sample clock = HS/256 = 31.25 kHz
	Monitor  = LS
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA1enable_LS;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA1TolerancePercent;
		Hvalue =( MCU_stClockStatus.IntOscLS_FRL_Speed * (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscHS_FRH_Speed/256 * 100) ;
		Hvalue+=1;
		
		Lvalue =( MCU_stClockStatus.IntOscLS_FRL_Speed * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscHS_FRH_Speed/256 * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA1_LS.ProtectUnit.Status !=0ul);
		
	}

	/*******************************************
	CLMA2:
	MainOSC monitor setting:
	
	sample clock = LS = 240 kHz
	Monitor  = LS
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA2enable_MainOsc;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		PLLClkindex=MCU_stClockAttribute.ClockUsrCfgHead->PLL0_Speed;
		MainOscValue=MCU_stPLL_CtrlValue[PLLClkindex].MainOsc_Fre;

		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA2TolerancePercent;
		Hvalue =( MCU_stClockStatus.MainOsc_Speed * (100 +TolerancePercent )) / (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Hvalue+=1;
		
		Lvalue =( MCU_stClockStatus.MainOsc_Speed * (100 -TolerancePercent)) /  (MCU_stClockStatus.IntOscLS_FRL_Speed * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA2_MainOsc.ProtectUnit.Status !=0ul);
		
	}

	/*******************************************
	CLMA3:
	PLL0 monitor setting:
	
	sample clock = LS = 240 kHz
	Monitor  = PLL0CLK/16
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA3enable_PLL0;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		PLLClkindex=MCU_stClockAttribute.ClockUsrCfgHead->PLL0_Speed;
		PLLClk=MCU_stPLL_CtrlValue[PLLClkindex].PLL_Fre / 16;

		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA3TolerancePercent;
		Hvalue =( PLLClk * (100 +TolerancePercent )) / (240000 * 100) ;
		Hvalue+=1;
		
		Lvalue =( PLLClk * (100 -TolerancePercent)) /  (240000 * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA3_PLL0.ProtectUnit.Status !=0ul);
		
	}
	
	
	/*******************************************
	CLMA4:
	PLL1 monitor setting:
	
	sample clock = LS = 240 kHz
	Monitor  = PLL1CLK/16
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->CLMA4enable_PLL1;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		PLLClkindex=MCU_stClockAttribute.ClockUsrCfgHead->PLL1_Speed;
		PLLClk=MCU_stPLL_CtrlValue[PLLClkindex].PLL_Fre/16;

		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA4TolerancePercent;
		Hvalue =( PLLClk * (100 +TolerancePercent )) / (240000 * 100) ;
		Hvalue+=1;
		
		Lvalue =( PLLClk * (100 -TolerancePercent)) /  (240000 * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA4_PLL1.ProtectUnit.Status !=0ul);
		
	}
	
	
	/*******************************************
	CLMA5:
	Video0 input monitor setting:
	
	sample clock = LS = 240 kHz
	Monitor  = VDCE0_VI_CLK
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->Video0_InClkFre;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA5TolerancePercent;
		Hvalue =( SetValue * (100 +TolerancePercent )) / (240000 * 100) ;
		Hvalue+=1;
		
		Lvalue =( SetValue * (100 -TolerancePercent)) /  (240000 * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA5_Video0In.ProtectUnit.Status !=0ul);
		
	}

	/*******************************************
	CLMA6:
	Video1 input monitor setting:
	
	sample clock = LS = 240 kHz
	Monitor  = VDCE1_VI_CLK
	
	*********************************************/
	SetValue=MCU_stClockAttribute.ClockUsrCfgHead->Video1_InClkFre;
	if(SetValue !=0ul && SetValue !=MCU_CLK_UsingDefault)
	{
		TolerancePercent =MCU_stClockAttribute.ClockUsrCfgHead->CLMA6TolerancePercent;
		Hvalue =( SetValue * (100 +TolerancePercent )) / (240000 * 100) ;
		Hvalue+=1;
		
		Lvalue =( SetValue * (100 -TolerancePercent)) /  (240000 * 100) ;
		Lvalue -=1;

		DET_ErrCheck((Hvalue -Lvalue) >3, DET_Err_CLMAValueNotAllow);

		MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.CompareH = Hvalue;
		MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.CompareL =Lvalue;

		/*write protect register*/
		do
		{
			MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.ProtectUnit.Commond=0xA5;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.Control= 1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.Control = ~1;
			MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.Control = 1;
		}
		while(MCU_stClockAttribute.ClockMonitorBlock->CLMA6_Video1In.ProtectUnit.Status !=0ul);
		
	}

}
#endif

/*****************************************************************************
 Function  : MCU_vLowVoltDetectInit												 
 Description   :Low voltage detect setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it will while(1){MCU Reset} after call this function if the 5V supply is below the lowest voltage

*****************************************************************************/
static void MCU_vLowVoltDetectInit(void)
{
	/*LVI module is not mount in this chip*/
}

/************************************************************************
 Function  : MCU_vStandbyCtrl_IoHold											 
 Description   :Low voltage detect setting initialization
 
 In Parameter: 
			PortIDmaskBit : Pin group mask bit 
			
Return Value:
			NULL
			
 NOTE:		

bit0 : 	Hold Port0 in deep_sleep mode
bit1 : 	Hold Port1 and Port2 in deep_sleep mode
bit2 : 	Hold Port3 in deep_sleep mode
bit3 : 	D1L1, D1L2:
		¡V P43_0, P43_1
		¡V P44_1 to P44_4, P44_6 to P44_11
		¡V P45_0 to P45_13.
		
		 D1L2H, D1M1(H)
		¡V P43_0, P43_1
		¡V P44_0 to P44_11
		¡V P45_0 to P45_13.
		
		D1M2(H):
			P43_0 to P43_6 
			P46 and P47.
			
bit4 : 	Hold P43_7 to P43_12 in deep_sleep mode
bit5 : 	Hold P42 in deep_sleep mode
bit6 : 	Hold P16 and P17 in deep_sleep mode
		
************************************************************************/
void MCU_vStandbyCtrl_IoHold(uint32 PortIDmaskBit)
{
	uint16 u16RetVal=DET_Err_NotErr;

	DET_ErrCheck(PortIDmaskBit<=0x7F, DET_Err_ParaOutOfRange);
	
	DI();
	do
	{
		MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
		MCU_stSTBCAttribute.STBC->IoHold=PortIDmaskBit;
		MCU_stSTBCAttribute.STBC->IoHold=~PortIDmaskBit;
		MCU_stSTBCAttribute.STBC->IoHold=PortIDmaskBit;
	}
	/*wait IO released!!*/
	while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);
	
	EI();
}

#if (MCU_mCPUModeCtrlEnable !=0u)
/*****************************************************************************
 Function  : MCU_vStandbyCtrl_ChgToMode												 
 Description   :MCU running mode control, to enter normal-mode, standby-mode, halt-mode ect
 
 In Parameter: 
 			u8ExpMode :MCU expected running mode 

						0: Halt mode =>
						
							the CPU operation clock 						--->stopped. 
							
							 the highspeed system clock oscillator, 			--->running
							 internal high-speed oscillator, 				--->running
							 internal low-speed oscillator  clock continues.	--->running
														
						1: Stop mode =>
						
							the CPU operation clock						 --->stopped. 

							 the highspeed system clock oscillator			--->stopped. 
							 internal high-speed oscillator					--->stopped. 
							 internal low-speed oscillator  clock continues	--->stopped. 
							 
Return Value:

			NULL
 			
 NOTE: 		
 
			CPU will not excute next commond until wake up!
		
*****************************************************************************/
void MCU_vStandbyCtrl_ChgToMode(MCU_enRunModeID u8ExpMode)
{
	if(u8ExpMode == MCU_mHaltMode)
	{
		EI_Force();
		HALT();

		/*need check what to do ~~~~~~~~~~~~~*/
	}
	else if(u8ExpMode == MCU_mDeepStopMode)
	{
		
		EI_Force();		
		do
		{
			/*go to deep standby mode!!!*/
			MCU_stSTBCAttribute.ProtectAddr->Commond=0xA5;
			MCU_stSTBCAttribute.STBC->PSC=2;
			MCU_stSTBCAttribute.STBC->PSC=~2;
			MCU_stSTBCAttribute.STBC->PSC=2;
		}
		/*wait IO released!!*/
		while(MCU_stSTBCAttribute.ProtectAddr->Status !=0u);
		
		MCU_stSTBCAttribute.STBC->WUFC = 0x0007FFFF;/*clean wakeup factor for new wakeup again !!*/
		/**while(1);*--->not use while(1), it will retry if it happen wakeup signal*/
	}
	else
	{

	
	}
	
}


/***************************************************************
 Function  : MCU_vStandbyCtrl_SetWakeUpFactor												 
 Description   :wake up factor setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		

wakeup factor enablecontrol::

	1 = enable
	0 = disable
	
		bit 0:	 	INTDCUTDI	 
		bit 1:	 	INTP0_RLIN31RX	 
		bit 2:	 	INTP1	 
		bit 3:	 	INTP _RLIN3 RX	 
		bit 4:	 	INTP3	 
		bit 5:	 	INTP4_RLIN33RX	 
		bit 6:	 	INTP5	 
		bit 7:	 	INTP6_CAN0RX	 
		bit 8:	 	INTP7	 
		bit 9:	 	INTP8_CAN1RX_RLIN30RX	 
		bit 10:	 	INTP9	
		bit 11:	 	INTP10_CAN RX_RLIN30RX	 
		bit 12:	 	INTWDTA0	 
		bit 13:	 	INTRTCA01S	 
		bit 14:	 	INTRTCA0AL	 
		bit 15:	 	INTRTCA0R	 
		bit 16:	 	INTAWOT0	 
		bit 17:	 	ECMTI	 
		bit 18:	 	ECMTNMI

**********************************************************/
void MCU_vStandbyCtrl_SetWakeUpFactor(void)
{
	DI();
	MCU_stSTBCAttribute.STBC->WUFMSK =~*(uint32 *)&MCU_stSTBCAttribute.STBC_UsrCfg->WakeUpEnable;	
	EI();
}

 /*****************************************************************************
  Function	: MCU_vStandbyCtrl_CleanAllWakeUpFactor											  
  Description	:clean the Wake Up Factor before change mode to stop,
  
  In Parameter: 
			 NULL
			 
 Return Value:
			 NULL
			 
  NOTE: 	 
			 call this function before system mainloop
 
 *****************************************************************************/
 void MCU_vStandbyCtrl_CleanAllWakeUpFactor(void)
 {
	 DI();
	 
	 MCU_stSTBCAttribute.STBC->WUFC = 0xFFFFFFFF;/*clean wakeup factor  !!*/
	 
	 EI();
 }


#if (MCU_mGetWakeUpFactorEnable !=0u) 

/*****************************************************************************
 Function  : MCU_u32GetWakeUpFactor												 
 Description   : get wake up factor
 
 In Parameter: 
 			NULL
Return Value:
 			wake up factor ID
 NOTE: 		
 			NULL
*****************************************************************************/
MCU_enWakeFactorID MCU_u32GetWakeUpFactor(void)
{

	uint32 u32WakeupFactor,u32Loop,u32Mask=1,u32FinalID;
	
	u32WakeupFactor=MCU_stSTBCAttribute.STBC->WUFC;					/*factor 1*/

	for(u32Loop=0;u32Loop<19;u32Loop++)
	{
		if((u32Mask & u32WakeupFactor) !=0)
		{
			u32FinalID=u32Loop;
			break;
		}
		else
		{
			u32Mask<<=1;
		}
	}
	
	return (MCU_enWakeFactorID)u32FinalID;
	
}

#endif

#endif

/*****************************************************************************
Function  : MCU_vResetCtrl_Reset 											 
Description   :MCU software reset request, it will reset MCU and re-run from file starup.850

In Parameter: 
		NULL
		
Return Value:
		NULL
		
NOTE:		
		NULL
*****************************************************************************/
void MCU_vResetCtrl_Reset(void)
{
	do
	{
		MCU_stResetCtrlAttribute.McuReset_ProtectAddr->Commond = 0xA5;
		MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =1;
		MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =~1;
		MCU_stResetCtrlAttribute.ResetCtrl->SWRESrequest =1;
	}
	while(MCU_stResetCtrlAttribute.McuReset_ProtectAddr->Status !=0ul);

	while(1); /*stop here to wait reset!*/

}


/***********************************************
 Function  : MCU_vResetCtrl_ModuleCtrl												 
 Description   : reset a module resource
 
 In Parameter: 
 			NULL
Return Value:

NOTE:
	
module release/reset control mdule:

	 1 = reset/release module
	 0 = keep status

		 bit0 =  		  VDCE0RES "
		 bit1 =  		  VDCE1RES "
		 bit2 =  		  ETNB0RES "
		 bit3 =  		  ISM0RES "
		 bit4 =  		  ADCE0RES "
		 bit5 =  		  SG0RES "
		 bit6 =  		  SG1RES "
		 bit7 =  		  SG2RES "
		 bit8 =  		  SG3RES "
		 bit9 =  		  SG4RES "
		 bit10 =		  LCBI0RES "
		 bit11 = 		  MLBB0RES "
		 bit12 = 		  SDRB0RES "
		 bit13 = 		  XC0RES "


**********************************************/
void MCU_vResetCtrl_ModuleCtrl(MCU_enModuleCtrlID CtrlType, uint32 u32ModuleMaskBit)
{

	uint32 u32SetValue=MCU_stResetCtrlAttribute.ResetCtrl->MRSTCtrl;
	
	//u32SetValue=*(uint32 *)&MCU_stResetCtrlAttribute.ModuleEnableCfg;
	if(CtrlType ==MCU_mModuleNotActive)
	{
		u32SetValue &=~u32ModuleMaskBit;
	}
	else
	{
		u32SetValue |=u32ModuleMaskBit;
	}
	
	DI();
	
	/*open write access to control INTC2*/
	*(volatile uint32 *)0xFFC4C000=0x7FFFFFF;

	do
	{
		MCU_stResetCtrlAttribute.ModuleReset_ProtectAddr->Commond=0xA5;
		MCU_stResetCtrlAttribute.ResetCtrl->MRSTCtrl=u32SetValue;
		MCU_stResetCtrlAttribute.ResetCtrl->MRSTCtrl=~u32SetValue;
		MCU_stResetCtrlAttribute.ResetCtrl->MRSTCtrl=u32SetValue;
	}
	while(MCU_stResetCtrlAttribute.ModuleReset_ProtectAddr->Status !=0ul);
	EI();
	
}

/*****************************************************************************
 Function  : MCU_u32GetResetReason												 
 Description   : get reset factor
 
 In Parameter: 
 			NULL
Return Value:
 			reset factor register value
 			
 NOTE: 	
 
!!!!!!!! only call this function once, then clear the reset factor!!!!!!!!!!!!!

the return value index the reset factor list follow:



*****************************************************************************/
uint32 MCU_u32GetResetReason(void)
{

	if(MCU_u32ResetReason ==0)
	{
		MCU_u32ResetReason=MCU_stResetCtrlAttribute.ResetCtrl->RESFactor;	
		MCU_stResetCtrlAttribute.ResetCtrl->RESFClean=0xC70F;
	}
	return  MCU_u32ResetReason;
}
	


/*****************************************************************************
 Function  : MCU_u16InterruptCtrl												 
 Description   : control the mask bit xxMK to enable or disable the interrupt_request
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u8IntEnable: enable or disable the interrupt_request, 1 is enable request
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint16 MCU_u16InterruptCtrl(MCU_enIsrID u16VectNum,uint8 u8IntEnable)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;
	
	
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}
	
	if(u8IntEnable)
	{
		pEIC->TB =1;/*-->yes, we using table mode as default*/
		pEIC->MK =0;
	}
	else
	{
		pEIC->MK =1;
	}
	
	return u16RetVal;
}

#if (MCU_mClearIF_Enable !=0u)
/*****************************************************************************
 Function  : MCU_u16InterruptFlagClean												 
 Description   : clean the interrupt_request flag
 
 In Parameter: 
 			u16VectNum: vector number to change
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
			IF is clean by hardware auto, so it is not need this function normal
*****************************************************************************/
uint16 MCU_u16InterruptFlagClean(MCU_enIsrID u16VectNum)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;

	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}
	
	pEIC->RF=0;

	return u16RetVal;
}
#endif


#if MCU_mINTPriorityChgEnable!=0u
/*****************************************************************************
 Function  : MCU_u16ChangeVectorPriority												 
 Description   : change a vector number interrupt priority
 
 In Parameter: 
 			u16VectNum: vector number to change
 			u16TargePri: new interrupt priority for u16VectNum
 			
Return Value:
 			u16RetVal: funciton execute resault
 			
 NOTE: 		
 			u16TargePri: 	0 ----->highest priority
 						15----->lowest priority
*****************************************************************************/
uint16 MCU_u16ChangeVectorPriority(MCU_enIsrID u16VectNum,uint16 u16TargePri)
{
	uint16 u16RetVal=DET_Err_NotErr;
	MCU_tstEIAttribute_Unint *pEIC;

	DET_ErrCheck(u16TargePri<MCU_mMaxVectorPrority , DET_Err_VectPriorityOutOfRange);
	DET_ErrCheck(u16VectNum< MCU_stInterruptCtrlAttribute.MaxVectorNumber, DET_Err_VectNumberOutOfRange);

	if(u16VectNum<=31)
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Hpro[u16VectNum];
	}
	else
	{
		pEIC=&MCU_stInterruptCtrlAttribute.EICtrl_Lpro[u16VectNum];
	}

	pEIC->PRO = u16TargePri;
	
	return u16RetVal;
	
}

#endif

#endif/*end of D1X*/

#if (MCU_mSackFunctionEnable!=0u)
/*****************************************************************************
 Function  : MCU_u32GetStackBottom												 
 Description   : Get the stack bottom address from linker
 
 In Parameter: 
 			NULL
 			
Return Value:
 			stack bottom address
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint32 MCU_u32GetStackBottom(void)
{
#pragma asm
  mov ___ghsend_stack,r10
#pragma endasm
}

/*****************************************************************************
 Function  : MCU_u32GetStackTop												 
 Description   : Get the stack top address from linker
 
 In Parameter: 
 			NULL
 			
Return Value:
 			stack top address
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint32 MCU_u32GetStackTop(void)
{
#pragma asm
  mov ___ghsbegin_stack,r10
#pragma endasm
}

/*****************************************************************************
 Function  : MCU_u32GetCurrentStack												 
 Description   : Get the Current running stack address from special-function-register[SP]
 
 In Parameter: 
 			NULL
 			
Return Value:
 			Current running stack address
 			
 NOTE: 		
			NULL
*****************************************************************************/
uint32 MCU_u32GetCurrentStack(void)
{
#pragma asm    
         mov     r3,r10
#pragma endasm        
}

#endif
/*****************************************************************************
 Function  : MCU_vWatchDogInit												 
 Description   :internal software watchdog setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			
*****************************************************************************/
static void MCU_vWatchDogInit(void)
{
	uint32 u32SetValue;

	/**********************************************
			watchdog 0 initial
	***********************************************/
	Debug_SetPin_WD(11, 4,1);
	Debug_SetPin_WD(11, 2,1);

	/*interval setting*/
	u32SetValue = (MCU_mResetTime_WD0 &7)<<4;

	/*75% interrupt disable*/
	u32SetValue |= (0<<3);

	/*mcu reset if overflow*/
	u32SetValue |= (1<<2);
	/*u32SetValue &= ~(1<<2);watch dog test*/
	
	/*100% window feed */
	u32SetValue |= (3<<0);

	/*setting the control value*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_0.MD = u32SetValue;

	/*start and clean the watchdog0*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_0.WDTE =0xAC  ;


	/**********************************************
			watchdog 1 initial
	***********************************************/

	/*interval setting*/
	u32SetValue = (MCU_mResetTime_WD1 &7) <<4;

	/*75% interrupt deisable*/
	u32SetValue |= (0<<3);

	/*mcu reset if overflow*/
	u32SetValue |= (1<<2);
	/*u32SetValue &= ~(1<<2);watch dog test*/
	
	/*100% window feed */
	u32SetValue |= (3<<0);

	/*setting the control value*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_1.MD = u32SetValue;

	/*start and clean the watchdog1*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_1.WDTE =0xAC ;
	
}


/*****************************************************************************
 Function  : MCU_vWatchDogClean												 
 Description   :clean internal software watchdog counter
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			it has done in asm in this serial chip
*****************************************************************************/
void MCU_vWatchDogClean(void)
{
	/*start and clean the watchdog0*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_0.WDTE =0xAC  ;
	
	/*start and clean the watchdog1*/
	MCU_stWatchDogAttribute.WDTAbasic_Addr->WDTA_1.WDTE =0xAC ;
}

/*****************************************************************************
 Function  : MCU_u16ClockInit												 
 Description   :clock setting initialization
 
 In Parameter: 
 			NULL
 			
Return Value:
 			DET_Err_NotErr
 			
 NOTE: 		
 			OPWDRUN: option byte watchdog control bits must set to start watchdog by software trigger(=0) !
 			OPWDVAC:  value must set to 0 for writting 0xAC to clear watchdog timer counter!
*****************************************************************************/
static uint16 MCU_u16ClockInit(void)
{

	MCU_stClockStatus.IntOscHS_FRH_Speed=MEGA(8);
	MCU_stClockStatus.IntOscLS_FRL_Speed=240000;
	MCU_stClockStatus.EMCLK_Speed=MCU_stClockStatus.IntOscHS_FRH_Speed;/*if fRH stop, it change to fRL*/

 	MCU_vClockInit_Basic();
	MCU_vClockInit_AWO();
	MCU_vClockInit_ISO();
	
	#if((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
	MCU_vClockInit_ExtISO();
	#endif

	#if (MCU_mClockMonitorEnable !=0u)
	MCU_vClockInit_ClockMonitor();
	#endif

	return DET_Err_NotErr;
	
}



/*****************************************************************************
 Function  : MCU_vNotExpINT												 
 Description   :one of the not-expected interrupt happen if this fucntion run
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt, it will halt system and reset MCU
*****************************************************************************/
void MCU_vNotExpINT(void)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
        u16RetVal+=1u;/*compiler warning*/
        #if _RH850_Debug !=0u
	do{}while(1u);
	#endif
}

/*****************************************************************************
 Function  : MCU_vNotExpINT_u8												 
 Description   :one of the not-expected interrupt happen if this fucntion run
 
 In Parameter: 
 			u8Dummy: a dummy data
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			this function ONLY run in interrupt, it will halt system and reset MCU
*****************************************************************************/
void MCU_vNotExpINT_u8(uint8 u8Dummy)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
	u8Dummy=0u;
        u8Dummy+=1u;/*compiler warning*/
        u16RetVal+=1u;/*compiler warning*/
        #if _RH850_Debug !=0u
	do{}while(1u);
	#endif
}

void MCU_vNotExpINT_u16(uint16 u16Dummy)
{
	uint16 u16RetVal=DET_Err_NotErr;
	DET_ErrReport(DET_Err_NotExpIntterupt);
	u16Dummy=0u;
        u16Dummy+=1u;/*compiler warning*/
        u16RetVal+=1u;/*compiler warning*/
	#if _RH850_Debug !=0u
	do{}while(1u);
	#endif

}


/*****************************************************************************
 Function  : MCU_vHWConfigCheck												 
 Description   :check the mainline download the HEX file currectly! it will halt if not
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vHWConfigCheck(void)
{
	/*check MCU option byte is OK or not
	if(MCU_au8OptionByteSetting[0u] != MCU_mOptByte0)
	{
		while(1u)
		{
			;
		}
	}*/
}

/*****************************************************************************
 Function  : MCU_vPortRelease												 
 Description   :release the pin for in/out enable
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
static void MCU_vPortRelease(void)
{
	MCU_vStandbyCtrl_IoHold(0);
}


/*****************************************************************************
 Function  : __low_level_init												 
 Description   :MCU low level init, this function called by _RH850_start.s26 file and run before main()
 			to initialiaztion the base hardware before C-pragma (main function entry)
 
 In Parameter: 
 			NULL
 			
Return Value:
 			always 1
 			if the return value is 0, MCU will not initial other RAM data, and it is wrong!!!
 			
 NOTE: 		
 			NULL
*****************************************************************************/
int __low_level_init(void)
{

#if MCU_Debug_ResetMonitor
	uint16 i=220;
	
	Debug_SetPin_Reset(11, 2,1);
	for(;i;i--)
	{
	}
	Debug_SetPin_Reset(11, 2,0);

#endif

	/*RAM data maybe clean if you set value here!*/
	return 1;
}

/********************************
	Import external APP layer interface
*********************************/

#if (_RH850_Debug !=0u)
	extern void MCU_vDebugMain(void);
#else
	extern void SYS_vMainLoop(void);
	extern void SYS_vPeripheralInit(void);
	
#endif

/*****************************************************************************
 Function  : main												 
 Description   : C pragma entry pionte, it will never return back
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			
		YES! I AM  AN AMAZING  BUG  AS YOU!
				_
			       :   `                     _..-=-=-=-.._.--.
			        `-._ ___,..-'" -~~`	~~~~  ~ >__')
			            `'"---'"`>>"'~~"~"~~>>'`
=====================```========```======== 
*****************************************************************************/
int main(void)
{

	Debug_SetPin_Reset(11, 2,1);
	DI();
	
	MCU_u16ClockInit();
	MCU_vWatchDogInit();
	MCU_vLowVoltDetectInit();
	MCU_vHWConfigCheck();
	
#if((MCU_UsingType > MCU_ID_RH850_D1L_Start)  && (MCU_UsingType<MCU_ID_RH850_D1M2H_End))
		MCU_vResetCtrl_ModuleCtrl(MCU_mModuleActive,\
			*(uint32 *)&MCU_stResetCtrlAttribute.ModuleEnableCfg);/*active the using module!!*/
#endif
	
	#if MCU_mPortModuleEnable !=0u
  	MCU_u16PortInit();
	#endif
		
	#if MCU_mPWGAModuleEnable!=0u
	MCU_u16PWGAinit();
	#endif
	
	#if MCU_mADCModuleEnable!=0u
	MCU_u16ADCinit();
	#endif
	
	#if MCU_mEINTModuleEnable!=0u
	MCU_u16EINTinit();
	#endif
	
	#if MCU_mIICModuleEnable!=0u
	MCU_u16IICinit();
	#endif

	#if (MCU_mCSIGModuleEnable!=0u)
	MCU_u16CSIGinit();
	#endif
	
	#if (MCU_mCSIHModuleEnable!=0u)
	MCU_u16CSIHinit();
	#endif

	#if MCU_mRLIN3UartModuleEnable !=0u
  	MCU_u16RLIN3Uart_Init();
  	#endif
  	
	#if ((MCU_mTAUBDModuleEnable!=0u) || (MCU_mTAUJModuleEnable!=0u))
	MCU_u16TAUxInit();
	#endif

	#if MCU_mDMAModuleEnable !=0u
	MCU_u16DMAinit();
	#endif	

	#if MCU_mOSTMModuleEnable !=0u
	MCU_u16OSTMinit();
	#endif	
	
	/*release pin status for enable control !*/
	MCU_vPortRelease();
	
	#if (MCU_mCPUModeCtrlEnable !=0u)
	/*enable wakeup detect!*/
	MCU_vStandbyCtrl_SetWakeUpFactor();
	#endif	

	#if (MCU_mFEinterruptEnable !=0u)
	MCU_u16InterruptInit_FE();
	#endif	

#if (_RH850_Debug !=0u)

	Debug_SetPin_Reset(11, 2,0);
	EI_Force();
	MCU_vDebugMain();
	
#else

	SYS_vPeripheralInit();
	EI_Force();
	SYS_vMainLoop();
	
#endif

	EI_Force();
while(1)
{
	MCU_vWatchDogClean();
}
//	MCU_vResetCtrl_Reset();

	return 0;
}


#endif/*end of this file*/

