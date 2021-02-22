/*******************************************************************************
| Module Name: MCU Drive for Renesas 78K0R serial, special chip is upd78F1xxx
| File Name: _78K0R_IO.h
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
| 2015.11.28  V0.01	Tan, fumin	:create this module
********************************************************************************/

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _78K0R_IO_H_
#define _78K0R_IO_H_

#pragma language=extended
#pragma system_include

/*----------------------------------------------
 * SFR bits (default names)
 *--------------------------------------------*/
  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
  } __BITS8;
  
typedef unsigned char __BYTE;
typedef int  __WORD;

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

extern __near __no_bit_access __no_init volatile unsigned char ADPC @ 0xF0017;
extern __near __no_init volatile union { unsigned char PU0; __BITS8 PU0_bit; } @ 0xF0030;
extern __near __no_init volatile union { unsigned char PU1; __BITS8 PU1_bit; } @ 0xF0031;
extern __near __no_init volatile union { unsigned char PU3; __BITS8 PU3_bit; } @ 0xF0033;
extern __near __no_init volatile union { unsigned char PU4; __BITS8 PU4_bit; } @ 0xF0034;
extern __near __no_init volatile union { unsigned char PU5; __BITS8 PU5_bit; } @ 0xF0035;
extern __near __no_init volatile union { unsigned char PU6; __BITS8 PU6_bit; } @ 0xF0036;
extern __near __no_init volatile union { unsigned char PU7; __BITS8 PU7_bit; } @ 0xF0037;
extern __near __no_init volatile union { unsigned char PU12; __BITS8 PU12_bit; } @ 0xF003C;
extern __near __no_init volatile union { unsigned char PU14; __BITS8 PU14_bit; } @ 0xF003E;
extern __near __no_init volatile union { unsigned char PU15; __BITS8 PU15_bit; } @ 0xF003F;
extern __near __no_init volatile union { unsigned char PIM6; __BITS8 PIM6_bit; } @ 0xF0046;
extern __near __no_init volatile union { unsigned char PIM7; __BITS8 PIM7_bit; } @ 0xF0047;
extern __near __no_init volatile union { unsigned char POM4; __BITS8 POM4_bit; } @ 0xF0054;
extern __near __no_init volatile union { unsigned char POM7; __BITS8 POM7_bit; } @ 0xF0057;
extern __near __no_init volatile union { unsigned char NFEN0; __BITS8 NFEN0_bit; } @ 0xF0060;
extern __near __no_init volatile union { unsigned char NFEN1; __BITS8 NFEN1_bit; } @ 0xF0061;
extern __near __no_init volatile union { unsigned char NFEN2; __BITS8 NFEN2_bit; } @ 0xF0062;
extern __near __no_init volatile union { unsigned char NFEN3; __BITS8 NFEN3_bit; } @ 0xF0063;
extern __near __no_init volatile union { unsigned char LVIOUT; __BITS8 LVIOUT_bit; } @ 0xF0067;
extern __near __no_init volatile union { unsigned char PSRSEL; __BITS8 PSRSEL_bit; } @ 0xF006F;
extern __near __no_init volatile union { unsigned char GUARD; __BITS8 GUARD_bit; } @ 0xF0070;
extern __near __no_bit_access __no_init volatile unsigned char WDTSELF @ 0xF0071;
extern __near __no_init volatile union { unsigned char IAWCTL; __BITS8 IAWCTL_bit; } @ 0xF0074;
extern __near __no_bit_access __no_init volatile unsigned char IAWRAM @ 0xF0075;
extern __near __no_bit_access __no_init volatile unsigned char IAWFLASH @ 0xF0076;
extern __near __no_bit_access __no_init volatile unsigned char DSA2 @ 0xF0080;
extern __near __no_bit_access __no_init volatile unsigned char DSA3 @ 0xF0081;
extern __near __no_bit_access __no_init volatile union { unsigned short DRA2; struct { unsigned char DRA2L; unsigned char DRA2H; }; } @ 0xF0082;
extern __near __no_bit_access __no_init volatile union { unsigned short DRA3; struct { unsigned char DRA3L; unsigned char DRA3H; }; } @ 0xF0084;
extern __near __no_bit_access __no_init volatile union { unsigned short DBC2; struct { unsigned char DBC2L; unsigned char DBC2H; }; } @ 0xF0086;
extern __near __no_bit_access __no_init volatile union { unsigned short DBC3; struct { unsigned char DBC3L; unsigned char DBC3H; }; } @ 0xF0088;
extern __near __no_init volatile union { unsigned char DMC2; __BITS8 DMC2_bit; } @ 0xF008A;
extern __near __no_init volatile union { unsigned char DMC3; __BITS8 DMC3_bit; } @ 0xF008B;
extern __near __no_init volatile union { unsigned char DRC2; __BITS8 DRC2_bit; } @ 0xF008C;
extern __near __no_init volatile union { unsigned char DRC3; __BITS8 DRC3_bit; } @ 0xF008D;
extern __near __no_init volatile union { unsigned char DMCALL; __BITS8 DMCALL_bit; } @ 0xF008F;
extern __near __no_bit_access __no_init volatile const unsigned short MDCL @ 0xF00E0;
extern __near __no_bit_access __no_init volatile const unsigned short MDCH @ 0xF00E2;
extern __near __no_init volatile union { unsigned char MDUC; __BITS8 MDUC_bit; } @ 0xF00E8;
extern __near __no_init volatile union { unsigned char PER0; __BITS8 PER0_bit; } @ 0xF00F0;
extern __near __no_init volatile union { unsigned char PER1; __BITS8 PER1_bit; } @ 0xF00F1;
extern __near __no_init volatile union { unsigned char PCKSEL; __BITS8 PCKSEL_bit; } @ 0xF00F2;
extern __near __no_init volatile union { unsigned char OSMC; __BITS8 OSMC_bit; } @ 0xF00F3;
extern __near __no_init volatile const union { unsigned char PLLSTS; __BITS8 PLLSTS_bit; } @ 0xF00F6;
extern __near __no_init volatile union { unsigned char PLLCTL; __BITS8 PLLCTL_bit; } @ 0xF00F7;
extern __near __no_bit_access __no_init volatile unsigned short HIOTRM @ 0xF00F8;
extern __near __no_bit_access __no_init volatile unsigned char LIOTRM @ 0xF00FA;
extern __near __no_init volatile union { unsigned char POCRES; __BITS8 POCRES_bit; } @ 0xF00FB;
extern __near __no_init volatile union { unsigned char STPSTC; __BITS8 STPSTC_bit; } @ 0xF00FC;
extern __near __no_bit_access __no_init volatile const unsigned char BCDADJ @ 0xF00FE;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR00; struct { unsigned char SSR00L; }; } @ 0xF0100;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR01; struct { unsigned char SSR01L; }; } @ 0xF0102;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR00; struct { unsigned char SIR00L; }; } @ 0xF0104;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR01; struct { unsigned char SIR01L; }; } @ 0xF0106;
extern __near __no_bit_access __no_init volatile unsigned short SMR00 @ 0xF0108;
extern __near __no_bit_access __no_init volatile unsigned short SMR01 @ 0xF010A;
extern __near __no_bit_access __no_init volatile unsigned short SCR00 @ 0xF010C;
extern __near __no_bit_access __no_init volatile unsigned short SCR01 @ 0xF010E;
extern __near __no_init volatile const union { unsigned short SE0; struct { union { unsigned char SE0L; __BITS8 SE0L_bit; }; }; } @ 0xF0110;
extern __near __no_init volatile union { unsigned short SS0; struct { union { unsigned char SS0L; __BITS8 SS0L_bit; }; }; } @ 0xF0112;
extern __near __no_init volatile union { unsigned short ST0; struct { union { unsigned char ST0L; __BITS8 ST0L_bit; }; }; } @ 0xF0114;
extern __near __no_bit_access __no_init volatile union { unsigned short SPS0; struct { unsigned char SPS0L; }; } @ 0xF0116;
extern __near __no_bit_access __no_init volatile unsigned short SO0 @ 0xF0118;
extern __near __no_init volatile union { unsigned short SOE0; struct { union { unsigned char SOE0L; __BITS8 SOE0L_bit; }; }; } @ 0xF011A;
extern __near __no_bit_access __no_init volatile union { unsigned short SOL0; struct { unsigned char SOL0L; }; } @ 0xF0120;
extern __near __no_init volatile union { unsigned short SSE0; struct { union { unsigned char SSE0L; __BITS8 SSE0L_bit; }; }; } @ 0xF0122;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR10; struct { unsigned char SSR10L; }; } @ 0xF0130;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR11; struct { unsigned char SSR11L; }; } @ 0xF0132;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR10; struct { unsigned char SIR10L; }; } @ 0xF0134;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR11; struct { unsigned char SIR11L; }; } @ 0xF0136;
extern __near __no_bit_access __no_init volatile unsigned short SMR10 @ 0xF0138;
extern __near __no_bit_access __no_init volatile unsigned short SMR11 @ 0xF013A;
extern __near __no_bit_access __no_init volatile unsigned short SCR10 @ 0xF013C;
extern __near __no_bit_access __no_init volatile unsigned short SCR11 @ 0xF013E;
extern __near __no_init volatile const union { unsigned short SE1; struct { union { unsigned char SE1L; __BITS8 SE1L_bit; }; }; } @ 0xF0140;
extern __near __no_init volatile union { unsigned short SS1; struct { union { unsigned char SS1L; __BITS8 SS1L_bit; }; }; } @ 0xF0142;
extern __near __no_init volatile union { unsigned short ST1; struct { union { unsigned char ST1L; __BITS8 ST1L_bit; }; }; } @ 0xF0144;
extern __near __no_bit_access __no_init volatile union { unsigned short SPS1; struct { unsigned char SPS1L; }; } @ 0xF0146;
extern __near __no_bit_access __no_init volatile unsigned short SO1 @ 0xF0148;
extern __near __no_init volatile union { unsigned short SOE1; struct { union { unsigned char SOE1L; __BITS8 SOE1L_bit; }; }; } @ 0xF014A;
extern __near __no_bit_access __no_init volatile union { unsigned short SOL1; struct { unsigned char SOL1L; }; } @ 0xF0150;
extern __near __no_bit_access __no_init volatile union { unsigned short SOL2; struct { unsigned char SOL2L; }; } @ 0xF0158;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR20; struct { unsigned char SSR20L; }; } @ 0xF0160;
extern __near __no_bit_access __no_init volatile const union { unsigned short SSR21; struct { unsigned char SSR21L; }; } @ 0xF0162;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR20; struct { unsigned char SIR20L; }; } @ 0xF0164;
extern __near __no_bit_access __no_init volatile union { unsigned short SIR21; struct { unsigned char SIR21L; }; } @ 0xF0166;
extern __near __no_bit_access __no_init volatile unsigned short SMR20 @ 0xF0168;
extern __near __no_bit_access __no_init volatile unsigned short SMR21 @ 0xF016A;
extern __near __no_bit_access __no_init volatile unsigned short SCR20 @ 0xF016C;
extern __near __no_bit_access __no_init volatile unsigned short SCR21 @ 0xF016E;
extern __near __no_init volatile const union { unsigned short SE2; struct { union { unsigned char SE2L; __BITS8 SE2L_bit; }; }; } @ 0xF0170;
extern __near __no_init volatile union { unsigned short SS2; struct { union { unsigned char SS2L; __BITS8 SS2L_bit; }; }; } @ 0xF0172;
extern __near __no_init volatile union { unsigned short ST2; struct { union { unsigned char ST2L; __BITS8 ST2L_bit; }; }; } @ 0xF0174;
extern __near __no_bit_access __no_init volatile union { unsigned short SPS2; struct { unsigned char SPS2L; }; } @ 0xF0176;
extern __near __no_bit_access __no_init volatile unsigned short SO2 @ 0xF0178;
extern __near __no_init volatile union { unsigned short SOE2; struct { union { unsigned char SOE2L; __BITS8 SOE2L_bit; }; }; } @ 0xF017A;
extern __near __no_bit_access __no_init volatile const unsigned short TCR00 @ 0xF0180;
extern __near __no_bit_access __no_init volatile const unsigned short TCR01 @ 0xF0182;
extern __near __no_bit_access __no_init volatile const unsigned short TCR02 @ 0xF0184;
extern __near __no_bit_access __no_init volatile const unsigned short TCR03 @ 0xF0186;
extern __near __no_bit_access __no_init volatile const unsigned short TCR04 @ 0xF0188;
extern __near __no_bit_access __no_init volatile const unsigned short TCR05 @ 0xF018A;
extern __near __no_bit_access __no_init volatile const unsigned short TCR06 @ 0xF018C;
extern __near __no_bit_access __no_init volatile const unsigned short TCR07 @ 0xF018E;
extern __near __no_bit_access __no_init volatile unsigned short TMR00 @ 0xF0190;
extern __near __no_bit_access __no_init volatile unsigned short TMR01 @ 0xF0192;
extern __near __no_bit_access __no_init volatile unsigned short TMR02 @ 0xF0194;
extern __near __no_bit_access __no_init volatile unsigned short TMR03 @ 0xF0196;
extern __near __no_bit_access __no_init volatile unsigned short TMR04 @ 0xF0198;
extern __near __no_bit_access __no_init volatile unsigned short TMR05 @ 0xF019A;
extern __near __no_bit_access __no_init volatile unsigned short TMR06 @ 0xF019C;
extern __near __no_bit_access __no_init volatile unsigned short TMR07 @ 0xF019E;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR00; struct { unsigned char TSR00L; }; } @ 0xF01A0;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR01; struct { unsigned char TSR01L; }; } @ 0xF01A2;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR02; struct { unsigned char TSR02L; }; } @ 0xF01A4;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR03; struct { unsigned char TSR03L; }; } @ 0xF01A6;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR04; struct { unsigned char TSR04L; }; } @ 0xF01A8;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR05; struct { unsigned char TSR05L; }; } @ 0xF01AA;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR06; struct { unsigned char TSR06L; }; } @ 0xF01AC;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR07; struct { unsigned char TSR07L; }; } @ 0xF01AE;
extern __near __no_init volatile const union { unsigned short TE0; struct { union { unsigned char TE0L; __BITS8 TE0L_bit; }; }; } @ 0xF01B0;
extern __near __no_init volatile union { unsigned short TS0; struct { union { unsigned char TS0L; __BITS8 TS0L_bit; }; }; } @ 0xF01B2;
extern __near __no_init volatile union { unsigned short TT0; struct { union { unsigned char TT0L; __BITS8 TT0L_bit; }; }; } @ 0xF01B4;
extern __near __no_bit_access __no_init volatile unsigned short TPS0 @ 0xF01B6;
extern __near __no_bit_access __no_init volatile union { unsigned short TO0; struct { unsigned char TO0L; }; } @ 0xF01B8;
extern __near __no_init volatile union { unsigned short TOE0; struct { union { unsigned char TOE0L; __BITS8 TOE0L_bit; }; }; } @ 0xF01BA;
extern __near __no_bit_access __no_init volatile union { unsigned short TOL0; struct { unsigned char TOL0L; }; } @ 0xF01BC;
extern __near __no_bit_access __no_init volatile union { unsigned short TOM0; struct { unsigned char TOM0L; }; } @ 0xF01BE;
extern __near __no_bit_access __no_init volatile const unsigned short TCR10 @ 0xF01C0;
extern __near __no_bit_access __no_init volatile const unsigned short TCR11 @ 0xF01C2;
extern __near __no_bit_access __no_init volatile const unsigned short TCR12 @ 0xF01C4;
extern __near __no_bit_access __no_init volatile const unsigned short TCR13 @ 0xF01C6;
extern __near __no_bit_access __no_init volatile const unsigned short TCR14 @ 0xF01C8;
extern __near __no_bit_access __no_init volatile const unsigned short TCR15 @ 0xF01CA;
extern __near __no_bit_access __no_init volatile const unsigned short TCR16 @ 0xF01CC;
extern __near __no_bit_access __no_init volatile const unsigned short TCR17 @ 0xF01CE;
extern __near __no_bit_access __no_init volatile unsigned short TMR10 @ 0xF01D0;
extern __near __no_bit_access __no_init volatile unsigned short TMR11 @ 0xF01D2;
extern __near __no_bit_access __no_init volatile unsigned short TMR12 @ 0xF01D4;
extern __near __no_bit_access __no_init volatile unsigned short TMR13 @ 0xF01D6;
extern __near __no_bit_access __no_init volatile unsigned short TMR14 @ 0xF01D8;
extern __near __no_bit_access __no_init volatile unsigned short TMR15 @ 0xF01DA;
extern __near __no_bit_access __no_init volatile unsigned short TMR16 @ 0xF01DC;
extern __near __no_bit_access __no_init volatile unsigned short TMR17 @ 0xF01DE;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR10; struct { unsigned char TSR10L; }; } @ 0xF01E0;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR11; struct { unsigned char TSR11L; }; } @ 0xF01E2;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR12; struct { unsigned char TSR12L; }; } @ 0xF01E4;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR13; struct { unsigned char TSR13L; }; } @ 0xF01E6;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR14; struct { unsigned char TSR14L; }; } @ 0xF01E8;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR15; struct { unsigned char TSR15L; }; } @ 0xF01EA;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR16; struct { unsigned char TSR16L; }; } @ 0xF01EC;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR17; struct { unsigned char TSR17L; }; } @ 0xF01EE;
extern __near __no_init volatile const union { unsigned short TE1; struct { union { unsigned char TE1L; __BITS8 TE1L_bit; }; }; } @ 0xF01F0;
extern __near __no_init volatile union { unsigned short TS1; struct { union { unsigned char TS1L; __BITS8 TS1L_bit; }; }; } @ 0xF01F2;
extern __near __no_init volatile union { unsigned short TT1; struct { union { unsigned char TT1L; __BITS8 TT1L_bit; }; }; } @ 0xF01F4;
extern __near __no_bit_access __no_init volatile unsigned short TPS1 @ 0xF01F6;
extern __near __no_bit_access __no_init volatile union { unsigned short TO1; struct { unsigned char TO1L; }; } @ 0xF01F8;
extern __near __no_init volatile union { unsigned short TOE1; struct { union { unsigned char TOE1L; __BITS8 TOE1L_bit; }; }; } @ 0xF01FA;
extern __near __no_bit_access __no_init volatile union { unsigned short TOL1; struct { unsigned char TOL1L; }; } @ 0xF01FC;
extern __near __no_bit_access __no_init volatile union { unsigned short TOM1; struct { unsigned char TOM1L; }; } @ 0xF01FE;
extern __near __no_bit_access __no_init volatile const unsigned short TCR20 @ 0xF0200;
extern __near __no_bit_access __no_init volatile const unsigned short TCR21 @ 0xF0202;
extern __near __no_bit_access __no_init volatile const unsigned short TCR22 @ 0xF0204;
extern __near __no_bit_access __no_init volatile const unsigned short TCR23 @ 0xF0206;
extern __near __no_bit_access __no_init volatile const unsigned short TCR24 @ 0xF0208;
extern __near __no_bit_access __no_init volatile const unsigned short TCR25 @ 0xF020A;
extern __near __no_bit_access __no_init volatile const unsigned short TCR26 @ 0xF020C;
extern __near __no_bit_access __no_init volatile const unsigned short TCR27 @ 0xF020E;
extern __near __no_bit_access __no_init volatile unsigned short TMR20 @ 0xF0210;
extern __near __no_bit_access __no_init volatile unsigned short TMR21 @ 0xF0212;
extern __near __no_bit_access __no_init volatile unsigned short TMR22 @ 0xF0214;
extern __near __no_bit_access __no_init volatile unsigned short TMR23 @ 0xF0216;
extern __near __no_bit_access __no_init volatile unsigned short TMR24 @ 0xF0218;
extern __near __no_bit_access __no_init volatile unsigned short TMR25 @ 0xF021A;
extern __near __no_bit_access __no_init volatile unsigned short TMR26 @ 0xF021C;
extern __near __no_bit_access __no_init volatile unsigned short TMR27 @ 0xF021E;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR20; struct { unsigned char TSR20L; }; } @ 0xF0220;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR21; struct { unsigned char TSR21L; }; } @ 0xF0222;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR22; struct { unsigned char TSR22L; }; } @ 0xF0224;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR23; struct { unsigned char TSR23L; }; } @ 0xF0226;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR24; struct { unsigned char TSR24L; }; } @ 0xF0228;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR25; struct { unsigned char TSR25L; }; } @ 0xF022A;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR26; struct { unsigned char TSR26L; }; } @ 0xF022C;
extern __near __no_bit_access __no_init volatile const union { unsigned short TSR27; struct { unsigned char TSR27L; }; } @ 0xF022E;
extern __near __no_init volatile const union { unsigned short TE2; struct { union { unsigned char TE2L; __BITS8 TE2L_bit; }; }; } @ 0xF0230;
extern __near __no_init volatile union { unsigned short TS2; struct { union { unsigned char TS2L; __BITS8 TS2L_bit; }; }; } @ 0xF0232;
extern __near __no_init volatile union { unsigned short TT2; struct { union { unsigned char TT2L; __BITS8 TT2L_bit; }; }; } @ 0xF0234;
extern __near __no_bit_access __no_init volatile unsigned short TPS2 @ 0xF0236;
extern __near __no_bit_access __no_init volatile union { unsigned short TO2; struct { unsigned char TO2L; }; } @ 0xF0238;
extern __near __no_init volatile union { unsigned short TOE2; struct { union { unsigned char TOE2L; __BITS8 TOE2L_bit; }; }; } @ 0xF023A;
extern __near __no_bit_access __no_init volatile union { unsigned short TOL2; struct { unsigned char TOL2L; }; } @ 0xF023C;
extern __near __no_bit_access __no_init volatile union { unsigned short TOM2; struct { unsigned char TOM2L; }; } @ 0xF023E;
extern __near __no_init volatile union { unsigned char UF0CTL0; __BITS8 UF0CTL0_bit; } @ 0xF0240;
extern __near __no_init volatile union { unsigned char UF0OPT0; __BITS8 UF0OPT0_bit; } @ 0xF0241;
extern __near __no_bit_access __no_init volatile unsigned short UF0CTL1 @ 0xF0242;
extern __near __no_init volatile union { unsigned char UF0OPT1; __BITS8 UF0OPT1_bit; } @ 0xF0244;
extern __near __no_init volatile union { unsigned char UF0OPT2; __BITS8 UF0OPT2_bit; } @ 0xF0245;
extern __near __no_bit_access __no_init volatile const unsigned short UF0STR @ 0xF0246;
extern __near __no_bit_access __no_init volatile unsigned short UF0STC @ 0xF0248;
extern __near __no_bit_access __no_init volatile union { unsigned short UF0WTX; struct { unsigned char UF0WTXB; }; } @ 0xF024A;
extern __near __no_bit_access __no_init volatile unsigned char UF0ID @ 0xF024E;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF0 @ 0xF024F;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF1 @ 0xF0250;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF2 @ 0xF0251;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF3 @ 0xF0252;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF4 @ 0xF0253;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF5 @ 0xF0254;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF6 @ 0xF0255;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF7 @ 0xF0256;
extern __near __no_bit_access __no_init volatile unsigned char UF0BUF8 @ 0xF0257;
extern __near __no_bit_access __no_init volatile unsigned short UF0BUCTL @ 0xF0258;
extern __near __no_init volatile union { unsigned char UF1CTL0; __BITS8 UF1CTL0_bit; } @ 0xF0260;
extern __near __no_init volatile union { unsigned char UF1OPT0; __BITS8 UF1OPT0_bit; } @ 0xF0261;
extern __near __no_bit_access __no_init volatile unsigned short UF1CTL1 @ 0xF0262;
extern __near __no_init volatile union { unsigned char UF1OPT1; __BITS8 UF1OPT1_bit; } @ 0xF0264;
extern __near __no_init volatile union { unsigned char UF1OPT2; __BITS8 UF1OPT2_bit; } @ 0xF0265;
extern __near __no_bit_access __no_init volatile const unsigned short UF1STR @ 0xF0266;
extern __near __no_bit_access __no_init volatile unsigned short UF1STC @ 0xF0268;
extern __near __no_bit_access __no_init volatile union { unsigned short UF1WTX; struct { unsigned char UF1WTXB; }; } @ 0xF026A;
extern __near __no_bit_access __no_init volatile unsigned char UF1ID @ 0xF026E;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF0 @ 0xF026F;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF1 @ 0xF0270;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF2 @ 0xF0271;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF3 @ 0xF0272;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF4 @ 0xF0273;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF5 @ 0xF0274;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF6 @ 0xF0275;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF7 @ 0xF0276;
extern __near __no_bit_access __no_init volatile unsigned char UF1BUF8 @ 0xF0277;
extern __near __no_bit_access __no_init volatile unsigned short UF1BUCTL @ 0xF0278;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR0; struct { unsigned char :8; const unsigned char ADCR0H; }; } @ 0xF0280;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR1; struct { unsigned char :8; const unsigned char ADCR1H; }; } @ 0xF0282;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR2; struct { unsigned char :8; const unsigned char ADCR2H; }; } @ 0xF0284;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR3; struct { unsigned char :8; const unsigned char ADCR3H; }; } @ 0xF0286;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR4; struct { unsigned char :8; const unsigned char ADCR4H; }; } @ 0xF0288;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR5; struct { unsigned char :8; const unsigned char ADCR5H; }; } @ 0xF028A;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR6; struct { unsigned char :8; const unsigned char ADCR6H; }; } @ 0xF028C;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR7; struct { unsigned char :8; const unsigned char ADCR7H; }; } @ 0xF028E;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR8; struct { unsigned char :8; const unsigned char ADCR8H; }; } @ 0xF0290;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR9; struct { unsigned char :8; const unsigned char ADCR9H; }; } @ 0xF0292;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR10; struct { unsigned char :8; const unsigned char ADCR10H; }; } @ 0xF0294;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR11; struct { unsigned char :8; const unsigned char ADCR11H; }; } @ 0xF0296;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR12; struct { unsigned char :8; const unsigned char ADCR12H; }; } @ 0xF0298;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR13; struct { unsigned char :8; const unsigned char ADCR13H; }; } @ 0xF029A;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR14; struct { unsigned char :8; const unsigned char ADCR14H; }; } @ 0xF029C;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR15; struct { unsigned char :8; const unsigned char ADCR15H; }; } @ 0xF029E;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR16; struct { unsigned char :8; const unsigned char ADCR16H; }; } @ 0xF02A0;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR17; struct { unsigned char :8; const unsigned char ADCR17H; }; } @ 0xF02A2;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR18; struct { unsigned char :8; const unsigned char ADCR18H; }; } @ 0xF02A4;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR19; struct { unsigned char :8; const unsigned char ADCR19H; }; } @ 0xF02A6;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR20; struct { unsigned char :8; const unsigned char ADCR20H; }; } @ 0xF02A8;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR21; struct { unsigned char :8; const unsigned char ADCR21H; }; } @ 0xF02AA;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR22; struct { unsigned char :8; const unsigned char ADCR22H; }; } @ 0xF02AC;
extern __near __no_bit_access __no_init volatile const union { unsigned short ADCR23; struct { unsigned char :8; const unsigned char ADCR23H; }; } @ 0xF02AE;
extern __near __no_init volatile const union { unsigned char DFLST; __BITS8 DFLST_bit; } @ 0xF04F0;
extern __near __no_bit_access __no_init volatile unsigned short CGMCTRL @ 0xF05C0;
extern __near __no_bit_access __no_init volatile unsigned short CGMABT @ 0xF05C6;
extern __near __no_bit_access __no_init volatile unsigned char CGMABTD @ 0xF05C8;
extern __near __no_bit_access __no_init volatile unsigned char CGMCS @ 0xF05CE;
extern __near __no_bit_access __no_init volatile unsigned short CMASK1L @ 0xF05D0;
extern __near __no_bit_access __no_init volatile unsigned short CMASK1H @ 0xF05D2;
extern __near __no_bit_access __no_init volatile unsigned short CMASK2L @ 0xF05D4;
extern __near __no_bit_access __no_init volatile unsigned short CMASK2H @ 0xF05D6;
extern __near __no_bit_access __no_init volatile unsigned short CMASK3L @ 0xF05D8;
extern __near __no_bit_access __no_init volatile unsigned short CMASK3H @ 0xF05DA;
extern __near __no_bit_access __no_init volatile unsigned short CMASK4L @ 0xF05DC;
extern __near __no_bit_access __no_init volatile unsigned short CMASK4H @ 0xF05DE;
extern __near __no_bit_access __no_init volatile unsigned short CCTRL @ 0xF05E0;
extern __near __no_bit_access __no_init volatile unsigned char CLEC @ 0xF05E2;
extern __near __no_bit_access __no_init volatile const unsigned char CINFO @ 0xF05E3;
extern __near __no_bit_access __no_init volatile const unsigned short CERC @ 0xF05E4;
extern __near __no_bit_access __no_init volatile unsigned short CIE @ 0xF05E6;
extern __near __no_bit_access __no_init volatile unsigned short CINTS @ 0xF05E8;
extern __near __no_bit_access __no_init volatile unsigned char CBRP @ 0xF05EA;
extern __near __no_bit_access __no_init volatile unsigned short CBTR @ 0xF05EC;
extern __near __no_bit_access __no_init volatile const unsigned char CLIPT @ 0xF05EE;
extern __near __no_bit_access __no_init volatile unsigned short CRGPT @ 0xF05F0;
extern __near __no_bit_access __no_init volatile const unsigned char CLOPT @ 0xF05F2;
extern __near __no_bit_access __no_init volatile unsigned short CTGPT @ 0xF05F4;
extern __near __no_bit_access __no_init volatile unsigned short CTS @ 0xF05F6;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0100; struct { unsigned char CMDB000; unsigned char CMDB100; }; } @ 0xF0600;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2300; struct { unsigned char CMDB200; unsigned char CMDB300; }; } @ 0xF0602;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4500; struct { unsigned char CMDB400; unsigned char CMDB500; }; } @ 0xF0604;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6700; struct { unsigned char CMDB600; unsigned char CMDB700; }; } @ 0xF0606;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC00 @ 0xF0608;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF00 @ 0xF0609;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL00 @ 0xF060A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH00 @ 0xF060C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL00 @ 0xF060E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0101; struct { unsigned char CMDB001; unsigned char CMDB101; }; } @ 0xF0610;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2301; struct { unsigned char CMDB201; unsigned char CMDB301; }; } @ 0xF0612;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4501; struct { unsigned char CMDB401; unsigned char CMDB501; }; } @ 0xF0614;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6701; struct { unsigned char CMDB601; unsigned char CMDB701; }; } @ 0xF0616;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC01 @ 0xF0618;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF01 @ 0xF0619;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL01 @ 0xF061A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH01 @ 0xF061C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL01 @ 0xF061E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0102; struct { unsigned char CMDB002; unsigned char CMDB102; }; } @ 0xF0620;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2302; struct { unsigned char CMDB202; unsigned char CMDB302; }; } @ 0xF0622;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4502; struct { unsigned char CMDB402; unsigned char CMDB502; }; } @ 0xF0624;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6702; struct { unsigned char CMDB602; unsigned char CMDB702; }; } @ 0xF0626;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC02 @ 0xF0628;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF02 @ 0xF0629;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL02 @ 0xF062A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH02 @ 0xF062C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL02 @ 0xF062E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0103; struct { unsigned char CMDB003; unsigned char CMDB103; }; } @ 0xF0630;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2303; struct { unsigned char CMDB203; unsigned char CMDB303; }; } @ 0xF0632;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4503; struct { unsigned char CMDB403; unsigned char CMDB503; }; } @ 0xF0634;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6703; struct { unsigned char CMDB603; unsigned char CMDB703; }; } @ 0xF0636;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC03 @ 0xF0638;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF03 @ 0xF0639;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL03 @ 0xF063A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH03 @ 0xF063C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL03 @ 0xF063E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0104; struct { unsigned char CMDB004; unsigned char CMDB104; }; } @ 0xF0640;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2304; struct { unsigned char CMDB204; unsigned char CMDB304; }; } @ 0xF0642;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4504; struct { unsigned char CMDB404; unsigned char CMDB504; }; } @ 0xF0644;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6704; struct { unsigned char CMDB604; unsigned char CMDB704; }; } @ 0xF0646;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC04 @ 0xF0648;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF04 @ 0xF0649;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL04 @ 0xF064A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH04 @ 0xF064C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL04 @ 0xF064E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0105; struct { unsigned char CMDB005; unsigned char CMDB105; }; } @ 0xF0650;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2305; struct { unsigned char CMDB205; unsigned char CMDB305; }; } @ 0xF0652;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4505; struct { unsigned char CMDB405; unsigned char CMDB505; }; } @ 0xF0654;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6705; struct { unsigned char CMDB605; unsigned char CMDB705; }; } @ 0xF0656;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC05 @ 0xF0658;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF05 @ 0xF0659;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL05 @ 0xF065A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH05 @ 0xF065C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL05 @ 0xF065E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0106; struct { unsigned char CMDB006; unsigned char CMDB106; }; } @ 0xF0660;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2306; struct { unsigned char CMDB206; unsigned char CMDB306; }; } @ 0xF0662;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4506; struct { unsigned char CMDB406; unsigned char CMDB506; }; } @ 0xF0664;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6706; struct { unsigned char CMDB606; unsigned char CMDB706; }; } @ 0xF0666;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC06 @ 0xF0668;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF06 @ 0xF0669;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL06 @ 0xF066A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH06 @ 0xF066C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL06 @ 0xF066E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0107; struct { unsigned char CMDB007; unsigned char CMDB107; }; } @ 0xF0670;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2307; struct { unsigned char CMDB207; unsigned char CMDB307; }; } @ 0xF0672;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4507; struct { unsigned char CMDB407; unsigned char CMDB507; }; } @ 0xF0674;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6707; struct { unsigned char CMDB607; unsigned char CMDB707; }; } @ 0xF0676;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC07 @ 0xF0678;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF07 @ 0xF0679;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL07 @ 0xF067A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH07 @ 0xF067C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL07 @ 0xF067E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0108; struct { unsigned char CMDB008; unsigned char CMDB108; }; } @ 0xF0680;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2308; struct { unsigned char CMDB208; unsigned char CMDB308; }; } @ 0xF0682;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4508; struct { unsigned char CMDB408; unsigned char CMDB508; }; } @ 0xF0684;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6708; struct { unsigned char CMDB608; unsigned char CMDB708; }; } @ 0xF0686;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC08 @ 0xF0688;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF08 @ 0xF0689;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL08 @ 0xF068A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH08 @ 0xF068C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL08 @ 0xF068E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0109; struct { unsigned char CMDB009; unsigned char CMDB109; }; } @ 0xF0690;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2309; struct { unsigned char CMDB209; unsigned char CMDB309; }; } @ 0xF0692;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4509; struct { unsigned char CMDB409; unsigned char CMDB509; }; } @ 0xF0694;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6709; struct { unsigned char CMDB609; unsigned char CMDB709; }; } @ 0xF0696;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC09 @ 0xF0698;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF09 @ 0xF0699;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL09 @ 0xF069A;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH09 @ 0xF069C;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL09 @ 0xF069E;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0110; struct { unsigned char CMDB010; unsigned char CMDB110; }; } @ 0xF06A0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2310; struct { unsigned char CMDB210; unsigned char CMDB310; }; } @ 0xF06A2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4510; struct { unsigned char CMDB410; unsigned char CMDB510; }; } @ 0xF06A4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6710; struct { unsigned char CMDB610; unsigned char CMDB710; }; } @ 0xF06A6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC10 @ 0xF06A8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF10 @ 0xF06A9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL10 @ 0xF06AA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH10 @ 0xF06AC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL10 @ 0xF06AE;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0111; struct { unsigned char CMDB011; unsigned char CMDB111; }; } @ 0xF06B0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2311; struct { unsigned char CMDB211; unsigned char CMDB311; }; } @ 0xF06B2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4511; struct { unsigned char CMDB411; unsigned char CMDB511; }; } @ 0xF06B4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6711; struct { unsigned char CMDB611; unsigned char CMDB711; }; } @ 0xF06B6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC11 @ 0xF06B8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF11 @ 0xF06B9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL11 @ 0xF06BA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH11 @ 0xF06BC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL11 @ 0xF06BE;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0112; struct { unsigned char CMDB012; unsigned char CMDB112; }; } @ 0xF06C0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2312; struct { unsigned char CMDB212; unsigned char CMDB312; }; } @ 0xF06C2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4512; struct { unsigned char CMDB412; unsigned char CMDB512; }; } @ 0xF06C4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6712; struct { unsigned char CMDB612; unsigned char CMDB712; }; } @ 0xF06C6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC12 @ 0xF06C8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF12 @ 0xF06C9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL12 @ 0xF06CA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH12 @ 0xF06CC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL12 @ 0xF06CE;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0113; struct { unsigned char CMDB013; unsigned char CMDB113; }; } @ 0xF06D0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2313; struct { unsigned char CMDB213; unsigned char CMDB313; }; } @ 0xF06D2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4513; struct { unsigned char CMDB413; unsigned char CMDB513; }; } @ 0xF06D4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6713; struct { unsigned char CMDB613; unsigned char CMDB713; }; } @ 0xF06D6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC13 @ 0xF06D8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF13 @ 0xF06D9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL13 @ 0xF06DA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH13 @ 0xF06DC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL13 @ 0xF06DE;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0114; struct { unsigned char CMDB014; unsigned char CMDB114; }; } @ 0xF06E0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2314; struct { unsigned char CMDB214; unsigned char CMDB314; }; } @ 0xF06E2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4514; struct { unsigned char CMDB414; unsigned char CMDB514; }; } @ 0xF06E4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6714; struct { unsigned char CMDB614; unsigned char CMDB714; }; } @ 0xF06E6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC14 @ 0xF06E8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF14 @ 0xF06E9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL14 @ 0xF06EA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH14 @ 0xF06EC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL14 @ 0xF06EE;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB0115; struct { unsigned char CMDB015; unsigned char CMDB115; }; } @ 0xF06F0;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB2315; struct { unsigned char CMDB215; unsigned char CMDB315; }; } @ 0xF06F2;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB4515; struct { unsigned char CMDB415; unsigned char CMDB515; }; } @ 0xF06F4;
extern __near __no_bit_access __no_init volatile union { unsigned short CMDB6715; struct { unsigned char CMDB615; unsigned char CMDB715; }; } @ 0xF06F6;
extern __near __no_bit_access __no_init volatile unsigned char CMDLC15 @ 0xF06F8;
extern __near __no_bit_access __no_init volatile unsigned char CMCONF15 @ 0xF06F9;
extern __near __no_bit_access __no_init volatile unsigned short CMIDL15 @ 0xF06FA;
extern __near __no_bit_access __no_init volatile unsigned short CMIDH15 @ 0xF06FC;
extern __near __no_bit_access __no_init volatile unsigned short CMCTRL15 @ 0xF06FE;

