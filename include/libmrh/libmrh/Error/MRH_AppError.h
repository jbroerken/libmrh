/**
 *  libmrh
 *  Copyright (C) 2021 - 2022 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

#ifndef MRH_AppError_h
#define MRH_AppError_h

// C
#include <stddef.h>

// External

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef enum
    {
        // None
        MRH_APP_ERROR_NONE = -1,
        
        // Unknown
        MRH_APP_ERROR_UNK = 0,
        
        // General
        MRH_APP_ERROR_GENERAL_EVENT_INVALID = 1,
        MRH_APP_ERROR_GENERAL_RESULT_FAIL = 2,
        MRH_APP_ERROR_GENERAL_INVALID_PARAM = 3,
        MRH_APP_ERROR_GENERAL_MALLOC = 4,
        MRH_APP_ERROR_GENERAL_STRING_LENGTH = 5,
        MRH_APP_ERROR_GENERAL_NO_FILE = 6,
        
        // User File
        MRH_APP_ERROR_FPI_NO_INFO = 7,
        MRH_APP_ERROR_FRI_NO_INFO,
        
        // Bounds
        MRH_APP_ERROR_TYPE_MAX = MRH_APP_ERROR_FRI_NO_INFO,

        MRH_APP_ERROR_TYPE_COUNT = MRH_APP_ERROR_TYPE_MAX + 1

    }MRH_App_Error_Type;

    //*************************************************************************************
    // Reset
    //*************************************************************************************

    /**
     *  Reset last error.
     */

    extern void MRH_ERR_AppReset(void);

    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Get library error.
     *
     *  \return The current library error.
     */

     extern MRH_App_Error_Type MRH_ERR_GetAppError(void);

     /**
      *  Get library error string.
      *
      *  \return The current library error string.
      */

     extern const char* MRH_ERR_GetAppErrorString(void);

#ifdef __cplusplus
}
#endif

#endif /* MRH_AppError_h */
