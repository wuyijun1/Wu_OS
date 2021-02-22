/*******************************************************************************
| Module Name: DC Motor driver model
| File Name: PCA8539.c
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

#include "./PCA8539.h"



extern PCA8539_UsrCfg PCA8539_Cfg;
uint8 PCA8539_u8InitStep;
uint8 PCA8593_BUF[200];

/*
uint8 BitMap_Buff[LCD_Y_LEN][LCD_X_LEN];
uint8 LCDMap_Buff[LCD_Y_LEN][LCD_X_LEN];
*/


/*****************************************************************************
 Function  : PCA8539_vDvrInit												 
 Description   :PCA8539 init
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void PCA8539_vDvrInit(void)
{
	PCA8539_vIIC_Init();
	PCA8539_vDvrInit_P1();
	
	/*part 2~~4 will finish in callback function*/
}

void PCA8539_vDvrInit_P1(void)
{
	uint8 Index=0;
	PCA8539_u8InitStep++;
	PCA8593_BUF[Index++]=(PCA8539_Cfg.u8SlaveAddr<<1)+0;/*IIC wrtie commond*/

/*#################################################################################*/	
	/*Comond 1, init driver*/
	PCA8593_BUF[Index++]=CO_DataByte|RS_0;	/*comond index byte,RS=0*/
	PCA8593_BUF[Index++]=DevCtrl_Init;	/*comond index byte*/
	
	/*Comond 2, Clear reset flag*/
	PCA8593_BUF[Index++]=DevCtrl_ClrRstFlg;	/*comond index byte*/

	/*Comond 3, OTP re-fresh*/
	PCA8593_BUF[Index++]=DevCtrl_OTP_Refresh;	/*comond index byte*/

	/*Comond 4, OTP re-fresh*/
	PCA8593_BUF[Index++]=DevCtrl_Clk_Out_Ctrl(0);	/*comond index byte*/
	
	/*Comond 5, Graphic mode conf*/
	PCA8593_BUF[Index++]=DevCtrl_Graphic_Mode_Cfg(PCA8539_Cfg.u8MultiplexNum);	/*comond index byte*/

	/*Comond 6, Set bank*/
	PCA8593_BUF[Index++]=DevCtrl_Sel_Mem_bank(1);	/*comond index byte*/
	
	/*Comond 6, Set driver addr to 0*/
	PCA8593_BUF[Index++]=DevCtrl_Set_Mem_addr(0);	/*comond index byte*/

	PCA8539_vStartCondition();
	PCA8539_vDataSendOut(PCA8593_BUF, Index);

}

void PCA8539_vDvrInit_P2(void)
{
	uint8 Index=0;
	
	PCA8539_u8InitStep++;
	
	PCA8593_BUF[Index++]=(PCA8539_Cfg.u8SlaveAddr<<1)+0;/*IIC wrtie commond*/
	
	/*#################################################################################*/	
	/*Comond 7, Set driver addr increase*/
	PCA8593_BUF[Index++]=CO_DataByte|RS_2;	/*comond index byte,RS=2*/
	PCA8593_BUF[Index++]=DisCtrl_Entry_mode_set(1);	/*comond index byte*/

	/*Comond 8, Set driver invese mode*/
	PCA8593_BUF[Index++]=DisCtrl_Inversion_mode(PCA8539_Cfg.u8LineInv);	/*comond index byte*/

	/*Comond 9, Set driver refresh frequency*/
	PCA8593_BUF[Index++]=DisCtrl_Frame_frequency(PCA8539_Cfg.u8LCDFrequency);	/*comond index byte*/

	/*Comond 10, Set segment data dispaly form 0 to 99*/
	PCA8593_BUF[Index++]=DisCtrl_Display_config(0);	/*comond index byte*/

	
	PCA8539_vStartCondition();
	PCA8539_vDataSendOut(PCA8593_BUF, Index);

}

