/*******************************************************************************
| Module Name: L9301
| File Name: L9301.c
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
| 2017.03.13  V0.01	Tan, fumin	:create this module
********************************************************************************/
#include "L9301.h"

extern const L9301_CR_Map L9301_UsrCfg;
L9301_RegisterMap L9301_Reg;
L9301_DrvSatusCtrl L9301_DrvManage ;

void L9301_vOutPutEnCtrl(uint8 u8Enable);
void L9301_vResetPinCtrl(uint8 u8PinLevel);
void L9301_vCSPinCtrl(uint8 u8PinLevel);
void L9301_vSPI_Init(void);
uint16 L9301_u16OUTxErrProccess(L9301_ChnID channel, L9301_ChnError u32ErrInfo);
uint16 L9301_u16VoltageErrProccess(L9301_VoltageError u32ErrInfo);
uint16 L9301_u16SPI_SendOutData(void *pOutDataHead, void *pRecDataHead,uint16 u16DataLen);

#define WORD_LEN 32UL
#define CRC_LEN 3UL
#define CRC_POLY 0x0FU /*L9301 CRC Poly:x^3+x^2+x+1*/
#define CRC_INIT_MASK (CRC_POLY<<(WORD_LEN-CRC_LEN-1))
#define FIRST_BIT_MASK (1<<(WORD_LEN-1))  // 0x80000000
#define CRC_LOWER_MASK ((1<<(CRC_LEN))-1) //0b111

/*****************************************************************************
 Function  : L9301_u32CrcCompute												 
 Description   :compute the L9301 CRC code
 
 In Parameter: 
 			InputWord: data source, which data send to L9301, [high 29bits] + [3bits 0]

Return Value:
 			LeftAlignedWordCopy: final data with [29bits source] + [3bits CRC]
 			
 NOTE: 		
 			NULL
*****************************************************************************/
uint32 L9301_u32CrcCompute(uint32 InputWord)
{
	uint32 TestBitMask ;
	uint32 CRCMask ;
	uint32 BitCount ;
	uint32 LeftAlignedWord ;
	uint32 LeftAlignedWordCopy ;


        /*masked lowest 3ibts*/
	LeftAlignedWord = InputWord& (~CRC_LOWER_MASK);
	LeftAlignedWordCopy = LeftAlignedWord ;

	TestBitMask = ( 1 << ( WORD_LEN - 1 ) ) ; 
	CRCMask = CRC_INIT_MASK ; 
	BitCount = ( WORD_LEN - CRC_LEN ) ;
	
	while ( 0 != BitCount-- ) 
	{
		if ( 0 != ( LeftAlignedWord & TestBitMask ) ) 
		{
			LeftAlignedWord ^= CRCMask ;
		} 
		
		CRCMask >>= 1 ;
		TestBitMask >>= 1 ;
	}

	LeftAlignedWord &= CRC_LOWER_MASK ;

	LeftAlignedWordCopy=( LeftAlignedWordCopy | LeftAlignedWord ) ;
	 
	 return LeftAlignedWordCopy;

}

/*****************************************************************************
 Function  : L9301_u16UpdateSatus												 
 Description   :control the OutX level by SPI command or INx pins
 
 In Parameter: 
 			u32ExpectValue: OutX level mask, one bit = one channel OutX

Return Value:
 			u32Res: chip feed back resault
 			
 NOTE: 		
 			truthly contorl L9301 Outx interface!!
*****************************************************************************/
static uint32 L9301_u32UpdateSatus(uint32 u32ExpectValue)
{

	uint32 u32SPI_Value,u32INx_Value;
	uint32 u32Res=0;
	
	/*only update the status in the condition that driver is in ready !!!*/
	if(L9301_DrvManage.DrvSatus ==L9301_Ready)
	{
		u32SPI_Value = u32ExpectValue& (~L9301_UsrCfg.PinCtrlMode);
		u32INx_Value = u32ExpectValue& (L9301_UsrCfg.PinCtrlMode);


		/*Update value by SPI*/
		L9301_WriteCmdMerge(L9301_CMD_CR0D,u32SPI_Value,u32SPI_Value);
		u32Res=L9301_u16SPI_SendOutData(&u32SPI_Value,&u32Res,4);
		
                 L9301_Reg.Table[L9301_CMD_CR0D]=u32Res;
                    
		/*Update value by INx-->
			u32ExpectValue bit0 = Out0*/
		if(L9301_UsrCfg.PinCtrlMode & (1<<0))/*INx_1*/
		{
			L9301_IN1_PinCtrl((u32INx_Value>>0) &1);
		}

		if(L9301_UsrCfg.PinCtrlMode & (1<<1))/*INx_2*/
		{
			L9301_IN2_PinCtrl((u32INx_Value>>1) &1);
		}

		if(L9301_UsrCfg.PinCtrlMode & (1<<2))/*INx_3*/
		{
			L9301_IN3_PinCtrl((u32INx_Value>>2) &1);
		}

		if(L9301_UsrCfg.PinCtrlMode & (1<<3))/*INx_4*/
		{
			L9301_IN4_PinCtrl((u32INx_Value>>3) &1);
		}
		
		if(L9301_UsrCfg.PinCtrlMode & (1<<4))/*INx_5*/
		{
			L9301_IN5_PinCtrl((u32INx_Value>>4) &1);
		}
		
		if(L9301_UsrCfg.PinCtrlMode & (1<<5))/*INx_6*/
		{
			L9301_IN6_PinCtrl((u32INx_Value>>5) &1);
		}
		
		if(L9301_UsrCfg.PinCtrlMode & (1<<6))/*INx_7*/
		{
			L9301_IN7_PinCtrl((u32INx_Value>>6) &1);
		}
		
		if(L9301_UsrCfg.PinCtrlMode & (1<<7))/*INx_8*/
		{
			L9301_IN8_PinCtrl((u32INx_Value>>7) &1);
		}
		
	}

	return u32Res;
	
}

