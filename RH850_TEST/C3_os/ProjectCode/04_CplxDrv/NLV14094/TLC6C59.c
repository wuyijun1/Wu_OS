/***************************************************************************************************
                                TLC6C59 LED DRIVER                                
                                        
  .File Name  : TLC6C59.c
  
  .Description: This file is used for TLC6C59 LED driver.
  
  --------------------------------------------------------------------------------------------------
    Version     Date        Author          Change
  --------------------------------------------------------------------------------------------------
    V001        2017-01-10  Chen Xiongzhi   - Creat this module.
***************************************************************************************************/

#include "TLC6C59.h"
#include "HAL.h"
#include "DIM.h"

uint8 LedDrv_stSendInfo[1];
uint8 LedDrv_stReceiveInfo[1];


void TLC6C59_vReset(void)
{
    LedDrv_stSendInfo[0] = 0x00U;  
    
    LED_vHalPwmInit(LED_nTelltaleGroup1Channel, 0);   
	SPI_vDrvInit_CH2();
	Led_Group1TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);


	SPI_vDrvInit_CH3();
	Led_Group2TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);
    LED_vHalPwmInit(LED_nTelltaleGroup2Channel, 0);   
}

void TLC6C59_vInit(void)
{
	//Led_Group1TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);
    //LED_vHalPwmSetDuty(LED_nTelltaleGroup1Channel, 0);  

	//Led_Group2TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);
    //LED_vHalPwmSetDuty(LED_nTelltaleGroup2Channel, 0);      
}

void TLC6C59_vDeinit(void)
{


}


void TLC6C59_vMain(void)
{
    uint16 u16TelltaleValue;
    uint8 u8Group1Duty, u8Group2Duty;
    
    u16TelltaleValue = LED_u16GetTelltaleValue;
    u8Group1Duty = (uint8)LED_u16GetGroup1Duty;
    u8Group2Duty = (uint8)LED_u16GetGroup1Duty;
    

    LedDrv_stSendInfo[0] = (uint8)u16TelltaleValue;
    Led_Group1TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);
    LED_vHalPwmSetDuty(LED_nTelltaleGroup1Channel, u8Group1Duty);  

    LedDrv_stSendInfo[0] = (uint8)(u16TelltaleValue>>8u);
    Led_Group2TransferData(LedDrv_stSendInfo, LedDrv_stReceiveInfo);   
    LED_vHalPwmSetDuty(LED_nTelltaleGroup2Channel, u8Group2Duty); 
}




