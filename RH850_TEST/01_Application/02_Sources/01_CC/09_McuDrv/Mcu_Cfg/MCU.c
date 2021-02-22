/*******************************************************************************
| Module Name: MCU Drive configeration for upper layer
| File Name: MCU.c
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
| Tan Fumin                        Desay SV Automotive Co., Ltd
| 
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date             Ver        	Author               Description
| ----------  -------  -------------  -------------------------------------------------
| 2015.08.17  V0.01	Tan, fumin	:create this module
| 2015.11.22  V0.02	Tan, fumin	:Add the 78K0R hardware platform
| 2016.05.06  V0.03	Tan, fumin	:Add the RH850 hardware platform
| 2016.06.21  V0.04	Tan, fumin	:update MCU list macro
********************************************************************************/

#define MCU_C

#include "DET.h"
#include "MCU_CFG.h"

#if (MCU_UsingType >=MCU_ID_16FX_Start) && (MCU_UsingType<=MCU_ID_16FX_End)

	#if MCU_UsingType == MCU_ID_MB96690
		#include "../FFMC_16FX/16FX_Drv/_16FX_IO_690.c"
	#elif MCU_UsingType == MCU_ID_MB96670
		#include "../FFMC_16FX/16FX_Drv/_16FX_IO_670.c"
	#endif
		#include "../FFMC_16FX/16FX_Drv/_16FX_Vect.c"
		#include "../FFMC_16FX/16FX_UsrCfg/_16FX_UsrCfg.c"
		#include "../FFMC_16FX/16FX_Drv/_16FX.c"

#elif (MCU_UsingType >=MCU_ID_78K0R_Start) && (MCU_UsingType<=MCU_ID_78K0R_End)

	#if MCU_UsingType == MCU_ID_78K0R_FG3
		#include "../78K0R/78K0R_Drv/_78K0R_FG3.c"
	#elif MCU_UsingType == MCU_ID_78K0R_FE3
		#include "../78K0R/78K0R_Drv/_78K0R_FE3.c"
	#endif
		#include "../78K0R/78K0R_Drv/_78K0R_Vect.c"
		#include "../78K0R/78K0R_UsrCfg/_78K0R_UsrCfg.c"
		#include "../78K0R/78K0R_Drv/_78K0R.c"

#elif (MCU_UsingType >=MCU_ID_RH850_Start) && (MCU_UsingType<=MCU_ID_RH850_End)

				
	#if ((MCU_UsingType >=MCU_ID_RH850_F1L_Start) &&	(MCU_UsingType<=MCU_ID_RH850_F1L_End))

		
		#if (_RH850_Debug != 0u)
			#include "../RH850/F1L_UsrCfg/_F1L_Debug.c"
		#else
			#include "../RH850/F1L_UsrCfg/_F1L_UsrCfg.c"
		#endif
		
		#include "../RH850/RH850_Drv/_F1L.c"
		#include "../RH850/RH850_Drv/_RH850.c"
		#include "../RH850/RH850_Drv/_F1L_Vector.c"
		#include "../RH850/RH850_Drv/_F1L_StartUp.c"
		
	#endif
		
	#if ((MCU_UsingType >=MCU_ID_RH850_D1L_Start) && (MCU_UsingType<=MCU_ID_RH850_D1M2H_End))

		
		#if (_RH850_Debug != 0u)
			#include "../RH850/D1X_UsrCfg/_D1X_Debug.c"
		#else
			#include "../RH850/D1X_UsrCfg/_D1X_UsrCfg.c"
		#endif
		
		#include "../RH850/RH850_Drv/_D1X.c"
		#include "../RH850/RH850_Drv/_RH850.c"
		#include "../RH850/RH850_Drv/_D1X_Vector.c"
		#include "../RH850/RH850_Drv/_D1X_StartUp.c"
		
	#endif
		
		
#else
		#error "THE MCU TYPE NOT SUPPORT!!!!!!!!!!!!!!!!!!!!!".
	
#endif


