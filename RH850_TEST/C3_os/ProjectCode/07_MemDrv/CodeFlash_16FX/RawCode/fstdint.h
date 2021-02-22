/******************************************************************************
 * $Revision$
 * $Date$
 *****************************************************************************/
/*               (C) Fujitsu Semiconductor Europe GmbH (FSEU)                */
/*                                                                           */
/* The following software deliverable is intended for and must only be       */
/* used for reference and in an evaluation laboratory environment.           */
/* It is provided on an as-is basis without charge and is subject to         */
/* alterations.                                                              */
/* It is the user’s obligation to fully test the software in its             */
/* environment and to ensure proper functionality, qualification and         */
/* compliance with component specifications.                                 */
/*                                                                           */
/* In the event the software deliverable includes the use of open            */
/* source components, the provisions of the governing open source            */
/* license agreement shall apply with respect to such software               */
/* deliverable.                                                              */
/* FSEU does not warrant that the deliverables do not infringe any           */
/* third party intellectual property right (IPR). In the event that          */
/* the deliverables infringe a third party IPR it is the sole                */
/* responsibility of the customer to obtain necessary licenses to            */
/* continue the usage of the deliverable.                                    */
/*                                                                           */
/* To the maximum extent permitted by applicable law FSEU disclaims all      */
/* warranties, whether express or implied, in particular, but not            */
/* limited to, warranties of merchantability and fitness for a               */
/* particular purpose for which the deliverable is not designated.           */
/*                                                                           */
/* To the maximum extent permitted by applicable law, FSEU’s liability       */
/* is restricted to intentional misconduct and gross negligence.             */
/* FSEU is not liable for consequential damages.                             */
/*                                                                           */
/* (V1.5)                                                                    */
/*****************************************************************************/
/** \file fstdint.h
 **
 ** Standard integer data types according to ANSI C C99 standard.
 ** The mcu.h file must be included for correct setting of CPU_TYPE.
 ** The compiler must define the symbol __64BIT_INT_TYPE_SUPPORT__ if
 ** 64 bit types are supported.
 **
 ** History:
 **   - 2009-10-02  0.01  JWa  First version
 **   - 2010-03-19  0.02  JWa  modifiy SVN keywords
 *****************************************************************************/

#ifndef __FSTDINT_H__
#define __FSTDINT_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "mcu.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

/* Limits of exact-width integer types */

#define INT8_MIN   (-128)
#define INT8_MAX   (127)
#define UINT8_MAX  (255)

#define INT16_MIN  (-32768)
#define INT16_MAX  (32767)
#define UINT16_MAX (65535)

#define INT32_MIN  (-2147483648L)
#define INT32_MAX  (2147483647L)
#define UINT32_MAX (4294967295UL)

#ifdef __64BIT_INT_TYPE_SUPPORT__
    #define INT64_MIN  (-9223372036854775808LL)
    #define INT64_MAX  (9223372036854775807LL)
    #define UINT64_MAX (18446744073709551615ULL)
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Limits of minimum-width integer types */

#define INT_LEAST8_MIN   (-128)
#define INT_LEAST8_MAX   (127)
#define UINT_LEAST8_MAX  (255)

#define INT_LEAST16_MIN  (-32768)
#define INT_LEAST16_MAX  (32767)
#define UINT_LEAST16_MAX (65535)

#define INT_LEAST32_MIN  (-2147483648L)
#define INT_LEAST32_MAX  (2147483647L)
#define UINT_LEAST32_MAX (4294967295U)

#ifdef __64BIT_INT_TYPE_SUPPORT__
    #define INT_LEAST64_MIN  (-9223372036854775808LL)
    #define INT_LEAST64_MAX  (9223372036854775807LL)
    #define UINT_LEAST64_MAX (18446744073709551615ULL)
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Limits of fastest minimum-width integer types */

#if (CPU_TYPE == CPU_TYPE_16BIT)
    #define INT_FAST8_MIN  (-32768)
    #define INT_FAST8_MAX  (32767)
    #define UINT_FAST8_MAX (65535)