/*----------------------------------------------
 *       Extended SFR bit declarations
 *--------------------------------------------*/

#define GDCSC             GUARD_bit.no0
#define GDPLL             GUARD_bit.no1
#define GDLTRM            GUARD_bit.no2
#define GDLVI             GUARD_bit.no5
#define GDIAW             GUARD_bit.no6
#define GDWDT             GUARD_bit.no7

#define IAWEN             IAWCTL_bit.no7

#define DS2               DMC2_bit.no5
#define DRS2              DMC2_bit.no6
#define STG2              DMC2_bit.no7

#define DS3               DMC3_bit.no5
#define DRS3              DMC3_bit.no6
#define STG3              DMC3_bit.no7

#define DST2              DRC2_bit.no0
#define DEN2              DRC2_bit.no7

#define DST3              DRC3_bit.no0
#define DEN3              DRC3_bit.no7

#define DWAITALL          DMCALL_bit.no0
#define DPRMOD            DMCALL_bit.no7

#define DIVST             MDUC_bit.no0
#define DIVMODE           MDUC_bit.no7

#define TAU0EN            PER0_bit.no0
#define TAU1EN            PER0_bit.no1
#define TAU2EN            PER0_bit.no2
#define SAU0EN            PER0_bit.no3
#define SAU1EN            PER0_bit.no4
#define LIN0EN            PER0_bit.no5
#define LIN1EN            PER0_bit.no6
#define ADCEN             PER0_bit.no7

