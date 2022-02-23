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

// C

// External

// Project
#include "./MRH_AppErrorInternal.h"


//*************************************************************************************
// Error Data
//*************************************************************************************

// Last error
static MRH_App_Error_Type e_LastError = MRH_APP_ERROR_NONE;

//*************************************************************************************
// Reset
//*************************************************************************************

void MRH_ERR_AppReset(void)
{
    e_LastError = MRH_APP_ERROR_NONE;
}

//*************************************************************************************
// Getters
//*************************************************************************************

MRH_App_Error_Type MRH_ERR_GetAppError(void)
{
    return e_LastError;
}

const char* MRH_ERR_GetAppErrorString(void)
{
    switch (e_LastError)
    {
        // None
        case MRH_APP_ERROR_NONE:
            return "No error";
            
        // Unknown
        case MRH_APP_ERROR_UNK:
            return "Unknown error";
            
        // General
        case MRH_APP_ERROR_GENERAL_EVENT_INVALID:
            return "Invalid event";
        case MRH_APP_ERROR_GENERAL_RESULT_FAIL:
            return "Event result fail";
        case MRH_APP_ERROR_GENERAL_INVALID_PARAM:
            return "Invalid parameters";
        case MRH_APP_ERROR_GENERAL_MALLOC:
            return "Memory allocation failed";
        case MRH_APP_ERROR_GENERAL_STRING_LENGTH:
            return "Invalid string length";
        case MRH_APP_ERROR_GENERAL_NO_FILE:
            return "No file";
        
        // User File
        case MRH_APP_ERROR_FPI_NO_INFO:
            return "The requested person info has no string value";
        case MRH_APP_ERROR_FRI_NO_INFO:
            return "The requested residence info has no string value";
            
        default:
            return NULL;
    }
}

//*************************************************************************************
// Setters
//*************************************************************************************

void MRH_ERR_SetAppError(MRH_App_Error_Type e_Error)
{
    e_LastError = e_Error;
}
