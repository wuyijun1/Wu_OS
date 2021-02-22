/*******************************************************************************
| Module Name: MCU Drive configeration for upper layer
| File Name: MCU_CFG.h
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
| 2015.11.17  V0.01	Tan, fumin	:create this module
| 2015.11.22  V0.02	Tan, fumin	:Add the 78K0R hardware platform
| 2016.05.06  V0.03	Tan, fumin	:Add the RH850 hardware platform
| 2016.06.21  V0.04	Tan, fumin	:update MCU list macro
********************************************************************************/
#include "DET.h"

#ifndef MCU_CFG_H
#define MCU_CFG_H


/*###############################################
	+++++++++++++MCU ID list++++++++++++++
################################################*/

/*--------------------------------------
ID 0x01-->0x0F for fujitsu FFMC-16FX serial MCU
##################################*/

#define MCU_ID_16FX_Start	0x00u

#define MCU_ID_MB96690	0x01u
#define MCU_ID_MB96670	0x02u


#define MCU_ID_16FX_End	0x0Fu


/*--------------------------------------
ID 0x11-->0x1F for Renesas 78K0R serial MCU
##################################*/

#define MCU_ID_78K0R_Start	0x10u

#define MCU_ID_78K0R_FG3	0x11u
/*
MCU_ID_78K0R_FG3:

100 pin product, including MCU type:
				ROM		RAM
---------------------------------------				
	uPD78F1845	256K	16K
	uPD78F1844	192K	12K
	uPD78F1843	128K	8K
	uPD78F1842	96K		6K
	uPD78F1841	64K		4K
--------------------------------------*/
#define MCU_ID_78K0R_FF3	0x12u
/*
MCU_ID_78K0R_FF3:

80 pin product, including MCU type:
				ROM		RAM
---------------------------------------				
	uPD78F1840	256K	16K
	uPD78F1839	192K	12K
	uPD78F1838	128K	8K
	uPD78F1825	128K	8K
	uPD78F1837	96K		6K
	uPD78F1824	96K		6K
	uPD78F1836	64K		4K
	uPD78F1823	64K		4K
--------------------------------------*/

#define MCU_ID_78K0R_FE3	0x13u
/*
MCU_ID_78K0R_FE3:

64 pin product, including MCU type:
				ROM		RAM
---------------------------------------				
	uPD78F1835	256K	16K
	uPD78F1834	192K	12K
	uPD78F1833	128K	8K
	uPD78F1822	128K	8K
	uPD78F1832	96K		6K
	uPD78F1821	96K		6K
	uPD78F1831	64K		4K
	uPD78F1820	64K		4K
	uPD78F1819	48K		3K
	uPD78F1818	32K		2K
--------------------------------------*/

#define MCU_ID_78K0R_FC3	0x14u
/*
MCU_ID_78K0R_FC3:

48 pin product, including MCU type:
				ROM		RAM
---------------------------------------				
	uPD78F1830	256K	16K
	uPD78F1829	192K	12K
	uPD78F1828	128K	8K
	uPD78F1817	128K	8K
	uPD78F1827	96K		6K
	uPD78F1816	96K		6K
	uPD78F1826	64K		4K
	uPD78F1815	64K		4K
	uPD78F1814	48K		3K
	uPD78F1813	32K		2K
	uPD78F1812	24K		1.5K
--------------------------------------*/

#define MCU_ID_78K0R_End	0x1Fu



/*-------------------------------------
ID 0x21-->0x2F for Renesas RH850 serial MCU
##################################*/

#define MCU_ID_RH850_Start		0x20u

/*F1L serial*/
#define MCU_ID_RH850_F1L_Start	0x20u
#define MCU_ID_7F1022			0x21u
#define MCU_ID_7F1023			0x22u
#define MCU_ID_7F1024			0x23u
#define MCU_ID_7F1025			0x24u
#define MCU_ID_RH850_F1L_End		0x2Fu