/*****************************************************************************
 Function  : L9301_u16SetOutputValue												 
 Description   :update the expected OutX level, 
 
 In Parameter: 
 			u32ExpectValue: OutX level mask, one bit = one channel OutX

Return Value:
 			u16Res: SPI resault
 			
 NOTE: 		
 			it record the expected setting into paramemter but not update immediately,
 			it ONLY update in the function L9301_u16UpdateSatus
 			
*****************************************************************************/
uint16 L9301_u16SetOutputValue(L9301_ChnID Ch, uint8 u8ExpectedLevel)
{

        uint16 u16Ret=0;

	if((Ch>=L9301_OutputChn_LS1)&&(Ch<=L9301_OutputChn_HS4))
	{
		if(u8ExpectedLevel !=0)
		{
		        L9301_DrvManage.ExpOutX_Level |=1<<Ch;
		}
		else
		{
		        L9301_DrvManage.ExpOutX_Level &=~(1<<Ch);
		}
	}
	else
	{
	    u16Ret=1;
	}

	return u16Ret;
	
}


/*****************************************************************************
 Function  : L9301_u32SatusInquire												 
 Description   :L9301 status check,
 
 In Parameter: 
 			Ch: L9301 register index

Return Value:
 			u32ReceiveData: register value
 			
 NOTE: 		
 			Null
*****************************************************************************/
uint32 L9301_u32SatusInquire(L9301_RegisterMapList Ch)
{
	L9301_RegisterNormalType_MOSI InquireCmd;
	uint32 u32ReceiveData=0;

	L9301_ReadCmdMerge(Ch,InquireCmd.Dword);
	L9301_u16SPI_SendOutData(&InquireCmd.Dword,&u32ReceiveData,4);

	return u32ReceiveData;
}

/*****************************************************************************
 Function  : L9301_vReset												 
 Description   :L9301 reset frame,
 
 In Parameter: 
 			Null

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vReset(void)
{
	/*set RES pin to high for chip self-test, it will need 11ms to finish!!*/
	L9301_vResetPinCtrl(1);
	L9301_vOutPutEnCtrl(0);
	
	/*SPI set to non-active*/
	L9301_vCSPinCtrl(1);

	/*SPI init*/
	L9301_vSPI_Init();

}

/*****************************************************************************
 Function  : L9301_vInit												 
 Description   :L9301 initialization frame,
 
 In Parameter: 
 			Null

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vInit(void)
{
	uint16 u16DataLen;
	L9301_RegisterNormalType_MOSI Cmd;
	uint32 *pUsrCfg=(uint32 *)&L9301_UsrCfg.CR_0x00,u32Dummy;

	/*set ResetPin High and OutputEnable Pin Low befor Init()*/
	L9301_vResetPinCtrl(1);
	L9301_vOutPutEnCtrl(0);
	
	/*check SR_0x1E for self-test resault*/
	L9301_Reg.Table[L9301_BIST]=L9301_u32SatusInquire(L9301_BIST);

	/*chip self-test finish and pass*/
	if((L9301_Reg.Table[L9301_BIST] & 0x18) ==0x18)
	{
		L9301_DrvManage.DrvSatus =L9301_Ready;

		/*update the user configeration to chip~~~~~~~~~*/
		for(u16DataLen=0;u16DataLen<0x0f;u16DataLen++)
		{
			if(u16DataLen==L9301_CMD_CR0D/*cmd Pin output level*/)
			{
		                /*BitValue = 0 is control by SPI, so update the OutX level by SPI*/
			       Cmd.Dword=(*pUsrCfg)& (~L9301_UsrCfg.PinCtrlMode);
			}
			else
			{
				Cmd.Dword=(*pUsrCfg);/*update register value directly*/
			}

			L9301_Reg.Table[u16DataLen]=Cmd.Dword;
		         L9301_WriteCmdMerge(u16DataLen,Cmd.Dword,Cmd.Dword);
		         L9301_u16SPI_SendOutData(&Cmd.Dword,&u32Dummy,4);

		         /*piont to next usrcfg*/
		         pUsrCfg++;
		         
		}

		/*record the usrcfg of OutX control type!*/
		L9301_Reg.Table[0x0f]=L9301_UsrCfg.PinCtrlMode;
		
		/*then enable output OutX*/
		L9301_vOutPutEnCtrl(1);
		
	}
	
}

