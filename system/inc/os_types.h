//////////////////////////////////////////////////////////////////////////
/// @file  os_types.h
/// @brief common os type abstraction
//////////////////////////////////////////////////////////////////////////
#ifndef OS_TYPES_H
#define OS_TYPES_H
//////////////////////////////////////////////////////////////////////////
// Includes
//////////////////////////////////////////////////////////////////////////
#include <stddef.h>
#include <stdint.h>

//////////////////////////////////////////////////////////////////////////
// Primitive Data Type Declaration
//////////////////////////////////////////////////////////////////////////
#if defined __cplusplus
extern "C" {
#endif  //__cplusplus

//bool type
typedef int             BOOL;

#if !defined(TRUE)
#define TRUE        1
#endif

#if !defined(FALSE)
#define FALSE       0
#endif

// character type
typedef char            CHAR;
typedef unsigned char   UCHAR;

// byte type
typedef uint8_t         SBYTE;
typedef unsigned int    BIT;

// integer type
typedef int             INT;
typedef unsigned int    UINT;
typedef uint8_t         UINT8;
typedef int8_t          INT8;
typedef uint16_t        UINT16;
typedef int16_t         INT16;
typedef uint32_t        UINT32;
typedef int32_t         INT32;
typedef uint64_t        UINT64;
typedef int64_t         INT64;

// size type
typedef size_t          SIZE_T;

// floating point type
typedef float           FLOAT;
typedef double          DOUBLE;

// pointer type
typedef intptr_t        INTPTR_T;
typedef uintptr_t       UINTPTR_T;
typedef ptrdiff_t       PTRDIFF_T;
typedef void*           HANDLE_T;

#if !defined(VOID)
typedef void            VOID;
#endif

#if defined __cplusplus
} 
#endif  //__cplusplus

#endif    // OS_TYPES_H
