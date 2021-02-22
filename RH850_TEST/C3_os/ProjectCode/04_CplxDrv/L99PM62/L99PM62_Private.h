/**************************** .FILE_HEADER_BEGIN *****************************
  .TITLE: CSI for EEPROM driver for 96CX6 EEPROM serial
*-----------------------------------------------------------------------------
  .FILE:EEP_Drv.h
  .AUTHOR:Tan, fumin
*-----------------------------------------------------------------------------

 Date        Author                       Change
 -----------------------------------------------------------------------------
2013.02.06  Tan, fumin		   :create this module
2013.03.12  Tan, fumin		    create macro EP_CallBackFunction_Enable for driver call back for special flow
*****************************************************************************/

#include "general.h"
#ifndef L99PM62_Private_H
#define L99PM62_Private_H

typedef uint32 L99PM62drv_StatusRegType;
#define REL1_ON     (CtrlReg1[2] |= 0x40U)
#define REL1_OFF    (CtrlReg1[2] &= (uint8_t)~0x40U)
#define REL2_ON     (CtrlReg1[2] |= 0x80U)
#define REL2_OFF    (CtrlReg1[2] &= (uint8_t)~0x80U)
uint16 SPI_u16TransferData_CH1(void *pOutDataHead, void *pRecDataHead,uint16 u16DataLen);

 
static uint8		CtrlReg1[3], /*!< Internal copy of L99PM62 control registers 1.
			                      Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg2[3], /*!< Internal copy of L99PM62 control registers 2.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg3[3], /*!< Internal copy of L99PM62 control registers 3.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg4[3], /*!< Internal copy of L99PM62 control registers 4.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg5[3], /*!< Internal copy of L99PM62 control registers 5.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg6[3], /*!< Internal copy of L99PM62 control registers 6.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				CtrlReg_Result[3],/*the result of control reg output after confige(write/read) */
								
				StatReg1[3], /*!< Internal copy of L99PM62 status registers 1.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				StatReg2[3], /*!< Internal copy of L99PM62 status registers 2.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				StatReg3[3], /*!< Internal copy of L99PM62 status registers 3.
				                Bit order: x[0]:23..16, x[1]:15..8, x[2]:7..0 */
				StatReg_Result[3];/*the result of state reg output after confige(write/read) */

static uint8    InitFlag = 0U;


#endif