/*****************************************************************************
 Function  : L9301_vDeinit												 
 Description   :L9301 De-initialization frame,
 
 In Parameter: 
 			Null

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vDeinit(void)
{
	/*OutX output disable, then default value is all 0*/
	L9301_vOutPutEnCtrl(0);
	
	/*SPI set to non-active*/
	L9301_vCSPinCtrl(1);

}


/*****************************************************************************
 Function  : L9301_vMain												 
 Description   :L9301 Main frame,
 
 In Parameter: 
 			Null

Return Value:
 			Null
 			
 NOTE: 		
 			Null
*****************************************************************************/
void L9301_vMain(void)
{

	L9301_RegisterNormalType_MISO ChnStatus;
	L9301_RegisterNormalType_MOSI UpdateStatus;
        uint32 *pUsrCfg=(uint32 *)&L9301_UsrCfg.CR_0x01_0x0C,u16ChnCheck;
	
	/*if Init() is not finish, then re-init agian*/
	if(L9301_DrvManage.DrvSatus ==L9301_NotInit)
	{
		L9301_vInit();
	}
	else
	{		        
		/*check channel is Error or not*/
		L9301_Reg.Table[L9301_GeneralSatus_SR10]=L9301_u32SatusInquire(L9301_GeneralSatus_SR10);
                 ChnStatus.Dword=L9301_Reg.Table[L9301_GeneralSatus_SR10];
                 
                /*VDD or VB voltage error~~~~*/
                if((ChnStatus.Bit.DATA & 0x0F)!=0)
                {
                            /*Clear VDD/VB Error~~~~*/
                            L9301_WriteCmdMerge(L9301_GeneralSatus_SR10,0,UpdateStatus.Dword);
                            L9301_u16SPI_SendOutData(&UpdateStatus.Dword,&UpdateStatus.Dword,4);

                            if(L9301_u16VoltageErrProccess((L9301_VoltageError)((ChnStatus.Dword & (0x0F<<3))>>3)/*Mask for Voltage Err bits*/)==0)
                            {
                                    /*disable OUTx if supply voltage is error*/
                                    L9301_vOutPutEnCtrl(0);
                            }
                            else
                            {
                                     L9301_vOutPutEnCtrl(1);
                            }
                }

              		
               if((ChnStatus.Bit.DATA & (1<<6)/*gf bit*/)!=0)
               {
                    /*some channel error, may Over-current, shut-cut error ect....find out the error channel*/
                    for(u16ChnCheck=L9301_LS1_SR11;u16ChnCheck<=L9301_HS4_SR1C;u16ChnCheck++,pUsrCfg++)
                    {
                    
                        L9301_Reg.Table[u16ChnCheck]=L9301_u32SatusInquire(u16ChnCheck);
                        ChnStatus.Dword=L9301_Reg.Table[u16ChnCheck];

                       
            		/*feedback data field, check the error bit to clear it ~~~~*/
            		if((ChnStatus.Bit.DATA &(0x7e))!=0)
    		        {
    			      /*disable CR bit test*/
                                L9301_WriteCmdMerge(u16ChnCheck-L9301_GeneralSatus_SR10,(*pUsrCfg>>3/*not CRC*/) | (0x60),UpdateStatus.Dword);
                                L9301_u16SPI_SendOutData(&UpdateStatus.Dword,&UpdateStatus.Dword,4);
   			          
    			      /*clear SR error bits*/
                                L9301_WriteCmdMerge(u16ChnCheck,0,UpdateStatus.Dword);
                                L9301_u16SPI_SendOutData(&UpdateStatus.Dword,&UpdateStatus.Dword,4);
                                

    			      /*enable CR bit test*/
                                L9301_WriteCmdMerge(u16ChnCheck-L9301_GeneralSatus_SR10,(*pUsrCfg>>3/*not CRC*/),UpdateStatus.Dword);
                                L9301_u16SPI_SendOutData(&UpdateStatus.Dword,&UpdateStatus.Dword,4);


            	             /*Error proccess for OUTx channel*/
            		     L9301_u16OUTxErrProccess(u16ChnCheck-L9301_LS1_SR11,(L9301_ChnError)((ChnStatus.Dword&(0x7e<<3))>>3)/*Mask for chn Err bits*/);

    			     /*record error channel*/
                               L9301_DrvManage.ChannelErrMask |=1<<(u16ChnCheck-L9301_LS1_SR11);
    				
    		        } 
    		        else
    		        {
       			        /*clear error channel*/
                                 L9301_DrvManage.ChannelErrMask &=~(1<<(u16ChnCheck-L9301_LS1_SR11));
    		        }
            		
                }
                    
        }

	/*update terminal OutX level by INx or SPI_Bits*/
        L9301_u32UpdateSatus(L9301_DrvManage.ExpOutX_Level);
        
    }

  
}

