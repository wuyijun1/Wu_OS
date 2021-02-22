;====================================================================
;
;    Startup file for memory and basic controller initialisation
;
;    MB96600 Family C Compiler
;
;====================================================================
; 1  Copyright
;====================================================================
;  F2MC-16FX Family Template Project V01L03
;  ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011
;  LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
;====================================================================

          .PROGRAM  STARTUP
          .TITLE    "STARTUP FILE FOR MEMORY INITIALISATION"

;====================================================================
; 2  Contents
;====================================================================
;
; 1  Copyright
;
; 2  Contents
;
; 3  Information
;
; 4  Settings
; 4.1   C-language Memory model
; 4.2   Function-Call Interface
; 4.3   Stack Type and Stack Size
; 4.4   General Register Bank
; 4.5   Clock Selection
; 4.6   Sub oscillator configuration
; 4.7   Clock Stabilization Time
; 4.8   ROM Mirror configuration
; 4.9   Enable RAMCODE Copying
; 4.10  Flash Security
; 4.11  Flash Write Protection
; 4.12  Boot Vector
; 4.13  Vector table base register configuration
; 4.14  HAL_stUart scanning
; 4.15  On-chip debug system configuration
; 4.16  NMI configuration
; 4.17  Low voltage detection configuration
; 4.18  Watchdog timer interval configuration
;
; 5  Section and Data Declaration
; 5.1   Several fixed addresses (fixed for MB966xx controllers)
; 5.2   Set ROM Configuration for Boot Vector
; 5.3   Set ROM configuration for HAL_stUart Scanning
; 5.4   Set Flash Security
; 5.5   Set Flash write protection
; 5.6   Set ROM configuration for OCDS
; 5.7   Set ROM configuration for NMI
; 5.8   Set ROM configuration for Table Base Register (TBR)
; 5.9   Set ROM configuration for sub oscillator
; 5.10  Set ROM configuration for low voltage detection
; 5.11  Set ROM configuration for watchdog interval
; 5.12  Declaration of __near addressed data sections
; 5.13  Declaration of sections containing other sections description
; 5.14  Stack area and stack top definition/declaration
; 5.15  Direct page register dummy label definition
;
; 6  Start-Up Code
; 6.1   Import external symbols
; 6.2   Program start (the reset vector should point here)
; 6.3   Initialisation of processor status
; 6.4   Set clock ratio (ignore subclock)
; 6.5   Set ROM mirror configuaration
; 6.6   Prepare stacks and set the default stack type
; 6.7   Copy initial values to data areas.
; 6.8   Clear uninitialized data areas to zero
; 6.9   Set Data Bank Register (DTB) and Direct Page Register (DPR)
; 6.10  Wait for clocks to stabilize
; 6.11  Call C-language main function
; 6.12  Program end loop
;
; 7  Revision and History

;====================================================================
; 3  Information
;====================================================================
; @file   : start.asm
; @target : F2MC-16FX Family MB966xx series

;====================================================================
; 4  Settings
;====================================================================
;
; CHECK ALL OPTIONS WHETHER THEY FIT TO THE APPLICATION
;
; Configure this startup file in the "Settings" section. Search for
; comments with leading "; <<<". This points to the items to be set.
;====================================================================
#set      OFF       0
#set      ON        1

;====================================================================
; 4.1   C-language Memory model
;====================================================================
                                   ;      data      code
#set      SMALL     0              ;     16 Bit    16 Bit
#set      MEDIUM    1              ;     16 Bit    24 Bit
#set      COMPACT   2              ;     24 Bit    16 Bit
#set      LARGE     3              ;     24 Bit    24 Bit
#set      AUTOMODEL 4              ; works always, might occupy two
                                   ; additional bytes

#set      MEMMODEL  AUTOMODEL      ; <<< C-memory model

; The selected memory model should be set in order to fit to the
; model selected for the compiler.
; Note, in this startup version AUTOMODEL will work for all
; C-models. However, if the compiler is configured for SMALL or
; COMPACT, two additional bytes on stack are occupied. If this is not
; acceptable, the above setting should be set to the correct model.

;====================================================================
; 4.2   Function-Call Interface
;====================================================================

          #if __REG_PASS__
            .REG_PASS
          #endif

; Above statement informs Assembler on compatibility of start-up code
; to  Function Call Interface  as selected for the application. There
; is nothing to configure.
; The Function-Call Interface specifies the method of passing parame-
; ter from function caller to callee.  The standard method of FCC907S
; compiler  uses  "stack argument passing".  Alternatively,  language
; tools can be configured for "register argument passing".
; For details see the compiler manual.
; This start-up file is compatible to both interfaces.

;====================================================================
; 4.3   Stack Type and Stack Size
;====================================================================

#set      USRSTACK       0      ; user stack: for main program
#set      SYSSTACK       1      ; system stack: for main program and interrupts

#set      STACKUSE  SYSSTACK    ; <<< set active stack

#set      STACK_RESERVE  ON     ; <<< reserve stack area in this module
#set      STACK_SYS_SIZE 512    ; <<< byte size of System stack
#set      STACK_USR_SIZE 2      ; <<< byte size of User stack

#set      STACK_FILL     ON     ; <<< fills the stack area with pattern
#set      STACK_PATTERN  0xFFFF ; <<< the pattern to write to stack

; - If the active stack is set to SYSSTACK, it is used for main program
;   and interrupts. In this case, the user stack can be set to a dummy
;   size.
;   If the active stack is set to user stack, it is used for the main
;   program but the system stack is automatically activated, if an inter-
;   rupt is serviced. Both stack areas must have a reasonable size.
; - If STACK_RESERVE is ON, the sections USTACK and SSTACK are reserved
;   in this module. Otherwise, they have to be reserved in other modules.
;   If STACK_RESERVE is OFF, the size definitions STACK_SYS_SIZE and
;   STACK_USR_SIZE have no meaning.
; - Even if they are reserved in other modules, they are still initialised
;   in this start-up file.
; - Filling the stack with a pattern allows to dynamically check the stack
;   area, which had already been used.
;
; - If only system stack is used and SSB is linked to a different bank
;   than USB, make sure that all C-modules (which generate far pointers
;   to stack data) have "#pragma SSB". Applies only to exclusive confi-
;   gurations.
; - Note, several library functions require quite a big stack (due to
;   ANSI). Check the stack information files (*.stk) in the LIB\907
;   directory.