#define DFLEN             PER1_bit.no0
#define WUTEN             PER1_bit.no1
#define SAU2EN            PER1_bit.no3

#define WUTMCKE           PCKSEL_bit.no2
#define CANMCKE           PCKSEL_bit.no4

#define SELPLLS           PLLSTS_bit.no3
#define LOCK              PLLSTS_bit.no7

#define PLLON             PLLCTL_bit.no0
#define SELPLL            PLLCTL_bit.no2

#define STPSEL            STPSTC_bit.no0
#define STPLV             STPSTC_bit.no4
#define STPOEN            STPSTC_bit.no7

#define UF0RXE            UF0CTL0_bit.no5
#define UF0TXE            UF0CTL0_bit.no6

#define UF0BTT            UF0OPT0_bit.no5
#define UF0BRT            UF0OPT0_bit.no6
#define UF0BRF            UF0OPT0_bit.no7

#define UF0EBC            UF0OPT1_bit.no5

#define UF0ITS            UF0OPT2_bit.no0

#define UF1RXE            UF1CTL0_bit.no5
#define UF1TXE            UF1CTL0_bit.no6

#define UF1BTT            UF1OPT0_bit.no5
#define UF1BRT            UF1OPT0_bit.no6
#define UF1BRF            UF1OPT0_bit.no7

