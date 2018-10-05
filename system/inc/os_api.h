//////////////////////////////////////////////////////////////////////////
/// @file  os_api.h
/// @brief common os call abstraction
//////////////////////////////////////////////////////////////////////////
#ifndef OS_API_H
#define OS_API_H

//////////////////////////////////////////////////////////////////////////
// includes
//////////////////////////////////////////////////////////////////////////
#include <cstdio>

#include "os_types.h"
#include "os_api.h"

namespace System {

    //////////////////////////////////////////////////////////////////////////
    // Entry Point
    //////////////////////////////////////////////////////////////////////////
    #if defined (_WIN32)
    #define OS_DLL_EXPORT            __declspec(dllexport)
    #define OS_DLL_IMPORT            __declspec(dllimport)
    #elif defined(__GNUC__)
    #define OS_DLL_EXPORT            __attribute((visibility("default")))
    #define OS_DLL_IMPORT
    #endif

    #if defined(OS_LIB_EXPORT)
    #define OS_API                   OS_DLL_EXPORT
    #define OS_INLINE                inline
    #else
    #define OS_INLINE
    #define OS_API                   OS_DLL_IMPORT
    #endif

    //////////////////////////////////////////////////////////////////////////
    // OS Class Declaration
    //////////////////////////////////////////////////////////////////////////
    class OS {
        public:

        //////////////////////////////////////////////////////////////////////////
        // String Functions
        //////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////
        /// VSNPrintF
        ///
        /// @brief  Static function that writes formatted data from variable
        ///         argument list to sized buffer
        ///
        /// @param pDst     Destination buffer
        /// @param sizeDst  Destination buffer size in bytes
        /// @param pFormat  Format string, printf style
        /// @param argPtr   Parameters required by format string
        ///
        /// @return number of characters written into destination buffer
        //////////////////////////////////////////////////////////////////////////
        OS_API static INT VSNPrintF(
            CHAR        *pDst,
            size_t      sizeDst,
            const CHAR  *pFormat,
            va_list     argPtr);

        //////////////////////////////////////////////////////////////////////////
        /// SNPrintF
        ///
        /// @brief  Static function that writes formatted data from variable
        ///         argument list to sized buffer
        ///
        /// @param pDst     Destination buffer
        /// @param sizeDst  Destination buffer size in bytes
        /// @param pFormat  Format string, printf style
        /// @param ...      Parameters required by format string
        ///
        /// @return number of characters written into destination buffer
        //////////////////////////////////////////////////////////////////////////
        OS_API static INT SNPrintF(
            CHAR        *pDst,
            size_t      sizeDst,
            const CHAR  *pFormat,
            ...);
    };
}

#endif    // OS_API_H
