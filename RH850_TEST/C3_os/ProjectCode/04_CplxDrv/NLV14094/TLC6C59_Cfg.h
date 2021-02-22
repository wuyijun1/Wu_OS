/***************************************************************************************************
                                TLC6C59 LED DRIVER                                
                                        
  .File Name  : TLC6C59_Cfg.h
  
  .Description: This file is used for TLC6C59 LED driver.
  
  --------------------------------------------------------------------------------------------------
    Version     Date        Author          Change
  --------------------------------------------------------------------------------------------------
    V001        2017-01-10  Chen Xiongzhi   - Creat this module.
***************************************************************************************************/

#ifndef TLC6C59_CFG_H
#define TLC6C59_CFG_H


   									
#define Led_Group1TransferData(OutDataHead,RecDataHead)     SPI_u16SlaveSelect_CH2(1,0);\
														    SPI_u16TransferData_CH2(OutDataHead,RecDataHead,1);\
														    SPI_u16SlaveSelect_CH2(1,1)

#define Led_Group2TransferData(OutDataHead,RecDataHead)     SPI_u16SlaveSelect_CH3(1,0);\
														    SPI_u16TransferData_CH3(OutDataHead,RecDataHead,1);\
														    SPI_u16SlaveSelect_CH3(1,1)


#define LED_nTelltaleGroup1Channel   (37U)
#define LED_nTelltaleGroup2Channel   (47U)

#define LED_vHalPwmSetDuty(Channel, Duty)               {PWD_SetDuty(Channel,Duty);}
#define LED_vHalPwmInit(Channel, Duty)                  {PWD_Init(Channel,Duty);PWD_Cmd(Channel,ENABLE/*True*/);}

#define LED_u16GetTelltaleValue                         DIM_u16GetValue(DIM_nu16TelltaleGroup)
#define LED_u16GetGroup1Duty                            DIM_u16GetValue(DIM_nu16TelltalePwm5Duty)
#define LED_u16GetGroup2Duty                            DIM_u16GetValue(DIM_nu16TelltalePwm5Duty)

#endif