#define UF1EBC            UF1OPT1_bit.no5

#define UF1ITS            UF1OPT2_bit.no0

#define DFRDY             DFLST_bit.no0

extern __saddr __no_init volatile union { unsigned char P0; __BITS8 P0_bit; } @ 0xFFF00;
extern __saddr __no_init volatile union { unsigned char P1; __BITS8 P1_bit; } @ 0xFFF01;
extern __saddr __no_init volatile union { unsigned char P3; __BITS8 P3_bit; } @ 0xFFF03;
extern __saddr __no_init volatile union { unsigned char P4; __BITS8 P4_bit; } @ 0xFFF04;
extern __saddr __no_init volatile union { unsigned char P5; __BITS8 P5_bit; } @ 0xFFF05;
extern __saddr __no_init volatile union { unsigned char P6; __BITS8 P6_bit; } @ 0xFFF06;
extern __saddr __no_init volatile union { unsigned char P7; __BITS8 P7_bit; } @ 0xFFF07;
extern __saddr __no_init volatile union { unsigned char P8; __BITS8 P8_bit; } @ 0xFFF08;
extern __saddr __no_init volatile union { unsigned char P9; __BITS8 P9_bit; } @ 0xFFF09;
extern __saddr __no_init volatile union { unsigned char P10; __BITS8 P10_bit; } @ 0xFFF0A;
extern __saddr __no_init volatile union { unsigned char P12; __BITS8 P12_bit; } @ 0xFFF0C;
extern __saddr __no_init volatile union { unsigned char P13; __BITS8 P13_bit; } @ 0xFFF0D;
extern __saddr __no_init volatile union { unsigned char P14; __BITS8 P14_bit; } @ 0xFFF0E;
extern __saddr __no_init volatile union { unsigned char P15; __BITS8 P15_bit; } @ 0xFFF0F;
extern __saddr __no_bit_access __no_init volatile union { unsigned short SDR00; struct { unsigned char SDR00L; }; } @ 0xFFF10;
extern __saddr __no_bit_access __no_init volatile union { unsigned short SDR01; struct { unsigned char SDR01L; }; } @ 0xFFF12;
extern __saddr __no_bit_access __no_init volatile union { unsigned short SDR10; struct { unsigned char SDR10L; }; } @ 0xFFF14;
extern __saddr __no_bit_access __no_init volatile union { unsigned short SDR11; struct { unsigned char SDR11L; }; } @ 0xFFF16;
extern __saddr __no_bit_access __no_init volatile unsigned short TDR00 @ 0xFFF18;
extern __saddr __no_bit_access __no_init volatile unsigned short TDR01 @ 0xFFF1A;
extern __saddr __no_bit_access __no_init volatile const union { unsigned short ADCR; struct { unsigned char :8; const unsigned char ADCRH; }; } @ 0xFFF1E;
extern __sfr __no_init volatile union { unsigned char PM0; __BITS8 PM0_bit; } @ 0xFFF20;
extern __sfr __no_init volatile union { unsigned char PM1; __BITS8 PM1_bit; } @ 0xFFF21;
extern __sfr __no_init volatile union { unsigned char PM3; __BITS8 PM3_bit; } @ 0xFFF23;
extern __sfr __no_init volatile union { unsigned char PM4; __BITS8 PM4_bit; } @ 0xFFF24;
extern __sfr __no_init volatile union { unsigned char PM5; __BITS8 PM5_bit; } @ 0xFFF25;
extern __sfr __no_init volatile union { unsigned char PM6; __BITS8 PM6_bit; } @ 0xFFF26;
extern __sfr __no_init volatile union { unsigned char PM7; __BITS8 PM7_bit; } @ 0xFFF27;
extern __sfr __no_init volatile union { unsigned char PM8; __BITS8 PM8_bit; } @ 0xFFF28;
extern __sfr __no_init volatile union { unsigned char PM9; __BITS8 PM9_bit; } @ 0xFFF29;
extern __sfr __no_init volatile union { unsigned char PM10; __BITS8 PM10_bit; } @ 0xFFF2A;
extern __sfr __no_init volatile union { unsigned char PM12; __BITS8 PM12_bit; } @ 0xFFF2C;
extern __sfr __no_init volatile union { unsigned char PM14; __BITS8 PM14_bit; } @ 0xFFF2E;
extern __sfr __no_init volatile union { unsigned char PM15; __BITS8 PM15_bit; } @ 0xFFF2F;
extern __sfr __no_init volatile union { unsigned char ADM0; __BITS8 ADM0_bit; } @ 0xFFF30;
extern __sfr __no_init volatile union { unsigned char ADS; __BITS8 ADS_bit; } @ 0xFFF31;
extern __sfr __no_init volatile union { unsigned char ADSMP; __BITS8 ADSMP_bit; } @ 0xFFF33;
extern __sfr __no_init volatile union { unsigned char IPSEL0; __BITS8 IPSEL0_bit; } @ 0xFFF36;
extern __sfr __no_init volatile union { unsigned char KRM; __BITS8 KRM_bit; } @ 0xFFF37;
extern __sfr __no_init volatile union { unsigned char EGP0; __BITS8 EGP0_bit; } @ 0xFFF38;
extern __sfr __no_init volatile union { unsigned char EGN0; __BITS8 EGN0_bit; } @ 0xFFF39;
extern __sfr __no_init volatile union { unsigned char EGP1; __BITS8 EGP1_bit; } @ 0xFFF3A;
extern __sfr __no_init volatile union { unsigned char EGN1; __BITS8 EGN1_bit; } @ 0xFFF3B;
extern __sfr __no_init volatile union { unsigned char STSEL; __BITS8 STSEL_bit; } @ 0xFFF3C;
extern __sfr __no_init volatile union { unsigned char TIS0; __BITS8 TIS0_bit; } @ 0xFFF3E;
extern __sfr __no_init volatile union { unsigned char TIS1; __BITS8 TIS1_bit; } @ 0xFFF3F;
extern __sfr __no_init volatile union { unsigned char ADM1; __BITS8 ADM1_bit; } @ 0xFFF42;
extern __sfr __no_bit_access __no_init volatile union { unsigned short SDR20; struct { unsigned char SDR20L; }; } @ 0xFFF44;
extern __sfr __no_bit_access __no_init volatile union { unsigned short SDR21; struct { unsigned char SDR21L; }; } @ 0xFFF46;
extern __sfr __no_bit_access __no_init volatile union { unsigned short UF0TX; struct { unsigned char UF0TXB; }; } @ 0xFFF48;
extern __sfr __no_bit_access __no_init volatile union { unsigned short UF0RX; struct { unsigned char UF0RXB; }; } @ 0xFFF4A;
extern __sfr __no_bit_access __no_init volatile union { unsigned short UF1TX; struct { unsigned char UF1TXB; }; } @ 0xFFF4C;
extern __sfr __no_bit_access __no_init volatile union { unsigned short UF1RX; struct { unsigned char UF1RXB; }; } @ 0xFFF4E;
extern __sfr __no_init volatile union { unsigned char TOS0; __BITS8 TOS0_bit; } @ 0xFFF60;
extern __sfr __no_init volatile union { unsigned char TOS1; __BITS8 TOS1_bit; } @ 0xFFF61;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR02 @ 0xFFF64;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR03 @ 0xFFF66;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR04 @ 0xFFF68;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR05 @ 0xFFF6A;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR06 @ 0xFFF6C;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR07 @ 0xFFF6E;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR10 @ 0xFFF70;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR11 @ 0xFFF72;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR12 @ 0xFFF74;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR13 @ 0xFFF76;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR14 @ 0xFFF78;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR15 @ 0xFFF7A;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR16 @ 0xFFF7C;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR17 @ 0xFFF7E;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR20 @ 0xFFF90;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR21 @ 0xFFF92;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR22 @ 0xFFF94;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR23 @ 0xFFF96;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR24 @ 0xFFF98;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR25 @ 0xFFF9A;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR26 @ 0xFFF9C;
extern __sfr __no_bit_access __no_init volatile unsigned short TDR27 @ 0xFFF9E;
extern __sfr __no_bit_access __no_init volatile unsigned char CMC @ 0xFFFA0;
extern __sfr __no_init volatile union { unsigned char CSC; __BITS8 CSC_bit; } @ 0xFFFA1;
extern __sfr __no_init volatile const union { unsigned char OSTC; __BITS8 OSTC_bit; } @ 0xFFFA2;
extern __sfr __no_bit_access __no_init volatile unsigned char OSTS @ 0xFFFA3;
extern __sfr __no_init volatile union { unsigned char CKC; __BITS8 CKC_bit; } @ 0xFFFA4;
extern __sfr __no_init volatile union { unsigned char CKS; __BITS8 CKS_bit; } @ 0xFFFA5;
extern __sfr __no_bit_access __no_init volatile const unsigned char RESF @ 0xFFFA8;
extern __sfr __no_init volatile union { unsigned char LVIM; __BITS8 LVIM_bit; } @ 0xFFFA9;
extern __sfr __no_init volatile union { unsigned char LVIS; __BITS8 LVIS_bit; } @ 0xFFFAA;
extern __sfr __no_bit_access __no_init volatile unsigned char WDTE @ 0xFFFAB;
extern __sfr __no_init volatile union { unsigned char WUTMCTL; __BITS8 WUTMCTL_bit; } @ 0xFFFAC;
extern __sfr __no_bit_access __no_init volatile unsigned short WUTMCMP @ 0xFFFAE;
extern __sfr __no_bit_access __no_init volatile unsigned char DSA0 @ 0xFFFB0;
extern __sfr __no_bit_access __no_init volatile unsigned char DSA1 @ 0xFFFB1;
extern __sfr __no_bit_access __no_init volatile union { unsigned short DRA0; struct { unsigned char DRA0L; unsigned char DRA0H; }; } @ 0xFFFB2;
extern __sfr __no_bit_access __no_init volatile union { unsigned short DRA1; struct { unsigned char DRA1L; unsigned char DRA1H; }; } @ 0xFFFB4;
extern __sfr __no_bit_access __no_init volatile union { unsigned short DBC0; struct { unsigned char DBC0L; unsigned char DBC0H; }; } @ 0xFFFB6;
extern __sfr __no_bit_access __no_init volatile union { unsigned short DBC1; struct { unsigned char DBC1L; unsigned char DBC1H; }; } @ 0xFFFB8;
extern __sfr __no_init volatile union { unsigned char DMC0; __BITS8 DMC0_bit; } @ 0xFFFBA;
extern __sfr __no_init volatile union { unsigned char DMC1; __BITS8 DMC1_bit; } @ 0xFFFBB;
extern __sfr __no_init volatile union { unsigned char DRC0; __BITS8 DRC0_bit; } @ 0xFFFBC;
extern __sfr __no_init volatile union { unsigned char DRC1; __BITS8 DRC1_bit; } @ 0xFFFBD;
extern __sfr __no_init volatile union { unsigned char BECTL; __BITS8 BECTL_bit; } @ 0xFFFBE;
extern __sfr __no_init volatile union { unsigned short IF2; struct { union { unsigned char IF2L; __BITS8 IF2L_bit; }; union { unsigned char IF2H; __BITS8 IF2H_bit; }; }; } @ 0xFFFD0;
extern __sfr __no_init volatile union { unsigned short IF3; struct { union { unsigned char IF3L; __BITS8 IF3L_bit; }; union { unsigned char IF3H; __BITS8 IF3H_bit; }; }; } @ 0xFFFD2;
extern __sfr __no_init volatile union { unsigned short MK2; struct { union { unsigned char MK2L; __BITS8 MK2L_bit; }; union { unsigned char MK2H; __BITS8 MK2H_bit; }; }; } @ 0xFFFD4;
extern __sfr __no_init volatile union { unsigned short MK3; struct { union { unsigned char MK3L; __BITS8 MK3L_bit; }; union { unsigned char MK3H; __BITS8 MK3H_bit; }; }; } @ 0xFFFD6;
extern __sfr __no_init volatile union { unsigned short PR02; struct { union { unsigned char PR02L; __BITS8 PR02L_bit; }; union { unsigned char PR02H; __BITS8 PR02H_bit; }; }; } @ 0xFFFD8;
extern __sfr __no_init volatile union { unsigned short PR03; struct { union { unsigned char PR03L; __BITS8 PR03L_bit; }; union { unsigned char PR03H; __BITS8 PR03H_bit; }; }; } @ 0xFFFDA;
extern __sfr __no_init volatile union { unsigned short PR12; struct { union { unsigned char PR12L; __BITS8 PR12L_bit; }; union { unsigned char PR12H; __BITS8 PR12H_bit; }; }; } @ 0xFFFDC;
extern __sfr __no_init volatile union { unsigned short PR13; struct { union { unsigned char PR13L; __BITS8 PR13L_bit; }; union { unsigned char PR13H; __BITS8 PR13H_bit; }; }; } @ 0xFFFDE;
extern __sfr __no_init volatile union { unsigned short IF0; struct { union { unsigned char IF0L; __BITS8 IF0L_bit; }; union { unsigned char IF0H; __BITS8 IF0H_bit; }; }; } @ 0xFFFE0;
extern __sfr __no_init volatile union { unsigned short IF1; struct { union { unsigned char IF1L; __BITS8 IF1L_bit; }; union { unsigned char IF1H; __BITS8 IF1H_bit; }; }; } @ 0xFFFE2;
extern __sfr __no_init volatile union { unsigned short MK0; struct { union { unsigned char MK0L; __BITS8 MK0L_bit; }; union { unsigned char MK0H; __BITS8 MK0H_bit; }; }; } @ 0xFFFE4;
extern __sfr __no_init volatile union { unsigned short MK1; struct { union { unsigned char MK1L; __BITS8 MK1L_bit; }; union { unsigned char MK1H; __BITS8 MK1H_bit; }; }; } @ 0xFFFE6;
extern __sfr __no_init volatile union { unsigned short PR00; struct { union { unsigned char PR00L; __BITS8 PR00L_bit; }; union { unsigned char PR00H; __BITS8 PR00H_bit; }; }; } @ 0xFFFE8;
extern __sfr __no_init volatile union { unsigned short PR01; struct { union { unsigned char PR01L; __BITS8 PR01L_bit; }; union { unsigned char PR01H; __BITS8 PR01H_bit; }; }; } @ 0xFFFEA;
extern __sfr __no_init volatile union { unsigned short PR10; struct { union { unsigned char PR10L; __BITS8 PR10L_bit; }; union { unsigned char PR10H; __BITS8 PR10H_bit; }; }; } @ 0xFFFEC;
extern __sfr __no_init volatile union { unsigned short PR11; struct { union { unsigned char PR11L; __BITS8 PR11L_bit; }; union { unsigned char PR11H; __BITS8 PR11H_bit; }; }; } @ 0xFFFEE;
extern __sfr __no_bit_access __no_init volatile unsigned short MDAL @ 0xFFFF0;
extern __sfr __no_bit_access __no_init volatile unsigned short MULA @ 0xFFFF0;
extern __sfr __no_bit_access __no_init volatile unsigned short MDAH @ 0xFFFF2;
extern __sfr __no_bit_access __no_init volatile unsigned short MULB @ 0xFFFF2;
extern __sfr __no_bit_access __no_init volatile unsigned short MDBH @ 0xFFFF4;
extern __sfr __no_bit_access __no_init volatile const unsigned short MULOH @ 0xFFFF4;
extern __sfr __no_bit_access __no_init volatile unsigned short MDBL @ 0xFFFF6;
extern __sfr __no_bit_access __no_init volatile const unsigned short MULOL @ 0xFFFF6;
extern __sfr __no_init volatile union { unsigned char PMC; __BITS8 PMC_bit; } @ 0xFFFFE;

