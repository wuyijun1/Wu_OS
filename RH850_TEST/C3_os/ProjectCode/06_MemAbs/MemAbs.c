/*******************************************************************************
| Module Name: Memory Hardware Abstraction module
| File Name: MemAbs.c
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
| 2017.01.11  V0.01	Tan, fumin	:create this module
********************************************************************************/

MemAbs_tstMemRequestList MemAbs_stMemRequestList[MemAbs_MemoryTypes];
uint32 MemAbs_u32CurDeviceAddr[MemAbs_MemOperat_Max];

void MemAbs_vGetMemInfo(MemAbs_enOperationReqType ReqType,MemAbs_tstMemMapping *MemInfo)
{
	uint16 Index;

	for(Index =0;Index<MemAbs_MemOperat_Max ;Index++)
	{
		if(MemAbs_stMemMapping[Index].OperatReqType==ReqType)
		{
			*MemInfo = MemAbs_stMemMapping[Index];
			break;
		}
	}

	DET_ErrCheck(Index<MemAbs_MemOperat_Max, DET_Err_MemOpTypeOutOfRange);

}


void MemAbs_vInit(void)
{
	uint16 Index;
	uint32 u32PiontAddre,MemoryType,UnitSize,u32StartAddre,TotalSize;

	/*call the initialization function first~~*/
	for(Index =0;Index<MemAbs_MemoryTypes ;Index++)
	{
		MemDeviceIf[Index].Open(0u);
	}
	
	/*find out the last free memory address in pending-type or overwrite type*/
	for(Index =0;Index<MemAbs_MemOperat_Max ;Index++)
	{
		/*pending addr*/
		if(MemAbs_stMemMapping[Index].Pending !=0)
		{
			MemoryType = MemAbs_stMemMapping[Index].MemType;
			UnitSize =  MemAbs_stMemMapping[Index].UnitSize;
			u32StartAddre =MemAbs_stMemMapping[Index].PhysicalStartAddr;
			TotalSize =  MemAbs_stMemMapping[Index].MapLenth;
			
			/*find out the last pending address*/
			for(u32PiontAddre=u32StartAddre;u32PiontAddre<(u32StartAddre + TotalSize);u32PiontAddre +=UnitSize)
			{
				/*should it need wait initialization time after init(); ????????*/
				if(MemDeviceIf[MemoryType].DevBlankCheck(u32PiontAddre,UnitSize) == 1)/*data is not writen, data fill is OK*/
				{
					/*last unit writen data address set~~*/
					MemAbs_u32CurDeviceAddr[Index] = u32PiontAddre;		
					break;
				}
				
			}
			
			if(u32PiontAddre >= (u32StartAddre + TotalSize))
			{
				MemAbs_u32CurDeviceAddr[Index] = (u32StartAddre + TotalSize);
			}
			
			DET_ErrCheck((MemAbs_u32CurDeviceAddr[Index] >=u32StartAddre && \
					MemAbs_u32CurDeviceAddr[Index]<=(u32StartAddre + TotalSize)), DET_Err_MemDevAddrOutOfRange);

		}
		/*overwrite addr*/
		else
		{
			MemAbs_u32CurDeviceAddr[Index] = MemAbs_stMemMapping[Index].PhysicalStartAddr;
		}
	}

}

#define ExtEEP_Read
#define ExtEEP_Write

#define ExtFlash_Read
#define ExtFlash_Write

void MemAbs_vDeInit(void)
{

}

uint16 MemAbs_u16Read(MemAbs_enOperationReqType ReqType, void *RecDataHead, uint16 u16DataLen)
{
	uint16 u16Index;
	MemAbs_tstMemMapping MemInfo;

	/*get memory mapping info*/
	MemAbs_vGetMemInfo(&MemInfo);
	DET_ErrCheck(u16DataLen<=MemAbs_stMemMapping[MemInfo.OperatReqType].MapLenth, DET_Err_MemDataLenOutOfRange);
	
	if()
	{
	
	}
	
	
	 
}

uint16 MemAbs_u16Write(MemAbs_enOperationReqType ReqType, void *FromDataHead, uint16 u16DataLen)
{
	uint16 u16Index;
	MemAbs_tstMemMapping MemInfo;

	/*get memory mapping info*/
	MemAbs_vGetMemInfo(&MemInfo);
	
	/*roll using type*/
	if(MemInfo.Pending !=0)
	{

	}
	/*over write type*/
	else
	{
		/*check the request list is full or not*/
		if((MemAbs_stMemRequestList[MemInfo.MemType].u16InIndex -\
				MemAbs_stMemRequestList[MemInfo.MemType].u16OutIndex )<MemAbs_MaxMemOperReq)
		{
		
			u16Index = MemAbs_stMemRequestList[MemInfo.MemType].u16InIndex++;
			
			MemAbs_stMemRequestList[MemInfo.MemType].Request[u16Index].DevOperatReq=MemAbs_DeviceOperat_Write;
			MemAbs_stMemRequestList[MemInfo.MemType].Request[u16Index].RamAddr=FromDataHead;
			MemAbs_stMemRequestList[MemInfo.MemType].Request[u16Index].DataLen_Byte=u16DataLen; 
			MemAbs_stMemRequestList[MemInfo.MemType].Request[u16Index].DeviceAddr=MemInfo.PhysicalStartAddr;

			/*trigger the task to run here if need*/
			
		}
		else
		{
			/*request queue is full~~*/
		}
	
	}
	
	
	 
}


uint16 MemAbs_u16ReqInject(MemAbs_enOperationReqType ReqType, void *DataHead, uint16 u16DataLen)
{

}

void MemAbs_vTask(void)/*handle ~~~*/
{

}