;====================================================================
; 4.4   General Register Bank
;====================================================================

#set      REGBANK   0           ; <<< set default register bank

; set the General Register Bank that is to be used after startup.
; Usually, this is bank 0, which applies to address 0x180..0x18F. Set
; in the range from 0 to 31.
; Note: All used register banks have to be reserved (linker options).

#if REGBANK > 31 || REGBANK < 0
#  error REGBANK setting out of range
#endif

;====================================================================
; 4.5   Clock Selection
;====================================================================

; The clock selection requires that a 4 MHz or 8 MHz external clock
; is provided as the Main Clock.

#set      CLOCKWAIT      ON     ; <<<  wait for stabilized clock, if
                                ;      Main Clock or PLL is used

; The clock is set quite early. However, if CLOCKWAIT is ON, polling
; for machine clock to be switched to Main Clock or PLL is done at
; the end of this file. Therefore, the stabilization time is not
; wasted. Main() will finally start at correct speed. Resources can
; be used immediately.
;
; This startup file version does not support subclock.

#set      FREQ_4MHZ       4000000L
#set      FREQ_8MHZ       8000000L

#set      CRYSTAL        FREQ_8MHZ  ; <<< select external crystal frequency

#set      CPU_RC_CLKP1_RC_CLKP2_RC                   0x0  ; will not modify initial clock settings
#set      CPU_MAINOSC_CLKP1_MAINOSC_CLKP2_MAINOSC    0x1
#set      CPU_16MHZ_CLKP1_16MHZ_CLKP2_16MHZ          0x2
#set      CPU_32MHZ_CLKP1_16MHZ_CLKP2_16MHZ          0x3
#set      CPU_32MHZ_CLKP1_32MHZ_CLKP2_16MHZ          0x4

#set      CLOCK_SPEED     CPU_16MHZ_CLKP1_16MHZ_CLKP2_16MHZ  ; <<< set clock speeds

;====================================================================
; 4.6   Sub oscillator configuration
;====================================================================
; The BootROM is able to configure sub oscillator availability and mode
#set      SUBOSC_DISABLED     1      ; Sub oscillator is disabled, pins can be used as GPIO pins
#set      SUBOSC_CRYSTAL      2      ; Sub oscillator is enabled in "oscillation mode", connect crystal/resonator to X0A/X1A pins
#set      SUBOSC_EXT_CLOCK    3      ; Sub oscillator is enabled in "external clock input mode", connect ext. clock to X0A pin, X1A can be used as GPIO

#set      SUBOSC_MODE         SUBOSC_DISABLED  ;SUBOSC_CRYSTAL   ; <<< select sub oscillator mode

;====================================================================
; 4.7   Clock Stabilization Time
;====================================================================

; Main clock stabilization time is given in clock cycles, where
; MC_2_X_CYCLES means 2 to power of X cycles.

#set      MC_2_10_CYCLES   0
#set      MC_2_12_CYCLES   1
#set      MC_2_13_CYCLES   2
#set      MC_2_14_CYCLES   3
#set      MC_2_15_CYCLES   4
#set      MC_2_16_CYCLES   5
#set      MC_2_17_CYCLES   6
#set      MC_2_18_CYCLES   7

#set      MC_STAB_TIME     MC_2_15_CYCLES ; <<< select Main Clock Stabilization Time

;====================================================================
; 4.8  ROM Mirror configuration
;====================================================================

#set      MIRROR_8KB    0
#set      MIRROR_16KB   1
#set      MIRROR_24KB   2
#set      MIRROR_32KB   3

#set      ROMMIRROR     ON          ; <<< ROM mirror function ON/OFF
#set      MIRROR_BANK   0xF         ; <<< ROM Mirror bank, allowed entries: 0x0..0xF for the banks 0xF0..0xFF
#set      MIRROR_SIZE   MIRROR_32KB ; <<< ROM Mirror size

; One can select which ROM area to mirror into the upper half of bank 00.
; If ROMMIRROR = OFF is selected, the address range 0x008000..0x00FFFF
; shows the contents of the respective area of bank 1: 0x018000..0x01FFFF.
; If ROMMIRROR = ON is selected, the memory bank to mirror can be selected.
; Available banks are 0xF0 to 0xFF. Furthermore, the ROM Mirror area size can
; be selected. 4 sizes are available: 8 kB, 16 kB, 24 kB, or 32 kB. The ROM Mirror
; from the highest address of the selected bank downwards, e.g. if bank 0xFF and
; mirror size 24 kB is selected, the memory range 0xFFA000..0xFFFFFF is mirrored
; to address range 0x00A000..0x00FFFF. The memory area not selected for
; ROM Mirror is still mirrored from bank 0x01.
; The ROM mirror function is necessary if the compiler option -ramconst is not
; specified. This is intended to increase performance, if a lot of dynamic data
; have to be accessed. In SMALL and MEDIUM model these data can be accessed
; within bank 0, which allows to use near addressing. Please make sure to have
; the linker setting adjusted accordingly!

;====================================================================
; 4.9  Enable RAMCODE Copying
;====================================================================

#set      COPY_RAMCODE      OFF     ; <<< enable RAMCODE section to
                                    ; be copied from ROM to RAM