/*----------------------------------------------
 *       SFR bit declarations
 *--------------------------------------------*/

#define ADCE              ADM0_bit.no0
#define ADCS              ADM0_bit.no7

#define ADTMD             ADM1_bit.no7

#define HIOSTOP           CSC_bit.no0
#define XTSTOP            CSC_bit.no6
#define MSTOP             CSC_bit.no7

#define MCM0              CKC_bit.no4
#define MCS               CKC_bit.no5
#define CSS               CKC_bit.no6
#define CLS               CKC_bit.no7

#define PCLOE             CKS_bit.no7

#define LVIF              LVIM_bit.no0
#define LVIMD             LVIM_bit.no1
#define LVISEL            LVIM_bit.no2
#define LVION             LVIM_bit.no7

#define WUTMCE            WUTMCTL_bit.no7

#define DS0               DMC0_bit.no5
#define DRS0              DMC0_bit.no6
#define STG0              DMC0_bit.no7

#define DS1               DMC1_bit.no5
#define DRS1              DMC1_bit.no6
#define STG1              DMC1_bit.no7

#define DST0              DRC0_bit.no0
#define DEN0              DRC0_bit.no7

#define DST1              DRC1_bit.no0
#define DEN1              DRC1_bit.no7

#define FLMDPUP           BECTL_bit.no7

