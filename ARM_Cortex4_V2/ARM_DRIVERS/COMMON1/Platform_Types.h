/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *       Module:  -
 *
 *  Description:  Contains types that dependent on platform - CortexM4     
 *  
 *********************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
 * CPU register type width
 */
#define WORD_LENGTH_BITS            (32U)
#define WORD_LENGTH_BYTES           (4U)

/*
 * Bit order definition
 */
#define MSB_FIRST                   (0u)        /* Big endian bit ordering        */
#define LSB_FIRST                   (1u)        /* Little endian bit ordering     */


/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST             (0u)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST              (1u)        /* Little endian byte ordering    */


/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE                       (0u)
#endif
#ifndef TRUE
#define TRUE                        (1u)
#endif

#define ENABLE                      (1u)
#define DISABLE                     (0u)

#ifndef LOW
#define LOW 0
#endif

#ifndef HIGH
#define HIGH 1
#endif

#define CPU_BIT_ORDER               LSB_FIRST        /*little endian bit ordering*/
#define CPU_BYTE_ORDER              LOW_BYTE_FIRST   /*little endian byte ordering*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

typedef signed char sint8;         /*        -128 .. +127            */
typedef unsigned char uint8;         /*           0 .. 255             */
typedef signed short sint16;        /*      -32768 .. +32767          */
typedef unsigned short uint16;        /*           0 .. 65535           */
typedef signed long sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long uint32;        /*           0 .. 4294967295      */

typedef float                 float32;
typedef double                float64;

#ifdef PLATFORM_SUPPORT_SINT64_UINT64 /*Valid only for gnu and C99 */
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/
