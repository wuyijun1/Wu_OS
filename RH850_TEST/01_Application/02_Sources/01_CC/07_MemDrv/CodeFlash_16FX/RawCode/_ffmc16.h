/*
 MB96670 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB96F673AA__) || \
    defined(__CPU_MB96F673RA__) || \
    defined(__CPU_MB96F675AA__) || \
    defined(__CPU_MB96F675RA__) || \
    defined(__CPU_MB96F673AB__) || \
    defined(__CPU_MB96F673RB__) || \
    defined(__CPU_MB96F675AB__) || \
    defined(__CPU_MB96F675RB__) 
#ifdef __FASM__
#include "mb96670_a.inc"
#else
#include "mb96670.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