#define TMIF05            IF2L_bit.no0
#define TMIF06            IF2L_bit.no1
#define TMIF07            IF2L_bit.no2
#define KRIF              IF2L_bit.no3
#define PIF6              IF2L_bit.no3
#define PIF7              IF2L_bit.no4
#define C0ERRIF           IF2L_bit.no5
#define C0WUPIF           IF2L_bit.no6
#define C0RECIF           IF2L_bit.no7

#define C0TRXIF           IF2H_bit.no0
#define TMIF10            IF2H_bit.no1
#define TMIF11            IF2H_bit.no2
#define TMIF12            IF2H_bit.no3
#define TMIF13            IF2H_bit.no4
#define MDIF              IF2H_bit.no5
#define IICIF20           IF2H_bit.no6
#define STIF2             IF2H_bit.no6
#define SRIF2             IF2H_bit.no7

#define PIFR2             IF3L_bit.no0
#define TMIF14            IF3L_bit.no1
#define TMIF15            IF3L_bit.no2
#define TMIF16            IF3L_bit.no3
#define TMIF17            IF3L_bit.no4
#define TMIF20            IF3L_bit.no5
#define TMIF21            IF3L_bit.no6
#define TMIF22            IF3L_bit.no7

#define TMIF23            IF3H_bit.no0
#define TMIF25            IF3H_bit.no1
#define TMIF27            IF3H_bit.no2
#define DMAIF2            IF3H_bit.no3
#define DMAIF3            IF3H_bit.no4

