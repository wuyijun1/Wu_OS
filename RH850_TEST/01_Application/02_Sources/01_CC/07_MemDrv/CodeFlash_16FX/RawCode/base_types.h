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
/** \file base_types.h
 **
 ** Base type header file defining all general data types that should be used
 ** instead the ANSI C data types
 **
 ** History:
 **   - 2009-10-02  0.01  JWa  First version
 **   - 2009-10-09  0.02  JWa  en_result_t added
 **   - 2009-10-21  0.03  JWa  removed FAR_NULL and NEAR_NULL macros
 **                            (use CPU_TYPE for differentiation)
 **   - 2009-10-22  0.04  JWa  ErrorOperationInProgress added to en_result_t
 **   - 2010-01-18  0.05  JWa  ErrorInvalidMode and ErrorUninitialized added to en_result_t
 **   - 2010-03-19  0.06  JWa  modifiy SVN keywords
 **   - 2010-05-26  0.07  JWa  remove mcu.h from include list
 **   - 2011-04-27  0.08  JWa  update disclaimer, add macros, extend en_result_t
 *****************************************************************************/

#ifndef __BASE_TYPE_H__
#define __BASE_TYPE_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "fstdint.h"
  
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#ifndef TRUE
	/** Value is true (boolean_t type) */
    #define TRUE        ((boolean_t) 1)
#endif

#ifndef FALSE
	/** Value is false (boolean_t type) */
    #define FALSE       ((boolean_t) 0)
#endif

/** Returns the minimum value out of two values */
#define MIN( X, Y )  ((X) < (Y) ? (X) : (Y))

/** Returns the maximum value out of two values */
#define MAX( X, Y )  ((X) > (Y) ? (X) : (Y))

/** Returns the dimension of an array */
#define DIM( X )  (sizeof(X) / sizeof(X[0]))

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/** logical datatype (only values are TRUE and FALSE) */
typedef uint_fast8_t boolean_t;
  
/** single precision floating point number (4 byte) */
typedef float        float32_t;

/** double precision floating point number (8 byte) */
typedef double       float64_t;

/** ASCCI character for string generation (8 bit) */
typedef char         char_t;

/** function pointer type to void/void function*/
typedef void (*func_ptr_t)(void);

/** generic error codes */
typedef enum en_result
{
    Ok                          = 0,  ///< No error
    Error                       = 1,  ///< Non-specific error code
    ErrorAddressAlignment       = 2,  ///< Address alignment does not match
    ErrorAccessRights           = 3,  ///< Wrong mode (e.g. user/system) mode is set
    ErrorInvalidParameter       = 4,  ///< Provided parameter is not valid
    ErrorOperationInProgress    = 5,  ///< A conflicting or requested operation is still in progress
    ErrorInvalidMode            = 6,  ///< Operation not allowed in current mode
    ErrorUninitialized          = 7,  ///< Module (or part of it) was not initialized properly
    ErrorBufferFull             = 8,  ///< Circular buffer can not be written because the buffer is full
    ErrorTimeout                = 9   ///< A requested operation could not be completed
} en_result_t;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __BASE_TYPE_H__ */