#elif (CPU_TYPE == CPU_TYPE_32BIT)
    #define INT_FAST8_MIN  (-2147483648L)
    #define INT_FAST8_MAX  (2147483647L)
    #define UINT_FAST8_MAX (4294967295UL)
#else
    #define INT_FAST8_MIN  (-128)
    #define INT_FAST8_MAX  (127)
    #define UINT_FAST8_MAX (255)
#endif /* CPU_TYPE */

#if (CPU_TYPE == CPU_TYPE_32BIT)
    #define INT_FAST16_MIN  (-2147483648L)
    #define INT_FAST16_MAX  (2147483647L)
    #define UINT_FAST16_MAX (4294967295U)
#else
    #define INT_FAST16_MIN  (-32768)
    #define INT_FAST16_MAX  (32767)
    #define UINT_FAST16_MAX (65535)
#endif /* CPU_TYPE */

#define INT_FAST32_MIN  (-2147483648L)
#define INT_FAST32_MAX  (2147483647L)
#define UINT_FAST32_MAX (4294967295UL)

#ifdef __64BIT_INT_TYPE_SUPPORT__
    #define INT_FAST64_MIN  (-9223372036854775808LL)
    #define INT_FAST64_MAX  (9223372036854775807LL)
    #define UINT_FAST64_MAX (18446744073709551615ULL)
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Macros for minimum-width integer constants */

#define INT8_C(value)  (value)
#define INT16_C(value) (value)
#define INT32_C(value) (value ## L)
#ifdef __64BIT_INT_TYPE_SUPPORT__
    #define INT64_C(value) (value ## LL)
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Macros for greatest-width integer constants */

#define UINT8_C(value)  (value)
#define UINT16_C(value) (value)
#define UINT32_C(value) (value ## UL)
#ifdef __64BIT_INT_TYPE_SUPPORT__
    #define UINT64_C(value) (value ## ULL)
#endif /* __64BIT_INT_TYPE_SUPPORT__ */


/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/* Exact-width integer types */
/* Signed types */

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef signed long long int64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Unsigned types */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef unsigned long long uint64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Minimum-width integer types */
/* Signed types */

typedef signed char int_least8_t;
typedef signed short int_least16_t;
typedef signed long int_least32_t;
#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef signed long long int_least64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Unsigned types */

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned long uint_least32_t;
#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef unsigned long long uint_least64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Fastest minimum-width integer types */
/* Signed types */

#if (CPU_TYPE == CPU_TYPE_16BIT)
    typedef signed short int_fast8_t;
#elif (CPU_TYPE == CPU_TYPE_32BIT)
    typedef signed long int_fast8_t;
#else
    typedef signed char int_fast8_t;
#endif /* CPU_TYPE */

#if (CPU_TYPE == CPU_TYPE_32BIT)
    typedef signed long int_fast16_t;
#else
    typedef signed short int_fast16_t;
#endif /* CPU_TYPE */

typedef signed long int_fast32_t;

#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef signed long long int_fast64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Unsigned types */

#if (CPU_TYPE == CPU_TYPE_16BIT)
    typedef unsigned short uint_fast8_t;
#elif (CPU_TYPE == CPU_TYPE_32BIT)
    typedef unsigned long uint_fast8_t;
#else
    typedef unsigned char uint_fast8_t;
#endif /* CPU_TYPE */

#if (CPU_TYPE == CPU_TYPE_32BIT)
    typedef unsigned long uint_fast16_t;
#else
    typedef unsigned short uint_fast16_t;
#endif /* CPU_TYPE */

typedef unsigned long uint_fast32_t;
#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef unsigned long long uint_fast64_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Greatest-width integer types */
/* Signed type */

#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef signed long long intmax_t;
#else
	typedef signed long intmax_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */

/* Unsigned type */

#ifdef __64BIT_INT_TYPE_SUPPORT__
    typedef unsigned long long uintmax_t;
#else
    typedef unsigned long uintmax_t;
#endif /* __64BIT_INT_TYPE_SUPPORT__ */


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif	// __FSTDINT_H__