#define TMMK05            MK2L_bit.no0
#define TMMK06            MK2L_bit.no1
#define TMMK07            MK2L_bit.no2
#define KRMK              MK2L_bit.no3
#define PMK6              MK2L_bit.no3
#define PMK7              MK2L_bit.no4
#define C0ERRMK           MK2L_bit.no5
#define C0WUPMK           MK2L_bit.no6
#define C0RECMK           MK2L_bit.no7

#define C0TRXMK           MK2H_bit.no0
#define TMMK10            MK2H_bit.no1
#define TMMK11            MK2H_bit.no2
#define TMMK12            MK2H_bit.no3
#define TMMK13            MK2H_bit.no4
#define MDMK              MK2H_bit.no5
#define IICMK20           MK2H_bit.no6
#define STMK2             MK2H_bit.no6
#define SRMK2             MK2H_bit.no7

#define PMKR2             MK3L_bit.no0
#define TMMK14            MK3L_bit.no1
#define TMMK15            MK3L_bit.no2
#define TMMK16            MK3L_bit.no3
#define TMMK17            MK3L_bit.no4
#define TMMK20            MK3L_bit.no5
#define TMMK21            MK3L_bit.no6
#define TMMK22            MK3L_bit.no7

#define TMMK23            MK3H_bit.no0
#define TMMK25            MK3H_bit.no1
#define TMMK27            MK3H_bit.no2
#define DMAMK2            MK3H_bit.no3
#define DMAMK3            MK3H_bit.no4

#define TMPR005           PR02L_bit.no0
#define TMPR006           PR02L_bit.no1
#define TMPR007           PR02L_bit.no2
#define KRPR0             PR02L_bit.no3
#define PPR06             PR02L_bit.no3
#define PPR07             PR02L_bit.no4
#define C0ERRPR0          PR02L_bit.no5
#define C0WUPPR0          PR02L_bit.no6
#define C0RECPR0          PR02L_bit.no7

#define C0TRXPR0          PR02H_bit.no0
#define TMPR010           PR02H_bit.no1
#define TMPR011           PR02H_bit.no2
#define TMPR012           PR02H_bit.no3
#define TMPR013           PR02H_bit.no4
#define MDPR0             PR02H_bit.no5
#define IICPR020          PR02H_bit.no6
#define STPR02            PR02H_bit.no6
#define SRPR02            PR02H_bit.no7

#define PPR0R2            PR03L_bit.no0
#define TMPR014           PR03L_bit.no1
#define TMPR015           PR03L_bit.no2
#define TMPR016           PR03L_bit.no3
#define TMPR017           PR03L_bit.no4
#define TMPR020           PR03L_bit.no5
#define TMPR021           PR03L_bit.no6
#define TMPR022           PR03L_bit.no7

#define TMPR023           PR03H_bit.no0
#define TMPR025           PR03H_bit.no1
#define TMPR027           PR03H_bit.no2
#define DMAPR02           PR03H_bit.no3
#define DMAPR03           PR03H_bit.no4

#define TMPR105           PR12L_bit.no0
#define TMPR106           PR12L_bit.no1
#define TMPR107           PR12L_bit.no2
#define KRPR1             PR12L_bit.no3
#define PPR16             PR12L_bit.no3
#define PPR17             PR12L_bit.no4
#define C0ERRPR1          PR12L_bit.no5
#define C0WUPPR1          PR12L_bit.no6
#define C0RECPR1          PR12L_bit.no7

#define C0TRXPR1          PR12H_bit.no0
#define TMPR110           PR12H_bit.no1
#define TMPR111           PR12H_bit.no2
#define TMPR112           PR12H_bit.no3
#define TMPR113           PR12H_bit.no4
#define MDPR1             PR12H_bit.no5
#define IICPR120          PR12H_bit.no6
#define STPR12            PR12H_bit.no6
#define SRPR12            PR12H_bit.no7

#define PPR1R2            PR13L_bit.no0
#define TMPR114           PR13L_bit.no1
#define TMPR115           PR13L_bit.no2
#define TMPR116           PR13L_bit.no3
#define TMPR117           PR13L_bit.no4
#define TMPR120           PR13L_bit.no5
#define TMPR121           PR13L_bit.no6
#define TMPR122           PR13L_bit.no7

#define TMPR123           PR13H_bit.no0
#define TMPR125           PR13H_bit.no1
#define TMPR127           PR13H_bit.no2
#define DMAPR12           PR13H_bit.no3
#define DMAPR13           PR13H_bit.no4