; To get this option properly working the code to be executed has to
; be linked to section RAMCODE (e.g. by #pragma section). The section
; RAMCODE has be located in RAM and the section @RAMCODE has to be
; located at a fixed address in ROM by linker settings.

;====================================================================
; 4.10  Flash Security
;====================================================================
; All settings regarding Flash B are ignored on devices that do not
; have a Flash B.

#set      FLASH_A_SECURITY_ENABLE     OFF ; <<< enable Flash Security for Flash A

; set the Flash Security unlock key (16 bytes)
; all 0: unlock not possible
#set      FLASH_A_UNLOCK_0           0x00
#set      FLASH_A_UNLOCK_1           0x00
#set      FLASH_A_UNLOCK_2           0x00
#set      FLASH_A_UNLOCK_3           0x00
#set      FLASH_A_UNLOCK_4           0x00
#set      FLASH_A_UNLOCK_5           0x00
#set      FLASH_A_UNLOCK_6           0x00
#set      FLASH_A_UNLOCK_7           0x00
#set      FLASH_A_UNLOCK_8           0x00
#set      FLASH_A_UNLOCK_9           0x00
#set      FLASH_A_UNLOCK_10          0x00
#set      FLASH_A_UNLOCK_11          0x00
#set      FLASH_A_UNLOCK_12          0x00
#set      FLASH_A_UNLOCK_13          0x00
#set      FLASH_A_UNLOCK_14          0x00
#set      FLASH_A_UNLOCK_15          0x00

;====================================================================
; 4.11  Flash Write Protection
;====================================================================
; All settings regarding sectors that do not exist on the particular
; device will have no effect.

#set      FLASH_A_WRITE_PROTECT           OFF       ; <<< select Flash A write protection
#set      PROTECT_SECTOR_SAS              OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA0              OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA1              OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA2              OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA3              OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA39             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA38             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA37             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA36             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA35             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA34             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA33             OFF       ; <<< select individual sector to protect
#set      PROTECT_SECTOR_SA32             OFF       ; <<< select individual sector to protect

;====================================================================
; 4.12  Boot Vector
;====================================================================

#set      BOOT_VECTOR_TABLE        1      ; boot vector setting in vector table
#set      BOOT_VECTOR_ALTERNATIVE  2      ; alternative boot vector

#set      BOOT_VECTOR              BOOT_VECTOR_TABLE   ; <<< select type of boot vector

; If boot vector generation is enabled (BOOT_VECTOR_TABLE, BOOT_VECTOR_ALTERNATIVE),
; appropriate code is generated. If it is disabled (OFF), start-up file does
; not care about.
;
;         BOOT_VECTOR_TABLE: - Create table entry at appropriate address of vector table.
;                            - Any start address can be set and start-up file will
;                              set address of this start code.
;   BOOT_VECTOR_ALTERNATIVE: - Instead of vector table entry, a special marker is set in
;                              ROM Configuration Block, which enables the alternative
;                              boot vector address programmed to 0xDF0040.
;                              This is prefered setting for user boot loaders.
;                       OFF: - Do not set table entry and marker. This might be used
;                              for application to be loaded by boot loader.
;
; Note
; BOOT_VECTOR_TABLE setting can also be used, if all other interrupt vectors
; are specified via "pragma intvect". Only if interrupts 0..7 are specified
; via "pragma intvect", these will conflict with the vector in this module.
; The reason is the INTVECT section, which includes the whole area from the
; lowest to the highest specified vector.

;====================================================================
; 4.13  Vector table base register configuration
;====================================================================

; The BootROM is able to set the vector table base register (TBR) that
; defines the memory area where the interrupt vectors are located

#set      TBR_INIT_VALUE         0xFFFF   ; <<< define TBR value (address bits [23:8])

; Note that address bits [9:8] are always treated as '0', which means
; that 0xFFFF will also locate the vector table to its default address 0xFF:FC00

; ATTENTION: Linker must place INTVECT section to the appropriate address

;====================================================================
; 4.14  HAL_stUart scanning
;====================================================================

#set      UART_SCANNING   OFF        ; <<< enable HAL_stUart scanning in
                                     ;     Internal Vector Mode
;
; By default, the MCU scans in Internal Vector Mode for a HAL_stUart
; communication after reset. This enables to establish a serial
; communication without switching to Serial Communication Mode.
; For the final application, set this switch to OFF to achieve the
; fastest start-up time.

;====================================================================
; 4.15  On-chip debug system configuration
;====================================================================
#set      DEBUG_SECURITY_ENABLE     OFF           ; <<< enable Debug Security

; Set the debug security password length 1-14 (number of 16-bit words)
; only evaluated if DEBUG_SECURITY_ENABLE is ON, otherwise a length of 0 will be automatically chosen
#set      DEBUG_SECURITY_PASSWORD_LENGTH     14   ; <<< set Debug Security password length

; Set the debug security password
#set      DEBUG_SECURITY_PASSWORD_1    0x0000
#set      DEBUG_SECURITY_PASSWORD_2    0x0000
#set      DEBUG_SECURITY_PASSWORD_3    0x0000
#set      DEBUG_SECURITY_PASSWORD_4    0x0000
#set      DEBUG_SECURITY_PASSWORD_5    0x0000
#set      DEBUG_SECURITY_PASSWORD_6    0x0000
#set      DEBUG_SECURITY_PASSWORD_7    0x0000
#set      DEBUG_SECURITY_PASSWORD_8    0x0000
#set      DEBUG_SECURITY_PASSWORD_9    0x0000
#set      DEBUG_SECURITY_PASSWORD_10   0x0000
#set      DEBUG_SECURITY_PASSWORD_11   0x0000
#set      DEBUG_SECURITY_PASSWORD_12   0x0000
#set      DEBUG_SECURITY_PASSWORD_13   0x0000
#set      DEBUG_SECURITY_PASSWORD_14   0x0000

; Set the on-chip debug system boot mode
#set      OCDS_BOOT_NORMAL          1      ; normal boot with handshaking, mode decided by MDI init sequence
#set      OCDS_BOOT_FAST_FREERUN    2      ; fast boot, don't wait for end of MDI init sequence, start in free-run mode
#set      OCDS_BOOT_FAST_EMULATION  3      ; fast boot, don't wait for end of MDI init sequence, start in emulation mode

#set      OCDS_BOOT_MODE            OCDS_BOOT_NORMAL   ; <<< select OCDS boot mode
; Note, it is recommended to choose the OCDS_BOOT_FAST_FREERUN mode for the final application in order to speed up the boot phase

; Set on-chip debug system pin mode
#set      OCDS_DEBUG_PIN_MDI        1      ; debug pin enabled
#set      OCDS_DEBUG_PIN_SOFTGPIO   2      ; debug pin temporarily disabled, but can be enabled by the application
#set      OCDS_DEBUG_PIN_GPIO       3      ; debug pin permanently disabled, no debugging possible any more (strongest security)

#set      OCDS_DEBUG_PIN_MODE       OCDS_DEBUG_PIN_MDI   ; <<< select OCDS debug pin mode
; Note, while debug pin is disabled it can be used as a GPIO pin

;====================================================================
; 4.16  NMI configuration
;====================================================================

; The BootROM is able to setup and enable the NMI pin,
; so that the NMI can be active during the whole execution of the user code
#set      NMIPIN_MODE_DISABLED                 1  ; BootROM disables the NMI
#set      NMIPIN_MODE_NMI_FUNCTION_LOW_ACT     2  ; BootROM enables the low active NMI function
#set      NMIPIN_MODE_NMI_FUNCTION_HIGH_ACT    3  ; BootROM enables the high active NMI function

#set      NMIPIN_MODE             NMI_MODE_DISABLED   ; <<< select mode of the NMI pin

; The BootROM is able to relocate the NMI pin
#set      NMIPIN_RELOCATION       OFF    ; <<< select NMI pin relocation

; Note, the relocation setting is device specific

;====================================================================
; 4.17  Low voltage detection configuration
;====================================================================

; The BootROM is able to lock the low voltage detector which means that
; low voltage detection and corresponding reset is always enabled and
; user code cannot change the setting by accident
#set      LVD_LOCK            OFF   ; <<< select locking of LVD state

;====================================================================
; 4.18  Watchdog timer interval configuration
;====================================================================

; BootROM can change the default Watchdog timer interval

; Watchdog timer interval is given in clock cycles, where
; WT_2_X_CYCLES means 2 to power of X cycles of Watchdog timer clock.

#set      WT_2_8_CYCLES    0
#set      WT_2_9_CYCLES    1
#set      WT_2_10_CYCLES   2
#set      WT_2_11_CYCLES   3
#set      WT_2_12_CYCLES   4
#set      WT_2_13_CYCLES   5
#set      WT_2_14_CYCLES   6
#set      WT_2_15_CYCLES   7
#set      WT_2_16_CYCLES   8
#set      WT_2_17_CYCLES   9
#set      WT_2_18_CYCLES   10
#set      WT_2_19_CYCLES   11
#set      WT_2_20_CYCLES   12
#set      WT_2_21_CYCLES   13
#set      WT_2_22_CYCLES   14
#set      WT_2_23_CYCLES   15

#set      WT_INTERVAL     WT_2_21_CYCLES    ; <<< select Watchdog timer interval

; <<< END OF SETTINGS >>>

;====================================================================
; 5  Section and Data Declaration
;====================================================================

;====================================================================
; 5.1   Several fixed addresses (fixed for MB966xx controllers)
;====================================================================

ROMM       .EQU      0x03AE          ; ROM mirror control register
CKSR       .EQU      0x0401          ; Clock selection register
CKSSR      .EQU      0x0402          ; Clock stabilization select register
CKMR       .EQU      0x0403          ; Clock monitor register
CKFCR      .EQU      0x0404          ; Clock frequency control register
PLLCR      .EQU      0x0406          ; PLL control register
TBR	   .EQU      0x03A2          ; Vector Table control register

;====================================================================
; 5.2   Set ROM Configuration for Boot Vector
;====================================================================
#set VECTOR_TABLE_BASE_ADDRESS    ((TBR_INIT_VALUE & 0xFFFC) << 8)

#if BOOT_VECTOR == BOOT_VECTOR_TABLE
          .SECTION        BOOT_SELECT, CONST, LOCATE=0xDF0030
          .DATA.L 0xFFFFFFFF
          .SECTION        RESVECT, CONST, LOCATE=(VECTOR_TABLE_BASE_ADDRESS + 0x3DC)
          .DATA.E _start

#elif BOOT_VECTOR == BOOT_VECTOR_ALTERNATIVE
          .SECTION        BOOT_SELECT, CONST, LOCATE=0xDF0030
          .DATA.L 0x292D3A7B        ; "Magic Word"
          .SECTION        ALTRESVECT, CONST, LOCATE=0xDF0040
          .DATA.E _start
#else
          .SECTION        BOOT_SELECT, CONST, LOCATE=0xDF0030
          .SKIP   4
#endif

;====================================================================
; 5.3   Set ROM configuration for HAL_stUart Scanning
;====================================================================

#if UART_SCANNING == ON
          .SECTION        UART_SCAN_SELECT, CONST, LOCATE=0xDF0034
          .DATA.L 0xFFFFFFFF
#else
          .SECTION        UART_SCAN_SELECT, CONST, LOCATE=0xDF0034
          .DATA.L 0x292D3A7B        ; Deactivation "Magic Word"
#endif
          .SKIP   2
;====================================================================
; 5.4   Set Flash Security
;====================================================================

          .SECTION FLASH_A_SECURITY, CONST, LOCATE=0xDF0000
#if FLASH_A_SECURITY_ENABLE == OFF
	      .DATA.W 0xFFFF ; Security DISABLED
	      .SKIP   26
#else FLASH_A_SECURITY_ENABLE == ON
	      .DATA.W 0x9999 ; Security ENABLED
	      .DATA.W ((FLASH_A_UNLOCK_1  << 8) | FLASH_A_UNLOCK_0)
	      .DATA.W ((FLASH_A_UNLOCK_3  << 8) | FLASH_A_UNLOCK_2)
	      .DATA.W ((FLASH_A_UNLOCK_5  << 8) | FLASH_A_UNLOCK_4)
	      .DATA.W ((FLASH_A_UNLOCK_7  << 8) | FLASH_A_UNLOCK_6)
	      .DATA.W ((FLASH_A_UNLOCK_9  << 8) | FLASH_A_UNLOCK_8)
	      .DATA.W ((FLASH_A_UNLOCK_11 << 8) | FLASH_A_UNLOCK_10)
	      .DATA.W ((FLASH_A_UNLOCK_13 << 8) | FLASH_A_UNLOCK_12)
	      .DATA.W ((FLASH_A_UNLOCK_15 << 8) | FLASH_A_UNLOCK_14)
#endif

;====================================================================
; 5.5   Set Flash write protection
;====================================================================

          .SECTION FLASH_A_PROTECT, CONST, LOCATE=0xDF001C
#if FLASH_A_WRITE_PROTECT == ON
          .DATA.L 0x292D3A7B
          .DATA.B ~((PROTECT_SECTOR_SA3 << 4) | (PROTECT_SECTOR_SA2 << 3) | (PROTECT_SECTOR_SA1 << 2) | (PROTECT_SECTOR_SA0 << 1) | PROTECT_SECTOR_SAS)
          .SKIP   3
          .DATA.B ~((PROTECT_SECTOR_SA39 << 7) | (PROTECT_SECTOR_SA38 << 6) | (PROTECT_SECTOR_SA37 << 5) | (PROTECT_SECTOR_SA36 << 4) | (PROTECT_SECTOR_SA35 << 3) | (PROTECT_SECTOR_SA34 << 2) | (PROTECT_SECTOR_SA33 << 1) | PROTECT_SECTOR_SA32)
          .SKIP   1
#else
          .DATA.L 0xFFFFFFFF
          .SKIP   6
#endif ; FLASH_A_WRITE_PROTECT

;====================================================================
; 5.6   Set ROM configuration for OCDS
;====================================================================

#if (DEBUG_SECURITY_ENABLE == ON) && ((DEBUG_SECURITY_PASSWORD_LENGTH > 14) || (DEBUG_SECURITY_PASSWORD_LENGTH < 1))
#  error DEBUG_SECURITY_PASSWORD_LENGTH out of range
#endif

          .SECTION        OCDS_BOOT_SELECT, CONST, LOCATE=0xDF0056

#if OCDS_BOOT_MODE == OCDS_BOOT_FAST_FREERUN
          .DATA.B 0x55
#elif OCDS_BOOT_MODE == OCDS_BOOT_FAST_EMULATION
          .DATA.B 0xAA
#else
          .DATA.B 0xFF
#endif
          .SKIP   1

          .SECTION OCDS_SECURITY, CONST, LOCATE=0xDF0058

#if DEBUG_SECURITY_ENABLE == ON
          .DATA.W DEBUG_SECURITY_PASSWORD_LENGTH
          .DATA.W DEBUG_SECURITY_PASSWORD_1
          .DATA.W DEBUG_SECURITY_PASSWORD_2
          .DATA.W DEBUG_SECURITY_PASSWORD_3
          .DATA.W DEBUG_SECURITY_PASSWORD_4
          .DATA.W DEBUG_SECURITY_PASSWORD_5
          .DATA.W DEBUG_SECURITY_PASSWORD_6
          .DATA.W DEBUG_SECURITY_PASSWORD_7
          .DATA.W DEBUG_SECURITY_PASSWORD_8
          .DATA.W DEBUG_SECURITY_PASSWORD_9
          .DATA.W DEBUG_SECURITY_PASSWORD_10
          .DATA.W DEBUG_SECURITY_PASSWORD_11
          .DATA.W DEBUG_SECURITY_PASSWORD_12
          .DATA.W DEBUG_SECURITY_PASSWORD_13
          .DATA.W DEBUG_SECURITY_PASSWORD_14
#else
          .DATA.W 0x00
          .SKIP   (14 * 2)
#endif

          .SECTION        OCDS_PINMODE_SELECT, CONST, LOCATE=0xDF0076

#if OCDS_DEBUG_PIN_MODE == OCDS_DEBUG_PIN_SOFTGPIO
          .DATA.B 0x82
          .DATA.B 0xB8
          .DATA.B 0xDB
          .DATA.B 0x6B
          .DATA.B 0x71
          .DATA.B 0xCE
          .DATA.B 0x39
          .DATA.B 0x84
          .DATA.B 0x53
          .DATA.B 0x58
          .DATA.B 0xE3
          .DATA.B 0x25
          .DATA.B 0x1B
          .DATA.B 0x63
          .DATA.B 0x7C
          .DATA.B 0x96
          .DATA.B 0xE4
          .DATA.B 0x36
#elif OCDS_DEBUG_PIN_MODE == OCDS_DEBUG_PIN_GPIO
          .DATAB.B 138, 0x00
#else
          .DATAB.B 138, 0xFF
#endif

;====================================================================
; 5.7   Set ROM configuration for NMI
;====================================================================

          .SECTION        NMIRELOC_SELECT, CONST, LOCATE=0xDF0026

#if NMI_RELOCATION == ON
          .DATA.B 0x55
#else
          .DATA.B 0xFF
#endif

          .SECTION        NMIPINMODE_SELECT, CONST, LOCATE=0xDF0027
#if NMIPIN_MODE == NMIPIN_MODE_NMI_FUNCTION_LOW_ACT
          .DATA.B 0x55
#elif NMIPIN_MODE == NMIPIN_MODE_NMI_FUNCTION_HIGH_ACT
          .DATA.B 0xAA
#else ; NMI disabled
          .DATA.B 0xFF
#endif
          .DATAB.B 2, 0xFF
;====================================================================
; 5.8   Set ROM configuration for Table Base Register (TBR)
;====================================================================

          .SECTION        TBR_SELECT, CONST, LOCATE=0xDF002A

          .DATA.W TBR_INIT_VALUE
          .DATAB.B 4, 0xFF
;====================================================================
; 5.9   Set ROM configuration for sub oscillator
;====================================================================

          .SECTION        SUBOSC_SELECT, CONST, LOCATE=0xDF003A

#if SUBOSC_MODE == SUBOSC_CRYSTAL
          .DATA.B 0x55
#elif SUBOSC_MODE == SUBOSC_EXT_CLOCK
          .DATA.B 0xAA
#else
          .DATA.B 0xFF
#endif

;====================================================================
; 5.10  Set ROM configuration for low voltage detection
;====================================================================

          .SECTION        LVD_SELECT, CONST, LOCATE=0xDF003B

#if LVD_LOCK == ON
          .DATA.B 0x55
#else
          .DATA.B 0xFF
#endif

;====================================================================
; 5.11  Set ROM configuration for watchdog interval
;====================================================================

          .SECTION        WTINTERVAL_SELECT, CONST, LOCATE=0xDF003C

          .DATA.B WT_INTERVAL
          .DATAB.B 25, 0xFF
;====================================================================
; 5.12  Declaration of __near addressed data sections
;====================================================================

; sections to be cleared
          .SECTION  DATA,      DATA,   ALIGN=2  ; zero clear area
          .SECTION  DIRDATA,   DIR,    ALIGN=2  ; zero clear direct
          .SECTION  LIBDATA,   DATA,   ALIGN=2  ; zero clear lib area

; sections to be initialised with start-up values
          .SECTION  INIT,      DATA,   ALIGN=2  ; initialised area
          .SECTION  DIRINIT,   DIR,    ALIGN=2  ; initialised dir
          .SECTION  LIBINIT,   DATA,   ALIGN=2  ; initialised lib area

; sections containing start-up values for initialised sections above
          .SECTION  DCONST,    CONST,  ALIGN=2  ; DINIT initialisers
          .SECTION  DIRCONST, DIRCONST,ALIGN=2  ; DIRINIT initialisers
          .SECTION  LIBDCONST, CONST,  ALIGN=2  ; LIBDCONST init val

          ; following section is either copied to CINIT (RAMCONST) or
          ; mapped by ROM-mirror function (ROMCONST)
          .SECTION  CONST,     CONST,  ALIGN=2  ; CINIT initialisers

;====================================================================
; 5.13  Declaration of sections containing other sections description
;====================================================================

; DCLEAR contains start address and size of all sections to be cleared
; DTRANS contains HAL_stSource and destination address and size of all
; sections to be initialised with start-up values
; The compiler automatically adds a descriptor for each __far addressed
; data section to DCLEAR or DTRANS. These __far sections are separated
; for each C-module.

; In addition the start-up file adds the descriptors of the previously
; declared __near section here. This way the same code in the start-up
; file can be used for initialising all sections.

   .SECTION  DCLEAR,    CONST,  ALIGN=2  ; zero clear table
   ;    Address         Bank            Size
   .DATA.H DATA,    BNKSEC DATA,    SIZEOF(DATA   )
   .DATA.H DIRDATA, BNKSEC DIRDATA, SIZEOF(DIRDATA)
   .DATA.H LIBDATA, BNKSEC LIBDATA, SIZEOF(LIBDATA)

   .SECTION  DTRANS,    CONST,  ALIGN=2  ; copy table
   ;    Address         Bank               Address     Bank          Size
   .DATA.H DCONST,   BNKSEC DCONST,   INIT,   BNKSEC INIT,   SIZEOF INIT
   .DATA.H DIRCONST, BNKSEC DIRCONST, DIRINIT,BNKSEC DIRINIT,SIZEOF DIRINIT
   .DATA.H LIBDCONST,BNKSEC LIBDCONST,LIBINIT,BNKSEC LIBINIT,SIZEOF LIBINIT

#if COPY_RAMCODE == ON
   .DATA.L _ROM_RAMCODE, _RAM_RAMCODE
   .DATA.H SIZEOF RAMCODE
#endif

;====================================================================
; 5.14  Stack area and stack top definition/declaration
;====================================================================
#if STACK_RESERVE == ON
            .SECTION  SSTACK, STACK, ALIGN=2

            .EXPORT __systemstack, __systemstack_top
__systemstack:
            .RES.B    (STACK_SYS_SIZE + 1) & 0xFFFE
__systemstack_top:
SSTACK_TOP:

            .SECTION  USTACK, STACK, ALIGN=2

            .EXPORT __userstack, __userstack_top
__userstack:
            .RES.B    (STACK_USR_SIZE + 1) & 0xFFFE
__userstack_top:
USTACK_TOP:

#else
            .SECTION  SSTACK, STACK, ALIGN=2
            .SECTION  USTACK, STACK, ALIGN=2
#endif

;====================================================================
; 5.15  Direct page register dummy label definition
;====================================================================

          .SECTION  DIRDATA  ; zero clear direct
DIRDATA_S:                                      ; label for DPR init

; This label is used to get the page of the __direct data.
; Depending on the linkage order of this startup file the label is
; placed anywhere within the __direct data page. However, the
; statement "PAGE (DIRDATA_S)" is processed. Therefore, the lower
; 8 Bit of the address of DIRDATA_S are not relevant and this feature
; becomes linkage order independent.
; Note, the linker settings have to make sure that all __direct
; data are located within the same physical page (256 Byte block).

;====================================================================
; 6  Start-Up Code
;====================================================================

;====================================================================
; 6.1   Import external symbols
;====================================================================

          .IMPORT   _main                    ; user code entrance
          .EXPORT   _start

;====================================================================
;   ___  _____   __    ___  _____
;  /       |    /  \  |   \   |
;  \___    |   |    | |___/   |
;      \   |   |----| |  \    |
;   ___/   |   |    | |   \   |      Begin of actual code section
;
;====================================================================
          .SECTION  CODE_START, CODE, ALIGN=1

;====================================================================
; 6.2   Program start (the reset vector should point here)
;====================================================================
_start:
          NOP  ; This NOP is only for debugging. On debugger the IP
               ; (instruction pointer) should point here after reset

;====================================================================
; 6.3   Initialisation of processor status
;====================================================================
          AND  CCR, #0x80          ; disable interrupts
          MOV  ILM,#7              ; set interrupt level mask to ALL
          MOV  RP,#REGBANK         ; set register bank pointer

          MOVN A, #0               ; set bank 0 in DTB for the case that
          MOV  DTB, A              ; start-up code was not jumped by reset

	  MOVW A, #0xFFFF	   ; Set Vector table address to default
	  MOVW TBR, A		   ; address, __interrupt commond locate
				   ; the ISR in 0xFFxxxx adress
				   ; -tan fumin 20160119
;====================================================================
; 6.4   Set clock ratio (ignore subclock)
;====================================================================
;#0: CPU_RC_CLKP1_RC_CLKP2_RC
;#1: CPU_MAINOSC_CLKP1_MAINOSC_CLKP2_MAINOSC
;#2: CPU_16MHZ_CLKP1_16MHZ_CLKP2_16MHZ
;#3: CPU_32MHZ_CLKP1_16MHZ_CLKP2_16MHZ
;#4: CPU_32MHZ_CLKP1_32MHZ_CLKP2_16MHZ
;
;+Main-+     +-----+          [PLLCR]        #1        #2        #3        #4
;| OSC +--+--+ PLL +---CLKPLL   4M                 16M(div4) 32M(div8) 32M(div8) VCO=64M
;+-----+  |  +-----+     |      8M                 16M(div2) 32M(div4) 32M(div4) VCO=64M
;         |              |
;         |              |     [CKFCR]       #1        #2        #3        #4
;         +----CLKMC-----x---+--CLKB   4M|8M(div1) 16M(div1) 32M(div1) 32M(div1)
;                            +--CLKP1  4M|8M(div1) 16M(div1) 16M(div2) 32M(div1)
;                            +--CLKP2  4M|8M(div1) 16M(div1) 16M(div2) 16M(div2)
;
;       #1       [CKSR] CLKMC(=0xB5) ;SCE="1",PCE="0",MCE="1",RCE="1",SC2S="01", SC1S="01"
;       #2/#3/#4 [CKSR] CLKPLL(=0xFA);SCE="1",PCE="1",MCE="1",RCE="1",SC2S="10", SC1S="10"

  MOV  CKSSR, #(0x38 | MC_STAB_TIME)  ; set clock stabilization time

#if CLOCK_SPEED == CPU_RC_CLKP1_RC_CLKP2_RC
  ; do nothing, keep initial clock settings
#elif CLOCK_SPEED == CPU_MAINOSC_CLKP1_MAINOSC_CLKP2_MAINOSC
  ; change CLKS1 and CLKS2 to main oscillator
  MOV  CKSR,  #0xB5 ; change CLKS1 and CLKS2 to main oscillator(remain SCE=1)
  ; set clock dividers for the current clock setting
  MOVW CKFCR, #0x0001 ;CLKP2="0000"(div1),CLKP1="0000"(div1),CLKB="0000"(div1),RCFS="0001"
#else
  #if CLOCK_SPEED == CPU_16MHZ_CLKP1_16MHZ_CLKP2_16MHZ
    ; Set PLL configuration depending on used crystal frequency
    #if CRYSTAL == FREQ_4MHZ
      MOVW PLLCR, #0x0023 ;VMS[2:0]="001"(div4),PMS[4:0]="00011"(div4)
    #elif CRYSTAL == FREQ_8MHZ
      MOVW PLLCR, #0x0021 ;VMS[2:0]="001"(div4),PMS[4:0]="00001"(div2)
    #else
      #error Wrong crystal setting
    #endif
    ; set clock dividers for the current clock setting
    MOVW CKFCR, #0x0001 ;CLKP2="0000"(div1),CLKP1="0000"(div1),CLKB="0000"(div1),RCFS="0001"

  #elif CLOCK_SPEED == CPU_32MHZ_CLKP1_16MHZ_CLKP2_16MHZ
    ; Set PLL configuration depending on used crystal frequency
    #if CRYSTAL == FREQ_4MHZ
      MOVW PLLCR, #0x0007 ;VMS[2:0]="000"(div2),PMS[4:0]="00111"(div8)
    #elif CRYSTAL == FREQ_8MHZ
      MOVW PLLCR, #0x0003 ;VMS[2:0]="000"(div2),PMS[4:0]="00011"(div4)
    #else
      #error Wrong CRYSTAL setting
    #endif
    ; set clock dividers for the current clock setting
    MOVW CKFCR, #0x1101 ;CLKP2="0001"(div2),CLKP1="0001"(div2),CLKB="0000"(div1),RCFS="0001"

  #elif CLOCK_SPEED == CPU_32MHZ_CLKP1_32MHZ_CLKP2_16MHZ
    ; Set PLL configuration depending on used crystal frequency
    #if CRYSTAL == FREQ_4MHZ
      MOVW PLLCR, #0x0007 ;VMS[2:0]="000"(div2),PMS[4:0]="00111"(div8)
    #elif CRYSTAL == FREQ_8MHZ
      MOVW PLLCR, #0x0003 ;VMS[2:0]="000"(div2),PMS[4:0]="00011"(div4)
    #else
      #error Wrong crystal setting
    #endif
    ; set clock dividers for the current clock setting
    MOVW CKFCR, #0x1001 ;CLKP2="0001"(div2),CLKP1="0000"(div1),CLKB="0000"(div1),RCFS="0001"

  #else
    #error Wrong CLOCK_SPEED setting
  #endif

  MOV  CKSR,  #0xFA ; change CLKS1 and CLKS2 to PLL clock(reamin SCE=1)

#endif

;====================================================================
; 6.5   Set ROM mirror configuaration
;====================================================================

ROMM_CONFIG    .EQU     ((MIRROR_BANK << 4) | (MIRROR_SIZE << 1) | (ROMMIRROR))
           MOV  ROMM, #ROMM_CONFIG

;====================================================================
; 6.6   Prepare stacks and set the default stack type
;====================================================================
;--------------------------------------------------------------------
; set user stack
;--------------------------------------------------------------------
        AND  CCR, #0xDF             ; clear system stack flag
        MOV  A, #BNKSYM USTACK_TOP
        MOV  USB, A
        MOVW A, #USTACK_TOP
        MOVW SP, A

;--------------------------------------------------------------------
; set system stack
;--------------------------------------------------------------------
        OR  CCR, #0x20             ; set system stack flag
        MOV  A, #BNKSYM SSTACK_TOP
        MOV  SSB, A
        MOVW A, #SSTACK_TOP
        MOVW SP, A

#if STACKUSE == USRSTACK
        AND  CCR, #0xDF             ; clear system stack flag
#endif

;--------------------------------------------------------------------
; stack fill
;--------------------------------------------------------------------
#macro  STACK_FILL_DATA  us_stack
        MOVW   RW0, #SIZEOF(\us_stack)/2 ; get word count
        MOVL   A, #\us_stack             ; load start stack address to A
        MOVW   A, #STACK_PATTERN         ; AL -> AH, pattern in AL
        FILSWI SPB                       ; write pattern to stack
#endm

#if STACK_FILL == ON                ; preset the stack
        STACK_FILL_DATA  SSTACK
        STACK_FILL_DATA  USTACK
#endif

;====================================================================
; 6.7   Copy initial values to data areas
;====================================================================
;
; Each C-module has its own __far INIT section. The names are generic.
; DCONST_module contains the initializers for the far data of the one
; module. INIT_module reserves the RAM area, which has to be loaded
; with the data from DCONST_module. ("module" is the name of the *.c
; file)
; All separated DCONST_module/INIT_module areas are described in
; DTRANS section by start addresses and length of each far section.
;   0000 1. HAL_stSource address (ROM)
;   0004 1. destination address (RAM)
;   0008 length of sections 1
;   000A 2. HAL_stSource address  (ROM)
;   000E 2. destination address (RAM)
;   0012 length of sections 2
;   0014 3. HAL_stSource address ...
; In addition the start-up file adds the descriptors of the __near
; sections to this table. The order of the descriptors in this table
; depends on the linkage order.
;
; Note: Sections cannot exceed bank boundaries.
;====================================================================
          MOVL A, #DTRANS          ; get address of table
          MOVL RL2, A              ; store address in RL2 (RW4/RW5)
          BRA  LABEL2              ; branch to loop condition
LABEL1:
          MOVW A, @RL2+6           ; get bank of destination
          MOV  DTB, A              ; save dest bank in DTB
          MOVW A, @RL2+2           ; get HAL_stSource bank
          MOV  ADB, A              ; save HAL_stSource bank in ADB
          MOVW A, @RL2+8           ; number of bytes to copy -> A
          MOVW RW0, A              ; number of bytes to copy -> RW0
          MOVW A, @RL2+4           ; move destination addr in AL
          MOVW A, @RL2             ; AL -> AH, src addr -> AL
          MOVSI DTB, ADB           ; copy data
          MOVN A, #10              ; length of one table entry is 10
          ADDW RW4, A              ; set pointer to next table entry
LABEL2:
          MOVW A, RW4              ; get address of next block
          CMPW A, #DTRANS + SIZEOF (DTRANS) ; all blocks processed ?
          BNE  LABEL1              ; if not, branch

;====================================================================
; 6.8   Clear uninitialized data areas to zero
;====================================================================
;
; Each C-module has its own __far DATA section. The names are generic.
; DATA_module contains the reserved area (RAM) to be cleared.
; ("module" is the name of the *.c file)
; All separated DATA_module areas are described in DCLEAR section by
; start addresses and length of all far section.
;   0000 1. section address (RAM)
;   0004 length of section 1
;   0006 2. section address (RAM)
;   000A length of section 2
;   000C 3. section address (RAM)
;   0010 length of section 3 ...
; In addition the start-up file adds the descriptors of the __near
; sections to this table. The order of the descriptors in this table
; depends on the linkage order.
;====================================================================
          MOV  A, #BNKSEC DCLEAR   ; get bank of table
          MOV  DTB, A              ; store bank in DTB
          MOVW RW1, #DCLEAR        ; get start offset of table
          BRA  LABEL4              ; branch to loop condition
LABEL3:
          MOV  A, @RW1+2           ; get section bank
          MOV  ADB, A              ; save section bank in ADB
          MOVW RW0, @RW1+4         ; number of bytes to copy -> RW0
          MOVW A, @RW1             ; move section addr in AL
          MOVN A, #0               ; AL -> AH, init value -> AL
          FILSI     ADB            ; write 0 to section
          MOVN A, #6               ; length of one table entry is 6
          ADDW RW1, A              ; set pointer to next table entry
LABEL4:
          MOVW A, RW1              ; get address of next block
          SUBW A, #DCLEAR          ; sub address of first block
          CMPW A, #SIZEOF (DCLEAR) ; all blocks processed ?
          BNE  LABEL3              ; if not, branch

;====================================================================
; 6.9   Set Data Bank Register (DTB) and Direct Page Register (DPR)
;====================================================================
          MOV  A,#BNKSEC DATA          ; User data bank offset
          MOV  DTB,A

          MOV  A,#PAGE DIRDATA_S       ; User direct page
          MOV  DPR,A

;====================================================================
; 6.10  Wait for clocks to stabilize
;====================================================================

#if CLOCKWAIT == ON
#  if CLOCK_SPEED == CPU_MAINOSC_CLKP1_MAINOSC_CLKP2_MAINOSC
no_MC_yet:
          BBC  CKMR:5,no_MC_yet        ; check MCM and wait for
                                       ; Main Clock to stabilize
#  elif (CLOCK_SPEED == CPU_16MHZ_CLKP1_16MHZ_CLKP2_16MHZ) || \
        (CLOCK_SPEED == CPU_32MHZ_CLKP1_16MHZ_CLKP2_16MHZ) || \
        (CLOCK_SPEED == CPU_32MHZ_CLKP1_32MHZ_CLKP2_16MHZ)
no_PLL_yet:
          BBC  CKMR:6,no_PLL_yet       ; check PCM and wait for
                                       ; PLL to stabilize
#  else
#    error Setting of CLKB_CLKP1_SOURCE is not supported.
#  endif
#endif

;====================================================================
; 6.11  Call C-language main function
;====================================================================
#if MEMMODEL == SMALL || MEMMODEL == COMPACT
          CALL _main               ; Start main function
#else                              ; MEDIUM, LARGE, AUTOMODEL
          CALLP _main              ; Start main function
                                   ; ignore remaining word on stack,
                                   ; if main was completed by RET
#endif

;====================================================================
; 6.12  Program end loop
;====================================================================

end:      BRA  end                 ; Loop

          .END  _start

;====================================================================
; ----------------------- End of Start-up file ---------------------
;====================================================================
;====================================================================
; 7  Revision and History
;====================================================================
;Date        Ver     Description
;2011-06-10  V00L01  Preliminary version
;2011-06-20  V00L02  Preliminary version 2
;                    mainc:
;                     -Comment addition
;                    start.asm:
;                     -Comment change in section 6.4
;                     -The setting of clock stabilization time(CKSSR) is moved
;                      from section 6.10 to the head of section 6.4.
;                     -To enable Sub-Clock, SCE, bit7 of CKSR, is changed to 1.
;                      (Two places in section 6.4)
;2011-06-28  V00L03  Preliminary version 3
;                    mainc:
;                     -removed function(Vectors_InitIrqLevels)
;                    vectors.c
;                     -removed function(Vectors_InitIrqLevels)
;                    vectors.h
;                     -removed function(Vectors_InitIrqLevels)
;                    start.asm:
;                     -changed section 6.6, 6.7 and 6.8
;2011-07-15  V00L04  Preliminary version 4
;                    mainc:
;                     -changed comment
;                    vectors.c
;                     -changed comment
;                    vectors.h
;                     -removed this file
;                    start.asm:
;                     -changed section 6.6, 6.7 and 6.8
;2011-08-30  V00L05  Preliminary version 5
;                    start.asm:
;                     -changed section 5.3,5.4,5.6,5.7,5.8 and 5.11
;                      There are interspaces in the section of ROM building block in some places.
;                      When disposing it automatically, CODE and CONST might be disposed to the interspaces.
;                      To prevent it, they are buried with 0xFF etc.
;                     -changed section 6.6
;                      Logical mistake correction
;                    vectors.c
;                     -removed a comment
;2011-10-26  V01L01  V00L05 is replaced with V01L01
;                    romconst.prc:
;                     -added a version notation
;                    main.c:
;                     -changed register name (WDTCP -> WDTCP_)
;2011-12-07  V01L02  start.asm:
;                     -The error in writing of the marker value for Flash security disabled is corrected.
;                      (marker value:0x6666 -> 0xFFFF)
;2012-01-12  V01L03  start.asm:
;                     -Removed some of the comments (line 545).