void PCA8539_vDvrInit_P3(void)
{
	uint8 Index=0;
	
	PCA8539_u8InitStep++;
	
	PCA8593_BUF[Index++]=(PCA8539_Cfg.u8SlaveAddr<<1)+0;/*IIC wrtie commond*/
	
/*#################################################################################*/	
	/*Comond 11, Set segment data dispaly form 0 to 99*/
	PCA8593_BUF[Index++]=CO_DataByte|RS_3;	/*comond index byte,RS=3*/
	PCA8593_BUF[Index++]=DevCtrl_Temperature_ctrl(PCA8539_Cfg.u8TemperatureSet);	/*comond index byte*/

	/*Comond 12, Set TSx*/
	PCA8593_BUF[Index++]=DevCtrl_TC_slope_TSA(PCA8539_Cfg.u8TSA);	/*comond index byte*/
	PCA8593_BUF[Index++]=DevCtrl_TC_slope_TSB(PCA8539_Cfg.u8TSB);	/*comond index byte*/
	PCA8593_BUF[Index++]=DevCtrl_TC_slope_TSC(PCA8539_Cfg.u8TSC);	/*comond index byte*/
	PCA8593_BUF[Index++]=DevCtrl_TC_slope_TSD(PCA8539_Cfg.u8TSD);	/*comond index byte*/

	/*Comond 13, Set EV value*/
	PCA8593_BUF[Index++]=DevCtrl_Set_VLCD_Msb(PCA8539_Cfg.u8EVvalue>>4);	/*comond index byte*/
	PCA8593_BUF[Index++]=DevCtrl_Set_VLCD_Lsb(PCA8539_Cfg.u8EVvalue&0x0f);	/*comond index byte*/

	/*Comond 14, Set Pumb ctrl*/
	PCA8593_BUF[Index++]=DevCtrl_Charge_pump_ctrl(PCA8539_Cfg.u8ChargeCtrl);	/*comond index byte*/

	PCA8539_vStartCondition();
	PCA8539_vDataSendOut(PCA8593_BUF, Index);

}

void PCA8539_vDvrInit_P4(void)
{
	uint8 Index=0;
	
	PCA8539_u8InitStep++;
	
	PCA8593_BUF[Index++]=(PCA8539_Cfg.u8SlaveAddr<<1)+0;/*IIC wrtie commond*/
	
/*#################################################################################*/	
	/*Comond 11, Set segment data dispaly from 0 to 99*/
	PCA8593_BUF[Index++]=CO_DataByte|RS_2;	/*comond index byte,RS=3*/
	PCA8593_BUF[Index++]=DisCtrl_Display_control(1);	
	
	PCA8539_vStartCondition();
	PCA8539_vDataSendOut(PCA8593_BUF, Index);
}

/*****************************************************************************
 Function  : PCA8539_vShutdown												 
 Description   :PCA8539 shutdown
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void PCA8539_vShutdown(void)
{
	PCA8539_u8InitStep=0;
}

/*****************************************************************************
 Function  : PCA8539_vExit												 
 Description   :PCA8539 exit
 
 In Parameter: 
 			NULL
 			
Return Value:
 			NULL
 			
 NOTE: 		
 			NULL
*****************************************************************************/
void PCA8539_vDrvExit(void)
{
	PCA8539_u8InitStep=0;
}



void PCA8539_vDisplayUpdate(uint8 u8RAMbank,uint8 u8RAWaddr,uint8 *u8DispalyRAM,uint8 dataLen)
{
	uint8 Index=0,u8Loop;

	PCA8593_BUF[Index++]=(PCA8539_Cfg.u8SlaveAddr<<1)+0;/*IIC wrtie commond*/
			
/*#################################################################################*/	
	/*Comond 1, set bank*/
	PCA8593_BUF[Index++]=CO_CtrlByte|RS_0;	/*comond index byte,RS=3*/
	PCA8593_BUF[Index++]=DevCtrl_Sel_Mem_bank(u8RAMbank);	/*comond index byte*/

/*#################################################################################*/	
	/*Comond 2, set address*/
	PCA8593_BUF[Index++]=CO_CtrlByte|RS_0;	/*comond index byte,RS=0*/
	PCA8593_BUF[Index++]=DevCtrl_Set_Mem_addr(u8RAWaddr);	/*comond index byte*/
	
	PCA8593_BUF[Index++]=CO_DataByte|RS_1;	/*comond index byte,RS=3*/

/*#################################################################################*/	
	for(u8Loop=0;u8Loop<dataLen;u8Loop++)
	{
		PCA8593_BUF[Index++]=u8DispalyRAM[u8Loop]  /*& 0x1F*/;
	}
	
	PCA8539_vStartCondition();
	PCA8539_vDataSendOut(PCA8593_BUF, Index);

}