#define WDTIIF            IF0L_bit.no0
#define LVIIF             IF0L_bit.no1
#define PIF0              IF0L_bit.no2
#define PIF1              IF0L_bit.no3
#define PIF2              IF0L_bit.no4
#define PIF3              IF0L_bit.no5
#define PIF4              IF0L_bit.no6
#define PIF5              IF0L_bit.no7

#define CLMIF             IF0H_bit.no0
#define CSIIF00           IF0H_bit.no1
#define CSIIF01           IF0H_bit.no2
#define DMAIF0            IF0H_bit.no3
#define DMAIF1            IF0H_bit.no4
#define WUTMIF            IF0H_bit.no5
#define FLIF              IF0H_bit.no6
#define LTIF0             IF0H_bit.no7

#define LRIF0             IF1L_bit.no0
#define LSIF0             IF1L_bit.no1
#define PIFLR0            IF1L_bit.no2
#define PIF8              IF1L_bit.no3
#define TMIF00            IF1L_bit.no4
#define TMIF01            IF1L_bit.no5
#define TMIF02            IF1L_bit.no6
#define TMIF03            IF1L_bit.no7

#define ADIF              IF1H_bit.no0
#define LTIF1             IF1H_bit.no1
#define LRIF1             IF1H_bit.no2
#define LSIF1             IF1H_bit.no3
#define PIFLR1            IF1H_bit.no4
#define CSIIF10           IF1H_bit.no5
#define CSIIF11           IF1H_bit.no6
#define IICIF11           IF1H_bit.no6
#define TMIF04            IF1H_bit.no7

#define WDTIMK            MK0L_bit.no0
#define LVIMK             MK0L_bit.no1
#define PMK0              MK0L_bit.no2
#define PMK1              MK0L_bit.no3
#define PMK2              MK0L_bit.no4
#define PMK3              MK0L_bit.no5
#define PMK4              MK0L_bit.no6
#define PMK5              MK0L_bit.no7

#define CLMMK             MK0H_bit.no0
#define CSIMK00           MK0H_bit.no1
#define CSIMK01           MK0H_bit.no2
#define DMAMK0            MK0H_bit.no3
#define DMAMK1            MK0H_bit.no4
#define WUTMMK            MK0H_bit.no5
#define FLMK              MK0H_bit.no6
#define LTMK0             MK0H_bit.no7

#define LRMK0             MK1L_bit.no0
#define LSMK0             MK1L_bit.no1
#define PMKLR0            MK1L_bit.no2
#define PMK8              MK1L_bit.no3
#define TMMK00            MK1L_bit.no4
#define TMMK01            MK1L_bit.no5
#define TMMK02            MK1L_bit.no6
#define TMMK03            MK1L_bit.no7

#define ADMK              MK1H_bit.no0
#define LTMK1             MK1H_bit.no1
#define LRMK1             MK1H_bit.no2
#define LSMK1             MK1H_bit.no3
#define PMKLR1            MK1H_bit.no4
#define CSIMK10           MK1H_bit.no5
#define CSIMK11           MK1H_bit.no6
#define IICMK11           MK1H_bit.no6
#define TMMK04            MK1H_bit.no7

#define WDTIPR0           PR00L_bit.no0
#define LVIPR0            PR00L_bit.no1
#define PPR00             PR00L_bit.no2
#define PPR01             PR00L_bit.no3
#define PPR02             PR00L_bit.no4
#define PPR03             PR00L_bit.no5
#define PPR04             PR00L_bit.no6
#define PPR05             PR00L_bit.no7

#define CLMPR0            PR00H_bit.no0
#define CSIPR000          PR00H_bit.no1
#define CSIPR001          PR00H_bit.no2
#define DMAPR00           PR00H_bit.no3
#define DMAPR01           PR00H_bit.no4
#define WUTMPR0           PR00H_bit.no5
#define FLPR0             PR00H_bit.no6
#define LTPR00            PR00H_bit.no7

#define LRPR00            PR01L_bit.no0
#define LSPR00            PR01L_bit.no1
#define PPR0LR0           PR01L_bit.no2
#define PPR08             PR01L_bit.no3
#define TMPR000           PR01L_bit.no4
#define TMPR001           PR01L_bit.no5
#define TMPR002           PR01L_bit.no6
#define TMPR003           PR01L_bit.no7

#define ADPR0             PR01H_bit.no0
#define LTPR01            PR01H_bit.no1
#define LRPR01            PR01H_bit.no2
#define LSPR01            PR01H_bit.no3
#define PPR0LR1           PR01H_bit.no4
#define CSIPR010          PR01H_bit.no5
#define CSIPR011          PR01H_bit.no6
#define IICPR011          PR01H_bit.no6
#define TMPR004           PR01H_bit.no7

#define WDTIPR1           PR10L_bit.no0
#define LVIPR1            PR10L_bit.no1
#define PPR10             PR10L_bit.no2
#define PPR11             PR10L_bit.no3
#define PPR12             PR10L_bit.no4
#define PPR13             PR10L_bit.no5
#define PPR14             PR10L_bit.no6
#define PPR15             PR10L_bit.no7

#define CLMPR1            PR10H_bit.no0
#define CSIPR100          PR10H_bit.no1
#define CSIPR101          PR10H_bit.no2
#define DMAPR10           PR10H_bit.no3
#define DMAPR11           PR10H_bit.no4
#define WUTMPR1           PR10H_bit.no5
#define FLPR1             PR10H_bit.no6
#define LTPR10            PR10H_bit.no7

#define LRPR10            PR11L_bit.no0
#define LSPR10            PR11L_bit.no1
#define PPR1LR0           PR11L_bit.no2
#define PPR18             PR11L_bit.no3
#define TMPR100           PR11L_bit.no4
#define TMPR101           PR11L_bit.no5
#define TMPR102           PR11L_bit.no6
#define TMPR103           PR11L_bit.no7

#define ADPR1             PR11H_bit.no0
#define LTPR11            PR11H_bit.no1
#define LRPR11            PR11H_bit.no2
#define LSPR11            PR11H_bit.no3
#define PPR1LR1           PR11H_bit.no4
#define CSIPR110          PR11H_bit.no5
#define CSIPR111          PR11H_bit.no6
#define IICPR111          PR11H_bit.no6
#define TMPR104           PR11H_bit.no7


/*###########################################################
		interrupt vector number in this serial MCU
###########################################################*/

#define RST_vect                 (0x00)
#define INTWDTI_vect             (0x04)
#define INTLVI_vect              (0x06)
#define INTP0_vect               (0x08)
#define INTP1_vect               (0x0A)
#define INTP2_vect               (0x0C)
#define INTP3_vect               (0x0E)
#define INTP4_vect               (0x10)
#define INTP5_vect               (0x12)
#define INTCLM_vect              (0x14)
#define INTCSI00_vect            (0x16)
#define INTCSI01_vect            (0x18)
#define INTDMA0_vect             (0x1A)
#define INTDMA1_vect             (0x1C)
#define INTWUTM_vect             (0x1E)
#define INTFL_vect               (0x20)
#define INTLT0_vect              (0x22)
#define INTLR0_vect              (0x24)
#define INTLS0_vect              (0x26)
#define INTPLR0_vect             (0x28)
#define INTP8_vect               (0x2A)
#define INTTM00_vect             (0x2C)
#define INTTM01_vect             (0x2E)
#define INTTM02_vect             (0x30)
#define INTTM03_vect             (0x32)
#define INTAD_vect               (0x34)
#define INTLT1_vect              (0x36)
#define INTLR1_vect              (0x38)
#define INTLS1_vect              (0x3A)
#define INTPLR1_vect             (0x3C)
#define INTCSI10_vect            (0x3E)
#define INTCSI11_vect            (0x40)
#define INTIIC11_vect            (0x40)
#define INTTM04_vect             (0x42)
#define INTTM05_vect             (0x44)
#define INTTM06_vect             (0x46)
#define INTTM07_vect             (0x48)
#define INTKR_vect               (0x4A)
#define INTP6_vect               (0x4A)
#define INTP7_vect               (0x4C)
#define INTC0ERR_vect            (0x4E)
#define INTC0WUP_vect            (0x50)
#define INTC0REC_vect            (0x52)
#define INTC0TRX_vect            (0x54)
#define INTTM10_vect             (0x56)
#define INTTM11_vect             (0x58)
#define INTTM12_vect             (0x5A)
#define INTTM13_vect             (0x5C)
#define INTMD_vect               (0x5E)
#define INTIIC20_vect            (0x60)
#define INTST2_vect              (0x60)
#define INTSR2_vect              (0x62)
#define INTPR2_vect              (0x64)
#define INTTM14_vect             (0x66)
#define INTTM15_vect             (0x68)
#define INTTM16_vect             (0x6A)
#define INTTM17_vect             (0x6C)
#define INTTM20_vect             (0x6E)
#define INTTM21_vect             (0x70)
#define INTTM22_vect             (0x72)
#define INTTM23_vect             (0x74)
#define INTTM25_vect             (0x76)
#define INTTM27_vect             (0x78)
#define INTDMA2_vect             (0x7A)
#define INTDMA3_vect             (0x7C)
#define BRK_I_vect               (0x7E)

#pragma language=default

#endif/*end of _78K0R_IO_H_*/

#endif /* __IAR_SYSTEMS_ICC__ */