/*D1L serial*/
#define MCU_ID_RH850_D1L_Start	0x30u
#define MCU_ID_7F1401			0x31u
#define MCU_ID_7F1421			0x32u
#define MCU_ID_RH850_D1L_End		0x3Fu

/*D1M1 serial*/
#define MCU_ID_RH850_D1M_Start	0x40u
#define MCU_ID_7F1404			0x41u
#define MCU_ID_7F1424			0x42u
#define MCU_ID_RH850_D1M_End	0x4Fu

/*D1M1H serial*/
#define MCU_ID_RH850_D1M1H_Start	0x50u
#define MCU_ID_7F1406			0x41u
#define MCU_ID_7F1426			0x42u
#define MCU_ID_RH850_D1M1H_End	0x5Fu

/*D1M2H serial*/
#define MCU_ID_RH850_D1M2H_Start	0x60u
#define MCU_ID_7F1408			0x61u
#define MCU_ID_7F1428			0x62u
#define MCU_ID_7F1412			0x63u
#define MCU_ID_7F1432			0x64u
#define MCU_ID_RH850_D1M2H_End	0x6Fu

#define MCU_ID_RH850_End		(MCU_ID_RH850_D1M2H_End)




#define FUJITSU_Softune	1
#define RENESAS_IAR	2
#define RENESAS_CSplus	3
#define RENESAS_GreenHills	4

/*##################################
+++++++++Using MCU type+++++++++++++
##################################*/

#define MCU_UsingType		(MCU_ID_7F1022)/*MCU_ID_7F1432*/
#define COMPILER_TYPE	(RENESAS_GreenHills)

/*###############################################################

(=^o ^=)---------DO NOT EDIT BELOW  ----- -(=^o ^=)

###############################################################*/


#if (MCU_UsingType >=MCU_ID_16FX_Start) && (MCU_UsingType<=MCU_ID_16FX_End)

	#include <string.h>
	#include "./General.h"
	#include "../FFMC_16FX/16FX_Drv/_16FX_IOMap.h"
	#include "../FFMC_16FX/16FX_UsrCfg/_16FX_UsrCfg.h"
	#include "../FFMC_16FX/16FX_Drv/_16FX_Type.h"
	#include "../FFMC_16FX/16FX_Drv/_16FX.h"



#elif (MCU_UsingType >=MCU_ID_78K0R_Start) && (MCU_UsingType<=MCU_ID_78K0R_End)

	#include <intrinsics.h>
	#include <string.h>
	#include "./General.h"
	#include "../78K0R/78K0R_Drv/_78K0R_IO.h"
	#include "../78K0R/78K0R_UsrCfg/_78K0R_UsrCfg.h"
	#include "../78K0R/78K0R_Drv/_78K0R_Type.h"
	#include "../78K0R/78K0R_Drv/_78K0R.h"
	#include "../../DET/DET.h"
	
#elif (MCU_UsingType >=MCU_ID_RH850_Start) && (MCU_UsingType<=MCU_ID_RH850_End)

		#include <string.h>
		#include "./General.h"
		
		#if (MCU_UsingType >=MCU_ID_RH850_F1L_Start) && \
				(MCU_UsingType<=MCU_ID_RH850_F1L_End)
				#include "../RH850/F1L_UsrCfg/_F1L_UsrCfg.h"
				#include "../RH850/RH850_Drv/_F1L.h"
				#include "../RH850/RH850_Drv/_F1L_Type.h"
				#include "../RH850/RH850_Drv/_F1L_RegisterMap.h"

		#elif (MCU_UsingType >=MCU_ID_RH850_D1M_Start) && \
				(MCU_UsingType<=MCU_ID_RH850_D1M2H_End)
				#include "../RH850/D1X_UsrCfg/_D1X_UsrCfg.h"
				#include "../RH850/RH850_Drv/_D1X.h"
				#include "../RH850/RH850_Drv/_D1X_Type.h"
		#else
				#error "THE MCU TYPE NOT SUPPORT!!!!!!!!!!!!!!!!!!!!!"
		#endif
		
		#include "../RH850/RH850_Drv/_RH850.h"
		
#endif










#endif


